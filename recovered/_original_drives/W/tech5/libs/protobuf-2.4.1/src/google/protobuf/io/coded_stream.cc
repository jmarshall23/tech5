
// ========================================================================
// ?NextNonEmpty@?A0xb9bf7876@io@protobuf@google@@YA_NPAVZeroCopyInputStream@234@PAPBXPAH@Z
// EA  : 0x83220DE0
// RVA : 0x01220DE0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::`anonymous namespace'::NextNonEmpty(
        google::protobuf::io::ZeroCopyInputStream *input,
        const void **data,
        int *size)
{
  int result; // r3

  do
    result = ((int (__fastcall *)(google::protobuf::io::ZeroCopyInputStream *, const void **, int *))input->Next)(
               a1: input,
               a2: data,
               a3: size);
  while ( (_BYTE)result != 0 && *size == 0 );
  return result;
}


// ========================================================================
// ?BytesUntilLimit@CodedInputStream@io@protobuf@google@@QAAHXZ
// EA  : 0x83220E38
// RVA : 0x01220E38
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

const unsigned __int8 *__fastcall google::protobuf::io::CodedInputStream::BytesUntilLimit(
        google::protobuf::io::CodedInputStream *this)
{
  int current_limit; // r9

  current_limit = this->current_limit_;
  if ( current_limit == 0x7FFFFFFF )
    return (const unsigned __int8 *)-1;
  else
    return &this->buffer_end_[this->buffer_size_after_limit_
                            - this->total_bytes_read_
                            - (unsigned int)this->buffer_
                            + current_limit];
}


// ========================================================================
// ?PrintTotalBytesLimitError@CodedInputStream@io@protobuf@google@@AAAXXZ
// EA  : 0x83220E80
// RVA : 0x01220E80
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedInputStream::PrintTotalBytesLimitError(
        google::protobuf::io::CodedInputStream *this)
{
  google::protobuf::internal::LogMessage *v2; // r3
  int total_bytes_limit; // r30
  google::protobuf::internal::LogMessage *v4; // r3
  google::protobuf::internal::LogMessage *v5; // r3
  google::protobuf::internal::LogMessage *v6; // r3
  google::protobuf::internal::LogFinisher v7; // [sp+50h] [-50h] BYREF
  google::protobuf::internal::LogMessage v8; // [sp+60h] [-40h] BYREF

  v7 = 0;
  v2 = google::protobuf::internal::LogMessage::LogMessage(
         this: &v8,
         level: LOGLEVEL_ERROR,
         filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
         line: 156);
  total_bytes_limit = this->total_bytes_limit_;
  v4 = google::protobuf::internal::LogMessage::operator<<(
         this: v2,
         value: "A protocol message was rejected because it was too big (more than ");
  v5 = google::protobuf::internal::LogMessage::operator<<(this: v4, value: total_bytes_limit);
  v6 = google::protobuf::internal::LogMessage::operator<<(
         this: v5,
         value: " bytes).  To increase the limit (or to disable these warnings), see CodedInputStream::SetTotalBytesLimit() in g"
         "oogle/protobuf/io/coded_stream.h.");
  google::protobuf::internal::LogFinisher::operator=(this: &v7, other: v6);
  google::protobuf::internal::LogMessage::~LogMessage(this: &v8);
}


// ========================================================================
// __unwind$31180
// EA  : 0x83220F10
// RVA : 0x01220F10
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _unwind_31180()
{
  int v0; // r12

  google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v0 - 160 + 96));
}


// ========================================================================
// ?ReadVarint32FromArray@?A0xb9bf7876@io@protobuf@google@@YAPBEPBEPAI@Z
// EA  : 0x83220F38
// RVA : 0x01220F38
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

