
// ========================================================================
// ?UpdateGameFrame@idGameTimeManager@@QAAXXZ
// EA  : 0x826780D8
// RVA : 0x006780D8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::UpdateGameFrame(idGameTimeManager *this)
{
  ++this->framenum;
}


// ========================================================================
// ?Count@idAccolade@@QBAHXZ
// EA  : 0x826780E8
// RVA : 0x006780E8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

int __fastcall idAccolade::Count(idGameTimeManager *this)
{
  return this->framenum;
}


// ========================================================================
// ?SetTimeScale@idGameTimeManager@@QAAXMW4gameTimeType_t@@@Z
// EA  : 0x826780F0
// RVA : 0x006780F0
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::SetTimeScale(
        idGameTimeManager *this,
        double scale,
        const gameTimeType_t type,
        int a4)
{
  this->useInterpolator = false;
  this->scale[a4] = scale;
  *((_BYTE *)this + 116) = ((scale < 1.0) << 7) | *((_BYTE *)this + 116) & 0x7F;
}


// ========================================================================
// ?UpdateGameMs@idGameTimeManager@@QAAXXZ
// EA  : 0x82678128
// RVA : 0x00678128
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::UpdateGameMs(idGameTimeManager *this)
{
  int v1; // r11
  int v2; // r10
  int v3; // r8
  int v4; // r7

  v1 = this->time[0];
  v2 = this->time[1];
  v3 = this->ticks[0] + v1;
  v4 = this->ticks[1] + v2;
  this->previousTime[0] = v1;
  this->time[0] = v3;
  this->previousTime[1] = v2;
  this->time[1] = v4;
}


// ========================================================================
// ?SetGameHz@idGameTimeManager@@SAXH@Z
// EA  : 0x82678158
// RVA : 0x00678158
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::SetGameHz(int hz)
{
  idTimeManager::SetGameHz(this: &timeManager, hertz: hz);
}


// ========================================================================
// ?GetGameMs@idGameTimeManager@@QBAHW4gameTimeType_t@@@Z
// EA  : 0x82678168
// RVA : 0x00678168
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

int __fastcall idGameTimeManager::GetGameMs(idGameTimeManager *this, gameTimeType_t type)
{
  if ( g_enableGameTimeScaling.valueInteger != 0 )
    return this->time[type];
  else
    return this->time[0];
}


// ========================================================================
// ?GetPreviousGameMs@idGameTimeManager@@QBAHW4gameTimeType_t@@@Z
// EA  : 0x82678198
// RVA : 0x00678198
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

int __fastcall idGameTimeManager::GetPreviousGameMs(idGameTimeManager *this, gameTimeType_t type)
{
  if ( g_enableGameTimeScaling.valueInteger != 0 )
    return this->previousTime[type];
  else
    return this->previousTime[0];
}


// ========================================================================
// ?GetGameMsPerFrame@idGameTimeManager@@QBAHW4gameTimeType_t@@@Z
// EA  : 0x826781C8
// RVA : 0x006781C8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

int __fastcall idGameTimeManager::GetGameMsPerFrame(idGameTimeManager *this, gameTimeType_t type)
{
  if ( g_enableGameTimeScaling.valueInteger != 0 )
    return this->ticks[type];
  else
    return this->ticks[0];
}


// ========================================================================
// ?GetRealMsPerFrame@idGameTimeManager@@QBAMW4gameTimeType_t@@@Z
// EA  : 0x826781F8
// RVA : 0x006781F8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

