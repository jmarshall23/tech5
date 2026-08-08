
// ========================================================================
// ?OnActivate@idTarget_Test@@MAAXPAVidEntity@@@Z
// EA  : 0x82CE85F0
// RVA : 0x00CE85F0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_Test::OnActivate(idTarget_Test *this, idEntity *activator)
{
  BOOL testFastExit; // r10

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    testFastExit = this->testFastExit;
    this->activated = true;
    if ( testFastExit )
    {
      if ( regressionTest.recordState == RECORD_PLAY )
      {
        regressionTest.fastExit = true;
        idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: 0.001);
      }
    }
    else
    {
      this->ActivateTargets(this, a2: activator);
    }
  }
}


// ========================================================================
// ?Event_TimerEvent@idTarget_TestExit@@AAA?AVeventVoid@@XZ
// EA  : 0x82CE8668
// RVA : 0x00CE8668
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestExit *__fastcall idTarget_TestExit::Event_TimerEvent(idTarget_TestExit *this, eventVoid *result)
{
  int v3; // r30

  if ( regressionTest.recordState != RECORD_NONE )
  {
    if ( regressionTest.recordState == RECORD_MAKE )
    {
      v3 = ((int (__fastcall *)(idCommon *, eventVoid *))common->GetRegression)(a1: common, a2: result);
      (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "~");
      (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "disconnect \n");
      (*(void (__fastcall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "recordEvents \n");
    }
  }
  else
  {
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect\n");
  }
  return this;
}


// ========================================================================
// ?RunCommands@idTarget_TestCommand@@AAAXXZ
// EA  : 0x82CE8740
// RVA : 0x00CE8740
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestCommand::RunCommands(idTarget_TestCommand *this)
{
  idRegression *v2; // r31
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  int v6; // r30
  int v7; // r29
  va *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  va *v12; // r3
  int v13; // [sp+8h] [-1088h]
  int v14; // [sp+Ch] [-1084h]
  int v15; // [sp+10h] [-1080h]
  int v16; // [sp+14h] [-107Ch]
  int v17; // [sp+18h] [-1078h]
  int v18; // [sp+1Ch] [-1074h]
  va v19; // [sp+50h] [-1040h] BYREF

  if ( common->GetRecordState(this: common) != RECORD_PLAY )
  {
    v2 = common->GetRegression(this: common);
    v2->QueueEventString(this: v2, a2: "~");
    v2->QueueEventString(this: v2, a2: "g_stopTime 1 \n");
    v6 = 0;
    if ( this->testCommandLines.num > 0 )
    {
      v7 = 0;
      do
      {
        HIDWORD(v5) = this->testCommandLines.list[v7].data;
        v8 = va::va(
               this: &v19,
               fmt: "%s\n",
               a3: v5,
               a4: v4,
               a5: v3,
               a6: v13,
               a7: v14,
               a8: v15,
               a9: v16,
               a10: v17,
               a11: v18);
        v2->QueueEventString(this: v2, a2: v8->buffer);
        LODWORD(v4) = this->testCommandLines.num;
        ++v6;
        ++v7;
      }
      while ( v6 < (int)v4 );
    }
    v2->QueueEventString(this: v2, a2: "g_stopTime 0 \n");
    LODWORD(v9) = &unk_82300000;
    HIDWORD(v10) = this->name.data;
    v12 = va::va(
            this: &v19,
            fmt: "trigger %s \n",
            a3: v10,
            a4: v9,
            a5: v11,
            a6: v13,
            a7: v14,
            a8: v15,
            a9: v16,
            a10: v17,
            a11: v18);
    v2->QueueEventString(this: v2, a2: v12->buffer);
    v2->QueueEventString(this: v2, a2: "~");
  }
}


// ========================================================================
// ?Event_TimerEvent@idTarget_TestCommand@@AAA?AVeventVoid@@XZ
// EA  : 0x82CE8890
// RVA : 0x00CE8890
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestCommand *__fastcall idTarget_TestCommand::Event_TimerEvent(
        idTarget_TestCommand *this,
        idTarget_Test *result)
{
  idTarget_Test::OnActivate(this: result, activator: result);
  return this;
}


// ========================================================================
// ?ScreenShot@@YAXVidStr@@@Z
// EA  : 0x82CE88D0
// RVA : 0x00CE88D0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall ScreenShot(idStr *imageName, int a2, int a3, int a4, __int64 a5)
{
  __int64 v6; // r6
  __int64 v7; // r10
  va *v8; // r3
  int v9; // [sp+8h] [-1998h]
  int v10; // [sp+Ch] [-1994h]
  int v11; // [sp+10h] [-1990h]
  int v12; // [sp+14h] [-198Ch]
  int v13; // [sp+18h] [-1988h]
  int v14; // [sp+1Ch] [-1984h]
  idStr v15; // [sp+50h] [-1950h] BYREF
  idCmdArgs v16; // [sp+70h] [-1930h] BYREF
  va v17; // [sp+980h] [-1020h] BYREF

  LODWORD(v6) = imageName->data;
  LODWORD(v7) = &unk_82300000;
  HIDWORD(v7) = &regressionTest;
  HIDWORD(v6) = regressionTest.testPath.data;
  v8 = va::va(
         this: &v17,
         fmt: "regression/reports/%s/%s",
         a3: v6,
         a4: a5,
         a5: v7,
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idStr::idStr(this: &v15, text: v8);
  v16.argc = 0;
  idCmdArgs::AppendArg(this: &v16, text: "jpg");
  idCmdArgs::AppendArg(this: &v16, text: v15.data);
  R_ScreenShot_f(args: &v16);
  idStr::FreeData(this: &v15);
  idStr::FreeData(this: imageName);
}


// ========================================================================
// __unwind$488723
// EA  : 0x82CE8974
// RVA : 0x00CE8974
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488723()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 6560 + 6580));
}


