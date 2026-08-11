#include "presentable.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

idPresentableServices defaultPresentableServices;
idPresentableServices* presentableServices = &defaultPresentableServices;

idVec3 ZeroVector() {
    return idVec3(0.0f, 0.0f, 0.0f);
}

idMat3 IdentityMatrix() {
    return idMat3(1.0f);
}

idBounds ZeroBounds() {
    idBounds bounds;
    bounds[0] = ZeroVector();
    bounds[1] = ZeroVector();
    return bounds;
}

idQuat MatrixToQuaternion(const idMat3& matrix) {
    idQuat result;
    const float trace = matrix[0][0] + matrix[1][1] + matrix[2][2];
    if (trace > 0.0f) {
        const float scale = std::sqrt(trace + 1.0f) * 2.0f;
        result.w = 0.25f * scale;
        result.x = (matrix[2][1] - matrix[1][2]) / scale;
        result.y = (matrix[0][2] - matrix[2][0]) / scale;
        result.z = (matrix[1][0] - matrix[0][1]) / scale;
    } else if (matrix[0][0] > matrix[1][1]
            && matrix[0][0] > matrix[2][2]) {
        const float scale = std::sqrt(1.0f + matrix[0][0]
            - matrix[1][1] - matrix[2][2]) * 2.0f;
        result.w = (matrix[2][1] - matrix[1][2]) / scale;
        result.x = 0.25f * scale;
        result.y = (matrix[0][1] + matrix[1][0]) / scale;
        result.z = (matrix[0][2] + matrix[2][0]) / scale;
    } else if (matrix[1][1] > matrix[2][2]) {
        const float scale = std::sqrt(1.0f + matrix[1][1]
            - matrix[0][0] - matrix[2][2]) * 2.0f;
        result.w = (matrix[0][2] - matrix[2][0]) / scale;
        result.x = (matrix[0][1] + matrix[1][0]) / scale;
        result.y = 0.25f * scale;
        result.z = (matrix[1][2] + matrix[2][1]) / scale;
    } else {
        const float scale = std::sqrt(1.0f + matrix[2][2]
            - matrix[0][0] - matrix[1][1]) * 2.0f;
        result.w = (matrix[1][0] - matrix[0][1]) / scale;
        result.x = (matrix[0][2] + matrix[2][0]) / scale;
        result.y = (matrix[1][2] + matrix[2][1]) / scale;
        result.z = 0.25f * scale;
    }
    return result.Normalize();
}

idQuat SlerpQuaternion(idQuat from, idQuat to, float fraction) {
    float cosine = from.x * to.x + from.y * to.y
        + from.z * to.z + from.w * to.w;
    if (cosine < 0.0f) {
        cosine = -cosine;
        to = to * -1.0f;
    }

    if (cosine > 0.9995f) {
        return (from + (to - from) * fraction).Normalize();
    }

    cosine = std::max(-1.0f, std::min(1.0f, cosine));
    const float angle = std::acos(cosine);
    const float sine = std::sin(angle);
    if (std::fabs(sine) < 1.0e-6f) {
        return from;
    }
    const float fromWeight = std::sin((1.0f - fraction) * angle) / sine;
    const float toWeight = std::sin(fraction * angle) / sine;
    return (from * fromWeight + to * toWeight).Normalize();
}

template<typename EnumType>
void SerializeEnum(idSerializer& serializer, EnumType& value) {
    int packed = static_cast<int>(value);
    serializer.Serialize(packed);
    if (serializer.IsReading()) {
        value = static_cast<EnumType>(packed);
    }
}

float BoundsRadius(const idBounds& bounds) {
    const idVec3 center = (bounds[0] + bounds[1]) * 0.5f;
    const idVec3 first = bounds[0] - center;
    const idVec3 second = bounds[1] - center;
    return std::max(first.Length(), second.Length());
}

} // namespace

void Tungsten_SetPresentableServices(idPresentableServices* services) {
    presentableServices = services != nullptr ? services
                                              : &defaultPresentableServices;
}

void idPresentableServices::DestroyPresentable(idPresentable* presentable) {
    delete presentable;
}

idClipModelInfo::idClipModelInfo() {
    Clear();
}

void idClipModelInfo::Clear() {
    type = CLIPMODEL_NONE;
    size = ZeroVector();
    offset = ZeroVector();
    numSides = 0;
    clipShrink = false;
    allowInline = false;
    softObstacle = false;
    overrideClipMaterial = nullptr;
}

