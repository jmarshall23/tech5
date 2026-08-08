
// ========================================================================
// ??0idXMLReader@@QAA@PBD@Z
// EA  : 0x82FA4570
// RVA : 0x00FA4570
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

idXMLReader *__fastcall idXMLReader::idXMLReader(idXMLReader *this, const char *relativePath)
{
  __int64 v4; // r10
  __int64 v5; // r8
  unsigned int v6; // r6

  idLexer::idLexer(this: &this->lexer, flags_: 0);
  idLexer::LoadFile(this: &this->lexer, filename_: relativePath, OSPath: v6, a4: v5, a5: v4);
  return this;
}


// ========================================================================
// __unwind$111524
// EA  : 0x82FA45B0
// RVA : 0x00FA45B0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_111524()
{
  int v0; // r12

  idLexer::~idLexer(this: *(idLexer **)(v0 - 112 + 132));
}


// ========================================================================
// ?ReadAttributes@idXMLReader@@AAA_NPAVidXMLElement@@@Z
// EA  : 0x82FA45E0
// RVA : 0x00FA45E0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

int __fastcall idXMLReader::ReadAttributes(idXMLReader *this, idXMLElement *owner)
{
  __int64 v2; // r8
  __int64 v5; // r6
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r6
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  char *data; // r29
  __int64 v17; // r6
  __int64 v18; // r8
  idToken v20; // [sp+50h] [-160h] BYREF
  idToken v21; // [sp+A0h] [-110h] BYREF
  idToken v22; // [sp+F0h] [-C0h] BYREF
  idXMLAttribute v23; // [sp+140h] [-70h] BYREF

  LODWORD(v2) = v22.baseBuffer;
  v22.len = 0;
  v22.allocedAndFlag = 20;
  v22.floatvalue = -3.4028235e38;
  v22.data = v22.baseBuffer;
  v22.baseBuffer[0] = 0;
  v22.intvalue = 0;
  memset(&v22.whiteSpaceStart_p, 0, 12);
  HIDWORD(v2) = v21.baseBuffer;
  v21.floatvalue = -3.4028235e38;
  v21.allocedAndFlag = 20;
  v21.data = v21.baseBuffer;
  v21.len = 0;
  v21.baseBuffer[0] = 0;
  v21.intvalue = 0;
  memset(&v21.whiteSpaceStart_p, 0, 12);
  v20.floatvalue = -3.4028235e38;
  v20.allocedAndFlag = 20;
  v20.data = v20.baseBuffer;
  v20.len = 0;
  v20.baseBuffer[0] = 0;
  v20.intvalue = 0;
  memset(&v20.whiteSpaceStart_p, 0, 12);
  LODWORD(v5) = &v20;
  HIDWORD(v5) = 28;
  if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v5, a4: v2) != 0 )
  {
LABEL_6:
    idStr::FreeData(this: &v20);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v22);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      LODWORD(v7) = &v20;
      HIDWORD(v7) = 38;
      if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v7, a4: v6) != 0 )
        break;
      idLexer::ReadToken(this: &this->lexer, token: &v22, a3: v10, a4: v9, a5: v8);
      LODWORD(v11) = &v20;
      HIDWORD(v11) = 32;
      idLexer::ExpectTokenType(this: &this->lexer, type: 5, token: v11, a4: v12);
      idLexer::ReadToken(this: &this->lexer, token: &v21, a3: v15, a4: v14, a5: v13);
      data = v21.data;
      idStr::idStr(this: &v23.name, text: v22.data);
      idStr::idStr(this: &v23.value, text: data);
      idStr::StripLeadingWhiteSpace(this: &v23.name);
      idStr::StripTrailingWhitespace(this: &v23.name);
      if ( idList<idXMLAttribute,44>::FindIndex(this: &owner->attributes, obj: &v23, startIndex: 0) < 0 )
        idList<idXMLAttribute,44>::Append(this: &owner->attributes, obj: (const idTarget_Cvar::keyVal_t *)&v23);
      idStr::FreeData(this: &v23.value);
      idStr::FreeData(this: &v23.name);
      LODWORD(v17) = &v20;
      HIDWORD(v17) = 28;
      if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v17, a4: v18) != 0 )
        goto LABEL_6;
    }
    idLexer::ReadToken(this: &this->lexer, token: &v20, a3: v10, a4: v9, a5: v8);
    idStr::FreeData(this: &v20);
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v22);
    return 0;
  }
}


