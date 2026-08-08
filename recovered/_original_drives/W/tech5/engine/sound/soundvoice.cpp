
// ========================================================================
// ?InitSurround@idSoundVoice_Base@@SAXHH@Z
// EA  : 0x82992FA0
// RVA : 0x00992FA0
// PDB : w:\tech5\engine\sound\soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_Base::InitSurround(unsigned int outputChannels, int channelMask)
{
  int v2; // ctr
  int *v5; // r11
  int *v6; // r9
  int v7; // r11
  int v8; // r10
  int v9; // r8
  int v10; // r6
  int v11; // r5
  double v12; // fp0

  v2 = 8;
  idSoundVoice_Base::speakerLeft[9] = 4;
  idSoundVoice_Base::speakerLeft[6] = 0;
  idSoundVoice_Base::speakerLeft[0] = 9;
  idSoundVoice_Base::speakerLeft[4] = 8;
  idSoundVoice_Base::speakerLeft[8] = 5;
  idSoundVoice_Base::speakerLeft[10] = 1;
  idSoundVoice_Base::speakerLeft[1] = 7;
  idSoundVoice_Base::speakerLeft[2] = 2;
  idSoundVoice_Base::speakerLeft[5] = 10;
  idSoundVoice_Base::speakerLeft[3] = 3;
  idSoundVoice_Base::speakerRight[1] = 10;
  idSoundVoice_Base::speakerLeft[7] = 6;
  idSoundVoice_Base::speakerRight[10] = 5;
  idSoundVoice_Base::speakerRight[8] = 4;
  idSoundVoice_Base::speakerRight[7] = 1;
  idSoundVoice_Base::speakerRight[4] = 9;
  idSoundVoice_Base::speakerRight[0] = 6;
  idSoundVoice_Base::speakerRight[5] = 8;
  idSoundVoice_Base::speakerRight[6] = 7;
  idSoundVoice_Base::speakerRight[3] = 3;
  idSoundVoice_Base::speakerRight[9] = 0;
  idSoundVoice_Base::dstLFE = -1;
  idSoundVoice_Base::dstCenter = -1;
  idSoundVoice_Base::speakerRight[2] = 2;
  v5 = &idSoundVoice_Base::dstMask;
  idSoundVoice_Base::dstChannels = outputChannels;
  idSoundVoice_Base::dstMask = channelMask;
  do
  {
    *++v5 = 0;
    --v2;
  }
  while ( v2 != 0 );
  memset(Dst: idSoundVoice_Base::invMap, Val: 0, Size: sizeof(idSoundVoice_Base::invMap));
  v6 = idSoundVoice_Base::dstMap;
  v7 = 0;
  v8 = 0;
  v9 = 1;
  do
  {
    if ( (int)v6 >= (int)idSoundVoice_Base::invMap )
      break;
    if ( (v9 & channelMask) != 0 )
    {
      if ( v7 == 3 )
      {
        idSoundVoice_Base::dstLFE = v8;
      }
      else if ( v7 == 2 )
      {
        idSoundVoice_Base::dstCenter = v8;
      }
      *v6++ = v7;
      idSoundVoice_Base::invMap[v7] = v8++;
    }
    else
    {
      v10 = idSoundVoice_Base::speakerRight[v7];
      v11 = idSoundVoice_Base::speakerLeft[v7];
      idSoundVoice_Base::speakerLeft[v10] = v11;
      idSoundVoice_Base::speakerRight[v11] = v10;
    }
    ++v7;
    v9 = __ROL4__(v9, 1);
  }
  while ( v7 < 11 );
  v12 = (float)__SPAIR64__(0x82000000, outputChannels);
  if ( (channelMask & 8) != 0 )
    v12 = (float)((float)__SPAIR64__(0x82000000, outputChannels) - (float)1.0);
  if ( (channelMask & 4) != 0 )
    v12 = (float)((float)v12 - (float)1.0);
  if ( v12 <= 0.0 )
    idSoundVoice_Base::omniLevel = 1.0;
  else
    idSoundVoice_Base::omniLevel = (float)1.0 / (float)v12;
}