char *__fastcall google::protobuf::io::`anonymous namespace'::ReadVarint32FromArray(
        const unsigned __int8 *buffer,
        unsigned int *value)
{
  char *result; // r3
  int v3; // r10
  int v4; // r11
  int v5; // r10
  int v6; // r10
  int v7; // r10
  int v8; // r10
  int v9; // r10
  char v10; // r9

  v3 = *buffer & 0x80;
  v4 = *buffer & 0x7F;
  result = (char *)(buffer + 1);
  if ( v3 != 0 )
  {
    v5 = (unsigned __int8)*result++;
    v4 |= (v5 << 7) & 0x3F80;
    if ( (v5 & 0x80) != 0 )
    {
      v6 = (unsigned __int8)*result++;
      v4 |= (v6 << 14) & 0x1FC000;
      if ( (v6 & 0x80) != 0 )
      {
        v7 = (unsigned __int8)*result++;
        v4 |= (v7 << 21) & 0xFE00000;
        if ( (v7 & 0x80) != 0 )
        {
          v8 = (unsigned __int8)*result++;
          v4 |= v8 << 28;
          if ( (v8 & 0x80) != 0 )
          {
            v9 = 0;
            while ( 1 )
            {
              v10 = *result++;
              if ( (v10 & 0x80) == 0 )
                break;
              if ( ++v9 >= 5 )
                return nullptr;
            }
          }
        }
      }
    }
  }
  *value = v4;
  return result;
}


// ========================================================================
// ??1CodedOutputStream@io@protobuf@google@@QAA@XZ
// EA  : 0x83220FF8
// RVA : 0x01220FF8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedOutputStream::~CodedOutputStream(
        google::protobuf::io::CodedOutputStream *this)
{
  if ( this->buffer_size_ > 0 )
    ((void (__fastcall *)(google::protobuf::io::ZeroCopyOutputStream *))this->output_->BackUp)(a1: this->output_);
}


// ========================================================================
// ?WriteVarint32FallbackToArrayInline@CodedOutputStream@io@protobuf@google@@CAPAEIPAE@Z
// EA  : 0x83221020
// RVA : 0x01221020
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

unsigned __int8 *__fastcall google::protobuf::io::CodedOutputStream::WriteVarint32FallbackToArrayInline(
        unsigned int value,
        unsigned __int8 *target)
{
  *target = value | 0x80;
  if ( value < 0x80 )
  {
    *target = value & 0x7F;
    return target + 1;
  }
  else
  {
    target[1] = (value >> 7) | 0x80;
    if ( value < 0x4000 )
    {
      target[1] = (value >> 7) & 0x7F;
      return target + 2;
    }
    else
    {
      target[2] = (value >> 14) | 0x80;
      if ( value < 0x200000 )
      {
        target[2] = (value >> 14) & 0x7F;
        return target + 3;
      }
      else
      {
        target[3] = (value >> 21) | 0x80;
        if ( value < 0x10000000 )
        {
          target[3] = (value >> 21) & 0x7F;
          return target + 4;
        }
        else
        {
          target[4] = value >> 28;
          return target + 5;
        }
      }
    }
  }
}


// ========================================================================
// ?WriteVarint64ToArrayInline@CodedOutputStream@io@protobuf@google@@CAPAE_KPAE@Z
// EA  : 0x832210C8
// RVA : 0x012210C8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall google::protobuf::io::CodedOutputStream::WriteVarint64ToArrayInline(
        unsigned __int64 value,
        unsigned __int8 *target)
{
  int v2; // r2 OVERLAPPED
  int v3; // r9

  if ( HIBYTE(*(unsigned __int64 *)((char *)&value + 4)) != 0 )
  {
    if ( (unsigned int)HIBYTE(*(unsigned __int64 *)((char *)&value + 4)) >= 0x80 )
    {
      v3 = 10;
      *(_BYTE *)(value + 9) = ((unsigned int)HIBYTE(*(unsigned __int64 *)((char *)&value + 4)) >> 7) | 0x80;
    }
    else
    {
      v3 = 9;
    }
    *(_BYTE *)(value + 8) = HIBYTE(v2) & 0x7F | 0x80;
    *(_BYTE *)(value + 7) = 0x80;
    *(_BYTE *)(value + 6) = 0x80;
    *(_BYTE *)(value + 5) = 0x80;
    *(_BYTE *)(value + 4) = 0x80;
    goto size4;
  }
  if ( HIDWORD(value) >= 0x4000 )
  {
    if ( HIDWORD(value) < 0x200000 )
    {
      v3 = 3;
size3:
      *(_BYTE *)(value + 2) = (HIDWORD(value) >> 14) & 0x7F | 0x80;
      goto size2;
    }
    v3 = 4;
size4:
    *(_BYTE *)(value + 3) = (HIDWORD(value) >> 21) & 0x7F | 0x80;
    goto size3;
  }
  if ( HIDWORD(value) >= 0x80 )
  {
    v3 = 2;
size2:
    *(_BYTE *)(value + 1) = (HIDWORD(value) >> 7) & 0x7F | 0x80;
    goto size1;
  }
  v3 = 1;
size1:
  *(_BYTE *)value = BYTE3(value) & 0x7F | 0x80;
  *(_BYTE *)(v3 + value - 1) &= ~0x80u;
  return (unsigned __int8 *)(v3 + value);
}


// ========================================================================
// ?Refresh@CodedOutputStream@io@protobuf@google@@AAA_NXZ
// EA  : 0x832211F8
// RVA : 0x012211F8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedOutputStream::Refresh(google::protobuf::io::CodedOutputStream *this)
{
  int *p_buffer_size; // r30
  unsigned __int8 *v4; // r9
  unsigned __int8 *v5; // [sp+50h] [-20h] BYREF

  p_buffer_size = &this->buffer_size_;
  if ( this->output_->Next(this: this->output_, a2: (void **)&v5, a3: &this->buffer_size_) )
  {
    v4 = v5;
    this->total_bytes_ += *p_buffer_size;
    this->buffer_ = v4;
    return 1;
  }
  else
  {
    this->buffer_ = nullptr;
    *p_buffer_size = 0;
    this->had_error_ = true;
    return 0;
  }
}


// ========================================================================
// ?VarintSize32Fallback@CodedOutputStream@io@protobuf@google@@CAHI@Z
// EA  : 0x83221290
// RVA : 0x01221290
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedOutputStream::VarintSize32Fallback(unsigned int value)
{
  if ( value < 0x80 )
    return 1;
  if ( value < 0x4000 )
    return 2;
  if ( value >= 0x200000 )
    return (value >= 0x10000000) - 1 + 5;
  return 3;
}


// ========================================================================
// ?VarintSize64@CodedOutputStream@io@protobuf@google@@SAH_K@Z
// EA  : 0x832212D8
// RVA : 0x012212D8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedOutputStream::VarintSize64(unsigned __int64 value)
{
  int result; // r3
  bool v2; // zf

  if ( HIDWORD(value) < 8 )
    return 1;
  if ( HIDWORD(value) < 0x400 )
    return 6;
  if ( HIDWORD(value) < 0x20000 )
    return 7;
  if ( HIDWORD(value) < 0x1000000 )
    return 8;
  v2 = HIDWORD(value) >= 0x80000000;
  result = 9;
  if ( v2 )
    return 10;
  return result;
}


// ========================================================================
// ?RecomputeBufferLimits@CodedInputStream@io@protobuf@google@@AAAXXZ
// EA  : 0x832213A0
// RVA : 0x012213A0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedInputStream::RecomputeBufferLimits(
        google::protobuf::io::CodedInputStream *this)
{
  int *p_total_bytes_limit; // r11
  int v2; // r11
  int total_bytes_read; // r10
  const unsigned __int8 *v4; // r7

  p_total_bytes_limit = &this->total_bytes_limit_;
  this->buffer_end_ += this->buffer_size_after_limit_;
  if ( this->total_bytes_limit_ >= this->current_limit_ )
    p_total_bytes_limit = &this->current_limit_;
  v2 = *p_total_bytes_limit;
  total_bytes_read = this->total_bytes_read_;
  if ( v2 >= total_bytes_read )
  {
    this->buffer_size_after_limit_ = 0;
  }
  else
  {
    v4 = &this->buffer_end_[-(total_bytes_read - v2)];
    this->buffer_size_after_limit_ = total_bytes_read - v2;
    this->buffer_end_ = v4;
  }
}


// ========================================================================
// ?PushLimit@CodedInputStream@io@protobuf@google@@QAAHH@Z
// EA  : 0x83221400
// RVA : 0x01221400
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::PushLimit(
        google::protobuf::io::CodedInputStream *this,
        int byte_limit)
{
  const unsigned __int8 *buffer; // r9
  const unsigned __int8 *buffer_end; // r8
  int *p_current_limit; // r10
  int buffer_size_after_limit; // r7
  int result; // r3
  int total_bytes_read; // r5
  int v9; // r9
  int *v10; // r9
  int v11; // r6
  const unsigned __int8 *v12; // r4
  int v13; // r7
  int v14; // r10
  const unsigned __int8 *v15; // r7
  int v16; // [sp+0h] [-10h] BYREF

  buffer = this->buffer_;
  buffer_end = this->buffer_end_;
  p_current_limit = &this->current_limit_;
  buffer_size_after_limit = this->buffer_size_after_limit_;
  total_bytes_read = this->total_bytes_read_;
  result = this->current_limit_;
  v9 = buffer - buffer_end - buffer_size_after_limit + total_bytes_read;
  if ( byte_limit < 0 || byte_limit > 0x7FFFFFFF - v9 )
    *p_current_limit = 0x7FFFFFFF;
  else
    *p_current_limit = v9 + byte_limit;
  v10 = &v16;
  if ( result >= *p_current_limit )
    v10 = p_current_limit;
  v11 = *v10;
  v12 = &buffer_end[buffer_size_after_limit];
  v13 = *v10;
  this->buffer_end_ = v12;
  *p_current_limit = v11;
  if ( this->total_bytes_limit_ < v13 )
    p_current_limit = &this->total_bytes_limit_;
  v14 = *p_current_limit;
  if ( v14 >= total_bytes_read )
  {
    this->buffer_size_after_limit_ = 0;
  }
  else
  {
    v15 = &this->buffer_end_[-(total_bytes_read - v14)];
    this->buffer_size_after_limit_ = total_bytes_read - v14;
    this->buffer_end_ = v15;
  }
  return result;
}


// ========================================================================
// ?PopLimit@CodedInputStream@io@protobuf@google@@QAAXH@Z
// EA  : 0x832214D0
// RVA : 0x012214D0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedInputStream::PopLimit(
        google::protobuf::io::CodedInputStream *this,
        int limit)
{
  const unsigned __int8 *buffer_end; // r8
  int buffer_size_after_limit; // r9
  int *p_current_limit; // r11
  int v5; // r11
  int total_bytes_read; // r10
  const unsigned __int8 *v7; // r6

  buffer_end = this->buffer_end_;
  buffer_size_after_limit = this->buffer_size_after_limit_;
  p_current_limit = &this->current_limit_;
  this->current_limit_ = limit;
  this->buffer_end_ = &buffer_end[buffer_size_after_limit];
  if ( this->total_bytes_limit_ < limit )
    p_current_limit = &this->total_bytes_limit_;
  v5 = *p_current_limit;
  total_bytes_read = this->total_bytes_read_;
  if ( v5 >= total_bytes_read )
  {
    this->buffer_size_after_limit_ = 0;
    this->legitimate_message_end_ = false;
  }
  else
  {
    v7 = &this->buffer_end_[-(total_bytes_read - v5)];
    this->buffer_size_after_limit_ = total_bytes_read - v5;
    this->legitimate_message_end_ = false;
    this->buffer_end_ = v7;
  }
}


// ========================================================================
// ?Skip@CodedInputStream@io@protobuf@google@@QAA_NH@Z
// EA  : 0x83221540
// RVA : 0x01221540
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

BOOL __fastcall google::protobuf::io::CodedInputStream::Skip(google::protobuf::io::CodedInputStream *this, int count)
{
  const unsigned __int8 *buffer; // r9
  const unsigned __int8 *v4; // r10
  int v6; // r4
  int *p_total_bytes_limit; // r9
  int v8; // r8
  int total_bytes_read; // r9
  google::protobuf::io::ZeroCopyInputStream *input; // r3

  if ( count < 0 )
    return false;
  buffer = this->buffer_;
  v4 = (const unsigned __int8 *)(this->buffer_end_ - buffer);
  if ( count <= (int)v4 )
  {
    this->buffer_ = &buffer[count];
    return true;
  }
  if ( this->buffer_size_after_limit_ > 0 )
  {
    this->buffer_ = this->buffer_end_;
    return false;
  }
  v6 = count - (_DWORD)v4;
  this->buffer_ = nullptr;
  p_total_bytes_limit = &this->total_bytes_limit_;
  this->buffer_end_ = nullptr;
  if ( this->total_bytes_limit_ >= this->current_limit_ )
    p_total_bytes_limit = &this->current_limit_;
  v8 = *p_total_bytes_limit;
  total_bytes_read = this->total_bytes_read_;
  if ( v8 - total_bytes_read < v6 )
  {
    if ( v8 - total_bytes_read > 0 )
    {
      this->total_bytes_read_ = v8;
      ((void (*)(void))this->input_->Skip)();
    }
    return false;
  }
  input = this->input_;
  this->total_bytes_read_ = total_bytes_read + v6;
  return ((bool (__fastcall *)(google::protobuf::io::ZeroCopyInputStream *))input->Skip)(a1: input);
}


// ========================================================================
// ?Refresh@CodedInputStream@io@protobuf@google@@AAA_NXZ
// EA  : 0x83221660
// RVA : 0x01221660
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::Refresh(google::protobuf::io::CodedInputStream *this)
{
  char v1; // r28
  int buffer_size_after_limit; // r10
  int total_bytes_read; // r9
  int total_bytes_warning_threshold; // r11
  google::protobuf::internal::LogMessage *v6; // r3
  int v7; // r27
  google::protobuf::internal::LogMessage *v8; // r3
  google::protobuf::internal::LogMessage *v9; // r3
  google::protobuf::internal::LogMessage *v10; // r3
  const unsigned __int8 *v11; // r11
  int v12; // r10
  google::protobuf::internal::LogMessage *v13; // r3
  google::protobuf::internal::LogMessage *v14; // r3
  int v15; // r9
  int v17; // r10
  const unsigned __int8 *buffer_end; // r9
  int total_bytes_limit; // r11
  google::protobuf::internal::LogFinisher v20; // [sp+50h] [-70h] BYREF
  int v21; // [sp+54h] [-6Ch] BYREF
  const unsigned __int8 *v22; // [sp+58h] [-68h] BYREF
  int v23; // [sp+5Ch] [-64h]
  google::protobuf::internal::LogMessage v24[2]; // [sp+60h] [-60h] BYREF

  v1 = 0;
  v23 = 0;
  buffer_size_after_limit = this->buffer_size_after_limit_;
  if ( buffer_size_after_limit > 0
    || this->overflow_bytes_ > 0
    || (total_bytes_read = this->total_bytes_read_) == this->current_limit_ )
  {
    total_bytes_limit = this->total_bytes_limit_;
    if ( this->total_bytes_read_ - buffer_size_after_limit >= total_bytes_limit
      && total_bytes_limit != this->current_limit_ )
    {
      google::protobuf::io::CodedInputStream::PrintTotalBytesLimitError(this);
    }
    return 0;
  }
  total_bytes_warning_threshold = this->total_bytes_warning_threshold_;
  if ( total_bytes_warning_threshold >= 0 && total_bytes_read >= total_bytes_warning_threshold )
  {
    v20 = 0;
    v6 = google::protobuf::internal::LogMessage::LogMessage(
           this: v24,
           level: LOGLEVEL_WARNING,
           filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
           line: 487);
    v7 = this->total_bytes_limit_;
    v8 = google::protobuf::internal::LogMessage::operator<<(
           this: v6,
           value: "Reading dangerously large protocol message.  If the message turns out to be larger than ");
    v9 = google::protobuf::internal::LogMessage::operator<<(this: v8, value: v7);
    v10 = google::protobuf::internal::LogMessage::operator<<(
            this: v9,
            value: " bytes, parsing will be halted for security reasons.  To increase the limit (or to disable these warnings), "
            "see CodedInputStream::SetTotalBytesLimit() in google/protobuf/io/coded_stream.h.");
    google::protobuf::internal::LogFinisher::operator=(this: &v20, other: v10);
    google::protobuf::internal::LogMessage::~LogMessage(this: v24);
    this->total_bytes_warning_threshold_ = -1;
  }
  if ( (unsigned __int8)google::protobuf::io::`anonymous namespace'::NextNonEmpty(
                          input: this->input_,
                          data: (const void **)&v22,
                          size: &v21) == 0 )
  {
    this->buffer_ = nullptr;
    this->buffer_end_ = nullptr;
    return 0;
  }
  v11 = v22;
  v12 = v21;
  this->buffer_ = v22;
  this->buffer_end_ = &v11[v12];
  if ( v12 < 0 )
  {
    v20 = 0;
    v13 = google::protobuf::internal::LogMessage::LogMessage(
            this: v24,
            level: LOGLEVEL_FATAL,
            filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
            line: 504);
    v1 = 2;
    v23 = 2;
    v14 = google::protobuf::internal::LogMessage::operator<<(this: v13, value: "CHECK failed: (buffer_size) >= (0): ");
    google::protobuf::internal::LogFinisher::operator=(this: &v20, other: v14);
    v12 = v21;
  }
  if ( (v1 & 2) != 0 )
  {
    google::protobuf::internal::LogMessage::~LogMessage(this: v24);
    v12 = v21;
  }
  v15 = this->total_bytes_read_;
  if ( v15 > 0x7FFFFFFF - v12 )
  {
    v17 = v15 + v12;
    buffer_end = this->buffer_end_;
    this->total_bytes_read_ = 0x7FFFFFFF;
    this->overflow_bytes_ = v17 - 0x7FFFFFFF;
    this->buffer_end_ = &buffer_end[-v17 + 0x7FFFFFFF];
  }
  else
  {
    this->total_bytes_read_ = v15 + v12;
  }
  google::protobuf::io::CodedInputStream::RecomputeBufferLimits(this);
  return 1;
}


