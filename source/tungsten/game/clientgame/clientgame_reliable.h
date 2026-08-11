#pragma once

#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/math/matrix.h"

#include <cstdint>

class idBitMsg;
class idClientGame;
class idDeclAmmo;
class idDeclDamage;
class idDeclInventory;
class idDeclMetric;
class idDeclProjectile;
class idDeclThrowable;
class idDeclWeapon;
class idPresentable;
class idPresentablePlayer;
class idSerializer;

enum gameReliable_t : int {
    RELIABLE_SELECT_QUICK_WEAPON = 0x00,
    RELIABLE_SELECT_QUICK_AMMO = 0x01,
    RELIABLE_CLEAR_PICKUP = 0x02,
    RELIABLE_SCOPE_BLUR = 0x03,
    RELIABLE_CLEAR_ROCKET_TARGET = 0x04,
    RELIABLE_HIDE_MODAL_GUI = 0x05,
    RELIABLE_SELECT_PLAYER_LOADOUT = 0x06,
    RELIABLE_FORCE_SELECT_PLAYER_LOADOUT = 0x07,
    RELIABLE_PLAYER_SUICIDE = 0x08,
    RELIABLE_PLAYER_CHANGE_TEAMS = 0x09,
    RELIABLE_LOBBY_VOTE_TO_SKIP = 0x0A,
    RELIABLE_ACCEPT_RESPAWN_FROM_SPECTATE = 0x0B,
    RELIABLE_LOOT_AI = 0x0C,
    RELIABLE_RESTART_CHALLENGE = 0x0D,
    RELIABLE_SET_AFK = 0x0E,
    RELIABLE_SELECT_WEAPON_SLOT = 0x0F,
    RELIABLE_SCROLL_WEAPONS = 0x10,
    RELIABLE_SCROLL_QUICKUSE = 0x11,
    RELIABLE_SELECT_DISABLE_DPAD_WEAPON_SELECT = 0x12,
    RELIABLE_SHOW_OBJECTIVE_RESULTS_GUI = 0x13,
    RELIABLE_SHOW_LOADOUT_SELECT_GUI = 0x14,
    RELIABLE_SEND_SERVER_TEXT = 0x15,
    RELIABLE_ONLINE_GAME_EVENT = 0x16,
    RELIABLE_BROADCAST_KILL_MESSAGE = 0x17,
    RELIABLE_LOBBY_UPDATE = 0x18,
    RELIABLE_BROADCAST_TEXT_CHAT = 0x19,
    RELIABLE_UPDATE_CASH = 0x1A,
    RELIABLE_RESTART_CHALLENGE_RESPONSE = 0x1B,
    RELIABLE_DUCK_SOUND = 0x1C,
    RELIABLE_PLAY_VO = 0x1D,
    RELIABLE_PLAYER_METRICS = 0x1E,
    RELIABLE_XP_GAIN = 0x1F,
    RELIABLE_PLAYER_VEHICLE_PICKUP = 0x20,
    RELIABLE_RALLY_SCORE = 0x21,
    RELIABLE_METEOR_SCORE = 0x22,
    RELIABLE_STATUS_ALERT = 0x23,
    RELIABLE_SHOW_TUTORIAL_GUI = 0x24,
    RELIABLE_TOGGLE_SHOW_LEGEND_TITLE = 0x25,
    RELIABLE_CLIENTGAMEMSG_HANDS_EQUIP = 0x26,
    RELIABLE_CLIENTGAMEMSG_HANDS_AMMO_CHANGE = 0x27,
    RELIABLE_CLIENTGAMEMSG_HANDS_THROW = 0x28,
    RELIABLE_CLIENTGAMEMSG_HITSCANHIT = 0x29,
    RELIABLE_CLIENTGAMEMSG_QUICKUSE = 0x2A,
    RELIABLE_CLIENTGAMEMSG_USEFOCUS = 0x2B,
    RELIABLE_CLIENTGAMEMSG_HANDSACTION = 0x2C,
    RELIABLE_CLIENTGAMEMSG_MELEEHIT = 0x2D,
    RELIABLE_CLIENTGAMEMSG_DROPITEM = 0x2E,
    RELIABLE_CLIENTGAMEMSG_VEHICLE_CROSSHAIR_CHANGE_TARGET = 0x2F,
    RELIABLE_CLIENTGAMEMSG_VEHICLE_WEAPON_CHANGE = 0x30,
    RELIABLE_CLIENTGAMEMSG_UPDATE_STAT = 0x31,
    RELIABLE_CLIENTGAMEMSG_ACTORMODIFIER = 0x32,
    RELIABLE_PUSH_NOTICE_TO_SERVER = 0x33,
    RELIABLE_PUSH_NOTICE_TO_CLIENT = 0x34,
    RELIABLE_PUSH_ACK_TO_SERVER = 0x35,
    RELIABLE_PUSH_ACK_TO_CLIENT = 0x36,
    RELIABLE_EMP_NOTICE_TO_SERVER = 0x37,
    RELIABLE_EMP_NOTICE_TO_CLIENT = 0x38,
    RELIABLE_SHIELD_DOWN = 0x39,
    RELIABLE_POSTGAME_SCORERECAP = 0x3A,
    RELIABLE_LOCK_SCRAMBLE = 0x3B,
    RELIABLE_SMASH_ACTIVE = 0x3C,
    RELIABLE_BOOST_EXTENDER = 0x3D,
    RELIABLE_GAME_OVER = 0x3E
};

