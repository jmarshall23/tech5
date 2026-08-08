
// ========================================================================
// DecodeBitArray
// EA  : 0x828279C8
// RVA : 0x008279C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

unsigned int __fastcall DecodeBitArray(const unsigned __int8 *bits, unsigned int numBits, unsigned __int8 *indices)
{
  unsigned int result; // r3
  int v5; // r11
  const unsigned __int8 *v6; // r8
  unsigned int v7; // r10
  int v8; // r9
  int v9; // r9
  int v10; // r9
  int v11; // r9
  BOOL v12; // r6
  int v13; // r9
  unsigned int v14; // r7
  int v15; // r10
  int v16; // r10
  int v17; // r11
  unsigned __int8 v18; // r9

  result = 0;
  if ( numBits != 0 )
  {
    v5 = 2;
    v6 = bits - 1;
    do
    {
      v7 = *++v6;
      indices[result] = v5 - 2;
      v8 = (v7 & 1) + result;
      indices[v8] = v5 - 1;
      v9 = ((v7 & 2) != 0) + v8;
      indices[v9] = v5;
      v10 = ((v7 & 4) != 0) + v9;
      indices[v10] = v5 + 1;
      v11 = ((v7 & 8) != 0) + v10;
      v12 = (v7 & 0x40) != 0;
      indices[v11] = v5 + 2;
      v13 = ((v7 & 0x10) != 0) + v11;
      v14 = v7 >> 7;
      v15 = ((v7 & 0x20) != 0) + v13;
      indices[v13] = v5 + 3;
      indices[v15] = v5 + 4;
      v16 = v12 + v15;
      result = v14 + v16;
      indices[v16] = v5 + 5;
      v5 += 8;
    }
    while ( v5 - 2 < numBits );
    if ( result != 0 )
    {
      v17 = 0;
      v18 = indices[result - 1];
      if ( (result & 7) != 0 )
      {
        do
          indices[result + v17++] = v18;
        while ( ((v17 + result) & 7) != 0 );
      }
    }
  }
  return result;
}


// ========================================================================
// ?VerifyRLEData@idMD6Anim@@ABAXPBDABV?$idList@E$04@@1111111@Z
// EA  : 0x82827AC8
// RVA : 0x00827AC8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall idMD6Anim::VerifyRLEData(
        idMD6Anim *this,
        const char *animName,
        const idList<unsigned char,5> *RRLE,
        const idList<unsigned char,5> *SRLE,
        const idList<unsigned char,5> *TRLE,
        const idList<unsigned char,5> *URLE,
        const idList<unsigned char,5> *RBits,
        const idList<unsigned char,5> *SBits,
        const idList<unsigned char,5> *TBits,
        const idList<unsigned char,5> *UBits,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30)
{
  int v32; // r31
  unsigned int v37; // r30
  unsigned int v38; // r27
  unsigned int v39; // r26
  unsigned int v40; // r25
  signed int v41; // r21
  signed int v42; // r29
  signed int v43; // r28
  signed int v44; // r3
  unsigned __int8 *v45; // r10
  unsigned __int8 *v46; // r11
  int v47; // r9
  int v48; // r7
  unsigned __int8 *v49; // r10
  unsigned __int8 *v50; // r11
  int v51; // r9
  int v52; // r7
  unsigned __int8 *v53; // r10
  unsigned __int8 *v54; // r11
  int v55; // r9
  int v56; // r7
  unsigned __int8 *v57; // r10
  unsigned __int8 *v58; // r11
  int v59; // r8
  int v60; // r7
  unsigned __int8 v61[272]; // [sp+50h] [-8E0h] BYREF
  unsigned __int8 v62[272]; // [sp+160h] [-7D0h] BYREF
  unsigned __int8 v63[272]; // [sp+270h] [-6C0h] BYREF
  unsigned __int8 v64[272]; // [sp+380h] [-5B0h] BYREF
  unsigned __int8 v65[272]; // [sp+490h] [-4A0h] BYREF
  unsigned __int8 v66[272]; // [sp+5A0h] [-390h] BYREF
  unsigned __int8 v67[272]; // [sp+6B0h] [-280h] BYREF
  unsigned __int8 v68[368]; // [sp+7C0h] [-170h] BYREF

  v32 = 0;
  memset(v63, 0, sizeof(v63));
  memset(v61, 0, sizeof(v61));
  memset(v64, 0, sizeof(v64));
  memset(v68, 0, 272);
  v37 = DecodeBitArray(bits: RBits->list, numBits: 8 * RBits->num, indices: v63);
  v38 = DecodeBitArray(bits: SBits->list, numBits: 8 * SBits->num, indices: v61);
  v39 = DecodeBitArray(bits: *(const unsigned __int8 **)a28, numBits: 8 * *(_DWORD *)(a28 + 4), indices: v64);
  v40 = DecodeBitArray(bits: *(const unsigned __int8 **)a30, numBits: 8 * *(_DWORD *)(a30 + 4), indices: v68);
  memset(v65, 0, sizeof(v65));
  memset(v67, 0, sizeof(v67));
  memset(v62, 0, sizeof(v62));
  memset(v66, 0, sizeof(v66));
  v41 = idMD6Blend::DecodeRLE(RLE: RRLE->list, sentinel: 0xFFu, indices: v65);
  v42 = idMD6Blend::DecodeRLE(RLE: SRLE->list, sentinel: 0xFFu, indices: v67);
  v43 = idMD6Blend::DecodeRLE(RLE: TRLE->list, sentinel: 0xFFu, indices: v62);
  v44 = idMD6Blend::DecodeRLE(RLE: URLE->list, sentinel: 0xFFu, indices: v66);
  if ( v37 != v41 || v38 != v42 || v39 != v43 || v40 != v44 )
    goto LABEL_21;
  v45 = v65;
  v46 = v63;
  v47 = 0;
  if ( v37 != 0 )
  {
    do
    {
      v48 = *v45;
      v47 = *v46 - v48;
      if ( *v46 != v48 )
        break;
      ++v46;
      ++v45;
    }
    while ( v46 != &v63[v37] );
  }
  if ( v47 != 0 )
    goto LABEL_21;
  v49 = v67;
  v50 = v61;
  v51 = 0;
  if ( v38 != 0 )
  {
    do
    {
      v52 = *v49;
      v51 = *v50 - v52;
      if ( *v50 != v52 )
        break;
      ++v50;
      ++v49;
    }
    while ( v50 != &v61[v38] );
  }
  if ( v51 != 0 )
    goto LABEL_21;
  v53 = v62;
  v54 = v64;
  v55 = 0;
  if ( v39 != 0 )
  {
    do
    {
      v56 = *v53;
      v55 = *v54 - v56;
      if ( *v54 != v56 )
        break;
      ++v54;
      ++v53;
    }
    while ( v54 != &v64[v39] );
  }
  if ( v55 != 0 )
    goto LABEL_21;
  v57 = v66;
  v58 = v68;
  if ( v40 != 0 )
  {
    do
    {
      v59 = *v58;
      v60 = *v57;
      v32 = v59 - v60;
      if ( v59 != v60 )
        break;
      ++v58;
      ++v57;
    }
    while ( v58 != &v68[v40] );
  }
  if ( v32 != 0 )
LABEL_21:
    idLib::Warning(fmt: "idMD6AnimData::VerifyRLEData - Verification failed for %s", animName);
}


// ========================================================================
// ??0idMD6Anim@@QAA@XZ
// EA  : 0x82827D90
// RVA : 0x00827D90
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

idMD6Anim *__fastcall idMD6Anim::idMD6Anim(idMD6Anim *this)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idMD6Anim_vtbl *)&idMD6Anim::`vftable';
  this->skelName.str = &byte_8200D768;
  this->animData = nullptr;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->phaseTrack);
  this->jointConversionHandle.value = -1;
  this->jointConversionChecksum.value = -1;
  this->timestamp = -1;
  this->phaseTrackTimestamp = -1;
  this->settingsTimestamp = -1;
  this->timeCode = 0;
  this->startFrameOffset = 0;
  this->endFrameOffset = 0;
  this->translatedBounds.b[1][2] = 0;
  this->translatedBounds.b[1][1] = 0;
  this->translatedBounds.b[1][0] = 0;
  this->translatedBounds.b[0][2] = 0;
  this->translatedBounds.b[0][1] = 0;
  this->translatedBounds.b[0][0] = 0;
  this->normalizedBounds.b[1][2] = 0;
  this->normalizedBounds.b[1][1] = 0;
  this->normalizedBounds.b[1][0] = 0;
  this->normalizedBounds.b[0][2] = 0;
  this->normalizedBounds.b[0][1] = 0;
  this->normalizedBounds.b[0][0] = 0;
  this->origWorldPos.z = 0.0;
  this->origWorldPos.y = 0.0;
  this->origWorldPos.x = 0.0;
  this->origWorldRot.roll = 0.0;
  this->origWorldRot.yaw = 0.0;
  this->origWorldRot.pitch = 0.0;
  this->origWorldScale.x = 1.0;
  this->origWorldScale.y = 1.0;
  this->origWorldScale.z = 1.0;
  return this;
}


// ========================================================================
// __unwind$230431
// EA  : 0x82827EB0
// RVA : 0x00827EB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_230431()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idMD6Anim@@UAA@XZ
// EA  : 0x82827EF0
// RVA : 0x00827EF0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall idMD6Anim::~idMD6Anim(idMD6Anim *this)
{
  idMD6AnimData *animData; // r4

  this->__vftable = (idMD6Anim_vtbl *)&idMD6Anim::`vftable';
  animData = this->animData;
  if ( animData != nullptr )
  {
    idMem::Free(this: &mem, ptr: animData, align: ALIGN_16);
    this->animData = nullptr;
  }
  idMD6PhaseTrack::~idMD6PhaseTrack(this: &this->phaseTrack);
  idMD6PhaseTrack::~idMD6PhaseTrack(this: &this->phaseTrack);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$230497
// EA  : 0x82827F5C
// RVA : 0x00827F5C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_230497()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$230498
// EA  : 0x82827F84
// RVA : 0x00827F84
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_230498()
{
  int v0; // r12

  idMD6PhaseTrack::~idMD6PhaseTrack(this: (idMD6PhaseTrack *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// ?LoadAnim_UserChannels@idMD6Anim@@SAPAV1@PBD@Z
// EA  : 0x82827FB0
// RVA : 0x00827FB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

idMD6Anim *__fastcall idMD6Anim::LoadAnim_UserChannels(char *filename)
{
  idMD6Anim *result; // r3

  idMD6Anim::skipJoints = true;
  result = (idMD6Anim *)idResourceList::Load(
                          this: &idMD6Anim::resourceList,
                          name: filename,
                          makeDefault: false,
                          skipStaleCheck: true);
  idMD6Anim::skipJoints = false;
  return result;
}


// ========================================================================
// ?AnimIsOkForModel@idMD6Anim@@QBA_NPBVidMD6Model@@@Z
// EA  : 0x82828000
// RVA : 0x00828000
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

BOOL __fastcall idMD6Anim::AnimIsOkForModel(idMD6Anim *this, const idMD6Model *model)
{
  const idMD6Skel *skeleton; // r11
  idMD6AnimData *animData; // r10

  skeleton = model->skeleton;
  if ( skeleton == nullptr )
    return false;
  animData = this->animData;
  if ( animData == nullptr )
    return false;
  return skeleton->data->parentTblCrc.value == HIWORD(animData[1].totalSize)
      && (skeleton->jointConversion.value == 0xFFFF
       || skeleton->jointConversionChecksum.value == this->jointConversionChecksum.value)
      || skeleton->jointConversion.value != 0xFFFF
      && skeleton->jointConversionChecksum.value == this->jointConversionChecksum.value;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GetTargetMappedJointIndex
// EA  : 0x82828088
// RVA : 0x00828088
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedJointIndex(
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *sourceSkeleton,
        idIndex<short,enum invalidJointIndex_t> *targetSkeleton,
        int sourceJointIndex)
{
  idHandle<unsigned short,enum invalidJointHandle_t,65535> v5; // [sp+50h] [-20h] BYREF
  __int16 v6; // [sp+52h] [-1Eh] BYREF

  if ( sourceSkeleton == (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)targetSkeleton )
    return sourceJointIndex;
  idMD6Skel::GetJointHandle(this: (idMD6Skel *)&v5, result: sourceSkeleton, jointIdx: (unsigned __int8)sourceJointIndex);
  idMD6Skel::GetJointIndex(this: (idMD6Skel *)&v6, result: targetSkeleton, handle: &v5);
  if ( v6 < 0 )
    return (*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 2) + 7) & 0xF8;
  else
    return (unsigned __int8)v6;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GetTargetMappedUserChannelIndex
// EA  : 0x82828130
// RVA : 0x00828130
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedUserChannelIndex(
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *sourceSkeleton,
        idIndex<short,enum invalidUserChannelIndex_t> *targetSkeleton,
        int sourceUserChannelIndex)
{
  int result; // r3
  bool v6; // zf
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> v7; // [sp+50h] [-20h] BYREF
  __int16 v8; // [sp+52h] [-1Eh] BYREF

  v6 = sourceSkeleton == nullptr;
  result = sourceUserChannelIndex;
  if ( !v6
    && targetSkeleton != nullptr
    && sourceSkeleton != (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)targetSkeleton )
  {
    idMD6Skel::GetUserChannelHandle(
      this: (idMD6Skel *)&v7,
      result: sourceSkeleton,
      userChannelIdx: (unsigned __int8)sourceUserChannelIndex);
    idMD6Skel::GetUserChannelIndex(this: (idMD6Skel *)&v8, result: targetSkeleton, handle: &v7);
    if ( v8 < 0 )
      return (*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 4) + 7) & 0xF8;
    else
      return (unsigned __int8)v8;
  }
  return result;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::CompressR
// EA  : 0x828281D0
// RVA : 0x008281D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::CompressR(const float *inR, __int16 *outR)
{
  int v2; // r10
  int v3; // r8
  int v4; // r11
  int v5; // r11
  int v6; // r11
  int v7; // r11
  int v8; // r11
  __int16 v9; // r9

  v2 = __fabs(inR[1]) > __fabs(*inR);
  if ( __fabs(inR[2]) > __fabs(inR[v2]) )
    v2 = 2;
  if ( __fabs(inR[3]) > __fabs(inR[v2]) )
    v2 = 3;
  v3 = (4 * (v2 + 1)) & 0xC;
  if ( inR[v2] >= 0.0 )
  {
    v7 = (int)(float)((float)((float)(*(const float *)((char *)inR + v3) - (float)-0.70710677) * 23169.768) + (float)0.5);
    if ( v7 > 0 )
    {
      if ( v7 >= 0x7FFF )
        LOWORD(v7) = 0x7FFF;
    }
    else
    {
      LOWORD(v7) = 0;
    }
    *outR = v7;
    v8 = (int)(float)((float)((float)(*(const float *)((char *)inR + ((4 * (v2 - 2)) & 0xC)) - (float)-0.70710677)
                            * (float)23169.768)
                    + (float)0.5);
    if ( v8 > 0 )
    {
      if ( v8 >= 0x7FFF )
        LOWORD(v8) = 0x7FFF;
    }
    else
    {
      LOWORD(v8) = 0;
    }
    outR[1] = v8;
    v6 = (int)(float)((float)((float)(*(const float *)((char *)inR + ((4 * (v2 - 1)) & 0xC)) - (float)-0.70710677)
                            * (float)23169.768)
                    + (float)0.5);
  }
  else
  {
    v4 = (int)(float)((float)((float)((float)-*(const float *)((char *)inR + v3) - (float)-0.70710677) * 23169.768)
                    + (float)0.5);
    if ( v4 > 0 )
    {
      if ( v4 >= 0x7FFF )
        LOWORD(v4) = 0x7FFF;
    }
    else
    {
      LOWORD(v4) = 0;
    }
    *outR = v4;
    v5 = (int)(float)((float)((float)((float)-*(const float *)((char *)inR + ((4 * (v2 - 2)) & 0xC)) - (float)-0.70710677)
                            * (float)23169.768)
                    + (float)0.5);
    if ( v5 > 0 )
    {
      if ( v5 >= 0x7FFF )
        LOWORD(v5) = 0x7FFF;
    }
    else
    {
      LOWORD(v5) = 0;
    }
    outR[1] = v5;
    v6 = (int)(float)((float)((float)((float)-*(const float *)((char *)inR + ((4 * (v2 - 1)) & 0xC)) - (float)-0.70710677)
                            * (float)23169.768)
                    + (float)0.5);
  }
  if ( v6 > 0 )
  {
    if ( v6 >= 0x7FFF )
      LOWORD(v6) = 0x7FFF;
  }
  else
  {
    LOWORD(v6) = 0;
  }
  outR[2] = v6;
  v9 = outR[1];
  *outR |= (3 - (_WORD)v2) << 15;
  outR[1] = ((3 - (_WORD)v2) << 14) & 0x8000 | v9;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::QuantizeR
// EA  : 0x82828418
// RVA : 0x00828418
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::QuantizeR(const float *inR, float *outR)
{
  __int128 v3; // r6 OVERLAPPED
  int v4; // r7
  int v5; // r11
  double v6; // fp13
  double v7; // fp12
  double v8; // fp11
  unsigned __int16 v9; // [sp+50h] [-30h] BYREF
  __int16 v10; // [sp+52h] [-2Eh]
  __int16 v11; // [sp+54h] [-2Ch]
  float v12; // [sp+60h] [-20h] BYREF
  float v13; // [sp+64h] [-1Ch]
  float v14; // [sp+68h] [-18h]
  float v15; // [sp+6Ch] [-14h]

  _idMD6Anim::CompressAnim_::_2_::local_t::CompressR(inR, outR: (__int16 *)&v9);
  LODWORD(v3) = v10 & 0x7FFF;
  DWORD2(v3) = v9 & 0x7FFF;
  v4 = v11 & 0x7FFF;
  v5 = (unsigned __int16)((v9 >> 1) | v10 & 0x8000) >> 14;
  v12 = (float)((float)*(__int64 *)((char *)&v3 + 4) * (float)0.000043159689) - (float)0.70710677;
  v13 = (float)((float)(__int64)v3 * (float)0.000043159689) - (float)0.70710677;
  v14 = (float)((float)*(__int64 *)((char *)&v3 - 4) * (float)0.000043159689) - (float)0.70710677;
  v15 = __fsqrts((float)-(float)((float)(v14 * v14)
                               - (float)-(float)((float)(v13 * v13) - (float)-(float)((float)(v12 * v12) - (float)1.0))));
  v6 = *(float *)((char *)&v12 + ((4 * (v5 + 1)) & 0xC));
  v7 = *(float *)((char *)&v12 + ((4 * (v5 - 2)) & 0xC));
  v8 = *(float *)((char *)&v12 + ((4 * (v5 - 1)) & 0xC));
  *outR = *(float *)((char *)&v12 + ((4 * v5) & 0xC));
  outR[1] = v6;
  outR[2] = v7;
  outR[3] = v8;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::CalculateFrameSize
// EA  : 0x82828528
// RVA : 0x00828528
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

unsigned int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::CalculateFrameSize(
        int frameStart,
        int frameRange,
        int numJoints,
        int numPaddedUserChannels,
        int numAnimR,
        int numAnimS,
        int numAnimT,
        int numAnimU,
        const idList<char,5> *maskR,
        const idList<char,5> *maskS,
        const idList<char,5> *maskT,
        const idList<char,5> *maskU,
        int *sizeR,
        int *sizeS,
        int *sizeT,
        int *sizeU,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28,
        int a29,
        _DWORD *a30,
        int a31,
        _DWORD *a32,
        int a33,
        _DWORD *a34,
        int a35,
        const idList<char,5> *maskRa,
        int a37,
        const idList<char,5> *maskSa,
        int a39,
        const idList<char,5> *maskTa,
        int a41,
        const idList<char,5> *maskUa)
{
  unsigned int v42; // r28
  unsigned int v43; // r30
  int v44; // r11
  int v45; // r3
  int v46; // r21
  int v47; // r31
  int v48; // r19
  int v49; // r11
  int v50; // ctr
  int v51; // r3
  int v52; // r3
  int i; // ctr
  unsigned int v54; // r3

  v44 = frameStart + 1;
  maskRa->list = nullptr;
  v45 = frameStart + frameRange;
  maskSa->list = nullptr;
  maskTa->list = nullptr;
  maskUa->list = nullptr;
  if ( v44 < v45 )
  {
    v46 = v44 * numPaddedUserChannels;
    v47 = v44 * numJoints;
    v48 = v45 - v44;
    do
    {
      v49 = 0;
      if ( numJoints > 0 )
      {
        v50 = numJoints;
        v51 = v47;
        do
        {
          if ( *(_BYTE *)(v51 + *a28) != 0 )
            maskRa->list += 6;
          if ( *(_BYTE *)(*a30 + v47 + v49) != 0 )
            maskSa->list += 12;
          if ( *(_BYTE *)(*a32 + v47 + v49) != 0 )
            maskTa->list += 12;
          ++v49;
          v51 = v47 + v49;
          --v50;
        }
        while ( v50 != 0 );
      }
      v52 = 0;
      if ( numPaddedUserChannels > 0 )
      {
        for ( i = numPaddedUserChannels; i != 0; --i )
        {
          if ( *(_BYTE *)(*a34 + v46 + v52) != 0 )
            maskUa->list += 4;
          ++v52;
        }
      }
      --v48;
      v47 += numJoints;
      v46 += numPaddedUserChannels;
    }
    while ( v48 != 0 );
  }
  v54 = (frameRange + 7) & 0xFFFFFFF8;
  v43 = (12 * numAnimT + 15) & 0xFFFFFFF0;
  v42 = (4 * numAnimU + 15) & 0xFFFFFFF0;
  return ((((int)(v54 * numAnimR + 7) / 8 + 15) & 0xFFFFFFF0)
        + (((int)(v54 * numAnimS + 7) / 8 + 15) & 0xFFFFFFF0)
        + (((int)(v54 * numAnimT + 7) / 8 + 15) & 0xFFFFFFF0)
        + (((int)(v54 * numAnimU + 7) / 8 + 15) & 0xFFFFFFF0)
        + ((int)(maskRa->list + 15) & 0xFFFFFFF0)
        + ((int)(maskSa->list + 15) & 0xFFFFFFF0)
        + ((int)(maskTa->list + 15) & 0xFFFFFFF0)
        + ((int)(maskUa->list + 15) & 0xFFFFFFF0)
        + v42
        + v43
        + ((12 * numAnimS + 15) & 0xFFFFFFF0)
        + ((6 * numAnimR + 15) & 0xFFFFFFF0)
        + v42
        + v43
        + ((12 * numAnimS + 15) & 0xFFFFFFF0)
        + ((6 * numAnimR + 15) & 0xFFFFFFF0)
        + 48
        + 70)
       & 0xFFFFFFF0;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GetSetDistanceToRoot
// EA  : 0x82828770
// RVA : 0x00828770
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

float __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GetSetDistanceToRoot(
        const __int16 jointIndex,
        const __int16 *parentTable,
        const float *baseT,
        idList<float,5> *distanceToRootList)
{
  int v4; // r11
  float *list; // r31
  unsigned int v6; // r30
  double v7; // fp1
  __int16 v8; // r3

  v4 = jointIndex;
  list = distanceToRootList->list;
  v6 = jointIndex;
  v7 = distanceToRootList->list[v6];
  if ( v7 == -1.0 )
  {
    v8 = parentTable[jointIndex];
    if ( v8 >= 0 )
      list[v6] = _idMD6Anim::CompressAnim_::_2_::local_t::GetSetDistanceToRoot(
                   jointIndex: v8,
                   parentTable,
                   baseT,
                   distanceToRootList)
               + (float)__fsqrts((float)((float)(baseT[3 * v4] * baseT[3 * v4]) * (float)3.0));
    else
      list[v6] = 0.0;
    v7 = list[v6];
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// `idMD6Anim::RewriteText'::`166'::helper_t::LoadModel
// EA  : 0x82828828
// RVA : 0x00828828
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

idMD6Model *__fastcall _idMD6Anim::RewriteText_::_166_::helper_t::LoadModel(
        const idStr *meshPath,
        const int numJoints,
        const int numPaddedUserChannels,
        const idHandle<unsigned short,enum invalidCrc_t,65535> *parentTblCrc)
{
  idMD6Model *result; // r3
  const idMD6Skel *skeleton; // r11

  result = (idMD6Model *)idResourceList::Load(
                           this: &idMD6Model::resourceList,
                           name: meshPath->data,
                           makeDefault: false,
                           skipStaleCheck: false);
  if ( result == nullptr )
  {
    result = (idMD6Model *)idResourceList::Load(
                             this: &idMD6Model::resourceList,
                             name: meshPath->data,
                             makeDefault: false,
                             skipStaleCheck: false);
    if ( result == nullptr )
      return nullptr;
  }
  skeleton = result->skeleton;
  if ( skeleton == nullptr || skeleton->data->numJoints < numJoints )
    return nullptr;
  return result;
}


// ========================================================================
// $M231239
// EA  : 0x828288DC
// RVA : 0x008288DC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void *_M231239()
{
  return &_LN13;
}


// ========================================================================
// $M231242
// EA  : 0x828288F8
// RVA : 0x008288F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void *_M231242()
{
  return &_LN15_0;
}


// ========================================================================
// `idMD6Anim::RewriteText'::`166'::helper_t::ValidateParenting
// EA  : 0x82828910
// RVA : 0x00828910
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::RewriteText_::_166_::helper_t::ValidateParenting(
        const char *filename,
        const idMD6Model *model,
        int numJoints,
        const idList<idStr,5> *animJointTable,
        const idList<short,5> *animParentTable,
        const idHandle<unsigned short,enum invalidCrc_t,65535> *parentTblCrc)
{
  const idMD6Skel *skeleton; // r29
  idMD6SkelData *data; // r10
  int v14; // r23
  int v15; // r28
  int i; // r31
  char *v17; // r30
  int v18; // r24
  int v19; // r27
  int v20; // r28
  char *v21; // r30
  char *v22; // r31
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  const char *v24; // r5
  int value; // r31
  __int16 v26; // r9
  idMD6Skel v27[2]; // [sp+50h] [-70h] BYREF

  if ( model == nullptr )
    return 0;
  skeleton = model->skeleton;
  data = skeleton->data;
  if ( data->parentTblCrc.value == (unsigned __int16)parentTblCrc )
    return 1;
  v14 = (int)skeleton->data + data->parentTblOffset;
  if ( skeleton->jointConversion.value != 0xFFFF )
  {
    v15 = 0;
    if ( numJoints <= 0 )
      return 1;
    for ( i = 0; ; ++i )
    {
      v17 = animJointTable->list[i].data;
      if ( (unsigned __int16)idMD6Skel::GetJointIndex(
                               this: v27,
                               result: (idIndex<short,enum invalidJointIndex_t> *)skeleton,
                               name: v17)->value == 0xFFFF )
        break;
      if ( ++v15 >= numJoints )
        return 1;
    }
    idLib::Error(
      fmt: "Skeleton for model '%s' is missing joint '%s' used in animation '%s'",
      model->name.str,
      v17,
      filename);
  }
  v18 = 1;
  if ( numJoints <= 1 )
    return 1;
  v19 = 1;
  v20 = 1;
  do
  {
    v21 = animJointTable->list[v20].data;
    v22 = animJointTable->list[animParentTable->list[v19]].data;
    JointIndex = idMD6Skel::GetJointIndex(
                   this: v27,
                   result: (idIndex<short,enum invalidJointIndex_t> *)skeleton,
                   name: v21);
    v24 = v22;
    value = JointIndex->value;
    v26 = idMD6Skel::GetJointIndex(
            this: (idMD6Skel *)((char *)&v27[0].__vftable + 2),
            result: (idIndex<short,enum invalidJointIndex_t> *)skeleton,
            name: v24)->value;
    if ( value == -1 || v26 == -1 )
      goto _LN84_0;
    if ( v26 != *(__int16 *)(2 * value + v14) )
    {
      idLib::Error(
        fmt: "Skeleton does not match between mesh '%s' and animation '%s', different parenting",
        model->name.str,
        filename);
_LN84_0:
      idLib::Error(
        fmt: "Skeleton does not match between mesh '%s' and animation '%s', missing joint '%s",
        model->name.str,
        filename,
        v21);
      JUMPOUT(0x82828ABC);
    }
    ++v18;
    ++v20;
    ++v19;
  }
  while ( v18 < numJoints );
  return 1;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::IsRWithinTolerance
// EA  : 0x82828CB8
// RVA : 0x00828CB8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

BOOL __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::IsRWithinTolerance(
        const float *a,
        const float *b,
        double length,
        double tolerance)
{
  double v4; // fp12
  double v5; // fp10
  double v6; // fp9
  double v8; // fp8
  double v10; // fp6
  double v11; // fp4
  double v12; // fp0
  double v13; // fp13
  double v14; // fp11
  float y; // r10
  float v16; // r9
  double v17; // fp1
  double v19; // fp8
  double v21; // fp6
  double v22; // fp9
  double v23; // fp8
  double v24; // fp4
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  idVec3 v29; // [sp+50h] [-A0h] BYREF
  idQuat v30; // [sp+60h] [-90h] BYREF
  idRotation v31; // [sp+70h] [-80h] BYREF

  v4 = -*a;
  v5 = -a[1];
  v6 = -a[2];
  v8 = b[2];
  v10 = *b;
  v11 = b[1];
  v12 = (float)((float)(b[3] * (float)v4) + (float)((float)(*b * a[3]) + (float)(b[2] * (float)v5)));
  v13 = (float)((float)(*b * (float)v6) + (float)((float)(b[1] * a[3]) + (float)(b[3] * (float)v5)));
  v14 = (float)((float)(b[1] * (float)v4) + (float)((float)(b[2] * a[3]) + (float)(b[3] * (float)v6)));
  v31.vec.x = -(float)((float)(b[2] * (float)v6)
                     - (float)-(float)((float)(b[1] * (float)v5)
                                     - (float)((float)(b[3] * a[3]) - (float)(*b * (float)v4))));
  v31.origin.x = -(float)((float)((float)v11 * (float)v6) - (float)v12);
  v31.origin.y = -(float)((float)((float)v8 * (float)v4) - (float)v13);
  v31.origin.z = -(float)((float)((float)v10 * (float)v5) - (float)v14);
  idQuat::ToRotation(this: (idQuat *)&v31.vec.y, result: &v31);
  if ( __fabs(v31.axis.mat[0].x) <= 0.5 )
  {
    v29.x = 1.0;
    v29.y = 0.0;
  }
  else
  {
    v29.x = 0.0;
    v29.y = 1.0;
  }
  v29.z = 0.0;
  y = v29.y;
  v16 = 0.0;
  v17 = (float)((float)(v31.axis.mat[0].y * v29.x) - (float)(v31.axis.mat[0].x * v29.y));
  _FP9 = (float)((float)((float)((float)((float)(v31.axis.mat[0].z * y) - (float)(v31.axis.mat[0].y * v16))
                               * (float)((float)(v31.axis.mat[0].z * y) - (float)(v31.axis.mat[0].y * v16)))
                       + (float)((float)((float)((float)(v31.axis.mat[0].y * v29.x) - (float)(v31.axis.mat[0].x * v29.y))
                                       * (float)((float)(v31.axis.mat[0].y * v29.x) - (float)(v31.axis.mat[0].x * v29.y)))
                               + (float)((float)((float)(v31.axis.mat[0].x * v29.z) - (float)(v31.axis.mat[0].z * v29.x))
                                       * (float)((float)(v31.axis.mat[0].x * v29.z) - (float)(v31.axis.mat[0].z * v29.x)))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v19 = (float)((float)((float)((float)((float)(v31.axis.mat[0].z * y) - (float)(v31.axis.mat[0].y * v16))
                              * (float)((float)(v31.axis.mat[0].z * y) - (float)(v31.axis.mat[0].y * v16)))
                      + (float)((float)((float)((float)(v31.axis.mat[0].y * v29.x) - (float)(v31.axis.mat[0].x * v29.y))
                                      * (float)((float)(v31.axis.mat[0].y * v29.x) - (float)(v31.axis.mat[0].x * v29.y)))
                              + (float)((float)((float)(v31.axis.mat[0].x * v29.z) - (float)(v31.axis.mat[0].z * v29.x))
                                      * (float)((float)(v31.axis.mat[0].x * v29.z) - (float)(v31.axis.mat[0].z * v29.x)))))
              * (float)0.5);
  __asm { fsel      f7, f9, f10, f13 }
  v21 = __frsqrte(_FP7);
  v22 = (float)((float)-(float)((float)((float)((float)v19
                                              * (float)((float)-(float)((float)((float)((float)v19 * (float)v21)
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21))
                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)v21) * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19 * (float)v21) * (float)v21) - (float)1.5) * (float)v21));
  v23 = (float)((float)v19
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)v21)
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21))
                                              * (float)((float)-(float)((float)((float)((float)v19 * (float)v21)
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19 * (float)v21) * (float)v21) - (float)1.5)
                              * (float)v21)));
  v24 = (float)((float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22) * (float)length);
  v26 = (float)((float)((float)(v31.axis.mat[0].x * (float)0.0) - (float)(v31.axis.mat[0].z * v29.x))
              * (float)((float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22)
                      * (float)length));
  v25 = (float)((float)((float)(v31.axis.mat[0].z * v29.y) - (float)(v31.axis.mat[0].y * (float)0.0))
              * (float)((float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22)
                      * (float)length));
  v29.y = (float)((float)(v31.axis.mat[0].x * (float)0.0) - (float)(v31.axis.mat[0].z * v29.x)) * (float)v24;
  v29.x = v25;
  v27 = (float)((float)v17 * (float)v24);
  v29.z = (float)v17 * (float)v24;
  idQuat::operator*(this: &v30, result: &v31.origin, a: &v29);
  return (float)((float)((float)(v30.x - (float)v25) * (float)(v30.x - (float)v25))
               + (float)((float)((float)(v30.z - (float)v27) * (float)(v30.z - (float)v27))
                       + (float)((float)(v30.y - (float)v26) * (float)(v30.y - (float)v26)))) <= (double)(float)((float)tolerance * (float)tolerance);
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::Reduce
// EA  : 0x82828ED0
// RVA : 0x00828ED0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
        const idList<float,5> *distanceToRootList,
        const idList<short,5> *farthestEndEffectorList,
        const idList<float,5> *keyFrame,
        int leftFrame,
        int rightFrame,
        int jointIndex,
        int numJoints,
        double minimumDistanceToFarthestEndEffector,
        double tolerance,
        const idMD6Anim::CompressAnim::__l2::local_t::channel_t channelType,
        idList<char,5> *mask,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        unsigned int a32,
        int a33,
        _DWORD *a34)
{
  int v34; // r15
  int v35; // r27
  int v39; // r11
  unsigned int v40; // r7
  double v41; // fp30
  double v42; // fp29
  double v43; // fp31
  BOOL v44; // r10
  double v45; // fp0
  __int64 v46; // r9
  double v47; // fp13
  double v48; // fp0
  int v51; // r25
  int v52; // r10
  int v53; // r14
  int v54; // r21
  __int64 v55; // r10 OVERLAPPED
  int v56; // r30
  int v57; // r24
  int v58; // r23
  int v59; // r28
  int v60; // r18
  int v61; // r20
  int v62; // r17
  int v63; // r22
  float *list; // r11
  double v65; // fp13
  double v66; // fp11
  double v67; // fp10
  double v68; // fp9
  double v69; // fp13
  float *v70; // r31
  char v71; // r29
  int v72; // r26
  double v73; // fp24
  int v74; // r30
  int v75; // r27
  int v76; // r31
  int v77; // r11
  double v78; // fp7
  double v79; // fp5
  double v80; // fp4
  double v81; // fp3
  double v82; // fp2
  double v83; // fp1
  int v84; // r11
  int v85; // ctr
  float *v86; // r11
  float *v87; // r11
  double v88; // fp12
  double v89; // fp10
  float *v90; // r11
  double v91; // fp4
  double v92; // fp3
  double v93; // fp2
  const float *v94; // r3
  double v97; // fp5
  double v98; // fp9
  unsigned __int8 IsRWithinTolerance; // r3
  int v100; // r11
  int v101; // r11
  int v102; // ctr
  int v103; // r10
  idList<char,5> *v104; // [sp+8h] [-1D8h]
  int v105; // [sp+70h] [-170h]
  int v106; // [sp+74h] [-16Ch]
  int v107; // [sp+78h] [-168h]
  int v108; // [sp+7Ch] [-164h]
  int i; // [sp+80h] [-160h]
  int v110; // [sp+84h] [-15Ch]
  BOOL v111; // [sp+88h] [-158h]
  int v112; // [sp+8Ch] [-154h]
  int v113; // [sp+90h] [-150h]
  int v114; // [sp+98h] [-148h]
  int v115; // [sp+A0h] [-140h]
  float v116; // [sp+C0h] [-120h] BYREF
  float v117; // [sp+C4h] [-11Ch] BYREF
  float v118; // [sp+C8h] [-118h] BYREF
  float v119; // [sp+CCh] [-114h] BYREF
  float v120; // [sp+D0h] [-110h] BYREF
  float v121; // [sp+D4h] [-10Ch] BYREF
  float v122[2]; // [sp+D8h] [-108h] BYREF
  float v123; // [sp+E0h] [-100h] BYREF
  float v124; // [sp+E4h] [-FCh] BYREF
  float v125[24]; // [sp+E8h] [-F8h] BYREF
  const idList<float,5> *v126; // [sp+1F4h] [+14h]
  const idList<short,5> *v127; // [sp+1FCh] [+1Ch]
  int v128; // [sp+20Ch] [+2Ch]

  v34 = numJoints;
  v35 = jointIndex;
  v126 = distanceToRootList;
  v127 = farthestEndEffectorList;
  v128 = leftFrame;
  v115 = rightFrame * numJoints;
  *(_BYTE *)(leftFrame * numJoints + *a34 + jointIndex) = 1;
  *(_BYTE *)(rightFrame * numJoints + *a34 + jointIndex) = 1;
  v39 = rightFrame - leftFrame - 1;
  if ( v39 > 0 )
  {
    v40 = a32;
    v41 = v118;
    v42 = v117;
    v43 = v116;
    v113 = -4 * numJoints;
    v44 = (_cntlzw(a32 - 3) & 0x20) != 0;
    v111 = v44;
    while ( 2 )
    {
      if ( v44 )
      {
        v45 = 0.0;
      }
      else
      {
        HIDWORD(v46) = 2 * v35;
        LODWORD(v46) = farthestEndEffectorList->list[v35];
        v45 = (float)v46;
      }
      if ( v44 )
      {
        v47 = 0.0;
        v48 = 0.0;
      }
      else
      {
        v47 = distanceToRootList->list[v35];
        v48 = distanceToRootList->list[(__int16)(int)v45];
      }
      _FP13 = (float)((float)((float)v48 - (float)v47) - (float)minimumDistanceToFarthestEndEffector);
      __asm { fsel      f28, f13, f0, f21 }
      if ( v40 != 0 )
      {
        if ( v40 == 3 )
          v51 = 1;
        else
          v51 = 3;
      }
      else
      {
        v51 = 4;
      }
      v105 = v39;
      v52 = (v39 + leftFrame + 1) * v34 + v35;
      v106 = 1;
      v114 = -4 * v51 * v34;
      v108 = 4 * v52;
      for ( i = 4 * v52 * v51; ; i += v114 )
      {
        if ( v105 <= 0 )
        {
          v100 = leftFrame + 1;
          if ( leftFrame + 1 < rightFrame )
          {
            v102 = rightFrame - v100;
            v101 = v100 * v34;
            do
            {
              v103 = v101 + *a34;
              v101 += v34;
              *(_BYTE *)(v103 + v35) = 1;
              --v102;
            }
            while ( v102 != 0 );
          }
          return;
        }
        if ( v106 > 0 )
          break;
LABEL_51:
        --v105;
        ++v106;
        v108 += v113;
      }
      v53 = v108;
      v54 = i;
      v110 = v108;
      LODWORD(v55) = leftFrame * v34 + v35;
      HIDWORD(v55) = (leftFrame + 1) * v34 + v35;
      v56 = 4 * v55;
      v57 = 4 * v34;
      v107 = 4 * v55;
      v58 = 4 * v51 * v34;
      v112 = -1 - leftFrame;
      v59 = leftFrame + 1;
      v60 = 4 * HIDWORD(v55);
      v61 = 4 * v55 * v51;
      v62 = 4 * HIDWORD(v55) * v51;
      while ( 1 )
      {
        v63 = v59 + v105;
        if ( v40 != 0 )
        {
          list = keyFrame->list;
          if ( v40 == 3 )
          {
            v69 = *(float *)((char *)list + v53);
            v123 = *(float *)((char *)list + v56);
            v120 = v69;
          }
          else
          {
            v65 = *(float *)((char *)list + v54);
            HIDWORD(v55) = (char *)list + v54;
            v123 = *(float *)((char *)list + v61);
            v120 = v65;
            v66 = *(float *)((char *)list + v61 + 8);
            v67 = *(float *)((char *)list + v54 + 4);
            v68 = *(float *)((char *)list + v54 + 8);
            v124 = *(float *)((char *)list + v61 + 4);
            v125[0] = v66;
            v121 = v67;
            v122[0] = v68;
          }
        }
        else
        {
          v70 = keyFrame->list;
          _idMD6Anim::CompressAnim_::_2_::local_t::QuantizeR(
            inR: (const float *)((char *)keyFrame->list + v61),
            outR: &v123);
          _idMD6Anim::CompressAnim_::_2_::local_t::QuantizeR(inR: (float *)((char *)v70 + v54), outR: &v120);
        }
        v71 = 1;
        LODWORD(v55) = v105 + 1;
        v72 = v59;
        v73 = (float)((float)1.0 / (float)v55);
        if ( v59 < v63 )
        {
          v74 = 1;
          v75 = v60;
          v76 = v62;
          do
          {
            *(__int64 *)((char *)&v55 - 4) = (unsigned int)v74;
            if ( v51 >= 4 )
            {
              v77 = 0;
              do
              {
                v78 = (float)(v122[v77 - 1] * (float)((float)(unsigned int)v74 * (float)v73));
                v79 = (float)(v122[v77] * (float)((float)(unsigned int)v74 * (float)v73));
                v80 = (float)(v122[v77 + 1] * (float)((float)(unsigned int)v74 * (float)v73));
                v81 = v125[v77 - 1];
                v82 = v125[v77];
                v83 = v125[v77 + 1];
                LODWORD(v55) = v55 + 4;
                *(float *)((char *)&v116 + v77 * 4) = (float)(*(float *)((char *)&v123 + v77 * 4)
                                                            * (float)((float)1.0
                                                                    - (float)((float)(unsigned int)v74 * (float)v73)))
                                                    + (float)(*(float *)((char *)&v120 + v77 * 4)
                                                            * (float)((float)(unsigned int)v74 * (float)v73));
                *(float *)((char *)&v117 + v77 * 4) = (float)((float)v81
                                                            * (float)((float)1.0
                                                                    - (float)((float)(unsigned int)v74 * (float)v73)))
                                                    + (float)v78;
                *(float *)((char *)&v118 + v77 * 4) = (float)((float)v82
                                                            * (float)((float)1.0
                                                                    - (float)((float)(unsigned int)v74 * (float)v73)))
                                                    + (float)v79;
                *(float *)((char *)&v119 + v77 * 4) = (float)((float)v83
                                                            * (float)((float)1.0
                                                                    - (float)((float)(unsigned int)v74 * (float)v73)))
                                                    + (float)v80;
                v77 += 4;
              }
              while ( (int)v55 < v51 - 3 );
              v41 = v118;
              v53 = v110;
              v42 = v117;
              v34 = numJoints;
              v43 = v116;
            }
            if ( (int)v55 < v51 )
            {
              v84 = 4 * v55;
              v85 = v51 - v55;
              do
              {
                LODWORD(v55) = &v120;
                *(float *)((char *)&v116 + v84) = (float)(*(float *)((char *)&v123 + v84)
                                                        * (float)((float)1.0
                                                                - (float)((float)(unsigned int)v74 * (float)v73)))
                                                + (float)(*(float *)((char *)&v120 + v84)
                                                        * (float)((float)(unsigned int)v74 * (float)v73));
                v84 += 4;
                --v85;
              }
              while ( v85 != 0 );
              v41 = v118;
              v42 = v117;
              v43 = v116;
            }
            if ( a32 != 0 )
            {
              if ( a32 == 1 )
              {
                v90 = (float *)((char *)keyFrame->list + v76);
                v91 = (float)((float)((float)v42 * (float)_FP28) - (float)(v90[1] * (float)_FP28));
                v92 = (float)((float)((float)v41 * (float)_FP28) - (float)(v90[2] * (float)_FP28));
                v93 = (float)((float)((float)v43 * (float)_FP28) - (float)((float)_FP28 * *v90));
                if ( (float)((float)((float)v93 * (float)v93)
                           + (float)((float)((float)v92 * (float)v92) + (float)((float)v91 * (float)v91))) > (double)(float)((float)tolerance * (float)tolerance) )
                  v71 = 0;
              }
              else
              {
                v86 = keyFrame->list;
                if ( a32 < 3 )
                {
                  v87 = (float *)((char *)v86 + v76);
                  v88 = (float)((float)v42 - v87[1]);
                  v89 = (float)((float)v41 - v87[2]);
                  if ( (float)((float)((float)((float)v43 - *v87) * (float)((float)v43 - *v87))
                             + (float)((float)((float)v89 * (float)v89) + (float)((float)v88 * (float)v88))) > (double)(float)((float)tolerance * (float)tolerance) )
                    v71 = 0;
                }
                else if ( __fabs((float)(*(float *)((char *)v86 + v75) - (float)v43)) > tolerance )
                {
                  v71 = 0;
                }
              }
            }
            else
            {
              v94 = (float *)((char *)keyFrame->list + v76);
              _FP8 = (float)((float)((float)((float)v42 * (float)v42)
                                   + (float)((float)((float)v41 * (float)v41)
                                           + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119))))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f6, f8, f9, f13 }
              v97 = __frsqrte(_FP6);
              v98 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97
                                                                                                  * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5))
                                                                                          * (float)v97)
                                                                                  - (float)1.5)
                                                                  * (float)v97)
                                                          * (float)((float)((float)((float)v42 * (float)v42)
                                                                          + (float)((float)((float)v41 * (float)v41)
                                                                                  + (float)((float)((float)v43
                                                                                                  * (float)v43)
                                                                                          + (float)(v119 * v119))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v97
                                                                                          * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v97)
                                                                          - (float)1.5)
                                                          * (float)v97))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v97
                                                                  * (float)((float)((float)((float)v42 * (float)v42)
                                                                                  + (float)((float)((float)v41
                                                                                                  * (float)v41)
                                                                                          + (float)((float)((float)v43 * (float)v43)
                                                                                                  + (float)(v119 * v119))))
                                                                          * (float)0.5))
                                                          * (float)v97)
                                                  - (float)1.5)
                                  * (float)v97));
              v116 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97) * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97)
                                                                                           - (float)1.5)
                                                                           * (float)v97))
                                                           * (float)((float)((float)((float)v42 * (float)v42)
                                                                           + (float)((float)((float)v41 * (float)v41)
                                                                                   + (float)((float)((float)v43 * (float)v43)
                                                                                           + (float)(v119 * v119))))
                                                                   * (float)0.5))
                                                   * (float)v98)
                                           - (float)1.5)
                           * (float)v98)
                   * (float)v43;
              v117 = (float)v42
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97) * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97)
                                                                                           - (float)1.5)
                                                                           * (float)v97))
                                                           * (float)((float)((float)((float)v42 * (float)v42)
                                                                           + (float)((float)((float)v41 * (float)v41)
                                                                                   + (float)((float)((float)v43 * (float)v43)
                                                                                           + (float)(v119 * v119))))
                                                                   * (float)0.5))
                                                   * (float)v98)
                                           - (float)1.5)
                           * (float)v98);
              v118 = (float)v41
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97) * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97)
                                                                                           - (float)1.5)
                                                                           * (float)v97))
                                                           * (float)((float)((float)((float)v42 * (float)v42)
                                                                           + (float)((float)((float)v41 * (float)v41)
                                                                                   + (float)((float)((float)v43 * (float)v43)
                                                                                           + (float)(v119 * v119))))
                                                                   * (float)0.5))
                                                   * (float)v98)
                                           - (float)1.5)
                           * (float)v98);
              v119 = v119
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97) * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97) - (float)1.5) * (float)v97))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v97 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)((float)v43 * (float)v43) + (float)(v119 * v119)))) * (float)0.5)) * (float)v97)
                                                                                           - (float)1.5)
                                                                           * (float)v97))
                                                           * (float)((float)((float)((float)v42 * (float)v42)
                                                                           + (float)((float)((float)v41 * (float)v41)
                                                                                   + (float)((float)((float)v43 * (float)v43)
                                                                                           + (float)(v119 * v119))))
                                                                   * (float)0.5))
                                                   * (float)v98)
                                           - (float)1.5)
                           * (float)v98);
              IsRWithinTolerance = _idMD6Anim::CompressAnim_::_2_::local_t::IsRWithinTolerance(
                                     a: v94,
                                     b: &v116,
                                     length: _FP28,
                                     tolerance);
              v41 = v118;
              LODWORD(v55) = -IsRWithinTolerance;
              v42 = v117;
              v43 = v116;
              v71 = IsRWithinTolerance == 0 ? 0 : v71;
            }
            if ( v71 == 0 )
              break;
            ++v72;
            ++v74;
            v75 += v57;
            v76 += v58;
          }
          while ( v72 < v63 );
          v56 = v107;
          v35 = jointIndex;
        }
        if ( v71 != 0 )
          break;
        ++v59;
        v53 += v57;
        HIDWORD(v55) = v112 + v59;
        v40 = a32;
        v110 = v53;
        v54 += v58;
        v107 = v57 + v56;
        v61 += v58;
        v60 += v57;
        v62 += v58;
        if ( v112 + v59 >= v106 )
        {
          leftFrame = v128;
          goto LABEL_51;
        }
        v56 += v57;
      }
      _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
        distanceToRootList: v126,
        farthestEndEffectorList: v127,
        keyFrame,
        leftFrame: v128,
        rightFrame: v59 - 1,
        jointIndex: v35,
        numJoints: v34,
        minimumDistanceToFarthestEndEffector,
        tolerance,
        channelType: (const idMD6Anim::CompressAnim::__l2::local_t::channel_t)v55,
        mask: v104);
      v128 = v59 + v105;
      *(_BYTE *)(v63 * v34 + *a34 + v35) = 1;
      v39 = rightFrame - v63 - 1;
      *(_BYTE *)(v115 + *a34 + v35) = 1;
      if ( v39 > 0 )
      {
        distanceToRootList = v126;
        farthestEndEffectorList = v127;
        v40 = a32;
        v44 = v111;
        leftFrame = v59 + v105;
        continue;
      }
      break;
    }
  }
}


// ========================================================================
// ?LoadAnim_Settings@idMD6Anim@@SA_NPBDAAUanimationSettings_t@1@PAI_N@Z
// EA  : 0x82829618
// RVA : 0x00829618
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::LoadAnim_Settings(
        const char *animationFilename,
        idMD6Anim::animationSettings_t *_animSettings,
        unsigned int *timeStamp,
        bool loadFromAnim)
{
  int v8; // r29
  idFile_vtbl *v9; // r27
  unsigned int v10; // r3
  char *v11; // r27
  unsigned int (__fastcall *Read)(idFile *, void *, unsigned int); // ctr
  int v13; // r3
  int v15; // r29
  idFile_vtbl *v16; // r27
  unsigned int v17; // r3
  char *buffer; // r17
  char v19; // r30
  int v20; // r3
  char v21; // r24
  double v22; // fp31
  idFileLocal v23; // [sp+50h] [-480h] BYREF
  idFileLocal v24; // [sp+54h] [-47Ch] BYREF
  idTempArray<char> v25; // [sp+58h] [-478h] BYREF
  idStr v26; // [sp+60h] [-470h] BYREF
  const char *v27; // [sp+80h] [-450h]
  const char *v28; // [sp+84h] [-44Ch]
  const char *v29; // [sp+88h] [-448h]
  const char *v30; // [sp+8Ch] [-444h]
  const char *v31; // [sp+90h] [-440h]
  idToken v32; // [sp+A0h] [-430h] BYREF
  idToken v33; // [sp+F0h] [-3E0h] BYREF
  idStr v34; // [sp+140h] [-390h] BYREF
  int v35; // [sp+174h] [-35Ch]
  float v36; // [sp+178h] [-358h]
  int v37; // [sp+17Ch] [-354h]
  int v38; // [sp+180h] [-350h]
  int v39; // [sp+184h] [-34Ch]
  idParser v40; // [sp+190h] [-340h] BYREF

  idStr::idStr(this: &v26, text: animationFilename);
  idStr::SetFileExtension(this: &v26, extension: "md6settings");
  v23.file = fileSystem->OpenFileRead(this: fileSystem, a2: v26.data, a3: 1, a4: 0);
  if ( v23.file == nullptr )
  {
    if ( loadFromAnim )
    {
      v24.file = fileSystem->OpenFileRead(this: fileSystem, a2: animationFilename, a3: 1, a4: 0);
      if ( v24.file != nullptr )
      {
        idParser::idParser(this: &v40, flags: 262704);
        v15 = v24.file->Length(this: v24.file);
        idTempArray<char>::idTempArray<char>(this: &v25, num: v15 + 1);
        v16 = v24.file->__vftable;
        v17 = v24.file->Length(this: v24.file);
        buffer = v25.buffer;
        if ( v16->Read(this: v24.file, a2: v25.buffer, a3: v17) != v15 )
        {
          idLib::Warning(fmt: "Failed to read file");
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
          idParser::~idParser(this: &v40);
          idFileLocal::~idFileLocal(this: &v24);
          idFileLocal::~idFileLocal(this: &v23);
          goto LABEL_105;
        }
        v19 = 0;
        buffer[v15] = 0;
        if ( !idParser::LoadMemory(this: &v40, ptr: buffer, length: v15 + 1, name: animationFilename) )
        {
          idLib::Warning(fmt: "Error parsing settings file");
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
          idParser::~idParser(this: &v40);
          idFileLocal::~idFileLocal(this: &v24);
          idFileLocal::~idFileLocal(this: &v23);
          idStr::FreeData(this: &v26);
          return 0;
        }
        idParser::ExpectTokenString(this: &v40, string: MD6_VERSION_STRING);
        v20 = idParser::ParseInt(this: &v40);
        if ( v20 != 7 && v20 != 6 )
          idParser::Error(
            this: &v40,
            str: "MD6 anim '%s' has an invalid version %d. Should be version %d.",
            animationFilename,
            v20,
            7);
        _animSettings->startFrameOffset = 0;
        _animSettings->endFrameOffset = 0;
        _animSettings->retargetAdditive = false;
        _animSettings->frameZeroDelta = false;
        _animSettings->useForwardTranslation = true;
        _animSettings->useLeftTranslation = true;
        _animSettings->useUpTranslation = true;
        _animSettings->errorTolerance = 0.60000002;
        _animSettings->useRotation = true;
        v32.floatvalue = -3.4028235e38;
        v32.allocedAndFlag = 20;
        v32.data = v32.baseBuffer;
        v32.len = 0;
        v32.baseBuffer[0] = 0;
        v32.intvalue = 0;
        memset(&v32.whiteSpaceStart_p, 0, 12);
        v21 = 0;
        v22 = 0.0020000001;
        idParser::ExpectTokenString(this: &v40, string: "init");
        idParser::ExpectTokenType(this: &v40, type: 5, subtype: 46, token: &v32);
        while ( idParser::ReadToken(this: &v40, token: &v32) && (v32.type != 5 || v32.subtype != 47) )
        {
          if ( idStr::Icmp(s1: v32.data, s2: "maxErrorRotation") != 0 )
          {
            if ( idStr::Icmp(s1: v32.data, s2: "maxErrorScale") != 0
              && idStr::Icmp(s1: v32.data, s2: "maxErrorTranslation") != 0
              && idStr::Icmp(s1: v32.data, s2: "maxErrorUser") != 0 )
            {
              if ( idStr::Icmp(s1: v32.data, s2: "errorTolerance") == 0 )
              {
                _animSettings->errorTolerance = idParser::ParseFloat(this: &v40, errorFlag: nullptr);
                v21 = 1;
              }
            }
            else
            {
              idParser::ParseFloat(this: &v40, errorFlag: nullptr);
            }
          }
          else
          {
            v19 = 1;
            v22 = idParser::ParseFloat(this: &v40, errorFlag: nullptr);
          }
        }
        if ( v21 == 0 && v19 != 0 )
          _animSettings->errorTolerance = (float)v22 * (float)300.0;
        idParser::SkipUntilString(this: &v40, string: "flags");
        idParser::ExpectTokenType(this: &v40, type: 5, subtype: 46, token: &v32);
        while ( idParser::ReadToken(this: &v40, token: &v32) && (v32.type != 5 || v32.subtype != 47) )
        {
          if ( idStr::Icmp(s1: v32.data, s2: "additive") != 0
            && idStr::Icmp(s1: v32.data, s2: "useForwardTranslation") != 0
            && idStr::Icmp(s1: v32.data, s2: "useLeftTranslation") != 0
            && idStr::Icmp(s1: v32.data, s2: "useUpTranslation") != 0
            && idStr::Icmp(s1: v32.data, s2: "useYawRotation") != 0
            && idStr::Icmp(s1: v32.data, s2: "useRotation") != 0 )
          {
            if ( idStr::Icmp(s1: v32.data, s2: "retargetAdditive") != 0 )
            {
              if ( idStr::Icmp(s1: v32.data, s2: "facetracksComposite") != 0 )
              {
                if ( idStr::Icmp(s1: v32.data, s2: "frameZeroDelta") != 0 )
                  idParser::Warning(
                    this: &v40,
                    str: "Unrecognized flag '%s' in MD6 anim file '%s'.",
                    v32.data,
                    animationFilename);
                else
                  _animSettings->frameZeroDelta = true;
              }
              else
              {
                _animSettings->facetracksComposite = true;
              }
            }
            else
            {
              _animSettings->retargetAdditive = true;
            }
          }
        }
        idParser::FreeSource(this: &v40);
        idStr::FreeData(this: &v32);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        idParser::~idParser(this: &v40);
      }
      idFileLocal::~idFileLocal(this: &v24);
    }
    idFileLocal::~idFileLocal(this: &v23);
LABEL_105:
    idStr::FreeData(this: &v26);
    return 0;
  }
  if ( timeStamp != nullptr )
    *timeStamp = fileSystem->GetTimestamp(this: fileSystem, a2: v26.data, a3: false);
  idParser::idParser(this: &v40, flags: 262704);
  v8 = v23.file->Length(this: v23.file);
  idTempArray<char>::idTempArray<char>(this: &v25, num: v8 + 1);
  v9 = v23.file->__vftable;
  v10 = v23.file->Length(this: v23.file);
  Read = v9->Read;
  v11 = v25.buffer;
  if ( Read(this: v23.file, a2: v25.buffer, a3: v10) != v8 )
  {
    idLib::Warning(fmt: "Failed to read file");
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    idParser::~idParser(this: &v40);
    idFileLocal::~idFileLocal(this: &v23);
    goto LABEL_105;
  }
  v11[v8] = 0;
  if ( !idParser::LoadMemory(this: &v40, ptr: v11, length: v8 + 1, name: v26.data) )
  {
    idLib::Warning(fmt: "Error parsing settings file");
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    idParser::~idParser(this: &v40);
    idFileLocal::~idFileLocal(this: &v23);
    idStr::FreeData(this: &v26);
    return 0;
  }
  idParser::ExpectTokenString(this: &v40, string: MD6_VERSION_STRING);
  v13 = idParser::ParseInt(this: &v40);
  if ( v13 != 7 && v13 != 6 && v13 != 5 )
    idParser::Error(this: &v40, str: "MD6 anim '%s' has an invalid version %d. Should be version %d.", v26.data, v13, 7);
  v33.len = 0;
  v33.baseBuffer[0] = 0;
  v33.intvalue = 0;
  v33.allocedAndFlag = 20;
  v33.data = v33.baseBuffer;
  memset(&v33.whiteSpaceStart_p, 0, 12);
  v33.floatvalue = -3.4028235e38;
  v36 = -3.4028235e38;
  v34.allocedAndFlag = 20;
  v34.data = v34.baseBuffer;
  v34.len = 0;
  v34.baseBuffer[0] = 0;
  v35 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  idParser::ExpectTokenType(this: &v40, type: 5, subtype: 46, token: &v33);
  v29 = "file '%s' - maxErrorTranslation is nolonger loaded from md6settings file";
  v30 = "file '%s' - maxErrorScale is nolonger loaded from md6settings file";
  v27 = "Unrecognized token '%s' in MD6 settings file '%s'.";
  v31 = "useForwardTranslation";
  v28 = "removeOrigin";
  while ( idParser::ReadToken(this: &v40, token: &v33) && (v33.type != 5 || v33.subtype != 47) )
  {
    if ( idStr::Icmp(s1: v33.data, s2: "maxErrorRotation") != 0 )
    {
      if ( idStr::Icmp(s1: v33.data, s2: "maxErrorScale") != 0 )
      {
        if ( idStr::Icmp(s1: v33.data, s2: "maxErrorTranslation") != 0 )
        {
          if ( idStr::Icmp(s1: v33.data, s2: "maxErrorUser") != 0 )
          {
            if ( idStr::Icmp(s1: v33.data, s2: "errorTolerance") != 0 )
            {
              if ( idStr::Icmp(s1: v33.data, s2: "startFrameOffset") != 0 )
              {
                if ( idStr::Icmp(s1: v33.data, s2: "endFrameOffset") != 0 )
                {
                  if ( idStr::Icmp(s1: v33.data, s2: v28) != 0 )
                  {
                    if ( idStr::Icmp(s1: v33.data, s2: v31) != 0 )
                    {
                      if ( idStr::Icmp(s1: v33.data, s2: "useLeftTranslation") != 0 )
                      {
                        if ( idStr::Icmp(s1: v33.data, s2: "useUpTranslation") != 0 )
                        {
                          if ( idStr::Icmp(s1: v33.data, s2: "useRotation") != 0 )
                          {
                            if ( idStr::Icmp(s1: v33.data, s2: "retargetAdditive") != 0 )
                            {
                              if ( idStr::Icmp(s1: v33.data, s2: "facetracksComposite") != 0 )
                              {
                                if ( idStr::Icmp(s1: v33.data, s2: "frameZeroDelta") != 0 )
                                  idParser::Error(this: &v40, str: v27, v33.data, v26.data);
                                else
                                  _animSettings->frameZeroDelta = idParser::ParseBool(this: &v40);
                              }
                              else
                              {
                                _animSettings->facetracksComposite = idParser::ParseBool(this: &v40);
                              }
                            }
                            else
                            {
                              _animSettings->retargetAdditive = idParser::ParseBool(this: &v40);
                            }
                          }
                          else
                          {
                            _animSettings->useRotation = idParser::ParseBool(this: &v40);
                          }
                        }
                        else
                        {
                          _animSettings->useUpTranslation = idParser::ParseBool(this: &v40);
                        }
                      }
                      else
                      {
                        _animSettings->useLeftTranslation = idParser::ParseBool(this: &v40);
                      }
                    }
                    else
                    {
                      _animSettings->useForwardTranslation = idParser::ParseBool(this: &v40);
                    }
                  }
                  else
                  {
                    _animSettings->removeOrigin = idParser::ParseBool(this: &v40);
                  }
                }
                else
                {
                  _animSettings->endFrameOffset = idParser::ParseInt(this: &v40);
                }
              }
              else
              {
                _animSettings->startFrameOffset = idParser::ParseInt(this: &v40);
              }
            }
            else
            {
              _animSettings->errorTolerance = idParser::ParseFloat(this: &v40, errorFlag: nullptr);
            }
          }
          else
          {
            idLib::Warning(fmt: "file '%s' - maxErrorUser is nolonger loaded from md6settings file", v26.data);
            idParser::ParseFloat(this: &v40, errorFlag: nullptr);
          }
        }
        else
        {
          idLib::Warning(fmt: v29, v26.data);
          idParser::ParseFloat(this: &v40, errorFlag: nullptr);
        }
      }
      else
      {
        idLib::Warning(fmt: v30, v26.data);
        idParser::ParseFloat(this: &v40, errorFlag: nullptr);
      }
    }
    else
    {
      idLib::Warning(fmt: "file '%s' - maxErrorRotation is nolonger loaded from md6settings file", v26.data);
      idParser::ParseFloat(this: &v40, errorFlag: nullptr);
    }
  }
  idParser::FreeSource(this: &v40);
  idStr::FreeData(this: &v34);
  idStr::FreeData(this: &v33);
  if ( v25.buffer != nullptr )
    idMem::Free(this: &mem, ptr: v25.buffer, align: ALIGN_16);
  idParser::~idParser(this: &v40);
  idFileLocal::~idFileLocal(this: &v23);
  idStr::FreeData(this: &v26);
  return 1;
}


// ========================================================================
// $M234845_0
// EA  : 0x8282A304
// RVA : 0x0082A304
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _M234845_0()
{
  idLib::Error(fmt: "idMD6Anim::LoadAnim_Settings - %s", idException::error);
  JUMPOUT(0x8282A324);
}


// ========================================================================
// $M234848_0
// EA  : 0x8282A32C
// RVA : 0x0082A32C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int _M234848_0()
{
  idLib::Error(fmt: "idMD6Anim::LoadAnim_Settings - %s", idException::error);
  return _LN616();
}


// ========================================================================
// $LN616
// EA  : 0x8282A34C
// RVA : 0x0082A34C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN616()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 96));
}


// ========================================================================
// __unwind$234042
// EA  : 0x8282A374
// RVA : 0x0082A374
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234042()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 1232 + 80));
}


// ========================================================================
// __unwind$234043
// EA  : 0x8282A39C
// RVA : 0x0082A39C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234043()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1232 + 400));
}


// ========================================================================
// __unwind$234044
// EA  : 0x8282A3C4
// RVA : 0x0082A3C4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234044()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1232 + 88));
}


// ========================================================================
// __unwind$234045
// EA  : 0x8282A3EC
// RVA : 0x0082A3EC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234045()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 240));
}


// ========================================================================
// __unwind$234046
// EA  : 0x8282A414
// RVA : 0x0082A414
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234046()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 320));
}


// ========================================================================
// __unwind$234047
// EA  : 0x8282A43C
// RVA : 0x0082A43C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234047()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 1232 + 84));
}


// ========================================================================
// __unwind$234048
// EA  : 0x8282A464
// RVA : 0x0082A464
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234048()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1232 + 400));
}


// ========================================================================
// __unwind$234049
// EA  : 0x8282A48C
// RVA : 0x0082A48C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234049()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1232 + 88));
}


// ========================================================================
// __unwind$234050
// EA  : 0x8282A4B4
// RVA : 0x0082A4B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_234050()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 160));
}


// ========================================================================
// `idMD6Anim::RewriteText'::`166'::helper_t::GetMeshPath
// EA  : 0x8282A4E0
// RVA : 0x0082A4E0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall _idMD6Anim::RewriteText_::_166_::helper_t::GetMeshPath(const idStr *commandLine, idStr *meshPath)
{
  int v4; // r3
  int v5; // r30
  char v6; // r29
  int i; // r11
  unsigned int allocedAndFlag; // r10
  int v9; // r11
  int v10; // r10
  bool v11; // zf
  char *data; // r9
  int v13; // r11

  v4 = idStr::Find(
         searchIn: commandLine->data,
         searchFor: "-mesh ",
         casesensitive: false,
         start: 0,
         end: commandLine->len);
  if ( v4 != -1 )
  {
    v5 = v4 + 6;
    v6 = commandLine->data[v4 + 6];
    for ( i = v6; v6 != 0; i = v6 )
    {
      if ( i == 32 )
        break;
      allocedAndFlag = meshPath->allocedAndFlag;
      v9 = meshPath->len + 2;
      v11 = allocedAndFlag >> 31 == 0;
      v10 = allocedAndFlag & 0x7FFFFFFF;
      if ( v11 )
      {
        if ( v9 > v10 )
          idStr::ReAllocate(this: meshPath, amount: (v9 >> 1) + v9, keepold: true);
      }
      else if ( v9 > v10
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      ++v5;
      meshPath->data[meshPath->len] = v6;
      data = meshPath->data;
      v13 = meshPath->len + 1;
      meshPath->len = v13;
      data[v13] = 0;
      v6 = commandLine->data[v5];
    }
  }
}


// ========================================================================
// ?GetAnimationDelta@idMD6Anim@@QBAXPAVidVec3@@PAVidMat3@@@Z
// EA  : 0x8282A5F8
// RVA : 0x0082A5F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall idMD6Anim::GetAnimationDelta(idMD6Anim *this, idVec3 *deltaTrans, idMat3 *deltaAxis)
{
  idMD6AnimData *animData; // r11
  idQuat *startDelta; // r29
  float *endDelta; // r30
  idQuat *v8; // r3
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double x; // fp10
  double y; // fp9
  double z; // fp4
  double v15; // fp5
  double v16; // fp2
  double v17; // fp3
  double v18; // fp8
  double v19; // fp6
  idVec3 *v20; // r3
  idQuat *v21; // r3
  idVec3 v22; // [sp+50h] [-90h] BYREF
  idQuat v23; // [sp+60h] [-80h] BYREF
  idMat3 v24[3]; // [sp+70h] [-70h] BYREF

  animData = this->animData;
  startDelta = nullptr;
  if ( animData != nullptr )
  {
    startDelta = (idQuat *)animData->startDelta;
    endDelta = animData->endDelta;
  }
  else
  {
    endDelta = nullptr;
  }
  if ( deltaAxis != nullptr )
  {
    v8 = idQuat::Inverse(this: &v23, result: startDelta);
    v9 = *endDelta;
    v10 = endDelta[1];
    v11 = endDelta[2];
    x = v8->x;
    y = v8->y;
    z = v8->z;
    v15 = (float)((float)(endDelta[2] * v8->w) + (float)((float)(endDelta[3] * v8->z) + (float)(endDelta[1] * v8->x)));
    v16 = (float)((float)(*endDelta * v8->w) + (float)((float)(endDelta[2] * v8->y) + (float)(endDelta[3] * v8->x)));
    v17 = (float)((float)(endDelta[1] * v8->w) + (float)((float)(*endDelta * v8->z) + (float)(endDelta[3] * v8->y)));
    v24[0].mat[1].x = -(float)((float)(endDelta[2] * v8->z)
                             - (float)-(float)((float)(endDelta[1] * v8->y)
                                             - (float)((float)(endDelta[3] * v8->w) - (float)(*endDelta * v8->x))));
    v24[0].mat[0].z = -(float)((float)((float)v9 * (float)y) - (float)v15);
    v24[0].mat[0].x = -(float)((float)((float)v10 * (float)z) - (float)v16);
    v24[0].mat[0].y = -(float)((float)((float)v11 * (float)x) - (float)v17);
    *deltaAxis = *idQuat::ToMat3(this: (idQuat *)&v24[0].mat[2].z, result: v24);
  }
  if ( deltaTrans != nullptr )
  {
    v18 = (float)(endDelta[9] - startDelta[2].y);
    v19 = (float)(endDelta[10] - startDelta[2].z);
    v22.x = endDelta[8] - startDelta[2].x;
    v22.y = v18;
    v22.z = v19;
    v20 = (idVec3 *)idQuat::Inverse(this: (idQuat *)&v24[0].mat[1].y, result: startDelta);
    v21 = idQuat::operator*(this: &v23, result: v20, a: &v22);
    deltaTrans->x = v21->x;
    deltaTrans->y = v21->y;
    deltaTrans->z = v21->z;
  }
}


// ========================================================================
// ?CheckCompressionError@@YA_NPBDM@Z
// EA  : 0x8282A788
// RVA : 0x0082A788
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall CheckCompressionError(const char *fileName, double errorTolerance)
{
  char v4; // r30
  char v5; // r29
  double v6; // fp31
  double v7; // fp30
  idLexer v9; // [sp+50h] [-2950h] BYREF
  idToken v10; // [sp+E0h] [-28C0h] BYREF
  char v11; // [sp+128h] [-2878h] BYREF
  idStr v12; // [sp+930h] [-2070h] BYREF
  char v13; // [sp+950h] [-2050h] BYREF

  idLexer::idLexer(this: &v9, flags_: 0);
  if ( idLexer::LoadFilePartial(this: &v9, filename_: fileName, OSPath: false, maxLoadBytes: 2048) )
  {
    v4 = 0;
    v10.baseBuffer[0] = 0;
    v10.intvalue = 0;
    v10.floatvalue = -3.4028235e38;
    memset(&v10.whiteSpaceStart_p, 0, 12);
    v11 = 0;
    v10.data = &v11;
    v10.len = 0;
    v10.allocedAndFlag = -2147481600;
    v12.baseBuffer[0] = 0;
    v13 = 0;
    v12.data = &v13;
    v12.len = 0;
    v12.allocedAndFlag = -2147475456;
    idLexer::ExpectTokenString(this: &v9, string: MD6_VERSION_STRING);
    idLexer::ParseInt(this: &v9);
    idLexer::ExpectTokenString(this: &v9, string: "init");
    idLexer::ExpectTokenType(this: &v9, type: 5, subtype: 46, token: &v10);
    v5 = 0;
    v6 = 0.0;
    v7 = 0.0;
    while ( idLexer::ReadToken(this: &v9, token: &v10) && (v10.type != 5 || v10.subtype != 47) )
    {
      if ( idStr::Icmp(s1: v10.data, s2: "maxErrorRotation") != 0 )
      {
        if ( idStr::Icmp(s1: v10.data, s2: "errorTolerance") != 0 )
        {
          idLexer::ParseRestOfLine(this: &v9, out: &v12);
        }
        else
        {
          v6 = idLexer::ParseFloat(this: &v9, errorFlag: nullptr);
          v4 = 1;
        }
      }
      else
      {
        v7 = idLexer::ParseFloat(this: &v9, errorFlag: nullptr);
        v5 = 1;
      }
    }
    if ( v5 != 0 && v4 == 0 )
      v6 = (float)((float)v7 * (float)300.0);
    if ( v6 < errorTolerance )
    {
      idLib::Printf(fmt: "'%s' exceeds threshold:\n", fileName);
      idLib::Printf(fmt: "  errorTolerance: %g\n", errorTolerance);
      idStr::FreeData(this: &v12);
      idStr::FreeData(this: &v10);
      idLexer::~idLexer(this: &v9);
      return 1;
    }
    idStr::FreeData(this: &v12);
    idStr::FreeData(this: &v10);
  }
  else
  {
    idLib::Warning(fmt: "Failed to load file '%s'", fileName);
  }
  idLexer::~idLexer(this: &v9);
  return 0;
}


// ========================================================================
// $M235439
// EA  : 0x8282AA3C
// RVA : 0x0082AA3C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void *_M235439()
{
  idLib::Warning(fmt: "Error parsing .md6anim file");
  return &_LN21_1;
}


// ========================================================================
// __unwind$235193
// EA  : 0x8282AA6C
// RVA : 0x0082AA6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_235193()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 10656 + 80));
}


// ========================================================================
// __unwind$235194
// EA  : 0x8282AA94
// RVA : 0x0082AA94
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_235194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10656 + 224));
}


// ========================================================================
// __unwind$235195
// EA  : 0x8282AABC
// RVA : 0x0082AABC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_235195()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10656 + 2352));
}


// ========================================================================
// ?anim_checkCompressionError_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8282AAF0
// RVA : 0x0082AAF0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall anim_checkCompressionError_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r30
  double v4; // fp31
  long double v5; // fp2
  const char *v6; // r4
  idFileList *v7; // r3
  idFileList *v8; // r29
  int num; // r5
  int v10; // r26
  int v11; // r28
  idStr v12; // [sp+60h] [-60h] BYREF

  argc = args->argc;
  if ( args->argc == 3 || argc == 2 )
  {
    v3 = 0;
    v12.len = 0;
    v12.allocedAndFlag = 20;
    v4 = 0.60000002;
    v12.data = v12.baseBuffer;
    v12.baseBuffer[0] = 0;
    if ( argc == 3 )
    {
      idStr::operator=(this: &v12, text: args->argv[2]);
      if ( args->argc <= 1 )
        v5 = atof(nptr: &byte_8200D768);
      else
        v5 = atof(nptr: args->argv[1]);
      v4 = (float)*(double *)&v5;
    }
    else
    {
      if ( argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      idStr::operator=(this: &v12, text: v6);
    }
    if ( Sys_IsFolder(path: v12.data) == FOLDER_NO )
      CheckCompressionError(fileName: v12.data, errorTolerance: v4);
    v7 = fileSystem->ListFilesTree(this: fileSystem, a2: v12.data, a3: "md6anim", a4: 0);
    v8 = v7;
    if ( v7 != nullptr && v7->list.num != 0 )
    {
      common->SetRefreshOnPrint(this: common, a2: true);
      v10 = 0;
      v11 = 0;
      num = v8->list.num;
      if ( num > 0 )
      {
        do
        {
          if ( (unsigned __int8)CheckCompressionError(fileName: v8->list.list[v3].data, errorTolerance: v4) != 0 )
            ++v10;
          ++v11;
          ++v3;
          num = v8->list.num;
        }
        while ( v11 < num );
      }
      idLib::Printf(fmt: "%d of %d animations exceed compression error.\n", v10, num);
      idLib::Printf(fmt: "Done.\n");
      common->SetRefreshOnPrint(this: common, a2: false);
    }
    else
    {
      idLib::Printf(fmt: "No files found.\n");
    }
    idStr::FreeData(this: &v12);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: anim_checkCompressionError <errorTolerance> <path>\n");
    idLib::Printf(fmt: "USAGE: anim_checkCompressionError <path>\n");
  }
}


// ========================================================================
// __unwind$235461
// EA  : 0x8282AD08
// RVA : 0x0082AD08
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_235461()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?VerifyBoundingBoxes@idMD6Anim@@QBA_NPBVidDeclMD6@@MM@Z
// EA  : 0x8282AD88
// RVA : 0x0082AD88
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::VerifyBoundingBoxes(
        idMD6Anim *this,
        const idDeclMD6 *decl,
        double epsilon,
        double jointradius)
{
  idMD6AnimData *animData; // r11
  unsigned __int16 flags; // r10
  int numFrames; // r21
  const idMD6Skel *skeleton; // r23
  signed int frameRate; // r29
  idBounds *v13; // r3
  int v14; // r26
  float v15; // r3
  int v16; // r12
  const idMD6SkelData *data; // r3
  int v18; // r22
  int v19; // r12
  double v20; // fp23
  double v21; // fp22
  double v22; // fp21
  double v23; // fp20
  double v24; // fp19
  double v25; // fp18
  unsigned int v26; // r27
  idMD6AnimData *v33; // r6
  int v34; // r11
  float *v35; // r10
  const idMD6Model *model; // r11
  __int16 *p_granularity; // r10
  unsigned int *p_skelTimestamp; // r11
  int i; // ctr
  char v58; // r11
  char v59; // r11
  _DWORD back_chain[2]; // [sp+0h] [-1A0h]
  bool v62; // [sp+Bh] [-195h]
  float *v63; // [sp+Ch] [-194h]
  float *v64; // [sp+10h] [-190h]
  int v65; // [sp+14h] [-18Ch]
  int v66; // [sp+18h] [-188h]
  int v67; // [sp+1Ch] [-184h]
  int v68; // [sp+20h] [-180h]
  int v69; // [sp+24h] [-17Ch]
  int v70; // [sp+28h] [-178h]
  int v71; // [sp+2Ch] [-174h]
  int v72; // [sp+30h] [-170h]
  int v73; // [sp+34h] [-16Ch]
  int v74; // [sp+38h] [-168h]
  int v75; // [sp+3Ch] [-164h]
  int v76; // [sp+40h] [-160h]
  int v77; // [sp+44h] [-15Ch]
  int v78; // [sp+48h] [-158h]
  int v79; // [sp+4Ch] [-154h]
  int v80; // [sp+50h] [-150h]
  int v81; // [sp+58h] [-148h]
  int v82; // [sp+60h] [-140h]
  float v83[2]; // [sp+70h] [-130h] BYREF
  idVec3 v84[2]; // [sp+78h] [-128h] BYREF
  idList<idVehicleState *,5> v85; // [sp+90h] [-110h] BYREF
  idBoundsShort v86; // [sp+A0h] [-100h] BYREF
  float v87; // [sp+ACh] [-F4h]
  float v88; // [sp+B0h] [-F0h]
  float v89; // [sp+B4h] [-ECh]

  animData = this->animData;
  flags = animData->flags;
  LODWORD(v83[0]) = animData;
  if ( (flags & 0x20) != 0 )
    return 1;
  numFrames = 0;
  skeleton = decl->model->skeleton;
  v84[0] = vec3_origin;
  if ( animData != nullptr )
  {
    numFrames = animData->numFrames;
    frameRate = animData->frameRate;
  }
  else
  {
    frameRate = 30;
  }
  memset(&v85, 0, 14);
  *(_WORD *)&v85.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v85);
  v13 = idBoundsShort::ToBounds(this: &v86, result: (idBounds *)&this->translatedBounds);
  v14 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  ((void (__fastcall *)(idBounds *))RtlCheckStack12)(a1: v13);
  v15 = *(float *)&skeleton->data;
  *(_DWORD *)((char *)back_chain + v16) = back_chain[0];
  v83[0] = v15;
  data = (const idMD6SkelData *)((int (*)(void))RtlCheckStack12)();
  v18 = 0;
  *(_DWORD *)((char *)back_chain + v19) = back_chain[0];
  if ( numFrames <= 0 )
  {
LABEL_33:
    if ( (v85.listStatic == 0 || v85.listStatic == 2) && v85.list != nullptr )
      idMem::Free(this: &mem, ptr: v85.list, align: ALIGN_16);
    return 1;
  }
  v20 = v89;
  v21 = v88;
  v22 = v87;
  __twllei(frameRate, 0);
  v23 = *(float *)&v86.b[1][1];
  v24 = *(float *)&v86.b[0][2];
  v25 = *(float *)&v86.b[0][0];
  v26 = 0;
  _FP27 = v89;
  __twlgei(frameRate & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
  _FP28 = v88;
  _FP25 = v87;
  _FP29 = *(float *)&v86.b[1][1];
  _FP30 = *(float *)&v86.b[0][2];
  _FP26 = *(float *)&v86.b[0][0];
  while ( 1 )
  {
    v33 = this->animData;
    LODWORD(v83[0]) = data;
    idMD6Blend::DecodeSingleFrame(
      skeleton: data,
      temp: v83,
      tempSize: 0x4000u,
      animData: v33,
      ticksPerSec: __SPAIR64__(v26, v14),
      clearOriginTransform: false,
      originOffset: &v84[0].x,
      offsetAdd: v62,
      outPose: v63,
      outUserChannels: v64,
      a11: v65,
      a12: v66,
      a13: v67,
      a14: v68,
      a15: v69,
      a16: v70,
      a17: v71,
      a18: v72,
      a19: v73,
      a20: v74,
      a21: v75,
      a22: v76,
      a23: v77,
      a24: v78,
      a25: v79,
      a26: v80,
      a27: 1u,
      a28: v81,
      a29: (int)v83,
      a30: v82,
      a31: nullptr);
    data = skeleton->data;
    v34 = 0;
    HIWORD(v83[0]) = data->numJoints;
    if ( HIWORD(v83[0]) != 0 )
    {
      do
      {
        v35 = &v83[12 * v34];
        if ( v34 != 0 )
        {
          _FP5 = (float)((float)_FP26 - (float)(v35[3] - (float)jointradius));
          _FP4 = (float)((float)_FP29 - (float)(v35[11] - (float)jointradius));
          _FP3 = (float)((float)_FP30 - (float)(v35[7] - (float)jointradius));
          _FP2 = (float)((float)(v35[7] - (float)jointradius) - (float)_FP28);
          _FP0 = (float)((float)(v35[3] - (float)jointradius) - (float)_FP25);
          _FP1 = (float)((float)(v35[11] - (float)jointradius) - (float)_FP27);
          __asm
          {
            fsel      f13, f5, f11, f26
            fsel      f12, f4, f10, f29
            fsel      f5, f3, f9, f30
            fsel      f4, f2, f9, f28
            fsel      f2, f0, f11, f25
            fsel      f3, f1, f10, f27
          }
          _FP1 = (float)((float)_FP13 - (float)(v35[3] + (float)jointradius));
          _FP0 = (float)((float)_FP12 - (float)(v35[11] + (float)jointradius));
          _FP11 = (float)((float)_FP5 - (float)(v35[7] + (float)jointradius));
          _FP10 = (float)((float)(v35[7] + (float)jointradius) - (float)_FP4);
          _FP25 = (float)((float)(v35[3] + (float)jointradius) - (float)_FP2);
          _FP9 = (float)((float)(v35[11] + (float)jointradius) - (float)_FP3);
          __asm
          {
            fsel      f26, f1, f8, f13
            fsel      f29, f0, f7, f12
            fsel      f30, f11, f6, f5
            fsel      f28, f10, f6, f4
            fsel      f25, f25, f8, f2
            fsel      f27, f9, f7, f3
          }
        }
        else
        {
          _FP26 = v35[3];
          _FP30 = v35[7];
          _FP29 = v35[11];
          _FP25 = _FP26;
          _FP28 = _FP30;
          _FP27 = _FP29;
        }
        ++v34;
      }
      while ( v34 < HIWORD(v83[0]) );
    }
    if ( HIWORD(v83[0]) == 1 )
    {
      model = decl->model;
      if ( model != nullptr )
      {
        p_granularity = &v85.granularity;
        p_skelTimestamp = &model->skelTimestamp;
        for ( i = 6; i != 0; --i )
        {
          ++p_skelTimestamp;
          p_granularity += 2;
          *(_DWORD *)p_granularity = *p_skelTimestamp;
        }
        if ( *(float *)&v86.b[0][0] < (double)(float)((float)v25 - (float)epsilon)
          || *(float *)&v86.b[0][2] < (double)(float)((float)v24 - (float)epsilon)
          || *(float *)&v86.b[1][1] < (double)(float)((float)v23 - (float)epsilon)
          || v87 > (double)(float)((float)v22 + (float)epsilon)
          || v88 > (double)(float)((float)v21 + (float)epsilon)
          || (v58 = 1, v89 > (double)(float)((float)v20 + (float)epsilon)) )
        {
          v58 = 0;
        }
        if ( v58 == 0 )
        {
          idLib::Warning(fmt: "Animation %s has joints outside bounds", this->name.str);
          if ( (v85.listStatic == 0 || v85.listStatic == 2) && v85.list != nullptr )
            idMem::Free(this: &mem, ptr: v85.list, align: ALIGN_16);
          return 0;
        }
      }
    }
    if ( _FP26 < (float)((float)v25 - (float)epsilon)
      || _FP30 < (float)((float)v24 - (float)epsilon)
      || _FP29 < (float)((float)v23 - (float)epsilon)
      || _FP25 > (float)((float)v22 + (float)epsilon)
      || _FP28 > (float)((float)v21 + (float)epsilon)
      || (v59 = 1, _FP27 > (float)((float)v20 + (float)epsilon)) )
    {
      v59 = 0;
    }
    if ( v59 == 0 )
      break;
    ++v18;
    v26 += v14 / frameRate;
    if ( v18 >= numFrames )
      goto LABEL_33;
  }
  idLib::Warning(fmt: "Animation %s has joints outside bounds", this->name.str);
  if ( v85.listStatic != 0 && v85.listStatic != 2 || v85.list == nullptr )
    return 0;
  idMem::Free(this: &mem, ptr: v85.list, align: ALIGN_16);
  return 0;
}


// ========================================================================
// __unwind$236075
// EA  : 0x8282B21C
// RVA : 0x0082B21C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_236075()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 144));
}


// ========================================================================
// ?LoadBinary@idMD6Anim@@AAA_NPBD@Z
// EA  : 0x8282B250
// RVA : 0x0082B250
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::LoadBinary(idMD6Anim *this, const char *filename)
{
  idFile *v4; // r3
  idFile *file; // r3
  unsigned __int16 v7; // r7
  idMD6AnimData *v8; // r3
  int v9; // [sp+50h] [-70h] BYREF
  idFileLocal v10; // [sp+54h] [-6Ch] BYREF
  unsigned int v11; // [sp+58h] [-68h] BYREF
  int v12; // [sp+5Ch] [-64h] BYREF
  idStr v13[3]; // [sp+60h] [-60h] BYREF

  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0);
  v10.file = v4;
  if ( v4 != nullptr && (v4->Read(this: v4, a2: &v12, a3: 4u), v12 == 641089869) )
  {
    v10.file->Read(this: v10.file, a2: &this->timestamp, a3: 4u);
    v10.file->Read(this: v10.file, a2: &this->phaseTrackTimestamp, a3: 4u);
    v10.file->Read(this: v10.file, a2: &this->settingsTimestamp, a3: 4u);
    v10.file->Read(this: v10.file, a2: &this->timeCode, a3: 4u);
    v10.file->Read(this: v10.file, a2: &this->translatedBounds, a3: 12u);
    v10.file->Read(this: v10.file, a2: &this->normalizedBounds, a3: 12u);
    v13[0].len = 0;
    v13[0].allocedAndFlag = 20;
    v13[0].data = v13[0].baseBuffer;
    v13[0].baseBuffer[0] = 0;
    idFile::ReadString(this: v10.file, string: v13);
    v7 = *(_WORD *)((int (__fastcall *)(int *))animation->FindJointConversionHandle)(a1: &v9);
    file = v10.file;
    this->jointConversionHandle.value = v7;
    file->Read(this: file, a2: &this->jointConversionChecksum, a3: 2u);
    v10.file->Read(this: v10.file, a2: &this->origWorldPos, a3: 12u);
    v10.file->Read(this: v10.file, a2: &this->origWorldRot, a3: 12u);
    v10.file->Read(this: v10.file, a2: &this->origWorldScale, a3: 12u);
    v10.file->Read(this: v10.file, a2: &this->startFrameOffset, a3: 2u);
    v10.file->Read(this: v10.file, a2: &this->endFrameOffset, a3: 2u);
    v11 = 0;
    v10.file->Read(this: v10.file, a2: &v11, a3: 4u);
    v8 = (idMD6AnimData *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Anim.cpp(613) : TAG_MD6_ANIMS",
                            size: v11 + 7,
                            tag: TAG_MD6_ANIMS,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    this->animData = v8;
    v10.file->Read(this: v10.file, a2: v8, a3: v11);
    idMD6PhaseTrack::LoadBinary(this: &this->phaseTrack, file: v10.file);
    idStr::FreeData(this: v13);
    idFileLocal::~idFileLocal(this: &v10);
    if ( idStr::Find(searchIn: filename, searchFor: "wrench/gestures", casesensitive: true, start: 0, end: -1) != -1
      || idStr::Find(searchIn: filename, searchFor: "/facial/", casesensitive: true, start: 0, end: -1) != -1 )
    {
      this->animData->flags &= 0xFFE1u;
    }
    if ( (this->animData->flags & 0x40) == 0 )
      return 1;
    idLib::Warning(fmt: "Anim file '%s' is defaulted", filename);
    if ( anim_allowDefaultedBinaryAnims.valueInteger != 0
      || resourceManager->GetBuildPlatforms(this: resourceManager) != 0
      || idLib::production == PROD_PRODUCTION )
    {
      return 1;
    }
    else
    {
      if ( anim_removeDefaultedAnimFiles.valueInteger != 0 )
      {
        fileSystem->RemoveFile(this: fileSystem, a2: filename, a3: FSPATH_BASE);
        idLib::Printf(fmt: "Removed binary anim file '%s'\n", filename);
      }
      idMem::Free(this: &mem, ptr: this->animData, align: ALIGN_16);
      this->animData = nullptr;
      return 0;
    }
  }
  else
  {
    idFileLocal::~idFileLocal(this: &v10);
    return 0;
  }
}


// ========================================================================
// __unwind$236937
// EA  : 0x8282B644
// RVA : 0x0082B644
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_236937()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$236938
// EA  : 0x8282B66C
// RVA : 0x0082B66C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_236938()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?WriteBinary@idMD6Anim@@QAA_NPBD@Z
// EA  : 0x8282B6A0
// RVA : 0x0082B6A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::WriteBinary(idMD6Anim *this, const char *filename)
{
  const char *v5; // r3
  idFileLocal v6; // [sp+50h] [-30h] BYREF
  unsigned int totalSize; // [sp+54h] [-2Ch] BYREF

  if ( this->animData != nullptr )
  {
    v6.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
    if ( v6.file != nullptr )
    {
      idLib::Printf(fmt: "Writing '%s'\n", filename);
      v6.file->Write(this: v6.file, a2: &MD6_ANIM_MAGIC, a3: 4u);
      v6.file->Write(this: v6.file, a2: &this->timestamp, a3: 4u);
      v6.file->Write(this: v6.file, a2: &this->phaseTrackTimestamp, a3: 4u);
      v6.file->Write(this: v6.file, a2: &this->settingsTimestamp, a3: 4u);
      v6.file->Write(this: v6.file, a2: &this->timeCode, a3: 4u);
      v6.file->Write(this: v6.file, a2: &this->translatedBounds, a3: 12u);
      v6.file->Write(this: v6.file, a2: &this->normalizedBounds, a3: 12u);
      v5 = animation->GetJointConversionName(this: animation, a2: &this->jointConversionHandle);
      idFile::WriteString(this: v6.file, string: v5);
      v6.file->Write(this: v6.file, a2: &this->jointConversionChecksum, a3: 2u);
      v6.file->Write(this: v6.file, a2: &this->origWorldPos, a3: 12u);
      v6.file->Write(this: v6.file, a2: &this->origWorldRot, a3: 12u);
      v6.file->Write(this: v6.file, a2: &this->origWorldScale, a3: 12u);
      v6.file->Write(this: v6.file, a2: &this->startFrameOffset, a3: 2u);
      v6.file->Write(this: v6.file, a2: &this->endFrameOffset, a3: 2u);
      totalSize = this->animData->totalSize;
      v6.file->Write(this: v6.file, a2: &totalSize, a3: 4u);
      v6.file->Write(this: v6.file, a2: this->animData, a3: totalSize);
      idMD6PhaseTrack::WriteBinary(this: &this->phaseTrack, file: v6.file);
      idFileLocal::~idFileLocal(this: &v6);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Could not write '%s'", filename);
      idFileLocal::~idFileLocal(this: &v6);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "Could not write '%s'. animData is NULL", filename);
    return 0;
  }
}


// ========================================================================
// __unwind$237226_1
// EA  : 0x8282B928
// RVA : 0x0082B928
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_237226_1()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 80));
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GenerateJointRLE
// EA  : 0x8282BCE0
// RVA : 0x0082BCE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *sourceSkeleton,
        idIndex<short,enum invalidJointIndex_t> *targetSkeleton,
        unsigned __int8 num,
        const idList<unsigned char,5> *bits,
        idList<unsigned char,37> *RLE,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        unsigned __int8 a16)
{
  int v20; // r29
  int v21; // r21
  int v22; // r23
  int v23; // r31
  unsigned __int8 TargetMappedJointIndex; // r24
  unsigned __int8 v25; // r27
  unsigned __int8 v26; // r30
  unsigned __int8 v27; // r3
  int v28; // r10
  bool v29; // cr58
  unsigned __int8 v31; // [sp+50h] [-80h] BYREF
  unsigned __int8 v32[127]; // [sp+51h] [-7Fh] BYREF

  a16 = num;
  if ( sourceSkeleton == nullptr || targetSkeleton == nullptr )
    return 0;
  idList<unsigned char,25>::Append(this: RLE, obj: &a16);
  v20 = 0;
  v21 = 1;
  v22 = (*(unsigned __int16 *)(*(_DWORD *)&sourceSkeleton[20].value + 2) + 7) & 0xFFF8;
  if ( v22 != 0 )
  {
    do
    {
      if ( ((1 << (v20 & 7)) & bits->list[v20 / 8]) != 0 )
      {
        v23 = v20 + 1;
        TargetMappedJointIndex = _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedJointIndex(
                                   sourceSkeleton,
                                   targetSkeleton,
                                   sourceJointIndex: (unsigned __int8)v20);
        v32[0] = TargetMappedJointIndex;
        v25 = 1;
        v31 = 1;
        v26 = TargetMappedJointIndex;
        if ( v20 + 1 < v22 )
        {
          while ( v25 < 0x7Fu )
          {
            if ( ((1 << (v23 & 7)) & bits->list[v23 / 8]) != 0 )
            {
              v27 = _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedJointIndex(
                      sourceSkeleton,
                      targetSkeleton,
                      sourceJointIndex: (unsigned __int8)v23);
              v28 = (*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 2) + 7) & 0xFFF8;
              if ( v27 == v28 )
                v29 = v26 == v28;
              else
                v29 = v27 == v26 + 1;
              if ( !v29 )
                break;
              v26 = v27;
              ++v25;
            }
            ++v23;
            ++v20;
            if ( v23 >= v22 )
              break;
          }
          v31 = v25;
        }
        if ( TargetMappedJointIndex == ((*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 2) + 7) & 0xFFF8) )
        {
          v31 = v25 | 0x80;
          idList<unsigned char,25>::Append(this: RLE, obj: &v31);
          v21 = (unsigned __int16)(v21 + 1);
        }
        else
        {
          idList<unsigned char,25>::Append(this: RLE, obj: &v31);
          idList<unsigned char,25>::Append(this: RLE, obj: v32);
          v21 = (unsigned __int16)(v21 + 2);
        }
      }
      ++v20;
    }
    while ( v20 < v22 );
  }
  return v21;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GenerateUserChannelRLE
// EA  : 0x8282BEB0
// RVA : 0x0082BEB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GenerateUserChannelRLE(
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *sourceSkeleton,
        idIndex<short,enum invalidUserChannelIndex_t> *targetSkeleton,
        int numPaddedUserChannels_,
        unsigned __int8 num,
        const idList<unsigned char,5> *bits,
        idList<unsigned char,37> *RLE,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        unsigned __int8 a18)
{
  int v24; // r21
  __int16 v25; // r10
  int v26; // r23
  int i; // r28
  int v28; // r31
  unsigned __int8 TargetMappedUserChannelIndex; // r24
  unsigned __int8 v30; // r27
  unsigned __int8 v31; // r30
  unsigned __int8 v32; // r3
  int v33; // r10
  bool v34; // cr58
  unsigned __int8 v36; // [sp+50h] [-80h] BYREF
  unsigned __int8 v37[127]; // [sp+51h] [-7Fh] BYREF

  a18 = num;
  idList<unsigned char,25>::Append(this: RLE, obj: &a18);
  v24 = 1;
  if ( sourceSkeleton != nullptr )
  {
    v25 = *(_WORD *)(*(_DWORD *)&sourceSkeleton[20].value + 4) + 7;
    if ( (unsigned __int16)(v25 & 0xFFF8) >= numPaddedUserChannels_ )
      v26 = numPaddedUserChannels_;
    else
      v26 = v25 & 0xFFF8;
  }
  else
  {
    v26 = num;
  }
  for ( i = 0; i < v26; ++i )
  {
    if ( ((1 << (i & 7)) & bits->list[i / 8]) != 0 )
    {
      v28 = i + 1;
      TargetMappedUserChannelIndex = _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedUserChannelIndex(
                                       sourceSkeleton,
                                       targetSkeleton,
                                       sourceUserChannelIndex: (unsigned __int8)i);
      v37[0] = TargetMappedUserChannelIndex;
      v30 = 1;
      v36 = 1;
      v31 = TargetMappedUserChannelIndex;
      if ( i + 1 < v26 )
      {
        while ( v30 < 0x7Fu )
        {
          if ( ((1 << (v28 & 7)) & bits->list[v28 / 8]) != 0 )
          {
            v32 = _idMD6Anim::CompressAnim_::_2_::local_t::GetTargetMappedUserChannelIndex(
                    sourceSkeleton,
                    targetSkeleton,
                    sourceUserChannelIndex: (unsigned __int8)v28);
            v33 = (*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 4) + 7) & 0xFFF8;
            if ( v32 == v33 )
              v34 = v31 == v33;
            else
              v34 = v32 == v31 + 1;
            if ( !v34 )
              break;
            v31 = v32;
            ++v30;
          }
          ++v28;
          ++i;
          if ( v28 >= v26 )
            break;
        }
        v36 = v30;
      }
      if ( TargetMappedUserChannelIndex == ((*(unsigned __int16 *)(*(_DWORD *)&targetSkeleton[20].value + 4) + 7)
                                          & 0xFFF8) )
      {
        v36 = v30 | 0x80;
        idList<unsigned char,25>::Append(this: RLE, obj: &v36);
        v24 = (unsigned __int16)(v24 + 1);
      }
      else
      {
        idList<unsigned char,25>::Append(this: RLE, obj: &v36);
        idList<unsigned char,25>::Append(this: RLE, obj: v37);
        v24 = (unsigned __int16)(v24 + 2);
      }
    }
  }
  return v24;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GetDescendants
// EA  : 0x8282C090
// RVA : 0x0082C090
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GetDescendants(
        const __int16 jointIndex,
        const __int16 *parentTable,
        int numPaddedJoints,
        idList<unsigned short,5> *descendants)
{
  int v6; // r29
  int v7; // r25
  int granularity; // r4
  int size; // r11
  bool v11; // cr58
  signed int v12; // r10
  int v13; // r4
  int v14; // r11
  int num; // r11

  v6 = 0;
  if ( numPaddedJoints > 0 )
  {
    v7 = jointIndex;
    do
    {
      if ( *parentTable == v7 )
      {
        if ( descendants->list != nullptr )
          goto LABEL_8;
        granularity = descendants->granularity;
        if ( granularity <= 0 )
          granularity = 1;
        if ( (unsigned __int8)idList<unsigned short,30>::Resize(this: descendants, newsize: granularity) != 0 )
        {
LABEL_8:
          size = descendants->size;
          if ( descendants->num != size )
            goto LABEL_19;
          if ( forceIdListsToReallocateEveryAppend )
          {
            v11 = (unsigned __int8)idList<unsigned short,30>::Resize(this: descendants, newsize: size + 1) == 0;
          }
          else
          {
            v12 = descendants->granularity;
            if ( descendants->granularity != 0 )
            {
              v14 = size + v12;
              __twllei(v12, 0);
              __twlgei(v12 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
              v11 = (unsigned __int8)idList<unsigned short,30>::Resize(this: descendants, newsize: v14 - v14 % v12) == 0;
            }
            else
            {
              v13 = 2 * size;
              if ( 2 * size >= size )
              {
                if ( v13 == 0 )
                  v13 = 1;
                v11 = (unsigned __int8)idList<unsigned short,30>::Resize(this: descendants, newsize: v13) == 0;
              }
              else
              {
                v11 = (unsigned __int8)idList<unsigned short,30>::Resize(this: descendants, newsize: 0x7FFFFFFF) == 0;
              }
            }
          }
          if ( !v11 )
          {
LABEL_19:
            num = descendants->num;
            if ( num < descendants->size )
            {
              descendants->list[num] = v6;
              ++descendants->num;
            }
          }
        }
      }
      ++v6;
      ++parentTable;
    }
    while ( v6 < numPaddedJoints );
  }
  return descendants->num;
}


// ========================================================================
// `idMD6Anim::CompressAnim'::`2'::local_t::GetSetFarthestEndEffector
// EA  : 0x8282C218
// RVA : 0x0082C218
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall _idMD6Anim::CompressAnim_::_2_::local_t::GetSetFarthestEndEffector(
        __int16 jointIndex,
        const __int16 *parentTable,
        const idList<float,5> *distanceToRoot,
        idList<short,5> *farthestEndEffectorList)
{
  __int16 *list; // r25
  unsigned int v6; // r24
  int result; // r3
  int num; // r5
  int Descendants; // r3
  __int16 v13; // r23
  double v14; // fp31
  int v15; // r30
  int i; // r26
  __int16 SetFarthestEndEffector; // r3
  int v18; // r8
  int v19; // r30
  idList<unsigned short,5> v20; // [sp+60h] [-290h] BYREF
  int v21; // [sp+70h] [-280h] BYREF

  list = farthestEndEffectorList->list;
  v6 = jointIndex;
  result = (unsigned __int16)farthestEndEffectorList->list[v6];
  if ( result == 0xFFFF )
  {
    num = distanceToRoot->num;
    v20.granularity = 1;
    v20.size = 272;
    v20.list = (unsigned __int16 *)&v21;
    v20.num = 0;
    v20.memTag = 5;
    v20.listStatic = 1;
    Descendants = _idMD6Anim::CompressAnim_::_2_::local_t::GetDescendants(
                    jointIndex,
                    parentTable,
                    numPaddedJoints: num,
                    descendants: &v20);
    if ( Descendants != 0 )
    {
      v13 = -1;
      v14 = -1.0;
      if ( Descendants > 0 )
      {
        v15 = 0;
        for ( i = Descendants; i != 0; --i )
        {
          SetFarthestEndEffector = _idMD6Anim::CompressAnim_::_2_::local_t::GetSetFarthestEndEffector(
                                     jointIndex: v20.list[v15],
                                     parentTable,
                                     distanceToRoot,
                                     farthestEndEffectorList);
          v18 = SetFarthestEndEffector;
          if ( distanceToRoot->list[v18] > v14 )
          {
            v14 = distanceToRoot->list[v18];
            v13 = SetFarthestEndEffector;
          }
          ++v15;
        }
      }
      list[v6] = v13;
    }
    else
    {
      list[v6] = jointIndex;
    }
    v19 = (unsigned __int16)list[v6];
    if ( (v20.listStatic == 0 || v20.listStatic == 2) && v20.list != nullptr )
      idMem::Free(this: &mem, ptr: v20.list, align: ALIGN_16);
    return v19;
  }
  return result;
}


// ========================================================================
// __unwind$238543
// EA  : 0x8282C350
// RVA : 0x0082C350
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_238543()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 96));
}


// ========================================================================
// ?ReloadIfStale@idMD6Anim@@UAA_NXZ
// EA  : 0x8282C598
// RVA : 0x0082C598
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::ReloadIfStale(idMD6Anim *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  bool v4; // r11
  bool v5; // r19
  unsigned __int64 v6; // r6
  const char *v7; // r7
  unsigned int str; // r21
  idResource *v9; // r3
  idMD6AnimData *animData; // r11
  unsigned __int64 v11; // r6
  const char *v12; // r7
  int v13; // r30
  idFile_vtbl *v14; // r26
  unsigned int v15; // r3
  void *logIndex; // r23
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  unsigned int timestamp; // r29
  unsigned int v22; // r3
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  int v26; // r3
  int v27; // r26
  int i; // r30
  const char *v29; // r3
  const idStr *v30; // r3
  idStr *v31; // r3
  unsigned int v32; // r3
  unsigned __int64 v33; // r6
  const char *v34; // r7
  unsigned int v35; // r30
  unsigned __int64 v36; // r6
  const char *v37; // r7
  unsigned int v38; // r30
  int v39; // [sp+8h] [-7D8h]
  int v40; // [sp+Ch] [-7D4h]
  int v41; // [sp+10h] [-7D0h]
  int v42; // [sp+14h] [-7CCh]
  int v43; // [sp+18h] [-7C8h]
  int v44; // [sp+1Ch] [-7C4h]
  idFileLocal v45; // [sp+50h] [-790h] BYREF
  __int16 v46; // [sp+54h] [-78Ch] BYREF
  idPLogScope v47; // [sp+58h] [-788h] BYREF
  idPLogScope v48; // [sp+60h] [-780h] BYREF
  idPLogScope v49; // [sp+68h] [-778h] BYREF
  int v50; // [sp+70h] [-770h] BYREF
  idStr v51; // [sp+80h] [-760h] BYREF
  idStr v52; // [sp+A0h] [-740h] BYREF
  idToken v53; // [sp+C0h] [-720h] BYREF
  idStr v54; // [sp+110h] [-6D0h] BYREF
  idStr v55; // [sp+130h] [-6B0h] BYREF
  idStr v56; // [sp+150h] [-690h] BYREF
  idStr v57; // [sp+170h] [-670h] BYREF
  idStrStatic<256> v58; // [sp+190h] [-650h] BYREF
  idParser v59; // [sp+2B0h] [-530h] BYREF
  idStrStatic<256> v60; // [sp+540h] [-2A0h] BYREF
  _BYTE v61[384]; // [sp+660h] [-180h] BYREF

  RD_EventBegin(name: "idMD6Anim::ReloadIfStale");
  LODWORD(v2) = "idMD6Anim::ReloadIfStale";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v49, pl: &pLog, gMask: v2, label: v3);
  v4 = this->jointConversionHandle.value != 0xFFFF && this->jointConversionChecksum.value != 0xFFFF;
  v5 = v4;
  if ( v4 )
    v5 = (_cntlzw(
            this->jointConversionChecksum.value
          - *(unsigned __int16 *)((int (__fastcall *)(int *))animation->GetJointConversionCrc)(a1: &v50))
        & 0x20) != 0;
  RD_EventBegin(name: "idMD6Anim::ReloadIfStale - GetTimeStamp 1");
  LODWORD(v6) = "idMD6Anim::ReloadIfStale - GetTimeStamp 1";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v47, pl: &pLog, gMask: v6, label: v7);
  str = fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false);
  idPLogScope::~idPLogScope(this: &v47);
  RD_EventEnd();
  idStr::idStr(this: &v52, text: this->name.str);
  idStr::StripPath(this: &v52);
  if ( idStr::Cmp(s1: v52.data, s2: idMD6Model::DEFAULT_ANIM_NAME) == 0 )
  {
    idStr::idStr(this: &v54, text: this->name.str);
    idStr::StripFilename(this: &v54);
    idStr::SetFileExtension(this: &v54, extension: MD6_SKEL_EXT);
    v9 = idResourceList::Load(this: &idMD6Skel::resourceList, name: v54.data, makeDefault: true, skipStaleCheck: false);
    if ( v9 != nullptr )
      str = (unsigned int)v9[1].name.str;
    idStr::FreeData(this: &v54);
  }
  animData = this->animData;
  if ( animData != nullptr && (animData->flags & 0x8000) != 0 )
  {
    RD_EventBegin(name: "idMD6Anim::ReloadIfStale - GetTimeStamp Composite");
    LODWORD(v11) = "idMD6Anim::ReloadIfStale - GetTimeStamp Composite";
    HIDWORD(v11) = 2;
    idPLogScope::idPLogScope(this: &v47, pl: &pLog, gMask: v11, label: v12);
    idParser::idParser(this: &v59, flags: 262704);
    v45.file = fileSystem->OpenFileRead(this: fileSystem, a2: this->name.str, a3: 1, a4: 0);
    v13 = v45.file->Length(this: v45.file);
    idTempArray<char>::idTempArray<char>(this: (idTempArray<char> *)&v48, num: v13 + 1);
    v14 = v45.file->__vftable;
    v15 = v45.file->Length(this: v45.file);
    logIndex = (void *)v48.logIndex;
    if ( v14->Read(this: v45.file, a2: (void *)v48.logIndex, a3: v15) != v13 )
    {
      HIDWORD(v19) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Failed to read file for md6anim '%s'",
        a3: v19,
        a4: v18,
        a5: v17,
        a6: v39,
        a7: v40,
        a8: v41,
        a9: v42,
        a10: v43,
        a11: v44);
      if ( logIndex != nullptr )
        idMem::Free(this: &mem, ptr: logIndex, align: ALIGN_16);
LABEL_16:
      idFileLocal::~idFileLocal(this: &v45);
      idParser::~idParser(this: &v59);
      idPLogScope::~idPLogScope(this: &v47);
      RD_EventEnd();
      idStr::FreeData(this: &v52);
      idPLogScope::~idPLogScope(this: &v49);
      RD_EventEnd();
      return 0;
    }
    timestamp = this->timestamp;
    v22 = v45.file->Timestamp(this: v45.file);
    if ( v22 <= timestamp )
      v22 = timestamp;
    this->timestamp = v22;
    *((_BYTE *)logIndex + v13) = 0;
    if ( !idParser::LoadMemory(this: &v59, ptr: (const char *)logIndex, length: v13 + 1, name: this->name.str) )
    {
      HIDWORD(v25) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Error parsing file for md6anim '%s'",
        a3: v25,
        a4: v24,
        a5: v23,
        a6: v39,
        a7: v40,
        a8: v41,
        a9: v42,
        a10: v43,
        a11: v44);
      if ( logIndex != nullptr )
        idMem::Free(this: &mem, ptr: logIndex, align: ALIGN_16);
      goto LABEL_16;
    }
    idParser::ExpectTokenString(this: &v59, string: MD6_VERSION_STRING);
    v26 = idParser::ParseInt(this: &v59);
    if ( v26 != 7 && v26 != 6 )
      idParser::Error(
        this: &v59,
        str: "MD6 anim '%s' has an invalid version %d. Should be version %d.",
        this->name.str,
        v26,
        7);
    idParser::SkipUntilString(this: &v59, string: "facesetupBasePath");
    v53.len = 0;
    v53.baseBuffer[0] = 0;
    v53.intvalue = 0;
    v53.allocedAndFlag = 20;
    v53.data = v53.baseBuffer;
    memset(&v53.whiteSpaceStart_p, 0, 12);
    v53.floatvalue = -3.4028235e38;
    idParser::ReadToken(this: &v59, token: &v53);
    idStrStatic<256>::idStrStatic<256>(this: &v58, text: v53.data);
    v27 = animation->GetNumUserChannels(this: animation);
    for ( i = 0; i < v27; ++i )
    {
      v46 = i;
      v29 = animation->GetUserChannelName(this: animation, a2: &v46);
      idStr::idStr(this: &v55, text: v29);
      if ( idStr::Find(searchIn: v55.data, searchFor: "facedata_", casesensitive: true, start: 0, end: v55.len) != -1 )
      {
        v30 = operator+(result: &v57, a: v53.data, b: &v55);
        v31 = operator+(result: &v56, a: v30, b: ".md6anim");
        idStrStatic<256>::idStrStatic<256>(this: &v60, text: v31);
        v58.len = v60.len;
        memcpy(Dst: v58.data, Src: v60.data, Size: v60.len + 1);
        idStr::FreeData(this: &v60);
        idStr::FreeData(this: &v56);
        idStr::FreeData(this: &v57);
        v32 = fileSystem->GetTimestamp(this: fileSystem, a2: v58.data, a3: false);
        if ( str <= v32 )
          str = v32;
      }
      idStr::FreeData(this: &v55);
    }
    idStr::FreeData(this: &v58);
    idStr::FreeData(this: &v53);
    if ( logIndex != nullptr )
      idMem::Free(this: &mem, ptr: logIndex, align: ALIGN_16);
    idFileLocal::~idFileLocal(this: &v45);
    idParser::~idParser(this: &v59);
    idPLogScope::~idPLogScope(this: &v47);
    RD_EventEnd();
  }
  if ( v5 && str == this->timestamp )
  {
    idStr::idStr(this: &v51, text: this->name.str);
    idStr::SetFileExtension(this: &v51, extension: "ptrack");
    RD_EventBegin(name: "idMD6Anim::ReloadIfStale - GetTimeStamp 2");
    LODWORD(v33) = "idMD6Anim::ReloadIfStale - GetTimeStamp 2";
    HIDWORD(v33) = 2;
    idPLogScope::idPLogScope(this: &v48, pl: &pLog, gMask: v33, label: v34);
    v35 = fileSystem->GetTimestamp(this: fileSystem, a2: v51.data, a3: false);
    idPLogScope::~idPLogScope(this: &v48);
    RD_EventEnd();
    if ( v35 == -1 || v35 == this->phaseTrackTimestamp )
    {
      idStr::SetFileExtension(this: &v51, extension: "md6settings");
      RD_EventBegin(name: "idMD6Anim::ReloadIfStale - GetTimeStamp 3");
      LODWORD(v36) = "idMD6Anim::ReloadIfStale - GetTimeStamp 3";
      HIDWORD(v36) = 2;
      idPLogScope::idPLogScope(this: &v48, pl: &pLog, gMask: v36, label: v37);
      v38 = fileSystem->GetTimestamp(this: fileSystem, a2: v51.data, a3: false);
      idPLogScope::~idPLogScope(this: &v48);
      RD_EventEnd();
      if ( v38 == this->settingsTimestamp )
      {
        idStr::FreeData(this: &v51);
        idStr::FreeData(this: &v52);
        idPLogScope::~idPLogScope(this: &v49);
        RD_EventEnd();
        return 0;
      }
    }
    idStr::FreeData(this: &v51);
  }
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6anim", a4: this->name.str, a5: v61, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v61, a3: FSPATH_BASE);
  this->LoadResource(this);
  idStr::FreeData(this: &v52);
  idPLogScope::~idPLogScope(this: &v49);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// $M239572
// EA  : 0x8282CD48
// RVA : 0x0082CD48
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int _M239572()
{
  idLib::Error(fmt: "idMD6Anim::ReloadIfStale - %s", idException::error);
  return _LN426();
}


// ========================================================================
// $LN426
// EA  : 0x8282CD68
// RVA : 0x0082CD68
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN426()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2016 + 1892));
}


// ========================================================================
// __unwind$239030
// EA  : 0x8282CD90
// RVA : 0x0082CD90
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239030()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2016 + 104));
}


// ========================================================================
// __unwind$239031
// EA  : 0x8282CDB8
// RVA : 0x0082CDB8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239031()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2016 + 1893));
}


// ========================================================================
// __unwind$239032
// EA  : 0x8282CDE0
// RVA : 0x0082CDE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239032()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2016 + 88));
}


// ========================================================================
// __unwind$239033
// EA  : 0x8282CE08
// RVA : 0x0082CE08
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 160));
}


// ========================================================================
// __unwind$239034
// EA  : 0x8282CE30
// RVA : 0x0082CE30
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 272));
}


// ========================================================================
// __unwind$239035
// EA  : 0x8282CE58
// RVA : 0x0082CE58
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239035()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2016 + 1894));
}


// ========================================================================
// __unwind$239036
// EA  : 0x8282CE80
// RVA : 0x0082CE80
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239036()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2016 + 88));
}


// ========================================================================
// __unwind$239037
// EA  : 0x8282CEA8
// RVA : 0x0082CEA8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239037()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 2016 + 688));
}


// ========================================================================
// __unwind$239038
// EA  : 0x8282CED0
// RVA : 0x0082CED0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239038()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 2016 + 80));
}


// ========================================================================
// __unwind$239039
// EA  : 0x8282CEF8
// RVA : 0x0082CEF8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239039()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 2016 + 96));
}


// ========================================================================
// __unwind$239040
// EA  : 0x8282CF20
// RVA : 0x0082CF20
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 192));
}


// ========================================================================
// __unwind$239041
// EA  : 0x8282CF48
// RVA : 0x0082CF48
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239041()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 400));
}


// ========================================================================
// __unwind$239042
// EA  : 0x8282CF70
// RVA : 0x0082CF70
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 304));
}


// ========================================================================
// __unwind$239043
// EA  : 0x8282CF98
// RVA : 0x0082CF98
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239043()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 368));
}


// ========================================================================
// __unwind$239044
// EA  : 0x8282CFC0
// RVA : 0x0082CFC0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 336));
}


// ========================================================================
// __unwind$239046
// EA  : 0x8282CFE8
// RVA : 0x0082CFE8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239046()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2016 + 128));
}


// ========================================================================
// __unwind$239047
// EA  : 0x8282D010
// RVA : 0x0082D010
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239047()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2016 + 1895));
}


// ========================================================================
// __unwind$239048
// EA  : 0x8282D038
// RVA : 0x0082D038
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239048()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2016 + 96));
}


// ========================================================================
// __unwind$239049
// EA  : 0x8282D060
// RVA : 0x0082D060
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239049()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2016 + 1896));
}


// ========================================================================
// __unwind$239050
// EA  : 0x8282D088
// RVA : 0x0082D088
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239050()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2016 + 96));
}


// ========================================================================
// ?RewriteText@idMD6Anim@@SA_NPBD@Z
// EA  : 0x8282D0B8
// RVA : 0x0082D0B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::RewriteText(const char *filename)
{
  int v2; // r3
  double v3; // fp31
  int v4; // r30
  int len; // r30
  int networkID; // r30
  unsigned __int8 listStatic; // r23
  unsigned __int16 *list; // r22
  int size; // r11
  char v10; // r3
  unsigned __int8 v11; // r15
  idStr *v12; // r16
  int v13; // r14
  bool v14; // r3
  int v15; // r27
  int v16; // r30
  int v17; // r25
  unsigned __int16 v18; // r28
  int v19; // r29
  unsigned __int8 *v20; // r10
  char resourceError; // r18
  char *str; // r19
  idResource *resourceListPtr; // r17
  bool v24; // r3
  idResource *i; // r30
  unsigned __int8 v26; // r21
  char *v27; // r22
  int v28; // r20
  int v29; // r28
  char v30; // r3
  int j; // r29
  idResource *v32; // r28
  char *v33; // r30
  idResource *v34; // r11
  int v35; // r26
  int v36; // r30
  idList<float,13> *v37; // r27
  idResource *v38; // r11
  idStr *v39; // r3
  float *v40; // r29
  const idHandle<unsigned short,enum invalidCrc_t,65535> *v41; // r6
  int v42; // r5
  const char *v43; // r25
  idMD6Model *v44; // r30
  const idMD6Skel *skeleton; // r28
  int i5; // r30
  const idHandle<unsigned short,enum invalidCrc_t,65535> *v47; // r6
  int v48; // r5
  int i1; // r30
  int i2; // r30
  int i3; // r11
  int i4; // r11
  int i6; // r30
  int i7; // r11
  int i8; // r11
  idResource *v57; // r3
  int jj; // r30
  int kk; // r30
  int mm; // r11
  int nn; // r11
  int k; // r30
  int m; // r30
  int n; // r11
  int ii; // r11
  int i9; // r30
  int i10; // r30
  int i11; // r11
  int i12; // r11
  int v70; // r26
  int i13; // r30
  const char *v72; // r3
  idFile *v73; // r3
  int i14; // r30
  int i15; // r30
  int i16; // r11
  int i17; // r11
  const char *v78; // r29
  const char *v79; // r3
  const char *v80; // r29
  const char *v81; // r3
  const char *v82; // r3
  const char *v83; // r3
  const char *v84; // r3
  unsigned __int16 *v85; // r26
  int v86; // r30
  unsigned __int8 *v87; // r24
  idResource *v88; // r23
  idResource *i18; // r30
  int i19; // r30
  void (*Printf)(void); // ctr
  int v92; // r24
  int i20; // r29
  void (*v94)(void); // ctr
  int i21; // r30
  idFile *file; // r30
  int v97; // r29
  cmType_t ScriptP; // r3
  int i22; // r30
  int i23; // r30
  int i24; // r11
  int i25; // r11
  double v103; // [sp+20h] [-540h]
  idFileLocal v104; // [sp+50h] [-510h] BYREF
  int v105; // [sp+54h] [-50Ch]
  idResource *nextOnHashChain; // [sp+58h] [-508h]
  idList<unsigned short,5> v107; // [sp+60h] [-500h] BYREF
  idList<unsigned char,37> v108; // [sp+70h] [-4F0h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> v109; // [sp+80h] [-4E0h] BYREF
  int v110; // [sp+84h] [-4DCh]
  idMD6Skel v111; // [sp+88h] [-4D8h] BYREF
  int v112; // [sp+C0h] [-4A0h]
  int v113; // [sp+C4h] [-49Ch]
  int v114; // [sp+D4h] [-48Ch]
  float v115; // [sp+D8h] [-488h]
  int v116; // [sp+DCh] [-484h]
  int v117; // [sp+E0h] [-480h]
  int v118; // [sp+E4h] [-47Ch]
  idList<idList<float,5>,5> v119; // [sp+F0h] [-470h] BYREF
  idList<idStr,5> v120; // [sp+100h] [-460h] BYREF
  __int16 v121; // [sp+110h] [-450h] BYREF
  int v122; // [sp+114h] [-44Ch]
  const char *v123; // [sp+118h] [-448h]
  const char *v124; // [sp+11Ch] [-444h]
  int v125; // [sp+120h] [-440h]
  idLexer v126; // [sp+130h] [-430h] BYREF
  idStr v127; // [sp+1C0h] [-3A0h] BYREF
  idStr v128; // [sp+1E0h] [-380h] BYREF
  idStr v129; // [sp+200h] [-360h] BYREF
  idStr v130; // [sp+220h] [-340h] BYREF
  idStr v131; // [sp+240h] [-320h] BYREF
  int v132; // [sp+260h] [-300h]
  idStr v133; // [sp+270h] [-2F0h] BYREF
  const char *v134; // [sp+290h] [-2D0h]
  const char *v135; // [sp+294h] [-2CCh]
  const char *v136; // [sp+298h] [-2C8h]
  const char *v137; // [sp+29Ch] [-2C4h]
  idStr v138; // [sp+2A0h] [-2C0h] BYREF
  const char *v139; // [sp+2C0h] [-2A0h]
  idStr v140; // [sp+2D0h] [-290h] BYREF
  const char *v141; // [sp+2F0h] [-270h]
  const char *v142; // [sp+2F4h] [-26Ch]
  const char *v143; // [sp+2F8h] [-268h]
  const char *v144; // [sp+2FCh] [-264h]
  const char *v145; // [sp+300h] [-260h]
  const char *v146; // [sp+304h] [-25Ch]
  idStr v147; // [sp+310h] [-250h] BYREF
  idStr v148; // [sp+330h] [-230h] BYREF
  idStr v149; // [sp+350h] [-210h] BYREF
  idStr v150; // [sp+370h] [-1F0h] BYREF
  idStr v151; // [sp+390h] [-1D0h] BYREF
  idStr v152; // [sp+3B0h] [-1B0h] BYREF
  idAngles v153; // [sp+3D0h] [-190h] BYREF
  idAngles v154; // [sp+3E0h] [-180h] BYREF
  idAngles v155; // [sp+3F0h] [-170h] BYREF
  idStr v156; // [sp+400h] [-160h] BYREF
  idStr v157; // [sp+420h] [-140h] BYREF
  idStr v158; // [sp+440h] [-120h] BYREF
  idStr v159; // [sp+460h] [-100h] BYREF
  idAngles v160; // [sp+480h] [-E0h] BYREF
  idAngles v161; // [sp+48Ch] [-D4h] BYREF
  idAngles v162; // [sp+4A0h] [-C0h] BYREF
  idAngles v163; // [sp+4ACh] [-B4h] BYREF

  idLexer::idLexer(this: &v126, flags_: 262704);
  if ( !idLexer::LoadFile(this: &v126, filename_: filename, OSPath: false) )
  {
    idLib::Warning(fmt: "Failed to load file '%s'", filename);
    idLexer::~idLexer(this: &v126);
    return 0;
  }
  idLexer::ExpectTokenString(this: &v126, string: MD6_VERSION_STRING);
  v2 = idLexer::ParseInt(this: &v126);
  v132 = v2;
  if ( v2 != 7 && v2 != 6 && v2 != 5 && v2 != 4 )
    idLexer::Error(this: &v126, str: "MD6 anim '%s' has an invalid version %d. Should be version %d.", filename, v2, 7);
  v111.networkID = 0;
  *((_DWORD *)&v111.idResource + 8) = 20;
  v111.staleCount = (int)&v111.defaultAnim;
  v115 = -3.4028235e38;
  HIBYTE(v111.defaultAnim) = 0;
  v114 = 0;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  idLexer::ExpectTokenString(this: &v126, string: "init");
  idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 46, token: (idToken *)&v111.networkID);
  v130.allocedAndFlag = 20;
  v130.len = 0;
  v130.data = v130.baseBuffer;
  v130.baseBuffer[0] = 0;
  v128.allocedAndFlag = 20;
  v128.data = v128.baseBuffer;
  v128.len = 0;
  v128.baseBuffer[0] = 0;
  v129.allocedAndFlag = 20;
  v129.data = v129.baseBuffer;
  v129.len = 0;
  v129.baseBuffer[0] = 0;
  v152.allocedAndFlag = 20;
  v152.data = v152.baseBuffer;
  v152.len = 0;
  v152.baseBuffer[0] = 0;
  v150.allocedAndFlag = 20;
  v150.data = v150.baseBuffer;
  v150.len = 0;
  v150.baseBuffer[0] = 0;
  v148.allocedAndFlag = 20;
  v148.data = v148.baseBuffer;
  v148.len = 0;
  v148.baseBuffer[0] = 0;
  v151.allocedAndFlag = 20;
  v151.data = v151.baseBuffer;
  v151.len = 0;
  v151.baseBuffer[0] = 0;
  v149.allocedAndFlag = 20;
  v149.data = v149.baseBuffer;
  v149.len = 0;
  v149.baseBuffer[0] = 0;
  v147.allocedAndFlag = 20;
  v147.data = v147.baseBuffer;
  v147.len = 0;
  v147.baseBuffer[0] = 0;
  v3 = 0.60000002;
  v155.pitch = 0.0;
  v155.yaw = 0.0;
  v155.roll = 0.0;
  v153.pitch = 0.0;
  v153.yaw = 0.0;
  v141 = "maxErrorUser";
  v143 = "maxErrorTranslation";
  v153.roll = 0.0;
  v154.pitch = 1.0;
  v154.yaw = 1.0;
  v154.roll = 1.0;
  v136 = "Unknown token '%s'";
  v145 = "numUserChannels";
  v123 = "scaleMask";
  v111.__vftable = (idMD6Skel_vtbl *)"rotationMask";
  v139 = "translatedBounds";
  v110 = 2;
  v125 = 30;
  v105 = 0;
  v122 = 0;
  nextOnHashChain = nullptr;
  v134 = "maxErrorScale";
  v135 = "maxErrorRotation";
  v144 = "worldScale";
  v4 = 0;
  v142 = "worldRot";
  v146 = "normalizedBounds";
  v124 = "translationMask";
  v137 = "worldPos";
  while ( idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID) && (v112 != 5 || v113 != 47) )
  {
    if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "commandLine") != 0 )
    {
      if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "sourceAnim") != 0 )
      {
        if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "sourceTake") != 0 )
        {
          if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "subtractiveAnim") != 0 )
          {
            if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: (const char *)v111.__vftable) != 0 )
            {
              if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v123) != 0 )
              {
                if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v124) != 0 )
                {
                  if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "skeletonName") == 0 )
                    goto _M243495;
                  if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "meshName") != 0 )
                  {
                    if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "startFrame") != 0 )
                    {
                      if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "numFrames") != 0 )
                      {
                        if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "frameRate") != 0 )
                        {
                          if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "numJoints") != 0 )
                          {
                            if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v145) != 0 )
                            {
                              if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v139) != 0 )
                              {
                                if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v146) != 0 )
                                {
                                  if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v137) != 0 )
                                  {
                                    if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v142) != 0 )
                                    {
                                      if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v144) != 0 )
                                      {
                                        if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: v135) != 0
                                          && idStr::Icmp(s1: (const char *)v111.staleCount, s2: v134) != 0
                                          && idStr::Icmp(s1: (const char *)v111.staleCount, s2: v143) != 0
                                          && idStr::Icmp(s1: (const char *)v111.staleCount, s2: "maxErrorUser") != 0 )
                                        {
                                          if ( idStr::Icmp(s1: (const char *)v111.staleCount, s2: "errorTolerance") != 0 )
                                            idLexer::Error(this: &v126, str: v136, v111.staleCount);
                                          else
                                            v3 = idLexer::ParseFloat(this: &v126, errorFlag: nullptr);
                                        }
                                        else
                                        {
_M243495:
                                          idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
                                        }
                                      }
                                      else
                                      {
                                        idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v154.pitch, expectCommas: false);
                                      }
                                    }
                                    else
                                    {
                                      idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v153.pitch, expectCommas: false);
                                    }
                                  }
                                  else
                                  {
                                    idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v155.pitch, expectCommas: false);
                                  }
                                }
                                else
                                {
                                  idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v162.pitch, expectCommas: false);
                                  idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v163.pitch, expectCommas: false);
                                }
                              }
                              else
                              {
                                idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v160.pitch, expectCommas: false);
                                idLexer::Parse1DMatrix(this: &v126, x: 3, m: &v161.pitch, expectCommas: false);
                              }
                            }
                            else
                            {
                              nextOnHashChain = (idResource *)idLexer::ParseInt(this: &v126);
                            }
                          }
                          else
                          {
                            v4 = idLexer::ParseInt(this: &v126);
                            v105 = v4;
                          }
                        }
                        else
                        {
                          v125 = idLexer::ParseInt(this: &v126);
                        }
                      }
                      else
                      {
                        v110 = idLexer::ParseInt(this: &v126);
                      }
                    }
                    else
                    {
                      v122 = idLexer::ParseInt(this: &v126);
                    }
                  }
                  else
                  {
                    idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
                    idStr::operator=(this: &v130, text: (const idStr *)&v111.networkID);
                  }
                }
                else
                {
                  idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
                  idStr::IReplace(this: (idStr *)&v111.networkID, old: ".md6skel", nw: ".md6mask");
                  idStr::operator=(this: &v149, text: (const idStr *)&v111.networkID);
                }
              }
              else
              {
                idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
                idStr::IReplace(this: (idStr *)&v111.networkID, old: ".md6skel", nw: ".md6mask");
                idStr::operator=(this: &v151, text: (const idStr *)&v111.networkID);
              }
            }
            else
            {
              idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
              idStr::IReplace(this: (idStr *)&v111.networkID, old: ".md6skel", nw: ".md6mask");
              idStr::operator=(this: &v148, text: (const idStr *)&v111.networkID);
            }
          }
          else
          {
            idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
            idStr::operator=(this: &v150, text: (const idStr *)&v111.networkID);
          }
        }
        else
        {
          idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
          idStr::operator=(this: &v152, text: (const idStr *)&v111.networkID);
        }
      }
      else
      {
        idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
        networkID = v111.networkID;
        idStr::EnsureAlloced(this: &v129, amount: v111.networkID + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v129.data, Src: (const void *)v111.staleCount, Size: networkID);
        v129.data[networkID] = 0;
        v129.len = networkID;
        v4 = v105;
      }
    }
    else
    {
      idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
      idStr::idStr(this: &v159, text: (const idStr *)&v111.networkID);
      idStr::IReplace(this: &v159, old: "-skel", nw: "-mask");
      idStr::IReplace(this: &v159, old: ".md6skel", nw: ".md6mask");
      len = v159.len;
      idStr::EnsureAlloced(this: &v128, amount: v159.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v128.data, Src: v159.data, Size: len);
      v128.data[len] = 0;
      v128.len = len;
      idStr::FreeData(this: &v159);
      v4 = v105;
    }
  }
  v127.len = 0;
  v127.data = v127.baseBuffer;
  v127.allocedAndFlag = 20;
  v127.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: "flags") )
    idLexer::ParseBracedSectionExact(this: &v126, out: &v127, parseFirstBrace: true, intro: 123, outro: 125);
  *(_WORD *)&v108.memTag = 1280;
  memset(&v108, 0, 14);
  if ( v4 <= 0 || idList<unsigned char,25>::Resize(this: &v108, newsize: v4) )
  {
    v108.num = v4;
    if ( v4 >= v108.size )
      v108.num = v108.size;
  }
  listStatic = 0;
  list = nullptr;
  size = 0;
  *(_WORD *)&v107.memTag = 1280;
  memset(&v107, 0, 14);
  if ( v4 <= 0 )
  {
LABEL_67:
    v107.num = v4;
    if ( v4 >= size )
      v107.num = size;
  }
  else
  {
    v10 = idList<unsigned short,30>::Resize(this: &v107, newsize: v4);
    listStatic = v107.listStatic;
    list = v107.list;
    if ( v10 != 0 )
    {
      size = v107.size;
      goto LABEL_67;
    }
  }
  v11 = 0;
  v12 = nullptr;
  v13 = 0;
  *(_WORD *)&v120.memTag = 1280;
  memset(&v120, 0, 14);
  if ( v4 <= 0
    || (v14 = idList<idStr,3>::Resize(this: &v120, newsize: v4),
        v11 = v120.listStatic,
        v13 = v120.size,
        v12 = v120.list,
        v14) )
  {
    v120.num = v4;
    if ( v4 >= v13 )
      v120.num = v13;
  }
  if ( idLexer::CheckTokenString(this: &v126, string: "joints") )
  {
    idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 46, token: (idToken *)&v111.networkID);
    v15 = v132;
    v16 = 0;
    v17 = v105;
    while ( v16 < v17 )
    {
      idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
      idStr::operator=(this: &v12[v16], text: (const char *)v111.staleCount);
      v18 = idLexer::ParseInt(this: &v126);
      v19 = idLexer::ParseInt(this: &v126);
      if ( v15 == 6 )
      {
        idLexer::Parse1DMatrix(this: &v126, x: 4, m: (float *)&v119, expectCommas: false);
        idLexer::Parse1DMatrix(this: &v126, x: 3, m: (float *)&v119, expectCommas: false);
        idLexer::Parse1DMatrix(this: &v126, x: 3, m: (float *)&v119, expectCommas: false);
      }
      else
      {
        idLexer::SkipRestOfLine(this: &v126);
      }
      v20 = v108.list;
      list[v16] = v18;
      v20[v16++] = v19 != 0;
    }
    idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 47, token: (idToken *)&v111.networkID);
    v4 = v105;
  }
  resourceError = 0;
  str = nullptr;
  resourceListPtr = nullptr;
  v111.resourceError = (const char *)1280;
  memset(&v111.name, 0, 12);
  if ( (int)nextOnHashChain <= 0
    || (v24 = idList<idStr,3>::Resize(this: (idList<idStr,5> *)&v111.name, newsize: (int)nextOnHashChain),
        resourceError = (char)v111.resourceError,
        resourceListPtr = (idResource *)v111.resourceListPtr,
        str = (char *)v111.name.str,
        v24) )
  {
    v111.nextOnHashChain = nextOnHashChain;
    if ( (int)nextOnHashChain >= (int)resourceListPtr )
      v111.nextOnHashChain = resourceListPtr;
  }
  if ( idLexer::CheckTokenString(this: &v126, string: "userChannels") )
  {
    idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 46, token: (idToken *)&v111.networkID);
    for ( i = nullptr; (int)i < (int)nextOnHashChain; i = (idResource *)((char *)i + 1) )
    {
      idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID);
      idStr::operator=(this: (idStr *)&str[32 * (_DWORD)i], text: (const char *)v111.staleCount);
    }
    idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 47, token: (idToken *)&v111.networkID);
    v4 = v105;
  }
  v140.allocedAndFlag = 20;
  v140.len = 0;
  v140.data = v140.baseBuffer;
  v140.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: (const char *)v111.__vftable) )
    idLexer::ParseBracedSectionExact(this: &v126, out: &v140, parseFirstBrace: true, intro: 123, outro: 125);
  v138.allocedAndFlag = 20;
  v138.len = 0;
  v138.data = v138.baseBuffer;
  v138.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: v123) )
    idLexer::ParseBracedSectionExact(this: &v126, out: &v138, parseFirstBrace: true, intro: 123, outro: 125);
  v133.allocedAndFlag = 20;
  v133.len = 0;
  v133.data = v133.baseBuffer;
  v133.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: v124) )
    idLexer::ParseBracedSectionExact(this: &v126, out: &v133, parseFirstBrace: true, intro: 123, outro: 125);
  v131.allocedAndFlag = 20;
  v131.len = 0;
  v131.data = v131.baseBuffer;
  v131.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: "frames") )
    idLexer::ParseBracedSectionExact(this: &v126, out: &v131, parseFirstBrace: true, intro: 123, outro: 125);
  v26 = 0;
  v27 = nullptr;
  v28 = 0;
  *(_WORD *)&v119.memTag = 1280;
  memset(&v119, 0, 14);
  v156.allocedAndFlag = 20;
  v156.data = v156.baseBuffer;
  v156.len = 0;
  v156.baseBuffer[0] = 0;
  if ( idLexer::CheckTokenString(this: &v126, string: "userChannels") )
  {
    v29 = v110;
    if ( v110 <= 0
      || (v30 = idList<idList<float,5>,5>::Resize(this: &v119, newsize: v110),
          v26 = v119.listStatic,
          v28 = v119.size,
          v27 = (char *)v119.list,
          v30 != 0) )
    {
      v119.num = v29;
      if ( v29 >= v28 )
        v119.num = v28;
    }
    idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 46, token: (idToken *)&v111.networkID);
    if ( idLexer::PeekTokenString(this: &v126, string: "frame") )
    {
      v35 = 0;
      while ( idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID) && (v112 != 5 || v113 != 47) )
      {
        idLexer::ParseInt(this: &v126);
        idLexer::ExpectTokenType(this: &v126, type: 5, subtype: 46, token: (idToken *)&v111.networkID);
        v36 = 0;
        v37 = (idList<float,13> *)&v27[16 * v35++];
        if ( (int)nextOnHashChain <= v37->size
          || (unsigned __int8)idList<float,116>::Resize(this: v37, newsize: (int)nextOnHashChain) != 0 )
        {
          v38 = (idResource *)v37->size;
          if ( (int)nextOnHashChain < (int)v38 )
            v38 = nextOnHashChain;
          v37->num = (int)v38;
        }
        while ( idLexer::ReadToken(this: &v126, token: (idToken *)&v111.networkID) && (v112 != 5 || v113 != 47) )
        {
          v39 = (idStr *)&str[32 * v36];
          if ( v39->len == 0 )
            idStr::operator=(this: v39, text: (const char *)v111.staleCount);
          v40 = v37->list;
          v40[v36++] = idLexer::ParseFloat(this: &v126, errorFlag: nullptr);
          idLexer::SkipRestOfLine(this: &v126);
        }
        idStr::Append(this: &v156, text: " )\n");
        v4 = v105;
      }
    }
    else
    {
      for ( j = 0; j < v29; ++j )
      {
        v32 = nextOnHashChain;
        v33 = &v27[16 * j];
        if ( (int)nextOnHashChain <= *((_DWORD *)v33 + 2)
          || (unsigned __int8)idList<float,116>::Resize(
                                this: (idList<float,13> *)&v27[16 * j],
                                newsize: (int)nextOnHashChain) != 0 )
        {
          v34 = *((idResource **)v33 + 2);
          if ( (int)nextOnHashChain < (int)v34 )
            v34 = nextOnHashChain;
          *((_DWORD *)v33 + 1) = v34;
        }
        if ( (int)v32 <= 0 )
          idLexer::SkipRestOfLine(this: &v126);
        else
          idLexer::Parse1DMatrix(this: &v126, x: (int)v32, m: *(float **)v33, expectCommas: false);
        v4 = v105;
        v29 = v110;
      }
    }
  }
  if ( v130.len == 0 )
  {
    v57 = idResourceList::Load(
            this: &idMD6Model::resourceList,
            name: v130.data,
            makeDefault: false,
            skipStaleCheck: false);
    if ( v57 != nullptr )
    {
      skeleton = *((const idMD6Skel **)&v57[5] + 8);
      if ( skeleton != nullptr )
      {
        idStr::operator=(this: &v147, text: skeleton->name.str);
        v43 = filename;
        goto _M243944_0;
      }
      idLexer::Error(this: &v126, str: "Invalid or missing skeleton for model '%s'", v57->name.str);
      idStr::FreeData(this: &v156);
      if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
        idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
      idStr::FreeData(this: &v131);
      idStr::FreeData(this: &v133);
      idStr::FreeData(this: &v138);
      idStr::FreeData(this: &v140);
      if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
      {
        for ( k = 0; k < (int)resourceListPtr; ++k )
          idStr::FreeData(this: (idStr *)&str[32 * k]);
        idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
      }
      if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
      {
        for ( m = 0; m < v13; ++m )
          idStr::FreeData(this: &v12[m]);
        idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      }
      if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
      {
        for ( n = 0; n < v107.size; ++n )
          ;
        idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
      }
      if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
      {
        for ( ii = 0; ii < v108.size; ++ii )
          ;
        idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
      }
    }
    else
    {
      idLexer::Error(this: &v126, str: "Failed to load model for animation '%s'", filename);
      idStr::FreeData(this: &v156);
      if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
        idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
      idStr::FreeData(this: &v131);
      idStr::FreeData(this: &v133);
      idStr::FreeData(this: &v138);
      idStr::FreeData(this: &v140);
      if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
      {
        for ( jj = 0; jj < (int)resourceListPtr; ++jj )
          idStr::FreeData(this: (idStr *)&str[32 * jj]);
        idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
      }
      if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
      {
        for ( kk = 0; kk < v13; ++kk )
          idStr::FreeData(this: &v12[kk]);
        idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      }
      if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
      {
        for ( mm = 0; mm < v107.size; ++mm )
          ;
        idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
      }
      if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
      {
        for ( nn = 0; nn < v108.size; ++nn )
          ;
        idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
      }
    }
_M244083:
    idStr::FreeData(this: &v127);
    idStr::FreeData(this: &v147);
    idStr::FreeData(this: &v149);
    idStr::FreeData(this: &v151);
    idStr::FreeData(this: &v148);
    idStr::FreeData(this: &v150);
    idStr::FreeData(this: &v152);
    idStr::FreeData(this: &v129);
    idStr::FreeData(this: &v128);
    idStr::FreeData(this: &v130);
    idStr::FreeData(this: (idStr *)&v111.networkID);
    idLexer::~idLexer(this: &v126);
    return 0;
  }
  idAnimator_TrackerBase::GetReferenceJointOverride(this: &v109);
  CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v109, data: v107.list, length: 2 * v4);
  v157.allocedAndFlag = 20;
  v157.len = 0;
  v157.data = v157.baseBuffer;
  v157.baseBuffer[0] = 0;
  if ( v130.len == 0 )
  {
    v43 = filename;
LABEL_147:
    _idMD6Anim::RewriteText_::_166_::helper_t::GetMeshPath(commandLine: &v128, meshPath: &v157);
    v44 = _idMD6Anim::RewriteText_::_166_::helper_t::LoadModel(
            meshPath: &v157,
            numJoints: v105,
            numPaddedUserChannels: v48,
            parentTblCrc: v47);
    HIWORD(v111.__vftable) = v109;
    if ( (unsigned __int8)_idMD6Anim::RewriteText_::_166_::helper_t::ValidateParenting(
                            filename: v43,
                            model: v44,
                            numJoints: v105,
                            animJointTable: &v120,
                            animParentTable: (const idList<short,5> *)&v107,
                            parentTblCrc: (const idHandle<unsigned short,enum invalidCrc_t,65535> *)(unsigned __int16)v109.value) != 0
      && v44 != nullptr )
    {
      goto LABEL_135;
    }
    idLexer::Error(this: &v126, str: "Failed to load model for animation '%s'", v43);
    idStr::FreeData(this: &v157);
    idStr::FreeData(this: &v156);
    if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
    idStr::FreeData(this: &v131);
    idStr::FreeData(this: &v133);
    idStr::FreeData(this: &v138);
    idStr::FreeData(this: &v140);
    if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
    {
      for ( i1 = 0; i1 < (int)resourceListPtr; ++i1 )
        idStr::FreeData(this: (idStr *)&str[32 * i1]);
      idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
    }
    if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
    {
      for ( i2 = 0; i2 < v13; ++i2 )
        idStr::FreeData(this: &v12[i2]);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
    {
      for ( i3 = 0; i3 < v107.size; ++i3 )
        ;
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    }
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
    {
      for ( i4 = 0; i4 < v108.size; ++i4 )
        ;
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    }
    idStr::FreeData(this: &v127);
    idStr::FreeData(this: &v147);
    idStr::FreeData(this: &v149);
    idStr::FreeData(this: &v151);
    idStr::FreeData(this: &v148);
    idStr::FreeData(this: &v150);
    idStr::FreeData(this: &v152);
    idStr::FreeData(this: &v129);
    idStr::FreeData(this: &v128);
    idStr::FreeData(this: &v130);
    idStr::FreeData(this: (idStr *)&v111.networkID);
    idLexer::~idLexer(this: &v126);
    return 0;
  }
  v43 = filename;
  v44 = _idMD6Anim::RewriteText_::_166_::helper_t::LoadModel(
          meshPath: &v130,
          numJoints: v4,
          numPaddedUserChannels: v42,
          parentTblCrc: v41);
  HIWORD(v111.__vftable) = v109;
  if ( (unsigned __int8)_idMD6Anim::RewriteText_::_166_::helper_t::ValidateParenting(
                          filename,
                          model: v44,
                          numJoints: v105,
                          animJointTable: &v120,
                          animParentTable: (const idList<short,5> *)&v107,
                          parentTblCrc: (const idHandle<unsigned short,enum invalidCrc_t,65535> *)(unsigned __int16)v109.value) == 0
    || v44 == nullptr )
  {
    goto LABEL_147;
  }
LABEL_135:
  skeleton = v44->skeleton;
  if ( skeleton == nullptr )
  {
    idLexer::Error(this: &v126, str: "Invalid or missing skeleton for model '%s'", v44->name.str);
    idStr::FreeData(this: &v157);
    idStr::FreeData(this: &v156);
    if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
    idStr::FreeData(this: &v131);
    idStr::FreeData(this: &v133);
    idStr::FreeData(this: &v138);
    idStr::FreeData(this: &v140);
    if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
    {
      for ( i5 = 0; i5 < (int)resourceListPtr; ++i5 )
        idStr::FreeData(this: (idStr *)&str[32 * i5]);
      idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
    }
    if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
    {
      for ( i6 = 0; i6 < v13; ++i6 )
        idStr::FreeData(this: &v12[i6]);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
    {
      for ( i7 = 0; i7 < v107.size; ++i7 )
        ;
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    }
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
    {
      for ( i8 = 0; i8 < v108.size; ++i8 )
        ;
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    }
    goto _M244083;
  }
  idStr::operator=(this: &v147, text: skeleton->name.str);
  idStr::FreeData(this: &v157);
  v4 = v105;
_M243944_0:
  if ( skeleton->data->numUserChannels < (int)nextOnHashChain )
  {
    idLexer::Error(this: &v126, str: "Animation '%s' has more userchannels than skeleton '%s'", v43, skeleton->name.str);
    idStr::FreeData(this: &v156);
    if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
    idStr::FreeData(this: &v131);
    idStr::FreeData(this: &v133);
    idStr::FreeData(this: &v138);
    idStr::FreeData(this: &v140);
    if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
    {
      for ( i9 = 0; i9 < (int)resourceListPtr; ++i9 )
        idStr::FreeData(this: (idStr *)&str[32 * i9]);
      idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
    }
    if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
    {
      for ( i10 = 0; i10 < v13; ++i10 )
        idStr::FreeData(this: &v12[i10]);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
    {
      for ( i11 = 0; i11 < v107.size; ++i11 )
        ;
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    }
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
    {
      for ( i12 = 0; i12 < v108.size; ++i12 )
        ;
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    }
    goto _M244083;
  }
  if ( idStr::Find(searchIn: v127.data, searchFor: "facetracksComposite", casesensitive: true, start: 0, end: v127.len) != -1 )
  {
    v70 = animation->GetNumUserChannels(this: animation);
    for ( i13 = 0; i13 < v70; ++i13 )
    {
      v121 = i13;
      v72 = animation->GetUserChannelName(this: animation, a2: &v121);
      idStr::idStr(this: &v158, text: v72);
      if ( idStr::Find(searchIn: v158.data, searchFor: "facedata_", casesensitive: true, start: 0, end: v158.len) != -1
        && (unsigned __int16)idMD6Skel::GetUserChannelIndex(
                               this: &v111,
                               result: (idIndex<short,enum invalidUserChannelIndex_t> *)skeleton,
                               name: v158.data)->value != 0xFFFF )
      {
        idList<idStr,5>::Append(this: (idList<idStr,5> *)&v111.name, obj: &v158);
        resourceError = (char)v111.resourceError;
        resourceListPtr = (idResource *)v111.resourceListPtr;
        str = (char *)v111.name.str;
      }
      idStr::FreeData(this: &v158);
    }
    v4 = v105;
    nextOnHashChain = v111.nextOnHashChain;
  }
  v73 = fileSystem->OpenFileWrite(this: fileSystem, a2: v43, a3: 0);
  v104.file = v73;
  if ( v73 == nullptr )
  {
    idLib::Warning(fmt: "Failed to open file '%s'", v43);
    idFileLocal::~idFileLocal(this: &v104);
    idStr::FreeData(this: &v156);
    if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
    idStr::FreeData(this: &v131);
    idStr::FreeData(this: &v133);
    idStr::FreeData(this: &v138);
    idStr::FreeData(this: &v140);
    if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
    {
      for ( i14 = 0; i14 < (int)resourceListPtr; ++i14 )
        idStr::FreeData(this: (idStr *)&str[32 * i14]);
      idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
    }
    if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
    {
      for ( i15 = 0; i15 < v13; ++i15 )
        idStr::FreeData(this: &v12[i15]);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    if ( (listStatic == 0 || listStatic == 2) && v107.list != nullptr )
    {
      for ( i16 = 0; i16 < v107.size; ++i16 )
        ;
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    }
    if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
    {
      for ( i17 = 0; i17 < v108.size; ++i17 )
        ;
      idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
    }
    goto _M244083;
  }
  v73->Printf(this: v73, a2: "%s %d\n", MD6_VERSION_STRING, 7);
  v104.file->Printf(this: v104.file, a2: "init {\n");
  v104.file->Printf(this: v104.file, a2: "\tcommandLine \"%s\"\n", v128.data);
  v104.file->Printf(this: v104.file, a2: "\tsourceAnim \"%s\"\n", v129.data);
  v104.file->Printf(this: v104.file, a2: "\tsourceTake \"%s\"\n", v152.data);
  v104.file->Printf(this: v104.file, a2: "\tsubtractiveAnim \"%s\"\n", v150.data);
  v104.file->Printf(this: v104.file, a2: "\trotationMask \"%s\"\n", v148.data);
  v104.file->Printf(this: v104.file, a2: "\tscaleMask \"%s\"\n", v151.data);
  v104.file->Printf(this: v104.file, a2: "\ttranslationMask \"%s\"\n", v149.data);
  v104.file->Printf(this: v104.file, a2: "\tskeletonName \"%s\"\n", v147.data);
  v104.file->Printf(this: v104.file, a2: "\tstartFrame %d\n", v122);
  v104.file->Printf(this: v104.file, a2: "\tnumFrames %d\n", v110);
  v104.file->Printf(this: v104.file, a2: "\tframeRate %d\n", v125);
  v104.file->Printf(this: v104.file, a2: "\tnumJoints %d\n", v4);
  v104.file->Printf(this: v104.file, a2: "\tnumUserChannels %d\n", nextOnHashChain);
  v78 = idVec3::ToString(this: &v161, precision: 2);
  v79 = idVec3::ToString(this: &v160, precision: 2);
  v104.file->Printf(this: v104.file, a2: "\ttranslatedBounds ( %s ) ( %s )\n", v79, v78);
  v80 = idVec3::ToString(this: &v163, precision: 2);
  v81 = idVec3::ToString(this: &v162, precision: 2);
  v104.file->Printf(this: v104.file, a2: "\tnormalizedBounds ( %s ) ( %s )\n", v81, v80);
  v82 = idVec3::ToString(this: &v155, precision: 2);
  v104.file->Printf(this: v104.file, a2: "\tworldPos ( %s )\n", v82);
  v83 = idVec3::ToString(this: &v153, precision: 2);
  v104.file->Printf(this: v104.file, a2: "\tworldRot ( %s )\n", v83);
  v84 = idVec3::ToString(this: &v154, precision: 2);
  v104.file->Printf(this: v104.file, a2: "\tworldScale ( %s )\n", v84);
  v104.file->Printf(this: v104.file, a2: "\terrorTolerance %f\n", LODWORD(v3), v3);
  v104.file->Printf(this: v104.file, a2: "}\n");
  if ( v127.len != 0 )
  {
    v104.file->Printf(this: v104.file, a2: "flags ");
    v104.file->Write(this: v104.file, a2: v127.data, a3: v127.len);
    v104.file->Printf(this: v104.file, a2: "\n");
  }
  if ( v120.num > 0 )
  {
    v104.file->Printf(this: v104.file, a2: "joints {\n");
    v85 = v107.list;
    v86 = 0;
    v87 = v108.list;
    while ( v86 < v105 )
    {
      v104.file->Printf(this: v104.file, a2: "\t\"%s\" %d %d\n", v12[v86].data, (__int16)v85[v86], v87[v86] != 0);
      ++v86;
    }
    v104.file->Printf(this: v104.file, a2: "}\n");
  }
  if ( (int)v111.nextOnHashChain <= 0 )
  {
    v88 = nextOnHashChain;
  }
  else
  {
    v104.file->Printf(this: v104.file, a2: "userChannels {\n");
    v88 = nextOnHashChain;
    for ( i18 = nullptr; (int)i18 < (int)nextOnHashChain; i18 = (idResource *)((char *)i18 + 1) )
      v104.file->Printf(this: v104.file, a2: "\t\"%s\"// index %d\n", *(_DWORD *)&str[32 * (_DWORD)i18 + 4], i18);
    v104.file->Printf(this: v104.file, a2: "}\n");
  }
  if ( v140.len != 0 )
  {
    v104.file->Printf(this: v104.file, a2: "rotationMask ");
    v104.file->Write(this: v104.file, a2: v140.data, a3: v140.len);
    v104.file->Printf(this: v104.file, a2: "\n");
  }
  if ( v138.len != 0 )
  {
    v104.file->Printf(this: v104.file, a2: "scaleMask ");
    v104.file->Write(this: v104.file, a2: v138.data, a3: v138.len);
    v104.file->Printf(this: v104.file, a2: "\n");
  }
  if ( v133.len != 0 )
  {
    v104.file->Printf(this: v104.file, a2: "translationMask ");
    v104.file->Write(this: v104.file, a2: v133.data, a3: v133.len);
    v104.file->Printf(this: v104.file, a2: "\n");
  }
  if ( v131.len != 0 )
  {
    v104.file->Printf(this: v104.file, a2: "frames ");
    v104.file->Write(this: v104.file, a2: v131.data, a3: v131.len);
    v104.file->Printf(this: v104.file, a2: "\n");
  }
  if ( v119.num > 0 )
  {
    v104.file->Printf(this: v104.file, a2: "userChannels {\n");
    v104.file->Printf(this: v104.file, a2: "//\t  ");
    for ( i19 = 0; ; ++i19 )
    {
      Printf = (void (*)(void))v104.file->Printf;
      if ( i19 >= (int)v88 )
        break;
      Printf();
    }
    Printf();
    v92 = v110;
    for ( i20 = 0; ; ++i20 )
    {
      v94 = (void (*)(void))v104.file->Printf;
      if ( i20 >= v92 )
        break;
      v94();
      for ( i21 = 0; i21 < (int)v88; ++i21 )
      {
        v103 = *(float *)(*(_DWORD *)&v27[16 * i20] + 4 * i21);
        v104.file->Printf(this: v104.file, a2: (const char *)HIDWORD(v103), LODWORD(v103));
      }
      v104.file->Printf(this: v104.file, a2: ")\n");
    }
    v94();
  }
  file = v104.file;
  v97 = v126.end_p - v126.script_p;
  ScriptP = idLexer::GetScriptP(this: (idCollisionModelLocal *)&v126);
  file->Write(this: file, a2: (const void *)ScriptP, a3: v97);
  idFileLocal::~idFileLocal(this: &v104);
  idStr::FreeData(this: &v156);
  if ( (v26 == 0 || v26 == 2) && v27 != nullptr )
    idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v27, num: v28);
  idStr::FreeData(this: &v131);
  idStr::FreeData(this: &v133);
  idStr::FreeData(this: &v138);
  idStr::FreeData(this: &v140);
  if ( (resourceError == 0 || resourceError == 2) && str != nullptr )
  {
    for ( i22 = 0; i22 < (int)resourceListPtr; ++i22 )
      idStr::FreeData(this: (idStr *)&str[32 * i22]);
    idMem::Free(this: &mem, ptr: str, align: ALIGN_16);
  }
  if ( (v11 == 0 || v11 == 2) && v12 != nullptr )
  {
    for ( i23 = 0; i23 < v13; ++i23 )
      idStr::FreeData(this: &v12[i23]);
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  }
  if ( (v107.listStatic == 0 || v107.listStatic == 2) && v107.list != nullptr )
  {
    for ( i24 = 0; i24 < v107.size; ++i24 )
      ;
    idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
  }
  if ( (v108.listStatic == 0 || v108.listStatic == 2) && v108.list != nullptr )
  {
    for ( i25 = 0; i25 < v108.size; ++i25 )
      ;
    idMem::Free(this: &mem, ptr: v108.list, align: ALIGN_16);
  }
  idStr::FreeData(this: &v127);
  idStr::FreeData(this: &v147);
  idStr::FreeData(this: &v149);
  idStr::FreeData(this: &v151);
  idStr::FreeData(this: &v148);
  idStr::FreeData(this: &v150);
  idStr::FreeData(this: &v152);
  idStr::FreeData(this: &v129);
  idStr::FreeData(this: &v128);
  idStr::FreeData(this: &v130);
  idStr::FreeData(this: (idStr *)&v111.networkID);
  idLexer::~idLexer(this: &v126);
  return 1;
}


// ========================================================================
// $M244329
// EA  : 0x8282FE6C
// RVA : 0x0082FE6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void *_M244329()
{
  idLib::Warning(fmt: "Error writing .md6anim file");
  return &_M244318;
}


// ========================================================================
// __unwind$239685
// EA  : 0x8282FE9C
// RVA : 0x0082FE9C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239685()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 1376 + 304));
}


// ========================================================================
// __unwind$239686
// EA  : 0x8282FEC4
// RVA : 0x0082FEC4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 160));
}


// ========================================================================
// __unwind$239687
// EA  : 0x8282FEEC
// RVA : 0x0082FEEC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239687()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 544));
}


// ========================================================================
// __unwind$239688
// EA  : 0x8282FF14
// RVA : 0x0082FF14
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239688()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 480));
}


// ========================================================================
// __unwind$239689
// EA  : 0x8282FF3C
// RVA : 0x0082FF3C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239689()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 512));
}


// ========================================================================
// __unwind$239690
// EA  : 0x8282FF64
// RVA : 0x0082FF64
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239690()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 944));
}


// ========================================================================
// __unwind$239691
// EA  : 0x8282FF8C
// RVA : 0x0082FF8C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239691()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 880));
}


// ========================================================================
// __unwind$239692
// EA  : 0x8282FFB4
// RVA : 0x0082FFB4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239692()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 816));
}


// ========================================================================
// __unwind$239693
// EA  : 0x8282FFDC
// RVA : 0x0082FFDC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239693()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 912));
}


// ========================================================================
// __unwind$239694
// EA  : 0x82830004
// RVA : 0x00830004
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239694()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 848));
}


// ========================================================================
// __unwind$239695
// EA  : 0x8283002C
// RVA : 0x0083002C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239695()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 784));
}


// ========================================================================
// __unwind$239696
// EA  : 0x82830054
// RVA : 0x00830054
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 1120));
}


// ========================================================================
// __unwind$239697
// EA  : 0x8283007C
// RVA : 0x0083007C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239697()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 448));
}


// ========================================================================
// __unwind$239698
// EA  : 0x828300A4
// RVA : 0x008300A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239698()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1376 + 112));
}


// ========================================================================
// __unwind$239699
// EA  : 0x828300CC
// RVA : 0x008300CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239699()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1376 + 96));
}


// ========================================================================
// __unwind$239700
// EA  : 0x828300F4
// RVA : 0x008300F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239700()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1376 + 256));
}


// ========================================================================
// __unwind$239701
// EA  : 0x8283011C
// RVA : 0x0083011C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239701()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1376 + 144));
}


// ========================================================================
// __unwind$239702
// EA  : 0x82830144
// RVA : 0x00830144
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239702()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 720));
}


// ========================================================================
// __unwind$239703
// EA  : 0x8283016C
// RVA : 0x0083016C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239703()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 672));
}


// ========================================================================
// __unwind$239704
// EA  : 0x82830194
// RVA : 0x00830194
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239704()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 624));
}


// ========================================================================
// __unwind$239705
// EA  : 0x828301BC
// RVA : 0x008301BC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239705()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 576));
}


// ========================================================================
// __unwind$239706
// EA  : 0x828301E4
// RVA : 0x008301E4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239706()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 1376 + 240));
}


// ========================================================================
// __unwind$239707
// EA  : 0x8283020C
// RVA : 0x0083020C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239707()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 1024));
}


// ========================================================================
// __unwind$239708
// EA  : 0x82830234
// RVA : 0x00830234
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239708()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 1056));
}


// ========================================================================
// __unwind$239709
// EA  : 0x8283025C
// RVA : 0x0083025C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1376 + 1088));
}


// ========================================================================
// __unwind$239710
// EA  : 0x82830284
// RVA : 0x00830284
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_239710()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 1376 + 80));
}


// ========================================================================
// ?CompressAnim@idMD6Anim@@AAAXPBVidMD6Skel@@ABV?$idList@PBVidMD6Skel@@$04@@ABV?$idList@M$04@@222ABV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@33ABV?$idList@V?$idIndex@FW4invalidUserChannelIndex_t@@@@$04@@2HHHABUanimationSettings_t@1@@Z
// EA  : 0x828302B8
// RVA : 0x008302B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMD6Anim::CompressAnim(
        idMD6Anim *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *skel,
        const idList<idMD6Skel const *,5> *mappedSkeletons,
        const idList<float,5> *rotation,
        const idList<float,5> *scale,
        const idList<float,5> *translation,
        const idList<float,5> *userChannels,
        const idList<idIndex<short,enum invalidJointIndex_t>,5> *maskRJoints,
        const idList<idIndex<short,enum invalidJointIndex_t>,5> *maskSJoints,
        const idList<idIndex<short,enum invalidJointIndex_t>,5> *maskTJoints,
        const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *maskUChannels,
        const idList<float,5> *jointWeights,
        const int flags,
        const int numFrames,
        const int frameRate,
        const idMD6Anim::animationSettings_t *animSettings,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28,
        int a29,
        _DWORD *a30,
        int a31,
        _DWORD *a32,
        int a33,
        int a34,
        int a35,
        __int16 maskSJoints_2,
        int a37,
        int maskTJointsa,
        int a39,
        __int16 maskUChannels_2,
        int a41,
        const idList<float,5> *jointWeightsa)
{
  double valueFloat; // fp31
  int v46; // r20
  int num; // r11
  int v48; // r10
  int v49; // r11
  int v50; // r29
  int v51; // r29
  const __int16 *v52; // r29
  idVehicleState **list; // r15
  idVehicleState **v54; // r16
  idVehicleState **v55; // r25
  int v56; // r8
  int v57; // r8
  int v58; // r2 OVERLAPPED
  int i; // r30
  __int128 v60; // r10
  __int128 v61; // r6
  __int16 v62; // r10
  double v63; // fp5
  double v64; // fp7
  double v65; // fp6
  double v66; // fp5
  double v67; // fp1
  double v68; // fp28
  double v69; // fp30
  double v70; // fp29
  int size; // r11
  int v72; // r30
  int v73; // r11
  int v74; // ctr
  unsigned int v75; // r27
  int v76; // r26
  int v77; // r7
  int v78; // r19
  bool *v79; // r6
  int v80; // r17
  bool *v81; // r5
  int v82; // r20
  int v83; // r23
  int v84; // r18
  int v85; // r24
  int v86; // r29
  int v89; // r30
  bool v90; // r3
  int v91; // r8
  int v92; // r11
  float *v93; // r9
  double v94; // fp4
  double v95; // fp3
  double v96; // fp2
  bool v97; // r3
  int v98; // r8
  int v99; // r11
  float *v100; // r9
  double v101; // fp9
  double v102; // fp7
  double v103; // fp5
  bool v104; // r3
  int v105; // r5
  bool *v106; // r17
  bool *v107; // r22
  bool *v108; // r21
  unsigned int v109; // r26
  bool *v110; // r6
  int v111; // r18
  float *v112; // r28
  float *v113; // r27
  bool *v114; // r15
  int v115; // r19
  int v116; // r20
  int v117; // r23
  int v118; // r24
  unsigned int v119; // r30
  int v120; // r29
  float *v123; // r3
  bool IsRWithinTolerance; // r3
  bool v139; // r11
  float *v140; // r11
  double v141; // fp11
  double v142; // fp10
  double v143; // fp9
  bool v148; // r11
  double v149; // fp2
  double v150; // fp1
  double v151; // fp0
  int v152; // r8
  float *v153; // r11
  double v154; // fp11
  double v155; // fp10
  double v156; // fp9
  bool v161; // r11
  double v162; // fp0
  bool v163; // r11
  int v164; // r8
  int v165; // r7
  int v166; // r9
  int value; // r4
  int v168; // r11
  int v169; // r10
  BOOL v170; // r4
  BOOL v171; // r4
  int v172; // r7
  int v173; // r6
  int v174; // r9
  int v175; // r5
  int v176; // r4
  int v177; // r11
  int v178; // r10
  BOOL v179; // r4
  BOOL v180; // r4
  int v181; // r7
  int v182; // r6
  int v183; // r9
  int v184; // r5
  int v185; // r4
  int v186; // r11
  int v187; // r10
  BOOL v188; // r4
  int v189; // r15
  unsigned int v190; // r27
  int v191; // r30
  int v192; // r24
  __int16 *v193; // r4
  float *v194; // r26
  float *v195; // r25
  unsigned int v196; // r29
  int v197; // r28
  int v198; // r4
  float *v199; // r11
  float *v200; // r11
  int v201; // r14
  int v202; // r7
  bool *v203; // r21
  int v204; // r17
  int v205; // r6
  int v206; // r5
  int v207; // r9
  int v208; // r11
  bool *v209; // r28
  int v210; // r24
  char *v211; // r26
  unsigned int v212; // r5
  int v213; // r29
  unsigned int v214; // r7
  int v215; // r4
  float *v216; // r6
  int v217; // r3
  int v218; // r9
  double v219; // fp0
  unsigned int v220; // r9
  int v221; // r8
  double v222; // fp0
  int v223; // r9
  double v224; // fp0
  unsigned int v225; // r10
  int v226; // r11
  double v227; // fp0
  unsigned int v228; // r8
  unsigned int v229; // ctr
  int v230; // r9
  double v231; // fp0
  int v232; // r7
  int v233; // r9
  int v234; // r6
  int v235; // r11
  int v236; // r10
  BOOL v237; // r4
  BOOL v238; // r6
  float *v239; // r4
  int v240; // r8
  int v241; // r10
  unsigned int v242; // r6
  int v243; // r9
  float *v244; // r11
  unsigned int v245; // r7
  int v246; // r11
  float *v247; // r9
  int v248; // ctr
  int v249; // r28
  bool *v250; // r26
  unsigned int v251; // r11
  idMD6Anim::CompressAnim::__l2::local_t::channel_t v252; // r10
  int v253; // r29
  int v254; // r6
  int v255; // r30
  int v256; // r7
  int v257; // r28
  bool *v258; // r26
  unsigned int v259; // r11
  idMD6Anim::CompressAnim::__l2::local_t::channel_t v260; // r10
  int v261; // r29
  int v262; // r6
  int v263; // r30
  int v264; // r7
  int v265; // r28
  bool *v266; // r26
  unsigned int v267; // r11
  idMD6Anim::CompressAnim::__l2::local_t::channel_t v268; // r10
  int v269; // r29
  int v270; // r6
  int v271; // r30
  int v272; // r7
  int v273; // r28
  unsigned int v274; // r11
  idMD6Anim::CompressAnim::__l2::local_t::channel_t v275; // r10
  int v276; // r29
  int v277; // r6
  int v278; // r30
  int v279; // r7
  int v280; // r26
  int v281; // r27
  int v282; // r22
  int v283; // r29
  int v284; // r23
  int v285; // r28
  int v286; // r30
  unsigned int v287; // r5
  int v288; // r11
  bool *v289; // r18
  char *v290; // r21
  char *v291; // r28
  int v292; // r20
  int v293; // r29
  _WORD *v294; // r3
  _WORD *v295; // r30
  __int64 v296; // r9
  _QWORD *v297; // r10
  int j; // ctr
  char *v299; // r28
  int v300; // r27
  char *v301; // r25
  char *v302; // r24
  int v303; // r11
  unsigned int v304; // r6
  unsigned int v305; // r10
  unsigned int v306; // r5
  unsigned int v307; // r16
  unsigned int v308; // r9
  unsigned int v309; // r8
  unsigned int v310; // r7
  unsigned int v311; // r11
  unsigned int v312; // r10
  unsigned int v313; // r11
  int v314; // r3
  unsigned int v315; // r11
  char *v316; // r25
  char *v317; // r26
  char *v318; // r24
  int v319; // r9
  unsigned int v320; // r4
  int v321; // r14
  int v322; // r8
  int v323; // r29
  bool *v324; // r27
  __int16 *v325; // r4
  unsigned int v326; // r11
  int v327; // r4
  int v328; // r10
  bool *v329; // r29
  int v330; // r9
  float *v331; // r11
  unsigned int v332; // r8
  float *v333; // r8
  float *v334; // r8
  float *v335; // r8
  float *v336; // r8
  float *v337; // r9
  int v338; // ctr
  float *v339; // r11
  int v340; // r10
  bool *v341; // r29
  int v342; // r9
  float *v343; // r11
  unsigned int v344; // r8
  float *v345; // r8
  float *v346; // r8
  float *v347; // r8
  float *v348; // r8
  float *v349; // r9
  int v350; // ctr
  float *v351; // r11
  int v352; // r4
  int v353; // r10
  bool *v354; // r29
  int v355; // r9
  int v356; // r5
  float *v357; // r11
  unsigned int v358; // r8
  float *v359; // r8
  int v360; // ctr
  unsigned int v361; // r24
  int v362; // r18
  int v363; // r22
  int v364; // r23
  unsigned int v365; // r3
  unsigned int v366; // r16
  unsigned int k; // r17
  unsigned int v368; // r21
  int v369; // r19
  int v370; // r27
  signed int v371; // r29
  unsigned int v372; // r26
  __int16 *v373; // r4
  int v374; // r28
  int v375; // r4
  int v376; // r6
  signed int v377; // r7
  char *v378; // r29
  unsigned int v379; // r5
  float *v380; // r10
  int v381; // r8
  float *v382; // r11
  int v383; // r6
  signed int v384; // r7
  char *v385; // r29
  unsigned int v386; // r5
  float *v387; // r10
  int v388; // r8
  float *v389; // r11
  int v390; // r29
  int v391; // r4
  unsigned int v392; // r10
  bool *v393; // r7
  unsigned int v394; // r11
  int v395; // r8
  signed int v396; // r10
  int v397; // r27
  char *v398; // r28
  float *v399; // r6
  int v400; // r5
  int v401; // r9
  int v402; // r10
  __int16 v403; // r8
  int m; // ctr
  char *v405; // r11
  unsigned __int8 *p_memTag; // r11
  int v407; // ctr
  int v408; // r11
  int v409; // r29
  idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *v410; // r28
  int v411; // r27
  int v412; // r25
  int v413; // r24
  int v414; // r23
  int v415; // r22
  int v416; // r21
  unsigned __int16 v417; // r26
  int v418; // r30
  char v419; // r3
  idList<unsigned char,37> *v420; // r29
  unsigned __int8 v421; // r18
  unsigned __int8 v422; // r17
  unsigned __int8 v423; // r16
  int granularity; // r27
  unsigned __int8 v425; // r15
  unsigned __int8 v426; // r14
  int v427; // r30
  int *v428; // r11
  idList<unsigned char,37> *v429; // r25
  int v430; // r8
  __int16 v431; // r26
  idList<unsigned char,37> *v432; // r24
  int v433; // r9
  int v434; // r8
  int v435; // r26
  int v436; // r9
  int v437; // r8
  idList<unsigned char,37> *v438; // r23
  int v439; // r9
  int v440; // r26
  idList<unsigned char,37> *v441; // r22
  int v442; // r9
  int v443; // r8
  __int16 JointRLE; // r3
  idList<unsigned char,37> *v445; // r21
  int v446; // r26
  int v447; // r9
  unsigned __int16 v448; // r3
  int v449; // r9
  idList<unsigned char,37> *v450; // r20
  int v451; // r26
  idList<unsigned char,37> *v452; // r19
  int v453; // r9
  int v454; // r23
  int v455; // r25
  __int16 v456; // r10
  int v457; // r8
  float *v458; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double w; // fp11
  float *v463; // r11
  double v464; // fp9
  double v465; // fp8
  double v466; // fp7
  double v467; // fp6
  float *v468; // r6
  double v469; // fp5
  double v470; // fp4
  double v471; // fp3
  double v472; // fp2
  double v473; // fp1
  double v474; // fp31
  double v475; // fp30
  double v476; // fp29
  double v477; // fp28
  double v478; // fp27
  double v479; // fp25
  __int16 v480; // r29
  __int16 v481; // r26
  __int16 v482; // r8
  int v483; // r10
  int v484; // r9
  __int16 v485; // r24
  idVehicleState **v486; // r7
  int v487; // r10
  unsigned __int16 v488; // r11
  int v489; // r9
  char v490; // r11
  int v491; // r10
  int v492; // r11
  int v493; // r10
  bool v494; // zf
  int v495; // ctr
  __int16 v496; // r11
  unsigned int v497; // r5
  idVehicleState **v498; // r11
  int v499; // ctr
  int v500; // r9
  int len_high; // r10
  idMD6AnimData *v502; // r3
  _QWORD *v503; // r11
  _QWORD *v504; // r10
  int n; // ctr
  int v506; // r29
  int *p_num; // r30
  int v508; // r26
  int v509; // r25
  int v510; // r24
  int v511; // r23
  char *v512; // r27
  int v513; // r22
  int v514; // r21
  int v515; // r20
  char *v516; // r19
  char *v517; // r18
  char *v518; // r17
  char *v519; // r16
  char *v520; // r15
  char *v521; // r14
  idMD6Anim *v522; // r28
  idMD6AnimData *animData; // r11
  int v524; // r16
  idVehicleState **v525; // r18
  _WORD *v526; // r29
  int v527; // r27
  int ii; // r17
  idMD6AnimData *v529; // r11
  unsigned __int16 *v530; // r4
  size_t v531; // r5
  int v532; // r10
  _WORD *v533; // r30
  __int16 v534; // r8
  __int16 v535; // r10
  __int16 v536; // r9
  __int16 v537; // r10
  __int16 v538; // r9
  __int16 v539; // r8
  idMD6AnimData *v540; // r8
  int v541; // r5
  int v542; // r11
  unsigned int v543; // r10
  const char *str; // r4
  idMD6AnimData *v545; // r9
  int v546; // r8
  unsigned int totalSize; // r7
  idMem *v548; // r28
  void **v549; // r29
  int jj; // r30
  idList<char,5> *v551; // [sp+8h] [-35C8h]
  int v552; // [sp+8h] [-35C8h]
  int v553; // [sp+8h] [-35C8h]
  int v554; // [sp+8h] [-35C8h]
  int v555; // [sp+8h] [-35C8h]
  int v556; // [sp+8h] [-35C8h]
  int v557; // [sp+8h] [-35C8h]
  int v558; // [sp+8h] [-35C8h]
  const idList<unsigned char,5> *v559; // [sp+8h] [-35C8h]
  const idList<char,5> *v560; // [sp+Ch] [-35C4h]
  int v561; // [sp+Ch] [-35C4h]
  int v562; // [sp+Ch] [-35C4h]
  int v563; // [sp+Ch] [-35C4h]
  int v564; // [sp+Ch] [-35C4h]
  int v565; // [sp+Ch] [-35C4h]
  int v566; // [sp+Ch] [-35C4h]
  int v567; // [sp+Ch] [-35C4h]
  const idList<unsigned char,5> *v568; // [sp+Ch] [-35C4h]
  const idList<char,5> *v569; // [sp+10h] [-35C0h]
  int v570; // [sp+10h] [-35C0h]
  int v571; // [sp+10h] [-35C0h]
  int v572; // [sp+10h] [-35C0h]
  int v573; // [sp+10h] [-35C0h]
  int v574; // [sp+10h] [-35C0h]
  int v575; // [sp+10h] [-35C0h]
  int v576; // [sp+10h] [-35C0h]
  int v577; // [sp+10h] [-35C0h]
  const idList<char,5> *v578; // [sp+14h] [-35BCh]
  int v579; // [sp+14h] [-35BCh]
  int v580; // [sp+14h] [-35BCh]
  int v581; // [sp+14h] [-35BCh]
  int v582; // [sp+14h] [-35BCh]
  int v583; // [sp+14h] [-35BCh]
  int v584; // [sp+14h] [-35BCh]
  int v585; // [sp+14h] [-35BCh]
  int v586; // [sp+14h] [-35BCh]
  int *v587; // [sp+18h] [-35B8h]
  int v588; // [sp+18h] [-35B8h]
  int v589; // [sp+18h] [-35B8h]
  int v590; // [sp+18h] [-35B8h]
  int v591; // [sp+18h] [-35B8h]
  int v592; // [sp+18h] [-35B8h]
  int v593; // [sp+18h] [-35B8h]
  int v594; // [sp+18h] [-35B8h]
  int v595; // [sp+18h] [-35B8h]
  int *v596; // [sp+1Ch] [-35B4h]
  int v597; // [sp+1Ch] [-35B4h]
  int v598; // [sp+1Ch] [-35B4h]
  int v599; // [sp+1Ch] [-35B4h]
  int v600; // [sp+1Ch] [-35B4h]
  int v601; // [sp+1Ch] [-35B4h]
  int v602; // [sp+1Ch] [-35B4h]
  int v603; // [sp+1Ch] [-35B4h]
  int v604; // [sp+1Ch] [-35B4h]
  int *v605; // [sp+20h] [-35B0h]
  int v606; // [sp+20h] [-35B0h]
  int v607; // [sp+20h] [-35B0h]
  int v608; // [sp+20h] [-35B0h]
  int v609; // [sp+20h] [-35B0h]
  int v610; // [sp+20h] [-35B0h]
  int v611; // [sp+20h] [-35B0h]
  int v612; // [sp+20h] [-35B0h]
  int v613; // [sp+20h] [-35B0h]
  int *v614; // [sp+24h] [-35ACh]
  int v615; // [sp+24h] [-35ACh]
  int v616; // [sp+24h] [-35ACh]
  int v617; // [sp+24h] [-35ACh]
  unsigned __int8 v618; // [sp+27h] [-35A9h]
  unsigned __int8 v619; // [sp+27h] [-35A9h]
  unsigned __int8 v620; // [sp+27h] [-35A9h]
  unsigned __int8 v621; // [sp+27h] [-35A9h]
  unsigned __int8 v622; // [sp+27h] [-35A9h]
  int v623; // [sp+28h] [-35A8h]
  int v624; // [sp+28h] [-35A8h]
  int v625; // [sp+28h] [-35A8h]
  int v626; // [sp+2Ch] [-35A4h]
  int v627; // [sp+2Ch] [-35A4h]
  unsigned __int8 v628; // [sp+2Fh] [-35A1h]
  int v629; // [sp+30h] [-35A0h]
  int v630; // [sp+30h] [-35A0h]
  int v631; // [sp+34h] [-359Ch]
  int v632; // [sp+34h] [-359Ch]
  int v633; // [sp+38h] [-3598h]
  int v634; // [sp+38h] [-3598h]
  int v635; // [sp+3Ch] [-3594h]
  int v636; // [sp+3Ch] [-3594h]
  int v637; // [sp+40h] [-3590h]
  int v638; // [sp+40h] [-3590h]
  int v639; // [sp+44h] [-358Ch]
  int v640; // [sp+44h] [-358Ch]
  int v641; // [sp+48h] [-3588h]
  int v642; // [sp+48h] [-3588h]
  int v643; // [sp+4Ch] [-3584h]
  int v644; // [sp+4Ch] [-3584h]
  int v645; // [sp+50h] [-3580h]
  int v646; // [sp+50h] [-3580h]
  int v647; // [sp+54h] [-357Ch]
  int v648; // [sp+58h] [-3578h]
  int v649; // [sp+58h] [-3578h]
  int v650; // [sp+60h] [-3570h]
  int v651; // [sp+68h] [-3568h]
  int v652; // [sp+70h] [-3560h]
  int v653; // [sp+78h] [-3558h]
  int v654; // [sp+80h] [-3550h]
  int v655; // [sp+88h] [-3548h]
  unsigned __int8 v656; // [sp+90h] [-3540h] BYREF
  int v657; // [sp+94h] [-353Ch] BYREF
  char *v658; // [sp+98h] [-3538h]
  int v659; // [sp+9Ch] [-3534h]
  int v660; // [sp+A0h] [-3530h]
  int v661; // [sp+A4h] [-352Ch] BYREF
  idList<char,5> v662; // [sp+A8h] [-3528h] BYREF
  int v663; // [sp+B8h] [-3518h]
  int v664; // [sp+BCh] [-3514h]
  int v665; // [sp+C0h] [-3510h] BYREF
  int v666; // [sp+C4h] [-350Ch]
  char *v667; // [sp+C8h] [-3508h] BYREF
  int v668; // [sp+CCh] [-3504h] BYREF
  idList<char,5> v669; // [sp+D0h] [-3500h] BYREF
  idList<idVehicleState *,5> v670; // [sp+E0h] [-34F0h] BYREF
  idList<bool,5> v671; // [sp+F0h] [-34E0h] BYREF
  idList<char,5> v672; // [sp+100h] [-34D0h] BYREF
  idList<bool,5> v673; // [sp+110h] [-34C0h] BYREF
  idList<char,5> v674; // [sp+120h] [-34B0h] BYREF
  idList<bool,5> v675; // [sp+130h] [-34A0h] BYREF
  idList<float,5> v676; // [sp+140h] [-3490h] BYREF
  idList<idVehicleState *,5> v677; // [sp+150h] [-3480h] BYREF
  idList<char,5> v678; // [sp+160h] [-3470h] BYREF
  idList<bool,5> v679; // [sp+170h] [-3460h] BYREF
  idList<idVehicleState *,5> v680; // [sp+180h] [-3450h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v681; // [sp+190h] [-3440h] BYREF
  idList<bool,5> v682; // [sp+1A0h] [-3430h] BYREF
  idList<bool,5> v683; // [sp+1B0h] [-3420h] BYREF
  idList<bool,5> v684; // [sp+1C0h] [-3410h] BYREF
  idList<bool,5> v685; // [sp+1D0h] [-3400h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v686; // [sp+1E0h] [-33F0h] BYREF
  idList<bool,5> v687; // [sp+1F0h] [-33E0h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v688; // [sp+200h] [-33D0h] BYREF
  idList<float,32> v689; // [sp+210h] [-33C0h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v690; // [sp+220h] [-33B0h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v691; // [sp+230h] [-33A0h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v692; // [sp+240h] [-3390h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v693; // [sp+250h] [-3380h] BYREF
  idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> v694; // [sp+260h] [-3370h] BYREF
  idList<char,5> v695; // [sp+270h] [-3360h] BYREF
  idList<bool,5> v696; // [sp+280h] [-3350h] BYREF
  idList<idVehicleState *,5> v697; // [sp+290h] [-3340h] BYREF
  idList<bool,5> v698; // [sp+2A0h] [-3330h] BYREF
  idList<int,5> v699; // [sp+2B0h] [-3320h] BYREF
  idList<bool,5> v700; // [sp+2C0h] [-3310h] BYREF
  idList<char,5> v701; // [sp+2D0h] [-3300h] BYREF
  idList<float,32> v702; // [sp+2E0h] [-32F0h] BYREF
  idList<bool,5> v703; // [sp+2F0h] [-32E0h] BYREF
  idList<float,32> v704; // [sp+300h] [-32D0h] BYREF
  idList<idVehicleState *,5> v705; // [sp+310h] [-32C0h] BYREF
  char *v706; // [sp+320h] [-32B0h]
  char *v707; // [sp+324h] [-32ACh]
  char *v708; // [sp+328h] [-32A8h]
  const char *v709; // [sp+32Ch] [-32A4h]
  char *v710; // [sp+330h] [-32A0h]
  _WORD v711[11]; // [sp+338h] [-3298h] BYREF
  __int16 v712; // [sp+34Eh] [-3282h]
  __int16 v713; // [sp+350h] [-3280h]
  __int16 v714; // [sp+352h] [-327Eh]
  __int16 v715; // [sp+354h] [-327Ch]
  __int16 v716; // [sp+356h] [-327Ah]
  __int16 v717; // [sp+358h] [-3278h]
  __int16 v718; // [sp+35Ah] [-3276h]
  __int16 v719; // [sp+35Ch] [-3274h]
  __int16 v720; // [sp+35Eh] [-3272h]
  float v721[24]; // [sp+360h] [-3270h] BYREF
  idList<idVehicleState *,5> v722; // [sp+3C0h] [-3210h] BYREF
  int v723; // [sp+3D0h] [-3200h] BYREF
  idList<idVehicleState *,5> v724; // [sp+4D0h] [-3100h] BYREF
  int v725; // [sp+4E0h] [-30F0h] BYREF
  idList<idVehicleState *,5> v726; // [sp+14E0h] [-20F0h] BYREF
  int v727; // [sp+14F0h] [-20E0h] BYREF
  idList<idVehicleState *,5> v728; // [sp+24F0h] [-10E0h] BYREF
  int v729; // [sp+2500h] [-10D0h] BYREF

  if ( maskTJointsa > 15810 )
    idLib::Error(
      fmt: "Animation '%s' is too long (%d frames, optimal max is %d), only 255 framesets are allowed and maxiumum optimal fra"
      "meset length is %d frames.",
      this->name.str,
      maskTJointsa,
      15810,
      62);
  valueFloat = anim_forceCompression.valueFloat;
  if ( anim_forceCompression.valueFloat < 0.0 )
    valueFloat = *(float *)&jointWeightsa->list;
  if ( idMD6Anim::skipJoints )
    v46 = 0;
  else
    v46 = (*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8;
  v660 = v46;
  if ( idMD6Anim::skipJoints )
  {
    num = userChannels->num;
    __twllei(maskTJointsa, 0);
    v48 = __ROL4__(num, 1);
    v49 = num / maskTJointsa;
    __twlgei(maskTJointsa & ~(v48 - 1), 0xFFFFFFFF);
  }
  else
  {
    v49 = (*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 4) + 7) & 0xFFF8;
  }
  memset(&v683, 0, 14);
  *(_WORD *)&v683.memTag = 1280;
  v50 = maskSJoints_2 < 0 ? 0 : v49;
  v659 = v50;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v683);
  memset(&v685, 0, 14);
  *(_WORD *)&v685.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v685);
  memset(&v684, 0, 14);
  *(_WORD *)&v684.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v684);
  memset(&v679, 0, 14);
  *(_WORD *)&v679.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v679);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v683, newNum: v46 * maskTJointsa, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v685, newNum: v46 * maskTJointsa, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v684, newNum: v46 * maskTJointsa, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v679, newNum: v50 * maskTJointsa, initValue: (const bool *)&v656);
  memset(&v697, 0, 14);
  v697.memTag = 5;
  v697.listStatic = 0;
  idList<idThread *,58>::Clear(this: &v697);
  memset(&v704, 0, 14);
  v704.memTag = 5;
  v704.listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v704);
  memset(&v702, 0, 14);
  v702.memTag = 5;
  v702.listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v702);
  memset(&v689, 0, 14);
  *(_WORD *)&v689.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v689);
  memset(&v700, 0, 14);
  *(_WORD *)&v700.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v700);
  memset(&v698, 0, 14);
  *(_WORD *)&v698.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v698);
  memset(&v696, 0, 14);
  *(_WORD *)&v696.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v696);
  memset(&v703, 0, 14);
  *(_WORD *)&v703.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v703);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v700, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v698, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v696, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  v51 = (v50 + 7) / 8;
  idList<bool,5>::SetNum(this: &v703, newNum: v51, initValue: (const bool *)&v656);
  memset(&v675, 0, 14);
  *(_WORD *)&v675.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v675);
  memset(&v671, 0, 14);
  *(_WORD *)&v671.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v671);
  memset(&v673, 0, 14);
  *(_WORD *)&v673.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v673);
  memset(&v682, 0, 14);
  *(_WORD *)&v682.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v682);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v675, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v671, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v673, newNum: (v46 + 7) / 8, initValue: (const bool *)&v656);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v682, newNum: v51, initValue: (const bool *)&v656);
  v663 = 0;
  v664 = 0;
  v662.size = 0;
  v666 = 0;
  if ( idMD6Anim::skipJoints )
    v52 = nullptr;
  else
    v52 = (const __int16 *)(*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 14) + *(_DWORD *)&skel[20].value);
  if ( idMD6Anim::skipJoints )
    list = nullptr;
  else
    list = (idVehicleState **)(*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8) + *(_DWORD *)&skel[20].value);
  if ( idMD6Anim::skipJoints )
    v54 = nullptr;
  else
    v54 = (idVehicleState **)(((16 * (*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 2) + 7)) & 0xFFF80)
                            + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                            + *(_DWORD *)&skel[20].value);
  if ( idMD6Anim::skipJoints )
    v55 = nullptr;
  else
    v55 = (idVehicleState **)(28 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                            + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                            + *(_DWORD *)&skel[20].value);
  if ( idMD6Anim::skipJoints )
    v658 = nullptr;
  else
    v658 = (char *)(40 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                  + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                  + *(_DWORD *)&skel[20].value);
  memset(&v676, 0, 14);
  *(_WORD *)&v676.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v676);
  *(float *)&v661 = -1.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&v676, newNum: v46, initValue: (float *)&v661);
  LOWORD(v56) = 0;
  if ( v46 > 0 )
  {
    do
    {
      _idMD6Anim::CompressAnim_::_2_::local_t::GetSetDistanceToRoot(
        jointIndex: v56,
        parentTable: v52,
        baseT: (const float *)v55,
        distanceToRootList: &v676);
      v56 = v57 + 1;
    }
    while ( v56 < v46 );
  }
  *(_WORD *)&v680.memTag = 1280;
  memset(&v680, 0, 14);
  v662.granularity = -1;
  idList<short,5>::SetNum(this: (idList<short,5> *)&v680, newNum: v46, initValue: &v662.granularity);
  for ( i = 0; i < v46; ++i )
    _idMD6Anim::CompressAnim_::_2_::local_t::GetSetFarthestEndEffector(
      jointIndex: i,
      parentTable: v52,
      distanceToRoot: &v676,
      farthestEndEffectorList: (idList<short,5> *)&v680);
  HIDWORD(v61) = this->normalizedBounds.b[0][2];
  DWORD1(v60) = (unsigned __int16)this->normalizedBounds.b[0][0];
  LODWORD(v61) = this->normalizedBounds.b[1][0];
  v62 = this->normalizedBounds.b[0][1];
  DWORD2(v61) = SWORD3(v60);
  *(_QWORD *)&v662.list = v61;
  DWORD1(v61) = (unsigned __int16)this->normalizedBounds.b[1][1];
  *(_QWORD *)&v662.list = *(_QWORD *)((char *)&v61 + 4);
  DWORD2(v60) = v62;
  LODWORD(v60) = SWORD3(v61);
  v63 = (double)(__int64)v61;
  LODWORD(v61) = this->normalizedBounds.b[1][2];
  v662.num = v61;
  v662.list = (char *)&this->normalizedBounds;
  v64 = (float)((float)(__int64)v61 - (float)*(__int64 *)(&v58 - 1));
  v65 = (float)((float)v63 - (float)*(__int64 *)((char *)&v61 + 4));
  v66 = (float)((float)(__int64)v60 - (float)*(__int64 *)((char *)&v60 + 4));
  v67 = __fsqrts((float)((float)((float)v66 * (float)v66)
                       + (float)((float)((float)v65 * (float)v65) + (float)((float)v64 * (float)v64))));
  v68 = (float)((float)((float)v67 * (float)0.00069999998) * (float)5.0);
  v69 = (float)((float)((float)v67 * (float)0.00069999998) * (float)valueFloat);
  if ( idMD6Anim::skipJoints )
    v70 = (float)((float)valueFloat * (float)0.0033333334);
  else
    v70 = (float)((float)((float)((float)v67 * (float)0.00069999998) * (float)valueFloat) * (float)0.050000001);
  v728.num = 0;
  size = 1024;
  v728.memTag = 5;
  v728.granularity = 1;
  v728.size = 1024;
  v728.list = (idVehicleState **)&v729;
  v728.listStatic = 1;
  v726.num = 0;
  v726.granularity = 1;
  v726.size = 1024;
  v726.memTag = 5;
  v726.list = (idVehicleState **)&v727;
  v726.listStatic = 1;
  v724.num = 0;
  v724.granularity = 1;
  v724.size = 1024;
  v724.memTag = 5;
  v724.list = (idVehicleState **)&v725;
  v724.listStatic = 1;
  if ( (maskSJoints_2 & 0x101) != 0 )
  {
    v72 = 4 * v46;
    if ( 4 * v46 > 1024 )
    {
      if ( (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v728, newsize: 4 * v46) == 0 )
      {
LABEL_39:
        if ( v72 <= v726.size
          || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v726, newsize: 4 * v46) != 0 )
        {
          v726.num = 4 * v46;
          if ( v72 >= v726.size )
            v726.num = v726.size;
        }
        if ( v72 <= v724.size
          || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v724, newsize: 4 * v46) != 0 )
        {
          v724.num = 4 * v46;
          if ( v72 >= v724.size )
            v724.num = v724.size;
        }
        if ( v46 > 0 )
        {
          v73 = 0;
          v74 = v660;
          do
          {
            *(float *)&v728.list[v73] = 0.0;
            *(float *)&v728.list[v73 + 1] = 0.0;
            *(float *)&v728.list[v73 + 2] = 0.0;
            *(float *)&v728.list[v73 + 3] = 1.0;
            *(float *)&v726.list[v73] = 1.0;
            *(float *)&v726.list[v73 + 1] = 1.0;
            *(float *)&v726.list[v73 + 2] = 1.0;
            *(float *)&v726.list[v73 + 3] = 1.0;
            *(float *)&v724.list[v73] = 0.0;
            *(float *)&v724.list[v73 + 1] = 0.0;
            *(float *)&v724.list[v73 + 2] = 0.0;
            *(float *)&v724.list[v73 + 3] = 0.0;
            v73 += 4;
            --v74;
          }
          while ( v74 != 0 );
        }
        list = v728.list;
        v54 = v726.list;
        v55 = v724.list;
        v46 = v660;
        goto LABEL_51;
      }
      size = v728.size;
    }
    v728.num = 4 * v46;
    if ( v72 >= size )
      v728.num = size;
    goto LABEL_39;
  }
LABEL_51:
  v75 = 0;
  if ( v46 > 0 )
  {
    v76 = 0;
    v77 = maskTJointsa;
    v78 = 0;
    v79 = v671.list;
    v80 = 16 * v660;
    v81 = v673.list;
    v82 = 0;
    v83 = 12 * v660;
    v84 = 16 * v660;
    v85 = 12 * v660;
    do
    {
      v86 = 1;
      _FP11 = (float)((float)(v676.list[*(__int16 *)((char *)v680.list + v82)] - v676.list[v78]) - (float)v68);
      __asm { fsel      f31, f11, f12, f28 }
      if ( v77 > 1 )
      {
        v89 = v84;
        while ( _idMD6Anim::CompressAnim_::_2_::local_t::IsRWithinTolerance(
                  a: &rotation->list[4 * v75],
                  b: (const float *)((char *)rotation->list + v89),
                  length: _FP31,
                  tolerance: v69) )
        {
          ++v86;
          v89 += v80;
          if ( v86 >= maskTJointsa )
            goto LABEL_59;
        }
        v90 = v675.list[v75 >> 3];
        ++v663;
        v675.list[v75 >> 3] = (1 << (v75 & 7)) | v90;
LABEL_59:
        v81 = v673.list;
        v79 = v671.list;
        v77 = maskTJointsa;
      }
      v91 = 1;
      if ( v77 > 1 )
      {
        v92 = v85;
        v93 = scale->list;
        while ( 1 )
        {
          v94 = (float)((float)(*(float *)((char *)v93 + v92) * (float)_FP31) - (float)(v93[v76] * (float)_FP31));
          v95 = (float)((float)(*(float *)((char *)v93 + v92 + 4) * (float)_FP31) - (float)(v93[v76 + 1] * (float)_FP31));
          v96 = (float)((float)(*(float *)((char *)v93 + v92 + 8) * (float)_FP31) - (float)(v93[v76 + 2] * (float)_FP31));
          if ( (float)((float)((float)v96 * (float)v96)
                     + (float)((float)((float)v94 * (float)v94) + (float)((float)v95 * (float)v95))) > (double)(float)((float)v69 * (float)v69) )
            break;
          ++v91;
          v92 += v83;
          if ( v91 >= v77 )
            goto LABEL_66;
        }
        v97 = v79[v75 >> 3];
        ++v664;
        v79[v75 >> 3] = (1 << (v75 & 7)) | v97;
      }
LABEL_66:
      v98 = 1;
      if ( v77 > 1 )
      {
        v99 = v85;
        v100 = translation->list;
        while ( 1 )
        {
          v101 = (float)(*(float *)((char *)v100 + v99) - v100[v76]);
          v102 = (float)(*(float *)((char *)v100 + v99 + 4) - v100[v76 + 1]);
          v103 = (float)(*(float *)((char *)v100 + v99 + 8) - v100[v76 + 2]);
          if ( (float)((float)((float)v103 * (float)v103)
                     + (float)((float)((float)v101 * (float)v101) + (float)((float)v102 * (float)v102))) > (double)(float)((float)v69 * (float)v69) )
            break;
          ++v98;
          v99 += v83;
          if ( v98 >= v77 )
            goto LABEL_72;
        }
        v104 = v81[v75 >> 3];
        ++v662.size;
        v81[v75 >> 3] = (1 << (v75 & 7)) | v104;
      }
LABEL_72:
      ++v75;
      v82 += 2;
      ++v78;
      v84 += 16;
      v76 += 3;
      v85 += 12;
    }
    while ( (int)v75 < v660 );
  }
  v105 = 0;
  v106 = v700.list;
  v107 = v698.list;
  v108 = v696.list;
  v109 = 0;
  v110 = v675.list;
  v657 = 0;
  v665 = 0;
  v668 = 0;
  if ( v660 <= 0 )
  {
    v114 = v671.list;
  }
  else
  {
    v111 = -8 - (_DWORD)list;
    v112 = (float *)(v54 + 1);
    v113 = (float *)(list + 2);
    v114 = v671.list;
    v115 = (char *)v55 - (char *)v54;
    v116 = -4 - (_DWORD)v54;
    v117 = 0;
    v118 = 0;
    do
    {
      v119 = v109 >> 3;
      v120 = 1 << (v109 & 7);
      _FP11 = (float)((float)(v676.list[*(__int16 *)((char *)v680.list + v118)] - v676.list[v117]) - (float)v68);
      __asm { fsel      f31, f11, f12, f28 }
      if ( (v110[v109 >> 3] & (unsigned __int8)v120) == 0 )
      {
        v123 = (float *)((char *)rotation->list + v111 + (unsigned int)v113);
        _FP4 = (float)((float)__fabs((float)(v123[2] - *v113)) - (float)__fabs((float)(v123[3] - v113[1])));
        _FP3 = (float)((float)__fabs((float)(v123[2] + *v113)) - (float)__fabs((float)(v123[3] + v113[1])));
        __asm
        {
          fsel      f2, f4, f10, f9
          fsel      f1, f3, f8, f7
        }
        _FP0 = (float)((float)__fabs((float)(v123[1] - *(v113 - 1))) - (float)_FP2);
        _FP13 = (float)((float)__fabs((float)(v123[1] + *(v113 - 1))) - (float)_FP1);
        __asm
        {
          fsel      f10, f0, f6, f2
          fsel      f9, f13, f5, f1
        }
        _FP8 = (float)((float)__fabs((float)(*v123 - *(v113 - 2))) - (float)_FP10);
        _FP7 = (float)((float)__fabs((float)(*v123 + *(v113 - 2))) - (float)_FP9);
        __asm
        {
          fsel      f6, f8, f12, f10
          fsel      f5, f7, f11, f9
        }
        _FP4 = (float)((float)_FP6 - (float)_FP5);
        __asm { fsel      f3, f4, f5, f6 }
        if ( _FP3 <= v70 )
        {
          IsRWithinTolerance = _idMD6Anim::CompressAnim_::_2_::local_t::IsRWithinTolerance(
                                 a: v123,
                                 b: v113 - 2,
                                 length: _FP31,
                                 tolerance: v69);
          v105 = v668;
          v114 = v671.list;
          v110 = v675.list;
        }
        else
        {
          IsRWithinTolerance = false;
        }
        if ( !IsRWithinTolerance )
        {
          v139 = v106[v119];
          v668 = ++v105;
          v106[v119] = v139 | v120;
        }
      }
      if ( (v114[v119] & (unsigned __int8)v120) == 0 )
      {
        v140 = (float *)((char *)scale->list + v116 + (unsigned int)v112);
        v141 = v140[1];
        v142 = v140[2];
        v143 = *v140;
        _FP2 = (float)((float)__fabs((float)(v140[1] - *v112)) - (float)__fabs((float)(v140[2] - v112[1])));
        __asm { fsel      f1, f2, f5, f4 }
        _FP8 = (float)((float)__fabs((float)(*v140 - *(v112 - 1))) - (float)_FP1);
        __asm { fsel      f7, f8, f3, f1 }
        v148 = _FP7 <= v70;
        if ( _FP7 <= v70 )
        {
          v149 = (float)((float)(*v112 * (float)_FP31) - (float)((float)v141 * (float)_FP31));
          v150 = (float)((float)(*(v112 - 1) * (float)_FP31) - (float)((float)v143 * (float)_FP31));
          v151 = (float)((float)(v112[1] * (float)_FP31) - (float)((float)_FP31 * (float)v142));
          v148 = (float)((float)((float)v151 * (float)v151)
                       + (float)((float)((float)v150 * (float)v150) + (float)((float)v149 * (float)v149))) <= (double)(float)((float)v69 * (float)v69);
        }
        if ( !v148 )
        {
          v152 = v657 + 1;
          v107[v119] |= v120;
          v657 = v152;
        }
      }
      if ( (v673.list[v119] & (unsigned __int8)v120) == 0 )
      {
        v153 = (float *)((char *)translation->list + v116 + (unsigned int)v112);
        v154 = v153[1];
        v155 = v153[2];
        v156 = *v153;
        _FP2 = (float)((float)__fabs((float)(v153[1] - *(float *)((char *)v112 + v115)))
                     - (float)__fabs((float)(v153[2] - *((float *)v55 + 2))));
        __asm { fsel      f1, f2, f5, f4 }
        _FP8 = (float)((float)__fabs((float)(*v153 - *(float *)v55)) - (float)_FP1);
        __asm { fsel      f7, f8, f3, f1 }
        v161 = _FP7 <= v70;
        if ( _FP7 <= v70 )
        {
          v162 = (float)(*(float *)((char *)v112 + v115) - (float)v154);
          v161 = (float)((float)((float)(*((float *)v55 + 2) - (float)v155) * (float)(*((float *)v55 + 2) - (float)v155))
                       + (float)((float)((float)(*(float *)v55 - (float)v156) * (float)(*(float *)v55 - (float)v156))
                               + (float)((float)v162 * (float)v162))) <= (double)(float)((float)v69 * (float)v69);
        }
        if ( !v161 )
        {
          v163 = v108[v119];
          ++v665;
          v108[v119] = v163 | v120;
        }
      }
      ++v109;
      v118 += 2;
      ++v117;
      v113 += 4;
      v112 += 3;
      v55 += 3;
    }
    while ( (int)v109 < v660 );
  }
  v164 = 0;
  if ( maskRJoints->num > 0 )
  {
    v165 = v663;
    v166 = 0;
    do
    {
      value = maskRJoints->list[v166].value;
      v168 = value >> 3;
      v169 = 1 << (value & 7);
      v170 = v106[value >> 3];
      if ( (v170 & v169) != 0 )
      {
        --v105;
        v106[v168] = v170 & ~(_BYTE)v169;
      }
      v171 = v110[v168];
      if ( (v171 & v169) != 0 )
      {
        --v165;
        v110[v168] = v171 & ~(_BYTE)v169;
      }
      ++v164;
      ++v166;
    }
    while ( v164 < maskRJoints->num );
    v663 = v165;
    v668 = v105;
  }
  v172 = 0;
  if ( (int)a28[1] > 0 )
  {
    v173 = v664;
    v174 = 0;
    v175 = v657;
    do
    {
      v176 = *(__int16 *)(v174 + *a28);
      v177 = v176 >> 3;
      v178 = 1 << (v176 & 7);
      v179 = v107[v176 >> 3];
      if ( (v179 & v178) != 0 )
      {
        --v175;
        v107[v177] = v179 & ~(_BYTE)v178;
      }
      v180 = v114[v177];
      if ( (v180 & v178) != 0 )
      {
        --v173;
        v114[v177] = v180 & ~(_BYTE)v178;
      }
      ++v172;
      v174 += 2;
    }
    while ( v172 < a28[1] );
    v664 = v173;
    v657 = v175;
  }
  v181 = 0;
  if ( (int)a30[1] > 0 )
  {
    v182 = v662.size;
    v183 = 0;
    v184 = v665;
    do
    {
      v185 = *(__int16 *)(v183 + *a30);
      v186 = v185 >> 3;
      v187 = 1 << (v185 & 7);
      v188 = v108[v185 >> 3];
      if ( (v188 & v187) != 0 )
      {
        --v184;
        v108[v186] = v188 & ~(_BYTE)v187;
      }
      if ( (v673.list[v186] & (unsigned __int8)v187) != 0 )
      {
        --v182;
        v673.list[v186] &= ~(_BYTE)v187;
      }
      ++v181;
      v183 += 2;
    }
    while ( v181 < a30[1] );
    v662.size = v182;
    v665 = v184;
  }
  v662.granularity = 0;
  idList<short,5>::SetNum(this: (idList<short,5> *)&v697, newNum: 3 * v668, initValue: &v662.granularity);
  *(float *)&v661 = 0.0;
  idList<float,17>::SetNum(this: &v704, newNum: 3 * v657, initValue: (float *)&v661);
  *(float *)&v661 = 0.0;
  idList<float,17>::SetNum(this: &v702, newNum: 3 * v665, initValue: (float *)&v661);
  v189 = v660;
  v190 = 0;
  if ( v660 > 0 )
  {
    v191 = 0;
    v192 = 0;
    v193 = (__int16 *)v697.list;
    v194 = v702.list - 1;
    v195 = v704.list - 1;
    do
    {
      v196 = v190 >> 3;
      v197 = 1 << (v190 & 7);
      if ( (v106[v190 >> 3] & (unsigned __int8)v197) != 0 )
      {
        _idMD6Anim::CompressAnim_::_2_::local_t::CompressR(inR: &rotation->list[v192], outR: v193);
        v193 = (__int16 *)(v198 + 6);
      }
      if ( (v107[v196] & (unsigned __int8)v197) != 0 )
      {
        v199 = &scale->list[v191];
        v195[1] = *v199;
        v195[2] = v199[1];
        v195 += 3;
        *v195 = v199[2];
      }
      if ( (v108[v196] & (unsigned __int8)v197) != 0 )
      {
        v200 = &translation->list[v191];
        v194[1] = *v200;
        v194[2] = v200[1];
        v194 += 3;
        *v194 = v200[2];
      }
      ++v190;
      v192 += 4;
      v191 += 3;
    }
    while ( (int)v190 < v189 );
  }
  v201 = v659;
  v202 = 0;
  v203 = v682.list;
  v204 = v666;
  if ( v659 > 0 )
  {
    v205 = 0;
    v206 = 4 * v659;
    do
    {
      v207 = 1;
      if ( maskTJointsa > 1 )
      {
        v208 = v206;
        while ( __fabs((float)(userChannels->list[v205] - *(float *)((char *)userChannels->list + v208))) <= v70 )
        {
          ++v207;
          v208 += 4 * v201;
          if ( v207 >= maskTJointsa )
            goto LABEL_135;
        }
        ++v204;
        v203[(unsigned int)v202 >> 3] |= 1 << (v202 & 7);
      }
LABEL_135:
      ++v202;
      ++v205;
      v206 += 4;
    }
    while ( v202 < v201 );
    v666 = v204;
  }
  v209 = v703.list;
  v210 = 0;
  v211 = v658;
  v674.num = 0;
  v212 = 0;
  if ( v201 >= 4 )
  {
    v213 = 4 - (_DWORD)v658;
    v214 = 2;
    v215 = 2;
    v216 = (float *)(v658 + 8);
    v217 = -8 - (_DWORD)v658;
    do
    {
      v218 = 1 << (v212 & 7);
      if ( (v203[v212 >> 3] & (unsigned __int8)v218) == 0 )
      {
        v219 = idMD6Anim::skipJoints ? 0.0 : *(v216 - 2);
        if ( __fabs((float)(*(float *)((char *)v216 + v217 + (unsigned int)userChannels->list) - (float)v219)) > v70 )
        {
          ++v210;
          v209[v212 >> 3] |= v218;
        }
      }
      v220 = (v214 - 1) >> 3;
      v221 = 1 << ((v214 - 1) & 7);
      if ( (v203[v220] & (unsigned __int8)v221) == 0 )
      {
        v222 = idMD6Anim::skipJoints ? 0.0 : *(v216 - 1);
        if ( __fabs((float)(*(float *)((char *)v216 + v217 + (unsigned int)userChannels->list + 4) - (float)v222)) > v70 )
        {
          ++v210;
          v209[v220] |= v221;
        }
      }
      v223 = 1 << (v214 & 7);
      if ( (v203[v214 >> 3] & (unsigned __int8)v223) == 0 )
      {
        v224 = idMD6Anim::skipJoints ? 0.0 : *v216;
        if ( __fabs((float)(userChannels->list[v215] - (float)v224)) > v70 )
        {
          ++v210;
          v209[v214 >> 3] |= v223;
        }
      }
      v225 = (v214 + 1) >> 3;
      v226 = 1 << ((v214 + 1) & 7);
      if ( (v203[v225] & (unsigned __int8)v226) == 0 )
      {
        v227 = idMD6Anim::skipJoints ? 0.0 : v216[1];
        if ( __fabs((float)(*(float *)((char *)v216 + v213 + (unsigned int)userChannels->list) - (float)v227)) > v70 )
        {
          ++v210;
          v209[v225] |= v226;
        }
      }
      v212 += 4;
      v215 += 4;
      v216 += 4;
      v214 += 4;
    }
    while ( (int)v212 < v201 - 3 );
    v674.num = v210;
  }
  if ( (int)v212 < v201 )
  {
    v228 = v212;
    v229 = v201 - v212;
    do
    {
      v230 = 1 << (v212 & 7);
      if ( (v203[v212 >> 3] & (unsigned __int8)v230) == 0 )
      {
        v231 = idMD6Anim::skipJoints ? 0.0 : *(float *)&v211[v228 * 4];
        if ( __fabs((float)(userChannels->list[v228] - (float)v231)) > v70 )
        {
          ++v210;
          v209[v212 >> 3] |= v230;
        }
      }
      ++v212;
      ++v228;
      --v229;
    }
    while ( v229 != 0 );
    v674.num = v210;
  }
  v232 = 0;
  if ( (int)a32[1] > 0 )
  {
    v233 = 0;
    do
    {
      v234 = *(__int16 *)(*a32 + v233);
      v235 = v234 >> 3;
      v236 = 1 << (v234 & 7);
      v237 = v209[v234 >> 3];
      if ( (v237 & v236) != 0 )
      {
        --v210;
        v209[v235] = v237 & ~(_BYTE)v236;
      }
      v238 = v203[v235];
      if ( (v238 & v236) != 0 )
      {
        --v204;
        v203[v235] = v238 & ~(_BYTE)v236;
      }
      ++v232;
      v233 += 2;
    }
    while ( v232 < a32[1] );
    v666 = v204;
    v674.num = v210;
  }
  *(float *)&v661 = 0.0;
  idList<float,17>::SetNum(this: &v689, newNum: 4 * v210, initValue: (float *)&v661);
  v239 = v689.list;
  v240 = 0;
  v241 = 0;
  if ( v201 >= 4 )
  {
    v242 = 2;
    v243 = 0;
    v244 = v689.list - 1;
    v245 = 0;
    do
    {
      if ( ((1 << (v240 & 7)) & v209[v245]) != 0 )
      {
        ++v241;
        v244[1] = userChannels->list[v243];
        ++v244;
      }
      if ( ((1 << ((v242 - 1) & 7)) & v209[(v242 - 1) >> 3]) != 0 )
      {
        ++v241;
        v244[1] = userChannels->list[v243 + 1];
        ++v244;
      }
      if ( ((1 << (v242 & 7)) & v209[v242 >> 3]) != 0 )
      {
        ++v241;
        v244[1] = userChannels->list[v243 + 2];
        ++v244;
      }
      if ( ((1 << ((v242 + 1) & 7)) & v209[(v242 + 1) >> 3]) != 0 )
      {
        ++v241;
        *++v244 = userChannels->list[v243 + 3];
      }
      v240 += 4;
      v243 += 4;
      v242 += 4;
      v245 = (unsigned int)v240 >> 3;
    }
    while ( v240 < v201 - 3 );
  }
  if ( v240 < v201 )
  {
    v246 = v240;
    v247 = &v239[v241 - 1];
    v248 = v201 - v240;
    do
    {
      if ( ((1 << (v240 & 7)) & v209[(unsigned int)v240 >> 3]) != 0 )
        *++v247 = userChannels->list[v246];
      ++v240;
      ++v246;
      --v248;
    }
    while ( v248 != 0 );
  }
  v249 = 0;
  if ( v189 > 0 )
  {
    v250 = v675.list;
    v251 = 0;
    do
    {
      v252 = v249 & 7;
      if ( ((1 << (v249 & 7)) & v250[v251]) != 0 )
      {
        v253 = maskTJointsa - 1;
        v254 = 0;
        if ( maskTJointsa - 1 > 0 )
        {
          do
          {
            v255 = v254 + 62;
            v256 = v254 + 62;
            if ( v254 + 62 >= v253 )
              v256 = maskTJointsa - 1;
            _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
              distanceToRootList: &v676,
              farthestEndEffectorList: (const idList<short,5> *)&v680,
              keyFrame: rotation,
              leftFrame: v254,
              rightFrame: v256,
              jointIndex: v249,
              numJoints: v189,
              minimumDistanceToFarthestEndEffector: v68,
              tolerance: v69,
              channelType: v252,
              mask: v551,
              a12: (int)v560,
              a13: (int)v569,
              a14: (int)v578,
              a15: (int)v587,
              a16: (int)v596,
              a17: (int)v605,
              a18: (int)v614,
              a19: v623,
              a20: v626,
              a21: v629,
              a22: v631,
              a23: v633,
              a24: v635,
              a25: v637,
              a26: v639,
              a27: v641,
              a28: v643,
              a29: v645,
              a30: v647,
              a31: v648,
              a32: 0,
              a33: v650,
              a34: &v683);
            v254 = v255;
          }
          while ( v255 < v253 );
        }
      }
      v251 = (unsigned int)++v249 >> 3;
    }
    while ( v249 < v189 );
  }
  v257 = 0;
  if ( v189 > 0 )
  {
    v258 = v671.list;
    v259 = 0;
    do
    {
      v260 = v257 & 7;
      if ( ((1 << (v257 & 7)) & v258[v259]) != 0 )
      {
        v261 = maskTJointsa - 1;
        v262 = 0;
        if ( maskTJointsa - 1 > 0 )
        {
          do
          {
            v263 = v262 + 62;
            v264 = v262 + 62;
            if ( v262 + 62 >= v261 )
              v264 = maskTJointsa - 1;
            _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
              distanceToRootList: &v676,
              farthestEndEffectorList: (const idList<short,5> *)&v680,
              keyFrame: scale,
              leftFrame: v262,
              rightFrame: v264,
              jointIndex: v257,
              numJoints: v189,
              minimumDistanceToFarthestEndEffector: v68,
              tolerance: v69,
              channelType: v260,
              mask: v551,
              a12: (int)v560,
              a13: (int)v569,
              a14: (int)v578,
              a15: (int)v587,
              a16: (int)v596,
              a17: (int)v605,
              a18: (int)v614,
              a19: v623,
              a20: v626,
              a21: v629,
              a22: v631,
              a23: v633,
              a24: v635,
              a25: v637,
              a26: v639,
              a27: v641,
              a28: v643,
              a29: v645,
              a30: v647,
              a31: v648,
              a32: 1u,
              a33: v650,
              a34: &v685);
            v262 = v263;
          }
          while ( v263 < v261 );
        }
      }
      v259 = (unsigned int)++v257 >> 3;
    }
    while ( v257 < v189 );
  }
  v265 = 0;
  if ( v189 > 0 )
  {
    v266 = v673.list;
    v267 = 0;
    do
    {
      v268 = v265 & 7;
      if ( ((1 << (v265 & 7)) & v266[v267]) != 0 )
      {
        v269 = maskTJointsa - 1;
        v270 = 0;
        if ( maskTJointsa - 1 > 0 )
        {
          do
          {
            v271 = v270 + 62;
            v272 = v270 + 62;
            if ( v270 + 62 >= v269 )
              v272 = maskTJointsa - 1;
            _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
              distanceToRootList: &v676,
              farthestEndEffectorList: (const idList<short,5> *)&v680,
              keyFrame: translation,
              leftFrame: v270,
              rightFrame: v272,
              jointIndex: v265,
              numJoints: v189,
              minimumDistanceToFarthestEndEffector: v68,
              tolerance: v69,
              channelType: v268,
              mask: v551,
              a12: (int)v560,
              a13: (int)v569,
              a14: (int)v578,
              a15: (int)v587,
              a16: (int)v596,
              a17: (int)v605,
              a18: (int)v614,
              a19: v623,
              a20: v626,
              a21: v629,
              a22: v631,
              a23: v633,
              a24: v635,
              a25: v637,
              a26: v639,
              a27: v641,
              a28: v643,
              a29: v645,
              a30: v647,
              a31: v648,
              a32: 2u,
              a33: v650,
              a34: &v684);
            v270 = v271;
          }
          while ( v271 < v269 );
        }
      }
      v267 = (unsigned int)++v265 >> 3;
    }
    while ( v265 < v189 );
  }
  v273 = 0;
  if ( v201 > 0 )
  {
    v274 = 0;
    do
    {
      v275 = v273 & 7;
      if ( ((1 << (v273 & 7)) & v203[v274]) != 0 )
      {
        v276 = maskTJointsa - 1;
        v277 = 0;
        if ( maskTJointsa - 1 > 0 )
        {
          do
          {
            v278 = v277 + 62;
            v279 = v277 + 62;
            if ( v277 + 62 >= v276 )
              v279 = maskTJointsa - 1;
            _idMD6Anim::CompressAnim_::_2_::local_t::Reduce(
              distanceToRootList: &v676,
              farthestEndEffectorList: (const idList<short,5> *)&v680,
              keyFrame: userChannels,
              leftFrame: v277,
              rightFrame: v279,
              jointIndex: v273,
              numJoints: v201,
              minimumDistanceToFarthestEndEffector: v68,
              tolerance: v70,
              channelType: v275,
              mask: v551,
              a12: (int)v560,
              a13: (int)v569,
              a14: (int)v578,
              a15: (int)v587,
              a16: (int)v596,
              a17: (int)v605,
              a18: (int)v614,
              a19: v623,
              a20: v626,
              a21: v629,
              a22: v631,
              a23: v633,
              a24: v635,
              a25: v637,
              a26: v639,
              a27: v641,
              a28: v643,
              a29: v645,
              a30: v647,
              a31: v648,
              a32: 3u,
              a33: v650,
              a34: &v679);
            v277 = v278;
          }
          while ( v278 < v276 );
        }
      }
      v274 = (unsigned int)++v273 >> 3;
    }
    while ( v273 < v201 );
  }
  v280 = v664;
  v281 = 0;
  v282 = v662.size;
  v283 = maskTJointsa;
  v284 = v663;
  v285 = 0;
  *(float *)&v661 = 0.0;
  v286 = 0;
  if ( maskTJointsa != 0 )
  {
    while ( 1 )
    {
      ++v286;
      --v283;
      if ( (int)_idMD6Anim::CompressAnim_::_2_::local_t::CalculateFrameSize(
                  frameStart: v285,
                  frameRange: v286,
                  numJoints: v189,
                  numPaddedUserChannels: v201,
                  numAnimR: v284,
                  numAnimS: v280,
                  numAnimT: v282,
                  numAnimU: v204,
                  maskR: v551,
                  maskS: v560,
                  maskT: v569,
                  maskU: v578,
                  sizeR: v587,
                  sizeS: v596,
                  sizeT: v605,
                  sizeU: v614,
                  a17: v623,
                  a18: v626,
                  a19: v629,
                  a20: v631,
                  a21: v633,
                  a22: v635,
                  a23: v637,
                  a24: v639,
                  a25: v641,
                  a26: v643,
                  a27: v645,
                  a28: &v683,
                  a29: v648,
                  a30: &v685,
                  a31: v650,
                  a32: &v684,
                  a33: v651,
                  a34: &v679,
                  a35: v652,
                  maskRa: &v678,
                  a37: v653,
                  maskSa: &v674,
                  a39: v654,
                  maskTa: &v672,
                  a41: v655,
                  maskUa: &v662) > 0x4000 )
        goto LABEL_237;
      if ( v283 == 0 )
        break;
      if ( v286 >= 62 )
        goto LABEL_238;
LABEL_239:
      if ( v283 == 0 )
      {
        v661 = v281;
        if ( v281 > 255 )
          idLib::Error(
            fmt: "Animation '%s' requires too many framesets with current compression settings (%d).",
            this->name.str,
            v281);
        goto _LN2030;
      }
    }
    if ( v286 > 1 )
    {
LABEL_237:
      --v286;
      ++v283;
    }
LABEL_238:
    v285 += v286;
    ++v281;
    v286 = 0;
    goto LABEL_239;
  }
_LN2030:
  *(_WORD *)&v687.memTag = 1280;
  memset(&v687, 0, 14);
  v656 = 0;
  idList<bool,5>::SetNum(this: &v687, newNum: maskTJointsa, initValue: (const bool *)&v656);
  *(_WORD *)&v699.memTag = 1280;
  memset(&v699, 0, 14);
  v667 = nullptr;
  idList<idRenderModelCommitted *,5>::SetNum(this: &v699, newNum: v281 + 1, initValue: (const int *)&v667);
  v287 = 4 * (v281 + 32) + maskTJointsa;
  if ( v287 > 0x4000 )
    idLib::Error(
      fmt: "Animation '%s' requires a header that is too large (%d, max is %d), sizeof(frameSetTbl) = %d, sizeof(frameSetOffsetTbl) = %d.",
      this->name.str,
      v287,
      0x4000,
      maskTJointsa,
      4 * v281);
  v288 = 0;
  memset(&v677, 0, 14);
  *(_WORD *)&v677.memTag = 1280;
  if ( v281 > 0 )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v677,
                            newsize: v281) == 0 )
      goto LABEL_249;
    v288 = v677.size;
  }
  v677.num = v281;
  if ( v281 >= v288 )
    v677.num = v288;
LABEL_249:
  v289 = v687.list;
  v290 = nullptr;
  v658 = nullptr;
  v291 = (char *)maskTJointsa;
  v292 = 0;
  v678.size = (int)&mem;
  v293 = 0;
  if ( maskTJointsa != 0 )
  {
    v709 = "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Anim.cpp(1685) : TAG_ANIMATION";
    while ( 1 )
    {
      ++v293;
      v667 = --v291;
      if ( (int)_idMD6Anim::CompressAnim_::_2_::local_t::CalculateFrameSize(
                  frameStart: v292,
                  frameRange: v293,
                  numJoints: v189,
                  numPaddedUserChannels: v201,
                  numAnimR: v284,
                  numAnimS: v280,
                  numAnimT: v282,
                  numAnimU: v204,
                  maskR: v551,
                  maskS: v560,
                  maskT: v569,
                  maskU: v578,
                  sizeR: v587,
                  sizeS: v596,
                  sizeT: v605,
                  sizeU: v614,
                  a17: v623,
                  a18: v626,
                  a19: v629,
                  a20: v631,
                  a21: v633,
                  a22: v635,
                  a23: v637,
                  a24: v639,
                  a25: v641,
                  a26: v643,
                  a27: v645,
                  a28: &v683,
                  a29: v648,
                  a30: &v685,
                  a31: v650,
                  a32: &v684,
                  a33: v651,
                  a34: &v679,
                  a35: v652,
                  maskRa: &v669,
                  a37: v653,
                  maskSa: (const idList<char,5> *)&v662.granularity,
                  a39: v654,
                  maskTa: &v695,
                  a41: v655,
                  maskUa: &v701) > 0x4000 )
        goto LABEL_256;
      if ( v291 == nullptr )
        break;
      if ( v293 >= 62 )
        goto LABEL_257;
LABEL_350:
      if ( v291 == nullptr )
        goto LABEL_351;
    }
    if ( v293 > 1 )
    {
LABEL_256:
      --v293;
      v667 = v291 + 1;
    }
LABEL_257:
    _idMD6Anim::CompressAnim_::_2_::local_t::CalculateFrameSize(
      frameStart: v292,
      frameRange: v293,
      numJoints: v189,
      numPaddedUserChannels: v201,
      numAnimR: v284,
      numAnimS: v280,
      numAnimT: v282,
      numAnimU: v204,
      maskR: v551,
      maskS: v560,
      maskT: v569,
      maskU: v578,
      sizeR: v587,
      sizeS: v596,
      sizeT: v605,
      sizeU: v614,
      a17: v623,
      a18: v626,
      a19: v629,
      a20: v631,
      a21: v633,
      a22: v635,
      a23: v637,
      a24: v639,
      a25: v641,
      a26: v643,
      a27: v645,
      a28: &v683,
      a29: v648,
      a30: &v685,
      a31: v650,
      a32: &v684,
      a33: v651,
      a34: &v679,
      a35: v652,
      maskRa: &v669,
      a37: v653,
      maskSa: (const idList<char,5> *)&v662.granularity,
      a39: v654,
      maskTa: &v695,
      a41: v655,
      maskUa: &v701);
    v294 = idMem::AllocWithLocation(
             this: (idMem *)v678.size,
             location: v709,
             size: 0x4000u,
             tag: TAG_ANIMATION,
             zeroBuffer: true,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
    HIDWORD(v296) = v677.list;
    v295 = v294;
    LODWORD(v296) = 0;
    v297 = v294 - 4;
    v677.list[(_DWORD)v290] = (idVehicleState *)v294;
    for ( j = 6; j != 0; --j )
      *++v297 = v296;
    v299 = v669.list;
    v300 = *(_DWORD *)&v662.granularity;
    v301 = v695.list;
    v302 = v701.list;
    v294[17] = v292;
    v303 = 6 * v284 + 63;
    v304 = v303 & 0xFFFFFFF0;
    v305 = 12 * v280 + (v303 & 0xFFFFFFF0) + 15;
    v306 = v305 & 0xFFFFFFF0;
    v307 = (v293 + 7) & 0xFFFFFFF8;
    v308 = 12 * v282 + (v305 & 0xFFFFFFF0) + 15;
    v309 = 4 * v204 + (v308 & 0xFFFFFFF0) + 15;
    v294[1] = v303 & 0xFFF0;
    v294[2] = v305 & 0xFFF0;
    v294[3] = v308 & 0xFFF0;
    v310 = (unsigned int)&v299[(v309 & 0xFFFFFFF0) + 15];
    v294[5] = v310 & 0xFFF0;
    v311 = v300 + (v310 & 0xFFFFFFF0) + 15;
    v294[18] = (unsigned __int8)v293;
    v294[4] = v309 & 0xFFF0;
    v294[6] = v311 & 0xFFF0;
    v312 = (unsigned int)&v301[(v311 & 0xFFFFFFF0) + 15];
    *v294 = 48;
    v708 = (char *)v294 + (v309 & 0xFFFFFFF0);
    v294[7] = v312 & 0xFFF0;
    v678.list = (char *)v294 + (v311 & 0xFFFFFFF0);
    v313 = (unsigned int)&v302[(v312 & 0xFFFFFFF0) + 15];
    v294[8] = v313 & 0xFFF0;
    v706 = (char *)v294 + (v310 & 0xFFFFFFF0);
    v314 = v307 * v280 + 7;
    v672.list = (char *)v295 + (v312 & 0xFFFFFFF0);
    v316 = (char *)v295 + v304;
    v317 = (char *)v295 + v306;
    v318 = (char *)v295 + (v308 & 0xFFFFFFF0);
    v707 = (char *)v295 + (v313 & 0xFFFFFFF0);
    v315 = (int)(v307 * v284 + 7) / 8 + (v313 & 0xFFFFFFF0);
    v295[9] = v315;
    v710 = (char *)v295 + v315;
    v319 = (int)(v307 * v282 + 7) / 8;
    v320 = v314 / 8 + v315;
    v295[10] = v320;
    v674.list = (char *)v295 + v320;
    v321 = v293 + v292;
    v295[11] = v319 + v320;
    v322 = v292;
    v662.list = (char *)v295 + v319 + v320;
    for ( v681.size = (int)(v307 * v204 + 7) / 8 + v319 + v320; v322 < v321; ++v322 )
      v289[v322] = (char)v290;
    v323 = 0;
    v699.list[(_DWORD)v290] = 0xFFFF;
    if ( v189 > 0 )
    {
      v324 = v675.list;
      v325 = v295 + 24;
      v326 = 0;
      do
      {
        if ( ((1 << (v323 & 7)) & v324[v326]) != 0 )
        {
          _idMD6Anim::CompressAnim_::_2_::local_t::CompressR(
            inR: &rotation->list[4 * v292 * v189 + 4 * v323],
            outR: v325);
          v325 = (__int16 *)(v327 + 6);
        }
        v326 = (unsigned int)++v323 >> 3;
      }
      while ( v323 < v189 );
    }
    v328 = 0;
    v329 = v671.list;
    v330 = 0;
    if ( v189 >= 4 )
    {
      v331 = (float *)(v316 - 4);
      v332 = 0;
      do
      {
        if ( ((1 << (v328 & 7)) & v329[v332]) != 0 )
        {
          v330 += 3;
          v333 = &scale->list[3 * v292 * v189 + 3 * v328];
          v331[1] = *v333;
          v331[2] = v333[1];
          v331[3] = v333[2];
          v331 += 3;
        }
        if ( ((1 << ((v328 + 1) & 7)) & v329[(unsigned int)(v328 + 1) >> 3]) != 0 )
        {
          v330 += 3;
          v334 = &scale->list[3 * v292 * v189 + 3 + 3 * v328];
          v331[1] = *v334;
          v331[2] = v334[1];
          v331[3] = v334[2];
          v331 += 3;
        }
        if ( ((1 << ((v328 + 2) & 7)) & v329[(unsigned int)(v328 + 2) >> 3]) != 0 )
        {
          v330 += 3;
          v335 = &scale->list[3 * v292 * v189 + 6 + 3 * v328];
          v331[1] = *v335;
          v331[2] = v335[1];
          v331[3] = v335[2];
          v331 += 3;
        }
        if ( ((1 << ((v328 + 3) & 7)) & v329[(unsigned int)(v328 + 3) >> 3]) != 0 )
        {
          v330 += 3;
          v336 = &scale->list[3 * v292 * v189 + 9 + 3 * v328];
          v331[1] = *v336;
          v331[2] = v336[1];
          v331 += 3;
          *v331 = v336[2];
        }
        v328 += 4;
        v332 = (unsigned int)v328 >> 3;
      }
      while ( v328 < v189 - 3 );
    }
    if ( v328 < v189 )
    {
      v337 = (float *)&v316[4 * v330 - 4];
      v338 = v189 - v328;
      do
      {
        if ( ((1 << (v328 & 7)) & v329[(unsigned int)v328 >> 3]) != 0 )
        {
          v339 = &scale->list[3 * v292 * v189 + 3 * v328];
          v337[1] = *v339;
          v337[2] = v339[1];
          v337 += 3;
          *v337 = v339[2];
        }
        ++v328;
        --v338;
      }
      while ( v338 != 0 );
    }
    v340 = 0;
    v341 = v673.list;
    v342 = 0;
    if ( v189 >= 4 )
    {
      v343 = (float *)(v317 - 4);
      v344 = 0;
      do
      {
        if ( ((1 << (v340 & 7)) & v341[v344]) != 0 )
        {
          v342 += 3;
          v345 = &translation->list[3 * v292 * v189 + 3 * v340];
          v343[1] = *v345;
          v343[2] = v345[1];
          v343[3] = v345[2];
          v343 += 3;
        }
        if ( ((1 << ((v340 + 1) & 7)) & v341[(unsigned int)(v340 + 1) >> 3]) != 0 )
        {
          v342 += 3;
          v346 = &translation->list[3 * v292 * v189 + 3 + 3 * v340];
          v343[1] = *v346;
          v343[2] = v346[1];
          v343[3] = v346[2];
          v343 += 3;
        }
        if ( ((1 << ((v340 + 2) & 7)) & v341[(unsigned int)(v340 + 2) >> 3]) != 0 )
        {
          v342 += 3;
          v347 = &translation->list[3 * v292 * v189 + 6 + 3 * v340];
          v343[1] = *v347;
          v343[2] = v347[1];
          v343[3] = v347[2];
          v343 += 3;
        }
        if ( ((1 << ((v340 + 3) & 7)) & v341[(unsigned int)(v340 + 3) >> 3]) != 0 )
        {
          v342 += 3;
          v348 = &translation->list[3 * v292 * v189 + 9 + 3 * v340];
          v343[1] = *v348;
          v343[2] = v348[1];
          v343 += 3;
          *v343 = v348[2];
        }
        v340 += 4;
        v344 = (unsigned int)v340 >> 3;
      }
      while ( v340 < v189 - 3 );
    }
    if ( v340 < v189 )
    {
      v349 = (float *)&v317[4 * v342 - 4];
      v350 = v189 - v340;
      do
      {
        if ( ((1 << (v340 & 7)) & v341[(unsigned int)v340 >> 3]) != 0 )
        {
          v351 = &translation->list[3 * v292 * v189 + 3 * v340];
          v349[1] = *v351;
          v349[2] = v351[1];
          v349 += 3;
          *v349 = v351[2];
        }
        ++v340;
        --v350;
      }
      while ( v350 != 0 );
    }
    v352 = v659;
    v353 = 0;
    v354 = v682.list;
    v355 = 0;
    if ( v659 >= 4 )
    {
      v356 = v659 - 3;
      v357 = (float *)(v318 - 4);
      v358 = 0;
      do
      {
        if ( ((1 << (v353 & 7)) & v354[v358]) != 0 )
        {
          ++v355;
          v357[1] = userChannels->list[v292 * v352 + v353];
          ++v357;
        }
        if ( ((1 << ((v353 + 1) & 7)) & v354[(unsigned int)(v353 + 1) >> 3]) != 0 )
        {
          ++v355;
          v357[1] = userChannels->list[v292 * v352 + 1 + v353];
          ++v357;
        }
        if ( ((1 << ((v353 + 2) & 7)) & v354[(unsigned int)(v353 + 2) >> 3]) != 0 )
        {
          ++v355;
          v357[1] = userChannels->list[v292 * v352 + 2 + v353];
          ++v357;
        }
        if ( ((1 << ((v353 + 3) & 7)) & v354[(unsigned int)(v353 + 3) >> 3]) != 0 )
        {
          ++v355;
          *++v357 = userChannels->list[v292 * v352 + 3 + v353];
        }
        v353 += 4;
        v358 = (unsigned int)v353 >> 3;
      }
      while ( v353 < v356 );
    }
    if ( v353 < v352 )
    {
      v359 = (float *)&v318[4 * v355 - 4];
      v360 = v352 - v353;
      do
      {
        if ( ((1 << (v353 & 7)) & v354[(unsigned int)v353 >> 3]) != 0 )
          *++v359 = userChannels->list[v292 * v352 + v353];
        ++v353;
        --v360;
      }
      while ( v360 != 0 );
    }
    v361 = 0;
    v362 = 0;
    v363 = 0;
    v364 = 0;
    v365 = 0;
    v366 = 0;
    for ( k = 0; (int)v361 < v189; ++v361 )
    {
      v368 = v361 >> 3;
      v369 = 1 << (v361 & 7);
      if ( (v675.list[v361 >> 3] & (unsigned __int8)v369) != 0 )
      {
        v370 = v292 + 1;
        v371 = v365 + 1;
        if ( v292 + 1 < v321 )
        {
          v372 = v370 * v189 + v361;
          v373 = (__int16 *)&v708[2 * v362];
          v374 = 4 * v372;
          do
          {
            if ( v683.list[v372] )
            {
              _idMD6Anim::CompressAnim_::_2_::local_t::CompressR(inR: &rotation->list[v374], outR: v373);
              v362 += 3;
              v373 = (__int16 *)(v375 + 6);
              v707[v371 / 8] |= 1 << (7 - (v371 & 7));
            }
            ++v370;
            ++v371;
            v374 += 4 * v189;
            v372 += v189;
          }
          while ( v370 < v321 );
        }
        v365 = (v371 + 7) & 0xFFFFFFF8;
      }
      if ( (v671.list[v368] & (unsigned __int8)v369) != 0 )
      {
        v376 = v292 + 1;
        v377 = v366 + 1;
        if ( v292 + 1 < v321 )
        {
          v378 = v710;
          v379 = v376 * v189 + v361;
          v380 = (float *)&v706[4 * v363 - 4];
          v381 = 3 * v379;
          do
          {
            if ( v685.list[v379] )
            {
              v382 = &scale->list[v381];
              v363 += 3;
              v380[1] = *v382;
              v380[2] = v382[1];
              v380 += 3;
              *v380 = v382[2];
              v378[v377 / 8] |= 1 << (7 - (v377 & 7));
            }
            ++v376;
            ++v377;
            v381 += 3 * v189;
            v379 += v189;
          }
          while ( v376 < v321 );
        }
        v366 = (v377 + 7) & 0xFFFFFFF8;
      }
      if ( (v673.list[v368] & (unsigned __int8)v369) != 0 )
      {
        v383 = v292 + 1;
        v384 = k + 1;
        if ( v292 + 1 < v321 )
        {
          v385 = v674.list;
          v386 = v383 * v189 + v361;
          v387 = (float *)&v678.list[4 * v364 - 4];
          v388 = 3 * v386;
          do
          {
            if ( v684.list[v386] )
            {
              v389 = &translation->list[v388];
              v364 += 3;
              v387[1] = *v389;
              v387[2] = v389[1];
              v387 += 3;
              *v387 = v389[2];
              v385[v384 / 8] |= 1 << (7 - (v384 & 7));
            }
            ++v383;
            ++v384;
            v388 += 3 * v189;
            v386 += v189;
          }
          while ( v383 < v321 );
        }
        k = (v384 + 7) & 0xFFFFFFF8;
      }
    }
    v390 = 0;
    v391 = 0;
    v392 = 0;
    if ( v659 > 0 )
    {
      v393 = v679.list;
      v394 = 0;
      do
      {
        if ( ((1 << (v390 & 7)) & v682.list[v394]) != 0 )
        {
          v395 = v292 + 1;
          v396 = v392 + 1;
          if ( v292 + 1 < v321 )
          {
            v397 = v659;
            v398 = v662.list;
            v399 = (float *)&v672.list[4 * v391 - 4];
            v400 = v395 * v659 + v390;
            v401 = v400;
            do
            {
              if ( v393[v400] )
              {
                ++v391;
                *++v399 = userChannels->list[v401];
                v398[v396 / 8] |= 1 << (7 - (v396 & 7));
                v393 = v679.list;
              }
              ++v395;
              ++v396;
              v401 += v397;
              v400 += v397;
            }
            while ( v395 < v321 );
          }
          v392 = (v396 + 7) & 0xFFFFFFF8;
        }
        v394 = (unsigned int)++v390 >> 3;
      }
      while ( v390 < v659 );
    }
    v402 = (int)v295 + v681.size - 1;
    v403 = (HIWORD(v681.size) + 22) & 0xFFF0;
    for ( m = 7; m != 0; --m )
      *(_BYTE *)++v402 = 0;
    v405 = v658;
    v292 = v321;
    v295[16] = v403;
    v293 = 0;
    v289 = v687.list;
    v204 = v666;
    v282 = v662.size;
    v280 = v664;
    v291 = v667;
    v290 = v405 + 1;
    v201 = v659;
    v284 = v663;
    v658 = v405 + 1;
    goto LABEL_350;
  }
LABEL_351:
  v722.num = 0;
  v722.granularity = 1;
  p_memTag = &v722.memTag;
  v722.size = 128;
  v722.listStatic = 1;
  v722.list = (idVehicleState **)&v723;
  v407 = 128;
  v722.memTag = 5;
  do
  {
    p_memTag += 2;
    *(_WORD *)p_memTag = -1;
    --v407;
  }
  while ( v407 != 0 );
  memset(&v705, 0, 14);
  *(_WORD *)&v705.memTag = 1280;
  v408 = 0;
  memset(&v694, 0, 14);
  *(_WORD *)&v694.memTag = 1280;
  v409 = 0;
  memset(&v692, 0, 14);
  *(_WORD *)&v692.memTag = 1280;
  v410 = nullptr;
  v411 = 0;
  memset(&v690, 0, 14);
  *(_WORD *)&v690.memTag = 1280;
  v412 = 0;
  memset(&v686, 0, 14);
  *(_WORD *)&v686.memTag = 1280;
  v413 = 0;
  memset(&v688, 0, 14);
  *(_WORD *)&v688.memTag = 1280;
  v414 = 0;
  memset(&v691, 0, 14);
  *(_WORD *)&v691.memTag = 1280;
  v415 = 0;
  memset(&v693, 0, 14);
  *(_WORD *)&v693.memTag = 1280;
  v416 = 0;
  memset(&v681, 0, 14);
  *(_WORD *)&v681.memTag = 1280;
  v417 = 0;
  v669.list = (char *)mappedSkeletons->num;
  v418 = (int)v669.list;
  if ( (int)v669.list > 0 )
  {
    idList<animMapOffsets_t,5>::Resize(this: (idList<cm_polygon_t,5> *)&v705, newsize: (int)v669.list);
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v694,
                            newsize: v418) == 0 )
      goto LABEL_358;
    v408 = v694.size;
  }
  v694.num = v418;
  if ( v418 >= v408 )
    v694.num = v408;
LABEL_358:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v692,
                            newsize: v418) == 0 )
      goto LABEL_363;
    v409 = v692.size;
  }
  v692.num = v418;
  if ( v418 >= v409 )
    v692.num = v409;
LABEL_363:
  if ( v418 > 0 )
  {
    v419 = idList<idList<unsigned char,5>,5>::Resize(this: (idList<idList<unsigned char,5>,5> *)&v690, newsize: v418);
    v410 = v690.list;
    if ( v419 == 0 )
      goto LABEL_368;
    v411 = v690.size;
  }
  v690.num = v418;
  if ( v418 >= v411 )
    v690.num = v411;
LABEL_368:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v686,
                            newsize: v418) == 0 )
      goto LABEL_373;
    v412 = v686.size;
  }
  v686.num = v418;
  if ( v418 >= v412 )
    v686.num = v412;
LABEL_373:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v688,
                            newsize: v418) == 0 )
      goto LABEL_378;
    v413 = v688.size;
  }
  v688.num = v418;
  if ( v418 >= v413 )
    v688.num = v413;
LABEL_378:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v691,
                            newsize: v418) == 0 )
      goto LABEL_383;
    v414 = v691.size;
  }
  v691.num = v418;
  if ( v418 >= v414 )
    v691.num = v414;
LABEL_383:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v693,
                            newsize: v418) == 0 )
      goto LABEL_388;
    v415 = v693.size;
  }
  v693.num = v418;
  if ( v418 >= v415 )
    v693.num = v415;
LABEL_388:
  if ( v418 > 0 )
  {
    if ( (unsigned __int8)idList<idList<unsigned char,5>,5>::Resize(
                            this: (idList<idList<unsigned char,5>,5> *)&v681,
                            newsize: v418) == 0 )
      goto LABEL_393;
    v416 = v681.size;
  }
  v681.num = v418;
  if ( v418 >= v416 )
    v681.num = v416;
LABEL_393:
  v662.granularity = 18 * v418 + 128;
  if ( v418 > 0 )
  {
    v420 = (idList<unsigned char,37> *)v410;
    v421 = v668;
    v422 = v657;
    v423 = v665;
    granularity = (unsigned __int16)v662.granularity;
    v425 = v674.num;
    v426 = v663;
    v656 = v666;
    v658 = nullptr;
    v667 = v669.list;
    do
    {
      v427 = *(int *)((char *)mappedSkeletons->list + (unsigned int)v658);
      if ( v427 != 0 )
      {
        v428 = &v668;
        HIWORD(v668) = *(_WORD *)(*(_DWORD *)(v427 + 40) + 6);
      }
      else
      {
        v428 = &v665;
        HIWORD(v665) = -1;
      }
      HIWORD(v657) = *(_WORD *)v428;
      idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Append(
        this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,30> *)&v722,
        obj: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v657);
      v429 = (idList<unsigned char,37> *)((char *)v420 + (char *)v694.list - (char *)v410);
      HIWORD(v670.list) = v417 + granularity;
      v431 = _idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
               sourceSkeleton: skel,
               targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
               num: v421,
               bits: (const idList<unsigned char,5> *)&v700,
               RLE: v429,
               a6: v430,
               a7: v417 + granularity,
               a8: (int)v694.list,
               a9: (int)v551,
               a10: (int)v560,
               a11: (int)v569,
               a12: (int)v578,
               a13: (int)v587,
               a14: (int)v596,
               a15: (int)v605,
               a16: (unsigned __int8)v614)
           + v417;
      v432 = (idList<unsigned char,37> *)((char *)v420 + (char *)v692.list - (char *)v410);
      LOWORD(v670.list) = v431 + granularity;
      v435 = (unsigned __int16)(_idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
                                  sourceSkeleton: skel,
                                  targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
                                  num: v422,
                                  bits: (const idList<unsigned char,5> *)&v698,
                                  RLE: v432,
                                  a6: v434,
                                  a7: v433,
                                  a8: (char *)v692.list - (char *)v410,
                                  a9: v552,
                                  a10: v561,
                                  a11: v570,
                                  a12: v579,
                                  a13: v588,
                                  a14: v597,
                                  a15: v606,
                                  a16: v618)
                              + v431);
      HIWORD(v670.num) = v435 + granularity;
      LOWORD(v435) = _idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
                       sourceSkeleton: skel,
                       targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
                       num: v423,
                       bits: (const idList<unsigned char,5> *)&v696,
                       RLE: v420,
                       a6: v437,
                       a7: v436,
                       a8: v435 + granularity,
                       a9: v553,
                       a10: v562,
                       a11: v571,
                       a12: v580,
                       a13: v589,
                       a14: v598,
                       a15: v607,
                       a16: v619)
                   + v435;
      v438 = (idList<unsigned char,37> *)((char *)v420 + (char *)v686.list - (char *)v410);
      LOWORD(v670.num) = v435 + granularity;
      v440 = (unsigned __int16)(_idMD6Anim::CompressAnim_::_2_::local_t::GenerateUserChannelRLE(
                                  sourceSkeleton: (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)skel,
                                  targetSkeleton: (idIndex<short,enum invalidUserChannelIndex_t> *)v427,
                                  numPaddedUserChannels_: v659,
                                  num: v425,
                                  bits: (const idList<unsigned char,5> *)&v703,
                                  RLE: v438,
                                  a7: v439,
                                  a8: (char *)v686.list - (char *)v410,
                                  a9: v554,
                                  a10: v563,
                                  a11: v572,
                                  a12: v581,
                                  a13: v590,
                                  a14: v599,
                                  a15: v608,
                                  a16: v615,
                                  a17: v623,
                                  a18: v626)
                              + v435);
      v441 = (idList<unsigned char,37> *)((char *)v420 + (char *)v688.list - (char *)v410);
      HIWORD(v670.size) = v440 + granularity;
      JointRLE = _idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
                   sourceSkeleton: skel,
                   targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
                   num: v426,
                   bits: (const idList<unsigned char,5> *)&v675,
                   RLE: v441,
                   a6: v443,
                   a7: v442,
                   a8: v440 + granularity,
                   a9: v555,
                   a10: v564,
                   a11: v573,
                   a12: v582,
                   a13: v591,
                   a14: v600,
                   a15: v609,
                   a16: v620);
      v445 = (idList<unsigned char,37> *)((char *)v420 + (char *)v691.list - (char *)v410);
      v446 = (unsigned __int16)(JointRLE + v440);
      LOWORD(v670.size) = v446 + granularity;
      v448 = _idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
               sourceSkeleton: skel,
               targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
               num: v664,
               bits: (const idList<unsigned char,5> *)&v671,
               RLE: v445,
               a6: (int)v691.list,
               a7: v447,
               a8: (char *)v691.list - (char *)v410,
               a9: v556,
               a10: v565,
               a11: v574,
               a12: v583,
               a13: v592,
               a14: v601,
               a15: v610,
               a16: v621);
      v449 = v448 + v446;
      LOWORD(v446) = v448 + v446;
      v450 = (idList<unsigned char,37> *)((char *)v420 + (char *)v693.list - (char *)v410);
      v670.granularity = v446 + granularity;
      v451 = (unsigned __int16)(_idMD6Anim::CompressAnim_::_2_::local_t::GenerateJointRLE(
                                  sourceSkeleton: skel,
                                  targetSkeleton: (idIndex<short,enum invalidJointIndex_t> *)v427,
                                  num: v662.size,
                                  bits: (const idList<unsigned char,5> *)&v673,
                                  RLE: v450,
                                  a6: v662.size,
                                  a7: v449,
                                  a8: (char *)v693.list - (char *)v410,
                                  a9: v557,
                                  a10: v566,
                                  a11: v575,
                                  a12: v584,
                                  a13: v593,
                                  a14: v602,
                                  a15: v611,
                                  a16: v622)
                              + v446);
      v452 = (idList<unsigned char,37> *)((char *)v420 + (char *)v681.list - (char *)v410);
      *(_WORD *)&v670.memTag = v451 + granularity;
      v417 = _idMD6Anim::CompressAnim_::_2_::local_t::GenerateUserChannelRLE(
               sourceSkeleton: (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)skel,
               targetSkeleton: (idIndex<short,enum invalidUserChannelIndex_t> *)v427,
               numPaddedUserChannels_: v659,
               num: v656,
               bits: (const idList<unsigned char,5> *)&v682,
               RLE: v452,
               a7: v453,
               a8: v451 + granularity,
               a9: v558,
               a10: v567,
               a11: v576,
               a12: v585,
               a13: v594,
               a14: v603,
               a15: v612,
               a16: v616,
               a17: v624,
               a18: v628)
           + v451;
      if ( v427 != 0 )
      {
        idMD6Anim::VerifyRLEData(
          this,
          animName: this->name.str,
          RRLE: (const idList<unsigned char,5> *)v429,
          SRLE: (const idList<unsigned char,5> *)v432,
          TRLE: (const idList<unsigned char,5> *)v420,
          URLE: (const idList<unsigned char,5> *)v438,
          RBits: (const idList<unsigned char,5> *)&v700,
          SBits: (const idList<unsigned char,5> *)&v698,
          TBits: (const idList<unsigned char,5> *)v551,
          UBits: (const idList<unsigned char,5> *)v560,
          a11: (int)v569,
          a12: (int)v578,
          a13: (int)v587,
          a14: (int)v596,
          a15: (int)v605,
          a16: (int)v614,
          a17: v623,
          a18: v626,
          a19: v629,
          a20: v631,
          a21: v633,
          a22: v635,
          a23: v637,
          a24: v639,
          a25: v641,
          a26: v643,
          a27: v645,
          a28: (int)&v696,
          a29: v648,
          a30: (int)&v703);
        idMD6Anim::VerifyRLEData(
          this,
          animName: this->name.str,
          RRLE: (const idList<unsigned char,5> *)v441,
          SRLE: (const idList<unsigned char,5> *)v445,
          TRLE: (const idList<unsigned char,5> *)v450,
          URLE: (const idList<unsigned char,5> *)v452,
          RBits: (const idList<unsigned char,5> *)&v675,
          SBits: (const idList<unsigned char,5> *)&v671,
          TBits: v559,
          UBits: v568,
          a11: v577,
          a12: v586,
          a13: v595,
          a14: v604,
          a15: v613,
          a16: v617,
          a17: v625,
          a18: v627,
          a19: v630,
          a20: v632,
          a21: v634,
          a22: v636,
          a23: v638,
          a24: v640,
          a25: v642,
          a26: v644,
          a27: v646,
          a28: (int)&v673,
          a29: v649,
          a30: (int)&v682);
      }
      idList<animMapOffsets_t,5>::Append(
        this: (idList<animMapOffsets_t,5> *)&v705,
        obj: (const animMapOffsets_t *)&v670);
      ++v420;
      --v667;
      v658 += 4;
    }
    while ( v667 != nullptr );
  }
  memset(v721, 0, sizeof(v721));
  v454 = v677.num;
  v455 = v660;
  v456 = maskSJoints_2;
  v711[9] = maskUChannels_2;
  v711[8] = maskTJointsa;
  v711[7] = maskSJoints_2;
  v714 = v722.num;
  v711[10] = v677.num;
  if ( v660 > 0 )
  {
    v456 = maskSJoints_2 | 0x400;
    v711[7] = maskSJoints_2 | 0x400;
  }
  if ( v659 > 0 )
    v711[7] = v456 | 0x800;
  if ( idMD6Anim::skipJoints || v660 == 0 )
  {
    v721[4] = 1.0;
    v721[5] = 1.0;
    v721[6] = 1.0;
    v721[7] = 1.0;
    x = quat_identity.x;
    y = quat_identity.y;
    z = quat_identity.z;
    w = quat_identity.w;
    v721[8] = vec4_origin.x;
    v721[9] = vec4_origin.y;
    v721[10] = vec4_origin.z;
    v721[11] = vec4_origin.w;
  }
  else
  {
    v721[11] = 0.0;
    v457 = (maskTJointsa - 1) * v660;
    v721[23] = 0.0;
    v721[7] = 1.0;
    v458 = rotation->list;
    v721[19] = 1.0;
    x = *v458;
    y = v458[1];
    z = v458[2];
    w = v458[3];
    v463 = &v458[4 * v457];
    v464 = scale->list[1];
    v457 *= 12;
    v465 = scale->list[2];
    v466 = *translation->list;
    v467 = translation->list[1];
    v468 = (float *)((char *)translation->list + v457);
    v469 = translation->list[2];
    v470 = *v463;
    v471 = v463[1];
    v472 = v463[2];
    v473 = v463[3];
    v474 = *(float *)((char *)scale->list + v457);
    v475 = *(float *)((char *)scale->list + v457 + 4);
    v476 = *(float *)((char *)scale->list + v457 + 8);
    v477 = *v468;
    v478 = v468[1];
    v479 = v468[2];
    v721[4] = *scale->list;
    v721[5] = v464;
    v721[6] = v465;
    v721[8] = v466;
    v721[9] = v467;
    v721[10] = v469;
    v721[12] = v470;
    v721[13] = v471;
    v721[14] = v472;
    v721[15] = v473;
    v721[16] = v474;
    v721[17] = v475;
    v721[18] = v476;
    v721[20] = v477;
    v721[21] = v478;
    v721[22] = v479;
  }
  memset(&v670, 0, 14);
  v662.list = (char *)(2 * v697.num);
  *(_WORD *)&v670.memTag = 1280;
  v721[3] = w;
  v672.list = (char *)(4 * v704.num);
  v721[2] = z;
  v721[1] = y;
  v716 = (((v662.granularity + v417 + 15) & 0xFFF0) + 2 * HIWORD(v697.num) + 15) & 0xFFF0;
  v721[0] = x;
  v715 = (v662.granularity + v417 + 15) & 0xFFF0;
  v674.list = (char *)(4 * v702.num);
  v717 = (v716 + 4 * HIWORD(v704.num) + 15) & 0xFFF0;
  v480 = (v717 + 4 * HIWORD(v702.num) + 15) & 0xFFF0;
  v718 = v480;
  idList<idThread *,58>::Clear(this: &v670);
  v481 = 0;
  v482 = 0;
  v720 = 0;
  v483 = 0;
  v678.list = *(char **)(a34 + 4);
  if ( (int)v678.list > 0 )
  {
    v484 = 0;
    while ( *(float *)(*(_DWORD *)a34 + v484) >= 1.0 )
    {
      ++v483;
      v484 += 4;
      if ( v483 >= (int)v678.list )
        goto LABEL_415;
    }
    v482 = v455;
    v481 = (4 * HIWORD(v689.num) + v480 + 15) & 0xFFF0;
    v720 = (4 * LOWORD(v689.num) + v480 + 15) & 0xFFF0;
  }
LABEL_415:
  v485 = v482;
  if ( v482 != 0 )
  {
    idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v670, newNum: v455);
    v486 = v670.list;
    v487 = 0;
    HIWORD(v657) = *(_WORD *)(*(_DWORD *)&skel[20].value + 2);
    v488 = HIWORD(v657);
    if ( HIWORD(v657) != 0 )
    {
      v489 = 0;
      do
      {
        v678.num = (int)(float)(*(float *)(*(_DWORD *)a34 + v489) * (float)255.0);
        v490 = v678.num;
        if ( v678.num >= 0 )
        {
          if ( v678.num > 255 )
            v490 = -1;
        }
        else
        {
          v490 = 0;
        }
        *((_BYTE *)v486 + v487++) = v490;
        v489 += 4;
        HIWORD(v657) = *(_WORD *)(*(_DWORD *)&skel[20].value + 2);
        v488 = HIWORD(v657);
      }
      while ( v487 < HIWORD(v657) );
    }
    v491 = v488;
    HIWORD(v657) = v488;
    if ( v488 < v455 )
    {
      v492 = v455 - v488;
      v494 = v455 == v491;
      v493 = (int)v486 + v491 - 1;
      if ( !v494 )
      {
        v495 = v492;
        do
        {
          *(_BYTE *)++v493 = 0;
          --v495;
        }
        while ( v495 != 0 );
      }
    }
    v496 = v481 + v485;
  }
  else
  {
    v496 = 4 * HIWORD(v689.num) + v480;
  }
  v712 = (v496 + 15) & 0xFFF0;
  v713 = (v712 + LOWORD(v687.num) + 15) & 0xFFF0;
  v678.list = (char *)(4 * v699.num);
  v497 = (v713 + 4 * LOWORD(v699.num) + 15) & 0xFFF0;
  v711[6] = (v713 + 4 * LOWORD(v699.num) + 15) & 0xFFF0;
  v719 = (4 * v666
        + ((12 * LOWORD(v662.size) + ((12 * v664 + ((6 * v663 + 63) & 0xFFF0) + 15) & 0xFFF0) + 15) & 0xFFF0)
        + 15)
       & 0xFFF0;
  if ( v454 > 0 )
  {
    v498 = v677.list;
    v499 = v454;
    v500 = (char *)v699.list - (char *)v677.list;
    do
    {
      *(idVehicleState **)((char *)v498 + v500) = (idVehicleState *)(v497 >> 4);
      len_high = HIWORD((*v498++)->debugName.len);
      v497 = (len_high + v497 + 15) & 0xFFFFFFF0;
      --v499;
    }
    while ( v499 != 0 );
  }
  *(_DWORD *)&v711[4] = v497;
  v502 = (idMD6AnimData *)idMem::AllocWithLocation(
                            this: (idMem *)v678.size,
                            location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Anim.cpp(2004) : TAG_MD6_ANIMS",
                            size: v497,
                            tag: TAG_MD6_ANIMS,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v503 = v711;
  v504 = (_QWORD *)&v502[-1].endDelta[10];
  this->animData = v502;
  for ( n = 16; n != 0; --n )
    *++v504 = *++v503;
  memcpy(Dst: &this->animData[1], Src: v722.list, Size: 2 * v722.num);
  memcpy(Dst: (char *)&this->animData[1] + 2 * this->animData->numAnimMaps, Src: v705.list, Size: 16 * v705.num);
  if ( (int)v669.list > 0 )
  {
    v506 = 0;
    p_num = &v692.list->num;
    v508 = (char *)v694.list - (char *)v692.list;
    v509 = (char *)v410 - (char *)v692.list;
    v510 = (char *)v686.list - (char *)v692.list;
    v511 = (char *)v688.list - (char *)v692.list;
    v512 = v669.list;
    v513 = (char *)v691.list - (char *)v692.list;
    v514 = (char *)v693.list - (char *)v692.list;
    v515 = (char *)v681.list - (char *)v692.list;
    v516 = (char *)((char *)v694.list - (char *)v410);
    v517 = (char *)((char *)v686.list - (char *)v410);
    v518 = (char *)((char *)v688.list - (char *)v410);
    v519 = (char *)((char *)v691.list - (char *)v410);
    v520 = (char *)((char *)v693.list - (char *)v410);
    v521 = (char *)((char *)v681.list - (char *)v410);
    do
    {
      memcpy(
        Dst: (char *)this->animData
      + *((unsigned __int16 *)&this->animData[1].totalSize + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v516[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v508));
      memcpy(
        Dst: (char *)this->animData
      + *((unsigned __int16 *)&this->animData[1].totalSize + this->animData->numAnimMaps + v506 + 1),
        Src: (const void *)*(p_num - 1),
        Size: *p_num);
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].size + this->animData->numAnimMaps + v506),
        Src: v410->list,
        Size: *(int *)((char *)p_num + v509));
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].flags + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v517[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v510));
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].numFrames + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v518[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v511));
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].frameRate + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v519[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v513));
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].numFrameSets + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v520[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v514));
      memcpy(
        Dst: (char *)this->animData + *(&this->animData[1].frameSetTblOffset + this->animData->numAnimMaps + v506),
        Src: *(const void **)&v521[(_DWORD)v410],
        Size: *(int *)((char *)p_num + v515));
      --v512;
      p_num += 4;
      ++v410;
      v506 += 8;
    }
    while ( v512 != nullptr );
  }
  v522 = this;
  memcpy(Dst: (char *)this->animData + this->animData->constROffset, Src: v697.list, Size: (size_t)v662.list);
  memcpy(Dst: (char *)v522->animData + v522->animData->constSOffset, Src: v704.list, Size: (size_t)v672.list);
  memcpy(Dst: (char *)v522->animData + v522->animData->constTOffset, Src: v702.list, Size: (size_t)v674.list);
  memcpy(Dst: (char *)v522->animData + v522->animData->constUOffset, Src: v689.list, Size: 4 * v689.num);
  animData = this->animData;
  if ( animData->jointWeightsOffset != 0 )
    memcpy(Dst: (char *)animData + animData->jointWeightsOffset, Src: v670.list, Size: v670.num);
  memcpy(Dst: (char *)this->animData + this->animData->frameSetTblOffset, Src: v687.list, Size: v687.num);
  memcpy(Dst: (char *)this->animData + this->animData->frameSetOffsetTblOffset, Src: v699.list, Size: (size_t)v678.list);
  v524 = v677.num;
  v525 = v677.list;
  v526 = nullptr;
  if ( v677.num > 0 )
  {
    v527 = 0;
    for ( ii = v677.num; ii != 0; --ii )
    {
      v529 = this->animData;
      v530 = (unsigned __int16 *)v525[v527];
      v531 = v530[16];
      v532 = v529->frameSetOffsetTblOffset + v527 * 4;
      v662.list = (char *)v529;
      v533 = (_WORD *)v529 + 8 * *(unsigned int *)((char *)&v529->totalSize + v532);
      memcpy(Dst: v533, Src: v530, Size: v531);
      qmemcpy(v533 + 19, "_FRAMESET_", 10);
      if ( v526 != nullptr )
      {
        v534 = v533[3] + (_WORD)v533;
        v535 = v533[1] + (_WORD)v533 - (_WORD)v526;
        v536 = v533[2] + (_WORD)v533 - (_WORD)v526;
        v526[12] = *v533 + (_WORD)v533 - (_WORD)v526;
        v526[13] = v535;
        v526[14] = v536;
        v526[15] = v534 - (_WORD)v526;
      }
      v526 = v533;
      ++v527;
    }
    v537 = v533[1];
    v538 = v533[2];
    v539 = v533[3];
    v533[12] = *v533;
    v533[13] = v537;
    v533[14] = v538;
    v533[15] = v539;
  }
  v540 = this->animData;
  v541 = 9 * v660 + v659;
  v542 = v540->frameSetOffsetTblOffset + 4 * v661;
  v543 = (unsigned __int16)(v540->totalSize >> 4);
  v662.list = (char *)v540;
  *(unsigned int *)((char *)&v540->totalSize + v542) = v543;
  str = this->name.str;
  v545 = this->animData;
  v546 = v545->numFrames;
  totalSize = v545->totalSize;
  __twllei(v545->totalSize, 0);
  v662.list = (char *)v545;
  idLib::Printf(fmt: "%s (%d : 1)\n", str, 4 * v541 * v546 / totalSize);
  if ( v524 > 0 )
  {
    v548 = (idMem *)v678.size;
    v549 = (void **)(v525 - 1);
    for ( jj = v524; jj != 0; --jj )
      idMem::Free(this: v548, ptr: *++v549, align: ALIGN_16);
  }
  idList<idThread *,58>::Clear(this: &v670);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v681);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v693);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v691);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v688);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v686);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v690);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v692);
  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: &v694);
  idList<idThread *,58>::Clear(this: &v705);
  idList<idThread *,58>::Clear(this: &v722);
  idList<idThread *,58>::Clear(this: &v677);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v699);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v687);
  idList<idThread *,58>::Clear(this: &v724);
  idList<idThread *,58>::Clear(this: &v726);
  idList<idThread *,58>::Clear(this: &v728);
  idList<idThread *,58>::Clear(this: &v680);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v676);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v682);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v673);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v671);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v675);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v703);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v696);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v698);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v700);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v689);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v702);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v704);
  idList<idThread *,58>::Clear(this: &v697);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v679);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v684);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v685);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v683);
}


// ========================================================================
// $LN1890
// EA  : 0x82833C44
// RVA : 0x00833C44
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN1890()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 432));
}


// ========================================================================
// __unwind$244796_0
// EA  : 0x82833C6C
// RVA : 0x00833C6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244796_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 464));
}


// ========================================================================
// __unwind$244797_0
// EA  : 0x82833C94
// RVA : 0x00833C94
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244797_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 448));
}


// ========================================================================
// __unwind$244798
// EA  : 0x82833CBC
// RVA : 0x00833CBC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244798()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 368));
}


// ========================================================================
// __unwind$244799
// EA  : 0x82833CE4
// RVA : 0x00833CE4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244799()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 656));
}


// ========================================================================
// __unwind$244800
// EA  : 0x82833D0C
// RVA : 0x00833D0C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244800()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 768));
}


// ========================================================================
// __unwind$244801
// EA  : 0x82833D34
// RVA : 0x00833D34
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244801()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 736));
}


// ========================================================================
// __unwind$244802
// EA  : 0x82833D5C
// RVA : 0x00833D5C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244802()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 528));
}


// ========================================================================
// __unwind$244803
// EA  : 0x82833D84
// RVA : 0x00833D84
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 704));
}


// ========================================================================
// __unwind$244804
// EA  : 0x82833DAC
// RVA : 0x00833DAC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244804()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 672));
}


// ========================================================================
// __unwind$244805
// EA  : 0x82833DD4
// RVA : 0x00833DD4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 640));
}


// ========================================================================
// __unwind$244806
// EA  : 0x82833DFC
// RVA : 0x00833DFC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244806()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 752));
}


// ========================================================================
// __unwind$244807
// EA  : 0x82833E24
// RVA : 0x00833E24
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244807()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 304));
}


// ========================================================================
// __unwind$244808
// EA  : 0x82833E4C
// RVA : 0x00833E4C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244808()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 240));
}


// ========================================================================
// __unwind$244809
// EA  : 0x82833E74
// RVA : 0x00833E74
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244809()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 272));
}


// ========================================================================
// __unwind$244810
// EA  : 0x82833E9C
// RVA : 0x00833E9C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244810()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 416));
}


// ========================================================================
// __unwind$244811
// EA  : 0x82833EC4
// RVA : 0x00833EC4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244811()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 320));
}


// ========================================================================
// __unwind$244812
// EA  : 0x82833EEC
// RVA : 0x00833EEC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244812()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 384));
}


// ========================================================================
// __unwind$244813
// EA  : 0x82833F14
// RVA : 0x00833F14
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244813()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 9456));
}


// ========================================================================
// __unwind$244814
// EA  : 0x82833F3C
// RVA : 0x00833F3C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244814()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 5344));
}


// ========================================================================
// __unwind$244815
// EA  : 0x82833F64
// RVA : 0x00833F64
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244815()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 1232));
}


// ========================================================================
// __unwind$244816
// EA  : 0x82833F8C
// RVA : 0x00833F8C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244816()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 496));
}


// ========================================================================
// __unwind$244817
// EA  : 0x82833FB4
// RVA : 0x00833FB4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244817()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 688));
}


// ========================================================================
// __unwind$244818
// EA  : 0x82833FDC
// RVA : 0x00833FDC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244818()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 336));
}


// ========================================================================
// __unwind$244819
// EA  : 0x82834004
// RVA : 0x00834004
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244819()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 960));
}


// ========================================================================
// __unwind$244820
// EA  : 0x8283402C
// RVA : 0x0083402C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244820()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 784));
}


// ========================================================================
// __unwind$244821
// EA  : 0x82834054
// RVA : 0x00834054
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244821()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 608));
}


// ========================================================================
// __unwind$244822
// EA  : 0x8283407C
// RVA : 0x0083407C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244822()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 576));
}


// ========================================================================
// __unwind$244823
// EA  : 0x828340A4
// RVA : 0x008340A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244823()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 544));
}


// ========================================================================
// __unwind$244824
// EA  : 0x828340CC
// RVA : 0x008340CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244824()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 480));
}


// ========================================================================
// __unwind$244825
// EA  : 0x828340F4
// RVA : 0x008340F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244825()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 512));
}


// ========================================================================
// __unwind$244826
// EA  : 0x8283411C
// RVA : 0x0083411C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244826()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 560));
}


// ========================================================================
// __unwind$244827
// EA  : 0x82834144
// RVA : 0x00834144
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244827()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 592));
}


// ========================================================================
// __unwind$244828
// EA  : 0x8283416C
// RVA : 0x0083416C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244828()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(v0 - 13776 + 400));
}


// ========================================================================
// __unwind$244829
// EA  : 0x82834194
// RVA : 0x00834194
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_244829()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 13776 + 224));
}


// ========================================================================
// ?LoadFacetracksComposite@idMD6Anim@@AAA_NABUanimationSettings_t@1@PBDPBVidMD6Skel@@ABV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@33ABV?$idList@M$04@@@Z
// EA  : 0x828341C8
// RVA : 0x008341C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int __fastcall idMD6Anim::LoadFacetracksComposite(
        idMD6Anim *this,
        const idList<float,5> *settings,
        const char *basePath,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *skeleton,
        const idList<idIndex<short,enum invalidJointIndex_t>,5> *maskRJoints,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *maskSJoints,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *maskTJoints,
        const idList<float,5> *jointWeights,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        idIndex<short,enum invalidJointIndex_t> *a18,
        int a19,
        const idList<idIndex<short,enum invalidJointIndex_t>,5> *a20,
        int a21,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *a22,
        int a23,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *a24,
        int a25,
        const idList<float,5> *a26)
{
  int v27; // r3
  const char *networkID; // r23
  int v29; // r26
  int resourceError; // r21
  int v31; // r28
  const char *v32; // r3
  __int16 value; // r11
  int v34; // r29
  const char *v35; // r30
  bool v36; // cr56
  bool v37; // r3
  idStr *v38; // r30
  size_t len; // r29
  int v41; // r11
  int v42; // r27
  int v43; // r30
  float *list; // r8
  int v45; // r9
  int i; // r7
  int v47; // r11
  int v48; // ctr
  float *v49; // r10
  int v50; // r26
  _WORD *v51; // r25
  int j; // r23
  int v53; // r25
  int v54; // r21
  idResourceList *resourceListPtr; // r22
  idStr *v56; // r3
  __int64 v57; // r10
  __int64 v58; // r8
  bool v59; // r3
  __int64 v60; // r6
  int k; // r11
  int m; // r11
  int n; // r11
  int ii; // r11
  int v65; // r27
  int jj; // r30
  int v67; // r30
  __int64 v68; // r10
  __int64 v69; // r8
  __int64 v70; // r6
  int kk; // r11
  int mm; // r11
  int nn; // r11
  int i1; // r11
  int v75; // r27
  int i2; // r30
  unsigned int fileTime; // r11
  char v78; // r22
  int v79; // r26
  int v80; // r11
  char v81; // r3
  int v82; // r28
  idIndex<short,enum invalidJointIndex_t> *v83; // r27
  int i3; // r29
  int v85; // r30
  int i4; // r27
  int v87; // r30
  int v88; // r28
  int v89; // r29
  int v90; // r11
  double v91; // fp0
  double v92; // fp0
  double v93; // fp0
  idResourceList *v94; // r27
  int v95; // r30
  idStr *v96; // r29
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v97; // [sp+8h] [-5F8h]
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v98; // [sp+Ch] [-5F4h]
  const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *v99; // [sp+10h] [-5F0h]
  const idList<float,5> *v100; // [sp+14h] [-5ECh]
  int v101; // [sp+18h] [-5E8h]
  int v102; // [sp+1Ch] [-5E4h]
  int v103; // [sp+20h] [-5E0h]
  const idMD6Anim::animationSettings_t *v104; // [sp+24h] [-5DCh]
  int v105; // [sp+28h] [-5D8h]
  int v106; // [sp+2Ch] [-5D4h]
  int v107; // [sp+30h] [-5D0h]
  int v108; // [sp+34h] [-5CCh]
  int v109; // [sp+38h] [-5C8h]
  int v110; // [sp+3Ch] [-5C4h]
  int v111; // [sp+40h] [-5C0h]
  int v112; // [sp+44h] [-5BCh]
  int v113; // [sp+48h] [-5B8h]
  int v114; // [sp+4Ch] [-5B4h]
  int v115; // [sp+50h] [-5B0h]
  int v116; // [sp+58h] [-5A8h]
  int v117; // [sp+60h] [-5A0h]
  int v118; // [sp+68h] [-598h]
  int v119; // [sp+70h] [-590h]
  int v120; // [sp+78h] [-588h]
  int v121; // [sp+80h] [-580h]
  int v122; // [sp+88h] [-578h]
  idMD6Skel v123; // [sp+90h] [-570h] BYREF
  int v124; // [sp+C4h] [-53Ch]
  int v125; // [sp+C8h] [-538h]
  __int16 v126; // [sp+CCh] [-534h]
  char v127; // [sp+CEh] [-532h]
  char v128; // [sp+CFh] [-531h]
  idList<float,32> v129; // [sp+D0h] [-530h] BYREF
  idList<float,32> v130; // [sp+E0h] [-520h] BYREF
  _WORD v131[8]; // [sp+F0h] [-510h] BYREF
  idList<float,5> v132; // [sp+100h] [-500h] BYREF
  idList<enum encounterGroupRole_t,5> v133; // [sp+110h] [-4F0h] BYREF
  int v134; // [sp+120h] [-4E0h] BYREF
  const char *v135; // [sp+124h] [-4DCh]
  const char *v136; // [sp+128h] [-4D8h]
  const char *v137; // [sp+12Ch] [-4D4h]
  const char *v138; // [sp+130h] [-4D0h]
  int v139; // [sp+134h] [-4CCh]
  const char *v140; // [sp+138h] [-4C8h]
  const char *v141; // [sp+13Ch] [-4C4h]
  const char *v142; // [sp+140h] [-4C0h]
  _BYTE v143[14]; // [sp+150h] [-4B0h] BYREF
  __int16 v144; // [sp+15Eh] [-4A2h]
  idStr v145; // [sp+160h] [-4A0h] BYREF
  idToken v146; // [sp+180h] [-480h] BYREF
  idStr v147; // [sp+1D0h] [-430h] BYREF
  idToken v148; // [sp+1F0h] [-410h] BYREF
  idStr v149; // [sp+240h] [-3C0h] BYREF
  int v150; // [sp+274h] [-38Ch]
  float v151; // [sp+278h] [-388h]
  int v152; // [sp+27Ch] [-384h]
  int v153; // [sp+280h] [-380h]
  int v154; // [sp+284h] [-37Ch]
  idStr v155; // [sp+290h] [-370h] BYREF
  idParser v156; // [sp+2B0h] [-350h] BYREF

  a18 = (idIndex<short,enum invalidJointIndex_t> *)skeleton;
  a20 = maskRJoints;
  a22 = maskSJoints;
  v123.staleCount = 1280;
  memset(&v123.resourceListPtr, 0, 12);
  a24 = maskTJoints;
  a26 = jointWeights;
  idList<idStr,3>::Resize(this: (idList<idStr,5> *)&v123.resourceListPtr, newsize: 128);
  v27 = animation->GetNumUserChannels(this: animation);
  networkID = (const char *)v123.networkID;
  v29 = v27;
  resourceError = (int)v123.resourceError;
  v31 = 0;
  if ( v27 > 0 )
  {
    while ( 1 )
    {
      v131[0] = v31;
      v32 = animation->GetUserChannelName(this: animation, a2: v131);
      idStr::idStr(this: &v147, text: v32);
      if ( idStr::Find(searchIn: v147.data, searchFor: "facedata_", casesensitive: true, start: 0, end: v147.len) == -1 )
        goto LABEL_14;
      value = idMD6Skel::GetUserChannelIndex(
                this: &v123,
                result: (idIndex<short,enum invalidUserChannelIndex_t> *)skeleton,
                name: v147.data)->value;
      v34 = value;
      if ( value == -1 )
        goto LABEL_14;
      v35 = (const char *)(value + 1);
      if ( (int)v35 <= resourceError )
        v35 = (const char *)resourceError;
      v36 = (int)v35 < (int)networkID;
      if ( (int)v35 <= (int)networkID )
        goto LABEL_9;
      v37 = idList<idStr,3>::Resize(this: (idList<idStr,5> *)&v123.resourceListPtr, newsize: (int)v35);
      networkID = (const char *)v123.networkID;
      if ( v37 )
        break;
      resourceError = (int)v123.resourceError;
LABEL_13:
      v38 = (idStr *)((char *)v123.resourceListPtr + 32 * v34);
      len = v147.len;
      idStr::EnsureAlloced(this: v38, amount: v147.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v38->data, Src: v147.data, Size: len);
      v38->data[len] = 0;
      v38->len = len;
LABEL_14:
      idStr::FreeData(this: &v147);
      if ( ++v31 >= v29 )
        goto LABEL_15;
    }
    v36 = (int)v35 < v123.networkID;
LABEL_9:
    if ( v36 )
    {
      resourceError = (int)v35;
      v123.resourceError = v35;
    }
    else
    {
      resourceError = (int)networkID;
      v123.resourceError = networkID;
    }
    goto LABEL_13;
  }
LABEL_15:
  if ( resourceError == 0 )
  {
    if ( (LOBYTE(v123.staleCount) == 0 || LOBYTE(v123.staleCount) == 2) && v123.resourceListPtr != nullptr )
      idListArrayDelete<idStr>(ptr: (idStr *)v123.resourceListPtr, num: (int)networkID);
    return 0;
  }
  v41 = *(unsigned __int16 *)(*(_DWORD *)&skeleton[20].value + 2);
  *(_WORD *)&v129.memTag = 1280;
  v42 = (v41 + 7) & 0x1FFF8;
  memset(&v129, 0, 14);
  v139 = v42;
  *(float *)&v123.__vftable = 0.0;
  idList<float,17>::SetNum(this: &v129, newNum: 4 * resourceError * v42, initValue: (float *)&v123);
  v123.timestamp = 1280;
  memset((char *)&v123.idResource + 32, 0, 12);
  v43 = 3 * resourceError * v42;
  *(float *)&v123.__vftable = 1.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&v123.idResource + 2, newNum: v43, initValue: (float *)&v123);
  *(_WORD *)&v130.memTag = 1280;
  memset(&v130, 0, 14);
  *(float *)&v123.__vftable = 0.0;
  idList<float,17>::SetNum(this: &v130, newNum: v43, initValue: (float *)&v123);
  if ( resourceError > 0 )
  {
    list = v129.list;
    v45 = 0;
    for ( i = resourceError; i != 0; --i )
    {
      if ( v42 > 0 )
      {
        v47 = v45 * 4;
        v48 = v42;
        v49 = &list[v45];
        do
        {
          v47 += 16;
          v49[3] = 1.0;
          list = v129.list;
          v49 = (float *)((char *)v129.list + v47);
          --v48;
        }
        while ( v48 != 0 );
      }
      v45 += 4 * v42;
    }
  }
  v50 = 0;
  v126 = 0;
  v127 = 5;
  v128 = 0;
  *(_DWORD *)&v123.jointConversion.value = 0;
  v125 = 0;
  v124 = 0;
  v51 = idListArrayResize<short>(voldptr: nullptr, oldNum: 0, newNum: 128, tag: TAG_IDLIST, zeroBuffer: false);
  *(_DWORD *)&v123.jointConversion.value = v51;
  if ( v51 != nullptr )
  {
    v50 = 128;
    v125 = 128;
  }
  v142 = "T";
  v135 = "S";
  v140 = "R";
  v138 = "frame";
  v141 = "frames";
  v137 = "idMD6Anim::LoadAnim_Text Joint not found in jointconversion: %s";
  v136 = "joints";
  for ( j = 0; j < resourceError; ++j )
  {
    v53 = 3 * j * v42;
    v54 = 4 * j * v42;
    idParser::idParser(this: &v156, flags: 262704);
    idStr::idStr(this: &v145, text: basePath);
    resourceListPtr = v123.resourceListPtr;
    v56 = operator+(result: &v155, a: (const idStr *)v123.resourceListPtr + j, b: ".md6anim");
    idStr::Append(this: &v145, text: v56);
    idStr::FreeData(this: &v155);
    while ( 1 )
    {
      if ( !idParser::LoadFile(this: &v156, filename: v145.data, OSPath: false) )
      {
        v59 = fileSystem->FileExists(this: fileSystem, a2: v145.data, a3: true);
        HIDWORD(v60) = v145.data;
        if ( v59 )
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Error parsing file for md6anim '%s'",
            a3: v60,
            a4: v58,
            a5: v57,
            a6: (int)v97,
            a7: (int)v98,
            a8: (int)v99,
            a9: (int)v100,
            a10: v101,
            a11: v102);
        else
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Missing file '%s'",
            a3: v60,
            a4: v58,
            a5: v57,
            a6: (int)v97,
            a7: (int)v98,
            a8: (int)v99,
            a9: (int)v100,
            a10: v101,
            a11: v102);
        idStr::FreeData(this: &v145);
        idParser::~idParser(this: &v156);
        if ( v128 == 0 || v128 == 2 )
        {
          if ( *(_DWORD *)&v123.jointConversion.value != 0 )
          {
            for ( k = 0; k < v50; ++k )
              ;
            idMem::Free(this: &mem, ptr: *(void **)&v123.jointConversion.value, align: ALIGN_16);
            *(_DWORD *)&v123.jointConversion.value = 0;
            v125 = 0;
          }
          else
          {
            *(_DWORD *)&v123.jointConversion.value = 0;
            v125 = 0;
          }
        }
        v124 = 0;
        if ( v130.listStatic == 0 || v130.listStatic == 2 )
        {
          if ( v130.list != nullptr )
          {
            for ( m = 0; m < v130.size; ++m )
              ;
            idMem::Free(this: &mem, ptr: v130.list, align: ALIGN_16);
          }
          v130.list = nullptr;
          v130.size = 0;
        }
        v130.num = 0;
        if ( LOBYTE(v123.timestamp) == 0 || LOBYTE(v123.timestamp) == 2 )
        {
          if ( *((_DWORD *)&v123.idResource + 8) != 0 )
          {
            for ( n = 0; n < (int)v123.data; ++n )
              ;
            idMem::Free(this: &mem, ptr: *((void **)&v123.idResource + 8), align: ALIGN_16);
          }
          *((_DWORD *)&v123.idResource + 8) = 0;
          v123.data = nullptr;
        }
        v123.defaultAnim = nullptr;
        if ( v129.listStatic == 0 || v129.listStatic == 2 )
        {
          if ( v129.list != nullptr )
          {
            for ( ii = 0; ii < v129.size; ++ii )
              ;
            idMem::Free(this: &mem, ptr: v129.list, align: ALIGN_16);
          }
          v129.list = nullptr;
          v129.size = 0;
        }
        v129.num = 0;
        if ( (LOBYTE(v123.staleCount) == 0 || LOBYTE(v123.staleCount) == 2) && resourceListPtr != nullptr )
        {
          v65 = v123.networkID;
          for ( jj = 0; jj < v65; ++jj )
            idStr::FreeData(this: (idStr *)resourceListPtr + jj);
          goto _M250273_0;
        }
        return 0;
      }
      idParser::ExpectTokenString(this: &v156, string: MD6_VERSION_STRING);
      v67 = idParser::ParseInt(this: &v156);
      if ( v67 == 7 )
        break;
      if ( (unsigned __int8)idMD6Anim::RewriteText(filename: v145.data) == 0 )
      {
        HIDWORD(v70) = v145.data;
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Error rewriting file for md6anim '%s'",
          a3: v70,
          a4: v69,
          a5: v68,
          a6: (int)v97,
          a7: (int)v98,
          a8: (int)v99,
          a9: (int)v100,
          a10: v101,
          a11: v102);
        idParser::Error(
          this: &v156,
          str: "MD6 anim '%s' has an invalid version %d. Should be version %d.",
          v145.data,
          v67,
          7);
        idStr::FreeData(this: &v145);
        idParser::~idParser(this: &v156);
        if ( v128 == 0 || v128 == 2 )
        {
          if ( *(_DWORD *)&v123.jointConversion.value != 0 )
          {
            for ( kk = 0; kk < v50; ++kk )
              ;
            idMem::Free(this: &mem, ptr: *(void **)&v123.jointConversion.value, align: ALIGN_16);
            *(_DWORD *)&v123.jointConversion.value = 0;
            v125 = 0;
          }
          else
          {
            *(_DWORD *)&v123.jointConversion.value = 0;
            v125 = 0;
          }
        }
        v124 = 0;
        if ( v130.listStatic == 0 || v130.listStatic == 2 )
        {
          if ( v130.list != nullptr )
          {
            for ( mm = 0; mm < v130.size; ++mm )
              ;
            idMem::Free(this: &mem, ptr: v130.list, align: ALIGN_16);
          }
          v130.list = nullptr;
          v130.size = 0;
        }
        v130.num = 0;
        if ( LOBYTE(v123.timestamp) == 0 || LOBYTE(v123.timestamp) == 2 )
        {
          if ( *((_DWORD *)&v123.idResource + 8) != 0 )
          {
            for ( nn = 0; nn < (int)v123.data; ++nn )
              ;
            idMem::Free(this: &mem, ptr: *((void **)&v123.idResource + 8), align: ALIGN_16);
          }
          *((_DWORD *)&v123.idResource + 8) = 0;
          v123.data = nullptr;
        }
        v123.defaultAnim = nullptr;
        if ( v129.listStatic == 0 || v129.listStatic == 2 )
        {
          if ( v129.list != nullptr )
          {
            for ( i1 = 0; i1 < v129.size; ++i1 )
              ;
            idMem::Free(this: &mem, ptr: v129.list, align: ALIGN_16);
          }
          v129.list = nullptr;
          v129.size = 0;
        }
        v129.num = 0;
        if ( (LOBYTE(v123.staleCount) == 0 || LOBYTE(v123.staleCount) == 2) && resourceListPtr != nullptr )
        {
          v75 = v123.networkID;
          for ( i2 = 0; i2 < v75; ++i2 )
            idStr::FreeData(this: (idStr *)resourceListPtr + i2);
_M250273_0:
          idMem::Free(this: &mem, ptr: resourceListPtr, align: ALIGN_16);
        }
        return 0;
      }
      idParser::FreeSource(this: &v156);
    }
    if ( v156.scriptstack != nullptr )
      fileTime = v156.scriptstack->fileTime;
    else
      fileTime = 0;
    if ( fileTime <= this->timestamp )
      fileTime = this->timestamp;
    v78 = 0;
    this->timestamp = fileTime;
    v146.floatvalue = -3.4028235e38;
    v146.len = 0;
    v146.data = v146.baseBuffer;
    v79 = 0;
    v146.allocedAndFlag = 20;
    v146.baseBuffer[0] = 0;
    v146.intvalue = 0;
    memset(&v146.whiteSpaceStart_p, 0, 12);
    v151 = -3.4028235e38;
    v149.allocedAndFlag = 20;
    v149.data = v149.baseBuffer;
    v149.len = 0;
    v149.baseBuffer[0] = 0;
    v150 = 0;
    v152 = 0;
    v153 = 0;
    v154 = 0;
    idParser::ExpectTokenString(this: &v156, string: "init");
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 46, token: &v146);
    while ( idParser::ReadToken(this: &v156, token: &v146) && (v146.type != 5 || v146.subtype != 47) )
    {
      if ( idStr::Icmp(s1: v146.data, s2: "numJoints") != 0 )
        idParser::SkipRestOfLine(this: &v156);
      else
        v79 = idParser::ParseInt(this: &v156);
    }
    v80 = v125;
    if ( v79 <= v125 )
    {
      v82 = *(_DWORD *)&v123.jointConversion.value;
    }
    else
    {
      v81 = idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)&v123.jointConversion, newsize: v79);
      v82 = *(_DWORD *)&v123.jointConversion.value;
      if ( v81 == 0 )
        goto LABEL_135;
      v80 = v125;
    }
    v124 = v79;
    if ( v79 >= v80 )
      v124 = v80;
LABEL_135:
    idParser::SkipUntilString(this: &v156, string: v136);
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 46, token: &v146);
    v83 = a18;
    for ( i3 = 0; i3 < v79; ++i3 )
    {
      v148.floatvalue = -3.4028235e38;
      v148.allocedAndFlag = 20;
      v148.data = v148.baseBuffer;
      v148.len = 0;
      v148.baseBuffer[0] = 0;
      v148.intvalue = 0;
      memset(&v148.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v156, type: 1, subtype: 0, token: &v148);
      v85 = (unsigned __int16)idMD6Skel::GetJointIndex(this: &v123, result: v83, name: v148.data)->value;
      if ( v85 == 0xFFFF )
        idParser::Error(this: &v156, str: v137, v146.data);
      *(_WORD *)(2 * i3 + v82) = v85;
      idParser::SkipRestOfLine(this: &v156);
      idStr::FreeData(this: &v148);
    }
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 47, token: &v146);
    idParser::SkipUntilString(this: &v156, string: v141);
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 46, token: &v146);
    idParser::ExpectTokenString(this: &v156, string: v138);
    idParser::ParseInt(this: &v156);
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 46, token: &v146);
    for ( i4 = 0; i4 < v79; ++i4 )
    {
      v87 = *(__int16 *)(2 * i4 + v82);
      idParser::ExpectTokenString(this: &v156, string: "joint");
      idParser::ParseInt(this: &v156);
      idParser::ExpectTokenType(this: &v156, type: 5, subtype: 46, token: &v146);
      idParser::ExpectTokenString(this: &v156, string: v140);
      if ( v87 >= 0 )
        idParser::Parse1DMatrix(this: &v156, x: 4, m: &v129.list[4 * v87 + v54]);
      else
        idParser::SkipRestOfLine(this: &v156);
      idParser::ExpectTokenString(this: &v156, string: v135);
      if ( v87 >= 0 )
      {
        v88 = 3 * v87 + v53;
        v89 = 4 * v88;
        idParser::Parse1DMatrix(this: &v156, x: 3, m: (float *)(*((_DWORD *)&v123.idResource + 8) + 4 * v88));
        v90 = *((_DWORD *)&v123.idResource + 8);
        v91 = *(float *)(*((_DWORD *)&v123.idResource + 8) + 4 * v88);
        if ( v91 < 0.0
          || v91 > 50.0
          || (v92 = *(float *)(*((_DWORD *)&v123.idResource + 8) + v89 + 4)) < 0.0
          || v92 > 50.0
          || (v93 = *(float *)(4 * (v88 + 2) + *((_DWORD *)&v123.idResource + 8))) < 0.0
          || v93 > 50.0 )
        {
          if ( v78 == 0 )
          {
            idParser::Warning(
              this: &v156,
              str: "Facetrack: %s Joint %d, scale out of range. This animation may have a 0 scale on the origin, which require"
              "s fixing and re-export.",
              *(&v123.resourceListPtr->resourceTypeName + 8 * j),
              v87);
            v90 = *((_DWORD *)&v123.idResource + 8);
            v78 = 1;
          }
          *(float *)(v90 + 4 * v88) = 1.0;
          *(float *)(*((_DWORD *)&v123.idResource + 8) + v89 + 4) = 1.0;
          *(float *)(4 * (v88 + 2) + *((_DWORD *)&v123.idResource + 8)) = 1.0;
        }
      }
      else
      {
        idParser::SkipRestOfLine(this: &v156);
      }
      idParser::ExpectTokenString(this: &v156, string: v142);
      if ( v87 >= 0 )
        idParser::Parse1DMatrix(this: &v156, x: 3, m: &v130.list[3 * v87 + v53]);
      else
        idParser::SkipRestOfLine(this: &v156);
      idParser::ExpectTokenType(this: &v156, type: 5, subtype: 47, token: &v146);
      v82 = *(_DWORD *)&v123.jointConversion.value;
    }
    idParser::ExpectTokenType(this: &v156, type: 5, subtype: 47, token: &v146);
    idStr::FreeData(this: &v149);
    idStr::FreeData(this: &v146);
    idStr::FreeData(this: &v145);
    idParser::~idParser(this: &v156);
    v51 = *(_WORD **)&v123.jointConversion.value;
    v42 = v139;
    resourceError = (int)v123.resourceError;
    v50 = v125;
  }
  *(_WORD *)&v132.memTag = 1280;
  memset(&v132, 0, 14);
  v144 = 1280;
  memset(v143, 0, sizeof(v143));
  *(_QWORD *)&v133.num = 1;
  v133.list = (encounterGroupRole_t *)&v134;
  *(_DWORD *)&v133.granularity = 66817;
  idList<idAnimWebBlendTree *,5>::Append(this: &v133, obj: (const encounterGroupRole_t *)&a18);
  idMD6Anim::CompressAnim(
    this,
    skel: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)a18,
    mappedSkeletons: (const idList<idMD6Skel const *,5> *)&v133,
    rotation: (const idList<float,5> *)&v129,
    scale: (const idList<float,5> *)&v123.idResource + 2,
    translation: (const idList<float,5> *)&v130,
    userChannels: &v132,
    maskRJoints: a20,
    maskSJoints: v97,
    maskTJoints: v98,
    maskUChannels: v99,
    jointWeights: v100,
    flags: v101,
    numFrames: v102,
    frameRate: v103,
    animSettings: v104,
    a17: v105,
    a18: v106,
    a19: v107,
    a20: v108,
    a21: v109,
    a22: v110,
    a23: v111,
    a24: v112,
    a25: v113,
    a26: v114,
    a27: v115,
    a28: a22,
    a29: v116,
    a30: a24,
    a31: v117,
    a32: v143,
    a33: v118,
    a34: (int)a26,
    a35: v119,
    maskSJoints_2: 32769,
    a37: v120,
    maskTJointsa: resourceError,
    a39: v121,
    maskUChannels_2: 30,
    a41: v122,
    jointWeightsa: settings);
  if ( v133.listStatic == 0 || v133.listStatic == 2 )
  {
    if ( v133.list != nullptr )
      idMem::Free(this: &mem, ptr: v133.list, align: ALIGN_16);
    v133.list = nullptr;
    v133.size = 0;
  }
  v133.num = 0;
  if ( v132.listStatic == 0 || v132.listStatic == 2 )
  {
    if ( v132.list != nullptr )
      idMem::Free(this: &mem, ptr: v132.list, align: ALIGN_16);
    v132.list = nullptr;
    v132.size = 0;
  }
  v132.num = 0;
  if ( (v128 == 0 || v128 == 2) && v51 != nullptr )
    idMem::Free(this: &mem, ptr: v51, align: ALIGN_16);
  if ( v130.listStatic == 0 || v130.listStatic == 2 )
  {
    if ( v130.list != nullptr )
      idMem::Free(this: &mem, ptr: v130.list, align: ALIGN_16);
    v130.list = nullptr;
    v130.size = 0;
  }
  v130.num = 0;
  if ( LOBYTE(v123.timestamp) == 0 || LOBYTE(v123.timestamp) == 2 )
  {
    if ( *((_DWORD *)&v123.idResource + 8) != 0 )
      idMem::Free(this: &mem, ptr: *((void **)&v123.idResource + 8), align: ALIGN_16);
    *((_DWORD *)&v123.idResource + 8) = 0;
    v123.data = nullptr;
  }
  v123.defaultAnim = nullptr;
  if ( v129.listStatic == 0 || v129.listStatic == 2 )
  {
    if ( v129.list != nullptr )
      idMem::Free(this: &mem, ptr: v129.list, align: ALIGN_16);
    v129.list = nullptr;
    v129.size = 0;
  }
  v129.num = 0;
  if ( LOBYTE(v123.staleCount) == 0 || LOBYTE(v123.staleCount) == 2 )
  {
    v94 = v123.resourceListPtr;
    if ( v123.resourceListPtr != nullptr )
    {
      v95 = v123.networkID;
      if ( v123.networkID > 0 )
      {
        v96 = (idStr *)v123.resourceListPtr;
        do
        {
          idStr::FreeData(this: v96);
          --v95;
          ++v96;
        }
        while ( v95 != 0 );
      }
      idMem::Free(this: &mem, ptr: v94, align: ALIGN_16);
    }
  }
  return 1;
}


// ========================================================================
// $M250406
// EA  : 0x82835268
// RVA : 0x00835268
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _M250406()
{
  idLib::Error(fmt: "idMD6Anim::LoadText - %s", idException::error);
  JUMPOUT(0x82835288);
}


// ========================================================================
// $M250409
// EA  : 0x82835290
// RVA : 0x00835290
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int _M250409()
{
  idLib::Error(fmt: "idMD6Anim::LoadAnim_FaceTracks - %s", idException::error);
  return _LN903();
}


// ========================================================================
// $LN903
// EA  : 0x828352B0
// RVA : 0x008352B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN903()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1536 + 160));
}


// ========================================================================
// __unwind$248658
// EA  : 0x828352D8
// RVA : 0x008352D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248658()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 464));
}


// ========================================================================
// __unwind$248659
// EA  : 0x82835300
// RVA : 0x00835300
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248659()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 208));
}


// ========================================================================
// __unwind$248660
// EA  : 0x82835328
// RVA : 0x00835328
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248660()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 176));
}


// ========================================================================
// __unwind$248661
// EA  : 0x82835350
// RVA : 0x00835350
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248661()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 224));
}


// ========================================================================
// __unwind$248662
// EA  : 0x82835378
// RVA : 0x00835378
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248662()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 192));
}


// ========================================================================
// __unwind$248663
// EA  : 0x828353A0
// RVA : 0x008353A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248663()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1536 + 688));
}


// ========================================================================
// __unwind$248664
// EA  : 0x828353C8
// RVA : 0x008353C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248664()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 352));
}


// ========================================================================
// __unwind$248665
// EA  : 0x828353F0
// RVA : 0x008353F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 656));
}


// ========================================================================
// __unwind$248666
// EA  : 0x82835418
// RVA : 0x00835418
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 384));
}


// ========================================================================
// __unwind$248667
// EA  : 0x82835440
// RVA : 0x00835440
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248667()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 576));
}


// ========================================================================
// __unwind$248668
// EA  : 0x82835468
// RVA : 0x00835468
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248668()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1536 + 496));
}


// ========================================================================
// __unwind$248669
// EA  : 0x82835490
// RVA : 0x00835490
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248669()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 256));
}


// ========================================================================
// __unwind$248670_0
// EA  : 0x828354B8
// RVA : 0x008354B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248670_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 336));
}


// ========================================================================
// __unwind$248671
// EA  : 0x828354E0
// RVA : 0x008354E0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_248671()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1536 + 272));
}


// ========================================================================
// ?MakeDefault@idMD6Anim@@QAAXPBVidMD6Skel@@@Z
// EA  : 0x82835510
// RVA : 0x00835510
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall idMD6Anim::MakeDefault(
        idMD6Anim *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *skel,
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
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *a14)
{
  idMD6AnimData *animData; // r4
  idMD6SkelData *v17; // r10
  __int16 v18; // r9
  int v19; // r26
  int v20; // r27
  int v21; // r28
  size_t v22; // r28
  idMD6SkelData *v23; // r10
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v24; // [sp+8h] [-1B8h]
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v25; // [sp+Ch] [-1B4h]
  const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *v26; // [sp+10h] [-1B0h]
  const idList<float,5> *v27; // [sp+14h] [-1ACh]
  int v28; // [sp+18h] [-1A8h]
  int v29; // [sp+1Ch] [-1A4h]
  int v30; // [sp+20h] [-1A0h]
  const idMD6Anim::animationSettings_t *v31; // [sp+24h] [-19Ch]
  int v32; // [sp+28h] [-198h]
  int v33; // [sp+2Ch] [-194h]
  int v34; // [sp+30h] [-190h]
  int v35; // [sp+34h] [-18Ch]
  int v36; // [sp+38h] [-188h]
  int v37; // [sp+3Ch] [-184h]
  int v38; // [sp+40h] [-180h]
  int v39; // [sp+44h] [-17Ch]
  int v40; // [sp+48h] [-178h]
  int v41; // [sp+4Ch] [-174h]
  int v42; // [sp+50h] [-170h]
  int v43; // [sp+58h] [-168h]
  int v44; // [sp+60h] [-160h]
  int v45; // [sp+68h] [-158h]
  int v46; // [sp+70h] [-150h]
  int v47; // [sp+78h] [-148h]
  int v48; // [sp+80h] [-140h]
  int v49; // [sp+88h] [-138h]
  float v50[4]; // [sp+90h] [-130h] BYREF
  idList<float,32> v51; // [sp+A0h] [-120h] BYREF
  idList<float,32> v52; // [sp+B0h] [-110h] BYREF
  idList<float,32> v53; // [sp+C0h] [-100h] BYREF
  idList<float,32> v54; // [sp+D0h] [-F0h] BYREF
  idList<float,32> v55; // [sp+E0h] [-E0h] BYREF
  idList<float,5> v56; // [sp+F0h] [-D0h] BYREF
  char v57; // [sp+100h] [-C0h]
  char v58; // [sp+101h] [-BFh]
  char v59; // [sp+102h] [-BEh]
  char v60; // [sp+103h] [-BDh]
  idList<idVehicleState *,5> v61; // [sp+110h] [-B0h] BYREF
  idList<idVehicleState *,5> v62; // [sp+120h] [-A0h] BYREF
  idList<idVehicleState *,5> v63; // [sp+130h] [-90h] BYREF
  idList<idVehicleState *,5> v64; // [sp+140h] [-80h] BYREF
  idList<enum encounterGroupRole_t,5> v65; // [sp+150h] [-70h] BYREF
  int v66; // [sp+160h] [-60h] BYREF

  a14 = skel;
  animData = this->animData;
  if ( animData != nullptr )
  {
    idMem::Free(this: &mem, ptr: animData, align: ALIGN_16);
    this->animData = nullptr;
  }
  idMD6PhaseTrack::~idMD6PhaseTrack(this: &this->phaseTrack);
  if ( skel == nullptr )
    idLib::Error(fmt: "Trying to make a default animation without a valid skeleton.");
  memset(&v54, 0, 14);
  *(_WORD *)&v54.memTag = 4352;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v54);
  memset(&v52, 0, 14);
  *(_WORD *)&v52.memTag = 4352;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v52);
  memset(&v51, 0, 14);
  *(_WORD *)&v51.memTag = 4352;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v51);
  memset(&v53, 0, 14);
  *(_WORD *)&v53.memTag = 4352;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v53);
  v17 = *(idMD6SkelData **)&skel[20].value;
  v50[0] = 0.0;
  v18 = v17->numJoints + 7;
  v19 = (v17->numUserChannels + 7) & 0xFFF8;
  v20 = 3 * (v18 & 0xFFF8);
  v21 = 4 * (v18 & 0xFFF8);
  idList<float,17>::SetNum(this: &v54, newNum: 8 * (v18 & 0xFFF8), initValue: v50);
  v50[0] = 0.0;
  idList<float,17>::SetNum(this: &v52, newNum: 2 * v20, initValue: v50);
  v50[0] = 0.0;
  idList<float,17>::SetNum(this: &v51, newNum: 2 * v20, initValue: v50);
  v50[0] = 0.0;
  idList<float,17>::SetNum(this: &v53, newNum: 2 * v19, initValue: v50);
  if ( v54.num > 0 )
  {
    v22 = 4 * v21;
    memcpy(
      Dst: v54.list,
      Src: (const void *)(*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8) + *(_DWORD *)&skel[20].value),
      Size: v22);
    memcpy(
      Dst: &v54.list[v22 / 4],
      Src: (const void *)(*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8) + *(_DWORD *)&skel[20].value),
      Size: v22);
  }
  if ( v52.num > 0 )
  {
    memcpy(
      Dst: v52.list,
      Src: (const void *)(((16 * (*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 2) + 7)) & 0xFFF80)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v20);
    memcpy(
      Dst: &v52.list[v20],
      Src: (const void *)(((16 * (*(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 2) + 7)) & 0xFFF80)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v20);
  }
  if ( v51.num > 0 )
  {
    memcpy(
      Dst: v51.list,
      Src: (const void *)(28 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v20);
    memcpy(
      Dst: &v51.list[v20],
      Src: (const void *)(28 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v20);
  }
  if ( v53.num > 0 )
  {
    memcpy(
      Dst: v53.list,
      Src: (const void *)(40 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v19);
    memcpy(
      Dst: &v53.list[v19],
      Src: (const void *)(40 * ((*(_WORD *)(*(_DWORD *)&skel[20].value + 2) + 7) & 0xFFF8)
                   + *(unsigned __int16 *)(*(_DWORD *)&skel[20].value + 8)
                   + *(_DWORD *)&skel[20].value),
      Size: 4 * v19);
  }
  memset(&v62, 0, 14);
  *(_WORD *)&v62.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v62);
  memset(&v61, 0, 14);
  *(_WORD *)&v61.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v61);
  memset(&v63, 0, 14);
  *(_WORD *)&v63.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v63);
  memset(&v55, 0, 14);
  *(_WORD *)&v55.memTag = 4352;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v55);
  v23 = *(idMD6SkelData **)&skel[20].value;
  v50[0] = 255.0;
  idList<float,17>::SetNum(this: &v55, newNum: (v23->numJoints + 7) & 0xFFF8, initValue: v50);
  *(_QWORD *)&v56.num = 0;
  *(float *)&v56.list = 0.60000002;
  *(_DWORD *)&v56.granularity = 16843009;
  v57 = 1;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  *(_QWORD *)&v65.num = 1;
  v65.list = (encounterGroupRole_t *)&v66;
  *(_DWORD *)&v65.granularity = 66817;
  idList<idAnimWebBlendTree *,5>::Append(this: &v65, obj: (const encounterGroupRole_t *)&a14);
  memset(&v64, 0, 14);
  *(_WORD *)&v64.memTag = 1280;
  this->jointConversionHandle.value = skel[24].value;
  this->jointConversionChecksum.value = skel[25].value;
  idList<idThread *,58>::Clear(this: &v64);
  this->timestamp = *(_DWORD *)&skel[22].value;
  idMD6Anim::CompressAnim(
    this,
    skel,
    mappedSkeletons: (const idList<idMD6Skel const *,5> *)&v65,
    rotation: (const idList<float,5> *)&v54,
    scale: (const idList<float,5> *)&v52,
    translation: (const idList<float,5> *)&v51,
    userChannels: (const idList<float,5> *)&v53,
    maskRJoints: (const idList<idIndex<short,enum invalidJointIndex_t>,5> *)&v62,
    maskSJoints: v24,
    maskTJoints: v25,
    maskUChannels: v26,
    jointWeights: v27,
    flags: v28,
    numFrames: v29,
    frameRate: v30,
    animSettings: v31,
    a17: v32,
    a18: v33,
    a19: v34,
    a20: v35,
    a21: v36,
    a22: v37,
    a23: v38,
    a24: v39,
    a25: v40,
    a26: v41,
    a27: v42,
    a28: &v63,
    a29: v43,
    a30: &v61,
    a31: v44,
    a32: &v64,
    a33: v45,
    a34: (int)&v55,
    a35: v46,
    maskSJoints_2: 0,
    a37: v47,
    maskTJointsa: 2,
    a39: v48,
    maskUChannels_2: 30,
    a41: v49,
    jointWeightsa: &v56);
  idList<idThread *,58>::Clear(this: &v64);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v65);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v55);
  idList<idThread *,58>::Clear(this: &v63);
  idList<idThread *,58>::Clear(this: &v61);
  idList<idThread *,58>::Clear(this: &v62);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v53);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v51);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v52);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v54);
}


// ========================================================================
// $LN172
// EA  : 0x82835A04
// RVA : 0x00835A04
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN172()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 208));
}


// ========================================================================
// __unwind$250490
// EA  : 0x82835A2C
// RVA : 0x00835A2C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250490()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 176));
}


// ========================================================================
// __unwind$250491
// EA  : 0x82835A54
// RVA : 0x00835A54
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250491()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 160));
}


// ========================================================================
// __unwind$250492
// EA  : 0x82835A7C
// RVA : 0x00835A7C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250492()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 192));
}


// ========================================================================
// __unwind$250493
// EA  : 0x82835AA4
// RVA : 0x00835AA4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250493()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 288));
}


// ========================================================================
// __unwind$250494
// EA  : 0x82835ACC
// RVA : 0x00835ACC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250494()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 272));
}


// ========================================================================
// __unwind$250495
// EA  : 0x82835AF4
// RVA : 0x00835AF4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250495()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 304));
}


// ========================================================================
// __unwind$250496
// EA  : 0x82835B1C
// RVA : 0x00835B1C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250496()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 224));
}


// ========================================================================
// __unwind$250497
// EA  : 0x82835B44
// RVA : 0x00835B44
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 336));
}


// ========================================================================
// __unwind$250498
// EA  : 0x82835B6C
// RVA : 0x00835B6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250498()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 320));
}


// ========================================================================
// ?LoadText@idMD6Anim@@QAA_NPBDPBM@Z
// EA  : 0x82835BA0
// RVA : 0x00835BA0
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMD6Anim::LoadText(idMD6Anim *this, const char *filename, float *errorToleranceOverride)
{
  idMD6AnimData *animData; // r4
  int v6; // r26
  unsigned int fileTime; // r11
  int v8; // r5
  int v9; // r5
  float v10; // r30
  int v11; // r4
  int v12; // r11
  unsigned int v13; // r28
  int v14; // r29
  idMD6Anim::animationSettings_t *v15; // r30
  int v16; // r14
  BOOL useForwardTranslation; // r11
  unsigned int v18; // r11
  bool v19; // zf
  unsigned int v20; // r11
  unsigned int v21; // r11
  unsigned int v22; // r11
  unsigned int v23; // r11
  unsigned int v24; // r11
  unsigned int v25; // r11
  int startFrameOffset; // r10
  int networkID; // r8
  int endFrameOffset; // r9
  int v29; // r11
  int v30; // r22
  int v31; // r20
  int v32; // r10
  __int16 *list; // r21
  __int16 *v34; // r23
  int i; // r26
  __int16 value; // r30
  double v37; // fp1
  __int16 *v38; // r28
  int j; // r30
  idMD6Skel *UserChannelIndex; // r11
  int k; // r29
  char v42; // r10
  int m; // r11
  int n; // r30
  char v45; // r10
  int ii; // r11
  int num; // r28
  int jj; // r29
  char v49; // r9
  int kk; // r11
  idIndex<short,enum invalidJointIndex_t> *v51; // r28
  int v52; // r10
  int v53; // r11
  int v54; // r10
  int v55; // r19
  int v56; // r18
  int v57; // r26
  int v58; // r30
  int mm; // r7
  int nn; // r11
  int v61; // r9
  int v62; // r29
  int i1; // r11
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v64; // r3
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v65; // r3
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v66; // r3
  idMem *staleCount; // r30
  int i2; // r11
  int i3; // r11
  int i4; // r11
  int i5; // r11
  int i6; // r11
  int i7; // r11
  int i8; // r11
  int i9; // r11
  int i10; // r11
  int i11; // r11
  idMD6Anim *v79; // r29
  int i12; // r30
  char v81; // r26
  int i13; // r28
  __int16 *v83; // r17
  int i14; // r27
  int v85; // r29
  int v86; // r30
  int v87; // r30
  float *v88; // r10
  float *v89; // r11
  double v90; // fp0
  double v91; // fp0
  double v92; // fp0
  int i15; // r30
  int i16; // r30
  int v95; // r25
  int v96; // r27
  int v97; // r24
  __int16 *v98; // r26
  int i17; // r30
  float *v100; // r28
  int v101; // r29
  int i18; // r30
  const char *v103; // r24
  int v104; // r5
  float *v105; // r29
  idMD6Anim *v106; // r26
  double v107; // fp11
  double v108; // fp8
  double v109; // fp0
  double v110; // fp13
  double v111; // fp12
  double z; // fp5
  double y; // fp4
  double x; // fp3
  double v116; // fp7
  double v118; // fp2
  double v119; // fp2
  double v120; // fp20
  double v121; // fp22
  double v122; // fp21
  double v123; // fp31
  double v124; // fp29
  double v125; // fp30
  char v126; // r11
  char v127; // r11
  idMat3 *v128; // r3
  double v129; // fp12
  double v130; // fp10
  double v131; // fp9
  double v132; // fp8
  double v133; // fp7
  double v134; // fp6
  double v135; // fp5
  double v136; // fp1
  double v137; // fp0
  double v138; // fp13
  double v139; // fp9
  double v140; // fp8
  idAngles *v141; // r3
  double pitch; // fp0
  double yaw; // fp11
  double roll; // fp10
  int v146; // r11
  float *v147; // r10
  __int64 v148; // r9 OVERLAPPED
  int v149; // r7 OVERLAPPED
  __int64 v150; // r4 OVERLAPPED
  __int64 v151; // r6 OVERLAPPED
  const char **v152; // r10
  int *v153; // r11
  int i19; // ctr
  int v156; // r28
  int v162; // r11
  float *v163; // r10
  int v164; // r30
  double v165; // fp7
  double v166; // fp5
  double v167; // fp4
  double v168; // fp2
  double v169; // fp12
  float *v170; // r29
  double v171; // fp2
  double v172; // fp3
  double v173; // fp31
  double v174; // fp30
  double v175; // fp29
  int *v176; // r10
  int *v177; // r11
  int i20; // ctr
  idMem *v200; // r27
  int v201; // r28
  int v202; // r11
  int v203; // r6
  int v204; // r10
  int v205; // r3
  int v206; // r30
  int v207; // r10
  const char *v208; // r9
  int v209; // r8
  float v210; // r25
  int v211; // r6
  float v212; // r24
  float v213; // r23
  float *v214; // r9
  float *v215; // r11
  int v216; // r5
  float *v217; // r8
  float v218; // r24
  float v219; // r23
  float v220; // r5
  float v221; // r26
  float v222; // r27
  float v223; // r22
  float v224; // r5
  int v225; // r4
  float v226; // r7
  float v227; // r26
  float v228; // r24
  double v229; // fp12
  double v230; // fp0
  float v231; // r25
  float v232; // r27
  float v233; // r26
  float v234; // r4
  double v235; // fp13
  double v236; // fp2
  double v237; // fp6
  double v238; // fp3
  double v239; // fp9
  double v240; // fp7
  double v241; // fp29
  double v242; // fp31
  double v243; // fp30
  double v244; // fp5
  int i21; // r11
  int i22; // r11
  int i23; // r11
  int i24; // r11
  int i25; // r11
  int i26; // r11
  int i27; // r11
  int i28; // r11
  int i29; // r11
  int i30; // r11
  int i31; // r11
  int i32; // r11
  int i33; // r11
  unsigned int v258; // r3
  __int64 v259; // r10
  __int64 v260; // r8
  __int64 v261; // r6
  __int64 v262; // r10
  __int64 v263; // r8
  bool v264; // r3
  __int64 v265; // r6
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v266; // [sp+8h] [-928h]
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v267; // [sp+Ch] [-924h]
  const idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *v268; // [sp+10h] [-920h]
  const idList<float,5> *v269; // [sp+14h] [-91Ch]
  int v270; // [sp+18h] [-918h]
  int v271; // [sp+1Ch] [-914h]
  int v272; // [sp+20h] [-910h]
  const idMD6Anim::animationSettings_t *v273; // [sp+24h] [-90Ch]
  int v274; // [sp+28h] [-908h]
  idIndex<short,enum invalidJointIndex_t> *v275; // [sp+2Ch] [-904h]
  int v276; // [sp+30h] [-900h]
  const idList<idIndex<short,enum invalidJointIndex_t>,5> *v277; // [sp+34h] [-8FCh]
  int v278; // [sp+38h] [-8F8h]
  idList<idIndex<short,enum invalidJointIndex_t>,5> *v279; // [sp+3Ch] [-8F4h]
  int v280; // [sp+40h] [-8F0h]
  idList<idIndex<short,enum invalidJointIndex_t>,5> *v281; // [sp+44h] [-8ECh]
  int v282; // [sp+48h] [-8E8h]
  const idList<float,5> *v283; // [sp+4Ch] [-8E4h]
  int v284; // [sp+50h] [-8E0h]
  int v285; // [sp+58h] [-8D8h]
  int v286; // [sp+60h] [-8D0h]
  int v287; // [sp+68h] [-8C8h]
  int v288; // [sp+70h] [-8C0h]
  int v289; // [sp+78h] [-8B8h]
  int v290; // [sp+80h] [-8B0h]
  int v291; // [sp+88h] [-8A8h]
  idMD6Skel v292; // [sp+90h] [-8A0h] BYREF
  int v293; // [sp+C4h] [-86Ch]
  int v294; // [sp+C8h] [-868h]
  __int16 v295; // [sp+CCh] [-864h]
  char v296; // [sp+CEh] [-862h]
  char v297; // [sp+CFh] [-861h]
  idList<float,32> v298; // [sp+D0h] [-860h] BYREF
  const char *v299; // [sp+E0h] [-850h]
  idList<float,32> v300; // [sp+F0h] [-840h] BYREF
  unsigned int v301; // [sp+100h] [-830h]
  idMD6Skel v302; // [sp+104h] [-82Ch] BYREF
  int v303; // [sp+144h] [-7ECh]
  float v304; // [sp+148h] [-7E8h]
  int v305; // [sp+14Ch] [-7E4h]
  int v306; // [sp+150h] [-7E0h]
  int v307; // [sp+154h] [-7DCh]
  int v308; // [sp+158h] [-7D8h]
  int v309; // [sp+15Ch] [-7D4h]
  idList<float,32> v310; // [sp+160h] [-7D0h] BYREF
  float v311[4]; // [sp+170h] [-7C0h] BYREF
  __int16 v312; // [sp+180h] [-7B0h]
  __int16 v313; // [sp+182h] [-7AEh]
  idList<idIndex<short,enum invalidJointIndex_t>,5> v314; // [sp+190h] [-7A0h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v315; // [sp+1A0h] [-790h] BYREF
  idList<idIndex<short,enum invalidJointIndex_t>,5> v316; // [sp+1B0h] [-780h] BYREF
  idTypedResourceList<idMD6Skel> *v317; // [sp+1C0h] [-770h]
  idList<short,5> v318; // [sp+1D0h] [-760h] BYREF
  const char *v319; // [sp+1E0h] [-750h]
  idList<short,5> v320; // [sp+1F0h] [-740h] BYREF
  const char *v321; // [sp+200h] [-730h]
  const char *v322; // [sp+204h] [-72Ch]
  idList<float,32> v323; // [sp+210h] [-720h] BYREF
  idList<short,5> v324; // [sp+220h] [-710h] BYREF
  __int64 v325; // [sp+230h] [-700h]
  float v326; // [sp+238h] [-6F8h]
  idQuat v327; // [sp+240h] [-6F0h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v328; // [sp+250h] [-6E0h] BYREF
  idAngles v329; // [sp+260h] [-6D0h] BYREF
  float v330; // [sp+26Ch] [-6C4h]
  const char *v331; // [sp+270h] [-6C0h]
  const char *v332; // [sp+274h] [-6BCh]
  const char *v333; // [sp+278h] [-6B8h]
  const char *v334; // [sp+27Ch] [-6B4h]
  const char *v335; // [sp+280h] [-6B0h]
  const char *v336; // [sp+284h] [-6ACh]
  int v337; // [sp+288h] [-6A8h]
  const char *v338; // [sp+28Ch] [-6A4h]
  idAngles v339; // [sp+290h] [-6A0h] BYREF
  float v340; // [sp+29Ch] [-694h]
  const char *v341; // [sp+2A0h] [-690h]
  idList<enum encounterGroupRole_t,5> v342; // [sp+2B0h] [-680h] BYREF
  const char *v343; // [sp+2C0h] [-670h]
  const char *v344; // [sp+2C4h] [-66Ch]
  const char *v345; // [sp+2C8h] [-668h]
  const char *v346; // [sp+2CCh] [-664h] BYREF
  idAngles v347; // [sp+2D0h] [-660h] BYREF
  float v348; // [sp+2DCh] [-654h]
  float v349; // [sp+2E0h] [-650h]
  float v350; // [sp+2E4h] [-64Ch]
  idMD6Anim::animationSettings_t v351; // [sp+300h] [-630h] BYREF
  int v352; // [sp+31Ch] [-614h] BYREF
  float v353; // [sp+320h] [-610h] BYREF
  float v354; // [sp+324h] [-60Ch]
  float v355; // [sp+328h] [-608h]
  float v356; // [sp+32Ch] [-604h]
  float v357; // [sp+330h] [-600h]
  float v358; // [sp+334h] [-5FCh]
  int v359; // [sp+33Ch] [-5F4h] BYREF
  idBounds v360; // [sp+340h] [-5F0h] BYREF
  idMat3 v361; // [sp+360h] [-5D0h] BYREF
  char *v362; // [sp+384h] [-5ACh]
  int v363; // [sp+388h] [-5A8h]
  char v364; // [sp+38Ch] [-5A4h] BYREF
  idToken v365; // [sp+3A0h] [-590h] BYREF
  idStr v366; // [sp+3F0h] [-540h] BYREF
  idStr v367; // [sp+410h] [-520h] BYREF
  idToken v368; // [sp+430h] [-500h] BYREF
  idParser v369; // [sp+480h] [-4B0h] BYREF
  idToken v370; // [sp+710h] [-220h] BYREF
  idBounds v371; // [sp+760h] [-1D0h] BYREF
  idStr v372; // [sp+780h] [-1B0h] BYREF
  idBounds v373; // [sp+7A0h] [-190h] BYREF
  idBounds v374; // [sp+7C0h] [-170h] BYREF
  idMat3 v375; // [sp+7E0h] [-150h] BYREF
  idBounds v376[5]; // [sp+810h] [-120h] BYREF

  animData = this->animData;
  v292.staleCount = (int)&mem;
  if ( animData != nullptr )
  {
    idMem::Free(this: &mem, ptr: animData, align: ALIGN_16);
    this->animData = nullptr;
  }
  idMD6PhaseTrack::~idMD6PhaseTrack(this: &this->phaseTrack);
  v361.mat[2].z = 0.0;
  v363 = 20;
  v362 = &v364;
  v364 = 0;
  v366.allocedAndFlag = 20;
  v366.data = v366.baseBuffer;
  v366.len = 0;
  v366.baseBuffer[0] = 0;
  v311[1] = 0.0;
  v311[2] = 0.0;
  v311[0] = 0.60000002;
  v351.errorTolerance = 0.60000002;
  v311[3] = 2.3694278e-38;
  v312 = 256;
  v313 = 0;
  v351.startFrameOffset = 0;
  v351.endFrameOffset = 0;
  v351.removeOrigin = true;
  v351.useForwardTranslation = true;
  v309 = 0;
  v351.useLeftTranslation = true;
  v308 = 0;
  v351.useUpTranslation = true;
  v301 = 0;
  v351.useRotation = true;
  v292.networkID = 0;
  v351.retargetAdditive = false;
  v337 = 0;
  v351.facetracksComposite = false;
  v351.frameZeroDelta = false;
  HIBYTE(v292.__vftable) = idMD6Anim::LoadAnim_Settings(
                             animationFilename: filename,
                             _animSettings: &v351,
                             timeStamp: &this->settingsTimestamp,
                             loadFromAnim: false);
  idParser::idParser(this: &v369, flags: 262704);
  while ( 1 )
  {
    if ( !idParser::LoadFile(this: &v369, filename, OSPath: false) )
    {
      v264 = fileSystem->FileExists(this: fileSystem, a2: filename, a3: true);
      HIDWORD(v265) = filename;
      if ( v264 )
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Error parsing file for md6anim '%s'",
          a3: v265,
          a4: v263,
          a5: v262,
          a6: (int)v266,
          a7: (int)v267,
          a8: (int)v268,
          a9: (int)v269,
          a10: v270,
          a11: v271);
      else
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Missing file '%s'",
          a3: v265,
          a4: v263,
          a5: v262,
          a6: (int)v266,
          a7: (int)v267,
          a8: (int)v268,
          a9: (int)v269,
          a10: v270,
          a11: v271);
      idParser::~idParser(this: &v369);
      idStr::FreeData(this: &v366);
      idStr::FreeData(this: (idStr *)&v361.mat[2].z);
      return 0;
    }
    idParser::ExpectTokenString(this: &v369, string: MD6_VERSION_STRING);
    v6 = idParser::ParseInt(this: &v369);
    if ( v6 == 7 )
      break;
    if ( (unsigned __int8)idMD6Anim::RewriteText(filename) == 0 )
    {
      HIDWORD(v261) = filename;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Error rewriting file for md6anim '%s'",
        a3: v261,
        a4: v260,
        a5: v259,
        a6: (int)v266,
        a7: (int)v267,
        a8: (int)v268,
        a9: (int)v269,
        a10: v270,
        a11: v271);
      idParser::Error(
        this: &v369,
        str: "MD6 anim '%s' has an invalid version %d. Should be version %d.",
        filename,
        v6,
        7);
      idParser::~idParser(this: &v369);
      idStr::FreeData(this: &v366);
      idStr::FreeData(this: (idStr *)&v361.mat[2].z);
      return 0;
    }
    idParser::FreeSource(this: &v369);
  }
  if ( v369.scriptstack != nullptr )
    fileTime = v369.scriptstack->fileTime;
  else
    fileTime = 0;
  this->timestamp = fileTime;
  v302.resourceError = (const char *)20;
  v302.nextOnHashChain = nullptr;
  HIBYTE(v302.networkID) = 0;
  v302.resourceListPtr = (idResourceList *)&v302.networkID;
  v303 = 0;
  v305 = 0;
  v306 = 0;
  v307 = 0;
  v304 = -3.4028235e38;
  v365.floatvalue = -3.4028235e38;
  v365.allocedAndFlag = 20;
  v365.data = v365.baseBuffer;
  v365.len = 0;
  v365.baseBuffer[0] = 0;
  v365.intvalue = 0;
  memset(&v365.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenString(this: &v369, string: "init");
  idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
  v321 = "rotationMask";
  HIDWORD(v325) = "w:\\tech5\\shared\\idlib\\text/Str.h";
  v317 = &idMD6Skel::resourceList;
  *(float *)&v292.name.str = 0.0020000001;
  v346 = "bounds";
  v319 = "scaleMask";
  HIBYTE(v292.resourceError) = 0;
  v338 = "amount <= GetAlloced()";
  HIBYTE(v292.defaultAnim) = 0;
  v322 = "translationMask";
  *((_DWORD *)&v292.idResource + 8) = 0;
  v345 = "Unrecognized token '%s' in MD6 anim file '%s'.";
  v336 = "worldScale";
  v341 = "worldRot";
  v334 = "worldPos";
  v343 = "startFrame";
  v344 = "sourceTake";
  v332 = "normalizedBounds";
  v299 = "skeletonName";
  v331 = "maskName";
  v333 = "subtractiveAnim";
  v335 = "sourceAnim";
  while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
       && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
  {
    if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "commandLine") != 0 )
    {
      if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v335) != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v333) != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v331) != 0 )
      {
        if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v299) != 0 )
        {
          if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "numFrames") != 0 )
          {
            if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "frameRate") != 0 )
            {
              if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "numJoints") != 0 )
              {
                if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "numUserChannels") != 0 )
                {
                  if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "maxErrorRotation") != 0 )
                  {
                    if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "maxErrorScale") != 0
                      && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "maxErrorTranslation") != 0
                      && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "maxErrorUser") != 0 )
                    {
                      if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "errorTolerance") != 0 )
                      {
                        if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v321) == 0
                          || idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v319) == 0
                          || idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v322) == 0 )
                        {
                          goto _M253996_0;
                        }
                        if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v346) != 0 )
                        {
                          if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "translatedBounds") != 0 )
                          {
                            if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v332) != 0 )
                            {
                              if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v344) == 0 )
                                goto _M253996_0;
                              if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v343) != 0 )
                              {
                                if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v334) != 0 )
                                {
                                  if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v341) != 0 )
                                  {
                                    if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: v336) != 0 )
                                      idParser::Error(this: &v369, str: v345, v302.resourceListPtr, filename);
                                    else
                                      idParser::Parse1DMatrix(this: &v369, x: 3, m: &this->origWorldScale.x);
                                  }
                                  else
                                  {
                                    idParser::Parse1DMatrix(this: &v369, x: 3, m: &this->origWorldRot.pitch);
                                  }
                                }
                                else
                                {
                                  idParser::Parse1DMatrix(this: &v369, x: 3, m: &this->origWorldPos.x);
                                }
                              }
                              else
                              {
                                this->timeCode = idParser::ParseInt(this: &v369);
                              }
                            }
                            else
                            {
                              idParser::Parse1DMatrix(this: &v369, x: 3, m: (float *)&v373);
                              idParser::Parse1DMatrix(this: &v369, x: 3, m: &v373.b[1].x);
                              idBoundsShort::SetBounds(this: &this->normalizedBounds, bounds: &v373);
                            }
                          }
                          else
                          {
                            idParser::Parse1DMatrix(this: &v369, x: 3, m: (float *)&v374);
                            idParser::Parse1DMatrix(this: &v369, x: 3, m: &v374.b[1].x);
                            idBoundsShort::SetBounds(this: &this->translatedBounds, bounds: &v374);
                          }
                        }
                        else
                        {
                          idParser::Parse1DMatrix(this: &v369, x: 3, m: (float *)&v371);
                          idParser::Parse1DMatrix(this: &v369, x: 3, m: &v371.b[1].x);
                          idBoundsShort::SetBounds(this: &this->translatedBounds, bounds: &v371);
                          idBoundsShort::SetBounds(this: &this->normalizedBounds, bounds: &v371);
                        }
                      }
                      else
                      {
                        v311[0] = idParser::ParseFloat(this: &v369, errorFlag: nullptr);
                        HIBYTE(v292.resourceError) = 1;
                      }
                    }
                    else
                    {
                      idParser::ParseFloat(this: &v369, errorFlag: nullptr);
                    }
                  }
                  else
                  {
                    *(float *)&v292.name.str = idParser::ParseFloat(this: &v369, errorFlag: nullptr);
                    HIBYTE(v292.defaultAnim) = 1;
                  }
                }
                else
                {
                  v308 = idParser::ParseInt(this: &v369);
                }
              }
              else
              {
                v309 = idParser::ParseInt(this: &v369);
              }
            }
            else
            {
              v9 = idParser::ParseInt(this: &v369);
              v337 = v9;
              if ( v9 != 30 )
                idParser::Error(
                  this: &v369,
                  str: "Unsupported animation rate, %d, in MD6 anim file '%s'.",
                  v9,
                  filename);
            }
          }
          else
          {
            v8 = idParser::ParseInt(this: &v369);
            v292.networkID = v8;
            if ( v8 <= 0 )
              idParser::Error(this: &v369, str: "Invalid number of frames, %d, in MD6 anim file '%s'.", v8, filename);
          }
        }
        else
        {
          idParser::ReadToken(this: &v369, token: &v365);
          v367.len = 0;
          v367.data = v367.baseBuffer;
          v367.allocedAndFlag = 20;
          v367.baseBuffer[0] = 0;
          idStr::ExtractFileExtension(this: &v365, dest: &v367);
          if ( idStr::Icmp(s1: v367.data, s2: "md6skel") == 0
            || idStr::Icmp(s1: v367.data, s2: "md6skl") == 0
            && (*((_DWORD *)&v292.idResource + 8) = idResourceList::Load(
                                                      this: v317,
                                                      name: v365.data,
                                                      makeDefault: false,
                                                      skipStaleCheck: false),
                *((_DWORD *)&v292.idResource + 8) == 0) )
          {
            idParser::Error(this: &v369, str: "Could not load skeleton '%s'", v365.data);
          }
          idStr::FreeData(this: &v367);
        }
      }
      else
      {
_M253996_0:
        idParser::ReadToken(this: &v369, token: &v365);
      }
    }
    else
    {
      idParser::ReadToken(this: &v369, token: &v365);
      v10 = *(float *)&v365.len;
      v11 = v365.len + 1;
      v12 = v363 & 0x7FFFFFFF;
      if ( v363 >= 0 )
      {
        if ( v11 > v12 )
          idStr::ReAllocate(this: (idStr *)&v361.mat[2].z, amount: v11, keepold: false);
      }
      else if ( v11 > v12
             && AssertFailed(file: (const char *)HIDWORD(v325), line: 463, expression: v338, inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: v362, Src: v365.data, Size: LODWORD(v10));
      v362[LODWORD(v10)] = 0;
      v361.mat[2].z = v10;
    }
  }
  if ( *((_DWORD *)&v292.idResource + 8) == 0 )
    idParser::Error(this: &v369, str: "Missing skeleton file for animation '%s'", this->name.str);
  idParser::ExpectTokenString(this: &v369, string: "flags");
  idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
  v13 = v301;
  *(_WORD *)((char *)&v311[3] + 1) = 257;
  LOBYTE(v311[3]) = 1;
  v312 = 256;
  LOBYTE(v313) = 0;
  while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
       && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
  {
    if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "additive") != 0 )
    {
      if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "useForwardTranslation") != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "useLeftTranslation") != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "useUpTranslation") != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "useYawRotation") != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "useRotation") != 0
        && idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "ignoreBounds") != 0 )
      {
        if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "retargetAdditive") != 0 )
        {
          if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "frameZeroDelta") != 0 )
          {
            if ( idStr::Icmp(s1: (const char *)v302.resourceListPtr, s2: "facetracksComposite") != 0 )
            {
              idParser::Warning(
                this: &v369,
                str: "Unrecognized flag '%s' in MD6 anim file '%s'.",
                (const char *)v302.resourceListPtr,
                filename);
            }
            else
            {
              v13 |= 0x8000u;
              HIBYTE(v313) = 1;
            }
          }
          else
          {
            v13 |= 0x200u;
            LOBYTE(v313) = 1;
          }
        }
        else
        {
          v13 |= 0x100u;
          LOBYTE(v312) = 1;
        }
      }
    }
    else
    {
      v13 |= 1u;
    }
  }
  v14 = HIBYTE(v292.__vftable);
  v15 = &v351;
  v16 = idMD6Anim::skipJoints ? 0 : v309;
  if ( HIBYTE(v292.__vftable) == 0 )
    v15 = (idMD6Anim::animationSettings_t *)v311;
  useForwardTranslation = v15->useForwardTranslation;
  v299 = (const char *)v15;
  v19 = useForwardTranslation;
  v18 = v13 | 2;
  if ( !v19 )
    v18 = v13 & 0xFFFFFFFD;
  if ( v15->useLeftTranslation )
    v20 = v18 | 4;
  else
    v20 = v18 & 0xFFFFFFFB;
  if ( v15->useUpTranslation )
    v21 = v20 | 8;
  else
    v21 = v20 & 0xFFFFFFF7;
  if ( v15->useRotation )
    v22 = v21 | 0x10;
  else
    v22 = v21 & 0xFFFFFFEF;
  if ( v15->retargetAdditive )
    v23 = v22 | 0x100;
  else
    v23 = v22 & 0xFFFFFEFF;
  if ( v15->frameZeroDelta )
    v24 = v23 | 0x200;
  else
    v24 = v23 & 0xFFFFFDFF;
  if ( v15->facetracksComposite )
    v25 = v24 | 0x8000;
  else
    v25 = v24 & 0xFFFF7FFF;
  v301 = v25;
  startFrameOffset = v15->startFrameOffset;
  networkID = v292.networkID;
  endFrameOffset = (__int16)v15->endFrameOffset;
  v29 = v292.networkID - endFrameOffset - (__int16)startFrameOffset;
  this->startFrameOffset = startFrameOffset;
  this->endFrameOffset = endFrameOffset;
  if ( v29 >= 2 )
  {
    v292.networkID = networkID - endFrameOffset - (__int16)startFrameOffset;
  }
  else
  {
    idLib::Warning(fmt: "Frameoffsets would make number of frames less than 2, resetting");
    this->startFrameOffset = 0;
    this->endFrameOffset = 0;
  }
  if ( errorToleranceOverride != nullptr )
  {
    v15->errorTolerance = *errorToleranceOverride;
  }
  else if ( HIBYTE(v292.resourceError) == 0 && v14 == 0 && HIBYTE(v292.defaultAnim) != 0 )
  {
    v15->errorTolerance = *(float *)&v292.name.str * (float)300.0;
  }
  *(_WORD *)&v324.memTag = 1280;
  memset(&v324, 0, 14);
  HIWORD(v292.__vftable) = -1;
  idList<short,5>::SetNum(this: &v324, newNum: v16, initValue: (const __int16 *)&v292);
  *(_WORD *)&v310.memTag = 1280;
  memset(&v310, 0, 14);
  *(_WORD *)&v320.memTag = 1280;
  memset(&v320, 0, 14);
  *(_WORD *)&v318.memTag = 1280;
  memset(&v318, 0, 14);
  HIWORD(v292.__vftable) = -1;
  idList<short,5>::SetNum(this: &v320, newNum: v16, initValue: (const __int16 *)&v292);
  HIWORD(v292.__vftable) = -1;
  v30 = v308;
  idList<short,5>::SetNum(this: &v318, newNum: v308, initValue: (const __int16 *)&v292);
  v31 = *((_DWORD *)&v292.idResource + 8);
  v32 = *(_DWORD *)(*((_DWORD *)&v292.idResource + 8) + 40);
  *(float *)&v292.name.str = 0.0;
  idList<float,17>::SetNum(this: &v310, newNum: *(unsigned __int16 *)(v32 + 2), initValue: (float *)&v292.name);
  this->jointConversionHandle.value = *(_WORD *)(v31 + 48);
  this->jointConversionChecksum.value = *(_WORD *)(v31 + 50);
  idParser::ExpectTokenString(this: &v369, string: "joints");
  if ( idMD6Anim::skipJoints )
  {
    idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
    list = v324.list;
    v34 = v320.list;
  }
  else
  {
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    list = v324.list;
    v34 = v320.list;
    for ( i = 0; i < v16; ++i )
    {
      v368.floatvalue = -3.4028235e38;
      v368.allocedAndFlag = 20;
      v368.data = v368.baseBuffer;
      v368.len = 0;
      v368.baseBuffer[0] = 0;
      v368.intvalue = 0;
      memset(&v368.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v369, type: 1, subtype: 0, token: &v368);
      list[i] = idParser::ParseInt(this: &v369);
      value = idMD6Skel::GetJointIndex(
                this: &v292,
                result: (idIndex<short,enum invalidJointIndex_t> *)v31,
                name: v368.data)->value;
      if ( value == -1 )
        idParser::Error(this: &v369, str: "Joint '%s' not found in skeleton", v368.data);
      v34[i] = value;
      v37 = idParser::ParseFloat(this: &v369, errorFlag: nullptr);
      v310.list[value] = v37;
      idStr::FreeData(this: &v368);
    }
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
  }
  if ( idParser::CheckTokenString(this: &v369, string: "userChannels") != 0 )
  {
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    v38 = v318.list;
    for ( j = 0; j < v30; ++j )
    {
      v370.floatvalue = -3.4028235e38;
      v370.allocedAndFlag = 20;
      v370.data = v370.baseBuffer;
      v370.len = 0;
      v370.baseBuffer[0] = 0;
      v370.intvalue = 0;
      memset(&v370.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: &v369, type: 1, subtype: 0, token: &v370);
      if ( idMD6Anim::skipJoints )
      {
        UserChannelIndex = &v292;
        HIWORD(v292.__vftable) = j;
      }
      else
      {
        UserChannelIndex = (idMD6Skel *)idMD6Skel::GetUserChannelIndex(
                                          this: (idMD6Skel *)&v292.defaultAnim,
                                          result: (idIndex<short,enum invalidUserChannelIndex_t> *)v31,
                                          name: v370.data);
      }
      v38[j] = HIWORD(UserChannelIndex->__vftable);
      idStr::FreeData(this: &v370);
    }
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
  }
  else
  {
    v38 = v318.list;
  }
  *(_WORD *)&v315.memTag = 1280;
  memset(&v315, 0, 14);
  *(_WORD *)&v316.memTag = 1280;
  memset(&v316, 0, 14);
  *(_WORD *)&v314.memTag = 1280;
  memset(&v314, 0, 14);
  *(_WORD *)&v328.memTag = 1280;
  memset(&v328, 0, 14);
  for ( k = 0; k < *(unsigned __int16 *)(*(_DWORD *)(v31 + 40) + 2); ++k )
  {
    v42 = 0;
    for ( m = 0; m < v16; ++m )
    {
      if ( v34[m] == k )
        v42 = 1;
    }
    if ( v42 == 0 )
    {
      HIWORD(v292.__vftable) = k;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: &v315,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
      HIWORD(v292.__vftable) = k;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v316,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
      HIWORD(v292.__vftable) = k;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v314,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
    }
  }
  for ( n = 0; n < *(unsigned __int16 *)(*(_DWORD *)(v31 + 40) + 4); ++n )
  {
    v45 = 0;
    for ( ii = 0; ii < v30; ++ii )
    {
      if ( v38[ii] == n )
        v45 = 1;
    }
    if ( v45 == 0 )
    {
      HIWORD(v292.__vftable) = n;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: &v328,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
    }
  }
  num = v310.num;
  for ( jj = 0; jj < num; ++jj )
  {
    if ( v310.list[jj] <= 0.0 )
    {
      HIWORD(v292.__vftable) = jj;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: &v315,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
      HIWORD(v292.__vftable) = jj;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v316,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
      HIWORD(v292.__vftable) = jj;
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v314,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v292);
    }
  }
  idAnimator_TrackerBase::GetReferenceJointOverride(this: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)&v302.__vftable + 1);
  CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v302.__vftable + 1, data: list, length: 2 * v16);
  if ( !idMD6Anim::skipJoints && *(unsigned __int16 *)(*(_DWORD *)(v31 + 40) + 6) != LOWORD(v302.__vftable) )
  {
    v49 = 0;
    if ( *(unsigned __int16 *)(v31 + 48) != 0xFFFF )
    {
      v49 = 1;
      for ( kk = 0; kk < v16; ++kk )
      {
        if ( v34[kk] == NULL_JOINT_INDEX.value )
        {
          v49 = 0;
          break;
        }
      }
    }
    if ( v49 == 0 )
      idParser::Error(
        this: &v369,
        str: "Joint parenting mismatch for anim '%s' and skeleton '%s'",
        filename,
        *(const char **)(v31 + 8));
  }
  v51 = *((idIndex<short,enum invalidJointIndex_t> **)&v292.idResource + 8);
  v52 = *(_DWORD *)(*((_DWORD *)&v292.idResource + 8) + 40);
  v53 = *(unsigned __int16 *)(v52 + 2);
  v54 = *(unsigned __int16 *)(v52 + 4);
  v295 = 0;
  v296 = 5;
  v55 = (v53 + 7) & 0xFFF8;
  v297 = 0;
  v56 = (v54 + 7) & 0xFFF8;
  *(_DWORD *)&v292.jointConversion.value = 0;
  v309 = v55;
  v294 = 0;
  v293 = 0;
  *(float *)&v292.name.str = 0.0;
  v57 = v292.networkID;
  v58 = v292.networkID * v55;
  idList<float,17>::SetNum(
    this: (idList<float,32> *)&v292.jointConversion,
    newNum: 4 * v292.networkID * v55,
    initValue: (float *)&v292.name);
  *(_WORD *)&v300.memTag = 1280;
  memset(&v300, 0, 14);
  v58 *= 3;
  *(float *)&v292.name.str = 1.0;
  idList<float,17>::SetNum(this: &v300, newNum: v58, initValue: (float *)&v292.name);
  *(_WORD *)&v298.memTag = 1280;
  memset(&v298, 0, 14);
  *(float *)&v292.name.str = 0.0;
  idList<float,17>::SetNum(this: &v298, newNum: v58, initValue: (float *)&v292.name);
  for ( mm = 0; mm < v57; ++mm )
  {
    for ( nn = 0; nn < v55; ++nn )
    {
      v61 = 16 * (nn + mm * v55);
      *(float *)(v61 + *(_DWORD *)&v292.jointConversion.value + 12) = 1.0;
    }
  }
  idParser::ExpectTokenString(this: &v369, string: v321);
  if ( idMD6Anim::skipJoints )
  {
    idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
  }
  else
  {
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
         && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
    {
      v64 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((int (__fastcall *)(idMD6Skel *))animation->FindJointHandle)(a1: &v292);
      idMD6Skel::GetJointIndex(this: &v302, result: v51, handle: v64);
      if ( SHIWORD(v302.__vftable) < 0 )
        idParser::Error(this: &v369, str: "Unknown joint name '%s' in rotationMask", (const char *)v302.resourceListPtr);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: &v315,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v302);
    }
  }
  idParser::ExpectTokenString(this: &v369, string: v319);
  if ( idMD6Anim::skipJoints )
  {
    idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
  }
  else
  {
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
         && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
    {
      v65 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((int (__fastcall *)(idMD6Skel *))animation->FindJointHandle)(a1: &v292);
      idMD6Skel::GetJointIndex(this: (idMD6Skel *)((char *)&v302.trackedMemory + 2), result: v51, handle: v65);
      if ( SLOWORD(v302.trackedMemory) < 0 )
        idParser::Error(this: &v369, str: "Unknown joint name '%s' in scaleMask", (const char *)v302.resourceListPtr);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v316,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v302.trackedMemory + 1);
    }
  }
  idParser::ExpectTokenString(this: &v369, string: v322);
  if ( idMD6Anim::skipJoints )
  {
    idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
  }
  else
  {
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
         && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
    {
      v66 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((int (__fastcall *)(idMD6Skel *))animation->FindJointHandle)(a1: &v292);
      idMD6Skel::GetJointIndex(this: (idMD6Skel *)&v302.trackedMemory, result: v51, handle: v66);
      if ( v302.trackedMemory < 0 )
        idParser::Error(
          this: &v369,
          str: "Unknown joint name '%s' in translationMask",
          (const char *)v302.resourceListPtr);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v314,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v302.trackedMemory);
    }
  }
  if ( (v301 & 0x8000) != 0 )
  {
    idParser::ExpectTokenString(this: &v369, string: "facetracksComposite");
    idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
    idParser::ExpectTokenString(this: &v369, string: "facesetupBasePath");
    idParser::ReadToken(this: &v369, token: &v365);
    v62 = idMD6Anim::LoadFacetracksComposite(
            this,
            settings: (const idList<float,5> *)v299,
            basePath: v365.data,
            skeleton: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v51,
            maskRJoints: (const idList<idIndex<short,enum invalidJointIndex_t>,5> *)&v315,
            maskSJoints: &v316,
            maskTJoints: &v314,
            jointWeights: (const idList<float,5> *)&v310,
            a9: (int)v266,
            a10: (int)v267,
            a11: (int)v268,
            a12: (int)v269,
            a13: v270,
            a14: v271,
            a15: v272,
            a16: (int)v273,
            a17: v274,
            a18: v275,
            a19: v276,
            a20: v277,
            a21: v278,
            a22: v279,
            a23: v280,
            a24: v281,
            a25: v282,
            a26: v283);
    if ( v298.listStatic != 0 && v298.listStatic != 2 )
    {
      staleCount = (idMem *)v292.staleCount;
    }
    else if ( v298.list != nullptr )
    {
      for ( i1 = 0; i1 < v298.size; ++i1 )
        ;
      staleCount = (idMem *)v292.staleCount;
      idMem::Free(this: (idMem *)v292.staleCount, ptr: v298.list, align: ALIGN_16);
      v298.list = nullptr;
      v298.size = 0;
    }
    else
    {
      staleCount = (idMem *)v292.staleCount;
      v298.list = nullptr;
      v298.size = 0;
    }
    v298.num = 0;
    if ( v300.listStatic == 0 || v300.listStatic == 2 )
    {
      if ( v300.list != nullptr )
      {
        for ( i2 = 0; i2 < v300.size; ++i2 )
          ;
        idMem::Free(this: staleCount, ptr: v300.list, align: ALIGN_16);
      }
      v300.list = nullptr;
      v300.size = 0;
    }
    v300.num = 0;
    if ( v297 == 0 || v297 == 2 )
    {
      if ( *(_DWORD *)&v292.jointConversion.value != 0 )
      {
        for ( i3 = 0; i3 < v294; ++i3 )
          ;
        idMem::Free(this: staleCount, ptr: *(void **)&v292.jointConversion.value, align: ALIGN_16);
      }
      *(_DWORD *)&v292.jointConversion.value = 0;
      v294 = 0;
    }
    v293 = 0;
    if ( (v328.listStatic == 0 || v328.listStatic == 2) && v328.list != nullptr )
    {
      for ( i4 = 0; i4 < v328.size; ++i4 )
        ;
      idMem::Free(this: staleCount, ptr: v328.list, align: ALIGN_16);
    }
    if ( (v314.listStatic == 0 || v314.listStatic == 2) && v314.list != nullptr )
    {
      for ( i5 = 0; i5 < v314.size; ++i5 )
        ;
      idMem::Free(this: staleCount, ptr: v314.list, align: ALIGN_16);
    }
    if ( (v316.listStatic == 0 || v316.listStatic == 2) && v316.list != nullptr )
    {
      for ( i6 = 0; i6 < v316.size; ++i6 )
        ;
      idMem::Free(this: staleCount, ptr: v316.list, align: ALIGN_16);
    }
    if ( (v315.listStatic == 0 || v315.listStatic == 2) && v315.list != nullptr )
    {
      for ( i7 = 0; i7 < v315.size; ++i7 )
        ;
      idMem::Free(this: staleCount, ptr: v315.list, align: ALIGN_16);
    }
    if ( (v318.listStatic == 0 || v318.listStatic == 2) && v318.list != nullptr )
    {
      for ( i8 = 0; i8 < v318.size; ++i8 )
        ;
      idMem::Free(this: staleCount, ptr: v318.list, align: ALIGN_16);
    }
    if ( (v320.listStatic == 0 || v320.listStatic == 2) && v320.list != nullptr )
    {
      for ( i9 = 0; i9 < v320.size; ++i9 )
        ;
      idMem::Free(this: staleCount, ptr: v320.list, align: ALIGN_16);
    }
    if ( (v310.listStatic == 0 || v310.listStatic == 2) && v310.list != nullptr )
    {
      for ( i10 = 0; i10 < v310.size; ++i10 )
        ;
      idMem::Free(this: staleCount, ptr: v310.list, align: ALIGN_16);
    }
    if ( (v324.listStatic == 0 || v324.listStatic == 2) && v324.list != nullptr )
    {
      for ( i11 = 0; i11 < v324.size; ++i11 )
        ;
      idMem::Free(this: staleCount, ptr: v324.list, align: ALIGN_16);
    }
    idStr::FreeData(this: &v365);
    idStr::FreeData(this: (idStr *)&v302.nextOnHashChain);
    idParser::~idParser(this: &v369);
    idStr::FreeData(this: &v366);
    idStr::FreeData(this: (idStr *)&v361.mat[2].z);
    return v62;
  }
  else
  {
    idParser::ExpectTokenString(this: &v369, string: "frames");
    if ( idMD6Anim::skipJoints )
    {
      idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
    }
    else
    {
      idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
      v79 = this;
      for ( i12 = 0; i12 < this->startFrameOffset; ++i12 )
      {
        idParser::ExpectTokenString(this: &v369, string: "frame");
        idParser::ParseInt(this: &v369);
        idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
      }
      v81 = 0;
      for ( i13 = 0; i13 < v292.networkID; ++i13 )
      {
        idParser::ExpectTokenString(this: &v369, string: "frame");
        idParser::ParseInt(this: &v369);
        idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
        v83 = v320.list;
        for ( i14 = 0; i14 < v16; ++i14 )
        {
          v85 = v83[i14];
          idParser::ExpectTokenString(this: &v369, string: "joint");
          idParser::ParseInt(this: &v369);
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
          idParser::ExpectTokenString(this: &v369, string: "R");
          v86 = i13 * v55 + v85;
          idParser::Parse1DMatrix(this: &v369, x: 4, m: (float *)(16 * v86 + *(_DWORD *)&v292.jointConversion.value));
          idParser::ExpectTokenString(this: &v369, string: "S");
          v87 = 3 * v86;
          idParser::Parse1DMatrix(this: &v369, x: 3, m: &v300.list[v87]);
          v88 = v300.list;
          v89 = &v300.list[v87];
          v90 = v300.list[v87];
          if ( v90 < 0.0 || v90 > 50.0 || (v91 = v89[1]) < 0.0 || v91 > 50.0 || (v92 = v89[2]) < 0.0 || v92 > 50.0 )
          {
            if ( v81 == 0 )
            {
              idParser::Warning(
                this: &v369,
                str: "Joint %d, frame %d scale out of range. This animation may have a 0 scale on the origin, which requires f"
                "ixing and re-export.",
                v85,
                i13);
              v88 = v300.list;
              v81 = 1;
            }
            v88[v87] = 1.0;
            v300.list[v87 + 1] = 1.0;
            v300.list[v87 + 2] = 1.0;
          }
          idParser::ExpectTokenString(this: &v369, string: "T");
          idParser::Parse1DMatrix(this: &v369, x: 3, m: &v298.list[v87]);
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
        }
        idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
        v79 = this;
      }
      for ( i15 = 0; i15 < v79->endFrameOffset; ++i15 )
      {
        idParser::ExpectTokenString(this: &v369, string: "frame");
        idParser::ParseInt(this: &v369);
        idParser::SkipBracedSection(this: &v369, parseFirstBrace: true);
      }
      idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
      v57 = v292.networkID;
    }
    *(_WORD *)&v323.memTag = 1280;
    memset(&v323, 0, 14);
    *(float *)&v292.name.str = 0.0;
    idList<float,17>::SetNum(this: &v323, newNum: v57 * v56, initValue: (float *)&v292.name);
    if ( idParser::CheckTokenString(this: &v369, string: "userChannels") != 0 )
    {
      idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
      if ( v308 <= 0 )
      {
        idParser::SkipBracedSection(this: &v369, parseFirstBrace: false);
      }
      else
      {
        for ( i16 = 0; i16 < this->startFrameOffset; ++i16 )
        {
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 44, token: (idToken *)&v302.nextOnHashChain);
          idParser::SkipRestOfLine(this: &v369);
        }
        v95 = v308;
        v96 = 0;
        v97 = v292.networkID;
        v98 = v318.list;
        while ( v96 < v97 )
        {
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 44, token: (idToken *)&v302.nextOnHashChain);
          if ( idParser::PeekTokenType(this: &v369, type: 5, subtype: 45, token: (idToken *)&v302.nextOnHashChain) == 0 )
          {
            for ( i17 = 0; i17 < v95; ++i17 )
            {
              v100 = v323.list;
              v101 = v96 * v56 + v98[i17];
              v100[v101] = idParser::ParseFloat(this: &v369, errorFlag: nullptr);
            }
          }
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 45, token: (idToken *)&v302.nextOnHashChain);
          ++v96;
        }
        for ( i18 = 0; i18 < this->endFrameOffset; ++i18 )
        {
          idParser::ExpectTokenType(this: &v369, type: 5, subtype: 44, token: (idToken *)&v302.nextOnHashChain);
          idParser::SkipRestOfLine(this: &v369);
        }
        idParser::ExpectTokenType(this: &v369, type: 5, subtype: 47, token: (idToken *)&v302.nextOnHashChain);
      }
    }
    *(_WORD *)&v342.memTag = 1280;
    memset(&v342, 0, 14);
    idList<idAnimWebBlendTree *,5>::Append(this: &v342, obj: (const encounterGroupRole_t *)&v292.idResource + 8);
    if ( idParser::CheckTokenString(this: &v369, string: "mappedSkeletons") != 0 )
    {
      idParser::ExpectTokenType(this: &v369, type: 5, subtype: 46, token: (idToken *)&v302.nextOnHashChain);
      while ( idParser::ReadToken(this: &v369, token: (idToken *)&v302.nextOnHashChain)
           && (v302.timestamp != 5 || *(_DWORD *)&v302.jointConversion.value != 47) )
      {
        v292.name.str = (const char *)idResourceList::Load(
                                        this: v317,
                                        name: (char *)v302.resourceListPtr,
                                        makeDefault: false,
                                        skipStaleCheck: false);
        if ( v292.name.str != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(this: &v342, obj: (const encounterGroupRole_t *)&v292.name);
      }
    }
    v103 = v299;
    v104 = *(_DWORD *)&v292.jointConversion.value;
    v105 = v298.list;
    v106 = this;
    if ( v299[12] != 0 )
    {
      v107 = *(float *)(*(_DWORD *)&v292.jointConversion.value + 8);
      v108 = (float)(*(float *)(*(_DWORD *)&v292.jointConversion.value + 8)
                   * *(float *)(*(_DWORD *)&v292.jointConversion.value + 8));
      v109 = **(float **)&v292.jointConversion.value;
      v110 = *(float *)(*(_DWORD *)&v292.jointConversion.value + 12);
      v111 = *(float *)(*(_DWORD *)&v292.jointConversion.value + 4);
      v329.pitch = **(float **)&v292.jointConversion.value;
      v329.roll = v107;
      v329.yaw = v111;
      v292.name.str = (const char *)&this->origWorldScale;
      v330 = v110;
      z = this->origWorldScale.z;
      v339 = v329;
      y = this->origWorldScale.y;
      v340 = v110;
      x = this->origWorldScale.x;
      _FP2 = (float)((float)((float)((float)v111 * (float)v111)
                           + (float)((float)((float)v110 * (float)v110)
                                   + (float)((float)((float)v109 * (float)v109) + (float)v108)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v116 = (float)((float)((float)((float)v111 * (float)v111)
                           + (float)((float)((float)v110 * (float)v110)
                                   + (float)((float)((float)v109 * (float)v109) + (float)v108)))
                   * (float)0.5);
      __asm { fsel      f6, f2, f6, f9 }
      v118 = __frsqrte(_FP6);
      v119 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v116) * (float)v118) - (float)1.5) * (float)v118)
                                                                                           * (float)v116)
                                                                                   * (float)((float)-(float)((float)((float)((float)v118 * (float)v116) * (float)v118) - (float)1.5)
                                                                                           * (float)v118))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v118 * (float)v116)
                                                                                           * (float)v118)
                                                                                   - (float)1.5)
                                                                   * (float)v118))
                                                   * (float)v116)
                                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v116) * (float)v118) - (float)1.5)
                                                                                           * (float)v118)
                                                                                   * (float)v116)
                                                                           * (float)((float)-(float)((float)((float)((float)v118 * (float)v116) * (float)v118) - (float)1.5)
                                                                                   * (float)v118))
                                                                   - (float)1.5)
                                                   * (float)((float)-(float)((float)((float)((float)v118 * (float)v116)
                                                                                   * (float)v118)
                                                                           - (float)1.5)
                                                           * (float)v118)))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v116)
                                                                                           * (float)v118)
                                                                                   - (float)1.5)
                                                                   * (float)v118)
                                                           * (float)v116)
                                                   * (float)((float)-(float)((float)((float)((float)v118 * (float)v116)
                                                                                   * (float)v118)
                                                                           - (float)1.5)
                                                           * (float)v118))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v118 * (float)v116) * (float)v118)
                                                   - (float)1.5)
                                   * (float)v118)));
      v339.yaw = -(float)((float)v119 * v329.yaw);
      v339.roll = -(float)((float)v119 * v329.roll);
      v339.pitch = -(float)((float)v119 * (float)v109);
      v120 = v298.list[1];
      v121 = *v298.list;
      v122 = v298.list[2];
      v123 = (float)((float)z * v298.list[2]);
      v124 = (float)(*v298.list * (float)x);
      v125 = (float)((float)y * v298.list[1]);
      if ( v109 != quat_identity.x
        || v111 != quat_identity.y
        || v107 != quat_identity.z
        || (v126 = 1, v110 != quat_identity.w) )
      {
        v126 = 0;
      }
      if ( v126 == 0 )
        goto LABEL_352;
      if ( v121 != vec3_origin.x || v120 != vec3_origin.y || (v127 = 1, v122 != vec3_origin.z) )
        v127 = 0;
      if ( v127 == 0 )
      {
LABEL_352:
        v128 = idAngles::ToMat3(this: &v347, result: (idMat3 *)&this->origWorldRot);
        v129 = (float)(v128->mat[2].x * (float)v123);
        v130 = (float)(v128->mat[1].z * (float)v125);
        v131 = (float)(v128->mat[1].y * (float)v125);
        v132 = v128->mat[1].x;
        v133 = v128->mat[0].z;
        v134 = v128->mat[0].y;
        v135 = v128->mat[0].x;
        v292.name.str = (const char *)v128;
        v136 = this->origWorldPos.y;
        v137 = (float)((float)((float)v132 * (float)v125) + (float)v129);
        v138 = this->origWorldPos.z;
        v140 = (float)((float)(v128->mat[2].y * (float)v123) + (float)((float)((float)v134 * (float)v124) + (float)v131));
        v139 = (float)((float)(v128->mat[2].z * (float)v123) + (float)((float)((float)v133 * (float)v124) + (float)v130));
        this->origWorldPos.x = (float)((float)((float)v124 * (float)v135) + (float)v137) + this->origWorldPos.x;
        this->origWorldPos.z = (float)v139 + (float)v138;
        this->origWorldPos.y = (float)v140 + (float)v136;
        v141 = idQuat::ToAngles(this: &v327, result: &v339);
        pitch = v141->pitch;
        v292.name.str = (const char *)v141;
        this->origWorldRot.pitch = this->origWorldRot.pitch + (float)pitch;
        yaw = this->origWorldRot.yaw;
        v292.name.str = (const char *)&this->origWorldRot;
        roll = this->origWorldRot.roll;
        v292.name.str = (const char *)&this->normalizedBounds;
        v146 = 2;
        v147 = &v353;
        this->origWorldRot.yaw = v141->yaw + (float)yaw;
        this->origWorldRot.roll = v141->roll + (float)roll;
        LODWORD(v150) = this->normalizedBounds.b[1][0];
        HIDWORD(v151) = this->normalizedBounds.b[0][2];
        LODWORD(v148) = this->normalizedBounds.b[1][2];
        HIDWORD(v148) = this->normalizedBounds.b[0][0];
        v149 = (unsigned __int16)this->normalizedBounds.b[1][1];
        HIDWORD(v150) = this->normalizedBounds.b[0][1];
        v325 = *(__int64 *)((char *)&v150 + 4);
        LODWORD(v151) = (__int16)v149;
        *(_QWORD *)&v292.name.str = *(__int64 *)((char *)&v151 + 4);
        while ( --v146 >= 0 )
          v147 += 3;
        v353 = (float)*(__int64 *)((char *)&v148 + 4);
        v152 = &v346;
        v354 = (float)*(__int64 *)((char *)&v150 + 4);
        v153 = &v352;
        v355 = (float)*(__int64 *)((char *)&v151 + 4);
        v356 = (float)v150;
        v357 = (float)v151;
        v358 = (float)v148;
        for ( i19 = 6; i19 != 0; --i19 )
          *++v152 = (const char *)*++v153;
        _FP23 = v350;
        v156 = 0;
        _FP24 = v349;
        _FP25 = v348;
        _FP26 = v347.roll;
        _FP27 = v347.yaw;
        _FP28 = v347.pitch;
        while ( v156 < v292.networkID )
        {
          v162 = 16 * v156 * v55;
          v163 = (float *)(*(_DWORD *)&v292.jointConversion.value + v162);
          v164 = 3 * v156 * v55;
          v165 = *(float *)(*(_DWORD *)&v292.jointConversion.value + v162 + 8);
          v166 = *(float *)(*(_DWORD *)&v292.jointConversion.value + v162 + 4);
          v167 = (float)((float)(*v163 * v340) + (float)((float)(v163[2] * v339.yaw) + (float)(v163[3] * v339.pitch)));
          v168 = (float)((float)(*v163 * v339.roll) + (float)((float)(v163[3] * v339.yaw) + (float)(v163[1] * v340)));
          v169 = (float)-(float)((float)(*(float *)(*(_DWORD *)&v292.jointConversion.value + v162) * v339.yaw)
                               - (float)((float)(v163[1] * v339.pitch)
                                       + (float)((float)(v163[3] * v339.roll) + (float)(v163[2] * v340))));
          v361.mat[1].x = -(float)((float)(v163[2] * v339.roll)
                                 - (float)-(float)((float)(v163[1] * v339.yaw)
                                                 - (float)((float)(v163[3] * v340) - (float)(*v163 * v339.pitch))));
          v361.mat[0].z = v169;
          v361.mat[0].x = -(float)((float)((float)v166 * v339.roll) - (float)v167);
          v361.mat[0].y = -(float)((float)((float)v165 * v339.pitch) - (float)v168);
          *v163 = v361.mat[0].x;
          *(float *)(*(_DWORD *)&v292.jointConversion.value + v162 + 4) = v361.mat[0].y;
          *(float *)(*(_DWORD *)&v292.jointConversion.value + v162 + 8) = v361.mat[0].z;
          *(float *)(*(_DWORD *)&v292.jointConversion.value + v162 + 12) = v361.mat[1].x;
          v170 = v298.list;
          v171 = (float)(v298.list[v164 + 2] - (float)v122);
          v172 = (float)(v298.list[v164 + 1] - (float)v120);
          *(float *)&v292.name.str = v298.list[v164] - (float)v121;
          *(float *)&v292.resourceListPtr = v171;
          *(float *)&v292.nextOnHashChain = v172;
          idQuat::operator*(this: &v327, result: (idVec3 *)&v329, a: (const idVec3 *)&v292.name);
          v173 = v327.x;
          v170[v164] = v327.x;
          v174 = v327.y;
          v298.list[v164 + 1] = v327.y;
          v175 = v327.z;
          v298.list[v164 + 2] = v327.z;
          *(float *)&v292.name.str = v173;
          *(float *)&v292.nextOnHashChain = v174;
          *(float *)&v292.resourceListPtr = v175;
          idQuat::ToMat3(this: (idQuat *)&v375, result: &v361);
          v176 = &v359;
          v177 = &v352;
          for ( i20 = 6; i20 != 0; --i20 )
            *++v176 = *++v177;
          idBounds::FromTransformedBounds(this: v376, bounds: &v360, origin: &vec3_origin, axis: &v375);
          ++v156;
          v360.b[0].y = v360.b[0].y + (float)v174;
          v360.b[0].z = v360.b[0].z + (float)v175;
          v360.b[1].x = (float)v173 + v360.b[1].x;
          v360.b[1].y = v360.b[1].y + (float)v174;
          _FP8 = (float)((float)_FP28 - (float)((float)v173 + v360.b[0].x));
          v360.b[0].x = (float)v173 + v360.b[0].x;
          v360.b[1].z = v360.b[1].z + (float)v175;
          _FP7 = (float)((float)_FP27 - v360.b[0].y);
          _FP6 = (float)((float)_FP26 - v360.b[0].z);
          _FP5 = (float)(v360.b[1].x - (float)_FP25);
          _FP4 = (float)(v360.b[1].y - (float)_FP24);
          _FP3 = (float)(v360.b[1].z - (float)_FP23);
          __asm { fsel      f28, f8, f0, f28 }
          v347.pitch = _FP28;
          __asm { fsel      f27, f7, f13, f27 }
          v347.yaw = _FP27;
          __asm { fsel      f26, f6, f12, f26 }
          v347.roll = _FP26;
          __asm { fsel      f25, f5, f11, f25 }
          v348 = _FP25;
          __asm { fsel      f24, f4, f10, f24 }
          v349 = _FP24;
          __asm { fsel      f23, f3, f9, f23 }
          v350 = _FP23;
        }
        _R10 = 8;
        __asm { vspltisw128 v61, 0 }
        _R11 = &v347;
        _R9 = 24;
        _R8 = &v347;
        _R7 = &v347;
        _R6 = 16;
        _R5 = &v347;
        __asm { lvrx128   v60, r9, r11 }
        __asm { lvlx128   v59, r10, r8 }
        __asm { vor128    v58, v91, v60 }
        _R11 = &idBoundsShort::vector_float_max_ushort;
        __asm { lvrx128   v57, r6, r7 }
        _R9 = idBoundsShort::vector_int_max_ushort;
        __asm { lvlx128   v56, r0, r5 }
        __asm { vor128    v55, v88, v57 }
        _R7 = &v347;
        __asm { vsldoi128 v54, v90, v61, 4 }
        _R6 = idBoundsShort::vector_int_zero;
        __asm { lvx128    v63, r0, r11 }
        _R5 = &v347;
        __asm { lvx128    v0, r0, r9 }
        _R4 = &v347;
        __asm { vrlimi128 v55, v61, 1, 0 }
        _R11 = &this->translatedBounds;
        __asm { vsubfp128 v53, v86, v63 }
        _R3 = 4;
        __asm
        {
          lvx128    v62, r0, r6
          stvx128   v61, r0, r7
          vaddfp128 v52, v87, v63
          stvx128   v61, r0, r5
          stvx128   v61, r0, r4
          vcfpsxws128 v13, v53, 0
          vcfpsxws128 v12, v52, 0
          vaddsws   v11, v13, v0
          vsubsws   v10, v12, v0
          vpkswss128 v51, v11, v62
          vpkswss128 v50, v10, v62
          vsldoi128 v49, v93, v51, 0xA
          vor128    v48, v82, v49
          vspltw128 v47, v48, 0
          vspltw128 v46, v48, 1
          vspltw128 v45, v48, 2
          stvewx128 v47, r0, r11
          stvewx128 v46, r11, r3
          stvewx128 v45, r11, r10
        }
        v105 = v298.list;
        v104 = *(_DWORD *)&v292.jointConversion.value;
      }
    }
    v200 = (idMem *)v292.staleCount;
    if ( v103[17] != 0 )
    {
      v201 = 0;
      v202 = *(_DWORD *)(*((_DWORD *)&v292.idResource + 8) + 40);
      v203 = *(unsigned __int16 *)(v202 + 8);
      v204 = *(unsigned __int16 *)(v202 + 2);
      v205 = ((16 * (v204 + 7)) & 0xFFF80) + v203 + v202;
      v292.name.str = (const char *)(v203 + v202);
      v206 = 28 * (((_WORD)v204 + 7) & 0xFFF8) + v203 + v202;
      while ( v201 < v292.networkID )
      {
        v207 = 0;
        while ( v207 < v55 )
        {
          v208 = &v292.name.str[16 * v207];
          v209 = v201 * v55 + v207;
          v210 = *((float *)v208 + 1);
          v211 = 3 * v209;
          v212 = *((float *)v208 + 2);
          v213 = *((float *)v208 + 3);
          v215 = (float *)(16 * v209 + v104);
          v353 = *(float *)v208;
          v214 = &v300.list[3 * v209];
          v216 = v205 + 12 * v207;
          v354 = v210;
          v355 = v212;
          v356 = v213;
          v218 = *(float *)(v206 + 12 * v207);
          v219 = *(float *)(v216 + 4);
          v220 = *(float *)(v216 + 8);
          v221 = v105[3 * v209];
          *((float *)&v325 + 1) = v214[1];
          v222 = v215[3];
          v223 = v214[2];
          v361.mat[2].x = v220;
          v347.roll = v215[2];
          v348 = v222;
          v224 = *v214;
          v217 = &v105[3 * v209];
          v225 = v206 + 12 * v207;
          v226 = *(float *)(v205 + 12 * v207);
          v329.pitch = v221;
          v327.x = v218;
          v227 = *v215;
          v228 = v215[1];
          *(float *)&v325 = v224;
          v361.mat[1].y = v226;
          v326 = v223;
          v347.pitch = v227;
          v229 = v210;
          v347.yaw = v228;
          v230 = v353;
          v231 = *(float *)(v225 + 4);
          v232 = v217[1];
          v233 = v217[2];
          v234 = *(float *)(v225 + 8);
          v361.mat[1].z = v219;
          v327.y = v231;
          v329.yaw = v232;
          v235 = v348;
          v329.roll = v233;
          v327.z = v234;
          v236 = (float)(v223 / v361.mat[2].x);
          v237 = (float)(v329.pitch - v327.x);
          v238 = (float)(*((float *)&v325 + 1) / v219);
          v239 = v356;
          v240 = v347.roll;
          v241 = (float)(v232 - v231);
          v55 = v309;
          v200 = (idMem *)v292.staleCount;
          ++v207;
          v242 = (float)-(float)((float)((float)v229 * v347.pitch)
                               - (float)((float)(v347.roll * v356) - (float)(v355 * v348)));
          v243 = (float)((float)(v347.pitch * v353) + (float)((float)(v347.roll * v355) + (float)((float)v229 * v228)));
          v244 = (float)-(float)((float)(v355 * v228) - (float)((float)(v356 * v347.pitch) - (float)(v353 * v348)));
          v215[1] = (float)(v355 * v347.pitch)
                  - (float)((float)(v347.roll * v353) - (float)((float)(v228 * v356) - (float)((float)v229 * v348)));
          v215[2] = (float)(v228 * (float)v230) + (float)v242;
          v215[3] = (float)((float)v239 * (float)v235) + (float)v243;
          *v215 = (float)((float)v229 * (float)v240) + (float)v244;
          *v214 = v224 / v226;
          v214[1] = v238;
          v214[2] = v236;
          v105[v211] = v237;
          v217[1] = v241;
          v217[2] = v233 - v234;
          v106 = this;
          v104 = *(_DWORD *)&v292.jointConversion.value;
          v105 = v298.list;
        }
        v103 = v299;
        ++v201;
      }
    }
    idMD6Anim::CompressAnim(
      this: v106,
      skel: *((idHandle<unsigned short,enum invalidJointHandle_t,65535> **)&v292.idResource + 8),
      mappedSkeletons: (const idList<idMD6Skel const *,5> *)&v342,
      rotation: (const idList<float,5> *)&v292.jointConversion,
      scale: (const idList<float,5> *)&v300,
      translation: (const idList<float,5> *)&v298,
      userChannels: (const idList<float,5> *)&v323,
      maskRJoints: (const idList<idIndex<short,enum invalidJointIndex_t>,5> *)&v315,
      maskSJoints: v266,
      maskTJoints: v267,
      maskUChannels: v268,
      jointWeights: v269,
      flags: v270,
      numFrames: v271,
      frameRate: v272,
      animSettings: v273,
      a17: v274,
      a18: (int)v275,
      a19: v276,
      a20: (int)v277,
      a21: v278,
      a22: (int)v279,
      a23: v280,
      a24: (int)v281,
      a25: v282,
      a26: (int)v283,
      a27: v284,
      a28: &v316,
      a29: v285,
      a30: &v314,
      a31: v286,
      a32: &v328,
      a33: v287,
      a34: (int)&v310,
      a35: v288,
      maskSJoints_2: v301,
      a37: v289,
      maskTJointsa: v292.networkID,
      a39: v290,
      maskUChannels_2: v337,
      a41: v291,
      jointWeightsa: (const idList<float,5> *)v103);
    if ( (v342.listStatic == 0 || v342.listStatic == 2) && v342.list != nullptr )
    {
      for ( i21 = 0; i21 < v342.size; ++i21 )
        ;
      idMem::Free(this: v200, ptr: v342.list, align: ALIGN_16);
    }
    if ( v323.listStatic == 0 || v323.listStatic == 2 )
    {
      if ( v323.list != nullptr )
      {
        for ( i22 = 0; i22 < v323.size; ++i22 )
          ;
        idMem::Free(this: v200, ptr: v323.list, align: ALIGN_16);
      }
      v323.list = nullptr;
      v323.size = 0;
    }
    v323.num = 0;
    if ( v298.listStatic == 0 || v298.listStatic == 2 )
    {
      if ( v298.list != nullptr )
      {
        for ( i23 = 0; i23 < v298.size; ++i23 )
          ;
        idMem::Free(this: v200, ptr: v298.list, align: ALIGN_16);
      }
      v298.list = nullptr;
      v298.size = 0;
    }
    v298.num = 0;
    if ( v300.listStatic == 0 || v300.listStatic == 2 )
    {
      if ( v300.list != nullptr )
      {
        for ( i24 = 0; i24 < v300.size; ++i24 )
          ;
        idMem::Free(this: v200, ptr: v300.list, align: ALIGN_16);
      }
      v300.list = nullptr;
      v300.size = 0;
    }
    v300.num = 0;
    if ( v297 == 0 || v297 == 2 )
    {
      if ( *(_DWORD *)&v292.jointConversion.value != 0 )
      {
        for ( i25 = 0; i25 < v294; ++i25 )
          ;
        idMem::Free(this: v200, ptr: *(void **)&v292.jointConversion.value, align: ALIGN_16);
      }
      *(_DWORD *)&v292.jointConversion.value = 0;
      v294 = 0;
    }
    v293 = 0;
    if ( (v328.listStatic == 0 || v328.listStatic == 2) && v328.list != nullptr )
    {
      for ( i26 = 0; i26 < v328.size; ++i26 )
        ;
      idMem::Free(this: v200, ptr: v328.list, align: ALIGN_16);
    }
    if ( (v314.listStatic == 0 || v314.listStatic == 2) && v314.list != nullptr )
    {
      for ( i27 = 0; i27 < v314.size; ++i27 )
        ;
      idMem::Free(this: v200, ptr: v314.list, align: ALIGN_16);
    }
    if ( (v316.listStatic == 0 || v316.listStatic == 2) && v316.list != nullptr )
    {
      for ( i28 = 0; i28 < v316.size; ++i28 )
        ;
      idMem::Free(this: v200, ptr: v316.list, align: ALIGN_16);
    }
    if ( (v315.listStatic == 0 || v315.listStatic == 2) && v315.list != nullptr )
    {
      for ( i29 = 0; i29 < v315.size; ++i29 )
        ;
      idMem::Free(this: v200, ptr: v315.list, align: ALIGN_16);
    }
    if ( (v318.listStatic == 0 || v318.listStatic == 2) && v318.list != nullptr )
    {
      for ( i30 = 0; i30 < v318.size; ++i30 )
        ;
      idMem::Free(this: v200, ptr: v318.list, align: ALIGN_16);
    }
    if ( (v320.listStatic == 0 || v320.listStatic == 2) && v320.list != nullptr )
    {
      for ( i31 = 0; i31 < v320.size; ++i31 )
        ;
      idMem::Free(this: v200, ptr: v320.list, align: ALIGN_16);
    }
    if ( (v310.listStatic == 0 || v310.listStatic == 2) && v310.list != nullptr )
    {
      for ( i32 = 0; i32 < v310.size; ++i32 )
        ;
      idMem::Free(this: v200, ptr: v310.list, align: ALIGN_16);
    }
    if ( (v324.listStatic == 0 || v324.listStatic == 2) && v324.list != nullptr )
    {
      for ( i33 = 0; i33 < v324.size; ++i33 )
        ;
      idMem::Free(this: v200, ptr: v324.list, align: ALIGN_16);
    }
    idStr::FreeData(this: &v365);
    idStr::FreeData(this: (idStr *)&v302.nextOnHashChain);
    idStr::idStr(this: &v372, text: v106->name.str);
    idStr::SetFileExtension(this: &v372, extension: "ptrack");
    v258 = fileSystem->GetTimestamp(this: fileSystem, a2: v372.data, a3: false);
    v106->phaseTrackTimestamp = v258;
    if ( v258 != -1 )
      idMD6PhaseTrack::LoadText(this: &v106->phaseTrack, fileName: v372.data, anim: v106);
    idStr::FreeData(this: &v372);
    idParser::~idParser(this: &v369);
    idStr::FreeData(this: &v366);
    idStr::FreeData(this: (idStr *)&v361.mat[2].z);
    return 1;
  }
}


// ========================================================================
// $M254454
// EA  : 0x82838D48
// RVA : 0x00838D48
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _M254454()
{
  idLib::Error(fmt: "idMD6Anim::LoadText - %s", idException::error);
  JUMPOUT(0x82838D68);
}


// ========================================================================
// $M254457
// EA  : 0x82838D70
// RVA : 0x00838D70
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void *_M254457()
{
  return &_M253938;
}


// ========================================================================
// $M254460
// EA  : 0x82838D8C
// RVA : 0x00838D8C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

int _M254460()
{
  idLib::Error(fmt: "idMD6Anim::LoadText - %s", idException::error);
  return _LN2114();
}


// ========================================================================
// $LN2114
// EA  : 0x82838DAC
// RVA : 0x00838DAC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _LN2114()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 896));
}


// ========================================================================
// __unwind$250927
// EA  : 0x82838DD4
// RVA : 0x00838DD4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250927()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 1008));
}


// ========================================================================
// __unwind$250928
// EA  : 0x82838DFC
// RVA : 0x00838DFC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250928()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 2352 + 1152));
}


// ========================================================================
// __unwind$250929
// EA  : 0x82838E24
// RVA : 0x00838E24
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 272));
}


// ========================================================================
// __unwind$250930
// EA  : 0x82838E4C
// RVA : 0x00838E4C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 928));
}


// ========================================================================
// __unwind$250931
// EA  : 0x82838E74
// RVA : 0x00838E74
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 1040));
}


// ========================================================================
// __unwind$250932
// EA  : 0x82838E9C
// RVA : 0x00838E9C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250932()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 544));
}


// ========================================================================
// __unwind$250933
// EA  : 0x82838EC4
// RVA : 0x00838EC4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250933()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 352));
}


// ========================================================================
// __unwind$250934
// EA  : 0x82838EEC
// RVA : 0x00838EEC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250934()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 496));
}


// ========================================================================
// __unwind$250935
// EA  : 0x82838F14
// RVA : 0x00838F14
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250935()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 464));
}


// ========================================================================
// __unwind$250936
// EA  : 0x82838F3C
// RVA : 0x00838F3C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 1072));
}


// ========================================================================
// __unwind$250937
// EA  : 0x82838F64
// RVA : 0x00838F64
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250937()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 1808));
}


// ========================================================================
// __unwind$250938
// EA  : 0x82838F8C
// RVA : 0x00838F8C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250938()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 416));
}


// ========================================================================
// __unwind$250939
// EA  : 0x82838FB4
// RVA : 0x00838FB4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250939()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 432));
}


// ========================================================================
// __unwind$250940
// EA  : 0x82838FDC
// RVA : 0x00838FDC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250940()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 400));
}


// ========================================================================
// __unwind$250941
// EA  : 0x82839004
// RVA : 0x00839004
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250941()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 592));
}


// ========================================================================
// __unwind$250942
// EA  : 0x8283902C
// RVA : 0x0083902C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 192));
}


// ========================================================================
// __unwind$250943
// EA  : 0x82839054
// RVA : 0x00839054
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250943()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 240));
}


// ========================================================================
// __unwind$250944
// EA  : 0x8283907C
// RVA : 0x0083907C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250944()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 208));
}


// ========================================================================
// __unwind$250945
// EA  : 0x828390A4
// RVA : 0x008390A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250945()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 528));
}


// ========================================================================
// __unwind$250946
// EA  : 0x828390CC
// RVA : 0x008390CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250946()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2352 + 688));
}


// ========================================================================
// __unwind$250947
// EA  : 0x828390F4
// RVA : 0x008390F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_250947()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2352 + 1920));
}


// ========================================================================
// ?LoadResource@idMD6Anim@@UAAXXZ
// EA  : 0x82839128
// RVA : 0x00839128
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __fastcall idMD6Anim::LoadResource(idMD6Anim *this)
{
  idMD6AnimData *animData; // r4
  int v3; // r11
  bool v4; // r29
  idResource *v5; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  idStr *v12; // r3
  float *v13; // r5
  idMD6AnimData *v14; // r11
  int v15; // r10
  char v16; // r11
  int v17; // [sp+8h] [-1E8h]
  int v18; // [sp+Ch] [-1E4h]
  int v19; // [sp+10h] [-1E0h]
  int v20; // [sp+14h] [-1DCh]
  int v21; // [sp+18h] [-1D8h]
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v22; // [sp+1Ch] [-1D4h]
  float v23; // [sp+50h] [-1A0h] BYREF
  idStr v24; // [sp+60h] [-190h] BYREF
  idStr v25; // [sp+80h] [-170h] BYREF
  idStr v26; // [sp+A0h] [-150h] BYREF
  char v27[304]; // [sp+C0h] [-130h] BYREF

  animData = this->animData;
  if ( animData != nullptr )
  {
    idMem::Free(this: &mem, ptr: animData, align: ALIGN_16);
    this->animData = nullptr;
  }
  idMD6PhaseTrack::~idMD6PhaseTrack(this: &this->phaseTrack);
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6anim", a4: this->name.str, a5: v27, a6: 256);
  if ( (unsigned __int8)idMD6Anim::LoadBinary(this, filename: v27) == 0 )
  {
    idStr::idStr(this: &v24, text: this->name.str);
    idStr::StripPath(this: &v24);
    v3 = 0;
    if ( *idMD6Anim::UNCOMPRESSED_ANIM_NAME != 0 )
    {
      do
        ++v3;
      while ( idMD6Anim::UNCOMPRESSED_ANIM_NAME[v3] != 0 );
    }
    v4 = false;
    if ( v24.len > v3 )
      v4 = idStr::Cmp(s1: &v24.data[v24.len - v3], s2: idMD6Anim::UNCOMPRESSED_ANIM_NAME) == 0;
    if ( idMD6Anim::skipJoints || idStr::Cmp(s1: v24.data, s2: idMD6Model::DEFAULT_ANIM_NAME) != 0 )
    {
      idStr::idStr(this: &v26, text: this->name.str);
      v13 = nullptr;
      v23 = 0.0;
      if ( v4 )
      {
        idStr::Replace(this: &v26, old: idMD6Anim::UNCOMPRESSED_ANIM_NAME, nw: ".md6anim");
        v13 = &v23;
      }
      if ( (unsigned __int8)idMD6Anim::LoadText(this, filename: v26.data, errorToleranceOverride: v13) == 0 )
      {
        idStr::FreeData(this: &v26);
LABEL_24:
        idStr::FreeData(this: &v24);
        return;
      }
      v14 = this->animData;
      if ( v14 == nullptr || (v15 = v14->flags & 0x40, v16 = 1, v15 == 0) )
        v16 = 0;
      if ( v16 == 0
        || anim_allowDefaultedBinaryAnims.valueInteger != 0
        || resourceManager->GetBuildPlatforms(this: resourceManager) != 0 )
      {
        idMD6Anim::WriteBinary(this, filename: v27);
      }
      v12 = &v26;
    }
    else
    {
      idStr::idStr(this: &v25, text: this->name.str);
      idStr::StripFilename(this: &v25);
      idStr::SetFileExtension(this: &v25, extension: MD6_SKEL_EXT);
      v5 = idResourceList::Load(
             this: &idMD6Skel::resourceList,
             name: v25.data,
             makeDefault: true,
             skipStaleCheck: false);
      idMD6Anim::MakeDefault(
        this,
        skel: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v5,
        a3: v11,
        a4: v10,
        a5: v9,
        a6: v8,
        a7: v7,
        a8: v6,
        a9: v17,
        a10: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22);
      idMD6Anim::WriteBinary(this, filename: v27);
      v12 = &v25;
    }
    idStr::FreeData(this: v12);
    goto LABEL_24;
  }
}


// ========================================================================
// __unwind$254562
// EA  : 0x8283938C
// RVA : 0x0083938C
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_254562()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 96));
}


// ========================================================================
// __unwind$254563
// EA  : 0x828393B4
// RVA : 0x008393B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_254563()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 128));
}


// ========================================================================
// __unwind$254564
// EA  : 0x828393DC
// RVA : 0x008393DC
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void _unwind_254564()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 160));
}


// ========================================================================
// `dynamic initializer for 'idMD6Anim::resourceList''
// EA  : 0x83344010
// RVA : 0x01344010
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idMD6Anim::resourceList__()
{
  idResourceList::idResourceList(this: &idMD6Anim::resourceList, typeName: "anim");
  idMD6Anim::resourceList.__vftable = (idTypedResourceList<idMD6Anim>_vtbl *)&idTypedResourceList<idMD6Anim>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idMD6Anim::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'anim_allowDefaultedBinaryAnims''
// EA  : 0x83344060
// RVA : 0x01344060
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_allowDefaultedBinaryAnims__()
{
  idCVar::idCVar(
    this: &anim_allowDefaultedBinaryAnims,
    name: "anim_allowDefaultedBinaryAnims",
    value: "0",
    flags: 1,
    description: "If set to 1, allows defaulted binary anims to be written. This should only be set as a last resort for building resource packages.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_allowDefaultedBinaryAnims__);
}


// ========================================================================
// `dynamic initializer for 'anim_removeDefaultedAnimFiles''
// EA  : 0x833440B8
// RVA : 0x013440B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_removeDefaultedAnimFiles__()
{
  idCVar::idCVar(
    this: &anim_removeDefaultedAnimFiles,
    name: "anim_removeDefaultedAnimFiles",
    value: "0",
    flags: 1,
    description: "If set to 1, any generated binary .bmd6anim files that have the defaulted flag set on load are deleted from the generated cache.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_removeDefaultedAnimFiles__);
}


// ========================================================================
// `dynamic initializer for 'anim_forceCompression''
// EA  : 0x83344110
// RVA : 0x01344110
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_forceCompression__()
{
  idCVar::idCVar(
    this: &anim_forceCompression,
    name: "anim_forceCompression",
    value: "-1",
    flags: 4,
    description: "If >= 0, force animation compression values to this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_forceCompression__);
}


// ========================================================================
// `dynamic initializer for 'anim_checkCompressionError_v''
// EA  : 0x83344168
// RVA : 0x01344168
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_checkCompressionError_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_checkCompressionError_v,
           cmdName: "anim_checkCompressionError",
           function: anim_checkCompressionError_f,
           description: "checks the compression error setting for animations in the specified folder",
           argCompletion: idTestModel2::ArgCompletion_Anim);
}

