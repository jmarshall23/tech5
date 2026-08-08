
// ========================================================================
// ?GetName@idLayer@@QBA?AVidStr@@XZ
// EA  : 0x82F4A728
// RVA : 0x00F4A728
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconsumer.h
// ========================================================================

idLayer *__fastcall idLayer::GetName(idLayer *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (const idStr *)&result->data);
  return this;
}

