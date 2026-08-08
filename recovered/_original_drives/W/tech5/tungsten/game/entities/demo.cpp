
// ========================================================================
// ?OnActivate@mgFunc_StopDemo@@UAAXPAVidEntity@@@Z
// EA  : 0x82C1F9D8
// RVA : 0x00C1F9D8
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_StopDemo::OnActivate(mgFunc_StopDemo *this, idEntity *activator)
{
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "demostop\n");
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect\n");
}


// ========================================================================
// ?StartCapture@mgFunc_CaptureFrames@@AAAXPBD@Z
// EA  : 0x82C1FA38
// RVA : 0x00C1FA38
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_CaptureFrames::StartCapture(mgFunc_CaptureFrames *this, const char *capturePath)
{
  bool v4; // r3
  BOOL preview; // r11
  int width; // r5
  int height; // r27
  int v8; // r5

  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "g_skipViewEffects", a3: 1, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedTic", a3: 1, a4: 0);
  gameLocal->GetGameTimeManager(this: gameLocal);
  idGameTimeManager::SetGameHz(hz: this->framerate);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_skipModelCPUCulling", a3: 1, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_skipModelGPUCulling", a3: 1, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "r_postProcessHQ", a3: true, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_capturePrimes", a3: 2, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "ai_debugLevel", a3: 0, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_noPrint", a3: true, a4: 0);
  this->oldWidth = cvarSystem->GetCVarInteger(this: cvarSystem, a2: "r_windowWidth", a3: 0);
  this->oldHeight = cvarSystem->GetCVarInteger(this: cvarSystem, a2: "r_windowheight", a3: 0);
  v4 = cvarSystem->GetCVarBool(this: cvarSystem, a2: "r_fullscreen", a3: false);
  preview = this->preview;
  this->oldFullscreen = v4;
  if ( preview )
    width = this->width / 2;
  else
    width = this->width;
  if ( preview )
    height = this->height / 2;
  else
    height = this->height;
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowWidth", a3: width, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowHeight", a3: height, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "r_fullscreen", a3: false, a4: 0);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "vid_restart");
  idCVar::SetInteger(this: &com_captureFrames, newValue: 2, force: true);
  idCVar::SetInteger(this: &com_captureSounds, newValue: 0, force: true);
  if ( this->preview )
    v8 = 0;
  else
    v8 = ((_cntlzw(this->usePNG) & 0x20) == 0) + 1;
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureTGA", a3: v8, a4: 0);
  cvarSystem->SetCVarString(this: cvarSystem, a2: "com_capturePath", a3: capturePath, a4: 0);
}


// ========================================================================
// ?StopCapture@mgFunc_CaptureFrames@@AAAXXZ
// EA  : 0x82C1FD60
// RVA : 0x00C1FD60
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_CaptureFrames::StopCapture(mgFunc_CaptureFrames *this)
{
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "g_skipViewEffects", a3: 0, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedTic", a3: 0, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_noPrint", a3: false, a4: 0);
  idCVar::SetInteger(this: &com_captureFrames, newValue: 0, force: true);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_skipModelCPUCulling", a3: 0, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_skipModelGPUCulling", a3: 0, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowWidth", a3: this->oldWidth, a4: 0);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "r_windowHeight", a3: this->oldHeight, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "r_fullscreen", a3: this->oldFullscreen, a4: 0);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "vid_restart");
}


// ========================================================================
// ??0mgFunc_RecordDemo@@QAA@XZ
// EA  : 0x82C1FEF0
// RVA : 0x00C1FEF0
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

mgFunc_RecordDemo *__fastcall mgFunc_RecordDemo::mgFunc_RecordDemo(mgFunc_RecordDemo *this)
{
  idEntity::idEntity(this);
  this->__vftable = (mgFunc_RecordDemo_vtbl *)&mgFunc_RecordDemo::`vftable';
  this->demoName.len = 0;
  this->demoName.data = this->demoName.baseBuffer;
  this->demoName.allocedAndFlag = 20;
  this->demoName.baseBuffer[0] = 0;
  idStr::operator=(this: &this->demoName, text: "demo");
  return this;
}


// ========================================================================
// __unwind$487664
// EA  : 0x82C1FF6C
// RVA : 0x00C1FF6C
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487664()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487665
// EA  : 0x82C1FF94
// RVA : 0x00C1FF94
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// ?OnActivate@mgFunc_RecordDemo@@UAAXPAVidEntity@@@Z
// EA  : 0x82C20038
// RVA : 0x00C20038
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_RecordDemo::OnActivate(
        mgFunc_RecordDemo *this,
        idEntity *activator,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  va *v5; // r3
  int v6; // [sp+8h] [-1058h]
  int v7; // [sp+Ch] [-1054h]
  int v8; // [sp+10h] [-1050h]
  int v9; // [sp+14h] [-104Ch]
  int v10; // [sp+18h] [-1048h]
  int v11; // [sp+1Ch] [-1044h]
  va v12; // [sp+50h] [-1010h] BYREF

  HIDWORD(a3) = this->demoName.data;
  v5 = va::va(this: &v12, fmt: "demorecord %s\n", a3, a4, a5, a6: v6, a7: v7, a8: v8, a9: v9, a10: v10, a11: v11);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v5->buffer);
}


// ========================================================================
// ??0mgFunc_CaptureDemo@@QAA@XZ
// EA  : 0x82C20090
// RVA : 0x00C20090
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

mgFunc_CaptureDemo *__fastcall mgFunc_CaptureDemo::mgFunc_CaptureDemo(mgFunc_CaptureDemo *this)
{
  idEntity::idEntity(this);
  this->__vftable = (mgFunc_CaptureDemo_vtbl *)&mgFunc_CaptureDemo::`vftable';
  this->demoName.len = 0;
  this->demoName.data = this->demoName.baseBuffer;
  this->demoName.allocedAndFlag = 20;
  this->demoName.baseBuffer[0] = 0;
  this->outputName.allocedAndFlag = 20;
  this->outputName.len = 0;
  this->outputName.data = this->outputName.baseBuffer;
  this->outputName.baseBuffer[0] = 0;
  this->extraParam.allocedAndFlag = 20;
  this->extraParam.len = 0;
  this->extraParam.data = this->extraParam.baseBuffer;
  this->extraParam.baseBuffer[0] = 0;
  idStr::operator=(this: &this->demoName, text: "demo");
  idStr::operator=(this: &this->outputName, text: "capture");
  idStr::operator=(this: &this->extraParam, text: &byte_8200D768);
  this->framerate = 30;
  return this;
}


