
// ========================================================================
// ?SetOrientation@idEffectPhysicsRigidBody@@QAAXABVidMat3@@@Z
// EA  : 0x826FA410
// RVA : 0x006FA410
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.h
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::SetOrientation(idEffectPhysicsRigidBody *this, const idMat3 *m)
{
  const idEffectPhysicsProperties *properties; // r9
  idMat3 *p_orientation; // r6
  idEffectPhysicsRigidBody::effectRBState_t *p_currentState; // r5
  idSPObject *p_SPObject; // r4
  double x; // fp11
  idEffectPhysicsBroadPhase *broadPhase; // r3

  this->currentState.orientation.mat[0].x = m->mat[0].x;
  properties = this->properties;
  this->currentState.orientation.mat[0].y = m->mat[0].y;
  p_orientation = &this->currentState.orientation;
  p_currentState = &this->currentState;
  this->currentState.orientation.mat[0].z = m->mat[0].z;
  x = m->mat[1].x;
  p_SPObject = &this->SPObject;
  broadPhase = properties->broadPhase;
  this->currentState.orientation.mat[1].x = x;
  this->currentState.orientation.mat[1].y = m->mat[1].y;
  this->currentState.orientation.mat[1].z = m->mat[1].z;
  this->currentState.orientation.mat[2] = m->mat[2];
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: broadPhase,
    object: p_SPObject,
    origin: &p_currentState->position,
    axis: p_orientation,
    bounds: nullptr);
}

