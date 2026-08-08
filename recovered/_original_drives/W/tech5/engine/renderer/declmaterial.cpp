
// ========================================================================
// ??0idContents@@QAA@XZ
// EA  : 0x828A9D70
// RVA : 0x008A9D70
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

idContents *__fastcall idContents::idContents(idContents *this)
{
  char v1; // r10

  v1 = *((_BYTE *)this + 3);
  *(_BYTE *)this = 0;
  *((_BYTE *)this + 1) = 0;
  *((_WORD *)this + 1) = v1 & 0x7F;
  return this;
}


// ========================================================================
// ?ToFlags@idContents@@QBAHXZ
// EA  : 0x828A9D90
// RVA : 0x008A9D90
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idContents::ToFlags(idContents *this)
{
  int v1; // r11
  char v2; // r10
  int result; // r3

  v1 = (*(_BYTE *)this & 0x80) != 0;
  if ( (*(_BYTE *)this & 0x40) != 0 )
    v1 |= 2u;
  if ( (*(_BYTE *)this & 0x20) != 0 )
    v1 |= 4u;
  if ( (*(_BYTE *)this & 0x10) != 0 )
    v1 |= 8u;
  if ( (*(_BYTE *)this & 4) != 0 )
    v1 |= 0x20u;
  if ( (*(_BYTE *)this & 8) != 0 )
    v1 |= 0x10u;
  if ( (*(_BYTE *)this & 2) != 0 )
    v1 |= 0x40u;
  if ( (*(_BYTE *)this & 1) != 0 )
    v1 |= 0x80u;
  if ( (*((_BYTE *)this + 1) & 0x80) != 0 )
    v1 |= 0x100u;
  if ( (*((_BYTE *)this + 1) & 0x40) != 0 )
    v1 |= 0x200u;
  if ( (*((_BYTE *)this + 1) & 0x20) != 0 )
    v1 |= 0x400u;
  if ( (*((_BYTE *)this + 1) & 0x10) != 0 )
    v1 |= 0x800u;
  if ( (*((_BYTE *)this + 1) & 8) != 0 )
    v1 |= 0x1000u;
  if ( (*((_BYTE *)this + 1) & 4) != 0 )
    v1 |= 0x4000u;
  if ( (*((_BYTE *)this + 1) & 2) != 0 )
    v1 |= 0x8000u;
  if ( (*((_BYTE *)this + 1) & 1) != 0 )
    v1 |= 0x10000u;
  if ( (*((_BYTE *)this + 2) & 0x80) != 0 )
    v1 |= 0x20000u;
  if ( (*((_BYTE *)this + 2) & 0x20) != 0 )
    v1 |= 0x80000u;
  if ( (*((_BYTE *)this + 2) & 0x10) != 0 )
    v1 |= 0x100000u;
  if ( (*((_BYTE *)this + 2) & 0x40) != 0 )
    v1 |= 0x40000u;
  if ( (*((_BYTE *)this + 2) & 8) != 0 )
    v1 |= 0x200000u;
  if ( (*((_BYTE *)this + 2) & 4) != 0 )
    v1 |= 0x400000u;
  if ( (*((_BYTE *)this + 2) & 2) != 0 )
    v1 |= 0x1000000u;
  if ( (*((_BYTE *)this + 2) & 1) != 0 )
    v1 |= 0x800000u;
  v2 = *((_BYTE *)this + 3);
  result = v1 | 0x40000000;
  if ( (v2 & 0x80) == 0 )
    return v1;
  return result;
}


// ========================================================================
// ?FromFlags@idContents@@QAAXH@Z
// EA  : 0x828A9F40
// RVA : 0x008A9F40
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idContents::FromFlags(idContents *this, unsigned int flags)
{
  char v2; // r10

  v2 = *((_BYTE *)this + 3);
  *((_BYTE *)this + 1) = (2
                        * ((2
                          * ((2
                            * ((2 * ((2 * ((2 * (flags >> 9)) & 2 | (flags >> 10) & 0xFD)) & 6 | ((flags & 0x800) != 0)))
                             | ((flags & 0x1000) != 0)))
                           | ((flags & 0x4000) != 0)))
                         | ((flags & 0x8000) != 0)))
                       | ((flags & 0x10000) != 0)
                       | (flags >> 1) & 0x80;
  *(_BYTE *)this = (2
                  * ((2
                    * ((2
                      * ((2
                        * ((2 * ((2 * ((2 * flags) | ((flags & 2) != 0))) | ((flags & 4) != 0))) | ((flags & 8) != 0)))
                       | ((flags & 0x10) != 0)))
                     | ((flags & 0x20) != 0)))
                   | ((flags & 0x40) != 0)))
                 | ((flags & 0x80) != 0);
  *((_BYTE *)this + 2) = (2
                        * ((2
                          * ((2
                            * ((2 * ((2 * ((flags >> 17) & 2 | ((flags & 0x80000) != 0))) | ((flags & 0x100000) != 0)))
                             | ((flags & 0x200000) != 0)))
                           | ((flags & 0x400000) != 0)))
                         | ((flags & 0x1000000) != 0)))
                       | (flags >> 10) & 0x80
                       | ((flags & 0x800000) != 0);
  *((_BYTE *)this + 3) = (flags >> 23) & 0x80 | v2 & 0x7F;
}


// ========================================================================
// ?DefaultDefinition@idMaterial@@UBAPBDXZ
// EA  : 0x828AA058
// RVA : 0x008AA058
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

const char *__fastcall idMaterial::DefaultDefinition(idMaterial *this)
{
  return "{ // DEFAULTED\n\ttransMap _default\n   stageProgram guiBlend\n}\n";
}


// ========================================================================
// ?IsValidMaterialName@idMaterial@@SA_NPBD_N1@Z
// EA  : 0x828AA068
// RVA : 0x008AA068
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::IsValidMaterialName(const char *name, bool allowUnderscore, bool allowAmpersand)
{
  int v3; // r11
  bool v4; // r10
  const char *v6; // r3
  int v7; // r11
  char v9; // r10

  v3 = *name;
  v4 = v3 >= 97 && v3 <= 122 || v3 >= 65 && v3 <= 90;
  if ( !v4 && (!allowUnderscore || v3 != 95) )
    return 0;
  v6 = name + 1;
  v7 = *v6;
  if ( *v6 != 0 )
  {
    while ( 1 )
    {
      if ( (v7 < 97 || v7 > 122) && (v7 < 65 || v7 > 90) )
      {
        if ( v7 > 57 || (v9 = 1, v7 < 48) )
          v9 = 0;
        if ( v9 == 0 && v7 != 95 && v7 != 47 && v7 != 92 && v7 != 46 && (v7 != 38 || !allowAmpersand) )
          break;
      }
      v7 = *++v6;
      if ( *v6 == 0 )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?Clear@idMaterial@@AAAXXZ
// EA  : 0x828AA1A0
// RVA : 0x008AA1A0
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::Clear(idMaterial *this)
{
  char v1; // r6
  float *v3; // r10
  int v4; // ctr

  v1 = *((_BYTE *)this + 73) & 0x1F;
  *((_BYTE *)this + 72) = 0;
  this->materialAutospriteType = AUTOSPRITE_NONE;
  this->materialDecalProjType = DECALPROJ_PLANAR;
  *((_BYTE *)this + 73) = v1;
  this->editorImage = nullptr;
  this->devVmtr = nullptr;
  this->atlasScaleBias.x = 1.0;
  this->atlasScaleBias.y = 1.0;
  v3 = (float *)&this->progs[7];
  this->atlasScaleBias.z = 0.0;
  v4 = 8;
  this->atlasScaleBias.w = 0.0;
  this->virtualMapping.w = 0.0;
  this->virtualMapping.z = 0.0;
  this->virtualMapping.y = 0.0;
  this->virtualMapping.x = 0.0;
  this->pageSource = PAGESOURCE_VMTR;
  this->pageFileName = nullptr;
  this->physicalPagesPool = PHYSICAL_PAGES_POOL_VMTR;
  this->materialMap = nullptr;
  this->coverage = MC_BAD;
  do
  {
    *(v3 - 7) = 0.0;
    *++v3 = 0.0;
    --v4;
  }
  while ( v4 != 0 );
  idParmBlock::Clear(this: &this->parmBlock);
  idParmBlock::Clear(this: &this->renderParmBlock);
}


// ========================================================================
// ?OptimizeRenderParmBlock@idMaterial@@QAAXXZ
// EA  : 0x828AA260
// RVA : 0x008AA260
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::OptimizeRenderParmBlock(idMaterial *this)
{
  idParmBlock *p_renderParmBlock; // r29
  const idDeclRenderProg **p_physicalPagesPool; // r30
  int i; // r31
  int v4; // r10
  const char *resourceError; // r8
  int numUsedParms; // r11
  idParmBlockOptimizer *v7; // r9
  int v8; // r10
  const char *v9; // r8
  idParmBlockOptimizer *v10; // r9
  int v11; // r10
  const char *v12; // r8
  idParmBlockOptimizer *v13; // r9
  int v14; // r10
  const char *v15; // r8
  idParmBlockOptimizer *v16; // r9
  int v17; // r10
  const char *v18; // r8
  idParmBlockOptimizer *v19; // r9
  int v20; // r10
  const char *v21; // r8
  idParmBlockOptimizer *v22; // r9
  int v23; // r10
  const char *v24; // r8
  idParmBlockOptimizer *v25; // r9
  idParmBlockOptimizer v26; // [sp+50h] [-350h] BYREF

  p_renderParmBlock = &this->renderParmBlock;
  p_physicalPagesPool = (const idDeclRenderProg **)&this->physicalPagesPool;
  idParmBlock::CopyFrom(this: &this->renderParmBlock, other: &this->parmBlock);
  v26.numUsedParms = 0;
  for ( i = 8; i != 0; --i )
    idParmBlockOptimizer::AddRenderProg(this: &v26, prog: *++p_physicalPagesPool);
  v4 = 0;
  resourceError = rp_lightColor.r[1].resourceError;
  numUsedParms = v26.numUsedParms;
  if ( v26.numUsedParms <= 0 )
  {
LABEL_7:
    v26.usedParms[v26.numUsedParms] = (int)resourceError;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v7 = &v26;
    while ( resourceError != (const char *)v7->usedParms[0] )
    {
      ++v4;
      v7 = (idParmBlockOptimizer *)((char *)v7 + 4);
      if ( v4 >= v26.numUsedParms )
        goto LABEL_7;
    }
  }
  v8 = 0;
  v9 = rp_lightRotation.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_12:
    v26.usedParms[numUsedParms] = (int)v9;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v10 = &v26;
    while ( v9 != (const char *)v10->usedParms[0] )
    {
      ++v8;
      v10 = (idParmBlockOptimizer *)((char *)v10 + 4);
      if ( v8 >= numUsedParms )
        goto LABEL_12;
    }
  }
  v11 = 0;
  v12 = rp_lightTranslation.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_17:
    v26.usedParms[numUsedParms] = (int)v12;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v13 = &v26;
    while ( v12 != (const char *)v13->usedParms[0] )
    {
      ++v11;
      v13 = (idParmBlockOptimizer *)((char *)v13 + 4);
      if ( v11 >= numUsedParms )
        goto LABEL_17;
    }
  }
  v14 = 0;
  v15 = rp_lightScale.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_22:
    v26.usedParms[numUsedParms] = (int)v15;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v16 = &v26;
    while ( v15 != (const char *)v16->usedParms[0] )
    {
      ++v14;
      v16 = (idParmBlockOptimizer *)((char *)v16 + 4);
      if ( v14 >= numUsedParms )
        goto LABEL_22;
    }
  }
  v17 = 0;
  v18 = rp_lightOscillationAmp.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_27:
    v26.usedParms[numUsedParms] = (int)v18;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v19 = &v26;
    while ( v18 != (const char *)v19->usedParms[0] )
    {
      ++v17;
      v19 = (idParmBlockOptimizer *)((char *)v19 + 4);
      if ( v17 >= numUsedParms )
        goto LABEL_27;
    }
  }
  v20 = 0;
  v21 = rp_lightOscillationFreq.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_32:
    v26.usedParms[numUsedParms] = (int)v21;
    numUsedParms = ++v26.numUsedParms;
  }
  else
  {
    v22 = &v26;
    while ( v21 != (const char *)v22->usedParms[0] )
    {
      ++v20;
      v22 = (idParmBlockOptimizer *)((char *)v22 + 4);
      if ( v20 >= numUsedParms )
        goto LABEL_32;
    }
  }
  v23 = 0;
  v24 = rp_lightOscillationPhase.r[1].resourceError;
  if ( numUsedParms <= 0 )
  {
LABEL_37:
    v26.usedParms[numUsedParms] = (int)v24;
    ++v26.numUsedParms;
  }
  else
  {
    v25 = &v26;
    while ( v24 != (const char *)v25->usedParms[0] )
    {
      ++v23;
      v25 = (idParmBlockOptimizer *)((char *)v25 + 4);
      if ( v23 >= numUsedParms )
        goto LABEL_37;
    }
  }
  idParmBlockOptimizer::OptimizeParmBlockForUsedParms(this: &v26, parmBlock: p_renderParmBlock);
}


