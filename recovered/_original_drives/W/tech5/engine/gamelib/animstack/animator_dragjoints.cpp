
// ========================================================================
// ?SetOrder@?$idCurve_BSpline@VidAngles@@@@UAAXH@Z
// EA  : 0x826E05D0
// RVA : 0x006E05D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __fastcall idCurve_BSpline<idAngles>::SetOrder(idAnimator_DragJoints *this, idAnimator_AnimWeb *web)
{
  this->animweb = web;
}


// ========================================================================
// ?InternalIsContributing@idAnimator_RollBones@@MBA_NXZ
// EA  : 0x826E05D8
// RVA : 0x006E05D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

BOOL __fastcall idAnimator_RollBones::InternalIsContributing(idAAS2Local *this)
{
  return this->defaulted;
}


// ========================================================================
// ?GetClipModel@idPhysics_Robot@@UBAPAVidClipModel@@H@Z
// EA  : 0x826E05E0
// RVA : 0x006E05E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

const idMD6Branch *__fastcall idPhysics_Robot::GetClipModel(idAnimator_DragJoints *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?ReinitJoints@idAnimator_DragJoints@@AAAXXZ
// EA  : 0x826E05E8
// RVA : 0x006E05E8
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __fastcall idAnimator_DragJoints::ReinitJoints(idAnimator_DragJoints *this)
{
  int v2; // r10
  int v3; // r9
  idAnimator_DragJoints::idJoint *v4; // r11
  double v5; // fp8
  double y; // fp7
  double v7; // fp6
  double z; // fp5
  idMat3 v9; // [sp+50h] [-40h] BYREF

  idTreeAnimator::GetWorldSpaceJointTransform(
    this: this->animator,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->baseJoint.value,
    origin: &this->joints.list->position,
    axis: &v9);
  v2 = 1;
  if ( this->joints.num > 1 )
  {
    v3 = 1;
    do
    {
      ++v2;
      v4 = &this->joints.list[v3++];
      v5 = (float)(v9.mat[0].y * v4[-1].length);
      y = v4[-1].position.y;
      v7 = (float)(v9.mat[0].z * v4[-1].length);
      z = v4[-1].position.z;
      v4->position.x = v4[-1].position.x - (float)(v9.mat[0].x * v4[-1].length);
      v4->position.y = (float)y - (float)v5;
      v4->position.z = (float)z - (float)v7;
    }
    while ( v2 < this->joints.num );
  }
}


// ========================================================================
// ?InternalShutdown@idAnimator_DragJoints@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826E06A0
// RVA : 0x006E06A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __fastcall idAnimator_DragJoints::InternalShutdown(idAnimator_DragJoints *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_DragJoints@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E06F8
// RVA : 0x006E06F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __fastcall idAnimator_DragJoints::InternalPreBlendTree(
        idAnimator_DragJoints *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  int v5; // r29
  int v6; // r30
  idRenderWorld *v7; // r3
  idAnimator_AnimWeb *animweb; // r4
  char v9; // r30
  int v10; // r10
  int v11; // r11
  int blendFrame; // r11
  int numBlendFrames; // r11
  int v14; // r10
  bool v15; // zf
  __int64 v16; // r7
  int v17; // r10
  int v18; // r9
  idAnimator_DragJoints::idJoint *v19; // r11
  double z; // fp1
  double v21; // fp11
  double y; // fp2
  double v23; // fp8
  double v24; // fp5
  double v27; // fp0
  double v28; // fp13
  double v29; // fp7
  double v30; // fp12
  double v31; // fp13
  int v32; // r30
  __int64 v33; // r9
  int v34; // r4
  bool v35; // r11
  double v36; // fp29
  BOOL v37; // r26
  idAnimator_DragJoints::idJoint *v38; // r11
  double v39; // fp11
  double v40; // fp8
  double v41; // fp5
  double v44; // fp10
  double v45; // fp1
  double v46; // fp10
  double v47; // fp8
  idTreeAnimator *animator; // r11
  double v49; // fp10
  double v50; // fp9
  double v51; // fp11
  double v52; // fp8
  double v53; // fp5
  double v56; // fp10
  double v57; // fp1
  const idQuat *v58; // r3
  float *v59; // r3
  int v60; // r29
  int v61; // r30
  int v62; // r3
  __int16 v63; // [sp+50h] [-150h] BYREF
  idVec3 v64; // [sp+58h] [-148h] BYREF
  idVec3 v65; // [sp+68h] [-138h] BYREF
  idMat3 v66; // [sp+80h] [-120h] BYREF
  idMat3 v67; // [sp+B0h] [-F0h] BYREF
  idMat3 v68; // [sp+E0h] [-C0h] BYREF
  idMat3 v69; // [sp+110h] [-90h] BYREF

  if ( anim_debugDragJoints.valueInteger != 0 )
  {
    v5 = 0;
    if ( this->joints.num > 0 )
    {
      v6 = 0;
      do
      {
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: this->animator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->joints.list[v6].index.value,
          origin: (idVec3 *)&v67.mat[1].y,
          axis: &v68);
        v7 = common->RW(this: common);
        v7->DebugPoint(
          this: v7,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: (const idVec3 *)&v67.mat[1].y,
          a4: 0,
          a5: false);
        ++v5;
        ++v6;
      }
      while ( v5 < this->joints.num );
    }
  }
  animweb = this->animweb;
  if ( animweb != nullptr )
  {
    v9 = 0;
    idAnimator_AnimWeb::GetCurSubWebIndex(
      this: (idAnimator_AnimWeb *)&v63,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)animweb);
    v10 = 0;
    if ( this->subwebs.num > 0 )
    {
      v11 = 0;
      do
      {
        if ( this->subwebs.list[v11].value == v63 )
          v9 = 1;
        ++v10;
        ++v11;
      }
      while ( v10 < this->subwebs.num );
    }
    blendFrame = this->blendFrame;
    if ( v9 != 0 )
    {
      if ( blendFrame == 0 )
        idAnimator_DragJoints::ReinitJoints(this);
      numBlendFrames = this->numBlendFrames;
      v14 = this->blendFrame;
      if ( v14 < numBlendFrames )
        numBlendFrames = v14 + 1;
    }
    else
    {
      v15 = blendFrame > 0;
      numBlendFrames = blendFrame - 1;
      if ( !v15 )
        numBlendFrames = 0;
    }
    this->blendFrame = numBlendFrames;
  }
  if ( this->blendFrame != 0 )
  {
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: this->animator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->baseJoint.value,
      origin: &this->joints.list->position,
      axis: &v69);
    v17 = 1;
    if ( this->joints.num > 1 )
    {
      v18 = 1;
      do
      {
        ++v17;
        v19 = &this->joints.list[v18++];
        z = v19[-1].position.z;
        v21 = (float)(v19->position.z - v19[-1].position.z);
        y = v19[-1].position.y;
        v23 = (float)(v19->position.y - v19[-1].position.y);
        v24 = (float)(v19->position.x - v19[-1].position.x);
        _FP9 = (float)((float)((float)((float)v24 * (float)v24)
                             + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f6, f9, f10, f0 }
        v27 = __frsqrte(_FP6);
        v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                            * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                    * (float)v27)
                                                                            - (float)1.5)
                                                            * (float)v27)
                                                    * (float)((float)((float)((float)v24 * (float)v24)
                                                                    + (float)((float)((float)v23 * (float)v23)
                                                                            + (float)((float)v21 * (float)v21)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v27
                                                                                    * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))
                                                                                            * (float)0.5))
                                                                            * (float)v27)
                                                                    - (float)1.5)
                                                    * (float)v27))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v27
                                                            * (float)((float)((float)((float)v24 * (float)v24)
                                                                            + (float)((float)((float)v23 * (float)v23)
                                                                                    + (float)((float)v21 * (float)v21)))
                                                                    * (float)0.5))
                                                    * (float)v27)
                                            - (float)1.5)
                            * (float)v27));
        v29 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27) * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27)
                                                                                            - (float)1.5)
                                                                            * (float)v27))
                                                            * (float)((float)((float)((float)v24 * (float)v24)
                                                                            + (float)((float)((float)v23 * (float)v23)
                                                                                    + (float)((float)v21 * (float)v21)))
                                                                    * (float)0.5))
                                                    * (float)v28)
                                            - (float)1.5)
                            * (float)v28)
                    * (float)v24);
        v30 = (float)((float)((float)v21
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27) * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                    * (float)v27))
                                                                    * (float)((float)((float)((float)v24 * (float)v24)
                                                                                    + (float)((float)((float)v23 * (float)v23)
                                                                                            + (float)((float)v21 * (float)v21)))
                                                                            * (float)0.5))
                                                            * (float)v28)
                                                    - (float)1.5)
                                    * (float)v28))
                    * v19[-1].length);
        v31 = (float)((float)((float)v23
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27) * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v24 * (float)v24) + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21))) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                    * (float)v27))
                                                                    * (float)((float)((float)((float)v24 * (float)v24)
                                                                                    + (float)((float)((float)v23 * (float)v23)
                                                                                            + (float)((float)v21 * (float)v21)))
                                                                            * (float)0.5))
                                                            * (float)v28)
                                                    - (float)1.5)
                                    * (float)v28))
                    * v19[-1].length);
        v19->position.x = (float)(v19[-1].length * (float)v29) + v19[-1].position.x;
        v19->position.z = (float)z + (float)v30;
        v19->position.y = (float)y + (float)v31;
      }
      while ( v17 < this->joints.num );
    }
    v32 = 0;
    LODWORD(v33) = this->numBlendFrames;
    HIDWORD(v33) = this->joints.num;
    LODWORD(v16) = this->blendFrame;
    *(_QWORD *)&v67.mat[0].x = v16;
    v34 = HIDWORD(v33) - 1;
    v35 = (_cntlzw(v33 - v16) & 0x20) != 0;
    v36 = (float)((float)v16 / (float)v33);
    if ( HIDWORD(v33) - 1 > 0 )
    {
      v37 = v35;
      do
      {
        v38 = &this->joints.list[v32];
        v39 = (float)(v38[1].position.y - v38->position.y);
        v40 = (float)(v38[1].position.x - v38->position.x);
        v41 = (float)(v38[1].position.z - v38->position.z);
        _FP1 = (float)((float)((float)((float)v41 * (float)v41)
                             + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f12, f1, f2, f0 }
        v44 = __frsqrte(_FP12);
        v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                            * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                    * (float)v44)
                                                                            - (float)1.5)
                                                            * (float)v44)
                                                    * (float)((float)((float)((float)v41 * (float)v41)
                                                                    + (float)((float)((float)v40 * (float)v40)
                                                                            + (float)((float)v39 * (float)v39)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v44
                                                                                    * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                            * (float)0.5))
                                                                            * (float)v44)
                                                                    - (float)1.5)
                                                    * (float)v44))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v44
                                                            * (float)((float)((float)((float)v41 * (float)v41)
                                                                            + (float)((float)((float)v40 * (float)v40)
                                                                                    + (float)((float)v39 * (float)v39)))
                                                                    * (float)0.5))
                                                    * (float)v44)
                                            - (float)1.5)
                            * (float)v44));
        v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                            * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                            * (float)v44))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                            * (float)v44)
                                                                                    - (float)1.5)
                                                                    * (float)v44))
                                                    * (float)((float)((float)((float)v41 * (float)v41)
                                                                    + (float)((float)((float)v40 * (float)v40)
                                                                            + (float)((float)v39 * (float)v39)))
                                                            * (float)0.5))
                                            * (float)v45)
                                    - (float)1.5)
                    * (float)v45);
        v47 = (float)((float)v46 * (float)(v38[1].position.y - v38->position.y));
        v65.x = (float)v46 * (float)(v38[1].position.x - v38->position.x);
        v65.y = v47;
        v65.z = (float)v46 * (float)v41;
        if ( v32 != 0 )
        {
          v51 = (float)(v38->position.y - v38[-1].position.y);
          v52 = (float)(v38->position.z - v38[-1].position.z);
          v53 = (float)(v38->position.x - v38[-1].position.x);
          _FP1 = (float)((float)((float)((float)v53 * (float)v53)
                               + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f12, f1, f2, f0 }
          v56 = __frsqrte(_FP12);
          v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56
                                                                                              * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56)
                                                      * (float)((float)((float)((float)v53 * (float)v53)
                                                                      + (float)((float)((float)v52 * (float)v52)
                                                                              + (float)((float)v51 * (float)v51)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v56
                                                                                      * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)v56)
                                                                      - (float)1.5)
                                                      * (float)v56))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v56
                                                              * (float)((float)((float)((float)v53 * (float)v53)
                                                                              + (float)((float)((float)v52 * (float)v52)
                                                                                      + (float)((float)v51 * (float)v51)))
                                                                      * (float)0.5))
                                                      * (float)v56)
                                              - (float)1.5)
                              * (float)v56));
          v64.y = (float)(v38->position.y - v38[-1].position.y)
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56)
                                                                                                * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                                * (float)v56))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                                * (float)v56)
                                                                                        - (float)1.5)
                                                                        * (float)v56))
                                                        * (float)((float)((float)((float)v53 * (float)v53)
                                                                        + (float)((float)((float)v52 * (float)v52)
                                                                                + (float)((float)v51 * (float)v51)))
                                                                * (float)0.5))
                                                * (float)v57)
                                        - (float)1.5)
                        * (float)v57);
          v64.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56)
                                                                                                * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                                * (float)v56))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                                * (float)v56)
                                                                                        - (float)1.5)
                                                                        * (float)v56))
                                                        * (float)((float)((float)((float)v53 * (float)v53)
                                                                        + (float)((float)((float)v52 * (float)v52)
                                                                                + (float)((float)v51 * (float)v51)))
                                                                * (float)0.5))
                                                * (float)v57)
                                        - (float)1.5)
                        * (float)v57)
                * (float)v53;
          v64.z = (float)v52
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56)
                                                                                                * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                                * (float)v56))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                                * (float)v56)
                                                                                        - (float)1.5)
                                                                        * (float)v56))
                                                        * (float)((float)((float)((float)v53 * (float)v53)
                                                                        + (float)((float)((float)v52 * (float)v52)
                                                                                + (float)((float)v51 * (float)v51)))
                                                                * (float)0.5))
                                                * (float)v57)
                                        - (float)1.5)
                        * (float)v57);
        }
        else
        {
          animator = this->animator;
          v49 = -animator->g.axis.mat[0].y;
          v50 = -animator->g.axis.mat[0].z;
          v64.x = -animator->g.axis.mat[0].x;
          v64.y = v49;
          v64.z = v50;
        }
        idMat3::MakeRotation(this: &v66, from: &v64, to: &v65);
        if ( !v37 )
        {
          v58 = idMat3::ToQuat(this: &v67, result: (idQuat *)&v66);
          idQuat::Slerp(this: (idQuat *)&v67.mat[2].z, from: &quat_identity, to: v58, t: v36);
          v59 = (float *)idQuat::ToMat3(this: (idQuat *)&v68, result: (idMat3 *)&v67.mat[2].z);
          v66.mat[0].x = *v59;
          v66.mat[0].y = v59[1];
          v66.mat[0].z = v59[2];
          v66.mat[1].x = v59[3];
          v66.mat[1].y = v59[4];
          v66.mat[1].z = v59[5];
          v66.mat[2].x = v59[6];
          v66.mat[2].y = v59[7];
          v66.mat[2].z = v59[8];
        }
        idTreeAnimator::SetJointAxis(
          this: this->animator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->joints.list[v32++].index.value,
          type: JOINTMOD_MODEL,
          axis: &v66);
      }
      while ( v32 < this->joints.num - 1 );
    }
    if ( anim_debugDragJoints.valueInteger != 0 )
    {
      v60 = 0;
      if ( this->joints.num > 0 )
      {
        v61 = 0;
        do
        {
          v62 = ((int (__fastcall *)(idCommon *, int))common->RW)(a1: common, a2: v34);
          (*(void (__fastcall **)(int, idColor *, idVec3 *, _DWORD, _DWORD))(*(_DWORD *)v62 + 256))(
            a1: v62,
            a2: &idColor::colorGreen,
            a3: &this->joints.list[v61].position,
            a4: 0,
            a5: 0);
          ++v60;
          ++v61;
        }
        while ( v60 < this->joints.num );
      }
    }
  }
}


