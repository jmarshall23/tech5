
// ========================================================================
// ?mutable_basekernelversion@Xbox360KitInfo@idreports@@QAAPAVXbox360VersionInfo@2@XZ
// EA  : 0x82894060
// RVA : 0x00894060
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Xbox360VersionInfo *__fastcall idreports::Xbox360KitInfo::mutable_basekernelversion(
        idreports::Xbox360KitInfo *this)
{
  idreports::Xbox360VersionInfo *basekernelversion; // r10
  idreports::Xbox360VersionInfo *v3; // r3
  idreports::Xbox360VersionInfo *v4; // r3

  basekernelversion = this->basekernelversion_;
  this->_has_bits_[0] |= 2u;
  if ( basekernelversion == nullptr )
  {
    v3 = (idreports::Xbox360VersionInfo *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                            size: 0x1Cu,
                                            tag: TAG_NEW,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::Xbox360VersionInfo::Xbox360VersionInfo(this: v3);
    else
      v4 = nullptr;
    this->basekernelversion_ = v4;
  }
  return this->basekernelversion_;
}


// ========================================================================
// __unwind$262670
// EA  : 0x828940F4
// RVA : 0x008940F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262670(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_kernelversion@Xbox360KitInfo@idreports@@QAAPAVXbox360VersionInfo@2@XZ
// EA  : 0x82894128
// RVA : 0x00894128
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Xbox360VersionInfo *__fastcall idreports::Xbox360KitInfo::mutable_kernelversion(
        idreports::Xbox360KitInfo *this)
{
  idreports::Xbox360VersionInfo *kernelversion; // r10
  idreports::Xbox360VersionInfo *v3; // r3
  idreports::Xbox360VersionInfo *v4; // r3

  kernelversion = this->kernelversion_;
  this->_has_bits_[0] |= 4u;
  if ( kernelversion == nullptr )
  {
    v3 = (idreports::Xbox360VersionInfo *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                            size: 0x1Cu,
                                            tag: TAG_NEW,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::Xbox360VersionInfo::Xbox360VersionInfo(this: v3);
    else
      v4 = nullptr;
    this->kernelversion_ = v4;
  }
  return this->kernelversion_;
}


// ========================================================================
// __unwind$262698
// EA  : 0x828941BC
// RVA : 0x008941BC
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262698(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_xdkversion@Xbox360KitInfo@idreports@@QAAPAVXbox360VersionInfo@2@XZ
// EA  : 0x828941F0
// RVA : 0x008941F0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Xbox360VersionInfo *__fastcall idreports::Xbox360KitInfo::mutable_xdkversion(
        idreports::Xbox360KitInfo *this)
{
  idreports::Xbox360VersionInfo *xdkversion; // r10
  idreports::Xbox360VersionInfo *v3; // r3
  idreports::Xbox360VersionInfo *v4; // r3

  xdkversion = this->xdkversion_;
  this->_has_bits_[0] |= 8u;
  if ( xdkversion == nullptr )
  {
    v3 = (idreports::Xbox360VersionInfo *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                            size: 0x1Cu,
                                            tag: TAG_NEW,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::Xbox360VersionInfo::Xbox360VersionInfo(this: v3);
    else
      v4 = nullptr;
    this->xdkversion_ = v4;
  }
  return this->xdkversion_;
}


// ========================================================================
// __unwind$262725
// EA  : 0x82894284
// RVA : 0x00894284
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262725(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_kitinfo@Xbox360CrashReport@idreports@@QAAPAVXbox360KitInfo@2@XZ
// EA  : 0x828942B8
// RVA : 0x008942B8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Xbox360KitInfo *__fastcall idreports::Xbox360CrashReport::mutable_kitinfo(
        idreports::Xbox360CrashReport *this)
{
  idreports::Xbox360KitInfo *kitinfo; // r10
  idreports::Xbox360KitInfo *v3; // r3
  idreports::Xbox360KitInfo *v4; // r3

  kitinfo = this->kitinfo_;
  this->_has_bits_[0] |= 0x800u;
  if ( kitinfo == nullptr )
  {
    v3 = (idreports::Xbox360KitInfo *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0x24u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::Xbox360KitInfo::Xbox360KitInfo(this: v3);
    else
      v4 = nullptr;
    this->kitinfo_ = v4;
  }
  return this->kitinfo_;
}


// ========================================================================
// __unwind$262752
// EA  : 0x8289434C
// RVA : 0x0089434C
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262752(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_exception@Xbox360CrashReport@idreports@@QAAPAVExceptionInfo@2@XZ
// EA  : 0x82894380
// RVA : 0x00894380
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::ExceptionInfo *__fastcall idreports::Xbox360CrashReport::mutable_exception(
        idreports::Xbox360CrashReport *this)
{
  idreports::ExceptionInfo *exception; // r10
  idreports::ExceptionInfo *v3; // r3
  idreports::ExceptionInfo *v4; // r3

  exception = this->exception_;
  this->_has_bits_[0] |= 0x2000u;
  if ( exception == nullptr )
  {
    v3 = (idreports::ExceptionInfo *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x18u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::ExceptionInfo::ExceptionInfo(this: v3);
    else
      v4 = nullptr;
    this->exception_ = v4;
  }
  return this->exception_;
}


// ========================================================================
// __unwind$262779
// EA  : 0x82894414
// RVA : 0x00894414
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262779(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_registers@Xbox360CrashReport@idreports@@QAAPAVXenonRegisterInfo@2@XZ
// EA  : 0x82894448
// RVA : 0x00894448
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::XenonRegisterInfo *__fastcall idreports::Xbox360CrashReport::mutable_registers(
        idreports::Xbox360CrashReport *this)
{
  idreports::XenonRegisterInfo *registers; // r10
  idreports::XenonRegisterInfo *v3; // r3
  idreports::XenonRegisterInfo *v4; // r3

  registers = this->registers_;
  this->_has_bits_[0] |= 0x4000u;
  if ( registers == nullptr )
  {
    v3 = (idreports::XenonRegisterInfo *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x8Cu,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::XenonRegisterInfo::XenonRegisterInfo(this: v3);
    else
      v4 = nullptr;
    this->registers_ = v4;
  }
  return this->registers_;
}


// ========================================================================
// __unwind$262806
// EA  : 0x828944DC
// RVA : 0x008944DC
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262806(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_consolememory@Xbox360CrashReport@idreports@@QAAPAVXenonMemoryInfo@2@XZ
// EA  : 0x82894510
// RVA : 0x00894510
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::XenonMemoryInfo *__fastcall idreports::Xbox360CrashReport::mutable_consolememory(
        idreports::Xbox360CrashReport *this)
{
  idreports::XenonMemoryInfo *consolememory; // r10
  idreports::XenonMemoryInfo *v3; // r3
  idreports::XenonMemoryInfo *v4; // r3

  consolememory = this->consolememory_;
  this->_has_bits_[0] |= 0x8000u;
  if ( consolememory == nullptr )
  {
    v3 = (idreports::XenonMemoryInfo *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x38u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::XenonMemoryInfo::XenonMemoryInfo(this: v3);
    else
      v4 = nullptr;
    this->consolememory_ = v4;
  }
  return this->consolememory_;
}


// ========================================================================
// __unwind$262833
// EA  : 0x828945A4
// RVA : 0x008945A4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262833(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_titlememory@Xbox360CrashReport@idreports@@QAAPAVXenonMemoryInfo@2@XZ
// EA  : 0x828945D8
// RVA : 0x008945D8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::XenonMemoryInfo *__fastcall idreports::Xbox360CrashReport::mutable_titlememory(
        idreports::Xbox360CrashReport *this)
{
  idreports::XenonMemoryInfo *titlememory; // r10
  idreports::XenonMemoryInfo *v3; // r3
  idreports::XenonMemoryInfo *v4; // r3

  titlememory = this->titlememory_;
  this->_has_bits_[0] |= 0x10000u;
  if ( titlememory == nullptr )
  {
    v3 = (idreports::XenonMemoryInfo *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x38u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::XenonMemoryInfo::XenonMemoryInfo(this: v3);
    else
      v4 = nullptr;
    this->titlememory_ = v4;
  }
  return this->titlememory_;
}


// ========================================================================
// __unwind$262860
// EA  : 0x8289466C
// RVA : 0x0089466C
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_262860(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?set_expcode@ExceptionInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895598
// RVA : 0x00895598
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ExceptionInfo::set_expcode(idreports::ExceptionInfo *this, const char *value)
{
  std::string *expcode; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  expcode = this->expcode_;
  this->_has_bits_[0] |= 1u;
  if ( expcode == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->expcode_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->expcode_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$264546
// EA  : 0x82895658
// RVA : 0x00895658
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_264546(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_expaddress@ExceptionInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895688
// RVA : 0x00895688
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ExceptionInfo::set_expaddress(idreports::ExceptionInfo *this, const char *value)
{
  std::string *expaddress; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  expaddress = this->expaddress_;
  this->_has_bits_[0] |= 4u;
  if ( expaddress == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->expaddress_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->expaddress_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$264667
// EA  : 0x82895748
// RVA : 0x00895748
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_264667(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_consolename@Xbox360KitInfo@idreports@@QAAXPBDI@Z
// EA  : 0x82895778
// RVA : 0x00895778
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360KitInfo::set_consolename(
        idreports::Xbox360KitInfo *this,
        const char *value,
        size_t size)
{
  std::string *consolename; // r9
  std::string *v7; // r3
  std::string *v8; // r11

  consolename = this->consolename_;
  this->_has_bits_[0] |= 0x20u;
  if ( consolename == &google::protobuf::internal::kEmptyString )
  {
    v7 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      v7->_Mysize = 0;
      v8 = v7;
      v7->_Myres = 15;
      v7->_Bx._Buf[0] = 0;
    }
    else
    {
      v8 = nullptr;
    }
    this->consolename_ = v8;
  }
  std::string::assign(this: this->consolename_, _Ptr: value, _Count: size);
}


// ========================================================================
// __unwind$264788_0
// EA  : 0x82895820
// RVA : 0x00895820
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_264788_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_msr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895850
// RVA : 0x00895850
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_msr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *msr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  msr = this->msr_;
  this->_has_bits_[0] |= 1u;
  if ( msr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->msr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->msr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$264899
// EA  : 0x82895910
// RVA : 0x00895910
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_264899(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_iar@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895940
// RVA : 0x00895940
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_iar(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *iar; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  iar = this->iar_;
  this->_has_bits_[0] |= 2u;
  if ( iar == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->iar_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->iar_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265020
// EA  : 0x82895A00
// RVA : 0x00895A00
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265020(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_lr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895A30
// RVA : 0x00895A30
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_lr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *lr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  lr = this->lr_;
  this->_has_bits_[0] |= 4u;
  if ( lr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->lr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->lr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265141
// EA  : 0x82895AF0
// RVA : 0x00895AF0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265141(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_ctr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895B20
// RVA : 0x00895B20
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_ctr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *ctr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  ctr = this->ctr_;
  this->_has_bits_[0] |= 8u;
  if ( ctr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->ctr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->ctr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265262
// EA  : 0x82895BE0
// RVA : 0x00895BE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265262(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_fpscr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895C10
// RVA : 0x00895C10
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_fpscr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *fpscr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  fpscr = this->fpscr_;
  this->_has_bits_[0] |= 0x10u;
  if ( fpscr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->fpscr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->fpscr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265383
// EA  : 0x82895CD0
// RVA : 0x00895CD0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265383(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_cr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895D00
// RVA : 0x00895D00
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_cr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *cr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  cr = this->cr_;
  this->_has_bits_[0] |= 0x40u;
  if ( cr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->cr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->cr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265523
// EA  : 0x82895DC0
// RVA : 0x00895DC0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265523(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_xer@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895DF0
// RVA : 0x00895DF0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_xer(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *xer; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  xer = this->xer_;
  this->_has_bits_[0] |= 0x80u;
  if ( xer == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->xer_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->xer_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265644
// EA  : 0x82895EB0
// RVA : 0x00895EB0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265644(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vscr@XenonRegisterInfo@idreports@@QAAXPBD@Z
// EA  : 0x82895EE0
// RVA : 0x00895EE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_vscr(idreports::XenonRegisterInfo *this, const char *value)
{
  std::string *vscr; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  vscr = this->vscr_;
  this->_has_bits_[0] |= 0x200u;
  if ( vscr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vscr_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->vscr_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265784
// EA  : 0x82895FA0
// RVA : 0x00895FA0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265784(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82895FD0
// RVA : 0x00895FD0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_game(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->game_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$265905
// EA  : 0x82896090
// RVA : 0x00896090
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_265905(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x828960C0
// RVA : 0x008960C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_username(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->username_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266026_0
// EA  : 0x82896180
// RVA : 0x00896180
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266026_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x828961B0
// RVA : 0x008961B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_platform(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->platform_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266147
// EA  : 0x82896270
// RVA : 0x00896270
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266147(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildstring@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x828962A0
// RVA : 0x008962A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_buildstring(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *buildstring; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildstring_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->buildstring_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266268
// EA  : 0x82896360
// RVA : 0x00896360
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266268(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82896390
// RVA : 0x00896390
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_timestamp(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->timestamp_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266389
// EA  : 0x82896450
// RVA : 0x00896450
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266389(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_launchcommand@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82896480
// RVA : 0x00896480
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_launchcommand(
        idreports::Xbox360CrashReport *this,
        const char *value)
{
  std::string *launchcommand; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->launchcommand_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->launchcommand_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266510
// EA  : 0x82896540
// RVA : 0x00896540
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266510(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepath@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82896570
// RVA : 0x00896570
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_vtfilepath(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *vtfilepath; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepath_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->vtfilepath_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266631
// EA  : 0x82896630
// RVA : 0x00896630
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266631(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepathvmtroverride@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82896660
// RVA : 0x00896660
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_vtfilepathvmtroverride(
        idreports::Xbox360CrashReport *this,
        const char *value)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->vtfilepathvmtroverride_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266752
// EA  : 0x82896720
// RVA : 0x00896720
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266752(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mappath@Xbox360CrashReport@idreports@@QAAXPBD@Z
// EA  : 0x82896750
// RVA : 0x00896750
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_mappath(idreports::Xbox360CrashReport *this, const char *value)
{
  std::string *mappath; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x400u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mappath_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->mappath_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$266873
// EA  : 0x82896810
// RVA : 0x00896810
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_266873(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_attachment@ViewNoteReport@idreports@@QAAPAVAttachment@2@XZ
// EA  : 0x82EF4FE8
// RVA : 0x00EF4FE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Attachment *__fastcall idreports::ViewNoteReport::mutable_attachment(idreports::ViewNoteReport *this)
{
  idreports::Attachment *attachment; // r10
  idreports::Attachment *v3; // r3
  idreports::Attachment *v4; // r3

  attachment = this->attachment_;
  this->_has_bits_[0] |= 0x40000u;
  if ( attachment == nullptr )
  {
    v3 = (idreports::Attachment *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x14u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
      v4 = idreports::Attachment::Attachment(this: v3);
    else
      v4 = nullptr;
    this->attachment_ = v4;
  }
  return this->attachment_;
}


// ========================================================================
// __unwind$159881
// EA  : 0x82EF507C
// RVA : 0x00EF507C
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_159881(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@LogEvent@idreports@@QAAXPBD@Z
// EA  : 0x82EF60C0
// RVA : 0x00EF60C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_timestamp(idreports::LogEvent *this, const char *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 1u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->timestamp_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$162743
// EA  : 0x82EF6180
// RVA : 0x00EF6180
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_162743(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_message@LogEvent@idreports@@QAAXPBD@Z
// EA  : 0x82EF61B0
// RVA : 0x00EF61B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_message(idreports::LogEvent *this, const char *value)
{
  std::string *message; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  message = this->message_;
  this->_has_bits_[0] |= 4u;
  if ( message == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->message_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->message_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$162864
// EA  : 0x82EF6270
// RVA : 0x00EF6270
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_162864(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_data@LogEvent@idreports@@QAAXPBXI@Z
// EA  : 0x82EF62A0
// RVA : 0x00EF62A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_data(idreports::LogEvent *this, const char *value, size_t size)
{
  std::string *data; // r9
  std::string *v7; // r3
  std::string *v8; // r11

  data = this->data_;
  this->_has_bits_[0] |= 0x10u;
  if ( data == &google::protobuf::internal::kEmptyString )
  {
    v7 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      v7->_Mysize = 0;
      v8 = v7;
      v7->_Myres = 15;
      v7->_Bx._Buf[0] = 0;
    }
    else
    {
      v8 = nullptr;
    }
    this->data_ = v8;
  }
  std::string::assign(this: this->data_, _Ptr: value, _Count: size);
}


// ========================================================================
// __unwind$162985
// EA  : 0x82EF6348
// RVA : 0x00EF6348
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_162985(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_datatype@LogEvent@idreports@@QAAXPBD@Z
// EA  : 0x82EF6378
// RVA : 0x00EF6378
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_datatype(idreports::LogEvent *this, const char *value)
{
  std::string *datatype; // r9
  std::string *v5; // r3
  std::string *v6; // r11
  const char *v7; // r11
  int v8; // r10

  datatype = this->datatype_;
  this->_has_bits_[0] |= 0x20u;
  if ( datatype == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->datatype_ = v6;
  }
  v7 = value;
  do
    v8 = *(unsigned __int8 *)v7++;
  while ( v8 != 0 );
  std::string::assign(this: this->datatype_, _Ptr: value, _Count: v7 - value - 1);
}


// ========================================================================
// __unwind$163096
// EA  : 0x82EF6438
// RVA : 0x00EF6438
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_163096(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?GetGraphNode@CFilterSkin@LEAPCORE@@UAAPAUIGraphNode@2@XZ
// EA  : 0x82F530A0
// RVA : 0x00F530A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

LEAPCORE::CGraphManager *__fastcall LEAPCORE::CFilterSkin::GetGraphNode(LEAPCORE::CFilterSkin *this)
{
  return this->m_pGraphManager;
}


// ========================================================================
// ?GetCachedSize@MemoryInfo@idreports@@UBAHXZ
// EA  : 0x82F53468
// RVA : 0x00F53468
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void *__fastcall idreports::MemoryInfo::GetCachedSize(XGRAPHICS::_SSM_OBJINFO *pSSMObj)
{
  return pSSMObj->hDev;
}


// ========================================================================
// ?mutable_vscr@PPURegisterInfo@idreports@@QAAPAVBigUInt@2@XZ
// EA  : 0x82F566A0
// RVA : 0x00F566A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::BigUInt *__fastcall idreports::PPURegisterInfo::mutable_vscr(idreports::PPURegisterInfo *this)
{
  idreports::BigUInt *vscr; // r10
  _DWORD *v3; // r3
  __int64 v4; // r11

  vscr = this->vscr_;
  this->_has_bits_[0] |= 0x200u;
  if ( vscr == nullptr )
  {
    v3 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: 0x20u,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      LODWORD(v4) = 0;
      v3[6] = 0;
      HIDWORD(v4) = v3;
      *v3 = &idreports::BigUInt::`vftable';
      *((_QWORD *)v3 + 1) = v4;
      *((_QWORD *)v3 + 2) = v4;
      v3[7] = 0;
    }
    else
    {
      HIDWORD(v4) = 0;
    }
    this->vscr_ = (idreports::BigUInt *)HIDWORD(v4);
  }
  return this->vscr_;
}


// ========================================================================
// ?mutable_exception@CrashReport@idreports@@QAAPAVExceptionInfo@2@XZ
// EA  : 0x82F56748
// RVA : 0x00F56748
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::ExceptionInfo *__fastcall idreports::CrashReport::mutable_exception(idreports::CrashReport *this)
{
  idreports::ExceptionInfo *exception; // r10
  idreports::ExceptionInfo *v3; // r3
  idreports::ExceptionInfo *v4; // r10

  exception = this->exception_;
  this->_has_bits_[0] |= 0x200000u;
  if ( exception == nullptr )
  {
    v3 = (idreports::ExceptionInfo *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x18u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_cached_size_ = 0;
      v3->expcode_ = &google::protobuf::internal::kEmptyString;
      v4 = v3;
      v3->__vftable = (idreports::ExceptionInfo_vtbl *)&idreports::ExceptionInfo::`vftable';
      v3->expflags_ = 0;
      v3->expaddress_ = &google::protobuf::internal::kEmptyString;
      v3->_has_bits_[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->exception_ = v4;
  }
  return this->exception_;
}


// ========================================================================
// ?mutable_registers@CrashReport@idreports@@QAAPAVRegisterInfo@2@XZ
// EA  : 0x82F567F8
// RVA : 0x00F567F8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::RegisterInfo *__fastcall idreports::CrashReport::mutable_registers(idreports::CrashReport *this)
{
  idreports::RegisterInfo *registers; // r10
  idreports::RegisterInfo *v3; // r3
  idreports::RegisterInfo *v4; // r10

  registers = this->registers_;
  this->_has_bits_[0] |= 0x400000u;
  if ( registers == nullptr )
  {
    v3 = (idreports::RegisterInfo *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x40u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_cached_size_ = 0;
      v3->edi_ = &google::protobuf::internal::kEmptyString;
      v4 = v3;
      v3->__vftable = (idreports::RegisterInfo_vtbl *)&idreports::RegisterInfo::`vftable';
      v3->esi_ = &google::protobuf::internal::kEmptyString;
      v3->eax_ = &google::protobuf::internal::kEmptyString;
      v3->ebx_ = &google::protobuf::internal::kEmptyString;
      v3->ecx_ = &google::protobuf::internal::kEmptyString;
      v3->edx_ = &google::protobuf::internal::kEmptyString;
      v3->eip_ = &google::protobuf::internal::kEmptyString;
      v3->ebp_ = &google::protobuf::internal::kEmptyString;
      v3->esp_ = &google::protobuf::internal::kEmptyString;
      v3->eflags_ = &google::protobuf::internal::kEmptyString;
      v3->segcs_ = &google::protobuf::internal::kEmptyString;
      v3->segss_ = &google::protobuf::internal::kEmptyString;
      v3->platform_ = 0;
      v3->_has_bits_[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->registers_ = v4;
  }
  return this->registers_;
}


// ========================================================================
// ?mutable_attachment@CrashReport@idreports@@QAAPAVAttachment@2@XZ
// EA  : 0x82F568D0
// RVA : 0x00F568D0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::Attachment *__fastcall idreports::CrashReport::mutable_attachment(idreports::CrashReport *this)
{
  idreports::Attachment *attachment; // r10
  idreports::Attachment *v3; // r3
  idreports::Attachment *v4; // r11

  attachment = this->attachment_;
  this->_has_bits_[0] |= 0x800000u;
  if ( attachment == nullptr )
  {
    v3 = (idreports::Attachment *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x14u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_cached_size_ = 0;
      v3->attachment_ = &google::protobuf::internal::kEmptyString;
      v4 = v3;
      v3->__vftable = (idreports::Attachment_vtbl *)&idreports::Attachment::`vftable';
      v3->filename_ = &google::protobuf::internal::kEmptyString;
      v3->_has_bits_[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->attachment_ = v4;
  }
  return this->attachment_;
}


// ========================================================================
// ?mutable_cpuinfo@CrashReport@idreports@@QAAPAVCPUInfo@2@XZ
// EA  : 0x82F56980
// RVA : 0x00F56980
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::CPUInfo *__fastcall idreports::CrashReport::mutable_cpuinfo(idreports::CrashReport *this)
{
  idreports::CPUInfo *cpuinfo; // r10
  float *v3; // r3
  idreports::CPUInfo *v4; // r10

  cpuinfo = this->cpuinfo_;
  this->_has_bits_[0] |= 0x11000000u;
  if ( cpuinfo == nullptr )
  {
    v3 = (float *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                    size: 0x20u,
                    tag: TAG_NEW,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3[5] = 0.0;
      *(_DWORD *)v3 = &idreports::CPUInfo::`vftable';
      v3[6] = 0.0;
      v4 = (idreports::CPUInfo *)v3;
      *((_DWORD *)v3 + 1) = &google::protobuf::internal::kEmptyString;
      v3[2] = 0.0;
      v3[3] = 0.0;
      v3[4] = 0.0;
      v3[7] = 0.0;
    }
    else
    {
      v4 = nullptr;
    }
    this->cpuinfo_ = v4;
  }
  return this->cpuinfo_;
}


// ========================================================================
// ?mutable_meminfo@CrashReport@idreports@@QAAPAVMemoryInfo@2@XZ
// EA  : 0x82F56A40
// RVA : 0x00F56A40
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::MemoryInfo *__fastcall idreports::CrashReport::mutable_meminfo(idreports::CrashReport *this)
{
  idreports::MemoryInfo *meminfo; // r10
  idreports::MemoryInfo *v3; // r3
  idreports::MemoryInfo *v4; // r10

  meminfo = this->meminfo_;
  this->_has_bits_[0] |= 0x22000000u;
  if ( meminfo == nullptr )
  {
    v3 = (idreports::MemoryInfo *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x28u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_cached_size_ = 0;
      v4 = v3;
      v3->__vftable = (idreports::MemoryInfo_vtbl *)&idreports::MemoryInfo::`vftable';
      v3->inuse_ = 0;
      v3->physicalmb_ = 0;
      v3->physicalfree_ = 0;
      v3->pagingfile_ = 0;
      v3->pagingfree_ = 0;
      v3->useraddress_ = 0;
      v3->userfree_ = 0;
      v3->_has_bits_[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->meminfo_ = v4;
  }
  return this->meminfo_;
}


// ========================================================================
// ?mutable_exception@PS3CrashReport@idreports@@QAAPAVPS3ExceptionInfo@2@XZ
// EA  : 0x82F56AF8
// RVA : 0x00F56AF8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::PS3ExceptionInfo *__fastcall idreports::PS3CrashReport::mutable_exception(idreports::PS3CrashReport *this)
{
  idreports::PS3ExceptionInfo *exception; // r10
  _DWORD *v3; // r3
  __int64 v4; // r11

  exception = this->exception_;
  this->_has_bits_[0] |= 0x1000u;
  if ( exception == nullptr )
  {
    v3 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: 0x20u,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      LODWORD(v4) = 0;
      v3[6] = 0;
      *v3 = &idreports::PS3ExceptionInfo::`vftable';
      HIDWORD(v4) = v3;
      v3[1] = &google::protobuf::internal::kEmptyString;
      *((_QWORD *)v3 + 1) = v4;
      *((_QWORD *)v3 + 2) = v4;
      v3[7] = 0;
    }
    else
    {
      HIDWORD(v4) = 0;
    }
    this->exception_ = (idreports::PS3ExceptionInfo *)HIDWORD(v4);
  }
  return this->exception_;
}


// ========================================================================
// ?GetCachedSize@MapReport@idreports@@UBAHXZ
// EA  : 0x82F58580
// RVA : 0x00F58580
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

int __fastcall idreports::MapReport::GetCachedSize(idreports::MapReport *this)
{
  return this->_cached_size_;
}


// ========================================================================
// ?GetCachedSize@XenonRegisterInfo@idreports@@UBAHXZ
// EA  : 0x82F59A70
// RVA : 0x00F59A70
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

int __fastcall idreports::XenonRegisterInfo::GetCachedSize(idreports::XenonRegisterInfo *this)
{
  return this->_cached_size_;
}


// ========================================================================
// ?mutable_attachment@Attachment@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D028
// RVA : 0x00F5D028
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Attachment::mutable_attachment(idreports::Attachment *this)
{
  std::string *attachment; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  attachment = this->attachment_;
  this->_has_bits_[0] |= 1u;
  if ( attachment == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->attachment_ = v4;
  }
  return this->attachment_;
}


// ========================================================================
// __unwind$192902
// EA  : 0x82F5D0D4
// RVA : 0x00F5D0D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_192902(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_filename@Attachment@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D108
// RVA : 0x00F5D108
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Attachment::mutable_filename(idreports::Attachment *this)
{
  std::string *filename; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 2u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->filename_ = v4;
  }
  return this->filename_;
}


// ========================================================================
// __unwind$193012
// EA  : 0x82F5D1B4
// RVA : 0x00F5D1B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193012(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_timestamp@LogEvent@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D1E8
// RVA : 0x00F5D1E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::LogEvent::mutable_timestamp(idreports::LogEvent *this)
{
  std::string *timestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 1u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->timestamp_ = v4;
  }
  return this->timestamp_;
}


// ========================================================================
// __unwind$193122
// EA  : 0x82F5D294
// RVA : 0x00F5D294
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193122(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_message@LogEvent@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D2C8
// RVA : 0x00F5D2C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::LogEvent::mutable_message(idreports::LogEvent *this)
{
  std::string *message; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  message = this->message_;
  this->_has_bits_[0] |= 4u;
  if ( message == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->message_ = v4;
  }
  return this->message_;
}


// ========================================================================
// __unwind$193232
// EA  : 0x82F5D374
// RVA : 0x00F5D374
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193232(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_data@LogEvent@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D3A8
// RVA : 0x00F5D3A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::LogEvent::mutable_data(idreports::LogEvent *this)
{
  std::string *data; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  data = this->data_;
  this->_has_bits_[0] |= 0x10u;
  if ( data == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->data_ = v4;
  }
  return this->data_;
}


// ========================================================================
// __unwind$193342
// EA  : 0x82F5D454
// RVA : 0x00F5D454
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193342(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_datatype@LogEvent@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D488
// RVA : 0x00F5D488
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::LogEvent::mutable_datatype(idreports::LogEvent *this)
{
  std::string *datatype; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  datatype = this->datatype_;
  this->_has_bits_[0] |= 0x20u;
  if ( datatype == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->datatype_ = v4;
  }
  return this->datatype_;
}


// ========================================================================
// __unwind$193452
// EA  : 0x82F5D534
// RVA : 0x00F5D534
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193452(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_expcode@ExceptionInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D568
// RVA : 0x00F5D568
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ExceptionInfo::mutable_expcode(idreports::ExceptionInfo *this)
{
  std::string *expcode; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  expcode = this->expcode_;
  this->_has_bits_[0] |= 1u;
  if ( expcode == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->expcode_ = v4;
  }
  return this->expcode_;
}


// ========================================================================
// __unwind$193567
// EA  : 0x82F5D614
// RVA : 0x00F5D614
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193567(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_expaddress@ExceptionInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D648
// RVA : 0x00F5D648
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ExceptionInfo::mutable_expaddress(idreports::ExceptionInfo *this)
{
  std::string *expaddress; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  expaddress = this->expaddress_;
  this->_has_bits_[0] |= 4u;
  if ( expaddress == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->expaddress_ = v4;
  }
  return this->expaddress_;
}


// ========================================================================
// __unwind$193677
// EA  : 0x82F5D6F4
// RVA : 0x00F5D6F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193677(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_cpuid@CPUInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D728
// RVA : 0x00F5D728
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CPUInfo::mutable_cpuid(idreports::PS3ExceptionInfo *this)
{
  std::string *exceptionname; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  exceptionname = this->exceptionname_;
  this->_has_bits_[0] |= 1u;
  if ( exceptionname == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->exceptionname_ = v4;
  }
  return this->exceptionname_;
}


// ========================================================================
// __unwind$199087
// EA  : 0x82F5D7D4
// RVA : 0x00F5D7D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199087(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_filename@CallstackLine@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D808
// RVA : 0x00F5D808
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CallstackLine::mutable_filename(idreports::CallstackLine *this)
{
  std::string *filename; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 8u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->filename_ = v4;
  }
  return this->filename_;
}


// ========================================================================
// __unwind$193897
// EA  : 0x82F5D8B4
// RVA : 0x00F5D8B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_193897(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_address@CallstackLine@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D8E8
// RVA : 0x00F5D8E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CallstackLine::mutable_address(idreports::CallstackLine *this)
{
  std::string *address; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  address = this->address_;
  this->_has_bits_[0] |= 0x10u;
  if ( address == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->address_ = v4;
  }
  return this->address_;
}


// ========================================================================
// __unwind$194007
// EA  : 0x82F5D994
// RVA : 0x00F5D994
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194007(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_filename@AssertReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5D9C8
// RVA : 0x00F5D9C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::AssertReport::mutable_filename(idreports::AssertReport *this)
{
  std::string *filename; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 2u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->filename_ = v4;
  }
  return this->filename_;
}


// ========================================================================
// __unwind$194117
// EA  : 0x82F5DA74
// RVA : 0x00F5DA74
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194117(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_expression@AssertReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DAA8
// RVA : 0x00F5DAA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::AssertReport::mutable_expression(idreports::AssertReport *this)
{
  std::string *expression; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  expression = this->expression_;
  this->_has_bits_[0] |= 8u;
  if ( expression == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->expression_ = v4;
  }
  return this->expression_;
}


// ========================================================================
// __unwind$194227
// EA  : 0x82F5DB54
// RVA : 0x00F5DB54
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194227(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_message@MapWarning@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DB88
// RVA : 0x00F5DB88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapWarning::mutable_message(idreports::MapWarning *this)
{
  std::string *message; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  message = this->message_;
  this->_has_bits_[0] |= 1u;
  if ( message == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->message_ = v4;
  }
  return this->message_;
}


// ========================================================================
// __unwind$194337
// EA  : 0x82F5DC34
// RVA : 0x00F5DC34
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194337(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_platform@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DC68
// RVA : 0x00F5DC68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_platform(idreports::MapReport *this)
{
  std::string *platform; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 0x10u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->platform_ = v4;
  }
  return this->platform_;
}


// ========================================================================
// __unwind$194447
// EA  : 0x82F5DD14
// RVA : 0x00F5DD14
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194447(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_game@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DD48
// RVA : 0x00F5DD48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_game(idreports::MapReport *this)
{
  std::string *game; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  game = this->game_;
  this->_has_bits_[0] |= 0x20u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->game_ = v4;
  }
  return this->game_;
}


// ========================================================================
// __unwind$194557
// EA  : 0x82F5DDF4
// RVA : 0x00F5DDF4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194557(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_buildversion@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DE28
// RVA : 0x00F5DE28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_buildversion(idreports::MapReport *this)
{
  std::string *buildversion; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  buildversion = this->buildversion_;
  this->_has_bits_[0] |= 0x40u;
  if ( buildversion == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->buildversion_ = v4;
  }
  return this->buildversion_;
}


// ========================================================================
// __unwind$194667
// EA  : 0x82F5DED4
// RVA : 0x00F5DED4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194667(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_buildtimestamp@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DF08
// RVA : 0x00F5DF08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_buildtimestamp(idreports::MapReport *this)
{
  std::string *buildtimestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  buildtimestamp = this->buildtimestamp_;
  this->_has_bits_[0] |= 0x80u;
  if ( buildtimestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->buildtimestamp_ = v4;
  }
  return this->buildtimestamp_;
}


// ========================================================================
// __unwind$194777
// EA  : 0x82F5DFB4
// RVA : 0x00F5DFB4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194777(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_game@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5DFE8
// RVA : 0x00F5DFE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_game(idreports::ViewNoteReport *this)
{
  std::string *game; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->game_ = v4;
  }
  return this->game_;
}


// ========================================================================
// __unwind$194887
// EA  : 0x82F5E094
// RVA : 0x00F5E094
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194887(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E0C8
// RVA : 0x00F5E0C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_username(idreports::ViewNoteReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$194997
// EA  : 0x82F5E174
// RVA : 0x00F5E174
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_194997(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_reportedby@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E1A8
// RVA : 0x00F5E1A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_reportedby(idreports::ViewNoteReport *this)
{
  std::string *reportedby; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  reportedby = this->reportedby_;
  this->_has_bits_[0] |= 4u;
  if ( reportedby == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->reportedby_ = v4;
  }
  return this->reportedby_;
}


// ========================================================================
// __unwind$195107
// EA  : 0x82F5E254
// RVA : 0x00F5E254
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195107(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_platform@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E288
// RVA : 0x00F5E288
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_platform(idreports::ViewNoteReport *this)
{
  std::string *platform; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 0x10u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->platform_ = v4;
  }
  return this->platform_;
}


// ========================================================================
// __unwind$195217
// EA  : 0x82F5E334
// RVA : 0x00F5E334
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195217(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_timestamp@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E368
// RVA : 0x00F5E368
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_timestamp(idreports::ViewNoteReport *this)
{
  std::string *timestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x80u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->timestamp_ = v4;
  }
  return this->timestamp_;
}


// ========================================================================
// __unwind$195327
// EA  : 0x82F5E414
// RVA : 0x00F5E414
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195327(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_launchcommand@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E448
// RVA : 0x00F5E448
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_launchcommand(idreports::ViewNoteReport *this)
{
  std::string *launchcommand; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x100u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->launchcommand_ = v4;
  }
  return this->launchcommand_;
}


// ========================================================================
// __unwind$195437
// EA  : 0x82F5E4F4
// RVA : 0x00F5E4F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195437(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepath@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E528
// RVA : 0x00F5E528
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_vtfilepath(idreports::ViewNoteReport *this)
{
  std::string *vtfilepath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepath_ = v4;
  }
  return this->vtfilepath_;
}


// ========================================================================
// __unwind$195547
// EA  : 0x82F5E5D4
// RVA : 0x00F5E5D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195547(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepathvmtroverride@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E608
// RVA : 0x00F5E608
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_vtfilepathvmtroverride(idreports::ViewNoteReport *this)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x400u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v4;
  }
  return this->vtfilepathvmtroverride_;
}


// ========================================================================
// __unwind$195657
// EA  : 0x82F5E6B4
// RVA : 0x00F5E6B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195657(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_bugtitle@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E6E8
// RVA : 0x00F5E6E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_bugtitle(idreports::ViewNoteReport *this)
{
  std::string *bugtitle; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  bugtitle = this->bugtitle_;
  this->_has_bits_[0] |= 0x800u;
  if ( bugtitle == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->bugtitle_ = v4;
  }
  return this->bugtitle_;
}


// ========================================================================
// __unwind$195767
// EA  : 0x82F5E794
// RVA : 0x00F5E794
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195767(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_tasktype@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E7C8
// RVA : 0x00F5E7C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_tasktype(idreports::ViewNoteReport *this)
{
  std::string *tasktype; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  tasktype = this->tasktype_;
  this->_has_bits_[0] |= 0x1000u;
  if ( tasktype == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->tasktype_ = v4;
  }
  return this->tasktype_;
}


// ========================================================================
// __unwind$195877
// EA  : 0x82F5E874
// RVA : 0x00F5E874
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195877(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_reprosteps@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E8A8
// RVA : 0x00F5E8A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_reprosteps(idreports::ViewNoteReport *this)
{
  std::string *reprosteps; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  reprosteps = this->reprosteps_;
  this->_has_bits_[0] |= 0x2000u;
  if ( reprosteps == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->reprosteps_ = v4;
  }
  return this->reprosteps_;
}


// ========================================================================
// __unwind$195987
// EA  : 0x82F5E954
// RVA : 0x00F5E954
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_195987(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_details@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5E988
// RVA : 0x00F5E988
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_details(idreports::ViewNoteReport *this)
{
  std::string *details; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  details = this->details_;
  this->_has_bits_[0] |= 0x4000u;
  if ( details == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->details_ = v4;
  }
  return this->details_;
}


// ========================================================================
// __unwind$196097
// EA  : 0x82F5EA34
// RVA : 0x00F5EA34
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196097(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_severity@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EA68
// RVA : 0x00F5EA68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_severity(idreports::ViewNoteReport *this)
{
  std::string *severity; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  severity = this->severity_;
  this->_has_bits_[0] |= 0x8000u;
  if ( severity == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->severity_ = v4;
  }
  return this->severity_;
}


// ========================================================================
// __unwind$196207
// EA  : 0x82F5EB14
// RVA : 0x00F5EB14
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196207(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mappath@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EB48
// RVA : 0x00F5EB48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_mappath(idreports::ViewNoteReport *this)
{
  std::string *mappath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x10000u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->mappath_ = v4;
  }
  return this->mappath_;
}


// ========================================================================
// __unwind$196317
// EA  : 0x82F5EBF4
// RVA : 0x00F5EBF4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196317(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_priority@ViewNoteReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EC28
// RVA : 0x00F5EC28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::ViewNoteReport::mutable_priority(idreports::ViewNoteReport *this)
{
  std::string *priority; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  priority = this->priority_;
  this->_has_bits_[0] |= 0x20000u;
  if ( priority == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->priority_ = v4;
  }
  return this->priority_;
}


// ========================================================================
// __unwind$196427
// EA  : 0x82F5ECD4
// RVA : 0x00F5ECD4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196427(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_edi@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5ED08
// RVA : 0x00F5ED08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_edi(idreports::RegisterInfo *this)
{
  std::string *edi; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  edi = this->edi_;
  this->_has_bits_[0] |= 1u;
  if ( edi == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->edi_ = v4;
  }
  return this->edi_;
}


// ========================================================================
// __unwind$196647
// EA  : 0x82F5EDB4
// RVA : 0x00F5EDB4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196647(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_esi@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EDE8
// RVA : 0x00F5EDE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_esi(idreports::RegisterInfo *this)
{
  std::string *esi; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  esi = this->esi_;
  this->_has_bits_[0] |= 2u;
  if ( esi == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->esi_ = v4;
  }
  return this->esi_;
}


// ========================================================================
// __unwind$196757
// EA  : 0x82F5EE94
// RVA : 0x00F5EE94
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196757(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_eax@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EEC8
// RVA : 0x00F5EEC8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_eax(idreports::RegisterInfo *this)
{
  std::string *eax; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  eax = this->eax_;
  this->_has_bits_[0] |= 4u;
  if ( eax == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->eax_ = v4;
  }
  return this->eax_;
}


// ========================================================================
// __unwind$196867
// EA  : 0x82F5EF74
// RVA : 0x00F5EF74
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196867(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_ebx@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5EFA8
// RVA : 0x00F5EFA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_ebx(idreports::RegisterInfo *this)
{
  std::string *ebx; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  ebx = this->ebx_;
  this->_has_bits_[0] |= 8u;
  if ( ebx == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->ebx_ = v4;
  }
  return this->ebx_;
}


// ========================================================================
// __unwind$196977
// EA  : 0x82F5F054
// RVA : 0x00F5F054
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_196977(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_ecx@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F088
// RVA : 0x00F5F088
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_ecx(idreports::RegisterInfo *this)
{
  std::string *ecx; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  ecx = this->ecx_;
  this->_has_bits_[0] |= 0x10u;
  if ( ecx == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->ecx_ = v4;
  }
  return this->ecx_;
}


// ========================================================================
// __unwind$197087
// EA  : 0x82F5F134
// RVA : 0x00F5F134
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197087(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_edx@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F168
// RVA : 0x00F5F168
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_edx(idreports::RegisterInfo *this)
{
  std::string *edx; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  edx = this->edx_;
  this->_has_bits_[0] |= 0x20u;
  if ( edx == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->edx_ = v4;
  }
  return this->edx_;
}


// ========================================================================
// __unwind$197197
// EA  : 0x82F5F214
// RVA : 0x00F5F214
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197197(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_eip@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F248
// RVA : 0x00F5F248
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_eip(idreports::RegisterInfo *this)
{
  std::string *eip; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  eip = this->eip_;
  this->_has_bits_[0] |= 0x40u;
  if ( eip == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->eip_ = v4;
  }
  return this->eip_;
}


// ========================================================================
// __unwind$197307
// EA  : 0x82F5F2F4
// RVA : 0x00F5F2F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197307(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_ebp@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F328
// RVA : 0x00F5F328
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_ebp(idreports::RegisterInfo *this)
{
  std::string *ebp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  ebp = this->ebp_;
  this->_has_bits_[0] |= 0x80u;
  if ( ebp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->ebp_ = v4;
  }
  return this->ebp_;
}


// ========================================================================
// __unwind$197417
// EA  : 0x82F5F3D4
// RVA : 0x00F5F3D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197417(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_esp@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F408
// RVA : 0x00F5F408
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_esp(idreports::RegisterInfo *this)
{
  std::string *esp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  esp = this->esp_;
  this->_has_bits_[0] |= 0x100u;
  if ( esp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->esp_ = v4;
  }
  return this->esp_;
}


// ========================================================================
// __unwind$197527
// EA  : 0x82F5F4B4
// RVA : 0x00F5F4B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197527(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_eflags@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F4E8
// RVA : 0x00F5F4E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_eflags(idreports::RegisterInfo *this)
{
  std::string *eflags; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  eflags = this->eflags_;
  this->_has_bits_[0] |= 0x200u;
  if ( eflags == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->eflags_ = v4;
  }
  return this->eflags_;
}


// ========================================================================
// __unwind$197637
// EA  : 0x82F5F594
// RVA : 0x00F5F594
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197637(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_segcs@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F5C8
// RVA : 0x00F5F5C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_segcs(idreports::RegisterInfo *this)
{
  std::string *segcs; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  segcs = this->segcs_;
  this->_has_bits_[0] |= 0x400u;
  if ( segcs == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->segcs_ = v4;
  }
  return this->segcs_;
}


// ========================================================================
// __unwind$197747
// EA  : 0x82F5F674
// RVA : 0x00F5F674
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197747(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_segss@RegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F6A8
// RVA : 0x00F5F6A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::RegisterInfo::mutable_segss(idreports::RegisterInfo *this)
{
  std::string *segss; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  segss = this->segss_;
  this->_has_bits_[0] |= 0x800u;
  if ( segss == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->segss_ = v4;
  }
  return this->segss_;
}


// ========================================================================
// __unwind$197857
// EA  : 0x82F5F754
// RVA : 0x00F5F754
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_197857(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_consolename@Xbox360KitInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F788
// RVA : 0x00F5F788
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360KitInfo::mutable_consolename(idreports::Xbox360KitInfo *this)
{
  std::string *consolename; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  consolename = this->consolename_;
  this->_has_bits_[0] |= 0x20u;
  if ( consolename == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->consolename_ = v4;
  }
  return this->consolename_;
}


// ========================================================================
// __unwind$198082
// EA  : 0x82F5F834
// RVA : 0x00F5F834
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198082(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_msr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F868
// RVA : 0x00F5F868
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_msr(idreports::XenonRegisterInfo *this)
{
  std::string *msr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  msr = this->msr_;
  this->_has_bits_[0] |= 1u;
  if ( msr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->msr_ = v4;
  }
  return this->msr_;
}


// ========================================================================
// __unwind$198192
// EA  : 0x82F5F914
// RVA : 0x00F5F914
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198192(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_iar@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5F948
// RVA : 0x00F5F948
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_iar(idreports::XenonRegisterInfo *this)
{
  std::string *iar; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  iar = this->iar_;
  this->_has_bits_[0] |= 2u;
  if ( iar == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->iar_ = v4;
  }
  return this->iar_;
}


// ========================================================================
// __unwind$198302
// EA  : 0x82F5F9F4
// RVA : 0x00F5F9F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198302(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_lr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FA28
// RVA : 0x00F5FA28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_lr(idreports::XenonRegisterInfo *this)
{
  std::string *lr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  lr = this->lr_;
  this->_has_bits_[0] |= 4u;
  if ( lr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->lr_ = v4;
  }
  return this->lr_;
}


// ========================================================================
// __unwind$198412
// EA  : 0x82F5FAD4
// RVA : 0x00F5FAD4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198412(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_ctr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FB08
// RVA : 0x00F5FB08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_ctr(idreports::XenonRegisterInfo *this)
{
  std::string *ctr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  ctr = this->ctr_;
  this->_has_bits_[0] |= 8u;
  if ( ctr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->ctr_ = v4;
  }
  return this->ctr_;
}


// ========================================================================
// __unwind$198522
// EA  : 0x82F5FBB4
// RVA : 0x00F5FBB4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198522(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_fpscr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FBE8
// RVA : 0x00F5FBE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_fpscr(idreports::XenonRegisterInfo *this)
{
  std::string *fpscr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  fpscr = this->fpscr_;
  this->_has_bits_[0] |= 0x10u;
  if ( fpscr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->fpscr_ = v4;
  }
  return this->fpscr_;
}


// ========================================================================
// __unwind$198632
// EA  : 0x82F5FC94
// RVA : 0x00F5FC94
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198632(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_cr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FCC8
// RVA : 0x00F5FCC8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_cr(idreports::XenonRegisterInfo *this)
{
  std::string *cr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  cr = this->cr_;
  this->_has_bits_[0] |= 0x40u;
  if ( cr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->cr_ = v4;
  }
  return this->cr_;
}


// ========================================================================
// __unwind$198742
// EA  : 0x82F5FD74
// RVA : 0x00F5FD74
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198742(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_xer@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FDA8
// RVA : 0x00F5FDA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_xer(idreports::XenonRegisterInfo *this)
{
  std::string *xer; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  xer = this->xer_;
  this->_has_bits_[0] |= 0x80u;
  if ( xer == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->xer_ = v4;
  }
  return this->xer_;
}


// ========================================================================
// __unwind$198852
// EA  : 0x82F5FE54
// RVA : 0x00F5FE54
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198852(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vscr@XenonRegisterInfo@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FE88
// RVA : 0x00F5FE88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::XenonRegisterInfo::mutable_vscr(idreports::XenonRegisterInfo *this)
{
  std::string *vscr; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vscr = this->vscr_;
  this->_has_bits_[0] |= 0x200u;
  if ( vscr == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vscr_ = v4;
  }
  return this->vscr_;
}


// ========================================================================
// __unwind$198962
// EA  : 0x82F5FF34
// RVA : 0x00F5FF34
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_198962(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_regionname@PS3VMRegionStats@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F5FF68
// RVA : 0x00F5FF68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3VMRegionStats::mutable_regionname(idreports::PS3VMRegionStats *this)
{
  std::string *regionname; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  regionname = this->regionname_;
  this->_has_bits_[0] |= 1u;
  if ( regionname == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->regionname_ = v4;
  }
  return this->regionname_;
}


// ========================================================================
// __unwind$199197
// EA  : 0x82F60014
// RVA : 0x00F60014
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199197(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_game@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60048
// RVA : 0x00F60048
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_game(idreports::CrashReport *this)
{
  std::string *game; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->game_ = v4;
  }
  return this->game_;
}


// ========================================================================
// __unwind$199312
// EA  : 0x82F600F4
// RVA : 0x00F600F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199312(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60128
// RVA : 0x00F60128
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_username(idreports::CrashReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$199422
// EA  : 0x82F601D4
// RVA : 0x00F601D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199422(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_platform@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60208
// RVA : 0x00F60208
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_platform(idreports::CrashReport *this)
{
  std::string *platform; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->platform_ = v4;
  }
  return this->platform_;
}


// ========================================================================
// __unwind$199532
// EA  : 0x82F602B4
// RVA : 0x00F602B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199532(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_buildstring@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F602E8
// RVA : 0x00F602E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_buildstring(idreports::CrashReport *this)
{
  std::string *buildstring; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->buildstring_ = v4;
  }
  return this->buildstring_;
}


// ========================================================================
// __unwind$199642
// EA  : 0x82F60394
// RVA : 0x00F60394
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199642(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_timestamp@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F603C8
// RVA : 0x00F603C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_timestamp(idreports::CrashReport *this)
{
  std::string *timestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->timestamp_ = v4;
  }
  return this->timestamp_;
}


// ========================================================================
// __unwind$199752
// EA  : 0x82F60474
// RVA : 0x00F60474
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199752(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_launchcommand@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F604A8
// RVA : 0x00F604A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_launchcommand(idreports::CrashReport *this)
{
  std::string *launchcommand; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->launchcommand_ = v4;
  }
  return this->launchcommand_;
}


// ========================================================================
// __unwind$199862
// EA  : 0x82F60554
// RVA : 0x00F60554
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199862(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepath@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60588
// RVA : 0x00F60588
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_vtfilepath(idreports::CrashReport *this)
{
  std::string *vtfilepath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepath_ = v4;
  }
  return this->vtfilepath_;
}


// ========================================================================
// __unwind$199972
// EA  : 0x82F60634
// RVA : 0x00F60634
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_199972(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepathvmtroverride@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60668
// RVA : 0x00F60668
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_vtfilepathvmtroverride(idreports::CrashReport *this)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v4;
  }
  return this->vtfilepathvmtroverride_;
}


// ========================================================================
// __unwind$200082
// EA  : 0x82F60714
// RVA : 0x00F60714
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200082(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_bugtitle@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60748
// RVA : 0x00F60748
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_bugtitle(idreports::CrashReport *this)
{
  std::string *bugtitle; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  bugtitle = this->bugtitle_;
  this->_has_bits_[0] |= 0x400u;
  if ( bugtitle == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->bugtitle_ = v4;
  }
  return this->bugtitle_;
}


// ========================================================================
// __unwind$200192
// EA  : 0x82F607F4
// RVA : 0x00F607F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200192(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_reprosteps@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60828
// RVA : 0x00F60828
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_reprosteps(idreports::CrashReport *this)
{
  std::string *reprosteps; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  reprosteps = this->reprosteps_;
  this->_has_bits_[0] |= 0x800u;
  if ( reprosteps == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->reprosteps_ = v4;
  }
  return this->reprosteps_;
}


// ========================================================================
// __unwind$200302
// EA  : 0x82F608D4
// RVA : 0x00F608D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200302(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_details@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60908
// RVA : 0x00F60908
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_details(idreports::CrashReport *this)
{
  std::string *details; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  details = this->details_;
  this->_has_bits_[0] |= 0x1000u;
  if ( details == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->details_ = v4;
  }
  return this->details_;
}


// ========================================================================
// __unwind$200412
// EA  : 0x82F609B4
// RVA : 0x00F609B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200412(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_severity@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F609E8
// RVA : 0x00F609E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_severity(idreports::CrashReport *this)
{
  std::string *severity; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  severity = this->severity_;
  this->_has_bits_[0] |= 0x2000u;
  if ( severity == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->severity_ = v4;
  }
  return this->severity_;
}


// ========================================================================
// __unwind$200522
// EA  : 0x82F60A94
// RVA : 0x00F60A94
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200522(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_component@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60AC8
// RVA : 0x00F60AC8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_component(idreports::CrashReport *this)
{
  std::string *component; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  component = this->component_;
  this->_has_bits_[0] |= 0x4000u;
  if ( component == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->component_ = v4;
  }
  return this->component_;
}


// ========================================================================
// __unwind$200632
// EA  : 0x82F60B74
// RVA : 0x00F60B74
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200632(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mappath@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60BA8
// RVA : 0x00F60BA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_mappath(idreports::CrashReport *this)
{
  std::string *mappath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x8000u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->mappath_ = v4;
  }
  return this->mappath_;
}


// ========================================================================
// __unwind$200742
// EA  : 0x82F60C54
// RVA : 0x00F60C54
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200742(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_priority@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60C88
// RVA : 0x00F60C88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_priority(idreports::CrashReport *this)
{
  std::string *priority; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  priority = this->priority_;
  this->_has_bits_[0] |= 0x10000u;
  if ( priority == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->priority_ = v4;
  }
  return this->priority_;
}


// ========================================================================
// __unwind$200852
// EA  : 0x82F60D34
// RVA : 0x00F60D34
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200852(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_localfilename@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60D68
// RVA : 0x00F60D68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_localfilename(idreports::CrashReport *this)
{
  std::string *localfilename; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  localfilename = this->localfilename_;
  this->_has_bits_[0] |= 0x20000u;
  if ( localfilename == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->localfilename_ = v4;
  }
  return this->localfilename_;
}


// ========================================================================
// __unwind$200962
// EA  : 0x82F60E14
// RVA : 0x00F60E14
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_200962(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_dmppath@CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60E48
// RVA : 0x00F60E48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::CrashReport::mutable_dmppath(idreports::CrashReport *this)
{
  std::string *dmppath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  dmppath = this->dmppath_;
  this->_has_bits_[0] |= 0x40000u;
  if ( dmppath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->dmppath_ = v4;
  }
  return this->dmppath_;
}


// ========================================================================
// __unwind$201072
// EA  : 0x82F60EF4
// RVA : 0x00F60EF4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201072(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_game@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F60F28
// RVA : 0x00F60F28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_game(idreports::Xbox360CrashReport *this)
{
  std::string *game; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->game_ = v4;
  }
  return this->game_;
}


// ========================================================================
// __unwind$201187
// EA  : 0x82F60FD4
// RVA : 0x00F60FD4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201187(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61008
// RVA : 0x00F61008
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_username(idreports::Xbox360CrashReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$201297
// EA  : 0x82F610B4
// RVA : 0x00F610B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201297(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_platform@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F610E8
// RVA : 0x00F610E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_platform(idreports::Xbox360CrashReport *this)
{
  std::string *platform; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->platform_ = v4;
  }
  return this->platform_;
}


// ========================================================================
// __unwind$201407
// EA  : 0x82F61194
// RVA : 0x00F61194
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201407(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_buildstring@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F611C8
// RVA : 0x00F611C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_buildstring(idreports::Xbox360CrashReport *this)
{
  std::string *buildstring; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->buildstring_ = v4;
  }
  return this->buildstring_;
}


// ========================================================================
// __unwind$201517
// EA  : 0x82F61274
// RVA : 0x00F61274
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201517(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_timestamp@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F612A8
// RVA : 0x00F612A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_timestamp(idreports::Xbox360CrashReport *this)
{
  std::string *timestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->timestamp_ = v4;
  }
  return this->timestamp_;
}


// ========================================================================
// __unwind$201627
// EA  : 0x82F61354
// RVA : 0x00F61354
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201627(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_launchcommand@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61388
// RVA : 0x00F61388
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_launchcommand(idreports::Xbox360CrashReport *this)
{
  std::string *launchcommand; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->launchcommand_ = v4;
  }
  return this->launchcommand_;
}


// ========================================================================
// __unwind$201737
// EA  : 0x82F61434
// RVA : 0x00F61434
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201737(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepath@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61468
// RVA : 0x00F61468
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_vtfilepath(idreports::Xbox360CrashReport *this)
{
  std::string *vtfilepath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepath_ = v4;
  }
  return this->vtfilepath_;
}


// ========================================================================
// __unwind$201847
// EA  : 0x82F61514
// RVA : 0x00F61514
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201847(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepathvmtroverride@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61548
// RVA : 0x00F61548
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_vtfilepathvmtroverride(
        idreports::Xbox360CrashReport *this)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v4;
  }
  return this->vtfilepathvmtroverride_;
}


// ========================================================================
// __unwind$201957
// EA  : 0x82F615F4
// RVA : 0x00F615F4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_201957(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mappath@Xbox360CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61628
// RVA : 0x00F61628
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::Xbox360CrashReport::mutable_mappath(idreports::Xbox360CrashReport *this)
{
  std::string *mappath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x400u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->mappath_ = v4;
  }
  return this->mappath_;
}


// ========================================================================
// __unwind$202067
// EA  : 0x82F616D4
// RVA : 0x00F616D4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202067(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_game@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61708
// RVA : 0x00F61708
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_game(idreports::PS3CrashReport *this)
{
  std::string *game; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->game_ = v4;
  }
  return this->game_;
}


// ========================================================================
// __unwind$202195
// EA  : 0x82F617B4
// RVA : 0x00F617B4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202195(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F617E8
// RVA : 0x00F617E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_username(idreports::PS3CrashReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$202305
// EA  : 0x82F61894
// RVA : 0x00F61894
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202305(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_platform@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F618C8
// RVA : 0x00F618C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_platform(idreports::PS3CrashReport *this)
{
  std::string *platform; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->platform_ = v4;
  }
  return this->platform_;
}


// ========================================================================
// __unwind$202415
// EA  : 0x82F61974
// RVA : 0x00F61974
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202415(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_buildstring@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F619A8
// RVA : 0x00F619A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_buildstring(idreports::PS3CrashReport *this)
{
  std::string *buildstring; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->buildstring_ = v4;
  }
  return this->buildstring_;
}


// ========================================================================
// __unwind$202525
// EA  : 0x82F61A54
// RVA : 0x00F61A54
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202525(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_timestamp@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61A88
// RVA : 0x00F61A88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_timestamp(idreports::PS3CrashReport *this)
{
  std::string *timestamp; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->timestamp_ = v4;
  }
  return this->timestamp_;
}


// ========================================================================
// __unwind$202635
// EA  : 0x82F61B34
// RVA : 0x00F61B34
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202635(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_launchcommand@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61B68
// RVA : 0x00F61B68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_launchcommand(idreports::PS3CrashReport *this)
{
  std::string *launchcommand; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->launchcommand_ = v4;
  }
  return this->launchcommand_;
}


// ========================================================================
// __unwind$202745
// EA  : 0x82F61C14
// RVA : 0x00F61C14
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202745(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepath@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61C48
// RVA : 0x00F61C48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_vtfilepath(idreports::PS3CrashReport *this)
{
  std::string *vtfilepath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepath_ = v4;
  }
  return this->vtfilepath_;
}


// ========================================================================
// __unwind$202855
// EA  : 0x82F61CF4
// RVA : 0x00F61CF4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202855(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_vtfilepathvmtroverride@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61D28
// RVA : 0x00F61D28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_vtfilepathvmtroverride(idreports::PS3CrashReport *this)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v4;
  }
  return this->vtfilepathvmtroverride_;
}


// ========================================================================
// __unwind$202965
// EA  : 0x82F61DD4
// RVA : 0x00F61DD4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_202965(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mappath@PS3CrashReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F61E08
// RVA : 0x00F61E08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::PS3CrashReport::mutable_mappath(idreports::PS3CrashReport *this)
{
  std::string *mappath; // r9
  std::string *v3; // r3
  std::string *v4; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x400u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v4 = v3;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->mappath_ = v4;
  }
  return this->mappath_;
}


// ========================================================================
// __unwind$203075
// EA  : 0x82F61EB4
// RVA : 0x00F61EB4
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_203075(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?mutable_ppuregisters@PS3CrashReport@idreports@@QAAPAVPPURegisterInfo@2@XZ
// EA  : 0x82F61EE0
// RVA : 0x00F61EE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::PPURegisterInfo *__fastcall idreports::PS3CrashReport::mutable_ppuregisters(idreports::PS3CrashReport *this)
{
  idreports::PPURegisterInfo *ppuregisters; // r10
  _DWORD *v3; // r3
  __int64 v4; // r11

  ppuregisters = this->ppuregisters_;
  this->_has_bits_[0] |= 0x2000u;
  if ( ppuregisters == nullptr )
  {
    v3 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: 0xC0u,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      *v3 = &idreports::PPURegisterInfo::`vftable';
      LODWORD(v4) = 0;
      v3[3] = 0;
      v3[4] = 4;
      v3[2] = v3 + 6;
      v3[26] = 4;
      v3[24] = v3 + 28;
      v3[25] = 0;
      v3[39] = 4;
      HIDWORD(v4) = v3;
      v3[36] = v3 + 40;
      v3[37] = 0;
      v3[38] = 0;
      v3[45] = 0;
      v3[20] = 0;
      *((_QWORD *)v3 + 7) = v4;
      *((_QWORD *)v3 + 8) = v4;
      *((_QWORD *)v3 + 9) = v4;
      *((_QWORD *)v3 + 11) = v4;
      v3[21] = 0;
      v3[44] = 0;
      v3[46] = 0;
    }
    else
    {
      HIDWORD(v4) = 0;
    }
    this->ppuregisters_ = (idreports::PPURegisterInfo *)HIDWORD(v4);
  }
  return this->ppuregisters_;
}


// ========================================================================
// ?mutable_memoryinfo@PS3CrashReport@idreports@@QAAPAVPS3MemoryInfo@2@XZ
// EA  : 0x82F61FE0
// RVA : 0x00F61FE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

idreports::PS3MemoryInfo *__fastcall idreports::PS3CrashReport::mutable_memoryinfo(idreports::PS3CrashReport *this)
{
  idreports::PS3MemoryInfo *memoryinfo; // r10
  _DWORD *v3; // r3
  __int64 v4; // r11

  memoryinfo = this->memoryinfo_;
  this->_has_bits_[0] |= 0x8000u;
  if ( memoryinfo == nullptr )
  {
    v3 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: 0x68u,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      LODWORD(v4) = 0;
      *v3 = &idreports::PS3MemoryInfo::`vftable';
      v3[17] = 0;
      v3[16] = v3 + 20;
      HIDWORD(v4) = v3;
      v3[18] = 0;
      v3[19] = 4;
      v3[24] = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      v3[4] = 0;
      v3[5] = 0;
      v3[6] = 0;
      *((_QWORD *)v3 + 4) = v4;
      *((_QWORD *)v3 + 5) = v4;
      *((_QWORD *)v3 + 6) = v4;
      *((_QWORD *)v3 + 7) = v4;
      v3[25] = 0;
    }
    else
    {
      HIDWORD(v4) = 0;
    }
    this->memoryinfo_ = (idreports::PS3MemoryInfo *)HIDWORD(v4);
  }
  return this->memoryinfo_;
}


// ========================================================================
// ?set_attachment@Attachment@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F4B0
// RVA : 0x00F6F4B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Attachment::set_attachment(idreports::Attachment *this, const std::string *value)
{
  std::string *attachment; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  attachment = this->attachment_;
  this->_has_bits_[0] |= 1u;
  if ( attachment == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->attachment_ = v6;
  }
  std::string::assign(this: this->attachment_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228406
// EA  : 0x82F6F558
// RVA : 0x00F6F558
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228406(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_filename@Attachment@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F588
// RVA : 0x00F6F588
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Attachment::set_filename(idreports::Attachment *this, const std::string *value)
{
  std::string *filename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 2u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->filename_ = v6;
  }
  std::string::assign(this: this->filename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228521
// EA  : 0x82F6F630
// RVA : 0x00F6F630
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228521(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@LogEvent@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F660
// RVA : 0x00F6F660
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_timestamp(idreports::LogEvent *this, const std::string *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 1u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  std::string::assign(this: this->timestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228636
// EA  : 0x82F6F708
// RVA : 0x00F6F708
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228636(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_message@LogEvent@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F738
// RVA : 0x00F6F738
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_message(idreports::LogEvent *this, const std::string *value)
{
  std::string *message; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  message = this->message_;
  this->_has_bits_[0] |= 4u;
  if ( message == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->message_ = v6;
  }
  std::string::assign(this: this->message_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228751
// EA  : 0x82F6F7E0
// RVA : 0x00F6F7E0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228751(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_data@LogEvent@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F810
// RVA : 0x00F6F810
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_data(idreports::LogEvent *this, const std::string *value)
{
  std::string *data; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  data = this->data_;
  this->_has_bits_[0] |= 0x10u;
  if ( data == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->data_ = v6;
  }
  std::string::assign(this: this->data_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228866
// EA  : 0x82F6F8B8
// RVA : 0x00F6F8B8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228866(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_datatype@LogEvent@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F8E8
// RVA : 0x00F6F8E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::LogEvent::set_datatype(idreports::LogEvent *this, const std::string *value)
{
  std::string *datatype; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  datatype = this->datatype_;
  this->_has_bits_[0] |= 0x20u;
  if ( datatype == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->datatype_ = v6;
  }
  std::string::assign(this: this->datatype_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$228981
// EA  : 0x82F6F990
// RVA : 0x00F6F990
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_228981(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_expcode@ExceptionInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6F9C0
// RVA : 0x00F6F9C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ExceptionInfo::set_expcode(idreports::ExceptionInfo *this, const std::string *value)
{
  std::string *expcode; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  expcode = this->expcode_;
  this->_has_bits_[0] |= 1u;
  if ( expcode == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->expcode_ = v6;
  }
  std::string::assign(this: this->expcode_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229096
// EA  : 0x82F6FA68
// RVA : 0x00F6FA68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229096(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_expaddress@ExceptionInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FA98
// RVA : 0x00F6FA98
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ExceptionInfo::set_expaddress(idreports::ExceptionInfo *this, const std::string *value)
{
  std::string *expaddress; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  expaddress = this->expaddress_;
  this->_has_bits_[0] |= 4u;
  if ( expaddress == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->expaddress_ = v6;
  }
  std::string::assign(this: this->expaddress_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229211
// EA  : 0x82F6FB40
// RVA : 0x00F6FB40
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229211(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_filename@CallstackLine@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FB70
// RVA : 0x00F6FB70
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CallstackLine::set_filename(idreports::CallstackLine *this, const std::string *value)
{
  std::string *filename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 8u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->filename_ = v6;
  }
  std::string::assign(this: this->filename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229441
// EA  : 0x82F6FC18
// RVA : 0x00F6FC18
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229441(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_address@CallstackLine@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FC48
// RVA : 0x00F6FC48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CallstackLine::set_address(idreports::CallstackLine *this, const std::string *value)
{
  std::string *address; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  address = this->address_;
  this->_has_bits_[0] |= 0x10u;
  if ( address == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->address_ = v6;
  }
  std::string::assign(this: this->address_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229556_0
// EA  : 0x82F6FCF0
// RVA : 0x00F6FCF0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229556_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mapname@AssertReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FD20
// RVA : 0x00F6FD20
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::AssertReport::set_mapname(idreports::AssertReport *this, const std::string *value)
{
  std::string *mapname; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mapname = this->mapname_;
  this->_has_bits_[0] |= 1u;
  if ( mapname == &idreports::AssertReport::_default_mapname_ )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mapname_ = v6;
  }
  std::string::assign(this: this->mapname_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229671
// EA  : 0x82F6FDC8
// RVA : 0x00F6FDC8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229671(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mapname@AssertReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F6FDF8
// RVA : 0x00F6FDF8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::AssertReport::mutable_mapname(idreports::AssertReport *this)
{
  std::string *mapname; // r9
  std::string *v3; // r3
  std::string *v4; // r30

  mapname = this->mapname_;
  this->_has_bits_[0] |= 1u;
  if ( mapname == &idreports::AssertReport::_default_mapname_ )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
      std::string::assign(this: v3, _Right: &idreports::AssertReport::_default_mapname_, _Roff: 0, _Count: 0xFFFFFFFF);
    }
    else
    {
      v4 = nullptr;
    }
    this->mapname_ = v4;
  }
  return this->mapname_;
}


// ========================================================================
// __unwind$229786
// EA  : 0x82F6FEA0
// RVA : 0x00F6FEA0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229786(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_filename@AssertReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FED0
// RVA : 0x00F6FED0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::AssertReport::set_filename(idreports::AssertReport *this, const std::string *value)
{
  std::string *filename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  filename = this->filename_;
  this->_has_bits_[0] |= 2u;
  if ( filename == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->filename_ = v6;
  }
  std::string::assign(this: this->filename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$229898
// EA  : 0x82F6FF78
// RVA : 0x00F6FF78
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_229898(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_expression@AssertReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F6FFA8
// RVA : 0x00F6FFA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::AssertReport::set_expression(idreports::AssertReport *this, const std::string *value)
{
  std::string *expression; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  expression = this->expression_;
  this->_has_bits_[0] |= 8u;
  if ( expression == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->expression_ = v6;
  }
  std::string::assign(this: this->expression_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230013_1
// EA  : 0x82F70050
// RVA : 0x00F70050
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230013_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@AssertReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70080
// RVA : 0x00F70080
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::AssertReport::set_username(idreports::AssertReport *this, const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 0x10u;
  if ( username == &idreports::AssertReport::_default_username_ )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230128
// EA  : 0x82F70128
// RVA : 0x00F70128
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230128(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@AssertReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F70158
// RVA : 0x00F70158
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::AssertReport::mutable_username(idreports::AssertReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r30

  username = this->username_;
  this->_has_bits_[0] |= 0x10u;
  if ( username == &idreports::AssertReport::_default_username_ )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
      std::string::assign(this: v3, _Right: &idreports::AssertReport::_default_username_, _Roff: 0, _Count: 0xFFFFFFFF);
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$230243_0
// EA  : 0x82F70200
// RVA : 0x00F70200
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230243_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_message@MapWarning@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70230
// RVA : 0x00F70230
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapWarning::set_message(idreports::MapWarning *this, const std::string *value)
{
  std::string *message; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  message = this->message_;
  this->_has_bits_[0] |= 1u;
  if ( message == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->message_ = v6;
  }
  std::string::assign(this: this->message_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230355
// EA  : 0x82F702D8
// RVA : 0x00F702D8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230355(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mapname@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70308
// RVA : 0x00F70308
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_mapname(idreports::MapReport *this, const std::string *value)
{
  std::string *mapname; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mapname = this->mapname_;
  this->_has_bits_[0] |= 1u;
  if ( mapname == &idreports::MapReport::_default_mapname_ )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mapname_ = v6;
  }
  std::string::assign(this: this->mapname_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230470
// EA  : 0x82F703B0
// RVA : 0x00F703B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230470(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_mapname@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F703E0
// RVA : 0x00F703E0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_mapname(idreports::MapReport *this)
{
  std::string *mapname; // r9
  std::string *v3; // r3
  std::string *v4; // r30

  mapname = this->mapname_;
  this->_has_bits_[0] |= 1u;
  if ( mapname == &idreports::MapReport::_default_mapname_ )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
      std::string::assign(this: v3, _Right: &idreports::MapReport::_default_mapname_, _Roff: 0, _Count: 0xFFFFFFFF);
    }
    else
    {
      v4 = nullptr;
    }
    this->mapname_ = v4;
  }
  return this->mapname_;
}


// ========================================================================
// __unwind$230585
// EA  : 0x82F70488
// RVA : 0x00F70488
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230585(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F704B8
// RVA : 0x00F704B8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_username(idreports::MapReport *this, const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 4u;
  if ( username == &idreports::MapReport::_default_username_ )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230697_0
// EA  : 0x82F70560
// RVA : 0x00F70560
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230697_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_username@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F70590
// RVA : 0x00F70590
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_username(idreports::MapReport *this)
{
  std::string *username; // r9
  std::string *v3; // r3
  std::string *v4; // r30

  username = this->username_;
  this->_has_bits_[0] |= 4u;
  if ( username == &idreports::MapReport::_default_username_ )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
      std::string::assign(this: v3, _Right: &idreports::MapReport::_default_username_, _Roff: 0, _Count: 0xFFFFFFFF);
    }
    else
    {
      v4 = nullptr;
    }
    this->username_ = v4;
  }
  return this->username_;
}


// ========================================================================
// __unwind$230812
// EA  : 0x82F70638
// RVA : 0x00F70638
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230812(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_machinename@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70668
// RVA : 0x00F70668
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_machinename(idreports::MapReport *this, const std::string *value)
{
  std::string *machinename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  machinename = this->machinename_;
  this->_has_bits_[0] |= 8u;
  if ( machinename == &idreports::MapReport::_default_machinename_ )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->machinename_ = v6;
  }
  std::string::assign(this: this->machinename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$230924
// EA  : 0x82F70710
// RVA : 0x00F70710
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_230924(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?mutable_machinename@MapReport@idreports@@QAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x82F70740
// RVA : 0x00F70740
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

std::string *__fastcall idreports::MapReport::mutable_machinename(idreports::MapReport *this)
{
  std::string *machinename; // r9
  std::string *v3; // r3
  std::string *v4; // r30

  machinename = this->machinename_;
  this->_has_bits_[0] |= 8u;
  if ( machinename == &idreports::MapReport::_default_machinename_ )
  {
    v3 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->_Mysize = 0;
      v3->_Myres = 15;
      v3->_Bx._Buf[0] = 0;
      std::string::assign(this: v3, _Right: &idreports::MapReport::_default_machinename_, _Roff: 0, _Count: 0xFFFFFFFF);
    }
    else
    {
      v4 = nullptr;
    }
    this->machinename_ = v4;
  }
  return this->machinename_;
}


// ========================================================================
// __unwind$231039_2
// EA  : 0x82F707E8
// RVA : 0x00F707E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231039_2(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70818
// RVA : 0x00F70818
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_platform(idreports::MapReport *this, const std::string *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 0x10u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  std::string::assign(this: this->platform_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231151
// EA  : 0x82F708C0
// RVA : 0x00F708C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231151(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F708F0
// RVA : 0x00F708F0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_game(idreports::MapReport *this, const std::string *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  game = this->game_;
  this->_has_bits_[0] |= 0x20u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  std::string::assign(this: this->game_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231266
// EA  : 0x82F70998
// RVA : 0x00F70998
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231266(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildversion@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F709C8
// RVA : 0x00F709C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_buildversion(idreports::MapReport *this, const std::string *value)
{
  std::string *buildversion; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  buildversion = this->buildversion_;
  this->_has_bits_[0] |= 0x40u;
  if ( buildversion == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildversion_ = v6;
  }
  std::string::assign(this: this->buildversion_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231381
// EA  : 0x82F70A70
// RVA : 0x00F70A70
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231381(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildtimestamp@MapReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70AA0
// RVA : 0x00F70AA0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::MapReport::set_buildtimestamp(idreports::MapReport *this, const std::string *value)
{
  std::string *buildtimestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  buildtimestamp = this->buildtimestamp_;
  this->_has_bits_[0] |= 0x80u;
  if ( buildtimestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildtimestamp_ = v6;
  }
  std::string::assign(this: this->buildtimestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231496
// EA  : 0x82F70B48
// RVA : 0x00F70B48
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231496(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70B78
// RVA : 0x00F70B78
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_game(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  std::string::assign(this: this->game_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231611
// EA  : 0x82F70C20
// RVA : 0x00F70C20
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231611(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70C50
// RVA : 0x00F70C50
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_username(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231726
// EA  : 0x82F70CF8
// RVA : 0x00F70CF8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231726(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_reportedby@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70D28
// RVA : 0x00F70D28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_reportedby(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *reportedby; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  reportedby = this->reportedby_;
  this->_has_bits_[0] |= 4u;
  if ( reportedby == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->reportedby_ = v6;
  }
  std::string::assign(this: this->reportedby_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231841
// EA  : 0x82F70DD0
// RVA : 0x00F70DD0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231841(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70E00
// RVA : 0x00F70E00
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_platform(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 0x10u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  std::string::assign(this: this->platform_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$231956
// EA  : 0x82F70EA8
// RVA : 0x00F70EA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_231956(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70ED8
// RVA : 0x00F70ED8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_timestamp(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x80u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  std::string::assign(this: this->timestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232071_0
// EA  : 0x82F70F80
// RVA : 0x00F70F80
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232071_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_launchcommand@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F70FB0
// RVA : 0x00F70FB0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_launchcommand(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *launchcommand; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x100u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->launchcommand_ = v6;
  }
  std::string::assign(this: this->launchcommand_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232186
// EA  : 0x82F71058
// RVA : 0x00F71058
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232186(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepath@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71088
// RVA : 0x00F71088
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_vtfilepath(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *vtfilepath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepath_ = v6;
  }
  std::string::assign(this: this->vtfilepath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232301
// EA  : 0x82F71130
// RVA : 0x00F71130
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232301(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepathvmtroverride@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71160
// RVA : 0x00F71160
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_vtfilepathvmtroverride(
        idreports::ViewNoteReport *this,
        const std::string *value)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x400u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v6;
  }
  std::string::assign(this: this->vtfilepathvmtroverride_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232416
// EA  : 0x82F71208
// RVA : 0x00F71208
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232416(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_bugtitle@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71238
// RVA : 0x00F71238
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_bugtitle(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *bugtitle; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  bugtitle = this->bugtitle_;
  this->_has_bits_[0] |= 0x800u;
  if ( bugtitle == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->bugtitle_ = v6;
  }
  std::string::assign(this: this->bugtitle_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232531_0
// EA  : 0x82F712E0
// RVA : 0x00F712E0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232531_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_tasktype@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71310
// RVA : 0x00F71310
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_tasktype(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *tasktype; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  tasktype = this->tasktype_;
  this->_has_bits_[0] |= 0x1000u;
  if ( tasktype == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->tasktype_ = v6;
  }
  std::string::assign(this: this->tasktype_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232646
// EA  : 0x82F713B8
// RVA : 0x00F713B8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232646(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_reprosteps@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F713E8
// RVA : 0x00F713E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_reprosteps(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *reprosteps; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  reprosteps = this->reprosteps_;
  this->_has_bits_[0] |= 0x2000u;
  if ( reprosteps == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->reprosteps_ = v6;
  }
  std::string::assign(this: this->reprosteps_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232761
// EA  : 0x82F71490
// RVA : 0x00F71490
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232761(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_details@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F714C0
// RVA : 0x00F714C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_details(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *details; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  details = this->details_;
  this->_has_bits_[0] |= 0x4000u;
  if ( details == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->details_ = v6;
  }
  std::string::assign(this: this->details_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232876
// EA  : 0x82F71568
// RVA : 0x00F71568
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232876(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_severity@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71598
// RVA : 0x00F71598
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_severity(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *severity; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  severity = this->severity_;
  this->_has_bits_[0] |= 0x8000u;
  if ( severity == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->severity_ = v6;
  }
  std::string::assign(this: this->severity_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$232991
// EA  : 0x82F71640
// RVA : 0x00F71640
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_232991(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mappath@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71670
// RVA : 0x00F71670
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_mappath(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *mappath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x10000u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mappath_ = v6;
  }
  std::string::assign(this: this->mappath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233106
// EA  : 0x82F71718
// RVA : 0x00F71718
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233106(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_priority@ViewNoteReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71748
// RVA : 0x00F71748
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::ViewNoteReport::set_priority(idreports::ViewNoteReport *this, const std::string *value)
{
  std::string *priority; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  priority = this->priority_;
  this->_has_bits_[0] |= 0x20000u;
  if ( priority == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->priority_ = v6;
  }
  std::string::assign(this: this->priority_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233221
// EA  : 0x82F717F0
// RVA : 0x00F717F0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233221(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_functioncall@CallstackLine@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71820
// RVA : 0x00F71820
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CallstackLine::set_functioncall(idreports::PS3ExceptionInfo *this, const std::string *value)
{
  std::string *exceptionname; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  exceptionname = this->exceptionname_;
  this->_has_bits_[0] |= 1u;
  if ( exceptionname == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->exceptionname_ = v6;
  }
  std::string::assign(this: this->exceptionname_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235981
// EA  : 0x82F718C8
// RVA : 0x00F718C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235981(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_edi@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F718F8
// RVA : 0x00F718F8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_edi(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *edi; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  edi = this->edi_;
  this->_has_bits_[0] |= 1u;
  if ( edi == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->edi_ = v6;
  }
  std::string::assign(this: this->edi_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233451
// EA  : 0x82F719A0
// RVA : 0x00F719A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233451(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_esi@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F719D0
// RVA : 0x00F719D0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_esi(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *esi; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  esi = this->esi_;
  this->_has_bits_[0] |= 2u;
  if ( esi == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->esi_ = v6;
  }
  std::string::assign(this: this->esi_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233566
// EA  : 0x82F71A78
// RVA : 0x00F71A78
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233566(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_eax@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71AA8
// RVA : 0x00F71AA8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_eax(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *eax; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  eax = this->eax_;
  this->_has_bits_[0] |= 4u;
  if ( eax == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->eax_ = v6;
  }
  std::string::assign(this: this->eax_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233681
// EA  : 0x82F71B50
// RVA : 0x00F71B50
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233681(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_ebx@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71B80
// RVA : 0x00F71B80
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_ebx(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *ebx; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  ebx = this->ebx_;
  this->_has_bits_[0] |= 8u;
  if ( ebx == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->ebx_ = v6;
  }
  std::string::assign(this: this->ebx_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233796
// EA  : 0x82F71C28
// RVA : 0x00F71C28
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233796(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_ecx@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71C58
// RVA : 0x00F71C58
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_ecx(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *ecx; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  ecx = this->ecx_;
  this->_has_bits_[0] |= 0x10u;
  if ( ecx == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->ecx_ = v6;
  }
  std::string::assign(this: this->ecx_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$233911
// EA  : 0x82F71D00
// RVA : 0x00F71D00
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_233911(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_edx@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71D30
// RVA : 0x00F71D30
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_edx(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *edx; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  edx = this->edx_;
  this->_has_bits_[0] |= 0x20u;
  if ( edx == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->edx_ = v6;
  }
  std::string::assign(this: this->edx_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234026
// EA  : 0x82F71DD8
// RVA : 0x00F71DD8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234026(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_eip@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71E08
// RVA : 0x00F71E08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_eip(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *eip; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  eip = this->eip_;
  this->_has_bits_[0] |= 0x40u;
  if ( eip == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->eip_ = v6;
  }
  std::string::assign(this: this->eip_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234141
// EA  : 0x82F71EB0
// RVA : 0x00F71EB0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234141(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_ebp@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71EE0
// RVA : 0x00F71EE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_ebp(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *ebp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  ebp = this->ebp_;
  this->_has_bits_[0] |= 0x80u;
  if ( ebp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->ebp_ = v6;
  }
  std::string::assign(this: this->ebp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234256_0
// EA  : 0x82F71F88
// RVA : 0x00F71F88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234256_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_esp@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F71FB8
// RVA : 0x00F71FB8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_esp(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *esp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  esp = this->esp_;
  this->_has_bits_[0] |= 0x100u;
  if ( esp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->esp_ = v6;
  }
  std::string::assign(this: this->esp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234371
// EA  : 0x82F72060
// RVA : 0x00F72060
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234371(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_eflags@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72090
// RVA : 0x00F72090
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_eflags(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *eflags; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  eflags = this->eflags_;
  this->_has_bits_[0] |= 0x200u;
  if ( eflags == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->eflags_ = v6;
  }
  std::string::assign(this: this->eflags_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234486_0
// EA  : 0x82F72138
// RVA : 0x00F72138
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234486_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_segcs@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72168
// RVA : 0x00F72168
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_segcs(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *segcs; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  segcs = this->segcs_;
  this->_has_bits_[0] |= 0x400u;
  if ( segcs == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->segcs_ = v6;
  }
  std::string::assign(this: this->segcs_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234601
// EA  : 0x82F72210
// RVA : 0x00F72210
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234601(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_segss@RegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72240
// RVA : 0x00F72240
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::RegisterInfo::set_segss(idreports::RegisterInfo *this, const std::string *value)
{
  std::string *segss; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  segss = this->segss_;
  this->_has_bits_[0] |= 0x800u;
  if ( segss == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->segss_ = v6;
  }
  std::string::assign(this: this->segss_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234716_0
// EA  : 0x82F722E8
// RVA : 0x00F722E8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234716_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_consolename@Xbox360KitInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72318
// RVA : 0x00F72318
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360KitInfo::set_consolename(idreports::Xbox360KitInfo *this, const std::string *value)
{
  std::string *consolename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  consolename = this->consolename_;
  this->_has_bits_[0] |= 0x20u;
  if ( consolename == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->consolename_ = v6;
  }
  std::string::assign(this: this->consolename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$234946
// EA  : 0x82F723C0
// RVA : 0x00F723C0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_234946(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_msr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F723F0
// RVA : 0x00F723F0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_msr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *msr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  msr = this->msr_;
  this->_has_bits_[0] |= 1u;
  if ( msr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->msr_ = v6;
  }
  std::string::assign(this: this->msr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235061
// EA  : 0x82F72498
// RVA : 0x00F72498
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235061(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_iar@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F724C8
// RVA : 0x00F724C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_iar(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *iar; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  iar = this->iar_;
  this->_has_bits_[0] |= 2u;
  if ( iar == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->iar_ = v6;
  }
  std::string::assign(this: this->iar_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235176
// EA  : 0x82F72570
// RVA : 0x00F72570
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235176(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_lr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F725A0
// RVA : 0x00F725A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_lr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *lr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  lr = this->lr_;
  this->_has_bits_[0] |= 4u;
  if ( lr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->lr_ = v6;
  }
  std::string::assign(this: this->lr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235291
// EA  : 0x82F72648
// RVA : 0x00F72648
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235291(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_ctr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72678
// RVA : 0x00F72678
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_ctr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *ctr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  ctr = this->ctr_;
  this->_has_bits_[0] |= 8u;
  if ( ctr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->ctr_ = v6;
  }
  std::string::assign(this: this->ctr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235406_0
// EA  : 0x82F72720
// RVA : 0x00F72720
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235406_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_fpscr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72750
// RVA : 0x00F72750
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_fpscr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *fpscr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  fpscr = this->fpscr_;
  this->_has_bits_[0] |= 0x10u;
  if ( fpscr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->fpscr_ = v6;
  }
  std::string::assign(this: this->fpscr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235521_0
// EA  : 0x82F727F8
// RVA : 0x00F727F8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235521_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_cr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72828
// RVA : 0x00F72828
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_cr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *cr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  cr = this->cr_;
  this->_has_bits_[0] |= 0x40u;
  if ( cr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->cr_ = v6;
  }
  std::string::assign(this: this->cr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235636
// EA  : 0x82F728D0
// RVA : 0x00F728D0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235636(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_xer@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72900
// RVA : 0x00F72900
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_xer(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *xer; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  xer = this->xer_;
  this->_has_bits_[0] |= 0x80u;
  if ( xer == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->xer_ = v6;
  }
  std::string::assign(this: this->xer_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235751
// EA  : 0x82F729A8
// RVA : 0x00F729A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235751(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vscr@XenonRegisterInfo@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F729D8
// RVA : 0x00F729D8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::XenonRegisterInfo::set_vscr(idreports::XenonRegisterInfo *this, const std::string *value)
{
  std::string *vscr; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vscr = this->vscr_;
  this->_has_bits_[0] |= 0x200u;
  if ( vscr == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vscr_ = v6;
  }
  std::string::assign(this: this->vscr_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$235866
// EA  : 0x82F72A80
// RVA : 0x00F72A80
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_235866(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_regionname@PS3VMRegionStats@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72AB0
// RVA : 0x00F72AB0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3VMRegionStats::set_regionname(
        idreports::PS3VMRegionStats *this,
        const std::string *value)
{
  std::string *regionname; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  regionname = this->regionname_;
  this->_has_bits_[0] |= 1u;
  if ( regionname == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->regionname_ = v6;
  }
  std::string::assign(this: this->regionname_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236096
// EA  : 0x82F72B58
// RVA : 0x00F72B58
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236096(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72B88
// RVA : 0x00F72B88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_game(idreports::CrashReport *this, const std::string *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  std::string::assign(this: this->game_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236211
// EA  : 0x82F72C30
// RVA : 0x00F72C30
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236211(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72C60
// RVA : 0x00F72C60
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_username(idreports::CrashReport *this, const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236326
// EA  : 0x82F72D08
// RVA : 0x00F72D08
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236326(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72D38
// RVA : 0x00F72D38
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_platform(idreports::CrashReport *this, const std::string *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  std::string::assign(this: this->platform_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236441_0
// EA  : 0x82F72DE0
// RVA : 0x00F72DE0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236441_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildstring@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72E10
// RVA : 0x00F72E10
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_buildstring(idreports::CrashReport *this, const std::string *value)
{
  std::string *buildstring; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildstring_ = v6;
  }
  std::string::assign(this: this->buildstring_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236556
// EA  : 0x82F72EB8
// RVA : 0x00F72EB8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236556(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72EE8
// RVA : 0x00F72EE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_timestamp(idreports::CrashReport *this, const std::string *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  std::string::assign(this: this->timestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236671
// EA  : 0x82F72F90
// RVA : 0x00F72F90
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236671(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_launchcommand@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F72FC0
// RVA : 0x00F72FC0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_launchcommand(idreports::CrashReport *this, const std::string *value)
{
  std::string *launchcommand; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->launchcommand_ = v6;
  }
  std::string::assign(this: this->launchcommand_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236786
// EA  : 0x82F73068
// RVA : 0x00F73068
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236786(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepath@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73098
// RVA : 0x00F73098
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_vtfilepath(idreports::CrashReport *this, const std::string *value)
{
  std::string *vtfilepath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepath_ = v6;
  }
  std::string::assign(this: this->vtfilepath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$236901
// EA  : 0x82F73140
// RVA : 0x00F73140
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_236901(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepathvmtroverride@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73170
// RVA : 0x00F73170
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_vtfilepathvmtroverride(
        idreports::CrashReport *this,
        const std::string *value)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v6;
  }
  std::string::assign(this: this->vtfilepathvmtroverride_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237016
// EA  : 0x82F73218
// RVA : 0x00F73218
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237016(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_bugtitle@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73248
// RVA : 0x00F73248
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_bugtitle(idreports::CrashReport *this, const std::string *value)
{
  std::string *bugtitle; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  bugtitle = this->bugtitle_;
  this->_has_bits_[0] |= 0x400u;
  if ( bugtitle == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->bugtitle_ = v6;
  }
  std::string::assign(this: this->bugtitle_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237131
// EA  : 0x82F732F0
// RVA : 0x00F732F0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237131(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_reprosteps@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73320
// RVA : 0x00F73320
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_reprosteps(idreports::CrashReport *this, const std::string *value)
{
  std::string *reprosteps; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  reprosteps = this->reprosteps_;
  this->_has_bits_[0] |= 0x800u;
  if ( reprosteps == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->reprosteps_ = v6;
  }
  std::string::assign(this: this->reprosteps_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237246_0
// EA  : 0x82F733C8
// RVA : 0x00F733C8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237246_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_details@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F733F8
// RVA : 0x00F733F8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_details(idreports::CrashReport *this, const std::string *value)
{
  std::string *details; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  details = this->details_;
  this->_has_bits_[0] |= 0x1000u;
  if ( details == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->details_ = v6;
  }
  std::string::assign(this: this->details_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237361
// EA  : 0x82F734A0
// RVA : 0x00F734A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237361(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_severity@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F734D0
// RVA : 0x00F734D0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_severity(idreports::CrashReport *this, const std::string *value)
{
  std::string *severity; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  severity = this->severity_;
  this->_has_bits_[0] |= 0x2000u;
  if ( severity == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->severity_ = v6;
  }
  std::string::assign(this: this->severity_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237476
// EA  : 0x82F73578
// RVA : 0x00F73578
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237476(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_component@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F735A8
// RVA : 0x00F735A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_component(idreports::CrashReport *this, const std::string *value)
{
  std::string *component; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  component = this->component_;
  this->_has_bits_[0] |= 0x4000u;
  if ( component == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->component_ = v6;
  }
  std::string::assign(this: this->component_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237591_0
// EA  : 0x82F73650
// RVA : 0x00F73650
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237591_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mappath@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73680
// RVA : 0x00F73680
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_mappath(idreports::CrashReport *this, const std::string *value)
{
  std::string *mappath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x8000u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mappath_ = v6;
  }
  std::string::assign(this: this->mappath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237706
// EA  : 0x82F73728
// RVA : 0x00F73728
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237706(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_priority@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73758
// RVA : 0x00F73758
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_priority(idreports::CrashReport *this, const std::string *value)
{
  std::string *priority; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  priority = this->priority_;
  this->_has_bits_[0] |= 0x10000u;
  if ( priority == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->priority_ = v6;
  }
  std::string::assign(this: this->priority_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237821
// EA  : 0x82F73800
// RVA : 0x00F73800
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237821(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_localfilename@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73830
// RVA : 0x00F73830
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_localfilename(idreports::CrashReport *this, const std::string *value)
{
  std::string *localfilename; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  localfilename = this->localfilename_;
  this->_has_bits_[0] |= 0x20000u;
  if ( localfilename == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->localfilename_ = v6;
  }
  std::string::assign(this: this->localfilename_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$237936
// EA  : 0x82F738D8
// RVA : 0x00F738D8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_237936(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_dmppath@CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73908
// RVA : 0x00F73908
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::CrashReport::set_dmppath(idreports::CrashReport *this, const std::string *value)
{
  std::string *dmppath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  dmppath = this->dmppath_;
  this->_has_bits_[0] |= 0x40000u;
  if ( dmppath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->dmppath_ = v6;
  }
  std::string::assign(this: this->dmppath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238051
// EA  : 0x82F739B0
// RVA : 0x00F739B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238051(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F739E0
// RVA : 0x00F739E0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_game(idreports::Xbox360CrashReport *this, const std::string *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  std::string::assign(this: this->game_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238166
// EA  : 0x82F73A88
// RVA : 0x00F73A88
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238166(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73AB8
// RVA : 0x00F73AB8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_username(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238281
// EA  : 0x82F73B60
// RVA : 0x00F73B60
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238281(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73B90
// RVA : 0x00F73B90
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_platform(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  std::string::assign(this: this->platform_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238396
// EA  : 0x82F73C38
// RVA : 0x00F73C38
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238396(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildstring@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73C68
// RVA : 0x00F73C68
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_buildstring(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *buildstring; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildstring_ = v6;
  }
  std::string::assign(this: this->buildstring_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238511
// EA  : 0x82F73D10
// RVA : 0x00F73D10
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238511(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73D40
// RVA : 0x00F73D40
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_timestamp(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  std::string::assign(this: this->timestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238626_0
// EA  : 0x82F73DE8
// RVA : 0x00F73DE8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238626_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_launchcommand@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73E18
// RVA : 0x00F73E18
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_launchcommand(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *launchcommand; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->launchcommand_ = v6;
  }
  std::string::assign(this: this->launchcommand_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238741_0
// EA  : 0x82F73EC0
// RVA : 0x00F73EC0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238741_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepath@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73EF0
// RVA : 0x00F73EF0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_vtfilepath(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *vtfilepath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepath_ = v6;
  }
  std::string::assign(this: this->vtfilepath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238856
// EA  : 0x82F73F98
// RVA : 0x00F73F98
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238856(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepathvmtroverride@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F73FC8
// RVA : 0x00F73FC8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_vtfilepathvmtroverride(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v6;
  }
  std::string::assign(this: this->vtfilepathvmtroverride_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$238971
// EA  : 0x82F74070
// RVA : 0x00F74070
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_238971(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mappath@Xbox360CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F740A0
// RVA : 0x00F740A0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::Xbox360CrashReport::set_mappath(
        idreports::Xbox360CrashReport *this,
        const std::string *value)
{
  std::string *mappath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x400u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mappath_ = v6;
  }
  std::string::assign(this: this->mappath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239086
// EA  : 0x82F74148
// RVA : 0x00F74148
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239086(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_game@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74178
// RVA : 0x00F74178
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_game(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *game; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  game = this->game_;
  this->_has_bits_[0] |= 1u;
  if ( game == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->game_ = v6;
  }
  std::string::assign(this: this->game_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239201
// EA  : 0x82F74220
// RVA : 0x00F74220
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239201(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_username@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74250
// RVA : 0x00F74250
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_username(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *username; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  username = this->username_;
  this->_has_bits_[0] |= 2u;
  if ( username == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->username_ = v6;
  }
  std::string::assign(this: this->username_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239316
// EA  : 0x82F742F8
// RVA : 0x00F742F8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239316(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_platform@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74328
// RVA : 0x00F74328
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_platform(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *platform; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  platform = this->platform_;
  this->_has_bits_[0] |= 4u;
  if ( platform == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->platform_ = v6;
  }
  std::string::assign(this: this->platform_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239431
// EA  : 0x82F743D0
// RVA : 0x00F743D0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239431(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_buildstring@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74400
// RVA : 0x00F74400
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_buildstring(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *buildstring; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  buildstring = this->buildstring_;
  this->_has_bits_[0] |= 0x20u;
  if ( buildstring == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->buildstring_ = v6;
  }
  std::string::assign(this: this->buildstring_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239546
// EA  : 0x82F744A8
// RVA : 0x00F744A8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239546(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_timestamp@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F744D8
// RVA : 0x00F744D8
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_timestamp(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *timestamp; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  timestamp = this->timestamp_;
  this->_has_bits_[0] |= 0x40u;
  if ( timestamp == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->timestamp_ = v6;
  }
  std::string::assign(this: this->timestamp_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239661
// EA  : 0x82F74580
// RVA : 0x00F74580
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239661(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_launchcommand@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F745B0
// RVA : 0x00F745B0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_launchcommand(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *launchcommand; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  launchcommand = this->launchcommand_;
  this->_has_bits_[0] |= 0x80u;
  if ( launchcommand == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->launchcommand_ = v6;
  }
  std::string::assign(this: this->launchcommand_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239776
// EA  : 0x82F74658
// RVA : 0x00F74658
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239776(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepath@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74688
// RVA : 0x00F74688
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_vtfilepath(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *vtfilepath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepath = this->vtfilepath_;
  this->_has_bits_[0] |= 0x100u;
  if ( vtfilepath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepath_ = v6;
  }
  std::string::assign(this: this->vtfilepath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$239891
// EA  : 0x82F74730
// RVA : 0x00F74730
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_239891(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_vtfilepathvmtroverride@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74760
// RVA : 0x00F74760
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_vtfilepathvmtroverride(
        idreports::PS3CrashReport *this,
        const std::string *value)
{
  std::string *vtfilepathvmtroverride; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  vtfilepathvmtroverride = this->vtfilepathvmtroverride_;
  this->_has_bits_[0] |= 0x200u;
  if ( vtfilepathvmtroverride == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->vtfilepathvmtroverride_ = v6;
  }
  std::string::assign(this: this->vtfilepathvmtroverride_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$240006
// EA  : 0x82F74808
// RVA : 0x00F74808
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_240006(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?set_mappath@PS3CrashReport@idreports@@QAAXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F74838
// RVA : 0x00F74838
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall idreports::PS3CrashReport::set_mappath(idreports::PS3CrashReport *this, const std::string *value)
{
  std::string *mappath; // r9
  std::string *v5; // r3
  std::string *v6; // r11

  mappath = this->mappath_;
  this->_has_bits_[0] |= 0x400u;
  if ( mappath == &google::protobuf::internal::kEmptyString )
  {
    v5 = (std::string *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1Cu,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
    {
      v5->_Mysize = 0;
      v6 = v5;
      v5->_Myres = 15;
      v5->_Bx._Buf[0] = 0;
    }
    else
    {
      v6 = nullptr;
    }
    this->mappath_ = v6;
  }
  std::string::assign(this: this->mappath_, _Right: value, _Roff: 0, _Count: 0xFFFFFFFF);
}


// ========================================================================
// __unwind$240121
// EA  : 0x82F748E0
// RVA : 0x00F748E0
// PDB : w:\tech5\shared\idlib\networking\protocols\reports.pb.h
// ========================================================================

void __fastcall _unwind_240121(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}

