#include "bounds2d.h"

bool idBounds2D::AddPoint(const idVec2& point) {
    bool expanded = false;

    if (point.x < bounds[0].x) {
        bounds[0].x = point.x;
        expanded = true;
    }
    if (point.x > bounds[1].x) {
        bounds[1].x = point.x;
        expanded = true;
    }
    if (point.y < bounds[0].y) {
        bounds[0].y = point.y;
        expanded = true;
    }
    if (point.y > bounds[1].y) {
        bounds[1].y = point.y;
        expanded = true;
    }

    return expanded;
}

bool idBounds2D::ContainsPoint(const idVec2& point) const {
    return point.x >= bounds[0].x
        && point.x <= bounds[1].x
        && point.y >= bounds[0].y
        && point.y <= bounds[1].y;
}

bool idBounds2D::IntersectBounds(const idBounds2D& other) const {
    if (&other == this) {
        return true;
    }

    return other.bounds[0].x <= bounds[1].x
        && other.bounds[1].x >= bounds[0].x
        && other.bounds[0].y <= bounds[1].y
        && other.bounds[1].y >= bounds[0].y;
}

