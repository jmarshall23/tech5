#pragma once

// The retail class is spread across many ai2_*.cpp translation units.
// Keep one canonical focused declaration surface while those units are
// recovered, instead of allowing the generated partial headers to define
// incompatible versions of idAI2.
#include "ai2_debug.h"
#include "ai2_interactions.h"
#include "ai2_jobs.h"
#include "ai2_script.h"
#include "ai2_utils.h"
