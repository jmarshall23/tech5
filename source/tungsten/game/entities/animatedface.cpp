#include "game/entities/animatedface.h"

namespace {
idAnimatedFaceServices defaultAnimatedFaceServices;
idAnimatedFaceServices* animatedFaceServices = &defaultAnimatedFaceServices;
}

void idAnimWebTesting::SetServices(idAnimatedFaceServices* const services) {
    animatedFaceServices = services == nullptr
        ? &defaultAnimatedFaceServices : services;
}

idAnimatedFaceServices& idAnimWebTesting::Services() {
    return *animatedFaceServices;
}

idAnimWebTesting::idAnimWebTesting()
    : blendBack(0.0f), blendRight(0.0f), blendAngle(0.0f) {
}

// Retail: 0x82BFB868 ?InternalInitWeb@idAnimWebTesting@@MAAXXZ
void idAnimWebTesting::InternalInitWeb() {
    Services().AddBlendVariable(*this, "blendBack", blendBack);
    Services().AddBlendVariable(*this, "blendRight", blendRight);
    Services().AddBlendVariable(*this, "blendAngle", blendAngle);
}

// Retail: 0x82BFB8D8 ?Think@idTestRollBones@@UAAXXZ
void idTestRollBones::Think() {
    idAnimatedEntity::Think();
}

// Retail: 0x82BFB8E0 ?InternalUpdateScalars@idAnimWebTesting@@MAAXH@Z
void idAnimWebTesting::InternalUpdateScalars(const int) {
    Services().ReadBlendVariable("blendBack", blendBack);
    Services().ReadBlendVariable("blendRight", blendRight);
    Services().ReadBlendVariable("blendAngle", blendAngle);
}

// Retail: 0x82BFB968 ??0idTestAnimWeb@@QAA@XZ
idTestAnimWeb::idTestAnimWeb()
    : idAnimatedEntity()
    , animWebDecl(nullptr)
    , animWeb()
    , lastActionTime(0)
    , interact(false) {
}

// Retail: 0x82BFBAD8 ?Think@idTestAnimWeb@@UAAXXZ
void idTestAnimWeb::Think() {
    const int now = idAnimWebTesting::Services().GetGameMilliseconds();
    if (animWebDecl != nullptr && now - lastActionTime > 4000) {
        lastActionTime = now;
        idAnimWebTesting::Services().ChangeAnimWebState(
            *this, interact ? "walk" : "idle");
        interact = !interact;
    }
    idAnimatedEntity::Think();
}

// Retail: 0x82BFBBF0 ??0idTestRollBones@@QAA@XZ
idTestRollBones::idTestRollBones()
    : idAnimatedEntity()
    , rollBonesDecl(nullptr)
    , nameBaseTrack()
    , useDualQuatSkinning(false)
    , baseTrackAlias() {
}

// Retail: 0x82BFBE50 ?Spawn@idTestRollBones@@QAAXXZ
void idTestRollBones::Spawn() {
    idAnimWebTesting::Services().SpawnRollBones(*this, rollBonesDecl,
        nameBaseTrack.c_str(), useDualQuatSkinning);
    thinkFlags |= TH_ANIMATE;
}

// Retail: 0x82BFC0A0 ?InitAnimation@idTestAnimWeb@@QAAXXZ
void idTestAnimWeb::InitAnimation() {
    idAnimWebTesting::Services().InitializeAnimWeb(*this, animWebDecl);
    thinkFlags |= TH_ANIMATE;
}

// Retail: 0x82BFC1B0 ?Spawn@idTestAnimWeb@@QAAXXZ
void idTestAnimWeb::Spawn() {
    InitAnimation();
}