// ========================================================================
// __unwind$488724_1
// EA  : 0x82CE899C
// RVA : 0x00CE899C
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488724_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6560 + 80));
}


// ========================================================================
// ??0idTarget_Test@@QAA@VidStr@@@Z
// EA  : 0x82CE89D0
// RVA : 0x00CE89D0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_Test *__fastcall idTarget_Test::idTarget_Test(idTarget_Test *this, idStr *_testType)
{
  int len; // r28

  idEntity::idEntity(this);
  this->__vftable = (idTarget_Test_vtbl *)&idTarget_Test::`vftable';
  this->testType.len = 0;
  this->testType.data = this->testType.baseBuffer;
  this->testType.allocedAndFlag = 20;
  this->testType.baseBuffer[0] = 0;
  this->testStatus = TEST_FAIL;
  this->info.allocedAndFlag = 20;
  this->info.data = this->info.baseBuffer;
  this->info.len = 0;
  this->info.baseBuffer[0] = 0;
  this->activated = false;
  this->testComment.allocedAndFlag = 20;
  this->testComment.len = 0;
  this->testComment.data = this->testComment.baseBuffer;
  this->testComment.baseBuffer[0] = 0;
  this->testFastExit = false;
  this->testErrorShot = false;
  len = _testType->len;
  idStr::EnsureAlloced(this: &this->testType, amount: _testType->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->testType.data, Src: _testType->data, Size: len);
  this->testType.data[len] = 0;
  this->testType.len = len;
  idRegressionTest::AddTest(this: &regressionTest, test: this);
  idStr::FreeData(this: _testType);
  return this;
}


// ========================================================================
// __unwind$488774
// EA  : 0x82CE8AC0
// RVA : 0x00CE8AC0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488774()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 172));
}


// ========================================================================
// __unwind$488775
// EA  : 0x82CE8AE8
// RVA : 0x00CE8AE8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488775()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$488776
// EA  : 0x82CE8B10
// RVA : 0x00CE8B10
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488776()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 800));
}


// ========================================================================
// __unwind$488777
// EA  : 0x82CE8B3C
// RVA : 0x00CE8B3C
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488777()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 836));
}


// ========================================================================
// __unwind$488778
// EA  : 0x82CE8B68
// RVA : 0x00CE8B68
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_488778()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 872));
}


// ========================================================================
// ?Event_TimerEvent@idTarget_Test@@IAA?AVeventVoid@@XZ
// EA  : 0x82CE8BA0
// RVA : 0x00CE8BA0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_Test *__fastcall idTarget_Test::Event_TimerEvent(idTarget_Test *this, eventVoid *result)
{
  idStr *v3; // r3
  __int64 v4; // r8
  int v5; // r6
  int v6; // r5
  int v7; // r4
  idStr v9; // [sp+50h] [-60h] BYREF
  idStr v10; // [sp+70h] [-40h] BYREF

  if ( *(_BYTE *)&result[905] != 0 )
  {
    idStr::idStr(this: &v9, text: "screenshot_error.jpg");
    v3 = idStr::idStr(this: &v10, text: &v9);
    ScreenShot(imageName: v3, a2: v7, a3: v6, a4: v5, a5: v4);
    idStr::FreeData(this: &v9);
  }
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect \n");
  return this;
}


// ========================================================================
// __unwind$489105_0
// EA  : 0x82CE8C2C
// RVA : 0x00CE8C2C
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489105_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?ReportResults@idTarget_Test@@MAAXXZ
// EA  : 0x82CE8C60
// RVA : 0x00CE8C60
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_Test::ReportResults(idTarget_Test *this, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  __int64 v7; // r6
  va *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  idStr *v13; // r3
  __int64 v14; // r8
  int v15; // r6
  int v16; // r5
  int v17; // r4
  __int64 v18; // r6
  __int64 v19; // r8
  __int64 v20; // r10
  va *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  idStr *v26; // r30
  idStr *v27; // r3
  int v28; // [sp+8h] [-2108h]
  int v29; // [sp+8h] [-2108h]
  int v30; // [sp+8h] [-2108h]
  int v31; // [sp+8h] [-2108h]
  int v32; // [sp+Ch] [-2104h]
  int v33; // [sp+Ch] [-2104h]
  int v34; // [sp+Ch] [-2104h]
  int v35; // [sp+Ch] [-2104h]
  int v36; // [sp+10h] [-2100h]
  int v37; // [sp+10h] [-2100h]
  int v38; // [sp+10h] [-2100h]
  int v39; // [sp+10h] [-2100h]
  int v40; // [sp+14h] [-20FCh]
  int v41; // [sp+14h] [-20FCh]
  int v42; // [sp+14h] [-20FCh]
  int v43; // [sp+14h] [-20FCh]
  int v44; // [sp+18h] [-20F8h]
  int v45; // [sp+18h] [-20F8h]
  int v46; // [sp+18h] [-20F8h]
  int v47; // [sp+18h] [-20F8h]
  int v48; // [sp+1Ch] [-20F4h]
  int v49; // [sp+1Ch] [-20F4h]
  int v50; // [sp+1Ch] [-20F4h]
  int v51; // [sp+1Ch] [-20F4h]
  idStr v52; // [sp+60h] [-20B0h] BYREF
  idStr v53; // [sp+80h] [-2090h] BYREF
  idStr v54; // [sp+A0h] [-2070h] BYREF
  idStr v55; // [sp+C0h] [-2050h] BYREF
  va v56; // [sp+E0h] [-2030h] BYREF
  va v57; // [sp+10E0h] [-1030h] BYREF

  LODWORD(a6) = this->testStatus;
  if ( (_DWORD)a6 == 3 && regressionTest.recordState == RECORD_PLAY && !regressionTest.fastExit )
  {
    LODWORD(v7) = this->info.data;
    HIDWORD(v7) = this->name.data;
    v8 = va::va(
           this: &v56,
           fmt: "\n          Entity: <TT><B> %s </B></TT><BR>\n          %s\n       ",
           a3: v7,
           a4: a5,
           a5: a6,
           a6: v28,
           a7: v32,
           a8: v36,
           a9: v40,
           a10: v44,
           a11: v48);
    idStr::operator=(this: &this->info, text: v8);
    if ( this->testErrorShot )
    {
      HIDWORD(v9) = idRegressionTest::GetImageNumString(this: &regressionTest);
      v12 = va::va(
              this: &v56,
              fmt: "screenshot_error_%s.jpg",
              a3: v9,
              a4: v11,
              a5: v10,
              a6: v29,
              a7: v33,
              a8: v37,
              a9: v41,
              a10: v45,
              a11: v49);
      idStr::idStr(this: &v52, text: v12);
      v13 = idStr::idStr(this: &v53, text: &v52);
      ScreenShot(imageName: v13, a2: v17, a3: v16, a4: v15, a5: v14);
      idStr::idStr(this: &v54, text: &this->info);
      idStr::operator=(this: &this->info, text: "\n");
      idStr::Append(this: &this->info, text: "          <DIV style='float: left;'>\n");
      LODWORD(v18) = v52.data;
      LODWORD(v19) = &unk_82300000;
      HIDWORD(v18) = v52.data;
      v21 = va::va(
              this: &v57,
              fmt: "            <A href='%s'><IMG src='%s' width='200'></A>\n",
              a3: v18,
              a4: v19,
              a5: v20,
              a6: v30,
              a7: v34,
              a8: v38,
              a9: v42,
              a10: v46,
              a11: v50);
      idStr::Append(this: &this->info, text: v21);
      idStr::Append(this: &this->info, text: "          </DIV>\n");
      LODWORD(v22) = &unk_82300000;
      HIDWORD(v22) = v54.data;
      v25 = va::va(
              this: &v57,
              fmt: "          %s\n",
              a3: v22,
              a4: v24,
              a5: v23,
              a6: v31,
              a7: v35,
              a8: v39,
              a9: v43,
              a10: v47,
              a11: v51);
      idStr::Append(this: &this->info, text: v25);
      idStr::Append(this: &this->info, text: "        ");
      idStr::FreeData(this: &v54);
      idStr::FreeData(this: &v52);
    }
  }
  v26 = idStr::idStr(this: &v53, text: &this->info);
  v27 = idStr::idStr(this: &v55, text: &this->testType);
  idRegressionTest::AddResult(this: &regressionTest, result: this->testStatus, typeName: v27, info: v26);
}


// ========================================================================
// __unwind$489139_1
// EA  : 0x82CE8DF4
// RVA : 0x00CE8DF4
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489139_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 96));
}


// ========================================================================
// __unwind$489141_2
// EA  : 0x82CE8E1C
// RVA : 0x00CE8E1C
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489141_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 160));
}


// ========================================================================
// __unwind$489142_1
// EA  : 0x82CE8E44
// RVA : 0x00CE8E44
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489142_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 8464 + 80));
}


// ========================================================================
// ?OnActivate@idTarget_TestActivation@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE8E70
// RVA : 0x00CE8E70
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestActivation::OnActivate(idTarget_TestActivation *this, idEntity *activator)
{
  int len; // r30

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    this->testStatus = !this->testShouldBeActivated ? TEST_FAIL : TEST_PASS;
    len = this->testComment.len;
    idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
    this->info.data[len] = 0;
    this->info.len = len;
    this->ReportResults(this);
  }
  idTarget_Test::OnActivate(this, activator);
}


// ========================================================================
// ?OnActivate@idTarget_TestScreenShot@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE8F28
// RVA : 0x00CE8F28
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestScreenShot::OnActivate(idTarget_TestScreenShot *this, idEntity *activator)
{
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  va *v7; // r3
  idStr *v8; // r3
  __int64 v9; // r8
  int v10; // r6
  int v11; // r5
  int v12; // r4
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  idTarget_TestScreenShot_vtbl *v17; // r10
  int v18; // [sp+8h] [-20A8h]
  int v19; // [sp+8h] [-20A8h]
  int v20; // [sp+Ch] [-20A4h]
  int v21; // [sp+Ch] [-20A4h]
  int v22; // [sp+10h] [-20A0h]
  int v23; // [sp+10h] [-20A0h]
  int v24; // [sp+14h] [-209Ch]
  int v25; // [sp+14h] [-209Ch]
  int v26; // [sp+18h] [-2098h]
  int v27; // [sp+18h] [-2098h]
  int v28; // [sp+1Ch] [-2094h]
  int v29; // [sp+1Ch] [-2094h]
  idStr v30; // [sp+50h] [-2060h] BYREF
  idStr v31; // [sp+70h] [-2040h] BYREF
  va v32; // [sp+90h] [-2020h] BYREF
  va v33; // [sp+1090h] [-1020h] BYREF

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    if ( regressionTest.recordState == RECORD_PLAY )
    {
      HIDWORD(v4) = idRegressionTest::GetImageNumString(this: &regressionTest);
      v7 = va::va(
             this: &v32,
             fmt: "screenshot_%s",
             a3: v4,
             a4: v6,
             a5: v5,
             a6: v18,
             a7: v20,
             a8: v22,
             a9: v24,
             a10: v26,
             a11: v28);
      idStr::idStr(this: &v30, text: v7);
      v8 = idStr::idStr(this: &v31, text: &v30);
      ScreenShot(imageName: v8, a2: v12, a3: v11, a4: v10, a5: v9);
      LODWORD(v13) = v30.data;
      LODWORD(v14) = &unk_82300000;
      HIDWORD(v13) = v30.data;
      v16 = va::va(
              this: &v33,
              fmt: "<A href='%s.jpg'><IMG src='%s.jpg' width='200'></A>",
              a3: v13,
              a4: v15,
              a5: v14,
              a6: v19,
              a7: v21,
              a8: v23,
              a9: v25,
              a10: v27,
              a11: v29);
      idStr::operator=(this: &this->info, text: v16);
      idStr::FreeData(this: &v30);
    }
    else
    {
      idStr::operator=(this: &this->info, text: &this->testComment);
    }
    v17 = this->__vftable;
    this->testStatus = TEST_PASS;
    v17->ReportResults(this);
  }
  idTarget_Test::OnActivate(this, activator);
}


// ========================================================================
// __unwind$489236_1
// EA  : 0x82CE9010
// RVA : 0x00CE9010
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489236_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8368 + 80));
}


// ========================================================================
// ?OnActivate@idTarget_TestExit@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE9038
// RVA : 0x00CE9038
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestExit::OnActivate(idTarget_TestExit *this, idEntity *activator)
{
  int len; // r30
  idTarget_TestExit_vtbl *v4; // r9

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    this->activated = true;
    len = this->testComment.len;
    idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
    this->info.data[len] = 0;
    this->info.len = len;
    v4 = this->__vftable;
    this->testStatus = TEST_PASS;
    v4->ReportResults(this);
    idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: 0.001);
  }
}


// ========================================================================
// ?OnActivate@idTarget_TestCommand@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE90E0
// RVA : 0x00CE90E0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestCommand::OnActivate(idTarget_TestCommand *this, idEntity *activator)
{
  int v4; // r11
  idTarget_TestCommand_vtbl *v5; // r10

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    v4 = this->testActivateCount + 1;
    this->testActivateCount = v4;
    if ( v4 == 1 )
    {
      idTarget_TestCommand::RunCommands(this);
      idEventReceiver::PostEventSec(this, ev: &EV_TimerEvent, time: 1.0);
    }
    else if ( v4 == 2 )
    {
      v5 = this->__vftable;
      this->testStatus = TEST_PASS;
      ((void (*)(void))v5->ReportResults)();
      idTarget_Test::OnActivate(this, activator);
    }
  }
}


// ========================================================================
// ?ReportResults@idTarget_TestCommand@@EAAXXZ
// EA  : 0x82CE9198
// RVA : 0x00CE9198
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestCommand::ReportResults(idTarget_TestCommand *this)
{
  int len; // r29
  idStr *p_info; // r31
  int v4; // r28
  int i; // r29
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  int v12; // r6
  int v13; // r5
  int v14; // r4
  int v15; // [sp+8h] [-1098h]
  int v16; // [sp+Ch] [-1094h]
  int v17; // [sp+10h] [-1090h]
  int v18; // [sp+14h] [-108Ch]
  int v19; // [sp+18h] [-1088h]
  int v20; // [sp+1Ch] [-1084h]
  va v21; // [sp+50h] [-1050h] BYREF

  len = this->testComment.len;
  p_info = &this->info;
  idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
  v4 = 0;
  this->info.data[len] = 0;
  this->info.len = len;
  idStr::Append(this: p_info, text: "\n");
  idStr::Append(this: p_info, text: "          <TABLE border='0'>\n");
  for ( i = 0; i < this->testCommandLines.num; ++v4 )
  {
    idStr::Append(this: p_info, text: "            <TR>\n");
    idStr::Append(this: p_info, text: "              <TD width='20'></TD>\n");
    HIDWORD(v6) = this->testCommandLines.list[v4].data;
    v9 = va::va(
           this: &v21,
           fmt: "              <TD><TT> %s </TT></TD>\n",
           a3: v6,
           a4: v8,
           a5: v7,
           a6: v15,
           a7: v16,
           a8: v17,
           a9: v18,
           a10: v19,
           a11: v20);
    idStr::Append(this: p_info, text: v9);
    idStr::Append(this: p_info, text: "            </TR>\n");
    ++i;
  }
  idStr::Append(this: p_info, text: "          </TABLE>\n");
  idTarget_Test::ReportResults(this, a2: v14, a3: v13, a4: v12, a5: v11, a6: v10);
}


// ========================================================================
// ?OnActivate@idTarget_TestInstruction@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE92B8
// RVA : 0x00CE92B8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestInstruction::OnActivate(idTarget_TestInstruction *this, idEntity *activator)
{
  idRegression *v4; // r3
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  va *v8; // r3
  int v9; // [sp+8h] [-1068h]
  int v10; // [sp+Ch] [-1064h]
  int v11; // [sp+10h] [-1060h]
  int v12; // [sp+14h] [-105Ch]
  int v13; // [sp+18h] [-1058h]
  int v14; // [sp+1Ch] [-1054h]
  va v15; // [sp+50h] [-1020h] BYREF

  if ( regressionTest.recordState == RECORD_MAKE && !this->activated )
  {
    v4 = common->GetRegression(this: common);
    v4->DisplayTextScreen(this: v4, a2: this->testComment.data, a3: this->displayTime);
    LODWORD(v5) = &unk_82300000;
    HIDWORD(v5) = this->testComment.data;
    v8 = va::va(
           this: &v15,
           fmt: "<I>%s</I>",
           a3: v5,
           a4: v7,
           a5: v6,
           a6: v9,
           a7: v10,
           a8: v11,
           a9: v12,
           a10: v13,
           a11: v14);
    idStr::operator=(this: &this->info, text: v8);
    this->ReportResults(this);
  }
  idTarget_Test::OnActivate(this, activator);
}


// ========================================================================
// ?OnActivate@idTarget_TestShotsFired@@MAAXPAVidEntity@@@Z
// EA  : 0x82CE9388
// RVA : 0x00CE9388
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestShotsFired::OnActivate(idTarget_TestShotsFired *this, idEntity *activator)
{
  idRegression *v4; // r3
  int SessionStat; // r3
  int minNumShots; // r8
  int len; // r27
  idRegression *v8; // r24
  idStr *v9; // r23
  idStr *v10; // r22
  idStr *v11; // r21
  idTestReport *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  va *v16; // r3
  idRegression *v17; // r24
  idStr *v18; // r23
  idStr *v19; // r22
  idStr *v20; // r21
  idTestReport *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  idRegression *v26; // r28
  idStr *v27; // r27
  idStr *v28; // r26
  idStr *v29; // r24
  idTestReport *v30; // r3
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  int v35; // [sp+8h] [-1178h]
  int v36; // [sp+8h] [-1178h]
  int v37; // [sp+8h] [-1178h]
  int v38; // [sp+Ch] [-1174h]
  int v39; // [sp+Ch] [-1174h]
  int v40; // [sp+Ch] [-1174h]
  int v41; // [sp+10h] [-1170h]
  int v42; // [sp+10h] [-1170h]
  int v43; // [sp+10h] [-1170h]
  int v44; // [sp+14h] [-116Ch]
  int v45; // [sp+14h] [-116Ch]
  int v46; // [sp+14h] [-116Ch]
  int v47; // [sp+18h] [-1168h]
  int v48; // [sp+18h] [-1168h]
  int v49; // [sp+18h] [-1168h]
  int v50; // [sp+1Ch] [-1164h]
  int v51; // [sp+1Ch] [-1164h]
  int v52; // [sp+1Ch] [-1164h]
  idStr v53; // [sp+60h] [-1120h] BYREF
  idStr v54; // [sp+80h] [-1100h] BYREF
  idStr v55; // [sp+A0h] [-10E0h] BYREF
  idStr v56; // [sp+C0h] [-10C0h] BYREF
  idStr v57; // [sp+E0h] [-10A0h] BYREF
  idStr v58; // [sp+100h] [-1080h] BYREF
  va v59; // [sp+120h] [-1060h] BYREF

  v4 = common->GetRegression(this: common);
  if ( v4->GetTestInProgress(this: v4) )
  {
    SessionStat = idRageMetrics::GetSessionStat(this: clientGame->rageMetrics, playerId: 0, stat: RAGE_STAT_SHOTS);
    minNumShots = this->minNumShots;
    this->numShotsFired = SessionStat;
    if ( SessionStat >= minNumShots && SessionStat <= this->maxNumShots )
      this->testStatus = TEST_PASS;
    len = this->testComment.len;
    idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
    this->info.data[len] = 0;
    this->info.len = len;
    idStr::Append(this: &this->info, text: "\n");
    idStr::Append(this: &this->info, text: "          <TABLE border='0'>\n");
    idStr::Append(this: &this->info, text: "            <TR>\n");
    idStr::Append(this: &this->info, text: "              <TD width='20'></TD>\n");
    idStr::Append(this: &this->info, text: "              <TD> ");
    v55.len = 0;
    v55.allocedAndFlag = 20;
    v55.data = v55.baseBuffer;
    v55.baseBuffer[0] = 0;
    v54.allocedAndFlag = 20;
    v54.data = v54.baseBuffer;
    v54.len = 0;
    v54.baseBuffer[0] = 0;
    v53.allocedAndFlag = 20;
    v53.data = v53.baseBuffer;
    v53.len = 0;
    v53.baseBuffer[0] = 0;
    idStr::operator=(this: &v55, text: "expectedMin");
    idStr::operator=(this: &v54, text: "int");
    idStr::Format(this: &v53, fmt: "%d", this->minNumShots);
    v8 = common->GetRegression(this: common);
    v9 = idStr::idStr(this: &v58, text: &v53);
    v10 = idStr::idStr(this: &v56, text: &v54);
    v11 = idStr::idStr(this: &v57, text: &v55);
    v12 = v8->GetTestReport(this: v8);
    idTestReport::AddTestReportField(this: v12, name: v11, type: v10, value: v9);
    HIDWORD(v13) = &unk_82300000;
    HIDWORD(v14) = v53.data;
    v16 = va::va(
            this: &v59,
            fmt: " min=<B>%s</B>",
            a3: v14,
            a4: v13,
            a5: v15,
            a6: v35,
            a7: v38,
            a8: v41,
            a9: v44,
            a10: v47,
            a11: v50);
    idStr::Append(this: &this->info, text: v16);
    idStr::operator=(this: &v55, text: "expectedMax");
    idStr::operator=(this: &v54, text: "int");
    idStr::Format(this: &v53, fmt: "%d", this->maxNumShots);
    v17 = common->GetRegression(this: common);
    v18 = idStr::idStr(this: &v57, text: &v53);
    v19 = idStr::idStr(this: &v56, text: &v54);
    v20 = idStr::idStr(this: &v58, text: &v55);
    v21 = v17->GetTestReport(this: v17);
    idTestReport::AddTestReportField(this: v21, name: v20, type: v19, value: v18);
    LODWORD(v22) = &unk_82300000;
    HIDWORD(v22) = v53.data;
    v25 = va::va(
            this: &v59,
            fmt: " max=<B>%s</B>",
            a3: v22,
            a4: v24,
            a5: v23,
            a6: v36,
            a7: v39,
            a8: v42,
            a9: v45,
            a10: v48,
            a11: v51);
    idStr::Append(this: &this->info, text: v25);
    idStr::operator=(this: &v55, text: "actual");
    idStr::operator=(this: &v54, text: "int");
    idStr::Format(this: &v53, fmt: "%d", this->numShotsFired);
    v26 = common->GetRegression(this: common);
    v27 = idStr::idStr(this: &v57, text: &v53);
    v28 = idStr::idStr(this: &v56, text: &v54);
    v29 = idStr::idStr(this: &v58, text: &v55);
    v30 = v26->GetTestReport(this: v26);
    idTestReport::AddTestReportField(this: v30, name: v29, type: v28, value: v27);
    HIDWORD(v31) = v53.data;
    v34 = va::va(
            this: &v59,
            fmt: " actual=<B>%s</B>",
            a3: v31,
            a4: v33,
            a5: v32,
            a6: v37,
            a7: v40,
            a8: v43,
            a9: v46,
            a10: v49,
            a11: v52);
    idStr::Append(this: &this->info, text: v34);
    idStr::Append(this: &this->info, text: " </TD>\n");
    idStr::Append(this: &this->info, text: "            </TR>\n");
    idStr::Append(this: &this->info, text: "          </TABLE>\n");
    this->ReportResults(this);
    idStr::FreeData(this: &v53);
    idStr::FreeData(this: &v54);
    idStr::FreeData(this: &v55);
  }
  idTarget_Test::OnActivate(this, activator);
}


// ========================================================================
// __unwind$489379_0
// EA  : 0x82CE97E0
// RVA : 0x00CE97E0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489379_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 160));
}


// ========================================================================
// __unwind$489380_0
// EA  : 0x82CE9808
// RVA : 0x00CE9808
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489380_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 128));
}


// ========================================================================
// __unwind$489381
// EA  : 0x82CE9830
// RVA : 0x00CE9830
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489381()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 96));
}


// ========================================================================
// __unwind$489382
// EA  : 0x82CE9858
// RVA : 0x00CE9858
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489382()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 80));
}


// ========================================================================
// __unwind$489383
// EA  : 0x82CE9880
// RVA : 0x00CE9880
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489383()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 84));
}


// ========================================================================
// __unwind$489384_0
// EA  : 0x82CE98A8
// RVA : 0x00CE98A8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489384_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 88));
}


// ========================================================================
// __unwind$489385
// EA  : 0x82CE98D0
// RVA : 0x00CE98D0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489385()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 88));
}


// ========================================================================
// __unwind$489386_0
// EA  : 0x82CE98F8
// RVA : 0x00CE98F8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489386_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 84));
}


// ========================================================================
// __unwind$489387_0
// EA  : 0x82CE9920
// RVA : 0x00CE9920
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489387_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 80));
}


// ========================================================================
// __unwind$489388_0
// EA  : 0x82CE9948
// RVA : 0x00CE9948
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489388_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 88));
}


// ========================================================================
// __unwind$489389_0
// EA  : 0x82CE9970
// RVA : 0x00CE9970
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489389_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 84));
}


// ========================================================================
// __unwind$489390_0
// EA  : 0x82CE9998
// RVA : 0x00CE9998
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489390_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4480 + 80));
}


// ========================================================================
// ??1idTarget_Test@@UAA@XZ
// EA  : 0x82CE99C8
// RVA : 0x00CE99C8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_Test::~idTarget_Test(idTarget_Test *this)
{
  int len; // r29
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r6
  int v6; // r5
  int v7; // r4

  this->__vftable = (idTarget_Test_vtbl *)&idTarget_Test::`vftable';
  if ( !this->activated && regressionTest.recordState != RECORD_NONE )
  {
    len = this->testComment.len;
    idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
    HIDWORD(v3) = this->info.data;
    LODWORD(v3) = 0;
    *(_BYTE *)(HIDWORD(v3) + len) = 0;
    this->info.len = len;
    idTarget_Test::ReportResults(this, a2: v7, a3: v6, a4: v5, a5: v4, a6: v3);
  }
  idRegressionTest::RemoveTest(this: &regressionTest, test: this);
  idStr::FreeData(this: &this->testComment);
  idStr::FreeData(this: &this->info);
  idStr::FreeData(this: &this->testType);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489653
// EA  : 0x82CE9A88
// RVA : 0x00CE9A88
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489653()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489654
// EA  : 0x82CE9AB0
// RVA : 0x00CE9AB0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489654()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$489655
// EA  : 0x82CE9ADC
// RVA : 0x00CE9ADC
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489655()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// __unwind$489656
// EA  : 0x82CE9B08
// RVA : 0x00CE9B08
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489656()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 872));
}


