#pragma once

#include "idlib/text/str.h"

class idEntity;
class idTarget_Bink;

class idTargetBinkServices {
public:
    virtual ~idTargetBinkServices() = default;
    virtual void FadeSoundWorld(float) {}
    virtual void BeginVideo(const char*) {}
    virtual bool IsVideoLoaded() const { return false; }
    virtual bool IsVideoPlaying() const { return false; }
    virtual void RenderSound() {}
    virtual bool PollExitInput() { return false; }
    virtual void GenerateEvents() {}
    virtual void ClearEvents() {}
    virtual void SleepMilliseconds(int) {}
    virtual void FreeVideo() {}
    virtual void WaitForSoundThread() {}
};

class idTarget_Bink {
public:
    idTarget_Bink();

    static void SetServices(idTargetBinkServices* services);
    static idTargetBinkServices& Services();

    virtual void OnActivate(idEntity* activator);

    idStr videoFileName;
};
