
// ========================================================================
// ??1idRenderWorld@@UAA@XZ
// EA  : 0x82956D88
// RVA : 0x00956D88
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorld::~idRenderWorld(idRenderWorld *this)
{
  this->__vftable = (idRenderWorld_vtbl *)&idRenderWorld::`vftable';
}


// ========================================================================
// ?TestEnvironment@idRenderWorldLocal@@UAAXPBVidDeclEnv@@@Z
// EA  : 0x82956D98
// RVA : 0x00956D98
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::TestEnvironment(idRenderWorldLocal *this, const idDeclEnv *envEffectsDecl)
{
  this->testEnv = envEffectsDecl;
}


// ========================================================================
// ?StampModel@idRenderWorldLocal@@UAAPAVidRenderModel@@XZ
// EA  : 0x82956DA8
// RVA : 0x00956DA8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModel *__fastcall idRenderWorldLocal::StampModel(idRenderWorldLocal *this)
{
  idRenderModel **p_stampModel; // r31

  p_stampModel = &this->stampModel;
  if ( this->stampModel == nullptr )
    *p_stampModel = this->AllocRenderModel(this, a2: "_stamp", a3: 1, a4: -1);
  return *p_stampModel;
}


// ========================================================================
// ?FoliageRenderModel@idRenderWorldLocal@@UAAPAVidRenderModelFoliage@@XZ
// EA  : 0x82956E08
// RVA : 0x00956E08
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModelFoliage *__fastcall idRenderWorldLocal::FoliageRenderModel(idRenderWorldLocal *this)
{
  idRenderModelFoliage **p_foliageRenderModel; // r31
  idRenderModel *v2; // r3

  p_foliageRenderModel = &this->foliageRenderModel;
  if ( this->foliageRenderModel == nullptr )
  {
    v2 = this->AllocRenderModel(this, a2: "_foliage", a3: 0, a4: -1);
    *p_foliageRenderModel = (idRenderModelFoliage *)_RTDynamicCast(
                                                      inptr: v2,
                                                      VfDelta: 0,
                                                      SrcType: &idRenderModel `RTTI Type Descriptor',
                                                      TargetType: &idRenderModelFoliage `RTTI Type Descriptor',
                                                      isReference: 0);
  }
  return *p_foliageRenderModel;
}


// ========================================================================
// ?DetailRenderModel@idRenderWorldLocal@@UAAPAVidRenderModelDetail@@XZ
// EA  : 0x82956E88
// RVA : 0x00956E88
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModelDetail *__fastcall idRenderWorldLocal::DetailRenderModel(idRenderWorldLocal *this)
{
  idRenderModelDetail **p_detailRenderModel; // r31
  idRenderModel *v2; // r3

  p_detailRenderModel = &this->detailRenderModel;
  if ( this->detailRenderModel == nullptr )
  {
    v2 = this->AllocRenderModel(this, a2: "_detail", a3: 0, a4: -1);
    *p_detailRenderModel = (idRenderModelDetail *)_RTDynamicCast(
                                                    inptr: v2,
                                                    VfDelta: 0,
                                                    SrcType: &idRenderModel `RTTI Type Descriptor',
                                                    TargetType: &idRenderModelDetail `RTTI Type Descriptor',
                                                    isReference: 0);
  }
  return *p_detailRenderModel;
}


// ========================================================================
// ?TransparencyRenderModel@idRenderWorldLocal@@UAAPAVidRenderModelTransparency@@XZ
// EA  : 0x82956F08
// RVA : 0x00956F08
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModelTransparency *__fastcall idRenderWorldLocal::TransparencyRenderModel(idRenderWorldLocal *this)
{
  return this->transparencyRenderModel;
}


// ========================================================================
// ?DecalModel@idRenderWorldLocal@@UAAPAVidRenderModelDecal@@XZ
// EA  : 0x82956F18
// RVA : 0x00956F18
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModelDecal *__fastcall idRenderWorldLocal::DecalModel(idRenderWorldLocal *this)
{
  return this->decalRenderModel;
}


// ========================================================================
// ?GetWorldRenderModel@idRenderWorldLocal@@UAAPBVidRenderModel@@XZ
// EA  : 0x82956F28
// RVA : 0x00956F28
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::GetWorldRenderModel(idRenderWorldLocal *this)
{
  idLib::FatalError(fmt: "GetWorldRenderModel called on console");
}


// ========================================================================
// ?BoundsInAreas_r@idRenderWorldLocal@@QBAXHABVidBounds@@PAH1H@Z
// EA  : 0x82956F38
// RVA : 0x00956F38
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::BoundsInAreas_r(
        idRenderWorldLocal *this,
        int nodeNum,
        idBounds *bounds,
        int *areas,
        int *numAreas,
        int maxAreas)
{
  bool v11; // cr56
  areaNode_t *v12; // r31
  int v13; // r3
  int v14; // r9
  int v15; // r8
  int v16; // r11
  int *v17; // r10

  v11 = nodeNum < 0;
  while ( !v11 )
  {
    v12 = &this->areaNodes[nodeNum];
    v13 = idBounds::PlaneSide(this: bounds, plane: &v12->plane, epsilon: 0.1);
    if ( v13 == 0 )
      goto LABEL_7;
    nodeNum = v12->children[1];
    if ( v13 != 1 )
    {
      if ( nodeNum != 0 )
      {
        idRenderWorldLocal::BoundsInAreas_r(this, nodeNum, bounds, areas, numAreas, maxAreas);
        if ( *numAreas >= maxAreas )
          return;
      }
LABEL_7:
      nodeNum = v12->children[0];
    }
    v11 = nodeNum < 0;
    if ( nodeNum == 0 )
      return;
  }
  v14 = *numAreas;
  v15 = -1 - nodeNum;
  v16 = 0;
  if ( *numAreas > 0 )
  {
    v17 = areas;
    do
    {
      if ( *v17 == v15 )
        break;
      ++v16;
      ++v17;
    }
    while ( v16 < *numAreas );
  }
  if ( v16 >= v14 && v14 < maxAreas )
  {
    areas[v14] = v15;
    ++*numAreas;
  }
}


// ========================================================================
// ?ShadowSample@idRenderWorldLocal@@UBAMABVidVec3@@@Z
// EA  : 0x82957040
// RVA : 0x00957040
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

double __fastcall idRenderWorldLocal::ShadowSample(idRenderWorldLocal *this, const idVec3 *worldPoint)
{
  return idGlobalShadows::ShadowSample(this: &this->globalShadows, worldPoint);
}


// ========================================================================
// ?NumEnvironments@idRenderWorldLocal@@UBAHXZ
// EA  : 0x82957100
// RVA : 0x00957100
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

ILeapFilter *__fastcall idRenderWorldLocal::NumEnvironments(XAUDIO2::CX2SubmixVoice *this)
{
  return this->m_pAudioFilter;
}


// ========================================================================
// ?GetCurrentBlendedParms@idRenderWorldLocal@@UBAABVidParmBlock@@XZ
// EA  : 0x82957108
// RVA : 0x00957108
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

const idParmBlock *__fastcall idRenderWorldLocal::GetCurrentBlendedParms(idRenderWorldLocal *this)
{
  return &this->RenderViewForIndex(this, a2: 0)->blendedEnvironmentParms;
}


// ========================================================================
// ?GetEnvironmentDeclForCurrentViewPoint@idRenderWorldLocal@@UBAPBVidDeclEnv@@XZ
// EA  : 0x82957140
// RVA : 0x00957140
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

const idDeclEnv *__fastcall idRenderWorldLocal::GetEnvironmentDeclForCurrentViewPoint(idRenderWorldLocal *this)
{
  int v2; // r28
  int i; // r29
  float *v4; // r31
  idRenderView *v5; // r3
  double x; // fp12
  double y; // fp13
  double z; // fp0
  char v9; // r11

  v2 = 0;
  if ( this->dynamicEnvironments.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v4 = (float *)&this->dynamicEnvironments.list[i];
    v5 = this->RenderViewForIndex(this, a2: 0);
    x = v5->g.vieworg.x;
    if ( x < *v4
      || (y = v5->g.vieworg.y) < v4[1]
      || (z = v5->g.vieworg.z) < v4[2]
      || x > v4[3]
      || y > v4[4]
      || (v9 = 1, z > v4[5]) )
    {
      v9 = 0;
    }
    if ( v9 != 0 )
      break;
    if ( ++v2 >= this->dynamicEnvironments.num )
      return nullptr;
  }
  return this->dynamicEnvironments.list[v2].env;
}


// ========================================================================
// ?MarkAllLightsAsSerialized@idRenderWorldLocal@@UAAXXZ
// EA  : 0x82957228
// RVA : 0x00957228
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::MarkAllLightsAsSerialized(idRenderWorldLocal *this)
{
  int v2; // r29
  int v3; // r31
  idRenderLight **list; // r11
  idRenderLight *v5; // r10

  v2 = 0;
  if ( this->renderLights.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->renderLights.list;
      v5 = list[v3];
      if ( v5 != nullptr && !v5->skipAutoReplication )
        this->MarkLightSerialized(this, a2: list[v3], a3: true, a4: false);
      ++v2;
      ++v3;
    }
    while ( v2 < this->renderLights.num );
  }
}


// ========================================================================
// ?RenderViewForIndex@idRenderWorldLocal@@UBAPAVidRenderView@@H@Z
// EA  : 0x829572A8
// RVA : 0x009572A8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderView *__fastcall idRenderWorldLocal::RenderViewForIndex(idRenderWorldLocal *this, int index)
{
  if ( index >= 0 && index < this->renderViews.num )
    return this->renderViews.list[index];
  idLib::Printf(fmt: "idRenderWorld::RenderViewForIndex: invalid index %i [0, %i]\n", index, this->renderViews.num);
  return nullptr;
}


// ========================================================================
// ?RenderModelForIndex@idRenderWorldLocal@@UBAPAVidRenderModel@@H@Z
// EA  : 0x82957320
// RVA : 0x00957320
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModel *__fastcall idRenderWorldLocal::RenderModelForIndex(idRenderWorldLocal *this, int index)
{
  if ( index >= 0 && index < this->renderModels.num )
    return this->renderModels.list[index];
  idLib::Printf(fmt: "idRenderWorld::RenderModelForIndex: invalid index %i [0, %i]\n", index, this->renderModels.num);
  return nullptr;
}


// ========================================================================
// ?RenderLightForIndex@idRenderWorldLocal@@UBAPAVidRenderLight@@H@Z
// EA  : 0x82957380
// RVA : 0x00957380
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderLight *__fastcall idRenderWorldLocal::RenderLightForIndex(idRenderWorldLocal *this, int index)
{
  if ( index >= 0 && index < this->renderLights.num )
    return this->renderLights.list[index];
  idLib::Printf(fmt: "idRenderWorld::RenderLightForIndex: invalid index %i [0, %i]\n", index, this->renderLights.num);
  return nullptr;
}


// ========================================================================
// ?MegatextureForIndex@idRenderWorldLocal@@UBA?AW4pageSource_t@@H@Z
// EA  : 0x829573E0
// RVA : 0x009573E0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

pageSource_t __fastcall idRenderWorldLocal::MegatextureForIndex(idRenderWorldLocal *this, int index)
{
  if ( index >= 0 && index < this->megaTextures.num )
    return this->megaTextures.list[index]->pageSource;
  idLib::Printf(fmt: "idRenderWorld::MegatextureForIndex: invalid index %i [0, %i]\n", index, this->megaTextures.num);
  return PAGESOURCE_INVALID;
}


// ========================================================================
// ?GetStaticWorldBounds@idRenderWorldLocal@@UBAXAAVidBounds@@@Z
// EA  : 0x82957458
// RVA : 0x00957458
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::GetStaticWorldBounds(idRenderWorldLocal *this, idBounds *bounds)
{
  int v2; // r7
  int v3; // r9
  worldArea_t *worldAreas; // r11
  int v5; // r8
  int v6; // r10
  worldArea_t *v7; // r11
  idRenderModelSurface *v8; // r11
  float *geometry; // r11
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v13; // fp10
  double v15; // fp7

  v2 = 0;
  bounds->b[0].z = 1.0e30;
  bounds->b[0].y = 1.0e30;
  bounds->b[0].x = 1.0e30;
  bounds->b[1].z = -1.0e30;
  bounds->b[1].y = -1.0e30;
  bounds->b[1].x = -1.0e30;
  if ( this->numWorldAreas > 0 )
  {
    v3 = 0;
    do
    {
      worldAreas = this->worldAreas;
      v5 = 0;
      if ( worldAreas[v3].worldSurfaces.num > 0 )
      {
        v6 = 0;
        v7 = &worldAreas[v3];
        do
        {
          v8 = &v7->worldSurfaces.list[v6];
          if ( v8 != nullptr )
          {
            geometry = (float *)v8->geometry;
            y = bounds->b[0].y;
            z = bounds->b[0].z;
            x = bounds->b[1].x;
            v13 = bounds->b[1].y;
            _FP8 = (float)(bounds->b[0].x - *geometry);
            v15 = bounds->b[1].z;
            __asm { fsel      f6, f8, f9, f0 }
            bounds->b[0].x = _FP6;
            _FP4 = (float)((float)y - geometry[1]);
            __asm { fsel      f3, f4, f5, f13 }
            bounds->b[0].y = _FP3;
            _FP1 = (float)((float)z - geometry[2]);
            __asm { fsel      f0, f1, f2, f12 }
            bounds->b[0].z = _FP0;
            _FP12 = (float)(geometry[3] - (float)x);
            __asm { fsel      f11, f12, f13, f11 }
            bounds->b[1].x = _FP11;
            _FP8 = (float)(geometry[4] - (float)v13);
            __asm { fsel      f6, f8, f9, f10 }
            bounds->b[1].y = _FP6;
            _FP4 = (float)(geometry[5] - (float)v15);
            __asm { fsel      f3, f4, f5, f7 }
            bounds->b[1].z = _FP3;
          }
          ++v5;
          ++v6;
          v7 = &this->worldAreas[v3];
        }
        while ( v5 < v7->worldSurfaces.num );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->numWorldAreas );
  }
}


// ========================================================================
// ?ClearOcclusionQueryForModel@idRenderWorldLocal@@QAAXPAVidRenderModel@@@Z
// EA  : 0x82957580
// RVA : 0x00957580
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ClearOcclusionQueryForModel(idRenderWorldLocal *this, idRenderModel *model)
{
  __int64 v2; // r6
  int v3; // r10
  int v4; // r11
  int v5; // r9

  LODWORD(v2) = 0;
  v3 = 0;
  if ( this->renderViews.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      HIDWORD(v2) = this->renderViews.list[v4++];
      v5 = *(_DWORD *)(HIDWORD(v2) + 4464);
      HIDWORD(v2) = 8 * ((model->committed->index.index >> 8) + 8256);
      *(_QWORD *)(HIDWORD(v2) + v5) = v2;
    }
    while ( v3 < this->renderViews.num );
  }
}


// ========================================================================
// ?ShowApproximateLighting@idRenderWorldLocal@@QAAXPAVidRenderModelCommitted@@ABUapproximateLightingParms_t@@@Z
// EA  : 0x829575E8
// RVA : 0x009575E8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ShowApproximateLighting(
        idRenderWorldLocal *this,
        idRenderModelCommitted *model,
        const approximateLightingParms_t *parms)
{
  idRenderWorldLocal_vtbl *v6; // r30
  idBox *v7; // r3
  double x; // fp13
  idRenderWorldLocal_vtbl *v9; // r11
  double y; // fp12
  double z; // fp10
  double v12; // fp9
  __int64 v13; // r8
  int v14; // r27
  int v15; // r26
  int i; // r30
  lightContribution_t *contributions; // r11
  const idRenderLightCommitted *light; // r10
  lightContribution_t *v19; // r11
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r9
  double v21; // fp0
  int v22; // r10
  double v23; // fp13
  double v24; // fp13
  double v25; // fp11
  __int64 v26; // r10
  __int64 v27; // r6
  idRenderView **list; // r26
  va *v29; // r3
  __int64 v30; // r6
  idRenderView **v31; // r30
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  int v35; // r27
  int v36; // r30
  char v37; // r8
  int v38; // r11
  const idRenderLightCommitted **lights; // r10
  float *v40; // r11
  double v41; // fp0
  double v42; // fp13
  void (__fastcall *v43)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  int v44; // [sp+8h] [-1158h]
  int v45; // [sp+8h] [-1158h]
  int v46; // [sp+Ch] [-1154h]
  int v47; // [sp+Ch] [-1154h]
  int v48; // [sp+10h] [-1150h]
  int v49; // [sp+10h] [-1150h]
  int v50; // [sp+14h] [-114Ch]
  int v51; // [sp+14h] [-114Ch]
  int v52; // [sp+18h] [-1148h]
  int v53; // [sp+18h] [-1148h]
  int v54; // [sp+1Ch] [-1144h]
  int v55; // [sp+1Ch] [-1144h]
  float v56[4]; // [sp+60h] [-1100h] BYREF
  float v57[4]; // [sp+70h] [-10F0h] BYREF
  float v58[4]; // [sp+80h] [-10E0h] BYREF
  float v59[8]; // [sp+90h] [-10D0h] BYREF
  idBox v60; // [sp+B0h] [-10B0h] BYREF
  va v61; // [sp+F0h] [-1070h] BYREF

  if ( r_showDynamicLightingSingleModel.valueInteger < 0
    || r_showDynamicLightingSingleModel.valueInteger == model->index.index >> 8 )
  {
    if ( r_showAmbientLighting.valueInteger != 0 )
      idAmbientLighting::DebugDrawAmbientLightingSamples(
        this: &this->ambientLighting,
        rw: this,
        pos: &parms->samplePoint);
    if ( r_showDynamicLighting.valueInteger != 0 && r_showDynamicLighting.valueInteger != 3 )
    {
      v6 = this->__vftable;
      v7 = idBox::idBox(this: &v60, bounds: &model->referenceBounds, origin: &model->r.origin, axis: &model->r.axis);
      v6->DebugBox(this, a2: (const idVec4 *)&idColor::colorWhite, a3: v7, a4: 1, a5: false);
      x = parms->samplePoint.x;
      v9 = this->__vftable;
      y = parms->samplePoint.y;
      z = parms->samplePoint.z;
      v12 = (float)(parms->samplePoint.y - (float)2.0);
      v59[0] = parms->samplePoint.x - (float)2.0;
      v59[1] = v12;
      v59[2] = (float)z - (float)2.0;
      v59[3] = (float)x + (float)2.0;
      v59[4] = (float)y + (float)2.0;
      v59[5] = (float)z + (float)2.0;
      v9->DebugBounds(
        this,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idBounds *)v59,
        a4: &vec3_origin,
        a5: 1,
        a6: false);
      v14 = 0;
      v15 = 0;
      for ( i = 0; i < 16; ++i )
      {
        contributions = parms->contributions;
        light = contributions[i].light;
        if ( light == nullptr )
          break;
        v19 = &contributions[i];
        DebugLine = this->DebugLine;
        v21 = v19->color.z;
        v22 = (_cntlzw(light->r.lightClass - 6) & 0x20) != 0;
        v23 = v19->color.y;
        v58[0] = v19->color.x;
        ++v14;
        v58[1] = v23;
        v15 += v22;
        v58[2] = v21;
        v58[3] = 1.0;
        DebugLine(
          this,
          a2: (const idVec4 *)v58,
          a3: &v19->light->globalLightOrigin,
          a4: &parms->samplePoint,
          a5: 3,
          a6: false);
      }
      if ( v14 >= 16 )
        idLib::Warning(fmt: "model %s has more than MAX_CONTRIBUTING_LIGHTS (%d)", model->name, 16);
      if ( v15 >= 2 )
        idLib::Warning(fmt: "model %s is affected by multiple LIGHT_PRIVATE_PRIME lights", model->name);
      v24 = parms->samplePoint.z;
      v25 = parms->samplePoint.y;
      LODWORD(v26) = model->index.index;
      v56[0] = parms->samplePoint.x;
      v56[1] = v25;
      HIDWORD(v26) = "Mips";
      HIDWORD(v27) = (unsigned int)v26 >> 8;
      v56[2] = (float)v24 + (float)8.0;
      LODWORD(v27) = model->name;
      list = this->renderViews.list;
      v29 = va::va(
              this: &v61,
              fmt: "%d: %s",
              a3: v27,
              a4: v13,
              a5: v26,
              a6: v44,
              a7: v46,
              a8: v48,
              a9: v50,
              a10: v52,
              a11: v54);
      ((void (__fastcall *)(idRenderWorldLocal *, va *, float *, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, idMat3 *, int, int, double))this->DebugText_2)(
        a1: this,
        a2: v29,
        a3: v56,
        a4: &off_82040000,
        a5: &idColor::colorWhite,
        a6: &(*list)->r.viewaxis,
        a7: 1,
        a8: 3,
        a9: 0.2);
      HIDWORD(v30) = parms->numLights;
      LODWORD(v30) = v14;
      v31 = this->renderViews.list;
      v34 = va::va(
              this: &v61,
              fmt: "%d / %d",
              a3: v30,
              a4: v33,
              a5: v32,
              a6: v45,
              a7: v47,
              a8: v49,
              a9: v51,
              a10: v53,
              a11: v55);
      ((void (__fastcall *)(idRenderWorldLocal *, va *, idVec3 *, idRenderWorldLocal_vtbl *, idColor *, idMat3 *, int, int, double))this->DebugText_2)(
        a1: this,
        a2: v34,
        a3: &parms->samplePoint,
        a4: this->__vftable,
        a5: &idColor::colorWhite,
        a6: &(*v31)->r.viewaxis,
        a7: 1,
        a8: 3,
        a9: 0.2);
      if ( r_showDynamicLighting.valueInteger == 2 )
      {
        v35 = 0;
        if ( parms->numLights > 0 )
        {
          v36 = 0;
          do
          {
            v37 = 0;
            v38 = 0;
            while ( parms->contributions[v38].light != parms->lights[v36] )
            {
              if ( ++v38 >= 16 )
                goto LABEL_22;
            }
            v37 = 1;
LABEL_22:
            if ( v37 == 0 )
            {
              lights = parms->lights;
              v40 = (float *)lights[v36];
              v41 = v40[281];
              v42 = v40[280];
              v43 = this->DebugLine;
              v57[0] = v40[279];
              v57[1] = v42;
              v57[2] = v41;
              v57[3] = 1.0;
              v43(
                this,
                a2: (const idVec4 *)v57,
                a3: &lights[v36]->globalLightOrigin,
                a4: &parms->samplePoint,
                a5: 3,
                a6: false);
            }
            ++v35;
            ++v36;
          }
          while ( v35 < parms->numLights );
        }
      }
    }
  }
}


// ========================================================================
// ?UpdateDeferredPositions@idRenderWorldLocal@@UAAXXZ
// EA  : 0x829579B0
// RVA : 0x009579B0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::UpdateDeferredPositions(idRenderWorldLocal *this)
{
  int v1; // r8
  int v2; // r9
  idRenderModel *v3; // r11

  v1 = 0;
  if ( this->renderModels.num > 0 )
  {
    v2 = 0;
    do
    {
      if ( this->commitModels.ptr[v1] )
      {
        v3 = this->renderModels.list[v2];
        if ( v3 != nullptr )
        {
          if ( v3->useDeferredPosition )
          {
            v3->g.origin.x = v3->deferredOrigin.x;
            v3->g.origin.y = v3->deferredOrigin.y;
            v3->g.origin.z = v3->deferredOrigin.z;
            v3->g.axis.mat[0].x = v3->deferredAxis.mat[0].x;
            v3->g.axis.mat[0].y = v3->deferredAxis.mat[0].y;
            v3->g.axis.mat[0].z = v3->deferredAxis.mat[0].z;
            v3->g.axis.mat[1].x = v3->deferredAxis.mat[1].x;
            v3->g.axis.mat[1].y = v3->deferredAxis.mat[1].y;
            v3->g.axis.mat[1].z = v3->deferredAxis.mat[1].z;
            v3->g.axis.mat[2].x = v3->deferredAxis.mat[2].x;
            v3->g.axis.mat[2].y = v3->deferredAxis.mat[2].y;
            v3->g.axis.mat[2].z = v3->deferredAxis.mat[2].z;
          }
          v3->deferredPositionInitialized = true;
        }
      }
      ++v1;
      ++v2;
    }
    while ( v1 < this->renderModels.num );
  }
}


// ========================================================================
// ?CommitData@idRenderWorldLocal@@QAAXXZ
// EA  : 0x82957A78
// RVA : 0x00957A78
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::CommitData(idRenderWorldLocal *this)
{
  int num; // r11
  int v3; // r29
  int v4; // r30
  idArray<bool,4096> *p_deletedModels; // r28
  idRenderModel *v6; // r3
  int v7; // r28
  int v8; // r26
  idArray<bool,4096> *p_commitModels; // r22
  bool *v10; // r29
  idRenderModel *v11; // r30
  BOOL unlinked; // r9
  idRenderModelCommitted *committed; // r27
  idRenderModel *referenceModel; // r3
  int v15; // r28
  int v16; // r26
  bool *v17; // r29
  idRenderLight *v18; // r30
  BOOL v19; // r8
  idRenderLightCommitted *v20; // r27

  num = this->renderModels.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    p_deletedModels = &this->deletedModels;
    do
    {
      if ( p_deletedModels->ptr[v3] )
      {
        v6 = this->renderModels.list[v4];
        if ( v6 != nullptr )
          ((void (__fastcall *)(idRenderModel *, int))v6->dtr_idRenderModel)(a1: v6, a2: 1);
        this->renderModels.list[v4] = nullptr;
        p_deletedModels->ptr[v3] = false;
      }
      num = this->renderModels.num;
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    p_commitModels = &this->commitModels;
    do
    {
      if ( p_commitModels->ptr[v7] )
      {
        p_commitModels->ptr[v7] = false;
        v10 = &this->postCommitModels.ptr[v7];
        *v10 = true;
        v11 = this->renderModels.list[v8];
        unlinked = v11->unlinked;
        committed = v11->committed;
        v11->needWriteToSnapshot = true;
        if ( unlinked || v11->deleteOnSync )
        {
          idRenderModel::ClearOcclusionQuery(this: v11);
          idRenderModelCommitted::FreeReferences(this: committed);
          idRenderModelCommitted::UnlinkAddAlways(this: committed);
          idRenderModelCommitted::UnlinkDimShadow(this: committed);
        }
        if ( v11->deleteOnSync )
        {
          *v10 = false;
          this->deletedModels.ptr[v7] = true;
        }
        else if ( v11->unlinked )
        {
          *((_BYTE *)&committed->r + 105) = *((_BYTE *)&v11->g + 105) & 4 | *((_BYTE *)&committed->r + 105) & 0xFB;
          *v10 = false;
        }
        else
        {
          idRenderModel::Commit(this: v11);
          referenceModel = v11->g.referenceModel;
          if ( referenceModel != nullptr && (*((_BYTE *)&this->renderModels.list[v8]->g + 105) & 4) == 0 )
            idRenderModel::Commit(this: referenceModel);
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->renderModels.num );
  }
  v15 = 0;
  if ( this->renderLights.num > 0 )
  {
    v16 = 0;
    do
    {
      if ( this->commitLights.ptr[v15] )
      {
        v17 = &this->postCommitLights.ptr[v15];
        this->commitModels.ptr[v15] = false;
        *v17 = true;
        v18 = this->renderLights.list[v16];
        v19 = v18->unlinked;
        v20 = v18->committed;
        v18->needWriteToSnapshot = true;
        if ( v19 || v18->deleteOnSync )
        {
          idRenderLightCommitted::FreeReferences(this: v20);
          *v17 = false;
        }
        if ( v18->deleteOnSync )
        {
          v20->world->renderLights.list[v16] = nullptr;
          idRenderLight::~idRenderLight(this: v18);
          idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
        }
        else if ( !v18->unlinked )
        {
          idRenderLight::Commit(this: v18);
        }
      }
      ++v15;
      ++v16;
    }
    while ( v15 < this->renderLights.num );
  }
  idRenderWorldLocal::DebugCommit(this);
}


// ========================================================================
// ?PostCommitData@idRenderWorldLocal@@QAAXXZ
// EA  : 0x82957D00
// RVA : 0x00957D00
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::PostCommitData(idRenderWorldLocal *this)
{
  int v2; // r30
  int v3; // r29
  idArray<bool,4096> *p_postCommitModels; // r28
  int v5; // r30
  int v6; // r29
  idArray<bool,4096> *p_postCommitLights; // r28

  v2 = 0;
  if ( this->renderModels.num > 0 )
  {
    v3 = 0;
    p_postCommitModels = &this->postCommitModels;
    do
    {
      if ( p_postCommitModels->ptr[v2] )
      {
        p_postCommitModels->ptr[v2] = false;
        idRenderModelCommitted::PostCommit(this: this->renderModels.list[v3]->committed);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->renderModels.num );
  }
  v5 = 0;
  if ( this->renderLights.num > 0 )
  {
    v6 = 0;
    p_postCommitLights = &this->postCommitLights;
    do
    {
      if ( p_postCommitLights->ptr[v5] )
      {
        p_postCommitLights->ptr[v5] = false;
        idRenderLightCommitted::PostCommit(this: this->renderLights.list[v6]->committed);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->renderLights.num );
  }
}


// ========================================================================
// ?ListRenderLights_f@idRenderWorldLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82957DC0
// RVA : 0x00957DC0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ListRenderLights_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r11
  int v2; // r29
  int v3; // r27
  int v4; // r31
  int v5; // r30
  idRenderLight *v6; // r11
  idRenderLightCommitted *committed; // r9
  const char *str; // r6

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    v2 = 0;
    v3 = 0;
    v4 = 0;
    if ( tr.primaryWorld->renderLights.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = primaryWorld->renderLights.list[v5];
        if ( v6 != nullptr )
        {
          committed = v6->committed;
          v3 += committed->references.num;
          if ( committed->lightMtr != nullptr )
            str = committed->lightMtr->name.str;
          else
            str = "NULL";
          idLib::Printf(fmt: "%4i: %2i refs %s\n", v4, v6->committed->references.num, str);
          ++v2;
        }
        else
        {
          idLib::Printf(fmt: "%4i: FREED\n", v4);
        }
        primaryWorld = tr.primaryWorld;
        ++v4;
        ++v5;
      }
      while ( v4 < tr.primaryWorld->renderLights.num );
    }
    idLib::Printf(fmt: "%i renderLights, %i areaRefs\n", v2, v3);
  }
}


// ========================================================================
// ?ListRenderModels_f@idRenderWorldLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82957EB0
// RVA : 0x00957EB0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ListRenderModels_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r11
  int v2; // r29
  int v3; // r30
  int v4; // r24
  int v5; // r28
  idRenderModel *v6; // r31
  idRenderModel *v7; // r3
  const char *str; // r31
  int NumReferences; // r3

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    v2 = 0;
    v3 = 0;
    if ( tr.primaryWorld->renderModels.num > 0 )
    {
      v4 = ((args->argc >= 0) + (args->argc <= 1u)) & 1;
      v5 = 0;
      do
      {
        v6 = primaryWorld->renderModels.list[v5];
        if ( v4 == 0 || v6 != nullptr && v6->committed->references.num != 0 )
        {
          if ( v6 != nullptr )
          {
            idRenderModel::GetNumReferences(this: v6);
            v7 = v6;
            str = v6->name.str;
            NumReferences = idRenderModel::GetNumReferences(this: v7);
            idLib::Printf(fmt: "%4i: %2i refs %s\n", v3, NumReferences, str);
            ++v2;
          }
          else
          {
            idLib::Printf(fmt: "%4i: FREED\n", v3);
          }
          primaryWorld = tr.primaryWorld;
        }
        ++v3;
        ++v5;
      }
      while ( v3 < primaryWorld->renderModels.num );
    }
    idLib::Printf(fmt: "total active: %i\n", v2);
  }
}


// ========================================================================
// ?unlinkParticleModels_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82957FB8
// RVA : 0x00957FB8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall unlinkParticleModels_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r11
  int v2; // r28
  int v3; // r29
  int v4; // r30
  idRenderModel **list; // r10
  idRenderModel *v6; // r31

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    v2 = 0;
    v3 = 0;
    if ( tr.primaryWorld->renderModels.num > 0 )
    {
      v4 = 0;
      do
      {
        list = primaryWorld->renderModels.list;
        v6 = list[v4];
        if ( v6 != nullptr )
        {
          if ( idRenderModel::GetNumReferences(this: list[v4]) != 0
            && strstr(str1: v6->name.str, str2: ".prt") != nullptr )
          {
            if ( !v6->unlinked )
            {
              idRenderModel::CommitThisFrame(this: v6);
              v6->unlinked = true;
            }
            ++v2;
          }
          primaryWorld = tr.primaryWorld;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < primaryWorld->renderModels.num );
    }
    idLib::Printf(fmt: "total unlinked: %i\n", v2);
  }
}


// ========================================================================
// ?ApproximateLightingForModel@idRenderWorldLocal@@QAAXPAVidRenderModelCommitted@@H@Z
// EA  : 0x82958500
// RVA : 0x00958500
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderWorldLocal::ApproximateLightingForModel(
        idRenderWorldLocal *this,
        idVec3 *model,
        int renderTime)
{
  int z_low; // r11
  idVec3 *v7; // r19
  idRenderModel *v8; // r11
  idVec3 *committed; // r11
  int *p_numApproximateLightingParms; // r17
  int *p_numApproximateLightingLights; // r18
  int numApproximateLightingLights; // r11
  int v13; // r30
  int v14; // r29
  int v15; // r26
  const idRenderLightCommitted **v16; // r22
  int v17; // r28
  int v18; // r11
  _DWORD *v19; // r5
  int v20; // ctr
  int v21; // r11
  int v22; // r3
  int v23; // r11
  int v24; // r6
  const idRenderLightCommitted **v25; // r7
  int v26; // r10
  const idRenderLightCommitted *v27; // r8
  const idRenderLightCommitted **v28; // r9
  double v29; // fp8
  double v30; // fp6
  void (__fastcall *DebugText)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool); // r6
  const char *x_low; // r4
  const idRenderLightCommitted **v33; // r26
  int i; // r28
  const idBounds *v35; // r30
  idRenderWorldLocal_vtbl *v36; // r14
  idRenderModelCommitted *LightingPoint; // r3
  int v38; // r9
  int v39; // r10
  approximateLightingParms_t *v40; // r30
  float *v41; // r3
  char v42; // r11
  __int64 v43; // r8
  __int64 v44; // r6
  bool v45; // r4
  int v46; // r2 OVERLAPPED
  __int64 v47; // r11
  double v48; // fp13
  double v51; // fp0
  int v52; // r3
  double v53; // fp1
  double v54; // fp0
  idLookupTable *table; // r3
  double v58; // fp10
  double v59; // fp8
  double v60; // fp7
  __int64 v61; // [sp+60h] [-200h] BYREF
  idColor v62; // [sp+70h] [-1F0h] BYREF
  idColor v63; // [sp+80h] [-1E0h] BYREF
  float v64[4]; // [sp+90h] [-1D0h] BYREF
  idStr v65; // [sp+A0h] [-1C0h] BYREF
  int v66; // [sp+C0h] [-1A0h] BYREF

  if ( (HIBYTE(model[118].x) & 0x20) != 0 && (BYTE1(model[11].z) & 4) == 0 && LODWORD(model[87].y) != 0 )
  {
    if ( r_skipDynamicLighting.valueInteger != 0 )
    {
      approximateLighting_t::Clear(this: (approximateLighting_t *)&model[104].z);
      model[107].y = 0.5;
      model[108].z = 0.5;
      model[107].z = 0.5;
      model[108].x = 0.5;
      model[108].y = 0.0;
      model[109].x = 0.5;
      HIDWORD(v61) = model + 114;
      model[109].y = 0.5;
      model[109].z = 0.0;
      model[110].x = 0.5;
      model[110].y = 0.5;
      model[110].z = 0.5;
      model[111].x = 0.0;
      model[111].y = 0.5;
      model[111].z = 0.5;
      model[112].x = 0.5;
      model[112].y = 0.0;
      model[112].z = 0.5;
      model[113].x = 0.5;
      model[113].y = 0.5;
      model[113].z = 0.0;
      model[114].x = 0.5;
      model[114].y = 0.5;
      model[114].z = 0.5;
      model[115].x = 0.0;
    }
    else
    {
      z_low = LODWORD(model[8].z);
      v7 = model;
      if ( z_low != -1 )
      {
        v8 = this->renderModels.list[z_low];
        if ( v8 != nullptr && (committed = (idVec3 *)v8->committed) != nullptr )
          v7 = committed;
        else
          idLib::Warning(fmt: "ApproximateLightingForModel: model had a groupMasterIndex pointing at a removed model");
      }
      p_numApproximateLightingParms = &this->numApproximateLightingParms;
      if ( this->numApproximateLightingParms < 64 )
      {
        p_numApproximateLightingLights = &this->numApproximateLightingLights;
        numApproximateLightingLights = this->numApproximateLightingLights;
        if ( numApproximateLightingLights < 2048 )
        {
          v13 = 2048 - numApproximateLightingLights;
          v14 = 0;
          v15 = 0;
          v16 = &this->approximateLightingLights[numApproximateLightingLights];
          if ( SLODWORD(v7[87].y) > 0 )
          {
            v17 = 0;
            do
            {
              v18 = *(_DWORD *)(v17 + LODWORD(v7[87].x));
              v19 = (_DWORD *)(v18 + 32);
              if ( !this->isComboMap )
                v19 = (_DWORD *)(v18 + 16);
              if ( v14 != 0 )
              {
                v22 = 0;
                if ( (int)v19[1] > 0 )
                {
                  v23 = v14 - 1;
                  v24 = 0;
                  v25 = &v16[v14 - 1];
                  do
                  {
                    if ( v14 >= v13 )
                      break;
                    ++v23;
                    ++v14;
                    v26 = 0;
                    v27 = *(idRenderLightCommitted **)((char *)this->linkedRenderLights.list
                                                     + ((*(_DWORD *)(*v19 + v24) >> 6) & 0x3FFFFFC));
                    *++v25 = v27;
                    if ( v23 > 0 )
                    {
                      v28 = v16;
                      while ( *v28 != v27 )
                      {
                        ++v26;
                        ++v28;
                        if ( v26 >= v23 )
                          goto LABEL_33;
                      }
                      --v14;
                      --v25;
                      --v23;
                    }
LABEL_33:
                    ++v22;
                    v24 += 4;
                  }
                  while ( v22 < v19[1] );
                }
              }
              else
              {
                v14 = v19[1];
                if ( v14 >= v13 )
                  v14 = v13;
                if ( v14 > 0 )
                {
                  v20 = v14;
                  v21 = 0;
                  do
                  {
                    v16[v21] = *(idRenderLightCommitted **)((char *)this->linkedRenderLights.list
                                                          + ((*(_DWORD *)(*v19 + v21 * 4) >> 6) & 0x3FFFFFC));
                    ++v21;
                    --v20;
                  }
                  while ( v20 != 0 );
                }
              }
              ++v15;
              v17 += 4;
            }
            while ( v15 < SLODWORD(v7[87].y) );
            if ( v14 >= 128 && this->isComboMap )
            {
              if ( r_showDynamicLighting.valueInteger == 3 )
              {
                this->DebugBounds(
                  this,
                  a2: (const idVec4 *)&idColor::colorRed,
                  a3: (const idBounds *)&model[91],
                  a4: &vec3_origin,
                  a5: 0,
                  a6: false);
                v29 = (float)(model[91].y + model[92].y);
                v30 = (float)(model[91].x + model[92].x);
                DebugText = this->DebugText;
                x_low = (const char *)LODWORD(model->x);
                v64[2] = (float)(model[91].z + model[92].z) * (float)0.5;
                v64[1] = (float)v29 * (float)0.5;
                v64[0] = (float)v30 * (float)0.5;
                ((void (__fastcall *)(idRenderWorldLocal *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD))DebugText)(
                  a1: this,
                  a2: x_low,
                  a3: v64,
                  a4: DebugText,
                  a5: &idColor::colorRed,
                  a6: 1,
                  a7: 0,
                  a8: 0);
                v33 = v16 - 1;
                for ( i = v14; i != 0; --i )
                {
                  v35 = (const idBounds *)*++v33;
                  v36 = this->__vftable;
                  LightingPoint = idRenderModelCommitted::GetLightingPoint(
                                    this: (idRenderModelCommitted *)&v61,
                                    result: model);
                  v36->DebugLine(
                    this,
                    a2: (const idVec4 *)&idColor::colorWhite,
                    a3: v35[46].b,
                    a4: (const idVec3 *)LightingPoint,
                    a5: 3,
                    a6: false);
                  this->DebugBounds(
                    this,
                    a2: (const idVec4 *)&idColor::colorYellow,
                    a3: &v35[45],
                    a4: &vec3_origin,
                    a5: 0,
                    a6: false);
                }
              }
              else
              {
                idLib::Warning(
                  fmt: "Approximate lighting affected by more than %d lights for model %s",
                  128,
                  (const char *)LODWORD(model->x));
              }
            }
          }
          v38 = *p_numApproximateLightingParms << 6;
          v39 = *p_numApproximateLightingLights + v14;
          ++*p_numApproximateLightingParms;
          v40 = (approximateLightingParms_t *)((char *)this->approximateLightingParms + v38);
          *p_numApproximateLightingLights = (v39 + 3) & 0xFFFFFFFC;
          v40->lighting = (approximateLighting_t *)&model[104].z;
          v40->lights = v16;
          v40->contributions = nullptr;
          v40->numLights = v14;
          v40->ambientMap = this->ambientLighting.ambientMap;
          v40->shadowMap = idGlobalShadows::GetShadowMap(this: &this->globalShadows);
          v41 = (float *)idRenderModelCommitted::GetLightingPoint(this: (idRenderModelCommitted *)&v63, result: v7);
          v40->samplePoint.x = *v41;
          v40->samplePoint.y = v41[1];
          HIDWORD(v61) = &v40->samplePoint;
          v40->samplePoint.z = v41[2];
          v40->noAmbient = (LOBYTE(v7[11].z) & 0x10) != 0;
          if ( this->isComboMap || (v42 = 1, (LOBYTE(model[11].z) & 8) != 0) )
            v42 = 0;
          v40->noApproximateLighting = v42;
          v40->privateLightOnly = BYTE2(model[11].z) & 1;
          if ( r_forceLightingModel.valueInteger != 0 )
            v40->lightingModel = r_forceLightingModel.valueInteger;
          else
            v40->lightingModel = (BYTE2(v7[11].z) & 1) != 0 && (LOBYTE(v7[11].z) & 0x80) == 0;
          HIDWORD(v43) = &r_directChannelScale;
          LODWORD(v43) = &renderLog.indentString[28];
          HIDWORD(v44) = &renderLog.indentString[28];
          LODWORD(v44) = &r_primeLightScale;
          v40->ambientChannelScale = r_ambientChannelScale.valueFloat;
          v40->directChannelScale = r_directChannelScale.valueFloat;
          v40->primeLightScale = r_primeLightScale.valueFloat;
          v40->dynamicLightingScale = r_dynamicLightingScale.valueFloat;
          v40->dimShadowHeightTweak = r_dimShadowHeightTweak.valueFloat;
          if ( r_showDynamicLighting.valueInteger == 0
            && r_showAmbientLighting.valueInteger == 0
            && this->isComboMap
            && r_useDynamicLightingJobs.valueInteger == 1 )
          {
            idParallelJobList::AddJob(
              this: this->renderModelJobList,
              function: (void (__fastcall *)(void *))ApproximateLightingJob,
              data: v40);
          }
          else
          {
            v40->contributions = (lightContribution_t *)&v66;
            ApproximateLightingJob(parms: v40, a2: (int)&renderLog.indentString[28], a3: v44, a4: v43);
            idRenderWorldLocal::ShowApproximateLighting(this, (idRenderModelCommitted *)model, parms: v40);
            *p_numApproximateLightingParms = 0;
            *p_numApproximateLightingLights = 0;
            v40->contributions = nullptr;
          }
          HIDWORD(v47) = tr.declHighlightTable;
          v48 = 1.0;
          if ( tr.declHighlightTable != nullptr )
            v48 = (float)(tr.declHighlightTable->right - tr.declHighlightTable->left);
          LODWORD(v47) = renderTime;
          v61 = v47;
          _FP10 = (float)((float)0.00000011920929 - (float)v48);
          __asm { fsel      f13, f10, f0, f13 }
          v51 = (float)((float)v47 * (float)0.001);
          if ( r_highlightSynchronized.valueInteger == 0 )
          {
            v52 = ((signed int)(1103515245 * (LODWORD(v7->z) >> 8) + 12345) >> 16) & 0x7FFF;
            v61 = *(_QWORD *)(&v46 - 1);
            v51 = (float)((float)((float)((float)*(__int64 *)(&v46 - 1) * (float)_FP13) * (float)0.000030518509)
                        + (float)((float)v47 * (float)0.001));
          }
          v53 = (float)((float)v51 * (float)((float)1.0 / (float)_FP13));
          v54 = 0.0;
          if ( tr.declHighlightTable != nullptr )
          {
            table = tr.declHighlightTable->table;
            if ( table != nullptr )
              v54 = idLookupTable::TableLookup(this: table, time: v53, fastSearch: v45);
          }
          _FP13 = -v54;
          __asm { fsel      f31, f13, f31, f0 }
          if ( LODWORD(model[13].y) != 0 )
          {
            v63.g = 240.0;
            v63.r = 247.0;
            v63.b = 180.0;
            v63.a = 255.0;
            v62.g = 240.0;
            v62.r = 247.0;
            v62.a = 255.0;
            v62.b = 180.0;
            idStr::idStr(this: &v65, text: r_highlightColor.valueString.data);
            if ( v65.len != 0 )
              idColor::SetFromString(this: &v62, str: v65.data, parseParens: false);
            v63.a = v62.a * (float)0.0039215689;
            v63.b = v62.b * (float)0.0039215689;
            v63.r = v62.r * (float)0.0039215689;
            v63.g = v62.g * (float)0.0039215689;
            v62 = v63;
            idStr::FreeData(this: &v65);
          }
          else
          {
            v62 = idColor::colorBlack;
          }
          v58 = (float)(v62.g * (float)_FP31);
          v59 = (float)(v62.b * (float)_FP31);
          v60 = (float)(v62.a * (float)_FP31);
          model[116].z = v62.r * (float)_FP31;
          model[117].x = v58;
          model[117].y = v59;
          model[117].z = v60;
        }
      }
    }
  }
}


// ========================================================================
// __unwind$238326
// EA  : 0x82958D8C
// RVA : 0x00958D8C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_238326()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 160));
}


// ========================================================================
// ?UpdateInView@idRenderWorldLocal@@QAAXPBVidRenderView@@0@Z
// EA  : 0x82958DB8
// RVA : 0x00958DB8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::UpdateInView(
        idRenderWorldLocal *this,
        const idRenderView *currentRenderView,
        const idRenderView *nextRenderView)
{
  idParallelJobList **p_transparencyJobList; // r24
  idRenderModelTransparency **p_transparencyRenderModel; // r22
  idParallelJobList **p_renderModelJobList; // r23
  long double v9; // fp2
  int v10; // r30
  idParallelJobList *v11; // r10
  idParallelJobList *v12; // r8
  int i; // r27
  idRenderModel *v14; // r10
  idRenderModel *v15; // r11
  idRenderModel *referenceModel; // r3
  idRenderModelUpdateTools v17[7]; // [sp+50h] [-70h] BYREF

  p_transparencyJobList = &this->transparencyJobList;
  idParallelJobList::Wait(this: this->transparencyJobList);
  console->AddJobListTimeRange(
    this: console,
    a2: RANGE_JBL_TRNS,
    a3: &idColor::colorMagenta,
    a4: *p_transparencyJobList,
    a5: 0);
  p_transparencyRenderModel = &this->transparencyRenderModel;
  idRenderModelTransparency::GenerateTransparencyRenderList(
    this: this->transparencyRenderModel,
    currentView: currentRenderView);
  p_renderModelJobList = &this->renderModelJobList;
  idParallelJobList::Wait(this: this->renderModelJobList);
  console->AddJobListTimeRange(
    this: console,
    a2: RANGE_JBL_RMDL,
    a3: &idColor::colorCyan,
    a4: this->renderModelJobList,
    a5: 0);
  idRenderModelTransparency::StartFrame();
  idRenderModelEffects::StartFrame();
  idRenderModelFlare::StartFrame();
  idRenderModelFlareOcclusionQuad::StartFrame();
  idRenderModelCuttableBeams::StartFrame();
  v10 = 0;
  this->numApproximateLightingParms = 0;
  this->numApproximateLightingLights = 0;
  if ( currentRenderView != nullptr && nextRenderView != nullptr )
  {
    v11 = *p_renderModelJobList;
    v12 = *p_transparencyJobList;
    v17[0].transparencyModel = *p_transparencyRenderModel;
    v17[0].renderModelJobList = v11;
    v17[0].decalModel = this->decalRenderModel;
    v17[0].transparencyJobList = v12;
    idRenderModelTransparency::GenerateVisibleInfluenceSphereList(
      this: v17[0].transparencyModel,
      currentRenderView,
      nextRenderView,
      updateTools: v17,
      a5: v9);
    for ( i = 0; i < this->renderModels.num; ++v10 )
    {
      if ( currentRenderView->occlusionState->modelVisibleFrameNumber[v10] >= currentRenderView->occlusionState->renderFrameNumber
        || nextRenderView->occlusionState->modelVisibleFrameNumber[v10] >= nextRenderView->occlusionState->renderFrameNumber )
      {
        v14 = this->renderModels.list[v10];
        if ( v14 != nullptr )
        {
          ((void (*)(void))v14->UpdateInView)();
          idRenderWorldLocal::ApproximateLightingForModel(
            this,
            model: (idVec3 *)this->renderModels.list[v10]->committed,
            renderTime: currentRenderView->r.renderTime);
          v15 = this->renderModels.list[v10];
          referenceModel = v15->g.referenceModel;
          if ( referenceModel != nullptr && (*((_BYTE *)&v15->g + 105) & 4) == 0 )
            referenceModel->UpdateInView(this: referenceModel, a2: currentRenderView, a3: nextRenderView, a4: v17);
        }
      }
      ++i;
    }
    if ( r_showAmbientLighting.valueInteger != 0 )
      idAmbientLighting::DebugDrawAmbientLightingBoxes(
        this: &this->ambientLighting,
        rw: this,
        showForView: ((r_showAmbientLighting.valueInteger >= 0) + (r_showAmbientLighting.valueInteger <= 1u)) & 1);
    idRenderModelTransparency::AddTransparencySortJob(this: *p_transparencyRenderModel, updateTools: v17);
  }
  idParallelJobList::Submit(this: *p_transparencyJobList, waitForJobList: nullptr, parallelism: -1);
  idParallelJobList::Submit(this: *p_renderModelJobList, waitForJobList: nullptr, parallelism: -1);
  idRenderModelCuttableBeams::EndFrame();
  idRenderModelFlare::EndFrame();
  idRenderModelEffects::EndFrame();
}


// ========================================================================
// ?Trace@idRenderWorldLocal@@UBA_NAAUmodelTrace_t@@ABVidVec3@@1PBVidTraceOpts@@@Z
// EA  : 0x829592B0
// RVA : 0x009592B0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

BOOL __fastcall idRenderWorldLocal::Trace(
        idRenderWorldLocal *this,
        modelTrace_t *trace,
        const idVec3 *start,
        const idVec3 *end,
        const idTraceOpts *traceOpts)
{
  idTraceOpts *v9; // r20
  idVec3 *p_point; // r29
  int v35; // r17
  bufferUsageType_t *p_usage; // r21
  worldArea_t *v37; // r26
  bool v38; // r7
  int v39; // r25
  int v40; // r28
  idRenderModelSurface *v41; // r31
  int numIndexes; // r11
  int numVerts; // r10
  int detailOffset; // r9
  double z; // fp13
  int v46; // r8
  double x; // fp12
  double v48; // fp10
  double v49; // fp9
  int v50; // r23
  int v51; // r28
  idRenderModel *skipModel; // r11
  int v53; // r31
  double v54; // fp13
  double y; // fp10
  double v56; // fp8
  double v57; // fp6
  double v58; // fp5
  double v59; // fp4
  double v60; // fp3
  double v61; // fp2
  double v62; // fp0
  __int64 v63; // r8
  int x_low; // r10
  double v65; // fp0
  float v66; // r9
  double v67; // fp13
  unsigned int cpuVertexMask; // r8
  double v69; // fp12
  idDrawVert *verts; // r7
  const idRenderModel *vertexMask; // r6
  unsigned __int16 *indexes; // r5
  double v73; // fp11
  double v74; // fp9
  double v75; // fp10
  double v76; // fp5
  double v77; // fp4
  double v78; // fp13
  double v79; // fp12
  double v80; // fp11
  int v82; // [sp+50h] [-3A0h] BYREF
  idVec3 v83; // [sp+58h] [-398h] BYREF
  idVec3 v84; // [sp+68h] [-388h] BYREF
  idVec3 v85; // [sp+78h] [-378h] BYREF
  idBounds v86; // [sp+90h] [-360h] BYREF
  idTriangles v87[5]; // [sp+B0h] [-340h] BYREF

  v9 = traceOpts;
  if ( traceOpts == nullptr )
  {
    if ( (_S13_28 & 1) == 0 )
    {
      defaultOps_0.radius = 0.0;
      defaultOps_0.skipTranslucent = false;
      _S13_28 |= 1u;
      defaultOps_0.skipInvisible = true;
      defaultOps_0.skipDynamic = true;
      defaultOps_0.skipModel = nullptr;
      defaultOps_0.twoSided = false;
    }
    v9 = &defaultOps_0;
  }
  v82 = 0;
  trace->tr.fraction = 1.0;
  trace->tr.point = *end;
  p_point = &trace->tr.point;
  trace->entity = nullptr;
  trace->surf = nullptr;
  _FP25 = (float)((float)1.0e30 - start->x);
  _FP27 = (float)((float)1.0e30 - start->z);
  _FP26 = (float)((float)1.0e30 - start->y);
  _FP24 = (float)(start->z - (float)-1.0e30);
  _FP23 = (float)(start->y - (float)-1.0e30);
  _FP22 = (float)(start->x - (float)-1.0e30);
  __asm
  {
    fsel      f2, f25, f11, f0
    fsel      f9, f27, f9, f0
    fsel      f4, f26, f10, f0
  }
  __asm
  {
    fsel      f0, f24, f7, f6
    fsel      f12, f23, f10, f6
    fsel      f11, f22, f11, f6
  }
  _FP10 = (float)((float)_FP2 - end->x);
  _FP8 = (float)((float)_FP9 - end->z);
  _FP7 = (float)((float)_FP4 - end->y);
  _FP6 = (float)(end->z - (float)_FP0);
  _FP29 = (float)(end->y - (float)_FP12);
  _FP27 = (float)(end->x - (float)_FP11);
  __asm { fsel      f2, f10, f28, f2 }
  v86.b[0].x = _FP2;
  __asm { fsel      f10, f8, f3, f9 }
  v86.b[0].z = _FP10;
  __asm { fsel      f9, f7, f5, f4 }
  v86.b[0].y = _FP9;
  __asm { fsel      f8, f6, f3, f0 }
  v86.b[1].z = _FP8;
  __asm { fsel      f7, f29, f5, f12 }
  v86.b[1].y = _FP7;
  __asm { fsel      f6, f27, f28, f11 }
  v86.b[1].x = _FP6;
  idRenderWorldLocal::BoundsInAreas_r(
    this,
    nodeNum: 0,
    bounds: &v86,
    areas: (int *)&v87[0].vertexBuffer.usage,
    numAreas: &v82,
    maxAreas: 128);
  v35 = 0;
  if ( v82 > 0 )
  {
    p_usage = &v87[0].vertexBuffer.usage;
    do
    {
      v37 = &this->worldAreas[*p_usage];
      if ( idBounds::LineIntersection(this: &this->worldAreaSubspaceBounds[*p_usage], start, end: &trace->tr.point) )
      {
        if ( idBounds::LineIntersection(this: &this->worldAreaGeometryBounds[*p_usage], start, end: &trace->tr.point) )
        {
          v39 = 0;
          if ( v37->worldSurfaces.num > 0 )
          {
            v40 = 0;
            do
            {
              v41 = &v37->worldSurfaces.list[v40];
              idTriangles::TriangleTrace(
                this: v87,
                result: (localTrace_t *)v41->geometry,
                start,
                end,
                radius: 0.0,
                twoSided: v38);
              if ( v87[0].bounds.b[0].x < (double)trace->tr.fraction )
              {
                numIndexes = v87[0].numIndexes;
                trace->tr.fraction = v87[0].bounds.b[0].x;
                numVerts = v87[0].numVerts;
                detailOffset = v87[0].detailOffset;
                z = v87[0].bounds.b[0].z;
                v46 = *(_DWORD *)&v87[0].allowGpuHosting;
                x = v87[0].bounds.b[1].x;
                p_point->x = v87[0].bounds.b[0].y;
                trace->tr.point.y = z;
                trace->tr.point.z = x;
                v48 = v87[0].bounds.b[1].z;
                v49 = *(float *)&v87[0].generateNormals;
                trace->tr.normal.x = v87[0].bounds.b[1].y;
                trace->tr.normal.y = v48;
                trace->tr.normal.z = v49;
                trace->tr.jointIndex = numIndexes;
                trace->tr.indexes[0] = numVerts;
                trace->tr.indexes[1] = detailOffset;
                trace->tr.indexes[2] = v46;
                trace->entity = nullptr;
                trace->surf = v41;
              }
              ++v39;
              ++v40;
            }
            while ( v39 < v37->worldSurfaces.num );
          }
        }
        v50 = 0;
        if ( v37->modelRefs.num > 0 )
        {
          v51 = 0;
          do
          {
            skipModel = v9->skipModel;
            v53 = *(int *)((char *)this->linkedRenderModels.list + ((v37->modelRefs.list[v51].index >> 6) & 0x3FFFFFC));
            if ( (skipModel == nullptr || (idRenderModelCommitted *)v53 != skipModel->committed)
              && (!v9->skipDynamic || (*(_BYTE *)(v53 + 140) & 0x20) != 0) )
            {
              v54 = start->z;
              y = start->y;
              v56 = start->x;
              v57 = end->z;
              v58 = end->y;
              v59 = end->x;
              v60 = trace->tr.point.z;
              v61 = trace->tr.point.y;
              v62 = p_point->x;
              v83.x = (float)((float)(start->x * *(float *)(v53 + 1192))
                            + (float)((float)(*(float *)(v53 + 1196) * start->y)
                                    + (float)(*(float *)(v53 + 1200) * start->z)))
                    + *(float *)(v53 + 1204);
              v83.y = (float)((float)(*(float *)(v53 + 1216) * (float)v54)
                            + (float)((float)(*(float *)(v53 + 1208) * (float)v56)
                                    + (float)(*(float *)(v53 + 1212) * (float)y)))
                    + *(float *)(v53 + 1220);
              v83.z = (float)((float)(*(float *)(v53 + 1232) * (float)v54)
                            + (float)((float)(*(float *)(v53 + 1224) * (float)v56)
                                    + (float)(*(float *)(v53 + 1228) * (float)y)))
                    + *(float *)(v53 + 1236);
              v84.x = (float)((float)((float)v59 * *(float *)(v53 + 1192))
                            + (float)((float)(*(float *)(v53 + 1196) * (float)v58)
                                    + (float)(*(float *)(v53 + 1200) * (float)v57)))
                    + *(float *)(v53 + 1204);
              v84.y = (float)((float)(*(float *)(v53 + 1216) * (float)v57)
                            + (float)((float)(*(float *)(v53 + 1208) * (float)v59)
                                    + (float)(*(float *)(v53 + 1212) * (float)v58)))
                    + *(float *)(v53 + 1220);
              v84.z = (float)((float)(*(float *)(v53 + 1232) * (float)v57)
                            + (float)((float)(*(float *)(v53 + 1224) * (float)v59)
                                    + (float)(*(float *)(v53 + 1228) * (float)v58)))
                    + *(float *)(v53 + 1236);
              v85.x = (float)((float)(*(float *)(v53 + 1192) * (float)v62)
                            + (float)((float)(*(float *)(v53 + 1196) * (float)v61)
                                    + (float)(*(float *)(v53 + 1200) * (float)v60)))
                    + *(float *)(v53 + 1204);
              v85.y = (float)((float)(*(float *)(v53 + 1216) * (float)v60)
                            + (float)((float)(*(float *)(v53 + 1208) * (float)v62)
                                    + (float)(*(float *)(v53 + 1212) * (float)v61)))
                    + *(float *)(v53 + 1220);
              v85.z = (float)((float)(*(float *)(v53 + 1232) * (float)v60)
                            + (float)((float)(*(float *)(v53 + 1224) * (float)v62)
                                    + (float)(*(float *)(v53 + 1228) * (float)v61)))
                    + *(float *)(v53 + 1236);
              if ( idBounds::LineIntersection(this: (idBounds *)(v53 + 12), start: &v83, end: &v85) )
              {
                HIDWORD(v63) = v9;
                if ( idRenderModelCommitted::ModelTriangleTrace(
                       this: (idRenderModelCommitted *)v53,
                       trace: (modelTrace_t *)&v87[0].vsb.xyzScale.y,
                       localStart: &v83,
                       localEnd: &v84,
                       traceOpts: v63)
                  && v87[0].vsb.xyzScale.y < (double)trace->tr.fraction )
                {
                  x_low = LODWORD(v87[0].vsb.stBias.x);
                  trace->tr.fraction = v87[0].vsb.xyzScale.y;
                  v65 = v87[0].vsb.xyzScale.z;
                  v66 = v87[0].vsb.stBias.y;
                  v67 = v87[0].vsb.xyzBias.x;
                  cpuVertexMask = v87[0].cpuVertexMask;
                  v69 = v87[0].vsb.xyzBias.y;
                  verts = v87[0].verts;
                  p_point->x = v87[0].vsb.xyzScale.z;
                  vertexMask = (const idRenderModel *)v87[0].vertexMask;
                  trace->tr.point.y = v67;
                  indexes = v87[0].indexes;
                  trace->tr.point.z = v69;
                  v73 = v87[0].vsb.stScale.y;
                  v74 = v87[0].vsb.stScale.x;
                  v75 = v87[0].vsb.xyzBias.z;
                  trace->tr.normal.z = v87[0].vsb.stScale.y;
                  trace->tr.normal.y = v74;
                  trace->tr.normal.x = v75;
                  trace->tr.jointIndex = x_low;
                  *(float *)trace->tr.indexes = v66;
                  trace->tr.indexes[1] = cpuVertexMask;
                  trace->tr.indexes[2] = (int)verts;
                  trace->entity = vertexMask;
                  trace->surf = (const idRenderModelSurface *)indexes;
                  trace->entity = *(idRenderModel **)((char *)this->renderModels.list
                                                    + ((*(_DWORD *)(v53 + 8) >> 6) & 0x3FFFFFC));
                  p_point->x = (float)((float)((float)v65 * *(float *)(v53 + 1128))
                                     + (float)((float)(*(float *)(v53 + 1136) * (float)v69)
                                             + (float)(*(float *)(v53 + 1132) * (float)v67)))
                             + *(float *)(v53 + 1140);
                  trace->tr.point.y = (float)((float)(*(float *)(v53 + 1144) * (float)v65)
                                            + (float)((float)(*(float *)(v53 + 1152) * (float)v69)
                                                    + (float)(*(float *)(v53 + 1148) * (float)v67)))
                                    + *(float *)(v53 + 1156);
                  trace->tr.point.z = (float)((float)(*(float *)(v53 + 1160) * (float)v65)
                                            + (float)((float)(*(float *)(v53 + 1168) * (float)v69)
                                                    + (float)(*(float *)(v53 + 1164) * (float)v67)))
                                    + *(float *)(v53 + 1172);
                  v76 = *(float *)(v53 + 52);
                  v77 = *(float *)(v53 + 56);
                  v78 = (float)((float)(*(float *)(v53 + 60) * (float)v74) + (float)(*(float *)(v53 + 72) * (float)v73));
                  v79 = (float)((float)(*(float *)(v53 + 64) * (float)v74) + (float)(*(float *)(v53 + 76) * (float)v73));
                  v80 = (float)((float)(*(float *)(v53 + 68) * (float)v74) + (float)(*(float *)(v53 + 80) * (float)v73));
                  trace->tr.normal.x = (float)(*(float *)(v53 + 48) * (float)v75) + (float)v78;
                  trace->tr.normal.y = (float)((float)v76 * (float)v75) + (float)v79;
                  trace->tr.normal.z = (float)((float)v77 * (float)v75) + (float)v80;
                }
              }
            }
            ++v50;
            ++v51;
          }
          while ( v50 < v37->modelRefs.num );
        }
      }
      ++v35;
      ++p_usage;
    }
    while ( v35 < v82 );
  }
  return trace->tr.fraction < 1.0;
}


// ========================================================================
// ?AllocRenderLight@idRenderWorldLocal@@UAAPAVidRenderLight@@_N@Z
// EA  : 0x82959D30
// RVA : 0x00959D30
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderLight *__fastcall idRenderWorldLocal::AllocRenderLight(idRenderWorldLocal *this, bool skipAutoReplication)
{
  idRenderLight *v4; // r3
  idRenderLight *v5; // r27
  idStaticList<idRenderLight *,4096> *p_renderLights; // r30
  int v7; // r9
  int v8; // r11
  int v9; // r10
  int v10; // r3
  int num; // r10
  int v12; // r11
  int v14[16]; // [sp+50h] [-40h] BYREF

  v4 = (idRenderLight *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x430u,
                          tag: TAG_RENDERMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v14[0] = (int)v4;
  if ( v4 != nullptr )
    v5 = idRenderLight::idRenderLight(this: v4);
  else
    v5 = nullptr;
  if ( com_multiplayer.valueInteger == 0 )
    goto _LN57_3;
  v14[0] = 0;
  p_renderLights = &this->renderLights;
  idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)&this->renderLights, newNum: 4096, initValue: v14);
  v5->skipAutoReplication = skipAutoReplication;
  v7 = !skipAutoReplication ? 3596 : 4096;
  v8 = !skipAutoReplication ? 0 : 0xE0C;
  if ( v8 >= v7 )
    goto LABEL_11;
  v9 = v8;
  while ( p_renderLights->list[v9] != nullptr )
  {
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_11;
  }
  v10 = v8;
  if ( v8 == -1 )
  {
LABEL_11:
    idLib::Error(fmt: "Max lights allocated.");
_LN57_3:
    num = this->renderLights.num;
    p_renderLights = &this->renderLights;
    v10 = 0;
    if ( num <= 0 )
      goto LABEL_18;
    v12 = 0;
    while ( p_renderLights->list[v12] != nullptr )
    {
      ++v10;
      ++v12;
      if ( v10 >= num )
        goto LABEL_18;
    }
    if ( v10 == -1 )
    {
LABEL_18:
      if ( this->renderLights.num == this->renderLights.size )
        idLib::Error(fmt: "Max lights allocated.");
      v14[0] = 0;
      v10 = idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->renderLights,
              obj: (const encounterGroupRole_t *)v14);
    }
  }
  p_renderLights->list[v10] = v5;
  v5->committed->world = this;
  v5->committed->index.index = (1 << (v10 & 7)) | (v10 << 8);
  return v5;
}


// ========================================================================
// $LN47_4
// EA  : 0x82959EDC
// RVA : 0x00959EDC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _LN47_4()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?MarkLightSerialized@idRenderWorldLocal@@UAAXPAVidRenderLight@@_N1@Z
// EA  : 0x82959F08
// RVA : 0x00959F08
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::MarkLightSerialized(
        idRenderWorldLocal *this,
        idRenderLight *light,
        bool serialized,
        char deleted)
{
  idStaticList<idRenderLight *,4096> *p_serializedLights; // r30
  idLobbyBase *v8; // r30
  idRenderLight *v9; // r3
  idLobbyBase_vtbl *v10; // r31
  unsigned int Index; // r3

  if ( com_multiplayer.valueInteger != 0 )
  {
    if ( light->skipAutoReplication )
    {
      serialized = false;
      deleted = 1;
    }
    p_serializedLights = &this->serializedLights;
    idList<idObstacleBuffers *,5>::SetNum(
      this: (idList<int,37> *)&this->serializedLights,
      newNum: this->renderLights.num);
    if ( serialized )
    {
      p_serializedLights->list[idRenderLight::GetIndex(this: light)] = light;
      light->needWriteToSnapshot = true;
    }
    else
    {
      if ( p_serializedLights->list[idRenderLight::GetIndex(this: light)] != nullptr )
        p_serializedLights->list[idRenderLight::GetIndex(this: light)] = nullptr;
      if ( deleted != 0 )
      {
        v8 = session->GetActingGameStateLobbyBase(this: session);
        v9 = light;
        v10 = v8->__vftable;
        Index = idRenderLight::GetIndex(this: v9);
        v10->MarkSnapObjDeleted(this: v8, a2: Index + 10021);
      }
    }
  }
}


// ========================================================================
// ?AllocRenderModel@idRenderWorldLocal@@UAAPAVidRenderModel@@PBD_NH@Z
// EA  : 0x8295A018
// RVA : 0x0095A018
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderModel *__fastcall idRenderWorldLocal::AllocRenderModel(
        idRenderWorldLocal *this,
        const char *modelName,
        bool makeDefault,
        int index)
{
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  idRenderModel *v10; // r30
  idRenderModelAugmentOutline *v11; // r3
  idRenderModelAugmentOutline *v12; // r3
  idRenderModelEffects *v13; // r3
  idRenderModelEffects *v14; // r3
  idRenderModelDecal *v15; // r3
  idRenderModelDecal *v16; // r3
  idRenderModelBeam *v17; // r3
  idRenderModelBeam *v18; // r3
  int v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // r4
  idRenderModelManyBoxes *v26; // r3
  idRenderModelManyBoxes *v27; // r3
  idRenderModelImposter *v28; // r3
  idRenderModelImposter *v29; // r3
  idRenderModelCloth *v30; // r3
  idRenderModelCloth *v31; // r3
  idRenderModelFlareOcclusionQuad *v32; // r3
  idRenderModelFlareOcclusionQuad *v33; // r3
  idRenderModelTransparency *v34; // r3
  idRenderModelTransparency *v35; // r3
  idRenderModelFoliage *v36; // r3
  idRenderModelFoliage *v37; // r3
  idRenderModelDetail *v38; // r3
  idRenderModelDetail *v39; // r3
  idRenderModelZipline *v40; // r3
  idRenderModelZipline *v41; // r3
  idRenderModelChain *v42; // r3
  idRenderModelChain *v43; // r3
  idRenderModelCuttableDynamic *v44; // r3
  idRenderModelCuttableDynamic *v45; // r3
  idRenderModelCuttableBeams *v46; // r3
  idRenderModelCuttableBeams *v47; // r3
  const idDeclParticle *v48; // r30
  idRenderModelParticle *v50; // r3
  idRenderModelParticle *v51; // r3
  const idDeclFlare *v52; // r30
  idRenderModelFlare *v53; // r3
  idRenderModelFlare *v54; // r3
  const idDeclCloth *v55; // r30
  idRenderModelCloth *v56; // r3
  idRenderModelCloth *v57; // r3
  idDecl *v58; // r30
  idRenderModelDiscreteAnimation *v59; // r3
  idRenderModelDiscreteAnimation *v60; // r3
  idDecl *v61; // r30
  idRenderModelDiscreteAnimation *v62; // r3
  idRenderModelDiscreteAnimation *v63; // r3
  idRenderModelWaterSurface *v64; // r3
  idRenderModelWaterSurface *v65; // r3
  idRenderModelCuttableSurface *v66; // r3
  idRenderModelCuttableSurface *v67; // r3
  const idStaticModel *v68; // r30
  idRenderModelStatic *v69; // r3
  idRenderModelStatic *v70; // r3
  const idDeclMD6 *v71; // r30
  idTreeAnimator *v72; // r3
  idTreeAnimator *v73; // r3
  idRenderModel *v74; // r3
  idRenderModel *v75; // r3
  int num; // r9
  idList<enum encounterGroupRole_t,5> *p_renderModels; // r3
  int v78; // r10
  int v79; // r11
  int size; // r11
  int v81; // [sp+8h] [-198h]
  int v82; // [sp+Ch] [-194h]
  int v83; // [sp+10h] [-190h]
  idRenderModelManyBoxes *v84; // [sp+14h] [-18Ch]
  void *v85; // [sp+50h] [-150h] BYREF
  idStr v86; // [sp+60h] [-140h] BYREF
  idStr v87; // [sp+80h] [-120h] BYREF
  idStr v88; // [sp+A0h] [-100h] BYREF
  idStr v89; // [sp+C0h] [-E0h] BYREF
  idStr v90; // [sp+E0h] [-C0h] BYREF
  idStr v91; // [sp+100h] [-A0h] BYREF
  idStr v92; // [sp+120h] [-80h] BYREF
  idStr v93[3]; // [sp+140h] [-60h] BYREF

  if ( modelName == nullptr || *modelName == 0 )
    return nullptr;
  idStr::idStr(this: &v86, text: modelName);
  idStr::MakeNameCanonical(this: &v86);
  v87.len = 0;
  v87.allocedAndFlag = 20;
  v87.data = v87.baseBuffer;
  v87.baseBuffer[0] = 0;
  idStr::ExtractFileExtension(this: &v86, dest: &v87);
  idStr::idStr(this: &v88, text: &v86);
  if ( idStr::Cmp(s1: v86.data, s2: "_scratch") != 0
    && idStr::Cmp(s1: v86.data, s2: "_stamp") != 0
    && idStr::Cmp(s1: v86.data, s2: "_world") != 0 )
  {
    if ( idStr::Cmp(s1: v86.data, s2: "_gui") == 0 )
    {
      v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xA410u,
                                 tag: TAG_RENDERMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v85 = v8;
      if ( v8 != nullptr )
        v9 = idRenderModelGui::idRenderModelGui(this: v8);
      else
        v9 = nullptr;
      v10 = v9;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_augmentoutline") == 0 )
    {
      v11 = (idRenderModelAugmentOutline *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                             size: 0x7F0u,
                                             tag: TAG_RENDERMODEL,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
      v85 = v11;
      if ( v11 != nullptr )
        v12 = idRenderModelAugmentOutline::idRenderModelAugmentOutline(this: v11);
      else
        v12 = nullptr;
      v10 = v12;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_smoke") == 0 )
    {
      v13 = (idRenderModelEffects *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x3890u,
                                      tag: TAG_RENDERMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
      v85 = v13;
      if ( v13 != nullptr )
        v14 = idRenderModelEffects::idRenderModelEffects(this: v13);
      else
        v14 = nullptr;
      v10 = v14;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_decal") == 0 )
    {
      v15 = (idRenderModelDecal *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x880u,
                                    tag: TAG_RENDERMODEL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      v85 = v15;
      if ( v15 != nullptr )
        v16 = idRenderModelDecal::idRenderModelDecal(this: v15);
      else
        v16 = nullptr;
      v10 = v16;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_beam") == 0 )
    {
      v17 = (idRenderModelBeam *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x191450u,
                                   tag: TAG_RENDERMODEL,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
      v85 = v17;
      if ( v17 != nullptr )
        v18 = idRenderModelBeam::idRenderModelBeam(this: v17);
      else
        v18 = nullptr;
      v10 = v18;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_boxes") == 0 )
    {
      v26 = (idRenderModelManyBoxes *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x8C0u,
                                        tag: TAG_RENDERMODEL,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
      v85 = v26;
      if ( v26 != nullptr )
        v27 = idRenderModelManyBoxes::idRenderModelManyBoxes(
                this: v26,
                a2: v25,
                a3: v24,
                a4: v23,
                a5: v22,
                a6: v21,
                a7: v20,
                a8: v19,
                a9: v81,
                a10: v82,
                a11: v83,
                a12: v84);
      else
        v27 = nullptr;
      v10 = v27;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_imposterstatic") == 0 )
    {
      v28 = (idRenderModelImposter *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x800u,
                                       tag: TAG_RENDERMODEL,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
      v85 = v28;
      if ( v28 != nullptr )
        v29 = idRenderModelImposter::idRenderModelImposter(this: v28);
      else
        v29 = nullptr;
      v10 = v29;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_cloth") == 0 )
    {
      v30 = (idRenderModelCloth *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x890u,
                                    tag: TAG_RENDERMODEL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      v85 = v30;
      if ( v30 != nullptr )
        v31 = idRenderModelCloth::idRenderModelCloth(this: v30, clothSys: nullptr);
      else
        v31 = nullptr;
      v10 = v31;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_flareocclusionquad") == 0 )
    {
      v32 = (idRenderModelFlareOcclusionQuad *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                 size: 0x800u,
                                                 tag: TAG_RENDERMODEL,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
      v85 = v32;
      if ( v32 != nullptr )
        v33 = idRenderModelFlareOcclusionQuad::idRenderModelFlareOcclusionQuad(this: v32);
      else
        v33 = nullptr;
      v10 = v33;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_transparency") == 0 )
    {
      v34 = (idRenderModelTransparency *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x820u,
                                           tag: TAG_RENDERMODEL,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
      v85 = v34;
      if ( v34 != nullptr )
        v35 = idRenderModelTransparency::idRenderModelTransparency(this: v34);
      else
        v35 = nullptr;
      v10 = v35;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_foliage") == 0 )
    {
      v36 = (idRenderModelFoliage *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x810u,
                                      tag: TAG_RENDERMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
      v85 = v36;
      if ( v36 != nullptr )
        v37 = idRenderModelFoliage::idRenderModelFoliage(this: v36);
      else
        v37 = nullptr;
      v10 = v37;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_detail") == 0 )
    {
      v38 = (idRenderModelDetail *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x880u,
                                     tag: TAG_RENDERMODEL,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      v85 = v38;
      if ( v38 != nullptr )
        v39 = idRenderModelDetail::idRenderModelDetail(this: v38);
      else
        v39 = nullptr;
      v10 = v39;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_zipline") == 0 )
    {
      v40 = (idRenderModelZipline *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x8A0u,
                                      tag: TAG_RENDERMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
      v85 = v40;
      if ( v40 != nullptr )
        v41 = idRenderModelZipline::idRenderModelZipline(this: v40);
      else
        v41 = nullptr;
      v10 = v41;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_chain") == 0 )
    {
      v42 = (idRenderModelChain *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x8B0u,
                                    tag: TAG_RENDERMODEL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      v85 = v42;
      if ( v42 != nullptr )
        v43 = idRenderModelChain::idRenderModelChain(this: v42);
      else
        v43 = nullptr;
      v10 = v43;
      goto LABEL_157;
    }
    if ( idStr::Icmp(s1: v86.data, s2: "_cuttabledynamic") == 0 )
    {
      v44 = (idRenderModelCuttableDynamic *)idMem::AllocWithLocation(
                                              this: &mem,
                                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                              size: 0x7F0u,
                                              tag: TAG_RENDERMODEL,
                                              zeroBuffer: false,
                                              align: ALIGN_16,
                                              heap: HEAP_DEFAULTHEAP);
      v85 = v44;
      if ( v44 != nullptr )
        v45 = idRenderModelCuttableDynamic::idRenderModelCuttableDynamic(this: v44);
      else
        v45 = nullptr;
      v10 = v45;
      goto LABEL_157;
    }
    if ( idStr::Cmp(s1: v86.data, s2: "_cuttablebeams") == 0 )
    {
      v46 = (idRenderModelCuttableBeams *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x800u,
                                            tag: TAG_RENDERMODEL,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      v85 = v46;
      if ( v46 != nullptr )
        v47 = idRenderModelCuttableBeams::idRenderModelCuttableBeams(this: v46);
      else
        v47 = nullptr;
      v10 = v47;
      goto LABEL_157;
    }
    if ( idStr::Icmp(s1: v87.data, s2: "prt") != 0 )
    {
      if ( idStr::Icmp(s1: v87.data, s2: "flare") != 0 )
      {
        if ( idStr::Icmp(s1: v87.data, s2: "cloth") != 0 )
        {
          if ( idStr::Icmp(s1: v87.data, s2: "md6") != 0 && idStr::Icmp(s1: v87.data, s2: "decl") != 0 )
          {
            if ( idStr::Icmp(s1: v87.data, s2: "breakabledecl") != 0 )
            {
              if ( idStr::Icmp(s1: v87.data, s2: "break") != 0 )
              {
                if ( idStr::Icmp(s1: v87.data, s2: "watersurf") != 0 )
                {
                  if ( idStr::Icmp(s1: v87.data, s2: "csurf") != 0 )
                  {
                    v68 = staticModelManager->FindStaticModel(this: staticModelManager, a2: v88.data, a3: makeDefault);
                    if ( v68 == nullptr )
                    {
LABEL_141:
                      idStr::FreeData(this: &v88);
                      idStr::FreeData(this: &v87);
                      goto LABEL_90;
                    }
                    v69 = (idRenderModelStatic *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x810u,
                                                   tag: TAG_RENDERMODEL,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
                    v85 = v69;
                    if ( v69 != nullptr )
                      v70 = idRenderModelStatic::idRenderModelStatic(this: v69, smod: v68);
                    else
                      v70 = nullptr;
                    v10 = v70;
                  }
                  else
                  {
                    v66 = (idRenderModelCuttableSurface *)idMem::AllocWithLocation(
                                                            this: &mem,
                                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                            size: 0x800u,
                                                            tag: TAG_RENDERMODEL,
                                                            zeroBuffer: false,
                                                            align: ALIGN_16,
                                                            heap: HEAP_DEFAULTHEAP);
                    v85 = v66;
                    if ( v66 != nullptr )
                      v67 = idRenderModelCuttableSurface::idRenderModelCuttableSurface(this: v66, modelName: v88.data);
                    else
                      v67 = nullptr;
                    v10 = v67;
                  }
                }
                else
                {
                  v64 = (idRenderModelWaterSurface *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                       size: 0x870u,
                                                       tag: TAG_RENDERMODEL,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
                  v85 = v64;
                  if ( v64 != nullptr )
                    v65 = idRenderModelWaterSurface::idRenderModelWaterSurface(this: v64, modelName: v88.data);
                  else
                    v65 = nullptr;
                  v10 = v65;
                }
              }
              else
              {
                idStr::idStr(this: v93, text: &v88);
                idStr::StripFileExtension(this: v93);
                if ( v93[0].data == nullptr
                  || (v61 = (idDecl *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclBreakable::resourceList,
                                        name: v93[0].data,
                                        makeDefault)) == nullptr )
                {
                  idStr::FreeData(this: v93);
                  idStr::FreeData(this: &v88);
                  idStr::FreeData(this: &v87);
                  goto LABEL_90;
                }
                v62 = (idRenderModelDiscreteAnimation *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                          size: 0x850u,
                                                          tag: TAG_RENDERMODEL,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
                v85 = v62;
                if ( v62 != nullptr )
                  v63 = idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation(
                          this: v62,
                          modelName: (char *)v61[1].__vftable,
                          decl: v61);
                else
                  v63 = nullptr;
                v10 = v63;
                idStr::FreeData(this: v93);
              }
            }
            else
            {
              idStr::idStr(this: &v89, text: modelName);
              idStr::StripFileExtension(this: &v89);
              idStr::SetFileExtension(this: &v89, extension: "decl");
              if ( v89.data == nullptr
                || (v58 = (idDecl *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclBreakable::resourceList,
                                      name: v89.data,
                                      makeDefault: false)) == nullptr )
              {
                idStr::FreeData(this: &v89);
                idStr::FreeData(this: &v88);
                idStr::FreeData(this: &v87);
                goto LABEL_90;
              }
              v59 = (idRenderModelDiscreteAnimation *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                        size: 0x850u,
                                                        tag: TAG_RENDERMODEL,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
              v85 = v59;
              if ( v59 != nullptr )
                v60 = idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation(
                        this: v59,
                        modelName: (char *)v58[1].__vftable,
                        decl: v58);
              else
                v60 = nullptr;
              v10 = v60;
              idStr::FreeData(this: &v89);
            }
          }
          else
          {
            if ( v88.data == nullptr )
              goto LABEL_141;
            v71 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                       this: &idDeclMD6::resourceList,
                                       name: v88.data,
                                       makeDefault: false);
            if ( v71 == nullptr )
              goto LABEL_141;
            v72 = (idTreeAnimator *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x970u,
                                      tag: TAG_RENDERMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
            v85 = v72;
            if ( v72 != nullptr )
              v73 = idTreeAnimator::idTreeAnimator(this: v72, declMD6: v71);
            else
              v73 = nullptr;
            v10 = v73;
          }
        }
        else
        {
          idStr::idStr(this: &v91, text: &v88);
          idStr::StripFileExtension(this: &v91);
          if ( v91.data == nullptr
            || (v55 = (const idDeclCloth *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclCloth::resourceList,
                                             name: v91.data,
                                             makeDefault)) == nullptr )
          {
            idStr::FreeData(this: &v91);
            idStr::FreeData(this: &v88);
            idStr::FreeData(this: &v87);
            goto LABEL_90;
          }
          v56 = (idRenderModelCloth *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x890u,
                                        tag: TAG_RENDERMODEL,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
          v85 = v56;
          if ( v56 != nullptr )
            v57 = idRenderModelCloth::idRenderModelCloth(this: v56, clothSys: v55);
          else
            v57 = nullptr;
          v10 = v57;
          idStr::FreeData(this: &v91);
        }
      }
      else
      {
        idStr::idStr(this: &v90, text: &v88);
        idStr::StripFileExtension(this: &v90);
        if ( v90.data == nullptr
          || (v52 = (const idDeclFlare *)idDeclInfo::FindWithInheritance(
                                           this: &idDeclFlare::resourceList,
                                           name: v90.data,
                                           makeDefault)) == nullptr )
        {
          idStr::FreeData(this: &v90);
          idStr::FreeData(this: &v88);
          idStr::FreeData(this: &v87);
          goto LABEL_90;
        }
        v53 = (idRenderModelFlare *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x800u,
                                      tag: TAG_RENDERMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
        v85 = v53;
        if ( v53 != nullptr )
          v54 = idRenderModelFlare::idRenderModelFlare(this: v53, declFlare: v52);
        else
          v54 = nullptr;
        v10 = v54;
        idStr::FreeData(this: &v90);
      }
    }
    else
    {
      idStr::idStr(this: &v92, text: &v88);
      idStr::StripFileExtension(this: &v92);
      if ( v92.data == nullptr
        || (v48 = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                            this: &idDeclParticle::resourceList,
                                            name: v92.data,
                                            makeDefault)) == nullptr )
      {
        idStr::FreeData(this: &v92);
        idStr::FreeData(this: &v88);
        idStr::FreeData(this: &v87);
LABEL_90:
        idStr::FreeData(this: &v86);
        return nullptr;
      }
      v50 = (idRenderModelParticle *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x840u,
                                       tag: TAG_RENDERMODEL,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
      v85 = v50;
      if ( v50 != nullptr )
        v51 = idRenderModelParticle::idRenderModelParticle(this: v50, decl: v48);
      else
        v51 = nullptr;
      v10 = v51;
      idStr::FreeData(this: &v92);
    }
  }
  else
  {
    v74 = (idRenderModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x7F0u,
                             tag: TAG_RENDERMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    v85 = v74;
    if ( v74 != nullptr )
      v75 = idRenderModel::idRenderModel(this: v74);
    else
      v75 = nullptr;
    v10 = v75;
  }
LABEL_157:
  if ( v10 == nullptr )
  {
    if ( makeDefault )
      idLib::Error(fmt: "AllocRenderModel for %s failed", modelName);
    goto LABEL_141;
  }
  if ( index == -1 )
  {
    num = this->renderModels.num;
    p_renderModels = (idList<enum encounterGroupRole_t,5> *)&this->renderModels;
    v78 = 0;
    if ( num <= 0 )
      goto LABEL_168;
    v79 = 0;
    while ( p_renderModels->list[v79] != ROLE_NONE )
    {
      ++v78;
      ++v79;
      if ( v78 >= num )
        goto LABEL_168;
    }
    index = v78;
    if ( v78 == -1 )
    {
LABEL_168:
      size = this->renderModels.size;
      if ( this->renderModels.num == size )
      {
        if ( idLib::production != PROD_BUILDING && com_production.valueInteger == 0 )
          idLib::Error(fmt: "Max render models allocated.");
        v85 = (void *)size;
        index = size - 1;
      }
      else
      {
        v85 = nullptr;
        index = idList<idAnimWebBlendTree *,5>::Append(this: p_renderModels, obj: (const encounterGroupRole_t *)&v85);
      }
    }
  }
  if ( this->renderModels.list[index] != nullptr )
  {
    if ( idLib::production != PROD_BUILDING && com_production.valueInteger == 0 )
      idLib::Error(fmt: "RegisterRenderModel: index %d already in use", index);
    idLib::Warning(fmt: "RegisterRenderModel: index %d already in use", index);
  }
  this->renderModels.list[index] = v10;
  idAtomicString::Set(this: &v10->name, str_: v86.data);
  v10->committed->name = v10->name.str;
  v10->committed->world = this;
  v10->committed->index.index = (1 << (index & 7)) | (index << 8);
  idStr::FreeData(this: &v88);
  idStr::FreeData(this: &v87);
  idStr::FreeData(this: &v86);
  return v10;
}


// ========================================================================
// $LN476
// EA  : 0x8295AEC8
// RVA : 0x0095AEC8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _LN476()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$241318
// EA  : 0x8295AEF0
// RVA : 0x0095AEF0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241318()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$241319
// EA  : 0x8295AF18
// RVA : 0x0095AF18
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$241321
// EA  : 0x8295AF40
// RVA : 0x0095AF40
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241321()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241322
// EA  : 0x8295AF6C
// RVA : 0x0095AF6C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241322()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241323
// EA  : 0x8295AF98
// RVA : 0x0095AF98
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241323()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241324
// EA  : 0x8295AFC4
// RVA : 0x0095AFC4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241324()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241325
// EA  : 0x8295AFF0
// RVA : 0x0095AFF0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241325()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241326
// EA  : 0x8295B01C
// RVA : 0x0095B01C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241326()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241327
// EA  : 0x8295B048
// RVA : 0x0095B048
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241327()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241328
// EA  : 0x8295B074
// RVA : 0x0095B074
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241328()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241329
// EA  : 0x8295B0A0
// RVA : 0x0095B0A0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241329()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241330
// EA  : 0x8295B0CC
// RVA : 0x0095B0CC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241330()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241331
// EA  : 0x8295B0F8
// RVA : 0x0095B0F8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241331()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241332
// EA  : 0x8295B124
// RVA : 0x0095B124
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241332()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241333
// EA  : 0x8295B150
// RVA : 0x0095B150
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241333()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241334
// EA  : 0x8295B17C
// RVA : 0x0095B17C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241334()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241335
// EA  : 0x8295B1A8
// RVA : 0x0095B1A8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241335()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241336
// EA  : 0x8295B1D4
// RVA : 0x0095B1D4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241336()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241337
// EA  : 0x8295B200
// RVA : 0x0095B200
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241337()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 288));
}


// ========================================================================
// __unwind$241338
// EA  : 0x8295B228
// RVA : 0x0095B228
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241338()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241339
// EA  : 0x8295B254
// RVA : 0x0095B254
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241339()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 224));
}


// ========================================================================
// __unwind$241340
// EA  : 0x8295B27C
// RVA : 0x0095B27C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241340()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241341
// EA  : 0x8295B2A8
// RVA : 0x0095B2A8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241341()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 256));
}


// ========================================================================
// __unwind$241342
// EA  : 0x8295B2D0
// RVA : 0x0095B2D0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241342()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241344
// EA  : 0x8295B2FC
// RVA : 0x0095B2FC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241344()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$241345
// EA  : 0x8295B324
// RVA : 0x0095B324
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241345()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241346
// EA  : 0x8295B350
// RVA : 0x0095B350
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241346()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 320));
}


// ========================================================================
// __unwind$241347
// EA  : 0x8295B378
// RVA : 0x0095B378
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241347()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241348
// EA  : 0x8295B3A4
// RVA : 0x0095B3A4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241348()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241349
// EA  : 0x8295B3D0
// RVA : 0x0095B3D0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241349()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241350
// EA  : 0x8295B3FC
// RVA : 0x0095B3FC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241350()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241343
// EA  : 0x8295B428
// RVA : 0x0095B428
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241343()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$241320
// EA  : 0x8295B454
// RVA : 0x0095B454
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_241320()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?SetNumRenderViews@idRenderWorldLocal@@UAAXH@Z
// EA  : 0x8295B480
// RVA : 0x0095B480
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::SetNumRenderViews(idRenderWorldLocal *this, int num)
{
  idStaticList<idRenderView *,2> *p_renderViews; // r30
  int size; // r11

  p_renderViews = &this->renderViews;
  if ( num <= this->renderViews.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderViews,
                          newsize: num) != 0 )
  {
    size = p_renderViews->size;
    if ( num < size )
      size = num;
    p_renderViews->num = size;
  }
}


// ========================================================================
// ?AddLightRefToArea@idRenderWorldLocal@@QAAXPAVidRenderLightCommitted@@PAUworldArea_t@@@Z
// EA  : 0x8295B4F0
// RVA : 0x0095B4F0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::AddLightRefToArea(
        idRenderWorldLocal *this,
        idRenderLightCommitted *light,
        const idVoiceEvent *area,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        const idVoiceEvent *a16)
{
  BOOL isComboMap; // r11
  idList<worldArea_t *,62> *p_references; // r3
  lightClass_t lightClass; // r11
  lightClass_t v22; // r11
  idList<idRenderIndex,62> *p_startMS; // r3
  bool v24; // zf

  isComboMap = this->isComboMap;
  a16 = area;
  p_references = &light->references;
  if ( isComboMap )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)p_references,
      obj: (const encounterGroupRole_t *)&a16);
    lightClass = light->r.lightClass;
    if ( lightClass == LIGHT_SLOWLIGHT_DYNAMIC_ONLY
      || lightClass == LIGHT_SLOWLIGHT_PRIVATE_ONLY
      || lightClass == LIGHT_BLENDED_ONLY
      || lightClass == LIGHT_PRELIGHT_ONLY
      || !this->IsComboMap(this) )
    {
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(
        this: (idList<idStrId,5> *)&area[1].startMS,
        obj: (const idStrId *)&light->index);
    }
    else
    {
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(
        this: (idList<idStrId,5> *)&area[2].durationMS,
        obj: (const idStrId *)&light->index);
    }
  }
  else
  {
    idList<idDeclMD6 const *,5>::AddUnique(this: (idList<idVoiceEvent const *,5> *)p_references, obj: &a16);
    v22 = light->r.lightClass;
    if ( v22 == LIGHT_SLOWLIGHT_DYNAMIC_ONLY
      || v22 == LIGHT_SLOWLIGHT_PRIVATE_ONLY
      || v22 == LIGHT_BLENDED_ONLY
      || v22 == LIGHT_PRELIGHT_ONLY
      || (v24 = this->IsComboMap(this), p_startMS = (idList<idRenderIndex,62> *)&area[2].durationMS, !v24) )
    {
      p_startMS = (idList<idRenderIndex,62> *)&area[1].startMS;
    }
    idList<idRenderIndex,62>::AddUnique(this: p_startMS, obj: (const idStrId *)&light->index);
  }
  ++tr.pc.c_lightReferences;
}


// ========================================================================
// ?PushPolytopeIntoTree_r@idRenderWorldLocal@@QAAXPAVidRenderModelCommitted@@PAVidRenderLightCommitted@@ABVidBox@@PBVidVec3@@HH@Z
// EA  : 0x8295B600
// RVA : 0x0095B600
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::PushPolytopeIntoTree_r(
        idRenderWorldLocal *this,
        idRenderModelCommitted *model,
        idRenderLightCommitted *light,
        const idBox *box,
        const idVec3 *points,
        int numPoints,
        int nodeNum)
{
  bool v13; // cr56
  areaNode_t *areaNodes; // r10
  areaNode_t *v15; // r30
  double v16; // fp9
  unsigned __int8 v17; // r11
  unsigned __int8 v18; // r10
  int v19; // r8
  float *p_y; // r9
  double v21; // fp10
  int v22; // r7
  double v23; // fp10
  int v24; // r7
  double v25; // fp10
  int v26; // r7
  double v27; // fp10
  int v28; // r7
  float *v29; // r9
  double v30; // fp10
  int v31; // r7
  int v32; // r9
  worldArea_t *worldAreas; // r9
  int v34; // r10
  int v35; // r8
  int v36; // r7
  idList<idStrId,5> *v37; // r31
  BOOL isComboMap; // r11
  idRenderIndex *p_index; // r4
  idList<enum encounterGroupRole_t,5> *p_references; // r3
  int num; // r7
  int v42; // r10
  int v43; // r11
  int v44; // r9
  int v45; // r10
  int v46; // r11
  int v47; // [sp+8h] [-C8h]
  int v48; // [sp+Ch] [-C4h]
  int v49; // [sp+10h] [-C0h]
  int v50; // [sp+14h] [-BCh]
  int v51; // [sp+18h] [-B8h]
  int v52; // [sp+1Ch] [-B4h]
  int v53; // [sp+20h] [-B0h]
  const idVoiceEvent *v54; // [sp+24h] [-ACh]
  worldArea_t *v55; // [sp+50h] [-80h] BYREF

  v13 = nodeNum < 0;
  while ( !v13 )
  {
    areaNodes = this->areaNodes;
    v15 = &areaNodes[nodeNum];
    v16 = (float)((float)((float)__fabs((float)((float)((float)(v15->plane.a * box->axis.mat[0].x)
                                                      + (float)((float)(box->axis.mat[0].y * v15->plane.b)
                                                              + (float)(box->axis.mat[0].z * v15->plane.c)))
                                              * box->extents.x))
                        + (float)__fabs((float)((float)((float)(v15->plane.a * box->axis.mat[1].x)
                                                      + (float)((float)(box->axis.mat[1].y * v15->plane.b)
                                                              + (float)(box->axis.mat[1].z * v15->plane.c)))
                                              * box->extents.y)))
                + (float)__fabs((float)((float)((float)(v15->plane.a * box->axis.mat[2].x)
                                              + (float)((float)(box->axis.mat[2].y * v15->plane.b)
                                                      + (float)(box->axis.mat[2].z * v15->plane.c)))
                                      * box->extents.z)));
    if ( (float)((float)((float)((float)(v15->plane.a * box->center.x)
                               + (float)((float)(box->center.y * v15->plane.b) + (float)(box->center.z * v15->plane.c)))
                       + v15->plane.d)
               - (float)v16) >= 0.0 )
    {
      nodeNum = v15->children[0];
      goto LABEL_44;
    }
    if ( (float)((float)v16
               + (float)((float)((float)(areaNodes[nodeNum].plane.a * box->center.x)
                               + (float)((float)(box->center.y * areaNodes[nodeNum].plane.b)
                                       + (float)(box->center.z * areaNodes[nodeNum].plane.c)))
                       + areaNodes[nodeNum].plane.d)) <= 0.0 )
      goto LABEL_43;
    if ( numPoints <= 0 )
    {
LABEL_41:
      v32 = v15->children[0];
      if ( v32 != 0 )
        idRenderWorldLocal::PushPolytopeIntoTree_r(this, model, light, box, points, numPoints, nodeNum: v32);
LABEL_43:
      nodeNum = v15->children[1];
      goto LABEL_44;
    }
    v17 = 0;
    v18 = 0;
    v19 = 0;
    if ( numPoints >= 4 )
    {
      p_y = &points[1].y;
      do
      {
        v21 = (float)((float)((float)(v15->plane.a * *(p_y - 4))
                            + (float)((float)(v15->plane.b * *(p_y - 3)) + (float)(v15->plane.c * *(p_y - 2))))
                    + v15->plane.d);
        if ( v21 <= 0.0 )
        {
          if ( v21 >= 0.0 )
            goto LABEL_14;
          v22 = v18;
          v17 = 1;
        }
        else
        {
          v22 = v17;
          v18 = 1;
        }
        if ( v22 != 0 )
          goto LABEL_38;
LABEL_14:
        v23 = (float)((float)((float)(v15->plane.a * *(p_y - 1))
                            + (float)((float)(v15->plane.b * *p_y) + (float)(v15->plane.c * p_y[1])))
                    + v15->plane.d);
        if ( v23 <= 0.0 )
        {
          if ( v23 >= 0.0 )
            goto LABEL_19;
          v24 = v18;
          v17 = 1;
        }
        else
        {
          v24 = v17;
          v18 = 1;
        }
        if ( v24 != 0 )
          goto LABEL_38;
LABEL_19:
        v25 = (float)((float)((float)(v15->plane.a * p_y[2])
                            + (float)((float)(v15->plane.b * p_y[3]) + (float)(v15->plane.c * p_y[4])))
                    + v15->plane.d);
        if ( v25 <= 0.0 )
        {
          if ( v25 >= 0.0 )
            goto LABEL_24;
          v26 = v18;
          v17 = 1;
        }
        else
        {
          v26 = v17;
          v18 = 1;
        }
        if ( v26 != 0 )
          goto LABEL_38;
LABEL_24:
        v27 = (float)((float)((float)(v15->plane.c * p_y[7])
                            + (float)((float)(v15->plane.a * p_y[5]) + (float)(v15->plane.b * p_y[6])))
                    + v15->plane.d);
        if ( v27 > 0.0 )
        {
          v28 = v17;
          v18 = 1;
          goto LABEL_28;
        }
        if ( v27 < 0.0 )
        {
          v28 = v18;
          v17 = 1;
LABEL_28:
          if ( v28 != 0 )
            goto LABEL_38;
        }
        v19 += 4;
        p_y += 12;
      }
      while ( v19 < numPoints - 3 );
    }
    if ( v19 < numPoints )
    {
      v29 = &points[v19].y;
      while ( 1 )
      {
        v30 = (float)((float)((float)(v15->plane.a * *(v29 - 1))
                            + (float)((float)(v15->plane.b * *v29) + (float)(v15->plane.c * v29[1])))
                    + v15->plane.d);
        if ( v30 > 0.0 )
          break;
        if ( v30 < 0.0 )
        {
          v31 = v18;
          v17 = 1;
LABEL_36:
          if ( v31 != 0 )
            goto LABEL_38;
        }
        ++v19;
        v29 += 3;
        if ( v19 >= numPoints )
          goto LABEL_38;
      }
      v31 = v17;
      v18 = 1;
      goto LABEL_36;
    }
LABEL_38:
    if ( (v17 & v18) != 0 )
      goto LABEL_41;
    if ( v18 == 0 )
      goto LABEL_43;
    nodeNum = v15->children[0];
LABEL_44:
    v13 = nodeNum < 0;
    if ( nodeNum == 0 )
      return;
  }
  v34 = 8 * (nodeNum + 1);
  v35 = 9 * (nodeNum + 1);
  v36 = 72 * (nodeNum + 1);
  worldAreas = this->worldAreas;
  v37 = (idList<idStrId,5> *)&worldAreas[v35 / 0xFFFFFFF7];
  if ( model != nullptr )
  {
    isComboMap = this->isComboMap;
    p_index = &model->index;
    v55 = &worldAreas[v35 / 0xFFFFFFF7];
    if ( isComboMap )
    {
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(
        this: (idList<idStrId,5> *)&worldAreas[v35 / 0xFFFFFFF7],
        obj: (const idStrId *)p_index);
      p_references = (idList<enum encounterGroupRole_t,5> *)&model->references;
    }
    else
    {
      num = v37->num;
      v42 = 0;
      if ( num <= 0 )
        goto LABEL_55;
      v43 = 0;
      while ( v37->list[v43].index != p_index->index )
      {
        ++v42;
        ++v43;
        if ( v42 >= num )
          goto LABEL_55;
      }
      if ( v42 < 0 )
LABEL_55:
        idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: v37, obj: (const idStrId *)p_index);
      v44 = model->references.num;
      p_references = (idList<enum encounterGroupRole_t,5> *)&model->references;
      v45 = 0;
      if ( v44 > 0 )
      {
        v46 = 0;
        while ( (idList<idStrId,5> *)p_references->list[v46] != v37 )
        {
          ++v45;
          ++v46;
          if ( v45 >= v44 )
            goto LABEL_62;
        }
        if ( v45 >= 0 )
          goto LABEL_63;
      }
    }
LABEL_62:
    idList<idAnimWebBlendTree *,5>::Append(this: p_references, obj: (const encounterGroupRole_t *)&v55);
LABEL_63:
    ++tr.pc.c_modelReferences;
    return;
  }
  idRenderWorldLocal::AddLightRefToArea(
    this,
    light,
    area: (const idVoiceEvent *)&worldAreas[v35 / 0xFFFFFFF7],
    a4: (int)box,
    a5: v36,
    a6: v35,
    a7: (int)worldAreas,
    a8: v34,
    a9: v47,
    a10: v48,
    a11: v49,
    a12: v50,
    a13: v51,
    a14: v52,
    a15: v53,
    a16: v54);
}


// ========================================================================
// ?PushPolytopeIntoTree@idRenderWorldLocal@@QAAXPAVidRenderModelCommitted@@PAVidRenderLightCommitted@@ABVidBox@@PBVidVec3@@H@Z
// EA  : 0x8295BA68
// RVA : 0x0095BA68
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::PushPolytopeIntoTree(
        idRenderWorldLocal *this,
        idRenderModelCommitted *model,
        idRenderLightCommitted *light,
        const idBox *box,
        const idVec3 *points,
        int numPoints)
{
  if ( this->areaNodes != nullptr )
  {
    if ( model != nullptr )
    {
      *(idRenderModelCommitted **)((char *)this->linkedRenderModels.list + ((model->index.index >> 6) & 0x3FFFFFC)) = model;
    }
    else if ( light != nullptr )
    {
      *(idRenderLightCommitted **)((char *)this->linkedRenderLights.list + ((light->index.index >> 6) & 0x3FFFFFC)) = light;
    }
    idRenderWorldLocal::PushPolytopeIntoTree_r(this, model, light, box, points, numPoints, nodeNum: 0);
  }
}


// ========================================================================
// ?AddEnvironment@idRenderWorldLocal@@UAAXABVidBounds@@PBVidDeclEnv@@@Z
// EA  : 0x8295C050
// RVA : 0x0095C050
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::AddEnvironment(
        idRenderWorldLocal *this,
        idBounds *b,
        const idDeclEnv *envEffectsDecl)
{
  int num; // r31
  double Volume; // fp1
  int v8; // r5
  dynamicEnvironment_t *v9; // r8
  int v10; // r9
  float *v11; // r11
  double v12; // fp0
  double v13; // fp0
  int v14; // r10
  dynamicEnvironment_t *v15; // r11
  double v16; // fp0
  float *v17; // r11
  double v18; // fp0
  dynamicEnvironment_t *list; // r9
  int v20; // r10
  float *v21; // r11
  double v22; // fp0
  double x; // fp0
  double z; // fp12
  double v25; // fp11
  double y; // fp10
  double v27; // fp9
  dynamicEnvironment_t v28; // [sp+50h] [-50h] BYREF

  if ( envEffectsDecl != nullptr )
  {
    num = this->dynamicEnvironments.num;
    if ( num == 128 )
    {
      idLib::Warning(fmt: "MAX_DYNAMIC_ENVIRONMENT exceeded");
    }
    else
    {
      Volume = idBounds::GetVolume(this: b);
      v8 = 0;
      if ( num < 4 )
      {
LABEL_31:
        if ( v8 < num )
        {
          list = this->dynamicEnvironments.list;
          v20 = v8;
          do
          {
            v21 = (float *)&list[v20];
            if ( list[v20].bounds.b[0].x >= (double)list[v20].bounds.b[1].x
              || v21[1] >= (double)v21[4]
              || v21[2] >= (double)v21[5] )
            {
              v22 = 0.0;
            }
            else
            {
              v22 = (float)((float)((float)(v21[5] - v21[2]) * (float)(v21[4] - v21[1]))
                          * (float)(list[v20].bounds.b[1].x - list[v20].bounds.b[0].x));
            }
            if ( Volume < v22 )
              break;
            ++v8;
            ++v20;
          }
          while ( v8 < num );
        }
      }
      else
      {
        v9 = this->dynamicEnvironments.list;
        v10 = 0;
        while ( 1 )
        {
          v11 = (float *)&v9[v10];
          if ( v9[v10].bounds.b[0].x >= (double)v9[v10].bounds.b[1].x
            || v11[1] >= (double)v11[4]
            || v11[2] >= (double)v11[5] )
          {
            v12 = 0.0;
          }
          else
          {
            v12 = (float)((float)((float)(v11[5] - v11[2]) * (float)(v11[4] - v11[1]))
                        * (float)(v9[v10].bounds.b[1].x - v9[v10].bounds.b[0].x));
          }
          if ( Volume < v12 )
            break;
          if ( v11[7] >= (double)v11[10] || v11[8] >= (double)v11[11] || v11[9] >= (double)v11[12] )
            v13 = 0.0;
          else
            v13 = (float)((float)((float)(v11[12] - v11[9]) * (float)(v11[11] - v11[8])) * (float)(v11[10] - v11[7]));
          if ( Volume < v13 )
          {
            ++v8;
            break;
          }
          v14 = v10 * 28 + 84;
          v15 = &v9[v10 + 3];
          if ( v15[-1].bounds.b[0].x >= (double)v15[-1].bounds.b[1].x
            || v15[-1].bounds.b[0].y >= (double)v15[-1].bounds.b[1].y
            || v15[-1].bounds.b[0].z >= (double)v15[-1].bounds.b[1].z )
          {
            v16 = 0.0;
          }
          else
          {
            v16 = (float)((float)((float)(v15[-1].bounds.b[1].z - v15[-1].bounds.b[0].z)
                                * (float)(v15[-1].bounds.b[1].y - v15[-1].bounds.b[0].y))
                        * (float)(v15[-1].bounds.b[1].x - v15[-1].bounds.b[0].x));
          }
          if ( Volume < v16 )
          {
            v8 += 2;
            break;
          }
          v17 = (float *)((char *)v9 + v14);
          if ( *(float *)((char *)&v9->bounds.b[0].x + v14) >= (double)*(float *)((char *)&v9->bounds.b[1].x + v14)
            || v17[1] >= (double)v17[4]
            || v17[2] >= (double)v17[5] )
          {
            v18 = 0.0;
          }
          else
          {
            v18 = (float)((float)((float)(v17[5] - v17[2]) * (float)(v17[4] - v17[1]))
                        * (float)(*(float *)((char *)&v9->bounds.b[1].x + v14)
                                - *(float *)((char *)&v9->bounds.b[0].x + v14)));
          }
          if ( Volume < v18 )
          {
            v8 += 3;
            break;
          }
          v8 += 4;
          v10 += 4;
          if ( v8 >= num - 3 )
            goto LABEL_31;
        }
      }
      x = b->b[0].x;
      v28.env = envEffectsDecl;
      z = b->b[0].z;
      v25 = b->b[1].x;
      y = b->b[1].y;
      v27 = b->b[1].z;
      v28.bounds.b[0].y = b->b[0].y;
      v28.bounds.b[0].x = x;
      v28.bounds.b[0].z = z;
      v28.bounds.b[1].x = v25;
      v28.bounds.b[1].y = y;
      v28.bounds.b[1].z = v27;
      idList<dynamicEnvironment_t,5>::Insert(this: &this->dynamicEnvironments, obj: &v28, index: v8);
    }
  }
}


// ========================================================================
// ?ClearEnvironments@idRenderWorldLocal@@UAAXXZ
// EA  : 0x8295C300
// RVA : 0x0095C300
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::ClearEnvironments(idRenderWorldLocal *this)
{
  __int64 v1; // r29
  idStaticList<dynamicEnvironment_t,128> *p_dynamicEnvironments; // r31
  idRenderView *v4; // r3

  p_dynamicEnvironments = &this->dynamicEnvironments;
  if ( this->dynamicEnvironments.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dynamicEnvironments);
  LODWORD(v1) = 0;
  p_dynamicEnvironments->num = __CFADD__(-p_dynamicEnvironments->size, p_dynamicEnvironments->size ^ 0x80000000)
                             ? 0
                             : p_dynamicEnvironments->size;
  v4 = this->RenderViewForIndex(this, a2: 0);
  *(_QWORD *)&v4->envBlend.env = v1;
  *(_QWORD *)&v4->envBlend.blendDuration = v1;
}


// ========================================================================
// ?ListRenderModelsGrouped_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8295C380
// RVA : 0x0095C380
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall ListRenderModelsGrouped_f(const idCmdArgs *args)
{
  unsigned __int64 v1; // r8
  int v2; // r6
  int v3; // r21
  __int64 v4; // r10
  signed int num; // r27
  int v6; // r22
  idVehicleState **list; // r25
  idRenderModel *v8; // r26
  char v9; // r28
  signed int v10; // r30
  const char **v11; // r29
  int v12; // r11
  idVehicleState **v13; // r30
  signed int i; // r29
  idVehicleState *v15; // r4
  idSort_Quick<renderModelDetails_t,idSort_DetailSort> v16; // [sp+50h] [-90h] BYREF
  renderModelDetails_t v17; // [sp+58h] [-88h] BYREF
  idList<idVehicleState *,5> v18[8]; // [sp+60h] [-80h] BYREF

  if ( tr.primaryWorld != nullptr )
  {
    memset(v18, 0, 14);
    v18[0].listStatic = 0;
    v18[0].memTag = 5;
    idList<idThread *,58>::Clear(this: v18);
    LODWORD(v4) = tr.primaryWorld;
    v3 = 0;
    HIDWORD(v4) = tr.primaryWorld->renderModels.num;
    if ( SHIDWORD(v4) <= 0 )
    {
      num = v18[0].num;
      list = v18[0].list;
    }
    else
    {
      num = v18[0].num;
      v6 = 0;
      list = v18[0].list;
      do
      {
        v8 = tr.primaryWorld->renderModels.list[v6];
        if ( v8 != nullptr )
        {
          v9 = 0;
          v10 = 0;
          if ( num > 0 )
          {
            v11 = (const char **)list;
            while ( idStr::Icmp(s1: *v11, s2: v8->name.str) != 0 )
            {
              ++v10;
              v11 += 2;
              if ( v10 >= num )
                goto LABEL_11;
            }
            v9 = 1;
            list[2 * v10 + 1] = (idVehicleState *)((char *)list[2 * v10 + 1] + 1);
          }
LABEL_11:
          if ( v9 == 0 )
          {
            HIDWORD(v4) = v8->name.str;
            v12 = 0;
            v17.modelName = (const char *)HIDWORD(v4);
            v17.count = 1;
            if ( num <= 0 )
              goto LABEL_18;
            LODWORD(v4) = list;
            while ( 1 )
            {
              LODWORD(v1) = *(_DWORD *)v4;
              HIDWORD(v1) = *(_DWORD *)v4 - HIDWORD(v4);
              v2 = _cntlzw(HIDWORD(v1));
              if ( (v2 & 0x20) != 0 )
                break;
              ++v12;
              LODWORD(v4) = v4 + 8;
              if ( v12 >= num )
                goto LABEL_18;
            }
            if ( v12 < 0 )
            {
LABEL_18:
              idList<renderModelDetails_t,5>::Append(this: (idList<renderModelDetails_t,5> *)v18, obj: &v17);
              num = v18[0].num;
              list = v18[0].list;
            }
          }
        }
        ++v3;
        ++v6;
        LODWORD(v4) = tr.primaryWorld->renderModels.num;
      }
      while ( v3 < (int)v4 );
    }
    v16.__vftable = (idSort_Quick<renderModelDetails_t,idSort_DetailSort>_vtbl *)&idSort_DetailSort::`vftable';
    if ( list != nullptr )
      idSort_Quick<renderModelDetails_t,idSort_DetailSort>::Sort(
        this: &v16,
        base: (renderModelDetails_t *)list,
        num,
        a4: v2,
        a5: v1,
        a6: v4);
    v16.__vftable = (idSort_Quick<renderModelDetails_t,idSort_DetailSort>_vtbl *)&idSort<renderModelDetails_t>::`vftable';
    if ( num > 0 )
    {
      v13 = list - 2;
      for ( i = num; i != 0; --i )
      {
        v15 = v13[3];
        v13 += 2;
        idLib::Printf(fmt: "%d %s\n", v15, (const char *)*v13);
      }
    }
    idLib::Printf(fmt: "Total RenderModels: %d\n", tr.primaryWorld->renderModels.num);
    if ( (v18[0].listStatic == 0 || v18[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$243151
// EA  : 0x8295C5A4
// RVA : 0x0095C5A4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243151()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$243152_0
// EA  : 0x8295C5CC
// RVA : 0x0095C5CC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243152_0()
{
  int v0; // r12

  idSort_DetailSort::~idSort_DetailSort(this: (idSort_DetailSort *)(v0 - 224 + 80));
}


// ========================================================================
// ?CountModelsPerNode_r@@YAXPBVidRenderWorldLocal@@HAAH11@Z
// EA  : 0x8295C5F8
// RVA : 0x0095C5F8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall CountModelsPerNode_r(
        const idRenderWorldLocal *world,
        int nodeNum,
        int *totalNodes,
        int *totalModelRefs,
        int *maxModelRefsPerNode)
{
  int num; // r11
  areaNode_t *areaNodes; // r11
  areaNode_t *v11; // r28
  int v12; // r4
  int v13; // r4
  worldArea_t v14; // [sp+50h] [-80h] BYREF

  if ( nodeNum >= 0 )
  {
    areaNodes = world->areaNodes;
    ++*totalNodes;
    v11 = &areaNodes[nodeNum];
    v12 = v11->children[0];
    if ( v12 != 0 )
      CountModelsPerNode_r(world, nodeNum: v12, totalNodes, totalModelRefs, maxModelRefsPerNode);
    v13 = v11->children[1];
    if ( v13 != 0 )
      CountModelsPerNode_r(world, nodeNum: v13, totalNodes, totalModelRefs, maxModelRefsPerNode);
  }
  else
  {
    worldArea_t::worldArea_t(this: &v14, __that: &world->worldAreas[-nodeNum - 1]);
    num = v14.modelRefs.num;
    *totalModelRefs += v14.modelRefs.num;
    if ( num > *maxModelRefsPerNode )
      *maxModelRefsPerNode = num;
    idSurface::~idSurface(this: (splineMoverModifier_t::splineMoverModifierSound_t *)&v14);
  }
}


// ========================================================================
// ?countModelsPerNode_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8295C6D8
// RVA : 0x0095C6D8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall countModelsPerNode_f(const idCmdArgs *args)
{
  idRenderWorldLocal *primaryWorld; // r31
  areaNode_t *areaNodes; // r30
  int v3; // r4
  int v4; // r4
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // [sp+50h] [-30h] BYREF
  int v9; // [sp+54h] [-2Ch] BYREF
  int v10[4]; // [sp+58h] [-28h] BYREF

  primaryWorld = tr.primaryWorld;
  if ( tr.primaryWorld != nullptr )
  {
    v8 = 0;
    v9 = 0;
    v10[0] = 0;
    areaNodes = tr.primaryWorld->areaNodes;
    v8 = 1;
    v3 = areaNodes->children[0];
    if ( v3 != 0 )
      CountModelsPerNode_r(
        world: tr.primaryWorld,
        nodeNum: v3,
        totalNodes: &v8,
        totalModelRefs: &v9,
        maxModelRefsPerNode: v10);
    v4 = areaNodes->children[1];
    if ( v4 != 0 )
      CountModelsPerNode_r(
        world: primaryWorld,
        nodeNum: v4,
        totalNodes: &v8,
        totalModelRefs: &v9,
        maxModelRefsPerNode: v10);
    idLib::Printf(fmt: "total nodes = %d\n", v8);
    idLib::Printf(fmt: "total model refs = %d\n", v9);
    v5 = v8;
    v6 = v9;
    v7 = v8 / 2;
    __twllei(v8, 0);
    __twlgei(v5 & ~(__ROL4__(v7 + v6, 1) - 1), 0xFFFFFFFF);
    idLib::Printf(fmt: "average model refs per node = %d\n", (v7 + v6) / v5);
    idLib::Printf(fmt: "maximum model refs per node = %d\n", v10[0]);
  }
}


// ========================================================================
// ??0idRenderWorldLocal@@QAA@XZ
// EA  : 0x8295C7E8
// RVA : 0x0095C7E8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idRenderWorldLocal *__fastcall idRenderWorldLocal::idRenderWorldLocal(idRenderWorldLocal *this)
{
  idStr *p_mapName; // r17
  idStaticList<idRenderView *,2> *p_renderViews; // r24
  idHashIndex *p_binaryModelHash; // r16
  idStaticList<idStr,1024> *p_binaryModelNames; // r15
  idStaticList<bool,1024> *p_binaryModelState; // r22
  int size; // r11
  int v8; // r11
  int v9; // r11
  int v10; // r11
  int v11; // r27
  int i; // r28
  idRenderView *v13; // r3
  idRenderView *v14; // r3
  idRenderView *v15; // r5
  int *indexChain; // r3
  int v17; // r4
  bool *list; // r4
  const idRenderLightCommitted **v19; // r3
  int v21[40]; // [sp+50h] [-A0h] BYREF

  p_mapName = &this->mapName;
  this->__vftable = (idRenderWorldLocal_vtbl *)&idRenderWorldLocal::`vftable';
  this->mapName.len = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  idIndexBuffer::idIndexBuffer(this: (idIndexBuffer *)&this->worldVertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->worldIndexBuffer);
  idAmbientLighting::idAmbientLighting(this: &this->ambientLighting);
  idGlobalShadows::idGlobalShadows(this: &this->globalShadows);
  this->dynamicEnvironments.num = 0;
  this->dynamicEnvironments.granularity = 1;
  this->dynamicEnvironments.memTag = 5;
  this->dynamicEnvironments.size = 128;
  this->dynamicEnvironments.list = this->dynamicEnvironments.staticList;
  this->dynamicEnvironments.listStatic = 1;
  this->renderModels.num = 0;
  this->renderModels.size = 4096;
  this->renderModels.granularity = 1;
  this->renderModels.list = this->renderModels.staticList;
  this->renderModels.memTag = 5;
  this->renderModels.listStatic = 1;
  this->renderLights.size = 4096;
  this->renderLights.num = 0;
  this->renderLights.granularity = 1;
  this->renderLights.list = this->renderLights.staticList;
  this->renderLights.memTag = 5;
  this->renderLights.listStatic = 1;
  this->serializedLights.size = 4096;
  this->serializedLights.num = 0;
  this->serializedLights.granularity = 1;
  this->serializedLights.list = this->serializedLights.staticList;
  this->serializedLights.memTag = 5;
  this->serializedLights.listStatic = 1;
  p_renderViews = &this->renderViews;
  this->renderViews.num = 0;
  this->renderViews.granularity = 1;
  this->renderViews.size = 2;
  this->renderViews.list = this->renderViews.staticList;
  this->renderViews.memTag = 5;
  this->renderViews.listStatic = 1;
  p_binaryModelHash = &this->binaryModelHash;
  this->binaryModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->binaryModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  p_binaryModelNames = &this->binaryModelNames;
  idStaticList<idStr,1024>::idStaticList<idStr,1024>(this: &this->binaryModelNames);
  p_binaryModelState = &this->binaryModelState;
  this->binaryModelState.size = 1024;
  this->binaryModelState.num = 0;
  this->binaryModelState.granularity = 1;
  this->binaryModelState.list = this->binaryModelState.staticList;
  this->binaryModelState.memTag = 5;
  this->binaryModelState.listStatic = 1;
  this->linkedRenderModels.size = 4096;
  this->linkedRenderModels.num = 0;
  this->linkedRenderModels.granularity = 1;
  this->linkedRenderModels.list = this->linkedRenderModels.staticList;
  this->linkedRenderModels.memTag = 5;
  this->linkedRenderModels.listStatic = 1;
  v21[0] = (int)&this->linkedRenderLights;
  this->linkedRenderLights.size = 4096;
  this->linkedRenderLights.num = 0;
  this->linkedRenderLights.granularity = 1;
  this->linkedRenderLights.list = this->linkedRenderLights.staticList;
  this->linkedRenderLights.memTag = 5;
  this->linkedRenderLights.listStatic = 1;
  this->megaTextures.list = nullptr;
  this->megaTextures.granularity = 0;
  this->megaTextures.memTag = 61;
  this->megaTextures.listStatic = 0;
  this->megaTextures.size = 0;
  this->megaTextures.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->megaTextures);
  this->rb_debugLines.list = nullptr;
  this->rb_debugLines.granularity = 0;
  this->rb_debugLines.memTag = 3;
  this->rb_debugLines.listStatic = 0;
  this->rb_debugLines.size = 0;
  this->rb_debugLines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rb_debugLines);
  this->rb_debugText.list = nullptr;
  this->rb_debugText.granularity = 0;
  this->rb_debugText.memTag = 3;
  this->rb_debugText.listStatic = 0;
  this->rb_debugText.size = 0;
  this->rb_debugText.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rb_debugText);
  this->rb_debugPolygons.granularity = 0;
  this->rb_debugPolygons.memTag = 3;
  this->rb_debugPolygons.listStatic = 0;
  this->rb_debugPolygons.list = nullptr;
  this->rb_debugPolygons.size = 0;
  this->rb_debugPolygons.num = 0;
  this->rb_debugBounds.list = nullptr;
  this->rb_debugBounds.granularity = 0;
  this->rb_debugBounds.memTag = 3;
  this->rb_debugBounds.listStatic = 0;
  this->rb_debugBounds.size = 0;
  this->rb_debugBounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rb_debugBounds);
  this->latchedDebugLines.list = nullptr;
  this->latchedDebugLines.granularity = 0;
  this->latchedDebugLines.memTag = 3;
  this->latchedDebugLines.listStatic = 0;
  this->latchedDebugLines.size = 0;
  this->latchedDebugLines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->latchedDebugLines);
  this->latchedDebugText.list = nullptr;
  this->latchedDebugText.granularity = 0;
  this->latchedDebugText.memTag = 3;
  this->latchedDebugText.listStatic = 0;
  this->latchedDebugText.size = 0;
  this->latchedDebugText.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->latchedDebugText);
  this->latchedDebugPolygons.granularity = 0;
  this->latchedDebugPolygons.memTag = 3;
  this->latchedDebugPolygons.listStatic = 0;
  this->latchedDebugPolygons.list = nullptr;
  this->latchedDebugPolygons.size = 0;
  this->latchedDebugPolygons.num = 0;
  this->latchedDebugBounds.list = nullptr;
  this->latchedDebugBounds.granularity = 0;
  this->latchedDebugBounds.memTag = 3;
  this->latchedDebugBounds.listStatic = 0;
  this->latchedDebugBounds.size = 0;
  this->latchedDebugBounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->latchedDebugBounds);
  idStr::Clear(this: p_mapName);
  this->isComboMap = false;
  this->everInitialized = false;
  this->specificationCompleteHasBeenCalled = false;
  this->hasWorldSurfaceOffsets = false;
  this->nextOnWorldList = nullptr;
  this->areaNodes = nullptr;
  this->numAreaNodes = 0;
  this->worldAreas = nullptr;
  this->numWorldAreas = 0;
  this->worldStaticModel = nullptr;
  this->worldRenderModel = nullptr;
  this->skyModel = nullptr;
  this->occlusionBaseModel = nullptr;
  if ( this->dynamicEnvironments.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dynamicEnvironments);
  size = this->dynamicEnvironments.size;
  v21[0] = 0;
  this->dynamicEnvironments.num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
  idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)&this->renderModels, newNum: 4096, initValue: v21);
  if ( this->renderModels.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->renderModels);
  v8 = this->renderModels.size;
  v21[0] = 0;
  this->renderModels.num = __CFADD__(-v8, v8 ^ 0x80000000) ? 0 : v8;
  idList<idRenderModelCommitted *,5>::SetNum(this: (idList<int,5> *)&this->renderLights, newNum: 4096, initValue: v21);
  if ( this->renderLights.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->renderLights);
  v9 = this->renderLights.size;
  v21[0] = 0;
  this->renderLights.num = __CFADD__(-v9, v9 ^ 0x80000000) ? 0 : v9;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->serializedLights,
    newNum: 4096,
    initValue: v21);
  if ( this->serializedLights.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->serializedLights);
  this->serializedLights.num = __CFADD__(-this->serializedLights.size, this->serializedLights.size ^ 0x80000000)
                             ? 0
                             : this->serializedLights.size;
  memset(Dst: &this->deletedModels, Val: 0, Size: sizeof(this->deletedModels));
  memset(Dst: &this->commitModels, Val: 0, Size: sizeof(this->commitModels));
  memset(Dst: &this->commitLights, Val: 0, Size: sizeof(this->commitLights));
  memset(Dst: &this->postCommitModels, Val: 0, Size: sizeof(this->postCommitModels));
  memset(Dst: &this->postCommitLights, Val: 0, Size: sizeof(this->postCommitLights));
  if ( this->renderViews.size >= 2
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderViews,
                          newsize: 2) != 0 )
  {
    v10 = this->renderViews.size;
    if ( v10 > 2 )
      v10 = 2;
    this->renderViews.num = v10;
  }
  v11 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v13 = (idRenderView *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x1180u,
                            tag: TAG_RENDERWORLD,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v21[0] = (int)v13;
    if ( v13 != nullptr )
      v14 = idRenderView::idRenderView(this: v13);
    else
      v14 = nullptr;
    p_renderViews->list[i] = v14;
    p_renderViews->list[i]->imgViewColor = tr.imgViewColor[i];
    v15 = p_renderViews->list[i];
    v15->viewIndex = v11++;
  }
  if ( p_binaryModelHash->hash != idHashIndex::INVALID_INDEX )
    memset(Dst: p_binaryModelHash->hash, Val: 255, Size: 4 * this->binaryModelHash.hashSize);
  indexChain = this->binaryModelHash.indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
    memset(Dst: indexChain, Val: 255, Size: 4 * this->binaryModelHash.indexSize);
  v17 = this->binaryModelNames.size;
  if ( v17 < 0 )
  {
    if ( this->binaryModelNames.listStatic == 0 || this->binaryModelNames.listStatic == 2 )
    {
      if ( p_binaryModelNames->list != nullptr )
        idListArrayDelete<idStr>(ptr: p_binaryModelNames->list, num: v17);
      p_binaryModelNames->list = nullptr;
      this->binaryModelNames.size = 0;
    }
    this->binaryModelNames.num = 0;
  }
  this->binaryModelNames.num = __CFADD__(-this->binaryModelNames.size, this->binaryModelNames.size ^ 0x80000000)
                             ? 0
                             : this->binaryModelNames.size;
  if ( this->binaryModelState.size < 0 )
  {
    if ( this->binaryModelState.listStatic == 0 || this->binaryModelState.listStatic == 2 )
    {
      list = p_binaryModelState->list;
      if ( p_binaryModelState->list != nullptr )
      {
        v21[0] = (int)p_binaryModelState->list;
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      p_binaryModelState->list = nullptr;
      this->binaryModelState.size = 0;
    }
    this->binaryModelState.num = 0;
  }
  this->binaryModelState.num = __CFADD__(-this->binaryModelState.size, this->binaryModelState.size ^ 0x80000000)
                             ? 0
                             : this->binaryModelState.size;
  idRenderWorldLocal::SetBinaryModelState_Internal(
    this,
    binaryModelName: "world",
    isVisible: true,
    makingDefinition: true);
  this->stampModel = nullptr;
  this->foliageRenderModel = nullptr;
  this->foliageEditRenderModel = nullptr;
  this->detailEditRenderModel = nullptr;
  this->detailRenderModel = nullptr;
  this->transparencyRenderModel = nullptr;
  this->decalRenderModel = nullptr;
  this->transparencyJobList = parallelJobManager->AllocJobList(
                                this: parallelJobManager,
                                a2: 3,
                                a3: 2,
                                a4: 4096,
                                a5: 16,
                                a6: &idColor::colorMagenta);
  this->renderModelJobList = parallelJobManager->AllocJobList(
                               this: parallelJobManager,
                               a2: 2,
                               a3: 2,
                               a4: 1024,
                               a5: 32,
                               a6: &idColor::colorPurple);
  this->approximateLightingParms = (approximateLightingParms_t *)idMem::AllocWithLocation(
                                                                   this: &mem,
                                                                   location: "w:\\tech5\\engine\\renderer\\RenderWorld.cpp(129) : TAG_RENDERWORLD",
                                                                   size: 0x1000u,
                                                                   tag: TAG_RENDERWORLD,
                                                                   zeroBuffer: false,
                                                                   align: ALIGN_128,
                                                                   heap: HEAP_DEFAULTHEAP);
  this->numApproximateLightingParms = 0;
  v19 = (const idRenderLightCommitted **)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\renderer\\RenderWorld.cpp(131) : TAG_RENDERWORLD",
                                           size: 0x2000u,
                                           tag: TAG_RENDERWORLD,
                                           zeroBuffer: false,
                                           align: ALIGN_128,
                                           heap: HEAP_DEFAULTHEAP);
  v21[0] = 0;
  this->approximateLightingLights = v19;
  this->numApproximateLightingLights = 0;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->linkedRenderModels,
    newNum: 4096,
    initValue: v21);
  v21[0] = 0;
  idList<idRenderModelCommitted *,5>::SetNum(
    this: (idList<int,5> *)&this->linkedRenderLights,
    newNum: 4096,
    initValue: v21);
  this->addAlwaysModels = nullptr;
  this->dimShadowModels = nullptr;
  this->testEnv = nullptr;
  this->worldEnableStaticSpecular = false;
  return this;
}


