
// ========================================================================
// ?AddEntry@VertexCache@@QAAHH@Z
// EA  : 0x828B3FC8
// RVA : 0x008B3FC8
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.h
// ========================================================================

int __fastcall VertexCache::AddEntry(VertexCache *this, int entry)
{
  int numEntries; // r11
  int v4; // r11
  int result; // r3
  int v6; // r11
  int v7; // ctr
  int *v8; // r9

  numEntries = this->numEntries;
  result = this->entries[numEntries - 1];
  v4 = numEntries - 2;
  if ( v4 >= 0 )
  {
    v7 = v4 + 1;
    v6 = v4;
    do
    {
      v8 = &this->entries[v6--];
      v8[1] = *v8;
      --v7;
    }
    while ( v7 != 0 );
  }
  *this->entries = entry;
  return result;
}


// ========================================================================
// ?IsInStrip@NvStripInfo@@QBA_NPBVNvFaceInfo@@@Z
// EA  : 0x828B4018
// RVA : 0x008B4018
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.h
// ========================================================================

BOOL __fastcall NvStripInfo::IsInStrip(NvStripInfo *this, const NvFaceInfo *faceInfo)
{
  int m_stripId; // r10
  unsigned int v4; // r9

  if ( faceInfo == nullptr )
    return false;
  m_stripId = this->m_stripId;
  if ( this->m_experimentId < 0 )
    v4 = m_stripId - faceInfo->m_stripId;
  else
    v4 = m_stripId - faceInfo->m_testStripId;
  return (_cntlzw(v4) & 0x20) != 0;
}


// ========================================================================
// ??0VertexCache@@QAA@H@Z
// EA  : 0x828B4528
// RVA : 0x008B4528
// PDB : w:\tech5\engine\renderer\development\nvtristripobjects.h
// ========================================================================

VertexCache *__fastcall VertexCache::VertexCache(VertexCache *this, unsigned int size)
{
  unsigned int v3; // r5
  int *v4; // r3
  int numEntries; // r9
  int v6; // r11
  int v7; // r10

  this->numEntries = size;
  v3 = 4 * size;
  if ( size > 0x3FFFFFFF )
    v3 = -1;
  v4 = (int *)idMem::AllocWithLocation(
                this: &mem,
                location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                size: v3,
                tag: TAG_NEW,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
  numEntries = this->numEntries;
  this->entries = v4;
  v6 = 0;
  if ( numEntries > 0 )
  {
    v7 = 0;
    do
    {
      ++v6;
      this->entries[v7++] = -1;
    }
    while ( v6 < this->numEntries );
  }
  return this;
}

