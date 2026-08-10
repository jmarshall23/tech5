#pragma once

#include "idlib/math/vector.h"

class idAI2;
class idCachedJoint;
class idDeclAnimWebNode;
class idMD6Anim;

struct eventVoid {};

enum aiAnimDCIdealDir_t : int {
    IDEALDIR_NONE = 0,
    IDEALDIR_BODYORIENTATION = 1,
    IDEALDIR_MOVEORIENTATION = 2,
    IDEALDIR_GOALORIENTATION = 3,
    IDEALDIR_TONEXTPOINT = 4,
    IDEALDIR_TOGOALPOINT = 5,
    IDEALDIR_TOENEMY = 6,
    IDEALDIR_CURRENT_ANIMNODE = 7,
    IDEALDIR_CURRENT_REF_AXIS = 8,
    IDEALDIR_TO_PREVIOUS_ENEMY = 9,
    IDEALDIR_TO_SECONDARY_ENEMY = 10,
    IDEALDIR_DEPARTURE_PATH_DIRECTION = 11,
    IDEALDIR_NOOP = 12
};

enum aiAnimDCIdealPoint_t : int {
    IDEALPOINT_NONE = 0,
    IDEALPOINT_GOALPOINT = 1,
    IDEALPOINT_NEXTPOINT = 2,
    IDEALPOINT_CURRENT_ANIMNODE = 3,
    IDEALPOINT_CURRENT_REF_PT = 4,
    IDEALPOINT_ENEMYORIGIN = 5,
    IDEALPOINT_NEXTGROUNDPOINT = 6,
    IDEALPOINT_FLIGHT_ANIM = 7,
    IDEALPOINT_PATH_POINT = 8,
    IDEALPOINT_TRAVERSAL_ENDPOINT = 9,
    IDEALPOINT_NOOP = 10
};

enum animEventBool_t : int {
    B_FALSE = 0,
    B_TRUE = 1
};

enum aiAnimDCFlags_t : int {
    DC_FLAGS_NONE = 0,
    DC_ROTATION_IGNORES_REMAINING_FRAMES = 0x1,
    DC_NO_REVERSE_ROTATION = 0x2,
    DC_NO_RESTRICT_ROTATION_DIRECTION_YAW = 0x4,
    DC_RESTRICT_ROTATION_DIRECTION_PITCH = 0x8,
    DC_RESTRICT_ROTATION_DIRECTION_ROLL = 0x10,
    DC_TRANSLATION_IGNORES_REMAINING_FRAMES = 0x20,
    DC_LERP_ONLY_MODEL_SPACE_X = 0x40,
    DC_LERP_ONLY_MODEL_SPACE_Y = 0x80,
    DC_LERP_ONLY_MODEL_SPACE_Z = 0x100,
    DC_CORRECT_TRANSLATED_ROTATION = 0x200,
    DC_NO_DELTA_REBUILD = 0x400
};

struct animDeltaCorrectionInput_t {
    float translationCorrectionMaxScale = 0.0f;
    idVec3 translationCorrectionPerFrameMax = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 translationPerFrameMax = idVec3(0.0f, 0.0f, 0.0f);
    float rotationMaxScale = 0.0f;
    float rotationMinScale = 0.0f;
    float rotationRateMax = 0.0f;
    bool lerpOnlyModelSpaceY = false;
    bool lerpOnlyModelSpaceX = false;
    bool rotationIgnoresRemainingFrames = false;
    bool noReverseRotation = false;
    bool restrictRotationDirectionRoll = false;
    bool restrictRotationDirectionPitch = false;
    bool restrictRotationDirectionYaw = false;
    bool translationIgnoresRemainingFrames = false;
    bool noDeltaRebuild = false;
    bool correctTranslatedRotation = false;
    bool allowRollCorrection = false;
    bool allowPitchCorrection = false;
    bool allowYawCorrection = true;
    bool lerpOnlyModelSpaceZ = false;
};

