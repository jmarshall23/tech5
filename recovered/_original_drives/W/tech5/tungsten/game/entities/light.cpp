
// ========================================================================
// ??1idLight@@UAA@XZ
// EA  : 0x82C6A2C8
// RVA : 0x00C6A2C8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::~idLight(idLight *this)
{
  idRenderLight *renderLight; // r3

  this->__vftable = (idLight_vtbl *)&idLight::`vftable';
  renderLight = this->renderLight;
  if ( renderLight != nullptr )
  {
    idRenderLight::Delete(this: renderLight);
    this->renderLight = nullptr;
  }
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488618
// EA  : 0x82C6A32C
// RVA : 0x00C6A32C
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _unwind_488618()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetColor@idLight@@UBAXAAVidColor@@@Z
// EA  : 0x82C6A358
// RVA : 0x00C6A358
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::GetColor(idLight *this, idColor *out)
{
  *out = this->lightColor;
}


// ========================================================================
// ?SetColor@idLight@@UAAXABVidVec4@@@Z
// EA  : 0x82C6A380
// RVA : 0x00C6A380
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetColor(idLight *this, idColor *color)
{
  this->lightColor = *color;
}


// ========================================================================
// ?PlaySound@idLight@@QAAX_N@Z
// EA  : 0x82C6A3A8
// RVA : 0x00C6A3A8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::PlaySound(idLight *this, bool play)
{
  const idSoundShader *shader; // r5
  bool v4; // r11

  if ( play && (shader = this->soundInfo.shader) != nullptr )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v4 = false;
  }
  else
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
    v4 = true;
  }
  this->soundWasPlaying = v4;
}


// ========================================================================
// ?UpdateModifiedProperties@idLight@@UAAXXZ
// EA  : 0x82C6A418
// RVA : 0x00C6A418
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::UpdateModifiedProperties(idLight *this)
{
  const idSoundShader *shader; // r5

  idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  shader = this->soundInfo.shader;
  this->soundWasPlaying = true;
  if ( shader != nullptr )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    this->soundWasPlaying = false;
  }
  else
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
    this->soundWasPlaying = true;
  }
}


// ========================================================================
// ?GetCastShadows@idEditorLightInterface@@UBA_NXZ
// EA  : 0x82C6A498
// RVA : 0x00C6A498
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

BOOL __fastcall idEditorLightInterface::GetCastShadows(idEditorLightInterface *this)
{
  idLight *v1; // r3
  idLight *v2; // r3

  v1 = (idLight *)this->GetEntity(this);
  v2 = idLight::CastTo(c: v1);
  return v2 == nullptr || (_cntlzw(v2->noShadows) & 0x20) != 0;
}


// ========================================================================
// ?GetLightSpotlight@idEditorLightInterface@@UBA_NXZ
// EA  : 0x82C6A4F0
// RVA : 0x00C6A4F0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

BOOL __fastcall idEditorLightInterface::GetLightSpotlight(idEditorLightInterface *this)
{
  idLight *v1; // r3
  idLight *v2; // r3

  v1 = (idLight *)this->GetEntity(this);
  v2 = idLight::CastTo(c: v1);
  return v2 != nullptr && (_cntlzw(v2->lightType - 1) & 0x20) != 0;
}


// ========================================================================
// ?GetLightParallel@idEditorLightInterface@@UBA_NXZ
// EA  : 0x82C6A550
// RVA : 0x00C6A550
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

BOOL __fastcall idEditorLightInterface::GetLightParallel(idEditorLightInterface *this)
{
  idLight *v1; // r3
  idLight *v2; // r3

  v1 = (idLight *)this->GetEntity(this);
  v2 = idLight::CastTo(c: v1);
  return v2 != nullptr && (_cntlzw(v2->lightType - 2) & 0x20) != 0;
}


// ========================================================================
// ?SetLightClass@idEditorLightInterface@@UAAXW4lightClass_t@@@Z
// EA  : 0x82C6A5B0
// RVA : 0x00C6A5B0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightClass(idEditorLightInterface *this, lightClass_t lightClass)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
    v4->lightClass = lightClass;
}


// ========================================================================
// ?InitRenderLight@idLight@@QAAXXZ
// EA  : 0x82C6A5F8
// RVA : 0x00C6A5F8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::InitRenderLight(idLight *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  float *v4; // r3
  double v5; // fp31
  double v6; // fp30
  double v7; // fp29
  float *v8; // r3
  idRenderLight *renderLight; // r11
  double v10; // fp3
  double v11; // fp2
  idPhysics *v12; // r3
  idMat3 *v13; // r3
  idMat3 *v14; // r3
  int *v15; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPhysics *v18; // r3
  int v19; // r3
  int *v20; // r10
  _DWORD *v21; // r11
  int j; // ctr
  idRenderLight *v23; // r11
  double y; // fp9
  double z; // fp5
  double v26; // fp2
  double v27; // fp1
  idMat3 *v28; // r3
  int *v29; // r10
  _DWORD *v30; // r11
  int k; // ctr
  int *v32; // r10
  float *v33; // r11
  int m; // ctr
  float *v35; // r11
  double v36; // fp13
  double v37; // fp12
  double v38; // fp11
  double v39; // fp10
  double v40; // fp7
  double v41; // fp6
  idRenderLight *v42; // r11
  float v43; // r8
  float v44; // r10
  double v45; // fp13
  float v46; // r6
  double v47; // fp10
  idRenderLight *v48; // r11
  float v49; // r3
  idRenderLight *v50; // r11
  double v51; // fp6
  float v52; // r8
  double v53; // fp4
  idRenderLight *v54; // r11
  idRenderLight *v55; // r11
  float v56; // r8
  float v57; // r9
  double v58; // fp0
  float x; // r9
  float v60; // r8
  double v61; // fp0
  int v62; // r8
  int v63; // r11
  __int64 v64; // r9
  float v65; // r6
  float v66; // r5
  idRenderLight *v67; // r11
  idRenderLight *v68; // r11
  float v69; // r7
  float v70; // r9
  idRenderLight *v71; // r11
  float v72; // r3
  idRenderLight *v73; // r11
  double v74; // fp7
  int slowMultiPass; // r11
  const idMaterial *lightMaterial; // r11
  int v77; // r3
  const idMaterial *v78; // r10
  const idDeclRenderParm *lightColor; // r30
  idStaticParmBlock<32> *ParmBlock; // r3
  double g; // fp12
  double b; // fp11
  double a; // fp10
  parmValue_t v84; // [sp+50h] [-A0h] BYREF
  float v85; // [sp+60h] [-90h]
  float v86; // [sp+64h] [-8Ch]
  float v87; // [sp+68h] [-88h]
  float v88; // [sp+6Ch] [-84h]
  float v89; // [sp+70h] [-80h]
  float v90; // [sp+74h] [-7Ch]
  float v91; // [sp+78h] [-78h]
  float v92; // [sp+7Ch] [-74h]
  float v93; // [sp+80h] [-70h]
  idMat3 v94; // [sp+90h] [-60h] BYREF

  if ( this->renderLight == nullptr )
    this->renderLight = clientGame->renderWorld->AllocRenderLight(this: clientGame->renderWorld, a2: 0);
  if ( idEntity::GetPhysics(this) != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = idEntity::GetPhysics(this);
    v4 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    v5 = (float)((float)(this->lightOffset.x * *v4)
               + (float)((float)(v4[3] * this->lightOffset.y) + (float)(v4[6] * this->lightOffset.z)));
    v6 = (float)((float)(v4[7] * this->lightOffset.z)
               + (float)((float)(v4[1] * this->lightOffset.x) + (float)(v4[4] * this->lightOffset.y)));
    v7 = (float)((float)(v4[8] * this->lightOffset.z)
               + (float)((float)(v4[2] * this->lightOffset.x) + (float)(v4[5] * this->lightOffset.y)));
    v8 = (float *)v3->GetOrigin(this: v3, a2: 0);
    renderLight = this->renderLight;
    v10 = (float)(v8[1] + (float)v6);
    v11 = (float)(v8[2] + (float)v7);
    renderLight->g.origin.x = *v8 + (float)v5;
    renderLight->g.origin.y = v10;
    renderLight->g.origin.z = v11;
    if ( this->lightType == LIGHT_REAL )
    {
      v12 = idEntity::GetPhysics(this);
      v13 = (idMat3 *)v12->GetAxis(this: v12, a2: 0);
      v14 = idMat3::operator*(this: &v94, result: v13, a: &this->lightOrientation);
      v15 = &v84.swizzle[3];
      p_z = (_DWORD *)&v14[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
        *++v15 = *++p_z;
    }
    else
    {
      v18 = idEntity::GetPhysics(this);
      v19 = (int)v18->GetAxis(this: v18, a2: 0);
      v20 = &v84.swizzle[3];
      v21 = (_DWORD *)(v19 - 4);
      for ( j = 9; j != 0; --j )
        *++v20 = *++v21;
    }
  }
  else
  {
    v23 = this->renderLight;
    y = this->spawnPosition.y;
    z = this->spawnPosition.z;
    v26 = (float)((float)(this->spawnOrientation.mat[2].y * this->lightOffset.z)
                + (float)((float)(this->spawnOrientation.mat[0].y * this->lightOffset.x)
                        + (float)(this->spawnOrientation.mat[1].y * this->lightOffset.y)));
    v27 = (float)((float)(this->spawnOrientation.mat[2].z * this->lightOffset.z)
                + (float)((float)(this->spawnOrientation.mat[0].z * this->lightOffset.x)
                        + (float)(this->spawnOrientation.mat[1].z * this->lightOffset.y)));
    v23->g.origin.x = this->spawnPosition.x
                    + (float)((float)(this->lightOffset.x * this->spawnOrientation.mat[0].x)
                            + (float)((float)(this->spawnOrientation.mat[1].x * this->lightOffset.y)
                                    + (float)(this->spawnOrientation.mat[2].x * this->lightOffset.z)));
    v23->g.origin.y = (float)y + (float)v26;
    v23->g.origin.z = (float)z + (float)v27;
    if ( this->lightType == LIGHT_REAL )
    {
      v28 = idMat3::operator*(this: &v94, result: &this->spawnOrientation, a: &this->lightOrientation);
      v29 = &v84.swizzle[3];
      v30 = (_DWORD *)&v28[-1].mat[2].z;
      for ( k = 9; k != 0; --k )
        *++v29 = *++v30;
    }
    else
    {
      v32 = &v84.swizzle[3];
      v33 = &this->spawnPosition.z;
      for ( m = 9; m != 0; --m )
        *++v32 = *(_DWORD *)++v33;
    }
  }
  v35 = (float *)this->renderLight;
  v36 = v88;
  v37 = v86;
  v38 = v87;
  v39 = v89;
  *v35 = v85;
  v35[3] = v36;
  v35[1] = v37;
  v35[2] = v38;
  v35[4] = v39;
  v35[5] = v90;
  v40 = v92;
  v35[6] = v91;
  v41 = v93;
  v35[7] = v40;
  v35[8] = v41;
  v42 = this->renderLight;
  if ( this->lightType == LIGHT_SPOT )
  {
    v43 = this->spotLight.lightTarget.y;
    v44 = this->spotLight.lightTarget.z;
    v84.swizzle[0] = LODWORD(this->spotLight.lightTarget.x);
    v45 = v84.value[0];
    v84.value[1] = v43;
    v84.value[2] = v44;
    v42->g.target.z = v44;
    v42->g.target.y = v43;
    v42->g.target.x = v45;
    v84.swizzle[0] = LODWORD(this->spotLight.lightUp.x);
    v46 = this->spotLight.lightUp.y;
    v84.swizzle[2] = LODWORD(this->spotLight.lightUp.z);
    v84.value[1] = v46;
    v47 = v84.value[2];
    v48 = this->renderLight;
    v48->g.up.x = v84.value[0];
    v48->g.up.y = v84.value[1];
    v48->g.up.z = v47;
    v84.swizzle[0] = LODWORD(this->spotLight.lightRight.x);
    v49 = this->spotLight.lightRight.z;
    v84.swizzle[1] = LODWORD(this->spotLight.lightRight.y);
    v84.value[2] = v49;
    v50 = this->renderLight;
    v50->g.right.x = v84.value[0];
    v51 = v84.value[2];
    v50->g.right.y = v84.value[1];
    v50->g.right.z = v51;
    v84.swizzle[0] = LODWORD(this->spotLight.lightStart.x);
    v52 = this->spotLight.lightStart.y;
    v84.swizzle[2] = LODWORD(this->spotLight.lightStart.z);
    v84.value[1] = v52;
    v53 = v84.value[2];
    v54 = this->renderLight;
    v54->g.start.x = v84.value[0];
    v54->g.start.y = v84.value[1];
    v54->g.start.z = v53;
    v55 = this->renderLight;
    if ( ((LODWORD(this->spotLight.lightEnd.z)
         | LODWORD(this->spotLight.lightEnd.y)
         | LODWORD(this->spotLight.lightEnd.x))
        & 0x7FFFFFFF) != 0 )
    {
      x = this->spotLight.lightEnd.x;
      v60 = this->spotLight.lightEnd.y;
      v84.swizzle[2] = LODWORD(this->spotLight.lightEnd.z);
      v84.value[0] = x;
      v84.value[1] = v60;
      v61 = v84.value[2];
      v55->g.end.y = v60;
      v55->g.end.x = x;
      v55->g.end.z = v61;
    }
    else
    {
      v56 = this->spotLight.lightTarget.x;
      v57 = this->spotLight.lightTarget.z;
      v84.swizzle[1] = LODWORD(this->spotLight.lightTarget.y);
      v84.value[0] = v56;
      v84.value[2] = v57;
      v55->g.end.z = v57;
      v58 = v84.value[1];
      v55->g.end.x = v84.value[0];
      v55->g.end.y = v58;
    }
    if ( ((LODWORD(this->spotLight.lightTarget.z)
         | LODWORD(this->spotLight.lightTarget.y)
         | LODWORD(this->spotLight.lightTarget.x))
        & 0x7FFFFFFF) != 0
      || ((LODWORD(this->spotLight.lightUp.z) | LODWORD(this->spotLight.lightUp.y) | LODWORD(this->spotLight.lightUp.x))
        & 0x7FFFFFFF) != 0
      || (v62 = 0,
          ((LODWORD(this->spotLight.lightRight.z)
          | LODWORD(this->spotLight.lightRight.y)
          | LODWORD(this->spotLight.lightRight.x))
         & 0x7FFFFFFF) != 0) )
    {
      v62 = 1;
    }
    if ( ((LODWORD(this->spotLight.lightTarget.z)
         | LODWORD(this->spotLight.lightTarget.y)
         | LODWORD(this->spotLight.lightTarget.x))
        & 0x7FFFFFFF) == 0
      || ((LODWORD(this->spotLight.lightUp.z) | LODWORD(this->spotLight.lightUp.y) | LODWORD(this->spotLight.lightUp.x))
        & 0x7FFFFFFF) == 0
      || (v63 = 1,
          ((LODWORD(this->spotLight.lightRight.z)
          | LODWORD(this->spotLight.lightRight.y)
          | LODWORD(this->spotLight.lightRight.x))
         & 0x7FFFFFFF) == 0) )
    {
      v63 = 0;
    }
    if ( v62 != v63 )
    {
      idLib::Printf(
        fmt: "Light at (%f,%f,%f) has bad target info\n",
        this->spawnPosition.x,
        this->spawnPosition.y,
        this->spawnPosition.z);
      return;
    }
  }
  else
  {
    v64 = *(_QWORD *)&this->lightCenter.x;
    v84.swizzle[2] = LODWORD(this->lightCenter.z);
    *(_QWORD *)v84.value = v64;
    v42->g.lightCenter.x = *(float *)&v64;
    v42->g.lightCenter.z = v84.value[2];
    v42->g.lightCenter.y = v84.value[1];
    v65 = this->lightRadius.y;
    v66 = this->lightRadius.z;
    v84.swizzle[0] = LODWORD(this->lightRadius.x);
    v84.value[1] = v65;
    v67 = this->renderLight;
    v84.value[2] = v66;
    v67->g.lightRadius.x = v84.value[0];
    v67->g.lightRadius.z = v66;
    v67->g.lightRadius.y = v65;
    if ( ((LODWORD(this->lightRadius.z) | LODWORD(this->lightRadius.y) | LODWORD(this->lightRadius.x)) & 0x7FFFFFFF) == 0 )
    {
      v68 = this->renderLight;
      v68->g.lightRadius.x = 320.0;
      v68->g.lightRadius.y = 320.0;
      v68->g.lightRadius.z = 320.0;
    }
  }
  this->renderLight->g.noShadows = this->noShadows;
  this->renderLight->g.slowLight = this->slowLight;
  this->renderLight->g.lightType = this->lightType;
  this->renderLight->g.lightClass = this->lightClass;
  this->renderLight->g.lightFalloff = this->lightFalloff;
  this->renderLight->g.dimShadowStretch = this->dimShadowStretch;
  v69 = this->dynamicModelLightingScale.y;
  v84.swizzle[2] = LODWORD(this->dynamicModelLightingScale.z);
  v70 = this->dynamicModelLightingScale.x;
  v71 = this->renderLight;
  v71->g.dynamicModelLightingScale.z = v84.value[2];
  v84.value[0] = v70;
  v84.value[1] = v69;
  v71->g.dynamicModelLightingScale.y = v69;
  v71->g.dynamicModelLightingScale.x = v84.value[0];
  this->renderLight->g.staticSpecularScale = this->staticSpecularScale;
  v72 = this->staticSpecularVector.y;
  v84.swizzle[0] = LODWORD(this->staticSpecularVector.x);
  v73 = this->renderLight;
  v84.swizzle[2] = LODWORD(this->staticSpecularVector.z);
  v74 = v84.value[2];
  v84.value[1] = v72;
  v73->g.staticSpecularVector.x = v84.value[0];
  v73->g.staticSpecularVector.y = v72;
  v73->g.staticSpecularVector.z = v74;
  this->renderLight->g.iesFile = this->lightIesFile;
  this->renderLight->g.iesPowerScale = this->iesPowerScale;
  this->renderLight->g.iesAreaScale = this->iesAreaScale;
  this->renderLight->g.bakedParallelShadows = this->bakedParallelShadows;
  slowMultiPass = this->slowMultiPass;
  if ( slowMultiPass >= 1 )
  {
    if ( slowMultiPass > 4 )
      slowMultiPass = 4;
  }
  else
  {
    slowMultiPass = 1;
  }
  this->renderLight->g.slowMultiPass = slowMultiPass;
  lightMaterial = this->lightMaterial;
  if ( lightMaterial != nullptr )
  {
    v77 = idStr::Icmp(s1: lightMaterial->name.str, s2: "_emptyname");
    v78 = nullptr;
    if ( v77 == 0 )
    {
LABEL_42:
      this->renderLight->g.shader = v78;
      goto LABEL_43;
    }
LABEL_41:
    v78 = this->lightMaterial;
    goto LABEL_42;
  }
  if ( this->renderLight->g.shader != nullptr )
    goto LABEL_41;
LABEL_43:
  this->renderLight->g.areaLightSize = this->lightGenAreaScale;
  lightColor = rp->lightColor;
  ParmBlock = idRenderLight::GetParmBlock(this: this->renderLight);
  g = this->lightColor.g;
  b = this->lightColor.b;
  a = this->lightColor.a;
  v84.value[0] = this->lightColor.r;
  v84.value[1] = g;
  v84.value[2] = b;
  v84.value[3] = a;
  idParmBlock::SetParm(this: ParmBlock, parm: lightColor, parmValue: &v84);
}


// ========================================================================
// ?GetColor@idLight@@UBAXAAVidVec3@@@Z
// EA  : 0x82C6AD90
// RVA : 0x00C6AD90
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::GetColor(idLight *this, idVec3 *out)
{
  double g; // fp13
  double b; // fp12

  g = this->lightColor.g;
  b = this->lightColor.b;
  out->x = this->lightColor.r;
  out->y = g;
  out->z = b;
}


// ========================================================================
// ?GetColor@idLight@@UBAXAAVidVec4@@@Z
// EA  : 0x82C6ADB0
// RVA : 0x00C6ADB0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::GetColor(idLight *this, idVec4 *out)
{
  double g; // fp13
  double b; // fp12
  double a; // fp11

  g = this->lightColor.g;
  b = this->lightColor.b;
  a = this->lightColor.a;
  out->x = this->lightColor.r;
  out->y = g;
  out->z = b;
  out->w = a;
}


// ========================================================================
// ?SetRadius@idLight@@QAAXM@Z
// EA  : 0x82C6ADD8
// RVA : 0x00C6ADD8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetRadius(idLight *this, double radius)
{
  idRenderLight *renderLight; // r3

  this->lightRadius.x = radius;
  this->lightRadius.y = radius;
  this->lightRadius.z = radius;
  renderLight = this->renderLight;
  renderLight->g.lightRadius.x = radius;
  renderLight->g.lightRadius.y = radius;
  renderLight->g.lightRadius.z = radius;
  idRenderLight::CommitThisFrame(this: renderLight);
}


// ========================================================================
// ?Fade@idLight@@QAAXABVidColor@@M@Z
// EA  : 0x82C6ADF8
// RVA : 0x00C6ADF8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Fade(idLight *this, const idColor *to, double fadeTime)
{
  this->GetColor_2(this, a2: &this->fadeFrom);
  this->fadeTo = *to;
  this->fadeStart = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->fadeEnd = (int)(float)((float)1000.0 * (float)fadeTime)
                + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?GetSoundTransform@idLight@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C6AEB0
// RVA : 0x00C6AEB0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::GetSoundTransform(idLight *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idPhysics *Physics; // r28
  idPhysics *v7; // r27
  float *v8; // r3
  double v9; // fp31
  double v10; // fp30
  double v11; // fp29
  float *v12; // r3
  double v13; // fp4
  double v14; // fp3
  idPhysics *v15; // r3
  idVec3 lightCenter; // 0:^50.12

  Physics = idEntity::GetPhysics(this);
  v7 = idEntity::GetPhysics(this);
  lightCenter = this->renderLight->g.lightCenter;
  v8 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  v9 = (float)((float)(lightCenter.x * *v8) + (float)((float)(v8[3] * lightCenter.y) + (float)(v8[6] * lightCenter.z)));
  v10 = (float)((float)(v8[1] * lightCenter.x) + (float)((float)(v8[4] * lightCenter.y) + (float)(v8[7] * lightCenter.z)));
  v11 = (float)((float)(v8[2] * lightCenter.x) + (float)((float)(v8[5] * lightCenter.y) + (float)(v8[8] * lightCenter.z)));
  v12 = (float *)v7->GetOrigin(this: v7, a2: 0);
  v13 = (float)(v12[1] + (float)v10);
  v14 = (float)(v12[2] + (float)v11);
  soundOrigin->x = *v12 + (float)v9;
  soundOrigin->y = v13;
  soundOrigin->z = v14;
  v15 = idEntity::GetPhysics(this);
  *soundAxis = *v15->GetAxis(this: v15, a2: 0);
}


// ========================================================================
// ?ShowEditingDialog@idLight@@UAAXXZ
// EA  : 0x82C6B030
// RVA : 0x00C6B030
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::ShowEditingDialog(idLight *this)
{
  if ( g_editEntityMode.valueInteger == 1 )
    common->InitTool(this: common, a2: EDITOR_LIGHT);
  else
    idEntity::ShowEditingDialog(this);
}


// ========================================================================
// ?UpdateEditingDialog@idLight@@UAAXXZ
// EA  : 0x82C6B068
// RVA : 0x00C6B068
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::UpdateEditingDialog(idLight *this)
{
  if ( g_editEntityMode.valueInteger == 1 )
    common->UpdateTool(this: common, a2: EDITOR_LIGHT);
  else
    idEntity::UpdateEditingDialog(this);
}


// ========================================================================
// ?Event_SetRadiusXYZ@idLight@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C6B0A0
// RVA : 0x00C6B0A0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_SetRadiusXYZ(idLight *this, eventVoid *result, double x, double y, double z)
{
  idRenderLight *v6; // r3

  v6 = *(idRenderLight **)&result[1044];
  *(float *)&result[816] = x;
  *(float *)&result[820] = y;
  *(float *)&result[824] = z;
  v6->g.lightRadius.x = x;
  v6->g.lightRadius.y = y;
  v6->g.lightRadius.z = z;
  idRenderLight::CommitThisFrame(this: v6);
  return this;
}


// ========================================================================
// ?Event_SetRadius@idLight@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C6B0F0
// RVA : 0x00C6B0F0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_SetRadius(idLight *this, eventVoid *result, double radius)
{
  idRenderLight *v4; // r3

  v4 = *(idRenderLight **)&result[1044];
  *(float *)&result[816] = radius;
  *(float *)&result[820] = radius;
  *(float *)&result[824] = radius;
  v4->g.lightRadius.x = radius;
  v4->g.lightRadius.y = radius;
  v4->g.lightRadius.z = radius;
  idRenderLight::CommitThisFrame(this: v4);
  return this;
}


// ========================================================================
// ?Event_Hide@idLight@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6B140
// RVA : 0x00C6B140
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idEntity *__fastcall idLight::Event_Hide(idEntity *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 132))(a1: result);
  return this;
}


// ========================================================================
// ?Event_Show@idLight@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6B180
// RVA : 0x00C6B180
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idEntity *__fastcall idLight::Event_Show(idEntity *this, eventVoid *result)
{
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 136))(a1: result);
  return this;
}


// ========================================================================
// ?Event_FadeOutLight@idLight@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C6B1C0
// RVA : 0x00C6B1C0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_FadeOutLight(idLight *this, idLight *result, double time)
{
  idLight::Fade(this: result, to: &idColor::colorBlack, fadeTime: time);
  return this;
}


// ========================================================================
// ?Event_FadeInLight@idLight@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C6B200
// RVA : 0x00C6B200
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_FadeInLight(idLight *this, idLight *result, double time)
{
  idLight::Fade(this: result, to: &result->originalColor, fadeTime: time);
  return this;
}


// ========================================================================
// ?SetLightTarget@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B238
// RVA : 0x00C6B238
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightTarget(idLight *this, const idVec3 *v)
{
  this->spotLight.lightTarget = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightRight@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B258
// RVA : 0x00C6B258
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightRight(idLight *this, const idVec3 *v)
{
  this->spotLight.lightRight = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightUp@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B278
// RVA : 0x00C6B278
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightUp(idLight *this, const idVec3 *v)
{
  this->spotLight.lightUp = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightStart@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B298
// RVA : 0x00C6B298
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightStart(idLight *this, const idVec3 *v)
{
  this->spotLight.lightStart = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightEnd@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B2B8
// RVA : 0x00C6B2B8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightEnd(idLight *this, const idVec3 *v)
{
  this->spotLight.lightEnd = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightCenter@idLight@@QAAXABVidVec3@@@Z
// EA  : 0x82C6B2D8
// RVA : 0x00C6B2D8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightCenter(idLight *this, const idVec3 *v)
{
  this->lightCenter = *v;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetParallel@idLight@@QAAX_N@Z
// EA  : 0x82C6B2F8
// RVA : 0x00C6B2F8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetParallel(idLight *this, bool b)
{
  lightType_t v2; // r11

  if ( b )
  {
    v2 = LIGHT_PARALLEL;
LABEL_5:
    this->lightType = v2;
    goto LABEL_6;
  }
  if ( this->lightType == LIGHT_PARALLEL )
  {
    v2 = LIGHT_POINT;
    goto LABEL_5;
  }
LABEL_6:
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetSpot@idLight@@QAAX_N@Z
// EA  : 0x82C6B328
// RVA : 0x00C6B328
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetSpot(idLight *this, bool b)
{
  lightType_t v2; // r11

  if ( b )
  {
    v2 = LIGHT_SPOT;
LABEL_5:
    this->lightType = v2;
    goto LABEL_6;
  }
  if ( this->lightType == LIGHT_SPOT )
  {
    v2 = LIGHT_POINT;
    goto LABEL_5;
  }
LABEL_6:
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?UpdateModelTransform@idLight@@UAAXXZ
// EA  : 0x82C6B358
// RVA : 0x00C6B358
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::UpdateModelTransform(idLight *this)
{
  float *v2; // r9
  int *v3; // r10
  double v4; // fp12
  int v5; // ctr
  idRenderLight *renderLight; // r11
  double v7; // fp13
  float *v8; // r11
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp10
  double v13; // fp8
  double v14; // fp7
  double v15; // fp6
  float v16; // [sp+50h] [-90h] BYREF
  float v17; // [sp+54h] [-8Ch]
  float v18; // [sp+58h] [-88h]
  float v19; // [sp+60h] [-80h]
  float v20; // [sp+64h] [-7Ch]
  float v21; // [sp+68h] [-78h]
  float v22[12]; // [sp+6Ch] [-74h] BYREF
  int v23; // [sp+9Ch] [-44h] BYREF
  float v24[12]; // [sp+A0h] [-40h] BYREF

  if ( this->renderLight != nullptr )
  {
    this->GetModelTransform(this, a2: (idVec3 *)&v16, a3: (idMat3 *)v24);
    v2 = v22;
    v3 = &v23;
    v21 = v18;
    v4 = v18;
    v19 = v16;
    v5 = 9;
    renderLight = this->renderLight;
    v20 = v17;
    v7 = v17;
    renderLight->g.origin.x = v16;
    renderLight->g.origin.z = v4;
    renderLight->g.origin.y = v7;
    do
    {
      *(_DWORD *)++v2 = *++v3;
      --v5;
    }
    while ( v5 != 0 );
    v8 = (float *)this->renderLight;
    v9 = v22[4];
    v10 = v22[2];
    v11 = v22[3];
    v12 = v22[5];
    *v8 = v24[0];
    v8[3] = v9;
    v8[1] = v10;
    v8[2] = v11;
    v8[4] = v12;
    v13 = v22[7];
    v8[5] = v22[6];
    v14 = v22[8];
    v8[6] = v13;
    v15 = v22[9];
    v8[7] = v14;
    v8[8] = v15;
    idRenderLight::CommitThisFrame(this: this->renderLight);
  }
}


// ========================================================================
// ?CreateEntityInterface@idLight@@UAAPAVidEntityInterface@@PAVidGame@@@Z
// EA  : 0x82C6B458
// RVA : 0x00C6B458
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idEntityInterface *__fastcall idLight::CreateEntityInterface(idLight *this, idGame *game)
{
  idEntityInterfaceLocal *v4; // r3
  _DWORD *v5; // r30

  v4 = (idEntityInterfaceLocal *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x14u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  v5 = &v4->__vftable;
  if ( v4 == nullptr )
    return nullptr;
  idEntityInterfaceLocal::idEntityInterfaceLocal(this: v4, game, ent: this);
  *v5 = &idEditorLightInterface::`vftable';
  return (idEntityInterface *)v5;
}


