#include "game/entities/actionnode.h"

#include "idlib/lib_print.h"

namespace {
idActionNodeServices defaultActionNodeServices;
idActionNodeServices* activeActionNodeServices =
    &defaultActionNodeServices;
}

void idActionNode::SetServices(idActionNodeServices* services) {
    activeActionNodeServices = services == nullptr
        ? &defaultActionNodeServices : services;
}

idActionNodeServices& idActionNode::Services() {
    return *activeActionNodeServices;
}

// EA 0x82BE1900
bool idActionNode::IsActionNodeAvailable(const idEntity* user) const {
    if (!isActive) {
        return false;
    }

    const bool isReserved = Services().ResolveAnimatedEntity(
        reservingEntity.GetSpawnId()) != nullptr;
    if (!touching.IsEmpty() || isReserved) {
        const idEntity* soleToucher = touching.Num() == 1
            ? Services().ResolveEntity(touching[0].GetSpawnId()) : nullptr;
        if (touching.Num() != 1 || soleToucher != user) {
            for (int index = 0; index < touching.Num(); ++index) {
                const idEntity* toucher = Services().ResolveEntity(
                    touching[index].GetSpawnId());
                if (toucher == nullptr || !Services().IsDead(toucher)) {
                    return false;
                }
            }
        }
    }
    return true;
}

// EA 0x82BE1A38
eventVoid idActionNode::Event_Untouch(idEntity* toucher,
        const int clipModelId) {
    (void)clipModelId;
    const int spawnId = toucher == nullptr
        ? 0x1FFF : Services().GetSpawnId(toucher);
    for (int index = 0; index < touching.Num(); ++index) {
        if (touching[index].GetSpawnId() == spawnId) {
            touching.RemoveIndex(index);
            break;
        }
    }
    return {};
}

// EA 0x82BE1AE0
bool idActionNode::ReserveActionNode(idAnimatedEntity* user) {
    if (!IsActionNodeAvailable(reinterpret_cast<idEntity*>(user))) {
        return false;
    }
    reservingEntity.SetSpawnId(user == nullptr
        ? 0x1FFF
        : Services().GetSpawnId(reinterpret_cast<idEntity*>(user)));
    return true;
}

// EA 0x82BE1B68
bool idActionNode::LeaveActionNode(idAnimatedEntity* user) {
    if (Services().ResolveAnimatedEntity(
            reservingEntity.GetSpawnId()) != user) {
        return false;
    }
    reservingEntity.Invalidate();
    return true;
}

// EA 0x82BE1C00
void idActionNode::DisableClip() {
    Services().SetClipEnabled(*this, false, 0);
    reservingEntity.Invalidate();
    touching.Clear();
}

// EA 0x82BE1CA8
void idActionNode::OnActivate(idEntity* activator) {
    (void)activator;
    isActive = !isActive;
    if (!isActive) {
        DisableClip();
    } else {
        Services().SetClipEnabled(*this, true, 0x4000);
    }
}

// EA 0x82BE1DA8
void idActionNode::Spawn() {
    if (anims.Num() >= 32) {
        idLibPrint::Error("Action node '%s' has more than %d anims.",
            name.c_str(), 32);
    }

    if (shouldCheckAAS) {
        idStr aasName;
        const actionNodeAASResult_t aasResult = Services().ValidateAAS(
            aasType, spawnPosition, aasName);
        if (aasResult == ACTIONNODE_AAS_LOAD_FAILED) {
            idLibPrint::Warning(
                "idActionNode '%s' - failed to load appropriate AAS.",
                name.c_str());
        } else if (aasResult == ACTIONNODE_AAS_OUTSIDE) {
            idLibPrint::Warning("idActionNode '%s' is outside of aas %s'",
                name.c_str(), aasName.c_str());
        }
    }

    if (startOff) {
        isActive = false;
    }

    idBounds clipBounds;
    clipBounds[0] = idVec3(
        clipModelInfo.size.x * -0.5f,
        clipModelInfo.size.y * -0.5f,
        0.0f);
    clipBounds[1] = idVec3(
        clipModelInfo.size.x * 0.5f,
        clipModelInfo.size.y * 0.5f,
        clipModelInfo.size.z);

    // EA 0x82BE20A8: the retail exception cleanup freed the just-allocated
    // clip model. ConfigureClip owns that allocation transaction here, so a
    // failed construction cannot publish or leak a clip model.
    Services().ConfigureClip(*this, clipBounds, spawnPosition,
        spawnOrientation, 1.0f, 0x4000, 0);
    if (!isActive) {
        DisableClip();
    }
}

// EA 0x82BE20D8
eventVoid idActionNode::Event_Touch(idEntity* toucher,
        const int clipModelId) {
    (void)clipModelId;
    if (toucher != nullptr &&
            (Services().IsPlayer(toucher)
                || (canBeBlockedByAI && Services().IsAI(toucher)))) {
        const int spawnId = Services().GetSpawnId(toucher);
        bool found = false;
        for (int index = 0; index < touching.Num(); ++index) {
            if (touching[index].GetSpawnId() == spawnId) {
                found = true;
                break;
            }
        }
        if (!found) {
            touching.Append(idEntityPtr<idEntity>(spawnId));
        }
    }
    return {};
}

// EA 0x82BE21C8
idActionNode::idActionNode()
    : name()
    , spawnPosition(0.0f, 0.0f, 0.0f)
    , spawnOrientation(1.0f)
    , clipModelInfo{idVec3(0.0f, 0.0f, 0.0f)}
    , reservingEntity()
    , groupName()
    , actionScript(0)
    , standState(STANDSTATE_DEFAULT)
    , sitState(SITSTATE_DEFAULT)
    , posture(POSTURE_STANDING)
    , anims(0)
    , shouldCheckAAS(true)
    , canBeBlockedByAI(false)
    , aasType(AAS_MONSTER48)
    , startOff(false)
    , isActive(true)
    , reachedPointTolerance(0.1f)
    , touching(0) {
}

// EA 0x82BE2390
idActionNode::~idActionNode() = default;
