
// ========================================================================
// ??1swfNamedVar_t@idSWFScriptObject@@QAA@XZ
// EA  : 0x8278AF78
// RVA : 0x0078AF78
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::swfNamedVar_t::~swfNamedVar_t(idSWFScriptObject::swfNamedVar_t *this)
{
  idSWFScriptVar::Free(this: &this->value);
}


// ========================================================================
// ?PrintToConsole@idSWFScriptObject@@QBAXXZ
// EA  : 0x8278AF88
// RVA : 0x0078AF88
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::PrintToConsole(idSWFScriptObject *this)
{
  idSWFScriptObject::swfObjectData_t v2; // r11
  const char *v3; // r6
  idSWFScriptObject::swfObjectData_t v4; // r11
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  int v8; // r11
  va *v9; // r26
  int v10; // r30
  int v11; // r29
  idSWFScriptObject::swfNamedVar_t *v12; // r28
  idStr *v13; // r11
  idSWFScriptVar *p_value; // r3
  char *data; // r27
  const char *str; // r28
  const char *v17; // r3
  int v18; // [sp+8h] [-10B8h]
  int v19; // [sp+Ch] [-10B4h]
  int v20; // [sp+10h] [-10B0h]
  int v21; // [sp+14h] [-10ACh]
  int v22; // [sp+18h] [-10A8h]
  int v23; // [sp+1Ch] [-10A4h]
  int num; // [sp+50h] [-1070h]
  int v25; // [sp+50h] [-1070h]
  idStr v26; // [sp+60h] [-1060h] BYREF
  va v27; // [sp+80h] [-1040h] BYREF

  if ( this->objectType == SWF_OBJECT_SPRITE )
  {
    v2.sprite = (idSWFSpriteInstance *)this->data;
    if ( v2.sprite != nullptr )
    {
      if ( v2.sprite->isPlaying )
        v3 = "playing";
      else
        v3 = "stopped";
      idLib::Printf(fmt: "Sprite '%s' on frame %d (%s)\n", v2.sprite->name.str, v2.sprite->currentFrame, v3);
    }
  }
  if ( this->objectType == SWF_OBJECT_TEXT )
  {
    v4.sprite = (idSWFSpriteInstance *)this->data;
    if ( v4.sprite != nullptr )
      idLib::Printf(
        fmt: "Text '%s': %s\n",
        (const char *)v4.sprite->itemIndex,
        *(const char **)&v4.sprite->materialWidth);
  }
  num = this->variables.num;
  if ( num > 0 )
  {
    idLib::Printf(fmt: "%d children:\n", num);
    LODWORD(v7) = 0;
    LODWORD(v6) = 0;
    v25 = this->variables.num;
    HIDWORD(v6) = v25;
    if ( v25 > 0 )
    {
      HIDWORD(v5) = &this->variables.list->name;
      do
      {
        LODWORD(v5) = *(_DWORD *)HIDWORD(v5);
        v8 = 0;
        if ( **(_BYTE **)HIDWORD(v5) != 0 )
        {
          do
            ++v8;
          while ( *(_BYTE *)(v8 + v5) != 0 );
        }
        if ( (int)v7 < v8 )
          LODWORD(v7) = v8;
        LODWORD(v6) = v6 + 1;
        HIDWORD(v5) += 28;
      }
      while ( (int)v6 < v25 );
    }
    HIDWORD(v7) = v7 + 2;
    v9 = va::va(
           this: &v27,
           fmt: "%%-%ds %%-10s %%-s\n",
           a3: v7,
           a4: v6,
           a5: v5,
           a6: v18,
           a7: v19,
           a8: v20,
           a9: v21,
           a10: v22,
           a11: v23);
    idLib::Printf(fmt: v9->buffer, "Name", "Type", "Value");
    idLib::Printf(fmt: "------------------------------------------------------------\n");
    v10 = 0;
    if ( this->variables.num > 0 )
    {
      v11 = 0;
      do
      {
        v12 = &this->variables.list[v11];
        v13 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v26, result: (idStr *)&v12->value);
        p_value = &v12->value;
        data = v13->data;
        str = v12->name.str;
        v17 = idSWFScriptVar::TypeOf(this: p_value);
        idLib::Printf(fmt: v9->buffer, str, v17, data);
        idStr::FreeData(this: &v26);
        ++v10;
        ++v11;
      }
      while ( v10 < this->variables.num );
    }
  }
}


// ========================================================================
// __unwind$220356
// EA  : 0x8278B150
// RVA : 0x0078B150
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_220356()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 96));
}


