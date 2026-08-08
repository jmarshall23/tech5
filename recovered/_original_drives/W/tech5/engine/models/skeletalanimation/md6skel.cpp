
// ========================================================================
// ?GetUserChannelHandle@idMD6Skel@@QBA?AV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@H@Z
// EA  : 0x828534B0
// RVA : 0x008534B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetUserChannelHandle(
        idMD6Skel *this,
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *result,
        const int userChannelIdx)
{
  HIWORD(this->__vftable) = *(_WORD *)(*(unsigned __int16 *)(*(_DWORD *)&result[20].value + 18)
                                     + 2 * userChannelIdx
                                     + *(_DWORD *)&result[20].value);
  return this;
}


// ========================================================================
// ??0idMD6Skel@@QAA@XZ
// EA  : 0x82853840
// RVA : 0x00853840
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::idMD6Skel(idMD6Skel *this)
{
  idResource::idResource(this: &this->idResource);
  this->defaultAnim = nullptr;
  this->__vftable = (idMD6Skel_vtbl *)&idMD6Skel::`vftable';
  this->data = nullptr;
  this->timestamp = -1;
  this->jointConversion.value = -1;
  this->jointConversionChecksum.value = -1;
  return this;
}


// ========================================================================
// ??1idMD6Skel@@UAA@XZ
// EA  : 0x828538B8
// RVA : 0x008538B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall idMD6Skel::~idMD6Skel(idMD6Skel *this)
{
  idMD6SkelData *data; // r4

  this->__vftable = (idMD6Skel_vtbl *)&idMD6Skel::`vftable';
  data = this->data;
  if ( data != nullptr )
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
  this->data = nullptr;
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$224734
// EA  : 0x82853928
// RVA : 0x00853928
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_224734()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetJointIndex@idMD6Skel@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@ABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@@Z
// EA  : 0x82853950
// RVA : 0x00853950
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetJointIndex(
        idMD6Skel *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const idHandle<unsigned short,enum invalidJointHandle_t,65535> *handle)
{
  int value; // r7
  int v4; // r10
  int v5; // r11
  int v6; // r9
  unsigned __int16 *v7; // r10

  value = handle->value;
  if ( value == 0xFFFF
    || (v4 = *(_DWORD *)&result[20].value,
        v5 = 0,
        v6 = *(unsigned __int16 *)(v4 + 2),
        v7 = (unsigned __int16 *)(*(unsigned __int16 *)(v4 + 16) + v4),
        v6 == 0) )
  {
LABEL_5:
    LOWORD(v5) = -1;
  }
  else
  {
    while ( *v7 != value )
    {
      ++v5;
      ++v7;
      if ( v5 >= v6 )
        goto LABEL_5;
    }
  }
  HIWORD(this->__vftable) = v5;
  return this;
}


// ========================================================================
// ?GetJointIndex@idMD6Skel@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@PBD@Z
// EA  : 0x828539A8
// RVA : 0x008539A8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetJointIndex(
        idMD6Skel *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const char *name)
{
  int v5; // r7
  int v6; // r10
  int v7; // r11
  int v8; // r9
  unsigned __int16 *v9; // r10
  _BYTE v11[8]; // [sp+50h] [-20h] BYREF

  v5 = *(unsigned __int16 *)((int (__fastcall *)(_BYTE *))animation->RegisterJoint)(a1: v11);
  if ( v5 == 0xFFFF
    || (v6 = *(_DWORD *)&result[20].value,
        v7 = 0,
        v8 = *(unsigned __int16 *)(v6 + 2),
        v9 = (unsigned __int16 *)(*(unsigned __int16 *)(v6 + 16) + v6),
        v8 == 0) )
  {
LABEL_5:
    LOWORD(v7) = -1;
  }
  else
  {
    while ( *v9 != v5 )
    {
      ++v7;
      ++v9;
      if ( v7 >= v8 )
        goto LABEL_5;
    }
  }
  HIWORD(this->__vftable) = v7;
  return this;
}


// ========================================================================
// ?GetJointHandle@idMD6Skel@@QBA?AV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@H@Z
// EA  : 0x82853A50
// RVA : 0x00853A50
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetJointHandle(
        idMD6Skel *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *result,
        const int jointIdx)
{
  HIWORD(this->__vftable) = *(_WORD *)(*(unsigned __int16 *)(*(_DWORD *)&result[20].value + 16)
                                     + 2 * jointIdx
                                     + *(_DWORD *)&result[20].value);
  return this;
}


// ========================================================================
// ?GetUserChannelIndex@idMD6Skel@@QBA?AV?$idIndex@FW4invalidUserChannelIndex_t@@@@ABV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@@Z
// EA  : 0x82853A70
// RVA : 0x00853A70
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetUserChannelIndex(
        idMD6Skel *this,
        idIndex<short,enum invalidUserChannelIndex_t> *result,
        const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *handle)
{
  int v3; // r11
  int v4; // r10
  int v5; // r8
  unsigned __int16 *v6; // r11

  v3 = *(_DWORD *)&result[20].value;
  v4 = 0;
  v5 = *(unsigned __int16 *)(v3 + 4);
  v6 = (unsigned __int16 *)(*(unsigned __int16 *)(v3 + 18) + v3);
  if ( v5 != 0 )
  {
    while ( *v6 != handle->value )
    {
      ++v4;
      ++v6;
      if ( v4 >= v5 )
        goto LABEL_4;
    }
    HIWORD(this->__vftable) = v4;
  }
  else
  {
LABEL_4:
    HIWORD(this->__vftable) = -1;
  }
  return this;
}


// ========================================================================
// ?GetUserChannelIndex@idMD6Skel@@QBA?AV?$idIndex@FW4invalidUserChannelIndex_t@@@@PBD@Z
// EA  : 0x82853AC8
// RVA : 0x00853AC8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6Skel *__fastcall idMD6Skel::GetUserChannelIndex(
        idMD6Skel *this,
        idIndex<short,enum invalidUserChannelIndex_t> *result,
        const char *name)
{
  unsigned __int16 *v5; // r3
  int v6; // r11
  int v7; // r10
  int v8; // r8
  unsigned __int16 *v9; // r11
  _BYTE v11[8]; // [sp+50h] [-20h] BYREF

  v5 = (unsigned __int16 *)((int (__fastcall *)(_BYTE *))animation->RegisterUserChannel)(a1: v11);
  v6 = *(_DWORD *)&result[20].value;
  v7 = 0;
  v8 = *(unsigned __int16 *)(v6 + 4);
  v9 = (unsigned __int16 *)(*(unsigned __int16 *)(v6 + 18) + v6);
  if ( v8 != 0 )
  {
    while ( *v9 != *v5 )
    {
      ++v7;
      ++v9;
      if ( v7 >= v8 )
        goto LABEL_4;
    }
    HIWORD(this->__vftable) = v7;
  }
  else
  {
LABEL_4:
    HIWORD(this->__vftable) = -1;
  }
  return this;
}


// ========================================================================
// ?IsJointChildOf@idMD6Skel@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@0@Z
// EA  : 0x82853B70
// RVA : 0x00853B70
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::IsJointChildOf(
        idMD6Skel *this,
        idIndex<short,enum invalidJointIndex_t> *joint,
        idIndex<short,enum invalidJointIndex_t> *parent)
{
  char *v3; // r10
  int v4; // r11
  __int16 v5; // r8

  v3 = (char *)this->data + this->data->parentTblOffset;
  v4 = *(__int16 *)&v3[2 * (__int16)joint];
  if ( v4 < 0 )
    return 0;
  while ( v4 != (__int16)parent )
  {
    v5 = *(_WORD *)&v3[2 * v4];
    v4 = v5;
    if ( v5 < 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?ReloadIfStale@idMD6Skel@@UAA_NXZ
// EA  : 0x82853BC8
// RVA : 0x00853BC8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::ReloadIfStale(idMD6Skel *this)
{
  idMD6SkelData *data; // r4
  idMD6Skel_vtbl *v4; // r10
  _BYTE v5[16]; // [sp+50h] [-130h] BYREF
  _BYTE v6[264]; // [sp+60h] [-120h] BYREF

  if ( this->jointConversion.value != 0xFFFF
    && this->jointConversionChecksum.value != 0xFFFF
    && *(unsigned __int16 *)((int (__fastcall *)(_BYTE *))animation->GetJointConversionCrc)(a1: v5) == this->jointConversionChecksum.value
    && fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->timestamp )
  {
    return 0;
  }
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6skl", a4: this->name.str, a5: v6, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v6, a3: FSPATH_BASE);
  data = this->data;
  if ( data != nullptr )
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
  v4 = this->__vftable;
  this->data = nullptr;
  v4->LoadResource(this);
  return 1;
}


// ========================================================================
// ?GetUserChannelsForAnimFrame@idMD6Skel@@QBA_NPIAMIPBVidMD6Anim@@M@Z
// EA  : 0x82853D00
// RVA : 0x00853D00
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::GetUserChannelsForAnimFrame(
        idMD6Skel *this,
        float *userChannels,
        float *userChannelsSize,
        const idMD6Anim *anim,
        double frame)
{
  idMD6AnimData *animData; // r11

  if ( anim == nullptr )
    return 0;
  animData = anim->animData;
  if ( animData == nullptr || userChannels == nullptr )
    return 0;
  idMD6Blend::DecodeUserChannelsForAnimFrame(
    skeleton: this->data,
    animData,
    frame,
    outUserChannels: userChannelsSize,
    outUserChannelsSize: userChannels);
  return 1;
}


// ========================================================================
// SubChildren_r
// EA  : 0x82853ED8
// RVA : 0x00853ED8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall SubChildren_r(
        const idMD6Skel *skeleton,
        const idIndex<short,enum invalidJointIndex_t> *parent,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *jointList)
{
  idMD6SkelData *data; // r11
  int v6; // r29
  int numJoints; // r26
  idMD6SkelData *v8; // r11
  int v9; // r25
  __int16 *v10; // r28
  int num; // r8
  int v12; // r4
  int v13; // r11

  data = skeleton->data;
  v6 = 0;
  numJoints = data->numJoints;
  v8 = (idMD6SkelData *)((char *)data + data->parentTblOffset);
  if ( numJoints != 0 )
  {
    v9 = (__int16)parent;
    v10 = (__int16 *)v8;
    do
    {
      if ( v9 == *v10 )
      {
        num = jointList->num;
        v12 = 0;
        if ( num > 0 )
        {
          v13 = 0;
          while ( jointList->list[v13].value != (__int16)v6 )
          {
            ++v12;
            ++v13;
            if ( v12 >= num )
              goto LABEL_11;
          }
          if ( v12 >= 0 )
            idList<idIndex<short,enum invalidJointIndex_t>,5>::RemoveIndex(this: jointList, index: v12);
        }
LABEL_11:
        SubChildren_r(skeleton, parent: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v6, jointList);
      }
      ++v6;
      ++v10;
    }
    while ( v6 < numJoints );
  }
}


// ========================================================================
// ?LoadBinary@idMD6Skel@@AAA_NPBD@Z
// EA  : 0x82853FA8
// RVA : 0x00853FA8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::LoadBinary(idMD6Skel *this, const char *fileName)
{
  idFile *v4; // r3
  int v5; // r29
  idMD6SkelData *v6; // r3
  idFile *file; // r3
  unsigned __int16 v8; // r10
  idMD6SkelData *data; // r11
  int jointHandleTblOffset; // r10
  _WORD *v11; // r28
  int v12; // r27
  idMD6SkelData *v13; // r11
  int userChannelHandleTblOffset; // r10
  _WORD *v15; // r28
  idMD6SkelData *v16; // r11
  idFile_vtbl *v17; // r7
  int v18; // r6
  int basePoseOffset; // r8
  int v20; // r10
  idMD6SkelData *v22; // [sp+50h] [-D0h] BYREF
  idFileLocal v23; // [sp+54h] [-CCh] BYREF
  unsigned int v24; // [sp+58h] [-C8h] BYREF
  unsigned int v25; // [sp+5Ch] [-C4h] BYREF
  idStr v26; // [sp+60h] [-C0h] BYREF
  idStr v27; // [sp+80h] [-A0h] BYREF
  idStr v28[4]; // [sp+A0h] [-80h] BYREF

  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v23.file = v4;
  if ( v4 != nullptr )
  {
    v4->Read(this: v4, a2: &v25, a3: 4u);
    if ( v25 == 137777997 )
    {
      v23.file->Read(this: v23.file, a2: &this->timestamp, a3: 4u);
      v5 = 0;
      v24 = 0;
      v23.file->Read(this: v23.file, a2: &v24, a3: 4u);
      v6 = (idMD6SkelData *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Skel.cpp(1089) : TAG_MD6",
                              size: v24,
                              tag: TAG_MD6,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      this->data = v6;
      v23.file->Read(this: v23.file, a2: v6, a3: v24);
      v28[0].len = 0;
      v28[0].baseBuffer[0] = 0;
      v28[0].allocedAndFlag = 20;
      v28[0].data = v28[0].baseBuffer;
      idFile::ReadString(this: v23.file, string: v28);
      v8 = *(_WORD *)((int (__fastcall *)(idMD6SkelData **))animation->FindJointConversionHandle)(a1: &v22);
      file = v23.file;
      this->jointConversion.value = v8;
      file->Read(this: file, a2: &this->jointConversionChecksum, a3: 2u);
      data = this->data;
      jointHandleTblOffset = data->jointHandleTblOffset;
      v27.len = 0;
      v27.baseBuffer[0] = 0;
      v11 = (unsigned __int16 *)((char *)&data->size + jointHandleTblOffset);
      v22 = data;
      v27.allocedAndFlag = 20;
      v27.data = v27.baseBuffer;
      v12 = 0;
      if ( ((data->numJoints + 7) & 0xFFF8) != 0 )
      {
        do
        {
          idFile::ReadString(this: v23.file, string: &v27);
          if ( v27.len != 0 )
            *v11 = *(_WORD *)((int (__fastcall *)(idMD6SkelData **))animation->RegisterJoint)(a1: &v22);
          else
            *v11 = -1;
          ++v12;
          ++v11;
        }
        while ( v12 < ((this->data->numJoints + 7) & 0xFFF8) );
      }
      v13 = this->data;
      userChannelHandleTblOffset = v13->userChannelHandleTblOffset;
      v22 = v13;
      v26.allocedAndFlag = 20;
      v15 = (unsigned __int16 *)((char *)&v13->size + userChannelHandleTblOffset);
      v26.data = v26.baseBuffer;
      v26.len = 0;
      v26.baseBuffer[0] = 0;
      if ( ((v13->numUserChannels + 7) & 0xFFF8) != 0 )
      {
        do
        {
          idFile::ReadString(this: v23.file, string: &v26);
          if ( v26.len != 0 )
            *v15 = *(_WORD *)((int (__fastcall *)(idMD6SkelData **))animation->RegisterUserChannel)(a1: &v22);
          else
            *v15 = -1;
          ++v5;
          ++v15;
        }
        while ( v5 < ((this->data->numUserChannels + 7) & 0xFFF8) );
      }
      v16 = this->data;
      v17 = v23.file->__vftable;
      v18 = v16->numUserChannels + 7;
      basePoseOffset = v16->basePoseOffset;
      v20 = (v16->numJoints + 7) & 0xFFF8;
      v22 = v16;
      v17->Read(this: v23.file, a2: (char *)v16 + 40 * v20 + basePoseOffset, a3: (4 * v18) & 0x3FFE0);
      if ( v23.file->Read(this: v23.file, a2: &v25, a3: 4u) != 0 && v25 == 137777997 )
      {
        idStr::FreeData(this: &v26);
        idStr::FreeData(this: &v27);
        idStr::FreeData(this: v28);
        idFileLocal::~idFileLocal(this: &v23);
        return 1;
      }
      idLib::Warning(fmt: "%s is corrupt ( %d != %d )", fileName, v25, 137777997);
      idStr::FreeData(this: &v26);
      idStr::FreeData(this: &v27);
      idStr::FreeData(this: v28);
    }
    else if ( (v25 & 0xFFFFFF) == 0x36534D )
    {
      if ( HIBYTE(v25) != 8 )
        idLib::Warning(fmt: "Skeleton version mismatch. Expected %d, found %d.", 8, HIBYTE(v25));
    }
    else
    {
      idLib::Warning(fmt: "File is not a valid bmd6skl file.");
    }
  }
  idFileLocal::~idFileLocal(this: &v23);
  return 0;
}


// ========================================================================
// __unwind$226499
// EA  : 0x82854388
// RVA : 0x00854388
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226499()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 288 + 84));
}


// ========================================================================
// __unwind$226500
// EA  : 0x828543B0
// RVA : 0x008543B0
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$226501
// EA  : 0x828543D8
// RVA : 0x008543D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226501()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$226502
// EA  : 0x82854400
// RVA : 0x00854400
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226502()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ?WriteBinary@idMD6Skel@@QBA_NPBD@Z
// EA  : 0x82854430
// RVA : 0x00854430
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::WriteBinary(idMD6Skel *this, const char *fileName)
{
  const char *v5; // r3
  int v6; // r29
  idMD6SkelData *data; // r11
  int jointHandleTblOffset; // r9
  __int16 v9; // r8
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v10; // r28
  const char *v11; // r4
  idFile *file; // r3
  int v13; // r28
  int userChannelHandleTblOffset; // r9
  __int16 v15; // r10
  const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v16; // r29
  const char *v17; // r4
  idFile *v18; // r3
  idMD6SkelData *v19; // r11
  idFile_vtbl *v20; // r7
  int v21; // r6
  int basePoseOffset; // r9
  int v23; // r10
  idFileLocal v24; // [sp+50h] [-60h] BYREF
  unsigned int size; // [sp+54h] [-5Ch] BYREF
  idMD6SkelData *v26; // [sp+58h] [-58h]

  v24.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  if ( v24.file != nullptr )
  {
    idLib::Printf(fmt: "Writing %s\n", fileName);
    v24.file->Write(this: v24.file, a2: &MD6_SKEL_MAGIC, a3: 4u);
    v24.file->Write(this: v24.file, a2: &this->timestamp, a3: 4u);
    size = this->data->size;
    v24.file->Write(this: v24.file, a2: &size, a3: 4u);
    v24.file->Write(this: v24.file, a2: this->data, a3: size);
    v5 = animation->GetJointConversionName(this: animation, a2: &this->jointConversion);
    idFile::WriteString(this: v24.file, string: v5);
    v24.file->Write(this: v24.file, a2: &this->jointConversionChecksum, a3: 2u);
    v6 = 0;
    data = this->data;
    jointHandleTblOffset = data->jointHandleTblOffset;
    v9 = data->numJoints + 7;
    v26 = data;
    v10 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((char *)data + jointHandleTblOffset);
    if ( (v9 & 0xFFF8) != 0 )
    {
      do
      {
        if ( v10->value == 0xFFFF )
        {
          file = v24.file;
          v11 = &byte_8200D768;
        }
        else
        {
          v11 = animation->GetJointName(this: animation, a2: v10);
          file = v24.file;
        }
        idFile::WriteString(this: file, string: v11);
        data = this->data;
        ++v6;
        ++v10;
      }
      while ( v6 < ((data->numJoints + 7) & 0xFFF8) );
    }
    v13 = 0;
    userChannelHandleTblOffset = data->userChannelHandleTblOffset;
    v15 = data->numUserChannels + 7;
    v26 = data;
    v16 = (const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)((char *)data
                                                                                 + userChannelHandleTblOffset);
    if ( (v15 & 0xFFF8) != 0 )
    {
      do
      {
        if ( v16->value == 0xFFFF )
        {
          v18 = v24.file;
          v17 = &byte_8200D768;
        }
        else
        {
          v17 = animation->GetUserChannelName(this: animation, a2: v16);
          v18 = v24.file;
        }
        idFile::WriteString(this: v18, string: v17);
        ++v13;
        ++v16;
      }
      while ( v13 < ((this->data->numUserChannels + 7) & 0xFFF8) );
    }
    v19 = this->data;
    v20 = v24.file->__vftable;
    v21 = v19->numUserChannels + 7;
    basePoseOffset = v19->basePoseOffset;
    v23 = (v19->numJoints + 7) & 0xFFF8;
    v26 = v19;
    v20->Write(this: v24.file, a2: (char *)v19 + 40 * v23 + basePoseOffset, a3: (4 * v21) & 0x3FFE0);
    v24.file->Write(this: v24.file, a2: &MD6_SKEL_MAGIC, a3: 4u);
    idFileLocal::~idFileLocal(this: &v24);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Could not open %s", fileName);
    idFileLocal::~idFileLocal(this: &v24);
    return 0;
  }
}


