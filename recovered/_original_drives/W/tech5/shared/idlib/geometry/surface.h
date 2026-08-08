
// ========================================================================
// ?GetBounds@idSurface@@QBAXAAVidBounds@@@Z
// EA  : 0x825C74D0
// RVA : 0x005C74D0
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void __fastcall idSurface::GetBounds(idSurface *this, idBounds *bounds)
{
  int v2; // r10
  int v3; // r9
  double y; // fp13
  idDrawVert *v5; // r11
  double z; // fp12
  double x; // fp11
  double v8; // fp10
  double v9; // fp9

  v2 = 0;
  bounds->b[0].z = 1.0e30;
  bounds->b[0].y = 1.0e30;
  bounds->b[0].x = 1.0e30;
  bounds->b[1].z = -1.0e30;
  bounds->b[1].y = -1.0e30;
  bounds->b[1].x = -1.0e30;
  if ( this->verts.num > 0 )
  {
    v3 = 0;
    do
    {
      y = bounds->b[0].y;
      ++v2;
      v5 = &this->verts.list[v3];
      z = bounds->b[0].z;
      x = bounds->b[1].x;
      ++v3;
      v8 = bounds->b[1].y;
      v9 = bounds->b[1].z;
      _FP7 = (float)(bounds->b[0].x - v5->xyz.x);
      __asm { fsel      f6, f7, f8, f0 }
      bounds->b[0].x = _FP6;
      _FP4 = (float)((float)y - v5->xyz.y);
      __asm { fsel      f3, f4, f5, f13 }
      bounds->b[0].y = _FP3;
      _FP1 = (float)((float)z - v5->xyz.z);
      __asm { fsel      f0, f1, f2, f12 }
      bounds->b[0].z = _FP0;
      _FP12 = (float)(v5->xyz.x - (float)x);
      __asm { fsel      f11, f12, f13, f11 }
      bounds->b[1].x = _FP11;
      _FP7 = (float)(v5->xyz.y - (float)v8);
      __asm { fsel      f6, f7, f8, f10 }
      bounds->b[1].y = _FP6;
      _FP4 = (float)(v5->xyz.z - (float)v9);
      __asm { fsel      f3, f4, f5, f9 }
      bounds->b[1].z = _FP3;
    }
    while ( v2 < this->verts.num );
  }
}


// ========================================================================
// ??0idSurface@@QAA@XZ
// EA  : 0x825CD3E8
// RVA : 0x005CD3E8
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

idSurface *__fastcall idSurface::idSurface(idSurface *this)
{
  this->verts.list = nullptr;
  this->verts.granularity = 0;
  this->verts.memTag = 44;
  this->verts.listStatic = 0;
  this->verts.size = 0;
  this->verts.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->indexes.list = nullptr;
  this->indexes.granularity = 0;
  this->indexes.memTag = 44;
  this->indexes.listStatic = 0;
  this->indexes.size = 0;
  this->indexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexes);
  this->edges.list = nullptr;
  this->edges.granularity = 0;
  this->edges.memTag = 44;
  this->edges.listStatic = 0;
  this->edges.size = 0;
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  this->edgeIndexes.list = nullptr;
  this->edgeIndexes.granularity = 0;
  this->edgeIndexes.memTag = 44;
  this->edgeIndexes.listStatic = 0;
  this->edgeIndexes.size = 0;
  this->edgeIndexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgeIndexes);
  return this;
}


