#pragma once

#include "idlib/runtimeexpression.h"

class idDeclMD6;

class idUserChannelExpression {
public:
    class VarId {
    public:
        VarId() : index(-1) {}
        int index;
    };

    class VarContext {
    public:
        bool LookUpVar(const char* name, VarId& result) const;
        float GetVar(const VarId& variable) const;

        const idDeclMD6* decl;
        const float* channels;
        int numChannels;
    };

    using LookupCallback = bool (*)(const idDeclMD6* declaration,
        const char* name, int& channelIndex);

    static void SetLookupCallback(LookupCallback callback);

    bool Parse(const char* expression, const idDeclMD6* declaration);
    float Eval(const float* userChannels, int channelCount) const;
    void Clear() { expr.Clear(); }

    idRuntimeExpression<VarId, VarContext> expr;

private:
    static LookupCallback lookupCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idUserChannelExpression) == 20,
    "Recovered user-channel expression ABI changed");
#endif
