
// ========================================================================
// ?FreeData@idAmbientLighting@@AAAXXZ
// EA  : 0x828A35C8
// RVA : 0x008A35C8
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void __fastcall idAmbientLighting::FreeData(idAmbientLighting *this)
{
  if ( this->ambientMap->data != nullptr )
  {
    idMem::Free(this: &mem, ptr: this->ambientMap->data, align: ALIGN_16);
    this->ambientMap->data = nullptr;
    this->ambientMap->samples = nullptr;
    this->ambientMap->nodes = nullptr;
  }
}


// ========================================================================
// ??0idAmbientLighting@@QAA@XZ
// EA  : 0x828A3630
// RVA : 0x008A3630
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

idAmbientLighting *__fastcall idAmbientLighting::idAmbientLighting(idAmbientLighting *this)
{
  ambientMap_t *v2; // r3
  ambientMap_t *v3; // r29
  ambientMap_t *v4; // r11

  v2 = (ambientMap_t *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x24u,
                         tag: TAG_RENDERER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    memset(Dst: &v2->forcedColors, Val: 0, Size: sizeof(v2->forcedColors));
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  this->ambientMap = v4;
  v4->data = nullptr;
  this->ambientMap->dataLen = 0;
  this->ambientMap->useForcedColors = false;
  this->ambientMap->nodes = nullptr;
  this->ambientMap->samples = nullptr;
  return this;
}


// ========================================================================
// ??1idAmbientLighting@@QAA@XZ
// EA  : 0x828A36C8
// RVA : 0x008A36C8
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void __fastcall idAmbientLighting::~idAmbientLighting(idAmbientLighting *this)
{
  ambientHeader_t *data; // r10

  data = this->ambientMap->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->ambientMap->data = nullptr;
    this->ambientMap->samples = nullptr;
    this->ambientMap->nodes = nullptr;
  }
  idMem::Free(this: &mem, ptr: this->ambientMap, align: ALIGN_16);
}


// ========================================================================
// ?DebugDrawAmbientLightingSamples@idAmbientLighting@@QBAXPAVidRenderWorldLocal@@ABVidVec3@@@Z
// EA  : 0x828A3750
// RVA : 0x008A3750
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAmbientLighting::DebugDrawAmbientLightingSamples(
        idAmbientLighting *this,
        idRenderWorldLocal *rw,
        const idVec3 *pos)
{
  ambientMap_t *ambientMap; // r29
  ambientSample_t *v6; // r30
  int i; // r31
  __int64 v8; // r9
  __int128 v9; // r4
  __int64 v10; // r11
  double v11; // fp7
  idRenderWorldLocal_vtbl *v12; // r7
  double v13; // fp2
  int v14; // r31
  __int16 *v15; // r30
  __int64 v16; // r10 OVERLAPPED
  __int16 v17; // r5
  __int16 v18; // r7
  __int64 v19; // r7
  int v20; // r11
  idRenderWorldLocal_vtbl *v21; // r8
  double v22; // fp3
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r11
  double v24; // fp13
  float v25; // [sp+60h] [-160h] BYREF
  float v26; // [sp+64h] [-15Ch] BYREF
  float v27[4]; // [sp+68h] [-158h] BYREF
  float v28[4]; // [sp+78h] [-148h] BYREF
  float v29[6]; // [sp+88h] [-138h] BYREF
  float v30[4]; // [sp+A0h] [-120h] BYREF
  int v31; // [sp+B0h] [-110h] BYREF
  unsigned int v32; // [sp+B4h] [-10Ch]
  unsigned int v33; // [sp+B8h] [-108h]
  int v34; // [sp+BCh] [-104h]
  __int64 v35; // [sp+C0h] [-100h]
  __int16 v36; // [sp+CEh] [-F2h] BYREF
  ambientSample_t v37[10]; // [sp+D0h] [-F0h] BYREF

  ambientMap = this->ambientMap;
  if ( this->ambientMap->data != nullptr )
  {
    v6 = v37;
    for ( i = 7; i >= 0; --i )
      memset(Dst: v6++, Val: 0, Size: 0x12u);
    ambientMap_t::SamplesForPoint(this: ambientMap, worldPoint: pos, cube: &v31, cubeSamples: v37);
    HIDWORD(v8) = allocationCurrent[242];
    LODWORD(v9) = v33;
    HIDWORD(v10) = v34 + v33;
    DWORD2(v9) = v32 + v34;
    LODWORD(v8) = v34 + v33;
    v11 = (double)(__int64)v9;
    v12 = rw->__vftable;
    LODWORD(v10) = v31 + v34;
    v26 = (float)__SPAIR64__(v33, v32);
    v13 = (double)v10;
    HIDWORD(v10) = v12->DebugBounds;
    v27[3] = (float)v8;
    v27[2] = (float)*(__int64 *)((char *)&v9 + 4);
    DWORD2(v9) = v31;
    v25 = (float)*(__int64 *)((char *)&v9 + 4);
    v27[0] = v11;
    v27[1] = v13;
    ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, idVec3 *, int, int))HIDWORD(v10))(
      a1: rw,
      a2: &idColor::colorCyan,
      a3: &v25,
      a4: &vec3_origin,
      a5: 1,
      a6: 1);
    v14 = 0;
    v15 = &v36;
    HIDWORD(v16) = &v25;
    do
    {
      v17 = v15[10];
      v18 = v15[11];
      HIDWORD(v19) = v14 >> 2;
      v15 += 12;
      v20 = v18;
      LODWORD(v19) = v17;
      LODWORD(v16) = *v15;
      v30[0] = idColor::colorRed.r;
      v35 = v19;
      v30[1] = idColor::colorRed.g;
      v30[2] = idColor::colorRed.b;
      v30[3] = idColor::colorRed.a;
      v29[1] = (float)*(__int64 *)((char *)&v16 - 4);
      v21 = rw->__vftable;
      v29[0] = (float)v19;
      v22 = *(&v25 + (v14 & 1) + ((2 * v14) & 2));
      v29[2] = (float)v16;
      DebugLine = v21->DebugLine;
      v24 = v27[3 * ((v14 >> 2) & 1)];
      v28[1] = v27[3 * ((v14 >> 1) & 1) - 1];
      v28[0] = v22;
      v28[2] = v24;
      DebugLine(this: rw, a2: (const idVec4 *)v30, a3: (const idVec3 *)v28, a4: (const idVec3 *)v29, a5: 1, a6: true);
      ++v14;
      HIDWORD(v16) = &v25;
    }
    while ( v14 < 8 );
  }
}


