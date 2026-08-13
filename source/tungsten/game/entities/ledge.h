#pragma once

#include "game/entities/entity.h"

class idFocusTrace;
class idLedge;
class idPlayer;

enum idContextualShimmyState_t : int {
    CONTEXTUAL_SHIMMY_STATE_NONE = 0,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0 = 1,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0 = 2,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0 = 3,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90 = 4,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90 = 5,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180 = 6,
    CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180 = 7,
    CONTEXTUAL_SHIMMY_STATE_CLIMB_OUT = 8,
    CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT = 13,
    CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD = 14,
    CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT = 15,
    CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM = 16
};

class idUseLedge;

class idLedgeServices {
public:
    virtual ~idLedgeServices() = default;
    virtual idPlayer* CastPlayer(idEntity* entity) const;
    virtual bool IsPlayerInShimmy(const idPlayer* player) const;
    virtual int GetBaseUsableState(const idUseLedge& use,
        const idEntity* activator, const void* focusTrace) const;
    virtual idVec3 GetPlayerOrigin(const idPlayer* player) const;
    virtual idVec3 GetEntityOrigin(const idEntity* entity) const;
    virtual int LoadAnimationAlias(const idUseLedge& use,
        const char* aliasName, bool handsAnimation);
    virtual void MountPlayer(idPlayer& player, idLedge& ledge,
        int ledgeBit, const idVec3& point, idUseLedge& use);
    virtual void DebugLine(const idColor& color, const idVec3& start,
        const idVec3& end, int lifetimeMilliseconds);
    virtual void DebugArrow(const idColor& color, const idVec3& start,
        const idVec3& end, float size, int lifetimeMilliseconds);
};

class idLedge : public idEntity {
public:
    enum ledgeEdgeType_t : int {
        EDGETYPE_NONE = 0,
        EDGETYPE_LEFTEDGE = 1,
        EDGETYPE_RIGHTEDGE = 2,
        EDGETYPE_LEFTEDGE_HASTURN = 3,
        EDGETYPE_RIGHTEDGE_HASTURN = 4
    };
    enum ledgeType_t : int {
        LEDGETYPE_CLOCKWISE = 0,
        LEDGETYPE_ANTICLOCKWISE = 1
    };
    enum ledgeBitFlags_t : int {
        CONNECTED_NONE = 0,
        CONNECTED_FIRST_90_INLEFT = 0x01,
        CONNECTED_FIRST_90_OUTLEFT = 0x02,
        CONNECTED_FIRST_90_INRIGHT = 0x04,
        CONNECTED_FIRST_90_OUTRIGHT = 0x08,
        CONNECTED_SECOND_90_INLEFT = 0x10,
        CONNECTED_SECOND_90_OUTLEFT = 0x20,
        CONNECTED_SECOND_90_INRIGHT = 0x40,
        CONNECTED_SECOND_90_OUTRIGHT = 0x80
    };

    class idLedgeBit {
    public:
        idLedgeBit();
        ledgeEdgeType_t GetPointOnLedge(const idPlayer* player,
            idVec3& pointOut, bool flipped) const;

        idVec3 firstPoint;
        idVec3 secondPoint;
        idVec3 direction;
        idVec3 normal;
        float length;
        int flags;
    };

    idLedge();
    static void SetServices(idLedgeServices* services);
    static idLedgeServices& Services();

    void Spawn() override;
    void DebugRender();
    int GetClosestPoint(const idVec3& playerPosition,
        idVec3& point) const;

    idList<idVec3, 5> controlPoints;
    idList<idLedgeBit, 5> ledgeBits;
    ledgeType_t ledgeNormalHint;
    int splineType;
    float maxDeltaYaw;
    float maxDeltaPitch;
    bool debugRender;
};

class idUseLedge : public idEntity {
public:
    idUseLedge();

    int GetUsableState(const idEntity* activator,
        const void* focusTrace) const override;
    bool Use(idEntity* activator, int usableState) override;
    void Event_PostSpawn();

    idContextualShimmyState_t mountType;
    idEntity* targetPositionEntity;
    idEntity* endPositionEntity;
    idStr customLegsAnimation;
    idStr customHandsAnimation;
    int customLegsAnimationHandle;
    int customHandsAnimationHandle;
    bool useEnabled;
    bool hideAfterUse;
};
