
// ========================================================================
// ?GetGlobal@idSWF@@QAA?AVidSWFScriptVar@@PBD@Z
// EA  : 0x82657398
// RVA : 0x00657398
// PDB : w:\tech5\engine\guis\swf\swf.h
// ========================================================================

idSWF *__fastcall idSWF::GetGlobal(idSWF *this, idSWFScriptVar *result, const char *name)
{
  idSWFScriptObject::Get((idSWFScriptObject *)this, result: (idSWFScriptVar *)result[8].value.i, name);
  return this;
}


// ========================================================================
// ?GetPrototype@idSWFScriptFunction_Object@idSWF@@UAAPAVidSWFScriptObject@@XZ
// EA  : 0x827764A0
// RVA : 0x007764A0
// PDB : w:\tech5\engine\guis\swf\swf.h
// ========================================================================

idSWFScriptObject *__fastcall idSWF::idSWFScriptFunction_Object::GetPrototype(idSWF::idSWFScriptFunction_Object *this)
{
  return &this->object;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_platform@idSWF@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x82779670
// RVA : 0x00779670
// PDB : w:\tech5\engine\guis\swf\swf.h
// ========================================================================

idSWF::idSWFScriptNativeVar_platform *__fastcall idSWF::idSWFScriptNativeVar_platform::Get(
        idSWF::idSWFScriptNativeVar_platform *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idStaticList<idSWFScriptVar,16> v7; // [sp+60h] [-C0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
  (*(void (__fastcall **)(idSWF::idSWFScriptNativeVar_platform *, int __struct_ptr, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)result->value.i + 4))(
    a1: this,
    a2: result->value.i,
    a3: object,
    a4: &v7);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7);
  return this;
}


// ========================================================================
// __unwind$230948
// EA  : 0x827796DC
// RVA : 0x007796DC
// PDB : w:\tech5\engine\guis\swf\swf.h
// ========================================================================

void _unwind_230948()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$230949
// EA  : 0x82779704
// RVA : 0x00779704
// PDB : w:\tech5\engine\guis\swf\swf.h
// ========================================================================

void _unwind_230949()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 308));
  }
}

