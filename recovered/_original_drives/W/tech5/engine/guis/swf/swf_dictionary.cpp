
// ========================================================================
// ??4idSWFDictionaryEntry@@QAAAAV0@AAV0@@Z
// EA  : 0x8276EF98
// RVA : 0x0076EF98
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

idSWFDictionaryEntry *__fastcall idSWFDictionaryEntry::operator=(
        idSWFDictionaryEntry *this,
        idSWFDictionaryEntry *other)
{
  this->type = other->type;
  this->material = other->material;
  this->shape = other->shape;
  this->sprite = other->sprite;
  this->font = other->font;
  this->text = other->text;
  this->edittext = other->edittext;
  this->imageSize = other->imageSize;
  this->imageAtlasOffset = other->imageAtlasOffset;
  other->type = SWF_DICT_NULL;
  other->material = nullptr;
  other->shape = nullptr;
  other->sprite = nullptr;
  other->font = nullptr;
  other->text = nullptr;
  other->edittext = nullptr;
  return this;
}


// ========================================================================
// ??0idSWFDictionaryEntry@@QAA@XZ
// EA  : 0x8276F018
// RVA : 0x0076F018
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

idSWFDictionaryEntry *__fastcall idSWFDictionaryEntry::idSWFDictionaryEntry(idSWFDictionaryEntry *this)
{
  this->type = SWF_DICT_NULL;
  this->material = nullptr;
  this->shape = nullptr;
  this->sprite = nullptr;
  this->font = nullptr;
  this->text = nullptr;
  this->edittext = nullptr;
  this->imageSize.x = 0;
  this->imageSize.y = 0;
  this->imageAtlasOffset.x = 0;
  this->imageAtlasOffset.y = 0;
  this->channelScale.x = 1.0;
  this->channelScale.y = 1.0;
  this->channelScale.z = 1.0;
  this->channelScale.w = 1.0;
  return this;
}


// ========================================================================
// ?FindDictionaryEntry@idSWF@@QAAPAVidSWFDictionaryEntry@@HW4swfDictType_t@@@Z
// EA  : 0x8276F068
// RVA : 0x0076F068
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

idSWFDictionaryEntry *__fastcall idSWF::FindDictionaryEntry(idSWF *this, int characterID, swfDictType_t type)
{
  idSWFDictionaryEntry *result; // r3

  if ( this->dictionary.num >= characterID + 1 )
  {
    result = &this->dictionary.list[characterID];
    if ( result->type == type )
      return result;
    idLib::Warning(fmt: "%s: Character %d is the wrong type", this->filename.str, characterID);
  }
  else
  {
    idLib::Warning(fmt: "%s: Could not find character %d", this->filename.str, characterID);
  }
  return nullptr;
}


// ========================================================================
// ?FindDictionaryEntry@idSWF@@QAAPAVidSWFDictionaryEntry@@H@Z
// EA  : 0x8276F0D8
// RVA : 0x0076F0D8
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

idSWFDictionaryEntry *__fastcall idSWF::FindDictionaryEntry(idSWF *this, int characterID)
{
  if ( this->dictionary.num >= characterID + 1 )
    return &this->dictionary.list[characterID];
  idLib::Warning(fmt: "%s: Could not find character %d", this->filename.str, characterID);
  return nullptr;
}


// ========================================================================
// ??1idSWFDictionaryEntry@@QAA@XZ
// EA  : 0x8276F568
// RVA : 0x0076F568
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

void __fastcall idSWFDictionaryEntry::~idSWFDictionaryEntry(idSWFDictionaryEntry *this)
{
  idSWFShape *shape; // r31
  idSWFSprite *sprite; // r31
  idSWFFont *font; // r31
  char *list; // r3
  idSWFText *text; // r31

  shape = this->shape;
  if ( shape != nullptr )
  {
    idSWFShape::~idSWFShape(this: this->shape);
    idMem::Free(this: &mem, ptr: shape, align: ALIGN_16);
  }
  sprite = this->sprite;
  if ( sprite != nullptr )
  {
    idSWFSprite::~idSWFSprite(this: this->sprite);
    idMem::Free(this: &mem, ptr: sprite, align: ALIGN_16);
  }
  font = this->font;
  if ( font != nullptr )
  {
    if ( font->glyphs.listStatic == 0 || font->glyphs.listStatic == 2 )
    {
      list = (char *)font->glyphs.list;
      if ( list != nullptr )
        idListArrayDelete<idSWFFontGlyph>(ptr: list, num: font->glyphs.size);
      font->glyphs.list = nullptr;
      font->glyphs.size = 0;
    }
    font->glyphs.num = 0;
    idMem::Free(this: &mem, ptr: font, align: ALIGN_16);
  }
  text = this->text;
  if ( text != nullptr )
  {
    idSWFText::~idSWFText(this: this->text);
    idMem::Free(this: &mem, ptr: text, align: ALIGN_16);
  }
  idMem::Free(this: &mem, ptr: this->edittext, align: ALIGN_16);
}


