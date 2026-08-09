#include "models/transparency/jobs/influencespherecull.h"

#include <algorithm>
#include <vector>

void CullInfluenceSpheresForView(const influenceSphereCullParms_t* parms) {
    if (parms == nullptr || parms->visibleInfluenceSpheres == nullptr) {
        return;
    }

    visibleInfluenceSpheres_t& output = *parms->visibleInfluenceSpheres;
    output.numSpheres = 0;
    if (parms->influenceSpheres == nullptr ||
            parms->numInfluenceSpheres <= 0) {
        return;
    }

    std::vector<int> visible;
    visible.reserve((std::min)(parms->numInfluenceSpheres,
        visibleInfluenceSpheres_t::MAX_SPHERES));

    for (int index = 0; index < parms->numInfluenceSpheres; ++index) {
        const influenceSphere_t& sphere = parms->influenceSpheres[index];
        const idVec3 relative = sphere.center - parms->viewOrg;
        const float depth = relative.Dot(parms->viewFwd);
        const float extent = sphere.outerRadius * 2.0f;
        if (depth + extent < parms->nearDist ||
                depth - extent > parms->farDist) {
            continue;
        }

        const idVec3 lateral = relative - parms->viewFwd * depth;
        const float horizontal = lateral.Dot(parms->viewLeft);
        const float horizontalLimit = depth * parms->fov.x;
        if (horizontal + extent < -horizontalLimit ||
                horizontal - extent > horizontalLimit) {
            continue;
        }

        const float vertical = lateral.Dot(parms->viewUp);
        const float verticalLimit = depth * parms->fov.y;
        if (vertical + extent < -verticalLimit ||
                vertical - extent > verticalLimit) {
            continue;
        }
        visible.push_back(index);
    }

    if (visible.size() > visibleInfluenceSpheres_t::MAX_SPHERES) {
        std::nth_element(visible.begin(),
            visible.begin() + visibleInfluenceSpheres_t::MAX_SPHERES,
            visible.end(), [&](int left, int right) {
                return parms->influenceSpheres[left].angle >
                    parms->influenceSpheres[right].angle;
            });
        visible.resize(visibleInfluenceSpheres_t::MAX_SPHERES);
    }
    std::sort(visible.begin(), visible.end());

    for (int index : visible) {
        output.spheres[output.numSpheres++] = parms->influenceSpheres[index];
    }
}
