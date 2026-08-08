
// ========================================================================
// ?Save@idRenderModelCuttableSurface@@UBAXPAVidFile@@@Z
// EA  : 0x827C88F8
// RVA : 0x007C88F8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

void __fastcall idRenderModelCuttableSurface::Save(idRenderModelCuttableSurface *this, idFile *fp)
{
  idRenderModel::Save(this, fp);
  fp->Write(this: fp, a2: &this->bufferIndex, a3: 4u);
}


// ========================================================================
// ?Load@idRenderModelCuttableSurface@@UAA_NPAVidFile@@@Z
// EA  : 0x827C8A00
// RVA : 0x007C8A00
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

BOOL __fastcall idRenderModelCuttableSurface::Load(idRenderModelCuttableSurface *this, idFile *fp)
{
  return idRenderModel::Load(this, fp) && fp->Read(this: fp, a2: &this->bufferIndex, a3: 4u) != 0;
}


// ========================================================================
// ?UpdateGeometry@idRenderModelCuttableSurface@@QAAHHABVidVertexBuffer@@0ABVidIndexBuffer@@HH@Z
// EA  : 0x827C8A70
// RVA : 0x007C8A70
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

int __fastcall idRenderModelCuttableSurface::UpdateGeometry(
        idRenderModelCuttableSurface *this,
        int bufferIndex_,
        const idVertexBuffer *vertexBuffer,
        const idVertexBuffer *stBuffer,
        const idIndexBuffer *indexBuffer,
        int numVertices,
        int numIndices)
{
  int num; // r11
  int bufferIndex; // r22
  int v15; // r26
  int v16; // r29
  idRenderModelSurface *v17; // r31
  idTriangles *geometry; // r3
  idVertexBuffer *stMap; // r3

  num = this->surfaces.num;
  bufferIndex = this->bufferIndex;
  this->bufferIndex = bufferIndex_;
  v15 = 0;
  if ( num > 0 )
  {
    v16 = 0;
    do
    {
      v17 = &this->surfaces.list[v16];
      if ( v17 != nullptr )
      {
        geometry = v17->geometry;
        if ( geometry != nullptr )
        {
          idTriangles::FreeCPUData(this: geometry);
          idVertexBuffer::Reference(this: &v17->geometry->vertexBuffer, other: vertexBuffer);
          idIndexBuffer::Reference(this: &v17->geometry->indexBuffer, other: indexBuffer);
          stMap = v17->stMap;
          if ( stMap != nullptr )
            idVertexBuffer::Reference(this: stMap, other: stBuffer);
          v17->geometry->numVerts = numVertices;
          v17->geometry->numIndexes = numIndices;
        }
      }
      ++v15;
      ++v16;
    }
    while ( v15 < this->surfaces.num );
  }
  return bufferIndex;
}


// ========================================================================
// ?LoadModel@idRenderModelCuttableSurface@@AAA_NPBD@Z
// EA  : 0x827C8B30
// RVA : 0x007C8B30
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

int __fastcall idRenderModelCuttableSurface::LoadModel(idRenderModelCuttableSurface *this, char *modelName)
{
  idRenderModelCuttableResource *v4; // r3

  v4 = (idRenderModelCuttableResource *)idResourceList::Load(
                                          this: &idRenderModelCuttableResource::resourceList,
                                          name: modelName,
                                          makeDefault: false,
                                          skipStaleCheck: false);
  this->modelResource = v4;
  if ( v4 == nullptr )
    idLib::Error(fmt: "idRenderModelCuttableResource - failed to load model '%s'", modelName);
  this->triangleInterpolator = &v4->triangleInterpolator;
  idRenderModelCuttableResource::BuildSurface(this: v4, model: this);
  idRenderModel::FinishSurfaces(this);
  return 1;
}


// ========================================================================
// ??0idRenderModelCuttableSurface@@QAA@PBD@Z
// EA  : 0x827C8BB8
// RVA : 0x007C8BB8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

