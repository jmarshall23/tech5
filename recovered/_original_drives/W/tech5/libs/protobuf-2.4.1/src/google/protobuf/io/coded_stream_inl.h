
// ========================================================================
// ?InternalReadStringInline@CodedInputStream@io@protobuf@google@@QAA_NPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
// EA  : 0x83222970
// RVA : 0x01222970
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\io\coded_stream_inl.h
// ========================================================================

int __fastcall google::protobuf::io::CodedInputStream::InternalReadStringInline(
        google::protobuf::io::CodedInputStream *this,
        std::string *buffer,
        int size)
{
  unsigned int Mysize; // r11
  std::string *Ptr; // r3

  if ( size < 0 )
    return 0;
  if ( this->buffer_end_ - this->buffer_ < size )
    return google::protobuf::io::CodedInputStream::ReadStringFallback(this, buffer, size);
  Mysize = buffer->_Mysize;
  if ( size > Mysize )
    std::string::append(this: buffer, _Count: size - Mysize, _Ch: 0);
  else
    std::string::erase(this: buffer, _Off: size, _Count: 0xFFFFFFFF);
  if ( buffer->_Mysize != 0 )
  {
    if ( buffer->_Myres < 0x10 )
      Ptr = buffer;
    else
      Ptr = (std::string *)buffer->_Bx._Ptr;
  }
  else
  {
    Ptr = nullptr;
  }
  memcpy(Dst: Ptr, Src: this->buffer_, Size: size);
  this->buffer_ += size;
  return 1;
}

