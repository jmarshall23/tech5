#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../engine/decls/declfxtypes.h"
#include "../../../shared/idlib/langdict.h"

class idDeclVoiceOver;
class idPresentable;

class alignas(4) idDeclOnlineFiction : public idDeclTypeInfo {
public:
    idDeclOnlineFiction();
    ~idDeclOnlineFiction() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclOnlineFiction@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BC9878, RVA: 0x00BC9878
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    int PlayVO(idPresentable* target, unsigned char peerMask) const;

    const idDeclVoiceOver* voiceOver;
    idStrId voiceOverTalkerName;
    fxCondition_t fxCondition;
    mutable bool hasPlayed;

    static idDeclInfoTemplate<idDeclOnlineFiction> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlineFiction) == 80,
    "Recovered online-fiction declaration ABI changed");
#endif
