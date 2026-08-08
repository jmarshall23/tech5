
// ========================================================================
// ??$MessageSizeNoVirtual@VXbox360VersionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVXbox360VersionInfo@idreports@@@Z
// EA  : 0x82F52CA8
// RVA : 0x00F52CA8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::Xbox360VersionInfo>(
        idreports::Xbox360VersionInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::Xbox360VersionInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VBigUInt@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVBigUInt@idreports@@@Z
// EA  : 0x82F52D08
// RVA : 0x00F52D08
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::BigUInt>(
        idreports::BigUInt *value)
{
  unsigned int v1; // r3

  v1 = idreports::BigUInt::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VMemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVMemoryInfo@idreports@@@Z
// EA  : 0x82F52D68
// RVA : 0x00F52D68
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::MemoryInfo>(
        idreports::MemoryInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::MemoryInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VXenonMemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVXenonMemoryInfo@idreports@@@Z
// EA  : 0x82F52DC8
// RVA : 0x00F52DC8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::XenonMemoryInfo>(
        idreports::XenonMemoryInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::XenonMemoryInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$ReadPrimitive@_J$02@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PA_J@Z
// EA  : 0x82F52E88
// RVA : 0x00F52E88
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadPrimitive<__int64,3>(
        google::protobuf::io::CodedInputStream *input,
        __int64 *value)
{
  __int64 v3; // r11
  bool v4; // r3
  unsigned __int64 v6; // [sp+50h] [-20h] BYREF

  LODWORD(v3) = input->buffer_;
  if ( (const unsigned __int8 *)v3 >= input->buffer_end_ || (HIDWORD(v3) = *(unsigned __int8 *)v3, HIDWORD(v3) >= 0x80) )
  {
    v4 = google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this: input, value: &v6);
    LODWORD(v3) = v6;
  }
  else
  {
    input->buffer_ = (const unsigned __int8 *)(v3 + 1);
    LODWORD(v3) = BYTE3(v3);
    v4 = true;
  }
  if ( !v4 )
    return 0;
  HIDWORD(v3) = v4;
  *value = v3;
  return 1;
}


// ========================================================================
// ??$ReadPrimitive@_N$07@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PA_N@Z
// EA  : 0x82F52F18
// RVA : 0x00F52F18
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadPrimitive<bool,8>(
        google::protobuf::io::CodedInputStream *input,
        bool *value)
{
  const unsigned __int8 *buffer; // r11
  unsigned int v4; // r10
  bool Varint32Fallback; // r3
  unsigned int v7[4]; // [sp+50h] [-20h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || (v4 = *buffer) >= 0x80 )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(this: input, value: v7);
    v4 = v7[0];
  }
  else
  {
    input->buffer_ = buffer + 1;
    Varint32Fallback = true;
  }
  if ( !Varint32Fallback )
    return 0;
  *value = v4 != 0;
  return 1;
}


// ========================================================================
// ??$ReadPrimitive@H$0O@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAH@Z
// EA  : 0x82F52FB0
// RVA : 0x00F52FB0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadPrimitive<int,14>(
        google::protobuf::io::CodedInputStream *input,
        int *value)
{
  const unsigned __int8 *buffer; // r11
  int v4; // r10
  bool Varint32Fallback; // r3
  unsigned int v7[4]; // [sp+50h] [-20h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || (unsigned int)(v4 = *buffer) >= 0x80 )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(this: input, value: v7);
    v4 = v7[0];
  }
  else
  {
    input->buffer_ = buffer + 1;
    Varint32Fallback = true;
  }
  if ( !Varint32Fallback )
    return 0;
  *value = v4;
  return 1;
}


