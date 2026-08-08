
// ========================================================================
// ?SetColor@idRenderModelInfo@@QAAXABVidColor@@@Z
// EA  : 0x82BB60D8
// RVA : 0x00BB60D8
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetColor(idRenderModelInfo *this, const idColor *inColor)
{
  this->color = *inColor;
}


// ========================================================================
// ?GetColor@idRenderModelInfo@@QBAXAAVidColor@@@Z
// EA  : 0x82BB6100
// RVA : 0x00BB6100
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::GetColor(idRenderModelInfo *this, idColor *out)
{
  *out = this->color;
}


// ========================================================================
// ?SetNoShadows@idRenderModelInfo@@QAAX_N@Z
// EA  : 0x82BB6128
// RVA : 0x00BB6128
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetNoShadows(idRenderModelInfo *this, bool set)
{
  *((_BYTE *)this + 4) = (32 * set) & 0x20 | *((_BYTE *)this + 4) & 0xDF;
}


// ========================================================================
// ?FreeRenderModel@idRenderModelInfo@@QAAXXZ
// EA  : 0x82BB6140
// RVA : 0x00BB6140
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::FreeRenderModel(idRenderModelInfo *this)
{
  idRenderModel *model; // r3

  model = this->model;
  if ( model != nullptr && !this->ownedByPresentable )
  {
    if ( (int)model > 10000 )
    {
      model->unlinked = true;
      model->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: model);
    }
    this->model = nullptr;
  }
}