// ========================================================================
// __unwind$226805_0
// EA  : 0x828546F4
// RVA : 0x008546F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226805_0()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 176 + 80));
}


// ========================================================================
// ?WriteSkeletonConfig_Binary@idMD6SkeletonConfig@@AAA_NPBD@Z
// EA  : 0x82854728
// RVA : 0x00854728
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6SkeletonConfig::WriteSkeletonConfig_Binary(idMD6SkeletonConfig *this, const char *filename)
{
  idFile *v4; // r3
  int v6; // r28
  int v7; // r30
  const idMD6Skel *skeleton; // r11
  const char *str; // r4
  const idDeclMD6 *boundsDecl; // r11
  const char *v11; // r4
  idFileLocal v12; // [sp+50h] [-40h] BYREF
  int num; // [sp+54h] [-3Ch] BYREF

  v4 = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  v12.file = v4;
  if ( v4 != nullptr )
  {
    v4->Write(this: v4, a2: &SKELETONCONFIG_MAGIC, a3: 4u);
    num = this->instances.num;
    v12.file->Write(this: v12.file, a2: &num, a3: 4u);
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        v12.file->Write(this: v12.file, a2: &this->instances.list[v7].timestamp, a3: 4u);
        skeleton = this->instances.list[v7].skeleton;
        if ( skeleton != nullptr )
          str = skeleton->name.str;
        else
          str = &byte_8200D768;
        idFile::WriteString(this: v12.file, string: str);
        ++v6;
        ++v7;
      }
      while ( v6 < num );
    }
    boundsDecl = this->boundsDecl;
    if ( boundsDecl != nullptr )
      v11 = boundsDecl->name.str;
    else
      v11 = &byte_8200D768;
    idFile::WriteString(this: v12.file, string: v11);
    idFileLocal::~idFileLocal(this: &v12);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Could not write '%s'", filename);
    idFileLocal::~idFileLocal(this: &v12);
    return 0;
  }
}


