
// ========================================================================
// ?RemoveObject2@idSWFSpriteInstance@@QAAXAAVidSWFBitStream@@@Z
// EA  : 0x8277DCD0
// RVA : 0x0077DCD0
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

void __fastcall idSWFSpriteInstance::RemoveObject2(
        idSWFSpriteInstance *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v7; // r11

  LODWORD(a7) = 0;
  v7 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v7;
  idSWFSpriteInstance::RemoveDisplayEntry(this, depth: __ROL4__(*(v7 - 1), 8) | *(v7 - 2));
}


// ========================================================================
// ?ExecutePlaceObject2@idSWFSpriteInstance@@AAAPAUswfDisplayEntry_t@@ABUplaceObject2Data_t@1@@Z
// EA  : 0x8277DD08
// RVA : 0x0077DD08
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

swfDisplayEntry_t *__fastcall idSWFSpriteInstance::ExecutePlaceObject2(
        idSWFSpriteInstance *this,
        const idSWFSpriteInstance::placeObject2Data_t *po2)
{
  unsigned __int64 flags; // r11
  char v5; // r9
  swfDisplayEntry_t *v6; // r29
  int characterID; // r5
  swfDisplayEntry_t *DisplayEntry; // r3
  int v10; // r4
  idSWFDictionaryEntry *DictionaryEntry; // r3
  idAtomicString *spriteInstance; // r11
  idSWFScriptVar *v13; // r3
  idAtomicString *textInstance; // r11
  idSWFScriptVar v15; // [sp+58h] [-38h] BYREF
  idSWFScriptVar v16[6]; // [sp+60h] [-30h] BYREF

  flags = po2->flags;
  HIDWORD(flags) = po2->flags & 1;
  if ( HIDWORD(flags) != 0 || (v5 = 1, (flags & 2) == 0) )
    v5 = 0;
  v6 = nullptr;
  if ( v5 != 0 )
  {
    characterID = po2->characterID;
    if ( characterID < 0 )
    {
      idLib::Warning(fmt: "ExecutePlaceObject2: Trying to create a new object without a character");
      return nullptr;
    }
    v6 = idSWFSpriteInstance::AddDisplayEntry(this, depth: po2->depth, characterID, objectName: &po2->name);
    if ( v6 == nullptr )
    {
      idLib::Warning(
        fmt: "ExecutePlaceObject2: trying to create a new entry at %d, but an item already exists there",
        po2->depth);
      return nullptr;
    }
    goto LABEL_20;
  }
  if ( HIDWORD(flags) != 0 )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this, depth: po2->depth);
    v6 = DisplayEntry;
    if ( DisplayEntry == nullptr )
    {
      idLib::Warning(fmt: "ExecutePlaceObject2: trying to modify entry %d, which doesn't exist", po2->depth);
      return nullptr;
    }
    v10 = po2->characterID;
    if ( v10 >= 0 )
    {
      if ( DisplayEntry->spriteInstance != nullptr || DisplayEntry->textInstance != nullptr )
      {
        idLib::Warning(fmt: "ExecutePlaceObject2: Trying to change the character of a sprite after it's been created");
        return nullptr;
      }
      DictionaryEntry = idSWF::FindDictionaryEntry(this: this->sprite->swf, characterID: v10);
      if ( DictionaryEntry != nullptr
        && (DictionaryEntry->type == SWF_DICT_SPRITE || DictionaryEntry->type == SWF_DICT_EDITTEXT) )
      {
        idLib::Warning(fmt: "ExecutePlaceObject2: Trying to change the character of a shape to a sprite");
        return nullptr;
      }
      v6->characterID = po2->characterID;
    }