// ========================================================================
// ??0idTarget_TestActivation@@QAA@XZ
// EA  : 0x82CE9B38
// RVA : 0x00CE9B38
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestActivation *__fastcall idTarget_TestActivation::idTarget_TestActivation(idTarget_TestActivation *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "ACTIVATION");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->testShouldBeActivated = true;
  this->__vftable = (idTarget_TestActivation_vtbl *)&idTarget_TestActivation::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_TestScreenShot@@QAA@XZ
// EA  : 0x82CE9B98
// RVA : 0x00CE9B98
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestScreenShot *__fastcall idTarget_TestScreenShot::idTarget_TestScreenShot(idTarget_TestScreenShot *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "SCREENSHOT");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->__vftable = (idTarget_TestScreenShot_vtbl *)&idTarget_TestScreenShot::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_TestScreenCompare@@QAA@XZ
// EA  : 0x82CE9BF0
// RVA : 0x00CE9BF0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestScreenCompare *__fastcall idTarget_TestScreenCompare::idTarget_TestScreenCompare(
        idTarget_TestScreenCompare *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "SCREENSHOT <BR> COMPARISON");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->__vftable = (idTarget_TestScreenCompare_vtbl *)&idTarget_TestScreenCompare::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_TestExit@@QAA@XZ
// EA  : 0x82CE9C48
// RVA : 0x00CE9C48
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestExit *__fastcall idTarget_TestExit::idTarget_TestExit(idTarget_TestExit *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "EXIT");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->__vftable = (idTarget_TestExit_vtbl *)&idTarget_TestExit::`vftable';
  return this;
}


// ========================================================================
// ??0idTarget_TestEntity@@QAA@VidStr@@@Z
// EA  : 0x82CE9CA8
// RVA : 0x00CE9CA8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestEntity *__fastcall idTarget_TestEntity::idTarget_TestEntity(idTarget_TestEntity *this, idStr *_testType)
{
  idStr *v4; // r3
  idStr v6[2]; // [sp+60h] [-40h] BYREF

  v4 = idStr::idStr(this: v6, text: _testType);
  idTarget_Test::idTarget_Test(this, _testType: v4);
  this->__vftable = (idTarget_TestEntity_vtbl *)&idTarget_TestEntity::`vftable';
  this->testEntity.spawnId.value = 0x1FFF;
  idStr::FreeData(this: _testType);
  return this;
}


