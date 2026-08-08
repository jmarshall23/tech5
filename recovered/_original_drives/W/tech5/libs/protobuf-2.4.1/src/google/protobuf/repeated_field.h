
// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// EA  : 0x828948E8
// RVA : 0x008948E8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

std::string *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  std::string *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = google::protobuf::internal::StringTypeHandlerBase::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (std::string *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$Clear@VTypeHandler@?$RepeatedPtrField@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXXZ
// EA  : 0x82894F90
// RVA : 0x00894F90
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::Clear<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int v1; // r9
  int v2; // r10
  _DWORD *v3; // r11
  unsigned int v4; // r7

  v1 = 0;
  if ( this->current_size_ > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->elements_[v2];
      v4 = v3[5];
      v3[4] = 0;
      if ( v4 >= 0x10 )
        v3 = (_DWORD *)*v3;
      ++v1;
      *(_BYTE *)v3 = 0;
      ++v2;
    }
    while ( v1 < this->current_size_ );
  }
  this->current_size_ = 0;
}


// ========================================================================
// ?New@?$GenericTypeHandler@VMapWarning@idreports@@@internal@protobuf@google@@SAPAVMapWarning@idreports@@XZ
// EA  : 0x82EF5230
// RVA : 0x00EF5230
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::MapWarning *__fastcall google::protobuf::internal::GenericTypeHandler<idreports::MapWarning>::New()
{
  idreports::MapWarning *v0; // r3

  v0 = (idreports::MapWarning *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x30u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idreports::MapWarning::MapWarning(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$160362
// EA  : 0x82EF5298
// RVA : 0x00EF5298
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall _unwind_160362(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VMapWarning@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVMapWarning@idreports@@XZ
// EA  : 0x82EF5660
// RVA : 0x00EF5660
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::MapWarning *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::MapWarning>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::MapWarning *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = google::protobuf::internal::GenericTypeHandler<idreports::MapWarning>::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::MapWarning *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??1?$RepeatedField@I@protobuf@google@@QAA@XZ
// EA  : 0x82F55C80
// RVA : 0x00F55C80
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned int>::~RepeatedField<unsigned int>(
        google::protobuf::RepeatedField<unsigned int> *this)
{
  if ( this->elements_ != this->initial_space_ )
    idMem::Free(this: &mem, ptr: this->elements_, align: ALIGN_16);
}


// ========================================================================
// ??1?$RepeatedField@_K@protobuf@google@@QAA@XZ
// EA  : 0x82F55CA8
// RVA : 0x00F55CA8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned __int64>::~RepeatedField<unsigned __int64>(
        google::protobuf::RepeatedField<unsigned __int64> *this)
{
  if ( this->elements_ != this->initial_space_ )
    idMem::Free(this: &mem, ptr: this->elements_, align: ALIGN_16);
}


// ========================================================================
// ??$Destroy@VTypeHandler@?$RepeatedPtrField@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXXZ
// EA  : 0x82F56290
// RVA : 0x00F56290
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::Destroy<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int v2; // r29
  int v3; // r31

  v2 = 0;
  if ( this->allocated_size_ > 0 )
  {
    v3 = 0;
    do
    {
      google::protobuf::internal::StringTypeHandlerBase::Delete(value: (std::string *)this->elements_[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->allocated_size_ );
  }
  if ( this->elements_ != this->initial_space_ )
    idMem::Free(this: &mem, ptr: this->elements_, align: ALIGN_16);
}


// ========================================================================
// ?Reserve@?$RepeatedField@I@protobuf@google@@QAAXH@Z
// EA  : 0x82F56300
// RVA : 0x00F56300
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned int>::Reserve(
        google::protobuf::RepeatedField<unsigned int> *this,
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
  google::protobuf::RepeatedField<unsigned int> *elements; // r29
  int *v17; // r11
  bool v18; // zf
  unsigned int v19; // r11
  unsigned int v20; // r5
  unsigned int *v21; // r3
  int v22; // [sp+50h] [-30h] BYREF

  total_size = this->total_size_;
  a14 = new_size;
  if ( total_size < new_size )
  {
    elements = (google::protobuf::RepeatedField<unsigned int> *)this->elements_;
    v22 = 2 * total_size;
    v18 = 2 * total_size < new_size;
    v17 = &a14;
    if ( !v18 )
      v17 = &v22;
    v19 = *v17;
    v20 = 4 * v19;
    this->total_size_ = v19;
    if ( v19 > 0x3FFFFFFF )
      v20 = -1;
    v21 = (unsigned int *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                            size: v20,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    this->elements_ = v21;
    memcpy(Dst: v21, Src: elements, Size: 4 * this->current_size_);
    if ( elements != (google::protobuf::RepeatedField<unsigned int> *)this->initial_space_ )
      idMem::Free(this: &mem, ptr: elements, align: ALIGN_16);
  }
}


// ========================================================================
// ?Reserve@?$RepeatedField@_K@protobuf@google@@QAAXH@Z
// EA  : 0x82F563C0
// RVA : 0x00F563C0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned __int64>::Reserve(
        google::protobuf::RepeatedField<unsigned __int64> *this,
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
  google::protobuf::RepeatedField<unsigned __int64> *elements; // r29
  int *v17; // r11
  bool v18; // zf
  unsigned int v19; // r11
  unsigned int v20; // r5
  unsigned __int64 *v21; // r3
  int v22; // [sp+50h] [-30h] BYREF

  total_size = this->total_size_;
  a14 = new_size;
  if ( total_size < new_size )
  {
    elements = (google::protobuf::RepeatedField<unsigned __int64> *)this->elements_;
    v22 = 2 * total_size;
    v18 = 2 * total_size < new_size;
    v17 = &a14;
    if ( !v18 )
      v17 = &v22;
    v19 = *v17;
    v20 = 8 * v19;
    this->total_size_ = v19;
    if ( v19 > 0x1FFFFFFF )
      v20 = -1;
    v21 = (unsigned __int64 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                size: v20,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    this->elements_ = v21;
    memcpy(Dst: v21, Src: elements, Size: 8 * this->current_size_);
    if ( elements != (google::protobuf::RepeatedField<unsigned __int64> *)this->initial_space_ )
      idMem::Free(this: &mem, ptr: elements, align: ALIGN_16);
  }
}


// ========================================================================
// ??$Clear@VTypeHandler@?$RepeatedPtrField@VHeapCategoryUsage@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXXZ
// EA  : 0x82F56480
// RVA : 0x00F56480
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::Clear<google::protobuf::RepeatedPtrField<idreports::HeapCategoryUsage>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int v2; // r29
  int v3; // r31

  v2 = 0;
  if ( this->current_size_ > 0 )
  {
    v3 = 0;
    do
    {
      (*(void (__fastcall **)(void *))(*(_DWORD *)this->elements_[v3] + 12))(a1: this->elements_[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->current_size_ );
  }
  this->current_size_ = 0;
}


// ========================================================================
// ??$Destroy@VTypeHandler@?$RepeatedPtrField@VMapWarning@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXXZ
// EA  : 0x82F564E0
// RVA : 0x00F564E0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::Destroy<google::protobuf::RepeatedPtrField<idreports::MapWarning>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int v2; // r29
  int v3; // r31
  void (__fastcall ***v4)(void *, int); // r3

  v2 = 0;
  if ( this->allocated_size_ > 0 )
  {
    v3 = 0;
    do
    {
      v4 = (void (__fastcall ***)(void *, int))this->elements_[v3];
      if ( v4 != nullptr )
        (**v4)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->allocated_size_ );
  }
  if ( this->elements_ != this->initial_space_ )
    idMem::Free(this: &mem, ptr: this->elements_, align: ALIGN_16);
}


// ========================================================================
// ??1?$RepeatedPtrField@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@protobuf@google@@QAA@XZ
// EA  : 0x82F571D8
// RVA : 0x00F571D8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

// attributes: thunk
void __fastcall google::protobuf::RepeatedPtrField<std::string>::~RepeatedPtrField<std::string>(
        google::protobuf::RepeatedPtrField<std::string > *this)
{
  google::protobuf::internal::RepeatedPtrFieldBase::Destroy<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this);
}


// ========================================================================
// ?Add@?$RepeatedField@I@protobuf@google@@QAAXABI@Z
// EA  : 0x82F571E0
// RVA : 0x00F571E0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned int>::Add(
        google::protobuf::RepeatedField<unsigned int> *this,
        unsigned int *value,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int total_size; // r11
  int current_size; // r10
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  int v14; // [sp+14h] [-5Ch]
  int v15; // [sp+18h] [-58h]
  int v16; // [sp+1Ch] [-54h]

  total_size = this->total_size_;
  current_size = this->current_size_;
  if ( current_size == total_size )
    google::protobuf::RepeatedField<unsigned int>::Reserve(
      this,
      new_size: total_size + 1,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8: current_size,
      a9: v11,
      a10: v12,
      a11: v13,
      a12: v14,
      a13: v15,
      a14: v16);
  this->elements_[this->current_size_++] = *value;
}


// ========================================================================
// ?MergeFrom@?$RepeatedField@I@protobuf@google@@QAAXABV123@@Z
// EA  : 0x82F57250
// RVA : 0x00F57250
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned int>::MergeFrom(
        google::protobuf::RepeatedField<unsigned int> *this,
        const google::protobuf::RepeatedField<unsigned int> *other,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]
  int v13; // [sp+18h] [-58h]
  int v14; // [sp+1Ch] [-54h]

  google::protobuf::RepeatedField<unsigned int>::Reserve(
    this,
    new_size: this->current_size_ + other->current_size_,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8: this->current_size_,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12,
    a13: v13,
    a14: v14);
  memcpy(Dst: &this->elements_[this->current_size_], Src: other->elements_, Size: 4 * other->current_size_);
  this->current_size_ += other->current_size_;
}


// ========================================================================
// ?Add@?$RepeatedField@_K@protobuf@google@@QAAXAB_K@Z
// EA  : 0x82F572C8
// RVA : 0x00F572C8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned __int64>::Add(
        google::protobuf::RepeatedField<unsigned __int64> *this,
        const unsigned __int64 *value,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int total_size; // r11
  int current_size; // r10
  __int64 v11; // r10
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+18h] [-58h]
  int v17; // [sp+1Ch] [-54h]

  total_size = this->total_size_;
  current_size = this->current_size_;
  if ( current_size == total_size )
    google::protobuf::RepeatedField<unsigned __int64>::Reserve(
      this,
      new_size: total_size + 1,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8: current_size,
      a9: v12,
      a10: v13,
      a11: v14,
      a12: v15,
      a13: v16,
      a14: v17);
  v11 = *value;
  HIDWORD(v11) = this->elements_;
  *(_QWORD *)(8 * this->current_size_++ + HIDWORD(v11)) = v11;
}


