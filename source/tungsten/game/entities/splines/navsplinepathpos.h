#pragma once

#include "../../../../shared/idlib/containers/staticlist.h"
#include "../../../../shared/idlib/math/vector.h"

class idNavSpline;
struct navSplinePathNode_t;

struct navSplineLink_t {
    navSplinePathNode_t* node;
    float nodeDistance;
    idNavSpline* navSpline;
    float splineDistance;
};

struct navSplinePathNode_t {
    struct navSplineSearch_t {
        float distance;
        navSplinePathNode_t* parent;
        idNavSpline* spline;
    };

    navSplinePathNode_t();
    void Init();

    idVec3 position;
    idStaticList<navSplineLink_t, 16> links;
    int index;
    navSplineSearch_t search;
};

static_assert(sizeof(navSplineLink_t) == 16,
    "Recovered navigation-spline link ABI changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(navSplinePathNode_t) == 300,
    "Recovered navigation-spline path-node ABI changed");
#endif
