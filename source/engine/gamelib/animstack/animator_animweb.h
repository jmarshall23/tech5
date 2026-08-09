#pragma once

#include "decls/animwebs/animwebscalar.h"
#include "gamelib/animstack/animator_base.h"
#include "gamelib/animstack/animator_channelweight.h"
#include "gamelib/animstack/animweb/animwebblendtree.h"
#include "gamelib/animstack/animweb/animwebeventhandler.h"
#include "gamelib/animstack/animweb/animwebpath.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/text/atomicstring.h"

class idDeclAnimWeb;
class idDeclAnimWebNode;
class idDeclMD6;
class idEventDef;
class idMD6Allocator;

class idAnimator_AnimWeb : public idAnimator_Base {
public:
    enum animWebError_t : int {
        ANIMWEB_ERROR_NONE = 0,
        ANIMWEB_ERROR_NOPATH = 1
    };

    struct animInfo_t {
        int curFrame;
        int numFrames;
        int frameRate;
    };

    struct forcedEdge_t {
        idAnimWebNodeIndex destNodeIndex;
        idAnimWebSubWebIndex destSubWebIndex;
        blendParms_t blendParms;
    };

    class idModelAnimState {
    public:
        idModelAnimState();
        idModelAnimState(const idModelAnimState& other);
        idModelAnimState(idModelAnimState&& other) noexcept;
        idModelAnimState& operator=(const idModelAnimState& other);
        idModelAnimState& operator=(idModelAnimState&& other) noexcept;
        ~idModelAnimState();

        const idAnimWebBlendTree* GetBlendTree(
            idAnimWebNodeIndex nodeIndex) const;
        idAnimWebBlendTree* GetBlendTree(idAnimWebNodeIndex nodeIndex);
        void FreeBlendTree(idAnimWebNodeIndex nodeIndex);
        idAnimWebBlendTree* AllocBlendTree(idAnimWebNodeIndex forNodeIndex,
            idAnimWebNodeIndex keepNodeIndex);
        void Update(int currentTime);
        void Free(idAnimator_AnimWeb* web);
        bool BeginNodePlaying(idAnimator_AnimWeb* web,
            const void* modelInfo, idAnimWebNodeIndex nodeIndex,
            int currentTime, int ticksPerSecond);
        void SetDestFrame(idMD6Node* node, const blendParms_t& parameters,
            int currentTime, int ticksPerSecond,
            unsigned int& longestAnimationLength, int& destinationFrame) const;
        void StartBlend(idAnimator_AnimWeb* web, const void* modelInfo,
            idAnimWebNodeIndex currentNode, idAnimWebNodeIndex nextNode,
            const blendParms_t& parameters, int currentTime,
            int ticksPerSecond, unsigned int& longestAnimationLength,
            int& destinationFrame);
        void SetDecl(const idDeclAnimWeb* declaration,
            idAnimator_AnimWeb* web, idAnimWebModelIndex modelIndex,
            int ticksPerSecond);

        idMD6Node* tree;
        idMD6Branch* branches[2];
        idStaticList<idAnimWebBlendTree*, 8> blendTreeCache;
        idAnimWebNodeIndex recentNodes[3];
        short recentNodeStart;
        bool blending;
    };

    idAnimator_AnimWeb();
    ~idAnimator_AnimWeb() override;

    priority_t GetStackPriority() override { return PRIORITY_WEB; }
    const idAnimWebHandle& GetHandle() const { return handle; }
    bool IsTransitioning() const;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override;
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    virtual void InternalInitWeb();
    virtual void InternalUpdate(int currentTime);
    virtual idAnimWebDeltaMode_t InternalGetCurrentAnimDeltaMode() const;
    virtual void InternalSetAnimDelta(idAnimWebModelIndex modelIndex,
        const idDeclAnimWebNode* node);
    virtual int InternalGetEdgeCost(idAnimWebNodeIndex nodeIndex,
        idAnimWebEdgeIndex edgeIndex) const;
    virtual void InternalStartPath();
    virtual void InternalUpdateScalars(int currentTime);
    virtual void InternalStartBlend(const idDeclAnimWebNode* currentNode,
        const idDeclAnimWebNode* nextNode, int currentTime);
    virtual void InternalFinishBlend(const idDeclAnimWebNode* currentNode,
        const idDeclAnimWebNode* nextNode, int currentTime);
    virtual awCheckPathResult_t CheckNextNode(
        const idDeclAnimWebNode* currentNode,
        const idDeclAnimWebNode* nextNode) const;
    virtual bool InternalShouldStartNextNode(idAnimWebNodeIndex currentNode,
        idAnimWebNodeIndex nextNode, int currentTime, int ticksPerSecond,
        const blendParms_t& parameters, idAnimWebModelIndex modelIndex,
        bool forced, animWebEvent_t* eventType);
    virtual void InternalTriggerEvent(const idDeclAnimWebNode* node,
        animWebEvent_t eventType, const idAnimWebHandle& webHandle,
        int eventNumber, int eventParameter);
    virtual void InternalTriggerBlendEvent(int nodeFlags,
        idAnimWebModelIndex modelIndex, idAnimWebNodeIndex currentNode,
        idAnimWebNodeIndex nextNode, int currentTime);
    virtual bool InternalRemapNames(idStr& subWebName,
        idStr& stateName) const;
    virtual void InternalUpdateBlendEvents(const idAnimStack* stack,
        int currentTime, int ticksPerSecond);