// ========================================================================
// ?SetImplicitText@idMaterial@@UAA_NXZ
// EA  : 0x828AA508
// RVA : 0x008AA508
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::SetImplicitText(idMaterial *this)
{
  const char *v2; // r6
  const char *v3; // r5
  char v5[2048]; // [sp+50h] [-810h] BYREF

  if ( (unsigned __int8)idMaterial::IsValidMaterialName(
                          name: this->name.str,
                          allowUnderscore: false,
                          allowAmpersand: false) != 0 )
  {
    if ( idStr::Icmpn(s1: v2, s2: "fonts/", n: 6) != 0 )
    {
      if ( r_useHardwareTextures.valueInteger != 0 )
        v3 = "{ // IMPLICITLY GENERATED\ntransMap clamp linear \"%s\"\nstageProgram\tguiBlend\n}\n";
      else
        v3 = "{ // IMPLICITLY GENERATED\nvirtualTransMap \"%s\"\nstageProgram\tvirtualGuiBlend\n}\n";
    }
    else
    {
      v3 = "{ // IMPLICITLY GENERATED\ntransmap alpha borderClamp \"%s\"\nstageprogram FontBiasAndGamma\n}\n";
    }
    idStr::snPrintf(dest: v5, size: 2048, fmt: v3, this->name.str);
  }
  else
  {
    idStr::snPrintf(
      dest: v5,
      size: 2048,
      fmt: "{ // IMPLICITLY GENERATED\ntransMap clamp linear \"%s\"\nstageProgram\tguiBlend\n}\n",
      v2);
  }
  idDecl::SetText(this: &this->idDecl, text: v5, length: 0);
  return 1;
}


// ========================================================================
// ?List@idMaterial@@UBAXXZ
// EA  : 0x828AA5D0
// RVA : 0x008AA5D0
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::List(idMaterial *this)
{
  idLib::Printf(fmt: "%s\n", this->name.str);
}


// ========================================================================
// ?SetupVirtualTexture@idMaterial@@QBAXXZ
// EA  : 0x828AA5E0
// RVA : 0x008AA5E0
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::SetupVirtualTexture(idMaterial *this)
{
  idVirtualTexture *v2; // r3
  idVirtualTexture *v3; // r31
  const idDeclRenderParm *r; // r28
  idVec4 *FeedbackVec4; // r3
  double y; // fp13
  double z; // fp12
  double w; // fp11
  parmValue_t v9; // [sp+50h] [-50h] BYREF
  char v10; // [sp+60h] [-40h] BYREF

  if ( this->pageFileName != nullptr )
  {
    v2 = idVirtualTextureSystem::VirtualTextureForMaterial(this: &virtualTextureSystem, mtr: this);
    v3 = v2;
    if ( v2 != nullptr && v2->pageFile != nullptr )
    {
      this->pageSource = v2->pageSource;
      if ( r_skipVmtrs.valueInteger == 0 )
      {
        r = (const idDeclRenderParm *)rp_virtualTextureFeedbackFloat.r;
        FeedbackVec4 = idVirtualTexture::GetFeedbackVec4(this: (idVirtualTexture *)&v10, result: (idVec4 *)v2);
        y = FeedbackVec4->y;
        z = FeedbackVec4->z;
        w = FeedbackVec4->w;
        v9.value[0] = FeedbackVec4->x;
        v9.value[1] = y;
        v9.value[2] = z;
        v9.value[3] = w;
        idParmBlock::SetParm(this: &this->parmBlock, parm: r, parmValue: &v9);
        idParmBlock::SetImage(
          this: &this->parmBlock,
          parm: (const idDeclRenderParm *)rp_pageTableMap.r,
          image: v3->pageTableImage);
      }
      idMaterial::OptimizeRenderParmBlock(this);
    }
  }
}


// ========================================================================
// ?UpdateVirtualMapping@idMaterial@@QBAXXZ
// EA  : 0x828AA6B8
// RVA : 0x008AA6B8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::UpdateVirtualMapping(idMaterial *this)
{
  idVirtualMaterial *devVmtr; // r11
  double y; // fp13
  idParmBlock *p_parmBlock; // r30
  double z; // fp12
  double w; // fp11
  idVirtualMaterial *v7; // r11
  idVirtualMaterial *v8; // r11
  double v9; // fp5
  double x; // fp4
  double v11; // fp3
  parmValue_t v12; // [sp+50h] [-40h] BYREF

  devVmtr = this->devVmtr;
  if ( devVmtr != nullptr )
  {
    y = devVmtr->scaleAndBias.y;
    p_parmBlock = &this->parmBlock;
    z = devVmtr->scaleAndBias.z;
    w = devVmtr->scaleAndBias.w;
    v12.value[0] = devVmtr->scaleAndBias.x;
    v12.value[1] = y;
    v12.value[2] = z;
    v12.value[3] = w;
    idParmBlock::SetParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_virtualMapping.r, parmValue: &v12);
    v12.value[3] = 1.0;
    v12.value[2] = 1.0;
    v12.value[1] = 1.0;
    v12.value[0] = 1.0;
    idParmBlock::SetParm(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_useVirtualMapping.r, parmValue: &v12);
    v7 = this->devVmtr;
    this->virtualMapping.x = v7->scaleAndBias.x;
    this->virtualMapping.y = v7->scaleAndBias.y;
    this->virtualMapping.z = v7->scaleAndBias.z;
    this->virtualMapping.w = v7->scaleAndBias.w;
    v8 = this->devVmtr;
    v9 = v8->scaleAndBias.z;
    x = v8->scaleAndBias.x;
    v11 = v8->scaleAndBias.w;
    v12.value[1] = v8->scaleAndBias.y;
    v12.value[3] = v11;
    v12.value[0] = x;
    v12.value[2] = v9;
    idParmBlock::SetParm(
      this: &this->renderParmBlock,
      parm: (const idDeclRenderParm *)rp_virtualMapping.r,
      parmValue: &v12);
    v12.value[3] = 1.0;
    v12.value[2] = 1.0;
    v12.value[1] = 1.0;
    v12.value[0] = 1.0;
    idParmBlock::SetParm(
      this: &this->renderParmBlock,
      parm: (const idDeclRenderParm *)rp_useVirtualMapping.r,
      parmValue: &v12);
  }
}


