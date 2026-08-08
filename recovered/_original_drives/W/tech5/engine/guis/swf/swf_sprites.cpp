
// ========================================================================
// ?DefineSprite@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82796D20
// RVA : 0x00796D20
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void __fastcall idSWF::DefineSprite(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  idSWFDictionaryEntry *v9; // r3

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v9 = idSWF::AddDictionaryEntry(
         this,
         characterID: (unsigned __int16)(__ROL4__(*(v8 - 1), 8) | *(v8 - 2)),
         type: SWF_DICT_SPRITE);
  if ( v9 != nullptr )
    idSWFSprite::Load(this: v9->sprite, bitstream, parseDictionary: false);
}


// ========================================================================
// ?Write@idSWFSprite@@QAAXPAVidFile@@@Z
// EA  : 0x82796D98
// RVA : 0x00796D98
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void __fastcall idSWFSprite::Write(idSWFSprite *this, idFile *f)
{
  idFile_vtbl *v4; // r8
  idFile_vtbl *v5; // r9
  int v6; // r28
  int v7; // r29
  int v8; // r11
  int v9; // r9
  idSWFSprite::swfSpriteCommand_t *list; // r7
  int v11; // r10
  int i; // ctr
  const unsigned __int8 *endp; // r8
  const unsigned __int8 *startp; // r6
  idSWFBitStream *v15; // r8
  int v16; // r11
  int v17; // ctr
  const unsigned __int8 *v18; // r7
  const unsigned __int8 *v19; // r6
  int v20; // r29
  int v21; // r28
  int v22; // r28
  int v23; // r29
  idFile_vtbl *v24; // r10
  int v25; // r28
  int v26; // r29
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v28; // r10
  int v29; // r29
  int v30; // r28
  unsigned int (__fastcall *v31)(idFile *, const void *, unsigned int); // ctr
  int v32; // [sp+50h] [-50h] BYREF
  int num; // [sp+54h] [-4Ch] BYREF
  int v34; // [sp+58h] [-48h] BYREF
  int v35; // [sp+5Ch] [-44h] BYREF
  int v36; // [sp+60h] [-40h] BYREF
  int v37; // [sp+64h] [-3Ch] BYREF
  int v38; // [sp+68h] [-38h] BYREF

  f->Write(this: f, a2: &this->frameCount, a3: 2u);
  v4 = f->__vftable;
  num = this->frameOffsets.num;
  v4->Write(this: f, a2: &num, a3: 4u);
  f->Write(this: f, a2: this->frameOffsets.list, a3: 4 * this->frameOffsets.num);
  v5 = f->__vftable;
  v34 = this->frameLabels.num;
  v5->Write(this: f, a2: &v34, a3: 4u);
  v6 = 0;
  if ( this->frameLabels.num > 0 )
  {
    v7 = 0;
    do
    {
      f->Write(this: f, a2: &this->frameLabels.list[v7].frameNum, a3: 4u);
      idFile::WriteString(this: f, string: this->frameLabels.list[v7].frameLabel.str);
      ++v6;
      ++v7;
    }
    while ( v6 < this->frameLabels.num );
  }
  v8 = this->commands.num;
  v9 = 0;
  v32 = 0;
  if ( v8 > 0 )
  {
    list = this->commands.list;
    v11 = 0;
    for ( i = v8; i != 0; --i )
    {
      endp = list[v11].stream.endp;
      startp = list[v11++].stream.startp;
      v9 += endp - startp;
      v32 = v9;
    }
  }
  if ( this->doInitActions.num > 0 )
  {
    v15 = this->doInitActions.list;
    v16 = 0;
    v17 = this->doInitActions.num;
    do
    {
      v18 = v15[v16].endp;
      v19 = v15[v16++].startp;
      v9 += v18 - v19;
      v32 = v9;
      --v17;
    }
    while ( v17 != 0 );
  }
  f->Write(this: f, a2: &v32, a3: 4u);
  v20 = 0;
  if ( this->commands.num > 0 )
  {
    v21 = 0;
    do
    {
      f->Write(
        this: f,
        a2: this->commands.list[v21].stream.startp,
        a3: this->commands.list[v21].stream.endp - this->commands.list[v21].stream.startp);
      ++v20;
      ++v21;
    }
    while ( v20 < this->commands.num );
  }
  v22 = 0;
  if ( this->doInitActions.num > 0 )
  {
    v23 = 0;
    do
    {
      f->Write(
        this: f,
        a2: this->doInitActions.list[v23].startp,
        a3: this->doInitActions.list[v23].endp - this->doInitActions.list[v23].startp);
      ++v22;
      ++v23;
    }
    while ( v22 < this->doInitActions.num );
  }
  v24 = f->__vftable;
  v35 = this->commands.num;
  v24->Write(this: f, a2: &v35, a3: 4u);
  v25 = 0;
  if ( this->commands.num > 0 )
  {
    v26 = 0;
    do
    {
      f->Write(this: f, a2: &this->commands.list[v26], a3: 4u);
      Write = f->Write;
      v36 = this->commands.list[v26].stream.endp - this->commands.list[v26].stream.startp;
      Write(this: f, a2: &v36, a3: 4u);
      ++v25;
      ++v26;
    }
    while ( v25 < this->commands.num );
  }
  v28 = f->__vftable;
  v37 = this->doInitActions.num;
  v28->Write(this: f, a2: &v37, a3: 4u);
  v29 = 0;
  if ( this->doInitActions.num > 0 )
  {
    v30 = 0;
    do
    {
      v31 = f->Write;
      v38 = this->doInitActions.list[v30].endp - this->doInitActions.list[v30].startp;
      v31(this: f, a2: &v38, a3: 4u);
      ++v29;
      ++v30;
    }
    while ( v29 < this->doInitActions.num );
  }
}


