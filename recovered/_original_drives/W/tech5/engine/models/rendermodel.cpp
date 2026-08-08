
// ========================================================================
// ?GetIndex@idRenderModel@@QBAHXZ
// EA  : 0x827F27E0
// RVA : 0x007F27E0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

unsigned int __fastcall idRenderModel::GetIndex(idRenderModel *this)
{
  return this->committed->index.index >> 8;
}


// ========================================================================
// ?GetWorld@idRenderModel@@QBAPAVidRenderWorld@@XZ
// EA  : 0x827F27F0
// RVA : 0x007F27F0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

idRenderWorldLocal *__fastcall idRenderModel::GetWorld(idRenderModel *this)
{
  return this->committed->world;
}


// ========================================================================
// ?GetParmBlock@idRenderModel@@QAAPAVidParmBlock@@XZ
// EA  : 0x827F2800
// RVA : 0x007F2800
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

idStaticParmBlock<32> *__fastcall idRenderModel::GetParmBlock(idRenderModel *this)
{
  return &this->gameParmBlock;
}


// ========================================================================
// ?SetParm@idRenderModel@@QAAXPBVidDeclRenderParm@@TparmValue_t@@@Z
// EA  : 0x827F2808
// RVA : 0x007F2808
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModel::SetParm(
        idRenderModel *this,
        const idDeclRenderParm *parm,
        __int64 parmValue,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  a11 = *(__int64 *)((char *)&parmValue + 4);
  HIDWORD(parmValue) = &a11;
  a12 = parmValue;
  idParmBlock::SetParm(this: &this->gameParmBlock, parm, parmValue: (const parmValue_t *)&a11);
}


// ========================================================================
// ?SetParm@idRenderModel@@QAAXPBVidDeclRenderParm@@M@Z
// EA  : 0x827F2838
// RVA : 0x007F2838
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetParm(idRenderModel *this, const idDeclRenderParm *parm, double scalar)
{
  parmValue_t v3; // [sp+60h] [-20h] BYREF
  parmValue_t v4; // 0:^50.16

  v4.value[3] = scalar;
  v4.value[2] = scalar;
  v4.value[1] = scalar;
  v4.value[0] = scalar;
  v3 = v4;
  idParmBlock::SetParm(this: &this->gameParmBlock, parm, parmValue: &v3);
}


// ========================================================================
// ?SetDecalPosition@idRenderModel@@IAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827F2898
// RVA : 0x007F2898
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

BOOL __fastcall idRenderModel::SetDecalPosition(
        idRenderModel *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle,
        const idVec3 *decalWorldPosition,
        const idMat3 *decalWorldAxis)
{
  idRenderWorldLocal *world; // r11

  world = this->committed->world;
  return world != nullptr
      && idRenderModelDecal::SetDecalPosition(
           this: world->decalRenderModel,
           decalHandle,
           decalWorldPosition,
           decalWorldAxis);
}


// ========================================================================
// ?SetViewport@idRenderModel@@QAAXHHHH@Z
// EA  : 0x827F28C0
// RVA : 0x007F28C0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetViewport(idRenderModel *this, int x, int y, int width, int height)
{
  this->g.viewport.x1 = x;
  this->g.viewport.y1 = y;
  this->g.viewport.x2 = x + width - 1;
  this->g.viewport.y2 = y + height - 1;
}


// ========================================================================
// ?ClearOcclusionQuery@idRenderModel@@QAAXXZ
// EA  : 0x827F28E8
// RVA : 0x007F28E8
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::ClearOcclusionQuery(idRenderModel *this)
{
  idRenderWorldLocal *world; // r3

  world = this->committed->world;
  if ( world != nullptr )
    idRenderWorldLocal::ClearOcclusionQueryForModel(this: world, model: this);
}


// ========================================================================
// ?GetModelMatrix@idRenderModel@@IBAABVidRenderMatrix@@XZ
// EA  : 0x827F2908
// RVA : 0x007F2908
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

const idRenderMatrix *__fastcall idRenderModel::GetModelMatrix(idRenderModel *this)
{
  return &this->committed->modelMatrix;
}


// ========================================================================
// ?GetRenderParmBlock@idRenderModel@@IAAPAVidParmBlock@@XZ
// EA  : 0x827F2918
// RVA : 0x007F2918
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

idStaticParmBlock<32> *__fastcall idRenderModel::GetRenderParmBlock(idRenderModel *this)
{
  return &this->committed->renderParmBlock;
}


// ========================================================================
// ?GetApproximateLighting@idRenderModel@@IBAABUapproximateLighting_t@@XZ
// EA  : 0x827F2928
// RVA : 0x007F2928
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

const approximateLighting_t *__fastcall idRenderModel::GetApproximateLighting(idRenderModel *this)
{
  return &this->committed->approximateLighting;
}


// ========================================================================
// ?SetLitTransSortFlag@idRenderModel@@IAAXXZ
// EA  : 0x827F2938
// RVA : 0x007F2938
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetLitTransSortFlag(idRenderModel *this)
{
  *((_BYTE *)this->committed + 1416) |= 1u;
}


// ========================================================================
// ?SetName@idRenderModel@@QAAXPBD@Z
// EA  : 0x827F2CD8
// RVA : 0x007F2CD8
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetName(idRenderModel *this, const char *name_)
{
  idAtomicString::Set(this: &this->name, str_: name_);
  this->committed->name = this->name.str;
}


// ========================================================================
// ?SetParm@idRenderModel@@QAAXPBVidDeclRenderParm@@ABVidVec3@@@Z
// EA  : 0x827F2D18
// RVA : 0x007F2D18
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetParm(idRenderModel *this, const idDeclRenderParm *parm, const idVec3 *v3)
{
  __int64 var2C; // [sp+54h] [-2Ch]
  parmValue_t v4; // [sp+60h] [-20h] BYREF

  *(float *)&var2C = v3->y;
  *((float *)&var2C + 1) = v3->z;
  v4.value[0] = v3->x;
  *(_QWORD *)(&v4.string + 1) = var2C;
  v4.value[3] = 0.0;
  idParmBlock::SetParm(this: &this->gameParmBlock, parm, parmValue: &v4);
}


// ========================================================================
// ?SetParm@idRenderModel@@QAAXPBVidDeclRenderParm@@ABVidVec4@@@Z
// EA  : 0x827F2D90
// RVA : 0x007F2D90
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetParm(idRenderModel *this, const idDeclRenderParm *parm, const idVec4 *v4)
{
  double y; // fp13
  double z; // fp12
  parmValue_t v5; // [sp+50h] [-20h] BYREF

  y = v4->y;
  z = v4->z;
  v5.value[0] = v4->x;
  v5.value[1] = y;
  v5.value[3] = v4->w;
  v5.value[2] = z;
  idParmBlock::SetParm(this: &this->gameParmBlock, parm, parmValue: &v5);
}


