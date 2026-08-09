#pragma once

#include "models/transparency/jobs/influencespheredata.h"

#include "idlib/math/vector.h"

struct influenceSphereCullParms_t {
    float nearDist;
    float farDist;
    idVec2 fov;
    idVec3 viewOrg;
    idVec3 viewFwd;
    idVec3 viewLeft;
    idVec3 viewUp;
    const influenceSphere_t* influenceSpheres;
    int numInfluenceSpheres;
    visibleInfluenceSpheres_t* visibleInfluenceSpheres;
};

void CullInfluenceSpheresForView(const influenceSphereCullParms_t* parms);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(influenceSphereCullParms_t) == 76,
    "Recovered influence-sphere cull parameters ABI changed");
#endif
