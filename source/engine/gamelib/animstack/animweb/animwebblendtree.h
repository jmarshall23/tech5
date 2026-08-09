#pragma once

#include "decls/animwebs/animwebscalar.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"

class idAnimator_AnimWeb;
class idDeclAnimWebNode;
class idMD6AnimProps;

class idAnimWebBlendTree {
public:
    explicit idAnimWebBlendTree(idAnimWebNodeIndex node =
        idAnimWebNodeIndex());
    ~idAnimWebBlendTree();

    bool Init(idAnimator_AnimWeb* owner, const idDeclAnimWebNode* node,
        short model, const char* blendEquation, const void* modelInfo,
        int ticksPerSecond);
    void Free();
    void BeginPlaying(idAnimator_AnimWeb* owner,
        const idMD6AnimProps* animationProperties, int propertyCount,
        int currentTime, int ticksPerSecond);
    void PreBlendTree(const idAnimator_AnimWeb* owner, int currentTime,
        int ticksPerSecond) const;
    bool GetAnimLength(int currentTime, int ticksPerSecond,
        idMD6Leaf::wrapMode_t wrapMode, bool ignoreAdditive,
        int& currentFrame, int& frameCount, int& frameRate) const;
    bool UsesAnyScalarIndices(const idAnimator_AnimWeb* owner,
        const idList<int, 5>& testScalars) const;
    void GetUsedScalarIndices(const idAnimator_AnimWeb* owner,
        idList<int, 5>& usedScalars, int minimumIndex,
        int maximumIndex) const;

    idMD6Node* tree;
    idAnimWebNodeIndex nodeIndex;
    short modelIndex;
    idAnimator_AnimWeb* web;
    idList<idAnimWebScalarPair, 33> scalarPairs;
    idList<const idMD6LeafPlay*, 33> leaves;

private:
    void CopyScalars(const idAnimator_AnimWeb* owner, int currentTime,
        int ticksPerSecond, unsigned char fieldFlags) const;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimWebBlendTree) == 44,
    "Recovered idAnimWebBlendTree ABI changed");
#endif
