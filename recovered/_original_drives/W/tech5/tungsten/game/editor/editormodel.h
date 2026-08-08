
// ========================================================================
// ?GetMD6Tree@idEditorModelEntity@@UBAPBVidMD6Node@@XZ
// EA  : 0x82BDA358
// RVA : 0x00BDA358
// PDB : w:\tech5\tungsten\game\editor\editormodel.h
// ========================================================================

idMD6Leaf *__fastcall idEditorModelEntity::GetMD6Tree(idEditorModelEntity *this)
{
  return this->leaf;
}


// ========================================================================
// ?GetAttachments@idEditorModelEntity@@UAAPAVidAttachmentCollection@@XZ
// EA  : 0x82BDA360
// RVA : 0x00BDA360
// PDB : w:\tech5\tungsten\game\editor\editormodel.h
// ========================================================================

const idAttachmentCollection *__fastcall idEditorModelEntity::GetAttachments(idEditorModelEntity *this)
{
  return &this->attachments;
}

