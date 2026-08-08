
// ========================================================================
// ??0binddef_t@idFuncChain@@QAA@XZ
// EA  : 0x82582F58
// RVA : 0x00582F58
// PDB : w:\tech5\tungsten\game\entities\chainentity.h
// ========================================================================

idFuncChain::binddef_t *__fastcall idFuncChain::binddef_t::binddef_t(idFuncChain::binddef_t *this)
{
  this->bindToObject.spawnId.value = 0x1FFF;
  idStr::idStr(this: &this->bindToJoint, text: &byte_8200D768);
  idStr::idStr(this: &this->bindToTag, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$668873
// EA  : 0x82582FA4
// RVA : 0x00582FA4
// PDB : w:\tech5\tungsten\game\entities\chainentity.h
// ========================================================================

void _unwind_668873()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0chaindef_t@idFuncChain@@QAA@XZ
// EA  : 0x82C10CB0
// RVA : 0x00C10CB0
// PDB : w:\tech5\tungsten\game\entities\chainentity.h
// ========================================================================

idFuncChain::chaindef_t *__fastcall idFuncChain::chaindef_t::chaindef_t(idFuncChain::chaindef_t *this)
{
  float z; // r10

  this->startPosition = vec3_origin;
  this->endPosition.x = vec3_origin.x;
  this->endPosition.y = vec3_origin.y;
  z = vec3_origin.z;
  this->extraLength = 0.0;
  this->endPosition.z = z;
  idFuncChain::binddef_t::binddef_t(this: &this->startBindInfo);
  idFuncChain::binddef_t::binddef_t(this: &this->endBindInfo);
  this->startRotation = 0.0;
  this->randomRotate = true;
  this->smoothSkinning = false;
  return this;
}


// ========================================================================
// __unwind$495999
// EA  : 0x82C10D60
// RVA : 0x00C10D60
// PDB : w:\tech5\tungsten\game\entities\chainentity.h
// ========================================================================

void _unwind_495999()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 112 + 132) + 28));
}


// ========================================================================
// ??0chain_t@idFuncChain@@QAA@XZ
// EA  : 0x82C10D90
// RVA : 0x00C10D90
// PDB : w:\tech5\tungsten\game\entities\chainentity.h
// ========================================================================

idFuncChain::chain_t *__fastcall idFuncChain::chain_t::chain_t(idFuncChain::chain_t *this)
{
  this->start.position = vec3_origin;
  this->start.bind.bindMaster.spawnId.value = 0x1FFF;
  this->start.bind.bindTag.trans.x = 0.0;
  this->start.bind.bindTag.trans.y = 0.0;
  this->start.bind.bindTag.trans.z = 0.0;
  this->start.bind.bindTag.rot.x = 0.0;
  this->start.bind.bindTag.rot.y = 0.0;
  this->start.bind.bindTag.rot.z = 0.0;
  this->start.bind.bindTag.rot.w = 0.0;
  this->start.bind.bindTag.parentJoint.value = -1;
  this->start.bind.bindJoint.value = -1;
  this->end.position = vec3_origin;
  this->end.bind.bindMaster.spawnId.value = 0x1FFF;
  this->end.bind.bindTag.trans.x = 0.0;
  this->end.bind.bindTag.trans.y = 0.0;
  this->end.bind.bindTag.trans.z = 0.0;
  this->end.bind.bindTag.rot.x = 0.0;
  this->end.bind.bindTag.rot.y = 0.0;
  this->end.bind.bindTag.rot.z = 0.0;
  this->end.bind.bindTag.rot.w = 0.0;
  this->end.bind.bindTag.parentJoint.value = -1;
  this->end.bind.bindJoint.value = -1;
  return this;
}

