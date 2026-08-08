
// ========================================================================
// ??0idVehicleCover@@QAA@XZ
// EA  : 0x82A90AC0
// RVA : 0x00A90AC0
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

idVehicleCover *__fastcall idVehicleCover::idVehicleCover(idVehicleCover *this)
{
  idDynamicCover::idDynamicCover(this, _numCover: 8);
  this->numCover = 8;
  this->__vftable = (idVehicleCover_vtbl *)&idVehicleCover::`vftable';
  return this;
}


// ========================================================================
// ?FreeCover@idVehicleCoverMgr@@UAAXPAVidDynamicCover@@@Z
// EA  : 0x82A90B08
// RVA : 0x00A90B08
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

void __fastcall idVehicleCoverMgr::FreeCover(idFormationCoverMgr *this, idDynamicCover *cover)
{
  if ( cover != nullptr )
    ((void (__fastcall *)(idDynamicCover *, int))cover->dtr_idClass)(a1: cover, a2: 1);
}


// ========================================================================
// ?UpdateUsable@idVehicleCover@@UAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A90B30
// RVA : 0x00A90B30
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

void __fastcall idVehicleCover::UpdateUsable(idVehicleCover *this, idVehicle *owner, const idAAS2 *aas, int curTime)
{
  idVehicle *v8; // r3
  idPhysics *Physics; // r3
  idVehicleCover_vtbl *v10; // r11
  float v11; // [sp+50h] [-40h] BYREF
  float v12; // [sp+54h] [-3Ch]
  float v13; // [sp+58h] [-38h]

  v8 = idVehicle::CastTo(c: owner);
  if ( ai_forceVehicleCoverFlag.valueInteger != 0 || v8 != nullptr && v8->provideDynamicCover )
  {
    Physics = idEntity::GetPhysics(this: owner);
    Physics->GetLinearVelocity(this: (idPhysics *)&v11, result: (idVec3 *)Physics, a3: 0);
    if ( (float)((float)(v13 * v13) + (float)((float)(v12 * v12) + (float)(v11 * v11))) <= 0.001 )
    {
      v10 = this->__vftable;
      if ( this->updated )
      {
        v10->InternalUpdateCurrent(this, a2: owner, a3: aas, a4: curTime);
      }
      else
      {
        v10->MarkAllUnusable(this);
        this->InternalUpdateUsable(this, a2: owner, a3: aas, a4: curTime);
        this->updated = true;
      }
    }
    else
    {
      this->MarkAllUnusable(this);
      this->updated = false;
    }
  }
}


// ========================================================================
// ?AllocCover@idVehicleCoverMgr@@UAAPAVidDynamicCover@@PBVidAAS2@@@Z
// EA  : 0x82A90C68
// RVA : 0x00A90C68
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

idDynamicCover *__fastcall idVehicleCoverMgr::AllocCover(idVehicleCoverMgr *this, const idAAS2 *aas)
{
  idDynamicCover *v2; // r3
  _DWORD *v3; // r30

  v2 = (idDynamicCover *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x1Cu,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v3 = &v2->__vftable;
  if ( v2 == nullptr )
    return nullptr;
  idDynamicCover::idDynamicCover(this: v2, _numCover: 8);
  v3[1] = 8;
  *v3 = &idVehicleCover::`vftable';
  return (idDynamicCover *)v3;
}


// ========================================================================
// __unwind$487754
// EA  : 0x82A90CF8
// RVA : 0x00A90CF8
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

