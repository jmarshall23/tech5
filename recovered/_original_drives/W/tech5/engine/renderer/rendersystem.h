
// ========================================================================
// ??0idScreenView@@QAA@XZ
// EA  : 0x8259EF10
// RVA : 0x0059EF10
// PDB : w:\tech5\engine\renderer\rendersystem.h
// ========================================================================

idScreenView *__fastcall idScreenView::idScreenView(idScreenView *this)
{
  this->usePreviousRendering = false;
  this->viewIndex = -1;
  this->world = nullptr;
  renderView_t::renderView_t(this: &this->g, threadId: THREAD_MAIN);
  this->viewGuis.num = 0;
  this->viewGuis.granularity = 1;
  this->viewGuis.size = 16;
  this->viewGuis.list = this->viewGuis.staticList;
  this->viewGuis.memTag = 5;
  this->viewGuis.listStatic = 1;
  this->guiOriginOffset = 0.0;
  idScreenRect::Clear(this: &this->screenRect);
  return this;
}


// ========================================================================
// __unwind$709970
// EA  : 0x8259EF94
// RVA : 0x0059EF94
// PDB : w:\tech5\engine\renderer\rendersystem.h
// ========================================================================

void _unwind_709970()
{
  int v0; // r12

  renderView_t::~renderView_t(this: (renderView_t *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$709971
// EA  : 0x8259EFC0
// RVA : 0x0059EFC0
// PDB : w:\tech5\engine\renderer\rendersystem.h
// ========================================================================

void _unwind_709971()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1904));
}


// ========================================================================
// ??1idRenderVideoOverlay@@UAA@XZ
// EA  : 0x826A6A48
// RVA : 0x006A6A48
// PDB : w:\tech5\engine\renderer\rendersystem.h
// ========================================================================

void __fastcall idRenderVideoOverlay::~idRenderVideoOverlay(idRenderVideoOverlay *this)
{
  this->__vftable = (idRenderVideoOverlay_vtbl *)&idRenderVideoOverlay::`vftable';
}


// ========================================================================
// ??1idRenderSystem@@UAA@XZ
// EA  : 0x82945D30
// RVA : 0x00945D30
// PDB : w:\tech5\engine\renderer\rendersystem.h
// ========================================================================

void __fastcall idRenderSystem::~idRenderSystem(idRenderSystem *this)
{
  this->__vftable = (idRenderSystem_vtbl *)&idRenderSystem::`vftable';
}

