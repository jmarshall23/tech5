#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idCmdArgs;
class idTestReport;

class idRegression {
public:
    virtual ~idRegression() = default;
    virtual void MakeTest(const idCmdArgs*) = 0;
    virtual void MakeTestLoadGame(const idCmdArgs*) = 0;
    virtual void StopTest() = 0;
    virtual void PlayTest(const char*, bool) = 0;
    virtual void NextTest() = 0;
    virtual idTestReport* GetTestReport() = 0;
    virtual void SetName(const char*) = 0;
    virtual const char* GetName() = 0;
    virtual void QueueEventString(const char*) = 0;
    virtual bool ProcessQueuedEvents() = 0;
    virtual void SetTestInProgress(bool) = 0;
    virtual bool GetTestInProgress() = 0;
};
