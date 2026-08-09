#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstring>

class idBase64 {
public:
    unsigned char* data;
    int len;
    int alloced;

    idBase64() : data(nullptr), len(0), alloced(0) {}
    idBase64(const idBase64& other) : idBase64() {
        if (EnsureAlloced(other.len + 1)) {
            std::memcpy(data, other.data, static_cast<std::size_t>(other.len + 1));
            len = other.len;
        }
    }
    ~idBase64() { std::free(data); }

    idBase64& operator=(const idBase64& other) {
        if (this != &other && EnsureAlloced(other.len + 1)) {
            std::memcpy(data, other.data, static_cast<std::size_t>(other.len + 1));
            len = other.len;
        }
        return *this;
    }

    void Encode(const unsigned char* source, int size);
    int Decode(unsigned char* destination) const;

    const char* c_str() const {
        return data == nullptr ? "" : reinterpret_cast<const char*>(data);
    }
    int Length() const { return len; }

private:
    bool EnsureAlloced(const int amount) {
        if (amount <= alloced) return true;
        void* replacement = std::realloc(data, static_cast<std::size_t>(amount));
        if (replacement == nullptr) return false;
        data = static_cast<unsigned char*>(replacement);
        alloced = amount;
        return true;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBase64) == 12, "Recovered idBase64 ABI changed");
#endif
