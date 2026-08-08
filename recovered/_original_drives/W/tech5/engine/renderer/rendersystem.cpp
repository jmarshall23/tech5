
// ========================================================================
// ?GetNumRenderWorlds@idRenderSystemLocal@@UBAHXZ
// EA  : 0x82945CC8
// RVA : 0x00945CC8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::GetNumRenderWorlds(idRenderSystemLocal *this)
{
  idRenderWorldLocal *worlds; // r11
  int result; // r3

  worlds = this->worlds;
  for ( result = 0; worlds != nullptr; ++result )
    worlds = worlds->nextOnWorldList;
  return result;
}


// ========================================================================
// ?RenderWorldForIndex@idRenderSystemLocal@@UBAPAVidRenderWorld@@H@Z
// EA  : 0x82945CF0
// RVA : 0x00945CF0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

idRenderWorld *__fastcall idRenderSystemLocal::RenderWorldForIndex(idRenderSystemLocal *this, int index)
{
  idRenderWorld *result; // r3

  result = this->worlds;
  if ( result == nullptr )
    return nullptr;
  while ( index-- > 0 )
  {
    result = (idRenderWorld *)result[10].__vftable;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?IsEndFrameRenderingInhibited@idRenderSystemLocal@@UBA_NXZ
// EA  : 0x82945D20
// RVA : 0x00945D20
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

BOOL __fastcall idRenderSystemLocal::IsEndFrameRenderingInhibited(idRenderSystemLocal *this)
{
  return this->inhibitRendering != 0;
}


// ========================================================================
// ?AllocRenderWorld@idRenderSystemLocal@@UAAPAVidRenderWorld@@PBD_N@Z
// EA  : 0x82945DA0
// RVA : 0x00945DA0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

idRenderWorldLocal *__fastcall idRenderSystemLocal::AllocRenderWorld(
        idRenderSystemLocal *this,
        const char *mapName,
        BOOL comboMap)
{
  idRenderWorldLocal *v6; // r3
  idRenderWorldLocal *v7; // r30

  v6 = (idRenderWorldLocal *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x22410u,
                               tag: TAG_RENDERWORLD,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    v7 = idRenderWorldLocal::idRenderWorldLocal(this: v6);
  else
    v7 = nullptr;
  v7->InitFromMap(this: v7, a2: mapName, a3: comboMap);
  v7->nextOnWorldList = this->worlds;
  this->worlds = v7;
  return v7;
}


// ========================================================================
// __unwind$233700
// EA  : 0x82945E38
// RVA : 0x00945E38
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_233700()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERWORLD);
}


// ========================================================================
// ?InhibitEndFrameRendering@idRenderSystemLocal@@UAAXH@Z
// EA  : 0x82945E68
// RVA : 0x00945E68
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InhibitEndFrameRendering(idRenderSystemLocal *this, int change)
{
  int inhibitRendering; // r11
  int v3; // r11

  inhibitRendering = this->inhibitRendering;
  if ( change <= -inhibitRendering )
    v3 = 0;
  else
    v3 = inhibitRendering + change;
  this->inhibitRendering = v3;
}


// ========================================================================
// ?LogPerformanceCountersForMap@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82945E90
// RVA : 0x00945E90
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::LogPerformanceCountersForMap(idRenderSystemLocal *this)
{
  idRenderWorldLocal *primaryWorld; // r10
  int v3; // r11
  idFile *v4; // r31
  wrapperStats_t *CurrentStats; // r3
  char *v6; // r10
  int *p_c_drawVertices; // r11
  int i; // ctr
  idFile_vtbl *v9; // r29
  const char *v10; // r3
  char v11; // [sp+4Ch] [-84h] BYREF
  int v12; // [sp+50h] [-80h]
  int v13; // [sp+54h] [-7Ch]
  int v14; // [sp+5Ch] [-74h]
  int v15; // [sp+68h] [-68h]
  int v16; // [sp+6Ch] [-64h]
  int v17; // [sp+70h] [-60h]
  wrapperStats_t v18[2]; // [sp+80h] [-50h] BYREF

  primaryWorld = this->primaryWorld;
  if ( primaryWorld == this->performanceCounterLogWorld )
  {
    v3 = this->performanceCounterLogWorldFrame + 1;
    this->performanceCounterLogWorldFrame = v3;
    if ( v3 == 5 && primaryWorld != nullptr )
    {
      v4 = fileSystem->OpenFileAppend(
             this: fileSystem,
             a2: "rendererPerformanceLogs.txt",
             a3: idLib::production != PROD_PRODUCTION ? 0 : 2);
      if ( v4 != nullptr )
      {
        CurrentStats = GL_GetCurrentStats(result: v18);
        v6 = &v11;
        p_c_drawVertices = &CurrentStats[-1].c_drawVertices;
        for ( i = 9; i != 0; --i )
        {
          ++p_c_drawVertices;
          v6 += 4;
          *(_DWORD *)v6 = *p_c_drawVertices;
        }
        v4->Printf(this: v4, a2: "Version: %s\n", com_version.valueString.data);
        v9 = v4->__vftable;
        v10 = this->primaryWorld->GetName(this: this->primaryWorld);
        v9->Printf(this: v4, a2: "Map: %s\n", v10);
        v4->Printf(this: v4, a2: "%8i\t c_modelCommits\n", this->pc.c_modelCommits);
        v4->Printf(this: v4, a2: "%8i\t c_lightCommits\n", this->pc.c_lightCommits);
        v4->Printf(this: v4, a2: "%8i\t c_modelReferences\n", this->pc.c_modelReferences);
        v4->Printf(this: v4, a2: "%8i\t c_lightReferences\n", this->pc.c_lightReferences);
        v4->Printf(this: v4, a2: "%8i\t c_viewWorldAreas\n", this->pc.c_viewWorldAreas);
        v4->Printf(this: v4, a2: "%8i\t c_viewModels\n", this->pc.c_viewModels);
        v4->Printf(this: v4, a2: "%8i\t c_viewLights\n", this->pc.c_viewLights);
        v4->Printf(this: v4, a2: "%8i\t c_drawElements\n", v15);
        v4->Printf(this: v4, a2: "%8i\t c_drawIndices\n", v16);
        v4->Printf(this: v4, a2: "%8i\t c_drawVertices\n", v17);
        v4->Printf(this: v4, a2: "%8i\t c_queriesIssued\n", v12);
        v4->Printf(this: v4, a2: "%8i\t c_queriesPassed\n", v13);
        v4->Printf(this: v4, a2: "%8i\t c_queriesTooOld\n", v14);
        v4->Printf(
          this: v4,
          a2: "%8i\t GPUTimeMicroSec\n",
          LODWORD(this->pc.endGPUTimeMicroSec) - LODWORD(this->pc.startGPUTimeMicroSec));
        v4->Printf(
          this: v4,
          a2: "%8i\t latchTimeMicroSec\n",
          LODWORD(this->pc.endLatchTimeMicroSec) - LODWORD(this->pc.startLatchTimeMicroSec));
        (*(void (**)(idFile *, const char *, ...))(HIDWORD(this->pc.startCPUTimeMicroSec) + 52))(
          a1: v4,
          a2: "%8i\t CPUTimeMicroSec\n",
          LODWORD(this->pc.endCPUTimeMicroSec) - LODWORD(this->pc.startCPUTimeMicroSec));
        v4->Printf(
          this: v4,
          a2: "%8i\t swapTimeMicroSec\n",
          LODWORD(this->pc.endSwapMicroSec) - LODWORD(this->pc.startSwapMicroSec));
        v4->Printf(this: v4, a2: "------------------------------------------\n");
        ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
      }
    }
  }
  else
  {
    this->performanceCounterLogWorld = primaryWorld;
    this->performanceCounterLogWorldFrame = 0;
  }
}


// ========================================================================
// ?LogMetrics@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82946248
// RVA : 0x00946248
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::LogMetrics(idRenderSystemLocal *this)
{
  bool v2; // r4
  wrapperStats_t *CurrentStats; // r3
  __int64 v4; // r10
  int *p_c_drawVertices; // r11
  int i; // ctr
  bool v7; // r4
  __int64 v8; // r11
  char v9; // [sp+5Ch] [-74h] BYREF
  int v10; // [sp+78h] [-58h]
  int v11; // [sp+7Ch] [-54h]
  BOOL v12; // [sp+80h] [-50h]
  wrapperStats_t v13; // [sp+90h] [-40h] BYREF

  if ( com_logMetrics.valueInteger != 0 )
  {
    CurrentStats = GL_GetCurrentStats(result: &v13);
    LODWORD(v4) = &v9;
    p_c_drawVertices = &CurrentStats[-1].c_drawVertices;
    for ( i = 9; i != 0; --i )
    {
      HIDWORD(v4) = *++p_c_drawVertices;
      LODWORD(v4) = v4 + 4;
      *(_DWORD *)v4 = *p_c_drawVertices;
    }
    LODWORD(v4) = v10;
    idGaugeMetric::Log(this: &this->drawsMetric, x: (float)v4, skipPush: v2);
    idGaugeMetric::Log(this: &this->trisMetric, x: (float)(unsigned int)(v11 / 3), skipPush: v7);
    LODWORD(v8) = v12;
    idGaugeMetric::Log(this: &this->vertsMetric, x: (float)v8, skipPush: v12);
  }
}


// ========================================================================
// ?GetNextRenderView@idRenderSystemLocal@@UAAHQAVidRenderWorld@@@Z
// EA  : 0x82946320
// RVA : 0x00946320
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::GetNextRenderView(idRenderSystemLocal *this, idRenderWorld *const world)
{
  int v2; // r8
  signed int v3; // r7

  v2 = this->frameCount + 1;
  v3 = (signed int)world[13234].__vftable;
  __twllei(v3, 0);
  __twlgei(v3 & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF);
  return v2 % v3;
}


// ========================================================================
// ?SetColorMappings@idRenderSystemLocal@@QAAXMMM@Z
// EA  : 0x82946358
// RVA : 0x00946358
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::SetColorMappings(
        idRenderSystemLocal *this,
        double gamma,
        double brightness,
        long double blackLevel)
{
  __int64 v5; // r11
  double v7; // fp28
  unsigned __int16 *gammaTable; // r28
  int v10; // r31
  _WORD *v11; // r30
  double v12; // fp23
  double v13; // fp25
  double v14; // fp0
  long double v15; // fp2
  long double v16; // fp2

  HIDWORD(v5) = byte_821B0000;
  v7 = *(double *)&blackLevel;
  gammaTable = this->gammaTable;
  v10 = 0;
  v11 = (_WORD *)&this->currentRenderView + 1;
  v12 = (float)((float)1.0 / (float)gamma);
  v13 = (float)((float)1.0 - (float)*(double *)&blackLevel);
  do
  {
    LODWORD(v5) = v10;
    v14 = (float)((float)((float)((float)v5 * (float)0.0039215689) * (float)v13) + (float)v7);
    if ( v14 >= 0.0 )
    {
      if ( v14 > 1.0 )
        v14 = 1.0;
    }
    else
    {
      v14 = 0.0;
    }
    LODWORD(v5) = (int)(float)((float)((float)v14 * (float)255.0) * (float)brightness);
    if ( (int)v5 > 255 )
      LODWORD(v5) = 255;
    if ( gamma == 1.0 )
    {
      HIDWORD(v5) = (_DWORD)v5 << 8;
      LODWORD(v5) = ((_DWORD)v5 << 8) | v5;
    }
    else
    {
      *((double *)&v15 + 1) = v12;
      *(double *)&v15 = (float)((float)v5 * (float)0.0039215689);
      v16 = pow(x: v15, y: blackLevel);
      LODWORD(v5) = (int)(float)((float)((float)*(double *)&v16 * (float)65535.0) + (float)0.5);
    }
    if ( (int)v5 >= 0 )
    {
      if ( (int)v5 > 0xFFFF )
        LOWORD(v5) = -1;
    }
    else
    {
      LOWORD(v5) = 0;
    }
    ++v10;
    *++v11 = v5;
  }
  while ( v10 < 256 );
  this->SetGamma(this, a2: gammaTable, a3: gammaTable, a4: gammaTable);
}


// ========================================================================
// ?RenderFrameInfoHasWorlds@@YA_NABVidRenderFrameInfo@@@Z
// EA  : 0x829464C8
// RVA : 0x009464C8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

int __fastcall RenderFrameInfoHasWorlds(const idRenderFrameInfo *rfi)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idScreenView *list; // r8

  num = rfi->screenViews.num;
  v2 = 0;
  if ( num <= 0 )
    return 0;
  v3 = 0;
  list = rfi->screenViews.list;
  while ( list->world == nullptr )
  {
    ++v2;
    list = &rfi->screenViews.list[++v3];
    if ( v2 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?InitGraphicsAPIWrapper@@YAXXZ
// EA  : 0x82946518
// RVA : 0x00946518
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall InitGraphicsAPIWrapper()
{
  wrapperConfig_t v0; // [sp+50h] [-40h] BYREF

  v0.waitForOcclusionQuery = r_waitForQuery.valueInteger != 0;
  v0.lazyBindPrograms = r_lazyBindPrograms.valueInteger != 0;
  v0.lazyBindParms = r_lazyBindParms.valueInteger != 0;
  v0.lazyBindTextures = r_lazyBindTextures.valueInteger != 0;
  v0.stripFragmentBranches = r_stripFragmentBranches.valueInteger != 0;
  v0.skipDetailTris = r_skipDetailTris.valueInteger != 0;
  v0.singleTriangle = r_singleTriangle.valueInteger != 0;
  v0.defaultPolyOfsFactor = r_defaultPolyOfsFactor.valueFloat;
  v0.defaultPolyOfsUnits = r_defaultPolyOfsUnits.valueFloat;
  v0.forceTwoSided = (_cntlzw(r_forceTwoSided.valueInteger - 1) & 0x20) != 0;
  v0.disableStateCaching = (_cntlzw(r_useStateCaching.valueInteger) & 0x20) != 0;
  v0.finishEveryDraw = r_finishEveryDraw.valueInteger != 0;
  v0.textureMinFilter = globalImages->textureMinFilter;
  v0.textureMaxFilter = globalImages->textureMaxFilter;
  v0.textureMipFilter = globalImages->textureMipFilter;
  v0.textureAnisotropy = globalImages->textureAnisotropy;
  v0.textureLODBias = globalImages->textureLODBias;
  GL_SetWrapperConfig(config: &v0);
}


// ========================================================================
// ?PrintStatistics@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82946848
// RVA : 0x00946848
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::PrintStatistics(idRenderSystemLocal *this)
{
  wrapperStats_t *CurrentStats; // r3
  char *v3; // r10
  int *p_c_drawVertices; // r11
  int i; // ctr
  __int64 v6; // r8
  wrapperStats_t *v7; // r3
  char *v8; // r10
  int *v9; // r11
  int j; // ctr
  idRenderWorldLocal *primaryWorld; // r11
  int v12; // r25
  double v13; // fp31
  int v14; // r27
  idRenderModel *v15; // r30
  int v16; // r28
  int v17; // r29
  idRenderModelSurface *v18; // r31
  const idMaterial *material; // r3
  bool IsVMTRVirtualTexture; // r3
  char v21; // r11
  idTriangles *geometry; // r3
  double SurfaceArea; // fp30
  wrapperStats_t *v24; // r3
  char *v25; // r10
  int *v26; // r11
  int k; // ctr
  unsigned int c_viewWorldAreas; // r7
  unsigned int v29; // r30
  unsigned int v30; // r31
  unsigned int c_viewModels; // r6
  unsigned int c_viewLights; // r5
  unsigned int v33; // r29
  unsigned int c_viewShadows; // r4
  unsigned int c_viewDimShadows; // r3
  int v36; // r10
  const char *v37; // r9
  int v38; // r5
  double UpstreamDropRate; // fp31
  int v40; // r5
  double v41; // fp31
  int v42; // r5
  double v43; // fp31
  int v44; // r5
  double v45; // fp31
  int v46; // r5
  int v47; // r5
  int v48; // r5
  int v49; // r5
  double v50; // fp31
  int v51; // r5
  int v52; // r5
  double v53; // fp1
  double v54; // fp3
  double v55; // [sp+30h] [-1D0h]
  int v56; // [sp+38h] [-1C8h]
  char v57; // [sp+10Ch] [-F4h] BYREF
  int v58; // [sp+110h] [-F0h]
  int v59; // [sp+114h] [-ECh]
  int v60; // [sp+118h] [-E8h]
  int v61; // [sp+128h] [-D8h]
  int v62; // [sp+12Ch] [-D4h]
  int v63; // [sp+130h] [-D0h]
  wrapperStats_t v64; // [sp+140h] [-C0h] BYREF

  if ( r_showPrimitives.valueInteger != 0 )
  {
    CurrentStats = GL_GetCurrentStats(result: &v64);
    v3 = &v57;
    p_c_drawVertices = &CurrentStats[-1].c_drawVertices;
    for ( i = 9; i != 0; --i )
    {
      ++p_c_drawVertices;
      v3 += 4;
      *(_DWORD *)v3 = *p_c_drawVertices;
    }
    idLib::Printf(fmt: "draws:%i tris:%i verts:%i\n", v61, v62 / 3, v63);
  }
  if ( r_showQueries.valueInteger != 0 )
  {
    v7 = GL_GetCurrentStats(result: &v64);
    v8 = &v57;
    v9 = &v7[-1].c_drawVertices;
    for ( j = 9; j != 0; --j )
    {
      ++v9;
      v8 += 4;
      *(_DWORD *)v8 = *v9;
    }
    LODWORD(v6) = v60;
    v55 = (float)((float)v6 * (float)0.001);
    idLib::Printf(fmt: "%d issued, %d passed, %d too old, %1.2f spin ms\n", v58, v59, HIDWORD(v55), v55);
  }
  if ( r_showCommits.valueInteger != 0 )
    idLib::Printf(
      fmt: "modelCommits:%i  modelRefs:%i  lightCommits:%i  lightRefs:%i\n",
      this->pc.c_modelCommits,
      this->pc.c_modelReferences,
      this->pc.c_lightCommits,
      this->pc.c_lightReferences);
  if ( r_showTotalSurfaceArea.valueInteger != 0 )
  {
    primaryWorld = this->primaryWorld;
    v12 = 0;
    v13 = 0.0;
    if ( primaryWorld->renderModels.num > 0 )
    {
      v14 = 0;
      do
      {
        v15 = primaryWorld->renderModels.list[v14];
        if ( v15 != nullptr
          && (r_showTotalSurfaceArea.valueInteger == 2
           || _RTDynamicCast(
                inptr: v15,
                VfDelta: 0,
                SrcType: &idRenderModel `RTTI Type Descriptor',
                TargetType: &idTreeAnimator `RTTI Type Descriptor',
                isReference: 0) == nullptr) )
        {
          v16 = 0;
          if ( v15->surfaces.num > 0 )
          {
            v17 = 0;
            do
            {
              v18 = &v15->surfaces.list[v17];
              material = v18->material;
              if ( v18->material != nullptr )
              {
                if ( material->pageSource > PAGESOURCE_VMTR
                  || (IsVMTRVirtualTexture = idMaterial::IsVMTRVirtualTexture(this: material),
                      v21 = 0,
                      IsVMTRVirtualTexture) )
                {
                  v21 = 1;
                }
                if ( v21 != 0 )
                {
                  geometry = v18->geometry;
                  if ( geometry->verts != nullptr && geometry->indexes != nullptr )
                  {
                    SurfaceArea = idTriangles::GetSurfaceArea(this: geometry);
                    idLib::Printf(fmt: "%.0f %s\n", SurfaceArea, (const char *)HIDWORD(SurfaceArea));
                    v13 = (float)((float)SurfaceArea + (float)v13);
                  }
                }
              }
              ++v16;
              ++v17;
            }
            while ( v16 < v15->surfaces.num );
          }
        }
        primaryWorld = this->primaryWorld;
        ++v12;
        ++v14;
      }
      while ( v12 < primaryWorld->renderModels.num );
    }
    idLib::Printf(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v13 * (float)0.000001))),
      (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v13 * (float)0.000001)));
    idCVar::SetBool(this: &r_showTotalSurfaceArea, newValue: false, force: true);
  }
  if ( r_showStats.valueInteger != 0 )
  {
    v24 = GL_GetCurrentStats(result: &v64);
    v25 = &v57;
    v26 = &v24[-1].c_drawVertices;
    for ( k = 9; k != 0; --k )
    {
      ++v26;
      v25 += 4;
      *(_DWORD *)v25 = *v26;
    }
    if ( r_showStats.valueInteger == 1 )
    {
      c_viewWorldAreas = this->pc.c_viewWorldAreas;
      v29 = v62 / 3;
      v30 = v61;
      c_viewModels = this->pc.c_viewModels;
      c_viewLights = this->pc.c_viewLights;
      v33 = v63;
      c_viewShadows = this->pc.c_viewShadows;
      c_viewDimShadows = this->pc.c_viewDimShadows;
      numWorldAreas = c_viewWorldAreas;
      numBatches = v61;
      numModels = c_viewModels;
      numTriangles = v62 / 3;
      numLights = c_viewLights;
      numVertices = v63;
      numShadows = c_viewShadows;
      numDimShadows = c_viewDimShadows;
    }
    else
    {
      c_viewWorldAreas = numWorldAreas;
      c_viewModels = numModels;
      c_viewLights = numLights;
      c_viewShadows = numShadows;
      c_viewDimShadows = numDimShadows;
      v30 = numBatches;
      v29 = numTriangles;
      v33 = numVertices;
    }
    v36 = (int)(31 * averageWorldAreas
              + (((__PAIR64__(c_viewWorldAreas >> 31, averageWorldAreas)
                 - __PAIR64__((unsigned int)averageWorldAreas >> 31, c_viewWorldAreas)) >> 32)
               & 0x1F)
              + c_viewWorldAreas)
        / 32;
    averageWorldAreas = v36;
    averageModels = (int)(31 * averageModels
                        + (((__PAIR64__(c_viewModels >> 31, averageModels)
                           - __PAIR64__((unsigned int)averageModels >> 31, c_viewModels)) >> 32)
                         & 0x1F)
                        + c_viewModels)
                  / 32;
    averageLights = (int)(31 * averageLights
                        + (((__PAIR64__(c_viewLights >> 31, averageLights)
                           - __PAIR64__((unsigned int)averageLights >> 31, c_viewLights)) >> 32)
                         & 0x1F)
                        + c_viewLights)
                  / 32;
    averageShadows = (int)(31 * averageShadows
                         + (((__PAIR64__(c_viewShadows >> 31, averageShadows)
                            - __PAIR64__((unsigned int)averageShadows >> 31, c_viewShadows)) >> 32)
                          & 0x1F)
                         + c_viewShadows)
                   / 32;
    averageDimShadows = (int)(31 * averageDimShadows
                            + (((__PAIR64__(c_viewDimShadows >> 31, averageDimShadows)
                               - __PAIR64__((unsigned int)averageDimShadows >> 31, c_viewDimShadows)) >> 32)
                             & 0x1F)
                            + c_viewDimShadows)
                      / 32;
    averageBatches = (int)(31 * averageBatches
                         + (((__PAIR64__(v30 >> 31, averageBatches) - __PAIR64__(
                                                                        (unsigned int)averageBatches >> 31,
                                                                        v30)) >> 32)
                          & 0x1F)
                         + v30)
                   / 32;
    averageTriangles = (int)(31 * averageTriangles
                           + (((__PAIR64__(v29 >> 31, averageTriangles)
                              - __PAIR64__((unsigned int)averageTriangles >> 31, v29)) >> 32)
                            & 0x1F)
                           + v29)
                     / 32;
    averageVertices = (int)(31 * averageVertices
                          + (((__PAIR64__(v33 >> 31, averageVertices)
                             - __PAIR64__((unsigned int)averageVertices >> 31, v33)) >> 32)
                           & 0x1F)
                          + v33)
                    / 32;
    if ( (_S13_26 & 1) == 0 )
    {
      _S13_26 |= 1u;
      stats1.index = -1;
      stats1.time = 0;
    }
    v37 = "^2";
    if ( v36 > 500 )
      v37 = "^1";
    ((void (*)(idConsole *, idOverlayHandle *, int, _DWORD, int, const char *, ...))console->PrintOverlay)(
      a1: console,
      a2: &stats1,
      a3: 1,
      a4: 1.0,
      a5: v56,
      a6: "%s%4d^7 / %4d world areas\n"
      "%s%4d^7 / %4d models     \n"
      "%s%4d^7 / %4d lights     \n"
      "%s%4d^7 / %4d shadows    \n"
      "%s%4d^7 / %4d dim-shadows\n"
      "%s%4d^7 / %4d batches    \n"
      "%s%3dk^7 / %3dk triangles  \n"
      "%s%3dk^7 / %3dk vertices   \n",
      v37,
      1.0,
      1.0);
    if ( r_showStats.valueInteger == 1 )
    {
      UpstreamDropRate = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 20, frac_bits: v38);
      v41 = (float)((float)UpstreamDropRate
                  + idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 19, frac_bits: v40));
      v43 = (float)(idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 17, frac_bits: v42)
                  + (float)v41);
      v45 = (float)(idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 13, frac_bits: v44)
                  + (float)v43);
      gpu_basePass = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 12, frac_bits: v46)
                   + (float)v45;
      gpu_lights = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 21, frac_bits: v47);
      gpu_dimShadows = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 22, frac_bits: v48);
      v50 = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 33, frac_bits: v49);
      gpu_guis = (float)v50
               + idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 32, frac_bits: v51);
      v53 = idSession::GetUpstreamDropRate(val: (unsigned int)&renderLog, int_bits: 38, frac_bits: v52);
      v54 = gpu_basePass;
      gpu_total = v53;
      gpu_effects = (float)((float)((float)((float)v53 - gpu_basePass) - gpu_lights) - gpu_dimShadows) - gpu_guis;
    }
    else
    {
      v54 = gpu_basePass;
    }
    if ( (_S13_26 & 2) == 0 )
    {
      stats2.time = 0;
      _S13_26 |= 2u;
      stats2.index = -1;
    }
    ((void (*)(idConsole *, idOverlayHandle *, int, _DWORD, int, const char *, ...))console->PrintOverlay)(
      a1: console,
      a2: &stats2,
      a3: 1,
      a4: HIDWORD(v55),
      a5: v56,
      a6: "--------------------------\n"
      "%s%4.1f^7 / %4.1f ms base pass  \n"
      "%s%4.1f^7 / %4.1f ms lights     \n"
      "%s%4.1f^7 / %4.1f ms dim-shadows\n"
      "%s%4.1f^7 / %4.1f ms effects    \n"
      "%s%4.1f^7 / %4.1f ms guis       \n"
      "%s%4.1f^7 / %4.1f ms total      \n",
      HIDWORD(v54),
      LODWORD(v54),
      1.0);
  }
}


