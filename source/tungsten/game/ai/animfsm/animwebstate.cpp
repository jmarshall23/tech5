#include "animwebstate.h"

namespace {

const char* SafeName(const char* const value) {
    return value != nullptr ? value : "";
}

} // namespace

// Retail symbol: ?AsState@idAnimWebState@@QBA?AV1@PBD@Z
// EA: 0x82A84F98, RVA: 0x00A84F98
idAnimWebState idAnimWebState::AsState(const char* const stateName) const {
    idAnimWebState result(*this);
    if (result.owner != nullptr) {
        result.state = idAnimWebStateIndex(
            Tungsten_GetAnimWebStateIndex(*result.owner, stateName));
    }
    return result;
}

// Retail symbol: ??0idAnimWebState@@QAA@XZ
// EA: 0x82A85000, RVA: 0x00A85000
idAnimWebState::idAnimWebState()
    : owner(nullptr)
    , subweb()
    , state()
    , node()
    , pathConstructed(false)
    , debugSubweb("")
    , debugState("") {
}

// Retail symbol: ?Clear@idAnimWebState@@QAAXXZ
// EA: 0x82A85038, RVA: 0x00A85038
void idAnimWebState::Clear() {
    owner = nullptr;
    subweb.Invalidate();
    state.Invalidate();
    node.Invalidate();
    pathConstructed = false;
    debugSubweb = "";
    debugState = "";
}

// Retail symbol: ??8idAnimWebState@@QBA_NABV0@@Z
// EA: 0x82A85070, RVA: 0x00A85070
bool idAnimWebState::operator==(const idAnimWebState& other) const {
    return owner == other.owner && subweb == other.subweb
        && state == other.state && node == other.node;
}

// Retail symbol: ?UpdateDebugInfo@idAnimWebState@@QAAXPBD0@Z
// EA: 0x82A850C0, RVA: 0x00A850C0
void idAnimWebState::UpdateDebugInfo(const char* const defaultSubWebName,
        const char* const defaultStateName) {
    idAnimWebStateNodeInfo nodeInfo;
    if (owner != nullptr && node.Get() >= 0
            && Tungsten_GetAnimWebStateNodeInfo(
                *owner, node.Get(), nodeInfo)) {
        subweb = idAnimWebSubWebIndex(nodeInfo.subweb);
        state = idAnimWebStateIndex(nodeInfo.state);
        debugSubweb = Tungsten_InternAnimWebDebugName(
            Tungsten_GetAnimWebSubWebName(*owner, subweb.Get()));
        debugState = Tungsten_InternAnimWebDebugName(
            Tungsten_GetAnimWebStateName(*owner, state.Get()));
    } else {
        debugSubweb = Tungsten_InternAnimWebDebugName(defaultSubWebName);
        debugState = Tungsten_InternAnimWebDebugName(defaultStateName);
    }
}

// Retail symbol: ?GetAnimPath@idAnimWebState@@QBA?AVidAnimWebPath@@XZ
// EA: 0x82A851A0, RVA: 0x00A851A0
idAnimWebPath idAnimWebState::GetAnimPath() const {
    idAnimWebPath result;
    if (Verify()) {
        result.SetPath(Tungsten_GetAnimWebDeclarationName(*owner),
            Tungsten_GetAnimWebSubWebName(*owner, subweb.Get()),
            Tungsten_GetAnimWebStateName(*owner, state.Get()));
    } else {
        result.Format("web/%s/%s", SafeName(debugSubweb),
            SafeName(debugState));
    }
    return result;
}

// Retail symbol: ?Verify@idAnimWebState@@QBA_NPBD@Z
// EA: 0x82A852F8, RVA: 0x00A852F8
bool idAnimWebState::Verify(const char* const errorMessage) const {
    bool valid = owner != nullptr && subweb.IsValid()
        && state.IsValid() && node.IsValid();
    if (owner != nullptr && node.IsValid()) {
        idAnimWebStateNodeInfo nodeInfo;
        if (Tungsten_GetAnimWebStateNodeInfo(*owner, node.Get(), nodeInfo)
                && !nodeInfo.hasAnimationProperties) {
            valid = false;
        }
    }
    if (!valid && errorMessage != nullptr) {
        const idAnimWebPath path = GetAnimPath();
        Tungsten_AnimWebStateWarning(path.c_str(), errorMessage);
    }
    return valid;
}

