
// ========================================================================
// ?TestRoot@idXMLWriter@@AAA_NXZ
// EA  : 0x82FA4F18
// RVA : 0x00FA4F18
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idXMLWriter::TestRoot(idXMLWriter *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idFile *xmlFile; // r3
  int v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v11; // r4
  int v12; // [sp+8h] [-58h]
  int v13; // [sp+Ch] [-54h]
  int v14; // [sp+10h] [-50h]
  int v15; // [sp+14h] [-4Ch]

  if ( !this->hasRoot || (LODWORD(a5) = this->tabLevel, (_DWORD)a5 != 0) )
  {
    this->hasRoot = true;
    return 1;
  }
  else
  {
    xmlFile = this->xmlFile;
    if ( xmlFile != nullptr )
    {
      v6 = (int)xmlFile->GetName(this: xmlFile);
      HIDWORD(v7) = &g_ThumbnailCaptureVS[702];
      idLib::Warning(
        fmt: __SPAIR64__("XML document %s cannot have two root elements.", v6),
        a2: v9,
        a3: v8,
        a4: v7,
        a5: v12,
        a6: v13,
        a7: v14,
        a8: v15);
    }
    else
    {
      HIDWORD(v11) = "XML documents cannot have two root elements.";
      idLib::Warning(fmt: v11, a2: a3, a3: a4, a4: a5, a5: v12, a6: v13, a7: v14, a8: v15);
    }
    return 0;
  }
}


// ========================================================================
// ??0idXMLWriter@@QAA@XZ
// EA  : 0x82FA4FC0
// RVA : 0x00FA4FC0
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

idXMLWriter *__fastcall idXMLWriter::idXMLWriter(idXMLWriter *this)
{
  this->xmlFile = nullptr;
  this->tabLevel = 0;
  this->hasRoot = false;
  this->openTags.last = nullptr;
  this->openTags.first = nullptr;
  return this;
}


// ========================================================================
// ?OpenFile@idXMLWriter@@QAA_NPBD_N1@Z
// EA  : 0x82FA4FE8
// RVA : 0x00FA4FE8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

