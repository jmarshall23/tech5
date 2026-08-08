
// ========================================================================
// ??1idAICamera_Control@@UAA@XZ
// EA  : 0x82A40C08
// RVA : 0x00A40C08
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

void __fastcall idAICamera_Control::~idAICamera_Control(idAICamera_Control *this)
{
  this->__vftable = (idAICamera_Control_vtbl *)&idAICamera_Control::`vftable';
}


// ========================================================================
// ??0idAICamera_Control@@QAA@XZ
// EA  : 0x82A40C18
// RVA : 0x00A40C18
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

idAICamera_Control *__fastcall idAICamera_Control::idAICamera_Control(idAICamera_Control *this)
{
  int v1; // ctr
  float *p_z; // r9
  float *p_y; // r10

  this->__vftable = (idAICamera_Control_vtbl *)&idAICamera_Control::`vftable';
  this->target = nullptr;
  this->flying = false;
  this->flyTo = vec3_origin;
  v1 = 9;
  p_z = &this->camPos.z;
  p_y = &mat2_identity.mat[1].y;
  this->camPos = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v1;
  }
  while ( v1 != 0 );
  this->interactionNormal = vec3_origin;
  this->angles.pitch = 0.0;
  this->angles.yaw = 0.0;
  this->angles.roll = 0.0;
  this->distance = 128.0;
  return this;
}


// ========================================================================
// ?FlyTo@idAICamera_Control@@QAAXABVidVec3@@@Z
// EA  : 0x82A40D28
// RVA : 0x00A40D28
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

void __fastcall idAICamera_Control::FlyTo(idAICamera_Control *this, const idVec3 *endPos)
{
  this->flying = true;
  this->flyTo = *endPos;
}


// ========================================================================
// ?Draw@idAICamera_Control@@QAAXPAVidPlayer@@@Z
// EA  : 0x82A40D50
// RVA : 0x00A40D50
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

void __fastcall idAICamera_Control::Draw(idAICamera_Control *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idView *v5; // r31

  if ( this->target != nullptr )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    v5 = (idView *)(v4 + 16224);
    idView::SetViewID(this: (idView *)(v4 + 16224), id: this->target->entityNumber + 1);
    idView::SetViewPos(this: v5, origin: &this->camPos, axis: &this->camAxis);
    idView::Render(this: v5);
  }
}