// ========================================================================
// ?StringSize@WireFormatLite@internal@protobuf@google@@SAHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x82F53040
// RVA : 0x00F53040
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::StringSize(const std::string *value)
{
  unsigned int Mysize; // r3

  Mysize = value->_Mysize;
  if ( Mysize >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: Mysize) + value->_Mysize;
  else
    return value->_Mysize + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VAttachment@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVAttachment@idreports@@@Z
// EA  : 0x82F55CD0
// RVA : 0x00F55CD0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::Attachment>(
        idreports::Attachment *value)
{
  unsigned int v1; // r3

  v1 = idreports::Attachment::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VXbox360VersionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVXbox360VersionInfo@idreports@@@Z
// EA  : 0x82F55D30
// RVA : 0x00F55D30
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::Xbox360VersionInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::Xbox360VersionInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::Xbox360VersionInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VBigUInt@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVBigUInt@idreports@@@Z
// EA  : 0x82F55E10
// RVA : 0x00F55E10
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::BigUInt>(
        google::protobuf::io::CodedInputStream *input,
        idreports::BigUInt *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::BigUInt::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VMemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVMemoryInfo@idreports@@@Z
// EA  : 0x82F55EF0
// RVA : 0x00F55EF0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::MemoryInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::MemoryInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::MemoryInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VExceptionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVExceptionInfo@idreports@@@Z
// EA  : 0x82F55FD0
// RVA : 0x00F55FD0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::ExceptionInfo>(
        idreports::ExceptionInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::ExceptionInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VRegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVRegisterInfo@idreports@@@Z
// EA  : 0x82F56030
// RVA : 0x00F56030
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::RegisterInfo>(
        idreports::RegisterInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::RegisterInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VCPUInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVCPUInfo@idreports@@@Z
// EA  : 0x82F56090
// RVA : 0x00F56090
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::CPUInfo>(
        idreports::CPUInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::CPUInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VXenonMemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVXenonMemoryInfo@idreports@@@Z
// EA  : 0x82F560F0
// RVA : 0x00F560F0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::XenonMemoryInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::XenonMemoryInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::XenonMemoryInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VXbox360KitInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVXbox360KitInfo@idreports@@@Z
// EA  : 0x82F561D0
// RVA : 0x00F561D0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::Xbox360KitInfo>(
        idreports::Xbox360KitInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::Xbox360KitInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VPS3ExceptionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVPS3ExceptionInfo@idreports@@@Z
// EA  : 0x82F56230
// RVA : 0x00F56230
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::PS3ExceptionInfo>(
        idreports::PS3ExceptionInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::PS3ExceptionInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$ReadRepeatedPrimitive@I$0N@@WireFormatLite@internal@protobuf@google@@SA_NHIPAVCodedInputStream@io@23@PAV?$RepeatedField@I@23@@Z
// EA  : 0x82F573B8
// RVA : 0x00F573B8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<unsigned int,13>(
        int __formal,
        unsigned int tag,
        google::protobuf::io::CodedInputStream *input,
        google::protobuf::RepeatedField<unsigned int> *values,
        int a5,
        int a6)
{
  const unsigned __int8 *buffer; // r11
  int v10; // r9
  bool Varint32Fallback; // r3
  int i; // r29
  const unsigned __int8 *v14; // r11
  char v15; // r11
  const unsigned __int8 *v16; // r11
  const unsigned __int8 *v17; // r11
  bool v18; // r3
  unsigned int v19[16]; // [sp+50h] [-40h] BYREF

  buffer = input->buffer_;
  v10 = 0;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(this: input, value: v19);
  }
  else
  {
    v19[0] = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  google::protobuf::RepeatedField<unsigned int>::Add(
    this: values,
    value: v19,
    a3: (int)input,
    a4: (int)values,
    a5,
    a6,
    a7: v10);
  for ( i = values->total_size_ - values->current_size_; i > 0; --i )
  {
    if ( tag >= 0x80 )
    {
      if ( tag < 0x4000 )
      {
        v16 = input->buffer_;
        if ( input->buffer_end_ - v16 >= 2 && *v16 == (tag & 0x7F | 0x80) && v16[1] == (unsigned __int8)(tag >> 7) )
        {
          input->buffer_ = v16 + 2;
          v15 = 1;
          goto LABEL_18;
        }
      }
    }
    else
    {
      v14 = input->buffer_;
      if ( v14 < input->buffer_end_ && *v14 == tag )
      {
        input->buffer_ = v14 + 1;
        v15 = 1;
        goto LABEL_18;
      }
    }
    v15 = 0;
LABEL_18:
    if ( v15 == 0 )
      return 1;
    v17 = input->buffer_;
    if ( v17 >= input->buffer_end_ || *v17 >= 0x80u )
    {
      v18 = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(this: input, value: v19);
    }
    else
    {
      v19[0] = *v17;
      v18 = true;
      input->buffer_ = v17 + 1;
    }
    if ( !v18 )
      return 0;
    values->elements_[values->current_size_++] = v19[0];
  }
  return 1;
}


// ========================================================================
// ??$ReadRepeatedPrimitive@_K$03@WireFormatLite@internal@protobuf@google@@SA_NHIPAVCodedInputStream@io@23@PAV?$RepeatedField@_K@23@@Z
// EA  : 0x82F57558
// RVA : 0x00F57558
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<unsigned __int64,4>(
        int __formal,
        unsigned int tag,
        google::protobuf::io::CodedInputStream *input,
        google::protobuf::RepeatedField<unsigned __int64> *values,
        int a5,
        int a6)
{
  const unsigned __int8 *buffer; // r11
  unsigned __int64 buffer_end; // r10
  bool Varint64Fallback; // r3
  unsigned __int64 v13; // r10 OVERLAPPED
  int v14; // r29
  const unsigned __int8 *v15; // r11
  char v16; // r11
  const unsigned __int8 *v17; // r11
  const unsigned __int8 *v18; // r11
  bool v19; // r3
  int current_size; // r8
  unsigned __int64 v21[8]; // [sp+50h] [-40h] BYREF

  buffer = input->buffer_;
  buffer_end = (unsigned int)input->buffer_end_;
  if ( (unsigned int)buffer >= (unsigned int)buffer_end
    || (LODWORD(buffer_end) = *buffer, (unsigned int)buffer_end >= 0x80) )
  {
    Varint64Fallback = google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this: input, value: v21);
  }
  else
  {
    LODWORD(buffer_end) = (unsigned __int8)buffer_end;
    input->buffer_ = buffer + 1;
    Varint64Fallback = true;
    v21[0] = buffer_end;
  }
  if ( !Varint64Fallback )
    return 0;
  google::protobuf::RepeatedField<unsigned __int64>::Add(
    this: values,
    value: v21,
    a3: (int)input,
    a4: (int)values,
    a5,
    a6,
    a7: SHIDWORD(buffer_end));
  v14 = values->total_size_ - values->current_size_;
  while ( v14 > 0 )
  {
    if ( tag >= 0x80 )
    {
      if ( tag < 0x4000 )
      {
        v17 = input->buffer_;
        HIDWORD(v13) = input->buffer_end_ - v17;
        if ( SHIDWORD(v13) >= 2 )
        {
          HIDWORD(v13) = *v17;
          if ( HIDWORD(v13) == (tag & 0x7F | 0x80) )
          {
            HIDWORD(v13) = (unsigned __int8)(tag >> 7);
            if ( v17[1] == HIDWORD(v13) )
            {
              input->buffer_ = v17 + 2;
              v16 = 1;
              goto LABEL_18;
            }
          }
        }
      }
    }
    else
    {
      v15 = input->buffer_;
      if ( v15 < input->buffer_end_ && *v15 == tag )
      {
        input->buffer_ = v15 + 1;
        v16 = 1;
        goto LABEL_18;
      }
    }
    v16 = 0;
LABEL_18:
    if ( v16 == 0 )
      return 1;
    v18 = input->buffer_;
    if ( v18 >= input->buffer_end_ || (LODWORD(v13) = *v18, (unsigned int)v13 >= 0x80) )
    {
      v19 = google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this: input, value: v21);
    }
    else
    {
      LODWORD(v13) = (unsigned __int8)v13;
      input->buffer_ = v18 + 1;
      v19 = true;
      v21[0] = v13;
    }
    if ( !v19 )
      return 0;
    --v14;
    HIDWORD(v13) = v21[0];
    current_size = values->current_size_;
    values->elements_[current_size] = *(unsigned __int64 *)((char *)&v13 + 4);
    ++values->current_size_;
  }
  return 1;
}


// ========================================================================
// ??$ReadPackedPrimitive@I$0N@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAV?$RepeatedField@I@23@@Z
// EA  : 0x82F57AB8
// RVA : 0x00F57AB8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<unsigned int,13>(
        google::protobuf::io::CodedInputStream *input,
        google::protobuf::RepeatedField<unsigned int> *values)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int i; // r29
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  const unsigned __int8 *v13; // r11
  bool v14; // r3
  int total_size; // r11
  int current_size; // r10
  int v17; // [sp+8h] [-78h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+10h] [-70h]
  int v20; // [sp+14h] [-6Ch]
  int v21; // [sp+18h] [-68h]
  int v22; // [sp+1Ch] [-64h]
  int v23; // [sp+50h] [-30h] BYREF
  unsigned int v24; // [sp+54h] [-2Ch] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v23);
  }
  else
  {
    v23 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  for ( i = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v23);
        google::protobuf::io::CodedInputStream::BytesUntilLimit(this: input) > 0;
        values->elements_[values->current_size_++] = v24 )
  {
    v13 = input->buffer_;
    if ( v13 >= input->buffer_end_ || *v13 >= 0x80u )
    {
      v14 = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(this: input, value: &v24);
    }
    else
    {
      v24 = *v13;
      v14 = true;
      input->buffer_ = v13 + 1;
    }
    if ( !v14 )
      return 0;
    total_size = values->total_size_;
    current_size = values->current_size_;
    if ( current_size == total_size )
      google::protobuf::RepeatedField<unsigned int>::Reserve(
        this: values,
        new_size: total_size + 1,
        a3: v12,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: current_size,
        a9: v17,
        a10: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22);
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: i);
  return 1;
}


