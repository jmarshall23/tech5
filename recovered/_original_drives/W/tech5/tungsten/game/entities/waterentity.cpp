
// ========================================================================
// ?Hide@idWaterEntity@@UAAXXZ
// EA  : 0x82D4CCF8
// RVA : 0x00D4CCF8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::Hide(idStaticWaterEntity *this)
{
  idPhysics *Physics; // r3

  idEntity::Hide(this);
  Physics = idEntity::GetPhysics(this);
  Physics->DisableClip(this: Physics);
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Show@idWaterEntity@@UAAXXZ
// EA  : 0x82D4CD48
// RVA : 0x00D4CD48
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::Show(idStaticWaterEntity *this)
{
  idPhysics *Physics; // r3

  idEntity::Show(this);
  Physics = idEntity::GetPhysics(this);
  Physics->EnableClip(this: Physics);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?OnActivate@idWaterEntity@@EAAXPAVidEntity@@@Z
// EA  : 0x82D4CD98
// RVA : 0x00D4CD98
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::OnActivate(idStaticWaterEntity *this, idEntity *activator)
{
  char idCombatStage_useRelaxedChatterVO; // r3
  idStaticWaterEntity_vtbl *v4; // r11

  idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this);
  v4 = this->__vftable;
  if ( idCombatStage_useRelaxedChatterVO != 0 )
    v4->Show(this);
  else
    v4->Hide_2(this);
}


// ========================================================================
// ?Spawn@idStaticWaterEntity@@QAAXXZ
// EA  : 0x82D4CDF0
// RVA : 0x00D4CDF0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idStaticWaterEntity::Spawn(idStaticWaterEntity *this)
{
  idPhysics *Physics; // r3
  idBounds *v3; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v3);
}


// ========================================================================
// ?Hide@idWaterRippleEmitter@@UAAXXZ
// EA  : 0x82D4CE40
// RVA : 0x00D4CE40
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterRippleEmitter::Hide(idWaterRippleEmitter *this)
{
  idDynamicEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 1);
  this->hidden = true;
}


// ========================================================================
// ?Show@idWaterRippleEmitter@@UAAXXZ
// EA  : 0x82D4CE80
// RVA : 0x00D4CE80
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterRippleEmitter::Show(idWaterRippleEmitter *this)
{
  idDynamicEntity::Show(this);
  this->hidden = false;
}


// ========================================================================
// ?OnActivate@idWaterRippleEmitter@@UAAXPAVidEntity@@@Z
// EA  : 0x82D4CEB8
// RVA : 0x00D4CEB8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterRippleEmitter::OnActivate(idWaterRippleEmitter *this, idEntity *activator)
{
  if ( this->cycleTrigger || this->hidden )
    ((void (__fastcall *)(idWaterRippleEmitter *, idEntity *))this->Show)(a1: this, a2: activator);
  else
    ((void (__fastcall *)(idWaterRippleEmitter *, idEntity *))this->Hide_2)(a1: this, a2: activator);
}


// ========================================================================
// ?Think@idWaterEntity@@UAAXXZ
// EA  : 0x82D4CEF0
// RVA : 0x00D4CEF0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::Think(idWaterEntity *this)
{
  double viscosity; // fp31
  double density; // fp30
  int v4; // r3
  surfTypes_t surfTypeOverride; // r30
  const idVec3 *damageDecl; // r29
  double v7; // fp29
  idPhysics *Physics; // r3
  surfTypes_t v9; // r9
  int v10; // [sp+8h] [-A8h]
  int v11; // [sp+Ch] [-A4h]
  int v12; // [sp+10h] [-A0h]
  int v13; // [sp+14h] [-9Ch]
  int v14; // [sp+18h] [-98h]
  int v15; // [sp+1Ch] [-94h]
  int v16; // [sp+20h] [-90h]
  int v17; // [sp+24h] [-8Ch]
  int v18; // [sp+28h] [-88h]
  int v19; // [sp+2Ch] [-84h]
  int v20; // [sp+30h] [-80h]
  int v21; // [sp+34h] [-7Ch]
  int v22; // [sp+38h] [-78h]
  int v23; // [sp+3Ch] [-74h]
  int v24; // [sp+40h] [-70h]
  int v25; // [sp+44h] [-6Ch]
  int v26; // [sp+48h] [-68h]
  int v27; // [sp+4Ch] [-64h]
  int v28; // [sp+50h] [-60h]
  int v29; // [sp+58h] [-58h]

  viscosity = this->viscosity;
  density = this->density;
  v4 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  surfTypeOverride = this->surfTypeOverride;
  damageDecl = (const idVec3 *)this->damageDecl;
  v7 = (float)((float)__SPAIR64__(&unk_82390000, v4) * (float)0.001);
  Physics = idEntity::GetPhysics(this);
  idBuoyancy::ApplyBuoyancy(
    this: &this->buoyancy,
    clip: &clientGame->clip,
    physics: Physics,
    timeStep: v7,
    waterDamage: (const idDeclDamage *)&ai_useTurnTransitions.valueString.baseBuffer[12],
    waterCurrent: damageDecl,
    waterDensity: density,
    waterViscosity: viscosity,
    clipMask: (int)&this->current,
    surfOverride: v9,
    a11: 37889,
    a12: v10,
    a13: v11,
    a14: v12,
    a15: v13,
    a16: v14,
    a17: v15,
    a18: v16,
    a19: v17,
    a20: v18,
    a21: v19,
    a22: v20,
    a23: v21,
    a24: v22,
    a25: v23,
    a26: v24,
    a27: v25,
    a28: v26,
    a29: v27,
    a30: v28,
    a31: 37889,
    a32: v29,
    a33: surfTypeOverride);
  this->damageDecl = nullptr;
  idEntity::Think(this);
}


// ========================================================================
// ?RebuildGeometry@idDynamicWaterEntity@@QAAXXZ
// EA  : 0x82D4CFC8
// RVA : 0x00D4CFC8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::RebuildGeometry(idDynamicWaterEntity *this)
{
  idGame *v2; // r3
  idRenderModel *v3; // r3
  idRenderModelWaterSurface *v4; // r29
  idGame *v5; // r28
  idPhysics *Physics; // r27
  char *data; // r26
  __int64 v8; // r7
  double speed; // fp31
  double damping; // fp30
  double spacing; // fp29
  double v12; // fp28
  const idBounds *v13; // r3
  int v14; // r9
  int v15; // r8
  int v16; // r7
  const char *v17; // r6
  idGame *v18; // r3
  idGame *v19; // r3

  v2 = common->Game(this: common);
  v3 = v2->EntityGetRenderModel(this: v2, a2: this);
  v4 = (idRenderModelWaterSurface *)_RTDynamicCast(
                                      inptr: v3,
                                      VfDelta: 0,
                                      SrcType: &idRenderModel `RTTI Type Descriptor',
                                      TargetType: &idRenderModelWaterSurface `RTTI Type Descriptor',
                                      isReference: 0);
  if ( v4 != nullptr )
  {
    v5 = common->Game(this: common);
    Physics = idEntity::GetPhysics(this);
    data = this->imgName.data;
    LODWORD(v8) = v5->GetGameMsPerFrame(this: v5, a2: GAMETIME_NORMAL);
    HIDWORD(v8) = Physics->__vftable;
    speed = this->speed;
    damping = this->damping;
    spacing = this->spacing;
    v12 = (float)((float)v8 * (float)0.001);
    v13 = Physics->GetBounds(this: Physics, a2: -1);
    idRenderModelWaterSurface::BuildWaterModel(
      this: v4,
      mtr: this->material,
      waterBounds: v13,
      spacing,
      damping,
      speed,
      timeStep: v12,
      imgName: v17,
      a9: v16,
      a10: v15,
      a11: v14,
      a12: data);
  }
  v18 = common->Game(this: common);
  v18->EntityUpdateModifiedProperties(this: v18, a2: this);
  v19 = common->Game(this: common);
  v19->EntityUpdateVisuals(this: v19, a2: this);
}


