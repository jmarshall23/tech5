
// ========================================================================
// ?Write@idLZWCompressor@@QAAHPBXH@Z
// EA  : 0x82658AE0
// RVA : 0x00658AE0
// PDB : w:\tech5\engine\network\lightweightcompression.h
// ========================================================================

int __fastcall idLZWCompressor::Write(idLZWCompressor *this, _BYTE *data, int length)
{
  int i; // r31

  for ( i = 0; i < length; ++i )
  {
    if ( this->overflowed )
      break;
    idLZWCompressor::WriteByte(this, value: data[i]);
  }
  return length;
}


// ========================================================================
// ??$ReadAgnostic@G@idLZWCompressor@@QAAIAAG_N@Z
// EA  : 0x826594B8
// RVA : 0x006594B8
// PDB : w:\tech5\engine\network\lightweightcompression.h
// ========================================================================

int __fastcall idLZWCompressor::ReadAgnostic<unsigned short>(
        idLZWCompressor *this,
        unsigned __int16 *c,
        bool ignoreOverflow)
{
  int v5; // r31
  unsigned __int16 *v6; // r30
  int Byte; // r3

  v5 = 0;
  v6 = c + 1;
  while ( 1 )
  {
    Byte = idLZWCompressor::ReadByte(this, ignoreOverflow);
    if ( Byte == -1 )
      break;
    ++v5;
    v6 = (unsigned __int16 *)((char *)v6 - 1);
    *(_BYTE *)v6 = Byte;
    if ( v5 >= 2 )
      return 2;
  }
  return v5;
}


// ========================================================================
// ?Read@idLZWCompressor@@QAAHPAXH_N@Z
// EA  : 0x8289B268
// RVA : 0x0089B268
// PDB : w:\tech5\engine\network\lightweightcompression.h
// ========================================================================

int __fastcall idLZWCompressor::Read(idLZWCompressor *this, _BYTE *data, int length, bool ignoreOverflow)
{
  int v8; // r31
  int Byte; // r3

  v8 = 0;
  if ( length <= 0 )
    return length;
  while ( 1 )
  {
    Byte = idLZWCompressor::ReadByte(this, ignoreOverflow);
    if ( Byte == -1 )
      break;
    data[v8] = Byte;
    if ( ++v8 >= length )
      return length;
  }
  return v8;
}


// ========================================================================
// ??$ReadAgnostic@I@idLZWCompressor@@QAAIAAI_N@Z
// EA  : 0x8289E540
// RVA : 0x0089E540
// PDB : w:\tech5\engine\network\lightweightcompression.h
// ========================================================================

int __fastcall idLZWCompressor::ReadAgnostic<unsigned int>(idLZWCompressor *this, int *c, bool ignoreOverflow)
{
  int v5; // r31
  int *v6; // r30
  int Byte; // r3

  v5 = 0;
  v6 = c + 1;
  while ( 1 )
  {
    Byte = idLZWCompressor::ReadByte(this, ignoreOverflow);
    if ( Byte == -1 )
      break;
    ++v5;
    v6 = (int *)((char *)v6 - 1);
    *(_BYTE *)v6 = Byte;
    if ( v5 >= 4 )
      return 4;
  }
  return v5;
}