// ========================================================================
// ?ToolEndFrame@idRenderSystemLocal@@UAAXPAXHHPAVidRenderWorld@@ABUrenderView_t@@PAVidRenderModel@@H@Z
// EA  : 0x82947178
// RVA : 0x00947178
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::ToolEndFrame(
        idRenderSystemLocal *this,
        void *hdc,
        int windowWidth,
        int windowHeight,
        idRenderWorld *world,
        const renderView_t *rvt,
        idRenderModel *gui,
        int timeMsec,
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
        int a22,
        int a23,
        idRenderModel *a24)
{
  idRenderView *v30; // r3

  a24 = gui;
  world->SetNumRenderViews(this: world, a2: 1);
  v30 = world->RenderViewForIndex(this: world, a2: 0);
  renderView_t::operator=(this: &v30->g, __that: rvt);
  ((void (__fastcall *)(idRenderSystemLocal *, void *, int, int, idRenderWorld *, idRenderModel **, bool, _DWORD))this->EndFrame)(
    a1: this,
    a2: hdc,
    a3: windowWidth,
    a4: windowHeight,
    a5: world,
    a6: &a24,
    a7: a24 != nullptr,
    a8: 0);
}


// ========================================================================
// ?RenderManual@idRenderSystemLocal@@QAAXPAX_N1@Z
// EA  : 0x82947238
// RVA : 0x00947238
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RenderManual(
        idRenderSystemLocal *this,
        void *hdc,
        bool skipSwapBuffers,
        bool resolveDepth)
{
  idRenderFrameInfo *p_currentRenderFrameInfo; // r30
  int num; // r6
  signed int v7; // r25
  int v8; // r10
  int v9; // r11
  idScreenView *list; // r8
  int v11; // r26
  int v12; // r14
  int v13; // r19
  int v14; // r24
  int v15; // r20
  idScreenView *v16; // r30
  idRenderWorldLocal *world; // r3
  idRenderWorldLocal *testWorld; // r11
  idRenderWorldLocal *primaryWorld; // r8
  idRenderView *v20; // r9
  const idRenderView *v21; // r28
  const char *v22; // r3
  int v23; // r5
  int v24; // r10
  int v25; // r9
  idRenderModel *v26; // r8
  float *committed; // r11
  int v28; // r30
  int v29; // r28
  int v30; // r22
  int v31; // r23
  idScreenView *v32; // r11
  int y1; // r21
  unsigned int x1; // r20
  int viewIndex; // r3
  int y2; // r8
  int v37; // r11
  int v38; // r28
  const idImage *v39; // r19
  int v40; // r30
  const idDeclRenderProg *r; // r28
  bool v42; // r7
  int v43; // r25
  int v44; // r26
  idScreenView *v45; // r30
  int v46; // r24
  int v47; // r23
  unsigned int v48; // r3
  int v49; // r28
  int v50; // r27
  int v51; // r5
  int v52; // r10
  int v53; // r9
  double v54; // fp13
  idRenderModel *v55; // r8
  float *v56; // r11
  idImage *v57; // r30
  unsigned int v58; // [sp+8h] [-148h]
  const _D3DRESOLVE_PARAMETERS *v59; // [sp+Ch] [-144h]
  idODSObject<idRenderDestination> v60; // [sp+70h] [-E0h] BYREF
  idODSObject<idDeclRenderProg> v61; // [sp+74h] [-DCh] BYREF
  idODSObject<idTriangles> v62; // [sp+78h] [-D8h] BYREF
  unsigned int v63; // [sp+7Ch] [-D4h]
  _D3DRECT v64; // [sp+80h] [-D0h] BYREF
  idScopedConsoleTimeRange v65; // [sp+90h] [-C0h] BYREF

  if ( this->currentRenderFrameInfo.screenViews.num != 0 )
  {
    videoManager->Update(this: videoManager);
    p_currentRenderFrameInfo = &this->currentRenderFrameInfo;
    if ( (unsigned __int8)RenderFrameInfoHasWorlds(rfi: &this->currentRenderFrameInfo) != 0
      && r_skipAnalyze.valueInteger == 0 )
    {
      idScopedConsoleTimeRange::idScopedConsoleTimeRange(this: &v65, id_: 1, color: &idColor::colorOrange);
      idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_PROCESS_FEEDBACK);
      idVirtualTextureSystem::PushFeedback(
        this: &virtualTextureSystem,
        data: virtualTextureSystem.feedbackBuffer,
        width: 160,
        height: 128,
        bytePitch: virtualTextureSystem.feedbackBufferPitch,
        forceHighestDetail: false);
      idVirtualTextureSystem::VisaulizeFeedback(this: &virtualTextureSystem);
      idRenderLog::CloseMainBlock(this: &renderLog);
      console->BeginTimeRange(this: console, a2: v65.id, a3: (const idColor *)&v65);
    }
    num = this->currentRenderFrameInfo.screenViews.num;
    v7 = 0;
    v8 = 0;
    if ( num > 0 )
    {
      v9 = 0;
      list = p_currentRenderFrameInfo->screenViews.list;
      do
      {
        if ( list->world != nullptr )
          ++v7;
        ++v8;
        list = &p_currentRenderFrameInfo->screenViews.list[++v9];
      }
      while ( v8 < num );
    }
    v11 = 0;
    v12 = 0;
    v13 = 0;
    if ( num > 0 )
    {
      v14 = 0;
      v15 = 0;
      do
      {
        v16 = &this->currentRenderFrameInfo.screenViews.list[v15];
        if ( v16->world != nullptr )
        {
          ++v11;
          ++v14;
          if ( !v16->usePreviousRendering )
          {
            this->windowWidth = v16->screenRect.x2 - v16->screenRect.x1 + 1;
            this->windowHeight = v16->screenRect.y2 - v16->screenRect.y1 + 1;
            world = (idRenderWorldLocal *)v16->world;
            this->primaryWorld = world;
            idRenderWorldLocal::PostCommitData(this: world);
            if ( r_testWorld.valueInteger != 0 )
            {
              testWorld = this->testWorld;
              if ( testWorld != nullptr )
                this->primaryWorld = testWorld;
            }
            primaryWorld = this->primaryWorld;
            v20 = primaryWorld->renderViews.list[v14 - 1];
            __twllei(v7, 0);
            __twlgei(v7 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
            this->currentRenderView = v20;
            v21 = primaryWorld->renderViews.list[v11 % v7];
            renderView_t::operator=(this: &v20->g, __that: &v16->g);
            idRenderView::CommitParameters(
              this: this->currentRenderView,
              windowWidth: this->windowWidth,
              windowHeight: this->windowHeight,
              renderWidth: this->windowWidth,
              renderHeight: this->windowHeight);
            if ( r_skipUpdateInView.valueInteger == 0 )
              idRenderWorldLocal::UpdateInView(
                this: this->primaryWorld,
                currentRenderView: this->currentRenderView,
                nextRenderView: v21);
            v22 = this->primaryWorld->GetName(this: this->primaryWorld);
            idResolutionScale::InitForMap(this: &resolutionScale, mapName: v22);
            idRender::InitSettings(this: &renderState, world_: this->primaryWorld, renderView_: this->currentRenderView);
            idRender::RenderSingleView(
              this: &renderState,
              hdc,
              world_: this->primaryWorld,
              renderView_: this->currentRenderView,
              currentScreenView: v16);
            ++v12;
            idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_VIEW_GUIS);
            v23 = v16->viewGuis.num;
            v24 = 0;
            if ( v23 > 0 )
            {
              v25 = 0;
              do
              {
                ++v24;
                v26 = v16->viewGuis.list[v25++];
                committed = (float *)v26->committed;
                committed[9] = v16->guiOriginOffset - (float)1.0;
                committed[10] = 1.0;
                committed[11] = 0.0;
                v23 = v16->viewGuis.num;
              }
              while ( v24 < v23 );
            }
            idRender::RenderGuiModels(
              this: &renderState,
              guiModels: v16->viewGuis.list,
              numGuiModels: v23,
              renderDestGuis: renderDestNative,
              windowWidth: this->windowWidth,
              windowHeight: this->windowHeight,
              renderWidth: this->windowWidth,
              renderHeight: this->windowHeight);
            idRenderLog::CloseMainBlock(this: &renderLog);
            idRender::CaptureToViewColor(this: &renderState, viewIndex: this->currentRenderView->viewIndex);
          }
        }
        ++v13;
        ++v15;
      }
      while ( v13 < this->currentRenderFrameInfo.screenViews.num );
    }
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_UPSAMPLE);
    v60.objectPtr = renderDestNative;
    GL_SetRenderDestination(destination: &v60, level: 0, side: 0);
    v28 = renderSystem->GetScanoutHeight(this: renderSystem);
    v29 = renderSystem->GetScanoutWidth(this: renderSystem);
    GL_Viewport(x: 0, y: 0, w: v29, h: v28);
    GL_Scissor(x: 0, y: 0, w: v29, h: v28);
    GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
    v30 = 0;
    if ( this->currentRenderFrameInfo.screenViews.num > 0 )
    {
      v31 = 0;
      do
      {
        v32 = &this->currentRenderFrameInfo.screenViews.list[v31];
        if ( v32->world != nullptr || v32->usePreviousRendering )
        {
          y1 = v32->screenRect.y1;
          x1 = v32->screenRect.x1;
          viewIndex = v32->viewIndex;
          y2 = v32->screenRect.y2;
          v37 = v32->screenRect.x2 - v32->screenRect.x1;
          v63 = y1;
          v38 = y2 - y1 + 1;
          v39 = tr.imgViewColor[viewIndex];
          v40 = v37 + 1;
          v63 = x1;
          GL_Viewport(x: x1, y: y1, w: v37 + 1, h: v38);
          GL_Scissor(x: x1, y: y1, w: v40, h: v38);
          r = (const idDeclRenderProg *)progViewColorIdentity_0.r;
          idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpViewColor_0.r, image: v39);
          idParmState::VirtualEvaluateParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
          v62.objectPtr = tr.unitSquareModel->surfaces.list->geometry;
          v61.objectPtr = r;
          GL_DrawElements(prog: &v61, tri: &v62, extraState: 0, skipDetailTriangles: v42);
          idParmState::VirtualRollbackParmBlock(
            this: renderThreadParmState,
            localParmBlock: &r->parmBlock,
            parmBlock: &r->parmBlock);
        }
        ++v30;
        ++v31;
      }
      while ( v30 < this->currentRenderFrameInfo.screenViews.num );
    }
    idRenderLog::CloseMainBlock(this: &renderLog);
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_FULL_SCREEN_GUIS);
    idRender::InitSettings(this: &renderState, world_: nullptr, renderView_: nullptr);
    v43 = 0;
    if ( this->currentRenderFrameInfo.screenViews.num > 0 )
    {
      v44 = 0;
      do
      {
        v45 = &this->currentRenderFrameInfo.screenViews.list[v44];
        if ( v45->world == nullptr && !v45->usePreviousRendering )
        {
          v46 = v45->screenRect.x1;
          v47 = v45->screenRect.y1;
          v48 = v45->screenRect.x1;
          v49 = v45->screenRect.y2 - v47 + 1;
          v50 = v45->screenRect.x2 - v45->screenRect.x1 + 1;
          v63 = v47;
          GL_Viewport(x: v48, y: v47, w: v50, h: v49);
          GL_Scissor(x: v46, y: v47, w: v50, h: v49);
          v51 = v45->viewGuis.num;
          v52 = 0;
          if ( v51 > 0 )
          {
            v53 = 0;
            do
            {
              v54 = (float)(v45->guiOriginOffset - (float)1.0);
              ++v52;
              v55 = v45->viewGuis.list[v53++];
              v56 = (float *)v55->committed;
              v56[10] = 1.0;
              v56[9] = v54;
              v56[11] = 0.0;
              v51 = v45->viewGuis.num;
            }
            while ( v52 < v51 );
          }
          idRender::RenderGuiModels(
            this: &renderState,
            guiModels: v45->viewGuis.list,
            numGuiModels: v51,
            renderDestGuis: renderDestNative,
            windowWidth: v45->screenRect.x2 - v45->screenRect.x1 + 1,
            windowHeight: v45->screenRect.y2 - v45->screenRect.y1 + 1,
            renderWidth: v45->screenRect.x2 - v45->screenRect.x1 + 1,
            renderHeight: v45->screenRect.y2 - v45->screenRect.y1 + 1);
        }
        ++v43;
        ++v44;
      }
      while ( v43 < this->currentRenderFrameInfo.screenViews.num );
    }
    idRenderLog::CloseMainBlock(this: &renderLog);
    if ( this->currentRenderFrameInfo.captureFrame )
    {
      v57 = this->imgViewColor[0];
      v64.y1 = 0;
      v64.x1 = 0;
      v64.x2 = v57->opts.width;
      v64.y2 = 720;
      D3DDevice_Resolve(
        pDevice: d3d,
        Flags: 0,
        pSourceRect: &v64,
        pDestTexture: v57->d3dTexture,
        pDestPoint: nullptr,
        DestLevel: 0,
        DestSliceOrFace: 0,
        pClearColor: nullptr,
        ClearZ: 0.0,
        ClearStencil: v58,
        pParameters: v59);
      this->renderingIsReadyForSwapbuffers = false;
    }
    if ( !skipSwapBuffers )
    {
      if ( v12 != 0 )
      {
        this->renderingIsReadyForSwapbuffers = true;
      }
      else
      {
        this->SwapBuffers(this, a2: hdc, a3: false);
        this->renderingIsReadyForSwapbuffers = false;
      }
    }
  }
}


