
// ========================================================================
// ??1idRenderModelGui@@UAA@XZ
// EA  : 0x82800010
// RVA : 0x00800010
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::~idRenderModelGui(idRenderModelGui *this)
{
  this->__vftable = (idRenderModelGui_vtbl *)&idRenderModelGui::`vftable';
  `eh vector destructor iterator'(
    ptr: &this->triangles,
    size: 0x84u,
    count: 256,
    pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231158
// EA  : 0x82800074
// RVA : 0x00800074
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _unwind_231158()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// ?Init@idRenderModelGui@@SAXXZ
// EA  : 0x828000A0
// RVA : 0x008000A0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

static void __fastcall idRenderModelGui::Init()
{
  int i; // r31

  for ( i = 0; i < 3; ++i )
  {
    idVertexBuffer::AllocBufferObject(
      this: &idRenderModelGui::vertexBuffer.ptr[i],
      data: nullptr,
      allocSize: 819200,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    idIndexBuffer::AllocBufferObject(
      this: &idRenderModelGui::indexBuffer.ptr[i],
      data: nullptr,
      allocSize: 81920,
      allocUsage: BU_DYNAMIC);
  }
  idRenderModelGui::mappedBufferIndex = -1;
  idRenderModelGui::numMappedVertices = 0;
  idRenderModelGui::mappedVertices = nullptr;
  idRenderModelGui::mappedIndices = nullptr;
  idRenderModelGui::numMappedIndices = 0;
  idRenderModelGui::frameCount = 0;
  idRenderModelGui::initialized = true;
}


// ========================================================================
// ?Shutdown@idRenderModelGui@@SAXXZ
// EA  : 0x82800158
// RVA : 0x00800158
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

static void __fastcall idRenderModelGui::Shutdown()
{
  int i; // r31

  if ( idRenderModelGui::mappedBufferIndex >= 0 )
  {
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelGui::vertexBuffer.ptr[idRenderModelGui::mappedBufferIndex]);
    idIndexBuffer::UnmapBuffer(this: &idRenderModelGui::indexBuffer.ptr[idRenderModelGui::mappedBufferIndex]);
  }
  for ( i = 0; i < 3; ++i )
  {
    idVertexBuffer::FreeBufferObject(this: &idRenderModelGui::vertexBuffer.ptr[i]);
    idIndexBuffer::FreeBufferObject(this: &idRenderModelGui::indexBuffer.ptr[i]);
  }
  idRenderModelGui::mappedBufferIndex = -1;
  idRenderModelGui::mappedVertices = nullptr;
  idRenderModelGui::mappedIndices = nullptr;
  idRenderModelGui::numMappedVertices = 0;
  idRenderModelGui::numMappedIndices = 0;
  idRenderModelGui::frameCount = 0;
  idRenderModelGui::initialized = false;
}


// ========================================================================
// ?StartFrame@idRenderModelGui@@SAXXZ
// EA  : 0x82800210
// RVA : 0x00800210
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

static void __fastcall idRenderModelGui::StartFrame()
{
  if ( idRenderModelGui::initialized )
  {
    if ( idRenderModelGui::mappedBufferIndex >= 0 )
    {
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelGui::vertexBuffer.ptr[idRenderModelGui::mappedBufferIndex]);
      idIndexBuffer::UnmapBuffer(this: &idRenderModelGui::indexBuffer.ptr[idRenderModelGui::mappedBufferIndex]);
    }
    idRenderModelGui::mappedBufferIndex = (idRenderModelGui::frameCount + 1) % 3;
    idRenderModelGui::mappedVertices = (idDrawVert *)idVertexBuffer::MapBuffer(
                                                       this: &idRenderModelGui::vertexBuffer.ptr[idRenderModelGui::mappedBufferIndex],
                                                       mapType: BM_WRITE_NOSYNC);
    idRenderModelGui::mappedIndices = (unsigned __int16 *)idIndexBuffer::MapBuffer(
                                                            this: &idRenderModelGui::indexBuffer.ptr[idRenderModelGui::mappedBufferIndex],
                                                            mapType: BM_WRITE_NOSYNC);
    idRenderModelGui::numMappedVertices = 0;
    idRenderModelGui::numMappedIndices = 0;
    ++idRenderModelGui::frameCount;
  }
}


// ========================================================================
// ?SetVirtualSize@idRenderModelGui@@QAAXHH@Z
// EA  : 0x82800358
// RVA : 0x00800358
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::SetVirtualSize(
        idRenderModelGui *this,
        __int64 height,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  LODWORD(a6) = HIDWORD(height);
  this->g.scale.z = 1.0;
  this->g.scale.x = (float)2.0 / (float)a6;
  this->g.scale.y = (float)-2.0 / (float)height;
  this->useVirtualSize = true;
}


// ========================================================================
// ?SetViewport@idRenderModelGui@@QAAXHHHH@Z
// EA  : 0x828003C0
// RVA : 0x008003C0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::SetViewport(
        idRenderModelGui *this,
        int x,
        int y,
        unsigned int width,
        unsigned int height)
{
  __int64 v8; // r10

  idRenderModel::SetViewport(this, x, y, width, height);
  HIDWORD(v8) = this->useVirtualSize;
  if ( !this->useVirtualSize )
  {
    LODWORD(v8) = width;
    this->g.scale.z = 1.0;
    this->g.scale.y = (float)-2.0 / (float)__SPAIR64__(width, height);
    this->g.scale.x = (float)2.0 / (float)v8;
  }
}


