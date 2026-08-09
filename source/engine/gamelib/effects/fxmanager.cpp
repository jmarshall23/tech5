#include "gamelib/effects/fxmanager.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

int GameLib_GetFXDeclActionCount(const idDeclFX* decl);
int GameLib_GetFXDeclChangeId(const idDeclFX* decl);
const char* GameLib_GetFXDeclName(const idDeclFX* decl);
bool GameLib_GetFXActionParameters(const idDeclFX* decl, int actionIndex,
    idFXActionParameters& parameters);
void GameLib_CreateFXActionResource(idGameLibEffects* effects,
    idRenderWorld* renderWorld, const idFXActionParameters& parameters,
    idFXAction& action);
void GameLib_StartFXActionResource(idGameLibEffects* effects,
    const idFXActionParameters& parameters, idFXAction& action,
    const idVec3& origin, const idMat3& axis, int time);
void GameLib_UpdateFXActionResource(idGameLibEffects* effects,
    const idFXActionParameters& parameters, idFXAction& action,
    const idVec3& origin, const idMat3& axis, const idVec3& velocity,
    const idVec4& color, int time, int frameNumber, float fovScale,
    float depthHack);
void GameLib_StopFXActionResource(idGameLibEffects* effects,
    const idFXActionParameters& parameters, idFXAction& action,
    int time, bool immediate, bool recycleResources);
void GameLib_FreeFXActionResource(idGameLibEffects* effects,
    const idFXActionParameters& parameters, idFXAction& action);
void GameLib_EnumerateFXActionTags(idTreeAnimator* animator,
    const idDeclFX* decl, int actionIndex, idList<tagData_t, 109>& tags);
bool GameLib_GetFXTagVelocity(idTreeAnimator* animator, const tagData_t& tag,
    int gameMsPerFrame, idVec3& velocity);
idVec4 GameLib_GetFXRenderParm(const idDeclRenderParm* parameter);
idVec4 GameLib_GetFXTableColor(const idFXSingleAction& action,
    float fraction);
idList<idViewCallbacks*, 109>* GameLib_GetFXViewCallbacks();
int GameLib_StartFXSound(idSoundEmitter* emitter, soundChannel_t channel,
    const idSoundShader* shader);
void GameLib_SerializeFXManager(idSerializer& serializer,
    idFXManager& manager);

idRenderModelParticle* GameLib_AllocParticleFxModel(idRenderWorld* renderWorld,
    const idDeclParticle* particleDecl);
void GameLib_FreeParticleFxModel(idRenderModelParticle* model);
idRenderModel* GameLib_AllocStaticFxModel(idRenderWorld* renderWorld,
    const char* modelName);
void GameLib_FreeStaticFxModel(idRenderModel* model);

namespace {

int PointerKey(const void* pointer) {
    return static_cast<int>(reinterpret_cast<std::uintptr_t>(pointer) >> 4);
}

float RandomRange(idRandom2& random, const idVec2& range) {
    return range.x + (range.y - range.x) * random.RandomFloat();
}

float Clamp01(const float value) {
    return (std::max)(0.0f, (std::min)(1.0f, value));
}

void ResetState(fxActionState_t& state) {
    state.startDelay = 0;
    state.startTime = -1;
    state.stopTime = 0;
    state.hidden = false;
    state.started = false;
    state.shouldTrigger = false;
    state.forceStop = false;
    state.fadeInStartTime = -1;
    state.fadeInEndTime = 0;
    state.fadeOutStartTime = 0;
}

} // namespace

idFXModelRecycler::idFXModelRecycler()
    : fxPrtModels()
    , activePrtModelHash(256, 256)
    , inactivePrtModelHash(256, 256)
    , fxStaticModels()
    , activeStaticModelHash(64, 64)
    , inactiveStaticModelHash(64, 64) {
}

idFXModelRecycler::~idFXModelRecycler() {
    Shutdown();
}