// ========================================================================
// __unwind$234470_0
// EA  : 0x8294798C
// RVA : 0x0094798C
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_234470_0()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 336 + 144));
}


// ========================================================================
// ?RenderAutomatic@idRenderSystemLocal@@QAAXPAX@Z
// EA  : 0x829479B8
// RVA : 0x009479B8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RenderAutomatic(idRenderSystemLocal *this, void *hdc)
{
  int v4; // r28
  int v5; // r27
  bool v6; // r7
  idODSObject<idRenderDestination> v7; // [sp+50h] [-50h] BYREF
  idODSObject<idDeclRenderProg> v8; // [sp+54h] [-4Ch] BYREF
  idODSObject<idTriangles> v9; // [sp+58h] [-48h] BYREF

  GL_WaitForEndFrame();
  if ( this->renderingIsReadyForSwapbuffers )
  {
    this->renderingIsReadyForSwapbuffers = false;
    this->SwapBuffers(this, a2: hdc, a3: false);
  }
  v7.objectPtr = renderDestNative;
  GL_SetRenderDestination(destination: &v7, level: 0, side: 0);
  GL_SetDefaultState();
  v4 = this->GetScanoutWidth(this);
  v5 = this->GetScanoutHeight(this);
  GL_Viewport(x: 0, y: 0, w: v4, h: v5);
  GL_Scissor(x: 0, y: 0, w: v4, h: v5);
  GL_Clear(color: true, depth: true, stencil: true, stencilValue: 0x80u, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
  idParmState::SetPositionToViewTexture(
    this: renderThreadParmState,
    windowWidth: v4,
    windowHeight: v5,
    renderWidth: v4,
    renderHeight: v5);
  idParmState::SetMVPMatrixFlipped(this: renderThreadParmState, mvp: &renderMatrix_identity);
  idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpViewColor_0.r, image: this->imgViewColor[0]);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: (const idParmBlock *)&progViewColorIdentity_0.r[2].resourceListPtr,
    parmBlock: (const idParmBlock *)&progViewColorIdentity_0.r[2].resourceListPtr);
  v8.objectPtr = (const idDeclRenderProg *)progViewColorIdentity_0.r;
  v9.objectPtr = this->unitSquareTris;
  GL_DrawElements(prog: &v8, tri: &v9, extraState: 0, skipDetailTriangles: v6);
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: (const idParmBlock *)&progViewColorIdentity_0.r[2].resourceListPtr,
    parmBlock: (const idParmBlock *)&progViewColorIdentity_0.r[2].resourceListPtr);
  Sys_Yield();
  this->SwapBuffers(this, a2: hdc, a3: false);
  this->renderingIsReadyForSwapbuffers = false;
}


// ========================================================================
// __unwind$234780
// EA  : 0x8294810C
// RVA : 0x0094810C
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_234780()
{
  int v0; // r12

  idRenderModelGui::~idRenderModelGui(this: (idRenderModelGui *)(v0 + 23392));
}


// ========================================================================
// __unwind$234781
// EA  : 0x82948134
// RVA : 0x00948134
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_234781()
{
  int v0; // r12

  idRenderView::~idRenderView(this: (idRenderView *)(v0 + 18912));
}


// ========================================================================
// ?RenderFrameInternal@idRenderSystemLocal@@QAAXW4renderMode_t@@PAX_N2@Z
// EA  : 0x82948168
// RVA : 0x00948168
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RenderFrameInternal(
        idRenderSystemLocal *this,
        renderMode_t renderMode,
        void *hdc,
        bool skipSwapBuffers,
        bool resolveDepth)
{
  unsigned int LastError; // r3
  unsigned __int64 v11; // r3
  unsigned __int64 v12; // r6
  int v13; // r4
  int v14; // r3
  long double v15; // fp4
  unsigned __int64 v16; // r6
  int v17; // r4
  int v18; // r3
  unsigned __int64 v19; // r3
  unsigned __int64 startCPUTimeMicroSec; // r11

  idRenderModelGui::StartFrame();
  RD_EventBegin(name: "idRenderSystemLocal::RenderFrame");
  if ( r_recordRendererTrace.valueInteger == 1 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorLtGrey);
  LODWORD(v11) = Sys_Microseconds() >> 32;
  this->pc.startCPUTimeMicroSec = v11;
  idParmState::RollbackOpsToZero(this: renderThreadParmState);
  GL_ResetProgramState(a1: v14, a2: v13, a3: v12);
  InitGraphicsAPIWrapper();
  GL_SetDefaultState();
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorGreen);
  if ( renderMode != RENDER_MODE_MANUAL )
  {
    if ( renderMode == RENDER_MODE_AUTOMATIC )
    {
      GL_StartFrame(frame: tr.frameCount);
      idRenderSystemLocal::RenderAutomatic(this, hdc);
    }
    else if ( renderMode == RENDER_MODE_BINK )
    {
      GL_StartFrame(frame: tr.frameCount);
      idRenderSystemLocal::RenderBink(this, hdc);
    }
  }
  else
  {
    idRenderSystemLocal::RenderManual(this, hdc, skipSwapBuffers, resolveDepth);
  }
  if ( this->updateGammaTable || (r_gamma.flags & 0x20000) != 0 || (r_brightness.flags & 0x20000) != 0 )
  {
    r_gamma.flags &= ~0x20000u;
    r_brightness.flags &= ~0x20000u;
    *(double *)&v15 = this->blackLevel[1];
    idRenderSystemLocal::SetColorMappings(
      this,
      gamma: r_gamma.valueFloat,
      brightness: r_brightness.valueFloat,
      blackLevel: v15);
    this->updateGammaTable = false;
  }
  UnbindBufferObjects();
  idImageManager::UnbindAll(this: globalImages);
  GL_EndFrame();
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  idRenderLog::EndFrame(this: &renderLog);
  idParmState::RollbackOpsToZero(this: renderThreadParmState);
  GL_ResetProgramState(a1: v18, a2: v17, a3: v16);
  if ( r_sleep.valueInteger > 0 )
    mgthread_sleep(ms: r_sleep.valueInteger);
  LODWORD(v19) = Sys_Microseconds() >> 32;
  startCPUTimeMicroSec = this->pc.startCPUTimeMicroSec;
  this->pc.endCPUTimeMicroSec = v19;
  time_renderFrame = v19 - startCPUTimeMicroSec;
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorBlack);
  if ( r_recordRendererTrace.valueInteger > 0 )
    idCVar::SetInteger(this: &r_recordRendererTrace, newValue: r_recordRendererTrace.valueInteger - 1, force: true);
  RD_EventEnd();
}


