#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../shared/idlib/langdict.h"
#include "../sound/soundshaderparms_recovery.h"

class idMaterial;
class idSoundShader;
class idDeclVoiceOver;

class idDeclOnlineScoringCallout : public idDeclTypeInfo {
public:
    idDeclOnlineScoringCallout();
    ~idDeclOnlineScoringCallout() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclOnlineScoringCallout@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BC9468, RVA: 0x00BC9468
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    const idSoundShader* sound;
    idStrId text;
    const idMaterial* icon;
    int priority;

    static idDeclInfoTemplate<idDeclOnlineScoringCallout> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlineScoringCallout) == 80,
    "Recovered online scoring-callout ABI changed");
#endif

class idDeclOnlineVOCallout : public idDeclTypeInfo {
public:
    idDeclOnlineVOCallout();
    ~idDeclOnlineVOCallout() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    TungstenSoundShaderParms parms;
    const idDeclVoiceOver* takenLead;
    const idDeclVoiceOver* tiedLead;
    const idDeclVoiceOver* lostLead;
    const idDeclVoiceOver* impressive;
    const idDeclVoiceOver* doubleKill;
    const idDeclVoiceOver* tripleKill;
    const idDeclVoiceOver* quadKill;
    const idDeclVoiceOver* slaughter;
    const idDeclVoiceOver* revenge;
    const idDeclVoiceOver* airMail;
    const idDeclVoiceOver* pull;
    const idDeclVoiceOver* afterLife;
    const idDeclVoiceOver* maxChain;
    const idDeclVoiceOver* chainBreaker;
    const idDeclVoiceOver* denial;
    const idDeclVoiceOver* closeCall;
    const idDeclVoiceOver* airRally;

    static idDeclInfoTemplate<idDeclOnlineVOCallout> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclOnlineVOCallout) == 280,
    "Recovered online voice-over callout ABI changed");
#endif
