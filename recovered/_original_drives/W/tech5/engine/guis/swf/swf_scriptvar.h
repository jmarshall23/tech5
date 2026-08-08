
// ========================================================================
// ?Call@idSWFScriptFunction_changeTeam@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82561460
// RVA : 0x00561460
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idMainMenu::idSWFScriptFunction_changeTeam::Call(idSWFScriptVar *this)
{
  this->type = SWF_VAR_UNDEF;
  return this;
}


// ========================================================================
// ??4idSWFScriptVar@@QAAAAV0@ABV0@@Z
// EA  : 0x825923E8
// RVA : 0x005923E8
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::operator=(idSWFScriptVar *this, const idSWFScriptVar *other)
{
  idSWFScriptVar *v2; // r31
  idSWFScriptVar::swfScriptVarType type; // r11

  v2 = this;
  if ( this != other )
  {
    idSWFScriptVar::Free(this);
    v2->type = other->type;
    v2->value.i = other->value.i;
    type = other->type;
    if ( other->type == SWF_VAR_STRING )
    {
      ++*(_DWORD *)(other->value.i + 32);
    }
    else if ( type == SWF_VAR_OBJECT )
    {
      ++*(_DWORD *)other->value.i;
    }
    else if ( type == SWF_VAR_FUNCTION )
    {
      (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)other->value.i + 8))(a1: other->value.i);
    }
    return v2;
  }
  return this;
}


// ========================================================================
// ??1idSWFScriptVar@@QAA@XZ
// EA  : 0x82592498
// RVA : 0x00592498
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

// attributes: thunk
void __fastcall idSWFScriptVar::~idSWFScriptVar(idSWFScriptVar *this)
{
  idSWFScriptVar::Free(this);
}


// ========================================================================
// ?Alloc@idSWFScriptString@@SAPAV1@ABVidStr@@@Z
// EA  : 0x8264D9E0
// RVA : 0x0064D9E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptString *__fastcall idSWFScriptString::Alloc(const idStr *s)
{
  idStr *v2; // r3
  idStr *v3; // r30

  v2 = (idStr *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x24u,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  idStr::idStr(this: v2, text: s);
  v3[1].len = 1;
  return (idSWFScriptString *)v3;
}


// ========================================================================
// __unwind$224226
// EA  : 0x8264DA50
// RVA : 0x0064DA50
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void _unwind_224226()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?Free@idSWFScriptVar@@AAAXXZ
// EA  : 0x8264E7C0
// RVA : 0x0064E7C0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::Free(idSWFScriptVar *this)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  idStr *string; // r31
  int v4; // r11

  type = this->type;
  if ( this->type == SWF_VAR_STRING )
  {
    string = this->value.string;
    v4 = string[1].len - 1;
    string[1].len = v4;
    if ( v4 == 0 )
    {
      idStr::FreeData(this: string);
      idMem::Free(this: &mem, ptr: string, align: ALIGN_16);
    }
  }
  else if ( type == SWF_VAR_OBJECT )
  {
    idSWFScriptObject::Release(this: this->value.object);
  }
  else if ( type == SWF_VAR_FUNCTION )
  {
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)this->value.i + 12))(a1: this->value.i);
  }
  this->type = SWF_VAR_UNDEF;
}


// ========================================================================
// ?SetFunction@idSWFScriptVar@@QAAXPAVidSWFScriptFunction@@@Z
// EA  : 0x8264E868
// RVA : 0x0064E868
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetFunction(idSWFScriptVar *this, idSWFScriptFunction *f)
{
  idSWFScriptVar::Free(this);
  if ( f != nullptr )
  {
    this->value.i = (int)f;
    this->type = SWF_VAR_FUNCTION;
    f->AddRef(this: f);
  }
  else
  {
    this->type = SWF_VAR_NULL;
  }
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@PAVidSWFScriptFunction@@@Z
// EA  : 0x8264EB38
// RVA : 0x0064EB38
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, idSWFScriptFunction *nf)
{
  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  if ( nf != nullptr )
  {
    this->value.i = (int)nf;
    this->type = SWF_VAR_FUNCTION;
    nf->AddRef(this: nf);
  }
  else
  {
    this->type = SWF_VAR_NULL;
  }
  return this;
}


// ========================================================================
// ?SetString@idSWFScriptVar@@QAAXABVidStr@@@Z
// EA  : 0x8264EBB0
// RVA : 0x0064EBB0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetString(idSWFScriptVar *this, const idStr *s)
{
  idSWFScriptVar::Free(this);
  this->type = SWF_VAR_STRING;
  this->value.i = (int)idSWFScriptString::Alloc(s);
}


// ========================================================================
// ?SetString@idSWFScriptVar@@QAAXABVva@@@Z
// EA  : 0x8264EC08
// RVA : 0x0064EC08
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetString(idSWFScriptVar *this, const va *s)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  idSWFScriptVar::Free(this);
  this->type = SWF_VAR_STRING;
  idStr::idStr(this: v4, text: s);
  this->value.i = (int)idSWFScriptString::Alloc(s: v4);
  idStr::FreeData(this: v4);
}


