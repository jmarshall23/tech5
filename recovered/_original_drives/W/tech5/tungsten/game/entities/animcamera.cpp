
// ========================================================================
// ?JobSync@idAnimCamera@@UAAXXZ
// EA  : 0x82C05400
// RVA : 0x00C05400
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::JobSync(idAnimCamera *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v2; // r31
  int v3; // r3

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v2 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: RenderModelFromPresentable,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  if ( v2 != nullptr )
  {
    v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idTreeAnimator::SyncJoints(this: v2, time: v3);
  }
}


// ========================================================================
// ?CalcValue@idRenderParmLerp@@QBAXPAVidVec4@@@Z
// EA  : 0x82C05478
// RVA : 0x00C05478
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idRenderParmLerp::CalcValue(idRenderParmLerp *this, idVec4 *dest)
{
  int overrideMask; // r11
  double x; // fp12
  double z; // fp0
  double w; // fp11

  overrideMask = this->overrideMask;
  if ( (overrideMask & 1) != 0 )
    x = this->overrideValue.x;
  else
    x = this->curValue.x;
  if ( (overrideMask & 2) != 0 )
    _FP13 = this->overrideValue.y;
  else
    _FP13 = this->curValue.y;
  if ( (overrideMask & 4) != 0 )
    z = this->overrideValue.z;
  else
    z = this->curValue.z;
  if ( (overrideMask & 8) != 0 )
    w = this->overrideValue.w;
  else
    w = this->curValue.w;
  if ( this->isDepthOfField )
  {
    z = (float)((float)z + (float)x);
    _FP9 = -(float)((float)x - (float)_FP13);
    __asm { fsel      f13, f9, f13, f10 }
  }
  dest->x = x;
  dest->y = _FP13;
  dest->z = z;
  dest->w = w;
}


// ========================================================================
// ?Update@idRenderParmLerp@@QAAXAAVidView@@H@Z
// EA  : 0x82C05540
// RVA : 0x00C05540
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderParmLerp::Update(
        idRenderParmLerp *this,
        idView *view,
        const int curTime,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int64 v7; // r11 OVERLAPPED
  int overrideMask; // r10
  int startTime; // r11
  double x; // fp0
  double v12; // fp5
  double y; // fp13
  double z; // fp9
  double w; // fp7
  double v16; // fp4
  double v17; // fp3
  double v18; // fp2
  const idDeclRenderParm **v19; // r3
  idVec4 v20; // [sp+50h] [-20h] BYREF

  if ( this->decl != nullptr )
  {
    overrideMask = this->overrideMask;
    if ( overrideMask == 15 )
    {
LABEL_8:
      idRenderParmLerp::CalcValue(this, dest: &v20);
      idView::SetEnvironmentParm(this: view, parm: *v19, val: &v20, blendDuration: 0.0);
      return;
    }
    startTime = this->startTime;
    if ( startTime >= 0 || overrideMask != 0 )
    {
      HIDWORD(v7) = this->duration;
      LODWORD(v7) = curTime - startTime;
      if ( (int)v7 < SHIDWORD(v7) )
      {
        x = this->startValue.x;
        v12 = this->endValue.x;
        *(_QWORD *)&v20.x = *(__int64 *)((char *)&v7 + 4);
        y = this->startValue.y;
        z = this->startValue.z;
        w = this->startValue.w;
        v16 = (float)((float)(this->endValue.y - this->startValue.y)
                    * (float)((float)v7 / (float)*(__int64 *)((char *)&v7 + 4)));
        v17 = (float)((float)(this->endValue.z - this->startValue.z)
                    * (float)((float)v7 / (float)*(__int64 *)((char *)&v7 + 4)));
        v18 = (float)((float)(this->endValue.w - this->startValue.w)
                    * (float)((float)v7 / (float)*(__int64 *)((char *)&v7 + 4)));
        this->curValue.x = (float)x
                         + (float)((float)((float)v12 - (float)x)
                                 * (float)((float)v7 / (float)*(__int64 *)((char *)&v7 + 4)));
        this->curValue.y = (float)y + (float)v16;
        this->curValue.z = (float)z + (float)v17;
        this->curValue.w = (float)w + (float)v18;
      }
      else
      {
        this->curValue = this->endValue;
        this->startTime = -1;
        this->duration = -1;
      }
      goto LABEL_8;
    }
  }
}


