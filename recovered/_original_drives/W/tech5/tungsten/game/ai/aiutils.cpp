
// ========================================================================
// ?CalcDecelerationDistance@idAIUtils@@SAMMM@Z
// EA  : 0x82A60E58
// RVA : 0x00A60E58
// PDB : w:\tech5\tungsten\game\ai\aiutils.cpp
// ========================================================================

float __fastcall idAIUtils::CalcDecelerationDistance(double currentVel, double decelerationRate)
{
  double v2; // fp1

  if ( __fabs(decelerationRate) >= 0.0000099999997 )
    v2 = (float)((float)-(float)((float)currentVel * (float)currentVel) / (float)((float)decelerationRate * (float)2.0));
  else
    v2 = 0.0;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?CalcExactDecelerationRate@idAIUtils@@SAMMM@Z
// EA  : 0x82A60E98
// RVA : 0x00A60E98
// PDB : w:\tech5\tungsten\game\ai\aiutils.cpp
// ========================================================================

float __fastcall idAIUtils::CalcExactDecelerationRate(double currentVel, double distance)
{
  double v2; // fp1

  if ( __fabs(distance) > 0.0000099999997 )
    v2 = (float)((float)-(float)((float)currentVel * (float)currentVel) / (float)((float)distance * (float)2.0));
  else
    v2 = 0.0;
  return *((float *)&v2 + 1);
}


// ========================================================================
// `dynamic initializer for 'ai_showSearchPath''
// EA  : 0x83367BF8
// RVA : 0x01367BF8
// PDB : w:\tech5\tungsten\game\ai\aiutils.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showSearchPath__()
{
  idCVar::idCVar(
    this: &ai_showSearchPath,
    name: "ai_showSearchPath",
    value: "0",
    flags: 1,
    description: "shows the search path calculated by AIs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showSearchPath__);
}