// Retail symbol: ??9idAnimWebState@@QBA_NABV0@@Z
// EA: 0x82A85418, RVA: 0x00A85418
bool idAnimWebState::operator!=(const idAnimWebState& other) const {
    return !(*this == other);
}

// Retail symbol: ?GetModel@idAnimWebState@@QBAPBVidDeclMD6@@H@Z
// EA: 0x82A85468, RVA: 0x00A85468
const idDeclMD6* idAnimWebState::GetModel(const int index) const {
    return owner != nullptr ? Tungsten_GetAnimWebModel(*owner, index) : nullptr;
}

// Retail symbol: ?GetNumAnims@idAnimWebState@@QBAHPBVidDeclMD6@@@Z
// EA: 0x82A85490, RVA: 0x00A85490
int idAnimWebState::GetNumAnims(const idDeclMD6* const model) const {
    return Verify() && model != nullptr && node.IsValid()
        ? Tungsten_GetAnimWebAnimationCount(*owner, node.Get(), *model) : 0;
}

// Retail symbol: ?GetAnimByIndex@idAnimWebState@@QBAPBVidMD6Anim@@PBVidDeclMD6@@HH@Z
// EA: 0x82A85530, RVA: 0x00A85530
const idMD6Anim* idAnimWebState::GetAnimByIndex(
        const idDeclMD6* const model, const int animationIndex,
        const int modelIndex) const {
    return Verify() && model != nullptr && node.IsValid()
        ? Tungsten_GetAnimWebAnimation(*owner, node.Get(), *model,
            animationIndex, modelIndex)
        : nullptr;
}

// Retail symbol: ?GetAnimDelta@idAnimWebState@@QBA_NPBVidDeclMD6@@HAAVidVec3@@AAVidMat3@@@Z
// EA: 0x82A85610, RVA: 0x00A85610
bool idAnimWebState::GetAnimDelta(const idDeclMD6* const model,
        const int animationIndex, idVec3& deltaPosition,
        idMat3& deltaAxis) const {
    const idMD6Anim* const animation =
        GetAnimByIndex(model, animationIndex, 0);
    return animation != nullptr && Tungsten_GetAnimWebAnimationDelta(
        *animation, deltaPosition, deltaAxis);
}

// Retail symbol: ?GetAnimWrapMode@idAnimWebState@@QBA?AW4wrapMode_t@idMD6Leaf@@XZ
// EA: 0x82A85670, RVA: 0x00A85670
idMD6Leaf::wrapMode_t idAnimWebState::GetAnimWrapMode() const {
    if (owner == nullptr || !node.IsValid()) {
        return idMD6Leaf::WRAP_MAX;
    }
    idAnimWebStateNodeInfo nodeInfo;
    return Tungsten_GetAnimWebStateNodeInfo(*owner, node.Get(), nodeInfo)
        && nodeInfo.hasAnimationProperties
        ? nodeInfo.wrapMode : idMD6Leaf::WRAP_MAX;
}

// Retail symbol: ?GetFlags@idAnimWebState@@QBAHXZ
// EA: 0x82A856E0, RVA: 0x00A856E0
int idAnimWebState::GetFlags() const {
    if (owner == nullptr || !node.IsValid()) {
        return 0;
    }
    idAnimWebStateNodeInfo nodeInfo;
    return Tungsten_GetAnimWebStateNodeInfo(*owner, node.Get(), nodeInfo)
        ? nodeInfo.flags : 0;
}

// Retail symbol: ?GetCustomFlags@idAnimWebState@@QBAHXZ
// EA: 0x82A85730, RVA: 0x00A85730
int idAnimWebState::GetCustomFlags() const {
    if (owner == nullptr || !node.IsValid()) {
        return 0;
    }
    idAnimWebStateNodeInfo nodeInfo;
    return Tungsten_GetAnimWebStateNodeInfo(*owner, node.Get(), nodeInfo)
        ? nodeInfo.customFlags : 0;
}