// ========================================================================
// ?DebugDrawColoredCube@idAmbientLighting@@ABAXPAVidRenderWorldLocal@@PBUambientSample_t@@M@Z
// EA  : 0x828A39B8
// RVA : 0x008A39B8
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAmbientLighting::DebugDrawColoredCube(
        idAmbientLighting *this,
        idRenderWorldLocal *rw,
        const ambientSample_t *sample,
        double size)
{
  __int64 v5; // r10
  unsigned __int8 *v8; // r26
  int i; // r27
  unsigned int v10; // r6
  __int64 v11; // r4
  int v12; // r2 OVERLAPPED
  int j; // r30
  __int64 v14; // r9
  int v15; // r11
  __int64 v16; // r11
  __int128 v17; // r7
  int v18; // r3
  idVec3 v19[2]; // [sp+98h] [-A8h] BYREF
  idWinding v20; // [sp+B0h] [-90h] BYREF
  float v21[4]; // [sp+C0h] [-80h] BYREF

  HIDWORD(v5) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  v8 = &sample->colors.channels[0][2];
  for ( i = 0; i < 24; i += 4 )
  {
    v10 = *(v8 - 2);
    v21[3] = 1.0;
    LODWORD(v5) = *v8;
    LODWORD(v11) = *(v8 - 1);
    HIDWORD(v11) = &v20;
    v20.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    memset(&v20.numPoints, 0, 12);
    v21[1] = (float)v11 * (float)0.0039215689;
    v21[2] = (float)v5 * (float)0.0039215689;
    v21[0] = (float)v10 * (float)0.0039215689;
    idWinding::ReAllocate(this: &v20, n: 4, keep: false);
    for ( j = 0; j < 4; ++j )
    {
      HIDWORD(v14) = &cubeSide[0][0][1];
      LODWORD(v14) = sample->origin[2];
      v15 = i + j;
      HIDWORD(v16) = (unsigned __int16)sample->origin[1];
      LODWORD(v17) = sample->origin[0];
      HIDWORD(v17) = v19;
      DWORD2(v17) = cubeSide[0][v15][1];
      DWORD1(v17) = cubeSide[0][v15][2];
      v18 = cubeSide[0][v15][0];
      LODWORD(v16) = SWORD1(v16);
      v19[0].y = (float)((float)*(__int64 *)((char *)&v17 + 4) * (float)size) + (float)v16;
      v19[0].x = (float)((float)*(__int64 *)(&v12 - 1) * (float)size) + (float)(__int64)v17;
      v19[0].z = (float)((float)*(__int64 *)&v17 * (float)size) + (float)v14;
      idWinding::AddPoint(this: &v20, v: v19);
    }
    rw->DebugFilledPolygon(this: rw, a2: (const idVec4 *)v21, a3: &v20, a4: 0, a5: true);
    v20.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    idMem::Free(this: &mem, ptr: v20.p, align: ALIGN_16);
    v8 += 3;
    v20.p = nullptr;
  }
}


