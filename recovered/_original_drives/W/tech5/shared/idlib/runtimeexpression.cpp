
// ========================================================================
// ?LookUpVar@VarContext@TestExpression@@QAA_NPBDAAVVarId@2@@Z
// EA  : 0x82F7DB48
// RVA : 0x00F7DB48
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

int __fastcall TestExpression::VarContext::LookUpVar(
        TestExpression::VarContext *this,
        const char *name,
        TestExpression::VarId *resId)
{
  TestExpression::VarListEntry *varList; // r11
  int v7; // r31
  int v8; // r10

  varList = this->varList;
  v7 = 0;
  if ( this->varList->name == nullptr )
    return 0;
  v8 = 0;
  while ( idStr::Cmp(s1: varList[v8].name, s2: name) != 0 )
  {
    ++v7;
    varList = this->varList;
    v8 = v7;
    if ( this->varList[v7].name == nullptr )
      return 0;
  }
  resId->index = v7;
  idStr::operator=(this: &resId->name, text: name);
  return 1;
}


// ========================================================================
// ?GetStr@VarId@TestExpression@@QAA?AVidStr@@XZ
// EA  : 0x82F7DC88
// RVA : 0x00F7DC88
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

TestExpression::VarId *__fastcall TestExpression::VarId::GetStr(TestExpression::VarId *this, idStr *result)
{
  idStr::idStr(this: &this->name, text: result);
  return this;
}


// ========================================================================
// ?Parse@TestExpression@@QAA_NPBD@Z
// EA  : 0x82F7FF28
// RVA : 0x00F7FF28
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall TestExpression::Parse(TestExpression *this, const char *exprStr, __int64 a3, __int64 a4, __int64 a5)
{
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *v5; // r3
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *v6; // r30
  const char *v8; // r3
  int v9; // r29
  __int64 v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  int v15; // [sp+8h] [-A8h]
  int v16; // [sp+8h] [-A8h]
  int v17; // [sp+Ch] [-A4h]
  int v18; // [sp+Ch] [-A4h]
  int v19; // [sp+10h] [-A0h]
  int v20; // [sp+10h] [-A0h]
  int v21; // [sp+14h] [-9Ch]
  int v22; // [sp+14h] [-9Ch]
  TestExpression::VarContext v23; // [sp+50h] [-60h] BYREF
  idStr v24[2]; // [sp+60h] [-50h] BYREF

  v6 = v5;
  v8 = "testExpr: %s\n";
  idLib::Printf(fmt: *(__int64 *)&exprStr, a2: a3, a3: a4, a4: a5, a5: v15, a6: v17, a7: v19, a8: v21);
  v23.varList = TestExpression::varList;
  v9 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Parse(this: v6, exprStr, varContext: &v23);
  LODWORD(v10) = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::PrintExp(
                   this: (idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> *)v24,
                   result: (idStr *)v6)->nodeAlloc.list;
  HIDWORD(v10) = "testExpr: %s\n";
  idLib::Printf(fmt: v10, a2: v13, a3: v12, a4: v11, a5: v16, a6: v18, a7: v20, a8: v22);
  idStr::FreeData(this: v24);
  return v9;
}


// ========================================================================
// __unwind$115742
// EA  : 0x82F7FF9C
// RVA : 0x00F7FF9C
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void _unwind_115742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?RunTest@@YAXPBDM@Z
// EA  : 0x82F7FFD0
// RVA : 0x00F7FFD0
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void __fastcall RunTest(const char *exprStr, double correctVal, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // [sp+8h] [-88h]
  int v9; // [sp+Ch] [-84h]
  int v10; // [sp+10h] [-80h]
  int v11; // [sp+14h] [-7Ch]
  __int64 v12; // [sp+18h] [-78h]
  TestExpression::VarContext v13; // [sp+50h] [-40h] BYREF
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> v14; // [sp+60h] [-30h] BYREF

  v14.root = 255;
  v14.nodeAlloc.memTag = 5;
  v14.nodeAlloc.listStatic = 0;
  memset(&v14.nodeAlloc, 0, 14);
  TestExpression::Parse(this: (TestExpression *)&v14, exprStr, a3: a4, a4: a5, a5: 0x5000000FFLL);
  v13.varList = TestExpression::varList;
  *(double *)&v12 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Eval(
                      this: &v14,
                      varContext: &v13);
  LODWORD(v5) = &unk_82390000;
  idLib::Printf(fmt: v12, a2: v5, a3: v7, a4: v6, a5: v8, a6: v9, a7: v10, a8: v11);
  if ( (v14.nodeAlloc.listStatic == 0 || v14.nodeAlloc.listStatic == 2) && v14.nodeAlloc.list != nullptr )
    idListArrayDelete<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode>(
      ptr: (char *)v14.nodeAlloc.list,
      num: v14.nodeAlloc.size);
}


// ========================================================================
// __unwind$115771
// EA  : 0x82F80080
// RVA : 0x00F80080
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void _unwind_115771()
{
  int v0; // r12

  TestExpression::~TestExpression(this: (TestExpression *)(v0 - 144 + 96));
}


// ========================================================================
// ?RuntimeExpressionRunTests@@YAHXZ
// EA  : 0x82F800A8
// RVA : 0x00F800A8
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

