
// ========================================================================
// ?Find@idAIBlackboard@@QBAPAVidAIVar@@PBD@Z
// EA  : 0x82A3F988
// RVA : 0x00A3F988
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

idAIVar *__fastcall idAIBlackboard::Find(idAIBlackboard *this, const char *name)
{
  int v4; // r28
  int i; // r29
  idAIBlackboard::idVarInfo *v6; // r11
  idAIBlackboard::varArray_t varArray; // r10
  char *list; // r10
  int v9; // r11
  const char **v10; // r30

  v4 = 0;
  if ( this->vars.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = &this->vars.list[i];
    varArray = v6->varArray;
    if ( v6->varArray == VARRAY_STRING )
      break;
    if ( varArray == VARRAY_INT )
    {
      list = (char *)this->intVars.list;
      v9 = 40 * v6->index;
      goto LABEL_9;
    }
    if ( varArray == VARRAY_FLOAT )
    {
      list = (char *)this->floatVars.list;
      v9 = 40 * v6->index;
      goto LABEL_9;
    }
LABEL_11:
    if ( ++v4 >= this->vars.num )
      return nullptr;
  }
  list = (char *)this->stringVars.list;
  v9 = 68 * v6->index;
LABEL_9:
  v10 = (const char **)&list[v9];
  if ( &list[v9] == nullptr || idStr::Icmp(s1: name, s2: v10[2]) != 0 )
    goto LABEL_11;
  return (idAIVar *)v10;
}


// ========================================================================
// ?Shutdown@idAIBlackboard@@QAAXXZ
// EA  : 0x82A3FB30
// RVA : 0x00A3FB30
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void __fastcall idAIBlackboard::Shutdown(idAIBlackboard *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3

  if ( this->stringVars.listStatic == 0 || this->stringVars.listStatic == 2 )
  {
    list = (char *)this->stringVars.list;
    if ( this->stringVars.list != nullptr )
      idListArrayDelete<idAIVar_String>(ptr: list, num: this->stringVars.size);
    this->stringVars.list = nullptr;
    this->stringVars.size = 0;
  }
  this->stringVars.num = 0;
  if ( this->floatVars.listStatic == 0 || this->floatVars.listStatic == 2 )
  {
    v3 = (char *)this->floatVars.list;
    if ( v3 != nullptr )
      idListArrayDelete<idLayer>(ptr: v3, num: this->floatVars.size);
    this->floatVars.list = nullptr;
    this->floatVars.size = 0;
  }
  this->floatVars.num = 0;
  if ( this->intVars.listStatic == 0 || this->intVars.listStatic == 2 )
  {
    v4 = (char *)this->intVars.list;
    if ( v4 != nullptr )
      idListArrayDelete<idLayer>(ptr: v4, num: this->intVars.size);
    this->intVars.list = nullptr;
    this->intVars.size = 0;
  }
  this->intVars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vars);
}


// ========================================================================
// ??1idAIBlackboard@@QAA@XZ
// EA  : 0x82A3FE50
// RVA : 0x00A3FE50
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void __fastcall idAIBlackboard::~idAIBlackboard(idAIBlackboard *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vars);
  idStaticList<idAIVar_Int,8>::~idStaticList<idAIVar_Int,8>(this: &this->intVars);
  idStaticList<idAIVar_Float,8>::~idStaticList<idAIVar_Float,8>(this: &this->floatVars);
  idStaticList<idAIVar_String,8>::~idStaticList<idAIVar_String,8>(this: &this->stringVars);
}