// ========================================================================
// ?MergeFrom@?$RepeatedField@_K@protobuf@google@@QAAXABV123@@Z
// EA  : 0x82F57338
// RVA : 0x00F57338
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::RepeatedField<unsigned __int64>::MergeFrom(
        google::protobuf::RepeatedField<unsigned __int64> *this,
        const google::protobuf::RepeatedField<unsigned __int64> *other,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]
  int v13; // [sp+18h] [-58h]
  int v14; // [sp+1Ch] [-54h]

  google::protobuf::RepeatedField<unsigned __int64>::Reserve(
    this,
    new_size: this->current_size_ + other->current_size_,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8: this->current_size_,
    a9: v9,
    a10: v10,
    a11: v11,
    a12: v12,
    a13: v13,
    a14: v14);
  memcpy(Dst: &this->elements_[this->current_size_], Src: other->elements_, Size: 8 * other->current_size_);
  this->current_size_ += other->current_size_;
}


// ========================================================================
// ??1?$RepeatedPtrField@VBigUInt@idreports@@@protobuf@google@@QAA@XZ
// EA  : 0x82F573B0
// RVA : 0x00F573B0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

// attributes: thunk
void __fastcall google::protobuf::RepeatedPtrField<idreports::BigUInt>::~RepeatedPtrField<idreports::BigUInt>(
        google::protobuf::RepeatedPtrField<idreports::SPURegisterInfo> *this)
{
  google::protobuf::internal::RepeatedPtrFieldBase::Destroy<google::protobuf::RepeatedPtrField<idreports::MapWarning>::TypeHandler>(this);
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VAttachment@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVAttachment@idreports@@XZ
// EA  : 0x82F57700
// RVA : 0x00F57700
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::Attachment *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::Attachment>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::Attachment *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = idreports::Attachment::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::Attachment *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VHeapCategoryUsage@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVHeapCategoryUsage@idreports@@XZ
// EA  : 0x82F577A8
// RVA : 0x00F577A8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::HeapCategoryUsage *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::HeapCategoryUsage>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::HeapCategoryUsage *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = google::protobuf::internal::GenericTypeHandler<idreports::HeapCategoryUsage>::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::HeapCategoryUsage *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VBigUInt@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVBigUInt@idreports@@XZ
// EA  : 0x82F57850
// RVA : 0x00F57850
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::BigUInt *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::BigUInt>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::BigUInt *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = idreports::BigUInt::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::BigUInt *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VBigUInt@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F578F8
// RVA : 0x00F578F8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::BigUInt>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::BigUInt *v6; // r27
  idreports::BigUInt *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::BigUInt *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::BigUInt>::TypeHandler>(this);
    idreports::BigUInt::MergeFrom(this: v7, from: v6);
    ++i;
  }
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VPS3VMRegionStats@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVPS3VMRegionStats@idreports@@XZ
// EA  : 0x82F57968
// RVA : 0x00F57968
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::PS3VMRegionStats *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::PS3VMRegionStats>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::PS3VMRegionStats *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = google::protobuf::internal::GenericTypeHandler<idreports::PS3VMRegionStats>::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::PS3VMRegionStats *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VCallstackLine@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVCallstackLine@idreports@@XZ
// EA  : 0x82F57A10
// RVA : 0x00F57A10
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::CallstackLine *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::CallstackLine>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::CallstackLine *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = google::protobuf::internal::GenericTypeHandler<idreports::CallstackLine>::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::CallstackLine *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$Add@VTypeHandler@?$RepeatedPtrField@VSPURegisterInfo@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAPAVSPURegisterInfo@idreports@@XZ
// EA  : 0x82F69C08
// RVA : 0x00F69C08
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

