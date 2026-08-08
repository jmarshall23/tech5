#pragma once

#include "str.h"

#include <algorithm>
#include <cfloat>
#include <cstring>

class idToken : public idStr {
public:
    idToken()
        : type(0), subtype(0), line(0), linesCrossed(0), flags(0),
          intvalue(0), floatvalue(-FLT_MAX), whiteSpaceStart_p(nullptr),
          whiteSpaceEnd_p(nullptr), next(nullptr) {
    }

    int type;
    int subtype;
    int line;
    int linesCrossed;
    int flags;
    unsigned int intvalue;
    float floatvalue;
    const char* whiteSpaceStart_p;
    const char* whiteSpaceEnd_p;
    idToken* next;
};

template<int BUFFER_SIZE>
class idTokenStatic : public idToken {
public:
    idTokenStatic() {
        UseStaticBufferRecovered(buffer, BUFFER_SIZE);
    }

    explicit idTokenStatic(const idStr& text) {
        UseStaticBufferRecovered(buffer, BUFFER_SIZE);
        const int copyLength = std::min(text.Length(), BUFFER_SIZE - 1);
        if (copyLength > 0) {
            std::memcpy(data, text.c_str(), static_cast<std::size_t>(copyLength));
        }
        data[copyLength] = '\0';
        len = copyLength;
    }

private:
    char buffer[BUFFER_SIZE];
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idToken) == 72, "Recovered idToken ABI changed");
static_assert(sizeof(idTokenStatic<256>) == 328,
    "Recovered idTokenStatic<256> ABI changed");
#endif

