
// ========================================================================
// ?DeclNameToModelName@idRenderModelParticle@@SAXPBDAAVidStr@@@Z
// EA  : 0x827F0B68
// RVA : 0x007F0B68
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __fastcall idRenderModelParticle::DeclNameToModelName(const char *declName, idStr *modelName)
{
  idStr::operator=(this: modelName, text: declName);
  idStr::SetFileExtension(this: modelName, extension: "prt");
}


// ========================================================================
// ?DrawDistributionVolumes@idRenderModelParticle@@AAAXXZ
// EA  : 0x827F0BB0
// RVA : 0x007F0BB0
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __fastcall idRenderModelParticle::DrawDistributionVolumes(idRenderModelParticle *this)
{
  int v2; // r26
  int v3; // r28
  const idDeclParticle *particleDecl; // r3
  idParticleStage *v5; // r30
  const idLookupTable *Tables; // r3
  double MaxParmVal; // fp31
  const idLookupTable *v8; // r3
  double v9; // fp30
  const idLookupTable *v10; // r3
  double v11; // fp29
  float *Axis; // r3
  double v13; // fp1
  double v14; // fp0
  double v15; // fp30
  double v16; // fp29
  double v17; // fp31
  idRenderModelParms *Origin; // r3
  double v19; // fp11
  double v20; // fp9
  const idParmBlock *RenderParmBlock; // r3
  float *v22; // r6
  float v23; // r4
  float v24; // r11
  const idParmBlock *v25; // r3
  const idLookupTable *v26; // r3
  double v27; // fp1
  double v28; // fp31
  const idLookupTable *v29; // r3
  double v30; // fp1
  double v31; // fp30
  const idLookupTable *v32; // r3
  double v33; // fp1
  double v34; // fp29
  double v35; // fp28
  idRenderWorld *World; // r3
  unsigned int type; // r11
  idRenderWorld *v38; // r30
  float *v39; // r3
  idColor *v40; // r3
  idRenderWorld *v41; // r24
  const idMat3 *v42; // r30
  idColor *v43; // r3
  idRenderWorld *v44; // r30
  idColor *v45; // r3
  float v46; // [sp+50h] [-110h] BYREF
  float v47; // [sp+54h] [-10Ch]
  float v48; // [sp+58h] [-108h]
  float v49; // [sp+60h] [-100h]
  float v50; // [sp+64h] [-FCh]
  float v51; // [sp+68h] [-F8h]
  float v52[4]; // [sp+70h] [-F0h] BYREF
  float v53[16]; // [sp+80h] [-E0h] BYREF
  idColor v54; // [sp+C0h] [-A0h] BYREF
  idColor v55; // [sp+D0h] [-90h] BYREF
  idColor v56; // [sp+E0h] [-80h] BYREF

  if ( idRenderModel::GetWorld(this) != nullptr )
  {
    v2 = 0;
    if ( this->particleDecl->stages.num > 0 )
    {
      v3 = 0;
      do
      {
        particleDecl = this->particleDecl;
        v5 = particleDecl->stages.list[v3];
        Tables = idDeclParticle::GetTables(this: particleDecl);
        MaxParmVal = idParticleParm::GetMaxParmVal(this: v5->offset.offset, tables: Tables);
        v8 = idDeclParticle::GetTables(this: this->particleDecl);
        v9 = idParticleParm::GetMaxParmVal(this: &v5->offset.offset[1], tables: v8);
        v10 = idDeclParticle::GetTables(this: this->particleDecl);
        v11 = idParticleParm::GetMaxParmVal(this: &v5->offset.offset[2], tables: v10);
        Axis = (float *)idRenderModel::GetAxis(this);
        v13 = (float)((float)(Axis[7] * (float)v11) + (float)(Axis[4] * (float)v9));
        v14 = (float)((float)(Axis[8] * (float)v11) + (float)(Axis[5] * (float)v9));
        v15 = (float)((float)((float)MaxParmVal * *Axis)
                    + (float)((float)(Axis[6] * (float)v11) + (float)(Axis[3] * (float)v9)));
        v16 = (float)((float)(Axis[1] * (float)MaxParmVal) + (float)v13);
        v17 = (float)((float)(Axis[2] * (float)MaxParmVal) + (float)v14);
        Origin = idRenderModel::GetOrigin(this);
        v19 = (float)(Origin->origin.z + (float)v17);
        v20 = (float)(Origin->origin.y + (float)v16);
        v46 = Origin->origin.x + (float)v15;
        v48 = v19;
        v47 = v20;
        RenderParmBlock = idRenderModel::GetRenderParmBlock(this);
        idParmState::VirtualEvaluateParmBlock(
          this: renderThreadParmState,
          localParmBlock: RenderParmBlock,
          parmBlock: RenderParmBlock);
        v22 = (float *)((char *)renderThreadParmState + 16 * (int)(rpParticleScale.r[1].resourceError + 3));
        v23 = v22[1];
        v24 = v22[2];
        v49 = *v22;
        v50 = v23;
        v51 = v24;
        v25 = idRenderModel::GetRenderParmBlock(this);
        idParmState::VirtualRollbackParmBlock(this: renderThreadParmState, localParmBlock: v25, parmBlock: v25);
        v26 = idDeclParticle::GetTables(this: this->particleDecl);
        v27 = idParticleParm::GetMaxParmVal(this: v5->distribution.size, tables: v26);
        v28 = (float)((float)v27 * v49);
        v29 = idDeclParticle::GetTables(this: this->particleDecl);
        v30 = idParticleParm::GetMaxParmVal(this: &v5->distribution.size[1], tables: v29);
        v31 = (float)((float)v30 * v50);
        v32 = idDeclParticle::GetTables(this: this->particleDecl);
        v33 = idParticleParm::GetMaxParmVal(this: &v5->distribution.size[2], tables: v32);
        v34 = (float)((float)v33 * v51);
        v35 = __fsqrts((float)((float)((float)v28 * (float)v28)
                             + (float)((float)((float)v31 * (float)v31)
                                     + (float)((float)((float)v33 * v51) * (float)((float)v33 * v51)))));
        if ( v35 == 0.0 )
        {
          World = idRenderModel::GetWorld(this);
          World->DebugPoint(
            this: World,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idVec3 *)&v46,
            a4: 0,
            a5: false);
        }
        else
        {
          type = v5->distribution.type;
          if ( type <= 5 )
          {
            if ( type == 1 )
              goto LABEL_13;
            if ( type == 2 )
              goto LABEL_14;
            if ( type != 3 )
            {
              if ( type == 4 )
              {
LABEL_13:
                v41 = idRenderModel::GetWorld(this);
                v42 = idRenderModel::GetAxis(this);
                v43 = BrightColorForNumber(result: &v56, number: v2);
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double, double))v41->DebugCone_2)(
                  a1: v41,
                  a2: v43,
                  a3: &v46,
                  a4: &v42->mat[2],
                  a5: v35,
                  a6: v35);
                goto LABEL_15;
              }
              if ( type != 0 )
              {
LABEL_14:
                v44 = idRenderModel::GetWorld(this);
                v52[0] = v46;
                v52[1] = v47;
                v52[2] = v48;
                v52[3] = v35;
                v45 = BrightColorForNumber(result: &v55, number: v2);
                v44->DebugSphere(
                  this: v44,
                  a2: (const idVec4 *)v45,
                  a3: (const idSphere *)v52,
                  a4: 12,
                  a5: 0,
                  a6: false);
                goto LABEL_15;
              }
            }
            v38 = idRenderModel::GetWorld(this);
            v39 = (float *)idRenderModel::GetAxis(this);
            v53[0] = v46;
            v53[1] = v47;
            v53[2] = v48;
            v53[3] = v28;
            v53[4] = v31;
            v53[5] = v34;
            v53[6] = *v39;
            v53[7] = v39[1];
            v53[8] = v39[2];
            v53[9] = v39[3];
            v53[10] = v39[4];
            v53[11] = v39[5];
            v53[12] = v39[6];
            v53[13] = v39[7];
            v53[14] = v39[8];
            v40 = BrightColorForNumber(result: &v54, number: v2);
            v38->DebugBox(this: v38, a2: (const idVec4 *)v40, a3: (const idBox *)v53, a4: 0, a5: false);
          }
        }