idPresentable::idPresentable()
    : groupMasterSpawnId(0)
    , groupMaster(nullptr)
    , clipModelDynamic(false)
    , clipModelDynamicAxis(false)
    , clipModelPhysID(-1)
    , becameReplicated(false)
    , origin(ZeroVector())
    , axis(IdentityMatrix())
    , model(nullptr)
    , curIFF(IFFN_UNINITIALIZED)
    , hidden(false)
    , entityNumber(ENTITYNUM_NONE)
    , clipModelSpawnPos(ZeroVector())
    , clipModelSpawnAxis(IdentityMatrix())
    , clipModel(nullptr)
    , clipModelContents(1)
    , overridingClipContents(false)
    , fxInitialized(false)
    , fxDecl(nullptr)
    , soundEmitter(nullptr)
    , parentSpawnId(0)
    , parent(nullptr)
    , parentJoint(-1)
    , controllerSpawnId(0)
    , controller(nullptr)
    , index(-1)
    , activeIndex(-1)
    , serializedIndex(-1)
    , debugName(nullptr)
    , serializeCount(0)
    , entity(nullptr)
    , spawnId(0)
    , radius(DEFAULT_PRESENTABLE_RADIUS)
    , changedCount(0)
    , stopSerializeCount(0)
    , clientThink(true)
    , team(TEAM_NONE)
    , ownerPlayerIndex(-1)
    , influenceHandle(-1)
    , usablePlayerMask(0)
    , usableState(USABLE_NOT_USABLE)
    , lastUsedTime(0)
    , highlightColor(PRESENTABLE_HIGHLIGHT_NONE)
    , predictedKey(0xFFFFFFFFu)
    , entityNumAdded(false)
    , serverPermanentSoundChannels(0)
    , hideDuringFirstSSInterval(false)
    , queueForDelete(false)
    , csInterface(nullptr)
    , entityTypeFlags(0)
    , shouldPresent(true)
    , shouldPresentCounter(presentableServices->OptimizePresentCountdown()) {
    origins[0] = origins[1] = origin;
    axes[0] = axes[1] = axis;
    peerInRangeMask[0] = 0xFFFFFFFFu;
    peerInRangeMask[1] = 0xFFFFFFFFu;
}

idPresentable::idPresentable(idEntity* newEntity,
        idRenderModel* renderModel, int newEntityNumber,
        const idDeclFX* declaration)
    : idPresentable() {
    entity = newEntity;
    entityNumber = newEntityNumber;
    fxDecl = declaration;
    SetRenderModel(renderModel, true);
    InitFXMgr(declaration);
}

idPresentable::~idPresentable() {
    if (clipModel != nullptr) {
        presentableServices->DeleteClipModel(clipModel);
        clipModel = nullptr;
    }
    FreeRenderModel();
    ShutdownFXMgr();
}

void idPresentable::Delete() {
    Shutdown();
    presentableServices->RemovePresentable(this);
    presentableServices->DestroyPresentable(this);
}

void idPresentable::PostSerializeRead(bool) {
    if (!shouldPresent && shouldPresentCounter > 0) {
        --shouldPresentCounter;
    }
}

void idPresentable::SetClipModelContents(int contents) {
    if (contents != clipModelContents) {
        presentableServices->MarkSerialized(this);
    }
    clipModelContents = contents;
}

const idSoundShader* idPresentable::GetCurrentSoundShader(
        soundChannel_t channel) const {
    return soundEmitter != nullptr
        ? presentableServices->GetCurrentSoundShader(soundEmitter, channel)
        : nullptr;
}

void idPresentable::FreeSoundEmitter(bool immediate) {
    if (soundEmitter != nullptr) {
        presentableServices->StopSound(soundEmitter, SND_CHANNEL_ANY);
        presentableServices->FreeSoundEmitter(soundEmitter, immediate);
        soundEmitter = nullptr;
    }
}

void idPresentable::Show() {
    if (model != nullptr) {
        presentableServices->CommitRenderModel(model);
        presentableServices->MarkSerialized(this);
    }
    StartFX(static_cast<fxCondition_t>(0),
        static_cast<fxExtraCondition_t>(0));
    hidden = false;
}

void idPresentable::ShutdownFXMgr(idFXManager*) {
    if (fxInitialized) {
        presentableServices->ShutdownFX(this);
        fxInitialized = false;
    }
}

