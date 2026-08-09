#pragma once

#include "idlib/text/str.h"

template<int bufferSize>
class idStrStatic : public idStr {
public:
    char buffer[bufferSize];

    idStrStatic() { UseStaticBufferRecovered(buffer, bufferSize); }
    idStrStatic(const char* text) : idStrStatic() { idStr::operator=(text); }
    idStrStatic(const idStr& text) : idStrStatic() { idStr::operator=(text); }
    idStrStatic(const idStrStatic& text) : idStrStatic() {
        idStr::operator=(static_cast<const idStr&>(text));
    }
    idStrStatic& operator=(const idStrStatic& text) {
        idStr::operator=(static_cast<const idStr&>(text)); return *this;
    }
    idStrStatic& operator=(const idStr& text) {
        idStr::operator=(text); return *this;
    }
    idStrStatic& operator=(const char* text) {
        idStr::operator=(text); return *this;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idStrStatic<8>) == 40, "Recovered idStrStatic<8> ABI changed");
static_assert(sizeof(idStrStatic<260>) == 292, "Recovered idStrStatic<260> ABI changed");
#endif

