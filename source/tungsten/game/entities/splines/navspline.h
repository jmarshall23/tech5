#pragma once

#include "navsplinevalue.h"
#include "navsplinepathpos.h"
#include "../entityptr.h"
#include "../../../../shared/idlib/bv/bounds.h"
#include "../../../../shared/idlib/containers/list.h"
#include "../../../../shared/idlib/math/curve.h"

class idEntity;
class idNavSplinePath;

enum navSplineType_t : int {
    NAV_SPLINE_TYPE_DEFAULT = 0,
    NAV_SPLINE_TYPE_VEHICLE_AI = 1,
    NAV_SPLINE_TYPE_QUEST = 2,
};

struct navSplineConnection_t {
    idNavSpline* navSpline;
    idVec3 forward;
};

class idNavSpline {
public:
    idNavSpline();
    ~idNavSpline();

    idVec3 GetWorldPos(float distance);
    idVec3 GetForward(float distance);
    idNavSpline* GetNextSplines(int num);
    idNavSpline* GetPrevSplines(int num);
    int GetDirFromLinkedSpline(idNavSpline* spline);
    void CalcBounds();
    bool IsDeadEnd();

    idNavSplinePath* splinePath;
    idCurve_Spline<idVec3>* curve;
    float width;
    float length;
    bool traversed;
    bool isTempSpline;
    idList<navSplineConnection_t, 5> next;
    idList<navSplineConnection_t, 5> prev;
    idList<idEntityPtr<idEntity>, 5> entityList;
    navSplinePathNode_t* startNode;
    navSplinePathNode_t* endNode;
    idNavSpline* bestNext;
    idNavSpline* bestPrev;
    idBounds bounds;
    int drawtime;
};

struct navSplineTrav_t {
    idNavSplinePosition pathPos;
    float traversalDist;
    int dir;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(navSplineConnection_t) == 16,
    "Recovered navigation-spline connection ABI changed");
static_assert(sizeof(idNavSpline) == 112,
    "Recovered navigation-spline object ABI changed");
static_assert(sizeof(navSplineTrav_t) == 20,
    "Recovered navigation-spline traversal ABI changed");
#endif
