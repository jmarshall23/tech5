#pragma once

#include "../math/vector.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

// Recovered Tungsten vertex layout. Normals and tangents use the observed
// unsigned-byte [-1, 1] encoding; tangent[3] stores the bitangent handedness.
class idDrawVert {
public:
    idVec3 xyz;
    idVec2 st;
    std::uint8_t normal[4];
    std::uint8_t tangent[4];
    std::uint8_t color[4];

    idDrawVert& operator=(const idDrawVert& rhs) = default;

    idVec3 GetNormal() const { return DecodeDirection(normal); }
    idVec3 GetTangent() const { return DecodeDirection(tangent); }

    idVec3 GetBiTangent() const {
        const idVec3 bitangent = GetNormal().Cross(GetTangent());
        return tangent[3] >= 128 ? bitangent : -bitangent;
    }

    void SetNormal(const idVec3& value) { EncodeDirection(value, normal); }
    void SetTangent(const idVec3& value) { EncodeDirection(value, tangent); }

    void SetBiTangent(const idVec3& value) {
        tangent[3] = value.Dot(GetNormal().Cross(GetTangent())) >= 0.0f
            ? std::uint8_t(255)
            : std::uint8_t(0);
    }

    void LerpAll(const idDrawVert& a, const idDrawVert& b, const float fraction) {
        xyz.Set(
            Lerp(a.xyz.x, b.xyz.x, fraction),
            Lerp(a.xyz.y, b.xyz.y, fraction),
            Lerp(a.xyz.z, b.xyz.z, fraction));
        st.Set(
            Lerp(a.st.x, b.st.x, fraction),
            Lerp(a.st.y, b.st.y, fraction));

        const idVec3 interpolatedNormal = Normalize(
            a.GetNormal() + (b.GetNormal() - a.GetNormal()) * fraction);
        const idVec3 interpolatedTangent = Normalize(
            a.GetTangent() + (b.GetTangent() - a.GetTangent()) * fraction);
        const idVec3 interpolatedBiTangent = Normalize(
            a.GetBiTangent() + (b.GetBiTangent() - a.GetBiTangent()) * fraction);
        SetNormal(interpolatedNormal);
        SetTangent(interpolatedTangent);
        SetBiTangent(interpolatedBiTangent);

        for (int component = 0; component < 4; ++component) {
            const int value = static_cast<int>(
                static_cast<float>(a.color[component])
                + (static_cast<float>(b.color[component])
                    - static_cast<float>(a.color[component])) * fraction);
            color[component] = static_cast<std::uint8_t>(
                (std::max)(0, (std::min)(255, value)));
        }
    }

private:
    static float Lerp(const float a, const float b, const float fraction) {
        return a + (b - a) * fraction;
    }

    static idVec3 Normalize(const idVec3& value) {
        const float lengthSqr = value.LengthSqr();
        if (lengthSqr <= 1.0e-30f) {
            return idVec3(0.0f, 0.0f, 0.0f);
        }
        return value * (1.0f / std::sqrt(lengthSqr));
    }

    static idVec3 DecodeDirection(const std::uint8_t value[4]) {
        return Normalize(idVec3(
            static_cast<float>(value[0]) * (2.0f / 255.0f) - 1.0f,
            static_cast<float>(value[1]) * (2.0f / 255.0f) - 1.0f,
            static_cast<float>(value[2]) * (2.0f / 255.0f) - 1.0f));
    }

    static void EncodeDirection(const idVec3& input, std::uint8_t value[4]) {
        const idVec3 direction = Normalize(input);
        for (int component = 0; component < 3; ++component) {
            const float scaled = (direction[component] + 1.0f) * 127.5f + 0.5f;
            value[component] = static_cast<std::uint8_t>(
                (std::max)(0.0f, (std::min)(255.0f, scaled)));
        }
    }
};

static_assert(sizeof(idDrawVert) == 32, "Recovered idDrawVert layout changed");