// ========================================================================
// __unwind$489836
// EA  : 0x82A3FEA8
// RVA : 0x00A3FEA8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void _unwind_489836()
{
  int v0; // r12

  idStaticList<idAIVar_String,8>::~idStaticList<idAIVar_String,8>(this: *(idStaticList<idAIVar_String,8> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489837
// EA  : 0x82A3FED0
// RVA : 0x00A3FED0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void _unwind_489837()
{
  int v0; // r12

  idStaticList<idAIVar_Float,8>::~idStaticList<idAIVar_Float,8>(this: (idStaticList<idAIVar_Float,8> *)(*(_DWORD *)(v0 - 112 + 132) + 560));
}


// ========================================================================
// __unwind$489838
// EA  : 0x82A3FEFC
// RVA : 0x00A3FEFC
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void _unwind_489838()
{
  int v0; // r12

  idStaticList<idAIVar_Int,8>::~idStaticList<idAIVar_Int,8>(this: (idStaticList<idAIVar_Int,8> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                + 896));
}


// ========================================================================
// ?Init@idAIBlackboard@@QAAXXZ
// EA  : 0x82A3FF28
// RVA : 0x00A3FF28
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAIBlackboard::Init(idAIBlackboard *this)
{
  idAIBlackboard::Shutdown(this);
}


// ========================================================================
// ??0idAIBlackboard@@QAA@XZ
// EA  : 0x82A40160
// RVA : 0x00A40160
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

idAIBlackboard *__fastcall idAIBlackboard::idAIBlackboard(idAIBlackboard *this)
{
  int v2; // ctr
  __int16 *p_granularity; // r11

  idStaticList<idAIVar_String,8>::idStaticList<idAIVar_String,8>(this: &this->stringVars);
  idStaticList<idAIVar_Float,8>::idStaticList<idAIVar_Float,8>(this: &this->floatVars);
  idStaticList<idAIVar_Int,8>::idStaticList<idAIVar_Int,8>(this: &this->intVars);
  this->vars.size = 24;
  this->vars.granularity = 1;
  this->vars.list = this->vars.staticList;
  v2 = 24;
  this->vars.num = 0;
  p_granularity = &this->vars.granularity;
  this->vars.memTag = 5;
  this->vars.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(_DWORD *)p_granularity = -1;
    --v2;
  }
  while ( v2 != 0 );
  return this;
}


// ========================================================================
// __unwind$490190
// EA  : 0x82A401F8
// RVA : 0x00A401F8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void _unwind_490190()
{
  int v0; // r12

  idStaticList<idAIVar_String,8>::~idStaticList<idAIVar_String,8>(this: *(idStaticList<idAIVar_String,8> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490191
// EA  : 0x82A40220
// RVA : 0x00A40220
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

void _unwind_490191()
{
  int v0; // r12

  idStaticList<idAIVar_Float,8>::~idStaticList<idAIVar_Float,8>(this: (idStaticList<idAIVar_Float,8> *)(*(_DWORD *)(v0 - 112 + 132) + 560));
}


// ========================================================================
// ?AllocInt@idAIBlackboard@@QAAPAVidAIVar@@PBDH@Z
// EA  : 0x82A40A18
// RVA : 0x00A40A18
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

idAIVar_Int *__fastcall idAIBlackboard::AllocInt(idAIBlackboard *this, const char *name, int val)
{
  idAIVar_Int *v7; // r31
  idAIBlackboard::idVarInfo v8; // [sp+50h] [-30h] BYREF

  if ( this->intVars.num < this->intVars.size )
  {
    v7 = idList<idAIVar_Int,5>::Alloc(this: &this->intVars);
    v8.index = this->intVars.num - 1;
    v8.varArray = VARRAY_INT;
    idList<idAIBlackboard::idVarInfo,5>::Append(this: &this->vars, obj: &v8);
    v7->Set_2(this: v7, a2: val);
    idStr::operator=(this: &v7->name, text: name);
    return v7;
  }
  else
  {
    idLib::Warning(fmt: "Exceeded max number of AI blackboard integer variables: %d", 8);
    return nullptr;
  }
}


// ========================================================================
// ?AllocFloat@idAIBlackboard@@QAAPAVidAIVar@@PBDM@Z
// EA  : 0x82A40AB8
// RVA : 0x00A40AB8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

idAIVar_Float *__fastcall idAIBlackboard::AllocFloat(idAIBlackboard *this, const char *name, double val)
{
  idAIVar_Float *v7; // r31
  idAIBlackboard::idVarInfo v8; // [sp+50h] [-30h] BYREF

  if ( this->floatVars.num < this->floatVars.size )
  {
    v7 = idList<idAIVar_Float,5>::Alloc(this: &this->floatVars);
    v8.index = this->floatVars.num - 1;
    v8.varArray = VARRAY_FLOAT;
    idList<idAIBlackboard::idVarInfo,5>::Append(this: &this->vars, obj: &v8);
    v7->Set(this: v7, a2: val);
    idStr::operator=(this: &v7->name, text: name);
    return v7;
  }
  else
  {
    idLib::Warning(fmt: "Exceeded max number of AI blackboard float variables: %d", 8);
    return nullptr;
  }
}


// ========================================================================
// ?AllocString@idAIBlackboard@@QAAPAVidAIVar@@PBD0@Z
// EA  : 0x82A40B68
// RVA : 0x00A40B68
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.cpp
// ========================================================================

idAIVar_String *__fastcall idAIBlackboard::AllocString(idAIBlackboard *this, const char *name, const char *val)
{
  idAIVar_String *v7; // r31
  idAIBlackboard::idVarInfo v8; // [sp+50h] [-30h] BYREF

  if ( this->stringVars.num < this->stringVars.size )
  {
    v7 = idList<idAIVar_String,5>::Alloc(this: &this->stringVars);
    v8.index = this->stringVars.num - 1;
    v8.varArray = VARRAY_STRING;
    idList<idAIBlackboard::idVarInfo,5>::Append(this: &this->vars, obj: &v8);
    v7->Set_3(this: v7, a2: val);
    idStr::operator=(this: &v7->name, text: name);
    return v7;
  }
  else
  {
    idLib::Warning(fmt: "Exceeded max number of AI blackboard string variables: %d", 8);
    return nullptr;
  }
}

