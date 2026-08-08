
// ========================================================================
// ?PlayFrame@idSWFSpriteInstance@@QAAXPBD@Z
// EA  : 0x82DB1860
// RVA : 0x00DB1860
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.h
// ========================================================================

void __fastcall idSWFSpriteInstance::PlayFrame(idSWFSpriteInstance *this, const char *frameName)
{
  idStaticList<idSWFScriptVar,16> v4; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v4);
  idSWFParmList::Append(this: (idSWFParmList *)&v4, s: frameName);
  idSWFSpriteInstance::PlayFrame(this, parms: (const idSWFParmList *)&v4);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v4);
}


// ========================================================================
// __unwind$536768
// EA  : 0x82DB18A8
// RVA : 0x00DB18A8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.h
// ========================================================================

void _unwind_536768()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?StopFrame@idSWFSpriteInstance@@QAAXH@Z
// EA  : 0x82DDC160
// RVA : 0x00DDC160
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.h
// ========================================================================

void __fastcall idSWFSpriteInstance::StopFrame(
        idSWFSpriteInstance *this,
        idSWFScriptVar::swfScriptVarValue_t *frameNum)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idStaticList<idSWFScriptVar,16> v7; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
  idSWFParmList::Append(this: (idSWFParmList *)&v7, i: frameNum);
  idSWFSpriteInstance::StopFrame(this, parms: (const idSWFParmList *)&v7, a3: v6, a4: v5, a5: v4);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
}


// ========================================================================
// __unwind$488635_0
// EA  : 0x82DDC1A8
// RVA : 0x00DDC1A8
// PDB : w:\tech5\engine\guis\swf\swf_spriteinstance.h
// ========================================================================

void _unwind_488635_0()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}

