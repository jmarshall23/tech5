#include "game/editor/editormodel.h"

#include "idlib/csystems/cvarsystem.h"
#include "idlib/lib_print.h"
#include "models/skeletalanimation/jobs/md6animdata.h"
#include "models/skeletalanimation/md6anim.h"

#include <algorithm>

idCVar modelEditor_entityDef(
    "modelEditor_entityDef", "player", 0,
    "Default entity def to use for footstep sounds and other defaults");

namespace {
idEditorModelServices defaultEditorModelServices;
idEditorModelServices* activeEditorModelServices =
    &defaultEditorModelServices;

int AnimationFrameRate(const idMD6Anim* animation) {
    return animation != nullptr && animation->animData != nullptr
        ? (std::max)(1, static_cast<int>(animation->animData->frameRate))
        : 30;
}

int AnimationFrameCount(const idMD6Anim* animation) {
    return animation != nullptr && animation->animData != nullptr
        ? static_cast<int>(animation->animData->numFrames) : 0;
}

int AnimationLength(const idMD6Anim* animation, const int ticksPerSecond) {
    const int intervals = (std::max)(0, AnimationFrameCount(animation) - 1);
    return intervals == 0 ? 0
        : intervals * ticksPerSecond / AnimationFrameRate(animation);
}

int PlayFrame(const idMD6LeafPlay& play, const int gameTime,
        const int ticksPerSecond) {
    if (play.anim == nullptr) return 0;
    const int frames = AnimationFrameCount(play.anim);
    if (frames <= 1) return 0;
    const int elapsed = (std::max)(0, gameTime - play.startTime);
    int frame = elapsed * AnimationFrameRate(play.anim) / ticksPerSecond;
    if (play.wrapMode == idMD6Leaf::WRAP_REPEAT) {
        frame %= frames - 1;
    } else {
        frame = (std::min)(frame, frames - 1);
    }
    return frame;
}

int PlayLoopCount(const idMD6LeafPlay& play, const int gameTime,
        const int ticksPerSecond) {
    const int length = AnimationLength(play.anim, ticksPerSecond);
    return length <= 0 ? 0
        : (std::max)(0, gameTime - play.startTime) / length;
}
}

void idEditorModelEntity::SetServices(idEditorModelServices* services) {
    activeEditorModelServices = services == nullptr
        ? &defaultEditorModelServices : services;
}

idEditorModelServices& idEditorModelEntity::Services() {
    return *activeEditorModelServices;
}

// EA 0x82BD7C48
float idEditorModelInterface::GetAnimTime() {
    const idEditorModelEntity* entity = ModelEntity();
    return entity == nullptr ? 0.0f : entity->caretTime;
}

// EA 0x82BD7CC8
void idEditorModelEntity::SetModel(idRenderModel* model) {
    Services().SetModel(this, model);
    Services().UpdateModelTransform(this);
    Services().SetRemoveOriginTranslation(this, false);
    Services().SetRemoveOriginRotation(this, false);
}

// EA 0x82BD7D48
void idEditorModelEntity::UpdateUncompressedTransform() {
    if (uncompressedModelView != nullptr) {
        Services().UpdateUncompressedTransform(this);
    }
}

// EA 0x82BD7E68
void idEditorModelEntity::SetAnimTime(const float timeSeconds) {
    if (Services().GetTreeAnimator(this, 0) == nullptr || curAnim == nullptr) {
        return;
    }
    const float frame = AnimationFrameRate(curAnim) * timeSeconds;
    leafPause.Init(curAnim, frame, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_LEGS);
    leaf = &leafPause;
    if (uncompressedModelView != nullptr && curAnimUncompressed != nullptr) {
        leafPauseUncompressed.Init(curAnimUncompressed, frame,
            idMD6Leaf::WRAP_CLAMP, MD6_WEIGHTGROUP_LEGS);
        leafUncompressed = &leafPauseUncompressed;
    }
}

// EA 0x82BD7F40
void idEditorModelEntity::SetRemoveOriginTranslation(const bool remove) {
    Services().UpdateModelTransform(this);
    movement = !remove;
    Services().SetRemoveOriginTranslation(this, remove);
}

