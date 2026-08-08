
// ========================================================================
// ??0idDeclAIPlayerInteraction@@QAA@XZ
// EA  : 0x82BD73F8
// RVA : 0x00BD73F8
// PDB : w:\tech5\tungsten\game\decls\declaiplayerinteraction.h
// ========================================================================

idDeclAIPlayerInteraction *__fastcall idDeclAIPlayerInteraction::idDeclAIPlayerInteraction(
        idDeclAIPlayerInteraction *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->approachRadius = 200.0;
  this->__vftable = (idDeclAIPlayerInteraction_vtbl *)&idDeclAIPlayerInteraction::`vftable';
  this->departureRadius = 350.0;
  this->lookAheadTime = 0.5;
  this->interactList.granularity = 0;
  this->interactList.memTag = 5;
  this->interactList.listStatic = 0;
  this->interactList.list = nullptr;
  this->interactList.size = 0;
  this->interactList.num = 0;
  return this;
}


// ========================================================================
// __unwind$505208
// EA  : 0x82BD748C
// RVA : 0x00BD748C
// PDB : w:\tech5\tungsten\game\decls\declaiplayerinteraction.h
// ========================================================================

void _unwind_505208()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclAIPlayerInteraction@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD74B8
// RVA : 0x00BD74B8
// PDB : w:\tech5\tungsten\game\decls\declaiplayerinteraction.h
// ========================================================================

idDeclInfoTemplate<idDeclAIPlayerInteraction> *__fastcall idDeclAIPlayerInteraction::GetDeclInfo(
        idDeclAIPlayerInteraction *this)
{
  return &idDeclAIPlayerInteraction::resourceList;
}

