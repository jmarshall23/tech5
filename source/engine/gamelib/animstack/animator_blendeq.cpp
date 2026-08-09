#include "gamelib/animstack/animator_blendeq.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Tree(idAnimStack* stack, idMD6Node* root);
bool GameLib_ParseAnimBlendEquation(idAnimStack* stack, int startTime,
    const char* equation, const void* modelInfo,
    idList<idAnimWebScalar, 33>& scalars,
    const idList<idAnimator_BlendEq::idNamedAnim, 33>& namedAnimations,
    idList<idAnimWebScalarPair, 33>& scalarPairs, idMD6Node*& tree);
float GameLib_GetAnimWebScalar(const idAnimWebScalar& scalar,
    const idScalarMemBlock* memory);
void GameLib_ApplyAnimWebScalar(const idAnimWebScalarPair& pair,
    float value, int currentTime,
    const idList<idAnimator_BlendEq::idNamedAnim, 33>& namedAnimations);
void GameLib_RebindAnimWebScalars(idList<idAnimWebScalar, 33>& scalars,
    idScalarMemBlock* memory);

namespace {
void InitBranch(idMD6Branch& branch) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_BlendEq::idAnimator_BlendEq()
    : idAnimator_Base()
    , blendEq()
    , mergeBranch(nullptr)
    , scalars(16)
    , scalarPairs(16)
    , scalarMem(nullptr)
    , namedAnims(16) {
}

idAnimator_BlendEq::~idAnimator_BlendEq() {
    scalarMem = nullptr;
}

void idAnimator_BlendEq::SetNamedAnims(
        const idList<idNamedAnim, 33>& animations) {
    namedAnims = animations;
}

bool idAnimator_BlendEq::InternalInit(
        const idAnimatorParms_Base& parameters) {
    const auto& blendParameters =
        static_cast<const idAnimatorParms_BlendEq&>(parameters);
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    InitBranch(*mergeBranch);
    scalars.SetNum(blendParameters.scalars.Num());
    for (int index = 0; index < scalars.Num(); ++index)
        scalars[index] = blendParameters.scalars[index];
    scalarMem = blendParameters.scalarMem;
    namedAnims.SetNum(blendParameters.anims.Num());
    for (int index = 0; index < namedAnims.Num(); ++index)
        namedAnims[index] = blendParameters.anims[index];
    SetBlendEquation(parameters.animStack, 0,
        blendParameters.blendEq.c_str(), nullptr);
    return true;
}

void idAnimator_BlendEq::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Tree(stack, mergeBranch->right);
        GameLib_FreeMD6Tree(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    scalarPairs.Clear();
}

void idAnimator_BlendEq::ParseBlendEquation(idAnimStack* const stack,
        const int startTime, const void* const modelInfo) {
    if (mergeBranch == nullptr) return;
    idMD6Node* oldTree = mergeBranch->right;
    idMD6Node* newTree = nullptr;
    scalarPairs.Clear();
    if (GameLib_ParseAnimBlendEquation(stack, startTime, blendEq.c_str(),
            modelInfo, scalars, namedAnims, scalarPairs, newTree)) {
        mergeBranch->right = newTree;
        if (oldTree != newTree) GameLib_FreeMD6Tree(stack, oldTree);
    }
}

void idAnimator_BlendEq::SetBlendEquation(idAnimStack* const stack,
        const int startTime, const char* const equation,
        const void* const modelInfo) {
    blendEq = equation != nullptr ? equation : "";
    ParseBlendEquation(stack, startTime, modelInfo);
    if (scalarMem != nullptr) {
        GameLib_RebindAnimWebScalars(scalars, scalarMem);
    }
}

void idAnimator_BlendEq::CopyScalars(const idAnimStack*,
        const int currentTime, const unsigned char fieldFlags) {
    if (scalarMem == nullptr) return;
    for (int index = 0; index < scalarPairs.Num(); ++index) {
        const idAnimWebScalarPair& pair = scalarPairs[index];
        if ((fieldFlags & pair.fieldFlags) == 0 || pair.scalarIndex < 0 ||
                pair.scalarIndex >= scalars.Num()) {
            continue;
        }
        GameLib_ApplyAnimWebScalar(pair,
            GameLib_GetAnimWebScalar(scalars[pair.scalarIndex], scalarMem),
            currentTime, namedAnims);
    }
}

void idAnimator_BlendEq::InternalStart(const idAnimStack* const stack,
        const int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t>) {
    CopyScalars(stack, currentTime, idAnimWebScalarPair::FF_COPY_ON_PLAY);
}

void idAnimator_BlendEq::InternalPreBlendTree(
        const idAnimStack* const stack, const int currentTime, int) {
    CopyScalars(stack, currentTime,
        idAnimWebScalarPair::FF_COPY_PRE_BLEND);
}
