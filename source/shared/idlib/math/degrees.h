#pragma once

#include "idlib/typesafenumber.h"

enum DegreesUnique_t : int;
typedef idTypesafeNumber<float, DegreesUnique_t> degrees_t;

static_assert(sizeof(degrees_t) == 4, "Recovered degrees_t ABI changed");

