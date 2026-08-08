
// ========================================================================
// ??0?$idTokenStatic@$0BAA@@@QAA@ABVidStr@@@Z
// EA  : 0x828035B0
// RVA : 0x008035B0
// PDB : w:\tech5\shared\idlib\text\tokenstatic.h
// ========================================================================

idTokenStatic<256> *__fastcall idTokenStatic<256>::idTokenStatic<256>(idTokenStatic<256> *this, const idStr *text)
{
  int len; // r28

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->intvalue = 0;
  this->floatvalue = -3.4028235e38;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->next = nullptr;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483392;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$231012
// EA  : 0x82803650
// RVA : 0x00803650
// PDB : w:\tech5\shared\idlib\text\tokenstatic.h
// ========================================================================

void _unwind_231012()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}