// ========================================================================
// __unwind$489766
// EA  : 0x82CE9D08
// RVA : 0x00CE9D08
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_489766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 160 + 188));
}


// ========================================================================
// ?GetEntity@idTarget_TestEntity@@IAAPAVidEntity@@PAV2@@Z
// EA  : 0x82CE9D30
// RVA : 0x00CE9D30
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idPlayer *__fastcall idTarget_TestEntity::GetEntity(idTarget_TestEntity *this, idEntity *activator)
{
  int value; // r10
  idEntity *v5; // r3
  int v7; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3
  int v10; // r9
  idEntity *v11; // r3

  value = this->testEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return (idPlayer *)activator;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr || idEntity::CastTo(c: v5) == nullptr )
    return (idPlayer *)activator;
  v7 = this->testEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
    v9 = idEntity::CastTo(c: v8);
  else
    v9 = nullptr;
  if ( (unsigned __int8)idPlayerStart::IsTypeOf(c: v9) != 0 )
    return idGameLocal::GetPlayer(this: gameLocal, i: 0);
  v10 = this->testEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
    return (idPlayer *)idEntity::CastTo(c: v11);
  else
    return nullptr;
}


// ========================================================================
// ??0idTarget_TestEntityBool@@QAA@XZ
// EA  : 0x82CE9E50
// RVA : 0x00CE9E50
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestEntityBool *__fastcall idTarget_TestEntityBool::idTarget_TestEntityBool(idTarget_TestEntityBool *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "ENTITY <BR> BOOL");
  idTarget_TestEntity::idTarget_TestEntity(this, _testType: v2);
  this->testBool = IS_DEAD;
  this->__vftable = (idTarget_TestEntityBool_vtbl *)&idTarget_TestEntityBool::`vftable';
  this->testValue = true;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_TestEntityBool@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE9EB8
// RVA : 0x00CE9EB8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestEntityBool::OnActivate(idTarget_TestEntityBool *this, idEntity *activator)
{
  idPlayer *Entity; // r3
  int len; // r30
  idPlayer *v6; // r28
  const char *v7; // r26
  bool v8; // r27
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r6
  va *v12; // r3
  testStatus_t v13; // r11
  int v14; // [sp+8h] [-1088h]
  int v15; // [sp+Ch] [-1084h]
  int v16; // [sp+10h] [-1080h]
  int v17; // [sp+14h] [-107Ch]
  int v18; // [sp+18h] [-1078h]
  int v19; // [sp+1Ch] [-1074h]
  va v20; // [sp+50h] [-1040h] BYREF

  if ( regressionTest.recordState != RECORD_NONE && !this->activated )
  {
    Entity = idTarget_TestEntity::GetEntity(this, activator);
    len = this->testComment.len;
    v6 = Entity;
    v7 = nullptr;
    v8 = false;
    idStr::EnsureAlloced(this: &this->info, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->info.data, Src: this->testComment.data, Size: len);
    this->info.data[len] = 0;
    this->info.len = len;
    LODWORD(v10) = this->testBool;
    if ( (_DWORD)v10 == 0 )
    {
      v8 = v6->IsDead(this: v6);
      v7 = "IsDead";
    }
    if ( this->testValue )
      LODWORD(v11) = "true";
    else
      LODWORD(v11) = "false";
    HIDWORD(v11) = v7;
    v12 = va::va(
            this: &v20,
            fmt: "%s=%s",
            a3: v11,
            a4: v9,
            a5: v10,
            a6: v14,
            a7: v15,
            a8: v16,
            a9: v17,
            a10: v18,
            a11: v19);
    idStr::Append(this: &this->info, text: v12);
    if ( v8 )
    {
      if ( !this->testValue )
      {
        v13 = TEST_FAIL;
LABEL_13:
        this->testStatus = v13;
        this->ReportResults(this);
        goto LABEL_14;
      }
    }
    else
    {
      v13 = TEST_FAIL;
      if ( this->testValue )
        goto LABEL_13;
    }
    v13 = TEST_PASS;
    goto LABEL_13;
  }
LABEL_14:
  idTarget_Test::OnActivate(this, activator);
}


// ========================================================================
// ??0idTarget_TestInstruction@@QAA@XZ
// EA  : 0x82CEA000
// RVA : 0x00CEA000
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestInstruction *__fastcall idTarget_TestInstruction::idTarget_TestInstruction(idTarget_TestInstruction *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "INSTRUCTION");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->displayTime = 3;
  this->__vftable = (idTarget_TestInstruction_vtbl *)&idTarget_TestInstruction::`vftable';
  this->testStatus = TEST_PASS;
  return this;
}