void idFXModelRecycler::Init() {
    Shutdown();
    activePrtModelHash.Clear();
    inactivePrtModelHash.Clear();
    activeStaticModelHash.Clear();
    inactiveStaticModelHash.Clear();
}

void idFXModelRecycler::Shutdown() {
    for (int index = 0; index < fxPrtModels.Num(); ++index) {
        if (fxPrtModels[index].pmodel != nullptr) {
            GameLib_FreeParticleFxModel(fxPrtModels[index].pmodel);
        }
    }
    for (int index = 0; index < fxStaticModels.Num(); ++index) {
        if (fxStaticModels[index].rmodel != nullptr) {
            GameLib_FreeStaticFxModel(fxStaticModels[index].rmodel);
        }
    }
    fxPrtModels.Clear();
    fxStaticModels.Clear();
    activePrtModelHash.Clear();
    inactivePrtModelHash.Clear();
    activeStaticModelHash.Clear();
    inactiveStaticModelHash.Clear();
}

idRenderModelParticle* idFXModelRecycler::GetParticleFxModel(
    const idDeclParticle* const particleDecl,
    idRenderWorld* const renderWorld) {
    if (particleDecl == nullptr) {
        return nullptr;
    }
    const int key = PointerKey(particleDecl);
    for (int index = inactivePrtModelHash.First(key); index >= 0;
         index = inactivePrtModelHash.Next(index)) {
        if (index < fxPrtModels.Num() &&
            fxPrtModels[index].pDecl == particleDecl) {
            inactivePrtModelHash.Remove(key, index);
            activePrtModelHash.Add(key, index);
            return fxPrtModels[index].pmodel;
        }
    }
    if (fxPrtModels.Num() >= fxPrtModels.Max()) {
        return nullptr;
    }
    fxPrtModel_t item{};
    item.pDecl = particleDecl;
    item.pmodel = GameLib_AllocParticleFxModel(renderWorld, particleDecl);
    if (item.pmodel == nullptr) {
        return nullptr;
    }
    const int index = fxPrtModels.Append(item);
    activePrtModelHash.Add(key, index);
    return item.pmodel;
}

void idFXModelRecycler::RecycleParticleFxModel(
    const idDeclParticle* const particleDecl,
    idRenderModelParticle* const model) {
    if (particleDecl == nullptr || model == nullptr) {
        return;
    }
    const int key = PointerKey(particleDecl);
    for (int index = activePrtModelHash.First(key); index >= 0;
         index = activePrtModelHash.Next(index)) {
        if (index < fxPrtModels.Num() &&
            fxPrtModels[index].pmodel == model) {
            activePrtModelHash.Remove(key, index);
            inactivePrtModelHash.Add(key, index);
            return;
        }
    }
}

idRenderModel* idFXModelRecycler::GetStaticFxModel(
    const idAtomicString& modelName, idRenderWorld* const renderWorld) {
    if (modelName.IsEmpty()) {
        return nullptr;
    }
    const int key = inactiveStaticModelHash.GenerateKeyForString(
        modelName.c_str(), false);
    for (int index = inactiveStaticModelHash.First(key); index >= 0;
         index = inactiveStaticModelHash.Next(index)) {
        if (index < fxStaticModels.Num() &&
            fxStaticModels[index].modelName == modelName) {
            inactiveStaticModelHash.Remove(key, index);
            activeStaticModelHash.Add(key, index);
            return fxStaticModels[index].rmodel;
        }
    }
    if (fxStaticModels.Num() >= fxStaticModels.Max()) {
        return nullptr;
    }
    fxStaticModel_t item{};
    item.modelName = modelName;
    item.rmodel = GameLib_AllocStaticFxModel(renderWorld, modelName.c_str());
    if (item.rmodel == nullptr) {
        return nullptr;
    }
    const int index = fxStaticModels.Append(item);
    activeStaticModelHash.Add(key, index);
    return item.rmodel;
}