float __fastcall idGameTimeManager::GetRealMsPerFrame(idGameTimeManager *this, gameTimeType_t type)
{
  double v2; // fp1

  if ( g_enableGameTimeScaling.valueInteger != 0 )
    v2 = this->timeDelta[type];
  else
    v2 = this->timeDelta[0];
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetGameHz@idGameTimeManager@@QBAHW4gameTimeType_t@@@Z
// EA  : 0x82678228
// RVA : 0x00678228
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

int __fastcall idGameTimeManager::GetGameHz(idGameTimeManager *this, gameTimeType_t type)
{
  if ( g_enableGameTimeScaling.valueInteger != 0 )
    return this->hz[type];
  else
    return this->hz[0];
}


// ========================================================================
// ?GetTimeScale@idGameTimeManager@@QBAMW4gameTimeType_t@@@Z
// EA  : 0x82678258
// RVA : 0x00678258
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

float __fastcall idGameTimeManager::GetTimeScale(idGameTimeManager *this, gameTimeType_t type)
{
  double v2; // fp1

  if ( g_enableGameTimeScaling.valueInteger != 0 )
    v2 = this->scale[type];
  else
    v2 = this->scale[0];
  return *((float *)&v2 + 1);
}


// ========================================================================
// ??0idGameTimeManager@@QAA@XZ
// EA  : 0x82678318
// RVA : 0x00678318
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

idGameTimeManager *__fastcall idGameTimeManager::idGameTimeManager(idGameTimeManager *this)
{
  idInterpolate<float> *timeScaleExtrapolation; // r11
  int v2; // r10
  double currentValue; // fp13
  float *v4; // r11
  __int64 v5; // r8
  int v6; // ctr

  timeScaleExtrapolation = this->timeScaleExtrapolation;
  this->framenum = 0;
  v2 = 1;
  do
  {
    timeScaleExtrapolation->duration = 0.0;
    timeScaleExtrapolation->startTime = 0.0;
    --v2;
    timeScaleExtrapolation->currentTime = 0.0;
    timeScaleExtrapolation->currentValue = 0.0;
    currentValue = timeScaleExtrapolation->currentValue;
    timeScaleExtrapolation->endValue = timeScaleExtrapolation->currentValue;
    timeScaleExtrapolation->startValue = currentValue;
    ++timeScaleExtrapolation;
  }
  while ( v2 >= 0 );
  this->slowmoParms.easeInDuration = 0.0;
  this->slowmoParms.slowmoDuration = 0.0;
  this->slowmoParms.easeOutDuration = 0.0;
  v4 = (float *)&this->previousTime[1];
  this->slowmoParms.timeScale = 1.0;
  HIDWORD(v5) = *((unsigned __int8 *)this + 116);
  v6 = 2;
  this->slowmoDuration = 0.0;
  *((_BYTE *)this + 116) = BYTE3(v5) & 0x7F;
  this->useInterpolator = false;
  do
  {
    *(v4 - 9) = *(float *)&timeManager.gameHz;
    *(v4 - 7) = *(float *)&timeManager.gameTimePerFrame.value;
    LODWORD(v5) = timeManager.gameHz;
    *(v4 - 3) = 0.0;
    *(v4 - 1) = 0.0;
    *(v4 - 5) = (float)1000.0 / (float)v5;
    *++v4 = 1.0;
    --v6;
  }
  while ( v6 != 0 );
  return this;
}


// ========================================================================
// ?SetGameMs@idGameTimeManager@@QAAXH@Z
// EA  : 0x826783E8
// RVA : 0x006783E8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::SetGameMs(idGameTimeManager *this, int newtime)
{
  int value; // r11

  value = timeManager.gameTimePerFrame.value;
  this->time[0] = newtime;
  this->previousTime[0] = newtime - value;
  this->previousTime[1] = newtime - value;
  this->time[1] = this->time[0];
}


// ========================================================================
// ?StartSlowmotion@idGameTimeManager@@QAAXABUslowmoParms_t@@@Z
// EA  : 0x82678418
// RVA : 0x00678418
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::StartSlowmotion(idGameTimeManager *this, const slowmoParms_t *slowmoParms)
{
  int v4; // r30
  char v5; // r9
  __int64 v6; // r11
  double v7; // fp31
  double v8; // fp29
  double easeInDuration; // fp30
  idInterpolate<float> *v10; // r31
  __int64 v11; // r10
  double CurrentValue; // fp1
  double timeScale; // fp13

  if ( g_enableGameTimeScaling.valueInteger != 0 )
  {
    v4 = 1;
    v5 = *((_BYTE *)this + 116) | 0x80;
    this->useInterpolator = true;
    HIDWORD(v6) = 0x82000000;
    *((_BYTE *)this + 116) = v5;
    this->slowmoParms = *slowmoParms;
    this->slowmoDuration = slowmoParms->slowmoDuration;
    LODWORD(v6) = this->time[0];
    v7 = (float)v6;
    v8 = (float)((float)v6 - (float)1.0);
    do
    {
      easeInDuration = slowmoParms->easeInDuration;
      v10 = &this->timeScaleExtrapolation[v4];
      CurrentValue = idInterpolate<float>::GetCurrentValue(this: v10, time: v7);
      if ( v4 == 1 )
        timeScale = slowmoParms->timeScale;
      else
        timeScale = 1.0;
      ++v4;
      v10->endValue = timeScale;
      v10->startTime = v7;
      v10->startValue = CurrentValue;
      v10->currentTime = v8;
      v10->currentValue = CurrentValue;
      LODWORD(v11) = (int)(float)(1000.0 * (float)easeInDuration);
      v10->duration = (float)v11;
    }
    while ( v4 < 2 );
  }
}


// ========================================================================
// ?StopSlowmotion@idGameTimeManager@@QAAXXZ
// EA  : 0x82678548
// RVA : 0x00678548
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::StopSlowmotion(idGameTimeManager *this)
{
  double easeOutDuration; // fp30
  __int64 v3; // r11
  double v4; // fp29
  double CurrentValue; // fp1
  __int64 v6; // r7

  if ( (*((_BYTE *)this + 116) & 0x80) != 0 && g_enableGameTimeScaling.valueInteger != 0 )
  {
    easeOutDuration = this->slowmoParms.easeOutDuration;
    *((_BYTE *)this + 116) &= ~0x80u;
    this->useInterpolator = false;
    HIDWORD(v3) = 0x82000000;
    this->slowmoDuration = 0.0;
    LODWORD(v3) = this->time[0];
    this->scale[1] = 1.0;
    v4 = (float)v3;
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->timeScaleExtrapolation[1], time: v4);
    this->timeScaleExtrapolation[1].startTime = v4;
    this->timeScaleExtrapolation[1].startValue = CurrentValue;
    this->timeScaleExtrapolation[1].endValue = 1.0;
    this->timeScaleExtrapolation[1].currentTime = (float)v4 - (float)1.0;
    this->timeScaleExtrapolation[1].currentValue = CurrentValue;
    LODWORD(v6) = (int)(float)((float)1000.0 * (float)easeOutDuration);
    this->timeScaleExtrapolation[1].duration = (float)v6;
  }
}


