
// ========================================================================
// ?Update@idDeferredFireManager@@QAAXXZ
// EA  : 0x82EB4DB0
// RVA : 0x00EB4DB0
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

void __fastcall idDeferredFireManager::Update(idDeferredFireManager *this)
{
  this->activeBuffer ^= 1u;
}


// ========================================================================
// ?IsHandleFinished@idDeferredFireManager@@QAA_NI@Z
// EA  : 0x82EB4DC8
// RVA : 0x00EB4DC8
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

int __fastcall idDeferredFireManager::IsHandleFinished(idDeferredFireManager *this, unsigned int handle)
{
  unsigned int activeBuffer; // r7
  int result; // r3
  unsigned int v4; // r9

  activeBuffer = this->activeBuffer;
  if ( handle >> 31 != (activeBuffer ^ 1) )
    return 0;
  v4 = this->deferredFireBuffers[activeBuffer ^ 1][handle & 0x1F].handle;
  result = 1;
  if ( v4 != handle )
    return 0;
  return result;
}


// ========================================================================
// ?IsHandleSubmitted@idDeferredFireManager@@QAA_NI@Z
// EA  : 0x82EB4E18
// RVA : 0x00EB4E18
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

int __fastcall idDeferredFireManager::IsHandleSubmitted(idDeferredFireManager *this, unsigned int handle)
{
  unsigned int activeBuffer; // r11
  int result; // r3
  unsigned int v4; // r9

  activeBuffer = this->activeBuffer;
  if ( handle >> 31 != activeBuffer )
    return 0;
  v4 = this->deferredFireBuffers[activeBuffer][handle & 0x1F].handle;
  result = 1;
  if ( v4 != handle )
    return 0;
  return result;
}


// ========================================================================
// ?CapHitScanRange@idDeferredFireManager@@ABAMPBVidDeclProjectile@@PBVidPresentable@@@Z
// EA  : 0x82EB4E68
// RVA : 0x00EB4E68
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idDeferredFireManager::CapHitScanRange(
        idDeferredFireManager *this,
        const idDeclProjectile *projDef,
        const idPresentable *attacker,
        int a4,
        int a5,
        __int64 a6)
{
  double v7; // fp1
  int maxRange; // r10

  LODWORD(a6) = projDef->maxRange;
  if ( (float)a6 <= 4096.0
    || attacker != nullptr && attacker->GetPlayerInterface(this: attacker) != nullptr
    || gameLocal == nullptr
    || gameLocal->world == nullptr
    || gameLocal->world->mapType != MAPTYPE_INSTANCE )
  {
    maxRange = projDef->maxRange;
    v7 = (float)*(__int64 *)((char *)&a6 - 4);
  }
  else
  {
    v7 = 4096.0;
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetWeapon@idFireParms@@QBAPAVidWeapon@@XZ
// EA  : 0x82EB4F38
// RVA : 0x00EB4F38
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

idWeapon *__fastcall idFireParms::GetWeapon(idFireParms *this)
{
  idWeapon *result; // r3
  idPresentable *v3; // r3
  idPresentable *v4; // r3

  result = this->weapon;
  if ( result == nullptr )
  {
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentableWeapon) != nullptr )
    {
      v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentableWeapon);
      return v3->GetFiredWeapon(this: v3, a2: this->wepDef);
    }
    else if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->attacker) != nullptr )
    {
      v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->attacker);
      return v4->GetFiredWeapon(this: v4, a2: this->wepDef);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}


// ========================================================================
// ?GetFireQuery@idDeferredFireManager@@QAA_NIAAVidFireParms@@AAVidTestFireResults@@@Z
// EA  : 0x82EB51F8
// RVA : 0x00EB51F8
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