// ========================================================================
// ??1idAnimator_DragJoints@@UAA@XZ
// EA  : 0x826E0C70
// RVA : 0x006E0C70
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __fastcall idAnimator_DragJoints::~idAnimator_DragJoints(idAnimator_DragJoints *this)
{
  this->__vftable = (idAnimator_DragJoints_vtbl *)&idAnimator_DragJoints::`vftable';
  idMD6LeafPause::~idMD6LeafPause(this: &this->animLeaf);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subwebs);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$246921
// EA  : 0x826E0CD4
// RVA : 0x006E0CD4
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_246921()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246922
// EA  : 0x826E0CFC
// RVA : 0x006E0CFC
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_246922()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$246923
// EA  : 0x826E0D28
// RVA : 0x006E0D28
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_246923()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// ??0idAnimator_DragJoints@@QAA@XZ
// EA  : 0x826E0D60
// RVA : 0x006E0D60
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

idAnimator_DragJoints *__fastcall idAnimator_DragJoints::idAnimator_DragJoints(idAnimator_DragJoints *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->enabled = false;
  this->__vftable = (idAnimator_DragJoints_vtbl *)&idAnimator_DragJoints::`vftable';
  this->blendFrame = 0;
  this->numBlendFrames = 20;
  this->animweb = nullptr;
  this->subwebs.list = nullptr;
  this->subwebs.granularity = 0;
  this->subwebs.memTag = 5;
  this->subwebs.listStatic = 0;
  this->subwebs.size = 0;
  this->subwebs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subwebs);
  this->baseJoint.value = -1;
  this->joints.list = nullptr;
  this->joints.granularity = 0;
  this->joints.memTag = 5;
  this->joints.listStatic = 0;
  this->joints.size = 0;
  this->joints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  this->animator = nullptr;
  idMD6LeafPause::idMD6LeafPause(this: &this->animLeaf);
  this->mergeBranch = nullptr;
  return this;
}


