
// ========================================================================
// ?GetFiredWeapon@idPresentableWeaponStatic@@UAAPAVidWeapon@@PBVidDeclWeapon@@@Z
// EA  : 0x82BB3958
// RVA : 0x00BB3958
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

idWeapon *__fastcall idPresentableWeaponStatic::GetFiredWeapon(
        idPresentableWeaponStatic *this,
        const idDeclWeapon *wepDef)
{
  const idDeclWeapon *weaponDecl; // r11

  weaponDecl = (const idDeclWeapon *)this->weaponDecl;
  if ( weaponDecl != nullptr && wepDef == weaponDecl )
    return this->clientWeapon;
  else
    return nullptr;
}


// ========================================================================
// ?PullTrigger@idPresentableWeaponStatic@@AAAXXZ
// EA  : 0x82BB3980
// RVA : 0x00BB3980
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::PullTrigger(idPresentableWeaponStatic *this)
{
  idPresentable::StartSoundShader(
    this,
    channel: SND_CHANNEL_WEAPON,
    shader: this->sndFireLoop,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0);
  this->windupTimer = this->windupTime;
  this->shooting = true;
}


// ========================================================================
// ?ReleaseTrigger@idPresentableWeaponStatic@@AAAXXZ
// EA  : 0x82BB39D0
// RVA : 0x00BB39D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::ReleaseTrigger(idPresentableWeaponStatic *this)
{
  this->shooting = false;
  idPresentable::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0);
  idPresentable::StartSoundShader(
    this,
    channel: SND_CHANNEL_WEAPON2,
    shader: this->sndFireStop,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0);
  this->windupTimer = this->windupTime;
}


// ========================================================================
// ?PostSerializeRead@idPresentableWeaponStatic@@UAAX_N@Z
// EA  : 0x82BB3A30
// RVA : 0x00BB3A30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::PostSerializeRead(idPresentableWeaponStatic *this, bool firstClientFrame)
{
  const idDeclInventory *weaponDecl; // r3
  idInventoryItem *v4; // r3
  idWeapon *v5; // r3

  idPresentableAnimatedEntity::PostSerializeRead(this, firstClientFrame);
  weaponDecl = this->weaponDecl;
  if ( weaponDecl != nullptr && this->clientWeapon == nullptr )
  {
    v4 = idInventoryItem::Create(decl: weaponDecl);
    v5 = (idWeapon *)_RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &idInventoryItem `RTTI Type Descriptor',
                       TargetType: &idWeapon `RTTI Type Descriptor',
                       isReference: 0);
    this->clientWeapon = v5;
    if ( v5 == nullptr )
      idLib::Warning(
        fmt: "idPresentableWeaponStatic::PostSerializeRead: Unable to create clientWeapon from serialized decl '%s'",
        this->weaponDecl->name.str);
  }
}


// ========================================================================
// ?Draw@idPresentableWeaponStatic@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82BB3AB8
// RVA : 0x00BB3AB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

int __fastcall idPresentableWeaponStatic::Draw(idPresentableWeaponStatic *this, idPresentablePlayer *player)
{
  idView *p_view; // r29
  idIndex<short,enum invalidJointIndex_t> *TreeAnimator; // r3
  idIndex<short,enum invalidJointIndex_t> *v5; // r3
  const idIndex<short,enum invalidJointIndex_t> *value; // r30
  idTreeAnimator *v7; // r3
  double x; // fp10
  double y; // fp9
  double z; // fp8
  double v12; // fp7
  BOOL shooting; // r11
  double v14; // fp0
  double v15; // fp7
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp9
  double v21; // fp8
  _BYTE v22[8]; // [sp+50h] [-A0h] BYREF
  idVec3 v23; // [sp+58h] [-98h] BYREF
  idVec3 v24; // [sp+68h] [-88h] BYREF
  idMat3 v25; // [sp+80h] [-70h] BYREF

  p_view = &player->view;
  if ( idPresentableAnimatedEntity::GetTreeAnimator(this) != nullptr )
  {
    TreeAnimator = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this);
    this->jointPitch.value = HIWORD(idTreeAnimator::GetJointIndex(
                                      this: (idTreeAnimator *)v22,
                                      result: TreeAnimator,
                                      jointName: "gun")->__vftable);
    v5 = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this);
    this->jointYaw.value = HIWORD(idTreeAnimator::GetJointIndex(
                                    this: (idTreeAnimator *)v22,
                                    result: v5,
                                    jointName: "disk")->__vftable);
  }
  value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value;
  v7 = idPresentableAnimatedEntity::GetTreeAnimator(this);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: v7,
                          pose: DRIVER_MODEL,
                          jointIndex: value,
                          origin: &v24,
                          axis: &v25) == 0 )
    return 0;
  x = this->lookAt.mat[2].x;
  y = this->lookAt.mat[2].y;
  z = this->lookAt.mat[2].z;
  v12 = (float)(this->zoomTime * (float)0.0055555557);
  v23.z = v24.z;
  shooting = this->shooting;
  v14 = 0.0;
  v16 = (float)((float)x
              * (float)((float)((float)((float)1.0 - (float)v12) * (float)9.0) + (float)((float)v12 * (float)16.0)));
  v17 = (float)((float)y
              * (float)((float)((float)((float)1.0 - (float)v12) * (float)9.0) + (float)((float)v12 * (float)16.0)));
  v18 = (float)((float)z
              * (float)((float)((float)((float)1.0 - (float)v12) * (float)9.0) + (float)((float)v12 * (float)16.0)));
  v15 = (float)((float)((float)((float)1.0 - (float)v12) * (float)0.0) + (float)((float)v12 * (float)29.0));
  v19 = (float)(this->lookAt.mat[0].x * (float)v15);
  v20 = (float)(this->lookAt.mat[0].y * (float)v15);
  v23.y = v24.y;
  v21 = (float)(this->lookAt.mat[0].z * (float)v15);
  v23.x = (float)(v24.x + (float)v16) - (float)v19;
  v23.y = (float)(v24.y + (float)v17) - (float)v20;
  v23.z = (float)(v24.z + (float)v18) - (float)v21;
  if ( shooting && this->windupTimer <= 0.0 )
  {
    idView::SetControllerShake(
      this: p_view,
      highMagnitude: 0.5,
      highDuration: SLODWORD(v24.y),
      lowMagnitude: 1.0,
      lowDuration: 250);
    v14 = 0.029999999;
  }
  p_view->cameraShake = v14;
  idView::SetViewPos(this: p_view, origin: &v23, axis: &this->lookAt);
  idView::CalcFOV(this: p_view, base_fov: 90.0);
  idView::Render(this: p_view);
  return 1;
}


