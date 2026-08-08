
// ========================================================================
// ?Init@idDeferredDecalManager@@QAAXPAVidClip@@PAVidRenderModelDecal@@@Z
// EA  : 0x82708240
// RVA : 0x00708240
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

void __fastcall idDeferredDecalManager::Init(
        idDeferredDecalManager *this,
        idClip *clip_,
        idRenderModelDecal *decalModel_)
{
  this->clip = clip_;
  this->decalModel = decalModel_;
}


// ========================================================================
// ?Shutdown@idDeferredDecalManager@@QAAXXZ
// EA  : 0x82708250
// RVA : 0x00708250
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

void __fastcall idDeferredDecalManager::Shutdown(idDeferredDecalManager *this)
{
  int v1; // ctr
  float *v2; // r11

  v1 = 16;
  v2 = (float *)((char *)this - 64);
  this->numLineQueries = 0;
  this->clip = nullptr;
  this->decalModel = nullptr;
  do
  {
    v2[19] = 8.0;
    v2[18] = 0.0;
    v2[20] = 32.0;
    v2[21] = 32.0;
    *((_DWORD *)v2 + 23) = 10000;
    v2[22] = 0.0;
    v2[25] = 0.0;
    *((_DWORD *)v2 + 24) = 2000;
    v2 += 16;
    *(_QWORD *)v2 = 0x7D000000000LL;
    --v1;
  }
  while ( v1 != 0 );
}


// ========================================================================
// ??0idDeferredDecalManager@@QAA@XZ
// EA  : 0x82708330
// RVA : 0x00708330
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

