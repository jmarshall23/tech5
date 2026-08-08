
// ========================================================================
// ?CommandLinks@@YAPAVidCommandLink@@XZ
// EA  : 0x82EFAB80
// RVA : 0x00EFAB80
// PDB : w:\tech5\shared\idlib\commandlink.cpp
// ========================================================================

idCommandLink *__fastcall CommandLinks()
{
  return commandLinks;
}


// ========================================================================
// ??0idCommandLink@@QAA@PBDP6AXABVidCmdArgs@@@Z0P6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82EFAB90
// RVA : 0x00EFAB90
// PDB : w:\tech5\shared\idlib\commandlink.cpp
// ========================================================================

idCommandLink *__fastcall idCommandLink::idCommandLink(
        idCommandLink *this,
        const char *cmdName,
        void (__fastcall *function)(const idCmdArgs *),
        const char *description,
        void (__fastcall *argCompletion)(idAutoComplete *))
{
  this->cmdName_ = cmdName;
  this->function_ = function;
  this->description_ = description;
  this->argCompletion_ = argCompletion;
  this->next = commandLinks;
  commandLinks = this;
  return this;
}

