#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/math/vector.h"
#include "idlib/typesafenumber.h"
#include "models/skeletalanimation/eyeinfocollection.h"
#include "decls/voiceovers/voicetrack.h"

#include <cstdint>
#include <vector>

class idAnimWebPath;
class idAnimator_AnimWeb;
class idDeclFacialAnimationSet;
class idDeclVisemeSet;
class idDeclVoiceOver;
class idEntity;
class idFaceAnimator;
class idFaceMgr;
class idMat3;
class idSoundShader;
class idTreeAnimator;
class idVoiceTrack;
enum soundChannel_t : int;
enum millisecondUnique_t : int;

using millisecond_t = idTypesafeNumber<int, millisecondUnique_t>;
using gameTime_t = idTypesafeNumber<int, gameTimeUnique_t>;

enum idFaceAnimatorOperation : int {
    FACEANIM_SHUTDOWN,
    FACEANIM_ENABLE_ALL,
    FACEANIM_ENABLE_GESTURES,
    FACEANIM_ENABLE_GLANCE,
    FACEANIM_ENABLE_IDLE_CYCLE,
    FACEANIM_ENABLE_IDLE_FIDGET,
    FACEANIM_START_LIPSYNC,
    FACEANIM_ANIMATE_MOOD,
    FACEANIM_RESET,
    FACEANIM_LIPSYNC_FINISHED,
    FACEANIM_PLAY_ANIMATION,
    FACEANIM_PLAY_WEB_ANIMATION,
    FACEANIM_ANIMATE_EYES,
    FACEANIM_BLINK,
    FACEANIM_GLANCE,
    FACEANIM_FIDGET,
    FACEANIM_INIT,
    FACEANIM_UPDATE
};

struct idFaceVoiceTrackInfo {
    const idSoundShader* soundShader = nullptr;
    const idDeclVisemeSet* visemeSet = nullptr;
    idAnimAliasHandle animationAlias;
    mood_t defaultMood = MOOD_NONE;
    faceChannel_t faceChannel = FACECHANNEL_MAX;
    int durationMilliseconds = -1;
    int soundOffsetMilliseconds = 0;
    int blendInMilliseconds = 0;
    int blendOutMilliseconds = 0;
    bool suppressBlinking = false;
    bool clearAnimationAfter = false;
    bool cycleAnimation = false;
    bool useRealTime = false;
    bool sampleValid = false;
    bool streamReady = false;
};

class idFaceMgrServices {
public:
    virtual ~idFaceMgrServices() = default;

    virtual int GetGameTime() const { return 0; }
    virtual int GetRealTime() const { return GetGameTime(); }
    virtual int GameToRealTime(int gameMilliseconds) const {
        return gameMilliseconds;
    }
    virtual int RandomInterval(int minimum, int maximum) {
        return minimum <= maximum ? minimum : maximum;
    }
    virtual bool GetDormantIntervals(const idEntity*, int& blinkMinimum,
        int& blinkMaximum, int& jitterMinimum, int& jitterMaximum) const {
        blinkMinimum = 500;
        blinkMaximum = 7500;
        jitterMinimum = 100;
        jitterMaximum = 1500;
        return false;
    }
    virtual const idDeclFacialAnimationSet* GetFacialAnimationSet(
        const idEntity*) const { return nullptr; }
    virtual void AnimatorOperation(idFaceAnimatorOperation, idFaceAnimator&,
        idFaceMgr&, idEntity*, idTreeAnimator*, idAnimAliasHandle,
        faceChannel_t, float, int, int, int, bool) {}
    virtual bool IsAnimatorActive(idFaceAnimatorOperation,
        const idFaceAnimator&, const idEntity*) const { return false; }
    virtual bool ShouldSkipBlink() const { return false; }
    virtual bool ShouldSkipProceduralAnimation() const { return false; }
    virtual bool LoadVisemeAliases(idTreeAnimator*, const idDeclVisemeSet*,
        bool, std::vector<idAnimAliasHandle>& aliases) {
        aliases.clear();
        return false;
    }
    virtual bool GetVoiceTrackInfo(const idDeclVoiceOver*, int,
        idFaceVoiceTrackInfo&) const { return false; }
    virtual int GetVoiceTrackCount(const idDeclVoiceOver*) const { return 0; }
    virtual int ChooseVoiceTrack(const idDeclVoiceOver*, int count,
        int previous) {
        if (count <= 0) {
            return -1;
        }
        return previous >= 0 && previous < count ? previous : 0;
    }
    virtual void StartSound(idEntity*, soundChannel_t,
        const idSoundShader*) {}
    virtual void NotifyVoiceOverStarted(idEntity*, const idDeclVoiceOver*,
        int) {}
    virtual void UpdateLipSync(idFaceMgr&, idEntity*, idTreeAnimator*,
        int) {}
    virtual int SelectFacialAnimation(const idFaceMgr&, idEntity*,
        idTreeAnimator*, bool, float) { return -1; }
    virtual void ApplyEyeAngles(idEntity*, idTreeAnimator*, idJointIndex,
        const idAngles&) {}
    virtual void UpdateFace(idFaceMgr&, idEntity*, idTreeAnimator*,
        const idVec3&) {}
};