struct presentableSpawnId_t {
    unsigned value;
    presentableSpawnId_t() : value(0) {}
};

class idClientGameMsg {
public:
    idClientGameMsg();
    virtual ~idClientGameMsg() = default;
    virtual void Serialize(idSerializer&) = 0;
    virtual void Execute() = 0;
    virtual gameReliable_t GetMsgType() const = 0;
    virtual void PrintDebug();
    virtual bool ShouldSendServerToClients() const { return true; }
    virtual bool ShouldExecuteOnInstigator() const { return true; }
    virtual bool IsMPOnly() const { return false; }

    std::uint8_t peerMask;
};

class idClientGameReliableServices {
public:
    virtual ~idClientGameReliableServices() = default;
    virtual idClientGame* GetClientGame() const { return nullptr; }
    virtual bool IsMultiplayer() const { return false; }
    virtual bool IsServer() const { return false; }
    virtual bool DebugEnabled() const { return false; }
    virtual void PrintDebug(const idClientGameMsg&) const {}
    virtual void SerializeInt(idSerializer&, int&, int) {}
    virtual void SerializeUnsigned(idSerializer&, unsigned&, int) {}
    virtual void SerializeBool(idSerializer&, bool&) {}
    virtual void SerializeFloat(idSerializer&, float&) {}
    virtual void SerializeVec3(idSerializer&, idVec3&) {}
    virtual void SerializeMat3(idSerializer&, idMat3&) {}
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}
    virtual void SerializeMessageRuntime(idClientGameMsg&, idSerializer&) {}
    virtual bool IsWriting(const idSerializer&) const { return true; }
    virtual void DeserializeMessage(idClientGameMsg&, idBitMsg&) {}
    virtual void ExecuteMessage(idClientGameMsg&) {}
    virtual void SendReliableMessage(const idClientGameMsg&) {}
    virtual unsigned GetPresentableSpawnId(const idPresentable*) const {
        return 0;
    }
    virtual bool IsPlayerLocallyControlled(
        const idPresentablePlayer&) const { return false; }
    virtual int GetPlayerGameTime(const idPresentablePlayer&) const {
        return 0;
    }
    virtual void ThrowItem(class idClientGameMsg_HandsThrow&,
        idPresentablePlayer&) {}
    virtual void ExecutePostGameScoreRecap(
        class idClientGameMsg_PostGameScoreRecap&) {}
};

void Tungsten_SetClientGameReliableServices(
    idClientGameReliableServices* services);

class idClientGameMsg_DropItem final : public idClientGameMsg {
public:
    struct ammoTransfer_t {
        const idDeclAmmo* ammoDecl;
        int count;
        ammoTransfer_t() : ammoDecl(nullptr), count(0) {}
    };
    idClientGameMsg_DropItem();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_DROPITEM;
    }
    void PrintDebug() override;
    int playerNumber;
    const idDeclInventory* itemDecl;
    int numAmmoTransfers;
    ammoTransfer_t ammoTransfers[4];
};

class idClientGameMsg_HandsEquip final : public idClientGameMsg {
public:
    idClientGameMsg_HandsEquip();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_HANDS_EQUIP;
    }
    int playerNumber;
    const idDeclInventory* itemDecl;
    const idDeclAmmo* ammoDecl;
};

class idClientGameMsg_HandsAmmoChange final : public idClientGameMsg {
public:
    idClientGameMsg_HandsAmmoChange();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_HANDS_AMMO_CHANGE;
    }
    int playerNumber;
    const idDeclAmmo* ammoDecl;
    const idDeclWeapon* weaponDecl;
    bool forced;
};

class idClientGameMsg_HandsThrow final : public idClientGameMsg {
public:
    enum clientGameMsgHandsThrow_t : int {
        HANDS_THROW_QUICK = 0,
        HANDS_THROW_IN = 1,
        HANDS_THROW_OUT = 2,
        HANDS_THROW_EXPLODE = 3,
        HANDS_THROW_ATTACH = 4,
        HANDS_THROW_RELEASE = 5,
        HANDS_THROW_DROPONDEATH = 6,
        HANDS_THROW_MAX = 7
    };
    idClientGameMsg_HandsThrow();
    idClientGameMsg_HandsThrow(int playerNumber,
        clientGameMsgHandsThrow_t throwType,
        const idDeclThrowable* throwItem, const idVec3& start,
        const idMat3& fireAxis, float initialSpeed, int startTime);
    bool ShouldExecuteOnInstigator() const override;
    int GetRealStartTime(idPresentablePlayer* player);
    void PrintDebug() override;
    void Serialize(idSerializer&) override;
    void ThrowItem(idPresentablePlayer* player);
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_HANDS_THROW;
    }
    int playerNumber;
    clientGameMsgHandsThrow_t throwType;
    const idDeclThrowable* throwItem;
    idVec3 start;
    idMat3 fireAxis;
    float initialSpeed;
    int startTime;
    int serverTime;
    int predictedKey;
};

