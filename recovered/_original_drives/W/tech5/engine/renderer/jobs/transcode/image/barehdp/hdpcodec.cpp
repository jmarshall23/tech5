
// ========================================================================
// ?HDPEstimateTempMemory@@YAIHHH@Z
// EA  : 0x828ECD48
// RVA : 0x008ECD48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

int __fastcall HDPEstimateTempMemory(int width, int height, int numComponents)
{
  return (1088 * ((width + 15) / 16) + 4096) * numComponents;
}


// ========================================================================
// ?TempAlloc@@YAPAXPAUhdpCodecParms_t@@II@Z
// EA  : 0x828ECD68
// RVA : 0x008ECD68
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

char *__fastcall TempAlloc(hdpCodecParms_t *codecParms, unsigned int size, unsigned int align)
{
  unsigned int tempBuffer; // r8
  unsigned int tempBufferSize; // r6
  unsigned int v5; // r10

  tempBuffer = (unsigned int)codecParms->tempBuffer;
  tempBufferSize = codecParms->tempBufferSize;
  v5 = ((codecParms->tempBufferUsed + (tempBuffer & (align - 1)) + align - 1) & ~(align - 1))
     - (tempBuffer & (align - 1));
  codecParms->tempBufferUsed = v5;
  if ( v5 + size <= tempBufferSize )
  {
    codecParms->tempBufferUsed = v5 + size;
    return (char *)(v5 + tempBuffer);
  }
  else
  {
    MEMORY[0] = 0;
    return nullptr;
  }
}


// ========================================================================
// ?AllocateAdditionalBitIOs@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828ECDC0
// RVA : 0x008ECDC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

int __fastcall AllocateAdditionalBitIOs(hdpCodec_t *codec)
{
  hdpSubBands_t subBands; // r11
  BOOL hasTileIndex; // r10
  unsigned int v5; // r30
  char *tempBuffer; // r10
  unsigned int tempBufferSize; // r7
  unsigned int v8; // r11
  unsigned int v9; // r9
  hdpBitIO_t *v10; // r3
  unsigned int *v11; // r3

  subBands = codec->codecParms.subBands;
  if ( subBands == SB_NO_LOWPASS )
  {
    subBands = SB_NO_FLEXBITS;
  }
  else if ( subBands != SB_NO_HIGHPASS )
  {
    subBands = ((_cntlzw(subBands - 1) & 0x20) == 0) + 3;
  }
  hasTileIndex = codec->codecParms.hasTileIndex;
  codec->numSubBands = subBands;
  if ( hasTileIndex )
  {
    if ( codec->codecParms.streamLayout != SL_SPATIAL )
      v5 = (codec->codecParms.numTilesWideMinusOne + 1) * subBands;
    else
      v5 = codec->codecParms.numTilesWideMinusOne + 1;
    if ( v5 == 0 )
      goto LABEL_17;
    tempBuffer = (char *)codec->codecParms.tempBuffer;
    tempBufferSize = codec->codecParms.tempBufferSize;
    v8 = ((codec->codecParms.tempBufferUsed + ((unsigned __int8)tempBuffer & 0xF) + 15) & 0xFFFFFFF0)
       - ((unsigned __int8)tempBuffer & 0xF);
    v9 = v8 + 40 * v5;
    codec->codecParms.tempBufferUsed = v8;
    if ( v9 <= tempBufferSize )
    {
      v10 = (hdpBitIO_t *)&tempBuffer[v8];
      codec->codecParms.tempBufferUsed = v9;
    }
    else
    {
      v10 = nullptr;
      MEMORY[0] = 0;
    }
    codec->tileBitIOs = v10;
    if ( v10 != nullptr
      && (memset(Dst: v10, Val: 0, Size: 40 * v5),
          v11 = (unsigned int *)TempAlloc(
                                  codecParms: &codec->codecParms,
                                  size: 4 * (codec->codecParms.numTilesHighMinusOne + 1) * v5,
                                  align: 0x10u),
          codec->tileIndex = v11,
          v11 != nullptr) )
    {
LABEL_17:
      codec->numTileBitIOs = v5;
      return 0;
    }
    else
    {
      return -2;
    }
  }
  else
  {
    codec->numTileBitIOs = 0;
    return 0;
  }
}


// ========================================================================
// ?UpdateTilePos@@YAXPAUhdpCodec_t@@II@Z
// EA  : 0x828ECF00
// RVA : 0x008ECF00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

