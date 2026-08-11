#include "ai2.h"

namespace {

void DispatchAnimWeb(const idAI2& ai, idAI2AnimWebCall& call) {
    if (ai.core.services != nullptr) {
        ai.core.services->DispatchAIAnimWeb(
            const_cast<idAI2&>(ai), call);
    }
}

awPathResult_t PathResult(const idAI2AnimWebCall& call) {
    return static_cast<awPathResult_t>(call.result);
}

} // namespace

// Retail symbol: ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@@Z
// EA: 0x82A32EC0, RVA: 0x00A32EC0
awPathResult_t idAI2::ChangeAnimState(const aiAnimWeb_t web,
        const idAnimWebSubWebIndex subWeb,
        const idAnimWebStateIndex state,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend) {
    idAI2AnimWebCall call("ChangeAnimState.indices");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = subWeb.Get();
    call.integers[2] = state.Get();
    call.integers[3] = static_cast<int>(interruptPath);
    call.integers[4] = static_cast<int>(interruptBlend);
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@12W4interruptPath_t@@W4interruptBlend_t@@@Z
// EA: 0x82A32EF0, RVA: 0x00A32EF0
awPathResult_t idAI2::ChangeAnimStateVia(const aiAnimWeb_t web,
        const idAnimWebSubWebIndex destinationSubWeb,
        const idAnimWebStateIndex destinationState,
        const idAnimWebSubWebIndex viaSubWeb,
        const idAnimWebStateIndex viaState,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend) {
    idAI2AnimWebCall call("ChangeAnimStateVia.indices");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = destinationSubWeb.Get();
    call.integers[2] = destinationState.Get();
    call.integers[3] = viaSubWeb.Get();
    call.integers[4] = viaState.Get();
    call.integers[5] = static_cast<int>(interruptPath);
    call.integers[6] = static_cast<int>(interruptBlend);
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?GetWeaponPrefix@idAI2@@QBAXPBVidWeapon@@AAVidStr@@@Z
// EA: 0x82A32F48, RVA: 0x00A32F48
void idAI2::GetWeaponPrefix(const idWeapon* const weapon,
        idStr& prefix) const {
    idAI2AnimWebCall call("GetWeaponPrefix.weapon");
    call.inputs[0] = weapon;
    call.outputs[0] = &prefix;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetWeaponPrefix@idAI2@@QBAXAAVidStr@@@Z
// EA: 0x82A32FE0, RVA: 0x00A32FE0
void idAI2::GetWeaponPrefix(idStr& prefix) const {
    idAI2AnimWebCall call("GetWeaponPrefix.current");
    call.outputs[0] = &prefix;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetSubWebName@idAI2@@QBAXABVidStr@@AAV2@@Z
// EA: 0x82A33040, RVA: 0x00A33040
void idAI2::GetSubWebName(const idStr& prefix,
        idStr& subWebName) const {
    idAI2AnimWebCall call("GetSubWebName");
    call.inputs[0] = &prefix;
    call.outputs[0] = &subWebName;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetSubWebAndStateFromAnimWebPath@idAI2@@QBA_NPBDAAVidStr@@1@Z
// EA: 0x82A33230, RVA: 0x00A33230
bool idAI2::GetSubWebAndStateFromAnimWebPath(const char* const path,
        idStr& subWebName, idStr& stateName) const {
    idAI2AnimWebCall call("GetSubWebAndStateFromAnimWebPath");
    call.strings[0] = path;
    call.outputs[0] = &subWebName;
    call.outputs[1] = &stateName;
    DispatchAnimWeb(*this, call);
    return call.boolResult;
}

// Retail symbol: ?GetAnimForAnimWebNode@idAI2@@QBAPBVidMD6Anim@@ABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A335B0, RVA: 0x00A335B0
const idMD6Anim* idAI2::GetAnimForAnimWebNode(
        const idAnimWebSubWebIndex& subWeb,
        const idAnimWebStateIndex& state) const {
    idAI2AnimWebCall call("GetAnimForAnimWebNode");
    call.inputs[0] = &subWeb;
    call.inputs[1] = &state;
    DispatchAnimWeb(*this, call);
    return static_cast<const idMD6Anim*>(call.pointerResult);
}

// Retail symbol: ?GetAnimForAnimWebNodeIndex@idAI2@@QBAPBVidMD6Anim@@ABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@H@Z
// EA: 0x82A33678, RVA: 0x00A33678
const idMD6Anim* idAI2::GetAnimForAnimWebNodeIndex(
        const idAnimWebSubWebIndex& subWeb,
        const idAnimWebStateIndex& state, const int nodeIndex) const {
    idAI2AnimWebCall call("GetAnimForAnimWebNodeIndex");
    call.inputs[0] = &subWeb;
    call.inputs[1] = &state;
    call.integers[0] = nodeIndex;
    DispatchAnimWeb(*this, call);
    return static_cast<const idMD6Anim*>(call.pointerResult);
}

// Retail symbol: ?GetCurrentSubWebAndStateIndices@idAI2@@QBAXAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A33750, RVA: 0x00A33750
void idAI2::GetCurrentSubWebAndStateIndices(
        idAnimWebSubWebIndex& subWeb,
        idAnimWebStateIndex& state) const {
    idAI2AnimWebCall call("GetCurrentSubWebAndStateIndices");
    call.outputs[0] = &subWeb;
    call.outputs[1] = &state;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetSubWebPrefix@idAI2@@QBAXPBVidWeapon@@W4aiSubWeb_t@@AAVidStr@@@Z
// EA: 0x82A33798, RVA: 0x00A33798
void idAI2::GetSubWebPrefix(const idWeapon* const weapon,
        const aiSubWeb_t subWeb, idStr& prefix) const {
    idAI2AnimWebCall call("GetSubWebPrefix.weapon");
    call.inputs[0] = weapon;
    call.integers[0] = static_cast<int>(subWeb);
    call.outputs[0] = &prefix;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetSubWebPrefix@idAI2@@QBAXW4aiSubWeb_t@@AAVidStr@@@Z
// EA: 0x82A337F8, RVA: 0x00A337F8
void idAI2::GetSubWebPrefix(const aiSubWeb_t subWeb,
        idStr& prefix) const {
    idAI2AnimWebCall call("GetSubWebPrefix.subweb");
    call.integers[0] = static_cast<int>(subWeb);
    call.outputs[0] = &prefix;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetSubWebPrefix@idAI2@@QBAXAAVidStr@@@Z
// EA: 0x82A33850, RVA: 0x00A33850
void idAI2::GetSubWebPrefix(idStr& prefix) const {
    idAI2AnimWebCall call("GetSubWebPrefix.current");
    call.outputs[0] = &prefix;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetMovementStateName@idAI2@@QBAXAAVidStr@@@Z
// EA: 0x82A338B0, RVA: 0x00A338B0
void idAI2::GetMovementStateName(idStr& stateName) const {
    idAI2AnimWebCall call("GetMovementStateName");
    call.outputs[0] = &stateName;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetIdleStateName@idAI2@@QBAXAAVidStr@@@Z
// EA: 0x82A339D0, RVA: 0x00A339D0
void idAI2::GetIdleStateName(idStr& stateName) const {
    idAI2AnimWebCall call("GetIdleStateName");
    call.outputs[0] = &stateName;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetIdleTurnStateName@idAI2@@QBAXW4turnDirection_t@@MPBVidDeclAITurnParms@@AAVidStr@@@Z
// EA: 0x82A33AF8, RVA: 0x00A33AF8
void idAI2::GetIdleTurnStateName(const turnDirection_t direction,
        const float angle, const idDeclAITurnParms* const turnParms,
        idStr& stateName) const {
    idAI2AnimWebCall call("GetIdleTurnStateName");
    call.integers[0] = static_cast<int>(direction);
    call.scalars[0] = angle;
    call.inputs[0] = turnParms;
    call.outputs[0] = &stateName;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A33C10, RVA: 0x00A33C10
awPathResult_t idAI2::ChangeAnimState(const aiAnimWeb_t web,
        const aiSubWeb_t subWeb, const idAnimWebStateIndex state,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend,
        idAnimWebSubWebIndex* const resolvedSubWeb) {
    idAI2AnimWebCall call("ChangeAnimState.subwebIndex");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(subWeb);
    call.integers[2] = state.Get();
    call.integers[3] = static_cast<int>(interruptPath);
    call.integers[4] = static_cast<int>(interruptBlend);
    call.outputs[0] = resolvedSubWeb;
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@PBDW4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A33D58, RVA: 0x00A33D58
awPathResult_t idAI2::ChangeAnimState(const aiAnimWeb_t web,
        const aiSubWeb_t subWeb, const char* const stateName,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend,
        idAnimWebSubWebIndex* const resolvedSubWeb,
        idAnimWebStateIndex* const resolvedState) {
    idAI2AnimWebCall call("ChangeAnimState.subwebName");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(subWeb);
    call.integers[2] = static_cast<int>(interruptPath);
    call.integers[3] = static_cast<int>(interruptBlend);
    call.strings[0] = stateName;
    call.outputs[0] = resolvedSubWeb;
    call.outputs[1] = resolvedState;
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?FindAnimWebAndStateIndices@idAI2@@QBAXW4aiAnimWeb_t@@W4aiSubWeb_t@@PBD_NPBVidWeapon@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A33E18, RVA: 0x00A33E18
void idAI2::FindAnimWebAndStateIndices(const aiAnimWeb_t web,
        const aiSubWeb_t subWeb, const char* const stateName,
        const bool useWeapon, const idWeapon* const weapon,
        idAnimWebSubWebIndex* const resolvedSubWeb,
        idAnimWebStateIndex* const resolvedState) const {
    idAI2AnimWebCall call("FindAnimWebAndStateIndices");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(subWeb);
    call.strings[0] = stateName;
    call.booleans[0] = useWeapon;
    call.inputs[0] = weapon;
    call.outputs[0] = resolvedSubWeb;
    call.outputs[1] = resolvedState;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@12W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@5@Z
// EA: 0x82A33F30, RVA: 0x00A33F30
awPathResult_t idAI2::ChangeAnimStateVia(const aiAnimWeb_t web,
        const aiSubWeb_t destinationSubWeb,
        const idAnimWebStateIndex destinationState,
        const aiSubWeb_t viaSubWeb, const idAnimWebStateIndex viaState,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend,
        idAnimWebSubWebIndex* const resolvedDestinationSubWeb,
        idAnimWebSubWebIndex* const resolvedViaSubWeb) {
    idAI2AnimWebCall call("ChangeAnimStateVia.subwebIndices");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(destinationSubWeb);
    call.integers[2] = destinationState.Get();
    call.integers[3] = static_cast<int>(viaSubWeb);
    call.integers[4] = viaState.Get();
    call.integers[5] = static_cast<int>(interruptPath);
    call.integers[6] = static_cast<int>(interruptBlend);
    call.outputs[0] = resolvedDestinationSubWeb;
    call.outputs[1] = resolvedViaSubWeb;
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@PBD12W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@56@Z
// EA: 0x82A34140, RVA: 0x00A34140
awPathResult_t idAI2::ChangeAnimStateVia(const aiAnimWeb_t web,
        const aiSubWeb_t destinationSubWeb,
        const char* const destinationStateName,
        const aiSubWeb_t viaSubWeb, const char* const viaStateName,
        const interruptPath_t interruptPath,
        const interruptBlend_t interruptBlend,
        idAnimWebSubWebIndex* const resolvedDestinationSubWeb,
        idAnimWebStateIndex* const resolvedDestinationState,
        idAnimWebSubWebIndex* const resolvedViaSubWeb,
        idAnimWebStateIndex* const resolvedViaState) {
    idAI2AnimWebCall call("ChangeAnimStateVia.subwebNames");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(destinationSubWeb);
    call.integers[2] = static_cast<int>(viaSubWeb);
    call.integers[3] = static_cast<int>(interruptPath);
    call.integers[4] = static_cast<int>(interruptBlend);
    call.strings[0] = destinationStateName;
    call.strings[1] = viaStateName;
    call.outputs[0] = resolvedDestinationSubWeb;
    call.outputs[1] = resolvedDestinationState;
    call.outputs[2] = resolvedViaSubWeb;
    call.outputs[3] = resolvedViaState;
    DispatchAnimWeb(*this, call);
    return PathResult(call);
}

// Retail symbol: ?ResetAnimState@idAI2@@QAAXW4aiAnimWeb_t@@W4aiSubWeb_t@@PBD@Z
// EA: 0x82A34258, RVA: 0x00A34258
void idAI2::ResetAnimState(const aiAnimWeb_t web,
        const aiSubWeb_t subWeb, const char* const stateName) {
    idAI2AnimWebCall call("ResetAnimState");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(subWeb);
    call.strings[0] = stateName;
    DispatchAnimWeb(*this, call);
}

// Retail symbol: ?GetAnimWebGrenadeThrowNode@idAI2@@QBA_NW4aiAnimWeb_t@@W4aiSubWeb_t@@W4coverAction_t@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A34348, RVA: 0x00A34348
bool idAI2::GetAnimWebGrenadeThrowNode(const aiAnimWeb_t web,
        const aiSubWeb_t subWeb, const coverAction_t coverAction,
        idAnimWebSubWebIndex& resolvedSubWeb,
        idAnimWebStateIndex& resolvedState,
        idAnimWebNodeIndex& resolvedNode) const {
    idAI2AnimWebCall call("GetAnimWebGrenadeThrowNode");
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(subWeb);
    call.integers[2] = static_cast<int>(coverAction);
    call.outputs[0] = &resolvedSubWeb;
    call.outputs[1] = &resolvedState;
    call.outputs[2] = &resolvedNode;
    DispatchAnimWeb(*this, call);
    return call.boolResult;
}

// Retail symbol: ?GetAnimWebNodeForOverride@idAI2@@QBA_NW4overrideAnim_t@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A345B0, RVA: 0x00A345B0
bool idAI2::GetAnimWebNodeForOverride(const overrideAnim_t animation,
        idAnimWebSubWebIndex& resolvedSubWeb,
        idAnimWebStateIndex& resolvedState) const {
    idAI2AnimWebCall call("GetAnimWebNodeForOverride");
    call.integers[0] = static_cast<int>(animation);
    call.outputs[0] = &resolvedSubWeb;
    call.outputs[1] = &resolvedState;
    DispatchAnimWeb(*this, call);
    return call.boolResult;
}

// Retail symbol: ?GetMovementSubWebAndStateIndices@idAI2@@QBAXAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA: 0x82A346D8, RVA: 0x00A346D8
void idAI2::GetMovementSubWebAndStateIndices(
        idAnimWebSubWebIndex& resolvedSubWeb,
        idAnimWebStateIndex& resolvedState) const {
    idAI2AnimWebCall call("GetMovementSubWebAndStateIndices");
    call.outputs[0] = &resolvedSubWeb;
    call.outputs[1] = &resolvedState;
    DispatchAnimWeb(*this, call);
}
