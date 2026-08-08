
// ========================================================================
// ??BcvarString_@@QBA?AVssString@@XZ
// EA  : 0x82EEAD78
// RVA : 0x00EEAD78
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

cvarString_ *__fastcall cvarString_::operator ssString(cvarString_ *this, ssString *result)
{
  char *v3; // r30

  v3 = (char *)gameInterface->GetCVarString(this: gameInterface, a2: result->alloced, a3: result->threadId);
  ssString::Init((ssString *)this);
  ssString::operator=((ssString *)this, text: v3);
  return this;
}


// ========================================================================
// ?RegisterCVar@cvarString_@@EAAXXZ
// EA  : 0x82EEADF0
// RVA : 0x00EEADF0
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

void __fastcall cvarString_::RegisterCVar(cvarString_ *this)
{
  ssString v1; // [sp+50h] [-30h] BYREF
  ssString v2; // [sp+60h] [-20h] BYREF

  cvarString_::operator ssString(this: (cvarString_ *)&v2, result: (ssString *)this);
  ssString::Init(this: &v1);
  ssString::operator=(this: &v1, text: &v2);
  ssString::Empty(this: &v1);
  ssString::Empty(this: &v2);
}


// ========================================================================
// __unwind$19311
// EA  : 0x82EEAE48
// RVA : 0x00EEAE48
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

void _unwind_19311()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 96));
}


// ========================================================================
// ??0cvarInt_@@QAA@PBDH@Z
// EA  : 0x82EEB7E8
// RVA : 0x00EEB7E8
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

cvarInt_ *__fastcall cvarInt_::cvarInt_(cvarInt_ *this, const char *name_, int default_)
{
  cvarInt_ *v3; // r31

  this->name = name_;
  this->defValue = default_;
  v3 = this;
  this->__vftable = (cvarInt__vtbl *)&cvarInt_::`vftable';
  if ( gameInterface != nullptr )
  {
    cvarInt_::RegisterCVar(this);
    return v3;
  }
  else
  {
    this->nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = this;
  }
  return this;
}


// ========================================================================
// ?RegisterCVar@cvarInt_@@EAAXXZ
// EA  : 0x82EEB868
// RVA : 0x00EEB868
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

void __fastcall cvarInt_::RegisterCVar(cvarInt_ *this)
{
  gameInterface->GetCVarInteger(this: gameInterface, a2: this->name, a3: this->defValue);
}


// ========================================================================
// ?RegisterStaticCVars@cvar_@@SAXXZ
// EA  : 0x82EECEE0
// RVA : 0x00EECEE0
// PDB : w:\tech5\tungsten\superscript\lib\cvars.h
// ========================================================================

static void __fastcall cvar_::RegisterStaticCVars()
{
  cvar_ *i; // r31

  for ( i = cvar_::staticCVars; i != nullptr; i = i->nextStaticCVar )
    i->RegisterCVar(this: i);
}