// ========================================================================
// ?FinishSurfaces@idRenderModel@@QAAXXZ
// EA  : 0x827F2E08
// RVA : 0x007F2E08
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::FinishSurfaces(idRenderModel *this)
{
  int v1; // r8
  int v2; // r11
  idRenderModelSurface *list; // r9
  const idMaterial *material; // r10
  const idMaterial *customMaterial; // r10
  idBounds *p_referenceBounds; // r11
  int v7; // r8
  int v8; // r9
  float *geometry; // r10
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v14; // fp8
  double v15; // fp7

  if ( this->g.customSkin != 0 || this->g.customMaterial != nullptr )
  {
    v1 = 0;
    if ( this->surfaces.num > 0 )
    {
      v2 = 0;
      do
      {
        list = this->surfaces.list;
        material = list[v2].material;
        if ( material != nullptr && material->coverage != MC_INVISIBLE )
        {
          customMaterial = this->g.customMaterial;
          if ( customMaterial != nullptr )
            list[v2].material = customMaterial;
        }
        ++v1;
        ++v2;
      }
      while ( v1 < this->surfaces.num );
    }
  }
  if ( this->surfaces.num != 0 )
  {
    p_referenceBounds = &this->referenceBounds;
    v7 = 0;
    this->referenceBounds.b[0].z = 1.0e30;
    this->referenceBounds.b[0].y = 1.0e30;
    this->referenceBounds.b[0].x = 1.0e30;
    this->referenceBounds.b[1].z = -1.0e30;
    this->referenceBounds.b[1].y = -1.0e30;
    this->referenceBounds.b[1].x = -1.0e30;
    if ( this->surfaces.num > 0 )
    {
      v8 = 0;
      do
      {
        geometry = (float *)this->surfaces.list[v8].geometry;
        if ( geometry != nullptr )
        {
          _FP12 = (float)(p_referenceBounds->b[0].x - *geometry);
          y = this->referenceBounds.b[0].y;
          z = this->referenceBounds.b[0].z;
          x = this->referenceBounds.b[1].x;
          v14 = this->referenceBounds.b[1].y;
          v15 = this->referenceBounds.b[1].z;
          __asm { fsel      f6, f12, f0, f13 }
          p_referenceBounds->b[0].x = _FP6;
          _FP4 = (float)((float)y - geometry[1]);
          __asm { fsel      f3, f4, f5, f11 }
          this->referenceBounds.b[0].y = _FP3;
          _FP1 = (float)((float)z - geometry[2]);
          __asm { fsel      f0, f1, f2, f10 }
          this->referenceBounds.b[0].z = _FP0;
          _FP12 = (float)(geometry[3] - (float)x);
          __asm { fsel      f11, f12, f13, f9 }
          this->referenceBounds.b[1].x = _FP11;
          _FP9 = (float)(geometry[4] - (float)v14);
          __asm { fsel      f8, f9, f10, f8 }
          this->referenceBounds.b[1].y = _FP8;
          _FP5 = (float)(geometry[5] - (float)v15);
          __asm { fsel      f4, f5, f6, f7 }
          this->referenceBounds.b[1].z = _FP4;
        }
        ++v7;
        ++v8;
      }
      while ( v7 < this->surfaces.num );
    }
  }
}


// ========================================================================
// ?CommitThisFrame@idRenderModel@@QAAXXZ
// EA  : 0x827F2F70
// RVA : 0x007F2F70
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::CommitThisFrame(idRenderModel *this)
{
  idRenderModelCommitted *committed; // r11
  idRenderWorldLocal *world; // r10

  committed = this->committed;
  this->unlinked = false;
  world = committed->world;
  if ( world != nullptr )
    world->commitModels.ptr[committed->index.index >> 8] = true;
}


// ========================================================================
// ?CompareEqualMat3@@YA_NABVidMat3@@0@Z
// EA  : 0x827F2FA8
// RVA : 0x007F2FA8
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

int __fastcall CompareEqualMat3(const idMat3 *a, const idMat3 *b)
{
  return ((_cntlzw(
             LODWORD(a->mat[2].z) ^ LODWORD(b->mat[2].z)
           | LODWORD(a->mat[2].y) ^ LODWORD(b->mat[2].y)
           | LODWORD(a->mat[2].x) ^ LODWORD(b->mat[2].x))
         & 0x20) != 0)
       & ((_cntlzw(
             LODWORD(a->mat[1].z) ^ LODWORD(b->mat[1].z)
           | LODWORD(a->mat[1].y) ^ LODWORD(b->mat[1].y)
           | LODWORD(a->mat[1].x) ^ LODWORD(b->mat[1].x))
         & 0x20) != 0)
       & ((_cntlzw(
             LODWORD(a->mat[0].z) ^ LODWORD(b->mat[0].z)
           | LODWORD(a->mat[0].y) ^ LODWORD(b->mat[0].y)
           | LODWORD(a->mat[0].x) ^ LODWORD(b->mat[0].x))
         & 0x20) != 0);
}


// ========================================================================
// ?InitDecalData@idRenderModel@@IAAXAAUdecalData_t@1@PBUdecalParams_t@@HABVidVec3@@2@Z
// EA  : 0x827F3400
// RVA : 0x007F3400
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::InitDecalData(
        idRenderModel *this,
        idRenderModel::decalData_t *decal,
        const decalParams_t *decalParms,
        const int startTime,
        const idVec3 *pos,
        const idVec3 *dir)
{
  int *v9; // r3
  const idHandle<int,enum invalidDecalHandle_t,-1> *v10; // r4
  float *p_deferredAxis; // r11
  double v12; // fp0
  double v13; // fp13
  double v14; // fp12
  double v15; // fp11
  double v16; // fp10
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  idRenderModelParms *p_deferredOrigin; // r11
  double v22; // fp1
  double v23; // fp3
  double v24; // fp2
  double v25; // fp0
  float *p_axis; // r11
  double v27; // fp13
  double v28; // fp12
  double v29; // fp11
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp7
  double v34; // fp6
  _BYTE v35[16]; // [sp+50h] [-D0h] BYREF
  idMat3 v36; // [sp+60h] [-C0h] BYREF
  idMat3 v37; // [sp+90h] [-90h] BYREF
  idMat3 v38[2]; // [sp+C0h] [-60h] BYREF

  v9 = (int *)((int (__fastcall *)(_BYTE *))this->committed->world->decalRenderModel->AddDecalFromPoint)(a1: v35);
  v10 = (const idHandle<int,enum invalidDecalHandle_t,-1> *)*v9;
  decal->handle.value = *v9;
  idRenderModelDecal::GetDecalAxis(this: this->committed->world->decalRenderModel, decalHandle: v10, decalAxis: &v37);
  p_deferredAxis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_deferredAxis = (float *)&this->g.axis;
  v12 = p_deferredAxis[8];
  v13 = p_deferredAxis[5];
  v14 = p_deferredAxis[2];
  v15 = p_deferredAxis[7];
  v16 = p_deferredAxis[4];
  v17 = p_deferredAxis[1];
  v18 = p_deferredAxis[6];
  v19 = p_deferredAxis[3];
  v20 = *p_deferredAxis;
  p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
  if ( !this->useDeferredPosition )
    p_deferredOrigin = &this->g;
  v22 = (float)(pos->x - p_deferredOrigin->origin.x);
  v23 = (float)((float)((float)(pos->z - p_deferredOrigin->origin.z) * (float)v12)
              + (float)((float)(pos->y - p_deferredOrigin->origin.y) * (float)v15));
  v24 = (float)((float)((float)(pos->z - p_deferredOrigin->origin.z) * (float)v14)
              + (float)((float)(pos->y - p_deferredOrigin->origin.y) * (float)v17));
  v25 = (float)((float)((float)(pos->z - p_deferredOrigin->origin.z) * (float)v13)
              + (float)((float)(pos->y - p_deferredOrigin->origin.y) * (float)v16));
  decal->relativePos.z = (float)((float)(pos->x - p_deferredOrigin->origin.x) * (float)v18) + (float)v23;
  decal->relativePos.x = (float)((float)v22 * (float)v20) + (float)v24;
  decal->relativePos.y = (float)((float)v22 * (float)v19) + (float)v25;
  p_axis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_axis = (float *)&this->g.axis;
  v27 = p_axis[5];
  v28 = p_axis[2];
  v29 = p_axis[7];
  v30 = p_axis[4];
  v31 = p_axis[1];
  v32 = p_axis[6];
  v33 = p_axis[3];
  v34 = *p_axis;
  v36.mat[2].z = p_axis[8];
  v36.mat[2].y = v27;
  v36.mat[2].x = v28;
  v36.mat[1].z = v29;
  v36.mat[1].y = v30;
  v36.mat[1].x = v31;
  v36.mat[0].z = v32;
  v36.mat[0].y = v33;
  v36.mat[0].x = v34;
  decal->relativeAxis = *idMat3::operator*(this: v38, result: &v37, a: &v36);
  decal->jointId = NULL_JOINT_INDEX;
}