int __fastcall idDeferredFireManager::GetFireQuery(
        idDeferredFireManager *this,
        unsigned int handle,
        idFireParms *fp,
        idTestFireResults *tfr)
{
  unsigned int v6; // r30
  __int64 v7; // r24
  int v8; // r11
  int v9; // r31
  int v10; // r27
  trace_t *traces; // r30
  idClientGame *v12; // r10
  int v13; // r11
  __int64 v14; // r9

  if ( handle >> 31 != (this->activeBuffer ^ 1) )
    return 0;
  v6 = 32 * (handle >> 31) + (handle & 0x1F);
  HIDWORD(v7) = (char *)this + 2600 * v6;
  if ( *(_DWORD *)(HIDWORD(v7) + 2588) != handle )
    return 0;
  idFireParms::operator=(this: fp, __that: (const idFireParms *)HIDWORD(v7));
  idTestFireResults::operator=(this: tfr, __that: (const idTestFireResults *)(HIDWORD(v7) + 280));
  v8 = *(_DWORD *)(HIDWORD(v7) + 2592);
  LODWORD(v7) = 0;
  v9 = 0;
  tfr->numTraces = v8;
  if ( v8 > 0 )
  {
    v10 = 325 * v6 + 19;
    traces = tfr->traces;
    do
    {
      v12 = clientGame;
      v13 = 8 * (v10 + v9);
      v14 = *(_QWORD *)((char *)&this->deferredFireBuffers[0][0].fireParms.attacker.spawnId + v13);
      *(_QWORD *)((char *)&this->deferredFireBuffers[0][0].fireParms.attacker.spawnId + v13) = v7;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: traces,
        query: &v12->clip.collisionQueries[v14 & 0xFFF].query,
        peek: false);
      ++v9;
      ++traces;
    }
    while ( v9 < tfr->numTraces );
  }
  *(_DWORD *)(HIDWORD(v7) + 2588) = 0;
  return 1;
}


// ========================================================================
// ??0idFireParms@@QAA@XZ
// EA  : 0x82EB5308
// RVA : 0x00EB5308
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

idFireParms *__fastcall idFireParms::idFireParms(idFireParms *this)
{
  int v2; // ctr
  int *p_muzzleTagIndex; // r10
  float *p_y; // r11
  char v5; // r6

  this->attacker.spawnId = 0;
  this->presentableWeapon.spawnId = 0;
  this->weapon = nullptr;
  this->ignoreEntityNum = -1;
  this->targetList.list = nullptr;
  this->targetList.granularity = 0;
  this->targetList.memTag = 5;
  this->targetList.listStatic = 0;
  this->targetList.size = 0;
  this->targetList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetList);
  this->target.spawnId = 0;
  this->targetPos = vec3_origin;
  v2 = 9;
  p_muzzleTagIndex = &this->muzzleTagIndex;
  p_y = &mat2_identity.mat[1].y;
  this->wepDef = nullptr;
  this->start = vec3_origin;
  this->muzzleOffset = vec3_origin;
  this->muzzleTagIndex = -1;
  do
  {
    *++p_muzzleTagIndex = *(_DWORD *)++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->projDef = nullptr;
  this->projectile.spawnId.value = 0x1FFF;
  this->tag = 0;
  v5 = *((_BYTE *)this + 129);
  *((_BYTE *)this + 128) = 0;
  *((_BYTE *)this + 129) = v5 & 0x3F;
  this->damageScale = 1.0;
  this->startTime = 0;
  this->addSpread = 0.0;
  this->startSpeed = -1.0;
  if ( gameLocal != nullptr )
    this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  return this;
}


// ========================================================================
// __unwind$488131_0
// EA  : 0x82EB5484
// RVA : 0x00EB5484
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

void _unwind_488131_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?Clear@idFireParms@@QAAXXZ
// EA  : 0x82EB54B0
// RVA : 0x00EB54B0
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

void __fastcall idFireParms::Clear(idFireParms *this)
{
  char v2; // r9

  this->targetPos = vec3_origin;
  this->wepDef = nullptr;
  this->attacker.spawnId = 0;
  this->presentableWeapon.spawnId = 0;
  this->weapon = nullptr;
  this->target.spawnId = 0;
  this->start = vec3_origin;
  this->muzzleOffset = vec3_origin;
  this->muzzleTagIndex = -1;
  this->fireAxis = mat3_identity;
  this->projDef = nullptr;
  this->projectile.spawnId.value = 0x1FFF;
  v2 = *((_BYTE *)this + 129);
  *((_BYTE *)this + 128) = 0;
  this->damageScale = 1.0;
  *((_BYTE *)this + 129) = v2 & 0x1F;
  this->addSpread = 0.0;
  this->ignoreEntityNum = -1;
  this->startSpeed = -1.0;
  this->startTime = 0;
  if ( gameLocal != nullptr )
    this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->tag = 0;
}


// ========================================================================
// ?SubmitFireQuery@idDeferredFireManager@@QAAIABVidFireParms@@@Z
// EA  : 0x82EB5600
// RVA : 0x00EB5600
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

