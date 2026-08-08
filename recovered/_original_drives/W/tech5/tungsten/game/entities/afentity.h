
// ========================================================================
// ?IsDead@idAFEntity_Dummy@@UBA_NXZ
// EA  : 0x82BEE858
// RVA : 0x00BEE858
// PDB : w:\tech5\tungsten\game\entities\afentity.h
// ========================================================================

unsigned int __fastcall idAFEntity_Dummy::IsDead(idAFEntity_Dummy *this)
{
  return (this->numHitsToKill | (unsigned int)(this->numHitsToKill - 1)) >> 31;
}


// ========================================================================
// ?GetAttachments@idAFEntity_Dummy@@UBAPBVidAttachmentCollection@@XZ
// EA  : 0x82BEE870
// RVA : 0x00BEE870
// PDB : w:\tech5\tungsten\game\entities\afentity.h
// ========================================================================

const idAttachmentCollection *__fastcall idAFEntity_Dummy::GetAttachments(idAFEntity_Dummy *this)
{
  return &this->attachments;
}