// ========================================================================
// ?Clear@idSWFScriptObject@@QAAXXZ
// EA  : 0x8278B178
// RVA : 0x0078B178
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::Clear(idSWFScriptObject *this)
{
  idSWFScriptObject::swfNamedVar_t *list; // r3
  __int16 *p_granularity; // r11
  int i; // ctr

  if ( this->variables.listStatic == 0 || this->variables.listStatic == 2 )
  {
    list = this->variables.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFScriptObject::swfNamedVar_t>(ptr: list, num: this->variables.size);
    this->variables.list = nullptr;
    this->variables.size = 0;
  }
  this->variables.num = 0;
  p_granularity = &this->variables.granularity;
  for ( i = 16; i != 0; --i )
  {
    p_granularity += 2;
    *(_DWORD *)p_granularity = -1;
  }
}


// ========================================================================
// ??0idSWFScriptObject@@QAA@XZ
// EA  : 0x8278B270
// RVA : 0x0078B270
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::idSWFScriptObject(idSWFScriptObject *this)
{
  this->refCount = 1;
  this->variables.granularity = 0;
  this->variables.listStatic = 0;
  this->variables.memTag = 72;
  this->variables.list = nullptr;
  this->variables.size = 0;
  this->variables.num = 0;
  this->prototype = nullptr;
  this->objectType = SWF_OBJECT_OBJECT;
  this->data.sprite = nullptr;
  idSWFScriptObject::Clear(this);
  return this;
}


