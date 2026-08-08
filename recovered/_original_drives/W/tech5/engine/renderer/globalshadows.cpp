
// ========================================================================
// ?ShadowSample@idGlobalShadows@@QBAMABVidVec3@@@Z
// EA  : 0x828BFB50
// RVA : 0x008BFB50
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

double __fastcall idGlobalShadows::ShadowSample(idGlobalShadows *this, const idVec3 *worldPoint)
{
  return shadowMap_t::ShadowSample(this: this->shadowMap, worldPoint);
}


// ========================================================================
// ??1idGlobalShadows@@QAA@XZ
// EA  : 0x828BFC30
// RVA : 0x008BFC30
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __fastcall idGlobalShadows::~idGlobalShadows(idGlobalShadows *this)
{
  unsigned __int16 *map; // r4

  map = this->shadowMap->map;
  if ( map != nullptr )
  {
    idMem::Free(this: &mem, ptr: map, align: ALIGN_16);
    this->shadowMap->map = nullptr;
  }
  idMem::Free(this: &mem, ptr: this->shadowMap, align: ALIGN_16);
}


// ========================================================================
// ?GetShadowMap@idGlobalShadows@@QBAPBUshadowMap_t@@XZ
// EA  : 0x828BFCA0
// RVA : 0x008BFCA0
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

const shadowMap_t *__fastcall idGlobalShadows::GetShadowMap(idGlobalShadows *this)
{
  this->shadowMap->coordinateBias = r_globalShadowsCoordinateBias.valueFloat;
  this->shadowMap->depthBias = r_globalShadowsDepthBias.valueFloat;
  this->shadowMap->useShadowMap = r_useGlobalShadows.valueInteger != 0;
  return this->shadowMap;
}


// ========================================================================
// ??0idGlobalShadows@@QAA@XZ
// EA  : 0x828BFCF0
// RVA : 0x008BFCF0
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

