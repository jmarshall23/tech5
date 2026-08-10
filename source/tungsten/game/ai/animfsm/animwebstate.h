#pragma once

#include "gamelib/animstack/animstacktypes.h"
#include "gamelib/animstack/animweb/animwebpath.h"

class idAnimator_AnimWeb;
class idDeclAnimWeb;
class idDeclMD6;
class idMD6Anim;

struct idAnimWebStateNodeInfo {
    short subweb = -1;
    short state = -1;
    bool hasAnimationProperties = false;
    int flags = 0;
    int customFlags = 0;
    idMD6Leaf::wrapMode_t wrapMode = idMD6Leaf::WRAP_MAX;
};

class idAnimWebState {
public:
    idAnimWebState();
    idAnimWebState(const idDeclAnimWeb* declaration,
        idAnimWebNodeIndex nodeIndex);
    void Clear();

    idAnimWebState AsState(const char* stateName) const;
    bool operator==(const idAnimWebState& other) const;
    bool operator!=(const idAnimWebState& other) const;
    void UpdateDebugInfo(const char* defaultSubWebName,
        const char* defaultStateName);
    idAnimWebPath GetAnimPath() const;
    bool Verify(const char* errorMessage = nullptr) const;
    const idDeclMD6* GetModel(int index) const;
    int GetNumAnims(const idDeclMD6* model) const;
    const idMD6Anim* GetAnimByIndex(const idDeclMD6* model,
        int animationIndex, int modelIndex) const;
    bool GetAnimDelta(const idDeclMD6* model, int animationIndex,
        idVec3& deltaPosition, idMat3& deltaAxis) const;
    idMD6Leaf::wrapMode_t GetAnimWrapMode() const;
    int GetFlags() const;
    int GetCustomFlags() const;
    bool GetBlendParmsToDestination(const idAnimWebState& destination,
        blendParms_t& parameters) const;
    idStr GetAnimName() const;
    bool VerifyDecl(const idDeclAnimWeb* declaration) const;

    const idDeclAnimWeb* owner;
    idAnimWebSubWebIndex subweb;
    idAnimWebStateIndex state;
    idAnimWebNodeIndex node;
    bool pathConstructed;
    const char* debugSubweb;
    const char* debugState;

protected:
    void Init(const idDeclAnimWeb* declaration, const char* subWebName,
        const char* stateName);
    void Init(const idDeclAnimWeb* declaration,
        idAnimWebNodeIndex nodeIndex);
};

class idAnimWebState_Current : public idAnimWebState {
public:
    explicit idAnimWebState_Current(const idAnimator_AnimWeb* web);
};

short Tungsten_GetAnimWebSubWebIndex(
    const idDeclAnimWeb& declaration, const char* subWebName);
short Tungsten_GetAnimWebStateIndex(
    const idDeclAnimWeb& declaration, const char* stateName);
short Tungsten_FindAnimWebNodeIndex(const idDeclAnimWeb& declaration,
    short subWebIndex, short stateIndex);
bool Tungsten_GetAnimWebStateNodeInfo(const idDeclAnimWeb& declaration,
    short nodeIndex, idAnimWebStateNodeInfo& nodeInfo);
const char* Tungsten_GetAnimWebSubWebName(
    const idDeclAnimWeb& declaration, short subWebIndex);
const char* Tungsten_GetAnimWebStateName(
    const idDeclAnimWeb& declaration, short stateIndex);
const char* Tungsten_GetAnimWebDeclarationName(
    const idDeclAnimWeb& declaration);
const char* Tungsten_InternAnimWebDebugName(const char* name);
void Tungsten_AnimWebStateWarning(
    const char* animationPath, const char* message);
const idDeclMD6* Tungsten_GetAnimWebModel(
    const idDeclAnimWeb& declaration, int index);
int Tungsten_GetAnimWebAnimationCount(const idDeclAnimWeb& declaration,
    short nodeIndex, const idDeclMD6& model);
const idMD6Anim* Tungsten_GetAnimWebAnimation(const idDeclAnimWeb& declaration,
    short nodeIndex, const idDeclMD6& model, int animationIndex,
    int modelIndex);
bool Tungsten_GetAnimWebAnimationDelta(const idMD6Anim& animation,
    idVec3& deltaPosition, idMat3& deltaAxis);
bool Tungsten_GetAnimWebEdgeBlend(const idDeclAnimWeb& declaration,
    short sourceNodeIndex, short destinationNodeIndex,
    blendParms_t& parameters);
bool Tungsten_GetCurrentAnimWebState(const idAnimator_AnimWeb& web,
    const idDeclAnimWeb*& declaration, short& nodeIndex);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimWebState) == 20,
    "Recovered animation-web state ABI changed");
#endif
