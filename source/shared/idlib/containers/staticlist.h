#pragma once

#include "idlib/containers/list.h"

template<typename type, int capacity>
class idStaticList : public idList<type, 5> {
public:
    type staticList[capacity];

    idStaticList() { this->SetStaticBuffer(staticList, capacity); }
    idStaticList(const idStaticList& other) : idStaticList() { *this = other; }
    idStaticList& operator=(const idStaticList& other) {
        this->SetNum(other.Num());
        for (int index = 0; index < this->num; ++index)
            staticList[index] = other.staticList[index];
        return *this;
    }
    int Max() const { return capacity; }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idStaticList<int, 4>) == 32,
    "Recovered idStaticList ABI changed");
#endif