idDeferredDecalManager *__fastcall idDeferredDecalManager::idDeferredDecalManager(idDeferredDecalManager *this)
{
  `eh vector constructor iterator'(
    ptr: this,
    size: 0x40u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idDeferredDecalQuery::idDeferredDecalQuery,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  this->numLineQueries = 0;
  this->clip = nullptr;
  this->decalModel = nullptr;
  return this;
}


// ========================================================================
// ?AddDecalFromLineTrace@idDeferredDecalManager@@QAAXPBUdeferredDecalParams_t@@ABVidVec3@@1H@Z
// EA  : 0x82708388
// RVA : 0x00708388
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

void __fastcall idDeferredDecalManager::AddDecalFromLineTrace(
        idDeferredDecalManager *this,
        const deferredDecalParams_t *decalParam,
        const idVec3 *start,
        const idVec3 *end,
        int clipMask)
{
  int numLineQueries; // r11
  idDeferredDecalQuery *v9; // r11
  unsigned __int64 v10; // r8
  idDeferredDecalQuery *v11; // r11
  int v12; // [sp+8h] [-98h]
  bool v13; // [sp+Fh] [-91h]
  const char *v14; // [sp+10h] [-90h]
  char v15; // [sp+70h] [-30h] BYREF

  if ( this->clip != nullptr && this->decalModel != nullptr )
  {
    numLineQueries = this->numLineQueries;
    if ( numLineQueries < 16 )
    {
      if ( decalParam != nullptr && decalParam->decalMat != nullptr )
      {
        v9 = &this->lineQueries[numLineQueries];
        HIDWORD(v10) = &unk_82150000;
        LODWORD(v10) = 0;
        v9->decalParams.depth = 8.0;
        v9->decalParams.decalMat = nullptr;
        v9->decalParams.size.x = 32.0;
        v9->decalParams.size.y = 32.0;
        v9->decalParams.fadeInEndTime = 0;
        v9->decalParams.lifetime = 10000;
        v9->decalParams.fadetime = 2000;
        v9->decalParams.angle = 0.0;
        v9->theQuery.index = v10;
        this->lineQueries[this->numLineQueries].theQuery = (idClipQuery)idClip::Translation(
                                                                          this: (idClip *)&v15,
                                                                          result: (idClipQuery *)this->clip,
                                                                          result: nullptr,
                                                                          start,
                                                                          end,
                                                                          clipModel: nullptr,
                                                                          startAxis: &mat3_identity,
                                                                          clipMask,
                                                                          passEntityNumber: v12,
                                                                          moveClipModel: v13,
                                                                          userName: v14)->index;
        v11 = &this->lineQueries[this->numLineQueries];
        v11->decalParams.decalMat = decalParam->decalMat;
        v11->decalParams.depth = decalParam->depth;
        v11->decalParams.size.x = decalParam->size.x;
        v11->decalParams.size.y = decalParam->size.y;
        v11->decalParams.angle = decalParam->angle;
        v11->decalParams.lifetime = decalParam->lifetime;
        v11->decalParams.fadetime = decalParam->fadetime;
        v11->decalParams.fadeInEndTime = decalParam->fadeInEndTime;
        ++this->numLineQueries;
      }
      else
      {
        idLib::Warning(fmt: "Null decal passed in to  idDeferredDecalManager::AddDecalFromLineTrace");
      }
    }
    else
    {
      idLib::Warning(fmt: "Too many deferred decal queries this frame!");
    }
  }
}


// ========================================================================
// ?AddDecalFromPoint@idDeferredDecalManager@@QAAXPBUdeferredDecalParams_t@@HABVidVec3@@1@Z
// EA  : 0x82708508
// RVA : 0x00708508
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

void __fastcall idDeferredDecalManager::AddDecalFromPoint(
        idDeferredDecalManager *this,
        const deferredDecalParams_t *decalParam,
        int time,
        const idVec3 *origin,
        const idVec3 *normal)
{
  const idMaterial *decalMat; // r10
  int fadetime; // r9
  int lifetime; // r7
  double angle; // fp0
  double depth; // fp13
  double x; // fp12
  double y; // fp11
  idRenderModelDecal *decalModel; // r4
  char v14; // [sp+50h] [-40h] BYREF
  float v15[8]; // [sp+60h] [-30h] BYREF
  char v16; // [sp+80h] [-10h]

  if ( this->clip != nullptr && this->decalModel != nullptr )
  {
    if ( decalParam != nullptr && (decalMat = decalParam->decalMat, decalParam->decalMat != nullptr) )
    {
      fadetime = decalParam->fadetime;
      lifetime = decalParam->lifetime;
      angle = decalParam->angle;
      depth = decalParam->depth;
      v16 = 0;
      x = decalParam->size.x;
      LODWORD(v15[0]) = decalMat;
      y = decalParam->size.y;
      v15[7] = 0.0;
      LODWORD(v15[6]) = fadetime;
      v15[4] = angle;
      LODWORD(v15[5]) = lifetime;
      v15[1] = depth;
      v15[2] = x;
      decalModel = this->decalModel;
      v15[3] = y;
      decalModel->AddDecalFromPoint(
        this: (idRenderModel *)&v14,
        result: (idHandle<int,enum invalidDecalHandle_t,-1> *)decalModel,
        a3: (const decalParams_t *)v15,
        a4: time,
        a5: origin,
        a6: normal,
        a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
    }
    else
    {
      idLib::Warning(
        fmt: "Null decal passed in to  idDeferredDecalManager::AddDecalFromLineTrace",
        decalParam,
        time,
        origin,
        normal,
        normal);
    }
  }
}


// ========================================================================
// ?Update@idDeferredDecalManager@@QAAXH@Z
// EA  : 0x827085E0
// RVA : 0x007085E0
// PDB : w:\tech5\engine\gamelib\effects\deferreddecalmanager.cpp
// ========================================================================

void __fastcall idDeferredDecalManager::Update(idDeferredDecalManager *this, int time)
{
  __int64 v4; // r29
  int v5; // r25
  float *p_depth; // r31
  float *v7; // r30
  __int64 v8; // r11
  trace_t v9; // [sp+50h] [-100h] BYREF

  if ( this->clip != nullptr && this->decalModel != nullptr )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numLineQueries > 0 )
    {
      p_depth = &this->lineQueries[0].decalParams.depth;
      do
      {
        HIDWORD(v4) = this->clip;
        v7 = p_depth - 3;
        if ( (unsigned __int8)idClip::QueryIsValid(
                                this: (idClip *)HIDWORD(v4),
                                clipQuery: (const idClipQuery *)(p_depth - 3)) != 0 )
        {
          v8 = *(_QWORD *)v7;
          *(_QWORD *)v7 = v4;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v9,
            query: (idCollisionQuery *)(24 * (v8 & 0xFFF) + HIDWORD(v4) + 278920),
            peek: false);
          if ( v9.fraction < 1.0 )
            idDeferredDecalManager::AddDecalFromPoint(
              this,
              decalParam: (const deferredDecalParams_t *)(p_depth - 1),
              time,
              origin: &v9.endpos,
              normal: &v9.c.normal);
        }
        *p_depth = 8.0;
        *(p_depth - 1) = 0.0;
        p_depth[1] = 32.0;
        ++v5;
        p_depth[2] = 32.0;
        *((_DWORD *)p_depth + 4) = 10000;
        p_depth[3] = 0.0;
        p_depth[6] = 0.0;
        *((_DWORD *)p_depth + 5) = 2000;
        p_depth += 16;
        *(_QWORD *)v7 = v4;
      }
      while ( v5 < this->numLineQueries );
    }
    this->numLineQueries = 0;
  }
}