BOOL __fastcall idXMLWriter::OpenFile(
        idXMLWriter *this,
        const char *relativePath,
        const bool overwrite,
        const bool savepath)
{
  idFile *xmlFile; // r3
  int v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idFileSystem_vtbl *v12; // r11
  idFile *v13; // r3
  char *data; // r4
  idFile *v15; // r3
  idFile *v16; // r22
  const char *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int *p_tabLevel; // r23
  idXMLWriter::stackXMLTag_t *v22; // r28
  idXMLWriter::stackXMLTag_t *next; // r29
  int v24; // r25
  idStr *v25; // r3
  idStr *v26; // r30
  int v27; // r8
  idStack<idXMLWriter::stackXMLTag_t,32> *p_openTags; // r9
  idXMLWriter::stackXMLTag_t *v29; // r10
  idStackNode<idXMLWriter::stackXMLTag_t> *p_stackNode; // r11
  int v31; // r4
  idXMLWriter::stackXMLTag_t *last; // r7
  BOOL v33; // r30
  int v34; // [sp+8h] [-108h]
  int v35; // [sp+Ch] [-104h]
  int v36; // [sp+10h] [-100h]
  int v37; // [sp+14h] [-FCh]
  idStr v38; // [sp+60h] [-B0h] BYREF
  idStr v39[4]; // [sp+80h] [-90h] BYREF

  xmlFile = this->xmlFile;
  if ( xmlFile != nullptr )
  {
    v7 = (int)xmlFile->GetName(this: xmlFile);
    HIDWORD(v8) = &g_ThumbnailCaptureVS[702];
    idLib::Warning(
      fmt: __SPAIR64__("idXMLWriter already writing to %s", v7),
      a2: v10,
      a3: v9,
      a4: v8,
      a5: v34,
      a6: v35,
      a7: v36,
      a8: v37);
    return false;
  }
  else
  {
    idStr::idStr(this: v39, text: relativePath);
    idStr::SetFileExtension(this: v39, extension: ".dat");
    v12 = fileSystem->__vftable;
    if ( overwrite )
    {
      this->xmlFile = (idFile *)((int (*)(void))v12->OpenFileWrite)();
    }
    else
    {
      v13 = (idFile *)((int (*)(void))v12->OpenFileAppend)();
      this->xmlFile = v13;
      if ( v13 != nullptr && fileSystem->FileExists(this: fileSystem, a2: v39[0].data, a3: false) )
      {
        data = v39[0].data;
        this->hasRoot = true;
        v15 = fileSystem->OpenFileRead(this: fileSystem, a2: data, a3: 1, a4: 0);
        v16 = v15;
        if ( v15 != nullptr )
        {
          p_tabLevel = &this->tabLevel;
          v15->Read(this: v15, a2: &this->tabLevel, a3: 4u);
          v38.len = 0;
          v22 = nullptr;
          v38.baseBuffer[0] = 0;
          next = nullptr;
          v38.allocedAndFlag = 20;
          v38.data = v38.baseBuffer;
          v24 = 0;
          if ( this->tabLevel > 0 )
          {
            do
            {
              idFile::ReadString(this: v16, string: &v38);
              v25 = (idStr *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x24u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
              v26 = v25;
              if ( v25 != nullptr )
              {
                idStr::idStr(this: v25, text: v38.data);
                v26[1].len = 0;
              }
              else
              {
                v26 = nullptr;
              }
              v26[1].len = (int)next;
              next = (idXMLWriter::stackXMLTag_t *)v26;
              if ( v22 == nullptr )
                v22 = (idXMLWriter::stackXMLTag_t *)v26;
              ++v24;
            }
            while ( v24 < *p_tabLevel );
          }
          v27 = 0;
          if ( *p_tabLevel > 0 )
          {
            p_openTags = &this->openTags;
            do
            {
              v29 = next;
              if ( next != nullptr )
              {
                p_stackNode = &next->stackNode;
                v31 = (next == v22) - 1;
                next = next->stackNode.next;
                v22 = (idXMLWriter::stackXMLTag_t *)(v31 & (unsigned int)v22);
                p_stackNode->next = nullptr;
              }
              v29->stackNode.next = p_openTags->first;
              last = this->openTags.last;
              p_openTags->first = v29;
              if ( last == nullptr )
                this->openTags.last = v29;
              ++v27;
            }
            while ( v27 < *p_tabLevel );
          }
          ((void (__fastcall *)(idFile *, int))v16->dtr_idFile)(a1: v16, a2: 1);
          idStr::FreeData(this: &v38);
        }
        else
        {
          v17 = this->xmlFile->GetName(this: this->xmlFile);
          HIDWORD(v18) = &g_ThumbnailCaptureVS[702];
          idLib::Warning(
            fmt: __SPAIR64__("XML file %s unable to load editing state.", (unsigned int)v17),
            a2: v20,
            a3: v19,
            a4: v18,
            a5: v34,
            a6: v35,
            a7: v36,
            a8: v37);
        }
      }
    }
    if ( fileSystem->FileExists(this: fileSystem, a2: v39[0].data, a3: false) )
      fileSystem->RemoveFile(this: fileSystem, a2: v39[0].data, a3: FSPATH_BASE);
    v33 = this->xmlFile != nullptr;
    idStr::FreeData(this: v39);
    return v33;
  }
}


// ========================================================================
// __unwind$112142
// EA  : 0x82FA5308
// RVA : 0x00FA5308
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$112143
// EA  : 0x82FA5330
// RVA : 0x00FA5330
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112143()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$112144
// EA  : 0x82FA5358
// RVA : 0x00FA5358
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void __fastcall _unwind_112144(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 272 + 80), tag: a2);
}


// ========================================================================
// ?IndentString@idXMLWriter@@ABAXAAVidStr@@@Z
// EA  : 0x82FA5380
// RVA : 0x00FA5380
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void __fastcall idXMLWriter::IndentString(idXMLWriter *this, idStr *s)
{
  int i; // r31

  idStr::Clear(this: s);
  for ( i = 0; i < this->tabLevel; ++i )
    idStr::Append(this: s, text: "  ");
}