class idFaceAnimator {
public:
    idFaceAnimator();
    virtual ~idFaceAnimator();

    void Shutdown(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void SetEnableAnimation(idFaceMgr* manager, idEntity* owner, bool enable);
    void SetEnableGestures(idFaceMgr* manager, idEntity* owner, bool enable);
    void SetEnableGlancing(idFaceMgr* manager, idEntity* owner, bool enable);
    void SetEnableIdleCycles(idFaceMgr* manager, idEntity* owner, bool enable);
    void SetEnableIdleFidgets(idFaceMgr* manager, idEntity* owner, bool enable);
    void StartLipSync(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void AnimateMood(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void Reset(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void LipSyncFinished(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void PlayAnimation(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator, idAnimAliasHandle aliasHandle,
        faceChannel_t channel, float rateScale, int startFrame,
        int blendInDurationMS, int blendOutDurationMS, bool cycleAnimation);
    void PlayWebAnimation(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator, idAnimator_AnimWeb* webAnimator,
        const idAnimWebPath& webPath);
    void AnimateEyes(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator, const idEyeInfo* eyeInfo,
        const idAnimAliasHandle* aliases, const float* weights, int count);
    void Blink(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void Glance(const idAnimAliasHandle& aliasHandle, idFaceMgr* manager,
        idEntity* owner, idTreeAnimator* treeAnimator);
    void Fidget(const idAnimAliasHandle& aliasHandle, idFaceMgr* manager,
        idEntity* owner, idTreeAnimator* treeAnimator);
    bool IsCurrentlyGlancing(idEntity* owner) const;
    bool IsCurrentlyFidgeting(idEntity* owner) const;
    bool Init(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);
    void Update(idFaceMgr* manager, idEntity* owner,
        idTreeAnimator* treeAnimator);

    bool IsInitialized() const { return initialized; }
    bool IsAnimationEnabled() const { return animationEnabled; }
    bool AreGesturesEnabled() const { return gesturesEnabled; }
    bool IsGlancingEnabled() const { return glancingEnabled; }
    bool AreIdleCyclesEnabled() const { return idleCyclesEnabled; }
    bool AreIdleFidgetsEnabled() const { return idleFidgetsEnabled; }

private:
    bool initialized;
    bool animationEnabled;
    bool gesturesEnabled;
    bool glancingEnabled;
    bool idleCyclesEnabled;
    bool idleFidgetsEnabled;
    bool currentlyGlancing;
    bool currentlyFidgeting;
};

void SortAliasesAndWeights(idAnimAliasHandle* aliases, float* weights,
    int count);

class idFaceMgr {
public:
    enum facialAnimFlags_t : std::uint16_t {
        FACEFLAG_ANIMATE_MOODS = 0x0001,
        FACEFLAG_ANIMATE_LIPSYNC = 0x0002,
        FACEFLAG_ANIMATE_GESTURES = 0x0004,
        FACEFLAG_EYE_TRACK = 0x0008,
        FACEFLAG_ANIMATE_BLINK = 0x0010,
        FACEFLAG_LID_DEFORMATION = 0x0020,
        FACEFLAG_DOUBLE_BLINK = 0x0040,
        FACEFLAG_SUPPRESS_BLINK = 0x0080,
        FACEFLAG_SUPPRESS_LID_DEFORM = 0x0100,
        FACEFLAG_ENABLE = 0x0200,
        FACEFLAG_ANIMATE_GLANCE = 0x0400,
        FACEFLAG_SUPPRESS_GLANCE = 0x0800,
        FACEFLAG_ANIMATE_CYCLE = 0x1000,
        FACEFLAG_SUPPRESS_CYCLE = 0x2000,
        FACEFLAG_ANIMATE_FIDGET = 0x4000,
        FACEFLAG_SUPPRESS_FIDGET = 0x8000
    };
    enum lidDeformation_t : int {
        LID_DEFORM_NONE, LID_DEFORM_UP, LID_DEFORM_DOWN,
        LID_DEFORM_RIGHT, LID_DEFORM_LEFT, LID_DEFORM_MAX
    };
    enum eyeFaceChannels_t : int {
        EYEFACECHANNEL_LEFT, EYEFACECHANNEL_RIGHT, EYEFACECHANNEL_UP,
        EYEFACECHANNEL_DOWN, EYEFACECHANNEL_NUM
    };
    enum attentionLevel_t : int {
        ATTENTION_LOW, ATTENTION_MODERATE, ATTENTION_HIGH, ATTENTION_MAX
    };
    enum soundSampleState_t : int {
        SOUNDSAMPLE_LEAD_IN, SOUNDSAMPLE_PLAYING, SOUNDSAMPLE_DONE,
        SOUNDSAMPLE_MAX
    };

    idFaceMgr();
    virtual ~idFaceMgr();

    void SetServices(idFaceMgrServices* newServices) { services = newServices; }
    idFaceMgrServices* GetServices() const { return services; }
    void SetEnableEyeTracking(idEntity* owner, bool enable);
    void SuppressBlinking(bool suppress);
    void SuppressLidDeformation(bool suppress);
    const idDeclFacialAnimationSet* GetFacialAnimSetDecl(idEntity* owner) const;
    void Shutdown(idEntity* owner, idTreeAnimator* treeAnimator);
    void DormantEnd(idEntity* owner, int timeDormant);
    void SetEnableAnimation(idEntity* owner, bool enable);
    void SetEnableMoodAnimation(idEntity* owner, bool enable);
    void SetEnableLipSyncAnimation(idEntity* owner, bool enable);
    void SetEnableGestureAnimation(idEntity* owner, bool enable);
    void SetEnableBlinking(idEntity* owner, bool enable);
    void SetEnableLidDeformation(idEntity* owner, bool enable);
    bool AnimateBlinks() const;
    void Reset(idEntity* owner, idTreeAnimator* treeAnimator);
    bool RecentlyPlayedVoiceOver(gameTime_t threshold) const;
    bool StartVoiceTrack(idEntity* owner, idTreeAnimator* treeAnimator,
        const idDeclVoiceOver* voiceOverDeclaration, int trackIndex);
    bool Init(idEntity* owner, idTreeAnimator* treeAnimator, mood_t initialMood,
        soundChannel_t channel, bool enableMoodAnimation,
        bool enableLipSyncAnimation, bool enableGestureAnimation,
        bool enableEyeTracking, bool useFaceSetupEyeTracking,
        bool enableBlinking, bool enableLidDeformation);
    void Update(idEntity* owner, idTreeAnimator* treeAnimator,
        const idVec3& focusPoint);
    bool StartVoiceOver(idEntity* owner, idTreeAnimator* treeAnimator,
        const idDeclVoiceOver* voiceOverDeclaration);

    std::uint16_t GetFlags() const { return flags; }
    mood_t GetMood() const { return mood; }
    int GetNextBlinkTime() const { return nextBlinkTime; }
    int GetNextJitterTime() const { return nextJitterTime; }
    int GetVoiceTrackIndex() const { return voiceTrackIndex; }
    bool HasStartedVoiceOver() const { return startedVO; }
    idFaceAnimator& GetFaceAnimator() { return faceAnimator; }
    const idFaceAnimator& GetFaceAnimator() const { return faceAnimator; }

private:
    idVec3 CalcEyeFocusPoint(const idVec3& focusPoint,
        const idVec3& eyeDelta, const idEyeInfo* eyeInfo, int eye);
    void AlignEye(idEntity* owner, idTreeAnimator* treeAnimator,
        idJointIndex eyeJoint, const idVec3& eyeJointPosition,
        const idMat3& eyeJointAxis, const idVec3& focusPoint,
        const idEyeInfo* eyeInfo, int eye, idAngles& offsetAngle);
    millisecond_t GetVoiceTrackTime(idEntity* owner,
        const idVoiceTrack* voiceTrack) const;
    void LipSyncFinished(idEntity* owner, idTreeAnimator* treeAnimator);
    void ReallyStartVoiceOver(idEntity* owner, idTreeAnimator* treeAnimator);
    bool StartVOIfStreamedSampleIsReady(idEntity* owner,
        idTreeAnimator* treeAnimator, const idVoiceTrack* voiceTrack);
    int SelectNewGlanceIndex(idEntity* owner,
        idTreeAnimator* treeAnimator) const;
    int SelectNewFidgetIndex(idEntity* owner,
        idTreeAnimator* treeAnimator) const;
    void LoadVisemeSetAnims(idTreeAnimator* treeAnimator,
        const idDeclVisemeSet* visemeSet, bool load);
    void UpdateLipSync(idEntity* owner, idTreeAnimator* treeAnimator);

    mood_t mood;
    mood_t lastMood;
    mood_t defaultMood;
    soundChannel_t voiceChannel;
    faceChannel_t clearChannel;
    std::uint16_t flags;
    std::uint16_t lastFlags;
    idAnimAliasHandle moodTable[MOOD_MAX];
    std::vector<idAnimAliasHandle> visemeTable;
    idAnimAliasHandle blinkAlias;
    idAnimAliasHandle lidDeformationAliases[LID_DEFORM_MAX];
    short eyeFaceChannels[EYEFACECHANNEL_NUM];
    idUserChannelIndex eyeLidUserChannels[2];
    const idDeclVoiceOver* voiceOver;
    int voiceTrackIndex;
    const idSoundShader* lastSoundShader;
    const idDeclVisemeSet* curVisemeSet;
    millisecond_t vtrackDuration;
    millisecond_t realStartTime;
    millisecond_t realEndTime;
    gameTime_t vtrackStartTime;
    millisecond_t startSoundTime;
    millisecond_t lastSampleTime;
    gameTime_t endLipsyncTime;
    idFaceAnimator faceAnimator;
    idJointIndex eyeJointIndex[2];
    idJointIndex headJointIndex;
    int nextBlinkTime;
    int nextJitterTime;
    idVec3 eyeJitterOffset;
    idAngles eyeAngles[2];
    float eyeWander[2];
    bool initEyeTracking;
    bool useFaceSetupEyeTracking;
    bool useFaceSetupBlinking;
    bool startedVO;
    attentionLevel_t focusAttentionLevel;
    int lastGlanceTime;
    int currentGlanceInterval;
    bool glancingPreviousFrame;
    int lastFidgetTime;
    int currentFidgetInterval;
    bool fidgetingPreviousFrame;
    int nextCycleSelectTime;
    int currentFluffInterval;
    idFaceMgrServices* services;
};
