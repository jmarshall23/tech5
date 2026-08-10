#pragma once

#include "../fsm/aifsm.h"
#include "../fsm/aifsmmanager.h"
#include "idlib/containers/staticlist.h"

#include <string>

class idEntity;
class idTypeInfo;
class idVehicleAI;

static constexpr int VEHICLE_INVALID_OWNER_SPAWN_ID = 0x1FFF;

// The retail transition result is a twelve-byte state/transition/code tuple.
// Its interpretation stays with the central FSM implementation.
class idStateData {
public:
    struct transResult_t {
        unsigned char opaque[12] = {};
    };
};

class idVehicleState : public idState {
public:
    idVehicleState();
    virtual ~idVehicleState() = default;
    virtual void InternalWork(idFiniteStateMachine*, int) {}

    const std::string& GetDebugName() const { return debugName; }
    const std::string& GetDebugInfo() const { return debugInfo; }

    bool stacked;
    std::string debugName;
    std::string debugInfo;
    idVehicleAI* ai;
};

class idVS_Idle : public idVehicleState {};

class idVS_Wait : public idVehicleState {
public:
    idVS_Wait() : waitTime(0), waitNextState(nullptr) {}
    void InternalWork(idFiniteStateMachine* baseFSM, int currentTime) override;

    int waitTime;
    idState* waitNextState;
};

enum idVehicleDefaultTransitionKind : int {
    VEHICLE_TRANSITION_UNHANDLED_CHILD_ERROR = 0,
    VEHICLE_TRANSITION_STATE_ERROR = 1
};

class idVehicleBaseFSM : public idFiniteStateMachine {
public:
    idVehicleBaseFSM();
    explicit idVehicleBaseFSM(const char* name);
    ~idVehicleBaseFSM() override = default;

    virtual void AppendDefaultTransitions(idState* state);
    virtual void SetState(const idStateData::transResult_t* result,
        int currentTime, bool forcingStack);
    virtual void SetState(const idTypeInfo* stateType,
        int delayTime, bool stacked);
    virtual void AddState(idState* state);
    virtual void InitStates(const idFiniteStateMachineParams* params);
    idState* GetErrorState() override;
    idState* GetDoneState() override;
    virtual void SetState(idState* state, int delayTime, bool stacked);

    void PopState(bool setPoppedState);
    void PushState(const idTypeInfo* stateType, int delayTime);

    idStaticList<idVehicleState*, 4> stateStack;
    idState* dataState;
    idVS_Idle s_Idle;
    idVS_Wait s_Wait;
};

class idVehicleFSM : public idVehicleBaseFSM {
public:
    idVehicleFSM();
    ~idVehicleFSM() override;
};

class idVehicleFSMManager : public idFSMManager {
public:
    idVehicleFSMManager();
    ~idVehicleFSMManager() override;

    idFiniteStateMachine* AllocFSM(const idTypeInfo* type,
        const idFiniteStateMachineParams* params);
    idVehicleFSM* FindFSM(const idTypeInfo* type) const;
    const idVehicleFSM* FindFSM(const char* name) const;
    void Init(idEntity* ownerEntity);
    void AddFSM(idVehicleFSM* fsm, const char* name);

    idList<idVehicleFSM*, 5> fsms;
};

// Runtime boundaries for the central FSM registry/current-state engine,
// generated type hierarchy, game clock, entity table, and vehicle AI layout.
int Tungsten_GetVehicleFSMTime(int referenceTime);
void Tungsten_SetBaseFSMState(idFiniteStateMachine& fsm, idState* state,
    int delayTime, bool stacked);
void Tungsten_AddVehicleDefaultTransition(idState& state,
    idVehicleBaseFSM& fsm, idVehicleDefaultTransitionKind kind,
    idState* destination);
void Tungsten_SetBaseFSMTransitionResult(idFiniteStateMachine& fsm,
    const idStateData::transResult_t* result, int currentTime,
    bool forcingStack);
void Tungsten_AddBaseFSMState(idFiniteStateMachine& fsm, idState* state);
idState* Tungsten_FindVehicleFSMState(idVehicleBaseFSM& fsm,
    const idTypeInfo* stateType);
bool Tungsten_IsVehicleFSMStateRegistered(const idVehicleBaseFSM& fsm,
    const idState& state);
idVehicleAI* Tungsten_GetVehicleFSMOwner(idVehicleFSM& fsm);
void Tungsten_InitVehicleBaseFSM(idVehicleBaseFSM& fsm,
    const idFiniteStateMachineParams* params);
void Tungsten_SetVehicleFSMDefaultState(idVehicleBaseFSM& fsm,
    idState* state);
void Tungsten_SetVehicleFSMCurrentState(idVehicleBaseFSM& fsm,
    idState* state, int currentTime);
const char* Tungsten_GetVehicleStateClassname(const idState& state);
void Tungsten_VehicleFSMWarning(const char* stateClassname);
void Tungsten_InitVehicleBaseFSMRuntime(idVehicleBaseFSM& fsm,
    const char* name);
bool Tungsten_VehicleFSMIsType(const idVehicleFSM& fsm,
    const idTypeInfo& type);
bool Tungsten_AIFSMIsType(const idAIFSM& fsm, const idTypeInfo& type);
const char* Tungsten_GetVehicleFSMName(const idVehicleFSM& fsm);
void Tungsten_InitRegisteredVehicleFSM(idVehicleFSM& fsm,
    const idFiniteStateMachineParams& params);
void Tungsten_SetVehicleFSMName(idVehicleFSM& fsm, const char* name);
