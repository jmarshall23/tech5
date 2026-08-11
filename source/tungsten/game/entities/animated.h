#pragma once

#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAnimated;
class idBinaryAnimation;
class idDeclEntityDef;
class idDeclMD6;
class idDeclTable;
class idDeclVoiceOver;
class idEntity;
class idMD6Anim;
class idTreeAnimator;

class idAnimatedServices {
public:
    virtual ~idAnimatedServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual idAnimAliasHandle ResolveAlias(
        const idAnimated&, const char*) const { return {}; }
    virtual bool PlayAnimation(idAnimated&, idAnimAliasHandle,
        bool, int) { return false; }
    virtual bool IsAnimationDone(const idAnimated&) const { return true; }
    virtual void SetActive(idAnimated&, bool, bool) {}
    virtual void StartVoiceOver(
        idAnimated&, const idDeclVoiceOver*) {}
    virtual bool InitializeAnimated(idAnimated&) { return true; }
    virtual void AddStartingAttachment(idAnimated&,
        const idDeclEntityDef*, const idDeclMD6*,
        const char*, const char*, const char*) {}
    virtual void UpdateAnimatedFrameCommands(idAnimated&) {}
    virtual void ApplyAnimatedOriginDelta(idAnimated&) {}
    virtual void UpdateAnimatedFace(idAnimated&) {}
    virtual void UpdateAnimatedAnimation(idAnimated&) {}
    virtual void UpdateAnimatedVisuals(idAnimated&) {}
    virtual void ShutdownAnimated(idAnimated&) {}

    virtual bool InitializeBinary(idBinaryAnimation&) { return true; }
    virtual idAnimAliasHandle ResolveBinaryAlias(
        const idBinaryAnimation&, const char*) const { return {}; }
    virtual const char* FirstBinaryAlias(
        const idBinaryAnimation&) const { return nullptr; }
    virtual int GetBinaryAnimationDuration(
        const idBinaryAnimation&, idAnimAliasHandle) const { return 1; }
    virtual void SetBinaryFrameZero(
        idBinaryAnimation&, idAnimAliasHandle) {}
    virtual void PlayBinaryAnimation(
        idBinaryAnimation&, idAnimAliasHandle) {}
    virtual bool IsBinaryAnimationDone(
        const idBinaryAnimation&) const { return true; }
    virtual float LookupMorph(
        const idDeclTable*, float fraction) const { return fraction; }
    virtual void SetBinaryMorph(idBinaryAnimation&, float) {}
    virtual void UpdateBinaryAnimation(idBinaryAnimation&) {}
    virtual void SetBinaryActive(idBinaryAnimation&, bool) {}
    virtual idTreeAnimator* GetBinaryTreeAnimator(
        idBinaryAnimation&) const { return nullptr; }
    virtual bool HasBinaryRenderModel(const idBinaryAnimation&) const {
        return false;
    }
    virtual void ShutdownBinary(idBinaryAnimation&) {}
};

class idAnimated {
public:
    struct anim_t {
        idStr animation;
        idAnimAliasHandle animationHandle;
        bool cycle = false;
        int blendDuration = 0;
    };
    struct attachment_t {
        const idDeclEntityDef* entityDef = nullptr;
        const idDeclMD6* md6 = nullptr;
        idStr entityName;
        idStr lwoName;
        idStr tag;
    };

    idAnimated();
    virtual ~idAnimated();

    static void SetServices(idAnimatedServices* services);
    static idAnimatedServices& Services();

    void StartCurAnim();
    virtual void OnActivate(idEntity* activator);
    eventVoid Event_Reset();
    eventVoid AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* voiceOver);
    void Spawn();
    virtual void Think();

    idStr name;
    idList<anim_t, 5> animations;
    idList<attachment_t, 5> startingAttachments;
    bool alwaysUpdate;
    bool applyAnimDelta;
    bool loopAnimList;
    int curAnim;
};

class idBinaryAnimation {
public:
    idBinaryAnimation();
    virtual ~idBinaryAnimation();

    virtual void Think();
    virtual void OnActivate(idEntity* activator);
    bool GetBinaryAnimationState(
        idTreeAnimator*& treeAnimator, idStr& animationName);
    void Spawn();

    idStr name;
    idStr animation;
    idAnimAliasHandle animationHandle;
    int totalAnimMilliseconds;
    int animStartMilliseconds;
    const idDeclTable* megaMorphTable;
};