// ========================================================================
// ??$ReadPackedPrimitive@_K$03@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAV?$RepeatedField@_K@23@@Z
// EA  : 0x82F57BF0
// RVA : 0x00F57BF0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<unsigned __int64,4>(
        google::protobuf::io::CodedInputStream *input,
        google::protobuf::RepeatedField<unsigned __int64> *values)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int i; // r29
  unsigned __int64 v8; // r10
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  const unsigned __int8 *v13; // r11
  bool v14; // r3
  int total_size; // r11
  unsigned __int64 v16; // r9
  int v17; // [sp+8h] [-78h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+10h] [-70h]
  int v20; // [sp+14h] [-6Ch]
  int v21; // [sp+18h] [-68h]
  int v22; // [sp+1Ch] [-64h]
  int v23; // [sp+50h] [-30h] BYREF
  unsigned __int64 v24; // [sp+58h] [-28h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v23);
  }
  else
  {
    v23 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  for ( i = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v23);
        google::protobuf::io::CodedInputStream::BytesUntilLimit(this: input) > 0;
        ++values->current_size_ )
  {
    v13 = input->buffer_;
    if ( v13 >= input->buffer_end_ || (LODWORD(v8) = *v13, (unsigned int)v8 >= 0x80) )
    {
      v14 = google::protobuf::io::CodedInputStream::ReadVarint64Fallback(this: input, value: &v24);
    }
    else
    {
      LODWORD(v8) = (unsigned __int8)v8;
      input->buffer_ = v13 + 1;
      v14 = true;
      v24 = v8;
    }
    if ( !v14 )
      return 0;
    total_size = values->total_size_;
    LODWORD(v8) = values->current_size_;
    if ( (_DWORD)v8 == total_size )
      google::protobuf::RepeatedField<unsigned __int64>::Reserve(
        this: values,
        new_size: total_size + 1,
        a3: v12,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: SHIDWORD(v8),
        a8: v8,
        a9: v17,
        a10: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22);
    LODWORD(v16) = v24;
    HIDWORD(v16) = 8 * values->current_size_;
    *(unsigned __int64 *)((char *)values->elements_ + HIDWORD(v16)) = v16;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: i);
  return 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VXenonRegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVXenonRegisterInfo@idreports@@@Z