// ========================================================================
// ?FormatString@idXMLWriter@@ABAXAAVidStr@@@Z
// EA  : 0x82FA53D8
// RVA : 0x00FA53D8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void __fastcall idXMLWriter::FormatString(idXMLWriter *this, idStr *s)
{
  idStr::RemoveColors(this: s);
  idStr::BackSlashesToSlashes(this: s);
  idStr::StripLeadingWhiteSpace(this: s);
  idStr::StripTrailingWhitespace(this: s);
  idStr::Replace(this: s, old: "&", nw: "&amp;");
  idStr::Replace(this: s, old: "<", nw: "&lt;");
  idStr::Replace(this: s, old: ">", nw: "&gt;");
}


// ========================================================================
// ?CloseFile@idXMLWriter@@QAA_NXZ
// EA  : 0x82FA5470
// RVA : 0x00FA5470
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

idFile *__fastcall idXMLWriter::CloseFile(idXMLWriter *this)
{
  idFile *result; // r3
  int *p_tabLevel; // r26
  const char *v4; // r3
  idFile *v5; // r3
  idFile *v6; // r28
  const char *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // r27
  idStack<idXMLWriter::stackXMLTag_t,32> *p_openTags; // r29
  idStr *p_tagName; // r30
  idXMLWriter::stackXMLTag_t *last; // r10
  int v15; // [sp+8h] [-B8h]
  int v16; // [sp+Ch] [-B4h]
  int v17; // [sp+10h] [-B0h]
  int v18; // [sp+14h] [-ACh]
  idStr v19[3]; // [sp+50h] [-70h] BYREF

  result = this->xmlFile;
  if ( result != nullptr )
  {
    p_tabLevel = &this->tabLevel;
    if ( this->tabLevel != 0 )
    {
      v4 = result->GetFullPath(this: result);
      idStr::idStr(this: v19, text: v4);
      idStr::SetFileExtension(this: v19, extension: ".dat");
      v5 = fileSystem->OpenFileWrite(this: fileSystem, a2: v19[0].data, a3: 0);
      v6 = v5;
      if ( v5 != nullptr )
      {
        v5->Write(this: v5, a2: &this->tabLevel, a3: 4u);
        v11 = 0;
        if ( *p_tabLevel > 0 )
        {
          p_openTags = &this->openTags;
          do
          {
            p_tagName = &p_openTags->first->tagName;
            if ( p_openTags->first != nullptr )
            {
              last = this->openTags.last;
              p_openTags->first = (idXMLWriter::stackXMLTag_t *)p_tagName[1].len;
              if ( last == (idXMLWriter::stackXMLTag_t *)p_tagName )
                this->openTags.last = nullptr;
              p_tagName[1].len = 0;
            }
            idFile::WriteString(this: v6, string: p_tagName);
            if ( p_tagName != nullptr )
            {
              idStr::FreeData(this: p_tagName);
              idMem::Free(this: &mem, ptr: p_tagName, align: ALIGN_16);
            }
            ++v11;
          }
          while ( v11 < *p_tabLevel );
        }
        ((void (__fastcall *)(idFile *, int))v6->dtr_idFile)(a1: v6, a2: 1);
      }
      else
      {
        v7 = this->xmlFile->GetName(this: this->xmlFile);
        HIDWORD(v8) = &g_ThumbnailCaptureVS[702];
        idLib::Warning(
          fmt: __SPAIR64__("XML file %s unable to save editting state.", (unsigned int)v7),
          a2: v10,
          a3: v9,
          a4: v8,
          a5: v15,
          a6: v16,
          a7: v17,
          a8: v18);
      }
      idStr::FreeData(this: v19);
    }
    if ( this->xmlFile != nullptr )
      ((void (__fastcall *)(idFile *, int))this->xmlFile->dtr_idFile)(a1: this->xmlFile, a2: 1);
    this->xmlFile = nullptr;
    *p_tabLevel = 0;
    this->hasRoot = false;
    return (idFile *)1;
  }
  return result;
}


