
// ========================================================================
// ?SetLinkedPosition@idClipModel@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826C9568
// RVA : 0x006C9568
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.h
// ========================================================================

void __fastcall idClipModel::SetLinkedPosition(idClipModel *this, const idVec3 *newOrigin, const idMat3 *newAxis)
{
  if ( this->clipLinks != nullptr )
  {
    idClipModel::Unlink(this);
    this->origin.x = newOrigin->x;
    this->origin.y = newOrigin->y;
    this->origin.z = newOrigin->z;
    this->axis.mat[0].x = newAxis->mat[0].x;
    this->axis.mat[0].y = newAxis->mat[0].y;
    this->axis.mat[0].z = newAxis->mat[0].z;
    this->axis.mat[1].x = newAxis->mat[1].x;
    this->axis.mat[1].y = newAxis->mat[1].y;
    this->axis.mat[1].z = newAxis->mat[1].z;
    this->axis.mat[2].x = newAxis->mat[2].x;
    this->axis.mat[2].y = newAxis->mat[2].y;
    this->axis.mat[2].z = newAxis->mat[2].z;
    idClipModel::Link(this);
  }
  else
  {
    this->origin = *newOrigin;
    this->axis = *newAxis;
  }
}


// ========================================================================
// ?GetNumCollisionModels@idClipModel@@QBAHXZ
// EA  : 0x827014B0
// RVA : 0x007014B0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.h
// ========================================================================

int __fastcall idClipModel::GetNumCollisionModels(idClipModel *this)
{
  if ( this->collisionModel != nullptr )
    return 1;
  else
    return this->traceModels.num;
}


// ========================================================================
// ?GetCollisionModel@idClipModel@@QBAPAVidCollisionModel@@H@Z
// EA  : 0x827014D0
// RVA : 0x007014D0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.h
// ========================================================================

idCollisionModel *__fastcall idClipModel::GetCollisionModel(idClipModel *this, int index)
{
  if ( this->collisionModel != nullptr )
    return this->collisionModel;
  if ( index >= this->traceModels.num )
    return idClipModel::NoTraceModelWarning(this);
  return this->clip->traceModelCache->cache.list[this->traceModels.list[index]]->collisionModel;
}


// ========================================================================
// ?GetModelJoints@idClipModel@@QBAPBVidJointMat@@XZ
// EA  : 0x8272BA90
// RVA : 0x0072BA90
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.h
// ========================================================================

const idJointMat *__fastcall idClipModel::GetModelJoints(idClipModel *this)
{
  idTreeAnimator *animatedModel; // r11

  animatedModel = this->animatedModel;
  if ( animatedModel != nullptr )
    return animatedModel->joints[1];
  else
    return nullptr;
}


// ========================================================================
// ?Translate@idClipModel@@QAAXABVidVec3@@@Z
// EA  : 0x82745870
// RVA : 0x00745870
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.h
// ========================================================================

void __fastcall idClipModel::Translate(idClipModel *this, const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8

  idClipModel::Unlink(this);
  y = this->origin.y;
  this->origin.x = this->origin.x + translation->x;
  z = this->origin.z;
  this->origin.y = translation->y + (float)y;
  this->origin.z = translation->z + (float)z;
}