void idFXModelRecycler::RecycleStaticFxModel(
    const idAtomicString& modelName, idRenderModel* const model) {
    if (modelName.IsEmpty() || model == nullptr) {
        return;
    }
    const int key = activeStaticModelHash.GenerateKeyForString(
        modelName.c_str(), false);
    for (int index = activeStaticModelHash.First(key); index >= 0;
         index = activeStaticModelHash.Next(index)) {
        if (index < fxStaticModels.Num() &&
            fxStaticModels[index].rmodel == model) {
            activeStaticModelHash.Remove(key, index);
            inactiveStaticModelHash.Add(key, index);
            return;
        }
    }
}

idFXAction::idFXAction()
    : tagIndex(0)
    , startOrg()
    , startAxis(1.0f)
    , rLight(nullptr)
    , rModel(nullptr)
    , rParticle(nullptr)
    , screenPrtHandle(-1)
    , flareManager()
    , ribbonManager()
    , tagData(4)
    , lastParticleDropPos()
    , renderParmStartValue(0.0f, 0.0f, 0.0f, 0.0f)
    , randomAngles(0.0f, 0.0f, 0.0f)
    , viewCallbacksID(-1) {
    startOrg.Zero();
    lastParticleDropPos.Zero();
}

idFXManager::idFXManager()
    : initialized(false)
    , fxDecl(nullptr)
    , gameLibEffects(nullptr)
    , ta(nullptr)
    , rw(nullptr)
    , systemColor(1.0f, 1.0f, 1.0f, 1.0f)
    , random(0)
    , soundInfo{nullptr, SND_CHANNEL_ANY}
    , actions(4)
    , actionState(4)
    , remote(false)
    , allowSurfaceOnlyInViewID(0)
    , suppressSurfaceInViewID(0)
    , viewCallbacksID(-1)
    , declChangeId(-1)
    , externalRotation(1.0f)
    , externalPosition()
    , hasExternalPositionAndRotation(false)
    , actionBuffer{}
    , actionBufferPos(0)
    , serializeActionCount(0) {
    externalPosition.Zero();
}

idFXManager::~idFXManager() {
    Shutdown();
}

idVec4 idFXManager::GetVector(const idDeclRenderParm* const parameter) const {
    return parameter != nullptr ? GameLib_GetFXRenderParm(parameter)
        : idVec4(0.0f, 0.0f, 0.0f, 0.0f);
}

idVec4 idFXManager::GetTableColor(const idFXSingleAction& action,
    const float fraction) const {
    return GameLib_GetFXTableColor(action, fraction);
}

bool idFXManager::GetWorldSpaceTagVelocity(const tagData_t& tag,
    const int gameMsPerFrame, idVec3& velocity) {
    velocity.Zero();
    return ta != nullptr && gameMsPerFrame > 0 &&
        GameLib_GetFXTagVelocity(ta, tag, gameMsPerFrame, velocity);
}

int idFXManager::StartSound(const soundChannel_t channel,
    const idSoundShader* const shader) {
    if (soundInfo.emitter == nullptr || shader == nullptr) {
        return 0;
    }
    const soundChannel_t resolved = channel == SND_CHANNEL_ANY
        ? soundInfo.channel : channel;
    return GameLib_StartFXSound(soundInfo.emitter, resolved, shader);
}

idList<idViewCallbacks*, 109>& idFXManager::GetViewCallbacks() {
    idList<idViewCallbacks*, 109>* callbacks = GameLib_GetFXViewCallbacks();
    if (callbacks != nullptr) {
        return *callbacks;
    }
    static idList<idViewCallbacks*, 109> empty;
    return empty;
}

const char* idFXManager::GetName() const {
    return fxDecl != nullptr ? GameLib_GetFXDeclName(fxDecl) : "";
}

