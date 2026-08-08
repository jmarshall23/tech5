
// ========================================================================
// ?CalculateBuoyancyWeights@idBuoyancy@@AAAXPBHPBVidPlane@@HPBVidClipModel@@QAM@Z
// EA  : 0x8272A8E0
// RVA : 0x0072A8E0
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

void __fastcall idBuoyancy::CalculateBuoyancyWeights(
        idBuoyancy *this,
        const int *polytopeNumPlanes,
        const idPlane *polytopePlanes,
        int numPolytopes,
        const idClipModel *clipModel,
        float *weights)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  int v12; // r27
  idTraceModelCache::trmCache_t *v13; // r11
  float *v14; // r10
  float *p_weight; // r11
  int i; // ctr
  double v17; // fp13
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp9
  double v22; // fp8
  double v23; // fp7
  double v24; // fp0
  int v33; // r16
  int v35; // r15
  int v36; // r14
  const int *v50; // r8
  int v52; // r15
  int v57; // ctr
  float *v61; // r11
  float *v62; // r10
  int j; // ctr
  double v64; // fp10
  double v65; // fp13
  double v66; // fp2
  double v67; // fp9
  double v68; // fp7
  double v69; // fp3
  double v70; // fp1
  double v71; // fp0
  idPLog *pLog; // r29
  idPLog::logEntry_t *v73; // r30
  int v74; // r3
  __int64 totalTicks; // r11
  __int64 v76; // r9
  const int *v77; // [sp+50h] [-370h]
  traceModelWater_t *list; // [sp+54h] [-36Ch]
  int v79; // [sp+58h] [-368h]
  int v80; // [sp+5Ch] [-364h]
  int v81; // [sp+60h] [-360h]
  int v82; // [sp+64h] [-35Ch]
  int v83; // [sp+68h] [-358h]
  float *v84; // [sp+6Ch] [-354h]
  int v85; // [sp+70h] [-350h]
  idPLogScope v86; // [sp+78h] [-348h] BYREF
  int v87; // [sp+80h] [-340h] BYREF
  _DWORD v88[3]; // [sp+84h] [-33Ch] BYREF
  _DWORD v89[4]; // [sp+90h] [-330h] BYREF
  _BYTE v90[640]; // [sp+A0h] [-320h] BYREF

  RD_EventBegin(name: "idBuoyancy::CalculateBuoyancyWeights");
  LODWORD(v10) = "idBuoyancy::CalculateBuoyancyWeights";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v86, pl: &::pLog, gMask: v10, label: v11);
  v12 = 0;
  if ( clipModel->traceModels.num <= 0 )
  {
    list = nullptr;
  }
  else
  {
    v13 = clipModel->clip->traceModelCache->cache.list[*clipModel->traceModels.list];
    if ( v13->hasWater )
      list = v13->waterPoints.list;
    else
      list = nullptr;
  }
  v14 = (float *)&v90[252];
  p_weight = &list[-1].weight;
  for ( i = 8; i != 0; --i )
  {
    v17 = p_weight[4];
    v18 = p_weight[8];
    v19 = p_weight[12];
    v20 = p_weight[16];
    v21 = p_weight[20];
    v22 = p_weight[24];
    v23 = p_weight[28];
    p_weight += 32;
    v24 = *p_weight;
    v14[1] = v17;
    v14[2] = v18;
    v14[3] = v19;
    v14[4] = v20;
    v14[5] = v21;
    v14[6] = v22;
    v14[7] = v23;
    v14 += 8;
    *v14 = v24;
  }
  memset(Dst: weights, Val: 0, Size: 0x100u);
  _R30 = 16;
  _R10 = &clipModel->origin;
  v89[3] = 0;
  _R9 = &clipModel->axis;
  v87 = 0;
  _R8 = &clipModel->axis.mat[1];
  v88[0] = 0;
  _R7 = &clipModel->axis.mat[2];
  v88[1] = 0;
  _R6 = v89;
  __asm { lvrx128   v62, r30, r10 }
  _R5 = &_vmx_00000000000000000000000000000000;
  __asm
  {
    lvlx128   v61, r0, r10
    lvrx128   v60, r30, r9
  }
  __asm
  {
    lvlx128   v58, r0, r9
    vor128    v59, v93, v62
    lvrx128   v57, r30, r8
    vor128    v56, v90, v60
    lvlx128   v55, r0, r8
  }
  memset(v89, 255, 12);
  __asm
  {
    lvrx128   v54, r30, r7
    vor128    v53, v87, v57
    lvlx128   v52, r0, r7
  }
  __asm
  {
    vor128    v51, v84, v54
    lvx128    v126, r0, r5
  }
  __asm { lvx128    v63, r0, r6 }
  v88[2] = -1;
  __asm
  {
    vmr128    v127, v126
    vand128   v125, v91, v63
    vand128   v124, v88, v63
    vand128   v123, v85, v63
    vand128   v122, v83, v63
  }
  if ( numPolytopes > 0 )
  {
    v77 = polytopeNumPlanes;
    v79 = numPolytopes;
    v33 = &v90[4] - (_BYTE *)weights;
    v85 = &v90[4] - (_BYTE *)weights;
    v81 = &v90[20] - (_BYTE *)weights;
    _R11 = &v87;
    v35 = &v90[8] - (_BYTE *)weights;
    __asm { lvx128    v121, r0, r11 }
    v84 = weights + 2;
    v82 = &v90[8] - (_BYTE *)weights;
    v36 = v90 - (_BYTE *)weights;
    v80 = &v90[12] - (_BYTE *)weights;
    v83 = &v90[16] - (_BYTE *)weights;
    _R28 = -16;
    _R29 = 32;
    _R17 = 48;
    _R18 = 64;
    _R19 = 80;
    _R20 = 96;
    _R21 = 112;
    _R22 = 128;
    _R23 = 144;
    _R24 = 160;
    _R25 = 176;
    _R26 = 208;
    do
    {
      memcpy(Dst: v90, Src: &v90[256], Size: 0x100u);
      v50 = v77;
      if ( *v77 > 0 )
      {
        _R4 = &polytopePlanes[v12];
        v52 = *v77;
        v12 += *v77;
        do
        {
          __asm
          {
            vmr128    v13, v125
            lvx128    v0, r0, r4
            vmr128    v12, v124
          }
          __asm { vmr128    v11, v123 }
          _R10 = &v90[16];
          _R9 = list + 14;
          __asm { vmaddcfp128 v13, v0, v13, v126 }
          _R11 = list + 2;
          _R8 = -32;
          v57 = 4;
          _R7 = -16;
          _R6 = 16;
          _R5 = 32;
          __asm
          {
            vsldoi128 v50, v13, v13, 4
            vaddfp128 v49, v13, v50
            vsldoi128 v48, v81, v49, 8
            vaddfp128 v47, v81, v48
            vand128   v46, v79, v121
            vaddfp128 v13, v0, v46
            vmaddcfp128 v12, v13, v12, v126
            vspltw    v0, v13, 3
            vmaddcfp128 v11, v13, v11, v126
            vmaddcfp128 v13, v122, v13, v126
            vsldoi128 v45, v12, v12, 4
            vsldoi128 v44, v11, v11, 4
            vsldoi128 v43, v13, v13, 4
            vaddfp128 v42, v12, v45
            vaddfp128 v41, v11, v44
            vaddfp128 v40, v13, v43
            vsldoi128 v39, v74, v42, 8
            vsldoi128 v38, v73, v41, 8
            vsldoi128 v37, v72, v40, 8
            vaddfp128 v13, v74, v39
            vaddfp128 v12, v73, v38
            vaddfp128 v11, v72, v37
          }
          do
          {
            __asm
            {
              lvx128    v36, r11, r5
              lvx128    v35, r11, r17
              lvx128    v34, r11, r18
              lvx128    v33, r11, r19
              vmrghw128 v32, v68, v34
              lvx128    v63, r11, r8
              vmrghw128 v62, v67, v33
              lvx128    v61, r11, r7
              lvx128    v60, r0, r11
              vmrglw128 v59, v68, v34
              lvx128    v58, r11, r6
              vmrglw128 v57, v67, v33
              lvx128    v56, r11, r20
              vmrghw128 v55, v95, v60
              lvx128    v54, r11, r21
              vmrghw128 v9, v64, v62
              lvx128    v53, r11, r22
              vmrghw128 v52, v93, v58
              lvx128    v51, r11, r23
              vmrglw128 v8, v64, v62
              lvx128    v50, r0, r9
              vmrghw128 v49, v88, v53
              lvx128    v48, r11, r24
              vmrghw128 v47, v86, v51
              lvx128    v46, r11, r25
              vmaddfp   v6, v13, v0, v9
              lvx128    v45, r11, r26
              vmrghw128 v44, v80, v50
              vmrghw128 v10, v87, v52
              lvx128    v43, r0, r10
              vmrghw128 v42, v78, v45
              lvx128    v41, r10, r28
              vmrghw128 v7, v81, v47
              lvx128    v40, r10, r30
              vmrglw128 v39, v95, v60
              lvx128    v38, r10, r29
              vmaddfp   v5, v13, v0, v10
              vmrglw128 v10, v87, v52
              vmrghw128 v9, v76, v42
            }
            _R11 += 16;
            __asm
            {
              vmaddfp   v4, v13, v0, v7
              vmrglw128 v7, v81, v47
              vmrglw128 v37, v93, v58
            }
            _R9 += 64;
            __asm
            {
              vmrglw128 v36, v88, v53
              vmaddfp   v3, v13, v0, v9
              vmrglw128 v35, v86, v51
              vmaddfp   v2, v12, v6, v8
              vmrglw128 v6, v76, v42
              vmrglw128 v34, v80, v50
              vmrglw128 v33, v78, v45
              vmrghw128 v9, v91, v57
              vmrghw128 v8, v68, v35
              vmaddfp   v5, v12, v5, v10
              vmrghw128 v10, v71, v37
              vmaddfp   v4, v12, v4, v7
              vmrghw128 v7, v66, v33
              vmaddfp   v6, v12, v3, v6
              vmaddfp   v9, v11, v2, v9
              vmaddfp   v10, v11, v5, v10
              vmaddfp   v8, v11, v4, v8
              vmaddfp   v7, v11, v6, v7
              vcmpgtfp128 v32, v127, v9
              vcmpgtfp128 v63, v127, v10
              vcmpgtfp128 v62, v127, v8
              vcmpgtfp128 v61, v127, v7
              vand128   v60, v75, v32
              stvx128   v60, r0, r10
              vand128   v59, v73, v63
              vand128   v58, v72, v62
              stvx128   v59, r10, r28
              vand128   v57, v70, v61
              stvx128   v58, r10, r30
              stvx128   v57, r10, r29
            }
            _R10 += 64;
            --v57;
          }
          while ( v57 != 0 );
          --v52;
          ++_R4;
        }
        while ( v52 != 0 );
        v35 = v82;
        v33 = v85;
        v50 = v77;
      }
      v61 = v84;
      v62 = (float *)v88;
      for ( j = 8; j != 0; --j )
      {
        v64 = (float)(*(v61 - 2) + v62[7]);
        v65 = (float)(*(float *)((char *)v61 + v33) + v61[1]);
        v66 = (float)(*(float *)((char *)v61 + v36) + *v61);
        v67 = (float)(*(float *)((char *)v61 + v35) + v61[2]);
        v68 = (float)(*(float *)((char *)v61 + v80) + v61[3]);
        v69 = (float)(*(float *)((char *)v61 + v83) + v61[4]);
        v62 += 8;
        v70 = (float)(*(float *)((char *)v61 + v81) + v61[5]);
        v71 = (float)(*(v61 - 1) + *v62);
        *(v61 - 2) = v64;
        *(v61 - 1) = v71;
        *v61 = v66;
        v61[1] = v65;
        v61[2] = v67;
        v61[3] = v68;
        v61[4] = v69;
        v61[5] = v70;
        v61 += 8;
      }
      v77 = v50 + 1;
      --v79;
    }
    while ( v79 != 0 );
  }
  if ( v86.logIndex >= 0 )
  {
    pLog = v86.pLog;
    v73 = &v86.pLog->logEntries.list[v86.logIndex];
    v74 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v73->totalTicks;
    HIDWORD(totalTicks) = v73->parent;
    LODWORD(v76) = v74 - totalTicks;
    v73->totalTicks = v76;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$246539
// EA  : 0x8272AE3C
// RVA : 0x0072AE3C
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

void _unwind_246539()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 960 + 672));
}


