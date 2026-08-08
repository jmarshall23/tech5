
// ========================================================================
// ??1MessageLite@protobuf@google@@UAA@XZ
// EA  : 0x83213E60
// RVA : 0x01213E60
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void __fastcall google::protobuf::MessageLite::~MessageLite(google::protobuf::MessageLite *this)
{
  this->__vftable = (google::protobuf::MessageLite_vtbl *)&google::protobuf::MessageLite::`vftable';
}


// ========================================================================
// ?ByteSizeConsistencyError@?A0x18666502@protobuf@google@@YAXHHH@Z
// EA  : 0x83213E78
// RVA : 0x01213E78
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void __fastcall google::protobuf::`anonymous namespace'::ByteSizeConsistencyError(
        int byte_size_before_serialization,
        int byte_size_after_serialization,
        int bytes_produced_by_serialization)
{
  int v5; // r30
  google::protobuf::internal::LogMessage *v6; // r3
  google::protobuf::internal::LogMessage *v7; // r3
  google::protobuf::internal::LogMessage *v8; // r3
  google::protobuf::internal::LogMessage *v9; // r3
  google::protobuf::internal::LogMessage *v10; // r3
  google::protobuf::internal::LogMessage *v11; // r3
  google::protobuf::internal::LogMessage *v12; // r3
  google::protobuf::internal::LogMessage *v13; // r3
  google::protobuf::internal::LogFinisher v14; // [sp+50h] [-70h] BYREF
  int v15; // [sp+54h] [-6Ch]
  google::protobuf::internal::LogMessage v16[2]; // [sp+60h] [-60h] BYREF

  v15 = 0;
  v5 = 0;
  if ( byte_size_before_serialization != byte_size_after_serialization )
  {
    v14 = 0;
    v6 = google::protobuf::internal::LogMessage::LogMessage(
           this: v16,
           level: LOGLEVEL_FATAL,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\message_lite.cc",
           line: 63);
    v5 = 1;
    v15 = 1;
    v7 = google::protobuf::internal::LogMessage::operator<<(
           this: v6,
           value: "CHECK failed: (byte_size_before_serialization) == (byte_size_after_serialization): ");
    v8 = google::protobuf::internal::LogMessage::operator<<(
           this: v7,
           value: "Protocol message was modified concurrently during serialization.");
    google::protobuf::internal::LogFinisher::operator=(this: &v14, other: v8);
  }
  if ( (v5 & 1) != 0 )
  {
    v5 &= ~1u;
    google::protobuf::internal::LogMessage::~LogMessage(this: v16);
  }
  if ( bytes_produced_by_serialization != byte_size_before_serialization )
  {
    v14 = 0;
    v9 = google::protobuf::internal::LogMessage::LogMessage(
           this: v16,
           level: LOGLEVEL_FATAL,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\message_lite.cc",
           line: 65);
    v5 |= 2u;
    v15 = v5;
    v10 = google::protobuf::internal::LogMessage::operator<<(
            this: v9,
            value: "CHECK failed: (bytes_produced_by_serialization) == (byte_size_before_serialization): ");
    v11 = google::protobuf::internal::LogMessage::operator<<(
            this: v10,
            value: "Byte size calculation and serialization were inconsistent.  This may indicate a bug in protocol buffers or i"
            "t may be caused by concurrent modification of the message.");
    google::protobuf::internal::LogFinisher::operator=(this: &v14, other: v11);
  }
  if ( (v5 & 2) != 0 )
    google::protobuf::internal::LogMessage::~LogMessage(this: v16);
  v14 = 0;
  v12 = google::protobuf::internal::LogMessage::LogMessage(
          this: v16,
          level: LOGLEVEL_FATAL,
          filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\message_lite.cc",
          line: 69);
  v13 = google::protobuf::internal::LogMessage::operator<<(
          this: v12,
          value: "This shouldn't be called if all the sizes are equal.");
  google::protobuf::internal::LogFinisher::operator=(this: &v14, other: v13);
  google::protobuf::internal::LogMessage::~LogMessage(this: v16);
}


// ========================================================================
// __unwind$28573
// EA  : 0x83213FB4
// RVA : 0x01213FB4
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28573()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v1 + 96));
  }
}


// ========================================================================
// __unwind$28576
// EA  : 0x83213FF8
// RVA : 0x01213FF8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28576()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 84) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v1 + 96));
  }
}


// ========================================================================
// __unwind$28579
// EA  : 0x8321403C
// RVA : 0x0121403C
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28579()
{
  int v0; // r12

  google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v0 - 192 + 96));
}


// ========================================================================
// ?SerializeWithCachedSizesToArray@MessageLite@protobuf@google@@UBAPAEPAE@Z
// EA  : 0x83214070
// RVA : 0x01214070
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