bool idFXManager::IsStopped(const int time) const {
    for (int index = 0; index < actionState.Num(); ++index) {
        if (time < actionState[index].stopTime) {
            return false;
        }
    }
    return true;
}

void idFXManager::Init(const idDeclFX* const declFX,
    idRenderWorld* const renderWorld,
    const fxEmitterSound_t* const emitterSound,
    idGameLibEffects* const effects, const float diversity,
    idTreeAnimator* const treeAnimator) {
    Shutdown();
    if (declFX == nullptr) {
        return;
    }
    fxDecl = declFX;
    gameLibEffects = effects;
    ta = treeAnimator;
    rw = renderWorld;
    random.SetSeed(static_cast<unsigned int>(diversity * 65535.0f));
    if (emitterSound != nullptr) {
        soundInfo = *emitterSound;
    }
    const int count = (std::max)(0, GameLib_GetFXDeclActionCount(fxDecl));
    actions.SetNum(count);
    actionState.SetNum(count);
    declChangeId = GameLib_GetFXDeclChangeId(fxDecl);
    for (int index = 0; index < count; ++index) {
        CreateAction(index, rw);
    }
    EnumerateTags();
    initialized = true;
}

void idFXManager::CreateAction(const int index,
    idRenderWorld* const renderWorld) {
    if (index < 0 || index >= actions.Num()) {
        return;
    }
    ResetState(actionState[index]);
    idFXActionParameters parameters{};
    if (GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
        GameLib_CreateFXActionResource(gameLibEffects, renderWorld,
            parameters, actions[index]);
    }
}

void idFXManager::EnumerateTags() {
    if (ta == nullptr) {
        return;
    }
    for (int index = 0; index < actions.Num(); ++index) {
        actions[index].tagData.Clear();
        GameLib_EnumerateFXActionTags(ta, fxDecl, index,
            actions[index].tagData);
    }
}

void idFXManager::StartAction(const int index, const idVec3& origin,
    const idMat3& axis, const int time, const int explicitTagIndex) {
    if (index < 0 || index >= actions.Num()) {
        return;
    }
    idFXActionParameters parameters{};
    if (!GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
        return;
    }
    idFXAction& action = actions[index];
    fxActionState_t& state = actionState[index];
    action.startOrg = origin;
    action.startAxis = axis;
    action.tagIndex = explicitTagIndex >= 0 ? explicitTagIndex : 0;
    if (explicitTagIndex < 0 && action.tagData.Num() > 1) {
        action.tagIndex = random.RandomInt(action.tagData.Num());
    }
    action.randomAngles = idAngles(
        RandomRange(random, parameters.randomRotationX),
        RandomRange(random, parameters.randomRotationY),
        RandomRange(random, parameters.randomRotationZ));
    state.startDelay = static_cast<int>(RandomRange(random,
        parameters.delay) * 1000.0f);
    state.startTime = time;
    state.stopTime = time + state.startDelay +
        static_cast<int>(parameters.duration * 1000.0f);
    state.fadeInStartTime = time + state.startDelay;
    state.fadeInEndTime = state.fadeInStartTime +
        static_cast<int>(parameters.fadeInTime * 1000.0f);
    state.fadeOutStartTime = state.stopTime -
        static_cast<int>(parameters.fadeOutTime * 1000.0f);
    state.hidden = false;
    state.started = false;
    state.shouldTrigger = true;
    state.forceStop = false;
}

int idFXManager::StartActions(const idVec3& origin, const idMat3& axis,
    const int time, const fxCondition_t startCondition,
    const fxExtraCondition_t extraCondition, const int explicitTagIndex) {
    int startedCount = 0;
    for (int index = 0; index < actions.Num(); ++index) {
        idFXActionParameters parameters{};
        if (!GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
            continue;
        }
        if (parameters.startCondition != startCondition) {
            continue;
        }
        if (parameters.extraCondition != FX_EXTRA_COND_NONE &&
            (static_cast<int>(parameters.extraCondition) &
             static_cast<int>(extraCondition)) == 0) {
            continue;
        }
        StartAction(index, origin, axis, time, explicitTagIndex);
        ++startedCount;
    }
    return startedCount;
}

