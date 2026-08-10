#pragma once

#include "rotationtracker.h"
#include "wanderingaim.h"
#include "../entities/entityptr.h"
#include "idlib/index.h"

class idAnimatedEntity;
class idEntity;
class idWeapon;
class idAI2;
class idAnimator_TrackerBase;
enum invalidJointIndex_t : int;

enum aimPoint_t : int {
    AIMPOINT_ORIGIN = 0,
    AIMPOINT_HEAD = 1,
    AIMPOINT_TORSO = 2,
    AIMPOINT_CENTER = 3,
    AIMPOINT_LEGS = 4,
    AIMPOINT_FEET = 5,
    AIMPOINT_BEST = 6,
    AIMPOINT_EYELEVEL = 7,
    AIMPOINT_LOOKAHEAD = 8,
    AIMPOINT_MAX = 9
};

enum aiFoci_t : int {
    AIFOCI_AIM = 0,
    AIFOCI_LOOK = 1,
    AIFOCI_MAX = 2
};

enum aiFocus_t : int {
    AIFOCUS_NOTHING = 0,
    AIFOCUS_ENTITY = 1,
    AIFOCUS_CAMERA = 2,
    AIFOCUS_LAST_SEEN_POS = 3,
    AIFOCUS_POS_WHEN_LAST_SEEN = 4,
    AIFOCUS_LAST_SENSED_POS = 5,
    AIFOCUS_POS_WHEN_LAST_SENSED = 6,
    AIFOCUS_ENEMY_APPROACH_DIR = 7,
    AIFOCUS_PARTIAL_SENSE = 8,
    AIFOCUS_FRIENDLY = 9,
    AIFOCUS_FRIENDLY_FOCUS = 10,
    AIFOCUS_MOVE_DEST = 11,
    AIFOCUS_LOOK_AROUND = 12,
    AIFOCUS_SUPPRESSION_FIRE_POINT = 13,
    AIFOCUS_MISC = 14
};

class idDeclMD6 {
public:
    struct idHeadTrackGroup {
        const char* name;
        idIndex<short, invalidJointIndex_t> focusJointIndex;
        idIndex<short, invalidJointIndex_t> orientationJointIndex;
        int blendTime;
    };
};

struct idFocusAnimatorState {
    float alpha;
    bool blendingIn;
    bool blendingOut;
    bool contributing;
};

struct idFocusUpdateRuntime {
    idAI2* aiOwner;
    bool skipForDeathGore;
    int aimTrackingIndexOverride;
    int lookTrackingIndexOverride;
    bool wanderingAimEnabled;
    bool accuracyPerfect;
    bool showWanderingAim;
    int frameMilliseconds;
    int aimTrackerDebugLevel;
    int lookTrackerDebugLevel;
    int globalDebugLevel;
    int aimDebugLevel;
    int lookDebugLevel;
    int trackingDebugLevel;

    idFocusUpdateRuntime()
        : aiOwner(nullptr), skipForDeathGore(false),
          aimTrackingIndexOverride(-1), lookTrackingIndexOverride(-1),
          wanderingAimEnabled(false), accuracyPerfect(true),
          showWanderingAim(false), frameMilliseconds(16),
          aimTrackerDebugLevel(0), lookTrackerDebugLevel(0),
          globalDebugLevel(0), aimDebugLevel(0), lookDebugLevel(0),
          trackingDebugLevel(0) {
    }
};

class idFocusInfo {
public:
    idFocusInfo();
    ~idFocusInfo();

    void Shutdown(idAnimatedEntity* owner);
    void SetConstraints(const idRotationTrackerRange& constraints);
    void AddWeaponFireKickback(const idAnimatedEntity* owner,
        const idWeapon* weapon);
    void SetEnableTracking(const idAnimatedEntity* owner, bool enable);
    void SetSuppressTracking(const idAnimatedEntity* owner, bool suppress);
    void SetDeclTrackingParms(const idDeclTrackingParms* declaration);
    void SetTrackingParmsIndex(int index);
    void SetTempFocusPoint(idAnimatedEntity* owner,
        const idVec3& focusPoint, aiFocus_t type);
    void SetLockTracking(bool lock);
    void Init(idAnimatedEntity* owner, aiFoci_t type);
    const idDeclMD6::idHeadTrackGroup* GetCurHeadTrackGroup(
        const idAnimatedEntity* owner) const;
    void SetReferenceJointOverride(const idAnimatedEntity* owner,
        idIndex<short, invalidJointIndex_t> jointIndex);
    void SetExplicitFocusPoint(idAnimatedEntity* owner,
        const idVec3& focusPoint, bool keepInView, int duration,
        aiFocus_t type);
    void Clear(idAnimatedEntity* owner);
    void SetCurHeadTrackGroup(const idAnimatedEntity* owner,
        int trackGroupIndex);
    void SetFocusEntity(idAnimatedEntity* owner, const idEntity* entity,
        bool keepInView, aimPoint_t point, int duration);
    void Update(const idAnimatedEntity* owner,
        const idAnimator_TrackerBase* parentTracker);
    bool HasFocus() const;

