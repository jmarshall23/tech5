
// ========================================================================
// ??1idSeenBits@@QAA@XZ
// EA  : 0x82971880
// RVA : 0x00971880
// PDB : w:\tech5\engine\renderer\seenbits.cpp
// ========================================================================

void __fastcall idSeenBits::~idSeenBits(idSeenBits *this)
{
  unsigned __int8 *bits; // r4

  bits = this->bits;
  if ( bits != nullptr )
    idMem::Free(this: &mem, ptr: bits, align: ALIGN_16);
  memset(Dst: this, Val: 0, Size: sizeof(idSeenBits));
}

