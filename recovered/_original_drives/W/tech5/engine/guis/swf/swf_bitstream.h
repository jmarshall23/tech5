
// ========================================================================
// ??1idSWFBitStream@@QAA@XZ
// EA  : 0x82561458
// RVA : 0x00561458
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.h
// ========================================================================

// attributes: thunk
void __fastcall idSWFBitStream::~idSWFBitStream(idSWFBitStream *this)
{
  idSWFBitStream::Free(this);
}


// ========================================================================
// ?ReadDouble@idSWFBitStream@@QAANXZ
// EA  : 0x82784E00
// RVA : 0x00784E00
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.h
// ========================================================================

double __fastcall idSWFBitStream::ReadDouble(
        idSWFBitStream *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *Data; // r3
  double v9; // [sp+50h] [-10h]

  Data = idSWFBitStream::ReadData(this, size: 8, a3, a4, a5, a6, a7);
  HIBYTE(v9) = Data[3];
  BYTE1(v9) = Data[2];
  BYTE2(v9) = Data[1];
  BYTE3(v9) = *Data;
  LOBYTE(v9) = Data[4];
  BYTE6(v9) = Data[5];
  BYTE5(v9) = Data[6];
  BYTE4(v9) = Data[7];
  return v9;
}