idGlobalShadows *__fastcall idGlobalShadows::idGlobalShadows(idGlobalShadows *this)
{
  shadowMap_t *v2; // r3
  shadowMap_t *shadowMap; // r10

  v2 = (shadowMap_t *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x54u,
                        tag: TAG_RENDERER,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  this->shadowMap = v2;
  v2->width = 1024;
  this->shadowMap->map = nullptr;
  memset(Dst: &this->shadowMap->mvp, Val: 0, Size: sizeof(this->shadowMap->mvp));
  shadowMap = this->shadowMap;
  shadowMap->mvp.m[15] = 1.0;
  shadowMap->coordinateBias = -0.5;
  this->shadowMap->depthBias = -40.0;
  this->shadowMap->useShadowMap = true;
  return this;
}


// ========================================================================
// ?LoadGlobalShadows@idGlobalShadows@@QAAXPAVidRenderWorldLocal@@@Z
// EA  : 0x828BFDB0
// RVA : 0x008BFDB0
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __fastcall idGlobalShadows::LoadGlobalShadows(idGlobalShadows *this, idRenderWorldLocal *rw)
{
  unsigned __int16 *map; // r4
  const char *v5; // r3
  idFileResource *v6; // r3
  idFileResource *v7; // r27
  idFile_Memory *File; // r3
  idFile_Memory *v9; // r29
  int v10; // r10
  int i; // ctr
  char *v12; // r11
  char v13; // r8
  char v14; // r7
  char v15; // r6
  char *v16; // r11
  char v17; // r5
  char v18; // r3
  char *v19; // r11
  char v20; // r8
  char v21; // r6
  char *v22; // r11
  char v23; // r4
  char v24; // r9
  int v25; // r10
  int j; // ctr
  unsigned __int16 *v27; // r11
  char v28; // r8
  idStr v29[3]; // [sp+50h] [-60h] BYREF

  map = this->shadowMap->map;
  if ( map != nullptr )
  {
    idMem::Free(this: &mem, ptr: map, align: ALIGN_16);
    this->shadowMap->map = nullptr;
  }
  memset(Dst: &this->shadowMap->mvp, Val: 0, Size: sizeof(this->shadowMap->mvp));
  this->shadowMap->mvp.m[15] = 1.0;
  if ( rw != nullptr )
  {
    v29[0].len = 0;
    v29[0].baseBuffer[0] = 0;
    v29[0].allocedAndFlag = 20;
    v29[0].data = v29[0].baseBuffer;
    v5 = rw->GetName(this: rw);
    idStr::operator=(this: v29, text: v5);
    idStr::Append(this: v29, text: "/globalShadows2.bin");
    if ( (unsigned __int8)idFileResource::FileExists(name: v29[0].data) != 0 )
    {
      v6 = (idFileResource *)idResourceList::Load(
                               this: &idFileResource::resourceList,
                               name: v29[0].data,
                               makeDefault: false,
                               skipStaleCheck: false);
      v7 = v6;
      if ( v6 != nullptr && (int)v6->length > 0 )
      {
        File = idFileResource::GetFile(this: v6);
        v9 = File;
        if ( File != nullptr )
        {
          if ( (int)File->Length(this: File) <= 0 )
          {
            ((void (__fastcall *)(idFile_Memory *, int))v9->dtr_idFile)(a1: v9, a2: 1);
          }
          else
          {
            idLib::Printf(fmt: "Loading globalShadows.\n");
            v9->Read(this: v9, a2: &this->shadowMap->mvp, a3: 64u);
            this->shadowMap->width = 1024;
            this->shadowMap->map = (unsigned __int16 *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\engine\\renderer\\GlobalShadows.cpp(98) : TAG_RENDERWORLD",
                                                         size: 0x200000u,
                                                         tag: TAG_RENDERWORLD,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
            v9->Read(this: v9, a2: this->shadowMap->map, a3: 0x200000u);
            ((void (__fastcall *)(idFile_Memory *, int))v9->dtr_idFile)(a1: v9, a2: 1);
            v10 = 12;
            for ( i = 4; i != 0; --i )
            {
              v12 = (char *)this->shadowMap + v10;
              v13 = *(v12 - 2);
              v14 = *(v12 - 3);
              v15 = *(v12 - 1);
              *(v12 - 1) = *(v12 - 4);
              *(v12 - 3) = v13;
              *(v12 - 2) = v14;
              *(v12 - 4) = v15;
              v16 = (char *)this->shadowMap + v10;
              v17 = *v16;
              *v16 = v16[3];
              v16[3] = v17;
              v18 = v16[1];
              v16[1] = v16[2];
              v16[2] = v18;
              v19 = (char *)this->shadowMap + v10;
              v20 = v19[4];
              v19[4] = v19[7];
              v19[7] = v20;
              v21 = v19[5];
              v19[5] = v19[6];
              v19[6] = v21;
              v22 = (char *)this->shadowMap + v10;
              v23 = v22[8];
              v10 += 16;
              v22[8] = v22[11];
              v22[11] = v23;
              v24 = v22[9];
              v22[9] = v22[10];
              v22[10] = v24;
            }
            v25 = 0;
            for ( j = 0x100000; j != 0; --j )
            {
              v27 = &this->shadowMap->map[v25++];
              v28 = *((_BYTE *)v27 + 1);
              *((_BYTE *)v27 + 1) = *(_BYTE *)v27;
              *(_BYTE *)v27 = v28;
            }
            this->shadowMap->coordinateBias = r_globalShadowsCoordinateBias.valueFloat;
            this->shadowMap->depthBias = r_globalShadowsDepthBias.valueFloat;
            this->shadowMap->useShadowMap = r_useGlobalShadows.valueInteger != 0;
            ((void (__fastcall *)(idFileResource *, int))v7->dtr_idResource)(a1: v7, a2: 1);
          }
        }
      }
    }
    idStr::FreeData(this: v29);
  }
}


// ========================================================================
// __unwind$229855
// EA  : 0x828C00F8
// RVA : 0x008C00F8
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void _unwind_229855()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?WriteShadowVisualizationModel@idGlobalShadows@@QAAXPBD@Z
// EA  : 0x828C0128
// RVA : 0x008C0128
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGlobalShadows::WriteShadowVisualizationModel(idGlobalShadows *this, const char *modelName)
{
  __int64 v2; // r16
  __int64 v4; // r11
  signed __int64 v5; // r21
  idVec4 *v6; // r27
  int i; // r28
  int v8; // r30
  idVec4 *v9; // r29
  int width; // r29
  unsigned __int16 *map; // r30
  int v12; // r11
  int j; // r10
  signed int v14; // r10
  int v15; // r22
  int v16; // r28
  int *v17; // r16
  unsigned int v18; // r18
  unsigned __int16 *v19; // r17
  idTriangles *v21; // r3
  idTriangles *v22; // r30
  __int64 v23; // r10 OVERLAPPED
  int v25; // r26
  int v26; // r23
  unsigned int v27; // r5
  int v28; // r28
  unsigned int v29; // r3
  unsigned __int16 *v30; // r4
  int v31; // r8
  double v32; // fp12
  unsigned __int16 *v33; // r7
  int v34; // r11
  idDrawVert *verts; // r11
  float y; // r14
  int v38; // r3
  __int16 v39; // r8
  unsigned int v40; // r4
  int v41; // r11
  __int16 v42; // r7
  idBounds *v43; // r3
  int v44; // r10
  int v45; // r9
  int v46; // r8
  int v47; // r7
  int v48; // r6
  int v49; // [sp+8h] [-548h]
  int v50; // [sp+Ch] [-544h]
  int v51; // [sp+10h] [-540h]
  int v52; // [sp+14h] [-53Ch]
  int v53; // [sp+18h] [-538h]
  unsigned int v54; // [sp+1Ch] [-534h]
  idVec4 v55; // [sp+50h] [-500h] BYREF
  const char *v56; // [sp+60h] [-4F0h]
  signed int v57; // [sp+64h] [-4ECh]
  idMem *v58; // [sp+68h] [-4E8h]
  __int64 v59; // [sp+70h] [-4E0h]
  idVec4 v60; // [sp+80h] [-4D0h] BYREF
  char *v61; // [sp+90h] [-4C0h]
  int *v62; // [sp+94h] [-4BCh]
  idDeclInfoTemplate<idMaterial> *v63; // [sp+98h] [-4B8h]
  int v64; // [sp+9Ch] [-4B4h]
  int v65; // [sp+A0h] [-4B0h]
  __int64 v66; // [sp+A8h] [-4A8h]
  idStaticModelSurface v67; // [sp+B0h] [-4A0h] BYREF
  idRenderMatrix v68; // [sp+100h] [-450h] BYREF
  unsigned __int64 v69; // [sp+140h] [-410h]
  __int64 v70; // [sp+148h] [-408h]
  __int64 v71; // [sp+150h] [-400h]
  idRenderMatrix mvp; // [sp+160h] [-3F0h] BYREF
  idTriangles v73[3]; // [sp+1A0h] [-3B0h] BYREF
  int v74; // [sp+360h] [-1F0h] BYREF

  if ( this->shadowMap != nullptr )
  {
    mvp = this->shadowMap->mvp;
    mvp.m[12] = 0.0;
    mvp.m[13] = 0.0;
    mvp.m[14] = 0.0;
    mvp.m[15] = 1.0;
    idRenderMatrix::InverseByDoubles(src: &mvp, out: &v68);
    v55.w = 1.0;
    v55.x = 0.5;
    v55.y = 0.5;
    v55.z = 0.5;
    idRenderMatrix::TransformPoint(this: &mvp, in: &v55, out: &v60);
    idRenderMatrix::TransformPoint(this: &v68, in: &v60, out: &v55);
    v55.w = 1.0;
    v55.x = -13608.0;
    v55.y = -6688.0;
    v55.z = 103.0;
    idRenderMatrix::TransformPoint(this: &mvp, in: &v55, out: &v60);
    idRenderMatrix::TransformPoint(this: &v68, in: &v60, out: &v55);
    LODWORD(v5) = 0;
    v55.w = 1.0;
    v55.z = 0.5;
    v6 = (idVec4 *)&v74;
    for ( i = 0; i < 4; ++i )
    {
      LODWORD(v4) = i;
      v8 = 0;
      v59 = v4;
      v9 = v6;
      v55.x = (float)v4 * (float)0.33333334;
      do
      {
        LODWORD(v4) = v8;
        v66 = v4;
        v55.y = (float)v4 * (float)0.33333334;
        idRenderMatrix::TransformPoint(this: &v68, in: &v55, out: v9);
        ++v8;
        v9 += 4;
      }
      while ( v8 < 4 );
      ++v6;
    }
    width = this->shadowMap->width;
    map = this->shadowMap->map;
    idStaticModel::idStaticModel(this: (idStaticModel *)&v73[0].numVerts);
    v12 = width * width;
    for ( j = 1; v12 > 0x10000; j *= 2 )
      v12 >>= 1;
    v14 = 2 * j;
    HIDWORD(v5) = width / v14;
    __twllei(v14, 0);
    __twlgei(v14 & ~(__ROL4__(width, 1) - 1), 0xFFFFFFFF);
    if ( v14 > 0 )
    {
      v15 = width - 1;
      v57 = v14;
      HIDWORD(v66) = 2 * HIDWORD(v5) * width;
      v16 = (HIDWORD(v5) + 1) * width;
      v64 = 6 * (width - 1) * HIDWORD(v5);
      v65 = v16;
      v56 = "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW";
      v58 = &mem;
      v17 = &breakHere_0;
      v61 = "textures/common/flatShadeTwoSidedDimRed";
      v18 = 0;
      v63 = &idMaterial::resourceList;
      v19 = map;
      v62 = &breakHere_0;
      _R19 = 16;
      while ( 1 )
      {
        v21 = (idTriangles *)idMem::AllocWithLocation(
                               this: v58,
                               location: v56,
                               size: 0x84u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        HIDWORD(v59) = v21;
        if ( v21 != nullptr )
          v22 = idTriangles::idTriangles(this: v21);
        else
          v22 = nullptr;
        idTriangles::AllocStaticTriSurfVerts(this: v22, numVerts: v16);
        v25 = 0;
        v22->numVerts = v16;
        if ( v5 >= 0 )
        {
          v26 = *v17;
          v27 = v18;
          v28 = 1;
          v29 = 0;
          v30 = v19;
          do
          {
            if ( v27 == width )
              break;
            v31 = 0;
            if ( width > 0 )
            {
              __asm { vspltisw128 v63, 0 }
              LODWORD(v23) = v27;
              v71 = v23;
              v69 = __PAIR64__(v27, width);
              __asm { vcmpequw128 v62, v95, v63 }
              v32 = (double)v23;
              v23 = __PAIR64__(v29, v28);
              __asm { vsldoi128 v62, v95, v62, 4 }
              v33 = v30;
              do
              {
                LODWORD(v2) = *v33;
                v34 = v31;
                *(_QWORD *)&v55.x = *(__int64 *)((char *)&v23 - 4);
                v70 = v2;
                v60.x = (float)((float)(v68.m[1] * (float)((float)v32 / (float)__SPAIR64__(v27, width)))
                              + (float)((float)(v68.m[0]
                                              * (float)((float)*(__int64 *)((char *)&v23 - 4)
                                                      / (float)__SPAIR64__(v27, width)))
                                      + (float)(v68.m[2] * (float)((float)v2 * (float)0.000015259022))))
                      + v68.m[3];
                v60.y = (float)((float)(v68.m[5] * (float)((float)v32 / (float)__SPAIR64__(v27, width)))
                              + (float)((float)(v68.m[4]
                                              * (float)((float)*(__int64 *)((char *)&v23 - 4)
                                                      / (float)__SPAIR64__(v27, width)))
                                      + (float)(v68.m[6] * (float)((float)v2 * (float)0.000015259022))))
                      + v68.m[7];
                v60.z = (float)((float)(v68.m[9] * (float)((float)v32 / (float)__SPAIR64__(v27, width)))
                              + (float)((float)(v68.m[8]
                                              * (float)((float)*(__int64 *)((char *)&v23 - 4)
                                                      / (float)__SPAIR64__(v27, width)))
                                      + (float)(v68.m[10] * (float)((float)v2 * (float)0.000015259022))))
                      + v68.m[11];
                v60.w = (float)((float)(v68.m[12]
                                      * (float)((float)*(__int64 *)((char *)&v23 - 4) / (float)__SPAIR64__(v27, width)))
                              + (float)((float)(v68.m[13] * (float)((float)v32 / (float)__SPAIR64__(v27, width)))
                                      + (float)(v68.m[14] * (float)((float)v2 * (float)0.000015259022))))
                      + v68.m[15];
                if ( (float)v2 < 65535.0 )
                  ++v26;
                verts = v22->verts;
                v22->numVerts = v23;
                ++v31;
                _R11 = (float *)((char *)&verts->xyz.x + HIDWORD(v23));
                ++v33;
                LODWORD(v23) = v23 + 1;
                HIDWORD(v23) += 32;
                __asm
                {
                  stvx128   v63, r0, r11
                  stvx128   v62, r11, r19
                }
                y = v60.y;
                v2 = __PAIR64__(LODWORD(v60.x), LODWORD(v60.z));
                *_R11 = v60.x;
                _R11[1] = y;
                *((_DWORD *)_R11 + 2) = v2;
              }
              while ( v31 < width );
              v17 = v62;
            }
            ++v25;
            ++v27;
            v30 += width;
            v29 += 32 * width;
            v28 += width;
          }
          while ( v25 <= SHIDWORD(v5) );
          *v17 = v26;
        }
        idTriangles::AllocStaticTriSurfIndexes(this: v22, numIndexes: v64);
        v38 = 0;
        v22->numIndexes = 0;
        if ( SHIDWORD(v5) > 0 )
        {
          v39 = 0;
          v40 = v18 + 1;
          do
          {
            if ( v40 == width )
              break;
            v41 = 0;
            if ( v15 > 0 )
            {
              v42 = v39 + width;
              do
              {
                v22->indexes[v22->numIndexes] = v39 + v41 + 1;
                v22->indexes[v22->numIndexes + 1] = v39 + v41;
                v22->indexes[v22->numIndexes + 2] = v42 + v41 + 1;
                v22->indexes[v22->numIndexes + 3] = v42 + v41 + 1;
                v22->indexes[v22->numIndexes + 4] = v39 + v41;
                v22->indexes[v22->numIndexes + 5] = v42 + v41++;
                v22->numIndexes += 6;
              }
              while ( v41 < v15 );
            }
            ++v38;
            ++v40;
            v39 += width;
          }
          while ( v38 < SHIDWORD(v5) );
        }
        v43 = idTriangles::BoundsFromVertScan(this: v73, result: &v22->bounds);
        v22->bounds.b[0].x = v43->b[0].x;
        HIDWORD(v59) = &v43->b[1];
        v22->bounds.b[0].y = v43->b[0].y;
        v22->bounds.b[0].z = v43->b[0].z;
        v22->bounds.b[1] = v43->b[1];
        v67.material = nullptr;
        v67.skinOffsets.x = 0.0;
        v67.materialNum = 0;
        v67.skinOffsets.y = 0.0;
        v67.extraGLState = v5;
        v67.skinOffsets.z = 0.0;
        v67.geometryIsReference = false;
        v67.skinOffsets.w = 0.0;
        v67.referenceMask = 0;
        memset(&v67.binaryModelId, 0, 16);
        v67.skinRemaps.memTag = 5;
        v67.skinRemaps.listStatic = 0;
        memset(&v67.skinRemaps, 0, 14);
        v67.geometry = v22;
        v67.material = (const idMaterial *)idResourceList::Load(
                                             this: v63,
                                             name: v61,
                                             makeDefault: true,
                                             skipStaleCheck: false);
        idStaticModel::AddSurface(this: (idStaticModel *)&v73[0].numVerts, surf: &v67);
        if ( v67.skinRemaps.listStatic == 0 || v67.skinRemaps.listStatic == 2 )
        {
          if ( v67.skinRemaps.list != nullptr )
            idMem::Free(this: v58, ptr: v67.skinRemaps.list, align: ALIGN_16);
          v67.skinRemaps.list = nullptr;
          v67.skinRemaps.size = 0;
        }
        v18 += HIDWORD(v5);
        v67.skinRemaps.num = 0;
        v19 = (unsigned __int16 *)((char *)v19 + HIDWORD(v66));
        if ( --v57 == 0 )
          break;
        v16 = v65;
      }
    }
    idStaticModel::FinishStaticModel(this: (idStaticModel *)&v73[0].numVerts, cleanup: false);
    idStaticModel::WriteStaticBModel(
      this: (idStaticModel *)&v73[0].numVerts,
      filename: modelName,
      basePath: FSPATH_BASE,
      a4: v48,
      a5: v47,
      a6: v46,
      a7: v45,
      a8: v44,
      a9: v49,
      a10: v50,
      a11: v51,
      a12: v52,
      a13: v53,
      a14: v54);
    idStaticModel::~idStaticModel(this: (idStaticModel *)&v73[0].numVerts);
  }
}


// ========================================================================
// __unwind$230075
// EA  : 0x828C07EC
// RVA : 0x008C07EC
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void _unwind_230075()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 1360 + 448));
}