// ========================================================================
// ?AddRipple@idDynamicWaterEntity@@QAAXABVidVec3@@MM@Z
// EA  : 0x82D4D140
// RVA : 0x00D4D140
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::AddRipple(
        idDynamicWaterEntity *this,
        const idVec3 *pos,
        double mag,
        double radius,
        const idRenderModel *a5,
        int a6)
{
  idRenderModelWaterSurface *waterModel; // r7
  idWaterSurfaceSim *waterSim; // r3

  waterModel = this->waterModel;
  if ( waterModel != nullptr )
  {
    waterSim = waterModel->waterSim;
    if ( waterSim != nullptr && (*((_BYTE *)&this->flags + 1) & 0x80) == 0 )
    {
      _FP12 = (float)(this->waterInteraction.maxRadius - (float)radius);
      _FP11 = (float)(this->waterInteraction.maxMagnitude - (float)mag);
      __asm
      {
        fsel      f2, f12, f2, f0# radius
        fsel      f1, f11, f1, f13# mag
      }
      idWaterSurfaceSim::AddRipple(this: waterSim, pos, mag: _FP1, radius: _FP2, rmod: a5, a6, a7: waterModel);
    }
  }
}


// ========================================================================
// ?AddRipple@idDynamicWaterEntity@@QAAXABVidVec3@@MMMM@Z
// EA  : 0x82D4D190
// RVA : 0x00D4D190
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::AddRipple(
        idDynamicWaterEntity *this,
        const idVec3 *pos,
        double amp,
        double frequency,
        double phase,
        double radius)
{
  idRenderModelWaterSurface *waterModel; // r11
  idWaterSurfaceSim *waterSim; // r30
  double v12; // fp1
  int v17; // r6
  const idRenderModel *v18; // r5

  waterModel = this->waterModel;
  if ( waterModel != nullptr )
  {
    waterSim = waterModel->waterSim;
    if ( waterSim != nullptr && (*((_BYTE *)&this->flags + 1) & 0x80) == 0 )
    {
      v12 = idMath::Sin16(a: (float)((float)frequency + (float)phase));
      _FP11 = (float)(this->waterInteraction.maxRadius - (float)radius);
      _FP10 = (float)(this->waterInteraction.maxMagnitude - (float)((float)v12 * (float)amp));
      __asm
      {
        fsel      f2, f11, f31, f13# radius
        fsel      f1, f10, f0, f12# mag
      }
      idWaterSurfaceSim::AddRipple(
        this: waterSim,
        pos,
        mag: _FP1,
        radius: _FP2,
        rmod: v18,
        a6: v17,
        a7: this->waterModel);
    }
  }
}


// ========================================================================
// ?ApplyRadiusEffect@idDynamicWaterEntity@@QAAXABVidVec3@@MH@Z
// EA  : 0x82D4D220
// RVA : 0x00D4D220
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::ApplyRadiusEffect(
        idDynamicWaterEntity *this,
        const idVec3 *pos,
        double radius,
        int time,
        int a5)
{
  idRenderModelWaterSurface *waterModel; // r11
  int v8; // r11

  waterModel = this->waterModel;
  if ( waterModel != nullptr && waterModel->waterSim != nullptr && (*((_BYTE *)&this->flags + 1) & 0x80) == 0 )
  {
    this->waterIllumination[this->nextWaterIlluminationTest].pos = *pos;
    this->waterIllumination[this->nextWaterIlluminationTest].radius = radius;
    this->waterIllumination[this->nextWaterIlluminationTest].startTime = idGameTimeManager::GetGameMs(
                                                                           this: &clientGame->gameTimeManager,
                                                                           type: GAMETIME_SCALED);
    this->waterIllumination[this->nextWaterIlluminationTest].endTime = idGameTimeManager::GetGameMs(
                                                                         this: &clientGame->gameTimeManager,
                                                                         type: GAMETIME_SCALED)
                                                                     + a5;
    v8 = this->nextWaterIlluminationTest + 1;
    this->nextWaterIlluminationTest = v8;
    if ( v8 >= 4 )
      this->nextWaterIlluminationTest = 0;
  }
}


// ========================================================================
// ?SetPositionOnSurface@idDynamicWaterEntity@@QAA_NAAVidVec3@@AAM0@Z
// EA  : 0x82D4D330
// RVA : 0x00D4D330
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

int __fastcall idDynamicWaterEntity::SetPositionOnSurface(
        idDynamicWaterEntity *this,
        idVec3 *pos,
        float *waveHeight,
        idVec3 *normal)
{
  idRenderModelWaterSurface *waterModel; // r11

  waterModel = this->waterModel;
  if ( waterModel->waterSim == nullptr || (*((_BYTE *)&this->flags + 1) & 0x80) != 0 )
    return 0;
  else
    return idWaterSurfaceSim::GetSurfacePositionAtPoint(
             this: waterModel->waterSim,
             pos,
             waterSurfaceModel: this->waterModel,
             retWaveHeight: waveHeight,
             normal);
}


