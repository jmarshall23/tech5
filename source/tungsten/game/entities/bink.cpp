#include "game/entities/bink.h"

namespace {
idTargetBinkServices defaultTargetBinkServices;
idTargetBinkServices* targetBinkServices = &defaultTargetBinkServices;
}

void idTarget_Bink::SetServices(idTargetBinkServices* const services) {
    targetBinkServices = services == nullptr
        ? &defaultTargetBinkServices : services;
}

idTargetBinkServices& idTarget_Bink::Services() {
    return *targetBinkServices;
}

// Retail: 0x82C0BC60 ??0idTarget_Bink@@QAA@XZ
idTarget_Bink::idTarget_Bink()
    : videoFileName("") {
}

// Retail: 0x82C0BCC0 ?OnActivate@idTarget_Bink@@UAAXPAVidEntity@@@Z
void idTarget_Bink::OnActivate(idEntity*) {
    Services().FadeSoundWorld(-60.0f);
    Services().BeginVideo(videoFileName.c_str());
    if (Services().IsVideoLoaded() && Services().IsVideoPlaying()) {
        while (Services().IsVideoPlaying()) {
            Services().RenderSound();
            Services().GenerateEvents();
            if (Services().PollExitInput()) {
                Services().ClearEvents();
                break;
            }
            Services().ClearEvents();
            Services().SleepMilliseconds(50);
        }
    }
    Services().FreeVideo();
    Services().WaitForSoundThread();
    Services().FadeSoundWorld(0.0f);
}
