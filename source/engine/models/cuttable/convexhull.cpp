#include "models/cuttable/convexhull.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

namespace {

std::int64_t HullCross(const idVec2i& origin, const idVec2i& a,
        const idVec2i& b) {
    return (static_cast<std::int64_t>(a.x) - origin.x) *
            (static_cast<std::int64_t>(b.y) - origin.y) -
        (static_cast<std::int64_t>(a.y) - origin.y) *
            (static_cast<std::int64_t>(b.x) - origin.x);
}

float RemovalWeight(const idVec2i& previous, const idVec2i& current,
        const idVec2i& following) {
    return static_cast<float>(std::llabs(HullCross(previous, current, following)));
}

} // namespace

void idConvexHull::Create(const idList<idVec2i, 5>& points,
        const float shrink) {
    vertices.Clear();
    if (points.Num() <= 0) return;

    std::vector<idVec2i> sorted(points.Ptr(), points.Ptr() + points.Num());
    std::sort(sorted.begin(), sorted.end(), [](const idVec2i& a,
            const idVec2i& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());

    std::vector<idVec2i> hull;
    hull.reserve(sorted.size() * 2);
    for (const idVec2i& point : sorted) {
        while (hull.size() >= 2 && HullCross(hull[hull.size() - 2],
                hull.back(), point) <= 0) {
            hull.pop_back();
        }
        hull.push_back(point);
    }
    const std::size_t lowerCount = hull.size();
    for (std::size_t index = sorted.size(); index-- > 0;) {
        const idVec2i& point = sorted[index];
        while (hull.size() > lowerCount && HullCross(hull[hull.size() - 2],
                hull.back(), point) <= 0) {
            hull.pop_back();
        }
        hull.push_back(point);
    }
    if (hull.size() > 1) hull.pop_back();

    // The Xbox implementation capped complex hulls at ten points by removing
    // the least significant corner area first.
    while (hull.size() > 10) {
        std::size_t least = 0;
        float leastWeight = RemovalWeight(hull.back(), hull[0], hull[1]);
        for (std::size_t index = 1; index < hull.size(); ++index) {
            const float weight = RemovalWeight(hull[index - 1], hull[index],
                hull[(index + 1) % hull.size()]);
            if (weight < leastWeight) {
                least = index;
                leastWeight = weight;
            }
        }
        hull.erase(hull.begin() + static_cast<std::ptrdiff_t>(least));
    }

    for (const idVec2i& point : hull) {
        vertices.Append(idVec2(static_cast<float>(point.x),
            static_cast<float>(point.y)));
    }

    if (std::fabs(shrink) <= 1.1920929e-7f || vertices.Num() < 2) return;
    for (int index = 0; index < vertices.Num(); ++index) {
        idVec2& current = vertices[index];
        idVec2& previous = vertices[(index + vertices.Num() - 1) % vertices.Num()];
        const float dx = previous.x - current.x;
        const float dy = previous.y - current.y;
        const float length = std::sqrt(dx * dx + dy * dy);
        if (length < std::fabs(shrink) * 2.0f || length <= 1.0e-20f) continue;
        const float scale = shrink / length;
        previous.x -= dx * scale;
        previous.y -= dy * scale;
        current.x += dx * scale;
        current.y += dy * scale;
    }
}