idreports::SPURegisterInfo *__fastcall google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::SPURegisterInfo>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this)
{
  int allocated_size; // r10
  int current_size; // r11
  idreports::SPURegisterInfo *result; // r3
  int total_size; // r11

  allocated_size = this->allocated_size_;
  current_size = this->current_size_;
  if ( current_size >= allocated_size )
  {
    total_size = this->total_size_;
    if ( allocated_size == total_size )
      google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: total_size + 1);
    ++this->allocated_size_;
    result = idreports::SPURegisterInfo::New();
    this->elements_[this->current_size_++] = result;
  }
  else
  {
    result = (idreports::SPURegisterInfo *)this->elements_[current_size];
    this->current_size_ = current_size + 1;
  }
  return result;
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VSPURegisterInfo@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F6E4E0
// RVA : 0x00F6E4E0
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::SPURegisterInfo>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::SPURegisterInfo *v6; // r27
  idreports::SPURegisterInfo *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::SPURegisterInfo *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::SPURegisterInfo>::TypeHandler>(this);
    idreports::SPURegisterInfo::MergeFrom(this: v7, from: v6);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F77210
// RVA : 0x00F77210
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const std::string *v6; // r26
  std::string *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const std::string *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<std::string>::TypeHandler>(this);
    std::string::assign(this: v7, _Right: v6, _Roff: 0, _Count: 0xFFFFFFFF);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VAttachment@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F77288
