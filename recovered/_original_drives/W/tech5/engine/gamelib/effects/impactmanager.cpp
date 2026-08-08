
// ========================================================================
// ?StopImpacts@idImpactManager@@QAAXXZ
// EA  : 0x82713510
// RVA : 0x00713510
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::StopImpacts(idImpactManager *this)
{
  int v2; // r28
  int v3; // r31
  idRenderModelParticle *pmodel; // r29
  idEffectsModelManager *effectsModelManager; // r3

  v2 = 0;
  if ( this->impacts.num > 0 )
  {
    v3 = 0;
    do
    {
      pmodel = this->impacts.list[v3].pmodel;
      if ( pmodel != nullptr )
      {
        if ( !pmodel->unlinked )
        {
          idRenderModel::CommitThisFrame(this: this->impacts.list[v3].pmodel);
          pmodel->unlinked = true;
        }
        effectsModelManager = this->effectsModelManager;
        if ( effectsModelManager != nullptr )
          idEffectsModelManager::RecycleParticleFxModel(
            this: effectsModelManager,
            particleDecl: pmodel->particleDecl,
            model: pmodel);
      }
      ++v2;
      this->impacts.list[v3].startTime = 0;
      this->impacts.list[v3++].endTime = 0;
    }
    while ( v2 < this->impacts.num );
  }
}