// ========================================================================
// __unwind$31526
// EA  : 0x83221848
// RVA : 0x01221848
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _unwind_31526()
{
  int v0; // r12

  google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$31527
// EA  : 0x83221870
// RVA : 0x01221870
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _unwind_31527()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 92) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 92) &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v1 + 96));
  }
}


// ========================================================================
// ??0CodedOutputStream@io@protobuf@google@@QAA@PAVZeroCopyOutputStream@123@@Z
// EA  : 0x832218B8
// RVA : 0x012218B8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

google::protobuf::io::CodedOutputStream *__fastcall google::protobuf::io::CodedOutputStream::CodedOutputStream(
        google::protobuf::io::CodedOutputStream *this,
        google::protobuf::io::ZeroCopyOutputStream *output)
{
  this->output_ = output;
  this->buffer_ = nullptr;
  this->buffer_size_ = 0;
  this->total_bytes_ = 0;
  this->had_error_ = false;
  google::protobuf::io::CodedOutputStream::Refresh(this);
  this->had_error_ = false;
  return this;
}


// ========================================================================
// ?WriteRaw@CodedOutputStream@io@protobuf@google@@QAAXPBXH@Z
// EA  : 0x83221910
// RVA : 0x01221910
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedOutputStream::WriteRaw(
        google::protobuf::io::CodedOutputStream *this,
        char *data,
        int size)
{
  signed int v5; // r29
  size_t *p_buffer_size; // r30
  char v7; // r11
  unsigned __int8 *v8; // r8
  size_t v9; // r9
  unsigned __int8 *v10; // [sp+50h] [-40h] BYREF

  v5 = size;
  p_buffer_size = (size_t *)&this->buffer_size_;
  if ( this->buffer_size_ >= size )
  {
LABEL_7:
    memcpy(Dst: this->buffer_, Src: data, Size: v5);
    v9 = *p_buffer_size - v5;
    this->buffer_ += v5;
    *p_buffer_size = v9;
  }
  else
  {
    while ( 1 )
    {
      memcpy(Dst: this->buffer_, Src: data, Size: *p_buffer_size);
      v5 -= *p_buffer_size;
      data += *p_buffer_size;
      if ( this->output_->Next(this: this->output_, a2: (void **)&v10, a3: (int *)p_buffer_size) )
      {
        v7 = 1;
        v8 = v10;
        this->total_bytes_ += *p_buffer_size;
        this->buffer_ = v8;
      }
      else
      {
        this->buffer_ = nullptr;
        v7 = 0;
        *p_buffer_size = 0;
        this->had_error_ = true;
      }
      if ( v7 == 0 )
        break;
      if ( (int)*p_buffer_size >= v5 )
        goto LABEL_7;
    }
  }
}