// ========================================================================
// ?IsRendered@idRenderModel@@QBA_NXZ
// EA  : 0x827F35D0
// RVA : 0x007F35D0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

BOOL __fastcall idRenderModel::IsRendered(idRenderModel *this)
{
  idRenderWorldLocal *world; // r10
  idRenderModelCommitted *committed; // r10
  idRenderWorldLocal *v3; // r31
  unsigned int v4; // r9
  idRenderView **list; // r11
  int v6; // r6
  idRenderView *v7; // r8
  int v8; // r11
  int firstVisibleFrameCount; // r10
  int v10; // r11

  world = this->committed->world;
  if ( world == nullptr || world->renderViews.num <= 0 )
    return false;
  committed = this->committed;
  v3 = committed->world;
  v4 = committed->index.index >> 8;
  list = v3->renderViews.list;
  v6 = 4 * (v4 + 41088);
  v7 = list[v3->renderViews.num - 1];
  v8 = *(_DWORD *)((char *)(*list)->occlusionState->nodeOcclusionQuery + v6) < (*list)->occlusionState->renderFrameNumber
     ? 0
     : (*list)->occlusionState->modelVisibleFrameCount[v4];
  firstVisibleFrameCount = this->g.firstVisibleFrameCount;
  if ( v8 >= firstVisibleFrameCount )
    return true;
  v10 = *(_DWORD *)((char *)v7->occlusionState->nodeOcclusionQuery + v6) < v7->occlusionState->renderFrameNumber
      ? 0
      : v7->occlusionState->modelVisibleFrameCount[v4];
  return v10 >= firstVisibleFrameCount;
}


// ========================================================================
// ?GetNumReferences@idRenderModel@@QBAHXZ
// EA  : 0x827F36D0
// RVA : 0x007F36D0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

int __fastcall idRenderModel::GetNumReferences(idRenderModel *this)
{
  return this->committed->references.num;
}


// ========================================================================
// ?Save@idRenderModel@@UBAXPAVidFile@@@Z
// EA  : 0x827F3D98
// RVA : 0x007F3D98
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::Save(idRenderModel *this, idFile *fp)
{
  idFile_vtbl *v4; // r6
  idFile_vtbl *v5; // r9
  idFile_vtbl *v6; // r6
  const idMaterial *customMaterial; // r11
  const char *str; // r4
  idFile_vtbl *v9; // r8
  idFile_vtbl *v10; // r10
  idFile_vtbl *v11; // r6
  idFile_vtbl *v12; // r8
  idFile_vtbl *v13; // r10
  idFile_vtbl *v14; // r6
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v16; // r10
  idFile_vtbl *v17; // r6
  idFile_vtbl *v18; // r8
  idFile_vtbl *v19; // r10
  idFile_vtbl *v20; // r6
  idFile_vtbl *v21; // r8
  idFile_vtbl *v22; // r10
  idFile_vtbl *v23; // r7
  idFile_vtbl *v24; // r8
  idFile_vtbl *v25; // r10
  idFile_vtbl *v26; // r6
  idFile_vtbl *v27; // r6
  char useDeferredPosition; // [sp+50h] [-20h] BYREF
  char v29; // [sp+51h] [-1Fh] BYREF
  _BYTE v30[6]; // [sp+52h] [-1Eh] BYREF

  fp->Write(this: fp, a2: &this->deferredOrigin, a3: 12u);
  fp->Write(this: fp, a2: &this->deferredAxis, a3: 36u);
  v4 = fp->__vftable;
  useDeferredPosition = this->useDeferredPosition;
  v4->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v5 = fp->__vftable;
  useDeferredPosition = this->deferredPositionInitialized;
  v5->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v6 = fp->__vftable;
  useDeferredPosition = this->unlinked;
  v6->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  fp->Write(this: fp, a2: &this->referenceBounds, a3: 24u);
  customMaterial = this->g.customMaterial;
  if ( customMaterial != nullptr )
    str = customMaterial->name.str;
  else
    str = &byte_8200D768;
  idFile::WriteString(this: fp, string: str);
  fp->Write(this: fp, a2: &this->g.customSkin, a3: 4u);
  fp->Write(this: fp, a2: &this->g, a3: 12u);
  fp->Write(this: fp, a2: &this->g.axis, a3: 36u);
  fp->Write(this: fp, a2: &this->g.scale, a3: 12u);
  fp->Write(this: fp, a2: &this->g.groupMasterIndex, a3: 4u);
  fp->Write(this: fp, a2: &this->g.allowSurfaceOnlyInViewID, a3: 4u);
  fp->Write(this: fp, a2: &this->g.suppressSurfaceInViewID, a3: 4u);
  fp->Write(this: fp, a2: &this->g.suppressShadowInViewID, a3: 4u);
  fp->Write(this: fp, a2: &this->g.suppressShadowInLightIndex, a3: 4u);
  fp->Write(this: fp, a2: &this->g.fovScale, a3: 4u);
  fp->Write(this: fp, a2: &this->g.modelDepthHack, a3: 4u);
  fp->Write(this: fp, a2: &this->g.castDimShadows, a3: 4u);
  fp->Write(this: fp, a2: &this->g.dimShadowClipZ, a3: 4u);
  v9 = fp->__vftable;
  v29 = *((_BYTE *)&this->g + 104) >> 7;
  v9->Write(this: fp, a2: &v29, a3: 1u);
  v10 = fp->__vftable;
  useDeferredPosition = *((_BYTE *)&this->g + 105) >> 7;
  v10->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v11 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 105) & 0x10) != 0;
  v11->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v12 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 105) & 8) != 0;
  v12->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v13 = fp->__vftable;
  useDeferredPosition = *((_BYTE *)&this->g + 106) & 1;
  v13->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v14 = fp->__vftable;
  useDeferredPosition = *((_BYTE *)&this->g + 107) >> 7;
  v14->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  Write = fp->Write;
  useDeferredPosition = (*((_BYTE *)&this->g + 107) & 0x40) != 0;
  Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v16 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 107) & 0x20) != 0;
  v16->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v17 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 107) & 0x10) != 0;
  v17->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v18 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 105) & 4) != 0;
  v18->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v19 = fp->__vftable;
  useDeferredPosition = *((_BYTE *)&this->g + 105) & 1;
  v19->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v20 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 106) & 0x40) != 0;
  v20->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v21 = fp->__vftable;
  useDeferredPosition = *((_BYTE *)&this->g + 106) >> 7;
  v21->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v22 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 106) & 0x10) != 0;
  v22->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v23 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 106) & 8) != 0;
  v23->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v24 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 106) & 4) != 0;
  v24->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v25 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 106) & 2) != 0;
  v25->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  v26 = fp->__vftable;
  useDeferredPosition = (*((_BYTE *)&this->g + 105) & 2) != 0;
  v26->Write(this: fp, a2: &useDeferredPosition, a3: 1u);
  fp->Write(this: fp, a2: &this->g.highlightColor, a3: 4u);
  fp->Write(this: fp, a2: &this->g.modelFade, a3: 4u);
  fp->Write(this: fp, a2: &this->g.maxVisibleRange, a3: 4u);
  fp->Write(this: fp, a2: &this->g.fadeVisibilityOver, a3: 4u);
  v27 = fp->__vftable;
  v30[0] = *((_BYTE *)&this->g + 104) & 1;
  v27->Write(this: fp, a2: v30, a3: 1u);
  idParmBlock::Save(this: &this->gameParmBlock, fp);
}


