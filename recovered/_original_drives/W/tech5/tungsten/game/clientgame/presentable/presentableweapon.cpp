
// ========================================================================
// ?WeaponDeleted@idPresentableWeapon@@QAAXXZ
// EA  : 0x82BB1C58
// RVA : 0x00BB1C58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::WeaponDeleted(idPresentableWeapon *this)
{
  this->clientWeapon = nullptr;
}


// ========================================================================
// ?Shutdown@idPresentableWeapon@@UAAXXZ
// EA  : 0x82BB1C68
// RVA : 0x00BB1C68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableWeapon::Shutdown(idPresentableWeapon *this)
{
  idPresentable::Shutdown(this);
}


// ========================================================================
// ?Present@idPresentableWeapon@@UAAXXZ
// EA  : 0x82BB1C70
// RVA : 0x00BB1C70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableWeapon::Present(idPresentablePlayer *this)
{
  idPresentableAnimatedEntity::Present(this);
}


// ========================================================================
// ?GetMuzzleFlashWorldTransform@idPresentableWeapon@@QAA_NAAVidVec3@@AAVidMat3@@W4attack_t@idWeapon@@@Z
// EA  : 0x82BB1C78
// RVA : 0x00BB1C78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

BOOL __fastcall idPresentableWeapon::GetMuzzleFlashWorldTransform(
        idPresentableWeapon *this,
        idVec3 *origin,
        idMat3 *axis,
        idWeapon::attack_t attackType)
{
  const idTreeAnimator *TreeAnimator; // r3

  if ( this->clientWeapon == nullptr || idPresentableAnimatedEntity::GetTreeAnimator(this) == nullptr )
    return false;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
  return idWeapon::GetMuzzleFlashWorldTransform(this: this->clientWeapon, ta: TreeAnimator, attackType, origin, axis);
}


// ========================================================================
// ??0idPresentableWeapon@@QAA@PAVidRenderModel@@PBVidDeclWeapon@@HPAVidAnimStack@@PAVidAnimatedEntity@@_N@Z
// EA  : 0x82BB1CF8
// RVA : 0x00BB1CF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

idPresentableWeapon *__fastcall idPresentableWeapon::idPresentableWeapon(
        idPresentableWeapon *this,
        idTreeAnimator *renderModel_,
        const idDeclWeapon *weaponDecl_,
        int ownerEntityNum_,
        idAnimStack *animStack_,
        idAnimatedEntity *ent_,
        bool useSphereModel_)
{
  int entityNumber; // r7
  const idDeclWeapon *weaponDecl; // r11
  bool laserDotQuad; // r26
  double fadeOut; // fp31
  const idMaterial *laserDotMtr; // r25
  double fadeIn; // fp30
  const idMaterial *laserBeamMtr; // r24
  double laserDotDepth; // fp29
  double laserDotSize; // fp28
  double laserBeamHeight; // fp27
  idRenderModelDecal *Flags; // r29
  idRenderModelBeam *NumContacts; // r3
  int v23; // r10
  int v24; // r9
  const idMaterial *v25; // r7
  idIndex<short,enum invalidJointIndex_t> *TreeAnimator; // r3
  int v27; // r10
  const idIndex<short,enum invalidJointIndex_t> *v28; // r27
  idTreeAnimator *v29; // r3
  int v31; // [sp+8h] [-E8h]
  int v32; // [sp+Ch] [-E4h]
  int v33; // [sp+10h] [-E0h]
  int v34; // [sp+14h] [-DCh]
  int v35; // [sp+18h] [-D8h]
  int v36; // [sp+1Ch] [-D4h]
  int v37; // [sp+20h] [-D0h]
  int v38; // [sp+24h] [-CCh]
  int v39; // [sp+28h] [-C8h]
  int v40; // [sp+2Ch] [-C4h]
  int v41; // [sp+30h] [-C0h]
  int v42; // [sp+34h] [-BCh]
  int v43; // [sp+38h] [-B8h]
  int v44; // [sp+3Ch] [-B4h]
  int v45; // [sp+40h] [-B0h]
  int v46; // [sp+44h] [-ACh]
  int v47; // [sp+48h] [-A8h]
  int v48; // [sp+4Ch] [-A4h]
  int v49; // [sp+50h] [-A0h]
  int v50; // [sp+54h] [-9Ch]
  int v51; // [sp+58h] [-98h]
  int v52; // [sp+5Ch] [-94h]
  int v53; // [sp+60h] [-90h]
  idIndex<short,enum invalidJointIndex_t> *p_rollJointIndex; // [sp+70h] [-80h] BYREF

  if ( ent_ != nullptr )
    entityNumber = ent_->entityNumber;
  else
    entityNumber = 0x1FFF;
  idPresentableAnimatedEntity::idPresentableAnimatedEntity(
    this,
    ent: ent_,
    renderModel_,
    animStack_,
    entityNumber_: entityNumber,
    fxDecl_: weaponDecl_->weaponFX,
    useSphereModel_);
  this->__vftable = (idPresentableWeapon_vtbl *)&idPresentableWeapon::`vftable';
  this->attacker.spawnId = 0;
  this->vehicleAttacker.spawnId = 0;
  this->soundInfo.emitter = nullptr;
  this->soundInfo.channel = SND_CHANNEL_ANY;
  idLaserSight::idLaserSight(this: &this->laserSight);
  this->hitPresentable.spawnId = 0;
  this->hitJoint.value = -1;
  this->rollJointIndex.value = -1;
  this->presentableWeaponID = -1;
  this->lastWeaponID = -1;
  this->rollDelta = 0.0;
  this->weaponDecl = weaponDecl_;
  this->rollAngle = 0.0;
  this->clientWeapon = nullptr;
  this->soundInfo.emitter = nullptr;
  this->soundInfo.channel = SND_CHANNEL_ANY;
  this->netFireIndex = 0;
  this->netFireIndexLastSerialize = 0;
  this->ammoDecl = nullptr;
  this->expectedHit = nullptr;
  this->lastFireTime = 0;
  this->presentableWeaponID = idPresentableWeapon::presentableWeaponCounter++;
  p_rollJointIndex = &this->rollJointIndex;
  weaponDecl = this->weaponDecl;
  p_rollJointIndex = &this->hitJoint;
  this->ownerEntityNum = ownerEntityNum_;
  if ( weaponDecl != nullptr )
  {
    laserDotQuad = weaponDecl->laserSightInfo.laserDotQuad;
    fadeOut = weaponDecl->laserSightInfo.fadeOut;
    laserDotMtr = weaponDecl->laserSightInfo.laserDotMtr;
    fadeIn = weaponDecl->laserSightInfo.fadeIn;
    laserBeamMtr = weaponDecl->laserSightInfo.laserBeamMtr;
    laserDotDepth = weaponDecl->laserSightInfo.laserDotDepth;
    laserDotSize = weaponDecl->laserSightInfo.laserDotSize;
    laserBeamHeight = weaponDecl->laserSightInfo.laserBeamHeight;
    Flags = idParser::GetFlags(this: clientGame);
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idLaserSight::Init(
      this: &this->laserSight,
      _beamEffects: NumContacts,
      _decalEffects: Flags,
      laserBeamMtr,
      laserBeamHeight,
      laserPointMtr: v25,
      laserPointSize: laserDotSize,
      laserPointDepth: laserDotDepth,
      fadeIn,
      fadeOut,
      isQuad: laserDotMtr,
      a12: v24,
      a13: v23,
      a14: v31,
      a15: v32,
      a16: v33,
      a17: v34,
      a18: v35,
      a19: v36,
      a20: v37,
      a21: v38,
      a22: v39,
      a23: v40,
      a24: v41,
      a25: v42,
      a26: v43,
      a27: v44,
      a28: v45,
      a29: v46,
      a30: v47,
      a31: v48,
      a32: v49,
      a33: v50,
      a34: v51,
      a35: v52,
      a36: v53,
      a37: laserDotQuad);
    if ( !this->weaponDecl->hasLaserUpgrade )
      idLaserSight::Hide(this: &this->laserSight);
    if ( this->weaponDecl->thirdPersonRotateBarrel && idPresentableAnimatedEntity::GetTreeAnimator(this) != nullptr )
    {
      TreeAnimator = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this);
      v27 = HIWORD(idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)&p_rollJointIndex,
                     result: TreeAnimator,
                     jointName: "barrel")->__vftable);
      this->rollJointIndex.value = v27;
      if ( v27 != 0xFFFF )
      {
        v28 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v27;
        v29 = idPresentableAnimatedEntity::GetTreeAnimator(this);
        idTreeAnimator::GetModelSpaceJointTransform(
          this: v29,
          pose: DRIVER_MODEL,
          jointIndex: v28,
          origin: &this->spinJointOrigin,
          axis: &this->spinJointMat);
      }
    }
  }
  return this;
}


// ========================================================================
// __unwind$488772_0
// EA  : 0x82BB1F2C
// RVA : 0x00BB1F2C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void _unwind_488772_0()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 240 + 260));
}


// ========================================================================
// __unwind$488773
// EA  : 0x82BB1F54
// RVA : 0x00BB1F54
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void _unwind_488773()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 240 + 260) + 1292));
}


// ========================================================================
// ??1idPresentableWeapon@@UAA@XZ
// EA  : 0x82BB1F88
// RVA : 0x00BB1F88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::~idPresentableWeapon(idPresentableWeapon *this)
{
  idWeapon *clientWeapon; // r11
  idWeapon *v3; // r3
  idWeapon *v4; // r3

  this->__vftable = (idPresentableWeapon_vtbl *)&idPresentableWeapon::`vftable';
  if ( common->IsClient(this: common) )
  {
    clientWeapon = this->clientWeapon;
    if ( clientWeapon != nullptr )
    {
      if ( presentableWeapon_debug.valueInteger != 0 )
        idLib::Printf(fmt: "Deleting clientWeapon %s\n", clientWeapon->decl->name.str);
      idWeapon::SetPresentableWeapon(this: this->clientWeapon, presentableWeapon_: nullptr);
      v3 = this->clientWeapon;
      if ( v3 != nullptr )
        ((void (__fastcall *)(idWeapon *, int))v3->dtr_idClass)(a1: v3, a2: 1);
      this->clientWeapon = nullptr;
    }
  }
  v4 = this->clientWeapon;
  if ( v4 != nullptr )
    idWeapon::SetPresentableWeapon(this: v4, presentableWeapon_: nullptr);
  idLaserSight::Shutdown(this: &this->laserSight);
  idLaserSight::~idLaserSight(this: &this->laserSight);
  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this);
}