// ========================================================================
// ??0idSWFSprite@@QAA@PAVidSWF@@@Z
// EA  : 0x827976F8
// RVA : 0x007976F8
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

idSWFSprite *__fastcall idSWFSprite::idSWFSprite(idSWFSprite *this, idSWF *_swf)
{
  this->swf = _swf;
  this->frameCount = 0;
  this->frameOffsets.list = nullptr;
  this->frameOffsets.granularity = 0;
  this->frameOffsets.memTag = 72;
  this->frameOffsets.listStatic = 0;
  this->frameOffsets.size = 0;
  this->frameOffsets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameOffsets);
  this->frameLabels.list = nullptr;
  this->frameLabels.granularity = 0;
  this->frameLabels.memTag = 72;
  this->frameLabels.listStatic = 0;
  this->frameLabels.size = 0;
  this->frameLabels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameLabels);
  this->commands.granularity = 0;
  this->commands.memTag = 72;
  this->commands.listStatic = 0;
  this->commands.list = nullptr;
  this->commands.size = 0;
  this->commands.num = 0;
  this->doInitActions.granularity = 0;
  this->doInitActions.memTag = 72;
  this->doInitActions.listStatic = 0;
  this->doInitActions.list = nullptr;
  this->doInitActions.size = 0;
  this->doInitActions.num = 0;
  this->commandBuffer = nullptr;
  return this;
}


