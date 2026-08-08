
// ========================================================================
// ?Reserve@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXH@Z
// EA  : 0x83213D00
// RVA : 0x01213D00
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.cc
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::Reserve(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        int new_size,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  int total_size; // r11
  google::protobuf::internal::RepeatedPtrFieldBase *elements; // r30
  int *v17; // r11
  bool v18; // zf
  unsigned int v19; // r11
  unsigned int v20; // r3
  void **v21; // r3
  memTag_t v22; // r4
  int v23; // [sp+50h] [-20h] BYREF

  total_size = this->total_size_;
  a14 = new_size;
  if ( total_size < new_size )
  {
    elements = (google::protobuf::internal::RepeatedPtrFieldBase *)this->elements_;
    v23 = 2 * total_size;
    v18 = 2 * total_size < new_size;
    v17 = &a14;
    if ( !v18 )
      v17 = &v23;
    v19 = *v17;
    v20 = 4 * v19;
    this->total_size_ = v19;
    if ( v19 > 0x3FFFFFFF )
      v20 = -1;
    v21 = (void **)operator new[](s: v20);
    this->elements_ = v21;
    memcpy(Dst: v21, Src: elements, Size: 4 * this->allocated_size_);
    if ( elements != (google::protobuf::internal::RepeatedPtrFieldBase *)this->initial_space_ )
      operator delete(p: elements, tag: v22);
  }
}


// ========================================================================
// ?New@StringTypeHandlerBase@internal@protobuf@google@@SAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x83213DA8
// RVA : 0x01213DA8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.cc
// ========================================================================

std::string *__fastcall google::protobuf::internal::StringTypeHandlerBase::New()
{
  std::string *result; // r3

  result = (std::string *)operator new(s: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->_Mysize = 0;
  result->_Myres = 15;
  result->_Bx._Buf[0] = 0;
  return result;
}


// ========================================================================
// ?Delete@StringTypeHandlerBase@internal@protobuf@google@@SAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
// EA  : 0x83213E00
// RVA : 0x01213E00
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.cc
// ========================================================================

void __fastcall google::protobuf::internal::StringTypeHandlerBase::Delete(std::string *value, memTag_t a2)
{
  if ( value != nullptr )
  {
    if ( value->_Myres >= 0x10 )
      operator delete(p: value->_Bx._Ptr, tag: a2);
    value->_Mysize = 0;
    value->_Myres = 15;
    value->_Bx._Buf[0] = 0;
    operator delete(p: value, tag: a2);
  }
}