// ========================================================================
// __unwind$243444
// EA  : 0x8295D030
// RVA : 0x0095D030
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243444()
{
  int v0; // r12

  idRenderWorld::~idRenderWorld(this: *(idRenderWorld **)(v0 - 240 + 260));
}


// ========================================================================
// __unwind$243445
// EA  : 0x8295D058
// RVA : 0x0095D058
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243445()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 240 + 260) + 4));
}


// ========================================================================
// __unwind$243446
// EA  : 0x8295D084
// RVA : 0x0095D084
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243446()
{
  int v0; // r12

  idVertexBuffer::~idVertexBuffer(this: (idVertexBuffer *)(*(_DWORD *)(v0 - 240 + 260) + 76));
}


// ========================================================================
// __unwind$243447
// EA  : 0x8295D0B0
// RVA : 0x0095D0B0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243447()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 240 + 260) + 92));
}


// ========================================================================
// __unwind$243448
// EA  : 0x8295D0DC
// RVA : 0x0095D0DC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243448()
{
  int v0; // r12

  idAmbientLighting::~idAmbientLighting(this: (idAmbientLighting *)(*(_DWORD *)(v0 - 240 + 260) + 124));
}


// ========================================================================
// __unwind$243449
// EA  : 0x8295D108
// RVA : 0x0095D108
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243449()
{
  int v0; // r12

  idGlobalShadows::~idGlobalShadows(this: (idGlobalShadows *)(*(_DWORD *)(v0 - 240 + 260) + 128));
}


