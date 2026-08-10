#include "vehiclefsm.h"

#include <cctype>

namespace {

bool EqualsIgnoreCase(const char* lhs, const char* rhs) {
    if (lhs == nullptr || rhs == nullptr) {
        return lhs == rhs;
    }
    while (*lhs != '\0' && *rhs != '\0') {
        if (std::tolower(static_cast<unsigned char>(*lhs))
                != std::tolower(static_cast<unsigned char>(*rhs))) {
            return false;
        }
        ++lhs;
        ++rhs;
    }
    return *lhs == *rhs;
}

} // namespace

// Retail header symbol: ??0idVehicleState@@QAA@ABVidTypeInfo@@@Z
// EA: 0x824E3790, RVA: 0x004E3790
idVehicleState::idVehicleState()
    : idState()
    , stacked(false)
    , debugName()
    , debugInfo()
    , ai(nullptr) {
}

// Retail header symbols: ??0idVehicleBaseFSM@@QAA@XZ and
// ??0idVehicleBaseFSM@@QAA@PBD@Z
idVehicleBaseFSM::idVehicleBaseFSM()
    : idVehicleBaseFSM("") {
}

idVehicleBaseFSM::idVehicleBaseFSM(const char* const name)
    : idFiniteStateMachine()
    , stateStack()
    , dataState(nullptr)
    , s_Idle()
    , s_Wait() {
    stateStack.SetGranularity(1);
    stateStack.Clear();
    Tungsten_InitVehicleBaseFSMRuntime(*this,
        name != nullptr ? name : "");
}

// Retail symbol: ?InternalWork@idVS_Wait@@UAAXPAVidFiniteStateMachine@@H@Z
// EA: 0x82B1D6B8, RVA: 0x00B1D6B8
void idVS_Wait::InternalWork(idFiniteStateMachine* const baseFSM,
        const int currentTime) {
    if (baseFSM != nullptr
            && waitTime <= Tungsten_GetVehicleFSMTime(currentTime)) {
        Tungsten_SetBaseFSMState(
            *baseFSM, waitNextState, 0, false);
    }
}

// Retail symbol:
// ?AppendDefaultTransitions@idVehicleBaseFSM@@UAAXPAVidState@@@Z
// EA: 0x82B1D738, RVA: 0x00B1D738
void idVehicleBaseFSM::AppendDefaultTransitions(idState* const state) {
    if (state == nullptr) {
        return;
    }
    idState* const errorState = GetErrorState();
    Tungsten_AddVehicleDefaultTransition(*state, *this,
        VEHICLE_TRANSITION_UNHANDLED_CHILD_ERROR, errorState);
    Tungsten_AddVehicleDefaultTransition(*state, *this,
        VEHICLE_TRANSITION_STATE_ERROR, errorState);
}

// Retail symbol:
// ?SetState@idVehicleBaseFSM@@UAAXABUtransResult_t@idStateData@@H_N@Z
// EA: 0x82B1D790, RVA: 0x00B1D790
void idVehicleBaseFSM::SetState(
        const idStateData::transResult_t* const result,
        const int currentTime, const bool forcingStack) {
    Tungsten_SetBaseFSMTransitionResult(
        *this, result, currentTime, forcingStack);
}

// Retail symbol:
// ?SetState@idVehicleBaseFSM@@UAAXABVidTypeInfo@@H_N@Z
// EA: 0x82B1D798, RVA: 0x00B1D798
void idVehicleBaseFSM::SetState(const idTypeInfo* const stateType,
        const int delayTime, const bool stacked) {
    SetState(Tungsten_FindVehicleFSMState(*this, stateType),
        delayTime, stacked);
}