LABEL_20:
    if ( (po2->flags & 4) != 0 )
    {
      v6->matrix.xx = po2->matrix.xx;
      v6->matrix.yy = po2->matrix.yy;
      v6->matrix.xy = po2->matrix.xy;
      v6->matrix.yx = po2->matrix.yx;
      v6->matrix.tx = po2->matrix.tx;
      v6->matrix.ty = po2->matrix.ty;
    }
    if ( (po2->flags & 8) != 0 )
    {
      v6->cxf.mul.x = po2->cxf.mul.x;
      v6->cxf.mul.y = po2->cxf.mul.y;
      v6->cxf.mul.z = po2->cxf.mul.z;
      v6->cxf.mul.w = po2->cxf.mul.w;
      v6->cxf.add.x = po2->cxf.add.x;
      v6->cxf.add.y = po2->cxf.add.y;
      v6->cxf.add.z = po2->cxf.add.z;
      v6->cxf.add.w = po2->cxf.add.w;
    }
    if ( (po2->flags & 0x10) != 0 )
      v6->ratio = po2->ratio;
    if ( (po2->flags & 0x20) == 0 )
      goto LABEL_35;
    if ( po2->characterID < 0 )
    {
      idLib::Warning(fmt: "ExecutePlaceObject2: Trying to set name of a newly created object");
      return nullptr;
    }
    spriteInstance = (idAtomicString *)v6->spriteInstance;
    if ( spriteInstance != nullptr )
    {
      idAtomicString::Set(this: spriteInstance + 15, str_: po2->name.data);
      idSWFScriptVar::idSWFScriptVar(this: &v15, o: v6->spriteInstance->scriptObject);
      idSWFScriptObject::Set(this: this->scriptObject, name: po2->name.data, value: &v15);
      v13 = &v15;
    }
    else
    {
      textInstance = (idAtomicString *)v6->textInstance;
      if ( textInstance == nullptr )
        goto LABEL_35;
      idAtomicString::Set(this: textInstance + 5, str_: po2->name.data);
      idSWFScriptVar::idSWFScriptVar(this: v16, o: v6->textInstance->scriptObject);
      idSWFScriptObject::Set(this: this->scriptObject, name: po2->name.data, value: v16);
      v13 = v16;
    }
    idSWFScriptVar::Free(this: v13);
LABEL_35:
    if ( (po2->flags & 0x40) != 0 )
      v6->clipDepth = po2->clipDepth;
  }
  return v6;
}


// ========================================================================
// __unwind$219457
// EA  : 0x8277E014
// RVA : 0x0077E014
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

void _unwind_219457()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$219458
// EA  : 0x8277E03C
// RVA : 0x0077E03C
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

void _unwind_219458()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 96));
}