// ========================================================================
// ?FreeSurfaces@idRenderModel@@UAAXXZ
// EA  : 0x827F4390
// RVA : 0x007F4390
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::FreeSurfaces(idRenderModel *this)
{
  int v2; // r26
  int v3; // r30
  idRenderModelSurface *v4; // r11
  idTriangles *geometry; // r29
  idRenderModelSurface *v6; // r11
  idVertexBuffer *stMap; // r29
  idRenderModelSurface *v8; // r11
  idVertexBuffer *morphMap; // r29
  idRenderModelSurface *v10; // r11
  idJointBuffer *joints; // r29
  idRenderModelSurface *list; // r4

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->surfaces.list[v3];
      geometry = v4->geometry;
      if ( geometry != nullptr && !v4->geometryIsReference )
      {
        idTriangles::~idTriangles(this: geometry);
        idMem::Free(this: &mem, ptr: geometry, align: ALIGN_16);
        this->surfaces.list[v3].geometry = nullptr;
      }
      v6 = &this->surfaces.list[v3];
      stMap = v6->stMap;
      if ( stMap != nullptr && (v6->referenceMask & 3) == 0 )
      {
        idVertexBuffer::~idVertexBuffer(this: stMap);
        idMem::Free(this: &mem, ptr: stMap, align: ALIGN_16);
        this->surfaces.list[v3].stMap = nullptr;
      }
      v8 = &this->surfaces.list[v3];
      morphMap = v8->morphMap;
      if ( morphMap != nullptr && (v8->referenceMask & 2) == 0 )
      {
        idVertexBuffer::~idVertexBuffer(this: morphMap);
        idMem::Free(this: &mem, ptr: morphMap, align: ALIGN_16);
        this->surfaces.list[v3].morphMap = nullptr;
      }
      v10 = &this->surfaces.list[v3];
      joints = v10->joints;
      if ( joints != nullptr && (v10->referenceMask & 1) == 0 )
      {
        idJointBuffer::~idJointBuffer(this: joints);
        idMem::Free(this: &mem, ptr: joints, align: ALIGN_16);
        this->surfaces.list[v3].joints = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
  if ( this->surfaces.listStatic == 0 || this->surfaces.listStatic == 2 )
  {
    list = this->surfaces.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->surfaces.list = nullptr;
    this->surfaces.size = 0;
  }
  this->surfaces.num = 0;
}


// ========================================================================
// ?RemoveDecals@idRenderModel@@UAAXXZ
// EA  : 0x827F4540
// RVA : 0x007F4540
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::RemoveDecals(idRenderModel *this)
{
  idRenderWorldLocal *world; // r11
  int v3; // r29
  int v4; // r30
  idRenderModelDecal *decalRenderModel; // r3
  idRenderModel::decalData_t *list; // r4

  world = this->committed->world;
  if ( world != nullptr && world->decalRenderModel != nullptr )
  {
    v3 = 0;
    if ( this->decalData.num > 0 )
    {
      v4 = 0;
      do
      {
        decalRenderModel = this->committed->world->decalRenderModel;
        decalRenderModel->RemoveDecal(
          this: decalRenderModel,
          a2: (const idHandle<int,enum invalidDecalHandle_t,-1> *)this->decalData.list[v4].handle.value);
        ++v3;
        ++v4;
      }
      while ( v3 < this->decalData.num );
    }
  }
  if ( this->decalData.listStatic == 0 || this->decalData.listStatic == 2 )
  {
    list = this->decalData.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->decalData.list = nullptr;
    this->decalData.size = 0;
  }
  this->decalData.num = 0;
}


// ========================================================================
// ??1idRenderModel@@MAA@XZ
// EA  : 0x827F4908
// RVA : 0x007F4908
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::~idRenderModel(idRenderModel *this)
{
  idRenderModelCommitted *committed; // r11
  idRenderWorldLocal *world; // r10
  idRenderModelCommitted *v4; // r28

  this->__vftable = (idRenderModel_vtbl *)&idRenderModel::`vftable';
  idRenderModel::FreeSurfaces(this);
  idRenderModel::RemoveDecals(this);
  committed = this->committed;
  world = committed->world;
  if ( world != nullptr )
  {
    world->commitModels.ptr[committed->index.index >> 8] = false;
    this->committed->world->postCommitModels.ptr[this->committed->index.index >> 8] = false;
    this->committed->world->deletedModels.ptr[this->committed->index.index >> 8] = false;
  }
  idRenderModelCommitted::FreeReferences(this: this->committed);
  idRenderModelCommitted::UnlinkAddAlways(this: this->committed);
  v4 = this->committed;
  if ( v4 != nullptr )
  {
    idRenderModelCommitted::~idRenderModelCommitted(this: this->committed);
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
  }
  this->committed = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->decalData);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  idParmBlock::~idParmBlock(this: &this->gameParmBlock);
}


// ========================================================================
// __unwind$239240
// EA  : 0x827F4A00
// RVA : 0x007F4A00
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_239240()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 128 + 148) + 288));
}


// ========================================================================
// __unwind$239241
// EA  : 0x827F4A2C
// RVA : 0x007F4A2C
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_239241()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1104));
}


// ========================================================================
// __unwind$239242
// EA  : 0x827F4A58
// RVA : 0x007F4A58
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_239242()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1120));
}


// ========================================================================
// ?Load@idRenderModel@@UAA_NPAVidFile@@@Z
// EA  : 0x827F4A90
// RVA : 0x007F4A90
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

int __fastcall idRenderModel::Load(idRenderModel *this, idFile *fp)
{
  const idMaterial *v5; // r11
  char v6; // r21
  char v7; // r22
  char v8; // r11
  char v9; // r6
  char v10; // r10
  char v11; // [sp+50h] [-B0h] BYREF
  char v12; // [sp+51h] [-AFh] BYREF
  char v13; // [sp+52h] [-AEh] BYREF
  char v14; // [sp+53h] [-ADh] BYREF
  char v15; // [sp+54h] [-ACh] BYREF
  char v16; // [sp+55h] [-ABh] BYREF
  char v17; // [sp+56h] [-AAh] BYREF
  char v18; // [sp+57h] [-A9h] BYREF
  char v19; // [sp+58h] [-A8h] BYREF
  char v20; // [sp+59h] [-A7h] BYREF
  char v21; // [sp+5Ah] [-A6h] BYREF
  char v22; // [sp+5Bh] [-A5h] BYREF
  char v23; // [sp+5Ch] [-A4h] BYREF
  char v24; // [sp+5Dh] [-A3h] BYREF
  char v25; // [sp+5Eh] [-A2h] BYREF
  char v26; // [sp+5Fh] [-A1h] BYREF
  char v27; // [sp+60h] [-A0h] BYREF
  char v28; // [sp+61h] [-9Fh] BYREF
  char v29; // [sp+62h] [-9Eh] BYREF
  idStr v30[4]; // [sp+70h] [-90h] BYREF

  if ( fp->Read(this: fp, a2: &this->deferredOrigin, a3: 12u) == 0
    || fp->Read(this: fp, a2: &this->deferredAxis, a3: 36u) == 0
    || fp->Read(this: fp, a2: &this->useDeferredPosition, a3: 1u) == 0
    || fp->Read(this: fp, a2: &this->deferredPositionInitialized, a3: 1u) == 0
    || fp->Read(this: fp, a2: &this->unlinked, a3: 1u) == 0
    || fp->Read(this: fp, a2: &this->referenceBounds, a3: 24u) == 0 )
  {
    return 0;
  }
  v30[0].len = 0;
  v30[0].allocedAndFlag = 20;
  v30[0].data = v30[0].baseBuffer;
  v30[0].baseBuffer[0] = 0;
  if ( idFile::ReadString(this: fp, string: v30) == 0 )
  {
    idStr::FreeData(this: v30);
    return 0;
  }
  if ( v30[0].len != 0 )
  {
    if ( v30[0].data != nullptr )
      v5 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v30[0].data,
                                 makeDefault: true);
    else
      v5 = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  this->g.customMaterial = v5;
  if ( fp->Read(this: fp, a2: &this->g.customSkin, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g, a3: 12u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.axis, a3: 36u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.scale, a3: 12u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.groupMasterIndex, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.allowSurfaceOnlyInViewID, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.suppressSurfaceInViewID, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.suppressShadowInViewID, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.suppressShadowInLightIndex, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.fovScale, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.modelDepthHack, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.castDimShadows, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.dimShadowClipZ, a3: 4u) == 0 )
    goto LABEL_70;
  v28 = 0;
  v22 = 0;
  v11 = 0;
  v12 = 0;
  v23 = 0;
  v25 = 0;
  v18 = 0;
  v19 = 0;
  v24 = 0;
  v17 = 0;
  v27 = 0;
  v16 = 0;
  v15 = 0;
  v13 = 0;
  v14 = 0;
  v20 = 0;
  v26 = 0;
  v21 = 0;
  if ( fp->Read(this: fp, a2: &v28, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v22, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v11, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v12, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v23, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v25, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v18, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v19, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v24, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v17, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v27, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v16, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v15, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v13, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v14, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v20, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v26, a3: 1u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &v21, a3: 1u) == 0 )
    goto LABEL_70;
  v6 = v27;
  v7 = (2 * ((2 * ((2 * v13) & 2 | v14 & 1)) | v20 & 1)) | v26 & 1;
  v8 = (2 * ((2 * ((2 * ((2 * v11) & 2 | v12 & 1)) | v17 & 1)) | v21 & 1))
     | (v22 << 7)
     | *((_BYTE *)&this->g + 105) & 0x60;
  v9 = (((unsigned __int8)(2 * v15) | v16 & 1) << 6) | *((_BYTE *)&this->g + 106) & 0x20 | v23 & 1;
  v10 = (16 * ((2 * ((2 * v18) & 2 | v19 & 1)) | v24 & 1)) | (v25 << 7) | *((_BYTE *)&this->g + 107) & 0xF;
  *((_BYTE *)&this->g + 104) = (v28 << 7) | *((_BYTE *)&this->g + 104) & 0x7F;
  *((_BYTE *)&this->g + 107) = v10;
  *((_BYTE *)&this->g + 106) = (2 * v7) | v9;
  *((_BYTE *)&this->g + 105) = v8 | v6 & 1;
  if ( fp->Read(this: fp, a2: &this->g.highlightColor, a3: 4u) == 0 )
    goto LABEL_70;
  if ( fp->Read(this: fp, a2: &this->g.modelFade, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.maxVisibleRange, a3: 4u) != 0
    && fp->Read(this: fp, a2: &this->g.fadeVisibilityOver, a3: 4u) != 0
    && (v29 = 0, fp->Read(this: fp, a2: &v29, a3: 1u) != 0)
    && (*((_BYTE *)&this->g + 104) = v29 & 1 | *((_BYTE *)&this->g + 104) & 0xFE,
        idParmBlock::Load(this: &this->gameParmBlock, fp)) )
  {
    idStr::FreeData(this: v30);
    return 1;
  }
  else
  {
LABEL_70:
    idStr::FreeData(this: v30);
    return 0;
  }
}


// ========================================================================
// __unwind$239486
// EA  : 0x827F54D4
// RVA : 0x007F54D4
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_239486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// ?SerializeSnapshot@idRenderModel@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x827F5508
// RVA : 0x007F5508
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SerializeSnapshot(idRenderModel *this, idSerializer *ser, bool serializeParmBlock)
{
  float *p_modelFade; // r28
  double modelFade; // fp31
  idStaticParmBlock<32> *p_gameParmBlock; // r3
  idBitMsg *msg; // r3
  int v10; // r28
  dimShadow_t castDimShadows; // r10
  bool v12; // r28
  idBitMsg *v13; // r3
  bool v14; // r28
  dimShadow_t v15; // r8
  idBitMsg *v16; // r3
  char v17; // r9
  bool v18; // r28
  idBitMsg *v19; // r3
  char v20; // r9
  char v21; // r28
  idBitMsg *v22; // r3
  char v23; // r11
  unsigned __int8 v24; // r28
  idBitMsg *v25; // r3
  char v26; // r9
  char v27; // r28
  idBitMsg *v28; // r3
  char v29; // r10
  bool v30; // r28
  idBitMsg *v31; // r3
  char v32; // r9
  bool v33; // r28
  idBitMsg *v34; // r3
  char v35; // r9
  bool v36; // r28
  idBitMsg *v37; // r3
  char v38; // r9
  bool v39; // r28
  idBitMsg *v40; // r3
  char v41; // r9
  char v42; // r28
  idBitMsg *v43; // r3
  char v44; // r10
  unsigned __int8 v45; // r28
  idBitMsg *v46; // r3
  idRenderModelCommitted *committed; // r11
  idRenderWorldLocal *world; // r10
  idRenderModelCommitted *v49; // r11
  idRenderWorldLocal *v50; // r10
  idFile_BitMsg v51; // [sp+50h] [-70h] BYREF

  p_modelFade = &this->g.modelFade;
  idFile_BitMsg::idFile_BitMsg(this: &v51, msg: ser->msg);
  modelFade = this->g.modelFade;
  idSerializer::SerializeQ<1,8>(this: ser, value: &this->g.modelFade);
  if ( serializeParmBlock )
  {
    p_gameParmBlock = &this->gameParmBlock;
    if ( ser->writing )
      idParmBlock::Save(this: p_gameParmBlock, fp: &v51);
    else
      idParmBlock::Load(this: p_gameParmBlock, fp: &v51);
  }
  else if ( !ser->writing && __fabs((float)((float)modelFade - *p_modelFade)) > 0.0099999998 )
  {
    idRenderModel::SetModelFade(this, v: *p_modelFade);
  }
  idSerializer::Serialize<idMaterial>(this: ser, decl: &this->g.customMaterial);
  idSerializer::Serialize(this: ser, value: &this->g.scale);
  idSerializer::SerializePacked(this: ser, original: &this->g.customSkin);
  idSerializer::SerializePacked(this: ser, original: &this->g.allowSurfaceOnlyInViewID);
  idSerializer::SerializePacked(this: ser, original: &this->g.suppressSurfaceInViewID);
  idSerializer::SerializePacked(this: ser, original: &this->g.suppressShadowInViewID);
  idSerializer::SerializePacked(this: ser, original: &this->g.suppressShadowInLightIndex);
  idSerializer::SerializeUQ<255,16>(this: ser, value: &this->g.fovScale);
  idSerializer::SerializeQ<128,16>(this: ser, value: &this->g.modelDepthHack);
  msg = ser->msg;
  v10 = *((unsigned __int8 *)&this->g + 105) >> 7;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: *((_BYTE *)&this->g + 105) >> 7, numBits: 1);
  else
    LOBYTE(v10) = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  castDimShadows = this->g.castDimShadows;
  *((_BYTE *)&this->g + 105) = ((_BYTE)v10 << 7) | *((_BYTE *)&this->g + 105) & 0x7F;
  v12 = castDimShadows != DIMSHADOW_OFF;
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: castDimShadows != DIMSHADOW_OFF, numBits: 1);
  else
    v12 = (_cntlzw(idBitMsg::ReadBits(this: v13, numBits: 1) - 1) & 0x20) != 0;
  v15 = v12;
  v14 = (*((_BYTE *)&this->g + 105) & 8) != 0;
  this->g.castDimShadows = v15;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: v14, numBits: 1);
  else
    v14 = (_cntlzw(idBitMsg::ReadBits(this: v16, numBits: 1) - 1) & 0x20) != 0;
  v17 = (8 * v14) & 8 | *((_BYTE *)&this->g + 105) & 0xF7;
  *((_BYTE *)&this->g + 105) = v17;
  v18 = (v17 & 4) != 0;
  v19 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v19, value: (v17 & 4) != 0, numBits: 1);
  else
    v18 = (_cntlzw(idBitMsg::ReadBits(this: v19, numBits: 1) - 1) & 0x20) != 0;
  v20 = (4 * v18) & 4 | *((_BYTE *)&this->g + 105) & 0xFB;
  *((_BYTE *)&this->g + 105) = v20;
  v21 = v20 & 1;
  v22 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v22, value: v20 & 1, numBits: 1);
  else
    v21 = (_cntlzw(idBitMsg::ReadBits(this: v22, numBits: 1) - 1) & 0x20) != 0;
  v23 = v21 & 1 | *((_BYTE *)&this->g + 105) & 0xFE;
  v24 = (*((_BYTE *)&this->g + 106) & 0x40) != 0;
  *((_BYTE *)&this->g + 105) = v23;
  v25 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v25, value: v24, numBits: 1);
  else
    v24 = (_cntlzw(idBitMsg::ReadBits(this: v25, numBits: 1) - 1) & 0x20) != 0;
  v26 = (v24 << 6) & 0x40 | *((_BYTE *)&this->g + 106) & 0xBF;
  *((_BYTE *)&this->g + 106) = v26;
  v27 = v26 < 0;
  v28 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v28, value: v26 < 0, numBits: 1);
  else
    v27 = (_cntlzw(idBitMsg::ReadBits(this: v28, numBits: 1) - 1) & 0x20) != 0;
  v29 = (v27 << 7) | *((_BYTE *)&this->g + 106) & 0x7F;
  *((_BYTE *)&this->g + 106) = v29;
  v30 = (v29 & 0x10) != 0;
  v31 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v31, value: (v29 & 0x10) != 0, numBits: 1);
  else
    v30 = (_cntlzw(idBitMsg::ReadBits(this: v31, numBits: 1) - 1) & 0x20) != 0;
  v32 = (16 * v30) & 0x10 | *((_BYTE *)&this->g + 106) & 0xEF;
  *((_BYTE *)&this->g + 106) = v32;
  v33 = (v32 & 8) != 0;
  v34 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v34, value: (v32 & 8) != 0, numBits: 1);
  else
    v33 = (_cntlzw(idBitMsg::ReadBits(this: v34, numBits: 1) - 1) & 0x20) != 0;
  v35 = (8 * v33) & 8 | *((_BYTE *)&this->g + 106) & 0xF7;
  *((_BYTE *)&this->g + 106) = v35;
  v36 = (v35 & 4) != 0;
  v37 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v37, value: (v35 & 4) != 0, numBits: 1);
  else
    v36 = (_cntlzw(idBitMsg::ReadBits(this: v37, numBits: 1) - 1) & 0x20) != 0;
  v38 = (4 * v36) & 4 | *((_BYTE *)&this->g + 106) & 0xFB;
  *((_BYTE *)&this->g + 106) = v38;
  v39 = (v38 & 2) != 0;
  v40 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v40, value: (v38 & 2) != 0, numBits: 1);
  else
    v39 = (_cntlzw(idBitMsg::ReadBits(this: v40, numBits: 1) - 1) & 0x20) != 0;
  v41 = (2 * v39) & 2 | *((_BYTE *)&this->g + 106) & 0xFD;
  *((_BYTE *)&this->g + 106) = v41;
  v42 = v41 & 1;
  v43 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v43, value: v41 & 1, numBits: 1);
  else
    v42 = (_cntlzw(idBitMsg::ReadBits(this: v43, numBits: 1) - 1) & 0x20) != 0;
  v44 = *((_BYTE *)&this->g + 106) & 0xFE | v42 & 1;
  v45 = *((_BYTE *)&this->g + 104) & 1;
  *((_BYTE *)&this->g + 106) = v44;
  v46 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v46, value: v45, numBits: 1);
  else
    v45 = (_cntlzw(idBitMsg::ReadBits(this: v46, numBits: 1) - 1) & 0x20) != 0;
  *((_BYTE *)&this->g + 104) = *((_BYTE *)&this->g + 104) & 0xFE | v45 & 1;
  if ( ser->writing )
  {
    this->unlinked = idSerializer::SerializeBoolNonRef(this: ser, value: this->unlinked);
  }
  else if ( idSerializer::SerializeBoolNonRef(this: ser, value: 0) )
  {
    if ( !this->unlinked )
    {
      committed = this->committed;
      this->unlinked = false;
      world = committed->world;
      if ( world != nullptr )
        world->commitModels.ptr[committed->index.index >> 8] = true;
      this->unlinked = true;
    }
  }
  else
  {
    v49 = this->committed;
    this->unlinked = false;
    v50 = v49->world;
    if ( v50 != nullptr )
      v50->commitModels.ptr[v49->index.index >> 8] = true;
  }
  idFile_BitMsg::~idFile_BitMsg(this: &v51);
}


// ========================================================================
// __unwind$239981
// EA  : 0x827F5AA8
// RVA : 0x007F5AA8
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_239981()
{
  int v0; // r12

  idFile_BitMsg::~idFile_BitMsg(this: (idFile_BitMsg *)(v0 - 192 + 80));
}


// ========================================================================
// ?RemoveDecal@idRenderModel@@UAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@@Z
// EA  : 0x827F5AD0
// RVA : 0x007F5AD0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

unsigned int __fastcall idRenderModel::RemoveDecal(
        idRenderModel *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle)
{
  int num; // r27
  int v5; // r29
  int v6; // r30
  idRenderModelDecal *decalRenderModel; // r3
  idRenderModel::decalData_t *list; // r4
  int v10; // r9
  int v11; // r4
  idRenderModel::decalData_t *v12; // r10
  idStaticList<idRenderModel::decalData_t,16> *p_decalData; // r3
  int i; // r11
  idRenderModelDecal *v15; // r3

  if ( decalHandle == (const idHandle<int,enum invalidDecalHandle_t,-1> *)-1 )
  {
    num = this->decalData.num;
    v5 = 0;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        decalRenderModel = this->committed->world->decalRenderModel;
        decalRenderModel->RemoveDecal(
          this: decalRenderModel,
          a2: (const idHandle<int,enum invalidDecalHandle_t,-1> *)this->decalData.list[v6].handle.value);
        ++v5;
        ++v6;
      }
      while ( v5 < this->decalData.num );
    }
    if ( this->decalData.listStatic == 0 || this->decalData.listStatic == 2 )
    {
      list = this->decalData.list;
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      this->decalData.list = nullptr;
      this->decalData.size = 0;
    }
    this->decalData.num = 0;
    return (-num & (unsigned int)~num) >> 31;
  }
  else
  {
    v10 = this->decalData.num;
    v11 = 0;
    if ( v10 <= 0 )
    {
      return 0;
    }
    else
    {
      v12 = this->decalData.list;
      p_decalData = &this->decalData;
      for ( i = 0; (const idHandle<int,enum invalidDecalHandle_t,-1> *)v12[i].handle.value != decalHandle; ++i )
      {
        if ( ++v11 >= v10 )
          return 0;
      }
      idList<idRenderModel::decalData_t,5>::RemoveIndexFast(this: p_decalData, index: v11);
      v15 = this->committed->world->decalRenderModel;
      v15->RemoveDecal(this: v15, a2: decalHandle);
      return 1;
    }
  }
}


// ========================================================================
// ??0idRenderModel@@IAA@XZ
// EA  : 0x827F5DA0
// RVA : 0x007F5DA0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

idRenderModel *__fastcall idRenderModel::idRenderModel(idRenderModel *this)
{
  idAtomicString *p_name; // r25
  int v2; // ctr
  float *p_y; // r11
  float *p_z; // r10
  idRenderModelCommitted **p_committed; // r10
  idSysMutex *p_viewNoteMutex; // r11
  int i; // ctr
  __int16 *p_granularity; // r11
  int v10; // ctr
  idRenderModelCommitted *v11; // r3
  idRenderModelCommitted *v12; // r3

  this->__vftable = (idRenderModel_vtbl *)&idRenderModel::`vftable';
  p_name = &this->name;
  this->name.str = &byte_8200D768;
  this->debugName = nullptr;
  v2 = 9;
  this->deferredOrigin.x = 0.0;
  this->deferredOrigin.y = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->deferredOrigin.z = 0.0;
  p_z = &this->deferredOrigin.z;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->useDeferredPosition = false;
  this->deferredPositionInitialized = false;
  this->deleteOnSync = false;
  this->nextOnCommitList = nullptr;
  this->unlinked = true;
  this->needWriteToSnapshot = true;
  p_committed = &this->committed;
  this->needCommitFrameNum = -1;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  for ( i = 6; i != 0; --i )
  {
    ++p_viewNoteMutex;
    *++p_committed = (idRenderModelCommitted *)p_viewNoteMutex->handle;
  }
  idRenderModelParms::idRenderModelParms(this: &this->g);
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->gameParmBlock, threadId: THREAD_MAIN);
  this->surfaces.list = nullptr;
  this->surfaces.granularity = 0;
  this->surfaces.memTag = 85;
  this->surfaces.listStatic = 0;
  this->surfaces.size = 0;
  this->surfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  this->decalData.num = 0;
  this->decalData.granularity = 1;
  this->decalData.list = this->decalData.staticList;
  p_granularity = &this->decalData.granularity;
  this->decalData.size = 16;
  this->decalData.memTag = 5;
  v10 = 16;
  this->decalData.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = -1;
    p_granularity += 28;
    *p_granularity = -1;
    --v10;
  }
  while ( v10 != 0 );
  v11 = (idRenderModelCommitted *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x5D0u,
                                    tag: TAG_RENDERMODEL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
    v12 = idRenderModelCommitted::idRenderModelCommitted(this: v11);
  else
    v12 = nullptr;
  this->committed = v12;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->decalData);
  idAtomicString::Set(this: p_name, str_: "<unnamed>");
  this->committed->name = p_name->str;
  return this;
}