// ========================================================================
// ?InitRenderModel@idRenderModelInfo@@QAAXABVidVec3@@ABVidMat3@@_NPBD3@Z
// EA  : 0x82BB61A8
// RVA : 0x00BB61A8
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::InitRenderModel(
        idRenderModelInfo *this,
        const idVec3 *spawnPosition,
        const idMat3 *spawnOrientation,
        bool enableStaticSpecular,
        const char *name,
        const char *className)
{
  int v12; // r29
  const char *v13; // r3
  int v14; // r3
  int (*GetName)(void); // ctr
  int v16; // r3
  int v17; // r3
  idRenderModel *model; // r3
  idRenderModel *v19; // r3
  idRenderModel *v20; // r11
  idRenderModel *v21; // r11
  const idMaterial *parmBlock; // r11
  const idParmBlock *p_parmBlock; // r27
  idStaticParmBlock<32> *v24; // r3
  int i; // r28
  int v26; // r10
  int v27; // r9
  int v28; // r8
  int v29; // r7
  double a; // fp11
  double r; // fp0
  double g; // fp13
  idRenderModel *v33; // r3
  __int64 v34; // [sp+8h] [-F8h]
  __int64 v35; // [sp+10h] [-F0h]
  __int64 v36; // [sp+18h] [-E8h]
  __int64 v37; // [sp+20h] [-E0h]
  __int64 v38; // [sp+28h] [-D8h]
  idVec4 v39; // [sp+60h] [-A0h] BYREF
  parmValue_t v40; // [sp+70h] [-90h] BYREF
  idStr v41[4]; // [sp+80h] [-80h] BYREF

  if ( this->model != nullptr )
  {
    v12 = 0;
    if ( (*((_BYTE *)this + 5) & 0x10) != 0 && clientGame->renderWorld->IsComboMap(this: clientGame->renderWorld) )
    {
      v41[0].len = 0;
      v41[0].baseBuffer[0] = 0;
      v41[0].allocedAndFlag = 20;
      v41[0].data = v41[0].baseBuffer;
      if ( idStr::Find(searchIn: this->model->name.str, searchFor: ".md6", casesensitive: true, start: 0, end: -1) == -1 )
      {
        v14 = idStr::Find(searchIn: this->model->name.str, searchFor: ".break", casesensitive: true, start: 0, end: -1);
        GetName = (int (*)(void))clientGame->renderWorld->GetName;
        if ( v14 == -1 )
        {
          v17 = GetName();
          idStr::Format(this: v41, fmt: "%s/_combo/megamodel_%s.bmodel", v17, name);
        }
        else
        {
          v16 = GetName();
          idStr::Format(this: v41, fmt: "%s/megabreakable_%s.breakabledecl", v16, name);
        }
      }
      else
      {
        v13 = clientGame->renderWorld->GetName(this: clientGame->renderWorld);
        idStr::Format(this: v41, fmt: "%s/megamodel_%s.decl", v13, name);
      }
      if ( idStr::Icmp(s1: v41[0].data, s2: this->model->name.str) != 0 )
      {
        model = this->model;
        model->unlinked = true;
        model->deleteOnSync = true;
        idRenderModel::CommitThisFrame(this: model);
        v19 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: v41[0].data, a3: 1, a4: -1);
        this->model = v19;
        if ( v19 == nullptr )
        {
          idLib::Warning(fmt: "Could not load mega model ( %s )", v41[0].data);
          idStr::FreeData(this: v41);
          return;
        }
      }
      idStr::FreeData(this: v41);
    }
    v20 = this->model;
    if ( !this->model->deferredPositionInitialized || !this->model->useDeferredPosition )
    {
      v20->g.origin.x = spawnPosition->x;
      v20->g.origin.y = spawnPosition->y;
      v20->g.origin.z = spawnPosition->z;
    }
    v20->deferredOrigin.x = spawnPosition->x;
    v20->deferredOrigin.y = spawnPosition->y;
    v20->deferredOrigin.z = spawnPosition->z;
    idRenderModel::SetAxis(this: this->model, a: spawnOrientation);
    v21 = this->model;
    v21->g.scale.x = this->scale.x;
    v21->g.scale.y = this->scale.y;
    v21->g.scale.z = this->scale.z;
    *((_BYTE *)&this->model->g + 107) = (*((_BYTE *)this + 4) >> 2) & 0x10 | *((_BYTE *)&this->model->g + 107) & 0xEF;
    *((_BYTE *)&this->model->g + 105) = (4 * *((_BYTE *)this + 4)) & 0x80 | *((_BYTE *)&this->model->g + 105) & 0x7F;
    *((_BYTE *)&this->model->g + 105) = (32 * *((_BYTE *)this + 4)) & 0x20 | *((_BYTE *)&this->model->g + 105) & 0xDF;
    *((_BYTE *)&this->model->g + 104) = (16 * *((_BYTE *)this + 4)) & 0x40 | *((_BYTE *)&this->model->g + 104) & 0xBF;
    *((_BYTE *)&this->model->g + 105) = (8 * *((_BYTE *)this + 4)) & 0x10 | *((_BYTE *)&this->model->g + 105) & 0xEF;
    *((_BYTE *)&this->model->g + 104) = (16 * *((_BYTE *)this + 4)) & 0x80 | *((_BYTE *)&this->model->g + 104) & 0x7F;
    *((_BYTE *)&this->model->g + 106) = (*((char *)this + 5) < 0) | *((_BYTE *)&this->model->g + 106) & 0xFE;
    *((_BYTE *)&this->model->g + 107) = (2 * *((_BYTE *)this + 5)) & 0x80 | *((_BYTE *)&this->model->g + 107) & 0x7F;
    *((_BYTE *)&this->model->g + 105) = (*((_BYTE *)this + 5) >> 1) & 8 | *((_BYTE *)&this->model->g + 105) & 0xF7;
    this->model->g.maxTexelDensity = this->maxTexelDensity;
    this->model->g.customMaterial = this->customMaterial;
    this->model->g.dimShadowClipZ = this->dimShadowClipZ;
    this->model->g.maxVisibleRange = this->maxVisibleRange;
    this->model->g.fadeVisibilityOver = this->fadeVisibilityOver;
    *((_BYTE *)&this->model->g + 108) = this->traceGroup;
    this->model->g.radiosityScale = this->radiosityScale;
    *((_BYTE *)&this->model->g + 107) = (4 * enableStaticSpecular) & 4 | *((_BYTE *)&this->model->g + 107) & 0xFB;
    *((_BYTE *)&this->model->g + 116) = (8 * *((_BYTE *)this + 5)) & 0x40 | *((_BYTE *)&this->model->g + 116) & 0xBF;
    this->model->g.staticReflectionStrength = this->staticReflectionStrength;
    if ( (*((_BYTE *)this + 4) & 8) != 0 )
    {
      this->model->g.castDimShadows = DIMSHADOW_HIGH_QUALITY;
    }
    else if ( (*((_BYTE *)this + 4) & 0x10) != 0 )
    {
      this->model->g.castDimShadows = DIMSHADOW_ON;
    }
    parmBlock = this->parmBlock;
    if ( parmBlock != nullptr )
    {
      p_parmBlock = &parmBlock->parmBlock;
      v24 = idRenderModel::GetParmBlock(this: this->model);
      idParmBlock::CopyFrom(this: v24, other: p_parmBlock);
    }
    for ( i = 0; i < this->renderParms.num; ++v12 )
    {
      idDeclRenderParm::ParseStringToValue(
        this: this->renderParms.list[v12].parm,
        str: this->renderParms.list[v12].value.data,
        value: &v40);
      idRenderModel::SetParm(
        this: this->model,
        parm: (const idDeclRenderParm *)v40.image,
        parmValue: *(__int64 *)&v40.swizzle[2],
        a4: v29,
        a5: v28,
        a6: v27,
        a7: v26,
        a8: v34,
        a9: v35,
        a10: v36,
        a11: v37,
        a12: v38);
      ++i;
    }
    a = this->color.a;
    r = this->color.r;
    g = this->color.g;
    v33 = this->model;
    v39.z = this->color.b;
    v39.w = a;
    v39.x = r;
    v39.y = g;
    idRenderModel::SetParm(this: v33, parm: rp->Color, v4: &v39);
    if ( this->model != nullptr )
      this->model->debugName = className;
  }
}


