#include "ai2.h"

namespace {

idAI2AccelSimCallback g_accelSimCallback = nullptr;

eventVoid DispatchAnimEvent(idAI2& ai,
        const idAI2AnimEventCall& call) {
    if (ai.core.services != nullptr) {
        ai.core.services->DispatchAIAnimEvent(ai, call);
    }
    return eventVoid();
}

#define AI2_ANIM_EVENT0(methodName) \
    eventVoid idAI2::methodName(const idMD6Anim* const animation) { \
        const idAI2AnimEventCall call(#methodName, animation); \
        return DispatchAnimEvent(*this, call); \
    }

#define AI2_ANIM_EVENT_STRING(methodName) \
    eventVoid idAI2::methodName(const idMD6Anim* const animation, \
            const char* const value) { \
        idAI2AnimEventCall call(#methodName, animation); \
        call.strings[0] = value; \
        return DispatchAnimEvent(*this, call); \
    }

#define AI2_ANIM_EVENT_JOINT(methodName) \
    eventVoid idAI2::methodName(const idMD6Anim* const animation, \
            const idJointName& joint) { \
        idAI2AnimEventCall call(#methodName, animation); \
        call.objects[0] = &joint; \
        return DispatchAnimEvent(*this, call); \
    }

} // namespace

// Retail symbol: ?AnimEvent_DeathAnimImpulse@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4deathImpulse_t@@@Z
// EA: 0x82A2DEE0, RVA: 0x00A2DEE0
eventVoid idAI2::AnimEvent_DeathAnimImpulse(
        const idMD6Anim* const animation,
        const deathImpulse_t impulse) {
    idAI2AnimEventCall call("AnimEvent_DeathAnimImpulse", animation);
    call.integers[0] = static_cast<int>(impulse);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_Kill@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclDamage@@@Z
// EA: 0x82A2DF28, RVA: 0x00A2DF28
eventVoid idAI2::AnimEvent_Kill(const idMD6Anim* const animation,
        const idDeclDamage* const damageType) {
    idAI2AnimEventCall call("AnimEvent_Kill", animation);
    call.objects[0] = damageType;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?Event_DisableAutoFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2DFA0, RVA: 0x00A2DFA0
eventVoid idAI2::Event_DisableAutoFocus() {
    core.enableAutoFocus = false;
    const idAI2AnimEventCall call("Event_DisableAutoFocus", nullptr);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableHeadTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2DFD8, RVA: 0x00A2DFD8
eventVoid idAI2::AnimEvent_EnableHeadTracking(
        const idMD6Anim* const animation) {
    core.enableHeadTracking = true;
    const idAI2AnimEventCall call(
        "AnimEvent_EnableHeadTracking", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableHeadTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E010, RVA: 0x00A2E010
eventVoid idAI2::AnimEvent_DisableHeadTracking(
        const idMD6Anim* const animation) {
    core.enableHeadTracking = false;
    const idAI2AnimEventCall call(
        "AnimEvent_DisableHeadTracking", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetLookFocusHeadTrackingGroup@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A2E048, RVA: 0x00A2E048
AI2_ANIM_EVENT_STRING(AnimEvent_SetLookFocusHeadTrackingGroup)

// Retail symbol: ?AnimEvent_EnableEyeTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E098, RVA: 0x00A2E098
AI2_ANIM_EVENT0(AnimEvent_EnableEyeTracking)

// Retail symbol: ?AnimEvent_DisableEyeTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E0D8, RVA: 0x00A2E0D8
AI2_ANIM_EVENT0(AnimEvent_DisableEyeTracking)

// Retail symbol: ?AnimEvent_SetMovePushStatus@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiMovePushStatus_t@@H@Z
// EA: 0x82A2E118, RVA: 0x00A2E118
eventVoid idAI2::AnimEvent_SetMovePushStatus(
        const idMD6Anim* const animation,
        const aiMovePushStatus_t status, const int frameCount) {
    SetMovePushStatus(status, frameCount);
    idAI2AnimEventCall call("AnimEvent_SetMovePushStatus", animation);
    call.integers[0] = static_cast<int>(status);
    call.integers[1] = frameCount;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableWorldCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E158, RVA: 0x00A2E158
eventVoid idAI2::AnimEvent_EnableWorldCollision(
        const idMD6Anim* const animation) {
    SetWorldCollision(true);
    const idAI2AnimEventCall call(
        "AnimEvent_EnableWorldCollision", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableWorldCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E190, RVA: 0x00A2E190
eventVoid idAI2::AnimEvent_DisableWorldCollision(
        const idMD6Anim* const animation) {
    SetWorldCollision(false);
    const idAI2AnimEventCall call(
        "AnimEvent_DisableWorldCollision", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableSolidCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E1C8, RVA: 0x00A2E1C8
eventVoid idAI2::AnimEvent_EnableSolidCollision(
        const idMD6Anim* const animation) {
    SetSolid(true);
    const idAI2AnimEventCall call(
        "AnimEvent_EnableSolidCollision", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableSolidCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA: 0x82A2E218, RVA: 0x00A2E218
eventVoid idAI2::AnimEvent_DisableSolidCollision(
        const idMD6Anim* const animation, const int frameCount) {
    SetSolid(false);
    idAI2AnimEventCall call("AnimEvent_DisableSolidCollision", animation);
    call.integers[0] = frameCount;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableDamage@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E258, RVA: 0x00A2E258
AI2_ANIM_EVENT0(AnimEvent_EnableDamage)

// Retail symbol: ?AnimEvent_DisableDamage@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E268, RVA: 0x00A2E268
AI2_ANIM_EVENT0(AnimEvent_DisableDamage)

// Retail symbol: ?AnimEvent_ClearReferenceJointOverride@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiFoci_t@@@Z
// EA: 0x82A2E280, RVA: 0x00A2E280
eventVoid idAI2::AnimEvent_ClearReferenceJointOverride(
        const idMD6Anim* const animation, const aiFoci_t focus) {
    idAI2AnimEventCall call(
        "AnimEvent_ClearReferenceJointOverride", animation);
    call.integers[0] = static_cast<int>(focus);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableExtendedClipModel@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E2C0, RVA: 0x00A2E2C0
eventVoid idAI2::AnimEvent_DisableExtendedClipModel(
        const idMD6Anim* const animation) {
    DeactivateExtendedClipModel();
    const idAI2AnimEventCall call(
        "AnimEvent_DisableExtendedClipModel", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableExtendedClipModel@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiExtendedClipModelStatus_t@@H@Z
// EA: 0x82A2E2F8, RVA: 0x00A2E2F8
eventVoid idAI2::AnimEvent_EnableExtendedClipModel(
        const idMD6Anim* const animation,
        const aiExtendedClipModelStatus_t status,
        const int frameCount) {
    idAI2AnimEventCall call(
        "AnimEvent_EnableExtendedClipModel", animation);
    call.integers[0] = static_cast<int>(status);
    call.integers[1] = frameCount;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EnableIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E338, RVA: 0x00A2E338
AI2_ANIM_EVENT0(AnimEvent_EnableIK)

// Retail symbol: ?AnimEvent_DisableIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E3C0, RVA: 0x00A2E3C0
AI2_ANIM_EVENT0(AnimEvent_DisableIK)

// Retail symbol: ?AnimEvent_EnableLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA: 0x82A2E438, RVA: 0x00A2E438
eventVoid idAI2::AnimEvent_EnableLegIK(
        const idMD6Anim* const animation, const int legIndex) {
    idAI2AnimEventCall call("AnimEvent_EnableLegIK", animation);
    call.integers[0] = legIndex;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA: 0x82A2E478, RVA: 0x00A2E478
eventVoid idAI2::AnimEvent_DisableLegIK(
        const idMD6Anim* const animation, const int legIndex) {
    idAI2AnimEventCall call("AnimEvent_DisableLegIK", animation);
    call.integers[0] = legIndex;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableTwoLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E4B8, RVA: 0x00A2E4B8
AI2_ANIM_EVENT0(AnimEvent_DisableTwoLegIK)

// Retail symbol: ?AnimEvent_EnableTwoLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E508, RVA: 0x00A2E508
AI2_ANIM_EVENT0(AnimEvent_EnableTwoLegIK)

// Retail symbol: ?AnimEvent_DisableFourLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E558, RVA: 0x00A2E558
AI2_ANIM_EVENT0(AnimEvent_DisableFourLegIK)

// Retail symbol: ?AnimEvent_EnableFourLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E5C0, RVA: 0x00A2E5C0
AI2_ANIM_EVENT0(AnimEvent_EnableFourLegIK)

// Retail symbol: ?AnimEvent_StartJetPackFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E628, RVA: 0x00A2E628
AI2_ANIM_EVENT0(AnimEvent_StartJetPackFX)

// Retail symbol: ?AnimEvent_StopJetPackFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E6E8, RVA: 0x00A2E6E8
AI2_ANIM_EVENT0(AnimEvent_StopJetPackFX)

// Retail symbol: ?AnimEvent_DropJetPack@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E740, RVA: 0x00A2E740
AI2_ANIM_EVENT0(AnimEvent_DropJetPack)

// Retail symbol: ?AnimEvent_EnableBlinking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E7A0, RVA: 0x00A2E7A0
AI2_ANIM_EVENT0(AnimEvent_EnableBlinking)

// Retail symbol: ?AnimEvent_DisableBlinking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E7E0, RVA: 0x00A2E7E0
AI2_ANIM_EVENT0(AnimEvent_DisableBlinking)

// Retail symbol: ?AnimEvent_EnableLidDeformation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E820, RVA: 0x00A2E820
AI2_ANIM_EVENT0(AnimEvent_EnableLidDeformation)

// Retail symbol: ?AnimEvent_DisableLidDeformation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E860, RVA: 0x00A2E860
AI2_ANIM_EVENT0(AnimEvent_DisableLidDeformation)

// Retail symbol: ?AnimEvent_SetLookFocusOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA: 0x82A2E8A0, RVA: 0x00A2E8A0
eventVoid idAI2::AnimEvent_SetLookFocusOffset(
        const idMD6Anim* const animation, const idVec3& offset) {
    idAI2AnimEventCall call("AnimEvent_SetLookFocusOffset", animation);
    call.vectors[0] = &offset;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetAimFocusOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA: 0x82A2E8C0, RVA: 0x00A2E8C0
eventVoid idAI2::AnimEvent_SetAimFocusOffset(
        const idMD6Anim* const animation, const idVec3& offset) {
    idAI2AnimEventCall call("AnimEvent_SetAimFocusOffset", animation);
    call.vectors[0] = &offset;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetLookFocusRotationOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA: 0x82A2E8E0, RVA: 0x00A2E8E0
eventVoid idAI2::AnimEvent_SetLookFocusRotationOffset(
        const idMD6Anim* const animation, const float pitch,
        const float yaw, const float roll) {
    idAI2AnimEventCall call(
        "AnimEvent_SetLookFocusRotationOffset", animation);
    call.scalars[0] = pitch;
    call.scalars[1] = yaw;
    call.scalars[2] = roll;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetAimFocusRotationOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA: 0x82A2E8F0, RVA: 0x00A2E8F0
eventVoid idAI2::AnimEvent_SetAimFocusRotationOffset(
        const idMD6Anim* const animation, const float pitch,
        const float yaw, const float roll) {
    idAI2AnimEventCall call(
        "AnimEvent_SetAimFocusRotationOffset", animation);
    call.scalars[0] = pitch;
    call.scalars[1] = yaw;
    call.scalars[2] = roll;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_LockTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA: 0x82A2E900, RVA: 0x00A2E900
eventVoid idAI2::AnimEvent_LockTracking(
        const idMD6Anim* const animation, const int lock) {
    idAI2AnimEventCall call("AnimEvent_LockTracking", animation);
    call.integers[0] = lock;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DisableStaggeringPain@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E940, RVA: 0x00A2E940
AI2_ANIM_EVENT0(AnimEvent_DisableStaggeringPain)

// Retail symbol: ?AnimEvent_DisableDeathAnimations@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E950, RVA: 0x00A2E950
AI2_ANIM_EVENT0(AnimEvent_DisableDeathAnimations)

// Retail symbol: ?AnimEvent_EnableDeathAnimations@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E960, RVA: 0x00A2E960
AI2_ANIM_EVENT0(AnimEvent_EnableDeathAnimations)

// Retail symbol: ?AnimEvent_EnableCanRagdoll@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E970, RVA: 0x00A2E970
AI2_ANIM_EVENT0(AnimEvent_EnableCanRagdoll)

// Retail symbol: ?AnimEvent_DisableCanRagdoll@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2E988, RVA: 0x00A2E988
AI2_ANIM_EVENT0(AnimEvent_DisableCanRagdoll)

// Retail symbol: ?AnimEvent_StartWeaponFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA: 0x82A2E998, RVA: 0x00A2E998
eventVoid idAI2::AnimEvent_StartWeaponFX(
        const idMD6Anim* const animation,
        const fxCondition_t condition) {
    idAI2AnimEventCall call("AnimEvent_StartWeaponFX", animation);
    call.integers[0] = static_cast<int>(condition);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_StopWeaponFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA: 0x82A2EA58, RVA: 0x00A2EA58
eventVoid idAI2::AnimEvent_StopWeaponFX(
        const idMD6Anim* const animation,
        const fxCondition_t condition) {
    idAI2AnimEventCall call("AnimEvent_StopWeaponFX", animation);
    call.integers[0] = static_cast<int>(condition);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_DeltaScaleToTarget@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMABVidJointName@@M@Z
// EA: 0x82A2EAE8, RVA: 0x00A2EAE8
eventVoid idAI2::AnimEvent_DeltaScaleToTarget(
        const idMD6Anim* const animation, const float minimumScale,
        const float maximumScale, const idJointName& joint,
        const float distance) {
    idAI2AnimEventCall call("AnimEvent_DeltaScaleToTarget", animation);
    call.objects[0] = &joint;
    call.scalars[0] = minimumScale;
    call.scalars[1] = maximumScale;
    call.scalars[2] = distance;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetDeltaScale@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA: 0x82A2F390, RVA: 0x00A2F390
eventVoid idAI2::AnimEvent_SetDeltaScale(
        const idMD6Anim* const animation, const idVec3& scale) {
    idAI2AnimEventCall call("AnimEvent_SetDeltaScale", animation);
    call.vectors[0] = &scale;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_PopOffArmor@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDH@Z
// EA: 0x82A2F3E8, RVA: 0x00A2F3E8
eventVoid idAI2::AnimEvent_PopOffArmor(
        const idMD6Anim* const animation, const char* const armorName,
        const int force) {
    idAI2AnimEventCall call("AnimEvent_PopOffArmor", animation);
    call.strings[0] = armorName;
    call.integers[0] = force;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetDefaultMoveMode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2F548, RVA: 0x00A2F548
AI2_ANIM_EVENT0(AnimEvent_SetDefaultMoveMode)

// Retail symbol: ?AnimEvent_SetFullDeltaGravityMovementMode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2F5B8, RVA: 0x00A2F5B8
AI2_ANIM_EVENT0(AnimEvent_SetFullDeltaGravityMovementMode)

// Retail symbol: ?AnimEvent_Death@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2F628, RVA: 0x00A2F628
AI2_ANIM_EVENT0(AnimEvent_Death)

// Retail symbol: ?AnimEvent_ForceAllowLooting@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2F660, RVA: 0x00A2F660
AI2_ANIM_EVENT0(AnimEvent_ForceAllowLooting)

// Retail symbol: ?AnimEvent_BeginDrop@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2F6C0, RVA: 0x00A2F6C0
eventVoid idAI2::AnimEvent_BeginDrop(
        const idMD6Anim* const animation) {
    core.dropState = 1;
    core.movementDropping = true;
    const idAI2AnimEventCall call("AnimEvent_BeginDrop", animation);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_ParticleAtRottrack@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclParticle@@ABVidJointName@@ABVidVec3@@@Z
// EA: 0x82A2F750, RVA: 0x00A2F750
eventVoid idAI2::AnimEvent_ParticleAtRottrack(
        const idMD6Anim* const animation,
        const idDeclParticle* const particle, const idJointName& joint,
        const idVec3& offset) {
    idAI2AnimEventCall call("AnimEvent_ParticleAtRottrack", animation);
    call.objects[0] = particle;
    call.objects[1] = &joint;
    call.vectors[0] = &offset;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?accelSim_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82A2F900, RVA: 0x00A2F900
void accelSim_f(const idCmdArgs& args) {
    if (g_accelSimCallback != nullptr) {
        g_accelSimCallback(args);
    }
}

void Tungsten_SetAI2AccelSimCallback(
        const idAI2AccelSimCallback callback) {
    g_accelSimCallback = callback;
}

// Retail symbol: ?AnimEvent_PlayVoice@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4voiceMsg_t@@@Z
// EA: 0x82A2FA88, RVA: 0x00A2FA88
eventVoid idAI2::AnimEvent_PlayVoice(
        const idMD6Anim* const animation,
        const voiceMsg_t voiceMessage) {
    idAI2AnimEventCall call("AnimEvent_PlayVoice", animation);
    call.integers[0] = static_cast<int>(voiceMessage);
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_SetHealth@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@M@Z
// EA: 0x82A2FAC8, RVA: 0x00A2FAC8
eventVoid idAI2::AnimEvent_SetHealth(
        const idMD6Anim* const animation, const float health) {
    idAI2AnimEventCall call("AnimEvent_SetHealth", animation);
    call.scalars[0] = health;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_AnimEndEnterAnimation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2FB10, RVA: 0x00A2FB10
AI2_ANIM_EVENT0(AnimEvent_AnimEndEnterAnimation)

// Retail symbol: ?AnimEvent_AnimReleaseWaitHandle@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A2FB80, RVA: 0x00A2FB80
AI2_ANIM_EVENT0(AnimEvent_AnimReleaseWaitHandle)

// Retail symbol: ?AnimEvent_SetTakedownWindowState@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@_N@Z
// EA: 0x82A2FBF0, RVA: 0x00A2FBF0
eventVoid idAI2::AnimEvent_SetTakedownWindowState(
        const idMD6Anim* const animation, const bool open) {
    idAI2AnimEventCall call(
        "AnimEvent_SetTakedownWindowState", animation);
    call.booleans[0] = open;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_TriggerGore@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A2FC28, RVA: 0x00A2FC28
AI2_ANIM_EVENT_STRING(AnimEvent_TriggerGore)

// Retail symbol: ?AnimEvent_SetReferenceJointOverride@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiFoci_t@@ABVidJointName@@@Z
// EA: 0x82A2FC78, RVA: 0x00A2FC78
eventVoid idAI2::AnimEvent_SetReferenceJointOverride(
        const idMD6Anim* const animation, const aiFoci_t focus,
        const idJointName& joint) {
    idAI2AnimEventCall call(
        "AnimEvent_SetReferenceJointOverride", animation);
    call.integers[0] = static_cast<int>(focus);
    call.objects[0] = &joint;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_RandomRunCycleIndex@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA: 0x82A2FCF8, RVA: 0x00A2FCF8
eventVoid idAI2::AnimEvent_RandomRunCycleIndex(
        const idMD6Anim* const animation, const int minimum,
        const int maximum, const int seed) {
    idAI2AnimEventCall call("AnimEvent_RandomRunCycleIndex", animation);
    call.integers[0] = minimum;
    call.integers[1] = maximum;
    call.integers[2] = seed;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_RandomRunCycleNormal@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA: 0x82A2FE18, RVA: 0x00A2FE18
eventVoid idAI2::AnimEvent_RandomRunCycleNormal(
        const idMD6Anim* const animation, const int minimum,
        const int maximum, const int seed) {
    idAI2AnimEventCall call("AnimEvent_RandomRunCycleNormal", animation);
    call.integers[0] = minimum;
    call.integers[1] = maximum;
    call.integers[2] = seed;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_StartDropToGround@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A2FF38, RVA: 0x00A2FF38
AI2_ANIM_EVENT_JOINT(AnimEvent_StartDropToGround)

// Retail symbol: ?AnimEvent_HideMesh@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30350, RVA: 0x00A30350
AI2_ANIM_EVENT_STRING(AnimEvent_HideMesh)

// Retail symbol: ?AnimEvent_Explode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A303B0, RVA: 0x00A303B0
AI2_ANIM_EVENT0(AnimEvent_Explode)

// Retail symbol: ?AnimEvent_SetAimFocusToEnemy@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A30558, RVA: 0x00A30558
AI2_ANIM_EVENT0(AnimEvent_SetAimFocusToEnemy)

// Retail symbol: ?AnimEvent_AIReloadWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30600, RVA: 0x00A30600
AI2_ANIM_EVENT_STRING(AnimEvent_AIReloadWeapon)

// Retail symbol: ?AnimEvent_AIFireWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30798, RVA: 0x00A30798
AI2_ANIM_EVENT_STRING(AnimEvent_AIFireWeapon)

// Retail symbol: ?AnimEvent_MeleeKick@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A30AF0, RVA: 0x00A30AF0
AI2_ANIM_EVENT_JOINT(AnimEvent_MeleeKick)

// Retail symbol: ?AnimEvent_EquipItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30C48, RVA: 0x00A30C48
AI2_ANIM_EVENT_STRING(AnimEvent_EquipItem)

// Retail symbol: ?AnimEvent_HolsterItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30D88, RVA: 0x00A30D88
AI2_ANIM_EVENT_STRING(AnimEvent_HolsterItem)

// Retail symbol: ?AnimEvent_DropAttachment@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A30F10, RVA: 0x00A30F10
AI2_ANIM_EVENT_STRING(AnimEvent_DropAttachment)

// Retail symbol: ?AnimEvent_MeleePunch@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A31050, RVA: 0x00A31050
AI2_ANIM_EVENT_JOINT(AnimEvent_MeleePunch)

// Retail symbol: ?AnimEvent_PushEntity@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A311A8, RVA: 0x00A311A8
AI2_ANIM_EVENT0(AnimEvent_PushEntity)

// Retail symbol: ?AnimEvent_LaunchItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A314D8, RVA: 0x00A314D8
AI2_ANIM_EVENT_JOINT(AnimEvent_LaunchItem)

// Retail symbol: ?AnimEvent_LaunchItemFromWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@PBD@Z
// EA: 0x82A31928, RVA: 0x00A31928
eventVoid idAI2::AnimEvent_LaunchItemFromWeapon(
        const idMD6Anim* const animation, const idJointName& joint,
        const char* const weaponName) {
    idAI2AnimEventCall call(
        "AnimEvent_LaunchItemFromWeapon", animation);
    call.objects[0] = &joint;
    call.strings[0] = weaponName;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_ThrowGrenade@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A31C90, RVA: 0x00A31C90
AI2_ANIM_EVENT_JOINT(AnimEvent_ThrowGrenade)

// Retail symbol: ?AnimEvent_VoiceOver@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA: 0x82A31E70, RVA: 0x00A31E70
eventVoid idAI2::AnimEvent_VoiceOver(
        const idMD6Anim* const animation,
        const idDeclVoiceOver* const voiceOver) {
    idAI2AnimEventCall call("AnimEvent_VoiceOver", animation);
    call.objects[0] = voiceOver;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_StopVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A31F60, RVA: 0x00A31F60
AI2_ANIM_EVENT0(AnimEvent_StopVoiceOver)

// Retail symbol: ?AnimEvent_StartMeleeTrace@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA: 0x82A32040, RVA: 0x00A32040
AI2_ANIM_EVENT_JOINT(AnimEvent_StartMeleeTrace)

// Retail symbol: ?AnimEvent_StartMeleeTrace2@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@1PBVidDeclDamage@@@Z
// EA: 0x82A32208, RVA: 0x00A32208
eventVoid idAI2::AnimEvent_StartMeleeTrace2(
        const idMD6Anim* const animation,
        const idJointName& startJoint, const idJointName& endJoint,
        const idDeclDamage* const damage) {
    idAI2AnimEventCall call("AnimEvent_StartMeleeTrace2", animation);
    call.objects[0] = &startJoint;
    call.objects[1] = &endJoint;
    call.objects[2] = damage;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_StartMeleeTraceTag@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA: 0x82A32410, RVA: 0x00A32410
AI2_ANIM_EVENT_STRING(AnimEvent_StartMeleeTraceTag)

// Retail symbol: ?AnimEvent_StartMeleeTraceTag2@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDABVidJointName@@PBVidDeclDamage@@@Z
// EA: 0x82A32648, RVA: 0x00A32648
eventVoid idAI2::AnimEvent_StartMeleeTraceTag2(
        const idMD6Anim* const animation, const char* const tagName,
        const idJointName& endJoint,
        const idDeclDamage* const damage) {
    idAI2AnimEventCall call("AnimEvent_StartMeleeTraceTag2", animation);
    call.strings[0] = tagName;
    call.objects[0] = &endJoint;
    call.objects[1] = damage;
    return DispatchAnimEvent(*this, call);
}

// Retail symbol: ?AnimEvent_EndMeleeTrace@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A328B0, RVA: 0x00A328B0
AI2_ANIM_EVENT0(AnimEvent_EndMeleeTrace)

// Retail symbol: ?AnimEvent_TraversalAttackChoice@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HMM@Z
// EA: 0x82A32970, RVA: 0x00A32970
eventVoid idAI2::AnimEvent_TraversalAttackChoice(
        const idMD6Anim* const animation, const int choice,
        const float minimum, const float maximum) {
    idAI2AnimEventCall call(
        "AnimEvent_TraversalAttackChoice", animation);
    call.integers[0] = choice;
    call.scalars[0] = minimum;
    call.scalars[1] = maximum;
    return DispatchAnimEvent(*this, call);
}

#undef AI2_ANIM_EVENT_JOINT
#undef AI2_ANIM_EVENT_STRING
#undef AI2_ANIM_EVENT0
