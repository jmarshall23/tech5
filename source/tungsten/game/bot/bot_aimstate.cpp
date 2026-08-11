#include "bot_aimstate.h"

#include <cmath>
#include <cstring>

namespace {
idBotAimStateServices* g_aimServices = nullptr;

constexpr int INVALID_ENTITY_SPAWN_ID = 0x1FFF;
constexpr float RAD_TO_DEG = 57.295779513082320876f;

float NormalizeDelta180(float angle) {
    angle = std::fmod(angle, 360.0f);
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    if (angle > 180.0f) {
        angle -= 360.0f;
    }
    return angle;
}

int FindFreeAimRequest(const idBotAimState& state) {
    for (int index = 0; index < 4; ++index) {
        if (state.aimRequests[index].aimUserName.Length() == 0) {
            return index;
        }
    }
    return -1;
}
} // namespace

void Tungsten_SetBotAimStateServices(
        idBotAimStateServices* const services) {
    g_aimServices = services;
}

// Header retail symbol: ?Reset@BotAimRequest_t@idBotAimState@@QAAXXZ
// EA: 0x82B40160, RVA: 0x00B40160
void idBotAimState::BotAimRequest_t::Reset() {
    aimUserName.Clear();
    aimPriority = AIM_PRIORITY_NULL;
    aimType = AIM_TYPE_NONE;
    aimStartTimeInMS = 0;
    aimValidTimeInMS = 0;
    aimVector.Zero();
    aimEntity.Invalidate();
    aimPoint = AIMPOINT_MAX;
}

// Header retail symbol: ??0BotAimRequest_t@idBotAimState@@QAA@XZ
// EA: 0x82B401E0, RVA: 0x00B401E0
idBotAimState::BotAimRequest_t::BotAimRequest_t()
    : aimPriority(AIM_PRIORITY_NULL), aimType(AIM_TYPE_NONE),
      aimPoint(AIMPOINT_MAX), aimStartTimeInMS(0), aimValidTimeInMS(0),
      aimVector(0.0f, 0.0f, 0.0f), aimUserName(), aimEntity() {
    Reset();
}

// Retail symbol: ??1idBotAimState@@QAA@XZ
// EA: 0x82B3FE20, RVA: 0x00B3FE20
idBotAimState::~idBotAimState() = default;

// Retail symbol: ?GetAimOffset@idBotAimState@@IAAMM@Z
// EA: 0x82B3FE38, RVA: 0x00B3FE38
float idBotAimState::GetAimOffset(const float distToAimPointSqr) const {
    const int skill = g_aimServices != nullptr
        ? g_aimServices->GetAimSkill() : 1;
    float offset = 0.0f;
    switch (skill) {
        case 0:
            offset = distToAimPointSqr <= 65536.0f ? -0.4f : -0.55f;
            break;
        case 1:
            offset = distToAimPointSqr > 262144.0f ? 0.35f : 0.2f;
            break;
        case 2:
            offset = distToAimPointSqr <= 1048576.0f ? 0.15f : 0.2f;
            break;
        case 3:
            offset = distToAimPointSqr <= 3211264.0f ? 0.05f : 0.1f;
            break;
        default:
            break;
    }
    if (distToAimPointSqr < 16384.0f && skill > 0) {
        return 0.0f;
    }
    return offset;
}

// Retail symbol: ?CalcDesiredViewAngles@idBotAimState@@IAAXABVidVec3@@@Z
// EA: 0x82B3FF28, RVA: 0x00B3FF28
void idBotAimState::CalcDesiredViewAngles(
        const idVec3& desiredAimVector) {
    const float horizontalLength = std::sqrt(
        desiredAimVector.x * desiredAimVector.x
        + desiredAimVector.y * desiredAimVector.y);
    const float targetPitch = -std::atan2(
        desiredAimVector.z, horizontalLength) * RAD_TO_DEG;
    const float targetYaw = std::atan2(
        desiredAimVector.y, desiredAimVector.x) * RAD_TO_DEG;

    desiredViewAngles.pitch += NormalizeDelta180(
        targetPitch - desiredViewAngles.pitch) * 0.083f;
    desiredViewAngles.yaw += NormalizeDelta180(
        targetYaw - desiredViewAngles.yaw) * 0.125f;
    desiredViewAngles.roll = 0.0f;
}

