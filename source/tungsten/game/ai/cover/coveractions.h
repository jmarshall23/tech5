#pragma once

#include <cstdint>

struct aas2Cover_t;

enum coverAction_t : int {
    COVERACTION_NONE = 0,
    COVERACTION_FIRE_OVER = 1,
    COVERACTION_FIRE_LEAN_LEFT = 2,
    COVERACTION_FIRE_LEAN_RIGHT = 3,
    COVERACTION_FIRE_STEP_LEFT = 4,
    COVERACTION_FIRE_STEP_RIGHT = 5,
    COVERACTION_BLINDFIRE_OVER = 6,
    COVERACTION_BLINDFIRE_LEFT = 7,
    COVERACTION_BLINDFIRE_RIGHT = 8,
    COVERACTION_PEEK_OVER = 9,
    COVERACTION_PEEK_LEFT = 10,
    COVERACTION_PEEK_RIGHT = 11,
    COVERACTION_HIDE = 12,
    COVERACTION_RAIL_DOWN = 13,
    COVERACTION_RAIL_UP = 14,
    COVERACTION_RAIL_LEFT = 15,
    COVERACTION_RAIL_RIGHT = 16,
    COVERACTION_MAX = 17
};

class alignas(4) idCoverActions {
public:
    idCoverActions() : actionBits(0) {}
    virtual ~idCoverActions() = default;
    virtual void Clear() { actionBits &= 0x07u; }

    void Init(const aas2Cover_t& cover);

    // Bits 3..7 are step-right, lean-right, step-left, lean-left, fire-over.
    std::uint8_t actionBits;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idCoverActions) == 8,
    "Recovered cover-action ABI changed");
#endif