// ========================================================================
// ?UseImpact@idImpactManager@@QAAXABVidVec3@@ABVidMat3@@PBVidDeclParticle@@H_N01HMABVidColor@@H@Z
// EA  : 0x827135B0
// RVA : 0x007135B0
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::UseImpact(
        idImpactManager *this,
        const idVec3 *org,
        idMat3 *axis,
        const idMaterial *prt,
        unsigned int startTime,
        bool bindToParent,
        const idVec3 *parentOrg,
        idMat3 *parentAxis,
        double distSqr,
        const int playerIndex,
        const idColor *color,
        const int numCycles,
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
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        float *a33,
        int a34,
        int a35)
{
  idRenderWorld *v44; // r3
  int next; // r11
  idImpactManager::impactBindState_t *v46; // r30
  idImpactManager::impactState_t *v47; // r29
  idRenderModel *pmodel; // r25
  idEffectsModelManager *effectsModelManager; // r3
  idEffectsModelManager *v50; // r3
  double v51; // fp12
  double v52; // fp8
  double v53; // fp4
  const idMat3 *v54; // r3
  float *v55; // r11
  float *v56; // r11
  double z; // fp3
  idRenderWorld *v58; // r3
  idRenderWorld *v59; // r3
  idRenderWorld *v60; // r3
  double x; // fp6
  double v62; // fp2
  double v63; // fp0
  idRenderWorld *v64; // r3
  idRenderModelParticle *v65; // r11
  unsigned int v66; // r7
  __int64 v67; // r4
  double v68; // fp5
  double v69; // fp4
  double v70; // fp3
  const idDeclRenderParm *r; // r30
  int v72; // r3
  int num; // r4
  int v74; // r11
  float v75[6]; // [sp+58h] [-108h] BYREF
  idVec4 v76; // [sp+70h] [-F0h] BYREF
  idMat3 v77; // [sp+80h] [-E0h] BYREF
  idMat3 v78; // [sp+B0h] [-B0h] BYREF

  if ( g_debugImpactMgr.valueInteger > 0 )
  {
    v44 = common->RW(this: common);
    v44->DebugAxis_2(this: v44, a2: org, a3: axis, a4: 200, a5: false);
  }
  if ( this->initialized && prt != nullptr )
  {
    next = this->next;
    v46 = &this->impactBinds.list[next];
    v47 = &this->impacts.list[next];
    pmodel = v47->pmodel;
    if ( v47->pmodel != nullptr )
    {
      if ( !pmodel->unlinked )
      {
        idRenderModel::CommitThisFrame(this: pmodel);
        pmodel->unlinked = true;
      }
      effectsModelManager = this->effectsModelManager;
      if ( effectsModelManager != nullptr )
        idEffectsModelManager::RecycleParticleFxModel(
          this: effectsModelManager,
          particleDecl: v47->pmodel->particleDecl,
          model: v47->pmodel);
    }
    v50 = this->effectsModelManager;
    if ( v50 != nullptr )
      v47->pmodel = idEffectsModelManager::GetNextParticleEffectModel(this: v50, particleDecl: prt);
    if ( v47->pmodel != nullptr )
    {
      v47->startTime = startTime;
      v47->endTime = *(_DWORD *)&prt->renderParmBlock.usingTempOps * a35 + startTime + 1000;
      v46->bindToParent = bindToParent;
      if ( bindToParent )
      {
        v51 = (float)(org->y - parentOrg->y);
        v52 = (float)(org->z - parentOrg->z);
        v53 = (float)(org->x - parentOrg->x);
        v46->relOrg.x = (float)(parentAxis->mat[0].x * (float)(org->x - parentOrg->x))
                      + (float)((float)(parentAxis->mat[0].z * (float)(org->z - parentOrg->z))
                              + (float)(parentAxis->mat[0].y * (float)(org->y - parentOrg->y)));
        v46->relOrg.y = (float)(parentAxis->mat[1].x * (float)v53)
                      + (float)((float)(parentAxis->mat[1].z * (float)v52) + (float)(parentAxis->mat[1].y * (float)v51));
        v46->relOrg.z = (float)(parentAxis->mat[2].x * (float)v53)
                      + (float)((float)(parentAxis->mat[2].z * (float)v52) + (float)(parentAxis->mat[2].y * (float)v51));
        v54 = idMat3::Inverse(this: &v77, result: parentAxis);
        v46->relRot = *idMat3::operator*(this: &v78, result: axis, a: v54);
      }
      if ( a29 != -1 && common->IsServer(this: common) )
      {
        v55 = (float *)((char *)this + 64 * this->impactBufferPos);
        if ( bindToParent )
        {
          v55[12] = v46->relOrg.x;
          v55[13] = v46->relOrg.y;
          v55[14] = v46->relOrg.z;
          v56 = (float *)((char *)this + 64 * this->impactBufferPos);
          v56[15] = v46->relRot.mat[0].x;
          v56[16] = v46->relRot.mat[0].y;
          v56[17] = v46->relRot.mat[0].z;
          v56[18] = v46->relRot.mat[1].x;
          v56[19] = v46->relRot.mat[1].y;
          v56[20] = v46->relRot.mat[1].z;
          v56[21] = v46->relRot.mat[2].x;
          v56[22] = v46->relRot.mat[2].y;
          z = v46->relRot.mat[2].z;
        }
        else
        {
          v55[12] = org->x;
          v55[13] = org->y;
          v55[14] = org->z;
          v56 = (float *)((char *)this + 64 * this->impactBufferPos);
          v56[15] = axis->mat[0].x;
          v56[16] = axis->mat[0].y;
          v56[17] = axis->mat[0].z;
          v56[18] = axis->mat[1].x;
          v56[19] = axis->mat[1].y;
          v56[20] = axis->mat[1].z;
          v56[21] = axis->mat[2].x;
          v56[22] = axis->mat[2].y;
          z = axis->mat[2].z;
        }
        v56[23] = z;
        this->impactBuffer[this->impactBufferPos].bindToParent = bindToParent;
        this->impactBuffer[this->impactBufferPos].prt = (const idDeclParticle *)prt;
        this->impactBuffer[this->impactBufferPos].playerIndex = a29;
        this->impactBuffer[this->impactBufferPos].serverTime = startTime;
        if ( g_debugImpactMgr.valueInteger > 1 && bindToParent )
        {
          v58 = common->RW(this: common);
          v58->DebugAxis_2(this: v58, a2: parentOrg, a3: parentAxis, a4: 5000, a5: false);
          v59 = common->RW(this: common);
          v59->DebugLine(
            this: v59,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: parentOrg,
            a4: org,
            a5: 5000,
            a6: false);
          v60 = common->RW(this: common);
          v60->DebugPoint(this: v60, a2: (const idVec4 *)&idColor::colorGreen, a3: org, a4: 5000, a5: false);
          x = parentOrg->x;
          v62 = (float)((float)(parentAxis->mat[0].x * v46->relOrg.x)
                      + (float)((float)(parentAxis->mat[1].x * v46->relOrg.y)
                              + (float)(parentAxis->mat[2].x * v46->relOrg.z)));
          v63 = (float)(parentOrg->z
                      + (float)((float)(parentAxis->mat[2].z * v46->relOrg.z)
                              + (float)((float)(parentAxis->mat[0].z * v46->relOrg.x)
                                      + (float)(parentAxis->mat[1].z * v46->relOrg.y))));
          v75[1] = parentOrg->y
                 + (float)((float)(parentAxis->mat[2].y * v46->relOrg.z)
                         + (float)((float)(parentAxis->mat[0].y * v46->relOrg.x)
                                 + (float)(parentAxis->mat[1].y * v46->relOrg.y)));
          v75[2] = v63;
          v75[0] = (float)x + (float)v62;
          v64 = common->RW(this: common);
          v64->DebugLine(
            this: v64,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: parentOrg,
            a4: (const idVec3 *)v75,
            a5: 5000,
            a6: false);
        }
        this->impactBufferPos = (this->impactBufferPos + 1) % 16;
      }
      v65 = v47->pmodel;
      if ( !v47->pmodel->deferredPositionInitialized || !v47->pmodel->useDeferredPosition )
      {
        v65->g.origin.x = org->x;
        v65->g.origin.y = org->y;
        v65->g.origin.z = org->z;
      }
      v65->deferredOrigin.x = org->x;
      v65->deferredOrigin.y = org->y;
      v65->deferredOrigin.z = org->z;
      idRenderModel::SetAxis(this: v47->pmodel, a: axis);
      v66 = 1664525 * this->random.seed + 1013904223;
      LODWORD(v67) = (v66 >> 10) & 0x7FFF;
      this->random.seed = v66;
      idRenderModel::SetParm(
        this: v47->pmodel,
        parm: rp->Diversity,
        scalar: (float)((float)v67 * (float)0.000030518509));
      idRenderModel::SetParm(this: v47->pmodel, parm: rp->TimeStop, scalar: 0.0);
      idRenderModel::SetParm(
        this: v47->pmodel,
        parm: rp->TimeOffset,
        scalar: (float)((float)__SPAIR64__(&unk_82390000, startTime) * (float)0.001));
      v68 = a33[3];
      v69 = *a33;
      v70 = a33[1];
      v76.z = a33[2];
      v76.w = v68;
      v76.x = v69;
      v76.y = v70;
      idRenderModel::SetParm(this: v47->pmodel, parm: rp->Color, v4: &v76);
      idRenderModel::SetParm(this: v47->pmodel, parm: rp->NoShadows, scalar: 0.0);
      r = (const idDeclRenderParm *)rp_particleLOD.r;
      v72 = idDeclParticle::CalcLodForDistance(this: (idDeclParticle *)prt, distSqr);
      idRenderModel::SetParm(this: v47->pmodel, parm: r, scalar: (float)__SPAIR64__((unsigned int)r, v72));
      idRenderModel::CommitThisFrame(this: v47->pmodel);
      num = this->impacts.num;
      v74 = this->next + 1;
      this->next = v74;
      if ( v74 >= num )
        this->next = 0;
    }
  }
}