// ========================================================================
// ?Spawn@idWaterEntity@@QAAXXZ
// EA  : 0x82D4D3B8
// RVA : 0x00D4D3B8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::Spawn(idWaterEntity *this)
{
  idPhysics *Physics; // r3
  const idDeclEnv *envWaterEffects; // r28
  idRenderWorld_vtbl *v4; // r30
  int v5; // r3

  if ( this->envWaterEffects == nullptr )
    this->envWaterEffects = (const idDeclEnv *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclEnv::resourceList,
                                                 name: "underwater/default",
                                                 makeDefault: true);
  if ( this->envWaterEffects != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    envWaterEffects = this->envWaterEffects;
    v4 = clientGame->renderWorld->__vftable;
    v5 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
    v4->AddEnvironment(this: clientGame->renderWorld, a2: (const idBounds *)v5, a3: envWaterEffects);
  }
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?UpdateWaves@idStaticWaterEntity@@AAAXXZ
// EA  : 0x82D4D460
// RVA : 0x00D4D460
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idStaticWaterEntity::UpdateWaves(idStaticWaterEntity *this)
{
  idPresentable *presentable; // r11
  char v3; // r11
  bool v4; // zf
  __int64 v5; // r7
  float *p_life; // r31
  int v7; // r26
  double v8; // fp31
  unsigned int v9; // r9
  double lifeMin; // fp13
  double v11; // fp13
  double v12; // fp0
  double v13; // fp0
  double v14; // fp0
  double v15; // fp13
  idLinkList<idFuncWind> *next; // r11
  idVec3 *owner; // r4
  float *CurrentWindDirection; // r3
  float *p_angleY; // r10
  int v20; // r11
  int v21; // ctr
  double v22; // fp12
  __int64 *v23; // r7
  __int64 *v24; // r9
  double v25; // fp10
  double v26; // fp8
  __int64 *v27; // r8
  double v28; // fp7
  double v29; // fp6
  double v30; // fp3
  double v31; // fp2
  idPresentable *v32; // r31
  int v33; // r10
  int v34; // r9
  int v35; // r8
  int v36; // r7
  int v37; // r10
  int v38; // r9
  int v39; // r8
  int v40; // r7
  int v41; // r10
  int v42; // r9
  int v43; // r8
  int v44; // r7
  int v45; // r10
  int v46; // r9
  int v47; // r8
  int v48; // r7
  __int64 v49; // [sp+8h] [-F8h]
  __int64 v50; // [sp+8h] [-F8h]
  __int64 v51; // [sp+8h] [-F8h]
  __int64 v52; // [sp+8h] [-F8h]
  __int64 v53; // [sp+8h] [-F8h]
  __int64 v54; // [sp+10h] [-F0h]
  __int64 v55; // [sp+10h] [-F0h]
  __int64 v56; // [sp+10h] [-F0h]
  __int64 v57; // [sp+10h] [-F0h]
  __int64 v58; // [sp+10h] [-F0h]
  __int64 v59; // [sp+18h] [-E8h]
  __int64 v60; // [sp+18h] [-E8h]
  __int64 v61; // [sp+18h] [-E8h]
  __int64 v62; // [sp+18h] [-E8h]
  __int64 v63; // [sp+18h] [-E8h]
  __int64 v64; // [sp+20h] [-E0h]
  __int64 v65; // [sp+20h] [-E0h]
  __int64 v66; // [sp+20h] [-E0h]
  __int64 v67; // [sp+20h] [-E0h]
  __int64 v68; // [sp+20h] [-E0h]
  __int64 v69; // [sp+28h] [-D8h]
  __int64 v70; // [sp+28h] [-D8h]
  __int64 v71; // [sp+28h] [-D8h]
  __int64 v72; // [sp+28h] [-D8h]
  __int64 v73; // [sp+28h] [-D8h]
  __int64 v74[2]; // [sp+50h] [-B0h] BYREF
  __int64 v75[2]; // [sp+60h] [-A0h] BYREF
  __int64 v76[2]; // [sp+70h] [-90h] BYREF
  __int64 v77[2]; // [sp+80h] [-80h] BYREF
  __int64 v78[3]; // [sp+90h] [-70h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = presentable->model != nullptr, v3 = 1, !v4) )
    v3 = 0;
  if ( v3 != 0 )
  {
    v74[0] = __PAIR64__(
               &unk_82390000,
               idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
    p_life = &this->waves[0].life;
    v7 = 4;
    v8 = (float)((float)v74[0] * (float)0.001);
    do
    {
      if ( *((_BYTE *)p_life + 80) != 0 )
      {
        if ( (float)((float)v8 - *(p_life - 1)) > (double)*p_life || v8 < *(p_life - 1) )
        {
          *(p_life - 1) = v8;
          v9 = 1664525 * this->waveRandom.seed + 1013904223;
          LODWORD(v5) = (v9 >> 10) & 0x7FFF;
          this->waveRandom.seed = v9;
          lifeMin = this->waveParms.lifeMin;
          v74[0] = v5;
          *p_life = (float)((float)((float)v5 * (float)(this->waveParms.lifeMax - (float)lifeMin))
                          * (float)0.000030518509)
                  + (float)lifeMin;
        }
        v11 = (float)((float)v8 - *(p_life - 1));
        v12 = (float)(this->waveParms.fade * *p_life);
        if ( v11 < v12 || (v11 = (float)((float)(*(p_life - 1) + *p_life) - (float)v8)) < v12 )
        {
          v13 = (float)((float)v11 / (float)(this->waveParms.fade * *p_life));
          if ( v13 < 0.0099999998 )
            v13 = 0.0099999998;
        }
        else
        {
          v13 = 1.0;
        }
        p_life[1] = v13;
        p_life[2] = idMath::Cos16(a: (float)(p_life[24] * idMath::M_DEG2RAD));
        p_life[3] = idMath::Sin16(a: (float)(p_life[24] * idMath::M_DEG2RAD));
      }
      --v7;
      p_life += 5;
    }
    while ( v7 != 0 );
    v14 = 1.0;
    v15 = 0.0;
    next = gameLocal->globalWindEntities.next;
    if ( next != nullptr && next != gameLocal->globalWindEntities.head )
    {
      owner = (idVec3 *)next->owner;
      if ( owner != nullptr )
      {
        CurrentWindDirection = (float *)idFuncWind::GetCurrentWindDirection(this: (idFuncWind *)v74, result: owner);
        v14 = *CurrentWindDirection;
        v15 = CurrentWindDirection[1];
      }
    }
    p_angleY = &this->waves[0].angleY;
    v20 = 0;
    v21 = 4;
    v22 = idMath::TWO_PI;
    do
    {
      v23 = v77;
      if ( *((_BYTE *)p_angleY + 68) != 0 )
      {
        v24 = v75;
        v25 = (float)((float)v14 * *p_angleY);
        v26 = (float)((float)v22 / p_angleY[19]);
        v27 = v76;
        v28 = (float)(*p_angleY * (float)v15);
        v29 = *(p_angleY - 1);
        v30 = p_angleY[20];
        v31 = (float)(*(p_angleY - 2) * p_angleY[18]);
        *(float *)((char *)v77 + v20) = (float)v22 / p_angleY[19];
        *(float *)((char *)v78 + v20) = v31;
        *(float *)((char *)v74 + v20) = (float)v26 * (float)v30;
        *(float *)((char *)v75 + v20) = (float)((float)v14 * (float)v29) + (float)v28;
        *(float *)((char *)v76 + v20) = (float)((float)v29 * (float)v15) + (float)-v25;
      }
      else
      {
        v24 = v74;
        *(float *)((char *)v77 + v20) = 0.0;
        v27 = v78;
        *(float *)((char *)v74 + v20) = 0.0;
        *(float *)((char *)v78 + v20) = 0.0;
        *(float *)((char *)v76 + v20) = 0.0;
        *(float *)((char *)v75 + v20) = 0.0;
      }
      p_angleY += 5;
      v20 += 4;
      --v21;
    }
    while ( v21 != 0 );
    v32 = this->presentable;
    if ( v32 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v32 = this->presentable;
    }
    idPresentable::SetParm(
      this: v32,
      parm: this->rp_wavePhase,
      v4: v74[1],
      a4: (int)v23,
      a5: (int)v27,
      a6: (int)v24,
      a7: (int)p_angleY,
      a8: v49,
      a9: v54,
      a10: v59,
      a11: v64,
      a12: v69);
    idPresentable::SetParm(
      this: v32,
      parm: this->rp_waveDirX,
      v4: v75[1],
      a4: v36,
      a5: v35,
      a6: v34,
      a7: v33,
      a8: v50,
      a9: v55,
      a10: v60,
      a11: v65,
      a12: v70);
    idPresentable::SetParm(
      this: v32,
      parm: this->rp_waveDirY,
      v4: v76[1],
      a4: v40,
      a5: v39,
      a6: v38,
      a7: v37,
      a8: v51,
      a9: v56,
      a10: v61,
      a11: v66,
      a12: v71);
    idPresentable::SetParm(
      this: v32,
      parm: this->rp_waveFreq,
      v4: v77[1],
      a4: v44,
      a5: v43,
      a6: v42,
      a7: v41,
      a8: v52,
      a9: v57,
      a10: v62,
      a11: v67,
      a12: v72);
    idPresentable::SetParm(
      this: v32,
      parm: this->rp_waveAmp,
      v4: v78[1],
      a4: v48,
      a5: v47,
      a6: v46,
      a7: v45,
      a8: v53,
      a9: v58,
      a10: v63,
      a11: v68,
      a12: v73);
    v32->Present(this: v32);
  }
}


// ========================================================================
// ?reloadWater_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D4D7B0
// RVA : 0x00D4D7B0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall reloadWater_f(const idCmdArgs *args)
{
  idGame *v1; // r3
  idDynamicWaterEntity *i; // r30
  const idGame *v3; // r29
  idEntityInterface *iface; // r11
  bool v5; // r3
  idDynamicWaterEntity *v6; // r3
  idGame *v7; // r3
  idEntityInterfaceObject v8[8]; // [sp+50h] [-40h] BYREF

  ++idResourceList::staleCount;
  v1 = common->Game(this: common);
  for ( i = (idDynamicWaterEntity *)v1->FindEntityUsingClass(this: v1, a2: nullptr, a3: "idDynamicWaterEntity");
        i != nullptr;
        i = (idDynamicWaterEntity *)v7->FindEntityUsingClass(this: v7, a2: i, a3: "idDynamicWaterEntity") )
  {
    v3 = common->Game(this: common);
    idGameLock::idGameLock(this: &v8[0].lock, newGame: v3);
    v8[0].iface = nullptr;
    iface = v3->AllocEntityInterface(this: v3, a2: i);
    v8[0].iface = iface;
    if ( iface != nullptr )
    {
      v5 = iface->IsValid(this: iface);
      iface = v8[0].iface;
    }
    else
    {
      v5 = false;
    }
    if ( v5 && iface->GetTypeInfoObject(this: iface) != nullptr )
    {
      v6 = idDynamicWaterEntity::CastTo(c: i);
      if ( v6 != nullptr )
        idDynamicWaterEntity::RebuildGeometry(this: v6);
    }
    idEntityInterfaceObject::~idEntityInterfaceObject(this: v8);
    v7 = common->Game(this: common);
  }
}


// ========================================================================
// __unwind$489909
// EA  : 0x82D4D918
// RVA : 0x00D4D918
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_489909()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$489904
// EA  : 0x82D4D940
// RVA : 0x00D4D940
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_489904()
{
  int v0; // r12

  idEntityInterfaceObject::~idEntityInterfaceObject(this: (idEntityInterfaceObject *)(v0 - 144 + 80));
}


// ========================================================================
// ?Spawn@idWaterRippleEmitter@@QAAXXZ
// EA  : 0x82D4D968
// RVA : 0x00D4D968
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterRippleEmitter::Spawn(idWaterRippleEmitter *this)
{
  int GameMs; // r3
  __int64 v3; // r8
  unsigned int v4; // r10
  double rippleWavelength; // fp0
  idWaterRippleEmitter::waterRippleType_t rippleType; // r10
  double rippleFade1; // fp12
  double rippleFade2; // fp11
  double v9; // fp2
  double v10; // fp1
  double v11; // fp12
  int value; // r10
  idEntityPtr<idDynamicWaterEntity> *p_waterSurface; // r29
  idDynamicWaterEntity *v14; // r3
  idDynamicWaterEntity *v15; // r3
  idDynamicWaterEntity *v16; // r3
  idEntityPtr<idDynamicWaterEntity> *v17; // r3
  char *data; // r31
  idDynamicWaterEntity *Entity; // r3

  if ( this->startOff )
  {
    this->hidden = true;
  }
  else
  {
    this->hidden = false;
    idEntity::BecomeActive(this, flags: 1);
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v3) = 1664525;
  this->startTime = (float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001;
  v4 = 1664525 * this->rnd.seed + 1013904223;
  LODWORD(v3) = (v4 >> 10) & 0x7FFF;
  this->rnd.seed = v4;
  rippleWavelength = this->rippleWavelength;
  rippleType = this->rippleType;
  rippleFade1 = this->rippleFade1;
  rippleFade2 = this->rippleFade2;
  v9 = (float)((float)1.0 / (float)(this->rippleFade1 * this->rippleWavelength));
  v10 = (float)((float)1.0 / (float)(this->rippleFade2 * this->rippleWavelength));
  this->restartTime = (float)((float)v3 * idMath::TWO_PI) * (float)0.000030518509;
  this->rippleFrequency = idMath::TWO_PI / (float)rippleWavelength;
  this->rippleDecay1 = v9;
  this->rippleDecay2 = v10;
  if ( rippleType == RIPPLETYPE_RIPPLE_DECAY )
    v11 = (float)((float)((float)rippleFade2 + (float)rippleFade1) * (float)rippleWavelength);
  else
    v11 = (float)(idMath::TWO_PI / this->rippleFrequency);
  this->maxDist = v11;
  if ( rippleType != RIPPLETYPE_RIPPLE_DECAY )
    this->rippleSpeed = idMath::TWO_PI;
  value = this->waterSurface.spawnId.value;
  p_waterSurface = &this->waterSurface;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v14 = (idDynamicWaterEntity *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v14 != nullptr && idDynamicWaterEntity::CastTo(c: v14) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_waterSurface->spawnId.value & 0x1FFF] == p_waterSurface->spawnId.value >> 13
        && (v15 = (idDynamicWaterEntity *)gameLocal->entities.ptr[p_waterSurface->spawnId.value & 0x1FFF]) != nullptr )
      {
        v16 = idDynamicWaterEntity::CastTo(c: v15);
      }
      else
      {
        v16 = nullptr;
      }
      if ( (unsigned __int8)idClass::IsType(this: v16, superclass: &idDynamicWaterEntity::Type) == 0 )
      {
        v17 = &this->waterSurface;
        data = this->name.data;
        Entity = idEntityPtr<idDynamicWaterEntity>::GetEntity(this: v17);
        idLib::Warning(fmt: "Invalid entity %s specified to ripple emitter %s", Entity->name.data, data);
      }
    }
  }
}


