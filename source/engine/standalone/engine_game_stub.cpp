// Minimal game-side ABI boundary for the engine-only link audit.
//
// This file must contain only symbols genuinely owned by the unfinished game.
// Missing engine, renderer, system, or idLib symbols intentionally remain
// unresolved so tech5_engine_linkcheck reports real recovery work.

#include "idlib/csystems/cvarsystem.h"

class idGame;

idGame* game = nullptr;

idCVar g_demoMode(
    "g_demoMode",
    "0",
    CVAR_BOOL,
    "standalone engine link-audit game mode"
);