void idPresentable::SetLocalClipModelContents(int contents) {
    if (clipModel != nullptr) {
        presentableServices->SetClipModelContents(clipModel, contents);
        presentableServices->MarkSerialized(this);
    }
}

void idPresentable::SetParm(const idDeclRenderParm* parm, float scalar) {
    if (model != nullptr) {
        presentableServices->SetRenderParm(model, parm, scalar);
    }
}

void idPresentable::SetParm(const idDeclRenderParm* parm,
        const idVec3& vector) {
    if (model != nullptr) {
        presentableServices->SetRenderParm(model, parm, vector);
    }
}

void idPresentable::SetParm(const idDeclRenderParm* parm,
        const idVec4& vector) {
    if (model != nullptr) {
        presentableServices->SetRenderParm(model, parm, vector);
    }
}

idParmBlock* idPresentable::GetParmBlock() {
    return model != nullptr ? presentableServices->GetParmBlock(model)
                            : nullptr;
}

void idPresentable::FreeRenderModel() {
    if (model != nullptr) {
        presentableServices->SetRenderModelUnlinked(model, true);
        presentableServices->MarkRenderModelForDelete(model);
        presentableServices->CommitRenderModel(model);
        SetRenderModel(nullptr, true);
    }
}

void idPresentable::Shutdown() {
    ShutdownFXMgr();
    FreeSoundEmitter(false);
}

void idPresentable::UpdateClientCollision(const idVec3&,
        const idMat3&, const idVec3&, const idMat3&) {
    if (clipModel == nullptr || !clipModelDynamic
            || overridingClipContents) {
        return;
    }
    if (!ShouldLinkPresentableCollision()) {
        presentableServices->UnlinkClipModel(clipModel);
        return;
    }
    const idMat3 linkAxis = clipModelDynamicAxis ? axis : IdentityMatrix();
    presentableServices->LinkClipModel(clipModel, entityNumber,
        clipModelPhysID, origin, linkAxis);
}

void idPresentable::InheritPropertiesFromModel(bool inheritTransform) {
    if (model == nullptr) {
        radius = DEFAULT_PRESENTABLE_RADIUS;
        return;
    }

    if (inheritTransform) {
        bool deferred = false;
        presentableServices->GetRenderModelTransform(model, origin, axis,
            deferred);
        origins[0] = origins[1] = origin;
        axes[0] = axes[1] = axis;
    }
    idBounds bounds = ZeroBounds();
    presentableServices->GetRenderModelBounds(model, bounds);
    radius = BoundsRadius(bounds);
    if (!(radius > 0.0f)) {
        radius = DEFAULT_PRESENTABLE_RADIUS;
    }
}

void idPresentable::UpdateModelTransform() {
    if (model != nullptr) {
        idVec3 worldOrigin;
        idMat3 worldAxis;
        GetWorldTransform(worldOrigin, worldAxis);
        presentableServices->SetRenderModelTransform(model, worldOrigin,
            worldAxis);
    }
}

void idPresentable::ClientOverrideClipContents(int contents) {
    clipModelContents = contents;
    overridingClipContents = true;
    if (clipModel != nullptr) {
        presentableServices->SetClipModelContents(clipModel, contents);
        presentableServices->EnableClipModel(clipModel, true);
        presentableServices->LinkClipModel(clipModel, entityNumber, -1,
            origin, axis);
    }
}

idSoundEmitter* idPresentable::GetSoundEmitter(bool allocate) {
    if (soundEmitter == nullptr && allocate) {
        soundEmitter = presentableServices->AllocateSoundEmitter(debugName);
    }
    return soundEmitter;
}

void idPresentable::UpdateSound(const idVec3& soundOrigin,
        const idMat3& soundAxis, const idVec3& velocity, int listenerId) {
    if (GetSoundEmitter(false) != nullptr) {
        presentableServices->UpdateSoundEmitter(soundEmitter, soundOrigin,
            soundAxis, velocity, listenerId);
    }
}

bool idPresentable::IsPlayingSound(soundChannel_t channel) const {
    return soundEmitter != nullptr
        && presentableServices->IsSoundPlaying(soundEmitter, channel);
}

void idPresentable::FadeSound(soundChannel_t channel, float to, float over) {
    if (GetSoundEmitter(false) != nullptr) {
        presentableServices->FadeSound(soundEmitter, channel, to, over);
    }
}

void idPresentable::FadePitch(soundChannel_t channel, float to, float over) {
    if (GetSoundEmitter(false) != nullptr) {
        presentableServices->FadePitch(soundEmitter, channel, to, over);
    }
}

