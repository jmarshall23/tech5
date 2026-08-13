#pragma once

#include "game/entities/entity.h"

class idAI2;
class idPlayer;
class idSoundShader;
class idVehicle;
class idVehicleKey;
enum aimPoint_t : int;

enum aiHintPrimitive_t : int {
    AIHINT_PRIMITIVE_CIRCLE = 0,
    AIHINT_PRIMITIVE_CYLINDER = 1,
    AIHINT_PRIMITIVE_SPHERE = 2,
    AIHINT_PRIMITIVE_PLANE = 3,
    AIHINT_PRIMITIVE_VOLUME = 4,
    AIHINT_PRIMITIVE_MAX = 5
};

class idInfoServices {
public:
    virtual ~idInfoServices() = default;
    virtual int GetGameMilliseconds() const;
    virtual int RandomInt(int maximum);
    virtual bool IsProduction() const;
    virtual const char* GetMapName() const;
    virtual idEntity* FindEntity(const char* name) const;
    virtual void SetEntityContents(idEntity& entity, int contents);
    virtual void QueueRemove(idEntity& entity);
    virtual void DebugPoint(const idVec3& origin, const idColor& color,
        int lifetimeMilliseconds, bool depthTest);
    virtual void DebugText(const char* text, const idVec3& origin,
        const idColor& color, float scale, int lifetimeMilliseconds,
        bool depthTest);
    virtual void RegisterLookTargetGroup(idEntity* group, bool add);
    virtual void RegisterGarageBay(idEntity* bay, bool add);
    virtual void ReportWarning(const char* message);
    virtual void ReportError(const char* message);

    virtual bool ValidateCombatHintType(int hintType,
        const idEntity& entity) const;
    virtual bool IsPointInHintVolume(const idEntity* volume,
        const idVec3& point) const;
    virtual bool IsEntityInHintVolume(const idEntity* volume,
        const idEntity* entity) const;
    virtual int GetCoverPointCount() const;
    virtual idVec3 GetCoverPoint(int index) const;
    virtual bool LoadAAS(const char* name) const;
    virtual bool LoadAAS(int type) const;
    virtual bool IsAASPointReachable(int type, const idVec3& point) const;
    virtual bool ActionBlocks(const idAI2* ai,
        const char* eventName) const;
    virtual bool ActionStopsMovement(const idAI2* ai,
        const char* eventName) const;

    virtual bool IsVehicleAtRest(const idVehicle* vehicle) const;
    virtual void SetVehicleActive(idVehicle* vehicle, bool active);
    virtual void TeleportVehicle(idVehicle* vehicle,
        const idVec3& origin, const idMat3& axis);
    virtual idVehicleKey* GetVehicleKey(idVehicle* vehicle) const;
    virtual void GetPlayerVehicleKeys(idPlayer* player, int garage,
        idList<idVehicleKey*, 5>& keys) const;
    virtual idVehicle* SpawnPlayerVehicle(idVehicleKey* key,
        const idVec3& origin, const idMat3& axis);
    virtual bool VehicleKeyIsSelected(const idVehicleKey* key) const;
    virtual void ClearVehicleKeySelection(idVehicleKey* key);
    virtual void PrepareGarageVehicle(idVehicle* vehicle,
        idVehicleKey* key, const idMat3& focusAxis);
    virtual void RotateGarageSystem(float angle,
        const idVec3& origin, const idMat3& axis);
    virtual void ActivateGarageEffect(idEntity* effect,
        idEntity* activator);
    virtual void PlayGarageSound(idEntity& owner,
        const idSoundShader* sound);
};

class idInfo : public idEntity {
public:
    static void SetServices(idInfoServices* services);
    static idInfoServices& Services();
    void Spawn() override;
};

class idAIHint : public idInfo {
public:
    idAIHint();
    bool enabled;
};

class idAIHintGroup : public idInfo {
public:
    idAIHintGroup();
};

class idAISearchHintGroup : public idAIHintGroup {
public:
    idAISearchHintGroup();
};

class idAIBackStandHint : public idAIHint {
public:
    idAIBackStandHint();
    void Spawn() override;
};

class idAIAASHint : public idAIHint {
public:
    idAIAASHint();
};

class idAISearchHintAuto : public idAIHint {
public:
    idAISearchHintAuto();
    float radius;
};

class idAISearchHintAnimation : public idAIHint {
public:
    idAISearchHintAnimation();
    int searchAnim;
};

class idInfoCover : public idInfo {
public:
    idInfoCover();
    int coverPosture;
    float duration;
    int transitions;
    float minRange;
    float maxRange;
    int aasLayer;
    bool force;
};

