
// ========================================================================
// ??0ssColor@@QAA@HHHH@Z
// EA  : 0x82EE6DC8
// RVA : 0x00EE6DC8
// PDB : w:\tech5\tungsten\superscript\lib\color.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
ssColor *__fastcall ssColor::ssColor(ssColor *this, unsigned int r_, unsigned int g_, unsigned int b_, __int64 a_)
{
  __int64 v5; // r10

  *(__int64 *)((char *)&a_ - 4) = __PAIR64__(r_, HIDWORD(a_));
  LODWORD(v5) = b_;
  this->a = (float)__SPAIR64__(r_, HIDWORD(a_)) * (float)0.00390625;
  this->r = (float)a_ * (float)0.00390625;
  this->g = (float)__SPAIR64__(b_, g_) * (float)0.00390625;
  this->b = (float)v5 * (float)0.00390625;
  return this;
}