// ========================================================================
// __unwind$487826_0
// EA  : 0x82BB6628
// RVA : 0x00BB6628
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void _unwind_487826_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?SetModel@idRenderModelInfo@@QAAXPAVidRenderModel@@PBD@Z
// EA  : 0x82BB6650
// RVA : 0x00BB6650
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetModel(idRenderModelInfo *this, idRenderModel *inModel, const char *className)
{
  idRenderModel *model; // r3
  int customSkin; // r30
  const idMaterial *customMaterial; // r28

  model = this->model;
  if ( model != nullptr )
  {
    customSkin = model->g.customSkin;
    customMaterial = model->g.customMaterial;
  }
  else
  {
    customSkin = 0;
    customMaterial = nullptr;
  }
  if ( model != nullptr && !this->ownedByPresentable )
  {
    if ( (int)model > 10000 )
    {
      model->unlinked = true;
      model->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: model);
    }
    this->model = nullptr;
  }
  this->model = inModel;
  if ( inModel != nullptr )
  {
    idRenderModel::CommitThisFrame(this: inModel);
    if ( customSkin != 0 )
      this->model->g.customSkin = customSkin;
    if ( customMaterial != nullptr )
      this->model->g.customMaterial = customMaterial;
    if ( this->model != nullptr )
      this->model->debugName = className;
  }
}


// ========================================================================
// ?SetColor@idRenderModelInfo@@QAAXMMMM@Z
// EA  : 0x82BB6708
// RVA : 0x00BB6708
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetColor(
        idRenderModelInfo *this,
        double red,
        double green,
        double blue,
        double alpha)
{
  idColor back_chain; // 0:^0.16

  back_chain.r = red;
  back_chain.g = green;
  back_chain.b = blue;
  back_chain.a = alpha;
  this->color = back_chain;
}


