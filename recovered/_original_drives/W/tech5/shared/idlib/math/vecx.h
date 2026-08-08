
// ========================================================================
// ??1idVecX@@QAA@XZ
// EA  : 0x8273BC50
// RVA : 0x0073BC50
// PDB : w:\tech5\shared\idlib\math\vecx.h
// ========================================================================

void __fastcall idVecX::~idVecX(idVecX *this)
{
  float *p; // r4

  p = this->p;
  if ( p != nullptr && (p < idVecX::tempPtr || p >= idVecX::tempPtr + 1024) && this->alloced != -1 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
}


// ========================================================================
// ?SetData@idVecX@@QAAXHPAM@Z
// EA  : 0x8273BC98
// RVA : 0x0073BC98
// PDB : w:\tech5\shared\idlib\math\vecx.h
// ========================================================================

void __fastcall idVecX::SetData(idVecX *this, int length, float *data)
{
  float *p; // r4
  signed int v7; // r11
  int v8; // r10

  p = this->p;
  if ( p != nullptr && (p < idVecX::tempPtr || p >= idVecX::tempPtr + 1024) && this->alloced != -1 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  this->p = data;
  this->size = length;
  this->alloced = -1;
  v7 = length;
  if ( length < (int)((length + 3) & 0xFFFFFFFC) )
  {
    v8 = length;
    do
    {
      ++v7;
      this->p[v8++] = 0.0;
    }
    while ( v7 < (int)((v7 + 3) & 0xFFFFFFFC) );
  }
}


// ========================================================================
// ?SetSize@idVecX@@QAAXH@Z
// EA  : 0x82F30450
// RVA : 0x00F30450
// PDB : w:\tech5\shared\idlib\math\vecx.h
// ========================================================================

void __fastcall idVecX::SetSize(idVecX *this, int newSize)
{
  int alloced; // r11
  signed int v5; // r30
  float *p; // r4
  signed int v7; // r11
  int v8; // r10

  if ( newSize != this->size || this->p == nullptr )
  {
    alloced = this->alloced;
    v5 = (newSize + 3) & 0xFFFFFFFC;
    if ( v5 > alloced && alloced != -1 )
    {
      p = this->p;
      if ( p != nullptr )
        idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
      this->p = (float *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\math/VecX.h(526) : TAG_MATH",
                           size: 4 * v5,
                           tag: TAG_MATH,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      this->alloced = v5;
    }
    this->size = newSize;
    v7 = newSize;
    if ( newSize < v5 )
    {
      v8 = newSize;
      do
      {
        ++v7;
        this->p[v8++] = 0.0;
      }
      while ( v7 < (int)((v7 + 3) & 0xFFFFFFFC) );
    }
  }
}


// ========================================================================
// ?Random@idVecX@@QAAXHHMM@Z
// EA  : 0x82F30528
// RVA : 0x00F30528
// PDB : w:\tech5\shared\idlib\math\vecx.h
// ========================================================================

void __fastcall idVecX::Random(idVecX *this, int length, int seed, double l, double u)
{
  __int64 v9; // r4
  int v10; // r11
  int v11; // r10

  idVecX::SetSize(this, newSize: length);
  v10 = 0;
  if ( this->size > 0 )
  {
    v11 = 0;
    do
    {
      seed = 1103515245 * seed + 12345;
      ++v10;
      LODWORD(v9) = (seed >> 16) & 0x7FFF;
      this->p[v11] = (float)((float)((float)v9 * (float)((float)u - (float)l)) * (float)0.000030518509) + (float)l;
      HIDWORD(v9) = this->size;
      ++v11;
    }
    while ( v10 < this->size );
  }
}


// ========================================================================
// ??4idVecX@@QAAAAV0@ABV0@@Z
// EA  : 0x82F338F0
// RVA : 0x00F338F0
// PDB : w:\tech5\shared\idlib\math\vecx.h
// ========================================================================

idVecX *__fastcall idVecX::operator=(idVecX *this, const idVecX *a)
{
  int v4; // r10

  idVecX::SetSize(this, newSize: a->size);
  v4 = 0;
  for ( _R11 = 0; v4 < a->size; _R11 += 16 )
  {
    _R9 = a->p;
    v4 += 4;
    _R8 = this->p;
    __asm
    {
      lvx128    v63, r9, r11
      stvx128   v63, r8, r11
    }
  }
  idVecX::tempIndex = 0;
  return this;
}