// ========================================================================
// __unwind$240593_0
// EA  : 0x827F5F58
// RVA : 0x007F5F58
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_240593_0()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 160 + 180) + 288));
}


// ========================================================================
// __unwind$240594_0
// EA  : 0x827F5F84
// RVA : 0x007F5F84
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_240594_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1104));
}


// ========================================================================
// __unwind$240595_0
// EA  : 0x827F5FB0
// RVA : 0x007F5FB0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_240595_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1120));
}


// ========================================================================
// __unwind$240596_0
// EA  : 0x827F5FDC
// RVA : 0x007F5FDC
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void _unwind_240596_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?AddSurface@idRenderModel@@QAAXVidRenderModelSurface@@@Z
// EA  : 0x827F6258
// RVA : 0x007F6258
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModel::AddSurface(
        idRenderModel *this,
        idRenderModelSurface *surf,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  __int64 *v15; // r4
  idList<idRenderModelSurface,85> *v16; // r3

  a9 = *(_QWORD *)&surf;
  v15 = &a9;
  a10 = *(__int64 *)((char *)&a3 + 4);
  a11 = a3;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  idList<idRenderModelSurface,62>::Append(this: v16 + 69, obj: (const idRenderModelSurface *)&a9);
}


// ========================================================================
// ?CommitSurfaces@idRenderModel@@IAAXXZ
// EA  : 0x827F62A0
// RVA : 0x007F62A0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::CommitSurfaces(idRenderModel *this)
{
  idRenderModelCommitted *committed; // r11
  int num; // r30
  idList<idRenderModelSurface,85> *p_surfaces; // r29
  int size; // r11
  int v6; // r8
  int v7; // r9
  idRenderModelSurface *v8; // r11
  idRenderModelSurface *v9; // r10

  committed = this->committed;
  num = this->surfaces.num;
  p_surfaces = (idList<idRenderModelSurface,85> *)&committed->surfaces;
  if ( num <= committed->surfaces.size
    || (unsigned __int8)idList<idRenderModelSurface,85>::Resize(this: p_surfaces, newsize: this->surfaces.num) != 0 )
  {
    size = p_surfaces->size;
    if ( num < size )
      size = num;
    p_surfaces->num = size;
  }
  v6 = 0;
  if ( this->surfaces.num > 0 )
  {
    v7 = 0;
    do
    {
      ++v6;
      v8 = &this->surfaces.list[v7];
      v9 = &this->committed->surfaces.list[v7++];
      v9->material = v8->material;
      v9->materialNum = v8->materialNum;
      v9->extraGLState = v8->extraGLState;
      v9->geometry = v8->geometry;
      v9->geometryIsReference = v8->geometryIsReference;
      v9->referenceMask = v8->referenceMask;
      v9->binaryModelId = v8->binaryModelId;
      v9->joints = v8->joints;
      v9->morphMap = v8->morphMap;
      v9->stMap = v8->stMap;
      v9->skinOffsets.x = v8->skinOffsets.x;
      v9->skinOffsets.y = v8->skinOffsets.y;
      v9->skinOffsets.z = v8->skinOffsets.z;
      v9->skinOffsets.w = v8->skinOffsets.w;
    }
    while ( v6 < this->surfaces.num );
  }
  idRenderModelCommitted::SetFlagsFromSurfaces(this: this->committed);
}


