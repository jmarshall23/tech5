
// ========================================================================
// ?SetData@idSpatialVec@@QAAXHPAM@Z
// EA  : 0x82719BA0
// RVA : 0x00719BA0
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

void __fastcall idSpatialVec::SetData(idSpatialVec *this, int length, float *data)
{
  float *p; // r4
  int v7; // r8
  int v8; // r11
  unsigned int v9; // ctr
  int v10; // r11
  int v11; // ctr

  p = this->p;
  if ( p != nullptr && this->allocated > 0 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  this->p = data;
  this->size = length;
  v7 = length;
  this->allocated = -8;
  if ( length < 8 )
  {
    if ( 8 - length >= 4 )
    {
      v8 = length;
      v7 = 4 * (((unsigned int)(4 - length) >> 2) + 1) + length;
      v9 = ((unsigned int)(4 - length) >> 2) + 1;
      do
      {
        this->p[v8] = 0.0;
        this->p[v8 + 1] = 0.0;
        this->p[v8 + 2] = 0.0;
        this->p[v8 + 3] = 0.0;
        v8 += 4;
        --v9;
      }
      while ( v9 != 0 );
    }
    if ( v7 < 8 )
    {
      v10 = v7;
      v11 = 8 - v7;
      do
      {
        this->p[v10++] = 0.0;
        --v11;
      }
      while ( v11 != 0 );
    }
  }
}


// ========================================================================
// ??1idSpatialVec@@QAA@XZ
// EA  : 0x82719C90
// RVA : 0x00719C90
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

void __fastcall idSpatialVec::~idSpatialVec(idStaticSpatialVec *this)
{
  float *p; // r4

  p = this->p;
  if ( p != nullptr && this->allocated > 0 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
}


// ========================================================================
// ?ChangeSize@idSpatialVec@@QAAXH@Z
// EA  : 0x8271A418
// RVA : 0x0071A418
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

void __fastcall idSpatialVec::ChangeSize(idSpatialVec *this, int newSize)
{
  int size; // r9
  int v3; // r11
  unsigned int v4; // ctr
  int v5; // r11
  int v6; // ctr

  size = this->size;
  if ( size >= newSize )
    size = newSize;
  if ( size < 8 )
  {
    if ( 8 - size >= 4 )
    {
      v3 = size;
      v4 = ((unsigned int)(4 - size) >> 2) + 1;
      size += 4 * v4;
      do
      {
        this->p[v3] = 0.0;
        this->p[v3 + 1] = 0.0;
        this->p[v3 + 2] = 0.0;
        this->p[v3 + 3] = 0.0;
        v3 += 4;
        --v4;
      }
      while ( v4 != 0 );
    }
    if ( size < 8 )
    {
      v5 = size;
      v6 = 8 - size;
      do
      {
        this->p[v5++] = 0.0;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  this->size = newSize;
}


// ========================================================================
// ?SetSize@idSpatialVec@@QAAXH@Z
// EA  : 0x8271A610
// RVA : 0x0071A610
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

void __fastcall idSpatialVec::SetSize(idSpatialVec *this, int newSize)
{
  if ( this->size != newSize || this->p == nullptr )
  {
    if ( this->p == nullptr )
    {
      this->p = (float *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\math/SpatialVec.h(218) : TAG_MATH",
                           size: 0x20u,
                           tag: TAG_MATH,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      this->allocated = 8;
    }
    idSpatialVec::ChangeSize(this, newSize);
  }
}


// ========================================================================
// ?Clamp@idSpatialVec@@QAAXMM@Z
// EA  : 0x8271B620
// RVA : 0x0071B620
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

void __fastcall idSpatialVec::Clamp(idSpatialVec *this, double min, double max)
{
  int v3; // r9
  int v4; // r11
  float *p; // r10
  double v6; // fp0

  v3 = 0;
  if ( this->size > 0 )
  {
    v4 = 0;
    do
    {
      p = this->p;
      v6 = p[v4];
      if ( v6 >= min )
      {
        if ( v6 > max )
          p[v4] = max;
      }
      else
      {
        p[v4] = min;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->size );
  }
}


// ========================================================================
// ?Length@idSpatialVec@@QBAMXZ
// EA  : 0x8271B678
// RVA : 0x0071B678
// PDB : w:\tech5\shared\idlib\math\spatialvec.h
// ========================================================================

float __fastcall idSpatialVec::Length(idSpatialVec *this)
{
  int v1; // r10
  int size; // r6
  double v3; // fp0
  double v4; // fp13
  double v5; // fp12
  float *p; // r9
  int v7; // r11
  double v8; // fp1

  v1 = 0;
  size = this->size;
  v3 = 0.0;
  v4 = 0.0;
  v5 = 0.0;
  if ( size >= 2 )
  {
    p = this->p;
    v7 = 0;
    do
    {
      v1 += 2;
      v3 = (float)((float)(p[v7] * p[v7]) + (float)v3);
      v4 = (float)((float)(p[v7 + 1] * p[v7 + 1]) + (float)v4);
      v7 += 2;
    }
    while ( v1 < size - 1 );
  }
  if ( v1 < size )
    v5 = (float)(this->p[v1] * this->p[v1]);
  v8 = __fsqrts((float)((float)((float)v4 + (float)v3) + (float)v5));
  return *((float *)&v8 + 1);
}

