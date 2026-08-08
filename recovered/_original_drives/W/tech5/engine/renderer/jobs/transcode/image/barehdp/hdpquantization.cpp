
// ========================================================================
// ?AllocateQuantizer@@YA?AW4hdpError_t@@PAUhdpCodecParms_t@@QAPAUhdpQuantizer_t@@II@Z
// EA  : 0x828FA630
// RVA : 0x008FA630
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

int __fastcall AllocateQuantizer(
        hdpCodecParms_t *codecParms,
        hdpQuantizer_t **pQuantizer,
        unsigned int numChannels,
        unsigned int numQuantizers)
{
  char *v7; // r3
  hdpQuantizer_t **v9; // r11
  int v10; // ctr
  unsigned int v11; // r10

  if ( numChannels > 0x10 || numQuantizers > 0x10 )
    return -1;
  v7 = TempAlloc(codecParms, size: 16 * numChannels * numQuantizers, align: 0x10u);
  *pQuantizer = (hdpQuantizer_t *)v7;
  if ( v7 == nullptr )
    return -2;
  if ( numChannels > 1 )
  {
    v9 = pQuantizer;
    v10 = numChannels - 1;
    do
    {
      v11 = (unsigned int)&(*v9++)[numQuantizers];
      *v9 = (hdpQuantizer_t *)v11;
      --v10;
    }
    while ( v10 != 0 );
  }
  return 0;
}


// ========================================================================
// ?FreeQuantizer@@YAXPAUhdpCodecParms_t@@QAPAUhdpQuantizer_t@@@Z
// EA  : 0x828FA6C0
// RVA : 0x008FA6C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall FreeQuantizer(bfx::BinaryReplayLogOut *codecParms, hdpQuantizer_t **pQuantizer)
{
  if ( *pQuantizer != nullptr )
    idPhysics_StaticMulti::UpdateTime(this: codecParms);
}


// ========================================================================
// ?FormatQuantizer@@YAXQAPAUhdpQuantizer_t@@EII_N11@Z
// EA  : 0x828FA6D8
// RVA : 0x008FA6D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall FormatQuantizer(
        hdpQuantizer_t **pQuantizer,
        unsigned __int8 cMode,
        unsigned int numChannels,
        unsigned int iPos,
        bool useShiftedUV,
        bool useScaledArith,
        bool useRoundDC)
{
  int v7; // r28
  unsigned int v8; // r6
  BOOL v9; // r26
  hdpQuantizer_t **v10; // r31
  hdpQuantizer_t *v11; // r11
  hdpQuantizer_t *v12; // r7
  hdpQuantizer_t *v13; // r10
  unsigned int iIndex; // r11
  int v15; // r9
  unsigned int iExp; // r11
  int v17; // r11
  int iQP; // r11
  int v19; // r9

  v7 = 0;
  if ( numChannels != 0 )
  {
    v8 = iPos;
    v9 = useRoundDC;
    v10 = pQuantizer;
    do
    {
      if ( v7 != 0 )
      {
        if ( cMode == 0 )
        {
          v11 = *pQuantizer;
LABEL_8:
          v12 = &(*v10)[v8];
          v12->iQP = v11[v8].iQP;
          v12->iRound = v11[v8].iRound;
          v12->iMan = v11[v8].iMan;
          *(_DWORD *)&v12->iExp = *(_DWORD *)&v11[v8].iExp;
          goto LABEL_9;
        }
        if ( cMode == 1 )
        {
          v11 = pQuantizer[1];
          goto LABEL_8;
        }
      }
LABEL_9:
      v13 = &(*v10)[v8];
      iIndex = v13->iIndex;
      if ( v13->iIndex != 0 )
      {
        if ( useScaledArith )
        {
          if ( iIndex >= 0x10 )
          {
            v15 = iIndex >> 4;
            iIndex = (iIndex & 0xF) + 16;
          }
          else
          {
            LOBYTE(v15) = 1;
          }
          v13->iQP = iIndex << v15;
          v13->iMan = gRecipTable[iIndex].iMan;
          iExp = gRecipTable[iIndex].iExp;
        }
        else
        {
          if ( iIndex >= 0x20 )
          {
            if ( iIndex >= 0x30 )
            {
              v15 = (iIndex >> 4) - 3;
              v17 = (iIndex & 0xF) + 16;
            }
            else
            {
              v15 = (iIndex >> 4) - 2;
              v17 = (int)((iIndex & 0xF) + 17) >> 1;
            }
          }
          else
          {
            LOBYTE(v15) = 0;
            v17 = (int)(iIndex + 3) >> 2;
          }
          v13->iQP = v17 << v15;
          v13->iMan = gRecipTable[v17].iMan;
          iExp = gRecipTable[v17].iExp;
        }
        v13->iExp = iExp + v15;
      }
      else
      {
        v13->iQP = 1;
        v13->iMan = 0;
        v13->iExp = 0;
      }
      iQP = v13->iQP;
      if ( v9 )
        v19 = iQP >> 1;
      else
        v19 = (3 * iQP + 1) >> 3;
      v13->iRound = v19;
      --numChannels;
      ++v7;
      ++v10;
    }
    while ( numChannels != 0 );
  }
}