// ========================================================================
// ??1idAnimCamera@@UAA@XZ
// EA  : 0x82C05688
// RVA : 0x00C05688
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::~idAnimCamera(idAnimCamera *this)
{
  this->__vftable = (idAnimCamera_vtbl *)&idAnimCamera::`vftable';
  idAnimEventHandler::~idAnimEventHandler(this: &this->animEventHandler);
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idAnimStack::~idAnimStack(this: &this->animStack);
  idStr::FreeData(this: &this->guiName);
  idStr::FreeData(this: &this->cameraDofChannel);
  idStr::FreeData(this: &this->cameraFovChannel);
  idStr::FreeData(this: &this->cameraJointName);
  idEntityCamera::~idEntityCamera((idEntityCamera *)this);
}


// ========================================================================
// __unwind$489319
// EA  : 0x82C0570C
// RVA : 0x00C0570C
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489319()
{
  int v0; // r12

  idCameraView::~idCameraView(this: *(idCameraView **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489320
// EA  : 0x82C05734
// RVA : 0x00C05734
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// __unwind$489321
// EA  : 0x82C05760
// RVA : 0x00C05760
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 912));
}


// ========================================================================
// __unwind$489322
// EA  : 0x82C0578C
// RVA : 0x00C0578C
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 944));
}


// ========================================================================
// __unwind$489323
// EA  : 0x82C057B8
// RVA : 0x00C057B8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 980));
}


// ========================================================================
// __unwind$489324
// EA  : 0x82C057E4
// RVA : 0x00C057E4
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489324()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 112 + 132) + 1072));
}


// ========================================================================
// __unwind$489325_0
// EA  : 0x82C05810
// RVA : 0x00C05810
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_489325_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 2644));
}


// ========================================================================
// ?Pause@idAnimCamera@@QAAXXZ
// EA  : 0x82C05848
// RVA : 0x00C05848
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::Pause(idAnimCamera *this)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> v2; // [sp+50h] [-20h] BYREF

  v2.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimStack::Pause(this: &this->animStack, curTime: &v2);
}


// ========================================================================
// ?Draw@idAnimCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82C05898
// RVA : 0x00C05898
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

int __fastcall idAnimCamera::Draw(idAnimCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r27
  double v7; // fp8
  double v8; // fp6
  unsigned int v9; // r7
  unsigned __int64 v10; // r6
  BOOL v11; // r10
  int overrideMask; // r9
  idPresentable *v13; // r3
  idPresentable *v14; // r3
  int v15; // r31
  idPresentable *v16; // r3
  int v17; // r3
  idRenderParmLerp **renderParms; // r31
  int i; // r29
  idRenderParmLerp *v20; // r25
  int v21; // r3
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r6
  idPresentable *v26; // r3
  int entityNumber; // r31
  idPresentablePlayer *v28; // r3
  double x; // fp31
  idRenderWorld *v30; // r3
  int v31; // r6
  idRenderWorld *v32; // r28
  float *v33; // r30
  int v34; // r10
  int v35; // r29
  long double v36; // fp2
  __int64 v37; // r11
  long double v38; // fp2
  __int64 v39; // r3
  int v40; // r29
  double v41; // fp30
  double v42; // fp29
  double v43; // fp9
  double v44; // fp12
  double v45; // fp10
  double v46; // fp3
  double v47; // fp2
  double v48; // fp2
  double v49; // fp9
  double v50; // fp6
  double v51; // fp10
  double v52; // fp8
  double v53; // fp10
  double v54; // fp2
  double v55; // fp1
  idVec4 v57; // [sp+50h] [-E0h] BYREF
  idVec3 v58; // [sp+60h] [-D0h] BYREF
  float v59[4]; // [sp+70h] [-C0h] BYREF
  float v60[4]; // [sp+80h] [-B0h] BYREF
  float v61[4]; // [sp+90h] [-A0h] BYREF
  float v62[4]; // [sp+A0h] [-90h] BYREF
  float v63[16]; // [sp+B0h] [-80h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = v5 + 16224;
  v7 = (float)(this->offset.y + this->camPos.y);
  v8 = (float)(this->offset.z + this->camPos.z);
  v58.x = this->offset.x + this->camPos.x;
  v58.y = v7;
  v58.z = v8;
  idView::SetViewPos(this: (idView *)(v5 + 16224), origin: &v58, axis: &this->camAxis);
  idView::CalcFOV(this: (idView *)v6, base_fov: this->cameraFOV, targetAspectRatio: this->targetAspect);
  if ( (this->overrideDOFMask & 1) == 0 )
  {
    v11 = this->cameraDOF > 0.0;
    overrideMask = this->depthOfField.overrideMask;
    this->depthOfField.overrideValue.x = this->cameraDOF;
    v9 = overrideMask & 0xFFFFFFFE;
    LODWORD(v10) = v11;
    HIDWORD(v10) = v10 | overrideMask & 0xFFFFFFFE;
    this->depthOfField.overrideMask = HIDWORD(v10);
  }
  if ( this->drawPlayerGUIS )
  {
    v13 = player->presentable;
    if ( v13 != nullptr )
      v13->GetPlayerInterface_2(this: v13);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v10,
      a4: v9);
    v14 = player->presentable;
    if ( v14 != nullptr )
      v15 = (int)v14->GetPlayerInterface_2(this: v14);
    else
      v15 = 0;
    v16 = player->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    idPlayerHud::Update(this: (idPlayerHud *)(v17 + 35096), hudInfo: (idHudInfo *)(v15 + 35368));
  }
  renderParms = this->renderParms;
  for ( i = 3; i != 0; --i )
  {
    if ( *renderParms != nullptr )
    {
      v20 = *renderParms;
      v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idRenderParmLerp::Update(this: v20, view: (idView *)v6, curTime: v21, a4: v25, a5: v24, a6: v23, a7: v22);
    }
    ++renderParms;
  }
  *(_BYTE *)(v6 + 1897) = this->forceVirtualMaterialLoad;
  *(_BYTE *)(v6 + 1898) = this->useHighQualityMipGeneration;
  idView::SetViewID(this: (idView *)v6, id: this->entityNumber + 1);
  idView::Render(this: (idView *)v6);
  if ( this->drawPlayerGUIS )
  {
    v26 = player->presentable;
    entityNumber = this->entityNumber;
    if ( v26 != nullptr )
      v28 = v26->GetPlayerInterface_2(this: v26);
    else
      v28 = nullptr;
    idPresentablePlayer::DrawGuis(this: v28, id: entityNumber + 1);
  }
  if ( g_debugAnimCameraFocus.valueInteger != 0 )
  {
    idRenderParmLerp::CalcValue(this: &this->depthOfField, dest: &v57);
    x = v57.x;
    if ( v57.x > 0.0 )
    {
      v30 = common->RW(this: common);
      LODWORD(v57.y) = (int)x;
      v31 = (((int)x - 1) >> 1) | ((int)x - 1);
      v32 = v30;
      v34 = (((v31 >> 2) | v31) >> 4) | (v31 >> 2) | v31;
      v35 = (v34 >> 8) | v34;
      *(double *)&v36 = (float)((float)(this->cameraFOV * idMath::M_DEG2RAD) * (float)0.5);
      v33 = (float *)(v6 + 112);
      v38 = atan(x: v36);
      v63[2] = 0.0;
      LODWORD(v39) = ((v35 >> 16) | v35) + 1;
      *(_QWORD *)&v57.x = v39;
      v63[0] = 1.0;
      v63[1] = 1.0;
      v40 = 0;
      v63[3] = 1.0;
      v41 = (float)((float)((float)((float)*(double *)&v38 * (float)0.80000001) * (float)((float)v39 * (float)0.0625))
                  * (float)16.0);
      v42 = -v41;
      do
      {
        LODWORD(v37) = v40;
        v43 = *(float *)(v6 + 124);
        v44 = (float)(*(float *)(v6 + 128) * (float)x);
        *(_QWORD *)&v57.x = v37;
        v45 = *v33;
        v46 = (float)((float)((float)v42 * *(float *)(v6 + 136))
                    + (float)((float)(*(float *)(v6 + 148)
                                    * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))
                            + (float)((float)v43 * (float)x)));
        v47 = (float)((float)((float)((float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41)
                                    * *(float *)(v6 + 152))
                            + (float)((float)((float)v42 * *(float *)(v6 + 140)) + (float)v44))
                    + *(float *)(v6 + 116));
        v60[2] = (float)((float)(*(float *)(v6 + 156)
                               * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))
                       + (float)((float)((float)v42 * *(float *)(v6 + 144)) + (float)(*(float *)(v6 + 132) * (float)x)))
               + *(float *)(v6 + 120);
        v60[1] = v47;
        v60[0] = (float)v45 + (float)v46;
        v48 = *v33;
        v49 = (float)((float)(*(float *)(v6 + 124) * (float)x)
                    + (float)((float)(*(float *)(v6 + 148)
                                    * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))
                            + (float)(*(float *)(v6 + 136) * (float)v41)));
        v50 = (float)((float)((float)((float)v41 * *(float *)(v6 + 140))
                            + (float)((float)(*(float *)(v6 + 128) * (float)x)
                                    + (float)((float)((float)((float)((float)v37 * (float)0.125) - (float)1.0)
                                                    * (float)v41)
                                            * *(float *)(v6 + 152))))
                    + *(float *)(v6 + 116));
        v59[2] = (float)((float)(*(float *)(v6 + 144) * (float)v41)
                       + (float)((float)(*(float *)(v6 + 132) * (float)x)
                               + (float)(*(float *)(v6 + 156)
                                       * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))))
               + *(float *)(v6 + 120);
        v59[1] = v50;
        v59[0] = (float)v48 + (float)v49;
        v51 = (float)((float)((float)((float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41)
                                    * *(float *)(v6 + 140))
                            + (float)((float)((float)v42 * *(float *)(v6 + 152))
                                    + (float)(*(float *)(v6 + 128) * (float)x)))
                    + *(float *)(v6 + 116));
        v52 = (float)(*v33
                    + (float)((float)((float)v42 * *(float *)(v6 + 148))
                            + (float)((float)(*(float *)(v6 + 136)
                                            * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0)
                                                    * (float)v41))
                                    + (float)(*(float *)(v6 + 124) * (float)x))));
        v62[2] = (float)((float)(*(float *)(v6 + 144)
                               * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))
                       + (float)((float)((float)v42 * *(float *)(v6 + 156)) + (float)(*(float *)(v6 + 132) * (float)x)))
               + *(float *)(v6 + 120);
        v62[0] = v52;
        v62[1] = v51;
        v53 = *v33;
        v54 = (float)((float)(*(float *)(v6 + 124) * (float)x)
                    + (float)((float)(*(float *)(v6 + 136)
                                    * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41))
                            + (float)(*(float *)(v6 + 148) * (float)v41)));
        v55 = (float)((float)((float)(*(float *)(v6 + 156) * (float)v41)
                            + (float)((float)(*(float *)(v6 + 132) * (float)x)
                                    + (float)(*(float *)(v6 + 144)
                                            * (float)((float)((float)((float)v37 * (float)0.125) - (float)1.0)
                                                    * (float)v41))))
                    + *(float *)(v6 + 120));
        v61[1] = (float)((float)((float)v41 * *(float *)(v6 + 152))
                       + (float)((float)(*(float *)(v6 + 128) * (float)x)
                               + (float)((float)((float)((float)((float)v37 * (float)0.125) - (float)1.0) * (float)v41)
                                       * *(float *)(v6 + 140))))
               + *(float *)(v6 + 116);
        v61[2] = v55;
        v61[0] = (float)v53 + (float)v54;
        v32->DebugLine(
          this: v32,
          a2: (const idVec4 *)v63,
          a3: (const idVec3 *)v60,
          a4: (const idVec3 *)v59,
          a5: 0,
          a6: true);
        v32->DebugLine(
          this: v32,
          a2: (const idVec4 *)v63,
          a3: (const idVec3 *)v62,
          a4: (const idVec3 *)v61,
          a5: 0,
          a6: true);
        ++v40;
      }
      while ( v40 <= 16 );
    }
  }
  return 1;
}


// ========================================================================
// ?AnimEvent_CameraFade@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@MM@Z
// EA  : 0x82C05E20
// RVA : 0x00C05E20
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAnimCamera::AnimEvent_CameraFade@<r4>(
        idAnimCamera *this@<r3>,
        int result@<r4>,
        const idMD6Anim *animHandle@<r5>,
        const idVec3 *_fadeColor@<r6>,
        double alpha@<f1>,
        double time@<f2>)
{
  double z; // fp13
  double y; // fp12

  z = _fadeColor->z;
  y = _fadeColor->y;
  *(float *)(result + 4288) = _fadeColor->x;
  *(float *)(result + 4292) = y;
  *(float *)(result + 4296) = z;
  *(float *)(result + 4300) = alpha;
  *(_DWORD *)(result + 4284) = (int)(float)((float)time * (float)1000.0);
  return result;
}


// ========================================================================
// ?AnimEvent_CameraTimeScale@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@M@Z
// EA  : 0x82C05E58
// RVA : 0x00C05E58
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraTimeScale(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        double scale)
{
  ((void (__fastcall *)(idCVarSystem *, const char *, const idMD6Anim *, _DWORD, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: "timescale",
    a3: animHandle,
    a4: 0,
    a5: scale);
  return this;
}


// ========================================================================
// ?AnimEvent_CameraSound@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82C05EA8
// RVA : 0x00C05EA8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraSound(
        idAnimCamera *this,
        idEntity *result,
        const idMD6Anim *animHandle,
        const idSoundShader *soundShader)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_ANY,
    shader: soundShader,
    soundShaderFlags: 0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_CameraWaitForKeypress@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82C05EF0
// RVA : 0x00C05EF0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraWaitForKeypress(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> v6; // [sp+50h] [-20h] BYREF

  result[1052] = (eventVoid)1;
  v6.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimStack::Pause(this: (idAnimStack *)&result[1072], curTime: &v6);
  return this;
}


// ========================================================================
// ?SetDOFOverride@idAnimCamera@@QAAXABVidVec4@@@Z
// EA  : 0x82C05F58
// RVA : 0x00C05F58
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::SetDOFOverride(idAnimCamera *this, const idVec4 *val)
{
  BOOL v2; // r8
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v6; // r8

  v2 = val->x >= 0.0;
  v3 = 2;
  if ( val->y < 0.0 )
    v3 = 0;
  v4 = 4;
  if ( val->z < 0.0 )
    v4 = 0;
  v5 = 8;
  if ( val->w < 0.0 )
    v5 = 0;
  this->depthOfField.overrideValue = *val;
  v6 = v5 | v4 | v3 | v2;
  this->depthOfField.overrideMask = v6;
  this->overrideDOFMask = v6;
}


// ========================================================================
// ?SetDOFOverride@idAnimCamera@@QAAXMH@Z
// EA  : 0x82C05FE8
// RVA : 0x00C05FE8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::SetDOFOverride(idAnimCamera *this, double val, int index, int a4)
{
  *(&this->depthOfField.overrideValue.x + a4) = val;
  this->depthOfField.overrideMask = (val < 0.0 ? 0 : 1 << a4) | this->depthOfField.overrideMask & ~(1 << a4);
  this->overrideDOFMask = this->overrideDOFMask & ~(1 << a4) | (val < 0.0 ? 0 : 1 << a4);
}


// ========================================================================
// ?AnimEvent_CameraRenderParm@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDMMMMM@Z
// EA  : 0x82C06058
// RVA : 0x00C06058
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraRenderParm(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *renderParmName,
        double x,
        double y,
        double z,
        double w,
        double duration)
{
  int v16; // r31
  eventVoid *i; // r30
  int GameMs; // r3
  int v21; // r5

  v16 = 0;
  for ( i = result + 4636;
        *(_DWORD *)i == 0 || idStr::Icmp(s1: *(const char **)(**(_DWORD **)i + 8), s2: renderParmName) != 0;
        i += 4 )
  {
    if ( ++v16 >= 3 )
      return this;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v21 = *(_DWORD *)&result[4 * v16 + 4636];
  *(_DWORD *)(v21 + 8) = GameMs;
  *(_DWORD *)(v21 + 12) = (int)(float)((float)duration * (float)1000.0);
  *(float *)(v21 + 16) = *(float *)(v21 + 48);
  *(float *)(v21 + 20) = *(float *)(v21 + 52);
  *(float *)(v21 + 24) = *(float *)(v21 + 56);
  *(float *)(v21 + 28) = *(float *)(v21 + 60);
  *(float *)(v21 + 32) = x;
  *(float *)(v21 + 36) = y;
  *(float *)(v21 + 40) = z;
  *(float *)(v21 + 44) = w;
  return this;
}


// ========================================================================
// ?AnimEvent_CameraTeleportClientToViewPos@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82C06168
// RVA : 0x00C06168
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraTeleportClientToViewPos(
        idAnimCamera *this,
        idCamera *result,
        const idMD6Anim *animHandle)
{
  idPlayer *PlayerActivator; // r3
  int *v5; // r31
  idPresentable *presentable; // r3
  int v7; // r3
  double v8; // fp1
  int v9; // r30
  idAngles *v10; // r3
  idVec3 v12; // [sp+50h] [-80h] BYREF
  float v13[4]; // [sp+60h] [-70h] BYREF
  idMat3 v14[2]; // [sp+70h] [-60h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this: result);
  v5 = (int *)PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    idView::GetViewPos(this: (idView *)(v7 + 16224), origin: &v12, axis: (idMat3 *)&v14[0].mat[1].y);
    v8 = ((double (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->GetCVarFloat)(
           a1: cvarSystem,
           a2: "pm_normalviewheight",
           a3: 0.0);
    v13[0] = v12.x;
    v13[1] = v12.y;
    v13[2] = v12.z - (float)v8;
    v9 = *v5;
    v10 = idMat3::ToAngles(this: v14, result: (idAngles *)&v14[0].mat[1].y);
    (*(void (__fastcall **)(int *, float *, idAngles *))(v9 + 404))(a1: v5, a2: v13, a3: v10);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_CameraKillVehicleAI@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C06238
// RVA : 0x00C06238
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraKillVehicleAI(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *name)
{
  idEventReceiver *v5; // r31

  v5 = (idEventReceiver *)((int (__fastcall *)(idGameLocal *, const char *, const idMD6Anim *))gameLocal->FindEntity)(
                            a1: gameLocal,
                            a2: name,
                            a3: animHandle);
  if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: v5) != 0 )
    idEventReceiver::PostEventMS(this: v5, ev: &EV_KillVehicleAndAi, time: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_CameraCVarFloat@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDM@Z
// EA  : 0x82C062B0
// RVA : 0x00C062B0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraCVarFloat(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *cvarName,
        double value)
{
  ((void (__fastcall *)(idCVarSystem *, const char *, const idMD6Anim *, _DWORD, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: cvarName,
    a3: animHandle,
    a4: 0,
    a5: value);
  return this;
}


// ========================================================================
// ?AnimEvent_CameraCVarString@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82C06300
// RVA : 0x00C06300
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraCVarString(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *cvarName,
        const char *value)
{
  cvarSystem->SetCVarString(this: cvarSystem, a2: cvarName, a3: value, a4: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_CameraSetFieldOfView@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@M@Z
// EA  : 0x82C06350
// RVA : 0x00C06350
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAnimCamera::AnimEvent_CameraSetFieldOfView@<r4>(
        idAnimCamera *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *animHandle@<r5>,
        double fovDegrees@<f1>)
{
  result[701] = fovDegrees;
  result[702] = fovDegrees;
  result[704] = fovDegrees;
  result[699] = 0.0;
  result[700] = 0.0;
  result[703] = -1.0;
  return result;
}


// ========================================================================
// ?AnimEvent_CameraLerpToFOV@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@MH@Z
// EA  : 0x82C06380
// RVA : 0x00C06380
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraLerpToFOV(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        double fovDegrees,
        const int timeInMs,
        int a6)
{
  __int64 v9; // r10
  idInterpolate<float> *v10; // r31
  double v11; // fp30
  __int64 v12; // r11
  double CurrentValue; // fp1

  v10 = (idInterpolate<float> *)&result[2796];
  LODWORD(v9) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v11 = (float)v9;
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: v10, time: v11);
  if ( fovDegrees >= 1.0 )
  {
    if ( fovDegrees > 179.0 )
      fovDegrees = 179.0;
  }
  else
  {
    fovDegrees = 1.0;
  }
  LODWORD(v12) = a6;
  v10->startTime = v11;
  v10->startValue = CurrentValue;
  v10->duration = (float)v12;
  v10->endValue = fovDegrees;
  v10->currentTime = (float)v11 - (float)1.0;
  v10->currentValue = CurrentValue;
  return this;
}


// ========================================================================
// ?AnimEvent_CameraPause@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82C06450
// RVA : 0x00C06450
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraPause(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> v6; // [sp+50h] [-20h] BYREF

  v6.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimStack::Pause(this: (idAnimStack *)&result[1072], curTime: &v6);
  return this;
}


// ========================================================================
// ??0idRenderParmLerp@@QAA@PBDH@Z
// EA  : 0x82C064B0
// RVA : 0x00C064B0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idRenderParmLerp *__fastcall idRenderParmLerp::idRenderParmLerp(
        idRenderParmLerp *this,
        const char *renderParmName,
        int _numValues)
{
  const idDeclRenderParm *v3; // r10

  this->numValues = _numValues;
  v3 = nullptr;
  this->decl = nullptr;
  this->startTime = -1;
  this->duration = -1;
  this->startValue.x = 0.0;
  this->startValue.y = 0.0;
  this->startValue.z = 0.0;
  this->startValue.w = 0.0;
  this->endValue.x = 0.0;
  this->endValue.y = 0.0;
  this->endValue.z = 0.0;
  this->endValue.w = 0.0;
  this->curValue.x = 0.0;
  this->curValue.y = 0.0;
  this->curValue.z = 0.0;
  this->curValue.w = 0.0;
  this->overrideValue.x = 0.0;
  this->overrideValue.y = 0.0;
  this->overrideValue.z = 0.0;
  this->overrideValue.w = 0.0;
  this->overrideMask = 0;
  if ( renderParmName != nullptr )
    v3 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclRenderParm::resourceList,
                                     name: renderParmName,
                                     makeDefault: true);
  this->decl = v3;
  this->isDepthOfField = (_cntlzw(idStr::Icmp(s1: renderParmName, s2: "depthOfField")) & 0x20) != 0;
  return this;
}


// ========================================================================
// ?Spawn@idAnimCamera@@QAAXXZ
// EA  : 0x82C065F0
// RVA : 0x00C065F0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::Spawn(idAnimCamera *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v3; // r28
  idDeclMD6 *decl; // r26
  _DWORD *v5; // r29
  idIndex<short,enum invalidUserChannelIndex_t> *v6; // r25
  int i; // r11
  idGameTimeManager *v8; // r3
  __int16 v9; // r3
  const idMD6Anim *v10; // r3
  int len; // r8
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> v12; // [sp+50h] [-90h] BYREF
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> v13; // [sp+52h] [-8Eh] BYREF
  idMD6Skel v14; // [sp+54h] [-8Ch] BYREF
  int v15; // [sp+88h] [-58h]
  int v16; // [sp+8Ch] [-54h]
  int v17; // [sp+90h] [-50h]
  float v18; // [sp+94h] [-4Ch]

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: RenderModelFromPresentable,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  if ( v3 == nullptr )
    idLib::Error(fmt: "Camera '%s' has no animated model.", this->name.data);
  decl = v3->decl;
  if ( decl != nullptr )
    v5 = &decl->model->__vftable;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
    v6 = (idIndex<short,enum invalidUserChannelIndex_t> *)v5[53];
  else
    v6 = nullptr;
  if ( v6 == nullptr )
  {
    if ( decl == nullptr )
      idLib::Warning(fmt: "Camera '%s' has tree animator without valid decl", this->name.data);
    if ( v5 != nullptr )
    {
      idLib::Warning(fmt: "Camera '%s' is missing valid skeleton for model '%s'", this->name.data, v5[2]);
    }
    else if ( decl != nullptr )
    {
      idLib::Warning(fmt: "Camera '%s' is missing valid model for decl '%s'", this->name.data, decl->name.str);
    }
    idLib::Error(fmt: "Camera '%s' is incorrectly setup", this->name.data);
  }
  for ( i = 0; i < v5[38]; ++i )
    v3->meshVisibility.list[i] = false;
  idAnimStack::Init(this: &this->animStack, treeAnimator: v3);
  v14.nextOnHashChain = (idResource *)this->GetAnimStack_2(this);
  idStr::idStr(this: (idStr *)&v14.resourceListPtr, text: "camera");
  v15 = 0;
  v16 = 0;
  *(_DWORD *)&v14.jointConversion.value = 1;
  v17 = 0;
  v18 = 1.0;
  v8 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(
    this: &this->channelAnimator,
    gametimeManager: v8,
    parms: (const idAnimatorParms_Base *)&v14.nextOnHashChain);
  v9 = HIWORD(idTreeAnimator::GetJointIndex(
                this: (idTreeAnimator *)&v14,
                result: (idIndex<short,enum invalidJointIndex_t> *)v3,
                jointName: this->cameraJointName.data)->__vftable);
  this->camJointIdx.value = v9;
  if ( v9 < 0 )
    idLib::Error(fmt: "Camera model '%s' has no joint named '%s", v3->name.str, this->cameraJointName.data);
  gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v3, a3: &this->animationName, a4: this->name.data);
  v10 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->animationName, load: false);
  len = this->cameraFovChannel.len;
  this->camAnim = v10;
  if ( len != 0 )
  {
    ((void (__fastcall *)(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *))animation->FindUserChannelHandle)(a1: &v12);
    if ( v12.value != 0xFFFF )
      this->camFovChannel.value = HIWORD(idMD6Skel::GetUserChannelIndex(this: &v14, result: v6, handle: &v12)->__vftable);
  }
  if ( this->cameraDofChannel.len != 0 )
  {
    ((void (__fastcall *)(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *))animation->FindUserChannelHandle)(a1: &v13);
    if ( v13.value != 0xFFFF )
      this->camDofChannel.value = HIWORD(idMD6Skel::GetUserChannelIndex(this: &v14, result: v6, handle: &v13)->__vftable);
  }
  idStr::FreeData(this: (idStr *)&v14.resourceListPtr);
}


// ========================================================================
// $LN117
// EA  : 0x82C06898
// RVA : 0x00C06898
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _LN117()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 224 + 96));
}


// ========================================================================
// ?Unpause@idAnimCamera@@QAAXXZ
// EA  : 0x82C068C0
// RVA : 0x00C068C0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::Unpause(idAnimCamera *this)
{
  int value; // r29
  int GameMs; // r3
  int v4; // r9
  idTypesafeNumber<int,enum gameTimeUnique_t> v5[12]; // [sp+50h] [-30h] BYREF

  value = this->animStack.pauseTime.value;
  this->waitingForKey = false;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v4 = this->startTime + GameMs - value;
  v5[0].value = GameMs - value;
  this->startTime = v4;
  idAnimEventHandler::OffsetTimes(this: &this->animEventHandler, timeOffset: v5);
  v5[0].value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimStack::Unpause(this: &this->animStack, curTime: v5);
}


// ========================================================================
// ?SetCameraAnim@idAnimCamera@@QAAXPBD@Z
// EA  : 0x82C06940
// RVA : 0x00C06940
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __fastcall idAnimCamera::SetCameraAnim(idAnimCamera *this, char *name)
{
  idPresentable *presentable; // r11
  idTreeAnimator *treeAnimator; // r30
  const idMD6Alias *Alias; // r3
  char *str; // r4
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v8[24]; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  treeAnimator = this->animStack.treeAnimator;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( treeAnimator != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)v8, result: treeAnimator->decl, aliasName: name);
    if ( v8[0].value == 0xFFFF )
    {
      str = name;
    }
    else
    {
      Alias = idDeclMD6::FindAlias(this: treeAnimator->decl, aliasHandle: v8, includeInherited: true);
      if ( Alias == nullptr )
        goto LABEL_9;
      str = (char *)Alias->animRefs.list[idRandom2::RandomInt(this: &clientGame->random, max: Alias->animRefs.num)].str;
    }
    this->camAnim = (const idMD6Anim *)idResourceList::Load(
                                         this: &idMD6Anim::resourceList,
                                         name: str,
                                         makeDefault: true,
                                         skipStaleCheck: false);
LABEL_9:
    if ( this->camAnim == nullptr )
      idLib::Error(fmt: "Invalid camera anim '%s' on camera '%s", name, this->name.data);
  }
}


// ========================================================================
// ?InternalDeactivate@idAnimCamera@@MAA_NXZ
// EA  : 0x82C06A20
// RVA : 0x00C06A20
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

BOOL __fastcall idAnimCamera::InternalDeactivate(idAnimCamera *this)
{
  idPlayer *PlayerActivator; // r30
  idEntity *v3; // r3
  idPresentable *v4; // r3
  float *v5; // r3
  idPresentable *v6; // r3
  const idAngles *v7; // r4
  idQuat *ViewAngles; // r3
  idPresentable *presentable; // r3
  int v11; // r3
  idPlayerHud::hudState_t prevHudState; // r29
  idPlayerHud *PlayerHud; // r3
  int value; // r10
  idEntity *v15; // r3
  idEntity *v16; // r3
  int v17; // r3
  idMat3 v18; // [sp+50h] [-50h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
  {
    idMat3::ToAngles(this: &v18, result: (idAngles *)&this->camAxis);
    v18.mat[0].z = 0.0;
    idPlayer::SetViewAngles(this: PlayerActivator, angles: (const idAngles *)&v18, force: true);
    idPlayer::CalculateView(this: PlayerActivator);
  }
  if ( this->exitBlendTime <= 0 || this->endTime != 0 )
  {
    if ( PlayerActivator != nullptr )
    {
      presentable = PlayerActivator->presentable;
      v11 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
      *(float *)(v11 + 19128) = 0.0;
      *(_BYTE *)(v11 + 19040) = 1;
      *(_BYTE *)(v11 + 18122) = 0;
      *(_BYTE *)(v11 + 18121) = 0;
      idPlayer::RemoveControl(this: PlayerActivator, entity: this);
      prevHudState = this->prevHudState;
      PlayerHud = idPlayer::GetPlayerHud(this: PlayerActivator);
      idPlayerHud::SetHudState(this: PlayerHud, state: prevHudState);
      *(_BYTE *)&PlayerActivator->flags |= 2u;
      if ( this->hidePlayer )
        idPlayer::ShowHands(this: PlayerActivator);
    }
    value = this->triggerWhenDone.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v15 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v15 != nullptr )
        v16 = idEntity::CastTo(c: v15);
      else
        v16 = nullptr;
      idEntity::Activate(this: v16, activator: this);
    }
    if ( idEntity::GetBindMaster(this) != nullptr )
      idEntity::Unbind(this);
    idEntity::BecomeInactive(this, flags: 5);
    v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_Base::End(
      this: &this->channelAnimator,
      stack: &this->animStack,
      curTime: v17,
      blendDurationMS: 0,
      reset: true);
    idCVar::SetInteger(this: &r_skipAdaptiveGlare, newValue: this->oldSkipAdaptiveGlare, force: true);
    return idCameraView::InternalDeactivate(this);
  }
  else
  {
    if ( gameLocal->spawnIds.ptr[this->triggerWhenDone.spawnId.value & 0x1FFF] == this->triggerWhenDone.spawnId.value >> 13 )
    {
      v3 = idEntityPtr<idEntity const>::operator->(this: &this->triggerWhenDone);
      idEntity::Activate(this: v3, activator: this);
    }
    if ( PlayerActivator != nullptr )
    {
      v4 = PlayerActivator->presentable;
      if ( v4 != nullptr )
        v5 = (float *)v4->GetPlayerInterface_2(this: v4);
      else
        v5 = nullptr;
      this->startPos.x = v5[11633];
      this->startPos.y = v5[11634];
      this->startPos.z = v5[11635];
      v6 = PlayerActivator->presentable;
      if ( v6 != nullptr )
        v7 = (const idAngles *)v6->GetPlayerInterface_2(this: v6);
      else
        v7 = nullptr;
      ViewAngles = (idQuat *)idPresentablePlayer::GetViewAngles(
                               this: (idPresentablePlayer *)&v18,
                               result: v7,
                               includeWeaponKick: true);
      this->startQuat = *idAngles::ToQuat(this: (idAngles *)&v18.mat[1].y, result: ViewAngles);
    }
    this->endTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEventReceiver::PostEventMS(this, ev: &EV_Deactivate, time: this->exitBlendTime);
    return false;
  }
}


// ========================================================================
// ?AnimEvent_CameraDepthOfField@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82C06D18
// RVA : 0x00C06D18
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraDepthOfField(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        double blurStart,
        double blurScale,
        double duration)
{
  char v8; // [sp+60h] [-20h] BYREF

  idAnimCamera::AnimEvent_CameraRenderParm(
    this: (idAnimCamera *)&v8,
    result,
    animHandle,
    renderParmName: "depthoffield",
    x: blurStart,
    y: blurScale,
    z: 0.0,
    w: 0.0,
    duration);
  return this;
}


// ========================================================================
// ?Think@idAnimCamera@@UAAXXZ
// EA  : 0x82C06DB0
// RVA : 0x00C06DB0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimCamera::Think(idAnimCamera *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v3; // r29
  idMat3 *p_camAxis; // r30
  idVec3 *p_camPos; // r28
  int value; // r10
  int v7; // r9
  BOOL v8; // r27
  char *v9; // r8
  int v10; // r6
  __int64 v11; // r10
  int GameMs; // r3
  __int64 v13; // r11 OVERLAPPED
  double y; // fp9
  double v15; // fp30
  double v16; // fp1
  double v17; // fp12
  double v18; // fp9
  double v19; // fp11
  double v20; // fp7
  const idQuat *v21; // r3
  idMat3 *v22; // r3
  int v23; // r3
  __int64 v24; // r11 OVERLAPPED
  double v25; // fp30
  double v26; // fp1
  double v27; // fp13
  double v28; // fp12
  double v29; // fp10
  double v30; // fp9
  const idQuat *v31; // r3
  idMat3 *v32; // r3
  idGameTimeManager *p_gameTimeManager; // r28
  idGameTimeManager *v34; // r27
  int GameMsPerFrame; // r24
  int PreviousGameMs; // r22
  int v37; // r3
  int remainingFrames; // r11
  int v39; // r11
  idMD6LeafPlay *LastPlayedLeaf; // r28
  int numLoops; // r11
  int v42; // r30
  const idAnimStack *v43; // r3
  signed int v44; // r30
  int v45; // r3
  idPlayer *PlayerActivator; // r3
  idPlayer *v47; // r28
  usercmd_t *p_prevcmd; // r30
  const idUCmdTracker *UCmdTracker2; // r3
  int buttons; // r11
  int v51; // r11
  idPresentable *presentable; // r3
  int v53; // r3
  int fadeTime; // r5
  idPresentable *v55; // r11
  idTreeAnimator *treeAnimator; // r30
  int v57; // r28
  const char *v58; // r27
  const char *v59; // r29
  idAnimStack *v60; // r3
  float *v61; // [sp+8h] [-128h]
  float *v62; // [sp+Ch] [-124h]
  float *v63; // [sp+10h] [-120h]
  idMat3 v64; // [sp+70h] [-C0h] BYREF
  idMat3 v65; // [sp+A0h] [-90h] BYREF

  if ( (this->thinkFlags & 1) == 0 )
    return;
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: RenderModelFromPresentable,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  if ( v3 == nullptr )
    return;
  idEntity::RunPhysics(this);
  this->UpdateModelTransform(this);
  p_camAxis = &this->camAxis;
  p_camPos = &this->camPos;
  idTreeAnimator::GetWorldSpaceJointTransform(
    this: v3,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->camJointIdx.value,
    origin: &this->camPos,
    axis: &this->camAxis);
  value = this->camFovChannel.value;
  v7 = this->camDofChannel.value;
  if ( value >= 0 || (v8 = v7 >= 0) )
  {
    v9 = (char *)v3 + ((16 * v3->currentDeferred) ^ 0x10);
    if ( value >= 0 )
    {
      v10 = *((_DWORD *)v9 + 530);
      if ( *(float *)(4 * value + v10) > 0.0 )
        this->cameraFOV = *(float *)(4 * value + v10);
    }
    v8 = v7 >= 0;
    if ( v7 >= 0 )
      this->cameraDOF = *(float *)(4 * v7 + *((_DWORD *)v9 + 530));
  }
  if ( value < 0 )
  {
    LODWORD(v11) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    *(_QWORD *)&v64.mat[0].x = v11;
    this->cameraFOV = idInterpolate<float>::GetCurrentValue(this: &this->camFov, time: (float)v11);
  }
  if ( !v8 )
    this->cameraDOF = -1.0;
  if ( this->initialBlendTime > 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v13) = this->initialBlendTime;
    HIDWORD(v13) = GameMs - this->blendStartTime;
    if ( SHIDWORD(v13) >= (int)v13 )
    {
      if ( this->isBlendingIn )
      {
        this->isBlendingIn = false;
        idAnimCamera::Unpause(this);
      }
    }
    else
    {
      y = this->startPos.y;
      v15 = (float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13);
      v16 = (float)(p_camPos->x * (float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13));
      *(_QWORD *)&v64.mat[0].x = *(__int64 *)((char *)&v13 + 4);
      v17 = (float)((float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13) * this->camPos.z);
      v19 = (float)(this->startPos.x * (float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13)));
      v20 = (float)((float)((float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13) * this->camPos.y)
                  + (float)((float)y * (float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13))));
      v18 = (float)(this->startPos.z * (float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v13 + 4) / (float)v13)));
      this->camPos.y = v20;
      this->camPos.z = (float)v17 + (float)v18;
      p_camPos->x = (float)v16 + (float)v19;
      v21 = idMat3::ToQuat(this: &v64, result: (idQuat *)&this->camAxis);
      idQuat::Slerp(this: (idQuat *)&v65, from: &this->startQuat, to: v21, t: v15);
      v22 = idQuat::ToMat3(this: (idQuat *)&v64, result: &v65);
      p_camAxis->mat[0].x = v22->mat[0].x;
      this->camAxis.mat[0].y = v22->mat[0].y;
      this->camAxis.mat[0].z = v22->mat[0].z;
      this->camAxis.mat[1] = v22->mat[1];
      this->camAxis.mat[2] = v22->mat[2];
    }
  }
  if ( this->exitBlendTime > 0 && this->endTime != 0 )
  {
    v23 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v24) = this->exitBlendTime;
    HIDWORD(v24) = v23 - this->endTime;
    if ( SHIDWORD(v24) < (int)v24 )
    {
      v25 = (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24);
      v26 = (float)(this->startPos.x * (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24));
      v27 = (float)(this->startPos.y * (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24));
      *(_QWORD *)&v64.mat[0].x = *(__int64 *)((char *)&v24 + 4);
      v28 = (float)(this->startPos.z * (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24));
      v29 = (float)((float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24)) * this->camPos.y);
      v30 = (float)((float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24)) * this->camPos.z);
      p_camPos->x = (float)(p_camPos->x
                          * (float)((float)1.0 - (float)((float)*(__int64 *)((char *)&v24 + 4) / (float)v24)))
                  + (float)v26;
      this->camPos.y = (float)v29 + (float)v27;
      this->camPos.z = (float)v30 + (float)v28;
      v31 = idMat3::ToQuat(this: &v64, result: (idQuat *)&this->camAxis);
      idQuat::Slerp(this: (idQuat *)&v65.mat[1].y, from: v31, to: &this->startQuat, t: v25);
      v32 = idQuat::ToMat3(this: (idQuat *)&v64, result: (idMat3 *)&v65.mat[1].y);
      p_camAxis->mat[0].x = v32->mat[0].x;
      this->camAxis.mat[0].y = v32->mat[0].y;
      this->camAxis.mat[0].z = v32->mat[0].z;
      this->camAxis.mat[1] = v32->mat[1];
      this->camAxis.mat[2] = v32->mat[2];
    }
  }
  if ( (this->thinkFlags & 4) != 0 )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    v34 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v37 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimStack::BlendStackInternal(
      this: &this->animStack,
      currentTime: v37,
      previousTime: PreviousGameMs,
      gameMsPerFrame: GameMsPerFrame,
      ticksPerSec: v34,
      game: p_gameTimeManager,
      parallelJobList: gameLocal->parallelJobList,
      localR: nullptr,
      localS: v61,
      localT: v62,
      localU: v63);
  }
  if ( this->GetAnimStack_2(this)->pauseTime.value < 0 )
  {
    remainingFrames = this->remainingFrames;
    if ( remainingFrames > 0 )
    {
      v39 = remainingFrames - 1;
      this->remainingFrames = v39;
      if ( v39 == 0 )
        idEventReceiver::ProcessEvent(this: (idEventReceiver *)&v64, result: (idEventArg *)this, ev: &EV_Deactivate);
      goto LABEL_37;
    }
    if ( remainingFrames < 0 )
    {
      LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
      if ( LastPlayedLeaf == nullptr )
        goto LABEL_36;
      numLoops = this->numLoops;
      if ( numLoops != 1 )
      {
        if ( numLoops <= 1 )
          goto LABEL_37;
        v44 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v45 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        if ( (signed int)idMD6LeafPlay::GetLoopCount(this: LastPlayedLeaf, gameTime: v45, ticksPerSec: v44) < this->numLoops )
          goto LABEL_37;
        goto LABEL_36;
      }
      v42 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v43 = this->GetAnimStack_2(this);
      if ( idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v43, curTime: v42) )
LABEL_36:
        this->remainingFrames = 1;
    }
  }
LABEL_37:
  idEntity::UpdateVisuals(this);
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v47 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    if ( (*((_BYTE *)&idPlayer::GetUCmdTracker2(this: PlayerActivator)->usercmd + 9) & 0x80) == 0 )
    {
      p_prevcmd = &idPlayer::GetUCmdTracker2(this: v47)->prevcmd;
      UCmdTracker2 = idPlayer::GetUCmdTracker2(this: v47);
      LOBYTE(buttons) = 0;
      if ( (*((_BYTE *)&UCmdTracker2->usercmd + 9) & 0x80) == 0 )
        buttons = UCmdTracker2->usercmd.buttons;
      if ( (buttons & 5) != 0 )
      {
        LOBYTE(v51) = 0;
        if ( (*((_BYTE *)p_prevcmd + 9) & 0x80) == 0 )
          v51 = p_prevcmd->buttons;
        if ( (v51 & 5) == 0 )
          goto LABEL_46;
      }
      if ( p_prevcmd->upmove != UCmdTracker2->usercmd.upmove )
      {
LABEL_46:
        if ( this->waitingForKey )
        {
          idAnimCamera::Unpause(this);
        }
        else if ( this->abortable )
        {
          idEventReceiver::ProcessEvent(this: (idEventReceiver *)&v64, result: (idEventArg *)this, ev: &EV_Deactivate);
          return;
        }
      }
    }
    presentable = v47->presentable;
    if ( presentable != nullptr )
      v53 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v53 = 0;
    fadeTime = this->screenFade.fadeTime;
    if ( fadeTime >= 0 )
    {
      idView::Fade(this: (idView *)(v53 + 16224), color: &this->screenFade.fadeColor, time: fadeTime);
      this->screenFade.fadeTime = -1;
    }
    v55 = this->presentable;
    treeAnimator = this->animStack.treeAnimator;
    if ( v55 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v55 = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: v55);
    if ( this->GetAnimStack_2(this)->pauseTime.value < 0 )
    {
      v57 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v58 = (const char *)idGameTimeManager::GetPreviousGameMs(
                            this: &clientGame->gameTimeManager,
                            type: GAMETIME_SCALED);
      v59 = (const char *)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v60 = this->GetAnimStack_2(this);
      idAnimEventHandler::BuildAnimEventList(
        this: &this->animEventHandler,
        decl: treeAnimator->decl,
        tree: v60->tree,
        curTime: v59,
        previousTime: v58,
        ticksPerSec: v57,
        onlyEvents: nullptr,
        onlyNumEvents: 0);
      idEventReceiver::ProcessAnimEvents(this, handler: &this->animEventHandler);
    }
  }
  if ( this->shouldPause )
  {
    idAnimCamera::Pause(this);
    this->shouldPause = false;
  }
}


// ========================================================================
// ?AnimEvent_Trigger@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C07568
// RVA : 0x00C07568
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_Trigger(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *entityName)
{
  idEntity *v7; // r28
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3

  v7 = gameLocal->FindEntity(this: gameLocal, a2: entityName);
  if ( v7 != nullptr )
  {
    v9 = *(_DWORD *)&result[800];
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      idEntity::Activate(this: v7, activator: v11);
      return this;
    }
    else
    {
      idEntity::Activate(this: v7, activator: nullptr);
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "EV_Trigger - failed to find entity '%s'", entityName);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_CameraTeleportClient@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82C07630
// RVA : 0x00C07630
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraTeleportClient(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idVec3 *pos,
        const idAngles *angles)
{
  int v5; // r10
  idEntity *v9; // r3
  idEntity *v10; // r3

  v5 = *(_DWORD *)&result[800];
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 )
  {
    v9 = gameLocal->entities.ptr[v5 & 0x1FFF];
    if ( v9 != nullptr )
      v10 = idEntity::CastTo(c: v9);
    else
      v10 = nullptr;
    v10->Teleport(this: v10, a2: pos, a3: angles);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_CameraSetJoint@idAnimCamera@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82C076C8
// RVA : 0x00C076C8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::AnimEvent_CameraSetJoint(
        idAnimCamera *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idJointName *jointName)
{
  size_t len; // r30
  char v9; // [sp+50h] [-30h] BYREF

  len = jointName->len;
  idStr::EnsureAlloced(this: (idStr *)&result[880], amount: jointName->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: *(void **)&result[884], Src: jointName->data, Size: len);
  *(_BYTE *)(*(_DWORD *)&result[884] + len) = 0;
  *(_DWORD *)&result[880] = len;
  *(_WORD *)&result[2788] = HIWORD(idTreeAnimator::GetJointIndex(
                                     this: (idTreeAnimator *)&v9,
                                     result: *(idIndex<short,enum invalidJointIndex_t> **)&result[1076],
                                     jointName: *(const char **)&result[884])->__vftable);
  return this;
}


// ========================================================================
// ??0idAnimCamera@@QAA@XZ
// EA  : 0x82C07748
// RVA : 0x00C07748
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

idAnimCamera *__fastcall idAnimCamera::idAnimCamera(idAnimCamera *this)
{
  float *p_z; // r9
  float *p_y; // r10
  int i; // ctr
  double currentValue; // fp0
  float w; // r9

  idCameraView::idCameraView(this);
  this->__vftable = (idAnimCamera_vtbl *)&idAnimCamera::`vftable';
  idStr::idStr(this: &this->cameraJointName, text: "camera");
  this->cameraFovChannel.len = 0;
  this->cameraFovChannel.allocedAndFlag = 20;
  this->cameraFovChannel.data = this->cameraFovChannel.baseBuffer;
  this->cameraFovChannel.baseBuffer[0] = 0;
  this->cameraDofChannel.allocedAndFlag = 20;
  this->cameraDofChannel.len = 0;
  this->cameraDofChannel.data = this->cameraDofChannel.baseBuffer;
  this->cameraDofChannel.baseBuffer[0] = 0;
  this->animationName.value = -1;
  this->guiName.allocedAndFlag = 20;
  this->guiName.data = this->guiName.baseBuffer;
  this->guiName.len = 0;
  this->guiName.baseBuffer[0] = 0;
  this->abortable = false;
  this->useDebugPlayerIfNeeded = false;
  this->forceVirtualMaterialLoad = false;
  this->numLoops = 1;
  this->initialFov = 80.0;
  this->hidePlayer = true;
  this->initialBlendTime = 500;
  this->startCamAnimImmediately = true;
  this->exitBlendTime = 500;
  this->triggerWhenDone.spawnId.value = 0x1FFF;
  this->targetAspect = 1.7777778;
  this->shouldPauseOnStart = false;
  this->fadeInOnStart = false;
  *(_WORD *)&this->drawPlayerGUIS = 1;
  *(_WORD *)&this->useHighQualityMipGeneration = 1;
  this->hasActivated = false;
  this->shouldPause = false;
  this->waitingForKey = false;
  this->cinematicHands.spawnId.value = 0x1FFF;
  this->blendAngleOffset = ang_zero;
  idAnimStack::idAnimStack(this: &this->animStack);
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  p_z = &this->camPos.z;
  this->camPos.x = 0.0;
  this->camPos.y = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->camPos.z = 0.0;
  for ( i = 9; i != 0; --i )
    *++p_z = *++p_y;
  this->camJointIdx.value = -1;
  this->camAnim = nullptr;
  this->camFov.duration = 0.0;
  this->camFov.startTime = 0.0;
  this->camFov.currentTime = 0.0;
  this->camFov.currentValue = 0.0;
  currentValue = this->camFov.currentValue;
  this->camFov.endValue = this->camFov.currentValue;
  this->camFov.startValue = currentValue;
  this->camFovChannel.value = -1;
  this->camDofChannel.value = -1;
  this->prevHudState = HUDSTATE_NONE;
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  this->offset.z = 0.0;
  idAnimEventHandler::idAnimEventHandler(this: &this->animEventHandler);
  this->remainingFrames = 0;
  idRenderParmLerp::idRenderParmLerp(this: &this->depthOfField, renderParmName: "depthoffield", _numValues: 4);
  idRenderParmLerp::idRenderParmLerp(this: &this->fogColor, renderParmName: "fogcolor", _numValues: 4);
  idRenderParmLerp::idRenderParmLerp(this: &this->fogScale, renderParmName: "fogscale", _numValues: 1);
  this->overrideDOFMask = 0;
  this->blendStartTime = 0;
  this->startTime = 0;
  this->endTime = 0;
  this->startPos = vec3_origin;
  this->startQuat.x = quat_identity.x;
  this->startQuat.y = quat_identity.y;
  this->startQuat.z = quat_identity.z;
  w = quat_identity.w;
  this->cameraFOV = 80.0;
  this->cameraDOF = -1.0;
  this->startQuat.w = w;
  this->isBlendingIn = false;
  this->oldSkipAdaptiveGlare = 0;
  this->screenFade.fadeTime = -1;
  this->screenFade.fadeColor.x = 0.0;
  this->screenFade.fadeColor.y = 0.0;
  this->screenFade.fadeColor.z = 0.0;
  this->screenFade.fadeColor.w = 1.0;
  this->renderParms[0] = nullptr;
  this->renderParms[1] = nullptr;
  this->renderParms[2] = nullptr;
  this->renderParms[0] = &this->depthOfField;
  this->renderParms[1] = &this->fogColor;
  this->renderParms[2] = &this->fogScale;
  this->camFov.startTime = 0.0;
  this->camFov.duration = 0.0;
  this->camFov.startValue = 80.0;
  this->camFov.endValue = 80.0;
  this->camFov.currentTime = -1.0;
  this->camFov.currentValue = 80.0;
  return this;
}


