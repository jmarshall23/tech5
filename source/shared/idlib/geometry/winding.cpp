#include "idlib/geometry/winding.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <malloc.h>

idWinding::idWinding()
    : numPoints(0), p(nullptr), allocedSize(0) {
}

idWinding::idWinding(const idWinding& other)
    : idWinding() {
    *this = other;
}

idWinding::~idWinding() {
    _aligned_free(p);
    p = nullptr;
}

idWinding& idWinding::operator=(const idWinding& other) {
    if (this != &other && ReAllocate(other.numPoints, false)) {
        numPoints = other.numPoints;
        if (numPoints > 0) {
            std::memcpy(p, other.p,
                static_cast<std::size_t>(numPoints) * sizeof(idVec5));
        }
    }
    return *this;
}

void idWinding::Clear() {
    numPoints = 0;
    allocedSize = 0;
    _aligned_free(p);
    p = nullptr;
}

bool idWinding::ReAllocate(const int count, const bool keep) {
    const int newSize = (count + 3) & ~3;
    idVec5* const replacement = static_cast<idVec5*>(_aligned_malloc(
        static_cast<std::size_t>(newSize) * sizeof(idVec5), 16));
    if (replacement == nullptr && newSize > 0) {
        return false;
    }
    if (keep && p != nullptr && numPoints > 0) {
        std::memcpy(replacement, p,
            static_cast<std::size_t>((std::min)(numPoints, newSize)) *
                sizeof(idVec5));
    }
    _aligned_free(p);
    p = replacement;
    allocedSize = newSize;
    if (numPoints > allocedSize) {
        numPoints = allocedSize;
    }
    return true;
}

void idWinding::AddPoint(const idVec3& point) {
    if (numPoints + 1 > allocedSize &&
        !ReAllocate(numPoints + 1, true)) {
        return;
    }
    p[numPoints++] = idVec5(point.x, point.y, point.z, 0.0f, 0.0f);
}

void idWinding::AddPoint(const idVec5& point) {
    if (numPoints + 1 > allocedSize &&
        !ReAllocate(numPoints + 1, true)) {
        return;
    }
    p[numPoints++] = point;
}

idFixedWinding::idFixedWinding() {
    p = data;
    numPoints = 0;
    allocedSize = 64;
}

idFixedWinding::idFixedWinding(const idFixedWinding& other)
    : idFixedWinding() {
    *this = other;
}

idFixedWinding& idFixedWinding::operator=(const idFixedWinding& other) {
    idWinding::operator=(other);
    return *this;
}

void idWinding::GetBounds(idBounds& bounds) const {
    if (numPoints <= 0) {
        bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        return;
    }
    bounds[0].Set(p[0].x, p[0].y, p[0].z);
    bounds[1] = bounds[0];
    for (int point = 1; point < numPoints; ++point) {
        bounds[0].x = (std::min)(bounds[0].x, p[point].x);
        bounds[0].y = (std::min)(bounds[0].y, p[point].y);
        bounds[0].z = (std::min)(bounds[0].z, p[point].z);
        bounds[1].x = (std::max)(bounds[1].x, p[point].x);
        bounds[1].y = (std::max)(bounds[1].y, p[point].y);
        bounds[1].z = (std::max)(bounds[1].z, p[point].z);
    }
}

bool idWinding::IsHuge(const float radius) const {
    for (int point = 0; point < numPoints; ++point) {
        for (int axis = 0; axis < 3; ++axis) {
            if (p[point][axis] <= -radius || p[point][axis] >= radius) {
                return true;
            }
        }
    }
    return false;
}

idFixedWinding::~idFixedWinding() {
    p = nullptr;
}

void idFixedWinding::Clear() {
    numPoints = 0;
    p = data;
    allocedSize = 64;
}

bool idFixedWinding::ReAllocate(const int count, const bool) {
    if (count <= 64) {
        return true;
    }
    idLibPrint::Warning(
        "idFixedWinding -> MAX_POINTS_ON_WINDING overflowed");
    return false;
}

int idFixedWinding::SplitInPlace(const idPlane& plane,
    const float epsilon, idFixedWinding* const back) {
    if (back == nullptr) {
        return 0;
    }

    float distances[65]{};
    int sides[65]{};
    int counts[3]{};
    for (int index = 0; index < numPoints; ++index) {
        distances[index] = plane.a * p[index].x + plane.b * p[index].y +
            plane.c * p[index].z + plane.d;
        if (distances[index] > epsilon) {
            sides[index] = 0;
        } else if (distances[index] < -epsilon) {
            sides[index] = 1;
        } else {
            sides[index] = 2;
        }
        ++counts[sides[index]];
    }
    if (counts[1] == 0) {
        return counts[0] != 0 ? 0 : 2;
    }
    if (counts[0] == 0) {
        return 1;
    }

    distances[numPoints] = distances[0];
    sides[numPoints] = sides[0];
    idFixedWinding front;
    back->Clear();
    for (int index = 0; index < numPoints; ++index) {
        const idVec5& current = p[index];
        if (sides[index] == 2) {
            front.AddPoint(current);
            back->AddPoint(current);
        } else if (sides[index] == 0) {
            front.AddPoint(current);
        } else {
            back->AddPoint(current);
        }

        if (sides[index + 1] == 2 ||
            sides[index + 1] == sides[index]) {
            continue;
        }
        const idVec5& next = p[(index + 1) % numPoints];
        const float fraction = distances[index] /
            (distances[index] - distances[index + 1]);
        idVec5 split;
        for (int component = 0; component < 5; ++component) {
            split[component] = current[component] +
                fraction * (next[component] - current[component]);
        }
        if (plane.a == 1.0f) split.x = -plane.d;
        else if (plane.a == -1.0f) split.x = plane.d;
        if (plane.b == 1.0f) split.y = -plane.d;
        else if (plane.b == -1.0f) split.y = plane.d;
        if (plane.c == 1.0f) split.z = -plane.d;
        else if (plane.c == -1.0f) split.z = plane.d;
        front.AddPoint(split);
        back->AddPoint(split);
    }
    Clear();
    for (int index = 0; index < front.numPoints; ++index) {
        AddPoint(front[index]);
    }
    return 3;
}
