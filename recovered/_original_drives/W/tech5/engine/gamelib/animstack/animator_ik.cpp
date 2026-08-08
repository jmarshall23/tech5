
// ========================================================================
// ??1idAnimator_IK@@UAA@XZ
// EA  : 0x826E26F8
// RVA : 0x006E26F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_IK::~idAnimator_IK(idAnimator_IK *this)
{
  this->animator = nullptr;
  this->__vftable = (idAnimator_IK_vtbl *)&idAnimator_IK::`vftable';
  this->clip = nullptr;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ?PreBlendSnapshot@idAnimator_IK@@UAAXPAVidAnimStack@@HHM@Z
// EA  : 0x826E2718
// RVA : 0x006E2718
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_IK::PreBlendSnapshot(
        idAnimator_IK *this,
        idAnimStack *stack,
        int curTime,
        int ticksPerSec,
        double fraction)
{
  ((void (__fastcall *)(idAnimator_IK *, idAnimStack *, int, int, double))this->Evaluate)(
    a1: this,
    a2: stack,
    a3: curTime,
    a4: ticksPerSec,
    a5: fraction);
}


// ========================================================================
// ??1idAnimator_WalkIK@@UAA@XZ
// EA  : 0x826E2730
// RVA : 0x006E2730
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::~idAnimator_WalkIK(idAnimator_WalkIK *this)
{
  idClipModel *footModel; // r3
  idClipModel *clipModel; // r3

  this->__vftable = (idAnimator_WalkIK_vtbl *)&idAnimator_WalkIK::`vftable';
  footModel = this->footModel;
  if ( footModel != nullptr )
    idClipModel::Delete(this: footModel);
  if ( this->createdClipModel )
  {
    clipModel = this->clipModel;
    if ( clipModel != nullptr )
      idClipModel::Delete(this: clipModel);
  }
  idMD6LeafPause::~idMD6LeafPause(this: &this->animLeaf);
  this->animator = nullptr;
  this->__vftable = (idAnimator_WalkIK_vtbl *)&idAnimator_IK::`vftable';
  this->clip = nullptr;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$247353
// EA  : 0x826E27C8
// RVA : 0x006E27C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_247353()
{
  int v0; // r12

  idAnimator_IK::~idAnimator_IK(this: *(idAnimator_IK **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247354
// EA  : 0x826E27F0
// RVA : 0x006E27F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_247354()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 112 + 132) + 1656));
}


// ========================================================================
// ?EnableLeg@idAnimator_WalkIK@@QAAXH@Z
// EA  : 0x826E2820
// RVA : 0x006E2820
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::EnableLeg(idAnimator_WalkIK *this, char num)
{
  this->enabledLegs |= 1 << num;
}


// ========================================================================
// ?DisableLeg@idAnimator_WalkIK@@QAAXH@Z
// EA  : 0x826E2838
// RVA : 0x006E2838
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::DisableLeg(idAnimator_WalkIK *this, char num)
{
  this->enabledLegs &= ~(1 << num);
}


// ========================================================================
// ?InternalGetMergeBranch@idAnimator_WalkIK@@MAAPAVidMD6Branch@@XZ
// EA  : 0x826E2850
// RVA : 0x006E2850
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_WalkIK::InternalGetMergeBranch(idAnimator_WalkIK *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ??1idAnimator_ReachIK@@UAA@XZ
// EA  : 0x826E2858
// RVA : 0x006E2858
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_ReachIK::~idAnimator_ReachIK(idAnimator_ReachIK *this)
{
  this->decl = nullptr;
  this->__vftable = (idAnimator_ReachIK_vtbl *)&idAnimator_IK::`vftable';
  this->animator = nullptr;
  this->clip = nullptr;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ?SolveTwoBones@idAnimator_IK@@QAA_NABVidVec3@@00MMAAV2@@Z
// EA  : 0x826E2970
// RVA : 0x006E2970
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

int __fastcall idAnimator_IK::SolveTwoBones(
        idAnimator_IK *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        const idVec3 *dir,
        double len0,
        double len1,
        idVec3 *jointPos,
        int a8,
        float *a9)
{
  double x; // fp26
  double v10; // fp9
  double y; // fp25
  double v13; // fp13
  double z; // fp24
  double v15; // fp12
  double v20; // fp2
  double v21; // fp2
  double v22; // fp31
  double v23; // fp27
  double v24; // fp23
  double v25; // fp22
  double v26; // fp21
  double v27; // fp10
  double v28; // fp4
  double v29; // fp2
  double v31; // fp7
  double v32; // fp12
  double v33; // fp10
  double v34; // fp9
  double v35; // fp13
  double v36; // fp12
  idVec3 v37; // [sp+50h] [-80h] BYREF

  x = startPos->x;
  v10 = (float)((float)len0 + (float)len1);
  y = startPos->y;
  v13 = (float)(endPos->y - startPos->y);
  z = startPos->z;
  v15 = (float)(endPos->z - startPos->z);
  _FP5 = (float)((float)((float)((float)v15 * (float)v15)
                       + (float)((float)((float)v13 * (float)v13)
                               + (float)((float)(endPos->x - startPos->x) * (float)(endPos->x - startPos->x))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f10 }
  v20 = __frsqrte(_FP3);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v13 * (float)v13) + (float)((float)(endPos->x - startPos->x) * (float)(endPos->x - startPos->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)(endPos->x - startPos->x)
                                                                              * (float)(endPos->x - startPos->x))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                                                              + (float)((float)((float)v13 * (float)v13) + (float)((float)(endPos->x - startPos->x) * (float)(endPos->x - startPos->x))))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)(endPos->x - startPos->x)
                                                                                      * (float)(endPos->x - startPos->x))))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)(endPos->x - startPos->x)
                                                                              * (float)(endPos->x - startPos->x))))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)(endPos->x - startPos->x)
                                                                                      * (float)(endPos->x - startPos->x))))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21)
              * (float)((float)((float)v15 * (float)v15)
                      + (float)((float)((float)v13 * (float)v13)
                              + (float)((float)(endPos->x - startPos->x) * (float)(endPos->x - startPos->x)))));
  if ( v23 >= v10 || v23 <= __fabs((float)((float)len0 - (float)len1)) )
  {
    v35 = (float)((float)(endPos->y - startPos->y) * (float)0.5);
    v36 = (float)((float)(endPos->z - startPos->z) * (float)0.5);
    *a9 = startPos->x + (float)((float)(endPos->x - startPos->x) * (float)0.5);
    a9[1] = (float)y + (float)v35;
    a9[2] = (float)z + (float)v36;
    return 0;
  }
  else
  {
    v24 = (float)((float)v13
                * (float)((float)-(float)((float)((float)((float)v21
                                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                                        + (float)((float)((float)v13 * (float)v13)
                                                                                + (float)((float)(endPos->x - startPos->x)
                                                                                        * (float)(endPos->x - startPos->x))))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v25 = (float)((float)(endPos->x - startPos->x)
                * (float)((float)-(float)((float)((float)((float)v21
                                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                                        + (float)((float)((float)v13 * (float)v13)
                                                                                + (float)((float)(endPos->x - startPos->x)
                                                                                        * (float)(endPos->x - startPos->x))))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v26 = (float)((float)v15
                * (float)((float)-(float)((float)((float)((float)v21
                                                        * (float)((float)((float)((float)v15 * (float)v15)
                                                                        + (float)((float)((float)v13 * (float)v13)
                                                                                + (float)((float)(endPos->x - startPos->x)
                                                                                        * (float)(endPos->x - startPos->x))))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v27 = dir->z;
    v28 = (float)((float)((float)v15 * (float)v22)
                * (float)((float)(dir->z * (float)((float)v15 * (float)v22))
                        + (float)((float)(dir->x * (float)((float)(endPos->x - startPos->x) * (float)v22))
                                + (float)(dir->y * (float)((float)(endPos->y - startPos->y) * (float)v22)))));
    v29 = (float)(dir->y
                - (float)((float)((float)v13 * (float)v22)
                        * (float)((float)(dir->z * (float)((float)(endPos->z - startPos->z) * (float)v22))
                                + (float)((float)(dir->x * (float)((float)(endPos->x - startPos->x) * (float)v22))
                                        + (float)(dir->y * (float)((float)v13 * (float)v22))))));
    v37.x = dir->x
          - (float)((float)((float)(endPos->x - startPos->x) * (float)v22)
                  * (float)((float)(dir->z * (float)((float)(endPos->z - startPos->z) * (float)v22))
                          + (float)((float)(dir->x * (float)((float)(endPos->x - startPos->x) * (float)v22))
                                  + (float)(dir->y * (float)((float)(endPos->y - startPos->y) * (float)v22)))));
    v37.y = v29;
    v37.z = (float)v27 - (float)v28;
    idVec3::NormalizeFast(this: &v37);
    v31 = (float)((float)-(float)((float)((float)len1 * (float)len1)
                                - (float)((float)((float)v23 * (float)v23) + (float)((float)len0 * (float)len0)))
                * (float)((float)v22 * (float)0.5));
    v32 = __fsqrts(__fabs((float)-(float)((float)((float)v31 * (float)v31) - (float)((float)len0 * (float)len0))));
    v33 = (float)(v37.y * (float)v32);
    v34 = (float)(v37.z * (float)v32);
    *a9 = (float)((float)x
                + (float)((float)v25
                        * (float)((float)-(float)((float)((float)len1 * (float)len1)
                                                - (float)((float)((float)v23 * (float)v23)
                                                        + (float)((float)len0 * (float)len0)))
                                * (float)((float)v22 * (float)0.5))))
        + (float)(v37.x * (float)v32);
    a9[1] = (float)((float)y
                  + (float)((float)v24
                          * (float)((float)-(float)((float)((float)len1 * (float)len1)
                                                  - (float)((float)((float)v23 * (float)v23)
                                                          + (float)((float)len0 * (float)len0)))
                                  * (float)((float)v22 * (float)0.5))))
          + (float)v33;
    a9[2] = (float)((float)z
                  + (float)((float)v26
                          * (float)((float)-(float)((float)((float)len1 * (float)len1)
                                                  - (float)((float)((float)v23 * (float)v23)
                                                          + (float)((float)len0 * (float)len0)))
                                  * (float)((float)v22 * (float)0.5))))
          + (float)v34;
    return 1;
  }
}


// ========================================================================
// ?GetBoneAxis@idAnimator_IK@@QAAMABVidVec3@@00AAVidMat3@@@Z
// EA  : 0x826E2B38
// RVA : 0x006E2B38
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

float __fastcall idAnimator_IK::GetBoneAxis(
        idAnimator_IK *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        const idVec3 *dir,
        idMat3 *axis)
{
  double v5; // fp8
  double v6; // fp11
  double v7; // fp6
  double v8; // fp3
  double v9; // fp5
  double v10; // fp11
  double v13; // fp7
  double v14; // fp7
  double z; // fp5
  double y; // fp3
  double v17; // fp10
  double v18; // fp8
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  double v25; // fp5
  double v28; // fp3
  double v29; // fp13
  double v30; // fp5
  double v31; // fp1
  double v32; // fp7
  double v33; // fp5

  v5 = (float)(endPos->y - startPos->y);
  v6 = (float)(endPos->x - startPos->x);
  v7 = (float)(endPos->z - startPos->z);
  axis->mat[0].x = endPos->x - startPos->x;
  axis->mat[0].z = v7;
  axis->mat[0].y = v5;
  v8 = v5;
  v9 = v6;
  v10 = (float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)));
  _FP10 = (float)((float)v10 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f13 }
  v13 = __frsqrte(_FP8);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                      * (float)((float)v10 * (float)0.5))
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13)
                                              * (float)((float)v10 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)v10 * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v10 * (float)0.5)) * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
  axis->mat[0].z = (float)v7
                 * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5)) * (float)v14)
                                         - (float)1.5)
                         * (float)v14);
  axis->mat[0].y = (float)v8
                 * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5)) * (float)v14)
                                         - (float)1.5)
                         * (float)v14);
  axis->mat[0].x = (float)v9
                 * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5)) * (float)v14)
                                         - (float)1.5)
                         * (float)v14);
  v17 = (float)((float)((float)((float)v7
                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5))
                                                              * (float)v14)
                                                      - (float)1.5)
                                      * (float)v14))
                      * dir->z)
              + (float)((float)((float)((float)v9
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)v10 * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              * dir->x)
                      + (float)((float)((float)v8
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)v10 * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              * dir->y)));
  v18 = (float)((float)((float)v8
                      * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5))
                                                      * (float)v14)
                                              - (float)1.5)
                              * (float)v14))
              * (float)((float)((float)((float)v7
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)v10 * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              * dir->z)
                      + (float)((float)((float)((float)v9
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)v10 * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      * dir->x)
                              + (float)((float)((float)v8
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)v10 * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      * dir->y))));
  v19 = (float)(dir->x
              - (float)((float)((float)v9
                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5))
                                                              * (float)v14)
                                                      - (float)1.5)
                                      * (float)v14))
                      * (float)((float)((float)((float)v7
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)v10 * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      * dir->z)
                              + (float)((float)((float)((float)v9
                                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)v10 * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14))
                                              * dir->x)
                                      + (float)((float)((float)v8
                                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)v10 * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14))
                                              * dir->y)))));
  y = dir->y;
  z = dir->z;
  axis->mat[1].x = v19;
  v20 = (float)((float)y - (float)v18);
  axis->mat[1].y = v20;
  v21 = (float)((float)z
              - (float)((float)((float)v7
                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5))
                                                              * (float)v14)
                                                      - (float)1.5)
                                      * (float)v14))
                      * (float)v17));
  axis->mat[1].z = (float)z
                 - (float)((float)((float)v7
                                 * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5))
                                                                 * (float)v14)
                                                         - (float)1.5)
                                         * (float)v14))
                         * (float)v17);
  v23 = v21;
  v22 = v19;
  v24 = v20;
  v25 = (float)((float)((float)v21 * (float)v21)
              + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20)));
  _FP4 = (float)((float)((float)((float)v21 * (float)v21)
                       + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f13 }
  v28 = (float)((float)v25 * (float)0.5);
  v29 = __frsqrte(_FP2);
  v30 = (float)((float)-(float)((float)((float)((float)v29 * (float)((float)v25 * (float)0.5)) * (float)v29) - (float)1.5)
              * (float)v29);
  v31 = (float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v10 * (float)0.5)) * (float)v14)
                                      - (float)1.5)
                      * (float)v14)
              * (float)v10);
  v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)v28)
                                                                              * (float)v30)
                                                                      - (float)1.5)
                                                      * (float)v30)
                                              * (float)v28)
                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)v28) * (float)v30)
                                                              - (float)1.5)
                                              * (float)v30))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v30 * (float)v28) * (float)v30) - (float)1.5) * (float)v30));
  v33 = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)v28)
                                                                                      * (float)v30)
                                                                              - (float)1.5)
                                                              * (float)v30)
                                                      * (float)v28)
                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)v28)
                                                                              * (float)v30)
                                                                      - (float)1.5)
                                                      * (float)v30))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v30 * (float)v28) * (float)v30) - (float)1.5)
                              * (float)v30)));
  axis->mat[1].y = v33;
  axis->mat[1].z = (float)v23 * (float)v32;
  axis->mat[1].x = (float)v22 * (float)v32;
  axis->mat[2].x = (float)(axis->mat[0].z * (float)v33) - (float)(axis->mat[0].y * (float)((float)v23 * (float)v32));
  axis->mat[2].y = (float)(axis->mat[0].x * axis->mat[1].z) - (float)(axis->mat[0].z * axis->mat[1].x);
  axis->mat[2].z = (float)(axis->mat[0].y * axis->mat[1].x) - (float)(axis->mat[0].x * axis->mat[1].y);
  return *((float *)&v31 + 1);
}


// ========================================================================
// ?IsActive@idAnimator_WalkIK@@QBA_NXZ
// EA  : 0x826E2D60
// RVA : 0x006E2D60
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

BOOL __fastcall idAnimator_WalkIK::IsActive(idAnimator_WalkIK *this)
{
  char v1; // r11
  char v2; // r11

  if ( !this->ikInitialized || (v1 = 1, ik_enable.valueInteger == 0) )
    v1 = 0;
  if ( v1 == 0 || this->decl == nullptr || this->animator == nullptr )
    return false;
  if ( !this->enabled || (v2 = 1, this->enabledLegs == 0) )
    v2 = 0;
  return v2 != 0;
}


// ========================================================================
// ?SetJointModFromOriginAxis@@YAXAAUjointMod_t@idMD6Blend@@V?$idIndex@FW4invalidJointIndex_t@@@@GABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826E2DE8
// RVA : 0x006E2DE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall SetJointModFromOriginAxis(
        idMD6Blend::jointMod_t *mod,
        idIndex<short,enum invalidJointIndex_t> *joint,
        unsigned __int16 flags,
        const idVec3 *origin,
        const idMat3 *axis)
{
  mod->joint.value = (__int16)joint;
  mod->flags = flags;
  mod->mat[0] = axis->mat[0].x;
  mod->mat[1] = axis->mat[1].x;
  mod->mat[2] = axis->mat[2].x;
  mod->mat[3] = origin->x;
  mod->mat[4] = axis->mat[0].y;
  mod->mat[5] = axis->mat[1].y;
  mod->mat[6] = axis->mat[2].y;
  mod->mat[7] = origin->y;
  mod->mat[8] = axis->mat[0].z;
  mod->mat[9] = axis->mat[1].z;
  mod->mat[10] = axis->mat[2].z;
  mod->mat[11] = origin->z;
  mod->s[0] = 0.0;
  mod->s[1] = 0.0;
  mod->s[2] = 0.0;
}


// ========================================================================
// ?EnableAll@idAnimator_WalkIK@@QAAXXZ
// EA  : 0x826E2E68
// RVA : 0x006E2E68
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::EnableAll(idAnimator_WalkIK *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  HIDWORD(v1) = 1 << this->numLegs;
  this->oldHeightsValid = false;
  this->modelQuery.index = v1;
  this->enabledLegs = HIDWORD(v1) - 1;
  this->waistQuery.index = v1;
  this->legQueries[0].index = v1;
  this->legQueries[1].index = v1;
  this->legQueries[2].index = v1;
  this->legQueries[3].index = v1;
  this->legQueries[4].index = v1;
  this->legQueries[5].index = v1;
  this->legQueries[6].index = v1;
  this->legQueries[7].index = v1;
  this->enabled = true;
}


// ========================================================================
// ?DisableAll@idAnimator_WalkIK@@QAAXXZ
// EA  : 0x826E2EB8
// RVA : 0x006E2EB8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::DisableAll(idAnimator_WalkIK *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->enabledLegs = 0;
  this->oldHeightsValid = false;
  this->modelQuery.index = v1;
  this->waistQuery.index = v1;
  this->legQueries[0].index = v1;
  this->legQueries[1].index = v1;
  this->legQueries[2].index = v1;
  this->legQueries[3].index = v1;
  this->legQueries[4].index = v1;
  this->legQueries[5].index = v1;
  this->legQueries[6].index = v1;
  this->legQueries[7].index = v1;
}


// ========================================================================
// ?GetFootSurfaceType@idAnimator_WalkIK@@QBA?BHW4footStepType_t@@@Z
// EA  : 0x826E2EF0
// RVA : 0x006E2EF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

int __fastcall idAnimator_WalkIK::GetFootSurfaceType(idAnimator_WalkIK *this, footStepType_t footstep)
{
  const idDeclWalkIK *decl; // r11
  int num; // r7
  int v6; // r10
  idIKLeg *list; // r8
  int v8; // r11
  idIKLeg *v9; // r9

  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  num = decl->legJoints.num;
  v6 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    idLib::Warning(fmt: "idAnimator_WalkIK::GetFootSurfaceType: no leg found for %d", footstep);
    return this->surfaceTypes[0];
  }
  else
  {
    list = decl->legJoints.list;
    v9 = list;
    v8 = 0;
    while ( v9->footstep != footstep )
    {
      ++v6;
      v9 = &list[++v8];
      if ( v6 >= num )
        goto LABEL_7;
    }
    return this->surfaceTypes[v6];
  }
}


// ========================================================================
// ?InternalShutdown@idAnimator_WalkIK@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826E2FA8
// RVA : 0x006E2FA8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::InternalShutdown(idAnimator_WalkIK *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?InternalIsContributing@idAnimator_WalkIK@@MBA_NXZ
// EA  : 0x826E3000
// RVA : 0x006E3000
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

// attributes: thunk
BOOL __fastcall idAnimator_WalkIK::InternalIsContributing(idAnimator_WalkIK *this)
{
  return idAnimator_WalkIK::IsActive(this);
}


// ========================================================================
// ?SetTargetOrigin@idAnimator_ReachIK@@QAAXHABVidVec3@@@Z
// EA  : 0x826E3008
// RVA : 0x006E3008
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_ReachIK::SetTargetOrigin(idAnimator_ReachIK *this, const int arm, const idVec3 *targetPos)
{
  char *v3; // r11

  v3 = (char *)this + 84 * arm;
  *(idVec3 *)(v3 + 80) = *targetPos;
  v3[160] = 1;
}


// ========================================================================
// ?SetTargetAxis@idAnimator_ReachIK@@QAAXHABVidMat3@@@Z
// EA  : 0x826E3038
// RVA : 0x006E3038
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_ReachIK::SetTargetAxis(idAnimator_ReachIK *this, const int arm, const idMat3 *targetAxis)
{
  char *v3; // r11

  v3 = (char *)this + 84 * arm;
  *(idMat3 *)(v3 + 92) = *targetAxis;
  v3[161] = 1;
}


// ========================================================================
// ?InternalInit@idAnimator_WalkIK@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E3300
// RVA : 0x006E3300
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