// ========================================================================
// __unwind$229752
// EA  : 0x828A3BD4
// RVA : 0x008A3BD4
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void _unwind_229752()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 320 + 176));
}


// ========================================================================
// ?DebugDrawAmbientLightingBoxes@idAmbientLighting@@QBAXPAVidRenderWorldLocal@@_N@Z
// EA  : 0x828A3C00
// RVA : 0x008A3C00
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void __fastcall idAmbientLighting::DebugDrawAmbientLightingBoxes(
        idAmbientLighting *this,
        idRenderWorldLocal *rw,
        bool showForView)
{
  __int64 v6; // r4
  ambientMap_t *ambientMap; // r11
  float *v8; // r29
  int v9; // r31
  float *v10; // r27
  int v11; // r28
  double v12; // fp0
  double v13; // fp13
  double v14; // fp12
  __int64 v15; // r6
  __int64 v16; // r11
  double v17; // fp30
  double v18; // fp31
  double v19; // fp29
  double v20; // fp3
  double v21; // fp5
  double v22; // fp2
  __int64 v23; // r6
  __int64 v24; // r10
  __int64 v25; // r8
  va *v26; // r3
  double v27; // fp7
  double v28; // fp5
  double v29; // fp3
  int x; // r11
  int y; // r11
  int z; // r11
  int v33; // [sp+8h] [-1168h]
  int v34; // [sp+Ch] [-1164h]
  int v35; // [sp+10h] [-1160h]
  int v36; // [sp+14h] [-115Ch]
  int v37; // [sp+18h] [-1158h]
  int v38; // [sp+1Ch] [-1154h]
  idVec3 v39; // [sp+68h] [-1108h] BYREF
  float v40[6]; // [sp+78h] [-10F8h] BYREF
  float v41[4]; // [sp+90h] [-10E0h] BYREF
  __int64 v42; // [sp+A0h] [-10D0h]
  ambientSample_t v43; // [sp+B0h] [-10C0h] BYREF
  __int64 v44; // [sp+C8h] [-10A8h]
  va v45; // [sp+D0h] [-10A0h] BYREF

  if ( this->ambientMap->data != nullptr )
  {
    HIDWORD(v6) = rw->RenderViewForIndex(this: rw, a2: 0);
    ambientMap = this->ambientMap;
    v8 = (float *)HIDWORD(v6);
    v9 = 0;
    if ( this->ambientMap->data->numSamples > 0 )
    {
      v10 = (float *)(HIDWORD(v6) + 2032);
      v11 = 0;
      do
      {
        v12 = v10[1];
        v13 = v10[2];
        HIDWORD(v15) = &ambientMap->samples[v11];
        v14 = *v10;
        LODWORD(v15) = *(__int16 *)(HIDWORD(v15) + 22);
        HIDWORD(v16) = *(unsigned __int16 *)(HIDWORD(v15) + 18);
        LODWORD(v16) = *(__int16 *)(HIDWORD(v15) + 20);
        LODWORD(v6) = SWORD1(v16);
        v42 = v15;
        v44 = v6;
        v17 = (float)v15;
        v18 = (float)v16;
        v19 = (float)v6;
        v20 = (float)((float)v15 - (float)v13);
        v21 = (float)((float)v16 - (float)v12);
        v22 = (float)((float)v6 - (float)v14);
        if ( (float)((float)((float)v22 * (float)v22)
                   + (float)((float)((float)v20 * (float)v20) + (float)((float)v21 * (float)v21))) < 4194304.0 )
        {
          idAmbientLighting::DebugDrawColoredCube(this, rw, sample: (const ambientSample_t *)HIDWORD(v15), size: 6.0);
          v41[0] = 1.0;
          v41[1] = 0.0;
          HIDWORD(v23) = v9;
          v41[2] = 0.0;
          v41[3] = 1.0;
          v40[0] = v19;
          v40[1] = v18;
          v40[2] = (float)v17 + (float)32.0;
          v26 = va::va(
                  this: &v45,
                  fmt: "%i",
                  a3: v23,
                  a4: v25,
                  a5: v24,
                  a6: v33,
                  a7: v34,
                  a8: v35,
                  a9: v36,
                  a10: v37,
                  a11: v38);
          HIDWORD(v6) = ((int (__fastcall *)(idRenderWorldLocal *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, int, double))rw->DebugText)(
                          a1: rw,
                          a2: v26,
                          a3: v40,
                          a4: rw->DebugText,
                          a5: v41,
                          a6: 1,
                          a7: 0,
                          a8: 1,
                          a9: 0.5);
        }
        ambientMap = this->ambientMap;
        ++v9;
        ++v11;
      }
      while ( v9 < this->ambientMap->data->numSamples );
    }
    if ( showForView )
    {
      v27 = v8[508];
      v28 = (float)(v8[511] * (float)128.0);
      v29 = (float)(v8[510] + (float)(v8[513] * (float)128.0));
      v39.y = v8[509] + (float)(v8[512] * (float)128.0);
      v39.z = v29;
      v39.x = (float)v28 + (float)v27;
      idAmbientLighting::DebugDrawAmbientLightingSamples(this, rw, pos: &v39);
      x = (int)v39.x;
      memset(&v43, 0, 18);
      if ( x >= -32768 )
      {
        if ( x > 0x7FFF )
          LOWORD(x) = 0x7FFF;
      }
      else
      {
        LOWORD(x) = 0x8000;
      }
      v43.origin[0] = x;
      y = (int)v39.y;
      if ( y >= -32768 )
      {
        if ( y > 0x7FFF )
          LOWORD(y) = 0x7FFF;
      }
      else
      {
        LOWORD(y) = 0x8000;
      }
      v43.origin[1] = y;
      z = (int)v39.z;
      if ( z >= -32768 )
      {
        if ( z > 0x7FFF )
          LOWORD(z) = 0x7FFF;
      }
      else
      {
        LOWORD(z) = 0x8000;
      }
      v43.origin[2] = z;
      ambientMap_t::AmbientSample(this: this->ambientMap, worldPoint: &v39, lighting: &v43.colors);
      idAmbientLighting::DebugDrawColoredCube(this, rw, sample: &v43, size: 4.0);
    }
  }
}