class idInfoOrbit : public idInfo {
public:
    idInfoOrbit();
    void Spawn() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;

    float degreesPerSec;
    bool useRealTime;
    float time;
    float rtDist;
    float upDist;
    int startTime;
    int endTime;
    idVec3 spawnOrg;
    idVec3 spawnDir;
};

class idInfoTexLod : public idInfo {
public:
    idInfoTexLod();
    idStr texLodModelName;
    float stepDistance;
};

class idInfoStaticReflection : public idInfo {
public:
    idInfoStaticReflection();
    int spotId;
};

class idInfoSpawnPoint : public idInfo {
public:
    idInfoSpawnPoint();
};

class idInfoDebugMarker : public idInfo {
public:
    void Think() override;
};

class idInfoDebugText : public idInfo {
public:
    idInfoDebugText();
    void Spawn() override;
    void Think() override;
    idStr text;
    idColor textColor;
    float textScale;
    bool depthTest;
    bool permanent;
};

class idInfoDebugMapName : public idInfoDebugText {
public:
    idInfoDebugMapName();
};

class idCamera : public idInfo {
public:
    void GetAimPoint(aimPoint_t type, idVec3& point) const;
};

class idInfoLookTargetGroup : public idInfo {
public:
    idInfoLookTargetGroup();
    ~idInfoLookTargetGroup() override;
    void Spawn() override;
    bool IsInside(const idVec3& point) const;
    float radius;
    float height;
};

class idAIHintPrimitive {
public:
    idAIHintPrimitive();
    float GetPointWeight(const idVec3& origin, const idMat3& axis,
        const idVec3& point, float minimumWeight) const;
    float GetEntityWeight(const idVec3& origin, const idMat3& axis,
        const idEntity* entity, float minimumWeight) const;

    aiHintPrimitive_t type;
    float radius;
    float height;
    float arcLen;
    idEntity* volume;
};

class idAICombatHint : public idAIHint {
public:
    enum combatHintType_t : int {
        COMBAT_HINT_DEFENSE_POINT = 0,
        COMBAT_HINT_ASSAULT_POINT = 1,
        COMBAT_HINT_FLANK_POINT = 2,
        COMBAT_HINT_FLANK_TARGET_POINT = 3,
        COMBAT_HINT_FLANK_PATH_POINT = 4,
        COMBAT_HINT_GRENADE_POINT = 5,
        COMBAT_HINT_RECHARGE_POINT = 6,
        COMBAT_HINT_SUPPRESSION_FIRE_POINT = 7,
        COMBAT_HINT_MAX = 8
    };
    enum combatHintClass_t : int {
        COMBATHINTCLASS_DEFAULT = 1,
        COMBATHINTCLASS_A = 1,
        COMBATHINTCLASS_B = 2,
        COMBATHINTCLASS_C = 4,
        CLASS_ALL = 7,
        COMBATHINTCLASS_MAX = 8
    };

    idAICombatHint();
    const char* GetClassName() const;
    static const idColor& HintTypeColor(combatHintType_t hintType);
    void Spawn() override;
    const idColor& GetDrawColor() const;
    float GetPointWeight(const idVec3& point) const;
    float GetEntityWeight(const idEntity* entity) const;
    int FindAASCoverIndices();

    combatHintType_t combatHintType;
    idAIHintPrimitive primitive;
    float minWeight;
    int delay;
    combatHintClass_t hintClass;
    idList<int, 5> coverIndices;
    int dontUseUntil;
};

class idInfoVehicleObstacle : public idInfo {
public:
    void Spawn() override;
};

class idInfo_Trigger_Facing_Target : public idInfo {
public:
    bool CheckIsFacing(const idVec3& viewDirection,
        const idVec3& viewPosition) const;
    float radius = 64.0f;
    bool doVerticleTest = false;
};

class idInfoLookTarget : public idInfo {
public:
    struct lookerInfo_t {
        const idEntity* looker = nullptr;
        int nextLookTime = -1;
    };

    idInfoLookTarget();
    bool CanLook(const idEntity* looker) const;
    void SetLooking(const idEntity* looker);

    float lookTime;
    float lookDelay;
    float maxDist;
    bool aim;
    lookerInfo_t lookerInfo[3];
    int nextLookerInfo;
};

class idInfoSplineChild : public idInfo {
public:
    struct splineLocation_t {
        idEntity* splinePath = nullptr;
        float controlPointLength = -1.0f;
        float lengthOnSpline = 0.0f;
        idVec3 controlPointOrigin = idVec3(0.0f, 0.0f, 0.0f);
        int controlPointIndex = 0;
        float controlPointPCT = 0.0f;
        idVec3 controlPointOriginNext = idVec3(0.0f, 0.0f, 0.0f);
        bool initialized = false;
        bool dirty = false;
    };

