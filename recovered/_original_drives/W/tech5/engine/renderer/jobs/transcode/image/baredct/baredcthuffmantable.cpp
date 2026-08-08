
// ========================================================================
// ?Init@idBareDCTHuffmanTable@@AAAXPBE0_N@Z
// EA  : 0x828EA1C8
// RVA : 0x008EA1C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredcthuffmantable.cpp
// ========================================================================

void __fastcall idBareDCTHuffmanTable::Init(
        idBareDCTHuffmanTable *this,
        const unsigned __int8 *pBits,
        const unsigned __int8 *pVal,
        bool encode)
{
  int v8; // r11
  int i; // r8
  int v10; // ctr
  _BYTE *v11; // r10
  int v12; // r24
  int v13; // r10
  int v14; // r11
  int j; // r6
  _BYTE *v16; // r9
  _DWORD *v17; // r8
  char v18; // r7
  int v19; // r10
  int v20; // r7
  int *v21; // r11
  int k; // ctr
  int v23; // r10
  int v24; // r7
  int m; // r4
  int v26; // r6
  _DWORD *v27; // r8
  int v28; // r11
  int v29; // ctr
  int v30; // r5
  int v31; // r11
  int *v32; // r4
  int v33; // r6
  int v34; // r7
  _DWORD *v35; // r10
  int v36; // r8
  int *v37; // r9
  int v38; // ctr
  unsigned int *v39; // r10
  int v40; // ctr
  const unsigned __int8 *v41; // r11
  char v42; // r5
  char *v43; // r4
  _BYTE v44[268]; // [sp+50h] [-570h] BYREF
  _BYTE v45[1124]; // [sp+15Ch] [-464h] BYREF

  memcpy(Dst: this->symbols, Src: pVal, Size: sizeof(this->symbols));
  v8 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    if ( pBits[i] != 0 )
    {
      v10 = pBits[i];
      v11 = &v44[v8 - 1];
      v8 += v10;
      do
      {
        *++v11 = i;
        --v10;
      }
      while ( v10 != 0 );
    }
  }
  v12 = v8;
  v13 = 0;
  v44[v8] = 0;
  v14 = 0;
  for ( j = v44[0]; v44[v14] != 0; ++j )
  {
    v16 = &v44[v14];
    if ( (char)v44[v14] == j )
    {
      v17 = &v45[4 * v14];
      do
      {
        v18 = *++v16;
        ++v14;
        *++v17 = v13++;
      }
      while ( v18 == j );
    }
    v13 *= 2;
  }
  this->minCode[0] = 0;
  v19 = 0;
  this->maxCode[0] = 0;
  v20 = 1;
  v21 = &this->minCode[1];
  for ( k = 16; k != 0; --k )
  {
    if ( pBits[v20] != 0 )
    {
      v21[35] = v19;
      *v21 = *(_DWORD *)&v45[4 * v19 + 4];
      v19 += pBits[v20];
      v21[17] = *(_DWORD *)&v45[4 * v19];
    }
    else
    {
      v21[35] = 0;
      *v21 = -1;
      v21[17] = -1;
    }
    ++v20;
    ++v21;
  }
  this->maxCode[17] = 0xFFFFF;
  XMemSet(dest: this->look_nbits, c: 0, count: 0x100u);
  XMemSet(dest: this->look_sym, c: 0, count: 0x100u);
  v23 = 0;
  v24 = 1;
  for ( m = 7; m >= 0; --m )
  {
    v26 = 1;
    if ( pBits[v24] != 0 )
    {
      v27 = &v45[4 * v23 + 4];
      do
      {
        v28 = *v27 << m;
        if ( 1 << m > 0 )
        {
          v29 = 1 << m;
          do
          {
            this->look_nbits[v28] = v24;
            this->look_sym[v28++] = pVal[v23];
            --v29;
          }
          while ( v29 != 0 );
        }
        ++v26;
        ++v23;
        ++v27;
      }
      while ( v26 <= pBits[v24] );
    }
    ++v24;
  }
  XMemSet(dest: this->test_nbits, c: 0, count: 0x40u);
  v30 = 0;
  v31 = 1;
  v32 = &this->test_nbits[1];
  do
  {
    v33 = 1;
    if ( pBits[v31] != 0 )
    {
      v34 = 16 - v31;
      v35 = &v45[4 * v30 + 4];
      do
      {
        v36 = (*v35 + 1) << v34;
        if ( v31 < 16 )
        {
          v37 = v32 - 1;
          if ( v34 != 0 )
          {
            v38 = 16 - v31;
            do
            {
              *++v37 = v36;
              --v38;
            }
            while ( v38 != 0 );
          }
        }
        ++v33;
        ++v30;
        ++v35;
      }
      while ( v33 <= pBits[v31] );
    }
    ++v31;
    ++v32;
  }
  while ( v31 <= 16 );
  if ( encode )
  {
    XMemSet(dest: this, c: 0, count: 0x400u);
    XMemSet(dest: this->size, c: 0, count: 0x100u);
    if ( v12 > 0 )
    {
      v39 = (unsigned int *)v45;
      v40 = v12;
      v41 = pVal;
      do
      {
        ++v39;
        v42 = v41[v44 - pVal];
        *(unsigned int *)((char *)this->code + __ROL4__(*v41, 2)) = *v39;
        v43 = (char *)this + *v41++;
        v43[1024] = v42;
        --v40;
      }
      while ( v40 != 0 );
    }
  }
}


// ========================================================================
// ??0idBareDCTHuffmanTable@@QAA@W4huffmanType_t@@_N@Z
// EA  : 0x828EA4F0
// RVA : 0x008EA4F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredcthuffmantable.cpp
// ========================================================================

idBareDCTHuffmanTable *__fastcall idBareDCTHuffmanTable::idBareDCTHuffmanTable(
        idBareDCTHuffmanTable *this,
        unsigned int huffmanType,
        bool encode)
{
  const unsigned __int8 *v5; // r5
  const unsigned __int8 *v6; // r4

  if ( huffmanType <= 3 )
  {
    if ( huffmanType == 1 )
    {
      v5 = valYAC_0;
      v6 = bitsYAC_0;
    }
    else if ( huffmanType == 2 )
    {
      v5 = valCoCgDC_0;
      v6 = bitsCoCgDC_0;
    }
    else if ( huffmanType != 0 )
    {
      v5 = valCoCgAC_0;
      v6 = bitsCoCgAC_0;
    }
    else
    {
      v6 = bitsYDC_0;
      v5 = valYDC_0;
    }
    idBareDCTHuffmanTable::Init(this, pBits: v6, pVal: v5, encode);
  }
  return this;
}

