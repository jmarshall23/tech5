#pragma once

#include "game/editor/entityinterfacelocal.h"
#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/math/vector.h"

class idAttachmentCollection;
class idCVar;
class idDeclVoiceOver;
class idGame;
class idMD6Anim;
class idPresentableAnimatedEntity;
class idSoundShader;
class idTreeAnimator;

class idEditorModelEntity;

class idEditorModelServices {
public:
    virtual ~idEditorModelServices() = default;

    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetTicksPerSecond() const { return 1000; }
    virtual int GetMillisecondsPerRealSecond() const { return 1000; }
    virtual idTreeAnimator* GetTreeAnimator(idEditorModelEntity*, int) {
        return nullptr;
    }
    virtual void SetModel(idEditorModelEntity*, idRenderModel*) {}
    virtual void SetModelByName(idEditorModelEntity*, const char*) {}
    virtual void UpdateModelTransform(idEditorModelEntity*) {}
    virtual void UpdateVisuals(idEditorModelEntity*) {}
    virtual void Show(idEditorModelEntity*) {}
    virtual void SetRemoveOriginTranslation(idEditorModelEntity*, bool) {}
    virtual void SetRemoveOriginRotation(idEditorModelEntity*, bool) {}
    virtual bool GetRemoveOriginTranslation(idEditorModelEntity*) const {
        return false;
    }
    virtual void UpdateAnimation(idEditorModelEntity*) {}
    virtual void UpdateUncompressedTransform(idEditorModelEntity*) {}
    virtual idPresentableAnimatedEntity* ShowUncompressed(
        idEditorModelEntity*, bool show) {
        return show ? reinterpret_cast<idPresentableAnimatedEntity*>(1)
                    : nullptr;
    }
    virtual const idMD6Anim* FindUncompressedAnimation(
        const idMD6Anim*) { return nullptr; }
    virtual void StartVoiceOver(idEditorModelEntity*, idTreeAnimator*,
        const idDeclVoiceOver*) {}
    virtual void StartVoiceTrack(idEditorModelEntity*, idTreeAnimator*,
        const idDeclVoiceOver*, int) {}
    virtual void StopVoiceTrack(idEditorModelEntity*, idTreeAnimator*) {}
    virtual void StartFootstepSound(idEditorModelEntity*,
        const idSoundShader*) {}
    virtual const idSoundShader* ResolveFootstepSound(const char*) {
        return nullptr;
    }
    virtual void Spawn(idEditorModelEntity*, const char*,
        idVec3& baseOrigin, idMat3& baseAxis) {
        baseOrigin.Zero();
        baseAxis = idMat3(1.0f);
    }
    virtual void ResetToBaseTransform(idEditorModelEntity*,
        const idVec3&, const idMat3&) {}
    virtual idAttachmentCollection* GetAttachments(idEditorModelEntity*) {
        return nullptr;
    }
    virtual void Shutdown(idEditorModelEntity*) {}
};

class idEditorModelEntity {
public:
    idEditorModelEntity();
    virtual ~idEditorModelEntity();

    static void SetServices(idEditorModelServices* services);
    static idEditorModelServices& Services();

    virtual void SetModel(idRenderModel* model);
    virtual void SetModelByName(const char* modelName);
    virtual void Think();
    virtual idEntityInterface* CreateEntityInterface(idGame* game);

    void Spawn();
    void UpdateUncompressedTransform();
    void SetAnimTime(float timeSeconds);
    void SetRemoveOriginTranslation(bool remove);
    bool GetRemoveOriginRotation() const;
    eventVoid AnimEvent_VoiceOver(const idMD6Anim* animation,
        const idDeclVoiceOver* voiceOver);
    eventVoid AnimEvent_VoiceTrack(const idDeclVoiceOver* voiceOver,
        int trackIndex);
    eventVoid AnimEvent_LeftRearFoot(const idMD6Anim* animation);
    void ShowUncompressed(bool show);
    int GetCurrentAnimFrame() const;
    bool IsAnimPlaying() const;
    bool PlayAnim(const idMD6Anim* animation, bool cycleAnimation);
    const idMD6Node* GetMD6Tree() const { return leaf; }
    idAttachmentCollection* GetAttachments() {
        return Services().GetAttachments(this);
    }

    idPresentableAnimatedEntity* uncompressedModelView;
    float moveSpeed;
    float caretTime;
    bool movement;
    bool cycle;
    bool cycleFrom;
    bool cycleTo;
    const idSoundShader* sndFootsteps;
    const idMD6Anim* curAnim;
    idMD6Leaf* leaf;
    idMD6LeafPlay leafPlay;
    idMD6LeafPause leafPause;
    const idMD6Anim* curAnimUncompressed;
    idMD6Leaf* leafUncompressed;
    idMD6LeafPlay leafPlayUncompressed;
    idMD6LeafPause leafPauseUncompressed;
    int lastLoopCount;
    idVec3 baseOrigin;
    idMat3 baseAxis;
};

class idEditorModelInterface : public idEntityInterfaceLocal {
public:
    idEditorModelInterface(idGame* game, idEditorModelEntity* entity);
    ~idEditorModelInterface() override = default;

    idTreeAnimator* GetTreeAnimator(int index) override;
    bool PlayAnim(const idMD6Anim* animation, bool cycle) override;
    bool PlayVTR(const idDeclVoiceOver* voiceOver, int trackIndex) override;
    bool StopVTR() override;
    bool IsAnimPlaying() override;
    void ShowUncompressed(bool show) override;
    void SetRemoveOriginTranslation(bool remove) override;
    bool GetRemoveOriginTranslation() override;
    void SetAnimTime(float timeSeconds) override;
    float GetAnimTime() override;
    int GetCurrentAnimFrame() override;

private:
    idEditorModelEntity* ModelEntity() const;
};

extern idCVar modelEditor_entityDef;