// ========================================================================
// ?PlaceObject2@idSWFSpriteInstance@@QAAXAAVidSWFBitStream@@@Z
// EA  : 0x8277E070
// RVA : 0x0077E070
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFSpriteInstance::PlaceObject2(idSWFSpriteInstance *this, idSWFBitStream *bitstream)
{
  int v2; // r2 OVERLAPPED
  unsigned __int64 v4; // r29
  const unsigned __int8 *readp; // r10
  int v6; // r3
  unsigned __int64 flags; // r9 OVERLAPPED
  int v8; // r7 OVERLAPPED
  __int64 v9; // r6
  int v10; // r4
  const unsigned __int8 *v11; // r11
  int v12; // r3
  const char *String; // r3
  const unsigned __int8 *v14; // r11
  idSWFSpriteInstance::placeObject2Data_t v15; // [sp+60h] [-A0h] BYREF

  LODWORD(v4) = 0;
  v15.matrix.xx = 1.0;
  v15.matrix.yy = 1.0;
  v15.matrix.xy = 0.0;
  v15.matrix.yx = 0.0;
  HIDWORD(v4) = this;
  v15.matrix.tx = 0.0;
  ++c_PlaceObject2;
  v15.matrix.ty = 0.0;
  v15.flags = v4;
  v15.cxf.mul.x = 1.0;
  v15.depth = 0;
  v15.cxf.mul.y = 1.0;
  v15.characterID = -1;
  v15.cxf.mul.z = 1.0;
  v15.name.data = v15.name.baseBuffer;
  v15.cxf.mul.w = 1.0;
  v15.name.len = 0;
  v15.cxf.add.x = 0.0;
  v15.name.baseBuffer[0] = 0;
  v15.cxf.add.y = 0.0;
  v15.clipDepth = 0;
  v15.cxf.add.z = 0.0;
  v15.name.allocedAndFlag = 20;
  v15.cxf.add.w = 0.0;
  v15.ratio = 0.0;
  readp = bitstream->readp;
  bitstream->currentBit = v4;
  bitstream->currentByte = v4;
  v6 = *readp;
  HIDWORD(flags) = v6 & 2;
  LOBYTE(flags) = *readp;
  v15.flags = *(_QWORD *)(&v2 - 1);
  bitstream->currentBit = v4;
  bitstream->currentByte = v4;
  bitstream->readp = readp + 3;
  v8 = readp[1];
  LODWORD(v9) = readp[2];
  HIDWORD(v9) = __ROL4__(v9, 8);
  v10 = HIDWORD(v9) | v8;
  v15.depth = HIDWORD(v9) | v8;
  if ( (v6 & 2) != 0 )
  {
    bitstream->currentBit = v4;
    bitstream->currentByte = v4;
    bitstream->readp = readp + 5;
    HIDWORD(flags) = readp[4];
    v8 = __ROL4__(HIDWORD(flags), 8);
    LODWORD(v9) = v8 | readp[3];
    v15.characterID = v9;
  }
  if ( (flags & 4) != 0 )
  {
    idSWFBitStream::ReadMatrix(this: bitstream, matrix: &v15.matrix);
    flags = v15.flags;
  }
  if ( (flags & 8) != 0 )
  {
    idSWFBitStream::ReadColorXFormRGBA(this: bitstream, cxf: v9);
    flags = v15.flags;
  }
  if ( (flags & 0x10) != 0 )
  {
    v11 = bitstream->readp;
    bitstream->currentBit = v4;
    v11 += 2;
    bitstream->currentByte = v4;
    bitstream->readp = v11;
    v8 = *(v11 - 1);
    LODWORD(v9) = __ROL4__(v8, 8);
    HIDWORD(flags) = *(v11 - 2);
    HIDWORD(v9) = v9 | HIDWORD(flags);
    v12 = (unsigned __int16)(v9 | WORD1(flags));
    v15.ratio = (float)*(__int64 *)(&v2 - 1) * (float)0.000015259022;
  }
  if ( (flags & 0x20) != 0 )
  {
    String = idSWFBitStream::ReadString(
               this: bitstream,
               a2: v10,
               a3: SHIDWORD(v9),
               a4: v9,
               a5: *(unsigned __int64 *)((char *)&flags + 4));
    idStr::operator=(this: &v15.name, text: String);
    LOBYTE(flags) = v15.flags;
  }
  if ( (flags & 0x40) != 0 )
  {
    v14 = bitstream->readp;
    bitstream->currentByte = v4;
    v14 += 2;
    bitstream->currentBit = v4;
    bitstream->readp = v14;
    v15.clipDepth = __ROL4__(*(v14 - 1), 8) | *(v14 - 2);
  }
  idSWFSpriteInstance::ExecutePlaceObject2(this: (idSWFSpriteInstance *)HIDWORD(v4), po2: &v15);
  idStr::FreeData(this: &v15.name);
}


// ========================================================================
// __unwind$219561_0
// EA  : 0x8277E28C
// RVA : 0x0077E28C
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

void _unwind_219561_0()
{
  int v0; // r12

  idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t(this: (idSWFSpriteInstance::placeObject2Data_t *)(v0 - 256 + 96));
}