int __fastcall idAnimator_WalkIK::InternalInit(idAnimator_WalkIK *this, const idAnimatorParms_Base *parms)
{
  idMD6Branch *v4; // r3
  idAnimStack *animStack; // r11
  idClipModel *clipModel; // r11
  float *p_z; // r10
  int v8; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  const idDeclWalkIK *decl; // r11
  idTreeAnimator *animator; // r10
  int num; // r11
  const idMD6Alias *Alias; // r3
  const idMD6Skel *skeleton; // r11
  const idMD6Anim *defaultAnim; // r30
  idTreeAnimator *v17; // r3
  int v18; // r12
  idDeclMD6 *v19; // r27
  char v20; // r25
  const idVec3 *VisualOffset; // r3
  int numLegs; // r11
  int v23; // r27
  int v24; // r30
  idIndex<short,enum invalidJointIndex_t> *v25; // r28
  int v26; // r10
  int v27; // r10
  int v28; // r10
  int v29; // r10
  int v30; // r7
  int value; // r10
  int v32; // r24
  float *v33; // r25
  idIndex<short,enum invalidJointIndex_t> *hipJoints; // r30
  float *v35; // r28
  float *v36; // r27
  __int16 v37; // r5
  idJointMat *v38; // r10
  idJointMat *v39; // r9
  int v40; // r11
  float *v41; // r11
  double v42; // fp26
  double v43; // fp25
  double v44; // fp24
  double v45; // fp23
  double v46; // fp22
  double v47; // fp19
  double v48; // fp18
  double v49; // fp0
  double v50; // fp9
  double v51; // fp8
  double v52; // fp4
  double v53; // fp3
  double v54; // fp2
  double v55; // fp1
  double v56; // fp31
  double v57; // fp30
  double v58; // fp29
  double v59; // fp28
  double v60; // fp27
  double v61; // fp12
  double v62; // fp10
  double v63; // fp6
  double v64; // fp21
  double v65; // fp20
  double v66; // fp13
  double v67; // fp7
  idJointMat *v68; // r11
  double v69; // fp5
  double v70; // fp11
  int v71; // r10
  int v72; // r5
  idJointMat *v73; // r11
  double v74; // fp8
  double v75; // fp5
  idJointMat *v76; // r11
  double z; // fp12
  double x; // fp0
  double y; // fp13
  const idDeclWalkIK *v80; // r10
  double v81; // fp9
  double v82; // fp11
  double v83; // fp8
  double v84; // fp5
  double v85; // fp7
  double v86; // fp6
  double v87; // fp10
  double v88; // fp9
  double v89; // fp11
  double v90; // fp6
  double v91; // fp5
  double v92; // fp12
  double v93; // fp13
  double v94; // fp8
  double v95; // fp8
  float *p_x; // r11
  double BoneAxis; // fp1
  double v98; // fp9
  double v99; // fp8
  double v100; // fp7
  double v101; // fp6
  double v102; // fp5
  double v103; // fp4
  double v104; // fp3
  double v105; // fp2
  double v106; // fp0
  idMat3 *v107; // r3
  double v108; // fp11
  double v109; // fp8
  double v110; // fp1
  double v111; // fp4
  double v112; // fp3
  double v113; // fp2
  double v114; // fp0
  double v115; // fp13
  double v116; // fp12
  double v117; // fp11
  double v118; // fp10
  double v119; // fp9
  idMat3 *v120; // r3
  double v121; // fp6
  double v122; // fp5
  const idDeclWalkIK *v123; // r11
  double footSize; // fp8
  double v125; // fp4
  double v126; // fp2
  double v127; // fp11
  double v128; // fp5
  double v129; // fp3
  idClipModel *v130; // r3
  idClipModel *v131; // r3
  _DWORD back_chain[20]; // [sp+0h] [-900h]
  idJointMat v133; // [sp+50h] [-8B0h] BYREF
  idMat3 v134; // [sp+80h] [-880h] BYREF
  int v135; // [sp+A4h] [-85Ch] BYREF
  int v136; // [sp+A8h] [-858h] BYREF
  idVec3 v137; // [sp+B0h] [-850h] BYREF
  idVec3 v138; // [sp+C0h] [-840h] BYREF
  idVec3 v139; // [sp+D0h] [-830h] BYREF
  idMat3 v140; // [sp+E0h] [-820h] BYREF
  idMat3 v141; // [sp+110h] [-7F0h] BYREF
  idMat3 v142; // [sp+140h] [-7C0h] BYREF
  idMat3 v143; // [sp+170h] [-790h] BYREF
  idVec3 v144; // [sp+1A0h] [-760h] BYREF
  float v145; // [sp+1ACh] [-754h]
  float v146; // [sp+1B0h] [-750h]
  float v147; // [sp+1B4h] [-74Ch]
  float v148; // [sp+1B8h] [-748h]
  float v149; // [sp+1BCh] [-744h]
  float v150; // [sp+1C0h] [-740h]
  float v151; // [sp+1C4h] [-73Ch]
  float v152; // [sp+1C8h] [-738h]
  float v153; // [sp+1CCh] [-734h]
  idMat3 v154; // [sp+1D0h] [-730h] BYREF
  idTraceModel v155; // [sp+200h] [-700h] BYREF

  v4 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  this->mergeBranch = v4;
  if ( v4 == nullptr )
    return 0;
  animStack = parms[1].animStack;
  LODWORD(v133.mat[0]) = &this->upNormal;
  this->decl = (const idDeclWalkIK *)animStack;
  this->animator = parms->animStack->treeAnimator;
  this->entityNum = parms[1].name.len;
  this->clip = (idClip *)parms[1].name.allocedAndFlag;
  this->clipModel = *(idClipModel **)parms[1].name.baseBuffer;
  this->clipMask = (int)parms[1].name.data;
  this->upNormal.x = *(float *)&parms[1].name.baseBuffer[4];
  this->upNormal.y = *(float *)&parms[1].name.baseBuffer[8];
  this->upNormal.z = *(float *)&parms[1].name.baseBuffer[12];
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    this->internalRadiusXY = idBounds::GetInternalRadiusXY(this: &clipModel->bounds);
  p_z = &v155.offset.z;
  v8 = 6;
  memset(&v155.type, 0, 20);
  v155.offset.x = 0.0;
  v155.offset.y = 0.0;
  v155.offset.z = 0.0;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v8;
  }
  while ( v8 != 0 );
  v155.radius = 0.0;
  v155.isConvex = false;
  v155.pad[2] = 0;
  v155.pad[1] = 0;
  v155.pad[0] = 0;
  if ( (_S13_9 & 1) == 0 )
  {
    footWinding[0].x = 1.0;
    footWinding[0].y = 1.0;
    footWinding[0].z = 0.0;
    footWinding[1].y = 1.0;
    _S13_9 |= 1u;
    footWinding[1].z = 0.0;
    footWinding[1].x = -1.0;
    footWinding[2].x = -1.0;
    footWinding[2].y = -1.0;
    footWinding[2].z = 0.0;
    footWinding[3].x = 1.0;
    footWinding[3].y = -1.0;
    footWinding[3].z = 0.0;
  }
  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  animator = this->animator;
  if ( animator == nullptr )
    return 0;
  num = decl->legJoints.num;
  if ( num >= 8 )
    num = 8;
  this->numLegs = num;
  if ( num == 0 )
    return 1;
  Alias = idDeclMD6::FindAlias(this: animator->decl, aliasName: "misc/af_pose", includeInherited: true);
  if ( Alias != nullptr )
  {
    defaultAnim = (const idMD6Anim *)idResourceList::Load(
                                       this: &idMD6Anim::resourceList,
                                       name: (char *)Alias->animRefs.list->str,
                                       makeDefault: true,
                                       skipStaleCheck: false);
  }
  else
  {
    skeleton = this->animator->decl->model->skeleton;
    if ( skeleton != nullptr )
      defaultAnim = skeleton->defaultAnim;
    else
      defaultAnim = nullptr;
  }
  idTreeAnimator::NumJoints(this: this->animator);
  ((void (*)(void))RtlCheckStack12)();
  v17 = this->animator;
  *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
  v19 = v17->decl;
  v20 = idTreeAnimator::GetRemoveOriginTranslation(ptr: v17);
  VisualOffset = idTreeAnimator::GetVisualOffset(this: this->animator);
  if ( !idDeclMD6::GetJointsForAnimTime(
          this: v19,
          joints: &v133,
          anim: defaultAnim,
          timeMS: 0,
          offset: VisualOffset,
          removeOriginOffset: v20) )
    idLib::Error(
      fmt: "IK animator '%s' is missing pose anim '%s'",
      (const char *)parms[1].animStack->md6Allocator.__vftable,
      defaultAnim->name.str);
  numLegs = this->numLegs;
  v23 = 0;
  this->enabledLegs = 0;
  if ( numLegs <= 0 )
  {
LABEL_28:
    value = (unsigned __int16)idTreeAnimator::GetJointIndex(
                                this: (idTreeAnimator *)&v133,
                                result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                                jointName: this->decl->waistJoint.str)->value;
    this->waistJointHandle.value = value;
    if ( value == 0xFFFF )
    {
      idLib::Warning(fmt: "idAnimator_WalkIK::Init: invalid waist joint '%s'", this->decl->waistJoint.str);
      return 0;
    }
    v32 = 0;
    if ( this->numLegs <= 0 )
    {
LABEL_49:
      v123 = this->decl;
      if ( v123->footSize > 0.0 )
      {
        footSize = v123->footSize;
        v144.y = v123->footSize * footWinding[0].y;
        v144.z = (float)footSize * footWinding[0].z;
        v144.x = (float)footSize * footWinding[0].x;
        v125 = v123->footSize;
        v126 = (float)(v123->footSize * footWinding[1].y);
        v145 = v123->footSize * footWinding[1].x;
        v146 = v126;
        v147 = (float)v125 * footWinding[1].z;
        v127 = v123->footSize;
        v149 = v123->footSize * footWinding[2].y;
        v148 = (float)v127 * footWinding[2].x;
        v150 = (float)v127 * footWinding[2].z;
        v128 = v123->footSize;
        v129 = (float)(v123->footSize * footWinding[3].y);
        v153 = v123->footSize * footWinding[3].z;
        v151 = (float)v128 * footWinding[3].x;
        v152 = v129;
        idTraceModel::SetupPolygon(this: &v155, v: &v144, count: 4);
        v130 = (idClipModel *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xD8u,
                                tag: TAG_CLIPMODEL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        LODWORD(v133.mat[0]) = v130;
        if ( v130 == nullptr )
          goto _LN479;
        v131 = idClipModel::idClipModel(this: v130, clip: this->clip, trm: &v155, numTraceModels: 1, material: nullptr);
LABEL_55:
        this->footModel = v131;
      }
      this->ikInitialized = true;
      return 1;
    }
    v33 = &this->upperLegLength[7];
    hipJoints = this->hipJoints;
    v35 = &this->hipForward[7].z;
    v36 = &this->upperLegToHipJoint[0].mat[1].z;
    while ( 1 )
    {
      v33[232] = 0.0;
      v37 = hipJoints[-24].value;
      v38 = &v133 + hipJoints->value;
      v39 = &v133 + hipJoints[-16].value;
      v40 = 12 * hipJoints[-8].value;
      LODWORD(v133.mat[0]) = v38;
      v41 = &v133.mat[v40];
      v42 = v38->mat[10];
      v43 = v38->mat[6];
      LODWORD(v133.mat[0]) = v41;
      v44 = v38->mat[2];
      LODWORD(v133.mat[0]) = v41;
      v45 = v38->mat[9];
      v46 = v38->mat[5];
      v47 = v38->mat[4];
      v48 = v38->mat[0];
      v49 = v38->mat[11];
      v50 = v39->mat[11];
      v51 = v39->mat[7];
      v52 = v41[10];
      v53 = v41[6];
      v54 = v41[2];
      v55 = v41[9];
      v56 = v41[5];
      v57 = v41[1];
      v58 = v41[8];
      v59 = v41[4];
      v60 = *v41;
      v61 = v41[11];
      v62 = v41[7];
      v63 = v41[3];
      v64 = v38->mat[1];
      v65 = v38->mat[8];
      v66 = v38->mat[7];
      v67 = v38->mat[3];
      v139.x = v39->mat[3];
      v137.x = v63;
      v138.x = v67;
      v140.mat[2].z = v52;
      v140.mat[2].y = v53;
      v140.mat[2].x = v54;
      v140.mat[1].z = v55;
      v140.mat[1].y = v56;
      v140.mat[1].x = v57;
      v140.mat[0].z = v58;
      v140.mat[0].y = v59;
      v140.mat[0].x = v60;
      v137.y = v62;
      v139.z = v50;
      v139.y = v51;
      v137.z = v61;
      v143.mat[2].x = v44;
      v143.mat[1].z = v45;
      v143.mat[1].y = v46;
      v143.mat[1].x = v64;
      v143.mat[0].z = v65;
      v143.mat[0].y = v47;
      v143.mat[0].x = v48;
      v143.mat[2].y = v43;
      v143.mat[2].z = v42;
      v138.y = v66;
      v138.z = v49;
      v68 = &v133 + v37;
      v69 = v68->mat[11];
      v70 = v68->mat[7];
      v35[320] = v68->mat[3];
      v35[321] = v70;
      v35[322] = v69;
      v71 = hipJoints[8].value;
      v72 = *(__int16 *)((char *)&this->animator->decl->model->skeleton->data->size
                       + 2 * hipJoints->value
                       + this->animator->decl->model->skeleton->data->parentTblOffset);
      v73 = &v133 + v72;
      v74 = v73->mat[11];
      v75 = v73->mat[3];
      if ( v71 != -1 )
        break;
      v80 = this->decl;
      if ( !v80->dirsFromBasePose )
      {
        p_x = (float *)((char *)&v80->legJoints.list[-12] + (unsigned int)v36 - (_DWORD)this);
        LODWORD(v133.mat[0]) = p_x;
        if ( (float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1]))) <= 0.0 )
        {
          x = v80->kneeDir.x;
          p_x = &v80->kneeDir.x;
          y = v80->kneeDir.y;
          z = v80->kneeDir.z;
        }
        else
        {
          x = *p_x;
          y = p_x[1];
          z = p_x[2];
        }
        LODWORD(v133.mat[0]) = p_x;
        goto LABEL_47;
      }
      v81 = (float)((float)v66 - v73->mat[7]);
      v133.mat[3] = (float)v66 - v73->mat[7];
      v82 = (float)((float)v67 - (float)v75);
      v133.mat[2] = (float)v67 - (float)v75;
      v83 = (float)((float)v49 - (float)v74);
      v133.mat[4] = v83;
      v84 = (float)((float)((float)v83 * (float)v83)
                  + (float)((float)(v133.mat[2] * v133.mat[2]) + (float)((float)v81 * (float)v81)));
      if ( v84 < 0.000099999997 )
      {
        idLib::Error(
          fmt: "idAnimator_WalkIK: hip joint (%d) and hip parent joint (%d) are in the same position",
          this->hipJoints[v32].value,
          v72);
_LN478:
        idLib::Error(
          fmt: "idAnimator_WalkIK: knee joint (%d) and hip joint (%d) are in the same position",
          this->kneeJoints[v32].value,
          this->hipJoints[v32].value);
_LN479:
        v131 = nullptr;
        goto LABEL_55;
      }
      v133.mat[0] = (float)v62 - (float)v66;
      v85 = (float)((float)v63 - (float)v67);
      v86 = (float)((float)1.0 / (float)__fsqrts(v84));
      v87 = (float)((float)v81 * (float)v86);
      v133.mat[3] = (float)v81 * (float)v86;
      v88 = (float)((float)v83 * (float)v86);
      v133.mat[4] = (float)v83 * (float)v86;
      v89 = (float)((float)v82 * (float)v86);
      v133.mat[2] = v89;
      v90 = (float)(vec3_up.z
                  * (float)((float)((float)v85 * vec3_up.x)
                          + (float)((float)(vec3_up.y * v133.mat[0])
                                  + (float)(vec3_up.z * (float)((float)v61 - (float)v49)))));
      v91 = (float)((float)((float)((float)v85 * vec3_up.x)
                          + (float)((float)(vec3_up.y * v133.mat[0])
                                  + (float)(vec3_up.z * (float)((float)v61 - (float)v49))))
                  * vec3_up.x);
      v93 = (float)(v133.mat[0]
                  - (float)(vec3_up.y
                          * (float)((float)((float)v85 * vec3_up.x)
                                  + (float)((float)(vec3_up.y * v133.mat[0])
                                          + (float)(vec3_up.z * (float)((float)v61 - (float)v49))))));
      v94 = (float)((float)((float)v93 * (float)v93)
                  + (float)((float)((float)((float)v85 - (float)v91) * (float)((float)v85 - (float)v91))
                          + (float)((float)((float)((float)v61 - (float)v49) - (float)v90)
                                  * (float)((float)((float)v61 - (float)v49) - (float)v90))));
      v92 = (float)((float)((float)v61 - (float)v49)
                  - (float)(vec3_up.z
                          * (float)((float)((float)v85 * vec3_up.x)
                                  + (float)((float)(vec3_up.y * v133.mat[0])
                                          + (float)(vec3_up.z * (float)((float)v61 - (float)v49))))));
      if ( v94 < 0.000099999997 )
        goto _LN478;
      v95 = __fsqrts(v94);
      x = (float)((float)((float)v85 - (float)v91) * (float)((float)1.0 / (float)v95));
      y = (float)((float)v93 * (float)((float)1.0 / (float)v95));
      z = (float)((float)v92 * (float)((float)1.0 / (float)v95));
LABEL_48:
      v133.mat[8] = z;
      v133.mat[7] = y;
      v133.mat[6] = x;
      *(v35 - 21) = (float)((float)v89 * (float)v44)
                  + (float)((float)((float)v87 * (float)v43) + (float)((float)v88 * (float)v42));
      *(v35 - 22) = (float)((float)v89 * (float)v64)
                  + (float)((float)((float)v87 * (float)v46) + (float)((float)v88 * (float)v45));
      *(v35 - 23) = (float)((float)v89 * (float)v48)
                  + (float)((float)((float)v87 * (float)v47) + (float)((float)v88 * (float)v65));
      v35[2] = (float)((float)x * (float)v57) + (float)((float)((float)y * (float)v56) + (float)((float)z * (float)v55));
      v35[1] = (float)((float)x * (float)v60) + (float)((float)((float)y * (float)v59) + (float)((float)z * (float)v58));
      v35 += 3;
      *v35 = (float)((float)x * (float)v54) + (float)((float)((float)y * (float)v53) + (float)((float)z * (float)v52));
      BoneAxis = idAnimator_IK::GetBoneAxis(
                   this,
                   startPos: &v138,
                   endPos: &v137,
                   dir: (const idVec3 *)&v133.mat[2],
                   axis: &v134);
      v98 = v134.mat[0].x;
      v99 = v134.mat[1].x;
      v100 = v134.mat[2].x;
      v101 = v134.mat[0].y;
      v102 = v134.mat[1].y;
      v103 = v134.mat[2].y;
      v104 = v134.mat[0].z;
      v105 = v134.mat[1].z;
      v106 = v134.mat[2].z;
      *(v33 - 7) = BoneAxis;
      v142.mat[0].x = v98;
      v142.mat[0].y = v99;
      v142.mat[0].z = v100;
      v142.mat[1].x = v101;
      v142.mat[1].y = v102;
      v142.mat[1].z = v103;
      v142.mat[2].x = v104;
      v142.mat[2].y = v105;
      v142.mat[2].z = v106;
      v107 = idMat3::operator*(this: &v154, result: &v143, a: &v142);
      *(v36 - 5) = v107->mat[0].x;
      *(v36 - 4) = v107->mat[0].y;
      v108 = v107->mat[0].z;
      LODWORD(v133.mat[0]) = &v107->mat[1];
      *(v36 - 3) = v108;
      *(v36 - 2) = v107->mat[1].x;
      *(v36 - 1) = v107->mat[1].y;
      v109 = v107->mat[1].z;
      LODWORD(v133.mat[0]) = &v107->mat[2];
      *v36 = v109;
      *(idVec3 *)(v36 + 1) = v107->mat[2];
      v110 = idAnimator_IK::GetBoneAxis(
               this,
               startPos: &v137,
               endPos: &v139,
               dir: (const idVec3 *)&v133.mat[6],
               axis: &v134);
      v111 = v134.mat[0].x;
      v112 = v134.mat[1].x;
      v113 = v134.mat[2].x;
      v114 = v134.mat[0].y;
      v115 = v134.mat[1].y;
      v116 = v134.mat[2].y;
      v117 = v134.mat[0].z;
      v118 = v134.mat[1].z;
      v119 = v134.mat[2].z;
      *++v33 = v110;
      v141.mat[0].x = v111;
      v141.mat[0].y = v112;
      v141.mat[0].z = v113;
      v141.mat[1].x = v114;
      v141.mat[1].y = v115;
      v141.mat[1].z = v116;
      v141.mat[2].x = v117;
      v141.mat[2].y = v118;
      v141.mat[2].z = v119;
      v120 = idMat3::operator*(this: &v154, result: &v140, a: &v141);
      v36[67] = v120->mat[0].x;
      ++v32;
      v36[68] = v120->mat[0].y;
      v121 = v120->mat[0].z;
      LODWORD(v133.mat[0]) = &v120->mat[1];
      v36[69] = v121;
      ++hipJoints;
      v122 = v120->mat[1].x;
      LODWORD(v133.mat[0]) = &v120->mat[2];
      v36[70] = v122;
      v36[71] = v120->mat[1].y;
      v36[72] = v120->mat[1].z;
      *(idVec3 *)(v36 + 73) = v120->mat[2];
      v36 += 9;
      if ( v32 >= this->numLegs )
        goto LABEL_49;
    }
    LODWORD(v133.mat[0]) = hipJoints[8].value;
    v76 = &v133 + v71;
    z = (float)(v76->mat[11] - (float)v61);
    x = (float)(v76->mat[3] - (float)v63);
    y = (float)(v76->mat[7] - (float)v62);
LABEL_47:
    v133.mat[2] = x;
    v89 = x;
    v133.mat[3] = y;
    v87 = y;
    v133.mat[4] = z;
    v88 = z;
    goto LABEL_48;
  }
  v24 = 0;
  v25 = &this->hipJoints[7];
  while ( 1 )
  {
    v26 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v136,
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->legJoints.list[v24].foot.str)->value;
    v25[-31].value = v26;
    if ( v26 == 0xFFFF )
    {
      idLib::Warning(fmt: "idAnimator_WalkIK::Init: invalid foot joint '%s'", this->decl->legJoints.list[v23].foot.str);
      return 0;
    }
    v27 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)((char *)&v135 + 2),
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->legJoints.list[v24].ankle.str)->value;
    v25[-23].value = v27;
    if ( v27 == 0xFFFF )
    {
      idLib::Warning(
        fmt: "idAnimator_WalkIK::Init: invalid ankle joint '%s'",
        this->decl->legJoints.list[v23].ankle.str);
      return 0;
    }
    v28 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)((char *)&v136 + 2),
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->legJoints.list[v24].knee.str)->value;
    v25[-15].value = v28;
    if ( v28 == 0xFFFF )
    {
      idLib::Warning(fmt: "idAnimator_WalkIK::Init: invalid knee joint '%s'", this->decl->legJoints.list[v23].knee.str);
      return 0;
    }
    v29 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v135,
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->legJoints.list[v24].hip.str)->value;
    v25[-7].value = v29;
    if ( v29 == 0xFFFF )
      break;
    ++v25;
    v25->value = idTreeAnimator::GetJointIndex(
                   this: (idTreeAnimator *)&v133,
                   result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                   jointName: this->decl->legJoints.list[v24++].forward.str)->value;
    v30 = (1 << v23++) | this->enabledLegs;
    this->enabledLegs = v30;
    if ( v23 >= this->numLegs )
      goto LABEL_28;
  }
  idLib::Warning(fmt: "idAnimator_WalkIK::Init: invalid hip joint '%s'", this->decl->legJoints.list[v23].hip.str);
  return 0;
}


// ========================================================================
// $LN465
// EA  : 0x826E3ED4
// RVA : 0x006E3ED4
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _LN465()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2304 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ??0idAnimator_ReachIK@@QAA@XZ
// EA  : 0x826E3F00
// RVA : 0x006E3F00
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

