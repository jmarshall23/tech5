#include "color.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const idColor idColor::colorBlack(0.00f, 0.00f, 0.00f, 1.00f);
const idColor idColor::colorWhite(1.00f, 1.00f, 1.00f, 1.00f);
const idColor idColor::colorRed(1.00f, 0.00f, 0.00f, 1.00f);
const idColor idColor::colorGreen(0.00f, 1.00f, 0.00f, 1.00f);
const idColor idColor::colorBlue(0.00f, 0.00f, 1.00f, 1.00f);
const idColor idColor::colorYellow(1.00f, 1.00f, 0.00f, 1.00f);
const idColor idColor::colorMagenta(1.00f, 0.00f, 1.00f, 1.00f);
const idColor idColor::colorCyan(0.00f, 1.00f, 1.00f, 1.00f);
const idColor idColor::colorOrange(1.00f, 0.50f, 0.00f, 1.00f);
const idColor idColor::colorPurple(0.60f, 0.00f, 0.60f, 1.00f);
const idColor idColor::colorPink(0.73f, 0.40f, 0.48f, 1.00f);
const idColor idColor::colorBrown(0.40f, 0.35f, 0.08f, 1.00f);
const idColor idColor::colorLtGrey(0.75f, 0.75f, 0.75f, 1.00f);
const idColor idColor::colorMdGrey(0.50f, 0.50f, 0.50f, 1.00f);
const idColor idColor::colorDkGrey(0.25f, 0.25f, 0.25f, 1.00f);
const idColor idColor::colorDefault = idColor::colorWhite;

// These axis assignments look unusual but are explicit in the recovered
// dynamic initializers: X=blue, Y=red, Z=green.
const idColor idColor::colorXAxis = idColor::colorBlue;
const idColor idColor::colorYAxis = idColor::colorRed;
const idColor idColor::colorZAxis = idColor::colorGreen;

namespace {

constexpr int kStringBufferSize = 4096;

std::uint8_t FloatToByte(const float value) {
    const int integer = static_cast<int>(value * 255.0f);
    return static_cast<std::uint8_t>(std::max(0, std::min(255, integer)));
}

void SkipWhitespace(const char*& cursor) {
    while (*cursor != '\0'
        && std::isspace(static_cast<unsigned char>(*cursor)) != 0) {
        ++cursor;
    }
}

bool ParseFloat(const char*& cursor, float& value) {
    SkipWhitespace(cursor);
    char* end = nullptr;
    value = std::strtof(cursor, &end);
    if (end == cursor) {
        return false;
    }
    cursor = end;
    return true;
}

void AppendFloat(
    char* destination,
    const int destinationSize,
    int& length,
    const float value,
    const int precision,
    const bool addLeadingSpace
) {
    char number[64];
    const int safePrecision = std::max(0, std::min(9, precision));
    std::snprintf(number, sizeof(number), "%.*f", safePrecision, value);

    if (safePrecision > 0) {
        int numberLength = static_cast<int>(std::strlen(number));
        while (numberLength > 0 && number[numberLength - 1] == '0') {
            number[--numberLength] = '\0';
        }
        if (numberLength > 0 && number[numberLength - 1] == '.') {
            number[--numberLength] = '\0';
        }
    }

    const int written = std::snprintf(
        destination + length,
        static_cast<std::size_t>(destinationSize - length),
        addLeadingSpace ? " %s" : "%s",
        number
    );
    if (written > 0) {
        length = std::min(destinationSize - 1, length + written);
    }
}

} // namespace

const char* idColor::ToString(const int precision, const bool parens) const {
    static thread_local int bufferIndex = 0;
    static thread_local char buffers[4][kStringBufferSize];

    char values[kStringBufferSize];
    values[0] = '\0';
    int length = 0;
    AppendFloat(values, kStringBufferSize, length, r, precision, false);
    AppendFloat(values, kStringBufferSize, length, g, precision, true);
    AppendFloat(values, kStringBufferSize, length, b, precision, true);
    AppendFloat(values, kStringBufferSize, length, a, precision, true);

    char* const result = buffers[bufferIndex];
    bufferIndex = (bufferIndex + 1) & 3;
    if (parens) {
        std::snprintf(result, kStringBufferSize, "( %s )", values);
    } else {
        std::snprintf(result, kStringBufferSize, "%s", values);
    }
    return result;
}

void idColor::Lerp(
    const idColor& from,
    const idColor& to,
    const float lerp
) {
    if (lerp <= 0.0f) {
        *this = from;
    } else if (lerp >= 1.0f) {
        *this = to;
    } else {
        r = from.r + (to.r - from.r) * lerp;
        g = from.g + (to.g - from.g) * lerp;
        b = from.b + (to.b - from.b) * lerp;
        a = from.a + (to.a - from.a) * lerp;
    }
}

std::uint32_t idColor::PackColor(const idVec4& color) {
    const std::uint32_t red = FloatToByte(color.x);
    const std::uint32_t green = FloatToByte(color.y);
    const std::uint32_t blue = FloatToByte(color.z);
    const std::uint32_t alpha = FloatToByte(color.w);
    return red | (green << 8) | (blue << 16) | (alpha << 24);
}

void idColor::UnpackColor(
    const std::uint32_t color,
    idVec4& unpackedColor
) {
    constexpr float kByteToFloat = 1.0f / 255.0f;
    unpackedColor.Set(
        static_cast<float>((color >> 0) & 255) * kByteToFloat,
        static_cast<float>((color >> 8) & 255) * kByteToFloat,
        static_cast<float>((color >> 16) & 255) * kByteToFloat,
        static_cast<float>((color >> 24) & 255) * kByteToFloat
    );
}

bool idColor::SetFromString(const char* str, const bool parseParens) {
    if (str == nullptr) {
        return false;
    }

    const char* cursor = str;
    SkipWhitespace(cursor);
    if (parseParens) {
        if (*cursor != '(') {
            return false;
        }
        ++cursor;
    }

    idColor parsed;
    if (!ParseFloat(cursor, parsed.r)
        || !ParseFloat(cursor, parsed.g)
        || !ParseFloat(cursor, parsed.b)
        || !ParseFloat(cursor, parsed.a)) {
        return false;
    }

    SkipWhitespace(cursor);
    if (parseParens) {
        if (*cursor != ')') {
            return false;
        }
        ++cursor;
        SkipWhitespace(cursor);
    }
    if (*cursor != '\0') {
        return false;
    }

    *this = parsed;
    return true;
}
