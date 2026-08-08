#pragma once

#include <atomic>
#include <cstddef>
#include <thread>

template<typename type, int queueSize>
class idLocklessQueueSingleProdCons {
public:
    idLocklessQueueSingleProdCons()
        : queue{}, queueStart(0), queueEnd(0) {
        static_assert(queueSize > 1 && (queueSize & (queueSize - 1)) == 0,
            "Lockless queue size must be a power of two");
    }

    void Add(type* element) {
        int end = queueEnd.load(std::memory_order_relaxed);
        while (((end + 1) & Mask())
            == queueStart.load(std::memory_order_acquire)) {
            std::this_thread::yield();
            end = queueEnd.load(std::memory_order_relaxed);
        }
        queue[end] = element;
        queueEnd.store((end + 1) & Mask(), std::memory_order_release);
    }

    type* Next() {
        const int start = queueStart.load(std::memory_order_relaxed);
        if (start == queueEnd.load(std::memory_order_acquire)) {
            return nullptr;
        }
        type* const result = queue[start];
        queueStart.store((start + 1) & Mask(), std::memory_order_release);
        return result;
    }

    bool IsEmpty() const {
        return queueStart.load(std::memory_order_acquire)
            == queueEnd.load(std::memory_order_acquire);
    }

private:
    type* queue[queueSize];
    std::atomic<int> queueStart;
    alignas(128) std::atomic<int> queueEnd;

    static constexpr int Mask() { return queueSize - 1; }
};

template<typename type, int queueSize>
class idLocklessQueueMultiProdCons {
public:
    idLocklessQueueMultiProdCons()
        : queue{}, queueStart(0), queueFetched(0), queueEnd(0), queueAlloced(0) {
        static_assert(queueSize > 1 && (queueSize & (queueSize - 1)) == 0,
            "Lockless queue size must be a power of two");
        static_assert(sizeof(std::atomic<type*>) == sizeof(type*),
            "PC atomics changed the recovered queue slot layout");
        for (int index = 0; index < queueSize; ++index) {
            queue[index].store(nullptr, std::memory_order_relaxed);
        }
    }

    void Add(type* element) {
        int allocated;
        for (;;) {
            allocated = queueAlloced.load(std::memory_order_relaxed);
            while ((((allocated + 1)
                ^ queueFetched.load(std::memory_order_acquire)) & Mask()) == 0) {
                std::this_thread::yield();
                allocated = queueAlloced.load(std::memory_order_relaxed);
            }
            if (queueAlloced.compare_exchange_weak(allocated, allocated + 1,
                std::memory_order_acq_rel, std::memory_order_relaxed)) {
                break;
            }
        }

        queue[allocated & Mask()].store(element, std::memory_order_release);
        AdvancePublishedEnd();
    }

    type* Next() {
        int start = queueStart.load(std::memory_order_relaxed);
        for (;;) {
            if (start == queueEnd.load(std::memory_order_acquire)) {
                return nullptr;
            }
            if (queueStart.compare_exchange_weak(start, start + 1,
                std::memory_order_acq_rel, std::memory_order_relaxed)) {
                break;
            }
        }

        type* const result = queue[start & Mask()].exchange(
            nullptr, std::memory_order_acq_rel
        );
        AdvanceFetched();
        return result;
    }

    bool IsEmpty() const {
        return queueStart.load(std::memory_order_acquire)
            == queueEnd.load(std::memory_order_acquire);
    }

private:
    std::atomic<type*> queue[queueSize];
    std::atomic<int> queueStart;
    alignas(128) std::atomic<int> queueFetched;
    alignas(128) std::atomic<int> queueEnd;
    alignas(128) std::atomic<int> queueAlloced;

    static constexpr int Mask() { return queueSize - 1; }

    void AdvancePublishedEnd() {
        int end = queueEnd.load(std::memory_order_relaxed);
        while (end != queueAlloced.load(std::memory_order_acquire)
            && queue[end & Mask()].load(std::memory_order_acquire) != nullptr) {
            if (!queueEnd.compare_exchange_weak(end, end + 1,
                std::memory_order_release, std::memory_order_relaxed)) {
                continue;
            }
            end = queueEnd.load(std::memory_order_relaxed);
        }
    }

    void AdvanceFetched() {
        int fetched = queueFetched.load(std::memory_order_relaxed);
        while (fetched != queueStart.load(std::memory_order_acquire)
            && queue[fetched & Mask()].load(std::memory_order_acquire) == nullptr) {
            if (!queueFetched.compare_exchange_weak(fetched, fetched + 1,
                std::memory_order_release, std::memory_order_relaxed)) {
                continue;
            }
            fetched = queueFetched.load(std::memory_order_relaxed);
        }
    }
};
