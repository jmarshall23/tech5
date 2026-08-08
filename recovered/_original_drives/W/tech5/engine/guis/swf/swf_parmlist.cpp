
// ========================================================================
// ?Append@idSWFParmList@@QAAXABVidSWFScriptVar@@@Z
// EA  : 0x8277DAD0
// RVA : 0x0077DAD0
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, const idSWFScriptVar *other)
{
  idSWFScriptVar *v3; // r3

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::operator=(this: v3, other);
}


// ========================================================================
// ?Append@idSWFParmList@@QAAXPAVidSWFScriptObject@@@Z
// EA  : 0x8277DB08
// RVA : 0x0077DB08
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, idSWFScriptObject *o)
{
  idSWFScriptVar *v3; // r30

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::Free(this: v3);
  if ( o != nullptr )
  {
    v3->value.i = (int)o;
    v3->type = SWF_VAR_OBJECT;
    ++o->refCount;
  }
  else
  {
    v3->type = SWF_VAR_NULL;
  }
}


// ========================================================================
// ?Append@idSWFParmList@@QAAXPBD@Z
// EA  : 0x8277DB70
// RVA : 0x0077DB70
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, const char *s)
{
  idSWFScriptVar *v3; // r3

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::SetString(this: v3, s);
}


// ========================================================================
// ?Append@idSWFParmList@@QAAXABVidStr@@@Z
// EA  : 0x8277DBA8
// RVA : 0x0077DBA8
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, const idStr *s)
{
  idSWFScriptVar *v3; // r30

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::Free(this: v3);
  v3->type = SWF_VAR_STRING;
  v3->value.i = (int)idSWFScriptString::Alloc(s);
}


// ========================================================================
// ?Append@idSWFParmList@@QAAXM@Z
// EA  : 0x8277DBF8
// RVA : 0x0077DBF8
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, double f)
{
  idSWFScriptVar *v3; // r31

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::Free(this: v3);
  v3->value.f = f;
  v3->type = SWF_VAR_FLOAT;
}


// ========================================================================
// ?Append@idSWFParmList@@QAAXH@Z
// EA  : 0x8277DC40
// RVA : 0x0077DC40
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, idSWFScriptVar::swfScriptVarValue_t i)
{
  idSWFScriptVar *v3; // r30

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::Free(this: v3);
  v3->value = i;
  v3->type = SWF_VAR_INTEGER;
}


// ========================================================================
// ?Append@idSWFParmList@@QAAX_N@Z
// EA  : 0x8277DC88
// RVA : 0x0077DC88
// PDB : w:\tech5\engine\guis\swf\swf_parmlist.cpp
// ========================================================================

void __fastcall idSWFParmList::Append(idSWFParmList *this, bool b)
{
  idSWFScriptVar *v3; // r30

  v3 = idList<idSWFScriptVar,5>::Alloc(this: &this->idStaticList<idSWFScriptVar,16>);
  idSWFScriptVar::Free(this: v3);
  v3->value.b = b;
  v3->type = SWF_VAR_BOOL;
}

