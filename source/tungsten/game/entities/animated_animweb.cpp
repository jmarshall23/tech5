#include "game/entities/animated_animweb.h"

#include "idlib/lib_print.h"

namespace {
idAnimatedAnimWebServices defaultAnimWebServices;
idAnimatedAnimWebServices* activeAnimWebServices = &defaultAnimWebServices;
}

void idAnimated_AnimWeb::SetServices(idAnimatedAnimWebServices* services) {
    activeAnimWebServices = services == nullptr
        ? &defaultAnimWebServices : services;
}

idAnimatedAnimWebServices& idAnimated_AnimWeb::Services() {
    return *activeAnimWebServices;
}

// EA 0x82C017A0
void idAnimated_AnimWeb::GetSoundTransform(
        idVec3& origin, idMat3& axis) const {
    Services().GetSoundTransform(*this, origin, axis);
}

// EA 0x82C01838
awPathResult_t idAnimated_AnimWeb::ChangeAnimWebState(const char* state) {
    return Services().ChangeState(*this, nullptr, state,
        nullptr, nullptr, false);
}

// EA 0x82C01958
awPathResult_t idAnimated_AnimWeb::ChangeAnimWebState(
        const char* subWeb, const char* state) {
    return Services().ChangeState(*this, subWeb, state,
        nullptr, nullptr, false);
}

// EA 0x82C019C0
awPathResult_t idAnimated_AnimWeb::ChangeAnimWebStateVia(
        const char* state, const char* viaState) {
    return Services().ChangeState(*this, nullptr, state,
        nullptr, viaState, false);
}

// EA 0x82C01BE0
awPathResult_t idAnimated_AnimWeb::ForceAnimWebState(const char* state) {
    return Services().ChangeState(*this, nullptr, state,
        nullptr, nullptr, true);
}

// EA 0x82C01D48
awPathResult_t idAnimated_AnimWeb::ChangeAnimWebStateVia(
        const char* subWeb, const char* state,
        const char* viaSubWeb, const char* viaState) {
    return Services().ChangeState(*this, subWeb, state,
        viaSubWeb, viaState, false);
}

// EA 0x82C01DC8
eventVoid idAnimated_AnimWeb::Event_ChangeAnimState(
        const char* subWeb, const char* state) {
    ChangeAnimWebState(subWeb, state);
    return {};
}

// EA 0x82C01E18
eventVoid idAnimated_AnimWeb::Event_ChangeAnimStateVia(
        const char* subWeb, const char* state,
        const char* viaSubWeb, const char* viaState) {
    ChangeAnimWebStateVia(subWeb, state, viaSubWeb, viaState);
    return {};
}

// EA 0x82C01E70
eventVoid idAnimated_AnimWeb::Event_ForceAnimState(
        const char* subWeb, const char* state, const int) {
    if (subWeb == nullptr || subWeb[0] == '\0') ForceAnimWebState(state);
    else Services().ChangeState(*this, subWeb, state,
        nullptr, nullptr, true);
    return {};
}

// EA 0x82C01EC8
eventBool idAnimated_AnimWeb::Event_StartVoiceOver(idEntity* speaker,
        const idDeclVoiceOver* voiceOver, const bool force) {
    return eventBool(voiceOver != nullptr
        && Services().StartVoiceOver(*this, speaker, voiceOver, force));
}

// EA 0x82C01F58
eventVoid idAnimated_AnimWeb::AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* voiceOver) {
    if (voiceOver == nullptr) {
        idLibPrint::Warning(
            "Invalid voice over decl specified for AnimEvent_VoiceOver");
    } else {
        Services().StartVoiceOver(*this,
            reinterpret_cast<idEntity*>(this), voiceOver, false);
    }
    return {};
}

// EA 0x82C01FD0
eventVoid idAnimated_AnimWeb::AnimEvent_HolsterItem(
        const idMD6Anim*, const char* itemName) {
    Services().EquipInventoryItem(*this, itemName, false);
    return {};
}