// ========================================================================
// __unwind$247180
// EA  : 0x826E0E10
// RVA : 0x006E0E10
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_247180()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$247181
// EA  : 0x826E0E38
// RVA : 0x006E0E38
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_247181()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// __unwind$247182
// EA  : 0x826E0E64
// RVA : 0x006E0E64
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void _unwind_247182()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// ?InternalInit@idAnimator_DragJoints@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E1020
// RVA : 0x006E1020
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

idMD6Branch *__fastcall idAnimator_DragJoints::InternalInit(
        idAnimator_DragJoints *this,
        const idAnimatorParms_Base *parms)
{
  idMD6Branch *result; // r3
  idAnimStack *animStack; // r11
  int v6; // r30
  int v7; // r28
  int v8; // r29
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v9; // r27
  idDeclAnimWeb *SubWebIndexForName; // r3
  int active; // r26
  idList<idAnimator_DragJoints::idJoint,5> *p_joints; // r30
  __int16 value; // r10
  idAnimator_DragJoints::idJoint *list; // r28
  int v15; // r29
  int v16; // r27
  int v17; // r28
  int v18; // r29
  idAnimStack *v19; // r9
  float *p_value; // r11
  double v21; // fp9
  double v22; // fp8
  double v23; // fp6
  double v24; // fp5
  int v25; // r9
  int v26; // r10
  float *v27; // r11
  double v28; // fp12
  double v29; // fp9
  _BYTE v30[80]; // [sp+50h] [-50h] BYREF

  result = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  this->mergeBranch = result;
  if ( result != nullptr )
  {
    this->animator = parms->animStack->treeAnimator;
    animStack = parms[1].animStack;
    if ( animStack != nullptr )
    {
      if ( this->animweb != nullptr )
      {
        idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5>::SetNum(
          this: &this->subwebs,
          newNum: animStack->md6Allocator.fusionBranches.total);
        animStack = parms[1].animStack;
        v6 = 0;
        if ( animStack->md6Allocator.fusionBranches.total > 0 )
        {
          v7 = 0;
          v8 = 0;
          do
          {
            v9 = &this->subwebs.list[v8];
            SubWebIndexForName = idDeclAnimWeb::GetSubWebIndexForName(
                                   this: (idDeclAnimWeb *)v30,
                                   result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->animweb->decl,
                                   subWebName: *(const char **)&animStack->md6Allocator.fusionBranches.free->buffer[v7 + 4]);
            ++v6;
            ++v8;
            v7 += 32;
            v9->value = (__int16)HIWORD(SubWebIndexForName->__vftable);
            animStack = parms[1].animStack;
          }
          while ( v6 < animStack->md6Allocator.fusionBranches.total );
        }
      }
      active = animStack->md6Allocator.blendAdditiveBranches.active;
      if ( active > 0 )
      {
        p_joints = &this->joints;
        idList<idAnimator_DragJoints::idJoint,5>::SetNum(this: &this->joints, newNum: active + 1);
        value = idTreeAnimator::GetJointIndex(
                  this: (idTreeAnimator *)v30,
                  result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                  jointName: (const char *)parms[1].animStack->md6Allocator.blendBranches.blocks)->value;
        this->enabled = true;
        this->baseJoint.value = value;
        list = this->joints.list;
        v15 = 0;
        v16 = 0;
        do
        {
          list[v15].index = (idIndex<short,enum invalidJointIndex_t>)idTreeAnimator::GetJointIndex(
                                                                       this: (idTreeAnimator *)v30,
                                                                       result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                                                                       jointName: *(const char **)(parms[1].animStack->md6Allocator.blendAdditiveBranches.total
                                                                                      + v16
                                                                                      + 4))->value;
          list = p_joints->list;
          if ( (unsigned __int16)p_joints->list[v15].index.value >= 0x8000u )
            this->enabled = false;
          --active;
          v16 += 32;
          ++v15;
        }
        while ( active != 0 );
        if ( this->enabled )
        {
          v17 = 0;
          p_joints->list[this->joints.num - 1].index.value = p_joints->list[this->joints.num - 2].index.value;
          if ( this->joints.num > 0 )
          {
            v18 = 0;
            do
            {
              idTreeAnimator::GetWorldSpaceJointTransform(
                this: this->animator,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_joints->list[v18].index.value,
                origin: &p_joints->list[v18].position,
                axis: &p_joints->list[v18].originalRotation);
              if ( v17 == this->joints.num - 1 )
              {
                v19 = parms[1].animStack;
                p_value = (float *)&p_joints->list[v18].index.value;
                v21 = (float)(p_value[12] * *(float *)&v19->md6Allocator.branches.active);
                v22 = (float)(p_value[13] * *(float *)&v19->md6Allocator.branches.active);
                v23 = p_value[2];
                v24 = p_value[3];
                p_value[1] = (float)(p_value[11] * *(float *)&v19->md6Allocator.branches.active) + p_value[1];
                p_value[2] = (float)v23 + (float)v21;
                p_value[3] = (float)v24 + (float)v22;
              }
              ++v17;
              ++v18;
            }
            while ( v17 < this->joints.num );
          }
          v25 = 0;
          if ( this->joints.num - 1 > 0 )
          {
            v26 = 0;
            do
            {
              ++v25;
              v27 = (float *)&p_joints->list[v26++].index.value;
              v28 = (float)(v27[1] - v27[15]);
              v29 = (float)(v27[2] - v27[16]);
              v27[4] = __fsqrts((float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)));
            }
            while ( v25 < this->joints.num - 1 );
          }
          idAnimator_DragJoints::ReinitJoints(this);
        }
      }
    }
    return (idMD6Branch *)this->enabled;
  }
  return result;
}


// ========================================================================
// `dynamic initializer for 'anim_debugDragJoints''
// EA  : 0x8333EFD8
// RVA : 0x0133EFD8
// PDB : w:\tech5\engine\gamelib\animstack\animator_dragjoints.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugDragJoints__()
{
  idCVar::idCVar(
    this: &anim_debugDragJoints,
    name: "anim_debugDragJoints",
    value: "0",
    flags: 1,
    description: "display debugging information for drag joints",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugDragJoints__);
}