LABEL_15:
        ++v2;
        ++v3;
      }
      while ( v2 < this->particleDecl->stages.num );
    }
  }
}


// ========================================================================
// ?EstimateVertAllocation@idRenderModelParticle@@SAHPBVidParticleStage@@HMHMH@Z
// EA  : 0x827F0F98
// RVA : 0x007F0F98
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idRenderModelParticle::EstimateVertAllocation(
        idParticleStage *stage,
        unsigned int renderTime,
        double timeOffset,
        const int stopTime,
        double deadTime,
        __int64 lodLevel,
        unsigned int a7,
        __int64 a8)
{
  signed int v10; // r26
  int v11; // r21
  double v12; // fp13
  double v13; // fp0
  signed int v14; // r30
  int v15; // r22
  int v16; // r25
  int v17; // r24
  signed int totalParticles; // r28
  signed int v19; // r8
  double v20; // fp6
  int v21; // r29
  int v22; // r27
  int v23; // r11
  __int16 cycles; // r8
  int v25; // r11

  v10 = HIDWORD(lodLevel);
  if ( (*((_BYTE *)stage + 68) & 8) != 0 || stage->cycleMsec == 0 )
    return 0;
  LODWORD(a8) = renderTime;
  v11 = (int)(float)(stage->maxParticleLife * (float)1000.0);
  v12 = 0.0;
  v13 = (float)(stage->lodParms.lerpAmount * (float)__SPAIR64__(renderTime, a7));
  v14 = (int)(float)((float)(stage->maxParticleLife + (float)deadTime) * (float)1000.0);
  v15 = (int)(float)((float)(stage->systemProperties.spawnBunching * stage->bunchTime) * (float)1000.0);
  v16 = (int)(float)((float)((float)((float)a8 * (float)0.001)
                           - (float)(stage->systemProperties.timeOffset + (float)timeOffset))
                   * (float)1000.0);
  if ( v13 < 0.0 || (v12 = 1.0, v13 > 1.0) )
    v13 = v12;
  v17 = 0;
  totalParticles = stage->systemProperties.totalParticles;
  LODWORD(lodLevel) = stage->lodParms.totalParticles;
  v19 = totalParticles;
  v20 = (float)((float)((float)((float)lodLevel - (float)*(__int64 *)((char *)&lodLevel - 4)) * (float)v13)
              + (float)*(__int64 *)((char *)&lodLevel - 4));
  if ( (int)v20 > 0 )
  {
    v21 = 0;
    v22 = (int)v20;
    do
    {
      __twllei(totalParticles, 0);
      v23 = v16 - v21 / totalParticles;
      __twlgei(totalParticles & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
      if ( v23 >= 0 )
      {
        cycles = stage->systemProperties.cycles;
        __twllei(v14, 0);
        __twlgei(v14 & ~(__ROL4__(v23, 1) - 1), 0xFFFFFFFF);
        if ( cycles == 0 || v23 / v14 < cycles )
        {
          v25 = v23 % v14;
          if ( (v10 == 0 || (int)(renderTime - v25) < v10) && v25 >= 0 && v25 <= v11 )
            v17 += idParticleStage::NumVertsPerParticle(this: stage);
        }
      }
      --v22;
      v21 += v15;
    }
    while ( v22 != 0 );
  }
  return v17;
}


// ========================================================================
// ??1idRenderModelParticle@@MAA@XZ
// EA  : 0x827F1260
// RVA : 0x007F1260
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __fastcall idRenderModelParticle::~idRenderModelParticle(idRenderModelParticle *this)
{
  __int16 *p_granularity; // r30
  int i; // r28
  void *v4; // r4
  deferredParticleGenParms_t *list; // r4

  this->__vftable = (idRenderModelParticle_vtbl *)&idRenderModelParticle::`vftable';
  idMem::Free(this: &mem, ptr: this->particleRenderView, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)this->modelParms, align: ALIGN_16);
  p_granularity = &this->genParms.granularity;
  for ( i = 3; i != 0; --i )
  {
    if ( *((_BYTE *)p_granularity + 27) == 0 || *((_BYTE *)p_granularity + 27) == 2 )
    {
      v4 = *((void **)p_granularity + 3);
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      *((_DWORD *)p_granularity + 3) = 0;
      *((_DWORD *)p_granularity + 5) = 0;
    }
    p_granularity += 8;
    *(_DWORD *)p_granularity = 0;
  }
  `eh vector destructor iterator'(
    ptr: this->stageCounts,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( this->genParms.listStatic == 0 || this->genParms.listStatic == 2 )
  {
    list = this->genParms.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->genParms.list = nullptr;
    this->genParms.size = 0;
  }
  this->genParms.num = 0;
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231276
// EA  : 0x827F1360
// RVA : 0x007F1360
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_231276()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$231277
// EA  : 0x827F1388
// RVA : 0x007F1388
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_231277()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2032));
}


