#include "gameanimtools.h"

#include "models/skeletalanimation/md6anim.h"

#include <algorithm>
#include <cmath>

namespace {

bool IsBranch(const idMD6Node* const node) {
    if (node == nullptr) {
        return false;
    }
    return node->type == idMD6Node::NODE_BRANCH
        || node->type == idMD6Node::NODE_BLEND_BRANCH
        || node->type == idMD6Node::NODE_BLENDA_BRANCH
        || node->type == idMD6Node::NODE_FUSION_BRANCH;
}

} // namespace

idGameAnimToolsLocal::idGameAnimToolsLocal()
    : guiModel(nullptr), nodeWidth(160.0f), nodeHeight(72.0f),
      whiteMaterial(nullptr), branchColor(0.0f, 0.0f, 0.3f, 0.75f),
      leafColor(0.0f, 0.3f, 0.0f, 0.75f),
      outlineColor(0.75f, 0.75f, 0.75f, 1.0f),
      textColor(1.0f, 1.0f, 1.0f, 1.0f),
      linkColor(0.75f, 0.75f, 0.75f, 1.0f), services(nullptr) {
}

// Retail symbol: ??1idGameAnimToolsLocal@@UAA@XZ
// EA: 0x82B34570, RVA: 0x00B34570
idGameAnimToolsLocal::~idGameAnimToolsLocal() {
    if (guiModel != nullptr && services != nullptr) {
        services->ReleaseGuiModel(guiModel);
    }
    guiModel = nullptr;
}

// Retail symbol: ?DrawBlendTreeBranch@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Branch@@@Z
// EA: 0x82B34668, RVA: 0x00B34668
void idGameAnimToolsLocal::DrawBlendTreeBranch(idDeviceContext& context,
        const float x, const float y, const idMD6Branch* const branch) {
    if (branch != nullptr && services != nullptr) {
        services->DrawBranch(*this, context, x, y, branch);
    }
}

// Retail symbol: ?GetAnimNumFrames@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBVidMD6Anim@@@Z
// EA: 0x82B348D0, RVA: 0x00B348D0
int idGameAnimToolsLocal::GetAnimNumFrames(const idTreeAnimator*,
        const idMD6Anim* const animation) {
    return animation != nullptr && animation->animData != nullptr
        ? animation->animData->numFrames : 0;
}

// Retail symbol: ?TreeMaxNodeWidth_r@idGameAnimToolsLocal@@AAAHAAVidDeviceContext@@PBVidMD6Node@@@Z
// EA: 0x82B348F8, RVA: 0x00B348F8
int idGameAnimToolsLocal::TreeMaxNodeWidth_r(idDeviceContext& context,
        const idMD6Node* const node) {
    if (node == nullptr) {
        return 0;
    }
    int width = services != nullptr ? services->MeasureNode(node) : 0;
    if (IsBranch(node)) {
        const idMD6Branch* const branch
            = static_cast<const idMD6Branch*>(node);
        width = (std::max)(width,
            TreeMaxNodeWidth_r(context, branch->left));
        width = (std::max)(width,
            TreeMaxNodeWidth_r(context, branch->right));
    }
    return width;
}

// Retail symbol: ?TreeDepth_r@idGameAnimToolsLocal@@AAAHPBVidMD6Node@@@Z
// EA: 0x82B34AC0, RVA: 0x00B34AC0
int idGameAnimToolsLocal::TreeDepth_r(const idMD6Node* const node) {
    if (node == nullptr || !IsBranch(node)) {
        return 0;
    }
    const idMD6Branch* const branch = static_cast<const idMD6Branch*>(node);
    return (std::max)(TreeDepth_r(branch->left),
        TreeDepth_r(branch->right)) + 1;
}

// Retail symbol: ?TreeDepth@idGameAnimToolsLocal@@UAAHPBVidMD6Node@@@Z
// EA: 0x82B34B58, RVA: 0x00B34B58
int idGameAnimToolsLocal::TreeDepth(const idMD6Node* const root) {
    return root != nullptr ? TreeDepth_r(root) : -1;
}

// Retail symbol: ?GetAnimData@idGameAnimToolsLocal@@AAAPBVidMD6AnimData@@PBVidTreeAnimator@@PBD@Z
// EA: 0x82B34B70, RVA: 0x00B34B70
const idMD6AnimData* idGameAnimToolsLocal::GetAnimData(
        const idTreeAnimator* const treeAnimator,
        const char* const aliasName) {
    if (treeAnimator == nullptr || aliasName == nullptr
            || services == nullptr) {
        return nullptr;
    }
    return services->GetAnimData(treeAnimator, aliasName);
}

