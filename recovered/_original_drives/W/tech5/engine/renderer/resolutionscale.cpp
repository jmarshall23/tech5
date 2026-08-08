
// ========================================================================
// ?InitForMap@idResolutionScale@@QAAXPBD@Z
// EA  : 0x829711C8
// RVA : 0x009711C8
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __fastcall idResolutionScale::InitForMap(idResolutionScale *this, const char *mapName)
{
  if ( idStr::Icmp(s1: mapName, s2: "maps/game/wasteland1/wellspring") != 0
    && idStr::Icmp(s1: mapName, s2: "maps/game/wasteland1/scientist") != 0
    && idStr::Icmp(s1: mapName, s2: "maps/game/wasteland1/bash_tv_entrance") != 0
    && idStr::Icmp(s1: mapName, s2: "maps/game/wasteland2/subway_town") != 0 )
  {
    this->dropMilliseconds = rs_dropMilliseconds.valueFloat;
    this->raiseMilliseconds = rs_raiseMilliseconds.valueFloat;
  }
  else
  {
    this->dropMilliseconds = 16.0;
    this->raiseMilliseconds = 15.0;
  }
}


// ========================================================================
// ?GetCurrentResolutionScale@idResolutionScale@@QAAXAAM0@Z
// EA  : 0x82971298
// RVA : 0x00971298
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __fastcall idResolutionScale::GetCurrentResolutionScale(idResolutionScale *this, float *x, float *y)
{
  double currentResolution; // fp0

  *x = 1.0;
  *y = 1.0;
  if ( rs_enable.valueInteger != 0 )
  {
    if ( rs_forceFractionX.valueFloat > 0.0 && rs_forceFractionX.valueFloat <= 1.0 )
      *x = rs_forceFractionX.valueFloat;
    if ( rs_forceFractionY.valueFloat > 0.0 && rs_forceFractionY.valueFloat <= 1.0 )
      *y = rs_forceFractionY.valueFloat;
    if ( rs_enable.valueInteger >= 2 && *x == 1.0 )
      currentResolution = this->currentResolution;
    else
      currentResolution = *x;
    *x = currentResolution;
    if ( (rs_enable.valueInteger & 1) != 0 && *y == 1.0 )
      *y = this->currentResolution;
    else
      *y = *y;
  }
}


// ========================================================================
// ?SetCurrentGPUFrameTime@idResolutionScale@@QAAXH@Z
// EA  : 0x82971360
// RVA : 0x00971360
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __fastcall idResolutionScale::SetCurrentGPUFrameTime(idResolutionScale *this, unsigned int microseconds)
{
  double currentResolution; // fp13
  double v3; // fp1
  double v4; // fp12
  int v5; // r11
  double v6; // fp12
  double v7; // fp11

  currentResolution = this->currentResolution;
  v3 = (float)((float)__SPAIR64__(&off_82040000, microseconds) * (float)0.001);
  if ( v3 <= this->dropMilliseconds )
  {
    if ( v3 >= this->raiseMilliseconds )
    {
      this->framesAboveRaise = 0;
    }
    else
    {
      v5 = this->framesAboveRaise + 1;
      this->framesAboveRaise = v5;
      if ( v5 >= rs_raiseFrames.valueInteger )
      {
        v6 = this->currentResolution;
        this->framesAboveRaise = 0;
        v7 = (float)(rs_raiseFraction.valueFloat + (float)v6);
        this->currentResolution = rs_raiseFraction.valueFloat + (float)v6;
        if ( v7 > 1.0 )
          this->currentResolution = 1.0;
      }
    }
  }
  else
  {
    v4 = (float)(this->currentResolution - rs_dropFraction.valueFloat);
    this->currentResolution = this->currentResolution - rs_dropFraction.valueFloat;
    if ( v4 < rs_minimumResolutionScale.valueFloat )
      this->currentResolution = rs_minimumResolutionScale.valueFloat;
  }
  if ( rs_showResolutionChanges.valueInteger > 1
    || rs_showResolutionChanges.valueInteger == 1 && this->currentResolution != currentResolution )
  {
    idLib::Printf(fmt: "GPU msec: %4.1f resolutionScale: %4.2f\n", v3, *(float *)(HIDWORD(v3) + 12));
  }
}


// ========================================================================
// ?LogMetrics@idResolutionScale@@QAAXXZ
// EA  : 0x82971490
// RVA : 0x00971490
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __fastcall idResolutionScale::LogMetrics(idResolutionScale *this)
{
  int v2; // r3
  bool v3; // r4
  bool v4; // r4
  float v5; // [sp+50h] [-20h] BYREF
  float v6[3]; // [sp+54h] [-1Ch] BYREF

  if ( com_logMetrics.valueInteger != 0 )
  {
    idResolutionScale::GetCurrentResolutionScale(this, x: &v5, y: v6);
    idGaugeMetric::Log(this: (idGaugeMetric *)(v2 + 16), x: v5, skipPush: v3);
    idGaugeMetric::Log(this: &this->resolutionScaleMetricY, x: v6[0], skipPush: v4);
  }
}


