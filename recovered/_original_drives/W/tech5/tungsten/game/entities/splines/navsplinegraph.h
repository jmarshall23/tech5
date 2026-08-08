
// ========================================================================
// ?Init@navSplinePathNode_t@@QAAXXZ
// EA  : 0x82582FD0
// RVA : 0x00582FD0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.h
// ========================================================================

void __fastcall navSplinePathNode_t::Init(navSplinePathNode_t *this)
{
  this->position.z = 0.0;
  this->index = 0;
  this->position.y = 0.0;
  this->position.x = 0.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->links);
  this->search.parent = nullptr;
  this->search.distance = 1.0e30;
  this->search.spline = nullptr;
}


// ========================================================================
// ??0navSplinePathNode_t@@QAA@XZ
// EA  : 0x8259F470
// RVA : 0x0059F470
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.h
// ========================================================================

navSplinePathNode_t *__fastcall navSplinePathNode_t::navSplinePathNode_t(navSplinePathNode_t *this)
{
  idStaticList<navSplineLink_t,16> *p_links; // r29

  p_links = &this->links;
  idStaticList<navSplineLink_t,16>::idStaticList<navSplineLink_t,16>(this: &this->links);
  this->index = 0;
  this->position.z = 0.0;
  this->position.y = 0.0;
  this->position.x = 0.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_links);
  this->search.parent = nullptr;
  this->search.distance = 1.0e30;
  this->search.spline = nullptr;
  return this;
}


// ========================================================================
// __unwind$711186
// EA  : 0x8259F4D8
// RVA : 0x0059F4D8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.h
// ========================================================================

void _unwind_711186()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 12));
}