// ========================================================================
// ?SetColor@idRenderModelInfo@@QAAXMMM@Z
// EA  : 0x82BB6748
// RVA : 0x00BB6748
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetColor(idRenderModelInfo *this, double red, double green, double blue)
{
  float back_chain; // [sp+0h] [-10h]
  float v5; // [sp+4h] [-Ch]
  float v6; // [sp+8h] [-8h]

  back_chain = red;
  v5 = green;
  v6 = blue;
  this->color.b = v6;
  this->color.g = v5;
  this->color.r = back_chain;
  this->color.a = 1.0;
}


// ========================================================================
// ?SetColor@idRenderModelInfo@@QAAXABVidVec3@@@Z
// EA  : 0x82BB6790
// RVA : 0x00BB6790
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetColor(idRenderModelInfo *this, const idVec3 *inColor)
{
  float x; // r6
  float y; // [sp+4h] [-Ch]

  y = inColor->y;
  x = inColor->x;
  this->color.b = inColor->z;
  this->color.g = y;
  this->color.r = x;
  this->color.a = 1.0;
}


// ========================================================================
// ?SetColor@idRenderModelInfo@@QAAXABVidVec4@@@Z
// EA  : 0x82BB67E0
// RVA : 0x00BB67E0
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetColor(idRenderModelInfo *this, const idVec4 *inColor)
{
  float w; // r8
  float x; // r7
  float y; // [sp+4h] [-Ch]

  y = inColor->y;
  w = inColor->w;
  x = inColor->x;
  this->color.b = inColor->z;
  this->color.g = y;
  this->color.r = x;
  this->color.a = w;
}


// ========================================================================
// ?GetColor@idRenderModelInfo@@QBAXAAVidVec3@@@Z
// EA  : 0x82BB6830
// RVA : 0x00BB6830
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::GetColor(idRenderModelInfo *this, idVec3 *out)
{
  out->x = this->color.r;
  out->y = this->color.g;
  out->z = this->color.b;
}


// ========================================================================
// ?GetColor@idRenderModelInfo@@QBAXAAVidVec4@@@Z
// EA  : 0x82BB6850
// RVA : 0x00BB6850
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::GetColor(idRenderModelInfo *this, idVec4 *out)
{
  double g; // fp13
  double b; // fp12
  double a; // fp11

  g = this->color.g;
  b = this->color.b;
  a = this->color.a;
  out->x = this->color.r;
  out->y = g;
  out->z = b;
  out->w = a;
}


// ========================================================================
// ?GetScale@idRenderModelInfo@@QBAXAAVidVec3@@@Z
// EA  : 0x82BB6878
// RVA : 0x00BB6878
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::GetScale(idRenderModelInfo *this, idVec3 *out)
{
  *out = this->scale;
}


// ========================================================================
// ?SetScale@idRenderModelInfo@@QAAXABVidVec3@@@Z
// EA  : 0x82BB6898
// RVA : 0x00BB6898
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetScale(idRenderModelInfo *this, const idVec3 *inScale)
{
  this->scale = *inScale;
}


// ========================================================================
// ?GetRenderModelMaterial@idRenderModelInfo@@QBAPBVidMaterial@@XZ
// EA  : 0x82BB68B8
// RVA : 0x00BB68B8
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

const idMaterial *__fastcall idRenderModelInfo::GetRenderModelMaterial(idRenderModelInfo *this)
{
  idRenderModel *model; // r11
  const idMaterial *result; // r3
  int num; // r10
  int v5; // r30
  int i; // r31
  int Integer; // r3

  model = this->model;
  if ( this->model == nullptr )
    return nullptr;
  result = model->g.customMaterial;
  if ( result != nullptr )
    return result;
  num = model->surfaces.num;
  if ( num == 0 )
    return nullptr;
  v5 = 0;
  if ( num <= 0 )
    return model->surfaces.list->material;
  for ( i = 0; ; ++i )
  {
    Integer = idParmBlock::GetInteger(this: &model->surfaces.list[i].material->parmBlock, parm: rp->surfaceType);
    model = this->model;
    if ( Integer != 0 )
      break;
    if ( ++v5 >= model->surfaces.num )
      return model->surfaces.list->material;
  }
  return model->surfaces.list[v5].material;
}