// ========================================================================
// __unwind$488840
// EA  : 0x82BB2070
// RVA : 0x00BB2070
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void _unwind_488840()
{
  int v0; // r12

  idPresentableAnimatedEntity::~idPresentableAnimatedEntity(this: *(idPresentableAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488841
// EA  : 0x82BB2098
// RVA : 0x00BB2098
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void _unwind_488841()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 112 + 132) + 1292));
}


// ========================================================================
// ?InitClientWeapon@idPresentableWeapon@@AAAXXZ
// EA  : 0x82BB20C8
// RVA : 0x00BB20C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::InitClientWeapon(idPresentableWeapon *this)
{
  idWeapon *clientWeapon; // r11
  __int64 v3; // r9
  const idDeclFX *weaponFX; // r28
  unsigned int v5; // r5
  double v6; // fp31
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v8; // r8
  int GameMs; // r3
  const idDeclInventory *decl; // r31
  double v11; // fp31
  char list_high; // r27
  double v13; // fp30
  const idMaterial *handsModelMD6Alt; // r26
  double v15; // fp29
  const idMaterial *handsModelMD6; // r25
  double v17; // fp28
  double v18; // fp27
  idRenderModelDecal *Flags; // r29
  idRenderModelBeam *NumContacts; // r3
  int v21; // r10
  int v22; // r9
  const idMaterial *v23; // r7
  idIndex<short,enum invalidJointIndex_t> *v24; // r3
  int v25; // r10
  const idIndex<short,enum invalidJointIndex_t> *v26; // r29
  idTreeAnimator *v27; // r3
  int v28; // [sp+8h] [-E8h]
  int v29; // [sp+Ch] [-E4h]
  int v30; // [sp+10h] [-E0h]
  int v31; // [sp+14h] [-DCh]
  int v32; // [sp+18h] [-D8h]
  int v33; // [sp+1Ch] [-D4h]
  int v34; // [sp+20h] [-D0h]
  int v35; // [sp+24h] [-CCh]
  int v36; // [sp+28h] [-C8h]
  int v37; // [sp+2Ch] [-C4h]
  int v38; // [sp+30h] [-C0h]
  int v39; // [sp+34h] [-BCh]
  int v40; // [sp+38h] [-B8h]
  int v41; // [sp+3Ch] [-B4h]
  int v42; // [sp+40h] [-B0h]
  int v43; // [sp+44h] [-ACh]
  int v44; // [sp+48h] [-A8h]
  int v45; // [sp+4Ch] [-A4h]
  int v46; // [sp+50h] [-A0h]
  int v47; // [sp+54h] [-9Ch]
  int v48; // [sp+58h] [-98h]
  int v49; // [sp+5Ch] [-94h]
  int v50; // [sp+60h] [-90h]
  char v51; // [sp+70h] [-80h] BYREF
  __int64 v52; // [sp+78h] [-78h]

  clientWeapon = this->clientWeapon;
  if ( clientWeapon != nullptr )
  {
    HIDWORD(v3) = &unk_822C0000;
    weaponFX = clientWeapon->decl->weaponFX;
    v5 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v5 + 1013904223;
    LODWORD(v3) = ((v5 + 1013904223) >> 10) & 0x7FFF;
    v52 = v3;
    v6 = (float)((float)v3 * (float)0.000030518509);
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
    idFXManager::Init(
      this: &this->fxManager,
      declFX: weaponFX,
      _rw: clientGame->renderWorld,
      _soundInfo: &this->soundInfo,
      _gameLibEffects: &clientGame->gameLibEffects,
      diversity: v6,
      _ta: v8,
      a8: TreeAnimator);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StartFX(
      this: &this->fxManager,
      org: &vec3_origin,
      axis: &mat3_identity,
      time: GameMs,
      startCondition: 0);
    decl = this->clientWeapon->decl;
    if ( decl != nullptr )
    {
      v11 = *(float *)&decl[3].childItem.size;
      list_high = HIBYTE(decl[3].childItem.list);
      v13 = *(float *)&decl[3].childItem.num;
      handsModelMD6Alt = (const idMaterial *)decl[3].handsModelMD6Alt;
      v15 = *(float *)&decl[3].thirdPersonStatic;
      handsModelMD6 = (const idMaterial *)decl[3].handsModelMD6;
      v17 = *(float *)&decl[3].dualWieldItemDecl;
      v18 = *(float *)&decl[3].thirdPersonMD6;
      Flags = idParser::GetFlags(this: clientGame);
      NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
      idLaserSight::Init(
        this: &this->laserSight,
        _beamEffects: NumContacts,
        _decalEffects: Flags,
        laserBeamMtr: handsModelMD6,
        laserBeamHeight: v18,
        laserPointMtr: v23,
        laserPointSize: v17,
        laserPointDepth: v15,
        fadeIn: v13,
        fadeOut: v11,
        isQuad: handsModelMD6Alt,
        a12: v22,
        a13: v21,
        a14: v28,
        a15: v29,
        a16: v30,
        a17: v31,
        a18: v32,
        a19: v33,
        a20: v34,
        a21: v35,
        a22: v36,
        a23: v37,
        a24: v38,
        a25: v39,
        a26: v40,
        a27: v41,
        a28: v42,
        a29: v43,
        a30: v44,
        a31: v45,
        a32: v46,
        a33: v47,
        a34: v48,
        a35: v49,
        a36: v50,
        a37: list_high);
      if ( !decl[3].hasBeenParsedAtLeastOnce )
        idLaserSight::Hide(this: &this->laserSight);
      if ( this->weaponDecl->thirdPersonRotateBarrel && idPresentableAnimatedEntity::GetTreeAnimator(this) != nullptr )
      {
        v24 = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this);
        v25 = HIWORD(idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v51, result: v24, jointName: "barrel")->__vftable);
        this->rollJointIndex.value = v25;
        if ( v25 != 0xFFFF )
        {
          v26 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v25;
          v27 = idPresentableAnimatedEntity::GetTreeAnimator(this);
          idTreeAnimator::GetModelSpaceJointTransform(
            this: v27,
            pose: DRIVER_MODEL,
            jointIndex: v26,
            origin: &this->spinJointOrigin,
            axis: &this->spinJointMat);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "InitClientWeapon() clientWeapon is NULL");
  }
}