// ========================================================================
// ?WriteLittleEndian32@CodedOutputStream@io@protobuf@google@@QAAXI@Z
// EA  : 0x83221A00
// RVA : 0x01221A00
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedOutputStream::WriteLittleEndian32(
        google::protobuf::io::CodedOutputStream *this,
        unsigned int value)
{
  BOOL v2; // r10
  unsigned __int8 *buffer; // r11
  int v4; // r9
  char v5[8]; // [sp+50h] [-10h] BYREF

  v2 = this->buffer_size_ >= 4u;
  if ( this->buffer_size_ < 4u )
    buffer = (unsigned __int8 *)v5;
  else
    buffer = this->buffer_;
  *buffer = value;
  buffer[1] = BYTE2(value);
  buffer[2] = BYTE1(value);
  buffer[3] = HIBYTE(value);
  if ( v2 )
  {
    v4 = this->buffer_size_ - 4;
    this->buffer_ += 4;
    this->buffer_size_ = v4;
  }
  else
  {
    google::protobuf::io::CodedOutputStream::WriteRaw(this, data: v5, size: 4);
  }
}


// ========================================================================
// ?WriteVarint32@CodedOutputStream@io@protobuf@google@@QAAXI@Z
// EA  : 0x83221AA0
// RVA : 0x01221AA0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void __fastcall google::protobuf::io::CodedOutputStream::WriteVarint32(
        google::protobuf::io::CodedOutputStream *this,
        unsigned int value)
{
  unsigned __int8 *buffer; // r30
  unsigned __int8 *v4; // r3
  int v5; // r7
  int v6; // r11
  char *v7; // r10
  char v8; // [sp+4Fh] [-21h] BYREF
  char v9[8]; // [sp+50h] [-20h] BYREF

  if ( this->buffer_size_ < 5 )
  {
    v6 = 0;
    if ( value > 0x7F )
    {
      v7 = &v8;
      do
      {
        ++v6;
        *++v7 = value | 0x80;
        value >>= 7;
      }
      while ( value > 0x7F );
    }
    v9[v6] = value & 0x7F;
    google::protobuf::io::CodedOutputStream::WriteRaw(this, data: v9, size: v6 + 1);
  }
  else
  {
    buffer = this->buffer_;
    v4 = google::protobuf::io::CodedOutputStream::WriteVarint32FallbackToArrayInline(value, target: buffer);
    v5 = this->buffer_size_ - (v4 - buffer);
    this->buffer_ += v4 - buffer;
    this->buffer_size_ = v5;
  }
}


