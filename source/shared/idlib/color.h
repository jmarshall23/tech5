#pragma once

#include "math/vector.h"

#include <cstdint>

// tungsten.exe.h type 12194.
class idColor {
public:
    float r;
    float g;
    float b;
    float a;

    idColor() = default;

    idColor(
        const float red,
        const float green,
        const float blue,
        const float alpha = 1.0f
    )
        : r(red)
        , g(green)
        , b(blue)
        , a(alpha) {
    }

    void Set(float red, float green, float blue, float alpha = 1.0f) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }

    const char* ToString(int precision, bool parens) const;
    void Lerp(const idColor& from, const idColor& to, float lerp);

    static std::uint32_t PackColor(const idVec4& color);
    static void UnpackColor(std::uint32_t color, idVec4& unpackedColor);

    bool SetFromString(const char* str, bool parseParens);

    static const idColor colorBlack;
    static const idColor colorWhite;
    static const idColor colorRed;
    static const idColor colorGreen;
    static const idColor colorBlue;
    static const idColor colorYellow;
    static const idColor colorMagenta;
    static const idColor colorCyan;
    static const idColor colorOrange;
    static const idColor colorPurple;
    static const idColor colorPink;
    static const idColor colorBrown;
    static const idColor colorLtGrey;
    static const idColor colorMdGrey;
    static const idColor colorDkGrey;
    static const idColor colorDefault;
    static const idColor colorXAxis;
    static const idColor colorYAxis;
    static const idColor colorZAxis;
};

static_assert(sizeof(idColor) == 16, "Recovered idColor layout changed");