void idPresentable::UpdateSound() {
    if (GetSoundEmitter(false) != nullptr) {
        UpdateSound(origin, axis, ZeroVector(), entityNumber + 1);
    }
}

int idPresentable::StartSoundShader(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        std::uint8_t peerMask) {
    if (shader == nullptr || GetSoundEmitter(true) == nullptr) {
        return 0;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateSoundStart(this, channel, shader,
            parms, peerMask);
    }
    return presentableServices->StartSound(soundEmitter, channel, shader,
        parms);
}

void idPresentable::SetSoundVolume(soundChannel_t channel, float volume,
        std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateSoundVolume(this, channel, volume,
            peerMask);
    }
    presentableServices->SetSoundVolume(soundEmitter, channel, volume);
}

void idPresentable::SetSoundPitch(soundChannel_t channel, float pitch,
        std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateSoundPitch(this, channel, pitch,
            peerMask);
    }
    presentableServices->SetSoundPitch(soundEmitter, channel, pitch);
}

void idPresentable::ModifySound(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parms,
        std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateSoundModify(this, channel, shader,
            parms, peerMask);
    }
    presentableServices->ModifySound(soundEmitter, channel, shader, parms);
}

void idPresentable::SetVolumeAdjustment(soundChannel_t channel,
        float adjustment, std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateVolumeAdjustment(this, channel,
            adjustment, false, peerMask);
    }
    presentableServices->SetVolumeAdjustment(soundEmitter, adjustment);
}

void idPresentable::SetClearVolumeAdjustment(soundChannel_t channel,
        std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateVolumeAdjustment(this, channel,
            0.0f, true, peerMask);
    }
    presentableServices->ClearVolumeAdjustment(soundEmitter);
}

void idPresentable::StopSound(soundChannel_t channel,
        std::uint8_t peerMask) {
    if (GetSoundEmitter(false) == nullptr) {
        return;
    }
    if (peerMask != 0) {
        presentableServices->ReplicateStopSound(this, channel, peerMask);
    }
    presentableServices->StopSound(soundEmitter, channel);
}

void idPresentable::Hide(bool stopFX) {
    if (model != nullptr) {
        if (!presentableServices->IsRenderModelUnlinked(model)) {
            presentableServices->SetRenderModelUnlinked(model, true);
            presentableServices->CommitRenderModel(model);
        }
        presentableServices->MarkSerialized(this);
    }
    if (stopFX) {
        StopAllFX();
    }
    hidden = true;
    hideDuringFirstSSInterval = false;
}

void idPresentable::ResetFXMgr(const idDeclFX* declaration) {
    ShutdownFXMgr();
    InitFXMgr(declaration);
}

void idPresentable::StartFX(fxCondition_t condition,
        fxExtraCondition_t extraCondition) {
    presentableServices->StartFX(this, condition, extraCondition, true);
}

void idPresentable::LocalStartFX(fxCondition_t condition) {
    presentableServices->StartFX(this, condition,
        static_cast<fxExtraCondition_t>(0), false);
}

void idPresentable::StopFX(fxCondition_t condition,
        fxExtraCondition_t extraCondition) {
    presentableServices->StopFX(this, condition, extraCondition, true,
        false);
}

void idPresentable::LocalStopFX(fxCondition_t condition) {
    presentableServices->StopFX(this, condition,
        static_cast<fxExtraCondition_t>(0), false, false);
}

void idPresentable::StopAllFX() {
    presentableServices->StopAllFX(this, true, false);
}

void idPresentable::LocalStopAllFX() {
    presentableServices->StopAllFX(this, false, false);
}

void idPresentable::UpdateFX(const idVec3& fxOrigin,
        const idMat3& fxAxis, float fovScale, float depthHack) {
    const float time = static_cast<float>(presentableServices->GetScaledGameTime());
    const float frameTime = static_cast<float>(presentableServices->GetScaledFrameTime());
    presentableServices->UpdateFX(this, fxOrigin, fxAxis, ZeroVector(),
        fovScale * time, depthHack * frameTime);
}

void idPresentable::UpdateFX(float fovScale, float depthHack) {
    idVec3 worldOrigin;
    idMat3 worldAxis;
    GetWorldTransform(worldOrigin, worldAxis);
    UpdateFX(worldOrigin, worldAxis, fovScale, depthHack);
}

