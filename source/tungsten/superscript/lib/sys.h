#pragma once

#include "string.h"

struct ssThreadInfo_t {
    int spawnId;
    int objectId;
    const char* name;
};

bool Tungsten_GetSuperScriptThreadInfo(int threadId, ssThreadInfo_t& info);
const char* Tungsten_GetSuperScriptObjectFullName(int spawnId, int objectId);
void Tungsten_SuperScriptPrint(const char* text);
void Tungsten_SuperScriptWaitFrame();
void Tungsten_TerminateSuperScriptThread(int threadId);

void Warning(const ssString& message);
void Error(const ssString& message);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(ssThreadInfo_t) == 12,
    "Recovered SuperScript thread-info ABI changed");
#endif
