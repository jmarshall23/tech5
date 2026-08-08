
// ========================================================================
// ?CRC32_UpdateChecksum@@YAXAAKPBXH@Z
// EA  : 0x82F2BE48
// RVA : 0x00F2BE48
// PDB : w:\tech5\shared\idlib\hashing\crc32.cpp
// ========================================================================

void __fastcall CRC32_UpdateChecksum(unsigned int *crcvalue, char *data, int length)
{
  unsigned int v3; // r11
  int v4; // ctr
  char *v5; // r10

  v3 = *crcvalue;
  if ( length != 0 )
  {
    v4 = length;
    v5 = data - 1;
    do
    {
      v3 = *(unsigned int *)((char *)crctable_0 + ((4 * ((unsigned __int8)*++v5 ^ v3)) & 0x3FC)) ^ (v3 >> 8);
      --v4;
    }
    while ( v4 != 0 );
  }
  *crcvalue = v3;
}


// ========================================================================
// ?CRC32_FinishChecksum@@YAXAAK@Z
// EA  : 0x82F2BE90
// RVA : 0x00F2BE90
// PDB : w:\tech5\shared\idlib\hashing\crc32.cpp
// ========================================================================

void __fastcall CRC32_FinishChecksum(unsigned int *crcvalue)
{
  *crcvalue = ~*crcvalue;
}


// ========================================================================
// ?CRC32_BlockChecksum@@YAKPBXH@Z
// EA  : 0x82F2BEA0
// RVA : 0x00F2BEA0
// PDB : w:\tech5\shared\idlib\hashing\crc32.cpp
// ========================================================================

int __fastcall CRC32_BlockChecksum(char *data, int length)
{
  unsigned int v2; // r11
  int v3; // ctr
  char *v4; // r10

  v2 = -1;
  if ( length != 0 )
  {
    v3 = length;
    v4 = data - 1;
    do
    {
      v2 = *(unsigned int *)((char *)crctable_0 + ((4 * ((unsigned __int8)*++v4 ^ v2)) & 0x3FC)) ^ (v2 >> 8);
      --v3;
    }
    while ( v3 != 0 );
  }
  return ~v2;
}