int idPresentable::GetLocalPlayerTeamNumber() const {
    return presentableServices->GetLocalPlayerTeam();
}

void idPresentable::IdentifyFriendFoeNeutral() {
    const int localTeam = GetLocalPlayerTeamNumber();
    if (localTeam == TEAM_NONE) {
        curIFF = IFFN_UNINITIALIZED;
    } else if (team != TEAM_NONE) {
        curIFF = localTeam == static_cast<int>(team)
            ? IFFN_FRIEND : IFFN_FOE;
    } else if (ownerPlayerIndex != -1) {
        curIFF = presentableServices->PlayerIndexIsLocal(ownerPlayerIndex)
            ? IFFN_FRIEND : IFFN_FOE;
    } else {
        curIFF = IFFN_NEUTRAL;
    }
}

void idPresentable::InitFXMgr(const idDeclFX* declaration,
        idFXManager*) {
    fxDecl = declaration;
    if (declaration != nullptr) {
        GetSoundEmitter(true);
        presentableServices->InitializeFX(this, declaration);
        fxInitialized = true;
    }
}

void idPresentable::InitFXMgr(const idDeclFX* declaration) {
    InitFXMgr(declaration, nullptr);
}

void idPresentable::ShutdownFXMgr() {
    ShutdownFXMgr(nullptr);
}

void idPresentable::SetTeam(gameTeam_t newTeam) {
    team = newTeam;
    IdentifyFriendFoeNeutral();
    StartFX(static_cast<fxCondition_t>(46),
        static_cast<fxExtraCondition_t>(0));
}

void idPresentable::SetOwnerPlayerIndex(int ownerIndex) {
    ownerPlayerIndex = ownerIndex;
    IdentifyFriendFoeNeutral();
}

idClipModel* idPresentable::CreateMoveableClipModel(
        const idClipModelInfo& information, idRenderModel* renderModel,
        const idVec3& renderModelScale, bool barrelCollision,
        float overrideRadius, const char* name) {
    return presentableServices->CreateMoveableClipModel(information,
        renderModel, renderModelScale, barrelCollision, overrideRadius,
        name);
}

void idPresentable::BecomeReplicated() {
    becameReplicated = true;
    origins[0] = origins[1] = origin;
    axes[0] = axes[1] = axis;
}

void idPresentable::AddToEntityLUT() {
    if (index == -1 || entityNumber == ENTITYNUM_NONE
            || entityNumber < 0 || entityNumber >= 8192) {
        return;
    }
    if (presentableServices->GetEntityLUT(entityNumber) != index) {
        presentableServices->SetEntityLUT(entityNumber, index);
    }
    entityNumAdded = true;
}

void idPresentable::RemoveFromEntityLUT() {
    if (index == -1 || entityNumber == ENTITYNUM_NONE
            || entityNumber < 0 || entityNumber >= 8192) {
        entityNumAdded = false;
        return;
    }
    if (presentableServices->GetEntityLUT(entityNumber) == index) {
        presentableServices->SetEntityLUT(entityNumber, -1);
    }
    entityNumAdded = false;
}

idBounds idPresentable::GetBounds(int bodyId) const {
    if (clipModel != nullptr) {
        return presentableServices->GetClipModelBounds(clipModel, false);
    }
    return entity != nullptr
        ? presentableServices->GetEntityBounds(entity, bodyId, false)
        : ZeroBounds();
}

idBounds idPresentable::GetAbsBounds(int bodyId) const {
    if (clipModel != nullptr) {
        return presentableServices->GetClipModelBounds(clipModel, true);
    }
    return entity != nullptr
        ? presentableServices->GetEntityBounds(entity, bodyId, true)
        : ZeroBounds();
}

idPlayer* idPresentable::GetPlayerEntity() const {
    return entity != nullptr ? presentableServices->CastPlayer(entity)
                             : nullptr;
}

bool idPresentable::IsTargetLockable(const idDeclAmmo* ammo) const {
    return entity != nullptr
        && presentableServices->EntityIsTargetLockable(entity, ammo);
}

usableState_t idPresentable::GetOnlineUsableState(
        idPresentablePlayer* user, int) const {
    return entity != nullptr
        ? presentableServices->GetEntityUsableState(entity, user)
        : usableState;
}

