
// ========================================================================
// ??1idBitArray@@QAA@XZ
// EA  : 0x825D4068
// RVA : 0x005D4068
// PDB : w:\tech5\shared\idlib\containers\bitarray.h
// ========================================================================

void __fastcall idBitArray::~idBitArray(idBitArray *this)
{
  if ( this->buffer != nullptr && this->free )
  {
    idMem::Free(this: &mem, ptr: this->buffer, align: ALIGN_16);
    this->buffer = nullptr;
    this->bits = 0;
    this->free = false;
  }
}


// ========================================================================
// ?Alloc@idBitArray@@QAAXI@Z
// EA  : 0x825D5608
// RVA : 0x005D5608
// PDB : w:\tech5\shared\idlib\containers\bitarray.h
// ========================================================================

void __fastcall idBitArray::Alloc(idBitArray *this, unsigned int numBits)
{
  unsigned int v4; // r30
  bool v5; // zf
  unsigned __int8 *v6; // r3

  if ( this->buffer != nullptr && this->free )
  {
    idMem::Free(this: &mem, ptr: this->buffer, align: ALIGN_16);
    this->buffer = nullptr;
    this->bits = 0;
    this->free = false;
  }
  this->bits = numBits;
  this->free = true;
  v5 = (numBits & 7) == 0;
  v4 = numBits >> 3;
  if ( !v5 )
    ++v4;
  v6 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\containers/BitArray.h(107) : static_cast< memTag_t >( memTag )",
                            size: v4,
                            tag: (memTag_t)this->memTag,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->buffer = v6;
  memset(Dst: v6, Val: 0, Size: v4);
}


// ========================================================================
// ?Set@idBitArray@@QAAXI@Z
// EA  : 0x825D56B8
// RVA : 0x005D56B8
// PDB : w:\tech5\shared\idlib\containers\bitarray.h
// ========================================================================

void __fastcall idBitArray::Set(idBitArray *this, unsigned int bitNum)
{
  char v2; // r9
  unsigned __int8 *v3; // r11
  char v4; // r10

  if ( bitNum >= this->bits )
  {
    v3 = nullptr;
    v4 = 0;
    v2 = 0;
  }
  else
  {
    v2 = 1;
    v3 = &this->buffer[bitNum >> 3];
    v4 = 1 << (bitNum & 7);
  }
  if ( v2 != 0 )
    *v3 |= v4;
}


// ========================================================================
// ?Get@idBitArray@@QBA_NI@Z
// EA  : 0x825D5710
// RVA : 0x005D5710
// PDB : w:\tech5\shared\idlib\containers\bitarray.h
// ========================================================================

BOOL __fastcall idBitArray::Get(idBitArray *this, unsigned int bitNum)
{
  char v2; // r9
  unsigned __int8 *v3; // r11
  char v4; // r10

  if ( bitNum >= this->bits )
  {
    v3 = nullptr;
    v4 = 0;
    v2 = 0;
  }
  else
  {
    v2 = 1;
    v3 = &this->buffer[bitNum >> 3];
    v4 = 1 << (bitNum & 7);
  }
  return v2 != 0 && (unsigned __int8)(*v3 & v4) != 0;
}


// ========================================================================
// ??0idBitArray@@QAA@PAEIW4memTag_t@@@Z
// EA  : 0x826AF2D8
// RVA : 0x006AF2D8
// PDB : w:\tech5\shared\idlib\containers\bitarray.h
// ========================================================================

idBitArray *__fastcall idBitArray::idBitArray(
        idBitArray *this,
        unsigned __int8 *buff,
        unsigned int bits,
        const memTag_t _memTag)
{
  unsigned int v5; // r5
  bool v6; // zf

  this->buffer = buff;
  this->bits = bits;
  this->memTag = _memTag;
  this->free = false;
  if ( buff != nullptr )
  {
    v6 = (bits & 7) == 0;
    v5 = bits >> 3;
    if ( !v6 )
      ++v5;
    memset(Dst: buff, Val: 0, Size: v5);
  }
  return this;
}

