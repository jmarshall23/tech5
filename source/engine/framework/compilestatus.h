#pragma once

#include "idlib/sourcecontrol.h"

struct CDialog;
class idCompileProgress;

class idCompileStatus {
public:
    virtual ~idCompileStatus() = default;
    virtual void SetDialog(CDialog*) = 0;
    virtual void UnsetDialog() = 0;
    virtual void Begin(const char*, bool, bool) = 0;
    virtual void End(bool) = 0;
    virtual void SetProgressRange(idCompileProgress*, int) = 0;
    virtual void SetProgress(idCompileProgress*, int) = 0;
    virtual void IncProgress(idCompileProgress*) = 0;
    virtual void Indent() = 0;
    virtual void Unindent() = 0;
    virtual void Print(const char*) = 0;
    virtual void Error(const char*) = 0;
    virtual void Cancel() = 0;
    virtual bool IsCompiling() = 0;
    virtual bool IsCancelled() = 0;
    virtual bool IsHandled() = 0;
    virtual bool HadErrors() = 0;
    virtual void SetStatusText(const char*) = 0;
    virtual void ShowRenderWindow(bool) = 0;
    virtual void MakeCurrentForRender() = 0;
    virtual void AddCompileProgress(idCompileProgress*) = 0;
    virtual void RemoveCompileProgress(idCompileProgress*) = 0;
    virtual int GetProgressRecordCount() = 0;
    virtual void StartConsoleListen() = 0;
    virtual void EndConsoleListen() = 0;
};

class idCompileStatusHandler {
public:
    idCompileStatusHandler() : compileStatus(nullptr) {}
    idCompileStatus* compileStatus;
};
