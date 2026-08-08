
// ========================================================================
// ?InternalShutdown@idAnimator_RollBones@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826EAF10
// RVA : 0x006EAF10
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void __fastcall idAnimator_RollBones::InternalShutdown(idAnimator_RollBones *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_RollBones@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826EAF68
// RVA : 0x006EAF68
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void __fastcall idAnimator_RollBones::InternalPreBlendTree(
        idAnimator_RollBones *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  const idMD6Skel *skeleton; // r26
  int v6; // r28
  int v7; // r29
  idAnimator_RollBones::idRollInstance *v8; // r31
  float *v9; // r3
  float *v10; // r9
  idTreeAnimator *animator; // r3
  idRotation v12; // [sp+50h] [-200h] BYREF
  float z; // [sp+94h] [-1BCh]
  float x; // [sp+98h] [-1B8h]
  float y; // [sp+9Ch] [-1B4h]
  float v16; // [sp+A0h] [-1B0h]
  idMat3 v17; // [sp+B0h] [-1A0h] BYREF
  idMat3 v18; // [sp+E0h] [-170h] BYREF
  idVec3 v19[2]; // [sp+108h] [-148h] BYREF
  idRotation v20; // [sp+120h] [-130h] BYREF
  idMat3 v21; // [sp+170h] [-E0h] BYREF
  idMat3 v22; // [sp+1C0h] [-90h] BYREF
  idMat3 v23[2]; // [sp+1F0h] [-60h] BYREF

  skeleton = this->animator->decl->model->skeleton;
  if ( skeleton != nullptr )
  {
    v6 = 0;
    if ( this->rollBones.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->rollBones.list[v7];
        idTreeAnimator::GetModelSpaceJointTransform(
          this: this->animator,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)((char *)&skeleton->data->size
                                                                               + 2 * v8->rollSourceJoint.value
                                                                               + skeleton->data->parentTblOffset),
          origin: v19,
          axis: &v18);
        idTreeAnimator::GetModelSpaceJointTransform(
          this: this->animator,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v8->rollSourceJoint.value,
          origin: v19,
          axis: &v22);
        v12.axis.mat[1].z = v18.mat[0].x;
        v12.axis.mat[2].x = v18.mat[0].y;
        v12.axis.mat[2].y = v18.mat[0].z;
        v12.axis.mat[2].z = v18.mat[1].x;
        *(float *)&v12.axisValid = v18.mat[1].y;
        z = v18.mat[1].z;
        x = v18.mat[2].x;
        y = v18.mat[2].y;
        v16 = v18.mat[2].z;
        idMat3::InverseSelf(this: (idMat3 *)&v12.axis.mat[1].z);
        v17.mat[0].x = v12.axis.mat[1].z;
        v17.mat[0].y = v12.axis.mat[2].x;
        v17.mat[0].z = v12.axis.mat[2].y;
        v17.mat[1].x = v12.axis.mat[2].z;
        v17.mat[1].y = *(float *)&v12.axisValid;
        v17.mat[1].z = z;
        v17.mat[2].x = x;
        v17.mat[2].y = y;
        v17.mat[2].z = v16;
        v9 = (float *)idMat3::operator*(this: v23, result: &v22, a: &v17);
        v12.origin.x = *v9;
        v12.origin.y = v9[1];
        v12.origin.z = v9[2];
        v12.vec.x = v9[3];
        v12.vec.y = v9[4];
        v12.vec.z = v9[5];
        v12.angle = v9[6];
        v12.axis.mat[0].x = v9[7];
        v12.axis.mat[0].y = v9[8];
        idMat3::ToRotation(this: &v21, result: &v12);
        v20.vec.x = v8->rollAxis.x;
        v20.vec.y = v8->rollAxis.y;
        v20.vec.z = v8->rollAxis.z;
        v20.axisValid = false;
        v20.angle = (float)((float)((float)(v21.mat[1].y * v8->rollAxis.y)
                                  + (float)((float)(v21.mat[1].z * v8->rollAxis.z)
                                          + (float)(v8->rollAxis.x * v21.mat[1].x)))
                          * v8->rollAmount)
                  * v21.mat[2].x;
        v20.axisValid = false;
        v10 = (float *)idRotation::ToMat3(this: &v20);
        animator = this->animator;
        v12.origin.x = *v10;
        v12.origin.y = v10[1];
        v12.origin.z = v10[2];
        v12.vec.x = v10[3];
        v12.vec.y = v10[4];
        v12.vec.z = v10[5];
        v12.angle = v10[6];
        v12.axis.mat[0].x = v10[7];
        v12.axis.mat[0].y = v10[8];
        idTreeAnimator::SetJointAxis(
          this: animator,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v8->rollDestJoint.value,
          type: JOINTMOD_LOCAL_OVERRIDE,
          axis: (const idMat3 *)&v12);
        ++v6;
        ++v7;
      }
      while ( v6 < this->rollBones.num );
    }
  }
}


