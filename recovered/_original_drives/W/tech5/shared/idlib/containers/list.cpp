
// ========================================================================
// ?ForceIdListsToReallocateEveryAppend_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFB710
// RVA : 0x00EFB710
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void __fastcall ForceIdListsToReallocateEveryAppend_f(const idCmdArgs *args)
{
  forceIdListsToReallocateEveryAppend = true;
  idLib::Printf(fmt: "forceIdListsToReallocateEveryAppend set, you may want to also set guardPages 1\n");
}


// ========================================================================
// ?testArrayWrapper_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFB728
// RVA : 0x00EFB728
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void __fastcall testArrayWrapper_f(const idCmdArgs *args)
{
  int v1; // r30
  const char **v2; // r31

  v1 = 0;
  v2 = testArray;
  do
    idLib::Printf(fmt: "arrayObject[%i] = %s\n", v1++, *v2++);
  while ( (int)v2 <= (int)&cmdSystem );
}


// ========================================================================
// ?testArray_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFB778
// RVA : 0x00EFB778
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void __fastcall testArray_f(const idCmdArgs *args)
{
  _DWORD *v1; // r10
  int v2; // r11
  int i; // ctr
  _DWORD *v4; // r10
  int v5; // r11
  int j; // ctr
  int v7; // r10
  int v8; // r7
  int v9; // r8
  int v10; // ctr
  int v11; // r9
  _DWORD *v12; // r11
  int v13; // r5
  int v14; // r4
  int v15; // r4
  int v16; // r10
  int v17; // ctr
  int v18; // r7
  int v19; // r8
  int v20; // r9
  _DWORD *v21; // r11
  int v22; // r3
  int v23; // r5
  _BYTE v24[8]; // [sp+4Ch] [-2014h] BYREF
  _BYTE v25[8]; // [sp+104Ch] [-1014h] BYREF

  v1 = v24;
  v2 = 0;
  for ( i = 1024; i != 0; --i )
    *++v1 = v2++;
  v4 = v25;
  v5 = 0;
  for ( j = 1024; j != 0; --j )
    *++v4 = v5++;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 256;
  v11 = 0;
  v12 = v24;
  do
  {
    v13 = v12[2];
    v14 = v12[3];
    v7 += v12[1];
    v12 += 4;
    v11 += v13;
    v9 += v14;
    v8 += *v12;
    --v10;
  }
  while ( v10 != 0 );
  v15 = v8 + v9 + v11 + v7;
  v16 = 0;
  v17 = 256;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = v25;
  do
  {
    v22 = v21[2];
    v23 = v21[3];
    v16 += v21[1];
    v21 += 4;
    v20 += v22;
    v19 += v23;
    v18 += *v21;
    --v17;
  }
  while ( v17 != 0 );
  idLib::Printf(fmt: "raw sum: %i  new sum: %i\n", v15, v18 + v19 + v20 + v16);
}


// ========================================================================
// ?TestStaleIdListReference_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFB9C0
// RVA : 0x00EFB9C0
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void __fastcall TestStaleIdListReference_f(const idCmdArgs *args)
{
  encounterGroupRole_t *list; // r29
  encounterGroupRole_t v2[4]; // [sp+50h] [-40h] BYREF
  idList<enum encounterGroupRole_t,5> v3[3]; // [sp+60h] [-30h] BYREF

  memset(v3, 0, 14);
  v3[0].memTag = 5;
  v3[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v3);
  v2[0] = ROLE_DEFEND;
  idList<idAnimWebBlendTree *,5>::Append(this: v3, obj: v2);
  v2[0] = ROLE_ASSAULT;
  list = v3[0].list;
  idList<idAnimWebBlendTree *,5>::Append(this: v3, obj: v2);
  *list = ROLE_NONE;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v3);
}


// ========================================================================
// __unwind$111817
// EA  : 0x82EFBA38
// RVA : 0x00EFBA38
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void _unwind_111817()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 96));
}