unsigned int __fastcall idDeferredFireManager::SubmitFireQuery(idDeferredFireManager *this, const idFireParms *fp)
{
  unsigned int *p_shotCount; // r18
  unsigned int *p_activeBuffer; // r30
  unsigned int v6; // r29
  idFireParms *p_fireParms; // r27
  const idPresentable *v9; // r3
  __int64 v10; // r10
  int v11; // r7
  int v12; // r6
  __int64 v13; // r6
  long double v14; // fp2
  double v15; // fp31
  int v16; // r26
  int v17; // r27
  float *RandomSpreadTraceDir; // r3
  float *v19; // r11
  double z; // fp12
  int ignoreEntityNum; // r10
  double v22; // fp0
  float *v23; // r11
  double v24; // fp7
  double v25; // fp5
  int entityNumber; // r23
  unsigned int v27; // r25
  idPresentable *PresentableByIndex; // r3
  unsigned int v29; // r25
  idPresentable *v30; // r3
  idPresentable *v31; // r3
  idPresentable *v32; // r3
  idPresentable *v33; // r3
  idTurret *v34; // r3
  unsigned __int64 v35; // r10
  int v36; // r11
  unsigned int v37; // r11
  int v38; // [sp+8h] [-128h]
  bool v39; // [sp+Fh] [-121h]
  const char *v40; // [sp+10h] [-120h]
  int v41; // [sp+14h] [-11Ch]
  int v42; // [sp+18h] [-118h]
  int v43; // [sp+1Ch] [-114h]
  int v44; // [sp+20h] [-110h]
  int v45; // [sp+24h] [-10Ch]
  int v46; // [sp+28h] [-108h]
  int v47; // [sp+2Ch] [-104h]
  int v48; // [sp+30h] [-100h]
  int v49; // [sp+34h] [-FCh]
  int v50; // [sp+38h] [-F8h]
  int v51; // [sp+3Ch] [-F4h]
  int v52; // [sp+40h] [-F0h]
  int v53; // [sp+44h] [-ECh]
  int v54; // [sp+48h] [-E8h]
  int v55; // [sp+4Ch] [-E4h]
  int v56; // [sp+50h] [-E0h]
  int v57; // [sp+58h] [-D8h]
  int v58; // [sp+60h] [-D0h]
  char v59; // [sp+70h] [-C0h] BYREF
  idVec3 v60; // [sp+78h] [-B8h] BYREF
  char v61; // [sp+88h] [-A8h] BYREF

  p_shotCount = &this->shotCount;
  p_activeBuffer = &this->activeBuffer;
  v6 = this->shotCount & 0x1F;
  p_fireParms = &this->deferredFireBuffers[this->activeBuffer][v6].fireParms;
  if ( p_fireParms->startTime == ((int (*)(void))gameLocal->GetGameMs)() )
  {
    idLib::Warning(fmt: "TO MANY DEFFERED FIRE TRACES");
    return 0;
  }
  else
  {
    idFireParms::operator=(this: p_fireParms, __that: fp);
    this->deferredFireBuffers[*p_activeBuffer][v6].fireParms.startTime = gameLocal->GetGameMs(
                                                                           this: gameLocal,
                                                                           a2: GAMETIME_SCALED);
    this->deferredFireBuffers[*p_activeBuffer][v6].handle = (*p_activeBuffer << 31) | *p_shotCount;
    this->deferredFireBuffers[*p_activeBuffer][v6].numTraces = fp->projDef->spawnCount;
    v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    *(double *)&v14 = idDeferredFireManager::CapHitScanRange(
                        this,
                        projDef: fp->projDef,
                        attacker: v9,
                        a4: v12,
                        a5: v11,
                        a6: v10);
    v15 = *(double *)&v14;
    v16 = 0;
    if ( this->deferredFireBuffers[*p_activeBuffer][v6].numTraces > 0 )
    {
      v17 = 0;
      do
      {
        if ( fp->projDef->spread == 0.0 || (*((_BYTE *)fp + 128) & 2) != 0 )
        {
          v19 = (float *)((char *)&this->deferredFireBuffers[*p_activeBuffer][v6].fireParms.attacker.spawnId + v17);
          v19[583] = fp->fireAxis.mat[0].x;
          v19[584] = fp->fireAxis.mat[0].y;
          z = fp->fireAxis.mat[0].z;
        }
        else
        {
          HIDWORD(v13) = fp;
          RandomSpreadTraceDir = (float *)idClientGame::GetRandomSpreadTraceDir(
                                            this: (idClientGame *)&v61,
                                            fp: v13,
                                            a3: v14);
          v19 = (float *)((char *)&this->deferredFireBuffers[*p_activeBuffer][v6].fireParms.attacker.spawnId + v17);
          v19[583] = *RandomSpreadTraceDir;
          v19[584] = RandomSpreadTraceDir[1];
          z = RandomSpreadTraceDir[2];
        }
        v19[585] = z;
        this->deferredFireBuffers[*p_activeBuffer][v6].fireResults.traceLens[v16] = v15;
        ignoreEntityNum = fp->ignoreEntityNum;
        v22 = fp->start.z;
        v23 = (float *)((char *)&this->deferredFireBuffers[*p_activeBuffer][v6].fireParms.attacker.spawnId + v17);
        v24 = (float)(v23[585] * (float)v15);
        v25 = (float)(fp->start.y + (float)(v23[584] * (float)v15));
        v60.x = fp->start.x + (float)(v23[583] * (float)v15);
        v60.y = v25;
        v60.z = (float)v22 + (float)v24;
        if ( ignoreEntityNum < 0 )
        {
          v27 = fp->attacker.spawnId & 0x3FFF;
          if ( fp->attacker.spawnId == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
            || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v27))->spawnId != fp->attacker.spawnId )
          {
            PresentableByIndex = nullptr;
          }
          entityNumber = PresentableByIndex->entityNumber;
        }
        else
        {
          entityNumber = ignoreEntityNum;
        }
        if ( common->IsMultiplayer(this: common) && gc_friendlyFire.valueInteger == 0 )
        {
          v29 = fp->attacker.spawnId & 0x3FFF;
          if ( fp->attacker.spawnId != 0
            && idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
            && idClientGame::GetPresentableByIndex(this: clientGame, index: v29)->spawnId == fp->attacker.spawnId )
          {
            v30 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
            if ( v30->GetPlayerInterface_2(this: v30) == nullptr )
            {
              v31 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
              if ( v31->GetTurretInterface(this: v31) != nullptr && common->IsServer(this: common) )
              {
                v32 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
                if ( v32->GetTurretInterface(this: v32) != nullptr )
                {
                  v33 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
                  v34 = idTurret::CastTo(c: (idTurret *)v33->entity);
                  if ( v34 != nullptr )
                    idPlayer::CastTo(c: (idPlayer *)v34->turretOwner);
                }
              }
            }
          }
        }
        v35 = *(_QWORD *)&idClip::Translation(
                            this: (idClip *)&v59,
                            result: &clientGame->clip,
                            a3: nullptr,
                            start: &fp->start,
                            end: &v60,
                            clipModel: nullptr,
                            startAxis: &fp->fireAxis,
                            clipMask: 8462469,
                            passEntityNumber: v38,
                            moveClipModel: v39,
                            userName: v40,
                            a12: v41,
                            a13: v42,
                            a14: v43,
                            a15: v44,
                            a16: v45,
                            a17: v46,
                            a18: v47,
                            a19: v48,
                            a20: v49,
                            a21: v50,
                            a22: v51,
                            a23: v52,
                            a24: v53,
                            a25: v54,
                            a26: v55,
                            a27: v56,
                            a28: entityNumber,
                            a29: v57,
                            a30: false,
                            a31: v58,
                            a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\FireParms.cpp(201) : deferred_fire")->world;
        v17 += 12;
        HIDWORD(v35) = 32 * *p_activeBuffer + v6;
        v36 = 325 * HIDWORD(v35) + v16++;
        this->deferredFireBuffers[0][0].queryHandles[v36].index = v35;
        LODWORD(v13) = *p_activeBuffer;
      }
      while ( v16 < this->deferredFireBuffers[*p_activeBuffer][v6].numTraces );
    }
    v37 = *p_shotCount + 1;
    *p_shotCount = v37;
    if ( v37 > 0x7FFFFFFF )
      *p_shotCount = 0;
    return this->deferredFireBuffers[*p_activeBuffer][v6].handle;
  }
}


// ========================================================================
// ??0idDeferredFireManager@@QAA@XZ
// EA  : 0x82EB5B58
// RVA : 0x00EB5B58
// PDB : w:\tech5\tungsten\game\weapons\fireparms.cpp
// ========================================================================

idDeferredFireManager *__fastcall idDeferredFireManager::idDeferredFireManager(idDeferredFireManager *this)
{
  `eh vector constructor iterator'(
    ptr: this,
    size: 0xA28u,
    count: 64,
    pCtor: (void (__fastcall *)(void *))idDeferredFireManager::deferredFire_t::deferredFire_t,
    pDtor: (void (__fastcall *)(void *))idFireParms::~idFireParms);
  this->shotCount = 1;
  this->activeBuffer = 0;
  memset(Dst: this, Val: 0, Size: 0x28A00u);
  return this;
}