// ========================================================================
// ?Shutdown@idImpactManager@@QAAXXZ
// EA  : 0x82713CD8
// RVA : 0x00713CD8
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::Shutdown(idImpactManager *this)
{
  idImpactManager::StopImpacts(this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->impactBinds);
  this->effectsModelManager = nullptr;
  this->impactBufferPos = 0;
  this->serializeImpactCount = 0;
  this->next = 0;
  this->initialized = false;
  this->localPlayerIndex = 0;
}


// ========================================================================
// ??0idImpactManager@@QAA@XZ
// EA  : 0x82713ED0
// RVA : 0x00713ED0
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

idImpactManager *__fastcall idImpactManager::idImpactManager(idImpactManager *this)
{
  idEffectsModelManager **p_effectsModelManager; // r11
  int v3; // ctr
  float *v4; // r8

  this->impacts.list = nullptr;
  this->impacts.granularity = 0;
  this->impacts.memTag = 5;
  this->impacts.listStatic = 0;
  this->impacts.size = 0;
  this->impacts.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->impactBinds.list = nullptr;
  this->impactBinds.granularity = 0;
  this->impactBinds.memTag = 5;
  this->impactBinds.listStatic = 0;
  this->impactBinds.size = 0;
  this->impactBinds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->impactBinds);
  this->next = 0;
  this->random.seed = 0;
  p_effectsModelManager = &this->effectsModelManager;
  v3 = 16;
  this->initialized = false;
  v4 = (float *)((char *)this - 16);
  this->effectsModelManager = nullptr;
  do
  {
    v4 += 16;
    *v4 = vec3_origin.x;
    p_effectsModelManager[2] = (idEffectsModelManager *)LODWORD(vec3_origin.y);
    p_effectsModelManager[3] = (idEffectsModelManager *)LODWORD(vec3_origin.z);
    *(idMat3 *)(p_effectsModelManager + 4) = mat3_identity;
    p_effectsModelManager[13] = nullptr;
    *((_BYTE *)p_effectsModelManager + 56) = 0;
    p_effectsModelManager[15] = nullptr;
    p_effectsModelManager += 16;
    *p_effectsModelManager = nullptr;
    --v3;
  }
  while ( v3 != 0 );
  this->impactBufferPos = 0;
  this->serializeImpactCount = 0;
  this->localPlayerIndex = 0;
  memset(Dst: this->impactBuffer, Val: 0, Size: sizeof(this->impactBuffer));
  return this;
}


