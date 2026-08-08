
// ========================================================================
// ??1?$idLinkList@VidWaypoint@@@@QAA@XZ
// EA  : 0x82C3DBE0
// RVA : 0x00C3DBE0
// PDB : w:\tech5\shared\idlib\containers\linklist.h
// ========================================================================

// attributes: thunk
void __fastcall idLinkList<idWaypoint>::~idLinkList<idWaypoint>(idLinkList<idProp_VehiclePickup> *this)
{
  idLinkList<idEvent>::Clear(this);
}


// ========================================================================
// ?Clear@?$idLinkList@VidEvent@@@@QAAXXZ
// EA  : 0x82C6E5C0
// RVA : 0x00C6E5C0
// PDB : w:\tech5\shared\idlib\containers\linklist.h
// ========================================================================

void __fastcall idLinkList<idEvent>::Clear(idLinkList<idProp_VehiclePickup> *this)
{
  idLinkList<idProp_VehiclePickup> *next; // r11

  if ( this->head == this )
  {
    for ( ; this->next != this; next->head = next )
    {
      next = this->next;
      next->prev->next = next->next;
      next->next->prev = next->prev;
      next->next = next;
      next->prev = next;
    }
  }
  else
  {
    this->prev->next = this->next;
    this->next->prev = this->prev;
    this->next = this;
    this->prev = this;
    this->head = this;
  }
}