void __fastcall _unwind_487754(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InternalUpdateCurrent@idVehicleCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A90D20
// RVA : 0x00A90D20
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

void __fastcall idVehicleCover::InternalUpdateCurrent(
        idVehicleCover *this,
        const idEntity *owner,
        idClipModel *aas,
        const int curTime)
{
  int numCover; // r11
  unsigned __int64 v5; // r27
  int v8; // r29
  unsigned __int64 index; // r11
  unsigned int v10; // r11
  char v11; // r11
  bool v12; // zf
  __int64 v13; // r11
  idClientGame *v14; // r9
  const idClipModel *ClipForAAS; // r3
  char *v16; // r10
  const idClipModel *p_z; // r11
  int i; // ctr
  idRenderWorld *v19; // r3
  idColor *v20; // r4
  float *v21; // r5
  unsigned __int64 v22; // r11
  unsigned int v23; // r11
  char v24; // r11
  __int64 v25; // r11
  idClientGame *v26; // r9
  idDynamicCover::coverInfo_t *v27; // r31
  const idClipModel *v28; // r3
  char *v29; // r10
  const idClipModel *v30; // r11
  int j; // ctr
  char *v32; // r10
  char *v33; // r11
  double v34; // fp0
  double v35; // fp8
  double v36; // fp7
  double v37; // fp6
  double v38; // fp5
  double v39; // fp4
  int v40; // ctr
  __int16 v53; // r3
  const idClipModel *v54; // r3
  char *v55; // r10
  const idClipModel *v56; // r11
  int k; // ctr
  char *v58; // r10
  char *v59; // r11
  double v60; // fp0
  double v61; // fp8
  double v62; // fp7
  double v63; // fp6
  double v64; // fp5
  double v65; // fp4
  int v66; // ctr
  idRenderWorld *(__fastcall *GetRenderWorld)(struct idGameLocal *); // r10
  _DWORD *v80; // r3
  const idClipModel *v81; // r3
  char *v82; // r10
  const idClipModel *v83; // r11
  int m; // ctr
  char *v85; // r10
  char *v86; // r11
  double v87; // fp0
  double v88; // fp8
  double v89; // fp7
  double v90; // fp6
  double v91; // fp5
  double v92; // fp4
  int v93; // ctr
  int v106; // r9
  int *p_coverFlags; // [sp+60h] [-310h]
  char v108; // [sp+6Ch] [-304h] BYREF
  float v109; // [sp+70h] [-300h] BYREF
  float v110; // [sp+74h] [-2FCh]
  float v111; // [sp+78h] [-2F8h]
  float v112; // [sp+7Ch] [-2F4h]
  float v113; // [sp+80h] [-2F0h]
  float v114; // [sp+84h] [-2ECh]
  char v115; // [sp+8Ch] [-2E4h] BYREF
  float v116; // [sp+90h] [-2E0h] BYREF
  float v117; // [sp+94h] [-2DCh]
  float v118; // [sp+98h] [-2D8h]
  float v119; // [sp+9Ch] [-2D4h]
  float v120; // [sp+A0h] [-2D0h]
  float v121; // [sp+A4h] [-2CCh]
  char v122; // [sp+ACh] [-2C4h] BYREF
  float v123; // [sp+B0h] [-2C0h]
  float v124; // [sp+B4h] [-2BCh]
  float v125; // [sp+B8h] [-2B8h]
  float v126; // [sp+BCh] [-2B4h]
  float v127; // [sp+C0h] [-2B0h]
  float v128; // [sp+C4h] [-2ACh]
  int v129; // [sp+C8h] [-2A8h]
  char v130; // [sp+CCh] [-2A4h] BYREF
  float v131; // [sp+D0h] [-2A0h] BYREF
  float v132; // [sp+D4h] [-29Ch]
  float v133; // [sp+D8h] [-298h]
  float v134; // [sp+DCh] [-294h]
  float v135; // [sp+E0h] [-290h]
  float v136; // [sp+E4h] [-28Ch]
  char v137; // [sp+ECh] [-284h] BYREF
  float v138; // [sp+F4h] [-27Ch]
  float v139; // [sp+F8h] [-278h]
  float v140; // [sp+FCh] [-274h]
  float v141; // [sp+100h] [-270h]
  float v142; // [sp+104h] [-26Ch]
  char v143; // [sp+10Ch] [-264h] BYREF
  float v144; // [sp+114h] [-25Ch]
  float v145; // [sp+118h] [-258h]
  float v146; // [sp+11Ch] [-254h]
  float v147; // [sp+120h] [-250h]
  float v148; // [sp+124h] [-24Ch]
  char v149; // [sp+12Ch] [-244h] BYREF
  float v150; // [sp+134h] [-23Ch]
  float v151; // [sp+138h] [-238h]
  float v152; // [sp+13Ch] [-234h]
  float v153; // [sp+140h] [-230h]
  float v154; // [sp+144h] [-22Ch]
  float v155[6]; // [sp+148h] [-228h] BYREF
  trace_t v156; // [sp+160h] [-210h] BYREF
  _BYTE v157[32]; // [sp+1E0h] [-190h] BYREF
  trace_t v158; // [sp+200h] [-170h] BYREF

  numCover = this->numCover;
  LODWORD(v5) = 0;
  v129 = 0;
  if ( numCover > 0 )
  {
    p_coverFlags = &vehicleCoverProps[0].coverFlags;
    v8 = 0;
    HIDWORD(v5) = &consoleFont[21088];
    do
    {
      index = this->coverInfo.list[v8].contentsQuery.index;
      if ( (unsigned int)index < LODWORD(clientGame->clip.collisionQueryFirstSubmittedIndex)
        || (unsigned int)index > LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
      {
        v11 = 0;
      }
      else
      {
        v10 = *((_DWORD *)&clientGame->clip.collisionQueries[0].query.offset
              + 2 * (index & 0xFFF)
              + 2 * ((2 * index) & 0x1FFE)
              + 1);
        if ( v10 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v12 = v10 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v11 = 1, !v12) )
        {
          v11 = 0;
        }
      }
      if ( v11 != 0 )
      {
        v13 = *(_QWORD *)HIDWORD(index);
        v14 = clientGame;
        *(_QWORD *)HIDWORD(v13) = v5;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v158,
          query: &v14->clip.collisionQueries[v13 & 0xFFF].query,
          peek: false);
        if ( (v158.c.contentFlags & 0x11) != 0 )
        {
          this->coverInfo.list[v8].cover.flags |= 0x2000u;
          if ( (unsigned __int8)idClip::QueryIsValid(
                                  this: &clientGame->clip,
                                  clipQuery: &this->coverInfo.list[v8].translationQuery) != 0 )
            this->coverInfo.list[v8].translationQuery.index = v5;
          if ( ai_debugDynamicCover.valueInteger <= 1 )
            goto LABEL_47;
          ClipForAAS = idDynamicCover::GetClipForAAS(aas);
          v16 = &v130;
          p_z = (const idClipModel *)&ClipForAAS->axis.mat[2].z;
          for ( i = 6; i != 0; --i )
          {
            p_z = (const idClipModel *)((char *)p_z + 4);
            v16 += 4;
            *(_DWORD *)v16 = p_z->__vftable;
          }
          v131 = v158.endpos.x + v131;
          v132 = v158.endpos.y + v132;
          v133 = v158.endpos.z + v133;
          v134 = v134 + v158.endpos.x;
          v135 = v135 + v158.endpos.y;
          v136 = v136 + v158.endpos.z;
          v19 = gameLocal->GetRenderWorld(this: gameLocal);
          v20 = &idColor::colorYellow;
          v21 = &v131;
          goto LABEL_46;
        }
      }
      v22 = this->coverInfo.list[v8].translationQuery.index;
      if ( (unsigned int)v22 < LODWORD(clientGame->clip.collisionQueryFirstSubmittedIndex)
        || (unsigned int)v22 > LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
      {
        v24 = 0;
      }
      else
      {
        v23 = *((_DWORD *)&clientGame->clip.collisionQueries[0].query.offset
              + 2 * (v22 & 0xFFF)
              + 2 * ((2 * v22) & 0x1FFE)
              + 1);
        if ( v23 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v12 = v23 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v24 = 1, !v12) )
        {
          v24 = 0;
        }
      }
      if ( v24 == 0 )
        goto LABEL_47;
      v25 = *(_QWORD *)HIDWORD(v22);
      v26 = clientGame;
      *(_QWORD *)HIDWORD(v25) = v5;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v156,
        query: &v26->clip.collisionQueries[v25 & 0xFFF].query,
        peek: false);
      v27 = &this->coverInfo.list[v8];
      if ( v156.fraction == 1.0 )
      {
        v27->cover.flags |= 0x2000u;
        if ( ai_debugDynamicCover.valueInteger > 1 )
        {
          v28 = idDynamicCover::GetClipForAAS(aas);
          v29 = &v108;
          v30 = (const idClipModel *)&v28->axis.mat[2].z;
          for ( j = 6; j != 0; --j )
          {
            v30 = (const idClipModel *)((char *)v30 + 4);
            v29 += 4;
            *(_DWORD *)v29 = v30->__vftable;
          }
          v32 = &v143;
          v33 = &v108;
          v34 = (float)(v156.endpos.x + v109);
          v35 = (float)(v156.endpos.y + v110);
          v36 = (float)(v156.endpos.z + v111);
          v37 = (float)(v112 + v156.endpos.x);
          v38 = (float)(v113 + v156.endpos.y);
          v39 = (float)(v114 + v156.endpos.z);
          v109 = v156.endpos.x + v109;
          v110 = v156.endpos.y + v110;
          v111 = v156.endpos.z + v111;
          v40 = 6;
          v112 = v112 + v156.endpos.x;
          v113 = v113 + v156.endpos.y;
          v114 = v114 + v156.endpos.z;
          do
          {
            v33 += 4;
            v32 += 4;
            *(_DWORD *)v32 = *(_DWORD *)v33;
            --v40;
          }
          while ( v40 != 0 );
          _FP28 = (float)((float)v34 - (float)v34);
          _FP30 = (float)((float)v35 - v144);
          _FP29 = (float)(v146 - (float)v37);
          _FP31 = (float)(v147 - (float)v38);
          __asm { fsel      f0, f28, f0, f0 }
          v109 = _FP0;
          v145 = v145 + (float)(v156.fraction * (float)96.0);
          __asm { fsel      f2, f30, f13, f8 }
          v110 = _FP2;
          __asm { fsel      f1, f29, f12, f6 }
          v112 = _FP1;
          __asm { fsel      f5, f31, f11, f5 }
          v113 = _FP5;
          _FP13 = (float)((float)v36 - v145);
          _FP12 = (float)((float)(v148 + (float)(v156.fraction * (float)96.0)) - (float)v39);
          v148 = v148 + (float)(v156.fraction * (float)96.0);
          __asm { fsel      f11, f13, f10, f7 }
          v111 = _FP11;
          __asm { fsel      f10, f12, f9, f4 }
          v114 = _FP10;
          v19 = gameLocal->GetRenderWorld(this: gameLocal);
          v20 = &idColor::colorRed;
          v21 = &v109;
LABEL_46:
          v19->DebugBounds(
            this: v19,
            a2: (const idVec4 *)v20,
            a3: (const idBounds *)v21,
            a4: &vec3_origin,
            a5: 5000,
            a6: true);
        }
      }
      else
      {
        v27->cover.origin = v156.endpos;
        ((void (__fastcall *)(_BYTE *, idClipModel *))aas->__vftable[6].dtr_idClipModel)(a1: v157, a2: aas);
        v53 = ((int (__fastcall *)(idClipModel *, _DWORD, idDynamicCover::coverInfo_t *, _BYTE *, int, int))aas->__vftable[10].dtr_idClipModel)(
                a1: aas,
                a2: 0,
                a3: v27,
                a4: v157,
                a5: 2,
                a6: 1);
        v27->cover.areaNum = v53;
        if ( v53 <= 0 )
        {
          v27->cover.flags |= 0x2000u;
          if ( ai_debugDynamicCover.valueInteger > 1 )
          {
            v54 = idDynamicCover::GetClipForAAS(aas);
            v55 = &v122;
            v56 = (const idClipModel *)&v54->axis.mat[2].z;
            for ( k = 6; k != 0; --k )
            {
              v56 = (const idClipModel *)((char *)v56 + 4);
              v55 += 4;
              *(_DWORD *)v55 = v56->__vftable;
            }
            v58 = &v149;
            v59 = &v122;
            v60 = (float)(v123 + v156.endpos.x);
            v61 = (float)(v124 + v156.endpos.y);
            v62 = (float)(v125 + v156.endpos.z);
            v63 = (float)(v126 + v156.endpos.x);
            v64 = (float)(v127 + v156.endpos.y);
            v65 = (float)(v128 + v156.endpos.z);
            v123 = v123 + v156.endpos.x;
            v124 = v124 + v156.endpos.y;
            v125 = v125 + v156.endpos.z;
            v66 = 6;
            v126 = v126 + v156.endpos.x;
            v127 = v127 + v156.endpos.y;
            v128 = v128 + v156.endpos.z;
            do
            {
              v59 += 4;
              v58 += 4;
              *(_DWORD *)v58 = *(_DWORD *)v59;
              --v66;
            }
            while ( v66 != 0 );
            _FP31 = (float)((float)v61 - v150);
            _FP29 = (float)(v152 - (float)v63);
            _FP27 = (float)((float)v60 - (float)v60);
            _FP28 = (float)(v153 - (float)v64);
            GetRenderWorld = gameLocal->GetRenderWorld;
            __asm { fsel      f30, f31, f13, f8 }
            v124 = _FP30;
            __asm { fsel      f29, f29, f12, f6 }
            v126 = _FP29;
            __asm { fsel      f31, f27, f0, f0 }
            v123 = _FP31;
            __asm { fsel      f28, f28, f11, f5 }
            v127 = _FP28;
            _FP8 = (float)((float)v62 - (float)(v151 + (float)(v156.fraction * (float)96.0)));
            v151 = v151 + (float)(v156.fraction * (float)96.0);
            _FP6 = (float)((float)(v154 + (float)(v156.fraction * (float)96.0)) - (float)v65);
            v154 = v154 + (float)(v156.fraction * (float)96.0);
            __asm { fsel      f27, f8, f10, f7 }
            v125 = _FP27;
            __asm { fsel      f26, f6, f9, f4 }
            v128 = _FP26;
            v80 = (_DWORD *)GetRenderWorld(this: gameLocal);
            v155[0] = (float)((float)_FP29 + (float)_FP31) * (float)0.5;
            v155[1] = (float)((float)_FP28 + (float)_FP30) * (float)0.5;
            v155[2] = (float)((float)_FP26 + (float)_FP27) * (float)0.5;
            (*(void (__fastcall **)(_DWORD *, const char *, float *, _DWORD, idColor *, int, int, int, double))(*v80 + 268))(
              a1: v80,
              a2: "INVALID AAS AREA",
              a3: v155,
              a4: *v80,
              a5: &idColor::colorRed,
              a6: 1,
              a7: 5000,
              a8: 1,
              a9: 0.2);
          }
          goto LABEL_47;
        }
        v27->cover.flags = *p_coverFlags;
        if ( ai_debugDynamicCover.valueInteger > 1 )
        {
          v81 = idDynamicCover::GetClipForAAS(aas);
          v82 = &v115;
          v83 = (const idClipModel *)&v81->axis.mat[2].z;
          for ( m = 6; m != 0; --m )
          {
            v83 = (const idClipModel *)((char *)v83 + 4);
            v82 += 4;
            *(_DWORD *)v82 = v83->__vftable;
          }
          v85 = &v137;
          v86 = &v115;
          v87 = (float)(v156.endpos.x + v116);
          v88 = (float)(v117 + v156.endpos.y);
          v89 = (float)(v118 + v156.endpos.z);
          v90 = (float)(v119 + v156.endpos.x);
          v91 = (float)(v120 + v156.endpos.y);
          v92 = (float)(v121 + v156.endpos.z);
          v116 = v156.endpos.x + v116;
          v117 = v117 + v156.endpos.y;
          v118 = v118 + v156.endpos.z;
          v93 = 6;
          v119 = v119 + v156.endpos.x;
          v120 = v120 + v156.endpos.y;
          v121 = v121 + v156.endpos.z;
          do
          {
            v86 += 4;
            v85 += 4;
            *(_DWORD *)v85 = *(_DWORD *)v86;
            --v93;
          }
          while ( v93 != 0 );
          _FP29 = (float)((float)v87 - (float)v87);
          _FP1 = (float)(v141 - (float)v91);
          _FP30 = (float)((float)v88 - v138);
          _FP31 = (float)(v140 - (float)v90);
          __asm { fsel      f0, f29, f0, f0 }
          v116 = _FP0;
          v139 = v139 + (float)(v156.fraction * (float)96.0);
          __asm { fsel      f5, f1, f11, f5 }
          v120 = _FP5;
          __asm { fsel      f1, f30, f13, f8 }
          v117 = _FP1;
          __asm { fsel      f2, f31, f12, f6 }
          v119 = _FP2;
          _FP13 = (float)((float)v89 - v139);
          _FP12 = (float)((float)(v142 + (float)(v156.fraction * (float)96.0)) - (float)v92);
          v142 = v142 + (float)(v156.fraction * (float)96.0);
          __asm { fsel      f11, f13, f10, f7 }
          v118 = _FP11;
          __asm { fsel      f10, f12, f9, f4 }
          v121 = _FP10;
          v19 = gameLocal->GetRenderWorld(this: gameLocal);
          v20 = &idColor::colorGreen;
          v21 = &v116;
          goto LABEL_46;
        }
      }
LABEL_47:
      ++v8;
      v106 = this->numCover;
      p_coverFlags += 2;
      ++v129;
    }
    while ( v129 < v106 );
  }
}