// ========================================================================
// ?ShowLaserSight@idPresentableWeapon@@QAAXXZ
// EA  : 0x82BB22D0
// RVA : 0x00BB22D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::ShowLaserSight(idPresentableWeapon *this)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idLaserSight::Show(this: &this->laserSight, startTime: GameMs);
}


// ========================================================================
// ?UpdateOwnerAndAttacker@idPresentableWeapon@@AAAXXZ
// EA  : 0x82BB2380
// RVA : 0x00BB2380
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::UpdateOwnerAndAttacker(idPresentableWeapon *this)
{
  int ownerEntityNum; // r4
  idPresentable *PresentableByEntityNum; // r3
  unsigned int *v4; // r31
  int v5; // r3
  idPresentableVehicle *v6; // r3
  idPresentable *Driver; // r3

  ownerEntityNum = this->ownerEntityNum;
  if ( ownerEntityNum >= 0 && ownerEntityNum != 0x1FFF )
  {
    PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: ownerEntityNum);
    v4 = (unsigned int *)PresentableByEntityNum;
    if ( PresentableByEntityNum == nullptr )
    {
      this->vehicleAttacker.spawnId = 0;
LABEL_5:
      this->attacker.spawnId = 0;
      return;
    }
    if ( PresentableByEntityNum->GetVehicleInterface(this: PresentableByEntityNum) != nullptr )
    {
      v5 = (*(int (__fastcall **)(unsigned int *))(*v4 + 76))(a1: v4);
      if ( v5 != 0 )
        this->vehicleAttacker.spawnId = *(_DWORD *)(v5 + 1100);
      else
        this->vehicleAttacker.spawnId = 0;
      v6 = (idPresentableVehicle *)(*(int (__fastcall **)(unsigned int *))(*v4 + 76))(a1: v4);
      Driver = idPresentableVehicle::GetDriver(this: v6);
      if ( Driver == nullptr )
        goto LABEL_5;
      this->attacker.spawnId = Driver->spawnId;
    }
    else
    {
      this->vehicleAttacker.spawnId = 0;
      this->attacker.spawnId = v4[275];
    }
  }
}


// ========================================================================
// ?UpdateLaserSight@idPresentableWeapon@@QAAXABVidVec3@@0H@Z
// EA  : 0x82BB2468
// RVA : 0x00BB2468
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::UpdateLaserSight(
        idPresentableWeapon *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        int passEntityNumber)
{
  const idDeclWeapon *weaponDecl; // r10
  double v8; // fp12
  double v9; // fp6
  double v10; // fp31
  const idMat3 *v11; // r3
  trace_t v12; // [sp+50h] [-D0h] BYREF
  idVec3 v13[3]; // [sp+D0h] [-50h] BYREF

  idClip::TracePoint(
    this: &clientGame->clip,
    result: &v12,
    start: startPos,
    end: endPos,
    clipMask: 8462469,
    passEntityNumber);
  weaponDecl = this->weaponDecl;
  v8 = (float)(endPos->y - startPos->y);
  v9 = (float)(endPos->z - startPos->z);
  v10 = (float)((float)((float)((float)((float)((float)((float)v9 * (float)v9)
                                              + (float)((float)((float)(endPos->x - startPos->x)
                                                              * (float)(endPos->x - startPos->x))
                                                      + (float)((float)v8 * (float)v8)))
                                      * v12.fraction)
                              / (float)(weaponDecl->maxRange * weaponDecl->maxRange))
                      * (float)(weaponDecl->laserSightInfo.laserDotMaxSizeScale
                              - weaponDecl->laserSightInfo.laserDotMinSizeScale))
              + weaponDecl->laserSightInfo.laserDotMinSizeScale);
  v11 = idVec3::ToZAxis(this: v13, result: (idMat3 *)&v12.c.normal);
  idLaserSight::Update(this: &this->laserSight, startPos, endPos: &v12.endpos, axis: v11, sizeScale: v10, fade: 1.0);
}


// ========================================================================
// ?GetLaserSightWorldTransform@idPresentableWeapon@@QBA_NPBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BB2540
// RVA : 0x00BB2540
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

int __fastcall idPresentableWeapon::GetLaserSightWorldTransform(
        idPresentableWeapon *this,
        idTreeAnimator *parentModel,
        idVec3 *origin,
        idMat3 *axis)
{
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r30
  const tagData_t *Tag; // r3
  const tagData_t *v10; // r3
  tagData_t v12; // [sp+50h] [-50h] BYREF

  if ( parentModel != nullptr )
  {
    decl = parentModel->decl;
    v12.parentJoint.value = -1;
    v12.trans.x = 0.0;
    v12.trans.y = 0.0;
    v12.trans.z = 0.0;
    v12.rot.x = 0.0;
    v12.rot.y = 0.0;
    v12.rot.z = 0.0;
    v12.rot.w = 0.0;
    if ( decl == nullptr )
      goto LABEL_6;
    p_props = &decl->props;
    if ( decl == (const idDeclMD6 *)-352 )
      goto LABEL_6;
    Tag = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: "laser_pos");
    v12.trans.x = Tag->trans.x;
    v12.trans.y = Tag->trans.y;
    v12.trans.z = Tag->trans.z;
    v12.rot.x = Tag->rot.x;
    v12.rot.y = Tag->rot.y;
    v12.rot.z = Tag->rot.z;
    v12.rot.w = Tag->rot.w;
    v12.parentJoint.value = Tag->parentJoint.value;
    if ( v12.parentJoint.value != 0xFFFF )
      goto LABEL_6;
    v10 = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: "muzzle");
    v12.trans.x = v10->trans.x;
    v12.trans.y = v10->trans.y;
    v12.trans.z = v10->trans.z;
    v12.rot.x = v10->rot.x;
    v12.rot.y = v10->rot.y;
    v12.rot.z = v10->rot.z;
    v12.rot.w = v10->rot.w;
    v12.parentJoint.value = v10->parentJoint.value;
    if ( v12.parentJoint.value != 0xFFFF )
    {
LABEL_6:
      if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(this: parentModel, tagData: &v12, origin, axis) != 0 )
        return 1;
      *origin = vec3_origin;
      *axis = mat3_identity;
    }
  }
  return 0;
}


