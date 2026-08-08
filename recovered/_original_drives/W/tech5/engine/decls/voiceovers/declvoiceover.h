
// ========================================================================
// ?GetTrack@idDeclVoiceOver@@QBAPBVidVoiceTrack@@H@Z
// EA  : 0x8262D3E8
// RVA : 0x0062D3E8
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.h
// ========================================================================

const idVoiceTrack *__fastcall idDeclVoiceOver::GetTrack(idDeclVoiceOver *this, int index)
{
  if ( index < 0 || index >= this->tracks.num )
    return nullptr;
  else
    return this->tracks.list[index];
}


// ========================================================================
// ?GetDeclInfo@idDeclVoiceOver@@UBAPAVidDeclInfo@@XZ
// EA  : 0x8262D908
// RVA : 0x0062D908
// PDB : w:\tech5\engine\decls\voiceovers\declvoiceover.h
// ========================================================================

idDeclInfoTemplate<idDeclVoiceOver> *__fastcall idDeclVoiceOver::GetDeclInfo(idDeclVoiceOver *this)
{
  return &idDeclVoiceOver::resourceList;
}