// ========================================================================
// ?AllocateTileQuantization@@YA?AW4hdpError_t@@PAUhdpCodec_t@@@Z
// EA  : 0x828FA870
// RVA : 0x008FA870
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

int __fastcall AllocateTileQuantization(hdpCodec_t *codec)
{
  unsigned int numTilesWideMinusOne; // r11
  int v4; // r30
  unsigned int v5; // r29
  char *v6; // r3
  int v7; // ctr
  int v8; // r11

  numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
  if ( numTilesWideMinusOne >= 0x1000 )
    return -1;
  v4 = numTilesWideMinusOne + 1;
  v5 = 196 * (numTilesWideMinusOne + 1);
  v6 = TempAlloc(codecParms: &codec->codecParms, size: v5, align: 0x10u);
  codec->tileQuantization = (hdpTileQuantization_t *)v6;
  if ( v6 == nullptr )
    return -2;
  memset(Dst: v6, Val: 0, Size: v5);
  if ( v4 > 0 )
  {
    v7 = v4;
    v8 = 0;
    do
    {
      codec->tileQuantization[v8].cNumQPLP = 1;
      codec->tileQuantization[v8].cNumQPHP = 1;
      codec->tileQuantization[v8].cBitsLP = 0;
      codec->tileQuantization[v8++].cBitsHP = 0;
      --v7;
    }
    while ( v7 != 0 );
  }
  return 0;
}


// ========================================================================
// ?FreeTileQuantization@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FA930
// RVA : 0x008FA930
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall FreeTileQuantization(hdpCodec_t *codec)
{
  unsigned int v2; // r29
  int v3; // r30
  unsigned int v4; // r29
  int v5; // r30
  unsigned int v6; // r29
  int v7; // r30

  if ( (codec->codecParms.quantizationMode & 1) != 0 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      if ( codec->tileQuantization[v3].pQuantizerDC[0] != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
      ++v2;
      ++v3;
    }
    while ( v2 <= codec->codecParms.numTilesWideMinusOne );
  }
  else if ( codec->tileQuantization->pQuantizerDC[0] != nullptr )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
  }
  if ( codec->codecParms.subBands < SB_NO_LOWPASS )
  {
    if ( (codec->codecParms.quantizationMode & 2) != 0 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        if ( codec->tileQuantization[v5].pQuantizerLP[0] != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
        ++v4;
        ++v5;
      }
      while ( v4 <= codec->codecParms.numTilesWideMinusOne );
    }
    else if ( codec->tileQuantization->pQuantizerLP[0] != nullptr )
    {
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
    }
  }
  if ( codec->codecParms.subBands < SB_NO_HIGHPASS )
  {
    if ( (codec->codecParms.quantizationMode & 4) != 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        if ( codec->tileQuantization[v7].pQuantizerHP[0] != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
        ++v6;
        ++v7;
      }
      while ( v6 <= codec->codecParms.numTilesWideMinusOne );
    }
    else if ( codec->tileQuantization->pQuantizerHP[0] != nullptr )
    {
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
    }
  }
  if ( codec->tileQuantization != nullptr )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&codec->codecParms);
}


// ========================================================================
// ?SetUniformQuantizerDC@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FAAA8
// RVA : 0x008FAAA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall SetUniformQuantizerDC(hdpCodec_t *codec)
{
  unsigned int v1; // r7
  unsigned int numTilesWideMinusOne; // r9
  int v3; // r8
  unsigned int v4; // r10
  int v5; // r11

  v1 = 0;
  if ( codec->codecParms.numChannels != 0 )
  {
    numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
    v3 = 0;
    do
    {
      v4 = 1;
      if ( numTilesWideMinusOne != 0 )
      {
        v5 = v3 * 4 + 196;
        do
        {
          ++v4;
          *(hdpQuantizer_t **)((char *)codec->tileQuantization->pQuantizerDC + v5) = codec->tileQuantization->pQuantizerDC[v3];
          v5 += 196;
          numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
        }
        while ( v4 <= numTilesWideMinusOne );
      }
      ++v1;
      ++v3;
    }
    while ( v1 < codec->codecParms.numChannels );
  }
}


