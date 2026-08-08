
// ========================================================================
// ??0idTypeInfoObject@@QAA@PAXPBDPBVidTypeInfoTools@@@Z
// EA  : 0x82647E78
// RVA : 0x00647E78
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.h
// ========================================================================

idTypeInfoObject *__fastcall idTypeInfoObject::idTypeInfoObject(
        idTypeInfoObject *this,
        void *objectPtr,
        const char *objectType,
        const idTypeInfoTools *ti)
{
  this->objectType.len = 0;
  this->objectType.data = this->objectType.baseBuffer;
  this->objectType.allocedAndFlag = 20;
  this->objectType.baseBuffer[0] = 0;
  this->objectPtr = objectPtr;
  idStr::operator=(this: &this->objectType, text: objectType);
  this->ti = ti;
  this->modified = false;
  return this;
}


// ========================================================================
// __unwind$224735
// EA  : 0x82647ED8
// RVA : 0x00647ED8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.h
// ========================================================================

void _unwind_224735()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}

