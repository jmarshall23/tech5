
// ========================================================================
// ?LoadSWF@idSWF@@AAA_NPBD@Z
// EA  : 0x82773650
// RVA : 0x00773650
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

int __fastcall idSWF::LoadSWF(idSWF *this, const char *fullpath)
{
  unsigned __int64 v3; // r23
  idFile *v4; // r3
  idFile *v5; // r30
  char v6; // r24
  char v7; // r5
  char v8; // r10
  unsigned int v9; // r28
  unsigned __int8 *v10; // r29
  int v11; // r25
  void *v12; // r30
  double y; // fp13
  const unsigned __int8 *v14; // r11
  idSWFSprite *mainsprite; // r3
  _BYTE v17[4]; // [sp+50h] [-1A0h] BYREF
  int v18; // [sp+54h] [-19Ch]
  swfRect_t v19; // [sp+60h] [-190h] BYREF
  idSWFBitStream v20; // [sp+70h] [-180h] BYREF
  char v21[352]; // [sp+90h] [-160h] BYREF

  HIDWORD(v3) = fullpath;
  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: fullpath, a3: 1, a4: 0);
  v5 = v4;
  if ( v4 == nullptr )
  {
    idLib::Printf(fmt: "SWF File not found %s\n", (const char *)HIDWORD(v3));
    return 0;
  }
  v4->Read(this: v4, a2: v17, a3: 8u);
  if ( v17[1] != 87 || v17[2] != 83 )
  {
    idLib::Warning(fmt: "Wrong signature bytes");
    goto LABEL_20;
  }
  if ( v17[3] > 9u )
  {
    idLib::Warning(fmt: "Unsupported version %d", v17[3]);
LABEL_20:
    ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
    return 0;
  }
  LODWORD(v3) = 0;
  if ( v17[0] == 70 )
  {
    v6 = 0;
  }
  else
  {
    if ( v17[0] != 67 )
    {
      idLib::Warning(fmt: "Unsupported compression type %c", v17[0]);
      goto LABEL_20;
    }
    v6 = 1;
  }
  v7 = BYTE2(v18);
  v8 = HIBYTE(v18);
  BYTE2(v18) = BYTE1(v18);
  HIBYTE(v18) = v18;
  BYTE1(v18) = v7;
  LOBYTE(v18) = v8;
  v9 = v18 - 8;
  v10 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\guis\\swf\\SWF_Load.cpp(62) : TAG_SWF",
                             size: v18 - 8,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v11 = v5->Read(this: v5, a2: v10, a3: v9);
  ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
  if ( v6 != 0 )
  {
    v12 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\engine\\guis\\swf\\SWF_Load.cpp(67) : TAG_SWF",
            size: v9,
            tag: TAG_SWF,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( !idSWF::Inflate(this, input: v10, inputSize: v11, output: (unsigned __int8 *)v12, outputSize: v9) )
    {
      idLib::Warning(fmt: "Inflate error");
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      return 0;
    }
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    v10 = (unsigned __int8 *)v12;
  }
  v20.free = false;
  idSWFBitStream::Load(this: &v20, data: v10, len: v9, copy: false);
  v19.tl.x = 0.0;
  v19.tl.y = 0.0;
  v19.br.x = 0.0;
  v19.br.y = 0.0;
  idSWFBitStream::ReadRect(this: &v20, rect: &v19);
  if ( ((LODWORD(v19.tl.y) | LODWORD(v19.tl.x)) & 0x7FFFFFFF) == 0 )
  {
    y = v19.br.y;
    v20.currentBit = v3;
    v14 = v20.readp + 2;
    this->frameWidth = v19.br.x;
    this->frameHeight = y;
    v20.currentByte = v3;
    v20.readp = v14;
    mainsprite = this->mainsprite;
    this->frameRate = __ROL4__(*(v14 - 1), 8) | *(v14 - 2);
    idSWFSprite::Load(this: mainsprite, bitstream: &v20, parseDictionary: true);
    fileSystem->FixLongFilename(
      this: fileSystem,
      a2: "generated",
      a3: "tga",
      a4: (const char *)HIDWORD(v3),
      a5: v21,
      a6: 256);
    idSWF::WriteSwfImageAtlas(this, filename: v21);
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    idSWFBitStream::Free(this: &v20);
    return 1;
  }
  idLib::Warning(fmt: "Invalid frameSize top left");
  idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  idSWFBitStream::Free(this: &v20);
  return 0;
}


// ========================================================================
// __unwind$222079
// EA  : 0x82773998
// RVA : 0x00773998
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_222079()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 496 + 112));
}