// ========================================================================
// ?Update@idAICamera_Control@@QAAXABVusercmd_t@@0_N@Z
// EA  : 0x82A40DE0
// RVA : 0x00A40DE0
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAICamera_Control::Update(
        idAICamera_Control *this,
        const usercmd_t *prevcmd,
        const usercmd_t *curcmd,
        bool actionScriptRunning)
{
  idAnimatedEntity *target; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const tagData_t *Tag; // r3
  char *v11; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r11
  int i; // ctr
  idTreeAnimator *v14; // r3
  int v15; // r2 OVERLAPPED
  double x; // fp31
  double y; // fp30
  double z; // fp29
  float v19; // r10
  float v20; // r9
  idAI2 *v21; // r3
  idAI2 *v22; // r30
  double v23; // fp9
  idAnimatedEntity *v24; // r10
  double v25; // fp4
  idPhysics *Physics; // r3
  const idVec3 *v27; // r3
  unsigned int v28; // r8 OVERLAPPED
  int v29; // r3
  __int64 v30; // r7 OVERLAPPED
  __int64 v31; // r10
  double v32; // fp4
  idVec3 *p_angles; // r4
  double v34; // fp2
  double v35; // fp13
  double v36; // fp1
  double v37; // fp8
  idAnimatedEntity *v38; // r10
  double v39; // fp3
  float v40; // r9
  double v41; // fp8
  float v42; // r8
  double v43; // fp7
  double v44; // fp6
  double v45; // fp10
  double valueFloat; // fp0
  double v47; // fp1
  double v48; // fp11
  double v49; // fp10
  double v50; // fp1
  double v51; // fp12
  double v52; // fp10
  double v55; // fp4
  double v56; // fp3
  double v57; // fp11
  double v58; // fp6
  double v59; // fp4
  double v60; // fp11
  double v61; // fp13
  double v62; // fp2
  double v63; // fp12
  idVec3 v64; // [sp+50h] [-1D0h] BYREF
  __int64 v65; // [sp+60h] [-1C0h]
  float v66; // [sp+68h] [-1B8h]
  idVec3 v67; // [sp+70h] [-1B0h] BYREF
  idAngles v68; // [sp+80h] [-1A0h] BYREF
  idAngles v69; // [sp+90h] [-190h] BYREF
  idMat3 v70; // [sp+A0h] [-180h] BYREF
  float v71; // [sp+C4h] [-15Ch]
  float v72; // [sp+C8h] [-158h]
  idVec3 v73; // [sp+D0h] [-150h] BYREF
  char v74; // [sp+DCh] [-144h] BYREF
  tagData_t v75; // [sp+E0h] [-140h] BYREF
  trace_t v76; // [sp+100h] [-120h] BYREF
  idVec3 v77[4]; // [sp+180h] [-A0h] BYREF
  idMat3 v78; // [sp+1B0h] [-70h] BYREF

  target = this->target;
  if ( target != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: target);
    Tag = idPropsCollection::GetTag(
            this: &TreeAnimatorFromPresentable->decl->props,
            propName: idPropInfo::INFO_PROP_NAME,
            tagName: "mc_camera");
    v11 = &v74;
    p_parentJoint = &Tag[-1].parentJoint;
    for ( i = 8; i != 0; --i )
    {
      p_parentJoint += 2;
      v11 += 4;
      *(_DWORD *)v11 = *(_DWORD *)&p_parentJoint->value;
    }
    v14 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->target);
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(this: v14, tagData: &v75, origin: &v64, axis: &v78) == 0 )
      this->target->GetEyePos(this: this->target, a2: &v64);
    if ( this->flying )
    {
      x = this->flyTo.x;
      y = this->flyTo.y;
      z = this->flyTo.z;
    }
    else if ( actionScriptRunning )
    {
      v19 = this->interactionNormal.y;
      v20 = this->interactionNormal.z;
      v21 = (idAI2 *)this->target;
      v67.x = this->interactionNormal.x;
      v67.y = v19;
      v67.z = v20;
      v22 = idAI2::CastTo(c: v21);
      v70.mat[2].z = (float)(v67.x * (float)256.0) + v64.x;
      v71 = v64.y + (float)(v67.y * (float)256.0);
      v72 = v64.z + (float)(v67.z * (float)256.0);
      idAI2::SetIdealAimFocusPoint(
        this: v22,
        point: (const idVec3 *)&v70.mat[2].z,
        timeout: -1,
        focusType: AIFOCUS_CAMERA);
      v23 = (float)(v67.z * this->distance);
      v24 = this->target;
      v25 = (float)(v64.y - (float)(v67.y * this->distance));
      v73.x = v64.x - (float)(v67.x * this->distance);
      v73.y = v25;
      v73.z = v64.z - (float)v23;
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: &v76,
        start: &v64,
        end: &v73,
        trm: clientGame->clip.clip16x16,
        clipMask: 3,
        passEntityNumber: v24->entityNumber);
      x = v76.endpos.x;
      y = v76.endpos.y;
      z = v76.endpos.z;
      Physics = idEntity::GetPhysics(this: v22);
      v27 = Physics->GetGravityNormal(this: Physics);
      idVec3::ProjectOntoPlane(this: &v67, normal: v27, overBounce: 1.0);
      idAIOrientation::SetIdealDir(
        this: &v22->aiVolatile.physics.moveState.moveOrientation,
        ai: v22->aiVolatile.physics.moveState.ai,
        dir: &v67);
    }
    else
    {
      v28 = 0x82000000;
      v29 = prevcmd->angles[1];
      HIDWORD(v30) = (unsigned __int16)curcmd->angles[1];
      LODWORD(v31) = curcmd->angles[0];
      HIDWORD(v31) = SWORD1(v30);
      LODWORD(v30) = prevcmd->angles[0];
      v65 = v30;
      v68.roll = 0.0;
      v68.pitch = (float)((float)v31 * (float)0.0054931641) - (float)((float)v30 * (float)0.0054931641);
      v68.yaw = (float)((float)*(__int64 *)(&v28 - 1) * (float)0.0054931641)
              - (float)((float)*(__int64 *)(&v15 - 1) * (float)0.0054931641);
      idAngles::Normalize180(this: &v68);
      v32 = (float)(v68.pitch + this->angles.pitch);
      p_angles = (idVec3 *)&this->angles;
      v34 = (float)(this->angles.yaw + v68.yaw);
      v35 = 35.0;
      v36 = (float)(this->angles.roll + v68.roll);
      this->angles.pitch = v68.pitch + this->angles.pitch;
      this->angles.yaw = v34;
      this->angles.roll = v36;
      if ( v32 > 35.0 || (v35 = -35.0, v32 < -35.0) )
        p_angles->x = v35;
      idAngles::ToForward(this: &v69, result: p_angles);
      v37 = (float)(v69.roll * this->distance);
      v38 = this->target;
      v39 = (float)(v64.y - (float)(v69.yaw * this->distance));
      v70.mat[1].y = v64.x - (float)(v69.pitch * this->distance);
      v70.mat[1].z = v39;
      v70.mat[2].x = v64.z - (float)v37;
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: &v76,
        start: &v64,
        end: (const idVec3 *)&v70.mat[1].y,
        trm: clientGame->clip.clip16x16,
        clipMask: 3,
        passEntityNumber: v38->entityNumber);
      x = v76.endpos.x;
      y = v76.endpos.y;
      z = v76.endpos.z;
    }
    v40 = this->camPos.x;
    v41 = v64.y;
    v42 = this->camPos.y;
    v43 = v64.z;
    v44 = v64.x;
    v66 = this->camPos.z;
    v45 = v66;
    *(float *)&v65 = v40;
    *((float *)&v65 + 1) = v42;
    valueFloat = aiCam_lerpScale.valueFloat;
    v47 = (float)((float)((float)z - v66) * aiCam_lerpScale.valueFloat);
    v48 = (float)((float)((float)((float)y - v42) * aiCam_lerpScale.valueFloat) + v42);
    this->camPos.y = (float)((float)((float)y - v42) * aiCam_lerpScale.valueFloat) + v42;
    v49 = (float)((float)v47 + (float)v45);
    this->camPos.z = v49;
    v50 = (float)((float)v41 - (float)v48);
    this->camPos.x = (float)((float)((float)x - v40) * (float)valueFloat) + v40;
    v51 = (float)((float)v43 - (float)v49);
    v52 = (float)((float)v44 - (float)((float)((float)((float)x - v40) * (float)valueFloat) + v40));
    _FP6 = (float)((float)((float)((float)v52 * (float)v52)
                         + (float)((float)((float)v51 * (float)v51)
                                 + (float)((float)((float)v41 - (float)v48) * (float)((float)v41 - (float)v48))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f6, f7, f0 }
    v55 = (float)((float)((float)((float)v52 * (float)v52)
                        + (float)((float)((float)v51 * (float)v51)
                                + (float)((float)((float)v41 - (float)v48) * (float)((float)v41 - (float)v48))))
                * (float)0.5);
    v56 = __frsqrte(_FP5);
    v57 = (float)-(float)((float)((float)((float)v56
                                        * (float)((float)((float)((float)v52 * (float)v52)
                                                        + (float)((float)((float)v51 * (float)v51)
                                                                + (float)((float)((float)v41 - (float)v48)
                                                                        * (float)((float)v41 - (float)v48))))
                                                * (float)0.5))
                                * (float)v56)
                        - (float)1.5);
    v58 = (float)((float)-(float)((float)((float)((float)((float)v57 * (float)v56) * (float)v55)
                                        * (float)((float)v57 * (float)v56))
                                - (float)1.5)
                * (float)((float)v57 * (float)v56));
    v59 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v57 * (float)v56)
                                                                                * (float)v55)
                                                                        * (float)((float)v57 * (float)v56))
                                                                - (float)1.5)
                                                * (float)((float)v57 * (float)v56))
                                        * (float)v55)
                                * (float)((float)-(float)((float)((float)((float)((float)v57 * (float)v56) * (float)v55)
                                                                * (float)((float)v57 * (float)v56))
                                                        - (float)1.5)
                                        * (float)((float)v57 * (float)v56)))
                        - (float)1.5);
    v70.mat[0].x = (float)v52 * (float)((float)v59 * (float)v58);
    v70.mat[0].y = (float)v50 * (float)((float)v59 * (float)v58);
    v70.mat[0].z = (float)v51 * (float)((float)v59 * (float)v58);
    this->camAxis = *idVec3::ToMat3(this: v77, result: &v70);
    v60 = this->camPos.z;
    v61 = (float)(aiCam_scale.valueFloat * this->camAxis.mat[0].z);
    v62 = this->camPos.y;
    v63 = (float)(aiCam_scale.valueFloat * this->camAxis.mat[0].y);
    this->camPos.x = this->camPos.x - (float)(this->camAxis.mat[0].x * aiCam_scale.valueFloat);
    this->camPos.z = (float)v60 - (float)v61;
    this->camPos.y = (float)v62 - (float)v63;
  }
}


// ========================================================================
// `dynamic initializer for 'aiCam_lerpScale''
// EA  : 0x83366D40
// RVA : 0x01366D40
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aiCam_lerpScale__()
{
  idCVar::idCVar(
    this: &aiCam_lerpScale,
    name: "aiCam_lerpScale",
    value: "1.0f",
    flags: 4,
    description: "float",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aiCam_lerpScale__);
}


// ========================================================================
// `dynamic initializer for 'aiCam_scale''
// EA  : 0x83366D98
// RVA : 0x01366D98
// PDB : w:\tech5\tungsten\game\ai\aicamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aiCam_scale__()
{
  idCVar::idCVar(
    this: &aiCam_scale,
    name: "aiCam_scale",
    value: "0.0f",
    flags: 4,
    description: "float",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aiCam_scale__);
}

