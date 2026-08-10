#pragma once

#include "../../../engine/decls/decltypeinfo.h"

enum vehicleAttack_t : int {
    ATTACK_IDLE = 0,
    ATTACK_RAM_ENEMY,
    ATTACK_RANGE_SHOOT,
    ATTACK_STRAFE_SHOOT,
    ATTACK_CIRCLE_SHOOT,
    ATTACK_CHASE_REAR_BUMP,
    ATTACK_CHASE_SIDE_BUMP,
    ATTACK_CHASE_SHOOT,
    ATTACK_CHASE_SIDE_SHOOT,
    ATTACK_CHASE_BYPASS,
    ATTACK_HITANDRUN,
    ATTACK_WAYPOINT_TAG,
    ATTACK_FIRE_WEAPON,
    ATTACK_RANDOM_FOLLOW,
    ATTACK_CHASE_POWERTURN_SHOOT,
    ATTACK_RC_BOMB_OUTSIDE,
    ATTACK_RC_BOMB_RACE,
    ATTACK_RC_BOMB_INSIDE,
    ATTACK_FREE_FORM,
    ATTACK_MP_STOP,
    ATTACK_MP_RAM,
    ATTACK_MP_CHASE,
    ATTACK_MP_PICKUP_ITEM,
    ATTACK_MP_REPAIR_STATION,
    ATTACK_MP_CTF_CAPTURE_FLAG,
    ATTACK_MP_CTF_DEFEND_BASE,
    ATTACK_MP_CTF_ENEMY_FLAG_TO_BASE,
    ATTACK_MP_CTF_DEFEND_TEAMMATE,
    ATTACK_MP_CTF_FIND_LOST_FLAG,
    ATTACK_MP_CTF_GET_FLAG_FROM_ENEMY,
    ATTACK_NONE
};

struct vehicleAttackParams_t {
    int attempts;
    float range;
    float time;
    float minSpeed;
    float maxSpeed;
};

class idDeclVehicleAttack : public idDeclTypeInfo {
public:
    // Retail symbol: ??0idDeclVehicleAttack@@QAA@XZ
    // EA: 0x82BCC878, RVA: 0x00BCC878
    idDeclVehicleAttack()
        : state(ATTACK_NONE)
        , params{-1, -1.0f, -1.0f, -1.0f, -1.0f} {
    }

    ~idDeclVehicleAttack() override = default;

    // Retail symbol: ?GetDeclInfo@idDeclVehicleAttack@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BCC8E0, RVA: 0x00BCC8E0
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    vehicleAttack_t state;
    vehicleAttackParams_t params;

    static idDeclInfoTemplate<idDeclVehicleAttack> resourceList;
};

static_assert(sizeof(vehicleAttackParams_t) == 20,
    "Recovered vehicle-attack parameter layout changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclVehicleAttack) == 88,
    "Recovered vehicle-attack declaration ABI changed");
#endif
