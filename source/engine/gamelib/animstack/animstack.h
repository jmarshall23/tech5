#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/typesafenumber.h"
#include "models/skeletalanimation/md6blockalloc.h"

class idAnimator_Base;
class idClip;
class idGameTimeManager;
class idParallelJobList;
class idSerializer;

class idAnimStack {
public:
    enum animatorFlag_t : int {
        ANIMATORFLAG_INITIALIZED = 0x01,
        ANIMATORFLAG_ENABLED = 0x02,
        ANIMATORFLAG_CONTRIBUTED_LAST_SERIALIZE = 0x04,
        ANIMATORFLAG_SERIALIZE = 0x08,
        ANIMATORFLAG_CLIENT_AUTHORITATIVE_ENABLED = 0x10,
        ANIMATORFLAG_CLIENT_AUTHORITATIVE_CONTRIBUTED = 0x20
    };

    struct syncNode_t {
        idMD6LeafPlay* node;
        float alpha;
    };
    struct syncGroup_t {
        idStaticList<syncNode_t, 16> nodes;
        float fraction;
        float syncRate;
        int groupNumber;
    };

    idAnimStack();
    virtual ~idAnimStack();

    void Init(idTreeAnimator* animator);
    void Shutdown();
    void AddAnimator(idAnimator_Base* animator);
    void RemoveAnimator(idAnimator_Base* animator);
    idAnimator_Base* GetAnimator(const char* name);
    int GetAnimatorIndex(const idAnimator_Base* animator) const;
    idAnimator_Base* GetAnimatorByIndex(int index) const;
    idAnimator_Base* GetAnimatorBySerializeType(serializeType_t type);
    void SetAnimatorFlag(const idAnimator_Base* animator,
        animatorFlag_t flag);
    void ClearAnimatorFlag(const idAnimator_Base* animator,
        animatorFlag_t flag);
    bool IsAnimatorFlagSet(const idAnimator_Base* animator,
        animatorFlag_t flag) const;
    void Pause(idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    void Unpause(idTypesafeNumber<int, gameTimeUnique_t> currentTime);
    void FreeSerializedAnimators();
    void SerializeSnapshot(idSerializer* serializer, idClip* clip,
        int currentTime, idGameTimeManager* gameTimeManager);
    void BlendSnapshot(int currentTime, int previousTime,
        int gameMillisecondsPerFrame, float fraction,
        idGameTimeManager* gameTimeManager,
        idParallelJobList* parallelJobList);
    void UpdateSynchronization(int currentTime, int previousTime,
        int gameMillisecondsPerFrame, int ticksPerSecond);

    idTreeAnimator* treeAnimator;
    idMD6BlockAlloc md6Allocator;
    idList<idAnimator_Base*, 25> blendStack;
    idList<unsigned char, 25> flags;
    idMD6Node* tree;
    idTypesafeNumber<int, gameTimeUnique_t> pauseTime;
    bool skipSerialization;
    unsigned char typesMemory[9];
    unsigned char branchMemory[96];
    unsigned char leafMemory[153];
    bool serializedNewTree;
    int prevSerializedTime;
    int curSerializedTime;
    bool createdFromSnapshot;
    bool blendedFromSnapshot;
    bool disableSerialization;
    idStaticList<idMD6Node*, 128> usedSnapshotNodes;
    idStaticList<idMD6Node*, 128> rememberedNodes;

private:
    void ShutdownBlendStackIndex(int index);
    void AddNodeToSyncGroups(idList<syncGroup_t, 5>& groups,
        idMD6LeafPlay* node, float alpha);
    void PreSynchronizeNode_r(idList<syncGroup_t, 5>& groups,
        idMD6Node* node, float branchAlpha);
    void BlendStackInternal(int currentTime, int previousTime,
        int gameMillisecondsPerFrame, int ticksPerSecond,
        idGameTimeManager* gameTimeManager,
        idParallelJobList* parallelJobList, float* localRotation,
        float* localScale, float* localTranslation, float* localUser);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimStack::syncNode_t) == 8,
    "Recovered animation sync-node ABI changed");
static_assert(sizeof(idAnimStack::syncGroup_t) == 156,
    "Recovered animation sync-group ABI changed");
static_assert(sizeof(idAnimStack) == 1572,
    "Recovered idAnimStack ABI changed");
#endif
