
// ========================================================================
// ??0idDeclActorModifier@@QAA@XZ
// EA  : 0x82BD5E48
// RVA : 0x00BD5E48
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

idDeclActorModifier *__fastcall idDeclActorModifier::idDeclActorModifier(idDeclActorModifier *this)
{
  idDeclInventory::idDeclInventory(this: &this->idDeclInventory);
  this->__vftable = (idDeclActorModifier_vtbl *)&idDeclActorModifier::`vftable';
  this->outputs.list = nullptr;
  this->outputs.granularity = 0;
  this->outputs.memTag = 5;
  this->outputs.listStatic = 0;
  this->outputs.size = 0;
  this->outputs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->outputs);
  this->triggers.granularity = 0;
  this->triggers.memTag = 5;
  this->triggers.listStatic = 0;
  this->triggers.list = nullptr;
  this->triggers.size = 0;
  this->triggers.num = 0;
  this->deps.list = nullptr;
  this->deps.granularity = 0;
  this->deps.memTag = 5;
  this->deps.listStatic = 0;
  this->deps.size = 0;
  this->deps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deps);
  this->lifetime = 0;
  this->removeAfter = 0;
  this->cooldown = 0;
  this->fxDecl = nullptr;
  this->uiSlot = SLOT_HIDDEN;
  this->removeOnDeath = false;
  idStr::operator=(this: &this->inventoryClass, text: "idActorModifierItem");
  return this;
}


// ========================================================================
// __unwind$504005
// EA  : 0x82BD5F0C
// RVA : 0x00BD5F0C
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

void _unwind_504005()
{
  int v0; // r12

  idDeclInventory::~idDeclInventory(this: *(idDeclInventory **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$504006
// EA  : 0x82BD5F34
// RVA : 0x00BD5F34
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

void _unwind_504006()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 504));
}


// ========================================================================
// __unwind$504007
// EA  : 0x82BD5F60
// RVA : 0x00BD5F60
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

void _unwind_504007()
{
  int v0; // r12

  idList<idDeclActorModifier::ActorModifierTrigger_t,5>::Clear(this: (idList<idDeclActorModifier::ActorModifierTrigger_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 520));
}


// ========================================================================
// __unwind$504008
// EA  : 0x82BD5F8C
// RVA : 0x00BD5F8C
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

void _unwind_504008()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 536));
}


// ========================================================================
// ?GetDeclInfo@idDeclActorModifier@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD5FB8
// RVA : 0x00BD5FB8
// PDB : w:\tech5\tungsten\game\decls\declactormodifier.h
// ========================================================================

idDeclInfoTemplate<idDeclActorModifier> *__fastcall idDeclActorModifier::GetDeclInfo(idDeclActorModifier *this)
{
  return &idDeclActorModifier::resourceList;
}

