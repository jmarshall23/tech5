
// ========================================================================
// ?DefaultLogHandler@internal@protobuf@google@@YAXW4LogLevel@23@PBDHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x83223118
// RVA : 0x01223118
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::DefaultLogHandler(
        google::protobuf::LogLevel level,
        const char *filename,
        int line,
        const std::string *message)
{
  const std::string *Ptr; // r31
  const char *v7; // r28
  _iobuf *v8; // r3
  _iobuf *v9; // r3

  if ( message->_Myres < 0x10 )
    Ptr = message;
  else
    Ptr = (const std::string *)message->_Bx._Ptr;
  v7 = level_names[level];
  v8 = _iob_func();
  fprintf(str: v8 + 2, format: "libprotobuf %s %s:%d] %s\n", v7, filename, line, Ptr->_Bx._Buf);
  v9 = _iob_func();
  fflush(stream: v9 + 2);
}


// ========================================================================
// ?DeleteLogSilencerCount@internal@protobuf@google@@YAXXZ
// EA  : 0x83223190
// RVA : 0x01223190
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::DeleteLogSilencerCount(google::protobuf::internal *this, memTag_t a2)
{
  google::protobuf::internal::Mutex *v2; // r31
  memTag_t v3; // r4

  v2 = log_silencer_count_mutex_;
  if ( log_silencer_count_mutex_ != nullptr )
  {
    operator delete(p: log_silencer_count_mutex_->mInternal, tag: a2);
    operator delete(p: v2, tag: v3);
  }
  log_silencer_count_mutex_ = nullptr;
}


// ========================================================================
// ?what@FatalException@protobuf@google@@UBAPBDXZ
// EA  : 0x832231E8
// RVA : 0x012231E8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

const std::string *__fastcall google::protobuf::FatalException::what(google::protobuf::FatalException *this)
{
  const std::string *result; // r3

  result = &this->message_;
  if ( result->_Myres >= 0x10 )
    return (const std::string *)result->_Bx._Ptr;
  return result;
}


// ========================================================================
// ?InitShutdownFunctions@internal@protobuf@google@@YAXXZ
// EA  : 0x83223208
// RVA : 0x01223208
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::InitShutdownFunctions(google::protobuf::internal *this)
{
  std::vector<void (__cdecl*)(void),std::allocator<void (__cdecl*)(void)> > *v1; // r3
  std::vector<void (__cdecl*)(void),std::allocator<void (__cdecl*)(void)> > *v2; // r11
  google::protobuf::internal::Mutex *v3; // r29
  _RTL_CRITICAL_SECTION *v4; // r3

  v1 = (std::vector<void (__cdecl*)(void),std::allocator<void (__cdecl*)(void)> > *)operator new(s: 0x10u);
  if ( v1 != nullptr )
  {
    v2 = v1;
    v1->_Myfirst = nullptr;
    v1->_Mylast = nullptr;
    v1->_Myend = nullptr;
  }
  else
  {
    v2 = nullptr;
  }
  google::protobuf::internal::shutdown_functions = v2;
  v3 = (google::protobuf::internal::Mutex *)operator new(s: 4u);
  if ( v3 != nullptr )
  {
    v4 = (_RTL_CRITICAL_SECTION *)operator new(s: 0x1Cu);
    v3->mInternal = (google::protobuf::internal::Mutex::Internal *)v4;
    RtlInitializeCriticalSection(CriticalSection: v4);
    google::protobuf::internal::shutdown_functions_mutex = v3;
  }
  else
  {
    google::protobuf::internal::shutdown_functions_mutex = nullptr;
  }
}


