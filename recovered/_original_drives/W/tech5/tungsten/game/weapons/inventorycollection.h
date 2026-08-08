
// ========================================================================
// ??1idInventorySerializeLock@@QAA@XZ
// EA  : 0x82B58720
// RVA : 0x00B58720
// PDB : w:\tech5\tungsten\game\weapons\inventorycollection.h
// ========================================================================

void __fastcall idInventorySerializeLock::~idInventorySerializeLock(idInventorySerializeLock *this)
{
  this->inv->net_serializeInventoryChanges = (_cntlzw(this->lock) & 0x20) != 0;
}

