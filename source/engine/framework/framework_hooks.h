#pragma once

class idRenderModelGui;
class idGame;
class idFile;
class idCmdArgs;
class idSWFScriptFunction;
class idUsercmdGenLocal;
class usercmd_t;
struct gameReturn_t;
struct inputSettings_t;
struct idGameSpawnInfo;
struct screenViewDef_t;

// Explicit ownership boundary for engine services that live outside framework.
// The executable installs these callbacks after renderer/input initialization;
// framework code remains usable in tools before those systems exist.
struct idFrameworkHooks {
    using DrawStringFn = void (*)(idRenderModelGui*, float, float,
        const char*, unsigned int, float);
    using DrawRectFn = void (*)(idRenderModelGui*, float, float, float, float,
        unsigned int);
    using MillisecondsFn = int (*)();
    using ClipboardFn = const char* (*)();
    using ResolveScreenViewDefFn = const screenViewDef_t* (*)(const char*);
    using RenderManagerFn = void (*)(const void* renderFrameInfo);
    using ClearGuiFn = void (*)(idRenderModelGui*);
    using CreateGuiFn = idRenderModelGui* (*)();
    using DestroyGuiFn = void (*)(idRenderModelGui*);
    using BuildGuiFrameFn = void (*)(void* renderFrameInfo,
        idRenderModelGui*, bool);
    using BuildGameFrameFn = void (*)(void* renderFrameInfo,
        const gameReturn_t&, idGame&, int);
    using PollInputFn = void (*)(idUsercmdGenLocal&, int);
    using UsercmdFilterFn = void (*)(usercmd_t&, int,
        const inputSettings_t&);
    using BoolFn = void (*)(bool);
    using VoidFn = void (*)();
    using IntFn = int (*)();
    using GameSystemInitFn = void (*)();
    using GameSystemAllocFn = bool (*)(idGame**, const idGameSpawnInfo*,
        idFile*);
    using GameSystemFreeFn = void (*)(idGame**);
    using ExcludeResourceFn = bool (*)(const char*);
    using DiscNumberFn = int (*)();
    using OwnerCommandFn = bool (*)(const char*, const idCmdArgs&);
    using ScriptCallbackFn = void (*)(idSWFScriptFunction*);
    using ExitFn = void (*)(int);
    using BoolQueryFn = bool (*)();

    DrawStringFn drawString;
    DrawRectFn drawRect;
    MillisecondsFn milliseconds;
    ClipboardFn clipboard;
    ResolveScreenViewDefFn resolveScreenViewDef;
    RenderManagerFn renderFrame;
    RenderManagerFn beginAutomaticBackgroundSwaps;
    ClearGuiFn clearGui;
    CreateGuiFn createGui;
    DestroyGuiFn destroyGui;
    BuildGuiFrameFn buildGuiFrame;
    BuildGameFrameFn buildGameFrame;
    VoidFn updateConsole;
    PollInputFn pollMouse;
    PollInputFn pollKeyboard;
    PollInputFn pollJoystick;
    UsercmdFilterFn aimAssist;
    UsercmdFilterFn weaponKick;
    IntFn playLoadSound;
    BoolFn showSaveIndicator;
    BoolFn refreshOnPrint;
    GameSystemInitFn initGameSystem;
    GameSystemInitFn shutdownGameSystem;
    GameSystemAllocFn allocGame;
    GameSystemFreeFn freeGame;
    GameSystemFreeFn minimalGameCleanup;
    ExcludeResourceFn excludeImage;
    ExcludeResourceFn excludeFont;
    DiscNumberFn currentDiscNumber;
    OwnerCommandFn ownerCommand;
    ScriptCallbackFn retainScriptCallback;
    ScriptCallbackFn releaseScriptCallback;
    ScriptCallbackFn invokeScriptCallback;

    // Recovered common.cpp synchronization/lifecycle boundaries. These are
    // installed by the PC renderer, sound, session and platform owners.
    VoidFn endVirtualTexturePreloading;
    VoidFn syncRenderThread;
    VoidFn finishVirtualTextureFeedback;
    VoidFn waitCollisionQueries;
    VoidFn waitParallelJobs;
    VoidFn waitSaveGames;
    VoidFn waitSoundThread;
    VoidFn stopAllSounds;
    VoidFn resetNetworkingState;
    VoidFn unbindAllVideos;
    VoidFn resetVirtualTextures;
    VoidFn freeDynamicMapResources;
    VoidFn shutdownSoundRelatedSystems;
    VoidFn initializeSoundRelatedSystems;
    BoolQueryFn canResetMapHeap;
    ExitFn systemQuit;
};

extern idFrameworkHooks frameworkHooks;