// ========================================================================
// __unwind$231278
// EA  : 0x827F13B4
// RVA : 0x007F13B4
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_231278()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2056),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?UpdateInView@idRenderModelParticle@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827F13F0
// RVA : 0x007F13F0
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

int __fastcall idRenderModelParticle::UpdateInView(
        idRenderModelParticle *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int v8; // r9
  int v9; // r10
  idRenderModelSurface *v10; // r11
  int valueInteger; // r14
  unsigned int LastError; // r3
  particleRenderView_t *particleRenderView; // r11
  particleRenderView_t *v15; // r11
  particleRenderView_t *v16; // r11
  particleRenderView_t *v17; // r11
  const idParmBlock *RenderParmBlock; // r3
  double v19; // fp28
  idParmState *v20; // r9
  modelParticleParms_t *modelParms; // r10
  const idDeclRenderParm *coverage; // r5
  parmValue_t *v23; // r11
  idParmState *v24; // r9
  modelParticleParms_t *v25; // r10
  const idDeclRenderParm *NoShadows; // r6
  parmValue_t *v27; // r11
  modelParticleParms_t *v28; // r10
  float *v29; // r11
  bool v30; // r28
  float *v31; // r9
  float *p_deferredAxis; // r11
  modelParticleParms_t *v33; // r10
  double v34; // fp13
  double v35; // fp6
  double v36; // fp1
  double v37; // fp12
  double v38; // fp10
  double v39; // fp9
  unsigned __int8 y_low; // r11
  const idParmBlock *v41; // r3
  double maxVisibleRange; // fp31
  idRenderModelParms *p_g; // r11
  double v44; // fp7
  double v45; // fp6
  double v46; // fp27
  double v47; // fp0
  double fadeVisibilityOver; // fp0
  idRenderModelParms *p_deferredOrigin; // r11
  double v50; // fp6
  double v51; // fp5
  idRenderWorld *World; // r3
  double v53; // fp1
  idRenderModelParms *v54; // r11
  modelParticleParms_t *v55; // r10
  float *p_axis; // r10
  float *v57; // r11
  modelParticleParms_t *v58; // r11
  int v59; // r19
  int v60; // r22
  float *v61; // r11
  float *particleDecl; // r10
  idRenderModelParms *v63; // r11
  double v64; // fp0
  double v65; // fp13
  double v66; // fp12
  double v67; // fp7
  double v68; // fp6
  idRenderWorld *v69; // r30
  const char *str; // r29
  int Index; // r3
  __int64 v72; // r10
  __int64 v73; // r8
  va *v74; // r3
  idMat3 *v75; // r6
  float z; // r3
  float x; // r10
  modelParticleParms_t *v78; // r9
  BOOL useDeferredPosition; // r11
  idRenderModelParms *v80; // r5
  idRenderWorld *v81; // r3
  int v82; // r9
  char *v83; // r30
  int v84; // r8
  int v85; // r29
  int v86; // r10
  int v87; // r3
  int v88; // r7
  int v89; // r11
  int v90; // r6
  int v91; // r29
  BOOL v92; // r28
  float *v93; // r11
  float *v94; // r10
  idRenderModelParms *v95; // r11
  double v96; // fp0
  double v97; // fp13
  double v98; // fp12
  double v99; // fp7
  double v100; // fp6
  idRenderWorld *v101; // r3
  __int64 v102; // r10
  idRenderWorld *v103; // r24
  __int64 v104; // r8
  __int64 v105; // r6
  va *v106; // r3
  const idDeclParticle *v107; // r10
  int v108; // r28
  int num; // r11
  int v110; // r29
  int v111; // r24
  int v112; // r23
  idParticleStage *v113; // r11
  idRenderModelSurface *v114; // r30
  const idMaterial *material; // r8
  double v116; // fp0
  double v117; // fp13
  double y; // fp12
  double v119; // fp11
  double v120; // fp10
  idTriangles *geometry; // r7
  double v122; // fp9
  idRenderModelParticle::stageCounts_t *v123; // r11
  int vertCount; // r6
  int indexOffset; // r21
  int v126; // r11
  int v127; // r5
  modelParticleParms_t *v128; // r11
  double v129; // fp7
  double v130; // fp5
  double v131; // fp4
  int v132; // r20
  int v133; // r20
  visibleInfluenceSpheres_t *visibleInfluenceSpheres; // r22
  int v135; // r30
  int v136; // r23
  int v137; // r21
  char *v138; // r24
  idParticleStage *v139; // r29
  idRandom2 *Tables; // r3
  __int64 v141; // r8
  idRandom2 *v142; // r5
  double v143; // fp31
  modelParticleParms_t *v144; // r6
  particleRenderView_t *v145; // r26
  __int64 v146; // r8
  unsigned int v147; // r9
  int v148; // r5
  int v149; // r3
  int v150; // r28
  deferredParticleGenParms_t *v151; // r26
  bool v152; // cr58
  deferredParticleGenParms_t *list; // r11
  __int64 v154; // [sp+8h] [-1188h]
  int v155; // [sp+10h] [-1180h]
  int v156; // [sp+14h] [-117Ch]
  int v157; // [sp+18h] [-1178h]
  int v158; // [sp+1Ch] [-1174h]
  idVec3 v159; // [sp+60h] [-1130h] BYREF
  idVec3 v160; // [sp+70h] [-1120h] BYREF
  float v161[4]; // [sp+80h] [-1110h] BYREF
  idBounds v162; // [sp+90h] [-1100h] BYREF
  float v163[6]; // [sp+A8h] [-10E8h] BYREF
  float v164[4]; // [sp+C0h] [-10D0h] BYREF
  va v165; // [sp+D0h] [-10C0h] BYREF

  if ( r_skipParticles.valueInteger != 0 )
  {
    v8 = 0;
    if ( this->surfaces.num > 0 )
    {
      v9 = 0;
      do
      {
        ++v8;
        v10 = &this->surfaces.list[v9++];
        v10->geometry->numVerts = 0;
        v10->geometry->numIndexes = 0;
      }
      while ( v8 < this->surfaces.num );
    }
    return 0;
  }
  valueInteger = r_useParticleGenJobs.valueInteger;
  if ( r_recordModelParticleTrace.valueInteger != 0 )
  {
    valueInteger = 0;
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  particleRenderView = this->particleRenderView;
  particleRenderView->viewOrg.x = nextView->r.vieworg.x;
  particleRenderView->viewOrg.y = nextView->r.vieworg.y;
  particleRenderView->viewOrg.z = nextView->r.vieworg.z;
  v15 = this->particleRenderView;
  v15->viewFwd.x = nextView->r.viewaxis.mat[0].x;
  v15->viewFwd.y = nextView->r.viewaxis.mat[0].y;
  v15->viewFwd.z = nextView->r.viewaxis.mat[0].z;
  v16 = this->particleRenderView;
  v16->viewLeft.x = nextView->r.viewaxis.mat[1].x;
  v16->viewLeft.y = nextView->r.viewaxis.mat[1].y;
  v16->viewLeft.z = nextView->r.viewaxis.mat[1].z;
  v17 = this->particleRenderView;
  v17->viewUp.x = nextView->r.viewaxis.mat[2].x;
  v17->viewUp.y = nextView->r.viewaxis.mat[2].y;
  v17->viewUp.z = nextView->r.viewaxis.mat[2].z;
  this->particleRenderView->renderTime = currentView->r.renderTime;
  this->particleRenderView->deltaTime = 0;
  this->particleRenderView->atlasWidth = globalImages->transSortImageAtlas->ATLAS_WIDTH;
  this->particleRenderView->atlasHeight = globalImages->transSortImageAtlas->ATLAS_HEIGHT;
  RenderParmBlock = idRenderModel::GetRenderParmBlock(this);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: RenderParmBlock,
    parmBlock: RenderParmBlock);
  v19 = renderThreadParmState->values[rp->Diversity->parmIndex].value[0];
  this->modelParms->stopTime = (int)(float)(renderThreadParmState->values[rp->TimeStop->parmIndex].value[0]
                                          * (float)1000.0);
  this->modelParms->timeOffset = renderThreadParmState->values[rp->TimeOffset->parmIndex].value[0];
  v20 = renderThreadParmState;
  modelParms = this->modelParms;
  coverage = rp->coverage;
  v23 = &renderThreadParmState->values[rp->Color->parmIndex];
  modelParms->color.x = v23->value[0];
  modelParms->color.y = v23->value[1];
  modelParms->color.z = v23->value[2];
  modelParms->color.w = v23->value[3];
  this->modelParms->coverage = v20->values[coverage->parmIndex].value[0];
  v24 = renderThreadParmState;
  v25 = this->modelParms;
  NoShadows = rp->NoShadows;
  v27 = &renderThreadParmState->values[rp->Wind->parmIndex];
  v25->wind.x = v27->value[0];
  v25->wind.y = v27->value[1];
  v25->wind.z = v27->value[2];
  v25->wind.w = v27->value[3];
  v28 = this->modelParms;
  v29 = (float *)((char *)v24 + 16 * (int)(rpParticleScale.r[1].resourceError + 3));
  v28->distribScale.x = *v29;
  v28->distribScale.y = v29[1];
  v28->distribScale.z = v29[2];
  v30 = v24->values[NoShadows->parmIndex].value[0] == 0.0;
  v31 = (float *)((char *)v24 + 16 * (int)(rpParticleVel_0.r[1].resourceError + 3));
  p_deferredAxis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_deferredAxis = (float *)&this->g.axis;
  v33 = this->modelParms;
  v34 = v31[2];
  v35 = *v31;
  v36 = *p_deferredAxis;
  v37 = p_deferredAxis[8];
  v38 = (float)((float)(p_deferredAxis[1] * v31[1]) + (float)(p_deferredAxis[2] * v31[2]));
  v39 = (float)((float)(p_deferredAxis[6] * *v31) + (float)(p_deferredAxis[7] * v31[1]));
  v33->velocity.y = (float)(p_deferredAxis[5] * v31[2])
                  + (float)((float)(p_deferredAxis[3] * *v31) + (float)(p_deferredAxis[4] * v31[1]));
  v33->velocity.x = (float)((float)v36 * (float)v35) + (float)v38;
  v33->velocity.z = (float)((float)v37 * (float)v34) + (float)v39;
  y_low = r_testParticleLOD.valueInteger;
  if ( r_testParticleLOD.valueInteger <= 0 )
  {
    LODWORD(v159.y) = (int)*((float *)&renderThreadParmState->renderParmVersion
                           + 4 * (int)(rpParticleLOD.r[1].resourceError + 3));
    y_low = LOBYTE(v159.y);
  }
  this->modelParms->lod = y_low;
  this->modelParms->alphaScaleOverride = *((float *)&renderThreadParmState->renderParmVersion
                                         + 4 * (int)(rpParticleAlphaScale.r[1].resourceError + 3));
  v41 = idRenderModel::GetRenderParmBlock(this);
  idParmState::VirtualRollbackParmBlock(this: renderThreadParmState, localParmBlock: v41, parmBlock: v41);
  maxVisibleRange = this->g.maxVisibleRange;
  if ( maxVisibleRange <= 0.0 || this->g.fadeVisibilityOver <= 0.0 )
  {
    fadeVisibilityOver = this->g.fadeVisibilityOver;
    if ( fadeVisibilityOver >= 0.0 )
      goto LABEL_26;
    p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
    if ( !this->useDeferredPosition )
      p_deferredOrigin = &this->g;
    v50 = (float)(currentView->r.vieworg.y - p_deferredOrigin->origin.y);
    v51 = (float)(currentView->r.vieworg.z - p_deferredOrigin->origin.z);
    v159.x = currentView->r.vieworg.x - p_deferredOrigin->origin.x;
    v159.y = v50;
    v159.z = v51;
    v47 = (float)((float)(idVec3::NormalizeFast(this: &v159) - (float)-fadeVisibilityOver) / (float)-fadeVisibilityOver);
  }
  else
  {
    p_g = (idRenderModelParms *)&this->deferredOrigin;
    if ( !this->useDeferredPosition )
      p_g = &this->g;
    v44 = (float)(currentView->r.vieworg.y - p_g->origin.y);
    v45 = (float)(currentView->r.vieworg.z - p_g->origin.z);
    v159.x = currentView->r.vieworg.x - p_g->origin.x;
    v159.y = v44;
    v159.z = v45;
    v46 = this->g.fadeVisibilityOver;
    v47 = (float)((float)1.0
                - (float)((float)(idVec3::NormalizeFast(this: &v159) - (float)v46)
                        / (float)((float)maxVisibleRange - (float)v46)));
  }
  if ( v47 >= 0.0 )
  {
    if ( v47 > 1.0 )
      v47 = 1.0;
  }
  else
  {
    v47 = 0.0;
  }
  this->modelParms->coverage = this->modelParms->coverage * (float)v47;
LABEL_26:
  if ( v30 )
  {
    World = idRenderModel::GetWorld(this);
    World->ShadowSample(this: World, a2: &this->modelParms->origin);
  }
  else
  {
    v53 = 1.0;
  }
  this->modelParms->shadow = v53;
  v54 = (idRenderModelParms *)&this->deferredOrigin;
  if ( !this->useDeferredPosition )
    v54 = &this->g;
  v55 = this->modelParms;
  v55->origin.x = v54->origin.x;
  v55->origin.y = v54->origin.y;
  v55->origin.z = v54->origin.z;
  p_axis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_axis = (float *)&this->g.axis;
  v57 = (float *)&this->modelParms->axis;
  *v57 = *p_axis;
  v57[1] = p_axis[1];
  v57[2] = p_axis[2];
  v57[3] = p_axis[3];
  v57[4] = p_axis[4];
  v57[5] = p_axis[5];
  v57[6] = p_axis[6];
  v57[7] = p_axis[7];
  v57[8] = p_axis[8];
  v58 = this->modelParms;
  v58->scale.x = this->g.scale.x;
  v58->scale.y = this->g.scale.y;
  v58->scale.z = this->g.scale.z;
  this->modelParms->diversity = (int)(float)((float)v19 * (float)32767.0);
  v59 = idRenderModelTransparency::mappedBufferIndex;
  v60 = (idRenderModelTransparency::mappedBufferIndex + 2) % 3;
  if ( r_showParticleBounds.valueInteger != 0 && idRenderModel::GetWorld(this) != nullptr )
  {
    v61 = (float *)&this->deferredAxis;
    if ( !this->useDeferredPosition )
      v61 = (float *)&this->g.axis;
    particleDecl = (float *)this->particleDecl;
    v64 = (float)((float)((float)((float)(particleDecl[37] + particleDecl[34]) * (float)0.5) * *v61)
                + (float)((float)(v61[6] * (float)((float)(particleDecl[39] + particleDecl[36]) * (float)0.5))
                        + (float)(v61[3] * (float)((float)(particleDecl[38] + particleDecl[35]) * (float)0.5))));
    v65 = (float)((float)(v61[1] * (float)((float)(particleDecl[37] + particleDecl[34]) * (float)0.5))
                + (float)((float)(v61[7] * (float)((float)(particleDecl[39] + particleDecl[36]) * (float)0.5))
                        + (float)(v61[4] * (float)((float)(particleDecl[38] + particleDecl[35]) * (float)0.5))));
    v66 = (float)((float)(v61[2] * (float)((float)(particleDecl[37] + particleDecl[34]) * (float)0.5))
                + (float)((float)(v61[8] * (float)((float)(particleDecl[39] + particleDecl[36]) * (float)0.5))
                        + (float)(v61[5] * (float)((float)(particleDecl[38] + particleDecl[35]) * (float)0.5))));
    v63 = (idRenderModelParms *)&this->deferredOrigin;
    if ( !this->useDeferredPosition )
      v63 = &this->g;
    v67 = (float)(v63->origin.y + (float)v65);
    v68 = (float)(v63->origin.z + (float)v66);
    v163[0] = (float)v64 + v63->origin.x;
    v163[1] = v67;
    v163[2] = v68;
    v69 = idRenderModel::GetWorld(this);
    str = this->particleDecl->name.str;
    Index = idRenderModel::GetIndex(this);
    LODWORD(v72) = &unk_82200000;
    v74 = va::va(
            this: &v165,
            fmt: "%d:%s",
            a3: __SPAIR64__(Index, (unsigned int)str),
            a4: v73,
            a5: v72,
            a6: SHIDWORD(v154),
            a7: v154,
            a8: v155,
            a9: v156,
            a10: v157,
            a11: v158);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v69->DebugText)(
      a1: v69,
      a2: v74,
      a3: v163,
      a4: v69->DebugText,
      a5: &idColor::colorYellow,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.30000001);
    v75 = &this->deferredAxis;
    z = this->g.scale.z;
    x = this->g.scale.x;
    v78 = this->modelParms;
    useDeferredPosition = this->useDeferredPosition;
    v160.y = this->g.scale.y;
    v162.b[1].z = -1.0e30;
    v160.z = z;
    v162.b[0].z = 1.0e30;
    v160.x = x;
    v162.b[0].y = 1.0e30;
    v162.b[0].x = 1.0e30;
    v162.b[1].y = v162.b[1].z;
    v162.b[1].x = v162.b[1].z;
    v160.x = v78->distribScale.x * x;
    v160.y = v78->distribScale.y * v160.y;
    v160.z = v78->distribScale.z * z;
    if ( useDeferredPosition )
    {
      v80 = (idRenderModelParms *)&this->deferredOrigin;
    }
    else
    {
      v75 = &this->g.axis;
      v80 = &this->g;
    }
    idBounds::FromTransformedBounds(
      this: &v162,
      bounds: &this->particleDecl->bounds,
      origin: &v80->origin,
      axis: v75,
      scale: &v160);
    v81 = idRenderModel::GetWorld(this);
    v164[1] = 0.0;
    v164[3] = 1.0;
    v164[2] = 0.0;
    v164[0] = 1.0;
    v81->DebugBounds(this: v81, a2: (const idVec4 *)v164, a3: &v162, a4: &vec3_origin, a5: 0, a6: false);
  }
  if ( r_showParticleDistVol.valueInteger != 0 )
    idRenderModelParticle::DrawDistributionVolumes(this);
  if ( r_showParticleInfo.valueInteger != 0 )
  {
    v82 = 0;
    v83 = (char *)this + 16 * v60;
    v84 = 0;
    v85 = 0;
    v86 = 0;
    v87 = *((_DWORD *)v83 + 515);
    if ( v87 >= 2 )
    {
      v88 = *((_DWORD *)v83 + 514);
      v89 = 0;
      do
      {
        v86 += 2;
        v82 += *(_DWORD *)(v88 + v89);
        v90 = *(_DWORD *)(v88 + v89 + 8);
        v89 += 16;
        v84 += v90;
      }
      while ( v86 < v87 - 1 );
    }
    if ( v86 < v87 )
      v85 = *(_DWORD *)(*((_DWORD *)v83 + 514) + 8 * v86);
    v91 = v82 + v84 + v85;
    v92 = (_cntlzw(r_showParticleInfo.valueInteger - 1) & 0x20) != 0;
    v93 = (float *)&this->deferredAxis;
    if ( !this->useDeferredPosition )
      v93 = (float *)&this->g.axis;
    v94 = (float *)this->particleDecl;
    v96 = (float)((float)((float)((float)(v94[37] + v94[34]) * (float)0.5) * *v93)
                + (float)((float)(v93[6] * (float)((float)(v94[39] + v94[36]) * (float)0.5))
                        + (float)(v93[3] * (float)((float)(v94[38] + v94[35]) * (float)0.5))));
    v97 = (float)((float)(v93[1] * (float)((float)(v94[37] + v94[34]) * (float)0.5))
                + (float)((float)(v93[7] * (float)((float)(v94[39] + v94[36]) * (float)0.5))
                        + (float)(v93[4] * (float)((float)(v94[38] + v94[35]) * (float)0.5))));
    v98 = (float)((float)(v93[2] * (float)((float)(v94[37] + v94[34]) * (float)0.5))
                + (float)((float)(v93[8] * (float)((float)(v94[39] + v94[36]) * (float)0.5))
                        + (float)(v93[5] * (float)((float)(v94[38] + v94[35]) * (float)0.5))));
    v95 = (idRenderModelParms *)&this->deferredOrigin;
    if ( !this->useDeferredPosition )
      v95 = &this->g;
    v99 = (float)(v95->origin.y + (float)v97);
    v100 = (float)(v95->origin.z + (float)v98);
    v161[0] = (float)v96 + v95->origin.x;
    v161[1] = v99;
    v161[2] = v100;
    v101 = idRenderModel::GetWorld(this);
    LODWORD(v102) = 2 * (v91 >> 2);
    HIDWORD(v102) = this->particleDecl;
    v103 = v101;
    LODWORD(v104) = this->modelParms->lod;
    LODWORD(v105) = v91;
    HIDWORD(v105) = *(_DWORD *)(HIDWORD(v102) + 8);
    HIDWORD(v104) = 6 * (v91 >> 2);
    v106 = va::va(
             this: &v165,
             fmt: "%s : total verts %d total indices %d LOD %d",
             a3: v105,
             a4: v104,
             a5: v102,
             a6: SHIDWORD(v154),
             a7: v154,
             a8: v155,
             a9: v156,
             a10: v157,
             a11: v158);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, BOOL, double))v103->DebugText)(
      a1: v103,
      a2: v106,
      a3: v161,
      a4: v103->DebugText,
      a5: &idColor::colorYellow,
      a6: 1,
      a7: 0,
      a8: v92,
      a9: 0.1);
    if ( r_showParticleInfo.valueInteger == 3 )
      idLib::Printf(
        fmt: "%s : total verts %d total indices %d LOD %d\n",
        this->particleDecl->name.str,
        v91,
        6 * (v91 >> 2),
        this->modelParms->lod);
  }
  v107 = this->particleDecl;
  v108 = 0;
  num = v107->stages.num;
  if ( num > 0 )
  {
    v110 = 0;
    v111 = 0;
    v112 = 0;
    do
    {
      v113 = v107->stages.list[v112];
      if ( v108 < this->surfaces.num )
      {
        v114 = &this->surfaces.list[v111];
        v114->geometry->numVerts = 0;
        v114->geometry->numIndexes = 0;
        v114->material = nullptr;
        material = v113->systemProperties.material;
        if ( material != nullptr
          && (*((_BYTE *)v113 + 68) & 0x40) == 0
          && v113->cycleMsec != 0
          && (*((_BYTE *)v113 + 68) & 8) == 0 )
        {
          v116 = v113->bounds.b[0].x;
          v117 = v113->bounds.b[1].x;
          y = v113->bounds.b[0].y;
          v119 = v113->bounds.b[0].z;
          v120 = v113->bounds.b[1].y;
          geometry = v114->geometry;
          v122 = v113->bounds.b[1].z;
          v123 = &this->stageCounts[v60].list[v110];
          vertCount = v123->vertCount;
          indexOffset = v123->indexOffset;
          v126 = v123->vertCount >> 2;
          v114->material = material;
          v127 = 3 * v126;
          v128 = this->modelParms;
          v129 = v128->distribScale.y;
          v130 = v128->distribScale.z;
          v131 = (float)(v128->distribScale.x + (float)v117);
          geometry->bounds.b[0].x = (float)v116 - v128->distribScale.x;
          geometry->bounds.b[1].x = v131;
          geometry->bounds.b[0].y = (float)y - (float)v129;
          geometry->bounds.b[0].z = (float)v119 - (float)v130;
          geometry->bounds.b[1].y = (float)v120 + (float)v129;
          v132 = 2 * v127;
          geometry->bounds.b[1].z = (float)v122 + (float)v130;
          geometry->numVerts = vertCount;
          v114->geometry->numIndexes = 2 * v127;
          idVertexBuffer::Reference(
            this: &v114->geometry->vertexBuffer,
            other: &idRenderModelTransparency::vertexBufferUnsorted[v60]);
          idIndexBuffer::Reference(
            this: &v114->geometry->indexBuffer,
            other: &idRenderModelTransparency::indexBufferUnsorted,
            refOffset: 2 * indexOffset,
            refSize: 2 * v132);
        }
      }
      v107 = this->particleDecl;
      ++v108;
      ++v112;
      ++v111;
      ++v110;
      num = v107->stages.num;
    }
    while ( v108 < num );
  }
  v133 = 0;
  visibleInfluenceSpheres = updateTools->transparencyModel->visibleInfluenceSpheres;
  LODWORD(v159.x) = this->modelParms->diversity;
  if ( num > 0 )
  {
    v135 = 0;
    v136 = 0;
    v137 = 0;
    do
    {
      if ( v133 < this->surfaces.num )
      {
        v138 = (char *)this + 16 * v59;
        v139 = this->particleDecl->stages.list[v137];
        *(_DWORD *)(v136 + *((_DWORD *)v138 + 514)) = 0;
        *(_DWORD *)(v136 + *((_DWORD *)v138 + 514) + 4) = 0;
        Tables = (idRandom2 *)idDeclParticle::GetTables(this: this->particleDecl);
        v143 = idParticleParm::Compute(
                 this: &v139->systemProperties.deadTime,
                 tables: Tables,
                 frac: 1.0,
                 rand: v142,
                 a5: (idRandom2 *)&v159,
                 a6: v141);
        v144 = this->modelParms;
        v145 = this->particleRenderView;
        LODWORD(v146) = v144->lod;
        v149 = idRenderModelParticle::EstimateVertAllocation(
                 stage: v139,
                 renderTime: v145->renderTime,
                 timeOffset: v144->timeOffset,
                 stopTime: v148,
                 deadTime: v143,
                 lodLevel: v146,
                 a7: v147,
                 a8: v154);
        v150 = v149;
        if ( v149 != 0 )
        {
          if ( v149 >= 512 )
            v150 = 512;
          this->genParms.list[v135].renderView = v145;
          this->genParms.list[v135].effectParticleParms = nullptr;
          this->genParms.list[v135].modelParticleParms = this->modelParms;
          this->genParms.list[v135].stage = v139;
          v151 = &this->genParms.list[v135];
          v151->tables = idDeclParticle::GetTables(this: this->particleDecl);
          this->genParms.list[v135].staticVerts = v139->staticVerts;
          this->genParms.list[v135].numEffectParticleParms = 0;
          this->genParms.list[v135].numModelParticleParms = 1;
          this->genParms.list[v135].numTables = this->particleDecl->tables.num;
          this->genParms.list[v135].staticVertsSize = v139->numStaticVerts;
          this->genParms.list[v135].deadTime = v143;
          this->genParms.list[v135].visibleInfluenceSpheres = visibleInfluenceSpheres;
          this->genParms.list[v135].maxVertsToGen = v150;
          this->genParms.list[v135].verts = nullptr;
          this->genParms.list[v135].quadDepth = nullptr;
          this->genParms.list[v135].quadsUsed = nullptr;
          if ( (*((_BYTE *)v139->systemProperties.material + 72) & 8) != 0 )
          {
            if ( r_skipParticles.valueInteger != 1 && r_skipParticles.valueInteger != 3 )
            {
              v152 = !idRenderModelTransparency::AllocateQuadSegment(
                        numQuads: v150 >> 2,
                        verts: &this->genParms.list[v135].verts,
                        quadDepths: &this->genParms.list[v135].quadDepth,
                        quadsUsed: &this->genParms.list[v135].quadsUsed,
                        hasEmissivePass: (*((_BYTE *)v139 + 68) & 0x10) != 0);
              goto LABEL_80;
            }
          }
          else if ( r_skipParticles.valueInteger != 1 && r_skipParticles.valueInteger != 2 )
          {
            v152 = !idRenderModelTransparency::AllocateUnsortedQuadSegment(
                      numQuads: v150 >> 2,
                      verts: &this->genParms.list[v135].verts,
                      indexOffset: (int *)(v136 + *((_DWORD *)v138 + 514) + 4),
                      vertCount: (int *)(v136 + *((_DWORD *)v138 + 514)));
LABEL_80:
            if ( !v152 )
            {
              list = this->genParms.list;
              if ( valueInteger == 1 )
                idParallelJobList::AddJob(
                  this: updateTools->transparencyJobList,
                  function: (void (__fastcall *)(void *))ParticleGenJob,
                  data: &list[v135]);
              else
                ParticleGenJob(parms: &list[v135]);
              ++v135;
            }
          }
        }
      }
      ++v133;
      ++v137;
      v136 += 8;
    }
    while ( v133 < this->particleDecl->stages.num );
  }
  if ( r_recordModelParticleTrace.valueInteger != 0 )
    idCVar::SetBool(this: &r_recordModelParticleTrace, newValue: false, force: true);
  return 1;
}