// ========================================================================
// ?AddDictionaryEntry@idSWF@@QAAPAVidSWFDictionaryEntry@@HW4swfDictType_t@@@Z
// EA  : 0x8276F790
// RVA : 0x0076F790
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

idSWFDictionaryEntry *__fastcall idSWF::AddDictionaryEntry(idSWF *this, int characterID, swfDictType_t type)
{
  int v3; // r30
  idList<idSWFDictionaryEntry,72> *p_dictionary; // r29
  idSWFDictionaryEntry *list; // r11
  int v9; // r30
  idSWFSprite *v11; // r3
  idSWFSprite *v12; // r3
  idSWFFont *v13; // r3
  idSWFText *v14; // r3
  idSWFText *v15; // r3
  idSWFEditText *v16; // r3
  idSWFShape *v17; // r3
  idSWFShape *v18; // r3

  v3 = characterID + 1;
  if ( this->dictionary.num < characterID + 1 )
  {
    p_dictionary = &this->dictionary;
    if ( v3 > this->dictionary.size )
      idList<idSWFDictionaryEntry,72>::Resize(this: &this->dictionary, newsize: characterID + 1);
    idList<idSWFDictionaryEntry,72>::SetNum(this: p_dictionary, newNum: v3);
  }
  list = this->dictionary.list;
  v9 = characterID;
  if ( list[characterID].type != SWF_DICT_NULL )
  {
    idLib::Warning(fmt: "%s: Duplicate character %d", this->filename.str, characterID);
    return nullptr;
  }
  else
  {
    list[v9].type = type;
    switch ( type )
    {
      case SWF_DICT_SHAPE:
      case SWF_DICT_MORPH:
        v17 = (idSWFShape *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x40u,
                              tag: TAG_SWF,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        if ( v17 != nullptr )
          v18 = idSWFShape::idSWFShape(this: v17);
        else
          v18 = nullptr;
        this->dictionary.list[v9].shape = v18;
        break;
      case SWF_DICT_SPRITE:
        v11 = (idSWFSprite *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x4Cu,
                               tag: TAG_SWF,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
          v12 = idSWFSprite::idSWFSprite(this: v11, _swf: this);
        else
          v12 = nullptr;
        this->dictionary.list[v9].sprite = v12;
        break;
      case SWF_DICT_FONT:
        v13 = (idSWFFont *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x1Cu,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
        if ( v13 != nullptr )
        {
          v13->fontID = nullptr;
          v13->ascent = 0;
          v13->descent = 0;
          v13->leading = 0;
          v13->glyphs.granularity = 0;
          v13->glyphs.memTag = 72;
          v13->glyphs.listStatic = 0;
          v13->glyphs.list = nullptr;
          v13->glyphs.size = 0;
          v13->glyphs.num = 0;
        }
        else
        {
          v13 = nullptr;
        }
        this->dictionary.list[v9].font = v13;
        break;
      case SWF_DICT_TEXT:
        v14 = (idSWFText *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x48u,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
        if ( v14 != nullptr )
          v15 = idSWFText::idSWFText(this: v14);
        else
          v15 = nullptr;
        this->dictionary.list[v9].text = v15;
        break;
      case SWF_DICT_EDITTEXT:
        v16 = (idSWFEditText *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x34u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        if ( v16 != nullptr )
        {
          v16->bounds.tl.x = 0.0;
          v16->bounds.tl.y = 0.0;
          v16->bounds.br.x = 0.0;
          v16->bounds.br.y = 0.0;
          v16->flags = 0;
          *(_DWORD *)&v16->fontID = 24;
          v16->color.r = -1;
          v16->color.g = -1;
          v16->color.b = -1;
          v16->color.a = -1;
          v16->align = SWF_ET_ALIGN_LEFT;
          v16->leftMargin = 0;
          v16->rightMargin = 0;
          v16->indent = 0;
          v16->leading = 0;
          v16->maxLength = -1;
          v16->variable.str = &byte_8200D768;
          v16->initialText.str = &byte_8200D768;
          this->dictionary.list[v9].edittext = v16;
        }
        else
        {
          this->dictionary.list[v9].edittext = nullptr;
        }
        break;
      default:
        break;
    }
    return &this->dictionary.list[v9];
  }
}


// ========================================================================
// __unwind$220748
// EA  : 0x8276FAA0
// RVA : 0x0076FAA0
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

void _unwind_220748()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$220749
// EA  : 0x8276FACC
// RVA : 0x0076FACC
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

void _unwind_220749()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$220750
// EA  : 0x8276FAF8
// RVA : 0x0076FAF8
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

void _unwind_220750()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$220747
// EA  : 0x8276FB24
// RVA : 0x0076FB24
// PDB : w:\tech5\engine\guis\swf\swf_dictionary.cpp
// ========================================================================

void _unwind_220747()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}

