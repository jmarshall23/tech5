
// ========================================================================
// ??1idAnimator_TrackerBase@@UAA@XZ
// EA  : 0x826EC738
// RVA : 0x006EC738
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::~idAnimator_TrackerBase(idAnimator_TrackerBase *this)
{
  this->parentTracker = nullptr;
  this->__vftable = (idAnimator_TrackerBase_vtbl *)&idAnimator_TrackerBase::`vftable';
  this->mergeBranch = nullptr;
  this->leaf = nullptr;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ??0idAnimator_TrackerBase@@QAA@XZ
// EA  : 0x826EC7D0
// RVA : 0x006EC7D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

idAnimator_TrackerBase *__fastcall idAnimator_TrackerBase::idAnimator_TrackerBase(idAnimator_TrackerBase *this)
{
  char v2; // r3

  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_TrackerBase_vtbl *)&idAnimator_TrackerBase::`vftable';
  this->parentTracker = nullptr;
  this->focusPoint = vec3_origin;
  this->yawRight.value = -90.0;
  this->yawLeft.value = 90.0;
  this->pitchUp.value = -90.0;
  this->pitchDown.value = 90.0;
  this->trackGroupIndex = -1;
  this->mergeBranch = nullptr;
  this->leaf = nullptr;
  this->msDirToFocus.x = 1.0;
  this->msDirToFocus.y = 0.0;
  this->msDirToFocus.z = 0.0;
  this->wsFocusJointPos.x = 0.0;
  this->wsFocusJointPos.y = 0.0;
  this->wsFocusJointPos.z = 0.0;
  this->msReferenceJointPos.x = 0.0;
  this->msReferenceJointPos.y = 0.0;
  this->msReferenceJointPos.z = 0.0;
  this->idealOffsetAngles = ang_zero;
  this->curOffsetAngles = ang_zero;
  this->lastAngles.pitch = ang_zero.pitch;
  v2 = *((_BYTE *)this + 180);
  this->lastAngles.yaw = ang_zero.yaw;
  this->lastAngles.roll = ang_zero.roll;
  *((_BYTE *)this + 180) = v2 & 3;
  this->focusPoints[0] = vec3_origin;
  this->focusPoints[1] = vec3_origin;
  return this;
}


// ========================================================================
// ?InternalInit@idAnimator_TrackerBase@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826EC9A8
// RVA : 0x006EC9A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

BOOL __fastcall idAnimator_TrackerBase::InternalInit(idAnimator_TrackerBase *this, const idAnimatorParms_Base *parms)
{
  idMD6LeafPause *v4; // r3
  BOOL result; // r3

  this->mergeBranch = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  v4 = (idMD6LeafPause *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 1);
  this->leaf = v4;
  idMD6LeafPause::Init(
    this: v4,
    anim: nullptr,
    frame: 0.0,
    wrapMode: (const idMD6Leaf::wrapMode_t)0x82000000,
    weightGroup: MD6_WEIGHTGROUP_ALL);
  result = this->mergeBranch != nullptr;
  *((_BYTE *)this + 180) = (16 * HIBYTE(parms[1].animStack)) & 0x10 | *((_BYTE *)this + 180) & 0xE7 | 8;
  return result;
}


// ========================================================================
// ?InternalShutdown@idAnimator_TrackerBase@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826ECA60
// RVA : 0x006ECA60
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::InternalShutdown(idAnimator_TrackerBase *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
  if ( this->leaf != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->leaf = nullptr;
  }
}


// ========================================================================
// ?SetPitchConstraints@idAnimator_TrackerBase@@QAAXV?$idTypesafeNumber@MW4DegreesUnique_t@@@@0@Z
// EA  : 0x826ECAC8
// RVA : 0x006ECAC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::SetPitchConstraints(
        idAnimator_TrackerBase *this,
        const idTypesafeNumber<float,enum DegreesUnique_t> *up,
        const idTypesafeNumber<float,enum DegreesUnique_t> *down)
{
  this->pitchUp.value = up->value;
  this->pitchDown.value = down->value;
}


// ========================================================================
// ?SetYawConstraints@idAnimator_TrackerBase@@QAAXV?$idTypesafeNumber@MW4DegreesUnique_t@@@@0@Z
// EA  : 0x826ECAE0
// RVA : 0x006ECAE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::SetYawConstraints(
        idAnimator_TrackerBase *this,
        const idTypesafeNumber<float,enum DegreesUnique_t> *right,
        const idTypesafeNumber<float,enum DegreesUnique_t> *left)
{
  this->yawRight.value = right->value;
  this->yawLeft.value = left->value;
}


