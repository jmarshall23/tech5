
// ========================================================================
// ??2@YAPAXI@Z
// EA  : 0x824E00A8
// RVA : 0x004E00A8
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

void *__fastcall operator new(unsigned int s)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
           size: s,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ??0?$idTempArray@H@@QAA@I@Z
// EA  : 0x825C7150
// RVA : 0x005C7150
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<int> *__fastcall idTempArray<int>::idTempArray<int>(idTempArray<int> *this, unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (int *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                          size: 4 * num,
                          tag: TAG_TEMP,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@G@@QAA@I@Z
// EA  : 0x825F6718
// RVA : 0x005F6718
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<unsigned short> *__fastcall idTempArray<unsigned short>::idTempArray<unsigned short>(
        idTempArray<unsigned short> *this,
        unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (unsigned __int16 *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                       size: 2 * num,
                                       tag: TAG_TEMP,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??1?$idTempArray@VidPlane@@@@QAA@XZ
// EA  : 0x8260ACD0
// RVA : 0x0060ACD0
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

void __fastcall idTempArray<idPlane>::~idTempArray<idPlane>(idTempArray<int> *this)
{
  if ( this->buffer != nullptr )
    idMem::Free(this: &mem, ptr: this->buffer, align: ALIGN_16);
}


// ========================================================================
// ??_U@YAPAXI@Z
// EA  : 0x826305F8
// RVA : 0x006305F8
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

void *__fastcall operator new[](unsigned int s)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
           size: s,
           tag: TAG_NEW,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ??3@YAXPAX@Z
// EA  : 0x82636570
// RVA : 0x00636570
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

void __fastcall operator delete(void *p, memTag_t tag)
{
  idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
}


// ========================================================================
// ??0?$idTempArray@D@@QAA@I@Z
// EA  : 0x8267AE90
// RVA : 0x0067AE90
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<char> *__fastcall idTempArray<char>::idTempArray<char>(idTempArray<char> *this, unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (char *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                           size: num,
                           tag: TAG_TEMP,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@UtangentVert_t@@@@QAA@I@Z
// EA  : 0x82875DD8
// RVA : 0x00875DD8
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<tangentVert_t> *__fastcall idTempArray<tangentVert_t>::idTempArray<tangentVert_t>(
        idTempArray<tangentVert_t> *this,
        unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (tangentVert_t *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                    size: 8 * num,
                                    tag: TAG_TEMP,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@Ubin_t@@@@QAA@I@Z
// EA  : 0x8288C8B0
// RVA : 0x0088C8B0
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<bin_t> *__fastcall idTempArray<bin_t>::idTempArray<bin_t>(idTempArray<bin_t> *this, unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (bin_t *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                            size: num << 8,
                            tag: TAG_TEMP,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@Unode_t@@@@QAA@I@Z
// EA  : 0x8288C918
// RVA : 0x0088C918
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<node_t> *__fastcall idTempArray<node_t>::idTempArray<node_t>(idTempArray<node_t> *this, unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (node_t *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: 20 * num,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@VidTransparencyVert@@@@QAA@I@Z
// EA  : 0x8288C988
// RVA : 0x0088C988
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<idTransparencyVert> *__fastcall idTempArray<idTransparencyVert>::idTempArray<idTransparencyVert>(
        idTempArray<idTransparencyVert> *this,
        unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (idTransparencyVert *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                         size: 32 * num,
                                         tag: TAG_TEMP,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??0?$idTempArray@UvertexTangents_t@@@@QAA@I@Z
// EA  : 0x829730E0
// RVA : 0x009730E0
// PDB : w:\tech5\shared\idlib\heap.h
// ========================================================================

idTempArray<vertexTangents_t> *__fastcall idTempArray<vertexTangents_t>::idTempArray<vertexTangents_t>(
        idTempArray<vertexTangents_t> *this,
        unsigned int num)
{
  this->num = num;
  this->buffer = nullptr;
  this->buffer = (vertexTangents_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                       size: 36 * num,
                                       tag: TAG_TEMP,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  return this;
}