// ========================================================================
// __unwind$235012
// EA  : 0x829483B0
// RVA : 0x009483B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_235012()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 80));
}


// ========================================================================
// ?RegenerateReferences@idRenderSystemLocal@@UAAXXZ
// EA  : 0x829484F0
// RVA : 0x009484F0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RegenerateReferences(idRenderSystemLocal *this)
{
  idRenderWorldLocal *i; // r25
  encounterGroupRole_t *list; // r22
  int num; // r29
  encounterGroupRole_t *v4; // r23
  int v5; // r30
  int v6; // r28
  int v7; // r28
  int v8; // r30
  idRenderModel **v9; // r27
  int j; // r26
  idRenderModel *v11; // r28
  idRenderLight **v12; // r27
  int k; // r28
  idRenderModel **v14; // r28
  idRenderLight **v15; // r29
  encounterGroupRole_t v16[4]; // [sp+50h] [-A0h] BYREF
  idList<enum encounterGroupRole_t,5> v17; // [sp+60h] [-90h] BYREF
  idList<enum encounterGroupRole_t,5> v18; // [sp+70h] [-80h] BYREF

  for ( i = this->worlds; i != nullptr; v18.num = 0 )
  {
    list = nullptr;
    num = 0;
    *(_WORD *)&v18.memTag = 15872;
    memset(&v18, 0, 14);
    v4 = nullptr;
    v5 = 0;
    *(_WORD *)&v17.memTag = 15872;
    memset(&v17, 0, 14);
    v6 = 0;
    if ( i->renderModels.num > 0 )
    {
      do
      {
        v16[0] = *(encounterGroupRole_t *)((char *)i->renderModels.list + num);
        if ( v16[0] != ROLE_NONE && *(_BYTE *)(v16[0] + 75) == 0 )
          idList<idAnimWebBlendTree *,5>::Append(this: &v18, obj: v16);
        ++v6;
        num += 4;
      }
      while ( v6 < i->renderModels.num );
      num = v18.num;
      list = v18.list;
    }
    v7 = 0;
    if ( i->renderLights.num > 0 )
    {
      v8 = 0;
      do
      {
        v16[0] = (encounterGroupRole_t)i->renderLights.list[v8];
        if ( v16[0] != ROLE_NONE && *(_BYTE *)(v16[0] + 1057) == 0 )
          idList<idAnimWebBlendTree *,5>::Append(this: &v17, obj: v16);
        ++v7;
        ++v8;
      }
      while ( v7 < i->renderLights.num );
      v5 = v17.num;
      v4 = v17.list;
    }
    if ( num > 0 )
    {
      v9 = (idRenderModel **)list;
      for ( j = num; j != 0; --j )
      {
        v11 = *v9;
        if ( !(*v9)->unlinked )
        {
          idRenderModel::CommitThisFrame(this: *v9);
          v11->unlinked = true;
        }
        ++v9;
      }
    }
    if ( v5 > 0 )
    {
      v12 = (idRenderLight **)(v4 - 1);
      for ( k = v5; k != 0; --k )
        idRenderLight::Unlink(this: *++v12);
    }
    if ( num > 0 )
    {
      v14 = (idRenderModel **)(list - 1);
      do
      {
        idRenderModel::CommitThisFrame(this: *++v14);
        --num;
      }
      while ( num != 0 );
    }
    if ( v5 > 0 )
    {
      v15 = (idRenderLight **)(v4 - 1);
      do
      {
        idRenderLight::CommitThisFrame(this: *++v15);
        --v5;
      }
      while ( v5 != 0 );
    }
    if ( v17.listStatic == 0 || v17.listStatic == 2 )
    {
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      v17.list = nullptr;
      v17.size = 0;
    }
    v17.num = 0;
    if ( v18.listStatic == 0 || v18.listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v18.list = nullptr;
      v18.size = 0;
    }
    i = i->nextOnWorldList;
  }
}


// ========================================================================
// __unwind$235806
// EA  : 0x82948728
// RVA : 0x00948728
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_235806()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$235807
// EA  : 0x82948750
// RVA : 0x00948750
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_235807()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ??1idRenderSystemLocal@@UAA@XZ
// EA  : 0x82948918
// RVA : 0x00948918
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::~idRenderSystemLocal(idRenderSystemLocal *this)
{
  this->__vftable = (idRenderSystemLocal_vtbl *)&idRenderSystemLocal::`vftable';
  idMetricRecord::~idMetricRecord(this: &this->vertsMetric);
  idMetricRecord::~idMetricRecord(this: &this->trisMetric);
  idMetricRecord::~idMetricRecord(this: &this->drawsMetric);
  idStaticList<idScreenView,3>::~idStaticList<idScreenView,3>(this: &this->currentRenderFrameInfo.screenViews);
  this->__vftable = (idRenderSystemLocal_vtbl *)&idRenderSystem::`vftable';
}


// ========================================================================
// __unwind$236453
// EA  : 0x82948988
// RVA : 0x00948988
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236453()
{
  int v0; // r12

  idRenderSystem::~idRenderSystem(this: *(idRenderSystem **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$236454
// EA  : 0x829489B0
// RVA : 0x009489B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236454()
{
  int v0; // r12

  idRenderFrameInfo::~idRenderFrameInfo(this: (idRenderFrameInfo *)(*(_DWORD *)(v0 - 112 + 132) + 592));
}


// ========================================================================
// __unwind$236455
// EA  : 0x829489DC
// RVA : 0x009489DC
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236455()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 112 + 132) + 7152));
}


// ========================================================================
// __unwind$236456
// EA  : 0x82948A08
// RVA : 0x00948A08
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236456()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 112 + 132) + 7256));
}


// ========================================================================
// ??0idRenderSystemLocal@@QAA@XZ
// EA  : 0x82948AE0
// RVA : 0x00948AE0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