// ========================================================================
// __unwind$112354
// EA  : 0x82FA5618
// RVA : 0x00FA5618
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112354()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?OpenElement@idXMLWriter@@QAA_NPBD@Z
// EA  : 0x82FA5648
// RVA : 0x00FA5648
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::OpenElement(idXMLWriter *this, char *name, __int64 a3, __int64 a4, __int64 a5)
{
  idStr *v7; // r3
  idXMLWriter::stackXMLTag_t *v8; // r30
  idXMLWriter::stackXMLTag_t *last; // r9
  idStr v11[2]; // [sp+60h] [-50h] BYREF

  if ( this->xmlFile == nullptr || (unsigned __int8)idXMLWriter::TestRoot(this, a2: (int)name, a3, a4, a5) == 0 )
    return 0;
  v11[0].len = 0;
  v11[0].allocedAndFlag = 20;
  v11[0].data = v11[0].baseBuffer;
  v11[0].baseBuffer[0] = 0;
  idXMLWriter::IndentString(this, s: v11);
  idStr::Append(this: v11, text: "<");
  idStr::Append(this: v11, text: name);
  idStr::Append(this: v11, text: ">\n");
  this->xmlFile->Printf(this: this->xmlFile, a2: v11[0].data);
  v7 = (idStr *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x24u,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v8 = (idXMLWriter::stackXMLTag_t *)v7;
  if ( v7 != nullptr )
  {
    idStr::idStr(this: v7, text: name);
    v8->stackNode.next = nullptr;
  }
  else
  {
    v8 = nullptr;
  }
  v8->stackNode.next = this->openTags.first;
  last = this->openTags.last;
  this->openTags.first = v8;
  if ( last == nullptr )
    this->openTags.last = v8;
  ++this->tabLevel;
  idStr::FreeData(this: v11);
  return 1;
}


// ========================================================================
// __unwind$112431
// EA  : 0x82FA5784
// RVA : 0x00FA5784
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112431()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$112432
// EA  : 0x82FA57AC
// RVA : 0x00FA57AC
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void __fastcall _unwind_112432(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?OpenElement@idXMLWriter@@QAA_NPBDABV?$idList@VidXMLAttribute@@$0CM@@@@Z
// EA  : 0x82FA57E0
// RVA : 0x00FA57E0
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::OpenElement(idXMLWriter *this, char *name, __int64 attributes, __int64 a4, __int64 a5)
{
  _DWORD *v7; // r28
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r30
  int v11; // r29
  __int64 v12; // r6
  va *v13; // r3
  idStr *v14; // r3
  idXMLWriter::stackXMLTag_t *v15; // r30
  idXMLWriter::stackXMLTag_t *last; // r9
  int v18; // [sp+8h] [-10E8h]
  int v19; // [sp+Ch] [-10E4h]
  int v20; // [sp+10h] [-10E0h]
  int v21; // [sp+14h] [-10DCh]
  int v22; // [sp+18h] [-10D8h]
  int v23; // [sp+1Ch] [-10D4h]
  int v24; // [sp+50h] [-10A0h]
  idStr v25; // [sp+60h] [-1090h] BYREF
  idStr v26; // [sp+80h] [-1070h] BYREF
  va v27; // [sp+A0h] [-1050h] BYREF

  v7 = (_DWORD *)HIDWORD(attributes);
  if ( this->xmlFile == nullptr
    || (unsigned __int8)idXMLWriter::TestRoot(this, a2: (int)name, a3: attributes, a4, a5) == 0 )
  {
    return 0;
  }
  v25.len = 0;
  v25.baseBuffer[0] = 0;
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  idXMLWriter::IndentString(this, s: &v25);
  idStr::Append(this: &v25, text: "<");
  idStr::Append(this: &v25, text: name);
  LODWORD(v9) = v7[1];
  v10 = 0;
  if ( (int)v9 > 0 )
  {
    v11 = 0;
    do
    {
      v24 = v11 + *v7;
      LODWORD(v12) = *(_DWORD *)(v24 + 36);
      HIDWORD(v12) = *(_DWORD *)(v24 + 4);
      v13 = va::va(
              this: &v27,
              fmt: " %s=\"%s\"",
              a3: v12,
              a4: v9,
              a5: v8,
              a6: v18,
              a7: v19,
              a8: v20,
              a9: v21,
              a10: v22,
              a11: v23);
      idStr::idStr(this: &v26, text: v13);
      idStr::Append(this: &v25, text: &v26);
      idStr::FreeData(this: &v26);
      ++v10;
      v11 += 64;
    }
    while ( v10 < v7[1] );
  }
  idStr::Append(this: &v25, text: ">\n");
  this->xmlFile->Printf(this: this->xmlFile, a2: v25.data);
  v14 = (idStr *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                   size: 0x24u,
                   tag: TAG_NEW,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v15 = (idXMLWriter::stackXMLTag_t *)v14;
  if ( v14 != nullptr )
  {
    idStr::idStr(this: v14, text: name);
    v15->stackNode.next = nullptr;
  }
  else
  {
    v15 = nullptr;
  }
  v15->stackNode.next = this->openTags.first;
  last = this->openTags.last;
  this->openTags.first = v15;
  if ( last == nullptr )
    this->openTags.last = v15;
  ++this->tabLevel;
  idStr::FreeData(this: &v25);
  return 1;
}


// ========================================================================
// __unwind$112514
// EA  : 0x82FA5998
// RVA : 0x00FA5998
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 96));
}


