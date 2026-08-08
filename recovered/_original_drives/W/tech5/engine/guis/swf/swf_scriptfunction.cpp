
// ========================================================================
// ?GetPropertyName@?A0x77bb9143@@YAPBDH@Z
// EA  : 0x82784478
// RVA : 0x00784478
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

char *__fastcall `anonymous namespace'::GetPropertyName(int index)
{
  char *result; // r3

  switch ( index )
  {
    case 0:
      result = "_x";
      break;
    case 1:
      result = "_y";
      break;
    case 2:
      result = "_xscale";
      break;
    case 3:
      result = "_yscale";
      break;
    case 4:
      result = "_currentframe";
      break;
    case 5:
      result = "_totalframes";
      break;
    case 6:
      result = "_alpha";
      break;
    case 7:
      result = "_visible";
      break;
    case 8:
      result = "_width";
      break;
    case 9:
      result = "_height";
      break;
    case 10:
      result = "_rotation";
      break;
    case 11:
      result = "_target";
      break;
    case 12:
      result = "_framesloaded";
      break;
    case 13:
      result = "_name";
      break;
    case 14:
      result = "_droptarget";
      break;
    case 15:
      result = "_url";
      break;
    case 16:
      result = "_highquality";
      break;
    case 17:
      result = "_focusrect";
      break;
    case 18:
      result = "_soundbuftime";
      break;
    case 19:
      result = "_quality";
      break;
    case 20:
      result = "_mousex";
      break;
    case 21:
      result = "_mousey";
      break;
    default:
      result = &byte_8200D768;
      break;
  }
  return result;
}


// ========================================================================
// ?GetSwfActionName@?A0x77bb9143@@YAPBDW4swfAction_t@@@Z
// EA  : 0x82784608
// RVA : 0x00784608
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

const char *__fastcall `anonymous namespace'::GetSwfActionName(swfAction_t code)
{
  const char *result; // r3

  switch ( code )
  {
    case Action_End:
      result = "Action_End";
      break;
    case Action_NextFrame:
      result = "Action_NextFrame";
      break;
    case Action_PrevFrame:
      result = "Action_PrevFrame";
      break;
    case Action_Play:
      result = "Action_Play";
      break;
    case Action_Stop:
      result = "Action_Stop";
      break;
    case Action_ToggleQuality:
      result = "Action_ToggleQuality";
      break;
    case Action_StopSounds:
      result = "Action_StopSounds";
      break;
    case Action_Add:
      result = "Action_Add";
      break;
    case Action_Subtract:
      result = "Action_Subtract";
      break;
    case Action_Multiply:
      result = "Action_Multiply";
      break;
    case Action_Divide:
      result = "Action_Divide";
      break;
    case Action_Equals:
      result = "Action_Equals";
      break;
    case Action_Less:
      result = "Action_Less";
      break;
    case Action_And:
      result = "Action_And";
      break;
    case Action_Or:
      result = "Action_Or";
      break;
    case Action_Not:
      result = "Action_Not";
      break;
    case Action_StringEquals:
      result = "Action_StringEquals";
      break;
    case Action_StringLength:
      result = "Action_StringLength";
      break;
    case Action_StringExtract:
      result = "Action_StringExtract";
      break;
    case Action_Pop:
      result = "Action_Pop";
      break;
    case Action_ToInteger:
      result = "Action_ToInteger";
      break;
    case Action_GetVariable:
      result = "Action_GetVariable";
      break;
    case Action_SetVariable:
      result = "Action_SetVariable";
      break;
    case Action_SetTarget2:
      result = "Action_SetTarget2";
      break;
    case Action_StringAdd:
      result = "Action_StringAdd";
      break;
    case Action_GetProperty:
      result = "Action_GetProperty";
      break;
    case Action_SetProperty:
      result = "Action_SetProperty";
      break;
    case Action_CloneSprite:
      result = "Action_CloneSprite";
      break;
    case Action_RemoveSprite:
      result = "Action_RemoveSprite";
      break;
    case Action_Trace:
      result = "Action_Trace";
      break;
    case Action_StartDrag:
      result = "Action_StartDrag";
      break;
    case Action_EndDrag:
      result = "Action_EndDrag";
      break;
    case Action_StringLess:
      result = "Action_StringLess";
      break;
    case Action_Throw:
      result = "Action_Throw";
      break;
    case Action_CastOp:
      result = "Action_CastOp";
      break;
    case Action_ImplementsOp:
      result = "Action_ImplementsOp";
      break;
    case Action_RandomNumber:
      result = "Action_RandomNumber";
      break;
    case Action_MBStringLength:
      result = "Action_MBStringLength";
      break;
    case Action_CharToAscii:
      result = "Action_CharToAscii";
      break;
    case Action_AsciiToChar:
      result = "Action_AsciiToChar";
      break;
    case Action_GetTime:
      result = "Action_GetTime";
      break;
    case Action_MBStringExtract:
      result = "Action_MBStringExtract";
      break;
    case Action_MBCharToAscii:
      result = "Action_MBCharToAscii";
      break;
    case Action_MBAsciiToChar:
      result = "Action_MBAsciiToChar";
      break;
    case Action_Delete:
      result = "Action_Delete";
      break;
    case Action_Delete2:
      result = "Action_Delete2";
      break;
    case Action_DefineLocal:
      result = "Action_DefineLocal";
      break;
    case Action_CallFunction:
      result = "Action_CallFunction";
      break;
    case Action_Return:
      result = "Action_Return";
      break;
    case Action_Modulo:
      result = "Action_Modulo";
      break;
    case Action_NewObject:
      result = "Action_NewObject";
      break;
    case Action_DefineLocal2:
      result = "Action_DefineLocal2";
      break;
    case Action_InitArray:
      result = "Action_InitArray";
      break;
    case Action_InitObject:
      result = "Action_InitObject";
      break;
    case Action_TypeOf:
      result = "Action_TypeOf";
      break;
    case Action_TargetPath:
      result = "Action_TargetPath";
      break;
    case Action_Enumerate:
      result = "Action_Enumerate";
      break;
    case Action_Add2:
      result = "Action_Add2";
      break;
    case Action_Less2:
      result = "Action_Less2";
      break;
    case Action_Equals2:
      result = "Action_Equals2";
      break;
    case Action_ToNumber:
      result = "Action_ToNumber";
      break;
    case Action_ToString:
      result = "Action_ToString";
      break;
    case Action_PushDuplicate:
      result = "Action_PushDuplicate";
      break;
    case Action_StackSwap:
      result = "Action_StackSwap";
      break;
    case Action_GetMember:
      result = "Action_GetMember";
      break;
    case Action_SetMember:
      result = "Action_SetMember";
      break;
    case Action_Increment:
      result = "Action_Increment";
      break;
    case Action_Decrement:
      result = "Action_Decrement";
      break;
    case Action_CallMethod:
      result = "Action_CallMethod";
      break;
    case Action_NewMethod:
      result = "Action_NewMethod";
      break;
    case Action_InstanceOf:
      result = "Action_InstanceOf";
      break;
    case Action_Enumerate2:
      result = "Action_Enumerate2";
      break;
    case Action_BitAnd:
      result = "Action_BitAnd";
      break;
    case Action_BitOr:
      result = "Action_BitOr";
      break;
    case Action_BitXor:
      result = "Action_BitXor";
      break;
    case Action_BitLShift:
      result = "Action_BitLShift";
      break;
    case Action_BitRShift:
      result = "Action_BitRShift";
      break;
    case Action_BitURShift:
      result = "Action_BitURShift";
      break;
    case Action_StrictEquals:
      result = "Action_StrictEquals";
      break;
    case Action_Greater:
      result = "Action_Greater";
      break;
    case Action_StringGreater:
      result = "Action_StringGreater";
      break;
    case Action_Extends:
      result = "Action_Extends";
      break;
    case Action_GotoFrame:
      result = "Action_GotoFrame";
      break;
    case Action_GetURL:
      result = "Action_GetURL";
      break;
    case Action_StoreRegister:
      result = "Action_StoreRegister";
      break;
    case Action_ConstantPool:
      result = "Action_ConstantPool";
      break;
    case Action_WaitForFrame:
      result = "Action_WaitForFrame";
      break;
    case Action_SetTarget:
      result = "Action_SetTarget";
      break;
    case Action_GoToLabel:
      result = "Action_GoToLabel";
      break;
    case Action_WaitForFrame2:
      result = "Action_WaitForFrame2";
      break;
    case Action_DefineFunction2:
      result = "Action_DefineFunction2";
      break;
    case Action_Try:
      result = "Action_Try";
      break;
    case Action_With:
      result = "Action_With";
      break;
    case Action_Push:
      result = "Action_Push";
      break;
    case Action_Jump:
      result = "Action_Jump";
      break;
    case Action_GetURL2:
      result = "Action_GetURL2";
      break;
    case Action_DefineFunction:
      result = "Action_DefineFunction";
      break;
    case Action_If:
      result = "Action_If";
      break;
    case Action_Call:
      result = "Action_Call";
      break;
    case Action_GotoFrame2:
      result = "Action_GotoFrame2";
      break;
    default:
      result = "UNKNOWN CODE";
      break;
  }
  return result;
}


// ========================================================================
// ?Clear@idSWFConstantPool@@QAAXXZ
// EA  : 0x82784EC0
// RVA : 0x00784EC0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWFConstantPool::Clear(idSWFConstantPool *this)
{
  int v2; // r28
  int v3; // r29
  idSWFScriptString *v4; // r31
  int refCount; // r10

  v2 = 0;
  if ( this->pool.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->pool.list[v3];
      refCount = v4->refCount;
      v4->refCount = refCount - 1;
      if ( refCount == 1 )
      {
        idStr::FreeData(this: v4);
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->pool.num );
  }
  if ( this->pool.listStatic == 0 || this->pool.listStatic == 2 )
  {
    if ( this->pool.list != nullptr )
      idMem::Free(this: &mem, ptr: this->pool.list, align: ALIGN_16);
    this->pool.list = nullptr;
    this->pool.size = 0;
  }
  this->pool.num = 0;
}


// ========================================================================
// ?Copy@idSWFConstantPool@@QAAXABV1@@Z
// EA  : 0x82784FF0
// RVA : 0x00784FF0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWFConstantPool::Copy(idSWFConstantPool *this, const idSWFConstantPool *other)
{
  int num; // r30
  int size; // r11
  int v6; // r10
  int v7; // r11
  idSWFScriptString *v8; // r5

  idSWFConstantPool::Clear(this);
  num = other->pool.num;
  if ( num <= this->pool.size
    || idList<idNavSpline *,5>::Resize((idList<idSpawnArea::GeneratedPosition *,5> *)this, newsize: other->pool.num) )
  {
    size = this->pool.size;
    if ( num < size )
      size = num;
    this->pool.num = size;
  }
  v6 = 0;
  if ( this->pool.num > 0 )
  {
    v7 = 0;
    do
    {
      ++v6;
      this->pool.list[v7] = other->pool.list[v7];
      v8 = this->pool.list[v7++];
      ++v8->refCount;
    }
    while ( v6 < this->pool.num );
  }
}


// ========================================================================
// ?Invoke@idSWF@@QAAXPBDABVidSWFParmList@@@Z
// EA  : 0x827850A0
// RVA : 0x007850A0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWF::Invoke(idSWF *this, const char *functionName, const idSWFParmList *parms)
{
  idSWFScriptVar v6; // [sp+50h] [-40h] BYREF
  idSWFScriptVar v7[7]; // [sp+58h] [-38h] BYREF

  idSWFScriptObject::Get(
    this: (idSWFScriptObject *)&v6,
    result: (idSWFScriptVar *)this->mainspriteInstance->scriptObject,
    name: functionName);
  if ( swf_debugInvoke.valueInteger != 0 )
    idLib::Printf(fmt: "SWF: Invoke %s with %d parms (%s)\n", functionName, parms->num, this->filename.str);
  if ( v6.type == SWF_VAR_FUNCTION )
  {
    (*(void (__fastcall **)(idSWFScriptVar *, int __struct_ptr, _DWORD, const idSWFParmList *))(*(_DWORD *)v6.value.i + 4))(
      a1: v7,
      a2: v6.value.i,
      a3: 0,
      a4: parms);
    idSWFScriptVar::Free(this: v7);
  }
  idSWFScriptVar::Free(this: &v6);
}


// ========================================================================
// __unwind$222304
// EA  : 0x82785140
// RVA : 0x00785140
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222304()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?Invoke@idSWF@@QAAXPBDABVidSWFParmList@@AA_N@Z
// EA  : 0x82785170
// RVA : 0x00785170
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWF::Invoke(idSWF *this, const char *functionName, const idSWFParmList *parms, bool *functionExists)
{
  idSWFScriptVar v8; // [sp+50h] [-40h] BYREF
  idSWFScriptVar v9[7]; // [sp+58h] [-38h] BYREF

  idSWFScriptObject::Get(
    this: (idSWFScriptObject *)&v8,
    result: (idSWFScriptVar *)this->mainspriteInstance->scriptObject,
    name: functionName);
  if ( swf_debugInvoke.valueInteger != 0 )
    idLib::Printf(fmt: "SWF: Invoke %s with %d parms (%s)\n", functionName, parms->num, this->filename.str);
  if ( v8.type == SWF_VAR_FUNCTION )
  {
    (*(void (__fastcall **)(idSWFScriptVar *, int __struct_ptr, _DWORD, const idSWFParmList *))(*(_DWORD *)v8.value.i + 4))(
      a1: v9,
      a2: v8.value.i,
      a3: 0,
      a4: parms);
    idSWFScriptVar::Free(this: v9);
    *functionExists = true;
  }
  else
  {
    *functionExists = false;
  }
  idSWFScriptVar::Free(this: &v8);
}


// ========================================================================
// __unwind$222408
// EA  : 0x82785228
// RVA : 0x00785228
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222408()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetScope@idSWFScriptFunction_Script@@QAAXAAV?$idList@PAVidSWFScriptObject@@$04@@@Z
// EA  : 0x827852B8
// RVA : 0x007852B8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWFScriptFunction_Script::SetScope(
        idSWFScriptFunction_Script *this,
        const idList<idMD6Filter *,5> *newScope)
{
  int v4; // r29
  int v5; // r30
  idSWFScriptObject **list; // r11
  idSWFScriptObject *v7; // r10
  idSWFScriptObject *v8; // r31
  idStaticList<idSWFScriptObject *,19> *p_scope; // r31
  int v11; // r9
  int v12; // r11
  idSWFScriptObject *v13; // r8

  v4 = 0;
  if ( this->scope.num > 0 )
  {
    v5 = 0;
    do
    {
      list = this->scope.list;
      v7 = list[v5];
      if ( v7 != nullptr )
      {
        v8 = list[v5];
        if ( v7->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v7);
          idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->scope.num );
  }
  p_scope = &this->scope;
  if ( this->scope.listStatic == 0 || this->scope.listStatic == 2 )
  {
    if ( p_scope->list != nullptr )
      idMem::Free(this: &mem, ptr: p_scope->list, align: ALIGN_16);
    p_scope->list = nullptr;
    this->scope.size = 0;
  }
  this->scope.num = 0;
  idList<idMD6Filter *,5>::Append(this: (idList<idMD6Filter *,5> *)&this->scope, other: newScope);
  v11 = 0;
  if ( this->scope.num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = p_scope->list[v12];
      if ( v13 != nullptr )
        ++v13->refCount;
      ++v11;
      ++v12;
    }
    while ( v11 < this->scope.num );
  }
}


// ========================================================================
// ??1idSWFScriptFunction_Script@@UAA@XZ
// EA  : 0x827855E0
// RVA : 0x007855E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __fastcall idSWFScriptFunction_Script::~idSWFScriptFunction_Script(idSWFScriptFunction_Script *this)
{
  int v2; // r27
  int v3; // r28
  idSWFScriptObject **list; // r11
  idSWFScriptObject *v5; // r10
  idSWFScriptObject *v6; // r30
  idSWFScriptObject *prototype; // r30
  idSWFScriptFunction_Script::parmInfo_t *v10; // r4
  idSWFScriptVar *v11; // r27
  int size; // r30
  idSWFScriptVar *v13; // r28
  idSWFConstantPool *p_constants; // r30
  idSWFScriptObject **v15; // r4

  this->__vftable = (idSWFScriptFunction_Script_vtbl *)&idSWFScriptFunction_Script::`vftable';
  v2 = 0;
  if ( this->scope.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->scope.list;
      v5 = list[v3];
      if ( v5 != nullptr )
      {
        v6 = list[v3];
        if ( v5->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v5);
          idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->scope.num );
  }
  prototype = this->prototype;
  if ( prototype != nullptr && prototype->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: prototype);
    idMem::Free(this: &mem, ptr: prototype, align: ALIGN_16);
  }
  if ( this->parameters.listStatic == 0 || this->parameters.listStatic == 2 )
  {
    v10 = this->parameters.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->parameters.list = nullptr;
    this->parameters.size = 0;
  }
  this->parameters.num = 0;
  if ( this->registers.listStatic == 0 || this->registers.listStatic == 2 )
  {
    v11 = this->registers.list;
    if ( v11 != nullptr )
    {
      size = this->registers.size;
      if ( size > 0 )
      {
        v13 = this->registers.list;
        do
        {
          idSWFScriptVar::Free(this: v13);
          --size;
          ++v13;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    }
    this->registers.list = nullptr;
    this->registers.size = 0;
  }
  this->registers.num = 0;
  p_constants = &this->constants;
  idSWFConstantPool::Clear(this: &this->constants);
  if ( this->constants.pool.listStatic == 0 || this->constants.pool.listStatic == 2 )
  {
    if ( p_constants->pool.list != nullptr )
      idMem::Free(this: &mem, ptr: p_constants->pool.list, align: ALIGN_16);
    p_constants->pool.list = nullptr;
    this->constants.pool.size = 0;
  }
  this->constants.pool.num = 0;
  if ( this->scope.listStatic == 0 || this->scope.listStatic == 2 )
  {
    v15 = this->scope.list;
    if ( v15 != nullptr )
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
    this->scope.list = nullptr;
    this->scope.size = 0;
  }
  this->scope.num = 0;
  this->__vftable = (idSWFScriptFunction_Script_vtbl *)&idSWFScriptFunction::`vftable';
}


// ========================================================================
// __unwind$222776
// EA  : 0x827857E0
// RVA : 0x007857E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222776()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$222777
// EA  : 0x82785808
// RVA : 0x00785808
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222777()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 28));
}


// ========================================================================
// __unwind$222778
// EA  : 0x82785834
// RVA : 0x00785834
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222778()
{
  int v0; // r12

  idSWFConstantPool::~idSWFConstantPool(this: (idSWFConstantPool *)(*(_DWORD *)(v0 - 160 + 180) + 120));
}


