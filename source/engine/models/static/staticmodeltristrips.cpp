#include "models/static/staticmodeltristrips.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <vector>

namespace {

using Triangle = std::array<std::uint16_t, 3>;

Triangle RotateMinimumFirst(const std::uint16_t* indexes) {
    Triangle best{indexes[0], indexes[1], indexes[2]};
    const Triangle second{indexes[1], indexes[2], indexes[0]};
    const Triangle third{indexes[2], indexes[0], indexes[1]};
    if (second < best) best = second;
    if (third < best) best = third;
    return best;
}

bool FindOrientedThird(const Triangle& triangle, const std::uint16_t a,
        const std::uint16_t b, const bool odd,
        std::uint16_t& third) {
    // A strip reverses winding on every emitted index.
    const std::uint16_t edgeA = odd ? b : a;
    const std::uint16_t edgeB = odd ? a : b;
    for (int rotation = 0; rotation < 3; ++rotation) {
        if (triangle[rotation] == edgeA &&
            triangle[(rotation + 1) % 3] == edgeB) {
            third = triangle[(rotation + 2) % 3];
            return true;
        }
    }
    return false;
}

} // namespace

void PutIndexesInSortedOrderForComparison(const int numIndexes,
        std::uint16_t* indexes) {
    if (indexes == nullptr || numIndexes < 3) return;
    const int triangleCount = numIndexes / 3;
    std::vector<Triangle> triangles(static_cast<std::size_t>(triangleCount));
    for (int triangle = 0; triangle < triangleCount; ++triangle)
        triangles[triangle] = RotateMinimumFirst(indexes + triangle * 3);
    std::sort(triangles.begin(), triangles.end());
    std::memcpy(indexes, triangles.data(),
        triangles.size() * sizeof(Triangle));
}

int RemoveDuplicatedTrianglesFromSortedList(const int numIndexes,
        std::uint16_t* indexes) {
    if (indexes == nullptr || numIndexes < 6) return numIndexes;
    int output = 3;
    for (int input = 3; input + 2 < numIndexes; input += 3) {
        if (indexes[input] == indexes[output - 3] &&
            indexes[input + 1] == indexes[output - 2] &&
            indexes[input + 2] == indexes[output - 1]) continue;
        if (output != input)
            std::memmove(indexes + output, indexes + input,
                3 * sizeof(std::uint16_t));
        output += 3;
    }
    return output;
}

void StripIndexesToTriangleIndexes(const std::uint16_t* stripIndexes,
        const int numStripIndexes,
        idList<std::uint16_t, 5>& triangleIndexes) {
    triangleIndexes.Clear();
    int cursor = 0;
    while (cursor < numStripIndexes) {
        while (cursor < numStripIndexes && stripIndexes[cursor] == 0xFFFFu)
            ++cursor;
        const int start = cursor;
        while (cursor < numStripIndexes && stripIndexes[cursor] != 0xFFFFu)
            ++cursor;
        const int count = cursor - start;
        for (int index = 2; index < count; ++index) {
            std::uint16_t a = stripIndexes[start + index - 2];
            std::uint16_t b = stripIndexes[start + index - 1];
            const std::uint16_t c = stripIndexes[start + index];
            if ((index & 1) != 0) std::swap(a, b);
            if (a == b || a == c || b == c) continue;
            triangleIndexes.Append(a);
            triangleIndexes.Append(b);
            triangleIndexes.Append(c);
        }
    }
}

void TriangleStripper(const std::uint16_t* indexes, const int numIndexes,
        idList<std::uint16_t, 5>& stripIndexes) {
    stripIndexes.Clear();
    if (indexes == nullptr || numIndexes < 3) return;
    const int triangleCount = numIndexes / 3;
    std::vector<Triangle> triangles(static_cast<std::size_t>(triangleCount));
    std::vector<bool> used(static_cast<std::size_t>(triangleCount));
    for (int triangle = 0; triangle < triangleCount; ++triangle) {
        triangles[triangle] = {indexes[triangle * 3],
            indexes[triangle * 3 + 1], indexes[triangle * 3 + 2]};
    }

    for (int seed = 0; seed < triangleCount; ++seed) {
        if (used[seed]) continue;
        if (stripIndexes.Num() != 0) stripIndexes.Append(0xFFFFu);
        stripIndexes.Append(triangles[seed][0]);
        stripIndexes.Append(triangles[seed][1]);
        stripIndexes.Append(triangles[seed][2]);
        used[seed] = true;
        bool extended = true;
        while (extended) {
            extended = false;
            const int stripLength = stripIndexes.Num();
            const std::uint16_t a = stripIndexes[stripLength - 2];
            const std::uint16_t b = stripIndexes[stripLength - 1];
            const bool odd = (stripLength - 3) % 2 != 0;
            for (int triangle = 0; triangle < triangleCount; ++triangle) {
                if (used[triangle]) continue;
                std::uint16_t third = 0;
                if (FindOrientedThird(triangles[triangle], a, b, odd,
                        third)) {
                    stripIndexes.Append(third);
                    used[triangle] = true;
                    extended = true;
                    break;
                }
            }
        }
    }
}