// ========================================================================
// ?CalculateChannelSurrond@idSoundVoice_Base@@IAAXHHPAMPAHABVidVec2@@MMM@Z
// EA  : 0x829931C8
// RVA : 0x009931C8
// PDB : w:\tech5\engine\sound\soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_Base::CalculateChannelSurrond(
        idSoundVoice_Base *this,
        int s,
        int srcChannels,
        float *pLevelMatrix,
        int *srcMap,
        const idVec2 *p,
        double lfeLevel,
        double centerLevel,
        double scale)
{
  double centerChannel; // fp11
  double v10; // fp0
  int v11; // r11
  float *v12; // r10
  __int64 v13; // r8
  float *v14; // r11
  int v16; // ctr
  double v18; // fp12
  double v19; // fp8
  double v20; // fp8
  double v21; // fp13
  double v22; // fp12
  double v23; // fp0
  int v24; // r10
  int v25; // r23
  int v26; // r31
  int v27; // r11
  idVec2 *v28; // r9
  int v29; // r7
  double y; // fp8
  idVec2 *v31; // r9
  int v32; // r8
  double v33; // fp6
  double v34; // fp4
  double v35; // fp7
  double v36; // fp5
  double v37; // fp31
  double v38; // fp30
  double v39; // fp4
  int v40; // r11
  int v41; // ctr
  int v42; // r7
  int v43; // r28
  int v44; // r11
  int v45; // r31
  int v46; // r9
  int v47; // r27
  float *v48; // r10
  int v49; // r10
  int v50; // r11
  int v51; // ctr
  int v52; // r9
  int v53; // r9
  idVec2 *v54; // r11
  double v55; // fp5
  int *v56; // r8
  int v57; // r10
  double v58; // fp6
  double v59; // fp5
  idVec2 *v60; // r11
  double v61; // fp7
  int v62; // r8
  double v63; // fp8
  double v64; // fp7
  double v65; // fp0
  double v66; // fp13
  int v67; // r11
  float *v68; // r10
  int v69; // r11
  float *v70; // r10
  int v71; // r10
  float *v72; // r11
  float v73[2]; // [sp+10h] [-A0h] BYREF
  _BYTE v74[32]; // [sp+18h] [-98h] BYREF

  centerChannel = this->centerChannel;
  v10 = (float)((float)(p->x * p->x) + (float)(p->y * p->y));
  if ( v10 == 0.0 )
  {
    v11 = 0;
    if ( idSoundVoice_Base::dstChannels > 0 )
    {
      v12 = &pLevelMatrix[s];
      do
      {
        if ( v11 != idSoundVoice_Base::dstLFE && v11 != idSoundVoice_Base::dstCenter )
          *v12 = idSoundVoice_Base::omniLevel;
        ++v11;
        v12 += srcChannels;
      }
      while ( v11 < idSoundVoice_Base::dstChannels );
    }
  }
  else
  {
    v13 = (__int64)*p;
    v14 = v73;
    v73[0] = 0.0;
    _FP8 = (float)((float)v10 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v16 = 7;
    __asm { fsel      f4, f8, f0, f12 }
    v18 = __frsqrte(_FP4);
    v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)v10 * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18)
                                                * (float)((float)v10 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v18
                                                                                * (float)((float)v10 * (float)0.5))
                                                                        * (float)v18)
                                                                - (float)1.5)
                                                * (float)v18))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v10 * (float)0.5)) * (float)v18)
                                        - (float)1.5)
                        * (float)v18));
    v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v10 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                                * (float)v18)
                                                                                        * (float)((float)v10 * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v10 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                        * (float)v18))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v18
                                                                                                * (float)((float)v10 * (float)0.5))
                                                                                        * (float)v18)
                                                                                - (float)1.5)
                                                                * (float)v18))
                                                * (float)((float)v10 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v10 * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                        * (float)v18)
                                                                                * (float)((float)v10 * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v10 * (float)0.5)) * (float)v18)
                                                                                                - (float)1.5)
                                                                                * (float)v18))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)v10 * (float)0.5))
                                                                                * (float)v18)
                                                                        - (float)1.5)
                                                        * (float)v18)))
                                - (float)1.5)
                * (float)v19);
    v21 = (float)(-9.4039548e-38 * (float)v20);
    v22 = (float)((float)v20 * (float)v10);
    v23 = (float)(*((float *)&v13 + 1) * (float)v20);
    centerChannel = (float)((float)(-9.4039548e-38 * (float)v20) * (float)centerChannel);
    do
    {
      *++v14 = 0.0;
      --v16;
    }
    while ( v16 != 0 );
    v24 = 0;
    v25 = idSoundVoice_Base::dstChannels;
    if ( idSoundVoice_Base::dstChannels >= 4 )
    {
      v26 = idSoundVoice_Base::dstChannels - 3;
      v27 = 0;
      do
      {
        v28 = &speakerPositions[idSoundVoice_Base::dstMap[v27]];
        v29 = idSoundVoice_Base::dstMap[v27 + 2];
        y = v28->y;
        v32 = idSoundVoice_Base::dstMap[v27 + 3];
        v33 = (float)((float)v21 * v28->x);
        v31 = &speakerPositions[idSoundVoice_Base::dstMap[v27 + 1]];
        v24 += 4;
        v34 = (float)((float)v21 * speakerPositions[v29].x);
        v35 = v31->y;
        v36 = (float)((float)v21 * v31->x);
        v37 = (float)((float)v21 * speakerPositions[v32].x);
        v38 = speakerPositions[v29].y;
        v73[v27] = (float)((float)y * (float)v23) + (float)v33;
        *(float *)&v74[v27 * 4] = (float)((float)v38 * (float)v23) + (float)v34;
        v39 = speakerPositions[v32].y;
        v73[v27 + 1] = (float)((float)v35 * (float)v23) + (float)v36;
        *(float *)&v74[v27 * 4 + 4] = (float)((float)v39 * (float)v23) + (float)v37;
        v27 += 4;
      }
      while ( v24 < v26 );
    }
    if ( v24 < v25 )
    {
      v40 = v24;
      v41 = v25 - v24;
      do
      {
        v73[v40] = (float)(speakerPositions[idSoundVoice_Base::dstMap[v40]].y * (float)v23)
                 + (float)((float)v21 * speakerPositions[idSoundVoice_Base::dstMap[v40]].x);
        ++v40;
        --v41;
      }
      while ( v41 != 0 );
    }
    v42 = 0;
    v43 = 1;
    if ( v25 > 1 )
    {
      if ( v25 - 1 >= 4 )
      {
        v44 = 0;
        v45 = 1;
        v46 = 3;
        v47 = 8;
        do
        {
          v48 = &v73[v45 + 1];
          if ( v73[v45] > (double)*(float *)((char *)v73 + v44) )
          {
            v42 = v43;
            v44 = v45 * 4;
          }
          if ( *v48 > (double)*(float *)((char *)v73 + v44) )
          {
            v42 = v46 - 1;
            v44 = v47;
          }
          if ( v48[1] > (double)*(float *)((char *)v73 + v44) )
          {
            v42 = v46;
            v44 = (int)v48 + 12 - (_DWORD)v74;
          }
          if ( v48[2] > (double)*(float *)((char *)v73 + v44) )
          {
            v42 = v46 + 1;
            v44 = (int)v48 + 16 - (_DWORD)v74;
          }
          v43 += 4;
          v46 += 4;
          v45 += 4;
          v47 += 16;
        }
        while ( v43 < v25 - 3 );
      }
      if ( v43 < v25 )
      {
        v49 = 4 * v42;
        v50 = v43;
        v51 = v25 - v43;
        do
        {
          if ( v73[v50] > (double)*(float *)((char *)v73 + v49) )
          {
            v42 = v43;
            v49 = v50 * 4;
          }
          ++v43;
          ++v50;
          --v51;
        }
        while ( v51 != 0 );
      }
    }
    v52 = idSoundVoice_Base::dstMap[v42];
    v54 = &speakerPositions[v52];
    v55 = (float)((float)(v54->x * (float)v23) - (float)(speakerPositions[v52].y * (float)v21));
    v53 = v52;
    if ( v55 <= 0.0 )
      v56 = idSoundVoice_Base::speakerRight;
    else
      v56 = idSoundVoice_Base::speakerLeft;
    v57 = v56[v53];
    v58 = (float)(v54->y - (float)v23);
    v59 = (float)(v54->x - (float)v21);
    v60 = &speakerPositions[v57];
    v61 = (float)(v60->y - (float)v23);
    v62 = idSoundVoice_Base::invMap[v57];
    v63 = __fsqrts((float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)));
    v64 = __fsqrts((float)((float)((float)(v60->x - (float)v21) * (float)(v60->x - (float)v21))
                         + (float)((float)v61 * (float)v61)));
    pLevelMatrix[v42 * srcChannels + s] = (float)((float)1.0 / (float)((float)v64 + (float)v63)) * (float)v64;
    pLevelMatrix[v62 * srcChannels + s] = (float)((float)1.0 / (float)((float)v64 + (float)v63)) * (float)v63;
    if ( v22 < this->innerRadius )
    {
      v65 = (float)((float)v22 / this->innerRadius);
      v66 = (float)((float)((float)1.0 - (float)((float)v22 / this->innerRadius)) * idSoundVoice_Base::omniLevel);
      if ( v66 >= 0.00000011920929 )
      {
        v67 = 0;
        if ( idSoundVoice_Base::dstChannels > 0 )
        {
          v68 = &pLevelMatrix[s];
          do
          {
            if ( v67 != idSoundVoice_Base::dstLFE && v67 != idSoundVoice_Base::dstCenter )
              *v68 = (float)(*v68 * (float)v65) + (float)v66;
            ++v67;
            v68 += srcChannels;
          }
          while ( v67 < idSoundVoice_Base::dstChannels );
        }
      }
    }
  }
  if ( idSoundVoice_Base::dstLFE != -1 )
    pLevelMatrix[idSoundVoice_Base::dstLFE * srcChannels + s] = lfeLevel;
  if ( idSoundVoice_Base::dstCenter != -1 && centerChannel > 0.0 )
  {
    v69 = 0;
    pLevelMatrix[idSoundVoice_Base::dstCenter * srcChannels + s] = (float)centerChannel * (float)centerLevel;
    if ( idSoundVoice_Base::dstChannels > 0 )
    {
      v70 = &pLevelMatrix[s];
      do
      {
        if ( v69 != idSoundVoice_Base::dstLFE && v69 != idSoundVoice_Base::dstCenter )
          *v70 = (float)((float)1.0 - (float)centerChannel) * *v70;
        ++v69;
        v70 += srcChannels;
      }
      while ( v69 < idSoundVoice_Base::dstChannels );
    }
  }
  v71 = 0;
  if ( idSoundVoice_Base::dstChannels > 0 )
  {
    v72 = &pLevelMatrix[s];
    do
    {
      ++v71;
      *v72 = (float)scale * *v72;
      v72 += srcChannels;
    }
    while ( v71 < idSoundVoice_Base::dstChannels );
  }
}


