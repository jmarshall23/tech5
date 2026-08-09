#include "models/skeletalanimation/userchannelexpression.h"

idUserChannelExpression::LookupCallback
    idUserChannelExpression::lookupCallback = nullptr;

bool idUserChannelExpression::VarContext::LookUpVar(
    const char* name, VarId& result) const {
    int index = -1;
    if (lookupCallback == nullptr ||
        !lookupCallback(decl, name, index) || index < 0) {
        return false;
    }
    result.index = index;
    return true;
}

float idUserChannelExpression::VarContext::GetVar(
    const VarId& variable) const {
    return channels != nullptr && variable.index >= 0 &&
        variable.index < numChannels
        ? channels[variable.index]
        : 0.0f;
}

void idUserChannelExpression::SetLookupCallback(LookupCallback callback) {
    lookupCallback = callback;
}

bool idUserChannelExpression::Parse(const char* expression,
    const idDeclMD6* declaration) {
    VarContext context = {};
    context.decl = declaration;
    return expr.Parse(expression, context);
}

float idUserChannelExpression::Eval(const float* userChannels,
    int channelCount) const {
    VarContext context = {};
    context.channels = userChannels;
    context.numChannels = channelCount;
    return expr.Eval(context);
}
