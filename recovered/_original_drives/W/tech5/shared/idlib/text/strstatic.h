
// ========================================================================
// ??0?$idStrStatic@$0EA@@@QAA@XZ
// EA  : 0x82561860
// RVA : 0x00561860
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idPlayerProfileGame::profileLoadout_t *__fastcall idStrStatic<64>::idStrStatic<64>(
        idPlayerProfileGame::profileLoadout_t *this)
{
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->name.data = this->name.buffer;
  this->name.buffer[0] = 0;
  this->name.len = 0;
  this->name.allocedAndFlag = -2147483584;
  return this;
}


// ========================================================================
// ??0?$idStrStatic@$0IA@@@QAA@XZ
// EA  : 0x82561890
// RVA : 0x00561890
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<128> *__fastcall idStrStatic<128>::idStrStatic<128>(idStrStatic<128> *this)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->data = this->buffer;
  this->buffer[0] = 0;
  this->len = 0;
  this->allocedAndFlag = -2147483520;
  return this;
}


// ========================================================================
// ??0?$idStrStatic@$0BAA@@@QAA@PBD@Z
// EA  : 0x826250A8
// RVA : 0x006250A8
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<256> *__fastcall idStrStatic<256>::idStrStatic<256>(idStrStatic<256> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483392;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$223314
// EA  : 0x82625114
// RVA : 0x00625114
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_223314()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0BAA@@@QAA@ABV0@@Z
// EA  : 0x8264E5E8
// RVA : 0x0064E5E8
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<256> *__fastcall idStrStatic<256>::idStrStatic<256>(idStrStatic<256> *this, const idStr *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
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
// __unwind$224559
// EA  : 0x8264E66C
// RVA : 0x0064E66C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_224559()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0IA@@@QAA@PBD@Z
// EA  : 0x82651460
// RVA : 0x00651460
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<128> *__fastcall idStrStatic<128>::idStrStatic<128>(idStrStatic<128> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483520;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$225167
// EA  : 0x826514CC
// RVA : 0x006514CC
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_225167()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0EAA@@@QAA@PBD@Z
// EA  : 0x82651500
// RVA : 0x00651500
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<1024> *__fastcall idStrStatic<1024>::idStrStatic<1024>(idStrStatic<1024> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147482624;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$225256_1
// EA  : 0x8265156C
// RVA : 0x0065156C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_225256_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0EAA@@@QAA@ABV0@@Z
// EA  : 0x82651C78
// RVA : 0x00651C78
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<1024> *__fastcall idStrStatic<1024>::idStrStatic<1024>(idStrStatic<1024> *this, const idStr *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147482624;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$225913
// EA  : 0x82651CFC
// RVA : 0x00651CFC
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_225913()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0DOI@@@QAA@PBD@Z
// EA  : 0x8265E010
// RVA : 0x0065E010
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<1000> *__fastcall idStrStatic<1000>::idStrStatic<1000>(idStrStatic<1000> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147482648;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$232684
// EA  : 0x8265E07C
// RVA : 0x0065E07C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_232684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0EA@@@QAA@ABVidStr@@@Z
// EA  : 0x8265E198
// RVA : 0x0065E198
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<64> *__fastcall idStrStatic<64>::idStrStatic<64>(idStrStatic<64> *this, const idStr *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483584;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$233321
// EA  : 0x8265E21C
// RVA : 0x0065E21C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_233321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0IA@@@QAA@ABVidStr@@@Z
// EA  : 0x8265E250
// RVA : 0x0065E250
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<128> *__fastcall idStrStatic<128>::idStrStatic<128>(idStrStatic<128> *this, const idStrStatic<128> *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483520;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$234328
// EA  : 0x8265E2D4
// RVA : 0x0065E2D4
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_234328()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0IAA@@@QAA@ABV0@@Z
// EA  : 0x8265EFB0
// RVA : 0x0065EFB0
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<2048> *__fastcall idStrStatic<2048>::idStrStatic<2048>(
        idStrStatic<2048> *this,
        const idStrStatic<2048> *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147481600;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$234388
// EA  : 0x8265F034
// RVA : 0x0065F034
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_234388()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0PL@@@QAA@ABVidStr@@@Z
// EA  : 0x8265F068
// RVA : 0x0065F068
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<251> *__fastcall idStrStatic<251>::idStrStatic<251>(idStrStatic<251> *this, const idStr *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483397;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$234448
// EA  : 0x8265F0EC
// RVA : 0x0065F0EC
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_234448()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0BA@@@QAA@PBD@Z
// EA  : 0x82698380
// RVA : 0x00698380
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<16> *__fastcall idStrStatic<16>::idStrStatic<16>(idStrStatic<16> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483632;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$246142
// EA  : 0x826983EC
// RVA : 0x006983EC
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_246142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0CAA@@@QAA@PBD@Z
// EA  : 0x826A6BF0
// RVA : 0x006A6BF0
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<512> *__fastcall idStrStatic<512>::idStrStatic<512>(idStrStatic<512> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483136;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$219900
// EA  : 0x826A6C5C
// RVA : 0x006A6C5C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_219900()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0EA@@@QAA@PBD@Z
// EA  : 0x829A33B0
// RVA : 0x009A33B0
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<64> *__fastcall idStrStatic<64>::idStrStatic<64>(idStrStatic<64> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483584;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$221435
// EA  : 0x829A341C
// RVA : 0x009A341C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_221435()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0PL@@@QAA@PBD@Z
// EA  : 0x829A3588
// RVA : 0x009A3588
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<251> *__fastcall idStrStatic<251>::idStrStatic<251>(idStrStatic<251> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483397;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$221664
// EA  : 0x829A35F4
// RVA : 0x009A35F4
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_221664()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$07@@QAA@PBD@Z
// EA  : 0x829BD0C0
// RVA : 0x009BD0C0
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<8> *__fastcall idStrStatic<8>::idStrStatic<8>(idStrStatic<8> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483640;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$229447
// EA  : 0x829BD12C
// RVA : 0x009BD12C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_229447()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$07@@QAA@ABV0@@Z
// EA  : 0x829DB488
// RVA : 0x009DB488
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<8> *__fastcall idStrStatic<8>::idStrStatic<8>(idStrStatic<8> *this, const idStrStatic<8> *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483640;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$228401
// EA  : 0x829DB50C
// RVA : 0x009DB50C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_228401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0IAA@@@QAA@PBD@Z
// EA  : 0x82DA2090
// RVA : 0x00DA2090
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<2048> *__fastcall idStrStatic<2048>::idStrStatic<2048>(idStrStatic<2048> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147481600;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$508872
// EA  : 0x82DA20FC
// RVA : 0x00DA20FC
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_508872()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0IAAA@@@QAA@ABVidStr@@@Z
// EA  : 0x82EFCB98
// RVA : 0x00EFCB98
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<32768> *__fastcall idStrStatic<32768>::idStrStatic<32768>(idStrStatic<32768> *this, const idStr *text)
{
  int len; // r29

  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147450880;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
  return this;
}


// ========================================================================
// __unwind$114146
// EA  : 0x82EFCC1C
// RVA : 0x00EFCC1C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_114146()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStrStatic@$0BAE@@@QAA@PBD@Z
// EA  : 0x82F08C98
// RVA : 0x00F08C98
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<260> *__fastcall idStrStatic<260>::idStrStatic<260>(idStrStatic<260> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483388;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$116185
// EA  : 0x82F08D04
// RVA : 0x00F08D04
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_116185()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStrStatic@$0CA@@@QAA@PBD@Z
// EA  : 0x82F1C230
// RVA : 0x00F1C230
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

idStrStatic<32> *__fastcall idStrStatic<32>::idStrStatic<32>(idStrStatic<32> *this, const char *text)
{
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  this->buffer[0] = 0;
  this->len = 0;
  this->data = this->buffer;
  this->allocedAndFlag = -2147483616;
  idStr::operator=(this, text);
  return this;
}


// ========================================================================
// __unwind$113135
// EA  : 0x82F1C29C
// RVA : 0x00F1C29C
// PDB : w:\tech5\shared\idlib\text\strstatic.h
// ========================================================================

void _unwind_113135()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}