// ========================================================================
// ?Think@idWaterRippleEmitter@@UAAXXZ
// EA  : 0x82D4DB88
// RVA : 0x00D4DB88
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idWaterRippleEmitter::Think(idWaterRippleEmitter *this)
{
  int value; // r10
  idDynamicWaterEntity *v3; // r3
  idDynamicWaterEntity *Entity; // r3
  idDynamicWaterEntity *v5; // r30
  idPhysics *Physics; // r3
  double rippleRadius; // fp31
  double rippleAmplitude; // fp30
  int v9; // r6
  const idRenderModel *v10; // r5
  const idVec3 *v11; // r3
  idRenderModelWaterSurface *waterModel; // r7
  int GameMs; // r3
  int v18; // r2 OVERLAPPED
  double v19; // fp31
  double v20; // fp30
  idPhysics *v21; // r3
  double rippleDecay2; // fp31
  double rippleDecay1; // fp29
  double rippleFrequency; // fp28
  double v25; // fp27
  const idVec3 *v26; // r3
  idRenderModelWaterSurface *v27; // r5
  idPhysics *v28; // r3
  double v29; // fp30
  double ripplePhase; // fp29
  double v31; // fp28
  double v32; // fp27
  const idVec3 *v33; // r3
  unsigned int v34; // r5
  int v35; // r3

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    value = this->waterSurface.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v3 = (idDynamicWaterEntity *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v3 != nullptr && idDynamicWaterEntity::CastTo(c: v3) != nullptr )
      {
        Entity = idEntityPtr<idDynamicWaterEntity>::GetEntity(this: &this->waterSurface);
        if ( (unsigned __int8)idClass::IsType(this: Entity, superclass: &idDynamicWaterEntity::Type) != 0 )
        {
          v5 = idEntityPtr<idDynamicWaterEntity>::GetEntity(this: &this->waterSurface);
          if ( this->rippleType == RIPPLETYPE_RIPPLE_DISTURBANCE )
          {
            Physics = idEntity::GetPhysics(this);
            rippleRadius = this->rippleRadius;
            rippleAmplitude = this->rippleAmplitude;
            v11 = Physics->GetOrigin(this: Physics, a2: 0);
            waterModel = v5->waterModel;
            if ( waterModel != nullptr && waterModel->waterSim != nullptr && (*((_BYTE *)&v5->flags + 1) & 0x80) == 0 )
            {
              _FP12 = (float)(v5->waterInteraction.maxRadius - (float)rippleRadius);
              _FP11 = (float)(v5->waterInteraction.maxMagnitude - (float)rippleAmplitude);
              __asm
              {
                fsel      f2, f12, f31, f0# radius
                fsel      f1, f11, f30, f13# mag
              }
              idWaterSurfaceSim::AddRipple(
                this: waterModel->waterSim,
                pos: v11,
                mag: _FP1,
                radius: _FP2,
                rmod: v10,
                a6: v9,
                a7: waterModel);
            }
          }
          else
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v19 = (float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001);
            v20 = (float)((float)((float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001) - this->startTime)
                        * this->rippleSpeed);
            if ( v20 < 0.0 || v20 >= this->maxDist )
            {
              if ( v20 > (float)(this->maxDist + this->restartTime) )
              {
                this->startTime = (float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001;
                v34 = 1664525 * this->rnd.seed + 1013904223;
                v35 = (v34 >> 10) & 0x7FFF;
                this->rnd.seed = v34;
                this->restartTime = (float)((float)*(__int64 *)(&v18 - 1) * idMath::TWO_PI) * (float)0.000030518509;
              }
            }
            else if ( this->rippleType == RIPPLETYPE_RIPPLE_DECAY )
            {
              v21 = idEntity::GetPhysics(this);
              rippleDecay2 = this->rippleDecay2;
              rippleDecay1 = this->rippleDecay1;
              rippleFrequency = this->rippleFrequency;
              v25 = this->rippleAmplitude;
              v26 = v21->GetOrigin(this: v21, a2: 0);
              v27 = v5->waterModel;
              if ( v27 != nullptr && v27->waterSim != nullptr && (*((_BYTE *)&v5->flags + 1) & 0x80) == 0 )
                idWaterSurfaceSim::AddFancyRipple(
                  this: v27->waterSim,
                  pos: v26,
                  rmod: v27,
                  amp: v25,
                  freq: rippleFrequency,
                  fade1: rippleDecay1,
                  fade2: rippleDecay2,
                  currDist: v20);
            }
            else
            {
              v28 = idEntity::GetPhysics(this);
              v29 = this->rippleRadius;
              ripplePhase = this->ripplePhase;
              v31 = this->rippleAmplitude;
              v32 = (float)(this->rippleFrequency * idMath::TWO_PI);
              v33 = v28->GetOrigin(this: v28, a2: 0);
              idDynamicWaterEntity::AddRipple(
                this: v5,
                pos: v33,
                amp: v31,
                frequency: (float)((float)v32 * (float)v19),
                phase: ripplePhase,
                radius: v29);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?Think@idStaticWaterEntity@@UAAXXZ
// EA  : 0x82D4DE88
// RVA : 0x00D4DE88
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idStaticWaterEntity::Think(idStaticWaterEntity *this)
{
  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idWaterEntity::Think(this);
    if ( (this->thinkFlags & 1) != 0 )
      idStaticWaterEntity::UpdateWaves(this);
  }
}


// ========================================================================
// ?Spawn@idDynamicWaterEntity@@QAAXXZ
// EA  : 0x82D4DEE8
// RVA : 0x00D4DEE8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::Spawn(idDynamicWaterEntity *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  int *v4; // r10
  _DWORD *v5; // r11
  int i; // ctr
  float *angleY; // r28
  float *p_angle; // r29
  int j; // r27
  const char *v10; // r3
  idRenderModel *v11; // r3
  __int128 v12; // r5
  char *data; // r29
  __int64 v14; // r9
  double speed; // fp3
  int v16; // r7
  const char *v17; // r6
  idPhysics *v18; // r3
  idBounds *v19; // r3
  int v24; // [sp+4Ch] [-144h] BYREF
  idBounds v25; // [sp+50h] [-140h] BYREF
  __int64 v26; // [sp+68h] [-128h]
  idStr v27; // [sp+70h] [-120h] BYREF
  idWaterSurfaceSim v28; // [sp+90h] [-100h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (int)Physics->GetBounds(this: Physics, a2: -1);
  v4 = &v24;
  v5 = (_DWORD *)(v3 - 4);
  for ( i = 6; i != 0; --i )
    *++v4 = *++v5;
  if ( v25.b[0].x < (double)v25.b[1].x
    && v25.b[0].y < (double)v25.b[1].y
    && v25.b[0].z < (double)v25.b[1].z
    && (float)((float)((float)(v25.b[1].z - v25.b[0].z) * (float)(v25.b[1].y - v25.b[0].y))
             * (float)(v25.b[1].x - v25.b[0].x)) >= 0.0099999998 )
  {
    angleY = this->angleY;
    p_angle = &this->waveParms[0].angle;
    for ( j = 4; j != 0; --j )
    {
      if ( *((_BYTE *)p_angle - 16) != 0 )
      {
        *(angleY - 4) = idMath::Cos16(a: (float)(*p_angle * idMath::M_DEG2RAD));
        *angleY = idMath::Sin16(a: (float)(*p_angle * idMath::M_DEG2RAD));
        angleY[4] = idMath::TWO_PI / *(p_angle - 2);
      }
      ++angleY;
      p_angle += 6;
    }
    if ( this->material == nullptr )
      this->material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                             this: &idMaterial::resourceList,
                                             name: "_default",
                                             makeDefault: true);
    v10 = clientGame->renderWorld->GetName(this: clientGame->renderWorld);
    idStr::idStr(this: &v27, text: v10);
    idStr::Append(this: &v27, text: "/");
    idStr::Append(this: &v27, text: this->name.data);
    idStr::Append(this: &v27, text: "_surface");
    idStr::SetFileExtension(this: &v27, extension: "watersurf");
    v11 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: v27.data, a3: 0, a4: -1);
    this->waterModel = (idRenderModelWaterSurface *)_RTDynamicCast(
                                                      inptr: v11,
                                                      VfDelta: 0,
                                                      SrcType: &idRenderModel `RTTI Type Descriptor',
                                                      TargetType: &idRenderModelWaterSurface `RTTI Type Descriptor',
                                                      isReference: 0);
    *(_QWORD *)((char *)&v12 + 4) = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMsPerFrame)(
                                      a1: gameLocal,
                                      a2: 1);
    LODWORD(v12) = DWORD1(v12);
    v26 = v12;
    idWaterSurfaceSim::idWaterSurfaceSim(
      this: &v28,
      bounds: &v25,
      s: this->spacing,
      damping: this->damping,
      speed: this->speed,
      timeStep: (float)((float)(__int64)v12 * (float)0.001));
    if ( (unsigned __int8)idRenderModelWaterSurface::CheckValid(
                            this: this->waterModel,
                            _waterSim: &v28,
                            waterSimBounds: &v25) == 0
      || g_waterForceGenerate.valueInteger != 0 )
    {
      data = this->imgName.data;
      LODWORD(v14) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      speed = this->speed;
      v26 = v14;
      idRenderModelWaterSurface::BuildWaterModel(
        this: this->waterModel,
        mtr: this->material,
        waterBounds: &v25,
        spacing: this->spacing,
        damping: this->damping,
        speed,
        timeStep: (float)((float)v14 * (float)0.001),
        imgName: v17,
        a9: v16,
        a10: SHIDWORD(v14),
        a11: v14,
        a12: data);
    }
    this->SetModel(this, a2: this->waterModel);
    v18 = idEntity::GetPhysics(this);
    v19 = (idBounds *)v18->GetAbsBounds(this: v18, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v19);
    _FP4 = (float)((float)(v25.b[1].x - v25.b[0].x) - (float)(v25.b[1].y - v25.b[0].y));
    __asm { fsel      f3, f4, f10, f8 }
    _FP2 = (float)((float)_FP3 - (float)(v25.b[1].z - v25.b[0].z));
    __asm { fsel      f1, f2, f3, f5 }
    this->allowDormancy = _FP1 < 1024.0;
    idWaterSurfaceSim::~idWaterSurfaceSim(this: &v28);
    idStr::FreeData(this: &v27);
  }
  else
  {
    idLib::Warning(fmt: "WARNING: Water entity %s has invalid physics bounds, failed to create", this->name.data);
  }
}