// EA 0x82BD7FA8
bool idEditorModelEntity::GetRemoveOriginRotation() const {
    Services().UpdateModelTransform(
        const_cast<idEditorModelEntity*>(this));
    return Services().GetRemoveOriginTranslation(
        const_cast<idEditorModelEntity*>(this));
}

// EA 0x82BD8018
eventVoid idEditorModelEntity::AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* voiceOver) {
    if (voiceOver == nullptr) {
        idLibPrint::Warning(
            "Invalid voice over decl specified for AnimEvent_VoiceOver");
        return {};
    }
    idTreeAnimator* treeAnimator = Services().GetTreeAnimator(this, 0);
    Services().UpdateModelTransform(this);
    if (treeAnimator != nullptr) {
        Services().StartVoiceOver(this, treeAnimator, voiceOver);
    }
    return {};
}

// EA 0x82BD80B8
eventVoid idEditorModelEntity::AnimEvent_VoiceTrack(
        const idDeclVoiceOver* voiceOver, const int trackIndex) {
    if (voiceOver == nullptr) {
        idLibPrint::Warning(
            "Invalid voice over decl specified for AnimEvent_VoiceOver");
        return {};
    }
    idTreeAnimator* treeAnimator = Services().GetTreeAnimator(this, 0);
    Services().UpdateModelTransform(this);
    if (treeAnimator != nullptr) {
        Services().StartVoiceTrack(this, treeAnimator, voiceOver, trackIndex);
    }
    return {};
}

// EA 0x82BD8150
eventVoid idEditorModelEntity::AnimEvent_LeftRearFoot(const idMD6Anim*) {
    if (sndFootsteps != nullptr) {
        Services().StartFootstepSound(this, sndFootsteps);
    }
    return {};
}

// EA 0x82BD81D8
idTreeAnimator* idEditorModelInterface::GetTreeAnimator(const int index) {
    idEditorModelEntity* entity = ModelEntity();
    return entity == nullptr ? nullptr
        : idEditorModelEntity::Services().GetTreeAnimator(entity, index);
}

// EA 0x82BD8268
bool idEditorModelInterface::PlayVTR(const idDeclVoiceOver* voiceOver,
        const int trackIndex) {
    idEditorModelEntity* entity = ModelEntity();
    if (entity == nullptr) return false;
    entity->AnimEvent_VoiceTrack(voiceOver, trackIndex);
    return true;
}

// EA 0x82BD82D0
bool idEditorModelInterface::StopVTR() {
    idEditorModelEntity* entity = ModelEntity();
    if (entity == nullptr) return false;
    idTreeAnimator* treeAnimator =
        idEditorModelEntity::Services().GetTreeAnimator(entity, 0);
    idEditorModelEntity::Services().StopVoiceTrack(entity, treeAnimator);
    return true;
}

// EA 0x82BD8358
void idEditorModelInterface::SetRemoveOriginTranslation(const bool remove) {
    idEditorModelEntity* entity = ModelEntity();
    if (entity != nullptr) entity->SetRemoveOriginTranslation(remove);
}

// EA 0x82BD83A8
bool idEditorModelInterface::GetRemoveOriginTranslation() {
    const idEditorModelEntity* entity = ModelEntity();
    return entity != nullptr && entity->GetRemoveOriginRotation();
}

// EA 0x82BD83F8
void idEditorModelInterface::SetAnimTime(const float timeSeconds) {
    idEditorModelEntity* entity = ModelEntity();
    if (entity != nullptr) entity->SetAnimTime(timeSeconds);
}

// EA 0x82BD84D8
void idEditorModelEntity::SetModelByName(const char* modelName) {
    if (uncompressedModelView != nullptr) {
        uncompressedModelView = Services().ShowUncompressed(this, false);
        curAnimUncompressed = nullptr;
        leafUncompressed = nullptr;
    }
    Services().SetModelByName(this, modelName);
    Services().UpdateModelTransform(this);
    Services().SetRemoveOriginTranslation(this, false);
    Services().SetRemoveOriginRotation(this, false);
    Services().Show(this);
    Services().UpdateVisuals(this);
}

