
// ========================================================================
// ??0idPresentableTurret@@QAA@PBVidDeclWeapon@@PAVidTurret@@PAVidRenderModel@@PAVidAnimator_JointMod@@V?$idIndex@FW4invalidJointIndex_t@@@@44PAVidAnimStack@@HPBVidDeclFX@@_N@Z
// EA  : 0x82B8FCD8
// RVA : 0x00B8FCD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableturret.cpp
// ========================================================================

idPresentableTurret *__fastcall idPresentableTurret::idPresentableTurret(
        idPresentableTurret *this,
        const idDeclWeapon *weaponDecl_,
        idTurret *ent,
        idRenderModel *renderModel_,
        idAnimator_JointMod *jointMod_,
        idIndex<short,enum invalidJointIndex_t> *jointRotaion_,
        idIndex<short,enum invalidJointIndex_t> *jointPitch_,
        idIndex<short,enum invalidJointIndex_t> *jointSpinwheel_,
        idAnimStack *animStack_,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idAnimStack *a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        bool a34)
{
  __int16 v34; // r29
  __int16 v36; // r28
  __int16 v38; // r27

  v34 = (__int16)jointRotaion_;
  v36 = (__int16)jointPitch_;
  v38 = (__int16)jointSpinwheel_;
  idPresentableWeapon::idPresentableWeapon(
    this,
    renderModel_,
    weaponDecl_,
    ownerEntityNum_: a30,
    animStack_: a28,
    ent_: ent,
    useSphereModel_: a34);
  this->__vftable = (idPresentableTurret_vtbl *)&idPresentableTurret::`vftable';
  this->jointRotation.value = -1;
  this->jointPitch.value = -1;
  this->jointSpinwheel.value = -1;
  this->jointRotationPitch = 0;
  this->jointRotationYaw = 0;
  this->clientLastUpdateRotationYaw = 0;
  this->clientLastUpdateRotationPitch = 0;
  this->jointModAnimator = jointMod_;
  this->jointRotation.value = v34;
  this->jointPitch.value = v36;
  this->jointSpinwheel.value = v38;
  return this;
}


// ========================================================================
// ?ClientThink@idPresentableTurret@@UAAXHM_N@Z
// EA  : 0x82B8FD60
// RVA : 0x00B8FD60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableturret.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentableTurret::ClientThink(idPresentableTurret *this, __int64 predict, double fraction)
{
  idAnimator_JointMod *jointModAnimator; // r3
  int v5; // r29
  __int16 value; // r11
  __int16 clientLastUpdateRotationYaw; // r11
  __int128 v9; // r6 OVERLAPPED
  __int64 v10; // r11
  __int64 v11; // r8
  double v12; // fp0
  const idMat3 *v13; // r3
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  __int16 clientLastUpdatejointPitch; // r11
  __int16 jointPitchPitch; // r10
  __int64 v21; // r9
  __int64 v22; // r7
  const idMat3 *v23; // r3
  int v24; // r10
  int v25; // r9
  int v26; // r8
  int v27; // r7
  int v28; // r6
  const idMat3 *v29; // r3
  int v30; // r10
  int v31; // r9
  int v32; // r8
  int v33; // r7
  int v34; // r6
  int v35; // [sp+8h] [-F8h]
  int v36; // [sp+Ch] [-F4h]
  int v37; // [sp+10h] [-F0h]
  int v38; // [sp+14h] [-ECh]
  int v39; // [sp+18h] [-E8h]
  idIndex<short,enum invalidUserChannelIndex_t> *v40; // [sp+1Ch] [-E4h]
  idMat3 v41; // [sp+58h] [-A8h] BYREF
  float v42; // [sp+7Ch] [-84h]
  float v43; // [sp+80h] [-80h]
  idAngles v44[4]; // [sp+90h] [-70h] BYREF

  jointModAnimator = this->jointModAnimator;
  v5 = HIDWORD(predict);
  if ( jointModAnimator != nullptr && this->serializeCount > 2 )
  {
    idAnimator_JointMod::ClearJointMods(this: jointModAnimator);
    value = NULL_JOINT_INDEX.value;
    if ( this->jointRotation.value != NULL_JOINT_INDEX.value )
    {
      clientLastUpdateRotationYaw = this->clientLastUpdateRotationYaw;
      v41.mat[0].z = 0.0;
      DWORD1(v9) = &v41;
      DWORD2(v9) = clientLastUpdateRotationYaw;
      HIDWORD(v10) = this->clientLastUpdateRotationPitch;
      LODWORD(v10) = this->jointRotationYaw - clientLastUpdateRotationYaw;
      LODWORD(v11) = HIDWORD(v10);
      LODWORD(v9) = this->jointRotationPitch - HIDWORD(v10);
      HIDWORD(v11) = v9;
      v12 = (float)((float)((float)(__int64)v9 * (float)fraction) + (float)v11);
      HIDWORD(v11) = (__int16)(int)(float)((float)((float)v10 * (float)fraction) + (float)*(__int64 *)((char *)&v9 + 4));
      LODWORD(v11) = (__int16)(int)v12;
      v41.mat[0].x = (float)v11 * (float)0.0054931641;
      v41.mat[0].y = (float)*(__int64 *)((char *)&v9 - 4) * (float)0.0054931641;
      v13 = idAngles::ToMat3(this: v44, result: &v41);
      idAnimator_JointMod::SetJointMod(
        this: this->jointModAnimator,
        index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointRotation.value,
        value: v13,
        a4: v18,
        a5: v17,
        a6: v16,
        a7: v15,
        a8: v14,
        a9: v35,
        a10: v36,
        a11: v37,
        a12: v38,
        a13: v39,
        a14: v40);
      value = NULL_JOINT_INDEX.value;
    }
    if ( this->jointPitch.value != value )
    {
      clientLastUpdatejointPitch = this->clientLastUpdatejointPitch;
      v41.mat[1].z = 0.0;
      jointPitchPitch = this->jointPitchPitch;
      v41.mat[2].x = 0.0;
      HIDWORD(v21) = jointPitchPitch;
      LODWORD(v22) = clientLastUpdatejointPitch;
      HIDWORD(v22) = jointPitchPitch - clientLastUpdatejointPitch;
      LODWORD(predict) = HIDWORD(v22);
      LODWORD(v21) = (__int16)(int)(float)((float)((float)predict * (float)fraction) + (float)v22);
      v41.mat[1].y = (float)v21 * (float)0.0054931641;
      v23 = idAngles::ToMat3(this: v44, result: (idMat3 *)&v41.mat[1].y);
      idAnimator_JointMod::SetJointMod(
        this: this->jointModAnimator,
        index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
        value: v23,
        a4: v28,
        a5: v27,
        a6: v26,
        a7: v25,
        a8: v24,
        a9: v35,
        a10: v36,
        a11: v37,
        a12: v38,
        a13: v39,
        a14: v40);
      value = NULL_JOINT_INDEX.value;
    }
    if ( this->jointSpinwheel.value != value )
    {
      v41.mat[2].z = 0.0;
      v42 = 0.0;
      v43 = 0.0;
      v29 = idAngles::ToMat3(this: v44, result: (idMat3 *)&v41.mat[2].z);
      idAnimator_JointMod::SetJointMod(
        this: this->jointModAnimator,
        index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointSpinwheel.value,
        value: v29,
        a4: v34,
        a5: v33,
        a6: v32,
        a7: v31,
        a8: v30,
        a9: v35,
        a10: v36,
        a11: v37,
        a12: v38,
        a13: v39,
        a14: v40);
    }
  }
  idPresentableWeapon::ClientThink(this, curTime: v5, fraction, predict);
}


// ========================================================================
// ?ApplyJointMod@idPresentableTurret@@QAAXV?$idIndex@FW4invalidJointIndex_t@@@@VidMat3@@@Z
// EA  : 0x82B8FFD0
// RVA : 0x00B8FFD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableturret.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentableTurret::ApplyJointMod(
        idPresentableTurret *this,
        __int64 axis,
        __int64 a3,
        __int64 a4,
        int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int16 value; // r11
  __int16 v15; // r29
  int v16; // r10
  __int16 v17; // r11
  bool v18; // zf
  int v19; // fp10
  __int16 v20; // r10
  idMat3 v21; // [sp+50h] [-40h] BYREF

  a9 = axis;
  value = this->jointRotation.value;
  a10 = *(__int64 *)((char *)&a3 + 4);
  v15 = WORD1(axis);
  a11 = a3;
  v16 = value;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  v18 = value == NULL_JOINT_INDEX.value;
  v17 = NULL_JOINT_INDEX.value;
  if ( !v18 && v16 == SWORD1(axis) )
  {
    idMat3::ToAngles(this: &v21, result: (idAngles *)&a9);
    v19 = (int)(float)(v21.mat[0].x * (float)182.04445);
    LODWORD(v21.mat[0].y) = (int)(float)(v21.mat[0].y * (float)182.04445);
    this->jointRotationYaw = LOWORD(v21.mat[0].y);
    this->jointRotationPitch = v19;
    v17 = NULL_JOINT_INDEX.value;
  }
  v20 = this->jointPitch.value;
  if ( v20 != v17 && v20 == v15 )
  {
    idMat3::ToAngles(this: &v21, result: (idAngles *)&a9);
    LODWORD(v21.mat[0].y) = (int)(float)(v21.mat[0].x * (float)182.04445);
    this->jointPitchPitch = LOWORD(v21.mat[0].y);
  }
}


// ========================================================================
// ?GetFiredWeapon@idPresentableTurret@@UAAPAVidWeapon@@PBVidDeclWeapon@@@Z
// EA  : 0x82B900C0
// RVA : 0x00B900C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableturret.cpp
// ========================================================================

idWeapon *__fastcall idPresentableTurret::GetFiredWeapon(idPresentableTurret *this, const idDeclWeapon *wepDef)
{
  idTurret *v2; // r3

  v2 = idTurret::CastTo(c: (idTurret *)this->entity);
  if ( v2 != nullptr )
    return v2->turretWeapon;
  else
    return nullptr;
}


// ========================================================================
// ?Serialize@idPresentableTurret@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B90108
// RVA : 0x00B90108
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableturret.cpp
// ========================================================================

void __fastcall idPresentableTurret::Serialize(idPresentableTurret *this, idSerializer *ser)
{
  __int16 jointRotationPitch; // r10
  __int16 jointPitchPitch; // r9
  int value; // r11
  unsigned __int16 Bits; // r30
  idBitMsg *msg; // r3
  idIndex<short,enum invalidJointIndex_t> *v9; // r11
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  int v12; // r11
  unsigned __int16 v13; // r30
  idBitMsg *v14; // r3
  idIndex<short,enum invalidJointIndex_t> *v15; // r11
  idBitMsg *v16; // r3
  int v17; // r11
  unsigned __int16 v18; // r30
  idBitMsg *v19; // r3
  int v20[16]; // [sp+50h] [-40h] BYREF

  idPresentableWeapon::Serialize(this, ser);
  if ( !ser->writing )
  {
    jointRotationPitch = this->jointRotationPitch;
    jointPitchPitch = this->jointPitchPitch;
    this->clientLastUpdateRotationYaw = this->jointRotationYaw;
    this->clientLastUpdateRotationPitch = jointRotationPitch;
    this->clientLastUpdatejointPitch = jointPitchPitch;
  }
  if ( ser->writing )
  {
    v20[0] = idAnimStack::GetAnimatorIndex(this: this->animStack, animator: this->jointModAnimator);
    idSerializer::SerializePacked(this: ser, original: v20);
  }
  else
  {
    idSerializer::SerializePacked(this: ser, original: v20);
    this->jointModAnimator = (idAnimator_JointMod *)idAnimStack::GetAnimatorByIndex(
                                                      this: this->animStack,
                                                      index: v20[0]);
  }
  value = this->jointRotation.value;
  if ( value == NULL_JOINT_INDEX.value )
    LOWORD(value) = -1;
  Bits = value;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, (unsigned __int16)value, numBits: 16);
  else
    Bits = idBitMsg::ReadBits(this: msg, numBits: 16);
  if ( Bits == 0xFFFF )
  {
    v9 = &NULL_JOINT_INDEX;
  }
  else
  {
    HIWORD(v20[0]) = Bits;
    v9 = (idIndex<short,enum invalidJointIndex_t> *)v20;
  }
  this->jointRotation = (idIndex<short,enum invalidJointIndex_t>)v9->value;
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: this->jointRotationYaw, numBits: -16);
  else
    this->jointRotationYaw = idBitMsg::ReadBits(this: v10, numBits: -16);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: this->jointRotationPitch, numBits: -16);
  else
    this->jointRotationPitch = idBitMsg::ReadBits(this: v11, numBits: -16);
  v12 = this->jointPitch.value;
  if ( v12 == NULL_JOINT_INDEX.value )
    LOWORD(v12) = -1;
  v13 = v12;
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: (unsigned __int16)v12, numBits: 16);
  else
    v13 = idBitMsg::ReadBits(this: v14, numBits: 16);
  if ( v13 == 0xFFFF )
  {
    v15 = &NULL_JOINT_INDEX;
  }
  else
  {
    HIWORD(v20[0]) = v13;
    v15 = (idIndex<short,enum invalidJointIndex_t> *)v20;
  }
  this->jointPitch = (idIndex<short,enum invalidJointIndex_t>)v15->value;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: this->jointPitchPitch, numBits: -16);
  else
    this->jointPitchPitch = idBitMsg::ReadBits(this: v16, numBits: -16);
  v17 = this->jointSpinwheel.value;
  if ( v17 == NULL_JOINT_INDEX.value )
    LOWORD(v17) = -1;
  v18 = v17;
  v19 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v19, value: (unsigned __int16)v17, numBits: 16);
  else
    v18 = idBitMsg::ReadBits(this: v19, numBits: 16);
  if ( v18 == 0xFFFF )
    this->jointSpinwheel = NULL_JOINT_INDEX;
  else
    this->jointSpinwheel.value = v18;
}

