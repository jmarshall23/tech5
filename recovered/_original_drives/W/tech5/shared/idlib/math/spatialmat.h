
// ========================================================================
// ??1idSpatialMat@@QAA@XZ
// EA  : 0x82719CC0
// RVA : 0x00719CC0
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::~idSpatialMat(idSpatialMat *this)
{
  float *mat; // r4

  mat = this->mat;
  if ( mat != nullptr && this->allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
}


// ========================================================================
// ?SetSize@idSpatialMat@@QAAXHH@Z
// EA  : 0x8271B6F8
// RVA : 0x0071B6F8
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::SetSize(idSpatialMat *this, int rows, int columns)
{
  int v6; // r6
  int v7; // r9
  int numColumns; // r11
  unsigned int v9; // ctr
  int v10; // r10
  int v11; // ctr
  int v12; // r7
  int v13; // r8
  float *v14; // r10
  int i; // ctr

  if ( rows != this->numRows || columns != this->numColumns || this->mat == nullptr )
  {
    if ( this->mat == nullptr )
    {
      this->mat = (float *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\math/SpatialMat.h(294) : TAG_MATH",
                             size: 0xC0u,
                             tag: TAG_MATH,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      this->allocatedRows = 6;
    }
    this->numRows = rows;
    v6 = 0;
    this->numColumns = columns;
    if ( rows > 0 )
    {
      v7 = 0;
      do
      {
        numColumns = this->numColumns;
        if ( numColumns < 8 )
        {
          if ( 8 - numColumns >= 4 )
          {
            v9 = ((unsigned int)(4 - numColumns) >> 2) + 1;
            do
            {
              v10 = v7 + numColumns;
              this->mat[v10] = 0.0;
              this->mat[v10 + 1] = 0.0;
              this->mat[v7 + 2 + numColumns] = 0.0;
              this->mat[v7 + 3 + numColumns] = 0.0;
              numColumns += 4;
              --v9;
            }
            while ( v9 != 0 );
          }
          if ( numColumns < 8 )
          {
            v11 = 8 - numColumns;
            do
            {
              v12 = v7 + numColumns++;
              this->mat[v12] = 0.0;
              --v11;
            }
            while ( v11 != 0 );
          }
        }
        ++v6;
        v7 += 8;
      }
      while ( v6 < this->numRows );
    }
    if ( this->numRows < 6 )
    {
      v13 = 8 * this->numRows;
      do
      {
        v14 = &this->mat[v13 - 1];
        for ( i = 8; i != 0; --i )
          *++v14 = 0.0;
        v13 += 8;
      }
      while ( v13 < 48 );
    }
  }
}


// ========================================================================
// ?ChangeNumRows@idSpatialMat@@QAAXH@Z
// EA  : 0x8271B888
// RVA : 0x0071B888
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::ChangeNumRows(idSpatialMat *this, int rows)
{
  int numRows; // r11
  int v3; // r8
  int v4; // r7
  float *v5; // r10
  int j; // ctr
  int v7; // r7
  int v8; // r8
  float *v9; // r10
  int i; // ctr

  numRows = this->numRows;
  if ( this->numRows >= rows )
  {
    v7 = rows;
    if ( rows < numRows )
    {
      v8 = 8 * rows;
      do
      {
        v9 = &this->mat[v8 - 1];
        for ( i = 8; i != 0; --i )
          *++v9 = 0.0;
        ++v7;
        v8 += 8;
      }
      while ( v7 < this->numRows );
    }
    this->numRows = rows;
  }
  else
  {
    v3 = 8 * numRows;
    v4 = rows - numRows;
    do
    {
      v5 = &this->mat[v3 - 1];
      for ( j = 8; j != 0; --j )
        *++v5 = 0.0;
      --v4;
      v3 += 8;
    }
    while ( v4 != 0 );
    this->numRows = rows;
  }
}


// ========================================================================
// ?Zero@idSpatialMat@@QAAXHH@Z
// EA  : 0x8271B920
// RVA : 0x0071B920
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::Zero(idSpatialMat *this, int rows, int columns)
{
  idSpatialMat::SetSize(this, rows, columns);
  __asm { vspltisw128 v63, 0 }
  _R11 = 16;
  _R10 = 32;
  _R9 = 48;
  _R8 = 64;
  _R7 = 80;
  _R6 = 96;
  _R5 = 112;
  _R4 = 128;
  _R3 = 144;
  _R30 = 160;
  _R29 = 176;
  _R28 = this->mat;
  __asm { stvx128   v63, r0, r28 }
  __asm { stvx128   v63, r28, r11 }
  _R11 = _R28;
  __asm { stvx128   v63, r11, r10 }
  _R10 = _R11;
  __asm { stvx128   v63, r10, r9 }
  _R9 = _R11;
  __asm { stvx128   v63, r9, r8 }
  _R8 = _R11;
  __asm { stvx128   v63, r8, r7 }
  _R7 = _R11;
  __asm { stvx128   v63, r7, r6 }
  _R6 = _R11;
  __asm { stvx128   v63, r6, r5 }
  _R5 = _R11;
  __asm { stvx128   v63, r5, r4 }
  _R4 = _R11;
  __asm { stvx128   v63, r4, r3 }
  _R3 = _R11;
  __asm { stvx128   v63, r3, r30 }
  __asm { stvx128   v63, r11, r29 }
}


// ========================================================================
// ?Set@idSpatialMat@@QAAXABVidMat3@@0@Z
// EA  : 0x82721348
// RVA : 0x00721348
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::Set(idSpatialMat *this, const idMat3 *m1, const idMat3 *m2)
{
  idSpatialMat::SetSize(this, rows: 3, columns: 6);
  *this->mat = m1->mat[0].x;
  this->mat[3] = m2->mat[0].x;
  this->mat[1] = m1->mat[0].y;
  this->mat[4] = m2->mat[0].y;
  this->mat[2] = m1->mat[0].z;
  this->mat[5] = m2->mat[0].z;
  this->mat[8] = m1->mat[1].x;
  this->mat[11] = m2->mat[1].x;
  this->mat[9] = m1->mat[1].y;
  this->mat[12] = m2->mat[1].y;
  this->mat[10] = m1->mat[1].z;
  this->mat[13] = m2->mat[1].z;
  this->mat[16] = m1->mat[2].x;
  this->mat[19] = m2->mat[2].x;
  this->mat[17] = m1->mat[2].y;
  this->mat[20] = m2->mat[2].y;
  this->mat[18] = m1->mat[2].z;
  this->mat[21] = m2->mat[2].z;
}


// ========================================================================
// ?Set@idSpatialMat@@QAAXABVidMat3@@000@Z
// EA  : 0x82721450
// RVA : 0x00721450
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::Set(
        idSpatialMat *this,
        const idMat3 *m1,
        const idMat3 *m2,
        const idMat3 *m3,
        const idMat3 *m4)
{
  int v10; // r4
  int v11; // r3
  float *p_y; // r10
  int v13; // r5
  float *p_z; // r9
  int v15; // ctr
  int v16; // r28
  const idMat3 *v17; // r8
  int v18; // r29
  int v19; // r11
  int v20; // r30

  idSpatialMat::SetSize(this, rows: 6, columns: 6);
  v10 = (char *)m3 - (char *)m2;
  v11 = (char *)m4 - (char *)m2;
  p_y = &m2->mat[0].y;
  v13 = (char *)m1 - (char *)m2;
  p_z = &m3->mat[0].z;
  v15 = 3;
  v16 = (char *)m1 - (char *)m3;
  v17 = m4;
  v18 = (char *)m4 - (char *)m3;
  v19 = 24;
  v20 = (char *)m1 - (char *)m4;
  do
  {
    this->mat[v19 - 24] = *(float *)((char *)&v17->mat[0].x + v20);
    this->mat[v19 - 21] = *(p_y - 1);
    this->mat[v19] = *(p_z - 2);
    this->mat[v19 + 3] = v17->mat[0].x;
    v17 = (const idMat3 *)((char *)v17 + 12);
    this->mat[v19 - 23] = *(float *)((char *)p_y + v13);
    this->mat[v19 - 20] = *p_y;
    this->mat[v19 + 1] = *(float *)((char *)p_y + v10);
    this->mat[v19 + 4] = *(float *)((char *)p_y + v11);
    this->mat[v19 - 22] = *(float *)((char *)p_z + v16);
    this->mat[v19 - 19] = p_y[1];
    p_y += 3;
    this->mat[v19 + 2] = *p_z;
    this->mat[v19 + 5] = *(float *)((char *)p_z + v18);
    p_z += 3;
    v19 += 8;
    --v15;
  }
  while ( v15 != 0 );
}


// ========================================================================
// ?SetData@idSpatialMat@@QAAXHHPAM@Z
// EA  : 0x82728E68
// RVA : 0x00728E68
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::SetData(idSpatialMat *this, int rows, int columns, float *data)
{
  float *mat; // r4
  int v9; // r6
  int v10; // r9
  int numColumns; // r11
  unsigned int v12; // ctr
  int v13; // r10
  int v14; // ctr
  int v15; // r7
  int v16; // r8
  float *v17; // r10
  int i; // ctr

  mat = this->mat;
  if ( mat != nullptr && this->allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  this->mat = data;
  this->numRows = rows;
  v9 = 0;
  this->allocatedRows = -6;
  this->numColumns = columns;
  if ( rows > 0 )
  {
    v10 = 0;
    do
    {
      numColumns = this->numColumns;
      if ( numColumns < 8 )
      {
        if ( 8 - numColumns >= 4 )
        {
          v12 = ((unsigned int)(4 - numColumns) >> 2) + 1;
          do
          {
            v13 = v10 + numColumns;
            this->mat[v13] = 0.0;
            this->mat[v13 + 1] = 0.0;
            this->mat[v10 + 2 + numColumns] = 0.0;
            this->mat[v10 + 3 + numColumns] = 0.0;
            numColumns += 4;
            --v12;
          }
          while ( v12 != 0 );
        }
        if ( numColumns < 8 )
        {
          v14 = 8 - numColumns;
          do
          {
            v15 = v10 + numColumns++;
            this->mat[v15] = 0.0;
            --v14;
          }
          while ( v14 != 0 );
        }
      }
      ++v9;
      v10 += 8;
    }
    while ( v9 < this->numRows );
  }
  if ( this->numRows < 6 )
  {
    v16 = 8 * this->numRows;
    do
    {
      v17 = &this->mat[v16 - 1];
      for ( i = 8; i != 0; --i )
        *++v17 = 0.0;
      v16 += 8;
    }
    while ( v16 < 48 );
  }
}


// ========================================================================
// ?Negate@idSpatialMat@@QAAXXZ
// EA  : 0x82728FD0
// RVA : 0x00728FD0
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

void __fastcall idSpatialMat::Negate(idSpatialMat *this)
{
  int v1; // r11
  int v3; // r10
  bool v4; // cr57
  int back_chain; // [sp+0h] [-10h] BYREF
  int v12; // [sp+8h] [-8h]
  int v13; // [sp+Ch] [-4h]

  v3 = 0;
  v4 = this->numRows > 0;
  v12 = v1;
  v13 = v1;
  if ( v4 )
  {
    _R9 = &back_chain;
    _R11 = 0;
    _R7 = 16;
    __asm { lvx128    v63, r0, r9 }
    do
    {
      _R9 = this->mat;
      ++v3;
      __asm
      {
        lvx128    v62, r11, r9
        vxor128   v61, v94, v63
        stvx128   v61, r11, r9
      }
      _R6 = &_R9[_R11];
      __asm { lvx128    v60, r6, r7 }
      _R5 = &_R9[_R11];
      __asm { vxor128   v59, v92, v63 }
      __asm { stvx128   v59, r5, r7 }
      _R11 += 8;
    }
    while ( v3 < this->numRows );
  }
}


// ========================================================================
// ?Inverse@idSpatialMat@@QBA_NAAV1@@Z
// EA  : 0x82729050
// RVA : 0x00729050
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

BOOL __fastcall idSpatialMat::Inverse(idSpatialMat *this, idSpatialMat *dst)
{
  BOOL result; // r3

  idSpatialMat::SetSize(this: dst, rows: this->numRows, columns: this->numColumns);
  result = false;
  if ( (unsigned int)(this->numRows - 1) <= 5 )
  {
    switch ( this->numRows )
    {
      case 2:
        return idSpatialMat::Inverse2x2(this, dst);
      case 3:
        return idSpatialMat::Inverse3x3(this, dst);
      case 4:
        return idSpatialMat::Inverse4x4(this, dst);
      case 5:
        return idSpatialMat::Inverse5x5(this, dst);
      case 1:
        return idSpatialMat::Inverse1x1(this, dst);
      default:
        return idSpatialMat::Inverse6x6(this, dst);
    }
  }
  return result;
}


// ========================================================================
// ?SubSpatialVec@idSpatialMat@@QBA?BVidSpatialVec@@H@Z
// EA  : 0x82729120
// RVA : 0x00729120
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

idSpatialMat *__fastcall idSpatialMat::SubSpatialVec(idSpatialMat *this, const idSpatialVec *result, int row)
{
  float *p; // r9
  float *v4; // r6

  p = result->p;
  v4 = &result[1].p[8 * row];
  LOWORD(this->numRows) = -1;
  HIWORD(this->numRows) = (_WORD)p;
  this->numColumns = (int)v4;
  return this;
}


// ========================================================================
// ??4idSpatialMat@@QAAAAV0@ABV0@@Z
// EA  : 0x827294C0
// RVA : 0x007294C0
// PDB : w:\tech5\shared\idlib\math\spatialmat.h
// ========================================================================

idSpatialMat *__fastcall idSpatialMat::operator=(idSpatialMat *this, const idSpatialMat *a)
{
  idSpatialMat::SetSize(this, rows: a->numRows, columns: a->numColumns);
  _R30 = 16;
  _R31 = 32;
  _R3 = 48;
  _R4 = 64;
  _R5 = 80;
  _R6 = 96;
  _R7 = 112;
  _R8 = 128;
  _R9 = 144;
  _R10 = 160;
  _R11 = 176;
  _R27 = a->mat;
  _R26 = this->mat;
  __asm
  {
    lvx128    v63, r0, r27
    stvx128   v63, r0, r26
  }
  __asm { lvx128    v62, r27, r30 }
  __asm { stvx128   v62, r26, r30 }
  _R30 = _R27;
  __asm { lvx128    v61, r30, r31 }
  _R27 = _R26;
  __asm { stvx128   v61, r27, r31 }
  _R31 = _R30;
  __asm { lvx128    v60, r31, r3 }
  _R30 = _R27;
  __asm { stvx128   v60, r30, r3 }
  _R3 = a->mat;
  __asm { lvx128    v59, r3, r4 }
  _R31 = _R27;
  __asm { stvx128   v59, r31, r4 }
  _R4 = _R3;
  __asm { lvx128    v58, r4, r5 }
  _R3 = _R27;
  __asm { stvx128   v58, r3, r5 }
  _R5 = a->mat;
  __asm { lvx128    v57, r5, r6 }
  _R4 = _R27;
  __asm { stvx128   v57, r4, r6 }
  _R3 = _R5;
  __asm { lvx128    v56, r3, r7 }
  _R6 = _R27;
  __asm { stvx128   v56, r6, r7 }
  __asm { lvx128    v55, r5, r8 }
  _R4 = _R27;
  __asm { stvx128   v55, r4, r8 }
  _R3 = _R5;
  __asm { lvx128    v54, r3, r9 }
  _R8 = _R27;
  __asm { stvx128   v54, r8, r9 }
  _R7 = _R3;
  _R6 = _R27;
  __asm
  {
    lvx128    v53, r7, r10
    stvx128   v53, r6, r10
  }
  _R5 = _R3;
  _R4 = _R27;
  __asm { lvx128    v52, r5, r11 }
  __asm { stvx128   v52, r4, r11 }
  return this;
}