// ========================================================================
// ?UpdateFX@idPresentableWeapon@@UAAXABVidVec3@@ABVidMat3@@AAVidFXManager@@MM@Z
// EA  : 0x82BB2708
// RVA : 0x00BB2708
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::UpdateFX(
        idPresentableWeapon *this,
        const idVec3 *origin,
        const idMat3 *axis,
        idFXManager *fxManager,
        double fovScale,
        double depthHack)
{
  idTreeAnimator *TreeAnimator; // r28
  int GameMs; // r3
  double valueFloat; // fp0
  double rollDelta; // fp13
  double rollAngle; // fp13
  double v12; // fp0
  const idMat3 *v13; // r3
  char *v14; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  unsigned int v17; // r29
  int GameMsPerFrame; // r27
  int PreviousGameMs; // r26
  int v20; // r3
  int v21; // r3
  float *v22; // [sp+8h] [-128h]
  float *v23; // [sp+Ch] [-124h]
  float *v24; // [sp+10h] [-120h]
  int v25; // [sp+14h] [-11Ch]
  int v26; // [sp+18h] [-118h]
  int v27; // [sp+1Ch] [-114h]
  int v28; // [sp+20h] [-110h]
  int v29; // [sp+24h] [-10Ch]
  int v30; // [sp+28h] [-108h]
  int v31; // [sp+2Ch] [-104h]
  int v32; // [sp+30h] [-100h]
  int v33; // [sp+34h] [-FCh]
  int v34; // [sp+38h] [-F8h]
  int v35; // [sp+3Ch] [-F4h]
  int v36; // [sp+40h] [-F0h]
  int v37; // [sp+44h] [-ECh]
  int v38; // [sp+48h] [-E8h]
  int v39; // [sp+4Ch] [-E4h]
  int v40; // [sp+50h] [-E0h]
  int v41; // [sp+58h] [-D8h]
  int v42; // [sp+60h] [-D0h]
  char v43; // [sp+6Ch] [-C4h] BYREF
  idMat3 v44; // [sp+70h] [-C0h] BYREF
  idRotation v45[2]; // [sp+A0h] [-90h] BYREF

  idPresentable::UpdateFX(this, origin, axis, fxManager, fovScale, depthHack);
  if ( (unsigned __int16)this->rollJointIndex.value < 0x8000u )
  {
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
    idPresentable::UpdateModelTransform(this);
    if ( TreeAnimator != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      valueFloat = 0.0;
      if ( GameMs - this->lastFireTime >= presentableWeapon_roll_endTime.valueInteger )
      {
        if ( this->rollDelta > 0.0 )
          this->rollDelta = this->rollDelta - presentableWeapon_roll_endAccel.valueFloat;
      }
      else
      {
        this->rollDelta = presentableWeapon_roll_startAccel.valueFloat + this->rollDelta;
      }
      rollDelta = this->rollDelta;
      if ( rollDelta >= 0.0 )
      {
        valueFloat = presentableWeapon_roll_topSpeed.valueFloat;
        if ( rollDelta <= presentableWeapon_roll_topSpeed.valueFloat )
          valueFloat = this->rollDelta;
      }
      rollAngle = this->rollAngle;
      this->rollDelta = valueFloat;
      v12 = (float)((float)rollAngle + (float)valueFloat);
      this->rollAngle = v12;
      if ( v12 >= 180.0 )
        this->rollAngle = (float)v12 - (float)360.0;
      idRotation::idRotation(
        this: v45,
        rotationOrigin: &vec3_origin,
        rotationVec: this->spinJointMat.mat,
        rotationAngle: -this->rollAngle);
      v13 = idRotation::ToMat3(this: v45);
      v14 = &v43;
      p_z = (_DWORD *)&v13[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v14 += 4;
        *(_DWORD *)v14 = *p_z;
      }
      idTreeAnimator::SetJointAxis(
        this: TreeAnimator,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->rollJointIndex.value,
        type: JOINTMOD_LOCAL,
        axis: &v44);
      v17 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idTreeAnimator::BlendTreeInternal(
        this: TreeAnimator,
        currentTime: v20,
        previousTime: PreviousGameMs,
        gameMsPerFrame: GameMsPerFrame,
        ticksPerSec: v17,
        tree: nullptr,
        parallelJobList: gameLocal->parallelJobList,
        localR: nullptr,
        localS: v22,
        localT: v23,
        localU: v24,
        a12: v25,
        a13: v26,
        a14: v27,
        a15: v28,
        a16: v29,
        a17: v30,
        a18: v31,
        a19: v32,
        a20: v33,
        a21: v34,
        a22: v35,
        a23: v36,
        a24: v37,
        a25: v38,
        a26: v39,
        a27: v40,
        a28: nullptr,
        a29: v41,
        a30: nullptr,
        a31: v42,
        a32: nullptr);
      v21 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idTreeAnimator::UpdateTime(this: TreeAnimator, time: v21);
    }
  }
}


// ========================================================================
// ?PostSerializeRead@idPresentableWeapon@@UAAX_N@Z
// EA  : 0x82BB2920
// RVA : 0x00BB2920
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::PostSerializeRead(idPresentableWeapon *this, bool firstClientFrame)
{
  const idDeclWeapon *weaponDecl; // r3
  idInventoryItem *v4; // r3
  idWeapon *v5; // r3
  const idDeclWeapon *v6; // r10
  idWeapon *clientWeapon; // r11
  const char *v9; // r4
  const char *str; // r5
  idWeapon *v11; // r11
  const idDeclAmmo *ammoDecl; // r4
  idWeapon *v13; // r3

  idPresentableAnimatedEntity::PostSerializeRead(this, firstClientFrame);
  idPresentableWeapon::UpdateOwnerAndAttacker(this);
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
    {
      idLib::Warning(fmt: "Unable to create clientWeapon from serialized decl %s", this->weaponDecl->name.str);
      return;
    }
    if ( presentableWeapon_debug.valueInteger != 0 )
      idLib::Printf(fmt: "Created PresentableWeapon: %s \n", this->weaponDecl->name.str);
    idPresentableWeapon::InitClientWeapon(this);
  }
  v6 = this->weaponDecl;
  if ( v6 != nullptr )
  {
    clientWeapon = this->clientWeapon;
    if ( clientWeapon == nullptr || v6 != clientWeapon->decl )
    {
      v9 = "NULL";
      if ( v6 != nullptr )
        str = v6->name.str;
      else
        str = "NULL";
      v11 = this->clientWeapon;
      if ( v11 != nullptr )
        v9 = v11->decl->name.str;
      idLib::Printf(fmt: "Mismatched PresentableWeapon: weapon: %s decl: %s \n", v9, str);
    }
  }
  ammoDecl = this->ammoDecl;
  if ( ammoDecl != nullptr )
  {
    v13 = this->clientWeapon;
    if ( ammoDecl != v13->ammoClip->decl )
      idWeapon::ForceReplaceAmmo(this: v13, newAmmoDecl: ammoDecl, secondaryAmmo: false);
  }
}


