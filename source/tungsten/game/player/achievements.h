#pragma once

#include "achievementids.h"
#include "../decls/declachievements.h"
#include "../../../engine/gamelib/class.h"
#include "../../../shared/idlib/containers/array.h"
#include "../../../shared/idlib/containers/staticlist.h"

class idLocalUser;
struct achievementDescription_t;

class idAchievement : public idClass {
public:
    struct eventAchievementInfo_t {
        int count;
    };

    struct raceAchievementInfo_t {
        raceMemoryPlace_t place;
    };

    idTypeInfo* GetType() override;
    ~idAchievement() override;

    // Retail symbol: ?IsFulfilled@idAchievement@@QBA_NXZ
    // EA: 0x82DEFD10, RVA: 0x00DEFD10
    bool IsFulfilled() const;

    const idDeclAchievement* decl;
    bool itemsFulfilled;
    bool jobsFulfilled;
    bool triggersFulfilled;
    bool eventsFulfilled;
    bool racesFulfilled;
    bool achievementsFulfilled;
    bool triggersActivated[6];
    bool achievementsGained[49];
    eventAchievementInfo_t eventInfo[30];
    raceAchievementInfo_t racesInfo[30];
};

class idAchievementSystem {
public:
    virtual ~idAchievementSystem();
    virtual void Init();
    virtual void Shutdown();
    virtual bool IsInitialized();
    virtual void RegisterLocalUser(idLocalUser* user);
    virtual void RemoveLocalUser(idLocalUser* user);
    virtual void AchievementUnlock(idLocalUser* user, int achievement);
    virtual void AchievementLock(idLocalUser* user, int achievement);
    virtual void AchievementLockAll(idLocalUser* user, int achievement);
    virtual void Pump();
    virtual void Reset(idLocalUser* user);
    virtual void Cancel(idLocalUser* user);
    virtual bool GetAchievementDescription(idLocalUser* user,
        int achievement, achievementDescription_t* description);
    virtual bool GetRequiredStorage(unsigned __int64* requiredStorage);
    virtual bool GetAchievementState(idLocalUser* user,
        idArray<bool, 128>* state);
    virtual bool SetAchievementState(idLocalUser* user,
        idArray<bool, 128>* state);

    idStaticList<idLocalUser*, 2> users;
};

#if defined(_XBOX)
class idAchievementSystemXbox : public idAchievementSystem {
public:
    enum state_t : int {
        STATE_WRITING = 1
    };

    struct achievementAction_t {
        idStaticList<XUSER_ACHIEVEMENT, 128> pendingAchievments;
        idStaticList<XUSER_ACHIEVEMENT, 128> achievements;
        state_t state;
        _XOVERLAPPED overlapped;
    };

    ~idAchievementSystemXbox() override;
    void Init() override;
    void Shutdown() override;
    bool IsInitialized() override;
    void RegisterLocalUser(idLocalUser* user) override;
    void RemoveLocalUser(idLocalUser* user) override;
    void AchievementUnlock(idLocalUser* user, int achievement) override;
    void AchievementLock(idLocalUser* user, int achievement) override;
    void AchievementLockAll(idLocalUser* user, int achievement) override;
    void Pump() override;
    void Reset(idLocalUser* user) override;
    void Cancel(idLocalUser* user) override;
    bool GetAchievementDescription(idLocalUser* user, int achievement,
        achievementDescription_t* description) override;
    bool GetRequiredStorage(unsigned __int64* requiredStorage) override;
    bool GetAchievementState(idLocalUser* user,
        idArray<bool, 128>* state) override;
    bool SetAchievementState(idLocalUser* user,
        idArray<bool, 128>* state) override;

    idArray<achievementAction_t, 2> achievementAction;
};
#endif

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAchievement) == 312,
    "Recovered runtime achievement ABI changed");
#endif
