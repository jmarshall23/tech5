
// ========================================================================
// ??0idAITest_Rotation@@QAA@XZ
// EA  : 0x82A60B10
// RVA : 0x00A60B10
// PDB : w:\tech5\tungsten\game\ai\aitest.cpp
// ========================================================================

idAITest_Rotation *__fastcall idAITest_Rotation::idAITest_Rotation(idAITest_Rotation *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idAITest_Rotation_vtbl *)&idAITest_Rotation::`vftable';
  idRotationTracker::idRotationTracker(this: &this->tracker);
  this->lastDir.x = 1.0;
  this->lastDir.y = 0.0;
  this->lastDir.z = 0.0;
  this->rate.pitch = 360.0;
  this->rate.yaw = 360.0;
  this->rate.roll = 0.0;
  return this;
}


// ========================================================================
// __unwind$487679
// EA  : 0x82A60BA4
// RVA : 0x00A60BA4
// PDB : w:\tech5\tungsten\game\ai\aitest.cpp
// ========================================================================

void _unwind_487679()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idAITest_Rotation@@UAAXXZ
// EA  : 0x82A60CA8
// RVA : 0x00A60CA8
// PDB : w:\tech5\tungsten\game\ai\aitest.cpp
// ========================================================================

void __fastcall idAITest_Rotation::Think(idAITest_Rotation *this)
{
  idPlayer *DebugPlayer; // r29
  idPhysics *Physics; // r3
  float *v4; // r30
  idPhysics *v5; // r3
  int v6; // r28
  double v7; // fp1
  idPhysics *v8; // r26
  float *v9; // r29
  float *v10; // r3
  double v11; // fp10
  double v12; // fp5
  double v13; // fp4
  double v14; // fp3
  double y; // fp13
  double z; // fp12
  __int64 v17; // r9
  double v18; // fp10
  double v19; // fp9
  __int64 v20; // [sp+50h] [-60h] BYREF
  idVec3 v21[6]; // [sp+60h] [-50h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v5 = idEntity::GetPhysics(this);
    v6 = (int)v5->GetAxis(this: v5, a2: 0);
    if ( aitest_freezeTracker.valueInteger != 0 )
    {
      y = this->lastDir.y;
      z = this->lastDir.z;
      v21[0].x = this->lastDir.x;
      v21[0].y = y;
      v21[0].z = z;
    }
    else
    {
      v8 = idEntity::GetPhysics(this: DebugPlayer);
      v9 = (float *)DebugPlayer->GetEyeOffset(this: (idActor *)&v20, result: (const idVec3 *)DebugPlayer);
      v10 = (float *)v8->GetOrigin(this: v8, a2: 0);
      v11 = v4[1];
      v12 = (float)(v9[1] + v10[1]);
      v13 = (float)(v9[2] + v10[2]);
      v14 = v4[2];
      v21[0].x = (float)(*v9 + *v10) - *v4;
      v21[0].y = (float)v12 - (float)v11;
      v21[0].z = (float)v13 - (float)v14;
      v7 = idVec3::NormalizeFast(this: v21);
    }
    LODWORD(v17) = ((int (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameMsPerFrame)(
                     a1: gameLocal,
                     a2: 1,
                     a3: v7);
    HIDWORD(v17) = this->tracker.__vftable;
    v20 = v17;
    (*(void (__fastcall **)(idRotationTracker *, float *, int, idVec3 *, double))(HIDWORD(v17) + 4))(
      a1: &this->tracker,
      a2: v4,
      a3: v6,
      a4: v21,
      a5: (float)((float)v17 * (float)0.001));
    v18 = v21[0].y;
    v19 = v21[0].z;
    this->lastDir.x = v21[0].x;
    this->lastDir.y = v18;
    this->lastDir.z = v19;
  }
}


// ========================================================================
// `dynamic initializer for 'aitest_freezeTracker''
// EA  : 0x83367BA0
// RVA : 0x01367BA0
// PDB : w:\tech5\tungsten\game\ai\aitest.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aitest_freezeTracker__()
{
  idCVar::idCVar(
    this: &aitest_freezeTracker,
    name: "aitest_freezeTracker",
    value: "0",
    flags: 1,
    description: "for testing ai rotation trackers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aitest_freezeTracker__);
}