// ========================================================================
// __unwind$225038
// EA  : 0x8264EC54
// RVA : 0x0064EC54
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void _unwind_225038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetInteger@idSWFScriptVar@@QAAXH@Z
// EA  : 0x8264EC80
// RVA : 0x0064EC80
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetInteger(idSWFScriptVar *this, idSWFScriptVar::swfScriptVarValue_t i)
{
  idSWFScriptVar::Free(this);
  this->value = i;
  this->type = SWF_VAR_INTEGER;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@VidStrId@@@Z
// EA  : 0x8264EDE0
// RVA : 0x0064EDE0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, idStrId *s)
{
  int index; // r30

  this->type = SWF_VAR_UNDEF;
  index = s->index;
  idSWFScriptVar::Free(this);
  this->value.i = index;
  this->type = SWF_VAR_STRINGID;
  return this;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@ABVidStr@@@Z
// EA  : 0x8264EE30
// RVA : 0x0064EE30
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, const idStr *s)
{
  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  this->type = SWF_VAR_STRING;
  this->value.i = (int)idSWFScriptString::Alloc(s);
  return this;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@H@Z
// EA  : 0x8264EE88
// RVA : 0x0064EE88
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, idSWFScriptVar::swfScriptVarValue_t i)
{
  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  this->value = i;
  this->type = SWF_VAR_INTEGER;
  return this;
}


// ========================================================================
// ?SetFloat@idSWFScriptVar@@QAAXM@Z
// EA  : 0x82657308
// RVA : 0x00657308
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetFloat(idSWFScriptVar *this, double f)
{
  idSWFScriptVar::Free(this);
  this->value.f = f;
  this->type = SWF_VAR_FLOAT;
}


// ========================================================================
// ?SetBool@idSWFScriptVar@@QAAX_N@Z
// EA  : 0x82657350
// RVA : 0x00657350
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetBool(idSWFScriptVar *this, bool b)
{
  idSWFScriptVar::Free(this);
  this->value.b = b;
  this->type = SWF_VAR_BOOL;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@PBD@Z
// EA  : 0x82657508
// RVA : 0x00657508
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, const char *s)
{
  const idStr *v3; // r29
  idStr v5[2]; // [sp+50h] [-40h] BYREF

  this->type = SWF_VAR_UNDEF;
  v3 = idStr::idStr(this: v5, text: s);
  idSWFScriptVar::Free(this);
  this->type = SWF_VAR_STRING;
  this->value.i = (int)idSWFScriptString::Alloc(s: v3);
  idStr::FreeData(this: v5);
  return this;
}


// ========================================================================
// __unwind$225474
// EA  : 0x82657560
// RVA : 0x00657560
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void _unwind_225474()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@M@Z
// EA  : 0x82657588
// RVA : 0x00657588
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, double f)
{
  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  this->value.f = f;
  this->type = SWF_VAR_FLOAT;
  return this;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@_N@Z
// EA  : 0x826575D8
// RVA : 0x006575D8
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, bool b)
{
  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  this->value.b = b;
  this->type = SWF_VAR_BOOL;
  return this;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@PAVidSWFScriptObject@@@Z
// EA  : 0x82777148
// RVA : 0x00777148
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, idSWFScriptObject *o)
{
  idSWFScriptVar *result; // r3

  this->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this);
  result = this;
  if ( o != nullptr )
  {
    this->value.i = (int)o;
    this->type = SWF_VAR_OBJECT;
    ++o->refCount;
  }
  else
  {
    this->type = SWF_VAR_NULL;
  }
  return result;
}


// ========================================================================
// ?SetString@idSWFScriptVar@@QAAXPBD@Z
// EA  : 0x8277DA08
// RVA : 0x0077DA08
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetString(idSWFScriptVar *this, const char *s)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  idSWFScriptVar::Free(this);
  this->type = SWF_VAR_STRING;
  idStr::idStr(this: v4, text: s);
  this->value.i = (int)idSWFScriptString::Alloc(s: v4);
  idStr::FreeData(this: v4);
}


// ========================================================================
// __unwind$219500
// EA  : 0x8277DA54
// RVA : 0x0077DA54
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void _unwind_219500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetString@idSWFScriptVar@@QAAXPAVidSWFScriptString@@@Z
// EA  : 0x8277DA80
// RVA : 0x0077DA80
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

void __fastcall idSWFScriptVar::SetString(idSWFScriptVar *this, idSWFScriptString *s)
{
  idSWFScriptVar::Free(this);
  this->value.i = (int)s;
  this->type = SWF_VAR_STRING;
  ++s->refCount;
}


// ========================================================================
// ??0idSWFScriptVar@@QAA@ABV0@@Z
// EA  : 0x82784D68
// RVA : 0x00784D68
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.h
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::idSWFScriptVar(idSWFScriptVar *this, const idSWFScriptVar *other)
{
  idSWFScriptVar::swfScriptVarType type; // r11

  *this = *other;
  type = other->type;
  if ( other->type == SWF_VAR_STRING )
  {
    ++*(_DWORD *)(other->value.i + 32);
  }
  else if ( type == SWF_VAR_OBJECT )
  {
    ++*(_DWORD *)other->value.i;
  }
  else if ( type == SWF_VAR_FUNCTION )
  {
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)other->value.i + 8))(a1: other->value.i);
  }
  return this;
}