// ========================================================================
// ??0idTarget_TestOverrideStatus@@QAA@XZ
// EA  : 0x82CEA068
// RVA : 0x00CEA068
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestOverrideStatus *__fastcall idTarget_TestOverrideStatus::idTarget_TestOverrideStatus(
        idTarget_TestOverrideStatus *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "OVERRIDESTATUS");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->testStatus = TEST_SKIP;
  this->__vftable = (idTarget_TestOverrideStatus_vtbl *)&idTarget_TestOverrideStatus::`vftable';
  this->overrideStatus = TEST_SKIP;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_TestOverrideStatus@@MAAXPAVidEntity@@@Z
// EA  : 0x82CEA0C8
// RVA : 0x00CEA0C8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void __fastcall idTarget_TestOverrideStatus::OnActivate(idTarget_TestOverrideStatus *this, idEntity *activator)
{
  int v3; // r29
  int v4; // r30
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  _DWORD *v8; // r3

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->targets.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = _RTDynamicCast(
             inptr: v7,
             VfDelta: 0,
             SrcType: &idEntity `RTTI Type Descriptor',
             TargetType: &idTarget_Test `RTTI Type Descriptor',
             isReference: 0);
      if ( v8 != nullptr )
        v8[208] = this->overrideStatus;
      ++v3;
      ++v4;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// ??0idTarget_TestShotsFired@@QAA@XZ
// EA  : 0x82CEA190
// RVA : 0x00CEA190
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestShotsFired *__fastcall idTarget_TestShotsFired::idTarget_TestShotsFired(idTarget_TestShotsFired *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+50h] [-30h] BYREF

  v2 = idStr::idStr(this: &v4, text: "SHOTS FIRED");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->minNumShots = 1;
  this->__vftable = (idTarget_TestShotsFired_vtbl *)&idTarget_TestShotsFired::`vftable';
  this->maxNumShots = 1;
  this->numShotsFired = 0;
  return this;
}