int __fastcall RuntimeExpressionRunTests(int a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r8
  __int64 v5; // r6
  int v6; // r4
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r4
  __int64 v10; // r6
  __int64 v11; // r8
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // r4
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // r4
  __int64 v18; // r8
  __int64 v19; // r6
  int v20; // r4
  __int64 v21; // r6
  __int64 v22; // r8
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r4

  RunTest(exprStr: "-5*3", correctVal: -15.0, a3: a2, a4: a3, a5: a4);
  LODWORD(v4) = &unk_82390000;
  RunTest(exprStr: "-5/3", correctVal: -1.6666666, a3: v6, a4: v5, a5: v4);
  HIDWORD(v7) = &unk_82150000;
  LODWORD(v8) = &unk_82390000;
  RunTest(exprStr: "-3*(-5/3)+2", correctVal: 7.0, a3: v9, a4: v8, a5: v7);
  HIDWORD(v10) = byte_821B0000;
  RunTest(exprStr: "max(-3, 6)", correctVal: 6.0, a3: (int)&unk_82390000, a4: v10, a5: v11);
  RunTest(exprStr: "-5*one", correctVal: -5.0, a3: v14, a4: v13, a5: v12);
  LODWORD(v15) = &unk_82390000;
  RunTest(exprStr: "two/4", correctVal: 0.5, a3: v17, a4: v16, a5: v15);
  HIDWORD(v18) = &off_82230000;
  LODWORD(v19) = &unk_82390000;
  RunTest(exprStr: "three*(3/4)", correctVal: 2.25, a3: v20, a4: v19, a5: v18);
  HIDWORD(v21) = &unk_82390000;
  RunTest(exprStr: "( -3 + 3/four)", correctVal: -2.25, a3: (int)&unk_82390000, a4: v21, a5: v22);
  RunTest(exprStr: "5*two + 4* ( -3 + 3/four)", correctVal: 1.0, a3: v25, a4: v24, a5: v23);
  return 0;
}


// ========================================================================
// ?testRuntimeExpression_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F80188
// RVA : 0x00F80188
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void __fastcall testRuntimeExpression_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // r11
  bool v5; // cr56
  __int64 v6; // r10
  __int64 v7; // r4
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r4
  int v13; // r3
  const char *v14; // r4
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r8
  int v20; // [sp+8h] [-A8h]
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+Ch] [-A4h]
  int v24; // [sp+10h] [-A0h]
  int v25; // [sp+10h] [-A0h]
  int v26; // [sp+14h] [-9Ch]
  int v27; // [sp+14h] [-9Ch]
  __int64 v28; // [sp+18h] [-98h]
  TestExpression::VarContext v29; // [sp+50h] [-60h] BYREF
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext> v30; // [sp+60h] [-50h] BYREF
  idStr v31; // [sp+80h] [-30h] BYREF

  v4 = *(_DWORD *)HIDWORD(args);
  v5 = *(_DWORD *)HIDWORD(args) < 2;
  v29.varList = *(TestExpression::VarListEntry **)HIDWORD(args);
  if ( v5 )
  {
    HIDWORD(args) = "USAGE: testRuntimeExpression <expresssion>\n";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v20, a6: v22, a7: v24, a8: v26);
    LODWORD(v6) = &unk_82390000;
    HIDWORD(v7) = "running unit test\n";
    idLib::Printf(fmt: v7, a2: v9, a3: v8, a4: v6, a5: v21, a6: v23, a7: v25, a8: v27);
    RuntimeExpressionRunTests(a1: v13, a2: v12, a3: v11, a4: v10);
  }
  else
  {
    if ( v4 <= 1 )
      v14 = &byte_8200D768;
    else
      v14 = *(const char **)(HIDWORD(args) + 8);
    idStr::idStr(this: &v31, text: v14);
    v30.root = 255;
    v30.nodeAlloc.memTag = 5;
    v30.nodeAlloc.listStatic = 0;
    memset(&v30.nodeAlloc, 0, 14);
    TestExpression::Parse(this: (TestExpression *)&v30, exprStr: v31.data, a3: v16, a4: v15, a5: 0x5000000FFLL);
    v29.varList = TestExpression::varList;
    *(double *)&v28 = idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::Eval(
                        this: &v30,
                        varContext: &v29);
    LODWORD(v17) = &unk_82390000;
    idLib::Printf(fmt: v28, a2: v17, a3: v19, a4: v18, a5: v20, a6: v22, a7: v24, a8: v26);
    TestExpression::~TestExpression(this: (TestExpression *)&v30);
    idStr::FreeData(this: &v31);
  }
}


// ========================================================================
// __unwind$115897
// EA  : 0x82F80270
// RVA : 0x00F80270
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void _unwind_115897()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 128));
}


// ========================================================================
// __unwind$115898
// EA  : 0x82F80298
// RVA : 0x00F80298
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

void _unwind_115898()
{
  int v0; // r12

  TestExpression::~TestExpression(this: (TestExpression *)(v0 - 176 + 96));
}


// ========================================================================
// `dynamic initializer for 'testRuntimeExpression_v''
// EA  : 0x83396A30
// RVA : 0x01396A30
// PDB : w:\tech5\shared\idlib\runtimeexpression.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testRuntimeExpression_v__()
{
  return idCommandLink::idCommandLink(
           this: &testRuntimeExpression_v,
           cmdName: "testRuntimeExpression",
           function: (void (__fastcall *)(const idCmdArgs *))testRuntimeExpression_f,
           description: "test runtime expression",
           argCompletion: nullptr);
}

