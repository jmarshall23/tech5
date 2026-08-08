
// ========================================================================
// ?startMoverTest@jake_test1@@QAAXXZ
// EA  : 0x82EE92B0
// RVA : 0x00EE92B0
// PDB : w:\tech5\tungsten\superscript\maps\user\jake\jake_test.cpp
// ========================================================================

void __fastcall jake_test1::startMoverTest(jake_test1 *this)
{
  ssEntity *v1; // r3
  ssEntity v2; // [sp+50h] [-10h] BYREF
  ssEntity v3; // [sp+54h] [-Ch] BYREF

  ssEntity::ssEntity(this: &v2, name: "mover1");
  v1 = ssEntity::ssEntity(this: &v3, name: "spline1");
  ssEntity::StartSpline(this: &v2, splineEntity: v1);
}


// ========================================================================
// ?toGoal1@jake_test1@@QAAXXZ
// EA  : 0x82EE92F8
// RVA : 0x00EE92F8
// PDB : w:\tech5\tungsten\superscript\maps\user\jake\jake_test.cpp
// ========================================================================

void __fastcall jake_test1::toGoal1(jake_test1 *this)
{
  ssEntity *Angles; // r3
  ssEntity *Origin; // r31
  ssEntity *v3; // r3
  int v4; // r6
  ssString v5; // [sp+50h] [-50h] BYREF
  int v6; // [sp+60h] [-40h]
  ssEntity v7[4]; // [sp+68h] [-38h] BYREF
  ssEntity v8; // [sp+78h] [-28h] BYREF

  ssEntity::ssEntity(this: (ssEntity *)&v5, name: "goal1");
  Angles = ssEntity::GetAngles(this: v7, result: &v5);
  *(float *)&v5.alloced = 0.0;
  *(float *)&v5.threadId = 0.0;
  *(float *)&v6 = 0.0;
  math::AngToVectors(a: (const ssVector *)Angles, f: (ssVector *)&v5.alloced, r: nullptr, u: nullptr);
  v7[0] = (ssEntity)v5.alloced;
  v7[1] = (ssEntity)v5.threadId;
  v7[2] = (ssEntity)v6;
  Origin = ssEntity::GetOrigin(this: &v8, result: &v5);
  v3 = ssEntity::ssEntity(this: (ssEntity *)&v5.data, name: "ai");
  ssEntity::Action_MoveToPoint(
    this: v3,
    dest: (ssVector *)Origin,
    stopUponArrival: 2,
    tolerance: 4.0,
    align: v4,
    alignDir: (ssVector *)1,
    a7: (float *)&v7[0].spawnId);
}


// ========================================================================
// ?toGoal2@jake_test1@@QAAXXZ
// EA  : 0x82EE93B0
// RVA : 0x00EE93B0
// PDB : w:\tech5\tungsten\superscript\maps\user\jake\jake_test.cpp
// ========================================================================

void __fastcall jake_test1::toGoal2(jake_test1 *this)
{
  ssEntity *Angles; // r3
  ssEntity *Origin; // r31
  ssEntity *v3; // r3
  int v4; // r6
  ssString v5; // [sp+50h] [-50h] BYREF
  int v6; // [sp+60h] [-40h]
  ssEntity v7[4]; // [sp+68h] [-38h] BYREF
  ssEntity v8; // [sp+78h] [-28h] BYREF

  ssEntity::ssEntity(this: (ssEntity *)&v5, name: "goal2");
  Angles = ssEntity::GetAngles(this: v7, result: &v5);
  *(float *)&v5.alloced = 0.0;
  *(float *)&v5.threadId = 0.0;
  *(float *)&v6 = 0.0;
  math::AngToVectors(a: (const ssVector *)Angles, f: (ssVector *)&v5.alloced, r: nullptr, u: nullptr);
  v7[0] = (ssEntity)v5.alloced;
  v7[1] = (ssEntity)v5.threadId;
  v7[2] = (ssEntity)v6;
  Origin = ssEntity::GetOrigin(this: &v8, result: &v5);
  v3 = ssEntity::ssEntity(this: (ssEntity *)&v5.data, name: "ai");
  ssEntity::Action_MoveToPoint(
    this: v3,
    dest: (ssVector *)Origin,
    stopUponArrival: 2,
    tolerance: 4.0,
    align: v4,
    alignDir: (ssVector *)1,
    a7: (float *)&v7[0].spawnId);
}