// ========================================================================
// ??0idRenderModelParticle@@QAA@PBVidDeclParticle@@@Z
// EA  : 0x827F2410
// RVA : 0x007F2410
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

idRenderModelParticle *__fastcall idRenderModelParticle::idRenderModelParticle(
        idRenderModelParticle *this,
        const idDeclParticle *decl)
{
  char v4; // r10
  char v5; // r8
  const idDeclParticle *particleDecl; // r9
  int num; // r23
  int v8; // r27
  int v9; // r26
  idParticleStage *v10; // r29
  idTriangles *v11; // r3
  idTriangles *v12; // r11
  int *p_size; // r29
  int i; // r28
  int v15; // r11
  int size; // r11
  idRenderModel *material; // [sp+70h] [-B0h]

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelParticle_vtbl *)&idRenderModelParticle::`vftable';
  this->genParms.list = nullptr;
  this->genParms.granularity = 0;
  this->genParms.memTag = 5;
  this->genParms.listStatic = 0;
  this->genParms.size = 0;
  this->genParms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->genParms);
  `eh vector constructor iterator'(
    ptr: this->stageCounts,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->particleDecl = decl;
  idRenderModel::SetName(this, name_: decl->name.str);
  this->referenceBounds = decl->bounds;
  v4 = *((_BYTE *)&this->g + 116);
  v5 = *((_BYTE *)&this->g + 106);
  particleDecl = this->particleDecl;
  *((_BYTE *)&this->g + 105) |= 0xC0u;
  *((_BYTE *)&this->g + 106) = v5 | 4;
  *((_BYTE *)&this->g + 116) = v4 | 0x20;
  num = particleDecl->stages.num;
  if ( num > 0 )
  {
    v8 = 0;
    v9 = particleDecl->stages.num;
    do
    {
      v10 = this->particleDecl->stages.list[v8];
      v11 = (idTriangles *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x84u,
                             tag: TAG_TRIANGLES,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v11 != nullptr )
        v12 = idTriangles::idTriangles(this: v11);
      else
        v12 = nullptr;
      v12->bounds.b[0].x = v10->bounds.b[0].x;
      v12->bounds.b[0].y = v10->bounds.b[0].y;
      material = (idRenderModel *)v10->systemProperties.material;
      v12->bounds.b[0].z = v10->bounds.b[0].z;
      v12->bounds.b[1].x = v10->bounds.b[1].x;
      v12->bounds.b[1].y = v10->bounds.b[1].y;
      v12->bounds.b[1].z = v10->bounds.b[1].z;
      v12->vertexMask = 3167;
      idRenderModel::AddSurface(this: material, surf: nullptr);
      --v9;
      ++v8;
    }
    while ( v9 != 0 );
  }
  p_size = &this->stageCounts[0].size;
  for ( i = 3; i != 0; --i )
  {
    if ( num <= *p_size
      || (unsigned __int8)idList<idStateTransition::transDest_t,111>::Resize(
                            this: (idList<swfGlyphEntry_t,72> *)(p_size - 2),
                            newsize: num) != 0 )
    {
      v15 = *p_size;
      if ( num < *p_size )
        v15 = num;
      *(p_size - 1) = v15;
    }
    p_size += 4;
  }
  if ( num <= this->genParms.size
    || (unsigned __int8)idList<deferredParticleGenParms_t,5>::Resize(this: &this->genParms, newsize: num) != 0 )
  {
    size = this->genParms.size;
    if ( num < size )
      size = num;
    this->genParms.num = size;
  }
  this->particleRenderView = (particleRenderView_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\models\\particles\\RenderModelParticle.cpp(80) : TAG_PARTICLE",
                                                       size: 0x40u,
                                                       tag: TAG_PARTICLE,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  this->modelParms = (modelParticleParms_t *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\engine\\models\\particles\\RenderModelParticle.cpp(81) : TAG_PARTICLE",
                                               size: 0x90u,
                                               tag: TAG_PARTICLE,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$232750
// EA  : 0x827F2724
// RVA : 0x007F2724
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_232750()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 288 + 308));
}


