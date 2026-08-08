
// ========================================================================
// ??0emailData_t@@QAA@XZ
// EA  : 0x8289D6E0
// RVA : 0x0089D6E0
// PDB : w:\tech5\engine\network\smtp.h
// ========================================================================

emailData_t *__fastcall emailData_t::emailData_t(emailData_t *this)
{
  idStr::idStr(this: &this->server, text: "sweuppexch01.ad.machinegames.com");
  this->subject.len = 0;
  this->subject.allocedAndFlag = 20;
  this->subject.data = this->subject.baseBuffer;
  this->subject.baseBuffer[0] = 0;
  this->senderName.allocedAndFlag = 20;
  this->senderName.len = 0;
  this->senderName.data = this->senderName.baseBuffer;
  this->senderName.baseBuffer[0] = 0;
  this->senderEmail.allocedAndFlag = 20;
  this->senderEmail.len = 0;
  this->senderEmail.data = this->senderEmail.baseBuffer;
  this->senderEmail.baseBuffer[0] = 0;
  this->recipientEmail.granularity = 0;
  this->recipientEmail.listStatic = 0;
  this->recipientEmail.memTag = 5;
  this->recipientEmail.list = nullptr;
  this->recipientEmail.size = 0;
  this->recipientEmail.num = 0;
  this->body.data = this->body.baseBuffer;
  this->body.allocedAndFlag = 20;
  this->body.len = 0;
  this->body.baseBuffer[0] = 0;
  this->attachment.allocedAndFlag = 20;
  this->attachment.data = this->attachment.baseBuffer;
  this->attachment.len = 0;
  this->attachment.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$220502
// EA  : 0x8289D7C8
// RVA : 0x0089D7C8
// PDB : w:\tech5\engine\network\smtp.h
// ========================================================================

void _unwind_220502()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$220503
// EA  : 0x8289D7F0
// RVA : 0x0089D7F0
// PDB : w:\tech5\engine\network\smtp.h
// ========================================================================

void _unwind_220503()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$220504
// EA  : 0x8289D81C
// RVA : 0x0089D81C
// PDB : w:\tech5\engine\network\smtp.h
// ========================================================================

void _unwind_220504()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$220505
// EA  : 0x8289D848
// RVA : 0x0089D848
// PDB : w:\tech5\engine\network\smtp.h
// ========================================================================

void _unwind_220505()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}