// ========================================================================
// ?GetVirtualWidth@idRenderModelGui@@QBAMXZ
// EA  : 0x82800450
// RVA : 0x00800450
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRenderModelGui::GetVirtualWidth(idRenderModelGui *this, int a2, int a3, __int64 a4)
{
  double v4; // fp1
  int x1; // r8

  if ( this->useVirtualSize )
  {
    v4 = (float)((float)2.0 / this->g.scale.x);
  }
  else
  {
    x1 = this->g.viewport.x1;
    LODWORD(a4) = this->g.viewport.x2;
    v4 = (float)((float)((float)a4 - (float)*(__int64 *)((char *)&a4 - 4)) + (float)1.0);
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?GetVirtualHeight@idRenderModelGui@@QBAMXZ
// EA  : 0x828004C0
// RVA : 0x008004C0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRenderModelGui::GetVirtualHeight(idRenderModelGui *this, int a2, int a3, __int64 a4)
{
  double v4; // fp1
  int y1; // r8

  if ( this->useVirtualSize )
  {
    v4 = (float)((float)-2.0 / this->g.scale.y);
  }
  else
  {
    y1 = this->g.viewport.y1;
    LODWORD(a4) = this->g.viewport.y2;
    v4 = (float)((float)((float)a4 - (float)*(__int64 *)((char *)&a4 - 4)) + (float)1.0);
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?AdvanceSurf@idRenderModelGui@@AAAXXZ
// EA  : 0x82800530
// RVA : 0x00800530
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::AdvanceSurf(
        idRenderModelGui *this,
        int a2,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6)
{
  int numGuiSurfaces; // r11
  int v8; // r4
  int frameNum; // r5
  int v10; // r11
  guiModelSurface_t *v11; // r11
  bool v12; // zf
  int v13; // r9

  numGuiSurfaces = this->numGuiSurfaces;
  if ( numGuiSurfaces == 256 )
  {
    idLib::Warning(fmt: "MAX_GUI_SURFACES exceeded!");
  }
  else
  {
    v8 = idRenderModelGui::frameCount;
    if ( numGuiSurfaces > 0 )
    {
      frameNum = this->frameNum;
      if ( idRenderModelGui::frameCount != frameNum )
      {
        idLib::Warning(
          fmt: "idRenderModelGui::AdvanceSurf: framenu missmatch %d, %d",
          idRenderModelGui::frameCount,
          frameNum);
        v8 = idRenderModelGui::frameCount;
      }
    }
    v10 = this->numGuiSurfaces;
    LODWORD(a6) = 0;
    this->frameNum = v8;
    v12 = v10 <= 0;
    v11 = &this->guiSurfaces.ptr[v10];
    if ( v12 )
    {
      v11->material = nullptr;
      v11->extraGLState = a6;
    }
    else
    {
      v11->material = this->surf->material;
      v11->extraGLState = this->surf->extraGLState;
    }
    v11->numIndexes = 0;
    v11->firstIndex = idRenderModelGui::numMappedIndices;
    v11->numVerts = 0;
    v13 = this->numGuiSurfaces + 1;
    this->surf = v11;
    this->numGuiSurfaces = v13;
  }
}


// ========================================================================
// ?SetGLState@idRenderModelGui@@QAAX_K@Z
// EA  : 0x82800610
// RVA : 0x00800610
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::SetGLState(idRenderModelGui *this, int a2, unsigned __int64 bits, int a4)
{
  unsigned __int64 v4; // r30
  guiModelSurface_t *surf; // r11

  surf = this->surf;
  LODWORD(v4) = a2;
  if ( surf != nullptr && a2 != LODWORD(surf->extraGLState) )
  {
    if ( surf->numVerts != 0 )
      idRenderModelGui::AdvanceSurf(this, a2, a3: SHIDWORD(bits), a4: bits, a5: a4, a6: surf->extraGLState);
    this->surf->extraGLState = v4;
  }
}


// ========================================================================
// ?AllocTris@idRenderModelGui@@QAAPAVidDrawVert@@HPBGHPBVidMaterial@@@Z
// EA  : 0x82800678
// RVA : 0x00800678
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

idDrawVert *__fastcall idRenderModelGui::AllocTris(
        idRenderModelGui *this,
        int numVerts,
        const unsigned __int16 *indexes,
        int numIndexes,
        const idMaterial *material,
        int a6,
        unsigned __int64 a7)
{
  int v10; // r31
  guiModelSurface_t *surf; // r11
  int v13; // r11
  unsigned int v14; // r6
  unsigned __int16 *v15; // r5
  unsigned __int16 *v16; // r9
  const unsigned __int16 *v17; // r10
  unsigned int v18; // ctr
  int v19; // r7
  const unsigned __int16 *v20; // r10
  int *v21; // r9

  v10 = numIndexes;
  if ( material == nullptr )
    return nullptr;
  if ( numIndexes == 0 )
    return nullptr;
  surf = this->surf;
  if ( surf == nullptr )
    return nullptr;
  LODWORD(a7) = surf->material;
  if ( material != (const idMaterial *)a7 )
  {
    if ( surf->numVerts != 0 )
      idRenderModelGui::AdvanceSurf(this, a2: numVerts, a3: (int)indexes, a4: numIndexes, a5: (int)material, a6: a7);
    this->surf->material = material;
  }
  v13 = idRenderModelGui::numMappedVertices;
  if ( idRenderModelGui::numMappedVertices + numVerts > 25600 || idRenderModelGui::numMappedIndices + v10 + 3 > 40960 )
    return nullptr;
  v14 = 0;
  v15 = &idRenderModelGui::mappedIndices[idRenderModelGui::numMappedIndices];
  if ( v10 - 1 > 0 )
  {
    v16 = v15 - 2;
    v17 = indexes - 1;
    v14 = ((unsigned int)(v10 - 2) >> 1) + 1;
    v18 = v14;
    do
    {
      v19 = v17[1];
      v17 += 2;
      v16 += 2;
      *(_DWORD *)v16 = ((v19 + v13) << 16) | (*v17 + v13);
      --v18;
    }
    while ( v18 != 0 );
  }
  if ( (v10 & 1) != 0 )
  {
    v20 = &indexes[v10];
    v21 = (int *)&v15[2 * v14];
    v10 += 3;
    *v21 = ((*(v20 - 1) + v13) << 16) | (*(v20 - 1) + v13);
    v21[1] = ((*(v20 - 1) + v13) << 16) | (*(v20 - 1) + v13);
  }
  this->surf->numVerts += numVerts;
  this->surf->numIndexes += v10;
  idRenderModelGui::numMappedIndices += v10;
  idRenderModelGui::numMappedVertices += numVerts;
  return &idRenderModelGui::mappedVertices[v13];
}


// ========================================================================
// ?DrawTris@idRenderModelGui@@QAAXPBVidDrawVert@@HPBGHPBVidMaterial@@@Z
// EA  : 0x82800808
// RVA : 0x00800808
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::DrawTris(
        idRenderModelGui *this,
        const idDrawVert *verts,
        int numVerts,
        const unsigned __int16 *indexes,
        int numIndexes,
        const idMaterial *material,
        unsigned __int64 a7)
{
  idDrawVert *v9; // r3
  int v12; // ctr

  v9 = idRenderModelGui::AllocTris(this, numVerts, indexes, numIndexes, material, a6: (int)material, a7);
  _R11 = v9;
  if ( v9 != nullptr && numVerts > 0 )
  {
    v12 = numVerts;
    _R8 = 16;
    _R10 = (char *)((char *)verts - (char *)v9);
    _R7 = 16;
    do
    {
      _R9 = (char *)_R11 + (_DWORD)_R10;
      __asm
      {
        lvx128    v63, r10, r11
        lvx128    v62, r9, r8
        stvx128   v63, r0, r11
        stvx128   v62, r11, r7
      }
      ++_R11;
      --v12;
    }
    while ( v12 != 0 );
  }
}


// ========================================================================
// ?DrawStretchPic@idRenderModelGui@@QAAXABVidVec4@@000PBVidMaterial@@@Z
// EA  : 0x82800890
// RVA : 0x00800890
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::DrawStretchPic(
        idRenderModelGui *this,
        const idVec4 *topLeft,
        const idVec4 *topRight,
        const idVec4 *bottomRight,
        const idVec4 *bottomLeft,
        const idMaterial *material,
        unsigned __int64 a7)
{
  guiModelSurface_t *surf; // r11
  int v15; // r9
  int v16; // r5
  unsigned int currentVertexColor; // r6
  double x; // fp13
  double y; // fp11
  double z; // fp10
  double w; // fp12
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6
  double v34; // fp5
  double v35; // fp4
  double v36; // fp3
  double v37; // fp2
  double v38; // fp1
  double v39; // fp13
  double v40; // fp12
  int v41; // ctr
  double v43; // fp11
  unsigned __int16 *v47; // r11
  float v48[4]; // [sp+50h] [-E0h] BYREF
  float v49; // [sp+60h] [-D0h] BYREF
  char v50; // [sp+68h] [-C8h]
  char v51; // [sp+69h] [-C7h]
  char v52; // [sp+6Ah] [-C6h]
  char v53; // [sp+6Bh] [-C5h]
  char v54; // [sp+6Ch] [-C4h]
  char v55; // [sp+6Dh] [-C3h]
  char v56; // [sp+6Eh] [-C2h]
  char v57; // [sp+6Fh] [-C1h]
  float v58[6]; // [sp+70h] [-C0h] BYREF
  char v59; // [sp+88h] [-A8h]
  char v60; // [sp+89h] [-A7h]
  char v61; // [sp+8Ah] [-A6h]
  char v62; // [sp+8Bh] [-A5h]
  char v63; // [sp+8Ch] [-A4h]
  char v64; // [sp+8Dh] [-A3h]
  char v65; // [sp+8Eh] [-A2h]
  char v66; // [sp+8Fh] [-A1h]
  float v67[6]; // [sp+90h] [-A0h] BYREF
  char v68; // [sp+A8h] [-88h]
  char v69; // [sp+A9h] [-87h]
  char v70; // [sp+AAh] [-86h]
  char v71; // [sp+ABh] [-85h]
  char v72; // [sp+ACh] [-84h]
  char v73; // [sp+ADh] [-83h]
  char v74; // [sp+AEh] [-82h]
  char v75; // [sp+AFh] [-81h]
  float v76[6]; // [sp+B0h] [-80h] BYREF
  char v77; // [sp+C8h] [-68h]
  char v78; // [sp+C9h] [-67h]
  char v79; // [sp+CAh] [-66h]
  char v80; // [sp+CBh] [-65h]
  char v81; // [sp+CCh] [-64h]
  char v82; // [sp+CDh] [-63h]
  char v83; // [sp+CEh] [-62h]
  char v84; // [sp+CFh] [-61h]

  if ( material != nullptr )
  {
    surf = this->surf;
    if ( surf != nullptr )
    {
      LODWORD(a7) = surf->material;
      if ( material != (const idMaterial *)a7 )
      {
        if ( surf->numVerts != 0 )
          idRenderModelGui::AdvanceSurf(
            this,
            a2: (int)topLeft,
            a3: (int)topRight,
            a4: (int)bottomRight,
            a5: (int)bottomLeft,
            a6: a7);
        this->surf->material = material;
      }
      v15 = idRenderModelGui::numMappedVertices;
      v16 = idRenderModelGui::numMappedIndices;
      if ( idRenderModelGui::numMappedVertices + 4 > 25600 || idRenderModelGui::numMappedIndices + 6 > 40960 )
      {
        if ( r_guiDebug.valueInteger != 0 )
          idLib::Printf(fmt: "idRenderModelGui::DrawStretchPic() - Too many verts or indices. NOT DRAWING.\n");
      }
      else
      {
        __asm { vspltisw128 v63, 0 }
        idRenderModelGui::numMappedIndices += 6;
        _R6 = v48;
        idRenderModelGui::numMappedVertices += 4;
        _R10 = 16;
        __asm { vor128    v62, v95, v63 }
        _R4 = v48;
        __asm { vor128    v61, v95, v63 }
        __asm { vor128    v60, v95, v63 }
        _R7 = v58;
        __asm
        {
          vcmpequw128 v53, v95, v63
          vcmpequw128 v59, v94, v62
        }
        _R26 = v58;
        __asm { vcmpequw128 v58, v93, v61 }
        _R25 = v67;
        __asm { vcmpequw128 v57, v92, v60 }
        _R24 = v67;
        _R23 = v76;
        __asm
        {
          vsldoi128 v56, v94, v59, 4
          vsldoi128 v55, v93, v58, 4
          vsldoi128 v54, v92, v57, 4
        }
        this->surf->numVerts += 4;
        this->surf->numIndexes += 6;
        __asm
        {
          stvx128   v62, r0, r6
          stvx128   v56, r4, r10
        }
        currentVertexColor = this->currentVertexColor;
        x = topLeft->x;
        y = topLeft->y;
        z = topLeft->z;
        w = topLeft->w;
        v57 = HIBYTE(currentVertexColor);
        v56 = BYTE1(currentVertexColor);
        v48[0] = x;
        v55 = BYTE2(currentVertexColor);
        v49 = w;
        v48[3] = z;
        v53 = 127;
        v48[1] = y;
        v54 = currentVertexColor;
        v48[2] = 0.0;
        v52 = 127;
        v51 = 127;
        v50 = 127;
        __asm
        {
          stvx128   v61, r0, r7
          stvx128   v55, r26, r10
        }
        v30 = topRight->x;
        v31 = topRight->w;
        v66 = HIBYTE(currentVertexColor);
        v32 = topRight->y;
        v65 = BYTE1(currentVertexColor);
        v58[3] = topRight->z;
        v64 = BYTE2(currentVertexColor);
        v63 = currentVertexColor;
        v58[1] = v32;
        v62 = 127;
        v58[0] = v30;
        v61 = 127;
        v58[4] = v31;
        v60 = 127;
        v58[2] = 0.0;
        v59 = 127;
        __asm
        {
          stvx128   v60, r0, r25
          stvx128   v54, r24, r10
          vsldoi128 v52, v95, v53, 4
        }
        _R4 = v76;
        v34 = bottomRight->y;
        v35 = bottomRight->z;
        v36 = bottomRight->w;
        v37 = bottomRight->x;
        v75 = HIBYTE(currentVertexColor);
        v74 = BYTE1(currentVertexColor);
        v67[3] = v35;
        v73 = BYTE2(currentVertexColor);
        v67[1] = v34;
        v71 = 127;
        v67[0] = v37;
        v70 = 127;
        v67[4] = v36;
        v69 = 127;
        v67[2] = 0.0;
        v68 = 127;
        v72 = currentVertexColor;
        __asm
        {
          stvx128   v63, r0, r23
          stvx128   v52, r4, r10
        }
        v38 = bottomLeft->w;
        v39 = bottomLeft->x;
        v40 = bottomLeft->y;
        v41 = 4;
        _R8 = 16;
        v80 = 127;
        v79 = 127;
        v78 = 127;
        v77 = 127;
        v43 = bottomLeft->z;
        _R11 = &idRenderModelGui::mappedVertices[v15];
        v76[0] = v39;
        _R7 = (char *)((char *)v48 - (char *)_R11);
        v76[1] = v40;
        v76[3] = v43;
        v84 = HIBYTE(currentVertexColor);
        v76[4] = v38;
        v83 = BYTE1(currentVertexColor);
        v76[2] = 0.0;
        v82 = BYTE2(currentVertexColor);
        v81 = currentVertexColor;
        _R10 = (char *)((char *)&v49 - (char *)_R11);
        do
        {
          __asm
          {
            lvx128    v51, r7, r11
            stvx128   v51, r0, r11
            lvx128    v50, r10, r11
            stvx128   v50, r11, r8
          }
          ++_R11;
          --v41;
        }
        while ( v41 != 0 );
        v47 = &idRenderModelGui::mappedIndices[v16];
        *(_DWORD *)v47 = ((v15 + 3) << 16) | v15;
        *((_DWORD *)v47 + 1) = ((v15 + 2) << 16) | (v15 + 2);
        *((_DWORD *)v47 + 2) = (v15 << 16) | (v15 + 1);
      }
    }
    else if ( r_guiDebug.valueInteger != 0 )
    {
      idLib::Printf(fmt: "idRenderModelGui::DrawStretchPic() - Surf is NULL. NOT DRAWING.\n");
    }
  }
  else if ( r_guiDebug.valueInteger != 0 )
  {
    idLib::Printf(fmt: "idRenderModelGui::DrawStretchPic() - Material is NULL. NOT DRAWING.\n");
  }
}


// ========================================================================
// ?GetStringWidth@idRenderModelGui@@QBAHPBDM@Z
// EA  : 0x82800C20
// RVA : 0x00800C20
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

int __fastcall idRenderModelGui::GetStringWidth(idRenderModelGui *this, const char *string, double scale)
{
  unsigned int v3; // r10
  char v4; // r11

  v3 = 0;
  while ( *string != 0 )
  {
    if ( *string != 94 || string[1] == 0 || (v4 = 1, string[1] == 32) )
      v4 = 0;
    if ( v4 != 0 )
    {
      string += 2;
    }
    else
    {
      ++string;
      ++v3;
    }
  }
  return (int)(float)((float)((float)__SPAIR64__((idCVar *)&r_cuttablemodel_freecpudata.description, v3)
                            * SMALLCHAR_WIDTH)
                    * (float)scale);
}


// ========================================================================
// ?GetStringHeight@idRenderModelGui@@QBAHM@Z
// EA  : 0x82800CC0
// RVA : 0x00800CC0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

int __fastcall idRenderModelGui::GetStringHeight(idRenderModelGui *this, double scale)
{
  return (int)(float)(SMALLCHAR_HEIGHT * (float)scale);
}


// ========================================================================
// ?SetupMonospaceFont@idRenderModelGui@@QAAXM@Z
// EA  : 0x82800CE0
// RVA : 0x00800CE0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::SetupMonospaceFont(
        idRenderModelGui *this,
        double drawWidth,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  const glyphInfo_t *Glyph; // r29
  __int128 v10; // r9
  __int64 v11; // r5
  unsigned int MaterialHeight; // r3
  __int64 v13; // r9
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  int v18; // [sp+18h] [-68h]
  unsigned int v19; // [sp+1Ch] [-64h]

  SMALLCHAR_WIDTH = drawWidth;
  Glyph = idFont::GetGlyph(
            this: (idFont *)monospaceFont.r,
            idx: 0x41u,
            a3: a4,
            a4: a5,
            a5: a6,
            a6: a7,
            a7: a8,
            a8: a9,
            a9: v14,
            a10: v15,
            a11: v16,
            a12: v17,
            a13: v18,
            a14: v19);
  LODWORD(v10) = idFont::GetPointSize(this: (idFont *)monospaceFont.r);
  DWORD2(v10) = Glyph->xSkip;
  DWORD1(v10) = &r_cuttablemodel_freecpudata.description;
  SMALLCHAR_HEIGHT = (float)((float)(__int64)v10 * SMALLCHAR_WIDTH) / (float)*(__int64 *)((char *)&v10 + 4);
  LODWORD(v11) = Glyph->xSkip;
  useScale = SMALLCHAR_WIDTH / (float)v11;
  fontWidth = idFont::GetMaterialWidth(this: (idFont *)monospaceFont.r);
  MaterialHeight = idFont::GetMaterialHeight(this: (idFont *)monospaceFont.r);
  LODWORD(v13) = fontWidth;
  fontHeight = MaterialHeight;
  oneOverWidth = (float)1.0 / (float)v13;
  oneOverHeight = (float)1.0 / (float)__SPAIR64__(fontWidth, MaterialHeight);
}


// ========================================================================
// ??0idRenderModelGui@@QAA@XZ
// EA  : 0x82800DE8
// RVA : 0x00800DE8
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

idRenderModelGui *__fastcall idRenderModelGui::idRenderModelGui(idRenderModelGui *this)
{
  __int64 v2; // r28
  char v3; // r11
  char v4; // r9
  __int64 v5; // r10

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelGui_vtbl *)&idRenderModelGui::`vftable';
  `eh vector constructor iterator'(
    ptr: &this->triangles,
    size: 0x84u,
    count: 256,
    pCtor: (void (__fastcall *)(void *))idTriangles::idTriangles,
    pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
  idRenderModel::SetName(this, name_: "_guiModel");
  this->frameNum = 0;
  this->surf = nullptr;
  this->currentVertexColor = 0;
  this->numGuiSurfaces = 0;
  this->useVirtualSize = false;
  this->waitForFrame = 0;
  HIDWORD(v2) = renderSystem->GetWidth(this: renderSystem);
  if ( SHIDWORD(v2) <= 0 )
    HIDWORD(v2) = 1280;
  LODWORD(v2) = renderSystem->GetHeight(this: renderSystem);
  if ( (int)v2 <= 0 )
    LODWORD(v2) = 720;
  v3 = *((_BYTE *)&this->g + 106);
  v4 = *((_BYTE *)&this->g + 105);
  this->useDeferredPosition = false;
  *((_BYTE *)&this->g + 106) = v3 | 0x80;
  *((_BYTE *)&this->g + 105) = v4 | 0xC0;
  idRenderModel::SetAxis(this, a: &mat3_identity);
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
  {
    this->g.origin.x = -1.0;
    this->g.origin.y = 1.0;
    this->g.origin.z = 0.0;
  }
  LODWORD(v5) = HIDWORD(v2);
  this->deferredOrigin.x = -1.0;
  this->deferredOrigin.y = 1.0;
  this->deferredOrigin.z = 0.0;
  this->g.scale.z = 1.0;
  this->g.scale.y = (float)-2.0 / (float)v2;
  this->g.scale.x = (float)2.0 / (float)v5;
  idRenderModelGui::SetViewport(this, x: 0, y: 0, width: HIDWORD(v2), height: v2);
  idRenderModel::SetMaxSurfaces(this, max: 256);
  return this;
}


// ========================================================================
// __unwind$232038
// EA  : 0x82800FC4
// RVA : 0x00800FC4
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _unwind_232038()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$232039
// EA  : 0x82800FEC
// RVA : 0x00800FEC
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _unwind_232039()
{
  int v0; // r12

  idArray<idTriangles,256>::~idArray<idTriangles,256>(this: (idArray<idTriangles,256> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                       + 0x2000));
}


// ========================================================================
// ?Clear@idRenderModelGui@@QAAX_K@Z
// EA  : 0x82801018
// RVA : 0x00801018
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelGui::Clear(idRenderModelGui *this, int a2, unsigned __int64 bits, int a4)
{
  unsigned __int64 v4; // r27
  idRenderModelGui *v5; // r29
  int v6; // r4
  unsigned __int64 v7; // r10 OVERLAPPED
  int *p_waitForFrame; // r31
  int v9; // r28
  char *v10; // r11
  double v11; // r4
  int v12; // r4
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r4
  guiModelSurface_t *surf; // r11

  LODWORD(v7) = 0;
  v5 = this;
  this->numGuiSurfaces = 0;
  LODWORD(v4) = v6;
  HIDWORD(v7) = idLib::headless;
  if ( !idLib::headless )
  {
    p_waitForFrame = &this->waitForFrame;
    v9 = Sys_Microseconds() >> 32;
    if ( idRenderModelGui::frameCount < v5->waitForFrame )
    {
      do
        mgthread_sleep(ms: 1);
      while ( (unsigned int)((Sys_Microseconds() >> 32) - v9) <= 0x3E80
           && idRenderModelGui::frameCount < *p_waitForFrame );
    }
    *(_QWORD *)(&this - 1) = Sys_Microseconds();
    if ( (int)this - v9 > 5000 )
    {
      v10 = (char *)this - v9;
      v11 = (float)((float)*(__int64 *)((char *)&v7 - 4) * (float)0.001);
      idLib::Warning(fmt: (const char *)HIDWORD(v11), LODWORD(v11));
    }
  }
  idRenderModelGui::AdvanceSurf(this: v5, a2: v12, a3: SHIDWORD(bits), a4: bits, a5: a4, a6: v7);
  surf = v5->surf;
  if ( surf != nullptr && (_DWORD)v4 != LODWORD(surf->extraGLState) )
  {
    if ( surf->numVerts != 0 )
      idRenderModelGui::AdvanceSurf(this: v5, a2: v16, a3: v15, a4: v14, a5: v13, a6: surf->extraGLState);
    v5->surf->extraGLState = v4;
  }
}


// ========================================================================
// ?UpdateInView@idRenderModelGui@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x82801118
// RVA : 0x00801118
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

int __fastcall idRenderModelGui::UpdateInView(
        idRenderModelGui *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int v5; // r29
  int v6; // r31
  idRenderModelSurface *v7; // r11

  v5 = 0;
  if ( this->surfaces.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->surfaces.list[v6];
      if ( v7 != nullptr && v7->material != nullptr )
        idVirtualTextureSystem::LoadMaterialPagesInBackground(this: &virtualTextureSystem, mtr: v7->material, lod: 0);
      ++v5;
      ++v6;
    }
    while ( v5 < this->surfaces.num );
  }
  return 1;
}


// ========================================================================
// ?DrawFilled@idRenderModelGui@@QAAXABVidVec4@@MMMM@Z
// EA  : 0x82801188
// RVA : 0x00801188
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::DrawFilled(
        idRenderModelGui *this,
        const idVec4 *color,
        double x,
        double y,
        double w,
        double h)
{
  unsigned int currentVertexColor; // r30
  unsigned __int64 v12; // r10
  idVec4 v13; // [sp+50h] [-80h] BYREF
  idVec4 v14; // [sp+60h] [-70h] BYREF
  idVec4 v15; // [sp+70h] [-60h] BYREF
  idVec4 v16; // [sp+80h] [-50h] BYREF

  currentVertexColor = this->currentVertexColor;
  this->currentVertexColor = idColor::PackColor(color);
  LODWORD(v12) = 0x82000000;
  v13.x = x;
  v15.y = y;
  HIDWORD(v12) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  v13.y = (float)y + (float)h;
  v13.z = 0.0;
  v13.w = 1.0;
  v14.z = 1.0;
  v14.w = 1.0;
  v15.z = 1.0;
  v15.w = 0.0;
  v14.x = (float)x + (float)w;
  v14.y = v13.y;
  v15.x = v14.x;
  v16.x = x;
  v16.y = y;
  v16.z = 0.0;
  v16.w = 0.0;
  idRenderModelGui::DrawStretchPic(
    this,
    topLeft: &v16,
    topRight: &v15,
    bottomRight: &v14,
    bottomLeft: &v13,
    material: (const idMaterial *)whiteShader.r,
    a7: v12);
  this->currentVertexColor = currentVertexColor;
}


// ========================================================================
// ?DrawPic@idRenderModelGui@@QAAXMMPBVidMaterial@@@Z
// EA  : 0x82801268
// RVA : 0x00801268
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::DrawPic(
        idRenderModelGui *this,
        double x,
        double y,
        const idMaterial *material,
        int a5,
        const idMaterial *a6)
{
  __int64 v10; // r11
  int Height; // r3
  idVec4 v12; // [sp+50h] [-70h] BYREF
  idVec4 v13; // [sp+60h] [-60h] BYREF
  idVec4 v14; // [sp+70h] [-50h] BYREF
  idVec4 v15; // [sp+80h] [-40h] BYREF

  v14.x = x;
  LODWORD(v10) = idMaterial::GetWidth(this: a6);
  v14.z = 0.0;
  v14.w = 1.0;
  v15.x = (float)v10 + (float)x;
  v15.z = 1.0;
  v15.w = 1.0;
  v12.x = v15.x;
  Height = idMaterial::GetHeight(this: a6);
  v12.y = y;
  v12.z = 1.0;
  v12.w = 0.0;
  v13.x = x;
  v13.y = y;
  v13.z = 0.0;
  v13.w = 0.0;
  v14.y = (float)__SPAIR64__(0x82000000, Height) + (float)y;
  v15.y = v14.y;
  idRenderModelGui::DrawStretchPic(
    this,
    topLeft: &v13,
    topRight: &v12,
    bottomRight: &v15,
    bottomLeft: &v14,
    material: a6,
    a7: __PAIR64__(0x82000000, Height));
}


// ========================================================================
// ?DrawChar@idRenderModelGui@@QAAXMMHM@Z
// EA  : 0x82801368
// RVA : 0x00801368
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelGui::DrawChar(
        idRenderModelGui *this,
        double x,
        double y,
        int character,
        double scale,
        int a6,
        unsigned int a7)
{
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int v18; // r4
  double v19; // fp30
  const glyphInfo_t *Glyph; // r7
  double v21; // fp29
  unsigned int width; // r11
  unsigned int height; // r9
  __int128 v24; // r11 OVERLAPPED
  __int128 v25; // r7
  char top; // r30
  __int64 v27; // fp5
  __int64 v28; // fp10
  const idMaterial *Material; // r3
  unsigned __int64 v30; // r10
  int v31; // [sp+8h] [-128h]
  int v32; // [sp+Ch] [-124h]
  int v33; // [sp+10h] [-120h]
  int v34; // [sp+14h] [-11Ch]
  int v35; // [sp+18h] [-118h]
  unsigned int v36; // [sp+1Ch] [-114h]
  __int64 v37; // [sp+50h] [-E0h]
  idVec4 v38; // [sp+60h] [-D0h] BYREF
  idVec4 v39; // [sp+70h] [-C0h] BYREF
  idVec4 v40; // [sp+80h] [-B0h] BYREF
  idVec4 v41; // [sp+90h] [-A0h] BYREF

  if ( idFont::GetMaterialWidth(this: (idFont *)monospaceFont.r) != fontWidth
    || idFont::GetMaterialHeight(this: (idFont *)monospaceFont.r) != fontHeight )
  {
    idRenderModelGui::SetupMonospaceFont(
      this,
      drawWidth: SMALLCHAR_WIDTH,
      a3: v18,
      a4: v17,
      a5: v16,
      a6: v15,
      a7: v14,
      a8: v13,
      a9: v12);
  }
  v19 = (float)(SMALLCHAR_HEIGHT + (float)y);
  Glyph = idFont::GetGlyph(
            this: (idFont *)monospaceFont.r,
            idx: a7,
            a3: v17,
            a4: v16,
            a5: v15,
            a6: v14,
            a7: v13,
            a8: v12,
            a9: v31,
            a10: v32,
            a11: v33,
            a12: v34,
            a13: v35,
            a14: v36);
  v21 = (float)(useScale * (float)scale);
  width = Glyph->width;
  height = Glyph->height;
  DWORD2(v24) = Glyph->s;
  *(_QWORD *)((char *)&v25 + 4) = __PAIR64__(0x82000000, height);
  v37 = __PAIR64__((unsigned int)monospaceFont.r, width);
  BYTE3(v25) = Glyph->left;
  *(_QWORD *)&v41.x = __PAIR64__(0x82000000, height);
  top = Glyph->top;
  HIDWORD(v24) = Glyph->t;
  v27 = __PAIR64__(0x82000000, height);
  DWORD2(v25) = DWORD2(v24) + width;
  *(_QWORD *)&v39.x = *(_QWORD *)((char *)&v25 + 4);
  DWORD2(v25) = Glyph->xSkip;
  LODWORD(v25) = top;
  DWORD1(v24) = HIDWORD(v24) + height;
  LODWORD(v24) = DWORD1(v24);
  v28 = *(_QWORD *)((char *)&v24 + 4);
  v40.z = (float)((float)*(__int64 *)((char *)&v24 + 4) - (float)0.5) * oneOverWidth;
  DWORD2(v24) = SBYTE3(v25);
  v40.w = (float)((float)(__int64)v24 + (float)0.5) * oneOverHeight;
  v39.z = (float)((float)*(__int64 *)&v39.x + (float)0.5) * oneOverWidth;
  v39.w = v40.w;
  v38.z = v39.z;
  v38.w = (float)((float)*(__int64 *)((char *)&v24 + 12) - (float)0.5) * oneOverHeight;
  v41.z = (float)((float)v28 - (float)0.5) * oneOverWidth;
  v40.x = (float)((float)((float)((float)((float)(SMALLCHAR_WIDTH / useScale) - (float)*(__int64 *)((char *)&v25 + 4))
                                * (float)0.5)
                        + (float)*(__int64 *)((char *)&v24 + 4))
                * (float)v21)
        + (float)x;
  v38.y = (float)v19 - (float)((float)(__int64)v25 * (float)v21);
  v41.x = v40.x;
  v41.y = v38.y;
  v41.w = v38.w;
  v40.y = v38.y + (float)((float)v21 * (float)((float)v27 + (float)1.0));
  v39.y = v40.y;
  v39.x = v40.x + (float)((float)v21 * (float)((float)v37 + (float)1.0));
  v38.x = v39.x;
  Material = idFont::GetMaterial(this: (idFont *)monospaceFont.r);
  idRenderModelGui::DrawStretchPic(
    this,
    topLeft: &v41,
    topRight: &v38,
    bottomRight: &v39,
    bottomLeft: &v40,
    material: Material,
    a7: v30);
}


// ========================================================================
// ?DrawString@idRenderModelGui@@QAAXMMPBDABVidVec4@@_NM@Z
// EA  : 0x828015B8
// RVA : 0x008015B8
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __fastcall idRenderModelGui::DrawString(
        idRenderModelGui *this,
        double x,
        double y,
        const char *string,
        const idVec4 *defaultColor,
        unsigned __int8 *forceColor,
        double scale,
        const idVec4 *a8,
        char a9)
{
  int v16; // r5
  int v17; // r4
  char v18; // r11
  int v19; // r3
  idVec4 *v20; // r3
  double w; // fp0
  idVec4 v22; // [sp+50h] [-60h] BYREF

  this->currentVertexColor = idColor::PackColor(color: a8);
  if ( *forceColor != 0 )
  {
    while ( 1 )
    {
      if ( *forceColor != 94 || forceColor[1] == 0 || (v18 = 1, forceColor[1] == 32) )
        v18 = 0;
      if ( v18 == 0 )
      {
        idRenderModelGui::DrawChar(this, x, y, character: v17, scale, a6: v16, a7: *forceColor++);
        x = (float)((float)(SMALLCHAR_WIDTH * (float)scale) + (float)x);
        goto LABEL_13;
      }
      if ( a9 != 0 )
        goto LABEL_11;
      v19 = (char)forceColor[1];
      if ( v19 != 48 )
        break;
      this->currentVertexColor = idColor::PackColor(color: a8);
      forceColor += 2;
LABEL_13:
      if ( *forceColor == 0 )
        goto LABEL_14;
    }
    v20 = idStr::ColorForIndex(i: v19);
    w = a8->w;
    v22.x = v20->x;
    v22.y = v20->y;
    v22.z = v20->z;
    v22.w = w;
    this->currentVertexColor = idColor::PackColor(color: &v22);
LABEL_11:
    forceColor += 2;
    goto LABEL_13;
  }
LABEL_14:
  this->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&idColor::colorWhite);
}