// ========================================================================
// ?TestListConstructors_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFBBC0
// RVA : 0x00EFBBC0
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void __fastcall TestListConstructors_f(const idCmdArgs *args)
{
  int size; // r11
  char v2; // r3
  bool v3; // cr57
  char v4; // r3
  bool v5; // cr57
  char v6; // r3
  bool v7; // cr57
  idList<idConstructorDestructorCounter,5> v8[3]; // [sp+50h] [-30h] BYREF

  memset(v8, 0, 14);
  v8[0].listStatic = 0;
  idConstructorDestructorCounter::constructors = 0;
  idConstructorDestructorCounter::destructors = 0;
  v8[0].memTag = 5;
  idList<idConstructorDestructorCounter,5>::Clear(this: v8);
  size = v8[0].size;
  if ( v8[0].size >= 10
    || (v2 = idList<idConstructorDestructorCounter,5>::Resize(this: v8, newsize: 10), size = v8[0].size, v2 != 0) )
  {
    v8[0].num = 10;
    if ( size <= 10 )
      v8[0].num = size;
  }
  if ( size < 0 )
  {
    idList<idConstructorDestructorCounter,5>::Clear(this: v8);
    size = v8[0].size;
  }
  v3 = size > 1;
  v8[0].num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
  if ( size < 1 )
  {
    v4 = idList<idConstructorDestructorCounter,5>::Resize(this: v8, newsize: 1);
    size = v8[0].size;
    if ( v4 == 0 )
      goto LABEL_13;
    v3 = v8[0].size > 1;
  }
  if ( v3 )
    v8[0].num = 1;
  else
    v8[0].num = size;
LABEL_13:
  v5 = size > 10;
  if ( size < 10 )
  {
    v6 = idList<idConstructorDestructorCounter,5>::Resize(this: v8, newsize: 10);
    size = v8[0].size;
    if ( v6 == 0 )
      goto LABEL_18;
    v5 = v8[0].size > 10;
  }
  v8[0].num = 10;
  if ( !v5 )
    v8[0].num = size;
LABEL_18:
  v7 = size > 20;
  if ( size < 20 )
  {
    if ( (unsigned __int8)idList<idConstructorDestructorCounter,5>::Resize(this: v8, newsize: 20) == 0 )
      goto LABEL_24;
    size = v8[0].size;
    v7 = v8[0].size > 20;
  }
  if ( v7 )
    size = 20;
  v8[0].num = size;
LABEL_24:
  idList<idConstructorDestructorCounter,5>::Clear(this: v8);
}


// ========================================================================
// __unwind$111914
// EA  : 0x82EFBD2C
// RVA : 0x00EFBD2C
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

void _unwind_111914()
{
  int v0; // r12

  idList<idConstructorDestructorCounter,5>::~idList<idConstructorDestructorCounter,5>(this: (idList<idConstructorDestructorCounter,5> *)(v0 - 128 + 80));
}


// ========================================================================
// `dynamic initializer for 'ForceIdListsToReallocateEveryAppend_v''
// EA  : 0x833942A8
// RVA : 0x013942A8
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ForceIdListsToReallocateEveryAppend_v__()
{
  return idCommandLink::idCommandLink(
           this: &ForceIdListsToReallocateEveryAppend_v,
           cmdName: "ForceIdListsToReallocateEveryAppend",
           function: ForceIdListsToReallocateEveryAppend_f,
           description: "Enable idList debugging tool",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestStaleIdListReference_v''
// EA  : 0x833942D0
// RVA : 0x013942D0
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestStaleIdListReference_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestStaleIdListReference_v,
           cmdName: "TestStaleIdListReference",
           function: TestStaleIdListReference_f,
           description: "Tests the test code",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testArrayWrapper_v''
// EA  : 0x833942F8
// RVA : 0x013942F8
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testArrayWrapper_v__()
{
  return idCommandLink::idCommandLink(
           this: &testArrayWrapper_v,
           cmdName: "testArrayWrapper",
           function: testArrayWrapper_f,
           description: "Test idArrayWrapper",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testArray_v''
// EA  : 0x83394320
// RVA : 0x01394320
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testArray_v__()
{
  return idCommandLink::idCommandLink(
           this: &testArray_v,
           cmdName: "testArray",
           function: testArray_f,
           description: "Test idArray",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestListConstructors_v''
// EA  : 0x83394348
// RVA : 0x01394348
// PDB : w:\tech5\shared\idlib\containers\list.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestListConstructors_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestListConstructors_v,
           cmdName: "TestListConstructors",
           function: TestListConstructors_f,
           description: "Tests constructor / destructor calling for lists",
           argCompletion: nullptr);
}