class idClientGameMsg_HitScanHit final : public idClientGameMsg {
public:
    struct hitInfo_t {
        int entityNum;
        int jointNum;
        int bodyId;
        idVec3 hitPos;
        hitInfo_t() : entityNum(0), jointNum(0), bodyId(0),
            hitPos(0.0f, 0.0f, 0.0f) {}
    };
    idClientGameMsg_HitScanHit(idPresentable* attacker = nullptr,
        const idDeclWeapon* weapon = nullptr,
        const idDeclProjectile* projectile = nullptr,
        const idVec3& start = idVec3(0.0f, 0.0f, 0.0f));
    void AddHit(int entityNumber, int jointNumber, int bodyId,
        idVec3 hitPosition);
    void Serialize(idSerializer&) override;
    void Execute() override;
    void PrintDebug() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_HITSCANHIT;
    }
    presentableSpawnId_t attacker;
    const idDeclWeapon* weaponDecl;
    const idDeclProjectile* projDecl;
    idVec3 startPos;
    int numHits;
    int serverTime;
    hitInfo_t hitInfos[24];
};

class idClientGameMsg_QuickUse final : public idClientGameMsg {
public:
    idClientGameMsg_QuickUse();
    void Serialize(idSerializer&) override;
    void Execute() override;
    void PrintDebug() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_QUICKUSE;
    }
    presentableSpawnId_t instigator;
    const idDeclInventory* invDecl;
};

class idClientGameMsg_VehicleCrosshairChangeTarget final
    : public idClientGameMsg {
public:
    idClientGameMsg_VehicleCrosshairChangeTarget();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_VEHICLE_CROSSHAIR_CHANGE_TARGET;
    }
    presentableSpawnId_t vehicle;
};

class idClientGameMsg_VehicleWeaponChange final : public idClientGameMsg {
public:
    idClientGameMsg_VehicleWeaponChange();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_VEHICLE_WEAPON_CHANGE;
    }
    presentableSpawnId_t vehicle;
};

class idClientGameMsg_UpdateStat final : public idClientGameMsg {
public:
    idClientGameMsg_UpdateStat();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_UPDATE_STAT;
    }
    presentableSpawnId_t presentable;
    int statType;
    int statParm;
};

class idClientGameMsg_UseFocus final : public idClientGameMsg {
public:
    idClientGameMsg_UseFocus();
    void Serialize(idSerializer&) override;
    void Execute() override;
    void PrintDebug() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_USEFOCUS;
    }
    presentableSpawnId_t instigator;
    presentableSpawnId_t usedPresentable;
    int usableState;
};

class idClientGameMsg_MeleeHit final : public idClientGameMsg {
public:
    idClientGameMsg_MeleeHit();
    void Serialize(idSerializer&) override;
    void Execute() override;
    void PrintDebug() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_MELEEHIT;
    }
    presentableSpawnId_t instigator;
    int hitEntityNum;
    const idDeclDamage* damageDecl;
    int traceJoint;
    int traceModelFeature;
};

class idClientGameMsg_ActorModifier final : public idClientGameMsg {
public:
    idClientGameMsg_ActorModifier();
    void Serialize(idSerializer&) override;
    void Execute() override;
    gameReliable_t GetMsgType() const override {
        return RELIABLE_CLIENTGAMEMSG_ACTORMODIFIER;
    }
    presentableSpawnId_t instigator;
    unsigned uid;
    int index;
};

class idClientGameMsg_PostGameScoreRecap final : public idClientGameMsg {
public:
    struct scoreItem_t {
        bool isFloat;
        union { int intValue; float floatValue; };
        int playerIndex;
        const idDeclMetric* metric;
        scoreItem_t() : isFloat(false), intValue(0), playerIndex(-1),
            metric(nullptr) {}
    };
    idClientGameMsg_PostGameScoreRecap();
    void PrintDebug() override;
    int GetNumAwards(int playerNum);
    void Serialize(idSerializer&) override;
    void Execute() override;
    void AddInt(const idDeclMetric* metric, int playerIndex, int value);
    gameReliable_t GetMsgType() const override {
        return RELIABLE_POSTGAME_SCORERECAP;
    }
    bool IsMPOnly() const override { return true; }
    idList<scoreItem_t, 5> items;
};