// ========================================================================
// ??0idResolutionScale@@QAA@XZ
// EA  : 0x82971500
// RVA : 0x00971500
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

idResolutionScale *__fastcall idResolutionScale::idResolutionScale(idResolutionScale *this)
{
  idStr v3; // [sp+50h] [-A0h] BYREF
  idStr v4; // [sp+70h] [-80h] BYREF
  idStr v5; // [sp+90h] [-60h] BYREF
  idStr v6; // [sp+B0h] [-40h] BYREF

  idStr::idStr(this: &v4, text: "horizontal resolution scaling");
  idStr::idStr(this: &v3, text: "resolutionScaleX");
  idGaugeMetric::idGaugeMetric(this: &this->resolutionScaleMetricX, _shortName: &v3, _description: &v4);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: &v4);
  idStr::idStr(this: &v6, text: "vertical resolution scaling");
  idStr::idStr(this: &v5, text: "resolutionScaleY");
  idGaugeMetric::idGaugeMetric(this: &this->resolutionScaleMetricY, _shortName: &v5, _description: &v6);
  idStr::FreeData(this: &v5);
  idStr::FreeData(this: &v6);
  this->framesAboveRaise = 0;
  this->dropMilliseconds = 15.0;
  this->raiseMilliseconds = 13.0;
  this->currentResolution = 1.0;
  return this;
}


// ========================================================================
// __unwind$229364
// EA  : 0x829715E8
// RVA : 0x009715E8
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229364()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$229365
// EA  : 0x82971610
// RVA : 0x00971610
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229365()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$229366
// EA  : 0x82971638
// RVA : 0x00971638
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229366()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 240 + 260) + 16));
}


// ========================================================================
// __unwind$229367
// EA  : 0x82971664
// RVA : 0x00971664
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 176));
}


// ========================================================================
// __unwind$229368
// EA  : 0x8297168C
// RVA : 0x0097168C
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229368()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$229369
// EA  : 0x829716B4
// RVA : 0x009716B4
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void _unwind_229369()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 240 + 260) + 120));
}


// ========================================================================
// ?GetConsoleText@idResolutionScale@@QAAXAAVidStr@@@Z
// EA  : 0x829716E0
// RVA : 0x009716E0
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __fastcall idResolutionScale::GetConsoleText(idResolutionScale *this, idStr *s)
{
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  double v6; // fp0
  double v7; // fp13
  va *v8; // r3
  const char *v9; // r4
  __int64 v10; // r6
  double v11; // fp12
  int v12; // [sp+8h] [-1068h]
  int v13; // [sp+Ch] [-1064h]
  int v14; // [sp+10h] [-1060h]
  int v15; // [sp+14h] [-105Ch]
  int v16; // [sp+18h] [-1058h]
  int v17; // [sp+1Ch] [-1054h]
  float v18; // [sp+50h] [-1020h] BYREF
  int v19; // [sp+54h] [-101Ch]
  float v20; // [sp+58h] [-1018h] BYREF
  int v21; // [sp+5Ch] [-1014h]
  va v22; // [sp+60h] [-1010h] BYREF

  if ( rs_enable.valueInteger != 0 )
  {
    idResolutionScale::GetCurrentResolutionScale(this, x: &v20, y: &v18);
    LODWORD(v5) = &rs_display;
    if ( rs_display.valueInteger <= 0 )
    {
      if ( HIDWORD(v3) == 3 )
      {
        LODWORD(v5) = "olor specular";
        v9 = "%2i%%h,%2i%%v";
        v19 = (int)(float)(v18 * (float)100.0);
        v21 = (int)(float)(v20 * (float)100.0);
        v10 = __PAIR64__(v21, v19);
      }
      else
      {
        if ( HIDWORD(v3) == 2 )
        {
          LODWORD(v10) = "h";
          v11 = (float)(v20 * (float)100.0);
        }
        else
        {
          LODWORD(v10) = "v";
          v11 = (float)(v18 * (float)100.0);
        }
        v19 = (int)v11;
        HIDWORD(v10) = (int)v11;
        v9 = "%2i%%%s";
      }
      v8 = va::va(this: &v22, fmt: v9, a3: v10, a4: v3, a5: v5, a6: v12, a7: v13, a8: v14, a9: v15, a10: v16, a11: v17);
    }
    else
    {
      LODWORD(v5) = "olor specular";
      v6 = (float)(v20 * (float)1280.0);
      v7 = (float)(v18 * (float)720.0);
      if ( HIDWORD(v3) == 1 )
      {
        v7 = 1.0;
      }
      else if ( HIDWORD(v3) == 2 )
      {
        v6 = 1.0;
      }
      v19 = (int)(float)((float)v6 * (float)v7);
      HIDWORD(v4) = v19;
      v8 = va::va(
             this: &v22,
             fmt: "rs-pixels %i",
             a3: v4,
             a4: v3,
             a5: v5,
             a6: v12,
             a7: v13,
             a8: v14,
             a9: v15,
             a10: v16,
             a11: v17);
    }
    idStr::operator=(this: s, text: v8);
  }
  else
  {
    idStr::operator=(this: s, text: "rs-off");
  }
}


