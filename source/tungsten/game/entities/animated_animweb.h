#pragma once

#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAnimated_AnimWeb;
class idDeclDamage;
class idDeclEntityDef;
class idDeclInventory;
class idDeclMD6;
class idDeclVoiceOver;
class idEntity;
class idInventoryItem;
class idMD6Anim;
class idSoundShader;

class idAnimatedAnimWebServices {
public:
    virtual ~idAnimatedAnimWebServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual void GetSoundTransform(
        const idAnimated_AnimWeb&, idVec3&, idMat3&) const {}
    virtual awPathResult_t ChangeState(idAnimated_AnimWeb&,
        const char*, const char*, const char*, const char*, bool) {
        return AWPATH_FAILED;
    }
    virtual bool StartVoiceOver(idAnimated_AnimWeb&, idEntity*,
        const idDeclVoiceOver*, bool) { return false; }
    virtual void EquipInventoryItem(
        idAnimated_AnimWeb&, const char*, bool) {}
    virtual void ItemFX(
        idAnimated_AnimWeb&, const char*, int, bool) {}
    virtual void SetVisible(idAnimated_AnimWeb&, bool) {}
    virtual void SetKnifeVisible(idAnimated_AnimWeb&,
        const char*, const char*, bool) {}
    virtual void DamagePlayer(idAnimated_AnimWeb&,
        const idDeclDamage*, int, float) {}
    virtual void ControllerShake(
        idAnimated_AnimWeb&, int, int, int, int) {}
    virtual void UpdateCollisionPiece(idAnimated_AnimWeb&,
        int, int, idBounds&, bool) {}
    virtual void SetCollisionStage(
        idAnimated_AnimWeb&, int, int, bool) {}
    virtual void TriggerAttachments(idAnimated_AnimWeb&) {}
    virtual void SetMeshVisible(
        idAnimated_AnimWeb&, const char*, bool) {}
    virtual void PauseAnimWeb(idAnimated_AnimWeb&, bool) {}
    virtual bool InitializeAnimWeb(idAnimated_AnimWeb&) { return true; }
    virtual void AddAttachment(idAnimated_AnimWeb&,
        const idDeclEntityDef*, const idDeclInventory*, const idDeclMD6*,
        const char*, const char*, const char*, int) {}
    virtual void InitializeCollisionPiece(
        idAnimated_AnimWeb&, int) {}
    virtual void ApplyOriginDelta(idAnimated_AnimWeb&) {}
    virtual void UpdateAnimation(idAnimated_AnimWeb&) {}
    virtual void UpdateFace(idAnimated_AnimWeb&) {}
    virtual void Think(idAnimated_AnimWeb&) {}
    virtual void Shutdown(idAnimated_AnimWeb&) {}
};

class idAnimated_AnimWeb {
public:
    struct animWebParms_t {
        const void* webDecl = nullptr;
        idStr initialSubWeb;
        idStr initialState;
        idList<idStr, 5> ambientAnims{0};
    };
    struct attachment_t {
        int equipSlot = 0;
        idStr tag;
        const idDeclEntityDef* entityDef = nullptr;
        idStr entityName;
        const idDeclInventory* declInventory = nullptr;
        const idDeclMD6* md6 = nullptr;
        idStr lwoName;
    };
    struct collisionPieceStage_t {
        idVec3 collisionBounds{0.0f, 0.0f, 0.0f};
        idStr tag;
        int clipMask = 0;
        int contents = 0;
        bool clipBounds = false;
        bool push = false;
        bool crush = false;
    };
    struct collisionPiece_t {
        idList<collisionPieceStage_t, 5> stages{0};
        int pushFlags = 0;
        int curStage = 0;
    };

    idAnimated_AnimWeb();
    virtual ~idAnimated_AnimWeb();

    static void SetServices(idAnimatedAnimWebServices* services);
    static idAnimatedAnimWebServices& Services();

    virtual void GetSoundTransform(idVec3& origin, idMat3& axis) const;
    awPathResult_t ChangeAnimWebState(const char* state);
    awPathResult_t ChangeAnimWebState(
        const char* subWeb, const char* state);
    awPathResult_t ChangeAnimWebStateVia(
        const char* state, const char* viaState);
    awPathResult_t ForceAnimWebState(const char* state);
    awPathResult_t ChangeAnimWebStateVia(const char* subWeb,
        const char* state, const char* viaSubWeb, const char* viaState);
    eventVoid Event_ChangeAnimState(const char*, const char*);
    eventVoid Event_ChangeAnimStateVia(
        const char*, const char*, const char*, const char*);
    eventVoid Event_ForceAnimState(const char*, const char*, int);
    eventBool Event_StartVoiceOver(
        idEntity*, const idDeclVoiceOver*, bool);
    eventVoid AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver*);
    eventVoid AnimEvent_HolsterItem(const idMD6Anim*, const char*);
    eventVoid AnimEvent_EquipItem(const idMD6Anim*, const char*);
    eventVoid AnimEvent_ItemStartFX(const idMD6Anim*, const char*, int);
    eventVoid AnimEvent_ItemStopFX(const idMD6Anim*, const char*, int);
    virtual void Hide();
    virtual void Show();
    eventVoid AnimEvent_HideFFFKnife(
        const idMD6Anim*, const char*, const char*);
    eventVoid AnimEvent_ShowFFFKnife(
        const idMD6Anim*, const char*, const char*);
    eventVoid AnimEvent_DamagePlayer(
        const idMD6Anim*, const idDeclDamage*, int, float);
    eventVoid AnimEvent_PlayerControllerShake(
        const idMD6Anim*, int, int, int, int);
    void UpdateCollisionPieces(idBounds& bounds, bool force);
    void SetStage(int piece, int stage, bool force);
    eventVoid AnimEvent_SetStage(const idMD6Anim*, int, int);
    eventVoid AnimEvent_TriggerAttachments(const idMD6Anim*);
    eventVoid AnimEvent_HideMesh(const idMD6Anim*, const char*);
    virtual void Think();
    void Spawn();

    idStr name;
    animWebParms_t animWebParms;
    idList<attachment_t, 5> startingAttachments;
    bool applyAnimDelta;
    bool useAmbientAnims;
    int ambientWaitTime;
    int ambientWait;
    bool useFaceManager;
    bool sceneModel;
    bool overrideUsingDeferredPositions;
    const idDeclDamage* crushDamage;
    const idDeclDamage* pushDamage;
    idStr soundJoint;
    idList<collisionPiece_t, 5> collisionPieces;
    idStr subtitleName;
    bool lightFromJointPositions;
    idStr skipJointForLighting;
    idList<idStr, 5> hideMeshes;
    idList<idStr, 5> showMeshes;
};

class idTarget_AnimWebChangeState {
public:
    idAnimated_AnimWeb* target = nullptr;
    idStr subWeb;
    idStr state;
    void OnActivate(idEntity* activator);
};

class idTarget_AnimWebChangeStateVia {
public:
    idAnimated_AnimWeb* target = nullptr;
    idStr subWeb;
    idStr state;
    idStr viaSubWeb;
    idStr viaState;
    void OnActivate(idEntity* activator);
};

class idTarget_AnimWebPause {
public:
    idAnimated_AnimWeb* target = nullptr;
    void OnActivate(idEntity* activator);
};

class idTarget_AnimWebUnpause {
public:
    idAnimated_AnimWeb* target = nullptr;
    void OnActivate(idEntity* activator);
};