// ========================================================================
// __unwind$490572
// EA  : 0x82C6B4D4
// RVA : 0x00C6B4D4
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall _unwind_490572(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?GetLightColor@idEditorLightInterface@@UBAXAAVidColor@@@Z
// EA  : 0x82C6B500
// RVA : 0x00C6B500
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::GetLightColor(idEditorLightInterface *this, idColor *color)
{
  idEntity *(__fastcall *GetEntity)(struct idEditorLightInterface *); // r9
  idLight *v4; // r3
  idLight *v5; // r3

  GetEntity = this->GetEntity;
  color->r = 1.0;
  color->g = 1.0;
  color->b = 1.0;
  color->a = 1.0;
  v4 = (idLight *)GetEntity(this);
  v5 = idLight::CastTo(c: v4);
  if ( v5 != nullptr )
    v5->GetColor_2(this: v5, a2: color);
}


// ========================================================================
// ?SetLightRadius@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B570
// RVA : 0x00C6B570
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightRadius(idEditorLightInterface *this, const idVec3 *radius)
{
  idLight *v3; // r3
  idLight *v4; // r3
  idRenderLight *renderLight; // r11
  double z; // fp0
  double y; // fp13
  double x; // fp12

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    renderLight = v4->renderLight;
    z = radius->z;
    y = radius->y;
    x = radius->x;
    v4->lightRadius.x = radius->x;
    v4->lightRadius.y = y;
    v4->lightRadius.z = z;
    renderLight->g.lightRadius.x = x;
    renderLight->g.lightRadius.y = y;
    renderLight->g.lightRadius.z = z;
    idRenderLight::CommitThisFrame(this: renderLight);
  }
}