// ========================================================================
// `dynamic initializer for 'resolutionScale''
// EA  : 0x8335E2C0
// RVA : 0x0135E2C0
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resolutionScale__()
{
  idResolutionScale::idResolutionScale(this: &resolutionScale);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resolutionScale__);
}


// ========================================================================
// `dynamic initializer for 'rs_enable''
// EA  : 0x8335E2F8
// RVA : 0x0135E2F8
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_enable__()
{
  idCVar::idCVar(
    this: &rs_enable,
    name: "rs_enable",
    value: "0",
    flags: 2,
    description: "Enable dynamic resolution scaling, 0 - off, 1 - vert only, 2 - horz only, 3 - both",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_enable__);
}


// ========================================================================
// `dynamic initializer for 'rs_minimumResolutionScale''
// EA  : 0x8335E350
// RVA : 0x0135E350
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_minimumResolutionScale__()
{
  idCVar::idCVar(
    this: &rs_minimumResolutionScale,
    name: "rs_minimumResolutionScale",
    value: "0.5",
    flags: 4,
    description: "Never go below this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_minimumResolutionScale__);
}


// ========================================================================
// `dynamic initializer for 'rs_forceFractionX''
// EA  : 0x8335E3A8
// RVA : 0x0135E3A8
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_forceFractionX__()
{
  idCVar::idCVar(
    this: &rs_forceFractionX,
    name: "rs_forceFractionX",
    value: "0",
    flags: 4,
    description: "Force a specific 0.0 to 1.0 horizontal resolution scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_forceFractionX__);
}


// ========================================================================
// `dynamic initializer for 'rs_forceFractionY''
// EA  : 0x8335E400
// RVA : 0x0135E400
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_forceFractionY__()
{
  idCVar::idCVar(
    this: &rs_forceFractionY,
    name: "rs_forceFractionY",
    value: "0",
    flags: 4,
    description: "Force a specific 0.0 to 1.0 vertical resolution scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_forceFractionY__);
}


// ========================================================================
// `dynamic initializer for 'rs_showResolutionChanges''
// EA  : 0x8335E458
// RVA : 0x0135E458
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_showResolutionChanges__()
{
  idCVar::idCVar(
    this: &rs_showResolutionChanges,
    name: "rs_showResolutionChanges",
    value: "0",
    flags: 2,
    description: "1 = Print whenever the resolution scale changes, 2 = always",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_showResolutionChanges__);
}


// ========================================================================
// `dynamic initializer for 'rs_dropMilliseconds''
// EA  : 0x8335E4B0
// RVA : 0x0135E4B0
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_dropMilliseconds__()
{
  idCVar::idCVar(
    this: &rs_dropMilliseconds,
    name: "rs_dropMilliseconds",
    value: "15.0",
    flags: 4,
    description: "Drop the resolution when GPU time exceeds this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_dropMilliseconds__);
}


// ========================================================================
// `dynamic initializer for 'rs_raiseMilliseconds''
// EA  : 0x8335E508
// RVA : 0x0135E508
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_raiseMilliseconds__()
{
  idCVar::idCVar(
    this: &rs_raiseMilliseconds,
    name: "rs_raiseMilliseconds",
    value: "13.0",
    flags: 4,
    description: "Raise the resolution when GPU time is below this for several frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_raiseMilliseconds__);
}


// ========================================================================
// `dynamic initializer for 'rs_dropFraction''
// EA  : 0x8335E560
// RVA : 0x0135E560
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_dropFraction__()
{
  idCVar::idCVar(
    this: &rs_dropFraction,
    name: "rs_dropFraction",
    value: "0.11",
    flags: 4,
    description: "Drop the resolution in increments of this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_dropFraction__);
}


// ========================================================================
// `dynamic initializer for 'rs_raiseFraction''
// EA  : 0x8335E5B8
// RVA : 0x0135E5B8
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_raiseFraction__()
{
  idCVar::idCVar(
    this: &rs_raiseFraction,
    name: "rs_raiseFraction",
    value: "0.06",
    flags: 4,
    description: "Raise the resolution in increments of this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_raiseFraction__);
}


// ========================================================================
// `dynamic initializer for 'rs_raiseFrames''
// EA  : 0x8335E610
// RVA : 0x0135E610
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_raiseFrames__()
{
  idCVar::idCVar(
    this: &rs_raiseFrames,
    name: "rs_raiseFrames",
    value: "5",
    flags: 2,
    description: "Require this many frames below rs_raiseMilliseconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_raiseFrames__);
}


// ========================================================================
// `dynamic initializer for 'rs_display''
// EA  : 0x8335E668
// RVA : 0x0135E668
// PDB : w:\tech5\engine\renderer\resolutionscale.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rs_display__()
{
  idCVar::idCVar(
    this: &rs_display,
    name: "rs_display",
    value: "0",
    flags: 2,
    description: "0 - percentages, 1 - pixels per frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rs_display__);
}