// ========================================================================
// __unwind$244454
// EA  : 0x825CD490
// RVA : 0x005CD490
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_244454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$244455
// EA  : 0x825CD4B8
// RVA : 0x005CD4B8
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_244455()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$244456
// EA  : 0x825CD4E4
// RVA : 0x005CD4E4
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_244456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// ??1idSurface@@QAA@XZ
// EA  : 0x825CD518
// RVA : 0x005CD518
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void __fastcall idSurface::~idSurface(splineMoverModifier_t::splineMoverModifierSound_t *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->volume);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pitch);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stopSounds);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$687931
// EA  : 0x825CD570
// RVA : 0x005CD570
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_687931()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$687932
// EA  : 0x825CD598
// RVA : 0x005CD598
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_687932()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$687933
// EA  : 0x825CD5C4
// RVA : 0x005CD5C4
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void _unwind_687933()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// ?TranslateSelf@idSurface@@QAAXABVidVec3@@@Z
// EA  : 0x8279F720
// RVA : 0x0079F720
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void __fastcall idSurface::TranslateSelf(idSurface *this, const idVec3 *translation)
{
  int v2; // r10
  int v3; // r9
  idDrawVert *v4; // r11
  double y; // fp11
  double z; // fp8

  v2 = 0;
  if ( this->verts.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = &this->verts.list[v3++];
      y = v4->xyz.y;
      v4->xyz.x = v4->xyz.x + translation->x;
      z = v4->xyz.z;
      v4->xyz.y = translation->y + (float)y;
      v4->xyz.z = translation->z + (float)z;
    }
    while ( v2 < this->verts.num );
  }
}


// ========================================================================
// ?RotateSelf@idSurface@@QAAXABVidMat3@@@Z
// EA  : 0x8279F788
// RVA : 0x0079F788
// PDB : w:\tech5\shared\idlib\geometry\surface.h
// ========================================================================