// ========================================================================
// ?GetLightRadius@idEditorLightInterface@@UBAXAAVidVec3@@@Z
// EA  : 0x82C6B5E8
// RVA : 0x00C6B5E8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::GetLightRadius(idEditorLightInterface *this, idVec3 *radius)
{
  idEntity *(__fastcall *GetEntity)(struct idEditorLightInterface *); // r9
  idLight *v4; // r3
  idLight *v5; // r3
  float *renderLight; // r11
  double v7; // fp13
  float v8; // [sp+54h] [-1Ch]

  GetEntity = this->GetEntity;
  radius->x = 0.0;
  radius->y = 0.0;
  radius->z = 0.0;
  v4 = (idLight *)GetEntity(this);
  v5 = idLight::CastTo(c: v4);
  if ( v5 != nullptr )
  {
    renderLight = (float *)v5->renderLight;
    v7 = renderLight[19];
    v8 = renderLight[20];
    radius->z = renderLight[21];
    radius->y = v8;
    radius->x = v7;
  }
}


// ========================================================================
// ?SetLightSpotlight@idEditorLightInterface@@UAAX_N@Z
// EA  : 0x82C6B678
// RVA : 0x00C6B678
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightSpotlight(idEditorLightInterface *this, const bool spot)
{
  idLight *v3; // r3
  idLight *v4; // r3
  int v5; // r11

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    if ( spot )
    {
      v5 = 1;
    }
    else
    {
      if ( v4->lightType != LIGHT_SPOT )
      {
LABEL_7:
        idLight::InitRenderLight(this: v4);
        return;
      }
      v5 = 0;
    }
    v4->lightType = v5;
    goto LABEL_7;
  }
}


