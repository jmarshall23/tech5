
// ========================================================================
// ??0idDeclEnv@@QAA@XZ
// EA  : 0x82620368
// RVA : 0x00620368
// PDB : w:\tech5\engine\decls\declenv.h
// ========================================================================

idDeclEnv *__fastcall idDeclEnv::idDeclEnv(idDeclEnv *this)
{
  idDecl::idDecl(this: &this->idDecl);
  this->__vftable = (idDeclEnv_vtbl *)&idDeclEnv::`vftable';
  idParmBlock::idParmBlock(this: &this->parmBlock, threadId: THREAD_MAIN);
  this->parentDeclName.str = &byte_8200D768;
  this->blendDuration = 2.2;
  return this;
}


// ========================================================================
// __unwind$221396
// EA  : 0x826203E0
// RVA : 0x006203E0
// PDB : w:\tech5\engine\decls\declenv.h
// ========================================================================

void _unwind_221396()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclEnv@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82620408
// RVA : 0x00620408
// PDB : w:\tech5\engine\decls\declenv.h
// ========================================================================

idDeclInfoTemplate<idDeclEnv> *__fastcall idDeclEnv::GetDeclInfo(idDeclEnv *this)
{
  return &idDeclEnv::resourceList;
}

