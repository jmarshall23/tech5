
// ========================================================================
// ?DefineEditText@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x827982F0
// RVA : 0x007982F0
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void __fastcall idSWF::DefineEditText(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r29
  const unsigned __int8 *v4; // r11
  idSWFDictionaryEntry *v5; // r3
  idSWFEditText *edittext; // r22
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // r6
  bool v9; // r23
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // r6
  unsigned int v12; // r3
  unsigned __int64 v13; // r8
  bool v14; // r16
  unsigned __int64 v15; // r6
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // r6
  bool v18; // r15
  unsigned __int64 v19; // r6
  bool v20; // r14
  unsigned __int64 v21; // r8
  unsigned int v22; // r3
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // r6
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // r6
  bool v27; // r26
  unsigned __int64 v28; // r6
  bool v29; // r25
  unsigned __int64 v30; // r8
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r6
  unsigned __int64 v33; // r8
  bool v34; // r27
  unsigned __int64 v35; // r6
  unsigned __int64 v36; // r6
  unsigned __int64 v37; // r8
  bool v38; // r24
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // r6
  unsigned __int64 v41; // r8
  unsigned __int64 v42; // r6
  unsigned __int64 v43; // r8
  unsigned __int64 v44; // r6
  unsigned __int64 v45; // r8
  unsigned __int64 v46; // r6
  unsigned __int64 v47; // r8
  unsigned __int64 v48; // r6
  unsigned __int64 v49; // r8
  int v50; // r6
  int v51; // r4
  int v52; // r5
  const unsigned __int8 *v53; // r11
  int v54; // r9
  const unsigned __int8 *v55; // r11
  const char *String; // r3
  const unsigned __int8 *readp; // r11
  int v58; // r9
  const unsigned __int8 *v59; // r11
  swfEditTextAlign_t v60; // r8
  const unsigned __int8 *v61; // r11
  const unsigned __int8 *v62; // r11
  const unsigned __int8 *v63; // r11
  const unsigned __int8 *v64; // r11
  int v65; // r9
  const char *v66; // r3
  unsigned __int64 v67; // r8
  int v68; // r6
  int v69; // r5
  int v70; // r4
  const char *v71; // r3
  const char *v72; // r27
  int v73; // r28
  char *v74; // r30
  int v75; // r11
  char v76; // r26
  char v77; // r30
  int i; // r11
  int v79; // r11
  int v80; // r10
  bool v81; // [sp+50h] [-110h]
  bool v82; // [sp+51h] [-10Fh]
  bool v83; // [sp+52h] [-10Eh]
  idStr v84; // [sp+60h] [-100h] BYREF
  idStr v85; // [sp+80h] [-E0h] BYREF
  idStr v86[6]; // [sp+A0h] [-C0h] BYREF

  LODWORD(v2) = 0;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  v5 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v4 - 1), 8) | *(v4 - 2)),
         type: SWF_DICT_EDITTEXT);
  if ( v5 != nullptr )
  {
    edittext = v5->edittext;
    idSWFBitStream::ReadRect(this: bitstream, rect: &edittext->bounds);
    bitstream->currentBit = v2;
    bitstream->currentByte = v2;
    v9 = idSWFBitStream::ReadU(this: bitstream, numBits: v8, a3: v7) != 0;
    v12 = idSWFBitStream::ReadU(this: bitstream, numBits: v11, a3: v10);
    LODWORD(v13) = v12 - 1;
    v14 = v12 != 0;
    HIDWORD(v16) = idSWFBitStream::ReadU(this: bitstream, numBits: v15, a3: v13);
    LODWORD(v17) = HIDWORD(v16) - 1;
    v18 = HIDWORD(v16) != 0;
    HIDWORD(v19) = idSWFBitStream::ReadU(this: bitstream, numBits: v17, a3: v16);
    v20 = HIDWORD(v19) != 0;
    v22 = idSWFBitStream::ReadU(this: bitstream, numBits: v19, a3: v21);
    LODWORD(v23) = v22 != 0;
    v83 = v22 != 0;
    HIDWORD(v25) = idSWFBitStream::ReadU(this: bitstream, numBits: v24, a3: v23);
    LODWORD(v26) = HIDWORD(v25) - 1;
    v27 = HIDWORD(v25) != 0;
    HIDWORD(v28) = idSWFBitStream::ReadU(this: bitstream, numBits: v26, a3: v25);
    v29 = HIDWORD(v28) != 0;
    HIDWORD(v2) = idSWFBitStream::ReadU(this: bitstream, numBits: v28, a3: v30) != 0;
    LODWORD(v33) = idSWFBitStream::ReadU(this: bitstream, numBits: v32, a3: v31);
    HIDWORD(v33) = v33 - 1;
    v34 = (_DWORD)v33 != 0;
    LODWORD(v36) = idSWFBitStream::ReadU(this: bitstream, numBits: v35, a3: v33);
    HIDWORD(v36) = v36 - 1;
    v82 = (_DWORD)v36 != 0;
    v38 = idSWFBitStream::ReadU(this: bitstream, numBits: v36, a3: v37) != 0;
    idSWFBitStream::ReadU(this: bitstream, numBits: v40, a3: v39);
    LODWORD(v43) = idSWFBitStream::ReadU(this: bitstream, numBits: v42, a3: v41);
    HIDWORD(v43) = v43 - 1;
    LODWORD(v44) = v43 != 0;
    v81 = (_DWORD)v43 != 0;
    idSWFBitStream::ReadU(this: bitstream, numBits: v44, a3: v43);
    idSWFBitStream::ReadU(this: bitstream, numBits: v46, a3: v45);
    idSWFBitStream::ReadU(this: bitstream, numBits: v48, a3: v47);
    v52 = BYTE3(v2);
    if ( BYTE3(v2) != 0 )
    {
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      v53 = bitstream->readp + 2;
      bitstream->readp = v53;
      v54 = __ROL4__(*(v53 - 1), 8);
      LODWORD(v49) = *(v53 - 2);
      HIDWORD(v49) = v54 | v49;
      edittext->fontID = v54 | v49;
      v55 = bitstream->readp + 2;
      bitstream->readp = v55;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      v52 = *(v55 - 2);
      v51 = *(v55 - 1);
      edittext->fontHeight = __ROL4__(v51, 8) | v52;
    }
    if ( v34 )
    {
      String = idSWFBitStream::ReadString(this: bitstream, a2: v51, a3: v52, a4: v50, a5: v49);
      idStr::idStr(this: v86, text: String);
      idStr::FreeData(this: v86);
    }
    if ( v27 )
      idSWFBitStream::ReadColorRGBA(this: bitstream, color: &edittext->color);
    if ( v29 )
    {
      readp = bitstream->readp;
      bitstream->currentBit = v2;
      readp += 2;
      bitstream->currentByte = v2;
      bitstream->readp = readp;
      v58 = __ROL4__(*(readp - 1), 8);
      LODWORD(v49) = *(readp - 2);
      HIDWORD(v49) = v58 | v49;
      edittext->maxLength = v58 | v49;
    }
    if ( v38 )
    {
      bitstream->currentBit = v2;
      v59 = bitstream->readp;
      bitstream->currentByte = v2;
      v60 = *v59;
      bitstream->readp = v59 + 1;
      edittext->align = v60;
      v61 = bitstream->readp;
      bitstream->currentBit = v2;
      v61 += 2;
      bitstream->currentByte = v2;
      bitstream->readp = v61;
      edittext->leftMargin = __ROL4__(*(v61 - 1), 8) | *(v61 - 2);
      v62 = bitstream->readp + 2;
      bitstream->readp = v62;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      edittext->rightMargin = __ROL4__(*(v62 - 1), 8) | *(v62 - 2);
      v63 = bitstream->readp + 2;
      bitstream->readp = v63;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      v52 = *(v63 - 2);
      v51 = *(v63 - 1);
      edittext->indent = __ROL4__(v51, 8) | v52;
      v64 = bitstream->readp + 2;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      bitstream->readp = v64;
      v65 = *(v64 - 2);
      LODWORD(v49) = *(v64 - 1);
      HIDWORD(v49) = __ROL4__(v49, 8);
      v50 = HIDWORD(v49) | v65;
      edittext->leading = WORD1(v49) | v65;
    }
    v66 = idSWFBitStream::ReadString(this: bitstream, a2: v51, a3: v52, a4: v50, a5: v49);
    idAtomicString::Set(this: &edittext->variable, str_: v66);
    if ( v9 )
    {
      v71 = idSWFBitStream::ReadString(this: bitstream, a2: v70, a3: v69, a4: v68, a5: v67);
      v85.baseBuffer[0] = 0;
      v85.allocedAndFlag = 20;
      v72 = v71;
      v85.data = v85.baseBuffer;
      v85.len = 0;
      v73 = 0;
      if ( *v71 != 0 )
      {
        v74 = (char *)v71;
        do
        {
          if ( *v74 == 60 )
          {
            if ( v73 != 0 && v72[v73 + 1] == 112 )
              idStr::Append(this: &v85, a: 10);
            v75 = *v74;
            if ( *v74 != 0 )
            {
              do
              {
                if ( v75 == 62 )
                  break;
                v75 = v72[++v73];
              }
              while ( v72[v73] != 0 );
            }
          }
          else
          {
            v76 = *v74;
            if ( *v74 == 38 )
            {
              v84.allocedAndFlag = 20;
              v84.len = 0;
              v84.data = v84.baseBuffer;
              v84.baseBuffer[0] = 0;
              v77 = v72[++v73];
              for ( i = v77; v77 != 0; i = v77 )
              {
                if ( i == 59 )
                  break;
                idStr::EnsureAlloced(this: &v84, amount: v84.len + 2, keepold: true, geometricGrowth: true);
                ++v73;
                v84.data[v84.len++] = v77;
                v84.data[v84.len] = 0;
                v77 = v72[v73];
              }
              if ( idStr::Icmp(s1: v84.data, s2: "amp") != 0 )
              {
                if ( idStr::Icmp(s1: v84.data, s2: "apos") != 0 )
                {
                  if ( idStr::Icmp(s1: v84.data, s2: "lt") != 0 )
                  {
                    if ( idStr::Icmp(s1: v84.data, s2: "gt") != 0 )
                    {
                      if ( idStr::Icmp(s1: v84.data, s2: "quot") == 0 )
                        v76 = 34;
                    }
                    else
                    {
                      v76 = 62;
                    }
                  }
                  else
                  {
                    v76 = 60;
                  }
                }
                else
                {
                  v76 = 39;
                }
              }
              else
              {
                v76 = 38;
              }
              idStr::FreeData(this: &v84);
            }
            v79 = v85.len + 2;
            v80 = v85.allocedAndFlag & 0x7FFFFFFF;
            if ( v85.allocedAndFlag >= 0 )
            {
              if ( v79 > v80 )
                idStr::ReAllocate(this: &v85, amount: (v79 >> 1) + v79, keepold: true);
            }
            else if ( v79 > v80
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            v85.data[v85.len++] = v76;
            v85.data[v85.len] = 0;
          }
          v74 = (char *)&v72[++v73];
        }
        while ( v72[v73] != 0 );
      }
      idAtomicString::Set(this: &edittext->initialText, str_: v85.data);
      idStr::FreeData(this: &v85);
    }
    edittext->flags |= (!v81 ? 0 : 0x20) | (!v82 ? 0 : 0x10) | (!v83 ? 0 : 8) | (!v20 ? 0 : 4) | (!v18 ? 0 : 2) | v14;
  }
}


