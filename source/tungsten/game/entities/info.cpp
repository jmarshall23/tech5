#include "game/entities/info.h"

#include <algorithm>
#include <cmath>

namespace {
idInfoServices defaultInfoServices;
idInfoServices* infoServices = &defaultInfoServices;

idVec3 Add(const idVec3& a, const idVec3& b) {
    return idVec3(a.x + b.x, a.y + b.y, a.z + b.z);
}
idVec3 Subtract(const idVec3& a, const idVec3& b) {
    return idVec3(a.x - b.x, a.y - b.y, a.z - b.z);
}
idVec3 Scale(const idVec3& value, float scale) {
    return idVec3(value.x * scale, value.y * scale, value.z * scale);
}
float Dot(const idVec3& a, const idVec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
float Length(const idVec3& value) {
    return std::sqrt(Dot(value, value));
}
idVec3 Normalize(const idVec3& value) {
    const float length = Length(value);
    return length > 1.0e-6f ? Scale(value, 1.0f / length)
                           : idVec3(0.0f, 0.0f, 1.0f);
}
idMat3 RotationAroundAxis(const idVec3& inputAxis, float degrees) {
    const idVec3 axis = Normalize(inputAxis);
    const float radians = degrees * 0.01745329251994329577f;
    const float cosine = std::cos(radians);
    const float sine = std::sin(radians);
    const float oneMinusCosine = 1.0f - cosine;
    return idMat3(
        cosine + axis.x * axis.x * oneMinusCosine,
        axis.x * axis.y * oneMinusCosine - axis.z * sine,
        axis.x * axis.z * oneMinusCosine + axis.y * sine,
        axis.y * axis.x * oneMinusCosine + axis.z * sine,
        cosine + axis.y * axis.y * oneMinusCosine,
        axis.y * axis.z * oneMinusCosine - axis.x * sine,
        axis.z * axis.x * oneMinusCosine - axis.y * sine,
        axis.z * axis.y * oneMinusCosine + axis.x * sine,
        cosine + axis.z * axis.z * oneMinusCosine);
}
}

int idInfoServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
int idInfoServices::RandomInt(int maximum) {
    if (maximum <= 0) return 0;
    return static_cast<int>(idEntity::Services().RandomFloat(
        static_cast<float>(maximum))) % maximum;
}
bool idInfoServices::IsProduction() const { return false; }
const char* idInfoServices::GetMapName() const { return ""; }
idEntity* idInfoServices::FindEntity(const char* name) const {
    return idEntity::Services().FindEntity(name);
}
void idInfoServices::SetEntityContents(idEntity& entity, int contents) {
    entity.contents = contents;
}
void idInfoServices::QueueRemove(idEntity& entity) { entity.removed = true; }
void idInfoServices::DebugPoint(const idVec3&, const idColor&, int, bool) {}
void idInfoServices::DebugText(const char*, const idVec3&, const idColor&,
        float, int, bool) {}
void idInfoServices::RegisterLookTargetGroup(idEntity*, bool) {}
void idInfoServices::RegisterGarageBay(idEntity*, bool) {}
void idInfoServices::ReportWarning(const char*) {}
void idInfoServices::ReportError(const char*) {}
bool idInfoServices::ValidateCombatHintType(int, const idEntity&) const {
    return true;
}
bool idInfoServices::IsPointInHintVolume(
        const idEntity*, const idVec3&) const { return false; }
bool idInfoServices::IsEntityInHintVolume(
        const idEntity*, const idEntity*) const { return false; }
int idInfoServices::GetCoverPointCount() const { return 0; }
idVec3 idInfoServices::GetCoverPoint(int) const {
    return idVec3(0.0f, 0.0f, 0.0f);
}
bool idInfoServices::LoadAAS(const char*) const { return false; }
bool idInfoServices::LoadAAS(int) const { return false; }
bool idInfoServices::IsAASPointReachable(int, const idVec3&) const {
    return false;
}
bool idInfoServices::ActionBlocks(const idAI2*, const char*) const {
    return false;
}
bool idInfoServices::ActionStopsMovement(const idAI2*, const char*) const {
    return false;
}
bool idInfoServices::IsVehicleAtRest(const idVehicle*) const { return true; }
void idInfoServices::SetVehicleActive(idVehicle*, bool) {}
void idInfoServices::TeleportVehicle(
        idVehicle*, const idVec3&, const idMat3&) {}
idVehicleKey* idInfoServices::GetVehicleKey(idVehicle*) const {
    return nullptr;
}
void idInfoServices::GetPlayerVehicleKeys(
        idPlayer*, int, idList<idVehicleKey*, 5>&) const {}
idVehicle* idInfoServices::SpawnPlayerVehicle(
        idVehicleKey*, const idVec3&, const idMat3&) { return nullptr; }
bool idInfoServices::VehicleKeyIsSelected(const idVehicleKey*) const {
    return false;
}
void idInfoServices::ClearVehicleKeySelection(idVehicleKey*) {}
void idInfoServices::PrepareGarageVehicle(
        idVehicle*, idVehicleKey*, const idMat3&) {}
void idInfoServices::RotateGarageSystem(
        float, const idVec3&, const idMat3&) {}
void idInfoServices::ActivateGarageEffect(idEntity* effect,
        idEntity* activator) {
    if (effect != nullptr) effect->Activate(activator);
}
void idInfoServices::PlayGarageSound(
        idEntity&, const idSoundShader*) {}

void idInfo::SetServices(idInfoServices* services) {
    infoServices = services != nullptr ? services : &defaultInfoServices;
}
idInfoServices& idInfo::Services() { return *infoServices; }

// Retail: 0x82C622C8
void idInfo::Spawn() {
    if (presentable != nullptr && renderModel != nullptr) {
        SetModel(static_cast<idRenderModel*>(nullptr));
    }
}

// Retail: 0x82C61690
idAIHint::idAIHint() : enabled(true) {}

// Retail: 0x82C616D8
idAIHintGroup::idAIHintGroup() = default;

// Retail: 0x82C61718
idAISearchHintGroup::idAISearchHintGroup() = default;

// Retail: 0x82C618D8
idAIBackStandHint::idAIBackStandHint() = default;

// Retail: 0x82C61358
void idAIBackStandHint::Spawn() { Services().SetEntityContents(*this, 0); }

// Retail: 0x82C61920
idAIAASHint::idAIAASHint() = default;

// Retail: 0x82C61968
idAISearchHintAuto::idAISearchHintAuto() : radius(48.0f) {}

// Retail: 0x82C619B8
idAISearchHintAnimation::idAISearchHintAnimation() : searchAnim(-1) {}

// Retail: 0x82C61A08
idInfoCover::idInfoCover()
    : coverPosture(0), duration(-1.0f), transitions(-1), minRange(0.0f),
      maxRange(0.0f), aasLayer(0), force(false) {}

// Retail: 0x82C61AA0
idInfoOrbit::idInfoOrbit()
    : degreesPerSec(1.0f), useRealTime(false), time(10.0f), rtDist(0.0f),
      upDist(0.0f), startTime(0), endTime(0),
      spawnOrg(0.0f, 0.0f, 0.0f), spawnDir(0.0f, 0.0f, 0.0f) {}

// Retail: 0x82C636D8
void idInfoOrbit::Spawn() {
    if (targets.Num() == 0 || targets[0] == nullptr) return;
    const idEntity* target = targets[0];
    const idVec3 delta = Subtract(origin, target->origin);
    rtDist = Dot(target->axis[1], delta);
    upDist = Dot(target->axis[2], delta);
    spawnOrg = target->origin;
    spawnDir = axis[0];
}

// Retail: 0x82C61B50
void idInfoOrbit::OnActivate(idEntity*) {
    BecomeActive(1);
    startTime = Services().GetGameMilliseconds();
    endTime = startTime + static_cast<int>(time * 1000.0f);
}

// Retail: 0x82C638C8
void idInfoOrbit::Think() {
    if (targets.Num() == 0 || targets[0] == nullptr) return;
    const int now = Services().GetGameMilliseconds();
    const float angle = static_cast<float>(startTime - now)
        * degreesPerSec * 0.001f;
    const idMat3 rotation = RotationAroundAxis(spawnDir, angle);
    const idVec3 offset = Add(Scale(rotation[1], rtDist),
        Scale(rotation[2], upDist));
    SetOrigin(Add(targets[0]->origin, offset));
    if (now >= endTime) BecomeInactive(1);
}

// Retail: 0x82C61BE8
idInfoTexLod::idInfoTexLod() : stepDistance(64.0f) {}

// Retail: 0x82C61C50
idInfoStaticReflection::idInfoStaticReflection() : spotId(0) {}

// Retail: 0x82C61D88
idInfoSpawnPoint::idInfoSpawnPoint() = default;

// Retail: 0x82C613C8
void idInfoDebugMarker::Think() {
    idColor drawColor(-1.0f, -1.0f, -1.0f, -1.0f);
    GetColor(drawColor);
    Services().DebugPoint(origin, drawColor,
        idEntity::Services().GetGameMillisecondsPerFrame(), true);
}

// Retail: 0x82C61DC8
idInfoDebugText::idInfoDebugText()
    : textColor(idColor::colorWhite), textScale(1.0f), depthTest(true),
      permanent(true) {}

// Retail: 0x82C61EE0
void idInfoDebugText::Think() {
    if (!text.IsEmpty()) {
        Services().DebugText(text.c_str(), origin, textColor,
            textScale * 0.25f,
            idEntity::Services().GetGameMillisecondsPerFrame(), depthTest);
    }
}

// Retail: 0x82C648C0
void idInfoDebugText::Spawn() {
    if (Services().IsProduction()) {
        Services().SetEntityContents(*this, 0);
        Services().QueueRemove(*this);
    } else if (permanent) {
        if (!text.IsEmpty()) {
            Services().DebugText(text.c_str(), origin, textColor,
                textScale * 0.25f, 0x7FFFFFFF, depthTest);
        }
    } else {
        BecomeActive(1);
    }
}

// Retail: 0x82C61FA0
idInfoDebugMapName::idInfoDebugMapName() { text = Services().GetMapName(); }

// Retail: 0x82C62038
void idCamera::GetAimPoint(aimPoint_t, idVec3& point) const {
    point = origin;
}

// Retail: 0x82C62090
idInfoLookTargetGroup::idInfoLookTargetGroup()
    : radius(512.0f), height(128.0f) {}

// Retail: 0x82C64F78
idInfoLookTargetGroup::~idInfoLookTargetGroup() {
    Services().RegisterLookTargetGroup(this, false);
}

// Retail: 0x82C65B68
void idInfoLookTargetGroup::Spawn() {
    Services().RegisterLookTargetGroup(this, true);
}

// Retail: 0x82C620E8
bool idInfoLookTargetGroup::IsInside(const idVec3& point) const {
    const float x = point.x - origin.x;
    const float y = point.y - origin.y;
    if (x * x + y * y > radius * radius) return false;
    const float halfHeight = height * 0.5f;
    return point.z >= origin.z - halfHeight
        && point.z < origin.z + halfHeight;
}

idAIHintPrimitive::idAIHintPrimitive()
    : type(AIHINT_PRIMITIVE_SPHERE), radius(128.0f), height(0.0f),
      arcLen(0.0f), volume(nullptr) {}

// Retail: 0x82C62358
float idAIHintPrimitive::GetPointWeight(const idVec3& origin,
        const idMat3& axis, const idVec3& point,
        const float minimumWeight) const {
    const idVec3 delta = Subtract(point, origin);
    float distance = 0.0f;
    switch (type) {
    case AIHINT_PRIMITIVE_CIRCLE:
    case AIHINT_PRIMITIVE_SPHERE:
        distance = Length(delta);
        if (radius <= 0.0f || distance > radius) return 0.0f;
        return (std::max)(minimumWeight, 1.0f - distance / radius);
    case AIHINT_PRIMITIVE_CYLINDER:
        if (delta.z < 0.0f || delta.z > height || radius <= 0.0f) {
            return 0.0f;
        }
        distance = Length(delta);
        if (distance > radius) return 0.0f;
        return (std::max)(minimumWeight, 1.0f - distance / radius);
    case AIHINT_PRIMITIVE_PLANE: {
        const float signedDistance = Dot(point, axis[0])
            - Dot(origin, axis[0]);
        if (signedDistance > 0.0f) return 0.0f;
        if (-signedDistance >= radius || radius <= 0.0f) return 1.0f;
        return (std::max)(minimumWeight,
            1.0f - (-signedDistance / radius));
    }
    case AIHINT_PRIMITIVE_VOLUME:
        return volume != nullptr
            && idInfo::Services().IsPointInHintVolume(volume, point)
            ? 1.0f : 0.0f;
    default:
        return 0.0f;
    }
}

// Retail: 0x82C625F0
float idAIHintPrimitive::GetEntityWeight(const idVec3& origin,
        const idMat3& axis, const idEntity* entity,
        const float minimumWeight) const {
    if (entity == nullptr) return 0.0f;
    if (type == AIHINT_PRIMITIVE_VOLUME) {
        return volume != nullptr
            && idInfo::Services().IsEntityInHintVolume(volume, entity)
            ? 1.0f : 0.0f;
    }
    return GetPointWeight(origin, axis, entity->origin, minimumWeight);
}

// Retail: 0x82C633E8
idAICombatHint::idAICombatHint()
    : combatHintType(COMBAT_HINT_DEFENSE_POINT), minWeight(0.0f), delay(0),
      hintClass(CLASS_ALL), dontUseUntil(0) {}

// Retail: 0x82C61288
const char* idAICombatHint::GetClassName() const {
    switch (hintClass) {
    case COMBATHINTCLASS_A: return "(A)";
    case COMBATHINTCLASS_B: return "(B)";
    case COMBATHINTCLASS_C: return "(C)";
    default: return "";
    }
}

// Retail: 0x82C612D8
const idColor& idAICombatHint::HintTypeColor(
        const combatHintType_t hintType) {
    switch (hintType) {
    case COMBAT_HINT_DEFENSE_POINT: return idColor::colorGreen;
    case COMBAT_HINT_ASSAULT_POINT: return idColor::colorOrange;
    case COMBAT_HINT_FLANK_POINT:
    case COMBAT_HINT_FLANK_PATH_POINT: return idColor::colorRed;
    case COMBAT_HINT_FLANK_TARGET_POINT: return idColor::colorWhite;
    case COMBAT_HINT_GRENADE_POINT: return idColor::colorPurple;
    case COMBAT_HINT_RECHARGE_POINT: return idColor::colorBlue;
    case COMBAT_HINT_SUPPRESSION_FIRE_POINT: return idColor::colorYellow;
    default: return idColor::colorWhite;
    }
}

// Retail: 0x82C61758
void idAICombatHint::Spawn() {
    if (!Services().ValidateCombatHintType(combatHintType, *this)) {
        Services().ReportError("combat hint entity type does not match hint type");
    }
    if (minWeight < 0.0f || minWeight > 1.0f) {
        Services().ReportError("combat hint minWeight must be in [0, 1]");
    }
}

// Retail: 0x82C61868
const idColor& idAICombatHint::GetDrawColor() const {
    return Services().GetGameMilliseconds() >= dontUseUntil
        ? HintTypeColor(combatHintType) : idColor::colorMdGrey;
}

// Retail: 0x82C62728
float idAICombatHint::GetPointWeight(const idVec3& point) const {
    return primitive.GetPointWeight(origin, axis, point, minWeight);
}

// Retail: 0x82C627B0
float idAICombatHint::GetEntityWeight(const idEntity* entity) const {
    return primitive.GetEntityWeight(origin, axis, entity, minWeight);
}

// Retail: 0x82C634D0
int idAICombatHint::FindAASCoverIndices() {
    coverIndices.Clear();
    const int count = Services().GetCoverPointCount();
    for (int index = 1; index < count; ++index) {
        if (GetPointWeight(Services().GetCoverPoint(index)) > 0.0f) {
            coverIndices.Append(index);
        }
    }
    if (count == 0) {
        Services().ReportWarning("no AAS to collect combat hint cover points");
    }
    return coverIndices.Num();
}

// Retail: 0x82C62B68
void idInfoVehicleObstacle::Spawn() {
    Services().SetEntityContents(*this, 0x20000);
}

// Retail: 0x82C62DF0
bool idInfo_Trigger_Facing_Target::CheckIsFacing(
        const idVec3& viewDirection, const idVec3& viewPosition) const {
    idVec3 direction = viewDirection;
    idVec3 toCenter = Subtract(origin, viewPosition);
    if (!doVerticleTest) {
        direction.z = 0.0f;
        toCenter.z = 0.0f;
    }
    const float directionLength = Length(direction);
    if (directionLength <= 1.0e-6f) return false;
    direction = Scale(direction, 1.0f / directionLength);
    const float projection = Dot(toCenter, direction);
    if (projection < 0.0f) return false;
    const idVec3 closest = Scale(direction, projection);
    return Dot(Subtract(toCenter, closest),
        Subtract(toCenter, closest)) < radius * radius;
}

// Retail: 0x82C64A20
idInfoLookTarget::idInfoLookTarget()
    : lookTime(3.0f), lookDelay(3.0f), maxDist(512.0f), aim(true),
      nextLookerInfo(0) {}

// Retail: 0x82C62FE8
bool idInfoLookTarget::CanLook(const idEntity* looker) const {
    if (looker == nullptr) return false;
    for (int index = 0; index < 3; ++index) {
        if (lookerInfo[index].looker == looker) {
            return Services().GetGameMilliseconds()
                >= lookerInfo[index].nextLookTime;
        }
    }
    return true;
}

// Retail: 0x82C64AA8
void idInfoLookTarget::SetLooking(const idEntity* looker) {
    int index = -1;
    for (int candidate = 0; candidate < 3; ++candidate) {
        if (lookerInfo[candidate].looker == looker) {
            index = candidate;
            break;
        }
    }
    if (index < 0) {
        index = nextLookerInfo;
        nextLookerInfo = (nextLookerInfo + 1) % 3;
    }
    lookerInfo[index].looker = looker;
    lookerInfo[index].nextLookTime = Services().GetGameMilliseconds()
        + static_cast<int>(lookDelay * 1000.0f);
}

// Retail: 0x82C64BD0
idInfoSplineChild::idInfoSplineChild() = default;

// Retail: 0x82C61390
float idInfoSplineChild::Event_GetLengthOnSpline() const {
    return splineLoc.lengthOnSpline;
}

// Retail: 0x82C630C8
idEntity* idInfoSplineChild::Event_GetParentSpline() const {
    return splineLoc.splinePath;
}

// Retail: 0x82C63148
void idInfoAAS::Spawn() {
    Services().LoadAAS(aasName.c_str());
    Services().QueueRemove(*this);
}

// Retail: 0x82C63638
void idInfoExportHint::Spawn() {
    Services().SetEntityContents(*this, 0);
    Services().QueueRemove(*this);
}

// Retail: 0x82C63B00
idInfoGarageBay::idInfoGarageBay()
    : garage(GARAGE_NONE), vehicleClass(VEHICLE_CLASSNONE),
      vehicle(nullptr) {}

// Retail: 0x82C64CF8
idInfoGarageBay::~idInfoGarageBay() { Services().RegisterGarageBay(this, false); }

// Retail: 0x82C65C48
void idInfoGarageBay::Spawn() { Services().RegisterGarageBay(this, true); }

// Retail: 0x82C628A0
const idVehicle* idInfoGarageBay::GetVehicle() const { return vehicle; }

// Retail: 0x82C63B60
idTownGarageManager::idTownGarageManager()
    : garage(idInfoGarageBay::GARAGE_NONE), focusBay(nullptr),
      newRotateEnt(nullptr), effectEnt(nullptr), timeToRotate(450),
      rotationStepAmount(45.0f), rotationSound(nullptr), stopSound(nullptr),
      wastelandMultiSpawn(nullptr), cantEnterSound(nullptr),
      currentState(GARAGESTATE_NORMAL), currentVehicleIndex(-1),
      nextVehicleIndex(-1), spawnCalled(false), shouldDeactivateCars(false),
      needStopSound(false), rotationStartTime(0), spawnTime(-1) {}

// Retail: 0x82C61C98
void idTownGarageManager::ActivateCars() {
    shouldDeactivateCars = false;
    for (int index = 0; index < vehicles.Num(); ++index) {
        Services().SetVehicleActive(vehicles[index].vehicle, true);
    }
}

// Retail: 0x82C61D18
void idTownGarageManager::DeactivateCars() {
    for (int index = 0; index < vehicles.Num(); ++index) {
        Services().SetVehicleActive(vehicles[index].vehicle, false);
    }
    BecomeInactive(1);
}

// Retail: 0x82C62928
void idTownGarageManager::Think() {
    if (!spawnCalled || !shouldDeactivateCars) {
        BecomeInactive(1);
        return;
    }
    for (int index = 0; index < vehicles.Num(); ++index) {
        if (!Services().IsVehicleAtRest(vehicles[index].vehicle)) return;
    }
    DeactivateCars();
}

// Retail: 0x82C62A08
bool idTownGarageManager::ProperSetup() {
    return focusBay != nullptr && newRotateEnt != nullptr;
}

// Retail: 0x82C62A60
void idTownGarageManager::SetupAndMoveOffscreen() {
    if (currentVehicleIndex < 0 || currentVehicleIndex >= vehicles.Num()) {
        return;
    }
    currentState = GARAGESTATE_MOVINGTOHIDE;
    rotationStartTime = Services().GetGameMilliseconds();
    needStopSound = true;
    if (rotationSound != nullptr) Services().PlayGarageSound(*this,
        rotationSound);
    Services().SetVehicleActive(vehicles[currentVehicleIndex].vehicle,
        false);
}

// Retail: 0x82C63DF0
bool idTownGarageManager::GotoNextTarget() {
    const int count = vehicles.Num();
    if (count <= 1) return false;
    const int base = nextVehicleIndex >= 0
        ? nextVehicleIndex : currentVehicleIndex;
    nextVehicleIndex = (base + 1) % count;
    if (currentState == GARAGESTATE_NORMAL) SetupAndMoveOffscreen();
    return true;
}

// Retail: 0x82C63EA0
bool idTownGarageManager::GotoPreviousTarget() {
    const int count = vehicles.Num();
    if (count <= 1) return false;
    const int base = nextVehicleIndex >= 0
        ? nextVehicleIndex : currentVehicleIndex;
    nextVehicleIndex = (base + count - 1) % count;
    if (currentState == GARAGESTATE_NORMAL) SetupAndMoveOffscreen();
    return true;
}

// Retail: 0x82C63F48
void idTownGarageManager::SetupAndMoveBackOn() {
    if (currentVehicleIndex >= 0 && currentVehicleIndex < vehicles.Num()) {
        Services().TeleportVehicle(vehicles[currentVehicleIndex].vehicle,
            spawnPosition, spawnOrientation);
        if (vehicles[currentVehicleIndex].shadowEntity != nullptr) {
            vehicles[currentVehicleIndex].shadowEntity->Teleport(
                spawnPosition, idAngles(0.0f, 0.0f, 0.0f));
        }
    }
    if (nextVehicleIndex < 0 || nextVehicleIndex >= vehicles.Num()) return;
    currentVehicleIndex = nextVehicleIndex;
    nextVehicleIndex = -1;
    currentState = GARAGESTATE_MOVINGTORETURN;
    rotationStartTime = Services().GetGameMilliseconds();
    if (rotationSound != nullptr) Services().PlayGarageSound(*this,
        rotationSound);
}

// Retail: 0x82C64140
void idTownGarageManager::SetSystemRotation(const float angle) {
    Services().RotateGarageSystem(angle, spawnPosition, spawnOrientation);
    if (currentVehicleIndex >= 0 && currentVehicleIndex < vehicles.Num()
            && focusBay != nullptr) {
        Services().TeleportVehicle(vehicles[currentVehicleIndex].vehicle,
            focusBay->spawnPosition, focusBay->spawnOrientation);
    }
}

// Retail: 0x82C646A8
void idTownGarageManager::StopMovingEffects() {
    if (stopSound != nullptr && needStopSound) {
        Services().PlayGarageSound(*this, stopSound);
        needStopSound = false;
    }
    Services().ActivateGarageEffect(effectEnt, this);
}

// Retail: 0x82C64768
void idTownGarageManager::Update() {
    if (currentState == GARAGESTATE_NORMAL) return;
    const int elapsed = Services().GetGameMilliseconds() - rotationStartTime;
    const float fraction = timeToRotate > 0
        ? (std::min)(1.0f, static_cast<float>(elapsed) / timeToRotate)
        : 1.0f;
    const float angle = currentState == GARAGESTATE_MOVINGTOHIDE
        ? fraction * rotationStepAmount
        : (1.0f - fraction) * rotationStepAmount;
    SetSystemRotation(angle);
    if (fraction < 1.0f) return;
    if (currentState == GARAGESTATE_MOVINGTOHIDE) {
        SetupAndMoveBackOn();
    } else if (nextVehicleIndex >= 0
            && currentVehicleIndex != nextVehicleIndex) {
        SetupAndMoveOffscreen();
    } else {
        nextVehicleIndex = -1;
        currentState = GARAGESTATE_NORMAL;
        StopMovingEffects();
    }
}

// Retail: 0x82C64E00
bool idTownGarageManager::SetUpVehiclesForView() {
    if (vehicles.Num() <= 0 || !ProperSetup()) return false;
    if (currentVehicleIndex < 0 || currentVehicleIndex >= vehicles.Num()) {
        currentVehicleIndex = 0;
    }
    ActivateCars();
    SetSystemRotation(0.0f);
    return true;
}

// Retail: 0x82C64EE8
idVehicleKey* idTownGarageManager::GetCurrentKey() {
    if (vehicles.Num() <= 0) return nullptr;
    if (currentVehicleIndex < 0 || currentVehicleIndex >= vehicles.Num()) {
        SetUpVehiclesForView();
        return nullptr;
    }
    const int index = nextVehicleIndex >= 0
        ? nextVehicleIndex : currentVehicleIndex;
    return Services().GetVehicleKey(vehicles[index].vehicle);
}

// Retail: 0x82C65460
void idTownGarageManager::SpawnVehicles(idPlayer* player) {
    spawnCalled = true;
    spawnTime = Services().GetGameMilliseconds();
    shouldDeactivateCars = true;
    BecomeActive(1);
    idList<idVehicleKey*, 5> keys;
    Services().GetPlayerVehicleKeys(player, garage, keys);
    for (int keyIndex = keys.Num() - 1; keyIndex >= 0; --keyIndex) {
        idVehicleKey* key = keys[keyIndex];
        bool duplicate = false;
        for (int vehicleIndex = 0; vehicleIndex < vehicles.Num();
                ++vehicleIndex) {
            if (Services().GetVehicleKey(vehicles[vehicleIndex].vehicle)
                    == key) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) continue;
        idVehicle* vehicle = Services().SpawnPlayerVehicle(key,
            spawnPosition, spawnOrientation);
        if (vehicle == nullptr) {
            Services().ReportWarning("failed to spawn garage vehicle");
            continue;
        }
        Services().PrepareGarageVehicle(vehicle, key,
            focusBay != nullptr ? focusBay->spawnOrientation
                                : spawnOrientation);
        vehicleInfo_t runtime;
        runtime.vehicle = vehicle;
        for (int shadowIndex = 0; shadowIndex < shadowInfoList.Num();
                ++shadowIndex) {
            if (shadowInfoList[shadowIndex].keyDecl
                    == static_cast<const void*>(key)) {
                runtime.shadowEntity =
                    shadowInfoList[shadowIndex].shadowEntity;
                break;
            }
        }
        vehicles.Append(runtime);
        if (Services().VehicleKeyIsSelected(key)) {
            currentVehicleIndex = vehicles.Num() - 1;
        }
        Services().ClearVehicleKeySelection(key);
    }
    DeactivateCars();
}

// Retail: 0x82C65CC8
idInfoPath::idInfoPath()
    : focus(nullptr), stopTime(0.0f), turnEarly(false),
      alignmentTolerance(1.0f), lookAtNextPoint(false), alignToNode(false),
      keepFocusInView(false), interactionPoint(true), abortForSearch(true),
      walkState(0), standState(0), sitState(0), walkMod(0), runMod(0),
      aasType(0) {}

// Retail: 0x82C61480
int idInfoPath::ChoosePlayerLeftAnim() const {
    int available[32];
    int availableCount = 0;
    int totalWeight = 0;
    const int now = Services().GetGameMilliseconds();
    for (int index = 0; index < playerLeftAnims.Num()
            && availableCount < 32; ++index) {
        const anim_t& animation = playerLeftAnims[index];
        if (animation.nextPlayTime <= now && animation.weight > 0) {
            available[availableCount++] = index;
            totalWeight += animation.weight * 100;
        }
    }
    if (availableCount == 0 || totalWeight <= 0) return -1;
    const int choice = Services().RandomInt(totalWeight);
    int accumulated = 0;
    for (int availableIndex = 0; availableIndex < availableCount;
            ++availableIndex) {
        const int index = available[availableIndex];
        anim_t& animation = const_cast<anim_t&>(playerLeftAnims[index]);
        accumulated += animation.weight * 100;
        if (choice < accumulated) {
            animation.nextPlayTime = now
                + static_cast<int>(animation.timeBetween * 1000.0f);
            return index;
        }
    }
    return -1;
}

// Retail: 0x82C62310
const idEntity* idInfoPath::GetFocus() const { return focus; }

// Retail: 0x82C631E8
bool idInfoPath::StopAtPoint(const idAI2* ai) const {
    for (int index = 0; index < actionScript.Num(); ++index) {
        const char* eventName = actionScript[index].eventName.c_str();
        if (Services().ActionBlocks(ai, eventName)
                && Services().ActionStopsMovement(ai, eventName)) {
            return true;
        }
    }
    return false;
}

// Retail: 0x82C632D8
const idInfoPath* idInfoPath::GetNextPathPoint() const {
    if (targets.Num() <= 0) return nullptr;
    const int index = Services().RandomInt(targets.Num());
    return dynamic_cast<const idInfoPath*>(targets[index]);
}

// Retail: 0x82C66260
void idInfoPath::Spawn() {
    if (!Services().LoadAAS(aasType)
            || !Services().IsAASPointReachable(aasType, spawnPosition)) {
        Services().ReportWarning("info path is outside its AAS");
    }
    if (stopTime > 0.0f) {
        idInfoPathAction idle;
        idle.eventName = "action_Idle";
        idle.durationMilliseconds = static_cast<int>(stopTime * 1000.0f);
        actionScript.Insert(idle, 1);
    }
}

// Retail header: 0x82518110
idInfoAmbient::idInfoAmbient() {
    idColor* colors[] = {
        &ambientOverrideColors.editorEast,
        &ambientOverrideColors.editorWest,
        &ambientOverrideColors.editorNorth,
        &ambientOverrideColors.editorSouth,
        &ambientOverrideColors.editorUp,
        &ambientOverrideColors.editorDown
    };
    for (int index = 0; index < 6; ++index) {
        colors[index]->Set(-1.0f, -1.0f, -1.0f, 1.0f);
    }
}

// Retail header: 0x82536780
idInfoDevComment::idInfoDevComment()
    : comment(), showAlways(true) {
    textColor = idColor::colorDefault;
}

// Retail: 0x82C61618
const char* GetInfoDevComment(const char* entityName) {
    idInfoDevComment* comment = dynamic_cast<idInfoDevComment*>(
        idInfo::Services().FindEntity(entityName));
    return comment != nullptr ? comment->comment.c_str() : nullptr;
}
