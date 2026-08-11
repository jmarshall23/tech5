#pragma once

#include "idlib/text/str.h"

class idEntity;

struct _LD_DEMO {
    unsigned int dwID;
    unsigned int dwRunmode;
    unsigned int dwTimeout;
    char szLauncherXEX[128];
    char szLaunchedXEX[128];
};
using LD_DEMO = _LD_DEMO;

class mgFunc_DemoServices {
public:
    virtual ~mgFunc_DemoServices() = default;
    virtual void AppendCommandText(const char* command);
    virtual void ExecuteCommandText(const char* command);
    virtual void SetCVarInteger(const char* name, int value);
    virtual void SetCVarFloat(const char* name, float value);
    virtual void SetCVarBool(const char* name, bool value);
    virtual void SetCVarString(const char* name, const char* value);
    virtual int GetCVarInteger(const char* name) const;
    virtual bool GetCVarBool(const char* name) const;
    virtual void SetGameHz(int hertz);
    virtual void SetCaptureFrames(int value);
    virtual void SetCaptureSounds(int value);
    virtual bool IsCaptureDisabled() const;
    virtual int GetCaptureFrames() const;
};

class mgFunc_DemoBase {
public:
    static void SetServices(mgFunc_DemoServices* services);
    static mgFunc_DemoServices& Services();
};

class mgFunc_StopDemo : public mgFunc_DemoBase {
public:
    void OnActivate(idEntity* activator);
};

class mgFunc_RecordDemo : public mgFunc_DemoBase {
public:
    mgFunc_RecordDemo();
    void OnActivate(idEntity* activator);

    idStr demoName;
};

class mgFunc_CaptureDemo : public mgFunc_DemoBase {
public:
    mgFunc_CaptureDemo();
    void OnActivate(idEntity* activator);

    idStr demoName;
    idStr outputName;
    idStr extraParam;
    int framerate;
};

class mgFunc_CaptureFrames : public mgFunc_DemoBase {
public:
    mgFunc_CaptureFrames();
    void StartCapture(const char* capturePath);
    void StopCapture();
    void Event_Deactivate();
    void OnActivate(idEntity* activator);

    idStr outputName;
    bool preview;
    bool usePNG;
    int framerate;
    int width;
    int height;
    bool oldFullscreen;
    int oldWidth;
    int oldHeight;
};
