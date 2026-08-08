
// ========================================================================
// ?Spawn@idExplodable@@QAAXXZ
// EA  : 0x82C49F60
// RVA : 0x00C49F60
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void __fastcall idExplodable::Spawn(idExplodable *this)
{
  idPhysics *Physics; // r3
  idVec3 *p_offset; // r27
  idClipModel *v4; // r30
  float *p_z; // r10
  int v6; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idRenderModelInfo *v8; // r28
  float *model; // r11
  int v10; // r9
  double v11; // fp0
  double v12; // fp12
  double v13; // fp10
  double v14; // fp13
  double v15; // fp11
  double v16; // fp9
  float y; // r10
  float z; // r9
  double v19; // fp8
  double v20; // fp11
  float *p_x; // r11
  int i; // ctr
  double v23; // fp8
  double v24; // fp7
  double v25; // fp5
  double v26; // fp4
  double v27; // fp3
  idClipModel *v28; // r3
  idPhysics *v29; // r3
  float x; // [sp+50h] [-670h] BYREF
  float v31; // [sp+54h] [-66Ch]
  float v32; // [sp+58h] [-668h]
  int p_referenceBounds; // [sp+5Ch] [-664h]
  idBounds v34; // [sp+60h] [-660h] BYREF
  idTraceModel v35; // [sp+80h] [-640h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 128, a3: -1);
  if ( this->clipModelInfo.type == CLIPMODEL_BOX )
  {
    p_offset = &this->clipModelInfo.offset;
    if ( (float)((float)(this->clipModelInfo.offset.z * this->clipModelInfo.offset.z)
               + (float)((float)(this->clipModelInfo.offset.x * this->clipModelInfo.offset.x)
                       + (float)(this->clipModelInfo.offset.y * this->clipModelInfo.offset.y))) > 0.0 )
    {
      v35.offset.x = 0.0;
      v35.offset.y = 0.0;
      v4 = nullptr;
      p_z = &v35.offset.z;
      v35.offset.z = 0.0;
      v6 = 6;
      memset(&v35.type, 0, 20);
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      do
      {
        ++p_viewNoteMutex;
        *++p_z = *(float *)&p_viewNoteMutex->handle;
        --v6;
      }
      while ( v6 != 0 );
      v35.radius = 0.0;
      v35.isConvex = false;
      v35.pad[2] = 0;
      v35.pad[1] = 0;
      v35.pad[0] = 0;
      v8 = this->GetRenderModelInfo(this);
      if ( ((LODWORD(this->clipModelInfo.size.z)
           | LODWORD(this->clipModelInfo.size.y)
           | LODWORD(this->clipModelInfo.size.x))
          & 0x7FFFFFFF) == 0
        && this->GetRenderModelInfo(this) != nullptr
        && this->GetRenderModelInfo(this)->model != nullptr )
      {
        model = (float *)v8->model;
        v10 = (int)&v8->model->referenceBounds.b[1];
        p_referenceBounds = (int)&v8->model->referenceBounds;
        v11 = model[23];
        v34.b[0].x = model[23];
        p_referenceBounds = v10;
        v12 = model[24];
        v34.b[0].y = model[24];
        v13 = model[25];
        v34.b[0].z = model[25];
        v14 = model[26];
        v34.b[1].x = model[26];
        v15 = model[27];
        v34.b[1].y = model[27];
        v16 = model[28];
      }
      else
      {
        y = this->clipModelInfo.size.y;
        z = this->clipModelInfo.size.z;
        x = this->clipModelInfo.size.x;
        v19 = x;
        v31 = y;
        v32 = z;
        if ( x <= 0.0 || (v20 = v31, v31 <= 0.0) || v32 <= 0.0 )
        {
          p_x = &x;
          for ( i = 3; i != 0; --i )
          {
            if ( *p_x <= 0.0 )
              *p_x = 1.0;
            ++p_x;
          }
          v20 = v31;
          v19 = x;
        }
        v16 = v32;
        v13 = 0.0;
        v12 = (float)((float)v20 * (float)-0.5);
        v15 = (float)((float)v20 * (float)0.5);
        v11 = (float)((float)v19 * (float)-0.5);
        v14 = (float)((float)v19 * (float)0.5);
      }
      v23 = p_offset->x;
      v24 = this->clipModelInfo.offset.y;
      v25 = this->clipModelInfo.offset.z;
      v26 = (float)(this->clipModelInfo.offset.y + (float)v12);
      v27 = (float)(this->clipModelInfo.offset.z + (float)v13);
      v34.b[0].x = p_offset->x + (float)v11;
      v34.b[0].y = v26;
      v34.b[0].z = v27;
      v34.b[1].x = (float)v23 + (float)v14;
      v34.b[1].y = (float)v24 + (float)v15;
      v34.b[1].z = (float)v25 + (float)v16;
      idTraceModel::SetupBox(this: &v35, boxBounds: &v34);
      v28 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      p_referenceBounds = (int)v28;
      if ( v28 != nullptr )
        v4 = idClipModel::idClipModel(
               this: v28,
               clip: &clientGame->clip,
               trm: &v35,
               numTraceModels: 1,
               material: this->clipModelInfo.overrideClipMaterial);
      idClipModel::SetContents(this: v4, newContents: 128);
      v29 = idEntity::GetPhysics(this);
      ((void (__fastcall *)(idPhysics *, idClipModel *, double))v29->SetClipModel)(a1: v29, a2: v4, a3: 1.0);
    }
  }
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// __unwind$488518
// EA  : 0x82C4A268
// RVA : 0x00C4A268
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_488518()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1728 + 92), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Explode@idExplodable@@AAAXPAVidEntity@@@Z
// EA  : 0x82C4A298
// RVA : 0x00C4A298
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void __fastcall idExplodable::Explode(idExplodable *this, idExplodable *attacker)
{
  idPhysics *Physics; // r3
  int v5; // r3
  float v6; // r7
  float v7; // r6
  idPhysics *v8; // r3
  int v9; // r3
  char *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  int GameMs; // r30
  idPhysics *v14; // r3
  idPhysics *v15; // r3
  idPresentable *presentable; // r11
  const idDeclDamage *damageDecl; // r7
  idScriptObject *v18; // r3
  idVec3 v19; // [sp+50h] [-1B0h] BYREF
  char v20; // [sp+5Ch] [-1A4h] BYREF
  idMat3 v21; // [sp+60h] [-1A0h] BYREF
  idScriptFunction v22; // [sp+90h] [-170h] BYREF

  Physics = idEntity::GetPhysics(this);
  v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v6 = *(float *)(v5 + 4);
  v7 = *(float *)(v5 + 8);
  v19.x = *(float *)v5;
  v19.y = v6;
  v19.z = v7;
  v8 = idEntity::GetPhysics(this);
  v9 = (int)v8->GetAxis(this: v8, a2: 0);
  v10 = &v20;
  v11 = (_DWORD *)(v9 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v11;
    v10 += 4;
    *(_DWORD *)v10 = *v11;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->SetModel(this, a2: this->brokenModel);
  v14 = idEntity::GetPhysics(this);
  v14->DisableClip(this: v14);
  v15 = idEntity::GetPhysics(this);
  v15->UnlinkClip(this: v15);
  idEntity::UpdateVisuals(this);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_EXPLODE,
    shader: this->soundExplosion,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idFXManager::StartFX(this: &presentable->fxManager, org: &v19, axis: &v21, time: GameMs, startCondition: 187);
  damageDecl = this->damageDecl;
  if ( damageDecl != nullptr )
  {
    if ( attacker == nullptr )
      attacker = this;
    idGameLocal::RadiusDamage(
      this: gameLocal,
      origin: &v19,
      inflictor: this,
      attacker,
      damageDef: damageDecl,
      dmgPower: 1.0);
  }
  v18 = this->GetScriptObject_2(this);
  if ( this->callScriptOnExplode && idScriptObject::HasObject(this: v18) )
  {
    idScriptFunction::idScriptFunction(this: &v22);
    idScriptFunction::SetFunction(
      this: &v22,
      ent: this,
      functionName: "onExplode",
      returnType: ev_void,
      numParms: 1,
      8,
      "attacker");
    if ( idScriptFunction::GetFunction(this: &v22) != nullptr )
    {
      idScriptFunction::SetArg_Entity(this: &v22, argNum: 0, ent: attacker);
      idScriptFunction::CallFunction(this: &v22, defer: true);
    }
  }
}


// ========================================================================
// ?AllocPresentable@idExplodable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C4A4A0
// RVA : 0x00C4A4A0
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

idPresentable *__fastcall idExplodable::AllocPresentable(idExplodable *this, idTreeAnimator *renderModel_)
{
  idPresentable *v4; // r3

  v4 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentable::idPresentable(
             this: v4,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: this->fxDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$488688_1
// EA  : 0x82C4A510
// RVA : 0x00C4A510
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_488688_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Event_DisablePhysics@idExplodable@@AAA?AVeventVoid@@XZ
// EA  : 0x82C4A540
// RVA : 0x00C4A540
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

idExplodable *__fastcall idExplodable::Event_DisablePhysics(idExplodable *this, idEntity *result)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r3

  Physics = idEntity::GetPhysics(this: result);
  Physics->DisableClip(this: Physics);
  v5 = idEntity::GetPhysics(this: result);
  v5->UnlinkClip(this: v5);
  return this;
}


// ========================================================================
// ?Damage@idExplodable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C4AB98
// RVA : 0x00C4AB98
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

float __fastcall idExplodable::Damage(
        idExplodable *this,
        idEntity *inflictor,
        idExplodable *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        idVec3 *trace,
        float *a8)
{
  double v15; // fp1
  idSimpleHealth *p_explodableHealth; // r24
  unsigned __int8 v17; // r11
  int v18; // r26
  int GameMs; // r28
  idPhysics *Physics; // r3
  int v21; // r3
  float v22; // r6
  float v23; // r5
  idPhysics *v24; // r3
  int v25; // r3
  char *v26; // r10
  _DWORD *v27; // r9
  int i; // ctr
  double v29; // fp5
  double v30; // fp4
  double v31; // fp2
  double v32; // fp1
  double v33; // fp30
  int fxLastSteamIndex; // r10
  idPresentable *presentable; // r9
  fxCondition_t v36; // r30
  int v37; // r4
  bool (__fastcall *Damage_Impl)(struct idSimpleHealth *, const float, const bool, float *); // ctr
  float v40[2]; // [sp+50h] [-160h] BYREF
  idVec3 v41; // [sp+58h] [-158h] BYREF
  float v42; // [sp+64h] [-14Ch] BYREF
  idVec3 v43; // [sp+68h] [-148h] BYREF
  idMat3 v44; // [sp+80h] [-130h] BYREF
  char v45; // [sp+ACh] [-104h] BYREF
  float v46; // [sp+B0h] [-100h]
  float v47; // [sp+B4h] [-FCh]
  float v48; // [sp+B8h] [-F8h]
  float v49; // [sp+BCh] [-F4h]
  float v50; // [sp+C0h] [-F0h]
  float v51; // [sp+C4h] [-ECh]
  float v52; // [sp+C8h] [-E8h]
  float v53; // [sp+CCh] [-E4h]
  float v54; // [sp+D0h] [-E0h]
  idMat3 v55[2]; // [sp+D8h] [-D8h] BYREF
  idMat3 v56; // [sp+120h] [-90h] BYREF

  if ( a8 == nullptr )
    goto LABEL_2;
  p_explodableHealth = &this->explodableHealth;
  if ( this->explodableHealth.IsDead_Impl(this: &this->explodableHealth) )
    goto LABEL_2;
  if ( damageDef == nullptr || (v17 = 1, (this->explodingDamageTypes & damageDef->damageTypes) == 0) )
    v17 = 0;
  v18 = v17;
  if ( v17 == 0 || this->steamOnDamage )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idVec3::NormalVectors(this: trace, left: &v41, down: v55[0].mat);
    idVec3::ToMat3(this: &v55[0].mat[2], result: v55);
    Physics = idEntity::GetPhysics(this);
    v21 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v22 = *(float *)(v21 + 4);
    v23 = *(float *)(v21 + 8);
    v41.x = *(float *)v21;
    v41.y = v22;
    v41.z = v23;
    v24 = idEntity::GetPhysics(this);
    v25 = (int)v24->GetAxis(this: v24, a2: 0);
    v26 = &v45;
    v27 = (_DWORD *)(v25 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v27;
      v26 += 4;
      *(_DWORD *)v26 = *v27;
    }
    v29 = (float)(a8[2] - v41.y);
    v30 = (float)(a8[1] - v41.x);
    v31 = (float)(v48 * (float)(a8[3] - v41.z));
    v32 = (float)(v51 * (float)(a8[3] - v41.z));
    v33 = (float)(v54 * (float)(a8[3] - v41.z));
    v44.mat[0].x = v46;
    v44.mat[0].y = v49;
    v44.mat[0].z = v52;
    v44.mat[1].x = v47;
    v44.mat[1].y = v50;
    v44.mat[1].z = v53;
    v44.mat[2].x = v48;
    v44.mat[2].y = v51;
    v44.mat[2].z = v54;
    v43.x = (float)(v46 * (float)v30) + (float)((float)(v47 * (float)v29) + (float)v31);
    v43.y = (float)(v49 * (float)v30) + (float)((float)(v50 * (float)v29) + (float)v32);
    v43.z = (float)(v52 * (float)v30) + (float)((float)(v53 * (float)v29) + (float)v33);
    idMat3::operator*(this: &v56, result: (idMat3 *)&v55[0].mat[2], a: &v44);
    fxLastSteamIndex = this->fxLastSteamIndex;
    presentable = this->presentable;
    v36 = fxSteamConditions[fxLastSteamIndex];
    this->fxLastSteamIndex = (fxLastSteamIndex + 1) % 4;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idFXManager::StartFX(this: &presentable->fxManager, org: &v43, axis: &v56, time: GameMs, startCondition: v36);
  }
  if ( v18 != 0 )
  {
    v40[0] = idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale;
    if ( !p_explodableHealth->IsDead_Impl(this: &this->explodableHealth) )
    {
      if ( attacker != nullptr )
        attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v40);
      else
        idLib::Warning(fmt: "NULL attacker in idExplodable::Damage");
      Damage_Impl = p_explodableHealth->Damage_Impl;
      v42 = 0.0;
      if ( ((unsigned __int8 (__fastcall *)(idSimpleHealth *, int, int, float *, double))Damage_Impl)(
             a1: &this->explodableHealth,
             a2: v37,
             a3: 1,
             a4: &v42,
             a5: v40[0]) != 0 )
        idExplodable::Explode(this, attacker);
    }
    v15 = v40[0];
  }
  else
  {
LABEL_2:
    v15 = 0.0;
  }
  return *((float *)&v15 + 1);
}