// ========================================================================
// ?SetLightParallel@idEditorLightInterface@@UAAX_N@Z
// EA  : 0x82C6B6E8
// RVA : 0x00C6B6E8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightParallel(idEditorLightInterface *this, const bool parallel)
{
  idLight *v3; // r3
  idLight *v4; // r3
  int v5; // r11

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    if ( parallel )
    {
      v5 = 2;
    }
    else
    {
      if ( v4->lightType != LIGHT_PARALLEL )
      {
LABEL_7:
        idLight::InitRenderLight(this: v4);
        return;
      }
      v5 = 0;
    }
    v4->lightType = v5;
    goto LABEL_7;
  }
}


// ========================================================================
// ?SetLightCenter@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B758
// RVA : 0x00C6B758
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightCenter(idEditorLightInterface *this, const idVec3 *center)
{
  idLight *v3; // r3
  idLight *v4; // r3
  idEntity *v5; // r31

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->lightCenter.x = center->x;
    v4->lightCenter.y = center->y;
    v4->lightCenter.z = center->z;
    idLight::InitRenderLight(this: v4);
    idEntity::UpdateVisuals(this: v5);
  }
}


// ========================================================================
// ?GetLightCenter@idEditorLightInterface@@UAAXAAVidVec3@@@Z
// EA  : 0x82C6B7D0
// RVA : 0x00C6B7D0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::GetLightCenter(idEditorLightInterface *this, idVec3 *center)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    center->x = v4->lightCenter.x;
    center->y = v4->lightCenter.y;
    center->z = v4->lightCenter.z;
  }
}


