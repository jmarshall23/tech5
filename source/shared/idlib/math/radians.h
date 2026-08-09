#pragma once

#include "idlib/typesafenumber.h"

enum RadiansUnique_t : int;
typedef idTypesafeNumber<float, RadiansUnique_t> radians_t;

static_assert(sizeof(radians_t) == 4, "Recovered radians_t ABI changed");

