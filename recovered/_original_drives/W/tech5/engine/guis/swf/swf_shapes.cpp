
// ========================================================================
// ?DefineShape@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82791270
// RVA : 0x00791270
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void __fastcall idSWF::DefineShape(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  idSWFDictionaryEntry *v9; // r29
  idSWFShapeParser v10; // [sp+50h] [-60h] BYREF

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v9 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v8 - 1), 8) | *(v8 - 2)),
         type: SWF_DICT_SHAPE);
  if ( v9 != nullptr )
  {
    idSWFShapeParser::idSWFShapeParser(this: &v10);
    idSWFShapeParser::Parse(this: &v10, bitstream, shape: v9->shape, recordType: 1);
    idSWFShapeParser::~idSWFShapeParser(this: &v10);
  }
}


// ========================================================================
// __unwind$219863
// EA  : 0x827912F0
// RVA : 0x007912F0
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void _unwind_219863()
{
  int v0; // r12

  idSWFShapeParser::~idSWFShapeParser(this: (idSWFShapeParser *)(v0 - 176 + 80));
}


// ========================================================================
// ?DefineShape2@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82791320
// RVA : 0x00791320
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void __fastcall idSWF::DefineShape2(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  idSWFDictionaryEntry *v9; // r29
  idSWFShapeParser v10; // [sp+50h] [-60h] BYREF

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v9 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v8 - 1), 8) | *(v8 - 2)),
         type: SWF_DICT_SHAPE);
  if ( v9 != nullptr )
  {
    idSWFShapeParser::idSWFShapeParser(this: &v10);
    idSWFShapeParser::Parse(this: &v10, bitstream, shape: v9->shape, recordType: 2);
    idSWFShapeParser::~idSWFShapeParser(this: &v10);
  }
}


// ========================================================================
// __unwind$219889
// EA  : 0x827913A0
// RVA : 0x007913A0
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void _unwind_219889()
{
  int v0; // r12

  idSWFShapeParser::~idSWFShapeParser(this: (idSWFShapeParser *)(v0 - 176 + 80));
}


// ========================================================================
// ?DefineShape3@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x827913D0
// RVA : 0x007913D0
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void __fastcall idSWF::DefineShape3(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  idSWFDictionaryEntry *v9; // r29
  idSWFShapeParser v10; // [sp+50h] [-60h] BYREF

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v9 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v8 - 1), 8) | *(v8 - 2)),
         type: SWF_DICT_SHAPE);
  if ( v9 != nullptr )
  {
    idSWFShapeParser::idSWFShapeParser(this: &v10);
    idSWFShapeParser::Parse(this: &v10, bitstream, shape: v9->shape, recordType: 3);
    idSWFShapeParser::~idSWFShapeParser(this: &v10);
  }
}


// ========================================================================
// __unwind$219915
// EA  : 0x82791450
// RVA : 0x00791450
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void _unwind_219915()
{
  int v0; // r12

  idSWFShapeParser::~idSWFShapeParser(this: (idSWFShapeParser *)(v0 - 176 + 80));
}


// ========================================================================
// ?DefineShape4@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82791480
// RVA : 0x00791480
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void __fastcall idSWF::DefineShape4(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  idSWFDictionaryEntry *v9; // r29
  idSWFShapeParser v10; // [sp+50h] [-60h] BYREF

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v9 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v8 - 1), 8) | *(v8 - 2)),
         type: SWF_DICT_SHAPE);
  if ( v9 != nullptr )
  {
    idSWFShapeParser::idSWFShapeParser(this: &v10);
    idSWFShapeParser::Parse(this: &v10, bitstream, shape: v9->shape, recordType: 4);
    idSWFShapeParser::~idSWFShapeParser(this: &v10);
  }
}


// ========================================================================
// __unwind$219941
// EA  : 0x82791500
// RVA : 0x00791500
// PDB : w:\tech5\engine\guis\swf\swf_shapes.cpp
// ========================================================================

void _unwind_219941()
{
  int v0; // r12

  idSWFShapeParser::~idSWFShapeParser(this: (idSWFShapeParser *)(v0 - 176 + 80));
}

