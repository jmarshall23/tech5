#pragma once

#include "../gamesys/eventarg.h"
#include "../gamesys/eventdef.h"

struct idAI2EventCall {
    const char* operation;
    const void* inputs[8];
    void* outputs[4];
    const char* strings[4];
    int integers[8];
    float scalars[4];
    bool booleans[4];
    int intResult;
    float floatResult;
    bool boolResult;
    idVec3 vectorResult;
    const char* stringResult;
    const idDecl* declResult;
    idEntity* entityResult;

    explicit idAI2EventCall(const char* operationValue)
        : operation(operationValue), inputs{}, outputs{}, strings{},
          integers{}, scalars{}, booleans{}, intResult(0),
          floatResult(0.0f), boolResult(false),
          vectorResult(0.0f, 0.0f, 0.0f), stringResult(""),
          declResult(nullptr), entityResult(nullptr) {
    }
};