int idFXManager::InternalStartFX(const fxActionCall_t& actionCall) {
    if (!initialized) {
        return 0;
    }
    const int result = StartActions(actionCall.org, actionCall.axis,
        actionCall.time, actionCall.condition, actionCall.extraCondition,
        actionCall.tagIdx);
    ++actionBufferPos;
    return result;
}

int idFXManager::StartFX(const idVec3& origin, const idMat3& axis,
    const int time, const fxCondition_t startCondition,
    const int explicitTagIndex, const int delay) {
    if (!initialized) {
        return 0;
    }
    fxActionCall_t& call = actionBuffer[actionBufferPos % 8];
    call.org = origin;
    call.axis = axis;
    call.condition = startCondition;
    call.time = time + delay;
    call.extraCondition = FX_EXTRA_COND_NONE;
    call.tagIdx = explicitTagIndex;
    call.actionType = FXACTION_START;
    call.immediate = false;
    call.viewCallbacksID = viewCallbacksID;
    return InternalStartFX(call);
}

int idFXManager::StartFX(const idVec3& origin, const idMat3& axis,
    const int time, const fxCondition_t startCondition,
    const fxExtraCondition_t extraCondition) {
    if (!initialized) {
        return 0;
    }
    fxActionCall_t& call = actionBuffer[actionBufferPos % 8];
    call.org = origin;
    call.axis = axis;
    call.condition = startCondition;
    call.time = time;
    call.extraCondition = extraCondition;
    call.tagIdx = -1;
    call.actionType = FXACTION_START;
    call.immediate = false;
    call.viewCallbacksID = viewCallbacksID;
    return InternalStartFX(call);
}

int idFXManager::StartFX(const idVec3& origin, const idMat3& axis,
    const int time, const fxCondition_t startCondition) {
    return StartFX(origin, axis, time, startCondition, -1, 0);
}

void idFXManager::LocalStartFX(const idVec3& origin, const idMat3& axis,
    const int time, const fxCondition_t startCondition) {
    if (initialized) {
        StartActions(origin, axis, time, startCondition,
            FX_EXTRA_COND_NONE, -1);
    }
}

void idFXManager::ApplyFade(const idFXActionParameters& parameters,
    idFXAction& action, fxActionState_t& state, const int time,
    const float fraction) {
    float fade = 1.0f;
    if (parameters.fadeInTime > 0.0f && time < state.fadeInEndTime) {
        const int duration = state.fadeInEndTime - state.fadeInStartTime;
        fade *= duration > 0 ? Clamp01(static_cast<float>(
            time - state.fadeInStartTime) / duration) : 1.0f;
    }
    if (parameters.fadeOutTime > 0.0f && time >= state.fadeOutStartTime) {
        const int duration = state.stopTime - state.fadeOutStartTime;
        fade *= duration > 0 ? Clamp01(static_cast<float>(
            state.stopTime - time) / duration) : 0.0f;
    }
    action.renderParmStartValue = idVec4(
        systemColor.x * fade, systemColor.y * fade,
        systemColor.z * fade, systemColor.w * fade * Clamp01(fraction));
}

void idFXManager::RestartAction(const int index, const int time) {
    if (index < 0 || index >= actions.Num()) {
        return;
    }
    const idVec3 origin = actions[index].startOrg;
    const idMat3 axis = actions[index].startAxis;
    StopAction(index, time, true, false);
    StartAction(index, origin, axis, time, actions[index].tagIndex);
}

