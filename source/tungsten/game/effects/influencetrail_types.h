#pragma once

#ifndef TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
#define TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
class idEntityInfluenceTrail {
public:
    idEntityInfluenceTrail()
        : innerRadius(32.0f)
        , outerRadius(64.0f)
        , angle(0.0f)
        , trailDist(32.0f)
        , trailFadeInTime(0.25f)
        , trailFadeOutTime(2.0f) {
    }

    float innerRadius;
    float outerRadius;
    float angle;
    float trailDist;
    float trailFadeInTime;
    float trailFadeOutTime;
};
#endif

static_assert(sizeof(idEntityInfluenceTrail) == 24,
    "Recovered entity-influence-trail ABI changed");