// ========================================================================
// __unwind$112515
// EA  : 0x82FA59C0
// RVA : 0x00FA59C0
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112515()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 128));
}


// ========================================================================
// __unwind$112516
// EA  : 0x82FA59E8
// RVA : 0x00FA59E8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void __fastcall _unwind_112516(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4336 + 80), tag: a2);
}


// ========================================================================
// ?WriteElement@idXMLWriter@@QAA_NPBD0@Z
// EA  : 0x82FA5A18
// RVA : 0x00FA5A18
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::WriteElement(idXMLWriter *this, const char *name, __int64 value, __int64 a4, __int64 a5)
{
  const char *v7; // r30
  __int64 v8; // r10
  __int64 v9; // r6
  __int64 v10; // r8
  va *v11; // r3
  int v12; // r11
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  int v17; // [sp+8h] [-20D8h]
  int v18; // [sp+8h] [-20D8h]
  int v19; // [sp+Ch] [-20D4h]
  int v20; // [sp+Ch] [-20D4h]
  int v21; // [sp+10h] [-20D0h]
  int v22; // [sp+10h] [-20D0h]
  int v23; // [sp+14h] [-20CCh]
  int v24; // [sp+14h] [-20CCh]
  int v25; // [sp+18h] [-20C8h]
  int v26; // [sp+18h] [-20C8h]
  int v27; // [sp+1Ch] [-20C4h]
  int v28; // [sp+1Ch] [-20C4h]
  idStr v29; // [sp+50h] [-2090h] BYREF
  idStr v30; // [sp+70h] [-2070h] BYREF
  idStr v31; // [sp+90h] [-2050h] BYREF
  va v32; // [sp+B0h] [-2030h] BYREF
  va v33; // [sp+10B0h] [-1030h] BYREF

  v7 = (const char *)HIDWORD(value);
  if ( this->xmlFile == nullptr || (unsigned __int8)idXMLWriter::TestRoot(this, a2: (int)name, a3: value, a4, a5) == 0 )
    return 0;
  v29.len = 0;
  v29.baseBuffer[0] = 0;
  v29.allocedAndFlag = 20;
  v29.data = v29.baseBuffer;
  idXMLWriter::IndentString(this, s: &v29);
  HIDWORD(v8) = &g_ThumbnailCaptureVS[702];
  HIDWORD(v9) = name;
  v11 = va::va(this: &v32, fmt: "<%s", a3: v9, a4: v10, a5: v8, a6: v17, a7: v19, a8: v21, a9: v23, a10: v25, a11: v27);
  idStr::idStr(this: &v30, text: v11);
  v12 = 0;
  if ( *v7 == 0 )
    goto LABEL_6;
  do
    ++v12;
  while ( v7[v12] != 0 );
  if ( v12 != 0 )
  {
    idStr::idStr(this: &v31, text: v7);
    idXMLWriter::FormatString(this, s: &v31);
    v15 = va::va(
            this: &v33,
            fmt: ">%s</%s>\n",
            a3: __SPAIR64__((unsigned int)v31.data, (unsigned int)name),
            a4: v14,
            a5: v13,
            a6: v18,
            a7: v20,
            a8: v22,
            a9: v24,
            a10: v26,
            a11: v28);
    idStr::Append(this: &v30, text: v15);
    idStr::FreeData(this: &v31);
  }
  else
  {
LABEL_6:
    idStr::Append(this: &v30, text: "/>\n");
  }
  idStr::Append(this: &v29, text: &v30);
  this->xmlFile->Printf(this: this->xmlFile, a2: v29.data);
  idStr::FreeData(this: &v30);
  idStr::FreeData(this: &v29);
  return 1;
}


