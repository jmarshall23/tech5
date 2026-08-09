#include "gamelib/animstack/animator_animweb.h"

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <string>

// Declaration, resource, event, and MD6 graph ownership lives outside
// GameLib.  These adapters are the PC seams for functionality the recovered
// body invokes through those owning systems.
int GameLib_GetAnimWebEventNumber(const idEventDef& eventDefinition);
const char* GameLib_GetAnimWebDeclName(const idDeclAnimWeb* declaration);
int GameLib_GetAnimWebDeclChangeId(const idDeclAnimWeb* declaration);
int GameLib_GetAnimWebModelCount(const idDeclAnimWeb* declaration,
    const idDeclMD6* firstModel);
const idDeclMD6* GameLib_GetAnimWebModel(const idDeclAnimWeb* declaration,
    const idDeclMD6* firstModel, int modelIndex);
bool GameLib_ResolveAnimWebNames(const idDeclAnimWeb* declaration,
    const char* subWebName, const char* stateName,
    idAnimWebSubWebIndex& subWebIndex, idAnimWebStateIndex& stateIndex,
    idAnimWebNodeIndex& nodeIndex);
bool GameLib_GetAnimWebNodeIdentity(const idDeclAnimWeb* declaration,
    idAnimWebNodeIndex nodeIndex, idAnimWebSubWebIndex& subWebIndex,
    idAnimWebStateIndex& stateIndex, const char*& subWebName,
    const char*& stateName);
idAnimWebNodeIndex GameLib_FindAnimWebNode(
    const idDeclAnimWeb* declaration, idAnimWebSubWebIndex subWebIndex,
    idAnimWebStateIndex stateIndex);
const idDeclAnimWebNode* GameLib_GetAnimWebNode(
    const idDeclAnimWeb* declaration, idAnimWebNodeIndex nodeIndex);
bool GameLib_GetAnimWebNodeModelInfo(const idDeclAnimWeb* declaration,
    idAnimWebNodeIndex nodeIndex, idAnimWebModelIndex modelIndex,
    const idDeclAnimWebNode*& node, const void*& modelInfo,
    const char*& blendEquation, const idMD6AnimProps*& animationProperties,
    int& animationPropertyCount);
bool GameLib_GetAnimWebLayerSubWeb(const idDeclAnimWeb* declaration,
    const char* layerName, idAnimWebSubWebIndex& subWebIndex);
bool GameLib_GetAnimWebEdgeInfo(const idDeclAnimWeb* declaration,
    idAnimWebNodeIndex edgeNode, short edgeIndex,
    idAnimWebSubWebIndex& subWebIndex, idAnimWebNodeIndex& nodeIndex,
    blendParms_t& parameters);
bool GameLib_FindAnimWebRoute(const idAnimator_AnimWeb* web,
    idAnimWebNodeIndex startNode, const idAnimWebStateList* destinationStates,
    idAnimWebNodeIndex destinationNode,
    idAnimWebSubWebIndex destinationSubWeb,
    idAnimWebSubWebIndex otherSubWeb, idAnimWebRoute& route);
bool GameLib_GetAnimWebNodeMovement(const idAnimator_AnimWeb* web,
    idAnimWebModelIndex modelIndex, idAnimWebSubWebIndex subWebIndex,
    idAnimWebStateIndex stateIndex, idVec3& translation, idQuat& rotation);
void GameLib_ConfigureAnimWebModelState(const idDeclAnimWeb* declaration,
    idAnimator_AnimWeb* web, idAnimWebModelIndex modelIndex,
    int ticksPerSecond, idAnimator_AnimWeb::idModelAnimState& state);
void GameLib_FreeAnimWebModelState(idAnimator_AnimWeb* web,
    idMD6Node*& tree, idMD6Branch* (&branches)[2]);
void GameLib_UpdateAnimWebModelState(
    idAnimator_AnimWeb::idModelAnimState& state, int currentTime);
void GameLib_StartAnimWebModelBlend(
    idAnimator_AnimWeb::idModelAnimState& state, idAnimator_AnimWeb* web,
    const void* modelInfo, idAnimWebNodeIndex currentNode,
    idAnimWebNodeIndex nextNode, const blendParms_t& parameters,
    int currentTime, int ticksPerSecond,
    unsigned int& longestAnimationLength, int& destinationFrame);
void GameLib_SetAnimWebDestinationFrame(idMD6Node* node,
    const blendParms_t& parameters, int currentTime, int ticksPerSecond,
    unsigned int& longestAnimationLength, int& destinationFrame);
idAnimWebDeltaMode_t GameLib_GetAnimWebDeltaMode(
    const idAnimator_AnimWeb* web);
void GameLib_SetAnimWebDelta(idAnimator_AnimWeb* web,
    idAnimWebModelIndex modelIndex, const idDeclAnimWebNode* node);
int GameLib_GetAnimWebEdgeCost(const idAnimator_AnimWeb* web,
    idAnimWebNodeIndex nodeIndex, idAnimWebEdgeIndex edgeIndex);
void GameLib_FinishAnimWebBlend(idAnimator_AnimWeb* web,
    const idDeclAnimWebNode* currentNode,
    const idDeclAnimWebNode* nextNode, int currentTime);
awCheckPathResult_t GameLib_CheckAnimWebNextNode(
    const idAnimator_AnimWeb* web, const idDeclAnimWebNode* currentNode,
    const idDeclAnimWebNode* nextNode);
bool GameLib_ShouldStartAnimWebNextNode(idAnimator_AnimWeb* web,
    idAnimWebNodeIndex currentNode, idAnimWebNodeIndex nextNode,
    int currentTime, int ticksPerSecond, const blendParms_t& parameters,
    idAnimWebModelIndex modelIndex, bool forced,
    animWebEvent_t* eventType);
void GameLib_DispatchAnimWebEvent(idAnimator_AnimWeb* web,
    const idDeclAnimWebNode* node, animWebEvent_t eventType,
    const idAnimWebHandle& webHandle, int eventNumber, int eventParameter);
void GameLib_DispatchAnimWebBlendEvent(idAnimator_AnimWeb* web,
    int nodeFlags, idAnimWebModelIndex modelIndex,
    idAnimWebNodeIndex currentNode, idAnimWebNodeIndex nextNode,
    int currentTime);
bool GameLib_RemapAnimWebNames(const idAnimator_AnimWeb* web,
    idStr& subWebName, idStr& stateName);
void GameLib_UpdateAnimWebBlendEvents(idAnimator_AnimWeb* web,
    const idAnimStack* stack, int currentTime, int ticksPerSecond);
void GameLib_UpdateAnimWebOwner(idAnimator_AnimWeb* web, int currentTime);
void GameLib_UpdateAnimWebScalars(idAnimator_AnimWeb* web, int currentTime);
void GameLib_UpdateAnimWebTransition(idAnimator_AnimWeb* web,
    int currentTime, int ticksPerSecond);
void GameLib_InitAnimWebOwner(idAnimator_AnimWeb* web);
bool GameLib_IsAnimWebNodeBlendOut(const idDeclAnimWebNode* node);
bool GameLib_IsMD6LeafAdditive(const idMD6Leaf* leaf, int modelIndex);
bool GameLib_DoesAnimWebNodeMatchEvent(const idDeclAnimWebNode* node,
    idAnimWebSubWebIndex subWeb, idAnimWebStateIndex state);