// ========================================================================
// __unwind$232751
// EA  : 0x827F274C
// RVA : 0x007F274C
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_232751()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 2032));
}


// ========================================================================
// __unwind$232752
// EA  : 0x827F2778
// RVA : 0x007F2778
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_232752()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 288 + 308) + 2056),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$232753
// EA  : 0x827F27B4
// RVA : 0x007F27B4
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _unwind_232753()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// `dynamic initializer for 'r_showParticleBounds''
// EA  : 0x83343400
// RVA : 0x01343400
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showParticleBounds__()
{
  idCVar::idCVar(
    this: &r_showParticleBounds,
    name: "r_showParticleBounds",
    value: "0",
    flags: 1,
    description: "draw particle bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showParticleBounds__);
}


// ========================================================================
// `dynamic initializer for 'r_showParticleDistVol''
// EA  : 0x83343458
// RVA : 0x01343458
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showParticleDistVol__()
{
  idCVar::idCVar(
    this: &r_showParticleDistVol,
    name: "r_showParticleDistVol",
    value: "0",
    flags: 1,
    description: "visualize the distribution volume for each stage of the particle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showParticleDistVol__);
}


// ========================================================================
// `dynamic initializer for 'r_showParticleInfo''
// EA  : 0x833434B0
// RVA : 0x013434B0
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showParticleInfo__()
{
  idCVar::idCVar(
    this: &r_showParticleInfo,
    name: "r_showParticleInfo",
    value: "0",
    flags: 2,
    description: "1 = show particle counts depth-tested, 2 = show particle counts non-depth-tested, 3 = dump particle info to console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showParticleInfo__);
}


// ========================================================================
// `dynamic initializer for 'r_skipParticles''
// EA  : 0x83343508
// RVA : 0x01343508
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipParticles__()
{
  idCVar::idCVar(
    this: &r_skipParticles,
    name: "r_skipParticles",
    value: "0",
    flags: 2,
    description: "1 = skip all particle systems, 2 = skip all non-transsort particles, 3 = skip all transsort particles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipParticles__);
}


// ========================================================================
// `dynamic initializer for 'r_useParticleGenJobs''
// EA  : 0x83343560
// RVA : 0x01343560
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useParticleGenJobs__()
{
  idCVar::idCVar(
    this: &r_useParticleGenJobs,
    name: "r_useParticleGenJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useParticleGenJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_testParticleLOD''
// EA  : 0x833435C8
// RVA : 0x013435C8
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testParticleLOD__()
{
  idCVar::idCVar(
    this: &r_testParticleLOD,
    name: "r_testParticleLOD",
    value: "0",
    flags: 2,
    description: "which lod level to apply",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_82200000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testParticleLOD__);
}


// ========================================================================
// `dynamic initializer for 'r_recordModelParticleTrace''
// EA  : 0x83343630
// RVA : 0x01343630
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_recordModelParticleTrace__()
{
  idCVar::idCVar(
    this: &r_recordModelParticleTrace,
    name: "r_recordModelParticleTrace",
    value: "0",
    flags: 1,
    description: "record particle timing using PIX trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_recordModelParticleTrace__);
}


// ========================================================================
// `dynamic initializer for 'rpParticleAlphaScale''
// EA  : 0x83343688
// RVA : 0x01343688
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleAlphaScale__()
{
  rpParticleAlphaScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleAlphaScale;
}


// ========================================================================
// `dynamic initializer for 'rpParticleScale''
// EA  : 0x833436A8
// RVA : 0x013436A8
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleScale__()
{
  rpParticleScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleScale;
}


// ========================================================================
// `dynamic initializer for 'rpParticleVel''_0
// EA  : 0x833436C8
// RVA : 0x013436C8
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleVel___0()
{
  rpParticleVel_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleVel_0;
}


// ========================================================================
// `dynamic initializer for 'rpParticleLOD''
// EA  : 0x833436E8
// RVA : 0x013436E8
// PDB : w:\tech5\engine\models\particles\rendermodelparticle.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleLOD__()
{
  rpParticleLOD.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleLOD;
}

