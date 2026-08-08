
// ========================================================================
// ?OnActivate@action_moveToGoalEntity@@UAAXVssEntity@@@Z
// EA  : 0x82EECFE0
// RVA : 0x00EECFE0
// PDB : w:\tech5\tungsten\superscript\util\action.cpp
// ========================================================================

void __fastcall action_moveToGoalEntity::OnActivate(action_moveToGoalEntity *this, ssEntity *activator)
{
  int v3; // r9
  char v4; // r11
  char v5; // r3
  char v6; // r11
  int v7; // r6
  ssEntity *v8; // r3
  ssEntity *v9; // r3
  int v10; // r27
  int v11; // r28
  int v12; // r9
  char v13; // r11
  ssEntity *v14; // r30
  ssEntity *v15; // r3
  ssString *v16; // r3
  ssEntity v17[2]; // [sp+50h] [-A0h] BYREF
  float v18[6]; // [sp+58h] [-98h] BYREF
  ssString v19; // [sp+70h] [-80h] BYREF
  ssString v20; // [sp+80h] [-70h] BYREF
  ssString v21[6]; // [sp+90h] [-60h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "Actor sent to goal");
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v19.data);
  ssString::Empty(this: &v19);
  if ( this->actor.spawnId == 0
    || (v3 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v4 = 1,
        v3 == 0) )
  {
    v4 = 0;
  }
  if ( v4 == 0 )
    goto LABEL_26;
  if ( this->goal.spawnId == 0
    || (v5 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v6 = 1,
        v5 == 0) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
  {
    ssEntity::Action_SetAlertCycle(this: &this->actor, alertCycle: 3);
    ssEntity::Action_SetWalkState(this: &this->actor, state: 2);
    gameInterface->WaitFrame(this: gameInterface);
    v18[0] = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    ssEntity::ssEntity(this: v17, e: &this->goal);
    ssEntity::Action_MoveToEntity(
      this: &this->actor,
      ent: v8,
      stopUponArraival: 0,
      reachedDistance: 16.0,
      align: v7,
      alignDir: nullptr,
      a7: v18);
    if ( (unsigned __int8)ssEntity::IsValid(this: &this->activationEntity) != 0 )
    {
      ssEntity::ssEntity(this: v17, e: &this->self);
      ssEntity::Activate(this: &this->activationEntity, activator: v9);
    }
    v10 = 0;
    if ( this->activationList.num > 0 )
    {
      v11 = 0;
      do
      {
        if ( v10 < 0 || v10 >= this->activationList.num )
          AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
        if ( this->activationList.data[v11].spawnId == 0
          || (v12 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
              v13 = 1,
              v12 == 0) )
        {
          v13 = 0;
        }
        if ( v13 != 0 )
        {
          if ( v10 < 0 || v10 >= this->activationList.num )
            AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
          v14 = &this->activationList.data[v11];
          ssEntity::ssEntity(this: v17, e: &this->actor);
          ssEntity::Activate(this: v14, activator: v15);
        }
        ++v10;
        ++v11;
      }
      while ( v10 < this->activationList.num );
    }
    ssString::Init(this: &v20);
    ssString::operator=(this: &v20, text: "Actor reached goal");
    gameInterface->Printf(this: gameInterface, a2: "%s\n", v20.data);
    v16 = &v20;
  }
  else
  {
LABEL_26:
    ssString::Init(this: v21);
    ssString::operator=(this: v21, text: "Actor or goal is not valid");
    gameInterface->Printf(this: gameInterface, a2: "%s\n", v21[0].data);
    v16 = v21;
  }
  ssString::Empty(this: v16);
}


// ========================================================================
// __unwind$19114
// EA  : 0x82EED2AC
// RVA : 0x00EED2AC
// PDB : w:\tech5\tungsten\superscript\util\action.cpp
// ========================================================================

void _unwind_19114()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$19116
// EA  : 0x82EED2D4
// RVA : 0x00EED2D4
// PDB : w:\tech5\tungsten\superscript\util\action.cpp
// ========================================================================

void _unwind_19116()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$19115
// EA  : 0x82EED2FC
// RVA : 0x00EED2FC
// PDB : w:\tech5\tungsten\superscript\util\action.cpp
// ========================================================================

void _unwind_19115()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 240 + 144));
}

