
// ========================================================================
// ??0idDeclOnlineFiction@@QAA@XZ
// EA  : 0x82BC9820
// RVA : 0x00BC9820
// PDB : w:\tech5\tungsten\game\decls\declonlinefiction.cpp
// ========================================================================

idDeclOnlineFiction *__fastcall idDeclOnlineFiction::idDeclOnlineFiction(idDeclOnlineFiction *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->voiceOver = nullptr;
  this->__vftable = (idDeclOnlineFiction_vtbl *)&idDeclOnlineFiction::`vftable';
  this->voiceOverTalkerName.index = -1;
  this->fxCondition = FX_NONE;
  this->hasPlayed = false;
  return this;
}


// ========================================================================
// ?PlayVO@idDeclOnlineFiction@@QBAHPAVidPresentable@@E@Z
// EA  : 0x82BC98F0
// RVA : 0x00BC98F0
// PDB : w:\tech5\tungsten\game\decls\declonlinefiction.cpp
// ========================================================================

int __fastcall idDeclOnlineFiction::PlayVO(idDeclOnlineFiction *this, idPresentable *target, unsigned __int8 peerMask)
{
  int index; // r11
  const idDeclVoiceOver *voiceOver; // r4
  idStrId v9; // [sp+50h] [-D0h] BYREF
  soundShaderParms_t v10; // [sp+60h] [-C0h] BYREF

  index = this->voiceOverTalkerName.index;
  this->hasPlayed = true;
  v9.index = index;
  soundShaderParms_t::Clear(this: &v10);
  voiceOver = this->voiceOver;
  v10.soundShaderFlags = 0;
  return idSound::PlayVoiceOverSound(
           channel: SND_CHANNEL_VOICE,
           voiceOver,
           parms: &v10,
           whoStartedMe: nullptr,
           target,
           voTalkerName: &v9,
           peerMask);
}

