
// ========================================================================
// ??0idFormationCover@@QAA@XZ
// EA  : 0x82A8FCA0
// RVA : 0x00A8FCA0
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

idFormationCover *__fastcall idFormationCover::idFormationCover(idFormationCover *this)
{
  idDynamicCover::idDynamicCover(this, _numCover: 1);
  this->numCover = 1;
  this->__vftable = (idFormationCover_vtbl *)&idFormationCover::`vftable';
  return this;
}


// ========================================================================
// ?UpdateUsable@idFormationCover@@UAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A8FD48
// RVA : 0x00A8FD48
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

void __fastcall idFormationCover::UpdateUsable(idFormationCover *this, idEntity *owner, const idAAS2 *aas, int curTime)
{
  idFormationCover_vtbl *v8; // r11
  bool v9; // r7
  int v10; // r10
  int v11; // r11
  idDynamicCover::coverInfo_t *list; // r8

  if ( owner->IsDead(this: owner) )
  {
    this->MarkAllUnusable(this);
    return;
  }
  v8 = this->__vftable;
  if ( !this->updated )
  {
    v8->MarkAllUnusable(this);
    this->InternalUpdateUsable(this, a2: owner, a3: aas, a4: curTime);
LABEL_10:
    v9 = true;
    goto LABEL_11;
  }
  v8->InternalUpdateCurrent(this, a2: owner, a3: aas, a4: curTime);
  v9 = false;
  v10 = 0;
  if ( this->numCover > 0 )
  {
    v11 = 0;
    list = this->coverInfo.list;
    while ( (list->cover.flags & 0x2000) != 0 )
    {
      ++v10;
      list = &this->coverInfo.list[++v11];
      if ( v10 >= this->numCover )
      {
        this->updated = false;
        return;
      }
    }
    goto LABEL_10;
  }
LABEL_11:
  this->updated = v9;
}


// ========================================================================
// ?AllocCover@idFormationCoverMgr@@UAAPAVidDynamicCover@@PBVidAAS2@@@Z
// EA  : 0x82A8FE68
// RVA : 0x00A8FE68
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

idDynamicCover *__fastcall idFormationCoverMgr::AllocCover(idFormationCoverMgr *this, const idAAS2 *aas)
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
  idDynamicCover::idDynamicCover(this: v2, _numCover: 1);
  v3[1] = 1;
  *v3 = &idFormationCover::`vftable';
  return (idDynamicCover *)v3;
}


// ========================================================================
// __unwind$487735
// EA  : 0x82A8FEF8
// RVA : 0x00A8FEF8
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

