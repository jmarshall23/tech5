
// ========================================================================
// ?IsEdited@idVoiceTrack@@QBA_NXZ
// EA  : 0x8262D398
// RVA : 0x0062D398
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.h
// ========================================================================

int __fastcall idVoiceTrack::IsEdited(idVoiceTrack *this)
{
  int v1; // r3
  unsigned __int8 v2; // r11

  if ( (*(_BYTE *)&this->flags & 4) != 0 )
    return 1;
  v1 = idVoiceEventManager::NumEventType(this: &this->voiceEventManager, type: VOICEEVENT_ANIM);
  v2 = 0;
  if ( v1 > 0 )
    return 1;
  return v2;
}


// ========================================================================
// ?GetResourceList@idVoiceTrack@@UBAPAVidResourceList@@XZ
// EA  : 0x826388A8
// RVA : 0x006388A8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.h
// ========================================================================

idTypedResourceList<idVoiceTrack> *__fastcall idVoiceTrack::GetResourceList(idVoiceTrack *this)
{
  return &idVoiceTrack::resourceList;
}