// ========================================================================
// ??1idAnimator_RollBones@@UAA@XZ
// EA  : 0x826EB1E0
// RVA : 0x006EB1E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void __fastcall idAnimator_RollBones::~idAnimator_RollBones(idAnimator_RollBones *this)
{
  this->__vftable = (idAnimator_RollBones_vtbl *)&idAnimator_RollBones::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rollBones);
  idMD6LeafPause::~idMD6LeafPause(this: &this->animLeaf);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$246431_0
// EA  : 0x826EB23C
// RVA : 0x006EB23C
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void _unwind_246431_0()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246432_0
// EA  : 0x826EB264
// RVA : 0x006EB264
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void _unwind_246432_0()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// ??0idAnimator_RollBones@@QAA@XZ
// EA  : 0x826EB298
// RVA : 0x006EB298
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

idAnimator_RollBones *__fastcall idAnimator_RollBones::idAnimator_RollBones(idAnimator_RollBones *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->enabled = false;
  this->__vftable = (idAnimator_RollBones_vtbl *)&idAnimator_RollBones::`vftable';
  this->animator = nullptr;
  idMD6LeafPause::idMD6LeafPause(this: &this->animLeaf);
  this->mergeBranch = nullptr;
  this->rollBones.list = nullptr;
  this->rollBones.granularity = 0;
  this->rollBones.memTag = 5;
  this->rollBones.listStatic = 0;
  this->rollBones.size = 0;
  this->rollBones.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rollBones);
  return this;
}


// ========================================================================
// __unwind$246624
// EA  : 0x826EB308
// RVA : 0x006EB308
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void _unwind_246624()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246625
// EA  : 0x826EB330
// RVA : 0x006EB330
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

void _unwind_246625()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// ?InternalInit@idAnimator_RollBones@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826EB4F0
// RVA : 0x006EB4F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.cpp
// ========================================================================

BOOL __fastcall idAnimator_RollBones::InternalInit(idAnimator_RollBones *this, const idAnimatorParms_Base *parms)
{
  idMD6Branch *v4; // r3
  idTreeAnimator *treeAnimator; // r10
  const idMD6Skel *skeleton; // r11
  idAnimStack *animStack; // r10
  int v9; // r24
  int v10; // r28
  int v11; // r30
  int v12; // r27
  idAnimator_RollBones::idRollInstance *v13; // r31
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  __int16 value; // r4
  float *v16; // r11
  char v17; // [sp+50h] [-50h] BYREF
  char v18; // [sp+52h] [-4Eh] BYREF

  v4 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  this->mergeBranch = v4;
  if ( v4 == nullptr )
    return false;
  treeAnimator = parms->animStack->treeAnimator;
  this->animator = treeAnimator;
  skeleton = treeAnimator->decl->model->skeleton;
  if ( skeleton == nullptr )
    return false;
  animStack = parms[1].animStack;
  if ( animStack != nullptr )
  {
    v9 = (int)skeleton->data + 28 * ((skeleton->data->numJoints + 7) & 0xFFF8) + skeleton->data->basePoseOffset;
    idList<idAnimator_RollBones::idRollInstance,5>::SetNum(
      this: &this->rollBones,
      newNum: *(_DWORD *)&animStack->md6Allocator.branches.allowAllocs);
    v10 = 0;
    if ( this->rollBones.num > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        v13 = &this->rollBones.list[v12];
        v13->rollSourceJoint = (idIndex<short,enum invalidJointIndex_t>)idTreeAnimator::GetJointIndex(
                                                                          this: (idTreeAnimator *)&v17,
                                                                          result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                                                                          jointName: *(const char **)(parms[1].animStack->md6Allocator.branches.active
                                                                                         + v11
                                                                                         + 4))->value;
        JointIndex = idTreeAnimator::GetJointIndex(
                       this: (idTreeAnimator *)&v18,
                       result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
                       jointName: *(const char **)(parms[1].animStack->md6Allocator.branches.active + v11 + 36));
        value = JointIndex->value;
        v13->rollDestJoint = (idIndex<short,enum invalidJointIndex_t>)JointIndex->value;
        v16 = (float *)(12 * value + v9);
        v13->rollAmount = *(float *)(parms[1].animStack->md6Allocator.branches.active + v11 + 64);
        v13->rollAxis.x = *v16;
        v13->rollAxis.y = v16[1];
        v13->rollAxis.z = v16[2];
        idVec3::NormalizeFast(this: &v13->rollAxis);
        ++v10;
        ++v12;
        v11 += 68;
      }
      while ( v10 < this->rollBones.num );
    }
    this->enabled = true;
  }
  return this->enabled;
}