// ========================================================================
// ?RecordFireEvent@idPresentableWeapon@@QAAXABVidFireParms@@ABVidTestFireResults@@AAVidFinishFireResults@@H@Z
// EA  : 0x82BB2A90
// RVA : 0x00BB2A90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::RecordFireEvent(
        idPresentableWeapon *this,
        const idFireParms *fp,
        const idTestFireResults *tfr,
        idFinishFireResults *ffr,
        int loadedCount)
{
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r31
  int *p_entityNum; // r29
  idPresentable *PresentableByEntityNum; // r3
  unsigned int spawnId; // r11
  int v16; // r31
  idPresentable *PresentableByIndex; // r3
  idPresentable *expectedHit; // r11
  int index; // r5
  idPresentable *v20; // r11
  int netFireIndex; // r11
  idWeapon *Weapon; // r3
  const idDeclAmmo *decl; // r11
  unsigned int v24; // r11
  int v25; // r31
  idPresentable *v26; // r3
  unsigned int v27; // r11
  unsigned int v28; // r31
  idPresentable *v29; // r3
  unsigned int v30; // r10
  int v31; // r31
  unsigned int v32; // r11
  int v33; // r31
  idPresentable *v34; // r3
  unsigned int v35; // r11
  unsigned int v36; // r31
  idPresentable *v37; // r3
  int v38; // r11
  contactInfo_t *p_c; // r10
  char *v40; // r11
  int v41; // r11
  int v42; // [sp+8h] [-88h]
  int v43; // [sp+Ch] [-84h]
  int v44; // [sp+10h] [-80h]
  int v45; // [sp+14h] [-7Ch]
  int v46; // [sp+18h] [-78h]
  idPresentable *v47; // [sp+1Ch] [-74h]

  v10 = common->IsServer(this: common);
  if ( v10 != 0 )
  {
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5: v11,
      a6: v10,
      a7: v9,
      a8: v8,
      a9: v42,
      a10: v43,
      a11: v44,
      a12: v45,
      a13: v46,
      a14: v47);
    this->hitPresentable.spawnId = 0;
    v12 = 0;
    if ( tfr->numTraces > 0 )
    {
      p_entityNum = &tfr->traces[0].c.entityNum;
      do
      {
        if ( *p_entityNum != 0x1FFF )
        {
          PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: *p_entityNum);
          if ( PresentableByEntityNum != nullptr )
            this->hitPresentable.spawnId = PresentableByEntityNum->spawnId;
        }
        ++v12;
        p_entityNum += 32;
      }
      while ( v12 < tfr->numTraces );
    }
    if ( this->expectedHit != nullptr )
    {
      if ( presentableWeapon_debug.valueInteger != 0 )
      {
        spawnId = this->hitPresentable.spawnId;
        v16 = spawnId & 0x3FFF;
        if ( spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v16))->spawnId != this->hitPresentable.spawnId )
        {
          PresentableByIndex = nullptr;
        }
        expectedHit = this->expectedHit;
        if ( PresentableByIndex == expectedHit )
        {
          idLib::Printf(fmt: "Expected presentable %d hit\n", expectedHit->index);
        }
        else
        {
          if ( PresentableByIndex != nullptr )
            index = PresentableByIndex->index;
          else
            index = -1;
          idLib::Printf(fmt: "Expected presentable %d NOT hit - hit %d instead \n", expectedHit->index, index);
        }
      }
      v20 = this->expectedHit;
      if ( v20 != nullptr )
        this->hitPresentable.spawnId = v20->spawnId;
      else
        this->hitPresentable.spawnId = 0;
    }
    netFireIndex = this->netFireIndex;
    this->expectedHit = nullptr;
    this->netFireIndex = netFireIndex + 1;
    Weapon = idFireParms::GetWeapon(this: fp);
    if ( Weapon != nullptr )
    {
      if ( (*((_BYTE *)fp + 129) & 0x20) != 0 )
        decl = (const idDeclAmmo *)Weapon->ammoClipSecondary->decl;
      else
        decl = (const idDeclAmmo *)Weapon->ammoClip->decl;
      this->ammoDecl = decl;
    }
    else
    {
      idLib::Warning(fmt: "Could not get weapon from idWeapon::RecordFireEvent");
    }
    this->lastFireTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v24 = this->hitPresentable.spawnId;
    v25 = v24 & 0x3FFF;
    if ( v24 != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: v24 & 0x3FFF) )
    {
      v26 = idClientGame::GetPresentableByIndex(this: clientGame, index: v25);
      v27 = this->hitPresentable.spawnId;
      if ( v26->spawnId == v27 )
      {
        v28 = this->hitPresentable.spawnId & 0x3FFF;
        if ( v27 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: this->hitPresentable.spawnId & 0x3FFF)
          || (v29 = idClientGame::GetPresentableByIndex(this: clientGame, index: v28))->spawnId != this->hitPresentable.spawnId )
        {
          v29 = nullptr;
        }
        if ( v29->entityNumber == 8190 )
          this->hitPresentable.spawnId = 0;
      }
    }
    this->hitJoint.value = -1;
    v30 = this->vehicleAttacker.spawnId;
    v31 = v30 & 0x3FFF;
    if ( v30 == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v30 & 0x3FFF)
      || idClientGame::GetPresentableByIndex(this: clientGame, index: v31)->spawnId != this->vehicleAttacker.spawnId )
    {
      v32 = this->hitPresentable.spawnId;
      v33 = v32 & 0x3FFF;
      if ( v32 != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: v32 & 0x3FFF) )
      {
        v34 = idClientGame::GetPresentableByIndex(this: clientGame, index: v33);
        v35 = this->hitPresentable.spawnId;
        if ( v34->spawnId == v35 )
        {
          v36 = this->hitPresentable.spawnId & 0x3FFF;
          if ( v35 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: this->hitPresentable.spawnId & 0x3FFF)
            || (v37 = idClientGame::GetPresentableByIndex(this: clientGame, index: v36))->spawnId != this->hitPresentable.spawnId )
          {
            v37 = nullptr;
          }
          if ( v37->GetAnimatedEntityInterface(this: v37) != nullptr )
          {
            v38 = 0;
            if ( tfr->numTraces > 0 )
            {
              p_c = &tfr->traces[0].c;
              while ( p_c->type != CONTACT_SPHERE )
              {
                ++v38;
                p_c = (contactInfo_t *)((char *)p_c + 128);
                if ( v38 >= tfr->numTraces )
                  goto LABEL_58;
              }
              v40 = (char *)tfr + 128 * v38;
              if ( *((_DWORD *)v40 + 14) == 4 )
                v41 = *((_DWORD *)v40 + 27);
              else
                LOWORD(v41) = -1;
              this->hitJoint.value = v41;
            }
          }
        }
      }
    }
