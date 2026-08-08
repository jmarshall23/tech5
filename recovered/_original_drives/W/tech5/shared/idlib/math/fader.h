
// ========================================================================
// ?GetLinear@idFader@@ABAMH@Z
// EA  : 0x826C92A0
// RVA : 0x006C92A0
// PDB : w:\tech5\shared\idlib\math\fader.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idFader::GetLinear(idFader *this, int time, int a3, int a4, int a5, _BYTE a6[12])
{
  int startTime; // r11
  double endValue; // fp1

  startTime = this->startTime;
  if ( time >= startTime )
  {
    *(_DWORD *)&a6[8] = this->duration;
    if ( time < *(_DWORD *)&a6[8] + startTime )
    {
      *(_DWORD *)&a6[4] = time - startTime;
      endValue = (float)((float)((float)((float)*(__int64 *)a6 / (float)*(__int64 *)&a6[4])
                               * (float)(this->endValue - this->startValue))
                       + this->startValue);
    }
    else
    {
      endValue = this->endValue;
    }
  }
  else
  {
    endValue = this->startValue;
  }
  return *((float *)&endValue + 1);
}


// ========================================================================
// ?GetSine@idFader@@ABAMH@Z
// EA  : 0x826C9310
// RVA : 0x006C9310
// PDB : w:\tech5\shared\idlib\math\fader.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idFader::GetSine(idFader *this, int time, long double a3, int a4, int a5, int a6, int a7, __int64 a8)
{
  int startTime; // r11
  double endValue; // fp1
  long double v10; // fp2

  startTime = this->startTime;
  if ( time >= startTime )
  {
    LODWORD(a8) = this->duration;
    if ( time < (int)a8 + startTime )
    {
      HIDWORD(a8) = time - startTime;
      *(double *)&a3 = (float)((float)((float)((float)*(__int64 *)((char *)&a8 + 4) / (float)a8) * (float)3.1415927)
                             * (float)0.5);
      v10 = sin(x: a3);
      endValue = (float)*(double *)&v10;
    }
    else
    {
      endValue = this->endValue;
    }
  }
  else
  {
    endValue = this->startValue;
  }
  return *((float *)&endValue + 1);
}


// ========================================================================
// ?GetInverseSine@idFader@@ABAMH@Z
// EA  : 0x826C93C0
// RVA : 0x006C93C0
// PDB : w:\tech5\shared\idlib\math\fader.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idFader::GetInverseSine(
        idFader *this,
        int time,
        long double a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  int startTime; // r11
  double endValue; // fp1
  long double v10; // fp2

  startTime = this->startTime;
  if ( time >= startTime )
  {
    LODWORD(a8) = this->duration;
    if ( time < (int)a8 + startTime )
    {
      HIDWORD(a8) = time - startTime;
      *(double *)&a3 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&a8 + 4) / (float)a8)
                                             * (float)3.1415927)
                                     * (float)0.5)
                             + (float)((float)3.1415927 * (float)1.5));
      v10 = sin(x: a3);
      endValue = (float)((float)*(double *)&v10 + (float)1.0);
    }
    else
    {
      endValue = this->endValue;
    }
  }
  else
  {
    endValue = this->startValue;
  }
  return *((float *)&endValue + 1);
}


// ========================================================================
// ?FadeTowards@idFader@@QAAXMHH@Z
// EA  : 0x826CB400
// RVA : 0x006CB400
// PDB : w:\tech5\shared\idlib\math\fader.h
// ========================================================================

void __fastcall idFader::FadeTowards(
        idFader *this,
        long double endValue_,
        const int time,
        int duration_,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  double v9; // fp31
  double Sine; // fp1

  v9 = *(double *)&endValue_;
  if ( this->type != FADE_LINEAR )
  {
    if ( this->type == FADE_SINE )
    {
      Sine = idFader::GetSine(this, time: duration_, a3: endValue_, a4: duration_, a5, a6, (int)a7, a8);
    }
    else if ( this->type < (unsigned int)(FADE_INVERSE_SINE|FADE_SINE) )
    {
      Sine = idFader::GetInverseSine(this, time: duration_, a3: endValue_, a4: duration_, a5, a6, (int)a7, a8);
    }
    else
    {
      Sine = 0.0;
    }
  }
  else
  {
    Sine = idFader::GetLinear(this, time: duration_, a3: duration_, a4: a5, a5: a6, a6: a7);
  }
  this->startValue = Sine;
  this->startTime = duration_;
  this->endValue = v9;
  this->duration = a5;
}