// ========================================================================
// ?SetLightTarget@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B830
// RVA : 0x00C6B830
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightTarget(idEditorLightInterface *this, const idVec3 *target)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    v4->spotLight.lightTarget.x = target->x;
    v4->spotLight.lightTarget.y = target->y;
    v4->spotLight.lightTarget.z = target->z;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ?SetLightRight@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B890
// RVA : 0x00C6B890
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightRight(idEditorLightInterface *this, const idVec3 *right)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    v4->spotLight.lightRight.x = right->x;
    v4->spotLight.lightRight.y = right->y;
    v4->spotLight.lightRight.z = right->z;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ?SetLightUp@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B8F0
// RVA : 0x00C6B8F0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightUp(idEditorLightInterface *this, const idVec3 *up)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    v4->spotLight.lightUp.x = up->x;
    v4->spotLight.lightUp.y = up->y;
    v4->spotLight.lightUp.z = up->z;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ?SetLightStart@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B950
// RVA : 0x00C6B950
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightStart(idEditorLightInterface *this, const idVec3 *start)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    v4->spotLight.lightStart.x = start->x;
    v4->spotLight.lightStart.y = start->y;
    v4->spotLight.lightStart.z = start->z;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ?SetLightEnd@idEditorLightInterface@@UAAXABVidVec3@@@Z
// EA  : 0x82C6B9B0
// RVA : 0x00C6B9B0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightEnd(idEditorLightInterface *this, const idVec3 *end)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    v4->spotLight.lightEnd.x = end->x;
    v4->spotLight.lightEnd.y = end->y;
    v4->spotLight.lightEnd.z = end->z;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ??0idLight@@QAA@XZ