// ========================================================================
// __unwind$220110
// EA  : 0x827989A8
// RVA : 0x007989A8
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void _unwind_220110()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$220111
// EA  : 0x827989D0
// RVA : 0x007989D0
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void _unwind_220111()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 96));
}


// ========================================================================
// ?DefineTextX@idSWF@@AAAXAAVidSWFBitStream@@_N@Z
// EA  : 0x82798B40
// RVA : 0x00798B40
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void __fastcall idSWF::DefineTextX(idSWF *this, idSWFBitStream *bitstream, bool rgba)
{
  unsigned __int64 v3; // r28
  const unsigned __int8 *v5; // r11
  idSWFDictionaryEntry *v7; // r3
  idSWFText *text; // r23
  const unsigned __int8 *readp; // r11
  int v10; // r30
  idSWFTextRecord *v11; // r3
  const unsigned __int8 *v12; // r11
  swfColorRGBA_t *p_color; // r4
  const unsigned __int8 *v14; // r11
  const unsigned __int8 *v15; // r11
  const unsigned __int8 *v16; // r11
  int v17; // r26
  const unsigned __int8 *v18; // r11
  int v19; // r8
  idList<swfGlyphEntry_t,72> *p_glyphs; // r30
  unsigned __int64 v21; // r8
  unsigned __int64 v22; // r6
  int num; // r11
  int size; // r10
  unsigned int *p_index; // r29
  unsigned __int64 v26; // r8
  unsigned __int64 v27; // r6
  const unsigned __int8 *v28; // r11

  LODWORD(v3) = 0;
  v5 = bitstream->readp + 2;
  bitstream->currentBit = v3;
  bitstream->currentByte = v3;
  bitstream->readp = v5;
  v7 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v5 - 1), 8) | *(v5 - 2)),
         type: SWF_DICT_TEXT);
  if ( v7 != nullptr )
  {
    text = v7->text;
    idSWFBitStream::ReadRect(this: bitstream, rect: &text->bounds);
    idSWFBitStream::ReadMatrix(this: bitstream, matrix: &text->matrix);
    readp = bitstream->readp;
    bitstream->currentBit = v3;
    bitstream->currentByte = v3;
    bitstream->readp = readp + 1;
    bitstream->currentBit = v3;
    bitstream->currentByte = v3;
    bitstream->readp = readp + 2;
    bitstream->currentBit = v3;
    bitstream->currentByte = v3;
    v10 = readp[2];
    for ( bitstream->readp = readp + 3; v10 != 0; bitstream->readp = v28 + 1 )
    {
      v11 = idList<idSWFTextRecord,72>::Alloc(this: &text->textRecords);
      HIDWORD(v3) = v11;
      if ( (v10 & 8) != 0 )
      {
        bitstream->currentBit = v3;
        bitstream->currentByte = v3;
        v12 = bitstream->readp + 2;
        bitstream->readp = v12;
        v11->fontID = __ROL4__(*(v12 - 1), 8) | *(v12 - 2);
      }
      if ( (v10 & 4) != 0 )
      {
        p_color = &v11->color;
        if ( rgba )
          idSWFBitStream::ReadColorRGBA(this: bitstream, color: p_color);
        else
          idSWFBitStream::ReadColorRGB(this: bitstream, color: p_color);
      }
      if ( (v10 & 1) != 0 )
      {
        bitstream->currentBit = v3;
        bitstream->currentByte = v3;
        v14 = bitstream->readp + 2;
        bitstream->readp = v14;
        *(_WORD *)(HIDWORD(v3) + 6) = __ROL4__(*(v14 - 1), 8) | *(v14 - 2);
      }
      if ( (v10 & 2) != 0 )
      {
        v15 = bitstream->readp;
        bitstream->currentBit = v3;
        v15 += 2;
        bitstream->currentByte = v3;
        bitstream->readp = v15;
        *(_WORD *)(HIDWORD(v3) + 8) = __ROL4__(*(v15 - 1), 8) | *(v15 - 2);
      }
      if ( (v10 & 8) != 0 )
      {
        v16 = bitstream->readp;
        bitstream->currentBit = v3;
        v16 += 2;
        bitstream->currentByte = v3;
        bitstream->readp = v16;
        *(_WORD *)(HIDWORD(v3) + 10) = __ROL4__(*(v16 - 1), 8) | *(v16 - 2);
      }
      v17 = 0;
      *(_WORD *)(HIDWORD(v3) + 12) = text->glyphs.num;
      bitstream->currentBit = v3;
      bitstream->currentByte = v3;
      v18 = bitstream->readp;
      v19 = *v18;
      bitstream->readp = v18 + 1;
      *(_BYTE *)(HIDWORD(v3) + 14) = v19;
      if ( v19 != 0 )
      {
        p_glyphs = &text->glyphs;
        do
        {
          idList<swfGlyphEntry_t,72>::PreAllocateWithGranularity(this: &text->glyphs, newSize: text->glyphs.num + 1);
          num = text->glyphs.num;
          size = text->glyphs.size;
          if ( num >= size )
          {
            p_index = &p_glyphs->list[size - 1].index;
          }
          else
          {
            p_index = &p_glyphs->list[num].index;
            text->glyphs.num = num + 1;
          }
          *p_index = idSWFBitStream::ReadU(this: bitstream, numBits: v22, a3: v21);
          ++v17;
          p_index[1] = idSWFBitStream::ReadS(this: bitstream, numBits: v27, a3: v26);
        }
        while ( v17 < *(unsigned __int8 *)(HIDWORD(v3) + 14) );
      }
      bitstream->currentBit = v3;
      bitstream->currentByte = v3;
      v28 = bitstream->readp;
      v10 = *v28;
    }
  }
}