// EA  : 0x82F5CF00
// RVA : 0x00F5CF00
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::XenonRegisterInfo>(
        idreports::XenonRegisterInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::XenonRegisterInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VPPURegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVPPURegisterInfo@idreports@@@Z
// EA  : 0x82F5CF60
// RVA : 0x00F5CF60
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

unsigned int __fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::PPURegisterInfo>(
        idreports::PPURegisterInfo *value)
{
  unsigned int v1; // r3

  v1 = idreports::PPURegisterInfo::ByteSize(this: value);
  if ( v1 >= 0x80 )
    return google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: v1) + v1;
  else
    return v1 + 1;
}


// ========================================================================
// ??$MessageSizeNoVirtual@VPS3MemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SAHABVPS3MemoryInfo@idreports@@@Z
// EA  : 0x82F5CFC0
// RVA : 0x00F5CFC0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

char *__fastcall google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual<idreports::PS3MemoryInfo>(
        idreports::PS3MemoryInfo *value)
{
  char *v1; // r3

  v1 = idreports::PS3MemoryInfo::ByteSize(this: value);
  if ( (unsigned int)v1 >= 0x80 )
    return &v1[google::protobuf::io::CodedOutputStream::VarintSize32Fallback(value: (unsigned int)v1)];
  else
    return v1 + 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VAttachment@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVAttachment@idreports@@@Z
// EA  : 0x82F690A8
// RVA : 0x00F690A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::Attachment>(
        google::protobuf::io::CodedInputStream *input,
        idreports::Attachment *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::Attachment::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VMapWarning@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVMapWarning@idreports@@@Z
// EA  : 0x82F69188
// RVA : 0x00F69188
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::MapWarning>(
        google::protobuf::io::CodedInputStream *input,
        idreports::MapWarning *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  const unsigned __int8 *v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int recursion_depth; // r11
  int v15; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v15);
  }
  else
  {
    v15 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v15);
  if ( (unsigned __int8)idreports::MapWarning::MergePartialFromCodedStream(
                          this: value,
                          input,
                          a3: v13,
                          a4: v12,
                          a5: v11,
                          a6: v10) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VHeapCategoryUsage@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVHeapCategoryUsage@idreports@@@Z
// EA  : 0x82F69268
// RVA : 0x00F69268
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::HeapCategoryUsage>(
        google::protobuf::io::CodedInputStream *input,
        idreports::HeapCategoryUsage *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::HeapCategoryUsage::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VPS3VMRegionStats@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVPS3VMRegionStats@idreports@@@Z
// EA  : 0x82F69348
// RVA : 0x00F69348
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::PS3VMRegionStats>(
        google::protobuf::io::CodedInputStream *input,
        idreports::PS3VMRegionStats *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::PS3VMRegionStats::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VCallstackLine@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVCallstackLine@idreports@@@Z
// EA  : 0x82F69428
// RVA : 0x00F69428
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::CallstackLine>(
        google::protobuf::io::CodedInputStream *input,
        idreports::CallstackLine *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::CallstackLine::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VExceptionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVExceptionInfo@idreports@@@Z
// EA  : 0x82F69508
// RVA : 0x00F69508
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::ExceptionInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::ExceptionInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::ExceptionInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VRegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVRegisterInfo@idreports@@@Z
// EA  : 0x82F695E8
// RVA : 0x00F695E8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::RegisterInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::RegisterInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::RegisterInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VCPUInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVCPUInfo@idreports@@@Z
// EA  : 0x82F696C8
// RVA : 0x00F696C8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::CPUInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::CPUInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::CPUInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VXbox360KitInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVXbox360KitInfo@idreports@@@Z
// EA  : 0x82F697A8
// RVA : 0x00F697A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::Xbox360KitInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::Xbox360KitInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::Xbox360KitInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VXenonRegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVXenonRegisterInfo@idreports@@@Z
// EA  : 0x82F69888
// RVA : 0x00F69888
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::XenonRegisterInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::XenonRegisterInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::XenonRegisterInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VPS3ExceptionInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVPS3ExceptionInfo@idreports@@@Z
// EA  : 0x82F69968
// RVA : 0x00F69968
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::PS3ExceptionInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::PS3ExceptionInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::PS3ExceptionInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VPPURegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVPPURegisterInfo@idreports@@@Z
// EA  : 0x82F69A48
// RVA : 0x00F69A48
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::PPURegisterInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::PPURegisterInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int recursion_depth; // r11
  int v15; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v15);
  }
  else
  {
    v15 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v15);
  if ( (unsigned __int8)idreports::PPURegisterInfo::MergePartialFromCodedStream(
                          this: value,
                          input,
                          a3: v13,
                          a4: v12,
                          a5: v11,
                          a6: v10) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VSPURegisterInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVSPURegisterInfo@idreports@@@Z
// EA  : 0x82F69B28
// RVA : 0x00F69B28
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::SPURegisterInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::SPURegisterInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int recursion_depth; // r11
  int v15; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v15);
  }
  else
  {
    v15 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v15);
  if ( (unsigned __int8)idreports::SPURegisterInfo::MergePartialFromCodedStream(
                          this: value,
                          input,
                          a3: v13,
                          a4: v12,
                          a5: v11,
                          a6: v10) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}


// ========================================================================
// ??$ReadMessageNoVirtual@VPS3MemoryInfo@idreports@@@WireFormatLite@internal@protobuf@google@@SA_NPAVCodedInputStream@io@23@PAVPS3MemoryInfo@idreports@@@Z
// EA  : 0x82F6E400
// RVA : 0x00F6E400
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\wire_format_lite_inl.h
// ========================================================================

int __fastcall google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual<idreports::PS3MemoryInfo>(
        google::protobuf::io::CodedInputStream *input,
        idreports::PS3MemoryInfo *value)
{
  const unsigned __int8 *buffer; // r11
  bool Varint32Fallback; // r3
  int recursion_limit; // r10
  int v8; // r11
  int v9; // r30
  int recursion_depth; // r11
  int v11; // [sp+50h] [-30h] BYREF

  buffer = input->buffer_;
  if ( buffer >= input->buffer_end_ || *buffer >= 0x80u )
  {
    Varint32Fallback = google::protobuf::io::CodedInputStream::ReadVarint32Fallback(
                         this: input,
                         value: (unsigned int *)&v11);
  }
  else
  {
    v11 = *buffer;
    Varint32Fallback = true;
    input->buffer_ = buffer + 1;
  }
  if ( !Varint32Fallback )
    return 0;
  recursion_limit = input->recursion_limit_;
  v8 = input->recursion_depth_ + 1;
  input->recursion_depth_ = v8;
  if ( v8 > recursion_limit )
    return 0;
  v9 = google::protobuf::io::CodedInputStream::PushLimit(this: input, byte_limit: v11);
  if ( (unsigned __int8)idreports::PS3MemoryInfo::MergePartialFromCodedStream(this: value, input) == 0
    || !input->legitimate_message_end_ )
  {
    return 0;
  }
  google::protobuf::io::CodedInputStream::PopLimit(this: input, limit: v9);
  recursion_depth = input->recursion_depth_;
  if ( recursion_depth > 0 )
    input->recursion_depth_ = recursion_depth - 1;
  return 1;
}