// ========================================================================
// __unwind$492264
// EA  : 0x82C07A78
// RVA : 0x00C07A78
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492264()
{
  int v0; // r12

  idCameraView::~idCameraView(this: *(idCameraView **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$492265
// EA  : 0x82C07AA0
// RVA : 0x00C07AA0
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 880));
}


// ========================================================================
// __unwind$492266
// EA  : 0x82C07ACC
// RVA : 0x00C07ACC
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492266()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 912));
}


// ========================================================================
// __unwind$492267_0
// EA  : 0x82C07AF8
// RVA : 0x00C07AF8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492267_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 944));
}


// ========================================================================
// __unwind$492268_0
// EA  : 0x82C07B24
// RVA : 0x00C07B24
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492268_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 980));
}


// ========================================================================
// __unwind$492269
// EA  : 0x82C07B50
// RVA : 0x00C07B50
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492269()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 176 + 196) + 1072));
}


// ========================================================================
// __unwind$492270_0
// EA  : 0x82C07B7C
// RVA : 0x00C07B7C
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492270_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 176 + 196) + 2644));
}


// ========================================================================
// __unwind$492271_0
// EA  : 0x82C07BA8
// RVA : 0x00C07BA8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void _unwind_492271_0()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 176 + 196) + 2840));
}