// EA 0x82C02168
eventVoid idAnimated_AnimWeb::AnimEvent_EquipItem(
        const idMD6Anim*, const char* itemName) {
    Services().EquipInventoryItem(*this, itemName, true);
    return {};
}

// EA 0x82C02300
eventVoid idAnimated_AnimWeb::AnimEvent_ItemStartFX(
        const idMD6Anim*, const char* itemName, const int condition) {
    Services().ItemFX(*this, itemName, condition, true);
    return {};
}

// EA 0x82C023D8
eventVoid idAnimated_AnimWeb::AnimEvent_ItemStopFX(
        const idMD6Anim*, const char* itemName, const int condition) {
    Services().ItemFX(*this, itemName, condition, false);
    return {};
}

// EA 0x82C024A8
void idAnimated_AnimWeb::Hide() {
    Services().SetVisible(*this, false);
}

// EA 0x82C02530
void idAnimated_AnimWeb::Show() {
    Services().SetVisible(*this, true);
}

// EA 0x82C025C0
eventVoid idAnimated_AnimWeb::AnimEvent_HideFFFKnife(
        const idMD6Anim*, const char* group, const char* knife) {
    Services().SetKnifeVisible(*this, group, knife, false);
    return {};
}

// EA 0x82C02670
eventVoid idAnimated_AnimWeb::AnimEvent_ShowFFFKnife(
        const idMD6Anim*, const char* group, const char* knife) {
    Services().SetKnifeVisible(*this, group, knife, true);
    return {};
}

// EA 0x82C02718
eventVoid idAnimated_AnimWeb::AnimEvent_DamagePlayer(
        const idMD6Anim*, const idDeclDamage* damage,
        const int location, const float scale) {
    if (damage != nullptr) {
        Services().DamagePlayer(*this, damage, location, scale);
    }
    return {};
}

// EA 0x82C02870
eventVoid idAnimated_AnimWeb::AnimEvent_PlayerControllerShake(
        const idMD6Anim*, const int low, const int lowTime,
        const int high, const int highTime) {
    Services().ControllerShake(*this, low, lowTime, high, highTime);
    return {};
}

// EA 0x82C02910
void idAnimated_AnimWeb::UpdateCollisionPieces(
        idBounds& bounds, const bool force) {
    for (int pieceIndex = 0; pieceIndex < collisionPieces.Num();
            ++pieceIndex) {
        collisionPiece_t& piece = collisionPieces[pieceIndex];
        if (piece.curStage < 0 || piece.curStage >= piece.stages.Num()) {
            continue;
        }
        Services().UpdateCollisionPiece(
            *this, pieceIndex, piece.curStage, bounds, force);
    }
}

// EA 0x82C02D50
void idAnimated_AnimWeb::SetStage(
        const int piece, const int stage, const bool force) {
    if (piece < 0 || piece >= collisionPieces.Num()) return;
    collisionPiece_t& collisionPiece = collisionPieces[piece];
    if (stage < 0 || stage >= collisionPiece.stages.Num()) return;
    if (!force && collisionPiece.curStage == stage) return;
    collisionPiece.curStage = stage;
    Services().SetCollisionStage(*this, piece, stage, force);
}

// EA 0x82C02EB0
eventVoid idAnimated_AnimWeb::AnimEvent_SetStage(
        const idMD6Anim*, const int piece, const int stage) {
    SetStage(piece, stage, false);
    return {};
}

// EA 0x82C02EF0
eventVoid idAnimated_AnimWeb::AnimEvent_TriggerAttachments(
        const idMD6Anim*) {
    Services().TriggerAttachments(*this);
    return {};
}

// EA 0x82C03010
eventVoid idAnimated_AnimWeb::AnimEvent_HideMesh(
        const idMD6Anim*, const char* mesh) {
    Services().SetMeshVisible(*this, mesh, false);
    return {};
}

