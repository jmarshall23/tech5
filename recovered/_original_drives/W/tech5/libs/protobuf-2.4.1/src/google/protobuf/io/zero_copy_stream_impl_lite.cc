
// ========================================================================
// ??0ArrayOutputStream@io@protobuf@google@@QAA@PAXHH@Z
// EA  : 0x83227C98
// RVA : 0x01227C98
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

google::protobuf::io::ArrayOutputStream *__fastcall google::protobuf::io::ArrayOutputStream::ArrayOutputStream(
        google::protobuf::io::ArrayOutputStream *this,
        unsigned __int8 *data,
        int size,
        int block_size)
{
  this->data_ = data;
  this->size_ = size;
  this->__vftable = (google::protobuf::io::ArrayOutputStream_vtbl *)&google::protobuf::io::ArrayOutputStream::`vftable';
  if ( block_size <= 0 )
    block_size = size;
  this->block_size_ = block_size;
  this->position_ = 0;
  this->last_returned_size_ = 0;
  return this;
}


// ========================================================================
// ??1ArrayOutputStream@io@protobuf@google@@UAA@XZ
// EA  : 0x83227CD0
// RVA : 0x01227CD0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

void __fastcall google::protobuf::io::ArrayOutputStream::~ArrayOutputStream(
        google::protobuf::io::ArrayOutputStream *this)
{
  this->__vftable = (google::protobuf::io::ArrayOutputStream_vtbl *)&google::protobuf::io::ArrayOutputStream::`vftable';
  google::protobuf::io::ZeroCopyOutputStream::~ZeroCopyOutputStream(this);
}


// ========================================================================
// ?BackUp@ArrayOutputStream@io@protobuf@google@@UAAXH@Z
// EA  : 0x83227CE8
// RVA : 0x01227CE8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

void __fastcall google::protobuf::io::ArrayOutputStream::BackUp(
        google::protobuf::io::ArrayOutputStream *this,
        memTag_t count)
{
  int v4; // r30
  google::protobuf::internal::LogMessage *v5; // r3
  google::protobuf::internal::LogMessage *v6; // r3
  google::protobuf::internal::LogMessage *v7; // r3
  google::protobuf::internal::LogMessage *v8; // r3
  google::protobuf::internal::LogMessage *v9; // r3
  google::protobuf::internal::LogMessage *v10; // r3
  google::protobuf::internal::LogMessage *v11; // r3
  int position; // r11
  google::protobuf::internal::LogFinisher v13; // [sp+50h] [-70h] BYREF
  int v14; // [sp+54h] [-6Ch]
  google::protobuf::internal::LogMessage v15[2]; // [sp+60h] [-60h] BYREF

  v14 = 0;
  v4 = 0;
  if ( this->last_returned_size_ <= 0 )
  {
    v13 = 0;
    v5 = google::protobuf::internal::LogMessage::LogMessage(
           this: v15,
           level: LOGLEVEL_FATAL,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\zero_copy_stream_impl_lite.cc",
           line: 132);
    v4 = 1;
    v14 = 1;
    v6 = google::protobuf::internal::LogMessage::operator<<(
           this: v5,
           value: "CHECK failed: (last_returned_size_) > (0): ");
    v7 = google::protobuf::internal::LogMessage::operator<<(
           this: v6,
           value: "BackUp() can only be called after a successful Next().");
    google::protobuf::internal::LogFinisher::operator=(this: &v13, other: v7);
  }
  if ( (v4 & 1) != 0 )
  {
    v4 &= ~1u;
    google::protobuf::internal::LogMessage::~LogMessage(this: v15, a2: count);
  }
  if ( count > this->last_returned_size_ )
  {
    v13 = 0;
    v8 = google::protobuf::internal::LogMessage::LogMessage(
           this: v15,
           level: LOGLEVEL_FATAL,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\zero_copy_stream_impl_lite.cc",
           line: 134);
    v4 |= 2u;
    v14 = v4;
    v9 = google::protobuf::internal::LogMessage::operator<<(
           this: v8,
           value: "CHECK failed: (count) <= (last_returned_size_): ");
    google::protobuf::internal::LogFinisher::operator=(this: &v13, other: v9);
  }
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: v15, a2: count);
  }
  if ( count < TAG_UNSET )
  {
    v13 = 0;
    v10 = google::protobuf::internal::LogMessage::LogMessage(
            this: v15,
            level: LOGLEVEL_FATAL,
            filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\zero_copy_stream_impl_lite.cc",
            line: 135);
    v4 |= 4u;
    v14 = v4;
    v11 = google::protobuf::internal::LogMessage::operator<<(this: v10, value: "CHECK failed: (count) >= (0): ");
    google::protobuf::internal::LogFinisher::operator=(this: &v13, other: v11);
  }
  if ( (v4 & 4) != 0 )
    google::protobuf::internal::LogMessage::~LogMessage(this: v15, a2: count);
  position = this->position_;
  this->last_returned_size_ = 0;
  this->position_ = position - count;
}


