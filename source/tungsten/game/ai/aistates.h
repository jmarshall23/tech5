#pragma once

// The retail type information exposes unnamed, data-driven stand and sit
// states.  Game code only assigns or compares the default and terminal
// values; the intermediate values are authored by number in declarations.
enum standState_t : int {
    STANDSTATE_DEFAULT = 0,
    STANDSTATE_MAX = 60
};

enum sitState_t : int {
    SITSTATE_DEFAULT = 0,
    SITSTATE_MAX = 50
};
