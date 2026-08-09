#include "gamelib/animstack/animweb/animwebblendtree.h"

bool GameLib_InitAnimWebBlendTree(idAnimator_AnimWeb* web,
    const idDeclAnimWebNode* node, short modelIndex,
    const char* blendEquation, const void* modelInfo, int ticksPerSecond,
    idMD6Node*& tree, idList<idAnimWebScalarPair, 33>& scalarPairs,
    idList<const idMD6LeafPlay*, 33>& leaves);
void GameLib_FreeAnimWebBlendTree(idAnimator_AnimWeb* web,
    idMD6Node* tree);
void GameLib_BeginAnimWebBlendTree(idAnimator_AnimWeb* web,
    idMD6Node* tree, short modelIndex,
    const idMD6AnimProps* animationProperties, int propertyCount,
    int currentTime, int ticksPerSecond);
bool GameLib_GetAnimWebBlendTreeLength(const idMD6Node* tree,
    int currentTime, int ticksPerSecond, idMD6Leaf::wrapMode_t wrapMode,
    bool ignoreAdditive, int& currentFrame, int& frameCount,
    int& frameRate);
float GameLib_GetAnimWebOwnerScalar(const idAnimator_AnimWeb* web,
    int scalarIndex);
void GameLib_ApplyAnimWebTreeScalar(const idAnimWebScalarPair& pair,
    float value, int currentTime, int ticksPerSecond);

idAnimWebBlendTree::idAnimWebBlendTree(const idAnimWebNodeIndex node)
    : tree(nullptr)
    , nodeIndex(node)
    , modelIndex(0)
    , web(nullptr)
    , scalarPairs(16)
    , leaves(16) {
}

idAnimWebBlendTree::~idAnimWebBlendTree() {
    Free();
    web = nullptr;
}

bool idAnimWebBlendTree::Init(idAnimator_AnimWeb* const owner,
        const idDeclAnimWebNode* const node, const short model,
        const char* const blendEquation, const void* const modelInfo,
        const int ticksPerSecond) {
    Free();
    web = owner;
    modelIndex = model;
    return GameLib_InitAnimWebBlendTree(owner, node, model,
        blendEquation, modelInfo, ticksPerSecond, tree, scalarPairs,
        leaves);
}

void idAnimWebBlendTree::Free() {
    leaves.Clear();
    scalarPairs.Clear();
    if (tree != nullptr) {
        GameLib_FreeAnimWebBlendTree(web, tree);
        tree = nullptr;
    }
}

bool idAnimWebBlendTree::UsesAnyScalarIndices(
        const idAnimator_AnimWeb*,
        const idList<int, 5>& testScalars) const {
    for (int pairIndex = 0; pairIndex < scalarPairs.Num(); ++pairIndex)
        if (testScalars.FindIndex(scalarPairs[pairIndex].scalarIndex) >= 0)
            return true;
    return false;
}

void idAnimWebBlendTree::GetUsedScalarIndices(
        const idAnimator_AnimWeb*, idList<int, 5>& usedScalars,
        const int minimumIndex, const int maximumIndex) const {
    for (int pairIndex = 0; pairIndex < scalarPairs.Num(); ++pairIndex) {
        const int scalarIndex = scalarPairs[pairIndex].scalarIndex;
        if ((minimumIndex < 0 || scalarIndex >= minimumIndex) &&
                (maximumIndex < 0 || scalarIndex <= maximumIndex)) {
            usedScalars.AddUnique(scalarIndex);
        }
    }
}

void idAnimWebBlendTree::CopyScalars(const idAnimator_AnimWeb* const owner,
        const int currentTime, const int ticksPerSecond,
        const unsigned char fieldFlags) const {
    for (int pairIndex = 0; pairIndex < scalarPairs.Num(); ++pairIndex) {
        const idAnimWebScalarPair& pair = scalarPairs[pairIndex];
        if ((pair.fieldFlags & fieldFlags) != 0) {
            GameLib_ApplyAnimWebTreeScalar(pair,
                GameLib_GetAnimWebOwnerScalar(owner, pair.scalarIndex),
                currentTime, ticksPerSecond);
        }
    }
}

void idAnimWebBlendTree::BeginPlaying(idAnimator_AnimWeb* const owner,
        const idMD6AnimProps* const animationProperties,
        const int propertyCount, const int currentTime,
        const int ticksPerSecond) {
    CopyScalars(owner, currentTime, ticksPerSecond,
        idAnimWebScalarPair::FF_COPY_ON_PLAY);
    GameLib_BeginAnimWebBlendTree(owner, tree, modelIndex,
        animationProperties, propertyCount, currentTime, ticksPerSecond);
}

void idAnimWebBlendTree::PreBlendTree(const idAnimator_AnimWeb* const owner,
        const int currentTime, const int ticksPerSecond) const {
    CopyScalars(owner, currentTime, ticksPerSecond,
        idAnimWebScalarPair::FF_COPY_PRE_BLEND);
}

bool idAnimWebBlendTree::GetAnimLength(const int currentTime,
        const int ticksPerSecond, const idMD6Leaf::wrapMode_t wrapMode,
        const bool ignoreAdditive, int& currentFrame, int& frameCount,
        int& frameRate) const {
    frameCount = 0;
    return tree != nullptr && GameLib_GetAnimWebBlendTreeLength(tree,
        currentTime, ticksPerSecond, wrapMode, ignoreAdditive,
        currentFrame, frameCount, frameRate);
}
