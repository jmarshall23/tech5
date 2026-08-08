
// ========================================================================
// ?UnloadDLL@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EAB070
// RVA : 0x00EAB070
// PDB : w:\tech5\tungsten\game\superscript\ss_dll.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::UnloadDLL(idSuperScriptSystem *this)
{
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->fibers);
  this->superScriptInterface = nullptr;
}


// ========================================================================
// ?LoadDLL@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EAB0B0
// RVA : 0x00EAB0B0
// PDB : w:\tech5\tungsten\game\superscript\ss_dll.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::LoadDLL(idSuperScriptSystem *this)
{
  idList<idSSFiber *,108> *p_fibers; // r29
  idSuperScript *SuperScriptAPI; // r3
  idSuperScript *superScriptInterface; // r29
  int v5; // [sp+54h] [-2Ch]

  p_fibers = &this->fibers;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->fibers);
  this->superScriptInterface = nullptr;
  SuperScriptAPI = GetSuperScriptAPI(version: 1);
  this->superScriptInterface = SuperScriptAPI;
  if ( !SuperScriptAPI->CheckVersionCRC(this: SuperScriptAPI, a2: typeInfo_0.superScriptVersion) )
  {
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)p_fibers);
    this->superScriptInterface = nullptr;
    idLib::FatalError(fmt: "superScript DLL version mismatch, update from source control and recompile\n");
  }
  superScriptInterface = this->superScriptInterface;
  v5 = (int)superScriptInterface->Lock(this: superScriptInterface, a2: this);
  this->superScriptInterface->RegisterCVars(this: this->superScriptInterface);
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v5);
}


// ========================================================================
// $LN13_6
// EA  : 0x82EAB180
// RVA : 0x00EAB180
// PDB : w:\tech5\tungsten\game\superscript\ss_dll.cpp
// ========================================================================

void _LN13_6()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 128 + 80));
}