idAnimator_ReachIK *__fastcall idAnimator_ReachIK::idAnimator_ReachIK(idAnimator_ReachIK *this)
{
  int v2; // ctr
  float *p_z; // r5
  float *p_y; // r10
  float *v5; // r4
  float *v6; // r8
  int i; // ctr
  float *v8; // r5
  idIndex<short,enum invalidJointIndex_t> *v9; // r6
  idVec3 *v10; // r10
  idVec3 *v11; // r8
  int v12; // ctr

  idAnimator_Base::idAnimator_Base(this);
  this->ik_activate = false;
  this->__vftable = (idAnimator_ReachIK_vtbl *)&idAnimator_ReachIK::`vftable';
  this->ikInitialized = false;
  this->animator = nullptr;
  this->enabled = true;
  this->entityNum = 0x1FFF;
  this->clip = nullptr;
  this->decl = nullptr;
  this->numArms = 0;
  v2 = 9;
  this->enabledArms = 0;
  this->handJoints[0].value = -1;
  this->handJoints[1].value = -1;
  p_z = &this->targetTransforms[0].origin.z;
  this->elbowJoints[0].value = -1;
  p_y = &mat2_identity.mat[1].y;
  this->elbowJoints[1].value = -1;
  this->shoulderJoints[0].value = -1;
  this->shoulderJoints[1].value = -1;
  this->targetTransforms[0].origin.x = 0.0;
  this->targetTransforms[0].origin.y = 0.0;
  this->targetTransforms[0].origin.z = 0.0;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->targetTransforms[0].selfTag.trans.x = 0.0;
  this->targetTransforms[0].selfTag.trans.y = 0.0;
  this->targetTransforms[0].selfTag.trans.z = 0.0;
  this->targetTransforms[0].selfTag.rot.x = 0.0;
  this->targetTransforms[0].selfTag.rot.y = 0.0;
  v5 = &this->targetTransforms[1].origin.z;
  this->targetTransforms[0].selfTag.rot.z = 0.0;
  v6 = &mat2_identity.mat[1].y;
  this->targetTransforms[0].selfTag.rot.w = 0.0;
  this->targetTransforms[0].selfTag.parentJoint.value = -1;
  this->targetTransforms[1].origin.x = 0.0;
  this->targetTransforms[0].validOrigin = false;
  this->targetTransforms[1].origin.y = 0.0;
  this->targetTransforms[0].validAxis = false;
  this->targetTransforms[1].origin.z = 0.0;
  this->targetTransforms[0].validTag = false;
  for ( i = 9; i != 0; --i )
    *++v5 = *++v6;
  this->targetTransforms[1].selfTag.trans.x = 0.0;
  this->targetTransforms[1].selfTag.trans.y = 0.0;
  this->targetTransforms[1].selfTag.trans.z = 0.0;
  v8 = &this->upperArmLength[1];
  this->targetTransforms[1].selfTag.rot.x = 0.0;
  v9 = &this->elbowJoints[1];
  this->targetTransforms[1].selfTag.rot.y = 0.0;
  this->targetTransforms[1].selfTag.rot.z = 0.0;
  v11 = &this->shoulderForward[1];
  this->targetTransforms[1].selfTag.rot.w = 0.0;
  this->targetTransforms[1].selfTag.parentJoint.value = -1;
  v10 = &this->upperArmToShoulderJoint[1].mat[1];
  this->targetTransforms[1].validOrigin = false;
  v12 = 2;
  this->targetTransforms[1].validAxis = false;
  this->targetTransforms[1].validTag = false;
  do
  {
    v9[-3].value = -1;
    v9[-1].value = -1;
    ++v9;
    v9->value = -1;
    v11[-1].z = 0.0;
    v11[-1].y = 0.0;
    v11[-1].x = 0.0;
    v11[1].z = 0.0;
    v11[1].y = 0.0;
    ++v11;
    v11->x = 0.0;
    *(v8++ - 1) = 0.0;
    *v8 = 0.0;
    v10[-2].z = 1.0;
    v10[-3].y = 1.0;
    v10[-4].x = 1.0;
    v10[-3].z = 0.0;
    v10[-4].z = 0.0;
    v10[-4].y = 0.0;
    v10[-2].y = 0.0;
    v10[-2].x = 0.0;
    v10[-3].x = 0.0;
    v10[4].z = 1.0;
    v10[3].y = 1.0;
    v10[2].x = 1.0;
    v10[3].z = 0.0;
    v10[2].z = 0.0;
    v10[2].y = 0.0;
    v10[4].y = 0.0;
    v10[4].x = 0.0;
    v10 += 3;
    v10->x = 0.0;
    --v12;
  }
  while ( v12 != 0 );
  return this;
}


// ========================================================================
// ?InternalInit@idAnimator_ReachIK@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E4170
// RVA : 0x006E4170
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

int __fastcall idAnimator_ReachIK::InternalInit(idAnimator_ReachIK *this, const idAnimatorParms_Base *parms)
{
  const idDeclReachIK *animStack; // r11
  idTreeAnimator *treeAnimator; // r9
  int num; // r11
  const idMD6Alias *Alias; // r3
  int v7; // r25
  const idMD6Skel *skeleton; // r11
  const idMD6Anim *v9; // r30
  idTreeAnimator *animator; // r3
  int v11; // r12
  idDeclMD6 *decl; // r29
  char v13; // r27
  const idVec3 *VisualOffset; // r3
  int numArms; // r11
  int v16; // r27
  int v17; // r29
  idIndex<short,enum invalidJointIndex_t> *elbowJoints; // r30
  int v19; // r9
  int v20; // r9
  int v21; // r9
  int v22; // r9
  float *v23; // r26
  idIndex<short,enum invalidJointIndex_t> *v24; // r27
  float *p_z; // r29
  float *v26; // r30
  double v27; // fp31
  __int16 value; // r11
  __int16 v29; // r8
  idJointMat *v30; // r10
  idJointMat *v31; // r11
  idJointMat *v32; // r9
  double v33; // fp0
  double v34; // fp13
  double v35; // fp12
  double v36; // fp10
  double v37; // fp9
  double v38; // fp7
  double v39; // fp4
  double v40; // fp3
  double v41; // fp2
  double v42; // fp1
  double v43; // fp30
  double v44; // fp29
  double v45; // fp28
  double v46; // fp11
  double v47; // fp27
  double v48; // fp26
  double v49; // fp25
  double v50; // fp8
  double v51; // fp24
  double v52; // fp6
  double v53; // fp23
  double v54; // fp22
  double v55; // fp31
  double v56; // fp21
  double v57; // fp20
  double v58; // fp19
  double v59; // fp18
  double v60; // fp17
  double v61; // fp16
  double v62; // fp15
  double v63; // fp14
  double BoneAxis; // fp1
  double v65; // fp0
  double v66; // fp13
  double v67; // fp12
  double v68; // fp11
  double v69; // fp10
  double v70; // fp9
  double v71; // fp8
  double v72; // fp7
  double v73; // fp6
  double v74; // fp1
  double v75; // fp10
  double v76; // fp9
  double v77; // fp8
  double v78; // fp7
  double v79; // fp6
  double v80; // fp5
  double v81; // fp4
  double v82; // fp3
  double v83; // fp2
  idVec3 *v84; // r3
  _DWORD back_chain[20]; // [sp+0h] [-2A0h]
  idJointMat v87; // [sp+50h] [-250h] BYREF
  float v88; // [sp+80h] [-220h]
  int v89; // [sp+84h] [-21Ch] BYREF
  idVec3 v90; // [sp+88h] [-218h] BYREF
  idVec3 v91; // [sp+98h] [-208h] BYREF
  idVec3 v92; // [sp+A8h] [-1F8h] BYREF
  idVec3 v93; // [sp+B8h] [-1E8h] BYREF
  idMat3 v94; // [sp+D0h] [-1D0h] BYREF
  idMat3 v95; // [sp+100h] [-1A0h] BYREF
  idMat3 v96; // [sp+130h] [-170h] BYREF
  idMat3 v97; // [sp+160h] [-140h] BYREF
  idMat3 v98[5]; // [sp+190h] [-110h] BYREF

  animStack = (const idDeclReachIK *)parms[1].animStack;
  this->decl = animStack;
  treeAnimator = parms->animStack->treeAnimator;
  this->animator = treeAnimator;
  this->entityNum = parms[1].name.len;
  this->clip = (idClip *)parms[1].name.data;
  if ( treeAnimator == nullptr )
    return 0;
  num = animStack->armInfo.num;
  if ( num >= 2 )
    num = 2;
  this->numArms = num;
  if ( num == 0 )
    return 1;
  Alias = idDeclMD6::FindAlias(this: treeAnimator->decl, aliasName: "misc/af_pose", includeInherited: true);
  v7 = 0;
  if ( Alias != nullptr )
  {
    v9 = (const idMD6Anim *)idResourceList::Load(
                              this: &idMD6Anim::resourceList,
                              name: (char *)Alias->animRefs.list->str,
                              makeDefault: true,
                              skipStaleCheck: false);
  }
  else
  {
    skeleton = this->animator->decl->model->skeleton;
    v9 = skeleton != nullptr ? skeleton->defaultAnim : nullptr;
  }
  idTreeAnimator::NumJoints(this: this->animator);
  ((void (*)(void))RtlCheckStack12)();
  animator = this->animator;
  *(_DWORD *)((char *)back_chain + v11) = back_chain[0];
  decl = animator->decl;
  v13 = idTreeAnimator::GetRemoveOriginTranslation(ptr: animator);
  VisualOffset = idTreeAnimator::GetVisualOffset(this: this->animator);
  if ( !idDeclMD6::GetJointsForAnimTime(
          this: decl,
          joints: &v87,
          anim: v9,
          timeMS: 0,
          offset: VisualOffset,
          removeOriginOffset: v13) )
    return 0;
  numArms = this->numArms;
  v16 = 0;
  this->enabledArms = 0;
  if ( numArms <= 0 )
  {
LABEL_17:
    if ( this->numArms > 0 )
    {
      v23 = &this->upperArmLength[1];
      v24 = &this->elbowJoints[1];
      p_z = &this->shoulderForward[1].z;
      v26 = &this->upperArmToShoulderJoint[1].mat[2].z;
      v27 = 0.0;
      v87.mat[0] = 0.0;
      v90.x = -1.0;
      v90.y = 0.0;
      v90.z = 0.0;
      do
      {
        value = v24[-3].value;
        v29 = v24[-1].value;
        ++v24;
        v30 = &v87 + v24->value;
        v32 = &v87 + value;
        v31 = &v87 + v29;
        v33 = v30->mat[10];
        v34 = v30->mat[6];
        v35 = v30->mat[9];
        v36 = v30->mat[5];
        v37 = v30->mat[8];
        v38 = v30->mat[4];
        v39 = v30->mat[2];
        v40 = v30->mat[1];
        v41 = v30->mat[0];
        v42 = v31->mat[5];
        v43 = v31->mat[8];
        v44 = (float)(v31->mat[5] + v31->mat[9]);
        v45 = v31->mat[4];
        v46 = (float)((float)((float)(v30->mat[6] + v30->mat[10]) * (float)v27) - v30->mat[2]);
        v47 = v31->mat[10];
        v48 = (float)(v31->mat[4] + v31->mat[8]);
        v49 = v31->mat[6];
        v50 = (float)((float)((float)(v30->mat[5] + v30->mat[9]) * (float)v27) - v30->mat[1]);
        v51 = v31->mat[1];
        v52 = (float)((float)((float)(v30->mat[4] + v30->mat[8]) * (float)v27) - v30->mat[0]);
        v53 = v31->mat[0];
        v54 = v31->mat[2];
        v55 = v32->mat[3];
        v56 = v32->mat[7];
        v57 = v32->mat[11];
        v58 = v31->mat[3];
        v59 = v31->mat[7];
        v60 = v31->mat[11];
        v61 = v30->mat[3];
        v62 = v30->mat[7];
        v63 = v30->mat[11];
        v95.mat[1].z = v31->mat[9];
        v97.mat[0].y = v38;
        v97.mat[0].z = v37;
        v97.mat[0].x = v41;
        v95.mat[0].z = v43;
        v95.mat[0].y = v45;
        v92.x = v55;
        v95.mat[0].x = v53;
        v92.y = v56;
        v95.mat[1].x = v51;
        v92.z = v57;
        v95.mat[1].y = v42;
        v91.x = v58;
        v95.mat[2].x = v54;
        v91.y = v59;
        v95.mat[2].y = v49;
        v91.z = v60;
        v95.mat[2].z = v47;
        v93.x = v61;
        v97.mat[1].x = v40;
        v93.y = v62;
        v97.mat[1].y = v36;
        v93.z = v63;
        v97.mat[1].z = v35;
        v97.mat[2].x = v39;
        v97.mat[2].y = v34;
        v97.mat[2].z = v33;
        v27 = v87.mat[0];
        *(p_z - 3) = v46;
        *(p_z - 4) = v50;
        *(p_z - 5) = v52;
        p_z[1] = (float)((float)v48 * (float)v27) - (float)v53;
        p_z[2] = (float)((float)v44 * (float)v27) - (float)v51;
        p_z += 3;
        *p_z = (float)((float)((float)v49 + (float)v47) * (float)v27) - (float)v54;
        BoneAxis = idAnimator_IK::GetBoneAxis(
                     this,
                     startPos: &v93,
                     endPos: &v91,
                     dir: &v90,
                     axis: (idMat3 *)&v87.mat[4]);
        v65 = v87.mat[4];
        v66 = v87.mat[7];
        v67 = v87.mat[10];
        v68 = v87.mat[5];
        v69 = v87.mat[8];
        v70 = v87.mat[11];
        v71 = v87.mat[6];
        v72 = v87.mat[9];
        v73 = v88;
        *(v23 - 1) = BoneAxis;
        v94.mat[0].x = v65;
        v94.mat[0].y = v66;
        v94.mat[0].z = v67;
        v94.mat[1].x = v68;
        v94.mat[1].y = v69;
        v94.mat[1].z = v70;
        v94.mat[2].x = v71;
        v94.mat[2].y = v72;
        v94.mat[2].z = v73;
        *(idMat3 *)(v26 - 17) = *idMat3::operator*(this: v98, result: &v97, a: &v94);
        v74 = idAnimator_IK::GetBoneAxis(this, startPos: &v91, endPos: &v92, dir: &v90, axis: (idMat3 *)&v87.mat[4]);
        v75 = v87.mat[4];
        v76 = v87.mat[7];
        v77 = v87.mat[10];
        v78 = v87.mat[5];
        v79 = v87.mat[8];
        v80 = v87.mat[11];
        v81 = v87.mat[6];
        v82 = v87.mat[9];
        v83 = v88;
        *++v23 = v74;
        v96.mat[0].x = v75;
        v96.mat[0].y = v76;
        v96.mat[0].z = v77;
        v96.mat[1].x = v78;
        v96.mat[1].y = v79;
        v96.mat[1].z = v80;
        v96.mat[2].x = v81;
        v96.mat[2].y = v82;
        v96.mat[2].z = v83;
        v84 = (idVec3 *)idMat3::operator*(this: v98, result: &v95, a: &v96);
        *(idVec3 *)(v26 + 1) = *v84;
        ++v7;
        *(idVec3 *)(v26 + 4) = v84[1];
        v26[7] = v84[2].x;
        v26[8] = v84[2].y;
        v26 += 9;
        *v26 = v84[2].z;
      }
      while ( v7 < this->numArms );
    }
    this->ikInitialized = true;
    return 1;
  }
  v17 = 0;
  elbowJoints = this->elbowJoints;
  while ( 1 )
  {
    v19 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v89,
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->armInfo.list[v17].hand.data)->value;
    elbowJoints[-2].value = v19;
    if ( v19 == 0xFFFF )
    {
      idLib::Warning(fmt: "idAnimator_ReachIK::Init: invalid hand joint '%s'", this->decl->armInfo.list[v16].hand.data);
      return 0;
    }
    v20 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)((char *)&v89 + 2),
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->armInfo.list[v17].elbow.data)->value;
    elbowJoints->value = v20;
    if ( v20 == 0xFFFF )
    {
      idLib::Warning(
        fmt: "idAnimator_ReachIK::Init: invalid elbow joint '%s'",
        this->decl->armInfo.list[v16].elbow.data);
      return 0;
    }
    v21 = (unsigned __int16)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v87,
                              result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                              jointName: this->decl->armInfo.list[v17].shoulder.data)->value;
    elbowJoints[2].value = v21;
    if ( v21 == 0xFFFF )
      break;
    v22 = (1 << v16++) | this->enabledArms;
    this->enabledArms = v22;
    ++elbowJoints;
    ++v17;
    if ( v16 >= this->numArms )
      goto LABEL_17;
  }
  idLib::Warning(
    fmt: "idAnimator_ReachIK::Init: invalid shoulder joint '%s'",
    this->decl->armInfo.list[v16].shoulder.data);
  return 0;
}


// ========================================================================
// ?ModelToJointAxis@idAnimator_ReachIK@@AAA?AVidMat3@@W4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@ABV2@@Z
// EA  : 0x826E4790
// RVA : 0x006E4790
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

idAnimator_ReachIK *__fastcall idAnimator_ReachIK::ModelToJointAxis(
        idAnimator_ReachIK *this,
        idMat3 *result,
        animationPose_t pose,
        idIndex<short,enum invalidJointIndex_t> *joint,
        idMat3 *modelSpaceAxis)
{
  float x; // r3
  idAnimator_ReachIK *v8; // r10
  float *p_y; // r11
  int i; // ctr
  idMD6SkelData *v11; // r9
  const idMat3 *v12; // r3
  idAnimator_ReachIK_vtbl **v13; // r10
  idAnimator_ReachIK *v14; // r9
  int j; // ctr
  idVec3 v17; // [sp+50h] [-B0h] BYREF
  char v18; // [sp+5Ch] [-A4h] BYREF
  idMat3 v19; // [sp+60h] [-A0h] BYREF
  idMat3 v20; // [sp+90h] [-70h] BYREF
  idMat3 v21; // [sp+C0h] [-40h] BYREF

  x = result[1].mat[1].x;
  if ( x == 0.0 )
  {
    v8 = (idAnimator_ReachIK *)((char *)this - 4);
    p_y = &mat2_identity.mat[1].y;
    for ( i = 9; i != 0; --i )
    {
      ++p_y;
      v8 = (idAnimator_ReachIK *)((char *)v8 + 4);
      v8->__vftable = *(idAnimator_ReachIK_vtbl **)p_y;
    }
  }
  else
  {
    v11 = *(idMD6SkelData **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 2032) + 60) + 212) + 40);
    idTreeAnimator::GetModelSpaceJointTransform(
      this: (idTreeAnimator *)LODWORD(x),
      pose,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)((char *)&v11->size
                                                                           + 2 * (__int16)joint
                                                                           + v11->parentTblOffset),
      origin: &v17,
      axis: &v20);
    v12 = idMat3::Inverse(this: &v21, result: &v20);
    idMat3::operator*(this: &v19, result: modelSpaceAxis, a: v12);
    idMat3::OrthoNormalizeSelf(this: &v19);
    v13 = (idAnimator_ReachIK_vtbl **)&v18;
    v14 = (idAnimator_ReachIK *)((char *)this - 4);
    for ( j = 9; j != 0; --j )
    {
      ++v13;
      v14 = (idAnimator_ReachIK *)((char *)v14 + 4);
      v14->__vftable = *v13;
    }
  }
  return this;
}


// ========================================================================
// ?ModelToJointAxis@idAnimator_ReachIK@@AAA?AVidMat3@@W4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@ABV2@12@Z
// EA  : 0x826E4870
// RVA : 0x006E4870
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

idAnimator_ReachIK *__fastcall idAnimator_ReachIK::ModelToJointAxis(
        idAnimator_ReachIK *this,
        idMat3 *result,
        animationPose_t pose,
        idIndex<short,enum invalidJointIndex_t> *joint,
        idMat3 *modelSpaceAxis,
        idIndex<short,enum invalidJointIndex_t> *parentJoint,
        const idMat3 *parentModelAxis)
{
  float x; // r3
  idAnimator_ReachIK *v13; // r10
  float *p_y; // r11
  int i; // ctr
  idMD6SkelData *v17; // r9
  const idIndex<short,enum invalidJointIndex_t> *v18; // r26
  idMat3 *v19; // r3
  const idMat3 *v20; // r3
  idAnimator_ReachIK_vtbl **v21; // r10
  idAnimator_ReachIK *v22; // r9
  int j; // ctr
  idVec3 v24; // [sp+50h] [-D0h] BYREF
  idMat3 v25; // [sp+60h] [-C0h] BYREF
  char v26; // [sp+8Ch] [-94h] BYREF
  idMat3 v27; // [sp+90h] [-90h] BYREF
  idMat3 v28[2]; // [sp+C0h] [-60h] BYREF

  x = result[1].mat[1].x;
  if ( x == 0.0 )
  {
    v13 = (idAnimator_ReachIK *)((char *)this - 4);
    p_y = &mat2_identity.mat[1].y;
    for ( i = 9; i != 0; --i )
    {
      ++p_y;
      v13 = (idAnimator_ReachIK *)((char *)v13 + 4);
      v13->__vftable = *(idAnimator_ReachIK_vtbl **)p_y;
    }
    return this;
  }
  else
  {
    v17 = *(idMD6SkelData **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(x) + 2032) + 60) + 212) + 40);
    v18 = (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)((char *)&v17->size
                                                                               + 2 * (__int16)joint
                                                                               + v17->parentTblOffset);
    idTreeAnimator::GetModelSpaceJointTransform(
      this: (idTreeAnimator *)LODWORD(x),
      pose,
      jointIndex: parentJoint,
      origin: &v24,
      axis: &v25);
    v19 = idMat3::Inverse(this: v28, result: &v25);
    idMat3::operator*(this: &v27, result: v19, a: parentModelAxis);
    idTreeAnimator::GetModelSpaceJointTransform(
      this: (idTreeAnimator *)LODWORD(result[1].mat[1].x),
      pose,
      jointIndex: v18,
      origin: &v24,
      axis: &v25);
    idMat3::operator*=(this: &v25, a: &v27);
    idMat3::OrthoNormalizeSelf(this: &v25);
    v20 = idMat3::Inverse(this: v28, result: &v25);
    idMat3::operator*(this: &v27, result: modelSpaceAxis, a: v20);
    idMat3::OrthoNormalizeSelf(this: &v27);
    v21 = (idAnimator_ReachIK_vtbl **)&v26;
    v22 = (idAnimator_ReachIK *)((char *)this - 4);
    for ( j = 9; j != 0; --j )
    {
      ++v21;
      v22 = (idAnimator_ReachIK *)((char *)v22 + 4);
      v22->__vftable = *v21;
    }
    return this;
  }
}


// ========================================================================
// ?Evaluate@idAnimator_WalkIK@@UAAXXZ
// EA  : 0x826E4BE0
// RVA : 0x006E4BE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::Evaluate(idAnimator_WalkIK *this)
{
  unsigned __int64 v1; // r21
  idClip *clip; // r28
  idTreeAnimator *animator; // r11
  idRenderModelParms *p_deferredOrigin; // r10
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  int *v9; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idClipQuery *p_modelQuery; // r29
  char IsValid; // r3
  double v14; // fp19
  char v15; // r15
  double v16; // fp21
  int v17; // r24
  unsigned __int64 index; // r11
  __int16 surfaceFlags; // r11
  idPhysics *PhysicsForId; // r3
  float *v21; // r3
  int physicsId; // r9
  int numLegs; // r10
  int v24; // r11
  double v25; // fp0
  float *p_oldWaistHeight; // r10
  double v27; // fp12
  idRenderWorld *v28; // r3
  double v29; // fp9
  double v30; // fp8
  int clipMask; // r10
  idClipModel *clipModel; // r8
  idClipQuery *v33; // r4
  idVec3 *p_upNormal; // r27
  unsigned __int64 v35; // r9
  idColor *v36; // r29
  idRenderWorld *v37; // r3
  idColor *v38; // r29
  idRenderWorld *v39; // r3
  int v40; // r25
  double v41; // fp31
  idIndex<short,enum invalidJointIndex_t> *footJoints; // r26
  unsigned int v43; // r29
  float *v44; // r11
  double x; // fp11
  double v46; // fp4
  double v47; // fp0
  double v48; // fp7
  double v49; // fp6
  double v50; // fp13
  double v51; // fp10
  double v52; // fp3
  double v53; // fp0
  double v54; // fp1
  double v55; // fp31
  double v56; // fp1
  float *v57; // r11
  double v58; // fp10
  double v59; // fp8
  double v60; // fp6
  double v61; // fp5
  float *v62; // r11
  int j; // ctr
  int v64; // r8
  float *v65; // r22
  idClipQuery *legQueries; // r24
  int *surfaceTypes; // r23
  int v68; // r25
  idClip *v69; // r29
  unsigned __int64 v70; // r11
  idClipQuery v71; // r9
  int surfaceType; // r9
  double v73; // fp12
  double v74; // fp8
  double v75; // fp0
  double v76; // fp9
  double v77; // fp2
  float *v78; // r11
  double v79; // fp13
  idCVar *v80; // r9
  double v81; // fp7
  double v82; // fp1
  double v83; // fp11
  int valueInteger; // r9
  double v85; // fp4
  double v86; // fp29
  double v87; // fp8
  double v88; // fp6
  double v89; // fp0
  double v90; // fp12
  double v91; // fp10
  double v92; // fp9
  idClipModel *footModel; // r11
  idTraceModel *trm; // r26
  unsigned int v95; // r28
  float *p_isConvex; // r29
  double v97; // fp0
  double v98; // fp13
  idRenderWorld *v99; // r3
  const idDeclWalkIK *decl; // r11
  double footDownTraceDead; // fp11
  float *v102; // r29
  float v103; // r9
  float v104; // r8
  double v105; // fp1
  double v106; // fp12
  double v107; // fp9
  double v110; // fp0
  double v111; // fp7
  double v112; // fp2
  double v113; // fp0
  double v116; // fp3
  double v117; // fp2
  double v118; // fp12
  double v119; // fp13
  double v120; // fp0
  double v121; // fp4
  double v122; // fp1
  double v123; // fp2
  double v124; // fp7
  double v125; // fp3
  idClipModel *v126; // r8
  idClipQuery *v127; // r4
  idRenderWorld *v128; // r3
  idRenderWorld *v129; // r3
  idRenderWorld *v130; // r3
  const idDeclWalkIK *v131; // r11
  double stairSmoothing; // fp29
  double stairWaistSmoothing; // fp20
  int v134; // r28
  double v135; // fp22
  double v136; // fp30
  double v137; // fp28
  idMat3 *v138; // r25
  float *v139; // r24
  float *v140; // r29
  float *v141; // r23
  idIndex<short,enum invalidJointIndex_t> *ankleJoints; // r26
  double v143; // fp31
  double v144; // fp0
  double v145; // fp11
  BOOL oldHeightsValid; // r11
  double v147; // fp2
  double v148; // fp13
  double v149; // fp10
  double v150; // fp9
  double v151; // fp1
  double v152; // fp8
  double v153; // fp27
  double v154; // fp12
  double v155; // fp7
  double v156; // fp6
  double v157; // fp5
  double v158; // fp4
  double v159; // fp3
  double v160; // fp0
  double v161; // fp0
  int v162; // r11
  double v163; // fp13
  double v164; // fp2
  double v165; // fp5
  double v166; // fp4
  _BYTE *v167; // r5
  const idDeclWalkIK *v168; // r29
  double v169; // fp26
  double v170; // fp27
  double v171; // fp28
  double minWaistFloorDist; // fp4
  double v173; // fp31
  double v174; // fp30
  double v175; // fp29
  double v176; // fp25
  double v177; // fp24
  double v178; // fp23
  idClip *v179; // r26
  idClipQuery *p_waistQuery; // r28
  unsigned __int64 v181; // r11
  idClipQuery v182; // r9
  double v183; // fp0
  idClipModel *v184; // r8
  double v185; // fp9
  double v186; // fp7
  idClipQuery *v187; // r4
  const idDeclWalkIK *v188; // r11
  double minWaistAnkleDist; // fp10
  double v190; // fp11
  BOOL v191; // r11
  double v192; // fp13
  double v193; // fp12
  float *v194; // r11
  double v195; // fp0
  int v196; // r10
  double v197; // fp13
  int v198; // r20
  double v199; // fp4
  double v200; // fp12
  double v201; // fp6
  double v202; // fp24
  double v203; // fp22
  double v204; // fp23
  idCVar *v205; // r26
  idClipQuery *footQueries; // r24
  unsigned __int64 v207; // r23
  idIndex<short,enum invalidJointIndex_t> *kneeJoints; // r21
  float *v209; // r28
  unsigned int v210; // r29
  unsigned int v211; // r25
  int v212; // r8
  __int64 v213; // r7
  const idDeclWalkIK *v214; // r11
  double v215; // fp4
  double v216; // fp2
  double v217; // fp0
  double v218; // fp7
  double v219; // fp11
  BOOL checkFeetForSolids; // r10
  double v221; // fp13
  double v222; // fp9
  double v223; // fp12
  double v224; // fp30
  double v225; // fp29
  double v226; // fp28
  double v227; // fp27
  double v228; // fp26
  double v229; // fp25
  unsigned __int64 v230; // r11
  unsigned int v231; // r11
  char v232; // r11
  bool v233; // zf
  unsigned __int64 v234; // r11
  idColor *v235; // r26
  idRenderWorld *v236; // r3
  double v237; // fp3
  double v238; // fp2
  _BYTE *v239; // r11
  float *v240; // r11
  const idDeclWalkIK *v241; // r10
  double v242; // fp0
  double v243; // fp7
  double v244; // fp1
  double v245; // fp2
  double v246; // fp5
  double v247; // fp4
  double v248; // fp20
  double v249; // fp18
  double v250; // fp17
  float *v251; // r3
  double v252; // fp2
  double v253; // fp1
  double v254; // fp0
  float *v255; // r11
  double v256; // fp13
  double v257; // fp12
  double v258; // fp11
  double v259; // fp10
  double v260; // fp9
  float *v261; // r3
  const idDeclWalkIK *v262; // r8
  double v263; // fp7
  double v264; // fp6
  double v265; // fp5
  double v266; // fp4
  double v267; // fp3
  BOOL v268; // r8
  double v269; // fp2
  double v270; // fp1
  double v271; // fp0
  double v272; // fp10
  double v273; // fp9
  double v274; // fp8
  idRenderWorld *v275; // r3
  idRenderWorld *v276; // r3
  idRenderWorld *v277; // r3
  idRenderWorld *v278; // r3
  idColor *v279; // r26
  idRenderWorld *v280; // r23
  __int64 v281; // r6
  __int64 v282; // r10
  __int64 v283; // r8
  va *v284; // r3
  __int16 value; // r7
  float *v286; // r10
  int v287; // r6
  idMD6Blend::jointMod_t *list; // r11
  idIndex<short,enum invalidJointIndex_t> *v289; // r7
  float *v290; // r11
  unsigned int v291; // r10
  __int16 v292; // r3
  double v293; // fp0
  double v294; // fp11
  double v295; // fp9
  double v296; // fp10
  double v297; // fp8
  double v298; // fp7
  double v299; // fp6
  double v300; // fp5
  double v301; // fp4
  double v302; // fp3
  double v303; // fp2
  double v304; // fp1
  double v305; // fp13
  double v306; // fp12
  double v307; // fp31
  double v308; // fp30
  double v309; // fp0
  idMD6Branch *mergeBranch; // r11
  int v311; // [sp+8h] [-2008h]
  int v312; // [sp+8h] [-2008h]
  int v313; // [sp+Ch] [-2004h]
  bool v314; // [sp+Fh] [-2001h]
  const char *v315; // [sp+10h] [-2000h]
  const char *v316; // [sp+10h] [-2000h]
  int v317; // [sp+14h] [-1FFCh]
  int v318; // [sp+18h] [-1FF8h]
  int v319; // [sp+1Ch] [-1FF4h]
  idVec3 v320; // [sp+70h] [-1FA0h] BYREF
  int v321; // [sp+7Ch] [-1F94h] BYREF
  idMat3 v322; // [sp+80h] [-1F90h] BYREF
  idCVar *v323; // [sp+A4h] [-1F6Ch]
  float v324; // [sp+A8h] [-1F68h] BYREF
  float v325; // [sp+ACh] [-1F64h]
  float v326; // [sp+B0h] [-1F60h]
  idVec3 v327; // [sp+B8h] [-1F58h] BYREF
  idColor *v328; // [sp+C4h] [-1F4Ch]
  idVec3 v329; // [sp+C8h] [-1F48h] BYREF
  idMat3 *v330; // [sp+D4h] [-1F3Ch]
  float v331; // [sp+D8h] [-1F38h]
  float *v332; // [sp+DCh] [-1F34h]
  float v333; // [sp+E0h] [-1F30h] BYREF
  float v334; // [sp+E4h] [-1F2Ch]
  float v335; // [sp+E8h] [-1F28h]
  float v336[2]; // [sp+F0h] [-1F20h] BYREF
  idColor *v337; // [sp+F8h] [-1F18h]
  float v338; // [sp+100h] [-1F10h] BYREF
  float v339; // [sp+104h] [-1F0Ch]
  float v340; // [sp+108h] [-1F08h]
  idVec3 v341; // [sp+110h] [-1F00h] BYREF
  idVec3 v342; // [sp+120h] [-1EF0h] BYREF
  idVec3 v343; // [sp+130h] [-1EE0h] BYREF
  float v344; // [sp+140h] [-1ED0h]
  float v345; // [sp+144h] [-1ECCh]
  float v346; // [sp+148h] [-1EC8h]
  float v347; // [sp+14Ch] [-1EC4h]
  idColor *v348; // [sp+150h] [-1EC0h]
  idColor *v349; // [sp+154h] [-1EBCh]
  idColor *v350; // [sp+158h] [-1EB8h]
  float v351; // [sp+15Ch] [-1EB4h]
  idVec3 v352; // [sp+160h] [-1EB0h] BYREF
  idVec3 v353; // [sp+170h] [-1EA0h] BYREF
  idVec3 v354; // [sp+180h] [-1E90h] BYREF
  idColor *v355; // [sp+190h] [-1E80h] BYREF
  idVec3 v356; // [sp+198h] [-1E78h] BYREF
  idMat3 v357; // [sp+1B0h] [-1E60h] BYREF
  idMat3 v358; // [sp+1E0h] [-1E30h] BYREF
  idVec3 v359; // [sp+208h] [-1E08h] BYREF
  float v360[4]; // [sp+218h] [-1DF8h] BYREF
  idVec3 v361; // [sp+228h] [-1DE8h] BYREF
  float v362[4]; // [sp+238h] [-1DD8h] BYREF
  float v363[4]; // [sp+248h] [-1DC8h] BYREF
  idVec3 v364; // [sp+258h] [-1DB8h] BYREF
  idVec3 v365; // [sp+268h] [-1DA8h] BYREF
  float v366[6]; // [sp+278h] [-1D98h] BYREF
  float v367[38]; // [sp+290h] [-1D80h] BYREF
  _BYTE v368[280]; // [sp+328h] [-1CE8h] BYREF
  trace_t v369; // [sp+440h] [-1BD0h] BYREF
  idMat3 v370; // [sp+4C0h] [-1B50h] BYREF
  trace_t v371; // [sp+4F0h] [-1B20h] BYREF
  trace_t v372; // [sp+570h] [-1AA0h] BYREF
  _BYTE v373[92]; // [sp+5F0h] [-1A20h] BYREF
  int v374; // [sp+64Ch] [-19C4h] BYREF
  _BYTE v375[96]; // [sp+650h] [-19C0h] BYREF
  _BYTE v376[288]; // [sp+6B0h] [-1960h] BYREF
  trace_t v377; // [sp+7D0h] [-1840h] BYREF
  idMat3 v378[9]; // [sp+850h] [-17C0h] BYREF
  idMat3 v379; // [sp+9A0h] [-1670h] BYREF
  idFixedWinding v380; // [sp+9D0h] [-1640h] BYREF
  va v381; // [sp+EE0h] [-1130h] BYREF

  if ( idAnimator_WalkIK::IsActive(this) )
  {
    clip = this->clip;
    if ( clip != nullptr && this->clipModel != nullptr && this->decl != nullptr )
    {
      animator = this->animator;
      if ( animator != nullptr )
      {
        p_deferredOrigin = (idRenderModelParms *)&animator->deferredOrigin;
        if ( !animator->useDeferredPosition )
          p_deferredOrigin = &animator->g;
        y = p_deferredOrigin->origin.y;
        z = p_deferredOrigin->origin.z;
        v320.x = p_deferredOrigin->origin.x;
        v320.y = y;
        v320.z = z;
        if ( animator->useDeferredPosition )
          p_deferredAxis = &animator->deferredAxis;
        else
          p_deferredAxis = &animator->g.axis;
        v9 = &v321;
        p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
        for ( i = 9; i != 0; --i )
          *++v9 = *++p_z;
        LODWORD(v1) = 0;
        p_modelQuery = &this->modelQuery;
        this->onGround = false;
        this->onStairs = false;
        IsValid = idClip::QueryIsValid(this: clip, clipQuery: &this->modelQuery);
        v14 = 1.0;
        v15 = 1;
        v16 = 0.0;
        v17 = -1;
        v347 = 0.0;
        v351 = 1.0;
        v323 = &ik_debug;
        if ( IsValid != 0 )
        {
          index = p_modelQuery->index;
          p_modelQuery->index = v1;
          LODWORD(v336[0]) = clip;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v372,
            query: &clip->collisionQueries[index & 0xFFF].query,
            peek: false);
          if ( v372.fraction < 1.0 )
          {
            surfaceFlags = v372.c.surfaceFlags;
            this->onGround = true;
            if ( (surfaceFlags & 0x400) != 0 )
              this->onStairs = true;
          }
          PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v372.c.physicsId);
          if ( v372.fraction < 1.0 && PhysicsForId != nullptr )
          {
            v21 = (float *)PhysicsForId->GetOrigin(this: PhysicsForId, a2: 0);
            physicsId = v372.c.physicsId;
            if ( v372.c.physicsId == this->oldGroundPhysicsId )
            {
              numLegs = this->numLegs;
              v24 = 0;
              v25 = (float)((float)((float)(*v21 - this->oldGroundPhysicsOrigin.x) * this->upNormal.x)
                          + (float)((float)(this->upNormal.y * (float)(v21[1] - this->oldGroundPhysicsOrigin.y))
                                  + (float)(this->upNormal.z * (float)(v21[2] - this->oldGroundPhysicsOrigin.z))));
              this->oldWaistHeight = this->oldWaistHeight
                                   + (float)((float)((float)(*v21 - this->oldGroundPhysicsOrigin.x) * this->upNormal.x)
                                           + (float)((float)(this->upNormal.y
                                                           * (float)(v21[1] - this->oldGroundPhysicsOrigin.y))
                                                   + (float)(this->upNormal.z
                                                           * (float)(v21[2] - this->oldGroundPhysicsOrigin.z))));
              if ( numLegs > 0 )
              {
                p_oldWaistHeight = &this->oldWaistHeight;
                do
                {
                  ++v24;
                  v27 = (float)(p_oldWaistHeight[1] + (float)v25);
                  *++p_oldWaistHeight = v27;
                }
                while ( v24 < this->numLegs );
              }
            }
            this->oldGroundPhysicsId = physicsId;
            this->oldGroundPhysicsOrigin.x = *v21;
            this->oldGroundPhysicsOrigin.y = v21[1];
            this->oldGroundPhysicsOrigin.z = v21[2];
          }
          else
          {
            this->oldGroundPhysicsId = -1;
            this->oldGroundPhysicsOrigin.z = 0.0;
            this->oldGroundPhysicsOrigin.y = 0.0;
            this->oldGroundPhysicsOrigin.x = 0.0;
          }
          if ( this->onGround && ik_debug.valueInteger != 0 )
          {
            v28 = common->RW(this: common);
            v28->DebugPoint(this: v28, a2: (const idVec4 *)&idColor::colorBlue, a3: &v372.endpos, a4: 0, a5: false);
          }
        }
        v29 = (float)(this->groundTraceDist * this->upNormal.z);
        v30 = (float)(this->groundTraceDist * this->upNormal.y);
        clipMask = this->clipMask;
        clipModel = this->clipModel;
        v33 = (idClipQuery *)this->clip;
        p_upNormal = &this->upNormal;
        v356.x = v320.x - (float)(this->groundTraceDist * this->upNormal.x);
        v356.z = v320.z - (float)v29;
        v356.y = v320.y - (float)v30;
        v330 = &mat3_identity;
        v35 = idClip::Translation(
                this: (idClip *)v336,
                result: v33,
                result: nullptr,
                start: &v320,
                end: &v356,
                clipModel,
                startAxis: &mat3_identity,
                clipMask,
                passEntityNumber: v311,
                moveClipModel: v314,
                userName: v315)->index;
        HIDWORD(v35) = this->onGround;
        v348 = &idColor::colorGreen;
        p_modelQuery->index = v35;
        v331 = COERCE_FLOAT(&idColor::colorOrange);
        if ( HIDWORD(v35) != 0 && ik_debug.valueInteger != 0 )
        {
          v36 = &idColor::colorOrange;
          if ( !this->onStairs )
            v36 = &idColor::colorGreen;
          v37 = common->RW(this: common);
          v37->DebugBounds(
            this: v37,
            a2: (const idVec4 *)v36,
            a3: &this->clipModel->bounds,
            a4: &v320,
            a5: 0,
            a6: false);
          v38 = &idColor::colorOrange;
          if ( !this->onStairs )
            v38 = &idColor::colorGreen;
          v39 = common->RW(this: common);
          v39->DebugPoint(this: v39, a2: (const idVec4 *)v38, a3: &v320, a4: 0, a5: false);
        }
        v40 = 0;
        v41 = 1.0e30;
        if ( this->numLegs > 0 )
        {
          footJoints = this->footJoints;
          v43 = 0;
          do
          {
            idTreeAnimator::GetModelSpaceJointTransform(
              this: this->animator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)footJoints->value,
              origin: (idVec3 *)&v373[v43],
              axis: &v370);
            v44 = (float *)&v373[v43 + 8];
            x = v320.x;
            v46 = p_upNormal->x;
            v47 = this->upNormal.z;
            v48 = (float)((float)(v322.mat[2].y * *v44)
                        + (float)((float)(v322.mat[1].y * *(v44 - 1)) + (float)(v322.mat[0].y * *(float *)&v373[v43])));
            v49 = v320.y;
            v50 = this->upNormal.y;
            v51 = (float)((float)(v322.mat[2].x * *v44)
                        + (float)((float)(v322.mat[0].x * *(float *)&v373[v43]) + (float)(v322.mat[1].x * *(v44 - 1))));
            v52 = (float)((float)((float)(v322.mat[2].z * *v44)
                                + (float)((float)(v322.mat[1].z * *(v44 - 1))
                                        + (float)(v322.mat[0].z * *(float *)&v373[v43])))
                        + v320.z);
            v367[v43 / 4 + 14] = (float)((float)(v322.mat[2].z * *(float *)&v373[v43 + 8])
                                       + (float)((float)(v322.mat[1].z * *(float *)&v373[v43 + 4])
                                               + (float)(v322.mat[0].z * *(float *)&v373[v43])))
                               + v320.z;
            v367[v43 / 4 + 13] = (float)v48 + (float)v49;
            v367[v43 / 4 + 12] = (float)v51 + (float)x;
            v53 = (float)((float)((float)((float)v48 + (float)v49) * (float)v50)
                        + (float)((float)((float)v52 * (float)v47) + (float)((float)v46 * (float)((float)v51 + (float)x))));
            if ( v53 < v41 )
            {
              v41 = v53;
              v17 = v40;
            }
            ++v40;
            ++footJoints;
            v43 += 12;
          }
          while ( v40 < this->numLegs );
        }
        if ( this->decl->usePivot )
        {
          v54 = idVec3::ToYaw(this: v322.mat);
          v55 = v54;
          if ( v17 != this->pivotFoot )
            goto LABEL_45;
          v56 = idMath::AngleNormalize360(angle: (float)((float)v54 - this->pivotYaw));
          if ( v56 > 180.0 )
            v56 = (float)((float)v56 - (float)360.0);
          if ( __fabs(v56) > 30.0 )
          {
LABEL_45:
            this->pivotYaw = v55;
            this->pivotFoot = v17;
            idTreeAnimator::GetModelSpaceJointTransform(
              this: this->animator,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->footJoints[v17].value,
              origin: &this->pivotPos,
              axis: &v370);
          }
          v57 = &v367[3 * this->pivotFoot + 12];
          v58 = v320.z;
          v59 = v320.y;
          v60 = (float)((float)(v322.mat[1].z * this->pivotPos.y)
                      + (float)((float)(v322.mat[0].z * this->pivotPos.x) + (float)(v322.mat[2].z * this->pivotPos.z)));
          v61 = (float)((float)(v322.mat[1].y * this->pivotPos.y)
                      + (float)((float)(v322.mat[0].y * this->pivotPos.x) + (float)(v322.mat[2].y * this->pivotPos.z)));
          *v57 = (float)((float)(v322.mat[1].x * this->pivotPos.y)
                       + (float)((float)(v322.mat[0].x * this->pivotPos.x) + (float)(v322.mat[2].x * this->pivotPos.z)))
               + v320.x;
          v57[2] = (float)v60 + (float)v58;
          v57[1] = (float)v61 + (float)v59;
        }
        v367[0] = 0.0;
        v62 = v367;
        for ( j = 7; j != 0; --j )
          *++v62 = 0.0;
        v64 = this->numLegs;
        v350 = &idColor::colorYellow;
        v337 = &idColor::colorPurple;
        v328 = &idColor::colorRed;
        if ( v64 > 0 )
        {
          v65 = v367;
          legQueries = this->legQueries;
          surfaceTypes = this->surfaceTypes;
          v68 = 0;
          do
          {
            if ( ((1 << v1) & this->enabledLegs) != 0 )
            {
              v69 = this->clip;
              if ( (unsigned __int8)idClip::QueryIsValid(this: v69, clipQuery: legQueries) != 0 )
              {
                LODWORD(v70) = 0;
                v71.index = legQueries->index;
                HIDWORD(v70) = &consoleFont[21088];
                LODWORD(v336[0]) = v69;
                legQueries->index = v70;
                idCollisionModelManager::GetContentsResult(
                  this: collisionModelManager,
                  result: &v369,
                  query: &v69->collisionQueries[v71.index & 0xFFF].query,
                  peek: false);
                surfaceType = v369.c.surfaceType;
                if ( v369.fraction >= 1.0 )
                  surfaceType = 0;
                v73 = v369.endpos.x;
                v74 = v320.x;
                *surfaceTypes = surfaceType;
                v75 = v369.endpos.z;
                v76 = (float)(v369.endpos.z - v320.z);
                v77 = this->upNormal.y;
                *(float *)&v373[v68 * 4] = (float)v73 - (float)v74;
                v78 = (float *)&v373[v68 * 4 + 4];
                v79 = v369.endpos.y;
                v80 = v323;
                v81 = (float)(v369.endpos.y - v320.y);
                v82 = v322.mat[0].z;
                v83 = v322.mat[1].x;
                *v78 = v369.endpos.y - v320.y;
                v78[1] = v76;
                valueInteger = v80->valueInteger;
                v85 = (float)((float)v73 - (float)v74);
                v86 = v322.mat[2].y;
                v87 = (float)((float)((float)v75 * this->upNormal.z) + (float)((float)v73 * this->upNormal.x));
                v88 = v322.mat[0].y;
                v89 = v322.mat[1].y;
                v90 = (float)((float)(v322.mat[0].x * (float)v85) + (float)((float)v82 * (float)v76));
                v91 = (float)((float)(v322.mat[1].z * (float)v76) + (float)((float)v83 * (float)v85));
                v92 = (float)((float)(v322.mat[2].z * (float)v76) + (float)(v322.mat[2].x * (float)v85));
                *v65 = (float)((float)v79 * (float)v77) + (float)v87;
                *(float *)&v373[v68 * 4] = (float)((float)v88 * (float)v81) + (float)v90;
                *v78 = (float)((float)v89 * (float)v81) + (float)v91;
                v78[1] = (float)((float)v86 * (float)v81) + (float)v92;
                if ( valueInteger != 0 )
                {
                  footModel = this->footModel;
                  if ( footModel != nullptr )
                  {
                    v380.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
                    trm = nullptr;
                    v380.allocedSize = 64;
                    v380.p = v380.data;
                    v380.numPoints = 0;
                    if ( footModel->traceModels.num > 0 )
                      trm = footModel->clip->traceModelCache->cache.list[*footModel->traceModels.list]->trm;
                    v95 = 0;
                    if ( trm->numVerts != 0 )
                    {
                      p_isConvex = (float *)&trm[-1].isConvex;
                      do
                      {
                        v97 = p_isConvex[65];
                        v98 = p_isConvex[33];
                        v327.x = *++p_isConvex;
                        v327.z = v97;
                        v327.y = v98;
                        idWinding::AddPoint(this: &v380, v: &v327);
                        ++v95;
                      }
                      while ( v95 < trm->numVerts );
                    }
                    v99 = common->RW(this: common);
                    v99->DebugWinding(
                      this: v99,
                      a2: (const idVec4 *)v328,
                      a3: &v380,
                      a4: &v369.endpos,
                      a5: &v369.endAxis,
                      a6: 0,
                      a7: false);
                    idFixedWinding::~idFixedWinding(this: &v380);
                  }
                }
              }
              else
              {
                v15 = 0;
                *surfaceTypes = 0;
              }
              decl = this->decl;
              if ( this->isDead )
                footDownTraceDead = decl->footDownTraceDead;
              else
                footDownTraceDead = decl->footDownTrace;
              v102 = &v367[v68 + 12];
              v103 = v367[v68 + 13];
              v104 = v367[v68 + 14];
              v324 = v367[v68 + 12];
              v325 = v103;
              v326 = v104;
              if ( decl->restrictToBounds || decl->checkFeetForSolids )
              {
                v105 = (float)((float)(v320.z - v367[v68 + 14])
                             - (float)((float)((float)((float)(v320.x - *v102) * this->upNormal.x)
                                             + (float)((float)((float)(v320.z - v367[v68 + 14]) * this->upNormal.z)
                                                     + (float)((float)(v320.y - v367[v68 + 13]) * this->upNormal.y)))
                                     * this->upNormal.z));
                v106 = (float)((float)(v320.x - *v102)
                             - (float)((float)((float)((float)(v320.x - *v102) * this->upNormal.x)
                                             + (float)((float)((float)(v320.z - v367[v68 + 14]) * this->upNormal.z)
                                                     + (float)((float)(v320.y - v367[v68 + 13]) * this->upNormal.y)))
                                     * this->upNormal.x));
                v107 = (float)((float)(v320.y - v367[v68 + 13])
                             - (float)((float)((float)((float)(v320.x - *v102) * this->upNormal.x)
                                             + (float)((float)((float)(v320.z - v367[v68 + 14]) * this->upNormal.z)
                                                     + (float)((float)(v320.y - v367[v68 + 13]) * this->upNormal.y)))
                                     * this->upNormal.y));
                _FP4 = (float)((float)((float)((float)v107 * (float)v107)
                                     + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                __asm { fsel      f2, f4, f5, f0 }
                v110 = __frsqrte(_FP2);
                v111 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                             * (float)v110)
                                                                                     - (float)1.5)
                                                                     * (float)v110)
                                                             * (float)((float)((float)((float)v107 * (float)v107)
                                                                             + (float)((float)((float)v106 * (float)v106)
                                                                                     + (float)((float)v105 * (float)v105)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v110
                                                                                             * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                     * (float)v110)
                                                                             - (float)1.5)
                                                             * (float)v110))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v110
                                                                     * (float)((float)((float)((float)v107 * (float)v107)
                                                                                     + (float)((float)((float)v106 * (float)v106)
                                                                                             + (float)((float)v105 * (float)v105)))
                                                                             * (float)0.5))
                                                             * (float)v110)
                                                     - (float)1.5)
                                     * (float)v110));
                v112 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110) * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110)
                                                                                             - (float)1.5)
                                                                             * (float)v110))
                                                             * (float)((float)((float)((float)v107 * (float)v107)
                                                                             + (float)((float)((float)v106 * (float)v106)
                                                                                     + (float)((float)v105 * (float)v105)))
                                                                     * (float)0.5))
                                                     * (float)v111)
                                             - (float)1.5)
                             * (float)v111);
                v113 = (float)((float)((float)((float)v107 * (float)v107)
                                     + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105)))
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110) * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110))
                                                                                             - (float)1.5)
                                                                             * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5)
                                                                                     * (float)v110))
                                                                     * (float)((float)((float)((float)v107 * (float)v107)
                                                                                     + (float)((float)((float)v106 * (float)v106)
                                                                                             + (float)((float)v105 * (float)v105)))
                                                                             * (float)0.5))
                                                             * (float)v111)
                                                     - (float)1.5)
                                     * (float)v111));
                _FP7 = (float)((float)v113
                             - (float)((float)(this->internalRadiusXY - decl->footSize) + decl->restrictToBoundsTolerance));
                __asm { fsel      f6, f7, f6, f0 }
                v116 = (float)((float)((float)((float)(v320.y - v367[v68 + 13])
                                             - (float)((float)((float)((float)(v320.x - *v102) * p_upNormal->x)
                                                             + (float)((float)((float)(v320.z - v367[v68 + 14])
                                                                             * p_upNormal->z)
                                                                     + (float)((float)(v320.y - v367[v68 + 13])
                                                                             * p_upNormal->y)))
                                                     * p_upNormal->y))
                                     * (float)v112)
                             * (float)((float)v113 - (float)_FP6));
                v118 = (float)((float)((float)((float)((float)(v320.x - *v102)
                                                     - (float)((float)((float)((float)(v320.x - *v102) * p_upNormal->x)
                                                                     + (float)((float)((float)(v320.z - v367[v68 + 14])
                                                                                     * p_upNormal->z)
                                                                             + (float)((float)(v320.y - v367[v68 + 13])
                                                                                     * p_upNormal->y)))
                                                             * p_upNormal->x))
                                             * (float)v112)
                                     * (float)((float)v113 - (float)_FP6))
                             + v324);
                v117 = (float)((float)((float)((float)(v320.z - v367[v68 + 14])
                                             - (float)((float)((float)((float)(v320.x - *v102) * p_upNormal->x)
                                                             + (float)((float)((float)(v320.z - v367[v68 + 14])
                                                                             * p_upNormal->z)
                                                                     + (float)((float)(v320.y - v367[v68 + 13])
                                                                             * p_upNormal->y)))
                                                     * p_upNormal->z))
                                     * (float)v112)
                             * (float)((float)v113 - (float)_FP6));
                v324 = v118;
                v119 = (float)(v325 + (float)v116);
                v325 = v325 + (float)v116;
                v120 = (float)(v326 + (float)v117);
                v326 = v326 + (float)v117;
              }
              else
              {
                v120 = v326;
                v119 = v325;
                v118 = v324;
              }
              v121 = (float)(this->upNormal.y * decl->footUpTrace);
              v122 = (float)(p_upNormal->x * decl->footUpTrace);
              v123 = (float)(this->upNormal.z * decl->footUpTrace);
              v124 = (float)(p_upNormal->x * (float)footDownTraceDead);
              v125 = (float)(this->upNormal.z * (float)footDownTraceDead);
              v126 = this->footModel;
              v127 = (idClipQuery *)this->clip;
              v353.y = (float)v119 - (float)(this->upNormal.y * (float)footDownTraceDead);
              v352.y = (float)v121 + (float)v119;
              v352.x = (float)v122 + (float)v118;
              v353.x = (float)v118 - (float)v124;
              v353.z = (float)v120 - (float)v125;
              v352.z = (float)v123 + (float)v120;
              legQueries->index = idClip::Translation(
                                    this: (idClip *)&v355,
                                    result: v127,
                                    result: nullptr,
                                    start: &v352,
                                    end: &v353,
                                    clipModel: v126,
                                    startAxis: v330,
                                    clipMask: 257,
                                    passEntityNumber: v312,
                                    moveClipModel: v313,
                                    userName: v316)->index;
              if ( v323->valueInteger != 0 )
              {
                v128 = common->RW(this: common);
                ((void (__fastcall *)(idRenderWorld *, double, idVec3 *, float *, _DWORD, _DWORD))v128->DebugLine)(
                  a1: v128,
                  a2: COERCE_DOUBLE(LODWORD(v331)),
                  a3: &v352,
                  a4: &v324,
                  a5: 0,
                  a6: 0);
                v129 = common->RW(this: common);
                v129->DebugLine(
                  this: v129,
                  a2: (const idVec4 *)v337,
                  a3: &v353,
                  a4: (const idVec3 *)&v324,
                  a5: 0,
                  a6: false);
                v130 = common->RW(this: common);
                v130->DebugLine(
                  this: v130,
                  a2: (const idVec4 *)&idColor::colorYellow,
                  a3: (const idVec3 *)&v367[v68 + 12],
                  a4: (const idVec3 *)&v324,
                  a5: 0,
                  a6: false);
              }
            }
            LODWORD(v1) = v1 + 1;
            ++legQueries;
            ++v65;
            ++surfaceTypes;
            v68 += 3;
          }
          while ( (int)v1 < this->numLegs );
        }
        if ( v15 != 0 )
        {
          v131 = this->decl;
          if ( this->onStairs )
            stairSmoothing = v131->stairSmoothing;
          else
            stairSmoothing = v131->smoothing;
          if ( this->onStairs )
            stairWaistSmoothing = v131->stairWaistSmoothing;
          else
            stairWaistSmoothing = v131->waistSmoothing;
          if ( ik_enableSmoothing.valueInteger == 0 )
          {
            stairSmoothing = 0.0;
            stairWaistSmoothing = 0.0;
          }
          v134 = 0;
          v135 = -1.0e30;
          v136 = 1.0e30;
          v137 = (float)((float)(this->upNormal.x * this->animator->g.origin.x)
                       + (float)((float)(this->animator->g.origin.y * this->upNormal.y)
                               + (float)(this->animator->g.origin.z * this->upNormal.z)));
          if ( this->numLegs > 0 )
          {
            v138 = (idMat3 *)v376;
            v139 = v367;
            v140 = (float *)&v374;
            v141 = &this->oldWaistHeight;
            ankleJoints = this->ankleJoints;
            do
            {
              if ( this->onGround && ((1 << v134) & this->enabledLegs) != 0 )
                v143 = (float)((float)(*v139 - (float)v137) + this->decl->footShift);
              else
                v143 = 0.0;
              if ( v143 < v136 )
                v136 = v143;
              idTreeAnimator::GetModelSpaceJointTransform(
                this: this->animator,
                pose: (animationPose_t)0,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)ankleJoints->value,
                origin: &v361,
                axis: v138);
              v144 = v361.z;
              v145 = v322.mat[2].x;
              oldHeightsValid = this->oldHeightsValid;
              v147 = (float)(v361.z * v322.mat[2].x);
              v148 = v361.y;
              v149 = v322.mat[1].z;
              v150 = v322.mat[1].y;
              v151 = (float)(v361.y * v322.mat[1].z);
              v152 = v322.mat[1].x;
              v153 = (float)(v361.y * v322.mat[1].y);
              v154 = v361.x;
              v155 = v322.mat[0].z;
              v156 = v322.mat[0].y;
              v157 = v322.mat[0].x;
              v140[2] = v361.y;
              v140[1] = v154;
              v158 = v322.mat[2].z;
              v159 = v322.mat[2].y;
              v140[3] = v144;
              v160 = (float)((float)((float)((float)((float)((float)v144 * (float)v159)
                                                   + (float)((float)((float)v156 * (float)v154) + (float)v153))
                                           + v320.y)
                                   * this->upNormal.y)
                           + (float)((float)((float)((float)((float)((float)v144 * (float)v158)
                                                           + (float)((float)((float)v155 * (float)v154) + (float)v151))
                                                   + v320.z)
                                           * this->upNormal.z)
                                   + (float)(this->upNormal.x
                                           * (float)(v320.x
                                                   + (float)((float)((float)v157 * (float)v154)
                                                           + (float)((float)((float)v148 * (float)v152) + (float)v147))))));
              if ( oldHeightsValid )
                v143 = (float)-(float)((float)((float)((float)((float)v160 + (float)v143) - v141[1])
                                             * (float)stairSmoothing)
                                     - (float)v143);
              v161 = (float)((float)v160 + (float)v143);
              if ( v161 > v135 )
                v135 = v161;
              *++v141 = v161;
              ++v134;
              v162 = this->numLegs;
              v163 = v140[1];
              ++ankleJoints;
              ++v139;
              v164 = v140[3];
              ++v138;
              v165 = (float)((float)((float)v157 * p_upNormal->x)
                           + (float)((float)((float)v155 * this->upNormal.z) + (float)((float)v156 * this->upNormal.y)));
              v166 = (float)((float)((float)v159 * this->upNormal.y)
                           + (float)((float)((float)v145 * this->upNormal.x) + (float)((float)v158 * this->upNormal.z)));
              v140[2] = (float)((float)((float)((float)v150 * this->upNormal.y)
                                      + (float)((float)((float)v152 * this->upNormal.x)
                                              + (float)((float)v149 * this->upNormal.z)))
                              * (float)v143)
                      + v140[2];
              v140[1] = (float)v163 + (float)((float)v143 * (float)v165);
              v140 += 3;
              *v140 = (float)((float)v166 * (float)v143) + (float)v164;
            }
            while ( v134 < v162 );
          }
          idTreeAnimator::GetModelSpaceJointTransform(
            this: this->animator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->waistJointHandle.value,
            origin: &v364,
            axis: v378);
          v168 = this->decl;
          v169 = p_upNormal->x;
          v170 = this->upNormal.y;
          v171 = this->upNormal.z;
          minWaistFloorDist = v168->minWaistFloorDist;
          v173 = (float)(p_upNormal->x * (float)(v168->waistShift + (float)v136));
          v175 = (float)(this->upNormal.z * (float)(v168->waistShift + (float)v136));
          v174 = (float)(this->upNormal.y * (float)(v168->waistShift + (float)v136));
          v176 = (float)(v320.x
                       + (float)((float)(v322.mat[0].x * v364.x)
                               + (float)((float)(v364.y * v322.mat[1].x) + (float)(v364.z * v322.mat[2].x))));
          v342.x = v320.x
                 + (float)((float)(v322.mat[0].x * v364.x)
                         + (float)((float)(v364.y * v322.mat[1].x) + (float)(v364.z * v322.mat[2].x)));
          v177 = (float)((float)((float)(v322.mat[0].y * v364.x)
                               + (float)((float)(v364.y * v322.mat[1].y) + (float)(v364.z * v322.mat[2].y)))
                       + v320.y);
          v342.y = (float)((float)(v322.mat[0].y * v364.x)
                         + (float)((float)(v364.y * v322.mat[1].y) + (float)(v364.z * v322.mat[2].y)))
                 + v320.y;
          v178 = (float)((float)((float)(v322.mat[0].z * v364.x)
                               + (float)((float)(v364.y * v322.mat[1].z) + (float)(v364.z * v322.mat[2].z)))
                       + v320.z);
          v342.z = (float)((float)(v322.mat[0].z * v364.x)
                         + (float)((float)(v364.y * v322.mat[1].z) + (float)(v364.z * v322.mat[2].z)))
                 + v320.z;
          if ( minWaistFloorDist > 0.0
            && (float)((float)((float)v169 * (float)v173)
                     + (float)((float)((float)v174 * (float)v170) + (float)((float)v175 * (float)v171))) < 0.0 )
          {
            v179 = this->clip;
            p_waistQuery = &this->waistQuery;
            if ( (unsigned __int8)idClip::QueryIsValid(this: v179, clipQuery: &this->waistQuery) != 0 )
            {
              LODWORD(v181) = 0;
              v182.index = p_waistQuery->index;
              HIDWORD(v181) = &consoleFont[21088];
              p_waistQuery->index = v181;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v377,
                query: &v179->collisionQueries[v182.index & 0xFFF].query,
                peek: false);
              v171 = this->upNormal.z;
              v168 = this->decl;
              v170 = this->upNormal.y;
              v169 = p_upNormal->x;
              if ( (float)((float)(this->upNormal.x * (float)((float)((float)v173 + (float)v176) - v377.endpos.x))
                         + (float)((float)((float)((float)((float)v174 + (float)v177) - v377.endpos.y) * this->upNormal.y)
                                 + (float)((float)((float)((float)v175 + (float)v178) - v377.endpos.z) * this->upNormal.z))) < (double)v168->minWaistFloorDist )
              {
                v183 = (float)(v168->minWaistFloorDist
                             - (float)((float)(this->upNormal.x
                                             * (float)((float)((float)v173 + (float)v176) - v377.endpos.x))
                                     + (float)((float)((float)((float)((float)v174 + (float)v177) - v377.endpos.y)
                                                     * this->upNormal.y)
                                             + (float)((float)((float)((float)v175 + (float)v178) - v377.endpos.z)
                                                     * this->upNormal.z))));
                v173 = (float)((float)(p_upNormal->x
                                     * (float)(v168->minWaistFloorDist
                                             - (float)((float)(p_upNormal->x
                                                             * (float)((float)((float)v173 + (float)v176) - v377.endpos.x))
                                                     + (float)((float)((float)((float)((float)v174 + (float)v177)
                                                                             - v377.endpos.y)
                                                                     * p_upNormal->y)
                                                             + (float)((float)((float)((float)v175 + (float)v178)
                                                                             - v377.endpos.z)
                                                                     * p_upNormal->z)))))
                             + (float)v173);
                v174 = (float)((float)(this->upNormal.y * (float)v183) + (float)v174);
                v175 = (float)((float)(this->upNormal.z * (float)v183) + (float)v175);
              }
            }
            v184 = this->footModel;
            v327 = v342;
            v185 = (float)(v168->footDownTrace + v168->footUpTrace);
            v186 = (float)((float)v171 * (float)(v168->footDownTrace + v168->footUpTrace));
            v187 = (idClipQuery *)this->clip;
            v359.x = (float)((float)v173 + (float)v176)
                   - (float)((float)v169 * (float)(v168->footDownTrace + v168->footUpTrace));
            v359.z = (float)((float)v175 + (float)v178) - (float)v186;
            v359.y = (float)((float)v174 + (float)v177) - (float)((float)v170 * (float)v185);
            p_waistQuery->index = idClip::Translation(
                                    this: (idClip *)v336,
                                    result: v187,
                                    result: nullptr,
                                    start: &v327,
                                    end: &v359,
                                    clipModel: v184,
                                    startAxis: &v322,
                                    clipMask: 257,
                                    passEntityNumber: v312,
                                    moveClipModel: v313,
                                    userName: v316)->index;
          }
          v188 = this->decl;
          minWaistAnkleDist = v188->minWaistAnkleDist;
          if ( minWaistAnkleDist > 0.0
            && (float)((float)((float)((float)((float)v174 + (float)v177) * this->upNormal.y)
                             + (float)((float)((float)((float)v175 + (float)v178) * this->upNormal.z)
                                     + (float)(this->upNormal.x * (float)((float)v173 + (float)v176))))
                     - (float)v135) < minWaistAnkleDist )
          {
            v190 = (float)(v188->minWaistAnkleDist
                         - (float)((float)((float)((float)((float)v174 + (float)v177) * this->upNormal.y)
                                         + (float)((float)((float)((float)v175 + (float)v178) * this->upNormal.z)
                                                 + (float)(this->upNormal.x * (float)((float)v173 + (float)v176))))
                                 - (float)v135));
            v173 = (float)((float)(p_upNormal->x
                                 * (float)(v188->minWaistAnkleDist
                                         - (float)((float)((float)((float)((float)v174 + (float)v177) * p_upNormal->y)
                                                         + (float)((float)((float)((float)v175 + (float)v178)
                                                                         * p_upNormal->z)
                                                                 + (float)(p_upNormal->x
                                                                         * (float)((float)v173 + (float)v176))))
                                                 - (float)v135)))
                         + (float)v173);
            v174 = (float)((float)(this->upNormal.y * (float)v190) + (float)v174);
            v175 = (float)((float)(this->upNormal.z * (float)v190) + (float)v175);
          }
          v191 = this->oldHeightsValid;
          if ( this->oldHeightsValid )
          {
            v192 = (float)(this->upNormal.y
                         * (float)((float)((float)((float)(this->upNormal.x * (float)((float)v173 + (float)v176))
                                                 + (float)((float)((float)((float)v175 + (float)v178) * this->upNormal.z)
                                                         + (float)((float)((float)v174 + (float)v177) * this->upNormal.y)))
                                         - this->oldWaistHeight)
                                 * (float)stairWaistSmoothing));
            v193 = (float)((float)((float)((float)((float)(this->upNormal.x * (float)((float)v173 + (float)v176))
                                                 + (float)((float)((float)((float)v175 + (float)v178) * this->upNormal.z)
                                                         + (float)((float)((float)v174 + (float)v177) * this->upNormal.y)))
                                         - this->oldWaistHeight)
                                 * (float)stairWaistSmoothing)
                         * this->upNormal.z);
            v173 = (float)((float)v173
                         - (float)(p_upNormal->x
                                 * (float)((float)((float)((float)(p_upNormal->x * (float)((float)v173 + (float)v176))
                                                         + (float)((float)((float)((float)v175 + (float)v178)
                                                                         * p_upNormal->z)
                                                                 + (float)((float)((float)v174 + (float)v177)
                                                                         * p_upNormal->y)))
                                                 - this->oldWaistHeight)
                                         * (float)stairWaistSmoothing)));
            v174 = (float)((float)v174 - (float)v192);
            v175 = (float)((float)v175 - (float)v193);
          }
          this->oldWaistHeight = (float)((float)((float)v174 + (float)v177) * this->upNormal.y)
                               + (float)((float)((float)((float)v175 + (float)v178) * this->upNormal.z)
                                       + (float)((float)((float)v173 + (float)v176) * this->upNormal.x));
          if ( v191 )
          {
            v194 = (float *)this->clipModel;
            v195 = this->upNormal.z;
            v196 = this->numLegs;
            v197 = this->upNormal.y;
            v198 = 0;
            v199 = v194[23];
            v200 = p_upNormal->x;
            v201 = (float)((float)(v194[24] * this->upNormal.y) + (float)(v194[25] * this->upNormal.z));
            v202 = (float)((float)(v322.mat[0].x * (float)v173)
                         + (float)((float)((float)v174 * v322.mat[0].y) + (float)((float)v175 * v322.mat[0].z)));
            v344 = (float)(v322.mat[0].x * (float)v173)
                 + (float)((float)((float)v174 * v322.mat[0].y) + (float)((float)v175 * v322.mat[0].z));
            v203 = (float)((float)(v322.mat[2].x * (float)v173)
                         + (float)((float)((float)v174 * v322.mat[2].y) + (float)((float)v175 * v322.mat[2].z)));
            v346 = (float)(v322.mat[2].x * (float)v173)
                 + (float)((float)((float)v174 * v322.mat[2].y) + (float)((float)v175 * v322.mat[2].z));
            v204 = (float)((float)(v322.mat[1].x * (float)v173)
                         + (float)((float)((float)v174 * v322.mat[1].y) + (float)((float)v175 * v322.mat[1].z)));
            v345 = (float)(v322.mat[1].x * (float)v173)
                 + (float)((float)((float)v174 * v322.mat[1].y) + (float)((float)v175 * v322.mat[1].z));
            v341.x = v320.x + (float)((float)v200 * (float)((float)((float)v199 * (float)v200) + (float)v201));
            v341.y = (float)((float)v197 * (float)((float)((float)v199 * (float)v200) + (float)v201)) + v320.y;
            v341.z = (float)((float)v195 * (float)((float)((float)v199 * (float)v200) + (float)v201)) + v320.z;
            if ( v196 > 0 )
            {
              v205 = v323;
              v336[0] = 0.2;
              v331 = 2.0;
              footQueries = this->footQueries;
              v355 = &idColor::colorWhite;
              HIDWORD(v207) = this->upperLegLength;
              v349 = &idColor::colorMagenta;
              kneeJoints = this->kneeJoints;
              v209 = &this->hipForward[0].z;
              v210 = 0;
              v211 = 0;
              do
              {
                idTreeAnimator::GetModelSpaceJointTransform(
                  this: this->animator,
                  pose: (animationPose_t)0,
                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)kneeJoints[8].value,
                  origin: &v329,
                  axis: &v358);
                idTreeAnimator::GetModelSpaceJointTransform(
                  this: this->animator,
                  pose: (animationPose_t)0,
                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)kneeJoints->value,
                  origin: &v343,
                  axis: &v357);
                v214 = this->decl;
                v215 = (float)(v358.mat[1].x * *(v209 - 1));
                v216 = (float)(v358.mat[1].y * *(v209 - 1));
                v217 = (float)(v358.mat[1].z * *(v209 - 1));
                v218 = v209[24];
                LODWORD(v207) = 0;
                v219 = (float)(v357.mat[2].x * v209[24]);
                v329.x = v329.x + (float)v202;
                v329.y = v329.y + (float)v204;
                v329.z = v329.z + (float)v203;
                checkFeetForSolids = v214->checkFeetForSolids;
                v221 = (float)((float)(v357.mat[0].y * v209[22]) + (float)(v357.mat[2].y * (float)v218));
                v222 = v209[23];
                v223 = (float)((float)(v357.mat[0].z * v209[22]) + (float)(v357.mat[2].z * (float)v218));
                v224 = (float)((float)(v358.mat[2].x * *v209)
                             + (float)((float)(*(v209 - 2) * v358.mat[0].x) + (float)v215));
                v225 = (float)((float)(v358.mat[2].y * *v209)
                             + (float)((float)(v358.mat[0].y * *(v209 - 2)) + (float)v216));
                v226 = (float)((float)(v358.mat[2].z * *v209)
                             + (float)((float)(v358.mat[0].z * *(v209 - 2)) + (float)v217));
                v227 = (float)((float)(v357.mat[1].x * v209[23])
                             + (float)((float)(v209[22] * v357.mat[0].x) + (float)v219));
                v365.x = (float)(v358.mat[2].x * *v209) + (float)((float)(*(v209 - 2) * v358.mat[0].x) + (float)v215);
                v365.y = v225;
                v365.z = v226;
                v228 = (float)((float)(v357.mat[1].y * (float)v222) + (float)v221);
                v354.x = v227;
                v229 = (float)((float)(v357.mat[1].z * (float)v222) + (float)v223);
                v354.y = (float)(v357.mat[1].y * (float)v222) + (float)v221;
                v354.z = (float)(v357.mat[1].z * (float)v222) + (float)v223;
                if ( checkFeetForSolids )
                {
                  v230 = footQueries->index;
                  v212 = 377208;
                  v213 = *(_QWORD *)(HIDWORD(footQueries->index) + 377208);
                  if ( LODWORD(footQueries->index) < (unsigned int)v213
                    || (v212 = 377216,
                        v213 = *(_QWORD *)(HIDWORD(v230) + 377216),
                        (unsigned int)v230 > (unsigned int)v213) )
                  {
                    v232 = 0;
                  }
                  else
                  {
                    v212 = HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset);
                    LODWORD(v213) = 0x40000;
                    v231 = *(_DWORD *)(8
                                     * (HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset)
                                      + ((2 * v230) & 0x1FFE))
                                     + HIDWORD(v230)
                                     + 278924);
                    if ( v231 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
                      || (v212 = HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset),
                          v233 = v231 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset,
                          v232 = 1,
                          !v233) )
                    {
                      v232 = 0;
                    }
                  }
                  if ( v232 != 0 )
                  {
                    v234 = footQueries->index;
                    footQueries->index = v207;
                    idCollisionModelManager::GetContentsResult(
                      this: collisionModelManager,
                      result: &v371,
                      query: (idCollisionQuery *)(8 * ((v234 & 0xFFF) + ((2 * v234) & 0x1FFE)) + HIDWORD(v234) + 278920),
                      peek: false);
                    if ( v371.fraction < v14
                      && (float)((float)((float)(v371.endpos.z * p_upNormal->z)
                                       + (float)((float)(p_upNormal->x * v371.endpos.x)
                                               + (float)(v371.endpos.y * p_upNormal->y)))
                               - (float)((float)(v367[v211 / 4 + 14] * p_upNormal->z)
                                       + (float)((float)(v367[v211 / 4 + 12] * p_upNormal->x)
                                               + (float)(v367[v211 / 4 + 13] * p_upNormal->y)))) > (double)v331
                      && (unsigned __int8)idBounds::ContainsPoint(this: &this->clipModel->absBounds, p: &v371.endpos) == 0 )
                    {
                      LOBYTE(v207) = 1;
                    }
                    if ( v205->valueInteger != 0 )
                    {
                      v235 = v349;
                      if ( (_BYTE)v207 == 0 )
                        v235 = v337;
                      v236 = common->RW(this: common);
                      v237 = (float)((float)(v367[v211 / 4 + 13] - v341.y) * v371.fraction);
                      v238 = (float)((float)(v367[v211 / 4 + 14] - v341.z) * v371.fraction);
                      v360[0] = (float)(v371.fraction * (float)(v367[v211 / 4 + 12] - v341.x)) + v341.x;
                      v360[1] = (float)v237 + v341.y;
                      v360[2] = (float)v238 + v341.z;
                      v236->DebugLine(
                        this: v236,
                        a2: (const idVec4 *)v235,
                        a3: &v341,
                        a4: (const idVec3 *)v360,
                        a5: 0,
                        a6: false);
                    }
                  }
                }
                if ( byte_83719EEC != 0 || (v239 = v375, (_BYTE)v207 != 0) )
                  v239 = v373;
                v240 = (float *)&v239[v211];
                v241 = this->decl;
                v242 = v240[1];
                v243 = v240[2];
                v244 = *(float *)HIDWORD(v207);
                v245 = *(float *)(HIDWORD(v207) + 32);
                v246 = (float)((float)((float)(v209[342] - v240[1])
                                     - (float)(p_upNormal->y
                                             * (float)((float)((float)(v209[343] - v240[2]) * p_upNormal->z)
                                                     + (float)((float)(p_upNormal->x * (float)(v209[341] - *v240))
                                                             + (float)((float)(v209[342] - v240[1]) * p_upNormal->y)))))
                             * v241->footSmoothing);
                v247 = (float)((float)((float)(v209[343] - v240[2])
                                     - (float)(p_upNormal->z
                                             * (float)((float)((float)(v209[343] - v240[2]) * p_upNormal->z)
                                                     + (float)((float)(p_upNormal->x * (float)(v209[341] - *v240))
                                                             + (float)((float)(v209[342] - v240[1]) * p_upNormal->y)))))
                             * v241->footSmoothing);
                v248 = (float)(*v240
                             + (float)(v241->footSmoothing
                                     * (float)((float)(v209[341] - *v240)
                                             - (float)(p_upNormal->x
                                                     * (float)((float)((float)(v209[343] - v240[2]) * p_upNormal->z)
                                                             + (float)((float)(p_upNormal->x * (float)(v209[341] - *v240))
                                                                     + (float)((float)(v209[342] - v240[1])
                                                                             * p_upNormal->y)))))));
                v249 = (float)((float)((float)((float)(v209[342] - v240[1])
                                             - (float)(p_upNormal->y
                                                     * (float)((float)((float)(v209[343] - v240[2]) * p_upNormal->z)
                                                             + (float)((float)(p_upNormal->x * (float)(v209[341] - *v240))
                                                                     + (float)((float)(v209[342] - v240[1])
                                                                             * p_upNormal->y)))))
                                     * v241->footSmoothing)
                             + v240[1]);
                v327.x = *v240
                       + (float)(v241->footSmoothing
                               * (float)((float)(v209[341] - *v240)
                                       - (float)(p_upNormal->x
                                               * (float)((float)((float)(v209[343] - v240[2]) * p_upNormal->z)
                                                       + (float)((float)(p_upNormal->x * (float)(v209[341] - *v240))
                                                               + (float)((float)(v209[342] - v240[1]) * p_upNormal->y))))));
                v327.y = (float)v246 + (float)v242;
                v250 = (float)((float)v247 + (float)v243);
                v327.z = (float)v247 + (float)v243;
                idAnimator_IK::SolveTwoBones(
                  this,
                  startPos: &v329,
                  endPos: &v327,
                  dir: &v354,
                  len0: v244,
                  len1: v245,
                  jointPos: (idVec3 *)v213,
                  a8: v212,
                  a9: &v343.x);
                idAnimator_IK::GetBoneAxis(this, startPos: &v329, endPos: &v343, dir: &v365, axis: &v358);
                idAnimator_IK::GetBoneAxis(this, startPos: &v343, endPos: &v327, dir: &v354, axis: &v357);
                v209[341] = v248;
                v209[342] = v249;
                v209[343] = v250;
                v251 = (float *)idMat3::operator*(
                                  this: (idMat3 *)v367,
                                  result: &this->upperLegToHipJoint[v210 / 9],
                                  a: &v358);
                v252 = v251[1];
                v253 = v251[2];
                v254 = v251[3];
                v255 = &v378[v210 / 9 + 1].mat[2].z;
                v256 = v251[4];
                v378[v210 / 9 + 1].mat[1].x = *v251;
                v378[v210 / 9 + 1].mat[1].y = v252;
                v378[v210 / 9 + 1].mat[1].z = v253;
                v332 = v251 + 3;
                v378[v210 / 9 + 1].mat[2].x = v254;
                v257 = v251[5];
                v258 = v251[6];
                *(v255 - 1) = v256;
                v259 = v251[7];
                v260 = v251[8];
                *v255 = v257;
                v378[v210 / 9 + 2].mat[0].x = v258;
                v255[2] = v259;
                v332 = v251 + 6;
                v255[3] = v260;
                v261 = (float *)idMat3::operator*(this: &v379, result: &this->lowerLegToKneeJoint[v210 / 9], a: &v357);
                v262 = this->decl;
                v263 = v261[1];
                v167 = v368;
                v264 = v261[2];
                v265 = v261[3];
                v367[v210 + 36] = *v261;
                v367[v210 + 37] = v263;
                *(float *)&v368[v210 * 4 + 4] = v265;
                v266 = v261[4];
                *(float *)&v368[v210 * 4] = v264;
                v267 = v261[5];
                v268 = v262->checkFeetForSolids;
                *(float *)&v368[v210 * 4 + 8] = v266;
                v269 = v261[6];
                *(float *)&v368[v210 * 4 + 12] = v267;
                v332 = v261 + 6;
                v270 = v261[7];
                *(float *)&v368[v210 * 4 + 16] = v269;
                v271 = v261[8];
                *(float *)&v368[v210 * 4 + 20] = v270;
                *(float *)&v368[v210 * 4 + 24] = v271;
                if ( v268 )
                  footQueries->index = idClip::Translation(
                                         this: (idClip *)&v342,
                                         result: (idClipQuery *)this->clip,
                                         result: nullptr,
                                         start: &v341,
                                         end: (const idVec3 *)&v367[v211 / 4 + 12],
                                         clipModel: nullptr,
                                         startAxis: v330,
                                         clipMask: 257,
                                         passEntityNumber: v312,
                                         moveClipModel: v313,
                                         userName: v316)->index;
                v205 = v323;
                if ( v323->valueInteger != 0 )
                {
                  v272 = (float)((float)(*(float *)&v375[v211 + 4] * v322.mat[1].x)
                               + (float)((float)(*(float *)&v375[v211] * v322.mat[0].x)
                                       + (float)(*(float *)&v375[v211 + 8] * v322.mat[2].x)));
                  v273 = (float)((float)(*(float *)&v375[v211 + 4] * v322.mat[1].y)
                               + (float)((float)(*(float *)&v375[v211] * v322.mat[0].y)
                                       + (float)(*(float *)&v375[v211 + 8] * v322.mat[2].y)));
                  v274 = (float)((float)(*(float *)&v375[v211 + 4] * v322.mat[1].z)
                               + (float)((float)(*(float *)&v375[v211] * v322.mat[0].z)
                                       + (float)(*(float *)&v375[v211 + 8] * v322.mat[2].z)));
                  v338 = v320.x
                       + (float)((float)(v329.z * v322.mat[2].x)
                               + (float)((float)(v322.mat[0].x * v329.x) + (float)(v329.y * v322.mat[1].x)));
                  v339 = (float)((float)(v322.mat[0].y * v329.x)
                               + (float)((float)(v329.y * v322.mat[1].y) + (float)(v329.z * v322.mat[2].y)))
                       + v320.y;
                  v340 = (float)((float)(v322.mat[0].z * v329.x)
                               + (float)((float)(v329.y * v322.mat[1].z) + (float)(v329.z * v322.mat[2].z)))
                       + v320.z;
                  v334 = (float)((float)(v343.z * v322.mat[2].y)
                               + (float)((float)(v322.mat[0].y * v343.x) + (float)(v343.y * v322.mat[1].y)))
                       + v320.y;
                  v333 = v320.x
                       + (float)((float)(v343.z * v322.mat[2].x)
                               + (float)((float)(v322.mat[0].x * v343.x) + (float)(v343.y * v322.mat[1].x)));
                  v335 = (float)((float)(v343.z * v322.mat[2].z)
                               + (float)((float)(v322.mat[0].z * v343.x) + (float)(v343.y * v322.mat[1].z)))
                       + v320.z;
                  v366[0] = v320.x + (float)v272;
                  v366[1] = (float)v273 + v320.y;
                  v366[2] = (float)v274 + v320.z;
                  v275 = common->RW(this: common);
                  v275->DebugLine(
                    this: v275,
                    a2: (const idVec4 *)&idColor::colorCyan,
                    a3: (const idVec3 *)&v338,
                    a4: (const idVec3 *)&v333,
                    a5: 0,
                    a6: false);
                  v276 = common->RW(this: common);
                  v276->DebugLine(
                    this: v276,
                    a2: (const idVec4 *)v328,
                    a3: (const idVec3 *)&v333,
                    a4: (const idVec3 *)v366,
                    a5: 0,
                    a6: false);
                  v277 = common->RW(this: common);
                  v362[0] = (float)((float)((float)((float)v226 * v322.mat[2].x)
                                          + (float)((float)(v322.mat[0].x * (float)v224)
                                                  + (float)((float)v225 * v322.mat[1].x)))
                                  * (float)16.0)
                          + v338;
                  v362[2] = (float)((float)((float)((float)v226 * v322.mat[2].z)
                                          + (float)((float)(v322.mat[0].z * (float)v224)
                                                  + (float)((float)v225 * v322.mat[1].z)))
                                  * (float)16.0)
                          + v340;
                  v362[1] = (float)((float)((float)((float)v226 * v322.mat[2].y)
                                          + (float)((float)(v322.mat[0].y * (float)v224)
                                                  + (float)((float)v225 * v322.mat[1].y)))
                                  * (float)16.0)
                          + v339;
                  v277->DebugLine(
                    this: v277,
                    a2: (const idVec4 *)v350,
                    a3: (const idVec3 *)&v338,
                    a4: (const idVec3 *)v362,
                    a5: 0,
                    a6: false);
                  v278 = common->RW(this: common);
                  v363[0] = (float)((float)((float)((float)v229 * v322.mat[2].x)
                                          + (float)((float)(v322.mat[0].x * (float)v227)
                                                  + (float)((float)v228 * v322.mat[1].x)))
                                  * (float)16.0)
                          + v333;
                  v363[1] = (float)((float)((float)((float)v229 * v322.mat[2].y)
                                          + (float)((float)(v322.mat[0].y * (float)v227)
                                                  + (float)((float)v228 * v322.mat[1].y)))
                                  * (float)16.0)
                          + v334;
                  v363[2] = (float)((float)((float)((float)v229 * v322.mat[2].z)
                                          + (float)((float)(v322.mat[0].z * (float)v227)
                                                  + (float)((float)v228 * v322.mat[1].z)))
                                  * (float)16.0)
                          + v335;
                  v278->DebugLine(
                    this: v278,
                    a2: (const idVec4 *)v348,
                    a3: (const idVec3 *)&v333,
                    a4: (const idVec3 *)v363,
                    a5: 0,
                    a6: false);
                  v279 = v328;
                  if ( (_BYTE)v207 == 0 )
                    v279 = v355;
                  v280 = common->RW(this: common);
                  HIDWORD(v281) = v198;
                  v284 = va::va(
                           this: &v381,
                           fmt: "%d",
                           a3: v281,
                           a4: v283,
                           a5: v282,
                           a6: v312,
                           a7: v313,
                           a8: (int)v316,
                           a9: v317,
                           a10: v318,
                           a11: v319);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v280->DebugText)(
                    a1: v280,
                    a2: v284,
                    a3: &v333,
                    a4: v280->DebugText,
                    a5: v279,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: v336[0]);
                  v16 = v347;
                  v205 = v323;
                  v14 = v351;
                  v203 = v346;
                  v204 = v345;
                  v202 = v344;
                }
                ++v198;
                ++kneeJoints;
                HIDWORD(v207) += 4;
                ++footQueries;
                v210 += 9;
                v209 += 3;
                v211 += 12;
              }
              while ( v198 < this->numLegs );
            }
            idMD6LeafPause::Init(
              this: &this->animLeaf,
              anim: nullptr,
              frame: v16,
              wrapMode: (const idMD6Leaf::wrapMode_t)v167,
              weightGroup: MD6_WEIGHTGROUP_ALL);
            idMD6LeafPause::SetNumAnimMods(this: &this->animLeaf, n: 3 * this->numLegs + 1);
            ++this->animLeaf.currentDeferred;
            idMD6LeafPause::SetUseStackTop(this: &this->animLeaf, set: true);
            idMD6LeafPause::SetClearNonModWeights(this: &this->animLeaf, set: true);
            value = this->waistJointHandle.value;
            v286 = (float *)v330;
            v287 = 0;
            list = this->animLeaf.animMods[this->animLeaf.currentDeferred & 1].list;
            list->flags = 8;
            list->joint.value = value;
            list->mat[0] = *v286;
            list->mat[1] = v286[3];
            list->mat[2] = v286[6];
            list->mat[3] = v202;
            list->mat[4] = v286[1];
            list->mat[5] = v286[4];
            list->mat[6] = v286[7];
            list->mat[7] = v204;
            list->mat[8] = v286[2];
            list->mat[9] = v286[5];
            list->mat[10] = v286[8];
            list->mat[11] = v203;
            list->s[0] = v16;
            list->s[1] = v16;
            list->s[2] = v16;
            if ( this->numLegs > 0 )
            {
              v289 = &this->footJoints[7];
              v290 = &list->s[2];
              v291 = 0;
              do
              {
                v292 = v289[17].value;
                v293 = v378[v291 / 0x24 + 1].mat[1].x;
                *((_WORD *)v290 + 35) = 35;
                v290[2] = v293;
                *((_WORD *)v290 + 34) = v292;
                v290[4] = v378[v291 / 0x24 + 2].mat[0].x;
                v290[3] = v378[v291 / 0x24 + 1].mat[2].x;
                v294 = v378[v291 / 0x24 + 1].mat[1].y;
                v295 = v378[v291 / 0x24 + 2].mat[0].y;
                v296 = v378[v291 / 0x24 + 1].mat[2].y;
                v297 = v378[v291 / 0x24 + 1].mat[1].z;
                v298 = v378[v291 / 0x24 + 1].mat[2].z;
                v299 = v378[v291 / 0x24 + 2].mat[0].z;
                v300 = v367[v291 / 4 + 36];
                v301 = *(float *)&v368[v291 + 4];
                v302 = *(float *)&v368[v291 + 16];
                v303 = v367[v291 / 4 + 37];
                v304 = *(float *)&v368[v291 + 8];
                v305 = *(float *)&v368[v291 + 20];
                v306 = *(float *)&v368[v291];
                v307 = *(float *)&v368[v291 + 12];
                v308 = *(float *)&v368[v291 + 24];
                v290[5] = vec3_origin.x;
                v290[6] = v294;
                v290[8] = v295;
                v290[7] = v296;
                v290[9] = vec3_origin.y;
                v290[10] = v297;
                v290[11] = v298;
                v290[12] = v299;
                v309 = vec3_origin.z;
                v290[16] = v16;
                v290[13] = v309;
                v290[14] = v16;
                v290[15] = v16;
                *((idIndex<short,enum invalidJointIndex_t> *)v290 + 66) = v289[9];
                v290[18] = v300;
                v290[19] = v301;
                *((_WORD *)v290 + 67) = 35;
                v290[20] = v302;
                v290[21] = vec3_origin.x;
                v290[22] = v303;
                v290[23] = v304;
                v290[24] = v305;
                v290[25] = vec3_origin.y;
                v290[26] = v306;
                v290[27] = v307;
                v290[28] = v308;
                v290[29] = vec3_origin.z;
                v290[30] = v16;
                v290[31] = v16;
                v290[32] = v16;
                ++v289;
                *((idIndex<short,enum invalidJointIndex_t> *)v290 + 98) = (idIndex<short,enum invalidJointIndex_t>)v289->value;
                *((_WORD *)v290 + 99) = 35;
                v290[34] = *(float *)&v376[v291];
                v290[35] = *(float *)&v376[v291 + 12];
                v290[36] = *(float *)&v376[v291 + 24];
                ++v287;
                v290[37] = vec3_origin.x;
                v290[38] = *(float *)&v376[v291 + 4];
                v290[39] = *(float *)&v376[v291 + 16];
                v290[40] = *(float *)&v376[v291 + 28];
                v290[41] = vec3_origin.y;
                v290[42] = *(float *)&v376[v291 + 8];
                v290[43] = *(float *)&v376[v291 + 20];
                v290[44] = *(float *)&v376[v291 + 32];
                v291 += 36;
                v290[45] = vec3_origin.z;
                v290[46] = v16;
                v290[47] = v16;
                v290 += 48;
                *v290 = v16;
              }
              while ( v287 < this->numLegs );
            }
            mergeBranch = this->mergeBranch;
            if ( mergeBranch != nullptr )
            {
              mergeBranch->left = nullptr;
              this->mergeBranch->right = &this->animLeaf;
              this->mergeBranch->filterGroup = 1;
            }
            this->ik_activate = true;
          }
          else
          {
            this->oldHeightsValid = true;
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$252352
// EA  : 0x826E6AD8
// RVA : 0x006E6AD8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_252352()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 8208 + 2512));
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_WalkIK@@UAAXAAVidSerializer@@@Z
// EA  : 0x826E6B08
// RVA : 0x006E6B08
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_WalkIK::SerializeSnapshot(idAnimator_WalkIK *this, idSerializer *ser)
{
  unsigned __int64 v3; // r28
  const idDeclWalkIK *decl; // r29
  idBitMsg *msg; // r3
  float *p_z; // r10
  int v8; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idClipModel *clipModel; // r3
  idClipModel *v11; // r3
  idClipModel *v12; // r7
  idAnimStack *animStack; // r10
  idClip *clip; // r6
  const idDeclWalkIK *v15; // r4
  int v16; // r25
  int v17; // r29
  int i; // r26
  idBitMsg *v19; // r3
  const char *v20; // [sp+8h] [-728h]
  int v21; // [sp+Ch] [-724h]
  int v22; // [sp+10h] [-720h]
  int v23; // [sp+14h] [-71Ch]
  int v24; // [sp+18h] [-718h]
  int v25; // [sp+1Ch] [-714h]
  int v26; // [sp+20h] [-710h]
  int v27; // [sp+24h] [-70Ch]
  int v28; // [sp+28h] [-708h]
  int v29; // [sp+2Ch] [-704h]
  int v30; // [sp+30h] [-700h]
  int v31; // [sp+34h] [-6FCh]
  int v32; // [sp+38h] [-6F8h]
  int v33; // [sp+3Ch] [-6F4h]
  int v34; // [sp+40h] [-6F0h]
  int v35; // [sp+44h] [-6ECh]
  int v36; // [sp+48h] [-6E8h]
  int v37; // [sp+4Ch] [-6E4h]
  int v38; // [sp+50h] [-6E0h]
  idBounds v39; // [sp+60h] [-6D0h] BYREF
  idClipModel *v40; // [sp+78h] [-6B8h]
  idAnimatorParms_WalkIK v41; // [sp+80h] [-6B0h] BYREF
  idTraceModel v42; // [sp+E0h] [-650h] BYREF

  HIDWORD(v3) = &this->decl;
  decl = this->decl;
  idSerializer::Serialize<idDeclWalkIK>(this: ser, decl: &this->decl);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->entityNum, numBits: 32);
  else
    this->entityNum = idBitMsg::ReadBits(this: msg, numBits: 32);
  LODWORD(v3) = 0;
  if ( decl != *(const idDeclWalkIK **)HIDWORD(v3) && !ser->writing )
  {
    memset(&v42.type, 0, 20);
    p_z = &v42.offset.z;
    v8 = 6;
    p_viewNoteMutex = &analysisClient.viewNoteMutex;
    v42.offset.x = 0.0;
    v42.offset.y = 0.0;
    v42.offset.z = 0.0;
    do
    {
      ++p_viewNoteMutex;
      *++p_z = *(float *)&p_viewNoteMutex->handle;
      --v8;
    }
    while ( v8 != 0 );
    v42.radius = 0.0;
    v39.b[0].z = 0.0;
    v42.isConvex = false;
    v42.pad[2] = 0;
    v42.pad[1] = 0;
    v42.pad[0] = 0;
    v39.b[0].x = -16.0;
    v39.b[0].y = -16.0;
    v39.b[1].x = 16.0;
    v39.b[1].y = 16.0;
    v39.b[1].z = 90.0;
    idTraceModel::SetupBox(this: &v42, boxBounds: &v39);
    clipModel = this->clipModel;
    if ( clipModel != nullptr )
      idClipModel::Delete(this: clipModel);
    v11 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v40 = v11;
    if ( v11 != nullptr )
      v12 = idClipModel::idClipModel(
              this: v11,
              clip: this->serializeProps.clip,
              trm: &v42,
              numTraceModels: 1,
              material: nullptr);
    else
      v12 = nullptr;
    animStack = this->serializeProps.animStack;
    clip = this->serializeProps.clip;
    v15 = *(const idDeclWalkIK **)HIDWORD(v3);
    this->clipModel = v12;
    this->createdClipModel = true;
    idAnimatorParms_WalkIK::idAnimatorParms_WalkIK(
      this: &v41,
      declWalkIK_: v15,
      entityNum_: -1,
      clip_: clip,
      clipModel_: v12,
      clipMask_: 257,
      upNormal_: &vec3_up,
      animStack_: animStack,
      alpha_: 1.0,
      name_: v20,
      a11: v21,
      a12: v22,
      a13: v23,
      a14: v24,
      a15: v25,
      a16: v26,
      a17: v27,
      a18: v28,
      a19: v29,
      a20: v30,
      a21: v31,
      a22: v32,
      a23: v33,
      a24: v34,
      a25: v35,
      a26: v36,
      a27: v37,
      a28: v38,
      a29: "walkIK");
    idAnimator_Base::Init(this, gametimeManager: this->gametimeManager.gameTimeManager, parms: &v41);
    idStr::FreeData(this: &v41.name);
  }
  v16 = 0;
  v17 = 1;
  for ( i = 0; i < this->numLegs; v17 *= 2 )
  {
    v19 = ser->msg;
    HIDWORD(v3) = (this->enabledLegs & v17) != 0;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v19, value: (this->enabledLegs & v17) != 0, numBits: 1);
    else
      HIDWORD(v3) = (_cntlzw(idBitMsg::ReadBits(this: v19, numBits: 1) - 1) & 0x20) != 0;
    ++i;
    v16 |= BYTE3(v3) == 0 ? 0 : v17;
  }
  if ( !ser->writing && this->enabledLegs != v16 )
  {
    this->oldHeightsValid = false;
    this->modelQuery.index = v3;
    this->waistQuery.index = v3;
    this->legQueries[0].index = v3;
    this->legQueries[1].index = v3;
    this->legQueries[2].index = v3;
    this->legQueries[3].index = v3;
    this->legQueries[4].index = v3;
    this->legQueries[5].index = v3;
    this->legQueries[6].index = v3;
    this->legQueries[7].index = v3;
  }
  this->enabledLegs = v16;
}


// ========================================================================
// __unwind$254728
// EA  : 0x826E6DAC
// RVA : 0x006E6DAC
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_254728()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1840 + 120), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$254729
// EA  : 0x826E6DD8
// RVA : 0x006E6DD8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_254729()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 1840 + 128));
}


// ========================================================================
// ?Evaluate@idAnimator_ReachIK@@UAAXXZ
// EA  : 0x826E6E00
// RVA : 0x006E6E00
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_ReachIK::Evaluate(idAnimator_ReachIK *this)
{
  idTreeAnimator *animator; // r11
  idRenderModelParms *p_deferredOrigin; // r10
  float y; // r8
  float z; // r7
  BOOL useDeferredPosition; // r6
  idMat3 *p_deferredAxis; // r11
  _DWORD *v8; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  int numArms; // r10
  char v12; // r29
  int v13; // r28
  float *v14; // r31
  idTreeAnimator *v15; // r11
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  idMat3 *v19; // r3
  float *v20; // r3
  idTreeAnimator *v21; // r11
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  BOOL v25; // r10
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v29; // fp4
  float *p_axis; // r10
  double v31; // fp3
  bool v32; // zf
  float *p_x; // r10
  double v34; // fp0
  double v35; // fp13
  double v36; // fp12
  const idMat3 *v37; // r5
  double v38; // fp7
  double v39; // fp6
  float *v40; // r3
  double v41; // fp2
  double v42; // fp13
  double v43; // fp12
  double v44; // fp0
  double v45; // fp13
  double v46; // fp10
  double v47; // fp9
  double v48; // fp8
  idRenderWorld *v49; // r3
  int v50; // r24
  double v51; // fp16
  double v52; // fp15
  double v53; // fp14
  double v54; // fp31
  double v55; // fp30
  double v56; // fp29
  double v57; // fp28
  float *upperArmLength; // r26
  double v59; // fp27
  idIndex<short,enum invalidJointIndex_t> *handJoints; // r28
  double v61; // fp26
  float *v62; // r25
  double v63; // fp25
  float *p_y; // r29
  double v65; // fp24
  unsigned int v66; // r31
  double v67; // fp23
  double v68; // fp5
  double v69; // fp2
  double v70; // fp3
  double v71; // fp1
  const idIndex<short,enum invalidJointIndex_t> *value; // r5
  idTreeAnimator *v73; // r3
  double v74; // fp6
  double v75; // fp13
  double v76; // fp4
  double v77; // fp3
  double v78; // fp22
  double v79; // fp0
  double v80; // fp12
  double v81; // fp10
  double v82; // fp9
  double v83; // fp5
  double v84; // fp1
  double v85; // fp0
  double v86; // fp13
  double v87; // fp22
  double v88; // fp21
  double v89; // fp20
  int v90; // r8
  double v91; // fp4
  double v92; // fp2
  double x; // fp0
  double v94; // fp13
  double v95; // fp12
  idClipQuery *clip; // r4
  double v97; // fp1
  double v98; // fp2
  double v99; // fp12
  double v100; // fp6
  double v101; // fp19
  double v102; // fp18
  double v103; // fp17
  idRenderWorld *v104; // r3
  idRenderWorld *v105; // r3
  idRenderWorld *v106; // r3
  idRenderWorld *v107; // r3
  const idMat3 *v108; // r3
  float *v109; // r3
  float *v110; // r11
  const idMat3 *v111; // r3
  float *v112; // r3
  int v113; // r7
  int v114; // r11
  int v115; // r26
  idMat3 *v116; // r28
  idIndex<short,enum invalidJointIndex_t> *elbowJoints; // r31
  int v118; // r29
  idAnimator_ReachIK *v119; // r3
  idAnimator_ReachIK *v120; // r3
  idAnimator_ReachIK *v121; // r3
  int v122; // r27
  idIndex<short,enum invalidJointIndex_t> *shoulderJoints; // r31
  idMat3 *v124; // r28
  int v125; // r29
  int v126; // [sp+8h] [-598h]
  bool v127; // [sp+Fh] [-591h]
  const char *v128; // [sp+10h] [-590h]
  _WORD v129[416]; // [sp+70h] [-530h] BYREF
  trace_t v130[2]; // [sp+3B0h] [-1F0h] BYREF

  animator = this->animator;
  if ( animator == nullptr || !this->enabled )
    return;
  p_deferredOrigin = (idRenderModelParms *)&animator->deferredOrigin;
  if ( !animator->useDeferredPosition )
    p_deferredOrigin = &animator->g;
  y = p_deferredOrigin->origin.y;
  z = p_deferredOrigin->origin.z;
  useDeferredPosition = animator->useDeferredPosition;
  *(float *)&v129[60] = p_deferredOrigin->origin.x;
  *(float *)&v129[62] = y;
  *(float *)&v129[64] = z;
  if ( useDeferredPosition )
    p_deferredAxis = &animator->deferredAxis;
  else
    p_deferredAxis = &animator->g.axis;
  v8 = &v129[70];
  p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
  for ( i = 9; i != 0; --i )
    *++v8 = *++p_z;
  numArms = this->numArms;
  v12 = 0;
  HIBYTE(v129[0]) = 0;
  v13 = 0;
  *(_DWORD *)&v129[90] = &ik_debug;
  if ( numArms > 0 )
  {
    v14 = &this->targetTransforms[0].axis.mat[1].z;
    do
    {
      if ( *((_BYTE *)v14 + 50) != 0 && *((unsigned __int16 *)v14 + 22) != 0xFFFF )
      {
        idDeclMD6::GetJointIndex(
          this: (idDeclMD6 *)v129,
          result: (idIndex<short,enum invalidJointIndex_t> *)this->animator->decl,
          handle: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v14 + 22);
        if ( v129[0] >= 0
          && idTreeAnimator::GetModelSpaceJointTransform(
               this: this->animator,
               pose: (animationPose_t)0,
               jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v129[0],
               origin: (idVec3 *)&v129[128],
               axis: (idMat3 *)&v129[136]) )
        {
          v15 = this->animator;
          v16 = (float)((float)((float)(*(float *)&v129[148] * (float)(v14[6] * v15->g.scale.z))
                              + (float)((float)(*(float *)&v129[136] * (float)(v14[4] * v15->g.scale.x))
                                      + (float)(*(float *)&v129[142] * (float)(v14[5] * v15->g.scale.y))))
                      + *(float *)&v129[128]);
          v17 = (float)(*(float *)&v129[130]
                      + (float)((float)((float)(v14[5] * v15->g.scale.y) * *(float *)&v129[144])
                              + (float)((float)(*(float *)&v129[138] * (float)(v14[4] * v15->g.scale.x))
                                      + (float)(*(float *)&v129[150] * (float)(v14[6] * v15->g.scale.z)))));
          v18 = (float)(*(float *)&v129[132]
                      + (float)((float)(*(float *)&v129[146] * (float)(v14[5] * v15->g.scale.y))
                              + (float)((float)(*(float *)&v129[140] * (float)(v14[4] * v15->g.scale.x))
                                      + (float)(*(float *)&v129[152] * (float)(v14[6] * v15->g.scale.z)))));
          v19 = idQuat::ToMat3(this: (idQuat *)&v129[224], result: (idMat3 *)(v14 + 7));
          v20 = (float *)idMat3::operator*(this: (idMat3 *)&v129[352], result: v19, a: (const idMat3 *)&v129[136]);
          v21 = this->animator;
          v22 = v20[1];
          v23 = v20[2];
          v24 = v20[3];
          v25 = v21->useDeferredPosition;
          v26 = v20[4];
          v27 = v20[5];
          v28 = v20[6];
          v29 = v20[7];
          v31 = v20[8];
          *(float *)&v129[32] = *v20;
          *(float *)&v129[34] = v22;
          *(float *)&v129[36] = v23;
          *(float *)&v129[38] = v24;
          *(float *)&v129[40] = v26;
          *(float *)&v129[42] = v27;
          *(float *)&v129[44] = v28;
          *(float *)&v129[46] = v29;
          *(float *)&v129[48] = v31;
          v32 = v25;
          p_axis = (float *)&v21->deferredAxis;
          if ( !v32 )
            p_axis = (float *)&v21->g.axis;
          v34 = (float)((float)(*p_axis * (float)v16)
                      + (float)((float)(p_axis[6] * (float)v18) + (float)(p_axis[3] * (float)v17)));
          v35 = (float)((float)(p_axis[1] * (float)v16)
                      + (float)((float)(p_axis[7] * (float)v18) + (float)(p_axis[4] * (float)v17)));
          v36 = (float)((float)(p_axis[2] * (float)v16)
                      + (float)((float)(p_axis[8] * (float)v18) + (float)(p_axis[5] * (float)v17)));
          p_x = &v21->deferredOrigin.x;
          if ( !v21->useDeferredPosition )
            p_x = &v21->g.origin.x;
          v37 = &v21->deferredAxis;
          v38 = (float)(p_x[1] + (float)v35);
          v39 = (float)(p_x[2] + (float)v36);
          *(float *)&v129[52] = (float)v34 + *p_x;
          *(float *)&v129[54] = v38;
          *(float *)&v129[56] = v39;
          if ( !v21->useDeferredPosition )
            v37 = &v21->g.axis;
          v40 = (float *)idMat3::operator*(this: (idMat3 *)&v129[352], result: (idMat3 *)&v129[32], a: v37);
          *(float *)&v129[160] = *v40;
          v12 = 1;
          *(float *)&v129[162] = v40[1];
          *(float *)&v129[164] = v40[2];
          *(float *)&v129[166] = v40[3];
          *(float *)&v129[168] = v40[4];
          *(float *)&v129[170] = v40[5];
          *(float *)&v129[172] = v40[6];
          *(float *)&v129[174] = v40[7];
          v41 = v40[8];
          v42 = *(float *)&v129[54];
          v43 = *(float *)&v129[56];
          *(v14 - 8) = *(float *)&v129[52];
          *(v14 - 7) = v42;
          *(v14 - 6) = v43;
          *((_BYTE *)v14 + 48) = 1;
          *((_BYTE *)v14 + 49) = 1;
          *(v14 - 5) = *(float *)&v129[32];
          v44 = *(float *)&v129[34];
          v45 = *(float *)&v129[36];
          *(v14 - 2) = *(float *)&v129[38];
          *(v14 - 4) = v44;
          *(v14 - 3) = v45;
          *(v14 - 1) = *(float *)&v129[40];
          v46 = *(float *)&v129[44];
          *v14 = *(float *)&v129[42];
          v47 = *(float *)&v129[46];
          v14[1] = v46;
          v48 = *(float *)&v129[48];
          v14[2] = v47;
          v14[3] = v48;
          *(float *)&v129[176] = v41;
          if ( ik_debug.valueInteger != 0 )
          {
            v49 = common->RW(this: common);
            v49->DebugAxis_2(this: v49, a2: (const idVec3 *)&v129[52], a3: (const idMat3 *)&v129[160], a4: 0, a5: false);
          }
        }
      }
      ++v13;
      v14 += 21;
    }
    while ( v13 < this->numArms );
    HIBYTE(v129[0]) = v12;
  }
  v50 = 0;
  if ( this->numArms > 0 )
  {
    v51 = *(float *)&v129[64];
    v52 = *(float *)&v129[62];
    v53 = *(float *)&v129[60];
    v54 = *(float *)&v129[88];
    v55 = *(float *)&v129[86];
    v56 = *(float *)&v129[84];
    v57 = *(float *)&v129[82];
    upperArmLength = this->upperArmLength;
    v59 = *(float *)&v129[80];
    handJoints = this->handJoints;
    v61 = *(float *)&v129[78];
    v62 = &this->targetTransforms[0].origin.z;
    v63 = *(float *)&v129[76];
    p_y = &this->shoulderForward[0].y;
    v65 = *(float *)&v129[74];
    v66 = 0;
    v67 = *(float *)&v129[72];
    *(_DWORD *)&v129[94] = &mat3_identity;
    while ( 1 )
    {
      idTreeAnimator::GetModelSpaceJointTransform(
        this: this->animator,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)handJoints[4].value,
        origin: (idVec3 *)&v129[20],
        axis: (idMat3 *)&v129[v66 / 2 + 312]);
      v68 = p_y[1];
      v69 = *p_y;
      v70 = (float)(*(float *)&v129[v66 / 2 + 326] * p_y[1]);
      v71 = *(p_y - 1);
      value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)handJoints->value;
      v73 = this->animator;
      *(_DWORD *)&v129[92] = &v129[322];
      v74 = *(float *)&v129[v66 / 2 + 320];
      v75 = (float)(*(float *)&v129[v66 / 2 + 328] * (float)v68);
      v76 = *(float *)&v129[v66 / 2 + 316];
      v77 = (float)((float)(*(float *)&v129[v66 / 2 + 314] * (float)v71) + (float)v70);
      v78 = *(float *)&v129[v66 / 2 + 322];
      v79 = (float)((float)((float)v56 * *(float *)&v129[24])
                  + (float)((float)((float)v67 * *(float *)&v129[20]) + (float)((float)v61 * *(float *)&v129[22])));
      v80 = *(float *)&v129[v66 / 2 + 312];
      v81 = (float)((float)(*(float *)&v129[v66 / 2 + 324] * (float)v68)
                  + (float)(*(float *)&v129[v66 / 2 + 318] * (float)v69));
      v82 = (float)((float)v51
                  + (float)((float)((float)v54 * *(float *)&v129[24])
                          + (float)((float)((float)v63 * *(float *)&v129[20]) + (float)((float)v57 * *(float *)&v129[22]))));
      *(float *)&v129[22] = (float)v52
                          + (float)((float)((float)v55 * *(float *)&v129[24])
                                  + (float)((float)((float)v65 * *(float *)&v129[20])
                                          + (float)((float)v59 * *(float *)&v129[22])));
      *(float *)&v129[24] = v82;
      *(float *)&v129[20] = (float)v79 + (float)v53;
      v83 = (float)((float)((float)v78 * (float)v69) + (float)((float)((float)v76 * (float)v71) + (float)v75));
      v85 = (float)((float)((float)v65 * (float)((float)((float)v80 * (float)v71) + (float)v81))
                  + (float)((float)((float)((float)v74 * (float)v69) + (float)v77) * (float)v59));
      v86 = (float)((float)((float)v63 * (float)((float)((float)v80 * (float)v71) + (float)v81))
                  + (float)((float)((float)((float)v74 * (float)v69) + (float)v77) * (float)v57));
      v84 = (float)((float)((float)((float)((float)v80 * (float)v71) + (float)v81) * (float)v67)
                  + (float)((float)((float)((float)v74 * (float)v69) + (float)v77) * (float)v61));
      v87 = (float)((float)((float)v83 * (float)v56) + (float)v84);
      *(float *)&v129[104] = (float)((float)v83 * (float)v56) + (float)v84;
      v88 = (float)((float)((float)v83 * (float)v55) + (float)v85);
      *(float *)&v129[106] = (float)((float)v83 * (float)v55) + (float)v85;
      v89 = (float)((float)((float)v83 * (float)v54) + (float)v86);
      *(float *)&v129[108] = (float)((float)v83 * (float)v54) + (float)v86;
      idTreeAnimator::GetModelSpaceJointTransform(
        this: v73,
        pose: (animationPose_t)0,
        jointIndex: value,
        origin: (idVec3 *)&v129[4],
        axis: (idMat3 *)((char *)&v130[1] + v66));
      v90 = *((unsigned __int8 *)v62 + 72);
      v91 = (float)((float)(*(float *)&v129[8] * (float)v54)
                  + (float)((float)((float)v63 * *(float *)&v129[4]) + (float)(*(float *)&v129[6] * (float)v57)));
      v92 = (float)((float)((float)(*(float *)&v129[8] * (float)v55)
                          + (float)((float)((float)v65 * *(float *)&v129[4]) + (float)(*(float *)&v129[6] * (float)v59)))
                  + (float)v52);
      *(float *)&v129[4] = (float)((float)(*(float *)&v129[8] * (float)v56)
                                 + (float)((float)(*(float *)&v129[4] * (float)v67)
                                         + (float)(*(float *)&v129[6] * (float)v61)))
                         + (float)v53;
      *(float *)&v129[6] = v92;
      *(float *)&v129[8] = (float)v91 + (float)v51;
      if ( v90 != 0 )
        break;
      clip = (idClipQuery *)this->clip;
      if ( clip != nullptr )
      {
        idClip::Translation(
          this: (idClip *)&v129[60],
          result: clip,
          result: v130,
          start: (const idVec3 *)&v129[20],
          end: (const idVec3 *)&v129[4],
          clipModel: nullptr,
          startAxis: *(const idMat3 **)&v129[94],
          clipMask: 1,
          passEntityNumber: v126,
          moveClipModel: v127,
          userName: v128);
        x = v130[0].endpos.x;
        v94 = v130[0].endpos.y;
        v95 = v130[0].endpos.z;
        goto LABEL_32;
      }
LABEL_33:
      idTreeAnimator::GetModelSpaceJointTransform(
        this: this->animator,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)handJoints[2].value,
        origin: (idVec3 *)&v129[12],
        axis: (idMat3 *)&v129[v66 / 2 + 272]);
      v97 = *upperArmLength;
      v98 = upperArmLength[2];
      v99 = (float)((float)(p_y[5] * *(float *)&v129[v66 / 2 + 272])
                  + (float)((float)(*(float *)&v129[v66 / 2 + 278] * p_y[6])
                          + (float)(*(float *)&v129[v66 / 2 + 284] * p_y[7])));
      v100 = (float)((float)((float)((float)(*(float *)&v129[v66 / 2 + 286] * p_y[7])
                                   + (float)((float)(*(float *)&v129[v66 / 2 + 274] * p_y[5])
                                           + (float)(*(float *)&v129[v66 / 2 + 280] * p_y[6])))
                           * (float)v57)
                   + (float)((float)((float)(*(float *)&v129[v66 / 2 + 288] * p_y[7])
                                   + (float)((float)(*(float *)&v129[v66 / 2 + 276] * p_y[5])
                                           + (float)(*(float *)&v129[v66 / 2 + 282] * p_y[6])))
                           * (float)v54));
      v101 = (float)((float)((float)((float)(*(float *)&v129[v66 / 2 + 288] * p_y[7])
                                   + (float)((float)(*(float *)&v129[v66 / 2 + 276] * p_y[5])
                                           + (float)(*(float *)&v129[v66 / 2 + 282] * p_y[6])))
                           * (float)v56)
                   + (float)((float)((float)((float)(p_y[5] * *(float *)&v129[v66 / 2 + 272])
                                           + (float)((float)(*(float *)&v129[v66 / 2 + 278] * p_y[6])
                                                   + (float)(*(float *)&v129[v66 / 2 + 284] * p_y[7])))
                                   * (float)v67)
                           + (float)((float)((float)(*(float *)&v129[v66 / 2 + 286] * p_y[7])
                                           + (float)((float)(*(float *)&v129[v66 / 2 + 274] * p_y[5])
                                                   + (float)(*(float *)&v129[v66 / 2 + 280] * p_y[6])))
                                   * (float)v61)));
      v102 = (float)((float)((float)v65
                           * (float)((float)(p_y[5] * *(float *)&v129[v66 / 2 + 272])
                                   + (float)((float)(*(float *)&v129[v66 / 2 + 278] * p_y[6])
                                           + (float)(*(float *)&v129[v66 / 2 + 284] * p_y[7]))))
                   + (float)((float)((float)((float)(*(float *)&v129[v66 / 2 + 286] * p_y[7])
                                           + (float)((float)(*(float *)&v129[v66 / 2 + 274] * p_y[5])
                                                   + (float)(*(float *)&v129[v66 / 2 + 280] * p_y[6])))
                                   * (float)v59)
                           + (float)((float)((float)(*(float *)&v129[v66 / 2 + 288] * p_y[7])
                                           + (float)((float)(*(float *)&v129[v66 / 2 + 276] * p_y[5])
                                                   + (float)(*(float *)&v129[v66 / 2 + 282] * p_y[6])))
                                   * (float)v55)));
      *(float *)&v129[96] = (float)((float)((float)(*(float *)&v129[v66 / 2 + 288] * p_y[7])
                                          + (float)((float)(*(float *)&v129[v66 / 2 + 276] * p_y[5])
                                                  + (float)(*(float *)&v129[v66 / 2 + 282] * p_y[6])))
                                  * (float)v56)
                          + (float)((float)((float)((float)(p_y[5] * *(float *)&v129[v66 / 2 + 272])
                                                  + (float)((float)(*(float *)&v129[v66 / 2 + 278] * p_y[6])
                                                          + (float)(*(float *)&v129[v66 / 2 + 284] * p_y[7])))
                                          * (float)v67)
                                  + (float)((float)((float)(*(float *)&v129[v66 / 2 + 286] * p_y[7])
                                                  + (float)((float)(*(float *)&v129[v66 / 2 + 274] * p_y[5])
                                                          + (float)(*(float *)&v129[v66 / 2 + 280] * p_y[6])))
                                          * (float)v61));
      *(float *)&v129[98] = v102;
      v103 = (float)((float)((float)v63 * (float)v99) + (float)v100);
      *(float *)&v129[100] = (float)((float)v63 * (float)v99) + (float)v100;
      idAnimator_IK::SolveTwoBones(
        this,
        startPos: (const idVec3 *)&v129[20],
        endPos: (const idVec3 *)&v129[4],
        dir: (const idVec3 *)&v129[96],
        len0: v97,
        len1: v98,
        jointPos: (idVec3 *)&v129[274],
        a8: (int)&v129[284],
        a9: (float *)&v129[12]);
      if ( *(_DWORD *)(*(_DWORD *)&v129[90] + 32) != 0 )
      {
        v104 = common->RW(this: common);
        v104->DebugLine(
          this: v104,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idVec3 *)&v129[20],
          a4: (const idVec3 *)&v129[12],
          a5: 0,
          a6: false);
        v105 = common->RW(this: common);
        v105->DebugLine(
          this: v105,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: (const idVec3 *)&v129[12],
          a4: (const idVec3 *)&v129[4],
          a5: 0,
          a6: false);
        v106 = common->RW(this: common);
        *(float *)&v129[120] = (float)v101 + *(float *)&v129[12];
        *(float *)&v129[122] = *(float *)&v129[14] + (float)v102;
        *(float *)&v129[124] = *(float *)&v129[16] + (float)v103;
        v106->DebugLine(
          this: v106,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: (const idVec3 *)&v129[12],
          a4: (const idVec3 *)&v129[120],
          a5: 0,
          a6: false);
        v107 = common->RW(this: common);
        *(float *)&v129[112] = *(float *)&v129[12] + (float)v87;
        *(float *)&v129[114] = *(float *)&v129[14] + (float)v88;
        *(float *)&v129[116] = *(float *)&v129[16] + (float)v89;
        v107->DebugLine(
          this: v107,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: (const idVec3 *)&v129[12],
          a4: (const idVec3 *)&v129[112],
          a5: 0,
          a6: false);
      }
      idAnimator_IK::GetBoneAxis(
        this,
        startPos: (const idVec3 *)&v129[20],
        endPos: (const idVec3 *)&v129[12],
        dir: (const idVec3 *)&v129[104],
        axis: (idMat3 *)&v129[224]);
      *(float *)&v129[72] = v67;
      *(float *)&v129[74] = v61;
      *(float *)&v129[76] = v56;
      *(float *)&v129[78] = v65;
      *(float *)&v129[80] = v59;
      *(float *)&v129[82] = v55;
      *(float *)&v129[84] = v63;
      *(float *)&v129[86] = v57;
      *(float *)&v129[88] = v54;
      v108 = idMat3::operator*(this: (idMat3 *)&v129[352], result: (idMat3 *)&v129[224], a: (const idMat3 *)&v129[72]);
      v109 = (float *)idMat3::operator*(
                        this: (idMat3 *)&v129[248],
                        result: &this->upperArmToShoulderJoint[v66 / 0x24],
                        a: v108);
      *(float *)&v129[v66 / 2 + 376] = *v109;
      v110 = (float *)&v129[v66 / 2 + 386];
      *(float *)&v129[v66 / 2 + 378] = v109[1];
      *(float *)&v129[v66 / 2 + 380] = v109[2];
      *(float *)&v129[v66 / 2 + 382] = v109[3];
      *(v110 - 1) = v109[4];
      *v110 = v109[5];
      *(float *)&v129[v66 / 2 + 388] = v109[6];
      v110[2] = v109[7];
      v110[3] = v109[8];
      idAnimator_IK::GetBoneAxis(
        this,
        startPos: (const idVec3 *)&v129[12],
        endPos: (const idVec3 *)&v129[4],
        dir: (const idVec3 *)&v129[96],
        axis: (idMat3 *)&v129[224]);
      *(float *)&v129[32] = v67;
      *(float *)&v129[34] = v61;
      *(float *)&v129[36] = v56;
      *(float *)&v129[38] = v65;
      *(float *)&v129[40] = v59;
      *(float *)&v129[42] = v55;
      *(float *)&v129[44] = v63;
      *(float *)&v129[46] = v57;
      *(float *)&v129[48] = v54;
      v111 = idMat3::operator*(this: (idMat3 *)&v129[248], result: (idMat3 *)&v129[224], a: (const idMat3 *)&v129[32]);
      v112 = (float *)idMat3::operator*(
                        this: (idMat3 *)&v129[352],
                        result: &this->lowerArmToElbowJoint[v66 / 0x24],
                        a: v111);
      *(float *)&v129[v66 / 2 + 184] = *v112;
      *(float *)&v129[v66 / 2 + 186] = v112[1];
      *(float *)&v129[v66 / 2 + 188] = v112[2];
      *(float *)&v129[v66 / 2 + 190] = v112[3];
      v113 = this->numArms;
      *(float *)&v129[v66 / 2 + 192] = v112[4];
      ++v50;
      ++handJoints;
      *(float *)&v129[v66 / 2 + 194] = v112[5];
      ++upperArmLength;
      v62 += 21;
      *(float *)&v129[v66 / 2 + 196] = v112[6];
      p_y += 3;
      *(float *)&v129[v66 / 2 + 198] = v112[7];
      *(float *)&v129[v66 / 2 + 200] = v112[8];
      v66 += 36;
      if ( v50 >= v113 )
      {
        v12 = HIBYTE(v129[0]);
        goto LABEL_37;
      }
    }
    x = *(v62 - 2);
    v94 = *(v62 - 1);
    v95 = *v62;
LABEL_32:
    *(float *)&v129[8] = v95;
    *(float *)&v129[6] = v94;
    *(float *)&v129[4] = x;
    goto LABEL_33;
  }
LABEL_37:
  v114 = this->numArms;
  if ( v12 == 0 )
  {
    v122 = 0;
    if ( v114 > 0 )
    {
      shoulderJoints = this->shoulderJoints;
      v124 = &this->targetTransforms[0].axis;
      v125 = 0;
      do
      {
        if ( BYTE1(v124[1].mat[2].z) != 0 )
          idTreeAnimator::SetJointAxis(
            this: this->animator,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)shoulderJoints[-4].value,
            type: JOINTMOD_MODEL_OVERRIDE,
            axis: v124);
        idTreeAnimator::SetJointAxis(
          this: this->animator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)shoulderJoints->value,
          type: JOINTMOD_MODEL_OVERRIDE,
          axis: (const idMat3 *)&v129[v125 + 376]);
        idTreeAnimator::SetJointAxis(
          this: this->animator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)shoulderJoints[-2].value,
          type: JOINTMOD_MODEL_OVERRIDE,
          axis: (const idMat3 *)&v129[v125 + 184]);
        ++v122;
        ++shoulderJoints;
        v124 = (idMat3 *)((char *)v124 + 84);
        v125 += 18;
      }
      while ( v122 < this->numArms );
    }
    goto LABEL_49;
  }
  v115 = 0;
  if ( v114 <= 0 )
  {
LABEL_49:
    this->ik_activate = true;
    return;
  }
  v116 = &this->targetTransforms[0].axis;
  elbowJoints = this->elbowJoints;
  v118 = 0;
  do
  {
    v119 = idAnimator_ReachIK::ModelToJointAxis(
             this: (idAnimator_ReachIK *)&v129[248],
             result: (idMat3 *)this,
             pose: (animationPose_t)0,
             joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints[2].value,
             modelSpaceAxis: (idMat3 *)&v129[v118 + 376]);
    idTreeAnimator::SetJointAxis(
      this: this->animator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints[2].value,
      type: JOINTMOD_LOCAL_OVERRIDE,
      axis: (const idMat3 *)v119);
    v120 = idAnimator_ReachIK::ModelToJointAxis(
             this: (idAnimator_ReachIK *)&v129[248],
             result: (idMat3 *)this,
             pose: (animationPose_t)0,
             joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints->value,
             modelSpaceAxis: (idMat3 *)&v129[v118 + 184],
             parentJoint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints[2].value,
             parentModelAxis: (const idMat3 *)&v129[v118 + 376]);
    idTreeAnimator::SetJointAxis(
      this: this->animator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints->value,
      type: JOINTMOD_LOCAL_OVERRIDE,
      axis: (const idMat3 *)v120);
    if ( BYTE1(v116[1].mat[2].z) != 0 )
    {
      v121 = idAnimator_ReachIK::ModelToJointAxis(
               this: (idAnimator_ReachIK *)&v129[248],
               result: (idMat3 *)this,
               pose: (animationPose_t)0,
               joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints[-2].value,
               modelSpaceAxis: v116,
               parentJoint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints->value,
               parentModelAxis: (const idMat3 *)&v129[v118 + 184]);
      idTreeAnimator::SetJointAxis(
        this: this->animator,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)elbowJoints[-2].value,
        type: JOINTMOD_LOCAL_OVERRIDE,
        axis: (const idMat3 *)v121);
    }
    ++v115;
    ++elbowJoints;
    v118 += 18;
    v116 = (idMat3 *)((char *)v116 + 84);
  }
  while ( v115 < this->numArms );
  this->ik_activate = true;
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_ReachIK@@UAAXAAVidSerializer@@@Z
// EA  : 0x826E79D8
// RVA : 0x006E79D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_ReachIK::SerializeSnapshot(idAnimator_ReachIK *this, idSerializer *ser)
{
  const idDeclReachIK *decl; // r28
  int v5; // r24
  const idDeclReachIK *v6; // r30
  idResource *animStack; // r11
  idClip *clip; // r28
  bool *p_validTag; // r28
  bool v10; // r30
  idBitMsg *msg; // r3
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  idBitMsg *v15; // r3
  unsigned __int16 value; // r11
  idTreeAnimator *animator; // r11
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r4
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  unsigned __int16 Bits; // r30
  idBitMsg *v22; // r3
  idIndex<short,enum invalidJointIndex_t> *v23; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v24; // r4
  __int16 v25; // [sp+50h] [-B0h] BYREF
  unsigned __int16 v26; // [sp+52h] [-AEh] BYREF
  idMD6Skel v27; // [sp+54h] [-ACh] BYREF
  int v28; // [sp+88h] [-78h]
  int v29; // [sp+8Ch] [-74h]
  int v30; // [sp+90h] [-70h]
  float v31; // [sp+94h] [-6Ch]
  const idDeclReachIK *v32; // [sp+98h] [-68h]
  int v33; // [sp+9Ch] [-64h]
  idClip *v34; // [sp+A0h] [-60h]

  decl = this->decl;
  idSerializer::Serialize<idDeclReachIK>(this: ser, decl: &this->decl);
  v5 = 2;
  v6 = this->decl;
  if ( decl != v6 )
  {
    animStack = (idResource *)this->serializeProps.animStack;
    clip = this->serializeProps.clip;
    v27.trackedMemory = (int)this->decl;
    v27.nextOnHashChain = animStack;
    idStr::idStr(this: (idStr *)&v27.resourceListPtr, text: "reachIK");
    v32 = v6;
    v34 = clip;
    *(_DWORD *)&v27.jointConversion.value = 2;
    v28 = 0;
    v29 = 0;
    v31 = 1.0;
    v30 = 0;
    v33 = -1;
    idAnimator_Base::Init(
      this,
      gametimeManager: this->gametimeManager.gameTimeManager,
      parms: (const idAnimatorParms_Base *)&v27.nextOnHashChain);
    idStr::FreeData(this: (idStr *)&v27.resourceListPtr);
  }
  p_validTag = &this->targetTransforms[0].validTag;
  do
  {
    v10 = *p_validTag;
    msg = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: msg, value: *p_validTag, numBits: 1);
    else
      v10 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
    *p_validTag = v10;
    if ( v10 )
    {
      idSerializer::Serialize(this: ser, value: (idVec3 *)(p_validTag - 34));
      v12 = ser->msg;
      if ( ser->writing )
      {
        v27.trackedMemory = *(int *)(p_validTag - 10);
        idBitMsg::WriteBits(this: v12, value: v27.trackedMemory, numBits: 32);
      }
      else
      {
        *(_DWORD *)(p_validTag - 10) = idBitMsg::ReadBits(this: v12, numBits: 32);
      }
      v13 = ser->msg;
      if ( ser->writing )
      {
        v27.trackedMemory = *(int *)(p_validTag - 22);
        idBitMsg::WriteBits(this: v13, value: v27.trackedMemory, numBits: 32);
      }
      else
      {
        *(_DWORD *)(p_validTag - 22) = idBitMsg::ReadBits(this: v13, numBits: 32);
      }
      v14 = ser->msg;
      if ( ser->writing )
      {
        v27.trackedMemory = *(int *)(p_validTag - 18);
        idBitMsg::WriteBits(this: v14, value: v27.trackedMemory, numBits: 32);
      }
      else
      {
        *(_DWORD *)(p_validTag - 18) = idBitMsg::ReadBits(this: v14, numBits: 32);
      }
      v15 = ser->msg;
      if ( ser->writing )
      {
        v27.trackedMemory = *(int *)(p_validTag - 14);
        idBitMsg::WriteBits(this: v15, value: v27.trackedMemory, numBits: 32);
      }
      else
      {
        *(_DWORD *)(p_validTag - 14) = idBitMsg::ReadBits(this: v15, numBits: 32);
      }
      value = -1;
      if ( ser->writing )
      {
        animator = this->animator;
        if ( animator != nullptr )
        {
          model = animator->decl->model;
          if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
          {
            v27.trackedMemory = (int)model->skeleton;
            JointIndex = idMD6Skel::GetJointIndex(
                           this: &v27,
                           result: skeleton,
                           handle: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)p_validTag - 3);
          }
          else
          {
            JointIndex = (idIndex<short,enum invalidJointIndex_t> *)&v25;
            v25 = -1;
          }
          value = JointIndex->value;
        }
        else
        {
          value = 0;
        }
      }
      if ( value == NULL_JOINT_INDEX.value )
        value = -1;
      Bits = value;
      v22 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v22, value, numBits: 16);
      else
        Bits = idBitMsg::ReadBits(this: v22, numBits: 16);
      if ( Bits == 0xFFFF )
      {
        v23 = &NULL_JOINT_INDEX;
      }
      else
      {
        v26 = Bits;
        v23 = (idIndex<short,enum invalidJointIndex_t> *)&v26;
      }
      if ( !ser->writing )
      {
        v24 = (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this->animator;
        if ( v24 != nullptr )
          *((idHandle<unsigned short,enum invalidJointHandle_t,65535> *)p_validTag - 3) = (idHandle<unsigned short,enum invalidJointHandle_t,65535>)idTreeAnimator::GetJointHandle(this: (idTreeAnimator *)((char *)&v27.__vftable + 2), result: v24, jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v23->value)->value;
        else
          *((_WORD *)p_validTag - 3) = 0;
      }
    }
    --v5;
    p_validTag += 84;
  }
  while ( v5 != 0 );
}


// ========================================================================
// __unwind$255785
// EA  : 0x826E7CB8
// RVA : 0x006E7CB8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_255785()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 256 + 96));
}


// ========================================================================
// ??0idAnimator_WalkIK@@QAA@XZ
// EA  : 0x826E7CE8
// RVA : 0x006E7CE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

idAnimator_WalkIK *__fastcall idAnimator_WalkIK::idAnimator_WalkIK(idAnimator_WalkIK *this)
{
  unsigned __int64 v2; // r28
  float *p_z; // r8
  int v4; // ctr
  idIndex<short,enum invalidJointIndex_t> *v5; // r9
  idVec3 *v6; // r11
  float *v7; // r10

  idAnimator_Base::idAnimator_Base(this);
  LODWORD(v2) = 0;
  this->ik_activate = false;
  this->enabled = true;
  this->ikInitialized = false;
  this->entityNum = 0x1FFF;
  this->animator = nullptr;
  this->clip = nullptr;
  this->__vftable = (idAnimator_WalkIK_vtbl *)&idAnimator_WalkIK::`vftable';
  HIDWORD(v2) = this->ankleJoints;
  this->footJoints[0].value = -1;
  this->footJoints[1].value = -1;
  this->footJoints[2].value = -1;
  this->footJoints[3].value = -1;
  this->footJoints[4].value = -1;
  this->footJoints[5].value = -1;
  this->footJoints[6].value = -1;
  this->footJoints[7].value = -1;
  this->ankleJoints[0].value = -1;
  this->ankleJoints[1].value = -1;
  this->ankleJoints[2].value = -1;
  this->ankleJoints[3].value = -1;
  this->ankleJoints[4].value = -1;
  this->ankleJoints[5].value = -1;
  this->ankleJoints[6].value = -1;
  this->ankleJoints[7].value = -1;
  this->kneeJoints[0].value = -1;
  this->kneeJoints[1].value = -1;
  this->kneeJoints[2].value = -1;
  this->kneeJoints[3].value = -1;
  this->kneeJoints[4].value = -1;
  this->kneeJoints[5].value = -1;
  this->kneeJoints[6].value = -1;
  this->kneeJoints[7].value = -1;
  this->hipJoints[0].value = -1;
  this->hipJoints[1].value = -1;
  this->hipJoints[2].value = -1;
  this->hipJoints[3].value = -1;
  this->hipJoints[4].value = -1;
  this->hipJoints[5].value = -1;
  this->hipJoints[6].value = -1;
  this->hipJoints[7].value = -1;
  this->dirJoints[0].value = -1;
  this->dirJoints[1].value = -1;
  this->dirJoints[2].value = -1;
  this->dirJoints[3].value = -1;
  this->dirJoints[4].value = -1;
  this->dirJoints[5].value = -1;
  this->dirJoints[6].value = -1;
  this->dirJoints[7].value = -1;
  this->waistJointHandle.value = -1;
  this->modelQuery.index = v2;
  this->waistQuery.index = v2;
  this->legQueries[0].index = v2;
  this->legQueries[1].index = v2;
  this->legQueries[2].index = v2;
  this->legQueries[3].index = v2;
  this->legQueries[4].index = v2;
  this->legQueries[5].index = v2;
  this->legQueries[6].index = v2;
  this->legQueries[7].index = v2;
  this->footQueries[0].index = v2;
  this->footQueries[1].index = v2;
  this->footQueries[2].index = v2;
  this->footQueries[3].index = v2;
  this->footQueries[4].index = v2;
  this->footQueries[5].index = v2;
  this->footQueries[6].index = v2;
  this->footQueries[7].index = v2;
  idMD6LeafPause::idMD6LeafPause(this: &this->animLeaf);
  this->decl = nullptr;
  this->clipModel = nullptr;
  this->clipMask = 1;
  p_z = &this->oldGroundPhysicsOrigin.z;
  this->upNormal.x = 0.0;
  v4 = 8;
  this->upNormal.y = 0.0;
  v5 = &this->hipJoints[7];
  this->upNormal.z = 1.0;
  v6 = &this->lowerLegToKneeJoint[7].mat[1];
  this->footModel = nullptr;
  v7 = (float *)&this->footQueries[7].index + 1;
  this->numLegs = 0;
  this->enabledLegs = 0;
  do
  {
    v5[-31].value = -1;
    v5[-23].value = -1;
    v5[-15].value = -1;
    v5[-7].value = -1;
    ++v5;
    v5->value = -1;
    *(v7 - 340) = 0.0;
    *(v7 - 341) = 0.0;
    *(v7 - 342) = 0.0;
    *(v7 - 316) = 0.0;
    *(v7 - 317) = 0.0;
    *(v7 - 318) = 0.0;
    *(p_z - 250) = 0.0;
    *(p_z - 242) = 0.0;
    v6[-44].z = 1.0;
    v6[-45].y = 1.0;
    v6[-46].x = 1.0;
    v6[-45].z = 0.0;
    v6[-46].z = 0.0;
    v6[-46].y = 0.0;
    v6[-44].y = 0.0;
    v6[-44].x = 0.0;
    v6[-45].x = 0.0;
    v6[-20].z = 1.0;
    v6[-21].y = 1.0;
    v6[-22].x = 1.0;
    v6[-21].z = 0.0;
    v6[-22].z = 0.0;
    v6[-22].y = 0.0;
    v6[-20].y = 0.0;
    v6[-20].x = 0.0;
    v6[-21].x = 0.0;
    v6[4].z = 1.0;
    v6[3].y = 1.0;
    v6[2].x = 1.0;
    v6[3].z = 0.0;
    v6[2].z = 0.0;
    v6[2].y = 0.0;
    v6[4].y = 0.0;
    v6[4].x = 0.0;
    v6 += 3;
    v6->x = 0.0;
    *(p_z - 11) = 0.0;
    *++p_z = 0.0;
    v7[1] = vec3_origin.x;
    v7[2] = vec3_origin.y;
    v7 += 3;
    *v7 = vec3_origin.z;
    --v4;
  }
  while ( v4 != 0 );
  this->pivotYaw = 0.0;
  this->waistJointHandle.value = -1;
  this->pivotFoot = -1;
  this->pivotPos.z = 0.0;
  this->pivotPos.y = 0.0;
  this->pivotPos.x = 0.0;
  this->oldHeightsValid = false;
  this->oldWaistHeight = 0.0;
  this->oldGroundPhysicsId = -1;
  this->oldGroundPhysicsOrigin.z = 0.0;
  this->oldGroundPhysicsOrigin.y = 0.0;
  this->oldGroundPhysicsOrigin.x = 0.0;
  this->createdClipModel = false;
  this->groundTraceDist = 1.0;
  this->onGround = false;
  this->internalRadiusXY = 0.0;
  this->onStairs = false;
  this->isDead = false;
  this->mergeBranch = nullptr;
  return this;
}