// ========================================================================
// ?AddDecalFromPoint@idRenderModel@@UAA?AV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@PBUdecalParams_t@@HABVidVec3@@1V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x827F63B0
// RVA : 0x007F63B0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

idRenderModel *__fastcall idRenderModel::AddDecalFromPoint(
        idRenderModel *this,
        idRenderModel *result,
        const decalParams_t *decalParms,
        int startTime,
        const idVec3 *pos,
        const idVec3 *dir,
        idIndex<short,enum invalidJointIndex_t> *jointId)
{
  int value; // r11
  idRenderModel::decalData_t v11; // [sp+50h] [-50h] BYREF

  value = -1;
  if ( result->decalData.num < result->decalData.size )
  {
    v11.handle.value = -1;
    v11.jointId.value = -1;
    idRenderModel::InitDecalData(this: result, decal: &v11, decalParms, startTime, pos, dir);
    if ( v11.handle.value != -1 )
      idList<idRenderModel::decalData_t,5>::Append(this: &result->decalData, obj: &v11);
    value = v11.handle.value;
  }
  this->__vftable = (idRenderModel_vtbl *)value;
  return this;
}


// ========================================================================
// ?Commit@idRenderModel@@AAAXXZ
// EA  : 0x827F6430
// RVA : 0x007F6430
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::Commit(idRenderModel *this)
{
  idRenderModelCommitted *committed; // r30
  char v3; // r26
  const char *v4; // r6
  idRenderModelCommitted *v5; // r11
  idRenderModel *referenceModel; // r10
  idRenderModelCommitted *v7; // r10
  float *v8; // r11
  float *v9; // r8
  float *p_referenceBounds; // r11
  idRenderModelCommitted *v11; // r11

  if ( r_skipCommits.valueInteger == 0 )
  {
    ++tr.pc.c_modelCommits;
    if ( r_showCommits.valueInteger > 1 )
      idLib::Printf(fmt: "model commit: index %i, %s\n", this->committed->index.index >> 8, this->name.str);
    committed = this->committed;
    v3 = ((_cntlzw((unsigned __int8)CompareEqualMat3(a: &this->g.axis, b: &committed->r.axis)) & 0x20) != 0)
       | ((_cntlzw(
             ((_cntlzw(
                 LODWORD(this->referenceBounds.b[0].z) ^ LODWORD(committed->referenceBounds.b[0].z)
               | LODWORD(this->referenceBounds.b[0].y) ^ LODWORD(committed->referenceBounds.b[0].y)
               | LODWORD(this->referenceBounds.b[0].x) ^ LODWORD(committed->referenceBounds.b[0].x))
             & 0x20) != 0)
           & ((_cntlzw(
                 LODWORD(this->referenceBounds.b[1].z) ^ LODWORD(committed->referenceBounds.b[1].z)
               | LODWORD(this->referenceBounds.b[1].y) ^ LODWORD(committed->referenceBounds.b[1].y)
               | LODWORD(this->referenceBounds.b[1].x) ^ LODWORD(committed->referenceBounds.b[1].x))
             & 0x20) != 0))
         & 0x20) != 0)
       | ((LODWORD(this->g.scale.z) ^ LODWORD(committed->r.scale.z)
         | LODWORD(this->g.scale.y) ^ LODWORD(committed->r.scale.y)
         | LODWORD(this->g.scale.x) ^ LODWORD(committed->r.scale.x)) != 0)
       | ((LODWORD(committed->r.origin.y) ^ LODWORD(this->g.origin.y)
         | LODWORD(committed->r.origin.z) ^ LODWORD(this->g.origin.z)
         | LODWORD(this->g.origin.x) ^ LODWORD(committed->r.origin.x)) != 0)
       | ((_cntlzw(committed->references.num) & 0x20) != 0)
       | (r_forceReferencesOnCommit.valueInteger != 0);
    if ( r_showReferenceUpdates.valueInteger != 0 )
    {
      if ( v3 != 0 )
        v4 = "TRUE";
      else
        v4 = "FALSE";
      idLib::Printf(fmt: "updating references for %s (%d): %s\n", this->name.str, committed->index.index >> 8, v4);
    }
    idStaticParmBlock<32>::operator=(this: &this->committed->renderParmBlock, __that: &this->gameParmBlock);
    idRenderModelParms::operator=(this: &this->committed->r, __that: &this->g);
    v5 = this->committed;
    referenceModel = v5->r.referenceModel;
    if ( referenceModel != nullptr )
      v7 = referenceModel->committed;
    else
      v7 = nullptr;
    v5->referenceModel = v7;
    this->committed->guiFrameCount = idRenderModelGui::frameCount;
    idRenderMatrix::FromOriginAxisScale(
      origin: &this->committed->r.origin,
      axis: &this->committed->r.axis,
      scale: &this->committed->r.scale,
      out: &this->committed->modelMatrix);
    if ( !idRenderMatrix::Inverse(src: &this->committed->modelMatrix, out: &this->committed->inverseModelMatrix) )
    {
      idLib::Warning(fmt: "modelMatrix invert failed on model %s", this->name.str);
      v8 = (float *)this->committed;
      v8[20] = 1.0;
      v8[16] = 1.0;
      v8[12] = 1.0;
      v8[17] = 0.0;
      v8[14] = 0.0;
      v8[13] = 0.0;
      v8[19] = 0.0;
      v8[18] = 0.0;
      v8[15] = 0.0;
      v9 = (float *)this->committed;
      v9[282] = v9[12];
      v9[283] = v9[15];
      v9[284] = v9[18];
      v9[285] = v9[9];
      v9[286] = v9[13];
      v9[287] = v9[16];
      v9[288] = v9[19];
      v9[289] = v9[10];
      v9[290] = v9[14];
      v9[291] = v9[17];
      v9[292] = v9[20];
      v9[293] = v9[11];
      v9[294] = 0.0;
      v9[295] = 0.0;
      v9[296] = 0.0;
      v9[297] = 1.0;
      idRenderMatrix::Inverse(src: &this->committed->modelMatrix, out: &this->committed->inverseModelMatrix);
    }
    if ( this->CommitSubclass(this) )
      v3 = 1;
    if ( this->useDeferredPosition )
    {
      this->g.origin.x = this->deferredOrigin.x;
      this->g.origin.y = this->deferredOrigin.y;
      this->g.origin.z = this->deferredOrigin.z;
      this->g.axis.mat[0].x = this->deferredAxis.mat[0].x;
      this->g.axis.mat[0].y = this->deferredAxis.mat[0].y;
      this->g.axis.mat[0].z = this->deferredAxis.mat[0].z;
      this->g.axis.mat[1].x = this->deferredAxis.mat[1].x;
      this->g.axis.mat[1].y = this->deferredAxis.mat[1].y;
      this->g.axis.mat[1].z = this->deferredAxis.mat[1].z;
      this->g.axis.mat[2].x = this->deferredAxis.mat[2].x;
      this->g.axis.mat[2].y = this->deferredAxis.mat[2].y;
      this->g.axis.mat[2].z = this->deferredAxis.mat[2].z;
    }
    this->deferredPositionInitialized = true;
    idRenderModel::CommitSurfaces(this);
    p_referenceBounds = (float *)&this->committed->referenceBounds;
    *p_referenceBounds = this->referenceBounds.b[0].x;
    p_referenceBounds[1] = this->referenceBounds.b[0].y;
    p_referenceBounds[2] = this->referenceBounds.b[0].z;
    p_referenceBounds[3] = this->referenceBounds.b[1].x;
    p_referenceBounds[4] = this->referenceBounds.b[1].y;
    p_referenceBounds[5] = this->referenceBounds.b[1].z;
    if ( r_checkBounds.valueInteger != 0 )
      idRenderModelCommitted::CheckBounds(this: this->committed);
    v11 = this->committed;
    if ( v11->world != nullptr && (*((_BYTE *)&v11->r + 104) & 0x10) == 0 )
    {
      *((_BYTE *)v11 + 1416) = (v3 << 6) & 0x40 | *((_BYTE *)v11 + 1416) & 0xBF;
      this->committed->world->postCommitModels.ptr[this->committed->index.index >> 8] = true;
    }
  }
}


