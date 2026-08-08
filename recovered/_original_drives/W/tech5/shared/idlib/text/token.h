
// ========================================================================
// ??0idToken@@QAA@XZ
// EA  : 0x825AF7A8
// RVA : 0x005AF7A8
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

idToken *__fastcall idToken::idToken(idToken *this)
{
  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->floatvalue = -3.4028235e38;
  this->intvalue = 0;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->next = nullptr;
  return this;
}


// ========================================================================
// ?GetUnsignedIntValue@idToken@@QAAIXZ
// EA  : 0x825B00E0
// RVA : 0x005B00E0
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

unsigned int __fastcall idToken::GetUnsignedIntValue(idToken *this)
{
  if ( this->type != 3 )
    return 0;
  if ( (this->subtype & 0x10000) == 0 )
    idToken::NumberValue(this);
  return this->intvalue;
}


// ========================================================================
// ?GetFloatValue@idToken@@QAAMXZ
// EA  : 0x825F8B50
// RVA : 0x005F8B50
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

float __fastcall idToken::GetFloatValue(idToken *this)
{
  double floatvalue; // fp1

  if ( this->type == 3 )
  {
    if ( (this->subtype & 0x10000) == 0 )
      idToken::NumberValue(this);
    floatvalue = this->floatvalue;
  }
  else
  {
    floatvalue = 0.0;
  }
  return *((float *)&floatvalue + 1);
}


// ========================================================================
// ??0idToken@@QAA@ABV0@@Z
// EA  : 0x8262C560
// RVA : 0x0062C560
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

idToken *__fastcall idToken::idToken(idToken *this, const idToken *token)
{
  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->intvalue = 0;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->next = nullptr;
  this->floatvalue = -3.4028235e38;
  idToken::operator=(this, __that: token);
  return this;
}


// ========================================================================
// __unwind$221108
// EA  : 0x8262C5D8
// RVA : 0x0062C5D8
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

void _unwind_221108()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idToken@@QAA@PBD@Z
// EA  : 0x82939FB0
// RVA : 0x00939FB0
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

idToken *__fastcall idToken::idToken(idToken *this, const char *text)
{
  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->intvalue = 0;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->next = nullptr;
  this->floatvalue = -3.4028235e38;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$230621_0
// EA  : 0x8293A028
// RVA : 0x0093A028
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

void _unwind_230621_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?AppendDirty@idToken@@AAAXD@Z
// EA  : 0x82F88048
// RVA : 0x00F88048
// PDB : w:\tech5\shared\idlib\text\token.h
// ========================================================================

void __fastcall idToken::AppendDirty(idToken *this, char a)
{
  idStr::EnsureAlloced(this, amount: this->len + 2, keepold: true, geometricGrowth: false);
  this->data[this->len++] = a;
}

