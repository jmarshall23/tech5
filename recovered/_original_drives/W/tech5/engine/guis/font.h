
// ========================================================================
// ?GetResourceList@idFont@@UBAPAVidResourceList@@XZ
// EA  : 0x8276CEC0
// RVA : 0x0076CEC0
// PDB : w:\tech5\engine\guis\font.h
// ========================================================================

idTypedResourceList<idFont> *__fastcall idFont::GetResourceList(idFont *this)
{
  return &idFont::resourceList;
}


// ========================================================================
// ??1idFont@@UAA@XZ
// EA  : 0x8276CFA0
// RVA : 0x0076CFA0
// PDB : w:\tech5\engine\guis\font.h
// ========================================================================

void __fastcall idFont::~idFont(idFont *this)
{
  fontInfo_t *fontInfo; // r30

  this->__vftable = (idFont_vtbl *)&idFont::`vftable';
  fontInfo = this->fontInfo;
  if ( fontInfo != nullptr )
  {
    idMem::Free(this: &mem, ptr: fontInfo->glyphData, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: fontInfo->charIndex, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: fontInfo, align: ALIGN_16);
  }
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$220878
// EA  : 0x8276D018
// RVA : 0x0076D018
// PDB : w:\tech5\engine\guis\font.h
// ========================================================================

void _unwind_220878()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}