    idWanderingAim wanderingAim;
    idEntityPtr<const idEntity> focusEntity;
    aimPoint_t aimPoint;
    const idDeclTrackingParms* declTrackingParms;
    int trackingParmsIndex;
    int focusTimeout;
    idVec3 idealFocusPoint;
    idVec3 curFocusPoint;
    idVec3 offset;
    idVec3 explicitOffset;
    idAngles explicitOffsetAngles;
    idAimTracker aimTracker;
    aiFoci_t fociType;
    aiFocus_t focusType;
    int defaultHeadTrackGroup;
    idAnimator_TrackerBase* animators[2];
    int curAnimatorIndex;
    idMat3 wsReferenceAxis;
    bool enableTracking;
    bool suppressTracking;
    bool keepFocusInView;
    bool hasExplicitFocusPoint;
    bool lockTracking;

private:
    void SwapTrackers(const idAnimatedEntity* owner, int blendTime);
    void BlendOut(const idAnimatedEntity* owner, int blendTime);
    void BlendIn(const idAnimatedEntity* owner, int blendTime);
    void ShowTrackingInfo(const idAnimatedEntity* owner,
        const char* name, const idVec3& eyePosition,
        const idVec3& debugOffset) const;
};

idAnimator_TrackerBase* Tungsten_CreateFocusAnimator(
    idAnimatedEntity& owner, aiFoci_t type, int index,
    const char* name, bool projectReferenceOrientation);
void Tungsten_ShutdownFocusAnimator(
    idAnimator_TrackerBase& animator, idAnimatedEntity& owner);
void Tungsten_DestroyFocusAnimator(idAnimator_TrackerBase* animator);
void Tungsten_SetFocusAnimatorLock(
    idAnimator_TrackerBase& animator, bool lock);
int Tungsten_GetFocusAnimatorTrackGroup(
    const idAnimator_TrackerBase& animator);
void Tungsten_SetFocusAnimatorTrackGroup(
    idAnimator_TrackerBase& animator, int trackGroupIndex);
idIndex<short, invalidJointIndex_t>
Tungsten_GetFocusAnimatorReferenceJoint(
    const idAnimator_TrackerBase& animator);
void Tungsten_SetFocusAnimatorReferenceJoint(
    idAnimator_TrackerBase& animator,
    idIndex<short, invalidJointIndex_t> jointIndex);
bool Tungsten_CanSwapFocusAnimators(
    const idAnimator_TrackerBase& first,
    const idAnimator_TrackerBase& second);
void Tungsten_StartFocusAnimator(idAnimator_TrackerBase& animator,
    const idAnimatedEntity& owner, int currentTime,
    int blendDuration, bool reset);
void Tungsten_EndFocusAnimator(idAnimator_TrackerBase& animator,
    const idAnimatedEntity& owner, int currentTime,
    int blendDuration, bool reset);
bool Tungsten_GetFocusAnimatorState(
    const idAnimator_TrackerBase& animator,
    idFocusAnimatorState& state);
void Tungsten_UpdateFocusAnimator(idAnimator_TrackerBase& animator,
    const idAnimator_TrackerBase* parentTracker,
    const idVec3& focusPoint, const idAngles& offsetAngles,
    const idRotationTrackerRange& constraints);

int Tungsten_GetFocusGameMilliseconds();
int Tungsten_GetFocusEntitySpawnId(const idEntity* entity);
const idEntity* Tungsten_ResolveFocusEntity(int spawnId);
bool Tungsten_GetFocusEntityAimPoint(const idEntity& entity,
    aimPoint_t aimPoint, idVec3& result);
void Tungsten_WarnFocusInfo(const char* text);
idAI2* Tungsten_CastFocusOwnerToAI2(const idAnimatedEntity* owner);
bool Tungsten_GetFocusUpdateRuntime(const idAnimatedEntity& owner,
    idFocusUpdateRuntime& runtime);
bool Tungsten_GetFocusFrameOfReference(const idAnimatedEntity& owner,
    const idAnimator_TrackerBase& animator,
    const idAnimator_TrackerBase* parentTracker,
    idVec3& worldOrigin, idMat3& worldReferenceAxis,
    float& ownerRadius, idVec3& gravityNormal);
int Tungsten_GetFocusHeadTrackGroupCount(
    const idAnimatedEntity& owner);
const idDeclMD6::idHeadTrackGroup* Tungsten_GetFocusHeadTrackGroup(
    const idAnimatedEntity& owner, int index);
const char* Tungsten_GetFocusTrackingDeclName(
    const idDeclTrackingParms* declaration);
int Tungsten_GetFocusTrackingParmsCount(
    const idDeclTrackingParms& declaration);
bool Tungsten_GetFocusTrackingParms(
    const idDeclTrackingParms& declaration, int index,
    trackingParms_t& parms);
void Tungsten_DebugFocusGeometry(const idFocusInfo& focus,
    const idAnimatedEntity& owner, const idVec3& eyePosition,
    const idVec3& finalFocusPoint);
void Tungsten_DebugFocusTracking(const idFocusInfo& focus,
    const idAnimatedEntity& owner, const char* name,
    const idVec3& eyePosition, const idVec3& debugOffset,
    const idDeclMD6::idHeadTrackGroup* group,
    idIndex<short, invalidJointIndex_t> referenceJoint,
    const char* trackingDeclarationName);