// ========================================================================
// ?UpdateTimeScale@idGameTimeManager@@QAAXXZ
// EA  : 0x82678650
// RVA : 0x00678650
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __fastcall idGameTimeManager::UpdateTimeScale(idGameTimeManager *this, int a2, __int64 a3)
{
  int v3; // r30
  int *hz; // r29
  int value; // r10
  double v7; // fp30
  __int64 v8; // r11
  double v9; // fp31
  __int64 v10; // r11
  double v11; // fp12
  double v12; // fp13

  v3 = this->time[0];
  hz = this->hz;
  LODWORD(a3) = timeManager.gameHz;
  value = timeManager.gameTimePerFrame.value;
  this->hz[0] = timeManager.gameHz;
  v7 = (float)a3;
  this->ticks[0] = value;
  this->timeDelta[0] = (float)1000.0 / (float)a3;
  LODWORD(v8) = value;
  HIDWORD(v8) = this->useInterpolator;
  v9 = (float)v8;
  if ( this->useInterpolator )
  {
    LODWORD(v8) = v3;
    this->scale[1] = idInterpolate<float>::GetCurrentValue(this: &this->timeScaleExtrapolation[1], time: (float)v8);
  }
  HIDWORD(v10) = 4;
  v11 = (float)(this->scale[1] * (float)v7);
  this->ticks[1] = (int)(float)(this->scale[1] * (float)v9);
  hz[1] = (int)v11;
  this->timeDelta[1] = (float)1000.0 / (float)v11;
  if ( this->slowmoDuration > 0.0 )
  {
    LODWORD(v10) = v3;
    if ( (float)v10 >= (double)(float)(this->timeScaleExtrapolation[1].duration
                                     + this->timeScaleExtrapolation[1].startTime) )
    {
      v12 = (float)-(float)((float)((float)v9 * (float)0.001) - this->slowmoDuration);
      this->slowmoDuration = -(float)((float)((float)v9 * (float)0.001) - this->slowmoDuration);
      if ( v12 <= 0.0 )
      {
        this->slowmoDuration = 0.0;
        idGameTimeManager::StopSlowmotion(this);
      }
    }
  }
}


