
// ========================================================================
// ?SetSnap@idLookupTable@@QAAX_N@Z
// EA  : 0x82F2EFD0
// RVA : 0x00F2EFD0
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

void __fastcall idLookupTable::SetSnap(idLookupTable *this, bool b)
{
  BOOL spline; // r11

  spline = this->spline;
  this->snap = b;
  if ( spline && b )
    this->spline = false;
}


// ========================================================================
// ?SetSpline@idLookupTable@@QAAX_N@Z
// EA  : 0x82F2EFF8
// RVA : 0x00F2EFF8
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

void __fastcall idLookupTable::SetSpline(idLookupTable *this, bool b)
{
  this->spline = b;
  if ( b && this->snap )
    this->snap = false;
}


// ========================================================================
// ?Finalize@idLookupTable@@QAAXXZ
// EA  : 0x82F2F748
// RVA : 0x00F2F748
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLookupTable::Finalize(idLookupTable *this)
{
  idCatmullRomSpline<float> *p_values; // r30
  __int64 v3; // r8 OVERLAPPED
  int numKnots; // r11
  int v5; // r9
  double v6; // fp1
  double v7; // fp0

  p_values = &this->values;
  idCatmullRomSpline<float>::Sort(this: &this->values);
  numKnots = this->values.numKnots;
  if ( numKnots > 1 && *(&this->_max + numKnots) > 1.0 )
  {
    if ( this->clamp )
    {
      v5 = this->values.numKnots;
      LODWORD(v3) = v5 - 1;
      v6 = (float)((float)v3 / (float)*(__int64 *)((char *)&v3 - 4));
    }
    else
    {
      v6 = 1.0;
    }
    idCatmullRomSpline<float>::Normalize(this: p_values, totalTime: v6);
  }
  v7 = *(&this->_max + this->values.numKnots);
  p_values->changed = true;
  p_values->closeTime = (float)1.0 - (float)v7;
}


// ========================================================================
// ?SetClamp@idLookupTable@@QAAX_N@Z
// EA  : 0x82F2F828
// RVA : 0x00F2F828
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

void __fastcall idLookupTable::SetClamp(idLookupTable *this, bool b)
{
  this->clamp = b;
  this->values.changed = true;
  if ( b )
    this->values.boundaryType = CLAMPED;
  else
    this->values.boundaryType = CLOSED;
}


// ========================================================================
// ?AddValue@idLookupTable@@QAAXMM@Z
// EA  : 0x82F2F860
// RVA : 0x00F2F860
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

void __fastcall idLookupTable::AddValue(idLookupTable *this, double t, double v)
{
  int numKnots; // r10
  idCatmullRomSpline<float> *p_values; // r11
  int v5; // r6

  numKnots = this->values.numKnots;
  p_values = &this->values;
  if ( numKnots < 64 )
  {
    p_values->times[numKnots] = t;
    p_values->values[this->values.numKnots] = v;
    v5 = this->values.numKnots + 1;
    this->values.changed = true;
    this->values.numKnots = v5;
  }
}


// ========================================================================
// ?Clear@idLookupTable@@QAAXXZ
// EA  : 0x82F2F8A0
// RVA : 0x00F2F8A0
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

void __fastcall idLookupTable::Clear(idLookupTable *this)
{
  this->values.numKnots = 0;
  this->values.currentIndex = -1;
  this->values.changed = true;
  this->_min = 0.0;
  this->clamp = false;
  this->_max = 1.0;
  this->snap = false;
  this->spline = false;
}


// ========================================================================
// ?TableLookupNormalized@idLookupTable@@QBAMM_N@Z
// EA  : 0x82F2F998
// RVA : 0x00F2F998
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

float __fastcall idLookupTable::TableLookupNormalized(idLookupTable *this, double time, bool fastSearch, char a4)
{
  int numKnots; // r11
  double CurrentValue; // fp1
  idCatmullRomSpline<float> *p_values; // r31
  double v9; // fp29
  bool v10; // r4
  __int64 v11; // r10
  int v12; // r8
  int v13; // r7
  __int64 v14; // r6
  int v15; // r3
  BOOL snap; // r11
  int v17; // r30
  double v18; // fp30
  __int64 v19; // r10
  int v20; // r8
  int v21; // r7
  __int64 v22; // r6
  double v23; // fp31
  double v24; // fp28

  numKnots = this->values.numKnots;
  if ( numKnots > 0 )
  {
    if ( numKnots == 1 )
    {
LABEL_4:
      CurrentValue = this->values.values[0];
      return *((float *)&CurrentValue + 1);
    }
    if ( this->spline )
    {
      CurrentValue = idCatmullRomSpline<float>::GetCurrentValue(this: &this->values, time, fastSearch, a4);
      return *((float *)&CurrentValue + 1);
    }
    if ( this->clamp )
    {
      if ( time <= this->values.times[0] )
        goto LABEL_4;
      if ( time >= *(&this->_max + numKnots) )
      {
        CurrentValue = this->values.times[numKnots + 63];
        return *((float *)&CurrentValue + 1);
      }
    }
    p_values = &this->values;
    v9 = idCatmullRomSpline<float>::ClampedTime(this: &this->values, t: time);
    v15 = idCatmullRomSpline<float>::IndexForTime(this: &this->values, time: v9, fastSearch: v10, a4);
    snap = this->snap;
    v17 = v15;
    if ( snap )
    {
      CurrentValue = idCatmullRomSpline<float>::ValueForIndex(this: p_values, index: v15 - 1);
      return *((float *)&CurrentValue + 1);
    }
    v18 = idCatmullRomSpline<float>::TimeForIndex(this: p_values, index: v14, a3: v13, a4: v12, a5: v11);
    v23 = idCatmullRomSpline<float>::TimeForIndex(this: p_values, index: v22, a3: v21, a4: v20, a5: v19);
    if ( v18 != v23 )
    {
      v24 = idCatmullRomSpline<float>::ValueForIndex(this: p_values, index: v17 - 1);
      CurrentValue = (float)((float)((float)(idCatmullRomSpline<float>::ValueForIndex(this: p_values, index: v17)
                                           - (float)v24)
                                   * (float)((float)((float)v9 - (float)v23) / (float)((float)v18 - (float)v23)))
                           + (float)v24);
      return *((float *)&CurrentValue + 1);
    }
  }
  CurrentValue = 0.0;
  return *((float *)&CurrentValue + 1);
}


// ========================================================================
// ?TableLookup@idLookupTable@@QBAMM_N@Z
// EA  : 0x82F2FB18
// RVA : 0x00F2FB18
// PDB : w:\tech5\shared\idlib\lookuptable.cpp
// ========================================================================

float __fastcall idLookupTable::TableLookup(idLookupTable *this, double time, bool fastSearch, char a4)
{
  double v4; // fp1

  v4 = (float)((float)((float)(this->_max - this->_min)
                     * idLookupTable::TableLookupNormalized(this, time, fastSearch, a4))
             + this->_min);
  return *((float *)&v4 + 1);
}