// ========================================================================
// __unwind$243450
// EA  : 0x8295D134
// RVA : 0x0095D134
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243450()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 132));
}


// ========================================================================
// __unwind$243451
// EA  : 0x8295D160
// RVA : 0x0095D160
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243451()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 3732));
}


// ========================================================================
// __unwind$243452
// EA  : 0x8295D18C
// RVA : 0x0095D18C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243452()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 20132));
}


// ========================================================================
// __unwind$243453
// EA  : 0x8295D1B8
// RVA : 0x0095D1B8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243453()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 36532));
}


// ========================================================================
// __unwind$243454
// EA  : 0x8295D1EC
// RVA : 0x0095D1EC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 52932));
}


// ========================================================================
// __unwind$243455
// EA  : 0x8295D220
// RVA : 0x0095D220
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243455()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 240 + 260) + 73436));
}


// ========================================================================
// __unwind$243456
// EA  : 0x8295D254
// RVA : 0x0095D254
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243456()
{
  int v0; // r12

  idStaticList<idStr,1024>::~idStaticList<idStr,1024>(this: (idStaticList<idStr,1024> *)(*(_DWORD *)(v0 - 240 + 260)
                                                                                       + 73468));
}


// ========================================================================
// __unwind$243457
// EA  : 0x8295D288
// RVA : 0x0095D288
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 106252));
}