// ========================================================================
// ?SetUniformQuantizerLP@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FAB08
// RVA : 0x008FAB08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall SetUniformQuantizerLP(hdpCodec_t *codec)
{
  unsigned int v1; // r6
  unsigned int numTilesWideMinusOne; // r9
  int v3; // r7
  unsigned int v4; // r10
  int v5; // r11

  v1 = 0;
  if ( codec->codecParms.numChannels != 0 )
  {
    numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
    v3 = 65;
    do
    {
      v4 = 1;
      if ( numTilesWideMinusOne != 0 )
      {
        v5 = v3 * 4;
        do
        {
          ++v4;
          *(hdpQuantizer_t **)((char *)codec->tileQuantization->pQuantizerDC + v5) = codec->tileQuantization[-1].pQuantizerDC[v3];
          v5 += 196;
          numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
        }
        while ( v4 <= numTilesWideMinusOne );
      }
      ++v1;
      ++v3;
    }
    while ( v1 < codec->codecParms.numChannels );
  }
}


// ========================================================================
// ?SetUniformQuantizerHP@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FAB70
// RVA : 0x008FAB70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall SetUniformQuantizerHP(hdpCodec_t *codec)
{
  unsigned int v1; // r6
  unsigned int numTilesWideMinusOne; // r9
  int v3; // r7
  unsigned int v4; // r10
  int v5; // r11

  v1 = 0;
  if ( codec->codecParms.numChannels != 0 )
  {
    numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
    v3 = 81;
    do
    {
      v4 = 1;
      if ( numTilesWideMinusOne != 0 )
      {
        v5 = v3 * 4;
        do
        {
          ++v4;
          *(hdpQuantizer_t **)((char *)codec->tileQuantization->pQuantizerDC + v5) = codec->tileQuantization[-1].pQuantizerDC[v3];
          v5 += 196;
          numTilesWideMinusOne = codec->codecParms.numTilesWideMinusOne;
        }
        while ( v4 <= numTilesWideMinusOne );
      }
      ++v1;
      ++v3;
    }
    while ( v1 < codec->codecParms.numChannels );
  }
}


// ========================================================================
// ?UseDCQuantizerForLP@@YAXPAUhdpCodec_t@@I@Z
// EA  : 0x828FABD8
// RVA : 0x008FABD8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall UseDCQuantizerForLP(hdpCodec_t *codec, unsigned int iTile)
{
  unsigned int v2; // r11
  unsigned int v3; // r10
  unsigned int v4; // r9
  hdpTileQuantization_t *tileQuantization; // r7
  int v6; // r5
  int v7; // r4
  hdpQuantizer_t *v8; // r8
  hdpQuantizer_t *v9; // r7

  v2 = 0;
  if ( codec->codecParms.numChannels != 0 )
  {
    v3 = 49 * iTile;
    v4 = 49 * iTile + 16;
    do
    {
      tileQuantization = codec->tileQuantization;
      v6 = v3 + v2;
      v7 = v4 + v2++;
      v8 = tileQuantization->pQuantizerDC[v6];
      v9 = tileQuantization->pQuantizerDC[v7];
      v9->iQP = v8->iQP;
      v9->iRound = v8->iRound;
      v9->iMan = v8->iMan;
      *(_DWORD *)&v9->iExp = *(_DWORD *)&v8->iExp;
    }
    while ( v2 < codec->codecParms.numChannels );
  }
}


// ========================================================================
// ?UseLPQuantizerForHP@@YAXPAUhdpCodec_t@@II@Z
// EA  : 0x828FAC40
// RVA : 0x008FAC40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

void __fastcall UseLPQuantizerForHP(hdpCodec_t *codec, unsigned int numQuantizers, unsigned int iTile)
{
  unsigned int i; // r31
  unsigned int v4; // r9
  int v5; // r11
  unsigned int v6; // r10
  hdpTileQuantization_t *tileQuantization; // r30
  hdpQuantizer_t *v8; // r7
  hdpQuantizer_t *v9; // r8

  for ( i = 0; i < codec->codecParms.numChannels; ++i )
  {
    if ( numQuantizers != 0 )
    {
      v4 = 49 * iTile + i;
      v5 = 0;
      v6 = numQuantizers;
      do
      {
        tileQuantization = codec->tileQuantization;
        --v6;
        v8 = &tileQuantization->pQuantizerHP[v4][v5];
        v9 = &tileQuantization->pQuantizerLP[v4][v5++];
        v8->iQP = v9->iQP;
        v8->iRound = v9->iRound;
        v8->iMan = v9->iMan;
        *(_DWORD *)&v8->iExp = *(_DWORD *)&v9->iExp;
      }
      while ( v6 != 0 );
    }
  }
}


// ========================================================================
// ?GetQuantizerBits@@YAEE@Z
// EA  : 0x828FACE0
// RVA : 0x008FACE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.cpp
// ========================================================================

int __fastcall GetQuantizerBits(unsigned __int8 numQuantizers)
{
  if ( numQuantizers < 2u )
    return 0;
  if ( numQuantizers < 4u )
    return 1;
  if ( numQuantizers >= 6u )
    return (unsigned __int8)((numQuantizers >= 0xAu) - 1 + 4);
  return 2;
}