// ========================================================================
// ?SetMaxSurfaces@idRenderModel@@QAAXH@Z
// EA  : 0x827F68C0
// RVA : 0x007F68C0
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __fastcall idRenderModel::SetMaxSurfaces(idRenderModel *this, int max)
{
  idList<idRenderModelSurface,85> *p_surfaces; // r31
  idRenderModelCommitted *committed; // r11
  idList<idRenderModelSurface,85> *v6; // r31

  p_surfaces = &this->surfaces;
  if ( max > this->surfaces.size )
    idList<idRenderModelSurface,85>::Resize(this: &this->surfaces, newsize: max);
  p_surfaces->listStatic = 2;
  committed = this->committed;
  v6 = (idList<idRenderModelSurface,85> *)&committed->surfaces;
  if ( max > committed->surfaces.size )
    idList<idRenderModelSurface,85>::Resize(this: v6, newsize: max);
  v6->listStatic = 2;
}


// ========================================================================
// `dynamic initializer for 'r_forceReferencesOnCommit''
// EA  : 0x83343708
// RVA : 0x01343708
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceReferencesOnCommit__()
{
  idCVar::idCVar(
    this: &r_forceReferencesOnCommit,
    name: "r_forceReferencesOnCommit",
    value: "0",
    flags: 1,
    description: "Never skip the reference update",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceReferencesOnCommit__);
}


// ========================================================================
// `dynamic initializer for 'r_showReferenceUpdates''
// EA  : 0x83343760
// RVA : 0x01343760
// PDB : w:\tech5\engine\models\rendermodel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showReferenceUpdates__()
{
  idCVar::idCVar(
    this: &r_showReferenceUpdates,
    name: "r_showReferenceUpdates",
    value: "0",
    flags: 1,
    description: "show rendermodels which have their references updated",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showReferenceUpdates__);
}

