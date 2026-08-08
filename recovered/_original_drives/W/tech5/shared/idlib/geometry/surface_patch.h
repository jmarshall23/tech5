
// ========================================================================
// ??1idSurface_Patch@@QAA@XZ
// EA  : 0x825CD5F0
// RVA : 0x005CD5F0
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.h
// ========================================================================

// attributes: thunk
void __fastcall idSurface_Patch::~idSurface_Patch(idSurface_Patch *this)
{
  idSurface::~idSurface((splineMoverModifier_t::splineMoverModifierSound_t *)this);
}


// ========================================================================
// ??0idSurface_Patch@@QAA@ABV0@@Z
// EA  : 0x825D0388
// RVA : 0x005D0388
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.h
// ========================================================================

idSurface_Patch *__fastcall idSurface_Patch::idSurface_Patch(idSurface_Patch *this, const idSurface_Patch *patch)
{
  idSurface::idSurface(this);
  idSurface_Patch::operator=(this, __that: patch);
  return this;
}


// ========================================================================
// __unwind$247610
// EA  : 0x825D03C0
// RVA : 0x005D03C0
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.h
// ========================================================================

void _unwind_247610()
{
  int v0; // r12

  idSurface::~idSurface(this: *(splineMoverModifier_t::splineMoverModifierSound_t **)(v0 - 112 + 132));
}