// ========================================================================
// ?SetModelByName@idRenderModelInfo@@QAAXPBD0@Z
// EA  : 0x82BB6968
// RVA : 0x00BB6968
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::SetModelByName(
        idRenderModelInfo *this,
        const char *modelName,
        const char *className)
{
  idRenderModel *v5; // r3

  v5 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: modelName, a3: 1, a4: -1);
  idRenderModelInfo::SetModel(this, inModel: v5, className);
}


// ========================================================================
// ?CleanRenderParms@idRenderModelInfo@@QAAXXZ
// EA  : 0x82BB6A90
// RVA : 0x00BB6A90
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

void __fastcall idRenderModelInfo::CleanRenderParms(idRenderModelInfo *this)
{
  int v1; // r31
  idList<idRenderParm,5> *p_renderParms; // r30
  int v3; // r29
  idAutoRenderParms *v4; // r10
  const idDeclRenderParm *parm; // r11

  v1 = this->renderParms.num - 1;
  if ( v1 >= 0 )
  {
    p_renderParms = &this->renderParms;
    v3 = v1;
    v4 = rp;
    do
    {
      parm = p_renderParms->list[v3].parm;
      if ( parm == v4->Color || parm == v4->lightColor )
      {
        idList<idRenderParm,5>::RemoveIndex(this: p_renderParms, index: v1);
        v4 = rp;
      }
      --v1;
      --v3;
    }
    while ( v1 >= 0 );
  }
}


// ========================================================================
// ??0idRenderModelInfo@@QAA@PAV0@@Z
// EA  : 0x82BB6B08
// RVA : 0x00BB6B08
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.cpp
// ========================================================================

idRenderModelInfo *__fastcall idRenderModelInfo::idRenderModelInfo(
        idRenderModelInfo *this,
        idRenderModelInfo *nextModel)
{
  char v2; // r5

  this->color.a = -1.0;
  this->color.b = -1.0;
  this->color.g = -1.0;
  this->color.r = -1.0;
  this->renderParms.granularity = 0;
  this->renderParms.memTag = 5;
  this->renderParms.listStatic = 0;
  this->renderParms.list = nullptr;
  this->renderParms.size = 0;
  this->renderParms.num = 0;
  this->editorModel.data = this->editorModel.baseBuffer;
  this->editorModel.allocedAndFlag = 20;
  this->editorModel.len = 0;
  this->editorModel.baseBuffer[0] = 0;
  this->maxTexelDensity = 0.0;
  *((_BYTE *)this + 5) &= 0xFu;
  this->maxVisibleRange = 0.0;
  this->fadeVisibilityOver = 400.0;
  this->next = nextModel;
  this->dimShadowClipZ = 0.0;
  this->model = nullptr;
  *((_BYTE *)this + 4) = 0;
  this->customMaterial = nullptr;
  this->scale.x = 1.0;
  this->scale.y = 1.0;
  this->scale.z = 1.0;
  this->color.r = 1.0;
  this->color.g = 1.0;
  this->color.b = 1.0;
  this->color.a = 1.0;
  v2 = *((_BYTE *)this + 5);
  this->radiosityScale = 1.0;
  this->staticReflectionStrength = 1.0;
  this->traceGroup = 0;
  *((_BYTE *)this + 5) = v2 & 0xF7;
  this->ownedByPresentable = false;
  this->parmBlock = nullptr;
  return this;
}

