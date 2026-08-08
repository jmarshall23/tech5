
// ========================================================================
// ?WriteEnum@WireFormatLite@internal@protobuf@google@@SAXHHPAVCodedOutputStream@io@34@@Z
// EA  : 0x83222A48
// RVA : 0x01222A48
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteEnum(
        int field_number,
        int value,
        google::protobuf::io::CodedOutputStream *output)
{
  unsigned __int64 v5; // r6

  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: 8 * field_number);
  if ( value >= 0 )
    google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value);
  else
    google::protobuf::io::CodedOutputStream::WriteVarint64(this: output, a2: value, value: v5);
}


// ========================================================================
// ?WriteUInt32@WireFormatLite@internal@protobuf@google@@SAXHIPAVCodedOutputStream@io@34@@Z
// EA  : 0x83222AA8
// RVA : 0x01222AA8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteUInt32(
        int field_number,
        unsigned int value,
        google::protobuf::io::CodedOutputStream *output)
{
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: 8 * field_number);
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value);
}


// ========================================================================
// ?WriteUInt64@WireFormatLite@internal@protobuf@google@@SAXH_KPAVCodedOutputStream@io@34@@Z
// EA  : 0x83222AF8
// RVA : 0x01222AF8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteUInt64(
        int field_number,
        int a2,
        unsigned __int64 value,
        google::protobuf::io::CodedOutputStream *output)
{
  google::protobuf::io::CodedOutputStream *v5; // r30
  unsigned __int64 v6; // r6

  v5 = (google::protobuf::io::CodedOutputStream *)HIDWORD(value);
  google::protobuf::io::CodedOutputStream::WriteVarint32(
    this: (google::protobuf::io::CodedOutputStream *)HIDWORD(value),
    value: 8 * field_number);
  google::protobuf::io::CodedOutputStream::WriteVarint64(this: v5, a2, value: v6);
}


// ========================================================================
// ?WriteFloat@WireFormatLite@internal@protobuf@google@@SAXHMPAVCodedOutputStream@io@34@@Z
// EA  : 0x83222B48
// RVA : 0x01222B48
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteFloat(
        int field_number,
        double value,
        google::protobuf::io::CodedOutputStream *output,
        google::protobuf::io::CodedOutputStream *a4)
{
  unsigned int v5; // [sp+50h] [-20h]

  *(float *)&v5 = value;
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: a4, value: (8 * field_number) | 5);
  google::protobuf::io::CodedOutputStream::WriteLittleEndian32(this: a4, value: v5);
}


// ========================================================================
// ?WriteBool@WireFormatLite@internal@protobuf@google@@SAXH_NPAVCodedOutputStream@io@34@@Z
// EA  : 0x83222BA0
// RVA : 0x01222BA0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteBool(
        int field_number,
        bool value,
        google::protobuf::io::CodedOutputStream *output)
{
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: 8 * field_number);
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value);
}


// ========================================================================
// ?WriteMessage@WireFormatLite@internal@protobuf@google@@SAXHABVMessageLite@34@PAVCodedOutputStream@io@34@@Z
// EA  : 0x83222BF8
// RVA : 0x01222BF8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteMessage(
        int field_number,
        google::protobuf::MessageLite *value,
        google::protobuf::io::CodedOutputStream *output)
{
  unsigned int v5; // r3

  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: (8 * field_number) | 2);
  v5 = value->GetCachedSize(this: value);
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: v5);
  value->SerializeWithCachedSizes(this: value, a2: output);
}


// ========================================================================
// ?SkipField@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@34@I@Z
// EA  : 0x83222C78
// RVA : 0x01222C78
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