// ========================================================================
// ?WriteBinary@idSWF@@AAAXPBD@Z
// EA  : 0x827739C8
// RVA : 0x007739C8
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void __fastcall idSWF::WriteBinary(idSWF *this, const char *bfilename)
{
  idFile *v3; // r3
  int v4; // r20
  int v5; // r21
  int v6; // r22
  idSWFDictionaryEntry *v7; // r11
  const idMaterial *material; // r11
  const char *str; // r4
  int i; // r30
  int j; // r30
  _DWORD *p_x; // r28
  int v13; // r24
  int v14; // r25
  int v15; // r30
  int v16; // r27
  int v17; // r29
  int v18; // r29
  int v19; // r27
  int v20; // r30
  idSWFFont *font; // r30
  int v22; // r28
  int v23; // r29
  _DWORD *v24; // r29
  int v25; // r28
  int v26; // r27
  int v27; // r30
  int v28; // r28
  int v29; // r30
  const char **edittext; // r30
  idFileLocal v31; // [sp+50h] [-B0h] BYREF
  int v32; // [sp+54h] [-ACh] BYREF
  int num; // [sp+58h] [-A8h] BYREF
  int v34; // [sp+5Ch] [-A4h] BYREF
  int v35; // [sp+60h] [-A0h] BYREF
  int v36; // [sp+64h] [-9Ch] BYREF
  int v37; // [sp+68h] [-98h] BYREF
  int v38; // [sp+6Ch] [-94h] BYREF
  int v39; // [sp+70h] [-90h] BYREF
  int v40; // [sp+74h] [-8Ch] BYREF
  int v41; // [sp+78h] [-88h] BYREF
  int v42; // [sp+7Ch] [-84h] BYREF
  int v43; // [sp+80h] [-80h] BYREF
  int v44; // [sp+84h] [-7Ch] BYREF
  int v45; // [sp+88h] [-78h] BYREF
  int v46; // [sp+8Ch] [-74h] BYREF

  v3 = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  v31.file = v3;
  if ( v3 != nullptr )
  {
    v32 = 1112758032;
    v3->Write(this: v3, a2: &v32, a3: 4u);
    v31.file->Write(this: v31.file, a2: &this->timestamp, a3: 4u);
    v31.file->Write(this: v31.file, a2: &this->frameWidth, a3: 4u);
    v31.file->Write(this: v31.file, a2: &this->frameHeight, a3: 4u);
    v31.file->Write(this: v31.file, a2: &this->frameRate, a3: 2u);
    v31.file->Write(this: v31.file, a2: &this->atlasWidth, a3: 4u);
    v31.file->Write(this: v31.file, a2: &this->atlasHeight, a3: 4u);
    idSWFSprite::Write(this: this->mainsprite, f: v31.file);
    num = this->dictionary.num;
    v31.file->Write(this: v31.file, a2: &num, a3: 4u);
    v4 = 0;
    if ( this->dictionary.num > 0 )
    {
      v5 = 0;
      v6 = 11;
      do
      {
        v31.file->Write(this: v31.file, a2: &this->dictionary.list[v5], a3: 4u);
        v7 = &this->dictionary.list[v5];
        if ( (unsigned int)(v7->type - 1) <= 6 )
        {
          switch ( v7->type )
          {
            case SWF_DICT_SHAPE:
            case SWF_DICT_MORPH:
              p_x = (_DWORD *)&v7->shape->startBounds.tl.x;
              v31.file->Write(this: v31.file, a2: p_x, a3: 8u);
              v31.file->Write(this: v31.file, a2: p_x + 2, a3: 8u);
              v31.file->Write(this: v31.file, a2: p_x + 4, a3: 8u);
              v31.file->Write(this: v31.file, a2: p_x + 6, a3: 8u);
              v34 = p_x[9];
              v31.file->Write(this: v31.file, a2: &v34, a3: 4u);
              v13 = 0;
              if ( (int)p_x[9] > 0 )
              {
                v14 = 0;
                do
                {
                  v15 = p_x[8] + v14;
                  v31.file->Write(this: v31.file, a2: (const void *)v15, a3: 1u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 1), a3: 1u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 2), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 6), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 12), a3: 24u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 36), a3: 24u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 60), a3: 1u);
                  v16 = 0;
                  if ( *(_BYTE *)(v15 + 60) != 0 )
                  {
                    v17 = v15 + 62;
                    do
                    {
                      v31.file->Write(this: v31.file, a2: (const void *)(v17 - 1), a3: 1u);
                      v31.file->Write(this: v31.file, a2: (const void *)v17, a3: 1u);
                      v31.file->Write(this: v31.file, a2: (const void *)(v17 + 1), a3: 4u);
                      v31.file->Write(this: v31.file, a2: (const void *)(v17 + 5), a3: 4u);
                      ++v16;
                      v17 += 10;
                    }
                    while ( v16 < *(unsigned __int8 *)(v15 + 60) );
                  }
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 224), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v15 + 228), a3: 2u);
                  v35 = *(_DWORD *)(v15 + 236);
                  v31.file->Write(this: v31.file, a2: &v35, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v15 + 232), a3: 8 * *(_DWORD *)(v15 + 236));
                  v36 = *(_DWORD *)(v15 + 252);
                  v31.file->Write(this: v31.file, a2: &v36, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v15 + 248), a3: 8 * *(_DWORD *)(v15 + 252));
                  v37 = *(_DWORD *)(v15 + 268);
                  v31.file->Write(this: v31.file, a2: &v37, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v15 + 264), a3: 2 * *(_DWORD *)(v15 + 268));
                  ++v13;
                  v14 += 280;
                }
                while ( v13 < p_x[9] );
              }
              v38 = p_x[13];
              v31.file->Write(this: v31.file, a2: &v38, a3: 4u);
              v18 = 0;
              if ( (int)p_x[13] > 0 )
              {
                v19 = 0;
                do
                {
                  v20 = p_x[12] + v19;
                  v31.file->Write(this: v31.file, a2: (const void *)v20, a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v20 + 2), a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v20 + 4), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v20 + 8), a3: 4u);
                  v39 = *(_DWORD *)(v20 + 16);
                  v31.file->Write(this: v31.file, a2: &v39, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v20 + 12), a3: 8 * *(_DWORD *)(v20 + 16));
                  v40 = *(_DWORD *)(v20 + 32);
                  v31.file->Write(this: v31.file, a2: &v40, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v20 + 28), a3: 8 * *(_DWORD *)(v20 + 32));
                  v41 = *(_DWORD *)(v20 + 48);
                  v31.file->Write(this: v31.file, a2: &v41, a3: 4u);
                  v31.file->Write(this: v31.file, a2: *(const void **)(v20 + 44), a3: 2 * *(_DWORD *)(v20 + 48));
                  ++v18;
                  v19 += 60;
                }
                while ( v18 < p_x[13] );
              }
              break;
            case SWF_DICT_SPRITE:
              idSWFSprite::Write(this: v7->sprite, f: v31.file);
              break;
            case SWF_DICT_FONT:
              font = v7->font;
              idFile::WriteString(this: v31.file, string: font->fontID->name.str);
              v31.file->Write(this: v31.file, a2: &font->ascent, a3: 2u);
              v31.file->Write(this: v31.file, a2: &font->descent, a3: 2u);
              v31.file->Write(this: v31.file, a2: &font->leading, a3: 2u);
              v42 = font->glyphs.num;
              v31.file->Write(this: v31.file, a2: &v42, a3: 4u);
              v22 = 0;
              if ( font->glyphs.num > 0 )
              {
                v23 = 0;
                do
                {
                  v31.file->Write(this: v31.file, a2: &font->glyphs.list[v23], a3: 2u);
                  v31.file->Write(this: v31.file, a2: &font->glyphs.list[v23].advance, a3: 2u);
                  v43 = font->glyphs.list[v23].verts.num;
                  v31.file->Write(this: v31.file, a2: &v43, a3: 4u);
                  v31.file->Write(
                    this: v31.file,
                    a2: font->glyphs.list[v23].verts.list,
                    a3: 8 * font->glyphs.list[v23].verts.num);
                  v44 = font->glyphs.list[v23].indices.num;
                  v31.file->Write(this: v31.file, a2: &v44, a3: 4u);
                  v31.file->Write(
                    this: v31.file,
                    a2: font->glyphs.list[v23].indices.list,
                    a3: 2 * font->glyphs.list[v23].indices.num);
                  ++v22;
                  ++v23;
                }
                while ( v22 < font->glyphs.num );
              }
              break;
            case SWF_DICT_TEXT:
              v24 = (_DWORD *)&v7->text->bounds.tl.x;
              v31.file->Write(this: v31.file, a2: v24, a3: 8u);
              v31.file->Write(this: v31.file, a2: v24 + 2, a3: 8u);
              v31.file->Write(this: v31.file, a2: v24 + 4, a3: 24u);
              v45 = v24[11];
              v31.file->Write(this: v31.file, a2: &v45, a3: 4u);
              v25 = 0;
              if ( (int)v24[11] > 0 )
              {
                v26 = 0;
                do
                {
                  v27 = v26 + v24[10];
                  v31.file->Write(this: v31.file, a2: (const void *)v27, a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 2), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 6), a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 8), a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 10), a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 12), a3: 2u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v27 + 14), a3: 1u);
                  ++v25;
                  v26 += 16;
                }
                while ( v25 < v24[11] );
              }
              v46 = v24[15];
              v31.file->Write(this: v31.file, a2: &v46, a3: 4u);
              v28 = 0;
              if ( (int)v24[15] > 0 )
              {
                v29 = 0;
                do
                {
                  v31.file->Write(this: v31.file, a2: (const void *)(v24[14] + v29), a3: 4u);
                  v31.file->Write(this: v31.file, a2: (const void *)(v24[14] + v29 + 4), a3: 4u);
                  ++v28;
                  v29 += 8;
                }
                while ( v28 < v24[15] );
              }
              break;
            case SWF_DICT_IMAGE:
              material = v7->material;
              if ( material != nullptr )
                str = material->name.str;
              else
                str = ".";
              idFile::WriteString(this: v31.file, string: str);
              for ( i = 0; i < 2; ++i )
              {
                v31.file->Write(
                  this: v31.file,
                  a2: (char *)&this->dictionary.list->imageSize + 4 * v6 + 4 * i - 44,
                  a3: 4u);
                v31.file->Write(this: v31.file, a2: (char *)this->dictionary.list + 4 * v6 + 4 * i - 8, a3: 4u);
              }
              for ( j = 0; j < 4; ++j )
                v31.file->Write(this: v31.file, a2: (char *)this->dictionary.list + 4 * v6 + 4 * j, a3: 4u);
              break;
            default:
              edittext = (const char **)v7->edittext;
              v31.file->Write(this: v31.file, a2: edittext, a3: 8u);
              v31.file->Write(this: v31.file, a2: edittext + 2, a3: 8u);
              v31.file->Write(this: v31.file, a2: edittext + 4, a3: 4u);
              v31.file->Write(this: v31.file, a2: edittext + 5, a3: 2u);
              v31.file->Write(this: v31.file, a2: (char *)edittext + 22, a3: 2u);
              v31.file->Write(this: v31.file, a2: edittext + 6, a3: 4u);
              v31.file->Write(this: v31.file, a2: edittext + 7, a3: 2u);
              v31.file->Write(this: v31.file, a2: edittext + 8, a3: 4u);
              v31.file->Write(this: v31.file, a2: edittext + 9, a3: 2u);
              v31.file->Write(this: v31.file, a2: (char *)edittext + 38, a3: 2u);
              v31.file->Write(this: v31.file, a2: edittext + 10, a3: 2u);
              v31.file->Write(this: v31.file, a2: (char *)edittext + 42, a3: 2u);
              idFile::WriteString(this: v31.file, string: edittext[11]);
              idFile::WriteString(this: v31.file, string: edittext[12]);
              break;
          }
        }
        ++v4;
        v6 += 15;
        ++v5;
      }
      while ( v4 < this->dictionary.num );
    }
  }
  idFileLocal::~idFileLocal(this: &v31);
}