void __fastcall UpdateTilePos(hdpCodec_t *codec, unsigned int mbX, unsigned int mbY)
{
  unsigned int currentTileColumn; // r9
  unsigned int *v4; // r11
  unsigned int v5; // r6
  unsigned int widthInMacroblocks; // r31
  unsigned int currentTileRow; // r8
  unsigned int *v8; // r11
  unsigned int v9; // r7
  unsigned int heightInMacroblocks; // r10
  bool v11; // r11
  char v12; // r10

  currentTileColumn = codec->currentTileColumn;
  v4 = &codec->codecParms.tileMacroblockOffsetX[currentTileColumn];
  v5 = *v4;
  if ( currentTileColumn >= codec->codecParms.numTilesWideMinusOne )
    widthInMacroblocks = codec->widthInMacroblocks;
  else
    widthInMacroblocks = v4[1];
  currentTileRow = codec->currentTileRow;
  v8 = &codec->codecParms.tileMacroblockOffsetY[currentTileRow];
  v9 = *v8;
  if ( currentTileRow >= codec->codecParms.numTilesHighMinusOne )
    heightInMacroblocks = codec->heightInMacroblocks;
  else
    heightInMacroblocks = v8[1];
  v11 = false;
  if ( mbX != 0 )
  {
    if ( mbX == widthInMacroblocks )
      codec->currentTileColumn = currentTileColumn + 1;
  }
  else
  {
    codec->currentTileColumn = 0;
  }
  if ( mbY != 0 )
  {
    if ( mbY == heightInMacroblocks )
      codec->currentTileRow = currentTileRow + 1;
  }
  else
  {
    codec->currentTileRow = 0;
  }
  v12 = _cntlzw(((_BYTE)mbX - (_BYTE)v5) & 0xF);
  codec->resetAdaptiveScanTotals = (v12 & 0x20) != 0;
  codec->atTileLeftMB = (_cntlzw(v5 - mbX) & 0x20) != 0;
  codec->atTileTopMB = (_cntlzw(v9 - mbY) & 0x20) != 0;
  if ( (v12 & 0x20) != 0 || mbX + 1 == widthInMacroblocks )
    v11 = true;
  codec->adaptContextHuffman = v11;
}


// ========================================================================
// ?InitMacroblockColumnPtrs@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ECFF8
// RVA : 0x008ECFF8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

void __fastcall InitMacroblockColumnPtrs(hdpCodec_t *firstCodec)
{
  hdpCodec_t *i; // r31

  for ( i = firstCodec; i != nullptr; i = i->nextCodec )
  {
    memcpy(Dst: i->macroBlockColumnPtr0, Src: i->macroBlockRowBuffer0, Size: sizeof(i->macroBlockColumnPtr0));
    memcpy(Dst: i->macroBlockColumnPtr1, Src: i->macroBlockRowBuffer1, Size: sizeof(i->macroBlockColumnPtr1));
  }
}


// ========================================================================
// ?AdvanceMacroblockColumnPtrs@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ED058
// RVA : 0x008ED058
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

void __fastcall AdvanceMacroblockColumnPtrs(hdpCodec_t *firstCodec)
{
  unsigned int v1; // r10
  __int16 *v2; // r11
  unsigned int numChannels; // r7
  __int16 *v4; // r4
  int v5; // r9
  int v6; // r8
  __int16 **macroBlockColumnPtr1; // r11
  __int16 *v8; // r9
  __int16 *v9; // r6

  for ( ; firstCodec != nullptr; firstCodec = firstCodec->nextCodec )
  {
    v1 = 1;
    v2 = firstCodec->macroBlockColumnPtr0[0];
    numChannels = firstCodec->codecParms.numChannels;
    v4 = firstCodec->macroBlockColumnPtr1[0] + 256;
    v5 = cblkChromas[firstCodec->codecParms.colorFormat];
    firstCodec->macroBlockPrevColumnPtr[0] = v2;
    firstCodec->macroBlockColumnPtr0[0] = v2 + 256;
    firstCodec->macroBlockColumnPtr1[0] = v4;
    if ( numChannels > 1 )
    {
      v6 = 16 * v5;
      macroBlockColumnPtr1 = firstCodec->macroBlockColumnPtr1;
      do
      {
        v8 = *(macroBlockColumnPtr1 - 15);
        ++v1;
        v9 = &macroBlockColumnPtr1[1][v6];
        *(macroBlockColumnPtr1 - 15) = &v8[v6];
        macroBlockColumnPtr1[17] = v8;
        *++macroBlockColumnPtr1 = v9;
      }
      while ( v1 < firstCodec->codecParms.numChannels );
    }
  }
}


// ========================================================================
// ?SwapMacroblockRowPtrs@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ED0E8
// RVA : 0x008ED0E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

void __fastcall SwapMacroblockRowPtrs(hdpCodec_t *firstCodec)
{
  hdpCodec_t *i; // r31
  _BYTE v2[64]; // [sp+50h] [-60h] BYREF

  for ( i = firstCodec; i != nullptr; i = i->nextCodec )
  {
    memcpy(Dst: v2, Src: i->macroBlockRowBuffer0, Size: sizeof(v2));
    memcpy(Dst: i->macroBlockRowBuffer0, Src: i->macroBlockRowBuffer1, Size: sizeof(i->macroBlockRowBuffer0));
    memcpy(Dst: i->macroBlockRowBuffer1, Src: v2, Size: sizeof(i->macroBlockRowBuffer1));
  }
}


// ========================================================================
// ?SwapMacroblockPredPtrs@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828ED150
// RVA : 0x008ED150
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcodec.cpp
// ========================================================================

void __fastcall SwapMacroblockPredPtrs(hdpCodec_t *firstCodec)
{
  unsigned int v1; // r10
  hdpPredictionInfo_t **v2; // r11
  hdpPredictionInfo_t *v3; // r8

  for ( ; firstCodec != nullptr; firstCodec = firstCodec->nextCodec )
  {
    v1 = 0;
    if ( firstCodec->codecParms.numChannels != 0 )
    {
      v2 = &firstCodec->predInfoCurRow[15];
      do
      {
        ++v1;
        v3 = *(v2 - 15);
        *(v2 - 15) = v2[1];
        *++v2 = v3;
      }
      while ( v1 < firstCodec->codecParms.numChannels );
    }
  }
}

