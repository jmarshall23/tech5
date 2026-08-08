
// ========================================================================
// ?SetDelta@idPhysics_AI@@QAAXABVidVec3@@H@Z
// EA  : 0x82A696F8
// RVA : 0x00A696F8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.h
// ========================================================================

void __fastcall idPhysics_AI::SetDelta(idPhysics_AI *this, const idVec3 *d, unsigned int ticksPerFrame)
{
  double x; // fp11
  double y; // fp10
  double z; // fp9
  void (__fastcall *SetLinearVelocity)(struct idPhysics_AI *, const idVec3 *, int); // ctr
  unsigned __int64 v7; // [sp+50h] [-20h] BYREF
  float v8; // [sp+58h] [-18h]

  x = d->x;
  y = d->y;
  v7 = __PAIR64__(&unk_82150000, ticksPerFrame);
  z = d->z;
  SetLinearVelocity = this->SetLinearVelocity;
  *(float *)&v7 = (float)x * (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame));
  *((float *)&v7 + 1) = (float)y * (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame));
  v8 = (float)z * (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame));
  SetLinearVelocity(this, a2: (const idVec3 *)&v7, a3: 0);
}


// ========================================================================
// ?GetDelta@idPhysics_AI@@QBA?BVidVec3@@H@Z
// EA  : 0x82A69770
// RVA : 0x00A69770
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.h
// ========================================================================

idPhysics_AI *__fastcall idPhysics_AI::GetDelta(idPhysics_AI *this, const idVec3 *result, unsigned int ticksPerFrame)
{
  float *v5; // r3
  double v6; // fp10
  double v7; // fp9
  _BYTE v9[16]; // [sp+58h] [-28h] BYREF

  v5 = (float *)(*(int (__fastcall **)(_BYTE *))(LODWORD(result->x) + 88))(a1: v9);
  v6 = v5[1];
  v7 = v5[2];
  *(float *)&this->__vftable = *v5
                             * (float)((float)1.0
                                     / (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame)));
  *((float *)&this->__vftable + 1) = (float)v6
                                   * (float)((float)1.0
                                           / (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame)));
  *(float *)&this->type = (float)v7
                        * (float)((float)1.0 / (float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, ticksPerFrame)));
  return this;
}