// ========================================================================
// ?PlaceObject3@idSWFSpriteInstance@@QAAXAAVidSWFBitStream@@@Z
// EA  : 0x8277E2C0
// RVA : 0x0077E2C0
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFSpriteInstance::PlaceObject3(idSWFSpriteInstance *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r29
  int v3; // r2 OVERLAPPED
  unsigned int v4; // r7
  const unsigned __int8 *readp; // r11
  int v8; // r10
  unsigned __int64 flags; // r8
  __int64 v10; // r6
  int v11; // r4
  const unsigned __int8 *v12; // r11
  const unsigned __int8 *v13; // r11
  int v14; // r9
  int v15; // r3
  const char *String; // r3
  const unsigned __int8 *v17; // r11
  const unsigned __int8 *v18; // r11
  swfDisplayEntry_t *v19; // r3
  idSWFSpriteInstance::placeObject2Data_t v20; // [sp+60h] [-A0h] BYREF

  v4 = 0x82000000;
  LODWORD(v2) = 0;
  v20.matrix.xx = 1.0;
  v20.matrix.yy = 1.0;
  v20.matrix.xy = 0.0;
  v20.matrix.yx = 0.0;
  v20.matrix.tx = 0.0;
  ++c_PlaceObject3;
  v20.matrix.ty = 0.0;
  v20.flags = v2;
  v20.cxf.mul.x = 1.0;
  v20.depth = 0;
  v20.cxf.mul.y = 1.0;
  v20.characterID = -1;
  v20.cxf.mul.z = 1.0;
  v20.name.data = v20.name.baseBuffer;
  v20.cxf.mul.w = 1.0;
  v20.name.len = 0;
  v20.cxf.add.x = 0.0;
  v20.name.baseBuffer[0] = 0;
  v20.cxf.add.y = 0.0;
  v20.clipDepth = 0;
  v20.cxf.add.z = 0.0;
  v20.name.allocedAndFlag = 20;
  v20.cxf.add.w = 0.0;
  v20.ratio = 0.0;
  readp = bitstream->readp;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  LODWORD(flags) = *readp;
  bitstream->readp = readp + 1;
  v20.flags = flags;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v8 = readp[1];
  HIDWORD(flags) = v8 & 8;
  bitstream->currentBit = v2;
  HIDWORD(v2) = v8;
  bitstream->currentByte = v2;
  bitstream->readp = readp + 4;
  LODWORD(v10) = readp[2];
  HIDWORD(v10) = readp[3];
  v11 = __ROL4__(HIDWORD(v10), 8);
  v20.depth = v11 | v10;
  if ( (v8 & 8) != 0 || (v8 & 0x10) != 0 && (flags & 2) != 0 )
  {
    idSWFBitStream::ReadString(this: bitstream, a2: v11, a3: SHIDWORD(v10), a4: v10, a5: flags);
    flags = v20.flags;
  }
  if ( (flags & 2) != 0 )
  {
    v12 = bitstream->readp;
    bitstream->currentBit = v2;
    v12 += 2;
    bitstream->currentByte = v2;
    bitstream->readp = v12;
    HIDWORD(flags) = __ROL4__(*(v12 - 1), 8);
    LODWORD(v10) = HIDWORD(flags) | *(v12 - 2);
    v20.characterID = v10;
  }
  if ( (flags & 4) != 0 )
  {
    idSWFBitStream::ReadMatrix(this: bitstream, matrix: &v20.matrix);
    flags = v20.flags;
  }
  if ( (flags & 8) != 0 )
  {
    idSWFBitStream::ReadColorXFormRGBA(this: bitstream, cxf: v10);
    flags = v20.flags;
  }
  if ( (flags & 0x10) != 0 )
  {
    v13 = bitstream->readp;
    bitstream->currentBit = v2;
    v13 += 2;
    bitstream->currentByte = v2;
    bitstream->readp = v13;
    v14 = *(v13 - 2);
    HIDWORD(flags) = *(v13 - 1);
    LODWORD(v10) = __ROL4__(HIDWORD(flags), 8);
    HIDWORD(v10) = v10 | v14;
    v15 = (unsigned __int16)(v10 | v14);
    v20.ratio = (float)*(__int64 *)(&v3 - 1) * (float)0.000015259022;
  }
  if ( (flags & 0x20) != 0 )
  {
    String = idSWFBitStream::ReadString(this: bitstream, a2: v11, a3: SHIDWORD(v10), a4: v10, a5: flags);
    idStr::operator=(this: &v20.name, text: String);
    LOBYTE(flags) = v20.flags;
  }
  if ( (flags & 0x40) != 0 )
  {
    v17 = bitstream->readp;
    bitstream->currentBit = v2;
    v17 += 2;
    bitstream->currentByte = v2;
    bitstream->readp = v17;
    v20.clipDepth = __ROL4__(*(v17 - 1), 8) | *(v17 - 2);
  }
  if ( (v2 & 0x100000000LL) != 0 )
  {
    idLib::Warning(fmt: "PlaceObject3: has filters");
  }
  else
  {
    HIDWORD(v2) = BYTE3(v2) & 2;
    if ( HIDWORD(v2) != 0 )
    {
      bitstream->currentBit = v2;
      v18 = bitstream->readp;
      bitstream->currentByte = v2;
      LOWORD(v2) = *v18;
      bitstream->readp = v18 + 1;
    }
    v19 = idSWFSpriteInstance::ExecutePlaceObject2(this, po2: &v20);
    if ( v19 != nullptr && HIDWORD(v2) != 0 )
      v19->blendMode = v2;
  }
  idStr::FreeData(this: &v20.name);
}


// ========================================================================
// __unwind$219691
// EA  : 0x8277E578
// RVA : 0x0077E578
// PDB : w:\tech5\engine\guis\swf\swf_placeobject.cpp
// ========================================================================

void _unwind_219691()
{
  int v0; // r12

  idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t(this: (idSWFSpriteInstance::placeObject2Data_t *)(v0 - 256 + 96));
}

