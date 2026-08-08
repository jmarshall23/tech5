
// ========================================================================
// ??1idMatX@@QAA@XZ
// EA  : 0x8273BE88
// RVA : 0x0073BE88
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

void __fastcall idMatX::~idMatX(idMatX *this)
{
  float *mat; // r4

  mat = this->mat;
  if ( mat != nullptr && this->alloced != -1 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
}


// ========================================================================
// ?SetDataCacheLines@idMatX@@QAAXHHPAM_N@Z
// EA  : 0x8273BEB8
// RVA : 0x0073BEB8
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

void __fastcall idMatX::SetDataCacheLines(idMatX *this, int rows, int columns, float *data, bool clear)
{
  float *mat; // r4
  int v11; // r11
  int v12; // r10
  int v13; // r11
  bool v14; // zf
  int v15; // r10
  int v16; // r9

  mat = this->mat;
  if ( mat != nullptr && this->alloced != -1 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  this->mat = data;
  this->numRows = rows;
  this->alloced = -1;
  v11 = rows * columns;
  this->numColumns = columns;
  if ( clear )
  {
    v12 = 4 * v11;
    v14 = 4 * v11 <= 0;
    v13 = 0;
    if ( !v14 )
    {
      do
      {
        __asm { dcbz128   r11, r9 }
        v13 += 128;
      }
      while ( v13 < v12 );
    }
  }
  else
  {
    v15 = v11 + 3;
    if ( v11 < (int)((v11 + 3) & 0xFFFFFFFC) )
    {
      v16 = v11;
      do
      {
        ++v15;
        ++v11;
        this->mat[v16++] = 0.0;
      }
      while ( v11 < (int)(v15 & 0xFFFFFFFC) );
    }
  }
}


// ========================================================================
// ?SetData@idMatX@@QAAXHHPAM@Z
// EA  : 0x82EF8508
// RVA : 0x00EF8508
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

void __fastcall idMatX::SetData(idMatX *this, int rows, int columns, float *data)
{
  float *mat; // r4
  int v9; // r11
  int v10; // r10
  int v11; // r9

  mat = this->mat;
  if ( mat != nullptr && this->alloced != -1 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  v9 = rows * columns;
  this->mat = data;
  this->numRows = rows;
  this->numColumns = columns;
  v10 = rows * columns + 3;
  this->alloced = -1;
  if ( rows * columns < (int)(v10 & 0xFFFFFFFC) )
  {
    v11 = v9;
    do
    {
      ++v10;
      ++v9;
      this->mat[v11++] = 0.0;
    }
    while ( v9 < (int)(v10 & 0xFFFFFFFC) );
  }
}


// ========================================================================
// ?SetSize@idMatX@@QAAXHH@Z
// EA  : 0x82F305E8
// RVA : 0x00F305E8
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

void __fastcall idMatX::SetSize(idMatX *this, int rows, int columns)
{
  int v6; // r30
  int alloced; // r11
  signed int v8; // r29
  float *mat; // r4
  int v10; // r10
  int v11; // r11
  int v12; // r9

  if ( rows != this->numRows || columns != this->numColumns || this->mat == nullptr )
  {
    v6 = rows * columns;
    alloced = this->alloced;
    v8 = (rows * columns + 3) & 0xFFFFFFFC;
    if ( v8 > alloced && alloced != -1 )
    {
      mat = this->mat;
      if ( mat != nullptr )
        idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
      this->mat = (float *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\math/MatX.h(688) : TAG_MATH",
                             size: 4 * v8,
                             tag: TAG_MATH,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      this->alloced = v8;
    }
    v10 = v6 + 3;
    this->numRows = rows;
    this->numColumns = columns;
    v11 = rows * columns;
    if ( v6 < (int)((v6 + 3) & 0xFFFFFFFC) )
    {
      v12 = v6;
      do
      {
        ++v10;
        ++v11;
        this->mat[v12++] = 0.0;
      }
      while ( v11 < (int)(v10 & 0xFFFFFFFC) );
    }
  }
}


// ========================================================================
// ?Random@idMatX@@QAAXHHHMM@Z
// EA  : 0x82F306E0
// RVA : 0x00F306E0
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMatX::Random(idMatX *this, int rows, int columns, int seed, double l, double u)
{
  int v10; // r2 OVERLAPPED
  __int64 v11; // r5
  int v12; // r9
  __int64 v13; // r7
  int v14; // r10
  int v15; // r8
  int v16; // r8
  int v17; // r3
  int v18; // r8
  int v19; // r3
  int v20; // r3
  int v21; // r10
  int v22; // ctr
  __int64 v23; // [sp+58h] [-48h]

  idMatX::SetSize(this, rows, columns);
  LODWORD(v11) = this->numColumns * this->numRows;
  v12 = 0;
  if ( (int)v11 >= 4 )
  {
    HIDWORD(v13) = v11 - 3;
    v14 = 0;
    do
    {
      v15 = 1103515245 * seed + 12345;
      v12 += 4;
      v17 = (v15 >> 16) & 0x7FFF;
      v16 = 1103515245 * v15 + 12345;
      v23 = *(_QWORD *)(&v10 - 1);
      v19 = (v16 >> 16) & 0x7FFF;
      v18 = 1103515245 * v16 + 12345;
      seed = 1103515245 * v18 + 12345;
      LODWORD(v13) = (seed >> 16) & 0x7FFF;
      this->mat[v14] = (float)((float)((float)v23 * (float)((float)u - (float)l)) * (float)0.000030518509) + (float)l;
      HIDWORD(v11) = &this->mat[v14];
      *(float *)(HIDWORD(v11) + 4) = (float)((float)((float)*(__int64 *)(&v10 - 1) * (float)((float)u - (float)l))
                                           * (float)0.000030518509)
                                   + (float)l;
      v20 = (v18 >> 16) & 0x7FFF;
      this->mat[v14 + 2] = (float)((float)((float)*(__int64 *)(&v10 - 1) * (float)((float)u - (float)l))
                                 * (float)0.000030518509)
                         + (float)l;
      this->mat[v14 + 3] = (float)((float)((float)v13 * (float)((float)u - (float)l)) * (float)0.000030518509)
                         + (float)l;
      v14 += 4;
    }
    while ( v12 < SHIDWORD(v13) );
  }
  if ( v12 < (int)v11 )
  {
    v21 = v12;
    v22 = v11 - v12;
    do
    {
      seed = 1103515245 * seed + 12345;
      LODWORD(v11) = (seed >> 16) & 0x7FFF;
      this->mat[v21++] = (float)((float)((float)v11 * (float)((float)u - (float)l)) * (float)0.000030518509) + (float)l;
      --v22;
    }
    while ( v22 != 0 );
  }
}


// ========================================================================
// ??4idMatX@@QAAAAV0@ABV0@@Z
// EA  : 0x82F33978
// RVA : 0x00F33978
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

idMatX *__fastcall idMatX::operator=(idMatX *this, const idMatX *a)
{
  int v4; // r11
  unsigned int v6; // ctr

  idMatX::SetSize(this, rows: a->numRows, columns: a->numColumns);
  v4 = a->numRows * a->numColumns;
  if ( v4 > 0 )
  {
    v6 = ((unsigned int)(v4 - 1) >> 2) + 1;
    _R11 = 0;
    do
    {
      _R10 = a->mat;
      _R9 = this->mat;
      __asm
      {
        lvx128    v63, r10, r11
        stvx128   v63, r9, r11
      }
      _R11 += 16;
      --v6;
    }
    while ( v6 != 0 );
  }
  return this;
}


// ========================================================================
// ?TransposeMultiply@idMatX@@QBAXAAV1@ABV1@@Z
// EA  : 0x82F339F8
// RVA : 0x00F339F8
// PDB : w:\tech5\shared\idlib\math\matx.h
// ========================================================================

void __fastcall idMatX::TransposeMultiply(idMatX *this, idMatX *dst, const idMatX *a)
{
  float *mat; // r11
  int v7; // r29
  int numColumns; // r26
  int v9; // r28
  float *v10; // r27
  int v11; // ctr
  int v12; // r4
  double v13; // fp0
  double v14; // fp13
  float *v15; // r10
  int numRows; // r5
  float *v17; // r11
  int v18; // r9
  double v19; // fp12
  int v20; // r8
  int v21; // r7
  float *v22; // r11
  float *v23; // r10

  idMatX::SetSize(this: dst, rows: this->numColumns, columns: a->numColumns);
  mat = dst->mat;
  v7 = 0;
  numColumns = this->numColumns;
  v9 = a->numColumns;
  if ( numColumns > 0 )
  {
    v10 = mat - 1;
    do
    {
      if ( v9 > 0 )
      {
        v11 = v9;
        v12 = 0;
        do
        {
          v13 = 0.0;
          v14 = 0.0;
          v15 = &this->mat[v7];
          numRows = this->numRows;
          v17 = &a->mat[v12];
          v18 = 1;
          v19 = (float)(*v17 * *v15);
          if ( this->numRows > 1 )
          {
            if ( numRows - 1 >= 2 )
            {
              v20 = this->numColumns;
              v21 = a->numColumns;
              do
              {
                v22 = &v17[v21];
                v18 += 2;
                v23 = &v15[v20];
                v13 = (float)((float)(*v22 * *v23) + (float)v13);
                v17 = &v22[v21];
                v15 = &v23[v20];
                v14 = (float)((float)(*v17 * *v15) + (float)v14);
              }
              while ( v18 < numRows - 1 );
            }
            if ( v18 < numRows )
              v19 = (float)((float)(v15[this->numColumns] * v17[a->numColumns]) + (float)v19);
            v19 = (float)((float)((float)v14 + (float)v13) + (float)v19);
          }
          *++v10 = v19;
          ++v12;
          --v11;
        }
        while ( v11 != 0 );
      }
      ++v7;
    }
    while ( v7 < numColumns );
  }
}