// ========================================================================
// __unwind$111867
// EA  : 0x82FA47BC
// RVA : 0x00FA47BC
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_111867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 240));
}


// ========================================================================
// __unwind$111868
// EA  : 0x82FA47E4
// RVA : 0x00FA47E4
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_111868()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$111869
// EA  : 0x82FA480C
// RVA : 0x00FA480C
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_111869()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$112033
// EA  : 0x82FA4834
// RVA : 0x00FA4834
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 320));
}


// ========================================================================
// __unwind$112034
// EA  : 0x82FA485C
// RVA : 0x00FA485C
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 352));
}


// ========================================================================
// __unwind$111870
// EA  : 0x82FA4888
// RVA : 0x00FA4888
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_111870()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 432 + 320));
}


// ========================================================================
// __unwind$112051
// EA  : 0x82FA48B0
// RVA : 0x00FA48B0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112051()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 320));
}


// ========================================================================
// ?ReadElement_R@idXMLReader@@AAAPAVidXMLElement@@XZ
// EA  : 0x82FA48E0
// RVA : 0x00FA48E0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

idXMLElement *__fastcall idXMLReader::ReadElement_R(idXMLReader *this, int a2, __int64 a3, __int64 a4)
{
  idXMLElement *v4; // r29
  __int64 v6; // r6
  __int64 v7; // r8
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v15; // r8
  idXMLElement *v16; // r3
  __int64 v17; // r6
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idXMLElement *v23; // r4
  idXMLReader *v24; // r3
  idToken v25; // [sp+60h] [-70h] BYREF

  v4 = nullptr;
  v25.len = 0;
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  v25.floatvalue = -3.4028235e38;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  idLexer::SkipUntilString(this: &this->lexer, string: "<", a3, a4);
  LODWORD(v6) = &v25;
  HIDWORD(v6) = 43;
  LODWORD(v8) = (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v6, a4: v7);
  if ( (_DWORD)v8 != 0 )
    idLexer::SkipUntilString(this: &this->lexer, string: "<", a3: v9, a4: v8);
  LODWORD(v10) = &v25;
  HIDWORD(v10) = 28;
  if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v10, a4: v8) != 0 )
  {
    idStr::FreeData(this: &v25);
    return nullptr;
  }
  idLexer::ReadToken(this: &this->lexer, token: &v25, a3: v13, a4: v12, a5: v11);
  v16 = (idXMLElement *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x60u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v16 != nullptr )
    v4 = idXMLElement::idXMLElement(this: v16, name: v25.data);
  LODWORD(v17) = &v25;
  HIDWORD(v17) = 28;
  if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v17, a4: v15) == 0 )
  {
    LODWORD(v19) = &v25;
    HIDWORD(v19) = 38;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v19, a4: v18) != 0 )
    {
      idLexer::ReadToken(this: &this->lexer, token: &v25, a3: v22, a4: v21, a5: v20);
      v23 = v4;
      v24 = this;
LABEL_12:
      idXMLReader::ReadElementContents(this: v24, element: v23);
      goto LABEL_13;
    }
    if ( (unsigned __int8)idXMLReader::ReadAttributes(this, owner: v4) == 0 )
    {
      v23 = v4;
      v24 = this;
      goto LABEL_12;
    }
  }
LABEL_13:
  idStr::FreeData(this: &v25);
  return v4;
}