void __fastcall idSurface::RotateSelf(idSurface *this, const idMat3 *rotation, float *_R5, int a4, __int64 _R8)
{
  int v8; // r19
  idVec3 *v9; // r29
  idVec3 *v10; // r28
  float *p_y; // r27
  float *v12; // r26
  float *v13; // r25
  float *p_z; // r24
  float *v15; // r23
  float *v16; // r22
  int v17; // r31
  idDrawVert *v23; // r11
  double x; // fp3
  double v25; // fp1
  double v26; // fp0
  double v27; // fp12
  double v28; // fp11
  idDrawVert *v29; // r21
  const idVec3 *Normal; // r3
  double y; // fp2
  double v34; // fp0
  double v37; // fp7
  double v38; // fp8
  double v40; // fp6
  double v41; // fp4
  idDrawVert *v42; // r21
  int v43; // r5
  const idVec3 *Tangent; // r3
  double z; // fp9
  double v48; // fp0
  double v50; // fp11
  double v51; // fp6
  int *p_num; // [sp+50h] [-100h]
  float v54; // [sp+58h] [-F8h] BYREF
  float v55; // [sp+5Ch] [-F4h] BYREF
  float v56; // [sp+60h] [-F0h] BYREF
  float v57; // [sp+68h] [-E8h] BYREF
  float v58; // [sp+6Ch] [-E4h] BYREF
  float v59; // [sp+70h] [-E0h] BYREF
  idDrawVert v60[6]; // [sp+78h] [-D8h] BYREF

  _R12 = -176;
  __asm { stvx128   v127, r1, r12 }
  p_num = &this->verts.num;
  v8 = 0;
  if ( this->verts.num > 0 )
  {
    __asm { vspltisw128 v127, 0 }
    v9 = &rotation->mat[2];
    v10 = &rotation->mat[1];
    p_y = &rotation->mat[2].y;
    v12 = &rotation->mat[1].y;
    v13 = &rotation->mat[0].y;
    p_z = &rotation->mat[2].z;
    v15 = &rotation->mat[1].z;
    v16 = &rotation->mat[0].z;
    v17 = 0;
    _R14 = 1;
    _R15 = 2;
    _R18 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R17 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R16 = &_vmx_3f8000003f8000003f8000003f800000;
    do
    {
      v23 = &this->verts.list[v17];
      x = v23->xyz.x;
      v25 = *v13;
      v26 = *v16;
      v27 = (float)((float)(v23->xyz.y * *v12) + (float)(v23->xyz.z * *p_y));
      v28 = (float)((float)(*v15 * v23->xyz.y) + (float)(*p_z * v23->xyz.z));
      v23->xyz.x = (float)(v23->xyz.y * v10->x)
                 + (float)((float)(v23->xyz.x * rotation->mat[0].x) + (float)(v23->xyz.z * v9->x));
      v23->xyz.y = (float)((float)v25 * (float)x) + (float)v27;
      v23->xyz.z = (float)((float)x * (float)v26) + (float)v28;
      v29 = &this->verts.list[v17];
      Normal = idDrawVert::GetNormal(this: v60, result: &v29->xyz, a3: (int)_R5, a4: _R8);
      y = Normal->y;
      _R10 = &v55;
      _R9 = &v56;
      v34 = Normal->x;
      LODWORD(_R8) = &v54;
      __asm { vmr128    v62, v127 }
      _R11 = v29->normal;
      v37 = *v16;
      v38 = *v12;
      __asm { lvx128    v63, r0, r16 }
      __asm { lvx128    v0, r0, r17 }
      v40 = (float)((float)(*v15 * Normal->y) + (float)(*p_z * Normal->z));
      __asm { lvx128    v13, r0, r18 }
      v41 = (float)((float)(Normal->z * *p_y) + (float)(Normal->x * *v13));
      v54 = (float)(Normal->x * rotation->mat[0].x) + (float)((float)(Normal->z * v9->x) + (float)(Normal->y * v10->x));
      v56 = (float)((float)v34 * (float)v37) + (float)v40;
      v55 = (float)((float)y * (float)v38) + (float)v41;
      __asm
      {
        lvlx128   v61, r0, r10
        lvlx128   v60, r0, r9
        lvlx128   v59, r0, r8
        vrlimi128 v62, v59, 8, 0
        vrlimi128 v62, v61, 4, 3
        vrlimi128 v62, v60, 2, 2
        vaddfp128 v12, v94, v63
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v58, v0, 0
        vpkswss128 v57, v90, v58
        vpkshus128 v0, v89, v57
        stvebx    v0, 0, r11
        stvebx    v0, r11, r14
        stvebx    v0, r11, r15
      }
      v42 = &this->verts.list[v17];
      Tangent = idDrawVert::GetTangent(this: (idDrawVert *)&v60[0].st.y, result: &v42->xyz, a3: v43, a4: _R8);
      z = Tangent->z;
      HIDWORD(_R8) = &v58;
      _R6 = &v59;
      _R5 = &v57;
      __asm { vmr128    v56, v127 }
      _R11 = v42->tangent;
      ++v8;
      v48 = *p_y;
      ++v17;
      __asm
      {
        lvx128    v63, r0, r16
        lvx128    v0, r0, r17
        lvx128    v13, r0, r18
      }
      v50 = (float)((float)(Tangent->x * *v13) + (float)(Tangent->y * *v12));
      v51 = (float)((float)(Tangent->z * v9->x)
                  + (float)((float)(Tangent->y * v10->x) + (float)(Tangent->x * rotation->mat[0].x)));
      v59 = (float)(Tangent->x * *v16) + (float)((float)(*v15 * Tangent->y) + (float)(*p_z * Tangent->z));
      v57 = v51;
      v58 = (float)((float)z * (float)v48) + (float)v50;
      __asm
      {
        lvlx128   v55, r0, r7
        lvlx128   v54, r0, r6
        lvlx128   v53, r0, r5
        vrlimi128 v56, v53, 8, 0
        vrlimi128 v56, v55, 4, 3
        vrlimi128 v56, v54, 2, 2
        vaddfp128 v12, v88, v63
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v52, v0, 0
        vpkswss128 v51, v84, v52
        vpkshus128 v0, v83, v51
        stvebx    v0, 0, r11
        stvebx    v0, r11, r14
        stvebx    v0, r11, r15
      }
    }
    while ( v8 < *p_num );
  }
  _R0 = -176;
  __asm { lvx128    v127, r1, r0 }
}

