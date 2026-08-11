#include "game/decls/decltwitchpain.h"

#include "idlib/lib_print.h"
#include "models/skeletalanimation/declmd6.h"

idDeclInfoTemplate<idDeclTwitchPain> idDeclTwitchPain::resourceList(
    "twitchPain", "idDeclTwitchPain", "tdef");

namespace {
const char* const damageDirectionNames[DAMAGEDIR_MAX] = {
    "none", "front", "back", "left", "right",
    "frontLeft", "frontRight", "backLeft", "backRight"
};

const char* SafeDirectionName(const damageDirection_t direction) {
    const int index = static_cast<int>(direction);
    return index >= 0 && index < DAMAGEDIR_MAX
        ? damageDirectionNames[index] : "invalid";
}
}

// EA 0x82519D70
idTwitchPain_WeaponGroup::idTwitchPain_WeaponGroup()
    : weaponPrefix()
    , damageDirectionGroups() {
}

// EA 0x82BCB680
void idDeclTwitchPain::Parse(idParser* const parser) {
    idDeclTypeInfo::Parse(parser);

    for (int weaponIndex = 0; weaponIndex < weaponGroups.Num(); ++weaponIndex) {
        idTwitchPain_WeaponGroup& weapon = weaponGroups[weaponIndex];
        for (int directionIndex = 0;
                directionIndex < weapon.damageDirectionGroups.Num();
                ++directionIndex) {
            idTwitchPain_DamageDirectionGroup& direction =
                weapon.damageDirectionGroups[directionIndex];
            for (int jointIndex = 0;
                    jointIndex < direction.jointGroups.Num(); ++jointIndex) {
                idTwitchPain_JointGroup& joint =
                    direction.jointGroups[jointIndex];
                joint.aliasHandle = animation != nullptr
                    ? animation->RegisterAlias(nullptr, joint.aliasName.c_str())
                    : aliasHandle_t();
                if (!joint.aliasHandle.IsValid()) {
                    idLibPrint::Warning(
                        "idDeclTwitchPain '%s' specifies invalid alias '%s' "
                        "for pain %s:%s:%s",
                        GetName(), joint.aliasName.c_str(),
                        weapon.weaponPrefix.c_str(),
                        SafeDirectionName(direction.damageDir),
                        joint.jointGroupName.c_str());
                }
            }
        }
    }
}

// EA 0x82BCB7E8
aliasHandle_t idDeclTwitchPain::GetTwitchPainAliasHandle(
        const idDeclMD6*, const char* const requestedWeaponPrefix,
        const damageDirection_t requestedDirection,
        const char* const requestedJointGroupName) const {
    for (int weaponIndex = 0; weaponIndex < weaponGroups.Num(); ++weaponIndex) {
        const idTwitchPain_WeaponGroup& weapon = weaponGroups[weaponIndex];
        if (idStr::Icmp(requestedWeaponPrefix,
                weapon.weaponPrefix.c_str()) != 0) {
            continue;
        }
        for (int directionIndex = 0;
                directionIndex < weapon.damageDirectionGroups.Num();
                ++directionIndex) {
            const idTwitchPain_DamageDirectionGroup& direction =
                weapon.damageDirectionGroups[directionIndex];
            if (direction.damageDir != requestedDirection) {
                continue;
            }
            for (int jointIndex = 0;
                    jointIndex < direction.jointGroups.Num(); ++jointIndex) {
                const idTwitchPain_JointGroup& joint =
                    direction.jointGroups[jointIndex];
                if (idStr::Icmp(requestedJointGroupName,
                        joint.jointGroupName.c_str()) == 0) {
                    return joint.aliasHandle;
                }
            }
        }
    }
    return aliasHandle_t();
}

// EA 0x82BCB8F8
aliasHandle_t idDeclTwitchPain::GetTwitchPainAliasHandle(
        const idDeclMD6* const forModelDef,
        const char* const weaponPrefix,
        const damageDirection_t damageDirection,
        const idTwitchPainJointIndex& jointIndex) const {
    if (forModelDef == nullptr) {
        return aliasHandle_t();
    }

    const idJointGroup* jointGroup =
        forModelDef->jointGroupCollection.GetJointGroupForJoint(
            idJointGroup::JOINTGROUP_TWITCH, jointIndex);
    if (jointGroup != nullptr) {
        return GetTwitchPainAliasHandle(forModelDef, weaponPrefix,
            damageDirection, jointGroup->groupName.c_str());
    }

    idLibPrint::Warning(
        "%s: missing twitch pain joint group for joint '%s'",
        forModelDef->GetName(), forModelDef->GetJointName(jointIndex));
    return aliasHandle_t();
}

// EA 0x82BCB9C8
idDeclTwitchPain::idDeclTwitchPain()
    : weaponGroups() {
}

// EA 0x82BCBB68
void idDeclTwitchPain::StrongLoadAliasesForModelDef(
        const idDeclMD6* const declaration) const {
    if (animation == nullptr) {
        return;
    }
    for (int weaponIndex = 0; weaponIndex < weaponGroups.Num(); ++weaponIndex) {
        const idTwitchPain_WeaponGroup& weapon = weaponGroups[weaponIndex];
        for (int directionIndex = 0;
                directionIndex < weapon.damageDirectionGroups.Num();
                ++directionIndex) {
            const idTwitchPain_DamageDirectionGroup& direction =
                weapon.damageDirectionGroups[directionIndex];
            for (int jointIndex = 0;
                    jointIndex < direction.jointGroups.Num(); ++jointIndex) {
                const idTwitchPain_JointGroup& joint =
                    direction.jointGroups[jointIndex];
                if (!joint.aliasName.IsEmpty()) {
                    animation->StrongLoadAlias(
                        declaration, joint.aliasHandle);
                }
            }
        }
    }
}