// ========================================================================
// __unwind$243458
// EA  : 0x8295D2BC
// RVA : 0x0095D2BC
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 107344));
}


// ========================================================================
// __unwind$243459
// EA  : 0x8295D2F0
// RVA : 0x0095D2F0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 123744));
}


// ========================================================================
// __unwind$243460
// EA  : 0x8295D324
// RVA : 0x0095D324
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243460()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140152));
}


// ========================================================================
// __unwind$243461
// EA  : 0x8295D358
// RVA : 0x0095D358
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243461()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140172));
}


// ========================================================================
// __unwind$243462
// EA  : 0x8295D38C
// RVA : 0x0095D38C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243462()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140188));
}


// ========================================================================
// __unwind$243463_0
// EA  : 0x8295D3C0
// RVA : 0x0095D3C0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243463_0()
{
  int v0; // r12

  idList<debugPolygon_t,3>::~idList<debugPolygon_t,3>(this: (idList<debugPolygon_t,3> *)(*(_DWORD *)(v0 - 240 + 260)
                                                                                       + 140204));
}


// ========================================================================
// __unwind$243464_0
// EA  : 0x8295D3F4
// RVA : 0x0095D3F4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243464_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140220));
}


// ========================================================================
// __unwind$243465_0
// EA  : 0x8295D428
// RVA : 0x0095D428
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243465_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140236));
}


