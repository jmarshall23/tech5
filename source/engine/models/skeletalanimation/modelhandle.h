#pragma once

#include "idlib/handle.h"

#include <cstdint>

enum invalidDecalHandle_t : int;

using decalHandle_t = idHandle<int, invalidDecalHandle_t, -1>;
using modelHandleType_t = std::uint16_t;