// ========================================================================
// __unwind$28264
// EA  : 0x83227E50
// RVA : 0x01227E50
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

void __fastcall _unwind_28264(int a1, memTag_t a2)
{
  int v2; // r12
  int v3; // r31

  v3 = v2 - 192;
  if ( (*(_DWORD *)(v2 - 192 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v3 + 84) &= ~1u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v3 + 96), a2);
  }
}


// ========================================================================
// __unwind$28267
// EA  : 0x83227E94
// RVA : 0x01227E94
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

void __fastcall _unwind_28267(int a1, memTag_t a2)
{
  int v2; // r12
  int v3; // r31

  v3 = v2 - 192;
  if ( (*(_DWORD *)(v2 - 192 + 84) & 2) != 0 )
  {
    *(_DWORD *)(v3 + 84) &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v3 + 96), a2);
  }
}


// ========================================================================
// __unwind$28270
// EA  : 0x83227ED8
// RVA : 0x01227ED8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

void __fastcall _unwind_28270(int a1, memTag_t a2)
{
  int v2; // r12
  int v3; // r31

  v3 = v2 - 192;
  if ( (*(_DWORD *)(v2 - 192 + 84) & 4) != 0 )
  {
    *(_DWORD *)(v3 + 84) &= ~4u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v3 + 96), a2);
  }
}


// ========================================================================
// ?ByteCount@ArrayOutputStream@io@protobuf@google@@UBA_JXZ
// EA  : 0x83227F20
// RVA : 0x01227F20
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

int __fastcall google::protobuf::io::ArrayOutputStream::ByteCount(google::protobuf::io::ArrayOutputStream *this)
{
  return this->position_;
}


// ========================================================================
// ?Next@ArrayOutputStream@io@protobuf@google@@UAA_NPAPAXPAH@Z
// EA  : 0x83227F90
// RVA : 0x01227F90
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\zero_copy_stream_impl_lite.cc
// ========================================================================

int __fastcall google::protobuf::io::ArrayOutputStream::Next(
        google::protobuf::io::ArrayOutputStream *this,
        unsigned __int8 **data,
        int *size)
{
  int v3; // r9
  int position; // r10
  int *p_block_size; // r9
  bool v6; // zf
  unsigned __int8 *v8; // r7
  int back_chain; // [sp+0h] [-10h] BYREF

  v3 = this->size_;
  position = this->position_;
  if ( position >= v3 )
  {
    this->last_returned_size_ = 0;
    return 0;
  }
  else
  {
    v6 = v3 - position >= this->block_size_;
    p_block_size = (int *)&this->block_size_;
    if ( !v6 )
      p_block_size = &back_chain;
    v8 = &this->data_[position];
    this->last_returned_size_ = *p_block_size;
    *data = v8;
    *size = this->last_returned_size_;
    this->position_ += this->last_returned_size_;
    return 1;
  }
}