// EA 0x82C03098
void idTarget_AnimWebChangeState::OnActivate(idEntity*) {
    if (target != nullptr) {
        target->ChangeAnimWebState(subWeb.c_str(), state.c_str());
    }
}

// EA 0x82C03178
void idTarget_AnimWebChangeStateVia::OnActivate(idEntity*) {
    if (target != nullptr) {
        target->ChangeAnimWebStateVia(subWeb.c_str(), state.c_str(),
            viaSubWeb.c_str(), viaState.c_str());
    }
}

// EA 0x82C03258
void idTarget_AnimWebPause::OnActivate(idEntity*) {
    if (target != nullptr) {
        idAnimated_AnimWeb::Services().PauseAnimWeb(*target, true);
    }
}

// EA 0x82C03300
void idTarget_AnimWebUnpause::OnActivate(idEntity*) {
    if (target != nullptr) {
        idAnimated_AnimWeb::Services().PauseAnimWeb(*target, false);
    }
}

// EA 0x82C03518
void idAnimated_AnimWeb::Think() {
    if (applyAnimDelta) Services().ApplyOriginDelta(*this);
    idBounds bounds;
    UpdateCollisionPieces(bounds, false);
    Services().UpdateAnimation(*this);
    if (useFaceManager) Services().UpdateFace(*this);
    Services().Think(*this);
    if (useAmbientAnims && !animWebParms.ambientAnims.IsEmpty()
            && Services().GetGameMilliseconds() >= ambientWait) {
        ChangeAnimWebState(animWebParms.ambientAnims[0].c_str());
        ambientWait = Services().GetGameMilliseconds() + ambientWaitTime;
    }
}

// EA 0x82C03B78
void idAnimated_AnimWeb::Spawn() {
    if (!Services().InitializeAnimWeb(*this)) {
        idLibPrint::Error("Invalid anim web on entity '%s'", name.c_str());
        return;
    }
    for (int index = 0; index < startingAttachments.Num(); ++index) {
        const attachment_t& attachment = startingAttachments[index];
        Services().AddAttachment(*this, attachment.entityDef,
            attachment.declInventory, attachment.md6,
            attachment.entityName.c_str(), attachment.lwoName.c_str(),
            attachment.tag.c_str(), attachment.equipSlot);
    }
    for (int index = 0; index < collisionPieces.Num(); ++index) {
        Services().InitializeCollisionPiece(*this, index);
        if (!collisionPieces[index].stages.IsEmpty()) {
            SetStage(index, collisionPieces[index].curStage, true);
        }
    }
    if (!animWebParms.initialState.IsEmpty()) {
        Services().ChangeState(*this,
            animWebParms.initialSubWeb.c_str(),
            animWebParms.initialState.c_str(), nullptr, nullptr, true);
    }
    ambientWait = Services().GetGameMilliseconds() + ambientWaitTime;

    // EA 0x82C04788: the retail cleanup thunk released temporary spawn
    // strings and collision descriptors; automatic storage owns them here.
}

// EA 0x82C048F0
idAnimated_AnimWeb::idAnimated_AnimWeb()
    : name(),
      animWebParms(),
      startingAttachments(0),
      applyAnimDelta(false),
      useAmbientAnims(false),
      ambientWaitTime(0),
      ambientWait(0),
      useFaceManager(false),
      sceneModel(false),
      overrideUsingDeferredPositions(false),
      crushDamage(nullptr),
      pushDamage(nullptr),
      soundJoint(),
      collisionPieces(0),
      subtitleName(),
      lightFromJointPositions(false),
      skipJointForLighting(),
      hideMeshes(0),
      showMeshes(0) {}

// EA 0x82C04D70
idAnimated_AnimWeb::~idAnimated_AnimWeb() {
    Services().Shutdown(*this);
    collisionPieces.Clear();
    startingAttachments.Clear();
    hideMeshes.Clear();
    showMeshes.Clear();
}
