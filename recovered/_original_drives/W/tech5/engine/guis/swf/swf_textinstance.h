
// ========================================================================
// ?GetSoundClip@idSWFTextInstance@@QBA?AVidStr@@XZ
// EA  : 0x8277FBB0
// RVA : 0x0077FBB0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.h
// ========================================================================

idSWFTextInstance *__fastcall idSWFTextInstance::GetSoundClip(idSWFTextInstance *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 228));
  return this;
}


// ========================================================================
// ?GetSpeaker@idSWFTextInstance@@QBA?AVidStr@@XZ
// EA  : 0x8277FBE8
// RVA : 0x0077FBE8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.h
// ========================================================================

idSWFTextInstance *__fastcall idSWFTextInstance::GetSpeaker(idSWFTextInstance *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (const char *)result[12].len);
  return this;
}


// ========================================================================
// ?SetText@idSWFTextInstance@@QAAXVidStr@@@Z
// EA  : 0x82DA2770
// RVA : 0x00DA2770
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.h
// ========================================================================

void __fastcall idSWFTextInstance::SetText(idSWFTextInstance *this, idStr *val)
{
  int len; // r29

  len = val->len;
  idStr::EnsureAlloced(this: &this->text, amount: val->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->text.data, Src: val->data, Size: len);
  this->text.data[len] = 0;
  this->text.len = len;
  idStr::FreeData(this: val);
}


// ========================================================================
// __unwind$510194
// EA  : 0x82DA27D4
// RVA : 0x00DA27D4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.h
// ========================================================================

void _unwind_510194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 156));
}