idRenderModelCuttableSurface *__fastcall idRenderModelCuttableSurface::idRenderModelCuttableSurface(
        idRenderModelCuttableSurface *this,
        char *modelName)
{
  char v4; // r10

  idRenderModel::idRenderModel(this);
  v4 = *((_BYTE *)&this->g + 105);
  this->modelResource = nullptr;
  this->__vftable = (idRenderModelCuttableSurface_vtbl *)&idRenderModelCuttableSurface::`vftable';
  this->triangleInterpolator = nullptr;
  *((_BYTE *)&this->g + 105) = v4 | 0xC0;
  idRenderModel::SetName(this, name_: modelName);
  idRenderModelCuttableSurface::LoadModel(this, modelName);
  return this;
}


// ========================================================================
// __unwind$220752
// EA  : 0x827C8C20
// RVA : 0x007C8C20
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

void _unwind_220752()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// ?BuildGeometry@idRenderModelCuttableSurface@@QBAXPBVContour@@0AAV?$idList@VidDrawVert@@$04@@AAV?$idList@VidVec2@@$04@@AAV?$idList@G$04@@@Z
// EA  : 0x827C8D20
// RVA : 0x007C8D20
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelCuttableSurface::BuildGeometry(
        idRenderModelCuttableSurface *this,
        const Contour *outer,
        const Contour *inner,
        idList<idDrawVert,44> *vtx,
        idList<idVec2,72> *st,
        idList<unsigned short,5> *idx,
        int a7,
        int a8,
        int a9,
        int a10,
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
        idList<unsigned short,5> *a22)
{
  idList<unsigned short,5> *v28; // r28
  __int64 v29; // r8
  int v30; // r5
  __int64 v31; // r8
  int v32; // r5
  int v33; // r14
  int num; // r11
  int *p_size; // r25
  int *v36; // r24
  int v37; // r27
  int v38; // r29
  int v39; // r11
  idDrawVert *v40; // r30
  int v41; // r11
  idVec2 *v42; // r6
  int v48; // r11
  int size; // r10
  idDrawVert *v50; // r30
  int v51; // r2 OVERLAPPED
  int v53; // r11
  int v54; // r10
  idVec2 *v55; // r10
  int v56; // r8
  idDrawVert *v57; // r11
  int v60; // r6
  int v61; // r5
  __int64 v62; // r4
  float *v64; // r11
  double v65; // fp12
  double v66; // fp10
  double v67; // fp8
  double v70; // fp2
  double v72; // fp6
  double v74; // fp2
  double v75; // fp13
  double v76; // fp11
  double v79; // fp5
  double v80; // fp9
  __int128 v81; // r4
  __int64 v82; // r8
  __int64 v83; // r10
  double v84; // fp11
  double v85; // fp12
  double v86; // fp8
  double v87; // fp9
  double v88; // fp1
  __int64 v89; // r6
  double v90; // fp10
  double v91; // fp7
  double v92; // fp6
  double v95; // fp12
  double v96; // fp5
  double v97; // fp2
  char v98; // r11
  double v99; // fp1
  double v100; // fp13
  double v101; // fp3
  double v102; // fp4
  double v103; // fp5
  double v104; // fp7
  double v107; // fp3
  double v108; // fp3
  double v109; // fp10
  double v110; // fp6
  double v111; // fp3
  int v112; // r8
  int v113; // r10
  int v114; // r10
  int v115; // r30
  unsigned int v116; // r29
  _DWORD v118[4]; // [sp+50h] [-230h] BYREF
  idList<idVec2,72> v119; // [sp+60h] [-220h] BYREF
  int v120; // [sp+70h] [-210h]
  idVec2 *p_st; // [sp+74h] [-20Ch]
  float v122; // [sp+78h] [-208h] BYREF
  float v123; // [sp+7Ch] [-204h] BYREF
  float v124; // [sp+80h] [-200h] BYREF
  float v125; // [sp+88h] [-1F8h] BYREF
  float v126; // [sp+8Ch] [-1F4h] BYREF
  _QWORD v127[2]; // [sp+90h] [-1F0h] BYREF
  __int64 v128; // [sp+A0h] [-1E0h]
  __int64 v129; // [sp+A8h] [-1D8h]
  __int64 v130; // [sp+B0h] [-1D0h]
  __int64 v131; // [sp+B8h] [-1C8h]
  __int64 v132; // [sp+C0h] [-1C0h]
  __int64 v133; // [sp+C8h] [-1B8h]
  __int64 v134; // [sp+D0h] [-1B0h]
  __int64 v135; // [sp+D8h] [-1A8h]
  __int64 v136; // [sp+E0h] [-1A0h]
  __int64 v137; // [sp+E8h] [-198h]
  __int64 v138; // [sp+F0h] [-190h]
  idDrawVert v139[7]; // [sp+F8h] [-188h] BYREF

  _R12 = -208;
  __asm { stvx128   v127, r1, r12 }
  a22 = idx;
  v28 = idx;
  idEarClipTriangulate::idEarClipTriangulate(this: (idEarClipTriangulate *)v139[0].tangent);
  idEarClipTriangulate::SetOuterFromContour(this: (idEarClipTriangulate *)v139[0].tangent, outer, a3: v30, a4: v29);
  idEarClipTriangulate::AddInnerFromContour(this: (idEarClipTriangulate *)v139[0].tangent, inner, a3: v32, a4: v31);
  idEarClipTriangulate::Triangulate(this: (idEarClipTriangulate *)v139[0].tangent);
  v33 = 0;
  memset(&v119, 0, 14);
  *(_WORD *)&v119.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v119);
  idEarClipTriangulate::BuildGeometry(
    this: (idEarClipTriangulate *)v139[0].tangent,
    normal: &this->triangleInterpolator->refNormal,
    pos: &v119,
    idx: v28);
  num = v119.num;
  p_size = &vtx->size;
  if ( 2 * v119.num > vtx->size )
  {
    idList<idDrawVert,44>::Resize(this: vtx, newsize: 2 * v119.num);
    num = v119.num;
  }
  v36 = &st->size;
  if ( 2 * num > st->size )
  {
    idList<idVec2,72>::Resize(this: st, newsize: 2 * num);
    num = v119.num;
  }
  v37 = 0;
  if ( num > 0 )
  {
    v38 = 0;
    do
    {
      idList<idDrawVert,5>::PreAllocateWithGranularity(this: (idList<idDrawVert,5> *)vtx, newSize: vtx->num + 1);
      v39 = vtx->num;
      if ( v39 >= *p_size )
      {
        v40 = &vtx->list[*p_size - 1];
      }
      else
      {
        v40 = &vtx->list[v39];
        vtx->num = v39 + 1;
      }
      idList<idVec2,5>::PreAllocateWithGranularity(this: (idList<idVec2,5> *)st, newSize: st->num + 1);
      v41 = st->num;
      if ( v41 >= *v36 )
      {
        v42 = &st->list[*v36 - 1];
      }
      else
      {
        v42 = &st->list[v41];
        st->num = v41 + 1;
      }
      idTriangleInterpolator::Interpolate(
        this: (idTriangleInterpolator *)this->triangleInterpolator,
        point: &v119.list[v38],
        vert: v40,
        st: v42);
      num = v119.num;
      ++v37;
      ++v38;
    }
    while ( v37 < v119.num );
  }
  v120 = 0;
  if ( num > 0 )
  {
    v118[0] = 0;
    __asm { vspltisw128 v127, 0 }
    _R15 = 1;
    _R16 = 2;
    _R19 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R18 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R17 = &_vmx_3f8000003f8000003f8000003f800000;
    do
    {
      idList<idDrawVert,5>::PreAllocateWithGranularity(this: (idList<idDrawVert,5> *)vtx, newSize: vtx->num + 1);
      v48 = vtx->num;
      size = vtx->size;
      if ( v48 >= size )
      {
        v50 = &vtx->list[size - 1];
      }
      else
      {
        v50 = &vtx->list[v48];
        vtx->num = v48 + 1;
      }
      idList<idVec2,5>::PreAllocateWithGranularity(this: (idList<idVec2,5> *)st, newSize: st->num + 1);
      v53 = st->num;
      v54 = st->size;
      if ( v53 >= v54 )
      {
        v55 = &st->list[v54 - 1];
      }
      else
      {
        v55 = &st->list[v53];
        st->num = v53 + 1;
      }
      v56 = v118[0];
      v57 = &vtx->list[v33];
      _R28 = v50->normal;
      p_st = &v57->st;
      _R29 = v50->tangent;
      v50->xyz.x = v57->xyz.x;
      v50->xyz.y = v57->xyz.y;
      v50->xyz.z = v57->xyz.z;
      v50->st.x = v57->st.x;
      v50->st.y = v57->st.y;
      v50->normal[0] = v57->normal[0];
      v50->normal[1] = v57->normal[1];
      v50->normal[2] = v57->normal[2];
      v50->normal[3] = v57->normal[3];
      v50->tangent[0] = v57->tangent[0];
      v50->tangent[1] = v57->tangent[1];
      v60 = v57->tangent[2];
      v50->tangent[2] = v60;
      v61 = v57->tangent[3];
      v50->tangent[3] = v61;
      v50->color[0] = v57->color[0];
      HIDWORD(v62) = v57->color[1];
      v50->color[1] = BYTE3(v62);
      v50->color[2] = v57->color[2];
      DWORD1(_R11) = &v123;
      v50->color[3] = v57->color[3];
      v64 = (float *)((char *)&st->list->x + v56);
      HIDWORD(_R11) = &v124;
      v55->x = *v64;
      v55->y = v64[1];
      LODWORD(v62) = v50->normal[0];
      LODWORD(_R11) = v50->normal[2];
      DWORD2(_R11) = v50->normal[1];
      v131 = v62;
      v132 = _R11;
      v134 = *(_QWORD *)((char *)&_R11 + 4);
      v65 = (float)((float)((float)*(__int64 *)((char *)&_R11 + 4) * (float)0.0078431377) - (float)1.0);
      v66 = (float)((float)((float)v62 * (float)0.0078431377) - (float)1.0);
      v67 = (float)((float)((float)(__int64)_R11 * (float)0.0078431377) - (float)1.0);
      _FP5 = (float)((float)((float)((float)v67 * (float)v67)
                           + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f3, f5, f6, f0 }
      v70 = __frsqrte(_FP3);
      _R7 = &v122;
      __asm
      {
        vmr128    v62, v127
        lvx128    v63, r0, r17
        lvx128    v13, r0, r19
        vmr128    v56, v127
        lvx128    v0, r0, r18
      }
      v72 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70
                                                                                          * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v70)
                                                                          - (float)1.5)
                                                          * (float)v70)
                                                  * (float)((float)((float)((float)v67 * (float)v67)
                                                                  + (float)((float)((float)v66 * (float)v66)
                                                                          + (float)((float)v65 * (float)v65)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v70
                                                                                  * (float)((float)((float)((float)v67 * (float)v67)
                                                                                                  + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65)))
                                                                                          * (float)0.5))
                                                                          * (float)v70)
                                                                  - (float)1.5)
                                                  * (float)v70))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v70
                                                          * (float)((float)((float)((float)v67 * (float)v67)
                                                                          + (float)((float)((float)v66 * (float)v66)
                                                                                  + (float)((float)v65 * (float)v65)))
                                                                  * (float)0.5))
                                                  * (float)v70)
                                          - (float)1.5)
                          * (float)v70));
      v123 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70) * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70)
                                                                                            - (float)1.5)
                                                                            * (float)v70))
                                                            * (float)((float)((float)((float)v67 * (float)v67)
                                                                            + (float)((float)((float)v66 * (float)v66)
                                                                                    + (float)((float)v65 * (float)v65)))
                                                                    * (float)0.5))
                                                    * (float)v72)
                                            - (float)1.5)
                            * (float)v72)
                    * (float)v65);
      v124 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70) * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70)
                                                                                            - (float)1.5)
                                                                            * (float)v70))
                                                            * (float)((float)((float)((float)v67 * (float)v67)
                                                                            + (float)((float)((float)v66 * (float)v66)
                                                                                    + (float)((float)v65 * (float)v65)))
                                                                    * (float)0.5))
                                                    * (float)v72)
                                            - (float)1.5)
                            * (float)v72)
                    * (float)v67);
      v122 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70) * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70) - (float)1.5) * (float)v70))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v67 * (float)v67) + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) * (float)0.5)) * (float)v70)
                                                                                            - (float)1.5)
                                                                            * (float)v70))
                                                            * (float)((float)((float)((float)v67 * (float)v67)
                                                                            + (float)((float)((float)v66 * (float)v66)
                                                                                    + (float)((float)v65 * (float)v65)))
                                                                    * (float)0.5))
                                                    * (float)v72)
                                            - (float)1.5)
                            * (float)v72)
                    * (float)v66);
      __asm { lvlx128   v61, r0, r9 }
      DWORD1(_R11) = &v126;
      __asm { lvlx128   v60, r0, r8 }
      HIDWORD(_R11) = v127;
      __asm
      {
        lvlx128   v59, r0, r7
        vrlimi128 v62, v59, 8, 0
        vrlimi128 v62, v61, 4, 3
      }
      _R7 = &v125;
      __asm
      {
        vrlimi128 v62, v60, 2, 2
        vaddfp128 v12, v94, v63
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v58, v0, 0
        vpkswss128 v57, v90, v58
        vpkshus128 v0, v89, v57
        stvebx    v0, 0, r28
        stvebx    v0, r28, r15
        stvebx    v0, r28, r16
      }
      DWORD2(_R11) = v50->tangent[2];
      LODWORD(_R11) = v50->tangent[0];
      HIDWORD(v62) = v50->tangent[1];
      __asm { lvx128    v63, r0, r17 }
      v137 = *(_QWORD *)(&v51 - 1);
      v135 = *(_QWORD *)((char *)&_R11 + 4);
      v129 = _R11;
      __asm { lvx128    v13, r0, r19 }
      v74 = (float)((float)((float)*(__int64 *)(&v51 - 1) * (float)0.0078431377) - (float)1.0);
      v75 = (float)((float)((float)(__int64)_R11 * (float)0.0078431377) - (float)1.0);
      v76 = (float)((float)((float)*(__int64 *)((char *)&_R11 + 4) * (float)0.0078431377) - (float)1.0);
      _FP8 = (float)((float)((float)((float)v76 * (float)v76)
                           + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f8, f9, f0 }
      v79 = __frsqrte(_FP6);
      v80 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79
                                                                                          * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v79)
                                                                          - (float)1.5)
                                                          * (float)v79)
                                                  * (float)((float)((float)((float)v76 * (float)v76)
                                                                  + (float)((float)((float)v75 * (float)v75)
                                                                          + (float)((float)v74 * (float)v74)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v79
                                                                                  * (float)((float)((float)((float)v76 * (float)v76)
                                                                                                  + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)))
                                                                                          * (float)0.5))
                                                                          * (float)v79)
                                                                  - (float)1.5)
                                                  * (float)v79))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v79
                                                          * (float)((float)((float)((float)v76 * (float)v76)
                                                                          + (float)((float)((float)v75 * (float)v75)
                                                                                  + (float)((float)v74 * (float)v74)))
                                                                  * (float)0.5))
                                                  * (float)v79)
                                          - (float)1.5)
                          * (float)v79));
      __asm { lvx128    v0, r0, r18 }
      v126 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79) * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79)
                                                                                            - (float)1.5)
                                                                            * (float)v79))
                                                            * (float)((float)((float)((float)v76 * (float)v76)
                                                                            + (float)((float)((float)v75 * (float)v75)
                                                                                    + (float)((float)v74 * (float)v74)))
                                                                    * (float)0.5))
                                                    * (float)v80)
                                            - (float)1.5)
                            * (float)v80)
                    * (float)v74);
      v125 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79) * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79)
                                                                                            - (float)1.5)
                                                                            * (float)v79))
                                                            * (float)((float)((float)((float)v76 * (float)v76)
                                                                            + (float)((float)((float)v75 * (float)v75)
                                                                                    + (float)((float)v74 * (float)v74)))
                                                                    * (float)0.5))
                                                    * (float)v80)
                                            - (float)1.5)
                            * (float)v80)
                    * (float)v75);
      *(float *)v127 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79) * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)((float)v76 * (float)v76) + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74))) * (float)0.5)) * (float)v79) - (float)1.5)
                                                                                      * (float)v79))
                                                                      * (float)((float)((float)((float)v76 * (float)v76)
                                                                                      + (float)((float)((float)v75 * (float)v75)
                                                                                              + (float)((float)v74 * (float)v74)))
                                                                              * (float)0.5))
                                                              * (float)v80)
                                                      - (float)1.5)
                                      * (float)v80)
                              * (float)v76);
      __asm
      {
        lvlx128   v54, r0, r9
        lvlx128   v55, r0, r8
        lvlx128   v53, r0, r7
        vrlimi128 v56, v53, 8, 0
        vrlimi128 v56, v54, 4, 3
        vrlimi128 v56, v55, 2, 2
        vaddfp128 v12, v88, v63
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v52, v0, 0
        vpkswss128 v51, v84, v52
        vpkshus128 v0, v83, v51
        stvebx    v0, 0, r29
        stvebx    v0, r29, r15
        stvebx    v0, r29, r16
      }
      DWORD2(v81) = idDrawVert::GetBiTangent(
                      this: v139,
                      result: &v50->xyz,
                      a3: v61,
                      a4: v60,
                      a5: *(__int64 *)((char *)&_R11 + 12));
      LODWORD(v82) = v50->tangent[2];
      LODWORD(v83) = v50->tangent[0];
      LODWORD(v81) = v50->tangent[1];
      v84 = -*(float *)(DWORD2(v81) + 8);
      v85 = *(float *)(DWORD2(v81) + 4);
      v86 = -*(float *)DWORD2(v81);
      v133 = v82;
      v136 = v83;
      v87 = -v85;
      v127[1] = v81;
      v88 = (float)(__int64)v81;
      LODWORD(v81) = v50->normal[1];
      v128 = v81;
      LODWORD(v89) = v50->normal[0];
      DWORD2(v81) = v50->normal[2];
      v130 = *(_QWORD *)((char *)&v81 + 4);
      v138 = v89;
      v90 = (float)((float)((float)v88 * (float)0.0078431377) - (float)1.0);
      v91 = (float)((float)((float)v83 * (float)0.0078431377) - (float)1.0);
      v92 = (float)((float)((float)v82 * (float)0.0078431377) - (float)1.0);
      _FP2 = (float)((float)((float)((float)v92 * (float)v92)
                           + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f2, f3, f0 }
      v95 = __frsqrte(_FP13);
      v96 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v95
                                                                                          * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v95)
                                                                          - (float)1.5)
                                                          * (float)v95)
                                                  * (float)((float)((float)((float)v92 * (float)v92)
                                                                  + (float)((float)((float)v91 * (float)v91)
                                                                          + (float)((float)v90 * (float)v90)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v95
                                                                                  * (float)((float)((float)((float)v92 * (float)v92)
                                                                                                  + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90)))
                                                                                          * (float)0.5))
                                                                          * (float)v95)
                                                                  - (float)1.5)
                                                  * (float)v95))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v95
                                                          * (float)((float)((float)((float)v92 * (float)v92)
                                                                          + (float)((float)((float)v91 * (float)v91)
                                                                                  + (float)((float)v90 * (float)v90)))
                                                                  * (float)0.5))
                                                  * (float)v95)
                                          - (float)1.5)
                          * (float)v95));
      v97 = (float)((float)((float)v128 * (float)0.0078431377) - (float)1.0);
      v98 = 0;
      v99 = (float)((float)((float)v89 * (float)0.0078431377) - (float)1.0);
      v100 = (float)((float)((float)*(__int64 *)((char *)&v81 + 4) * (float)0.0078431377) - (float)1.0);
      v101 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5) * (float)v95)
                                                                                           * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5)
                                                                                           * (float)v95))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5))
                                                                                           * (float)v95)
                                                                                   - (float)1.5)
                                                                   * (float)v95))
                                                   * (float)((float)((float)((float)v92 * (float)v92)
                                                                   + (float)((float)((float)v91 * (float)v91)
                                                                           + (float)((float)v90 * (float)v90)))
                                                           * (float)0.5))
                                           * (float)v96)
                                   - (float)1.5)
                   * (float)v96);
      v102 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5) * (float)v95) * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5) * (float)v95))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95)
                                                                                           - (float)1.5)
                                                                           * (float)v95))
                                                           * (float)((float)((float)((float)v92 * (float)v92)
                                                                           + (float)((float)((float)v91 * (float)v91)
                                                                                   + (float)((float)v90 * (float)v90)))
                                                                   * (float)0.5))
                                                   * (float)v96)
                                           - (float)1.5)
                           * (float)v96)
                   * (float)v92);
      v103 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5) * (float)v95) * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95) - (float)1.5) * (float)v95))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v95 * (float)((float)((float)((float)v92 * (float)v92) + (float)((float)((float)v91 * (float)v91) + (float)((float)v90 * (float)v90))) * (float)0.5)) * (float)v95)
                                                                                           - (float)1.5)
                                                                           * (float)v95))
                                                           * (float)((float)((float)((float)v92 * (float)v92)
                                                                           + (float)((float)((float)v91 * (float)v91)
                                                                                   + (float)((float)v90 * (float)v90)))
                                                                   * (float)0.5))
                                                   * (float)v96)
                                           - (float)1.5)
                           * (float)v96)
                   * (float)v90);
      v104 = (float)((float)v101 * (float)((float)((float)v83 * (float)0.0078431377) - (float)1.0));
      _FP3 = (float)((float)((float)((float)v100 * (float)v100)
                           + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f3, f12, f0 }
      v107 = __frsqrte(_FP6);
      v108 = (float)((float)-(float)((float)((float)((float)v107
                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                           + (float)((float)v97 * (float)v97)))
                                                           * (float)0.5))
                                           * (float)v107)
                                   - (float)1.5)
                   * (float)v107);
      v109 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                           * (float)v108)
                                                                                   - (float)1.5)
                                                                   * (float)v108)
                                                           * (float)((float)((float)((float)v100 * (float)v100)
                                                                           + (float)((float)((float)v99 * (float)v99)
                                                                                   + (float)((float)v97 * (float)v97)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v108
                                                                                           * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                   * (float)v108)
                                                                           - (float)1.5)
                                                           * (float)v108))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v108
                                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                                           + (float)((float)v97 * (float)v97)))
                                                                           * (float)0.5))
                                                           * (float)v108)
                                                   - (float)1.5)
                                   * (float)v108))
                   * (float)v97);
      v110 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                           * (float)v108)
                                                                                   - (float)1.5)
                                                                   * (float)v108)
                                                           * (float)((float)((float)((float)v100 * (float)v100)
                                                                           + (float)((float)((float)v99 * (float)v99)
                                                                                   + (float)((float)v97 * (float)v97)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v108
                                                                                           * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                   * (float)v108)
                                                                           - (float)1.5)
                                                           * (float)v108))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v108
                                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                                           + (float)((float)v97 * (float)v97)))
                                                                           * (float)0.5))
                                                           * (float)v108)
                                                   - (float)1.5)
                                   * (float)v108))
                   * (float)v99);
      v111 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                           * (float)v108)
                                                                                   - (float)1.5)
                                                                   * (float)v108)
                                                           * (float)((float)((float)((float)v100 * (float)v100)
                                                                           + (float)((float)((float)v99 * (float)v99)
                                                                                   + (float)((float)v97 * (float)v97)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v108
                                                                                           * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                   * (float)v108)
                                                                           - (float)1.5)
                                                           * (float)v108))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v108
                                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                                           + (float)((float)v97 * (float)v97)))
                                                                           * (float)0.5))
                                                           * (float)v108)
                                                   - (float)1.5)
                                   * (float)v108))
                   * (float)v100);
      if ( (float)((float)((float)((float)((float)v109 * (float)v102) - (float)((float)v111 * (float)v103)) * (float)v86)
                 + (float)((float)((float)((float)((float)v111 * (float)v104) - (float)((float)v102 * (float)v110))
                                 * (float)v87)
                         + (float)((float)((float)((float)v103 * (float)v110) - (float)((float)v109 * (float)v104))
                                 * (float)v84))) >= 0.0 )
        v98 = -1;
      v112 = v118[0];
      ++v33;
      v113 = v120 + 1;
      v50->tangent[3] = v98;
      LOWORD(num) = v119.num;
      v120 = v113;
      v118[0] = v112 + 8;
    }
    while ( v113 < v119.num );
    v28 = a22;
  }
  v114 = 3 * (v28->num / 3);
  if ( v114 > 0 )
  {
    v115 = 0;
    v116 = (v114 - 1) / 3u + 1;
    while ( 1 )
    {
      HIWORD(v118[0]) = v28->list[v115] + num;
      idList<unsigned short,72>::Append(this: v28, obj: (unsigned __int16 *)v118);
      HIWORD(v118[0]) = v28->list[v115 + 2] + LOWORD(v119.num);
      idList<unsigned short,72>::Append(this: v28, obj: (unsigned __int16 *)v118);
      HIWORD(v118[0]) = v28->list[v115 + 1] + LOWORD(v119.num);
      idList<unsigned short,72>::Append(this: v28, obj: (unsigned __int16 *)v118);
      --v116;
      v115 += 3;
      if ( v116 == 0 )
        break;
      LOWORD(num) = v119.num;
    }
  }
  if ( v119.listStatic == 0 || v119.listStatic == 2 )
  {
    if ( v119.list != nullptr )
      idMem::Free(this: &mem, ptr: v119.list, align: ALIGN_16);
    v119.list = nullptr;
    v119.size = 0;
  }
  v119.num = 0;
  idEarClipTriangulate::~idEarClipTriangulate(this: (idEarClipTriangulate *)v139[0].tangent);
  _R0 = -208;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$220840
// EA  : 0x827C957C
// RVA : 0x007C957C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

void _unwind_220840()
{
  int v0; // r12

  idEarClipTriangulate::~idEarClipTriangulate(this: (idEarClipTriangulate *)(v0 - 640 + 272));
}


// ========================================================================
// __unwind$220841
// EA  : 0x827C95A4
// RVA : 0x007C95A4
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttablesurface.cpp
// ========================================================================

void _unwind_220841()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 640 + 96));
}

