
// ========================================================================
// ??0idLensFlareManager@@QAA@XZ
// EA  : 0x827151E8
// RVA : 0x007151E8
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

idLensFlareManager *__fastcall idLensFlareManager::idLensFlareManager(idLensFlareManager *this)
{
  float z; // r6

  this->flareRenderModel = nullptr;
  this->flareOcclusionQuadModel = nullptr;
  this->sunDirection = vec3_origin;
  this->occlusionOffset.x = vec3_origin.x;
  this->occlusionOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->isAutosprited = false;
  this->isInitialized = false;
  this->occlusionOffset.z = z;
  return this;
}


// ========================================================================
// ?ApplyFade@idLensFlareManager@@QAAXM@Z
// EA  : 0x82715240
// RVA : 0x00715240
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::ApplyFade(idLensFlareManager *this, double f)
{
  idRenderModelFlare *flareRenderModel; // r3

  flareRenderModel = this->flareRenderModel;
  if ( flareRenderModel != nullptr )
  {
    idRenderModel::SetParm(this: flareRenderModel, parm: rp->coverage, scalar: f);
    idRenderModel::CommitThisFrame(this: this->flareRenderModel);
  }
}


// ========================================================================
// ?ApplyColor@idLensFlareManager@@QAAXABVidVec4@@@Z
// EA  : 0x82715290
// RVA : 0x00715290
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::ApplyColor(idLensFlareManager *this, const idVec4 *color)
{
  idRenderModelFlare *flareRenderModel; // r3

  flareRenderModel = this->flareRenderModel;
  if ( flareRenderModel != nullptr )
  {
    idRenderModel::SetParm(this: flareRenderModel, parm: rp->Color, v4: color);
    idRenderModel::CommitThisFrame(this: this->flareRenderModel);
  }
}


// ========================================================================
// ??1idLensFlareManager@@QAA@XZ
// EA  : 0x827152E0
// RVA : 0x007152E0
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::~idLensFlareManager(idLensFlareManager *this)
{
  idRenderModelFlare *flareRenderModel; // r3
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r3

  if ( this->flareRenderModel != nullptr )
  {
    this->flareRenderModel->quadModelIndex = -1;
    flareRenderModel = this->flareRenderModel;
    flareRenderModel->unlinked = true;
    flareRenderModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: flareRenderModel);
    this->flareRenderModel = nullptr;
  }
  flareOcclusionQuadModel = this->flareOcclusionQuadModel;
  if ( flareOcclusionQuadModel != nullptr )
  {
    flareOcclusionQuadModel->unlinked = true;
    flareOcclusionQuadModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: flareOcclusionQuadModel);
    this->flareOcclusionQuadModel = nullptr;
  }
  this->isInitialized = false;
}