// ========================================================================
// ?GetUnconstrainedAngleDeltas@idAnimator_TrackerBase@@MAAXPBV1@PAVidTreeAnimator@@AAVidAngles@@2AAVidVec3@@@Z
// EA  : 0x826ECAF8
// RVA : 0x006ECAF8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::GetUnconstrainedAngleDeltas(
        idAnimator_TrackerBase *this,
        const idAnimator_TrackerBase *parentTracker,
        idTreeAnimator *ta,
        idAngles *angleDeltas,
        idAngles *angles,
        idVec3 *cross)
{
  char *v6; // r10
  int v11; // ctr
  float *p_z; // r9
  idVec3 *p_wsFocusJointPos; // r28
  double v15; // fp31
  double v16; // fp30
  double v17; // fp28
  float x; // r10
  double y; // fp7
  double v20; // fp8
  double z; // fp6
  double v22; // fp0
  double v23; // fp1
  float v24; // r9
  double v25; // fp8
  double v26; // fp13
  idVec3 *p_msDirToFocus; // r31
  double v28; // fp11
  double v29; // fp12
  double v30; // fp4
  double v31; // fp10
  double v32; // fp9
  double v33; // fp0
  double v34; // fp12
  double v35; // fp10
  double v36; // fp11
  double v37; // fp9
  double v40; // fp2
  double v41; // fp0
  double v42; // fp11
  double v43; // fp4
  double v44; // fp2
  double v45; // fp1
  char v46; // r11
  double v47; // fp12
  double v48; // fp0
  double v49; // fp13
  double v50; // fp12
  double v51; // fp10
  double v56; // fp6
  double v57; // fp5
  double v58; // fp3
  double v59; // fp7
  double v60; // fp6
  double v61; // fp9
  double v62; // fp7
  double v63; // fp9
  double v64; // fp28
  double v65; // fp27
  double v66; // fp23
  double v67; // fp8
  double v68; // fp7
  double v69; // fp26
  double v70; // fp25
  double v71; // fp24
  long double v72; // fp2
  double v73; // fp22
  float v74; // r9
  float v75; // r8
  double v76; // fp22
  double v79; // fp4
  double v80; // fp8
  double v81; // fp4
  double v82; // fp3
  long double v83; // fp2
  double v84; // fp0
  int v85; // r3
  idRenderWorld *v86; // r3
  idVec3 v87; // [sp+50h] [-1B0h] BYREF
  idVec3 v88; // [sp+60h] [-1A0h] BYREF
  _DWORD v89[2]; // [sp+70h] [-190h] BYREF
  float v90; // [sp+78h] [-188h]
  idAngles v91; // [sp+80h] [-180h] BYREF
  idVec3 v92; // [sp+8Ch] [-174h] BYREF
  idVec3 v93; // [sp+98h] [-168h] BYREF
  idMat3 v94; // [sp+A8h] [-158h] BYREF
  char v95; // [sp+CCh] [-134h] BYREF
  float v96; // [sp+D0h] [-130h]
  float v97; // [sp+D4h] [-12Ch]
  float v98; // [sp+D8h] [-128h]
  float v99; // [sp+DCh] [-124h]
  float v100; // [sp+E0h] [-120h]
  float v101; // [sp+E4h] [-11Ch]
  float v102; // [sp+E8h] [-118h]
  float v103; // [sp+ECh] [-114h]
  float v104; // [sp+F0h] [-110h]
  idAngles v105[2]; // [sp+100h] [-100h] BYREF
  float v106; // [sp+118h] [-E8h]
  float v107; // [sp+11Ch] [-E4h]
  float v108; // [sp+120h] [-E0h]
  _BYTE v109[128]; // [sp+130h] [-D0h] BYREF

  v6 = &v95;
  v11 = 9;
  p_z = &ta->g.origin.z;
  do
  {
    ++p_z;
    v6 += 4;
    *(float *)v6 = *p_z;
    --v11;
  }
  while ( v11 != 0 );
  p_wsFocusJointPos = &this->wsFocusJointPos;
  v15 = v97;
  v16 = v98;
  v17 = v101;
  this->GetWorldSpaceFrameOfReference(this, a2: parentTracker, a3: ta, a4: &this->wsFocusJointPos, a5: (idMat3 *)v109);
  x = this->focusPoint.x;
  y = this->wsFocusJointPos.y;
  v20 = this->wsFocusJointPos.x;
  z = this->wsFocusJointPos.z;
  v22 = v103;
  v90 = this->focusPoint.z;
  *(float *)v89 = x;
  v23 = (float)(x - (float)v20);
  v24 = this->focusPoint.y;
  v25 = (float)(v90 - (float)z);
  v26 = v99;
  p_msDirToFocus = &this->msDirToFocus;
  v28 = v102;
  this->msDirToFocus.x = v23;
  v29 = v96;
  *(float *)&v89[1] = v24;
  this->msDirToFocus.y = v24 - (float)y;
  v30 = (float)((float)(v24 - (float)y) * (float)v22);
  v31 = v104;
  v32 = v100;
  this->msDirToFocus.z = v25;
  v33 = (float)((float)((float)v23 * (float)v29) + (float)((float)v25 * (float)v16));
  v34 = (float)((float)((float)v25 * (float)v31) + (float)((float)((float)v23 * (float)v28) + (float)v30));
  this->msDirToFocus.z = (float)((float)v25 * (float)v31) + (float)((float)((float)v23 * (float)v28) + (float)v30);
  v35 = (float)((float)((float)(v24 - (float)y) * (float)v32)
              + (float)((float)((float)v25 * (float)v17) + (float)((float)v23 * (float)v26)));
  this->msDirToFocus.y = (float)((float)(v24 - (float)y) * (float)v32)
                       + (float)((float)((float)v25 * (float)v17) + (float)((float)v23 * (float)v26));
  v36 = (float)((float)((float)(v24 - (float)y) * (float)v15) + (float)v33);
  this->msDirToFocus.x = (float)((float)(v24 - (float)y) * (float)v15) + (float)v33;
  v37 = v36;
  _FP3 = (float)((float)((float)((float)v34 * (float)v34)
                       + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f0 }
  v40 = (float)((float)((float)((float)v34 * (float)v34)
                      + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35)))
              * (float)0.5);
  v41 = __frsqrte(_FP1);
  v42 = (float)-(float)((float)((float)((float)v41
                                      * (float)((float)((float)((float)v34 * (float)v34)
                                                      + (float)((float)((float)v36 * (float)v36)
                                                              + (float)((float)v35 * (float)v35)))
                                              * (float)0.5))
                              * (float)v41)
                      - (float)1.5);
  v43 = (float)((float)-(float)((float)((float)((float)((float)v42 * (float)v41) * (float)v40)
                                      * (float)((float)v42 * (float)v41))
                              - (float)1.5)
              * (float)((float)v42 * (float)v41));
  v44 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v42 * (float)v41)
                                                                              * (float)v40)
                                                                      * (float)((float)v42 * (float)v41))
                                                              - (float)1.5)
                                              * (float)((float)v42 * (float)v41))
                                      * (float)v40)
                              * (float)((float)-(float)((float)((float)((float)((float)v42 * (float)v41) * (float)v40)
                                                              * (float)((float)v42 * (float)v41))
                                                      - (float)1.5)
                                      * (float)((float)v42 * (float)v41)))
                      - (float)1.5);
  this->msDirToFocus.x = (float)v37 * (float)((float)v44 * (float)v43);
  this->msDirToFocus.y = (float)v35 * (float)((float)v44 * (float)v43);
  this->msDirToFocus.z = (float)v34 * (float)((float)v44 * (float)v43);
  this->GetModelSpaceFrameOfReference(
    this,
    a2: parentTracker,
    a3: ta,
    a4: &this->msReferenceJointPos,
    a5: (idMat3 *)v105);
  v46 = *((_BYTE *)this + 180);
  if ( (v46 & 0x20) != 0 )
  {
    _FP4 = (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                         + (float)(this->msDirToFocus.y * this->msDirToFocus.y))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    _FP3 = (float)((float)((float)(v105[0].pitch * v105[0].pitch) + (float)(v105[0].yaw * v105[0].yaw))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm
    {
      fsel      f9, f4, f6, f0
      fsel      f7, f3, f5, f0
    }
    v56 = __frsqrte(_FP9);
    v57 = __frsqrte(_FP7);
    v58 = (float)v57;
    v59 = (float)-(float)((float)((float)((float)v56
                                        * (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                                                        + (float)(this->msDirToFocus.y * this->msDirToFocus.y))
                                                * (float)0.5))
                                * (float)v56)
                        - (float)1.5);
    v61 = (float)-(float)((float)((float)((float)((float)v59 * (float)v56)
                                        * (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                                                        + (float)(this->msDirToFocus.y * this->msDirToFocus.y))
                                                * (float)0.5))
                                * (float)((float)v59 * (float)v56))
                        - (float)1.5);
    v64 = (float)(this->msDirToFocus.y
                * (float)((float)-(float)((float)((float)((float)((float)v61 * (float)((float)v59 * (float)v56))
                                                        * (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                                                                        + (float)(this->msDirToFocus.y
                                                                                * this->msDirToFocus.y))
                                                                * (float)0.5))
                                                * (float)((float)v61 * (float)((float)v59 * (float)v56)))
                                        - (float)1.5)
                        * (float)((float)v61 * (float)((float)v59 * (float)v56))));
    v65 = (float)((float)((float)-(float)((float)((float)((float)((float)v61 * (float)((float)v59 * (float)v56))
                                                        * (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                                                                        + (float)(this->msDirToFocus.y
                                                                                * this->msDirToFocus.y))
                                                                * (float)0.5))
                                                * (float)((float)v61 * (float)((float)v59 * (float)v56)))
                                        - (float)1.5)
                        * (float)((float)v61 * (float)((float)v59 * (float)v56)))
                * p_msDirToFocus->x);
    v66 = (float)((float)((float)-(float)((float)((float)((float)((float)v61 * (float)((float)v59 * (float)v56))
                                                        * (float)((float)((float)(p_msDirToFocus->x * p_msDirToFocus->x)
                                                                        + (float)(this->msDirToFocus.y
                                                                                * this->msDirToFocus.y))
                                                                * (float)0.5))
                                                * (float)((float)v61 * (float)((float)v59 * (float)v56)))
                                        - (float)1.5)
                        * (float)((float)v61 * (float)((float)v59 * (float)v56)))
                * (float)0.0);
    v60 = (float)-(float)((float)((float)((float)v57
                                        * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                        + (float)(v105[0].yaw * v105[0].yaw))
                                                * (float)0.5))
                                * (float)v57)
                        - (float)1.5);
    v62 = (float)-(float)((float)((float)((float)((float)v60 * (float)v57)
                                        * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                        + (float)(v105[0].yaw * v105[0].yaw))
                                                * (float)0.5))
                                * (float)((float)v60 * (float)v57))
                        - (float)1.5);
    v63 = (float)((float)-(float)((float)((float)((float)((float)v62 * (float)((float)v60 * (float)v58))
                                                * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                + (float)(v105[0].yaw * v105[0].yaw))
                                                        * (float)0.5))
                                        * (float)((float)v62 * (float)((float)v60 * (float)v58)))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)((float)v60 * (float)v58)
                                                        * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                        + (float)(v105[0].yaw * v105[0].yaw))
                                                                * (float)0.5))
                                                * (float)((float)v60 * (float)v58))
                                        - (float)1.5)
                        * (float)((float)v60 * (float)v58)));
    v67 = (float)((float)((float)-(float)((float)((float)((float)((float)v62 * (float)((float)v60 * (float)v58))
                                                        * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                        + (float)(v105[0].yaw * v105[0].yaw))
                                                                * (float)0.5))
                                                * (float)((float)v62 * (float)((float)v60 * (float)v58)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)v60 * (float)v58)
                                                                * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                                + (float)(v105[0].yaw * v105[0].yaw))
                                                                        * (float)0.5))
                                                        * (float)((float)v60 * (float)v58))
                                                - (float)1.5)
                                * (float)((float)v60 * (float)v58)))
                * (float)0.0);
    v68 = (float)(v105[0].pitch
                * (float)((float)-(float)((float)((float)((float)((float)v62 * (float)((float)v60 * (float)v58))
                                                        * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                        + (float)(v105[0].yaw * v105[0].yaw))
                                                                * (float)0.5))
                                                * (float)((float)v62 * (float)((float)v60 * (float)v58)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)v60 * (float)v58)
                                                                * (float)((float)((float)(v105[0].pitch * v105[0].pitch)
                                                                                + (float)(v105[0].yaw * v105[0].yaw))
                                                                        * (float)0.5))
                                                        * (float)((float)v60 * (float)v58))
                                                - (float)1.5)
                                * (float)((float)v60 * (float)v58))));
    v88.z = (float)((float)v65 * (float)0.0) - (float)((float)v64 * (float)0.0);
    v88.x = (float)((float)v64 * (float)-1.0) - (float)((float)v66 * (float)0.0);
    *((double *)&v72 + 1) = (float)((float)((float)v65 * (float)v68) + (float)((float)v66 * (float)v67));
    v88.y = -(float)((float)((float)v65 * (float)-1.0) - (float)((float)v66 * (float)0.0));
    *(double *)&v72 = (float)((float)(v88.y * (float)(v105[0].yaw * (float)v63))
                            + (float)((float)(v88.x * (float)v68) + (float)(v88.z * (float)v67)));
    if ( (float)((float)((float)v64 * (float)(v105[0].yaw * (float)v63))
               + (float)((float)((float)v65 * (float)v68) + (float)((float)v66 * (float)v67))) >= 0.0 )
    {
      v73 = (float)-(float)((float)((float)3.1415927 * (float)0.5) - idMath::ACos(a: v72));
    }
    else if ( *(double *)&v72 <= 0.0 )
    {
      v73 = (float)((float)((float)3.1415927 * (float)1.5) - idMath::ACos(a: v72));
    }
    else
    {
      v73 = (float)((float)((float)3.1415927 * (float)-0.5) - idMath::ACos(a: v72));
    }
    v74 = this->msDirToFocus.y;
    v75 = this->msDirToFocus.z;
    v87.x = p_msDirToFocus->x;
    v87.y = v74;
    v87.z = v75;
    idVec3::ProjectOntoPlane(this: &v87, normal: &v88, overBounce: 1.0);
    v76 = (float)(idMath::M_RAD2DEG * (float)v73);
    _FP7 = (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f0 }
    v79 = __frsqrte(_FP5);
    v80 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79
                                                                                        * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z)))
                                                                                                * (float)0.5))
                                                                                * (float)v79)
                                                                        - (float)1.5)
                                                        * (float)v79)
                                                * (float)((float)((float)(v87.y * v87.y)
                                                                + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v79
                                                                                * (float)((float)((float)(v87.y * v87.y)
                                                                                                + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z)))
                                                                                        * (float)0.5))
                                                                        * (float)v79)
                                                                - (float)1.5)
                                                * (float)v79))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v79
                                                        * (float)((float)((float)(v87.y * v87.y)
                                                                        + (float)((float)(v87.x * v87.x)
                                                                                + (float)(v87.z * v87.z)))
                                                                * (float)0.5))
                                                * (float)v79)
                                        - (float)1.5)
                        * (float)v79));
    v82 = (float)(v87.y
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79)
                                                                                                * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5)
                                                                                                * (float)v79))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5))
                                                                                                * (float)v79)
                                                                                        - (float)1.5)
                                                                        * (float)v79))
                                                        * (float)((float)((float)(v87.y * v87.y)
                                                                        + (float)((float)(v87.x * v87.x)
                                                                                + (float)(v87.z * v87.z)))
                                                                * (float)0.5))
                                                * (float)v80)
                                        - (float)1.5)
                        * (float)v80));
    *((double *)&v83 + 1) = (float)(v87.z
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79) * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79))
                                                                                                  - (float)1.5)
                                                                                  * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5)
                                                                                          * (float)v79))
                                                                          * (float)((float)((float)(v87.y * v87.y)
                                                                                          + (float)((float)(v87.x * v87.x)
                                                                                                  + (float)(v87.z * v87.z)))
                                                                                  * (float)0.5))
                                                                  * (float)v80)
                                                          - (float)1.5)
                                          * (float)v80));
    v81 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5) * (float)v79)
                                                                                                * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5)) * (float)v79) - (float)1.5)
                                                                                                * (float)v79))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v79 * (float)((float)((float)(v87.y * v87.y) + (float)((float)(v87.x * v87.x) + (float)(v87.z * v87.z))) * (float)0.5))
                                                                                                * (float)v79)
                                                                                        - (float)1.5)
                                                                        * (float)v79))
                                                        * (float)((float)((float)(v87.y * v87.y)
                                                                        + (float)((float)(v87.x * v87.x)
                                                                                + (float)(v87.z * v87.z)))
                                                                * (float)0.5))
                                                * (float)v80)
                                        - (float)1.5)
                        * (float)v80)
                * v87.x);
    v69 = (float)((float)((float)v65 * (float)0.0) - (float)((float)v64 * (float)0.0));
    v70 = (float)((float)((float)v64 * (float)-1.0) - (float)((float)v66 * (float)0.0));
    v71 = (float)-(float)((float)((float)v65 * (float)-1.0) - (float)((float)v66 * (float)0.0));
    *(double *)&v83 = (float)((float)((float)((float)((float)v69 * (float)v81)
                                            - (float)((float)*((double *)&v83 + 1) * (float)v70))
                                    * (float)v64)
                            + (float)((float)((float)((float)((float)*((double *)&v83 + 1) * (float)v71)
                                                    - (float)((float)v82 * (float)v69))
                                            * (float)v65)
                                    + (float)((float)((float)((float)v82 * (float)v70) - (float)((float)v71 * (float)v81))
                                            * (float)v66)));
    v45 = idMath::ACos(a: v83);
    v84 = idMath::M_RAD2DEG;
    angleDeltas->yaw = v76;
    angleDeltas->roll = 0.0;
    angleDeltas->pitch = (float)-(float)((float)(3.1415927 * (float)0.5) - (float)v45) * (float)v84;
  }
  else
  {
    v87 = (idVec3)v105[0];
    if ( (v46 & 0x10) != 0 )
    {
      v88.z = 1.0;
      v88.x = 0.0;
      v88.y = 0.0;
      idVec3::ProjectOntoPlane(this: &v87, normal: &v88, overBounce: 1.0);
      v45 = idVec3::NormalizeFast(this: &v87);
    }
    v47 = this->msDirToFocus.z;
    v48 = p_msDirToFocus->x;
    v49 = this->msDirToFocus.y;
    if ( (float)((float)(this->msDirToFocus.y * v87.y)
               + (float)((float)(this->msDirToFocus.x * v87.x) + (float)(this->msDirToFocus.z * v87.z))) < 0.99998999 )
    {
      v91.pitch = p_msDirToFocus->x;
      v91.yaw = v49;
      v91.roll = v47;
      v92.z = (float)(v106 * (float)v49) - (float)(v107 * (float)v48);
      v92.x = (float)(v107 * (float)v47) - (float)(v108 * (float)v49);
      v92.y = (float)(v108 * (float)v48) - (float)(v106 * (float)v47);
      idVec3::NormalizeFast(this: &v92);
      v93.x = (float)(v92.z * v91.yaw) - (float)(v92.y * v91.roll);
      v93.y = (float)(v92.x * v91.roll) - (float)(v92.z * v91.pitch);
      v93.z = (float)(v92.y * v91.pitch) - (float)(v92.x * v91.yaw);
      idVec3::NormalizeFast(this: &v93);
      idMat3::ToAngles(this: (idMat3 *)&v94.mat[1].y, result: &v91);
      idMat3::ToAngles(this: &v94, result: v105);
      v45 = (float)(v94.mat[1].y - v94.mat[0].x);
      v50 = (float)(v94.mat[1].z - v94.mat[0].y);
      v51 = (float)(v94.mat[2].x - v94.mat[0].z);
      angles->pitch = v94.mat[1].y - v94.mat[0].x;
      angles->yaw = v50;
      angles->roll = v51;
    }
  }
  if ( anim_debugTorsoTracker.valueInteger == 1 )
  {
    v85 = ((int (__fastcall *)(idCommon *, double))common->RW)(a1: common, a2: v45);
    (*(void (__fastcall **)(int, idColor *, idVec3 *, _DWORD, int))(*(_DWORD *)v85 + 256))(
      a1: v85,
      a2: &idColor::colorCyan,
      a3: &this->focusPoint,
      a4: 0,
      a5: 1);
    v86 = common->RW(this: common);
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, _DWORD *, double))v86->DebugArrow)(
      a1: v86,
      a2: &idColor::colorYellow,
      a3: p_wsFocusJointPos,
      a4: v89,
      a5: 4.0);
  }
}