// Retail symbol: ?AddState@idVehicleBaseFSM@@UAAXPAVidState@@@Z
// EA: 0x82B1D7E0, RVA: 0x00B1D7E0
void idVehicleBaseFSM::AddState(idState* const state) {
    Tungsten_AddBaseFSMState(*this, state);
    idVehicleFSM* const concreteFSM = dynamic_cast<idVehicleFSM*>(this);
    idVehicleState* const vehicleState =
        dynamic_cast<idVehicleState*>(state);
    if (concreteFSM != nullptr && vehicleState != nullptr) {
        vehicleState->ai = Tungsten_GetVehicleFSMOwner(*concreteFSM);
    }
}

// Retail symbol:
// ?AllocFSM@idVehicleFSMManager@@UAAPAVidFiniteStateMachine@@ABVidTypeInfo@@ABVidFiniteStateMachineParams@@@Z
// EA: 0x82B1D850, RVA: 0x00B1D850
idFiniteStateMachine* idVehicleFSMManager::AllocFSM(
        const idTypeInfo* const type,
        const idFiniteStateMachineParams*) {
    return FindFSM(type);
}

// Retail symbol:
// ?InitStates@idVehicleBaseFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA: 0x82B1D860, RVA: 0x00B1D860
void idVehicleBaseFSM::InitStates(
        const idFiniteStateMachineParams* const params) {
    Tungsten_InitVehicleBaseFSM(*this, params);
    AddState(Tungsten_GetGlobalAIErrorState());
    AddState(Tungsten_GetGlobalAIDoneState());
    AddState(&s_Idle);
    AddState(&s_Wait);
    Tungsten_SetVehicleFSMDefaultState(*this, &s_Idle);
}

// Retail symbol: ?GetErrorState@idVehicleBaseFSM@@UBAPAVidState@@XZ
// EA: 0x82B1D920, RVA: 0x00B1D920
idState* idVehicleBaseFSM::GetErrorState() {
    return Tungsten_GetGlobalAIErrorState();
}

// Retail symbol: ?PopState@idVehicleBaseFSM@@QAAX_N@Z
// EA: 0x82B1D940, RVA: 0x00B1D940
void idVehicleBaseFSM::PopState(const bool setPoppedState) {
    idVehicleState* poppedState = &s_Idle;
    if (stateStack.Num() > 0) {
        poppedState = stateStack[stateStack.Num() - 1];
        stateStack.RemoveIndexFast(stateStack.Num() - 1);
    }
    if (poppedState == nullptr) {
        return;
    }
    if (setPoppedState) {
        SetState(poppedState, 0, true);
    }
    poppedState->stacked = false;
}

// Retail symbol:
// ?FindFSM@idVehicleFSMManager@@UBAPBVidFiniteStateMachine@@PBD@Z
// EA: 0x82B1DA60, RVA: 0x00B1DA60
const idVehicleFSM* idVehicleFSMManager::FindFSM(
        const char* const name) const {
    for (int index = 0; index < fsms.Num(); ++index) {
        const idVehicleFSM* const fsm = fsms[index];
        if (fsm != nullptr && EqualsIgnoreCase(
                Tungsten_GetVehicleFSMName(*fsm), name)) {
            return fsm;
        }
    }
    return nullptr;
}

// Retail symbol:
// ?FindFSM@idAIFSMManager@@UBAPBVidFiniteStateMachine@@ABVidTypeInfo@@@Z
// EA: 0x82B1DAD8, RVA: 0x00B1DAD8
const idAIFSM* idAIFSMManager::FindFSM(
        const idTypeInfo* const type) const {
    if (type == nullptr) {
        return nullptr;
    }
    for (int index = 0; index < fsms.Num(); ++index) {
        const idAIFSM* const fsm = fsms[index];
        if (fsm != nullptr && Tungsten_AIFSMIsType(*fsm, *type)) {
            return fsm;
        }
    }
    return nullptr;
}

idVehicleFSM* idVehicleFSMManager::FindFSM(
        const idTypeInfo* const type) const {
    if (type == nullptr) {
        return nullptr;
    }
    for (int index = 0; index < fsms.Num(); ++index) {
        idVehicleFSM* const fsm = fsms[index];
        if (fsm != nullptr && Tungsten_VehicleFSMIsType(*fsm, *type)) {
            return fsm;
        }
    }
    return nullptr;
}

