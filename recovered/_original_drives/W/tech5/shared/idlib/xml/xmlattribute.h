
// ========================================================================
// ??0idXMLAttribute@@QAA@PBD0@Z
// EA  : 0x82647DD0
// RVA : 0x00647DD0
// PDB : w:\tech5\shared\idlib\xml\xmlattribute.h
// ========================================================================

idXMLAttribute *__fastcall idXMLAttribute::idXMLAttribute(idXMLAttribute *this, const char *name, const char *value)
{
  idStr::idStr(this: &this->name, text: name);
  idStr::idStr(this: &this->value, text: value);
  idStr::StripLeadingWhiteSpace(this: &this->name);
  idStr::StripTrailingWhitespace(this: &this->name);
  return this;
}


// ========================================================================
// __unwind$224712
// EA  : 0x82647E18
// RVA : 0x00647E18
// PDB : w:\tech5\shared\idlib\xml\xmlattribute.h
// ========================================================================

void _unwind_224712()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$224713
// EA  : 0x82647E40
// RVA : 0x00647E40
// PDB : w:\tech5\shared\idlib\xml\xmlattribute.h
// ========================================================================

void _unwind_224713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}