// ========================================================================
// ??0idAnimatorParms_TrackerBase@@QAA@PAVidAnimStack@@PBDW4originBlend_t@idMD6Blend@@W4md6WeightGroup_t@@3M_N@Z
// EA  : 0x826ED0F0
// RVA : 0x006ED0F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

idAnimatorParms_TrackerBase *__fastcall idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
        idAnimatorParms_TrackerBase *this,
        idAnimStack *animStack_,
        const char *name_,
        idMD6Blend::originBlend_t originBlend_,
        md6WeightGroup_t weightGroup_,
        md6WeightGroup_t filterGroup_,
        double alpha_,
        const bool projectReferenceOrientation_,
        bool a9)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->originBlend = originBlend_;
  this->blendOp = BOP_REF_LERP;
  this->weightGroup = weightGroup_;
  this->filterGroup = filterGroup_;
  this->projectReferenceOrientation = a9;
  return this;
}


// ========================================================================
// ?InternalIsContributing@idAnimator_TrackerBase@@MBA_NXZ
// EA  : 0x826ED158
// RVA : 0x006ED158
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

unsigned int __fastcall idAnimator_TrackerBase::InternalIsContributing(idAnimator_TrackerBase *this)
{
  idMD6LeafPause *leaf; // r11

  leaf = this->leaf;
  if ( leaf != nullptr )
    return (-leaf->animMods[0].num & (unsigned int)~leaf->animMods[0].num) >> 31;
  else
    return 0;
}