void idPresentable::GetOnlineModifiedCrosshairInfo(
        const idPresentable* activator, const idFocusTrace&,
        usableState_t state, idCrosshairInfo& info) {
    const int activatorBit = activator != nullptr
        ? (1 << (activator->entityNumber & 7)) : 0;
    const bool permitted = activatorBit != 0
        && (usablePlayerMask & activatorBit) != 0;

    switch (state) {
    case USABLE_LOOT:
        presentableServices->SetCrosshairState(&info, 12, permitted, false);
        break;
    case USABLE_PROP:
        presentableServices->SetCrosshairState(&info, 7, true, false);
        break;
    case USABLE_DOOR:
        presentableServices->SetCrosshairState(&info, 5, permitted, true);
        break;
    case USABLE_MOVER:
        presentableServices->SetCrosshairState(&info, 6, permitted, true);
        break;
    case USABLE_RC_PICKUP:
        presentableServices->SetCrosshairState(&info, 8, permitted, true);
        break;
    case USABLE_AMMO_REFILL:
        presentableServices->SetCrosshairState(&info,
            permitted ? 13 : 12, permitted, false);
        break;
    default:
        break;
    }
}

bool idPresentable::GetShouldPresent() const {
    if (presentableServices->IsMultiplayer()
            && !presentableServices->IsHost()
            && index >= 0 && index < 8192
            && presentableServices->OptimizePresents()) {
        return shouldPresentCounter != 0;
    }
    return true;
}

void idPresentable::SetParent(idPresentable* newParent, int joint) {
    parent = newParent;
    parentSpawnId = newParent != nullptr ? newParent->spawnId : 0;
    parentJoint = joint;
}

void idPresentable::Interpolate(int, float fraction) {
    const idVec3 oldOrigin = origin;
    const idMat3 oldAxis = axis;
    axis = SlerpQuaternion(MatrixToQuaternion(axes[0]),
        MatrixToQuaternion(axes[1]), fraction).ToMat3();
    origin = origins[0] + (origins[1] - origins[0]) * fraction;
    if (!ShouldInterpolate()) {
        origin = origins[1];
    }
    UpdateModelTransform();
    UpdateClientCollision(oldOrigin, oldAxis, origin, axis);
}

void idPresentable::ClientThink(int currentTime, float fraction,
        bool predict) {
    if (index >= 8192) {
        return;
    }
    Interpolate(currentTime, fraction);
    if (predict) {
        ClientPredict(currentTime, fraction);
    }
    UpdateFX(1.0f, 0.0f);
    UpdateSound();
    Present();
}

void idPresentable::SetRenderModel(idRenderModel* renderModel,
        bool inheritTransform) {
    model = renderModel;
    presentableServices->ResetFXAnimator(this, renderModel);
    if (model != nullptr) {
        InheritPropertiesFromModel(inheritTransform);
    }
}

void idPresentable::SetClipModelInfo(const idClipModelInfo& information,
        const idVec3& spawnPosition, const idMat3& spawnAxis) {
    clipModelInfo = information;
    clipModelSpawnPos = spawnPosition;
    clipModelSpawnAxis = spawnAxis;
    presentableServices->MarkSerialized(this);
}

void idPresentable::SetClipModelInfo_DynamicRenderModel(
        const idVec3& spawnPosition, const idMat3& spawnAxis,
        int contents) {
    clipModelInfo.Clear();
    clipModelInfo.type = idClipModelInfo::CLIPMODEL_RENDERMODEL;
    clipModelSpawnPos = spawnPosition;
    clipModelSpawnAxis = spawnAxis;
    clipModelDynamic = true;
    clipModelDynamicAxis = true;
    SetClipModelContents(contents);
    presentableServices->MarkSerialized(this);
}

int idPresentable::StartSoundShader(soundChannel_t channel,
        const idSoundShader* shader, int soundShaderFlags,
        std::uint8_t peerMask) {
    soundShaderParms_t parms{};
    parms.soundShaderFlags = static_cast<soundShaderFlags_t>(soundShaderFlags);
    return StartSoundShader(channel, shader, parms, peerMask);
}

void idPresentable::SetEntityNumber(int value) {
    RemoveFromEntityLUT();
    entityNumber = value;
    AddToEntityLUT();
}

idPresentable* idPresentable::GetParent() const {
    if (parentSpawnId == 0) {
        return nullptr;
    }
    idPresentable* resolved = presentableServices->ResolvePresentable(
        parentSpawnId);
    return resolved != nullptr && resolved->spawnId == parentSpawnId
        ? resolved : nullptr;
}