// ========================================================================
// ?StartFlare@idLensFlareManager@@QAAXABVidVec3@@ABVidMat3@@ABVidVec4@@MM@Z
// EA  : 0x82715348
// RVA : 0x00715348
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::StartFlare(
        idLensFlareManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        const idVec4 *color,
        double fadeStartRange,
        double fadeEndRange)
{
  idRenderModelFlare *flareRenderModel; // r11
  idVec3 *p_sunDirection; // r30
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r11
  double z; // fp12
  idRenderModelFlare *v15; // r11
  double v16; // fp0
  double v17; // fp13

  flareRenderModel = this->flareRenderModel;
  if ( this->flareRenderModel != nullptr && this->flareOcclusionQuadModel != nullptr )
  {
    p_sunDirection = &this->sunDirection;
    if ( ((LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.x) | LODWORD(this->sunDirection.y)) & 0x7FFFFFFF) != 0 )
    {
      if ( !flareRenderModel->deferredPositionInitialized || !flareRenderModel->useDeferredPosition )
      {
        flareRenderModel->g.origin.x = p_sunDirection->x;
        flareRenderModel->g.origin.y = this->sunDirection.y;
        flareRenderModel->g.origin.z = this->sunDirection.z;
      }
      flareRenderModel->deferredOrigin.x = p_sunDirection->x;
      flareRenderModel->deferredOrigin.y = this->sunDirection.y;
      flareRenderModel->deferredOrigin.z = this->sunDirection.z;
      idRenderModel::SetAxis(this: this->flareRenderModel, a: axis);
      flareOcclusionQuadModel = this->flareOcclusionQuadModel;
      if ( !flareOcclusionQuadModel->deferredPositionInitialized || !flareOcclusionQuadModel->useDeferredPosition )
      {
        flareOcclusionQuadModel->g.origin.x = p_sunDirection->x;
        flareOcclusionQuadModel->g.origin.y = p_sunDirection->y;
        flareOcclusionQuadModel->g.origin.z = p_sunDirection->z;
      }
      flareOcclusionQuadModel->deferredOrigin.x = p_sunDirection->x;
      flareOcclusionQuadModel->deferredOrigin.y = p_sunDirection->y;
      z = p_sunDirection->z;
    }
    else
    {
      flareRenderModel->g.fadeVisibilityOver = fadeStartRange;
      this->flareRenderModel->g.maxVisibleRange = fadeEndRange;
      v15 = this->flareRenderModel;
      if ( !this->flareRenderModel->deferredPositionInitialized || !this->flareRenderModel->useDeferredPosition )
        v15->g.origin = *org;
      v15->deferredOrigin = *org;
      idRenderModel::SetAxis(this: this->flareRenderModel, a: axis);
      this->flareOcclusionQuadModel->g.maxVisibleRange = fadeEndRange;
      flareOcclusionQuadModel = this->flareOcclusionQuadModel;
      v16 = (float)(org->x + this->occlusionOffset.x);
      z = (float)(this->occlusionOffset.z + org->z);
      v17 = (float)(this->occlusionOffset.y + org->y);
      if ( !flareOcclusionQuadModel->deferredPositionInitialized || !flareOcclusionQuadModel->useDeferredPosition )
      {
        flareOcclusionQuadModel->g.origin.x = org->x + this->occlusionOffset.x;
        flareOcclusionQuadModel->g.origin.y = v17;
        flareOcclusionQuadModel->g.origin.z = z;
      }
      flareOcclusionQuadModel->deferredOrigin.y = v17;
      flareOcclusionQuadModel->deferredOrigin.x = v16;
    }
    flareOcclusionQuadModel->deferredOrigin.z = z;
    idRenderModel::SetAxis(this: this->flareOcclusionQuadModel, a: axis);
    idRenderModel::SetParm(this: this->flareRenderModel, parm: rp->Color, v4: color);
    idRenderModel::SetParm(this: this->flareRenderModel, parm: rp->coverage, scalar: 1.0);
    idRenderModel::CommitThisFrame(this: this->flareRenderModel);
    idRenderModel::CommitThisFrame(this: this->flareOcclusionQuadModel);
  }
}


// ========================================================================
// ?StopFlare@idLensFlareManager@@QAAXXZ
// EA  : 0x82715558
// RVA : 0x00715558
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::StopFlare(idLensFlareManager *this)
{
  idRenderModelFlare *flareRenderModel; // r3
  idRenderModelFlare *v3; // r31
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r31

  flareRenderModel = this->flareRenderModel;
  if ( flareRenderModel != nullptr && this->flareOcclusionQuadModel != nullptr )
  {
    idRenderModel::SetParm(this: flareRenderModel, parm: rp->coverage, scalar: 0.0);
    v3 = this->flareRenderModel;
    if ( !this->flareRenderModel->unlinked )
    {
      idRenderModel::CommitThisFrame(this: this->flareRenderModel);
      v3->unlinked = true;
    }
    flareOcclusionQuadModel = this->flareOcclusionQuadModel;
    if ( !flareOcclusionQuadModel->unlinked )
    {
      idRenderModel::CommitThisFrame(this: this->flareOcclusionQuadModel);
      flareOcclusionQuadModel->unlinked = true;
    }
  }
}


