
// ========================================================================
// ?AllocateGlyphs@fontInfo_t@@QAAXH@Z
// EA  : 0x8276CB30
// RVA : 0x0076CB30
// PDB : w:\tech5\shared\guis\fontinfo.h
// ========================================================================

void __fastcall fontInfo_t::AllocateGlyphs(fontInfo_t *this, int num)
{
  idMem::Free(this: &mem, ptr: this->glyphData, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->charIndex, align: ALIGN_16);
  this->numGlyphs = num;
  this->charIndex = (unsigned int *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\guis\\../../shared/guis/FontInfo.h(60) : TAG_FONTS",
                                      size: 4 * num,
                                      tag: TAG_FONTS,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  this->glyphData = (glyphInfo_t *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\engine\\guis\\../../shared/guis/FontInfo.h(61) : TAG_FONTS",
                                     size: 10 * num,
                                     tag: TAG_FONTS,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
}

