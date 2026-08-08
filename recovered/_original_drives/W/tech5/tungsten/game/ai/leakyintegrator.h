
// ========================================================================
// ?Update@?$idLeakyIntegrator@$0A@$00@@QAA_NHM@Z
// EA  : 0x829F5B68
// RVA : 0x009F5B68
// PDB : w:\tech5\tungsten\game\ai\leakyintegrator.h
// ========================================================================

BOOL __fastcall idLeakyIntegrator<0,1>::Update(idLeakyIntegrator<0,1> *this, const int curTimeMS, double seconds)
{
  double v4; // fp0
  BOOL result; // r3
  char v6; // r11

  if ( seconds > 0.0 )
  {
    v4 = (float)((float)(this->decayRate * (float)seconds) + this->value);
    this->value = (float)(this->decayRate * (float)seconds) + this->value;
    if ( v4 >= 0.0 )
    {
      if ( v4 > 1.0 )
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0;
    }
    this->value = v4;
  }
  if ( (*((_BYTE *)this + 12) & 0x80) != 0 )
    return true;
  v6 = ((this->value >= 1.0) << 7) | *((_BYTE *)this + 12) & 0x7F;
  result = (unsigned __int8)((this->value >= 1.0) << 7) != 0;
  *((_BYTE *)this + 12) = v6;
  return result;
}


// ========================================================================
// ?Update@?$idLeakyIntegrator@$0A@$00@@QAA_NH@Z
// EA  : 0x829FB9F8
// RVA : 0x009FB9F8
// PDB : w:\tech5\tungsten\game\ai\leakyintegrator.h
// ========================================================================

BOOL __fastcall idLeakyIntegrator<0,1>::Update(idLeakyIntegrator<0,1> *this, int curTimeMS, int a3, int a4, __int64 a5)
{
  LODWORD(a5) = curTimeMS - this->lastUpdateMS;
  this->lastUpdateMS = curTimeMS;
  return idLeakyIntegrator<0,1>::Update(this, curTimeMS, seconds: (float)((float)a5 * (float)0.001));
}


// ========================================================================
// ?AddStimulus@?$idLeakyIntegrator@$0A@$00@@QAA_NHM@Z
// EA  : 0x82AFA420
// RVA : 0x00AFA420
// PDB : w:\tech5\tungsten\game\ai\leakyintegrator.h
// ========================================================================

BOOL __fastcall idLeakyIntegrator<0,1>::AddStimulus(
        idLeakyIntegrator<0,1> *this,
        int curTimeMS,
        double stimulus,
        int a4,
        int a5,
        __int64 a6)
{
  double v8; // fp0
  char v9; // r11
  char v11; // r11

  LODWORD(a6) = curTimeMS - this->lastUpdateMS;
  this->lastUpdateMS = curTimeMS;
  idLeakyIntegrator<0,1>::Update(this, curTimeMS, seconds: (float)((float)a6 * (float)0.001));
  v8 = (float)(this->value + (float)stimulus);
  this->value = this->value + (float)stimulus;
  if ( v8 >= 0.0 )
  {
    if ( v8 > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = *((_BYTE *)this + 12);
  this->value = v8;
  if ( v9 < 0 )
    return true;
  v11 = ((v8 >= 1.0) << 7) | v9 & 0x7F;
  *((_BYTE *)this + 12) = v11;
  return v11 < 0;
}


// ========================================================================
// ?IsStillTriggered@?$idLeakyIntegrator@$0A@$00@@QAA_NXZ
// EA  : 0x82B44B48
// RVA : 0x00B44B48
// PDB : w:\tech5\tungsten\game\ai\leakyintegrator.h
// ========================================================================

int __fastcall idLeakyIntegrator<0,1>::IsStillTriggered(idLeakyIntegrator<0,1> *this)
{
  double v1; // fp0
  char v2; // r11
  unsigned __int8 v3; // r11

  v1 = (float)(this->decayRate + this->value);
  this->value = this->decayRate + this->value;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 1.0 )
      v1 = 1.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = *((_BYTE *)this + 12);
  this->value = v1;
  if ( (v2 & 0x80) == 0 || v1 > 0.0 )
    return *((unsigned __int8 *)this + 12) >> 7;
  v3 = v2 & 0x7F;
  *((_BYTE *)this + 12) = v3;
  return v3 >> 7;
}