// ========================================================================
// __unwind$220957
// EA  : 0x8278B2EC
// RVA : 0x0078B2EC
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_220957()
{
  int v0; // r12

  idList<idSWFScriptObject::swfNamedVar_t,72>::Clear(this: (idList<idSWFScriptObject::swfNamedVar_t,72> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??1idSWFScriptObject@@QAA@XZ
// EA  : 0x8278B320
// RVA : 0x0078B320
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::~idSWFScriptObject(idSWFScriptObject *this)
{
  idSWFScriptObject *prototype; // r3
  idSWFScriptObject::swfNamedVar_t *list; // r3

  prototype = this->prototype;
  if ( prototype != nullptr )
    idSWFScriptObject::Release(this: prototype);
  if ( this->variables.listStatic == 0 || this->variables.listStatic == 2 )
  {
    list = this->variables.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFScriptObject::swfNamedVar_t>(ptr: list, num: this->variables.size);
    this->variables.list = nullptr;
    this->variables.size = 0;
  }
  this->variables.num = 0;
}


// ========================================================================
// __unwind$220988
// EA  : 0x8278B3A8
// RVA : 0x0078B3A8
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_220988()
{
  int v0; // r12

  idList<idSWFScriptObject::swfNamedVar_t,72>::Clear(this: (idList<idSWFScriptObject::swfNamedVar_t,72> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??4swfNamedVar_t@idSWFScriptObject@@QAAAAU01@ABU01@@Z
// EA  : 0x8278B3D8
// RVA : 0x0078B3D8
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject::swfNamedVar_t *__fastcall idSWFScriptObject::swfNamedVar_t::operator=(
        idSWFScriptObject::swfNamedVar_t *this,
        const idSWFScriptObject::swfNamedVar_t *other)
{
  if ( other != this )
  {
    this->index = other->index;
    this->name.str = other->name.str;
    this->hashNext = other->hashNext;
    idSWFScriptVar::operator=(this: &this->value, other: &other->value);
    this->native = other->native;
    this->flags = other->flags;
  }
  return this;
}


// ========================================================================
// ?GetVariable@idSWFScriptObject@@AAAPAUswfNamedVar_t@1@H_N@Z
// EA  : 0x8278B650
// RVA : 0x0078B650
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idAtomicString *__fastcall idSWFScriptObject::GetVariable(idSWFScriptObject *this, const char *index, bool create)
{
  int num; // r9
  int v6; // r10
  idSWFScriptObject::swfNamedVar_t *list; // r8
  int v8; // r11
  idList<idSWFScriptObject::swfNamedVar_t,72> *p_variables; // r30
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r11
  __int64 v13; // r10
  idAtomicString *v14; // r31
  va *v16; // r3
  const char *str; // r9
  char v18; // r11
  char i; // r8
  int v20; // r11
  int v21; // [sp+8h] [-1078h]
  int v22; // [sp+Ch] [-1074h]
  int v23; // [sp+10h] [-1070h]
  int v24; // [sp+14h] [-106Ch]
  int v25; // [sp+18h] [-1068h]
  int v26; // [sp+1Ch] [-1064h]
  va v27; // [sp+50h] [-1030h] BYREF

  num = this->variables.num;
  v6 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    if ( create )
    {
      p_variables = &this->variables;
      idList<idSWFScriptObject::swfNamedVar_t,72>::PreAllocateWithGranularity(
        this: &this->variables,
        newSize: this->variables.num + 1);
      v12 = this->variables.num;
      LODWORD(v13) = this->variables.size;
      HIDWORD(v13) = p_variables->list;
      if ( v12 >= (int)v13 )
      {
        v14 = (idAtomicString *)(28 * v13 + HIDWORD(v13) - 28);
      }
      else
      {
        LODWORD(v13) = 28 * v12;
        v14 = (idAtomicString *)(28 * v12 + HIDWORD(v13));
        this->variables.num = v12 + 1;
      }
      v14->str = index;
      v14[6].str = nullptr;
      HIDWORD(v11) = index;
      v16 = va::va(
              this: &v27,
              fmt: "%d",
              a3: v11,
              a4: v10,
              a5: v13,
              a6: v21,
              a7: v22,
              a8: v23,
              a9: v24,
              a10: v25,
              a11: v26);
      idAtomicString::Set(this: v14 + 2, str_: v16->buffer);
      str = v14[2].str;
      v14[5].str = nullptr;
      v18 = 0;
      for ( i = *str; *str != 0; i = *str )
      {
        ++str;
        v18 = 31 * v18 + i;
      }
      v20 = 4 * ((v18 & 0xF) + 5);
      v14[1].str = *(const char **)((char *)&this->refCount + v20);
      *(int *)((char *)&this->refCount + v20) = this->variables.num - 1;
      return v14;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    list = this->variables.list;
    v8 = 0;
    while ( (const char *)list[v8].index != index )
    {
      ++v6;
      ++v8;
      if ( v6 >= num )
        goto LABEL_5;
    }
    return (idAtomicString *)&list[v6];
  }
}


// ========================================================================
// ?GetVariable@idSWFScriptObject@@AAAPAUswfNamedVar_t@1@PBD_N@Z
// EA  : 0x8278B7A8
// RVA : 0x0078B7A8
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject::swfNamedVar_t *__fastcall idSWFScriptObject::GetVariable(
        idSWFScriptObject *this,
        char *name,
        bool create)
{
  char v3; // r8
  char v7; // r11
  const char *v8; // r9
  int v9; // r27
  int hashNext; // r11
  int v11; // r31
  const char *str; // r3
  int v13; // r3
  char v14; // r11
  idSWFScriptObject::swfNamedVar_t *v15; // r11
  bool v16; // zf
  idSWFScriptObject *prototype; // r3
  idSWFScriptObject::swfNamedVar_t *result; // r3
  int num; // r11
  int size; // r10
  idSWFScriptObject::swfNamedVar_t *list; // r9
  idAtomicString *v22; // r31
  int v23; // r3

  v3 = *name;
  v7 = 0;
  if ( *name != 0 )
  {
    v8 = name;
    do
    {
      ++v8;
      v7 = 31 * v7 + v3;
      v3 = *v8;
    }
    while ( *v8 != 0 );
  }
  v9 = 4 * ((v7 & 0xF) + 5);
  hashNext = *(int *)((char *)&this->refCount + v9);
  if ( hashNext < 0 )
  {
LABEL_10:
    prototype = this->prototype;
    if ( prototype == nullptr
      || (result = idSWFScriptObject::GetVariable(this: prototype, name, create: false)) == nullptr
      || result->native == nullptr && create )
    {
      if ( create )
      {
        idList<idSWFScriptObject::swfNamedVar_t,72>::PreAllocateWithGranularity(
          this: &this->variables,
          newSize: this->variables.num + 1);
        num = this->variables.num;
        size = this->variables.size;
        list = this->variables.list;
        if ( num >= size )
        {
          v22 = (idAtomicString *)&list[size - 1];
        }
        else
        {
          v22 = (idAtomicString *)&list[num];
          this->variables.num = num + 1;
        }
        v22[6].str = nullptr;
        v23 = atol(nptr: name);
        v22->str = (const char *)v23;
        if ( v23 == 0 && idStr::Cmp(s1: name, s2: "0") != 0 )
          v22->str = (const char *)-1;
        idAtomicString::Set(this: v22 + 2, str_: name);
        v22[5].str = nullptr;
        v22[1].str = *(const char **)((char *)&this->refCount + v9);
        *(int *)((char *)&this->refCount + v9) = this->variables.num - 1;
        return (idSWFScriptObject::swfNamedVar_t *)v22;
      }
      else
      {
        return nullptr;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v11 = hashNext;
      str = this->variables.list[hashNext].name.str;
      if ( str == name || (v13 = idStr::Cmp(s1: str, s2: name), v14 = 0, v13 == 0) )
        v14 = 1;
      v16 = v14 != 0;
      v15 = this->variables.list;
      if ( v16 )
        return &v15[v11];
      hashNext = v15[v11].hashNext;
      if ( hashNext < 0 )
        goto LABEL_10;
    }
  }
  return result;
}


// ========================================================================
// ?MakeArray@idSWFScriptObject@@QAAXXZ
// EA  : 0x8278B980
// RVA : 0x0078B980
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::MakeArray(idSWFScriptObject *this)
{
  idSWFScriptObject::swfNamedVar_t *Variable; // r30
  idSWFScriptVar v2[6]; // [sp+50h] [-30h] BYREF

  this->objectType = SWF_OBJECT_ARRAY;
  Variable = idSWFScriptObject::GetVariable(this, name: "length", create: true);
  v2[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v2);
  v2[0].type = SWF_VAR_INTEGER;
  v2[0].value.i = 0;
  idSWFScriptVar::operator=(this: &Variable->value, other: v2);
  idSWFScriptVar::Free(this: v2);
  Variable->flags = 4;
}


// ========================================================================
// __unwind$221572
// EA  : 0x8278B9EC
// RVA : 0x0078B9EC
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221572()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?HasProperty@idSWFScriptObject@@QAA_NPBD@Z
// EA  : 0x8278BA18
// RVA : 0x0078BA18
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

BOOL __fastcall idSWFScriptObject::HasProperty(idSWFScriptObject *this, char *name)
{
  return idSWFScriptObject::GetVariable(this, name, create: false) != nullptr;
}


// ========================================================================
// ?HasValidProperty@idSWFScriptObject@@QAA_NPBD@Z
// EA  : 0x8278BA50
// RVA : 0x0078BA50
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

BOOL __fastcall idSWFScriptObject::HasValidProperty(idSWFScriptObject *this, char *name)
{
  idSWFScriptObject::swfNamedVar_t *Variable; // r3
  idSWFScriptNativeVariable *native; // r11
  idSWFScriptVar::swfScriptVarType type; // r11
  idSWFScriptVar v6; // [sp+50h] [-20h] BYREF

  Variable = idSWFScriptObject::GetVariable(this, name, create: false);
  if ( Variable == nullptr )
    return false;
  native = Variable->native;
  if ( native != nullptr )
  {
    ((void (__fastcall *)(idSWFScriptVar *))native->Get)(a1: &v6);
    if ( v6.type != SWF_VAR_NULL && v6.type != SWF_VAR_UNDEF )
    {
      idSWFScriptVar::Free(this: &v6);
      return true;
    }
    idSWFScriptVar::Free(this: &v6);
    return false;
  }
  type = Variable->value.type;
  return type != SWF_VAR_NULL && type != SWF_VAR_UNDEF;
}


// ========================================================================
// __unwind$221608
// EA  : 0x8278BB08
// RVA : 0x0078BB08
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221608()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?Get@idSWFScriptObject@@QAA?AVidSWFScriptVar@@PBD@Z
// EA  : 0x8278BB30
// RVA : 0x0078BB30
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::Get(idSWFScriptObject *this, idSWFScriptObject *result, char *name)
{
  idSWFScriptObject::swfNamedVar_t *Variable; // r3
  idSWFScriptNativeVariable *native; // r11

  Variable = idSWFScriptObject::GetVariable(this: result, name, create: false);
  if ( Variable != nullptr )
  {
    native = Variable->native;
    if ( native != nullptr )
      ((void (__fastcall *)(idSWFScriptObject *))native->Get)(a1: this);
    else
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, other: &Variable->value);
  }
  else
  {
    this->refCount = 4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptObject@@QAA?AVidSWFScriptVar@@H@Z
// EA  : 0x8278BBC8
// RVA : 0x0078BBC8
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::Get(
        idSWFScriptObject *this,
        idSWFScriptObject *result,
        const char *index)
{
  idAtomicString *Variable; // r3
  const char *str; // r11

  Variable = idSWFScriptObject::GetVariable(this: result, index, create: false);
  if ( Variable != nullptr )
  {
    str = Variable[5].str;
    if ( str != nullptr )
      (*(void (__fastcall **)(idSWFScriptObject *))(*(_DWORD *)str + 12))(a1: this);
    else
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, other: (const idSWFScriptVar *)&Variable[3]);
  }
  else
  {
    this->refCount = 4;
  }
  return this;
}


// ========================================================================
// ?GetSprite@idSWFScriptObject@@QAAPAVidSWFSpriteInstance@@PBD@Z
// EA  : 0x8278BC68
// RVA : 0x0078BC68
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFScriptObject::GetSprite(idSWFScriptObject *this, char *name)
{
  idSWFSpriteInstance *v2; // r30
  idSWFScriptVar v4; // [sp+50h] [-20h] BYREF

  idSWFScriptObject::Get(this: (idSWFScriptObject *)&v4, result: this, name);
  v2 = idSWFScriptVar::ToSprite(this: &v4);
  idSWFScriptVar::Free(this: &v4);
  return v2;
}


// ========================================================================
// __unwind$221688
// EA  : 0x8278BCC0
// RVA : 0x0078BCC0
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221688()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetScriptObject@idSWFScriptObject@@QAAPAV1@PBD@Z
// EA  : 0x8278BCF0
// RVA : 0x0078BCF0
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::GetScriptObject(idSWFScriptObject *this, char *name)
{
  idSWFScriptVar::swfScriptVarValue_t v2; // r30
  idSWFScriptVar v4; // [sp+50h] [-20h] BYREF

  idSWFScriptObject::Get(this: (idSWFScriptObject *)&v4, result: this, name);
  if ( v4.type == SWF_VAR_OBJECT )
  {
    LODWORD(v2.f) = v4.value;
    idSWFScriptVar::Free(this: &v4);
    return (idSWFScriptObject *)v2.i;
  }
  else
  {
    idSWFScriptVar::Free(this: &v4);
    return nullptr;
  }
}


// ========================================================================
// __unwind$221738
// EA  : 0x8278BD5C
// RVA : 0x0078BD5C
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221738()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetText@idSWFScriptObject@@QAAPAVidSWFTextInstance@@PBD@Z
// EA  : 0x8278BD90
// RVA : 0x0078BD90
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFTextInstance *__fastcall idSWFScriptObject::GetText(idSWFScriptObject *this, char *name)
{
  int v2; // r30
  idSWFScriptVar v4; // [sp+50h] [-20h] BYREF

  idSWFScriptObject::Get(this: (idSWFScriptObject *)&v4, result: this, name);
  if ( v4.type == SWF_VAR_OBJECT )
  {
    if ( *(_DWORD *)(v4.value.i + 88) == 3 )
      v2 = *(_DWORD *)(v4.value.i + 92);
    else
      v2 = 0;
    idSWFScriptVar::Free(this: &v4);
    return (idSWFTextInstance *)v2;
  }
  else
  {
    idSWFScriptVar::Free(this: &v4);
    return nullptr;
  }
}


// ========================================================================
// __unwind$221802
// EA  : 0x8278BE14
// RVA : 0x0078BE14
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221802()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?Set@idSWFScriptObject@@QAAXPBDABVidSWFScriptVar@@@Z
// EA  : 0x8278BE48
// RVA : 0x0078BE48
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::Set(idSWFScriptObject *this, char *name, idSWFScriptVar *value)
{
  int v6; // r26
  int v7; // r28
  int v8; // r29
  __int16 *p_granularity; // r11
  int i; // ctr
  int v11; // r5
  int v12; // r7
  char v13; // r11
  idSWFScriptObject::swfNamedVar_t *v14; // r6
  const char *str; // r9
  char j; // r8
  int v17; // r11
  int v18; // r3
  int v19; // r28
  idSWFScriptVar *p_value; // r29
  idSWFScriptVar *v21; // r3
  idSWFScriptObject::swfNamedVar_t *Variable; // r3
  idSWFScriptNativeVariable *native; // r11
  idSWFScriptVar v24[10]; // [sp+50h] [-50h] BYREF

  if ( this->objectType == SWF_OBJECT_ARRAY )
  {
    if ( idStr::Cmp(s1: name, s2: "length") != 0 )
    {
      v18 = atol(nptr: name);
      v19 = v18;
      if ( v18 > 0 || v18 == 0 && idStr::Cmp(s1: name, s2: "0") == 0 )
      {
        p_value = &idSWFScriptObject::GetVariable(this, name: "length", create: true)->value;
        if ( idSWFScriptVar::ToInteger(this: p_value) <= v19 )
        {
          v21 = idSWFScriptVar::idSWFScriptVar(this: v24, i: (idSWFScriptVar::swfScriptVarValue_t *)(v19 + 1));
          idSWFScriptVar::operator=(this: p_value, other: v21);
          idSWFScriptVar::Free(this: v24);
        }
      }
    }
    else
    {
      v6 = idSWFScriptVar::ToInteger(this: value);
      v7 = 0;
      if ( this->variables.num > 0 )
      {
        v8 = 0;
        do
        {
          if ( this->variables.list[v8].index >= v6 )
          {
            idList<idSWFScriptObject::swfNamedVar_t,72>::RemoveIndexFast(this: &this->variables, index: v7--);
            --v8;
          }
          ++v7;
          ++v8;
        }
        while ( v7 < this->variables.num );
      }
      p_granularity = &this->variables.granularity;
      for ( i = 16; i != 0; --i )
      {
        p_granularity += 2;
        *(_DWORD *)p_granularity = -1;
      }
      v11 = 0;
      if ( this->variables.num > 0 )
      {
        v12 = 0;
        do
        {
          v13 = 0;
          v14 = &this->variables.list[v12];
          str = v14->name.str;
          for ( j = *str; *str != 0; j = *str )
          {
            ++str;
            v13 = 31 * v13 + j;
          }
          ++v12;
          v17 = 4 * ((v13 & 0xF) + 5);
          v14->hashNext = *(int *)((char *)&this->refCount + v17);
          *(int *)((char *)&this->refCount + v17) = v11++;
        }
        while ( v11 < this->variables.num );
      }
    }
  }
  Variable = idSWFScriptObject::GetVariable(this, name, create: true);
  native = Variable->native;
  if ( native != nullptr )
  {
    ((void (*)(void))native->Set)();
  }
  else if ( (Variable->flags & 2) == 0 )
  {
    idSWFScriptVar::operator=(this: &Variable->value, other: value);
  }
}


// ========================================================================
// __unwind$221893_0
// EA  : 0x8278C05C
// RVA : 0x0078C05C
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221893_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 160 + 80));
}


// ========================================================================
// ?Set@idSWFScriptObject@@QAAXHABVidSWFScriptVar@@@Z
// EA  : 0x8278C090
// RVA : 0x0078C090
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::Set(idSWFScriptObject *this, int index, const idSWFScriptVar *value)
{
  idSWFScriptVar *p_value; // r28
  idSWFScriptVar *v7; // r3
  idAtomicString *Variable; // r3
  const char *str; // r11
  idSWFScriptVar v10[8]; // [sp+50h] [-40h] BYREF

  if ( index >= 0 )
  {
    if ( this->objectType == SWF_OBJECT_ARRAY )
    {
      p_value = &idSWFScriptObject::GetVariable(this, name: "length", create: true)->value;
      if ( idSWFScriptVar::ToInteger(this: p_value) <= index )
      {
        v7 = idSWFScriptVar::idSWFScriptVar(this: v10, i: (idSWFScriptVar::swfScriptVarValue_t *)(index + 1));
        idSWFScriptVar::operator=(this: p_value, other: v7);
        idSWFScriptVar::Free(this: v10);
      }
    }
    Variable = idSWFScriptObject::GetVariable(this, (const char *)index, create: true);
    str = Variable[5].str;
    if ( str != nullptr )
    {
      (*(void (**)(void))(*(_DWORD *)str + 8))();
    }
    else if ( ((int)Variable[6].str & 2) == 0 )
    {
      idSWFScriptVar::operator=(this: (idSWFScriptVar *)&Variable[3], other: value);
    }
  }
  else if ( swf_debug.valueInteger != 0 )
  {
    idLib::Printf(fmt: "SWF: Trying to set a negative array index.\n");
  }
}


// ========================================================================
// __unwind$221955
// EA  : 0x8278C18C
// RVA : 0x0078C18C
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221955()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetNative@idSWFScriptObject@@QAAXPBDPAVidSWFScriptNativeVariable@@@Z
// EA  : 0x8278C1B8
// RVA : 0x0078C1B8
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __fastcall idSWFScriptObject::SetNative(idSWFScriptObject *this, char *name, idSWFScriptNativeVariable *native)
{
  idSWFScriptObject::swfNamedVar_t *Variable; // r3
  idSWFScriptObject::swfNamedVar_t *v5; // r31

  Variable = idSWFScriptObject::GetVariable(this, name, create: true);
  Variable->native = native;
  v5 = Variable;
  Variable->flags = 4;
  if ( native->IsReadOnly(this: native) )
    v5->flags |= 2u;
}


// ========================================================================
// ?DefaultValue@idSWFScriptObject@@QAA?AVidSWFScriptVar@@_N@Z
// EA  : 0x8278C238
// RVA : 0x0078C238
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::DefaultValue(
        idSWFScriptObject *this,
        idSWFScriptObject *result,
        bool stringHint)
{
  int v3; // r27
  char **v6; // r28
  idSWFScriptObject::swfNamedVar_t *list; // r26
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idSWFScriptVar::swfScriptVarType objectType; // r11
  va *v12; // r3
  va *v13; // r3
  idSWFScriptVar::swfScriptVarValue_t v14; // r11
  va *v15; // r3
  va *v16; // r3
  const idStr *v17; // r29
  int v19; // [sp+8h] [-4158h]
  int v20; // [sp+Ch] [-4154h]
  int v21; // [sp+10h] [-4150h]
  int v22; // [sp+14h] [-414Ch]
  int v23; // [sp+18h] [-4148h]
  int v24; // [sp+1Ch] [-4144h]
  _DWORD v25[2]; // [sp+50h] [-4110h] BYREF
  idSWFScriptVar v26; // [sp+58h] [-4108h] BYREF
  idSWFScriptObject v27[2]; // [sp+60h] [-4100h] BYREF
  va v28; // [sp+120h] [-4040h] BYREF
  va v29; // [sp+1120h] [-3040h] BYREF
  va v30; // [sp+2120h] [-2040h] BYREF
  va v31; // [sp+3120h] [-1040h] BYREF

  v3 = 0;
  v25[0] = "toString";
  v25[1] = "valueOf";
  if ( !stringHint )
  {
    v25[0] = "valueOf";
    v25[1] = "toString";
  }
  v6 = (char **)v25;
  do
  {
    idSWFScriptObject::Get(this: v27, result, name: *v6);
    if ( v27[0].refCount == 7 )
    {
      list = v27[0].variables.list;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v27[0].variablesHash[7]);
      (*(void (__fastcall **)(idSWFScriptVar *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, int *))(list->index + 4))(
        a1: &v26,
        a2: list,
        a3: result,
        a4: &v27[0].variablesHash[7]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v27[0].variablesHash[7]);
      if ( v26.type != SWF_VAR_OBJECT && v26.type != SWF_VAR_FUNCTION )
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, other: &v26);
        idSWFScriptVar::Free(this: &v26);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)v27);
        return this;
      }
      idSWFScriptVar::Free(this: &v26);
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)v27);
    ++v3;
    ++v6;
  }
  while ( v3 < 2 );
  objectType = result->objectType;
  if ( (unsigned int)objectType > SWF_VAR_NULL )
  {
    this->refCount = 4;
    v17 = idStr::idStr(this: (idStr *)&v27[0].variables.granularity, text: "[unknown]");
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->refCount = 1;
    this->variables.list = (idSWFScriptObject::swfNamedVar_t *)idSWFScriptString::Alloc(s: v17);
    idStr::FreeData(this: (idStr *)&v27[0].variables.granularity);
  }
  else if ( objectType != SWF_VAR_STRINGID )
  {
    if ( objectType == SWF_VAR_STRING )
    {
      LODWORD(v8) = &swf_debugShowAddress;
      if ( swf_debugShowAddress.valueInteger != 0 )
      {
        HIDWORD(v10) = result;
        v13 = va::va(
                this: &v28,
                fmt: "[array:%p]",
                a3: v10,
                a4: v9,
                a5: v8,
                a6: v19,
                a7: v20,
                a8: v21,
                a9: v22,
                a10: v23,
                a11: v24);
        this->refCount = 4;
        idSWFScriptVar::SetString((idSWFScriptVar *)this, s: v13);
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "[array]");
      }
    }
    else if ( objectType == SWF_VAR_FLOAT )
    {
      *(idSWFSpriteInstance **)&v14.f = result->data.sprite;
      if ( v14.i != 0 )
      {
        LODWORD(v8) = &unk_821F0000;
        HIDWORD(v10) = *(_DWORD *)(v14.i + 60);
        v15 = va::va(
                this: &v29,
                fmt: "[sprite:%s]",
                a3: v10,
                a4: v9,
                a5: v8,
                a6: v19,
                a7: v20,
                a8: v21,
                a9: v22,
                a10: v23,
                a11: v24);
        this->refCount = 4;
        idSWFScriptVar::SetString((idSWFScriptVar *)this, s: v15);
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "[null sprite]");
      }
    }
    else
    {
      LODWORD(v8) = &swf_debugShowAddress;
      if ( swf_debugShowAddress.valueInteger != 0 )
      {
        HIDWORD(v10) = result;
        v16 = va::va(
                this: &v31,
                fmt: "[edittext:%p]",
                a3: v10,
                a4: v9,
                a5: v8,
                a6: v19,
                a7: v20,
                a8: v21,
                a9: v22,
                a10: v23,
                a11: v24);
        this->refCount = 4;
        idSWFScriptVar::SetString((idSWFScriptVar *)this, s: v16);
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "[edittext]");
      }
    }
  }
  else
  {
    LODWORD(v8) = &swf_debugShowAddress;
    if ( swf_debugShowAddress.valueInteger != 0 )
    {
      HIDWORD(v10) = result;
      v12 = va::va(
              this: &v30,
              fmt: "[object:%p]",
              a3: v10,
              a4: v9,
              a5: v8,
              a6: v19,
              a7: v20,
              a8: v21,
              a9: v22,
              a10: v23,
              a11: v24);
      this->refCount = 4;
      idSWFScriptVar::SetString((idSWFScriptVar *)this, s: v12);
    }
    else
    {
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: "[object]");
    }
  }
  return this;
}


