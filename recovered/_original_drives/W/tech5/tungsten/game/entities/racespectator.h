
// ========================================================================
// ??1idAnimWebSpectator@@UAA@XZ
// EA  : 0x82CACE10
// RVA : 0x00CACE10
// PDB : w:\tech5\tungsten\game\entities\racespectator.h
// ========================================================================

void __fastcall idAnimWebSpectator::~idAnimWebSpectator(idAnimWebSpectator *this)
{
  this->__vftable = (idAnimWebSpectator_vtbl *)&idAnimWebSpectator::`vftable';
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this);
}


// ========================================================================
// ?GetAttachments@idRaceSpectator@@UBAPBVidAttachmentCollection@@XZ
// EA  : 0x82CAD610
// RVA : 0x00CAD610
// PDB : w:\tech5\tungsten\game\entities\racespectator.h
// ========================================================================

const idAttachmentCollection *__fastcall idRaceSpectator::GetAttachments(idRaceSpectator *this)
{
  return &this->attachments;
}

