
// ========================================================================
// ??1idAnimator_TorsoTracker@@UAA@XZ
// EA  : 0x826EC180
// RVA : 0x006EC180
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::~idAnimator_TorsoTracker(idAnimator_TorsoTracker *this)
{
  this->__vftable = (idAnimator_TorsoTracker_vtbl *)&idAnimator_TorsoTracker::`vftable';
  idAnimator_TrackerBase::~idAnimator_TrackerBase(this);
}


// ========================================================================
// ?SetReferenceJointOverride@idAnimator_TorsoTracker@@UAAXV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x826EC190
// RVA : 0x006EC190
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::SetReferenceJointOverride(
        idAnimator_TorsoTracker *this,
        const idIndex<short,enum invalidJointIndex_t> *ji)
{
  this->referenceJointOverrideIdx.value = (__int16)ji;
}


// ========================================================================
// ?GetReferenceJointOverride@idAnimator_TorsoTracker@@UBA?BV?$idIndex@FW4invalidJointIndex_t@@@@XZ
// EA  : 0x826EC198
// RVA : 0x006EC198
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

idAnimator_TorsoTracker *__fastcall idAnimator_TorsoTracker::GetReferenceJointOverride(
        idAnimator_TorsoTracker *this,
        const idIndex<short,enum invalidJointIndex_t> *result)
{
  HIWORD(this->__vftable) = result[92];
  return this;
}


// ========================================================================
// ??0idAnimator_TorsoTracker@@QAA@XZ
// EA  : 0x826EC1A8
// RVA : 0x006EC1A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

idAnimator_TorsoTracker *__fastcall idAnimator_TorsoTracker::idAnimator_TorsoTracker(idAnimator_TorsoTracker *this)
{
  idAnimator_TrackerBase::idAnimator_TrackerBase(this);
  this->__vftable = (idAnimator_TorsoTracker_vtbl *)&idAnimator_TorsoTracker::`vftable';
  this->referenceJointOverrideIdx.value = -1;
  this->useOriginXYForWorldSpace = false;
  this->referenceJointOverrideIdx.value = -1;
  return this;
}