// ========================================================================
// ?ConvertTimeGameToReal@idGameTimeManager@@QBA?BV?$idTypesafeNumber@HW4millisecondUnique_t@@@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826787B8
// RVA : 0x006787B8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

idGameTimeManager *__fastcall idGameTimeManager::ConvertTimeGameToReal(
        idGameTimeManager *this,
        const idTypesafeNumber<int,enum millisecondUnique_t> *result,
        idTypesafeNumber<int,enum gameTimeUnique_t> *ticks)
{
  int v3; // r8
  int v4; // r5
  unsigned int v5; // r4

  v3 = 1000 * ticks->value;
  v4 = v3 / (timeManager.gameTimePerFrame.value * timeManager.gameHz);
  v5 = (timeManager.gameTimePerFrame.value * timeManager.gameHz) & ~(__ROL4__(v3, 1) - 1);
  __twllei(timeManager.gameTimePerFrame.value * timeManager.gameHz, 0);
  this->framenum = v4;
  __twlgei(v5, 0xFFFFFFFF);
  return this;
}


// ========================================================================
// ?ConvertTimeRealToGame@idGameTimeManager@@QBA?BV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@V?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA  : 0x826787F8
// RVA : 0x006787F8
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

idGameTimeManager *__fastcall idGameTimeManager::ConvertTimeRealToGame(
        idGameTimeManager *this,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *result,
        idTypesafeNumber<int,enum millisecondUnique_t> *ms)
{
  this->framenum = ms->value * timeManager.gameTimePerFrame.value * timeManager.gameHz / 1000;
  return this;
}


// ========================================================================
// ?Clear@idGameTimeManager@@QAAXXZ
// EA  : 0x82678828
// RVA : 0x00678828
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameTimeManager::Clear(idGameTimeManager *this, int a2)
{
  __int64 v2; // r7 OVERLAPPED
  void *v3; // r5 OVERLAPPED
  int v4; // ctr
  float *v5; // r11
  float *v6; // r10

  *((_BYTE *)this + 116) &= ~0x80u;
  HIDWORD(v2) = 0x82000000;
  v3 = &unk_82150000;
  v4 = 2;
  this->slowmoDuration = 0.0;
  this->useInterpolator = false;
  v5 = (float *)&this->previousTime[1];
  v6 = &this->scale[1];
  do
  {
    *(v5 - 9) = *(float *)&timeManager.gameHz;
    *(v5 - 7) = *(float *)&timeManager.gameTimePerFrame.value;
    LODWORD(v2) = timeManager.gameHz;
    *(v5 - 3) = 0.0;
    *(v5 - 1) = 0.0;
    *(v5 - 5) = (float)1000.0 / (float)v2;
    *++v5 = 1.0;
    v6[1] = 0.0;
    v6[2] = 0.0;
    v6[3] = 1.0;
    v6[4] = 1.0;
    v6[5] = -1.0;
    v6 += 6;
    *v6 = 1.0;
    --v4;
  }
  while ( v4 != 0 );
  idGameTimeManager::UpdateTimeScale(this, a2, a3: *(__int64 *)((char *)&v2 + 4));
}


// ========================================================================
// `dynamic initializer for 'g_enableGameTimeScaling''
// EA  : 0x8333B888
// RVA : 0x0133B888
// PDB : w:\tech5\engine\framework\gametimemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_enableGameTimeScaling__()
{
  idCVar::idCVar(
    this: &g_enableGameTimeScaling,
    name: "g_enableGameTimeScaling",
    value: "1",
    flags: 1,
    description: "Enables or Disables Scaling of Game Time via the GameTimeManager-Turning this off disables slow motion throughout the game",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_enableGameTimeScaling__);
}

