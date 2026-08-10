#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/array.h"
#include "idlib/containers/list.h"
#include "idlib/containers/pair.h"
#include "models/skeletalanimation/jobs/md6blend.h"

class idDeclAnimWebTagGroup;
class idMD6Filter;
class idMD6Skel;

enum idMD6BlendBranchFlags_t : int {
    MD6_BLENDBRANCH_NORMAL = 0,
    MD6_BLENDBRANCH_ANGLEWRAP = 1
};

class idMD6BlendBranch_Base : public idMD6Branch {
public:
    idList<float, 30> coordinateList;
    idList<idMD6Node*, 30> animationList;
};

class idMD6BlendBranch : public idMD6BlendBranch_Base {
public:
    idList<float, 30> currentCoordinate;
    idList<idUserChannelIndex, 30> userChannelIndices;
    idList<float, 30> activeCoordinate;
    idList<int, 30> activeIndices;
    idList<idMD6Branch, 30> branchList;
    std::uint8_t numDimensions;
    bool isAngleWrapped;
};

class idMD6BlendAdditiveBranch : public idMD6BlendBranch_Base {
public:
    float currentCoordinate;
    float activeCoordinate;
    idMD6Node* baseAnimation;
};

class idMD6FusionBranch : public idMD6BlendBranch {
public:
    idList<unsigned short, 30> phaseToFrameLookupData;
};

class idMD6Filter : public idMD6Node {};

class alignas(4) idMD6TagFilter : public idMD6Filter {
public:
    const idDeclAnimWebTagGroup* tagGroup;
    unsigned int tagMask;
    std::uint8_t tagGroupIndex;
    std::uint8_t tagBias;
};

struct idMD6DebugFilterLogicHelper_t {};

class idMD6BestLeaf : public idMD6Node {
public:
    idList<idMD6Node*, 30> leafList;
    idList<unsigned int, 30> tagList;
    idList<idMD6Filter*, 30> filterList;
    idMD6TagFilter tagGroupFilter;
    idMD6DebugFilterLogicHelper_t debugFilterLogicHelper;
    const idDeclAnimWebTagGroup* tagGroup;
    unsigned int desiredTag;
    unsigned int activeTag;
    unsigned int defaultTag;
    std::uint16_t bestLeafIndex;
    std::uint8_t tagBias;
    std::uint8_t tagGroupIndex;
};