// ========================================================================
// ?DefineText@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82798DE0
// RVA : 0x00798DE0
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void __fastcall idSWF::DefineText(idSWF *this, idSWFBitStream *bitstream)
{
  idSWF::DefineTextX(this, bitstream, rgba: false);
}


// ========================================================================
// ?DefineText2@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82798DE8
// RVA : 0x00798DE8
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void __fastcall idSWF::DefineText2(idSWF *this, idSWFBitStream *bitstream)
{
  idSWF::DefineTextX(this, bitstream, rgba: true);
}


// ========================================================================
// ?DefineFont2@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82798DF8
// RVA : 0x00798DF8
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void __fastcall idSWF::DefineFont2(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r29
  const unsigned __int8 *v4; // r11
  idSWFDictionaryEntry *v5; // r25
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  const unsigned __int8 *readp; // r11
  unsigned __int64 v11; // r10
  unsigned __int8 v12; // r27
  const unsigned __int8 *Data; // r3
  const unsigned __int8 *v14; // r11
  unsigned __int64 v15; // r10
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  unsigned __int8 v20; // r24
  int v21; // r11
  unsigned int v22; // r27
  const unsigned __int8 *v23; // r3
  const unsigned __int8 *v24; // r10
  const unsigned __int8 *v25; // r11
  unsigned __int64 v26; // r10
  int v27; // r27
  int v28; // r8
  int v29; // r6
  int v30; // r5
  int v31; // r26
  idSWFBitStream *v32; // r3
  int v33; // r26
  const unsigned __int8 *v34; // r3
  const unsigned __int8 *v35; // r10
  const unsigned __int8 *v36; // r11
  int v37; // r27
  unsigned __int64 v38; // r10
  int v39; // r8
  int v40; // r7
  int v41; // r9
  int v42; // r10
  const unsigned __int8 *v43; // r11
  int v44; // r10
  int v45; // r11
  const unsigned __int8 *v46; // r9
  unsigned __int16 v47; // r7
  const unsigned __int8 *v48; // r11
  int v49; // r10
  const unsigned __int8 *v50; // r11
  const unsigned __int8 *v51; // r11
  int v52; // r9
  const unsigned __int8 *v53; // r11
  idSWFFontGlyph *v54; // r4
  int v55; // r27
  const unsigned __int8 *v56; // r11
  const unsigned __int8 *v57; // r11
  int v58; // r8
  int v59; // r10
  idSWFBitStream v60; // [sp+50h] [-1B0h] BYREF
  idSWFBitStream v61; // [sp+70h] [-190h] BYREF
  swfRect_t v62; // [sp+90h] [-170h] BYREF
  char v63[272]; // [sp+A0h] [-160h] BYREF

  LODWORD(v2) = 0;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  v5 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v4 - 1), 8) | *(v4 - 2)),
         type: SWF_DICT_FONT);
  if ( v5 != nullptr )
  {
    readp = bitstream->readp;
    bitstream->currentBit = v2;
    bitstream->currentByte = v2;
    LODWORD(v11) = readp + 2;
    HIDWORD(v11) = readp + 3;
    v12 = *readp;
    bitstream->currentBit = v2;
    bitstream->readp = readp + 2;
    bitstream->currentByte = v2;
    HIDWORD(v2) = readp[2];
    bitstream->readp = readp + 3;
    Data = idSWFBitStream::ReadData(this: bitstream, size: SHIDWORD(v2), a3: v9, a4: v8, a5: v7, a6: v6, a7: v11);
    memcpy(Dst: v63, Src: Data, Size: HIDWORD(v2));
    v63[HIDWORD(v2)] = 0;
    v5->font->fontID = (const idFont *)idResourceList::Load(
                                         this: &idFont::resourceList,
                                         name: v63,
                                         makeDefault: true,
                                         skipStaleCheck: false);
    v14 = bitstream->readp + 2;
    bitstream->currentBit = v2;
    bitstream->currentByte = v2;
    bitstream->readp = v14;
    HIDWORD(v2) = (unsigned __int16)(__ROL4__(*(v14 - 1), 8) | *(v14 - 2));
    idList<idSWFFontGlyph,72>::SetNum(this: &v5->font->glyphs, newNum: SHIDWORD(v2));
    if ( HIDWORD(v2) == 0 )
    {
      idLib::Warning(fmt: "idSWF::DefineFont2: numglyphs = 0 exiting");
      return;
    }
    v20 = v12;
    v21 = HIDWORD(v2) + 1;
    if ( (v12 & 8) != 0 )
    {
      v22 = 4 * v21;
      v23 = idSWFBitStream::ReadData(this: bitstream, size: 4 * v21, a3: v19, a4: v18, a5: v17, a6: v16, a7: v15);
      v60.free = false;
      idSWFBitStream::Load(this: &v60, data: v23, len: v22, copy: false);
      v24 = v60.readp;
      v60.currentBit = v2;
      v25 = v60.readp + 4;
      v60.currentByte = v2;
      v60.readp += 4;
      if ( (((((__ROL4__(v24[3], 8) | v24[2]) << 8) | v24[1]) << 8) | *v24) != v22 )
      {
        idLib::Warning(fmt: "idSWF::DefineFont2: first glyph offset != offsetTableSize");
        idSWFBitStream::Free(this: &v60);
        return;
      }
      LODWORD(v26) = v22;
      v27 = 0;
      while ( 1 )
      {
        v60.currentBit = v2;
        v60.currentByte = v2;
        v60.readp = v25 + 4;
        v28 = *v25;
        v29 = __ROL4__(v25[3], 8);
        v30 = v29 | v25[2];
        HIDWORD(v26) = (v30 << 8) | v25[1];
        v31 = (HIDWORD(v26) << 8) | v28;
        idSWFBitStream::ReadData(
          this: bitstream,
          size: v31 - v26,
          a3: v30,
          a4: v29,
          a5: HIDWORD(v26) << 8,
          a6: v28,
          a7: v26);
        ++v27;
        LODWORD(v26) = v31;
        if ( v27 >= SHIDWORD(v2) )
          break;
        v25 = v60.readp;
      }
      v32 = &v60;
    }
    else
    {
      v33 = (2 * v21) & 0xFFFE;
      v34 = idSWFBitStream::ReadData(this: bitstream, size: v33, a3: v19, a4: v18, a5: v17, a6: v16, a7: v15);
      v61.free = false;
      idSWFBitStream::Load(this: &v61, data: v34, len: v33, copy: false);
      v35 = v61.readp;
      v61.currentBit = v2;
      v36 = v61.readp + 2;
      v61.currentByte = v2;
      v61.readp += 2;
      if ( (__ROL4__(v35[1], 8) | *v35) != v33 )
      {
        idLib::Warning(fmt: "idSWF::DefineFont2: first glyph offset != offsetTableSize");
        idSWFBitStream::Free(this: &v61);
        return;
      }
      v37 = 0;
      while ( 1 )
      {
        v61.currentByte = v2;
        v61.currentBit = v2;
        LODWORD(v38) = (unsigned __int16)v33;
        v61.readp = v36 + 2;
        v39 = v36[1];
        v40 = __ROL4__(v39, 8);
        HIDWORD(v38) = *v36;
        v33 = (unsigned __int16)(v40 | WORD1(v38));
        idSWFBitStream::ReadData(
          this: bitstream,
          size: (unsigned __int16)(v33 - v38),
          a3: v33 - v38,
          a4: v40 | HIDWORD(v38),
          a5: v40,
          a6: v39,
          a7: v38);
        if ( ++v37 >= SHIDWORD(v2) )
          break;
        v36 = v61.readp;
      }
      v32 = &v61;
    }
    idSWFBitStream::Free(this: v32);
    if ( (v20 & 4) != 0 )
    {
      v41 = 0;
      v42 = 0;
      do
      {
        v43 = bitstream->readp;
        ++v41;
        bitstream->currentBit = v2;
        v43 += 2;
        bitstream->currentByte = v2;
        bitstream->readp = v43;
        v5->font->glyphs.list[v42++].code = __ROL4__(*(v43 - 1), 8) | *(v43 - 2);
      }
      while ( v41 < SHIDWORD(v2) );
    }
    else
    {
      v44 = 0;
      v45 = 0;
      do
      {
        bitstream->currentBit = v2;
        ++v44;
        bitstream->currentByte = v2;
        v46 = bitstream->readp;
        v47 = *v46;
        bitstream->readp = v46 + 1;
        v5->font->glyphs.list[v45++].code = v47;
      }
      while ( v44 < SHIDWORD(v2) );
    }
    if ( (v20 & 0x80) != 0 )
    {
      v48 = bitstream->readp;
      v49 = 0;
      bitstream->currentBit = v2;
      v48 += 2;
      bitstream->currentByte = v2;
      bitstream->readp = v48;
      v5->font->ascent = __ROL4__(*(v48 - 1), 8) | *(v48 - 2);
      v50 = bitstream->readp + 2;
      bitstream->readp = v50;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      v5->font->descent = __ROL4__(*(v50 - 1), 8) | *(v50 - 2);
      v51 = bitstream->readp + 2;
      bitstream->currentBit = v2;
      bitstream->currentByte = v2;
      bitstream->readp = v51;
      v5->font->leading = __ROL4__(*(v51 - 1), 8) | *(v51 - 2);
      v52 = 0;
      do
      {
        v53 = bitstream->readp;
        ++v49;
        bitstream->currentBit = v2;
        v53 += 2;
        bitstream->currentByte = v2;
        bitstream->readp = v53;
        v54 = &v5->font->glyphs.list[v52++];
        v54->advance = __ROL4__(*(v53 - 1), 8) | *(v53 - 2);
      }
      while ( v49 < SHIDWORD(v2) );
      v55 = 0;
      do
      {
        v62.tl.x = 0.0;
        v62.tl.y = 0.0;
        v62.br.x = 0.0;
        v62.br.y = 0.0;
        idSWFBitStream::ReadRect(this: bitstream, rect: &v62);
        ++v55;
      }
      while ( v55 < SHIDWORD(v2) );
      v56 = bitstream->readp;
      bitstream->currentBit = v2;
      v57 = v56 + 2;
      bitstream->currentByte = v2;
      bitstream->readp = v57;
      v58 = (unsigned __int16)(__ROL4__(*(v57 - 1), 8) | *(v57 - 2));
      v59 = 0;
      if ( (v20 & 4) != 0 )
      {
        if ( v58 > 0 )
        {
          do
          {
            bitstream->currentBit = v2;
            ++v59;
            bitstream->currentByte = v2;
            bitstream->readp = v57 + 4;
            v57 += 6;
            bitstream->readp = v57;
          }
          while ( v59 < v58 );
        }
      }
      else if ( v58 > 0 )
      {
        do
        {
          bitstream->currentBit = v2;
          ++v59;
          bitstream->currentByte = v2;
          bitstream->readp = v57 + 2;
          v57 += 4;
          bitstream->readp = v57;
        }
        while ( v59 < v58 );
      }
    }
  }
}


// ========================================================================
// __unwind$221116
// EA  : 0x82799354
// RVA : 0x00799354
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void _unwind_221116()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$221117
// EA  : 0x8279937C
// RVA : 0x0079937C
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

void _unwind_221117()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 512 + 112));
}


// ========================================================================
// ?DefineFont3@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x827993A8
// RVA : 0x007993A8
// PDB : w:\tech5\engine\guis\swf\swf_text.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSWF::DefineFont3(idSWF *this, idSWFBitStream *bitstream)
{
  idSWF::DefineFont2(this, bitstream);
}