// ========================================================================
// __unwind$247960
// EA  : 0x82714004
// RVA : 0x00714004
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _unwind_247960()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idImpactManager@@QAA@XZ
// EA  : 0x82714038
// RVA : 0x00714038
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::~idImpactManager(idImpactManager *this)
{
  idImpactManager::StopImpacts(this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->impactBinds);
  this->impactBufferPos = 0;
  this->serializeImpactCount = 0;
  this->next = 0;
  this->initialized = false;
  this->localPlayerIndex = 0;
  this->effectsModelManager = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->impactBinds);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$248055
// EA  : 0x8271409C
// RVA : 0x0071409C
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _unwind_248055()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$248056
// EA  : 0x827140C4
// RVA : 0x007140C4
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _unwind_248056()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?Serialize@idImpactManager@@QAAXAAVidSerializer@@@Z
// EA  : 0x827141B0
// RVA : 0x007141B0
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::Serialize(idImpactManager *this, idSerializer *ser)
{
  int impactBufferPos; // r26
  idBitMsg *msg; // r3
  unsigned int v6; // r10
  idImpactManager::impactBufferItem_t *impactBuffer; // r30
  int i; // r27
  bool bindToParent; // r29
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  __int64 v12; // r8
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  int v15; // r11
  int serializeImpactCount; // r4
  int j; // r31
  float *v18; // r11

  impactBufferPos = this->impactBufferPos;
  msg = ser->msg;
  v6 = _cntlzw(0xFu);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: impactBufferPos, numBits: 32 - v6);
  else
    impactBufferPos = idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  impactBuffer = this->impactBuffer;
  for ( i = 16; i != 0; --i )
  {
    bindToParent = impactBuffer->bindToParent;
    v10 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v10, value: impactBuffer->bindToParent, numBits: 1);
    else
      bindToParent = (_cntlzw(idBitMsg::ReadBits(this: v10, numBits: 1) - 1) & 0x20) != 0;
    impactBuffer->bindToParent = bindToParent;
    v11 = ser->msg;
    if ( bindToParent )
    {
      if ( ser->writing )
        idBitMsg::WriteQuantizedVector<idVec3,1024,8>(this: v11, v: &impactBuffer->pos);
      else
        idBitMsg::ReadQuantizedVector<idVec3,1024,8>(this: v11, v: &impactBuffer->pos);
    }
    else if ( ser->writing )
    {
      idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v11, v: &impactBuffer->pos);
    }
    else
    {
      idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v11, v: &impactBuffer->pos);
    }
    idSerializer::SerializeQ(this: ser, axis: (idQuat *)&impactBuffer->axis, bits: 8, a4: v12);
    idSerializer::Serialize<idDeclParticle>(this: ser, decl: &impactBuffer->prt);
    v13 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v13, value: impactBuffer->playerIndex, numBits: 32);
    else
      impactBuffer->playerIndex = idBitMsg::ReadBits(this: v13, numBits: 32);
    v14 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v14, value: impactBuffer->serverTime, numBits: 32);
    else
      impactBuffer->serverTime = idBitMsg::ReadBits(this: v14, numBits: 32);
    ++impactBuffer;
  }
  v15 = impactBufferPos - this->impactBufferPos;
  if ( v15 >= 16 )
    v15 = 16;
  this->serializeImpactCount = v15;
  if ( v15 < 0 )
    this->serializeImpactCount = v15 + 16;
  if ( g_debugImpactMgr.valueInteger > 0 )
  {
    serializeImpactCount = this->serializeImpactCount;
    if ( serializeImpactCount != 0 )
    {
      idLib::Printf(fmt: "idImpactManager::Serialize. serializeImpactCount: %d \n", serializeImpactCount);
      for ( j = 0; j < this->serializeImpactCount; ++j )
      {
        v18 = (float *)((char *)this + 64 * ((j + this->impactBufferPos) % 16));
        idLib::Printf(
          fmt: "  Serialized Particle %d: %s <%.2f, %.2f, %.2f> \n",
          j,
          (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v18[12])),
          v18[12],
          v18[13],
          v18[14]);
      }
      idLib::Printf(fmt: "\n");
    }
  }
}