// ========================================================================
// __unwind$222704
// EA  : 0x82774654
// RVA : 0x00774654
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_222704()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 256 + 80));
}


// ========================================================================
// ?LoadBinary@idSWF@@AAA_NPBD@Z
// EA  : 0x82774C78
// RVA : 0x00774C78
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

int __fastcall idSWF::LoadBinary(idSWF *this, char *bfilename)
{
  idSWF *v2; // r24
  idFileResource *v4; // r27
  idFile_Memory *File; // r30
  idFile_Memory_vtbl *v7; // r11
  idList<idSWFDictionaryEntry,72> *p_dictionary; // r21
  int num; // r5
  int v10; // r19
  int v11; // r18
  int i; // r29
  int j; // r29
  idSWFShape *v14; // r3
  idSWFShape *v15; // r10
  idSWFShape *shape; // r27
  int v17; // r23
  int v18; // r24
  idSWFShapeDrawFill *v19; // r29
  int v20; // r26
  unsigned __int8 *p_endRatio; // r28
  int v22; // r28
  int v23; // r26
  idSWFShapeDrawLine *v24; // r29
  idSWFSprite *v25; // r3
  idSWFSprite *v26; // r3
  _WORD *v27; // r3
  idSWFFont *font; // r26
  idList<idSWFFontGlyph,72> *p_glyphs; // r28
  int v30; // r27
  int v31; // r29
  idSWFText *v32; // r3
  idSWFText *v33; // r10
  idSWFText *text; // r28
  int v35; // r27
  int v36; // r26
  idSWFTextRecord *v37; // r29
  idList<swfGlyphEntry_t,72> *v38; // r26
  int v39; // r27
  int v40; // r29
  float *v41; // r3
  float *v42; // r11
  idAtomicString *edittext; // r29
  int v44; // r10
  int v45; // [sp+50h] [-140h] BYREF
  int v46; // [sp+54h] [-13Ch] BYREF
  int v47; // [sp+58h] [-138h] BYREF
  int v48; // [sp+5Ch] [-134h]
  idDeclInfoTemplate<idMaterial> *v49; // [sp+60h] [-130h]
  idTypedResourceList<idFont> *v50; // [sp+64h] [-12Ch]
  idFileResource *v51; // [sp+68h] [-128h]
  char *v52; // [sp+70h] [-120h]
  int v53; // [sp+74h] [-11Ch]
  idStr v54; // [sp+80h] [-110h] BYREF
  idStr v55; // [sp+A0h] [-F0h] BYREF
  idStr v56; // [sp+C0h] [-D0h] BYREF

  v2 = this;
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 15u);
  v4 = (idFileResource *)idResourceList::Load(
                           this: &idFileResource::resourceList,
                           name: bfilename,
                           makeDefault: true,
                           skipStaleCheck: false);
  v51 = v4;
  if ( v4 == nullptr )
    return 0;
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  File = idFileResource::GetFile(this: v4);
  if ( (int)File->Length(this: File) <= 0 )
  {
    ((void (__fastcall *)(idFile_Memory *, int))File->dtr_idFile)(a1: File, a2: 1);
    return 0;
  }
  v47 = 0;
  v46 = 0;
  v56.allocedAndFlag = 20;
  v56.data = v56.baseBuffer;
  v56.len = 0;
  v56.baseBuffer[0] = 0;
  File->Read(this: File, a2: &v47, a3: 4u);
  File->Read(this: File, a2: &v46, a3: 4u);
  if ( idLib::production != PROD_DEVELOPMENT || v2->timestamp == v46 )
  {
    v7 = File->__vftable;
    if ( v47 == 1112758032 )
    {
      v7->Read(this: File, a2: &v2->frameWidth, a3: 4u);
      File->Read(this: File, a2: &v2->frameHeight, a3: 4u);
      File->Read(this: File, a2: &v2->frameRate, a3: 2u);
      if ( idSWF::mouseX == -1 )
      {
        v53 = (int)(float)(v2->frameWidth * (float)0.5);
        idSWF::mouseX = v53;
      }
      if ( idSWF::mouseY == -1 )
      {
        v53 = (int)(float)(v2->frameHeight * (float)0.5);
        idSWF::mouseY = v53;
      }
      File->Read(this: File, a2: &v2->atlasWidth, a3: 4u);
      File->Read(this: File, a2: &v2->atlasHeight, a3: 4u);
      idSWFSprite::Read(this: v2->mainsprite, f: File);
      v45 = 0;
      File->Read(this: File, a2: &v45, a3: 4u);
      p_dictionary = &v2->dictionary;
      idList<idSWFDictionaryEntry,72>::SetNum(this: &v2->dictionary, newNum: v45);
      num = v2->dictionary.num;
      v48 = 0;
      if ( num > 0 )
      {
        v10 = 0;
        v50 = &idFont::resourceList;
        v11 = 11;
        v49 = &idMaterial::resourceList;
        do
        {
          File->Read(this: File, a2: &p_dictionary->list[v10], a3: 4u);
          if ( (unsigned int)(p_dictionary->list[v10].type - 1) <= 6 )
          {
            switch ( p_dictionary->list[v10].type )
            {
              case SWF_DICT_SHAPE:
              case SWF_DICT_MORPH:
                v14 = (idSWFShape *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x40u,
                                      tag: TAG_SWF,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
                v52 = (char *)v14;
                if ( v14 != nullptr )
                  v15 = idSWFShape::idSWFShape(this: v14);
                else
                  v15 = nullptr;
                p_dictionary->list[v10].shape = v15;
                shape = p_dictionary->list[v10].shape;
                File->Read(this: File, a2: shape, a3: 8u);
                File->Read(this: File, a2: &shape->startBounds.br, a3: 8u);
                File->Read(this: File, a2: &shape->endBounds, a3: 8u);
                File->Read(this: File, a2: &shape->endBounds.br, a3: 8u);
                File->Read(this: File, a2: &v45, a3: 4u);
                idList<idSWFShapeDrawFill,72>::SetNum(this: &shape->fillDraws, newNum: v45);
                v17 = 0;
                if ( shape->fillDraws.num > 0 )
                {
                  v18 = 0;
                  do
                  {
                    v19 = &shape->fillDraws.list[v18];
                    File->Read(this: File, a2: v19, a3: 1u);
                    File->Read(this: File, a2: &v19->style.subType, a3: 1u);
                    File->Read(this: File, a2: &v19->style.startColor, a3: 4u);
                    File->Read(this: File, a2: &v19->style.endColor, a3: 4u);
                    File->Read(this: File, a2: &v19->style.startMatrix, a3: 24u);
                    File->Read(this: File, a2: &v19->style.endMatrix, a3: 24u);
                    File->Read(this: File, a2: &v19->style.gradient, a3: 1u);
                    v20 = 0;
                    if ( v19->style.gradient.numGradients != 0 )
                    {
                      p_endRatio = &v19->style.gradient.gradientRecords[0].endRatio;
                      do
                      {
                        File->Read(this: File, a2: p_endRatio - 1, a3: 1u);
                        File->Read(this: File, a2: p_endRatio, a3: 1u);
                        File->Read(this: File, a2: p_endRatio + 1, a3: 4u);
                        File->Read(this: File, a2: p_endRatio + 5, a3: 4u);
                        ++v20;
                        p_endRatio += 10;
                      }
                      while ( v20 < v19->style.gradient.numGradients );
                    }
                    File->Read(this: File, a2: &v19->style.focalPoint, a3: 4u);
                    File->Read(this: File, a2: &v19->style.bitmapID, a3: 2u);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<idVec2,72>::SetNum(this: &v19->startVerts, newNum: v45);
                    File->Read(this: File, a2: v19->startVerts.list, a3: 8 * v19->startVerts.num);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<idVec2,72>::SetNum(this: &v19->endVerts, newNum: v45);
                    File->Read(this: File, a2: v19->endVerts.list, a3: 8 * v19->endVerts.num);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<unsigned short,115>::SetNum(this: &v19->indices, newNum: v45);
                    File->Read(this: File, a2: v19->indices.list, a3: 2 * v19->indices.num);
                    ++v17;
                    ++v18;
                  }
                  while ( v17 < shape->fillDraws.num );
                  v2 = this;
                }
                File->Read(this: File, a2: &v45, a3: 4u);
                idList<idSWFShapeDrawLine,72>::SetNum(this: &shape->lineDraws, newNum: v45);
                v22 = 0;
                if ( shape->lineDraws.num > 0 )
                {
                  v23 = 0;
                  do
                  {
                    v24 = &shape->lineDraws.list[v23];
                    File->Read(this: File, a2: v24, a3: 2u);
                    File->Read(this: File, a2: &v24->style.endWidth, a3: 2u);
                    File->Read(this: File, a2: &v24->style.startColor, a3: 4u);
                    File->Read(this: File, a2: &v24->style.endColor, a3: 4u);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<idVec2,72>::SetNum(this: &v24->startVerts, newNum: v45);
                    File->Read(this: File, a2: v24->startVerts.list, a3: 8 * v24->startVerts.num);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<idVec2,72>::SetNum(this: &v24->endVerts, newNum: v45);
                    File->Read(this: File, a2: v24->endVerts.list, a3: 8 * v24->endVerts.num);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<unsigned short,115>::SetNum(this: &v24->indices, newNum: v45);
                    File->Read(this: File, a2: v24->indices.list, a3: 2 * v24->indices.num);
                    ++v22;
                    ++v23;
                  }
                  while ( v22 < shape->lineDraws.num );
                }
                break;
              case SWF_DICT_SPRITE:
                v25 = (idSWFSprite *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x4Cu,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
                v52 = (char *)v25;
                if ( v25 != nullptr )
                  v26 = idSWFSprite::idSWFSprite(this: v25, _swf: v2);
                else
                  v26 = nullptr;
                p_dictionary->list[v10].sprite = v26;
                idSWFSprite::Read(this: p_dictionary->list[v10].sprite, f: File);
                break;
              case SWF_DICT_FONT:
                v27 = idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x1Cu,
                        tag: TAG_SWF,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
                if ( v27 != nullptr )
                {
                  *(_DWORD *)v27 = 0;
                  v27[2] = 0;
                  v27[3] = 0;
                  v27[4] = 0;
                  v27[12] = 0;
                  *((_BYTE *)v27 + 26) = 72;
                  *((_BYTE *)v27 + 27) = 0;
                  *((_DWORD *)v27 + 3) = 0;
                  *((_DWORD *)v27 + 5) = 0;
                  *((_DWORD *)v27 + 4) = 0;
                  v52 = (char *)(v27 + 6);
                }
                else
                {
                  v27 = nullptr;
                }
                p_dictionary->list[v10].font = (idSWFFont *)v27;
                font = p_dictionary->list[v10].font;
                v55.allocedAndFlag = 20;
                v55.data = v55.baseBuffer;
                v55.len = 0;
                v55.baseBuffer[0] = 0;
                idFile::ReadString(this: File, string: &v55);
                font->fontID = (const idFont *)idResourceList::Load(
                                                 this: v50,
                                                 name: v55.data,
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
                File->Read(this: File, a2: &font->ascent, a3: 2u);
                File->Read(this: File, a2: &font->descent, a3: 2u);
                File->Read(this: File, a2: &font->leading, a3: 2u);
                File->Read(this: File, a2: &v45, a3: 4u);
                p_glyphs = &font->glyphs;
                idList<idSWFFontGlyph,72>::SetNum(this: &font->glyphs, newNum: v45);
                v30 = 0;
                if ( font->glyphs.num > 0 )
                {
                  v31 = 0;
                  do
                  {
                    File->Read(this: File, a2: &p_glyphs->list[v31], a3: 2u);
                    File->Read(this: File, a2: &p_glyphs->list[v31].advance, a3: 2u);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<idVec2,72>::SetNum(this: &p_glyphs->list[v31].verts, newNum: v45);
                    File->Read(this: File, a2: p_glyphs->list[v31].verts.list, a3: 8 * p_glyphs->list[v31].verts.num);
                    File->Read(this: File, a2: &v45, a3: 4u);
                    idList<unsigned short,115>::SetNum(this: &p_glyphs->list[v31].indices, newNum: v45);
                    File->Read(
                      this: File,
                      a2: p_glyphs->list[v31].indices.list,
                      a3: 2 * p_glyphs->list[v31].indices.num);
                    ++v30;
                    ++v31;
                  }
                  while ( v30 < font->glyphs.num );
                }
                idStr::FreeData(this: &v55);
                break;
              case SWF_DICT_TEXT:
                v32 = (idSWFText *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x48u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
                v52 = (char *)v32;
                if ( v32 != nullptr )
                  v33 = idSWFText::idSWFText(this: v32);
                else
                  v33 = nullptr;
                p_dictionary->list[v10].text = v33;
                text = p_dictionary->list[v10].text;
                File->Read(this: File, a2: text, a3: 8u);
                File->Read(this: File, a2: &text->bounds.br, a3: 8u);
                File->Read(this: File, a2: &text->matrix, a3: 24u);
                File->Read(this: File, a2: &v45, a3: 4u);
                idList<idSWFTextRecord,72>::SetNum(this: &text->textRecords, newNum: v45);
                v35 = 0;
                if ( text->textRecords.num > 0 )
                {
                  v36 = 0;
                  do
                  {
                    v37 = &text->textRecords.list[v36];
                    File->Read(this: File, a2: v37, a3: 2u);
                    File->Read(this: File, a2: &v37->color, a3: 4u);
                    File->Read(this: File, a2: &v37->xOffset, a3: 2u);
                    File->Read(this: File, a2: &v37->yOffset, a3: 2u);
                    File->Read(this: File, a2: &v37->textHeight, a3: 2u);
                    File->Read(this: File, a2: &v37->firstGlyph, a3: 2u);
                    File->Read(this: File, a2: &v37->numGlyphs, a3: 1u);
                    ++v35;
                    ++v36;
                  }
                  while ( v35 < text->textRecords.num );
                }
                File->Read(this: File, a2: &v45, a3: 4u);
                v38 = &text->glyphs;
                idList<idActorModifierTimer,5>::SetNum(this: &text->glyphs, newNum: v45);
                v39 = 0;
                if ( text->glyphs.num > 0 )
                {
                  v40 = 0;
                  do
                  {
                    File->Read(this: File, a2: &v38->list[v40], a3: 4u);
                    File->Read(this: File, a2: &v38->list[v40].advance, a3: 4u);
                    ++v39;
                    ++v40;
                  }
                  while ( v39 < text->glyphs.num );
                }
                break;
              case SWF_DICT_IMAGE:
                v54.allocedAndFlag = 20;
                v54.len = 0;
                v54.data = v54.baseBuffer;
                v54.baseBuffer[0] = 0;
                idFile::ReadString(this: File, string: &v54);
                if ( *v54.data == 46 )
                  p_dictionary->list[v10].material = nullptr;
                else
                  p_dictionary->list[v10].material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                           this: v49,
                                                                           name: v54.data,
                                                                           makeDefault: true);
                for ( i = 0; i < 2; ++i )
                {
                  File->Read(this: File, a2: (char *)&p_dictionary->list->imageSize + 4 * v11 + 4 * i - 44, a3: 4u);
                  File->Read(this: File, a2: (char *)p_dictionary->list + 4 * v11 + 4 * i - 8, a3: 4u);
                }
                for ( j = 0; j < 4; ++j )
                  File->Read(this: File, a2: &p_dictionary->list->type + v11 + j, a3: 4u);
                idStr::FreeData(this: &v54);
                break;
              default:
                v41 = (float *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x34u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
                if ( v41 != nullptr )
                {
                  *v41 = 0.0;
                  v41[1] = 0.0;
                  v41[2] = 0.0;
                  v41[3] = 0.0;
                  *((_WORD *)v41 + 11) = 24;
                  v41[4] = 0.0;
                  *((_WORD *)v41 + 10) = 0;
                  *((_BYTE *)v41 + 24) = -1;
                  *((_BYTE *)v41 + 25) = -1;
                  v42 = v41;
                  *((_BYTE *)v41 + 26) = -1;
                  *((_BYTE *)v41 + 27) = -1;
                  *((_WORD *)v41 + 14) = -1;
                  v41[8] = 0.0;
                  *((_WORD *)v41 + 18) = 0;
                  *((_WORD *)v41 + 19) = 0;
                  *((_WORD *)v41 + 20) = 0;
                  *((_WORD *)v41 + 21) = 0;
                  v52 = (char *)(v41 + 12);
                  *((_DWORD *)v41 + 11) = &byte_8200D768;
                  *((_DWORD *)v41 + 12) = &byte_8200D768;
                }
                else
                {
                  v42 = nullptr;
                }
                p_dictionary->list[v10].edittext = (idSWFEditText *)v42;
                edittext = (idAtomicString *)p_dictionary->list[v10].edittext;
                File->Read(this: File, a2: edittext, a3: 8u);
                File->Read(this: File, a2: &edittext[2], a3: 8u);
                File->Read(this: File, a2: &edittext[4], a3: 4u);
                File->Read(this: File, a2: &edittext[5], a3: 2u);
                File->Read(this: File, a2: (char *)&edittext[5].str + 2, a3: 2u);
                File->Read(this: File, a2: &edittext[6], a3: 4u);
                File->Read(this: File, a2: &edittext[7], a3: 2u);
                File->Read(this: File, a2: &edittext[8], a3: 4u);
                File->Read(this: File, a2: &edittext[9], a3: 2u);
                File->Read(this: File, a2: (char *)&edittext[9].str + 2, a3: 2u);
                File->Read(this: File, a2: &edittext[10], a3: 2u);
                File->Read(this: File, a2: (char *)&edittext[10].str + 2, a3: 2u);
                idFile::ReadString(this: File, string: edittext + 11);
                idFile::ReadString(this: File, string: edittext + 12);
                break;
            }
          }
          v11 += 15;
          v44 = v2->dictionary.num;
          ++v10;
          ++v48;
        }
        while ( v48 < v44 );
        v4 = v51;
      }
      ((void (__fastcall *)(idFile_Memory *, int))File->dtr_idFile)(a1: File, a2: 1);
      ((void (__fastcall *)(idFileResource *, int))v4->dtr_idResource)(a1: v4, a2: 1);
      idStr::FreeData(this: &v56);
      return 1;
    }
    else
    {
      ((void (__fastcall *)(idFile_Memory *, int))v7->dtr_idFile)(a1: File, a2: 1);
      idStr::FreeData(this: &v56);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(idFile_Memory *, int))File->dtr_idFile)(a1: File, a2: 1);
    idStr::FreeData(this: &v56);
    return 0;
  }
}


// ========================================================================
// __unwind$225463
// EA  : 0x82775DE4
// RVA : 0x00775DE4
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225463()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 192));
}


// ========================================================================
// __unwind$225464
// EA  : 0x82775E0C
// RVA : 0x00775E0C
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225464()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$225465
// EA  : 0x82775E34
// RVA : 0x00775E34
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225465()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 400 + 112), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225466
// EA  : 0x82775E60
// RVA : 0x00775E60
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225466()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 400 + 112), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225467
// EA  : 0x82775E8C
// RVA : 0x00775E8C
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225467()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 400 + 224), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225468
// EA  : 0x82775EB8
// RVA : 0x00775EB8
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225468()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$225469
// EA  : 0x82775EE0
// RVA : 0x00775EE0
// PDB : w:\tech5\engine\guis\swf\swf_load.cpp
// ========================================================================

void _unwind_225469()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 400 + 112), tag: TAG_SWF);
}

