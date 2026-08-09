#include "models/transparency/rendermodeltransparency.h"

#include <cstring>
#include <malloc.h>

namespace {

constexpr std::size_t RECOVERED_SORT_PARMS_SIZE = 0x30;
constexpr std::size_t RECOVERED_SORT_RESULT_SIZE = 0x10;

void* AllocateAligned(std::size_t size) {
    void* memory = _aligned_malloc(size, 16);
    if (memory != nullptr) {
        std::memset(memory, 0, size);
    }
    return memory;
}

} // namespace

idRenderModelTransparency::idRenderModelTransparency()
    : sortParms(static_cast<transSortParms_t*>(
          AllocateAligned(RECOVERED_SORT_PARMS_SIZE))),
      sortResult(static_cast<transSortResult_t*>(
          AllocateAligned(RECOVERED_SORT_RESULT_SIZE))),
      currentSphereIndex(0),
      visibleInfluenceSpheres(static_cast<visibleInfluenceSpheres_t*>(
          AllocateAligned(sizeof(visibleInfluenceSpheres_t)))),
      influenceSphereCullParms(static_cast<influenceSphereCullParms_t*>(
          AllocateAligned(sizeof(influenceSphereCullParms_t)))) {
    influenceSpheres[0] = static_cast<influenceSphere_t*>(
        AllocateAligned(sizeof(influenceSphere_t) * MAX_INFLUENCE_SPHERES));
    influenceSpheres[1] = static_cast<influenceSphere_t*>(
        AllocateAligned(sizeof(influenceSphere_t) * MAX_INFLUENCE_SPHERES));
    numInfluenceSpheres[0] = 0;
    numInfluenceSpheres[1] = 0;
}

idRenderModelTransparency::~idRenderModelTransparency() {
    _aligned_free(influenceSphereCullParms);
    _aligned_free(visibleInfluenceSpheres);
    _aligned_free(influenceSpheres[1]);
    _aligned_free(influenceSpheres[0]);
    _aligned_free(sortResult);
    _aligned_free(sortParms);
}

bool idRenderModelTransparency::UpdateInView(const idRenderView*,
    const idRenderView*, idRenderModelUpdateTools*) {
    // View extraction, renderer job submission and streamed buffer updates
    // are supplied by the renderer-side adapter.
    return false;
}

void idRenderModelTransparency::ClearInfluenceSpheres() {
    numInfluenceSpheres[currentSphereIndex] = 0;
}

bool idRenderModelTransparency::AddInfluenceSphere(const idVec3& center,
    float innerRadius, float outerRadius, float angle) {
    int& count = numInfluenceSpheres[currentSphereIndex];
    if (influenceSpheres[currentSphereIndex] == nullptr ||
        count >= MAX_INFLUENCE_SPHERES) {
        return false;
    }

    influenceSphere_t& sphere = influenceSpheres[currentSphereIndex][count++];
    sphere.center = center;
    sphere.innerRadius = innerRadius;
    sphere.outerRadius = outerRadius;
    sphere.angle = angle;
    return true;
}

void idRenderModelTransparency::GenerateVisibleInfluenceSphereList(
    const influenceSphereCullParms_t& viewParms) {
    if (visibleInfluenceSpheres == nullptr ||
        influenceSphereCullParms == nullptr) {
        return;
    }

    *influenceSphereCullParms = viewParms;
    influenceSphereCullParms->influenceSpheres =
        influenceSpheres[currentSphereIndex];
    influenceSphereCullParms->numInfluenceSpheres =
        numInfluenceSpheres[currentSphereIndex];
    influenceSphereCullParms->visibleInfluenceSpheres =
        visibleInfluenceSpheres;

    CullInfluenceSpheresForView(influenceSphereCullParms);
    currentSphereIndex ^= 1;
}

const visibleInfluenceSpheres_t&
idRenderModelTransparency::GetVisibleInfluenceSpheres() const {
    return *visibleInfluenceSpheres;
}

int idRenderModelTransparency::GetNumInfluenceSpheres() const {
    return numInfluenceSpheres[currentSphereIndex];
}