// ========================================================================
// ?MaterialIsMergableWith@idMaterial@@QBA_NPBV1@@Z
// EA  : 0x828AA7D0
// RVA : 0x008AA7D0
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::MaterialIsMergableWith(idMaterial *this, const idMaterial *testMtr)
{
  const idDeclRenderProg *v3; // r11
  bool v4; // cr58

  if ( testMtr == this )
    return 1;
  if ( this->progs[0] == testMtr->progs[0]
    && this->progs[1] == testMtr->progs[1]
    && this->progs[2] == testMtr->progs[2]
    && this->progs[3] == testMtr->progs[3] )
  {
    v3 = this->progs[4];
    if ( (*((_BYTE *)this + 73) & 0x80) != 0 )
    {
      if ( v3 != testMtr->progs[4] )
        return 0;
      v4 = this->progs[5] == testMtr->progs[5];
    }
    else
    {
      if ( v3 != nullptr || testMtr->progs[4] != nullptr || this->progs[5] != nullptr )
        return 0;
      v4 = testMtr->progs[5] == nullptr;
    }
    if ( v4 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?GetMaterialMapping@idMaterial@@QBAPBMPBV1@@Z
// EA  : 0x828AA888
// RVA : 0x008AA888
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

float *__fastcall idMaterial::GetMaterialMapping(idMaterial *this, const idMaterial *mtr)
{
  idMaterialMap *materialMap; // r11
  int v5; // r31
  int i; // r30
  int v7; // r3

  materialMap = this->materialMap;
  if ( materialMap == nullptr )
    return defaultScaleBias;
  v5 = 0;
  if ( materialMap->mappings.num <= 0 )
    return defaultScaleBias;
  for ( i = 0; ; ++i )
  {
    v7 = idStr::Icmp(s1: materialMap->mappings.list[i].materialName.str, s2: mtr->name.str);
    materialMap = this->materialMap;
    if ( v7 == 0 )
      break;
    if ( ++v5 >= materialMap->mappings.num )
      return defaultScaleBias;
  }
  return (float *)&materialMap->mappings.list[v5].scaleBias;
}


// ========================================================================
// ?MaterialMappingsAreCompatible@idMaterial@@QBA_NPBV1@@Z
// EA  : 0x828AA918
// RVA : 0x008AA918
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::MaterialMappingsAreCompatible(idMaterial *this, const idMaterial *mtr)
{
  idMaterialMap *materialMap; // r10
  idMaterialMap *v3; // r11
  int num; // r5
  int v5; // r6
  idMaterialMapping *list; // r8
  int v7; // r9
  idMaterialMapping *v8; // r7
  float *v9; // r11
  float *v10; // r10
  double v11; // fp13
  char v12; // r11

  materialMap = this->materialMap;
  if ( materialMap != nullptr )
  {
    v3 = mtr->materialMap;
    if ( v3 != nullptr )
    {
      num = materialMap->mappings.num;
      if ( num == v3->mappings.num )
      {
        v5 = 0;
        if ( num <= 0 )
          return 1;
        list = v3->mappings.list;
        v7 = 0;
        v8 = materialMap->mappings.list;
        while ( 1 )
        {
          v9 = (float *)&list[v7];
          v10 = (float *)&v8[v7];
          if ( v8[v7].scaleBias.x != list[v7].scaleBias.x
            || v10[8] != v9[8]
            || v10[9] != v9[9]
            || (v11 = v9[10], v12 = 1, v10[10] != v11) )
          {
            v12 = 0;
          }
          if ( v12 == 0 )
            break;
          ++v5;
          ++v7;
          if ( v5 >= num )
            return 1;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?GetImageDimensions@idMaterial@@QBA_NAAH0@Z
// EA  : 0x828AA9D8
// RVA : 0x008AA9D8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::GetImageDimensions(idMaterial *this, int *width, int *height)
{
  idMaterialMap *materialMap; // r3
  int result; // r3
  idParmBlock *p_parmBlock; // r31
  const char *String; // r3
  bool v10; // r28
  const char *v11; // r3
  bool v12; // r5
  idParmBlock *v13; // r3
  const char *v14; // r3
  bool v15; // r3
  int v16; // r11
  int v17; // r10
  int v18; // r11
  int v19; // r9
  int v20; // [sp+50h] [-40h] BYREF
  int v21; // [sp+54h] [-3Ch] BYREF
  int v22; // [sp+58h] [-38h] BYREF
  int v23; // [sp+5Ch] [-34h] BYREF
  int v24; // [sp+60h] [-30h] BYREF
  int v25; // [sp+64h] [-2Ch] BYREF

  materialMap = this->materialMap;
  if ( materialMap != nullptr )
    return idMaterialMap::GetImageDimensions(this: materialMap, width, height);
  p_parmBlock = &this->parmBlock;
  String = idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_virtualTransMap.r);
  v10 = R_LoadImageProgram(name: String, pic: nullptr, width: &v20, height: &v23, timestamps: nullptr);
  v11 = idParmBlock::GetString(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_diffuseMap.r);
  v12 = R_LoadImageProgram(name: v11, pic: nullptr, width: &v21, height: &v24, timestamps: nullptr);
  v13 = p_parmBlock;
  LOBYTE(p_parmBlock) = v12 && v10;
  v14 = idParmBlock::GetString(this: v13, parm: (const idDeclRenderParm *)rp_bumpMap.r);
  v15 = R_LoadImageProgram(name: v14, pic: nullptr, width: &v22, height: &v25, timestamps: nullptr);
  v16 = v20;
  result = v15 & (unsigned __int8)p_parmBlock;
  if ( v20 <= v21 )
    v16 = v21;
  v17 = v22;
  if ( v22 <= v16 )
    v17 = v16;
  v18 = v23;
  v19 = v24;
  *width = v17;
  if ( v18 <= v19 )
    v18 = v19;
  if ( v25 > v18 )
    v18 = v25;
  *height = v18;
  if ( *width == 0 || v18 == 0 )
  {
    *width = 1;
    *height = 1;
  }
  return result;
}


// ========================================================================
// ?MaterialIsUniqueMap@idMaterial@@QBA_NXZ
// EA  : 0x828AAB18
// RVA : 0x008AAB18
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

BOOL __fastcall idMaterial::MaterialIsUniqueMap(idMaterial *this)
{
  char *pageFileName; // r10

  pageFileName = (char *)this->pageFileName;
  return pageFileName != nullptr && virtualTextureSystem.vts[1].baseName.data != pageFileName;
}


// ========================================================================
// ?IsVMTRVirtualTexture@idMaterial@@QBA_NXZ
// EA  : 0x828AAB48
// RVA : 0x008AAB48
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

BOOL __fastcall idMaterial::IsVMTRVirtualTexture(idMaterial *this)
{
  return this->pageSource <= PAGESOURCE_VMTR && (*((_BYTE *)this + 72) & 0x10) != 0;
}


// ========================================================================
// ??0idMaterial@@QAA@XZ
// EA  : 0x828AAD18
// RVA : 0x008AAD18
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

idMaterial *__fastcall idMaterial::idMaterial(idMaterial *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idMaterial_vtbl *)&idMaterial::`vftable';
  idParmBlock::idParmBlock(this: &this->parmBlock, threadId: THREAD_MAIN);
  idParmBlock::idParmBlock(this: &this->renderParmBlock, threadId: THREAD_RENDERER);
  idMaterial::Clear(this);
  return this;
}


// ========================================================================
// __unwind$232668
// EA  : 0x828AAD84
// RVA : 0x008AAD84
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_232668()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$232669
// EA  : 0x828AADAC
// RVA : 0x008AADAC
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_232669()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$232670
// EA  : 0x828AADD8
// RVA : 0x008AADD8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_232670()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 124));
}


// ========================================================================
// ?GetDeclTimestamp@idMaterial@@UBAIXZ
// EA  : 0x828AAE20
// RVA : 0x008AAE20
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::GetDeclTimestamp(idMaterial *this)
{
  idMaterial *v2; // r3
  bool v3; // zf
  const char *v4; // r3
  unsigned int v5; // r30
  idFileSystem_vtbl *v7; // r30
  const char *FileName; // r3
  idStr v9[2]; // [sp+50h] [-40h] BYREF

  v3 = !idDecl::IsImplicit(this: &this->idDecl);
  v2 = this;
  if ( v3 )
  {
    v7 = fileSystem->__vftable;
    FileName = idDecl::GetFileName(this: &v2->idDecl);
    return v7->GetTimestamp(this: fileSystem, a2: FileName, a3: false);
  }
  else
  {
    v4 = idDecl::GetFileName(this: &this->idDecl);
    idStr::idStr(this: v9, text: v4);
    idStr::SetFileExtension(this: v9, extension: "tga");
    v5 = fileSystem->GetTimestamp(this: fileSystem, a2: v9[0].data, a3: false);
    idStr::FreeData(this: v9);
    return v5;
  }
}


// ========================================================================
// __unwind$232767
// EA  : 0x828AAECC
// RVA : 0x008AAECC
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_232767()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetEditorImage@idMaterial@@ABAXXZ
// EA  : 0x828AAF00
// RVA : 0x008AAF00
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::SetEditorImage(idMaterial *this)
{
  idParmBlock *p_parmBlock; // r29
  const char *String; // r3
  idCodeResource<idDeclRenderParm> *v4; // r30
  idParmBlock *v5; // r3
  bool v6; // zf
  const char *v7; // r3
  const idImage *v8; // r3
  const char *v9; // r3
  int v10; // r26
  int v11; // r27
  int v12; // r28
  expOp_t *v13; // r30
  parmType_t parmType; // r11
  char v15; // r11
  int v16; // r11
  idStr v17[3]; // [sp+50h] [-70h] BYREF

  p_parmBlock = &this->parmBlock;
  String = idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_editorImage.r);
  idStr::idStr(this: v17, text: String);
  if ( v17[0].len != 0 )
  {
LABEL_8:
    v8 = idImageManager::ImageFromFile(this: globalImages, _name: v17[0].data, opts_p: nullptr, makeDefault: false);
    this->editorImage = v8;
    if ( v8 != nullptr )
      goto LABEL_24;
    goto LABEL_9;
  }
  v4 = &rp_transSortMap;
  v6 = idParmBlock::SetsRenderParm(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_transSortMap.r);
  v5 = p_parmBlock;
  if ( !v6 )
  {
    v4 = &rp_virtualTransMap;
    v6 = idParmBlock::SetsRenderParm(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_virtualTransMap.r);
    v5 = p_parmBlock;
    if ( !v6 )
    {
      v4 = &rp_transAtlasMap;
      if ( !idParmBlock::SetsRenderParm(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_transAtlasMap.r) )
        goto LABEL_7;
      v5 = p_parmBlock;
    }
  }
  v7 = idParmBlock::GetString(this: v5, parm: (const idDeclRenderParm *)v4->r);
  idStr::operator=(this: v17, text: v7);
LABEL_7:
  if ( v17[0].len != 0 )
    goto LABEL_8;
LABEL_9:
  if ( idParmBlock::SetsRenderParm(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_diffuseMap.r) )
  {
    v9 = idParmBlock::GetString(this: p_parmBlock, parm: (const idDeclRenderParm *)rp_diffuseMap.r);
    this->editorImage = idImageManager::ImageFromFile(this: globalImages, _name: v9, opts_p: nullptr, makeDefault: true);
  }
  else
  {
    v10 = 0;
    if ( this->parmBlock.ops.num <= 0 )
    {
LABEL_23:
      this->editorImage = globalImages->defaultImage;
    }
    else
    {
      v11 = 0;
      v12 = 0;
      while ( 1 )
      {
        v13 = &p_parmBlock->ops.list[v12];
        parmType = expOp_t::GetDest(this: v13)->parmType;
        if ( parmType < PT_TEXTURE || (v6 = parmType <= PT_TEXTURE_MULTISAMPLE_2D, v15 = 1, !v6) )
          v15 = 0;
        if ( v15 != 0 )
        {
          v16 = (v13->type & 0x1F) != 0
              ? expOp_t::GetA(this: v13)->declaredValue.swizzle[0]
              : this->parmBlock.constants.list[v11].swizzle[0];
          if ( v16 != 0 && *(_DWORD *)(v16 + 60) == 0 )
            break;
        }
        ++v10;
        ++v12;
        ++v11;
        if ( v10 >= this->parmBlock.ops.num )
          goto LABEL_23;
      }
      this->editorImage = (const idImage *)v16;
    }
  }
LABEL_24:
  idStr::FreeData(this: v17);
}


// ========================================================================
// __unwind$232792
// EA  : 0x828AB110
// RVA : 0x008AB110
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_232792()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ReloadImages@idMaterial@@QBAX_N@Z
// EA  : 0x828AB138
// RVA : 0x008AB138
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::ReloadImages(idMaterial *this, bool force)
{
  int v3; // r27
  int v4; // r28
  int v5; // r30
  expOp_t *v6; // r31
  parmType_t parmType; // r11
  char v8; // r11
  bool v9; // zf
  void (*ReloadIfStale)(void); // ctr

  v3 = 0;
  if ( this->parmBlock.ops.num > 0 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = &this->parmBlock.ops.list[v5];
      parmType = expOp_t::GetDest(this: v6)->parmType;
      if ( parmType < PT_TEXTURE || (v9 = parmType <= PT_TEXTURE_MULTISAMPLE_2D, v8 = 1, !v9) )
        v8 = 0;
      if ( v8 != 0 )
      {
        if ( (v6->type & 0x1F) != 0 )
          ReloadIfStale = (void (*)(void))expOp_t::GetA(this: v6)->declaredValue.image->ReloadIfStale;
        else
          ReloadIfStale = (void (*)(void))this->parmBlock.constants.list[v4].image->ReloadIfStale;
        ReloadIfStale();
      }
      ++v3;
      ++v5;
      ++v4;
    }
    while ( v3 < this->parmBlock.ops.num );
  }
}


// ========================================================================
// ?InitCompatibleGenericMaterials@idMaterial@@SAXXZ
// EA  : 0x828AB200
// RVA : 0x008AB200
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

static void __fastcall idMaterial::InitCompatibleGenericMaterials()
{
  int v0; // r30
  genericMtr_t *v1; // r11
  int v2; // r31
  const idMaterial *v3; // r3
  idMaterial *v4; // r3

  if ( genericMaterials[0].mtr == nullptr )
  {
    v0 = 0;
    if ( genericMaterials[0].name != nullptr )
    {
      v1 = genericMaterials;
      v2 = 0;
      while ( 1 )
      {
        v3 = v1->name != nullptr
           ? (const idMaterial *)idDeclInfo::FindWithInheritance(
                                   this: &idMaterial::resourceList,
                                   name: v1->name,
                                   makeDefault: false)
           : nullptr;
        genericMaterials[v2].mtr = v3;
        if ( v3 == nullptr )
          break;
        v3->pageFileName = virtualTextureSystem.vts[1].baseName.data;
        idMaterial::SetupVirtualTexture(this: genericMaterials[v2].mtr);
        v2 = ++v0;
        v1 = &genericMaterials[v0];
        if ( v1->name == nullptr )
          return;
      }
      idLib::FatalError(fmt: "Couldn't find material: %s", genericMaterials[v2].name);
      idMaterial::CompatibleGenericMaterial(this: v4);
    }
  }
}


// ========================================================================
// ?CompatibleGenericMaterial@idMaterial@@QBAPBV1@XZ
// EA  : 0x828AB2B8
// RVA : 0x008AB2B8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

const idMaterial *__fastcall idMaterial::CompatibleGenericMaterial(idMaterial *this)
{
  int v2; // r29
  genericMtr_t *v3; // r10
  int v4; // r11
  const idMaterial *mtr; // r30
  int v6; // r9

  if ( genericMaterials[0].mtr == nullptr )
    idMaterial::InitCompatibleGenericMaterials();
  v2 = 0;
  if ( genericMaterials[0].name == nullptr )
    return nullptr;
  v3 = genericMaterials;
  v4 = 0;
  while ( 1 )
  {
    mtr = genericMaterials[v4].mtr;
    if ( v3->name != nullptr )
      idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: v3->name, makeDefault: false);
    if ( (unsigned __int8)idMaterial::MaterialIsMergableWith(this, testMtr: mtr) != 0 )
      break;
    v4 = ++v2;
    v3 = &genericMaterials[v2];
    if ( v3->name == nullptr )
      return nullptr;
  }
  return (const idMaterial *)v6;
}


// ========================================================================
// ?MaterialMappingNeedsReload@idMaterial@@QBA_NPBVidDeclSkins@@@Z
// EA  : 0x828AB378
// RVA : 0x008AB378
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::MaterialMappingNeedsReload(idMaterial *this, const idDeclSkins *skins)
{
  idMaterialMap *materialMap; // r11
  int v5; // r27
  int i; // r31
  const char *str; // r4
  idCollisionModelLocal *v8; // r3
  idCollisionModelLocal *v9; // r29
  idMaterialMapping *v10; // r28
  idCollisionModelLocal *v11; // r3
  idMaterialMapping *v12; // r29
  cmType_t (__fastcall *GetModelType)(struct idCollisionModelLocal *); // ctr
  idMaterialMap *v14; // r29

  materialMap = this->materialMap;
  if ( materialMap == nullptr )
    return 0;
  if ( idLib::production == PROD_PRODUCTION )
    return 0;
  v5 = 0;
  if ( materialMap->mappings.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    str = materialMap->mappings.list[i].materialName.str;
    if ( str == nullptr )
      break;
    v8 = (idCollisionModelLocal *)idDeclInfo::FindWithInheritance(
                                    this: &idMaterial::resourceList,
                                    name: str,
                                    makeDefault: false);
    v9 = v8;
    if ( v8 == nullptr )
      break;
    v10 = &this->materialMap->mappings.list[i];
    if ( v10->materialChecksum != idLexer::GetScriptP(this: v8) )
    {
      v11 = v9;
      GetModelType = v9->GetModelType;
      v12 = &this->materialMap->mappings.list[i];
      if ( GetModelType(this: v11) > v12->materialTimestamp )
        break;
    }
    v14 = this->materialMap;
    if ( v14->skinFileTimeStamp != skins->GetDeclTimestamp(this: skins) )
      break;
    if ( !idVirtualImageFile::NeedsReload(this: &v14->mappings.list[i].specularFile)
      && !idVirtualImageFile::NeedsReload(this: &this->materialMap->mappings.list[i].coverFile)
      && !idVirtualImageFile::NeedsReload(this: &this->materialMap->mappings.list[i].diffuseFile)
      && !idVirtualImageFile::NeedsReload(this: &this->materialMap->mappings.list[i].bumpFile) )
    {
      idVirtualImageFile::NeedsReload(this: &this->materialMap->mappings.list[i].powerFile);
    }
    materialMap = this->materialMap;
    if ( ++v5 >= materialMap->mappings.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?MaterialForcesNormalSmoothing@idMaterial@@QBA_NXZ
// EA  : 0x828AB518
// RVA : 0x008AB518
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

BOOL __fastcall idMaterial::MaterialForcesNormalSmoothing(idMaterial *this)
{
  const idDeclRenderParm *v2; // r3
  const char *String; // r3

  v2 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclRenderParm::resourceList,
                                   name: "renderbump",
                                   makeDefault: true);
  String = idParmBlock::GetString(this: &this->parmBlock, parm: v2);
  if ( String != nullptr && *String != 0 )
    return (_cntlzw((unsigned int)strstr(str1: String, str2: "-facet")) & 0x20) != 0;
  else
    return ((this->pageSource >= PAGESOURCE_INVALID) + (this->pageSource <= (unsigned int)PAGESOURCE_VMTR)) & 1;
}


// ========================================================================
// ?NameWithoutAutoMaterial@idMaterial@@QBA?AVidStr@@XZ
// EA  : 0x828AB5C8
// RVA : 0x008AB5C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

idMaterial *__fastcall idMaterial::NameWithoutAutoMaterial(idMaterial *this, idStr *result)
{
  const char *v4; // r11
  int v5; // r10
  const char *v6; // r11
  int v7; // r9
  idStr v9[2]; // [sp+60h] [-50h] BYREF

  v4 = AUTO_MATERIAL_PREFIX;
  do
    v5 = *(unsigned __int8 *)v4++;
  while ( v5 != 0 );
  if ( strncmp(
         Str1: (const char *)result->allocedAndFlag,
         Str2: AUTO_MATERIAL_PREFIX,
         MaxCount: v4 - AUTO_MATERIAL_PREFIX - 1) != 0 )
  {
    idStr::idStr((idStr *)this, text: (const char *)result->allocedAndFlag);
  }
  else
  {
    v6 = AUTO_MATERIAL_PREFIX;
    do
      v7 = *(unsigned __int8 *)v6++;
    while ( v7 != 0 );
    idStr::idStr(this: v9, text: (const char *)(v6 - AUTO_MATERIAL_PREFIX - 1 + result->allocedAndFlag));
    idStr::StripFileExtension(this: v9);
    idStr::idStr((idStr *)this, text: v9);
    idStr::FreeData(this: v9);
  }
  return this;
}


// ========================================================================
// __unwind$233415
// EA  : 0x828AB68C
// RVA : 0x008AB68C
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_233415()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetWidth@idMaterial@@QBAHXZ
// EA  : 0x828AB758
// RVA : 0x008AB758
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::GetWidth(idMaterial *this, long double a2)
{
  int result; // r3
  idVirtualMaterial *devVmtr; // r11
  __int64 v5; // r6
  long double v6; // fp2

  if ( this->pageSource <= PAGESOURCE_VMTR )
  {
    devVmtr = this->devVmtr;
    if ( devVmtr != nullptr )
    {
      if ( (devVmtr->flags & 2) != 0 )
        result = devVmtr->allocWidth;
      else
        result = devVmtr->allocWidth - 32;
      if ( (devVmtr->flags & 2) != 0 )
        result = (result << 7) / 120;
    }
    else
    {
      HIDWORD(v5) = LODWORD(this->virtualMapping.w)
                  | LODWORD(this->virtualMapping.z)
                  | LODWORD(this->virtualMapping.y)
                  | LODWORD(this->virtualMapping.x);
      if ( (v5 & 0x7FFFFFFF00000000LL) != 0 )
      {
        LODWORD(v5) = 120 * virtualTextureSystem.vmtrMega->VIRTUAL_MAPPING_PAGES_WIDE;
        *(double *)&a2 = (float)((float)((float)v5 * this->virtualMapping.x) + (float)0.5);
        v6 = floor(x: a2);
        result = (int)(float)*(double *)&v6;
      }
      else
      {
        if ( this->editorImage == nullptr )
          idMaterial::SetEditorImage(this);
        result = this->editorImage->opts.width;
      }
    }
  }
  else
  {
    result = 960 * idParmBlock::GetInteger(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_landDimensions.r);
  }
  if ( result < 1 )
    return 1;
  return result;
}


// ========================================================================
// ?GetHeight@idMaterial@@QBAHXZ
// EA  : 0x828AB898
// RVA : 0x008AB898
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

int __fastcall idMaterial::GetHeight(idMaterial *this, long double a2)
{
  int result; // r3
  idVirtualMaterial *devVmtr; // r11
  __int64 v5; // r6
  long double v6; // fp2

  if ( this->pageSource <= PAGESOURCE_VMTR )
  {
    devVmtr = this->devVmtr;
    if ( devVmtr != nullptr )
    {
      if ( (devVmtr->flags & 2) != 0 )
        result = devVmtr->allocHeight;
      else
        result = devVmtr->allocHeight - 32;
      if ( (devVmtr->flags & 2) != 0 )
        result = (result << 7) / 120;
    }
    else
    {
      HIDWORD(v5) = LODWORD(this->virtualMapping.w)
                  | LODWORD(this->virtualMapping.z)
                  | LODWORD(this->virtualMapping.y)
                  | LODWORD(this->virtualMapping.x);
      if ( (v5 & 0x7FFFFFFF00000000LL) != 0 )
      {
        LODWORD(v5) = 120 * virtualTextureSystem.vmtrMega->VIRTUAL_MAPPING_PAGES_WIDE;
        *(double *)&a2 = (float)((float)((float)v5 * this->virtualMapping.y) + (float)0.5);
        v6 = floor(x: a2);
        result = (int)(float)*(double *)&v6;
      }
      else
      {
        if ( this->editorImage == nullptr )
          idMaterial::SetEditorImage(this);
        result = this->editorImage->opts.height;
      }
    }
  }
  else
  {
    result = 960 * idParmBlock::GetInteger(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_landDimensions.r);
  }
  if ( result < 1 )
    return 1;
  return result;
}


// ========================================================================
// ?Write@idMaterial@@QBAPAVidStr@@XZ
// EA  : 0x828AB9D8
// RVA : 0x008AB9D8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

idStr *__fastcall idMaterial::Write(idMaterial *this)
{
  idStr *v2; // r3
  idStr *v3; // r30
  idStr *v4; // r31

  v2 = (idStr *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x20u,
                  tag: TAG_DECL,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
  {
    v2->len = 0;
    v2->allocedAndFlag = 20;
    v3 = v2;
    v2->data = v2->baseBuffer;
    v2->baseBuffer[0] = 0;
  }
  else
  {
    v3 = nullptr;
  }
  idStr::operator=(this: v3, text: "{\n");
  v4 = idParmBlock::WriteString(this: &this->parmBlock);
  idStr::Append(this: v3, text: v4);
  if ( v4 != nullptr )
  {
    idStr::FreeData(this: v4);
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
  }
  idStr::Append(this: v3, text: "}\n");
  return v3;
}


// ========================================================================
// ?Print@idMaterial@@UBAXXZ
// EA  : 0x828ABAA8
// RVA : 0x008ABAA8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::Print(idMaterial *this)
{
  idStr *v2; // r3
  const idDeclRenderProg *v3; // r11
  const char *str; // r4
  const idDeclRenderProg *v5; // r11
  const char *v6; // r4
  const idDeclRenderProg *v7; // r11
  const char *v8; // r4
  const idDeclRenderProg *v9; // r11
  const char *v10; // r4
  const idDeclRenderProg *v11; // r11
  const char *v12; // r4
  const idDeclRenderProg *v13; // r11
  const char *v14; // r4
  const idDeclRenderProg *v15; // r11
  const char *v16; // r4

  idLib::Printf(fmt: "---- Write output ----\n");
  v2 = idMaterial::Write(this);
  idLib::Printf(fmt: "%s", v2->data);
  idLib::Printf(fmt: "Coverage: %i\n", this->coverage);
  v3 = this->progs[0];
  if ( v3 != nullptr )
    str = v3->name.str;
  else
    str = "NULL";
  idLib::Printf(fmt: "ambientProgram: %s\n", str);
  v5 = this->progs[1];
  if ( v5 != nullptr )
    v6 = v5->name.str;
  else
    v6 = "NULL";
  idLib::Printf(fmt: "interactionProgram: %s\n", v6);
  v7 = this->progs[2];
  if ( v7 != nullptr )
    v8 = v7->name.str;
  else
    v8 = "NULL";
  idLib::Printf(fmt: "shadowProgram: %s\n", v8);
  v9 = this->progs[3];
  if ( v9 != nullptr )
    v10 = v9->name.str;
  else
    v10 = "NULL";
  idLib::Printf(fmt: "depthFillProgram: %s\n", v10);
  v11 = this->progs[4];
  if ( v11 != nullptr )
    v12 = v11->name.str;
  else
    v12 = "NULL";
  idLib::Printf(fmt: "addProgram: %s\n", v12);
  v13 = this->progs[5];
  if ( v13 != nullptr )
    v14 = v13->name.str;
  else
    v14 = "NULL";
  idLib::Printf(fmt: "blendProgram: %s\n", v14);
  v15 = this->progs[6];
  if ( v15 != nullptr )
    v16 = v15->name.str;
  else
    v16 = "NULL";
  idLib::Printf(fmt: "stageProgram: %s\n", v16);
}


// ========================================================================
// ?ParseMaterialMap@idMaterial@@AAA_NAAVidParser@@@Z
// EA  : 0x828ABF80
// RVA : 0x008ABF80
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMaterial::ParseMaterialMap(idMaterial *this, idParser *src)
{
  idMaterialMap *v4; // r3
  idMaterialMap *v5; // r10
  __int64 v6; // r7
  idMaterialMap *materialMap; // r11
  __int64 v8; // r9 OVERLAPPED
  __int64 v9; // r7 OVERLAPPED
  __int64 v10; // fp11
  int height; // r10
  idMaterialMapping v13; // [sp+50h] [-120h] BYREF
  __int64 v14; // [sp+A8h] [-C8h]
  idToken v15; // [sp+B0h] [-C0h] BYREF
  unsigned __int64 v16; // [sp+F8h] [-78h]
  __int64 v17; // [sp+100h] [-70h]
  __int64 v18; // [sp+108h] [-68h]
  __int64 v19; // [sp+110h] [-60h]
  unsigned __int64 v20; // [sp+118h] [-58h]
  __int64 v21; // [sp+120h] [-50h]
  __int64 v22; // [sp+128h] [-48h]

  v15.len = 0;
  v15.allocedAndFlag = 20;
  v15.floatvalue = -3.4028235e38;
  v15.data = v15.baseBuffer;
  v15.baseBuffer[0] = 0;
  v15.intvalue = 0;
  memset(&v15.whiteSpaceStart_p, 0, 12);
  v4 = (idMaterialMap *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x3Cu,
                          tag: TAG_DECL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  HIDWORD(v14) = v4;
  if ( v4 != nullptr )
    v5 = idMaterialMap::idMaterialMap(this: v4);
  else
    v5 = nullptr;
  this->materialMap = v5;
  idParser::ExpectTokenString(this: src, string: "{");
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
  idStr::operator=(this: &this->materialMap->name, text: v15.data);
  this->materialMap->width = idParser::ParseInt(this: src);
  this->materialMap->height = idParser::ParseInt(this: src);
  if ( idParser::PeekTokenString(this: src, string: "{") != 0 )
    this->materialMap->skinFileTimeStamp = -1;
  else
    this->materialMap->skinFileTimeStamp = idParser::ParseInt(this: src);
  while ( idParser::CheckTokenString(this: src, string: "{") != 0 )
  {
    v13.specularFile.timeStamp = 0;
    v13.coverFile.timeStamp = 0;
    v13.diffuseFile.timeStamp = 0;
    v13.bumpFile.timeStamp = 0;
    v13.materialName.str = &byte_8200D768;
    v13.specularFile.fileName.str = &byte_8200D768;
    v13.coverFile.fileName.str = &byte_8200D768;
    v13.diffuseFile.fileName.str = &byte_8200D768;
    v13.bumpFile.fileName.str = &byte_8200D768;
    v13.powerFile.fileName.str = &byte_8200D768;
    v13.powerFile.timeStamp = 0;
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.materialName, str_: v15.data);
    v13.materialChecksum = idParser::ParseInt(this: src);
    v13.materialTimestamp = idParser::ParseInt(this: src);
    v13.x = idParser::ParseInt(this: src);
    v13.y = idParser::ParseInt(this: src);
    v13.width = idParser::ParseInt(this: src);
    LODWORD(v6) = idParser::ParseInt(this: src);
    materialMap = this->materialMap;
    v21 = v6;
    v14 = *(_QWORD *)&v13.y;
    LODWORD(v8) = v13.y;
    v13.height = v6;
    HIDWORD(v8) = materialMap->width;
    v22 = v8;
    v16 = __PAIR64__(&v15, HIDWORD(v8));
    v10 = v8;
    v20 = __PAIR64__(v13.y, v13.x);
    v13.scaleBias.x = (float)*(__int64 *)&v13.y / (float)__SPAIR64__(&v15, HIDWORD(v8));
    LODWORD(v8) = materialMap->height;
    v19 = v8;
    v13.scaleBias.y = (float)v6 / (float)v8;
    v9 = __PAIR64__(&v15, HIDWORD(v8));
    LODWORD(v9) = materialMap->width;
    v17 = v9;
    v13.scaleBias.z = (float)__SPAIR64__(v13.y, v13.x) / (float)v9;
    height = materialMap->height;
    v18 = *(__int64 *)((char *)&v8 - 4);
    v13.scaleBias.w = (float)v10 / (float)*(__int64 *)((char *)&v8 - 4);
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.specularFile.fileName, str_: v15.data);
    v13.specularFile.timeStamp = idParser::ParseInt(this: src);
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.coverFile.fileName, str_: v15.data);
    v13.coverFile.timeStamp = idParser::ParseInt(this: src);
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.diffuseFile.fileName, str_: v15.data);
    v13.diffuseFile.timeStamp = idParser::ParseInt(this: src);
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.bumpFile.fileName, str_: v15.data);
    v13.bumpFile.timeStamp = idParser::ParseInt(this: src);
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v15);
    idAtomicString::Set(this: &v13.powerFile.fileName, str_: v15.data);
    v13.powerFile.timeStamp = idParser::ParseInt(this: src);
    idParser::ExpectTokenString(this: src, string: "}");
    idList<idMaterialMapping,46>::Append(this: &this->materialMap->mappings, obj: &v13);
  }
  idParser::ExpectTokenString(this: src, string: "}");
  idStr::FreeData(this: &v15);
  return 1;
}


// ========================================================================
// __unwind$233998
// EA  : 0x828AC364
// RVA : 0x008AC364
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_233998()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$233999
// EA  : 0x828AC38C
// RVA : 0x008AC38C
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_233999()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 168), tag: TAG_DECL);
}


// ========================================================================
// ?FreeData@idMaterial@@UAAXXZ
// EA  : 0x828AC3B8
// RVA : 0x008AC3B8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::FreeData(idMaterial *this)
{
  idMaterialMap *materialMap; // r31

  materialMap = this->materialMap;
  if ( materialMap != nullptr )
  {
    idMaterialMap::~idMaterialMap(this: this->materialMap);
    idMem::Free(this: &mem, ptr: materialMap, align: ALIGN_16);
  }
  idMaterial::Clear(this);
}


// ========================================================================
// ?Parse@idMaterial@@UAAXAAVidParser@@@Z
// EA  : 0x828AC420
// RVA : 0x008AC420
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::Parse(idMaterial *this, idParser *src)
{
  char v4; // r29
  const idDeclRenderProg *Program; // r3
  char v6; // r7
  char *String; // r3
  idResource *v8; // r3
  float v9; // r8
  float v10; // r7
  float v11; // r6
  double v12; // fp13
  double w; // fp9
  double x; // fp8
  double y; // fp7
  double z; // fp1
  char *v21; // r3
  idResource *v22; // r3
  int nextOnHashChain; // r4
  int trackedMemory; // r7
  int str; // r6
  double v26; // fp0
  double v27; // fp13
  double v28; // fp9
  double v29; // fp8
  double v30; // fp7
  double v33; // fp1
  const idDeclRenderProg *v36; // r3
  const idDeclRenderProg *v37; // r11
  const idDeclRenderProg *v38; // r3
  const char *v39; // r4
  const idDeclRenderProg *v40; // r3
  const char *v41; // r4
  const idDeclRenderProg *v42; // r3
  const idDeclRenderProg **v43; // r28
  const idDeclRenderProg *v44; // r3
  const idDeclRenderProg **progs; // r20
  const char *v46; // r4
  const idDeclRenderProg *v47; // r11
  const idDeclRenderProg *v48; // r11
  const idDeclRenderProg *v49; // r11
  const idDeclRenderProg *v50; // r11
  const idDeclRenderProg *v51; // r11
  const idDeclRenderProg *v52; // r11
  int i; // ctr
  int v54; // r11
  int v55; // r11
  __int64 v56; // r10
  char v57; // r11
  bool v58; // zf
  const idDeclRenderProg *v59; // r11
  unsigned __int64 glState; // r10
  char v61; // r11
  const idDeclRenderProg *v62; // r11
  const idDeclRenderProg *v63; // r11
  unsigned __int64 v64; // r10
  char v65; // r11
  const idDeclRenderProg *v66; // r11
  const idDeclRenderProg *v67; // r11
  unsigned __int64 v68; // r10
  char v69; // r11
  char v70; // r29
  int v71; // r10
  char v72; // r11
  int v73; // r11
  __int64 v74; // r10
  materialCoverage_t coverage; // r11
  autospriteType_t materialAutospriteType; // r11
  const char *v77; // r4
  const idDeclRenderProg *v78; // r3
  const char *v79; // r3
  const char *v80; // r3
  int Integer; // r3
  idVec4 *Vector; // r3
  int v83; // r28
  const idDeclRenderProg **v84; // r29
  int v85; // r28
  const idDeclRenderProg **v86; // r29
  pageSource_t pageSource; // r11
  idImage *pageTableImage; // r5
  const idDeclRenderParm *v89; // r4
  const idDeclRenderParm *r; // r29
  idVec4 *FeedbackVec4; // r3
  double v92; // fp13
  double v93; // fp12
  double v94; // fp11
  parmValue_t v95; // [sp+50h] [-150h] BYREF
  parmValue_t v96; // [sp+60h] [-140h] BYREF
  idToken v97; // [sp+70h] [-130h] BYREF
  idParmBlock v98; // [sp+C0h] [-E0h] BYREF
  idParmBlock v99[4]; // [sp+F0h] [-B0h] BYREF

  v97.len = 0;
  v97.allocedAndFlag = 20;
  v97.floatvalue = -3.4028235e38;
  v97.data = v97.baseBuffer;
  v97.baseBuffer[0] = 0;
  v97.intvalue = 0;
  memset(&v97.whiteSpaceStart_p, 0, 12);
  if ( idParser::ExpectAnyToken(this: src, token: &v97) == 0
    || idStr::Icmp(s1: v97.data, s2: "materialmap") == 0
    && ((unsigned __int8)idMaterial::ParseMaterialMap(this, src) == 0
     || idParser::ExpectAnyToken(this: src, token: &v97) == 0) )
  {
    goto LABEL_183;
  }
  v4 = 0;
  if ( idStr::Cmp(s1: v97.data, s2: "{") != 0 )
    idParser::UnreadToken(this: src, token: &v97);
  else
    v4 = 1;
  idParmBlock::Parse(this: &this->parmBlock, src);
  if ( idParser::HadWarning(this: src) )
  {
    idLib::Warning(
      fmt: "idMaterial::Parse: Material %s had parmblock parse warning, ill-formed material may result!!",
      this->name.str);
    goto LABEL_183;
  }
  if ( v4 != 0 )
  {
    idParser::ReadToken(this: src, token: &v97);
    if ( idStr::Cmp(s1: v97.data, s2: "}") != 0 )
    {
      idLib::Warning(
        fmt: "idMaterial::Parse: Material %s missing a brace, ill-formed material may result!!",
        this->name.str);
      goto LABEL_183;
    }
  }
  idParmBlock::idParmBlock(this: &v98, other: &this->parmBlock);
  Program = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_stageProgram.r);
  this->progs[6] = Program;
  if ( Program != nullptr
    || (Program = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_ambientProgram.r),
        this->progs[0] = Program,
        Program != nullptr) )
  {
    idParmBlock::Append(this: &v98, block: &Program->parmBlock);
  }
  *((_BYTE *)this + 72) = ((idParmBlock::GetFloat(this: &v98, parm: (const idDeclRenderParm *)rp_NoShadows.r) == 0.0) << 7)
                        | *((_BYTE *)this + 72) & 0x7F;
  this->materialAutospriteType = (int)idParmBlock::GetFloat(
                                        this: &v98,
                                        parm: (const idDeclRenderParm *)rp_autoSpriteType.r);
  this->materialDecalProjType = (int)idParmBlock::GetFloat(
                                       this: &v98,
                                       parm: (const idDeclRenderParm *)rp_decalProjType.r);
  *((_BYTE *)this + 73) = (32
                         * (idParmBlock::GetFloat(this: &v98, parm: (const idDeclRenderParm *)rp_useClipSpheres.r) == 1.0))
                        & 0x20
                        | *((_BYTE *)this + 73) & 0xDF;
  if ( idParser::HadWarning(this: src) )
  {
    idLib::Warning(
      fmt: "idMaterial::Parse: Material %s had parse warning, ill-formed material may result!!",
      this->name.str);
    idParmBlock::~idParmBlock(this: &v98);
    goto LABEL_183;
  }
  v6 = (8 * idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_transSortMap.r)) & 8
     | *((_BYTE *)this + 72) & 0xF7;
  *((_BYTE *)this + 72) = v6;
  if ( (v6 & 8) != 0 )
  {
    String = (char *)idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_transSortMap.r);
    v8 = idResourceList::Load(
           this: &idAtlasResource::resourceList,
           name: String,
           makeDefault: true,
           skipStaleCheck: false);
    v95.swizzle[0] = (int)&this->atlasScaleBias;
    v9 = *(float *)&v8[1].name.str;
    v10 = *(float *)&v8[1].nextOnHashChain;
    v11 = *(float *)&v8[1].resourceListPtr;
    v95.swizzle[0] = v8[1].trackedMemory;
    v95.value[1] = v9;
    v95.value[2] = v10;
    v95.value[3] = v11;
    v12 = v95.value[0];
    this->atlasScaleBias.w = v11;
    this->atlasScaleBias.z = v10;
    this->atlasScaleBias.x = v12;
    this->atlasScaleBias.y = v9;
    *((_BYTE *)this + 72) |= 4u;
    w = this->atlasScaleBias.w;
    x = this->atlasScaleBias.x;
    y = this->atlasScaleBias.y;
    v95.value[2] = this->atlasScaleBias.z;
    v95.value[1] = y;
    v95.value[0] = x;
    v95.value[3] = w;
    idParmBlock::SetParm(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_transAtlasScaleBias.r,
      parmValue: &v95);
    _FP4 = (float)(this->atlasScaleBias.y - (float)0.000001);
    _FP3 = (float)(this->atlasScaleBias.x - (float)0.000001);
    z = this->atlasScaleBias.z;
    v95.value[3] = this->atlasScaleBias.w;
    v95.value[2] = z;
    __asm
    {
      fsel      f0, f4, f6, f31
      fsel      f13, f3, f5, f31
    }
    v95.value[1] = (float)1.0 / (float)_FP0;
    v95.value[0] = (float)1.0 / (float)_FP13;
    idParmBlock::SetParm(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_transAtlasScaleBiasInv.r,
      parmValue: &v95);
  }
  if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_transAtlasMap.r) )
  {
    v21 = (char *)idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_transAtlasMap.r);
    v22 = idResourceList::Load(
            this: &idAtlasResource::resourceList,
            name: v21,
            makeDefault: true,
            skipStaleCheck: false);
    v95.swizzle[0] = (int)&this->atlasScaleBias;
    nextOnHashChain = (int)v22[1].nextOnHashChain;
    trackedMemory = v22[1].trackedMemory;
    str = (int)v22[1].name.str;
    v95.swizzle[3] = (int)v22[1].resourceListPtr;
    v95.swizzle[2] = nextOnHashChain;
    v95.swizzle[0] = trackedMemory;
    v95.swizzle[1] = str;
    this->atlasScaleBias.w = v95.value[3];
    v26 = v95.value[2];
    v27 = v95.value[1];
    this->atlasScaleBias.x = v95.value[0];
    this->atlasScaleBias.y = v27;
    this->atlasScaleBias.z = v26;
    *((_BYTE *)this + 72) |= 4u;
    idParmBlock::SetImage(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_transMap.r,
      image: globalImages->transSortImageAtlas->atlas);
    v28 = this->atlasScaleBias.y;
    v29 = this->atlasScaleBias.z;
    v30 = this->atlasScaleBias.w;
    v96.value[0] = this->atlasScaleBias.x;
    v95.swizzle[0] = (int)&this->atlasScaleBias;
    v96.value[1] = v28;
    v96.value[2] = v29;
    v96.value[3] = v30;
    idParmBlock::SetParm(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_transAtlasScaleBias.r,
      parmValue: &v96);
    _FP4 = (float)(this->atlasScaleBias.y - (float)0.000001);
    _FP3 = (float)(this->atlasScaleBias.x - (float)0.000001);
    v33 = this->atlasScaleBias.z;
    v96.value[3] = this->atlasScaleBias.w;
    v96.value[2] = v33;
    __asm
    {
      fsel      f0, f4, f6, f31
      fsel      f13, f3, f5, f31
    }
    v96.value[1] = (float)1.0 / (float)_FP0;
    v96.value[0] = (float)1.0 / (float)_FP13;
    idParmBlock::SetParm(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_transAtlasScaleBiasInv.r,
      parmValue: &v96);
  }
  if ( this->progs[6] == nullptr
    && (idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_virtualMapping.r)
     || idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_bumpMap.r)
     || idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_diffuseMap.r)) )
  {
    *((_BYTE *)this + 72) |= 0x10u;
  }
  *((_BYTE *)this + 73) = ((idParmBlock::GetInteger(
                              this: &this->parmBlock,
                              parm: (const idDeclRenderParm *)rp_skipSurfaceInfo.r) != 0) << 6)
                        & 0x40
                        | *((_BYTE *)this + 73) & 0xBF;
  *((_BYTE *)this + 73) = ((idParmBlock::GetInteger(
                              this: &this->parmBlock,
                              parm: (const idDeclRenderParm *)rp_allowBlendedPassMerge.r) != 0) << 7)
                        | *((_BYTE *)this + 73) & 0x7F;
  this->progs[4] = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_addProgram.r);
  v36 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_blendProgram.r);
  v37 = this->progs[6];
  this->progs[5] = v36;
  if ( v37 == nullptr && (this->progs[4] != nullptr || v36 != nullptr) )
    *((_BYTE *)this + 72) |= 0x20u;
  v38 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_shadowProgram.r);
  this->progs[2] = v38;
  if ( v38 == nullptr )
  {
    if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_coverMap.r) )
      v39 = "occluderShadowTransVmtr";
    else
      v39 = "occluderShadowVmtr";
    this->progs[2] = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderProg::resourceList,
                                                 name: v39,
                                                 makeDefault: true);
  }
  v40 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_depthFillProgram.r);
  this->progs[3] = v40;
  if ( v40 == nullptr )
  {
    if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_coverMap.r) )
      v41 = "occluderTransVmtr";
    else
      v41 = "occluderVmtr";
    this->progs[3] = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderProg::resourceList,
                                                 name: v41,
                                                 makeDefault: true);
  }
  v42 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_interactionProgram.r);
  v43 = &this->progs[1];
  this->progs[1] = v42;
  if ( v42 != nullptr )
  {
    *((_BYTE *)this + 72) |= 0x10u;
  }
  else if ( (*((_BYTE *)this + 72) & 0x10) != 0 )
  {
    *v43 = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                       this: &idDeclRenderProg::resourceList,
                                       name: "interBasic",
                                       makeDefault: true);
  }
  v44 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_ambientProgram.r);
  progs = this->progs;
  this->progs[0] = v44;
  if ( v44 == nullptr && (*((_BYTE *)this + 72) & 0x10) != 0 && *v43 != nullptr )
  {
    if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_coverMap.r) )
    {
      if ( ((*v43)->glState & 0x8000) != 0 )
        v46 = "outsideTwoSided";
      else
        v46 = "outsideTrans";
    }
    else
    {
      v46 = "outside";
    }
    *progs = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclRenderProg::resourceList,
                                         name: v46,
                                         makeDefault: true);
  }
  if ( *progs != nullptr )
    this->stageSort[0] = (*progs)->stageSort;
  if ( *v43 != nullptr )
    this->stageSort[1] = (*v43)->stageSort;
  v47 = this->progs[2];
  if ( v47 != nullptr )
    this->stageSort[2] = v47->stageSort;
  v48 = this->progs[3];
  if ( v48 != nullptr )
    this->stageSort[3] = v48->stageSort;
  v49 = this->progs[4];
  if ( v49 != nullptr )
    this->stageSort[4] = v49->stageSort;
  v50 = this->progs[5];
  if ( v50 != nullptr )
    this->stageSort[5] = v50->stageSort;
  v51 = this->progs[6];
  if ( v51 != nullptr )
    this->stageSort[6] = v51->stageSort;
  v52 = this->progs[7];
  if ( v52 != nullptr )
    this->stageSort[7] = v52->stageSort;
  this->coverage = MC_BAD;
  if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_materialCoverage.r) )
  {
    this->coverage = idParmBlock::GetInteger(
                       this: &this->parmBlock,
                       parm: (const idDeclRenderParm *)rp_materialCoverage.r);
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      v54 = (int)*(v43 - 1);
      if ( v54 != 0 )
      {
        if ( (*(_DWORD *)(v54 + 68) & 0x8000) != 0 )
          *((_BYTE *)this + 72) |= 0x40u;
        v55 = (int)*(v43 - 1);
        v56 = *(_QWORD *)(v55 + 64);
        HIDWORD(v56) = v56 & 0x20038;
        *(_QWORD *)v95.value = v56;
        if ( (v56 & 0x20038) == 0 )
        {
          HIDWORD(v56) = *(unsigned __int8 *)(v55 + 72);
          if ( *(_BYTE *)(v55 + 72) != 0 || (v58 = *(_BYTE *)(v55 + 73) == 0, v57 = 0, !v58) )
            v57 = 1;
          if ( v57 != 0 )
          {
            *(_QWORD *)v95.value = v56;
            if ( (v56 & 0x40) == 0 )
              this->coverage = MC_PERFORATED;
          }
        }
      }
      if ( *v43 != nullptr )
      {
        if ( ((*v43)->glState & 0x8000) != 0 )
          *((_BYTE *)this + 72) |= 0x40u;
        v59 = *v43;
        glState = (*v43)->glState;
        HIDWORD(glState) = glState & 0x20038;
        *(_QWORD *)v95.value = glState;
        if ( (glState & 0x20038) == 0 )
        {
          HIDWORD(glState) = v59->hasClip;
          if ( v59->hasClip || (v58 = !v59->hasAlphaToCoverage, v61 = 0, !v58) )
            v61 = 1;
          if ( v61 != 0 )
          {
            *(_QWORD *)v95.value = glState;
            if ( (glState & 0x40) == 0 )
              this->coverage = MC_PERFORATED;
          }
        }
      }
      v62 = v43[1];
      if ( v62 != nullptr )
      {
        if ( (v62->glState & 0x8000) != 0 )
          *((_BYTE *)this + 72) |= 0x40u;
        v63 = v43[1];
        v64 = v63->glState;
        HIDWORD(v64) = v64 & 0x20038;
        *(_QWORD *)v95.value = v64;
        if ( (v64 & 0x20038) == 0 )
        {
          HIDWORD(v64) = v63->hasClip;
          if ( v63->hasClip || (v58 = !v63->hasAlphaToCoverage, v65 = 0, !v58) )
            v65 = 1;
          if ( v65 != 0 )
          {
            *(_QWORD *)v95.value = v64;
            if ( (v64 & 0x40) == 0 )
              this->coverage = MC_PERFORATED;
          }
        }
      }
      v66 = v43[2];
      if ( v66 != nullptr )
      {
        if ( (v66->glState & 0x8000) != 0 )
          *((_BYTE *)this + 72) |= 0x40u;
        v67 = v43[2];
        v68 = v67->glState;
        HIDWORD(v68) = v68 & 0x20038;
        *(_QWORD *)v95.value = v68;
        if ( (v68 & 0x20038) == 0 )
        {
          HIDWORD(v68) = v67->hasClip;
          if ( v67->hasClip || (v58 = !v67->hasAlphaToCoverage, v69 = 0, !v58) )
            v69 = 1;
          if ( v69 != 0 )
          {
            *(_QWORD *)v95.value = v68;
            if ( (v68 & 0x40) == 0 )
              this->coverage = MC_PERFORATED;
          }
        }
      }
      v43 += 4;
    }
  }
  v70 = 0;
  v71 = (*((_BYTE *)this + 72) & 0x10) != 0;
  if ( (*((_BYTE *)this + 72) & 0x10) != 0 && *progs != nullptr )
  {
    *(_QWORD *)v95.value = (*progs)->glState;
    v71 = v95.swizzle[0];
    if ( (v95.swizzle[1] & 0x20038) == 0 || (v72 = 0, (v95.swizzle[1] & 0x8000) != 0) )
      v72 = 1;
    v70 = v72;
  }
  if ( this->coverage == MC_BAD )
  {
    if ( v71 != 0
      && !idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_coverMap.r)
      && v70 != 0 )
    {
      this->coverage = MC_OPAQUE;
    }
    else
    {
      this->coverage = (*((unsigned __int8 *)this + 72) >> 3) & 2 | 1;
      if ( idParmBlock::GetFloat(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_If.r) != 0.0 )
      {
        v95.swizzle[0] = (int)this->progs[6];
        v73 = v95.swizzle[0];
        if ( v95.swizzle[0] != 0 )
        {
          if ( (*(_DWORD *)(v95.swizzle[0] + 68) & 0x20038) != 0
            || (this->coverage = MC_OPAQUE, this->stageSort[6] != *(float *)&rp_stageSortCoverage.r[2].__vftable)
            && (v74 = *(_QWORD *)(v73 + 64), v95.swizzle[0] = v73, (v74 & 0x40) != 0) )
          {
            this->coverage = MC_TRANSLUCENT;
          }
        }
      }
    }
  }
  coverage = this->coverage;
  if ( coverage == MC_INVISIBLE )
  {
    this->progs[2] = nullptr;
    this->progs[3] = nullptr;
    this->progs[7] = nullptr;
  }
  else if ( coverage == MC_TRANSLUCENT )
  {
    materialAutospriteType = this->materialAutospriteType;
    this->progs[2] = nullptr;
    if ( materialAutospriteType == AUTOSPRITE_VIEW_ORIENTED )
    {
      v77 = "occluderQueryOnlyAutosprite1";
    }
    else if ( materialAutospriteType == AUTOSPRITE_LONGEST_AXIS_ALIGNED )
    {
      v77 = "occluderQueryOnlyAutosprite2";
    }
    else
    {
      if ( idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_depthFillProgram.r) != nullptr )
        goto LABEL_141;
      v77 = "occluderQueryOnly";
    }
    this->progs[3] = (const idDeclRenderProg *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclRenderProg::resourceList,
                                                 name: v77,
                                                 makeDefault: true);
  }
LABEL_141:
  if ( this->progs[3] != nullptr )
  {
    v78 = idParmBlock::GetProgram(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_fadePerturbProgram.r);
    this->progs[7] = v78;
    if ( v78 == nullptr )
      this->progs[7] = idParmBlock::GetProgram(
                         this: &this->progs[3]->parmBlock,
                         parm: (const idDeclRenderParm *)rp_fadePerturbProgram.r);
  }
  v79 = idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_landDefinitionFile.r);
  if ( v79 != nullptr && *v79 != 0 )
    this->pageSource = PAGESOURCE_UNIQUE;
  else
    this->pageSource = PAGESOURCE_VMTR;
  v80 = idParmBlock::GetString(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_landPageFile.r);
  this->pageFileName = v80;
  if ( v80 == nullptr || *v80 == 0 )
    this->pageFileName = virtualTextureSystem.vts[1].baseName.data;
  if ( this->pageSource <= PAGESOURCE_VMTR )
  {
    this->physicalPagesPool = PHYSICAL_PAGES_POOL_VMTR;
  }
  else
  {
    Integer = idParmBlock::GetInteger(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_landDiffuseOnly.r);
    if ( Integer == 1 )
    {
      this->physicalPagesPool = PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY;
    }
    else if ( Integer == 2 )
    {
      this->physicalPagesPool = PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2;
    }
    else
    {
      this->physicalPagesPool = PHYSICAL_PAGES_POOL_UNIQUE;
    }
  }
  if ( idStr::Cmpn(s1: this->name.str, s2: "generic", n: 7) != 0 )
  {
    if ( idParmBlock::SetsRenderParm(this: &this->parmBlock, parm: (const idDeclRenderParm *)rp_virtualMapping.r) )
    {
      Vector = idParmBlock::GetVector(
                 this: v99,
                 result: (idVec4 *)&this->parmBlock,
                 parm: (const idDeclRenderParm *)rp_virtualMapping.r);
      this->virtualMapping.x = Vector->x;
      v96.value[3] = 1.0;
      v96.value[2] = 1.0;
      this->virtualMapping.y = Vector->y;
      v95.swizzle[0] = (int)&this->virtualMapping;
      this->virtualMapping.z = Vector->z;
      this->virtualMapping.w = Vector->w;
      v96.value[1] = 1.0;
      v96.value[0] = 1.0;
      idParmBlock::SetParm(
        this: &this->parmBlock,
        parm: (const idDeclRenderParm *)rp_useVirtualMapping.r,
        parmValue: &v96);
    }
    else if ( idLib::production < PROD_PRODUCTION )
    {
      this->devVmtr = idVirtualTextureSystem::VirtualMaterialForMaterial(this: &virtualTextureSystem, mtr: this);
      idMaterial::UpdateVirtualMapping(this);
    }
  }
  else
  {
    if ( idLib::production != PROD_BUILDING )
      idParmBlock::Clear(this: &this->parmBlock);
    this->coverage = MC_OPAQUE;
  }
  v83 = 0;
  v84 = this->progs;
  *((_BYTE *)this + 72) &= ~2u;
  while ( *v84 == nullptr
       || !idDeclRenderProg::ProgUsesParm(this: *v84, parm: (const idDeclRenderParm *)rp_primeLightDir.r)
       && !idDeclRenderProg::ProgUsesParm(this: *v84, parm: (const idDeclRenderParm *)rp_channelLight0.r) )
  {
    ++v83;
    ++v84;
    if ( v83 >= 8 )
      goto LABEL_173;
  }
  *((_BYTE *)this + 72) |= 2u;
LABEL_173:
  v85 = 0;
  v86 = this->progs;
  *((_BYTE *)this + 72) &= ~1u;
  while ( *v86 == nullptr
       || !idDeclRenderProg::ProgUsesParm(this: *v86, parm: (const idDeclRenderParm *)rp_wrinkleFactor0.r) )
  {
    ++v85;
    ++v86;
    if ( v85 >= 8 )
      goto LABEL_179;
  }
  *((_BYTE *)this + 72) |= 1u;
LABEL_179:
  pageSource = this->pageSource;
  if ( pageSource <= PAGESOURCE_VMTR )
  {
    r = (const idDeclRenderParm *)rp_virtualTextureFeedbackFloat.r;
    FeedbackVec4 = idVirtualTexture::GetFeedbackVec4(
                     this: (idVirtualTexture *)v99,
                     result: (idVec4 *)&virtualTextureSystem.vts[pageSource]);
    v92 = FeedbackVec4->y;
    v93 = FeedbackVec4->z;
    v94 = FeedbackVec4->w;
    v96.value[0] = FeedbackVec4->x;
    v96.value[1] = v92;
    v96.value[2] = v93;
    v96.value[3] = v94;
    idParmBlock::SetParm(this: &this->parmBlock, parm: r, parmValue: &v96);
    v89 = (const idDeclRenderParm *)rp_pageTableMap.r;
    pageTableImage = virtualTextureSystem.vts[this->pageSource].pageTableImage;
  }
  else
  {
    v96.value[0] = 0.0;
    v96.value[1] = 0.0;
    v96.value[2] = 0.0;
    v96.value[3] = 0.0;
    idParmBlock::SetParm(
      this: &this->parmBlock,
      parm: (const idDeclRenderParm *)rp_virtualTextureFeedbackFloat.r,
      parmValue: &v96);
    pageTableImage = globalImages->defaultImage;
    v89 = (const idDeclRenderParm *)rp_pageTableMap.r;
  }
  idParmBlock::SetImage(this: &this->parmBlock, parm: v89, image: pageTableImage);
  idMaterial::OptimizeRenderParmBlock(this);
  idParmBlock::~idParmBlock(this: &v98);
LABEL_183:
  idStr::FreeData(this: &v97);
}


// ========================================================================
// __unwind$234287
// EA  : 0x828AD4A4
// RVA : 0x008AD4A4
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_234287()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 112));
}


// ========================================================================
// __unwind$234288
// EA  : 0x828AD4CC
// RVA : 0x008AD4CC
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_234288()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(v0 - 416 + 192));
}


// ========================================================================
// ??1idMaterial@@UAA@XZ
// EA  : 0x828AD500
// RVA : 0x008AD500
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __fastcall idMaterial::~idMaterial(idMaterial *this)
{
  idVirtualMaterial *devVmtr; // r11
  idMaterialMap *materialMap; // r29

  this->__vftable = (idMaterial_vtbl *)&idMaterial::`vftable';
  devVmtr = this->devVmtr;
  if ( devVmtr != nullptr )
    devVmtr->material = nullptr;
  materialMap = this->materialMap;
  if ( materialMap != nullptr )
  {
    idMaterialMap::~idMaterialMap(this: this->materialMap);
    idMem::Free(this: &mem, ptr: materialMap, align: ALIGN_16);
  }
  idMaterial::Clear(this);
  idParmBlock::~idParmBlock(this: &this->renderParmBlock);
  idParmBlock::~idParmBlock(this: &this->parmBlock);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$235437
// EA  : 0x828AD588
// RVA : 0x008AD588
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_235437()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$235438
// EA  : 0x828AD5B0
// RVA : 0x008AD5B0
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_235438()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$235439
// EA  : 0x828AD5DC
// RVA : 0x008AD5DC
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _unwind_235439()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(*(_DWORD *)(v0 - 112 + 132) + 124));
}


// ========================================================================
// `dynamic initializer for 'rp_stageProgram''
// EA  : 0x8334B208
// RVA : 0x0134B208
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_stageProgram__()
{
  rp_stageProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_stageProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_stageSort''
// EA  : 0x8334B228
// RVA : 0x0134B228
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_stageSort__()
{
  rp_stageSort.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_stageSort;
}


// ========================================================================
// `dynamic initializer for 'rp_stageSortCoverage''
// EA  : 0x8334B248
// RVA : 0x0134B248
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_stageSortCoverage__()
{
  rp_stageSortCoverage.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_stageSortCoverage;
}


// ========================================================================
// `dynamic initializer for 'rp_NoShadows''
// EA  : 0x8334B268
// RVA : 0x0134B268
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_NoShadows__()
{
  rp_NoShadows.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_NoShadows;
}


// ========================================================================
// `dynamic initializer for 'rp_allowBlendedPassMerge''
// EA  : 0x8334B288
// RVA : 0x0134B288
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_allowBlendedPassMerge__()
{
  rp_allowBlendedPassMerge.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_allowBlendedPassMerge;
}


// ========================================================================
// `dynamic initializer for 'rp_useClipSpheres''
// EA  : 0x8334B2A8
// RVA : 0x0134B2A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_useClipSpheres__()
{
  rp_useClipSpheres.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_useClipSpheres;
}


// ========================================================================
// `dynamic initializer for 'rp_autoSpriteType''
// EA  : 0x8334B2C8
// RVA : 0x0134B2C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_autoSpriteType__()
{
  rp_autoSpriteType.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_autoSpriteType;
}


// ========================================================================
// `dynamic initializer for 'rp_decalProjType''
// EA  : 0x8334B2E8
// RVA : 0x0134B2E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_decalProjType__()
{
  rp_decalProjType.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_decalProjType;
}


// ========================================================================
// `dynamic initializer for 'rp_discrete''
// EA  : 0x8334B308
// RVA : 0x0134B308
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_discrete__()
{
  rp_discrete.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_discrete;
}


// ========================================================================
// `dynamic initializer for 'rp_diffuseMap''
// EA  : 0x8334B328
// RVA : 0x0134B328
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_diffuseMap__()
{
  rp_diffuseMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_diffuseMap;
}


// ========================================================================
// `dynamic initializer for 'rp_specularMap''
// EA  : 0x8334B348
// RVA : 0x0134B348
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_specularMap__()
{
  rp_specularMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_specularMap;
}


// ========================================================================
// `dynamic initializer for 'rp_bumpMap''
// EA  : 0x8334B368
// RVA : 0x0134B368
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_bumpMap__()
{
  rp_bumpMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_bumpMap;
}


// ========================================================================
// `dynamic initializer for 'rp_coverMap''
// EA  : 0x8334B388
// RVA : 0x0134B388
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_coverMap__()
{
  rp_coverMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_coverMap;
}


// ========================================================================
// `dynamic initializer for 'rp_powerMap''
// EA  : 0x8334B3A8
// RVA : 0x0134B3A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_powerMap__()
{
  rp_powerMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_powerMap;
}


// ========================================================================
// `dynamic initializer for 'rp_virtualTransMap''
// EA  : 0x8334B3C8
// RVA : 0x0134B3C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_virtualTransMap__()
{
  rp_virtualTransMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_virtualTransMap;
}


// ========================================================================
// `dynamic initializer for 'rp_transMap''
// EA  : 0x8334B3E8
// RVA : 0x0134B3E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transMap__()
{
  rp_transMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transMap;
}


// ========================================================================
// `dynamic initializer for 'rp_transSortMap''
// EA  : 0x8334B408
// RVA : 0x0134B408
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transSortMap__()
{
  rp_transSortMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transSortMap;
}


// ========================================================================
// `dynamic initializer for 'rp_transAtlasMap''
// EA  : 0x8334B428
// RVA : 0x0134B428
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transAtlasMap__()
{
  rp_transAtlasMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transAtlasMap;
}


// ========================================================================
// `dynamic initializer for 'rp_transAtlasScaleBias''
// EA  : 0x8334B448
// RVA : 0x0134B448
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transAtlasScaleBias__()
{
  rp_transAtlasScaleBias.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transAtlasScaleBias;
}


// ========================================================================
// `dynamic initializer for 'rp_transAtlasScaleBiasInv''
// EA  : 0x8334B468
// RVA : 0x0134B468
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_transAtlasScaleBiasInv__()
{
  rp_transAtlasScaleBiasInv.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_transAtlasScaleBiasInv;
}


// ========================================================================
// `dynamic initializer for 'rp_skipSurfaceInfo''
// EA  : 0x8334B488
// RVA : 0x0134B488
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_skipSurfaceInfo__()
{
  rp_skipSurfaceInfo.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_skipSurfaceInfo;
}


// ========================================================================
// `dynamic initializer for 'rp_addProgram''
// EA  : 0x8334B4A8
// RVA : 0x0134B4A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_addProgram__()
{
  rp_addProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_addProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_blendProgram''
// EA  : 0x8334B4C8
// RVA : 0x0134B4C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_blendProgram__()
{
  rp_blendProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_blendProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_shadowProgram''
// EA  : 0x8334B4E8
// RVA : 0x0134B4E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_shadowProgram__()
{
  rp_shadowProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_shadowProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_depthFillProgram''
// EA  : 0x8334B508
// RVA : 0x0134B508
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_depthFillProgram__()
{
  rp_depthFillProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_depthFillProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_interactionProgram''
// EA  : 0x8334B528
// RVA : 0x0134B528
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_interactionProgram__()
{
  rp_interactionProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_interactionProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_ambientProgram''
// EA  : 0x8334B548
// RVA : 0x0134B548
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_ambientProgram__()
{
  rp_ambientProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_ambientProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_fadePerturbProgram''
// EA  : 0x8334B568
// RVA : 0x0134B568
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_fadePerturbProgram__()
{
  rp_fadePerturbProgram.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_fadePerturbProgram;
}


// ========================================================================
// `dynamic initializer for 'rp_If''
// EA  : 0x8334B588
// RVA : 0x0134B588
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_If__()
{
  rp_If.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_If;
}


// ========================================================================
// `dynamic initializer for 'rp_landDefinitionFile''
// EA  : 0x8334B5A8
// RVA : 0x0134B5A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landDefinitionFile__()
{
  rp_landDefinitionFile.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landDefinitionFile;
}


// ========================================================================
// `dynamic initializer for 'rp_materialCoverage''
// EA  : 0x8334B5C8
// RVA : 0x0134B5C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_materialCoverage__()
{
  rp_materialCoverage.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_materialCoverage;
}


// ========================================================================
// `dynamic initializer for 'rp_virtualMapping''
// EA  : 0x8334B5E8
// RVA : 0x0134B5E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_virtualMapping__()
{
  rp_virtualMapping.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_virtualMapping;
}


// ========================================================================
// `dynamic initializer for 'rp_primeLightDir''
// EA  : 0x8334B608
// RVA : 0x0134B608
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_primeLightDir__()
{
  rp_primeLightDir.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_primeLightDir;
}


// ========================================================================
// `dynamic initializer for 'rp_channelLight0''
// EA  : 0x8334B628
// RVA : 0x0134B628
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_channelLight0__()
{
  rp_channelLight0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_channelLight0;
}


// ========================================================================
// `dynamic initializer for 'rp_virtualTextureFeedbackFloat''
// EA  : 0x8334B648
// RVA : 0x0134B648
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_virtualTextureFeedbackFloat__()
{
  rp_virtualTextureFeedbackFloat.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_virtualTextureFeedbackFloat;
}


// ========================================================================
// `dynamic initializer for 'rp_pageTableMap''
// EA  : 0x8334B668
// RVA : 0x0134B668
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_pageTableMap__()
{
  rp_pageTableMap.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_pageTableMap;
}


// ========================================================================
// `dynamic initializer for 'rp_useVirtualMapping''
// EA  : 0x8334B688
// RVA : 0x0134B688
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_useVirtualMapping__()
{
  rp_useVirtualMapping.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_useVirtualMapping;
}


// ========================================================================
// `dynamic initializer for 'rp_useSkinBlending''
// EA  : 0x8334B6A8
// RVA : 0x0134B6A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_useSkinBlending__()
{
  rp_useSkinBlending.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_useSkinBlending;
}


// ========================================================================
// `dynamic initializer for 'rp_editorImage''
// EA  : 0x8334B6C8
// RVA : 0x0134B6C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_editorImage__()
{
  rp_editorImage.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_editorImage;
}


// ========================================================================
// `dynamic initializer for 'rp_landDimensions''
// EA  : 0x8334B6E8
// RVA : 0x0134B6E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landDimensions__()
{
  rp_landDimensions.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landDimensions;
}


// ========================================================================
// `dynamic initializer for 'rp_landPageFile''
// EA  : 0x8334B708
// RVA : 0x0134B708
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landPageFile__()
{
  rp_landPageFile.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landPageFile;
}


// ========================================================================
// `dynamic initializer for 'rp_landDiffuseOnly''
// EA  : 0x8334B728
// RVA : 0x0134B728
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_landDiffuseOnly__()
{
  rp_landDiffuseOnly.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_landDiffuseOnly;
}


// ========================================================================
// `dynamic initializer for 'rp_lightColor''
// EA  : 0x8334B748
// RVA : 0x0134B748
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightColor__()
{
  rp_lightColor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightColor;
}


// ========================================================================
// `dynamic initializer for 'rp_lightRotation''
// EA  : 0x8334B768
// RVA : 0x0134B768
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightRotation__()
{
  rp_lightRotation.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightRotation;
}


// ========================================================================
// `dynamic initializer for 'rp_lightTranslation''
// EA  : 0x8334B788
// RVA : 0x0134B788
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightTranslation__()
{
  rp_lightTranslation.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightTranslation;
}


// ========================================================================
// `dynamic initializer for 'rp_lightScale''
// EA  : 0x8334B7A8
// RVA : 0x0134B7A8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightScale__()
{
  rp_lightScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightScale;
}


// ========================================================================
// `dynamic initializer for 'rp_lightOscillationAmp''
// EA  : 0x8334B7C8
// RVA : 0x0134B7C8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightOscillationAmp__()
{
  rp_lightOscillationAmp.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightOscillationAmp;
}


// ========================================================================
// `dynamic initializer for 'rp_lightOscillationFreq''
// EA  : 0x8334B7E8
// RVA : 0x0134B7E8
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightOscillationFreq__()
{
  rp_lightOscillationFreq.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightOscillationFreq;
}


// ========================================================================
// `dynamic initializer for 'rp_lightOscillationPhase''
// EA  : 0x8334B808
// RVA : 0x0134B808
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void _dynamic_initializer_for__rp_lightOscillationPhase__()
{
  rp_lightOscillationPhase.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_lightOscillationPhase;
}


// ========================================================================
// `dynamic initializer for 'r_useHardwareTextures''
// EA  : 0x8334B828
// RVA : 0x0134B828
// PDB : w:\tech5\engine\renderer\declmaterial.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useHardwareTextures__()
{
  idCVar::idCVar(
    this: &r_useHardwareTextures,
    name: "r_useHardwareTextures",
    value: "0",
    flags: 1,
    description: "Use hardware textures instead of virtual textures for implicit gui images",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useHardwareTextures__);
}

