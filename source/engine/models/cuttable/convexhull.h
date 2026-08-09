#pragma once

#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/vector.h"
#include "idlib/math/vectori.h"

class idConvexHull {
public:
    void Create(const idList<idVec2i, 5>& points, float shrink = 0.0f);

    idStaticList<idVec2, 32> vertices;
};