// ========================================================================
// __unwind$256149
// EA  : 0x826E8004
// RVA : 0x006E8004
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_256149()
{
  int v0; // r12

  idAnimator_IK::~idAnimator_IK(this: *(idAnimator_IK **)(v0 - 160 + 180));
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_IK@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E8038
// RVA : 0x006E8038
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __fastcall idAnimator_IK::InternalPreBlendTree(
        idAnimator_IK *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idPLogScope v7[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idAnimator_IK::InternalPreBlendTree");
  LODWORD(v5) = "idAnimator_IK::InternalPreBlendTree";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v5, label: v6);
  this->Evaluate(this);
  idPLogScope::~idPLogScope(this: v7);
  RD_EventEnd();
}


// ========================================================================
// __unwind$256818
// EA  : 0x826E809C
// RVA : 0x006E809C
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_256818()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$256819
// EA  : 0x826E80C4
// RVA : 0x006E80C4
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void _unwind_256819()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// `dynamic initializer for 'ik_enable''
// EA  : 0x8333F030
// RVA : 0x0133F030
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ik_enable__()
{
  idCVar::idCVar(
    this: &ik_enable,
    name: "ik_enable",
    value: "1",
    flags: 1,
    description: "enable IK",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ik_enable__);
}


// ========================================================================
// `dynamic initializer for 'ik_enableSmoothing''
// EA  : 0x8333F088
// RVA : 0x0133F088
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ik_enableSmoothing__()
{
  idCVar::idCVar(
    this: &ik_enableSmoothing,
    name: "ik_enableSmoothing",
    value: "1",
    flags: 1,
    description: "enable IK smoothing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ik_enableSmoothing__);
}


// ========================================================================
// `dynamic initializer for 'ik_debug''
// EA  : 0x8333F0E0
// RVA : 0x0133F0E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ik_debug__()
{
  idCVar::idCVar(
    this: &ik_debug,
    name: "ik_debug",
    value: "0",
    flags: 1,
    description: "show IK debug lines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ik_debug__);
}

