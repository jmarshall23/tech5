#pragma once

// tungsten.exe.h type 12913. Unlike Doom 3 BFG's idScreenRect, this idTech 5
// build uses four 32-bit coordinates and does not store depth bounds here.
class idScreenRect {
public:
    int x1;
    int y1;
    int x2;
    int y2;

    void Clear();
    void Zero();

    bool IsEmpty() const {
        return x1 > x2 || y1 > y2;
    }
};

static_assert(sizeof(idScreenRect) == 16, "Recovered idScreenRect layout changed");