// ========================================================================
// ?LoadAmbientLighting@idAmbientLighting@@QAAXPAVidRenderWorldLocal@@@Z
// EA  : 0x828A3F18
// RVA : 0x008A3F18
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void __fastcall idAmbientLighting::LoadAmbientLighting(idAmbientLighting *this, idRenderWorldLocal *rw)
{
  ambientHeader_t *data; // r10
  const char *v5; // r3
  idResource *v6; // r3
  idResource *v7; // r29
  ambientHeader_t *v8; // r10
  int trackedMemory; // [sp+50h] [-60h]
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  data = this->ambientMap->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->ambientMap->data = nullptr;
    this->ambientMap->samples = nullptr;
    this->ambientMap->nodes = nullptr;
  }
  if ( rw != nullptr )
  {
    v5 = rw->GetName(this: rw);
    idStr::idStr(this: v10, text: v5);
    idStr::Append(this: v10, text: ".ambient");
    if ( fileSystem->FileExists(this: fileSystem, a2: v10[0].data, a3: false) )
    {
      v6 = idResourceList::Load(
             this: &idFileResource::resourceList,
             name: v10[0].data,
             makeDefault: false,
             skipStaleCheck: false);
      v7 = v6;
      if ( v6 != nullptr && (trackedMemory = v6[1].trackedMemory) > 0 )
      {
        this->ambientMap->dataLen = trackedMemory;
        this->ambientMap->data = (ambientHeader_t *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\engine\\renderer\\AmbientLighting.cpp(127) : TAG_FILE",
                                                      size: this->ambientMap->dataLen,
                                                      tag: TAG_FILE,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
        memcpy(Dst: this->ambientMap->data, Src: v7[1].name.str, Size: v7[1].trackedMemory);
        ((void (__fastcall *)(idResource *, int))v7->dtr_idResource)(a1: v7, a2: 1);
        v8 = this->ambientMap->data;
        if ( v8->magic == 555046657 )
        {
          this->ambientMap->nodes = (ambientNode_t *)&v8[1];
          this->ambientMap->samples = (ambientSample_t *)&this->ambientMap->nodes[this->ambientMap->data->numNodes];
          if ( this->ambientMap->data->numNodes == 0 )
            this->ambientMap->data = nullptr;
          this->ambientMap->useForcedColors = false;
        }
        else
        {
          idLib::Warning(fmt: "idAmbientLighting::LoadAmbientLighting: bad file magic on %s", v10[0].data);
          idAmbientLighting::FreeData(this);
        }
      }
      else
      {
        idLib::Warning(fmt: "idAmbientLighting::LoadAmbientLighting: file not found: %s", v10[0].data);
      }
    }
    idStr::FreeData(this: v10);
  }
}


// ========================================================================
// __unwind$229996
// EA  : 0x828A411C
// RVA : 0x008A411C
// PDB : w:\tech5\engine\renderer\ambientlighting.cpp
// ========================================================================

void _unwind_229996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}

