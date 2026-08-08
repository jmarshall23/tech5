
// ========================================================================
// ??1MutexLock@internal@protobuf@google@@QAA@XZ
// EA  : 0x83223088
// RVA : 0x01223088
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.h
// ========================================================================

void __fastcall google::protobuf::internal::MutexLock::~MutexLock(google::protobuf::internal::MutexLock *this)
{
  RtlLeaveCriticalSection(CriticalSection: (PRTL_CRITICAL_SECTION)this->mu_->mInternal);
}


// ========================================================================
// ??0FatalException@protobuf@google@@QAA@PBDHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x832236C0
// RVA : 0x012236C0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.h
// ========================================================================

google::protobuf::FatalException *__fastcall google::protobuf::FatalException::FatalException(
        google::protobuf::FatalException *this,
        const char *filename,
        int line,
        const std::string *message)
{
  this->_Mywhat = nullptr;
  this->_Mydofree = false;
  this->filename_ = filename;
  this->line_ = line;
  this->__vftable = (google::protobuf::FatalException_vtbl *)&google::protobuf::FatalException::`vftable';
  this->message_._Myres = 15;
  this->message_._Mysize = 0;
  this->message_._Bx._Buf[0] = 0;
  std::string::assign(this: (std::string *)&this->message_, _Right: message, _Roff: 0, _Count: 0xFFFFFFFF);
  return this;
}


// ========================================================================
// __unwind$92945
// EA  : 0x83223744
// RVA : 0x01223744
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.h
// ========================================================================

void _unwind_92945()
{
  int v0; // r12

  std::exception::~exception(this: *(std::bad_alloc **)(v0 - 112 + 132));
}