// Retail symbol: ?FindIndexOfAimRequestUser@idBotAimState@@IAAHPBD@Z
// EA: 0x82B3FFF0, RVA: 0x00B3FFF0
int idBotAimState::FindIndexOfAimRequestUser(
        const char* const userName) const {
    for (int index = 0; index < 4; ++index) {
        const BotAimRequest_t& request = aimRequests[index];
        if (request.aimUserName.Length() != 0
                && idStr::Icmp(request.aimUserName.c_str(), userName) == 0) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ??0idBotAimState@@QAA@XZ
// EA: 0x82B40280, RVA: 0x00B40280
idBotAimState::idBotAimState()
    : currentAimPoint(0.0f, 0.0f, 0.0f), owner(nullptr),
      desiredViewAngles(0.0f, 0.0f, 0.0f), aimRequests() {
    // The retail constructor deliberately leaves request zero as a completely
    // zeroed sentinel after constructing all four records.
    std::memset(&aimRequests[0], 0, sizeof(aimRequests[0]));
}

// Retail symbol: ?Update@idBotAimState@@QAAXXZ
// EA: 0x82B40328, RVA: 0x00B40328
void idBotAimState::Update() {
    if (owner == nullptr || g_aimServices == nullptr) {
        return;
    }

    desiredViewAngles = g_aimServices->GetOwnerViewAngles(*owner);
    int selectedIndex = -1;
    botAimPriority_t selectedPriority = AIM_PRIORITY_NULL;
    for (int index = 0; index < 4; ++index) {
        const BotAimRequest_t& request = aimRequests[index];
        if (request.aimUserName.Length() != 0
                && request.aimPriority > selectedPriority) {
            selectedIndex = index;
            selectedPriority = request.aimPriority;
        }
    }
    if (selectedIndex == -1) {
        return;
    }

    const idVec3 eyePosition = g_aimServices->GetOwnerEyePosition(*owner);
    const BotAimRequest_t& request = aimRequests[selectedIndex];
    idVec3 desiredAimVector(0.0f, 0.0f, 0.0f);
    bool hasAimVector = false;

    switch (request.aimType) {
        case AIM_TYPE_ENTITY: {
            const idEntity* const entity =
                g_aimServices->ResolveEntitySpawnId(
                    request.aimEntity.GetSpawnId());
            if (entity == nullptr) {
                break;
            }

            aimPoint_t selectedAimPoint = request.aimPoint;
            if (selectedAimPoint == AIMPOINT_BEST) {
                const idVec3 entityOrigin =
                    g_aimServices->GetEntityOrigin(*entity);
                const float deltaX = entityOrigin.x - eyePosition.x;
                const float deltaY = entityOrigin.y - eyePosition.y;
                selectedAimPoint = deltaX * deltaX + deltaY * deltaY
                    >= 36864.0f ? AIMPOINT_TORSO : AIMPOINT_HEAD;
            }

            idVec3 point;
            if (!g_aimServices->GetEntityAimPoint(
                    *entity, selectedAimPoint, point)) {
                break;
            }
            if (g_aimServices->GetAimSkill() < 4) {
                const float deltaX = point.x - eyePosition.x;
                const float deltaY = point.y - eyePosition.y;
                point = point + g_aimServices->GetEntityLinearVelocity(*entity)
                    * GetAimOffset(deltaX * deltaX + deltaY * deltaY);
            }
            currentAimPoint = point;
            desiredAimVector = point - eyePosition;
            hasAimVector = true;
            break;
        }
        case AIM_TYPE_POSITION:
            currentAimPoint = request.aimVector;
            desiredAimVector = request.aimVector - eyePosition;
            hasAimVector = true;
            break;
        case AIM_TYPE_DIRECTION:
            currentAimPoint = eyePosition + request.aimVector;
            desiredAimVector = request.aimVector;
            hasAimVector = true;
            break;
        default:
            break;
    }

    if (hasAimVector && g_aimServices->ShouldShowAimPoint(*owner)) {
        g_aimServices->DebugAimPoint(currentAimPoint);
    }
    if (hasAimVector && desiredAimVector.LengthSqr() != 0.0f) {
        CalcDesiredViewAngles(desiredAimVector);
    }
}

// Retail symbol: ?AddAimRequestPosition@idBotAimState@@QAAXABVidVec3@@W4botAimPriority_t@@PBDM@Z
// EA: 0x82B40908, RVA: 0x00B40908
void idBotAimState::AddAimRequestPosition(const idVec3& pos,
        const botAimPriority_t priority, const char* const userName,
        const float aimTimeInSeconds) {
    int index = FindIndexOfAimRequestUser(userName);
    if (index == -1) {
        index = FindFreeAimRequest(*this);
    }
    if (index == -1) {
        return;
    }

    BotAimRequest_t& request = aimRequests[index];
    request.aimVector = pos;
    request.aimType = AIM_TYPE_POSITION;
    request.aimPoint = AIMPOINT_MAX;
    request.aimPriority = priority;
    request.aimUserName = userName;
    request.aimEntity.Invalidate();
    request.aimValidTimeInMS = static_cast<int>(
        1000.0f * aimTimeInSeconds);
    request.aimStartTimeInMS = g_aimServices != nullptr
        ? g_aimServices->GetScaledGameTime() : 0;
}

// Retail symbol: ?AddAimRequestEntity@idBotAimState@@QAAXPBVidEntity@@W4botAimPriority_t@@PBDW4aimPoint_t@@M@Z
// EA: 0x82B40A00, RVA: 0x00B40A00
void idBotAimState::AddAimRequestEntity(const idEntity* const entity,
        const botAimPriority_t priority, const char* const userName,
        const aimPoint_t requestedAimPoint,
        const float aimTimeInSeconds) {
    int index = FindIndexOfAimRequestUser(userName);
    if (index == -1) {
        index = FindFreeAimRequest(*this);
    }
    if (index == -1) {
        return;
    }

    BotAimRequest_t& request = aimRequests[index];
    request.aimVector.Zero();
    request.aimType = AIM_TYPE_ENTITY;
    request.aimPriority = priority;
    request.aimPoint = requestedAimPoint;
    request.aimUserName = userName;
    request.aimEntity.SetSpawnId(entity != nullptr && g_aimServices != nullptr
        ? g_aimServices->GetEntitySpawnId(entity)
        : INVALID_ENTITY_SPAWN_ID);
    request.aimValidTimeInMS = static_cast<int>(
        1000.0f * aimTimeInSeconds);
    request.aimStartTimeInMS = g_aimServices != nullptr
        ? g_aimServices->GetScaledGameTime() : 0;
}

// Retail symbol: ?ClearOldAimRequests@idBotAimState@@IAAXXZ
// EA: 0x82B40B30, RVA: 0x00B40B30
void idBotAimState::ClearOldAimRequests() {
    const int currentTime = g_aimServices != nullptr
        ? g_aimServices->GetScaledGameTime() : 0;
    for (int index = 0; index < 4; ++index) {
        BotAimRequest_t& request = aimRequests[index];
        if (request.aimUserName.Length() != 0
                && request.aimStartTimeInMS + request.aimValidTimeInMS
                    < currentTime) {
            request.Reset();
        }
    }
}

// Retail symbol: ?PostUpdate@idBotAimState@@QAAXXZ
// EA: 0x82B40BE8, RVA: 0x00B40BE8
void idBotAimState::PostUpdate() {
    ClearOldAimRequests();
}