// ========================================================================
// __unwind$112157
// EA  : 0x82FA4A78
// RVA : 0x00FA4A78
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112157()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$112158
// EA  : 0x82FA4AA0
// RVA : 0x00FA4AA0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void __fastcall _unwind_112158(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 80), tag: a2);
}


// ========================================================================
// ?ReadChildren@idXMLReader@@AAAXPAVidXMLElement@@@Z
// EA  : 0x82FA4AD0
// RVA : 0x00FA4AD0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void __fastcall idXMLReader::ReadChildren(idXMLReader *this, idXMLElement *parent, __int64 a3, __int64 a4)
{
  __int64 v6; // r6
  __int64 v7; // r8
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r8
  idXMLElement *v15; // r3
  idXMLElement *v16; // r29
  __int64 v17; // r6
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idXMLElement *v23; // r4
  idXMLReader *v24; // r3
  idXMLElement *v25; // [sp+50h] [-B0h] BYREF
  idToken v26; // [sp+60h] [-A0h] BYREF

  LODWORD(a4) = byte_821B0000;
  while ( 1 )
  {
    v26.floatvalue = -3.4028235e38;
    v26.allocedAndFlag = 20;
    v26.data = v26.baseBuffer;
    v26.len = 0;
    v26.baseBuffer[0] = 0;
    v26.intvalue = 0;
    memset(&v26.whiteSpaceStart_p, 0, 12);
    idLexer::SkipUntilString(this: &this->lexer, string: "<", a3, a4);
    LODWORD(v6) = &v26;
    HIDWORD(v6) = 43;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v6, a4: v7) != 0 )
      idLexer::SkipUntilString(this: &this->lexer, string: "<", a3: v9, a4: v8);
    LODWORD(v10) = &v26;
    HIDWORD(v10) = 28;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v10, a4: v8) != 0 )
      break;
    idLexer::ReadToken(this: &this->lexer, token: &v26, a3: v13, a4: v12, a5: v11);
    v15 = (idXMLElement *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0x60u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v25 = v15;
    if ( v15 != nullptr )
      v16 = idXMLElement::idXMLElement(this: v15, name: v26.data);
    else
      v16 = nullptr;
    LODWORD(v17) = &v26;
    HIDWORD(v17) = 28;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v17, a4: v14) == 0 )
    {
      LODWORD(v19) = &v26;
      HIDWORD(v19) = 38;
      if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v19, a4: v18) != 0 )
      {
        idLexer::ReadToken(this: &this->lexer, token: &v26, a3: v22, a4: v21, a5: v20);
        v23 = v16;
        v24 = this;
      }
      else
      {
        if ( (unsigned __int8)idXMLReader::ReadAttributes(this, owner: v16) != 0 )
          goto LABEL_14;
        v23 = v16;
        v24 = this;
      }
      idXMLReader::ReadElementContents(this: v24, element: v23);
    }
LABEL_14:
    idStr::FreeData(this: &v26);
    if ( v16 == nullptr )
      return;
    v25 = v16;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&parent->children,
      obj: (encounterGroupRole_t *)&v25);
  }
  idStr::FreeData(this: &v26);
}


// ========================================================================
// __unwind$112426_0
// EA  : 0x82FA4C98
// RVA : 0x00FA4C98
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112426_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$112427
// EA  : 0x82FA4CC0
// RVA : 0x00FA4CC0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void __fastcall _unwind_112427(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 256 + 80), tag: a2);
}