BOOL __fastcall google::protobuf::internal::WireFormatLite::SkipField(
        google::protobuf::io::CodedInputStream *input,
        unsigned int tag)
{
  unsigned int v2; // r11
  const unsigned __int8 *v5; // r11
  const unsigned __int8 *buffer; // r11
  char Varint32Fallback; // r3
  int recursion_limit; // r10
  int v10; // r11
  int recursion_depth; // r11
  int v12; // [sp+50h] [-30h] BYREF
  unsigned int v13; // [sp+54h] [-2Ch] BYREF
  unsigned __int64 v14; // [sp+58h] [-28h] BYREF
  unsigned __int64 v15; // [sp+60h] [-20h] BYREF

  v2 = tag & 7;
  if ( v2 > 5 )
    return false;
  if ( v2 == 1 )
    return (unsigned __int8)google::protobuf::io::CodedInputStream::ReadLittleEndian64Fallback(this: input, value: &v15) != 0;
  if ( v2 == 2 )
  {
    buffer = input->buffer_;
    if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
    {
      Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                           this: input,
                           value: (unsigned int *)&v12);
    }
    else
    {
      v12 = *buffer;
      Varint32Fallback = 1;
      input->buffer_ = buffer + 1;
    }
    if ( Varint32Fallback != 0 )
      return google::protobuf::io::CodedInputStream::Skip(this: input, count: v12);
    return false;
  }
  if ( v2 != 3 )
  {
    if ( v2 != 4 )
    {
      if ( (tag & 7) != 0 )
        return (unsigned __int8)google::protobuf::io::CodedInputStream::ReadLittleEndian32Fallback(
                                  this: input,
                                  value: &v13) != 0;
      v5 = input->buffer_;
      if ( v5 >= input->buffer_end_ || *v5 >= 0x80u )
        return (unsigned __int8)google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this: input, value: &v14) != 0;
      input->buffer_ = v5 + 1;
      return true;
    }
    return false;
  }
  recursion_limit = input->recursion_limit_;
  v10 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v10;
  if ( v10 > recursion_limit || !google::protobuf::internal::WireFormatLite::SkipMessage(input) )
    return false;
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return (_cntlzw((tag & 0xFFFFFFF8 | 4) - input->last_tag_) & 0x20) != 0;
}


// ========================================================================
// ?SkipMessage@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@34@@Z
// EA  : 0x83222E28
// RVA : 0x01222E28
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::SkipMessage(google::protobuf::io::CodedInputStream *input)
{
  const unsigned __int8 *buffer; // r11
  unsigned int v3; // r10
  unsigned int TagFallback; // r4

  while ( 1 )
  {
    buffer = input->buffer_;
    if ( buffer >= input->buffer_end_ || (v3 = *buffer) >= 0x80 )
    {
      TagFallback = (unsigned int)google::protobuf::io::CodedInputStream::ReadTagFallback(this: input);
      input->last_tag_ = TagFallback;
    }
    else
    {
      input->last_tag_ = v3;
      TagFallback = v3;
      input->buffer_ = buffer + 1;
    }
    if ( TagFallback == 0 || (TagFallback & 7) == 4 )
      break;
    if ( !google::protobuf::internal::WireFormatLite::SkipField(input, tag: TagFallback) )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?WriteBytes@WireFormatLite@internal@protobuf@google@@SAXHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAVCodedOutputStream@io@34@@Z
// EA  : 0x83222ED8
// RVA : 0x01222ED8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

void __fastcall google::protobuf::internal::WireFormatLite::WriteBytes(
        int field_number,
        std::string *value,
        google::protobuf::io::CodedOutputStream *output)
{
  std::string *Ptr; // r4

  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: (8 * field_number) | 2);
  google::protobuf::io::CodedOutputStream::WriteVarint32(this: output, value: value->_Mysize);
  if ( value->_Myres < 0x10 )
    Ptr = value;
  else
    Ptr = (std::string *)value->_Bx._Ptr;
  google::protobuf::io::CodedOutputStream::WriteRaw(this: output, data: Ptr->_Bx._Buf, size: value->_Mysize);
}


// ========================================================================
// ?ReadString@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@34@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x83222F50
// RVA : 0x01222F50
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

BOOL __fastcall google::protobuf::internal::WireFormatLite::ReadString(
        google::protobuf::io::CodedInputStream *input,
        std::string *value)
{
  const unsigned __int8 *buffer; // r11
  char Varint32Fallback; // r3
  int v7; // [sp+50h] [-20h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v7);
  }
  else
  {
    v7 = *buffer;
    Varint32Fallback = 1;
    input->buffer_ = buffer + 1;
  }
  return Varint32Fallback != 0
      && (unsigned __int8)google::protobuf::io::CodedInputStream::InternalReadStringInline(
                            this: input,
                            buffer: value,
                            size: v7) != 0;
}


// ========================================================================
// ?ReadBytes@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@34@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x83222FF0
// RVA : 0x01222FF0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite.cc
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadBytes(
        google::protobuf::io::CodedInputStream *input,
        std::string *value)
{
  const unsigned __int8 *buffer; // r11
  char Varint32Fallback; // r3
  int v7; // [sp+50h] [-20h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v7);
  }
  else
  {
    v7 = *buffer;
    Varint32Fallback = 1;
    input->buffer_ = buffer + 1;
  }
  if ( Varint32Fallback != 0 )
    return google::protobuf::io::CodedInputStream::InternalReadStringInline(this: input, buffer: value, size: v7);
  else
    return 0;
}