// ========================================================================
// __unwind$112628
// EA  : 0x82FA5B68
// RVA : 0x00FA5B68
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112628()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8416 + 80));
}


// ========================================================================
// __unwind$112629
// EA  : 0x82FA5B90
// RVA : 0x00FA5B90
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112629()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8416 + 112));
}


// ========================================================================
// __unwind$112630
// EA  : 0x82FA5BB8
// RVA : 0x00FA5BB8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8416 + 144));
}


// ========================================================================
// ?WriteElement@idXMLWriter@@QAA_NPBD0ABV?$idList@VidXMLAttribute@@$0CM@@@@Z
// EA  : 0x82FA5BE8
// RVA : 0x00FA5BE8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::WriteElement(idXMLWriter *this, char *name, __int64 attributes, __int64 a4, __int64 a5)
{
  const char *v7; // r24
  _DWORD *v8; // r28
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r30
  int v12; // r29
  __int64 v13; // r6
  va *v14; // r3
  int v15; // r11
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  int v20; // [sp+8h] [-1128h]
  int v21; // [sp+Ch] [-1124h]
  int v22; // [sp+10h] [-1120h]
  int v23; // [sp+14h] [-111Ch]
  int v24; // [sp+18h] [-1118h]
  int v25; // [sp+1Ch] [-1114h]
  int v26; // [sp+50h] [-10E0h]
  idStr v27; // [sp+60h] [-10D0h] BYREF
  idStr v28; // [sp+80h] [-10B0h] BYREF
  idStr v29; // [sp+A0h] [-1090h] BYREF
  idStr v30; // [sp+C0h] [-1070h] BYREF
  va v31; // [sp+E0h] [-1050h] BYREF

  v7 = (const char *)HIDWORD(attributes);
  v8 = (_DWORD *)attributes;
  if ( this->xmlFile == nullptr
    || (unsigned __int8)idXMLWriter::TestRoot(this, a2: (int)name, a3: attributes, a4, a5) == 0 )
  {
    return 0;
  }
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  idXMLWriter::IndentString(this, s: &v27);
  idStr::Append(this: &v27, text: "<");
  idStr::Append(this: &v27, text: name);
  LODWORD(v10) = v8[1];
  v11 = 0;
  if ( (int)v10 > 0 )
  {
    v12 = 0;
    do
    {
      v26 = v12 + *v8;
      LODWORD(v13) = *(_DWORD *)(v26 + 36);
      HIDWORD(v13) = *(_DWORD *)(v26 + 4);
      v14 = va::va(
              this: &v31,
              fmt: " %s=\"%s\"",
              a3: v13,
              a4: v10,
              a5: v9,
              a6: v20,
              a7: v21,
              a8: v22,
              a9: v23,
              a10: v24,
              a11: v25);
      idStr::idStr(this: &v30, text: v14);
      idStr::Append(this: &v27, text: &v30);
      idStr::FreeData(this: &v30);
      ++v11;
      v12 += 64;
    }
    while ( v11 < v8[1] );
  }
  v15 = 0;
  if ( *v7 == 0 )
    goto LABEL_9;
  do
    ++v15;
  while ( v7[v15] != 0 );
  if ( v15 != 0 )
  {
    idStr::idStr(this: &v28, text: v7);
    idXMLWriter::FormatString(this, s: &v28);
    v18 = va::va(
            this: &v31,
            fmt: ">%s</%s>\n",
            a3: __SPAIR64__((unsigned int)v28.data, (unsigned int)name),
            a4: v17,
            a5: v16,
            a6: v20,
            a7: v21,
            a8: v22,
            a9: v23,
            a10: v24,
            a11: v25);
    idStr::idStr(this: &v29, text: v18);
    idStr::Append(this: &v27, text: &v29);
    idStr::FreeData(this: &v29);
    idStr::FreeData(this: &v28);
  }
  else
  {
LABEL_9:
    idStr::Append(this: &v27, text: "/>\n");
  }
  this->xmlFile->Printf(this: this->xmlFile, a2: v27.data);
  idStr::FreeData(this: &v27);
  return 1;
}