// ========================================================================
// __unwind$490324_0
// EA  : 0x82D4E254
// RVA : 0x00D4E254
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_490324_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$490325
// EA  : 0x82D4E27C
// RVA : 0x00D4E27C
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_490325()
{
  int v0; // r12

  idWaterSurfaceSim::~idWaterSurfaceSim(this: (idWaterSurfaceSim *)(v0 - 400 + 144));
}


// ========================================================================
// ?UpdateModifiedProperties@idDynamicWaterEntity@@UAAXXZ
// EA  : 0x82D4E2B0
// RVA : 0x00D4E2B0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::UpdateModifiedProperties(idDynamicWaterEntity *this)
{
  const char *v2; // r3
  idRenderModel *v3; // r3
  idRenderModelWaterSurface *v4; // r3
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  idEntity::FreeRenderModel(this);
  v2 = clientGame->renderWorld->GetName(this: clientGame->renderWorld);
  idStr::idStr(this: v5, text: v2);
  idStr::Append(this: v5, text: "/");
  idStr::Append(this: v5, text: this->name.data);
  idStr::Append(this: v5, text: "_surface");
  idStr::SetFileExtension(this: v5, extension: "watersurf");
  v3 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: v5[0].data, a3: 0, a4: -1);
  v4 = (idRenderModelWaterSurface *)_RTDynamicCast(
                                      inptr: v3,
                                      VfDelta: 0,
                                      SrcType: &idRenderModel `RTTI Type Descriptor',
                                      TargetType: &idRenderModelWaterSurface `RTTI Type Descriptor',
                                      isReference: 0);
  this->waterModel = v4;
  this->SetModel(this, a2: v4);
  idStr::FreeData(this: v5);
}