// ========================================================================
// ?Update@idLensFlareManager@@QAAXABVidVec3@@ABVidMat3@@H_N2@Z
// EA  : 0x827155E0
// RVA : 0x007155E0
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::Update(
        idLensFlareManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        const int time,
        bool bindOrg,
        bool bindAxis)
{
  idRenderModelFlare *flareRenderModel; // r11
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r11
  double v10; // fp0
  double v11; // fp12
  double v12; // fp13
  idRenderModelFlareOcclusionQuad *v13; // r11
  float *p_x; // r10
  BOOL v15; // r29
  double v16; // fp7
  double v17; // fp6
  idRenderWorld *v18; // r3
  idRenderWorld *v19; // r3
  idRenderModelFlareOcclusionQuad *v20; // r11
  idMat3 *p_deferredAxis; // r5
  idRenderModelParms *p_deferredOrigin; // r4
  idRenderWorld *v23; // r3
  idRenderModelFlareOcclusionQuad *v24; // r11
  idRenderWorld *v25; // r30
  idRenderModelParms *p_g; // r28
  int Index; // r26
  int v28; // r3
  __int64 v29; // r10
  __int64 v30; // r8
  va *v31; // r3
  int v32; // [sp+8h] [-10D8h]
  int v33; // [sp+Ch] [-10D4h]
  int v34; // [sp+10h] [-10D0h]
  int v35; // [sp+14h] [-10CCh]
  int v36; // [sp+18h] [-10C8h]
  int v37; // [sp+1Ch] [-10C4h]
  float v38[16]; // [sp+60h] [-1080h] BYREF
  va v39; // [sp+A0h] [-1040h] BYREF

  flareRenderModel = this->flareRenderModel;
  if ( this->flareRenderModel != nullptr && this->flareOcclusionQuadModel != nullptr )
  {
    if ( ((LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.y) | LODWORD(this->sunDirection.x)) & 0x7FFFFFFF) == 0 )
    {
      if ( bindOrg )
      {
        if ( !flareRenderModel->deferredPositionInitialized || !flareRenderModel->useDeferredPosition )
          flareRenderModel->g.origin = *org;
        flareRenderModel->deferredOrigin = *org;
        flareOcclusionQuadModel = this->flareOcclusionQuadModel;
        v10 = (float)(org->x + this->occlusionOffset.x);
        v11 = (float)(this->occlusionOffset.z + org->z);
        v12 = (float)(this->occlusionOffset.y + org->y);
        if ( !flareOcclusionQuadModel->deferredPositionInitialized || !flareOcclusionQuadModel->useDeferredPosition )
        {
          flareOcclusionQuadModel->g.origin.x = org->x + this->occlusionOffset.x;
          flareOcclusionQuadModel->g.origin.y = v12;
          flareOcclusionQuadModel->g.origin.z = v11;
        }
        flareOcclusionQuadModel->deferredOrigin.x = v10;
        flareOcclusionQuadModel->deferredOrigin.y = v12;
        flareOcclusionQuadModel->deferredOrigin.z = v11;
      }
      if ( bindAxis )
      {
        idRenderModel::SetAxis(this: this->flareRenderModel, a: axis);
        idRenderModel::SetAxis(this: this->flareOcclusionQuadModel, a: axis);
      }
    }
    idRenderModel::CommitThisFrame(this: this->flareRenderModel);
    idRenderModel::CommitThisFrame(this: this->flareOcclusionQuadModel);
    if ( g_showFlareDebug.valueInteger != 0 )
    {
      v13 = this->flareOcclusionQuadModel;
      p_x = &v13->deferredOrigin.x;
      v15 = (_cntlzw(g_showFlareDebug.valueInteger - 2) & 0x20) != 0;
      if ( !v13->useDeferredPosition )
        p_x = &v13->g.origin.x;
      v16 = (float)(this->occlusionOffset.z + p_x[2]);
      v17 = (float)(*p_x + this->occlusionOffset.x);
      v38[1] = this->occlusionOffset.y + p_x[1];
      v38[2] = v16;
      v38[0] = v17;
      v38[3] = v13->g.scale.x;
      v38[4] = v13->g.scale.y;
      v38[5] = v13->g.scale.z;
      v38[6] = mat3_identity.mat[0].x;
      v38[7] = mat3_identity.mat[0].y;
      v38[8] = mat3_identity.mat[0].z;
      v38[9] = mat3_identity.mat[1].x;
      v38[10] = mat3_identity.mat[1].y;
      v38[11] = mat3_identity.mat[1].z;
      v38[12] = mat3_identity.mat[2].x;
      v38[13] = mat3_identity.mat[2].y;
      v38[14] = mat3_identity.mat[2].z;
      v18 = common->RW(this: common);
      v18->DebugBox(this: v18, a2: (const idVec4 *)&idColor::colorYellow, a3: (const idBox *)v38, a4: 0, a5: v15);
      v19 = common->RW(this: common);
      v20 = this->flareOcclusionQuadModel;
      p_deferredAxis = &v20->deferredAxis;
      if ( !v20->useDeferredPosition )
        p_deferredAxis = &v20->g.axis;
      p_deferredOrigin = (idRenderModelParms *)&v20->deferredOrigin;
      if ( !v20->useDeferredPosition )
        p_deferredOrigin = &v20->g;
      v19->DebugAxis_2(this: v19, a2: &p_deferredOrigin->origin, a3: p_deferredAxis, a4: 0, a5: v15);
      v23 = common->RW(this: common);
      v24 = this->flareOcclusionQuadModel;
      v25 = v23;
      p_g = (idRenderModelParms *)&v24->deferredOrigin;
      if ( !v24->useDeferredPosition )
        p_g = &v24->g;
      Index = idRenderModel::GetIndex(this: this->flareOcclusionQuadModel);
      v28 = idRenderModel::GetIndex(this: this->flareRenderModel);
      v31 = va::va(
              this: &v39,
              fmt: "flare %d quad %d",
              a3: __SPAIR64__(v28, Index),
              a4: v30,
              a5: v29,
              a6: v32,
              a7: v33,
              a8: v34,
              a9: v35,
              a10: v36,
              a11: v37);
      ((void (__fastcall *)(idRenderWorld *, va *, idRenderModelParms *, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, _DWORD, BOOL, double))v25->DebugText)(
        a1: v25,
        a2: v31,
        a3: p_g,
        a4: &off_82040000,
        a5: &idColor::colorYellow,
        a6: 1,
        a7: 0,
        a8: v15,
        a9: 0.2);
    }
  }
}