// ========================================================================
// __unwind$230076
// EA  : 0x828C0814
// RVA : 0x008C0814
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __fastcall _unwind_230076(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 1360 + 112), tag: a2);
}


// ========================================================================
// __unwind$230077
// EA  : 0x828C083C
// RVA : 0x008C083C
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void _unwind_230077()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 1360 + 176));
}


// ========================================================================
// ?DrawGlobalShadowsModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C0870
// RVA : 0x008C0870
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __fastcall DrawGlobalShadowsModel_f(const idCmdArgs *args)
{
  const char *v1; // r3
  bool v2; // cr58
  int (*GetName)(void); // ctr
  const char *v4; // r3
  const char *v5; // r3
  char v6; // r25
  int v7; // r26
  int v8; // r27
  idRenderModel *v9; // r28
  const char *v10; // r3
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  va *v14; // r3
  idRenderModel *v15; // r3
  char v16; // r9
  char v17; // r8
  int v18; // [sp+8h] [-10A8h]
  int v19; // [sp+Ch] [-10A4h]
  int v20; // [sp+10h] [-10A0h]
  int v21; // [sp+14h] [-109Ch]
  int v22; // [sp+18h] [-1098h]
  int v23; // [sp+1Ch] [-1094h]
  idStr v24; // [sp+50h] [-1060h] BYREF
  va v25; // [sp+70h] [-1040h] BYREF

  if ( tr.primaryWorld == nullptr )
  {
    idLib::Printf(fmt: "No primaryWorld.\n");
    return;
  }
  if ( (_S13_22 & 1) == 0 )
  {
    _S13_22 |= 1u;
    mapName.allocedAndFlag = 20;
    mapName.data = mapName.baseBuffer;
    mapName.len = 0;
    mapName.baseBuffer[0] = 0;
    atexit(func: (void (__fastcall *)())_DrawGlobalShadowsModel_f_::_5_::_dynamic_atexit_destructor_for__mapName__);
  }
  v1 = (const char *)((int (*)(void))tr.primaryWorld->GetName)();
  v2 = idStr::Cmp(s1: mapName.data, s2: v1) == 0;
  GetName = (int (*)(void))tr.primaryWorld->GetName;
  if ( v2 )
  {
    v5 = (const char *)GetName();
    if ( idStr::Cmp(s1: mapName.data, s2: v5) != 0 )
    {
      v9 = renderModel;
    }
    else
    {
      if ( renderModel == nullptr )
        goto LABEL_19;
      v6 = 0;
      v7 = 0;
      if ( tr.primaryWorld->GetNumRenderModels(this: tr.primaryWorld) <= 0 )
      {
LABEL_13:
        v9 = renderModel;
      }
      else
      {
        v8 = 0;
        while ( 1 )
        {
          v9 = renderModel;
          if ( renderModel == tr.primaryWorld->renderModels.list[v8] )
            break;
          ++v7;
          ++v8;
          if ( v7 >= tr.primaryWorld->GetNumRenderModels(this: tr.primaryWorld) )
            goto LABEL_13;
        }
        v6 = 1;
      }
      if ( v6 == 0 )
      {
        renderModel = nullptr;
        goto LABEL_19;
      }
    }
    if ( v9 != nullptr )
      goto _M231188;
    goto LABEL_19;
  }
  v4 = (const char *)GetName();
  idStr::operator=(this: &mapName, text: v4);
  renderModel = nullptr;
LABEL_19:
  v10 = tr.primaryWorld->GetName(this: tr.primaryWorld);
  LODWORD(v11) = &off_82230000;
  HIDWORD(v12) = v10;
  v14 = va::va(
          this: &v25,
          fmt: "generated/%s",
          a3: v12,
          a4: v11,
          a5: v13,
          a6: v18,
          a7: v19,
          a8: v20,
          a9: v21,
          a10: v22,
          a11: v23);
  idStr::idStr(this: &v24, text: v14);
  idStr::StripFileExtension(this: &v24);
  idStr::Append(this: &v24, text: "/globalShadows2.bmodel");
  idGlobalShadows::WriteShadowVisualizationModel(this: &tr.primaryWorld->globalShadows, modelName: v24.data);
  v15 = tr.primaryWorld->AllocRenderModel(this: tr.primaryWorld, a2: v24.data, a3: 1, a4: -1);
  v16 = *((_BYTE *)&v15->g + 105);
  renderModel = v15;
  *((_BYTE *)&v15->g + 105) = v16 | 4;
  idStr::FreeData(this: &v24);
  v9 = renderModel;
_M231188:
  v17 = _cntlzw(showingShadows);
  showingShadows = (v17 & 0x20) != 0;
  if ( (v17 & 0x20) != 0 )
  {
    idRenderModel::CommitThisFrame(this: v9);
  }
  else if ( !v9->unlinked )
  {
    idRenderModel::CommitThisFrame(this: v9);
    v9->unlinked = true;
  }
}


