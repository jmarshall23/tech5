#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/text/str.h"
#include "idlib/typesafenumber.h"

class idSerializer;

class idAnimatorParms_Base;

class idAnimator_Base {
public:
    enum priority_t : int {
        PRIORITY_WEB = 0,
        PRIORITY_AFTER_WEB = 1,
        PRIORITY_IK = 99,
        PRIORITY_AF = 100
    };

    struct serializeProps_t {
        idMD6Branch* serializedTrees[2];
        idAnimStack* animStack;
        idClip* clip;
        bool createdThroughSerialization;
    };

    idAnimator_Base();
    virtual ~idAnimator_Base();

    bool Init(idGameTimeManager* gameTimeManager,
        const idAnimatorParms_Base& parameters);
    void Shutdown(idAnimStack* stack);
    bool IsInitialized(idAnimStack* stack) const;
    bool IsEnabled(idAnimStack* stack) const;
    void SetEnabled(idAnimStack* stack, bool enabled);
    void Blend(const idAnimStack* stack, int currentTime, float targetAlpha,
        int blendDurationMS, bool reset);
    bool IsContributing() const;
    md6WeightGroup_t GetFilterGroup() const;
    float GetAlpha() const;
    void SetAlpha(float alpha);
    void Pause(const idAnimStack* stack,
        idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    void Unpause(const idAnimStack* stack,
        idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    void Start(const idAnimStack* stack, int currentTime,
        int blendDurationMS, bool reset);
    void End(const idAnimStack* stack, int currentTime,
        int blendDurationMS, bool reset);

    virtual priority_t GetStackPriority();
    virtual serializeType_t GetSerializeType();
    virtual void SerializeSnapshot(idSerializer* serializer);
    virtual void PreBlendSnapshot(idAnimStack* stack, int currentTime,
        int ticksPerSecond, float fraction);
    virtual void PreSerializeInit(idAnimStack* stack, idClip* clip,
        idGameTimeManager* gameTimeManager);
    virtual bool InternalInit(const idAnimatorParms_Base& parameters);
    virtual bool InternalPostInit(const idAnimatorParms_Base& parameters);
    virtual void InternalShutdown(idAnimStack* stack);
    virtual void InternalPreBlendTree(const idAnimStack* stack,
        int currentTime, int ticksPerSecond);
    virtual void InternalPostBlendTree(const idAnimStack* stack,
        int currentTime);
    virtual void InternalStart(const idAnimStack* stack, int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime);
    virtual void InternalEnd(const idAnimStack* stack, int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime);
    virtual void InternalBlend(const idAnimStack* stack, int currentTime,
        float targetAlpha,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime);
    virtual bool InternalIsContributing() const;
    virtual const idMD6Branch* InternalGetMergeBranch() const;
    virtual idMD6Branch* InternalGetMergeBranch();
    virtual void InternalPause(const idAnimStack* stack,
        idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    virtual void InternalUnpause(const idAnimStack* stack,
        idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    virtual const idMD6Branch* InternalGetEndBranch() const;
    virtual idMD6Branch* InternalGetEndBranch();

    idGameTimeManagerPtr gametimeManager;
    md6WeightGroup_t weightGroup;
    md6WeightGroup_t filterGroup;
    serializeProps_t serializeProps;
    bool initialized;
};

class idAnimatorParms_Base {
public:
    idAnimStack* animStack;
    idStr name;
    int blendOp;
    int originBlend;
    md6WeightGroup_t weightGroup;
    md6WeightGroup_t filterGroup;
    float alpha;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Base::serializeProps_t) == 20,
    "Recovered animator serialization properties ABI changed");
static_assert(sizeof(idAnimator_Base) == 40,
    "Recovered idAnimator_Base ABI changed");
static_assert(sizeof(idAnimatorParms_Base) == 56,
    "Recovered idAnimatorParms_Base ABI changed");
#endif