// ========================================================================
// ??0idTarget_TestCommand@@QAA@XZ
// EA  : 0x82CEA2F0
// RVA : 0x00CEA2F0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

idTarget_TestCommand *__fastcall idTarget_TestCommand::idTarget_TestCommand(idTarget_TestCommand *this)
{
  idStr *v2; // r3
  idStr v4; // [sp+60h] [-40h] BYREF

  v2 = idStr::idStr(this: &v4, text: "CONSOLE <BR> COMMANDS");
  idTarget_Test::idTarget_Test(this, _testType: v2);
  this->__vftable = (idTarget_TestCommand_vtbl *)&idTarget_TestCommand::`vftable';
  this->testCommandLines.granularity = 0;
  this->testCommandLines.memTag = 5;
  this->testCommandLines.listStatic = 0;
  this->testCommandLines.list = nullptr;
  this->testCommandLines.size = 0;
  this->testCommandLines.num = 0;
  this->testActivateCount = 0;
  return this;
}


// ========================================================================
// __unwind$490208
// EA  : 0x82CEA37C
// RVA : 0x00CEA37C
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490208()
{
  int v0; // r12

  idTarget_Test::~idTarget_Test(this: *(idTarget_Test **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$490443_0
// EA  : 0x82CEA7C8
// RVA : 0x00CEA7C8
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490443_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 1008);
}


// ========================================================================
// __unwind$490444_0
// EA  : 0x82CEA7F0
// RVA : 0x00CEA7F0
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490444_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 1010);
}


// ========================================================================
// __unwind$490445_0
// EA  : 0x82CEA818
// RVA : 0x00CEA818
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490445_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 1011);
}


// ========================================================================
// __unwind$490446_0
// EA  : 0x82CEA840
// RVA : 0x00CEA840
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490446_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 1007);
}


// ========================================================================
// __unwind$490447_0
// EA  : 0x82CEA868
// RVA : 0x00CEA868
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490447_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 1009);
}


// ========================================================================
// __unwind$490449_0
// EA  : 0x82CEA890
// RVA : 0x00CEA890
// PDB : w:\tech5\tungsten\game\entities\testtarget.cpp
// ========================================================================

void _unwind_490449_0()
{
  idList<idStr,5> *v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: v0 + 2013);
}