void GameLib_FreeAnimWebScalarMemory(idScalarMemBlock& memory);
idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
bool GameLib_IsMD6NodeValid(const idMD6Node* node);
int GameLib_GetGameTicksPerSecond();

namespace {

void ClearStateList(idAnimWebStateList& states) {
    for (idAnimWebStateIndex& state : states.stateIndex) state.Invalidate();
    states.numStates = 0;
}

void SetSingleState(idAnimWebStateList& states,
        const idAnimWebStateIndex state) {
    ClearStateList(states);
    states.stateIndex[0] = state;
    states.numStates = state.IsValid() ? 1 : 0;
}

idAnimWebPath MakePath(const char* webName, const char* subWebName,
        const char* stateName) {
    idAnimWebPath path;
    if (webName != nullptr && *webName != '\0') {
        path = webName;
        path.Append("::");
    }
    if (subWebName != nullptr && *subWebName != '\0') {
        path.Append(subWebName);
        path.Append("::");
    }
    if (stateName != nullptr) path.Append(stateName);
    return path;
}

bool IsRecent(const idAnimator_AnimWeb::idModelAnimState& state,
        const idAnimWebNodeIndex node) {
    for (const idAnimWebNodeIndex recent : state.recentNodes)
        if (recent == node) return true;
    return false;
}

} // namespace

idAnimator_AnimWeb::idModelAnimState::idModelAnimState()
    : tree(nullptr)
    , branches{nullptr, nullptr}
    , blendTreeCache()
    , recentNodes{}
    , recentNodeStart(0)
    , blending(false) {
}

idAnimator_AnimWeb::idModelAnimState::idModelAnimState(
        const idModelAnimState& other) : idModelAnimState() {
    *this = other;
}

idAnimator_AnimWeb::idModelAnimState::idModelAnimState(
        idModelAnimState&& other) noexcept : idModelAnimState() {
    *this = static_cast<idModelAnimState&&>(other);
}

idAnimator_AnimWeb::idModelAnimState&
idAnimator_AnimWeb::idModelAnimState::operator=(
        const idModelAnimState& other) {
    if (this == &other) return *this;
    tree = other.tree;
    branches[0] = other.branches[0];
    branches[1] = other.branches[1];
    blendTreeCache = other.blendTreeCache;
    for (int index = 0; index < 3; ++index)
        recentNodes[index] = other.recentNodes[index];
    recentNodeStart = other.recentNodeStart;
    blending = other.blending;
    return *this;
}

idAnimator_AnimWeb::idModelAnimState&
idAnimator_AnimWeb::idModelAnimState::operator=(
        idModelAnimState&& other) noexcept {
    if (this == &other) return *this;
    for (int index = 0; index < blendTreeCache.Num(); ++index)
        delete blendTreeCache[index];
    blendTreeCache.Clear();
    tree = other.tree;
    branches[0] = other.branches[0];
    branches[1] = other.branches[1];
    for (int index = 0; index < other.blendTreeCache.Num(); ++index)
        blendTreeCache.Append(other.blendTreeCache[index]);
    for (int index = 0; index < 3; ++index)
        recentNodes[index] = other.recentNodes[index];
    recentNodeStart = other.recentNodeStart;
    blending = other.blending;
    other.tree = nullptr;
    other.branches[0] = other.branches[1] = nullptr;
    other.blendTreeCache.Clear();
    other.blending = false;
    return *this;
}

idAnimator_AnimWeb::idModelAnimState::~idModelAnimState() {
    for (int index = 0; index < blendTreeCache.Num(); ++index)
        delete blendTreeCache[index];
    blendTreeCache.Clear();
}

const idAnimWebBlendTree*
idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
        const idAnimWebNodeIndex nodeIndex) const {
    for (int index = 0; index < blendTreeCache.Num(); ++index) {
        const idAnimWebBlendTree* candidate = blendTreeCache[index];
        if (candidate != nullptr && candidate->nodeIndex == nodeIndex)
            return candidate;
    }
    return nullptr;
}

idAnimWebBlendTree* idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
        const idAnimWebNodeIndex nodeIndex) {
    return const_cast<idAnimWebBlendTree*>(
        static_cast<const idModelAnimState*>(this)->GetBlendTree(nodeIndex));
}

void idAnimator_AnimWeb::idModelAnimState::FreeBlendTree(
        const idAnimWebNodeIndex nodeIndex) {
    for (int index = 0; index < blendTreeCache.Num(); ++index) {
        if (blendTreeCache[index] != nullptr &&
                blendTreeCache[index]->nodeIndex == nodeIndex) {
            delete blendTreeCache[index];
            blendTreeCache.RemoveIndexFast(index);
            return;
        }
    }
}

idAnimWebBlendTree* idAnimator_AnimWeb::idModelAnimState::AllocBlendTree(
        const idAnimWebNodeIndex forNodeIndex,
        const idAnimWebNodeIndex keepNodeIndex) {
    if (idAnimWebBlendTree* existing = GetBlendTree(forNodeIndex))
        return existing;

    idAnimWebBlendTree* replacement = new (std::nothrow)
        idAnimWebBlendTree(forNodeIndex);
    if (replacement == nullptr) return nullptr;
    if (blendTreeCache.Num() < blendTreeCache.Max()) {
        blendTreeCache.Append(replacement);
        return replacement;
    }

    int replaceIndex = -1;
    int leastLeaves = (std::numeric_limits<int>::max)();
    for (int index = 0; index < blendTreeCache.Num(); ++index) {
        idAnimWebBlendTree* candidate = blendTreeCache[index];
        if (candidate == nullptr || candidate->nodeIndex == keepNodeIndex ||
                IsRecent(*this, candidate->nodeIndex)) continue;
        if (candidate->leaves.Num() < leastLeaves) {
            leastLeaves = candidate->leaves.Num();
            replaceIndex = index;
        }
    }
    if (replaceIndex < 0) replaceIndex = 0;
    delete blendTreeCache[replaceIndex];
    blendTreeCache[replaceIndex] = replacement;
    return replacement;
}

void idAnimator_AnimWeb::idModelAnimState::Update(const int currentTime) {
    GameLib_UpdateAnimWebModelState(*this, currentTime);
}

void idAnimator_AnimWeb::idModelAnimState::Free(
        idAnimator_AnimWeb* const web) {
    GameLib_FreeAnimWebModelState(web, tree, branches);
    for (int index = 0; index < blendTreeCache.Num(); ++index)
        delete blendTreeCache[index];
    blendTreeCache.Clear();
    tree = nullptr;
    branches[0] = branches[1] = nullptr;
    blending = false;
}

bool idAnimator_AnimWeb::idModelAnimState::BeginNodePlaying(
        idAnimator_AnimWeb* const web, const void* const modelInfo,
        const idAnimWebNodeIndex nodeIndex, const int currentTime,
        const int ticksPerSecond) {
    idAnimWebBlendTree* blendTree = GetBlendTree(nodeIndex);
    if (modelInfo == nullptr || blendTree == nullptr) return false;
    const idDeclAnimWebNode* node = nullptr;
    const void* resolvedInfo = nullptr;
    const char* blendEquation = nullptr;
    const idMD6AnimProps* animationProperties = nullptr;
    int propertyCount = 0;
    GameLib_GetAnimWebNodeModelInfo(web->decl, nodeIndex,
        idAnimWebModelIndex(blendTree->modelIndex), node, resolvedInfo,
        blendEquation, animationProperties, propertyCount);
    blendTree->BeginPlaying(web, animationProperties, propertyCount,
        currentTime, ticksPerSecond);
    tree = blendTree->tree;
    blending = false;
    recentNodes[recentNodeStart] = nodeIndex;
    recentNodeStart = static_cast<short>((recentNodeStart + 1) % 3);
    return tree != nullptr;
}

