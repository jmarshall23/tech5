
// ========================================================================
// ??0idParametricDecay@@QAA@XZ
// EA  : 0x82F30348
// RVA : 0x00F30348
// PDB : w:\tech5\shared\idlib\math\decay.cpp
// ========================================================================

idParametricDecay *__fastcall idParametricDecay::idParametricDecay(idParametricDecay *this)
{
  this->delta = 0.0;
  this->linear = 0.0;
  this->t0 = 0.0;
  this->tdelta = 0.0;
  this->lambda = 0.0;
  return this;
}


// ========================================================================
// ?Init@idParametricDecay@@QAAXMMMMM@Z
// EA  : 0x82F30368
// RVA : 0x00F30368
// PDB : w:\tech5\shared\idlib\math\decay.cpp
// ========================================================================

void __fastcall idParametricDecay::Init(
        idParametricDecay *this,
        double delta,
        double linear,
        double t0,
        double tdelta,
        double lambda)
{
  this->delta = delta;
  this->linear = linear;
  this->t0 = t0;
  this->tdelta = tdelta;
  this->lambda = lambda;
}


// ========================================================================
// ?SetTZero@idParametricDecay@@QAAXM@Z
// EA  : 0x82F30380
// RVA : 0x00F30380
// PDB : w:\tech5\shared\idlib\math\decay.cpp
// ========================================================================

void __fastcall idParametricDecay::SetTZero(idParametricDecay *this, double t0)
{
  this->t0 = t0;
}


// ========================================================================
// ?SetDelta@idParametricDecay@@QAAXM@Z
// EA  : 0x82F30388
// RVA : 0x00F30388
// PDB : w:\tech5\shared\idlib\math\decay.cpp
// ========================================================================

void __fastcall idParametricDecay::SetDelta(idParametricDecay *this, double delta)
{
  this->delta = delta;
}


// ========================================================================
// ?Evaluate@idParametricDecay@@QBAMM@Z
// EA  : 0x82F30390
// RVA : 0x00F30390
// PDB : w:\tech5\shared\idlib\math\decay.cpp
// ========================================================================

float __fastcall idParametricDecay::Evaluate(idParametricDecay *this, double t, double a3, long double a4)
{
  double delta; // fp1
  double v6; // fp31
  long double v7; // fp2
  long double v8; // fp2

  if ( t >= this->t0 )
  {
    if ( (float)((float)t - this->t0) <= (double)this->tdelta )
    {
      v6 = (float)((float)((float)t - this->t0) / this->tdelta);
      *((double *)&v7 + 1) = (float)((float)((float)t - this->t0) / (float)(this->lambda * this->tdelta));
      *(_QWORD *)&v7 = 0x3FE0000000000000LL;
      v8 = pow(x: v7, y: a4);
      delta = (float)((float)((float)((float)((float)1.0 - this->linear) * (float)*(double *)&v8)
                            + (float)((float)((float)1.0 - (float)v6) * this->linear))
                    * this->delta);
    }
    else
    {
      delta = 0.0;
    }
  }
  else
  {
    delta = this->delta;
  }
  return *((float *)&delta + 1);
}