// RVA : 0x00F77288
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::Attachment>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::Attachment *v6; // r27
  idreports::Attachment *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::Attachment *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::Attachment>::TypeHandler>(this);
    idreports::Attachment::MergeFrom(this: v7, from: v6);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VMapWarning@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F772F8
// RVA : 0x00F772F8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::MapWarning>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::MapWarning *v6; // r27
  idreports::MapWarning *v7; // r3
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::MapWarning *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::MapWarning>::TypeHandler>(this);
    idreports::MapWarning::MergeFrom(this: v7, from: v6, a3: v12, a4: v11, a5: v10, a6: v9, a7: v8);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VHeapCategoryUsage@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F77368
// RVA : 0x00F77368
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::HeapCategoryUsage>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::HeapCategoryUsage *v6; // r27
  idreports::HeapCategoryUsage *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::HeapCategoryUsage *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::HeapCategoryUsage>::TypeHandler>(this);
    idreports::HeapCategoryUsage::MergeFrom(this: v7, from: v6);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VPS3VMRegionStats@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F773D8
// RVA : 0x00F773D8
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::PS3VMRegionStats>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::PS3VMRegionStats *v6; // r27
  idreports::PS3VMRegionStats *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::PS3VMRegionStats *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::PS3VMRegionStats>::TypeHandler>(this);
    idreports::PS3VMRegionStats::MergeFrom(this: v7, from: v6);
    ++i;
  }
}


// ========================================================================
// ??$MergeFrom@VTypeHandler@?$RepeatedPtrField@VCallstackLine@idreports@@@protobuf@google@@@RepeatedPtrFieldBase@internal@protobuf@google@@IAAXABV0123@@Z
// EA  : 0x82F77448
// RVA : 0x00F77448
// PDB : w:\tech5\libs\protobuf-2.4.1\src\google\protobuf\repeated_field.h
// ========================================================================

void __fastcall google::protobuf::internal::RepeatedPtrFieldBase::MergeFrom<google::protobuf::RepeatedPtrField<idreports::CallstackLine>::TypeHandler>(
        google::protobuf::internal::RepeatedPtrFieldBase *this,
        const google::protobuf::internal::RepeatedPtrFieldBase *other)
{
  int v4; // r29
  int i; // r30
  const idreports::CallstackLine *v6; // r27
  idreports::CallstackLine *v7; // r3

  v4 = 0;
  google::protobuf::internal::RepeatedPtrFieldBase::Reserve(this, new_size: this->current_size_ + other->current_size_);
  for ( i = 0; i < other->current_size_; ++v4 )
  {
    v6 = (const idreports::CallstackLine *)other->elements_[v4];
    v7 = google::protobuf::internal::RepeatedPtrFieldBase::Add<google::protobuf::RepeatedPtrField<idreports::CallstackLine>::TypeHandler>(this);
    idreports::CallstackLine::MergeFrom(this: v7, from: v6);
    ++i;
  }
}