// ========================================================================
// ?WriteVarint64@CodedOutputStream@io@protobuf@google@@QAAX_K@Z
// EA  : 0x83221B58
// RVA : 0x01221B58
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall google::protobuf::io::CodedOutputStream::WriteVarint64(
        google::protobuf::io::CodedOutputStream *this,
        int a2,
        unsigned __int64 value)
{
  google::protobuf::io::CodedOutputStream *v3; // r31
  unsigned __int8 *buffer; // r30
  unsigned int v5; // r4
  unsigned __int8 *v6; // r3
  int v7; // r7
  int v8; // r11
  unsigned int v9; // r4
  char *v10; // r10
  unsigned int v11; // r4
  char v12; // r4
  char v13; // [sp+4Fh] [-31h] BYREF
  char v14[24]; // [sp+50h] [-30h] BYREF

  v3 = this;
  if ( this->buffer_size_ < 10 )
  {
    v8 = 0;
    if ( v9 > 0x7F )
    {
      v10 = &v13;
      do
      {
        ++v8;
        *++v10 = v11 | 0x80;
        *(_QWORD *)(&this - 1) >>= 7;
      }
      while ( v11 > 0x7F );
    }
    v14[v8] = v12 & 0x7F;
    google::protobuf::io::CodedOutputStream::WriteRaw(this: v3, data: v14, size: v8 + 1);
  }
  else
  {
    buffer = this->buffer_;
    v6 = google::protobuf::io::CodedOutputStream::WriteVarint64ToArrayInline(
           value: __PAIR64__(v5, (unsigned int)buffer),
           target: (unsigned __int8 *)HIDWORD(value));
    v7 = v3->buffer_size_ - (v6 - buffer);
    v3->buffer_ += v6 - buffer;
    v3->buffer_size_ = v7;
  }
}


