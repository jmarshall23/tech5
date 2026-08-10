#pragma once

class ssColor {
public:
    ssColor(int red, int green, int blue, int alpha);

    float r;
    float g;
    float b;
    float a;
};

static_assert(sizeof(ssColor) == 16,
    "Recovered SuperScript color ABI changed");