// ========================================================================
// ?Update@idAnimator_TrackerBase@@QAAXPBV1@ABVidVec3@@ABVidAngles@@V?$idTypesafeNumber@MW4DegreesUnique_t@@@@333@Z
// EA  : 0x826ED180
// RVA : 0x006ED180
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::Update(
        idAnimator_TrackerBase *this,
        const idAnimator_TrackerBase *parentTracker_,
        const idVec3 *focusPoint_,
        const idAngles *offsetAngles_,
        const idTypesafeNumber<float,enum DegreesUnique_t> *pitchUp,
        const idTypesafeNumber<float,enum DegreesUnique_t> *pitchDown,
        const idTypesafeNumber<float,enum DegreesUnique_t> *yawRight,
        const idTypesafeNumber<float,enum DegreesUnique_t> *yawLeft)
{
  idAnimator_TrackerBase_vtbl *v8; // r11
  double value; // fp7
  void (*InternalUpdate)(void); // r8
  double v11; // fp5

  this->focusPoint = *focusPoint_;
  this->idealOffsetAngles = *offsetAngles_;
  this->parentTracker = parentTracker_;
  v8 = this->__vftable;
  value = pitchUp->value;
  this->pitchDown.value = pitchDown->value;
  InternalUpdate = (void (*)(void))v8->InternalUpdate;
  this->pitchUp.value = value;
  v11 = yawRight->value;
  this->yawLeft.value = yawLeft->value;
  this->yawRight.value = v11;
  InternalUpdate();
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_TrackerBase@@UAAXAAVidSerializer@@@Z
// EA  : 0x826ED1F0
// RVA : 0x006ED1F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::SerializeSnapshot(idAnimator_TrackerBase *this, idSerializer *ser)
{
  char v2; // r10
  idBitMsg *msg; // r3
  bool v6; // r28
  char v7; // r9
  bool v8; // r28
  idBitMsg *v9; // r3
  idVec3 *v10; // r28
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  double value; // fp31
  idBitMsg *v16; // r3
  double v17; // fp31
  idBitMsg *v18; // r3
  double v19; // fp31
  idBitMsg *v20; // r3
  double v21; // fp31
  idBitMsg *v22; // r3
  idAnimatorParms_Base v23; // [sp+60h] [-80h] BYREF

  v2 = *((_BYTE *)this + 180);
  msg = ser->msg;
  v6 = (v2 & 0x10) != 0;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: (v2 & 0x10) != 0, numBits: 1);
  else
    v6 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  v7 = (16 * v6) & 0x10 | *((_BYTE *)this + 180) & 0xEF;
  *((_BYTE *)this + 180) = v7;
  v8 = (v7 & 0x20) != 0;
  v9 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v9, value: (v7 & 0x20) != 0, numBits: 1);
  else
    v8 = (_cntlzw(idBitMsg::ReadBits(this: v9, numBits: 1) - 1) & 0x20) != 0;
  *((_BYTE *)this + 180) = (32 * v8) & 0x20 | *((_BYTE *)this + 180) & 0xDF;
  v10 = &this->focusPoints[1];
  this->focusPoints[0].x = this->focusPoints[1].x;
  this->focusPoints[0].y = this->focusPoints[1].y;
  this->focusPoints[0].z = this->focusPoints[1].z;
  this->focusPoints[1].x = this->focusPoint.x;
  this->focusPoints[1].y = this->focusPoint.y;
  this->focusPoints[1].z = this->focusPoint.z;
  idSerializer::Serialize(this: ser, value: &this->focusPoints[1]);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: this->trackGroupIndex, numBits: 32);
  else
    this->trackGroupIndex = idBitMsg::ReadBits(this: v11, numBits: 32);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: COERCE_INT(this->idealOffsetAngles.pitch), numBits: 32);
  else
    LODWORD(this->idealOffsetAngles.pitch) = idBitMsg::ReadBits(this: v12, numBits: 32);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: COERCE_INT(this->idealOffsetAngles.yaw), numBits: 32);
  else
    LODWORD(this->idealOffsetAngles.yaw) = idBitMsg::ReadBits(this: v13, numBits: 32);
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: COERCE_INT(this->idealOffsetAngles.roll), numBits: 32);
  else
    LODWORD(this->idealOffsetAngles.roll) = idBitMsg::ReadBits(this: v14, numBits: 32);
  value = this->pitchUp.value;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: COERCE_INT(this->pitchUp.value), numBits: 32);
  else
    value = COERCE_FLOAT(idBitMsg::ReadBits(this: v16, numBits: 32));
  this->pitchUp.value = value;
  v17 = this->pitchDown.value;
  v18 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v18, value: COERCE_INT(this->pitchDown.value), numBits: 32);
  else
    v17 = COERCE_FLOAT(idBitMsg::ReadBits(this: v18, numBits: 32));
  this->pitchDown.value = v17;
  v19 = this->yawLeft.value;
  v20 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v20, value: COERCE_INT(this->yawLeft.value), numBits: 32);
  else
    v19 = COERCE_FLOAT(idBitMsg::ReadBits(this: v20, numBits: 32));
  this->yawLeft.value = v19;
  v21 = this->yawRight.value;
  v22 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v22, value: COERCE_INT(this->yawRight.value), numBits: 32);
  else
    v21 = COERCE_FLOAT(idBitMsg::ReadBits(this: v22, numBits: 32));
  this->yawRight.value = v21;
  if ( this->mergeBranch == nullptr )
  {
    v23.animStack = this->serializeProps.animStack;
    idStr::idStr(this: &v23.name, text: "tracker");
    v23.blendOp = BOP_REF_LERP;
    v23.originBlend = ORIGINBLEND_BRANCH;
    v23.weightGroup = MD6_WEIGHTGROUP_TORSO;
    v23.alpha = 1.0;
    v23.filterGroup = MD6_WEIGHTGROUP_TORSO;
    if ( (unsigned __int8)idAnimator_Base::Init(
                            this,
                            gametimeManager: this->gametimeManager.gameTimeManager,
                            parms: &v23) == 0 )
      idLib::Warning(fmt: "Failed to initialize idAnimator_TrackerBase.");
    this->focusPoints[0].x = v10->x;
    this->focusPoints[0].y = this->focusPoints[1].y;
    this->focusPoints[0].z = this->focusPoints[1].z;
    this->focusPoint.x = v10->x;
    this->focusPoint.y = this->focusPoints[1].y;
    this->focusPoint.z = this->focusPoints[1].z;
    idStr::FreeData(this: &v23.name);
  }
}


