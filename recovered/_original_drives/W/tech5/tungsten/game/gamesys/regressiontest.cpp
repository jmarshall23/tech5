
// ========================================================================
// ?GetImageNumString@idRegressionTest@@QAAPBDXZ
// EA  : 0x82D6C028
// RVA : 0x00D6C028
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

char *__fastcall idRegressionTest::GetImageNumString(idRegressionTest *this)
{
  int imageNum; // r11
  int i; // r10
  char v3; // r8

  imageNum = this->imageNum;
  for ( i = 3; imageNum != 0 && i != 0 || i == 3; --i )
  {
    v3 = a0123456789[imageNum % 10];
    imageNum /= 10;
    this->imageNumStr[i] = v3;
  }
  return &this->imageNumStr[i + 1];
}


// ========================================================================
// ??0idRegressionTest@@QAA@XZ
// EA  : 0x82D6C0A8
// RVA : 0x00D6C0A8
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

idRegressionTest *__fastcall idRegressionTest::idRegressionTest(idRegressionTest *this)
{
  idStr *p_testPath; // r3

  this->testReport = nullptr;
  this->recordState = RECORD_NONE;
  this->testPath.allocedAndFlag = 20;
  this->testPath.len = 0;
  p_testPath = &this->testPath;
  this->testPath.data = p_testPath->baseBuffer;
  this->testPath.baseBuffer[0] = 0;
  this->testName.allocedAndFlag = 20;
  this->testName.len = 0;
  this->testName.data = this->testName.baseBuffer;
  this->testName.baseBuffer[0] = 0;
  this->fastExit = false;
  this->testFailed = false;
  this->imageNum = 0;
  idStr::operator=(this: p_testPath, text: &byte_8200D768);
  idStr::operator=(this: &this->testName, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$487367
// EA  : 0x82D6C13C
// RVA : 0x00D6C13C
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void _unwind_487367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$487368
// EA  : 0x82D6C168
// RVA : 0x00D6C168
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void _unwind_487368()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ?EndTests@idRegressionTest@@QAAXXZ
// EA  : 0x82D6C198
// RVA : 0x00D6C198
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void __fastcall idRegressionTest::EndTests(idRegressionTest *this)
{
  idRegression *v2; // r3
  BOOL fastExit; // r11

  if ( this->recordState == RECORD_MAKE && this->testFailed )
  {
    v2 = common->GetRegression(this: common);
    v2->DisplayTextScreen(
      this: v2,
      a2: "Regression Test failed while recording. This test should not be submitted until fixed!",
      a3: 2);
    this->testFailed = false;
  }
  if ( this->recordState == RECORD_PLAY && idStr::Cmp(s1: this->testName.data, s2: &byte_8200D768) != 0 )
  {
    this->testReport->WriteReport(this: this->testReport);
    this->testReport = nullptr;
  }
  fastExit = this->fastExit;
  this->recordState = RECORD_NONE;
  if ( fastExit )
  {
    this->fastExit = false;
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "recordEvents \n");
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "activateConsole 0.5 \n");
  }
  this->imageNum = 0;
}


// ========================================================================
// ?AddTest@idRegressionTest@@QAAXPAVidTarget_Test@@@Z
// EA  : 0x82D6C298
// RVA : 0x00D6C298
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void __fastcall idRegressionTest::AddTest(idRegressionTest *this, idTarget_Test *test)
{
  int testCount; // r11
  idRegression *v4; // r3
  idStr *p_testName; // r29
  const char *v6; // r3
  recordState_t v7; // r3
  idRegression *v8; // r3
  size_t len; // r30

  testCount = this->testCount;
  if ( testCount <= 0 )
  {
    v4 = common->GetRegression(this: common);
    p_testName = &this->testName;
    v6 = v4->GetName(this: v4);
    idStr::operator=(this: &this->testName, text: v6);
    if ( idStr::Cmp(s1: this->testName.data, s2: &byte_8200D768) != 0 )
    {
      v7 = common->GetRecordState(this: common);
      this->recordState = v7;
      if ( v7 == RECORD_PLAY )
      {
        v8 = common->GetRegression(this: common);
        this->testReport = v8->GetTestReport(this: v8);
      }
      len = p_testName->len;
      idStr::EnsureAlloced(this: &this->testPath, amount: p_testName->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->testPath.data, Src: this->testName.data, Size: len);
      this->testPath.data[len] = 0;
      this->testPath.len = len;
      idStr::StripPath(this: &this->testName);
      ++this->testCount;
    }
  }
  else
  {
    this->testCount = testCount + 1;
  }
}


// ========================================================================
// ?RemoveTest@idRegressionTest@@QAAXPAVidTarget_Test@@@Z
// EA  : 0x82D6C3B0
// RVA : 0x00D6C3B0
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void __fastcall idRegressionTest::RemoveTest(idRegressionTest *this, idTarget_Test *test)
{
  int v2; // r11

  v2 = this->testCount - 1;
  this->testCount = v2;
  if ( v2 <= 0 && this->recordState != RECORD_NONE )
    idRegressionTest::EndTests(this);
}


// ========================================================================
// ?AddResult@idRegressionTest@@QAAXW4testStatus_t@@VidStr@@1@Z
// EA  : 0x82D6C4D0
// RVA : 0x00D6C4D0
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void __fastcall idRegressionTest::AddResult(
        idRegressionTest *this,
        encounterGroupRole_t result,
        idStr *typeName,
        idStr *info)
{
  recordState_t recordState; // r11
  idStr *v8; // r3
  idStr *v9; // r3
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  recordState = this->recordState;
  if ( recordState == RECORD_MAKE && result == ROLE_FLANK )
    this->testFailed = true;
  if ( recordState == RECORD_PLAY )
  {
    idTestReport::AddResult(this: this->testReport, result: this->fastExit ? ROLE_NONE : result);
    v8 = idStr::idStr(this: v10, text: typeName);
    idTestReport::AddType(this: this->testReport, type: v8);
    v9 = idStr::idStr(this: v10, text: info);
    idTestReport::AddInfo(this: this->testReport, info: v9);
  }
  idStr::FreeData(this: typeName);
  idStr::FreeData(this: info);
}


// ========================================================================
// __unwind$487679_0
// EA  : 0x82D6C578
// RVA : 0x00D6C578
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void _unwind_487679_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 160 + 204));
}


// ========================================================================
// __unwind$487680
// EA  : 0x82D6C5A0
// RVA : 0x00D6C5A0
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void _unwind_487680()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 160 + 196));
}


// ========================================================================
// `dynamic initializer for 'regressionTest''
// EA  : 0x83380FE8
// RVA : 0x01380FE8
// PDB : w:\tech5\tungsten\game\gamesys\regressiontest.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__regressionTest__()
{
  idRegressionTest::idRegressionTest(this: &regressionTest);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__regressionTest__);
}

