
// ========================================================================
// ?InternalCallEvent@idEventReceiver@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x824E2D40
// RVA : 0x004E2D40
// PDB : w:\tech5\tungsten\game\gamesys\eventreceiver.h
// ========================================================================

idEventReceiver *__fastcall idEventReceiver::InternalCallEvent(
        idEventReceiver *this,
        idEventArg *result,
        const idEventDef *event,
        const idEventArg *args)
{
  HIBYTE(this->__vftable) = 0;
  this->listenerList = nullptr;
  return this;
}

