
// ========================================================================
// ??1idImageData@@QAA@XZ
// EA  : 0x827DAA80
// RVA : 0x007DAA80
// PDB : w:\tech5\engine\renderer\imagedata.h
// ========================================================================

void __fastcall idImageData::~idImageData(idImageData *this)
{
  unsigned __int8 *data; // r4
  float *floatData; // r4

  data = this->data;
  if ( data != nullptr )
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
  floatData = this->floatData;
  if ( floatData != nullptr )
    idMem::Free(this: &mem, ptr: floatData, align: ALIGN_16);
}


// ========================================================================
// ??0idImageData@@QAA@HH@Z
// EA  : 0x828C2CC0
// RVA : 0x008C2CC0
// PDB : w:\tech5\engine\renderer\imagedata.h
// ========================================================================

idImageData *__fastcall idImageData::idImageData(idImageData *this, int w, int h)
{
  this->width = w;
  this->height = h;
  this->data = (unsigned __int8 *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\renderer\\ImageData.h(18) : TAG_IMAGE",
                                    size: 4 * w * h,
                                    tag: TAG_IMAGE,
                                    zeroBuffer: true,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  this->floatData = nullptr;
  return this;
}