// ========================================================================
// __unwind$91355
// EA  : 0x83223290
// RVA : 0x01223290
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall _unwind_91355(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0LogMessage@internal@protobuf@google@@QAA@W4LogLevel@23@PBDH@Z
// EA  : 0x83223368
// RVA : 0x01223368
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

google::protobuf::internal::LogMessage *__fastcall google::protobuf::internal::LogMessage::LogMessage(
        google::protobuf::internal::LogMessage *this,
        google::protobuf::LogLevel level,
        const char *filename,
        int line)
{
  this->level_ = level;
  this->filename_ = filename;
  this->line_ = line;
  this->message_._Myres = 15;
  this->message_._Mysize = 0;
  this->message_._Bx._Buf[0] = 0;
  return this;
}


// ========================================================================
// ??1LogMessage@internal@protobuf@google@@QAA@XZ
// EA  : 0x83223390
// RVA : 0x01223390
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::LogMessage::~LogMessage(
        google::protobuf::internal::LogMessage *this,
        memTag_t a2)
{
  std::string *p_message; // r31

  p_message = &this->message_;
  if ( this->message_._Myres >= 0x10 )
    operator delete(p: p_message->_Bx._Ptr, tag: a2);
  p_message->_Mysize = 0;
  p_message->_Myres = 15;
  p_message->_Bx._Buf[0] = 0;
}


// ========================================================================
// ??1FatalException@protobuf@google@@UAA@XZ
// EA  : 0x832233E0
// RVA : 0x012233E0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::FatalException::~FatalException(google::protobuf::FatalException *this, memTag_t a2)
{
  const std::string *p_message; // r30
  BOOL Mydofree; // r8

  p_message = &this->message_;
  this->__vftable = (google::protobuf::FatalException_vtbl *)&google::protobuf::FatalException::`vftable';
  if ( this->message_._Myres >= 0x10 )
    operator delete(p: p_message->_Bx._Ptr, tag: a2);
  p_message->_Mysize = 0;
  p_message->_Myres = 15;
  p_message->_Bx._Buf[0] = 0;
  Mydofree = this->_Mydofree;
  this->__vftable = (google::protobuf::FatalException_vtbl *)&std::exception::`vftable';
  if ( Mydofree )
    free(pBlock: (void *)this->_Mywhat);
  this->_Mywhat = nullptr;
  this->_Mydofree = false;
}


// ========================================================================
// ?OnShutdown@internal@protobuf@google@@YAXP6AXXZ@Z
// EA  : 0x83223608
// RVA : 0x01223608
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::OnShutdown(
        void (__fastcall *func)(),
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        void (__fastcall *a12)())
{
  google::protobuf::internal::Mutex *v12; // r30

  a12 = func;
  if ( !google::protobuf::internal::shutdown_functions_init.initialized_ )
    google::protobuf::ProtobufOnceType::Init(
      this: &google::protobuf::internal::shutdown_functions_init,
      init_func: (void (__fastcall *)())google::protobuf::internal::InitShutdownFunctions);
  v12 = google::protobuf::internal::shutdown_functions_mutex;
  RtlEnterCriticalSection(CriticalSection: &google::protobuf::internal::shutdown_functions_mutex->mInternal->mutex);
  std::vector<void (__cdecl *)(void),std::allocator<void (__cdecl *)(void)>>::push_back(
    this: google::protobuf::internal::shutdown_functions,
    _Val: &a12);
  RtlLeaveCriticalSection(CriticalSection: &v12->mInternal->mutex);
}


// ========================================================================
// __unwind$92717
// EA  : 0x8322368C
// RVA : 0x0122368C
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void _unwind_92717()
{
  int v0; // r12

  google::protobuf::internal::MutexLock::~MutexLock(this: (google::protobuf::internal::MutexLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?InitLogSilencerCount@internal@protobuf@google@@YAXXZ
// EA  : 0x83223778
// RVA : 0x01223778
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::InitLogSilencerCount(google::protobuf::internal *this)
{
  google::protobuf::internal::Mutex *v1; // r30
  int v2; // r9
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // r4
  _RTL_CRITICAL_SECTION *v8; // r3
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  void (__fastcall *v12)(); // [sp+14h] [-5Ch]

  v1 = (google::protobuf::internal::Mutex *)operator new(s: 4u);
  if ( v1 != nullptr )
  {
    v8 = (_RTL_CRITICAL_SECTION *)operator new(s: 0x1Cu);
    v1->mInternal = (google::protobuf::internal::Mutex::Internal *)v8;
    RtlInitializeCriticalSection(CriticalSection: v8);
  }
  else
  {
    v1 = nullptr;
  }
  log_silencer_count_mutex_ = v1;
  google::protobuf::internal::OnShutdown(
    func: (void (__fastcall *)())google::protobuf::internal::DeleteLogSilencerCount,
    a2: v7,
    a3: v6,
    a4: v5,
    a5: v4,
    a6: v3,
    a7: v2,
    a8: (int)&loc_83220000,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12);
}


// ========================================================================
// __unwind$93046
// EA  : 0x832237EC
// RVA : 0x012237EC
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall _unwind_93046(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?Finish@LogMessage@internal@protobuf@google@@AAAXXZ
// EA  : 0x83223818
// RVA : 0x01223818
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::LogMessage::Finish(google::protobuf::internal::LogMessage *this)
{
  unsigned int v2; // r31
  google::protobuf::internal::Mutex *v3; // r31
  _RTL_CRITICAL_SECTION *p_mutex; // r3
  google::protobuf::FatalException v5; // [sp+50h] [-50h] BYREF

  LOBYTE(v2) = 0;
  if ( this->level_ != LOGLEVEL_FATAL )
  {
    if ( !google::protobuf::internal::log_silencer_count_init_.initialized_ )
      google::protobuf::ProtobufOnceType::Init(
        this: &google::protobuf::internal::log_silencer_count_init_,
        init_func: (void (__fastcall *)())google::protobuf::internal::InitLogSilencerCount);
    v3 = log_silencer_count_mutex_;
    RtlEnterCriticalSection(CriticalSection: &log_silencer_count_mutex_->mInternal->mutex);
    p_mutex = &v3->mInternal->mutex;
    v2 = (-log_silencer_count_ & (unsigned int)~log_silencer_count_) >> 31;
    RtlLeaveCriticalSection(CriticalSection: p_mutex);
  }
  if ( (_BYTE)v2 == 0 )
    log_handler_(a1: this->level_, a2: this->filename_, a3: this->line_, a4: &this->message_);
  if ( this->level_ == LOGLEVEL_FATAL )
  {
    google::protobuf::FatalException::FatalException(
      this: &v5,
      filename: this->filename_,
      line: this->line_,
      message: &this->message_);
    CxxThrowException(pExceptionObject: &v5, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVFatalException_protobuf_google__);
  }
}


// ========================================================================
// ??4LogFinisher@internal@protobuf@google@@QAAXAAVLogMessage@123@@Z
// EA  : 0x832239A0
// RVA : 0x012239A0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::LogFinisher::operator=(
        google::protobuf::internal::LogFinisher *this,
        google::protobuf::internal::LogMessage *other)
{
  google::protobuf::internal::LogMessage::Finish(this: other);
}


// ========================================================================
// ?VersionString@internal@protobuf@google@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
// EA  : 0x832239A8
// RVA : 0x012239A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

std::string *__fastcall google::protobuf::internal::VersionString(std::string *result, int version)
{
  char *v3; // r11
  int v4; // r9
  char v6[136]; // [sp+50h] [-A0h] BYREF

  snprintf_0(string: v6, count: 0x80u, format: "%d.%d.%d", version / 1000000, version / 1000 % 1000, version % 1000);
  v3 = v6;
  result->_Mysize = 0;
  result->_Myres = 15;
  v6[127] = 0;
  result->_Bx._Buf[0] = 0;
  do
    v4 = (unsigned __int8)*v3++;
  while ( v4 != 0 );
  std::string::assign(this: result, _Ptr: v6, _Count: v3 - v6 - 1);
  return result;
}


// ========================================================================
// ??6LogMessage@internal@protobuf@google@@QAAAAV0123@PBD@Z
// EA  : 0x83223A88
// RVA : 0x01223A88
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

google::protobuf::internal::LogMessage *__fastcall google::protobuf::internal::LogMessage::operator<<(
        google::protobuf::internal::LogMessage *this,
        const char *value)
{
  const char *v3; // r11
  int v4; // r10

  v3 = value;
  do
    v4 = *(unsigned __int8 *)v3++;
  while ( v4 != 0 );
  std::string::append(this: &this->message_, _Ptr: value, _Count: v3 - value - 1);
  return this;
}


// ========================================================================
// ??6LogMessage@internal@protobuf@google@@QAAAAV0123@H@Z
// EA  : 0x83223AE0
// RVA : 0x01223AE0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

google::protobuf::internal::LogMessage *__fastcall google::protobuf::internal::LogMessage::operator<<(
        google::protobuf::internal::LogMessage *this,
        int value)
{
  char *v3; // r11
  int v4; // r9
  char v6[128]; // [sp+50h] [-90h] BYREF

  snprintf_0(string: v6, count: 0x80u, format: "%d", value);
  v3 = v6;
  v6[127] = 0;
  do
    v4 = (unsigned __int8)*v3++;
  while ( v4 != 0 );
  std::string::append(this: &this->message_, _Ptr: v6, _Count: v3 - v6 - 1);
  return this;
}


// ========================================================================
// ?VerifyVersion@internal@protobuf@google@@YAXHHPBD@Z
// EA  : 0x83223B68
// RVA : 0x01223B68
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall google::protobuf::internal::VerifyVersion(
        int headerVersion,
        int minLibraryVersion,
        const char *filename)
{
  const std::string *v6; // r20
  const std::string *v7; // r28
  const char *v8; // r11
  int v9; // r10
  memTag_t v10; // r4
  const std::string *v11; // r28
  const std::string *v12; // r27
  const char *v13; // r11
  int v14; // r10
  memTag_t v15; // r4
  google::protobuf::internal::LogMessage v16; // [sp+50h] [-150h] BYREF
  google::protobuf::internal::LogMessage v17; // [sp+80h] [-120h] BYREF
  std::string v18; // [sp+B0h] [-F0h] BYREF
  std::string v19; // [sp+D0h] [-D0h] BYREF
  std::string v20; // [sp+F0h] [-B0h] BYREF
  std::string v21[5]; // [sp+110h] [-90h] BYREF

  if ( minLibraryVersion > 2004001 )
  {
    v6 = google::protobuf::internal::VersionString(result: &v19, version: 2004001);
    v7 = google::protobuf::internal::VersionString(result: &v20, version: minLibraryVersion);
    v17.filename_ = "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\stubs\\common.cc";
    v17.level_ = LOGLEVEL_FATAL;
    v17.line_ = 67;
    v17.message_._Myres = 15;
    v17.message_._Mysize = 0;
    v17.message_._Bx._Buf[0] = 0;
    std::string::append(this: &v17.message_, _Ptr: "This program requires version ", _Count: 0x1Eu);
    std::string::append(this: &v17.message_, _Right: v7, _Roff: 0, _Count: 0xFFFFFFFF);
    std::string::append(
      this: &v17.message_,
      _Ptr: " of the Protocol Buffer runtime library, but the installed version is ",
      _Count: 0x46u);
    std::string::append(this: &v17.message_, _Right: v6, _Roff: 0, _Count: 0xFFFFFFFF);
    std::string::append(
      this: &v17.message_,
      _Ptr: ".  Please update your library.  If you compiled the program yourself, make sure that your headers are from the sam"
      "e version of Protocol Buffers as your link-time library.  (Version verification failed in \"",
      _Count: 0xCDu);
    v8 = filename;
    do
      v9 = *(unsigned __int8 *)v8++;
    while ( v9 != 0 );
    std::string::append(this: &v17.message_, _Ptr: filename, _Count: v8 - filename - 1);
    std::string::append(this: &v17.message_, _Ptr: "\".)", _Count: 3u);
    google::protobuf::internal::LogMessage::Finish(this: &v17);
    if ( v17.message_._Myres >= 0x10 )
      operator delete(p: v17.message_._Bx._Ptr, tag: v10);
    v17.message_._Myres = 15;
    v17.message_._Mysize = 0;
    v17.message_._Bx._Buf[0] = 0;
    if ( v20._Myres >= 0x10 )
      operator delete(p: v20._Bx._Ptr, tag: v10);
    v20._Myres = 15;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    if ( v19._Myres >= 0x10 )
      operator delete(p: v19._Bx._Ptr, tag: v10);
    v19._Myres = 15;
    v19._Mysize = 0;
    v19._Bx._Buf[0] = 0;
  }
  if ( headerVersion < 2004000 )
  {
    v11 = google::protobuf::internal::VersionString(result: v21, version: 2004001);
    v12 = google::protobuf::internal::VersionString(result: &v18, version: headerVersion);
    v16.filename_ = "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\stubs\\common.cc";
    v16.level_ = LOGLEVEL_FATAL;
    v16.line_ = 78;
    v16.message_._Myres = 15;
    v16.message_._Mysize = 0;
    v16.message_._Bx._Buf[0] = 0;
    std::string::append(this: &v16.message_, _Ptr: "This program was compiled against version ", _Count: 0x2Au);
    std::string::append(this: &v16.message_, _Right: v12, _Roff: 0, _Count: 0xFFFFFFFF);
    std::string::append(
      this: &v16.message_,
      _Ptr: " of the Protocol Buffer runtime library, which is not compatible with the installed version (",
      _Count: 0x5Du);
    std::string::append(this: &v16.message_, _Right: v11, _Roff: 0, _Count: 0xFFFFFFFF);
    std::string::append(
      this: &v16.message_,
      _Ptr: ").  Contact the program author for an update.  If you compiled the program yourself, make sure that your headers a"
      "re from the same version of Protocol Buffers as your link-time library.  (Version verification failed in \"",
      _Count: 0xDCu);
    v13 = filename;
    do
      v14 = *(unsigned __int8 *)v13++;
    while ( v14 != 0 );
    std::string::append(this: &v16.message_, _Ptr: filename, _Count: v13 - filename - 1);
    std::string::append(this: &v16.message_, _Ptr: "\".)", _Count: 3u);
    google::protobuf::internal::LogMessage::Finish(this: &v16);
    if ( v16.message_._Myres >= 0x10 )
      operator delete(p: v16.message_._Bx._Ptr, tag: v15);
    v16.message_._Myres = 15;
    v16.message_._Mysize = 0;
    v16.message_._Bx._Buf[0] = 0;
    if ( v18._Myres >= 0x10 )
      operator delete(p: v18._Bx._Ptr, tag: v15);
    v18._Myres = 15;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( v21[0]._Myres >= 0x10 )
      operator delete(p: v21[0]._Bx._Ptr, tag: v15);
  }
}


// ========================================================================
// __unwind$93646
// EA  : 0x83223E48
// RVA : 0x01223E48
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void _unwind_93646()
{
  int v0; // r12

  std::string::~string(this: (std::string *)(v0 - 416 + 208));
}


// ========================================================================
// __unwind$93647
// EA  : 0x83223E70
// RVA : 0x01223E70
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void _unwind_93647()
{
  int v0; // r12

  std::string::~string(this: (std::string *)(v0 - 416 + 240));
}


// ========================================================================
// __unwind$93648
// EA  : 0x83223E98
// RVA : 0x01223E98
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall _unwind_93648(int a1, memTag_t a2)
{
  int v2; // r12

  google::protobuf::internal::LogMessage::~LogMessage(
    this: (google::protobuf::internal::LogMessage *)(v2 - 416 + 128),
    a2);
}


// ========================================================================
// __unwind$93649
// EA  : 0x83223EC0
// RVA : 0x01223EC0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void _unwind_93649()
{
  int v0; // r12

  std::string::~string(this: (std::string *)(v0 - 416 + 272));
}


// ========================================================================
// __unwind$93650
// EA  : 0x83223EE8
// RVA : 0x01223EE8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void _unwind_93650()
{
  int v0; // r12

  std::string::~string(this: (std::string *)(v0 - 416 + 176));
}


// ========================================================================
// __unwind$93651
// EA  : 0x83223F10
// RVA : 0x01223F10
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __fastcall _unwind_93651(int a1, memTag_t a2)
{
  int v2; // r12

  google::protobuf::internal::LogMessage::~LogMessage(
    this: (google::protobuf::internal::LogMessage *)(v2 - 416 + 80),
    a2);
}


// ========================================================================
// google::protobuf::internal::`dynamic initializer for 'log_silencer_count_init_''
// EA  : 0x83397E28
// RVA : 0x01397E28
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __noreturn google::protobuf::internal::_dynamic_initializer_for__log_silencer_count_init___()
{
  google::protobuf::ProtobufOnceType::ProtobufOnceType(this: &google::protobuf::internal::log_silencer_count_init_);
  atexit(func: (void (__fastcall *)())google::protobuf::internal::_dynamic_atexit_destructor_for__log_silencer_count_init___);
}


// ========================================================================
// google::protobuf::internal::`dynamic initializer for 'shutdown_functions_init''
// EA  : 0x83397E60
// RVA : 0x01397E60
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\common.cc
// ========================================================================

void __noreturn google::protobuf::internal::_dynamic_initializer_for__shutdown_functions_init__()
{
  google::protobuf::ProtobufOnceType::ProtobufOnceType(this: &google::protobuf::internal::shutdown_functions_init);
  atexit(func: (void (__fastcall *)())google::protobuf::internal::_dynamic_atexit_destructor_for__shutdown_functions_init__);
}