// ========================================================================
// ?CalculateSurround@idSoundVoice_Base@@QAAXHIQAMMH@Z
// EA  : 0x829937F0
// RVA : 0x009937F0
// PDB : w:\tech5\engine\sound\soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_Base::CalculateSurround(
        idSoundVoice_Base *this,
        int srcChannels,
        unsigned int srcMask,
        float *pLevelMatrix,
        double scale,
        int startFlags,
        int a7)
{
  int v9; // r4
  int *v10; // r10
  int i; // ctr
  char *v12; // r11
  int v13; // r25
  int v14; // r27
  int v15; // r9
  int v16; // r10
  int v17; // r7
  double z; // fp13
  double y; // fp3
  double innerSampleRangeSqr; // fp2
  double v21; // fp12
  double v22; // fp0
  double gainLFE; // fp1
  double v24; // fp0
  double v25; // fp31
  float *v26; // r6
  idSoundVoice_Base *v27; // r3
  double v28; // fp2
  __int64 v29; // r11
  double v30; // fp1
  double v31; // fp2
  int *v32; // r29
  double v33; // fp0
  double v34; // fp13
  double v35; // fp12
  idVec2 *v36; // r11
  double v37; // fp0
  double v38; // fp6
  idVec2 v39; // [sp+60h] [-B0h] BYREF
  idVec2 v40; // [sp+70h] [-A0h]
  char v41; // [sp+7Ch] [-94h] BYREF
  int v42[14]; // [sp+80h] [-90h] BYREF

  v9 = 0;
  v10 = v42;
  v42[0] = 0;
  for ( i = 10; i != 0; --i )
    *++v10 = 0;
  if ( this->channelMask != 0 )
    srcMask = this->channelMask;
  v12 = &v41;
  v13 = -1;
  v14 = -1;
  v15 = 0;
  v16 = 0;
  v17 = 1;
  do
  {
    if ( v16 >= 8 )
      break;
    if ( (v17 & srcMask) != 0 )
    {
      if ( v15 == 3 )
      {
        v13 = v16;
      }
      else if ( v15 == 2 && (srcMask & 1) != 0 )
      {
        v14 = v16;
      }
      v12 += 4;
      *(_DWORD *)v12 = v15;
      ++v16;
    }
    ++v15;
    v17 = __ROL4__(v17, 1);
  }
  while ( v15 < 11 );
  if ( (a7 & 0x80000) != 0 && srcChannels == 2 )
  {
    z = this->position.z;
    y = this->invListenerAxis.mat[2].y;
    innerSampleRangeSqr = this->innerSampleRangeSqr;
    v21 = (float)((float)(this->invListenerAxis.mat[0].y * this->position.x)
                + (float)(this->invListenerAxis.mat[1].y * this->position.y));
    v22 = (float)((float)(this->position.x * this->invListenerAxis.mat[0].x)
                + (float)((float)(this->invListenerAxis.mat[1].x * this->position.y)
                        + (float)(this->invListenerAxis.mat[2].x * this->position.z)));
    v39.x = (float)(this->position.x * this->invListenerAxis.mat[0].x)
          + (float)((float)(this->invListenerAxis.mat[1].x * this->position.y)
                  + (float)(this->invListenerAxis.mat[2].x * this->position.z));
    gainLFE = this->gainLFE;
    v39.y = (float)((float)y * (float)z) + (float)v21;
    v24 = (float)((float)(v39.y * v39.y) + (float)((float)v22 * (float)v22));
    if ( v24 >= innerSampleRangeSqr )
    {
      if ( v24 <= this->outerSampleRangeSqr )
      {
        v25 = (float)((float)((float)v24 - this->innerSampleRangeSqr)
                    / (float)(this->outerSampleRangeSqr - this->innerSampleRangeSqr));
        idSoundVoice_Base::CalculateChannelSurrond(
          this,
          s: 0,
          srcChannels: 2,
          pLevelMatrix,
          srcMap: v42,
          p: &v39,
          lfeLevel: gainLFE,
          centerLevel: 1.0,
          scale: (float)((float)((float)1.0
                        - (float)((float)((float)v24 - this->innerSampleRangeSqr)
                                / (float)(this->outerSampleRangeSqr - this->innerSampleRangeSqr)))
                * (float)scale));
        idSoundVoice_Base::CalculateChannelSurrond(
          this: v27,
          s: 1,
          srcChannels: 2,
          pLevelMatrix: v26,
          srcMap: v42,
          p: &v39,
          lfeLevel: v27->gainLFE,
          centerLevel: v28,
          scale: (float)((float)v25 * (float)scale));
      }
      else
      {
        idSoundVoice_Base::CalculateChannelSurrond(
          this,
          s: 1,
          srcChannels: 2,
          pLevelMatrix,
          srcMap: v42,
          p: &v39,
          lfeLevel: gainLFE,
          centerLevel: 1.0,
          scale);
      }
    }
    else
    {
      idSoundVoice_Base::CalculateChannelSurrond(
        this,
        s: 0,
        srcChannels: 2,
        pLevelMatrix,
        srcMap: v42,
        p: &v39,
        lfeLevel: gainLFE,
        centerLevel: 1.0,
        scale);
    }
    return;
  }
  HIDWORD(v29) = 0x82000000;
  v30 = 0.0;
  v31 = 0.0;
  if ( v13 == -1 )
  {
    LODWORD(v29) = srcChannels;
    v30 = (float)(this->gainLFE * (float)((float)1.0 / (float)v29));
    v39 = (idVec2)v29;
    if ( v14 == -1 )
      v31 = (float)((float)1.0 / (float)v29);
  }
  else if ( v14 == -1 )
  {
    LODWORD(v29) = srcChannels;
    v39 = (idVec2)v29;
    v31 = (float)((float)1.0 / (float)((float)v29 - (float)1.0));
  }
  if ( srcChannels > 0 )
  {
    v32 = v42;
    do
    {
      if ( v9 == v13 )
      {
        if ( idSoundVoice_Base::dstLFE != -1 )
          pLevelMatrix[idSoundVoice_Base::dstLFE * srcChannels + v13] = 1.0;
      }
      else
      {
        v33 = 0.0;
        v34 = 0.0;
        v35 = 0.0;
        if ( srcChannels > 1 )
        {
          v36 = &speakerPositions[*v32];
          v33 = (float)((float)(this->axis.mat[2].x * (float)0.0)
                      + (float)((float)(this->axis.mat[1].x * (float)(v36->y * this->innerRadius))
                              + (float)(this->axis.mat[0].x * (float)(v36->x * this->innerRadius))));
          v34 = (float)((float)(this->axis.mat[2].y * (float)0.0)
                      + (float)((float)(this->axis.mat[1].y * (float)(v36->y * this->innerRadius))
                              + (float)(this->axis.mat[0].y * (float)(v36->x * this->innerRadius))));
          v35 = (float)((float)(this->axis.mat[2].z * (float)0.0)
                      + (float)((float)(this->axis.mat[1].z * (float)(v36->y * this->innerRadius))
                              + (float)(this->axis.mat[0].z * (float)(v36->x * this->innerRadius))));
        }
        v37 = (float)(this->position.x + (float)v33);
        v38 = (float)((float)(this->invListenerAxis.mat[0].y * (float)v37)
                    + (float)((float)(this->invListenerAxis.mat[2].y * (float)(this->position.z + (float)v35))
                            + (float)(this->invListenerAxis.mat[1].y * (float)(this->position.y + (float)v34))));
        v40.x = (float)((float)v37 * this->invListenerAxis.mat[0].x)
              + (float)((float)(this->invListenerAxis.mat[2].x * (float)(this->position.z + (float)v35))
                      + (float)(this->invListenerAxis.mat[1].x * (float)(this->position.y + (float)v34)));
        v40.y = v38;
        v39 = v40;
        if ( v9 == v14 )
        {
          if ( idSoundVoice_Base::dstCenter != -1 )
          {
            pLevelMatrix[idSoundVoice_Base::dstCenter * srcChannels + v14] = 1.0;
            if ( idSoundVoice_Base::dstLFE != -1 )
              pLevelMatrix[idSoundVoice_Base::dstLFE * srcChannels + v9] = v30;
            goto LABEL_40;
          }
          v39.x = this->innerRadius;
          v39.y = 0.0;
        }
        idSoundVoice_Base::CalculateChannelSurrond(
          this,
          s: v9,
          srcChannels,
          pLevelMatrix,
          srcMap: v42,
          p: &v39,
          lfeLevel: v30,
          centerLevel: v31,
          scale);
      }
LABEL_40:
      ++v9;
      ++v32;
    }
    while ( v9 < srcChannels );
  }
}


