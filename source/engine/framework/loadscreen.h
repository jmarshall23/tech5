#pragma once

#include "idlib/containers/list.h"
#include "idlib/sys/sys_threading.h"
#include "idlib/text/str.h"

class idSWF;
class idRenderModelGui;
struct gameReturn_t;

class idLoadScreenInfo {
public:
    idStr varName;
    idStr value;
};

// Xbox metadata reported align(2), but the PC base has pointer alignment 4.
class idLoadScreenThread : public idSysThread {
public:
    idLoadScreenThread();
    ~idLoadScreenThread() override;
    int Run() override;

    bool initialized;
    volatile bool stopRunning;
    volatile bool isRunning;
};

class idLoadScreenInfo2 {
public:
    idStr varName;
    idStr value;
};

class idLoadScreen {
public:
    idLoadScreen();
    ~idLoadScreen();
    void Init();
    void Shutdown();
    void LevelLoadCompleted(const gameReturn_t& gameReturn);
    void LaunchLoadScreen(const char* mapName,
        const idList<idLoadScreenInfo2, 5>& info);

    idLoadScreenThread* thread;
    idSWF* loadingGui;
    idRenderModelGui* guiModel;
};

extern idLoadScreen loadScreen;
