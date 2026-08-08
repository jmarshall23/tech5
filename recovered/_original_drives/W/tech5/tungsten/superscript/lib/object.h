
// ========================================================================
// ?_setEntity@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1B78
// RVA : 0x00EE1B78
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void __fastcall idSuperScriptObject::_setEntity(idSuperScriptObject *this, XGRAPHICS::Compiler *spawnId)
{
  const ssEntity *v3; // r3
  char v4; // [sp+50h] [-20h] BYREF

  v3 = (const ssEntity *)ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v4, context: spawnId);
  ssEntity::ssEntity(this: &this->self, e: v3);
}


// ========================================================================
// ?FullName@ssObjectBase@@QBA?AVssString@@XZ
// EA  : 0x82EE8590
// RVA : 0x00EE8590
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

ssObjectBase *__fastcall ssObjectBase::FullName(ssObjectBase *this, ssString *result)
{
  idSSObject *v4; // r3
  void *v5; // r3
  char *v6; // r29
  ssEntity *v7; // r3
  const ssString *v8; // r3
  XGRAPHICS::VRegTable v10; // [sp+50h] [-70h] BYREF
  ssString v11[4]; // [sp+80h] [-40h] BYREF

  v10.symbols = nullptr;
  v4 = gameInterface->GetScriptObject(this: gameInterface, a2: result->len, a3: result->data);
  v5 = _RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &idSuperScriptObject `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
    v6 = (char *)(*(int (__fastcall **)(void *))(*(_DWORD *)v5 + 92))(a1: v5);
  else
    v6 = "<null>";
  ssString::Init(this: (ssString *)&v10.constants_3);
  ssString::operator=(this: (ssString *)&v10.constants_3, text: v6);
  ssEntity::ssEntity(this: &v10, context: (XGRAPHICS::Compiler *)result->len);
  v7 = ssEntity::Name(this: (ssEntity *)v11, result: (ssString *)&v10);
  v8 = operator+(result: (ssString *)&v10.inVertexShader, a: (const ssString *)v7, b: ".");
  operator+(result: (ssString *)this, a: v8, b: (const ssString *)&v10.constants_3);
  v10.symbols = (XGRAPHICS::HashTable<XGRAPHICS::VRegInfo *> *)1;
  ssString::Empty(this: (ssString *)&v10.inVertexShader);
  ssString::Empty(this: v11);
  ssString::Empty(this: (ssString *)&v10.constants_3);
  return this;
}


// ========================================================================
// __unwind$18101
// EA  : 0x82EE8694
// RVA : 0x00EE8694
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_18101()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$18102
// EA  : 0x82EE86BC
// RVA : 0x00EE86BC
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_18102()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$18103
// EA  : 0x82EE86E4
// RVA : 0x00EE86E4
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_18103()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$18104
// EA  : 0x82EE870C
// RVA : 0x00EE870C
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_18104()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    ssString::~ssString(this: *(ssString **)(v1 + 212));
  }
}


// ========================================================================
// ?CreateThreadNamed@idSuperScriptObject@@QAAHVssString@@P6AXPAVidSSObject@@PAX@Z@Z
// EA  : 0x82EE8C58
// RVA : 0x00EE8C58
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

int __fastcall idSuperScriptObject::CreateThreadNamed(
        idSuperScriptObject *this,
        ssString *threadName,
        void (__fastcall *f)(idSSObject *, void *))
{
  int v4; // r29

  v4 = gameInterface->CreateThread(this: gameInterface, a2: threadName->data, a3: this, a4: f, a5: nullptr);
  ssString::Empty(this: threadName);
  return v4;
}


// ========================================================================
// __unwind$19195
// EA  : 0x82EE8CB0
// RVA : 0x00EE8CB0
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_19195()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 112 + 140));
}


// ========================================================================
// ?IsValid@ssObjectBase@@QAA_NXZ
// EA  : 0x82EEBFE8
// RVA : 0x00EEBFE8
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

BOOL __fastcall ssObjectBase::IsValid(ssObjectBase *this)
{
  idSSObject *v1; // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  return _RTDynamicCast(
           inptr: v1,
           VfDelta: 0,
           SrcType: &idSSObject `RTTI Type Descriptor',
           TargetType: &idSuperScriptObject `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}


// ========================================================================
// ?proxyFunc@?$threadData2_t@VssString@@M@idSuperScriptObject@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EEE690
// RVA : 0x00EEE690
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void __fastcall idSuperScriptObject::threadData2_t<ssString,float>::proxyFunc(
        idSSObject *object,
        void (__fastcall **data)(idSSObject *, ssString *, double))
{
  const ssString *v3; // r29
  ssString v5[3]; // [sp+50h] [-30h] BYREF

  v3 = (const ssString *)data[1];
  ssString::Init(this: v5);
  ssString::operator=(this: v5, text: v3);
  (*data)(a1: object, a2: v5, a3: *(float *)data[2]);
}


// ========================================================================
// ?proxyFunc@?$threadData3_t@VssEntity@@M_N@idSuperScriptObject@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EF18C8
// RVA : 0x00EF18C8
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void __fastcall idSuperScriptObject::threadData3_t<ssEntity,float,bool>::proxyFunc(idSSObject *object, void *data)
{
  double v4; // fp31
  int v5; // r3
  ssEntity v6; // [sp+50h] [-30h] BYREF

  v4 = **((float **)data + 2);
  ssEntity::ssEntity(this: &v6, e: *((const ssEntity **)data + 1));
  (*(void (__fastcall **)(idSSObject *, int, double))data)(a1: object, a2: v5, a3: v4);
}


// ========================================================================
// ?proxyFunc@?$threadData2_t@VssEntity@@M@idSuperScriptObject@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EF1928
// RVA : 0x00EF1928
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void __fastcall idSuperScriptObject::threadData2_t<ssEntity,float>::proxyFunc(idSSObject *object, void *data)
{
  double v4; // fp31
  int v5; // r3
  ssEntity v6; // [sp+50h] [-30h] BYREF

  v4 = **((float **)data + 2);
  ssEntity::ssEntity(this: &v6, e: *((const ssEntity **)data + 1));
  (*(void (__fastcall **)(idSSObject *, int, double))data)(a1: object, a2: v5, a3: v4);
}


// ========================================================================
// ?proxyFunc@?$threadData2_t@W4musicTensionStates_t@@UtensionTransition_t@@@idSuperScriptObject@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EF1990
// RVA : 0x00EF1990
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void __fastcall idSuperScriptObject::threadData2_t<enum musicTensionStates_t,tensionTransition_t>::proxyFunc(
        idSSObject *object,
        _DWORD **data)
{
  ((void (__fastcall *)(idSSObject *, _DWORD, _DWORD))*data)(a1: object, a2: *data[1], a3: data[2][1]);
}


// ========================================================================
// ??$CreateThreadNamed@W4musicTensionStates_t@@UtensionTransition_t@@@ssObjectBase@@QAAHABVssString@@P6AXPAVidSSObject@@W4musicTensionStates_t@@UtensionTransition_t@@@ZABW43@ABU4@@Z
// EA  : 0x82EF2820
// RVA : 0x00EF2820
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

int __fastcall ssObjectBase::CreateThreadNamed<enum musicTensionStates_t,tensionTransition_t>(
        ssObjectBase *this,
        const ssString *threadName,
        void (__fastcall *f)(idSSObject *, musicTensionStates_t, tensionTransition_t *__struct_ptr),
        const musicTensionStates_t *p1,
        const tensionTransition_t *p2)
{
  idSSObject *v9; // r3
  idSSObject *v10; // r5
  ssString *v11; // r3
  const ssString *v12; // r3
  _DWORD v14[4]; // [sp+50h] [-70h] BYREF
  ssString v15; // [sp+60h] [-60h] BYREF
  ssString v16[5]; // [sp+70h] [-50h] BYREF

  v9 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v10 = (idSSObject *)_RTDynamicCast(
                        inptr: v9,
                        VfDelta: 0,
                        SrcType: &idSSObject `RTTI Type Descriptor',
                        TargetType: &idSuperScriptObject `RTTI Type Descriptor',
                        isReference: 0);
  if ( v10 != nullptr )
  {
    v14[0] = f;
    v14[1] = p1;
    v14[2] = p2;
    return gameInterface->CreateThread(
             this: gameInterface,
             a2: threadName->data,
             a3: v10,
             a4: (void (__fastcall *)(idSSObject *, void *))idSuperScriptObject::threadData2_t<enum musicTensionStates_t,tensionTransition_t>::proxyFunc,
             a5: v14);
  }
  else
  {
    v11 = operator+(result: v16, a: "Could not create thread ", b: threadName);
    v12 = operator+(result: &v15, a: v11, b: " on null object");
    Warning(msg: v12);
    ssString::Empty(this: &v15);
    ssString::Empty(this: v16);
    return 0;
  }
}


// ========================================================================
// __unwind$20778
// EA  : 0x82EF2908
// RVA : 0x00EF2908
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_20778()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$20779
// EA  : 0x82EF2930
// RVA : 0x00EF2930
// PDB : w:\tech5\tungsten\superscript\lib\object.h
// ========================================================================

void _unwind_20779()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}

