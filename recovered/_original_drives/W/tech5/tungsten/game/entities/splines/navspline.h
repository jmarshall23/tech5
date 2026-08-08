
// ========================================================================
// ??0idNavSplinePath@@QAA@XZ
// EA  : 0x8253D5E8
// RVA : 0x0053D5E8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.h
// ========================================================================

idNavSplinePath *__fastcall idNavSplinePath::idNavSplinePath(idNavSplinePath *this)
{
  idSplinePath::idSplinePath(this);
  this->__vftable = (idNavSplinePath_vtbl *)&idNavSplinePath::`vftable';
  this->pathWidth.list = nullptr;
  this->pathWidth.granularity = 0;
  this->pathWidth.memTag = 5;
  this->pathWidth.listStatic = 0;
  this->pathWidth.size = 0;
  this->pathWidth.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pathWidth);
  this->resetWidth = 0.0;
  this->splineFlags = (idNavSplinePath::splineFlags_t)119;
  this->navSplineType = NAV_SPLINE_TYPE_DEFAULT;
  this->excessEdgeLimit = 100000.0;
  return this;
}


// ========================================================================
// __unwind$582568
// EA  : 0x8253D670
// RVA : 0x0053D670
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.h
// ========================================================================

void _unwind_582568()
{
  int v0; // r12

  idSplinePath::~idSplinePath(this: *(idSplinePath **)(v0 - 128 + 148));
}

