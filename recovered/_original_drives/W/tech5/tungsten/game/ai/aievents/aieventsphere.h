
// ========================================================================
// ?Clear@idAIEventProjectedSphere@@UAAXXZ
// EA  : 0x8251CE68
// RVA : 0x0051CE68
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.h
// ========================================================================

void __fastcall idAIEventProjectedSphere::Clear(idAIEventProjectedSphere *this)
{
  this->hasProjection = false;
  this->projectedOrigin = vec3_origin;
  this->curSimPos = vec3_origin;
  this->curSimVel = vec3_origin;
  this->traceFrom = vec3_origin;
  this->bounces = -1;
  this->horizontalBounces = -1;
}


// ========================================================================
// ??0idAIEventProjectedSphere@@QAA@XZ
// EA  : 0x82536650
// RVA : 0x00536650
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.h
// ========================================================================

idAIEventProjectedSphere *__fastcall idAIEventProjectedSphere::idAIEventProjectedSphere(idAIEventProjectedSphere *this)
{
  idAIEventSphere::idAIEventSphere(this);
  this->__vftable = (idAIEventProjectedSphere_vtbl *)&idAIEventProjectedSphere::`vftable';
  this->hasProjection = false;
  this->projectedOrigin = vec3_origin;
  this->curSimPos = vec3_origin;
  this->curSimVel = vec3_origin;
  this->traceFrom = vec3_origin;
  this->bounces = -1;
  this->horizontalBounces = -1;
  return this;
}


// ========================================================================
// ?GetColor@idAIEventSphere@@UBAABVidColor@@XZ
// EA  : 0x82536708
// RVA : 0x00536708
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsphere.h
// ========================================================================

const idColor *__fastcall idAIEventSphere::GetColor(idAIEventSphere *this)
{
  return &idAIEventSphere::defaultColor;
}