// ========================================================================
// ?ReadRaw@CodedInputStream@io@protobuf@google@@QAA_NPAXH@Z
// EA  : 0x83221C18
// RVA : 0x01221C18
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadRaw(
        google::protobuf::io::CodedInputStream *this,
        char *buffer,
        int size)
{
  signed int v5; // r26
  int v6; // r23
  signed int v7; // r29
  int buffer_size_after_limit; // r10
  int total_bytes_read; // r9
  int total_bytes_warning_threshold; // r11
  google::protobuf::internal::LogMessage *v11; // r3
  int v12; // r18
  google::protobuf::internal::LogMessage *v13; // r3
  google::protobuf::internal::LogMessage *v14; // r3
  google::protobuf::internal::LogMessage *v15; // r3
  const unsigned __int8 *v16; // r10
  int v17; // r11
  google::protobuf::internal::LogMessage *v18; // r3
  google::protobuf::internal::LogMessage *v19; // r3
  int v20; // r10
  int v21; // r11
  bool v22; // zf
  const unsigned __int8 *buffer_end; // r10
  int *p_total_bytes_limit; // r11
  int v25; // r11
  int v26; // r10
  char v27; // r11
  const unsigned __int8 *v28; // r7
  int total_bytes_limit; // r11
  google::protobuf::internal::LogFinisher v31; // [sp+50h] [-E0h] BYREF
  google::protobuf::internal::LogFinisher v32; // [sp+51h] [-DFh] BYREF
  int v33; // [sp+54h] [-DCh] BYREF
  const unsigned __int8 *v34; // [sp+58h] [-D8h] BYREF
  int v35; // [sp+5Ch] [-D4h]
  google::protobuf::internal::LogMessage v36; // [sp+60h] [-D0h] BYREF
  google::protobuf::internal::LogMessage v37[4]; // [sp+90h] [-A0h] BYREF

  v35 = 0;
  v5 = size;
  v6 = 0;
  v7 = this->buffer_end_ - this->buffer_;
  if ( v7 >= size )
  {
LABEL_28:
    memcpy(Dst: buffer, Src: this->buffer_, Size: v5);
    this->buffer_ += v5;
    return 1;
  }
  while ( 1 )
  {
    memcpy(Dst: buffer, Src: this->buffer_, Size: v7);
    buffer_size_after_limit = this->buffer_size_after_limit_;
    buffer += v7;
    v5 -= v7;
    this->buffer_ += v7;
    if ( buffer_size_after_limit > 0
      || this->overflow_bytes_ > 0
      || (total_bytes_read = this->total_bytes_read_) == this->current_limit_ )
    {
      total_bytes_limit = this->total_bytes_limit_;
      if ( this->total_bytes_read_ - buffer_size_after_limit >= total_bytes_limit
        && total_bytes_limit != this->current_limit_ )
      {
        google::protobuf::io::CodedInputStream::PrintTotalBytesLimitError(this);
      }
      goto LABEL_25;
    }
    total_bytes_warning_threshold = this->total_bytes_warning_threshold_;
    if ( total_bytes_warning_threshold >= 0 && total_bytes_read >= total_bytes_warning_threshold )
    {
      v31 = 0;
      v11 = google::protobuf::internal::LogMessage::LogMessage(
              this: &v36,
              level: LOGLEVEL_WARNING,
              filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
              line: 487);
      v12 = this->total_bytes_limit_;
      v13 = google::protobuf::internal::LogMessage::operator<<(
              this: v11,
              value: "Reading dangerously large protocol message.  If the message turns out to be larger than ");
      v14 = google::protobuf::internal::LogMessage::operator<<(this: v13, value: v12);
      v15 = google::protobuf::internal::LogMessage::operator<<(
              this: v14,
              value: " bytes, parsing will be halted for security reasons.  To increase the limit (or to disable these warnings)"
              ", see CodedInputStream::SetTotalBytesLimit() in google/protobuf/io/coded_stream.h.");
      google::protobuf::internal::LogFinisher::operator=(this: &v31, other: v15);
      google::protobuf::internal::LogMessage::~LogMessage(this: &v36);
      this->total_bytes_warning_threshold_ = -1;
    }
    if ( (unsigned __int8)google::protobuf::io::`anonymous namespace'::NextNonEmpty(
                            input: this->input_,
                            data: (const void **)&v34,
                            size: &v33) == 0 )
    {
      this->buffer_ = nullptr;
      this->buffer_end_ = nullptr;
LABEL_25:
      v27 = 0;
      goto LABEL_26;
    }
    v16 = v34;
    v17 = v33;
    this->buffer_ = v34;
    this->buffer_end_ = &v16[v17];
    if ( v17 < 0 )
    {
      v32 = 0;
      v18 = google::protobuf::internal::LogMessage::LogMessage(
              this: v37,
              level: LOGLEVEL_FATAL,
              filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
              line: 504);
      v6 |= 2u;
      v35 = v6;
      v19 = google::protobuf::internal::LogMessage::operator<<(this: v18, value: "CHECK failed: (buffer_size) >= (0): ");
      google::protobuf::internal::LogFinisher::operator=(this: &v32, other: v19);
      v17 = v33;
    }
    if ( (v6 & 2) != 0 )
    {
      v6 &= ~2u;
      google::protobuf::internal::LogMessage::~LogMessage(this: v37);
      v17 = v33;
    }
    v20 = this->total_bytes_read_;
    v22 = v20 > 0x7FFFFFFF - v17;
    v21 = v20 + v17;
    if ( v22 )
    {
      buffer_end = this->buffer_end_;
      this->total_bytes_read_ = 0x7FFFFFFF;
      this->overflow_bytes_ = v21 - 0x7FFFFFFF;
      this->buffer_end_ = &buffer_end[-v21 + 0x7FFFFFFF];
    }
    else
    {
      this->total_bytes_read_ = v21;
    }
    p_total_bytes_limit = &this->total_bytes_limit_;
    this->buffer_end_ += this->buffer_size_after_limit_;
    if ( this->total_bytes_limit_ >= this->current_limit_ )
      p_total_bytes_limit = &this->current_limit_;
    v25 = *p_total_bytes_limit;
    v26 = this->total_bytes_read_;
    if ( v25 >= v26 )
    {
      this->buffer_size_after_limit_ = 0;
      v27 = 1;
    }
    else
    {
      v28 = &this->buffer_end_[-(v26 - v25)];
      this->buffer_size_after_limit_ = v26 - v25;
      v27 = 1;
      this->buffer_end_ = v28;
    }
LABEL_26:
    if ( v27 == 0 )
      return 0;
    v7 = this->buffer_end_ - this->buffer_;
    if ( v7 >= v5 )
      goto LABEL_28;
  }
}


// ========================================================================
// $M31957
// EA  : 0x83221EE0
// RVA : 0x01221EE0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _M31957()
{
  int v0; // r12

  google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$31877
// EA  : 0x83221F08
// RVA : 0x01221F08
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _unwind_31877()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 304;
  if ( (*(_DWORD *)(v0 - 304 + 92) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 92) &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v1 + 144));
  }
}


// ========================================================================
// ?ReadLittleEndian32Fallback@CodedInputStream@io@protobuf@google@@AAA_NPAI@Z
// EA  : 0x83221F50
// RVA : 0x01221F50
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadLittleEndian32Fallback(
        google::protobuf::io::CodedInputStream *this,
        unsigned int *value)
{
  const unsigned __int8 *buffer; // r11
  char v5[16]; // [sp+50h] [-20h] BYREF

  buffer = this->buffer_;
  if ( (unsigned int)(this->buffer_end_ - buffer) < 4 )
  {
    if ( (unsigned __int8)google::protobuf::io::CodedInputStream::ReadRaw(this, buffer: v5, size: 4) == 0 )
      return 0;
    buffer = (const unsigned __int8 *)v5;
  }
  else
  {
    this->buffer_ = buffer + 4;
  }
  *value = ((((__ROL4__(buffer[3], 8) | buffer[2]) << 8) | buffer[1]) << 8) | *buffer;
  return 1;
}


// ========================================================================
// ?ReadLittleEndian64Fallback@CodedInputStream@io@protobuf@google@@AAA_NPA_K@Z
// EA  : 0x83222000
// RVA : 0x01222000
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadLittleEndian64Fallback(
        google::protobuf::io::CodedInputStream *this,
        unsigned __int64 *value)
{
  const unsigned __int8 *buffer; // r11
  unsigned __int64 v5; // r9
  char v6[16]; // [sp+50h] [-20h] BYREF

  buffer = this->buffer_;
  if ( (unsigned int)(this->buffer_end_ - buffer) < 8 )
  {
    if ( (unsigned __int8)google::protobuf::io::CodedInputStream::ReadRaw(this, buffer: v6, size: 8) == 0 )
      return 0;
    buffer = (const unsigned __int8 *)v6;
  }
  else
  {
    this->buffer_ = buffer + 8;
  }
  HIDWORD(v5) = (((__ROL4__(buffer[7], 8) | buffer[6]) << 8) | buffer[5]) << 8;
  LODWORD(v5) = ((((__ROL4__(buffer[3], 8) | buffer[2]) << 8) | buffer[1]) << 8) | *buffer;
  *value = v5;
  return 1;
}


// ========================================================================
// ?ReadVarint64Slow@CodedInputStream@io@protobuf@google@@AAA_NPA_K@Z
// EA  : 0x832220E8
// RVA : 0x012220E8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadVarint64Slow(
        google::protobuf::io::CodedInputStream *this,
        unsigned __int64 *value)
{
  int v3; // r24
  __int64 v4; // r18
  int i; // r19
  int v6; // r10
  int total_bytes_warning_threshold; // r11
  google::protobuf::internal::LogMessage *v8; // r3
  int v9; // r29
  google::protobuf::internal::LogMessage *v10; // r3
  google::protobuf::internal::LogMessage *v11; // r3
  google::protobuf::internal::LogMessage *v12; // r3
  google::protobuf::io::ZeroCopyInputStream *input; // r29
  BOOL v14; // r10
  int v15; // r11
  const unsigned __int8 *v16; // r10
  google::protobuf::internal::LogMessage *v17; // r3
  google::protobuf::internal::LogMessage *v18; // r3
  int total_bytes_read; // r10
  int v20; // r11
  bool v21; // zf
  const unsigned __int8 *buffer_end; // r10
  int *p_total_bytes_limit; // r11
  int v24; // r11
  int v25; // r10
  char v26; // r11
  const unsigned __int8 *v27; // r7
  int total_bytes_limit; // r11
  const unsigned __int8 *buffer; // r11
  unsigned __int8 v30; // r8
  __int64 v31; // r7
  google::protobuf::internal::LogFinisher v33; // [sp+50h] [-F0h] BYREF
  google::protobuf::internal::LogFinisher v34; // [sp+51h] [-EFh] BYREF
  int v35; // [sp+54h] [-ECh] BYREF
  const unsigned __int8 *v36; // [sp+58h] [-E8h] BYREF
  int v37; // [sp+5Ch] [-E4h]
  google::protobuf::internal::LogMessage v38; // [sp+60h] [-E0h] BYREF
  google::protobuf::internal::LogMessage v39[4]; // [sp+90h] [-B0h] BYREF

  v37 = 0;
  HIDWORD(v4) = value;
  v3 = 0;
  LODWORD(v4) = 0;
  for ( i = 0; i != 70; i += 7 )
  {
    while ( this->buffer_ == this->buffer_end_ )
    {
      if ( this->buffer_size_after_limit_ > 0
        || this->overflow_bytes_ > 0
        || (v6 = this->total_bytes_read_) == this->current_limit_ )
      {
        total_bytes_limit = this->total_bytes_limit_;
        if ( this->total_bytes_read_ - this->buffer_size_after_limit_ >= total_bytes_limit
          && total_bytes_limit != this->current_limit_ )
        {
          google::protobuf::io::CodedInputStream::PrintTotalBytesLimitError(this);
        }
LABEL_29:
        v26 = 0;
      }
      else
      {
        total_bytes_warning_threshold = this->total_bytes_warning_threshold_;
        if ( total_bytes_warning_threshold >= 0 && v6 >= total_bytes_warning_threshold )
        {
          v33 = 0;
          v8 = google::protobuf::internal::LogMessage::LogMessage(
                 this: &v38,
                 level: LOGLEVEL_WARNING,
                 filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
                 line: 487);
          v9 = this->total_bytes_limit_;
          v10 = google::protobuf::internal::LogMessage::operator<<(
                  this: v8,
                  value: "Reading dangerously large protocol message.  If the message turns out to be larger than ");
          v11 = google::protobuf::internal::LogMessage::operator<<(this: v10, value: v9);
          v12 = google::protobuf::internal::LogMessage::operator<<(
                  this: v11,
                  value: " bytes, parsing will be halted for security reasons.  To increase the limit (or to disable these warni"
                  "ngs), see CodedInputStream::SetTotalBytesLimit() in google/protobuf/io/coded_stream.h.");
          google::protobuf::internal::LogFinisher::operator=(this: &v33, other: v12);
          google::protobuf::internal::LogMessage::~LogMessage(this: &v38);
          this->total_bytes_warning_threshold_ = -1;
        }
        input = this->input_;
        do
        {
          v14 = input->Next(this: input, a2: (const void **)&v36, a3: &v35);
          v15 = v35;
          if ( !v14 )
          {
            this->buffer_ = nullptr;
            this->buffer_end_ = nullptr;
            goto LABEL_29;
          }
        }
        while ( v35 == 0 );
        v16 = v36;
        this->buffer_end_ = &v36[v35];
        this->buffer_ = v16;
        if ( v15 < 0 )
        {
          v34 = 0;
          v17 = google::protobuf::internal::LogMessage::LogMessage(
                  this: v39,
                  level: LOGLEVEL_FATAL,
                  filename: "w:\\tech5\\libs\\protobuf-2.4.1\\src\\google\\protobuf\\io\\coded_stream.cc",
                  line: 504);
          v3 |= 2u;
          v37 = v3;
          v18 = google::protobuf::internal::LogMessage::operator<<(
                  this: v17,
                  value: "CHECK failed: (buffer_size) >= (0): ");
          google::protobuf::internal::LogFinisher::operator=(this: &v34, other: v18);
          v15 = v35;
        }
        if ( (v3 & 2) != 0 )
        {
          v3 &= ~2u;
          google::protobuf::internal::LogMessage::~LogMessage(this: v39);
          v15 = v35;
        }
        total_bytes_read = this->total_bytes_read_;
        v21 = total_bytes_read > 0x7FFFFFFF - v15;
        v20 = total_bytes_read + v15;
        if ( v21 )
        {
          buffer_end = this->buffer_end_;
          this->total_bytes_read_ = 0x7FFFFFFF;
          this->overflow_bytes_ = v20 - 0x7FFFFFFF;
          this->buffer_end_ = &buffer_end[-v20 + 0x7FFFFFFF];
        }
        else
        {
          this->total_bytes_read_ = v20;
        }
        p_total_bytes_limit = &this->total_bytes_limit_;
        this->buffer_end_ += this->buffer_size_after_limit_;
        if ( this->total_bytes_limit_ >= this->current_limit_ )
          p_total_bytes_limit = &this->current_limit_;
        v24 = *p_total_bytes_limit;
        v25 = this->total_bytes_read_;
        if ( v24 >= v25 )
        {
          this->buffer_size_after_limit_ = 0;
          v26 = 1;
        }
        else
        {
          v27 = &this->buffer_end_[-(v25 - v24)];
          this->buffer_size_after_limit_ = v25 - v24;
          v26 = 1;
          this->buffer_end_ = v27;
        }
      }
      if ( v26 == 0 )
        return 0;
    }
    buffer = this->buffer_;
    v30 = *buffer;
    this->buffer_ = buffer + 1;
    LODWORD(v31) = v30 & 0x7F;
    HIDWORD(v31) = v30 & 0x80;
    LODWORD(v4) = (v31 << i) | v4;
    if ( (v30 & 0x80) == 0 )
    {
      *(_QWORD *)HIDWORD(v4) = v4;
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// $M32123
// EA  : 0x832223CC
// RVA : 0x012223CC
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _M32123()
{
  int v0; // r12

  google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$32022
// EA  : 0x832223F4
// RVA : 0x012223F4
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

void _unwind_32022()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 320;
  if ( (*(_DWORD *)(v0 - 320 + 92) & 2) != 0 )
  {
    *(_DWORD *)(v1 + 92) &= ~2u;
    google::protobuf::internal::LogMessage::~LogMessage(this: (google::protobuf::internal::LogMessage *)(v1 + 144));
  }
}


// ========================================================================
// ?ReadVarint64Fallback@CodedInputStream@io@protobuf@google@@AAA_NPA_K@Z
// EA  : 0x83222438
// RVA : 0x01222438
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadVarint64Fallback(
        google::protobuf::io::CodedInputStream *this,
        unsigned __int64 *value)
{
  const unsigned __int8 *buffer_end; // r10
  const unsigned __int8 *buffer; // r11
  int v5; // r8
  int v6; // r7
  const unsigned __int8 *v7; // r11
  unsigned __int64 v8; // r10
  int v9; // r7
  int v10; // r7
  int v11; // r7
  int v12; // r7
  int v13; // r7
  int v14; // r7
  int v15; // r7
  int v16; // r7
  int v17; // r7

  buffer_end = this->buffer_end_;
  buffer = this->buffer_;
  if ( buffer_end - buffer < 10 && (buffer_end <= buffer || (*(buffer_end - 1) & 0x80) != 0) )
    return google::protobuf::io::CodedInputStream::ReadVarint64Slow(this, value);
  LODWORD(v8) = 0;
  v5 = 0;
  v6 = *buffer & 0x80;
  HIDWORD(v8) = *buffer & 0x7F;
  v7 = buffer + 1;
  if ( v6 != 0 )
  {
    v9 = *v7++;
    HIDWORD(v8) |= (v9 << 7) & 0x3F80;
    if ( (v9 & 0x80) != 0 )
    {
      v10 = *v7++;
      HIDWORD(v8) |= (v10 << 14) & 0x1FC000;
      if ( (v10 & 0x80) != 0 )
      {
        v11 = *v7++;
        HIDWORD(v8) |= (v11 << 21) & 0xFE00000;
        if ( (v11 & 0x80) != 0 )
        {
          v12 = *v7 & 0x80;
          LODWORD(v8) = *v7++ & 0x7F;
          if ( v12 != 0 )
          {
            v13 = *v7++;
            LODWORD(v8) = (v13 << 7) & 0x3F80 | v8;
            if ( (v13 & 0x80) != 0 )
            {
              v14 = *v7++;
              LODWORD(v8) = (v14 << 14) & 0x1FC000 | v8;
              if ( (v14 & 0x80) != 0 )
              {
                v15 = *v7++;
                LODWORD(v8) = (v15 << 21) & 0xFE00000 | v8;
                if ( (v15 & 0x80) != 0 )
                {
                  v16 = *v7 & 0x80;
                  v5 = *v7++ & 0x7F;
                  if ( v16 != 0 )
                  {
                    v17 = *v7++;
                    v5 |= (v17 << 7) & 0x3F80;
                    if ( (v17 & 0x80) != 0 )
                      return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  this->buffer_ = v7;
  LODWORD(v8) = (((v5 << 28) | (unsigned int)v8) << 28) | HIDWORD(v8);
  *value = v8;
  return 1;
}


// ========================================================================
// ?ReadVarint32Slow@CodedInputStream@io@protobuf@google@@AAA_NPAI@Z
// EA  : 0x832225B0
// RVA : 0x012225B0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadVarint32Slow(
        google::protobuf::io::CodedInputStream *this,
        unsigned int *value)
{
  unsigned __int64 v4; // [sp+50h] [-20h] BYREF

  if ( (unsigned __int8)google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this, value: &v4) == 0 )
    return 0;
  *value = v4;
  return 1;
}


// ========================================================================
// ?ReadVarint32Fallback@CodedInputStream@io@protobuf@google@@AAA_NPAI@Z
// EA  : 0x83222610
// RVA : 0x01222610
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
        google::protobuf::io::CodedInputStream *this,
        unsigned int *value)
{
  const unsigned __int8 *buffer_end; // r11
  const unsigned __int8 *buffer; // r3
  int result; // r3

  buffer_end = this->buffer_end_;
  buffer = this->buffer_;
  if ( buffer_end - buffer < 10 && (buffer_end <= buffer || (*(buffer_end - 1) & 0x80) != 0) )
    return google::protobuf::io::CodedInputStream::ReadVarint32Slow(this, value);
  result = (int)google::protobuf::io::`anonymous namespace'::ReadVarint32FromArray(buffer, value);
  if ( result != 0 )
  {
    this->buffer_ = (const unsigned __int8 *)result;
    return 1;
  }
  return result;
}


// ========================================================================
// ?ReadTagSlow@CodedInputStream@io@protobuf@google@@AAAIXZ
// EA  : 0x832226A8
// RVA : 0x012226A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadTagSlow(google::protobuf::io::CodedInputStream *this)
{
  int total_bytes_limit; // r11
  int result; // r3
  const unsigned __int8 *buffer; // r11
  int v5; // r10
  int v6; // r11
  char v7; // r3
  bool v8; // zf
  unsigned __int64 v9; // [sp+50h] [-20h] BYREF

  if ( this->buffer_ != this->buffer_end_ || (unsigned __int8)google::protobuf::io::CodedInputStream::Refresh(this) != 0 )
  {
    buffer = this->buffer_;
    if ( buffer >= this->buffer_end_ || (unsigned int)(v5 = *buffer) >= 0x80 )
    {
      v7 = google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this, value: &v9);
      v6 = v9;
    }
    else
    {
      this->buffer_ = buffer + 1;
      v6 = (unsigned __int8)v5;
      v7 = 1;
    }
    v8 = v7 == 0;
    result = 0;
    if ( !v8 )
      return v6;
  }
  else
  {
    total_bytes_limit = this->total_bytes_limit_;
    result = 0;
    this->legitimate_message_end_ = this->total_bytes_read_ - this->buffer_size_after_limit_ < total_bytes_limit
                                 || (_cntlzw(total_bytes_limit - this->current_limit_) & 0x20) != 0;
  }
  return result;
}


// ========================================================================
// ?ReadTagFallback@CodedInputStream@io@protobuf@google@@AAAIXZ
// EA  : 0x832227A8
// RVA : 0x012227A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

char *__fastcall google::protobuf::io::CodedInputStream::ReadTagFallback(google::protobuf::io::CodedInputStream *this)
{
  const unsigned __int8 *buffer_end; // r11
  const unsigned __int8 *buffer; // r3
  bool v4; // cr58
  int buffer_size_after_limit; // r11
  char *result; // r3
  const unsigned __int8 *v7; // r11
  char *v8; // [sp+50h] [-20h] BYREF

  buffer_end = this->buffer_end_;
  buffer = this->buffer_;
  if ( buffer_end - buffer < 10 )
  {
    v4 = buffer == buffer_end;
    if ( buffer >= buffer_end )
    {
LABEL_5:
      if ( !v4 )
        return (char *)google::protobuf::io::CodedInputStream::ReadTagSlow(this);
      buffer_size_after_limit = this->buffer_size_after_limit_;
      if ( buffer_size_after_limit <= 0 || this->total_bytes_read_ - buffer_size_after_limit >= this->total_bytes_limit_ )
        return (char *)google::protobuf::io::CodedInputStream::ReadTagSlow(this);
      this->legitimate_message_end_ = true;
      return nullptr;
    }
    if ( (*(buffer_end - 1) & 0x80) != 0 )
    {
      v4 = buffer == buffer_end;
      goto LABEL_5;
    }
  }
  result = google::protobuf::io::`anonymous namespace'::ReadVarint32FromArray(buffer, value: (unsigned int *)&v8);
  v7 = (const unsigned __int8 *)result;
  if ( result != nullptr )
  {
    result = v8;
    this->buffer_ = v7;
  }
  return result;
}


// ========================================================================
// ?ReadStringFallback@CodedInputStream@io@protobuf@google@@AAA_NPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
// EA  : 0x83222890
// RVA : 0x01222890
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream.cc
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::ReadStringFallback(
        google::protobuf::io::CodedInputStream *this,
        std::string *buffer,
        int size)
{
  signed int v5; // r29
  unsigned int Myres; // r11
  std::string *Ptr; // r11
  signed int v8; // r30

  v5 = size;
  if ( buffer->_Mysize != 0 )
  {
    Myres = buffer->_Myres;
    buffer->_Mysize = 0;
    if ( Myres < 0x10 )
      Ptr = buffer;
    else
      Ptr = (std::string *)buffer->_Bx._Ptr;
    Ptr->_Bx._Buf[0] = 0;
  }
  v8 = this->buffer_end_ - this->buffer_;
  if ( v8 >= size )
  {
LABEL_11:
    std::string::append(this: buffer, _Ptr: (const char *)this->buffer_, _Count: v5);
    this->buffer_ += v5;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      if ( v8 != 0 )
        std::string::append(this: buffer, _Ptr: (const char *)this->buffer_, _Count: v8);
      v5 -= v8;
      this->buffer_ += v8;
      if ( (unsigned __int8)google::protobuf::io::CodedInputStream::Refresh(this) == 0 )
        return 0;
      v8 = this->buffer_end_ - this->buffer_;
      if ( v8 >= v5 )
        goto LABEL_11;
    }
  }
}