// ========================================================================
// ?InternalActivate@idAnimCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82C07BD8
// RVA : 0x00C07BD8
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

BOOL __fastcall idAnimCamera::InternalActivate(idAnimCamera *this, idEntity *activator_)
{
  idPlayer *PlayerActivator; // r30
  idPlayer *DebugPlayer; // r3
  idPresentable *presentable; // r3
  int v7; // r11
  idPlayerHud *PlayerHud; // r3
  int (*GetGameMs)(void); // ctr
  int v10; // r3
  const blendParms_t *v11; // r7
  int v12; // r3
  __int64 v13; // r8
  int GameMs; // r3
  idPresentable *v15; // r3
  float *v16; // r3
  idPresentable *v17; // r3
  const idAngles *v18; // r4
  idQuat *ViewAngles; // r3
  BOOL adaptiveGlare; // r10
  char v21; // [sp+50h] [-70h] BYREF
  idAngles v22; // [sp+60h] [-60h] BYREF
  blendParms_t v23; // [sp+70h] [-50h] BYREF

  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  if ( this->shouldPauseOnStart )
  {
    if ( this->hasActivated )
    {
      idAnimCamera::Unpause(this);
      return false;
    }
    this->shouldPause = true;
  }
  this->hasActivated = true;
  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
    goto LABEL_13;
  if ( this->useDebugPlayerIfNeeded )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    PlayerActivator = DebugPlayer;
    if ( DebugPlayer == nullptr )
    {
      this->activator.spawnId.value = 0x1FFF;
      goto LABEL_33;
    }
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[DebugPlayer->entityNumber] << 13)
                                  | DebugPlayer->entityNumber;