unsigned __int8 *__fastcall google::protobuf::MessageLite::SerializeWithCachedSizesToArray(
        google::protobuf::MessageLite *this,
        unsigned __int8 *target)
{
  char v2; // r28
  int v5; // r29
  google::protobuf::internal::LogMessage *v6; // r3
  google::protobuf::internal::LogMessage *v7; // r3
  google::protobuf::internal::LogFinisher v9; // [sp+50h] [-B0h] BYREF
  int v10; // [sp+54h] [-ACh]
  google::protobuf::io::CodedOutputStream v11; // [sp+60h] [-A0h] BYREF
  google::protobuf::io::ArrayOutputStream v12; // [sp+80h] [-80h] BYREF
  google::protobuf::internal::LogMessage v13[2]; // [sp+A0h] [-60h] BYREF

  v2 = 0;
  v10 = 0;
  v5 = this->GetCachedSize(this);
  google::protobuf::io::ArrayOutputStream::ArrayOutputStream(this: &v12, data: target, size: v5, block_size: -1);
  google::protobuf::io::CodedOutputStream::CodedOutputStream(this: &v11, output: &v12);
  this->SerializeWithCachedSizes(this, a2: &v11);
  if ( v11.had_error_ )
  {
    v9 = 0;
    v6 = google::protobuf::internal::LogMessage::LogMessage(
           this: v13,
           level: LOGLEVEL_FATAL,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\message_lite.cc",
           line: 224);
    v2 = 1;
    v10 = 1;
    v7 = google::protobuf::internal::LogMessage::operator<<(this: v6, value: "CHECK failed: !coded_out.HadError(): ");
    google::protobuf::internal::LogFinisher::operator=(this: &v9, other: v7);
  }
  if ( (v2 & 1) != 0 )
    google::protobuf::internal::LogMessage::~LogMessage(this: v13);
  google::protobuf::io::CodedOutputStream::~CodedOutputStream(this: &v11);
  google::protobuf::io::ArrayOutputStream::~ArrayOutputStream(this: &v12);
  return &target[v5];
}


// ========================================================================
// __unwind$28745
// EA  : 0x8321415C
// RVA : 0x0121415C
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28745()
{
  int v0; // r12

  google::protobuf::io::ArrayOutputStream::~ArrayOutputStream(this: (google::protobuf::io::ArrayOutputStream *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$28746
// EA  : 0x83214184
// RVA : 0x01214184
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28746()
{
  int v0; // r12

  google::protobuf::io::CodedOutputStream::~CodedOutputStream(this: (google::protobuf::io::CodedOutputStream *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$28748
// EA  : 0x832141AC
// RVA : 0x012141AC
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

void _unwind_28748()
{
  int v0; // r12
  google::protobuf::internal::LogMessage *v1; // r31

  v1 = (google::protobuf::internal::LogMessage *)(v0 - 256);
  if ( (*(_DWORD *)(v0 - 256 + 84) & 1) != 0 )
  {
    v1[2].filename_ = (const char *)((int)v1[2].filename_ & ~1u);
    google::protobuf::internal::LogMessage::~LogMessage(this: v1 + 4);
  }
}


// ========================================================================
// ?SerializePartialToArray@MessageLite@protobuf@google@@QBA_NPAXH@Z
// EA  : 0x832141F0
// RVA : 0x012141F0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

int __fastcall google::protobuf::MessageLite::SerializePartialToArray(
        google::protobuf::MessageLite *this,
        unsigned __int8 *data,
        int size)
{
  int v6; // r30
  int v8; // r29
  int v9; // r3

  v6 = this->ByteSize(this);
  if ( size < v6 )
    return 0;
  v8 = this->SerializeWithCachedSizesToArray(this, a2: data) - data;
  if ( v8 != v6 )
  {
    v9 = this->ByteSize(this);
    google::protobuf::`anonymous namespace'::ByteSizeConsistencyError(
      byte_size_before_serialization: v6,
      byte_size_after_serialization: v9,
      bytes_produced_by_serialization: v8);
  }
  return 1;
}


// ========================================================================
// ?InitializationErrorString@MessageLite@protobuf@google@@UBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x832145E8
// RVA : 0x012145E8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

google::protobuf::MessageLite *__fastcall google::protobuf::MessageLite::InitializationErrorString(
        google::protobuf::MessageLite *this,
        std::string *result)
{
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 15;
  HIBYTE(this->__vftable) = 0;
  std::string::assign((std::string *)this, _Ptr: "(cannot determine missing fields for lite message)", _Count: 0x32u);
  return this;
}


// ========================================================================
// ?SerializeToArray@MessageLite@protobuf@google@@QBA_NPAXH@Z
// EA  : 0x83214640
// RVA : 0x01214640
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\message_lite.cc
// ========================================================================

int __fastcall google::protobuf::MessageLite::SerializeToArray(
        google::protobuf::MessageLite *this,
        unsigned __int8 *data,
        int size)
{
  return google::protobuf::MessageLite::SerializePartialToArray(this, data, size);
}