void __fastcall _unwind_487735(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?InternalUpdateCurrent@idFormationCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A8FF20
// RVA : 0x00A8FF20
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

void __fastcall idFormationCover::InternalUpdateCurrent(
        idFormationCover *this,
        idAI2 *owner,
        idAAS2 *aas,
        const int curTime)
{
  unsigned __int64 v4; // r27
  int v7; // r14
  int *p_coverFlags; // r18
  int v9; // r29
  idAI2 *v10; // r3
  idEntity *v11; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v14; // r30
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r31
  const char *PropNameForAAS; // r3
  const tagData_t *Tag; // r4
  idClientGame *v19; // r31
  idDynamicCover::coverInfo_t *v20; // r11
  idClip *p_clip; // r3
  idDynamicCover::coverInfo_t *v22; // r11
  unsigned __int64 index; // r10
  const idClipModel *ClipForAAS; // r3
  char *v25; // r10
  const idClipModel *p_z; // r11
  int i; // ctr
  idRenderWorld *v28; // r3
  idColor *v29; // r4
  idBounds *v30; // r5
  idClipQuery *p_translationQuery; // r30
  idClipQuery v32; // r11
  idDynamicCover::coverInfo_t *list; // r11
  idDynamicCover::coverInfo_t *v34; // r31
  const idClipModel *v35; // r3
  char *v36; // r10
  const idClipModel *v37; // r11
  int j; // ctr
  char *v39; // r10
  double v40; // fp11
  int v41; // ctr
  char *v42; // r11
  __int16 v43; // r3
  const idClipModel *v44; // r3
  char *v45; // r10
  const idClipModel *v46; // r11
  int k; // ctr
  char *v48; // r10
  double v49; // fp11
  int v50; // ctr
  char *v51; // r11
  idRenderWorld *v52; // r3
  const idClipModel *v53; // r3
  char *v54; // r10
  const idClipModel *v55; // r11
  int m; // ctr
  char *v57; // r10
  double v58; // fp11
  int v59; // ctr
  char *v60; // r11
  char v61; // [sp+5Ch] [-2F4h] BYREF
  idBounds v62; // [sp+60h] [-2F0h] BYREF
  char v63; // [sp+7Ch] [-2D4h] BYREF
  idBounds v64; // [sp+80h] [-2D0h] BYREF
  char v65; // [sp+9Ch] [-2B4h] BYREF
  idBounds v66; // [sp+A0h] [-2B0h] BYREF
  char v67; // [sp+BCh] [-294h] BYREF
  float v68; // [sp+C0h] [-290h] BYREF
  float v69; // [sp+C4h] [-28Ch]
  float v70; // [sp+C8h] [-288h]
  float v71; // [sp+CCh] [-284h]
  float v72; // [sp+D0h] [-280h]
  float v73; // [sp+D4h] [-27Ch]
  char v74; // [sp+DCh] [-274h] BYREF
  idBounds v75; // [sp+E0h] [-270h] BYREF
  char v76; // [sp+FCh] [-254h] BYREF
  idBounds v77; // [sp+100h] [-250h] BYREF
  char v78; // [sp+11Ch] [-234h] BYREF
  idBounds v79; // [sp+120h] [-230h] BYREF
  idVec3 v80; // [sp+138h] [-218h] BYREF
  float v81[6]; // [sp+148h] [-208h] BYREF
  trace_t v82; // [sp+160h] [-1F0h] BYREF
  idMat3 v83; // [sp+1E0h] [-170h] BYREF
  trace_t v84; // [sp+210h] [-140h] BYREF

  LODWORD(v4) = 0;
  v7 = 0;
  if ( this->numCover > 0 )
  {
    p_coverFlags = &formationCoverProps[0].coverFlags;
    v9 = 0;
    HIDWORD(v4) = &consoleFont[21088];
    do
    {
      v10 = idAI2::CastTo(c: owner);
      v11 = v10;
      if ( v10 == nullptr )
        return;
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10);
      presentable = v11->presentable;
      v14 = TreeAnimatorFromPresentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v11);
        presentable = v11->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      if ( v14 == nullptr )
        return;
      decl = v14->decl;
      if ( decl == nullptr )
        return;
      p_props = &decl->props;
      if ( decl == (const idDeclMD6 *)-352 )
        return;
      PropNameForAAS = idDynamicCover::GetPropNameForAAS(aas);
      Tag = idPropsCollection::GetTag(
              this: p_props,
              propName: PropNameForAAS,
              tagName: (const char *)*(p_coverFlags - 1));
      if ( Tag->parentJoint.value != 0xFFFF
        && (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(this: v14, tagData: Tag, origin: &v80, axis: &v83) != 0 )
      {
        v19 = clientGame;
        v20 = &this->coverInfo.list[v9];
        p_clip = &clientGame->clip;
        v20->cover.origin = v80;
        v20->cover.dir = v83.mat[0];
        if ( (unsigned __int8)idClip::QueryIsValid(this: p_clip, clipQuery: &this->coverInfo.list[v9].contentsQuery) != 0 )
        {
          v22 = &this->coverInfo.list[v9];
          index = v22->contentsQuery.index;
          v22->contentsQuery.index = v4;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v84,
            query: &v19->clip.collisionQueries[index & 0xFFF].query,
            peek: false);
          if ( (v84.c.contentFlags & 0x11) != 0 )
          {
            this->coverInfo.list[v9].cover.flags |= 0x2000u;
            if ( (unsigned __int8)idClip::QueryIsValid(
                                    this: &clientGame->clip,
                                    clipQuery: &this->coverInfo.list[v9].translationQuery) != 0 )
              this->coverInfo.list[v9].translationQuery.index = v4;
            if ( ai_debugDynamicCover.valueInteger <= 1 )
              goto LABEL_42;
            ClipForAAS = idDynamicCover::GetClipForAAS((const idClipModel *)aas);
            v25 = &v67;
            p_z = (const idClipModel *)&ClipForAAS->axis.mat[2].z;
            for ( i = 6; i != 0; --i )
            {
              p_z = (const idClipModel *)((char *)p_z + 4);
              v25 += 4;
              *(_DWORD *)v25 = p_z->__vftable;
            }
            v70 = v84.endpos.z + v70;
            v71 = v71 + v84.endpos.x;
            v72 = v72 + v84.endpos.y;
            v73 = v73 + v84.endpos.z;
            v68 = v84.endpos.x + v68;
            v69 = v84.endpos.y + v69;
            v28 = gameLocal->GetRenderWorld(this: gameLocal);
            v29 = &idColor::colorYellow;
            v30 = (idBounds *)&v68;
            goto LABEL_41;
          }
          v19 = clientGame;
        }
        p_translationQuery = &this->coverInfo.list[v9].translationQuery;
        if ( (unsigned __int8)idClip::QueryIsValid(this: &v19->clip, clipQuery: p_translationQuery) != 0 )
        {
          v32.index = p_translationQuery->index;
          p_translationQuery->index = v4;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v82,
            query: &v19->clip.collisionQueries[v32.index & 0xFFF].query,
            peek: false);
          list = this->coverInfo.list;
          v34 = &list[v9];
          if ( v82.fraction == 1.0 )
          {
            v34->cover.flags |= 0x2000u;
            if ( ai_debugDynamicCover.valueInteger > 1 )
            {
              v35 = idDynamicCover::GetClipForAAS((const idClipModel *)aas);
              v36 = &v65;
              v37 = (const idClipModel *)&v35->axis.mat[2].z;
              for ( j = 6; j != 0; --j )
              {
                v37 = (const idClipModel *)((char *)v37 + 4);
                v36 += 4;
                *(_DWORD *)v36 = v37->__vftable;
              }
              v39 = &v78;
              v40 = (float)(v82.endpos.x + v66.b[0].x);
              v41 = 6;
              v66.b[0].x = v82.endpos.x + v66.b[0].x;
              v42 = &v65;
              v66.b[0].y = v82.endpos.y + v66.b[0].y;
              v66.b[0].z = v82.endpos.z + v66.b[0].z;
              v66.b[1].x = v66.b[1].x + v82.endpos.x;
              v66.b[1].y = v66.b[1].y + v82.endpos.y;
              v66.b[1].z = v66.b[1].z + v82.endpos.z;
              do
              {
                v42 += 4;
                v39 += 4;
                *(_DWORD *)v39 = *(_DWORD *)v42;
                --v41;
              }
              while ( v41 != 0 );
              v79.b[0].x = v40;
              v79.b[0].z = v79.b[0].z + (float)(v82.fraction * (float)96.0);
              v79.b[1].z = v79.b[1].z + (float)(v82.fraction * (float)96.0);
              idBounds::AddBounds(this: &v66, a: &v79);
              v28 = gameLocal->GetRenderWorld(this: gameLocal);
              v29 = &idColor::colorRed;
              v30 = &v66;
LABEL_41:
              v28->DebugBounds(this: v28, a2: (const idVec4 *)v29, a3: v30, a4: &vec3_origin, a5: 5000, a6: true);
            }
          }
          else
          {
            v34->cover.origin = v82.endpos;
            v43 = aas->PointAreaNum(this: aas, a2: nullptr, a3: (const idVec3 *)&list[v9]);
            v34->cover.areaNum = v43;
            if ( v43 <= 0 )
            {
              v34->cover.flags |= 0x2000u;
              if ( ai_debugDynamicCover.valueInteger > 1 )
              {
                v44 = idDynamicCover::GetClipForAAS((const idClipModel *)aas);
                v45 = &v61;
                v46 = (const idClipModel *)&v44->axis.mat[2].z;
                for ( k = 6; k != 0; --k )
                {
                  v46 = (const idClipModel *)((char *)v46 + 4);
                  v45 += 4;
                  *(_DWORD *)v45 = v46->__vftable;
                }
                v48 = &v74;
                v49 = (float)(v62.b[0].x + v82.endpos.x);
                v50 = 6;
                v62.b[0].x = v62.b[0].x + v82.endpos.x;
                v51 = &v61;
                v62.b[0].y = v62.b[0].y + v82.endpos.y;
                v62.b[0].z = v62.b[0].z + v82.endpos.z;
                v62.b[1].x = v62.b[1].x + v82.endpos.x;
                v62.b[1].y = v62.b[1].y + v82.endpos.y;
                v62.b[1].z = v62.b[1].z + v82.endpos.z;
                do
                {
                  v51 += 4;
                  v48 += 4;
                  *(_DWORD *)v48 = *(_DWORD *)v51;
                  --v50;
                }
                while ( v50 != 0 );
                v75.b[0].x = v49;
                v75.b[0].z = v75.b[0].z + (float)(v82.fraction * (float)96.0);
                v75.b[1].z = v75.b[1].z + (float)(v82.fraction * (float)96.0);
                idBounds::AddBounds(this: &v62, a: &v75);
                v52 = gameLocal->GetRenderWorld(this: gameLocal);
                v81[0] = (float)(v62.b[1].x + v62.b[0].x) * (float)0.5;
                v81[1] = (float)(v62.b[1].y + v62.b[0].y) * (float)0.5;
                v81[2] = (float)(v62.b[1].z + v62.b[0].z) * (float)0.5;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, int, int, double))v52->DebugText)(
                  a1: v52,
                  a2: "INVALID AAS AREA",
                  a3: v81,
                  a4: v52->__vftable,
                  a5: &idColor::colorRed,
                  a6: 1,
                  a7: 5000,
                  a8: 1,
                  a9: 0.2);
              }
              goto LABEL_42;
            }
            v34->cover.flags = *p_coverFlags;
            if ( ai_debugDynamicCover.valueInteger > 1 )
            {
              v53 = idDynamicCover::GetClipForAAS((const idClipModel *)aas);
              v54 = &v63;
              v55 = (const idClipModel *)&v53->axis.mat[2].z;
              for ( m = 6; m != 0; --m )
              {
                v55 = (const idClipModel *)((char *)v55 + 4);
                v54 += 4;
                *(_DWORD *)v54 = v55->__vftable;
              }
              v57 = &v76;
              v58 = (float)(v82.endpos.x + v64.b[0].x);
              v59 = 6;
              v64.b[0].x = v82.endpos.x + v64.b[0].x;
              v60 = &v63;
              v64.b[0].y = v64.b[0].y + v82.endpos.y;
              v64.b[0].z = v64.b[0].z + v82.endpos.z;
              v64.b[1].x = v64.b[1].x + v82.endpos.x;
              v64.b[1].y = v64.b[1].y + v82.endpos.y;
              v64.b[1].z = v64.b[1].z + v82.endpos.z;
              do
              {
                v60 += 4;
                v57 += 4;
                *(_DWORD *)v57 = *(_DWORD *)v60;
                --v59;
              }
              while ( v59 != 0 );
              v77.b[0].x = v58;
              v77.b[0].z = v77.b[0].z + (float)(v82.fraction * (float)96.0);
              v77.b[1].z = v77.b[1].z + (float)(v82.fraction * (float)96.0);
              idBounds::AddBounds(this: &v64, a: &v77);
              v28 = gameLocal->GetRenderWorld(this: gameLocal);
              v29 = &idColor::colorGreen;
              v30 = &v64;
              goto LABEL_41;
            }
          }
        }
      }
LABEL_42:
      ++v7;
      ++v9;
      p_coverFlags += 2;
    }
    while ( v7 < this->numCover );
  }
}


// ========================================================================
// ?InternalUpdateUsable@idFormationCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A90690
// RVA : 0x00A90690
// PDB : w:\tech5\tungsten\game\ai\cover\formationcover.cpp
// ========================================================================

void __fastcall idFormationCover::InternalUpdateUsable(
        idFormationCover *this,
        idAI2 *owner,
        const idClipModel *aas,
        int curTime)
{
  idAI2 *v7; // r3
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

  v7 = idAI2::CastTo(c: owner);
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
              v18 = formationCoverProps;
              v72 = formationCoverProps;
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
                                                               a28: (int)"w:\\tech5\\tungsten\\game\\ai\\cover\\FormationCover"
                                                                    ".cpp(225) : Contents")->world;
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
                                                                  a32: (int)"w:\\tech5\\tungsten\\game\\ai\\cover\\FormationCo"
                                                                       "ver.cpp(234) : Translation")->world;
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