// ========================================================================
// ??0idExplodable@@QAA@XZ
// EA  : 0x82C4AFA8
// RVA : 0x00C4AFA8
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

idExplodable *__fastcall idExplodable::idExplodable(idExplodable *this)
{
  idEntity::idEntity(this);
  this->soundExplosion = nullptr;
  this->__vftable = (idExplodable_vtbl *)&idExplodable::`vftable';
  this->impactParticle = nullptr;
  this->brokenModel = nullptr;
  this->damageDecl = nullptr;
  this->fxDecl = nullptr;
  this->explodingDamageTypes = DAMAGETYPE_EXPLOSION;
  this->explodableHealth.components[0].max = 100.0;
  this->explodableHealth.components[0].cur = 100.0;
  this->explodableHealth.components[0].type = SIMPLE_HEALTH_MAX;
  this->explodableHealth.accumulatedDamageFrame = -1;
  this->explodableHealth.killThreshold = 0.0;
  this->explodableHealth.isDead = false;
  this->explodableHealth.killingBlowDamage = 0.0;
  this->explodableHealth.accumulatedFrameDamage = 0.0;
  this->explodableHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
  this->explodableHealth.components[0].cur = 0.0;
  this->explodableHealth.__vftable = (idSimpleHealth_vtbl *)&idSimpleHealth::`vftable';
  this->explodableHealth.components[0].max = 0.0;
  this->steamOnDamage = false;
  this->callScriptOnExplode = false;
  this->fxLastSteamIndex = 0;
  return this;
}