// ========================================================================
// ?GetModelSpaceFrameOfReferenceForChild@idAnimator_TorsoTracker@@UBAXPBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x826EC260
// RVA : 0x006EC260
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::GetModelSpaceFrameOfReferenceForChild(
        idAnimator_TorsoTracker *this,
        const idTreeAnimator *ta,
        idVec3 *msRefPos,
        idMat3 *msRefAxis)
{
  double x; // fp0
  double z; // fp7
  double y; // fp9
  double v7; // fp11
  double v8; // fp13
  double v9; // fp12
  double v10; // fp3
  double v11; // fp1
  double v12; // fp2
  double v13; // fp9
  double v14; // fp11
  double v15; // fp6
  double v18; // fp2
  double v19; // fp3
  double v20; // fp8
  double v21; // fp12
  double v22; // fp9
  double v23; // fp4
  double v24; // fp3
  double v25; // fp2
  double v26; // fp13
  double v27; // fp12
  double v28; // fp11
  double v29; // fp9
  double v30; // fp8
  double v31; // fp6
  double v33; // fp12
  double v35; // fp10
  double v36; // fp13
  double v37; // fp12

  x = this->msDirToFocus.x;
  msRefAxis->mat[0].x = this->msDirToFocus.x;
  msRefAxis->mat[0].y = this->msDirToFocus.y;
  z = this->msDirToFocus.z;
  msRefAxis->mat[0].z = this->msDirToFocus.z;
  y = msRefAxis->mat[0].y;
  v7 = mat3_identity.mat[2].z;
  v8 = mat3_identity.mat[2].y;
  v9 = mat3_identity.mat[2].x;
  v10 = (float)((float)((float)x * mat3_identity.mat[2].z) - (float)((float)z * mat3_identity.mat[2].x));
  msRefAxis->mat[1].y = (float)((float)x * mat3_identity.mat[2].z) - (float)((float)z * mat3_identity.mat[2].x);
  v11 = (float)((float)((float)z * (float)v8) - (float)((float)y * (float)v7));
  msRefAxis->mat[1].x = (float)((float)z * (float)v8) - (float)((float)y * (float)v7);
  v12 = (float)((float)((float)y * (float)v9) - (float)((float)x * (float)v8));
  msRefAxis->mat[1].z = (float)((float)y * (float)v9) - (float)((float)x * (float)v8);
  v14 = v12;
  v13 = v10;
  v15 = (float)((float)((float)v12 * (float)v12)
              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)));
  _FP5 = (float)((float)((float)((float)v12 * (float)v12)
                       + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v18 = __frsqrte(_FP3);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)v15 * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)v15 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)v15 * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)v14
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)v15 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)v15 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)))
                                      - (float)1.5)
                      * (float)v19));
  msRefAxis->mat[1].z = (float)v14
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18) * (float)((float)v15 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18)
                                                                                              - (float)1.5)
                                                                              * (float)v18))
                                                              * (float)((float)v15 * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18)))
                                              - (float)1.5)
                              * (float)v19);
  v21 = (float)((float)v11
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)v15 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)v15 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)))
                                      - (float)1.5)
                      * (float)v19));
  msRefAxis->mat[1].x = (float)v11
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18) * (float)((float)v15 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18)
                                                                                              - (float)1.5)
                                                                              * (float)v18))
                                                              * (float)((float)v15 * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18)))
                                              - (float)1.5)
                              * (float)v19);
  v22 = (float)((float)v13
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5) * (float)v18)
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5))
                                                                                              * (float)v18)
                                                                                      - (float)1.5)
                                                                      * (float)v18))
                                                      * (float)((float)v15 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)v15 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)v15 * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)))
                                      - (float)1.5)
                      * (float)v19));
  msRefAxis->mat[1].y = v22;
  v23 = msRefAxis->mat[0].z;
  v25 = v21;
  v24 = msRefAxis->mat[0].y;
  v26 = (float)(msRefAxis->mat[0].z * (float)v22);
  v28 = (float)((float)((float)v22 * msRefAxis->mat[0].x) - (float)((float)v21 * msRefAxis->mat[0].y));
  v27 = (float)((float)v20 * msRefAxis->mat[0].x);
  msRefAxis->mat[2].z = v28;
  v29 = (float)((float)((float)v24 * (float)v20) - (float)v26);
  msRefAxis->mat[2].x = (float)((float)v24 * (float)v20) - (float)v26;
  v30 = (float)((float)((float)v25 * (float)v23) - (float)v27);
  msRefAxis->mat[2].y = (float)((float)v25 * (float)v23) - (float)v27;
  v31 = v28;
  _FP1 = (float)((float)((float)((float)v28 * (float)v28)
                       + (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v33 = (float)((float)((float)((float)v28 * (float)v28)
                      + (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30)))
              * (float)0.5);
  __asm { fsel      f11, f1, f2, f13 }
  v35 = __frsqrte(_FP11);
  v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)v33)
                                                                              * (float)v35)
                                                                      - (float)1.5)
                                                      * (float)v35)
                                              * (float)v33)
                                      * (float)((float)-(float)((float)((float)((float)v35 * (float)v33) * (float)v35)
                                                              - (float)1.5)
                                              * (float)v35))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v35 * (float)v33) * (float)v35) - (float)1.5) * (float)v35));
  v37 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)v33)
                                                                                      * (float)v35)
                                                                              - (float)1.5)
                                                              * (float)v35)
                                                      * (float)v33)
                                              * (float)((float)-(float)((float)((float)((float)v35 * (float)v33)
                                                                              * (float)v35)
                                                                      - (float)1.5)
                                                      * (float)v35))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v35 * (float)v33) * (float)v35) - (float)1.5)
                              * (float)v35))
              * (float)v33);
  msRefAxis->mat[2].x = (float)v29
                      * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5) * (float)v36);
  msRefAxis->mat[2].z = (float)v31
                      * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5) * (float)v36);
  msRefAxis->mat[2].y = (float)v30
                      * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5) * (float)v36);
  *msRefPos = this->msReferenceJointPos;
}


// ========================================================================
// ?GetWorldSpaceFrameOfReferenceForChild@idAnimator_TorsoTracker@@UBAXPBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x826EC408
// RVA : 0x006EC408
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::GetWorldSpaceFrameOfReferenceForChild(
        idAnimator_TorsoTracker *this,
        const idTreeAnimator *ta,
        idVec3 *wsRefPos,
        idMat3 *wsRefAxis)
{
  _BYTE v8[16]; // [sp+50h] [-90h] BYREF
  idMat3 v9; // [sp+60h] [-80h] BYREF
  idMat3 v10[2]; // [sp+90h] [-50h] BYREF

  this->GetModelSpaceFrameOfReferenceForChild(this, a2: ta, a3: (idVec3 *)v8, a4: &v9);
  *wsRefAxis = *idMat3::operator*(this: v10, result: &v9, a: &ta->g.axis);
  *wsRefPos = this->wsFocusJointPos;
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_TorsoTracker@@UAAXAAVidSerializer@@@Z
// EA  : 0x826EC4B8
// RVA : 0x006EC4B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::SerializeSnapshot(idAnimator_TorsoTracker *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  bool useOriginXYForWorldSpace; // r31
  unsigned __int16 value; // r11
  unsigned __int16 Bits; // r31
  idBitMsg *v8; // r3

  idAnimator_TrackerBase::SerializeSnapshot(this, ser);
  msg = ser->msg;
  useOriginXYForWorldSpace = this->useOriginXYForWorldSpace;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->useOriginXYForWorldSpace, numBits: 1);
  else
    useOriginXYForWorldSpace = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  value = this->referenceJointOverrideIdx.value;
  this->useOriginXYForWorldSpace = useOriginXYForWorldSpace;
  if ( value == NULL_JOINT_INDEX.value )
    value = -1;
  Bits = value;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value, numBits: 16);
  else
    Bits = idBitMsg::ReadBits(this: v8, numBits: 16);
  if ( Bits == 0xFFFF )
    this->referenceJointOverrideIdx = NULL_JOINT_INDEX;
  else
    this->referenceJointOverrideIdx.value = Bits;
}