// ========================================================================
// __unwind$221990
// EA  : 0x8278C4F4
// RVA : 0x0078C4F4
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221990()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 16736 + 96));
}


// ========================================================================
// __unwind$221991
// EA  : 0x8278C51C
// RVA : 0x0078C51C
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221991()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 16736 + 144));
}


// ========================================================================
// __unwind$221992
// EA  : 0x8278C544
// RVA : 0x0078C544
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_221992()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 16736 + 88));
}


// ========================================================================
// __unwind$222069
// EA  : 0x8278C56C
// RVA : 0x0078C56C
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 16736 + 112));
}


// ========================================================================
// ?GetNestedVar@idSWFScriptObject@@QAA?AVidSWFScriptVar@@PBD00000@Z
// EA  : 0x8278C5A0
// RVA : 0x0078C5A0
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::GetNestedVar(
        idSWFScriptObject *this,
        idSWFScriptObject *result,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4,
        const char *arg5,
        const char *arg6)
{
  int v10; // r30
  int v11; // r26
  const encounterGroupRole_t *p_granularity; // r27
  int v13; // r29
  idSWFScriptVar v15; // [sp+58h] [-A8h] BYREF
  idSWFScriptObject v16; // [sp+60h] [-A0h] BYREF

  v10 = 0;
  v16.variablesHash[8] = 0;
  *(_DWORD *)&v16.variables.granularity = arg1;
  v16.variablesHash[0] = (int)arg2;
  v16.variablesHash[1] = (int)arg3;
  v16.variablesHash[2] = (int)arg4;
  v16.variablesHash[3] = (int)arg5;
  v16.variablesHash[4] = (int)arg6;
  v16.variablesHash[9] = 6;
  v16.variablesHash[7] = (int)&v16.variablesHash[11];
  v16.variablesHash[10] = 66817;
  v11 = 0;
  p_granularity = (const encounterGroupRole_t *)&v16.variables.granularity;
  do
  {
    if ( *p_granularity == ROLE_NONE )
      break;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&v16.variablesHash[7],
      obj: p_granularity);
    ++v11;
    ++p_granularity;
  }
  while ( v11 < 6 );
  this->refCount = 4;
  v13 = 0;
  if ( v16.variablesHash[8] > 0 )
  {
    while ( 1 )
    {
      v15.type = v10 + v16.variablesHash[7];
      idSWFScriptObject::Get(this: &v16, result, name: *(char **)(v10 + v16.variablesHash[7]));
      if ( v13 == v16.variablesHash[8] - 1 )
      {
        idSWFScriptVar::operator=((idSWFScriptVar *)this, other: (const idSWFScriptVar *)&v16);
        goto LABEL_11;
      }
      if ( v16.refCount != 8 )
        break;
      result = (idSWFScriptObject *)v16.variables.list;
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v16);
      ++v13;
      v10 += 4;
      if ( v13 >= v16.variablesHash[8] )
        goto LABEL_12;
    }
    v15.type = SWF_VAR_UNDEF;
    idSWFScriptVar::operator=((idSWFScriptVar *)this, other: &v15);
    idSWFScriptVar::Free(this: &v15);