// ========================================================================
// ?CommitSubclass@idRenderModelGui@@EAA_NXZ
// EA  : 0x82801858
// RVA : 0x00801858
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

int __fastcall idRenderModelGui::CommitSubclass(idRenderModelGui *this)
{
  idList<idRenderModelSurface,85> *p_surfaces; // r25
  int numGuiSurfaces; // r8
  int frameNum; // r5
  int *p_numVerts; // r31
  int v7; // r4
  int v8; // r23
  idArray<idTriangles,256> *p_triangles; // r30
  idRenderModelSurface *v10; // r21
  unsigned __int64 v11; // r10

  p_surfaces = &this->surfaces;
  if ( this->surfaces.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  p_surfaces->num = __CFADD__(-p_surfaces->size, p_surfaces->size ^ 0x80000000) ? 0 : p_surfaces->size;
  numGuiSurfaces = this->numGuiSurfaces;
  frameNum = this->frameNum;
  this->waitForFrame = frameNum + 1;
  if ( numGuiSurfaces <= 0 )
    return 0;
  p_numVerts = &this->guiSurfaces.ptr[0].numVerts;
  if ( this->guiSurfaces.ptr[0].numVerts != 0 )
  {
    if ( idRenderModelGui::frameCount != frameNum )
      idLib::Warning(
        fmt: "idRenderModelGui::CommitSubclass: framenu missmatch %d, %d",
        idRenderModelGui::frameCount,
        frameNum);
    v7 = this->numGuiSurfaces;
    if ( v7 > p_surfaces->size )
      idList<idRenderModelSurface,85>::Resize(this: p_surfaces, newsize: v7);
    v8 = 0;
    if ( this->numGuiSurfaces > 0 )
    {
      p_triangles = &this->triangles;
      do
      {
        if ( *p_numVerts != 0 && *(p_numVerts - 1) != 0 )
        {
          v10 = idList<idRenderModelSurface,85>::Alloc(this: p_surfaces);
          v10->material = (const idMaterial *)*(p_numVerts - 1);
          v11 = *(_QWORD *)(p_numVerts - 3);
          v10->geometry = (idTriangles *)p_triangles;
          v10->extraGLState = v11;
          v10->geometryIsReference = true;
          p_triangles->ptr[0].numVerts = *p_numVerts;
          v10->geometry->numIndexes = p_numVerts[2];
          idVertexBuffer::Reference(
            this: &v10->geometry->vertexBuffer,
            other: &idRenderModelGui::vertexBuffer.ptr[idRenderModelGui::mappedBufferIndex]);
          idIndexBuffer::Reference(
            this: &v10->geometry->indexBuffer,
            other: &idRenderModelGui::indexBuffer.ptr[idRenderModelGui::mappedBufferIndex],
            refOffset: 2 * p_numVerts[1],
            refSize: 2 * p_numVerts[2]);
        }
        ++v8;
        p_numVerts += 6;
        p_triangles = (idArray<idTriangles,256> *)((char *)p_triangles + 132);
      }
      while ( v8 < this->numGuiSurfaces );
    }
    this->numGuiSurfaces = 0;
  }
  return 1;
}


// ========================================================================
// `dynamic initializer for 'idRenderModelGui::vertexBuffer''
// EA  : 0x83343A80
// RVA : 0x01343A80
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelGui::vertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)&idRenderModelGui::vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelGui::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelGui::indexBuffer''
// EA  : 0x83343AD0
// RVA : 0x01343AD0
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelGui::indexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)&idRenderModelGui::indexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelGui::indexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'whiteShader''
// EA  : 0x83343B20
// RVA : 0x01343B20
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _dynamic_initializer_for__whiteShader__()
{
  whiteShader.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &whiteShader;
}


// ========================================================================
// `dynamic initializer for 'monospaceFont''
// EA  : 0x83343B40
// RVA : 0x01343B40
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _dynamic_initializer_for__monospaceFont__()
{
  monospaceFont.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &monospaceFont;
  monospaceFont.name = idFont::DEFAULT_FONT;
}


// ========================================================================
// `dynamic initializer for 'progGuiBlend''
// EA  : 0x83343B70
// RVA : 0x01343B70
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void _dynamic_initializer_for__progGuiBlend__()
{
  progGuiBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progGuiBlend;
}


// ========================================================================
// `dynamic initializer for 'r_guiDebug''
// EA  : 0x83343B90
// RVA : 0x01343B90
// PDB : w:\tech5\engine\models\rendermodelgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_guiDebug__()
{
  idCVar::idCVar(
    this: &r_guiDebug,
    name: "r_guiDebug",
    value: "0",
    flags: 1,
    description: "Provides debug output in idRenderModelGui code",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_guiDebug__);
}

