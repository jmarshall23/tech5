
// ========================================================================
// ??0idSPObject@@QAA@XZ
// EA  : 0x826FA6A8
// RVA : 0x006FA6A8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.h
// ========================================================================

idSPObject *__fastcall idSPObject::idSPObject(idSPObject *this)
{
  unsigned __int64 v1; // r30

  LODWORD(v1) = 0;
  this->query.offset = v1;
  this->overlap.list = nullptr;
  this->overlap.granularity = 0;
  this->overlap.memTag = 59;
  this->overlap.listStatic = 0;
  this->overlap.size = 0;
  this->overlap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->overlap);
  this->id = 0;
  this->traceModelIndex = -1;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->absBounds.b[0][2] = 0x7FFF;
  this->absBounds.b[0][1] = 0x7FFF;
  this->absBounds.b[0][0] = 0x7FFF;
  this->absBounds.b[1][2] = 0x8000;
  this->absBounds.b[1][1] = 0x8000;
  this->absBounds.b[1][0] = 0x8000;
  this->motion.valid = false;
  this->motion.worldCollisionOnly = false;
  this->motion.ignore = false;
  this->motion.translation.z = 0.0;
  this->motion.translation.y = 0.0;
  this->motion.translation.x = 0.0;
  this->motion.rotationVec.z = 0.0;
  this->motion.rotationVec.y = 0.0;
  this->motion.rotationVec.x = 0.0;
  this->index[0][2] = 0;
  this->motion.rotationAngle = 0.0;
  this->index[0][1] = 0;
  this->index[0][0] = 0;
  this->index[1][2] = 0;
  this->index[1][1] = 0;
  this->index[1][0] = 0;
  this->entityNum = 0x1FFF;
  this->clipMask = 1;
  return this;
}