void idFXManager::StopAction(const int index, const int time,
    const bool immediate, const bool recycleResources) {
    if (index < 0 || index >= actions.Num()) {
        return;
    }
    idFXActionParameters parameters{};
    if (!GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
        return;
    }
    fxActionState_t& state = actionState[index];
    if (state.startTime < 0) {
        return;
    }
    if (!immediate && !state.forceStop && parameters.fadeOutTime > 0.0f &&
        parameters.type != FX_SOUND) {
        state.fadeOutStartTime = time;
        state.stopTime = time + static_cast<int>(
            parameters.fadeOutTime * 1000.0f);
        state.forceStop = true;
        return;
    }
    if (parameters.type == FX_FLARE) {
        actions[index].flareManager.StopFlare();
    } else if (parameters.type == FX_RIBBON) {
        actions[index].ribbonManager.StopRibbon();
    }
    GameLib_StopFXActionResource(gameLibEffects, parameters, actions[index],
        time, immediate, recycleResources);
    const bool keepHidden = parameters.triggered;
    ResetState(state);
    state.hidden = keepHidden;
    actions[index].lastParticleDropPos.Zero();
    actions[index].randomAngles = idAngles(0.0f, 0.0f, 0.0f);
    actions[index].startAxis = idMat3(1.0f);
    actions[index].startOrg.Zero();
}

void idFXManager::StopActions(const int time,
    const fxCondition_t stopCondition,
    const fxExtraCondition_t extraCondition, const bool stopAll,
    const bool immediate) {
    for (int index = 0; index < actions.Num(); ++index) {
        idFXActionParameters parameters{};
        if (!GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
            continue;
        }
        if (!stopAll && parameters.stopCondition != stopCondition) {
            continue;
        }
        if (!stopAll && parameters.extraCondition != FX_EXTRA_COND_NONE &&
            (static_cast<int>(parameters.extraCondition) &
             static_cast<int>(extraCondition)) == 0) {
            continue;
        }
        StopAction(index, time, immediate, true);
    }
}

void idFXManager::InternalStopFX(const fxActionCall_t& actionCall) {
    if (!initialized) {
        return;
    }
    StopActions(actionCall.time, actionCall.condition,
        actionCall.extraCondition,
        actionCall.actionType == FXACTION_STOP_ALL, actionCall.immediate);
    ++actionBufferPos;
}

void idFXManager::StopFX(const int time,
    const fxCondition_t stopCondition, const bool immediate) {
    StopFX(time, stopCondition, FX_EXTRA_COND_NONE, immediate);
}

void idFXManager::StopFX(const int time,
    const fxCondition_t stopCondition,
    const fxExtraCondition_t extraCondition, const bool immediate) {
    if (!initialized) {
        return;
    }
    fxActionCall_t& call = actionBuffer[actionBufferPos % 8];
    call.condition = stopCondition;
    call.time = time;
    call.extraCondition = extraCondition;
    call.actionType = FXACTION_STOP;
    call.immediate = immediate;
    call.viewCallbacksID = viewCallbacksID;
    InternalStopFX(call);
}

void idFXManager::LocalStopFX(const int time,
    const fxCondition_t stopCondition, const bool immediate) {
    if (initialized) {
        StopActions(time, stopCondition, FX_EXTRA_COND_NONE, false,
            immediate);
    }
}

void idFXManager::StopAllFX(const int time, const bool immediate) {
    if (!initialized) {
        return;
    }
    fxActionCall_t& call = actionBuffer[actionBufferPos % 8];
    call.condition = FX_NONE;
    call.time = time;
    call.extraCondition = FX_EXTRA_COND_NONE;
    call.actionType = FXACTION_STOP_ALL;
    call.immediate = immediate;
    call.viewCallbacksID = viewCallbacksID;
    InternalStopFX(call);
}

void idFXManager::LocalStopAllFX(const int time, const bool immediate) {
    if (initialized) {
        StopActions(time, FX_NONE, FX_EXTRA_COND_NONE, true, immediate);
    }
}