// ========================================================================
// __unwind$112712
// EA  : 0x82FA5DA8
// RVA : 0x00FA5DA8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112712()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 96));
}


// ========================================================================
// __unwind$112713
// EA  : 0x82FA5DD0
// RVA : 0x00FA5DD0
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 192));
}


// ========================================================================
// __unwind$112714
// EA  : 0x82FA5DF8
// RVA : 0x00FA5DF8
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 128));
}


// ========================================================================
// __unwind$112715
// EA  : 0x82FA5E20
// RVA : 0x00FA5E20
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112715()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 160));
}


// ========================================================================
// ?CloseElement@idXMLWriter@@QAA_NXZ
// EA  : 0x82FA5E50
// RVA : 0x00FA5E50
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::CloseElement(idXMLWriter *this)
{
  idXMLWriter::stackXMLTag_t *first; // r30
  idXMLWriter::stackXMLTag_t *last; // r8
  int tabLevel; // r11
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  if ( this->xmlFile == nullptr )
    return 0;
  first = this->openTags.first;
  if ( first == nullptr )
    return 0;
  last = this->openTags.last;
  this->openTags.first = first->stackNode.next;
  if ( last == first )
    this->openTags.last = nullptr;
  first->stackNode.next = nullptr;
  tabLevel = this->tabLevel;
  v6[0].len = 0;
  v6[0].allocedAndFlag = 20;
  v6[0].data = v6[0].baseBuffer;
  this->tabLevel = tabLevel - 1;
  v6[0].baseBuffer[0] = 0;
  idXMLWriter::IndentString(this, s: v6);
  idStr::Append(this: v6, text: "</");
  idStr::Append(this: v6, text: &first->tagName);
  idStr::Append(this: v6, text: ">\n");
  this->xmlFile->Printf(this: this->xmlFile, a2: v6[0].data);
  idStr::FreeData(this: &first->tagName);
  idMem::Free(this: &mem, ptr: first, align: ALIGN_16);
  idStr::FreeData(this: v6);
  return 1;
}