void idAnimator_AnimWeb::idModelAnimState::SetDestFrame(idMD6Node* node,
        const blendParms_t& parameters, const int currentTime,
        const int ticksPerSecond, unsigned int& longestAnimationLength,
        int& destinationFrame) const {
    GameLib_SetAnimWebDestinationFrame(node, parameters, currentTime,
        ticksPerSecond, longestAnimationLength, destinationFrame);
}

void idAnimator_AnimWeb::idModelAnimState::StartBlend(
        idAnimator_AnimWeb* const web, const void* const modelInfo,
        const idAnimWebNodeIndex currentNode,
        const idAnimWebNodeIndex nextNode,
        const blendParms_t& parameters, const int currentTime,
        const int ticksPerSecond, unsigned int& longestAnimationLength,
        int& destinationFrame) {
    GameLib_StartAnimWebModelBlend(*this, web, modelInfo, currentNode,
        nextNode, parameters, currentTime, ticksPerSecond,
        longestAnimationLength, destinationFrame);
    blending = true;
}

void idAnimator_AnimWeb::idModelAnimState::SetDecl(
        const idDeclAnimWeb* const declaration,
        idAnimator_AnimWeb* const web, const idAnimWebModelIndex modelIndex,
        const int ticksPerSecond) {
    Free(web);
    GameLib_ConfigureAnimWebModelState(declaration, web, modelIndex,
        ticksPerSecond, *this);
}

idAnimator_AnimWeb::idAnimator_AnimWeb()
    : idAnimator_Base()
    , decl(nullptr)
    , md6Allocator(nullptr)
    , initialActiveSubWebs(0)
    , modelAnimStates(0)
    , curNodeIndex()
    , prevNodeIndex()
    , destSubWebIndex()
    , destStateIndices{}
    , viaSubWebIndex()
    , viaStateIndices{}
    , otherSubWebIndex()
    , curEdgeNodeIndex()
    , curEdgeIndex(-1)
    , pathableSubWebNodeLists()
    , pathIndex(-1)
    , curPath{}
    , interruptPath(INTR_PATH_NO)
    , interruptBlend(INTR_BLEND_NO)
    , nodeStartTime(-1)
    , prevNodeStartTime(-1)
    , nodeStartFrame(0)
    , scalars(0)
    , scalarMem()
    , firstRandomScalarIndex(0)
    , blendEventMask(0)
    , declChangeId(-1)
    , curNodeStateName()
    , curNodeSubWebName()
    , destNodeStateName()
    , destNodeSubWebName()
    , handle()
    , eventHandler()
    , clearEventsOnStateChanges(true)
    , skipFlags(2)
    , requiredFlags(0)
    , forcedEdge{}
    , randomBlendVals{}
    , mergeBranch(nullptr)
    , channelWeightAnimator()
    , modelDecls(0)
    , error(ANIMWEB_ERROR_NONE)
    , debug(false)
    , forceAnimDeltaModeOnBlendStart(false)
    , skipForcedEdgeAutoPath(false) {
    ClearStateList(destStateIndices);
    ClearStateList(viaStateIndices);
    curPath.num = 0;
    curPath.cost = (std::numeric_limits<int>::max)();
    forcedEdge.destNodeIndex.Invalidate();
    forcedEdge.destSubWebIndex.Invalidate();
    std::memset(&forcedEdge.blendParms, 0, sizeof(forcedEdge.blendParms));
    for (int index = 0; index < pathableSubWebNodeLists.Max(); ++index)
        pathableSubWebNodeLists.staticList[index] = nullptr;
}

idAnimator_AnimWeb::~idAnimator_AnimWeb() {
    Free();
    md6Allocator = nullptr;
    mergeBranch = nullptr;
}

idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(idAnimStack* const stack,
        const char* const animatorName, const int blendOperation,
        const int originBlendOperation,
        const md6WeightGroup_t animatorWeightGroup,
        const md6WeightGroup_t animatorFilterGroup,
        const float animatorAlpha, const idDeclAnimWeb* const declaration,
        const char* const initialSubWeb, const char* const initialState,
        const int currentTime)
    : idAnimatorParms_Base()
    , webDecl(declaration)
    , initialStateName(initialState)
    , initialSubWebName(initialSubWeb)
    , curTime(currentTime)
    , activeLayers(0) {
    animStack = stack;
    name = animatorName;
    blendOp = blendOperation;
    originBlend = originBlendOperation;
    weightGroup = animatorWeightGroup;
    filterGroup = animatorFilterGroup;
    alpha = animatorAlpha;
}

bool idAnimator_AnimWeb::IsTransitioning() const {
    return curEdgeNodeIndex.IsValid() && curEdgeIndex >= 0;
}

const idMD6Branch* idAnimator_AnimWeb::InternalGetMergeBranch() const {
    return mergeBranch;
}

bool idAnimator_AnimWeb::InternalIsContributing() const {
    return modelAnimStates.Num() > 0 && modelAnimStates[0].tree != nullptr &&
        GameLib_IsMD6NodeValid(modelAnimStates[0].tree);
}

bool idAnimator_AnimWeb::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const idAnimatorParms_AnimWeb& webParameters =
        static_cast<const idAnimatorParms_AnimWeb&>(parameters);
    md6Allocator = nullptr;
    if (parameters.animStack != nullptr) {
        mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
        if (mergeBranch != nullptr) {
            mergeBranch->type = idMD6Node::NODE_BRANCH;
            mergeBranch->left = nullptr;
            mergeBranch->right = nullptr;
            mergeBranch->currentAlpha = 1.0f;
            mergeBranch->targetAlpha = 1.0f;
        }
    }
    InitWeb(webParameters);
    return decl != nullptr;
}

void idAnimator_AnimWeb::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr && stack != nullptr)
        GameLib_FreeMD6Branch(stack, mergeBranch);
    mergeBranch = nullptr;
    Free();
}

void idAnimator_AnimWeb::InternalInitWeb() {
    static const char* const randomNames[8] = {
        nullptr, "_random2", "_random3", "_random4", "_random5",
        "_random6", "_random7", "_random8"
    };
    for (int index = 1; index < 8; ++index) {
        const int scalarIndex = AddBlendVariable(randomNames[index],
            &randomBlendVals[index], idAnimWebScalarPair::FF_NO_OVERRIDE);
        if (index == 1) firstRandomScalarIndex = scalarIndex;
    }
    GameLib_InitAnimWebOwner(this);
}

void idAnimator_AnimWeb::InternalUpdate(const int currentTime) {
    GameLib_UpdateAnimWebOwner(this, currentTime);
}

idAnimWebDeltaMode_t
idAnimator_AnimWeb::InternalGetCurrentAnimDeltaMode() const {
    return GameLib_GetAnimWebDeltaMode(this);
}

void idAnimator_AnimWeb::InternalSetAnimDelta(
        const idAnimWebModelIndex modelIndex,
        const idDeclAnimWebNode* const node) {
    GameLib_SetAnimWebDelta(this, modelIndex, node);
}

int idAnimator_AnimWeb::InternalGetEdgeCost(
        const idAnimWebNodeIndex nodeIndex,
        const idAnimWebEdgeIndex edgeIndex) const {
    return GameLib_GetAnimWebEdgeCost(this, nodeIndex, edgeIndex);
}

