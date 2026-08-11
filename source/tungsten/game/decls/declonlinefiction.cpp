#include "game/decls/declonlinefiction.h"

idDeclInfoTemplate<idDeclOnlineFiction> idDeclOnlineFiction::resourceList(
    "onlineFiction", "idDeclOnlineFiction", "tdef");

// EA 0x82BC9820
idDeclOnlineFiction::idDeclOnlineFiction()
    : voiceOver(nullptr)
    , voiceOverTalkerName()
    , fxCondition(FX_NONE)
    , hasPlayed(false) {
}

// EA 0x82BC98F0
int idDeclOnlineFiction::PlayVO(idPresentable* const target,
        const unsigned char peerMask) const {
    hasPlayed = true;

    TungstenSoundShaderParms parms;
    parms.Clear();
    parms.soundShaderFlags = 0;
    return Tungsten_PlayVoiceOverSound(voiceOver, parms, target,
        voiceOverTalkerName, peerMask);
}