// ========================================================================
// __unwind$221414
// EA  : 0x827977B0
// RVA : 0x007977B0
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221414()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$221415_0
// EA  : 0x827977DC
// RVA : 0x007977DC
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221415_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// __unwind$221416_0
// EA  : 0x82797808
// RVA : 0x00797808
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221416_0()
{
  int v0; // r12

  idList<idSWFSprite::swfSpriteCommand_t,72>::~idList<idSWFSprite::swfSpriteCommand_t,72>(this: (idList<idSWFSprite::swfSpriteCommand_t,72> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ??1idSWFSprite@@QAA@XZ
// EA  : 0x82797840
// RVA : 0x00797840
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void __fastcall idSWFSprite::~idSWFSprite(idSWFSprite *this)
{
  idSWFBitStream *list; // r3
  char *v3; // r3

  idMem::Free(this: &mem, ptr: this->commandBuffer, align: ALIGN_16);
  if ( this->doInitActions.listStatic == 0 || this->doInitActions.listStatic == 2 )
  {
    list = this->doInitActions.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFBitStream>(ptr: list, num: this->doInitActions.size);
    this->doInitActions.list = nullptr;
    this->doInitActions.size = 0;
  }
  this->doInitActions.num = 0;
  if ( this->commands.listStatic == 0 || this->commands.listStatic == 2 )
  {
    v3 = (char *)this->commands.list;
    if ( v3 != nullptr )
      idListArrayDelete<idSWFSprite::swfSpriteCommand_t>(ptr: v3, num: this->commands.size);
    this->commands.list = nullptr;
    this->commands.size = 0;
  }
  this->commands.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameLabels);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameOffsets);
}


// ========================================================================
// __unwind$221479
// EA  : 0x827978F0
// RVA : 0x007978F0
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221479()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$221480
// EA  : 0x8279791C
// RVA : 0x0079791C
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221480()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// __unwind$221481
// EA  : 0x82797948
// RVA : 0x00797948
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221481()
{
  int v0; // r12

  idList<idSWFSprite::swfSpriteCommand_t,72>::~idList<idSWFSprite::swfSpriteCommand_t,72>(this: (idList<idSWFSprite::swfSpriteCommand_t,72> *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$221482
// EA  : 0x82797974
// RVA : 0x00797974
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221482()
{
  int v0; // r12

  idList<idSWFBitStream,72>::~idList<idSWFBitStream,72>(this: (idList<idSWFBitStream,72> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                          + 56));
}


// ========================================================================
// ?Read@idSWFSprite@@QAAXPAVidFile@@@Z
// EA  : 0x827979A8
// RVA : 0x007979A8
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void __fastcall idSWFSprite::Read(idSWFSprite *this, idFile *f)
{
  int v2; // r24
  idFile_vtbl *v3; // r11
  int v6; // r28
  int size; // r11
  idList<idSWFSprite::swfFrameLabel_t,72> *p_frameLabels; // r26
  int v9; // r29
  int v10; // r11
  int v11; // r28
  int v12; // r29
  idSWFSprite::swfFrameLabel_t *list; // r11
  idAtomicString *p_frameLabel; // r25
  unsigned __int8 *v15; // r3
  unsigned int v16; // r5
  unsigned __int8 *commandBuffer; // r25
  idList<idSWFSprite::swfSpriteCommand_t,72> *p_commands; // r26
  int v19; // r29
  int v20; // r11
  int v21; // r28
  int v22; // r29
  int num; // r11
  int v24; // r10
  idSWFBitStream *v25; // r9
  idSWFBitStream *v26; // r3
  int v27; // [sp+50h] [-80h] BYREF
  unsigned int v28; // [sp+54h] [-7Ch] BYREF
  unsigned int v29; // [sp+58h] [-78h] BYREF
  unsigned int v30; // [sp+5Ch] [-74h] BYREF
  idStr v31[3]; // [sp+60h] [-70h] BYREF

  v2 = 0;
  v3 = f->__vftable;
  v27 = 0;
  v3->Read(this: f, a2: &this->frameCount, a3: 2u);
  f->Read(this: f, a2: &v27, a3: 4u);
  v6 = v27;
  if ( v27 <= this->frameOffsets.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->frameOffsets,
         newsize: v27) )
  {
    size = this->frameOffsets.size;
    if ( v6 < size )
      size = v6;
    this->frameOffsets.num = size;
  }
  f->Read(this: f, a2: this->frameOffsets.list, a3: 4 * this->frameOffsets.num);
  f->Read(this: f, a2: &v27, a3: 4u);
  p_frameLabels = &this->frameLabels;
  v9 = v27;
  if ( v27 <= this->frameLabels.size
    || (unsigned __int8)idList<idSWFSprite::swfFrameLabel_t,72>::Resize(this: &this->frameLabels, newsize: v27) != 0 )
  {
    v10 = this->frameLabels.size;
    if ( v9 < v10 )
      v10 = v9;
    this->frameLabels.num = v10;
  }
  v11 = 0;
  if ( this->frameLabels.num > 0 )
  {
    v12 = 0;
    do
    {
      f->Read(this: f, a2: &p_frameLabels->list[v12].frameNum, a3: 4u);
      list = p_frameLabels->list;
      v31[0].allocedAndFlag = 20;
      v31[0].data = v31[0].baseBuffer;
      p_frameLabel = &list[v12].frameLabel;
      v31[0].len = 0;
      v31[0].baseBuffer[0] = 0;
      idFile::ReadString(this: f, string: v31);
      idAtomicString::Set(this: p_frameLabel, str_: v31[0].data);
      idStr::FreeData(this: v31);
      ++v11;
      ++v12;
    }
    while ( v11 < this->frameLabels.num );
  }
  f->Read(this: f, a2: &v30, a3: 4u);
  v15 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\guis\\swf\\SWF_Sprites.cpp(170) : TAG_SWF",
                             size: v30,
                             tag: TAG_SWF,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v16 = v30;
  this->commandBuffer = v15;
  f->Read(this: f, a2: v15, a3: v16);
  commandBuffer = this->commandBuffer;
  f->Read(this: f, a2: &v27, a3: 4u);
  p_commands = &this->commands;
  v19 = v27;
  if ( v27 <= this->commands.size
    || (unsigned __int8)idList<idSWFSprite::swfSpriteCommand_t,72>::Resize(this: &this->commands, newsize: v27) != 0 )
  {
    v20 = this->commands.size;
    if ( v19 < v20 )
      v20 = v19;
    this->commands.num = v20;
  }
  v21 = 0;
  if ( this->commands.num > 0 )
  {
    v22 = 0;
    do
    {
      v28 = 0;
      f->Read(this: f, a2: &p_commands->list[v22], a3: 4u);
      f->Read(this: f, a2: &v28, a3: 4u);
      idSWFBitStream::Load(this: &p_commands->list[v22].stream, data: commandBuffer, len: v28, copy: false);
      ++v21;
      ++v22;
      commandBuffer += v28;
    }
    while ( v21 < this->commands.num );
  }
  v29 = 0;
  f->Read(this: f, a2: &v27, a3: 4u);
  if ( v27 > 0 )
  {
    do
    {
      f->Read(this: f, a2: &v29, a3: 4u);
      idList<idSWFBitStream,72>::PreAllocateWithGranularity(
        this: &this->doInitActions,
        newSize: this->doInitActions.num + 1);
      num = this->doInitActions.num;
      v24 = this->doInitActions.size;
      v25 = this->doInitActions.list;
      if ( num >= v24 )
      {
        v26 = &v25[v24 - 1];
      }
      else
      {
        v26 = &v25[num];
        this->doInitActions.num = num + 1;
      }
      idSWFBitStream::Load(this: v26, data: commandBuffer, len: v29, copy: true);
      ++v2;
      commandBuffer += v29;
    }
    while ( v2 < v27 );
  }
}


// ========================================================================
// __unwind$221659
// EA  : 0x82797D5C
// RVA : 0x00797D5C
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221659()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Load@idSWFSprite@@QAAXAAVidSWFBitStream@@_N@Z
// EA  : 0x82797E20
// RVA : 0x00797E20
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void __fastcall idSWFSprite::Load(idSWFSprite *this, idSWFBitStream *bitstream, bool parseDictionary)
{
  unsigned __int64 v3; // r25
  const unsigned __int8 *v5; // r11
  bool v7; // r29
  unsigned __int64 v8; // r25
  int v9; // r11
  int v10; // r30
  int size; // r6
  int v12; // r11
  int v13; // r23
  BOOL v14; // r21
  int v15; // r22
  const unsigned __int8 *readp; // r11
  const unsigned __int8 *v17; // r11
  int v18; // r8
  int v19; // r7
  unsigned __int64 v20; // r10
  unsigned int v21; // r28
  unsigned int v22; // r30
  const unsigned __int8 *Data; // r3
  unsigned __int64 v24; // r10
  int v25; // r8
  int v26; // r7
  int v27; // r6
  int v28; // r5
  int v29; // r29
  char v30; // r30
  idSWFSprite::swfSpriteCommand_t *v31; // r30
  unsigned __int64 v32; // r10
  int v33; // r8
  int v34; // r7
  int v35; // r6
  char v36; // r5
  const unsigned __int8 *v37; // r3
  idSWFBitStream *v38; // r30
  unsigned __int64 v39; // r10
  int v40; // r8
  int v41; // r7
  int v42; // r6
  char v43; // r5
  const unsigned __int8 *v44; // r3
  idList<idSWFSprite::swfFrameLabel_t,72> *p_frameLabels; // r30
  unsigned __int64 v46; // r8
  int v47; // r6
  int v48; // r5
  int v49; // r4
  int num; // r11
  int v51; // r10
  idAtomicString *p_frameLabel; // r29
  const char *String; // r3
  idSWFBitStream v54[4]; // [sp+50h] [-80h] BYREF

  LODWORD(v3) = 0;
  v5 = bitstream->readp + 2;
  bitstream->currentBit = v3;
  bitstream->currentByte = v3;
  bitstream->readp = v5;
  v7 = parseDictionary;
  HIDWORD(v8) = &this->frameOffsets;
  v9 = (unsigned __int16)(__ROL4__(*(v5 - 1), 8) | *(v5 - 2));
  v10 = v9 + 1;
  this->frameCount = v9;
  size = this->frameOffsets.size;
  if ( v9 + 1 <= size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->frameOffsets,
         newsize: v9 + 1) )
  {
    v12 = *(_DWORD *)(HIDWORD(v8) + 8);
    if ( v10 < v12 )
      v12 = v10;
    *(_DWORD *)(HIDWORD(v8) + 4) = v12;
  }
  v13 = 1;
  v14 = v7;
  v15 = 4;
  **(_DWORD **)HIDWORD(v8) = 0;
  while ( 1 )
  {
    readp = bitstream->readp;
    bitstream->currentBit = v8;
    v17 = readp + 2;
    bitstream->currentByte = v8;
    bitstream->readp = v17;
    HIDWORD(v20) = *(v17 - 1);
    v18 = __ROL4__(HIDWORD(v20), 8);
    v19 = v18 | *(v17 - 2);
    LODWORD(v20) = (unsigned __int16)(v18 | *(v17 - 2));
    v21 = v20 & 0x3F;
    v22 = (unsigned __int16)v20;
    if ( v21 == 63 )
    {
      bitstream->currentByte = v8;
      bitstream->currentBit = v8;
      bitstream->readp = v17 + 4;
      LODWORD(v20) = v17[1];
      size = *v17;
      HIDWORD(v20) = v17[3];
      v18 = v17[2];
      v19 = __ROL4__(HIDWORD(v20), 8);
      parseDictionary = v19 | v18;
      v21 = ((((v19 | v18) << 8) | (unsigned int)v20) << 8) | size;
    }
    Data = idSWFBitStream::ReadData(
             this: bitstream,
             size: v21,
             a3: parseDictionary,
             a4: size,
             a5: v19,
             a6: v18,
             a7: v20);
    v54[0].free = false;
    idSWFBitStream::Load(this: v54, data: Data, len: v21, copy: false);
    v29 = v22 >> 6;
    if ( !v14 )
      goto _M221945;
    v30 = 1;
    if ( v29 > 32 )
    {
      if ( v29 <= 48 )
      {
        if ( v29 == 48 )
        {
          idSWF::DefineFont2(this: this->swf, bitstream: v54);
          goto LABEL_42;
        }
        if ( (unsigned int)(v29 - 33) <= 6 )
        {
          if ( v29 == 33 )
          {
            idSWF::DefineText2(this: this->swf, bitstream: v54);
            goto LABEL_42;
          }
          if ( v29 != 34 )
          {
            switch ( v29 )
            {
              case '#':
                idSWF::DefineBitsJPEG3(this: this->swf, bitstream: v54);
                goto LABEL_42;
              case '$':
                idSWF::DefineBitsLossless2(this: this->swf, bitstream: v54);
                goto LABEL_42;
              case '%':
                idSWF::DefineEditText(this: this->swf, bitstream: v54);
                goto LABEL_42;
              default:
                break;
            }
            if ( v29 != 38 )
            {
              idSWF::DefineSprite(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
              goto LABEL_42;
            }
          }
        }
LABEL_39:
        v30 = 0;
        goto LABEL_42;
      }
      if ( v29 == 75 )
      {
        idSWF::DefineFont3(this: this->swf, bitstream: v54);
      }
      else
      {
        if ( v29 != 83 )
          goto LABEL_39;
        idSWF::DefineShape4(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
      }
    }
    else if ( v29 == 32 )
    {
      idSWF::DefineShape3(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
    }
    else
    {
      switch ( v29 )
      {
        case 2:
          idSWF::DefineShape(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
          break;
        case 6:
          idSWF::DefineBits(this: this->swf, bitstream: v54);
          break;
        case 8:
          idSWF::JPEGTables(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25);
          break;
        case 11:
          idSWF::DefineText(this: this->swf, bitstream: v54);
          break;
        case 14:
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)this->swf);
          break;
        case 20:
          idSWF::DefineBitsLossless(this: this->swf, bitstream: v54);
          break;
        case 21:
          idSWF::DefineBitsJPEG2(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
          break;
        case 22:
          idSWF::DefineShape2(this: this->swf, bitstream: v54, a3: v28, a4: v27, a5: v26, a6: v25, a7: v24);
          break;
        default:
          goto LABEL_39;
      }
    }
LABEL_42:
    if ( v30 != 0 )
      goto LABEL_43;
_M221945:
    if ( v29 <= 28 )
      break;
    switch ( v29 )
    {
      case '+':
        p_frameLabels = &this->frameLabels;
        idList<idSWFSprite::swfFrameLabel_t,72>::PreAllocateWithGranularity(
          this: &this->frameLabels,
          newSize: this->frameLabels.num + 1);
        num = this->frameLabels.num;
        v51 = this->frameLabels.size;
        if ( num >= v51 )
        {
          p_frameLabel = &p_frameLabels->list[v51 - 1].frameLabel;
        }
        else
        {
          p_frameLabel = &p_frameLabels->list[num].frameLabel;
          this->frameLabels.num = num + 1;
        }
        p_frameLabel[1].str = (const char *)v13;
        String = idSWFBitStream::ReadString(this: v54, a2: v49, a3: v48, a4: v47, a5: v46);
        idAtomicString::Set(this: p_frameLabel, str_: String);
        break;
      case ';':
        v54[0].currentBit = v8;
        v54[0].currentByte = v8;
        v54[0].readp += 2;
        v38 = idList<idSWFBitStream,72>::Alloc(this: &this->doInitActions);
        v44 = idSWFBitStream::ReadData(this: v54, size: v21 - 2, a3: v43, a4: v42, a5: v41, a6: v40, a7: v39);
        idSWFBitStream::Load(this: v38, data: v44, len: v21 - 2, copy: true);
        break;
      case 'F':
LABEL_56:
        v31 = idList<idSWFSprite::swfSpriteCommand_t,72>::Alloc(this: &this->commands);
        v31->tag = v29;
        v37 = idSWFBitStream::ReadData(this: v54, size: v21, a3: v36, a4: v35, a5: v34, a6: v33, a7: v32);
        idSWFBitStream::Load(this: &v31->stream, data: v37, len: v21, copy: true);
        break;
      default:
        break;
    }
LABEL_43:
    idSWFBitStream::Free(this: v54);
  }
  if ( v29 == 28 )
    goto LABEL_56;
  if ( v29 > 12 )
  {
    if ( v29 == 26 )
      goto LABEL_56;
    goto LABEL_43;
  }
  if ( v29 == 12 )
    goto LABEL_56;
  if ( v29 != 0 )
  {
    if ( v29 == 1 )
    {
      ++v13;
      *(_DWORD *)(v15 + *(_DWORD *)HIDWORD(v8)) = this->commands.num;
      v15 += 4;
    }
    goto LABEL_43;
  }
  idSWFBitStream::Free(this: v54);
}


// ========================================================================
// __unwind$221849_0
// EA  : 0x827982BC
// RVA : 0x007982BC
// PDB : w:\tech5\engine\guis\swf\swf_sprites.cpp
// ========================================================================

void _unwind_221849_0()
{
  int v0; // r12

  idSWFBitStream::~idSWFBitStream(this: (idSWFBitStream *)(v0 - 208 + 80));
}

