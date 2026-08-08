
// ========================================================================
// crc32_big
// EA  : 0x83220A58
// RVA : 0x01220A58
// PDB : w:\tech5\libs\zlib\crc32.c
// ========================================================================

unsigned int __fastcall crc32_big(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
{
  unsigned int i; // r9
  int v4; // r10
  const unsigned __int8 *v5; // r10
  unsigned int v6; // ctr
  _DWORD *v7; // r10
  unsigned int v8; // r4
  int v9; // r29
  unsigned int v10; // r6
  int v11; // r4
  unsigned int v12; // r6
  unsigned int v13; // r3
  unsigned int v14; // r7
  unsigned int v15; // r4
  unsigned int v16; // r3
  unsigned int v17; // ctr
  const unsigned __int8 *v18; // r10
  const unsigned __int8 *v19; // r10

  for ( i = ~((((crc & 0xFF00) + (crc << 16)) << 8) + ((crc >> 8) & 0xFF00) + HIBYTE(crc));
        len != 0;
        i = crc_table[4][v4] ^ (i << 8) )
  {
    if ( ((unsigned __int8)buf & 3) == 0 )
      break;
    v4 = HIBYTE(i) ^ *buf;
    --len;
    ++buf;
  }
  v5 = buf - 4;
  if ( len >= 0x20 )
  {
    v6 = len >> 5;
    do
    {
      v7 = v5 + 4;
      v8 = *(const unsigned int *)((char *)crc_table[6] + (((*v7 ^ i) >> 14) & 0x3FC))
         ^ *(const unsigned int *)((char *)crc_table[5] + (((*v7 ^ i) >> 6) & 0x3FC))
         ^ *(const unsigned int *)((char *)crc_table[7] + (((*v7 ^ i) >> 22) & 0x3FC))
         ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * (*v7 ^ i)) & 0x3FC))
         ^ v7[1];
      v9 = v7[5];
      v10 = *(const unsigned int *)((char *)crc_table[6] + ((v8 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v8 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v8 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v8) & 0x3FC))
          ^ v7[2];
      v11 = v7[6];
      v12 = *(const unsigned int *)((char *)crc_table[6] + ((v10 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v10 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v10 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v10) & 0x3FC))
          ^ v7[3];
      v13 = *(const unsigned int *)((char *)crc_table[6] + ((v12 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v12 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v12 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v12) & 0x3FC))
          ^ v7[4];
      v5 = (const unsigned __int8 *)(v7 + 7);
      v14 = *(const unsigned int *)((char *)crc_table[6] + ((v13 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v13 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v13 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v13) & 0x3FC))
          ^ v9;
      len -= 32;
      v15 = *(const unsigned int *)((char *)crc_table[6] + ((v14 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v14 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v14 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v14) & 0x3FC))
          ^ v11;
      v16 = *(const unsigned int *)((char *)crc_table[6] + ((v15 >> 14) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[5] + ((v15 >> 6) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[7] + ((v15 >> 22) & 0x3FC))
          ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v15) & 0x3FC))
          ^ *(_DWORD *)v5;
      i = *(const unsigned int *)((char *)crc_table[6] + ((v16 >> 14) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[5] + ((v16 >> 6) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[7] + ((v16 >> 22) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * v16) & 0x3FC));
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( len >= 4 )
  {
    v17 = len >> 2;
    do
    {
      v5 += 4;
      len -= 4;
      i = *(const unsigned int *)((char *)crc_table[6] + (((*(_DWORD *)v5 ^ i) >> 14) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[5] + (((*(_DWORD *)v5 ^ i) >> 6) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[7] + (((*(_DWORD *)v5 ^ i) >> 22) & 0x3FC))
        ^ *(const unsigned int *)((char *)crc_table[4] + ((4 * (*(_DWORD *)v5 ^ i)) & 0x3FC));
      --v17;
    }
    while ( v17 != 0 );
  }
  v18 = v5 + 4;
  if ( len != 0 )
  {
    v19 = v18 - 1;
    do
    {
      ++v19;
      --len;
      i = crc_table[4][HIBYTE(i) ^ *v19] ^ (i << 8);
    }
    while ( len != 0 );
  }
  return (((~i & 0xFF00) + (~i << 16)) << 8) + ((~i >> 8) & 0xFF00) + (~i >> 24);
}


// ========================================================================
// crc32
// EA  : 0x83220DC8
// RVA : 0x01220DC8
// PDB : w:\tech5\libs\zlib\crc32.c
// ========================================================================

unsigned int __fastcall crc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
{
  if ( buf != nullptr )
    return crc32_big(crc, buf, len);
  else
    return 0;
}