LABEL_58:
    if ( presentableWeapon_debug.valueInteger != 0 )
      idLib::Printf(
        fmt: "Recorded fireEvent for presentableWeapon %s. netFireIndex: %d \n",
        this->weaponDecl->name.str,
        this->netFireIndex);
  }
}


// ========================================================================
// ?Serialize@idPresentableWeapon@@UAAXAAVidSerializer@@@Z
// EA  : 0x82BB2E80
// RVA : 0x00BB2E80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::Serialize(idPresentableWeapon *this, idSerializer *ser)
{
  unsigned int spawnId; // r10
  int v5; // r29
  idIndex<short,enum invalidJointIndex_t> *v6; // r29
  int value; // r11
  unsigned __int16 v8[24]; // [sp+50h] [-30h] BYREF

  idPresentableAnimatedEntity::Serialize(this, ser);
  this->netFireIndexLastSerialize = this->netFireIndex;
  idSerializer::SerializePacked(this: ser, original: &this->netFireIndexLastSerialize);
  idSerializer::SerializePacked(this: ser, original: &this->ownerEntityNum);
  idSerializer::Serialize<idDeclWeapon>(this: ser, decl: &this->weaponDecl);
  idSerializer::Serialize<idDeclAmmo>(this: ser, decl: &this->ammoDecl);
  idPresentableWeapon::UpdateOwnerAndAttacker(this);
  spawnId = this->vehicleAttacker.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId != this->vehicleAttacker.spawnId )
  {
    idPresentablePtr<idPresentableVehicle>::Serialize(
      this: (idPresentablePtr<idPresentableVehicle> *)&this->hitPresentable,
      ser);
    v6 = &NULL_JOINT_INDEX;
    value = this->hitJoint.value;
    if ( value == NULL_JOINT_INDEX.value )
      LOWORD(value) = -1;
    v8[0] = value;
    idSerializer::Serialize(this: ser, value: v8);
    if ( v8[0] != 0xFFFF )
      v6 = (idIndex<short,enum invalidJointIndex_t> *)v8;
    this->hitJoint = (idIndex<short,enum invalidJointIndex_t>)v6->value;
  }
}


// ========================================================================
// ?IsLocallyControlledByPlayer@idPresentableWeapon@@AAA_NXZ
// EA  : 0x82BB2F88
// RVA : 0x00BB2F88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

int __fastcall idPresentableWeapon::IsLocallyControlledByPlayer(idPresentableWeapon *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_attacker; // r30
  int v4; // r29
  int v5; // r29
  idPresentable *v6; // r3
  idPresentable *v7; // r3

  spawnId = this->attacker.spawnId;
  p_attacker = &this->attacker;
  v4 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId != p_attacker->spawnId )
  {
    idPresentableWeapon::UpdateOwnerAndAttacker(this);
  }
  v5 = p_attacker->spawnId & 0x3FFF;
  if ( p_attacker->spawnId == 0 )
    return 0;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_attacker->spawnId & 0x3FFF) )
    return 0;
  if ( idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId != p_attacker->spawnId )
    return 0;
  v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_attacker);
  if ( v6->GetPlayerInterface_2(this: v6) == nullptr )
    return 0;
  v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_attacker);
  return idClientGame::PlayerIndexIsLocal(this: clientGame, playerNum: v7->entityNumber);
}