void idAnimator_AnimWeb::InternalStartPath() {}

void idAnimator_AnimWeb::InternalUpdateScalars(const int currentTime) {
    GameLib_UpdateAnimWebScalars(this, currentTime);
}

void idAnimator_AnimWeb::InternalStartBlend(
        const idDeclAnimWebNode* const currentNode,
        const idDeclAnimWebNode* const nextNode, const int currentTime) {
    SelectRandomBlendVals(currentNode, nextNode);
    unsigned int longestAnimationLength = 0;
    int destinationFrame = 0;
    for (int model = 0; model < modelAnimStates.Num(); ++model) {
        const idDeclAnimWebNode* node = nullptr;
        const void* modelInfo = nullptr;
        const char* equation = nullptr;
        const idMD6AnimProps* properties = nullptr;
        int propertyCount = 0;
        GameLib_GetAnimWebNodeModelInfo(decl, curNodeIndex,
            idAnimWebModelIndex(static_cast<short>(model)), node, modelInfo,
            equation, properties, propertyCount);
        modelAnimStates[model].StartBlend(this, modelInfo, prevNodeIndex,
            curNodeIndex, forcedEdge.blendParms, currentTime,
            GameLib_GetGameTicksPerSecond(), longestAnimationLength,
            destinationFrame);
    }
}

void idAnimator_AnimWeb::InternalFinishBlend(
        const idDeclAnimWebNode* const currentNode,
        const idDeclAnimWebNode* const nextNode, const int currentTime) {
    GameLib_FinishAnimWebBlend(this, currentNode, nextNode, currentTime);
}

awCheckPathResult_t idAnimator_AnimWeb::CheckNextNode(
        const idDeclAnimWebNode* const currentNode,
        const idDeclAnimWebNode* const nextNode) const {
    return GameLib_CheckAnimWebNextNode(this, currentNode, nextNode);
}

bool idAnimator_AnimWeb::InternalShouldStartNextNode(
        const idAnimWebNodeIndex currentNode,
        const idAnimWebNodeIndex nextNode, const int currentTime,
        const int ticksPerSecond, const blendParms_t& parameters,
        const idAnimWebModelIndex modelIndex, const bool forced,
        animWebEvent_t* const eventType) {
    return GameLib_ShouldStartAnimWebNextNode(this, currentNode, nextNode,
        currentTime, ticksPerSecond, parameters, modelIndex, forced,
        eventType);
}

void idAnimator_AnimWeb::InternalTriggerEvent(
        const idDeclAnimWebNode* const node, const animWebEvent_t eventType,
        const idAnimWebHandle& webHandle, const int eventNumber,
        const int eventParameter) {
    GameLib_DispatchAnimWebEvent(this, node, eventType, webHandle,
        eventNumber, eventParameter);
}

void idAnimator_AnimWeb::InternalTriggerBlendEvent(const int nodeFlags,
        const idAnimWebModelIndex modelIndex,
        const idAnimWebNodeIndex currentNode,
        const idAnimWebNodeIndex nextNode, const int currentTime) {
    GameLib_DispatchAnimWebBlendEvent(this, nodeFlags, modelIndex,
        currentNode, nextNode, currentTime);
}

bool idAnimator_AnimWeb::InternalRemapNames(idStr& subWebName,
        idStr& stateName) const {
    return GameLib_RemapAnimWebNames(this, subWebName, stateName);
}

void idAnimator_AnimWeb::InternalUpdateBlendEvents(
        const idAnimStack* const stack, const int currentTime,
        const int ticksPerSecond) {
    if (decl != nullptr && blendEventMask != 0)
        GameLib_UpdateAnimWebBlendEvents(this, stack, currentTime,
            ticksPerSecond);
}

void idAnimator_AnimWeb::DebugPrint(const char* const format, ...) const {
    if (!debug || format == nullptr) return;
    va_list arguments;
    va_start(arguments, format);
    std::vfprintf(stderr, format, arguments);
    va_end(arguments);
}

void idAnimator_AnimWeb::ClearEvent(const animWebEvent_t eventType) {
    eventHandler.ClearEvent(eventType);
}

void idAnimator_AnimWeb::ClearEvents() { eventHandler.ClearEvents(); }

bool idAnimator_AnimWeb::IsEventPending(
        const animWebEvent_t eventType) const {
    return eventHandler.IsEventPending(eventType);
}

bool idAnimator_AnimWeb::IsAnyEventPending() const {
    return eventHandler.IsAnyEventPending();
}

void idAnimator_AnimWeb::SetEvent(const animWebEvent_t eventType,
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idEventDef& eventDefinition,
        const idAnimWebEvent::priority_t priority) {
    eventHandler.SetEvent(this, subWebIndex, stateIndex, eventType,
        GameLib_GetAnimWebEventNumber(eventDefinition), priority);
}

void idAnimator_AnimWeb::TriggerEvent(const idDeclAnimWebNode* const node,
        const animWebEvent_t eventType, const idAnimWebEvent& event,
        const int eventParameter) {
    InternalTriggerEvent(node, eventType, GetHandle(), event.eventNum,
        eventParameter);
}

bool GameLib_AnimWebNodeMatchesEvent(const idDeclAnimWebNode* const node,
        const idAnimWebSubWebIndex subWeb,
        const idAnimWebStateIndex state) {
    return GameLib_DoesAnimWebNodeMatchEvent(node, subWeb, state);
}

void GameLib_TriggerAnimWebEvent(idAnimator_AnimWeb* const web,
        const idDeclAnimWebNode* const node,
        const animWebEvent_t eventType, const idAnimWebEvent& event,
        const int eventParameter) {
    if (web != nullptr)
        web->TriggerEvent(node, eventType, event, eventParameter);
}

idAnimWebPath idAnimator_AnimWeb::GetDestWebPath(
        const bool includeWebName) const {
    return MakePath(includeWebName ? GameLib_GetAnimWebDeclName(decl) : "",
        destNodeSubWebName.c_str(), destNodeStateName.c_str());
}

idAnimWebPath idAnimator_AnimWeb::GetCurWebPath(
        const bool includeWebName) const {
    return MakePath(includeWebName ? GameLib_GetAnimWebDeclName(decl) : "",
        GetCurSubWebName(), GetCurStateName());
}

const char* idAnimator_AnimWeb::GetCurSubWebName() const {
    return curNodeSubWebName.c_str();
}

const char* idAnimator_AnimWeb::GetCurStateName() const {
    return curNodeStateName.IsEmpty() ? "<NULL>" : curNodeStateName.c_str();
}

idAnimWebSubWebIndex idAnimator_AnimWeb::GetCurSubWebIndex() const {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    const char* subWebName = nullptr;
    const char* stateName = nullptr;
    if (!GameLib_GetAnimWebNodeIdentity(decl, curNodeIndex, subWeb, state,
            subWebName, stateName)) subWeb.Invalidate();
    return subWeb;
}

idAnimWebStateIndex idAnimator_AnimWeb::GetCurStateIndex() const {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    const char* subWebName = nullptr;
    const char* stateName = nullptr;
    if (!GameLib_GetAnimWebNodeIdentity(decl, curNodeIndex, subWeb, state,
            subWebName, stateName)) state.Invalidate();
    return state;
}