// ========================================================================
// ?InternalUpdateUsable@idVehicleCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A91568
// RVA : 0x00A91568
// PDB : w:\tech5\tungsten\game\ai\cover\vehiclecover.cpp
// ========================================================================

void __fastcall idVehicleCover::InternalUpdateUsable(
        idVehicleCover *this,
        idVehicle *owner,
        const idClipModel *aas,
        int curTime)
{
  idVehicle *v7; // r3
  idAnimatedEntity *v8; // r31
  idPhysics *Physics; // r3
  idAngles *v10; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v13; // r29
  idPropsCollection *decl; // r11
  idClipModel *ClipForAAS; // r26
  const char *PropNameForAAS; // r3
  int numCover; // r11
  const coverProperties_t *v18; // r14
  int v19; // r30
  idDynamicCover::coverInfo_t *v20; // r31
  const tagData_t *Tag; // r4
  idDynamicCover::coverInfo_t *v22; // r31
  int entityNumber; // r14
  idDynamicCover::coverInfo_t *v24; // r31
  char *v25; // r9
  idClipModel *p_z; // r10
  int i; // ctr
  idClipModel *v28; // r11
  int v29; // ctr
  int *v30; // r10
  idRenderWorld *v31; // r3
  const char *v32; // [sp+8h] [-1E8h]
  int v33; // [sp+8h] [-1E8h]
  int v34; // [sp+Ch] [-1E4h]
  bool v35; // [sp+Fh] [-1E1h]
  int v36; // [sp+10h] [-1E0h]
  const char *v37; // [sp+10h] [-1E0h]
  int v38; // [sp+14h] [-1DCh]
  int v39; // [sp+14h] [-1DCh]
  int v40; // [sp+18h] [-1D8h]
  int v41; // [sp+18h] [-1D8h]
  int v42; // [sp+1Ch] [-1D4h]
  int v43; // [sp+1Ch] [-1D4h]
  int v44; // [sp+20h] [-1D0h]
  int v45; // [sp+20h] [-1D0h]
  int v46; // [sp+24h] [-1CCh]
  int v47; // [sp+24h] [-1CCh]
  int v48; // [sp+28h] [-1C8h]
  int v49; // [sp+28h] [-1C8h]
  int v50; // [sp+2Ch] [-1C4h]
  int v51; // [sp+2Ch] [-1C4h]
  int v52; // [sp+30h] [-1C0h]
  int v53; // [sp+30h] [-1C0h]
  int v54; // [sp+34h] [-1BCh]
  int v55; // [sp+34h] [-1BCh]
  int v56; // [sp+38h] [-1B8h]
  int v57; // [sp+38h] [-1B8h]
  int v58; // [sp+3Ch] [-1B4h]
  int v59; // [sp+3Ch] [-1B4h]
  int v60; // [sp+40h] [-1B0h]
  int v61; // [sp+40h] [-1B0h]
  int v62; // [sp+44h] [-1ACh]
  int v63; // [sp+44h] [-1ACh]
  int v64; // [sp+48h] [-1A8h]
  int v65; // [sp+48h] [-1A8h]
  int v66; // [sp+4Ch] [-1A4h]
  int v67; // [sp+4Ch] [-1A4h]
  int v68; // [sp+50h] [-1A0h]
  int v69; // [sp+50h] [-1A0h]
  int v70; // [sp+58h] [-198h]
  int v71; // [sp+60h] [-190h]
  const coverProperties_t *v72; // [sp+70h] [-180h]
  int v73; // [sp+74h] [-17Ch]
  idVec3 v74; // [sp+78h] [-178h] BYREF
  char v75; // [sp+8Ch] [-164h] BYREF
  idBounds v76; // [sp+90h] [-160h] BYREF
  idVec3 v77; // [sp+A8h] [-148h] BYREF
  idVec3 v78; // [sp+B8h] [-138h] BYREF
  int v79; // [sp+CCh] [-124h] BYREF
  idBounds v80; // [sp+D0h] [-120h] BYREF
  idPropsCollection *v81; // [sp+E8h] [-108h]
  const char *v82; // [sp+ECh] [-104h]
  idTreeAnimator *v83; // [sp+F0h] [-100h]
  idMat3 v84; // [sp+100h] [-F0h] BYREF
  idMat3 v85; // [sp+128h] [-C8h] BYREF

  v7 = idVehicle::CastTo(c: owner);
  v8 = v7;
  if ( v7 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v7);
    v10 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
    idMat3::ToAngles(this: &v85, result: v10);
    if ( __fabs(v85.mat[0].z) <= 45.0 )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v8);
      presentable = v8->presentable;
      v13 = TreeAnimatorFromPresentable;
      v83 = TreeAnimatorFromPresentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v8);
        presentable = v8->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( v13 != nullptr )
      {
        decl = (idPropsCollection *)v13->decl;
        if ( decl != nullptr )
        {
          v81 = decl + 22;
          if ( decl != (idPropsCollection *)-352 )
          {
            ClipForAAS = (idClipModel *)idDynamicCover::GetClipForAAS(aas);
            PropNameForAAS = idDynamicCover::GetPropNameForAAS((const idAAS2 *)aas);
            numCover = this->numCover;
            v82 = PropNameForAAS;
            v73 = 0;
            if ( numCover > 0 )
            {
              v18 = vehicleCoverProps;
              v72 = vehicleCoverProps;
              v19 = 0;
              do
              {
                v20 = &this->coverInfo.list[v19];
                if ( v20->cover.usableTime <= curTime )
                {
                  Tag = idPropsCollection::GetTag(this: v81, propName: v82, tagName: v18->tagName);
                  if ( Tag->parentJoint.value != 0xFFFF
                    && (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                                          this: v83,
                                          tagData: Tag,
                                          origin: &v74,
                                          axis: &v84) != 0 )
                  {
                    v20->cover.origin = v74;
                    v20->cover.dir = v84.mat[0];
                    if ( (float)((float)(v84.mat[2].x * vec3_up.x)
                               + (float)((float)(v84.mat[2].y * vec3_up.y) + (float)(v84.mat[2].z * vec3_up.z))) >= 0.70709997
                      && ClipForAAS != nullptr )
                    {
                      v22 = &this->coverInfo.list[v19];
                      v22->contentsQuery.index = *(_QWORD *)&idClip::Contents(
                                                               this: (idClip *)&v85.mat[2],
                                                               result: &clientGame->clip,
                                                               a3: nullptr,
                                                               start: &v74,
                                                               clipModel: ClipForAAS,
                                                               startAxis: &mat3_identity,
                                                               clipMask: 17,
                                                               passEntityNumber: 0x1FFF,
                                                               userName: v32,
                                                               a10: v34,
                                                               a11: v36,
                                                               a12: v38,
                                                               a13: v40,
                                                               a14: v42,
                                                               a15: v44,
                                                               a16: v46,
                                                               a17: v48,
                                                               a18: v50,
                                                               a19: v52,
                                                               a20: v54,
                                                               a21: v56,
                                                               a22: v58,
                                                               a23: v60,
                                                               a24: v62,
                                                               a25: v64,
                                                               a26: v66,
                                                               a27: v68,
                                                               a28: (int)"w:\\tech5\\tungsten\\game\\ai\\cover\\VehicleCover.c"
                                                                    "pp(220) : Contents")->world;
                      entityNumber = owner->entityNumber;
                      v24 = &this->coverInfo.list[v19];
                      v77.x = v74.x;
                      v77.y = v74.y;
                      v77.z = v74.z + 48.0;
                      v78.x = v74.x;
                      v78.y = v74.y;
                      v78.z = v74.z - 48.0;
                      v24->translationQuery.index = *(_QWORD *)&idClip::Translation(
                                                                  this: (idClip *)&v85.mat[1].y,
                                                                  result: &clientGame->clip,
                                                                  a3: nullptr,
                                                                  start: &v77,
                                                                  end: &v78,
                                                                  clipModel: ClipForAAS,
                                                                  startAxis: &mat3_identity,
                                                                  clipMask: 17,
                                                                  passEntityNumber: v33,
                                                                  moveClipModel: v35,
                                                                  userName: v37,
                                                                  a12: v39,
                                                                  a13: v41,
                                                                  a14: v43,
                                                                  a15: v45,
                                                                  a16: v47,
                                                                  a17: v49,
                                                                  a18: v51,
                                                                  a19: v53,
                                                                  a20: v55,
                                                                  a21: v57,
                                                                  a22: v59,
                                                                  a23: v61,
                                                                  a24: v63,
                                                                  a25: v65,
                                                                  a26: v67,
                                                                  a27: v69,
                                                                  a28: entityNumber,
                                                                  a29: v70,
                                                                  a30: false,
                                                                  a31: v71,
                                                                  a32: (int)"w:\\tech5\\tungsten\\game\\ai\\cover\\VehicleCove"
                                                                       "r.cpp(230) : Translation")->world;
                      if ( ai_debugDynamicCover.valueInteger > 1 )
                      {
                        v25 = &v75;
                        p_z = (idClipModel *)&ClipForAAS->axis.mat[2].z;
                        for ( i = 6; i != 0; --i )
                        {
                          p_z = (idClipModel *)((char *)p_z + 4);
                          v25 += 4;
                          *(_DWORD *)v25 = p_z->__vftable;
                        }
                        v28 = (idClipModel *)&ClipForAAS->axis.mat[2].z;
                        v29 = 6;
                        v76.b[0].x = v76.b[0].x + v77.x;
                        v76.b[0].y = v76.b[0].y + v77.y;
                        v30 = &v79;
                        v76.b[0].z = v76.b[0].z + v77.z;
                        v76.b[1].x = v76.b[1].x + v77.x;
                        v76.b[1].y = v76.b[1].y + v77.y;
                        v76.b[1].z = v76.b[1].z + v77.z;
                        do
                        {
                          v28 = (idClipModel *)((char *)v28 + 4);
                          *++v30 = (int)v28->__vftable;
                          --v29;
                        }
                        while ( v29 != 0 );
                        v80.b[0].x = v80.b[0].x + v78.x;
                        v80.b[0].y = v80.b[0].y + v78.y;
                        v80.b[0].z = v80.b[0].z + v78.z;
                        v80.b[1].x = v80.b[1].x + v78.x;
                        v80.b[1].y = v80.b[1].y + v78.y;
                        v80.b[1].z = v80.b[1].z + v78.z;
                        idBounds::AddBounds(this: &v76, a: &v80);
                        v31 = gameLocal->GetRenderWorld(this: gameLocal);
                        v31->DebugBounds(
                          this: v31,
                          a2: (const idVec4 *)&idColor::colorLtGrey,
                          a3: &v76,
                          a4: &vec3_origin,
                          a5: 5000,
                          a6: true);
                      }
                      v18 = v72;
                    }
                  }
                }
                ++v18;
                ++v19;
                v72 = v18;
                ++v73;
              }
              while ( v73 < this->numCover );
            }
          }
        }
      }
    }
  }
}