// ========================================================================
// ?ClientThink@idPresentableWeapon@@UAAXHM_N@Z
// EA  : 0x82BB3088
// RVA : 0x00BB3088
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::ClientThink(
        idPresentableWeapon *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  const idDeclWeapon *v6; // r11
  const idDeclWeapon *weaponDecl; // r9
  char v8; // r11
  idWeapon *clientWeapon; // r11
  const char *v10; // r4
  const char *str; // r5
  char MuzzleFlashWorldTransform; // r3
  idTreeAnimator *TreeAnimator; // r3
  const idDeclWeapon *v14; // r11
  int entityNumber; // r6
  double v16; // fp6
  double v17; // fp5
  idTreeAnimator *v18; // r3
  int valueInteger; // r29
  idFinishFireResults *v20; // r11
  int i; // ctr
  int GameMs; // r3
  const idDeclWeapon *v23; // r6
  int ownerEntityNum; // r5
  unsigned int spawnId; // r11
  idPresentableVehicle *v26; // r3
  idPresentable *LockedTarget; // r3
  idPresentable *v28; // r3
  float y; // r9
  float z; // r8
  idPresentable *v31; // r3
  idPresentable *v32; // r3
  idPresentable *v33; // r3
  int v34; // r3
  float *v35; // r3
  double x; // fp31
  double v37; // fp30
  double v38; // fp29
  idPresentable *v39; // r3
  idPresentable *v40; // r3
  idPresentableAnimatedEntity *v41; // r3
  idTreeAnimator *v42; // r28
  idPresentable *v43; // r3
  idPresentable *v44; // r3
  idMat3 *v45; // r3
  double v46; // fp0
  double v47; // fp13
  double v48; // fp12
  idPresentable *v49; // r4
  int v50; // r11
  int v51; // r28
  idVec3 *p_endpos; // r29
  idFXManager *v53; // [sp+8h] [-BD8h]
  bool v54; // [sp+Fh] [-BD1h]
  idMat3 v55; // [sp+68h] [-B78h] BYREF
  float v56; // [sp+8Ch] [-B54h]
  float v57; // [sp+90h] [-B50h]
  idVec3 v58; // [sp+98h] [-B48h] BYREF
  float v59[4]; // [sp+A8h] [-B38h] BYREF
  float v60[4]; // [sp+B8h] [-B28h] BYREF
  idVec3 v61; // [sp+C8h] [-B18h] BYREF
  idVec3 v62; // [sp+D8h] [-B08h] BYREF
  idFireParms v63; // [sp+F0h] [-AF0h] BYREF
  idMat3 v64; // [sp+190h] [-A50h] BYREF
  idMat3 v65; // [sp+1C0h] [-A20h] BYREF
  idMat3 v66; // [sp+1F0h] [-9F0h] BYREF
  idFinishFireResults v67; // [sp+220h] [-9C0h] BYREF
  idTestFireResults v68; // [sp+270h] [-970h] BYREF

  idPresentableAnimatedEntity::ClientThink(this, curTime, fraction, predict, a5);
  if ( idPresentableAnimatedEntity::GetTreeAnimator(this) != nullptr )
  {
    if ( presentableWeapon_serializeLocal.valueInteger != 0
      || (unsigned __int8)idPresentableWeapon::IsLocallyControlledByPlayer(this) == 0 )
    {
      weaponDecl = this->weaponDecl;
      if ( weaponDecl == nullptr || (v8 = 1, this->clientWeapon == nullptr) )
        v8 = 0;
      if ( v8 != 0 )
      {
        if ( weaponDecl->hasLaserUpgrade )
        {
          if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->vehicleAttacker) != nullptr
            && idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->vehicleAttacker)->hidden )
          {
            MuzzleFlashWorldTransform = idPresentableWeapon::GetMuzzleFlashWorldTransform(
                                          this,
                                          origin: (idVec3 *)&v55.mat[1].y,
                                          axis: &v65,
                                          attackType: ATTACK_DEFAULT);
          }
          else
          {
            TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this);
            MuzzleFlashWorldTransform = idPresentableWeapon::GetLaserSightWorldTransform(
                                          this,
                                          parentModel: TreeAnimator,
                                          origin: (idVec3 *)&v55.mat[1].y,
                                          axis: &v65);
          }
          if ( MuzzleFlashWorldTransform != 0 )
          {
            v14 = this->weaponDecl;
            entityNumber = this->entityNumber;
            v16 = (float)(v65.mat[0].y * v14->maxRange);
            v17 = (float)(v65.mat[0].x * v14->maxRange);
            v62.z = v55.mat[2].x + (float)(v65.mat[0].z * v14->maxRange);
            v62.y = v55.mat[1].z + (float)v16;
            v62.x = v55.mat[1].y + (float)v17;
            idPresentableWeapon::UpdateLaserSight(
              this,
              startPos: (const idVec3 *)&v55.mat[1].y,
              endPos: &v62,
              passEntityNumber: entityNumber);
          }
        }
        if ( idPresentableWeapon::GetMuzzleFlashWorldTransform(
               this,
               origin: &v61,
               axis: &v64,
               attackType: ATTACK_DEFAULT) )
        {
          if ( this->netFireIndex < this->netFireIndexLastSerialize )
          {
            valueInteger = presentableWeapon_minFireTime.valueInteger;
            if ( this->lastFireTime + valueInteger < idGameTimeManager::GetGameMs(
                                                       this: &clientGame->gameTimeManager,
                                                       type: GAMETIME_SCALED) )
            {
              idFireParms::idFireParms(this: &v63);
              memset(&v68, 0, sizeof(v68));
              v20 = &v67;
              v67.numProjectiles = 0;
              for ( i = 16; i != 0; --i )
              {
                v20 = (idFinishFireResults *)((char *)v20 + 4);
                v20->numProjectiles = 0;
              }
              idFireParms::Clear(this: &v63);
              v68.numTraces = 0;
              v67.numProjectiles = 0;
              idInventoryItem::SetCount(this: &this->clientWeapon->ammoClip->idInventoryItem, amount: 5);
              *((_BYTE *)&v63 + 128) |= 0x20u;
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v23 = this->weaponDecl;
              ownerEntityNum = this->ownerEntityNum;
              spawnId = this->attacker.spawnId;
              v63.startTime = GameMs;
              *((_BYTE *)&v63 + 129) &= ~0x20u;
              v63.wepDef = v23;
              v63.ignoreEntityNum = ownerEntityNum;
              v63.attacker.spawnId = spawnId;
              v63.fireAxis.mat[0].x = v64.mat[0].x;
              v63.fireAxis.mat[0].y = v64.mat[0].y;
              v63.fireAxis.mat[0].z = v64.mat[0].z;
              v63.fireAxis.mat[1].x = v64.mat[1].x;
              v63.fireAxis.mat[1].y = v64.mat[1].y;
              v63.fireAxis.mat[1].z = v64.mat[1].z;
              v63.fireAxis.mat[2].x = v64.mat[2].x;
              v63.fireAxis.mat[2].y = v64.mat[2].y;
              v63.fireAxis.mat[2].z = v64.mat[2].z;
              v63.start.x = v61.x;
              v63.start.y = v61.y;
              v63.start.z = v61.z;
              if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->vehicleAttacker) != nullptr )
              {
                v26 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->vehicleAttacker);
                LockedTarget = idPresentableVehicle::GetLockedTarget(this: v26);
                if ( LockedTarget != nullptr )
                  this->hitPresentable.spawnId = LockedTarget->spawnId;
                else
                  this->hitPresentable.spawnId = 0;
              }
              if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable) != nullptr )
              {
                v28 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                y = v28->origin.y;
                z = v28->origin.z;
                v55.mat[2].z = v28->origin.x;
                v56 = y;
                v57 = z;
                v31 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                if ( v31->GetVehicleInterface(this: v31) != nullptr
                  && (v32 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable),
                      v32->IsLocallyControlled(this: v32)) )
                {
                  v33 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                  v34 = (int)v33->GetVehicleInterface(this: v33);
                  v35 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v34 + 16512) + 64))(
                                   a1: v34 + 16512,
                                   a2: 0);
                  x = *v35;
                  v37 = v35[1];
                  v38 = v35[2];
                }
                else
                {
                  v38 = v57;
                  v37 = v56;
                  x = v55.mat[2].z;
                }
                if ( (unsigned __int16)this->hitJoint.value < 0x8000u )
                {
                  v39 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                  if ( v39->GetAnimatedEntityInterface(this: v39) != nullptr )
                  {
                    v40 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                    v41 = v40->GetAnimatedEntityInterface(this: v40);
                    v42 = idPresentableAnimatedEntity::GetTreeAnimator(this: v41);
                    v43 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->hitPresentable);
                    v44 = v43->GetAnimatedEntityInterface(this: v43);
                    idPresentable::UpdateModelTransform(this: v44);
                    if ( v42 != nullptr )
                    {
                      idTreeAnimator::GetWorldSpaceJointTransform(
                        this: v42,
                        pose: DRIVER_MODEL,
                        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->hitJoint.value,
                        origin: &v58,
                        axis: &v66);
                      if ( presentableWeapon_debug.valueInteger != 0 )
                        clientGame->renderWorld->DebugAxis(
                          this: clientGame->renderWorld,
                          a2: (const idVec4 *)&idColor::colorYellow,
                          a3: &v58,
                          a4: &v66,
                          a5: 5000,
                          a6: false);
                      x = v58.x;
                      v37 = v58.y;
                      v38 = v58.z;
                    }
                  }
                }
                v55.mat[0].x = (float)x - v63.start.x;
                v55.mat[0].z = (float)v38 - v63.start.z;
                v55.mat[0].y = (float)v37 - v63.start.y;
                if ( (COERCE_UNSIGNED_INT(fabs(v55.mat[0].y))
                    | COERCE_UNSIGNED_INT(fabs(v55.mat[0].z))
                    | COERCE_UNSIGNED_INT(fabs(v55.mat[0].x))) != 0 )
                {
                  idVec3::NormalizeFast(this: v55.mat);
                  v45 = idVec3::ToMat3(this: v66.mat, result: &v55);
                  v46 = v45->mat[0].x;
                  v63.fireAxis.mat[0].x = v45->mat[0].x;
                  v47 = v45->mat[0].y;
                  v63.fireAxis.mat[0].y = v45->mat[0].y;
                  v48 = v45->mat[0].z;
                  v63.fireAxis.mat[0].z = v45->mat[0].z;
                  v63.fireAxis.mat[1].x = v45->mat[1].x;
                  v63.fireAxis.mat[1].y = v45->mat[1].y;
                  v63.fireAxis.mat[1].z = v45->mat[1].z;
                  v63.fireAxis.mat[2] = v45->mat[2];
                  if ( presentableWeapon_debug.valueInteger != 0 )
                  {
                    v59[1] = v63.start.y + (float)((float)v47 * (float)1000.0);
                    v59[0] = (float)((float)v46 * (float)1000.0) + v63.start.x;
                    v59[2] = v63.start.z + (float)((float)v48 * (float)1000.0);
                    clientGame->renderWorld->DebugLine(
                      this: clientGame->renderWorld,
                      a2: (const idVec4 *)&idColor::colorRed,
                      a3: &v63.start,
                      a4: (const idVec3 *)v59,
                      a5: 5000,
                      a6: false);
                    v60[1] = v63.start.y + (float)(v63.fireAxis.mat[0].y * (float)1000.0);
                    v60[0] = (float)(v63.fireAxis.mat[0].x * (float)1000.0) + v63.start.x;
                    v60[2] = v63.start.z + (float)(v63.fireAxis.mat[0].z * (float)1000.0);
                    clientGame->renderWorld->DebugLine(
                      this: clientGame->renderWorld,
                      a2: (const idVec4 *)&idColor::colorGreen,
                      a3: &v63.start,
                      a4: (const idVec3 *)v60,
                      a5: 5000,
                      a6: false);
                  }
                }
              }
              v49 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->attacker);
              idWeapon::Fire(
                this: this->clientWeapon,
                attacker: v49,
                target: nullptr,
                start: &v63.start,
                fireAxis: &v63.fireAxis,
                fp: &v63,
                tfr: &v68,
                ffr: &v67,
                fxMgr: v53,
                secondaryAmmo: v54);
              v50 = presentableWeapon_debug.valueInteger;
              if ( presentableWeapon_debug.valueInteger != 0 )
              {
                v51 = 0;
                if ( v68.numTraces > 0 )
                {
                  p_endpos = &v68.traces[0].endpos;
                  do
                  {
                    if ( v50 != 0 )
                    {
                      clientGame->renderWorld->DebugAxis_2(
                        this: clientGame->renderWorld,
                        a2: p_endpos,
                        a3: (const idMat3 *)&p_endpos[1],
                        a4: 5000,
                        a5: false);
                      v50 = presentableWeapon_debug.valueInteger;
                    }
                    ++v51;
                    p_endpos = (idVec3 *)((char *)p_endpos + 128);
                  }
                  while ( v51 < v68.numTraces );
                }
              }
              ++this->netFireIndex;
              this->lastFireTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
              idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v63.targetList);
            }
          }
        }
        else if ( idPresentableAnimatedEntity::GetTreeAnimator(this) != nullptr )
        {
          v18 = idPresentableAnimatedEntity::GetTreeAnimator(this);
          idLib::Warning(fmt: "Unable to find muzzle transform for %s", v18->decl->name.str);
        }
        else
        {
          idLib::Warning(fmt: "Unable to find muzzle transform for %s", "NULL");
        }
      }
      else
      {
        clientWeapon = this->clientWeapon;
        v10 = "NULL";
        if ( clientWeapon != nullptr )
          str = clientWeapon->decl->name.str;
        else
          str = "NULL";
        if ( weaponDecl != nullptr )
          v10 = weaponDecl->name.str;
        idLib::Warning(
          fmt: "fireEvents to play but no weapon. weaponDecl: %s clientWeapon: %s netFireIndex: %d netFireIndexLastSerialize: %d",
          v10,
          str,
          this->netFireIndex,
          this->netFireIndexLastSerialize);
        this->netFireIndex = this->netFireIndexLastSerialize;
      }
    }
    else
    {
      this->netFireIndex = this->netFireIndexLastSerialize;
    }
  }
  else
  {
    v6 = this->weaponDecl;
    if ( v6 != nullptr )
      idLib::Warning(fmt: "NULL tree animator for presentable weapon %s", v6->name.str);
    else
      idLib::Warning(fmt: "NULL tree animator for presentable weapon %s", "NULL");
  }
}