// ========================================================================
// ?Init@idLensFlareManager@@QAAXPAVidRenderWorld@@PBVidDeclFlare@@MABVidVec3@@2_N@Z
// EA  : 0x82715918
// RVA : 0x00715918
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __fastcall idLensFlareManager::Init(
        idLensFlareManager *this,
        idRenderWorld *renderWorld,
        const idDeclFlare *flareDecl,
        double quadSize,
        const idVec3 *_sunDirection,
        const idVec3 *_occlusionOffset,
        idVec3 *_isAutosprited,
        bool a8)
{
  idVec3 *p_sunDirection; // r29
  idRenderModel *v13; // r3
  idRenderModel *v14; // r3
  idRenderModelFlareOcclusionQuad *v15; // r3
  idRenderModelFlare *flareRenderModel; // r11
  char v17; // r28
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r11
  idStr v21; // [sp+60h] [-60h] BYREF

  if ( flareDecl != nullptr )
  {
    this->sunDirection = *_occlusionOffset;
    p_sunDirection = &this->sunDirection;
    this->occlusionOffset = *_isAutosprited;
    this->isAutosprited = a8;
    idStr::idStr(this: &v21, text: flareDecl->name.str);
    idStr::SetFileExtension(this: &v21, extension: "flare");
    v13 = renderWorld->AllocRenderModel(this: renderWorld, a2: v21.data, a3: 0, a4: -1);
    this->flareRenderModel = (idRenderModelFlare *)_RTDynamicCast(
                                                     inptr: v13,
                                                     VfDelta: 0,
                                                     SrcType: &idRenderModel `RTTI Type Descriptor',
                                                     TargetType: &idRenderModelFlare `RTTI Type Descriptor',
                                                     isReference: 0);
    v14 = renderWorld->AllocRenderModel(this: renderWorld, a2: "_flareocclusionquad", a3: 0, a4: -1);
    v15 = (idRenderModelFlareOcclusionQuad *)_RTDynamicCast(
                                               inptr: v14,
                                               VfDelta: 0,
                                               SrcType: &idRenderModel `RTTI Type Descriptor',
                                               TargetType: &idRenderModelFlareOcclusionQuad `RTTI Type Descriptor',
                                               isReference: 0);
    flareRenderModel = this->flareRenderModel;
    this->flareOcclusionQuadModel = v15;
    if ( flareRenderModel != nullptr && v15 != nullptr )
    {
      v17 = ((LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.y) | LODWORD(p_sunDirection->x)) & 0x7FFFFFFF) != 0;
      flareRenderModel->isSunFlare = v17;
      this->flareRenderModel->quadModelIndex = idRenderModel::GetIndex(this: this->flareOcclusionQuadModel);
      flareOcclusionQuadModel = this->flareOcclusionQuadModel;
      _FP13 = (float)((float)8.0 - (float)quadSize);
      __asm { fsel      f12, f13, f0, f31 }
      flareOcclusionQuadModel->g.scale.y = _FP12;
      flareOcclusionQuadModel->g.scale.x = _FP12;
      flareOcclusionQuadModel->g.scale.z = _FP12;
      *((_BYTE *)&this->flareOcclusionQuadModel->g + 105) = (2 * this->isAutosprited) & 2
                                                          | *((_BYTE *)&this->flareOcclusionQuadModel->g + 105) & 0xFD;
      *((_BYTE *)&this->flareOcclusionQuadModel->g + 106) = (v17 << 6) & 0x40
                                                          | *((_BYTE *)&this->flareOcclusionQuadModel->g + 106) & 0xBF;
      this->flareOcclusionQuadModel->isSunFlare = v17;
      if ( ((LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.y) | LODWORD(p_sunDirection->x)) & 0x7FFFFFFF) != 0 )
      {
        *((_BYTE *)&this->flareOcclusionQuadModel->g + 105) |= 4u;
        *((_BYTE *)&this->flareOcclusionQuadModel->g + 106) |= 2u;
      }
      this->isInitialized = true;
    }
    else
    {
      idLib::Warning(fmt: "Failed to create lens flare models: %s", flareDecl->name.str);
    }
    idStr::FreeData(this: &v21);
  }
}


// ========================================================================
// __unwind$246388
// EA  : 0x82715B38
// RVA : 0x00715B38
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void _unwind_246388()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// `dynamic initializer for 'g_showFlareDebug''
// EA  : 0x8333F9E8
// RVA : 0x0133F9E8
// PDB : w:\tech5\engine\gamelib\effects\lensflaremanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showFlareDebug__()
{
  idCVar::idCVar(
    this: &g_showFlareDebug,
    name: "g_showFlareDebug",
    value: "0",
    flags: 2,
    description: "1 = render flare debug, 2 = render flare debug depth-tested",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showFlareDebug__);
}

