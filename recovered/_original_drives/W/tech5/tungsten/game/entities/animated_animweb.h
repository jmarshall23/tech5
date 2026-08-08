
// ========================================================================
// XGComparePixelShaders
// EA  : 0x825411C8
// RVA : 0x005411C8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.h
// ========================================================================

int __fastcall XGComparePixelShaders()
{
  return 1;
}


// ========================================================================
// ?GetInventory@idAnimated_AnimWeb@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x825411D0
// RVA : 0x005411D0
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.h
// ========================================================================

const idInventoryCollection *__fastcall idAnimated_AnimWeb::GetInventory(idAnimated_AnimWeb *this)
{
  return &this->inventory;
}


// ========================================================================
// ?GetAttachments@idAnimated_AnimWeb@@UBAPBVidAttachmentCollection@@XZ
// EA  : 0x825411D8
// RVA : 0x005411D8
// PDB : w:\tech5\tungsten\game\entities\animated_animweb.h
// ========================================================================

const idAttachmentCollection *__fastcall idAnimated_AnimWeb::GetAttachments(idAnimated_AnimWeb *this)
{
  return &this->attachments;
}