// ========================================================================
// __unwind$490743_0
// EA  : 0x82D4E398
// RVA : 0x00D4E398
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_490743_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??1idWaterEntity@@UAA@XZ
// EA  : 0x82D4E3C8
// RVA : 0x00D4E3C8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idWaterEntity::~idWaterEntity(idWaterEntity *this)
{
  this->__vftable = (idWaterEntity_vtbl *)&idWaterEntity::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->buoyancy);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$490969
// EA  : 0x82D4E41C
// RVA : 0x00D4E41C
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_490969()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDynamicWaterEntity@@UAA@XZ
// EA  : 0x82D4E450
// RVA : 0x00D4E450
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::~idDynamicWaterEntity(idDynamicWaterEntity *this)
{
  this->__vftable = (idDynamicWaterEntity_vtbl *)&idDynamicWaterEntity::`vftable';
  idStr::FreeData(this: &this->imgName);
  idWaterEntity::~idWaterEntity(this);
}


// ========================================================================
// __unwind$491008
// EA  : 0x82D4E4A4
// RVA : 0x00D4E4A4
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_491008()
{
  int v0; // r12

  idWaterEntity::~idWaterEntity(this: *(idWaterEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idWaterRippleEmitter@@QAA@XZ
// EA  : 0x82D4E4D0
// RVA : 0x00D4E4D0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

idWaterRippleEmitter *__fastcall idWaterRippleEmitter::idWaterRippleEmitter(idWaterRippleEmitter *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->__vftable = (idWaterRippleEmitter_vtbl *)&idWaterRippleEmitter::`vftable';
  this->rippleAmplitude = 1.0;
  this->startOff = false;
  this->rippleWavelength = 6.2800002;
  this->cycleTrigger = false;
  this->ripplePhase = 0.0;
  this->rippleType = RIPPLETYPE_RIPPLE;
  this->rippleSpeed = 20.0;
  this->rippleRadius = 15.0;
  this->rippleFade1 = 4.0;
  this->rippleFade2 = 8.0;
  this->waterSurface.spawnId.value = 0x1FFF;
  this->sndRipple = nullptr;
  this->rnd.seed = 0;
  this->rippleFrequency = 1.0;
  this->rippleDecay1 = 0.0;
  this->hidden = false;
  this->rippleDecay2 = 0.0;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->startTime = 0.0;
  this->restartTime = 0.0;
  this->maxDist = 0.0;
  return this;
}


// ========================================================================
// ??0idWaterEntity@@QAA@XZ
// EA  : 0x82D4E5A0
// RVA : 0x00D4E5A0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

idWaterEntity *__fastcall idWaterEntity::idWaterEntity(idWaterEntity *this)
{
  int v2; // ctr
  __int16 *p_granularity; // r11
  char flags; // r11

  idEntity::idEntity(this);
  this->density = 0.0040000002;
  this->__vftable = (idWaterEntity_vtbl *)&idWaterEntity::`vftable';
  this->viscosity = 1.0;
  this->current.x = 0.0;
  this->current.y = 0.0;
  this->current.z = 0.0;
  this->damage = nullptr;
  this->loot.spawnId.value = 0x1FFF;
  this->envWaterEffects = nullptr;
  this->damageDecl = nullptr;
  v2 = 128;
  this->surfTypeOverride = SURFTYPE_LIQUID;
  this->buoyancy.buoyantClipModels.num = 0;
  p_granularity = &this->buoyancy.buoyantClipModels.granularity;
  this->buoyancy.buoyantClipModels.list = this->buoyancy.buoyantClipModels.staticList;
  this->buoyancy.buoyantClipModels.size = 128;
  this->buoyancy.buoyantClipModels.granularity = 1;
  this->buoyancy.buoyantClipModels.memTag = 5;
  this->buoyancy.buoyantClipModels.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = -1;
    p_granularity += 4;
    *(_DWORD *)p_granularity = -1;
    --v2;
  }
  while ( v2 != 0 );
  flags = (char)this->flags;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  *(_BYTE *)&this->flags = flags | 0x40;
  return this;
}


// ========================================================================
// ??0idStaticWaterEntity@@QAA@XZ
// EA  : 0x82D4E6E8
// RVA : 0x00D4E6E8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

idStaticWaterEntity *__fastcall idStaticWaterEntity::idStaticWaterEntity(idStaticWaterEntity *this)
{
  char flags; // r9

  idWaterEntity::idWaterEntity(this);
  this->__vftable = (idStaticWaterEntity_vtbl *)&idStaticWaterEntity::`vftable';
  this->waveRandom.seed = 0;
  flags = (char)this->flags;
  this->waveParms.lifeMin = 16.0;
  this->waveParms.lifeMax = 64.0;
  this->waveParms.fade = 0.40000001;
  this->rp_waveDirX = nullptr;
  this->rp_waveDirY = nullptr;
  this->rp_waveFreq = nullptr;
  this->rp_waveAmp = nullptr;
  this->rp_wavePhase = nullptr;
  *(_BYTE *)&this->flags = flags | 0x40;
  this->waveProperties[0].amplitude = 0.30000001;
  this->waveProperties[0].waveLength = 2.0;
  this->waveProperties[0].speed = 0.5;
  this->waveProperties[0].useWave = false;
  this->waveProperties[0].angle = 30.0;
  this->waveProperties[1].useWave = false;
  this->waveProperties[1].amplitude = 0.30000001;
  this->waveProperties[2].useWave = false;
  this->waveProperties[1].waveLength = 2.0;
  this->waveProperties[3].useWave = false;
  this->waveProperties[1].speed = 0.5;
  this->waveProperties[1].angle = 30.0;
  this->waveProperties[2].amplitude = 0.30000001;
  this->waveProperties[2].waveLength = 2.0;
  this->waveProperties[2].speed = 0.5;
  this->waveProperties[2].angle = 30.0;
  this->waveProperties[3].amplitude = 0.30000001;
  this->waveProperties[3].waveLength = 2.0;
  this->waveProperties[3].speed = 0.5;
  this->waveProperties[3].angle = 30.0;
  memset(Dst: this->waves, Val: 0, Size: sizeof(this->waves));
  this->rp_waveDirX = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "waterWaveDirX",
                                                  makeDefault: true);
  this->rp_waveDirY = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "waterWaveDirY",
                                                  makeDefault: true);
  this->rp_waveFreq = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "waterWaveFreq",
                                                  makeDefault: true);
  this->rp_waveAmp = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "waterWaveAmp",
                                                 makeDefault: true);
  this->rp_wavePhase = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "waterWavePhase",
                                                   makeDefault: true);
  return this;
}