// EA 0x82BD8840
idEntityInterface* idEditorModelEntity::CreateEntityInterface(idGame* game) {
    return new idEditorModelInterface(game, this);
}

// EA 0x82BD88F0
void idEditorModelEntity::Spawn() {
    Services().Spawn(this, modelEditor_entityDef.GetString(),
        baseOrigin, baseAxis);
    sndFootsteps = Services().ResolveFootstepSound(
        modelEditor_entityDef.GetString());
}

// EA 0x82BD8B30
void idEditorModelEntity::Think() {
    const int gameTime = Services().GetGameMilliseconds();
    const int ticksPerSecond = (std::max)(1, Services().GetTicksPerSecond());

    if (leaf == &leafPlay) {
        const int loopCount = PlayLoopCount(leafPlay, gameTime,
            ticksPerSecond);
        const int length = AnimationLength(curAnim, ticksPerSecond);
        const int millisecondsPerSecond = (std::max)(1,
            Services().GetMillisecondsPerRealSecond());
        caretTime = length <= 0 ? 0.0f
            : static_cast<float>(gameTime - loopCount * length -
                leafPlay.startTime) / millisecondsPerSecond;
        if (lastLoopCount < loopCount) {
            lastLoopCount = loopCount;
            Services().ResetToBaseTransform(this, baseOrigin, baseAxis);
            if (!cycle) {
                leaf = nullptr;
                leafPlay.anim = nullptr;
            }
        }
    } else if (curAnim != nullptr) {
        caretTime = leafPause.frame / AnimationFrameRate(curAnim);
    } else {
        caretTime = 0.0f;
    }

    Services().UpdateAnimation(this);
    UpdateUncompressedTransform();
}

// EA 0x82BD9448
void idEditorModelEntity::ShowUncompressed(const bool show) {
    uncompressedModelView = Services().ShowUncompressed(this, show);
    if (!show) {
        curAnimUncompressed = nullptr;
        leafUncompressed = nullptr;
        return;
    }
    if (uncompressedModelView == nullptr || curAnim == nullptr) return;

    curAnimUncompressed = Services().FindUncompressedAnimation(curAnim);
    if (curAnimUncompressed == nullptr) return;
    if (leaf == &leafPause) {
        leafPauseUncompressed.Init(curAnimUncompressed, leafPause.frame,
            static_cast<std::uint8_t>(leafPause.wrapMode),
            MD6_WEIGHTGROUP_LEGS);
        leafUncompressed = &leafPauseUncompressed;
    } else {
        const int gameTime = Services().GetGameMilliseconds();
        const int ticksPerSecond =
            (std::max)(1, Services().GetTicksPerSecond());
        const int currentFrame = GetCurrentAnimFrame();
        leafPlayUncompressed.Init(curAnimUncompressed, gameTime, 1.0f,
            cycle ? idMD6Leaf::WRAP_REPEAT : idMD6Leaf::WRAP_CLAMP,
            MD6_WEIGHTGROUP_LEGS);
        leafPlayUncompressed.startTime = gameTime -
            currentFrame * ticksPerSecond /
                AnimationFrameRate(curAnimUncompressed);
        leafUncompressed = &leafPlayUncompressed;
    }
}

// EA 0x82BD9B88
int idEditorModelEntity::GetCurrentAnimFrame() const {
    if (leaf == &leafPlay) {
        return PlayFrame(leafPlay, Services().GetGameMilliseconds(),
            (std::max)(1, Services().GetTicksPerSecond()));
    }
    return static_cast<int>(leafPause.frame);
}

// EA 0x82BD9C28
bool idEditorModelEntity::IsAnimPlaying() const {
    if (leaf != &leafPlay || leafPlay.anim == nullptr) return false;
    if (leafPlay.wrapMode == idMD6Leaf::WRAP_REPEAT) return true;
    const int ticks = (std::max)(1, Services().GetTicksPerSecond());
    return Services().GetGameMilliseconds() - leafPlay.startTime <
        AnimationLength(leafPlay.anim, ticks);
}

