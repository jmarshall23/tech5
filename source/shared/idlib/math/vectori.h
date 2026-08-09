#pragma once

#include <cassert>

class idVec2i {
public:
    int x;
    int y;

    idVec2i() = default;
    idVec2i(const int newX, const int newY) : x(newX), y(newY) {}
    void Set(const int newX, const int newY) { x = newX; y = newY; }
    void Zero() { x = 0; y = 0; }
    int operator[](const int index) const {
        assert(index >= 0 && index < 2); return (&x)[index];
    }
    int& operator[](const int index) {
        assert(index >= 0 && index < 2); return (&x)[index];
    }
    bool operator==(const idVec2i& other) const { return x == other.x && y == other.y; }
    bool operator!=(const idVec2i& other) const { return !(*this == other); }
};

class idVec3i {
public:
    int x;
    int y;
    int z;

    idVec3i() = default;
    idVec3i(const int newX, const int newY, const int newZ)
        : x(newX), y(newY), z(newZ) {}
    void Set(const int newX, const int newY, const int newZ) {
        x = newX; y = newY; z = newZ;
    }
    void Zero() { x = 0; y = 0; z = 0; }
    int operator[](const int index) const {
        assert(index >= 0 && index < 3); return (&x)[index];
    }
    int& operator[](const int index) {
        assert(index >= 0 && index < 3); return (&x)[index];
    }
    bool operator==(const idVec3i& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    bool operator!=(const idVec3i& other) const { return !(*this == other); }
};

static_assert(sizeof(idVec2i) == 8, "Recovered idVec2i ABI changed");
static_assert(sizeof(idVec3i) == 12, "Recovered idVec3i ABI changed");