void idPresentable::SerializeFX(idSerializer& serializer) {
    bool hasFX = fxDecl != nullptr;
    serializer.Serialize(hasFX);
    if (!hasFX) {
        if (serializer.IsReading()) {
            ShutdownFXMgr();
            fxDecl = nullptr;
        }
        return;
    }

    const void* declaration = fxDecl;
    presentableServices->SerializeDeclaration(serializer, declaration);
    if (serializer.IsReading()) {
        const idDeclFX* serializedFX = static_cast<const idDeclFX*>(declaration);
        if (fxInitialized && serializedFX != fxDecl) {
            ShutdownFXMgr();
        }
        fxDecl = serializedFX;
        if (!fxInitialized) {
            InitFXMgr(fxDecl);
        }
    }
    presentableServices->SerializeFX(this, serializer);
}

void idPresentable::UpdateModelGroupMaster() {
    if (model == nullptr) {
        return;
    }
    int groupIndex = -1;
    idPresentable* master = groupMaster;
    if (master == nullptr && groupMasterSpawnId != 0) {
        master = presentableServices->ResolvePresentable(groupMasterSpawnId);
    }
    if (master != nullptr && master->model != nullptr) {
        groupIndex = presentableServices->GetRenderModelIndex(master->model);
    }
    presentableServices->SetRenderModelGroupMasterIndex(model, groupIndex);
}

void idPresentable::GetWorldTransformInternal(const idVec3& inOrigin,
        const idMat3& inAxis, idVec3& outOrigin, idMat3& outAxis) const {
    idPresentable* resolvedParent = parent;
    if (resolvedParent == nullptr && parentSpawnId != 0) {
        resolvedParent = presentableServices->ResolvePresentable(parentSpawnId);
    }
    if (resolvedParent == nullptr) {
        outOrigin = inOrigin;
        outAxis = inAxis;
        return;
    }

    if (parentJoint == -1) {
        idVec3 parentOrigin;
        idMat3 parentAxis;
        resolvedParent->GetWorldTransform(parentOrigin, parentAxis);
        outOrigin = parentOrigin + parentAxis * inOrigin;
        outAxis = parentAxis * inAxis;
        return;
    }
    if (!presentableServices->GetJointWorldTransform(resolvedParent,
            parentJoint, inOrigin, inAxis, outOrigin, outAxis)) {
        outOrigin = inOrigin;
        outAxis = inAxis;
    }
}

void idPresentable::GetWorldTransform(idVec3& outOrigin,
        idMat3& outAxis) {
    GetWorldTransformInternal(origin, axis, outOrigin, outAxis);
}

void idPresentable::Present() {
    if (presentableServices->IsHost()) {
        presentableServices->MarkSerialized(this);
        shouldPresent = true;
    }
    if (!GetShouldPresent() || model == nullptr) {
        return;
    }
    UpdateModelTransform();
    UpdateModelGroupMaster();
    if (hidden) {
        if (!presentableServices->IsRenderModelUnlinked(model)) {
            presentableServices->SetRenderModelUnlinked(model, true);
            presentableServices->CommitRenderModel(model);
        }
    } else {
        presentableServices->SetRenderModelUnlinked(model, false);
        presentableServices->CommitRenderModel(model);
    }
}