LABEL_13:
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    *(_BYTE *)(v7 + 19040) = 0;
    this->prevHudState = idPlayer::GetPlayerHud(this: PlayerActivator)->hudState;
    PlayerHud = idPlayer::GetPlayerHud(this: PlayerActivator);
    idPlayerHud::SetHudState(this: PlayerHud, state: HUDSTATE_NONE);
    *(_BYTE *)&PlayerActivator->flags &= ~2u;
    if ( this->hidePlayer )
      idPlayer::HideHands(this: PlayerActivator);
    if ( this->fadeInOnStart )
    {
      this->screenFade.fadeColor.x = 0.0;
      this->screenFade.fadeColor.y = 0.0;
      this->screenFade.fadeColor.z = 0.0;
      this->screenFade.fadeColor.w = 0.0;
      this->screenFade.fadeTime = 1000;
    }
    idEntity::BecomeActive(this, flags: 5);
    g_startTimeMs = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    blendParms_t::blendParms_t(this: &v23);
    GetGameMs = (int (*)(void))gameLocal->GetGameMs;
    if ( this->numLoops == 1 )
    {
      v10 = GetGameMs();
      idAnimator_Channel::PlayAnim(
        this: &this->channelAnimator,
        stack: &this->animStack,
        ah: this->camAnim,
        curTime: v10,
        rateScale: 1.0,
        blendParms: v11,
        blendOutDurationMS_: &v23,
        leafStarted: nullptr,
        a9: nullptr);
    }
    else
    {
      v12 = GetGameMs();
      LODWORD(v13) = &v23;
      idAnimator_Channel::CycleAnim(
        this: &this->channelAnimator,
        stack: &this->animStack,
        ah: this->camAnim,
        curTime: v12,
        rateScale: 1.0,
        leafStarted: v13,
        a7: nullptr);
    }
    if ( this->initialBlendTime > 0 && !this->startCamAnimImmediately )
    {
      this->isBlendingIn = true;
      this->shouldPause = true;
    }
    this->remainingFrames = -1;
    this->camFov.startTime = 0.0;
    this->camFov.duration = 0.0;
    this->camFov.startValue = this->initialFov;
    this->camFov.endValue = this->initialFov;
    this->camFov.currentTime = -1.0;
    this->camFov.currentValue = this->initialFov;
    this->cameraFOV = this->initialFov;
    this->cameraDOF = -1.0;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->endTime = 0;
    this->startTime = GameMs;
    this->blendStartTime = GameMs;
    v15 = PlayerActivator->presentable;
    if ( v15 != nullptr )
      v16 = (float *)v15->GetPlayerInterface_2(this: v15);
    else
      v16 = nullptr;
    this->startPos.x = v16[11633];
    this->startPos.y = v16[11634];
    this->startPos.z = v16[11635];
    v17 = PlayerActivator->presentable;
    if ( v17 != nullptr )
      v18 = (const idAngles *)v17->GetPlayerInterface_2(this: v17);
    else
      v18 = nullptr;
    ViewAngles = (idQuat *)idPresentablePlayer::GetViewAngles(
                             this: (idPresentablePlayer *)&v21,
                             result: v18,
                             includeWeaponKick: true);
    this->startQuat = *idAngles::ToQuat(this: &v22, result: ViewAngles);
  }
LABEL_33:
  adaptiveGlare = this->adaptiveGlare;
  this->oldSkipAdaptiveGlare = r_skipAdaptiveGlare.valueInteger;
  idCVar::SetInteger(this: &r_skipAdaptiveGlare, newValue: !adaptiveGlare, force: true);
  return idCameraView::InternalActivate(this, activator_: PlayerActivator);
}


// ========================================================================
// `dynamic initializer for 'g_debugAnimCameraFocus''
// EA  : 0x83375028
// RVA : 0x01375028
// PDB : w:\tech5\tungsten\game\entities\animcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugAnimCameraFocus__()
{
  idCVar::idCVar(
    this: &g_debugAnimCameraFocus,
    name: "g_debugAnimCameraFocus",
    value: "0",
    flags: 1,
    description: "Show AnimCamera focal plane.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugAnimCameraFocus__);
}

