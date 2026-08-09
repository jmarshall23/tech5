#pragma once

#include "decls/declfxtypes.h"
#include "gamelib/effects/lensflaremanager.h"
#include "gamelib/effects/ribbonmanager.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/random.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>

class idDeclFX;
class idDeclParticle;
class idDeclRenderParm;
class idDeclTable;
class idFXSingleAction;
class idGameLibEffects;
class idMaterial;
class idRenderLight;
class idRenderModel;
class idRenderModelParticle;
class idRenderWorld;
class idSerializer;
class idSoundEmitter;
class idSoundShader;
class idTreeAnimator;
class idViewCallbacks;

struct tagData_t {
    idVec3 trans;
    idQuat rot;
    std::uint16_t parentJoint;
};

struct fxEmitterSound_t {
    idSoundEmitter* emitter;
    soundChannel_t channel;
};

// Stable PC-side view of the fields the recovered state machine reads from
// each idFXSingleAction.  The declaration system fills this view.
struct idFXActionParameters {
    fxActionType_t type;
    fxCondition_t startCondition;
    fxCondition_t stopCondition;
    fxExtraCondition_t extraCondition;
    idVec2 delay;
    float duration;
    float fadeInTime;
    float fadeOutTime;
    float restart;
    bool looping;
    bool triggered;
    bool trackOrigin;
    bool bindOrigin;
    bool bindAxis;
    idVec2 randomRotationX;
    idVec2 randomRotationY;
    idVec2 randomRotationZ;
    const idDeclParticle* particleDecl;
    idAtomicString modelName;
    const idSoundShader* sound;
    soundChannel_t soundChannel;
};

class idFXModelRecycler {
public:
    struct fxPrtModel_t {
        idRenderModelParticle* pmodel;
        const idDeclParticle* pDecl;
    };
    struct fxStaticModel_t {
        idRenderModel* rmodel;
        idAtomicString modelName;
    };

    idFXModelRecycler();
    ~idFXModelRecycler();
    void Init();
    void Shutdown();
    idRenderModelParticle* GetParticleFxModel(
        const idDeclParticle* particleDecl, idRenderWorld* renderWorld);
    void RecycleParticleFxModel(const idDeclParticle* particleDecl,
        idRenderModelParticle* model);
    idRenderModel* GetStaticFxModel(const idAtomicString& modelName,
        idRenderWorld* renderWorld);
    void RecycleStaticFxModel(const idAtomicString& modelName,
        idRenderModel* model);

    idStaticList<fxPrtModel_t, 256> fxPrtModels;
    idHashIndex activePrtModelHash;
    idHashIndex inactivePrtModelHash;
    idStaticList<fxStaticModel_t, 64> fxStaticModels;
    idHashIndex activeStaticModelHash;
    idHashIndex inactiveStaticModelHash;
};

struct idFXAction {
    idFXAction();

    int tagIndex;
    idVec3 startOrg;
    idMat3 startAxis;
    idRenderLight* rLight;
    idRenderModel* rModel;
    idRenderModelParticle* rParticle;
    int screenPrtHandle;
    idLensFlareManager flareManager;
    idRibbonManager ribbonManager;
    idList<tagData_t, 109> tagData;
    idVec3 lastParticleDropPos;
    idVec4 renderParmStartValue;
    idAngles randomAngles;
    int viewCallbacksID;
};

struct fxActionState_t {
    int startDelay;
    int startTime;
    int stopTime;
    bool hidden;
    bool started;
    bool shouldTrigger;
    bool forceStop;
    int fadeInStartTime;
    int fadeInEndTime;
    int fadeOutStartTime;
};

class idFXManager {
public:
    enum fxActionCallType_t : int {
        FXACTION_START = 0,
        FXACTION_STOP = 1,
        FXACTION_STOP_ALL = 2,
        FXACTION_MAX = 3
    };

    struct fxActionCall_t {
        idVec3 org;
        idMat3 axis;
        fxCondition_t condition;
        int time;
        fxExtraCondition_t extraCondition;
        int tagIdx;
        fxActionCallType_t actionType;
        bool immediate;
        int viewCallbacksID;
    };

    idFXManager();
    ~idFXManager();

