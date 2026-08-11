#include "game/entities/demo.h"

#include <cstdio>

namespace {
mgFunc_DemoServices defaultDemoServices;
mgFunc_DemoServices* demoServices = &defaultDemoServices;
}

void mgFunc_DemoServices::AppendCommandText(const char*) {}
void mgFunc_DemoServices::ExecuteCommandText(const char*) {}
void mgFunc_DemoServices::SetCVarInteger(const char*, int) {}
void mgFunc_DemoServices::SetCVarFloat(const char*, float) {}
void mgFunc_DemoServices::SetCVarBool(const char*, bool) {}
void mgFunc_DemoServices::SetCVarString(const char*, const char*) {}
int mgFunc_DemoServices::GetCVarInteger(const char*) const { return 0; }
bool mgFunc_DemoServices::GetCVarBool(const char*) const { return false; }
void mgFunc_DemoServices::SetGameHz(int) {}
void mgFunc_DemoServices::SetCaptureFrames(int) {}
void mgFunc_DemoServices::SetCaptureSounds(int) {}
bool mgFunc_DemoServices::IsCaptureDisabled() const { return false; }
int mgFunc_DemoServices::GetCaptureFrames() const { return 0; }

void mgFunc_DemoBase::SetServices(mgFunc_DemoServices* const services) {
    demoServices = services == nullptr ? &defaultDemoServices : services;
}

mgFunc_DemoServices& mgFunc_DemoBase::Services() {
    return *demoServices;
}

// Retail: 0x82C1F9D8 ?OnActivate@mgFunc_StopDemo@@UAAXPAVidEntity@@@Z
void mgFunc_StopDemo::OnActivate(idEntity*) {
    Services().AppendCommandText("demostop\n");
    Services().AppendCommandText("disconnect\n");
}

// Retail: 0x82C1FA38 ?StartCapture@mgFunc_CaptureFrames@@AAAXPBD@Z
void mgFunc_CaptureFrames::StartCapture(const char* const capturePath) {
    Services().SetCVarInteger("g_skipViewEffects", 1);
    Services().SetCVarInteger("com_fixedTic", 1);
    Services().SetGameHz(framerate);
    Services().SetCVarInteger("r_skipModelCPUCulling", 1);
    Services().SetCVarInteger("r_skipModelGPUCulling", 1);
    Services().SetCVarBool("r_postProcessHQ", true);
    Services().SetCVarInteger("com_capturePrimes", 2);
    Services().SetCVarInteger("ai_debugLevel", 0);
    Services().SetCVarBool("con_noPrint", true);
    oldWidth = Services().GetCVarInteger("r_windowWidth");
    oldHeight = Services().GetCVarInteger("r_windowHeight");
    oldFullscreen = Services().GetCVarBool("r_fullscreen");
    Services().SetCVarInteger("r_windowWidth",
        preview ? width / 2 : width);
    Services().SetCVarInteger("r_windowHeight",
        preview ? height / 2 : height);
    Services().SetCVarBool("r_fullscreen", false);
    Services().ExecuteCommandText("vid_restart");
    Services().SetCaptureFrames(2);
    Services().SetCaptureSounds(0);
    Services().SetCVarInteger("com_captureTGA",
        preview ? 0 : (usePNG ? 2 : 1));
    Services().SetCVarString("com_capturePath",
        capturePath == nullptr ? "" : capturePath);
}

// Retail: 0x82C1FD60 ?StopCapture@mgFunc_CaptureFrames@@AAAXXZ
void mgFunc_CaptureFrames::StopCapture() {
    Services().SetCVarInteger("g_skipViewEffects", 0);
    Services().SetCVarInteger("com_fixedTic", 0);
    Services().SetCVarBool("con_noPrint", false);
    Services().SetCaptureFrames(0);
    Services().SetCVarInteger("r_skipModelCPUCulling", 0);
    Services().SetCVarInteger("r_skipModelGPUCulling", 0);
    Services().SetCVarInteger("r_windowWidth", oldWidth);
    Services().SetCVarInteger("r_windowHeight", oldHeight);
    Services().SetCVarBool("r_fullscreen", oldFullscreen);
    Services().ExecuteCommandText("vid_restart");
}

// Retail: 0x82C1FEF0 ??0mgFunc_RecordDemo@@QAA@XZ
mgFunc_RecordDemo::mgFunc_RecordDemo()
    : demoName("demo") {
}

// Retail: 0x82C20038 ?OnActivate@mgFunc_RecordDemo@@UAAXPAVidEntity@@@Z
void mgFunc_RecordDemo::OnActivate(idEntity*) {
    char command[512];
    std::snprintf(command, sizeof(command),
        "demorecord %s\n", demoName.c_str());
    Services().AppendCommandText(command);
}

// Retail: 0x82C20090 ??0mgFunc_CaptureDemo@@QAA@XZ
mgFunc_CaptureDemo::mgFunc_CaptureDemo()
    : demoName("demo"), outputName("capture"), extraParam(""),
      framerate(30) {
}

// Retail: 0x82C202E0 ?OnActivate@mgFunc_CaptureDemo@@UAAXPAVidEntity@@@Z
void mgFunc_CaptureDemo::OnActivate(idEntity*) {
    Services().SetCVarInteger("g_skipViewEffects", 1);
    Services().SetCVarFloat("com_demoPlaybackRate",
        framerate != 0 ? 960.0f / static_cast<float>(framerate) : 0.0f);
    char command[1024];
    std::snprintf(command, sizeof(command),
        "demoCaptureFrames demos/%s %s %s\n",
        demoName.c_str(), outputName.c_str(), extraParam.c_str());
    Services().AppendCommandText(command);
}

// Retail: 0x82C203C0 ??0mgFunc_CaptureFrames@@QAA@XZ
mgFunc_CaptureFrames::mgFunc_CaptureFrames()
    : outputName("capture"), preview(false), usePNG(false),
      framerate(30), width(1280), height(720), oldFullscreen(false),
      oldWidth(-1), oldHeight(-1) {
}

// Retail: 0x82C204A8 ?Event_Deactivate@mgFunc_CaptureFrames@@QAA?AVeventVoid@@XZ
void mgFunc_CaptureFrames::Event_Deactivate() {
    if (oldWidth != -1) {
        StopCapture();
        oldWidth = -1;
    }
}

// Retail: 0x82C20570 ?OnActivate@mgFunc_CaptureFrames@@UAAXPAVidEntity@@@Z
void mgFunc_CaptureFrames::OnActivate(idEntity*) {
    if (Services().IsCaptureDisabled()
            || Services().GetCaptureFrames() != 0) {
        return;
    }
    idStr capturePath(outputName);
    capturePath.StripFileExtension();
    capturePath.Append("/frames/");
    StartCapture(capturePath.c_str());
}