// ========================================================================
// ??1idPresentableWeaponStatic@@UAA@XZ
// EA  : 0x82BB3D90
// RVA : 0x00BB3D90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::~idPresentableWeaponStatic(idPresentableWeaponStatic *this)
{
  idWeapon *clientWeapon; // r11
  idWeapon *v3; // r3

  this->__vftable = (idPresentableWeaponStatic_vtbl *)&idPresentableWeaponStatic::`vftable';
  clientWeapon = this->clientWeapon;
  if ( clientWeapon != nullptr )
  {
    clientWeapon->presentableWeapon.spawnId = 0;
    if ( common->IsClient(this: common) )
    {
      v3 = this->clientWeapon;
      if ( v3 != nullptr )
        ((void (__fastcall *)(idWeapon *, int))v3->dtr_idClass)(a1: v3, a2: 1);
    }
    this->clientWeapon = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->barrels);
  idPresentableProp::~idPresentableProp(this);
}


// ========================================================================
// __unwind$489346
// EA  : 0x82BB3E34
// RVA : 0x00BB3E34
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void _unwind_489346()
{
  int v0; // r12

  idPresentableProp::~idPresentableProp(this: *(idPresentableProp **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489347
// EA  : 0x82BB3E5C
// RVA : 0x00BB3E5C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void _unwind_489347()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1400));
}


// ========================================================================
// ?SetClientWeapon@idPresentableWeaponStatic@@QAAXPAVidWeapon@@@Z
// EA  : 0x82BB3E90
// RVA : 0x00BB3E90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::SetClientWeapon(idPresentableWeaponStatic *this, idWeapon *weapon)
{
  idWeapon *clientWeapon; // r11

  clientWeapon = this->clientWeapon;
  if ( clientWeapon != nullptr )
    clientWeapon->presentableWeapon.spawnId = 0;
  this->clientWeapon = weapon;
}


// ========================================================================
// ?Serialize@idPresentableWeaponStatic@@UAAXAAVidSerializer@@@Z
// EA  : 0x82BB3EB0
// RVA : 0x00BB3EB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::Serialize(idPresentableWeaponStatic *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  idBitMsg *v10; // r3
  bool overheating; // r29
  idBitMsg *v12; // r3
  int v13[12]; // [sp+50h] [-30h] BYREF

  idPresentableProp::Serialize(this, ser);
  msg = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->curHeat);
    idBitMsg::WriteBits(this: msg, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->curHeat) = idBitMsg::ReadBits(this: msg, numBits: 32);
  }
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->maxHeat, numBits: 32);
  else
    this->maxHeat = idBitMsg::ReadBits(this: v5, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->minPitch);
    idBitMsg::WriteBits(this: v6, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->minPitch) = idBitMsg::ReadBits(this: v6, numBits: 32);
  }
  v7 = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->maxPitch);
    idBitMsg::WriteBits(this: v7, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->maxPitch) = idBitMsg::ReadBits(this: v7, numBits: 32);
  }
  v8 = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->minYaw);
    idBitMsg::WriteBits(this: v8, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->minYaw) = idBitMsg::ReadBits(this: v8, numBits: 32);
  }
  v9 = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->maxYaw);
    idBitMsg::WriteBits(this: v9, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->maxYaw) = idBitMsg::ReadBits(this: v9, numBits: 32);
  }
  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->weaponDecl);
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndTurning);
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndFireLoop);
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndFireStop);
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndOverheat);
  v10 = ser->msg;
  if ( ser->writing )
  {
    v13[0] = SLODWORD(this->windupTime);
    idBitMsg::WriteBits(this: v10, value: v13[0], numBits: 32);
  }
  else
  {
    LODWORD(this->windupTime) = idBitMsg::ReadBits(this: v10, numBits: 32);
  }
  if ( ser->writing )
  {
    v13[0] = idAnimStack::GetAnimatorIndex(this: this->animStack, animator: this->jointModAnimator);
    idSerializer::SerializePacked(this: ser, original: v13);
  }
  else
  {
    idSerializer::SerializePacked(this: ser, original: v13);
    this->jointModAnimator = (idAnimator_JointMod *)idAnimStack::GetAnimatorByIndex(
                                                      this: this->animStack,
                                                      index: v13[0]);
  }
  overheating = this->overheating;
  v12 = ser->msg;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v12, value: this->overheating, numBits: 1);
    this->overheating = overheating;
  }
  else
  {
    this->overheating = (_cntlzw(idBitMsg::ReadBits(this: v12, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ?ClientThink@idPresentableWeaponStatic@@UAAXHM_N@Z
// EA  : 0x82BB4230
// RVA : 0x00BB4230
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentableWeaponStatic::ClientThink(
        idPresentableWeaponStatic *this,
        unsigned int curTime,
        double fraction,
        bool predict,
        char a5)
{
  const idIndex<short,enum invalidJointIndex_t> *value; // r28
  idTreeAnimator *TreeAnimator; // r3
  idMat3 *p_lookAt; // r24
  double y; // fp12
  double z; // fp11
  double v14; // fp10
  double v15; // fp9
  double x; // fp8
  double v17; // fp7
  double v18; // fp6
  int v19; // r26
  BOOL v20; // r27
  char v21; // r28
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  idPresentablePlayer *Controller; // r3
  _BYTE v26[12]; // r7 OVERLAPPED
  __int64 v27; // r4
  int v28; // r29
  int v29; // r30
  int v30; // r10
  int v31; // r11
  char v32; // r11
  __int64 v33; // r6
  double v34; // fp1
  double v35; // fp30
  __int64 v36; // r6
  double v37; // fp1
  double v38; // fp31
  double v39; // fp1
  int GameMs; // r20
  int v41; // r8
  int v42; // r11
  double v43; // fp31
  idWeapon *v44; // r3
  double v45; // fp13
  double v46; // fp13
  idWeapon *clientWeapon; // r3
  int turning; // r11
  double v49; // fp7
  char *v50; // r10
  float *p_z; // r11
  int i; // ctr
  double maxYaw; // fp7
  double minPitch; // fp26
  double minYaw; // fp25
  double v56; // fp1
  double v57; // fp31
  double v58; // fp1
  double v59; // fp27
  double v60; // fp1
  idMat3 *v61; // r3
  const idMat3 *v62; // r3
  int v63; // r10
  int v64; // r9
  int v65; // r8
  int v66; // r7
  int v67; // r6
  const idMat3 *v68; // r3
  int v69; // r10
  int v70; // r9
  int v71; // r8
  int v72; // r7
  int v73; // r6
  unsigned __int8 v74; // r5
  double v75; // fp10
  double v76; // fp8
  double v77; // fp9
  idClipModel *clipModel; // r3
  double v79; // fp13
  double v80; // fp0
  double v81; // fp1
  int v82; // r11
  __int64 v83; // r11
  bool v84; // r5
  idWeapon *v85; // r3
  int v86; // [sp+8h] [-258h]
  int v87; // [sp+8h] [-258h]
  int v88; // [sp+Ch] [-254h]
  int v89; // [sp+Ch] [-254h]
  int v90; // [sp+10h] [-250h]
  int v91; // [sp+10h] [-250h]
  int v92; // [sp+14h] [-24Ch]
  int v93; // [sp+14h] [-24Ch]
  int v94; // [sp+18h] [-248h]
  int v95; // [sp+18h] [-248h]
  idIndex<short,enum invalidUserChannelIndex_t> *v96; // [sp+1Ch] [-244h]
  idIndex<short,enum invalidUserChannelIndex_t> *v97; // [sp+1Ch] [-244h]
  idAngles v98; // [sp+50h] [-210h] BYREF
  idVec3 v99; // [sp+60h] [-200h] BYREF
  idMat3 v100; // [sp+70h] [-1F0h] BYREF
  float v101; // [sp+94h] [-1CCh]
  float v102; // [sp+98h] [-1C8h]
  idMat3 v103; // [sp+A0h] [-1C0h] BYREF
  idMat3 v104; // [sp+D0h] [-190h] BYREF
  idAngles v105; // [sp+F8h] [-168h] BYREF
  idVec3 v106; // [sp+108h] [-158h] BYREF
  idMat3 v107; // [sp+120h] [-140h] BYREF
  idMat3 v108; // [sp+150h] [-110h] BYREF
  char v109; // [sp+17Ch] [-E4h] BYREF
  idAngles v110[10]; // [sp+180h] [-E0h] BYREF

  idAnimator_JointMod::ClearJointMods(this: this->jointModAnimator);
  value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: TreeAnimator,
                          pose: DRIVER_MODEL,
                          jointIndex: value,
                          origin: &v106,
                          axis: &v104) != 0 )
  {
    p_lookAt = &this->lookAt;
    if ( (unsigned __int8)idMat3::Compare(this: &this->lookAt, a: &mat3_identity, epsilon: 0.000099999997) != 0 )
    {
      p_lookAt->mat[0].x = v104.mat[0].x;
      y = v104.mat[0].y;
      z = v104.mat[0].z;
      this->lookAt.mat[1].x = v104.mat[1].x;
      v14 = v104.mat[1].y;
      this->lookAt.mat[0].y = y;
      this->lookAt.mat[0].z = z;
      v15 = v104.mat[1].z;
      this->lookAt.mat[1].y = v14;
      x = v104.mat[2].x;
      this->lookAt.mat[1].z = v15;
      v17 = v104.mat[2].y;
      this->lookAt.mat[2].x = x;
      v18 = v104.mat[2].z;
      this->lookAt.mat[2].y = v17;
      this->lookAt.mat[2].z = v18;
    }
    idMat3::ToAngles(this: (idMat3 *)&v99, result: (idAngles *)&this->lookAt);
    v19 = 0;
    v20 = false;
    *(idVec3 *)&v100.mat[1].y = v99;
    v21 = 0;
    v22 = 0.0;
    v23 = 0.0;
    v24 = 0.0;
    Controller = idPresentable::GetController(this);
    *(_DWORD *)&v26[8] = byte_821B0000;
    if ( Controller != nullptr )
    {
      HIDWORD(v27) = idPresentable::GetController(this);
      if ( HIDWORD(v27) != 0 )
      {
        v28 = HIDWORD(v27) + 46312;
        v29 = HIDWORD(v27) + 46252;
        v30 = *(unsigned __int8 *)(HIDWORD(v27) + 46321) >> 7;
        LOBYTE(v31) = 0;
        if ( v30 == 0 )
          v31 = *(_DWORD *)v28;
        v19 = v31 & 1;
        LOBYTE(v31) = 0;
        if ( v30 == 0 )
          v31 = *(_DWORD *)v28;
        v20 = (v31 & 8) != 0;
        if ( (_BYTE)v19 != 0 || (v32 = 0, v20) )
          v32 = 1;
        v21 = v32;
        LODWORD(v27) = *(__int16 *)(HIDWORD(v27) + 46322) - *(__int16 *)(HIDWORD(v27) + 46262);
        *(_QWORD *)&v98.pitch = v27;
        v34 = idMath::AngleNormalize360(angle: (float)((float)v27 * (float)0.0054931641));
        v35 = v34;
        if ( v34 > 180.0 )
          v35 = (float)((float)v34 - (float)360.0);
        LODWORD(v33) = *(__int16 *)(v28 + 12) - *(__int16 *)(v29 + 12);
        *(_QWORD *)&v98.pitch = v33;
        v37 = idMath::AngleNormalize360(angle: (float)((float)v33 * (float)0.0054931641));
        v38 = v37;
        if ( v37 > 180.0 )
          v38 = (float)((float)v37 - (float)360.0);
        LODWORD(v36) = *(__int16 *)(v28 + 14) - *(__int16 *)(v29 + 14);
        *(_QWORD *)&v98.pitch = v36;
        v39 = idMath::AngleNormalize360(angle: (float)((float)v36 * (float)0.0054931641));
        if ( v39 > 180.0 )
          v39 = (float)((float)v39 - (float)360.0);
        v22 = (float)((float)v35 * s_turretTurnScale.valueFloat);
        v23 = (float)((float)v38 * s_turretTurnScale.valueFloat);
        v24 = (float)((float)v39 * s_turretTurnScale.valueFloat);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v41 = GameMs - idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        *(_DWORD *)&v26[8] = *(unsigned __int8 *)(v28 + 9);
        LOBYTE(v42) = 0;
        *(_QWORD *)v26 = *(_QWORD *)&v26[-4] & 0x80FFFFFFFFLL;
        *(_QWORD *)&v98.pitch = *(_QWORD *)&v26[-4] & 0x80FFFFFFFFLL;
        v43 = (float)*(_QWORD *)&v26[-4];
        if ( (v26[11] & 0x80) == 0 )
          v42 = *(_DWORD *)v28;
        if ( (v42 & 8) != 0 )
        {
          v46 = (float)(this->zoomTime - (float)*(__int64 *)v26);
          this->zoomTime = this->zoomTime - (float)*(__int64 *)v26;
          if ( v46 < 0.0 )
          {
            clientWeapon = this->clientWeapon;
            this->zoomTime = 0.0;
            if ( clientWeapon != nullptr )
              idWeapon::SetZoomed(this: clientWeapon, zoomed: true, fxMgr: &this->fxManager);
          }
        }
        else
        {
          v44 = this->clientWeapon;
          if ( v44 != nullptr )
            idWeapon::SetZoomed(this: v44, zoomed: false, fxMgr: &this->fxManager);
          v45 = (float)((float)v43 + this->zoomTime);
          this->zoomTime = (float)v43 + this->zoomTime;
          if ( v45 > 180.0 )
            this->zoomTime = 180.0;
        }
        if ( __fsqrts((float)((float)((float)v22 * (float)v22)
                            + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))) <= 0.0 )
        {
          *(_QWORD *)&v26[4] = __PAIR64__((unsigned int)this->turning >> 31, 3) - (unsigned int)this->turning;
          this->turning = v26[7] & 3;
        }
        else
        {
          turning = this->turning;
          if ( turning <= 3 )
            this->turning = turning + 1;
        }
      }
    }
    if ( v21 != 0 )
    {
      if ( !this->shooting )
        idPresentableWeaponStatic::PullTrigger(this);
      if ( this->windupTimer > 0.0 )
      {
        v49 = (float)-(float)((float)((float)((float)__SPAIR64__(&unk_82390000, curTime) - this->lastThinkTime)
                                    * (float)0.001)
                            - this->windupTimer);
        *(_QWORD *)&v98.pitch = __PAIR64__(&unk_82390000, curTime);
        this->windupTimer = v49;
      }
      if ( this->windupTimer <= 0.0 )
        ((void (__fastcall *)(idPresentableWeaponStatic *, int, BOOL, _DWORD, _DWORD))this->Shoot)(
          a1: this,
          a2: v19,
          a3: v20,
          a4: *(_DWORD *)&v26[4],
          a5: *(_DWORD *)&v26[8]);
    }
    else if ( this->shooting )
    {
      idPresentableWeaponStatic::ReleaseTrigger(this);
    }
    if ( this->turning != 0
      || (unsigned __int8)idMat3::Compare(this: &this->lookAt, a: &mat3_identity, epsilon: 0.000099999997) != 0 )
    {
      v50 = &v109;
      p_z = &this->origin.z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v50 += 4;
        *(float *)v50 = *p_z;
      }
      idMat3::ToAngles(this: (idMat3 *)&v100.mat[2].z, result: v110);
      v99.z = v99.z + (float)v24;
      v99.x = v99.x + (float)v22;
      v99.y = v99.y + (float)v23;
      maxYaw = this->maxYaw;
      v105.pitch = this->maxPitch;
      v105.roll = 0.0;
      v105.yaw = maxYaw;
      minPitch = this->minPitch;
      minYaw = this->minYaw;
      v56 = idMath::AngleNormalize360(angle: (float)(v99.z - v102));
      v57 = v56;
      if ( v56 > 180.0 )
        v57 = (float)((float)v56 - (float)360.0);
      v58 = idMath::AngleNormalize360(angle: (float)(v99.y - v101));
      v59 = v58;
      if ( v58 > 180.0 )
        v59 = (float)((float)v58 - (float)360.0);
      v60 = idMath::AngleNormalize360(angle: (float)(v99.x - v100.mat[2].z));
      if ( v60 > 180.0 )
        v60 = (float)((float)v60 - (float)360.0);
      v100.mat[0].x = -minPitch;
      v98.pitch = v60;
      v98.yaw = v59;
      v98.roll = v57;
      v100.mat[0].y = -minYaw;
      v100.mat[0].z = -0.0;
      idAngles::Clamp(this: &v98, min: (const idAngles *)&v100, max: &v105);
      v100.mat[1].y = v98.pitch + v100.mat[2].z;
      v100.mat[1].z = v98.yaw + v101;
      v100.mat[2].x = v98.roll + v102;
      v61 = idAngles::ToMat3(this: (idAngles *)&v108, result: (idMat3 *)&v100.mat[1].y);
      p_lookAt->mat[0].x = v61->mat[0].x;
      this->lookAt.mat[0].y = v61->mat[0].y;
      this->lookAt.mat[0].z = v61->mat[0].z;
      this->lookAt.mat[1] = v61->mat[1];
      this->lookAt.mat[2] = v61->mat[2];
      idMat3::OrthoNormalizeSelf(this: &this->lookAt);
    }
    v62 = idMat3::Inverse(this: &v108, result: &this->axis);
    idMat3::operator*(this: &v107, result: &this->lookAt, a: v62);
    idAnimator_JointMod::SetJointMod(
      this: this->jointModAnimator,
      index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
      value: &v107,
      a4: v67,
      a5: v66,
      a6: v65,
      a7: v64,
      a8: v63,
      a9: v86,
      a10: v88,
      a11: v90,
      a12: v92,
      a13: v94,
      a14: v96);
    if ( this->jointYaw.value != this->jointPitch.value )
    {
      idMat3::ToAngles(this: &v100, result: (idAngles *)&v107);
      v100.mat[0].x = 0.0;
      v68 = idAngles::ToMat3(this: (idAngles *)&v108, result: &v100);
      idAnimator_JointMod::SetJointMod(
        this: this->jointModAnimator,
        index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointYaw.value,
        value: v68,
        a4: v73,
        a5: v72,
        a6: v71,
        a7: v70,
        a8: v69,
        a9: v87,
        a10: v89,
        a11: v91,
        a12: v93,
        a13: v95,
        a14: v97);
    }
    idPresentableAnimatedEntity::UpdateAnimation(this, curTime, fraction);
    this->UpdateFX_3(this, a2: 1.0, a3: 0.0);
    if ( this->clipModelInfo.type == CLIPMODEL_CUSTOM )
    {
      idAngles::ToMat3(this: (idAngles *)&v103, result: (idMat3 *)&v100.mat[1].y);
      v75 = (float)(v104.mat[0].x * this->clipForwardAmount);
      v76 = (float)(v104.mat[0].z * this->clipForwardAmount);
      v77 = (float)(v104.mat[0].y * this->clipForwardAmount);
      *(_QWORD *)&v98.pitch = *(_QWORD *)&v103.mat[2].x;
      clipModel = this->clipModel;
      v98.roll = v103.mat[2].z;
      v100.mat[0].x = v106.x + (float)v75;
      v79 = v103.mat[2].y;
      v80 = v103.mat[2].z;
      v103.mat[2].y = v103.mat[1].y;
      v81 = v103.mat[2].x;
      v103.mat[2].x = v103.mat[1].x;
      v103.mat[2].z = v103.mat[1].z;
      v103.mat[1].z = -v103.mat[0].z;
      v103.mat[1].x = -v103.mat[0].x;
      v103.mat[1].y = -v103.mat[0].y;
      v100.mat[0].y = v106.y + (float)v77;
      v103.mat[0].x = v81;
      v103.mat[0].z = v80;
      v103.mat[0].y = v79;
      v100.mat[0].z = v106.z + (float)v76;
      idClipModel::SetLinkedPosition(this: clipModel, newOrigin: v100.mat, newAxis: &v103);
    }
    v82 = this->turning;
    if ( v82 != 0 )
    {
      if ( v82 == 1 )
        idPresentable::StartSoundShader(
          this,
          channel: SND_CHANNEL_STEERING,
          shader: this->sndTurning,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0);
      idPresentable::SetSoundVolume(
        this,
        channel: SND_CHANNEL_STEERING,
        volume: (float)((float)((float)__fsqrts((float)((float)((float)v22 * (float)v22)
                                              + (float)((float)((float)v24 * (float)v24)
                                                      + (float)((float)v23 * (float)v23))))
                      * (float)5.0)
              - (float)40.0),
        peerMask: v74,
        a5: 0);
    }
    else if ( idPresentable::IsPlayingSound(this, channel: SND_CHANNEL_STEERING) )
    {
      idPresentable::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0);
    }
    v85 = this->clientWeapon;
    if ( v85 != nullptr )
      v85->ClientUpdate(this: v85);
    LODWORD(v83) = curTime;
    *(_QWORD *)&v98.pitch = v83;
    this->lastThinkTime = (float)v83;
    idPresentableAnimatedEntity::ClientThink(this, curTime, fraction, predict: v84, a5);
  }
}


// ========================================================================
// ?Shoot@idPresentableWeaponStatic@@UAAX_N0@Z
// EA  : 0x82BB4A90
// RVA : 0x00BB4A90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::Shoot(idPresentableWeaponStatic *this, bool primary, bool secondary)
{
  idWeapon *clientWeapon; // r3
  idFinishFireResults *v7; // r11
  int i; // ctr
  idPresentablePlayer *Controller; // r19
  const idDeclProjectile *CurrentProjectileDecl; // r18
  idTreeAnimator *TreeAnimator; // r26
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  double v20; // fp5
  double v21; // fp4
  double v22; // fp3
  idPresentableWeaponStatic *v23; // r22
  idWeapon *v24; // r10
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r27
  bool v27; // r20
  int v28; // r23
  int v29; // r25
  barrelProps_t *v30; // r28
  int muzzleTagIndex; // r5
  const tagData_t *TagByIndices; // r3
  int ejectTagIndex; // r5
  const tagData_t *v34; // r3
  barrelProps_t *v35; // r28
  char v36; // r11
  int v37; // r5
  const tagData_t *v38; // r3
  int v39; // r5
  const tagData_t *v40; // r3
  int GameMs; // r29
  signed int num; // r10
  int v43; // r9
  idFXManager *v44; // [sp+8h] [-B58h]
  bool v45; // [sp+Fh] [-B51h]
  idVec3 v46; // [sp+68h] [-AF8h] BYREF
  idVec3 v47[2]; // [sp+78h] [-AE8h] BYREF
  idMat3 v48; // [sp+90h] [-AD0h] BYREF
  idMat3 v49; // [sp+C0h] [-AA0h] BYREF
  idFireParms v50; // [sp+F0h] [-A70h] BYREF
  idFinishFireResults v51; // [sp+190h] [-9D0h] BYREF
  idTestFireResults v52; // [sp+1E0h] [-980h] BYREF

  clientWeapon = this->clientWeapon;
  if ( clientWeapon != nullptr && idWeapon::IsReadyToFire(this: clientWeapon) )
  {
    idFireParms::idFireParms(this: &v50);
    memset(&v52, 0, sizeof(v52));
    v7 = &v51;
    v51.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v7 = (idFinishFireResults *)((char *)v7 + 4);
      v7->numProjectiles = 0;
    }
    Controller = idPresentable::GetController(this);
    CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: this->clientWeapon, secondaryAmmo: false);
    *((_BYTE *)&v50 + 128) |= 0x20u;
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
    if ( TreeAnimator == nullptr )
    {
      y = this->origin.y;
      z = this->origin.z;
      x = this->axis.mat[0].x;
      v15 = this->axis.mat[0].y;
      v16 = this->axis.mat[0].z;
      v17 = this->axis.mat[1].x;
      v18 = this->axis.mat[1].y;
      v19 = this->axis.mat[1].z;
      v20 = this->axis.mat[2].x;
      v21 = this->axis.mat[2].y;
      v22 = this->axis.mat[2].z;
      v46.x = this->origin.x;
      v46.y = y;
      v46.z = z;
      v48.mat[0].x = x;
      v48.mat[0].y = v15;
      v48.mat[0].z = v16;
      v48.mat[1].x = v17;
      v48.mat[1].y = v18;
      v48.mat[1].z = v19;
      v48.mat[2].x = v20;
      v48.mat[2].y = v21;
      v48.mat[2].z = v22;
    }
    v23 = this;
    if ( Controller != nullptr )
    {
      v24 = this->clientWeapon;
      *((_BYTE *)&v50 + 128) |= 0x10u;
      v50.addSpread = idPresentablePlayer::GetCurWeaponSpread(
                        this: Controller,
                        secondary: (_cntlzw(v24->weaponState - 1) & 0x20) != 0)
                    - CurrentProjectileDecl->spread;
      v23 = (idPresentableWeaponStatic *)Controller;
    }
    if ( TreeAnimator == nullptr )
      goto LABEL_35;
    decl = TreeAnimator->decl;
    if ( decl == nullptr )
      goto LABEL_35;
    p_props = &decl->props;
    if ( decl == (const idDeclMD6 *)-352 )
      goto LABEL_35;
    v27 = (_cntlzw(this->fireInOrder) & 0x20) != 0;
    if ( !this->fireInOrder )
    {
      v28 = 0;
      if ( this->barrels.num > 0 )
      {
        v29 = 0;
        do
        {
          v30 = &this->barrels.list[v29];
          muzzleTagIndex = v30->muzzleTagIndex;
          if ( muzzleTagIndex != -1 )
          {
            TagByIndices = idPropsCollection::GetTagByIndices(
                             this: p_props,
                             propIndex: this->infopropsIndex,
                             tagIndex: muzzleTagIndex);
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimator,
              tagData: TagByIndices,
              origin: &v46,
              axis: &v48);
            idWeapon::Fire(
              this: this->clientWeapon,
              attacker: v23,
              target: nullptr,
              start: &v46,
              fireAxis: &this->lookAt,
              fp: &v50,
              tfr: &v52,
              ffr: &v51,
              fxMgr: v44,
              secondaryAmmo: v45);
            ejectTagIndex = v30->ejectTagIndex;
            if ( ejectTagIndex != -1 )
            {
              v34 = idPropsCollection::GetTagByIndices(
                      this: p_props,
                      propIndex: this->infopropsIndex,
                      tagIndex: ejectTagIndex);
              idTreeAnimator::GetWorldSpaceTagTransform(this: TreeAnimator, tagData: v34, origin: v47, axis: &v49);
              idWeapon::EjectShell(
                this: this->clientWeapon,
                ejectPos: v47,
                firstPersonOffset: &vec3_origin,
                shellOrientation: &v49,
                ejectAxis: &v49,
                emitterVelocity: &vec3_origin,
                fxMgr: &this->fxManager);
            }
          }
          ++v28;
          ++v29;
        }
        while ( v28 < this->barrels.num );
      }
LABEL_32:
      if ( v27 && Controller != nullptr )
        idPresentablePlayer::WeaponFireFeedback(
          this: Controller,
          weapon: this->clientWeapon,
          projDecl: CurrentProjectileDecl);
LABEL_35:
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v50.targetList);
      return;
    }
    v35 = &this->barrels.list[this->barrelIndex];
    if ( !v35->primary )
      goto LABEL_23;
    if ( primary )
    {
LABEL_24:
      v36 = 1;
LABEL_26:
      v27 = v36;
      if ( v36 != 0 )
      {
        v37 = v35->muzzleTagIndex;
        if ( v37 != -1 )
        {
          v38 = idPropsCollection::GetTagByIndices(this: p_props, propIndex: this->infopropsIndex, tagIndex: v37);
          idTreeAnimator::GetWorldSpaceTagTransform(this: TreeAnimator, tagData: v38, origin: &v46, axis: &v48);
          idWeapon::Fire(
            this: this->clientWeapon,
            attacker: v23,
            target: nullptr,
            start: &v46,
            fireAxis: &this->lookAt,
            fp: &v50,
            tfr: &v52,
            ffr: &v51,
            fxMgr: v44,
            secondaryAmmo: v45);
          v39 = v35->ejectTagIndex;
          if ( v39 != -1 )
          {
            v40 = idPropsCollection::GetTagByIndices(this: p_props, propIndex: this->infopropsIndex, tagIndex: v39);
            idTreeAnimator::GetWorldSpaceTagTransform(this: TreeAnimator, tagData: v40, origin: v47, axis: &v49);
            idWeapon::EjectShell(
              this: this->clientWeapon,
              ejectPos: v47,
              firstPersonOffset: &vec3_origin,
              shellOrientation: &v49,
              ejectAxis: &v49,
              emitterVelocity: &vec3_origin,
              fxMgr: &this->fxManager);
          }
        }
      }
      else
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->clientWeapon->nextFireTime = idWeapon::GetFiringInterval(this: this->clientWeapon, secondaryAmmo: false)
                                         + GameMs;
      }
      num = this->barrels.num;
      v43 = this->barrelIndex + 1;
      __twllei(num, 0);
      this->barrelIndex = v43 % num;
      __twlgei(num & ~(__ROL4__(v43, 1) - 1), 0xFFFFFFFF);
      goto LABEL_32;
    }
    if ( !v35->primary )
    {
LABEL_23:
      if ( secondary )
        goto LABEL_24;
    }
    v36 = 0;
    goto LABEL_26;
  }
}


// ========================================================================
// __unwind$490389_1
// EA  : 0x82BB4EE0
// RVA : 0x00BB4EE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void _unwind_490389_1()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2912 + 240));
}


// ========================================================================
// ?SetDefaults@idPresentableWeaponStatic@@AAAXXZ
// EA  : 0x82BB4F98
// RVA : 0x00BB4F98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void __fastcall idPresentableWeaponStatic::SetDefaults(idPresentableWeaponStatic *this)
{
  int num; // r8
  barrelProps_t *v2; // r31

  this->overheating = false;
  this->maxHeat = 100;
  this->curHeat = 0.0;
  this->fireInOrder = false;
  this->lookAt = mat3_identity;
  this->turning = 0;
  num = this->barrels.num;
  this->weaponDecl = nullptr;
  this->sndTurning = nullptr;
  this->zoomTime = 180.0;
  this->sndFireLoop = nullptr;
  this->windupTime = 0.5;
  this->sndFireStop = nullptr;
  this->windupTimer = 0.0;
  this->sndOverheat = nullptr;
  this->clipForwardAmount = 22.0;
  this->lastThinkTime = 0.0;
  this->shooting = false;
  this->barrelIndex = 0;
  this->clientWeapon = nullptr;
  this->infopropsIndex = -1;
  if ( num <= 0 )
  {
    v2 = idList<barrelProps_t,5>::Alloc(this: &this->barrels);
    idAtomicString::Set(this: &v2->muzzleTag, str_: "muzzle");
    idAtomicString::Set(this: &v2->ejectTag, str_: &byte_8200D768);
    v2->primary = true;
  }
}


// ========================================================================
// ??0idPresentableWeaponStatic@@QAA@PAVidProp_WeaponStatic@@PAVidRenderModel@@PAVidAnimStack@@PAVidAnimator_JointMod@@HPBVidDeclFX@@_N@Z
// EA  : 0x82BB50D0
// RVA : 0x00BB50D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

idPresentableWeaponStatic *__fastcall idPresentableWeaponStatic::idPresentableWeaponStatic(
        idPresentableWeaponStatic *this,
        idProp_WeaponStatic *ent,
        idRenderModel *renderModel_,
        idAnimStack *animStack_,
        idAnimator_JointMod *animJointMod_,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_)
{
  idTreeAnimator *TreeAnimator; // r3
  idPropsCollection *decl; // r11
  bool v13; // [sp+Bh] [-85h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]
  int v19; // [sp+20h] [-70h]
  int v20; // [sp+24h] [-6Ch]
  int v21; // [sp+28h] [-68h]
  int v22; // [sp+2Ch] [-64h]
  int v23; // [sp+30h] [-60h]
  int v24; // [sp+34h] [-5Ch]
  int v25; // [sp+38h] [-58h]
  int v26; // [sp+3Ch] [-54h]
  int v27; // [sp+40h] [-50h]
  int v28; // [sp+44h] [-4Ch]
  int v29; // [sp+48h] [-48h]
  int v30; // [sp+4Ch] [-44h]
  int v31; // [sp+50h] [-40h]

  idPresentableProp::idPresentableProp(
    this,
    e: ent,
    renderModel_,
    animStack_,
    entityNumber_,
    fxDecl_,
    useSphereModel_,
    inventoryDecl_: nullptr,
    isUsable_: v13,
    a10: v14,
    a11: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: false);
  this->__vftable = (idPresentableWeaponStatic_vtbl *)&idPresentableWeaponStatic::`vftable';
  this->jointYaw.value = -1;
  this->jointPitch.value = -1;
  this->barrels.list = nullptr;
  this->barrels.granularity = 0;
  this->barrels.memTag = 5;
  this->barrels.listStatic = 0;
  this->barrels.size = 0;
  this->barrels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->barrels);
  idPresentableWeaponStatic::SetDefaults(this);
  this->jointModAnimator = animJointMod_;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
  if ( TreeAnimator != nullptr )
  {
    decl = (idPropsCollection *)TreeAnimator->decl;
    if ( decl != nullptr && decl != (idPropsCollection *)-352 )
      this->infopropsIndex = idPropsCollection::FindPropIndex(this: decl + 22, propName: idPropInfo::INFO_PROP_NAME);
  }
  return this;
}


// ========================================================================
// __unwind$490646
// EA  : 0x82BB51B0
// RVA : 0x00BB51B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void _unwind_490646()
{
  int v0; // r12

  idPresentableProp::~idPresentableProp(this: *(idPresentableProp **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$490647
// EA  : 0x82BB51D8
// RVA : 0x00BB51D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweaponstatic.cpp
// ========================================================================

void _unwind_490647()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1400));
}