// ========================================================================
// __unwind$112853
// EA  : 0x82FA5F4C
// RVA : 0x00FA5F4C
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?CloseDocument@idXMLWriter@@QAA_NXZ
// EA  : 0x82FA5F80
// RVA : 0x00FA5F80
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::CloseDocument(idXMLWriter *this)
{
  int tabLevel; // r11
  int result; // r3
  idXMLWriter::stackXMLTag_t *first; // r29
  idXMLWriter::stackXMLTag_t *last; // r9
  int v6; // r11
  int v7; // r7
  int v8; // r30
  idStr v9[4]; // [sp+50h] [-80h] BYREF

  tabLevel = this->tabLevel;
  result = 1;
  if ( tabLevel != 0 )
  {
    do
    {
      if ( (_BYTE)result == 0 )
        break;
      if ( this->xmlFile != nullptr && (first = this->openTags.first) != nullptr )
      {
        last = this->openTags.last;
        this->openTags.first = first->stackNode.next;
        if ( last == first )
          this->openTags.last = nullptr;
        first->stackNode.next = nullptr;
        v6 = this->tabLevel;
        v9[0].allocedAndFlag = 20;
        v9[0].data = v9[0].baseBuffer;
        v9[0].len = 0;
        this->tabLevel = v6 - 1;
        v9[0].baseBuffer[0] = 0;
        idStr::FreeData(this: v9);
        v7 = this->tabLevel;
        v9[0].allocedAndFlag = 20;
        v8 = 0;
        v9[0].len = 0;
        v9[0].data = v9[0].baseBuffer;
        v9[0].baseBuffer[0] = 0;
        if ( v7 > 0 )
        {
          do
          {
            idStr::Append(this: v9, text: "  ");
            ++v8;
          }
          while ( v8 < this->tabLevel );
        }
        idStr::Append(this: v9, text: "</");
        idStr::Append(this: v9, text: &first->tagName);
        idStr::Append(this: v9, text: ">\n");
        this->xmlFile->Printf(this: this->xmlFile, a2: v9[0].data);
        idStr::FreeData(this: &first->tagName);
        idMem::Free(this: &mem, ptr: first, align: ALIGN_16);
        idStr::FreeData(this: v9);
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
    while ( this->tabLevel != 0 );
  }
  return result;
}


// ========================================================================
// __unwind$112947
// EA  : 0x82FA60F4
// RVA : 0x00FA60F4
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

void _unwind_112947()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?WriteElement_R@idXMLWriter@@AAA_NPBVidXMLElement@@@Z
// EA  : 0x82FA6120
// RVA : 0x00FA6120
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::WriteElement_R(
        idXMLWriter *this,
        const idXMLElement *element,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int num; // r11
  char *data; // r4
  idList<idXMLElement *,44> *p_children; // r30
  int v11; // r29
  int i; // r31
  __int64 v13; // r6

  if ( element == nullptr )
    return 0;
  num = element->children.num;
  data = element->name.data;
  if ( num != 0 )
  {
    HIDWORD(a3) = &element->attributes;
    if ( (unsigned __int8)idXMLWriter::OpenElement(this, name: data, attributes: a3, a4, a5) == 0 )
      return 0;
    p_children = &element->children;
    v11 = 0;
    if ( element->children.num > 0 )
    {
      for ( i = 0; idXMLWriter::WriteElement_R(this, element: p_children->list[i]); ++i )
      {
        if ( ++v11 >= p_children->num )
          return idXMLWriter::CloseElement(this);
      }
      return 0;
    }
    return idXMLWriter::CloseElement(this);
  }
  else
  {
    LODWORD(v13) = &element->attributes;
    HIDWORD(v13) = element->value.data;
    return idXMLWriter::WriteElement(this, name: data, attributes: v13, a4, a5);
  }
}


// ========================================================================
// ?WriteDocument@idXMLWriter@@QAA_NPBVidXMLElement@@@Z
// EA  : 0x82FA61E0
// RVA : 0x00FA61E0
// PDB : w:\tech5\shared\idlib\xml\xmlwriter.cpp
// ========================================================================

int __fastcall idXMLWriter::WriteDocument(
        idXMLWriter *this,
        const idXMLElement *root,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  int v11; // [sp+8h] [-58h]
  int v12; // [sp+Ch] [-54h]
  int v13; // [sp+10h] [-50h]
  int v14; // [sp+14h] [-4Ch]

  if ( this->hasRoot )
  {
    v6 = ((int (__fastcall *)(idFile *, const idXMLElement *))this->xmlFile->GetName)(a1: this->xmlFile, a2: root);
    HIDWORD(v7) = &g_ThumbnailCaptureVS[702];
    idLib::Warning(
      fmt: __SPAIR64__("XML file %s already contains elements.", v6),
      a2: v9,
      a3: v8,
      a4: v7,
      a5: v11,
      a6: v12,
      a7: v13,
      a8: v14);
    return 0;
  }
  if ( (unsigned __int8)idXMLWriter::WriteElement_R(this, element: root, a3, a4, a5) == 0 )
    return 0;
  return idXMLWriter::CloseDocument(this);
}