    void DebugPrint(const char* format, ...) const;
    void ClearEvent(animWebEvent_t eventType);
    void ClearEvents();
    bool IsEventPending(animWebEvent_t eventType) const;
    bool IsAnyEventPending() const;
    void SetEvent(animWebEvent_t eventType,
        idAnimWebSubWebIndex subWebIndex, idAnimWebStateIndex stateIndex,
        const idEventDef& eventDefinition,
        idAnimWebEvent::priority_t priority);
    void TriggerEvent(const idDeclAnimWebNode* node,
        animWebEvent_t eventType, const idAnimWebEvent& event,
        int eventParameter);

    idAnimWebPath GetDestWebPath(bool includeWebName) const;
    idAnimWebPath GetCurWebPath(bool includeWebName) const;
    const char* GetCurSubWebName() const;
    const char* GetCurStateName() const;
    idAnimWebSubWebIndex GetCurSubWebIndex() const;
    idAnimWebStateIndex GetCurStateIndex() const;
    bool GetCurEdgeInfo(idAnimWebSubWebIndex& subWebIndex,
        idAnimWebNodeIndex& nodeIndex, blendParms_t& parameters) const;
    bool DecomposeAnimRef(const char* animationReference,
        idStr& subWebName, idStr& stateName) const;
    bool GetNodeTotalMovement(idAnimWebModelIndex modelIndex,
        idAnimWebSubWebIndex subWebIndex, idAnimWebStateIndex stateIndex,
        idVec3& translation, idQuat& rotation) const;

    bool UsesAnyScalarIndices(const idList<int, 5>& testScalars) const;
    int AddBlendVariable(const char* name, float* scalar,
        idAnimWebScalarPair::fieldFlag_t flags);
    void Free();
    void Reset(const char* initialSubWebName, const char* initialStateName,
        int currentTime);
    void SetDecl(const idDeclAnimWeb* declaration,
        const idDeclMD6* firstModel);
    void InitWeb(const class idAnimatorParms_AnimWeb& parameters);
    void Reinitialize(int currentTime);

