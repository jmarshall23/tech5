
// ========================================================================
// ?GetEndTimeByFrames@@YAHH@Z
// EA  : 0x82A42788
// RVA : 0x00A42788
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

int __fastcall GetEndTimeByFrames(int frameCount)
{
  int GameMs; // r31

  if ( frameCount <= 0 )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return gameLocal->GetGameMsPerRealSec(this: gameLocal) * frameCount / 30 + GameMs;
}


// ========================================================================
// ?GetRandomInterval@@YAHHH@Z
// EA  : 0x82A42810
// RVA : 0x00A42810
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

int __fastcall GetRandomInterval(int _min, const int _max)
{
  signed int v2; // r11
  unsigned int seed; // r8
  unsigned int v4; // r4
  int v5; // r9

  if ( _max > _min )
  {
    v2 = _max - _min;
    if ( _max != _min )
    {
      seed = clientGame->random.seed;
      __twllei(v2, 0);
      v4 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v4;
      v5 = (v4 >> 10) & 0x7FFF;
      __twlgei(v2 & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
      _min += v5 % v2;
    }
  }
  return _min;
}


// ========================================================================
// ?GetRandomInterval@@YAMMM@Z
// EA  : 0x82A42880
// RVA : 0x00A42880
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

float __fastcall GetRandomInterval(double _min, double _max)
{
  __int64 v2; // r11
  unsigned int v3; // r4

  if ( _max > _min )
  {
    HIDWORD(v2) = 1638400;
    v3 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v3;
    LODWORD(v2) = (v3 >> 10) & 0x7FFF;
    _min = (float)((float)((float)((float)v2 * (float)((float)_max - (float)_min)) * (float)0.000030518509) + (float)_min);
  }
  return *((float *)&_min + 1);
}


// ========================================================================
// ?GetRandomIntervalBySeconds@@YAHMM@Z
// EA  : 0x82A428E0
// RVA : 0x00A428E0
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

int __fastcall GetRandomIntervalBySeconds(double minSecs, double maxSecs)
{
  __int64 v2; // r9
  unsigned int v3; // r5
  double v4; // fp31
  __int64 v5; // r6

  HIDWORD(v2) = 1664525;
  v3 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v3 + 1013904223;
  LODWORD(v2) = ((v3 + 1013904223) >> 10) & 0x7FFF;
  v4 = (float)((float)((float)((float)v2 * (float)((float)maxSecs - (float)minSecs)) * (float)0.000030518509)
             + (float)minSecs);
  LODWORD(v5) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  return (int)(float)((float)v5 * (float)v4);
}


// ========================================================================
// ?RandomInt@@YAHH@Z
// EA  : 0x82A42990
// RVA : 0x00A42990
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

int __fastcall RandomInt(int max)
{
  unsigned int seed; // r9
  unsigned int v3; // r5
  int v4; // r4

  if ( max == 0 )
    return 0;
  seed = clientGame->random.seed;
  __twllei(max, 0);
  v3 = 1664525 * seed + 1013904223;
  clientGame->random.seed = v3;
  v4 = (v3 >> 10) & 0x7FFF;
  __twlgei(max & ~(__ROL4__(v4, 1) - 1), 0xFFFFFFFF);
  return v4 % max;
}


// ========================================================================
// ?RandomInt@@YAHHH@Z
// EA  : 0x82A429F0
// RVA : 0x00A429F0
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

int __fastcall RandomInt(int min, int max)
{
  signed int v2; // r6
  unsigned int v3; // r5
  signed int v4; // r10

  if ( min < max )
  {
    v2 = max - min + 1;
    v3 = 1664525 * clientGame->random.seed;
    __twllei(v2, 0);
    clientGame->random.seed = v3 + 1013904223;
    v4 = ((v3 + 1013904223) >> 10) & 0x7FFF;
    __twlgei(v2 & ~(__ROL4__(v4, 1) - 1), 0xFFFFFFFF);
    min += v4 % v2;
  }
  return min;
}


// ========================================================================
// ?RandomFloat@@YAMXZ
// EA  : 0x82A42A58
// RVA : 0x00A42A58
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

float __fastcall RandomFloat()
{
  __int64 v0; // r11
  unsigned int v1; // r4
  double v2; // fp1

  HIDWORD(v0) = 1638400;
  v1 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v1;
  LODWORD(v0) = (v1 >> 10) & 0x7FFF;
  v2 = (float)((float)v0 * (float)0.000030518509);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?RandomFloat@@YAMM@Z
// EA  : 0x82A42AA8
// RVA : 0x00A42AA8
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

float __fastcall RandomFloat(double max)
{
  __int64 v1; // r11
  unsigned int v2; // r4
  double v3; // fp1

  HIDWORD(v1) = 1638400;
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  LODWORD(v1) = (v2 >> 10) & 0x7FFF;
  v3 = (float)((float)((float)v1 * (float)max) * (float)0.000030518509);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?RandomFloat@@YAMMM@Z
// EA  : 0x82A42AF8
// RVA : 0x00A42AF8
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

float __fastcall RandomFloat(double min, double max)
{
  __int64 v2; // r11
  unsigned int v3; // r4
  double v4; // fp1

  HIDWORD(v2) = 1638400;
  v3 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v3;
  LODWORD(v2) = (v3 >> 10) & 0x7FFF;
  v4 = (float)((float)((float)((float)v2 * (float)((float)max - (float)min)) * (float)0.000030518509) + (float)min);
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?SecondsToTicks@@YA?AV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@M@Z
// EA  : 0x82A42B50
// RVA : 0x00A42B50
// PDB : w:\tech5\tungsten\game\ai\aidefs.cpp
// ========================================================================

idTypesafeNumber<int,enum gameTimeUnique_t> *__fastcall SecondsToTicks(
        idTypesafeNumber<int,enum gameTimeUnique_t> *result,
        double seconds)
{
  __int64 v4; // r8

  LODWORD(v4) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  result->value = (int)(float)((float)v4 * (float)seconds);
  return result;
}