struct animDeltaCorrection_t {
    idVec3 endPoint = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 endDir = idVec3(1.0f, 0.0f, 0.0f);
    idVec3 animEndTranslation = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 animEndRotation = idMat3(1.0f);
    bool correctTranslation = false;
    bool correctRotation = false;
    idMat3 uncorrectedAxis = idMat3(1.0f);
    bool useUncorrectedAxis = false;
    idVec3 startOrigin = idVec3(0.0f, 0.0f, 0.0f);
    aiAnimDCIdealPoint_t idealPoint = IDEALPOINT_NONE;
    aiAnimDCIdealPoint_t idealPointOverride = IDEALPOINT_NONE;
    idVec3 animSpaceEndTranslation = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 animSpaceGoalTranslation = idVec3(0.0f, 0.0f, 0.0f);
    int translationEndTime = 0;
    aiAnimDCIdealDir_t idealDir = IDEALDIR_NONE;
    aiAnimDCIdealDir_t idealDirOverride = IDEALDIR_NONE;
    idMat3 animSpaceEndRotation = idMat3(1.0f);
    idMat3 animSpaceGoalRotation = idMat3(1.0f);
    idVec3 animSpaceEndRotationTranslation = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 animSpaceGoalRotationTranslation = idVec3(0.0f, 0.0f, 0.0f);
    int rotationEndTime = 0;
    int rotationGoalTime = 0;
    idVec3 currentAnimnodeOrigin = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 currentAnimnodeAxis = idMat3(1.0f);
    idVec3 currentRefOrigin = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 currentRefAxis = idMat3(1.0f);
    bool animHasRemainingDelta = false;
    bool useDeltaCorrection = false;
    bool rotationGoalPriorToEnd = false;
    bool translationGoalPriorToEnd = false;
    const idMD6Anim* anim = nullptr;
    const idDeclAnimWebNode* node = nullptr;
    float previousRemainingTranslationFrames = 0.0f;
    float previousRemainingRotationFrames = 0.0f;
    float previousRemainingRotationFramesToGoal = 0.0f;
    idMat3 animSpacePreTranslationCorrection = idMat3(1.0f);
    bool skipFirstFrame = false;
    animDeltaCorrectionInput_t in;
};

struct idAnimDeltaTransform {
    idVec3 translation = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 rotation = idMat3(1.0f);
};

struct idAnimDeltaEventMarker {
    bool present = false;
    int frame = -1;
    const idCachedJoint* translationJoint = nullptr;
    const idCachedJoint* rotationJoint = nullptr;
};

struct idAnimDeltaEventContext {
    int currentFrame = 0;
    const idDeclAnimWebNode* node = nullptr;
    idAnimDeltaEventMarker end;
    idAnimDeltaEventMarker goal;
};

struct idAnimDeltaMoveRuntime {
    bool physicsIsAI = false;
    idVec3 origin = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 animatorAxis = idMat3(1.0f);
    idVec3 animatorScale = idVec3(1.0f, 1.0f, 1.0f);
    idVec3 lastOriginDelta = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 lastOriginRotation = idMat3(1.0f);
    idVec3 lastOriginTranslation = idVec3(0.0f, 0.0f, 0.0f);
    bool blending = false;
    int originBlendOperation = 0;
    int gameTime = 0;
    int frameMilliseconds = 1;
    int lastBlendTime = 0;
    bool userChannelUsesGravity = true;
    bool hasBindMaster = false;
    bool animationPaused = false;
};

class idAnimBaseFSM {
public:
    struct deltaCorrectionGoalRotationParms_t {
        idVec3 sourcePosition = idVec3(0.0f, 0.0f, 0.0f);
        idMat3 sourceAxis = idMat3(1.0f);
        idVec3 worldSpaceAnimGoalOrigin = idVec3(0.0f, 0.0f, 0.0f);
        idMat3 worldSpaceAnimGoalAxis = idMat3(1.0f);
        bool debug = false;
    };

    idAnimBaseFSM();

    float GetRemainingFramesToTime(int time) const;
    void ResetAnimDeltaCorrection();
    void BeginAnimDeltaCorrectionRotation(const idMD6Anim* anim,
        const idDeclAnimWebNode* node, aiAnimDCIdealDir_t idealDir,
        int startFrame, int endFrame, int goalFrame,
        const idCachedJoint* endJoint, const idCachedJoint* goalJoint);
    idVec3 GetDeltaCorrectionGoalOrigin() const;
    idMat3 GetDeltaCorrectionGoalRotation(
        const deltaCorrectionGoalRotationParms_t* parms = nullptr) const;
    void CheckResetAnimDeltaCorrection(const idDeclAnimWebNode* node);
    void BeginAnimDeltaCorrectionTranslation(const idMD6Anim* anim,
        const idDeclAnimWebNode* node, aiAnimDCIdealPoint_t idealPoint,
        int startFrame, int endFrame, int goalFrame,
        const idCachedJoint* endJoint, const idCachedJoint* goalJoint,
        bool correctGravity);
    bool CheckDeltaCorrectionAbortConditions() const;
    void MoveAIDeltaCorrection();

    idAI2* ai;
    unsigned int currentStateFlags;
    animDeltaCorrection_t animDeltaCorrection;
    idVec3 navNextPos;
    idVec3 nextArrivalPos;
    idMat3 nextArrivalAxis;
    idVec3 intermediateMoveDestination;
    idVec3 traversalEndpoint;
    idVec3 firstCachedCorner;
    int cachedCornerCount;
    idVec3 orientMoveIdealDir;
    idMat3 orientMoveAxis;
    idVec3 orientBodyIdealDir;
    idMat3 orientBodyAxis;
    bool moveOrientationOnPath;
    int animDeltaMode;
};