// EA 0x82BD9CB8
bool idEditorModelInterface::IsAnimPlaying() {
    const idEditorModelEntity* entity = ModelEntity();
    return entity != nullptr && entity->IsAnimPlaying();
}

// EA 0x82BD9D08
void idEditorModelInterface::ShowUncompressed(const bool show) {
    idEditorModelEntity* entity = ModelEntity();
    if (entity != nullptr) entity->ShowUncompressed(show);
}

// EA 0x82BD9D58
int idEditorModelInterface::GetCurrentAnimFrame() {
    const idEditorModelEntity* entity = ModelEntity();
    return entity == nullptr ? 0 : entity->GetCurrentAnimFrame();
}

// EA 0x82BD9DA8
bool idEditorModelEntity::PlayAnim(const idMD6Anim* animation,
        const bool cycleAnimation) {
    if (Services().GetTreeAnimator(this, 0) == nullptr ||
            animation == nullptr) {
        return false;
    }

    curAnim = animation;
    cycle = cycleAnimation;
    const int gameTime = Services().GetGameMilliseconds();
    const int ticksPerSecond = (std::max)(1, Services().GetTicksPerSecond());
    const int millisecondsPerSecond = (std::max)(1,
        Services().GetMillisecondsPerRealSecond());
    const int duration = AnimationLength(animation, millisecondsPerSecond);
    int initialFrame = 0;
    if (duration > 0) {
        const int offset = static_cast<int>(caretTime *
            millisecondsPerSecond) % duration;
        initialFrame = AnimationFrameRate(animation) * offset /
            millisecondsPerSecond;
    }

    leafPlay.Init(animation, gameTime, 1.0f,
        cycle ? idMD6Leaf::WRAP_REPEAT : idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_LEGS);
    leafPlay.startTime = gameTime - initialFrame * ticksPerSecond /
        AnimationFrameRate(animation);
    leaf = &leafPlay;
    lastLoopCount = PlayLoopCount(leafPlay, gameTime, ticksPerSecond);
    Services().ResetToBaseTransform(this, baseOrigin, baseAxis);
    if (uncompressedModelView != nullptr) ShowUncompressed(true);
    return true;
}

// EA 0x82BDA008
bool idEditorModelInterface::PlayAnim(const idMD6Anim* animation,
        const bool cycleAnimation) {
    idEditorModelEntity* entity = ModelEntity();
    return entity != nullptr && entity->PlayAnim(animation, cycleAnimation);
}

// EA 0x82BDA070
idEditorModelEntity::~idEditorModelEntity() {
    Services().Shutdown(this);
    uncompressedModelView = nullptr;
}

// EA 0x82BDA370
idEditorModelEntity::idEditorModelEntity()
    : uncompressedModelView(nullptr)
    , moveSpeed(0.0f)
    , caretTime(0.0f)
    , movement(false)
    , cycle(false)
    , cycleFrom(true)
    , cycleTo(true)
    , sndFootsteps(nullptr)
    , curAnim(nullptr)
    , leaf(nullptr)
    , leafPlay{}
    , leafPause{}
    , curAnimUncompressed(nullptr)
    , leafUncompressed(nullptr)
    , leafPlayUncompressed{}
    , leafPauseUncompressed{}
    , lastLoopCount(0)
    , baseOrigin(0.0f, 0.0f, 0.0f)
    , baseAxis(1.0f) {
    leafPlay.type = idMD6Node::NODE_LEAF_PLAY;
    leafPlay.rateScale = 1.0f;
    leafPause.type = idMD6Node::NODE_LEAF_PAUSE;
    leafPlayUncompressed.type = idMD6Node::NODE_LEAF_PLAY;
    leafPlayUncompressed.rateScale = 1.0f;
    leafPauseUncompressed.type = idMD6Node::NODE_LEAF_PAUSE;
}

idEditorModelInterface::idEditorModelInterface(idGame* game,
        idEditorModelEntity* entity)
    : idEntityInterfaceLocal(game, reinterpret_cast<idEntity*>(entity)) {
}

idEditorModelEntity* idEditorModelInterface::ModelEntity() const {
    return reinterpret_cast<idEditorModelEntity*>(entityPtr);
}