// ========================================================================
// ??0idSoundVoice_Base@@QAA@XZ
// EA  : 0x82993BF0
// RVA : 0x00993BF0
// PDB : w:\tech5\engine\sound\soundvoice.cpp
// ========================================================================

idSoundVoice_Base *__fastcall idSoundVoice_Base::idSoundVoice_Base(idSoundVoice_Base *this)
{
  this->position.x = 0.0;
  this->position.y = 0.0;
  this->position.z = 0.0;
  this->velocity.x = 0.0;
  this->velocity.y = 0.0;
  this->velocity.z = 0.0;
  this->channelMask = 0;
  this->gain = 1.0;
  this->dryGain = 1.0;
  this->wetGain = 1.0;
  this->gainLFE = 1.0;
  this->centerChannel = 0.0;
  this->pitch = 1.0;
  this->innerRadius = 32.0;
  this->occlusion = 0.0;
  this->innerSampleRangeSqr = 0.0;
  this->outerSampleRangeSqr = 0.0;
  this->samples.list = nullptr;
  this->samples.granularity = 0;
  this->samples.memTag = 5;
  this->samples.listStatic = 0;
  this->samples.size = 0;
  this->samples.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->samples);
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->invListenerAxis.mat[2].z = 1.0;
  this->invListenerAxis.mat[1].y = 1.0;
  this->invListenerAxis.mat[0].x = 1.0;
  this->invListenerAxis.mat[1].z = 0.0;
  this->invListenerAxis.mat[0].z = 0.0;
  this->invListenerAxis.mat[0].y = 0.0;
  this->invListenerAxis.mat[2].y = 0.0;
  this->invListenerAxis.mat[2].x = 0.0;
  this->invListenerAxis.mat[1].x = 0.0;
  return this;
}