    awPathResult_t ForceState(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, const blendParms_t& parameters,
        int blendEvents);
    awPathResult_t ForceState(const char* subWebName, const char* stateName,
        const blendParms_t& parameters, int blendEvents);
    awPathResult_t ChangeState(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ChangeState(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex,
        idAnimWebSubWebIndex otherSubWeb, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ChangeState(const char* subWebName,
        idAnimWebStateIndex stateIndex, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ChangeState(const char* subWebName, const char* stateName,
        interruptPath_t pathInterrupt, interruptBlend_t blendInterrupt,
        int blendEvents);
    awPathResult_t ChangeStateVia(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, idAnimWebSubWebIndex viaSubWeb,
        idAnimWebStateIndex viaState, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ChangeStateVia(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, idAnimWebSubWebIndex viaSubWeb,
        idAnimWebStateIndex viaState, idAnimWebSubWebIndex otherSubWeb,
        interruptPath_t pathInterrupt, interruptBlend_t blendInterrupt,
        int blendEvents);
    awPathResult_t ChangeStateVia(const char* subWebName,
        idAnimWebStateIndex stateIndex, const char* viaSubWebName,
        idAnimWebStateIndex viaState, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ChangeStateVia(const char* subWebName,
        const char* stateName, const char* viaSubWebName,
        const char* viaStateName, interruptPath_t pathInterrupt,
        interruptBlend_t blendInterrupt, int blendEvents);
    awPathResult_t ForceAndChangeState(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, idAnimWebSubWebIndex forcedSubWeb,
        idAnimWebStateIndex forcedState, const blendParms_t& parameters,
        int blendEvents);
    awPathResult_t ForceAndChangeState(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, idAnimWebSubWebIndex forcedSubWeb,
        idAnimWebStateIndex forcedState, idAnimWebSubWebIndex otherSubWeb,
        const blendParms_t& parameters, int blendEvents);

    bool FindPath(idAnimWebNodeIndex startNode,
        idAnimWebStateIndex destinationState,
        idAnimWebSubWebIndex destinationSubWeb,
        idAnimWebSubWebIndex otherSubWeb, idAnimWebRoute& route) const;
    bool FindPath(idAnimWebNodeIndex startNode,
        const idAnimWebStateList& destinationStates,
        idAnimWebSubWebIndex destinationSubWeb,
        idAnimWebSubWebIndex otherSubWeb, idAnimWebRoute& route) const;
    bool FindPath(idAnimWebNodeIndex startNode,
        idAnimWebNodeIndex destinationNode,
        idAnimWebSubWebIndex otherSubWeb, idAnimWebRoute& route) const;
    void StartPath(int currentTime);
    void SetCurNode(idAnimWebNodeIndex nodeIndex, int currentTime);
    void SetCurNode(idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, int currentTime);
    idAnimWebBlendTree* AllocBlendTrees(idAnimWebNodeIndex nodeIndex,
        idAnimWebNodeIndex keepNodeIndex);
    void BeginNodesPlaying(idAnimWebNodeIndex nodeIndex, int currentTime);
    const idMD6Leaf* FindFirstLeaf(const idMD6Node* node, int modelIndex,
        bool ignoreAdditive) const;
    const idMD6Leaf* FindLeafWithMatchingAnim(const idMD6Node* node,
        int modelIndex, const idMD6Anim* animation,
        bool ignoreAdditive) const;
    bool GetNodeAnimLength(int currentTime, idAnimWebModelIndex modelIndex,
        idAnimWebNodeIndex nodeIndex, idMD6Leaf::wrapMode_t wrapMode,
        bool ignoreAdditive, animInfo_t& animationInfo) const;
    bool GetNodeAnimLength(int currentTime, idAnimWebModelIndex modelIndex,
        idAnimWebSubWebIndex subWebIndex, idAnimWebStateIndex stateIndex,
        idMD6Leaf::wrapMode_t wrapMode, bool ignoreAdditive,
        animInfo_t& animationInfo) const;
    bool GetNodeAnimLength(int currentTime, idAnimWebModelIndex modelIndex,
        idAnimWebNodeIndex nodeIndex, animInfo_t& animationInfo) const;

    const idDeclAnimWeb* decl;
    idMD6Allocator* md6Allocator;
    idList<idAnimWebSubWebIndex, 5> initialActiveSubWebs;
    idList<idModelAnimState, 33> modelAnimStates;
    idAnimWebNodeIndex curNodeIndex;
    idAnimWebNodeIndex prevNodeIndex;
    idAnimWebSubWebIndex destSubWebIndex;
    idAnimWebStateList destStateIndices;
    idAnimWebSubWebIndex viaSubWebIndex;
    idAnimWebStateList viaStateIndices;
    idAnimWebSubWebIndex otherSubWebIndex;
    idAnimWebNodeIndex curEdgeNodeIndex;
    short curEdgeIndex;
    idStaticList<const idList<idAnimWebNodeIndex, 32>*, 16>
        pathableSubWebNodeLists;
    short pathIndex;
    idAnimWebRoute curPath;
    interruptPath_t interruptPath;
    interruptBlend_t interruptBlend;
    int nodeStartTime;
    int prevNodeStartTime;
    int nodeStartFrame;
    idList<idAnimWebScalar, 33> scalars;
    idScalarMemBlock scalarMem;
    int firstRandomScalarIndex;
    int blendEventMask;
    int declChangeId;
    idAtomicString curNodeStateName;
    idAtomicString curNodeSubWebName;
    idAtomicString destNodeStateName;
    idAtomicString destNodeSubWebName;
    idAnimWebHandle handle;
    idAnimWebEventHandler_Zion eventHandler;
    bool clearEventsOnStateChanges;
    unsigned char skipFlags;
    unsigned char requiredFlags;
    forcedEdge_t forcedEdge;
    float randomBlendVals[8];
    idMD6Branch* mergeBranch;
    idAnimator_ChannelWeight channelWeightAnimator;
    idList<const idDeclMD6*, 33> modelDecls;
    animWebError_t error;
    bool debug;
    bool forceAnimDeltaModeOnBlendStart;
    bool skipForcedEdgeAutoPath;

private:
    void CacheCurNode();
    void CacheDestNode();
    void SelectRandomBlendVals(const idDeclAnimWebNode* currentNode,
        const idDeclAnimWebNode* nextNode);
    void Update(int currentTime, int ticksPerSecond);
};

class idAnimatorParms_AnimWeb : public idAnimatorParms_Base {
public:
    idAnimatorParms_AnimWeb(idAnimStack* stack, const char* animatorName,
        int blendOperation, int originBlendOperation,
        md6WeightGroup_t animatorWeightGroup,
        md6WeightGroup_t animatorFilterGroup, float animatorAlpha,
        const idDeclAnimWeb* declaration, const char* initialSubWeb,
        const char* initialState, int currentTime);

    const idDeclAnimWeb* webDecl;
    idStr initialStateName;
    idStr initialSubWebName;
    int curTime;
    idList<idAtomicString, 5> activeLayers;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_AnimWeb::idModelAnimState) == 72,
    "Recovered AnimWeb model-state ABI changed");
static_assert(sizeof(idAnimator_AnimWeb::forcedEdge_t) == 24,
    "Recovered AnimWeb forced-edge ABI changed");
static_assert(sizeof(idAnimator_AnimWeb::animInfo_t) == 12,
    "Recovered AnimWeb animation-info ABI changed");
static_assert(sizeof(idAnimator_AnimWeb) == 648,
    "Recovered idAnimator_AnimWeb ABI changed");
static_assert(sizeof(idAnimatorParms_AnimWeb) == 144,
    "Recovered AnimWeb parameters ABI changed");
#endif
