#pragma once

#include "decls/decltypeinfo.h"
#include "gamelib/class.h"
#include "gamelib/timeline/timelineeventdata.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/text/str.h"
#include "models/skeletalanimation/animation.h"

class idDeclMD6;

enum damageDirection_t : int {
    DAMAGEDIR_NONE = 0,
    DAMAGEDIR_FRONT = 1,
    DAMAGEDIR_BACK = 2,
    DAMAGEDIR_LEFT = 3,
    DAMAGEDIR_RIGHT = 4,
    DAMAGEDIR_FRONTLEFT = 5,
    DAMAGEDIR_FRONTRIGHT = 6,
    DAMAGEDIR_BACKLEFT = 7,
    DAMAGEDIR_BACKRIGHT = 8,
    DAMAGEDIR_MAX = 9
};

enum invalidJointIndex_t : int;
using idTwitchPainJointIndex = idIndex<short, invalidJointIndex_t>;

class idTwitchPain_JointGroup : public idClass {
public:
    idTypeInfo* GetType() override { return nullptr; }

    idStr jointGroupName;
    idAnimAliasRef aliasName;
    aliasHandle_t aliasHandle;
};

class idTwitchPain_DamageDirectionGroup : public idClass {
public:
    idTypeInfo* GetType() override { return nullptr; }

    damageDirection_t damageDir;
    idList<idTwitchPain_JointGroup, 5> jointGroups;
};

class idTwitchPain_WeaponGroup : public idClass {
public:
    idTwitchPain_WeaponGroup();
    idTypeInfo* GetType() override { return nullptr; }

    idStr weaponPrefix;
    idList<idTwitchPain_DamageDirectionGroup, 5> damageDirectionGroups;
};

class idDeclTwitchPain : public idDeclTypeInfo {
public:
    idDeclTwitchPain();
    ~idDeclTwitchPain() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    void Parse(idParser* parser) override;

    aliasHandle_t GetTwitchPainAliasHandle(
        const idDeclMD6* forModelDef, const char* weaponPrefix,
        damageDirection_t damageDir, const char* jointGroupName) const;
    aliasHandle_t GetTwitchPainAliasHandle(
        const idDeclMD6* forModelDef, const char* weaponPrefix,
        damageDirection_t damageDir,
        const idTwitchPainJointIndex& jointIndex) const;
    void StrongLoadAliasesForModelDef(const idDeclMD6* declaration) const;

    idList<idTwitchPain_WeaponGroup, 5> weaponGroups;

    static idDeclInfoTemplate<idDeclTwitchPain> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTwitchPain_JointGroup) == 72,
    "Recovered twitch-pain joint-group ABI changed");
static_assert(sizeof(idTwitchPain_DamageDirectionGroup) == 24,
    "Recovered twitch-pain direction-group ABI changed");
static_assert(sizeof(idTwitchPain_WeaponGroup) == 52,
    "Recovered twitch-pain weapon-group ABI changed");
static_assert(sizeof(idDeclTwitchPain) == 80,
    "Recovered twitch-pain declaration ABI changed");
#endif
