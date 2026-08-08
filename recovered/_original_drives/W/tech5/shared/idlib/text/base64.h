
// ========================================================================
// ?EnsureAlloced@idBase64@@AAAXH@Z
// EA  : 0x829A32B0
// RVA : 0x009A32B0
// PDB : w:\tech5\shared\idlib\text\base64.h
// ========================================================================

void __fastcall idBase64::EnsureAlloced(idBase64 *this, int size)
{
  if ( size > this->alloced )
  {
    if ( this->data != nullptr )
      idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
    this->len = 0;
    this->alloced = 0;
    this->data = nullptr;
  }
  this->data = (unsigned __int8 *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                    size,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  this->alloced = size;
}


// ========================================================================
// ??4idBase64@@QAAXABVidStr@@@Z
// EA  : 0x829A3338
// RVA : 0x009A3338
// PDB : w:\tech5\shared\idlib\text\base64.h
// ========================================================================

void __fastcall idBase64::operator=(idBase64 *this, const idStr *s)
{
  char *v4; // r11
  unsigned __int8 *v5; // r10
  char v6; // r9

  idBase64::EnsureAlloced(this, size: s->len + 1);
  v4 = s->data - 1;
  v5 = this->data - 1;
  do
  {
    v6 = *++v4;
    *++v5 = *v4;
  }
  while ( v6 != 0 );
  this->len = s->len;
}


// ========================================================================
// ??1idBase64@@QAA@XZ
// EA  : 0x829A3620
// RVA : 0x009A3620
// PDB : w:\tech5\shared\idlib\text\base64.h
// ========================================================================

void __fastcall idBase64::~idBase64(idBase64 *this)
{
  if ( this->data != nullptr )
    idMem::Free(this: &mem, ptr: this->data, align: ALIGN_16);
  this->len = 0;
  this->alloced = 0;
  this->data = nullptr;
}