// Retail symbol:
// ?SetState@idVehicleBaseFSM@@UAAXPAVidState@@H_N@Z
// EA: 0x82B1DB80, RVA: 0x00B1DB80
void idVehicleBaseFSM::SetState(idState* state,
        const int delayTime, const bool stacked) {
    if (state == nullptr || state == curState) {
        return;
    }

    const int currentTime = Tungsten_GetVehicleFSMTime(-1);
    if (!Tungsten_IsVehicleFSMStateRegistered(*this, *state)) {
        Tungsten_SetVehicleFSMCurrentState(*this, &s_Idle, currentTime);
        Tungsten_VehicleFSMWarning(
            Tungsten_GetVehicleStateClassname(*state));
        return;
    }

    if (!stacked) {
        stateStack.Clear();
    }
    if (delayTime != 0) {
        s_Wait.waitNextState = state;
        s_Wait.waitTime = currentTime + delayTime;
        state = &s_Wait;
    } else {
        s_Wait.waitTime = 0;
    }
    Tungsten_SetVehicleFSMCurrentState(*this, state, currentTime);
}

// Retail symbol: ??0idVehicleFSMManager@@QAA@XZ
// EA: 0x82B1DCE8, RVA: 0x00B1DCE8
idVehicleFSMManager::idVehicleFSMManager()
    : idFSMManager()
    , fsms() {
    owner.Invalidate();
    fsms.Clear();
}

// Retail symbol: ??1idVehicleFSMManager@@UAA@XZ
// EA: 0x82B1DDA0, RVA: 0x00B1DDA0
idVehicleFSMManager::~idVehicleFSMManager() {
    fsms.Clear();
}

// Retail symbol: ??1idVehicleFSM@@UAA@XZ
// EA: 0x82B1DE28, RVA: 0x00B1DE28
idVehicleFSM::~idVehicleFSM() = default;

// Retail symbol: ?Init@idVehicleFSMManager@@QAAXPAVidEntity@@@Z
// EA: 0x82B1DE98, RVA: 0x00B1DE98
void idVehicleFSMManager::Init(idEntity* const ownerEntity) {
    owner.SetSpawnId(ownerEntity != nullptr
        ? Tungsten_GetEntitySpawnId(ownerEntity)
        : VEHICLE_INVALID_OWNER_SPAWN_ID);
}

// Retail symbol: ?PushState@idVehicleBaseFSM@@QAAXABVidTypeInfo@@H@Z
// EA: 0x82B1E028, RVA: 0x00B1E028
void idVehicleBaseFSM::PushState(const idTypeInfo* const stateType,
        const int delayTime) {
    idVehicleState* const current =
        dynamic_cast<idVehicleState*>(curState);
    if (current == nullptr) {
        return;
    }
    stateStack.Append(current);
    current->stacked = true;
    SetState(stateType, delayTime, true);
}

// Retail symbol: ??0idVehicleFSM@@QAA@XZ
// EA: 0x82B1E090, RVA: 0x00B1E090
idVehicleFSM::idVehicleFSM()
    : idVehicleBaseFSM("FSM_Vehicle") {
}

// Retail symbol: ?AddFSM@idVehicleFSMManager@@QAAXPAVidVehicleFSM@@PBD@Z
// EA: 0x82B1E140, RVA: 0x00B1E140
void idVehicleFSMManager::AddFSM(idVehicleFSM* const fsm,
        const char* const name) {
    if (fsm == nullptr) {
        return;
    }
    fsms.Append(fsm);
    idFiniteStateMachineParams params;
    params.manager = this;
    Tungsten_InitRegisteredVehicleFSM(*fsm, params);
    if (name != nullptr) {
        Tungsten_SetVehicleFSMName(*fsm, name);
    }
}