// ========================================================================
// __unwind$243466_0
// EA  : 0x8295D45C
// RVA : 0x0095D45C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243466_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140252));
}


// ========================================================================
// __unwind$243467_0
// EA  : 0x8295D490
// RVA : 0x0095D490
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243467_0()
{
  int v0; // r12

  idList<debugPolygon_t,3>::~idList<debugPolygon_t,3>(this: (idList<debugPolygon_t,3> *)(*(_DWORD *)(v0 - 240 + 260)
                                                                                       + 140268));
}


// ========================================================================
// __unwind$243468_0
// EA  : 0x8295D4C4
// RVA : 0x0095D4C4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243468_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 240 + 260) + 140284));
}


// ========================================================================
// __unwind$243469_0
// EA  : 0x8295D4F8
// RVA : 0x0095D4F8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_243469_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_RENDERWORLD);
}


// ========================================================================
// ??1idRenderWorldLocal@@UAA@XZ
// EA  : 0x8295D5C0
// RVA : 0x0095D5C0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::~idRenderWorldLocal(idRenderWorldLocal *this)
{
  bfx::BinaryReplayLogOut *v2; // r3
  idRenderWorldLocal *worlds; // r10
  idRenderWorldLocal **i; // r11
  int v5; // r27
  int num; // r8
  int v7; // r29
  idRenderLight **list; // r11
  idRenderLight *v9; // r30
  int v10; // r29
  int v11; // r30
  int v12; // r29
  int v13; // r30
  idRenderModel **v14; // r11
  char **p_renderViews; // r22
  int size; // r11
  char *v17; // r3
  char v18; // r11
  int v19; // r11
  int v20; // r11
  int j; // r30
  void *v22; // r29
  int numWorldAreas; // r10
  int v24; // r23
  int v25; // r24
  worldArea_t *v26; // r30
  int v27; // r25
  int v28; // r29
  idRenderModelSurface *v29; // r11
  idTriangles *geometry; // r27
  idRenderModelSurface *v31; // r4
  worldArea_t *worldAreas; // r3
  int *p_firstSurfaceInWorldModel; // r30
  idBounds *worldAreaSubspaceBounds; // r4
  idBounds *worldAreaGeometryBounds; // r4
  areaNode_t *areaNodes; // r4
  idBounds *areaNodeBounds; // r4
  int *areaNodeOcclusionIndex; // r4
  approximateLightingParms_t *approximateLightingParms; // r4
  const idRenderLightCommitted **approximateLightingLights; // r4
  idList<debugBounds_t,3> *p_latchedDebugBounds; // r30
  char **p_latchedDebugPolygons; // r30
  idList<debugText_t,3> *p_latchedDebugText; // r30
  idList<debugLine_t,3> *p_latchedDebugLines; // r30
  idList<debugBounds_t,3> *p_rb_debugBounds; // r30
  char **p_rb_debugPolygons; // r30
  idList<debugText_t,3> *p_rb_debugText; // r30
  idList<debugLine_t,3> *p_rb_debugLines; // r30
  idList<idVirtualTexture *,61> *p_megaTextures; // r30
  idStaticList<idRenderLightCommitted *,4096> *p_linkedRenderLights; // r30
  idStaticList<idRenderModelCommitted *,4096> *p_linkedRenderModels; // r30
  idStaticList<bool,1024> *p_binaryModelState; // r30
  idStaticList<idRenderLight *,4096> *p_serializedLights; // r30
  idRenderLight **v54; // r4
  idRenderModel **v55; // r4
  dynamicEnvironment_t *v56; // r4
  int v57; // r6
  int v58; // r5
  int v59; // r4
  int v60; // r3

  this->__vftable = (idRenderWorldLocal_vtbl *)&idRenderWorldLocal::`vftable';
  idRenderSystemLocal::SyncRenderThread(this: &tr, syncGPU: true);
  idVirtualTextureSystem::ClearFeedback(this: &virtualTextureSystem);
  idCVar::SetInteger(this: &r_showWorldAreas, newValue: 0, force: true);
  if ( tr.primaryWorld == this )
    tr.primaryWorld = nullptr;
  worlds = tr.worlds;
  for ( i = &tr.worlds; worlds != this; worlds = worlds->nextOnWorldList )
    i = &worlds->nextOnWorldList;
  v5 = 0;
  *i = this->nextOnWorldList;
  num = this->renderLights.num;
  this->nextOnWorldList = nullptr;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      list = this->renderLights.list;
      v9 = list[v7];
      if ( v9 != nullptr )
      {
        list[v7] = nullptr;
        idRenderLight::~idRenderLight(this: v9);
        idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->renderLights.num );
  }
  v10 = 0;
  if ( this->renderModels.num > 0 )
  {
    v11 = 0;
    do
    {
      v2 = (bfx::BinaryReplayLogOut *)this->renderModels.list[v11];
      if ( v2 != nullptr )
        v2 = (bfx::BinaryReplayLogOut *)((int (__fastcall *)(bfx::BinaryReplayLogOut *))v2->WriteAttrib_4)(a1: v2);
      ++v10;
      ++v11;
    }
    while ( v10 < this->renderModels.num );
  }
  v12 = 0;
  if ( this->renderModels.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = this->renderModels.list;
      v2 = (bfx::BinaryReplayLogOut *)v14[v13];
      if ( v2 != nullptr )
      {
        v14[v13] = nullptr;
        v2 = (bfx::BinaryReplayLogOut *)((int (__fastcall *)(bfx::BinaryReplayLogOut *, int))v2->WriteAttrib_9)(
                                          a1: v2,
                                          a2: 1);
      }
      ++v12;
      ++v13;
    }
    while ( v12 < this->renderModels.num );
  }
  p_renderViews = (char **)&this->renderViews;
  size = this->renderViews.size;
  if ( size < 2 )
  {
    if ( this->renderViews.listStatic == 0 )
    {
      if ( size > 0 || this->renderViews.granularity == 2 )
        idPhysics_StaticMulti::UpdateTime(this: v2);
      v17 = (char *)idListArrayResize<idDeclMD6 const *>(
                      voldptr: *p_renderViews,
                      oldNum: this->renderViews.size,
                      newNum: 2,
                      tag: (memTag_t)this->renderViews.memTag,
                      zeroBuffer: false);
      *p_renderViews = v17;
      if ( v17 == nullptr )
      {
        v18 = 0;
        goto LABEL_30;
      }
      v19 = this->renderViews.num;
      this->renderViews.size = 2;
      if ( v19 > 2 )
        this->renderViews.num = 2;
    }
    v18 = 1;
LABEL_30:
    if ( v18 == 0 )
      goto LABEL_34;
  }
  v20 = this->renderViews.size;
  if ( v20 > 2 )
    v20 = 2;
  this->renderViews.num = v20;
LABEL_34:
  for ( j = 0; j < 8; j += 4 )
  {
    v22 = *(void **)&(*p_renderViews)[j];
    if ( v22 != nullptr )
    {
      idRenderView::~idRenderView(this: *(idRenderView **)&(*p_renderViews)[j]);
      idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
    }
    *(_DWORD *)&(*p_renderViews)[j] = 0;
  }
  numWorldAreas = this->numWorldAreas;
  this->stampModel = nullptr;
  this->foliageEditRenderModel = nullptr;
  this->foliageRenderModel = nullptr;
  v24 = 0;
  this->detailEditRenderModel = nullptr;
  this->detailRenderModel = nullptr;
  this->transparencyRenderModel = nullptr;
  this->decalRenderModel = nullptr;
  if ( numWorldAreas <= 0 )
  {
LABEL_56:
    worldAreas = this->worldAreas;
    if ( worldAreas != nullptr )
    {
      p_firstSurfaceInWorldModel = &worldAreas[-1].firstSurfaceInWorldModel;
      `eh vector destructor iterator'(
        ptr: worldAreas,
        size: 0x48u,
        count: worldAreas[-1].firstSurfaceInWorldModel,
        pDtor: (void (__fastcall *)(void *))idSurface::~idSurface);
      idMem::Free(this: &mem, ptr: p_firstSurfaceInWorldModel, align: ALIGN_16);
      this->worldAreas = nullptr;
    }
    worldAreaSubspaceBounds = this->worldAreaSubspaceBounds;
    if ( worldAreaSubspaceBounds != nullptr )
    {
      idMem::Free(this: &mem, ptr: worldAreaSubspaceBounds, align: ALIGN_128);
      this->worldAreaSubspaceBounds = nullptr;
    }
    worldAreaGeometryBounds = this->worldAreaGeometryBounds;
    if ( worldAreaGeometryBounds != nullptr )
    {
      idMem::Free(this: &mem, ptr: worldAreaGeometryBounds, align: ALIGN_128);
      this->worldAreaGeometryBounds = nullptr;
    }
    areaNodes = this->areaNodes;
    this->numWorldAreas = 0;
    if ( areaNodes != nullptr )
    {
      idMem::Free(this: &mem, ptr: areaNodes, align: ALIGN_16);
      this->areaNodes = nullptr;
    }
    areaNodeBounds = this->areaNodeBounds;
    if ( areaNodeBounds != nullptr )
    {
      idMem::Free(this: &mem, ptr: areaNodeBounds, align: ALIGN_128);
      this->areaNodeBounds = nullptr;
    }
    areaNodeOcclusionIndex = this->areaNodeOcclusionIndex;
    if ( areaNodeOcclusionIndex != nullptr )
    {
      idMem::Free(this: &mem, ptr: areaNodeOcclusionIndex, align: ALIGN_16);
      this->areaNodeOcclusionIndex = nullptr;
    }
    this->numAreaNodes = 0;
    idStr::operator=(this: &this->mapName, text: "<FREED>");
    if ( this->transparencyJobList != nullptr )
    {
      ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
      this->transparencyJobList = nullptr;
    }
    if ( this->renderModelJobList != nullptr )
    {
      ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
      this->renderModelJobList = nullptr;
    }
    approximateLightingParms = this->approximateLightingParms;
    if ( approximateLightingParms != nullptr )
    {
      idMem::Free(this: &mem, ptr: approximateLightingParms, align: ALIGN_128);
      this->approximateLightingParms = nullptr;
    }
    approximateLightingLights = this->approximateLightingLights;
    if ( approximateLightingLights != nullptr )
    {
      idMem::Free(this: &mem, ptr: approximateLightingLights, align: ALIGN_128);
      this->approximateLightingLights = nullptr;
    }
    p_latchedDebugBounds = &this->latchedDebugBounds;
    if ( this->latchedDebugBounds.listStatic == 0 || this->latchedDebugBounds.listStatic == 2 )
    {
      if ( p_latchedDebugBounds->list != nullptr )
        idMem::Free(this: &mem, ptr: p_latchedDebugBounds->list, align: ALIGN_16);
      p_latchedDebugBounds->list = nullptr;
      this->latchedDebugBounds.size = 0;
    }
    this->latchedDebugBounds.num = 0;
    p_latchedDebugPolygons = (char **)&this->latchedDebugPolygons;
    if ( this->latchedDebugPolygons.listStatic == 0 || this->latchedDebugPolygons.listStatic == 2 )
    {
      if ( *p_latchedDebugPolygons != nullptr )
        idListArrayDelete<debugPolygon_t>(ptr: *p_latchedDebugPolygons, num: this->latchedDebugPolygons.size);
      *p_latchedDebugPolygons = nullptr;
      this->latchedDebugPolygons.size = 0;
    }
    this->latchedDebugPolygons.num = 0;
    p_latchedDebugText = &this->latchedDebugText;
    if ( this->latchedDebugText.listStatic == 0 || this->latchedDebugText.listStatic == 2 )
    {
      if ( p_latchedDebugText->list != nullptr )
        idMem::Free(this: &mem, ptr: p_latchedDebugText->list, align: ALIGN_16);
      p_latchedDebugText->list = nullptr;
      this->latchedDebugText.size = 0;
    }
    this->latchedDebugText.num = 0;
    p_latchedDebugLines = &this->latchedDebugLines;
    if ( this->latchedDebugLines.listStatic == 0 || this->latchedDebugLines.listStatic == 2 )
    {
      if ( p_latchedDebugLines->list != nullptr )
        idMem::Free(this: &mem, ptr: p_latchedDebugLines->list, align: ALIGN_16);
      p_latchedDebugLines->list = nullptr;
      this->latchedDebugLines.size = 0;
    }
    this->latchedDebugLines.num = 0;
    p_rb_debugBounds = &this->rb_debugBounds;
    if ( this->rb_debugBounds.listStatic == 0 || this->rb_debugBounds.listStatic == 2 )
    {
      if ( p_rb_debugBounds->list != nullptr )
        idMem::Free(this: &mem, ptr: p_rb_debugBounds->list, align: ALIGN_16);
      p_rb_debugBounds->list = nullptr;
      this->rb_debugBounds.size = 0;
    }
    this->rb_debugBounds.num = 0;
    p_rb_debugPolygons = (char **)&this->rb_debugPolygons;
    if ( this->rb_debugPolygons.listStatic == 0 || this->rb_debugPolygons.listStatic == 2 )
    {
      if ( *p_rb_debugPolygons != nullptr )
        idListArrayDelete<debugPolygon_t>(ptr: *p_rb_debugPolygons, num: this->rb_debugPolygons.size);
      *p_rb_debugPolygons = nullptr;
      this->rb_debugPolygons.size = 0;
    }
    this->rb_debugPolygons.num = 0;
    p_rb_debugText = &this->rb_debugText;
    if ( this->rb_debugText.listStatic == 0 || this->rb_debugText.listStatic == 2 )
    {
      if ( p_rb_debugText->list != nullptr )
        idMem::Free(this: &mem, ptr: p_rb_debugText->list, align: ALIGN_16);
      p_rb_debugText->list = nullptr;
      this->rb_debugText.size = 0;
    }
    this->rb_debugText.num = 0;
    p_rb_debugLines = &this->rb_debugLines;
    if ( this->rb_debugLines.listStatic == 0 || this->rb_debugLines.listStatic == 2 )
    {
      if ( p_rb_debugLines->list != nullptr )
        idMem::Free(this: &mem, ptr: p_rb_debugLines->list, align: ALIGN_16);
      p_rb_debugLines->list = nullptr;
      this->rb_debugLines.size = 0;
    }
    this->rb_debugLines.num = 0;
    p_megaTextures = &this->megaTextures;
    if ( this->megaTextures.listStatic == 0 || this->megaTextures.listStatic == 2 )
    {
      if ( p_megaTextures->list != nullptr )
        idMem::Free(this: &mem, ptr: p_megaTextures->list, align: ALIGN_16);
      p_megaTextures->list = nullptr;
      this->megaTextures.size = 0;
    }
    this->megaTextures.num = 0;
    p_linkedRenderLights = &this->linkedRenderLights;
    if ( this->linkedRenderLights.listStatic == 0 || this->linkedRenderLights.listStatic == 2 )
    {
      if ( p_linkedRenderLights->list != nullptr )
        idMem::Free(this: &mem, ptr: p_linkedRenderLights->list, align: ALIGN_16);
      p_linkedRenderLights->list = nullptr;
      this->linkedRenderLights.size = 0;
    }
    this->linkedRenderLights.num = 0;
    p_linkedRenderModels = &this->linkedRenderModels;
    if ( this->linkedRenderModels.listStatic == 0 || this->linkedRenderModels.listStatic == 2 )
    {
      if ( p_linkedRenderModels->list != nullptr )
        idMem::Free(this: &mem, ptr: p_linkedRenderModels->list, align: ALIGN_16);
      p_linkedRenderModels->list = nullptr;
      this->linkedRenderModels.size = 0;
    }
    this->linkedRenderModels.num = 0;
    p_binaryModelState = &this->binaryModelState;
    if ( this->binaryModelState.listStatic == 0 || this->binaryModelState.listStatic == 2 )
    {
      if ( p_binaryModelState->list != nullptr )
        idMem::Free(this: &mem, ptr: p_binaryModelState->list, align: ALIGN_16);
      p_binaryModelState->list = nullptr;
      this->binaryModelState.size = 0;
    }
    this->binaryModelState.num = 0;
    idStaticList<idStr,1024>::~idStaticList<idStr,1024>(this: &this->binaryModelNames);
    idHashIndex::Free(this: &this->binaryModelHash);
    if ( this->renderViews.listStatic == 0 || this->renderViews.listStatic == 2 )
    {
      if ( *p_renderViews != nullptr )
        idMem::Free(this: &mem, ptr: *p_renderViews, align: ALIGN_16);
      *p_renderViews = nullptr;
      this->renderViews.size = 0;
    }
    this->renderViews.num = 0;
    p_serializedLights = &this->serializedLights;
    if ( this->serializedLights.listStatic == 0 || this->serializedLights.listStatic == 2 )
    {
      if ( p_serializedLights->list != nullptr )
        idMem::Free(this: &mem, ptr: p_serializedLights->list, align: ALIGN_16);
      p_serializedLights->list = nullptr;
      this->serializedLights.size = 0;
    }
    this->serializedLights.num = 0;
    if ( this->renderLights.listStatic == 0 || this->renderLights.listStatic == 2 )
    {
      v54 = this->renderLights.list;
      if ( v54 != nullptr )
        idMem::Free(this: &mem, ptr: v54, align: ALIGN_16);
      this->renderLights.list = nullptr;
      this->renderLights.size = 0;
    }
    this->renderLights.num = 0;
    if ( this->renderModels.listStatic == 0 || this->renderModels.listStatic == 2 )
    {
      v55 = this->renderModels.list;
      if ( v55 != nullptr )
        idMem::Free(this: &mem, ptr: v55, align: ALIGN_16);
      this->renderModels.list = nullptr;
      this->renderModels.size = 0;
    }
    this->renderModels.num = 0;
    if ( this->dynamicEnvironments.listStatic == 0 || this->dynamicEnvironments.listStatic == 2 )
    {
      v56 = this->dynamicEnvironments.list;
      if ( v56 != nullptr )
        idMem::Free(this: &mem, ptr: v56, align: ALIGN_16);
      this->dynamicEnvironments.list = nullptr;
      this->dynamicEnvironments.size = 0;
    }
    this->dynamicEnvironments.num = 0;
    idGlobalShadows::~idGlobalShadows(this: &this->globalShadows);
    idAmbientLighting::~idAmbientLighting(this: &this->ambientLighting);
    idIndexBuffer::~idIndexBuffer(this: &this->worldIndexBuffer);
    idVertexBuffer::~idVertexBuffer(this: &this->worldVertexBuffer);
    idStr::FreeData(this: &this->mapName);
    this->__vftable = (idRenderWorldLocal_vtbl *)&idRenderWorld::`vftable';
  }
  else
  {
    v25 = 0;
    while ( 1 )
    {
      v26 = &this->worldAreas[v25];
      if ( v26->approximatedLightRefs.num != 0 )
        break;
      if ( v26->drawLightRefs.num != 0 )
        goto _LN569;
      if ( v26->modelRefs.num != 0 )
        goto _LN570;
      v27 = 0;
      if ( v26->worldSurfaces.num > 0 )
      {
        v28 = 0;
        do
        {
          v29 = &v26->worldSurfaces.list[v28];
          if ( !v29->geometryIsReference )
          {
            geometry = v29->geometry;
            if ( geometry != nullptr )
            {
              idTriangles::~idTriangles(this: v29->geometry);
              idMem::Free(this: &mem, ptr: geometry, align: ALIGN_16);
            }
            v26->worldSurfaces.list[v28].geometry = nullptr;
          }
          ++v27;
          ++v28;
        }
        while ( v27 < v26->worldSurfaces.num );
      }
      if ( v26->worldSurfaces.listStatic == 0 || v26->worldSurfaces.listStatic == 2 )
      {
        v31 = v26->worldSurfaces.list;
        if ( v31 != nullptr )
          idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
        v26->worldSurfaces.list = nullptr;
        v26->worldSurfaces.size = 0;
      }
      ++v24;
      v26->worldSurfaces.num = 0;
      ++v25;
      if ( v24 >= this->numWorldAreas )
        goto LABEL_56;
    }
    idLib::Error(fmt: "FreeWorld: unexpected remaining approximatedLightRefs");
_LN569:
    idLib::Error(fmt: "FreeWorld: unexpected remaining drawLightRefs");
_LN570:
    idLib::Error(fmt: "FreeWorld: unexpected remaining modelRefs");
    _LN571(a1: v60, a2: v59, a3: v58, a4: v57);
  }
}


// ========================================================================
// $LN571
// EA  : 0x8295DFE0
// RVA : 0x0095DFE0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _LN571()
{
  int v0; // r12

  idRenderWorld::~idRenderWorld(this: *(idRenderWorld **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$245173
// EA  : 0x8295E008
// RVA : 0x0095E008
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245173()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 4));
}


// ========================================================================
// __unwind$245174
// EA  : 0x8295E034
// RVA : 0x0095E034
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245174()
{
  int v0; // r12

  idVertexBuffer::~idVertexBuffer(this: (idVertexBuffer *)(*(_DWORD *)(v0 - 192 + 212) + 76));
}


// ========================================================================
// __unwind$245175
// EA  : 0x8295E060
// RVA : 0x0095E060
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245175()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 192 + 212) + 92));
}


// ========================================================================
// __unwind$245176
// EA  : 0x8295E08C
// RVA : 0x0095E08C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245176()
{
  int v0; // r12

  idAmbientLighting::~idAmbientLighting(this: (idAmbientLighting *)(*(_DWORD *)(v0 - 192 + 212) + 124));
}


// ========================================================================
// __unwind$245177
// EA  : 0x8295E0B8
// RVA : 0x0095E0B8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245177()
{
  int v0; // r12

  idGlobalShadows::~idGlobalShadows(this: (idGlobalShadows *)(*(_DWORD *)(v0 - 192 + 212) + 128));
}


// ========================================================================
// __unwind$245178
// EA  : 0x8295E0E4
// RVA : 0x0095E0E4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245178()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 132));
}


// ========================================================================
// __unwind$245179
// EA  : 0x8295E110
// RVA : 0x0095E110
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245179()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 3732));
}


// ========================================================================
// __unwind$245180
// EA  : 0x8295E13C
// RVA : 0x0095E13C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245180()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 20132));
}


// ========================================================================
// __unwind$245181
// EA  : 0x8295E168
// RVA : 0x0095E168
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245181()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 36532));
}


// ========================================================================
// __unwind$245182
// EA  : 0x8295E19C
// RVA : 0x0095E19C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245182()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 52932));
}


// ========================================================================
// __unwind$245183
// EA  : 0x8295E1D0
// RVA : 0x0095E1D0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245183()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 192 + 212) + 73436));
}


// ========================================================================
// __unwind$245184
// EA  : 0x8295E204
// RVA : 0x0095E204
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245184()
{
  int v0; // r12

  idStaticList<idStr,1024>::~idStaticList<idStr,1024>(this: (idStaticList<idStr,1024> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                       + 73468));
}


// ========================================================================
// __unwind$245185
// EA  : 0x8295E238
// RVA : 0x0095E238
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245185()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 106252));
}


// ========================================================================
// __unwind$245186
// EA  : 0x8295E26C
// RVA : 0x0095E26C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245186()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 107344));
}


// ========================================================================
// __unwind$245187
// EA  : 0x8295E2A0
// RVA : 0x0095E2A0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245187()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 123744));
}


// ========================================================================
// __unwind$245188
// EA  : 0x8295E2D4
// RVA : 0x0095E2D4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245188()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140152));
}


// ========================================================================
// __unwind$245189
// EA  : 0x8295E308
// RVA : 0x0095E308
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245189()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140172));
}


// ========================================================================
// __unwind$245190
// EA  : 0x8295E33C
// RVA : 0x0095E33C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245190()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140188));
}


// ========================================================================
// __unwind$245191
// EA  : 0x8295E370
// RVA : 0x0095E370
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245191()
{
  int v0; // r12

  idList<debugPolygon_t,3>::~idList<debugPolygon_t,3>(this: (idList<debugPolygon_t,3> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                       + 140204));
}


// ========================================================================
// __unwind$245192
// EA  : 0x8295E3A4
// RVA : 0x0095E3A4
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245192()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140220));
}


// ========================================================================
// __unwind$245193
// EA  : 0x8295E3D8
// RVA : 0x0095E3D8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245193()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140236));
}


// ========================================================================
// __unwind$245194
// EA  : 0x8295E40C
// RVA : 0x0095E40C
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245194()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140252));
}


// ========================================================================
// __unwind$245195
// EA  : 0x8295E440
// RVA : 0x0095E440
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245195()
{
  int v0; // r12

  idList<debugPolygon_t,3>::~idList<debugPolygon_t,3>(this: (idList<debugPolygon_t,3> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                       + 140268));
}


// ========================================================================
// __unwind$245196
// EA  : 0x8295E474
// RVA : 0x0095E474
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void _unwind_245196()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 140284));
}


// ========================================================================
// `dynamic initializer for 'r_useDynamicLightingJobs''
// EA  : 0x8335DA40
// RVA : 0x0135DA40
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useDynamicLightingJobs__()
{
  idCVar::idCVar(
    this: &r_useDynamicLightingJobs,
    name: "r_useDynamicLightingJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useDynamicLightingJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_skipDynamicLighting''
// EA  : 0x8335DAA8
// RVA : 0x0135DAA8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDynamicLighting__()
{
  idCVar::idCVar(
    this: &r_skipDynamicLighting,
    name: "r_skipDynamicLighting",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDynamicLighting__);
}


// ========================================================================
// `dynamic initializer for 'r_showDynamicLighting''
// EA  : 0x8335DB00
// RVA : 0x0135DB00
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDynamicLighting__()
{
  idCVar::idCVar(
    this: &r_showDynamicLighting,
    name: "r_showDynamicLighting",
    value: "0",
    flags: 2,
    description: "Draw lines to lights for each dynamic model, 3 = draw bounds of problem models and lights affecting them",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDynamicLighting__);
}


// ========================================================================
// `dynamic initializer for 'r_dynamicLightingScale''
// EA  : 0x8335DB58
// RVA : 0x0135DB58
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dynamicLightingScale__()
{
  idCVar::idCVar(
    this: &r_dynamicLightingScale,
    name: "r_dynamicLightingScale",
    value: "1",
    flags: 4,
    description: "Scales all approximated lighting on dynamic models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dynamicLightingScale__);
}


// ========================================================================
// `dynamic initializer for 'r_directChannelScale''
// EA  : 0x8335DBB0
// RVA : 0x0135DBB0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_directChannelScale__()
{
  idCVar::idCVar(
    this: &r_directChannelScale,
    name: "r_directChannelScale",
    value: "1",
    flags: 4,
    description: "Scales the direct light contribution",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_directChannelScale__);
}


// ========================================================================
// `dynamic initializer for 'r_ambientChannelScale''
// EA  : 0x8335DC08
// RVA : 0x0135DC08
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_ambientChannelScale__()
{
  idCVar::idCVar(
    this: &r_ambientChannelScale,
    name: "r_ambientChannelScale",
    value: "1",
    flags: 4,
    description: "Scales the ambient light contribution",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_ambientChannelScale__);
}


// ========================================================================
// `dynamic initializer for 'r_primeLightScale''
// EA  : 0x8335DC60
// RVA : 0x0135DC60
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_primeLightScale__()
{
  idCVar::idCVar(
    this: &r_primeLightScale,
    name: "r_primeLightScale",
    value: "1",
    flags: 4,
    description: "Scales prime light contribution",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_primeLightScale__);
}


// ========================================================================
// `dynamic initializer for 'r_dimShadowHeightTweak''
// EA  : 0x8335DCB8
// RVA : 0x0135DCB8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dimShadowHeightTweak__()
{
  idCVar::idCVar(
    this: &r_dimShadowHeightTweak,
    name: "r_dimShadowHeightTweak",
    value: "0.9",
    flags: 4,
    description: "This value is added to the true combined light z value to prevent long stretched shadows.  Set to 0 for true shadows.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dimShadowHeightTweak__);
}


// ========================================================================
// `dynamic initializer for 'r_highlightSynchronized''
// EA  : 0x8335DD10
// RVA : 0x0135DD10
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_highlightSynchronized__()
{
  idCVar::idCVar(
    this: &r_highlightSynchronized,
    name: "r_highlightSynchronized",
    value: "0",
    flags: 1,
    description: "All highlights in phase",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_highlightSynchronized__);
}


// ========================================================================
// `dynamic initializer for 'r_highlightColor''
// EA  : 0x8335DD68
// RVA : 0x0135DD68
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_highlightColor__()
{
  idCVar::idCVar(
    this: &r_highlightColor,
    name: "r_highlightColor",
    value: &byte_8200D768,
    flags: 0,
    description: "default highlight color on 'useables'",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_highlightColor__);
}


// ========================================================================
// `dynamic initializer for 'unlinkParticleModels_v''
// EA  : 0x8335DDC0
// RVA : 0x0135DDC0
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__unlinkParticleModels_v__()
{
  return idCommandLink::idCommandLink(
           this: &unlinkParticleModels_v,
           cmdName: "unlinkParticleModels",
           function: unlinkParticleModels_f,
           description: "remove all particle render models from the world",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ListRenderModelsGrouped_v''
// EA  : 0x8335DDE8
// RVA : 0x0135DDE8
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ListRenderModelsGrouped_v__()
{
  return idCommandLink::idCommandLink(
           this: &ListRenderModelsGrouped_v,
           cmdName: "ListRenderModelsGrouped",
           function: ListRenderModelsGrouped_f,
           description: "lists the renderModels grouped by Model name and sorted by total number",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'countModelsPerNode_v''
// EA  : 0x8335DE10
// RVA : 0x0135DE10
// PDB : w:\tech5\engine\renderer\renderworld.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__countModelsPerNode_v__()
{
  return idCommandLink::idCommandLink(
           this: &countModelsPerNode_v,
           cmdName: "countModelsPerNode",
           function: countModelsPerNode_f,
           description: &byte_8200D768,
           argCompletion: nullptr);
}

