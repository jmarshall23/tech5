
// ========================================================================
// ?GetDefaultChannelMask@idWaveFile@@SAIH@Z
// EA  : 0x8299F6E0
// RVA : 0x0099F6E0
// PDB : w:\tech5\engine\sound\files\wavefile.h
// ========================================================================

int __fastcall idWaveFile::GetDefaultChannelMask(int numChannels)
{
  _DWORD back_chain[8]; // [sp+0h] [-20h] BYREF

  back_chain[2] = 11;
  back_chain[3] = 51;
  back_chain[4] = 59;
  back_chain[5] = 63;
  back_chain[6] = 319;
  back_chain[7] = 1599;
  if ( numChannels <= 0 || numChannels > 8 )
    return (1 << numChannels) - 1;
  else
    return back_chain[numChannels - 1];
}


// ========================================================================
// ??1idWaveFile@@QAA@XZ
// EA  : 0x8299FCA8
// RVA : 0x0099FCA8
// PDB : w:\tech5\engine\sound\files\wavefile.h
// ========================================================================

void __fastcall idWaveFile::~idWaveFile(idWaveFile *this)
{
  idWaveFile::Close(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chunks);
}


// ========================================================================
// __unwind$225348
// EA  : 0x8299FCEC
// RVA : 0x0099FCEC
// PDB : w:\tech5\engine\sound\files\wavefile.h
// ========================================================================

void _unwind_225348()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}