// ========================================================================
// ?Think@idExplodable@@UAAXXZ
// EA  : 0x82C4B070
// RVA : 0x00C4B070
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void __fastcall idExplodable::Think(idExplodable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idExplodable::Think");
  LODWORD(v2) = "idExplodable::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  idEntity::Think(this);
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489661
// EA  : 0x82C4B0C8
// RVA : 0x00C4B0C8
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489661()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$489662
// EA  : 0x82C4B0F0
// RVA : 0x00C4B0F0
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489662()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Hide@idExplodable@@UAAXXZ
// EA  : 0x82C4B120
// RVA : 0x00C4B120
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void __fastcall idExplodable::Hide(idExplodable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idExplodable::Hide");
  LODWORD(v2) = "idExplodable::Hide";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  idEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 7);
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489692
// EA  : 0x82C4B184
// RVA : 0x00C4B184
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489692()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$489693
// EA  : 0x82C4B1AC
// RVA : 0x00C4B1AC
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489693()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Show@idExplodable@@UAAXXZ
// EA  : 0x82C4B1E0
// RVA : 0x00C4B1E0
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void __fastcall idExplodable::Show(idExplodable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idExplodable::Show");
  LODWORD(v2) = "idExplodable::Show";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  idEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489723
// EA  : 0x82C4B244
// RVA : 0x00C4B244
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489723()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$489724
// EA  : 0x82C4B26C
// RVA : 0x00C4B26C
// PDB : w:\tech5\tungsten\game\entities\explodable.cpp
// ========================================================================

void _unwind_489724()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}

