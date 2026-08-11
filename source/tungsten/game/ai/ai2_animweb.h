#pragma once

struct idAI2AnimWebCall {
    const char* operation;
    const void* inputs[8];
    void* outputs[8];
    const char* strings[4];
    int integers[8];
    float scalars[2];
    bool booleans[2];
    int result;
    bool boolResult;
    const void* pointerResult;

    explicit idAI2AnimWebCall(const char* operationValue)
        : operation(operationValue), inputs{}, outputs{}, strings{},
          integers{}, scalars{}, booleans{}, result(0),
          boolResult(false), pointerResult(nullptr) {
    }
};