// ========================================================================
// __unwind$226943
// EA  : 0x82854874
// RVA : 0x00854874
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_226943()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetJointsForAnimFrame@idMD6Skel@@QBA_NPAVidJointMat@@PBVidMD6Anim@@HABVidVec3@@_N@Z
// EA  : 0x828548A0
// RVA : 0x008548A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::GetJointsForAnimFrame(
        idMD6Skel *this,
        idJointMat *joints,
        const idMD6Anim *anim,
        const int frame,
        const idVec3 *offset,
        const bool removeOriginOffset)
{
  idMD6AnimData *animData; // r11
  unsigned int frameRate; // r26
  idMD6SkelData *data; // r3
  int v12; // r30
  int numJoints; // r4
  float *v14; // r11
  int v15; // r3
  int v16; // r12
  const idMD6SkelData *v17; // r3
  int v18; // r5
  const idMD6AnimData *v19; // r6
  int v20; // r9
  int v21; // r12
  const float *v22; // r10
  __int64 v23; // r8
  int v24; // r11
  _DWORD back_chain[2]; // [sp+0h] [-B0h]
  bool v27; // [sp+Bh] [-A5h]
  float *v28; // [sp+Ch] [-A4h]
  float *v29; // [sp+10h] [-A0h]
  int v30; // [sp+14h] [-9Ch]
  int v31; // [sp+18h] [-98h]
  int v32; // [sp+1Ch] [-94h]
  int v33; // [sp+20h] [-90h]
  int v34; // [sp+24h] [-8Ch]
  int v35; // [sp+28h] [-88h]
  int v36; // [sp+2Ch] [-84h]
  int v37; // [sp+30h] [-80h]
  int v38; // [sp+34h] [-7Ch]
  int v39; // [sp+38h] [-78h]
  int v40; // [sp+3Ch] [-74h]
  int v41; // [sp+40h] [-70h]
  int v42; // [sp+44h] [-6Ch]
  int v43; // [sp+48h] [-68h]
  int v44; // [sp+4Ch] [-64h]
  int v45; // [sp+50h] [-60h]
  int v46; // [sp+58h] [-58h]
  int v47; // [sp+60h] [-50h]
  _BYTE v48[64]; // [sp+70h] [-40h] BYREF

  if ( anim == nullptr )
    return 0;
  animData = anim->animData;
  if ( animData == nullptr )
    return 0;
  frameRate = animData->frameRate;
  data = this->data;
  v12 = 0;
  __twllei(frameRate, 0);
  numJoints = data->numJoints;
  __twlgei(frameRate & ~(__ROL4__(timeManager.gameTimePerFrame.value * timeManager.gameHz * frame, 1) - 1), 0xFFFFFFFF);
  if ( numJoints != 0 )
  {
    v14 = &joints[-1].mat[11];
    do
    {
      ++v12;
      v14[1] = mat3_identity.mat[0].x;
      v14[2] = mat3_identity.mat[1].x;
      v14[3] = mat3_identity.mat[2].x;
      v14[5] = mat3_identity.mat[0].y;
      v14[6] = mat3_identity.mat[1].y;
      v14[7] = mat3_identity.mat[2].y;
      v14[9] = mat3_identity.mat[0].z;
      v14[10] = mat3_identity.mat[1].z;
      v14[11] = mat3_identity.mat[2].z;
      v14[4] = offset->x;
      v14[8] = offset->y;
      v14 += 12;
      *v14 = offset->z;
    }
    while ( v12 < data->numJoints );
  }
  v15 = ((int (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v16) = back_chain[0];
  v17 = (const idMD6SkelData *)((int (__fastcall *)(int))RtlCheckStack12)(a1: v15);
  v19 = *(const idMD6AnimData **)(v18 + 40);
  *(_DWORD *)((char *)back_chain + v21) = back_chain[0];
  idMD6Blend::DecodeSingleFrame(
    skeleton: v17,
    temp: (float *)((v20 + 15) & 0xFFFFFFF0),
    tempSize: 0x4000u,
    animData: v19,
    ticksPerSec: v23,
    clearOriginTransform: false,
    originOffset: v22,
    offsetAdd: v27,
    outPose: v28,
    outUserChannels: v29,
    a11: v30,
    a12: v31,
    a13: v32,
    a14: v33,
    a15: v34,
    a16: v35,
    a17: v36,
    a18: v37,
    a19: v38,
    a20: v39,
    a21: v40,
    a22: v41,
    a23: v42,
    a24: v43,
    a25: v44,
    a26: v45,
    a27: (_cntlzw(removeOriginOffset) & 0x20) != 0,
    a28: v46,
    a29: (int)v48,
    a30: v47,
    a31: nullptr);
  v24 = this->data->numJoints;
  memcpy(Dst: joints, Src: v48, Size: 16 * (v24 + __ROL4__(v24, 1)));
  return 1;
}


// ========================================================================
// ?GetJointsForAnimTime@idMD6Skel@@QBA_NPAVidJointMat@@PBVidMD6Anim@@HABVidVec3@@_N@Z
// EA  : 0x82854A60
// RVA : 0x00854A60
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::GetJointsForAnimTime(
        idMD6Skel *this,
        idJointMat *joints,
        const idMD6Anim *anim,
        const int timeMS,
        const idVec3 *offset,
        const bool removeOriginOffset)
{
  idMD6SkelData *data; // r3
  int v10; // r7
  float *v11; // r11
  int v12; // r3
  int v13; // r12
  __int64 v14; // r4
  unsigned __int8 v15; // r8
  int v16; // r5
  const idMD6AnimData *v17; // r6
  int v18; // r12
  int v19; // r9
  __int64 v20; // r8
  const float *v21; // r10
  int numJoints; // r11
  _DWORD back_chain[2]; // [sp+0h] [-A0h]
  bool v25; // [sp+Bh] [-95h]
  float *v26; // [sp+Ch] [-94h]
  float *v27; // [sp+10h] [-90h]
  int v28; // [sp+14h] [-8Ch]
  int v29; // [sp+18h] [-88h]
  int v30; // [sp+1Ch] [-84h]
  int v31; // [sp+20h] [-80h]
  int v32; // [sp+24h] [-7Ch]
  int v33; // [sp+28h] [-78h]
  int v34; // [sp+2Ch] [-74h]
  int v35; // [sp+30h] [-70h]
  int v36; // [sp+34h] [-6Ch]
  int v37; // [sp+38h] [-68h]
  int v38; // [sp+3Ch] [-64h]
  int v39; // [sp+40h] [-60h]
  int v40; // [sp+44h] [-5Ch]
  int v41; // [sp+48h] [-58h]
  int v42; // [sp+4Ch] [-54h]
  int v43; // [sp+50h] [-50h]
  unsigned __int8 v44; // [sp+57h] [-49h]
  int v45; // [sp+58h] [-48h]
  int v46; // [sp+60h] [-40h]
  _BYTE v47[48]; // [sp+70h] [-30h] BYREF

  if ( anim == nullptr || anim->animData == nullptr )
    return 0;
  data = this->data;
  v10 = 0;
  if ( data->numJoints != 0 )
  {
    v11 = &joints[-1].mat[11];
    do
    {
      ++v10;
      v11[1] = mat3_identity.mat[0].x;
      v11[2] = mat3_identity.mat[1].x;
      v11[3] = mat3_identity.mat[2].x;
      v11[5] = mat3_identity.mat[0].y;
      v11[6] = mat3_identity.mat[1].y;
      v11[7] = mat3_identity.mat[2].y;
      v11[9] = mat3_identity.mat[0].z;
      v11[10] = mat3_identity.mat[1].z;
      v11[11] = mat3_identity.mat[2].z;
      v11[4] = offset->x;
      v11[8] = offset->y;
      v11 += 12;
      *v11 = offset->z;
    }
    while ( v10 < data->numJoints );
  }
  v12 = ((int (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v13) = back_chain[0];
  v14 = ((__int64 (__fastcall *)(int))RtlCheckStack12)(a1: v12);
  v17 = *(const idMD6AnimData **)(v16 + 40);
  *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
  HIDWORD(v20) = v14;
  v44 = (_cntlzw(v15) & 0x20) != 0;
  LODWORD(v20) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  idMD6Blend::DecodeSingleFrame(
    skeleton: (const idMD6SkelData *)HIDWORD(v14),
    temp: (float *)((v19 + 15) & 0xFFFFFFF0),
    tempSize: 0x4000u,
    animData: v17,
    ticksPerSec: v20,
    clearOriginTransform: false,
    originOffset: v21,
    offsetAdd: v25,
    outPose: v26,
    outUserChannels: v27,
    a11: v28,
    a12: v29,
    a13: v30,
    a14: v31,
    a15: v32,
    a16: v33,
    a17: v34,
    a18: v35,
    a19: v36,
    a20: v37,
    a21: v38,
    a22: v39,
    a23: v40,
    a24: v41,
    a25: v42,
    a26: v43,
    a27: v44,
    a28: v45,
    a29: (int)v47,
    a30: v46,
    a31: nullptr);
  numJoints = this->data->numJoints;
  memcpy(Dst: joints, Src: v47, Size: 16 * (numJoints + __ROL4__(numJoints, 1)));
  return 1;
}


// ========================================================================
// ??0idMD6SkeletonConfig@@QAA@XZ
// EA  : 0x82854C10
// RVA : 0x00854C10
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

idMD6SkeletonConfig *__fastcall idMD6SkeletonConfig::idMD6SkeletonConfig(idMD6SkeletonConfig *this)
{
  idResource::idResource(this);
  this->__vftable = (idMD6SkeletonConfig_vtbl *)&idMD6SkeletonConfig::`vftable';
  this->instances.list = nullptr;
  this->instances.granularity = 0;
  this->instances.memTag = 5;
  this->instances.listStatic = 0;
  this->instances.size = 0;
  this->instances.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->instances);
  this->boundsDecl = nullptr;
  return this;
}


// ========================================================================
// __unwind$227968_0
// EA  : 0x82854C70
// RVA : 0x00854C70
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_227968_0()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?ReadSkeletonConfig_Binary@idMD6SkeletonConfig@@AAA_NPBD@Z
// EA  : 0x82854E40
// RVA : 0x00854E40
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6SkeletonConfig::ReadSkeletonConfig_Binary(idMD6SkeletonConfig *this, const char *filename)
{
  idFile *v3; // r3
  idList<idMD6SkeletonConfig::instance_t,5> *p_instances; // r29
  int v6; // r27
  int v7; // r30
  idFileLocal v8; // [sp+50h] [-70h] BYREF
  int v9; // [sp+54h] [-6Ch] BYREF
  int v10; // [sp+58h] [-68h] BYREF
  idStr v11[3]; // [sp+60h] [-60h] BYREF

  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0);
  v8.file = v3;
  if ( v3 != nullptr && (v3->Read(this: v3, a2: &v10, a3: 4u), v10 == 37112397) )
  {
    v8.file->Read(this: v8.file, a2: &v9, a3: 4u);
    p_instances = &this->instances;
    idList<idSWFSpriteInstance::swfAction_t,72>::SetNum(
      this: (idList<idSWFSpriteInstance::swfAction_t,72> *)&this->instances,
      newNum: v9);
    v11[0].len = 0;
    v11[0].baseBuffer[0] = 0;
    v11[0].allocedAndFlag = 20;
    v11[0].data = v11[0].baseBuffer;
    v6 = 0;
    if ( v9 > 0 )
    {
      v7 = 0;
      do
      {
        v8.file->Read(this: v8.file, a2: &p_instances->list[v7].timestamp, a3: 4u);
        idFile::ReadString(this: v8.file, string: v11);
        if ( v11[0].len != 0 )
          p_instances->list[v7].skeleton = (const idMD6Skel *)idResourceList::Load(
                                                                this: &idMD6Skel::resourceList,
                                                                name: v11[0].data,
                                                                makeDefault: true,
                                                                skipStaleCheck: false);
        else
          p_instances->list[v7].skeleton = nullptr;
        ++v6;
        ++v7;
      }
      while ( v6 < v9 );
    }
    idFile::ReadString(this: v8.file, string: v11);
    if ( v11[0].len != 0 )
      this->boundsDecl = (const idDeclMD6 *)idResourceList::Load(
                                              this: &idDeclMD6::resourceList,
                                              name: v11[0].data,
                                              makeDefault: true,
                                              skipStaleCheck: false);
    else
      this->boundsDecl = nullptr;
    idStr::FreeData(this: v11);
    idFileLocal::~idFileLocal(this: &v8);
    return 1;
  }
  else
  {
    idFileLocal::~idFileLocal(this: &v8);
    return 0;
  }
}


// ========================================================================
// __unwind$228202
// EA  : 0x82855000
// RVA : 0x00855000
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228202()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$228203
// EA  : 0x82855028
// RVA : 0x00855028
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228203()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?ReloadIfStale@idMD6SkeletonConfig@@UAA_NXZ
// EA  : 0x82855050
// RVA : 0x00855050
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6SkeletonConfig::ReloadIfStale(idMD6SkeletonConfig *this)
{
  idFileList *v2; // r3
  idFileList *v3; // r25
  char v4; // r22
  int v5; // r23
  int v6; // r24
  int v7; // r27
  const char *data; // r28
  int v9; // r30
  idMD6SkeletonConfig::instance_t *v10; // r29
  idMD6SkeletonConfig::instance_t *list; // r4
  _BYTE v13[368]; // [sp+50h] [-170h] BYREF

  v2 = fileSystem->ListFilesTree(this: fileSystem, a2: this->name.str, a3: "md6skl", a4: 1);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = 0;
    v5 = 0;
    if ( v2->list.num > 0 )
    {
      v6 = 0;
      do
      {
        if ( v4 != 0 )
          break;
        v7 = 0;
        data = v3->list.list[v6].data;
        if ( this->instances.num > 0 )
        {
          v9 = 0;
          while ( 1 )
          {
            if ( idStr::Icmp(s1: this->instances.list[v9].skeleton->name.str, s2: data) == 0 )
            {
              v10 = &this->instances.list[v9];
              if ( fileSystem->GetTimestamp(this: fileSystem, a2: data, a3: false) != v10->timestamp )
                break;
            }
            ++v7;
            ++v9;
            if ( v7 >= this->instances.num )
              goto LABEL_12;
          }
          v4 = 1;
        }
LABEL_12:
        ++v5;
        ++v6;
      }
      while ( v5 < v3->list.num );
    }
    idFileList::~idFileList(this: v3);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
    if ( v4 == 0 )
      return 0;
  }
  else if ( this->instances.num == 0 )
  {
    return 0;
  }
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6skeletonconfig",
    a4: this->name.str,
    a5: v13,
    a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v13, a3: FSPATH_BASE);
  if ( this->instances.listStatic == 0 || this->instances.listStatic == 2 )
  {
    list = this->instances.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->instances.list = nullptr;
    this->instances.size = 0;
  }
  this->instances.num = 0;
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?MakeSkeletonData@idMD6Skel@@QAA_NHPBMPAV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@PAFHPAMPAV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@QAPAE5@Z
// EA  : 0x82855258
// RVA : 0x00855258
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::MakeSkeletonData(
        idMD6Skel *this,
        signed int numJoints,
        const float *basePose,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *jointHandleTbl,
        __int16 *parentTbl,
        signed int numUserChannels,
        float *U,
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *userChannelHandleTbl,
        unsigned __int8 **jointWeights,
        unsigned __int8 **userWeights,
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
        const void **a28,
        int a29,
        const void **a30)
{
  int v30; // r20
  void *v37; // r28
  __int64 v38; // r26
  signed int v39; // r21
  signed int v40; // r28
  const float *v41; // r14
  int size; // r11
  int v43; // r11
  int v44; // r29
  bool v45; // cr56
  int v46; // r11
  bool v47; // cr56
  int v48; // r11
  bool v49; // cr56
  int num; // r17
  int v51; // r11
  bool v52; // cr56
  int v53; // r11
  bool v54; // cr56
  int v55; // r11
  bool v56; // cr56
  idVehicleState **list; // r18
  idVehicleState **v58; // r15
  idVehicleState **v59; // r28
  unsigned __int16 *v60; // r16
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v61; // r25
  float *v62; // r6
  float *v63; // r7
  signed int v64; // ctr
  float *v65; // r8
  int v66; // r3
  unsigned __int16 *v67; // r9
  float *v68; // r5
  float *v69; // r10
  float *v70; // r11
  int v71; // r23
  int v72; // r4
  int v73; // r29
  int v74; // r28
  int v75; // r27
  int v76; // r25
  int v77; // r24
  int v78; // r24
  int v79; // ctr
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v80; // r9
  float *v81; // r8
  float *v82; // r11
  float *v83; // r10
  idVehicleState **v84; // r18
  signed int v85; // r9
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v86; // r20
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v87; // r7
  float *v88; // r8
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v89; // r10
  float *v90; // r11
  int v91; // r5
  unsigned __int16 value; // r28
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v93; // r10
  float *v94; // r11
  int v95; // ctr
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v96; // r10
  float *v97; // r11
  int v98; // ctr
  idList<unsigned char,37> *v100; // r29
  int i; // r27
  signed int v102; // r11
  idList<unsigned char,37> *v104; // r29
  int j; // r27
  int v106; // r11
  size_t v107; // r29
  size_t v108; // r28
  size_t v109; // r27
  int v110; // r11
  idMem *v111; // r23
  idMD6SkelData *v112; // r3
  idVehicleState **v113; // r15
  idVehicleState **v114; // r16
  idVehicleState **v115; // r19
  unsigned __int16 *v116; // r22
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v117; // r24
  __int64 v118; // r26
  unsigned int v119; // r28
  _WORD *v120; // r29
  idMD6SkelData *data; // r11
  char *v122; // r3
  unsigned int v123; // r28
  const void **v124; // r29
  idMD6SkelData *v125; // r11
  char *v126; // r3
  unsigned __int16 *v127; // r11
  int k; // ctr
  void *v129; // r3
  idMD6SkelData *v130; // r3
  int v131; // r4
  __int64 v132; // r10
  int v133; // r29
  int v134; // r12
  int inverseBasePoseOffset; // r11
  idMD6SkelData *v136; // r11
  int inverseBasePoseQuatOffset; // r9
  char *v138; // r10
  idJointQuat *v139; // r28
  float *v140; // r30
  signed int m; // r29
  double v142; // fp13
  double v143; // fp12
  double v144; // fp11
  double v145; // fp10
  double v146; // fp9
  double v147; // fp8
  double v148; // fp7
  double v149; // fp6
  double v150; // fp5
  double v151; // fp4
  double v152; // fp3
  idMat4 *v153; // r3
  double y; // fp1
  double z; // fp0
  double w; // fp13
  double x; // fp12
  double v158; // fp11
  double v159; // fp10
  double v160; // fp9
  double v161; // fp8
  double v162; // fp7
  double v163; // fp6
  double v164; // fp5
  double v165; // fp4
  _DWORD back_chain[2]; // [sp+0h] [-3A0h]
  bool v168; // [sp+Bh] [-395h]
  const float *v169; // [sp+Ch] [-394h]
  const float *v170; // [sp+10h] [-390h]
  const float *v171; // [sp+14h] [-38Ch]
  float *v172; // [sp+18h] [-388h]
  float *v173; // [sp+1Ch] [-384h]
  int v174; // [sp+20h] [-380h]
  int v175; // [sp+24h] [-37Ch]
  int v176; // [sp+28h] [-378h]
  int v177; // [sp+2Ch] [-374h]
  int v178; // [sp+30h] [-370h]
  int v179; // [sp+34h] [-36Ch]
  int v180; // [sp+38h] [-368h]
  int v181; // [sp+3Ch] [-364h]
  int v182; // [sp+40h] [-360h]
  int v183; // [sp+44h] [-35Ch]
  int v184; // [sp+48h] [-358h]
  int v185; // [sp+4Ch] [-354h]
  int v186; // [sp+50h] [-350h]
  float *v187; // [sp+58h] [-348h]
  int v188; // [sp+60h] [-340h]
  float *v189; // [sp+68h] [-338h]
  float *v190; // [sp+70h] [-330h]
  float *v191; // [sp+78h] [-328h]
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> v192; // [sp+80h] [-320h] BYREF
  signed int v193; // [sp+84h] [-31Ch]
  void *v194; // [sp+88h] [-318h]
  idList<idVehicleState *,5> v195; // [sp+90h] [-310h] BYREF
  idList<idVehicleState *,5> v196; // [sp+A0h] [-300h] BYREF
  idList<idVehicleState *,5> v197; // [sp+B0h] [-2F0h] BYREF
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> v198; // [sp+C0h] [-2E0h] BYREF
  idList<unsigned short,5> v199; // [sp+D0h] [-2D0h] BYREF
  idList<idVehicleState *,5> v200; // [sp+E0h] [-2C0h] BYREF
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> v201; // [sp+F0h] [-2B0h] BYREF
  const float *v202; // [sp+100h] [-2A0h]
  idMat4 v203; // [sp+110h] [-290h] BYREF
  unsigned int v204; // [sp+150h] [-250h]
  idMem *v205; // [sp+154h] [-24Ch]
  idMat4 v206; // [sp+160h] [-240h] BYREF
  __int64 v207; // [sp+1A0h] [-200h]
  _DWORD v208[32]; // [sp+1B0h] [-1F0h] BYREF
  _WORD v209[64]; // [sp+230h] [-170h] BYREF
  idMat4 v210; // [sp+2B0h] [-F0h] BYREF

  v30 = 2 * numJoints;
  v205 = &mem;
  v37 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Skel.cpp(100) : TAG_MD6_MISC",
          size: 2 * numJoints,
          tag: TAG_MD6_MISC,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v37, Src: parentTbl, Size: v30);
  idAnimator_TrackerBase::GetReferenceJointOverride(this: &v192);
  CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v192, data: v37, length: v30);
  idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
  LODWORD(v38) = 0;
  memset(&v197, 0, 14);
  v197.memTag = 5;
  v39 = (numJoints + 7) & 0xFFFFFFF8;
  v197.listStatic = 0;
  v40 = (numUserChannels + 7) & 0xFFFFFFF8;
  v41 = &basePose[4 * v39];
  v193 = v40;
  v194 = (void *)v41;
  v202 = &basePose[8 * v39];
  idList<idThread *,58>::Clear(this: &v197);
  memset(&v196, 0, 14);
  v196.memTag = 5;
  v196.listStatic = 0;
  idList<idThread *,58>::Clear(this: &v196);
  memset(&v195, 0, 14);
  v195.memTag = 5;
  v195.listStatic = 0;
  idList<idThread *,58>::Clear(this: &v195);
  memset(&v200, 0, 14);
  *(_WORD *)&v200.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v200);
  memset(&v199, 0, 14);
  *(_WORD *)&v199.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v199);
  memset(&v198, 0, 14);
  *(_WORD *)&v198.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v198);
  memset(&v201, 0, 14);
  *(_WORD *)&v201.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v201);
  size = v197.size;
  if ( 4 * v39 > v197.size )
  {
    if ( (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v197, newsize: 4 * v39) == 0 )
      goto LABEL_6;
    size = v197.size;
  }
  v197.num = 4 * v39;
  if ( 4 * v39 >= size )
    v197.num = size;
LABEL_6:
  v43 = v196.size;
  v44 = 3 * v39;
  v45 = 3 * v39 < v196.size;
  if ( 3 * v39 > v196.size )
  {
    if ( (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v196, newsize: 3 * v39) == 0 )
      goto LABEL_11;
    v43 = v196.size;
    v45 = v44 < v196.size;
  }
  v196.num = 3 * v39;
  if ( !v45 )
    v196.num = v43;
LABEL_11:
  v46 = v195.size;
  v47 = v44 < v195.size;
  if ( v44 > v195.size )
  {
    if ( (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&v195, newsize: 3 * v39) == 0 )
      goto LABEL_16;
    v46 = v195.size;
    v47 = v44 < v195.size;
  }
  v195.num = 3 * v39;
  if ( !v47 )
    v195.num = v46;
LABEL_16:
  v48 = v200.size;
  v49 = v40 < v200.size;
  if ( v40 > v200.size )
  {
    if ( (unsigned __int8)idList<float,116>::Resize(
                            this: (idList<float,13> *)&v200,
                            newsize: (numUserChannels + 7) & 0xFFFFFFF8) == 0 )
    {
      num = v200.num;
      goto LABEL_23;
    }
    v48 = v200.size;
    v49 = v40 < v200.size;
  }
  if ( v49 )
  {
    num = (numUserChannels + 7) & 0xFFFFFFF8;
    v200.num = num;
  }
  else
  {
    num = v48;
    v200.num = v48;
  }
LABEL_23:
  v51 = v199.size;
  v52 = v39 < v199.size;
  if ( v39 > v199.size )
  {
    if ( (unsigned __int8)idList<unsigned short,30>::Resize(this: &v199, newsize: (numJoints + 7) & 0xFFFFFFF8) == 0 )
      goto LABEL_28;
    v51 = v199.size;
    v52 = v39 < v199.size;
  }
  v199.num = (numJoints + 7) & 0xFFFFFFF8;
  if ( !v52 )
    v199.num = v51;
LABEL_28:
  v53 = v198.size;
  v54 = v39 < v198.size;
  if ( v39 > v198.size )
  {
    if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                            this: &v198,
                            newsize: (numJoints + 7) & 0xFFFFFFF8) == 0 )
      goto LABEL_33;
    v53 = v198.size;
    v54 = v39 < v198.size;
  }
  v198.num = (numJoints + 7) & 0xFFFFFFF8;
  if ( !v54 )
    v198.num = v53;
LABEL_33:
  v55 = v201.size;
  v56 = v40 < v201.size;
  if ( v40 > v201.size )
  {
    if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                            this: &v201,
                            newsize: (numUserChannels + 7) & 0xFFFFFFF8) == 0 )
      goto LABEL_38;
    v55 = v201.size;
    v56 = v40 < v201.size;
  }
  v201.num = (numUserChannels + 7) & 0xFFFFFFF8;
  if ( !v56 )
    v201.num = v55;
LABEL_38:
  list = v197.list;
  v58 = v196.list;
  v59 = v195.list;
  v60 = v199.list;
  v61 = v198.list;
  if ( numJoints > 0 )
  {
    v62 = (float *)(v195.list - 2);
    v63 = (float *)(basePose + 3);
    v64 = numJoints;
    v65 = (float *)(v202 + 2);
    v66 = (char *)v202 - (char *)v197.list;
    v67 = v199.list;
    v68 = (float *)(v41 - 4);
    v69 = (float *)(v196.list + 2);
    v70 = (float *)(v197.list + 1);
    v71 = (char *)basePose - (char *)v197.list;
    v72 = (char *)v41 - (char *)v197.list;
    v73 = (char *)v41 - (char *)v202;
    v74 = (char *)v195.list - (char *)v196.list;
    v75 = (char *)parentTbl - (char *)v199.list;
    v76 = (char *)v198.list - (char *)v199.list;
    v77 = (char *)jointHandleTbl - (char *)v199.list;
    do
    {
      if ( *v63 >= 0.0 )
      {
        *(v70 - 1) = *(v63 - 3);
        *v70 = *(float *)((char *)v70 + v71);
        v70[1] = *(v63 - 1);
        v70[2] = *v63;
      }
      else
      {
        *(v70 - 1) = -*(v63 - 3);
        *v70 = -*(float *)((char *)v70 + v71);
        v70[1] = -*(v63 - 1);
        v70[2] = -*v63;
      }
      v68 += 4;
      v63 += 4;
      *(v69 - 2) = *v68;
      *(v69 - 1) = *(float *)((char *)v70 + v72);
      *v69 = *(float *)((char *)v65 + v73);
      v62[2] = *(v65 - 2);
      v62 += 3;
      *v62 = *(float *)((char *)v70 + v66);
      v70 += 4;
      *(float *)((char *)v69 + v74) = *v65;
      v65 += 4;
      v69 += 3;
      *v67 = *(unsigned __int16 *)((char *)v67 + v75);
      *(unsigned __int16 *)((char *)v67 + v76) = *(unsigned __int16 *)((char *)v67 + v77);
      ++v67;
      --v64;
    }
    while ( v64 != 0 );
    v61 = v198.list;
    v59 = v195.list;
  }
  v78 = v193;
  if ( numJoints < v39 )
  {
    v79 = v39 - numJoints;
    v80 = &v61[v30 / 2u];
    v81 = (float *)&v59[3 * numJoints - 2];
    v82 = (float *)&v58[3 * numJoints + 2];
    v83 = (float *)&list[4 * numJoints - 1];
    do
    {
      v83[1] = 0.0;
      v83[2] = 0.0;
      v83[3] = 0.0;
      v83 += 4;
      *v83 = 1.0;
      *(v82 - 2) = 1.0;
      *(v82 - 1) = 1.0;
      *v82 = 1.0;
      v81[2] = 0.0;
      v81 += 3;
      *v81 = 0.0;
      *(float *)((char *)v82 + (char *)v59 - (char *)v58) = 0.0;
      *(unsigned __int16 *)((char *)&v80->value + (char *)v60 - (char *)v61) = -1;
      v80->value = -1;
      v82 += 3;
      ++v80;
      --v79;
    }
    while ( v79 != 0 );
  }
  v84 = v200.list;
  v85 = 0;
  v86 = v201.list;
  if ( numUserChannels >= 4 )
  {
    v87 = v201.list - 1;
    v88 = U - 1;
    v89 = userChannelHandleTbl + 1;
    v90 = (float *)(v200.list + 1);
    v91 = (char *)U - (char *)v200.list;
    do
    {
      v85 += 4;
      *(v90 - 1) = v88[1];
      v87[1].value = v89[-1].value;
      *v90 = *(float *)((char *)v90 + v91);
      *(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)((char *)v89
                                                                        + (char *)v86
                                                                        - (char *)userChannelHandleTbl) = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>)v89->value;
      v90[1] = v88[3];
      v87[3].value = v89[1].value;
      v88 += 4;
      v90[2] = *v88;
      v90 += 4;
      value = v89[2].value;
      v89 += 4;
      v87 += 4;
      v87->value = value;
    }
    while ( v85 < numUserChannels - 3 );
  }
  if ( v85 < numUserChannels )
  {
    v93 = &userChannelHandleTbl[v85];
    v94 = (float *)&v84[v85];
    v95 = numUserChannels - v85;
    do
    {
      *v94 = *(float *)((char *)v94 + (char *)U - (char *)v84);
      ++v94;
      *(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)((char *)v93
                                                                        + (char *)v86
                                                                        - (char *)userChannelHandleTbl) = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>)v93->value;
      ++v93;
      --v95;
    }
    while ( v95 != 0 );
  }
  if ( numUserChannels < v78 )
  {
    v96 = &v86[numUserChannels - 1];
    v97 = (float *)&v84[numUserChannels - 1];
    v98 = v78 - numUserChannels;
    do
    {
      *++v97 = 0.0;
      ++v96;
      v96->value = -1;
      --v98;
    }
    while ( v98 != 0 );
  }
  `eh vector constructor iterator'(
    ptr: v209,
    size: 0x10u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector constructor iterator'(
    ptr: v208,
    size: 0x10u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  v100 = (idList<unsigned char,37> *)v209;
  for ( i = 8; i != 0; --i )
  {
    if ( *a28 != nullptr )
    {
      if ( v39 <= v100->size || idList<unsigned char,25>::Resize(this: v100, newsize: (numJoints + 7) & 0xFFFFFFF8) )
      {
        v102 = v100->size;
        if ( v39 < v102 )
          v102 = (numJoints + 7) & 0xFFFFFFF8;
        v100->num = v102;
      }
      memcpy(Dst: v100->list, Src: *a28, Size: numJoints);
      memset(Dst: &v100->list[numJoints], Val: 0, Size: v39 - numJoints);
    }
    ++a28;
    ++v100;
  }
  v104 = (idList<unsigned char,37> *)v208;
  for ( j = 8; j != 0; --j )
  {
    if ( *a30 != nullptr )
    {
      if ( v78 <= v104->size || idList<unsigned char,25>::Resize(this: v104, newsize: v78) )
      {
        v106 = v104->size;
        if ( v78 < v106 )
          v106 = v78;
        v104->num = v106;
      }
      memcpy(Dst: v104->list, Src: *a30, Size: numUserChannels);
      memset(Dst: &v104->list[numUserChannels], Val: 0, Size: v78 - numUserChannels);
    }
    ++a30;
    ++v104;
  }
  v107 = 2 * v199.num;
  LOWORD(v203.mat[0].x) = numJoints;
  v108 = 2 * v198.num;
  HIWORD(v203.mat[0].y) = numUserChannels;
  v109 = 2 * v201.num;
  v110 = (unsigned __int16)(2 * LOWORD(v199.num)
                          + 4 * (num + LOWORD(v195.num) + LOWORD(v196.num) + LOWORD(v197.num) + 16));
  HIDWORD(v38) = v208[1];
  v204 = (((4 * (num + v195.num + v196.num + v197.num + 16)) & 0xFFFC) + 1) & 0xFFFFFFFE;
  v193 = v110 + 1;
  v207 = v38;
  HIWORD(v203.mat[1].y) = 2 * LOWORD(v201.num) + 2 * LOWORD(v198.num) + v110;
  LOWORD(v203.mat[0].y) = v192;
  HIWORD(v203.mat[0].z) = 64;
  LOWORD(v203.mat[1].y) = HIWORD(v203.mat[1].y) + v209[3];
  LOWORD(v203.mat[0].w) = (4 * (num + LOWORD(v195.num) + LOWORD(v196.num) + LOWORD(v197.num) + 16) + 1) & 0xFFFE;
  HIWORD(v203.mat[1].x) = (v110 + 1) & 0xFFFE;
  LOWORD(v203.mat[1].x) = (2 * LOWORD(v198.num) + v110 + 1) & 0xFFFE;
  HIWORD(v203.mat[1].z) = HIWORD(v203.mat[1].y) + v209[3] + v209[11];
  LOWORD(v203.mat[1].z) = HIWORD(v203.mat[1].z) + v209[19];
  HIWORD(v203.mat[1].w) = HIWORD(v203.mat[1].z) + v209[19] + v209[27];
  LOWORD(v203.mat[1].w) = HIWORD(v203.mat[1].w) + v209[35];
  HIWORD(v203.mat[2].x) = HIWORD(v203.mat[1].w) + v209[35] + v209[43];
  LOWORD(v203.mat[2].x) = HIWORD(v203.mat[2].x) + v209[51];
  HIWORD(v203.mat[2].y) = HIWORD(v203.mat[2].x) + v209[51] + v209[59];
  LOWORD(v203.mat[2].y) = HIWORD(v203.mat[2].y) + LOWORD(v208[1]);
  HIWORD(v203.mat[2].z) = HIWORD(v203.mat[2].y) + LOWORD(v208[1]) + LOWORD(v208[5]);
  LOWORD(v203.mat[2].z) = HIWORD(v203.mat[2].z) + LOWORD(v208[9]);
  v111 = v205;
  HIWORD(v203.mat[2].w) = HIWORD(v203.mat[2].z) + LOWORD(v208[9]) + LOWORD(v208[13]);
  LOWORD(v203.mat[2].w) = HIWORD(v203.mat[2].w) + LOWORD(v208[17]);
  HIWORD(v203.mat[3].x) = HIWORD(v203.mat[2].w) + LOWORD(v208[17]) + LOWORD(v208[21]);
  LOWORD(v203.mat[3].x) = HIWORD(v203.mat[3].x) + LOWORD(v208[25]);
  LOWORD(v110) = 48 * v39 + HIWORD(v203.mat[3].x) + LOWORD(v208[25]) + LOWORD(v208[29]);
  LOWORD(v203.mat[0].z) = (HIWORD(v203.mat[3].x) + LOWORD(v208[25]) + LOWORD(v208[29]) + 15) & 0xFFF0;
  HIWORD(v203.mat[0].w) = (v110 + 15) & 0xFFF0;
  HIWORD(v203.mat[0].x) = (v110 + 32 * v39 + 15) & 0xFFF0;
  v112 = (idMD6SkelData *)idMem::AllocWithLocation(
                            this: v205,
                            location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6Skel.cpp(225) : TAG_MD6",
                            size: HIWORD(v203.mat[0].x),
                            tag: TAG_MD6,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->data = v112;
  *(idMat4 *)v112 = v203;
  v113 = v197.list;
  memcpy(Dst: (char *)this->data + this->data->basePoseOffset, Src: v197.list, Size: 4 * v197.num);
  v114 = v196.list;
  memcpy(
    Dst: (char *)this->data + ((16 * (this->data->numJoints + 7)) & 0xFFF80) + this->data->basePoseOffset,
    Src: v196.list,
    Size: 4 * v196.num);
  v115 = v195.list;
  memcpy(
    Dst: (char *)this->data + 28 * ((this->data->numJoints + 7) & 0xFFF8) + this->data->basePoseOffset,
    Src: v195.list,
    Size: 4 * v195.num);
  memcpy(
    Dst: (char *)this->data + 40 * ((this->data->numJoints + 7) & 0xFFF8) + this->data->basePoseOffset,
    Src: v84,
    Size: 4 * num);
  v116 = v199.list;
  memcpy(Dst: (char *)this->data + this->data->parentTblOffset, Src: v199.list, Size: v107);
  v117 = v198.list;
  memcpy(Dst: (char *)this->data + this->data->jointHandleTblOffset, Src: v198.list, Size: v108);
  memcpy(Dst: (char *)this->data + this->data->userChannelHandleTblOffset, Src: v86, Size: v109);
  v118 = v207;
  v119 = 20;
  v120 = v209;
  do
  {
    data = this->data;
    v122 = (char *)data + *(unsigned __int16 *)((char *)&data->size + v119);
    if ( *(unsigned __int16 *)((char *)&data->size + v119) == 0 )
      v122 = (char *)v118;
    memcpy(Dst: v122, Src: *(const void **)v120, Size: *((_DWORD *)v120 + 1));
    v119 += 2;
    v120 += 8;
  }
  while ( v119 < 0x24 );
  v123 = 36;
  v124 = (const void **)v208;
  do
  {
    v125 = this->data;
    v126 = (char *)v125 + *(unsigned __int16 *)((char *)&v125->size + v123);
    if ( *(unsigned __int16 *)((char *)&v125->size + v123) == 0 )
      v126 = (char *)v118;
    memcpy(Dst: v126, Src: *v124, Size: (size_t)v124[1]);
    v123 += 2;
    v124 += 4;
  }
  while ( v123 < 0x34 );
  v127 = &this->data->userWeightOffsets[7];
  for ( k = 6; k != 0; --k )
    *++v127 = v118;
  memset(Dst: (char *)this->data + this->data->inverseBasePoseOffset, Val: 0, Size: HIDWORD(v118));
  v129 = memset(Dst: (char *)this->data + this->data->inverseBasePoseQuatOffset, Val: 0, Size: 32 * v39);
  if ( v39 > 0 )
  {
    ((void (__fastcall *)(void *))RtlCheckStack12)(a1: v129);
    v130 = this->data;
    v131 = (int)v202;
    LODWORD(v132) = 1;
    v133 = (int)v194;
    HIDWORD(v132) = &vec3_origin;
    *(_DWORD *)((char *)back_chain + v134) = back_chain[0];
    inverseBasePoseOffset = v130->inverseBasePoseOffset;
    v194 = v130;
    idMD6Blend::TransformLocalJointsToModelMatrices(
      skeleton: v130,
      temp: (char *)&v192,
      tempSize: 0x4000u,
      mods: nullptr,
      numMods: 0,
      originOffset: v132,
      addOffset: v168,
      inR: v169,
      inS: v170,
      inT: v171,
      outMatrices: v172,
      quatTemp: v173,
      a13: v174,
      a14: v175,
      a15: v176,
      a16: v177,
      a17: v178,
      a18: v179,
      a19: v180,
      a20: v181,
      a21: v182,
      a22: v183,
      a23: v184,
      a24: v185,
      a25: v186,
      a26: (int)basePose,
      a27: v187,
      a28: v133,
      a29: v188,
      a30: v131,
      a31: v189,
      a32: (int)v130 + inverseBasePoseOffset,
      a33: v190,
      a34: v118,
      inRa: v191);
    v136 = this->data;
    inverseBasePoseQuatOffset = v136->inverseBasePoseQuatOffset;
    v138 = (char *)v136 + v136->inverseBasePoseOffset;
    v194 = v136;
    v139 = (idJointQuat *)((char *)v136 + inverseBasePoseQuatOffset);
    v140 = (float *)(v138 - 48);
    for ( m = v39; m != 0; --m )
    {
      v142 = v140[22];
      v143 = v140[21];
      v144 = v140[20];
      v145 = v140[19];
      v146 = v140[18];
      v147 = v140[17];
      v148 = v140[16];
      v149 = v140[15];
      v150 = v140[14];
      v151 = v140[13];
      v152 = v140[12];
      v203.mat[2].w = v140[23];
      v203.mat[2].z = v142;
      v203.mat[2].y = v143;
      v203.mat[2].x = v144;
      v203.mat[1].w = v145;
      v203.mat[1].z = v146;
      v203.mat[1].y = v147;
      v203.mat[1].x = v148;
      v203.mat[0].w = v149;
      v203.mat[0].z = v150;
      v203.mat[0].x = v152;
      v203.mat[0].y = v151;
      v203.mat[3].x = 0.0;
      v203.mat[3].y = 0.0;
      v203.mat[3].z = 0.0;
      v203.mat[3].w = 1.0;
      v153 = idMat4::Inverse(this: &v210, result: &v203);
      v206.mat[3].x = 0.0;
      v206.mat[3].y = 0.0;
      v206.mat[3].z = 0.0;
      v206.mat[3].w = 1.0;
      v140[12] = v153->mat[0].x;
      y = v153->mat[0].y;
      v140[13] = v153->mat[0].y;
      z = v153->mat[0].z;
      v140[14] = v153->mat[0].z;
      w = v153->mat[0].w;
      v140[15] = v153->mat[0].w;
      x = v153->mat[1].x;
      v140[16] = v153->mat[1].x;
      v158 = v153->mat[1].y;
      v140[17] = v153->mat[1].y;
      v159 = v153->mat[1].z;
      v140[18] = v153->mat[1].z;
      v160 = v153->mat[1].w;
      v140[19] = v153->mat[1].w;
      v161 = v153->mat[2].x;
      v140[20] = v153->mat[2].x;
      v162 = v153->mat[2].y;
      v140[21] = v153->mat[2].y;
      v163 = v153->mat[2].z;
      v140[22] = v153->mat[2].z;
      v164 = v153->mat[2].w;
      v140[23] = v153->mat[2].w;
      v140 += 12;
      v165 = *v140;
      v206.mat[0].y = y;
      v206.mat[0].z = z;
      v206.mat[0].w = w;
      v206.mat[1].x = x;
      v206.mat[1].y = v158;
      v206.mat[1].z = v159;
      v206.mat[1].w = v160;
      v206.mat[2].x = v161;
      v206.mat[2].y = v162;
      v206.mat[2].z = v163;
      v206.mat[2].w = v164;
      v206.mat[0].x = v165;
      idJointQuat::FromMat4(this: v139++, mat: &v206);
    }
  }
  `eh vector destructor iterator'(
    ptr: v208,
    size: 0x10u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector destructor iterator'(
    ptr: v209,
    size: 0x10u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( (v201.listStatic == 0 || v201.listStatic == 2) && v86 != nullptr )
    idMem::Free(this: v111, ptr: v86, align: ALIGN_16);
  if ( (v198.listStatic == 0 || v198.listStatic == 2) && v117 != nullptr )
    idMem::Free(this: v111, ptr: v117, align: ALIGN_16);
  if ( (v199.listStatic == 0 || v199.listStatic == 2) && v116 != nullptr )
    idMem::Free(this: v111, ptr: v116, align: ALIGN_16);
  if ( (v200.listStatic == 0 || v200.listStatic == 2) && v84 != nullptr )
    idMem::Free(this: v111, ptr: v84, align: ALIGN_16);
  if ( (v195.listStatic == 0 || v195.listStatic == 2) && v115 != nullptr )
    idMem::Free(this: v111, ptr: v115, align: ALIGN_16);
  if ( (v196.listStatic == 0 || v196.listStatic == 2) && v114 != nullptr )
    idMem::Free(this: v111, ptr: v114, align: ALIGN_16);
  if ( (v197.listStatic == 0 || v197.listStatic == 2) && v113 != nullptr )
    idMem::Free(this: v111, ptr: v113, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$228547
// EA  : 0x82856104
// RVA : 0x00856104
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228547()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 176));
}


// ========================================================================
// __unwind$228548
// EA  : 0x8285612C
// RVA : 0x0085612C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228548()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 160));
}


// ========================================================================
// __unwind$228549
// EA  : 0x82856154
// RVA : 0x00856154
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228549()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 144));
}


// ========================================================================
// __unwind$228550
// EA  : 0x8285617C
// RVA : 0x0085617C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228550()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 224));
}


// ========================================================================
// __unwind$228551
// EA  : 0x828561A4
// RVA : 0x008561A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228551()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 208));
}


// ========================================================================
// __unwind$228552
// EA  : 0x828561CC
// RVA : 0x008561CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228552()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 192));
}


// ========================================================================
// __unwind$228553
// EA  : 0x828561F4
// RVA : 0x008561F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228553()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 928 + 240));
}


// ========================================================================
// __unwind$228554
// EA  : 0x8285621C
// RVA : 0x0085621C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228554()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 928 + 560),
    size: 0x10u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$228555
// EA  : 0x82856254
// RVA : 0x00856254
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_228555()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 928 + 432),
    size: 0x10u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// AddChildren_r
// EA  : 0x82856290
// RVA : 0x00856290
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall AddChildren_r(
        const idMD6Skel *skeleton,
        const idIndex<short,enum invalidJointIndex_t> *parent,
        idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *jointList)
{
  idMD6SkelData *data; // r11
  int v6; // r29
  int numJoints; // r26
  idMD6SkelData *v8; // r11
  int v9; // r25
  __int16 *v10; // r28
  int num; // r7
  int v12; // r10
  int v13; // r11
  idIndex<short,enum invalidUserChannelIndex_t> v14; // [sp+50h] [-50h] BYREF

  data = skeleton->data;
  v6 = 0;
  numJoints = data->numJoints;
  v8 = (idMD6SkelData *)((char *)data + data->parentTblOffset);
  if ( numJoints != 0 )
  {
    v9 = (__int16)parent;
    v10 = (__int16 *)v8;
    do
    {
      if ( v9 == *v10 )
      {
        num = jointList->num;
        v12 = 0;
        v14.value = v6;
        if ( num <= 0 )
          goto LABEL_10;
        v13 = 0;
        while ( jointList->list[v13].value != (__int16)v6 )
        {
          ++v12;
          ++v13;
          if ( v12 >= num )
            goto LABEL_10;
        }
        if ( v12 < 0 )
LABEL_10:
          idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(this: jointList, obj: &v14);
        AddChildren_r(
          skeleton,
          parent: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v6,
          (idList<idIndex<short,enum invalidJointIndex_t>,5> *)jointList);
      }
      ++v6;
      ++v10;
    }
    while ( v6 < numJoints );
  }
}


// ========================================================================
// ?GetJointList@idMD6Skel@@QBAXPBVidMD6Model@@PBDAAV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@@Z
// EA  : 0x82856368
// RVA : 0x00856368
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall idMD6Skel::GetJointList(
        idMD6Skel *this,
        const idMD6Model *model,
        const char *jointNames,
        idList<idVehicleState *,5> *jointList)
{
  unsigned int i; // r5
  int v9; // r29
  const idIndex<short,enum invalidJointIndex_t> *v10; // r30
  idMD6Skel v11; // [sp+50h] [-240h] BYREF
  int v12; // [sp+84h] [-20Ch]
  int v13; // [sp+94h] [-1FCh]
  float v14; // [sp+98h] [-1F8h]
  int v15; // [sp+9Ch] [-1F4h]
  int v16; // [sp+A0h] [-1F0h]
  int v17; // [sp+A4h] [-1ECh]
  char v18; // [sp+A8h] [-1E8h] BYREF
  idLexer v19; // [sp+1B0h] [-E0h] BYREF

  idList<idThread *,58>::Clear(this: jointList);
  idLexer::idLexer(this: &v19, flags_: 262148);
  for ( i = 0; jointNames[i] != 0; ++i )
    ;
  idLexer::LoadMemory(this: &v19, ptr: jointNames, length_: i, name: "GetJointList");
  v9 = 0;
  HIBYTE(v11.staleCount) = 0;
  v13 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v14 = -3.4028235e38;
  v18 = 0;
  v11.resourceError = &v18;
  v11.resourceListPtr = nullptr;
  v11.networkID = -2147483392;
  while ( idLexer::ReadToken(this: &v19, token: (idToken *)&v11.resourceListPtr) )
  {
    if ( *(_DWORD *)&v11.jointConversion.value == 5 )
    {
      if ( v12 == 27 )
      {
        v9 |= 1u;
      }
      else if ( v12 == 31 )
      {
        v9 |= 2u;
      }
    }
    else if ( *(_DWORD *)&v11.jointConversion.value == 4 )
    {
      idStr::ToLower(this: (idStr *)&v11.resourceListPtr);
      idMD6Skel::GetJointIndex(
        this: &v11,
        result: (idIndex<short,enum invalidJointIndex_t> *)this,
        name: v11.resourceError);
      v10 = (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v11.__vftable);
      if ( SHIWORD(v11.__vftable) >= 0 )
      {
        if ( (v9 & 2) != 0 )
        {
          idList<idIndex<short,enum invalidJointIndex_t>,5>::Remove(
            this: (idList<idIndex<short,enum invalidJointIndex_t>,5> *)jointList,
            obj: (const idIndex<short,enum invalidJointIndex_t> *)&v11);
          if ( (v9 & 1) == 0 )
            goto LABEL_14;
          SubChildren_r(skeleton: this, parent: v10, (idList<idIndex<short,enum invalidJointIndex_t>,5> *)jointList);
          v9 = 0;
        }
        else
        {
          idList<idIndex<short,enum invalidJointIndex_t>,5>::AddUnique(
            this: (idList<idIndex<short,enum invalidJointIndex_t>,5> *)jointList,
            obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v11);
          if ( (v9 & 1) != 0 )
            AddChildren_r(
              skeleton: this,
              parent: v10,
              (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)jointList);
LABEL_14:
          v9 = 0;
        }
      }
      else
      {
        idLib::Warning(fmt: "Unknown joint '%s' in '%s' for model '%s'", v11.resourceError, jointNames, model->name.str);
        v9 = 0;
      }
    }
  }
  idStr::FreeData(this: (idStr *)&v11.resourceListPtr);
  idLexer::~idLexer(this: &v19);
}


// ========================================================================
// $M230605
// EA  : 0x8285655C
// RVA : 0x0085655C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void *_M230605()
{
  int v0; // r12

  idLib::Warning(
    fmt: "idDeclMD5::GetJointList for '%s' - %s",
    *(const char **)(*(_DWORD *)(v0 - 656 + 684) + 8),
    idException::error);
  return &_M230595;
}


// ========================================================================
// __unwind$230442
// EA  : 0x828565A0
// RVA : 0x008565A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230442()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 656 + 432));
}


// ========================================================================
// __unwind$230443
// EA  : 0x828565C8
// RVA : 0x008565C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230443()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 96));
}


// ========================================================================
// ?Parse@idMD6Skel@@AAA_NAAVidParser@@@Z
// EA  : 0x828565F8
// RVA : 0x008565F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMD6Skel::Parse(idMD6Skel *this, idParser *parser)
{
  int v3; // r5
  int v5; // r20
  int v6; // r21
  unsigned int v7; // r3
  unsigned int v8; // r3
  idStr *v9; // r3
  idFile *v10; // r3
  unsigned int v11; // r30
  const idDeclVehicleUpgrade **v12; // r28
  int v13; // r3
  signed int v14; // r29
  signed int v15; // r30
  int v16; // r12
  int v17; // r3
  int v18; // r12
  int v19; // r12
  int v20; // r12
  int v21; // r12
  unsigned int *p_num; // r10
  char *buffer; // r6
  char *v24; // r7
  int i; // ctr
  _DWORD *v26; // r11
  int j; // ctr
  unsigned int k; // r9
  char *v29; // r10
  int v30; // r11
  char *v31; // r8
  unsigned int v32; // ctr
  int v33; // r11
  unsigned int v34; // ctr
  char *v35; // r23
  char *v36; // r30
  float *v37; // r27
  int v38; // r26
  float *v39; // r29
  int v40; // r21
  _WORD *v41; // r28
  int v42; // r15
  int v43; // r19
  char *v44; // r20
  int v45; // r18
  int v46; // r17
  int v47; // r25
  int v48; // r16
  int v49; // r22
  int v50; // r14
  int v51; // r24
  __int16 v52; // r3
  int v53; // r5
  int v54; // r3
  unsigned int v55; // r8
  char v56; // r11
  BOOL v57; // r8
  char v58; // r11
  char v59; // r11
  char v60; // r11
  char v61; // r11
  char v62; // r11
  char v63; // r11
  idParser *v64; // r16
  idParser *v65; // r22
  signed int v66; // r15
  int v67; // r27
  int v68; // r29
  char *v69; // r30
  int v70; // r21
  int v71; // r20
  float *v72; // r26
  int v73; // r19
  int v74; // r18
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v75; // r28
  int v76; // r16
  int v77; // r24
  int v78; // r25
  int v79; // r15
  int v80; // r14
  char v81; // r11
  int v82; // r8
  char v83; // r11
  int v84; // r10
  char v85; // r11
  char v86; // r11
  char v87; // r11
  char v88; // r11
  char v89; // r11
  char v90; // r11
  idMem *v91; // r14
  const float *v92; // r20
  __int16 *v93; // r18
  char *v94; // r11
  int v95; // ctr
  float *v96; // r7
  int v97; // r5
  int v98; // r4
  int v99; // r3
  int v100; // r27
  int v101; // r26
  int v102; // r25
  int v103; // r24
  int v104; // r30
  int v105; // r29
  int v106; // r28
  _WORD *v107; // r8
  float *v108; // r9
  float *v109; // r10
  int v110; // r23
  float *v111; // r10
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v112; // r11
  int v113; // ctr
  int v114; // r11
  int m; // ctr
  int v116; // r11
  int n; // ctr
  int len; // r30
  int v119; // r4
  int v120; // r11
  unsigned __int16 v121; // r5
  int v122; // r4
  unsigned __int16 *v123; // r22
  int v124; // r11
  int v125; // r30
  int v126; // r26
  char v127; // r3
  unsigned __int16 *v128; // r3
  int value; // r4
  __int16 v130; // r23
  int v131; // r28
  unsigned __int16 *v132; // r27
  __int16 v133; // r3
  int v134; // r29
  __int16 v135; // r30
  __int16 v136; // r30
  signed int v137; // r18
  unsigned __int16 *v138; // r27
  int v139; // r28
  signed int ii; // r26
  __int16 v141; // r3
  int v142; // r29
  signed int v143; // r19
  signed int v144; // r27
  signed int v145; // r24
  idStr *v146; // r29
  int v147; // r30
  idStr *v148; // r28
  idStr *v149; // r29
  int v150; // r30
  idStr *v151; // r28
  idStr *v152; // r29
  int v153; // r30
  idStr *v154; // r28
  idStr *v155; // r29
  int v156; // r30
  idStr *v157; // r28
  int v158; // r11
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v159; // r16
  int v160; // r11
  char v161; // r3
  int v162; // r11
  float *v163; // r29
  int v164; // r10
  char v165; // r3
  float *v166; // r15
  int v167; // r11
  char v168; // r3
  idMem *v169; // r26
  float *v170; // r30
  float *v171; // r28
  char *v172; // r22
  void *v173; // r23
  int *v174; // r10
  unsigned int v175; // r6
  char *v176; // r7
  int jj; // ctr
  int *v178; // r11
  int kk; // ctr
  unsigned int mm; // r9
  char *v181; // r10
  int v182; // r4
  int v183; // r11
  unsigned int v184; // ctr
  int v185; // r11
  signed int nn; // ctr
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v187; // r9
  float *v188; // r8
  unsigned int v189; // ctr
  float *v190; // r10
  float *v191; // r11
  int v192; // r3
  float *v193; // r10
  signed int v194; // ctr
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v195; // r11
  int v196; // r14
  __int64 v197; // r10 OVERLAPPED
  int v198; // r29
  int v199; // r28
  int v200; // r27
  __int16 *v201; // r3
  float *v202; // r30
  char *v203; // r25
  const void *v204; // r5
  int v205; // ctr
  float *v206; // r4
  int v207; // r26
  __int64 v208; // r8 OVERLAPPED
  int v209; // r24
  int v210; // r23
  int v211; // r22
  int v212; // r21
  int v213; // r20
  int v214; // r17
  int v215; // r19
  int v216; // r16
  int v217; // r18
  int v218; // r15
  int v219; // r11
  int v220; // r7
  int v221; // r9
  signed __int16 v222; // r9
  unsigned __int16 *v223; // r6
  BOOL v224; // r10
  int v225; // r9
  int v226; // r6
  unsigned __int8 v227; // r6
  int v228; // r10
  BOOL v229; // r14
  int v230; // r14
  char v231; // r14
  char v232; // r9
  int v233; // r14
  char v234; // r9
  int v235; // r7
  int v236; // r6
  int v237; // r6
  int v238; // r6
  unsigned int v239; // r11
  unsigned int v240; // r6
  idMem *v241; // r21
  int v242; // ctr
  unsigned __int64 v243; // r9
  float *v244; // r7
  int v245; // r17
  float v246; // r5
  unsigned __int64 v247; // r4
  float v248; // r30
  float v249; // r29
  float v250; // r28
  float v251; // r27
  float v252; // r18
  int v253; // r6
  int v254; // r25
  int v255; // r24
  int v256; // r23
  int v257; // r22
  int v258; // r21
  int v259; // r20
  int v260; // r19
  unsigned __int64 v261; // r11
  int v262; // r15
  int v263; // r11
  char v264; // r10
  int v265; // r15
  unsigned __int64 v266; // r9
  char v267; // r10
  int v268; // r15
  char v269; // r10
  int v270; // r15
  char v271; // r10
  int v272; // r15
  char v273; // r10
  int v274; // r15
  char v275; // r10
  int v276; // r15
  char v277; // r10
  int v278; // r15
  char v279; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v280; // r25
  unsigned __int16 *v281; // r27
  _BYTE *v282; // r11
  unsigned __int16 *v283; // r10
  int v284; // ctr
  char *v285; // r7
  int v286; // r6
  int v287; // r5
  int v288; // r4
  int v289; // r3
  int v290; // r30
  int v291; // r29
  float *v292; // r10
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v293; // r11
  int v294; // ctr
  int v295; // r11
  int i1; // ctr
  int v297; // r11
  int i2; // ctr
  float *v299; // r30
  idStr *v300; // r29
  int v301; // r30
  idStr *v302; // r28
  idStr *v303; // r29
  int v304; // r30
  idStr *v305; // r28
  idStr *v306; // r29
  int v307; // r30
  idStr *v308; // r28
  idMem *v309; // r26
  idStr *list; // r29
  int size; // r30
  idStr *v312; // r28
  idStr *v313; // r29
  int v314; // r30
  idStr *v315; // r28
  idStr *v316; // r29
  int v317; // r30
  idStr *v318; // r28
  _DWORD back_chain[2]; // [sp+0h] [-670h]
  unsigned __int8 **v320; // [sp+8h] [-668h]
  unsigned __int8 **v321; // [sp+Ch] [-664h]
  int v322; // [sp+10h] [-660h]
  int v323; // [sp+14h] [-65Ch]
  int v324; // [sp+18h] [-658h]
  int v325; // [sp+1Ch] [-654h]
  int v326; // [sp+20h] [-650h]
  int v327; // [sp+24h] [-64Ch]
  int v328; // [sp+28h] [-648h]
  int v329; // [sp+2Ch] [-644h]
  int v330; // [sp+30h] [-640h]
  int v331; // [sp+34h] [-63Ch]
  int v332; // [sp+38h] [-638h]
  int v333; // [sp+3Ch] [-634h]
  int v334; // [sp+40h] [-630h]
  int v335; // [sp+44h] [-62Ch]
  int v336; // [sp+48h] [-628h]
  int v337; // [sp+4Ch] [-624h]
  int v338; // [sp+50h] [-620h]
  int v339; // [sp+58h] [-618h]
  void *v340; // [sp+60h] [-610h] BYREF
  int v341; // [sp+64h] [-60Ch]
  int v342; // [sp+68h] [-608h]
  idMem *v343; // [sp+6Ch] [-604h]
  char v344[4]; // [sp+70h] [-600h] BYREF
  int v345; // [sp+74h] [-5FCh]
  idFileLocal v346[2]; // [sp+78h] [-5F8h] BYREF
  idList<idStr,5> v347; // [sp+80h] [-5F0h] BYREF
  idList<idStr,5> v348; // [sp+90h] [-5E0h] BYREF
  const char *v349; // [sp+A0h] [-5D0h]
  int v350; // [sp+A4h] [-5CCh] BYREF
  float *v351; // [sp+A8h] [-5C8h]
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v352; // [sp+ACh] [-5C4h]
  __int64 v353; // [sp+B0h] [-5C0h]
  unsigned __int64 v354; // [sp+B8h] [-5B8h] BYREF
  unsigned int v355; // [sp+C0h] [-5B0h] BYREF
  int v356; // [sp+C4h] [-5ACh]
  int v357; // [sp+C8h] [-5A8h]
  int v358; // [sp+CCh] [-5A4h]
  int v359; // [sp+D0h] [-5A0h]
  int v360; // [sp+D4h] [-59Ch]
  int v361; // [sp+D8h] [-598h]
  int v362; // [sp+DCh] [-594h]
  idList<unsigned short,5> v363; // [sp+E0h] [-590h] BYREF
  idList<unsigned short,5> v364; // [sp+F0h] [-580h] BYREF
  signed int v365; // [sp+100h] [-570h]
  int v366; // [sp+104h] [-56Ch]
  int v367; // [sp+108h] [-568h]
  const float *v368; // [sp+10Ch] [-564h]
  __int64 v369; // [sp+110h] [-560h]
  int v370; // [sp+118h] [-558h]
  __int64 v371; // [sp+120h] [-550h]
  idList<idDeclVehicleUpgrade const *,5> v372; // [sp+130h] [-540h] BYREF
  const void *v373[8]; // [sp+140h] [-530h] BYREF
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> v374; // [sp+160h] [-510h] BYREF
  idStr v375; // [sp+170h] [-500h] BYREF
  idList<unsigned short,5> v376; // [sp+190h] [-4E0h] BYREF
  idList<float,13> v377; // [sp+1A0h] [-4D0h] BYREF
  idList<float,13> v378; // [sp+1B0h] [-4C0h] BYREF
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> v379; // [sp+1C0h] [-4B0h] BYREF
  float v380; // [sp+1D0h] [-4A0h] BYREF
  float v381; // [sp+1D4h] [-49Ch]
  float v382; // [sp+1D8h] [-498h]
  float v383; // [sp+1DCh] [-494h]
  float v384; // [sp+1E0h] [-490h]
  unsigned __int64 v385; // [sp+1E4h] [-48Ch]
  float v386; // [sp+1ECh] [-484h]
  idTempArray<char> v387; // [sp+1F0h] [-480h] BYREF
  idTempArray<char> v388; // [sp+1F8h] [-478h] BYREF
  int v389; // [sp+200h] [-470h] BYREF
  int v390; // [sp+204h] [-46Ch]
  int v391; // [sp+208h] [-468h]
  int v392; // [sp+20Ch] [-464h]
  int v393; // [sp+210h] [-460h]
  int v394; // [sp+214h] [-45Ch]
  int v395; // [sp+218h] [-458h]
  int v396; // [sp+21Ch] [-454h]
  idStr v397; // [sp+220h] [-450h] BYREF
  idToken v398; // [sp+240h] [-430h] BYREF
  int v399; // [sp+28Ch] [-3E4h] BYREF
  int v400; // [sp+290h] [-3E0h] BYREF
  int v401; // [sp+294h] [-3DCh]
  int v402; // [sp+298h] [-3D8h]
  int v403; // [sp+29Ch] [-3D4h]
  int v404; // [sp+2A0h] [-3D0h]
  int v405; // [sp+2A4h] [-3CCh]
  int v406; // [sp+2A8h] [-3C8h]
  int v407; // [sp+2ACh] [-3C4h]
  const void *v408[7]; // [sp+2B0h] [-3C0h] BYREF
  int v409; // [sp+2CCh] [-3A4h] BYREF
  int v410; // [sp+2D0h] [-3A0h] BYREF
  int v411; // [sp+2D4h] [-39Ch]
  unsigned int v412; // [sp+2D8h] [-398h]
  int v413; // [sp+2DCh] [-394h]
  int v414; // [sp+2E0h] [-390h]
  int v415; // [sp+2E4h] [-38Ch]
  int v416; // [sp+2E8h] [-388h]
  int v417; // [sp+2ECh] [-384h]
  char *v418; // [sp+2F0h] [-380h]
  int v419; // [sp+2F4h] [-37Ch]
  idStr v420; // [sp+300h] [-370h] BYREF
  idParser v421; // [sp+320h] [-350h] BYREF

  idParser::ExpectTokenString(this: parser, string: MD6_VERSION_STRING);
  v3 = idParser::ParseInt(this: parser);
  if ( v3 != 1 )
  {
    idParser::Error(this: parser, str: "Invalid skeleton version %d. Should be version %d.\n", v3, 1);
    return 0;
  }
  v375.len = 0;
  v5 = 0;
  v375.allocedAndFlag = 20;
  v6 = 0;
  v375.data = v375.baseBuffer;
  v342 = 0;
  v345 = 0;
  v375.baseBuffer[0] = 0;
  v397.allocedAndFlag = 20;
  v397.data = v397.baseBuffer;
  v397.len = 0;
  v397.baseBuffer[0] = 0;
  v398.allocedAndFlag = 20;
  v398.len = 0;
  v398.data = v398.baseBuffer;
  v398.baseBuffer[0] = 0;
  v398.intvalue = 0;
  v398.floatvalue = -3.4028235e38;
  memset(&v398.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenString(this: parser, string: "init");
  idParser::ExpectTokenType(this: parser, type: 5, subtype: 46, token: &v398);
  if ( idParser::HadError(this: parser) )
    goto LABEL_27;
  while ( 1 )
  {
    if ( !idParser::ReadToken(this: parser, token: &v398) || v398.type == 5 && v398.subtype == 47 )
    {
LABEL_26:
      v345 = v6;
      v342 = v5;
      goto LABEL_27;
    }
    if ( idStr::Icmp(s1: v398.data, s2: "commandLine") != 0 && idStr::Icmp(s1: v398.data, s2: "sourceFile") != 0 )
      break;
    idParser::ExpectTokenType(this: parser, type: 1, subtype: 0, token: &v398);
LABEL_25:
    if ( idParser::HadError(this: parser) )
      goto LABEL_26;
  }
  if ( idStr::Icmp(s1: v398.data, s2: "numJoints") == 0 )
  {
    v7 = idParser::ParseInt(this: parser);
    v5 = v7;
    if ( v7 >= 0x100 )
    {
      v342 = v7;
      v345 = v6;
      idParser::Error(this: parser, str: "Invalid number of joints %d", v7);
      idStr::FreeData(this: &v398);
      idStr::FreeData(this: &v397);
      idStr::FreeData(this: &v375);
      return 0;
    }
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v398.data, s2: "numUserChannels") == 0 )
  {
    v8 = idParser::ParseInt(this: parser);
    v6 = v8;
    if ( v8 >= 0x100 )
    {
      v342 = v5;
      v345 = v8;
      idParser::Error(this: parser, str: "Invalid number of user channels %d", v8);
      idStr::FreeData(this: &v398);
      idStr::FreeData(this: &v397);
      idStr::FreeData(this: &v375);
      return 0;
    }
    goto LABEL_25;
  }
  if ( idStr::Icmp(s1: v398.data, s2: "jointconversion") == 0 )
  {
    idParser::ExpectTokenType(this: parser, type: 1, subtype: 0, token: &v398);
    idStr::operator=(this: &v375, text: &v398);
    if ( v375.len == 0 || *v375.data != 0 )
      goto LABEL_25;
    v9 = &v375;
    goto LABEL_24;
  }
  if ( idStr::Icmp(s1: v398.data, s2: "userChannelFile") == 0 )
  {
    idParser::ExpectTokenType(this: parser, type: 1, subtype: 0, token: &v398);
    idStr::operator=(this: &v397, text: &v398);
    if ( v397.len == 0 || *v397.data != 0 )
      goto LABEL_25;
    v9 = &v397;
LABEL_24:
    idStr::Clear(this: v9);
    goto LABEL_25;
  }
  v345 = v6;
  v342 = v5;
  idParser::Error(this: parser, str: "Unknown token '%s' in 'init' section", v398.data);
LABEL_27:
  if ( idParser::HadError(this: parser) )
  {
    idStr::FreeData(this: &v398);
    idStr::FreeData(this: &v397);
    idStr::FreeData(this: &v375);
    return 0;
  }
  v10 = fileSystem->OpenFileRead(this: fileSystem, a2: v397.data, a3: 1, a4: 0);
  v346[0].file = v10;
  if ( v397.len != 0 && v10 == nullptr )
    idParser::Error(this: parser, str: "UserChannels file not found %s", v398.data);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v372);
  idParser::idParser(this: &v421, flags: 544);
  if ( v346[0].file == nullptr )
  {
LABEL_41:
    v14 = (v6 + 7) & 0xFFFFFFF8;
    v15 = (v5 + 7) & 0xFFFFFFF8;
    v365 = v14;
    v367 = v15;
    if ( v14 < v6 )
    {
      idParser::Error(this: parser, str: "numUserChannels too big (wrapping 32-bit");
      idParser::~idParser(this: &v421);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v372);
      idFileLocal::~idFileLocal(this: v346);
      idStr::FreeData(this: &v398);
      idStr::FreeData(this: &v397);
      idStr::FreeData(this: &v375);
      return 0;
    }
    if ( v15 < v5 )
    {
      idParser::Error(this: parser, str: "numJoints too big (wrapping 32-bit");
      idParser::~idParser(this: &v421);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v372);
      idFileLocal::~idFileLocal(this: v346);
      idStr::FreeData(this: &v398);
      idStr::FreeData(this: &v397);
      idStr::FreeData(this: &v375);
      return 0;
    }
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v16) = back_chain[0];
    HIDWORD(v371) = &v340;
    v17 = ((int (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
    v352 = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)&v340;
    ((void (__fastcall *)(int))RtlCheckStack12)(a1: v17);
    *(_DWORD *)((char *)back_chain + v19) = back_chain[0];
    HIDWORD(v354) = &v340;
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v20) = back_chain[0];
    v368 = (const float *)&v340;
    HIDWORD(v369) = &v340 + 4 * v15;
    HIDWORD(v353) = &v340 + 8 * v15;
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v21) = back_chain[0];
    v351 = (float *)&v340;
    idTempArray<char>::idTempArray<char>(this: &v388, num: 8 * v15);
    idTempArray<char>::idTempArray<char>(this: &v387, num: 8 * v14);
    p_num = &v388.num;
    buffer = v387.buffer;
    v24 = v388.buffer;
    for ( i = 8; i != 0; --i )
      *++p_num = 0;
    v26 = (_DWORD *)&v354 + 1;
    for ( j = 8; j != 0; --j )
      *++v26 = 0;
    for ( k = 0; k < 8; ++k )
    {
      v29 = v15 == 0 ? nullptr : v24;
      v373[k] = v29;
      v30 = 0;
      v31 = v14 == 0 ? nullptr : buffer;
      v408[k] = v31;
      if ( v15 > 0 )
      {
        v32 = (v5 + 7) & 0xFFFFFFF8;
        do
        {
          v29[v30++] = 0;
          --v32;
        }
        while ( v32 != 0 );
      }
      v33 = 0;
      if ( v14 > 0 )
      {
        v34 = (v6 + 7) & 0xFFFFFFF8;
        do
        {
          v31[v33++] = 0;
          --v34;
        }
        while ( v34 != 0 );
      }
      v24 += v15;
      buffer += v14;
    }
    *(_WORD *)&v348.memTag = 1280;
    memset(&v348, 0, 14);
    *(_WORD *)&v347.memTag = 1280;
    memset(&v347, 0, 14);
    idList<idStr,3>::SetNum(this: &v348, newNum: v5);
    idList<idStr,3>::SetNum(this: &v347, newNum: v6);
    idParser::ExpectTokenString(this: parser, string: "joints");
    idParser::ExpectTokenType(this: parser, type: 5, subtype: 46, token: &v398);
    v35 = (char *)v373[1];
    v343 = (idMem *)-2091122688;
    if ( v5 > 0 )
    {
      v36 = (char *)v373[1];
      v37 = (float *)HIDWORD(v369);
      v38 = 0;
      v39 = (float *)(HIDWORD(v353) + 12);
      v40 = HIDWORD(v369) - HIDWORD(v353);
      v41 = (_WORD *)HIDWORD(v371);
      v42 = (char *)v373[6] - (char *)v373[1];
      v43 = HIDWORD(v354) - HIDWORD(v371);
      v44 = (char *)v368 - HIDWORD(v369);
      v45 = (char *)v373[2] - (char *)v373[1];
      v46 = (char *)v373[3] - (char *)v373[1];
      v47 = v342;
      v48 = (char *)v373[4] - (char *)v373[1];
      v49 = v362;
      v50 = (char *)v373[5] - (char *)v373[1];
      v366 = (char *)v373[0] - (char *)v373[1];
      v51 = (char *)v373[7] - (char *)v373[1];
      v349 = "Invalid parent for joint '%s'";
      do
      {
        idParser::ReadToken(this: parser, token: &v398);
        idStr::ToLower(this: &v398);
        idStr::operator=(this: &v348.list[v38], text: v398.data);
        *v41 = *(_WORD *)(*(int (__fastcall **)(char *))(**(_DWORD **)&v343[-1896] + 24))(a1: v344);
        v52 = idParser::ParseInt(this: parser);
        v53 = v342;
        *(_WORD *)((char *)v41 + v43) = v52;
        if ( v52 >= v53 )
        {
          v54 = (*(int (__fastcall **)(_DWORD, _WORD *))(**(_DWORD **)&v343[-1896] + 32))(
                  a1: *(_DWORD *)&v343[-1896],
                  a2: v41);
          idParser::Error(this: parser, str: v349, v54);
        }
        idParser::Parse1DMatrix(this: parser, x: 8, m: &v380);
        v380 = 1.0;
        v55 = v355 | 1;
        v36[v366] = -1;
        v355 = v55;
        v341 = (int)(float)((float)(v381 * (float)255.0) + (float)0.5);
        v56 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v56 = -1;
        }
        else
        {
          v56 = 0;
        }
        *v36 = v56;
        v341 = (int)(float)((float)(v382 * (float)255.0) + (float)0.5);
        v57 = v56 != 0;
        v58 = v341;
        v356 |= v57;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v58 = -1;
        }
        else
        {
          v58 = 0;
        }
        v36[v45] = v58;
        v357 |= v36[v45] != 0;
        v341 = (int)(float)((float)(v383 * (float)255.0) + (float)0.5);
        v59 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v59 = -1;
        }
        else
        {
          v59 = 0;
        }
        v36[v46] = v59;
        v358 |= v36[v46] != 0;
        v341 = (int)(float)((float)(v384 * (float)255.0) + (float)0.5);
        v60 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v60 = -1;
        }
        else
        {
          v60 = 0;
        }
        v36[v48] = v60;
        v359 |= v36[v48] != 0;
        v341 = (int)(float)((float)(*(float *)&v385 * (float)255.0) + (float)0.5);
        v61 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v61 = -1;
        }
        else
        {
          v61 = 0;
        }
        v36[v50] = v61;
        v360 |= v36[v50] != 0;
        v341 = (int)(float)((float)(*((float *)&v385 + 1) * (float)255.0) + (float)0.5);
        v62 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v62 = -1;
        }
        else
        {
          v62 = 0;
        }
        v36[v42] = v62;
        v361 |= v36[v42] != 0;
        v341 = (int)(float)((float)(v386 * (float)255.0) + (float)0.5);
        v63 = v341;
        if ( v341 >= 0 )
        {
          if ( v341 > 255 )
            v63 = -1;
        }
        else
        {
          v63 = 0;
        }
        v36[v51] = v63;
        v49 |= v63 != 0;
        idParser::Parse1DMatrix(this: parser, x: 4, m: (float *)((char *)v37 + (_DWORD)v44));
        idParser::Parse1DMatrix(this: parser, x: 3, m: v37);
        idParser::Parse1DMatrix(this: parser, x: 3, m: v39 - 3);
        *(float *)((char *)v39 + v40) = 1.0;
        *v39 = 0.0;
        --v47;
        ++v38;
        ++v41;
        ++v36;
        v37 += 4;
        v39 += 4;
      }
      while ( v47 != 0 );
      v362 = v49;
    }
    v64 = parser;
    idParser::ExpectTokenType(this: parser, type: 5, subtype: 47, token: &v398);
    v65 = &v421;
    if ( v346[0].file == nullptr )
      v65 = parser;
    if ( idParser::CheckTokenString(this: v65, string: "userChannels") != 0 )
    {
      idParser::ExpectTokenType(this: v65, type: 5, subtype: 46, token: &v398);
      v66 = v345;
      if ( v345 > 0 )
      {
        v67 = v345;
        v68 = 0;
        v69 = (char *)v408[1];
        v70 = (char *)v408[2] - (char *)v408[1];
        v71 = (char *)v408[3] - (char *)v408[1];
        v72 = v351 - 1;
        v73 = (char *)v408[4] - (char *)v408[1];
        v74 = (char *)v408[5] - (char *)v408[1];
        v75 = v352;
        v76 = (char *)v408[6] - (char *)v408[1];
        v77 = v396;
        v78 = v409 - (unsigned int)v408[1];
        v79 = v395;
        v80 = v394;
        v350 = (char *)v408[0] - (char *)v408[1];
        do
        {
          idParser::ReadToken(this: v65, token: &v398);
          idStr::ToLower(this: &v398);
          idStr::operator=(this: &v347.list[v68], text: v398.data);
          v75->value = *(unsigned __int16 *)(*(int (__fastcall **)(char *))(**(_DWORD **)&v343[-1896] + 36))(a1: v344);
          idParser::Parse1DMatrix(this: v65, x: 8, m: &v380);
          v341 = (int)(float)((float)(v380 * (float)255.0) + (float)0.5);
          v81 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v81 = -1;
          }
          else
          {
            v81 = 0;
          }
          v82 = v389;
          v69[v350] = v81;
          v341 = (int)(float)((float)(v381 * (float)255.0) + (float)0.5);
          v389 = (v81 != 0) | v82;
          v83 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v83 = -1;
          }
          else
          {
            v83 = 0;
          }
          *v69 = v83;
          v84 = (unsigned __int8)*v69;
          v341 = (int)(float)((float)(v382 * (float)255.0) + (float)0.5);
          v85 = v341;
          v390 |= v84 != 0;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v85 = -1;
          }
          else
          {
            v85 = 0;
          }
          v69[v70] = v85;
          v391 |= v69[v70] != 0;
          v341 = (int)(float)((float)(v383 * (float)255.0) + (float)0.5);
          v86 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v86 = -1;
          }
          else
          {
            v86 = 0;
          }
          v69[v71] = v86;
          v392 |= v69[v71] != 0;
          v341 = (int)(float)((float)(v384 * (float)255.0) + (float)0.5);
          v87 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v87 = -1;
          }
          else
          {
            v87 = 0;
          }
          v69[v73] = v87;
          v393 |= v69[v73] != 0;
          v341 = (int)(float)((float)(*(float *)&v385 * (float)255.0) + (float)0.5);
          v88 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v88 = -1;
          }
          else
          {
            v88 = 0;
          }
          v69[v74] = v88;
          v80 |= v88 != 0;
          v341 = (int)(float)((float)(*((float *)&v385 + 1) * (float)255.0) + (float)0.5);
          v89 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v89 = -1;
          }
          else
          {
            v89 = 0;
          }
          v69[v76] = v89;
          v79 |= v89 != 0;
          v341 = (int)(float)((float)(v386 * (float)255.0) + (float)0.5);
          v90 = v341;
          if ( v341 >= 0 )
          {
            if ( v341 > 255 )
              v90 = -1;
          }
          else
          {
            v90 = 0;
          }
          v69[v78] = v90;
          v77 |= v90 != 0;
          *++v72 = idParser::ParseFloat(this: v65, errorFlag: nullptr);
          --v67;
          ++v68;
          ++v75;
          ++v69;
        }
        while ( v67 != 0 );
        v395 = v79;
        v64 = parser;
        v66 = v345;
        v394 = v80;
        v396 = v77;
      }
      v91 = v343;
      idParser::ExpectTokenType(this: v65, type: 5, subtype: 47, token: &v398);
    }
    else
    {
      v91 = v343;
      v66 = v345;
    }
    v92 = v368;
    v93 = (__int16 *)HIDWORD(v354);
    if ( v342 < v367 )
    {
      v94 = &v35[v342];
      v95 = v367 - v342;
      v97 = HIDWORD(v369) - (_DWORD)v368;
      v98 = HIDWORD(v353) - (_DWORD)v368;
      v99 = HIDWORD(v353) - HIDWORD(v369);
      v100 = (char *)v373[3] - (char *)v35;
      v101 = (char *)v373[4] - (char *)v35;
      v102 = (char *)v373[5] - (char *)v35;
      v103 = (char *)v373[6] - (char *)v35;
      v349 = (const char *)v373[7];
      v104 = HIDWORD(v371) - HIDWORD(v354);
      v105 = (char *)v373[0] - (char *)v35;
      v106 = (char *)v373[2] - (char *)v35;
      v107 = (_WORD *)(2 * v342 + HIDWORD(v354));
      v96 = (float *)(16 * v342 + HIDWORD(v353) - 12);
      v108 = (float *)(16 * v342 + HIDWORD(v369) + 12);
      v109 = (float *)&v368[4 * v342 + 2];
      v110 = (char *)v373[7] - (char *)v35;
      do
      {
        *(_WORD *)((char *)v107 + v104) = NULL_JOINT.value;
        *v107++ = -1;
        v94[v105] = 0;
        *v94 = 0;
        v94[v106] = 0;
        v94[v100] = 0;
        v94[v101] = 0;
        v94[v102] = 0;
        v94[v103] = 0;
        v94[v110] = 0;
        *(v109 - 2) = 0.0;
        *(v109 - 1) = 0.0;
        ++v94;
        *v109 = 0.0;
        v109[1] = 1.0;
        *(v108 - 3) = 1.0;
        *(v108 - 2) = 1.0;
        *(float *)((char *)v109 + v97) = 1.0;
        *v108 = 1.0;
        v96[3] = 0.0;
        *(float *)((char *)v109 + v98) = 0.0;
        v109 += 4;
        *(float *)((char *)v108 + v99) = 0.0;
        v108 += 4;
        v96 += 4;
        *v96 = 0.0;
        --v95;
      }
      while ( v95 != 0 );
    }
    if ( v66 < v365 )
    {
      v111 = &v351[v66 - 1];
      v112 = &v352[v66 - 1];
      v113 = v365 - v66;
      do
      {
        ++v112;
        v112->value = NULL_USERCHANNEL.value;
        *++v111 = 0.0;
        --v113;
      }
      while ( v113 != 0 );
    }
    v114 = 0;
    for ( m = 8; m != 0; --m )
    {
      if ( *(unsigned int *)((char *)&v355 + v114 * 4) == 0 )
        v373[v114] = nullptr;
      ++v114;
    }
    v116 = 0;
    for ( n = 8; n != 0; --n )
    {
      if ( *(int *)((char *)&v389 + v116 * 4) == 0 )
        v408[v116] = nullptr;
      ++v116;
    }
    idStr::idStr(this: &v420, text: this->name.str);
    idStr::AppendPath(this: &v420, text: "_default.md6jointconversion");
    (*(void (__fastcall **)(_DWORD, char *, idList<idStr,5> *, idList<idStr,5> *))(**(_DWORD **)&v91[-1896] + 52))(
      a1: *(_DWORD *)&v91[-1896],
      a2: v420.data,
      a3: &v348,
      a4: &v347);
    if ( v375.len == 0 )
    {
      len = v420.len;
      v119 = v420.len + 1;
      v120 = v375.allocedAndFlag & 0x7FFFFFFF;
      if ( v375.allocedAndFlag >= 0 )
      {
        if ( v119 > v120 )
          idStr::ReAllocate(this: &v375, amount: v119, keepold: false);
      }
      else if ( v119 > v120
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: v375.data, Src: v420.data, Size: len);
      v375.data[len] = 0;
      v375.len = len;
    }
    idStr::FreeData(this: &v420);
    this->jointConversion.value = *(_WORD *)(*(int (__fastcall **)(char *))(**(_DWORD **)&v91[-1896] + 56))(a1: v344);
    v121 = *(_WORD *)(*(int (__fastcall **)(int *))(**(_DWORD **)&v91[-1896] + 80))(a1: &v350);
    v122 = v375.len;
    v343 = &mem;
    this->jointConversionChecksum.value = v121;
    if ( v122 == 0 )
    {
      idLib::Warning(fmt: "Skeleton '%s' contains no joint conversion '%s'", this->name.str, v375.data);
      if ( (unsigned __int8)idMD6Skel::MakeSkeletonData(
                              this,
                              numJoints: v342,
                              basePose: v92,
                              jointHandleTbl: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)HIDWORD(v371),
                              parentTbl: v93,
                              numUserChannels: v66,
                              U: v351,
                              userChannelHandleTbl: v352,
                              jointWeights: v320,
                              userWeights: v321,
                              a11: v322,
                              a12: v323,
                              a13: v324,
                              a14: v325,
                              a15: v326,
                              a16: v327,
                              a17: v328,
                              a18: v329,
                              a19: v330,
                              a20: v331,
                              a21: v332,
                              a22: v333,
                              a23: v334,
                              a24: v335,
                              a25: v336,
                              a26: v337,
                              a27: v338,
                              a28: v373,
                              a29: v339,
                              a30: v408) == 0 )
      {
        if ( v347.listStatic == 0 || v347.listStatic == 2 )
        {
          list = v347.list;
          if ( v347.list != nullptr )
          {
            size = v347.size;
            v312 = v347.list;
            if ( v347.size > 0 )
            {
              do
              {
                idStr::FreeData(this: list);
                --size;
                ++list;
              }
              while ( size != 0 );
            }
            idMem::Free(this: &mem, ptr: v312, align: ALIGN_16);
          }
          v347.list = nullptr;
          v347.size = 0;
        }
        v347.num = 0;
        if ( v348.listStatic == 0 || v348.listStatic == 2 )
        {
          v313 = v348.list;
          if ( v348.list != nullptr )
          {
            v314 = v348.size;
            v315 = v348.list;
            if ( v348.size > 0 )
            {
              do
              {
                idStr::FreeData(this: v313);
                --v314;
                ++v313;
              }
              while ( v314 != 0 );
            }
            idMem::Free(this: &mem, ptr: v315, align: ALIGN_16);
          }
          v348.list = nullptr;
          v348.size = 0;
        }
        v348.num = 0;
        if ( v387.buffer != nullptr )
          idMem::Free(this: &mem, ptr: v387.buffer, align: ALIGN_16);
        if ( v388.buffer != nullptr )
          idMem::Free(this: &mem, ptr: v388.buffer, align: ALIGN_16);
        idParser::~idParser(this: &v421);
        if ( (v372.listStatic == 0 || v372.listStatic == 2) && v372.list != nullptr )
          idMem::Free(this: &mem, ptr: v372.list, align: ALIGN_16);
        goto LABEL_476;
      }
      goto LABEL_447;
    }
    v123 = nullptr;
    *(_WORD *)&v363.memTag = 1280;
    v124 = 0;
    memset(&v363, 0, 14);
    v125 = 0;
    *(_WORD *)&v364.memTag = 1280;
    memset(&v364, 0, 14);
    v126 = v342;
    if ( v342 > 0 )
    {
      v127 = idList<unsigned short,30>::Resize(this: &v363, newsize: v342);
      v123 = v363.list;
      if ( v127 == 0 )
        goto LABEL_160;
      v124 = v363.size;
    }
    v363.num = v126;
    if ( v126 >= v124 )
      v363.num = v124;
LABEL_160:
    if ( v66 > 0 )
    {
      if ( (unsigned __int8)idList<unsigned short,30>::Resize(this: &v364, newsize: v66) == 0 )
        goto LABEL_165;
      v125 = v364.size;
    }
    v364.num = v66;
    if ( v66 >= v125 )
      v364.num = v125;
LABEL_165:
    this->jointConversion.value = *(_WORD *)(*(int (__fastcall **)(int *))(**(_DWORD **)&v91[-1896] + 56))(a1: &v350);
    v128 = (unsigned __int16 *)(*(int (__fastcall **)(char *))(**(_DWORD **)&v91[-1896] + 80))(a1: v344);
    value = this->jointConversion.value;
    this->jointConversionChecksum.value = *v128;
    if ( value == 0xFFFF )
      idParser::Error(this: v64, str: "Invalid jointconversion: %s", v375.data);
    v130 = -1;
    if ( v126 > 0 )
    {
      v131 = 0;
      v132 = v123;
      do
      {
        v133 = (*(int (__fastcall **)(_DWORD, _DWORD, char *))(**(_DWORD **)&v91[-1896] + 72))(
                 a1: *(_DWORD *)&v91[-1896],
                 a2: this->jointConversion.value,
                 a3: v348.list[v131].data);
        v134 = v133;
        v135 = v133;
        if ( v133 == -1 )
          idParser::Error(this: v64, str: "Joint not found in jointconversion: %s", v348.list[v131].data);
        *v132 = v135;
        if ( v130 <= v134 )
          v130 = v135;
        --v126;
        ++v131;
        ++v132;
      }
      while ( v126 != 0 );
    }
    v136 = -1;
    v137 = v130 + 1;
    v349 = (const char *)v137;
    if ( v66 > 0 )
    {
      v138 = v364.list;
      v139 = 0;
      for ( ii = v66; ii != 0; --ii )
      {
        v141 = (*(int (__fastcall **)(_DWORD, _DWORD, char *))(**(_DWORD **)&v91[-1896] + 88))(
                 a1: *(_DWORD *)&v91[-1896],
                 a2: this->jointConversion.value,
                 a3: v347.list[v139].data);
        v142 = v141;
        v136 = v141;
        if ( v141 == -1 )
          idParser::Error(this: v64, str: "UserChannel not found in jointconversion: %s", v347.list[v139].data);
        *v138 = v136;
        if ( v130 > v142 )
          v136 = v130;
        ++v139;
        ++v138;
      }
    }
    v143 = v136 + 1;
    v144 = (v130 + 8) & 0xFFFFFFF8;
    v365 = v143;
    v367 = v144;
    v145 = (v136 + 8) & 0xFFFFFFF8;
    v366 = v145;
    if ( v144 < v137 )
    {
      idParser::Error(this: v64, str: "numJointsConv too big (wrapping 32-bit");
      if ( (v364.listStatic == 0 || v364.listStatic == 2) && v364.list != nullptr )
        idMem::Free(this: &mem, ptr: v364.list, align: ALIGN_16);
      if ( (v363.listStatic == 0 || v363.listStatic == 2) && v123 != nullptr )
        idMem::Free(this: &mem, ptr: v123, align: ALIGN_16);
      if ( v347.listStatic == 0 || v347.listStatic == 2 )
      {
        v146 = v347.list;
        if ( v347.list != nullptr )
        {
          v147 = v347.size;
          v148 = v347.list;
          if ( v347.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v146);
              --v147;
              ++v146;
            }
            while ( v147 != 0 );
          }
          idMem::Free(this: &mem, ptr: v148, align: ALIGN_16);
        }
        v347.list = nullptr;
        v347.size = 0;
      }
      v347.num = 0;
      if ( v348.listStatic == 0 || v348.listStatic == 2 )
      {
        v149 = v348.list;
        if ( v348.list != nullptr )
        {
          v150 = v348.size;
          v151 = v348.list;
          if ( v348.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v149);
              --v150;
              ++v149;
            }
            while ( v150 != 0 );
          }
          idMem::Free(this: &mem, ptr: v151, align: ALIGN_16);
        }
        v348.list = nullptr;
        v348.size = 0;
      }
      v348.num = 0;
      if ( v387.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v387.buffer, align: ALIGN_16);
      if ( v388.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v388.buffer, align: ALIGN_16);
      idParser::~idParser(this: &v421);
      if ( (v372.listStatic == 0 || v372.listStatic == 2) && v372.list != nullptr )
        idMem::Free(this: &mem, ptr: v372.list, align: ALIGN_16);
LABEL_476:
      idFileLocal::~idFileLocal(this: v346);
      idStr::FreeData(this: &v398);
      idStr::FreeData(this: &v397);
      idStr::FreeData(this: &v375);
      return 0;
    }
    if ( v145 < v143 )
    {
      idParser::Error(this: v64, str: "numUserChannelsConv too big (wrapping 32-bit");
      if ( (v364.listStatic == 0 || v364.listStatic == 2) && v364.list != nullptr )
        idMem::Free(this: &mem, ptr: v364.list, align: ALIGN_16);
      if ( (v363.listStatic == 0 || v363.listStatic == 2) && v123 != nullptr )
        idMem::Free(this: &mem, ptr: v123, align: ALIGN_16);
      if ( v347.listStatic == 0 || v347.listStatic == 2 )
      {
        v152 = v347.list;
        if ( v347.list != nullptr )
        {
          v153 = v347.size;
          v154 = v347.list;
          if ( v347.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v152);
              --v153;
              ++v152;
            }
            while ( v153 != 0 );
          }
          idMem::Free(this: &mem, ptr: v154, align: ALIGN_16);
        }
        v347.list = nullptr;
        v347.size = 0;
      }
      v347.num = 0;
      if ( v348.listStatic == 0 || v348.listStatic == 2 )
      {
        v155 = v348.list;
        if ( v348.list != nullptr )
        {
          v156 = v348.size;
          v157 = v348.list;
          if ( v348.size > 0 )
          {
            do
            {
              idStr::FreeData(this: v155);
              --v156;
              ++v155;
            }
            while ( v156 != 0 );
          }
          idMem::Free(this: &mem, ptr: v157, align: ALIGN_16);
        }
        v348.list = nullptr;
        v348.size = 0;
      }
      v348.num = 0;
      if ( v387.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v387.buffer, align: ALIGN_16);
      if ( v388.buffer != nullptr )
        idMem::Free(this: &mem, ptr: v388.buffer, align: ALIGN_16);
      idParser::~idParser(this: &v421);
      if ( (v372.listStatic == 0 || v372.listStatic == 2) && v372.list != nullptr )
        idMem::Free(this: &mem, ptr: v372.list, align: ALIGN_16);
      goto LABEL_476;
    }
    v158 = 0;
    *(_WORD *)&v374.memTag = 1280;
    memset(&v374, 0, 14);
    if ( v144 > 0 )
    {
      if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                              this: &v374,
                              newsize: (v130 + 8) & 0xFFFFFFF8) == 0 )
        goto LABEL_250;
      v158 = v374.size;
    }
    v374.num = (v130 + 8) & 0xFFFFFFF8;
    if ( v144 >= v158 )
      v374.num = v158;
LABEL_250:
    v159 = nullptr;
    v160 = 0;
    *(_WORD *)&v379.memTag = 1280;
    memset(&v379, 0, 14);
    if ( v145 > 0 )
    {
      v161 = idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(this: &v379, newsize: v145);
      v159 = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)v379.list;
      if ( v161 == 0 )
        goto LABEL_255;
      v160 = v379.size;
    }
    v379.num = (v136 + 8) & 0xFFFFFFF8;
    if ( v145 >= v160 )
      v379.num = v160;
LABEL_255:
    v162 = 0;
    *(_WORD *)&v376.memTag = 1280;
    memset(&v376, 0, 14);
    if ( v144 > 0 )
    {
      if ( (unsigned __int8)idList<unsigned short,30>::Resize(this: &v376, newsize: (v130 + 8) & 0xFFFFFFF8) == 0 )
        goto LABEL_260;
      v162 = v376.size;
    }
    v376.num = (v130 + 8) & 0xFFFFFFF8;
    if ( v144 >= v162 )
      v376.num = v162;
LABEL_260:
    v163 = nullptr;
    v164 = 0;
    *(_WORD *)&v378.memTag = 1280;
    memset(&v378, 0, 14);
    if ( 12 * v144 > 0 )
    {
      v165 = idList<float,116>::Resize(this: &v378, newsize: 12 * v144);
      v163 = v378.list;
      if ( v165 == 0 )
        goto LABEL_265;
      v164 = v378.size;
    }
    v378.num = 12 * v144;
    if ( 12 * v144 >= v164 )
      v378.num = v164;
LABEL_265:
    v166 = nullptr;
    v167 = 0;
    *(_WORD *)&v377.memTag = 1280;
    memset(&v377, 0, 14);
    if ( v145 > 0 )
    {
      v168 = idList<float,116>::Resize(this: &v377, newsize: v145);
      v166 = v377.list;
      if ( v168 == 0 )
      {
LABEL_270:
        v169 = v343;
        v170 = &v163[4 * v144];
        v171 = &v163[8 * v144];
        v419 = 8 * v144;
        v350 = (int)v170;
        v370 = (int)v171;
        v172 = (char *)idMem::AllocWithLocation(
                         this: v343,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                         size: 8 * v144,
                         tag: TAG_TEMP,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
        v418 = v172;
        v341 = 8 * v145;
        v173 = idMem::AllocWithLocation(
                 this: v169,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 8 * v145,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
        v340 = v173;
        v174 = &v399;
        v175 = (unsigned int)v173;
        v176 = v172;
        for ( jj = 8; jj != 0; --jj )
          *++v174 = 0;
        v178 = &v409;
        for ( kk = 8; kk != 0; --kk )
          *++v178 = 0;
        for ( mm = 0; mm < 0x20; mm += 4 )
        {
          v181 = v144 == 0 ? nullptr : v176;
          v182 = (v145 == 0) - 1;
          *(unsigned int *)((char *)&v355 + mm) = (unsigned int)v181;
          v183 = 0;
          *(_DWORD *)((char *)&v380 + mm) = v182 & v175;
          if ( v144 > 0 )
          {
            v184 = (v137 + 7) & 0xFFFFFFF8;
            do
            {
              v181[v183++] = 0;
              --v184;
            }
            while ( v184 != 0 );
          }
          v185 = 0;
          if ( v145 > 0 )
          {
            for ( nn = v145; nn != 0; --nn )
            {
              *(_BYTE *)(v185 + (v182 & v175)) = 0;
              ++v185;
            }
          }
          v176 += v144;
          v175 += v145;
        }
        if ( v144 > 0 )
        {
          v187 = v374.list;
          v188 = v171 - 3;
          v189 = (v137 + 7) & 0xFFFFFFF8;
          v190 = v170 + 3;
          v191 = v163 + 2;
          v192 = (char *)v376.list - (char *)v374.list;
          do
          {
            *(unsigned __int16 *)((char *)&v187->value + v192) = 0;
            v187->value = NULL_JOINT.value;
            *(v191 - 2) = 0.0;
            *(v191 - 1) = 0.0;
            ++v187;
            *v191 = 0.0;
            v191[1] = 1.0;
            *(v190 - 3) = 1.0;
            *(v190 - 2) = 1.0;
            v191[4 * v144] = 1.0;
            *v190 = 1.0;
            v188[3] = 0.0;
            v191[8 * v144] = 0.0;
            v191 += 4;
            *(float *)((char *)v190 + (char *)v171 - (char *)v170) = 0.0;
            v190 += 4;
            v188 += 4;
            *v188 = 0.0;
            --v189;
          }
          while ( v189 != 0 );
        }
        if ( v145 > 0 )
        {
          v193 = v166 - 1;
          v194 = v145;
          v195 = v159 - 1;
          do
          {
            ++v195;
            v195->value = NULL_USERCHANNEL.value;
            *++v193 = 0.0;
            --v194;
          }
          while ( v194 != 0 );
        }
        v196 = v356;
        if ( v342 > 0 )
        {
          LODWORD(v197) = v368 + 2;
          v198 = HIDWORD(v369) - (_DWORD)v368;
          v199 = HIDWORD(v353) - (_DWORD)v368;
          v200 = HIDWORD(v369) - HIDWORD(v353);
          v201 = (__int16 *)HIDWORD(v354);
          v202 = (float *)(HIDWORD(v369) - 16);
          v203 = (char *)v363.list - HIDWORD(v371);
          v204 = v373[1];
          v205 = v342;
          v206 = (float *)(HIDWORD(v353) + 4);
          v207 = HIDWORD(v371) - HIDWORD(v354);
          *((const void **)&v208 + 1) = v373[1];
          v209 = (char *)v373[0] - (char *)v373[1];
          v210 = (char *)v373[2] - (char *)v373[1];
          v211 = (char *)v373[3] - (char *)v373[1];
          v212 = (char *)v373[4] - (char *)v373[1];
          v213 = (char *)v373[5] - (char *)v373[1];
          v214 = v417;
          v215 = (char *)v373[6] - (char *)v373[1];
          v216 = v416;
          v217 = (char *)v373[7] - (char *)v373[1];
          v218 = v415;
          do
          {
            v219 = *(__int16 *)&v203[(_DWORD)v201 + v207];
            v220 = v219;
            v374.list[v219].value = *(__int16 *)((char *)v201 + v207);
            v221 = *v201;
            if ( v221 == -1 )
              v222 = -1;
            else
              v222 = v363.list[v221];
            v223 = v376.list;
            v376.list[v220] = v222;
            if ( v219 != 0 && v222 == -1 )
              v223[v220] = 0;
            if ( v373[0] != nullptr )
            {
              HIDWORD(v208) = v410;
              v344[0] = *(_BYTE *)(v209 + v208);
              HIDWORD(v197) = (unsigned __int8)v344[0];
              v371 = v197;
              v224 = v344[0] != 0;
              v225 = v357;
              v196 = v356;
              HIDWORD(v369) = v410;
              v354 = *(__int64 *)((char *)&v208 - 4);
              v353 = v208;
              *(_BYTE *)(v355 + v219) = v344[0];
              LODWORD(v208) = HIDWORD(v354);
              v410 = v224 | HIDWORD(v208);
              v197 = v371;
            }
            else
            {
              HIDWORD(v197) = v357;
            }
            HIDWORD(v208) = v358;
            v226 = v359;
            if ( v204 != nullptr )
            {
              v227 = *(_BYTE *)v208;
              v353 = v197;
              v369 = *(__int64 *)((char *)&v197 + 4);
              v228 = v411;
              v344[0] = v227;
              *(_BYTE *)(v196 + v219) = v227;
              v229 = v227 != 0;
              v226 = v359;
              LODWORD(v208) = HIDWORD(v369);
              v230 = v229 | v228;
              v197 = v353;
              v411 = v230;
            }
            if ( v373[2] != nullptr )
            {
              v353 = v197;
              v231 = *(_BYTE *)(v210 + v208);
              LODWORD(v197) = v412;
              *(_BYTE *)(HIDWORD(v197) + v219) = v231;
              v412 = (v231 != 0) | (unsigned int)v197;
              LODWORD(v197) = v353;
            }
            if ( v373[3] != nullptr )
            {
              v232 = *(_BYTE *)(v211 + v208);
              v233 = v413;
              *(_BYTE *)(HIDWORD(v208) + v219) = v232;
              v413 = (v232 != 0) | v233;
            }
            if ( v373[4] != nullptr )
            {
              v234 = *(_BYTE *)(v212 + v208);
              v235 = v414;
              *(_BYTE *)(v226 + v219) = v234;
              v414 = (v234 != 0) | v235;
            }
            if ( v373[5] != nullptr )
            {
              v236 = *(unsigned __int8 *)(v213 + v208);
              *(_BYTE *)(v360 + v219) = *(_BYTE *)(v213 + v208);
              v218 |= v236 != 0;
            }
            if ( v373[6] != nullptr )
            {
              v237 = *(unsigned __int8 *)(v215 + v208);
              *(_BYTE *)(v361 + v219) = *(_BYTE *)(v215 + v208);
              v216 |= v237 != 0;
            }
            if ( v373[7] != nullptr )
            {
              v238 = *(unsigned __int8 *)(v217 + v208);
              *(_BYTE *)(v362 + v219) = *(_BYTE *)(v217 + v208);
              v214 |= v238 != 0;
            }
            v239 = 16 * v219;
            HIDWORD(v197) = &v378.list[v239 / 4];
            HIDWORD(v208) = v239 + v350;
            v240 = v239 + v370;
            *(float *)HIDWORD(v197) = *(float *)(v197 - 8);
            v196 = v356;
            ++v201;
            *(float *)(HIDWORD(v197) + 4) = *(float *)(v197 - 4);
            LODWORD(v208) = v208 + 1;
            *(float *)(HIDWORD(v197) + 8) = *(float *)v197;
            *(float *)(HIDWORD(v197) + 12) = *(float *)(v197 + 4);
            v202 += 4;
            *(float *)(v239 + v350) = *v202;
            HIDWORD(v197) = v370;
            *(float *)(HIDWORD(v208) + 4) = *(float *)((char *)v206 + v200);
            *(float *)(HIDWORD(v208) + 8) = *(float *)(v197 + v198);
            *(float *)(v239 + HIDWORD(v197)) = *(v206 - 1);
            *(float *)(v240 + 4) = *v206;
            v206 += 4;
            *(float *)(v240 + 8) = *(float *)(v197 + v199);
            LODWORD(v197) = v197 + 16;
            --v205;
          }
          while ( v205 != 0 );
          v416 = v216;
          v415 = v218;
          v137 = (signed int)v349;
          v173 = v340;
          v172 = v418;
          v166 = v377.list;
          v159 = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)v379.list;
          v145 = v366;
          v144 = v367;
          v143 = v365;
          v417 = v214;
        }
        v241 = v343;
        if ( v345 > 0 )
        {
          v242 = v345;
          v243 = __PAIR64__((unsigned int)v352, (unsigned int)v408[1]);
          v244 = v351 - 1;
          v350 = (char *)v408[0] - (char *)v408[1];
          v245 = (char *)v364.list - (char *)v352;
          v370 = (char *)v408[2] - (char *)v408[1];
          HIDWORD(v353) = (char *)v408[3] - (char *)v408[1];
          HIDWORD(v369) = (char *)v408[4] - (char *)v408[1];
          v351 = (float *)((char *)v408[6] - (char *)v408[1]);
          v246 = v386;
          v247 = v385;
          v248 = v384;
          v249 = v383;
          v250 = v382;
          v251 = v381;
          v252 = v380;
          v253 = v407;
          v254 = v406;
          v255 = v405;
          v256 = v404;
          v257 = v403;
          v258 = v402;
          v259 = v401;
          v260 = v400;
          HIDWORD(v371) = (char *)v408[5] - (char *)v408[1];
          v352 = (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)(v409 - (unsigned int)v408[1]);
          do
          {
            HIDWORD(v261) = (unsigned __int16)*(_WORD *)HIDWORD(v243);
            LODWORD(v261) = *(__int16 *)(v245 + HIDWORD(v243));
            v262 = v389;
            v354 = v261;
            v159[(_DWORD)v261] = *(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)((char *)&v261 + 2);
            v263 = v354;
            if ( v262 != 0 )
              v264 = *(_BYTE *)(v243 + v350);
            else
              v264 = 0;
            v354 = v243;
            v265 = v390;
            *(_BYTE *)(v263 + LODWORD(v252)) = v264;
            v266 = v354;
            v260 |= v264 != 0;
            if ( v265 != 0 )
              v267 = *(_BYTE *)v354;
            else
              v267 = 0;
            v268 = v391;
            *(_BYTE *)(v263 + LODWORD(v251)) = v267;
            v259 |= v267 != 0;
            if ( v268 != 0 )
              v269 = *(_BYTE *)(v266 + v370);
            else
              v269 = 0;
            v270 = v392;
            *(_BYTE *)(v263 + LODWORD(v250)) = v269;
            v258 |= v269 != 0;
            if ( v270 != 0 )
              v271 = *(_BYTE *)(v266 + HIDWORD(v353));
            else
              v271 = 0;
            v272 = v393;
            *(_BYTE *)(v263 + LODWORD(v249)) = v271;
            v257 |= v271 != 0;
            if ( v272 != 0 )
              v273 = *(_BYTE *)(v266 + HIDWORD(v369));
            else
              v273 = 0;
            v274 = v394;
            *(_BYTE *)(v263 + LODWORD(v248)) = v273;
            v256 |= v273 != 0;
            if ( v274 != 0 )
              v275 = *(_BYTE *)(v266 + HIDWORD(v371));
            else
              v275 = 0;
            v276 = v395;
            *(_BYTE *)(v263 + HIDWORD(v247)) = v275;
            v255 |= v275 != 0;
            if ( v276 != 0 )
              v277 = *((_BYTE *)v351 + v266);
            else
              v277 = 0;
            v278 = v396;
            *(_BYTE *)(v263 + v247) = v277;
            v254 |= v277 != 0;
            if ( v278 != 0 )
              v279 = *((_BYTE *)&v352->value + v266);
            else
              v279 = 0;
            *(_BYTE *)(v263 + LODWORD(v246)) = v279;
            HIDWORD(v243) = HIDWORD(v266) + 2;
            v354 = v247;
            v166 = v377.list;
            LODWORD(v243) = v266 + 1;
            v253 |= v279 != 0;
            v377.list[v263] = *++v244;
            v247 = v354;
            --v242;
          }
          while ( v242 != 0 );
          v405 = v255;
          v404 = v256;
          v403 = v257;
          v402 = v258;
          v400 = v260;
          v143 = v365;
          v144 = v367;
          v145 = v366;
          v172 = v418;
          v173 = v340;
          v137 = (signed int)v349;
          v241 = v343;
          v407 = v253;
          v406 = v254;
          v401 = v259;
        }
        v280 = (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v374.list;
        if ( v137 >= v144 )
        {
          v281 = v376.list;
        }
        else
        {
          v282 = (_BYTE *)(v196 + v137);
          v283 = &v376.list[v137];
          v284 = v144 - v137;
          v281 = v376.list;
          v285 = (char *)(v355 - v196);
          v286 = v357 - v196;
          v287 = v358 - v196;
          v288 = v359 - v196;
          v289 = v360 - v196;
          v290 = v361 - v196;
          v291 = v362 - v196;
          do
          {
            *(unsigned __int16 *)((char *)v283 + (char *)v280 - (char *)v281) = NULL_JOINT.value;
            *v283++ = -1;
            v282[(_DWORD)v285] = 0;
            *v282 = 0;
            v282[v286] = 0;
            v282[v287] = 0;
            v282[v288] = 0;
            v282[v289] = 0;
            v282[v290] = 0;
            (v282++)[v291] = 0;
            --v284;
          }
          while ( v284 != 0 );
        }
        if ( v143 < v145 )
        {
          v292 = &v166[v143 - 1];
          v293 = &v159[v143 - 1];
          v294 = v145 - v143;
          do
          {
            ++v293;
            v293->value = NULL_USERCHANNEL.value;
            *++v292 = 0.0;
            --v294;
          }
          while ( v294 != 0 );
        }
        v295 = 0;
        for ( i1 = 8; i1 != 0; --i1 )
        {
          if ( *(int *)((char *)&v410 + v295) == 0 )
            *(unsigned int *)((char *)&v355 + v295) = 0;
          v295 += 4;
        }
        v297 = 0;
        for ( i2 = 8; i2 != 0; --i2 )
        {
          if ( *(int *)((char *)&v400 + v297) == 0 )
            *(float *)((char *)&v380 + v297) = 0.0;
          v297 += 4;
        }
        v299 = v378.list;
        if ( (unsigned __int8)idMD6Skel::MakeSkeletonData(
                                this,
                                numJoints: v137,
                                basePose: v378.list,
                                jointHandleTbl: v280,
                                parentTbl: (__int16 *)v281,
                                numUserChannels: v143,
                                U: v166,
                                userChannelHandleTbl: v159,
                                jointWeights: v320,
                                userWeights: v321,
                                a11: v322,
                                a12: v323,
                                a13: v324,
                                a14: v325,
                                a15: v326,
                                a16: v327,
                                a17: v328,
                                a18: v329,
                                a19: v330,
                                a20: v331,
                                a21: v332,
                                a22: v333,
                                a23: v334,
                                a24: v335,
                                a25: v336,
                                a26: v337,
                                a27: v338,
                                a28: (const void **)&v355,
                                a29: v339,
                                a30: (const void **)&v380) == 0 )
        {
          if ( v173 != nullptr )
            idMem::Free(this: v241, ptr: v173, align: ALIGN_16);
          if ( v172 != nullptr )
            idMem::Free(this: v241, ptr: v172, align: ALIGN_16);
          if ( (v377.listStatic == 0 || v377.listStatic == 2) && v166 != nullptr )
            idMem::Free(this: v241, ptr: v166, align: ALIGN_16);
          if ( (v378.listStatic == 0 || v378.listStatic == 2) && v299 != nullptr )
            idMem::Free(this: v241, ptr: v299, align: ALIGN_16);
          if ( (v376.listStatic == 0 || v376.listStatic == 2) && v281 != nullptr )
            idMem::Free(this: v241, ptr: v281, align: ALIGN_16);
          if ( (v379.listStatic == 0 || v379.listStatic == 2) && v159 != nullptr )
            idMem::Free(this: v241, ptr: v159, align: ALIGN_16);
          if ( (v374.listStatic == 0 || v374.listStatic == 2) && v280 != nullptr )
            idMem::Free(this: v241, ptr: v280, align: ALIGN_16);
          if ( (v364.listStatic == 0 || v364.listStatic == 2) && v364.list != nullptr )
            idMem::Free(this: v241, ptr: v364.list, align: ALIGN_16);
          if ( (v363.listStatic == 0 || v363.listStatic == 2) && v363.list != nullptr )
            idMem::Free(this: v241, ptr: v363.list, align: ALIGN_16);
          if ( v347.listStatic == 0 || v347.listStatic == 2 )
          {
            v300 = v347.list;
            if ( v347.list != nullptr )
            {
              v301 = v347.size;
              v302 = v347.list;
              if ( v347.size > 0 )
              {
                do
                {
                  idStr::FreeData(this: v300);
                  --v301;
                  ++v300;
                }
                while ( v301 != 0 );
              }
              idMem::Free(this: v241, ptr: v302, align: ALIGN_16);
            }
            v347.list = nullptr;
            v347.size = 0;
          }
          v347.num = 0;
          if ( v348.listStatic == 0 || v348.listStatic == 2 )
          {
            v303 = v348.list;
            if ( v348.list != nullptr )
            {
              v304 = v348.size;
              v305 = v348.list;
              if ( v348.size > 0 )
              {
                do
                {
                  idStr::FreeData(this: v303);
                  --v304;
                  ++v303;
                }
                while ( v304 != 0 );
              }
              idMem::Free(this: v241, ptr: v305, align: ALIGN_16);
            }
            v348.list = nullptr;
            v348.size = 0;
          }
          v348.num = 0;
          if ( v387.buffer != nullptr )
            idMem::Free(this: v241, ptr: v387.buffer, align: ALIGN_16);
          if ( v388.buffer != nullptr )
            idMem::Free(this: v241, ptr: v388.buffer, align: ALIGN_16);
          idParser::~idParser(this: &v421);
          if ( (v372.listStatic == 0 || v372.listStatic == 2) && v372.list != nullptr )
            idMem::Free(this: v241, ptr: v372.list, align: ALIGN_16);
          goto LABEL_476;
        }
        if ( v173 != nullptr )
          idMem::Free(this: v241, ptr: v173, align: ALIGN_16);
        if ( v172 != nullptr )
          idMem::Free(this: v241, ptr: v172, align: ALIGN_16);
        if ( (v377.listStatic == 0 || v377.listStatic == 2) && v166 != nullptr )
          idMem::Free(this: v241, ptr: v166, align: ALIGN_16);
        if ( (v378.listStatic == 0 || v378.listStatic == 2) && v299 != nullptr )
          idMem::Free(this: v241, ptr: v299, align: ALIGN_16);
        if ( (v376.listStatic == 0 || v376.listStatic == 2) && v281 != nullptr )
          idMem::Free(this: v241, ptr: v281, align: ALIGN_16);
        if ( (v379.listStatic == 0 || v379.listStatic == 2) && v159 != nullptr )
          idMem::Free(this: v241, ptr: v159, align: ALIGN_16);
        if ( (v374.listStatic == 0 || v374.listStatic == 2) && v280 != nullptr )
          idMem::Free(this: v241, ptr: v280, align: ALIGN_16);
        if ( (v364.listStatic == 0 || v364.listStatic == 2) && v364.list != nullptr )
          idMem::Free(this: v241, ptr: v364.list, align: ALIGN_16);
        if ( (v363.listStatic == 0 || v363.listStatic == 2) && v363.list != nullptr )
          idMem::Free(this: v343, ptr: v363.list, align: ALIGN_16);
LABEL_447:
        if ( v347.listStatic != 0 && v347.listStatic != 2 )
        {
          v309 = v343;
        }
        else
        {
          v306 = v347.list;
          if ( v347.list != nullptr )
          {
            v307 = v347.size;
            v308 = v347.list;
            if ( v347.size > 0 )
            {
              do
              {
                idStr::FreeData(this: v306);
                --v307;
                ++v306;
              }
              while ( v307 != 0 );
            }
            v309 = v343;
            idMem::Free(this: v343, ptr: v308, align: ALIGN_16);
            v347.list = nullptr;
            v347.size = 0;
          }
          else
          {
            v309 = v343;
            v347.list = nullptr;
            v347.size = 0;
          }
        }
        v347.num = 0;
        if ( v348.listStatic == 0 || v348.listStatic == 2 )
        {
          v316 = v348.list;
          if ( v348.list != nullptr )
          {
            v317 = v348.size;
            v318 = v348.list;
            if ( v348.size > 0 )
            {
              do
              {
                idStr::FreeData(this: v316);
                --v317;
                ++v316;
              }
              while ( v317 != 0 );
            }
            idMem::Free(this: v309, ptr: v318, align: ALIGN_16);
          }
          v348.list = nullptr;
          v348.size = 0;
        }
        v348.num = 0;
        if ( v387.buffer != nullptr )
          idMem::Free(this: v309, ptr: v387.buffer, align: ALIGN_16);
        if ( v388.buffer != nullptr )
          idMem::Free(this: v309, ptr: v388.buffer, align: ALIGN_16);
        idParser::~idParser(this: &v421);
        if ( (v372.listStatic == 0 || v372.listStatic == 2) && v372.list != nullptr )
          idMem::Free(this: v309, ptr: v372.list, align: ALIGN_16);
        idFileLocal::~idFileLocal(this: v346);
        idStr::FreeData(this: &v398);
        idStr::FreeData(this: &v397);
        idStr::FreeData(this: &v375);
        return 1;
      }
      v167 = v377.size;
    }
    v377.num = (v136 + 8) & 0xFFFFFFF8;
    if ( v145 >= v167 )
      v377.num = v167;
    goto LABEL_270;
  }
  v11 = v346[0].file->Length(this: v346[0].file);
  idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v372, newNum: v11 + 1);
  v12 = v372.list;
  if ( v346[0].file->Read(this: v346[0].file, a2: v372.list, a3: v11) == v11 )
  {
    *((_BYTE *)v12 + v11) = 0;
    if ( idParser::LoadMemory(this: &v421, ptr: (const char *)v12, length: v11 + 1, name: v397.data) )
    {
      idParser::ExpectTokenString(this: &v421, string: MD6_VERSION_STRING);
      v13 = idParser::ParseInt(this: &v421);
      if ( v13 != 0 && v13 != 2 )
        idParser::Error(this: &v421, str: "Invalid userchannel version %d.  Should be version %d\n", v13, 2);
      idParser::ExpectTokenString(this: &v421, string: "numUserChannels");
      v6 = idParser::ParseInt(this: &v421);
      v345 = v6;
      goto LABEL_41;
    }
  }
  idParser::~idParser(this: &v421);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v372);
  idFileLocal::~idFileLocal(this: v346);
  idStr::FreeData(this: &v398);
  idStr::FreeData(this: &v397);
  idStr::FreeData(this: &v375);
  return 0;
}


// ========================================================================
// __unwind$230656
// EA  : 0x82859224
// RVA : 0x00859224
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230656()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1648 + 368));
}


// ========================================================================
// __unwind$230657
// EA  : 0x8285924C
// RVA : 0x0085924C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230657()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1648 + 544));
}


// ========================================================================
// __unwind$230658
// EA  : 0x82859274
// RVA : 0x00859274
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230658()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1648 + 576));
}


// ========================================================================
// __unwind$230659
// EA  : 0x8285929C
// RVA : 0x0085929C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230659()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 1648 + 120));
}


// ========================================================================
// __unwind$230660
// EA  : 0x828592C4
// RVA : 0x008592C4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230660()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 304));
}


// ========================================================================
// __unwind$230661
// EA  : 0x828592EC
// RVA : 0x008592EC
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230661()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1648 + 800));
}


// ========================================================================
// __unwind$230662
// EA  : 0x82859314
// RVA : 0x00859314
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230662()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1648 + 504));
}


// ========================================================================
// __unwind$230663
// EA  : 0x8285933C
// RVA : 0x0085933C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230663()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1648 + 496));
}


// ========================================================================
// __unwind$230664
// EA  : 0x82859364
// RVA : 0x00859364
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230664()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1648 + 144));
}


// ========================================================================
// __unwind$230665
// EA  : 0x8285938C
// RVA : 0x0085938C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230665()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1648 + 128));
}


// ========================================================================
// __unwind$230666
// EA  : 0x828593B4
// RVA : 0x008593B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1648 + 768));
}


// ========================================================================
// __unwind$230667
// EA  : 0x828593DC
// RVA : 0x008593DC
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230667()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 224));
}


// ========================================================================
// __unwind$230668
// EA  : 0x82859404
// RVA : 0x00859404
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230668()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 240));
}


// ========================================================================
// __unwind$230669
// EA  : 0x8285942C
// RVA : 0x0085942C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230669()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 352));
}


// ========================================================================
// __unwind$230670
// EA  : 0x82859454
// RVA : 0x00859454
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230670()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 448));
}


// ========================================================================
// __unwind$230671
// EA  : 0x8285947C
// RVA : 0x0085947C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230671()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 400));
}


// ========================================================================
// __unwind$230672
// EA  : 0x828594A4
// RVA : 0x008594A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230672()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 432));
}


// ========================================================================
// __unwind$230673
// EA  : 0x828594CC
// RVA : 0x008594CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230673()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1648 + 416));
}


// ========================================================================
// __unwind$230674
// EA  : 0x828594F4
// RVA : 0x008594F4
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230674()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1648 + 752));
}


// ========================================================================
// __unwind$230675
// EA  : 0x8285951C
// RVA : 0x0085951C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_230675()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1648 + 96));
}


// ========================================================================
// ?LoadSkeletonConfig@idMD6SkeletonConfig@@AAA_NPBD@Z
// EA  : 0x82859550
// RVA : 0x00859550
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6SkeletonConfig::LoadSkeletonConfig(idMD6SkeletonConfig *this, const char *basePath)
{
  idFileList *v4; // r3
  idFileList *v5; // r26
  int num; // r27
  idList<idMD6SkeletonConfig::instance_t,5> *p_instances; // r28
  int v8; // r30
  int v9; // r29
  idMD6SkeletonConfig::instance_t *v10; // r11
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r8
  va *v14; // r3
  int v15; // r5
  const idDeclMD6 *v17; // r3
  int v18; // [sp+8h] [-1388h]
  int v19; // [sp+Ch] [-1384h]
  int v20; // [sp+10h] [-1380h]
  int v21; // [sp+14h] [-137Ch]
  int v22; // [sp+18h] [-1378h]
  int v23; // [sp+1Ch] [-1374h]
  idToken v24; // [sp+50h] [-1340h] BYREF
  idParser v25; // [sp+A0h] [-12F0h] BYREF
  va v26; // [sp+330h] [-1060h] BYREF

  v4 = fileSystem->ListFilesTree(this: fileSystem, a2: basePath, a3: "md6skl", a4: 1);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  num = v4->list.num;
  p_instances = &this->instances;
  idList<idSWFSpriteInstance::swfAction_t,72>::SetNum(
    this: (idList<idSWFSpriteInstance::swfAction_t,72> *)&this->instances,
    newNum: num);
  if ( num > 0 )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      p_instances->list[v8].skeleton = (const idMD6Skel *)idResourceList::Load(
                                                            this: &idMD6Skel::resourceList,
                                                            name: v5->list.list[v9].data,
                                                            makeDefault: false,
                                                            skipStaleCheck: false);
      v10 = &p_instances->list[v8];
      if ( v10->skeleton != nullptr )
        v10->timestamp = v10->skeleton->timestamp;
      else
        v10->timestamp = -1;
      --num;
      ++v9;
      ++v8;
    }
    while ( num != 0 );
  }
  idFileList::~idFileList(this: v5);
  idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  idParser::idParser(this: &v25, flags: 560);
  LODWORD(v11) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v12) = basePath;
  v14 = va::va(
          this: &v26,
          fmt: "%s/.skeletonconfig",
          a3: v12,
          a4: v13,
          a5: v11,
          a6: v18,
          a7: v19,
          a8: v20,
          a9: v21,
          a10: v22,
          a11: v23);
  if ( idParser::LoadFile(this: &v25, filename: v14->buffer, OSPath: false) )
  {
    idParser::ExpectTokenString(this: &v25, string: SKELETONCONFIG_VERSION_STRING);
    v15 = idParser::ParseInt(this: &v25);
    if ( v15 != 2 )
    {
      idParser::Error(this: &v25, str: "Invalid skeleton config version %d. Should be version %d.\n", v15, 2);
      idParser::~idParser(this: &v25);
      return 0;
    }
    v24.len = 0;
    v24.baseBuffer[0] = 0;
    v24.intvalue = 0;
    v24.allocedAndFlag = 20;
    v24.data = v24.baseBuffer;
    memset(&v24.whiteSpaceStart_p, 0, 12);
    v24.floatvalue = -3.4028235e38;
    idParser::ExpectTokenType(this: &v25, type: 1, subtype: 0, token: &v24);
    v17 = (const idDeclMD6 *)idResourceList::Load(
                               this: &idDeclMD6::resourceList,
                               name: v24.data,
                               makeDefault: true,
                               skipStaleCheck: false);
    this->boundsDecl = v17;
    if ( v17 == nullptr )
      idParser::Error(this: &v25, str: "Skeleton config had invalid md6Decl %s. \n", v24.data);
    idStr::FreeData(this: &v24);
  }
  idParser::~idParser(this: &v25);
  return 1;
}


// ========================================================================
// __unwind$233863
// EA  : 0x82859764
// RVA : 0x00859764
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_233863()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5008 + 160));
}


// ========================================================================
// __unwind$233864
// EA  : 0x8285978C
// RVA : 0x0085978C
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_233864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5008 + 80));
}


// ========================================================================
// ?LoadText@idMD6Skel@@AAA_NPBD@Z
// EA  : 0x828597C0
// RVA : 0x008597C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

int __fastcall idMD6Skel::LoadText(idMD6Skel *this, const char *fileName)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // [sp+8h] [-2F8h]
  int v12; // [sp+Ch] [-2F4h]
  int v13; // [sp+10h] [-2F0h]
  int v14; // [sp+14h] [-2ECh]
  int v15; // [sp+18h] [-2E8h]
  int v16; // [sp+1Ch] [-2E4h]
  idParser v17; // [sp+50h] [-2B0h] BYREF

  idParser::idParser(this: &v17, flags: 560);
  if ( idParser::LoadFile(this: &v17, filename: fileName, OSPath: false) )
  {
    if ( (unsigned __int8)idMD6Skel::Parse(this, parser: &v17) != 0 )
    {
      this->timestamp = fileSystem->GetTimestamp(this: fileSystem, a2: fileName, a3: false);
      idParser::~idParser(this: &v17);
      return 1;
    }
    else
    {
      HIDWORD(v10) = fileName;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Failed to load md6skel '%s'.",
        a3: v10,
        a4: v9,
        a5: v8,
        a6: v11,
        a7: v12,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16);
      idParser::~idParser(this: &v17);
      return 0;
    }
  }
  else
  {
    HIDWORD(v6) = fileName;
    idResource::SetResourceError(
      this: &this->idResource,
      fmt: "Failed to open file for md6skel '%s'",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    idParser::~idParser(this: &v17);
    return 0;
  }
}


// ========================================================================
// __unwind$234021
// EA  : 0x82859898
// RVA : 0x00859898
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_234021()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 768 + 80));
}


// ========================================================================
// ?LoadResource@idMD6SkeletonConfig@@UAAXXZ
// EA  : 0x828598C8
// RVA : 0x008598C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall idMD6SkeletonConfig::LoadResource(
        idMD6SkeletonConfig *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  va *v6; // r3
  int v7; // [sp+8h] [-1188h]
  int v8; // [sp+Ch] [-1184h]
  int v9; // [sp+10h] [-1180h]
  int v10; // [sp+14h] [-117Ch]
  int v11; // [sp+18h] [-1178h]
  int v12; // [sp+1Ch] [-1174h]
  idStr v13; // [sp+50h] [-1140h] BYREF
  char v14[256]; // [sp+70h] [-1120h] BYREF
  va v15; // [sp+170h] [-1020h] BYREF

  HIDWORD(a3) = this->name.str;
  v6 = va::va(this: &v15, fmt: "%sskeletonconfig", a3, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  idStr::idStr(this: &v13, text: v6);
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6skeletonconfig",
    a4: this->name.str,
    a5: v14,
    a6: 256);
  if ( (unsigned __int8)idMD6SkeletonConfig::ReadSkeletonConfig_Binary(this, filename: v14) == 0
    && (unsigned __int8)idMD6SkeletonConfig::LoadSkeletonConfig(this, basePath: this->name.str) != 0 )
  {
    idMD6SkeletonConfig::WriteSkeletonConfig_Binary(this, filename: v14);
  }
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$234044_0
// EA  : 0x82859998
// RVA : 0x00859998
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_234044_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 80));
}


// ========================================================================
// ?LoadResource@idMD6Skel@@UAAXXZ
// EA  : 0x828599C8
// RVA : 0x008599C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __fastcall idMD6Skel::LoadResource(idMD6Skel *this)
{
  const void **v2; // r11
  int i; // ctr
  unsigned __int8 **v4; // [sp+8h] [-1B8h]
  unsigned __int8 **v5; // [sp+Ch] [-1B4h]
  int v6; // [sp+10h] [-1B0h]
  int v7; // [sp+14h] [-1ACh]
  int v8; // [sp+18h] [-1A8h]
  int v9; // [sp+1Ch] [-1A4h]
  int v10; // [sp+20h] [-1A0h]
  int v11; // [sp+24h] [-19Ch]
  int v12; // [sp+28h] [-198h]
  int v13; // [sp+2Ch] [-194h]
  int v14; // [sp+30h] [-190h]
  int v15; // [sp+34h] [-18Ch]
  int v16; // [sp+38h] [-188h]
  int v17; // [sp+3Ch] [-184h]
  int v18; // [sp+40h] [-180h]
  int v19; // [sp+44h] [-17Ch]
  int v20; // [sp+48h] [-178h]
  int v21; // [sp+4Ch] [-174h]
  int v22; // [sp+50h] [-170h]
  int v23; // [sp+58h] [-168h]
  idStr v24; // [sp+60h] [-160h] BYREF
  const void *v25[8]; // [sp+80h] [-140h] BYREF
  char v26[288]; // [sp+A0h] [-120h] BYREF

  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6skl", a4: this->name.str, a5: v26, a6: 256);
  if ( (unsigned __int8)idMD6Skel::LoadBinary(this, fileName: v26) == 0 )
  {
    if ( (unsigned __int8)idMD6Skel::LoadText(this, fileName: this->name.str) == 0 )
    {
      v2 = v25;
      v25[0] = nullptr;
      for ( i = 7; i != 0; --i )
        *++v2 = nullptr;
      idMD6Skel::MakeSkeletonData(
        this,
        numJoints: 0,
        basePose: nullptr,
        jointHandleTbl: nullptr,
        parentTbl: nullptr,
        numUserChannels: 0,
        U: nullptr,
        userChannelHandleTbl: nullptr,
        jointWeights: v4,
        userWeights: v5,
        a11: v6,
        a12: v7,
        a13: v8,
        a14: v9,
        a15: v10,
        a16: v11,
        a17: v12,
        a18: v13,
        a19: v14,
        a20: v15,
        a21: v16,
        a22: v17,
        a23: v18,
        a24: v19,
        a25: v20,
        a26: v21,
        a27: v22,
        a28: v25,
        a29: v23,
        a30: v25);
    }
    idMD6Skel::WriteBinary(this, fileName: v26);
  }
  idStr::idStr(this: &v24, text: this->name.str);
  idStr::EnsureAlloced(this: &v24, amount: v24.len + 2, keepold: true, geometricGrowth: true);
  v24.data[v24.len] = 47;
  v24.data[++v24.len] = 0;
  idStr::Append(this: &v24, text: (char *)idMD6Model::DEFAULT_ANIM_NAME);
  this->defaultAnim = (const idMD6Anim *)idResourceList::Load(
                                           this: &idMD6Anim::resourceList,
                                           name: v24.data,
                                           makeDefault: true,
                                           skipStaleCheck: false);
  idStr::FreeData(this: &v24);
}


// ========================================================================
// __unwind$234091
// EA  : 0x82859B24
// RVA : 0x00859B24
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void _unwind_234091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 96));
}


// ========================================================================
// `dynamic initializer for 'idMD6Skel::resourceList''
// EA  : 0x83344498
// RVA : 0x01344498
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idMD6Skel::resourceList__()
{
  idResourceList::idResourceList(this: &idMD6Skel::resourceList, typeName: "skeleton");
  idMD6Skel::resourceList.__vftable = (idTypedResourceList<idMD6Skel>_vtbl *)&idTypedResourceList<idMD6Skel>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idMD6Skel::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'idMD6SkeletonConfig::resourceList''
// EA  : 0x833444E8
// RVA : 0x013444E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6skel.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idMD6SkeletonConfig::resourceList__()
{
  idResourceList::idResourceList(this: &idMD6SkeletonConfig::resourceList, typeName: "skeletonconfig");
  idMD6SkeletonConfig::resourceList.__vftable = (idTypedResourceList<idMD6SkeletonConfig>_vtbl *)&idTypedResourceList<idMD6SkeletonConfig>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idMD6SkeletonConfig::resourceList__);
}