// ========================================================================
// ?ReadElementContents@idXMLReader@@AAAXPAVidXMLElement@@@Z
// EA  : 0x82FA4CF0
// RVA : 0x00FA4CF0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void __fastcall idXMLReader::ReadElementContents(idXMLReader *this, idXMLElement *element, int a3, int a4, __int64 a5)
{
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r6
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r6
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r8
  __int64 v20; // r6
  __int64 v21; // r8
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r4
  int v26; // [sp+8h] [-D8h]
  int v27; // [sp+Ch] [-D4h]
  int v28; // [sp+10h] [-D0h]
  int v29; // [sp+14h] [-CCh]
  idStr v30; // [sp+50h] [-90h] BYREF
  idToken v31; // [sp+70h] [-70h] BYREF

  LODWORD(a5) = v31.baseBuffer;
  v31.len = 0;
  v31.allocedAndFlag = 20;
  v31.floatvalue = -3.4028235e38;
  v31.data = v31.baseBuffer;
  v31.baseBuffer[0] = 0;
  v31.intvalue = 0;
  memset(&v31.whiteSpaceStart_p, 0, 12);
  LODWORD(v7) = &v31;
  HIDWORD(v7) = 39;
  HIDWORD(v9) = (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v7, a4: a5);
  if ( HIDWORD(v9) != 0 )
  {
    idXMLReader::ReadChildren(this, parent: element, a3: v10, a4: v9);
  }
  else
  {
    idLexer::ReadToken(this: &this->lexer, token: &v31, a3: v10, a4: (unsigned int)v9, a5: v8);
    idStr::idStr(this: &v30, text: v31.data);
    LODWORD(v11) = &v31;
    HIDWORD(v11) = 39;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v11, a4: v12) == 0 )
    {
      do
      {
        idLexer::ReadToken(this: &this->lexer, token: &v31, a3: v15, a4: v14, a5: v13);
        if ( v31.type != 5 )
          idStr::Append(this: &v30, text: " ");
        idStr::Append(this: &v30, text: v31.data);
        LODWORD(v16) = &v31;
        HIDWORD(v16) = 39;
      }
      while ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v16, a4: v17) == 0 );
    }
    idStr::operator=(this: &element->value, text: v30.data);
    LODWORD(v18) = &v31;
    HIDWORD(v18) = 39;
    idLexer::ExpectTokenType(this: &this->lexer, type: 5, token: v18, a4: v19);
    LODWORD(v20) = &v31;
    HIDWORD(v20) = 28;
    if ( (unsigned __int8)idLexer::PeekTokenType(this: &this->lexer, type: 5, token: v20, a4: v21) == 0 )
    {
      HIDWORD(v25) = "idXMLReader does not currently support tags with both values and child elements.";
      idLib::Warning(fmt: v25, a2: v24, a3: v23, a4: v22, a5: v26, a6: v27, a7: v28, a8: v29);
    }
    idStr::FreeData(this: &v30);
  }
  idStr::FreeData(this: &v31);
}


// ========================================================================
// __unwind$112592
// EA  : 0x82FA4E5C
// RVA : 0x00FA4E5C
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$112593
// EA  : 0x82FA4E84
// RVA : 0x00FA4E84
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

void _unwind_112593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?ReadDocument@idXMLReader@@QAAPAVidXMLElement@@XZ
// EA  : 0x82FA4EB0
// RVA : 0x00FA4EB0
// PDB : w:\tech5\shared\idlib\xml\xmlreader.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idXMLElement *__fastcall idXMLReader::ReadDocument(idXMLReader *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // r4
  int v7; // r4
  idXMLElement *Element_R; // r31
  int v9; // [sp+8h] [-58h]
  int v10; // [sp+Ch] [-54h]
  int v11; // [sp+10h] [-50h]
  int v12; // [sp+14h] [-4Ch]

  if ( this->lexer.loaded )
  {
    Element_R = idXMLReader::ReadElement_R(this, a2: v7, a3, a4);
    idXMLElement::FormatStrings_R(this: Element_R, element: Element_R);
    return Element_R;
  }
  else
  {
    HIDWORD(v5) = "idXMLReader does not have a source file open.";
    idLib::Warning(fmt: v5, a2: a3, a3: a4, a4: a5, a5: v9, a6: v10, a7: v11, a8: v12);
    return nullptr;
  }
}