// ========================================================================
// __unwind$491303
// EA  : 0x82D4E870
// RVA : 0x00D4E870
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_491303()
{
  int v0; // r12

  idWaterEntity::~idWaterEntity(this: *(idWaterEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idDynamicWaterEntity@@QAA@XZ
// EA  : 0x82D4E900
// RVA : 0x00D4E900
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

idDynamicWaterEntity *__fastcall idDynamicWaterEntity::idDynamicWaterEntity(idDynamicWaterEntity *this)
{
  int v2; // ctr
  float *v3; // r9
  float *p_disturbanceAmount; // r10

  idWaterEntity::idWaterEntity(this);
  this->spacing = 8.0;
  this->__vftable = (idDynamicWaterEntity_vtbl *)&idDynamicWaterEntity::`vftable';
  this->damping = 0.30000001;
  this->speed = 50.0;
  this->material = nullptr;
  this->imgName.data = this->imgName.baseBuffer;
  this->imgName.allocedAndFlag = 20;
  this->imgName.len = 0;
  this->imgName.baseBuffer[0] = 0;
  this->allowDormancy = true;
  v2 = 4;
  this->disturbanceType = DISTURBANCE_RANDOM_DROPS;
  this->numDisturbances = 0;
  *(_BYTE *)&this->flags |= 0x40u;
  this->waterModel = nullptr;
  this->waterInteraction.maxMagnitude = 15.0;
  this->nextWaterIlluminationTest = 0;
  this->waterInteraction.maxRadius = 25.0;
  v3 = &this->angleY[3];
  p_disturbanceAmount = &this->disturbanceAmount;
  this->disturbanceAmount = 40.0;
  do
  {
    p_disturbanceAmount[2] = 5.0;
    *((_BYTE *)p_disturbanceAmount + 4) = 0;
    p_disturbanceAmount[3] = 50.0;
    p_disturbanceAmount[4] = 20.0;
    p_disturbanceAmount[5] = 40.0;
    p_disturbanceAmount += 6;
    *p_disturbanceAmount = 1.0;
    *(v3 - 7) = 0.0;
    *(v3 - 3) = 0.0;
    *++v3 = 0.0;
    --v2;
  }
  while ( v2 != 0 );
  this->waterIllumination[0].pos = vec3_origin;
  this->waterIllumination[0].startTime = 0;
  this->waterIllumination[0].radius = 0.0;
  this->waterIllumination[0].endTime = 0;
  this->waterIllumination[1].pos = vec3_origin;
  this->waterIllumination[1].startTime = 0;
  this->waterIllumination[1].radius = 0.0;
  this->waterIllumination[1].endTime = 0;
  this->waterIllumination[2].pos = vec3_origin;
  this->waterIllumination[2].startTime = 0;
  this->waterIllumination[2].radius = 0.0;
  this->waterIllumination[2].endTime = 0;
  this->waterIllumination[3].pos = vec3_origin;
  this->waterIllumination[3].startTime = 0;
  this->waterIllumination[3].radius = 0.0;
  this->waterIllumination[3].endTime = 0;
  return this;
}


// ========================================================================
// ?UpdateWater@idDynamicWaterEntity@@AAAXXZ
// EA  : 0x82D4EB28
// RVA : 0x00D4EB28
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::UpdateWater(idDynamicWaterEntity *this)
{
  idRenderModelWaterSurface *waterModel; // r11
  idWaterSurfaceSim *waterSim; // r24
  unsigned __int64 v4; // r6
  const char *v5; // r7
  __int64 v6; // r9
  idDynamicWaterEntity::idDisturbanceType_t disturbanceType; // r11
  double v8; // fp29
  __int64 v9; // r9
  unsigned int v10; // r3
  double disturbanceAmount; // fp12
  double v12; // fp10
  unsigned int v13; // r6
  unsigned int width; // r27
  unsigned int height; // r26
  double v16; // fp30
  double v17; // fp31
  __int128 v18; // r5
  int v19; // r28
  unsigned int v20; // r27
  unsigned int v21; // r26
  idClientGame *v22; // r11
  unsigned int v23; // r5
  unsigned int v24; // r8
  double v25; // fp31
  double v26; // fp30
  idLinkList<idFuncWind> *next; // r11
  idVec3 *owner; // r4
  float *CurrentWindDirection; // r3
  float *p_speed; // r30
  float *angleY; // r29
  int i; // r28
  double v33; // fp12
  double v34; // fp11
  double v35; // fp1
  double v36; // fp9
  double v37; // fp3
  double v38; // fp4
  float *p_radius; // r30
  int j; // r29
  int GameMs; // r3
  int v42; // r11
  __int128 v43; // r9
  double v44; // fp0
  int valueInteger; // r11
  idRenderModelWaterSurface *v46; // r11
  const idVec3 *p_deferredOrigin; // r6
  idPhysics *Physics; // r30
  idPhysics *v49; // r29
  idPhysics *v50; // r3
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v52; // r30
  int v53; // r28
  int v54; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v56; // r30
  int v57; // r3
  __int64 totalTicks; // r11
  __int64 v59; // r9
  idVec2 v60; // [sp+50h] [-B0h] BYREF
  idPLogScope v61; // [sp+58h] [-A8h] BYREF
  __int64 v62; // [sp+60h] [-A0h]
  __int64 v63; // [sp+68h] [-98h]
  __int64 v64; // [sp+70h] [-90h] BYREF

  waterModel = this->waterModel;
  if ( waterModel != nullptr )
  {
    waterSim = waterModel->waterSim;
    if ( waterSim != nullptr && g_skipWaterSim.valueInteger == 0 )
    {
      RD_EventBegin(name: "idDynamicWaterEntity::UpdateWater");
      LODWORD(v4) = "idDynamicWaterEntity::UpdateWater";
      HIDWORD(v4) = 2;
      idPLogScope::idPLogScope(this: &v61, pl: &::pLog, gMask: v4, label: v5);
      waterSim->visible = idRenderModel::IsRendered(this: this->waterModel);
      if ( g_skipWaterSim.valueInteger == 0 )
      {
        LODWORD(v6) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        disturbanceType = this->disturbanceType;
        v62 = v6;
        v8 = (float)((float)v6 * (float)0.001);
        if ( disturbanceType != DISTURBANCE_RANDOM_DROPS )
        {
          if ( disturbanceType == DISTURBANCE_WAVES )
          {
            v25 = 1.0;
            v26 = 0.0;
            next = gameLocal->globalWindEntities.next;
            if ( next != nullptr && next != gameLocal->globalWindEntities.head )
            {
              owner = (idVec3 *)next->owner;
              if ( owner != nullptr )
              {
                CurrentWindDirection = (float *)idFuncWind::GetCurrentWindDirection(
                                                  this: (idFuncWind *)&v64,
                                                  result: owner);
                v25 = *CurrentWindDirection;
                v26 = CurrentWindDirection[1];
              }
            }
            p_speed = &this->waveParms[0].speed;
            angleY = this->angleY;
            for ( i = 4; i != 0; --i )
            {
              if ( *((_BYTE *)p_speed - 12) != 0 )
              {
                v33 = *(angleY - 4);
                v34 = (float)(*angleY * (float)v25);
                v35 = angleY[4];
                v36 = (float)(*p_speed * angleY[4]);
                v37 = *(p_speed - 2);
                v38 = p_speed[2];
                v60.x = (float)(*(angleY - 4) * (float)v25) + (float)(*angleY * (float)v26);
                v60.y = (float)((float)v33 * (float)v26) - (float)v34;
                idWaterSurfaceSim::AddWave(
                  this: waterSim,
                  waveDir: &v60,
                  freq: v35,
                  phase: (float)((float)v36 * (float)v8),
                  amp: v37,
                  waveExp: v38);
              }
              ++angleY;
              p_speed += 6;
            }
          }
        }
        else
        {
          HIDWORD(v9) = &idEventDef::eventDefList[3154];
          v10 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v10;
          disturbanceAmount = this->disturbanceAmount;
          LODWORD(v9) = (v10 >> 10) & 0x7FFF;
          v62 = v9;
          v12 = (double)v9;
          v13 = 1664525 * clientGame->random.seed;
          clientGame->random.seed = v13 + 1013904223;
          LODWORD(v9) = ((v13 + 1013904223) >> 10) & 0x7FFF;
          width = waterSim->width;
          height = waterSim->height;
          v62 = v9;
          v16 = (float)((float)((float)((float)v12 * (float)0.000061037019) - (float)1.0) * (float)disturbanceAmount);
          v17 = (float)((float)v9 * (float)0.00061037019);
          DWORD1(v18) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
          LODWORD(v18) = DWORD1(v18);
          DWORD2(v18) = this->numDisturbances;
          LODWORD(v62) = (int)(float)((float)((float)*(__int64 *)((char *)&v18 + 4) * (float)(__int64)v18) * (float)0.001);
          v19 = v62;
          if ( (int)v62 > 0 )
          {
            v20 = width - 2;
            v21 = height - 2;
            do
            {
              v22 = clientGame;
              __twllei(v20, 0);
              __twllei(v21, 0);
              v22->random.seed = 1664525 * v22->random.seed + 1013904223;
              v23 = (v22->random.seed >> 10) & 0x7FFF;
              v24 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v24;
              idWaterSurfaceSim::AddDrop(
                this: waterSim,
                xpos: v23 % v20 + 1,
                ypos: ((v24 >> 10) & 0x7FFF) % v21 + 1,
                radius: v17,
                mag: v16);
              --v19;
            }
            while ( v19 != 0 );
          }
        }
        idWaterSurfaceSim::ClearRadiusEffects(this: waterSim);
        p_radius = &this->waterIllumination[0].radius;
        for ( j = 4; j != 0; --j )
        {
          if ( *((_DWORD *)p_radius + 2) != 0 )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v42 = *((_DWORD *)p_radius + 2);
            if ( GameMs >= v42 )
            {
              if ( v42 != 0 )
              {
                idWaterSurfaceSim::ApplyRadiusEffect(
                  this: waterSim,
                  pos: (const idVec3 *)p_radius - 1,
                  rmod: this->waterModel,
                  radius: *p_radius,
                  fade: 0.0);
                p_radius[2] = 0.0;
              }
            }
            else
            {
              LODWORD(v43) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v62 = *(_QWORD *)(p_radius + 1);
              *(_QWORD *)((char *)&v43 + 4) = v62;
              v63 = v43;
              v64 = *(_QWORD *)&v43;
              v44 = (float)((float)((float)(__int64)v43 - (float)*(__int64 *)&v43)
                          / (float)((float)v62 - (float)*(__int64 *)&v43));
              if ( v44 >= 0.0 )
              {
                if ( v44 > 1.0 )
                  v44 = 1.0;
              }
              else
              {
                v44 = 0.0;
              }
              idWaterSurfaceSim::ApplyRadiusEffect(
                this: waterSim,
                pos: (const idVec3 *)p_radius - 1,
                rmod: this->waterModel,
                radius: *p_radius,
                fade: (float)((float)1.0 - (float)v44));
            }
          }
          p_radius += 6;
        }
      }
      valueInteger = g_showWaterDebug.valueInteger;
      if ( g_showWaterDebug.valueInteger == 1 )
      {
        v46 = this->waterModel;
        p_deferredOrigin = &v46->deferredOrigin;
        if ( !v46->useDeferredPosition )
          p_deferredOrigin = &v46->g.origin;
        clientGame->renderWorld->DebugBounds(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idBounds *)v46->surfaces.list->geometry,
          a4: p_deferredOrigin,
          a5: 0,
          a6: false);
        valueInteger = g_showWaterDebug.valueInteger;
      }
      if ( valueInteger == 2 )
      {
        Physics = idEntity::GetPhysics(this);
        v49 = idEntity::GetPhysics(this);
        v50 = Physics;
        GetOrigin = Physics->GetOrigin;
        v52 = clientGame->renderWorld->__vftable;
        v53 = (int)GetOrigin(this: v50, a2: 0);
        v54 = (int)v49->GetBounds(this: v49, a2: -1);
        v52->DebugBounds(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idBounds *)v54,
          a4: (const idVec3 *)v53,
          a5: 0,
          a6: false);
      }
      if ( v61.logIndex >= 0 )
      {
        pLog = v61.pLog;
        v56 = &v61.pLog->logEntries.list[v61.logIndex];
        v57 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v56->totalTicks;
        HIDWORD(totalTicks) = v56->parent;
        LODWORD(v59) = v57 - totalTicks;
        v56->totalTicks = v59;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
    }
  }
}


// ========================================================================
// __unwind$491503
// EA  : 0x82D4F080
// RVA : 0x00D4F080
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_491503()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 124));
}


// ========================================================================
// __unwind$491504
// EA  : 0x82D4F0A8
// RVA : 0x00D4F0A8
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void _unwind_491504()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?Think@idDynamicWaterEntity@@UAAXXZ
// EA  : 0x82D4F0D0
// RVA : 0x00D4F0D0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __fastcall idDynamicWaterEntity::Think(idDynamicWaterEntity *this)
{
  if ( !this->allowDormancy || (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idWaterEntity::Think(this);
    if ( (this->thinkFlags & 1) != 0 )
    {
      idDynamicWaterEntity::UpdateWater(this);
      idEntity::UpdateVisuals(this);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_showWaterDebug''
// EA  : 0x8337FF20
// RVA : 0x0137FF20
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showWaterDebug__()
{
  idCVar::idCVar(
    this: &g_showWaterDebug,
    name: "g_showWaterDebug",
    value: "0",
    flags: 2,
    description: "render water surface debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showWaterDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_waterForceGenerate''
// EA  : 0x8337FF78
// RVA : 0x0137FF78
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_waterForceGenerate__()
{
  idCVar::idCVar(
    this: &g_waterForceGenerate,
    name: "g_waterForceGenerate",
    value: "0",
    flags: 1,
    description: "force water surfaces to regenerate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_waterForceGenerate__);
}


// ========================================================================
// `dynamic initializer for 'g_skipWaterSim''
// EA  : 0x8337FFD0
// RVA : 0x0137FFD0
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_skipWaterSim__()
{
  idCVar::idCVar(
    this: &g_skipWaterSim,
    name: "g_skipWaterSim",
    value: "0",
    flags: 2,
    description: "skips water surface simulation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_skipWaterSim__);
}


// ========================================================================
// `dynamic initializer for 'reloadWater_v''
// EA  : 0x83380028
// RVA : 0x01380028
// PDB : w:\tech5\tungsten\game\entities\waterentity.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reloadWater_v__()
{
  return idCommandLink::idCommandLink(
           this: &reloadWater_v,
           cmdName: "reloadWater",
           function: reloadWater_f,
           description: "reloads all loaded dynamic water entities",
           argCompletion: nullptr);
}