    void Init(const idDeclFX* declFX, idRenderWorld* renderWorld,
        const fxEmitterSound_t* soundInfo, idGameLibEffects* gameLibEffects,
        float diversity, idTreeAnimator* treeAnimator);
    void Shutdown();
    void Update(const idVec3& parentOrigin, const idMat3& parentAxis,
        const idVec3& parentVelocity, int time, int gameMsPerFrame,
        int frameNumber, float fovScale, float depthHack);
    int StartFX(const idVec3& origin, const idMat3& axis, int time,
        fxCondition_t startCondition, int explicitTagIndex, int delay);
    int StartFX(const idVec3& origin, const idMat3& axis, int time,
        fxCondition_t startCondition, fxExtraCondition_t extraCondition);
    int StartFX(const idVec3& origin, const idMat3& axis, int time,
        fxCondition_t startCondition);
    void LocalStartFX(const idVec3& origin, const idMat3& axis, int time,
        fxCondition_t startCondition);
    void StopFX(int time, fxCondition_t stopCondition, bool immediate);
    void StopFX(int time, fxCondition_t stopCondition,
        fxExtraCondition_t extraCondition, bool immediate);
    void LocalStopFX(int time, fxCondition_t stopCondition, bool immediate);
    void StopAllFX(int time, bool immediate);
    void LocalStopAllFX(int time, bool immediate);
    bool IsStopped(int time) const;
    const char* GetName() const;
    void ResetTreeAnimator(idTreeAnimator* treeAnimator);
    void Serialize(idSerializer& serializer);

    bool initialized;
    const idDeclFX* fxDecl;
    idGameLibEffects* gameLibEffects;
    idTreeAnimator* ta;
    idRenderWorld* rw;
    idVec4 systemColor;
    idRandom2 random;
    fxEmitterSound_t soundInfo;
    idList<idFXAction, 109> actions;
    idList<fxActionState_t, 109> actionState;
    bool remote;
    int allowSurfaceOnlyInViewID;
    int suppressSurfaceInViewID;
    int viewCallbacksID;
    int declChangeId;
    idMat3 externalRotation;
    idVec3 externalPosition;
    bool hasExternalPositionAndRotation;
    fxActionCall_t actionBuffer[8];
    int actionBufferPos;
    int serializeActionCount;

private:
    idVec4 GetVector(const idDeclRenderParm* parameter) const;
    idVec4 GetTableColor(const idFXSingleAction& action, float fraction) const;
    bool GetWorldSpaceTagVelocity(const tagData_t& tag,
        int gameMsPerFrame, idVec3& velocity);
    int StartSound(soundChannel_t channel, const idSoundShader* shader);
    idList<idViewCallbacks*, 109>& GetViewCallbacks();
    void ApplyFade(const idFXActionParameters& parameters,
        idFXAction& action, fxActionState_t& state, int time, float fraction);
    void StopAction(int index, int time, bool immediate,
        bool recycleResources);
    void RestartAction(int index, int time);
    void StopActions(int time, fxCondition_t stopCondition,
        fxExtraCondition_t extraCondition, bool stopAll, bool immediate);
    void InternalStopFX(const fxActionCall_t& actionCall);
    void StartAction(int index, const idVec3& origin, const idMat3& axis,
        int time, int explicitTagIndex);
    void EnumerateTags();
    void UpdateActions(const idVec3& origin, const idMat3& axis,
        const idVec3& velocity, int time, int gameMsPerFrame,
        int frameNumber, float fovScale, float depthHack);
    int StartActions(const idVec3& origin, const idMat3& axis, int time,
        fxCondition_t startCondition, fxExtraCondition_t extraCondition,
        int explicitTagIndex);
    void CreateAction(int index, idRenderWorld* renderWorld);
    void FreeActions();
    int InternalStartFX(const fxActionCall_t& actionCall);
};

static_assert(sizeof(tagData_t) == 32, "Recovered tagData_t ABI changed");
static_assert(sizeof(fxEmitterSound_t) == 8,
    "Recovered FX emitter sound ABI changed");
static_assert(sizeof(fxActionState_t) == 28,
    "Recovered FX action-state ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFXAction) == 184,
    "Recovered idFXAction ABI changed");
static_assert(sizeof(idFXManager::fxActionCall_t) == 76,
    "Recovered FX action-call ABI changed");
static_assert(sizeof(idFXManager) == 768,
    "Recovered idFXManager ABI changed");
#endif
