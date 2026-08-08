
// ========================================================================
// ??0ProtobufOnceType@protobuf@google@@QAA@XZ
// EA  : 0x832332B0
// RVA : 0x012332B0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\once.cc
// ========================================================================

google::protobuf::ProtobufOnceType *__fastcall google::protobuf::ProtobufOnceType::ProtobufOnceType(
        google::protobuf::ProtobufOnceType *this)
{
  _RTL_CRITICAL_SECTION *v2; // r3
  google::protobuf::ProtobufOnceInternal *v3; // r31

  if ( this->internal_ == nullptr )
  {
    v2 = (_RTL_CRITICAL_SECTION *)operator new(s: 0x1Cu);
    v3 = (google::protobuf::ProtobufOnceInternal *)v2;
    if ( v2 != nullptr )
      RtlInitializeCriticalSection(CriticalSection: v2);
    else
      v3 = nullptr;
    this->internal_ = v3;
  }
  return this;
}


// ========================================================================
// ?Init@ProtobufOnceType@protobuf@google@@QAAXP6AXXZ@Z
// EA  : 0x83233318
// RVA : 0x01233318
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\once.cc
// ========================================================================

void __fastcall google::protobuf::ProtobufOnceType::Init(
        google::protobuf::ProtobufOnceType *this,
        void (__fastcall *init_func)())
{
  _RTL_CRITICAL_SECTION *v4; // r3
  google::protobuf::ProtobufOnceInternal *v5; // r30

  if ( this->internal_ == nullptr )
  {
    v4 = (_RTL_CRITICAL_SECTION *)operator new(s: 0x1Cu);
    v5 = (google::protobuf::ProtobufOnceInternal *)v4;
    if ( v4 != nullptr )
      RtlInitializeCriticalSection(CriticalSection: v4);
    else
      v5 = nullptr;
    this->internal_ = v5;
  }
  RtlEnterCriticalSection(CriticalSection: &this->internal_->critical_section);
  if ( !this->initialized_ )
  {
    init_func();
    this->initialized_ = true;
  }
  RtlLeaveCriticalSection(CriticalSection: &this->internal_->critical_section);
}


// ========================================================================
// ??1ProtobufOnceType@protobuf@google@@QAA@XZ
// EA  : 0x83233390
// RVA : 0x01233390
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\stubs\once.cc
// ========================================================================

void __fastcall google::protobuf::ProtobufOnceType::~ProtobufOnceType(
        google::protobuf::ProtobufOnceType *this,
        memTag_t a2)
{
  google::protobuf::ProtobufOnceInternal *internal; // r3

  internal = this->internal_;
  if ( internal != nullptr )
    operator delete(p: internal, tag: a2);
  this->internal_ = nullptr;
}