// ========================================================================
// __unwind$222779
// EA  : 0x82785860
// RVA : 0x00785860
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222779()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                         + 136));
}


// ========================================================================
// __unwind$222780
// EA  : 0x8278588C
// RVA : 0x0078588C
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222780()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 152));
}


// ========================================================================
// __unwind$222954
// EA  : 0x827858B8
// RVA : 0x007858B8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_222954()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 80));
}


// ========================================================================
// ?Run@idSWFScriptFunction_Script@@AAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@AAVidSWFStack@@AAVidSWFBitStream@@@Z
// EA  : 0x82785D78
// RVA : 0x00785D78
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

idSWFScriptFunction_Script *__fastcall idSWFScriptFunction_Script::Run(
        idSWFScriptFunction_Script *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        idList<idSWFScriptVar,5> *stack,
        idSWFBitStream *bitstream)
{
  idSWFScriptObject::swfObjectType_t objectType; // r10
  const char *p_isPlaying; // r11
  bool v8; // cr56
  idSWFSpriteInstance *v9; // r14
  idSWFSpriteInstance *v10; // r25
  const unsigned __int8 *v11; // r5
  const char *v12; // r4
  unsigned __int64 v13; // r23
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // r8
  int v16; // r6
  const unsigned __int8 *readp; // r11
  unsigned __int16 v18; // r27
  swfAction_t v19; // r26
  int v20; // r11
  int v21; // r29
  int v22; // r28
  char *data; // r25
  int num; // r24
  const char *v25; // r3
  idSWFScriptVar::swfScriptVarValue_t v26; // r28
  int v27; // r29
  idStr *v28; // r4
  char *v29; // r25
  const char *v30; // r3
  const char *SwfActionName; // r3
  const unsigned __int8 *v32; // r11
  int Frame; // r3
  const unsigned __int8 *v34; // r3
  int v35; // r6
  int v36; // r5
  int v37; // r4
  const unsigned __int8 *v38; // r11
  unsigned __int64 v39; // r10
  unsigned __int64 v40; // r8
  const char *v41; // r29
  idSWFScriptVar *v42; // r3
  idSWFScriptVar *v43; // r29
  double v44; // fp0
  idSWFScriptVar *v45; // r29
  idSWFScriptVar *v46; // r29
  idSWFScriptVar::swfScriptVarType v47; // r10
  int v48; // r8
  const idSWFScriptVar *v49; // r29
  idSWFScriptVar *v50; // r3
  int v51; // r29
  idSWFScriptVar *v52; // r28
  double v53; // fp30
  idSWFScriptVar *v54; // r29
  int v55; // r29
  idSWFScriptVar *v56; // r28
  idSWFScriptVar::swfScriptVarType v57; // r9
  int v58; // r8
  idSWFScriptString *v59; // r29
  idSWFScriptVar *v60; // r3
  int v61; // r11
  idSWFScriptVar *v62; // r3
  idSWFScriptVar *v63; // r29
  double v64; // fp30
  double v65; // fp30
  int v66; // r11
  idSWFScriptVar *v67; // r29
  idSWFScriptVar *v68; // r28
  double v69; // fp30
  double v70; // fp30
  int v71; // r11
  idSWFScriptVar *v72; // r3
  idSWFScriptVar *v73; // r29
  double v74; // fp30
  double v75; // fp30
  int v76; // r11
  idSWFScriptVar *v77; // r29
  idSWFScriptVar *v78; // r28
  double v79; // fp30
  double v80; // fp30
  int v81; // r11
  idSWFScriptVar *v82; // r29
  double v83; // fp30
  bool v84; // r28
  int v85; // r11
  idSWFScriptVar *v86; // r29
  double v87; // fp30
  idSWFScriptVar *v88; // r29
  idSWFScriptVar *v89; // r29
  bool v90; // r28
  idStr *v91; // r29
  idStr *v92; // r3
  bool v93; // r28
  idSWFScriptVar *v94; // r29
  int len; // r28
  idSWFScriptVar *v96; // r29
  const idStr *v97; // r29
  const idStr *v98; // r3
  const idStr *v99; // r28
  idSWFScriptVar *v100; // r29
  idStr *v101; // r28
  idSWFScriptVar *v102; // r11
  idSWFScriptVar *v103; // r3
  idSWFScriptVar *v104; // r29
  int v105; // r27
  int v106; // r3
  const idStr *v107; // r28
  idSWFScriptVar *v108; // r29
  int v109; // r4
  idStr *v110; // r29
  idStr *v111; // r3
  unsigned int v112; // r28
  idSWFScriptVar *v113; // r29
  idStr *v114; // r29
  idStr *v115; // r3
  char *v116; // r27
  char *v117; // r28
  idSWFScriptVar *v118; // r29
  idSWFScriptVar *v119; // r29
  int v120; // r28
  idStr *v121; // r3
  idSWFScriptVar *v122; // r29
  idSWFScriptVar::swfScriptVarValue_t v123; // r28
  idSWFScriptVar *v124; // r29
  __int64 v125; // r6
  __int64 v126; // r10
  __int64 v127; // r8
  va *v128; // r3
  const unsigned __int8 *v129; // r11
  const unsigned __int8 *v130; // r11
  __int16 v131; // r29
  __int32 v132; // r28
  int v133; // r29
  const idSWFScriptVar *v134; // r3
  char v135; // r27
  __int32 v136; // r29
  int v137; // r28
  int v138; // r11
  int v139; // r29
  int size; // r11
  int v141; // r29
  _BYTE *v142; // r11
  unsigned __int8 *v143; // r10
  char v144; // r11
  char v145; // r28
  int v146; // r11
  idSWFScriptVar *v147; // r10
  idSWFScriptVar *v148; // r9
  idSWFScriptVar::swfScriptVarType v149; // r9
  char v150; // r9
  bool v151; // zf
  idStr *v152; // r3
  int v153; // r29
  const char *v154; // r3
  idStr *v155; // r3
  idSWFSpriteInstance *v156; // r29
  int v157; // r3
  char *PropertyName; // r3
  const idSWFScriptVar *v159; // r3
  idStr *v160; // r3
  idSWFSpriteInstance *v161; // r28
  int v162; // r11
  const idSWFScriptVar *v163; // r29
  int v164; // r3
  char *v165; // r3
  unsigned int v166; // r29
  idStr *v167; // r3
  int v168; // r29
  idSWFScriptVar *v169; // r28
  int v170; // r3
  idRandom2 *v171; // r28
  idSWFScriptVar *v172; // r29
  int v173; // r3
  int v174; // r28
  idSWFScriptVar::swfScriptVarType v175; // r26
  int v176; // r25
  __int32 v177; // r29
  int v178; // r28
  const idSWFScriptVar *v179; // r3
  int v180; // r11
  int v181; // r29
  int v182; // r11
  int v183; // r3
  int v184; // r11
  int v185; // r29
  bool v186; // cr56
  int v187; // r11
  int v188; // r29
  int v189; // r11
  int v190; // r27
  int v191; // r28
  int v192; // r11
  int v193; // r29
  int v194; // r11
  const idSWFScriptVar *v195; // r29
  int v196; // r11
  int v197; // r10
  idSWFScriptVar *v198; // r3
  int v199; // r11
  int v200; // r10
  idSWFScriptVar *v201; // r29
  int v202; // r11
  idSWFScriptVar *v203; // r10
  idSWFScriptVar *v204; // r9
  idSWFScriptVar::swfScriptVarType v205; // r25
  idSWFScriptVar *v206; // r26
  idSWFScriptVar *v207; // r10
  const idSWFScriptVar *v208; // r3
  bool v209; // r29
  idStr *v210; // r3
  idStr *v211; // r3
  int v212; // r3
  int v213; // r27
  int v214; // r28
  int v215; // r11
  int v216; // r29
  int v217; // r11
  const idSWFScriptVar *v218; // r29
  idSWFScriptVar *v219; // r3
  idSWFScriptVar *v220; // r29
  const unsigned __int8 *v221; // r11
  int v222; // r29
  int v223; // r9
  unsigned __int64 v224; // r8
  int v225; // r27
  const char *String; // r3
  const char *v227; // r3
  idSWFScriptFunction_Script *v228; // r29
  const unsigned __int8 *v229; // r11
  int v230; // r27
  unsigned __int64 v231; // r8
  int v232; // r6
  int v233; // r5
  int v234; // r4
  int n; // r28
  const char *v236; // r3
  int v237; // r11
  const unsigned __int8 *v238; // r11
  unsigned __int64 v239; // r10
  int v240; // r8
  int v241; // r28
  const unsigned __int8 *v242; // r3
  idSWFScriptVar *v243; // r3
  const idSWFScriptVar *v244; // r3
  const char *v245; // r3
  idSWFScriptFunction_Script *v246; // r29
  const unsigned __int8 *v247; // r11
  __int16 v248; // r9
  __int16 v249; // r7
  unsigned __int16 v250; // r6
  int v251; // r27
  int v252; // r28
  int v253; // r25
  int v254; // r26
  unsigned int v255; // r24
  unsigned __int64 v256; // r8
  int v257; // r6
  int v258; // r5
  int v259; // r4
  int v260; // r28
  unsigned __int8 *v261; // r11
  unsigned int v262; // r27
  const char *v263; // r3
  const char *v264; // r26
  int v265; // r11
  const unsigned __int8 *v266; // r11
  unsigned __int64 v267; // r10
  int v268; // r8
  int v269; // r28
  idSWFScriptVar *v270; // r3
  const idSWFScriptVar *v271; // r3
  __int32 v272; // r28
  int v273; // r29
  const idSWFScriptVar *v274; // r3
  int v275; // r11
  idSWFScriptVar *v276; // r10
  idSWFScriptVar *v277; // r9
  idSWFScriptVar::swfScriptVarType v278; // r8
  int v279; // r9
  idSWFScriptVar *v280; // r29
  idSWFScriptObject *object; // r29
  idSWFScriptVar *v282; // r28
  int v283; // r26
  int v284; // r27
  const char *str; // r25
  int v286; // r11
  int v287; // r10
  idSWFScriptVar *v288; // r28
  idSWFScriptVar *v290; // r11
  idSWFScriptVar *v291; // r29
  idSWFScriptObject *v292; // r29
  idSWFScriptVar *v293; // r28
  int v294; // r28
  int v295; // r27
  const char *v296; // r26
  idSWFScriptVar *v297; // r3
  int v299; // r11
  idSWFScriptVar *v300; // r29
  idSWFScriptVar *v301; // r3
  bool v302; // r28
  int v303; // r11
  idSWFScriptVar *v304; // r29
  idSWFScriptVar *v305; // r3
  bool v306; // r28
  idSWFScriptVar *v307; // r9
  int v308; // r29
  idStr *v309; // r3
  idSWFScriptVar *v310; // r11
  idSWFScriptVar *list; // r10
  idSWFScriptVar::swfScriptVarType v312; // r9
  idSWFScriptVar *v313; // r29
  char v314; // r9
  idSWFScriptVar *v315; // r11
  int v316; // r3
  const idSWFScriptVar *v317; // r3
  idStr *v318; // r3
  const idSWFScriptVar *v319; // r3
  idSWFScriptVar *v320; // r9
  idStr *v321; // r3
  idSWFScriptVar::swfScriptVarType v322; // r9
  char v323; // r9
  int v324; // r28
  idSWFScriptVar *v325; // r29
  idSWFScriptVar *v326; // r29
  int v327; // r3
  int v328; // r11
  idSWFScriptVar *v329; // r10
  int v330; // r28
  idSWFScriptObject *v331; // r29
  idSWFScriptObject *v332; // r3
  const idSWFScriptVar *v333; // r3
  idSWFScriptVar *v334; // r29
  idSWFScriptVar *v335; // r10
  idSWFScriptVar::swfScriptVarType v336; // r9
  idSWFScriptObject *v337; // r28
  char v338; // r9
  char *v339; // r9
  const idSWFScriptVar *v340; // r29
  int v341; // r3
  idStr *v342; // r3
  idSWFScriptObject *v343; // r28
  int v344; // r26
  int j; // r27
  int v346; // r11
  int v347; // r29
  int v348; // r11
  idSWFScriptVar *v349; // r29
  int v351; // r29
  int k; // r27
  idStr *v353; // r3
  int v354; // r11
  int v355; // r29
  int v356; // r11
  idSWFScriptObject *v357; // r27
  int v358; // r28
  int i; // r29
  idSWFScriptObject *v360; // r3
  int v361; // r3
  int v362; // r29
  int v363; // r28
  idSWFScriptObject::swfNamedVar_t *v364; // r29
  idSWFScriptObject *v365; // r3
  idSWFScriptObject *v366; // r3
  idSWFScriptVar *v367; // r29
  idSWFScriptVar *v369; // r6
  idSWFScriptFunction *function; // r29
  idSWFScriptVar::swfScriptVarValue_t v371; // r28
  idSWFScriptObject *v372; // r27
  idSWFScriptObject *v373; // r3
  idSWFScriptObject *v374; // r3
  const idSWFScriptVar *v375; // r3
  const idSWFScriptVar *v376; // r3
  int v377; // r11
  idSWFScriptVar *v378; // r10
  idSWFScriptVar *v379; // r9
  idSWFScriptVar *v380; // r29
  idSWFScriptVar::swfScriptVarValue_t v381; // r29
  int v382; // r9
  int v383; // r11
  int m; // r28
  const idStr *v385; // r3
  idStr *v386; // r27
  size_t v387; // r29
  idSWFScriptVar *v388; // r29
  const unsigned __int8 *v389; // r11
  unsigned __int64 v390; // r10
  unsigned int v391; // r29
  const unsigned __int8 *v392; // r3
  int v393; // r11
  idSWFScriptVar *v394; // r10
  idSWFScriptVar *v395; // r7
  idSWFScriptVar *v396; // r29
  idSWFScriptVar::swfScriptVarType v397; // r11
  idSWFScriptVar *v398; // r29
  double v399; // fp30
  const idStr *v400; // r28
  idSWFScriptVar *v401; // r29
  idSWFScriptVar *v402; // r29
  const char *v403; // r3
  int v404; // r11
  idSWFScriptVar *v405; // r10
  idSWFScriptVar *v406; // r9
  idSWFScriptVar::swfScriptVarType v407; // r9
  char v408; // r9
  idSWFScriptVar::swfScriptVarType v409; // r9
  char v410; // r9
  idSWFScriptVar *v411; // r29
  double v412; // fp30
  double v413; // fp1
  const idStr *v414; // r29
  const idStr *v415; // r3
  const idStr *v416; // r3
  int v417; // r11
  idSWFScriptVar *v418; // r10
  idSWFScriptVar *v419; // r9
  idSWFScriptVar::swfScriptVarType v420; // r9
  char v421; // r9
  idSWFScriptVar::swfScriptVarType v422; // r9
  char v423; // r9
  idStr *v424; // r29
  idStr *v425; // r3
  int v426; // r3
  idSWFScriptVar *v427; // r29
  double v428; // fp30
  bool v429; // r4
  int v430; // r11
  idSWFScriptVar *v431; // r10
  idSWFScriptVar *v432; // r9
  idSWFScriptVar::swfScriptVarType v433; // r9
  char v434; // r9
  idSWFScriptVar::swfScriptVarType v435; // r9
  char v436; // r9
  idStr *v437; // r29
  idStr *v438; // r3
  idSWFScriptVar *v439; // r29
  double v440; // fp30
  signed int v441; // r29
  int v442; // r3
  idSWFScriptVar *v443; // r29
  int v444; // r4
  unsigned int v445; // r9
  idSWFScriptVar *v446; // r3
  int v447; // r10
  idSWFScriptVar *v448; // r3
  idSWFScriptVar *v449; // r29
  int v450; // r28
  int v451; // r3
  int v452; // r10
  idSWFScriptVar *v453; // r3
  idSWFScriptVar *v454; // r29
  char v455; // r28
  int v456; // r3
  int v457; // r10
  idSWFScriptVar *v458; // r3
  idSWFScriptVar *v459; // r29
  int v460; // r28
  int v461; // r3
  int v462; // r10
  idSWFScriptVar *v463; // r3
  idSWFScriptVar *v464; // r29
  char v465; // r28
  int v466; // r3
  int v467; // r10
  idSWFScriptVar *v468; // r3
  idSWFScriptVar *v469; // r29
  char v470; // r28
  unsigned int v471; // r3
  int v472; // r10
  idSWFScriptVar *v473; // r3
  idSWFScriptVar *v474; // r29
  int v475; // r28
  int v476; // r3
  idSWFScriptVar *v477; // r29
  double v478; // fp1
  idSWFScriptVar *v479; // r29
  double v480; // fp1
  idSWFScriptVar *v481; // r3
  int v482; // r11
  idSWFScriptVar *v483; // r9
  const idSWFScriptVar *v484; // r4
  unsigned __int8 *v485; // r11
  int v486; // r9
  idStr *v487; // r3
  idStr *v488; // r3
  const unsigned __int8 *startp; // r11
  idSWFScriptVar *v490; // r11
  const char *ActionName; // r3
  int v493; // [sp+8h] [-1B08h]
  int v494; // [sp+Ch] [-1B04h]
  int v495; // [sp+10h] [-1B00h]
  int v496; // [sp+14h] [-1AFCh]
  int v497; // [sp+18h] [-1AF8h]
  int v498; // [sp+1Ch] [-1AF4h]
  idSWFScriptVar *v499; // [sp+50h] [-1AC0h] BYREF
  const char *type; // [sp+54h] [-1ABCh]
  char v501; // [sp+58h] [-1AB8h]
  idMem *v502; // [sp+5Ch] [-1AB4h]
  idSWFSpriteInstance *v503; // [sp+60h] [-1AB0h]
  idSWFBitStream v504; // [sp+70h] [-1AA0h] BYREF
  const char *v505; // [sp+90h] [-1A80h]
  const char *v506; // [sp+94h] [-1A7Ch]
  const char *v507; // [sp+98h] [-1A78h]
  idRandom2 *v508; // [sp+9Ch] [-1A74h]
  const char *v509; // [sp+A0h] [-1A70h]
  idSWFScriptVar v510; // [sp+A8h] [-1A68h] BYREF
  idSWFScriptVar v511; // [sp+B0h] [-1A60h] BYREF
  const char *v512; // [sp+B8h] [-1A58h]
  const char *v513; // [sp+BCh] [-1A54h]
  const char *v514; // [sp+C0h] [-1A50h]
  const char *v515; // [sp+C4h] [-1A4Ch]
  const char *v516; // [sp+C8h] [-1A48h]
  const char *v517; // [sp+CCh] [-1A44h]
  const char *v518; // [sp+D0h] [-1A40h]
  const char *v519; // [sp+D4h] [-1A3Ch]
  const char *v520; // [sp+D8h] [-1A38h]
  const char *v521; // [sp+DCh] [-1A34h]
  const char *v522; // [sp+E0h] [-1A30h]
  const char *v523; // [sp+E4h] [-1A2Ch]
  const char *v524; // [sp+E8h] [-1A28h]
  const char *v525; // [sp+ECh] [-1A24h]
  const char *v526; // [sp+F0h] [-1A20h]
  const char *v527; // [sp+F4h] [-1A1Ch]
  const char *v528; // [sp+F8h] [-1A18h]
  const char *v529; // [sp+FCh] [-1A14h]
  const char *v530; // [sp+100h] [-1A10h]
  const char *v531; // [sp+104h] [-1A0Ch]
  const char *v532; // [sp+108h] [-1A08h]
  idSWFScriptObject v533; // [sp+110h] [-1A00h] BYREF
  idSWFScriptObject v534; // [sp+170h] [-19A0h] BYREF
  idSWFScriptVar v535; // [sp+1D0h] [-1940h] BYREF
  idSWFScriptVar v536; // [sp+1D8h] [-1938h] BYREF
  idSWFScriptVar v537; // [sp+1E0h] [-1930h] BYREF
  idSWFScriptObject v538; // [sp+1E8h] [-1928h] BYREF
  idStr v539; // [sp+250h] [-18C0h] BYREF
  idStr v540; // [sp+270h] [-18A0h] BYREF
  idStr v541; // [sp+290h] [-1880h] BYREF
  idStr v542; // [sp+2B0h] [-1860h] BYREF
  idStr v543; // [sp+2D0h] [-1840h] BYREF
  idStr v544; // [sp+2F0h] [-1820h] BYREF
  idStr v545; // [sp+310h] [-1800h] BYREF
  idSWFBitStream v546; // [sp+330h] [-17E0h] BYREF
  idStr v547; // [sp+350h] [-17C0h] BYREF
  idStr v548; // [sp+370h] [-17A0h] BYREF
  idStr v549; // [sp+390h] [-1780h] BYREF
  idStr v550; // [sp+3B0h] [-1760h] BYREF
  idStr v551; // [sp+3D0h] [-1740h] BYREF
  idStaticList<idSWFScriptVar,16> v552; // [sp+3F0h] [-1720h] BYREF
  idStr v553; // [sp+480h] [-1690h] BYREF
  idStr v554; // [sp+4A0h] [-1670h] BYREF
  idStr v555; // [sp+4C0h] [-1650h] BYREF
  idStr v556; // [sp+4E0h] [-1630h] BYREF
  idStr v557; // [sp+500h] [-1610h] BYREF
  idStr v558; // [sp+520h] [-15F0h] BYREF
  idStr v559; // [sp+540h] [-15D0h] BYREF
  idStr v560; // [sp+560h] [-15B0h] BYREF
  idStr v561; // [sp+580h] [-1590h] BYREF
  idStr v562; // [sp+5A0h] [-1570h] BYREF
  idStr v563; // [sp+5C0h] [-1550h] BYREF
  idStr v564; // [sp+5E0h] [-1530h] BYREF
  idStr v565; // [sp+600h] [-1510h] BYREF
  idStr v566; // [sp+620h] [-14F0h] BYREF
  idStr v567; // [sp+640h] [-14D0h] BYREF
  idStr v568; // [sp+660h] [-14B0h] BYREF
  idStr v569; // [sp+680h] [-1490h] BYREF
  idStr v570; // [sp+6A0h] [-1470h] BYREF
  idStr v571; // [sp+6C0h] [-1450h] BYREF
  idStr v572; // [sp+6E0h] [-1430h] BYREF
  idStr v573; // [sp+700h] [-1410h] BYREF
  idStr v574; // [sp+720h] [-13F0h] BYREF
  idStr v575; // [sp+740h] [-13D0h] BYREF
  idStr v576; // [sp+760h] [-13B0h] BYREF
  idStr v577; // [sp+780h] [-1390h] BYREF
  idStr v578; // [sp+7A0h] [-1370h] BYREF
  idStr v579; // [sp+7C0h] [-1350h] BYREF
  idStr v580; // [sp+7E0h] [-1330h] BYREF
  idStr v581; // [sp+800h] [-1310h] BYREF
  idStr v582; // [sp+820h] [-12F0h] BYREF
  idStr v583; // [sp+840h] [-12D0h] BYREF
  idStr v584; // [sp+860h] [-12B0h] BYREF
  idStr v585; // [sp+880h] [-1290h] BYREF
  idStr v586; // [sp+8A0h] [-1270h] BYREF
  idStr v587; // [sp+8C0h] [-1250h] BYREF
  idStr v588; // [sp+8E0h] [-1230h] BYREF
  idStr v589; // [sp+900h] [-1210h] BYREF
  idStr v590; // [sp+920h] [-11F0h] BYREF
  idStaticList<idSWFScriptVar,16> v591; // [sp+940h] [-11D0h] BYREF
  idStaticList<idSWFScriptVar,16> v592; // [sp+9D0h] [-1140h] BYREF
  va v593; // [sp+A60h] [-10B0h] BYREF
  idSWFScriptVar *v594; // [sp+1B24h] [+14h]

  objectType = thisObject->objectType;
  p_isPlaying = nullptr;
  v594 = (idSWFScriptVar *)this;
  v507 = nullptr;
  if ( objectType == SWF_OBJECT_SPRITE )
    p_isPlaying = (const char *)&thisObject->data.sprite->isPlaying;
  v503 = (idSWFSpriteInstance *)p_isPlaying;
  type = p_isPlaying;
  if ( p_isPlaying == nullptr )
  {
    type = (const char *)result[3].type;
    v503 = (idSWFSpriteInstance *)type;
  }
  v8 = (const unsigned __int8 *)(bitstream->readp - bitstream->startp) < (const unsigned __int8 *)(bitstream->endp
                                                                                                 - bitstream->startp);
  ++callstackLevel;
  if ( v8 )
  {
    v502 = &mem;
    v507 = "SWF: Delete2 ignored\n";
    v533.variablesHash[6] = (int)"SWF: no target movie clip for gotoAndStop\n";
    v515 = "prototype";
    v525 = "SWF: Delete ignored\n";
    v523 = "SWF: with() invalid object specified\n";
    v521 = ".";
    v519 = "SWF: Unknown class definition %s";
    v517 = "Array";
    v505 = "__proto__";
    v506 = "Object";
    v512 = "SWF: unknown method %s on %s\n";
    v513 = "value";
    v532 = "length";
    v533.variablesHash[0] = (int)"SWF: unknown member %s\n";
    v530 = "SWF: tried to get member %s on an invalid object in sprite '%s'\n";
    v533.variables.size = (int)&byte_8200D768;
    v528 = "SWF: Parameter %s in function %s bound to out of range register %d";
    v533.variablesHash[5] = (int)"SWF: NULL object for method %s\n";
    v520 = "SWF: no target movie clip for gotoAndPlay\n";
    v509 = "__constructor__";
    v533.variablesHash[1] = (int)"SWF: unknown function %s\n";
    v508 = &random_4;
    v524 = "SWF Trace: %s\n";
    v533.variablesHash[3] = (int)"SWF: no target movie clip for setProperty\n";
    v522 = "SWF: no target movie clip for getProperty\n";
    v9 = v503;
    HIDWORD(v13) = bitstream;
    v533.variablesHash[4] = (int)"SWF: unknown variable %s\n";
    v10 = (idSWFSpriteInstance *)type;
    v518 = "%c";
    v516 = "SWF: no target movie clip for runTo %s\n";
    v533.variablesHash[2] = (int)"SWF: no target movie clip for setTarget %s\n";
    v11 = "SWF: no target movie clip for runTo %d\n";
    v514 = "SWF: no target movie clip for runTo %d\n";
    v12 = "SWF: no target movie clip for stop\n";
    *(_DWORD *)&v533.variables.granularity = "SWF: no target movie clip for stop\n";
    v531 = "SWF: no target movie clip for play\n";
    LODWORD(v13) = 0;
    v529 = "SWF: no target movie clip for prevFrame\n";
    HIDWORD(v14) = "SWF: no target movie clip for nextFrame\n";
    v527 = "SWF: no target movie clip for nextFrame\n";
    LODWORD(v15) = "SWF%d: code %s\n";
    v526 = "SWF%d: code %s\n";
    HIDWORD(v15) = " R%d: %s (%s)\n";
    v533.variables.num = (int)" R%d: %s (%s)\n";
    v16 = (int)"  %c: %s (%s)\n";
    v503 = (idSWFSpriteInstance *)"  %c: %s (%s)\n";
    while ( 1 )
    {
      readp = bitstream->readp;
      v18 = 0;
      *(_QWORD *)(HIDWORD(v13) + 16) = v13;
      LODWORD(v14) = readp + 1;
      *(_QWORD *)(HIDWORD(v13) + 24) = v13;
      v19 = *readp;
      bitstream->readp = readp + 1;
      if ( (unsigned int)v19 >= 0x80 )
      {
        *(_QWORD *)(HIDWORD(v13) + 16) = v13;
        *(_QWORD *)(HIDWORD(v13) + 24) = v13;
        *(_DWORD *)(HIDWORD(v13) + 12) = readp + 3;
        v20 = *(unsigned __int8 *)v14;
        HIDWORD(v14) = __ROL4__(*(unsigned __int8 *)(v14 + 1), 8);
        LODWORD(v15) = HIDWORD(v14) | v20;
        v18 = WORD1(v14) | v20;
      }
      LODWORD(v14) = swf_debug.valueInteger;
      if ( swf_debug.valueInteger >= 3 )
      {
        if ( swf_debug.valueInteger >= 4 )
        {
          v21 = stack->num - 1;
          if ( v21 >= 0 )
          {
            v22 = v21;
            do
            {
              data = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v558, result: (idStr *)&stack->list[v22])->data;
              num = stack->num;
              v25 = idSWFScriptVar::TypeOf(this: &stack->list[v22]);
              idLib::Printf(fmt: (const char *)&v503->isPlaying, (char)(num - v21 + 64), data, v25);
              idStr::FreeData(this: &v558);
              --v21;
              --v22;
            }
            while ( v21 >= 0 );
          }
          v26.i = 0;
          if ( result[17].value.i > 0 )
          {
            v27 = 0;
            do
            {
              v28 = (idStr *)(v27 + result[17].type);
              if ( v28->len != 4 )
              {
                v499 = (idSWFScriptVar *)(v27 + result[17].type);
                v29 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v587, result: v28)->data;
                v30 = idSWFScriptVar::TypeOf(this: (idSWFScriptVar *)(v27 + result[17].type));
                idLib::Printf(fmt: (const char *)v533.variables.num, v26.i, v29, v30);
                idStr::FreeData(this: &v587);
              }
              ++v26.i;
              v27 += 8;
            }
            while ( v26.i < result[17].value.i );
          }
        }
        SwfActionName = `anonymous namespace'::GetSwfActionName(code: v19);
        idLib::Printf(fmt: v526, callstackLevel, SwfActionName);
        LODWORD(v14) = swf_debug.valueInteger;
        v10 = (idSWFSpriteInstance *)type;
      }
      switch ( v19 )
      {
        case Action_End:
          goto LABEL_409;
        case Action_NextFrame:
          if ( v10 != nullptr )
          {
            idSWFSpriteInstance::NextFrame(this: v10);
          }
          else if ( (int)v14 > 0 )
          {
            idLib::Printf(fmt: v527);
          }
          goto LABEL_405;
        case Action_PrevFrame:
          if ( v10 != nullptr )
          {
            idSWFSpriteInstance::PrevFrame(this: v10);
          }
          else if ( (int)v14 > 0 )
          {
            idLib::Printf(fmt: v529);
          }
          goto LABEL_405;
        case Action_Play:
          if ( v10 != nullptr )
          {
            idSWFSpriteInstance::Play(this: v10);
          }
          else if ( (int)v14 > 0 )
          {
            idLib::Printf(fmt: v531);
          }
          goto LABEL_405;
        case Action_Stop:
          if ( v10 != nullptr )
          {
            idSWFSpriteInstance::Stop(this: v10);
          }
          else if ( (int)v14 > 0 )
          {
            idLib::Printf(fmt: *(const char **)&v533.variables.granularity);
          }
          goto LABEL_405;
        case Action_ToggleQuality:
        case Action_StopSounds:
          goto LABEL_405;
        case Action_Add:
          v61 = stack->num;
          v62 = &stack->list[v61 - 1];
          v499 = &stack->list[v61 - 2];
          v63 = v499;
          v64 = idSWFScriptVar::ToFloat(this: v62);
          v65 = (float)((float)v64 + idSWFScriptVar::ToFloat(this: v63));
          idSWFScriptVar::Free(this: v63);
          v63->value.f = v65;
          v63->type = SWF_VAR_FLOAT;
          goto LABEL_403;
        case Action_Subtract:
          v66 = stack->num;
          v68 = &stack->list[v66 - 1];
          v499 = &stack->list[v66 - 2];
          v67 = v499;
          v69 = idSWFScriptVar::ToFloat(this: v499);
          v70 = (float)((float)v69 - idSWFScriptVar::ToFloat(this: v68));
          idSWFScriptVar::Free(this: v67);
          v67->value.f = v70;
          v67->type = SWF_VAR_FLOAT;
          goto LABEL_403;
        case Action_Multiply:
          v71 = stack->num;
          v72 = &stack->list[v71 - 1];
          v499 = &stack->list[v71 - 2];
          v73 = v499;
          v74 = idSWFScriptVar::ToFloat(this: v72);
          v75 = (float)((float)v74 * idSWFScriptVar::ToFloat(this: v73));
          idSWFScriptVar::Free(this: v73);
          v73->value.f = v75;
          v73->type = SWF_VAR_FLOAT;
          goto LABEL_403;
        case Action_Divide:
          v76 = stack->num;
          v78 = &stack->list[v76 - 1];
          v499 = &stack->list[v76 - 2];
          v77 = v499;
          v79 = idSWFScriptVar::ToFloat(this: v499);
          v80 = (float)((float)v79 / idSWFScriptVar::ToFloat(this: v78));
          idSWFScriptVar::Free(this: v77);
          v77->value.f = v80;
          v77->type = SWF_VAR_FLOAT;
          goto LABEL_403;
        case Action_Equals:
          v81 = stack->num;
          v82 = &stack->list[v81 - 1];
          v83 = idSWFScriptVar::ToFloat(this: &stack->list[v81 - 2]);
          v84 = v83 == idSWFScriptVar::ToFloat(this: v82);
          goto LABEL_78;
        case Action_Less:
          v85 = stack->num;
          v86 = &stack->list[v85 - 1];
          v87 = idSWFScriptVar::ToFloat(this: &stack->list[v85 - 2]);
          v84 = v87 < idSWFScriptVar::ToFloat(this: v86);
          goto LABEL_78;
        case Action_And:
          if ( !idSWFScriptVar::ToBool(this: &stack->list[stack->num - 2])
            || (v84 = true, !idSWFScriptVar::ToBool(this: &stack->list[stack->num - 1])) )
          {
            v84 = false;
          }
          goto LABEL_78;
        case Action_Or:
          if ( idSWFScriptVar::ToBool(this: &stack->list[stack->num - 2])
            || (v84 = false, idSWFScriptVar::ToBool(this: &stack->list[stack->num - 1])) )
          {
            v84 = true;
          }
LABEL_78:
          v88 = &stack->list[stack->num - 2];
          idSWFScriptVar::Free(this: v88);
          v88->value.b = v84;
          v88->type = SWF_VAR_BOOL;
          goto LABEL_403;
        case Action_Not:
          v499 = &stack->list[stack->num - 1];
          v89 = v499;
          v90 = (_cntlzw(idSWFScriptVar::ToBool(this: v499)) & 0x20) != 0;
          idSWFScriptVar::Free(this: v89);
          v89->value.b = v90;
          v89->type = SWF_VAR_BOOL;
          goto LABEL_405;
        case Action_StringEquals:
          v91 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v556, result: (idStr *)&stack->list[stack->num - 1]);
          v92 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v574, result: (idStr *)&stack->list[stack->num - 2]);
          v93 = (_cntlzw(idStr::Cmp(s1: v92->data, s2: v91->data)) & 0x20) != 0;
          v94 = &stack->list[stack->num - 2];
          idSWFScriptVar::Free(this: v94);
          v94->value.b = v93;
          v94->type = SWF_VAR_BOOL;
          idStr::FreeData(this: &v574);
          idStr::FreeData(this: &v556);
          goto LABEL_403;
        case Action_StringLength:
          len = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v584, result: (idStr *)&stack->list[stack->num - 1])->len;
          v96 = &stack->list[stack->num];
          idSWFScriptVar::Free(this: v96 - 1);
          v96[-1].value.i = len;
          v96[-1].type = SWF_VAR_INTEGER;
          idStr::FreeData(this: &v584);
          goto LABEL_405;
        case Action_StringExtract:
          v101 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v562, result: (idStr *)&stack->list[stack->num - 3]);
          v102 = (idSWFScriptVar *)stack->num;
          v103 = &stack->list[(int)v102 - 1];
          v104 = &stack->list[(int)v102 - 2];
          v499 = v102;
          v105 = idSWFScriptVar::ToInteger(this: v103);
          v106 = idSWFScriptVar::ToInteger(this: v104);
          v107 = idStr::Mid(this: &v590, result: v101, start: v106, len: v105);
          v108 = &stack->list[stack->num - 3];
          idSWFScriptVar::Free(this: v108);
          v108->type = SWF_VAR_STRING;
          v108->value.i = (int)idSWFScriptString::Alloc(s: v107);
          idStr::FreeData(this: &v590);
          idStr::FreeData(this: &v562);
          v109 = 2;
          goto LABEL_404;
        case Action_Pop:
          goto LABEL_403;
        case Action_ToInteger:
          v499 = &stack->list[stack->num - 1];
          v119 = v499;
          v120 = idSWFScriptVar::ToInteger(this: v499);
          idSWFScriptVar::Free(this: v119);
          v119->value.i = v120;
          v119->type = SWF_VAR_INTEGER;
          goto LABEL_405;
        case Action_GetVariable:
          idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v544, result: (idStr *)&stack->list[stack->num - 1]);
          v132 = result[4].type - 1;
          if ( v132 >= 0 )
          {
            v133 = 4 * v132;
            do
            {
              v134 = idSWFScriptObject::Get(
                       this: (idSWFScriptObject *)&v534.variablesHash[13],
                       result: *(idSWFScriptVar **)(v133 + result[3].value.i),
                       name: v544.data);
              idSWFScriptVar::operator=(this: &stack->list[stack->num - 1], other: v134);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variablesHash[13]);
              if ( stack->list[stack->num - 1].type != SWF_VAR_UNDEF )
                break;
              --v132;
              v133 -= 4;
            }
            while ( v132 >= 0 );
          }
          if ( stack->list[stack->num - 1].type == SWF_VAR_UNDEF && swf_debug.valueInteger > 1 )
            idLib::Printf(fmt: (const char *)v533.variablesHash[4], v544.data);
          idStr::FreeData(this: &v544);
          goto LABEL_405;
        case Action_SetVariable:
          idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v540, result: (idStr *)&stack->list[stack->num - 2]);
          v135 = 0;
          v136 = result[4].type - 1;
          if ( v136 >= 0 )
          {
            v137 = 4 * v136;
            while ( !idSWFScriptObject::HasProperty(
                       this: *(idSWFScriptObject **)(v137 + result[3].value.i),
                       name: v540.data) )
            {
              --v136;
              v137 -= 4;
              if ( v136 < 0 )
                goto LABEL_106;
            }
            idSWFScriptObject::Set(
              this: *(idSWFScriptObject **)(4 * v136 + result[3].value.i),
              name: v540.data,
              value: &stack->list[stack->num - 1]);
            v135 = 1;
          }
LABEL_106:
          if ( v135 == 0 )
            idSWFScriptObject::Set(this: thisObject, name: v540.data, value: &stack->list[stack->num - 1]);
          v138 = stack->num;
          v139 = v138 - 2;
          if ( v138 - 2 <= stack->size
            || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v138 - 2) != 0 )
          {
            size = stack->size;
            if ( v139 < size )
              size = v139;
            stack->num = size;
          }
          idStr::FreeData(this: &v540);
          goto LABEL_405;
        case Action_StringAdd:
          v97 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v560, result: (idStr *)&stack->list[stack->num - 1]);
          v98 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v576, result: (idStr *)&stack->list[stack->num - 2]);
          v99 = operator+(result: &v553, a: v98, b: v97);
          v100 = &stack->list[stack->num - 2];
          idSWFScriptVar::Free(this: v100);
          v100->type = SWF_VAR_STRING;
          v100->value.i = (int)idSWFScriptString::Alloc(s: v99);
          idStr::FreeData(this: &v553);
          idStr::FreeData(this: &v576);
          idStr::FreeData(this: &v560);
          goto LABEL_403;
        case Action_GetProperty:
          if ( v9 != nullptr )
          {
            v155 = idSWFScriptVar::ToString(
                     this: (idSWFScriptVar *)&v589,
                     result: (idStr *)&stack->list[stack->num - 2]);
            v156 = idSWFSpriteInstance::ResolveTarget(this: v9, targetName: v155->data);
            idStr::FreeData(this: &v589);
            v157 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
            PropertyName = `anonymous namespace'::GetPropertyName(index: v157);
            v159 = idSWFScriptObject::Get(
                     this: (idSWFScriptObject *)&v534.variablesHash[1],
                     result: (idSWFScriptVar *)v156->scriptObject,
                     name: PropertyName);
            idSWFScriptVar::operator=(this: &stack->list[stack->num - 2], other: v159);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variablesHash[1]);
          }
          else if ( (int)v14 > 0 )
          {
            idLib::Printf(fmt: v522);
          }
          goto LABEL_403;
        case Action_SetProperty:
          if ( v9 != nullptr )
          {
            v160 = idSWFScriptVar::ToString(
                     this: (idSWFScriptVar *)&v570,
                     result: (idStr *)&stack->list[stack->num - 3]);
            v161 = idSWFSpriteInstance::ResolveTarget(this: v9, targetName: v160->data);
            idStr::FreeData(this: &v570);
            v162 = stack->num;
            v163 = &stack->list[v162 - 1];
            v164 = idSWFScriptVar::ToInteger(this: &stack->list[v162 - 2]);
            v165 = `anonymous namespace'::GetPropertyName(index: v164);
            idSWFScriptObject::Set(this: v161->scriptObject, name: v165, value: v163);
            v109 = 3;
          }
          else
          {
            if ( (int)v14 > 0 )
              idLib::Printf(fmt: (const char *)v533.variablesHash[3]);
            v109 = 3;
          }
          goto LABEL_404;
        case Action_Trace:
          v166 = (-(int)v14 & (unsigned int)~(_DWORD)v14) >> 31;
          v167 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v582, result: (idStr *)&stack->list[stack->num - 1]);
          idLib::PrintfIf(condition: v166, fmt: v524, v167->data);
          idStr::FreeData(this: &v582);
          goto LABEL_403;
        case Action_StringLess:
          v110 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v564, result: (idStr *)&stack->list[stack->num - 1]);
          v111 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v578, result: (idStr *)&stack->list[stack->num - 2]);
          v112 = (unsigned int)idStr::Cmp(s1: v111->data, s2: v110->data) >> 31;
          v113 = &stack->list[stack->num - 2];
          idSWFScriptVar::Free(this: v113);
          v113->value.b = v112;
          v113->type = SWF_VAR_BOOL;
          idStr::FreeData(this: &v578);
          idStr::FreeData(this: &v564);
          goto LABEL_403;
        case Action_RandomNumber:
          if ( (_S13_17 & 1) != 0 )
          {
            v171 = v508;
          }
          else
          {
            _S13_17 |= 1u;
            v170 = Sys_Milliseconds();
            v171 = v508;
            v508->seed = v170;
          }
          v499 = &stack->list[stack->num - 1];
          v172 = v499;
          v173 = idSWFScriptVar::ToInteger(this: v499);
          v174 = idRandom2::RandomInt(this: v171, max: v173);
          idSWFScriptVar::Free(this: v172);
          v172->value.i = v174;
          v172->type = SWF_VAR_INTEGER;
          goto LABEL_405;
        case Action_CharToAscii:
          v121 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v580, result: (idStr *)&stack->list[stack->num - 1]);
          v122 = &stack->list[stack->num];
          v123.i = *v121->data;
          idSWFScriptVar::Free(this: v122 - 1);
          v122[-1].value = v123;
          v122[-1].type = SWF_VAR_INTEGER;
          idStr::FreeData(this: &v580);
          goto LABEL_405;
        case Action_AsciiToChar:
          v499 = &stack->list[stack->num - 1];
          v124 = v499;
          HIDWORD(v125) = idSWFScriptVar::ToInteger(this: v499);
          v128 = va::va(
                   this: &v593,
                   fmt: v518,
                   a3: v125,
                   a4: v127,
                   a5: v126,
                   a6: v493,
                   a7: v494,
                   a8: v495,
                   a9: v496,
                   a10: v497,
                   a11: v498);
          idSWFScriptVar::SetString(this: v124, s: v128);
          goto LABEL_405;
        case Action_GetTime:
          v168 = Sys_Milliseconds();
          v169 = idList<idSWFScriptVar,5>::Alloc(this: stack);
          idSWFScriptVar::Free(this: v169);
          v169->value.i = v168;
          v169->type = SWF_VAR_INTEGER;
          goto LABEL_405;
        case Action_Delete:
          if ( (int)v14 > 0 )
            idLib::Printf(fmt: v525);
          v109 = 2;
          goto LABEL_404;
        case Action_Delete2:
          if ( (int)v14 <= 0 )
            goto LABEL_403;
          v154 = v507;
          goto LABEL_402;
        case Action_DefineLocal:
          v487 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v583, result: (idStr *)&stack->list[stack->num - 2]);
          idSWFScriptObject::Set(
            this: *(idSWFScriptObject **)(4 * result[4].type + result[3].value.i - 4),
            name: v487->data,
            value: &stack->list[stack->num - 1]);
          idStr::FreeData(this: &v583);
          v109 = 2;
          goto LABEL_404;
        case Action_CallFunction:
          idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v545, result: (idStr *)&stack->list[stack->num - 1]);
          v175 = SWF_VAR_UNDEF;
          v510.type = SWF_VAR_UNDEF;
          v176 = 0;
          v177 = result[4].type - 1;
          if ( v177 < 0 )
            goto LABEL_151;
          v178 = 4 * v177;
          break;
        case Action_Return:
          v490 = &stack->list[stack->num];
          --callstackLevel;
          idSWFScriptVar::idSWFScriptVar(this: v594, other: v490 - 1);
          return (idSWFScriptFunction_Script *)v594;
        case Action_Modulo:
          v441 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
          v442 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 2]);
          list = stack->list;
          if ( v441 == 0 )
          {
            v310 = (idSWFScriptVar *)stack->num;
            goto LABEL_382;
          }
          v444 = v442 % v441;
          v445 = v441 & ~(__ROL4__(v442, 1) - 1);
          v446 = &list[stack->num - 2];
          __twllei(v441, 0);
          __twlgei(v445, 0xFFFFFFFF);
          idSWFScriptVar::SetInteger(this: v446, i: (idSWFScriptVar::swfScriptVarValue_t *)v444);
          goto LABEL_403;
        case Action_NewObject:
          v357 = idSWFScriptObject::Alloc();
          idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v541, result: (idStr *)&stack->list[stack->num - 1]);
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
          if ( idStr::Cmp(s1: v541.data, s2: v517) != 0 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v592);
            v361 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
            idList<idSWFScriptVar,5>::SetNum(this: &v592, newNum: v361);
            idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
            v362 = 0;
            if ( v592.num > 0 )
            {
              v363 = 0;
              do
              {
                idSWFScriptVar::operator=(this: &v592.list[v363], other: &stack->list[stack->num - 1]);
                idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
                ++v362;
                ++v363;
              }
              while ( v362 < v592.num );
            }
            idSWFScriptObject::Get(this: &v533, result: *(idSWFScriptVar **)result[3].value.i, name: v541.data);
            if ( v533.refCount == 7 )
            {
              v364 = v533.variables.list;
              v365 = (idSWFScriptObject *)(*(int (__fastcall **)(idSWFScriptObject::swfNamedVar_t *))(v533.variables.list->index + 16))(a1: v533.variables.list);
              idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v533.variablesHash[15], o: v365);
              idSWFScriptObject::Set(this: v357, name: v505, value: (const idSWFScriptVar *)&v533.variablesHash[15]);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.variablesHash[15]);
              v366 = (idSWFScriptObject *)(*(int (__fastcall **)(idSWFScriptObject::swfNamedVar_t *))(v364->index + 16))(a1: v364);
              v357->prototype = v366;
              ++v366->refCount;
              (*(void (__fastcall **)(idSWFScriptVar *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(v364->index + 4))(
                a1: &v535,
                a2: v364,
                a3: v357,
                a4: &v592);
              idSWFScriptVar::Free(this: &v535);
            }
            else
            {
              idLib::Warning(fmt: v519, v541.data);
            }
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v592);
          }
          else
          {
            idSWFScriptObject::MakeArray(this: v357);
            v358 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
            idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
            for ( i = 0; i < v358; ++i )
            {
              idSWFScriptObject::Set(this: v357, index: i, value: &stack->list[stack->num - 1]);
              idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
            }
            idSWFScriptObject::Get(this: &v534, result: *(idSWFScriptVar **)result[3].value.i, name: v506);
            v360 = (idSWFScriptObject *)(*(int (__fastcall **)(idSWFScriptObject::swfNamedVar_t *))(v534.variables.list->index
                                                                                                  + 16))(a1: v534.variables.list);
            idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v533.variablesHash[11], o: v360);
            idSWFScriptObject::Set(this: v357, name: v505, value: (const idSWFScriptVar *)&v533.variablesHash[11]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.variablesHash[11]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534);
          }
          v367 = idList<idSWFScriptVar,5>::Alloc(this: stack);
          idSWFScriptVar::Free(this: v367);
          if ( v357 != nullptr )
          {
            v367->value.i = (int)v357;
            v367->type = SWF_VAR_OBJECT;
            ++v357->refCount;
          }
          else
          {
            v367->type = SWF_VAR_NULL;
          }
          if ( v357->refCount-- == 1 )
          {
            idSWFScriptObject::~idSWFScriptObject(this: v357);
            idMem::Free(this: v502, ptr: v357, align: ALIGN_16);
          }
          idStr::FreeData(this: &v541);
          goto LABEL_405;
        case Action_DefineLocal2:
          v533.objectType = NUM_SWF_OBJECT_TYPES;
          v488 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v585, result: (idStr *)&stack->list[stack->num - 1]);
          idSWFScriptObject::Set(
            this: *(idSWFScriptObject **)(4 * result[4].type + result[3].value.i - 4),
            name: v488->data,
            value: (const idSWFScriptVar *)&v533.objectType);
          idStr::FreeData(this: &v585);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.objectType);
          goto LABEL_403;
        case Action_InitArray:
          v343 = idSWFScriptObject::Alloc();
          idSWFScriptObject::MakeArray(this: v343);
          v344 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
          for ( j = 0; j < v344; ++j )
          {
            idSWFScriptObject::Set(this: v343, index: j, value: &stack->list[stack->num - 1]);
            v346 = stack->num;
            v347 = v346 - 1;
            if ( v346 - 1 <= stack->size
              || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v346 - 1) != 0 )
            {
              v348 = stack->size;
              if ( v347 < v348 )
                v348 = v347;
              stack->num = v348;
            }
          }
          v349 = idList<idSWFScriptVar,5>::Alloc(this: stack);
          idSWFScriptVar::Free(this: v349);
          if ( v343 != nullptr )
            goto LABEL_298;
          v349->type = SWF_VAR_NULL;
          goto LABEL_299;
        case Action_InitObject:
          v343 = idSWFScriptObject::Alloc();
          v351 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
          if ( v351 > 0 )
          {
            for ( k = v351; k != 0; --k )
            {
              v353 = idSWFScriptVar::ToString(
                       this: (idSWFScriptVar *)&v561,
                       result: (idStr *)&stack->list[stack->num - 2]);
              idSWFScriptObject::Set(this: v343, name: v353->data, value: &stack->list[stack->num - 1]);
              idStr::FreeData(this: &v561);
              v354 = stack->num;
              v355 = v354 - 2;
              if ( v354 - 2 <= stack->size
                || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v354 - 2) != 0 )
              {
                v356 = stack->size;
                if ( v355 < v356 )
                  v356 = v355;
                stack->num = v356;
              }
            }
          }
          v349 = idList<idSWFScriptVar,5>::Alloc(this: stack);
          idSWFScriptVar::Free(this: v349);
          if ( v343 != nullptr )
          {
LABEL_298:
            v349->value.i = (int)v343;
            v349->type = SWF_VAR_OBJECT;
            ++v343->refCount;
          }
          else
          {
            v349->type = SWF_VAR_NULL;
          }
LABEL_299:
          if ( v343->refCount-- == 1 )
          {
            idSWFScriptObject::~idSWFScriptObject(this: v343);
            idMem::Free(this: v502, ptr: v343, align: ALIGN_16);
          }
          goto LABEL_405;
        case Action_TypeOf:
          v499 = &stack->list[stack->num - 1];
          v402 = v499;
          v403 = idSWFScriptVar::TypeOf(this: v499);
          idSWFScriptVar::SetString(this: v402, s: v403);
          goto LABEL_405;
        case Action_TargetPath:
          v377 = stack->num;
          v378 = stack->list;
          v379 = &stack->list[v377];
          v499 = (idSWFScriptVar *)v377;
          if ( v379[-1].type == SWF_VAR_OBJECT
            && (v499 = (idSWFScriptVar *)v377, LODWORD(v381.f) = v378[v377 - 1].value, *(_DWORD *)(v381.i + 88) == 2)
            && (v382 = *(_DWORD *)(v381.i + 92)) != 0 )
          {
            idStr::idStr(this: (idStr *)&v534.variablesHash[3], text: *(const char **)(v382 + 60));
            if ( *(_DWORD *)(v381.i + 88) == 2 )
              v383 = *(_DWORD *)(v381.i + 92);
            else
              v383 = 0;
            for ( m = *(_DWORD *)(v383 + 12); m != 0; m = *(_DWORD *)(m + 12) )
            {
              idStr::idStr(this: &v550, text: v521);
              v385 = operator+(result: &v565, a: *(const char **)(m + 60), b: &v550);
              v386 = operator+(result: &v563, a: v385, b: (const idStr *)&v534.variablesHash[3]);
              v387 = v386->len;
              idStr::EnsureAlloced(
                this: (idStr *)&v534.variablesHash[3],
                amount: v386->len + 1,
                keepold: false,
                geometricGrowth: false);
              memcpy(Dst: (void *)v534.variablesHash[4], Src: v386->data, Size: v387);
              *(_BYTE *)(v387 + v534.variablesHash[4]) = 0;
              v534.variablesHash[3] = v387;
              idStr::FreeData(this: &v563);
              idStr::FreeData(this: &v565);
              idStr::FreeData(this: &v550);
            }
            v388 = &stack->list[stack->num];
            idSWFScriptVar::Free(this: v388 - 1);
            v388[-1].type = SWF_VAR_STRING;
            v388[-1].value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)&v534.variablesHash[3]);
            idStr::FreeData(this: (idStr *)&v534.variablesHash[3]);
          }
          else
          {
            v380 = &v378[v377];
            idSWFScriptVar::Free(this: v380 - 1);
            v380[-1].type = SWF_VAR_UNDEF;
          }
          goto LABEL_405;
        case Action_Enumerate:
          idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v551, result: (idStr *)&stack->list[stack->num - 1]);
          v272 = result[4].type - 1;
          if ( v272 >= 0 )
          {
            v273 = 4 * v272;
            do
            {
              v274 = idSWFScriptObject::Get(
                       this: (idSWFScriptObject *)&v538.variablesHash[7],
                       result: *(idSWFScriptVar **)(v273 + result[3].value.i),
                       name: v551.data);
              idSWFScriptVar::operator=(this: &stack->list[stack->num - 1], other: v274);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variablesHash[7]);
              if ( stack->list[stack->num - 1].type != SWF_VAR_UNDEF )
                break;
              --v272;
              v273 -= 4;
            }
            while ( v272 >= 0 );
          }
          v275 = stack->num;
          v276 = stack->list;
          v277 = &stack->list[v275];
          v499 = (idSWFScriptVar *)v275;
          v278 = v277[-1].type;
          v279 = v275;
          if ( v278 == SWF_VAR_OBJECT )
          {
            object = v276[v279 - 1].value.object;
            ++object->refCount;
            v282 = &stack->list[stack->num];
            idSWFScriptVar::Free(this: v282 - 1);
            v282[-1].type = SWF_VAR_NULL;
            v283 = 0;
            if ( object->variables.num > 0 )
            {
              v284 = 0;
              do
              {
                str = object->variables.list[v284].name.str;
                idList<idSWFScriptVar,5>::PreAllocateWithGranularity(this: stack, newSize: stack->num + 1);
                v286 = stack->num;
                v287 = stack->size;
                if ( v286 >= v287 )
                {
                  v288 = &stack->list[v287 - 1];
                }
                else
                {
                  v288 = &stack->list[v286];
                  stack->num = v286 + 1;
                }
                idSWFScriptVar::Free(this: v288);
                v288->type = SWF_VAR_STRING;
                idStr::idStr(this: &v549, text: str);
                v288->value.i = (int)idSWFScriptString::Alloc(s: &v549);
                idStr::FreeData(this: &v549);
                ++v283;
                ++v284;
              }
              while ( v283 < object->variables.num );
            }
            if ( object->refCount-- == 1 )
            {
              idSWFScriptObject::~idSWFScriptObject(this: object);
              idMem::Free(this: v502, ptr: object, align: ALIGN_16);
            }
          }
          else
          {
            v280 = &v276[v279];
            idSWFScriptVar::Free(this: &v276[v279 - 1]);
            v280[-1].type = SWF_VAR_NULL;
          }
          idStr::FreeData(this: &v551);
          v10 = (idSWFSpriteInstance *)type;
          goto LABEL_405;
        case Action_Add2:
          v404 = stack->num;
          v405 = stack->list;
          v406 = &stack->list[v404];
          v499 = (idSWFScriptVar *)v404;
          v407 = v406[-1].type;
          if ( v407 == SWF_VAR_STRING || (v151 = v407 != SWF_VAR_STRINGID, v408 = 0, !v151) )
            v408 = 1;
          if ( v408 != 0 )
            goto LABEL_358;
          v499 = (idSWFScriptVar *)v404;
          v409 = v405[v404 - 2].type;
          if ( v409 == SWF_VAR_STRING || (v151 = v409 != SWF_VAR_STRINGID, v410 = 0, !v151) )
            v410 = 1;
          if ( v410 != 0 )
          {
LABEL_358:
            v499 = (idSWFScriptVar *)v404;
            v414 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v573, result: (idStr *)&v405[v404 - 1]);
            v415 = idSWFScriptVar::ToString(
                     this: (idSWFScriptVar *)&v571,
                     result: (idStr *)&stack->list[stack->num - 2]);
            v416 = operator+(result: &v569, a: v415, b: v414);
            idSWFScriptVar::SetString(this: &stack->list[stack->num - 2], s: v416);
            idStr::FreeData(this: &v569);
            idStr::FreeData(this: &v571);
            idStr::FreeData(this: &v573);
          }
          else
          {
            v411 = &v405[v404 - 2];
            v499 = v411;
            v412 = idSWFScriptVar::ToFloat(this: &v405[v404 - 1]);
            v413 = idSWFScriptVar::ToFloat(this: v411);
            idSWFScriptVar::SetFloat(this: v411, f: (float)((float)v412 + (float)v413));
          }
          goto LABEL_403;
        case Action_Less2:
          v417 = stack->num;
          v418 = stack->list;
          v419 = &stack->list[v417];
          v499 = (idSWFScriptVar *)v417;
          v420 = v419[-1].type;
          if ( v420 == SWF_VAR_STRING || (v151 = v420 != SWF_VAR_STRINGID, v421 = 0, !v151) )
            v421 = 1;
          if ( v421 != 0 )
          {
            v499 = (idSWFScriptVar *)v417;
            v422 = v418[v417 - 2].type;
            if ( v422 == SWF_VAR_STRING || (v151 = v422 != SWF_VAR_STRINGID, v423 = 0, !v151) )
              v423 = 1;
            if ( v423 != 0 )
            {
              v499 = (idSWFScriptVar *)v417;
              v424 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v577, result: (idStr *)&v418[v417 - 1]);
              v425 = idSWFScriptVar::ToString(
                       this: (idSWFScriptVar *)&v575,
                       result: (idStr *)&stack->list[stack->num - 2]);
              v426 = idStr::Cmp(s1: v425->data, s2: v424->data);
              idSWFScriptVar::SetBool(this: &stack->list[stack->num - 2], b: v426 < 0);
              idStr::FreeData(this: &v575);
              idStr::FreeData(this: &v577);
              goto LABEL_403;
            }
          }
          v427 = &v418[v417 - 1];
          v428 = idSWFScriptVar::ToFloat(this: &v418[v417 - 2]);
          v429 = v428 < idSWFScriptVar::ToFloat(this: v427);
          goto LABEL_369;
        case Action_Equals2:
          v299 = stack->num;
          v301 = &stack->list[v299 - 1];
          v499 = &stack->list[v299 - 2];
          v300 = v499;
          v302 = idSWFScriptVar::AbstractEquals(this: v301, other: v499);
          idSWFScriptVar::Free(this: v300);
          v300->value.b = v302;
          v300->type = SWF_VAR_BOOL;
          goto LABEL_403;
        case Action_ToNumber:
          v499 = &stack->list[stack->num - 1];
          v398 = v499;
          v399 = idSWFScriptVar::ToFloat(this: v499);
          idSWFScriptVar::Free(this: v398);
          v398->value.f = v399;
          v398->type = SWF_VAR_FLOAT;
          goto LABEL_405;
        case Action_ToString:
          v400 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v567, result: (idStr *)&stack->list[stack->num - 1]);
          v401 = &stack->list[stack->num];
          idSWFScriptVar::Free(this: v401 - 1);
          v401[-1].type = SWF_VAR_STRING;
          v401[-1].value.i = (int)idSWFScriptString::Alloc(s: v400);
          idStr::FreeData(this: &v567);
          goto LABEL_405;
        case Action_PushDuplicate:
          idSWFScriptVar::idSWFScriptVar(
            this: (idSWFScriptVar *)&v533.variablesHash[9],
            other: &stack->list[stack->num - 1]);
          v481 = idList<idSWFScriptVar,5>::Alloc(this: stack);
          idSWFScriptVar::operator=(this: v481, other: (const idSWFScriptVar *)&v533.variablesHash[9]);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.variablesHash[9]);
          goto LABEL_405;
        case Action_StackSwap:
          idSWFScriptVar::idSWFScriptVar(
            this: (idSWFScriptVar *)&v533.variablesHash[13],
            other: &stack->list[stack->num - 1]);
          v482 = stack->num;
          v483 = &stack->list[v482];
          v484 = &stack->list[v482 - 2];
          v499 = (idSWFScriptVar *)v482;
          idSWFScriptVar::operator=(this: v483 - 1, other: v484);
          idSWFScriptVar::operator=(
            this: &stack->list[stack->num - 1],
            other: (const idSWFScriptVar *)&v533.variablesHash[13]);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.variablesHash[13]);
          goto LABEL_405;
        case Action_GetMember:
          v307 = stack->list;
          v499 = (idSWFScriptVar *)stack->num;
          if ( (v307[(int)v499 - 2].type == SWF_VAR_UNDEF || v307[(int)v499 - 2].type == SWF_VAR_NULL) && (int)v14 > 1 )
          {
            if ( v9 != nullptr )
              v308 = (int)v9->name.str;
            else
              v308 = v533.variables.size;
            v309 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v588, result: (idStr *)&v307[(int)v499 - 1]);
            idLib::Printf(fmt: v530, v309->data, v308);
            idStr::FreeData(this: &v588);
          }
          list = stack->list;
          v499 = (idSWFScriptVar *)stack->num;
          v310 = v499;
          if ( list[(int)v499 - 2].type == SWF_VAR_OBJECT )
          {
            v312 = list[(int)v499 - 1].type;
            v313 = *((idSWFScriptVar **)&list[(int)v499 - 1] - 1);
            if ( v312 == SWF_VAR_FLOAT || v312 == SWF_VAR_INTEGER || (v151 = v312 != SWF_VAR_BOOL, v314 = 0, !v151) )
              v314 = 1;
            v315 = &list[(_DWORD)v499];
            if ( v314 != 0 )
            {
              v316 = idSWFScriptVar::ToInteger(this: v315 - 1);
              v317 = idSWFScriptObject::Get(this: &v538, result: v313, index: v316);
              idSWFScriptVar::operator=(this: &stack->list[stack->num - 2], other: v317);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538);
            }
            else
            {
              v318 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v554, result: (idStr *)&v315[-1]);
              v319 = idSWFScriptObject::Get(
                       this: (idSWFScriptObject *)&v534.variables.granularity,
                       result: v313,
                       name: v318->data);
              idSWFScriptVar::operator=(this: &stack->list[stack->num - 2], other: v319);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variables.granularity);
              idStr::FreeData(this: &v554);
            }
            v320 = stack->list;
            v499 = (idSWFScriptVar *)stack->num;
            if ( v320[(int)v499 - 2].type == SWF_VAR_UNDEF && swf_debug.valueInteger > 1 )
            {
              v321 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v555, result: (idStr *)&v320[(int)v499 - 1]);
              idLib::Printf(fmt: (const char *)v533.variablesHash[0], v321->data);
              idStr::FreeData(this: &v555);
            }
          }
          else
          {
            v322 = list[(int)v499 - 2].type;
            if ( v322 == SWF_VAR_STRING || (v151 = v322 != SWF_VAR_STRINGID, v323 = 0, !v151) )
              v323 = 1;
            if ( v323 != 0 )
            {
              idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v542, result: (idStr *)&list[(int)v499 - 1]);
              if ( idStr::Cmp(s1: v542.data, s2: v532) != 0 )
              {
                if ( idStr::Cmp(s1: v542.data, s2: v513) != 0 )
                {
                  v326 = &stack->list[stack->num - 2];
                  idSWFScriptVar::Free(this: v326);
                  v326->type = SWF_VAR_UNDEF;
                }
              }
              else
              {
                v324 = idSWFScriptVar::ToString(
                         this: (idSWFScriptVar *)&v557,
                         result: (idStr *)&stack->list[stack->num - 2])->len;
                v325 = &stack->list[stack->num - 2];
                idSWFScriptVar::Free(this: v325);
                v325->value.i = v324;
                v325->type = SWF_VAR_INTEGER;
                idStr::FreeData(this: &v557);
              }
              idStr::FreeData(this: &v542);
            }
            else if ( list[(int)v499 - 2].type == SWF_VAR_FUNCTION )
            {
              idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v548, result: (idStr *)&list[(int)v499 - 1]);
              v327 = idStr::Cmp(s1: v548.data, s2: v515);
              v328 = stack->num;
              v329 = stack->list;
              if ( v327 != 0 )
              {
                v334 = &v329[v328 - 2];
                idSWFScriptVar::Free(this: v334);
                v334->type = SWF_VAR_UNDEF;
              }
              else
              {
                v330 = *((_DWORD *)&v329[v328 - 1] - 1);
                v331 = (idSWFScriptObject *)(*(int (__fastcall **)(int))(*(_DWORD *)v330 + 16))(a1: v330);
                if ( v331 == nullptr )
                {
                  v331 = idSWFScriptObject::Alloc();
                  idSWFScriptObject::Get(
                    this: (idSWFScriptObject *)&v534.variables.num,
                    result: *(idSWFScriptVar **)result[3].value.i,
                    name: v506);
                  v332 = (idSWFScriptObject *)(*(int (__fastcall **)(int))(*(_DWORD *)v534.variables.size + 16))(a1: v534.variables.size);
                  idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v533.variablesHash[7], o: v332);
                  idSWFScriptObject::Set(this: v331, name: v505, value: (const idSWFScriptVar *)&v533.variablesHash[7]);
                  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v533.variablesHash[7]);
                  (*(void (__fastcall **)(int, idSWFScriptObject *))(*(_DWORD *)v330 + 20))(a1: v330, a2: v331);
                  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variables.num);
                }
                v333 = idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v534.variablesHash[15], o: v331);
                idSWFScriptVar::operator=(this: &stack->list[stack->num - 2], other: v333);
                idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variablesHash[15]);
              }
              idStr::FreeData(this: &v548);
            }
            else
            {
LABEL_382:
              v443 = &list[(int)v310 - 2];
              idSWFScriptVar::Free(this: v443);
              v443->type = SWF_VAR_UNDEF;
            }
          }
          goto LABEL_403;
        case Action_SetMember:
          v335 = stack->list;
          v499 = (idSWFScriptVar *)stack->num;
          if ( v335[(int)v499 - 3].type != SWF_VAR_OBJECT )
            goto LABEL_288;
          v336 = v335[(int)v499 - 2].type;
          v337 = *((idSWFScriptObject **)&v335[(int)v499 - 2] - 1);
          if ( v336 == SWF_VAR_FLOAT || v336 == SWF_VAR_INTEGER || (v151 = v336 != SWF_VAR_BOOL, v338 = 0, !v151) )
            v338 = 1;
          v151 = v338 == 0;
          v339 = (char *)&v499[-1].value.i + 2;
          if ( v151 )
          {
            v342 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v559, result: (idStr *)&v335[(_DWORD)v339]);
            idSWFScriptObject::Set(this: v337, name: v342->data, value: &stack->list[stack->num - 1]);
            idStr::FreeData(this: &v559);
LABEL_288:
            v109 = 3;
          }
          else
          {
            v340 = &v335[(int)v499 - 1];
            v341 = idSWFScriptVar::ToInteger(this: &v335[(_DWORD)v339]);
            idSWFScriptObject::Set(this: v337, index: v341, value: v340);
            v109 = 3;
          }
          goto LABEL_404;
        case Action_Increment:
          v499 = &stack->list[stack->num - 1];
          v479 = v499;
          v480 = idSWFScriptVar::ToFloat(this: v499);
          idSWFScriptVar::SetFloat(this: v479, f: (float)((float)v480 + (float)1.0));
          goto LABEL_405;
        case Action_Decrement:
          v499 = &stack->list[stack->num - 1];
          v477 = v499;
          v478 = idSWFScriptVar::ToFloat(this: v499);
          idSWFScriptVar::SetFloat(this: v477, f: (float)((float)v478 - (float)1.0));
          goto LABEL_405;
        case Action_CallMethod:
          idSWFScriptVar::ToString(
            this: (idSWFScriptVar *)&v538.variablesHash[13],
            result: (idStr *)&stack->list[stack->num - 1]);
          if ( v538.variablesHash[13] == 0
            || (v202 = stack->num,
                v203 = stack->list,
                v204 = &stack->list[v202],
                v499 = (idSWFScriptVar *)v202,
                v204[-1].type == SWF_VAR_UNDEF)
            || (v499 = (idSWFScriptVar *)v202, v203[v202 - 1].type == SWF_VAR_NULL) )
          {
            idStr::operator=(this: (idStr *)&v538.variablesHash[13], text: v509);
          }
          v205 = SWF_VAR_UNDEF;
          v511.type = SWF_VAR_UNDEF;
          v206 = nullptr;
          v207 = stack->list;
          v499 = (idSWFScriptVar *)stack->num;
          if ( v207[(int)v499 - 2].type == SWF_VAR_OBJECT )
          {
            v206 = *((idSWFScriptVar **)&v207[(int)v499 - 1] - 1);
            v208 = idSWFScriptObject::Get(
                     this: (idSWFScriptObject *)&v538.variablesHash[5],
                     result: v206,
                     name: (const char *)v538.variablesHash[14]);
            idSWFScriptVar::operator=(this: &v511, other: v208);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variablesHash[5]);
            v205 = v511.type;
            if ( v511.type != SWF_VAR_FUNCTION )
            {
              v209 = ((swf_debug.valueInteger >= 0) + (swf_debug.valueInteger <= 1u)) & 1;
              v210 = (idStr *)idSWFScriptObject::DefaultValue(
                                this: (idSWFScriptObject *)&v538.variablesHash[9],
                                result: v206,
                                stringHint: true);
              v211 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v572, result: v210);
              idLib::PrintfIf(condition: v209, fmt: v512, v538.variablesHash[14], v211->data);
              idStr::FreeData(this: &v572);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variablesHash[9]);
            }
          }
          else
          {
            idLib::PrintfIf(
              condition: ((swf_debug.valueInteger >= 0) + (swf_debug.valueInteger <= 1u)) & 1,
              fmt: (const char *)v533.variablesHash[5],
              v538.variablesHash[14],
              (swf_debug.valueInteger >= 0) + (swf_debug.valueInteger <= 1u),
              swf_debug.valueInteger >= 0,
              ~(swf_debug.valueInteger ^ 1),
              1 - swf_debug.valueInteger);
          }
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 2);
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v591);
          v212 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
          idList<idSWFScriptVar,5>::SetNum(this: &v591, newNum: v212);
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
          v213 = 0;
          if ( v591.num > 0 )
          {
            v214 = 0;
            do
            {
              idSWFScriptVar::operator=(this: &v591.list[v214], other: &stack->list[stack->num - 1]);
              v215 = stack->num;
              v216 = v215 - 1;
              if ( v215 - 1 <= stack->size
                || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v215 - 1) != 0 )
              {
                v217 = stack->size;
                if ( v216 < v217 )
                  v217 = v216;
                stack->num = v217;
              }
              ++v213;
              ++v214;
            }
            while ( v213 < v591.num );
          }
          if ( v205 == SWF_VAR_FUNCTION )
          {
            v218 = (const idSWFScriptVar *)(*(int (__fastcall **)(idSWFScriptObject::swfObjectType_t *, int __struct_ptr, idSWFScriptVar *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v511.value.i + 4))(
                                             a1: &v534.objectType,
                                             a2: v511.value.i,
                                             a3: v206,
                                             a4: &v591);
            v219 = idList<idSWFScriptVar,5>::Alloc(this: stack);
            idSWFScriptVar::operator=(this: v219, other: v218);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.objectType);
          }
          else
          {
            v220 = idList<idSWFScriptVar,5>::Alloc(this: stack);
            idSWFScriptVar::Free(this: v220);
            v220->type = SWF_VAR_UNDEF;
          }
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v591);
          idSWFScriptVar::Free(this: &v511);
          idStr::FreeData(this: (idStr *)&v538.variablesHash[13]);
          v10 = (idSWFSpriteInstance *)type;
          goto LABEL_405;
        case Action_Enumerate2:
          v290 = &stack->list[stack->num];
          v291 = v290 - 1;
          if ( v290[-1].type == SWF_VAR_OBJECT )
          {
            v292 = v290[-1].value.object;
            ++v292->refCount;
            v293 = &stack->list[stack->num];
            idSWFScriptVar::Free(this: v293 - 1);
            v293[-1].type = SWF_VAR_NULL;
            v294 = 0;
            if ( v292->variables.num > 0 )
            {
              v295 = 0;
              do
              {
                v296 = v292->variables.list[v295].name.str;
                v297 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::SetString(this: v297, s: v296);
                ++v294;
                ++v295;
              }
              while ( v294 < v292->variables.num );
            }
            if ( v292->refCount-- == 1 )
            {
              idSWFScriptObject::~idSWFScriptObject(this: v292);
              idMem::Free(this: v502, ptr: v292, align: ALIGN_16);
            }
          }
          else
          {
            v499 = v290 - 1;
            idSWFScriptVar::Free(this: v290 - 1);
            v291->type = SWF_VAR_NULL;
          }
          goto LABEL_405;
        case Action_BitAnd:
          v447 = stack->num;
          v448 = &stack->list[v447 - 1];
          v499 = &stack->list[v447 - 2];
          v449 = v499;
          v450 = idSWFScriptVar::ToInteger(this: v448);
          v451 = idSWFScriptVar::ToInteger(this: v449);
          idSWFScriptVar::SetInteger(this: v449, i: (idSWFScriptVar::swfScriptVarValue_t *)(v450 & v451));
          goto LABEL_403;
        case Action_BitOr:
          v457 = stack->num;
          v458 = &stack->list[v457 - 1];
          v499 = &stack->list[v457 - 2];
          v459 = v499;
          v460 = idSWFScriptVar::ToInteger(this: v458);
          v461 = idSWFScriptVar::ToInteger(this: v459);
          idSWFScriptVar::SetInteger(this: v459, i: (idSWFScriptVar::swfScriptVarValue_t *)(v460 | v461));
          goto LABEL_403;
        case Action_BitXor:
          v472 = stack->num;
          v473 = &stack->list[v472 - 1];
          v499 = &stack->list[v472 - 2];
          v474 = v499;
          v475 = idSWFScriptVar::ToInteger(this: v473);
          v476 = idSWFScriptVar::ToInteger(this: v474);
          idSWFScriptVar::SetInteger(this: v474, i: (idSWFScriptVar::swfScriptVarValue_t *)(v475 ^ v476));
          goto LABEL_403;
        case Action_BitLShift:
          v452 = stack->num;
          v453 = &stack->list[v452 - 1];
          v499 = &stack->list[v452 - 2];
          v454 = v499;
          v455 = idSWFScriptVar::ToInteger(this: v453);
          v456 = idSWFScriptVar::ToInteger(this: v454);
          idSWFScriptVar::SetInteger(this: v454, i: (idSWFScriptVar::swfScriptVarValue_t *)(v456 << v455));
          goto LABEL_403;
        case Action_BitRShift:
          v462 = stack->num;
          v463 = &stack->list[v462 - 1];
          v499 = &stack->list[v462 - 2];
          v464 = v499;
          v465 = idSWFScriptVar::ToInteger(this: v463);
          v466 = idSWFScriptVar::ToInteger(this: v464);
          idSWFScriptVar::SetInteger(this: v464, i: (idSWFScriptVar::swfScriptVarValue_t *)(v466 >> v465));
          goto LABEL_403;
        case Action_BitURShift:
          v467 = stack->num;
          v468 = &stack->list[v467 - 1];
          v499 = &stack->list[v467 - 2];
          v469 = v499;
          v470 = idSWFScriptVar::ToInteger(this: v468);
          v471 = idSWFScriptVar::ToInteger(this: v469);
          idSWFScriptVar::SetInteger(this: v469, i: (idSWFScriptVar::swfScriptVarValue_t *)(v471 >> v470));
          goto LABEL_403;
        case Action_StrictEquals:
          v303 = stack->num;
          v305 = &stack->list[v303 - 1];
          v499 = &stack->list[v303 - 2];
          v304 = v499;
          v306 = idSWFScriptVar::StrictEquals(this: v305, other: v499);
          idSWFScriptVar::Free(this: v304);
          v304->value.b = v306;
          v304->type = SWF_VAR_BOOL;
          goto LABEL_403;
        case Action_Greater:
          v430 = stack->num;
          v431 = stack->list;
          v432 = &stack->list[v430];
          v499 = (idSWFScriptVar *)v430;
          v433 = v432[-1].type;
          if ( v433 == SWF_VAR_STRING || (v151 = v433 != SWF_VAR_STRINGID, v434 = 0, !v151) )
            v434 = 1;
          if ( v434 == 0 )
            goto _M228986_0;
          v499 = (idSWFScriptVar *)v430;
          v435 = v431[v430 - 2].type;
          if ( v435 == SWF_VAR_STRING || (v151 = v435 != SWF_VAR_STRINGID, v436 = 0, !v151) )
            v436 = 1;
          if ( v436 != 0 )
          {
            v499 = (idSWFScriptVar *)v430;
            v437 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v581, result: (idStr *)&v431[v430 - 2]);
            v438 = idSWFScriptVar::ToString(
                     this: (idSWFScriptVar *)&v579,
                     result: (idStr *)&stack->list[stack->num - 1]);
            idSWFScriptVar::SetBool(this: &stack->list[stack->num - 2], b: v438->data < v437->data);
            idStr::FreeData(this: &v579);
            idStr::FreeData(this: &v581);
          }
          else
          {
_M228986_0:
            v439 = &v431[v430 - 1];
            v440 = idSWFScriptVar::ToFloat(this: &v431[v430 - 2]);
            v429 = v440 > idSWFScriptVar::ToFloat(this: v439);
LABEL_369:
            idSWFScriptVar::SetBool(this: &stack->list[stack->num - 2], b: v429);
          }
LABEL_403:
          v109 = 1;
LABEL_404:
          idSWFStack::Pop(this: (idSWFStack *)stack, n: v109);
          goto LABEL_405;
        case Action_StringGreater:
          v114 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v566, result: (idStr *)&stack->list[stack->num - 2]);
          v115 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v586, result: (idStr *)&stack->list[stack->num - 1]);
          v116 = v114->data;
          v117 = v115->data;
          v118 = &stack->list[stack->num - 2];
          idSWFScriptVar::Free(this: v118);
          v118->type = SWF_VAR_BOOL;
          v118->value.b = v117 < v116;
          idStr::FreeData(this: &v586);
          idStr::FreeData(this: &v566);
          goto LABEL_403;
        case Action_Extends:
          v369 = &stack->list[stack->num];
          v499 = (idSWFScriptVar *)stack->num;
          function = v369[-1].value.function;
          LODWORD(v371.f) = v369[-2].value;
          idSWFStack::Pop(this: (idSWFStack *)stack, n: 2);
          v372 = idSWFScriptObject::Alloc();
          v373 = function->GetPrototype(this: function);
          v372->prototype = v373;
          ++v373->refCount;
          v374 = function->GetPrototype(this: function);
          v375 = idSWFScriptVar::idSWFScriptVar(this: &v537, o: v374);
          idSWFScriptObject::Set(this: v372, name: v505, value: v375);
          idSWFScriptVar::Free(this: &v537);
          v376 = idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v538.variables.num, nf: function);
          idSWFScriptObject::Set(this: v372, name: v509, value: v376);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variables.num);
          (*(void (__fastcall **)(idSWFScriptVar::swfScriptVarValue_t *__struct_ptr, idSWFScriptObject *))(*(_DWORD *)v371.i + 20))(
            a1: (idSWFScriptVar::swfScriptVarValue_t)v371.i,
            a2: v372);
          idSWFScriptObject::Release(this: v372);
          goto LABEL_405;
        case Action_GotoFrame:
          v32 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v32 += 2;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          bitstream->readp = v32;
          v12 = (const char *)((__ROL4__(*(v32 - 1), 8) | *(v32 - 2)) + 1);
          if ( v10 != nullptr )
          {
            idSWFSpriteInstance::RunTo(this: v10, targetFrame: (int)v12);
          }
          else if ( swf_debug.valueInteger > 0 )
          {
            idLib::Printf(fmt: v514, v12);
          }
          goto LABEL_405;
        case Action_StoreRegister:
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v485 = *(unsigned __int8 **)(HIDWORD(v13) + 12);
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v486 = *v485;
          *(_DWORD *)(HIDWORD(v13) + 12) = v485 + 1;
          idSWFScriptVar::operator=(
            this: (idSWFScriptVar *)(__ROL4__(v486, 3) + result[17].type),
            other: &stack->list[stack->num - 1]);
          goto LABEL_405;
        case Action_ConstantPool:
          idSWFConstantPool::Clear(this: (idSWFConstantPool *)&result[15]);
          v221 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v222 = 0;
          v221 += 2;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          bitstream->readp = v221;
          LODWORD(v224) = *(v221 - 2);
          v223 = __ROL4__(*(v221 - 1), 8);
          HIDWORD(v224) = v223 | v224;
          v225 = (unsigned __int16)(v223 | v224);
          if ( ((unsigned __int16)v223 | (unsigned __int16)v224) != 0 )
          {
            do
            {
              String = idSWFBitStream::ReadString(this: bitstream, a2: (int)v12, a3: (int)v11, a4: v16, a5: v224);
              idStr::idStr(this: &v547, text: String);
              *(float *)&v499 = COERCE_FLOAT(idSWFScriptString::Alloc(s: &v547));
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&result[15],
                obj: (const encounterGroupRole_t *)&v499);
              idStr::FreeData(this: &v547);
              ++v222;
            }
            while ( v222 < v225 );
          }
          goto LABEL_405;
        case Action_SetTarget:
          v12 = (const char *)idSWFBitStream::ReadData(
                                this: bitstream,
                                size: v18,
                                a3: (int)v11,
                                a4: v16,
                                a5: SHIDWORD(v15),
                                a6: v15,
                                a7: v14);
          if ( v9 != nullptr )
          {
            v10 = idSWFSpriteInstance::ResolveTarget(this: v9, targetName: v12);
            type = (const char *)&v10->isPlaying;
          }
          else if ( swf_debug.valueInteger > 0 )
          {
            idLib::Printf(fmt: (const char *)v533.variablesHash[2], v12);
          }
          goto LABEL_405;
        case Action_GoToLabel:
          v12 = (const char *)idSWFBitStream::ReadData(
                                this: bitstream,
                                size: v18,
                                a3: (int)v11,
                                a4: v16,
                                a5: SHIDWORD(v15),
                                a6: v15,
                                a7: v14);
          if ( v10 != nullptr )
          {
            Frame = idSWFSpriteInstance::FindFrame(this: v10, labelName: v12);
            idSWFSpriteInstance::RunTo(this: v10, targetFrame: Frame);
          }
          else if ( swf_debug.valueInteger > 0 )
          {
            idLib::Printf(fmt: v516, v12);
          }
          goto LABEL_405;
        case Action_DefineFunction2:
          v245 = idSWFBitStream::ReadString(this: bitstream, a2: (int)v12, a3: (int)v11, a4: v16, a5: v15);
          idStr::idStr(this: &v539, text: v245);
          v246 = idSWFScriptFunction_Script::Alloc();
          idSWFScriptFunction_Script::SetScope(this: v246, newScope: (const idList<idMD6Filter *,5> *)&result[3].value);
          idSWFConstantPool::Copy(this: &v246->constants, other: (const idSWFConstantPool *)&result[15]);
          v246->defaultSprite = (idSWFSpriteInstance *)result[3].type;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v247 = bitstream->readp + 2;
          bitstream->readp = v247;
          v248 = *(v247 - 2);
          v249 = __ROL4__(*(v247 - 1), 8);
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v250 = v249 | v248;
          LOBYTE(v248) = *v247;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v251 = v250;
          bitstream->readp = v247 + 3;
          v252 = (unsigned __int8)(v248 + 1);
          v253 = v250;
          v254 = __ROL4__(v247[2], 8) | v247[1];
          v255 = v252;
          idSWFScriptFunction_Script::AllocParameters(this: v246, numParms: v250);
          idSWFScriptFunction_Script::AllocRegisters(this: v246, numRegs: v252);
          v246->flags = v254;
          v260 = 0;
          if ( v251 > 0 )
          {
            do
            {
              *(_QWORD *)(HIDWORD(v13) + 16) = v13;
              *(_QWORD *)(HIDWORD(v13) + 24) = v13;
              v261 = *(unsigned __int8 **)(HIDWORD(v13) + 12);
              v262 = *v261;
              *(_DWORD *)(HIDWORD(v13) + 12) = v261 + 1;
              v263 = idSWFBitStream::ReadString(
                       this: (idSWFBitStream *)HIDWORD(v13),
                       a2: v259,
                       a3: v258,
                       a4: v257,
                       a5: v256);
              v257 = v262;
              v264 = v263;
              if ( v262 >= v255 )
              {
                idLib::Warning(fmt: v528, v263, v539.data, v262);
                LOBYTE(v262) = 0;
              }
              v265 = (8 * v260) & 0x7F8;
              LODWORD(v256) = (char *)v246->parameters.list + v265;
              v501 = v260++;
              *(_BYTE *)(v256 + 4) = v262;
              HIDWORD(v256) = v246->parameters.list;
              *(_DWORD *)(v265 + HIDWORD(v256)) = v264;
            }
            while ( v260 < v253 );
          }
          v266 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v266 += 2;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          bitstream->readp = v266;
          LODWORD(v267) = *(v266 - 1);
          HIDWORD(v267) = *(v266 - 2);
          v268 = __ROL4__(v267, 8);
          v269 = (unsigned __int16)(v268 | WORD1(v267));
          v246->data = idSWFBitStream::ReadData(
                         this: bitstream,
                         size: v269,
                         a3: v258,
                         a4: v257,
                         a5: v268 | HIDWORD(v267),
                         a6: v268,
                         a7: v267);
          v246->length = v269;
          if ( v539.len != 0 )
          {
            v271 = idSWFScriptVar::idSWFScriptVar(this: &v536, nf: v246);
            idSWFScriptObject::Set(this: thisObject, name: v539.data, value: v271);
            idSWFScriptVar::Free(this: &v536);
          }
          else
          {
            v270 = idList<idSWFScriptVar,5>::Alloc(this: stack);
            idSWFScriptVar::SetFunction(this: v270, f: v246);
          }
          v246->Release(this: v246);
          idStr::FreeData(this: &v539);
          v10 = (idSWFSpriteInstance *)type;
          goto LABEL_405;
        case Action_With:
          v389 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v389 += 2;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          bitstream->readp = v389;
          HIDWORD(v390) = *(v389 - 1);
          LODWORD(v15) = __ROL4__(HIDWORD(v390), 8);
          LODWORD(v390) = *(v389 - 2);
          v391 = v15 | v390;
          v392 = idSWFBitStream::ReadData(
                   this: bitstream,
                   size: v15 | v390,
                   a3: (int)v11,
                   a4: v16,
                   a5: SHIDWORD(v15),
                   a6: v15,
                   a7: v390);
          v546.free = false;
          idSWFBitStream::Load(this: &v546, data: v392, len: v391, copy: false);
          v393 = stack->num;
          v394 = stack->list;
          v395 = &stack->list[v393];
          v499 = (idSWFScriptVar *)v393;
          if ( v395[-1].type == SWF_VAR_OBJECT )
          {
            v499 = (idSWFScriptVar *)v393;
            v396 = (idSWFScriptVar *)v394[v393 - 1].value.i;
            v397 = v396->type;
            v499 = v396;
            v396->type = v397 + 1;
            idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&result[3].value,
              obj: (const encounterGroupRole_t *)&v499);
            idSWFScriptFunction_Script::Run(
              this: (idSWFScriptFunction_Script *)&v538.variablesHash[1],
              result,
              thisObject,
              (idSWFStack *)stack,
              bitstream: &v546);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variablesHash[1]);
            idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&result[3].value, newNum: result[4].type - 1);
            idSWFScriptObject::Release(this: (idSWFScriptObject *)v396);
          }
          else
          {
            if ( swf_debug.valueInteger > 0 )
              idLib::Printf(fmt: v523);
            idSWFStack::Pop(this: (idSWFStack *)stack, n: 1);
          }
          idSWFBitStream::Free(this: &v546);
          goto LABEL_405;
        case Action_Push:
          v34 = idSWFBitStream::ReadData(
                  this: bitstream,
                  size: v18,
                  a3: (int)v11,
                  a4: v16,
                  a5: SHIDWORD(v15),
                  a6: v15,
                  a7: v14);
          v504.free = false;
          idSWFBitStream::Load(this: &v504, data: v34, len: v18, copy: false);
          v38 = v504.readp;
          HIDWORD(v39) = v504.endp;
          LODWORD(v40) = v504.readp - v504.startp;
          for ( HIDWORD(v40) = v504.endp - v504.startp;
                (const unsigned __int8 *)(v38 - v504.startp) < (const unsigned __int8 *)(v504.endp - v504.startp);
                HIDWORD(v40) = v504.endp - v504.startp )
          {
            v504.currentBit = v13;
            v504.currentByte = v13;
            LODWORD(v39) = *v38++;
            v504.readp = v38;
            switch ( (int)v39 )
            {
              case 0:
                v41 = idSWFBitStream::ReadString(this: &v504, a2: v37, a3: v36, a4: v35, a5: v40);
                v42 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::SetString(this: v42, s: v41);
                goto LABEL_62;
              case 1:
                v504.currentBit = v13;
                v504.currentByte = v13;
                v504.readp = v38 + 4;
                v499 = (idSWFScriptVar *)(((((__ROL4__(v38[3], 8) | v38[2]) << 8) | v38[1]) << 8) | *v38);
                v43 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v43);
                v44 = *(float *)&v499;
                v43->type = SWF_VAR_FLOAT;
                v43->value.f = v44;
                goto LABEL_62;
              case 2:
                v45 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v45);
                v45->type = SWF_VAR_NULL;
                goto LABEL_62;
              case 3:
                v46 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v46);
                v46->type = SWF_VAR_UNDEF;
                goto LABEL_62;
              case 4:
                v504.currentBit = v13;
                v504.currentByte = v13;
                v47 = result[17].type;
                v48 = *v38;
                v504.readp = v38 + 1;
                v49 = (const idSWFScriptVar *)(__ROL4__(v48, 3) + v47);
                v50 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::operator=(this: v50, other: v49);
                goto LABEL_62;
              case 5:
                v504.currentBit = v13;
                v504.currentByte = v13;
                v51 = *v38;
                v504.readp = v38 + 1;
                v52 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v52);
                v52->type = SWF_VAR_BOOL;
                v52->value.b = v51 != 0;
                goto LABEL_62;
              case 6:
                v53 = (float)idSWFBitStream::ReadDouble(
                               this: &v504,
                               a2: v37,
                               a3: v36,
                               a4: v35,
                               a5: SHIDWORD(v40),
                               a6: v40,
                               a7: v39);
                v54 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v54);
                v54->value.f = v53;
                v54->type = SWF_VAR_FLOAT;
                goto LABEL_62;
              case 7:
                v504.currentByte = v13;
                v504.currentBit = v13;
                v504.readp = v38 + 4;
                v55 = ((((__ROL4__(v38[3], 8) | v38[2]) << 8) | v38[1]) << 8) | *v38;
                v56 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::Free(this: v56);
                v56->value.i = v55;
                v56->type = SWF_VAR_INTEGER;
                goto LABEL_62;
              case 8:
                v504.currentBit = v13;
                v504.currentByte = v13;
                v57 = result[15].type;
                v58 = *v38;
                v504.readp = v38 + 1;
                v59 = *(idSWFScriptString **)(__ROL4__(v58, 2) + v57);
                goto LABEL_61;
              case 9:
                v504.currentBit = v13;
                v504.currentByte = v13;
                v504.readp = v38 + 2;
                v59 = *(idSWFScriptString **)(((4 * (__ROL4__(v38[1], 8) | *v38)) & 0x3FFFC) + result[15].type);
LABEL_61:
                v60 = idList<idSWFScriptVar,5>::Alloc(this: stack);
                idSWFScriptVar::SetString(this: v60, s: v59);
LABEL_62:
                v38 = v504.readp;
                break;
              default:
                break;
            }
            HIDWORD(v39) = v504.endp;
            LODWORD(v40) = v38 - v504.startp;
          }
          idSWFBitStream::Free(this: &v504);
          goto LABEL_405;
        case Action_Jump:
          v129 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v129 += 2;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          bitstream->readp = v129;
          v16 = (__int16)__ROL4__(*(v129 - 1), 8);
          v11 = &v129[v16 | *(v129 - 2)];
          bitstream->readp = v11;
          goto LABEL_405;
        case Action_DefineFunction:
          v227 = idSWFBitStream::ReadString(this: bitstream, a2: (int)v12, a3: (int)v11, a4: v16, a5: v15);
          idStr::idStr(this: &v543, text: v227);
          v228 = idSWFScriptFunction_Script::Alloc();
          idSWFScriptFunction_Script::SetScope(this: v228, newScope: (const idList<idMD6Filter *,5> *)&result[3].value);
          idSWFConstantPool::Copy(this: &v228->constants, other: (const idSWFConstantPool *)&result[15]);
          v228->defaultSprite = (idSWFSpriteInstance *)result[3].type;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v229 = bitstream->readp + 2;
          bitstream->readp = v229;
          v230 = (unsigned __int16)(__ROL4__(*(v229 - 1), 8) | *(v229 - 2));
          idSWFScriptFunction_Script::AllocParameters(this: v228, numParms: v230);
          for ( n = 0; n < v230; *(_DWORD *)(v237 + HIDWORD(v231)) = v236 )
          {
            v236 = idSWFBitStream::ReadString(this: bitstream, a2: v234, a3: v233, a4: v232, a5: v231);
            v237 = (8 * n) & 0x7F8;
            LODWORD(v231) = (char *)v228->parameters.list + v237;
            v501 = n++;
            *(_BYTE *)(v231 + 4) = 0;
            HIDWORD(v231) = v228->parameters.list;
          }
          v238 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v238 += 2;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          bitstream->readp = v238;
          LODWORD(v239) = *(v238 - 1);
          HIDWORD(v239) = *(v238 - 2);
          v240 = __ROL4__(v239, 8);
          v241 = (unsigned __int16)(v240 | WORD1(v239));
          v242 = idSWFBitStream::ReadData(
                   this: bitstream,
                   size: v241,
                   a3: v233,
                   a4: v232,
                   a5: v240 | HIDWORD(v239),
                   a6: v240,
                   a7: v239);
          v228->length = v241;
          v228->data = v242;
          if ( v543.len != 0 )
          {
            v244 = idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v538.variables.granularity, nf: v228);
            idSWFScriptObject::Set(this: thisObject, name: v543.data, value: v244);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variables.granularity);
          }
          else
          {
            v243 = idList<idSWFScriptVar,5>::Alloc(this: stack);
            idSWFScriptVar::SetFunction(this: v243, f: v228);
          }
          v228->Release(this: v228);
          idStr::FreeData(this: &v543);
          goto LABEL_405;
        case Action_If:
          v130 = bitstream->readp;
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v130 += 2;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          bitstream->readp = v130;
          v131 = __ROL4__(*(v130 - 1), 8) | *(v130 - 2);
          if ( idSWFScriptVar::ToBool(this: &stack->list[stack->num - 1]) )
            bitstream->readp += v131;
          goto LABEL_403;
        case Action_GotoFrame2:
          *(_QWORD *)(HIDWORD(v13) + 16) = v13;
          v141 = 0;
          *(_QWORD *)(HIDWORD(v13) + 24) = v13;
          v142 = *(_BYTE **)(HIDWORD(v13) + 12);
          v143 = v142 + 1;
          v144 = *v142;
          *(_DWORD *)(HIDWORD(v13) + 12) = v143;
          v145 = v144;
          if ( (v144 & 2) != 0 )
          {
            *(_QWORD *)(HIDWORD(v13) + 16) = v13;
            *(_QWORD *)(HIDWORD(v13) + 24) = v13;
            *(_DWORD *)(HIDWORD(v13) + 12) = v143 + 2;
            v141 = __ROL4__(v143[1], 8) | *v143;
          }
          if ( v9 != nullptr )
          {
            v146 = stack->num;
            v147 = stack->list;
            v148 = &stack->list[v146];
            v499 = (idSWFScriptVar *)v146;
            v149 = v148[-1].type;
            if ( v149 == SWF_VAR_STRING || (v151 = v149 != SWF_VAR_STRINGID, v150 = 0, !v151) )
              v150 = 1;
            if ( v150 != 0 )
            {
              v499 = (idSWFScriptVar *)v146;
              v152 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v568, result: (idStr *)&v147[v146 - 1]);
              v153 = idSWFSpriteInstance::FindFrame(this: v9, labelName: v152->data) + v141;
              idStr::FreeData(this: &v568);
            }
            else
            {
              v153 = idSWFScriptVar::ToInteger(this: &v147[v146 - 1]) + v141;
            }
            if ( (v145 & 1) != 0 )
              idSWFSpriteInstance::Play(this: v9);
            else
              idSWFSpriteInstance::Stop(this: v9);
            idSWFSpriteInstance::RunTo(this: v9, targetFrame: v153);
          }
          else if ( swf_debug.valueInteger > 0 )
          {
            v154 = v520;
            if ( (v144 & 1) != 0 )
LABEL_402:
              idLib::Printf(fmt: v154);
            else
              idLib::Printf(fmt: (const char *)v533.variablesHash[6]);
          }
          goto LABEL_403;
        default:
          ActionName = idSWF::GetActionName(action: v19);
          idLib::Warning(fmt: "SWF: Unhandled Action %s", ActionName);
          goto LABEL_409;
      }
      while ( 1 )
      {
        v179 = idSWFScriptObject::Get(
                 this: (idSWFScriptObject *)&v538.variablesHash[3],
                 result: *(idSWFScriptVar **)(v178 + result[3].value.i),
                 name: v545.data);
        idSWFScriptVar::operator=(this: &v510, other: v179);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v538.variablesHash[3]);
        v175 = v510.type;
        if ( v510.type != SWF_VAR_UNDEF )
          break;
        --v177;
        v178 -= 4;
        if ( v177 < 0 )
          goto LABEL_151;
      }
      v176 = *(_DWORD *)(4 * v177 + result[3].value.i);
LABEL_151:
      v180 = stack->num;
      v181 = v180 - 1;
      if ( v180 - 1 <= stack->size
        || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v180 - 1) != 0 )
      {
        v182 = stack->size;
        if ( v181 < v182 )
          v182 = v181;
        stack->num = v182;
      }
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v552);
      v183 = idSWFScriptVar::ToInteger(this: &stack->list[stack->num - 1]);
      v184 = v552.size;
      v185 = v183;
      v186 = v183 < v552.size;
      if ( v183 > v552.size )
      {
        if ( (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: &v552, newsize: v183) == 0 )
          goto LABEL_161;
        v184 = v552.size;
        v186 = v185 < v552.size;
      }
      v552.num = v185;
      if ( !v186 )
        v552.num = v184;
LABEL_161:
      v187 = stack->num;
      v188 = v187 - 1;
      if ( v187 - 1 <= stack->size
        || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v187 - 1) != 0 )
      {
        v189 = stack->size;
        if ( v188 < v189 )
          v189 = v188;
        stack->num = v189;
      }
      v190 = 0;
      if ( v552.num > 0 )
      {
        v191 = 0;
        do
        {
          idSWFScriptVar::operator=(this: &v552.list[v191], other: &stack->list[stack->num - 1]);
          v192 = stack->num;
          v193 = v192 - 1;
          if ( v192 - 1 <= stack->size
            || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: stack, newsize: v192 - 1) != 0 )
          {
            v194 = stack->size;
            if ( v193 < v194 )
              v194 = v193;
            stack->num = v194;
          }
          ++v190;
          ++v191;
        }
        while ( v190 < v552.num );
      }
      if ( v175 == SWF_VAR_FUNCTION && v176 != 0 )
      {
        v195 = (const idSWFScriptVar *)(*(int (__fastcall **)(int *, int __struct_ptr, int, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v510.value.i + 4))(
                                         a1: &v534.variablesHash[11],
                                         a2: v510.value.i,
                                         a3: v176,
                                         a4: &v552);
        idList<idSWFScriptVar,5>::PreAllocateWithGranularity(this: stack, newSize: stack->num + 1);
        v196 = stack->num;
        v197 = stack->size;
        if ( v196 >= v197 )
        {
          v198 = &stack->list[v197 - 1];
        }
        else
        {
          v198 = &stack->list[v196];
          stack->num = v196 + 1;
        }
        idSWFScriptVar::operator=(this: v198, other: v195);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v534.variablesHash[11]);
      }
      else
      {
        idLib::PrintfIf(
          condition: (-swf_debug.valueInteger & ~swf_debug.valueInteger) < 0,
          fmt: (const char *)v533.variablesHash[1],
          v545.data);
        idList<idSWFScriptVar,5>::PreAllocateWithGranularity(this: stack, newSize: stack->num + 1);
        v199 = stack->num;
        v200 = stack->size;
        if ( v199 >= v200 )
        {
          v201 = &stack->list[v200 - 1];
        }
        else
        {
          v201 = &stack->list[v199];
          stack->num = v199 + 1;
        }
        idSWFScriptVar::Free(this: v201);
        v201->type = SWF_VAR_UNDEF;
      }
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v552);
      idSWFScriptVar::Free(this: &v510);
      idStr::FreeData(this: &v545);
      v10 = (idSWFSpriteInstance *)type;
LABEL_405:
      startp = bitstream->startp;
      LODWORD(v14) = bitstream->endp;
      HIDWORD(v14) = bitstream->readp;
      LODWORD(v15) = v14 - (_DWORD)startp;
      HIDWORD(v15) = HIDWORD(v14) - (_DWORD)startp;
      if ( HIDWORD(v14) - (int)startp >= (unsigned int)(v14 - (_DWORD)startp) )
      {
LABEL_409:
        this = (idSWFScriptFunction_Script *)v594;
        break;
      }
    }
  }
  this->__vftable = (idSWFScriptFunction_Script_vtbl *)4;
  --callstackLevel;
  return this;
}


// ========================================================================
// __unwind$223506
// EA  : 0x82789888
// RVA : 0x00789888
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223506()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1312));
}


// ========================================================================
// __unwind$223507
// EA  : 0x827898B0
// RVA : 0x007898B0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223507()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2240));
}


// ========================================================================
// __unwind$223511_0
// EA  : 0x827898D8
// RVA : 0x007898D8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223511_0()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 6928 + 112));
}


// ========================================================================
// __unwind$223512
// EA  : 0x82789900
// RVA : 0x00789900
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223512()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1248));
}


// ========================================================================
// __unwind$223513
// EA  : 0x82789928
// RVA : 0x00789928
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223513()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1824));
}


// ========================================================================
// __unwind$223514
// EA  : 0x82789950
// RVA : 0x00789950
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2144));
}


// ========================================================================
// __unwind$223515
// EA  : 0x82789978
// RVA : 0x00789978
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223515()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1376));
}


// ========================================================================
// __unwind$223516
// EA  : 0x827899A0
// RVA : 0x007899A0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223516()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1888));
}


// ========================================================================
// __unwind$223517
// EA  : 0x827899C8
// RVA : 0x007899C8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223517()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1152));
}


// ========================================================================
// __unwind$223518
// EA  : 0x827899F0
// RVA : 0x007899F0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223518()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1440));
}


// ========================================================================
// __unwind$223519
// EA  : 0x82789A18
// RVA : 0x00789A18
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223519()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2336));
}


// ========================================================================
// __unwind$223520
// EA  : 0x82789A40
// RVA : 0x00789A40
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223520()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1504));
}


// ========================================================================
// __unwind$223521
// EA  : 0x82789A68
// RVA : 0x00789A68
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1952));
}


// ========================================================================
// __unwind$223522
// EA  : 0x82789A90
// RVA : 0x00789A90
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223522()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1568));
}


// ========================================================================
// __unwind$223523
// EA  : 0x82789AB8
// RVA : 0x00789AB8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2208));
}


// ========================================================================
// __unwind$223524
// EA  : 0x82789AE0
// RVA : 0x00789AE0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223524()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2016));
}


// ========================================================================
// __unwind$223525
// EA  : 0x82789B08
// RVA : 0x00789B08
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223525()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 752));
}


// ========================================================================
// __unwind$223526
// EA  : 0x82789B30
// RVA : 0x00789B30
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223526()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 440));
}


// ========================================================================
// __unwind$223527
// EA  : 0x82789B58
// RVA : 0x00789B58
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223527()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 624));
}


// ========================================================================
// __unwind$223528
// EA  : 0x82789B80
// RVA : 0x00789B80
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1632));
}


// ========================================================================
// __unwind$223529
// EA  : 0x82789BA8
// RVA : 0x00789BA8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223529()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2304));
}


// ========================================================================
// __unwind$223530
// EA  : 0x82789BD0
// RVA : 0x00789BD0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223530()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 392));
}


// ========================================================================
// __unwind$223531
// EA  : 0x82789BF8
// RVA : 0x00789BF8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223531()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1696));
}


// ========================================================================
// __unwind$223532
// EA  : 0x82789C20
// RVA : 0x00789C20
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223532()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2080));
}


// ========================================================================
// __unwind$223533
// EA  : 0x82789C48
// RVA : 0x00789C48
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223533()
{
  _S13_17 &= ~1u;
}


// ========================================================================
// __unwind$223534
// EA  : 0x82789C68
// RVA : 0x00789C68
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223534()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 784));
}


// ========================================================================
// __unwind$223535
// EA  : 0x82789C90
// RVA : 0x00789C90
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223535()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 168));
}


// ========================================================================
// __unwind$223536
// EA  : 0x82789CB8
// RVA : 0x00789CB8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223536()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 520));
}


// ========================================================================
// __unwind$223537
// EA  : 0x82789CE0
// RVA : 0x00789CE0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223537()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 6928 + 1008));
}


// ========================================================================
// __unwind$223538
// EA  : 0x82789D08
// RVA : 0x00789D08
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223538()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 432));
}


// ========================================================================
// __unwind$223539
// EA  : 0x82789D30
// RVA : 0x00789D30
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223539()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 560));
}


// ========================================================================
// __unwind$223540
// EA  : 0x82789D58
// RVA : 0x00789D58
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223540()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 176));
}


// ========================================================================
// __unwind$223541
// EA  : 0x82789D80
// RVA : 0x00789D80
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223541()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 528));
}


// ========================================================================
// __unwind$223542
// EA  : 0x82789DA8
// RVA : 0x00789DA8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223542()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 544));
}


// ========================================================================
// __unwind$223543
// EA  : 0x82789DD0
// RVA : 0x00789DD0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223543()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1760));
}


// ========================================================================
// __unwind$223544
// EA  : 0x82789DF8
// RVA : 0x00789DF8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223544()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 6928 + 2368));
}


// ========================================================================
// __unwind$223545
// EA  : 0x82789E20
// RVA : 0x00789E20
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223545()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 456));
}


// ========================================================================
// __unwind$223546
// EA  : 0x82789E48
// RVA : 0x00789E48
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223546()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 848));
}


// ========================================================================
// __unwind$223547
// EA  : 0x82789E70
// RVA : 0x00789E70
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223547()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 720));
}


// ========================================================================
// __unwind$223548
// EA  : 0x82789E98
// RVA : 0x00789E98
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223548()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 504));
}


// ========================================================================
// __unwind$223549
// EA  : 0x82789EC0
// RVA : 0x00789EC0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223549()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 592));
}


// ========================================================================
// __unwind$223550
// EA  : 0x82789EE8
// RVA : 0x00789EE8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223550()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 472));
}


// ========================================================================
// __unwind$223551
// EA  : 0x82789F10
// RVA : 0x00789F10
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223551()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 976));
}


// ========================================================================
// __unwind$223552
// EA  : 0x82789F38
// RVA : 0x00789F38
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223552()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 536));
}


// ========================================================================
// __unwind$226095
// EA  : 0x82789F60
// RVA : 0x00789F60
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_226095()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 912));
}


// ========================================================================
// __unwind$223553
// EA  : 0x82789F88
// RVA : 0x00789F88
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2272));
}


// ========================================================================
// __unwind$223554
// EA  : 0x82789FB0
// RVA : 0x00789FB0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223554()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 488));
}


// ========================================================================
// __unwind$223555
// EA  : 0x82789FD8
// RVA : 0x00789FD8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223555()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1184));
}


// ========================================================================
// __unwind$223556
// EA  : 0x8278A000
// RVA : 0x0078A000
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223556()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 384));
}


// ========================================================================
// __unwind$223557
// EA  : 0x8278A028
// RVA : 0x0078A028
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223557()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1216));
}


// ========================================================================
// __unwind$223558
// EA  : 0x8278A050
// RVA : 0x0078A050
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223558()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 688));
}


// ========================================================================
// __unwind$223559
// EA  : 0x8278A078
// RVA : 0x0078A078
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223559()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1280));
}


// ========================================================================
// __unwind$223560
// EA  : 0x8278A0A0
// RVA : 0x0078A0A0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223560()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 880));
}


// ========================================================================
// __unwind$223561
// EA  : 0x8278A0C8
// RVA : 0x0078A0C8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223561()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 376));
}


// ========================================================================
// __unwind$223562
// EA  : 0x8278A0F0
// RVA : 0x0078A0F0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223562()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 320));
}


// ========================================================================
// __unwind$223563
// EA  : 0x8278A118
// RVA : 0x0078A118
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223563()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 448));
}


// ========================================================================
// __unwind$223564
// EA  : 0x8278A140
// RVA : 0x0078A140
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223564()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1344));
}


// ========================================================================
// __unwind$223565
// EA  : 0x8278A168
// RVA : 0x0078A168
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223565()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1408));
}


// ========================================================================
// __unwind$223566
// EA  : 0x8278A190
// RVA : 0x0078A190
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223566()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 656));
}


// ========================================================================
// __unwind$223567
// EA  : 0x8278A1B8
// RVA : 0x0078A1B8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223567()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 368));
}


// ========================================================================
// __unwind$223568
// EA  : 0x8278A1E0
// RVA : 0x0078A1E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223568()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 336));
}


// ========================================================================
// __unwind$223569
// EA  : 0x8278A208
// RVA : 0x0078A208
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223569()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 6928 + 2512));
}


// ========================================================================
// __unwind$223570
// EA  : 0x8278A230
// RVA : 0x0078A230
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223570()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 272));
}


// ========================================================================
// __unwind$223571
// EA  : 0x8278A258
// RVA : 0x0078A258
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223571()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 352));
}


// ========================================================================
// __unwind$223573
// EA  : 0x8278A280
// RVA : 0x0078A280
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223573()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 480));
}


// ========================================================================
// __unwind$223574
// EA  : 0x8278A2A8
// RVA : 0x0078A2A8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223574()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 496));
}


// ========================================================================
// __unwind$223575
// EA  : 0x8278A2D0
// RVA : 0x0078A2D0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223575()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 400));
}


// ========================================================================
// __unwind$223576
// EA  : 0x8278A2F8
// RVA : 0x0078A2F8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223576()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 944));
}


// ========================================================================
// __unwind$223577
// EA  : 0x8278A320
// RVA : 0x0078A320
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223577()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1536));
}


// ========================================================================
// __unwind$223578
// EA  : 0x8278A348
// RVA : 0x0078A348
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223578()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1472));
}


// ========================================================================
// __unwind$223579
// EA  : 0x8278A370
// RVA : 0x0078A370
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223579()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 6928 + 816));
}


// ========================================================================
// __unwind$223581
// EA  : 0x8278A398
// RVA : 0x0078A398
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1600));
}


// ========================================================================
// __unwind$223582
// EA  : 0x8278A3C0
// RVA : 0x0078A3C0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223582()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1792));
}


// ========================================================================
// __unwind$223583
// EA  : 0x8278A3E8
// RVA : 0x0078A3E8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223583()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1728));
}


// ========================================================================
// __unwind$223584_0
// EA  : 0x8278A410
// RVA : 0x0078A410
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223584_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1664));
}


// ========================================================================
// __unwind$223585_0
// EA  : 0x8278A438
// RVA : 0x0078A438
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223585_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1920));
}


// ========================================================================
// __unwind$223586_0
// EA  : 0x8278A460
// RVA : 0x0078A460
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223586_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1856));
}


// ========================================================================
// __unwind$223587_0
// EA  : 0x8278A488
// RVA : 0x0078A488
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223587_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2048));
}


// ========================================================================
// __unwind$223588_0
// EA  : 0x8278A4B0
// RVA : 0x0078A4B0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223588_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 1984));
}


// ========================================================================
// __unwind$223589_0
// EA  : 0x8278A4D8
// RVA : 0x0078A4D8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223589_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 328));
}


// ========================================================================
// __unwind$223590
// EA  : 0x8278A500
// RVA : 0x0078A500
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223590()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 344));
}


// ========================================================================
// __unwind$223591
// EA  : 0x8278A528
// RVA : 0x0078A528
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2112));
}


// ========================================================================
// __unwind$223592
// EA  : 0x8278A550
// RVA : 0x0078A550
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223592()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 6928 + 360));
}


// ========================================================================
// __unwind$223593
// EA  : 0x8278A578
// RVA : 0x0078A578
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_223593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6928 + 2176));
}


// ========================================================================
// ?Call@idSWFScriptFunction_Script@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8278A5A8
// RVA : 0x0078A5A8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

idSWFScriptFunction_Script *__fastcall idSWFScriptFunction_Script::Call(
        idSWFScriptFunction_Script *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject *v8; // r17
  int v9; // r11
  int num; // r9
  int v11; // r30
  int v12; // r11
  idSWFScriptVar::swfScriptVarValue_t v13; // r28
  int v14; // r30
  idSWFScriptVar::swfScriptVarValue_t v15; // r11
  idSWFScriptVar::swfScriptVarValue_t v16; // r27
  int v17; // r28
  idSWFScriptVar::swfScriptVarValue_t v18; // r11
  idSWFScriptVar *v19; // r30
  int v20; // r28
  int v21; // r30
  int v22; // r23
  idSWFScriptVar *v23; // r30
  idSWFScriptObject *v24; // r3
  idSWFScriptObject *v25; // r28
  int v26; // r30
  int v27; // r26
  int v28; // r27
  idSWFScriptVar *v29; // r30
  idSWFScriptObject *v31; // r3
  idSWFScriptObject *v32; // r28
  int v33; // r30
  int v34; // r26
  int v35; // r27
  idSWFScriptObject *prototype; // r30
  idSWFScriptVar *v38; // r28
  idSWFScriptObject *v39; // r30
  const idSWFScriptVar *v40; // r3
  idSWFScriptObject::swfObjectData_t v41; // r9
  idSWFScriptVar *v42; // r28
  idSWFScriptObject *scriptObject; // r30
  idSWFScriptVar *v44; // r30
  idSWFScriptVar *v45; // r28
  _DWORD *v46; // r30
  idSWFScriptVar::swfScriptVarValue_t *p_value; // r26
  idSWFScriptVar::swfScriptVarType type; // r27
  idSWFScriptVar::swfScriptVarType v49; // r10
  idSWFScriptVar::swfScriptVarType v50; // r25
  int v51; // r28
  idSWFScriptObject *v52; // r10
  void *v53; // r30
  idSWFScriptVar::swfScriptVarType i; // r11
  idSWFScriptVar *v57; // r29
  int v58; // r30
  void *v59; // r28
  encounterGroupRole_t v61[3]; // [sp+54h] [-FCh] BYREF
  idSWFScriptVar v62; // [sp+60h] [-F0h] BYREF
  idSWFScriptVar v63; // [sp+68h] [-E8h] BYREF
  idSWFScriptVar v64; // [sp+70h] [-E0h] BYREF
  idSWFScriptVar v65; // [sp+78h] [-D8h] BYREF
  idSWFScriptObject v66[2]; // [sp+80h] [-D0h] BYREF

  v61[1] = ROLE_NONE;
  HIBYTE(v66[0].variablesHash[3]) = 0;
  idSWFBitStream::Load(
    this: (idSWFBitStream *)&v66[0].variablesHash[3],
    data: (const unsigned __int8 *)result[1].value.i,
    len: result[2].type,
    copy: false);
  if ( thisObject == nullptr )
    thisObject = *(idSWFScriptObject **)result[3].value.i;
  v8 = idSWFScriptObject::Alloc();
  v9 = 0;
  v61[0] = (encounterGroupRole_t)v8;
  v66[0].variablesHash[2] = 18432;
  *(_DWORD *)&v66[0].variables.granularity = 0;
  v66[0].variablesHash[0] = 0;
  v66[0].variablesHash[1] = 0;
  num = parms->num;
  v11 = num + 1;
  if ( num + 1 > 0 )
  {
    if ( (unsigned __int8)idList<idSWFScriptVar,72>::Resize(
                            this: (idList<idSWFScriptVar,5> *)&v66[0].variables.granularity,
                            newsize: num + 1) == 0 )
      goto LABEL_8;
    v9 = v66[0].variablesHash[1];
  }
  v66[0].variablesHash[0] = v11;
  if ( v11 >= v9 )
    v66[0].variablesHash[0] = v9;
LABEL_8:
  v13.i = 0;
  v12 = parms->num;
  if ( v12 > 0 )
  {
    v14 = 0;
    do
    {
      idSWFScriptVar::operator=(
        this: (idSWFScriptVar *)(8 * (v12 - v13.i - 1) + *(_DWORD *)&v66[0].variables.granularity),
        other: &parms->list[v14]);
      if ( v13.i < result[19].value.i )
      {
        v15.i = *(unsigned __int8 *)(v14 * 8 + result[19].type + 4);
        if ( *(_BYTE *)(v14 * 8 + result[19].type + 4) != 0 && v15.i < result[17].value.i )
          idSWFScriptVar::operator=(this: (idSWFScriptVar *)(8 * v15.i + result[17].type), other: &parms->list[v14]);
        idSWFScriptObject::Set(this: v8, name: *(const char **)(v14 * 8 + result[19].type), value: &parms->list[v14]);
      }
      ++v13.i;
      ++v14;
      v12 = parms->num;
    }
    while ( v13.i < v12 );
  }
  v16.i = v12;
  if ( v12 < result[19].value.i )
  {
    v17 = 8 * v12;
    do
    {
      v18.i = *(unsigned __int8 *)(v17 + result[19].type + 4);
      if ( *(_BYTE *)(v17 + result[19].type + 4) != 0 && v18.i < result[17].value.i )
      {
        v19 = (idSWFScriptVar *)(8 * v18.i + result[17].type);
        idSWFScriptVar::Free(this: v19);
        v19->type = SWF_VAR_UNDEF;
      }
      v65.type = SWF_VAR_UNDEF;
      idSWFScriptObject::Set(this: v8, name: *(const char **)(v17 + result[19].type), value: &v65);
      idSWFScriptVar::Free(this: &v65);
      ++v16.i;
      v17 += 8;
    }
    while ( v16.i < result[19].value.i );
  }
  v20 = parms->num;
  v21 = 8 * v66[0].variablesHash[0] + *(_DWORD *)&v66[0].variables.granularity;
  idSWFScriptVar::Free(this: (idSWFScriptVar *)(v21 - 8));
  *(_DWORD *)(v21 - 4) = v20;
  *(_DWORD *)(v21 - 8) = 6;
  v22 = 1;
  if ( (HIWORD(result[1].type) & 1) != 0 )
  {
    v23 = (idSWFScriptVar *)(result[17].type + 8);
    idSWFScriptVar::Free(this: v23);
    if ( thisObject != nullptr )
    {
      v23->value.i = (int)thisObject;
      v23->type = SWF_VAR_OBJECT;
      ++thisObject->refCount;
    }
    else
    {
      v23->type = SWF_VAR_NULL;
    }
    v22 = 2;
  }
  if ( (HIWORD(result[1].type) & 2) == 0 )
  {
    v62.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v62);
    if ( thisObject != nullptr )
    {
      v62.type = SWF_VAR_OBJECT;
      v62.value.i = (int)thisObject;
      ++thisObject->refCount;
    }
    else
    {
      v62.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v8, name: "this", value: &v62);
    idSWFScriptVar::Free(this: &v62);
  }
  if ( (HIWORD(result[1].type) & 4) != 0 )
  {
    v24 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x60u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v24 != nullptr )
      v25 = idSWFScriptObject::idSWFScriptObject(this: v24);
    else
      v25 = nullptr;
    idSWFScriptObject::MakeArray(this: v25);
    v26 = 0;
    v27 = parms->num;
    if ( v27 > 0 )
    {
      v28 = 0;
      do
        idSWFScriptObject::Set(this: v25, index: v26++, value: &parms->list[v28++]);
      while ( v26 < v27 );
    }
    v29 = (idSWFScriptVar *)(8 * v22 + result[17].type);
    idSWFScriptVar::Free(this: v29);
    if ( v25 != nullptr )
    {
      v29->value.i = (int)v25;
      v29->type = SWF_VAR_OBJECT;
      ++v25->refCount;
    }
    else
    {
      v29->type = SWF_VAR_NULL;
    }
    ++v22;
    if ( v25->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v25);
      idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
    }
  }
  if ( (HIWORD(result[1].type) & 8) == 0 )
  {
    v31 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x60u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v31 != nullptr )
      v32 = idSWFScriptObject::idSWFScriptObject(this: v31);
    else
      v32 = nullptr;
    idSWFScriptObject::MakeArray(this: v32);
    v33 = 0;
    v34 = parms->num;
    if ( v34 > 0 )
    {
      v35 = 0;
      do
        idSWFScriptObject::Set(this: v32, index: v33++, value: &parms->list[v35++]);
      while ( v33 < v34 );
    }
    v63.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v63);
    if ( v32 != nullptr )
    {
      v63.value.i = (int)v32;
      v63.type = SWF_VAR_OBJECT;
      ++v32->refCount;
    }
    else
    {
      v63.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v8, name: "arguments", value: &v63);
    idSWFScriptVar::Free(this: &v63);
    if ( v32->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v32);
      idMem::Free(this: &mem, ptr: v32, align: ALIGN_16);
    }
  }
  if ( (HIWORD(result[1].type) & 0x10) != 0 )
  {
    prototype = thisObject->prototype;
    v38 = (idSWFScriptVar *)(8 * v22 + result[17].type);
    idSWFScriptVar::Free(this: v38);
    if ( prototype != nullptr )
    {
      v38->type = SWF_VAR_OBJECT;
      v38->value.i = (int)prototype;
      ++prototype->refCount;
    }
    else
    {
      v38->type = SWF_VAR_NULL;
    }
    ++v22;
  }
  if ( (HIWORD(result[1].type) & 0x20) == 0 )
  {
    v39 = thisObject->prototype;
    v64.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v64);
    if ( v39 != nullptr )
    {
      v64.type = SWF_VAR_OBJECT;
      v64.value.i = (int)v39;
      ++v39->refCount;
    }
    else
    {
      v64.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v8, name: "super", value: &v64);
    idSWFScriptVar::Free(this: &v64);
  }
  if ( (HIWORD(result[1].type) & 0x40) != 0 )
  {
    v40 = idSWFScriptObject::Get(this: v66, result: *(idSWFScriptVar **)result[3].value.i, name: "_root");
    idSWFScriptVar::operator=(this: (idSWFScriptVar *)(8 * v22 + result[17].type), other: v40);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)v66);
    ++v22;
  }
  if ( (HIWORD(result[1].type) & 0x80) != 0 )
  {
    if ( thisObject->objectType == SWF_OBJECT_SPRITE
      && (v41.sprite = (idSWFSpriteInstance *)thisObject->data, v41.sprite != nullptr)
      && v41.sprite->parent != nullptr )
    {
      v42 = (idSWFScriptVar *)(8 * v22 + result[17].type);
      scriptObject = v41.sprite->parent->scriptObject;
      idSWFScriptVar::Free(this: v42);
      if ( scriptObject != nullptr )
      {
        v42->value.i = (int)scriptObject;
        v42->type = SWF_VAR_OBJECT;
        ++scriptObject->refCount;
      }
      else
      {
        v42->type = SWF_VAR_NULL;
      }
    }
    else
    {
      v44 = (idSWFScriptVar *)(8 * v22 + result[17].type);
      idSWFScriptVar::Free(this: v44);
      v44->type = SWF_VAR_NULL;
    }
    ++v22;
  }
  if ( (HIWORD(result[1].type) & 0x100) != 0 )
  {
    v45 = (idSWFScriptVar *)(8 * v22 + result[17].type);
    v46 = *(_DWORD **)result[3].value.i;
    idSWFScriptVar::Free(this: v45);
    if ( v46 != nullptr )
    {
      v45->type = SWF_VAR_OBJECT;
      v45->value.i = (int)v46;
      ++*v46;
    }
    else
    {
      v45->type = SWF_VAR_NULL;
    }
  }
  p_value = &result[3].value;
  type = result[4].type;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&result[3].value, obj: v61);
  ++v8->refCount;
  idSWFScriptFunction_Script::Run(
    this,
    result,
    thisObject,
    stack: (idList<idSWFScriptVar,5> *)&v66[0].variables.granularity,
    bitstream: (idSWFBitStream *)&v66[0].variablesHash[3]);
  v49 = result[4].type;
  v50 = type;
  v61[1] = ROLE_DEFEND;
  if ( type < v49 )
  {
    v51 = 4 * type;
    do
    {
      v52 = *(idSWFScriptObject **)(p_value->i + v51);
      if ( v52 != nullptr )
      {
        v53 = *(void **)(p_value->i + v51);
        if ( v52->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v52);
          idMem::Free(this: &mem, ptr: v53, align: ALIGN_16);
        }
      }
      ++v50;
      v51 += 4;
    }
    while ( v50 < result[4].type );
  }
  if ( type <= result[4].value.i
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&result[3].value,
         newsize: type) )
  {
    i = result[4].value.i;
    if ( type < i )
      i = type;
    result[4].type = i;
  }
  if ( v8->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v8);
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  }
  if ( LOBYTE(v66[0].variablesHash[2]) == 0 || LOBYTE(v66[0].variablesHash[2]) == 2 )
  {
    v57 = *(idSWFScriptVar **)&v66[0].variables.granularity;
    if ( *(_DWORD *)&v66[0].variables.granularity != 0 )
    {
      v58 = v66[0].variablesHash[1];
      v59 = *(void **)&v66[0].variables.granularity;
      if ( v66[0].variablesHash[1] > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v57);
          --v58;
          ++v57;
        }
        while ( v58 != 0 );
      }
      idMem::Free(this: &mem, ptr: v59, align: ALIGN_16);
    }
    *(_DWORD *)&v66[0].variables.granularity = 0;
    v66[0].variablesHash[1] = 0;
  }
  v66[0].variablesHash[0] = 0;
  idSWFBitStream::Free(this: (idSWFBitStream *)&v66[0].variablesHash[3]);
  return this;
}


// ========================================================================
// __unwind$229347
// EA  : 0x8278ADC0
// RVA : 0x0078ADC0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229347()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$229348
// EA  : 0x8278ADE8
// RVA : 0x0078ADE8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229348()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$229349
// EA  : 0x8278AE10
// RVA : 0x0078AE10
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229349()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 120));
}


// ========================================================================
// __unwind$229350
// EA  : 0x8278AE38
// RVA : 0x0078AE38
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229350()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$229554
// EA  : 0x8278AE60
// RVA : 0x0078AE60
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229554()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 336 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$229617
// EA  : 0x8278AE8C
// RVA : 0x0078AE8C
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229617()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 336 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$229351
// EA  : 0x8278AEB8
// RVA : 0x0078AEB8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229351()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 104));
}


// ========================================================================
// __unwind$229352
// EA  : 0x8278AEE0
// RVA : 0x0078AEE0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229352()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$229353
// EA  : 0x8278AF08
// RVA : 0x0078AF08
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229353()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$229354
// EA  : 0x8278AF30
// RVA : 0x0078AF30
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void _unwind_229354()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 336;
  if ( (*(_DWORD *)(v0 - 336 + 88) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 88) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 356));
  }
}


// ========================================================================
// `dynamic initializer for 'swf_debug''
// EA  : 0x83341C70
// RVA : 0x01341C70
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_debug__()
{
  idCVar::idCVar(
    this: &swf_debug,
    name: "swf_debug",
    value: "0",
    flags: 2,
    description: "debug swf scripts.  1 shows traces/errors.  2 also shows warnings.  3 also shows disassembly.  4 shows parameters in"
    " the disassembly.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_debug__);
}


// ========================================================================
// `dynamic initializer for 'swf_debugInvoke''
// EA  : 0x83341CC8
// RVA : 0x01341CC8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_debugInvoke__()
{
  idCVar::idCVar(
    this: &swf_debugInvoke,
    name: "swf_debugInvoke",
    value: "0",
    flags: 2,
    description: "debug swf functions being called from game.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_debugInvoke__);
}