// ========================================================================
// __unwind$487950
// EA  : 0x82C20154
// RVA : 0x00C20154
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487950()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487951
// EA  : 0x82C2017C
// RVA : 0x00C2017C
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487951()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$487952
// EA  : 0x82C201A8
// RVA : 0x00C201A8
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487952()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// __unwind$487953
// EA  : 0x82C201D4
// RVA : 0x00C201D4
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_487953()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 864));
}


// ========================================================================
// ?OnActivate@mgFunc_CaptureDemo@@UAAXPAVidEntity@@@Z
// EA  : 0x82C202E0
// RVA : 0x00C202E0
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_CaptureDemo::OnActivate(mgFunc_CaptureDemo *this, idEntity *activator)
{
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  va *v7; // r3
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  va v14; // [sp+60h] [-1020h] BYREF

  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "g_skipViewEffects", a3: 1, a4: 0);
  LODWORD(v3) = this->framerate;
  ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: "com_demoPlaybackRate",
    a3: (float)((float)960.0 / (float)v3));
  LODWORD(v4) = &unk_822D0000;
  HIDWORD(v4) = this->extraParam.data;
  LODWORD(v5) = this->outputName.data;
  HIDWORD(v5) = this->demoName.data;
  v7 = va::va(
         this: &v14,
         fmt: "demoCaptureFrames demos/%s %s %s\n",
         a3: v5,
         a4: v4,
         a5: v6,
         a6: v8,
         a7: v9,
         a8: v10,
         a9: v11,
         a10: v12,
         a11: v13);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v7->buffer);
}


// ========================================================================
// ??0mgFunc_CaptureFrames@@QAA@XZ
// EA  : 0x82C203C0
// RVA : 0x00C203C0
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

mgFunc_CaptureFrames *__fastcall mgFunc_CaptureFrames::mgFunc_CaptureFrames(mgFunc_CaptureFrames *this)
{
  idEntity::idEntity(this);
  this->__vftable = (mgFunc_CaptureFrames_vtbl *)&mgFunc_CaptureFrames::`vftable';
  this->outputName.len = 0;
  this->outputName.data = this->outputName.baseBuffer;
  this->outputName.allocedAndFlag = 20;
  this->outputName.baseBuffer[0] = 0;
  idStr::operator=(this: &this->outputName, text: "capture");
  this->preview = false;
  this->usePNG = false;
  this->framerate = 30;
  this->width = 1280;
  this->height = 720;
  this->oldFullscreen = false;
  this->oldWidth = -1;
  this->oldHeight = -1;
  return this;
}


// ========================================================================
// __unwind$488117_0
// EA  : 0x82C20454
// RVA : 0x00C20454
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_488117_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488118_0
// EA  : 0x82C2047C
// RVA : 0x00C2047C
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_488118_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// ?Event_Deactivate@mgFunc_CaptureFrames@@QAA?AVeventVoid@@XZ
// EA  : 0x82C204A8
// RVA : 0x00C204A8
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

mgFunc_CaptureFrames *__fastcall mgFunc_CaptureFrames::Event_Deactivate(
        mgFunc_CaptureFrames *this,
        mgFunc_CaptureFrames *result)
{
  if ( (-result->oldWidth & ~result->oldWidth) < 0 )
  {
    mgFunc_CaptureFrames::StopCapture(this: result);
    result->oldWidth = -1;
  }
  return this;
}


// ========================================================================
// ?OnActivate@mgFunc_CaptureFrames@@UAAXPAVidEntity@@@Z
// EA  : 0x82C20570
// RVA : 0x00C20570
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __fastcall mgFunc_CaptureFrames::OnActivate(mgFunc_CaptureFrames *this, idEntity *activator)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  if ( demo_disableCapture.valueInteger == 0 && com_captureFrames.valueInteger == 0 )
  {
    idStr::idStr(this: &v3, text: &this->outputName);
    idStr::StripFileExtension(this: &v3);
    idStr::Append(this: &v3, text: "/frames/");
    mgFunc_CaptureFrames::StartCapture(this, capturePath: v3.data);
    idStr::FreeData(this: &v3);
  }
}


// ========================================================================
// __unwind$488274
// EA  : 0x82C20604
// RVA : 0x00C20604
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void _unwind_488274()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// `dynamic initializer for 'demo_disableCapture''
// EA  : 0x83375C60
// RVA : 0x01375C60
// PDB : w:\tech5\tungsten\game\entities\demo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__demo_disableCapture__()
{
  idCVar::idCVar(
    this: &demo_disableCapture,
    name: "demo_disableCapture",
    value: "0",
    flags: 1,
    description: "Set to 1 to disable capturing via 'func/demo/capture' objects.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__demo_disableCapture__);
}