LABEL_11:
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v16);
  }
LABEL_12:
  if ( (LOBYTE(v16.variablesHash[10]) == 0 || LOBYTE(v16.variablesHash[10]) == 2) && v16.variablesHash[7] != 0 )
    idMem::Free(this: &mem, ptr: (void *)v16.variablesHash[7], align: ALIGN_16);
  return this;
}


// ========================================================================
// __unwind$222128
// EA  : 0x8278C718
// RVA : 0x0078C718
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222128()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$222129
// EA  : 0x8278C740
// RVA : 0x0078C740
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222129()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 256;
  if ( (*(_DWORD *)(v0 - 256 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 276));
  }
}


// ========================================================================
// __unwind$222132
// EA  : 0x8278C784
// RVA : 0x0078C784
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222132()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$222133
// EA  : 0x8278C7AC
// RVA : 0x0078C7AC
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222133()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// ?GetNestedObj@idSWFScriptObject@@QAAPAV1@PBD00000@Z
// EA  : 0x8278C7E0
// RVA : 0x0078C7E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::GetNestedObj(
        idSWFScriptObject *this,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4,
        const char *arg5,
        const char *arg6)
{
  idSWFScriptVar::swfScriptVarValue_t v8; // r30
  idSWFScriptVar v9; // [sp+50h] [-20h] BYREF

  idSWFScriptObject::GetNestedVar(this: (idSWFScriptObject *)&v9, result: this, arg1, arg2, arg3, arg4, arg5, arg6);
  if ( v9.type == SWF_VAR_OBJECT )
  {
    LODWORD(v8.f) = v9.value;
    idSWFScriptVar::Free(this: &v9);
    return (idSWFScriptObject *)v8.i;
  }
  else
  {
    idSWFScriptVar::Free(this: &v9);
    return nullptr;
  }
}