// ========================================================================
// ?GetWorldSpaceFrameOfReference@idAnimator_TorsoTracker@@UBAXPBVidAnimator_TrackerBase@@PBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x826EC598
// RVA : 0x006EC598
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::GetWorldSpaceFrameOfReference(
        idAnimator_TorsoTracker *this,
        idAnimator_TrackerBase *parentTracker,
        idTreeAnimator *ta,
        idVec3 *wsRefPos,
        idMat3 *wsRefAxis)
{
  int trackGroupIndex; // r11
  const idDeclMD6 *decl; // r10
  int v12; // r11
  const idIndex<short,enum invalidJointIndex_t> *v13; // r5

  if ( parentTracker != nullptr && idAnimator_Base::IsContributing(this: parentTracker) )
  {
    parentTracker->GetWorldSpaceFrameOfReferenceForChild(this: parentTracker, a2: ta, a3: wsRefPos, a4: wsRefAxis);
  }
  else
  {
    trackGroupIndex = this->trackGroupIndex;
    decl = ta->decl;
    if ( trackGroupIndex >= 0
      && trackGroupIndex < decl->headTrackGroups.num
      && (v12 = (int)&decl->headTrackGroups.list[trackGroupIndex]) != 0 )
    {
      v13 = (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)(v12 + 20);
    }
    else
    {
      v13 = nullptr;
    }
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: ta,
      pose: (animationPose_t)0,
      jointIndex: v13,
      origin: wsRefPos,
      axis: wsRefAxis);
  }
  if ( this->useOriginXYForWorldSpace )
  {
    wsRefPos->x = ta->g.origin.x;
    wsRefPos->y = ta->g.origin.y;
  }
}


// ========================================================================
// ?GetModelSpaceFrameOfReference@idAnimator_TorsoTracker@@UBAXPBVidAnimator_TrackerBase@@PBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x826EC670
// RVA : 0x006EC670
// PDB : w:\tech5\engine\gamelib\animstack\animator_torsotracker.cpp
// ========================================================================

void __fastcall idAnimator_TorsoTracker::GetModelSpaceFrameOfReference(
        idAnimator_TorsoTracker *this,
        idAnimator_TrackerBase *parentTracker,
        idTreeAnimator *ta,
        idVec3 *msRefPos,
        idMat3 *msRefAxis)
{
  int trackGroupIndex; // r11
  const idDeclMD6 *decl; // r10
  int v12; // r10
  idIndex<short,enum invalidJointIndex_t> *p_referenceJointOverrideIdx; // r11

  if ( parentTracker != nullptr && idAnimator_Base::IsContributing(this: parentTracker) )
  {
    parentTracker->GetModelSpaceFrameOfReferenceForChild(this: parentTracker, a2: ta, a3: msRefPos, a4: msRefAxis);
  }
  else
  {
    trackGroupIndex = this->trackGroupIndex;
    decl = ta->decl;
    if ( trackGroupIndex < 0 || trackGroupIndex >= decl->headTrackGroups.num )
      v12 = 0;
    else
      v12 = (int)&decl->headTrackGroups.list[trackGroupIndex];
    p_referenceJointOverrideIdx = &this->referenceJointOverrideIdx;
    if ( (unsigned __int16)this->referenceJointOverrideIdx.value >= 0x8000u )
      p_referenceJointOverrideIdx = (idIndex<short,enum invalidJointIndex_t> *)(v12 + 22);
    idTreeAnimator::GetModelSpaceJointTransform(
      this: ta,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_referenceJointOverrideIdx->value,
      origin: msRefPos,
      axis: msRefAxis);
  }
}

