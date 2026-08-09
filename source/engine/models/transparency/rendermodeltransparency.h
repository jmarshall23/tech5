#pragma once

#include "models/rendermodel.h"
#include "models/transparency/jobs/influencespherecull.h"
#include "models/transparency/jobs/transparencysort.h"

class alignas(16) idRenderModelTransparency : public idRenderModel {
public:
    static constexpr int MAX_INFLUENCE_SPHERES = 1024;

    idRenderModelTransparency();
    ~idRenderModelTransparency() override;

    bool UpdateInView(const idRenderView* view,
        const idRenderView* previousView,
        idRenderModelUpdateTools* tools) override;

    void ClearInfluenceSpheres();
    bool AddInfluenceSphere(const idVec3& center, float innerRadius,
        float outerRadius, float angle);

    // Culls the bank filled during the current frame, then advances to the
    // other bank.  The renderer-facing overload converts an idRenderView to
    // these parameters in the renderer integration layer.
    void GenerateVisibleInfluenceSphereList(
        const influenceSphereCullParms_t& viewParms);

    const visibleInfluenceSpheres_t& GetVisibleInfluenceSpheres() const;
    int GetNumInfluenceSpheres() const;
    int GetCurrentSphereBank() const { return currentSphereIndex; }

    // Recovered opaque transparency-sort blocks.  Their definitions belong
    // to the renderer sort job and are deliberately not duplicated here.
    transSortParms_t* sortParms;
    transSortResult_t* sortResult;
    influenceSphere_t* influenceSpheres[2];
    int numInfluenceSpheres[2];
    int currentSphereIndex;
    visibleInfluenceSpheres_t* visibleInfluenceSpheres;
    influenceSphereCullParms_t* influenceSphereCullParms;

private:
    idRenderModelTransparency(const idRenderModelTransparency&) = delete;
    idRenderModelTransparency& operator=(
        const idRenderModelTransparency&) = delete;
};