    idInfoSplineChild();
    float Event_GetLengthOnSpline() const;
    idEntity* Event_GetParentSpline() const;
    splineLocation_t splineLoc;
};

class idInfoAAS : public idInfo {
public:
    void Spawn() override;
    idStr aasName;
};

class idInfoExportHint : public idInfo {
public:
    void Spawn() override;
};

class idInfoGarageBay : public idInfo {
public:
    enum garage_t : int {
        GARAGE_NONE = 0, GARAGE_HAGER, GARAGE_WELLSPRING,
        GARAGE_SUBWAYTOWN, GARAGE_MAX
    };
    enum vehicleClass_t : int {
        VEHICLE_CLASSNONE = 0, VEHICLE_CLASS1, VEHICLE_CLASS2,
        VEHICLE_CLASS3, VEHICLE_CLASS4
    };

    idInfoGarageBay();
    ~idInfoGarageBay() override;
    void Spawn() override;
    const idVehicle* GetVehicle() const;
    garage_t garage;
    vehicleClass_t vehicleClass;
    idVehicle* vehicle;
};

class idTownGarageManager : public idInfo {
public:
    enum garageState_t : int {
        GARAGESTATE_NORMAL = 0,
        GARAGESTATE_MOVINGTOHIDE = 1,
        GARAGESTATE_MOVINGTORETURN = 2
    };
    struct vehicleShadowInfo_t {
        const void* keyDecl = nullptr;
        idEntity* shadowEntity = nullptr;
    };
    struct vehicleInfo_t {
        idVehicle* vehicle = nullptr;
        idEntity* shadowEntity = nullptr;
    };

    idTownGarageManager();
    void Think() override;
    void ActivateCars();
    void DeactivateCars();
    bool ProperSetup();
    void SetupAndMoveOffscreen();
    bool GotoNextTarget();
    bool GotoPreviousTarget();
    void SetupAndMoveBackOn();
    void SetSystemRotation(float angle);
    void StopMovingEffects();
    void Update();
    bool SetUpVehiclesForView();
    idVehicleKey* GetCurrentKey();
    void SpawnVehicles(idPlayer* player);

    idInfoGarageBay::garage_t garage;
    idInfoGarageBay* focusBay;
    idEntity* newRotateEnt;
    idEntity* effectEnt;
    int timeToRotate;
    float rotationStepAmount;
    const idSoundShader* rotationSound;
    const idSoundShader* stopSound;
    idList<vehicleShadowInfo_t, 5> shadowInfoList;
    idEntity* wastelandMultiSpawn;
    const idSoundShader* cantEnterSound;
    garageState_t currentState;
    int currentVehicleIndex;
    int nextVehicleIndex;
    bool spawnCalled;
    bool shouldDeactivateCars;
    bool needStopSound;
    idList<vehicleInfo_t, 5> vehicles;
    int rotationStartTime;
    int spawnTime;
};

struct idInfoPathAction {
    idStr eventName;
    int durationMilliseconds = 0;
};

class idInfoPath : public idInfo {
public:
    struct anim_t {
        idStr name;
        int weight = 1;
        float timeBetween = 0.0f;
        int nextPlayTime = 0;
    };

    idInfoPath();
    void Spawn() override;
    int ChoosePlayerLeftAnim() const;
    const idEntity* GetFocus() const;
    bool StopAtPoint(const idAI2* ai) const;
    const idInfoPath* GetNextPathPoint() const;

    idList<idInfoPathAction, 5> actionScript;
    idEntity* focus;
    float stopTime;
    bool turnEarly;
    float alignmentTolerance;
    bool lookAtNextPoint;
    bool alignToNode;
    bool keepFocusInView;
    bool interactionPoint;
    bool abortForSearch;
    int walkState;
    int standState;
    int sitState;
    int walkMod;
    int runMod;
    int aasType;
    idList<anim_t, 5> playerLeftAnims;
};

struct idInfoAmbientColors {
    idColor editorEast;
    idColor editorWest;
    idColor editorNorth;
    idColor editorSouth;
    idColor editorUp;
    idColor editorDown;
};

class idInfoAmbient : public idInfo {
public:
    // Retail header source: 0x82518110
    idInfoAmbient();
    idInfoAmbientColors ambientOverrideColors;
};

class idInfoDevComment : public idInfoDebugText {
public:
    // Retail header source: 0x82536780
    idInfoDevComment();
    idStr comment;
    bool showAlways;
};

const char* GetInfoDevComment(const char* entityName);