namespace idMD6AnimTree {

using TagFilterCallback = bool (*)(const idMD6TagFilter& filter,
    unsigned int candidateTag, const idMD6DebugFilterLogicHelper_t& helper);

void SetTagFilterCallback(TagFilterCallback callback);
bool IsValid(const idMD6Node* node);

void Clear(idMD6LeafPlay& leaf);
void Init(idMD6LeafPlay& leaf, const idMD6Anim* animation, int gameTime,
    int ticksPerSecond, int frame, float rate,
    idMD6Leaf::wrapMode_t wrapMode, md6WeightGroup_t weightGroup);
void Restart(idMD6LeafPlay& leaf, int gameTime, int ticksPerSecond,
    int frame, idMD6Leaf::wrapMode_t wrapMode);
int GetFrameRate(const idMD6Leaf& leaf);
int GetLength(const idMD6Leaf& leaf, int ticksPerSecond = 1000);
void SetFrameTime(idMD6LeafPlay& leaf, int gameTime, int targetTime);
int GetFrameTime(const idMD6LeafPlay& leaf, int gameTime);
int GetFrameTicks(const idMD6LeafPlay& leaf, int gameTime);
int GetAnimLength(const idMD6LeafPlay& leaf, int ticksPerSecond = 1000,
    bool scaled = true);
int GetAnimTicks(const idMD6LeafPlay& leaf, int ticksPerSecond = 1000);
float GetFloatFrame(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond = 1000);
unsigned short GetFrame(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond = 1000);
void SetFloatFrame(idMD6LeafPlay& leaf, int gameTime, int ticksPerSecond,
    float frame);
void SetFrame(idMD6LeafPlay& leaf, int gameTime, int ticksPerSecond,
    unsigned short frame);
void SetRateScale(idMD6LeafPlay& leaf, int gameTime, float scale,
    int ticksPerSecond = 1000);
int GetLoopCount(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond = 1000);
bool IsPlaying(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond = 1000);
bool IsPlaying(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond, bool clampIgnoreExtraFrame);
bool IsPlaying(const idMD6LeafPlay& leaf, int gameTime,
    int ticksPerSecond, idMD6Leaf::wrapMode_t wrapMode);

void Clear(idMD6LeafPause& leaf);
void Init(idMD6LeafPause& leaf, const idMD6Anim* animation, float frame,
    idMD6Leaf::wrapMode_t wrapMode, md6WeightGroup_t weightGroup);
void SetUseStackTop(idMD6LeafPause& leaf, bool enabled);
void SetClearNonModWeights(idMD6LeafPause& leaf, bool enabled);
void SetOverrideFrameBounds(idMD6LeafPause& leaf, bool enabled);
void SetNumAnimMods(idMD6LeafPause& leaf, int count);

void Init(idMD6Branch& branch, idMD6Node* left, idMD6Node* right,
    idMD6Blend::blendOp_t operation, idMD6Blend::originBlend_t originBlend,
    float currentAlpha, float targetAlpha, float alphaRate,
    md6WeightGroup_t filterGroup, idMD6Branch::blendType_t blendType);
void UpdateCurrentAlpha(idMD6Branch& branch, int time, int previousTime,
    int ticksPerSecond = 1000);
bool IsBlendFinished(const idMD6Branch& branch);
bool IsChildBlendedOut(const idMD6Branch& branch, const idMD6Node* child);
bool IsBlendingOut(const idMD6Branch& branch);
bool IsBlendingIn(const idMD6Branch& branch);

void Init(idMD6BlendAdditiveBranch& branch, idMD6Node* baseAnimation,
    const idList<float, 5>& coordinates,
    const idList<idMD6Node*, 5>& animations, float coordinate,
    md6WeightGroup_t weightGroup);
void Update(idMD6BlendAdditiveBranch& branch, bool force);
void FindAnimation(const idMD6BlendAdditiveBranch& branch,
    idMD6Node*& animation, float& alpha);
void InitCoordinateNodePairs(idMD6BlendBranch_Base& branch,
    int dimensions, const idList<float, 5>& coordinates,
    const idList<idMD6Node*, 5>& animations, int flags);
void Init(idMD6BlendBranch& branch, std::uint8_t dimensions,
    const idList<idUserChannelIndex, 5>& userChannelIndices,
    const idList<float, 5>& coordinates,
    const idList<idMD6Node*, 5>& animations,
    const idList<float, 5>& initialCoordinates,
    md6WeightGroup_t weightGroup, int flags);
void Update(idMD6BlendBranch& branch, bool force, bool isSorted);
void FindAnimation(idMD6BlendBranch& branch, bool isSorted,
    idMD6Node*& leftAnimation, idMD6Node*& rightAnimation, float& alpha);
void FindBarycentric(idMD6BlendBranch& branch,
    idList<idPair<float, idMD6Node*>, 5>& leaves);
bool BuildPointList(idMD6BlendBranch& branch, idList<int, 5>& indices);
bool SolveGaussian(int dimensions, float* matrix, float* values,
    float* output);
void Init(idMD6FusionBranch& branch, std::uint8_t dimensions,
    const idList<idUserChannelIndex, 5>& userChannelIndices,
    const idList<float, 5>& coordinates,
    const idList<idMD6Node*, 5>& animations,
    const idList<float, 5>& initialCoordinates,
    md6WeightGroup_t weightGroup, int flags);
void Update(idMD6FusionBranch& branch, bool force, int gameTime,
    int ticksPerSecond, const idMD6Skel* skeleton);

void Init(idMD6TagFilter& filter, std::uint8_t groupIndex,
    unsigned int tagMask, std::uint8_t bias,
    const idDeclAnimWebTagGroup* group);
bool Filter(const idMD6TagFilter& filter, unsigned int tag,
    const idMD6DebugFilterLogicHelper_t& helper);
void Init(idMD6BestLeaf& best, std::uint8_t tagBias,
    unsigned int tagMask, std::uint8_t tagGroupIndex,
    const idList<idMD6Node*, 5>& leaves,
    const idList<unsigned int, 5>& tags,
    const idList<idMD6Filter*, 5>& filters, unsigned int defaultTag,
    const idDeclAnimWebTagGroup* group);
void Update(idMD6BestLeaf& best);

} // namespace idMD6AnimTree