// ========================================================================
// __unwind$490590
// EA  : 0x82BB3894
// RVA : 0x00BB3894
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void _unwind_490590()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3040 + 240));
}


// ========================================================================
// ?SetClientWeapon@idPresentableWeapon@@QAAXPAVidWeapon@@@Z
// EA  : 0x82BB38C0
// RVA : 0x00BB38C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __fastcall idPresentableWeapon::SetClientWeapon(idPresentableWeapon *this, idWeapon *weapon)
{
  idWeapon *clientWeapon; // r4
  const char *str; // r7

  clientWeapon = this->clientWeapon;
  if ( clientWeapon != nullptr )
  {
    if ( weapon != nullptr )
      str = weapon->decl->name.str;
    else
      str = "NULL";
    idLib::Warning(
      fmt: "Setting presentableWeapon's clientWeapon twice? old: %p[%s] new: %p[%s]",
      clientWeapon,
      clientWeapon->decl->name.str,
      weapon,
      str);
    if ( idWeapon::GetPresentableWeapon(this: this->clientWeapon) == this )
      this->clientWeapon->presentableWeapon.spawnId = 0;
  }
  this->clientWeapon = weapon;
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_debug''
// EA  : 0x83371FA0
// RVA : 0x01371FA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_debug__()
{
  idCVar::idCVar(
    this: &presentableWeapon_debug,
    name: "presentableWeapon_debug",
    value: "0",
    flags: 1,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_debug__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_debugFire''
// EA  : 0x83371FF8
// RVA : 0x01371FF8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_debugFire__()
{
  idCVar::idCVar(
    this: &presentableWeapon_debugFire,
    name: "presentableWeapon_debugFire",
    value: "0",
    flags: 1,
    description: "Debug PresentableWeapons interpolated fire",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_debugFire__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_loopingSoundEnd''
// EA  : 0x83372050
// RVA : 0x01372050
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_loopingSoundEnd__()
{
  idCVar::idCVar(
    this: &presentableWeapon_loopingSoundEnd,
    name: "presentableWeapon_loopingSoundEnd",
    value: "200",
    flags: 2,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_loopingSoundEnd__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_roll_startAccel''
// EA  : 0x833720A8
// RVA : 0x013720A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_roll_startAccel__()
{
  idCVar::idCVar(
    this: &presentableWeapon_roll_startAccel,
    name: "presentableWeapon_roll_startAccel",
    value: "1.25",
    flags: 4,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_roll_startAccel__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_roll_endAccel''
// EA  : 0x83372100
// RVA : 0x01372100
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_roll_endAccel__()
{
  idCVar::idCVar(
    this: &presentableWeapon_roll_endAccel,
    name: "presentableWeapon_roll_endAccel",
    value: "0.2",
    flags: 4,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_roll_endAccel__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_roll_topSpeed''
// EA  : 0x83372158
// RVA : 0x01372158
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_roll_topSpeed__()
{
  idCVar::idCVar(
    this: &presentableWeapon_roll_topSpeed,
    name: "presentableWeapon_roll_topSpeed",
    value: "10.0",
    flags: 4,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_roll_topSpeed__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_roll_endTime''
// EA  : 0x833721B0
// RVA : 0x013721B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_roll_endTime__()
{
  idCVar::idCVar(
    this: &presentableWeapon_roll_endTime,
    name: "presentableWeapon_roll_endTime",
    value: "250",
    flags: 2,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_roll_endTime__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_serializeLocal''
// EA  : 0x83372208
// RVA : 0x01372208
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_serializeLocal__()
{
  idCVar::idCVar(
    this: &presentableWeapon_serializeLocal,
    name: "presentableWeapon_serializeLocal",
    value: "0",
    flags: 1,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_serializeLocal__);
}


// ========================================================================
// `dynamic initializer for 'presentableWeapon_minFireTime''
// EA  : 0x83372260
// RVA : 0x01372260
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentableWeapon_minFireTime__()
{
  idCVar::idCVar(
    this: &presentableWeapon_minFireTime,
    name: "presentableWeapon_minFireTime",
    value: "32",
    flags: 2,
    description: "Debug PresentableWeapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentableWeapon_minFireTime__);
}

