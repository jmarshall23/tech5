#pragma once

#include "surface.h"

template<class type_t>
class idCurve_Spline;

class idSurface_SweptSpline : public idSurface {
public:
    idSurface_SweptSpline() : spline(nullptr), sweptSpline(nullptr) {}
    ~idSurface_SweptSpline() = default;

    idCurve_Spline<idVec4>* spline;
    idCurve_Spline<idVec4>* sweptSpline;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSurface_SweptSpline) == 72,
    "Recovered idSurface_SweptSpline ABI changed");
#endif