bool idAnimator_AnimWeb::GetCurEdgeInfo(
        idAnimWebSubWebIndex& subWebIndex,
        idAnimWebNodeIndex& nodeIndex, blendParms_t& parameters) const {
    if (!curEdgeNodeIndex.IsValid() || curEdgeIndex < 0 || decl == nullptr)
        return false;
    if (curEdgeIndex == 0x7FFF) {
        subWebIndex = forcedEdge.destSubWebIndex;
        nodeIndex = forcedEdge.destNodeIndex;
        parameters = forcedEdge.blendParms;
        return nodeIndex.IsValid();
    }
    return GameLib_GetAnimWebEdgeInfo(decl, curEdgeNodeIndex, curEdgeIndex,
        subWebIndex, nodeIndex, parameters);
}

bool idAnimator_AnimWeb::DecomposeAnimRef(const char* animationReference,
        idStr& subWebName, idStr& stateName) const {
    subWebName.Clear();
    stateName.Clear();
    if (animationReference == nullptr || *animationReference == '\0')
        return false;
    std::string path(animationReference);
    for (char& character : path)
        if (character == '\\' || character == '/') character = ':';
    std::size_t stateStart = path.find_last_of(':');
    if (stateStart == std::string::npos) {
        stateName = path.c_str();
    } else {
        stateName = path.substr(stateStart + 1).c_str();
        while (stateStart > 0 && path[stateStart - 1] == ':') --stateStart;
        const std::size_t subStart = path.find_last_of(':',
            stateStart == 0 ? 0 : stateStart - 1);
        subWebName = path.substr(subStart == std::string::npos ? 0 :
            subStart + 1, stateStart - (subStart == std::string::npos ? 0 :
            subStart + 1)).c_str();
    }
    return InternalRemapNames(subWebName, stateName);
}

bool idAnimator_AnimWeb::GetNodeTotalMovement(
        const idAnimWebModelIndex modelIndex,
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex, idVec3& translation,
        idQuat& rotation) const {
    return GameLib_GetAnimWebNodeMovement(this, modelIndex, subWebIndex,
        stateIndex, translation, rotation);
}

void idAnimator_AnimWeb::CacheCurNode() {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    const char* subWebName = "";
    const char* stateName = "";
    if (!GameLib_GetAnimWebNodeIdentity(decl, curNodeIndex, subWeb, state,
            subWebName, stateName)) {
        subWebName = stateName = "";
    }
    curNodeSubWebName.Set(subWebName);
    curNodeStateName.Set(stateName);
}

void idAnimator_AnimWeb::CacheDestNode() {
    destNodeSubWebName.Set("");
    destNodeStateName.Set("");
    if (curPath.num <= 0) return;
    const idAnimWebNodeIndex node = curPath.path[curPath.num - 1];
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    const char* subWebName = "";
    const char* stateName = "";
    if (GameLib_GetAnimWebNodeIdentity(decl, node, subWeb, state,
            subWebName, stateName)) {
        destNodeSubWebName.Set(subWebName);
        destNodeStateName.Set(stateName);
    }
}

bool idAnimator_AnimWeb::UsesAnyScalarIndices(
        const idList<int, 5>& testScalars) const {
    for (int model = 0; model < modelAnimStates.Num(); ++model) {
        const idModelAnimState& state = modelAnimStates[model];
        for (int treeIndex = 0; treeIndex < state.blendTreeCache.Num();
                ++treeIndex) {
            const idAnimWebBlendTree* tree =
                state.blendTreeCache[treeIndex];
            if (tree != nullptr && tree->UsesAnyScalarIndices(this,
                    testScalars)) return true;
        }
    }
    return false;
}

int idAnimator_AnimWeb::AddBlendVariable(const char* const name,
        float* const scalar, const idAnimWebScalarPair::fieldFlag_t flags) {
    if (name == nullptr || *name == '\0') return -1;
    for (int index = 0; index < scalars.Num(); ++index) {
        idAnimWebScalar& existing = scalars[index];
        if (existing.name == name) {
            if (existing.scalarPtr != nullptr || existing.scalarIndex >= 0)
                return -1;
            existing.flags = flags == idAnimWebScalarPair::FF_NO_OVERRIDE
                ? existing.flags : static_cast<unsigned char>(flags);
            existing.scalarPtr = scalar;
            return index;
        }
    }
    idAnimWebScalar value{};
    value.name.Set(name);
    value.flags = static_cast<unsigned char>(flags);
    value.scalarIndex = -1;
    value.scalarPtr = scalar;
    return scalars.Append(value);
}

float GameLib_GetAnimWebOwnerScalar(const idAnimator_AnimWeb* const web,
        const int scalarIndex) {
    if (web == nullptr || scalarIndex < 0 || scalarIndex >= web->scalars.Num())
        return 0.0f;
    const idAnimWebScalar& scalar = web->scalars[scalarIndex];
    return scalar.scalarPtr != nullptr ? *scalar.scalarPtr : 0.0f;
}

void idAnimator_AnimWeb::Free() {
    for (int index = 0; index < modelAnimStates.Num(); ++index)
        modelAnimStates[index].Free(this);
    modelAnimStates.ClearFree();
    modelDecls.ClearFree();
    initialActiveSubWebs.Clear();
    scalars.ClearFree();
    GameLib_FreeAnimWebScalarMemory(scalarMem);
    scalarMem.floats = nullptr;
    scalarMem.num = 0;
    decl = nullptr;
    ClearStateList(destStateIndices);
    ClearStateList(viaStateIndices);
    destSubWebIndex.Invalidate();
    viaSubWebIndex.Invalidate();
    otherSubWebIndex.Invalidate();
    curEdgeNodeIndex.Invalidate();
    curEdgeIndex = -1;
    pathIndex = -1;
    nodeStartTime = -1;
    prevNodeStartTime = -1;
    nodeStartFrame = 0;
    curNodeIndex.Invalidate();
    prevNodeIndex.Invalidate();
    curPath.num = 0;
    curPath.cost = (std::numeric_limits<int>::max)();
    forcedEdge.destNodeIndex.Invalidate();
    forcedEdge.destSubWebIndex.Invalidate();
    handle.Invalidate();
    CacheCurNode();
    CacheDestNode();
}

void idAnimator_AnimWeb::SetDecl(const idDeclAnimWeb* const declaration,
        const idDeclMD6* const firstModel) {
    for (int index = 0; index < modelAnimStates.Num(); ++index)
        modelAnimStates[index].Free(this);
    modelAnimStates.ClearFree();
    modelDecls.ClearFree();
    decl = declaration;
    declChangeId = declaration != nullptr
        ? GameLib_GetAnimWebDeclChangeId(declaration) : -1;
    if (declaration == nullptr) return;
    const int modelCount = (std::max)(0,
        GameLib_GetAnimWebModelCount(declaration, firstModel));
    modelDecls.SetNum(modelCount);
    modelAnimStates.SetNum(modelCount);
    for (int model = 0; model < modelCount; ++model) {
        modelDecls[model] = GameLib_GetAnimWebModel(declaration, firstModel,
            model);
        modelAnimStates[model].SetDecl(declaration, this,
            idAnimWebModelIndex(static_cast<short>(model)),
            GameLib_GetGameTicksPerSecond());
    }
}