// ========================================================================
// ?ApplyBuoyancy@idBuoyancy@@QAAXPAVidClip@@PAVidPhysics@@MPBVidDeclDamage@@ABVidVec3@@MMHW4surfTypes_t@@@Z
// EA  : 0x8272AE70
// RVA : 0x0072AE70
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idBuoyancy::ApplyBuoyancy(
        idBuoyancy *this,
        idClip *clip,
        idPhysics *physics,
        double timeStep,
        const idDeclDamage *waterDamage,
        const idVec3 *waterCurrent,
        double waterDensity,
        double waterViscosity,
        int clipMask,
        surfTypes_t surfOverride,
        int a11,
        int a12,
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
        surfTypes_t a33)
{
  double v33; // fp26
  idBuoyancy *v34; // r3
  idBuoyancy *v35; // r22
  double v36; // fp2
  double v37; // fp24
  double v38; // fp3
  double v39; // fp23
  idClip *v40; // r4
  idClip *v41; // r30
  _DWORD *v42; // r5
  _DWORD *v43; // r25
  const idDeclDamage *v44; // r7
  const idDeclDamage *v45; // r16
  float *v46; // r8
  float *v47; // r18
  unsigned __int64 v48; // r6
  const char *v49; // r7
  int v50; // ctr
  __int16 *p_granularity; // r11
  const idBounds *v52; // r3
  int ClipModelsTouchingBounds; // r28
  idClipModel *v54; // r3
  idCollisionModel *CollisionModel; // r3
  idGame *v56; // r3
  int v57; // r30
  idGame *v58; // r3
  const char *v59; // r4
  int v60; // r17
  float *v61; // r30
  float *v62; // r3
  int *v63; // r7
  int v64; // ctr
  float *v65; // r11
  int v66; // r8
  int i; // r9
  double v68; // fp0
  double v69; // fp11
  double v70; // fp9
  double v71; // fp8
  double v72; // fp7
  double v73; // fp1
  double v74; // fp0
  double v75; // fp13
  float *v76; // r24
  idClipModel **v77; // r21
  int j; // r20
  idClipModel *v79; // r30
  idTraceModelCache::trmCache_t *v80; // r11
  traceModelWater_t *list; // r29
  idPhysics *PhysicsForId; // r3
  idPhysics *v83; // r28
  double v84; // fp30
  double volume; // fp0
  double v86; // fp0
  float *v87; // r26
  float *p_y; // r29
  int v89; // r27
  double v90; // fp27
  double v91; // fp29
  double v92; // fp28
  double v93; // fp31
  double v94; // fp0
  double v95; // fp3
  double v96; // fp12
  double v97; // fp4
  double z; // fp8
  double y; // fp6
  double x; // fp10
  double v101; // fp22
  double v102; // fp2
  double v103; // fp21
  double v104; // fp5
  double v105; // fp7
  double v106; // fp1
  int v107; // r29
  int v108; // r3
  int bodyId; // r29
  int physicsId; // r27
  int v111; // r8
  buoyantClipModel_t *v112; // r7
  int v113; // r10
  int v114; // r28
  int v115; // r8
  int v116; // r29
  int v117; // r9
  idVehicleState **v118; // r11
  buoyantClipModel_t *v119; // r10
  idPhysics *v120; // r3
  idPhysics *v121; // r30
  idPLog *pLog; // r29
  idPLog::logEntry_t *v123; // r30
  int v124; // r3
  __int64 totalTicks; // r11
  __int64 v126; // r9
  physicsType_t type; // [sp+50h] [-92C0h]
  int num; // [sp+50h] [-92C0h]
  idPLogScope v129; // [sp+58h] [-92B8h] BYREF
  buoyantClipModel_t v130; // [sp+60h] [-92B0h] BYREF
  float v131[4]; // [sp+68h] [-92A8h] BYREF
  float v132[6]; // [sp+78h] [-9298h] BYREF
  int v133[32]; // [sp+90h] [-9280h] BYREF
  idList<idVehicleState *,5> v134; // [sp+110h] [-9200h] BYREF
  _BYTE v135[1024]; // [sp+120h] [-91F0h] BYREF
  float v136[61]; // [sp+520h] [-8DF0h] BYREF
  int v137; // [sp+614h] [-8CFCh] BYREF
  idPlane v138[192]; // [sp+620h] [-8CF0h] BYREF
  idClipModel *v139[8216]; // [sp+1220h] [-80F0h] BYREF

  v33 = ((double (*)(void))RtlCheckStack12)();
  v35 = v34;
  v37 = v36;
  v39 = v38;
  v41 = v40;
  v43 = v42;
  v45 = v44;
  v47 = v46;
  RD_EventBegin(name: "idBuoyancy::ApplyBuoyancy");
  LODWORD(v48) = "idBuoyancy::ApplyBuoyancy";
  HIDWORD(v48) = 2;
  idPLogScope::idPLogScope(this: &v129, pl: &::pLog, gMask: v48, label: v49);
  v134.granularity = 1;
  v134.size = 128;
  v134.num = 0;
  v134.list = (idVehicleState **)v135;
  v134.memTag = 5;
  v50 = 128;
  v134.listStatic = 1;
  p_granularity = &v134.granularity;
  do
  {
    *((_DWORD *)p_granularity + 1) = -1;
    p_granularity += 4;
    *(_DWORD *)p_granularity = -1;
    --v50;
  }
  while ( v50 != 0 );
  v52 = (const idBounds *)(*(int (__fastcall **)(_DWORD *, int))(*v43 + 44))(a1: v43, a2: -1);
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: v41,
                               bounds: v52,
                               clipMask: a31,
                               clipModelList: v139,
                               maxCount: 0x2000);
  if ( ClipModelsTouchingBounds > 0 )
  {
    v54 = (idClipModel *)(*(int (__fastcall **)(_DWORD *, _DWORD))(*v43 + 8))(a1: v43, a2: 0);
    if ( v54 == nullptr || (CollisionModel = idClipModel::GetCollisionModel(this: v54, index: 0)) == nullptr )
    {
      v56 = common->Game(this: common);
      v57 = (int)v56->GetEntity(this: v56, a2: v43[4]);
      if ( v57 != 0 )
      {
        v58 = common->Game(this: common);
        v59 = v58->GetEntityName(this: v58, a2: (idEntity *)v57);
      }
      else
      {
        v59 = "<unknown>";
      }
      idLib::Warning(fmt: "Entity '%s' does not have a valid collision model set for buoyancy", v59);
      idList<idThread *,58>::Clear(this: &v134);
      idPLogScope::~idPLogScope(this: &v129);
      goto LABEL_60;
    }
    v60 = CollisionModel->GetPolytopes(this: CollisionModel, a2: v133, a3: 32, a4: v138, a5: 192);
    if ( v60 == 0 )
    {
      idList<idThread *,58>::Clear(this: &v134);
      idPLogScope::~idPLogScope(this: &v129);
      goto LABEL_60;
    }
    v61 = (float *)((*(int (__fastcall **)(_DWORD *, _DWORD))(*v43 + 8))(a1: v43, a2: 0) + 32);
    v62 = (float *)(*(int (__fastcall **)(_DWORD *, _DWORD))(*v43 + 8))(a1: v43, a2: 0);
    if ( v60 > 0 )
    {
      v63 = v133;
      v64 = v60;
      v65 = (float *)&v137;
      do
      {
        v66 = *v63;
        for ( i = 0; i < v66; *v65 = (float)((float)v69 * (float)v72) + (float)v74 )
        {
          ++i;
          v68 = v65[4];
          v69 = v65[3];
          v70 = v65[5];
          v65[6] = v65[6]
                 - (float)((float)(v65[5] * v61[2]) + (float)((float)(v65[3] * *v61) + (float)(v65[4] * v61[1])));
          v71 = v62[13];
          v72 = v62[12];
          v73 = (float)((float)((float)v68 * v62[16]) + (float)((float)v70 * v62[19]));
          v75 = (float)((float)((float)v69 * v62[11])
                      + (float)((float)((float)v68 * v62[14]) + (float)((float)v70 * v62[17])));
          v74 = (float)((float)((float)v68 * v62[15]) + (float)((float)v70 * v62[18]));
          v65[3] = v75;
          v65[5] = (float)((float)v69 * (float)v71) + (float)v73;
          v65 += 4;
        }
        ++v63;
        --v64;
      }
      while ( v64 != 0 );
    }
    v76 = (float *)(*(int (__fastcall **)(_DWORD *))(*v43 + 100))(a1: v43);
    v77 = v139;
    for ( j = ClipModelsTouchingBounds; j != 0; --j )
    {
      v79 = *v77;
      if ( (*v77)->traceModels.num > 0 )
      {
        v80 = v79->clip->traceModelCache->cache.list[*v79->traceModels.list];
        if ( v80->hasWater )
        {
          list = v80->waterPoints.list;
          if ( list != nullptr )
          {
            PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v79->physicsId);
            v83 = PhysicsForId;
            if ( PhysicsForId != nullptr )
            {
              type = PhysicsForId->type;
              if ( type != PHYSICS_STATIC && type != PHYSICS_STATICMULTI )
              {
                v84 = 0.0;
                idBuoyancy::CalculateBuoyancyWeights(
                  this: v35,
                  polytopeNumPlanes: v133,
                  polytopePlanes: v138,
                  numPolytopes: v60,
                  clipModel: v79,
                  weights: v136);
                if ( v79->traceModels.num <= 0 )
                  volume = 0.0;
                else
                  volume = v79->clip->traceModelCache->cache.list[*v79->traceModels.list]->volume;
                v86 = (float)((float)volume * (float)v37);
                v87 = v136;
                p_y = &list->xyz.y;
                v89 = 64;
                v90 = (float)((float)(*v47 - (float)(*v76 * (float)v86)) * (float)v33);
                v91 = (float)((float)(v47[2] - (float)(v76[2] * (float)v86)) * (float)v33);
                v92 = (float)((float)(v47[1] - (float)(v76[1] * (float)v86)) * (float)v33);
                do
                {
                  v93 = *v87;
                  if ( v93 > 0.0 )
                  {
                    v94 = *(p_y - 1);
                    v95 = *p_y;
                    v96 = p_y[1];
                    v97 = (float)(v79->axis.mat[2].x * p_y[1]);
                    z = v79->axis.mat[2].z;
                    y = v79->axis.mat[2].y;
                    x = v79->axis.mat[1].x;
                    v101 = v79->axis.mat[0].x;
                    v102 = (float)((float)(v79->axis.mat[1].z * *p_y) + (float)(v79->axis.mat[0].z * *(p_y - 1)));
                    v103 = v79->origin.z;
                    v104 = (float)((float)(v79->axis.mat[1].y * *p_y) + (float)(v79->axis.mat[0].y * *(p_y - 1)));
                    v105 = v79->origin.y;
                    v106 = v79->origin.x;
                    v132[0] = *v87 * (float)v90;
                    v132[1] = (float)v93 * (float)v92;
                    v132[2] = (float)v93 * (float)v91;
                    v131[2] = (float)v103 + (float)((float)((float)z * (float)v96) + (float)v102);
                    v131[1] = (float)v105 + (float)((float)((float)y * (float)v96) + (float)v104);
                    v131[0] = (float)v106
                            + (float)((float)((float)v94 * (float)v101)
                                    + (float)((float)((float)x * (float)v95) + (float)v97));
                    v83->ApplyImpulse(this: v83, a2: v79->bodyId, a3: (const idVec3 *)v131, a4: (const idVec3 *)v132);
                    v84 = (float)((float)v93 + (float)v84);
                  }
                  --v89;
                  p_y += 4;
                  ++v87;
                }
                while ( v89 != 0 );
                ((void (__fastcall *)(idPhysics *, double))v83->SetWaterLevel)(a1: v83, a2: v84);
                v83->SetWaterEntNum(this: v83, a2: v43[4]);
                v107 = (*(int (__fastcall **)(_DWORD *, int))(*v43 + 40))(a1: v43, a2: -1);
                v108 = (*(int (__fastcall **)(_DWORD *, _DWORD))(*v43 + 64))(a1: v43, a2: 0);
                v83->SetWaterSurfaceWrldHeight(this: v83, a2: (float)(*(float *)(v108 + 8) + *(float *)(v107 + 20)));
                ((void (__fastcall *)(idPhysics *, double))v83->SetWaterViscosity)(a1: v83, a2: v39);
                v83->callbacks->ApplyDamage(this: v83->callbacks, a2: v43[3], a3: v79->bodyId, a4: v45);
                if ( v84 > 0.0 )
                {
                  v83->callbacks->ApplyWaterEffects(this: v83->callbacks, a2: v43[3], a3: v79->bodyId);
                  bodyId = v79->bodyId;
                  physicsId = v79->physicsId;
                  v130.physicsId = physicsId;
                  v130.bodyId = bodyId;
                  idList<buoyantClipModel_t,5>::Append(this: (idList<buoyantClipModel_t,5> *)&v134, obj: &v130);
                  v111 = 0;
                  num = v35->buoyantClipModels.num;
                  if ( num > 0 )
                  {
                    v112 = v35->buoyantClipModels.list;
                    v113 = 0;
                    do
                    {
                      if ( v112[v113].physicsId == physicsId && v112[v113].bodyId == bodyId )
                        break;
                      ++v111;
                      ++v113;
                    }
                    while ( v111 < num );
                  }
                  if ( v111 >= num )
                    v83->callbacks->ApplyWaterSplashEffects(
                      this: v83->callbacks,
                      a2: v43[3],
                      a3: v79->bodyId,
                      a4: a33,
                      a5: WATER_ENTERED);
                }
              }
            }
          }
        }
      }
      ++v77;
    }
  }
  v114 = 0;
  if ( v35->buoyantClipModels.num > 0 )
  {
    v115 = v134.num;
    v116 = 0;
    do
    {
      v117 = 0;
      if ( v115 <= 0 )
        goto LABEL_49;
      v118 = v134.list;
      v119 = &v35->buoyantClipModels.list[v116];
      while ( *v118 != (idVehicleState *)v119->physicsId || v118[1] != (idVehicleState *)v119->bodyId )
      {
        ++v117;
        v118 += 2;
        if ( v117 >= v115 )
          goto LABEL_49;
      }
      if ( v117 >= v115 )
      {
LABEL_49:
        v120 = idPhysics::GetPhysicsForId(physicsId_: v35->buoyantClipModels.list[v116].physicsId);
        v121 = v120;
        if ( v120 != nullptr )
        {
          ((void (__fastcall *)(idPhysics *, double))v120->SetWaterLevel)(a1: v120, a2: 0.0);
          ((void (__fastcall *)(idPhysics *, double))v121->SetWaterViscosity)(a1: v121, a2: 0.0);
        }
        v115 = v134.num;
      }
      ++v114;
      ++v116;
    }
    while ( v114 < v35->buoyantClipModels.num );
  }
  idList<buoyantClipModel_t,5>::operator=(
    this: &v35->buoyantClipModels,
    other: (const idList<buoyantClipModel_t,5> *)&v134);
  blkmov(a1: v35->buoyantClipModels.staticList, a2: v135, a3: 1024);
  if ( v134.listStatic == 0 || v134.listStatic == 2 )
  {
    if ( v134.list != nullptr )
      idMem::Free(this: &mem, ptr: v134.list, align: ALIGN_16);
    v134.list = nullptr;
    v134.size = 0;
  }
  v134.num = 0;
  if ( v129.logIndex >= 0 )
  {
    pLog = v129.pLog;
    v123 = &v129.pLog->logEntries.list[v129.logIndex];
    v124 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v123->totalTicks;
    HIDWORD(totalTicks) = v123->parent;
    LODWORD(v126) = v124 - totalTicks;
    v123->totalTicks = v126;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
LABEL_60:
  RD_EventEnd();
}


// ========================================================================
// __unwind$246803
// EA  : 0x8272B6AC
// RVA : 0x0072B6AC
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

void _unwind_246803()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65296);
}


// ========================================================================
// __unwind$246804
// EA  : 0x8272B6DC
// RVA : 0x0072B6DC
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

void _unwind_246804()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 3497);
}


// ========================================================================
// __unwind$246805
// EA  : 0x8272B704
// RVA : 0x0072B704
// PDB : w:\tech5\engine\gamelib\physics\buoyancy.cpp
// ========================================================================

void _unwind_246805()
{
  idStaticList<idVehicleState *,4> *v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: v0 + 880);
}

