
// ========================================================================
// ?CRC16_UpdateChecksum@@YAXAAGPBXH@Z
// EA  : 0x82F2BE00
// RVA : 0x00F2BE00
// PDB : w:\tech5\shared\idlib\hashing\crc16.cpp
// ========================================================================

void __fastcall CRC16_UpdateChecksum(unsigned __int16 *crcvalue, char *data, int length)
{
  unsigned __int16 v3; // r11
  int v4; // ctr
  char *v5; // r10

  v3 = *crcvalue;
  if ( length != 0 )
  {
    v4 = length;
    v5 = data - 1;
    do
    {
      v3 = crctable[HIBYTE(v3) ^ (unsigned __int8)*++v5] ^ (v3 << 8);
      --v4;
    }
    while ( v4 != 0 );
  }
  *crcvalue = v3;
}

