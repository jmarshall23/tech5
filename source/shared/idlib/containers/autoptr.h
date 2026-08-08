#pragma once

#include <cstdint>
#include <cstdlib>

template<typename type>
class idAutoPtr {
public:
    explicit idAutoPtr(type* pointer = nullptr)
        : Pointee(pointer) {
    }

    ~idAutoPtr() {
        delete Pointee;
    }

    idAutoPtr(idAutoPtr&& other) noexcept
        : Pointee(other.Release()) {
    }

    idAutoPtr& operator=(idAutoPtr&& other) noexcept {
        if (this != &other) {
            Reset(other.Release());
        }
        return *this;
    }

    idAutoPtr(const idAutoPtr&) = delete;
    idAutoPtr& operator=(const idAutoPtr&) = delete;

    type* Get() const { return Pointee; }
    type* operator->() const { return Pointee; }
    type& operator*() const { return *Pointee; }
    explicit operator bool() const { return Pointee != nullptr; }

    type* Release() {
        type* const result = Pointee;
        Pointee = nullptr;
        return result;
    }

    void Reset(type* pointer = nullptr) {
        if (Pointee != pointer) {
            delete Pointee;
            Pointee = pointer;
        }
    }

private:
    type* Pointee;
};

template<typename type>
class idAutoPtr_Array {
public:
    explicit idAutoPtr_Array(type* pointer = nullptr)
        : Pointee(pointer) {
    }

    virtual ~idAutoPtr_Array() {
        std::free(Pointee);
    }

    idAutoPtr_Array(const idAutoPtr_Array&) = delete;
    idAutoPtr_Array& operator=(const idAutoPtr_Array&) = delete;

    type* Get() const { return Pointee; }
    type& operator[](const int index) const { return Pointee[index]; }

    type* Release() {
        type* const result = Pointee;
        Pointee = nullptr;
        return result;
    }

private:
    type* Pointee;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAutoPtr<int>) == 4, "Recovered idAutoPtr ABI changed");
static_assert(sizeof(idAutoPtr_Array<int>) == 8,
    "Recovered idAutoPtr_Array ABI changed");
#endif
