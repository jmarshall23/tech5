
// ========================================================================
// ??B?$idPresentablePtr@VidPresentablePlayer@@@@QBAPAVidPresentablePlayer@@XZ
// EA  : 0x82B4F3A8
// RVA : 0x00B4F3A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr.h
// ========================================================================

// attributes: thunk
idPresentablePlayer *__fastcall idPresentablePtr<idPresentablePlayer>::operator idPresentablePlayer *(
        idPresentablePtr<idPresentablePlayer> *this)
{
  return idPresentablePtr<idPresentablePlayer>::GetPresentable(this);
}


// ========================================================================
// ?Serialize@netBoolEvent_t@@QAAXAAVidSerializer@@@Z
// EA  : 0x82B72780
// RVA : 0x00B72780
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr.h
// ========================================================================

void __fastcall netBoolEvent_t::Serialize(netBoolEvent_t *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  unsigned int v5; // r10

  if ( this->count >= 7 )
    idLib::Warning(fmt: "netBoolEvent_t. count %d > max %d", this->count, 7);
  msg = ser->msg;
  v5 = _cntlzw(7u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->count, numBits: 32 - v5);
  else
    this->count = idBitMsg::ReadBits(this: msg, numBits: 32 - v5);
}