// ========================================================================
// ?SelectSample@idSoundVoice_Base@@IAAPAVidSoundSample@@PAV2@@Z
// EA  : 0x82993CF8
// RVA : 0x00993CF8
// PDB : w:\tech5\engine\sound\soundvoice.cpp
// ========================================================================

idSoundSample *__fastcall idSoundVoice_Base::SelectSample(
        idSoundVoice_Base *this,
        idMapChangeListener *previousSample,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapChangeListener *a14)
{
  int num; // r11
  int v18; // r11
  idList<idSoundSample *,5> *p_samples; // r11
  idSoundSample *v20; // r31
  int v21; // r3

  num = this->samples.num;
  a14 = previousSample;
  if ( num == 1 )
    return *this->samples.list;
  if ( previousSample != nullptr )
    idList<void *,108>::RemoveFast(this: (idList<idMapChangeListener *,5> *)&this->samples, obj: &a14);
  v18 = this->samples.num;
  if ( v18 == 1 )
  {
    p_samples = &this->samples;
    v20 = *this->samples.list;
  }
  else
  {
    v21 = idRandom2::RandomInt(this: &soundSystemLocal.random, min: 0, max: v18 - 1);
    p_samples = &this->samples;
    v20 = this->samples.list[v21];
  }
  if ( previousSample != nullptr )
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)p_samples,
      obj: (const encounterGroupRole_t *)&a14);
  return v20;
}