void idPresentable::Serialize(idSerializer& serializer) {
    ++serializeCount;
    serializer.Serialize(entityTypeFlags);

    if (serializer.IsReading()) {
        origins[0] = origins[1];
        axes[0] = axes[1];
    } else {
        origins[1] = origin;
        axes[1] = axis;
    }
    serializer.Serialize(origins[1]);
    serializer.SerializeQ(axes[1]);
    if (serializer.IsReading()) {
        origin = origins[1];
        axis = axes[1];
        if (!becameReplicated) {
            origins[0] = origins[1];
            axes[0] = axes[1];
            becameReplicated = true;
        }
    }

    serializer.Serialize(parentSpawnId);
    serializer.Serialize(parentJoint);
    serializer.Serialize(controllerSpawnId);
    serializer.Serialize(entityNumber);
    if (serializer.IsReading() && entityNumber >= 12288) {
        entityNumber = ENTITYNUM_NONE;
    }

    const gameTeam_t oldTeam = team;
    SerializeEnum(serializer, team);
    serializer.Serialize(ownerPlayerIndex);
    if (serializer.IsReading() && oldTeam != team) {
        IdentifyFriendFoeNeutral();
    }
    serializer.Serialize(usablePlayerMask);
    SerializeEnum(serializer, usableState);

    bool serializedShouldPresent = shouldPresent;
    serializer.Serialize(serializedShouldPresent);
    if (serializer.IsWriting()) {
        shouldPresent = false;
    } else {
        shouldPresent = serializedShouldPresent;
        if (shouldPresent) {
            shouldPresentCounter = presentableServices->OptimizePresentCountdown();
        }
    }

    bool hasModel = model != nullptr;
    serializer.Serialize(hasModel);
    if (hasModel) {
        idStr modelName;
        if (serializer.IsWriting()) {
            const char* name = presentableServices->GetRenderModelName(model);
            modelName = name != nullptr ? name : "";
        }
        serializer.SerializeString(modelName);
        if (serializer.IsReading()) {
            const char* currentName = model != nullptr
                ? presentableServices->GetRenderModelName(model) : nullptr;
            if (model == nullptr || currentName == nullptr
                    || std::strcmp(currentName, modelName.c_str()) != 0) {
                FreeRenderModel();
                SetRenderModel(presentableServices->CreateRenderModel(
                    modelName.c_str()), false);
            }
        }
        if (ShouldSerializeHidden()) {
            serializer.Serialize(hidden);
        }
        serializer.Serialize(groupMasterSpawnId);
        presentableServices->SerializeRenderModel(model, serializer,
            ShouldSerializeRenderModelParms());
        SerializeEnum(serializer, highlightColor);
    } else if (serializer.IsReading()) {
        FreeRenderModel();
    }

    SerializeEnum(serializer, clipModelInfo.type);
    serializer.Serialize(clipModelInfo.size);
    serializer.Serialize(clipModelInfo.offset);
    serializer.Serialize(clipModelInfo.numSides);
    serializer.Serialize(clipModelInfo.clipShrink);
    serializer.Serialize(clipModelInfo.allowInline);
    serializer.Serialize(clipModelInfo.softObstacle);
    serializer.Serialize(clipModelDynamic);
    serializer.Serialize(clipModelDynamicAxis);
    const void* clipMaterial = clipModelInfo.overrideClipMaterial;
    presentableServices->SerializeDeclaration(serializer, clipMaterial);
    if (serializer.IsReading()) {
        clipModelInfo.overrideClipMaterial =
            static_cast<const idMaterial*>(clipMaterial);
    }
    serializer.Serialize(clipModelContents);
    if (!clipModelDynamic) {
        serializer.Serialize(clipModelSpawnPos);
        serializer.SerializeQ(clipModelSpawnAxis);
    } else if (serializer.IsReading()) {
        clipModelSpawnPos = origin;
        clipModelSpawnAxis = axis;
    }
    if (clipModelInfo.type == idClipModelInfo::CLIPMODEL_CUSTOM
            || clipModelInfo.type == idClipModelInfo::CLIPMODEL_RENDERMODEL) {
        serializer.SerializeString(clipModelInfo.clipModelName);
    }

    if (serializer.IsReading()) {
        if (clipModel != nullptr) {
            presentableServices->DeleteClipModel(clipModel);
            clipModel = nullptr;
        }
        if (clipModelInfo.type != idClipModelInfo::CLIPMODEL_NONE) {
            clipModel = CreateMoveableClipModel(clipModelInfo, model,
                idVec3(1.0f, 1.0f, 1.0f), false, 0.0f, debugName);
            if (clipModel != nullptr) {
                presentableServices->SetClipModelContents(clipModel,
                    clipModelContents);
                const idVec3 linkOrigin = clipModelDynamic
                    ? origin : clipModelSpawnPos;
                const idMat3 linkAxis = clipModelDynamic
                    ? (clipModelDynamicAxis ? axis : IdentityMatrix())
                    : clipModelSpawnAxis;
                presentableServices->LinkClipModel(clipModel, entityNumber,
                    clipModelPhysID, linkOrigin, linkAxis);
            }
        }
    }

    if (hideDuringFirstSSInterval && serializer.IsReading()) {
        if (serializeCount == 1) {
            if (hidden) {
                hideDuringFirstSSInterval = false;
            } else {
                Hide(true);
                hideDuringFirstSSInterval = true;
            }
        } else if (serializeCount == 2) {
            Show();
        }
    }
    SerializeFX(serializer);
}

void idPresentable::SetGroupMaster(idPresentable* presentable) {
    groupMaster = presentable;
    groupMasterSpawnId = presentable != nullptr ? presentable->spawnId : 0;
    UpdateModelGroupMaster();
}