// ========================================================================
// __unwind$222276
// EA  : 0x8278C860
// RVA : 0x0078C860
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222276()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetNestedSprite@idSWFScriptObject@@QAAPAVidSWFSpriteInstance@@PBD00000@Z
// EA  : 0x8278C890
// RVA : 0x0078C890
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFScriptObject::GetNestedSprite(
        idSWFScriptObject *this,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4,
        const char *arg5,
        const char *arg6)
{
  idSWFSpriteInstance *v7; // r30
  idSWFScriptVar v9; // [sp+50h] [-20h] BYREF

  idSWFScriptObject::GetNestedVar(this: (idSWFScriptObject *)&v9, result: this, arg1, arg2, arg3, arg4, arg5, arg6);
  v7 = idSWFScriptVar::ToSprite(this: &v9);
  idSWFScriptVar::Free(this: &v9);
  return v7;
}


// ========================================================================
// __unwind$222303_0
// EA  : 0x8278C8FC
// RVA : 0x0078C8FC
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void _unwind_222303_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// `dynamic initializer for 'swf_debugShowAddress''
// EA  : 0x83341D20
// RVA : 0x01341D20
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_debugShowAddress__()
{
  idCVar::idCVar(
    this: &swf_debugShowAddress,
    name: "swf_debugShowAddress",
    value: "0",
    flags: 1,
    description: "shows addresses along with object types when they are serialized",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_debugShowAddress__);
}

