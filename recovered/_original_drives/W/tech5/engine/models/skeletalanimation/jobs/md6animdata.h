
// ========================================================================
// ?NumCompressedUserChannels@idMD6AnimData@@QBAHH@Z
// EA  : 0x826DFBB8
// RVA : 0x006DFBB8
// PDB : w:\tech5\engine\models\skeletalanimation\jobs\md6animdata.h
// ========================================================================

int __fastcall idMD6AnimData::NumCompressedUserChannels(idMD6AnimData *this, const int animMapIndex)
{
  int v2; // r11

  if ( (this->flags & 0x800) != 0 )
    v2 = *((unsigned __int8 *)&this->totalSize + *((unsigned __int16 *)this + 8 * animMapIndex + this->numAnimMaps + 67));
  else
    v2 = 0;
  if ( (this->flags & 0x800) != 0 )
    return *((unsigned __int8 *)&this->totalSize
           + *((unsigned __int16 *)this + 8 * animMapIndex + this->numAnimMaps + 71))
         + v2;
  else
    return v2;
}