// ========================================================================
// __unwind$248271
// EA  : 0x826ED558
// RVA : 0x006ED558
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void _unwind_248271()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 224 + 96));
}


// ========================================================================
// ?InternalDoTracking@idAnimator_TrackerBase@@AAAXPBVidAnimStack@@M@Z
// EA  : 0x826ED580
// RVA : 0x006ED580
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::InternalDoTracking(
        idAnimator_TrackerBase *this,
        const idAnimStack *stack,
        double deltaLerpScale)
{
  idMD6Branch *mergeBranch; // r9
  idTreeAnimator *treeAnimator; // r31
  int trackGroupIndex; // r11
  const idDeclMD6 *decl; // r10
  int v9; // r25
  int v10; // r8
  double yaw; // fp13
  double roll; // fp12
  float v13; // r9
  double pitch; // fp1
  float v15; // r8
  idAnimator_TrackerBase_vtbl *v16; // r11
  const idAnimator_TrackerBase *parentTracker; // r4
  char v18; // r11
  double v19; // fp1
  double v20; // fp13
  double value; // fp0
  double v22; // fp12
  double v23; // fp0
  double v24; // fp13
  double v25; // fp0
  char v26; // r11
  char v27; // r10
  double v28; // fp13
  char v29; // r11
  int v30; // r26
  char *v31; // r31
  int v32; // r27
  float *v33; // r29
  double v34; // fp9
  double v35; // fp8
  float *v36; // r3
  double v37; // fp6
  double v38; // fp5
  double v39; // fp4
  double v40; // fp3
  double v41; // fp2
  double v42; // fp1
  double v43; // fp0
  double v44; // fp13
  float *v45; // r3
  double v46; // fp7
  double v47; // fp6
  double v48; // fp5
  double v49; // fp4
  double v50; // fp3
  double v51; // fp2
  double v52; // fp1
  double v53; // fp0
  char v54; // r11
  double v55; // fp10
  double v56; // fp8
  const idMat3 *v57; // r3
  __int16 v58; // r11
  double x; // fp0
  double v60; // fp13
  double v61; // fp12
  double y; // fp10
  double v63; // fp9
  double z; // fp7
  double v65; // fp6
  idAngles v66; // [sp+50h] [-140h] BYREF
  idAngles v67; // [sp+60h] [-130h] BYREF
  idMat3 v68; // [sp+70h] [-120h] BYREF
  float v69; // [sp+98h] [-F8h]
  float v70; // [sp+9Ch] [-F4h]
  float v71; // [sp+A0h] [-F0h]
  float v72[4]; // [sp+A8h] [-E8h] BYREF
  idMat3 v73; // [sp+B8h] [-D8h] BYREF
  float v74; // [sp+DCh] [-B4h]
  float v75; // [sp+E0h] [-B0h]
  idAngles v76[3]; // [sp+F0h] [-A0h] BYREF

  if ( this->leaf == nullptr )
  {
    idLib::Warning(fmt: "idAnimator_TrackerBase::InternalDoTracking called while leaf = NULL");
    return;
  }
  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    if ( anim_tracker_disable.valueInteger != 0 )
    {
      mergeBranch->right = nullptr;
LABEL_48:
      idMD6LeafPause::SetNumAnimMods(this: this->leaf, n: 0);
      return;
    }
    treeAnimator = stack->treeAnimator;
    trackGroupIndex = this->trackGroupIndex;
    decl = treeAnimator->decl;
    if ( trackGroupIndex < 0 || trackGroupIndex >= decl->headTrackGroups.num )
      v9 = 0;
    else
      v9 = (int)&decl->headTrackGroups.list[trackGroupIndex];
    if ( v9 == 0 || *(unsigned __int16 *)(v9 + 20) >= 0x8000u )
    {
      mergeBranch->right = nullptr;
      goto LABEL_48;
    }
    v10 = *((_BYTE *)this + 180) & 4;
    v66 = ang_zero;
    v67 = ang_zero;
    if ( v10 != 0 )
    {
      yaw = this->lastAngles.yaw;
      roll = this->lastAngles.roll;
      v66.pitch = this->lastAngles.pitch;
      v66.yaw = yaw;
      v66.roll = roll;
    }
    else
    {
      v13 = this->idealOffsetAngles.yaw;
      pitch = this->curOffsetAngles.pitch;
      v15 = this->idealOffsetAngles.roll;
      v69 = this->idealOffsetAngles.pitch;
      v70 = v13;
      v71 = v15;
      this->curOffsetAngles.pitch = LerpToWithScale(cur: pitch, dest: v69, scale: 0.1);
      this->curOffsetAngles.yaw = LerpToWithScale(cur: this->curOffsetAngles.yaw, dest: v70, scale: 0.1);
      this->curOffsetAngles.roll = LerpToWithScale(cur: this->curOffsetAngles.roll, dest: v71, scale: 0.1);
      v16 = this->__vftable;
      parentTracker = this->parentTracker;
      *(idVec3 *)&v73.mat[1].y = vec3_up;
      v16->GetUnconstrainedAngleDeltas(
        this,
        a2: parentTracker,
        a3: treeAnimator,
        a4: &v67,
        a5: &v66,
        a6: (idVec3 *)&v73.mat[1].y);
      v18 = *((_BYTE *)this + 180);
      if ( (v18 & 0x20) != 0 )
      {
        value = this->pitchUp.value;
        v22 = v67.pitch;
        if ( v67.pitch >= value )
        {
          v23 = this->pitchDown.value;
          if ( v22 <= v23 )
          {
            *((_BYTE *)this + 180) = v18 & 0xBF;
          }
          else
          {
            v67.pitch = this->pitchDown.value;
            v22 = v23;
            *((_BYTE *)this + 180) = v18 | 0x40;
          }
        }
        else
        {
          v67.pitch = this->pitchUp.value;
          v22 = value;
          *((_BYTE *)this + 180) = v18 | 0x40;
        }
        v24 = this->yawRight.value;
        v25 = v67.yaw;
        if ( v67.yaw >= v24 )
        {
          v28 = this->yawLeft.value;
          if ( v25 <= v28 )
          {
            v27 = *((_BYTE *)this + 180) & 0x7F;
          }
          else
          {
            v29 = *((_BYTE *)this + 180);
            v67.yaw = this->yawLeft.value;
            v25 = v28;
            v27 = v29 | 0x80;
          }
        }
        else
        {
          v26 = *((_BYTE *)this + 180);
          v67.yaw = this->yawRight.value;
          v25 = v24;
          v27 = v26 | 0x80;
        }
        *((_BYTE *)this + 180) = v27;
        if ( anim_torsoTrackerZeroPitch.valueInteger != 0 )
        {
          v67.pitch = 0.0;
          v22 = 0.0;
        }
        if ( anim_torsoTrackerZeroYaw.valueInteger != 0 )
        {
          v67.yaw = 0.0;
          v25 = 0.0;
        }
        v20 = v67.roll;
        this->lastAngles.pitch = v22;
        this->lastAngles.yaw = v25;
      }
      else
      {
        v66.pitch = LerpToWithScale(cur: this->lastAngles.pitch, dest: v66.pitch, scale: deltaLerpScale);
        v19 = LerpToWithScale(cur: this->lastAngles.yaw, dest: v66.yaw, scale: deltaLerpScale);
        v20 = v66.roll;
        v66.yaw = v19;
        this->lastAngles.pitch = v66.pitch;
        this->lastAngles.yaw = v19;
      }
      this->lastAngles.roll = v20;
    }
    idMD6LeafPause::SetNumAnimMods(this: this->leaf, n: *(_DWORD *)(v9 + 8));
    ++this->leaf->currentDeferred;
    idMD6LeafPause::SetUseStackTop(this: this->leaf, set: true);
    idMD6LeafPause::SetClearNonModWeights(this: this->leaf, set: true);
    v30 = 0;
    if ( *(int *)(v9 + 8) > 0 )
    {
      v31 = (char *)&this->leaf->animMods[this->leaf->currentDeferred & 1].list[-1].s[2];
      v32 = 0;
      do
      {
        v33 = (float *)(v32 + *(_DWORD *)(v9 + 4));
        if ( (*((_BYTE *)this + 180) & 0x20) != 0 )
        {
          v73.mat[2].z = v33[1] * v67.pitch;
          v74 = v33[2] * v67.yaw;
          v75 = 0.0;
          v45 = (float *)idAngles::ToMat3(this: v76, result: (idMat3 *)&v73.mat[2].z);
          v46 = v45[1];
          v47 = v45[2];
          v48 = v45[3];
          v49 = v45[4];
          v50 = v45[5];
          v51 = v45[6];
          v52 = v45[7];
          v53 = v45[8];
          v68.mat[0].x = *v45;
          v68.mat[0].y = v46;
          v68.mat[0].z = v47;
          v68.mat[1].x = v48;
          v68.mat[1].y = v49;
          v68.mat[1].z = v50;
          v68.mat[2].x = v51;
          v68.mat[2].y = v52;
          v68.mat[2].z = v53;
        }
        else
        {
          v34 = (float)(v33[2] * v66.yaw);
          v35 = (float)(v66.roll * v33[2]);
          v72[0] = v33[2] * v66.pitch;
          v72[1] = v34;
          v72[2] = v35;
          v36 = (float *)idAngles::ToMat3(this: v76, result: (idMat3 *)v72);
          v37 = v36[1];
          v38 = v36[2];
          v39 = v36[3];
          v40 = v36[4];
          v41 = v36[5];
          v42 = v36[6];
          v43 = v36[7];
          v44 = v36[8];
          v68.mat[0].x = *v36;
          v68.mat[0].y = v37;
          v68.mat[0].z = v38;
          v68.mat[1].x = v39;
          v68.mat[1].y = v40;
          v68.mat[1].z = v41;
          v68.mat[2].x = v42;
          v68.mat[2].y = v43;
          v68.mat[2].z = v44;
        }
        if ( ang_zero.pitch != this->curOffsetAngles.pitch
          || ang_zero.yaw != this->curOffsetAngles.yaw
          || (v54 = 1, ang_zero.roll != this->curOffsetAngles.roll) )
        {
          v54 = 0;
        }
        if ( v54 == 0
          && (anim_torsoApplyOffsetToEndJointOnly.valueInteger == 0
           || *(unsigned __int16 *)v33 == *(unsigned __int16 *)(v9 + 20)) )
        {
          v55 = (float)(this->curOffsetAngles.roll * v33[2]);
          v56 = (float)(this->curOffsetAngles.yaw * v33[2]);
          v73.mat[0].x = v33[1] * this->curOffsetAngles.pitch;
          v73.mat[0].z = v55;
          v73.mat[0].y = v56;
          v57 = idAngles::ToMat3(this: v76, result: &v73);
          idMat3::operator*=(this: &v68, a: v57);
        }
        v58 = *(_WORD *)v33;
        x = v68.mat[1].x;
        v60 = v68.mat[2].x;
        *((_WORD *)v31 + 35) = 131;
        v61 = v68.mat[0].x;
        ++v30;
        *((float *)v31 + 3) = x;
        v32 += 12;
        *((float *)v31 + 4) = v60;
        *((float *)v31 + 2) = v61;
        *((_WORD *)v31 + 34) = v58;
        *((float *)v31 + 5) = vec3_origin.x;
        y = v68.mat[1].y;
        v63 = v68.mat[2].y;
        *((float *)v31 + 6) = v68.mat[0].y;
        *((float *)v31 + 7) = y;
        *((float *)v31 + 8) = v63;
        z = v68.mat[1].z;
        *((float *)v31 + 9) = vec3_origin.y;
        *((float *)v31 + 11) = z;
        v65 = v68.mat[2].z;
        *((float *)v31 + 10) = v68.mat[0].z;
        *((float *)v31 + 12) = v65;
        *((float *)v31 + 13) = vec3_origin.z;
        *((float *)v31 + 14) = 0.0;
        *((float *)v31 + 15) = 0.0;
        v31 += 64;
        *(float *)v31 = 0.0;
      }
      while ( v30 < *(_DWORD *)(v9 + 8) );
    }
    this->mergeBranch->left = nullptr;
    this->mergeBranch->right = this->leaf;
    this->mergeBranch->filterGroup = 2;
    this->parentTracker = nullptr;
  }
}