// Retail symbol: ?GetBlendParmsToDestination@idAnimWebState@@QBA_NABV1@AAVblendParms_t@@@Z
// EA: 0x82A85780, RVA: 0x00A85780
bool idAnimWebState::GetBlendParmsToDestination(
        const idAnimWebState& destination,
        blendParms_t& parameters) const {
    return Verify() && destination.Verify()
        && Tungsten_GetAnimWebEdgeBlend(*owner, node.Get(),
            destination.node.Get(), parameters);
}

// Retail symbol: ?Init@idAnimWebState@@IAAXPBVidDeclAnimWeb@@PBD1@Z
// EA: 0x82A85810, RVA: 0x00A85810
void idAnimWebState::Init(const idDeclAnimWeb* const declaration,
        const char* const subWebName, const char* const stateName) {
    owner = declaration;
    pathConstructed = false;
    if (declaration != nullptr) {
        subweb = idAnimWebSubWebIndex(
            Tungsten_GetAnimWebSubWebIndex(*declaration, subWebName));
        state = idAnimWebStateIndex(
            Tungsten_GetAnimWebStateIndex(*declaration, stateName));
        node = idAnimWebNodeIndex(Tungsten_FindAnimWebNodeIndex(
            *declaration, subweb.Get(), state.Get()));
    }
    UpdateDebugInfo(subWebName, stateName);
}

// Retail symbol: ?Init@idAnimWebState@@IAAXPBVidDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A858A0, RVA: 0x00A858A0
void idAnimWebState::Init(const idDeclAnimWeb* const declaration,
        const idAnimWebNodeIndex nodeIndex) {
    owner = declaration;
    pathConstructed = false;
    if (declaration != nullptr && nodeIndex.Get() >= 0) {
        idAnimWebStateNodeInfo nodeInfo;
        if (Tungsten_GetAnimWebStateNodeInfo(
                *declaration, nodeIndex.Get(), nodeInfo)) {
            subweb = idAnimWebSubWebIndex(nodeInfo.subweb);
            state = idAnimWebStateIndex(nodeInfo.state);
            node = nodeIndex;
        }
    }
    UpdateDebugInfo(nullptr, nullptr);
}

// Retail symbol: ?GetAnimName@idAnimWebState@@QBA?AVidStr@@XZ
// EA: 0x82A85908, RVA: 0x00A85908
idStr idAnimWebState::GetAnimName() const {
    idStr result("<none>");
    if (Verify()) {
        const char* const subWebName =
            Tungsten_GetAnimWebSubWebName(*owner, subweb.Get());
        const char* const stateName =
            Tungsten_GetAnimWebStateName(*owner, state.Get());
        result.Format("%s/%s", subWebName != nullptr ? subWebName : "no sw",
            stateName != nullptr ? stateName : "no st");
    }
    return result;
}

// Retail symbol: ??0idAnimWebState_Current@@QAA@PBVidAnimator_AnimWeb@@@Z
// EA: 0x82A85A08, RVA: 0x00A85A08
idAnimWebState_Current::idAnimWebState_Current(
        const idAnimator_AnimWeb* const web) {
    if (web != nullptr) {
        const idDeclAnimWeb* declaration = nullptr;
        short nodeIndex = -1;
        if (Tungsten_GetCurrentAnimWebState(
                *web, declaration, nodeIndex)) {
            Init(declaration, idAnimWebNodeIndex(nodeIndex));
            return;
        }
    }
    UpdateDebugInfo(nullptr, nullptr);
}

// Retail symbol: ??0idAnimWebState@@QAA@PBVidDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A85AB8, RVA: 0x00A85AB8
idAnimWebState::idAnimWebState(const idDeclAnimWeb* const declaration,
        const idAnimWebNodeIndex nodeIndex)
    : idAnimWebState() {
    Init(declaration, nodeIndex);
}

// Retail symbol: ?VerifyDecl@idAnimWebState@@QBA_NPBVidDeclAnimWeb@@@Z
// EA: 0x82A85B68, RVA: 0x00A85B68
bool idAnimWebState::VerifyDecl(
        const idDeclAnimWeb* const declaration) const {
    if (declaration == owner) {
        return true;
    }
    idAnimWebState candidate;
    candidate.Init(declaration, debugSubweb, debugState);
    return *this == candidate;
}