void idFXManager::UpdateActions(const idVec3& origin, const idMat3& axis,
    const idVec3& velocity, const int time, const int gameMsPerFrame,
    const int frameNumber, const float fovScale, const float depthHack) {
    (void)gameMsPerFrame;
    for (int index = 0; index < actions.Num(); ++index) {
        idFXActionParameters parameters{};
        if (!GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
            continue;
        }
        fxActionState_t& state = actionState[index];
        idFXAction& action = actions[index];
        if (state.startTime < 0 || state.hidden) {
            continue;
        }
        const int actualStart = state.startTime + state.startDelay;
        if (time < actualStart) {
            continue;
        }
        if (!state.started) {
            GameLib_StartFXActionResource(gameLibEffects, parameters, action,
                action.startOrg, action.startAxis, actualStart);
            if (parameters.type == FX_SOUND) {
                StartSound(parameters.soundChannel, parameters.sound);
            }
            state.started = true;
        }
        if (time >= state.stopTime) {
            if (parameters.looping && !state.forceStop) {
                RestartAction(index, time + static_cast<int>(
                    parameters.restart * 1000.0f));
            } else {
                StopAction(index, time, true, true);
            }
            continue;
        }
        const int duration = (std::max)(1, state.stopTime - actualStart);
        const float fraction = Clamp01(static_cast<float>(time - actualStart) /
            static_cast<float>(duration));
        ApplyFade(parameters, action, state, time, fraction);
        const idVec3 updateOrigin = parameters.trackOrigin ? origin
            : action.startOrg;
        const idMat3 updateAxis = parameters.trackOrigin ? axis
            : action.startAxis;
        GameLib_UpdateFXActionResource(gameLibEffects, parameters, action,
            updateOrigin, updateAxis, velocity, action.renderParmStartValue,
            time, frameNumber, fovScale, depthHack);
    }
}

void idFXManager::Update(const idVec3& parentOrigin,
    const idMat3& parentAxis, const idVec3& parentVelocity, const int time,
    const int gameMsPerFrame, const int frameNumber, const float fovScale,
    const float depthHack) {
    if (!initialized) {
        return;
    }
    while (serializeActionCount > 0) {
        --serializeActionCount;
        fxActionCall_t& call = actionBuffer[actionBufferPos % 8];
        call.time = time;
        viewCallbacksID = call.viewCallbacksID;
        if (call.actionType == FXACTION_START) {
            InternalStartFX(call);
        } else {
            InternalStopFX(call);
        }
    }
    UpdateActions(parentOrigin, parentAxis, parentVelocity, time,
        gameMsPerFrame, frameNumber, fovScale, depthHack);
}

void idFXManager::ResetTreeAnimator(idTreeAnimator* const treeAnimator) {
    ta = treeAnimator;
    EnumerateTags();
}

void idFXManager::Serialize(idSerializer& serializer) {
    GameLib_SerializeFXManager(serializer, *this);
}

void idFXManager::FreeActions() {
    for (int index = 0; index < actions.Num(); ++index) {
        idFXActionParameters parameters{};
        if (GameLib_GetFXActionParameters(fxDecl, index, parameters)) {
            GameLib_FreeFXActionResource(gameLibEffects, parameters,
                actions[index]);
        }
        actions[index].tagData.Clear();
    }
    actions.Clear();
    actionState.Clear();
}

void idFXManager::Shutdown() {
    if (fxDecl != nullptr) {
        StopActions(0, FX_NONE, FX_EXTRA_COND_NONE, true, true);
        FreeActions();
    }
    initialized = false;
    fxDecl = nullptr;
    gameLibEffects = nullptr;
    ta = nullptr;
    rw = nullptr;
    soundInfo.emitter = nullptr;
    soundInfo.channel = SND_CHANNEL_ANY;
    declChangeId = -1;
    actionBufferPos = 0;
    serializeActionCount = 0;
}
