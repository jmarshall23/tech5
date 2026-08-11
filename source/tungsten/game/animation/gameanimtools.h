#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "idlib/color.h"

class idClass;
class idDeviceContext;
class idMD6Anim;
class idMD6AnimData;
class idMD6Branch;
class idMD6Leaf;
class idMaterial;
class idRenderModelGui;
class idTreeAnimator;

class idGameAnimToolsLocal;

class idGameAnimToolsServices {
public:
    virtual ~idGameAnimToolsServices() = default;
    virtual void ReleaseGuiModel(idRenderModelGui*) {}
    virtual idRenderModelGui* DrawBlendTree(idGameAnimToolsLocal&,
        const char*, const idMD6Node*, idRenderModelGui* currentModel,
        float, float) { return currentModel; }
    virtual void DrawBranch(idGameAnimToolsLocal&, idDeviceContext&,
        float, float, const idMD6Branch*) {}
    virtual void DrawLeaf(idGameAnimToolsLocal&, idDeviceContext&,
        float, float, const idMD6Leaf*) {}
    virtual int MeasureNode(const idMD6Node*) const { return 0; }
    virtual void DebugNode(idClass*, const idTreeAnimator*,
        const idMD6Node*) {}
    virtual const idMD6AnimData* GetAnimData(const idTreeAnimator*,
        const char*) const { return nullptr; }
    virtual bool VerifyStrongAliasRefs(const idTreeAnimator*,
        const idAnimAliasHandle&, const char*) const { return false; }
};

class idGameAnimTools {
public:
    virtual ~idGameAnimTools() = default;
    virtual void AnimDebugHud(idClass* owner,
        const idTreeAnimator* animator, const idMD6Node* tree) = 0;
    virtual idRenderModelGui* DrawBlendTree(const char* name,
        const idMD6Node* tree) = 0;
    virtual int TreeDepth(const idMD6Node* root) = 0;
    virtual int GetAnimFrameRate(const idTreeAnimator* treeAnimator,
        const char* aliasName) = 0;
    virtual int GetAnimNumFrames(const idTreeAnimator* treeAnimator,
        const idMD6Anim* animation) = 0;
    virtual int GetAnimNumFrames(const idTreeAnimator* treeAnimator,
        const char* aliasName) = 0;
    virtual bool VerifyStrongAliasRefs(const idTreeAnimator* treeAnimator,
        const idAnimAliasHandle& aliasHandle,
        const char* entityName) = 0;
};

class idGameAnimToolsLocal final : public idGameAnimTools {
public:
    enum textLines_t : int {
        TL_NAME, TL_BLEND_OP, TL_ORIGIN_BLEND, TL_FRAME, TL_ALPHA,
        TL_WRAP, TL_RATE, TL_WEIGHTGROUP, TL_MAX
    };

    idGameAnimToolsLocal();
    ~idGameAnimToolsLocal() override;

    void SetServices(idGameAnimToolsServices* newServices) {
        services = newServices;
    }
    idGameAnimToolsServices* GetServices() const { return services; }
    void AnimDebugHud(idClass* owner, const idTreeAnimator* animator,
        const idMD6Node* tree) override;
    idRenderModelGui* DrawBlendTree(const char* name,
        const idMD6Node* tree) override;
    int TreeDepth(const idMD6Node* root) override;
    int GetAnimFrameRate(const idTreeAnimator* treeAnimator,
        const char* aliasName) override;
    int GetAnimNumFrames(const idTreeAnimator* treeAnimator,
        const idMD6Anim* animation) override;
    int GetAnimNumFrames(const idTreeAnimator* treeAnimator,
        const char* aliasName) override;
    bool VerifyStrongAliasRefs(const idTreeAnimator* treeAnimator,
        const idAnimAliasHandle& aliasHandle,
        const char* entityName) override;

    float GetNodeWidth() const { return nodeWidth; }
    float GetNodeHeight() const { return nodeHeight; }
    idRenderModelGui* GetGuiModel() const { return guiModel; }

private:
    void DrawBlendTreeBranch(idDeviceContext& context, float x, float y,
        const idMD6Branch* branch);
    int TreeMaxNodeWidth_r(idDeviceContext& context,
        const idMD6Node* node);
    int TreeDepth_r(const idMD6Node* node);
    const idMD6AnimData* GetAnimData(const idTreeAnimator* treeAnimator,
        const char* aliasName);
    void WalkTree_r(idClass* owner, const idTreeAnimator* animator,
        const idMD6Node* node);
    void DrawBlendTreeLeaf(idDeviceContext& context, float x, float y,
        const idMD6Leaf* leaf);
    void DrawTree_r(idDeviceContext& context, float x, float y,
        const idMD6Node* node, int depth);

    idRenderModelGui* guiModel;
    float nodeWidth;
    float nodeHeight;
    const idMaterial* whiteMaterial;
    idColor branchColor;
    idColor leafColor;
    idColor outlineColor;
    idColor textColor;
    idColor linkColor;
    idGameAnimToolsServices* services;
};