class idAI2 {
public:
    eventVoid AnimEvent_AnimDeltaCorrectionSetFlags(
        const idMD6Anim* anim, aiAnimDCFlags_t flags);
    eventVoid AnimEvent_AnimDeltaCorrectionRotationRate(
        const idMD6Anim* anim, float rotationRateMax,
        float rotationMinScale, float rotationMaxScale);
    void HandleAnimDeltaCorrection(const idMD6Anim* anim,
        aiAnimDCIdealPoint_t idealPoint, aiAnimDCIdealDir_t idealDir,
        animEventBool_t correctGravity, int thisEventNumber);
    eventVoid AnimEvent_AnimDeltaCorrection(const idMD6Anim* anim,
        aiAnimDCIdealPoint_t idealPoint, aiAnimDCIdealDir_t idealDir,
        animEventBool_t correctGravity);
    eventVoid AnimEvent_AnimDeltaCorrection_Turn(const idMD6Anim* anim);
    eventVoid AnimEvent_AnimDeltaCorrection_Land(const idMD6Anim* anim);
};

bool SameSignRelaxed(float x, float y, float tolerance);

idAnimBaseFSM& Tungsten_GetAnimDeltaFSM(idAI2& ai);
bool Tungsten_IsAnimDeltaCorrectionEnabled();
bool Tungsten_IsAnimDeltaServer();
int Tungsten_GetAnimDeltaEventNumber(int eventKind);
bool Tungsten_GetAnimDeltaEventContext(idAI2& ai, const idMD6Anim& anim,
    int thisEventNumber, idAnimDeltaEventContext& context);
void Tungsten_AnimDeltaWarning(const char* format, ...);

bool Tungsten_GetAnimDeltaTransform(const idMD6Anim& anim,
    bool endTransform, idAnimDeltaTransform& transform, int& numFrames);
bool Tungsten_GetCachedJointAnimDeltaTransform(
    const idCachedJoint& joint, idAnimDeltaTransform& transform);
bool Tungsten_GetAnimDeltaTiming(const idAnimBaseFSM& fsm,
    const idMD6Anim& anim, int& currentFrameTime,
    int& frameRate, int& millisecondsPerRealSecond);
bool Tungsten_GetAnimDeltaAnimatorPose(const idAnimBaseFSM& fsm,
    idVec3& origin, idMat3& axis);
bool Tungsten_GetAnimDeltaAIOrigin(const idAnimBaseFSM& fsm,
    idVec3& origin);
bool Tungsten_GetAnimDeltaEnemyOrigin(const idAnimBaseFSM& fsm,
    idVec3& origin);
bool Tungsten_GetAnimDeltaPathDirection(const idAnimBaseFSM& fsm,
    const idVec3& start, const idVec3& testPoint,
    idVec3& closestPoint, idVec3& direction);
bool Tungsten_TraceAnimDeltaGround(const idAnimBaseFSM& fsm,
    const idVec3& start, const idVec3& end, idVec3& hitPoint);
bool Tungsten_GetAnimDeltaAnimationTranslation(const idMD6Anim& anim,
    idVec3& translation);
bool Tungsten_HasAnimDeltaGoalChanged(const idAnimBaseFSM& fsm,
    const idVec3& newGoal, float cutoff);
bool Tungsten_GetAnimDeltaLandOrigin(idAI2& ai,
    const idMD6Anim& anim, idVec3& origin);
void Tungsten_SetAnimDeltaCorrectGravity(idAnimBaseFSM& fsm,
    bool correctGravity);

bool Tungsten_GetAnimDeltaMoveRuntime(const idAnimBaseFSM& fsm,
    idAnimDeltaMoveRuntime& runtime);
void Tungsten_SetAnimDeltaNullDestination(idAnimBaseFSM& fsm);
void Tungsten_SetAnimDeltaRemoveOriginRotation(idAnimBaseFSM& fsm,
    bool removeRotation);
void Tungsten_ForceAnimDeltaOriginBlendRight(idAnimBaseFSM& fsm);
bool Tungsten_ProbeAnimDeltaMovement(idAnimBaseFSM& fsm,
    const idVec3& start, const idVec3& end, idVec3& result);
void Tungsten_SetAnimDeltaPhysics(idAnimBaseFSM& fsm,
    const idVec3& delta, int frameMilliseconds, bool applyGravity);
bool Tungsten_RespondsToAnimDeltaDepartureReturn(idAnimBaseFSM& fsm);
void Tungsten_SendAnimDeltaDepartureReturn(idAnimBaseFSM& fsm);
void Tungsten_UpdateAnimDeltaBodyOrientation(idAnimBaseFSM& fsm,
    const idMat3& axis, float turnRate, int updateIdeal,
    bool animationDeltaMode);
void Tungsten_SetAnimDeltaMoveIdealDirection(idAnimBaseFSM& fsm,
    const idVec3& direction);
