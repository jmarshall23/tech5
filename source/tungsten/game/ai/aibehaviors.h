#pragma once

#include "aimoveparms.h"
#include "cover/covercapabilities.h"

class idAI2;
class idAICover;
class idDeclAIBehavior;
class idDeclAIBehaviorEvents;
class idDeclAIBehaviorVO;
class idDeclAIBehaviorVOChains;
class idDeclTrackingParms;
class idWeapon;

enum coverOrientation_t : int {
    COVERORIENT_NONE = 0,
    COVERORIENT_LEFT = 1,
    COVERORIENT_FORWARD = 2,
    COVERORIENT_BACKWARD = 3
};

class idAIBehaviors {
public:
    idAIBehaviors();
    virtual ~idAIBehaviors() = default;

    bool GetWeaponCoverCapabilities(const idWeapon* weapon,
        posture_t coverPosture, coverOrientation_t coverOrientation,
        idCoverCapabilities& capabilities) const;
    bool HasCoverCapability(const idAI2* ai, posture_t coverPosture,
        coverOrientation_t coverOrientation,
        const idCoverCapabilities& coverCapabilities) const;
    coverOrientation_t FindBestCoverOrientation(
        const idAI2* ai, const idAICover& cover) const;

    const idDeclAIBehavior* decl;
    const idDeclAIBehaviorVO* declBehaviorVo;
    const idDeclAIBehaviorVOChains* declBehaviorVoChains;
    const idDeclAIBehaviorEvents* declBehaviorEvents;
    const idDeclTrackingParms* aimTrackingParms;
    const idDeclTrackingParms* lookTrackingParms;
    float avoidRadius;
};

int Tungsten_GetAIBehaviorWeaponCategory(const idWeapon& weapon);
const idAICoverCapabilities* Tungsten_GetAIBehaviorWeaponCoverSet(
    const idAIBehaviors& behaviors, coverOrientation_t orientation,
    int weaponCategory);
const idWeapon* Tungsten_GetAIBehaviorEquippedWeapon(const idAI2& ai);
bool Tungsten_IsAIBehaviorCoverPartiallyExposed(const idAICover& cover);
bool Tungsten_AIBehaviorUsesForwardCover(
    const idAIBehaviors& behaviors, const idAI2& ai);
bool Tungsten_AIBehaviorUsesBackwardCover(
    const idAIBehaviors& behaviors, const idAI2& ai);
posture_t Tungsten_GetAIBehaviorCoverPosture(const idAICover& cover);
void Tungsten_GetAIBehaviorCoverActions(
    const idAICover& cover, idCoverActions& actions);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIBehaviors) == 32,
    "Recovered AI behaviors ABI changed");
#endif