// ========================================================================
// ?PreBlendSnapshot@idAnimator_TrackerBase@@UAAXPAVidAnimStack@@HHM@Z
// EA  : 0x826EDBA8
// RVA : 0x006EDBA8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::PreBlendSnapshot(
        idAnimator_TrackerBase *this,
        idAnimStack *stack,
        int curTime,
        const int ticksPerSec,
        double fraction)
{
  bool IsAnimatorFlagSet; // r3
  char v9; // r11
  float y; // [sp+54h] [-3Ch]
  float z; // [sp+58h] [-38h]
  float v12; // [sp+64h] [-2Ch]
  float v13; // [sp+68h] [-28h]

  if ( !idAnimator_Base::IsContributing(this)
    || (IsAnimatorFlagSet = idAnimStack::IsAnimatorFlagSet(
                              this: stack,
                              animator: this,
                              flag: ANIMATORFLAG_CONTRIBUTED_LAST_SERIALIZE),
        v9 = 0,
        !IsAnimatorFlagSet) )
  {
    v9 = 1;
  }
  if ( v9 != 0 || (*((_BYTE *)this + 180) & 8) != 0 )
  {
    this->focusPoints[0].x = this->focusPoints[1].x;
    this->focusPoints[0].y = this->focusPoints[1].y;
    this->focusPoints[0].z = this->focusPoints[1].z;
    this->focusPoint.x = this->focusPoints[1].x;
    this->focusPoint.y = this->focusPoints[1].y;
    this->focusPoint.z = this->focusPoints[1].z;
    *((_BYTE *)this + 180) = (8 * v9) & 8 | *((_BYTE *)this + 180) & 0xF7;
  }
  else
  {
    z = this->focusPoints[1].z;
    v13 = this->focusPoints[0].z;
    y = this->focusPoints[1].y;
    v12 = this->focusPoints[0].y;
    this->focusPoint.x = (float)((float)(this->focusPoints[1].x - this->focusPoints[0].x) * (float)fraction)
                       + this->focusPoints[0].x;
    this->focusPoint.y = (float)((float)(y - v12) * (float)fraction) + v12;
    this->focusPoint.z = (float)((float)(z - v13) * (float)fraction) + v13;
  }
  idAnimator_TrackerBase::InternalDoTracking(this, stack: this->serializeProps.animStack, deltaLerpScale: 1.0);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_TrackerBase@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826EDD18
// RVA : 0x006EDD18
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __fastcall idAnimator_TrackerBase::InternalPreBlendTree(
        idAnimator_TrackerBase *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPLogScope v8[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idAnimator_TrackerBase::InternalPreBlendTree");
  LODWORD(v6) = "idAnimator_TrackerBase::InternalPreBlendTree";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v6, label: v7);
  idAnimator_TrackerBase::InternalDoTracking(this, stack, deltaLerpScale: 1.0);
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
}


// ========================================================================
// __unwind$249338
// EA  : 0x826EDD80
// RVA : 0x006EDD80
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void _unwind_249338()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$249339
// EA  : 0x826EDDA8
// RVA : 0x006EDDA8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void _unwind_249339()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// `dynamic initializer for 'anim_tracker_disable''
// EA  : 0x8333F1E8
// RVA : 0x0133F1E8
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_tracker_disable__()
{
  idCVar::idCVar(
    this: &anim_tracker_disable,
    name: "anim_tracker_disable",
    value: "0",
    flags: 1,
    description: "1 = show 3D debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_tracker_disable__);
}


// ========================================================================
// `dynamic initializer for 'anim_debugTorsoTracker''
// EA  : 0x8333F240
// RVA : 0x0133F240
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugTorsoTracker__()
{
  idCVar::idCVar(
    this: &anim_debugTorsoTracker,
    name: "anim_debugTorsoTracker",
    value: "0",
    flags: 2,
    description: "1 = show 3D debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugTorsoTracker__);
}


// ========================================================================
// `dynamic initializer for 'anim_torsoTrackerZeroPitch''
// EA  : 0x8333F298
// RVA : 0x0133F298
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_torsoTrackerZeroPitch__()
{
  idCVar::idCVar(
    this: &anim_torsoTrackerZeroPitch,
    name: "anim_torsoTrackerZeroPitch",
    value: "0",
    flags: 1,
    description: "1 = clear torso tracker pitch each frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_torsoTrackerZeroPitch__);
}


// ========================================================================
// `dynamic initializer for 'anim_torsoTrackerZeroYaw''
// EA  : 0x8333F2F0
// RVA : 0x0133F2F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_torsoTrackerZeroYaw__()
{
  idCVar::idCVar(
    this: &anim_torsoTrackerZeroYaw,
    name: "anim_torsoTrackerZeroYaw",
    value: "0",
    flags: 1,
    description: "1 = clear torso tracker yaw each frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_torsoTrackerZeroYaw__);
}


// ========================================================================
// `dynamic initializer for 'anim_torsoApplyOffsetToEndJointOnly''
// EA  : 0x8333F348
// RVA : 0x0133F348
// PDB : w:\tech5\engine\gamelib\animstack\animator_trackerbase.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_torsoApplyOffsetToEndJointOnly__()
{
  idCVar::idCVar(
    this: &anim_torsoApplyOffsetToEndJointOnly,
    name: "anim_torsoApplyOffsetToEndJointOnly",
    value: "0",
    flags: 1,
    description: "1 = apply extra offset in torso trackers only to the end joint in the head tracking group",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_torsoApplyOffsetToEndJointOnly__);
}