// ========================================================================
// ?Init@idImpactManager@@QAAXPAVidEffectsModelManager@@MHH@Z
// EA  : 0x82714638
// RVA : 0x00714638
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::Init(
        idImpactManager *this,
        idEffectsModelManager *effectsModelManager_,
        double diversity,
        const int maxImpacts,
        int playerIndex,
        int a6)
{
  int size; // r10
  int i; // r31
  idAnimator_ChannelWeight::leafAnimation_t *v10; // r3
  int j; // r31
  float *p_z; // r10
  float *p_y; // r11
  int v14; // ctr
  int v15; // r10
  int num; // r11
  idImpactManager::impactBindState_t *list; // r9
  int v18; // r11
  double v19; // fp9
  double v20; // fp8
  double v21; // fp5
  double v22; // fp4
  double v23; // fp3
  idVec3 v24; // [sp+54h] [-7Ch] BYREF
  float v25; // [sp+60h] [-70h]
  float v26; // [sp+64h] [-6Ch]
  float v27; // [sp+68h] [-68h]
  float v28; // [sp+6Ch] [-64h]
  float v29; // [sp+70h] [-60h]
  float v30; // [sp+74h] [-5Ch]
  float v31; // [sp+78h] [-58h]
  float v32; // [sp+7Ch] [-54h]
  float v33; // [sp+80h] [-50h]

  if ( !this->initialized )
  {
    size = this->impacts.size;
    this->effectsModelManager = effectsModelManager_;
    this->localPlayerIndex = a6;
    this->next = 0;
    this->random.seed = (int)(float)((float)diversity * (float)65535.0);
    if ( playerIndex > size )
      idList<idSoundSystemLocal::bufferContext_t,5>::Resize(
        (idList<idAnimator_ChannelWeight::leafAnimation_t,5> *)this,
        newsize: playerIndex);
    this->impacts.listStatic = 2;
    if ( playerIndex > this->impactBinds.size )
      idList<idImpactManager::impactBindState_t,5>::Resize(this: &this->impactBinds, newsize: playerIndex);
    this->impactBinds.listStatic = 2;
    for ( i = 0; i < this->impacts.size; v10->branch = nullptr )
    {
      v10 = idList<idAnimator_ChannelWeight::leafAnimation_t,5>::Alloc((idList<idAnimator_ChannelWeight::leafAnimation_t,5> *)this);
      ++i;
      v10->animation = nullptr;
      v10->leaf = nullptr;
    }
    for ( j = 0; j < this->impactBinds.size; *(float *)(v18 + 48) = v23 )
    {
      p_z = &v24.z;
      p_y = &mat2_identity.mat[1].y;
      v14 = 9;
      v24 = vec3_origin;
      do
      {
        *++p_z = *++p_y;
        --v14;
      }
      while ( v14 != 0 );
      idList<idImpactManager::impactBindState_t,5>::PreAllocateWithGranularity(
        this: &this->impactBinds,
        newSize: this->impactBinds.num + 1);
      v15 = this->impactBinds.size;
      num = this->impactBinds.num;
      list = this->impactBinds.list;
      if ( num >= v15 )
      {
        v18 = (int)&list[v15 - 1];
      }
      else
      {
        this->impactBinds.num = num + 1;
        v18 = (int)&list[num];
      }
      *(_BYTE *)v18 = 0;
      ++j;
      *(idVec3 *)(v18 + 4) = v24;
      *(float *)(v18 + 16) = v25;
      v19 = v26;
      v20 = v27;
      *(float *)(v18 + 28) = v28;
      *(float *)(v18 + 20) = v19;
      *(float *)(v18 + 24) = v20;
      *(float *)(v18 + 32) = v29;
      v21 = v31;
      *(float *)(v18 + 36) = v30;
      v22 = v32;
      *(float *)(v18 + 40) = v21;
      v23 = v33;
      *(float *)(v18 + 44) = v22;
    }
    this->initialized = true;
  }
}