void idAnimator_AnimWeb::InitWeb(
        const idAnimatorParms_AnimWeb& parameters) {
    initialActiveSubWebs.Clear();
    SetDecl(parameters.webDecl, nullptr);
    if (decl == nullptr) return;
    for (int layer = 0; layer < parameters.activeLayers.Num(); ++layer) {
        idAnimWebSubWebIndex subWeb;
        if (GameLib_GetAnimWebLayerSubWeb(decl,
                parameters.activeLayers[layer].c_str(), subWeb))
            initialActiveSubWebs.AddUnique(subWeb);
    }
    InternalInitWeb();
    Reset(parameters.initialSubWebName.c_str(),
        parameters.initialStateName.c_str(), parameters.curTime);
}

void idAnimator_AnimWeb::Reset(const char* const initialSubWebName,
        const char* const initialStateName, const int currentTime) {
    if (decl == nullptr) return;
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    if (!GameLib_ResolveAnimWebNames(decl, initialSubWebName,
            initialStateName, subWeb, state, node)) node.Invalidate();
    SetCurNode(node, node.IsValid() ? currentTime : 0);
    ClearEvents();
}

awPathResult_t idAnimator_AnimWeb::ForceState(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const blendParms_t& parameters, const int blendEvents) {
    if (decl == nullptr) return AWPATH_FAILED;
    const idAnimWebNodeIndex node = GameLib_FindAnimWebNode(decl,
        subWebIndex, stateIndex);
    if (!node.IsValid()) return AWPATH_FAILED;
    curEdgeNodeIndex = curNodeIndex;
    if (node == curNodeIndex) {
        ClearStateList(destStateIndices);
        ClearStateList(viaStateIndices);
        destSubWebIndex.Invalidate();
        viaSubWebIndex.Invalidate();
        otherSubWebIndex.Invalidate();
        curEdgeNodeIndex.Invalidate();
        curEdgeIndex = -1;
        curPath.num = 0;
        curPath.cost = (std::numeric_limits<int>::max)();
        pathIndex = -1;
        forcedEdge.destNodeIndex.Invalidate();
        forcedEdge.destSubWebIndex.Invalidate();
        return AWPATH_ALREADY_THERE;
    }
    forcedEdge.destNodeIndex = node;
    forcedEdge.destSubWebIndex = subWebIndex;
    forcedEdge.blendParms = parameters;
    blendEventMask = blendEvents;
    ClearStateList(destStateIndices);
    ClearStateList(viaStateIndices);
    destSubWebIndex.Invalidate();
    viaSubWebIndex.Invalidate();
    otherSubWebIndex.Invalidate();
    interruptPath = INTR_PATH_YES;
    interruptBlend = INTR_BLEND_YES;
    skipForcedEdgeAutoPath = false;
    if (clearEventsOnStateChanges) ClearEvents();
    return AWPATH_OK;
}

awPathResult_t idAnimator_AnimWeb::ForceState(const char* const subWebName,
        const char* const stateName, const blendParms_t& parameters,
        const int blendEvents) {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    if (!GameLib_ResolveAnimWebNames(decl, subWebName, stateName,
            subWeb, state, node)) return AWPATH_FAILED;
    return ForceState(subWeb, state, parameters, blendEvents);
}

bool idAnimator_AnimWeb::FindPath(const idAnimWebNodeIndex startNode,
        const idAnimWebStateIndex destinationState,
        const idAnimWebSubWebIndex destinationSubWeb,
        const idAnimWebSubWebIndex otherSubWeb,
        idAnimWebRoute& route) const {
    idAnimWebStateList states;
    SetSingleState(states, destinationState);
    return FindPath(startNode, states, destinationSubWeb, otherSubWeb, route);
}

bool idAnimator_AnimWeb::FindPath(const idAnimWebNodeIndex startNode,
        const idAnimWebStateList& destinationStates,
        const idAnimWebSubWebIndex destinationSubWeb,
        const idAnimWebSubWebIndex otherSubWeb,
        idAnimWebRoute& route) const {
    route.num = 0;
    route.cost = (std::numeric_limits<int>::max)();
    return decl != nullptr && GameLib_FindAnimWebRoute(this, startNode,
        &destinationStates, idAnimWebNodeIndex(), destinationSubWeb,
        otherSubWeb, route);
}

bool idAnimator_AnimWeb::FindPath(const idAnimWebNodeIndex startNode,
        const idAnimWebNodeIndex destinationNode,
        const idAnimWebSubWebIndex otherSubWeb,
        idAnimWebRoute& route) const {
    route.num = 0;
    route.cost = (std::numeric_limits<int>::max)();
    return decl != nullptr && GameLib_FindAnimWebRoute(this, startNode,
        nullptr, destinationNode, idAnimWebSubWebIndex(), otherSubWeb,
        route);
}