// Retail symbol: ?GetAnimNumFrames@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBD@Z
// EA: 0x82B34C58, RVA: 0x00B34C58
int idGameAnimToolsLocal::GetAnimNumFrames(
        const idTreeAnimator* const treeAnimator,
        const char* const aliasName) {
    const idMD6AnimData* const data = GetAnimData(treeAnimator, aliasName);
    return data != nullptr ? data->numFrames : 0;
}

// Retail symbol: ?GetAnimFrameRate@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBD@Z
// EA: 0x82B34CA8, RVA: 0x00B34CA8
int idGameAnimToolsLocal::GetAnimFrameRate(
        const idTreeAnimator* const treeAnimator,
        const char* const aliasName) {
    const idMD6AnimData* const data = GetAnimData(treeAnimator, aliasName);
    return data != nullptr ? data->frameRate : 0;
}

// Retail symbol: ?VerifyStrongAliasRefs@idGameAnimToolsLocal@@UAA_NPBVidTreeAnimator@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA: 0x82B34CF8, RVA: 0x00B34CF8
bool idGameAnimToolsLocal::VerifyStrongAliasRefs(
        const idTreeAnimator* const treeAnimator,
        const idAnimAliasHandle& aliasHandle,
        const char* const entityName) {
    return aliasHandle.IsValid() && treeAnimator != nullptr
        && services != nullptr
        && services->VerifyStrongAliasRefs(
            treeAnimator, aliasHandle, entityName);
}

// Retail symbol: ?WalkTree_r@idGameAnimToolsLocal@@AAAXPBVidMD6Node@@@Z
// EA: 0x82B34E68, RVA: 0x00B34E68
void idGameAnimToolsLocal::WalkTree_r(idClass* const owner,
        const idTreeAnimator* const animator, const idMD6Node* const node) {
    if (node == nullptr) {
        return;
    }
    if (IsBranch(node)) {
        const idMD6Branch* const branch
            = static_cast<const idMD6Branch*>(node);
        WalkTree_r(owner, animator, branch->left);
        WalkTree_r(owner, animator, branch->right);
    }
    if (services != nullptr) {
        services->DebugNode(owner, animator, node);
    }
}

// Retail symbol: ?AnimDebugHud@idGameAnimToolsLocal@@UAAXPAVidClass@@PBVidTreeAnimator@@PBVidMD6Node@@@Z
// EA: 0x82B35058, RVA: 0x00B35058
void idGameAnimToolsLocal::AnimDebugHud(idClass* const owner,
        const idTreeAnimator* const animator, const idMD6Node* const tree) {
    WalkTree_r(owner, animator, tree);
}

// Retail symbol: ?DrawBlendTreeLeaf@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Leaf@@@Z
// EA: 0x82B35118, RVA: 0x00B35118
void idGameAnimToolsLocal::DrawBlendTreeLeaf(idDeviceContext& context,
        const float x, const float y, const idMD6Leaf* const leaf) {
    if (leaf != nullptr && services != nullptr) {
        services->DrawLeaf(*this, context, x, y, leaf);
    }
}

// Retail symbol: ?DrawTree_r@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Node@@H@Z
// EA: 0x82B35488, RVA: 0x00B35488
void idGameAnimToolsLocal::DrawTree_r(idDeviceContext& context,
        const float x, const float y, const idMD6Node* const node,
        const int depth) {
    if (node == nullptr) {
        return;
    }
    if (!IsBranch(node)) {
        if (node->type == idMD6Node::NODE_LEAF_PAUSE
                || node->type == idMD6Node::NODE_LEAF_PLAY) {
            DrawBlendTreeLeaf(context, x, y,
                static_cast<const idMD6Leaf*>(node));
        }
        return;
    }
    const idMD6Branch* const branch = static_cast<const idMD6Branch*>(node);
    DrawBlendTreeBranch(context, x, y, branch);
    const float span = nodeWidth * std::pow(2.0f,
        static_cast<float>((std::max)(0, depth - 1)));
    DrawTree_r(context, x - span * 0.5f, y + nodeHeight + 32.0f,
        branch->left, depth - 1);
    DrawTree_r(context, x + span * 0.5f, y + nodeHeight + 32.0f,
        branch->right, depth - 1);
}

// Retail symbol: ?DrawBlendTree@idGameAnimToolsLocal@@UAAPAVidRenderModelGui@@PBDPBVidMD6Node@@@Z
// EA: 0x82B35680, RVA: 0x00B35680
idRenderModelGui* idGameAnimToolsLocal::DrawBlendTree(
        const char* const name, const idMD6Node* const tree) {
    if (tree == nullptr || services == nullptr) {
        return nullptr;
    }
    guiModel = services->DrawBlendTree(
        *this, name, tree, guiModel, nodeWidth, nodeHeight);
    return guiModel;
}
