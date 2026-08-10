// Minimal game-side ABI boundary for the engine-only link audit.
//
// This file must contain only symbols genuinely owned by the unfinished game.
// Missing engine, renderer, system, or idLib symbols intentionally remain
// unresolved so tech5_engine_linkcheck reports real recovery work.

#include "idlib/csystems/cvarsystem.h"
#include "idlib/csystems/cmdsystem.h"
#include "sys/win32/win_local.h"

class idGame;

idGame* game = nullptr;
idCmdSystem* cmdSystem = nullptr;

idCVar com_productionMode("com_productionMode", "0", CVAR_INTEGER,
    "standalone production mode");
idCVar fs_savepath("fs_savepath", "", CVAR_INIT,
    "standalone save path");
idCVar r_debugContext("r_debugContext", "0", CVAR_BOOL,
    "request an OpenGL debug context");
idCVar r_glDriver("r_glDriver", "", CVAR_INIT,
    "optional OpenGL driver override");
idCVar r_logFile("r_logFile", "0", CVAR_INTEGER,
    "OpenGL call logging");
idCVar r_swapInterval("r_swapInterval", "1", CVAR_INTEGER,
    "swap interval");
idCVar r_windowX("r_windowX", "0", CVAR_ARCHIVE | CVAR_INTEGER,
    "window x position");
idCVar r_windowY("r_windowY", "0", CVAR_ARCHIVE | CVAR_INTEGER,
    "window y position");
idCVar r_windowWidth("r_windowWidth", "1280", CVAR_ARCHIVE | CVAR_INTEGER,
    "window width");
idCVar r_windowHeight("r_windowHeight", "720", CVAR_ARCHIVE | CVAR_INTEGER,
    "window height");

glconfig_t glConfig{};

idCVar g_demoMode(
    "g_demoMode",
    "0",
    CVAR_BOOL,
    "standalone engine link-audit game mode"
);