awPathResult_t idAnimator_AnimWeb::ChangeState(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    return ChangeState(subWebIndex, stateIndex, idAnimWebSubWebIndex(),
        pathInterrupt, blendInterrupt, blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ChangeState(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idAnimWebSubWebIndex requestedOtherSubWeb,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    if (decl == nullptr) return AWPATH_FAILED;
    const idAnimWebNodeIndex destinationNode = GameLib_FindAnimWebNode(decl,
        subWebIndex, stateIndex);
    if (!destinationNode.IsValid()) return AWPATH_FAILED;
    if (destinationNode == curNodeIndex) return AWPATH_ALREADY_THERE;
    idAnimWebRoute route;
    if (!FindPath(curNodeIndex, stateIndex, subWebIndex,
            requestedOtherSubWeb, route)) {
        error = ANIMWEB_ERROR_NOPATH;
        return AWPATH_FAILED;
    }
    curPath = route;
    destSubWebIndex = subWebIndex;
    SetSingleState(destStateIndices, stateIndex);
    viaSubWebIndex.Invalidate();
    ClearStateList(viaStateIndices);
    otherSubWebIndex = requestedOtherSubWeb;
    interruptPath = pathInterrupt;
    interruptBlend = blendInterrupt;
    blendEventMask = blendEvents;
    error = ANIMWEB_ERROR_NONE;
    if (clearEventsOnStateChanges) ClearEvents();
    StartPath(nodeStartTime >= 0 ? nodeStartTime : 0);
    return AWPATH_OK;
}

awPathResult_t idAnimator_AnimWeb::ChangeState(const char* const subWebName,
        const idAnimWebStateIndex stateIndex,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex resolvedState;
    idAnimWebNodeIndex node;
    const char* stateName = nullptr;
    idAnimWebSubWebIndex currentSubWeb;
    if (!GameLib_GetAnimWebNodeIdentity(decl,
            GameLib_FindAnimWebNode(decl, idAnimWebSubWebIndex(), stateIndex),
            currentSubWeb, resolvedState, stateName, stateName)) {
        // The declaration adapter resolves a sub-web with any valid state
        // name; state index remains authoritative in the final lookup.
    }
    if (!GameLib_ResolveAnimWebNames(decl, subWebName, "", subWeb,
            resolvedState, node)) return AWPATH_FAILED;
    return ChangeState(subWeb, stateIndex, pathInterrupt, blendInterrupt,
        blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ChangeState(const char* const subWebName,
        const char* const stateName, const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    if (!GameLib_ResolveAnimWebNames(decl, subWebName, stateName,
            subWeb, state, node)) return AWPATH_FAILED;
    return ChangeState(subWeb, state, pathInterrupt, blendInterrupt,
        blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ChangeStateVia(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idAnimWebSubWebIndex viaSubWeb,
        const idAnimWebStateIndex viaState,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    return ChangeStateVia(subWebIndex, stateIndex, viaSubWeb, viaState,
        idAnimWebSubWebIndex(), pathInterrupt, blendInterrupt, blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ChangeStateVia(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idAnimWebSubWebIndex viaSubWeb,
        const idAnimWebStateIndex viaState,
        const idAnimWebSubWebIndex requestedOtherSubWeb,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    if (decl == nullptr) return AWPATH_FAILED;
    const idAnimWebNodeIndex viaNode = GameLib_FindAnimWebNode(decl,
        viaSubWeb, viaState);
    if (!viaNode.IsValid()) return AWPATH_FAILED;
    idAnimWebRoute firstRoute;
    idAnimWebRoute secondRoute;
    if (!FindPath(curNodeIndex, viaNode, requestedOtherSubWeb, firstRoute) ||
            !FindPath(viaNode, stateIndex, subWebIndex,
                requestedOtherSubWeb, secondRoute)) {
        error = ANIMWEB_ERROR_NOPATH;
        return AWPATH_FAILED;
    }
    firstRoute.AppendPath(secondRoute);
    curPath = firstRoute;
    destSubWebIndex = subWebIndex;
    SetSingleState(destStateIndices, stateIndex);
    viaSubWebIndex = viaSubWeb;
    SetSingleState(viaStateIndices, viaState);
    otherSubWebIndex = requestedOtherSubWeb;
    interruptPath = pathInterrupt;
    interruptBlend = blendInterrupt;
    blendEventMask = blendEvents;
    error = ANIMWEB_ERROR_NONE;
    if (clearEventsOnStateChanges) ClearEvents();
    StartPath(nodeStartTime >= 0 ? nodeStartTime : 0);
    return AWPATH_OK;
}

awPathResult_t idAnimator_AnimWeb::ChangeStateVia(
        const char* const subWebName,
        const idAnimWebStateIndex stateIndex,
        const char* const viaSubWebName,
        const idAnimWebStateIndex viaState,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex unusedState;
    idAnimWebNodeIndex unusedNode;
    idAnimWebSubWebIndex viaSubWeb;
    if (!GameLib_ResolveAnimWebNames(decl, subWebName, "", subWeb,
            unusedState, unusedNode) ||
            !GameLib_ResolveAnimWebNames(decl, viaSubWebName, "",
                viaSubWeb, unusedState, unusedNode)) return AWPATH_FAILED;
    return ChangeStateVia(subWeb, stateIndex, viaSubWeb, viaState,
        pathInterrupt, blendInterrupt, blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ChangeStateVia(
        const char* const subWebName, const char* const stateName,
        const char* const viaSubWebName, const char* const viaStateName,
        const interruptPath_t pathInterrupt,
        const interruptBlend_t blendInterrupt, const int blendEvents) {
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    idAnimWebSubWebIndex viaSubWeb;
    idAnimWebStateIndex viaState;
    if (!GameLib_ResolveAnimWebNames(decl, subWebName, stateName,
            subWeb, state, node) ||
            !GameLib_ResolveAnimWebNames(decl, viaSubWebName,
                viaStateName, viaSubWeb, viaState, node))
        return AWPATH_FAILED;
    return ChangeStateVia(subWeb, state, viaSubWeb, viaState,
        pathInterrupt, blendInterrupt, blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ForceAndChangeState(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idAnimWebSubWebIndex forcedSubWeb,
        const idAnimWebStateIndex forcedState,
        const blendParms_t& parameters, const int blendEvents) {
    return ForceAndChangeState(subWebIndex, stateIndex, forcedSubWeb,
        forcedState, idAnimWebSubWebIndex(), parameters, blendEvents);
}

awPathResult_t idAnimator_AnimWeb::ForceAndChangeState(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idAnimWebSubWebIndex forcedSubWeb,
        const idAnimWebStateIndex forcedState,
        const idAnimWebSubWebIndex requestedOtherSubWeb,
        const blendParms_t& parameters, const int blendEvents) {
    const awPathResult_t forced = ForceState(forcedSubWeb, forcedState,
        parameters, blendEvents);
    if (forced == AWPATH_FAILED) return forced;
    return ChangeState(subWebIndex, stateIndex, requestedOtherSubWeb,
        INTR_PATH_YES, INTR_BLEND_YES, blendEvents);
}

void idAnimator_AnimWeb::StartPath(const int currentTime) {
    if (curPath.num <= 0) {
        pathIndex = -1;
        return;
    }
    pathIndex = 0;
    if (curPath.path[0] == curNodeIndex && curPath.num > 1) pathIndex = 0;
    nodeStartTime = currentTime;
    CacheDestNode();
    InternalStartPath();
}

idAnimWebBlendTree* idAnimator_AnimWeb::AllocBlendTrees(
        const idAnimWebNodeIndex nodeIndex,
        const idAnimWebNodeIndex keepNodeIndex) {
    if (decl == nullptr || !nodeIndex.IsValid()) return nullptr;
    idAnimWebBlendTree* primary = nullptr;
    for (int model = 0; model < modelAnimStates.Num(); ++model) {
        const idAnimWebModelIndex modelIndex(static_cast<short>(model));
        const idDeclAnimWebNode* node = nullptr;
        const void* modelInfo = nullptr;
        const char* blendEquation = nullptr;
        const idMD6AnimProps* properties = nullptr;
        int propertyCount = 0;
        if (!GameLib_GetAnimWebNodeModelInfo(decl, nodeIndex, modelIndex,
                node, modelInfo, blendEquation, properties, propertyCount))
            continue;
        idModelAnimState& state = modelAnimStates[model];
        idAnimWebBlendTree* tree = state.GetBlendTree(nodeIndex);
        if (tree == nullptr) {
            tree = state.AllocBlendTree(nodeIndex, keepNodeIndex);
            if (tree == nullptr || !tree->Init(this, node,
                    static_cast<short>(model), blendEquation, modelInfo,
                    GameLib_GetGameTicksPerSecond())) {
                state.FreeBlendTree(nodeIndex);
                continue;
            }
        }
        if (model == 0) primary = tree;
    }
    return primary;
}

void idAnimator_AnimWeb::SetCurNode(const idAnimWebNodeIndex nodeIndex,
        const int currentTime) {
    prevNodeIndex.Invalidate();
    curEdgeNodeIndex.Invalidate();
    curEdgeIndex = -1;
    if (!nodeIndex.IsValid()) {
        curNodeIndex.Invalidate();
        ClearStateList(destStateIndices);
        destSubWebIndex.Invalidate();
        for (int model = 0; model < modelAnimStates.Num(); ++model) {
            modelAnimStates[model].tree = nullptr;
            modelAnimStates[model].blending = false;
        }
        CacheCurNode();
        return;
    }
    curNodeIndex = nodeIndex;
    AllocBlendTrees(nodeIndex, idAnimWebNodeIndex());
    const idDeclAnimWebNode* node = GameLib_GetAnimWebNode(decl, nodeIndex);
    InternalStartBlend(nullptr, node, currentTime);
    BeginNodesPlaying(nodeIndex, currentTime);
    ClearStateList(destStateIndices);
    destSubWebIndex.Invalidate();
    for (int model = 0; model < modelAnimStates.Num(); ++model)
        InternalSetAnimDelta(idAnimWebModelIndex(static_cast<short>(model)),
            node);
    if (mergeBranch != nullptr) {
        const float alpha = GameLib_IsAnimWebNodeBlendOut(node) ? 0.0f : 1.0f;
        mergeBranch->currentAlpha = alpha;
        mergeBranch->targetAlpha = alpha;
    }
    CacheCurNode();
}

void idAnimator_AnimWeb::SetCurNode(
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex, const int currentTime) {
    if (decl != nullptr)
        SetCurNode(GameLib_FindAnimWebNode(decl, subWebIndex, stateIndex),
            currentTime);
}

void idAnimator_AnimWeb::BeginNodesPlaying(
        const idAnimWebNodeIndex nodeIndex, const int currentTime) {
    for (int model = 0; model < modelAnimStates.Num(); ++model) {
        const idDeclAnimWebNode* node = nullptr;
        const void* modelInfo = nullptr;
        const char* blendEquation = nullptr;
        const idMD6AnimProps* properties = nullptr;
        int propertyCount = 0;
        if (GameLib_GetAnimWebNodeModelInfo(decl, nodeIndex,
                idAnimWebModelIndex(static_cast<short>(model)), node,
                modelInfo, blendEquation, properties, propertyCount)) {
            modelAnimStates[model].BeginNodePlaying(this, modelInfo,
                nodeIndex, currentTime, GameLib_GetGameTicksPerSecond());
        }
    }
}

const idMD6Leaf* idAnimator_AnimWeb::FindFirstLeaf(
        const idMD6Node* const node, const int modelIndex,
        const bool ignoreAdditive) const {
    if (node == nullptr) return nullptr;
    if (node->type == idMD6Node::NODE_LEAF_PLAY ||
            node->type == idMD6Node::NODE_LEAF_PAUSE) {
        const idMD6Leaf* leaf = static_cast<const idMD6Leaf*>(node);
        return ignoreAdditive && GameLib_IsMD6LeafAdditive(leaf, modelIndex)
            ? nullptr : leaf;
    }
    if (node->type <= idMD6Node::NODE_TAG_FILTER) {
        const idMD6Branch* branch = static_cast<const idMD6Branch*>(node);
        if (const idMD6Leaf* left = FindFirstLeaf(branch->left, modelIndex,
                ignoreAdditive)) return left;
        return FindFirstLeaf(branch->right, modelIndex, ignoreAdditive);
    }
    return nullptr;
}

const idMD6Leaf* idAnimator_AnimWeb::FindLeafWithMatchingAnim(
        const idMD6Node* const node, const int modelIndex,
        const idMD6Anim* const animation, const bool ignoreAdditive) const {
    if (node == nullptr) return nullptr;
    if (node->type == idMD6Node::NODE_LEAF_PLAY ||
            node->type == idMD6Node::NODE_LEAF_PAUSE) {
        const idMD6Leaf* leaf = static_cast<const idMD6Leaf*>(node);
        return leaf->anim == animation &&
            !(ignoreAdditive && GameLib_IsMD6LeafAdditive(leaf, modelIndex))
            ? leaf : nullptr;
    }
    if (node->type <= idMD6Node::NODE_TAG_FILTER) {
        const idMD6Branch* branch = static_cast<const idMD6Branch*>(node);
        if (const idMD6Leaf* left = FindLeafWithMatchingAnim(branch->left,
                modelIndex, animation, ignoreAdditive)) return left;
        return FindLeafWithMatchingAnim(branch->right, modelIndex,
            animation, ignoreAdditive);
    }
    return nullptr;
}

bool idAnimator_AnimWeb::GetNodeAnimLength(const int currentTime,
        const idAnimWebModelIndex modelIndex,
        const idAnimWebNodeIndex nodeIndex,
        const idMD6Leaf::wrapMode_t wrapMode, const bool ignoreAdditive,
        animInfo_t& animationInfo) const {
    animationInfo = {0, 0, 0};
    const int model = modelIndex.Get();
    if (model < 0 || model >= modelAnimStates.Num()) return false;
    const idAnimWebBlendTree* tree =
        modelAnimStates[model].GetBlendTree(nodeIndex);
    return tree != nullptr && tree->GetAnimLength(currentTime,
        GameLib_GetGameTicksPerSecond(), wrapMode, ignoreAdditive,
        animationInfo.curFrame, animationInfo.numFrames,
        animationInfo.frameRate);
}

bool idAnimator_AnimWeb::GetNodeAnimLength(const int currentTime,
        const idAnimWebModelIndex modelIndex,
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const idMD6Leaf::wrapMode_t wrapMode, const bool ignoreAdditive,
        animInfo_t& animationInfo) const {
    return GetNodeAnimLength(currentTime, modelIndex,
        GameLib_FindAnimWebNode(decl, subWebIndex, stateIndex), wrapMode,
        ignoreAdditive, animationInfo);
}

bool idAnimator_AnimWeb::GetNodeAnimLength(const int currentTime,
        const idAnimWebModelIndex modelIndex,
        const idAnimWebNodeIndex nodeIndex,
        animInfo_t& animationInfo) const {
    return GetNodeAnimLength(currentTime, modelIndex, nodeIndex,
        idMD6Leaf::WRAP_MAX, false, animationInfo);
}

void idAnimator_AnimWeb::SelectRandomBlendVals(
        const idDeclAnimWebNode*, const idDeclAnimWebNode*) {
    for (float& value : randomBlendVals)
        value = static_cast<float>(std::rand()) /
            static_cast<float>(RAND_MAX);
}

void idAnimator_AnimWeb::Reinitialize(const int currentTime) {
    if (decl == nullptr) return;
    const idDeclAnimWeb* currentDeclaration = decl;
    const idStr currentSubWeb(curNodeSubWebName.c_str());
    const idStr currentState(curNodeStateName.c_str());
    const idStr destinationSubWeb(destNodeSubWebName.c_str());
    const idStr destinationState(destNodeStateName.c_str());
    SetDecl(currentDeclaration, nullptr);
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    if (GameLib_ResolveAnimWebNames(decl, currentSubWeb.c_str(),
            currentState.c_str(), subWeb, state, node)) {
        SetCurNode(node, currentTime);
        if (destinationState.Length() > 0)
            ChangeState(destinationSubWeb.c_str(), destinationState.c_str(),
                INTR_PATH_YES, INTR_BLEND_YES, 0);
    } else {
        SetCurNode(idAnimWebNodeIndex(), 0);
    }
}

void idAnimator_AnimWeb::Update(const int currentTime,
        const int ticksPerSecond) {
    if (decl == nullptr) return;
    if (declChangeId != GameLib_GetAnimWebDeclChangeId(decl))
        Reinitialize(currentTime);
    InternalUpdateScalars(currentTime);
    for (int model = 0; model < modelAnimStates.Num(); ++model)
        modelAnimStates[model].Update(currentTime);
    GameLib_UpdateAnimWebTransition(this, currentTime, ticksPerSecond);
    InternalUpdate(currentTime);
}

void idAnimator_AnimWeb::InternalPreBlendTree(const idAnimStack* const stack,
        const int currentTime, const int ticksPerSecond) {
    Update(currentTime, ticksPerSecond);
    for (int model = 0; model < modelAnimStates.Num(); ++model) {
        const idModelAnimState& state = modelAnimStates[model];
        for (int treeIndex = 0; treeIndex < state.blendTreeCache.Num();
                ++treeIndex) {
            if (state.blendTreeCache[treeIndex] != nullptr)
                state.blendTreeCache[treeIndex]->PreBlendTree(this,
                    currentTime, ticksPerSecond);
        }
    }
    InternalUpdateBlendEvents(stack, currentTime, ticksPerSecond);
}