// EA  : 0x82C6BA10
// RVA : 0x00C6BA10
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::idLight(idLight *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idLight_vtbl *)&idLight::`vftable';
  this->lightColor.a = -1.0;
  this->lightColor.b = -1.0;
  this->lightColor.g = -1.0;
  this->lightColor.r = -1.0;
  this->fadeFrom.a = -1.0;
  this->fadeFrom.b = -1.0;
  this->fadeFrom.g = -1.0;
  this->fadeFrom.r = -1.0;
  this->fadeTo.a = -1.0;
  this->fadeTo.b = -1.0;
  this->fadeTo.g = -1.0;
  this->fadeTo.r = -1.0;
  this->originalColor.a = -1.0;
  this->originalColor.b = -1.0;
  this->originalColor.g = -1.0;
  this->originalColor.r = -1.0;
  this->lightColor = idColor::colorWhite;
  this->lightParent = nullptr;
  this->fadeFrom.r = 1.0;
  this->fadeFrom.g = 1.0;
  this->fadeFrom.b = 1.0;
  this->fadeFrom.a = 1.0;
  this->fadeTo.r = 1.0;
  this->fadeTo.g = 1.0;
  this->fadeTo.b = 1.0;
  this->fadeTo.a = 1.0;
  this->fadeStart = 0;
  this->fadeEnd = 0;
  this->soundWasPlaying = false;
  this->spotLight.lightTarget.x = 64.0;
  this->spotLight.lightTarget.y = 0.0;
  this->spotLight.lightTarget.z = 0.0;
  this->spotLight.lightRight.x = 0.0;
  this->spotLight.lightRight.y = -64.0;
  this->spotLight.lightRight.z = 0.0;
  this->spotLight.lightUp.z = 64.0;
  this->spotLight.lightUp.x = 0.0;
  this->spotLight.lightUp.y = 0.0;
  this->spotLight.lightStart.z = 0.0;
  this->spotLight.lightStart.y = 0.0;
  this->spotLight.lightStart.x = 0.0;
  this->spotLight.lightEnd.z = 0.0;
  this->spotLight.lightEnd.y = 0.0;
  this->spotLight.lightEnd.x = 0.0;
  this->lightCenter.z = 0.0;
  this->lightCenter.y = 0.0;
  this->lightCenter.x = 0.0;
  this->lightRadius.x = 320.0;
  this->lightRadius.y = 320.0;
  this->lightRadius.z = 320.0;
  this->lightOffset.z = 0.0;
  this->lightOffset.y = 0.0;
  this->lightOffset.x = 0.0;
  this->lightOrientation.mat[2].z = 1.0;
  this->lightOrientation.mat[1].y = 1.0;
  this->lightOrientation.mat[0].x = 1.0;
  this->lightOrientation.mat[1].z = 0.0;
  this->lightOrientation.mat[0].z = 0.0;
  this->lightOrientation.mat[0].y = 0.0;
  this->lightOrientation.mat[2].y = 0.0;
  this->lightOrientation.mat[2].x = 0.0;
  this->lightOrientation.mat[1].x = 0.0;
  this->noShadows = false;
  this->lightType = LIGHT_POINT;
  this->lightGenAreaScale = 8.0;
  this->lightMaterial = nullptr;
  this->iesPowerScale = 1.0;
  this->lightIesFile = nullptr;
  this->iesAreaScale = 1.0;
  this->envEffectsDecl = nullptr;
  this->dimShadowStretch = 1.0;
  this->soundInfo.shader = nullptr;
  this->soundInfo.waitForTrigger = false;
  this->startOff = false;
  this->renderLight = nullptr;
  this->lightClass = LIGHT_NORMAL;
  this->lightFalloff = LIGHT_FALLOFF_TEXTURE;
  this->slowLight = false;
  this->dynamicModelLightingScale.x = 1.0;
  this->dynamicModelLightingScale.y = 1.0;
  this->dynamicModelLightingScale.z = 1.0;
  this->staticSpecularScale = 10.0;
  this->staticSpecularVector.x = 0.0;
  this->staticSpecularVector.y = 0.70700002;
  this->staticSpecularVector.z = 0.70700002;
  this->bakedParallelShadows = false;
  this->additiveBlendLight = false;
  this->slowMultiPass = 1;
  return this;
}


// ========================================================================
// ?SetShader@idLight@@QAAXPBD@Z
// EA  : 0x82C6BC38
// RVA : 0x00C6BC38
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetShader(idLight *this, const char *shadername)
{
  const idMaterial *v3; // r31
  const idDecl *v4; // r3

  if ( shadername != nullptr )
  {
    v4 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: shadername, makeDefault: false);
    v3 = (const idMaterial *)v4;
    if ( v4 != nullptr && idStr::Icmp(s1: v4->name.str, s2: "_emptyname") == 0 )
    {
      this->renderLight->g.shader = nullptr;
      this->lightMaterial = nullptr;
      goto LABEL_4;
    }
  }
  else
  {
    v3 = nullptr;
  }
  this->renderLight->g.shader = v3;
  this->lightMaterial = v3;
LABEL_4:
  idRenderLight::CommitThisFrame(this: this->renderLight);
}


// ========================================================================
// ?PresentModelDefChange@idLight@@AAAXXZ
// EA  : 0x82C6BCD0
// RVA : 0x00C6BCD0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::PresentModelDefChange(idLight *this)
{
  idPresentable *presentable; // r11
  char v3; // r11
  bool v4; // zf
  idPresentable *v5; // r3

  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = presentable->model != nullptr, v3 = 1, !v4) )
    v3 = 0;
  if ( v3 != 0 && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    v5 = this->presentable;
    if ( v5 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v5 = this->presentable;
    }
    v5->Present(this: v5);
  }
}


// ========================================================================
// ?Think@idLight@@UAAXXZ
// EA  : 0x82C6BD60
// RVA : 0x00C6BD60
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Think(idLight *this)
{
  int v2; // r9
  __int128 v3; // r9
  float r; // r11
  float g; // r9
  float b; // r7
  float a; // r6
  idPhysics *Physics; // r3
  float *v9; // r3
  idRenderLight *renderLight; // r11
  idPhysics *v11; // r3
  int v12; // r3
  float *p_a; // r10
  _DWORD *v14; // r11
  int i; // ctr
  float *v16; // r11
  double v17; // fp13
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  float v24; // [sp+5Ch] [-74h]
  float v25; // [sp+60h] [-70h]
  idColor v26; // [sp+70h] [-60h] BYREF
  float v27; // [sp+80h] [-50h]
  float v28; // [sp+84h] [-4Ch]
  float v29; // [sp+88h] [-48h]
  float v30; // [sp+8Ch] [-44h]
  float v31; // [sp+90h] [-40h]
  float v32; // [sp+94h] [-3Ch]
  float v33; // [sp+98h] [-38h]
  float v34; // [sp+9Ch] [-34h]
  float v35; // [sp+A0h] [-30h]

  v2 = this->thinkFlags & 1;
  v26.a = -1.0;
  v26.b = -1.0;
  v26.g = -1.0;
  v26.r = -1.0;
  if ( v2 != 0 && this->fadeEnd > 0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->fadeEnd )
    {
      r = this->fadeTo.r;
      g = this->fadeTo.g;
      b = this->fadeTo.b;
      a = this->fadeTo.a;
      this->fadeEnd = 0;
      v26.r = r;
      v26.g = g;
      v26.b = b;
      v26.a = a;
      idEntity::BecomeInactive(this, flags: 1);
    }
    else
    {
      LODWORD(v3) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      DWORD2(v3) = this->fadeStart;
      DWORD1(v3) = this->fadeEnd;
      idColor::Lerp(
        this: &v26,
        from: &this->fadeFrom,
        to: &this->fadeTo,
        lerp: (float)((float)((float)(__int64)v3 - (float)*(__int64 *)((char *)&v3 + 4))
              / (float)((float)*(__int64 *)&v3 - (float)*(__int64 *)((char *)&v3 + 4))));
    }
    this->SetColor_2(this, a2: &v26);
  }
  idEntity::RunPhysics(this);
  Physics = idEntity::GetPhysics(this);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  renderLight = this->renderLight;
  v24 = v9[1];
  v25 = v9[2];
  renderLight->g.origin.x = *v9;
  renderLight->g.origin.y = v24;
  renderLight->g.origin.z = v25;
  v11 = idEntity::GetPhysics(this);
  v12 = (int)v11->GetAxis(this: v11, a2: 0);
  p_a = &v26.a;
  v14 = (_DWORD *)(v12 - 4);
  for ( i = 9; i != 0; --i )
    *++p_a = *(float *)++v14;
  v16 = (float *)this->renderLight;
  v17 = v30;
  v18 = v28;
  v19 = v29;
  v20 = v31;
  *v16 = v27;
  v16[3] = v17;
  v16[1] = v18;
  v16[2] = v19;
  v16[4] = v20;
  v21 = v33;
  v16[5] = v32;
  v22 = v34;
  v16[6] = v21;
  v23 = v35;
  v16[7] = v22;
  v16[8] = v23;
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
}


// ========================================================================
// ?Event_SetShader@idLight@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82C6BF88
// RVA : 0x00C6BF88
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_SetShader(idLight *this, idLight *result, const char *shadername)
{
  idLight::SetShader(this: result, shadername);
  return this;
}


// ========================================================================
// ?SetLightMaterial@idLight@@QAAXPBD@Z
// EA  : 0x82C6BFC0
// RVA : 0x00C6BFC0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightMaterial(idLight *this, const char *mat)
{
  const idMaterial *v3; // r3

  if ( mat != nullptr )
    v3 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                               this: &idMaterial::resourceList,
                               name: mat,
                               makeDefault: false);
  else
    v3 = nullptr;
  this->lightMaterial = v3;
  idLight::InitRenderLight(this);
}


// ========================================================================
// ?SetLightMaterial@idEditorLightInterface@@UAAXPBD@Z
// EA  : 0x82C6C018
// RVA : 0x00C6C018
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightMaterial(idEditorLightInterface *this, const char *lightMaterial)
{
  idLight *v3; // r3
  idLight *v4; // r30
  const idDecl *v5; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    if ( lightMaterial != nullptr )
      v5 = idDeclInfo::FindWithInheritance(this: &idMaterial::resourceList, name: lightMaterial, makeDefault: false);
    else
      v5 = nullptr;
    v4->lightMaterial = (const idMaterial *)v5;
    idLight::InitRenderLight(this: v4);
  }
}


// ========================================================================
// ?SetLightLevel@idLight@@QAAXXZ
// EA  : 0x82C6C098
// RVA : 0x00C6C098
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightLevel(idLight *this)
{
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
}


// ========================================================================
// ?SetColor@idLight@@UAAXMMM@Z
// EA  : 0x82C6C0D8
// RVA : 0x00C6C0D8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetColor(idLight *this, double red, double green, double blue)
{
  this->lightColor.r = red;
  this->lightColor.g = green;
  this->lightColor.b = blue;
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
}


// ========================================================================
// ?SetColor@idLight@@UAAXABVidColor@@@Z
// EA  : 0x82C6C120
// RVA : 0x00C6C120
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetColor(idLight *this, const idColor *color)
{
  this->lightColor = *color;
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
}


// ========================================================================
// ?SetLightParms@idLight@@QAAXMMMM@Z
// EA  : 0x82C6C180
// RVA : 0x00C6C180
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::SetLightParms(idLight *this, double parm0, double parm1, double parm2, double parm3)
{
  float a; // r9
  float b; // r10
  float r; // r7

  this->lightColor.a = parm3;
  a = this->lightColor.a;
  this->lightColor.b = parm2;
  b = this->lightColor.b;
  this->lightColor.r = parm0;
  r = this->lightColor.r;
  this->lightColor.g = parm1;
  this->originalColor.g = this->lightColor.g;
  this->originalColor.r = r;
  this->originalColor.b = b;
  this->originalColor.a = a;
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
}


// ========================================================================
// ?On@idLight@@QAAXXZ
// EA  : 0x82C6C1F0
// RVA : 0x00C6C1F0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::On(idLight *this)
{
  float g; // r10
  float b; // r8
  float a; // r7

  if ( (this->soundWasPlaying || this->soundInfo.waitForTrigger) && this->soundInfo.shader != nullptr )
    idLight::PlaySound(this, play: true);
  g = this->originalColor.g;
  b = this->originalColor.b;
  a = this->originalColor.a;
  this->lightColor.r = this->originalColor.r;
  this->lightColor.g = g;
  this->lightColor.b = b;
  this->lightColor.a = a;
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
  if ( this->targets.num > 0 )
    idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
}


// ========================================================================
// ?Off@idLight@@QAAXXZ
// EA  : 0x82C6C2A8
// RVA : 0x00C6C2A8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Off(idLight *this)
{
  int v2; // r27
  int v3; // r29
  int value; // r9
  idEntity *v5; // r3
  idEntity *v6; // r31
  idPresentable *presentable; // r11
  char v8; // r11
  bool v9; // zf
  const idDeclRenderParm *Color; // r25
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModel *v12; // r3
  idVec4 v13; // [sp+50h] [-60h] BYREF

  if ( idEntity::IsPlayingSound(this, channel: SND_CHANNEL_ANY) )
    idLight::PlaySound(this, play: false);
  this->lightColor = idColor::colorBlack;
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  idLight::PresentModelDefChange(this);
  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( v2 < this->targets.num
        && (value = this->targets.list[v3].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      if ( v6 != nullptr )
      {
        presentable = v6->presentable;
        if ( presentable == nullptr || (v9 = presentable->model != nullptr, v8 = 1, !v9) )
          v8 = 0;
        if ( v8 != 0 )
        {
          if ( this->additiveBlendLight )
          {
            v13.x = 0.0;
            v13.y = 0.0;
            v13.z = 0.0;
            v13.w = 0.0;
          }
          else
          {
            v13.x = 1.0;
            v13.y = 1.0;
            v13.z = 1.0;
            v13.w = 1.0;
          }
          Color = rp->Color;
          RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v6);
          idRenderModel::SetParm(this: RenderModelFromPresentable, parm: Color, v4: &v13);
          v12 = idEntity::GetRenderModelFromPresentable(this: v6);
          idRenderModel::CommitThisFrame(this: v12);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
}


// ========================================================================
// ?Event_SetLightParms@idLight@@AAA?AVeventVoid@@MMMM@Z
// EA  : 0x82C6C460
// RVA : 0x00C6C460
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_SetLightParms(
        idLight *this,
        idLight *result,
        double parm0,
        double parm1,
        double parm2,
        double parm3)
{
  float a; // r9
  float b; // r10
  float r; // r7

  result->lightColor.a = parm3;
  a = result->lightColor.a;
  result->lightColor.b = parm2;
  b = result->lightColor.b;
  result->lightColor.r = parm0;
  r = result->lightColor.r;
  result->lightColor.g = parm1;
  result->originalColor.g = result->lightColor.g;
  result->originalColor.r = r;
  result->originalColor.b = b;
  result->originalColor.a = a;
  idLight::InitRenderLight(this: result);
  idRenderLight::CommitThisFrame(this: result->renderLight);
  idLight::PresentModelDefChange(this: result);
  return this;
}


// ========================================================================
// ?Hide@idLight@@UAAXXZ
// EA  : 0x82C6C4E8
// RVA : 0x00C6C4E8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Hide(idLight *this)
{
  idEntity::Hide(this);
  idLight::PresentModelDefChange(this);
  idLight::Off(this);
}


// ========================================================================
// ?Show@idLight@@UAAXXZ
// EA  : 0x82C6C528
// RVA : 0x00C6C528
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Show(idLight *this)
{
  idEntity::Show(this);
  idLight::PresentModelDefChange(this);
  idLight::On(this);
}


// ========================================================================
// ?Event_On@idLight@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6C568
// RVA : 0x00C6C568
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_On(idLight *this, idLight *result)
{
  idLight::On(this: result);
  return this;
}


// ========================================================================
// ?Event_PostOff@idLight@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6C5A0
// RVA : 0x00C6C5A0
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_PostOff(idLight *this, idLight *result)
{
  idLight::Off(this: result);
  return this;
}


// ========================================================================
// ?OnActivate@idLight@@EAAXPAVidEntity@@@Z
// EA  : 0x82C6C5D8
// RVA : 0x00C6C5D8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::OnActivate(idLight *this, idEntity *activator)
{
  char v2; // r11

  if ( this->lightColor.r != idColor::colorBlack.r
    || this->lightColor.g != idColor::colorBlack.g
    || this->lightColor.b != idColor::colorBlack.b
    || (v2 = 1, this->lightColor.a != idColor::colorBlack.a) )
  {
    v2 = 0;
  }
  if ( v2 != 0 )
    idLight::On(this);
  else
    idLight::Off(this);
}


// ========================================================================
// ?Event_PostSpawn@idLight@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6C640
// RVA : 0x00C6C640
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idLight *__fastcall idLight::Event_PostSpawn(idLight *this, idEntity *result)
{
  idRenderLight *x_low; // r3
  expOp_t v4; // r18
  const idMaterial *shader; // r11
  idStaticParmBlock<32> *ParmBlock; // r16
  int v8; // r19
  int v9; // r20
  int value; // r9
  idEntity *v11; // r3
  idLight *v12; // r31
  idLight *v13; // r3
  idEntity *v14; // r31
  idPresentable *presentable; // r10
  char v16; // r11
  idPresentable *v17; // r24
  idStaticParmBlock<32> *v18; // r31
  int next_high; // r10
  const char *resourceError; // r6
  __int16 v21; // r7
  __int16 v22; // r9
  expOp_t v24[2]; // [sp+50h] [-E0h] BYREF
  idPlane v25; // [sp+60h] [-D0h] BYREF
  idPlane v26; // [sp+70h] [-C0h] BYREF
  idParmBlock v27; // [sp+80h] [-B0h] BYREF

  x_low = (idRenderLight *)LODWORD(result[1].clipModelInfo.size.x);
  v4 = 0;
  shader = x_low->g.shader;
  if ( shader != nullptr )
    *(_DWORD *)&v4.type = &shader->parmBlock;
  ParmBlock = idRenderLight::GetParmBlock(this: x_low);
  v8 = 0;
  if ( result->targets.num > 0 )
  {
    v9 = 0;
    do
    {
      value = result->targets.list[v9].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v12 = (idLight *)idEntity::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      if ( v12 != nullptr )
      {
        if ( (unsigned __int8)idLight::IsTypeOf(c: v12) != 0 )
        {
          v13 = idLight::CastTo(c: v12);
          v13->lightParent = result;
          v14 = v13;
          idEntity::FreeSoundEmitter(this: v13, immediate: true);
          idEntity::UpdateVisuals(this: v14);
        }
        else
        {
          presentable = v12->presentable;
          if ( presentable == nullptr || (v16 = 1, presentable->model == nullptr) )
            v16 = 0;
          if ( v16 != 0 )
          {
            if ( presentable == nullptr )
              idEntity::InitPresentableInternal(this: v12);
            v17 = v12->presentable;
            v18 = idPresentable::GetParmBlock(this: v17);
            idParmBlock::Append(this: v18, block: ParmBlock);
            if ( *(_DWORD *)&v4.type != 0 )
              idParmBlock::Append(this: v18, block: *(const idParmBlock **)&v4.type);
            idParmBlock::GetVector(this: &v27, result: v18, parm: rp->Color);
            next_high = HIBYTE(result[1].renderModelInfo.next);
            v24[0] = v4;
            v25.a = 1.0;
            v25.b = 1.0;
            v25.c = 1.0;
            v25.d = 1.0;
            v26.a = *(float *)&v27.ops.list;
            v26.b = *(float *)&v27.ops.num;
            v26.c = *(float *)&v27.ops.size;
            v26.d = *(float *)&v27.ops.granularity;
            v24[0].parmIndexDest = (__int16)rpTemp1.r[1].resourceError;
            v24[0].parmIndexA = 2047;
            v24[0].parmIndexB = 2047;
            v24[0].type = v4.type & 0xE1E0 | 0x1E00;
            v24[0].type = v4.type & 0xE000 | 0x1E00 | (32 * rpTemp1.r[1].networkID);
            if ( next_high != 0 )
            {
              idParmBlock::AddOp(this: v18, op: v24, constant: &v26);
              v24[0].parmIndexDest = (__int16)rpColor.r[1].resourceError;
              v24[0].parmIndexA = (__int16)rpLightColor.r[1].resourceError;
              v24[0].parmIndexB = (__int16)rpTemp1.r[1].resourceError;
              v24[0].type = v24[0].type & 0xE1E0 | 0x1E07;
              v24[0].type = v24[0].type & 0xFE1F | (32 * rpColor.r[1].networkID);
            }
            else
            {
              idParmBlock::AddOp(this: v18, op: v24, constant: &v25);
              resourceError = rpTemp2.r[1].resourceError;
              v24[0].parmIndexB = 2047;
              v24[0].type = v24[0].type & 0xE1E0 | 0x1E00;
              v24[0].parmIndexA = 2047;
              v24[0].parmIndexDest = (__int16)resourceError;
              v24[0].type = v24[0].type & 0xFE1F | (32 * rpTemp2.r[1].networkID);
              idParmBlock::AddOp(this: v18, op: v24, constant: &v26);
              v24[0].parmIndexDest = (__int16)rpTemp3.r[1].resourceError;
              v24[0].parmIndexA = (__int16)rpTemp1.r[1].resourceError;
              v21 = v24[0].type & 0xE000 | 0x1E06;
              v24[0].parmIndexB = (__int16)rpLightColor.r[1].resourceError;
              v24[0].type = v24[0].type & 0xE1E0 | 0x1E06;
              v24[0].type = v21 | (32 * rpTemp3.r[1].networkID);
              idParmBlock::AddOp(this: v18, op: v24, constant: &v25);
              v22 = v24[0].type & 0xE1E0;
              v24[0].parmIndexDest = (__int16)rpColor.r[1].resourceError;
              v24[0].parmIndexA = (__int16)rpTemp2.r[1].resourceError;
              v24[0].parmIndexB = (__int16)rpTemp3.r[1].resourceError;
              v24[0].type = v24[0].type & 0xE1E0 | 0x1E07;
              v24[0].type = v22 & 0xE018 | 0x1E07 | (32 * rpColor.r[1].networkID);
            }
            idParmBlock::AddOp(this: v18, op: v24, constant: &v25);
            v17->Present(this: v17);
          }
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < result->targets.num );
  }
  return this;
}


// ========================================================================
// ?SetLightColor@idEditorLightInterface@@UAAXABVidColor@@@Z
// EA  : 0x82C6CA38
// RVA : 0x00C6CA38
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetLightColor(idEditorLightInterface *this, const idColor *color)
{
  idLight *v3; // r3
  idLight *v4; // r3

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  if ( v4 != nullptr )
    idLight::SetLightParms(this: v4, parm0: color->r, parm1: color->g, parm2: color->b, parm3: color->a);
}


// ========================================================================
// ?SetCastShadows@idEditorLightInterface@@UAAX_N@Z
// EA  : 0x82C6CA90
// RVA : 0x00C6CA90
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idEditorLightInterface::SetCastShadows(idEditorLightInterface *this, const bool castShadows)
{
  idLight *v3; // r3
  idLight *v4; // r3
  idLight *v5; // r31

  v3 = (idLight *)this->GetEntity(this);
  v4 = idLight::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->noShadows = (_cntlzw(castShadows) & 0x20) != 0;
    idLight::InitRenderLight(this: v4);
    idRenderLight::CommitThisFrame(this: v5->renderLight);
    idLight::PresentModelDefChange(this: v5);
  }
}


// ========================================================================
// ?Spawn@idLight@@QAAXXZ
// EA  : 0x82C6CB08
// RVA : 0x00C6CB08
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idLight::Spawn(idLight *this)
{
  idLinkList<idEntity> *head; // r5
  float g; // r10
  float b; // r9
  float a; // r8
  BOOL startOff; // r7
  float v31[14]; // [sp+50h] [-50h] BYREF

  if ( this->lightType == LIGHT_PARALLEL && !clientGame->renderWorld->HasGlobalShadows(this: clientGame->renderWorld) )
    idLib::Warning(fmt: "Entity: %s - Map has parallel lights but no global shadows", this->name.data);
  if ( this->envEffectsDecl != nullptr )
  {
    _FP4 = (float)((float)1.0e30 - (float)(this->lightRadius.x + this->spawnPosition.x));
    _FP8 = (float)((float)1.0e30 - (float)(this->spawnPosition.y + this->lightRadius.y));
    _FP28 = (float)((float)(this->lightRadius.x + this->spawnPosition.x) - (float)-1.0e30);
    _FP31 = (float)((float)1.0e30 - (float)(this->spawnPosition.z + this->lightRadius.z));
    _FP30 = (float)((float)(this->spawnPosition.z + this->lightRadius.z) - (float)-1.0e30);
    _FP29 = (float)((float)(this->spawnPosition.y + this->lightRadius.y) - (float)-1.0e30);
    __asm
    {
      fsel      f0, f4, f11, f0
      fsel      f1, f8, f7, f1
      fsel      f8, f31, f3, f2
      fsel      f4, f30, f3, f5
      fsel      f2, f28, f11, f5
      fsel      f3, f29, f7, f5
    }
    _FP11 = (float)((float)_FP0 - (float)(this->spawnPosition.x - this->lightRadius.x));
    _FP12 = (float)((float)_FP1 - (float)(this->spawnPosition.y - this->lightRadius.y));
    _FP10 = (float)((float)_FP8 - (float)(this->spawnPosition.z - this->lightRadius.z));
    _FP7 = (float)((float)(this->spawnPosition.z - this->lightRadius.z) - (float)_FP4);
    _FP31 = (float)((float)(this->spawnPosition.x - this->lightRadius.x) - (float)_FP2);
    _FP5 = (float)((float)(this->spawnPosition.y - this->lightRadius.y) - (float)_FP3);
    __asm { fsel      f0, f11, f9, f0 }
    v31[0] = _FP0;
    __asm { fsel      f1, f12, f6, f1 }
    v31[1] = _FP1;
    __asm { fsel      f12, f10, f13, f8 }
    v31[2] = _FP12;
    __asm { fsel      f11, f7, f13, f4 }
    v31[5] = _FP11;
    __asm { fsel      f9, f31, f9, f2 }
    v31[3] = _FP9;
    __asm { fsel      f10, f5, f6, f3 }
    v31[4] = _FP10;
    ((void (__fastcall *)(idRenderWorld *, float *))clientGame->renderWorld->AddEnvironment)(
      a1: clientGame->renderWorld,
      a2: v31);
    if ( this->soundInfo.shader != nullptr )
      idLib::Warning(fmt: "Entity: %s - Invalid sound shader on Env Area entity!", this->name.data);
    if ( this->lightMaterial != nullptr )
      idLib::Warning(fmt: "Entity: %s - Invalid material specified on Env Area entity!", this->name.data);
LABEL_9:
    head = gameLocal->removeEntities.head;
    this->removeNode.prev->next = this->removeNode.next;
    this->removeNode.next->prev = this->removeNode.prev;
    this->removeNode.prev = &this->removeNode;
    this->removeNode.head = &this->removeNode;
    this->removeNode.next = head;
    this->removeNode.prev = head->prev;
    head->prev = &this->removeNode;
    this->removeNode.prev->next = &this->removeNode;
    this->removeNode.head = head->head;
    return;
  }
  if ( gameLocal->GetGameSpawnInfo(this: gameLocal)->comboMap
    && (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0
    && this->lightClass == LIGHT_PRELIGHT_ONLY )
  {
    if ( this->soundInfo.shader != nullptr )
      idLib::Warning(fmt: "Entity: %s - Invalid sound shader on PRELIGHT_ONLY light!", this->name.data);
    goto LABEL_9;
  }
  idLib::WarningIf(
    condition: ((this->slowMultiPass >= 0) + (this->slowMultiPass <= 2u)) & 1,
    fmt: "Light '%s' has more than two blend-passes, consider lowering 'slowMultiPass' to two or less.",
    this->name.data);
  idLight::InitRenderLight(this);
  idRenderLight::CommitThisFrame(this: this->renderLight);
  g = this->lightColor.g;
  b = this->lightColor.b;
  a = this->lightColor.a;
  startOff = this->startOff;
  this->originalColor.r = this->lightColor.r;
  this->originalColor.g = g;
  this->originalColor.b = b;
  this->originalColor.a = a;
  if ( startOff )
  {
    idLight::Off(this);
  }
  else
  {
    if ( !this->soundInfo.waitForTrigger && this->soundInfo.shader != nullptr )
      idLight::PlaySound(this, play: true);
    if ( this->targets.num > 0 )
      idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
  }
  this->fadeFrom.r = 1.0;
  this->fadeFrom.g = 1.0;
  this->fadeFrom.b = 1.0;
  this->fadeFrom.a = 1.0;
  this->fadeTo.r = 1.0;
  this->fadeTo.g = 1.0;
  this->fadeTo.b = 1.0;
  this->fadeTo.a = 1.0;
  this->fadeStart = 0;
  this->fadeEnd = 0;
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ??0idBuildArea@@QAA@XZ
// EA  : 0x82C6CED8
// RVA : 0x00C6CED8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

idBuildArea *__fastcall idBuildArea::idBuildArea(idBuildArea *this)
{
  idLight::idLight(this);
  this->__vftable = (idBuildArea_vtbl *)&idBuildArea::`vftable';
  this->buildVars.granularity = 0;
  this->buildVars.memTag = 5;
  this->buildVars.listStatic = 0;
  this->buildVars.list = nullptr;
  this->buildVars.size = 0;
  this->buildVars.num = 0;
  this->areaOrigin.z = 0.0;
  this->areaOrigin.y = 0.0;
  this->areaOrigin.x = 0.0;
  this->areaSecondaryOrigin.z = 0.0;
  this->areaSecondaryOrigin.y = 0.0;
  this->areaSecondaryOrigin.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$492421
