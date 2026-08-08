
// ========================================================================
// ?GetAverage@idRunningAverage@@QAAMXZ
// EA  : 0x82F7D718
// RVA : 0x00F7D718
// PDB : w:\tech5\shared\idlib\runningaverage.cpp
// ========================================================================

float __fastcall idRunningAverage::GetAverage(idRunningAverage *this)
{
  int num; // r6
  __int64 v2; // r11
  double v3; // fp0
  double v4; // fp13
  double v5; // fp12
  float *list; // r9
  double v7; // fp1

  num = this->vals.num;
  HIDWORD(v2) = 0;
  v3 = 0.0;
  v4 = 0.0;
  v5 = 0.0;
  if ( num >= 2 )
  {
    list = this->vals.list;
    LODWORD(v2) = 0;
    do
    {
      HIDWORD(v2) += 2;
      v3 = (float)(*(float *)((char *)list + v2) + (float)v3);
      v4 = (float)(*(float *)((char *)list + v2 + 4) + (float)v4);
      LODWORD(v2) = v2 + 8;
    }
    while ( SHIDWORD(v2) < num - 1 );
  }
  if ( SHIDWORD(v2) < num )
  {
    HIDWORD(v2) *= 4;
    v5 = *(float *)((char *)this->vals.list + HIDWORD(v2));
  }
  LODWORD(v2) = this->vals.num;
  v7 = (float)((float)((float)((float)v4 + (float)v3) + (float)v5) / (float)v2);
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetMin@idRunningAverage@@QAAMXZ
// EA  : 0x82F7D7A0
// RVA : 0x00F7D7A0
// PDB : w:\tech5\shared\idlib\runningaverage.cpp
// ========================================================================

float __fastcall idRunningAverage::GetMin(idRunningAverage *this)
{
  float *list; // r10
  int v2; // r9
  int num; // r5
  int v5; // r11
  int v13; // r11
  int v14; // ctr

  list = this->vals.list;
  v2 = 1;
  num = this->vals.num;
  _FP1 = *list;
  if ( num > 1 )
  {
    if ( num - 1 >= 4 )
    {
      v5 = 1;
      do
      {
        _FP13 = (float)((float)_FP1 - list[v5]);
        v2 += 4;
        __asm { fsel      f9, f13, f0, f1 }
        _FP8 = (float)((float)_FP9 - list[v5 + 1]);
        __asm { fsel      f7, f8, f12, f9 }
        _FP6 = (float)((float)_FP7 - list[v5 + 2]);
        __asm { fsel      f5, f6, f10, f7 }
        _FP4 = (float)((float)_FP5 - list[v5 + 3]);
        v5 += 4;
        __asm { fsel      f1, f4, f11, f5 }
      }
      while ( v2 < num - 3 );
    }
    if ( v2 < num )
    {
      v13 = v2;
      v14 = num - v2;
      do
      {
        _FP13 = (float)((float)_FP1 - list[v13++]);
        __asm { fsel      f1, f13, f0, f1 }
        --v14;
      }
      while ( v14 != 0 );
    }
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?GetMax@idRunningAverage@@QAAMXZ
// EA  : 0x82F7D848
// RVA : 0x00F7D848
// PDB : w:\tech5\shared\idlib\runningaverage.cpp
// ========================================================================

float __fastcall idRunningAverage::GetMax(idRunningAverage *this)
{
  float *list; // r10
  int v2; // r9
  int num; // r5
  int v5; // r11
  int v13; // r11
  int v14; // ctr

  list = this->vals.list;
  v2 = 1;
  num = this->vals.num;
  _FP1 = *list;
  if ( num > 1 )
  {
    if ( num - 1 >= 4 )
    {
      v5 = 1;
      do
      {
        _FP13 = (float)((float)_FP1 - list[v5]);
        v2 += 4;
        __asm { fsel      f9, f13, f1, f0 }
        _FP8 = (float)((float)_FP9 - list[v5 + 1]);
        __asm { fsel      f7, f8, f9, f12 }
        _FP6 = (float)((float)_FP7 - list[v5 + 2]);
        __asm { fsel      f5, f6, f7, f10 }
        _FP4 = (float)((float)_FP5 - list[v5 + 3]);
        v5 += 4;
        __asm { fsel      f1, f4, f5, f11 }
      }
      while ( v2 < num - 3 );
    }
    if ( v2 < num )
    {
      v13 = v2;
      v14 = num - v2;
      do
      {
        _FP13 = (float)((float)_FP1 - list[v13++]);
        __asm { fsel      f1, f13, f1, f0 }
        --v14;
      }
      while ( v14 != 0 );
    }
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?Init@idRunningAverage@@QAAXH@Z
// EA  : 0x82F7DA38
// RVA : 0x00F7DA38
// PDB : w:\tech5\shared\idlib\runningaverage.cpp
// ========================================================================

void __fastcall idRunningAverage::Init(idRunningAverage *this, int num)
{
  int maxNum; // r11
  idList<float,5> *p_vals; // r30

  maxNum = this->maxNum;
  this->current = 0;
  if ( maxNum != num )
  {
    p_vals = &this->vals;
    if ( num > this->vals.size )
      idList<float,116>::Resize(this: (idList<float,13> *)&this->vals, newsize: num);
    p_vals->listStatic = 2;
  }
  if ( this->vals.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vals);
  this->vals.num = __CFADD__(-this->vals.size, this->vals.size ^ 0x80000000) ? 0 : this->vals.size;
  this->maxNum = num;
}


// ========================================================================
// ?Add@idRunningAverage@@QAAXM@Z
// EA  : 0x82F7DAC0
// RVA : 0x00F7DAC0
// PDB : w:\tech5\shared\idlib\runningaverage.cpp
// ========================================================================

void __fastcall idRunningAverage::Add(idRunningAverage *this, double val)
{
  int maxNum; // r10
  int v5; // r11
  int v6; // r11

  maxNum = this->maxNum;
  if ( this->vals.num != this->maxNum )
  {
    idList<float,5>::Alloc(this: &this->vals);
    v6 = this->vals.num - 1;
    goto LABEL_5;
  }
  v5 = this->current + 1;
  this->current = v5;
  if ( v5 >= maxNum )
  {
    v6 = 0;
LABEL_5:
    this->current = v6;
  }
  this->vals.list[this->current] = val;
}

