#pragma once

#include "gamelib/animstack/animator_base.h"

// The recovered client animator adds no state or virtual slots beyond the
// base animator; its distinct type selects a client-side vtable at runtime.
class idAnimator_Client : public idAnimator_Base {
public:
    ~idAnimator_Client() override = default;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Client) == 40,
    "Recovered idAnimator_Client ABI changed");
#endif