idRenderSystemLocal *__fastcall idRenderSystemLocal::idRenderSystemLocal(idRenderSystemLocal *this)
{
  idRenderDestination **p_renderDestGui; // r11
  int v3; // ctr
  idStr v5; // [sp+50h] [-E0h] BYREF
  idStr v6; // [sp+70h] [-C0h] BYREF
  idStr v7; // [sp+90h] [-A0h] BYREF
  idStr v8; // [sp+B0h] [-80h] BYREF
  idStr v9; // [sp+D0h] [-60h] BYREF
  idStr v10[2]; // [sp+F0h] [-40h] BYREF

  this->__vftable = (idRenderSystemLocal_vtbl *)&idRenderSystemLocal::`vftable';
  idStaticList<idScreenView,3>::idStaticList<idScreenView,3>(this: &this->currentRenderFrameInfo.screenViews);
  this->currentRenderFrameInfo.captureFrame = false;
  idStr::idStr(this: &v7, text: "draw calls in a frame");
  idStr::idStr(this: &v9, text: "draws");
  idGaugeMetric::idGaugeMetric(this: &this->drawsMetric, _shortName: &v9, _description: &v7);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v7);
  idStr::idStr(this: &v6, text: "drawn triangles in the scene");
  idStr::idStr(this: &v5, text: "triangles");
  idGaugeMetric::idGaugeMetric(this: &this->trisMetric, _shortName: &v5, _description: &v6);
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: &v6);
  idStr::idStr(this: v10, text: "vertices count in the scene");
  idStr::idStr(this: &v8, text: "vertices");
  idGaugeMetric::idGaugeMetric(this: &this->vertsMetric, _shortName: &v8, _description: v10);
  idStr::FreeData(this: &v8);
  idStr::FreeData(this: v10);
  this->insideEndFrame = false;
  this->automaticBackgroundSwapsEnabled = false;
  this->renderLoadingIcon = false;
  this->renderingIsReadyForSwapbuffers = false;
  this->allowBackgroundSwaps = true;
  this->loadingIconPosX = 0.1;
  this->renderSynced = true;
  this->loadingIconPosY = -0.30000001;
  this->frameCount = 0;
  this->loadingIconScale = 0.1;
  this->inhibitRendering = 0;
  this->loadingIconSpeed = 0.5;
  this->worlds = nullptr;
  this->primaryWorld = nullptr;
  this->performanceCounterLogWorld = nullptr;
  this->performanceCounterLogWorldFrame = 0;
  this->testWorld = nullptr;
  this->testImage = nullptr;
  this->testCubeImage = nullptr;
  this->testMaterial = nullptr;
  this->videoOverlay = nullptr;
  memset(Dst: &this->pc, Val: 0, Size: sizeof(this->pc));
  GL_ClearStats();
  this->mtrDefault = nullptr;
  this->mtrDefaultPointLight = nullptr;
  this->mtrDefaultProjectedLight = nullptr;
  this->mtrDefaultParallelLight = nullptr;
  this->mtrDefaultPointBlendLight = nullptr;
  this->mtrDefaultProjectedBlendLight = nullptr;
  this->mtrDefaultParallelBlendLight = nullptr;
  this->progGauss = nullptr;
  this->progGlareScale = nullptr;
  this->progOverlappedDownSample = nullptr;
  this->progFeedbackDownSample = nullptr;
  this->progPostProcess = nullptr;
  this->progDepthOnly = nullptr;
  this->progColorOnly = nullptr;
  this->progColorParmOnly = nullptr;
  this->progWireFrame = nullptr;
  this->progTextureOnly = nullptr;
  this->progCubeImageOnly = nullptr;
  this->progTestImage = nullptr;
  this->progBasicBlend = nullptr;
  this->progEnvironmentBlend = nullptr;
  this->progOccluderUnique = nullptr;
  this->progLandUniqueBump = nullptr;
  this->progLandUniqueDiffuseOnly = nullptr;
  this->progBlendedLightDebugDraw = nullptr;
  this->progVarianceShadowMap = nullptr;
  this->progCreateGodRayMask = nullptr;
  this->progDrawGodRay = nullptr;
  this->rpGlareMap = nullptr;
  this->rpGlareStep = nullptr;
  this->rpDistortionMap = nullptr;
  this->rpDynamicEnvMap = nullptr;
  this->rpPowerMip = nullptr;
  this->rpFrameNumber = nullptr;
  this->rpVirtualTextureFeedbackFloat = nullptr;
  this->rpPageTableMap = nullptr;
  this->rpVmtrPageTableMap = nullptr;
  this->rpDepthOfField2 = nullptr;
  this->rpGodRayQuadScaleBias = nullptr;
  this->rpGodRaySourceScaleBias = nullptr;
  p_renderDestGui = &this->renderDestGui;
  this->rpGodRaysColor = nullptr;
  this->progBloomThreshold = nullptr;
  this->progLuminosity = nullptr;
  this->rpAdaptiveGlareMap = nullptr;
  v3 = 2;
  this->rpAdaptiveGlareMapAlt = nullptr;
  this->rpLuminosityMap = nullptr;
  this->rpLuminosityMapAlt = nullptr;
  this->rpAdaptiveLuminance = nullptr;
  this->rpAdaptiveGlareBlurMap = nullptr;
  this->rpAdaptiveGlareBlurStep = nullptr;
  this->rpAdaptiveGlareParms = nullptr;
  this->declHighlightTable = nullptr;
  this->declHighlightExplodeTable = nullptr;
  this->defaultCubeModel = nullptr;
  this->unitCubeModel = nullptr;
  this->zeroOneCubeModel = nullptr;
  this->extrudeBoxModel = nullptr;
  this->unitSquareModel = nullptr;
  this->zeroOneSquareModel = nullptr;
  this->unitSquareTris = nullptr;
  do
  {
    *(p_renderDestGui - 23) = nullptr;
    *(p_renderDestGui - 20) = nullptr;
    *(p_renderDestGui - 13) = nullptr;
    *(p_renderDestGui - 18) = nullptr;
    *(p_renderDestGui - 8) = nullptr;
    *(p_renderDestGui - 2) = nullptr;
    *++p_renderDestGui = nullptr;
    --v3;
  }
  while ( v3 != 0 );
  this->imgScreenMip3 = nullptr;
  this->imgScreenMip3Alt = nullptr;
  this->imgGui = nullptr;
  this->renderDestViewDepth = nullptr;
  this->renderDestMip1 = nullptr;
  this->renderDestMip3 = nullptr;
  this->renderDestMip3Alt = nullptr;
  this->renderDestGui = nullptr;
  this->renderDestDimShadow = nullptr;
  this->imgLuminosity = nullptr;
  this->imgLuminosityAlt = nullptr;
  this->renderDestLuminosity = nullptr;
  this->renderDestLuminosityAlt = nullptr;
  this->windowWidth = 0;
  this->windowHeight = 0;
  this->renderWidth = 0;
  this->renderHeight = 0;
  memset(Dst: this->gammaTable, Val: 0, Size: sizeof(this->gammaTable));
  this->blackLevel[1] = 0.0;
  this->blackLevel[0] = 0.0;
  this->updateGammaTable = false;
  return this;
}


// ========================================================================
// __unwind$236538
// EA  : 0x82948DE8
// RVA : 0x00948DE8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236538()
{
  int v0; // r12

  idRenderSystem::~idRenderSystem(this: *(idRenderSystem **)(v0 - 304 + 324));
}


// ========================================================================
// __unwind$236539
// EA  : 0x82948E10
// RVA : 0x00948E10
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236539()
{
  int v0; // r12

  idRenderFrameInfo::~idRenderFrameInfo(this: (idRenderFrameInfo *)(*(_DWORD *)(v0 - 304 + 324) + 592));
}


// ========================================================================
// __unwind$236540
// EA  : 0x82948E3C
// RVA : 0x00948E3C
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236540()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$236541
// EA  : 0x82948E64
// RVA : 0x00948E64
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236541()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 208));
}


// ========================================================================
// __unwind$236542
// EA  : 0x82948E8C
// RVA : 0x00948E8C
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236542()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 304 + 324) + 7152));
}


// ========================================================================
// __unwind$236543
// EA  : 0x82948EB8
// RVA : 0x00948EB8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236543()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$236544
// EA  : 0x82948EE0
// RVA : 0x00948EE0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236544()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$236545
// EA  : 0x82948F08
// RVA : 0x00948F08
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236545()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 304 + 324) + 7256));
}


// ========================================================================
// __unwind$236546
// EA  : 0x82948F34
// RVA : 0x00948F34
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236546()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 240));
}


// ========================================================================
// __unwind$236547
// EA  : 0x82948F5C
// RVA : 0x00948F5C
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236547()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 176));
}


// ========================================================================
// __unwind$236548_0
// EA  : 0x82948F84
// RVA : 0x00948F84
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236548_0()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 304 + 324) + 7360));
}


// ========================================================================
// ?EndFrame@idRenderSystemLocal@@UAAXPAXHHPAVidRenderWorld@@QAPAVidRenderModel@@H_N33H@Z
// EA  : 0x82949018
// RVA : 0x00949018
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::EndFrame(
        idRenderSystemLocal *this,
        void *hdc,
        int windowWidth_,
        int windowHeight_,
        idRenderWorld *world,
        idRenderModel **guis,
        int numGuis,
        BOOL allowSMP,
        bool skipSwapBuffers,
        bool resolveDepth,
        int timeMsec,
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
        bool a28,
        int a29,
        bool a30,
        int a31,
        int a32)
{
  int size; // r11
  idScreenView *list; // r30
  idRenderView *v42; // r3
  idList<enum encounterGroupRole_t,5> *p_viewGuis; // r28
  int i; // r30
  idStaticList<idScreenView,3> v45; // [sp+50h] [-1800h] BYREF
  char v46; // [sp+17D0h] [-80h]

  idStaticList<idScreenView,3>::idStaticList<idScreenView,3>(this: &v45);
  v46 = 0;
  size = v45.size;
  if ( v45.size < 1 )
  {
    if ( (unsigned __int8)idList<idScreenView,5>::Resize(this: &v45, newsize: 1) == 0 )
      goto LABEL_7;
    size = v45.size;
  }
  if ( size > 1 )
    size = 1;
  v45.num = size;
LABEL_7:
  list = v45.list;
  if ( world != nullptr )
  {
    v42 = world->RenderViewForIndex(this: world, a2: 0);
    renderView_t::operator=(this: &list->g, __that: &v42->g);
    list->g.renderTime = a32;
  }
  list->world = world;
  list->screenRect.x1 = 0;
  list->screenRect.y1 = 0;
  list->screenRect.x2 = windowWidth_ - 1;
  list->screenRect.y2 = windowHeight_ - 1;
  list->viewIndex = 0;
  if ( numGuis > 0 )
  {
    p_viewGuis = (idList<enum encounterGroupRole_t,5> *)&list->viewGuis;
    for ( i = numGuis; i != 0; --i )
      idList<idAnimWebBlendTree *,5>::Append(this: p_viewGuis, obj: (const encounterGroupRole_t *)guis++);
  }
  this->RenderFrame(this, a2: hdc, a3: (const idRenderFrameInfo *)&v45, a4: allowSMP, a5: a28, a6: a30);
  idStaticList<idScreenView,3>::~idStaticList<idScreenView,3>(this: &v45);
}


// ========================================================================
// __unwind$236660_0
// EA  : 0x82949150
// RVA : 0x00949150
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236660_0()
{
  int v0; // r12

  idRenderFrameInfo::~idRenderFrameInfo(this: (idRenderFrameInfo *)(v0 - 6224 + 80));
}


// ========================================================================
// ?RenderFrame@idRenderSystemLocal@@UAAXQAXABVidRenderFrameInfo@@_N22@Z
// EA  : 0x82949180
// RVA : 0x00949180
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RenderFrame(
        idRenderSystemLocal *this,
        void *const hdc,
        const idRenderFrameInfo *renderFrameInfo,
        const bool allowSMP,
        bool skipSwapBuffers,
        bool resolveDepth)
{
  idRenderSystemLocal_vtbl *v12; // r11
  unsigned int LastError; // r3
  idRenderFrameInfo *p_currentRenderFrameInfo; // r25
  idFile *v15; // r3
  renderView_t *p_g; // r30
  unsigned __int64 v17; // r3
  int num; // r8
  encounterGroupRole_t *list; // r7
  int v20; // r27
  int v21; // r29
  int v22; // r28
  int v23; // r30
  int v24; // r10
  encounterGroupRole_t *v25; // r11
  int v26; // r29
  int v27; // r30
  int v28; // r29
  int v29; // r30
  idScreenView *v30; // r11
  idRenderWorldLocal *world; // r3
  unsigned __int64 v32; // r3
  int valueInteger; // [sp+50h] [-150h] BYREF
  idRenderModel *v34; // [sp+54h] [-14Ch] BYREF
  idList<enum encounterGroupRole_t,5> v35; // [sp+60h] [-140h] BYREF
  _BYTE v36[304]; // [sp+70h] [-130h] BYREF

  if ( !this->insideEndFrame )
  {
    v12 = this->__vftable;
    this->insideEndFrame = true;
    v12->SyncRenderThread(this, a2: false);
    if ( r_recordEndFrameTrace.valueInteger == 1 )
    {
      LastError = GetLastError();
      idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
    }
    idRenderSystemLocal::PrintStatistics(this);
    idRenderSystemLocal::LogMetrics(this);
    idVirtualTextureSystem::LogMetrics(this: &virtualTextureSystem);
    idResolutionScale::LogMetrics(this: &resolutionScale);
    idRenderSystemLocal::LogPerformanceCountersForMap(this);
    memset(Dst: &this->pc, Val: 0, Size: sizeof(this->pc));
    GL_ClearStats();
    idRenderLog::StartFrame(this: &renderLog);
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_SETUP_RENDERING_DATA);
    p_currentRenderFrameInfo = &this->currentRenderFrameInfo;
    ++this->frameCount;
    idStaticList<idScreenView,3>::operator=(
      this: &this->currentRenderFrameInfo.screenViews,
      __that: &renderFrameInfo->screenViews);
    this->currentRenderFrameInfo.captureFrame = renderFrameInfo->captureFrame;
    valueInteger = r_recordFlyThrough.valueInteger;
    if ( r_recordFlyThrough.valueInteger > 0 )
    {
      v15 = file;
      if ( file == nullptr )
      {
        file = fileSystem->OpenFileWrite(this: fileSystem, a2: "flythrough.views", a3: 0);
        file->Write(this: file, a2: &valueInteger, a3: 4u);
        v15 = file;
      }
      p_g = &renderFrameInfo->screenViews.list->g;
      v15->Write(this: v15, a2: p_g, a3: 4u);
      file->Write(this: file, a2: &p_g->viewID, a3: 4u);
      file->Write(this: file, a2: &p_g->forceFullVirtualTextureLoad, a3: 1u);
      file->Write(this: file, a2: &p_g->discontinuousViewPosition, a3: 1u);
      file->Write(this: file, a2: &p_g->skipDimShadows, a3: 1u);
      file->Write(this: file, a2: &p_g->skipPostProcess, a3: 1u);
      file->Write(this: file, a2: &p_g->skipDynamicEnvironment, a3: 1u);
      file->Write(this: file, a2: &p_g->forceFullResolution, a3: 1u);
      file->Write(this: file, a2: &p_g->useHQViewColorMipsGeneration, a3: 1u);
      file->Write(this: file, a2: &p_g->fov_x, a3: 4u);
      file->Write(this: file, a2: &p_g->fov_y, a3: 4u);
      file->Write(this: file, a2: &p_g->cramZNear, a3: 1u);
      file->Write(this: file, a2: &p_g->explicitProjectionMatrix, a3: 64u);
      file->Write(this: file, a2: &p_g->useExplicitProjectionMatrix, a3: 1u);
      file->Write(this: file, a2: &p_g->vieworg, a3: 12u);
      file->Write(this: file, a2: &p_g->viewaxis, a3: 36u);
      file->Write(this: file, a2: &p_g->forceIdentityViewMatrix, a3: 1u);
      if ( valueInteger == 1 )
      {
        if ( file != nullptr )
          ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
        file = nullptr;
        idLib::Printf(fmt: "fly through recorded!\n");
      }
      idCVar::SetInteger(this: &r_recordFlyThrough, newValue: valueInteger - 1, force: true);
    }
    idImageManager::CheckCvars(this: globalImages);
    if ( this->blackLevel[0] != this->blackLevel[1] )
    {
      this->blackLevel[1] = this->blackLevel[0];
      this->updateGammaTable = true;
    }
    idRenderLog::CloseMainBlock(this: &renderLog);
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_COMMIT_RENDERING_DATA);
    LODWORD(v17) = Sys_Microseconds() >> 32;
    this->pc.startLatchTimeMicroSec = v17;
    num = 0;
    v35.size = 48;
    list = (encounterGroupRole_t *)v36;
    v35.granularity = 1;
    v35.num = 0;
    v35.memTag = 5;
    v35.list = (encounterGroupRole_t *)v36;
    v35.listStatic = 1;
    v20 = 0;
    if ( this->currentRenderFrameInfo.screenViews.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = 0;
        if ( p_currentRenderFrameInfo->screenViews.list[v21].viewGuis.num > 0 )
        {
          v23 = 0;
          do
          {
            v34 = p_currentRenderFrameInfo->screenViews.list[v21].viewGuis.list[v23];
            if ( v34 != nullptr && !v34->deleteOnSync )
            {
              v24 = 0;
              if ( num <= 0 )
                goto LABEL_26;
              v25 = list;
              while ( *(idRenderModel **)v25 != v34 )
              {
                ++v24;
                ++v25;
                if ( v24 >= num )
                  goto LABEL_26;
              }
              if ( v24 < 0 )
              {
LABEL_26:
                idList<idAnimWebBlendTree *,5>::Append(this: &v35, obj: (const encounterGroupRole_t *)&v34);
                num = v35.num;
                list = v35.list;
              }
            }
            ++v22;
            ++v23;
          }
          while ( v22 < p_currentRenderFrameInfo->screenViews.list[v21].viewGuis.num );
        }
        ++v20;
        ++v21;
      }
      while ( v20 < this->currentRenderFrameInfo.screenViews.num );
    }
    v26 = 0;
    if ( num > 0 )
    {
      v27 = 0;
      while ( 1 )
      {
        idRenderModel::Commit(this: (idRenderModel *)list[v27]);
        (*(void (__fastcall **)(encounterGroupRole_t, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v35.list[v27] + 36))(
          a1: v35.list[v27],
          a2: 0,
          a3: 0,
          a4: 0);
        ++v26;
        ++v27;
        if ( v26 >= v35.num )
          break;
        list = v35.list;
      }
    }
    v28 = 0;
    if ( this->currentRenderFrameInfo.screenViews.num > 0 )
    {
      v29 = 0;
      do
      {
        v30 = &p_currentRenderFrameInfo->screenViews.list[v29];
        world = (idRenderWorldLocal *)v30->world;
        if ( world != nullptr )
        {
          v34 = (idRenderModel *)v30->world;
          idRenderWorldLocal::CommitData(this: world);
        }
        ++v28;
        ++v29;
      }
      while ( v28 < this->currentRenderFrameInfo.screenViews.num );
    }
    LODWORD(v32) = Sys_Microseconds() >> 32;
    this->pc.endLatchTimeMicroSec = v32;
    idRenderLog::CloseMainBlock(this: &renderLog);
    console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorPurple);
    soundSystem->WaitForSoundThread(this: soundSystem);
    if ( this->inhibitRendering != 0 || idLib::headless )
    {
      UnbindBufferObjects();
    }
    else if ( r_useSMP.valueInteger != 0 )
    {
      idRenderSystemLocal::RestartRenderThread(this, hdc);
      if ( !allowSMP )
        this->SyncRenderThread(this, a2: false);
    }
    else
    {
      this->MakeCurrent(this, a2: hdc);
      idRenderSystemLocal::RenderFrameInternal(this, renderMode: RENDER_MODE_MANUAL, hdc, skipSwapBuffers, resolveDepth);
    }
    if ( r_recordEndFrameTrace.valueInteger > 0 )
      idCVar::SetInteger(this: &r_recordEndFrameTrace, newValue: r_recordEndFrameTrace.valueInteger - 1, force: true);
    this->insideEndFrame = false;
    if ( (v35.listStatic == 0 || v35.listStatic == 2) && v35.list != nullptr )
      idMem::Free(this: &mem, ptr: v35.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$236714
// EA  : 0x82949830
// RVA : 0x00949830
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236714()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// ?playFlyThrough_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82949860
// RVA : 0x00949860
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __fastcall playFlyThrough_f(const idCmdArgs *args)
{
  idFile *v2; // r30
  bool v3; // cr57
  const char *v4; // r4
  unsigned int v5; // r29
  char *v6; // r25
  int i; // r28
  idRenderView *v8; // r30
  idRenderWorldLocal *primaryWorld; // r30
  int Height; // r20
  int ScanoutWidth; // r19
  void *v12; // r3
  bool v13; // [sp+Bh] [-235h]
  bool v14; // [sp+Fh] [-231h]
  int v15; // [sp+10h] [-230h]
  int v16; // [sp+14h] [-22Ch]
  int v17; // [sp+18h] [-228h]
  int v18; // [sp+1Ch] [-224h]
  int v19; // [sp+20h] [-220h]
  int v20; // [sp+24h] [-21Ch]
  int v21; // [sp+28h] [-218h]
  int v22; // [sp+2Ch] [-214h]
  int v23; // [sp+30h] [-210h]
  int v24; // [sp+34h] [-20Ch]
  int v25; // [sp+38h] [-208h]
  int v26; // [sp+3Ch] [-204h]
  int v27; // [sp+40h] [-200h]
  int v28; // [sp+44h] [-1FCh]
  int v29; // [sp+48h] [-1F8h]
  int v30; // [sp+4Ch] [-1F4h]
  int v31; // [sp+50h] [-1F0h]
  int v32; // [sp+58h] [-1E8h]
  int v33; // [sp+60h] [-1E0h]
  _DWORD v34[4]; // [sp+70h] [-1D0h] BYREF
  idFile_Memory v35; // [sp+80h] [-1C0h] BYREF

  v2 = fileSystem->OpenFileRead(this: fileSystem, a2: "flythrough.views", a3: 1, a4: 0);
  if ( v2 != nullptr )
  {
    v3 = args->argc > 1;
    v34[1] = args->argc;
    if ( v3 )
    {
      idLib::Printf(fmt: "vt_recordStats %s\n", args->argv[1]);
      if ( args->argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idCVar::SetString(this: &vt_recordStats, newValue: v4, force: true);
      idStreamFileCache::ClearHDC(this: streamFileCache);
      idVirtualTextureSystem::EmptyCache(this: &virtualTextureSystem, skipVmtrCache: false);
    }
    idCVar::SetBool(this: &r_swapInterval, newValue: true, force: true);
    v5 = v2->Length(this: v2);
    v6 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\renderer\\RenderSystem.cpp(2061) : TAG_FILE",
                   size: v5,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v2->Read(this: v2, a2: v6, a3: v5);
    ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
    idFile_Memory::idFile_Memory(this: &v35, name: "flythrough");
    idFile_Memory::SetReadOnlyData(this: &v35, data: v6, length: v5);
    v34[0] = -1;
    v35.Read(this: &v35, a2: v34, a3: 4u);
    for ( i = 0; i < v34[0]; ++i )
    {
      v8 = *tr.primaryWorld->renderViews.list;
      v35.Read(this: &v35, a2: (void *)v8, a3: 4u);
      v35.Read(this: &v35, a2: &v8->g.viewID, a3: 4u);
      v35.Read(this: &v35, a2: &v8->g.forceFullVirtualTextureLoad, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.discontinuousViewPosition, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.skipDimShadows, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.skipPostProcess, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.skipDynamicEnvironment, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.forceFullResolution, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.useHQViewColorMipsGeneration, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.fov_x, a3: 4u);
      v35.Read(this: &v35, a2: &v8->g.fov_y, a3: 4u);
      v35.Read(this: &v35, a2: &v8->g.cramZNear, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.explicitProjectionMatrix, a3: 64u);
      v35.Read(this: &v35, a2: &v8->g.useExplicitProjectionMatrix, a3: 1u);
      v35.Read(this: &v35, a2: &v8->g.vieworg, a3: 12u);
      v35.Read(this: &v35, a2: &v8->g.viewaxis, a3: 36u);
      v35.Read(this: &v35, a2: &v8->g.forceIdentityViewMatrix, a3: 1u);
      primaryWorld = tr.primaryWorld;
      Height = idRenderSystemLocal::GetHeight(this: &tr);
      ScanoutWidth = idRenderSystemLocal::GetScanoutWidth(this: &tr);
      v12 = (void *)XGComparePixelShaders();
      idRenderSystemLocal::EndFrame(
        this: &tr,
        hdc: v12,
        windowWidth_: ScanoutWidth,
        windowHeight_: Height,
        world: primaryWorld,
        guis: nullptr,
        numGuis: 0,
        allowSMP: false,
        skipSwapBuffers: v13,
        resolveDepth: v14,
        timeMsec: v15,
        a12: v16,
        a13: v17,
        a14: v18,
        a15: v19,
        a16: v20,
        a17: v21,
        a18: v22,
        a19: v23,
        a20: v24,
        a21: v25,
        a22: v26,
        a23: v27,
        a24: v28,
        a25: v29,
        a26: v30,
        a27: v31,
        a28: false,
        a29: v32,
        a30: false,
        a31: v33,
        a32: 0);
    }
    idFile_Memory::~idFile_Memory(this: &v35);
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    if ( args->argc > 1 )
      idCVar::SetString(this: &vt_recordStats, newValue: &byte_8200D768, force: true);
    idLib::Printf(fmt: "playback done!\n");
  }
  else
  {
    idLib::Printf(fmt: "failed to open file %s\n", "flythrough.views");
  }
}


// ========================================================================
// __unwind$236982
// EA  : 0x82949CC4
// RVA : 0x00949CC4
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _unwind_236982()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 576 + 128));
}


// ========================================================================
// `dynamic initializer for 'tr''
// EA  : 0x8335AEA8
// RVA : 0x0135AEA8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tr__()
{
  idRenderSystemLocal::idRenderSystemLocal(this: &tr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tr__);
}


// ========================================================================
// `dynamic initializer for 'r_swapInterval''
// EA  : 0x8335AEE0
// RVA : 0x0135AEE0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_swapInterval__()
{
  idCVar::idCVar(
    this: &r_swapInterval,
    name: "r_swapInterval",
    value: "1",
    flags: 2,
    description: "changes D3DRS_PRESENTINTERVAL. 0 = off, 1 = swap-tear 60Hz, 2 = vsync 30Hz",
    valueCompletion: (const char **)idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_swapInterval__);
}


// ========================================================================
// `dynamic initializer for 'r_shadows''
// EA  : 0x8335AF40
// RVA : 0x0135AF40
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_shadows__()
{
  idCVar::idCVar(
    this: &r_shadows,
    name: "r_shadows",
    value: "1",
    flags: 1,
    description: "enable shadows",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_shadows__);
}


// ========================================================================
// `dynamic initializer for 'r_skipPostProcess''
// EA  : 0x8335AF98
// RVA : 0x0135AF98
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipPostProcess__()
{
  idCVar::idCVar(
    this: &r_skipPostProcess,
    name: "r_skipPostProcess",
    value: "0",
    flags: 2,
    description: "skip post processing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipPostProcess__);
}


// ========================================================================
// `dynamic initializer for 'r_skipEmissiveGlare''
// EA  : 0x8335AFF0
// RVA : 0x0135AFF0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipEmissiveGlare__()
{
  idCVar::idCVar(
    this: &r_skipEmissiveGlare,
    name: "r_skipEmissiveGlare",
    value: "0",
    flags: 2,
    description: "skip emissive glare processing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipEmissiveGlare__);
}


// ========================================================================
// `dynamic initializer for 'r_testMegaTexture''
// EA  : 0x8335B048
// RVA : 0x0135B048
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testMegaTexture__()
{
  idCVar::idCVar(
    this: &r_testMegaTexture,
    name: "r_testMegaTexture",
    value: "0",
    flags: 1,
    description: "draw the entire megatexture as a flat quad",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testMegaTexture__);
}


// ========================================================================
// `dynamic initializer for 'r_testWorld''
// EA  : 0x8335B0A0
// RVA : 0x0135B0A0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testWorld__()
{
  idCVar::idCVar(
    this: &r_testWorld,
    name: "r_testWorld",
    value: "0",
    flags: 1,
    description: "use the testWorld instead of the passed world",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testWorld__);
}


// ========================================================================
// `dynamic initializer for 'r_showTotalSurfaceArea''
// EA  : 0x8335B0F8
// RVA : 0x0135B0F8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTotalSurfaceArea__()
{
  idCVar::idCVar(
    this: &r_showTotalSurfaceArea,
    name: "r_showTotalSurfaceArea",
    value: "0",
    flags: 2,
    description: "print the total surface area of all static surfaces (2=include non-statics too)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTotalSurfaceArea__);
}


// ========================================================================
// `dynamic initializer for 'r_useDynamicEnvironment''
// EA  : 0x8335B150
// RVA : 0x0135B150
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useDynamicEnvironment__()
{
  idCVar::idCVar(
    this: &r_useDynamicEnvironment,
    name: "r_useDynamicEnvironment",
    value: "1",
    flags: 2,
    description: "generate a new environment map every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useDynamicEnvironment__);
}


// ========================================================================
// `dynamic initializer for 'r_useSMP''
// EA  : 0x8335B1A8
// RVA : 0x0135B1A8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useSMP__()
{
  idCVar::idCVar(
    this: &r_useSMP,
    name: "r_useSMP",
    value: "1",
    flags: 1,
    description: "1 = run the renderer in a separate thread",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useSMP__);
}


// ========================================================================
// `dynamic initializer for 'r_usePBOTextureFeedback''
// EA  : 0x8335B200
// RVA : 0x0135B200
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_usePBOTextureFeedback__()
{
  idCVar::idCVar(
    this: &r_usePBOTextureFeedback,
    name: "r_usePBOTextureFeedback",
    value: "1",
    flags: 1,
    description: "use async pixel buffer read for texture feedback query",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_usePBOTextureFeedback__);
}


// ========================================================================
// `dynamic initializer for 'r_singleTriangle''
// EA  : 0x8335B258
// RVA : 0x0135B258
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_singleTriangle__()
{
  idCVar::idCVar(
    this: &r_singleTriangle,
    name: "r_singleTriangle",
    value: "0",
    flags: 1,
    description: "only draw a single triangle per primitive",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_singleTriangle__);
}


// ========================================================================
// `dynamic initializer for 'r_checkBounds''
// EA  : 0x8335B2B0
// RVA : 0x0135B2B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_checkBounds__()
{
  idCVar::idCVar(
    this: &r_checkBounds,
    name: "r_checkBounds",
    value: "0",
    flags: 1,
    description: "compare all surface bounds with precalculated ones in MakeRenderModelCurrent()",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_checkBounds__);
}


// ========================================================================
// `dynamic initializer for 'r_forceTwoSided''
// EA  : 0x8335B308
// RVA : 0x0135B308
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceTwoSided__()
{
  idCVar::idCVar(
    this: &r_forceTwoSided,
    name: "r_forceTwoSided",
    value: "0",
    flags: 2,
    description: "Force two sided rendering for everything",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceTwoSided__);
}


// ========================================================================
// `dynamic initializer for 'r_useStateCaching''
// EA  : 0x8335B360
// RVA : 0x0135B360
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useStateCaching__()
{
  idCVar::idCVar(
    this: &r_useStateCaching,
    name: "r_useStateCaching",
    value: "1",
    flags: 1,
    description: "avoid redundant state changes in GL_*() calls",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useStateCaching__);
}


// ========================================================================
// `dynamic initializer for 'r_finishEveryDraw''
// EA  : 0x8335B3B8
// RVA : 0x0135B3B8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_finishEveryDraw__()
{
  idCVar::idCVar(
    this: &r_finishEveryDraw,
    name: "r_finishEveryDraw",
    value: "0",
    flags: 1,
    description: "call glFinish() or equivalent after each draw call",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_finishEveryDraw__);
}


// ========================================================================
// `dynamic initializer for 'r_znear''
// EA  : 0x8335B410
// RVA : 0x0135B410
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_znear__()
{
  idCVar::idCVar(
    this: &r_znear,
    name: "r_znear",
    value: "3",
    flags: 4,
    description: "near Z clip plane distance",
    valueMin: 0.001,
    valueMax: 200.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_znear__);
}


// ========================================================================
// `dynamic initializer for 'r_zfar''
// EA  : 0x8335B478
// RVA : 0x0135B478
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_zfar__()
{
  idCVar::idCVar(
    this: &r_zfar,
    name: "r_zfar",
    value: "0",
    flags: 4,
    description: "far Z clip plane distance, 0 = infinity",
    valueMin: 0.0,
    valueMax: 200000.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_zfar__);
}


// ========================================================================
// `dynamic initializer for 'r_gamma''
// EA  : 0x8335B4E0
// RVA : 0x0135B4E0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_gamma__()
{
  idCVar::idCVar(
    this: &r_gamma,
    name: "r_gamma",
    value: "1.2",
    flags: 65540,
    description: "changes gamma tables",
    valueMin: 0.5,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_gamma__);
}


// ========================================================================
// `dynamic initializer for 'r_brightness''
// EA  : 0x8335B548
// RVA : 0x0135B548
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_brightness__()
{
  idCVar::idCVar(
    this: &r_brightness,
    name: "r_brightness",
    value: "1.0",
    flags: 65540,
    description: "changes gamma tables",
    valueMin: 0.5,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"DE_LEFT",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_brightness__);
}


// ========================================================================
// `dynamic initializer for 'r_jitter''
// EA  : 0x8335B5B0
// RVA : 0x0135B5B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jitter__()
{
  idCVar::idCVar(
    this: &r_jitter,
    name: "r_jitter",
    value: "0",
    flags: 1,
    description: "randomly subpixel jitter the projection matrix",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jitter__);
}


// ========================================================================
// `dynamic initializer for 'r_skipCommits''
// EA  : 0x8335B608
// RVA : 0x0135B608
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipCommits__()
{
  idCVar::idCVar(
    this: &r_skipCommits,
    name: "r_skipCommits",
    value: "0",
    flags: 1,
    description: "1 = don't accept any entity or light updates, making everything static",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipCommits__);
}


// ========================================================================
// `dynamic initializer for 'r_logFile''
// EA  : 0x8335B660
// RVA : 0x0135B660
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_logFile__()
{
  idCVar::idCVar(
    this: &r_logFile,
    name: "r_logFile",
    value: "0",
    flags: 2,
    description: "number of frames to emit render logs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_logFile__);
}


// ========================================================================
// `dynamic initializer for 'r_clear''
// EA  : 0x8335B6B8
// RVA : 0x0135B6B8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_clear__()
{
  idCVar::idCVar(
    this: &r_clear,
    name: "r_clear",
    value: "2",
    flags: 0,
    description: "force screen clear every frame, 1 = purple, 2 = black, 'r g b' = custom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_clear__);
}


// ========================================================================
// `dynamic initializer for 'r_testGamma''
// EA  : 0x8335B710
// RVA : 0x0135B710
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testGamma__()
{
  idCVar::idCVar(
    this: &r_testGamma,
    name: "r_testGamma",
    value: "0",
    flags: 4,
    description: "if > 0 draw a grid pattern to test gamma levels",
    valueMin: 0.0,
    valueMax: 195.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testGamma__);
}


// ========================================================================
// `dynamic initializer for 'r_testGammaBias''
// EA  : 0x8335B778
// RVA : 0x0135B778
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testGammaBias__()
{
  idCVar::idCVar(
    this: &r_testGammaBias,
    name: "r_testGammaBias",
    value: "0",
    flags: 4,
    description: "if > 0 draw a grid pattern to test gamma levels",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testGammaBias__);
}


// ========================================================================
// `dynamic initializer for 'r_calibrateGamma''
// EA  : 0x8335B7D0
// RVA : 0x0135B7D0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_calibrateGamma__()
{
  idCVar::idCVar(
    this: &r_calibrateGamma,
    name: "r_calibrateGamma",
    value: "0",
    flags: 4,
    description: "if > 0 draw a swatch at a specific luminance for calibrating gamma",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_calibrateGamma__);
}


// ========================================================================
// `dynamic initializer for 'r_calibrateGammaMode''
// EA  : 0x8335B828
// RVA : 0x0135B828
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_calibrateGammaMode__()
{
  idCVar::idCVar(
    this: &r_calibrateGammaMode,
    name: "r_calibrateGammaMode",
    value: "0",
    flags: 4,
    description: "0=measure total luminance, 1=measure red, 2=measure green, 3=measure blue",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_calibrateGammaMode__);
}


// ========================================================================
// `dynamic initializer for 'r_calibrateGammaLum''
// EA  : 0x8335B880
// RVA : 0x0135B880
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_calibrateGammaLum__()
{
  idCVar::idCVar(
    this: &r_calibrateGammaLum,
    name: "r_calibrateGammaLum",
    value: "0",
    flags: 4,
    description: "luminance to display for calibrating gamma [0,255]",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_calibrateGammaLum__);
}


// ========================================================================
// `dynamic initializer for 'r_skipVmtrs''
// EA  : 0x8335B8D8
// RVA : 0x0135B8D8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipVmtrs__()
{
  idCVar::idCVar(
    this: &r_skipVmtrs,
    name: "r_skipVmtrs",
    value: "0",
    flags: 1,
    description: "1 = skip loading of vmtrs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipVmtrs__);
}


// ========================================================================
// `dynamic initializer for 'r_showVertexColor''
// EA  : 0x8335B930
// RVA : 0x0135B930
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showVertexColor__()
{
  idCVar::idCVar(
    this: &r_showVertexColor,
    name: "r_showVertexColor",
    value: "0",
    flags: 1,
    description: "draws all triangles with the solid vertex color",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showVertexColor__);
}


// ========================================================================
// `dynamic initializer for 'r_showCommits''
// EA  : 0x8335B988
// RVA : 0x0135B988
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showCommits__()
{
  idCVar::idCVar(
    this: &r_showCommits,
    name: "r_showCommits",
    value: "0",
    flags: 2,
    description: "report model and light commits and ref counts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showCommits__);
}


// ========================================================================
// `dynamic initializer for 'r_showDynamic''
// EA  : 0x8335B9E0
// RVA : 0x0135B9E0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDynamic__()
{
  idCVar::idCVar(
    this: &r_showDynamic,
    name: "r_showDynamic",
    value: "0",
    flags: 2,
    description: "report stats on dynamic surface generation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDynamic__);
}


// ========================================================================
// `dynamic initializer for 'r_showTrace''
// EA  : 0x8335BA38
// RVA : 0x0135BA38
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTrace__()
{
  idCVar::idCVar(
    this: &r_showTrace,
    name: "r_showTrace",
    value: "0",
    flags: 2,
    description: "show the intersection of an eye trace with the world",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTrace__);
}


// ========================================================================
// `dynamic initializer for 'r_showIntensity''
// EA  : 0x8335BAA0
// RVA : 0x0135BAA0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showIntensity__()
{
  idCVar::idCVar(
    this: &r_showIntensity,
    name: "r_showIntensity",
    value: "0",
    flags: 1,
    description: "draw the screen colors based on intensity, red = 0, green = 128, blue = 255",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showIntensity__);
}


// ========================================================================
// `dynamic initializer for 'r_showDestinationAlpha''
// EA  : 0x8335BAF8
// RVA : 0x0135BAF8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDestinationAlpha__()
{
  idCVar::idCVar(
    this: &r_showDestinationAlpha,
    name: "r_showDestinationAlpha",
    value: "0",
    flags: 1,
    description: "draw destination alpha",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDestinationAlpha__);
}


// ========================================================================
// `dynamic initializer for 'r_showStats''
// EA  : 0x8335BB50
// RVA : 0x0135BB50
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showStats__()
{
  idCVar::idCVar(
    this: &r_showStats,
    name: "r_showStats",
    value: "0",
    flags: 2,
    description: "report render stats",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showStats__);
}


// ========================================================================
// `dynamic initializer for 'r_showQueries''
// EA  : 0x8335BBA8
// RVA : 0x0135BBA8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showQueries__()
{
  idCVar::idCVar(
    this: &r_showQueries,
    name: "r_showQueries",
    value: "0",
    flags: 1,
    description: "reports the number of occlusion queries per frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showQueries__);
}


// ========================================================================
// `dynamic initializer for 'r_showLights''
// EA  : 0x8335BC00
// RVA : 0x0135BC00
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showLights__()
{
  idCVar::idCVar(
    this: &r_showLights,
    name: "r_showLights",
    value: "0",
    flags: 2,
    description: "1 = just print volumes numbers, highlighting ones covering the view, 2 = also draw planes of each volume, 3 = also d"
    "raw edges of each volume",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showLights__);
}


// ========================================================================
// `dynamic initializer for 'r_showModels''
// EA  : 0x8335BC68
// RVA : 0x0135BC68
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showModels__()
{
  idCVar::idCVar(
    this: &r_showModels,
    name: "r_showModels",
    value: "0",
    flags: 2,
    description: "1 = displays the bounding boxes of all view models, 2 = print index numbers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showModels__);
}


// ========================================================================
// `dynamic initializer for 'r_showEnvs''
// EA  : 0x8335BCC0
// RVA : 0x0135BCC0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showEnvs__()
{
  idCVar::idCVar(
    this: &r_showEnvs,
    name: "r_showEnvs",
    value: "0",
    flags: 1,
    description: "displays the bounding boxes of all the dynamic environments",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showEnvs__);
}


// ========================================================================
// `dynamic initializer for 'r_showSurfaceBounds''
// EA  : 0x8335BD18
// RVA : 0x0135BD18
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showSurfaceBounds__()
{
  idCVar::idCVar(
    this: &r_showSurfaceBounds,
    name: "r_showSurfaceBounds",
    value: "0",
    flags: 2,
    description: "1 = displays the bounding boxes of all model surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showSurfaceBounds__);
}


// ========================================================================
// `dynamic initializer for 'r_showAnimatedBounds''
// EA  : 0x8335BD70
// RVA : 0x0135BD70
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showAnimatedBounds__()
{
  idCVar::idCVar(
    this: &r_showAnimatedBounds,
    name: "r_showAnimatedBounds",
    value: "0",
    flags: 2,
    description: "displays the bounding boxes of all animated models (1 = frame, 2 = normalized, 4 = translated)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showAnimatedBounds__);
}


// ========================================================================
// `dynamic initializer for 'r_showAmbientLighting''
// EA  : 0x8335BDC8
// RVA : 0x0135BDC8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showAmbientLighting__()
{
  idCVar::idCVar(
    this: &r_showAmbientLighting,
    name: "r_showAmbientLighting",
    value: "0",
    flags: 2,
    description: "Draw boxes for all the ambient samples, and lines from all dynamic models to their chosen ambients",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showAmbientLighting__);
}


// ========================================================================
// `dynamic initializer for 'r_showDynamicLightingSingleModel''
// EA  : 0x8335BE20
// RVA : 0x0135BE20
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDynamicLightingSingleModel__()
{
  idCVar::idCVar(
    this: &r_showDynamicLightingSingleModel,
    name: "r_showDynamicLightingSingleModel",
    value: "-1",
    flags: 2,
    description: "suppress show dynamic lighting on all but one model specified with this model index",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDynamicLightingSingleModel__);
}


// ========================================================================
// `dynamic initializer for 'r_showOcclusionBaseModel''
// EA  : 0x8335BE78
// RVA : 0x0135BE78
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showOcclusionBaseModel__()
{
  idCVar::idCVar(
    this: &r_showOcclusionBaseModel,
    name: "r_showOcclusionBaseModel",
    value: "0",
    flags: 2,
    description: "show sound BSP base occlusion model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showOcclusionBaseModel__);
}


// ========================================================================
// `dynamic initializer for 'r_showManifolds''
// EA  : 0x8335BED0
// RVA : 0x0135BED0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showManifolds__()
{
  idCVar::idCVar(
    this: &r_showManifolds,
    name: "r_showManifolds",
    value: "0",
    flags: 2,
    description: "0 = off, 1 = all manifolds, 2 = significant manifolds, 3 = omni-significant manifolds, 4 = show detail manifolds, 5 "
    "= show pipe manifolds, 6 = subdivided world manifolds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showManifolds__);
}


// ========================================================================
// `dynamic initializer for 'r_showTJunctions''
// EA  : 0x8335BF28
// RVA : 0x0135BF28
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTJunctions__()
{
  idCVar::idCVar(
    this: &r_showTJunctions,
    name: "r_showTJunctions",
    value: "0",
    flags: 2,
    description: "0 = off, 1 = all t-junctions, 2 = t-junctions on significant occluders, 3 = j-junctions with vertices between two co"
    "linear edges, 4 =  = j-junctions with vertices between two colinear edges on significant occluders",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTJunctions__);
}


// ========================================================================
// `dynamic initializer for 'r_showDuplicateTriangles''
// EA  : 0x8335BF80
// RVA : 0x0135BF80
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDuplicateTriangles__()
{
  idCVar::idCVar(
    this: &r_showDuplicateTriangles,
    name: "r_showDuplicateTriangles",
    value: "0",
    flags: 1,
    description: "show duplicate triangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDuplicateTriangles__);
}


// ========================================================================
// `dynamic initializer for 'r_showSpecularTriangles''
// EA  : 0x8335BFD8
// RVA : 0x0135BFD8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showSpecularTriangles__()
{
  idCVar::idCVar(
    this: &r_showSpecularTriangles,
    name: "r_showSpecularTriangles",
    value: "0",
    flags: 1,
    description: "show specular triangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showSpecularTriangles__);
}


// ========================================================================
// `dynamic initializer for 'r_showWorldAreas''
// EA  : 0x8335C030
// RVA : 0x0135C030
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showWorldAreas__()
{
  idCVar::idCVar(
    this: &r_showWorldAreas,
    name: "r_showWorldAreas",
    value: "0",
    flags: 2,
    description: "0 = 0ff, 1 = show world areas, 2 = lock view and show world areas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showWorldAreas__);
}


// ========================================================================
// `dynamic initializer for 'r_showLightCount''
// EA  : 0x8335C088
// RVA : 0x0135C088
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showLightCount__()
{
  idCVar::idCVar(
    this: &r_showLightCount,
    name: "r_showLightCount",
    value: "0",
    flags: 2,
    description: "1 = colors surfaces based on light count, 2 = also print overdraw",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showLightCount__);
}


// ========================================================================
// `dynamic initializer for 'r_showTris''
// EA  : 0x8335C0F0
// RVA : 0x0135C0F0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTris__()
{
  idCVar::idCVar(
    this: &r_showTris,
    name: "r_showTris",
    value: "0",
    flags: 2,
    description: "enables wireframe rendering of the world, 1 = only draw visible ones, 2 = draw all front facing, 3 = draw all, 4 = o"
    "nly visible ones with blended lines",
    valueMin: -4.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_82950000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<-4,4>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTris__);
}


// ========================================================================
// `dynamic initializer for 'r_showDrawColor''
// EA  : 0x8335C158
// RVA : 0x0135C158
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDrawColor__()
{
  idCVar::idCVar(
    this: &r_showDrawColor,
    name: "r_showDrawColor",
    value: "1 1 1 0.4",
    flags: 0,
    description: "specifies the draw color for r_showTris mode 4",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDrawColor__);
}


// ========================================================================
// `dynamic initializer for 'r_showTwoSided''
// EA  : 0x8335C1B0
// RVA : 0x0135C1B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTwoSided__()
{
  idCVar::idCVar(
    this: &r_showTwoSided,
    name: "r_showTwoSided",
    value: "0",
    flags: 2,
    description: "outline two sided geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTwoSided__);
}


// ========================================================================
// `dynamic initializer for 'r_showBlendedSurfaces''
// EA  : 0x8335C208
// RVA : 0x0135C208
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showBlendedSurfaces__()
{
  idCVar::idCVar(
    this: &r_showBlendedSurfaces,
    name: "r_showBlendedSurfaces",
    value: "0",
    flags: 2,
    description: "outline and draw blended geometry, 1 = all, 2 = emissive pass, 3 = blended pass, 4 = background sort, 5 = emit sort,"
    " 6 = light sort, 7 = decal sort, 8 = trans sort, 9 = water sort",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showBlendedSurfaces__);
}


// ========================================================================
// `dynamic initializer for 'r_showSurfaceInfo''
// EA  : 0x8335C260
// RVA : 0x0135C260
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showSurfaceInfo__()
{
  idCVar::idCVar(
    this: &r_showSurfaceInfo,
    name: "r_showSurfaceInfo",
    value: "0",
    flags: 2,
    description: "show surface material name under crosshair",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showSurfaceInfo__);
}


// ========================================================================
// `dynamic initializer for 'r_showNoDrawSurfaceInfo''
// EA  : 0x8335C2B8
// RVA : 0x0135C2B8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showNoDrawSurfaceInfo__()
{
  idCVar::idCVar(
    this: &r_showNoDrawSurfaceInfo,
    name: "r_showNoDrawSurfaceInfo",
    value: "0",
    flags: 1,
    description: "allow r_showSurfaceInfo to intersect materials that don't draw ( \"isdrawn 0\" )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showNoDrawSurfaceInfo__);
}


// ========================================================================
// `dynamic initializer for 'r_showTraceWorld''
// EA  : 0x8335C310
// RVA : 0x0135C310
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTraceWorld__()
{
  idCVar::idCVar(
    this: &r_showTraceWorld,
    name: "r_showTraceWorld",
    value: "0",
    flags: 2,
    description: "show traceworld info under crosshair",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTraceWorld__);
}


// ========================================================================
// `dynamic initializer for 'r_showNormals''
// EA  : 0x8335C368
// RVA : 0x0135C368
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showNormals__()
{
  idCVar::idCVar(
    this: &r_showNormals,
    name: "r_showNormals",
    value: "0",
    flags: 4,
    description: "draws wireframe normals",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showNormals__);
}


// ========================================================================
// `dynamic initializer for 'r_showDepth''
// EA  : 0x8335C3C0
// RVA : 0x0135C3C0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDepth__()
{
  idCVar::idCVar(
    this: &r_showDepth,
    name: "r_showDepth",
    value: "0",
    flags: 1,
    description: "display the contents of the depth buffer and the depth range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDepth__);
}


// ========================================================================
// `dynamic initializer for 'r_showCracks''
// EA  : 0x8335C418
// RVA : 0x0135C418
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showCracks__()
{
  idCVar::idCVar(
    this: &r_showCracks,
    name: "r_showCracks",
    value: "0",
    flags: 2,
    description: "display cracks less that the given number of pixels wide",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showCracks__);
}


// ========================================================================
// `dynamic initializer for 'r_showStencil''
// EA  : 0x8335C470
// RVA : 0x0135C470
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showStencil__()
{
  idCVar::idCVar(
    this: &r_showStencil,
    name: "r_showStencil",
    value: "0",
    flags: 1,
    description: "display the contents of the stencil buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showStencil__);
}


// ========================================================================
// `dynamic initializer for 'r_showPrimitives''
// EA  : 0x8335C4C8
// RVA : 0x0135C4C8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showPrimitives__()
{
  idCVar::idCVar(
    this: &r_showPrimitives,
    name: "r_showPrimitives",
    value: "0",
    flags: 2,
    description: "report drawsurf/index/vertex counts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showPrimitives__);
}


// ========================================================================
// `dynamic initializer for 'r_showEdges''
// EA  : 0x8335C520
// RVA : 0x0135C520
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showEdges__()
{
  idCVar::idCVar(
    this: &r_showEdges,
    name: "r_showEdges",
    value: "0",
    flags: 1,
    description: "draw the sil edges",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showEdges__);
}


// ========================================================================
// `dynamic initializer for 'r_showNonTwoManifoldEdges''
// EA  : 0x8335C578
// RVA : 0x0135C578
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showNonTwoManifoldEdges__()
{
  idCVar::idCVar(
    this: &r_showNonTwoManifoldEdges,
    name: "r_showNonTwoManifoldEdges",
    value: "0",
    flags: 1,
    description: "draw edges that are not shared by exactly two triangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showNonTwoManifoldEdges__);
}


// ========================================================================
// `dynamic initializer for 'r_showTexelDensity''
// EA  : 0x8335C5D0
// RVA : 0x0135C5D0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTexelDensity__()
{
  idCVar::idCVar(
    this: &r_showTexelDensity,
    name: "r_showTexelDensity",
    value: "0",
    flags: 2,
    description: "shade triangles by texel density.  Set > 0 to scale range by specified amount.  Colors mean: 0: black, 1: purple, 2:"
    " blue, 3: green, 4: yellow, 5: orange, 6: red, 7+: white.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTexelDensity__);
}


// ========================================================================
// `dynamic initializer for 'r_showTexturePolarity''
// EA  : 0x8335C628
// RVA : 0x0135C628
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTexturePolarity__()
{
  idCVar::idCVar(
    this: &r_showTexturePolarity,
    name: "r_showTexturePolarity",
    value: "0",
    flags: 1,
    description: "shade triangles by texture area polarity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTexturePolarity__);
}


// ========================================================================
// `dynamic initializer for 'r_showTangentSpace''
// EA  : 0x8335C680
// RVA : 0x0135C680
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTangentSpace__()
{
  idCVar::idCVar(
    this: &r_showTangentSpace,
    name: "r_showTangentSpace",
    value: "0",
    flags: 2,
    description: "shade triangles by tangent space, 1 = use 1st tangent vector, 2 = use 2nd tangent vector, 3 = use normal vector",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTangentSpace__);
}


// ========================================================================
// `dynamic initializer for 'r_showTextureSpace''
// EA  : 0x8335C6E8
// RVA : 0x0135C6E8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTextureSpace__()
{
  idCVar::idCVar(
    this: &r_showTextureSpace,
    name: "r_showTextureSpace",
    value: "0",
    flags: 2,
    description: "shade triangles by texture space",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTextureSpace__);
}


// ========================================================================
// `dynamic initializer for 'r_showTextureDistortion''
// EA  : 0x8335C740
// RVA : 0x0135C740
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTextureDistortion__()
{
  idCVar::idCVar(
    this: &r_showTextureDistortion,
    name: "r_showTextureDistortion",
    value: "0",
    flags: 2,
    description: "shade triangles based on UV stretching",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTextureDistortion__);
}


// ========================================================================
// `dynamic initializer for 'r_showTriangleInfo''
// EA  : 0x8335C798
// RVA : 0x0135C798
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTriangleInfo__()
{
  idCVar::idCVar(
    this: &r_showTriangleInfo,
    name: "r_showTriangleInfo",
    value: "0",
    flags: 2,
    description: "show vertex numbers and tangents of the triangle the crosshair is over",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Mips",
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTriangleInfo__);
}


// ========================================================================
// `dynamic initializer for 'r_showTransSortOverdraw''
// EA  : 0x8335C800
// RVA : 0x0135C800
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTransSortOverdraw__()
{
  idCVar::idCVar(
    this: &r_showTransSortOverdraw,
    name: "r_showTransSortOverdraw",
    value: "0",
    flags: 4,
    description: " if > 0 show overdraw from transparency sorted surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTransSortOverdraw__);
}


// ========================================================================
// `dynamic initializer for 'r_showBlendedSurfOverdraw''
// EA  : 0x8335C858
// RVA : 0x0135C858
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showBlendedSurfOverdraw__()
{
  idCVar::idCVar(
    this: &r_showBlendedSurfOverdraw,
    name: "r_showBlendedSurfOverdraw",
    value: "0",
    flags: 1,
    description: " if > 0 show overdraw from all blended surfaces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showBlendedSurfOverdraw__);
}


// ========================================================================
// `dynamic initializer for 'r_testVMTR''
// EA  : 0x8335C8B0
// RVA : 0x0135C8B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testVMTR__()
{
  idCVar::idCVar(
    this: &r_testVMTR,
    name: "r_testVMTR",
    value: "0",
    flags: 4,
    description: " if > 0 displays the vmtr specified by r_currentMaterial centered on the screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testVMTR__);
}


// ========================================================================
// `dynamic initializer for 'r_testVMTRLod''
// EA  : 0x8335C908
// RVA : 0x0135C908
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testVMTRLod__()
{
  idCVar::idCVar(
    this: &r_testVMTRLod,
    name: "r_testVMTRLod",
    value: "0",
    flags: 2,
    description: "which LOD of the vmtr to display",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testVMTRLod__);
}


// ========================================================================
// `dynamic initializer for 'r_testAutosprites''
// EA  : 0x8335C960
// RVA : 0x0135C960
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testAutosprites__()
{
  idCVar::idCVar(
    this: &r_testAutosprites,
    name: "r_testAutosprites",
    value: "0",
    flags: 1,
    description: "display the autosprited geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testAutosprites__);
}


// ========================================================================
// `dynamic initializer for 'r_debugLineDepthTest''
// EA  : 0x8335C9B8
// RVA : 0x0135C9B8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugLineDepthTest__()
{
  idCVar::idCVar(
    this: &r_debugLineDepthTest,
    name: "r_debugLineDepthTest",
    value: "0",
    flags: 1,
    description: "perform depth test on debug lines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugLineDepthTest__);
}


// ========================================================================
// `dynamic initializer for 'r_debugPolyDepthTest''
// EA  : 0x8335CA10
// RVA : 0x0135CA10
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugPolyDepthTest__()
{
  idCVar::idCVar(
    this: &r_debugPolyDepthTest,
    name: "r_debugPolyDepthTest",
    value: "0",
    flags: 1,
    description: "perform depth test on debug polys",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugPolyDepthTest__);
}


// ========================================================================
// `dynamic initializer for 'r_debugLineWidth''
// EA  : 0x8335CA68
// RVA : 0x0135CA68
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugLineWidth__()
{
  idCVar::idCVar(
    this: &r_debugLineWidth,
    name: "r_debugLineWidth",
    value: "1",
    flags: 2,
    description: "width of debug lines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugLineWidth__);
}


// ========================================================================
// `dynamic initializer for 'r_debugArrowStep''
// EA  : 0x8335CAC0
// RVA : 0x0135CAC0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugArrowStep__()
{
  idCVar::idCVar(
    this: &r_debugArrowStep,
    name: "r_debugArrowStep",
    value: "120",
    flags: 65538,
    description: "step size of arrow cone line rotation in degrees",
    valueMin: 0.0,
    valueMax: 120.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugArrowStep__);
}


// ========================================================================
// `dynamic initializer for 'r_debugPolygonFilled''
// EA  : 0x8335CB28
// RVA : 0x0135CB28
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugPolygonFilled__()
{
  idCVar::idCVar(
    this: &r_debugPolygonFilled,
    name: "r_debugPolygonFilled",
    value: "1",
    flags: 1,
    description: "draw a filled polygon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugPolygonFilled__);
}


// ========================================================================
// `dynamic initializer for 'r_forceFullVirtualTextureLoad''
// EA  : 0x8335CB80
// RVA : 0x0135CB80
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceFullVirtualTextureLoad__()
{
  idCVar::idCVar(
    this: &r_forceFullVirtualTextureLoad,
    name: "r_forceFullVirtualTextureLoad",
    value: "0",
    flags: 1,
    description: "force each frame to do a full virtual texture load for capturing video, etc * SLOW *",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceFullVirtualTextureLoad__);
}


// ========================================================================
// `dynamic initializer for 'r_skipAnalyze''
// EA  : 0x8335CBD8
// RVA : 0x0135CBD8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipAnalyze__()
{
  idCVar::idCVar(
    this: &r_skipAnalyze,
    name: "r_skipAnalyze",
    value: "0",
    flags: 2,
    description: "skip the feedback analysis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipAnalyze__);
}


// ========================================================================
// `dynamic initializer for 'r_skipUpdateInView''
// EA  : 0x8335CC30
// RVA : 0x0135CC30
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipUpdateInView__()
{
  idCVar::idCVar(
    this: &r_skipUpdateInView,
    name: "r_skipUpdateInView",
    value: "0",
    flags: 1,
    description: "skip world update in view call",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipUpdateInView__);
}


// ========================================================================
// `dynamic initializer for 'r_waitForQuery''
// EA  : 0x8335CC88
// RVA : 0x0135CC88
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_waitForQuery__()
{
  idCVar::idCVar(
    this: &r_waitForQuery,
    name: "r_waitForQuery",
    value: "1",
    flags: 1,
    description: "Stall until occlusion query returns",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_waitForQuery__);
}


// ========================================================================
// `dynamic initializer for 'r_lazyBindPrograms''
// EA  : 0x8335CCE0
// RVA : 0x0135CCE0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_lazyBindPrograms__()
{
  idCVar::idCVar(
    this: &r_lazyBindPrograms,
    name: "r_lazyBindPrograms",
    value: "1",
    flags: 1,
    description: "lazy program binds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_lazyBindPrograms__);
}


// ========================================================================
// `dynamic initializer for 'r_lazyBindParms''
// EA  : 0x8335CD38
// RVA : 0x0135CD38
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_lazyBindParms__()
{
  idCVar::idCVar(
    this: &r_lazyBindParms,
    name: "r_lazyBindParms",
    value: "1",
    flags: 1,
    description: "lazy update of render parms",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_lazyBindParms__);
}


// ========================================================================
// `dynamic initializer for 'r_lazyBindTextures''
// EA  : 0x8335CD90
// RVA : 0x0135CD90
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_lazyBindTextures__()
{
  idCVar::idCVar(
    this: &r_lazyBindTextures,
    name: "r_lazyBindTextures",
    value: "1",
    flags: 1,
    description: "lazy texture binds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_lazyBindTextures__);
}


// ========================================================================
// `dynamic initializer for 'r_stripFragmentBranches''
// EA  : 0x8335CDE8
// RVA : 0x0135CDE8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_stripFragmentBranches__()
{
  idCVar::idCVar(
    this: &r_stripFragmentBranches,
    name: "r_stripFragmentBranches",
    value: "1",
    flags: 1,
    description: "strip branches from fragment programs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_stripFragmentBranches__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDetailTris''
// EA  : 0x8335CE40
// RVA : 0x0135CE40
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDetailTris__()
{
  idCVar::idCVar(
    this: &r_skipDetailTris,
    name: "r_skipDetailTris",
    value: "0",
    flags: 1,
    description: "skip all detail triangles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDetailTris__);
}


// ========================================================================
// `dynamic initializer for 'r_flatShadeOnMissingMegas''
// EA  : 0x8335CE98
// RVA : 0x0135CE98
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_flatShadeOnMissingMegas__()
{
  idCVar::idCVar(
    this: &r_flatShadeOnMissingMegas,
    name: "r_flatShadeOnMissingMegas",
    value: "1",
    flags: 1,
    description: "draw missing megatextures as flat shaded upon loading map",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_flatShadeOnMissingMegas__);
}


// ========================================================================
// `dynamic initializer for 'r_flatShadeOnMapLoad''
// EA  : 0x8335CEF0
// RVA : 0x0135CEF0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_flatShadeOnMapLoad__()
{
  idCVar::idCVar(
    this: &r_flatShadeOnMapLoad,
    name: "r_flatShadeOnMapLoad",
    value: "0",
    flags: 1,
    description: "set to flat shade on all map loads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_flatShadeOnMapLoad__);
}


// ========================================================================
// `dynamic initializer for 'r_defaultPolyOfsUnits''
// EA  : 0x8335CF48
// RVA : 0x0135CF48
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_defaultPolyOfsUnits__()
{
  idCVar::idCVar(
    this: &r_defaultPolyOfsUnits,
    name: "r_defaultPolyOfsUnits",
    value: "-0.0001",
    flags: 4,
    description: "default polygonOffset units",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_defaultPolyOfsUnits__);
}


// ========================================================================
// `dynamic initializer for 'r_defaultPolyOfsFactor''
// EA  : 0x8335CFA0
// RVA : 0x0135CFA0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_defaultPolyOfsFactor__()
{
  idCVar::idCVar(
    this: &r_defaultPolyOfsFactor,
    name: "r_defaultPolyOfsFactor",
    value: "-1.0",
    flags: 4,
    description: "default polygonOffset factor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_defaultPolyOfsFactor__);
}


// ========================================================================
// `dynamic initializer for 'r_currentMaterial''
// EA  : 0x8335CFF8
// RVA : 0x0135CFF8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_currentMaterial__()
{
  idCVar::idCVar(
    this: &r_currentMaterial,
    name: "r_currentMaterial",
    value: &byte_8200D768,
    flags: 0,
    description: "current material name from r_showSurfaceInfo",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_currentMaterial__);
}


// ========================================================================
// `dynamic initializer for 'r_forceAspectRatio''
// EA  : 0x8335D050
// RVA : 0x0135D050
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceAspectRatio__()
{
  idCVar::idCVar(
    this: &r_forceAspectRatio,
    name: "r_forceAspectRatio",
    value: "0",
    flags: 4,
    description: "1.777 for 16:9, 1.6 for 16:10, 1.333 for 4:3, 0 to disable",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceAspectRatio__);
}


// ========================================================================
// `dynamic initializer for 'r_sleep''
// EA  : 0x8335D0A8
// RVA : 0x0135D0A8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_sleep__()
{
  idCVar::idCVar(
    this: &r_sleep,
    name: "r_sleep",
    value: "0",
    flags: 2,
    description: "Sleep for this many milliseconds to simulate low frame rates.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_sleep__);
}


// ========================================================================
// `dynamic initializer for 'r_recordFlyThrough''
// EA  : 0x8335D100
// RVA : 0x0135D100
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_recordFlyThrough__()
{
  idCVar::idCVar(
    this: &r_recordFlyThrough,
    name: "r_recordFlyThrough",
    value: "0",
    flags: 2,
    description: "record a fly through for the given number of frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_recordFlyThrough__);
}


// ========================================================================
// `dynamic initializer for 'r_recordEndFrameTrace''
// EA  : 0x8335D158
// RVA : 0x0135D158
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_recordEndFrameTrace__()
{
  idCVar::idCVar(
    this: &r_recordEndFrameTrace,
    name: "r_recordEndFrameTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_recordEndFrameTrace__);
}


// ========================================================================
// `dynamic initializer for 'r_recordRendererTrace''
// EA  : 0x8335D1B0
// RVA : 0x0135D1B0
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_recordRendererTrace__()
{
  idCVar::idCVar(
    this: &r_recordRendererTrace,
    name: "r_recordRendererTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_recordRendererTrace__);
}


// ========================================================================
// `dynamic initializer for 'mtrBink''
// EA  : 0x8335D208
// RVA : 0x0135D208
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__mtrBink__()
{
  mtrBink.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrBink;
}


// ========================================================================
// `dynamic initializer for 'progBink''
// EA  : 0x8335D228
// RVA : 0x0135D228
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__progBink__()
{
  progBink.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progBink;
}


// ========================================================================
// `dynamic initializer for 'rpViewColor''_0
// EA  : 0x8335D248
// RVA : 0x0135D248
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpViewColor___0()
{
  rpViewColor_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpViewColor_0;
}


// ========================================================================
// `dynamic initializer for 'rpLoadingIcon''
// EA  : 0x8335D268
// RVA : 0x0135D268
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpLoadingIcon__()
{
  rpLoadingIcon.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLoadingIcon;
}


// ========================================================================
// `dynamic initializer for 'rpTransMap''_0
// EA  : 0x8335D288
// RVA : 0x0135D288
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpTransMap___0()
{
  rpTransMap_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpTransMap_0;
}


// ========================================================================
// `dynamic initializer for 'progGuiBlend''_0
// EA  : 0x8335D2A8
// RVA : 0x0135D2A8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__progGuiBlend___0()
{
  progGuiBlend.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progGuiBlend;
}


// ========================================================================
// `dynamic initializer for 'progViewColorIdentity''_0
// EA  : 0x8335D2C8
// RVA : 0x0135D2C8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

void _dynamic_initializer_for__progViewColorIdentity___0()
{
  progViewColorIdentity_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progViewColorIdentity_0;
}


// ========================================================================
// `dynamic initializer for 'playFlyThrough_v''
// EA  : 0x8335D2E8
// RVA : 0x0135D2E8
// PDB : w:\tech5\engine\renderer\rendersystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playFlyThrough_v__()
{
  return idCommandLink::idCommandLink(
           this: &playFlyThrough_v,
           cmdName: "playFlyThrough",
           function: playFlyThrough_f,
           description: "play back a fly through",
           argCompletion: nullptr);
}