// ========================================================================
// __unwind$231109_0
// EA  : 0x828C0B04
// RVA : 0x008C0B04
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void _unwind_231109_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 80));
}


// ========================================================================
// `dynamic initializer for 'r_globalShadowsCoordinateBias''
// EA  : 0x8334BA90
// RVA : 0x0134BA90
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_globalShadowsCoordinateBias__()
{
  idCVar::idCVar(
    this: &r_globalShadowsCoordinateBias,
    name: "r_globalShadowsCoordinateBias",
    value: "0.5",
    flags: 4,
    description: "Bias to the shadow check coordinate calculation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_globalShadowsCoordinateBias__);
}


// ========================================================================
// `dynamic initializer for 'r_globalShadowsDepthBias''
// EA  : 0x8334BAE8
// RVA : 0x0134BAE8
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_globalShadowsDepthBias__()
{
  idCVar::idCVar(
    this: &r_globalShadowsDepthBias,
    name: "r_globalShadowsDepthBias",
    value: "0",
    flags: 4,
    description: "Bias to the shadow check depth calculation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_globalShadowsDepthBias__);
}


// ========================================================================
// `dynamic initializer for 'r_useGlobalShadows''
// EA  : 0x8334BB40
// RVA : 0x0134BB40
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useGlobalShadows__()
{
  idCVar::idCVar(
    this: &r_useGlobalShadows,
    name: "r_useGlobalShadows",
    value: "1",
    flags: 1,
    description: "If false, always return 1.0 for shadow tests",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useGlobalShadows__);
}


// ========================================================================
// `dynamic initializer for 'DrawGlobalShadowsModel_v''
// EA  : 0x8334BB98
// RVA : 0x0134BB98
// PDB : w:\tech5\engine\renderer\globalshadows.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DrawGlobalShadowsModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &DrawGlobalShadowsModel_v,
           cmdName: "DrawGlobalShadowsModel",
           function: DrawGlobalShadowsModel_f,
           description: "Visualize the global shadow map as a model surface",
           argCompletion: nullptr);
}