// ========================================================================
// ?Update@idImpactManager@@QAAXABVidVec3@@ABVidMat3@@HH@Z
// EA  : 0x82714828
// RVA : 0x00714828
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __fastcall idImpactManager::Update(
        idImpactManager *this,
        const idVec3 *parentOrigin,
        idMat3 *parentAxis,
        signed int localTime,
        int serverTime)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  int impactBufferPos; // r11
  char *v13; // r10
  char *v14; // r30
  float *v15; // r11
  double y; // fp9
  double x; // fp5
  double v18; // fp2
  double v19; // fp1
  float v20; // r8
  float v21; // r10
  idMat3 *v22; // r3
  float *v23; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idRenderWorld *v26; // r3
  idRenderWorld *v27; // r3
  idRenderWorld *v28; // r3
  int v29; // r25
  int v30; // r26
  int v31; // r27
  idImpactManager::impactState_t *v32; // r11
  idRenderModelParticle *pmodel; // r30
  signed int endTime; // r11
  idImpactManager::impactBindState_t *v35; // r11
  double v36; // fp12
  double v37; // fp0
  double v38; // fp13
  const idMat3 *v39; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v41; // r30
  int v42; // r3
  __int64 totalTicks; // r11
  __int64 v44; // r9
  int v45; // [sp+8h] [-188h]
  const idColor *v46; // [sp+Ch] [-184h]
  int v47; // [sp+10h] [-180h]
  int v48; // [sp+14h] [-17Ch]
  int v49; // [sp+18h] [-178h]
  int v50; // [sp+1Ch] [-174h]
  int v51; // [sp+20h] [-170h]
  int v52; // [sp+24h] [-16Ch]
  int v53; // [sp+28h] [-168h]
  int v54; // [sp+2Ch] [-164h]
  int v55; // [sp+30h] [-160h]
  int v56; // [sp+34h] [-15Ch]
  int v57; // [sp+38h] [-158h]
  int v58; // [sp+3Ch] [-154h]
  int v59; // [sp+40h] [-150h]
  int v60; // [sp+44h] [-14Ch]
  int v61; // [sp+48h] [-148h]
  int v62; // [sp+4Ch] [-144h]
  int v63; // [sp+50h] [-140h]
  int v64; // [sp+58h] [-138h]
  int v65; // [sp+5Ch] [-134h]
  int v66; // [sp+60h] [-130h]
  int v67; // [sp+68h] [-128h]
  idPLogScope v68; // [sp+78h] [-118h] BYREF
  idVec3 v69; // [sp+80h] [-110h] BYREF
  float v70[4]; // [sp+90h] [-100h] BYREF
  float v71[3]; // [sp+A0h] [-F0h] BYREF
  float v72; // [sp+ACh] [-E4h] BYREF
  idMat3 v73; // [sp+B0h] [-E0h] BYREF
  idMat3 v74; // [sp+E0h] [-B0h] BYREF

  RD_EventBegin(name: "idImpactManager::Update");
  LODWORD(v10) = "idImpactManager::Update";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v68, pl: &::pLog, gMask: v10, label: v11);
  while ( this->serializeImpactCount > 0 )
  {
    impactBufferPos = this->impactBufferPos;
    v13 = (char *)this + 64 * impactBufferPos;
    if ( *((_DWORD *)v13 + 27) > serverTime && serverTime != 0 )
      break;
    v14 = v13 + 48;
    --this->serializeImpactCount;
    this->impactBufferPos = (impactBufferPos + 1) % 16;
    if ( *((_DWORD *)v13 + 24) != 0 )
    {
      if ( v13[100] != 0 )
      {
        v15 = v70;
        y = parentOrigin->y;
        x = parentOrigin->x;
        v18 = (float)((float)(parentAxis->mat[2].y * *((float *)v13 + 14))
                    + (float)((float)(parentAxis->mat[0].y * *((float *)v13 + 12))
                            + (float)(parentAxis->mat[1].y * *((float *)v13 + 13))));
        v19 = (float)((float)(*((float *)v13 + 12) * parentAxis->mat[0].x)
                    + (float)((float)(parentAxis->mat[1].x * *((float *)v13 + 13))
                            + (float)(parentAxis->mat[2].x * *((float *)v13 + 14))));
        v70[2] = parentOrigin->z
               + (float)((float)(parentAxis->mat[2].z * *((float *)v13 + 14))
                       + (float)((float)(parentAxis->mat[0].z * *((float *)v13 + 12))
                               + (float)(parentAxis->mat[1].z * *((float *)v13 + 13))));
        v70[1] = (float)y + (float)v18;
        v70[0] = (float)x + (float)v19;
      }
      else
      {
        v15 = (float *)(v13 + 48);
      }
      v20 = v15[2];
      v21 = *v15;
      v69.y = v15[1];
      v69.z = v20;
      v69.x = v21;
      v22 = v14[52] != 0
          ? idMat3::operator*(this: &v74, result: parentAxis, a: (const idMat3 *)(v14 + 12))
          : (idMat3 *)(v14 + 12);
      v23 = &v72;
      p_z = (_DWORD *)&v22[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
        *++v23 = *(float *)++p_z;
      if ( *((_DWORD *)v14 + 14) != this->localPlayerIndex )
      {
        if ( g_debugImpactMgr.valueInteger > 0 )
        {
          v26 = common->RW(this: common);
          v71[0] = v69.x;
          v71[1] = v69.y;
          v71[2] = v69.z;
          v72 = 10.0;
          v26->DebugSphere(
            this: v26,
            a2: (const idVec4 *)&idColor::colorYellow,
            a3: (const idSphere *)v71,
            a4: 12,
            a5: 5000,
            a6: false);
          if ( g_debugImpactMgr.valueInteger > 1 )
          {
            v27 = common->RW(this: common);
            v27->DebugAxis_2(this: v27, a2: parentOrigin, a3: parentAxis, a4: 5000, a5: false);
            v28 = common->RW(this: common);
            v28->DebugLine(
              this: v28,
              a2: (const idVec4 *)&idColor::colorRed,
              a3: parentOrigin,
              a4: &v69,
              a5: 5000,
              a6: false);
          }
        }
        idImpactManager::UseImpact(
          this,
          org: &v69,
          axis: &v73,
          prt: *((const idMaterial **)v14 + 12),
          startTime: localTime,
          bindToParent: v14[52],
          parentOrg: parentOrigin,
          parentAxis,
          distSqr: 0.0,
          playerIndex: v45,
          color: v46,
          numCycles: v47,
          a13: v48,
          a14: v49,
          a15: v50,
          a16: v51,
          a17: v52,
          a18: v53,
          a19: v54,
          a20: v55,
          a21: v56,
          a22: v57,
          a23: v58,
          a24: v59,
          a25: v60,
          a26: v61,
          a27: v62,
          a28: v63,
          a29: 0,
          a30: v64,
          a31: v65,
          a32: v66,
          a33: &idColor::colorWhite.r,
          a34: v67,
          a35: 1);
      }
    }
  }
  v29 = 0;
  if ( this->impacts.num > 0 )
  {
    v30 = 0;
    v31 = 0;
    do
    {
      v32 = &this->impacts.list[v30];
      pmodel = v32->pmodel;
      if ( v32->pmodel != nullptr )
      {
        endTime = v32->endTime;
        if ( endTime != 0 && localTime < endTime )
        {
          v35 = &this->impactBinds.list[v31];
          if ( v35->bindToParent )
          {
            v36 = (float)(parentOrigin->x
                        + (float)((float)(v35->relOrg.x * parentAxis->mat[0].x)
                                + (float)((float)(parentAxis->mat[1].x * v35->relOrg.y)
                                        + (float)(parentAxis->mat[2].x * v35->relOrg.z))));
            v38 = (float)(parentOrigin->y
                        + (float)((float)(parentAxis->mat[2].y * v35->relOrg.z)
                                + (float)((float)(parentAxis->mat[0].y * v35->relOrg.x)
                                        + (float)(parentAxis->mat[1].y * v35->relOrg.y))));
            v37 = (float)(parentOrigin->z
                        + (float)((float)(parentAxis->mat[2].z * v35->relOrg.z)
                                + (float)((float)(parentAxis->mat[0].z * v35->relOrg.x)
                                        + (float)(parentAxis->mat[1].z * v35->relOrg.y))));
            if ( !pmodel->deferredPositionInitialized || !pmodel->useDeferredPosition )
            {
              pmodel->g.origin.x = parentOrigin->x
                                 + (float)((float)(v35->relOrg.x * parentAxis->mat[0].x)
                                         + (float)((float)(parentAxis->mat[1].x * v35->relOrg.y)
                                                 + (float)(parentAxis->mat[2].x * v35->relOrg.z)));
              pmodel->g.origin.y = v38;
              pmodel->g.origin.z = v37;
            }
            pmodel->deferredOrigin.x = v36;
            pmodel->deferredOrigin.y = v38;
            pmodel->deferredOrigin.z = v37;
            v39 = idMat3::operator*(this: &v74, result: &this->impactBinds.list[v31].relRot, a: parentAxis);
            idRenderModel::SetAxis(this: pmodel, a: v39);
            idRenderModel::CommitThisFrame(this: pmodel);
          }
        }
        else if ( !pmodel->unlinked )
        {
          idRenderModel::CommitThisFrame(this: pmodel);
          pmodel->unlinked = true;
          idEffectsModelManager::RecycleParticleFxModel(
            this: this->effectsModelManager,
            particleDecl: pmodel->particleDecl,
            model: pmodel);
          this->impacts.list[v30].pmodel = nullptr;
        }
      }
      ++v29;
      ++v31;
      ++v30;
    }
    while ( v29 < this->impacts.num );
  }
  if ( v68.logIndex >= 0 )
  {
    pLog = v68.pLog;
    v41 = &v68.pLog->logEntries.list[v68.logIndex];
    v42 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v41->totalTicks;
    HIDWORD(totalTicks) = v41->parent;
    LODWORD(v44) = v42 - totalTicks;
    v41->totalTicks = v44;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$248471
// EA  : 0x82714CF0
// RVA : 0x00714CF0
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _unwind_248471()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 400 + 260));
}


// ========================================================================
// __unwind$248472
// EA  : 0x82714D18
// RVA : 0x00714D18
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _unwind_248472()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 400 + 120));
}


// ========================================================================
// `dynamic initializer for 'g_debugImpactMgr''
// EA  : 0x8333F970
// RVA : 0x0133F970
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugImpactMgr__()
{
  idCVar::idCVar(
    this: &g_debugImpactMgr,
    name: "g_debugImpactMgr",
    value: "0",
    flags: 2,
    description: "impact manager debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugImpactMgr__);
}


// ========================================================================
// `dynamic initializer for 'rp_particleLOD''
// EA  : 0x8333F9C8
// RVA : 0x0133F9C8
// PDB : w:\tech5\engine\gamelib\effects\impactmanager.cpp
// ========================================================================

void _dynamic_initializer_for__rp_particleLOD__()
{
  rp_particleLOD.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_particleLOD;
}