// EA  : 0x82C6CF78
// RVA : 0x00C6CF78
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _unwind_492421()
{
  int v0; // r12

  idLight::~idLight(this: *(idLight **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idBuildArea@@UAA@XZ
// EA  : 0x82C6CFA8
// RVA : 0x00C6CFA8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void __fastcall idBuildArea::~idBuildArea(idBuildArea *this)
{
  idBuildArea::buildVar_t *list; // r3

  this->__vftable = (idBuildArea_vtbl *)&idBuildArea::`vftable';
  if ( this->buildVars.listStatic == 0 || this->buildVars.listStatic == 2 )
  {
    list = this->buildVars.list;
    if ( list != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &list->varName, num: this->buildVars.size);
    this->buildVars.list = nullptr;
    this->buildVars.size = 0;
  }
  this->buildVars.num = 0;
  idLight::~idLight(this);
}


// ========================================================================
// __unwind$492465
// EA  : 0x82C6D014
// RVA : 0x00C6D014
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _unwind_492465()
{
  int v0; // r12

  idLight::~idLight(this: *(idLight **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'rpLightColor''
// EA  : 0x83377958
// RVA : 0x01377958
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _dynamic_initializer_for__rpLightColor__()
{
  rpLightColor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLightColor;
}


// ========================================================================
// `dynamic initializer for 'rpColor''_0
// EA  : 0x83377978
// RVA : 0x01377978
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _dynamic_initializer_for__rpColor___0()
{
  rpColor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpColor;
}


// ========================================================================
// `dynamic initializer for 'rpTemp1''
// EA  : 0x83377998
// RVA : 0x01377998
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _dynamic_initializer_for__rpTemp1__()
{
  rpTemp1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpTemp1;
}


// ========================================================================
// `dynamic initializer for 'rpTemp2''
// EA  : 0x833779B8
// RVA : 0x013779B8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _dynamic_initializer_for__rpTemp2__()
{
  rpTemp2.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpTemp2;
}


// ========================================================================
// `dynamic initializer for 'rpTemp3''
// EA  : 0x833779D8
// RVA : 0x013779D8
// PDB : w:\tech5\tungsten\game\entities\light.cpp
// ========================================================================

void _dynamic_initializer_for__rpTemp3__()
{
  rpTemp3.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpTemp3;
}

