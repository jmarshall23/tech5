
// ========================================================================
// ?MurMur32_HashData@@YAIPBXHI@Z
// EA  : 0x82F2CBB8
// RVA : 0x00F2CBB8
// PDB : w:\tech5\shared\idlib\hashing\murmur.cpp
// ========================================================================

unsigned int __fastcall MurMur32_HashData(unsigned __int8 *key, unsigned int len, unsigned int seed)
{
  unsigned int v4; // r9
  unsigned int v5; // ctr
  int v6; // r7
  int v7; // r6
  int v8; // r5
  int v9; // r3
  int v10; // r9
  unsigned int v11; // r6

  v4 = len ^ seed;
  if ( (int)len >= 4 )
  {
    v5 = len >> 2;
    len -= len & 0xFFFFFFFC;
    do
    {
      v6 = 1540483477 * v4;
      v7 = key[2];
      v8 = key[1];
      v9 = *key;
      v10 = __ROL4__(key[3], 8);
      key += 4;
      v11 = 1540483477 * (((((v10 | v7) << 8) | v8) << 8) | v9);
      v4 = (1540483477 * (HIBYTE(v11) ^ v11)) ^ v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  switch ( len )
  {
    case 1u:
      goto LABEL_9;
    case 2u:
LABEL_8:
      v4 ^= __ROL4__(key[1], 8);
LABEL_9:
      v4 = 1540483477 * (*key ^ v4);
      return ((1540483477 * ((v4 >> 13) ^ v4)) >> 15) ^ (1540483477 * ((v4 >> 13) ^ v4));
    case 3u:
      v4 ^= __ROL4__(key[2], 16);
      goto LABEL_8;
    default:
      break;
  }
  return ((1540483477 * ((v4 >> 13) ^ v4)) >> 15) ^ (1540483477 * ((v4 >> 13) ^ v4));
}


// ========================================================================
// ?MurMur64_HashData@@YA_KPBXHI@Z
// EA  : 0x82F2CC80
// RVA : 0x00F2CC80
// PDB : w:\tech5\shared\idlib\hashing\murmur.cpp
// ========================================================================

unsigned int __fastcall MurMur64_HashData(int *key, int len, unsigned int seed)
{
  unsigned int v4; // r8
  unsigned int v5; // r9
  unsigned int v6; // ctr
  int v7; // r6
  _DWORD *v8; // r10
  unsigned int v9; // r7
  unsigned int v10; // r6
  unsigned int v11; // r5

  v4 = len ^ seed;
  v5 = 0;
  if ( len >= 8 )
  {
    v6 = (unsigned int)len >> 3;
    len -= len & 0xFFFFFFF8;
    do
    {
      v7 = *key;
      v8 = key + 1;
      v9 = 1540483477 * (((unsigned int)(1540483477 * v7) >> 24) ^ (1540483477 * v7));
      v10 = 1540483477 * (((unsigned int)(1540483477 * *v8) >> 24) ^ (1540483477 * *v8));
      v4 = v9 ^ (1540483477 * v4);
      key = v8 + 1;
      v5 = v10 ^ (1540483477 * v5);
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( len >= 4 )
  {
    v11 = 1540483477 * *key++;
    len -= 4;
    v4 = (1540483477 * (HIBYTE(v11) ^ v11)) ^ (1540483477 * v4);
  }
  switch ( len )
  {
    case 1:
      goto LABEL_11;
    case 2:
LABEL_10:
      v5 ^= __ROL4__(*((unsigned __int8 *)key + 1), 8);
LABEL_11:
      v5 = 1540483477 * (*(unsigned __int8 *)key ^ v5);
      return 1540483477
           * (((1540483477
              * (((1540483477 * (((1540483477 * ((v5 >> 18) ^ v4)) >> 22) ^ v5)) >> 17)
               ^ (1540483477 * ((v5 >> 18) ^ v4)))) >> 19)
            ^ (1540483477 * (((1540483477 * ((v5 >> 18) ^ v4)) >> 22) ^ v5)));
    case 3:
      v5 ^= __ROL4__(*((unsigned __int8 *)key + 2), 16);
      goto LABEL_10;
    default:
      break;
  }
  return 1540483477
       * (((1540483477
          * (((1540483477 * (((1540483477 * ((v5 >> 18) ^ v4)) >> 22) ^ v5)) >> 17) ^ (1540483477 * ((v5 >> 18) ^ v4)))) >> 19)
        ^ (1540483477 * (((1540483477 * ((v5 >> 18) ^ v4)) >> 22) ^ v5)));
}

