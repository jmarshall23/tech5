
// ========================================================================
// ?GetJointIndex@idAnimationLocal@@UAAFPBD0@Z
// EA  : 0x82801C70
// RVA : 0x00801C70
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetJointIndex(
        idAnimationLocal *this,
        const char *jointConversion,
        const char *jointName)
{
  _BYTE v6[2]; // [sp+50h] [-20h] BYREF
  _WORD v7[3]; // [sp+52h] [-1Eh] BYREF

  this->FindJointHandle(
    this: (struct idAnimationLocal *)v6,
    result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this,
    a3: jointName);
  this->FindJointConversionHandle(
    this: (struct idAnimationLocal *)v7,
    result: (idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *)this,
    a3: jointConversion);
  return this->GetJointIndex(
           this,
           a2: (idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *)v7[0],
           a3: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v6);
}


// ========================================================================
// ?GetJointIndex@idAnimationLocal@@UBAFV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82801CF8
// RVA : 0x00801CF8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetJointIndex(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *jointConversionHandle,
        const char *jointName)
{
  _BYTE v6[8]; // [sp+50h] [-20h] BYREF

  this->FindJointHandle(
    this: (struct idAnimationLocal *)v6,
    result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this,
    a3: jointName);
  return this->GetJointIndex(
           this,
           a2: jointConversionHandle,
           a3: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v6);
}


// ========================================================================
// ?GetUserChannelIndex@idAnimationLocal@@UAAFPBD0@Z
// EA  : 0x82801D60
// RVA : 0x00801D60
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetUserChannelIndex(
        idAnimationLocal *this,
        const char *jointConversion,
        const char *userChannelName)
{
  _BYTE v6[2]; // [sp+50h] [-20h] BYREF
  _WORD v7[3]; // [sp+52h] [-1Eh] BYREF

  this->FindUserChannelHandle(
    this: (struct idAnimationLocal *)v6,
    result: (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)this,
    a3: userChannelName);
  this->FindJointConversionHandle(
    this: (struct idAnimationLocal *)v7,
    result: (idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *)this,
    a3: jointConversion);
  return this->GetUserChannelIndex(
           this,
           a2: (idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *)v7[0],
           a3: (const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)v6);
}


// ========================================================================
// ?GetUserChannelIndex@idAnimationLocal@@UBAFV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82801DE8
// RVA : 0x00801DE8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetUserChannelIndex(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *jointConversionHandle,
        const char *userChannelName)
{
  _BYTE v6[8]; // [sp+50h] [-20h] BYREF

  this->FindUserChannelHandle(
    this: (struct idAnimationLocal *)v6,
    result: (idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)this,
    a3: userChannelName);
  return this->GetUserChannelIndex(
           this,
           a2: jointConversionHandle,
           a3: (const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)v6);
}


// ========================================================================
// ?anim_listWeakRefs_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82801E50
// RVA : 0x00801E50
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_listWeakRefs_f(const idCmdArgs *args)
{
  idLib::Printf(fmt: "^1IMPLEMENT ME\n");
}


// ========================================================================
// ?IsJointConversionEqual@@YA_NPBVidMD6Skel@@0@Z
// EA  : 0x82801F80
// RVA : 0x00801F80
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

BOOL __fastcall IsJointConversionEqual(const idMD6Skel *_pS1, const idMD6Skel *_pS2)
{
  int value; // r10

  value = _pS1->jointConversion.value;
  if ( value == 0xFFFF || _pS2->jointConversion.value == 0xFFFF )
    return (_cntlzw((-65535 - ((_pS2->jointConversion.value == 0xFFFF) - 0x10000)) ^ (-65535
                                                                                    - ((value == 0xFFFF)
                                                                                     - 0x10000)))
          & 0x20) != 0;
  else
    return (_cntlzw(_pS2->jointConversionChecksum.value - _pS1->jointConversionChecksum.value) & 0x20) != 0;
}


// ========================================================================
// ?StrongLoadAlias@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBVidDeclMD6@@PBD@Z
// EA  : 0x82801FF0
// RVA : 0x00801FF0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::StrongLoadAlias(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const idDeclMD6 *decl,
        const char *aliasName)
{
  idAnimationLocal *v4; // r29
  _WORD v8[24]; // [sp+50h] [-30h] BYREF

  v4 = this;
  if ( decl != nullptr )
  {
    (*(void (__fastcall **)(_WORD *, idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, const idDeclMD6 *))(*(_DWORD *)&result->value + 96))(
      a1: v8,
      a2: result,
      a3: decl);
    (*(void (__fastcall **)(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, const idDeclMD6 *, _WORD *))(*(_DWORD *)&result->value + 128))(
      a1: result,
      a2: decl,
      a3: v8);
    HIWORD(v4->__vftable) = v8[0];
    return v4;
  }
  else
  {
    HIWORD(this->__vftable) = -1;
  }
  return this;
}


// ========================================================================
// ?ReloadIfStale@idJointConversion@@UAA_NXZ
// EA  : 0x82802070
// RVA : 0x00802070
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idJointConversion::ReloadIfStale(idJointConversion *this)
{
  int v3; // r11
  int v4; // r10
  int v5; // r10
  int v6; // r11
  _BYTE v7[264]; // [sp+50h] [-120h] BYREF

  if ( fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->timestamp )
    return 0;
  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6jointconversion",
    a4: this->name.str,
    a5: v7,
    a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v7, a3: FSPATH_BASE);
  v3 = 0;
  if ( this->tableJoints.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      this->tableJoints.list[v4++] = NULL_JOINT;
    }
    while ( v3 < this->tableJoints.num );
  }
  v5 = 0;
  if ( this->tableUserChannels.num > 0 )
  {
    v6 = 0;
    do
    {
      ++v5;
      this->tableUserChannels.list[v6++] = NULL_USERCHANNEL;
    }
    while ( v5 < this->tableUserChannels.num );
  }
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?GetResourceList@idJointResource@@UBAPAVidResourceList@@XZ
// EA  : 0x828021B0
// RVA : 0x008021B0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idTypedResourceList<idJointResource> *__fastcall idJointResource::GetResourceList(idJointResource *this)
{
  return &idJointResource::resourceList;
}


// ========================================================================
// ?VerifyAnimations@idAnimationLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x828025D8
// RVA : 0x008025D8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::VerifyAnimations(const idCmdArgs *args)
{
  double v2; // fp30
  double v3; // fp31
  long double v4; // fp2
  long double v5; // fp2
  int v6; // r24
  idAnimationLocal *v7; // r25
  int v8; // r26
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v9; // r27
  const idAliasGroup *ptr; // r29
  int v11; // r28
  int v12; // r30
  const idDeclMD6 *v13; // r31
  idMD6Anim *v14; // r3

  v2 = 0.1;
  v3 = 1.0;
  if ( args->argc > 1 )
  {
    v4 = atof(nptr: args->argv[1]);
    v2 = (float)*(double *)&v4;
  }
  if ( args->argc > 2 )
  {
    v5 = atof(nptr: args->argv[2]);
    v3 = (float)*(double *)&v5;
  }
  v6 = 0;
  v7 = (idAnimationLocal *)animation;
  if ( (int)animation[0xE].randomNumberGenerator.seed > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &v7->aliasHash.list.list[v8];
      if ( v9 != nullptr )
      {
        ptr = v9->ptr;
        if ( v9->ptr != nullptr )
        {
          v11 = 0;
          if ( ptr->declRefs.num > 0 )
          {
            v12 = 0;
            do
            {
              v13 = ptr->declRefs.list[v12];
              if ( v13 != nullptr )
              {
                v14 = idDeclMD6::AnimForAlias(this: ptr->declRefs.list[v12], aliasHandle: &v9->handle, load: false);
                if ( v14 != nullptr )
                  idMD6Anim::VerifyBoundingBoxes(this: v14, decl: v13, epsilon: v2, jointradius: v3);
              }
              ++v11;
              ++v12;
            }
            while ( v11 < ptr->declRefs.num );
          }
        }
      }
      ++v6;
      ++v8;
    }
    while ( v6 < v7->aliasHash.list.num );
  }
}


// ========================================================================
// ?GenerateChecksum@idJointConversion@@AAAXXZ
// EA  : 0x828026F8
// RVA : 0x008026F8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idJointConversion::GenerateChecksum(idJointConversion *this)
{
  int v2; // r29
  int v3; // r28
  const char *v4; // r3
  int v5; // r29
  int v6; // r28
  const char *v7; // r3
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> v8; // [sp+50h] [-80h] BYREF
  _WORD v9[7]; // [sp+52h] [-7Eh] BYREF
  idStr v10; // [sp+60h] [-70h] BYREF
  idStr v11[2]; // [sp+80h] [-50h] BYREF

  idAnimator_TrackerBase::GetReferenceJointOverride(this: &v8);
  v2 = 0;
  if ( this->tableJoints.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( this->tableJoints.list[v3].value != 0xFFFF )
      {
        *(_DWORD *)&v9[1] = &this->tableJoints.list[v3];
        v4 = (const char *)((int (__fastcall *)(idAnimation *))animation->GetJointName)(a1: animation);
        idStr::idStr(this: &v10, text: v4);
        CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v8, data: v10.data, length: v10.len);
        v9[0] = v2;
        CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v8, data: v9, length: 2);
        idStr::FreeData(this: &v10);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->tableJoints.num );
  }
  v5 = 0;
  if ( this->tableUserChannels.num > 0 )
  {
    v6 = 0;
    do
    {
      if ( this->tableUserChannels.list[v6].value != 0xFFFF )
      {
        *(_DWORD *)&v9[1] = &this->tableUserChannels.list[v6];
        v7 = (const char *)((int (__fastcall *)(idAnimation *))animation->GetUserChannelName)(a1: animation);
        idStr::idStr(this: v11, text: v7);
        CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v8, data: v11[0].data, length: v11[0].len);
        v9[0] = v5;
        CRC16_UpdateChecksum(crcvalue: (unsigned __int16 *)&v8, data: v9, length: 2);
        idStr::FreeData(this: v11);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->tableUserChannels.num );
  }
  this->checksum.value = v8.value;
}


// ========================================================================
// __unwind$229858
// EA  : 0x82802840
// RVA : 0x00802840
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_229858()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$229859
// EA  : 0x82802868
// RVA : 0x00802868
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_229859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?LoadJointConversion_Text@idJointConversion@@AAA_NXZ
// EA  : 0x82802898
// RVA : 0x00802898
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idJointConversion::LoadJointConversion_Text(idJointConversion *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  idFile *v5; // r3
  unsigned int v7; // r3
  idFile *file; // r11
  int v9; // r30
  idFile_vtbl *v10; // r26
  unsigned int v11; // r3
  char *buffer; // r24
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  int v19; // r5
  int v20; // r3
  unsigned int v21; // r30
  int i; // r10
  __int16 value; // r11
  int v24; // r3
  unsigned int v25; // r30
  int j; // r10
  __int16 v27; // r11
  int v28; // [sp+8h] [-398h]
  int v29; // [sp+Ch] [-394h]
  int v30; // [sp+10h] [-390h]
  int v31; // [sp+14h] [-38Ch]
  int v32; // [sp+18h] [-388h]
  int v33; // [sp+1Ch] [-384h]
  idFileLocal v34; // [sp+50h] [-350h] BYREF
  unsigned __int16 v35; // [sp+54h] [-34Ch] BYREF
  unsigned __int16 v36[5]; // [sp+56h] [-34Ah] BYREF
  idToken v37; // [sp+60h] [-340h] BYREF
  idTempArray<char> v38; // [sp+A8h] [-2F8h] BYREF
  idParser v39; // [sp+B0h] [-2F0h] BYREF

  v5 = fileSystem->OpenFileRead(this: fileSystem, a2: this->name.str, a3: 1, a4: 0);
  v34.file = v5;
  if ( v5 == nullptr )
  {
    HIDWORD(v4) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "Failed to open file for jointconversion '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v28,
      a7: v29,
      a8: v30,
      a9: v31,
      a10: v32,
      a11: v33);
    idFileLocal::~idFileLocal(this: &v34);
    return 0;
  }
  v7 = v5->Timestamp(this: v5);
  file = v34.file;
  this->timestamp = v7;
  v9 = file->Length(this: file);
  idTempArray<char>::idTempArray<char>(this: &v38, num: v9 + 1);
  v10 = v34.file->__vftable;
  v11 = v34.file->Length(this: v34.file);
  buffer = v38.buffer;
  if ( v10->Read(this: v34.file, a2: v38.buffer, a3: v11) != v9 )
  {
    HIDWORD(v15) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "Failed to read file for jointconversion '%s'",
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v28,
      a7: v29,
      a8: v30,
      a9: v31,
      a10: v32,
      a11: v33);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
LABEL_6:
    idFileLocal::~idFileLocal(this: &v34);
    return 0;
  }
  buffer[v9] = 0;
  idParser::idParser(this: &v39, flags: 262704);
  if ( !idParser::LoadMemory(this: &v39, ptr: buffer, length: v9 + 1, name: this->name.str) )
  {
    HIDWORD(v18) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "Error parsing file for jointconversion '%s'",
      a3: v18,
      a4: v17,
      a5: v16,
      a6: v28,
      a7: v29,
      a8: v30,
      a9: v31,
      a10: v32,
      a11: v33);
    idParser::~idParser(this: &v39);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    goto LABEL_6;
  }
  v37.len = 0;
  v37.baseBuffer[0] = 0;
  v37.intvalue = 0;
  v37.allocedAndFlag = 20;
  v37.data = v37.baseBuffer;
  memset(&v37.whiteSpaceStart_p, 0, 12);
  v37.floatvalue = -3.4028235e38;
  idParser::ExpectTokenString(this: &v39, string: "MD6JointConversionVersion");
  v19 = idParser::ParseInt(this: &v39);
  if ( v19 != 2 )
    idParser::Error(this: &v39, str: "MD6 Jointconversion has an invalid version %d should be %d.", v19, 2);
  idParser::ExpectTokenString(this: &v39, string: "jointConversion");
  idParser::ExpectTokenType(this: &v39, type: 5, subtype: 46, token: &v37);
  while ( idParser::ReadToken(this: &v39, token: &v37) && (v37.type != 5 || v37.subtype != 47) )
  {
    ((void (__fastcall *)(unsigned __int16 *))animation->RegisterJoint)(a1: &v35);
    v20 = idParser::ParseInt(this: &v39);
    v21 = v20;
    if ( v35 != 0xFFFF )
    {
      for ( i = 0; i < 256; ++i )
      {
        if ( this->tableJoints.list[i].value == v35 )
        {
          value = NULL_JOINT_INDEX.value;
          goto LABEL_24;
        }
      }
    }
    value = NULL_JOINT_INDEX.value;
    LOWORD(i) = NULL_JOINT_INDEX;
LABEL_24:
    if ( (__int16)i != value && (__int16)i != v20 )
      idParser::Error(
        this: &v39,
        str: "MD6 Jointconversion: Jointhandle already specified with different joint index: %s:%d.",
        v37.data,
        v20);
    if ( v21 >= 0x100 )
      idParser::Error(this: &v39, str: "MD6 Jointconversion has invalid joint index: %d for %s.", v21, v37.data);
    else
      this->tableJoints.list[v21].value = v35;
  }
  idParser::ExpectTokenString(this: &v39, string: "userChannelConversion");
  idParser::ExpectTokenType(this: &v39, type: 5, subtype: 46, token: &v37);
  while ( idParser::ReadToken(this: &v39, token: &v37) && (v37.type != 5 || v37.subtype != 47) )
  {
    ((void (__fastcall *)(unsigned __int16 *))animation->RegisterUserChannel)(a1: v36);
    v24 = idParser::ParseInt(this: &v39);
    v25 = v24;
    if ( v36[0] != 0xFFFF )
    {
      for ( j = 0; j < 256; ++j )
      {
        if ( this->tableUserChannels.list[j].value == v36[0] )
        {
          v27 = NULL_USERCHANNEL_INDEX.value;
          goto LABEL_41;
        }
      }
    }
    v27 = NULL_USERCHANNEL_INDEX.value;
    LOWORD(j) = NULL_USERCHANNEL_INDEX;
LABEL_41:
    if ( (__int16)j != v27 && (__int16)j != v24 )
      idParser::Error(
        this: &v39,
        str: "MD6 Jointconversion: UserChannelhandle already specified with different joint index: %s:%d.",
        v37.data,
        v24);
    if ( v25 >= 0x100 )
      idParser::Error(this: &v39, str: "MD6 Jointconversion has invalid joint index: %d for %s.", v25, v37.data);
    else
      this->tableUserChannels.list[v25].value = v36[0];
  }
  idJointConversion::GenerateChecksum(this);
  idStr::FreeData(this: &v37);
  idParser::~idParser(this: &v39);
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  idFileLocal::~idFileLocal(this: &v34);
  return 1;
}


// ========================================================================
// $M230285
// EA  : 0x82802DE8
// RVA : 0x00802DE8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int _M230285()
{
  idLib::Error(fmt: "idJointConversion::LoadJointConversion_Text - %s", idException::error);
  return _LN238();
}


// ========================================================================
// $LN238
// EA  : 0x82802E08
// RVA : 0x00802E08
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _LN238()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 928 + 80));
}


// ========================================================================
// __unwind$229952
// EA  : 0x82802E30
// RVA : 0x00802E30
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_229952()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 928 + 168));
}


// ========================================================================
// __unwind$229953
// EA  : 0x82802E58
// RVA : 0x00802E58
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_229953()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 928 + 176));
}


// ========================================================================
// __unwind$229954
// EA  : 0x82802E80
// RVA : 0x00802E80
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_229954()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 928 + 96));
}


// ========================================================================
// ?WriteJointConversion_Binary@idJointConversion@@AAA_NPBD@Z
// EA  : 0x82802EB0
// RVA : 0x00802EB0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idJointConversion::WriteJointConversion_Binary(idJointConversion *this, const char *filename)
{
  idFile *v4; // r3
  int v6; // r28
  int v7; // r29
  const char *v8; // r4
  idFile *file; // r3
  int v10; // r28
  int v11; // r29
  const char *v12; // r4
  idFile *v13; // r3
  idFileLocal v14; // [sp+50h] [-50h] BYREF
  int num; // [sp+54h] [-4Ch] BYREF
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v16; // [sp+58h] [-48h]

  v4 = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  v14.file = v4;
  if ( v4 != nullptr )
  {
    v4->Write(this: v4, a2: &MD6_JOINTCONVERSION_MAGIC, a3: 4u);
    v14.file->Write(this: v14.file, a2: &this->timestamp, a3: 4u);
    v14.file->Write(this: v14.file, a2: &this->checksum, a3: 2u);
    num = this->tableJoints.num;
    v14.file->Write(this: v14.file, a2: &num, a3: 4u);
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        if ( this->tableJoints.list[v7].value == 0xFFFF )
        {
          file = v14.file;
          v8 = &byte_8200D768;
        }
        else
        {
          v16 = &this->tableJoints.list[v7];
          v8 = (const char *)((int (__fastcall *)(idAnimation *))animation->GetJointName)(a1: animation);
          file = v14.file;
        }
        idFile::WriteString(this: file, string: v8);
        ++v6;
        ++v7;
      }
      while ( v6 < num );
    }
    num = this->tableUserChannels.num;
    v14.file->Write(this: v14.file, a2: &num, a3: 4u);
    v10 = 0;
    if ( num > 0 )
    {
      v11 = 0;
      do
      {
        if ( this->tableUserChannels.list[v11].value == 0xFFFF )
        {
          v13 = v14.file;
          v12 = &byte_8200D768;
        }
        else
        {
          v16 = (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)&this->tableUserChannels.list[v11];
          v12 = (const char *)((int (__fastcall *)(idAnimation *))animation->GetUserChannelName)(a1: animation);
          v13 = v14.file;
        }
        idFile::WriteString(this: v13, string: v12);
        ++v10;
        ++v11;
      }
      while ( v10 < num );
    }
    idFileLocal::~idFileLocal(this: &v14);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Could not write '%s'", filename);
    idFileLocal::~idFileLocal(this: &v14);
    return 0;
  }
}


// ========================================================================
// __unwind$230314
// EA  : 0x828030AC
// RVA : 0x008030AC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230314()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 160 + 80));
}


// ========================================================================
// ?anim_checkVersions_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828030E0
// RVA : 0x008030E0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_checkVersions_f(const idCmdArgs *args)
{
  const char *v1; // r30
  idFileList *v2; // r27
  int v3; // r17
  int i; // r19
  int v5; // r29
  int v6; // r5
  int v7; // r5
  idStr v8; // [sp+60h] [-1C0h] BYREF
  idToken v9; // [sp+80h] [-1A0h] BYREF
  idStr v10; // [sp+D0h] [-150h] BYREF
  idStr v11; // [sp+F0h] [-130h] BYREF
  idLexer v12[2]; // [sp+110h] [-110h] BYREF

  if ( args->argc <= 1 )
    v1 = "md6";
  else
    v1 = args->argv[1];
  idStr::idStr(this: &v10, text: ".md6mesh|.md6anim");
  v2 = fileSystem->ListFilesTree(this: fileSystem, a2: v1, a3: v10.data, a4: 0);
  v3 = 0;
  if ( v2 != nullptr )
  {
    common->SetRefreshOnPrint(this: common, a2: true);
    v9.len = 0;
    v9.baseBuffer[0] = 0;
    v9.intvalue = 0;
    v9.data = v9.baseBuffer;
    v9.allocedAndFlag = 20;
    memset(&v9.whiteSpaceStart_p, 0, 12);
    v9.floatvalue = -3.4028235e38;
    for ( i = 0; ; ++i )
    {
      while ( 1 )
      {
        if ( i >= v2->list.num )
        {
          fileSystem->FreeFileList(this: fileSystem, a2: v2);
          common->SetRefreshOnPrint(this: common, a2: false);
          idStr::FreeData(this: &v9);
          goto LABEL_20;
        }
        idLexer::idLexer(this: v12, flags_: 262704);
        v5 = i;
        if ( idLexer::LoadFile(this: v12, filename_: v2->list.list[i].data, OSPath: false) )
          break;
        idLib::Warning(fmt: "Failed to open file '%s'", v2->list.list[v5].data);
        idLexer::~idLexer(this: v12);
        ++i;
      }
      idLexer::ReadToken(this: v12, token: &v9);
      if ( idStr::Icmp(s1: v9.data, s2: MD6_VERSION_STRING) != 0 )
        idLexer::Error(this: v12, str: "Invalid animation asset tag. Expected '%s'", MD6_VERSION_STRING);
      idStr::idStr(this: &v11, text: v2->list.list[v5].data);
      v8.len = 0;
      v8.baseBuffer[0] = 0;
      v8.data = v8.baseBuffer;
      v8.allocedAndFlag = 20;
      idStr::ExtractFileExtension(this: &v11, dest: &v8);
      if ( idStr::Cmp(s1: v8.data, s2: "md6mesh") == 0 )
        break;
      if ( idStr::Cmp(s1: v8.data, s2: "md6anim") == 0 )
      {
        v7 = idLexer::ParseInt(this: v12);
        if ( v7 != 7 )
        {
          idLib::Printf(fmt: "Anim '%s' is old version %d.\n", v2->list.list[v5].data, v7);
LABEL_16:
          ++v3;
        }
      }
_M230706:
      idStr::FreeData(this: &v8);
      idStr::FreeData(this: &v11);
      idLexer::~idLexer(this: v12);
    }
    v6 = idLexer::ParseInt(this: v12);
    if ( v6 == 5 )
      goto _M230706;
    idLib::Printf(fmt: "Mesh '%s' is old version %d.\n", v2->list.list[v5].data, v6);
    goto LABEL_16;
  }
LABEL_20:
  idLib::Printf(fmt: "Found %d animation assets with old versions.\n", v3);
  idStr::FreeData(this: &v10);
}


// ========================================================================
// $M230724
// EA  : 0x8280346C
// RVA : 0x0080346C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M230724()
{
  return &_M230711;
}


// ========================================================================
// __unwind$230447
// EA  : 0x82803480
// RVA : 0x00803480
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230447()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 208));
}


// ========================================================================
// __unwind$230448
// EA  : 0x828034A8
// RVA : 0x008034A8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230448()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 128));
}


// ========================================================================
// __unwind$230449
// EA  : 0x828034D0
// RVA : 0x008034D0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230449()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 544 + 272));
}


// ========================================================================
// __unwind$230450
// EA  : 0x828034F8
// RVA : 0x008034F8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230450()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$230451
// EA  : 0x82803520
// RVA : 0x00803520
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_230451()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 96));
}


// ========================================================================
// ??1idJointConversion@@UAA@XZ
// EA  : 0x82803CB0
// RVA : 0x00803CB0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idJointConversion::~idJointConversion(idJointConversion *this)
{
  this->__vftable = (idJointConversion_vtbl *)&idJointConversion::`vftable';
  animation->UnregisterJointConversion(this: animation, a2: this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableUserChannels);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableJoints);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$232306
// EA  : 0x82803D28
// RVA : 0x00803D28
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_232306()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$232307
// EA  : 0x82803D50
// RVA : 0x00803D50
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_232307()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$232308
// EA  : 0x82803D7C
// RVA : 0x00803D7C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_232308()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// ?GetResourceList@idJointConversion@@UBAPAVidResourceList@@XZ
// EA  : 0x82803DA8
// RVA : 0x00803DA8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idTypedResourceList<idJointConversion> *__fastcall idJointConversion::GetResourceList(idJointConversion *this)
{
  return &idJointConversion::resourceList;
}


// ========================================================================
// ?GetResourceTypeName@idJointConversion@@UBAPBDXZ
// EA  : 0x82803DB8
// RVA : 0x00803DB8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

const char *__fastcall idJointConversion::GetResourceTypeName(idJointConversion *this)
{
  return "jointconversion";
}


// ========================================================================
// ?Initialize@idAnimationLocal@@UAAXXZ
// EA  : 0x82803E28
// RVA : 0x00803E28
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::Initialize(idAnimationLocal *this)
{
  idAnimationLocal_vtbl *v1; // r30
  const char *v3; // r3
  char v4; // [sp+50h] [-20h] BYREF

  v1 = this->__vftable;
  v3 = this->GetOriginJointName(this);
  this->originJointHandle.value = v1->RegisterJoint(
                                    this: (struct idAnimationLocal *)&v4,
                                    result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this,
                                    a3: v3)->value;
  this->randomNumberGenerator.seed = Sys_Milliseconds();
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "verifyAnimations",
    a3: idAnimationLocal::VerifyAnimations,
    a4: "Verifies that animations are within their bboxes",
    a5: nullptr);
}


// ========================================================================
// ?GetJointName@idAnimationLocal@@UBAPBDABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@@Z
// EA  : 0x82803EC8
// RVA : 0x00803EC8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

char *__fastcall idAnimationLocal::GetJointName(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidJointHandle_t,65535> *handle)
{
  int value; // r11

  value = handle->value;
  if ( value == 0xFFFF || value >= this->jointHash.list.num )
    return nullptr;
  else
    return this->jointHash.list.list[value].name.data;
}


// ========================================================================
// ?GetJointConversionName@idAnimationLocal@@UBAPBDABV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@@Z
// EA  : 0x82803F08
// RVA : 0x00803F08
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

char *__fastcall idAnimationLocal::GetJointConversionName(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *handle)
{
  int value; // r11

  value = handle->value;
  if ( value == 0xFFFF || value >= this->jointConversionHash.list.num )
    return nullptr;
  else
    return this->jointConversionHash.list.list[value].name.data;
}


// ========================================================================
// ?GetJointConversionCrc@idAnimationLocal@@UBA?AV?$idHandle@GW4invalidCrc_t@@$0PPPP@@@V?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@@Z
// EA  : 0x82803F48
// RVA : 0x00803F48
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::GetJointConversionCrc(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidCrc_t,65535> *result,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *jointConversionHandle)
{
  int *v3; // r11
  int v4; // r11

  if ( (unsigned __int16)jointConversionHandle != 0xFFFF
    && (unsigned __int16)jointConversionHandle < *(int *)&result[84].value
    && (v3 = (int *)(52 * (unsigned __int16)jointConversionHandle + *(_DWORD *)&result[82].value)) != nullptr
    && (v4 = *v3) != 0 )
  {
    HIWORD(this->__vftable) = *(_WORD *)(v4 + 72);
  }
  else
  {
    HIWORD(this->__vftable) = -1;
  }
  return this;
}


// ========================================================================
// ?GetJointIndex@idAnimationLocal@@UBAFV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@ABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@@Z
// EA  : 0x82803FA0
// RVA : 0x00803FA0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetJointIndex(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *jointConversionHandle,
        const idHandle<unsigned short,enum invalidJointHandle_t,65535> *handle)
{
  int value; // r8
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v4; // r11
  const idJointConversion *ptr; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *list; // r9
  __int16 v7; // r10
  int v8; // r11

  value = handle->value;
  if ( value == 0xFFFF )
    return (unsigned __int16)NULL_JOINT_INDEX.value;
  if ( (unsigned __int16)jointConversionHandle == 0xFFFF )
    return (unsigned __int16)NULL_JOINT_INDEX.value;
  if ( (unsigned __int16)jointConversionHandle >= this->jointConversionHash.list.num )
    return (unsigned __int16)NULL_JOINT_INDEX.value;
  v4 = &this->jointConversionHash.list.list[(unsigned __int16)jointConversionHandle];
  if ( v4 == nullptr )
    return (unsigned __int16)NULL_JOINT_INDEX.value;
  ptr = v4->ptr;
  if ( ptr == nullptr )
    return (unsigned __int16)NULL_JOINT_INDEX.value;
  list = ptr->tableJoints.list;
  v7 = 0;
  v8 = 0;
  while ( list[v8].value != value )
  {
    ++v8;
    ++v7;
    if ( v8 >= 256 )
      return (unsigned __int16)NULL_JOINT_INDEX.value;
  }
  return v7;
}


// ========================================================================
// ?GetUserChannelName@idAnimationLocal@@UBAPBDABV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@@Z
// EA  : 0x82804028
// RVA : 0x00804028
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

char *__fastcall idAnimationLocal::GetUserChannelName(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *handle)
{
  int value; // r11

  value = handle->value;
  if ( value == 0xFFFF || value >= this->userChannelHash.list.num )
    return nullptr;
  else
    return this->userChannelHash.list.list[value].name.data;
}


// ========================================================================
// ?GetUserChannelIndex@idAnimationLocal@@UBAFV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@ABV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@@Z
// EA  : 0x82804068
// RVA : 0x00804068
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idAnimationLocal::GetUserChannelIndex(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *jointConversionHandle,
        const idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *handle)
{
  int value; // r8
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v4; // r11
  const idJointConversion *ptr; // r11
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *list; // r9
  __int16 v7; // r10
  int v8; // r11

  value = handle->value;
  if ( value == 0xFFFF )
    return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  if ( (unsigned __int16)jointConversionHandle == 0xFFFF )
    return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  if ( (unsigned __int16)jointConversionHandle >= this->jointConversionHash.list.num )
    return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  v4 = &this->jointConversionHash.list.list[(unsigned __int16)jointConversionHandle];
  if ( v4 == nullptr )
    return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  ptr = v4->ptr;
  if ( ptr == nullptr )
    return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  list = ptr->tableUserChannels.list;
  v7 = 0;
  v8 = 0;
  while ( list[v8].value != value )
  {
    ++v8;
    ++v7;
    if ( v8 >= 256 )
      return (unsigned __int16)NULL_USERCHANNEL_INDEX.value;
  }
  return v7;
}


// ========================================================================
// ?UnregisterJointConversion@idAnimationLocal@@UAAXPAVidJointConversion@@@Z
// EA  : 0x828040F0
// RVA : 0x008040F0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::UnregisterJointConversion(idAnimationLocal *this, idJointConversion *jointConversion)
{
  int value; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v3; // r11

  value = jointConversion->handle.value;
  if ( value != 0xFFFF && value < this->jointConversionHash.list.num )
  {
    v3 = &this->jointConversionHash.list.list[value];
    if ( v3->ptr != nullptr )
    {
      v3->ptr = nullptr;
      v3->parent = nullptr;
      v3->refType = REF_FREED;
    }
  }
}


// ========================================================================
// ?FindAliasName@idAnimationLocal@@UBAPBDABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x82804140
// RVA : 0x00804140
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

char *__fastcall idAnimationLocal::FindAliasName(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handle)
{
  int value; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v3; // r11

  value = handle->value;
  if ( value != 0xFFFF && value < this->aliasHash.list.num && (v3 = &this->aliasHash.list.list[value]) != nullptr )
    return v3->name.data;
  else
    return nullptr;
}


// ========================================================================
// ?FinalizeAliasRefs@idAnimationLocal@@AAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x82804180
// RVA : 0x00804180
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::FinalizeAliasRefs(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handle)
{
  int value; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v4; // r25
  const idAliasGroup *ptr; // r11
  int v6; // r26
  int v7; // r28
  idDeclMD6 *v8; // r3
  const idMD6Alias *Alias; // r3
  const idMD6Alias *v10; // r29
  int v11; // r30
  int v12; // r31

  value = handle->value;
  if ( value != 0xFFFF && value < this->aliasHash.list.num )
  {
    v4 = &this->aliasHash.list.list[value];
    if ( v4 != nullptr )
    {
      ptr = v4->ptr;
      if ( v4->ptr != nullptr )
      {
        v6 = 0;
        if ( ptr->declRefs.num > 0 )
        {
          v7 = 0;
          do
          {
            v8 = ptr->declRefs.list[v7];
            if ( v8 != nullptr )
            {
              Alias = idDeclMD6::FindAlias(this: v8, aliasHandle: handle, includeInherited: true);
              v10 = Alias;
              if ( Alias != nullptr )
              {
                v11 = 0;
                if ( Alias->animRefs.num > 0 )
                {
                  v12 = 0;
                  do
                  {
                    idResourceList::Load(
                      this: &idMD6Anim::resourceList,
                      name: (char *)v10->animRefs.list[v12].str,
                      makeDefault: true,
                      skipStaleCheck: false);
                    ++v11;
                    ++v12;
                  }
                  while ( v11 < v10->animRefs.num );
                }
              }
            }
            ptr = v4->ptr;
            ++v6;
            ++v7;
          }
          while ( v6 < v4->ptr->declRefs.num );
        }
      }
    }
  }
}


// ========================================================================
// ?FindJointHandle@idAnimationLocal@@UBA?AV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82804750
// RVA : 0x00804750
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::FindJointHandle(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *result,
        const char *name)
{
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
    (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)this,
    result: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[4],
    typeId: JOINTCONVERSION_ANY,
    name);
  return this;
}


// ========================================================================
// ?FindUserChannelHandle@idAnimationLocal@@UBA?AV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82804790
// RVA : 0x00804790
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::FindUserChannelHandle(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *result,
        const char *name)
{
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
    (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)this,
    result: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[30],
    typeId: JOINTCONVERSION_ANY,
    name);
  return this;
}


// ========================================================================
// ?FindAliasHandle@idAnimationLocal@@UBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x828047D0
// RVA : 0x008047D0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::FindAliasHandle(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const char *aliasName)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v3; // r31
  int v5; // r3
  __int16 v6; // r11
  int v8; // [sp+50h] [-20h] BYREF

  v3 = result + 56;
  v5 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
         this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[56],
         typeId: JOINTCONVERSION_ANY,
         name: aliasName,
         key: &v8);
  if ( v5 >= 0 && 52 * v5 + *(_DWORD *)&v3->value != 0 )
    v6 = *(_WORD *)(52 * v5 + *(_DWORD *)&v3->value + 44);
  else
    v6 = -1;
  HIWORD(this->__vftable) = v6;
  return this;
}


// ========================================================================
// ?FindAliasHandle@idAnimationLocal@@UBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBVidDeclMD6@@PBD@Z
// EA  : 0x82804840
// RVA : 0x00804840
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::FindAliasHandle(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const idDeclMD6 *decl,
        const char *aliasName)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v4; // r31
  int v7; // r3
  _WORD *v8; // r29
  int *v9; // r11
  int v11; // r30
  int v12; // r31
  int v13; // r11
  int v14; // [sp+50h] [-40h] BYREF

  v4 = result + 56;
  v7 = idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::IndexForName(
         this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[56],
         typeId: JOINTCONVERSION_ANY,
         name: aliasName,
         key: &v14);
  if ( v7 >= 0 )
  {
    v8 = (_WORD *)(52 * v7 + *(_DWORD *)&v4->value);
    if ( v8 != nullptr )
    {
      v9 = *(int **)v8;
      if ( *(_DWORD *)v8 == 0 )
      {
LABEL_4:
        HIWORD(this->__vftable) = v8[22];
        return this;
      }
      v11 = 0;
      if ( v9[1] > 0 )
      {
        v12 = 0;
        do
        {
          v13 = *v9;
          if ( *(const idDeclMD6 **)(v12 + v13) == decl
            || idDeclMD6::IsChildOf(this: decl, decl: *(const idDeclMD6 **)(v12 + v13)) )
          {
            goto LABEL_4;
          }
          v9 = *(int **)v8;
          ++v11;
          v12 += 4;
        }
        while ( v11 < *(_DWORD *)(*(_DWORD *)v8 + 4) );
      }
    }
  }
  HIWORD(this->__vftable) = -1;
  return this;
}


// ========================================================================
// ?FinalizeAliasRefs@idAnimationLocal@@UAAXXZ
// EA  : 0x82804910
// RVA : 0x00804910
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::FinalizeAliasRefs(idAnimationLocal *this)
{
  int v2; // r29
  int v3; // r30
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *list; // r4

  v2 = 0;
  if ( this->strongAliasRefs.num > 0 )
  {
    v3 = 0;
    do
    {
      idAnimationLocal::FinalizeAliasRefs(this, handle: &this->strongAliasRefs.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->strongAliasRefs.num );
  }
  if ( this->strongAliasRefs.listStatic == 0 || this->strongAliasRefs.listStatic == 2 )
  {
    list = this->strongAliasRefs.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->strongAliasRefs.list = nullptr;
    this->strongAliasRefs.size = 0;
  }
  this->strongAliasRefs.num = 0;
}


// ========================================================================
// ?anim_bumpFormat2to3_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828049A8
// RVA : 0x008049A8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_bumpFormat2to3_f(const idCmdArgs *args)
{
  int v1; // r27
  idFileList *v2; // r29
  int v3; // r21
  int v4; // r24
  idStr *list; // r20
  int v6; // r28
  int v7; // r27
  int v8; // r29
  idStr *v9; // r30
  const char *data; // r3
  int v11; // r5
  const char *v12; // r27
  const char *v13; // r28
  const char *v14; // r29
  int v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  va *v19; // r3
  int j; // r4
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r6
  __int64 v27; // r8
  va *v28; // r3
  int i; // r11
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  int size; // r29
  int k; // r30
  int v36; // [sp+8h] [-1798h]
  int v37; // [sp+8h] [-1798h]
  int v38; // [sp+8h] [-1798h]
  int v39; // [sp+Ch] [-1794h]
  int v40; // [sp+Ch] [-1794h]
  int v41; // [sp+Ch] [-1794h]
  int v42; // [sp+10h] [-1790h]
  int v43; // [sp+10h] [-1790h]
  int v44; // [sp+10h] [-1790h]
  int v45; // [sp+14h] [-178Ch]
  int v46; // [sp+14h] [-178Ch]
  int v47; // [sp+14h] [-178Ch]
  int v48; // [sp+18h] [-1788h]
  int v49; // [sp+18h] [-1788h]
  int v50; // [sp+18h] [-1788h]
  int v51; // [sp+1Ch] [-1784h]
  int v52; // [sp+1Ch] [-1784h]
  int v53; // [sp+1Ch] [-1784h]
  int v54; // [sp+54h] [-174Ch]
  idFileList *v55; // [sp+5Ch] [-1744h]
  int v56; // [sp+68h] [-1738h]
  int v57; // [sp+6Ch] [-1734h]
  idList<idStr,5> v58; // [sp+70h] [-1730h] BYREF
  const char *v59; // [sp+80h] [-1720h]
  const char *v60; // [sp+84h] [-171Ch]
  char *v61; // [sp+88h] [-1718h]
  const char *v62; // [sp+8Ch] [-1714h]
  const char *v63; // [sp+90h] [-1710h]
  char *v64; // [sp+94h] [-170Ch]
  const char *v65; // [sp+98h] [-1708h]
  const char *v66; // [sp+9Ch] [-1704h]
  const char *v67; // [sp+A0h] [-1700h]
  const char *v68; // [sp+A4h] [-16FCh]
  idMem *v69; // [sp+A8h] [-16F8h]
  const char *v70; // [sp+ACh] [-16F4h]
  const char *v71; // [sp+B0h] [-16F0h]
  const char *v72; // [sp+B4h] [-16ECh]
  const char *v73; // [sp+B8h] [-16E8h]
  const char *v74; // [sp+BCh] [-16E4h]
  const char *v75; // [sp+C0h] [-16E0h]
  char *v76; // [sp+C4h] [-16DCh] BYREF
  idToken v77; // [sp+D0h] [-16D0h] BYREF
  idStr *v78; // [sp+118h] [-1688h]
  idStr v79; // [sp+120h] [-1680h] BYREF
  idStr v80; // [sp+140h] [-1660h] BYREF
  idStr v81; // [sp+160h] [-1640h] BYREF
  idToken v82; // [sp+180h] [-1620h] BYREF
  idParser v83; // [sp+1D0h] [-15D0h] BYREF
  idParser v84; // [sp+460h] [-1340h] BYREF
  va v85; // [sp+6F0h] [-10B0h] BYREF

  common->SetRefreshOnPrint(this: common, a2: true);
  v56 = 0;
  v57 = 0;
  v55 = fileSystem->ListFilesTree(this: fileSystem, a2: "md6", a3: "md6anim", a4: 0);
  v69 = &mem;
  v63 = " -transMask animation/characters/default/mesh/mask_no_eyes.md6mask";
  v54 = 0;
  v67 = "updated version number.\n";
  v74 = "anim";
  v62 = "\n\nrotationMask {\n}\n\nscaleMask {\n}\n\ntranslationMask {\n}";
  v70 = "updated with eye mask.\n";
  v64 = "\"";
  v72 = "skel";
  v66 = "mesh";
  v65 = "-ex";
  v61 = " \"";
  v1 = 0;
  v60 = "flags";
  v59 = "transMask";
  v68 = "scaleMask";
  v71 = "\n"
        "\n"
        "rotationMask {\n"
        "}\n"
        "\n"
        "scaleMask {\n"
        "}\n"
        "\n"
        "translationMask {\n"
        "\t\"EyeBall_Left_Joint\"\n"
        "\t\"EyeBall_Right_Joint\"\n"
        "}";
  v2 = v55;
  v73 = "rotMask";
  v75 = "Expected a joint name string, found '%s'.";
  while ( v1 < v2->list.num )
  {
    idLib::Printf(fmt: "Checking %s...", v2->list.list[v1].data);
    fileSystem->ReadFile(this: fileSystem, a2: v2->list.list[v1].data, a3: (void **)&v76, a4: nullptr);
    idStr::idStr(this: &v80, text: v76);
    fileSystem->FreeFile(this: fileSystem, a2: v76);
    idParser::idParser(this: &v83, flags: 262704);
    v77.floatvalue = -3.4028235e38;
    v77.allocedAndFlag = 20;
    v77.data = v77.baseBuffer;
    v77.len = 0;
    v77.baseBuffer[0] = 0;
    v77.intvalue = 0;
    memset(&v77.whiteSpaceStart_p, 0, 12);
    if ( !idParser::LoadMemory(this: &v83, ptr: v80.data, length: v80.len, name: v2->list.list[v1].data) )
    {
      idLib::Printf(fmt: "^2ERROR LOADING FILE.\n");
      idStr::FreeData(this: &v77);
      idParser::~idParser(this: &v83);
      idStr::FreeData(this: &v80);
      v54 = ++v1;
      continue;
    }
    idParser::ExpectTokenString(this: &v83, string: MD6_VERSION_STRING);
    if ( idParser::ParseInt(this: &v83) != 2 )
    {
      idStr::FreeData(this: &v77);
      idParser::~idParser(this: &v83);
      idStr::FreeData(this: &v80);
      v54 = ++v1;
      continue;
    }
    idParser::ExpectTokenString(this: &v83, string: "init");
    idParser::ExpectTokenType(this: &v83, type: 5, subtype: 46, token: &v77);
    v82.floatvalue = -3.4028235e38;
    v82.allocedAndFlag = 20;
    v82.data = v82.baseBuffer;
    v82.len = 0;
    v82.baseBuffer[0] = 0;
    v82.intvalue = 0;
    memset(&v82.whiteSpaceStart_p, 0, 12);
    v3 = -1;
    v4 = -1;
    while ( idParser::ReadToken(this: &v83, token: &v77) && (v77.type != 5 || v77.subtype != 47) )
    {
      if ( idStr::Icmp(s1: v77.data, s2: "commandLine") == 0 )
      {
        if ( v83.scriptstack != nullptr )
          v3 = v83.scriptstack->script_p - v83.scriptstack->buffer;
        else
          v3 = 0;
        idParser::ReadToken(this: &v83, token: &v82);
        if ( v83.scriptstack != nullptr )
          v4 = v83.scriptstack->script_p - v83.scriptstack->buffer;
        else
          v4 = 0;
        idParser::SkipBracedSection(this: &v83, parseFirstBrace: false);
        break;
      }
    }
    idParser::ExpectTokenString(this: &v83, string: v60);
    idParser::SkipBracedSection(this: &v83, parseFirstBrace: true);
    *(_WORD *)&v58.memTag = 1280;
    list = nullptr;
    memset(&v58, 0, 14);
    idParser::ExpectTokenString(this: &v83, string: "joints");
    idParser::ExpectTokenType(this: &v83, type: 5, subtype: 46, token: &v77);
    while ( idParser::ReadToken(this: &v83, token: &v77) )
    {
      if ( v77.type == 5 )
      {
        if ( v77.subtype == 47 )
          break;
LABEL_23:
        idParser::Error(this: &v83, str: v75, v77.data);
      }
      else
      {
        if ( v77.type != 1 )
          goto LABEL_23;
        idList<idStr,5>::Append(this: &v58, obj: &v77);
        idParser::ParseInt(this: &v83);
        list = v58.list;
      }
    }
    v6 = -1;
    v7 = -1;
    v8 = 0;
    while ( v8 < v58.num )
    {
      v9 = &list[v8];
      v78 = v9;
      if ( idStr::Icmp(s1: v9->data, s2: "EyeBall_Left_Joint") != 0 )
      {
        data = v9->data;
        v78 = &list[v8];
        if ( idStr::Icmp(s1: data, s2: "EyeBall_Right_Joint") != 0 )
          goto LABEL_32;
        v7 = v8++;
      }
      else
      {
        v6 = v8;
LABEL_32:
        ++v8;
      }
    }
    if ( v83.scriptstack != nullptr )
      v11 = v83.scriptstack->script_p - v83.scriptstack->buffer;
    else
      v11 = 0;
    if ( v6 < 0 || v7 < 0 )
    {
      idStr::Insert(this: &v80, text: v62, index: v11);
      v81.len = 0;
      LODWORD(v25) = 20;
      v81.baseBuffer[0] = 0;
      v81.data = v81.baseBuffer;
      v81.allocedAndFlag = 20;
      HIDWORD(v26) = MD6_VERSION_STRING;
      v28 = va::va(
              this: &v85,
              fmt: "%s 2",
              a3: v26,
              a4: v27,
              a5: v25,
              a6: v36,
              a7: v39,
              a8: v42,
              a9: v45,
              a10: v48,
              a11: v51);
      for ( i = 0; v28->buffer[i] != 0; ++i )
        ;
      idStr::Append(this: &v81, text: &v80.data[i]);
      HIDWORD(v30) = MD6_VERSION_STRING;
      LODWORD(v30) = 7;
      v33 = va::va(
              this: &v85,
              fmt: "%s %d",
              a3: v30,
              a4: v32,
              a5: v31,
              a6: v38,
              a7: v41,
              a8: v44,
              a9: v47,
              a10: v50,
              a11: v53);
      idStr::Insert(this: &v81, text: v33->buffer, index: 0);
      fileSystem->WriteFile(this: fileSystem, a2: v55->list.list[v54].data, a3: v81.data, a4: v81.len, a5: FSPATH_BASE);
      idLib::Printf(fmt: v67);
      ++v57;
      idStr::FreeData(this: &v81);
    }
    else
    {
      idStr::Insert(this: &v80, text: v71, index: v11);
      idParser::idParser(this: &v84, flags: 262704);
      idParser::LoadMemory(this: &v84, ptr: v82.data, length: v82.len, name: "commandLine");
      v12 = v65;
      v13 = v66;
      v14 = v72;
LABEL_39:
      v15 = 0;
      while ( idParser::ReadToken(this: &v84, token: &v77) )
      {
        if ( v77.type == 5 && v77.subtype == 31 )
        {
          idParser::ReadToken(this: &v84, token: &v77);
          if ( idStr::Cmp(s1: v77.data, s2: v73) != 0
            && idStr::Cmp(s1: v77.data, s2: v68) != 0
            && idStr::Cmp(s1: v77.data, s2: v59) != 0 )
          {
            if ( idStr::Cmp(s1: v77.data, s2: v12) != 0 )
            {
              if ( idStr::Cmp(s1: v77.data, s2: v13) != 0 )
              {
                if ( idStr::Cmp(s1: v77.data, s2: v14) != 0 )
                {
                  if ( idStr::Cmp(s1: v77.data, s2: "subanim") == 0 )
                  {
                    idParser::ReadToken(this: &v84, token: &v77);
                    if ( v84.scriptstack == nullptr )
                      goto LABEL_39;
                    v15 = v84.scriptstack->script_p - v84.scriptstack->buffer;
                  }
                }
                else
                {
                  idParser::ReadToken(this: &v84, token: &v77);
                  if ( v84.scriptstack == nullptr )
                    goto LABEL_39;
                  v15 = v84.scriptstack->script_p - v84.scriptstack->buffer;
                }
              }
              else
              {
                idParser::ReadToken(this: &v84, token: &v77);
                if ( v84.scriptstack == nullptr )
                  goto LABEL_39;
                v15 = v84.scriptstack->script_p - v84.scriptstack->buffer;
              }
            }
            else
            {
              idParser::ExpectTokenString(this: &v84, string: v74);
              if ( v84.scriptstack == nullptr )
                goto LABEL_39;
              v15 = v84.scriptstack->script_p - v84.scriptstack->buffer;
            }
          }
          else
          {
            idParser::ReadToken(this: &v84, token: &v77);
          }
        }
      }
      v79.len = 0;
      LODWORD(v16) = 20;
      v79.baseBuffer[0] = 0;
      v79.data = v79.baseBuffer;
      v79.allocedAndFlag = 20;
      HIDWORD(v18) = MD6_VERSION_STRING;
      v19 = va::va(
              this: &v85,
              fmt: "%s 2",
              a3: v18,
              a4: v17,
              a5: v16,
              a6: v36,
              a7: v39,
              a8: v42,
              a9: v45,
              a10: v48,
              a11: v51);
      for ( j = 0; v19->buffer[j] != 0; ++j )
        ;
      idStr::Mid(this: &v80, start: j, len: v3 - j, result: &v79);
      HIDWORD(v21) = MD6_VERSION_STRING;
      LODWORD(v21) = 7;
      v24 = va::va(
              this: &v85,
              fmt: "%s %d",
              a3: v21,
              a4: v23,
              a5: v22,
              a6: v37,
              a7: v40,
              a8: v43,
              a9: v46,
              a10: v49,
              a11: v52);
      idStr::Insert(this: &v79, text: v24->buffer, index: 0);
      idStr::Insert(this: &v82, text: v63, index: v15);
      idStr::Append(this: &v79, text: v61);
      idStr::Append(this: &v79, text: &v82);
      idStr::Append(this: &v79, text: v64);
      idStr::Append(this: &v79, text: &v80.data[v4]);
      fileSystem->WriteFile(this: fileSystem, a2: v55->list.list[v54].data, a3: v79.data, a4: v79.len, a5: FSPATH_BASE);
      idLib::Printf(fmt: v70);
      ++v56;
      idStr::FreeData(this: &v79);
      idParser::~idParser(this: &v84);
    }
    if ( v58.listStatic == 0 || v58.listStatic == 2 )
    {
      if ( list != nullptr )
      {
        size = v58.size;
        for ( k = 0; k < size; ++k )
          idStr::FreeData(this: &list[k]);
        idMem::Free(this: v69, ptr: list, align: ALIGN_16);
      }
      v58.list = nullptr;
      v58.size = 0;
    }
    v58.num = 0;
    idStr::FreeData(this: &v82);
    idStr::FreeData(this: &v77);
    idParser::~idParser(this: &v83);
    idStr::FreeData(this: &v80);
    v2 = v55;
    v1 = ++v54;
  }
  idLib::Printf(fmt: "%d files modified.\n", v57 + v56);
  idLib::Printf(fmt: "Masked: %d files.\n", v56);
  idLib::Printf(fmt: "Reversioned: %d files.\n", v57);
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// $M234751_0
// EA  : 0x82805660
// RVA : 0x00805660
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M234751_0()
{
  idLib::Warning(fmt: idException::error);
  return &_LN54_1;
}


// ========================================================================
// __unwind$233840
// EA  : 0x82805690
// RVA : 0x00805690
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233840()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6048 + 320));
}


// ========================================================================
// __unwind$233841
// EA  : 0x828056B8
// RVA : 0x008056B8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233841()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 6048 + 464));
}


// ========================================================================
// __unwind$233842
// EA  : 0x828056E0
// RVA : 0x008056E0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233842()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6048 + 208));
}


// ========================================================================
// __unwind$233843
// EA  : 0x82805708
// RVA : 0x00805708
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233843()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6048 + 384));
}


// ========================================================================
// __unwind$233844
// EA  : 0x82805730
// RVA : 0x00805730
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233844()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 6048 + 112));
}


// ========================================================================
// __unwind$233845
// EA  : 0x82805758
// RVA : 0x00805758
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233845()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 6048 + 1120));
}


// ========================================================================
// __unwind$233846
// EA  : 0x82805780
// RVA : 0x00805780
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233846()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6048 + 288));
}


// ========================================================================
// __unwind$233847
// EA  : 0x828057A8
// RVA : 0x008057A8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_233847()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6048 + 352));
}


// ========================================================================
// ?anim_bumpFormat3to4_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828057D8
// RVA : 0x008057D8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_bumpFormat3to4_f(const idCmdArgs *args)
{
  const char *v1; // r29
  idFileList *v2; // r18
  int v3; // r3
  int v4; // r30
  idStr *list; // r27
  encounterGroupRole_t *v6; // r28
  int v7; // r30
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // r29
  va *v12; // r3
  int i; // r4
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  int j; // r30
  __int64 v21; // r6
  va *v22; // r3
  int k; // r11
  int m; // r30
  int v25; // [sp+8h] [-1468h]
  int v26; // [sp+8h] [-1468h]
  int v27; // [sp+Ch] [-1464h]
  int v28; // [sp+Ch] [-1464h]
  int v29; // [sp+10h] [-1460h]
  int v30; // [sp+10h] [-1460h]
  int v31; // [sp+14h] [-145Ch]
  int v32; // [sp+14h] [-145Ch]
  int v33; // [sp+18h] [-1458h]
  int v34; // [sp+18h] [-1458h]
  int v35; // [sp+1Ch] [-1454h]
  int v36; // [sp+1Ch] [-1454h]
  int v37; // [sp+50h] [-1420h]
  int v38; // [sp+54h] [-141Ch]
  idList<idStr,5> v39; // [sp+60h] [-1410h] BYREF
  idList<enum encounterGroupRole_t,5> v40; // [sp+70h] [-1400h] BYREF
  const char *v41; // [sp+80h] [-13F0h]
  const char *v42; // [sp+84h] [-13ECh]
  char *v43; // [sp+88h] [-13E8h] BYREF
  const char *v44; // [sp+8Ch] [-13E4h]
  const char *v45; // [sp+90h] [-13E0h]
  char *v46; // [sp+94h] [-13DCh]
  char *v47; // [sp+98h] [-13D8h]
  const char *v48; // [sp+9Ch] [-13D4h]
  const char *v49; // [sp+A0h] [-13D0h]
  idFileList *v50; // [sp+A4h] [-13CCh]
  encounterGroupRole_t v51[2]; // [sp+A8h] [-13C8h] BYREF
  idStr v52; // [sp+B0h] [-13C0h] BYREF
  idToken v53; // [sp+D0h] [-13A0h] BYREF
  idStr v54; // [sp+120h] [-1350h] BYREF
  idParser v55; // [sp+140h] [-1330h] BYREF
  va v56; // [sp+3D0h] [-10A0h] BYREF

  common->SetRefreshOnPrint(this: common, a2: true);
  v38 = 0;
  v50 = fileSystem->ListFilesTree(this: fileSystem, a2: "md6", a3: "md6anim", a4: 0);
  v37 = 0;
  v49 = "^2updated joint mask.\n";
  v47 = "\n";
  v44 = "flags";
  v1 = "Expected joint name, found '%s'";
  v46 = "}";
  v45 = "Expected joint name, found '%s'";
  v48 = "init";
  v2 = v50;
  v42 = "already version 4.\n";
  v41 = "^2ERROR LOADING FILE.\n";
  v3 = 0;
  while ( v3 < v2->list.num )
  {
    v4 = v3;
    idLib::Printf(fmt: "Checking %s...", v2->list.list[v3].data);
    fileSystem->ReadFile(this: fileSystem, a2: v2->list.list[v4].data, a3: (void **)&v43, a4: nullptr);
    idStr::idStr(this: &v54, text: v43);
    fileSystem->FreeFile(this: fileSystem, a2: v43);
    idParser::idParser(this: &v55, flags: 262704);
    v53.floatvalue = -3.4028235e38;
    v53.data = v53.baseBuffer;
    v53.allocedAndFlag = 20;
    v53.len = 0;
    v53.baseBuffer[0] = 0;
    v53.intvalue = 0;
    memset(&v53.whiteSpaceStart_p, 0, 12);
    if ( !idParser::LoadMemory(this: &v55, ptr: v54.data, length: v54.len, name: v2->list.list[v4].data) )
    {
      idLib::Printf(fmt: v41);
      idStr::FreeData(this: &v53);
      idParser::~idParser(this: &v55);
      idStr::FreeData(this: &v54);
      v3 = ++v37;
      continue;
    }
    idParser::ExpectTokenString(this: &v55, string: MD6_VERSION_STRING);
    if ( idParser::ParseInt(this: &v55) != 3 )
    {
      idLib::Printf(fmt: v42);
      idStr::FreeData(this: &v53);
      idParser::~idParser(this: &v55);
      idStr::FreeData(this: &v54);
      v3 = ++v37;
      continue;
    }
    idParser::ExpectTokenString(this: &v55, string: v48);
    idParser::SkipBracedSection(this: &v55, parseFirstBrace: true);
    idParser::ExpectTokenString(this: &v55, string: v44);
    idParser::SkipBracedSection(this: &v55, parseFirstBrace: true);
    *(_WORD *)&v39.memTag = 1280;
    list = nullptr;
    memset(&v39, 0, 14);
    v6 = nullptr;
    *(_WORD *)&v40.memTag = 1280;
    memset(&v40, 0, 14);
    idParser::ExpectTokenString(this: &v55, string: "joints");
    idParser::ExpectTokenType(this: &v55, type: 5, subtype: 46, token: &v53);
    if ( v55.scriptstack != nullptr )
      v7 = v55.scriptstack->script_p - v55.scriptstack->buffer;
    else
      v7 = 0;
    while ( idParser::ReadToken(this: &v55, token: &v53) )
    {
      if ( v53.type == 5 )
      {
        if ( v53.subtype == 47 )
          break;
LABEL_13:
        idParser::Error(this: &v55, str: v1, v53.data);
      }
      else
      {
        if ( v53.type != 1 )
          goto LABEL_13;
        idList<idStr,5>::Append(this: &v39, obj: &v53);
        v51[0] = idParser::ParseInt(this: &v55);
        idList<idAnimWebBlendTree *,5>::Append(this: &v40, obj: v51);
        list = v39.list;
        v6 = v40.list;
      }
    }
    if ( v55.scriptstack != nullptr )
    {
      v8 = *(_QWORD *)&v55.scriptstack->buffer;
      v11 = v8 - HIDWORD(v8);
    }
    else
    {
      v11 = 0;
    }
    v52.allocedAndFlag = 20;
    v52.len = 0;
    v52.data = v52.baseBuffer;
    v52.baseBuffer[0] = 0;
    HIDWORD(v10) = MD6_VERSION_STRING;
    v12 = va::va(
            this: &v56,
            fmt: "%s 2",
            a3: v10,
            a4: v9,
            a5: v8,
            a6: v25,
            a7: v27,
            a8: v29,
            a9: v31,
            a10: v33,
            a11: v35);
    for ( i = 0; v12->buffer[i] != 0; ++i )
      ;
    idStr::Mid(this: &v54, start: i, len: v7 - i, result: &v52);
    HIDWORD(v14) = MD6_VERSION_STRING;
    LODWORD(v14) = 7;
    v17 = va::va(
            this: &v56,
            fmt: "%s %d",
            a3: v14,
            a4: v16,
            a5: v15,
            a6: v26,
            a7: v28,
            a8: v30,
            a9: v32,
            a10: v34,
            a11: v36);
    idStr::Insert(this: &v52, text: v17->buffer, index: 0);
    idStr::Append(this: &v52, text: v47);
    for ( j = 0; j < v39.num; ++j )
    {
      LODWORD(v18) = 4 * j;
      SLODWORD(v21) = v6[j];
      HIDWORD(v21) = list[j].data;
      v22 = va::va(
              this: &v56,
              fmt: "\t\"%s\" %d 1\n",
              a3: v21,
              a4: v19,
              a5: v18,
              a6: v25,
              a7: v27,
              a8: v29,
              a9: v31,
              a10: v33,
              a11: v35);
      idStr::Append(this: &v52, text: v22);
    }
    idStr::Append(this: &v52, text: v46);
    idStr::Append(this: &v52, text: &v54.data[v11]);
    fileSystem->WriteFile(this: fileSystem, a2: v2->list.list[v37].data, a3: v52.data, a4: v52.len, a5: FSPATH_BASE);
    idLib::Printf(fmt: v49);
    ++v38;
    idStr::FreeData(this: &v52);
    if ( v40.listStatic == 0 || v40.listStatic == 2 )
    {
      if ( v6 != nullptr )
      {
        for ( k = 0; k < v40.size; ++k )
          ;
        idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
      }
      v40.list = nullptr;
      v40.size = 0;
    }
    v40.num = 0;
    if ( v39.listStatic == 0 || v39.listStatic == 2 )
    {
      if ( list != nullptr )
      {
        for ( m = 0; m < v39.size; ++m )
          idStr::FreeData(this: &list[m]);
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      v39.list = nullptr;
      v39.size = 0;
    }
    v39.num = 0;
    idStr::FreeData(this: &v53);
    idParser::~idParser(this: &v55);
    idStr::FreeData(this: &v54);
    v1 = v45;
    v3 = ++v37;
  }
  idLib::Printf(fmt: "%d files bumped.\n", v38);
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// $M235373_2
// EA  : 0x82805F34
// RVA : 0x00805F34
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M235373_2()
{
  idLib::Warning(fmt: idException::error);
  return &_LN27_1;
}


// ========================================================================
// __unwind$234798
// EA  : 0x82805F64
// RVA : 0x00805F64
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234798()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5232 + 288));
}


// ========================================================================
// __unwind$234799
// EA  : 0x82805F8C
// RVA : 0x00805F8C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234799()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5232 + 320));
}


// ========================================================================
// __unwind$234800
// EA  : 0x82805FB4
// RVA : 0x00805FB4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234800()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5232 + 208));
}


// ========================================================================
// __unwind$234801
// EA  : 0x82805FDC
// RVA : 0x00805FDC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234801()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 5232 + 96));
}


// ========================================================================
// __unwind$234802
// EA  : 0x82806004
// RVA : 0x00806004
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234802()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5232 + 112));
}


// ========================================================================
// __unwind$234803
// EA  : 0x8280602C
// RVA : 0x0080602C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_234803()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5232 + 176));
}


// ========================================================================
// ?anim_fixProps_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82806060
// RVA : 0x00806060
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_fixProps_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr58
  const char *v3; // r30
  idFileList *v4; // r3
  idFileList *v5; // r28
  int v6; // r29
  int v7; // r30
  idStr *list; // r19
  int v9; // r20
  const idStr *v10; // r30
  unsigned int v11; // r29
  const char *data; // r6
  int v13; // r29
  idFile *v14; // r30
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  __int64 v18; // r10
  idQuat *v19; // r3
  double x; // fp9
  double v21; // fp0
  double z; // fp5
  double v23; // fp2
  double v24; // fp1
  double v25; // fp13
  double v26; // fp11
  double v27; // fp0
  double v28; // fp12
  double v29; // fp1
  double v30; // fp4
  double v31; // fp2
  va *v32; // r3
  int v33; // [sp+8h] [-1398h]
  int v34; // [sp+Ch] [-1394h]
  int v35; // [sp+10h] [-1390h]
  int v36; // [sp+14h] [-138Ch]
  int v37; // [sp+18h] [-1388h]
  int v38; // [sp+1Ch] [-1384h]
  double v39; // [sp+30h] [-1370h]
  const char *v40; // [sp+50h] [-1350h] BYREF
  int v41; // [sp+54h] [-134Ch]
  idList<idStr,5> v42; // [sp+60h] [-1340h] BYREF
  float v43; // [sp+70h] [-1330h] BYREF
  float v44; // [sp+74h] [-132Ch]
  float v45; // [sp+78h] [-1328h]
  float v46; // [sp+7Ch] [-1324h]
  const idStr *v47; // [sp+80h] [-1320h]
  float v48[6]; // [sp+88h] [-1318h] BYREF
  idQuat v49; // [sp+A0h] [-1300h] BYREF
  idToken v50; // [sp+B0h] [-12F0h] BYREF
  idStr v51; // [sp+100h] [-12A0h] BYREF
  idLexer v52; // [sp+120h] [-1280h] BYREF
  idStr v53; // [sp+1B0h] [-11F0h] BYREF
  idStr v54; // [sp+1D0h] [-11D0h] BYREF
  idStr v55; // [sp+1F0h] [-11B0h] BYREF
  idStr v56; // [sp+210h] [-1190h] BYREF
  idQuat v57; // [sp+230h] [-1170h] BYREF
  idJointGroupCollection v58; // [sp+240h] [-1160h] BYREF
  va v59; // [sp+310h] [-1090h] BYREF

  argc = args->argc;
  v2 = args->argc == 2;
  v41 = args->argc;
  if ( !v2 )
  {
    idLib::Printf(fmt: "USAGE: anim_fixProps [path]\n");
    return;
  }
  if ( argc <= 1 )
    v3 = &byte_8200D768;
  else
    v3 = args->argv[1];
  *(_WORD *)&v42.memTag = 1280;
  memset(&v42, 0, 14);
  if ( fileSystem->IsFolder(this: fileSystem, a2: v3, a3: FSPATH_BASE) == FOLDER_YES )
  {
    v4 = fileSystem->ListFilesTree(this: fileSystem, a2: v3, a3: ".md6def", a4: 0);
    v5 = v4;
    if ( v4 == nullptr )
    {
_M235805:
      idLib::Printf(fmt: "No files found.");
      idList<idStr,99>::~idList<idStr,99>(this: &v42);
      return;
    }
    v6 = 0;
    if ( v4->list.num > 0 )
    {
      v7 = 0;
      do
      {
        idStr::idStr(this: &v56, text: v5->list.list[v7].data);
        idList<idStr,5>::Append(this: &v42, obj: &v56);
        idStr::FreeData(this: &v56);
        ++v6;
        ++v7;
      }
      while ( v6 < v5->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v5);
  }
  else
  {
    idStr::idStr(this: &v55, text: v3);
    idList<idStr,5>::Append(this: &v42, obj: &v55);
    idStr::FreeData(this: &v55);
  }
  if ( v42.num <= 0 )
    goto _M235805;
  list = v42.list;
  v9 = 0;
  while ( 1 )
  {
    v41 = v9;
    if ( v9 >= v42.num )
      break;
    v40 = nullptr;
    v10 = &list[v9];
    v47 = v10;
    v11 = fileSystem->ReadFile(this: fileSystem, a2: v10->data, a3: (void **)&v40, a4: nullptr);
    if ( v11 != 0 )
    {
      idLexer::idLexer(this: &v52, flags_: 418360);
      data = v10->data;
      v47 = &list[v9];
      if ( idLexer::LoadMemory(this: &v52, ptr: v40, length_: v11, name: data) )
      {
        v47 = &list[v9];
        idStr::idStr(this: &v51, text: v47);
        v50.floatvalue = -3.4028235e38;
        v50.data = v50.baseBuffer;
        v50.allocedAndFlag = 20;
        v50.len = 0;
        v50.baseBuffer[0] = 0;
        v50.intvalue = 0;
        memset(&v50.whiteSpaceStart_p, 0, 12);
        v13 = 0;
        idJointGroupCollection::idJointGroupCollection(this: &v58);
        v14 = nullptr;
        while ( idLexer::ReadToken(this: &v52, token: &v50) )
        {
          if ( idStr::Cmp(s1: v50.data, s2: "trans") != 0 )
          {
            if ( idStr::Cmp(s1: v50.data, s2: "rot") == 0 )
            {
              if ( v14 == nullptr )
              {
                v14 = fileSystem->OpenFileWrite(this: fileSystem, a2: v51.data, a3: 0);
                if ( v14 == nullptr )
                  goto LABEL_40;
              }
              v14->Write(this: v14, a2: &v40[v13], a3: v52.script_p - v52.buffer - v13);
              idLexer::Parse1DMatrix(this: &v52, x: 4, m: &v43, expectCommas: false);
              idLexer::SkipRestOfLine(this: &v52);
              v49.x = 0.5;
              v49.y = 0.5;
              v49.z = 0.5;
              v49.w = 0.5;
              v13 = v52.script_p - v52.buffer;
              v19 = idQuat::Inverse(this: &v57, result: &v49);
              x = v19->x;
              v21 = v43;
              z = v19->z;
              v23 = (float)((float)(v19->x * v45) + (float)((float)(v19->w * v44) + (float)(v19->y * v46)));
              v24 = (float)((float)(v19->w * v45) + (float)((float)(v19->y * v43) + (float)(v19->z * v46)));
              v25 = (float)-(float)((float)(v19->y * v45)
                                  - (float)((float)(v19->x * v46)
                                          + (float)((float)(v19->z * v44) + (float)(v19->w * v43))));
              v26 = (float)-(float)((float)(v19->z * v45)
                                  - (float)-(float)((float)(v19->y * v44)
                                                  - (float)((float)(v19->w * v46) - (float)(v19->x * v43))));
              v43 = -(float)((float)(v19->y * v45)
                           - (float)((float)(v19->x * v46) + (float)((float)(v19->z * v44) + (float)(v19->w * v43))));
              v46 = v26;
              v27 = (float)-(float)((float)((float)z * (float)v21) - (float)v23);
              v28 = (float)-(float)((float)((float)x * v44) - (float)v24);
              v45 = -(float)((float)((float)x * v44) - (float)v24);
              v44 = v27;
              v29 = v25;
              v30 = v26;
              v31 = v27;
              if ( v25 < 0.0000099999997 && v25 > -0.0000099999997 )
              {
                v43 = 0.0;
                v29 = 0.0;
              }
              if ( v27 < 0.0000099999997 && v27 > -0.0000099999997 )
              {
                v44 = 0.0;
                v31 = 0.0;
              }
              if ( v28 < 0.0000099999997 && v28 > -0.0000099999997 )
                v45 = 0.0;
              if ( v26 < 0.0000099999997 && v26 > -0.0000099999997 )
              {
                v46 = 0.0;
                v30 = 0.0;
              }
              v32 = va::va(
                      this: &v59,
                      fmt: " ( %g %g %g %g )",
                      a3: __SPAIR64__(LODWORD(v29), LODWORD(v31)),
                      a4: *(__int64 *)&v30,
                      a5: v18,
                      a6: v33,
                      a7: v34,
                      a8: v35,
                      a9: v36,
                      a10: v37,
                      a11: v38);
              idStr::idStr(this: &v53, text: v32);
              v14->Write(this: v14, a2: v53.data, a3: v53.len);
              idStr::FreeData(this: &v53);
            }
          }
          else
          {
            if ( v14 == nullptr )
            {
              v14 = fileSystem->OpenFileWrite(this: fileSystem, a2: v51.data, a3: 0);
              if ( v14 == nullptr )
                goto LABEL_40;
            }
            v14->Write(this: v14, a2: &v40[v13], a3: v52.script_p - v52.buffer - v13);
            idLexer::Parse1DMatrix(this: &v52, x: 3, m: v48, expectCommas: false);
            idLexer::SkipRestOfLine(this: &v52);
            LODWORD(v15) = v52.buffer;
            v39 = v48[1];
            HIDWORD(v16) = LODWORD(v39);
            v13 = v52.script_p - v52.buffer;
            v17 = va::va(
                    this: &v59,
                    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v48[2])),
                    a3: COERCE__INT64(v48[0]),
                    a4: v16,
                    a5: v15,
                    a6: v33,
                    a7: v34,
                    a8: v35,
                    a9: v36,
                    a10: v37,
                    a11: v38);
            idStr::idStr(this: &v54, text: v17);
            v14->Write(this: v14, a2: v54.data, a3: v54.len);
            idStr::FreeData(this: &v54);
          }
        }
        if ( v14 == nullptr )
        {
LABEL_40:
          v14 = fileSystem->OpenFileWrite(this: fileSystem, a2: v51.data, a3: 0);
          if ( v14 == nullptr )
            goto LABEL_42;
        }
        v14->Write(this: v14, a2: &v40[v13], a3: v52.script_p - v52.buffer - v13);
        ((void (__fastcall *)(idFile *, int))v14->dtr_idFile)(a1: v14, a2: 1);
LABEL_42:
        idJointGroupCollection::~idJointGroupCollection(this: &v58);
        idStr::FreeData(this: &v50);
        idStr::FreeData(this: &v51);
        idLexer::~idLexer(this: &v52);
        list = v42.list;
        ++v9;
      }
      else
      {
        idLexer::~idLexer(this: &v52);
        ++v9;
      }
    }
    else
    {
      idLib::Warning(fmt: "Failed to open file '%s'", v10->data);
      ++v9;
    }
  }
  if ( (v42.listStatic == 0 || v42.listStatic == 2) && list != nullptr )
    idListArrayDelete<idStr>(ptr: list, num: v42.size);
}


// ========================================================================
// $M235815
// EA  : 0x828067F4
// RVA : 0x008067F4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M235815()
{
  int v0; // r12

  idLib::Printf(
    fmt: "Failed parsing '%s'\n",
    *(const char **)(32 * *(_DWORD *)(v0 - 5024 + 84) + *(_DWORD *)(v0 - 5024 + 96) + 4));
  return &_M235799;
}


// ========================================================================
// __unwind$235427
// EA  : 0x8280683C
// RVA : 0x0080683C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235427()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 5024 + 96));
}


// ========================================================================
// __unwind$235428
// EA  : 0x82806864
// RVA : 0x00806864
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235428()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 528));
}


// ========================================================================
// __unwind$235429
// EA  : 0x8280688C
// RVA : 0x0080688C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235429()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 496));
}


// ========================================================================
// __unwind$235430
// EA  : 0x828068B4
// RVA : 0x008068B4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235430()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 5024 + 288));
}


// ========================================================================
// __unwind$235431
// EA  : 0x828068DC
// RVA : 0x008068DC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235431()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 256));
}


// ========================================================================
// __unwind$235432
// EA  : 0x82806904
// RVA : 0x00806904
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235432()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 176));
}


// ========================================================================
// __unwind$235433
// EA  : 0x8280692C
// RVA : 0x0080692C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235433()
{
  int v0; // r12

  idJointGroupCollection::~idJointGroupCollection(this: (idJointGroupCollection *)(v0 - 5024 + 576));
}


// ========================================================================
// __unwind$235434
// EA  : 0x82806954
// RVA : 0x00806954
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235434()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 464));
}


// ========================================================================
// __unwind$235435
// EA  : 0x8280697C
// RVA : 0x0080697C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_235435()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5024 + 432));
}


// ========================================================================
// ??0idJointConversion@@QAA@XZ
// EA  : 0x82806DF0
// RVA : 0x00806DF0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idJointConversion *__fastcall idJointConversion::idJointConversion(idJointConversion *this)
{
  idResource::idResource(this);
  this->__vftable = (idJointConversion_vtbl *)&idJointConversion::`vftable';
  this->handle.value = -1;
  this->tableJoints.list = nullptr;
  this->tableJoints.granularity = 0;
  this->tableJoints.memTag = 5;
  this->tableJoints.listStatic = 0;
  this->tableJoints.size = 0;
  this->tableJoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableJoints);
  this->tableUserChannels.memTag = 5;
  this->tableUserChannels.list = nullptr;
  this->tableUserChannels.granularity = 0;
  this->tableUserChannels.listStatic = 0;
  this->tableUserChannels.size = 0;
  this->tableUserChannels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tableUserChannels);
  this->checksum.value = -1;
  idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5>::SetNum(
    this: &this->tableJoints,
    newNum: 256,
    initValue: &NULL_JOINT);
  idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5>::SetNum(
    this: (idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5> *)&this->tableUserChannels,
    newNum: 256,
    initValue: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)&NULL_USERCHANNEL);
  return this;
}


// ========================================================================
// __unwind$236052
// EA  : 0x82806EC4
// RVA : 0x00806EC4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236052()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$236053
// EA  : 0x82806EEC
// RVA : 0x00806EEC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236053()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// __unwind$236054
// EA  : 0x82806F18
// RVA : 0x00806F18
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236054()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// ?GetAliasRefs@idAnimationLocal@@UBAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NAAV?$idList@PBVidDeclMD6@@$04@@@Z
// EA  : 0x82806F48
// RVA : 0x00806F48
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::GetAliasRefs(
        idAnimationLocal *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        const bool strongOnly,
        idList<idVehicleState *,5> *declList)
{
  int v8; // r30
  int value; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v10; // r29
  const idAliasGroup *ptr; // r11
  int v12; // r31
  const idMD6Alias *Alias; // r3
  idDeclMD6 *v14; // [sp+50h] [-40h] BYREF

  if ( declList->size < 0 )
    idList<idThread *,58>::Clear(this: declList);
  v8 = 0;
  declList->num = __CFADD__(-declList->size, declList->size ^ 0x80000000) ? 0 : declList->size;
  value = aliasHandle->value;
  if ( value != 0xFFFF && value < this->aliasHash.list.num )
  {
    v10 = &this->aliasHash.list.list[value];
    if ( v10 != nullptr && (_cntlzw(v10->refType - 1) & 0x20) == 0 )
    {
      ptr = v10->ptr;
      if ( v10->ptr->declRefs.num > 0 )
      {
        v12 = 0;
        do
        {
          v14 = ptr->declRefs.list[v12];
          if ( v14 != nullptr
            && (!strongOnly
             || (Alias = idDeclMD6::FindAlias(this: v14, aliasHandle, includeInherited: true)) != nullptr
             && (Alias->flags & 2) != 0) )
          {
            idList<idDeclMD6 const *,5>::AddUnique(
              this: (idList<idVoiceEvent const *,5> *)declList,
              obj: (const idVoiceEvent *const *)&v14);
            if ( declList->num == declList->size )
              break;
          }
          ptr = v10->ptr;
          ++v8;
          ++v12;
        }
        while ( v8 < v10->ptr->declRefs.num );
      }
    }
  }
}


// ========================================================================
// ?MakeDefault@idJointConversion@@SAXPBDABV?$idList@VidStr@@$04@@1@Z
// EA  : 0x82807080
// RVA : 0x00807080
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idJointConversion::MakeDefault(
        const char *filename,
        const idList<idStr,5> *jointNames,
        const idList<idStr,5> *userChannelNames)
{
  int size; // r11
  int num; // r30
  int v7; // r28
  int v8; // r29
  int v9; // r30
  int v10; // r11
  int v11; // r30
  bool v12; // cr56
  int v13; // r28
  int v14; // r29
  int v15; // r30
  _WORD v16[8]; // [sp+50h] [-1A0h] BYREF
  idJointConversion v17; // [sp+60h] [-190h] BYREF
  char v18[320]; // [sp+B0h] [-140h] BYREF

  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6jointconversion",
    a4: filename,
    a5: v18,
    a6: 256);
  idJointConversion::idJointConversion(this: &v17);
  size = v17.tableJoints.size;
  num = jointNames->num;
  v17.timestamp = -1;
  if ( num > v17.tableJoints.size )
  {
    if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                            this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *)&v17.tableJoints,
                            newsize: num) == 0 )
      goto LABEL_6;
    size = v17.tableJoints.size;
  }
  v17.tableJoints.num = num;
  if ( num >= size )
    v17.tableJoints.num = size;
LABEL_6:
  v7 = 0;
  if ( jointNames->num > 0 )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      ((void (__fastcall *)(_WORD *))animation->RegisterJoint)(a1: v16);
      ++v7;
      v9 += 32;
      v17.tableJoints.list[v8++].value = v16[0];
    }
    while ( v7 < jointNames->num );
  }
  v10 = v17.tableUserChannels.size;
  v11 = userChannelNames->num;
  v12 = v11 < v17.tableUserChannels.size;
  if ( v11 > v17.tableUserChannels.size )
  {
    if ( (unsigned __int8)idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                            this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *)&v17.tableUserChannels,
                            newsize: userChannelNames->num) == 0 )
      goto LABEL_14;
    v10 = v17.tableUserChannels.size;
    v12 = v11 < v17.tableUserChannels.size;
  }
  v17.tableUserChannels.num = v11;
  if ( !v12 )
    v17.tableUserChannels.num = v10;
LABEL_14:
  v13 = 0;
  if ( userChannelNames->num > 0 )
  {
    v14 = 0;
    v15 = 0;
    do
    {
      ((void (__fastcall *)(_WORD *))animation->RegisterUserChannel)(a1: v16);
      ++v13;
      v15 += 32;
      v17.tableUserChannels.list[v14++].value = v16[0];
    }
    while ( v13 < userChannelNames->num );
  }
  idJointConversion::GenerateChecksum(this: &v17);
  idJointConversion::WriteJointConversion_Binary(this: &v17, filename: v18);
  idJointConversion::~idJointConversion(this: &v17);
}


// ========================================================================
// __unwind$236366
// EA  : 0x8280723C
// RVA : 0x0080723C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236366()
{
  int v0; // r12

  idJointConversion::~idJointConversion(this: (idJointConversion *)(v0 - 496 + 96));
}


// ========================================================================
// ?LoadJointConversion_Binary@idJointConversion@@AAA_NPBD@Z
// EA  : 0x82807270
// RVA : 0x00807270
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

int __fastcall idJointConversion::LoadJointConversion_Binary(idJointConversion *this, const char *filename)
{
  idFile *v3; // r3
  idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5> *p_tableJoints; // r30
  int v6; // r26
  int v7; // r29
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *list; // r28
  int v9; // r4
  idList<idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,5> *p_tableUserChannels; // r28
  int v11; // r30
  char v12; // r3
  int size; // r11
  int v14; // r27
  int v15; // r30
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *v16; // r29
  int v17; // [sp+50h] [-B0h] BYREF
  idFileLocal v18; // [sp+54h] [-ACh] BYREF
  int v19; // [sp+58h] [-A8h] BYREF
  int v20; // [sp+5Ch] [-A4h] BYREF
  idStr v21; // [sp+60h] [-A0h] BYREF
  idStr v22[4]; // [sp+80h] [-80h] BYREF

  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: filename, a3: 1, a4: 0);
  v18.file = v3;
  if ( v3 != nullptr && (v3->Read(this: v3, a2: &v20, a3: 4u), v20 == 70666829) )
  {
    v18.file->Read(this: v18.file, a2: &this->timestamp, a3: 4u);
    v18.file->Read(this: v18.file, a2: &this->checksum, a3: 2u);
    v18.file->Read(this: v18.file, a2: &v19, a3: 4u);
    p_tableJoints = &this->tableJoints;
    idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5>::SetNum(
      this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *)&this->tableJoints,
      newNum: v19);
    v22[0].len = 0;
    v22[0].baseBuffer[0] = 0;
    v22[0].allocedAndFlag = 20;
    v22[0].data = v22[0].baseBuffer;
    v6 = 0;
    if ( v19 > 0 )
    {
      v7 = 0;
      do
      {
        idFile::ReadString(this: v18.file, string: v22);
        if ( v22[0].len != 0 )
        {
          list = p_tableJoints->list;
          list[v7] = *(idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((int (__fastcall *)(int *))animation->RegisterJoint)(a1: &v17);
        }
        else
        {
          p_tableJoints->list[v7].value = -1;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v19 );
    }
    v18.file->Read(this: v18.file, a2: &v19, a3: 4u);
    v9 = v19;
    p_tableUserChannels = &this->tableUserChannels;
    v11 = v19;
    if ( v19 <= this->tableUserChannels.size
      || (v12 = idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
                  this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *)&this->tableUserChannels,
                  newsize: v19),
          v9 = v19,
          v12 != 0) )
    {
      size = this->tableUserChannels.size;
      if ( v11 < size )
        size = v11;
      this->tableUserChannels.num = size;
    }
    v21.allocedAndFlag = 20;
    v21.len = 0;
    v21.data = v21.baseBuffer;
    v21.baseBuffer[0] = 0;
    v14 = 0;
    if ( v9 > 0 )
    {
      v15 = 0;
      do
      {
        idFile::ReadString(this: v18.file, string: &v21);
        if ( v21.len != 0 )
        {
          v16 = p_tableUserChannels->list;
          v16[v15] = *(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *)((int (__fastcall *)(int *))animation->RegisterUserChannel)(a1: &v17);
        }
        else
        {
          p_tableUserChannels->list[v15].value = -1;
        }
        ++v14;
        ++v15;
      }
      while ( v14 < v19 );
    }
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: v22);
    idFileLocal::~idFileLocal(this: &v18);
    return 1;
  }
  else
  {
    idFileLocal::~idFileLocal(this: &v18);
    return 0;
  }
}


// ========================================================================
// __unwind$236474
// EA  : 0x82807504
// RVA : 0x00807504
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236474()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 256 + 84));
}


// ========================================================================
// __unwind$236475
// EA  : 0x8280752C
// RVA : 0x0080752C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236475()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$236476
// EA  : 0x82807554
// RVA : 0x00807554
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236476()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?anim_verifySources_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82807588
// RVA : 0x00807588
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_verifySources_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idFileList *v2; // r3
  idFileList *v3; // r19
  int v4; // r14
  int v5; // r16
  int v6; // r15
  int v7; // r18
  const char *data; // r19
  int v9; // r5
  int v10; // r3
  const idStr *v11; // r3
  int v12; // r3
  const idStr *v13; // r3
  idFileList *v14; // [sp+5Ch] [-19D4h]
  int num; // [sp+64h] [-19CCh]
  idLexer v16; // [sp+70h] [-19C0h] BYREF
  idTokenStatic<256> v17; // [sp+100h] [-1930h] BYREF
  idStr v18; // [sp+250h] [-17E0h] BYREF
  idStr v19; // [sp+270h] [-17C0h] BYREF
  idTokenStatic<256> v20; // [sp+290h] [-17A0h] BYREF
  idToken v21; // [sp+3E0h] [-1650h] BYREF
  char v22; // [sp+428h] [-1608h] BYREF
  idTokenStatic<256> v23; // [sp+C30h] [-E00h] BYREF
  idTokenStatic<256> v24; // [sp+D80h] [-CB0h] BYREF
  idTokenStatic<256> v25; // [sp+ED0h] [-B60h] BYREF
  idTokenStatic<256> v26; // [sp+1020h] [-A10h] BYREF
  idStr v27; // [sp+1170h] [-8C0h] BYREF
  char v28; // [sp+1190h] [-8A0h] BYREF

  if ( args->argc == 2 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    v2 = fileSystem->ListFilesTree(this: fileSystem, a2: v1, a3: "md6anim", a4: 0);
    v3 = v2;
    v14 = v2;
    if ( v2 != nullptr && v2->list.num != 0 )
    {
      common->SetRefreshOnPrint(this: common, a2: true);
      v21.baseBuffer[0] = 0;
      v21.intvalue = 0;
      v21.floatvalue = -3.4028235e38;
      memset(&v21.whiteSpaceStart_p, 0, 12);
      v22 = 0;
      v21.len = 0;
      v21.data = &v22;
      v21.allocedAndFlag = -2147481600;
      v17.floatvalue = -3.4028235e38;
      v17.baseBuffer[0] = 0;
      v17.intvalue = 0;
      memset(&v17.whiteSpaceStart_p, 0, 13);
      v17.len = 0;
      v17.data = v17.buffer;
      v17.allocedAndFlag = -2147483392;
      v20.floatvalue = -3.4028235e38;
      v20.baseBuffer[0] = 0;
      v20.intvalue = 0;
      memset(&v20.whiteSpaceStart_p, 0, 13);
      v20.len = 0;
      v20.data = v20.buffer;
      v20.allocedAndFlag = -2147483392;
      v27.baseBuffer[0] = 0;
      v28 = 0;
      v27.len = 0;
      v27.data = &v28;
      v27.allocedAndFlag = -2147481600;
      v4 = 0;
      v5 = 0;
      v6 = 0;
      v7 = 0;
      while ( 1 )
      {
        num = v3->list.num;
        if ( v7 >= num )
        {
          idLib::Printf(fmt: "%d animations searched.\n", num);
          idLib::Printf(fmt: "%d missing meshes.\n", v5);
          idLib::Printf(fmt: "%d missing source anims.\n", v6);
          idLib::Printf(fmt: "%d bad anim versions.\n", v4);
          idFileList::~idFileList(this: v3);
          idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
          common->SetRefreshOnPrint(this: common, a2: false);
          idStr::FreeData(this: &v27);
          idStr::FreeData(this: &v20);
          idStr::FreeData(this: &v17);
          idStr::FreeData(this: &v21);
          return;
        }
        data = v3->list.list[v7].data;
        idLexer::idLexer(this: &v16, flags_: 0);
        if ( !idLexer::LoadFile(this: &v16, filename_: data, OSPath: false) )
          break;
        idStr::EnsureAlloced(this: &v17, amount: 1, keepold: true, geometricGrowth: false);
        *v17.data = 0;
        v17.len = 0;
        idLexer::ExpectTokenString(this: &v16, string: MD6_VERSION_STRING);
        v9 = idLexer::ParseInt(this: &v16);
        if ( v9 == 7 )
        {
          idLexer::ExpectTokenString(this: &v16, string: "init");
          idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 46, token: &v21);
          while ( idLexer::ReadToken(this: &v16, token: &v21) && (v21.type != 5 || v21.subtype != 47) )
          {
            if ( idStr::Icmp(s1: v21.data, s2: "meshName") != 0 )
            {
              if ( idStr::Icmp(s1: v21.data, s2: "sourceAnim") != 0 )
              {
                idLexer::ParseRestOfLine(this: &v16, out: &v27);
              }
              else
              {
                idLexer::ExpectTokenType(this: &v16, type: 1, subtype: 0, token: &v21);
                idStr::BackSlashesToSlashes(this: &v21);
                idStr::ToLower(this: &v21);
                v12 = idStr::Find(
                        searchIn: v21.data,
                        searchFor: "rage/base/",
                        casesensitive: true,
                        start: 0,
                        end: v21.len);
                if ( v12 == -1 )
                {
                  idTokenStatic<256>::idTokenStatic<256>(this: &v24, text: &v21);
                  idTokenStatic<256>::operator=(this: &v20, __that: &v24);
                  idStr::FreeData(this: &v24);
                }
                else
                {
                  v13 = idStr::Mid(this: &v19, result: &v21, start: v12 + 10, len: v21.len - v12 + 10);
                  idTokenStatic<256>::idTokenStatic<256>(this: &v26, text: v13);
                  idTokenStatic<256>::operator=(this: &v20, __that: &v26);
                  idStr::FreeData(this: &v26);
                  idStr::FreeData(this: &v19);
                }
              }
            }
            else
            {
              idLexer::ExpectTokenType(this: &v16, type: 1, subtype: 0, token: &v21);
              idStr::BackSlashesToSlashes(this: &v21);
              idStr::ToLower(this: &v21);
              v10 = idStr::Find(
                      searchIn: v21.data,
                      searchFor: "rage/base/",
                      casesensitive: true,
                      start: 0,
                      end: v21.len);
              if ( v10 == -1 )
              {
                idTokenStatic<256>::idTokenStatic<256>(this: &v25, text: &v21);
                idTokenStatic<256>::operator=(this: &v17, __that: &v25);
                idStr::FreeData(this: &v25);
              }
              else
              {
                v11 = idStr::Mid(this: &v18, result: &v21, start: v10 + 10, len: v21.len - v10 + 10);
                idTokenStatic<256>::idTokenStatic<256>(this: &v23, text: v11);
                idTokenStatic<256>::operator=(this: &v17, __that: &v23);
                idStr::FreeData(this: &v23);
                idStr::FreeData(this: &v18);
              }
            }
          }
          if ( v17.len == 0 )
          {
            idLib::Warning(fmt: "No meshName entry was found in '%s'", data);
            idLexer::~idLexer(this: &v16);
            idStr::FreeData(this: &v27);
            idStr::FreeData(this: &v20);
            idStr::FreeData(this: &v17);
            idStr::FreeData(this: &v21);
            return;
          }
          if ( !fileSystem->FileExists(this: fileSystem, a2: v20.data, a3: false) )
          {
            idLib::Warning(fmt: "Missing source anim '%s' in anim '%s'", v20.data, data);
            ++v6;
          }
          if ( !fileSystem->FileExists(this: fileSystem, a2: v17.data, a3: false) )
          {
            idLib::Warning(fmt: "Missing mesh '%s' in anim '%s'", v17.data, data);
            ++v5;
          }
LABEL_33:
          idLexer::~idLexer(this: &v16);
          ++v7;
          v3 = v14;
        }
        else
        {
          idLib::Warning(fmt: "File '%s' has incorrect version. Got %d, expected %d", data, v9, 7);
          ++v4;
          idLexer::~idLexer(this: &v16);
          ++v7;
          v3 = v14;
        }
      }
      idLib::Warning(fmt: "Failed to load file '%s'", data);
      goto LABEL_33;
    }
    idLib::Printf(fmt: "No files found.\n");
  }
  else
  {
    idLib::Printf(fmt: "USAGE: anim_verifyMeshes <path>\n");
  }
}


// ========================================================================
// $M237425_0
// EA  : 0x82807C98
// RVA : 0x00807C98
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M237425_0()
{
  idLib::Warning(fmt: "Unknown error parsing .md6mesh file");
  return &_LN42_1;
}


// ========================================================================
// __unwind$236722
// EA  : 0x82807CC8
// RVA : 0x00807CC8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236722()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 992));
}


// ========================================================================
// __unwind$236723
// EA  : 0x82807CF0
// RVA : 0x00807CF0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236723()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 256));
}


// ========================================================================
// __unwind$236724
// EA  : 0x82807D18
// RVA : 0x00807D18
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 656));
}


// ========================================================================
// __unwind$236725
// EA  : 0x82807D40
// RVA : 0x00807D40
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 4464));
}


// ========================================================================
// __unwind$236726
// EA  : 0x82807D68
// RVA : 0x00807D68
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236726()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 6704 + 112));
}


// ========================================================================
// __unwind$236727
// EA  : 0x82807D90
// RVA : 0x00807D90
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236727()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 592));
}


// ========================================================================
// __unwind$236728
// EA  : 0x82807DB8
// RVA : 0x00807DB8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236728()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 3120));
}


// ========================================================================
// __unwind$236729
// EA  : 0x82807DE0
// RVA : 0x00807DE0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236729()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 3792));
}


// ========================================================================
// __unwind$236730
// EA  : 0x82807E08
// RVA : 0x00807E08
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236730()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 624));
}


// ========================================================================
// __unwind$236731
// EA  : 0x82807E30
// RVA : 0x00807E30
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236731()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 4128));
}


// ========================================================================
// __unwind$236732
// EA  : 0x82807E58
// RVA : 0x00807E58
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_236732()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6704 + 3456));
}


// ========================================================================
// ?MakeDefaultJointConversion@idAnimationLocal@@UAAXPBDABV?$idList@VidStr@@$04@@1@Z
// EA  : 0x82808118
// RVA : 0x00808118
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::MakeDefaultJointConversion(
        idAnimationLocal *this,
        char *jointConversion,
        const idList<idStr,5> *jointNames,
        const idList<idStr,5> *userChannelsNames)
{
  idResource *Existing; // r3

  idJointConversion::MakeDefault(filename: jointConversion, jointNames, userChannelNames: userChannelsNames);
  Existing = idResourceList::FindExisting(
               this: &idJointConversion::resourceList,
               name: jointConversion,
               skipStaleCheck: true);
  if ( Existing != nullptr )
    Existing->LoadResource(this: Existing);
}


// ========================================================================
// ?AddStrongAliasRef@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82808180
// RVA : 0x00808180
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::AddStrongAliasRef(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const char *aliasName)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v6[4]; // [sp+50h] [-20h] BYREF

  if ( aliasName != nullptr && *aliasName != 0 )
  {
    (*(void (__fastcall **)(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, idHandle<unsigned short,enum invalidAliasHandle_t,65535> *, _DWORD, const char *))(*(_DWORD *)&result->value + 96))(
      a1: v6,
      a2: result,
      a3: 0,
      a4: aliasName);
    idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,30>::AddUnique(
      this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,30> *)&result[110],
      obj: v6);
    HIWORD(this->__vftable) = v6[0];
  }
  else
  {
    HIWORD(this->__vftable) = -1;
  }
  return this;
}


// ========================================================================
// ?StrongLoadAlias@idAnimationLocal@@UAAPBVidMD6Alias@@PBVidDeclMD6@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x82808210
// RVA : 0x00808210
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

const idMD6Alias *__fastcall idAnimationLocal::StrongLoadAlias(
        idAnimationLocal *this,
        const idDeclMD6 *decl,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  unsigned __int64 v9; // r6
  const char *v10; // r7
  int value; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v12; // r29
  unsigned __int64 v13; // r6
  const char *v14; // r7
  idMD6Alias *Alias; // r30
  const char *data; // r4
  unsigned __int64 v17; // r6
  const char *v18; // r7
  int v19; // [sp+50h] [-60h] BYREF
  idPLogScope v20; // [sp+58h] [-58h] BYREF
  idPLogScope v21[10]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "idAnimationLocal::StrongLoadAlias");
  LODWORD(v6) = "idAnimationLocal::StrongLoadAlias";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &pLog, gMask: v6, label: v7);
  if ( decl != nullptr )
  {
    RD_EventBegin(name: "idAnimationLocal::StrongLoadAlias - FindEntry");
    LODWORD(v9) = "idAnimationLocal::StrongLoadAlias - FindEntry";
    HIDWORD(v9) = 2;
    idPLogScope::idPLogScope(this: v21, pl: &pLog, gMask: v9, label: v10);
    value = aliasHandle->value;
    if ( value == 0xFFFF || value >= this->aliasHash.list.num )
    {
      v12 = nullptr;
    }
    else
    {
      v12 = &this->aliasHash.list.list[value];
      if ( v12 != nullptr )
        this->RegisterAlias(
          this: (struct idAnimationLocal *)&v19,
          result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)this,
          a3: decl,
          a4: v12->name.data);
    }
    idPLogScope::~idPLogScope(this: v21);
    RD_EventEnd();
    RD_EventBegin(name: "idAnimationLocal::StrongLoadAlias - Find Alias");
    LODWORD(v13) = "idAnimationLocal::StrongLoadAlias - Find Alias";
    HIDWORD(v13) = 2;
    idPLogScope::idPLogScope(this: v21, pl: &pLog, gMask: v13, label: v14);
    Alias = (idMD6Alias *)idDeclMD6::FindAlias(this: decl, aliasHandle, includeInherited: true);
    if ( Alias != nullptr )
    {
      idPLogScope::~idPLogScope(this: v21);
      RD_EventEnd();
      RD_EventBegin(name: "idAnimationLocal::StrongLoadAlias - LoadAnims");
      LODWORD(v17) = "idAnimationLocal::StrongLoadAlias - LoadAnims";
      HIDWORD(v17) = 2;
      idPLogScope::idPLogScope(this: v21, pl: &pLog, gMask: v17, label: v18);
      idMD6Alias::LoadAnims(this: Alias, decl);
      idPLogScope::~idPLogScope(this: v21);
      RD_EventEnd();
      idPLogScope::~idPLogScope(this: &v20);
      RD_EventEnd();
      return Alias;
    }
    else
    {
      if ( v12 != nullptr )
        data = v12->name.data;
      else
        data = "NULL";
      idLib::Warning(fmt: "StrongLoadAlias - alias '%s' not in modelDef '%s'", data, decl->name.str);
      idPLogScope::~idPLogScope(this: v21);
      RD_EventEnd();
      idPLogScope::~idPLogScope(this: &v20);
      RD_EventEnd();
      return nullptr;
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v20);
    RD_EventEnd();
    return nullptr;
  }
}


// ========================================================================
// __unwind$237883
// EA  : 0x828083E4
// RVA : 0x008083E4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237883()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$237884
// EA  : 0x8280840C
// RVA : 0x0080840C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237884()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$237885
// EA  : 0x82808434
// RVA : 0x00808434
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237885()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 105));
}


// ========================================================================
// __unwind$237886
// EA  : 0x8280845C
// RVA : 0x0080845C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237886()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$237887
// EA  : 0x82808484
// RVA : 0x00808484
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237887()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 106));
}


// ========================================================================
// __unwind$237888
// EA  : 0x828084AC
// RVA : 0x008084AC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237888()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$237889
// EA  : 0x828084D4
// RVA : 0x008084D4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237889()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 107));
}


// ========================================================================
// __unwind$237890
// EA  : 0x828084FC
// RVA : 0x008084FC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_237890()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// ?LoadResource@idJointConversion@@UAAXXZ
// EA  : 0x82808528
// RVA : 0x00808528
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idJointConversion::LoadResource(idJointConversion *this)
{
  char v2[256]; // [sp+50h] [-110h] BYREF

  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bmd6jointconversion",
    a4: this->name.str,
    a5: v2,
    a6: 256);
  if ( (unsigned __int8)idJointConversion::LoadJointConversion_Binary(this, filename: v2) == 0
    && (unsigned __int8)idJointConversion::LoadJointConversion_Text(this) != 0 )
  {
    idJointConversion::WriteJointConversion_Binary(this, filename: v2);
  }
}


// ========================================================================
// ?FreeDynamic@idAnimationLocal@@UAAXXZ
// EA  : 0x828091E0
// RVA : 0x008091E0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::FreeDynamic(idAnimationLocal *this)
{
  int num; // r9

  if ( !markStaticDone )
  {
    num = this->jointHash.list.num;
    markStaticDone = true;
    this->jointHash.markStaticNum = num;
    this->userChannelHash.markStaticNum = this->userChannelHash.list.num;
    this->aliasHash.markStaticNum = this->aliasHash.list.num;
    this->jointConversionHash.markStaticNum = this->jointConversionHash.list.num;
  }
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::FreeDynamic(this: (idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *)&this->jointHash);
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId>>::FreeDynamic(this: &this->userChannelHash);
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::FreeDynamic(this: &this->aliasHash);
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::FreeDynamic(this: &this->jointConversionHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->strongAliasRefs);
}


// ========================================================================
// ?Shutdown@idAnimationLocal@@UAAXXZ
// EA  : 0x82809268
// RVA : 0x00809268
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::Shutdown(idAnimationLocal *this)
{
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::Free(this: (idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *)&this->jointHash);
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::Free(this: &this->userChannelHash);
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Free(this: &this->aliasHash);
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Free(this: &this->jointConversionHash);
}


// ========================================================================
// ?UnregisterAlias@idAnimationLocal@@UAAXPBVidDeclMD6@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x828092B0
// RVA : 0x008092B0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::UnregisterAlias(
        idAnimationLocal *this,
        const idDeclMD6 *decl,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle)
{
  int value; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *p_aliasHash; // r3
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v5; // r6
  _DWORD *v6; // r9
  int v7; // r7
  int v8; // r11
  int v9; // r10
  int v10; // r10
  int v11; // r10

  value = aliasHandle->value;
  p_aliasHash = &this->aliasHash;
  if ( value != 0xFFFF && value < p_aliasHash->list.num )
  {
    v5 = (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&p_aliasHash->list.list[value];
    if ( v5 != nullptr )
    {
      v6 = *(_DWORD **)&v5->value;
      if ( *(_DWORD *)&v5->value != 0 )
      {
        v7 = v6[1];
        v8 = 0;
        if ( v7 > 0 )
        {
          v9 = 0;
          while ( *(const idDeclMD6 **)(v9 + *v6) != decl )
          {
            ++v8;
            v9 += 4;
            if ( v8 >= v7 )
              goto LABEL_14;
          }
          if ( v8 >= 0 )
          {
            v10 = v6[1];
            if ( v8 < v10 )
            {
              v11 = v10 - 1;
              v6[1] = v11;
              if ( v8 != v11 )
                *(_DWORD *)(4 * v8 + *v6) = *(_DWORD *)(4 * v11 + *v6);
            }
          }
        }
LABEL_14:
        if ( *(_DWORD *)(*(_DWORD *)&v5->value + 4) == 0 )
          idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Remove(
            this: p_aliasHash,
            handle: v5 + 22);
      }
    }
  }
}


// ========================================================================
// ?UnregisterAliases@idAnimationLocal@@UAAXPBVidDeclMD6@@@Z
// EA  : 0x82809380
// RVA : 0x00809380
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall idAnimationLocal::UnregisterAliases(idAnimationLocal *this, const idDeclMD6 *decl)
{
  int v3; // r29
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *p_aliasHash; // r30
  int v5; // r31
  unsigned __int16 *v6; // r6
  _DWORD *v7; // r9
  int v8; // r7
  int v9; // r11
  int v10; // r10
  int v11; // r10
  int v12; // r10
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v13; // [sp+50h] [-30h] BYREF

  v3 = this->aliasHash.list.num - 1;
  if ( v3 >= 0 )
  {
    p_aliasHash = &this->aliasHash;
    v5 = v3;
    do
    {
      v6 = (unsigned __int16 *)&p_aliasHash->list.list[v5];
      if ( v6 != nullptr )
      {
        v7 = *(_DWORD **)v6;
        if ( *(_DWORD *)v6 != 0 )
        {
          v8 = v7[1];
          v9 = 0;
          if ( v8 > 0 )
          {
            v10 = 0;
            while ( decl != *(const idDeclMD6 **)(v10 + *v7) )
            {
              ++v9;
              v10 += 4;
              if ( v9 >= v8 )
                goto LABEL_16;
            }
            if ( v9 >= 0 )
            {
              v11 = v7[1];
              if ( v9 < v11 )
              {
                v12 = v11 - 1;
                v7[1] = v12;
                if ( v9 != v12 )
                  *(_DWORD *)(4 * v9 + *v7) = *(_DWORD *)(4 * v12 + *v7);
              }
            }
            if ( *(_DWORD *)(*(_DWORD *)v6 + 4) == 0 )
            {
              v13.value = v6[22];
              idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Remove(
                this: p_aliasHash,
                handle: &v13);
            }
          }
        }
      }
LABEL_16:
      --v3;
      --v5;
    }
    while ( v3 >= 0 );
  }
}


// ========================================================================
// ?anim_genScripts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82809470
// RVA : 0x00809470
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __fastcall anim_genScripts_f(const idCmdArgs *args)
{
  int argc; // r11
  idStr *list; // r29
  int v4; // r30
  const char **v5; // r29
  int v6; // r28
  char *v7; // r10
  const char *v8; // r3
  const char *v9; // r3
  char *v10; // r3
  const char *v11; // r3
  char *v12; // r3
  char *v13; // r4
  char *v14; // r3
  char *v15; // r4
  int num; // r21
  unsigned __int8 listStatic; // r20
  idRemap *v18; // r19
  int size; // r18
  double v20; // fp31
  idRemap *v21; // r30
  size_t len; // r28
  idStr *p_replace; // r29
  idStr *v24; // r3
  size_t v25; // r30
  const char *v26; // r4
  const char *v27; // r4
  idRemap *v28; // r30
  idStr *v29; // r25
  int v30; // r24
  idStr *v31; // r23
  int v32; // r27
  idFile *v33; // r3
  idFile *v34; // r30
  idFileSystem **v35; // r26
  int v36; // r25
  idRemap *v37; // r24
  int v38; // r27
  idStr *v39; // r30
  int v40; // r29
  int v41; // r4
  char *v42; // r10
  char *v43; // r9
  char v44; // r11
  const char *v45; // r28
  const char *v46; // r23
  int v47; // r30
  int v48; // r3
  int v49; // r30
  int v50; // r8
  int v51; // r30
  int v52; // r30
  _BYTE *v53; // r23
  char v54; // r28
  int i; // r30
  idRemap *v56; // r29
  int v57; // r30
  int v58; // r3
  int v59; // r30
  int v60; // r30
  char *data; // r11
  char *v62; // r10
  char v63; // r9
  __int64 v64; // r10
  __int64 v65; // r8
  __int64 v66; // r6
  va *v67; // r3
  va *v68; // r29
  size_t j; // r30
  const char *v70; // r3
  idToken *v71; // r27
  int v72; // r24
  int v73; // r26
  char v74; // r25
  int v75; // r28
  int k; // r30
  const idStr *v77; // r30
  const char *v78; // r3
  const char *v79; // r3
  int v80; // r11
  int v81; // r10
  int v82; // r11
  int v83; // r10
  int v84; // r10
  idFile *v85; // r29
  int m; // r30
  idFile *v87; // r30
  idStr *v88; // r28
  int v89; // r30
  idStr *v90; // r29
  idStr *v91; // r28
  int v92; // r30
  idStr *v93; // r29
  idStr *v94; // r29
  int n; // r30
  int v96; // r30
  idStr *v97; // r29
  idFileList *v98; // r3
  idFileList *v99; // r30
  int v100; // r28
  int v101; // r29
  int v102; // [sp+8h] [-1D78h]
  int v103; // [sp+Ch] [-1D74h]
  int v104; // [sp+10h] [-1D70h]
  int v105; // [sp+14h] [-1D6Ch]
  int v106; // [sp+18h] [-1D68h]
  int v107; // [sp+1Ch] [-1D64h]
  char v108; // [sp+50h] [-1D30h]
  char v109; // [sp+5Ch] [-1D24h]
  idStr v110; // [sp+70h] [-1D10h] BYREF
  const char *v111; // [sp+90h] [-1CF0h]
  const char **v112; // [sp+94h] [-1CECh]
  const char **v113; // [sp+98h] [-1CE8h]
  idStr v114; // [sp+A0h] [-1CE0h] BYREF
  idList<idStr,5> v115; // [sp+C0h] [-1CC0h] BYREF
  int v116; // [sp+D0h] [-1CB0h]
  const char *v117; // [sp+D4h] [-1CACh]
  const char *v118; // [sp+D8h] [-1CA8h]
  idMem *v119; // [sp+DCh] [-1CA4h]
  idFileSystem **v120; // [sp+E0h] [-1CA0h]
  idFile *v121; // [sp+E4h] [-1C9Ch]
  int v122; // [sp+E8h] [-1C98h]
  const char *v123; // [sp+ECh] [-1C94h]
  idList<idToken,5> v124; // [sp+F0h] [-1C90h] BYREF
  idList<idStr,5> v125; // [sp+100h] [-1C80h] BYREF
  idList<idRemap,5> v126; // [sp+110h] [-1C70h] BYREF
  int v127; // [sp+120h] [-1C60h]
  idToken *v128; // [sp+128h] [-1C58h]
  int v129; // [sp+130h] [-1C50h]
  char *v130; // [sp+134h] [-1C4Ch]
  int v131; // [sp+138h] [-1C48h]
  const char *v132; // [sp+13Ch] [-1C44h]
  const char **v133; // [sp+140h] [-1C40h]
  idToken v134; // [sp+150h] [-1C30h] BYREF
  const char *v135; // [sp+198h] [-1BE8h]
  const char *v136; // [sp+19Ch] [-1BE4h]
  const char *v137; // [sp+1A0h] [-1BE0h]
  const char *v138; // [sp+1A4h] [-1BDCh]
  const char *v139; // [sp+1A8h] [-1BD8h]
  const char *v140; // [sp+1ACh] [-1BD4h]
  const char *v141; // [sp+1B0h] [-1BD0h]
  const char *v142; // [sp+1B4h] [-1BCCh]
  const char *v143; // [sp+1B8h] [-1BC8h]
  const char *v144; // [sp+1BCh] [-1BC4h]
  char *v145; // [sp+1C0h] [-1BC0h]
  const char *v146; // [sp+1C4h] [-1BBCh]
  const char *v147; // [sp+1C8h] [-1BB8h]
  const char *v148; // [sp+1CCh] [-1BB4h]
  const char *v149; // [sp+1D0h] [-1BB0h]
  const char *v150; // [sp+1D4h] [-1BACh]
  char *v151; // [sp+1D8h] [-1BA8h]
  const char *v152; // [sp+1DCh] [-1BA4h]
  const char *v153; // [sp+1E0h] [-1BA0h]
  const char *v154; // [sp+1E4h] [-1B9Ch]
  const char *v155; // [sp+1E8h] [-1B98h]
  const char *v156; // [sp+1ECh] [-1B94h]
  const char *v157; // [sp+1F0h] [-1B90h]
  idStr v158; // [sp+200h] [-1B80h] BYREF
  idStr v159; // [sp+220h] [-1B60h] BYREF
  idStr v160; // [sp+240h] [-1B40h] BYREF
  idStr v161; // [sp+260h] [-1B20h] BYREF
  idStr v162; // [sp+280h] [-1B00h] BYREF
  idStr v163; // [sp+2A0h] [-1AE0h] BYREF
  idStr v164; // [sp+2C0h] [-1AC0h] BYREF
  idStr v165; // [sp+2E0h] [-1AA0h] BYREF
  idStr v166; // [sp+300h] [-1A80h] BYREF
  idStr v167; // [sp+320h] [-1A60h] BYREF
  idStr v168; // [sp+340h] [-1A40h] BYREF
  idToken v169; // [sp+360h] [-1A20h] BYREF
  idStr v170; // [sp+3D0h] [-19B0h] BYREF
  idToken v171; // [sp+3F0h] [-1990h] BYREF
  idToken v172; // [sp+440h] [-1940h] BYREF
  idToken v173; // [sp+490h] [-18F0h] BYREF
  idToken v174; // [sp+4E0h] [-18A0h] BYREF
  idStr v175; // [sp+530h] [-1850h] BYREF
  idStr v176; // [sp+550h] [-1830h] BYREF
  idStr v177; // [sp+570h] [-1810h] BYREF
  idStr v178; // [sp+590h] [-17F0h] BYREF
  idLexer v179; // [sp+5B0h] [-17D0h] BYREF
  idParser v180; // [sp+6B0h] [-16D0h] BYREF
  char v181[256]; // [sp+940h] [-1440h] BYREF
  idParser v182; // [sp+A40h] [-1340h] BYREF
  va v183; // [sp+CD0h] [-10B0h] BYREF

  argc = args->argc;
  if ( args->argc == 1 )
  {
ShowHelp:
    idLib::Printf(fmt: "anim_genScripts [options] -script <script file name> -path <path name>\n");
    idLib::Printf(
      fmt: "Recurses the given directory, generating a .MEL export scripts for all Maya-exported meshes and animations found.\n");
    idLib::Printf(fmt: "Valid options:\n");
    idLib::Printf(
      fmt: "  -noframes : ignores -startFrame and -endFrame switches on anim commandline (uses the default in the Maya file.)\n");
    idLib::Printf(fmt: "  -namespace <namespace> : specifies the namespace to use when filtering joints for an animation export.\n");
    idLib::Printf(fmt: "  -script <script file name> : specifies the name of the file to output the MEL script to\n");
    idLib::Printf(fmt: "  -path <path name> : specifies the name of a path to process. Multiple -path parameters can be specified.\n");
    return;
  }
  v109 = 0;
  v159.allocedAndFlag = 20;
  v159.data = v159.baseBuffer;
  v159.len = 0;
  v108 = 0;
  v159.baseBuffer[0] = 0;
  v160.allocedAndFlag = 20;
  v160.data = v160.baseBuffer;
  v160.len = 0;
  v160.baseBuffer[0] = 0;
  list = nullptr;
  *(_WORD *)&v115.memTag = 1280;
  memset(&v115, 0, 14);
  v162.allocedAndFlag = 20;
  v162.data = v162.baseBuffer;
  v162.len = 0;
  v162.baseBuffer[0] = 0;
  v4 = 1;
  if ( argc <= 1 )
  {
LABEL_338:
    idLib::Warning(fmt: "Both a script file name and an animation source path must be specified.");
    idStr::FreeData(this: &v162);
    if ( (v115.listStatic == 0 || v115.listStatic == 2) && list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: v115.size);
LABEL_342:
    idStr::FreeData(this: &v160);
LABEL_343:
    idStr::FreeData(this: &v159);
    goto ShowHelp;
  }
  v5 = (const char **)&args->argv[1];
  v6 = 2;
  v130 = &byte_8200D768;
  while ( 1 )
  {
    if ( v4 < 0 || v4 >= argc )
      v7 = &byte_8200D768;
    else
      v7 = (char *)*v5;
    if ( *v7 != 45 )
    {
      if ( v4 < 0 || v4 >= argc )
        v27 = &byte_8200D768;
      else
        v27 = args->argv[v4];
      idLib::Warning(fmt: "Error on command line: unknown token '%s'", v27);
      idStr::FreeData(this: &v162);
      if ( (v115.listStatic == 0 || v115.listStatic == 2) && v115.list != nullptr )
        idListArrayDelete<idStr>(ptr: v115.list, num: v115.size);
      goto LABEL_342;
    }
    if ( v4 < 0 || v4 >= argc )
      v8 = &byte_8200D768;
    else
      v8 = *v5;
    if ( idStr::Icmp(s1: v8, s2: "-noFrames") == 0 )
    {
      v109 = 1;
      goto LABEL_63;
    }
    if ( v4 < 0 || v4 >= args->argc )
      v9 = &byte_8200D768;
    else
      v9 = *v5;
    if ( idStr::Icmp(s1: v9, s2: "-remap") == 0 )
    {
      ++v4;
      ++v6;
      ++v5;
      if ( v4 >= args->argc )
      {
        idLib::Warning(fmt: "Error: no file name specified after -remap.");
        idStr::FreeData(this: &v162);
        idList<idStr,99>::~idList<idStr,99>(this: &v115);
        idStr::FreeData(this: &v160);
        goto LABEL_343;
      }
      if ( v4 < 0 || v4 >= args->argc )
        idStr::operator=(this: &v160, text: &byte_8200D768);
      else
        idStr::operator=(this: &v160, text: *v5);
      goto LABEL_63;
    }
    if ( v4 < 0 || v4 >= args->argc )
      v10 = &byte_8200D768;
    else
      v10 = (char *)*v5;
    if ( idStr::Icmp(s1: v10, s2: "-namespace") == 0 )
    {
      if ( v6 >= args->argc )
        goto LABEL_64;
      ++v4;
      ++v6;
      ++v5;
      if ( v4 < 0 || v4 >= args->argc )
        idStr::operator=(this: &v162, text: &byte_8200D768);
      else
        idStr::operator=(this: &v162, text: *v5);
      goto LABEL_63;
    }
    v11 = v4 < 0 || v4 >= args->argc ? &byte_8200D768 : *v5;
    if ( idStr::Icmp(s1: v11, s2: "-errorsOnly") != 0 )
      break;
    v108 = 1;
LABEL_63:
    argc = args->argc;
    ++v4;
    ++v6;
    ++v5;
    if ( v4 >= args->argc )
      goto LABEL_64;
  }
  if ( v4 < 0 || v4 >= args->argc )
    v12 = &byte_8200D768;
  else
    v12 = (char *)*v5;
  if ( idStr::Icmp(s1: v12, s2: "-path") == 0 )
  {
    if ( v6 >= args->argc )
      goto LABEL_64;
    ++v4;
    ++v6;
    ++v5;
    if ( v4 < 0 || v4 >= args->argc )
      v13 = &byte_8200D768;
    else
      v13 = (char *)*v5;
    idStr::idStr(this: &v178, text: v13);
    idList<idStr,5>::Append(this: &v115, obj: &v178);
    idStr::FreeData(this: &v178);
    goto LABEL_63;
  }
  if ( v4 < 0 || v4 >= args->argc )
    v14 = &byte_8200D768;
  else
    v14 = (char *)*v5;
  if ( idStr::Icmp(s1: v14, s2: "-script") != 0 )
  {
    if ( v4 < 0 || v4 >= args->argc )
      v26 = &byte_8200D768;
    else
      v26 = args->argv[v4];
    idLib::Warning(fmt: "Unknown option '%s'", v26);
    idStr::FreeData(this: &v162);
    idList<idStr,99>::~idList<idStr,99>(this: &v115);
    idStr::FreeData(this: &v160);
    goto LABEL_343;
  }
  if ( v6 < args->argc )
  {
    ++v4;
    ++v6;
    ++v5;
    if ( v4 < 0 || v4 >= args->argc )
      v15 = &byte_8200D768;
    else
      v15 = (char *)*v5;
    idStr::operator=(this: &v159, text: v15);
    idStr::SetFileExtension(this: &v159, extension: ".mel");
    goto LABEL_63;
  }
LABEL_64:
  if ( v159.len == 0 || (num = v115.num, v115.num <= 0) )
  {
    list = v115.list;
    goto LABEL_338;
  }
  listStatic = 0;
  v18 = nullptr;
  size = 0;
  *(_WORD *)&v126.memTag = 1280;
  memset(&v126, 0, 14);
  if ( v160.len != 0 )
  {
    idLexer::idLexer(this: &v179, flags_: 262704);
    if ( idLexer::LoadFile(this: &v179, filename_: v160.data, OSPath: false) )
    {
      v169.allocedAndFlag = 20;
      v169.len = 0;
      v169.data = v169.baseBuffer;
      v169.baseBuffer[0] = 0;
      v169.intvalue = 0;
      memset(&v169.whiteSpaceStart_p, 0, 12);
      v20 = -3.4028235e38;
      v169.floatvalue = -3.4028235e38;
      idLexer::ExpectTokenType(this: &v179, type: 5, subtype: 46, token: &v169);
      while ( idLexer::ReadToken(this: &v179, token: &v169) && (v169.type != 5 || v169.subtype != 47) )
      {
        if ( idStr::Cmp(s1: v169.data, s2: "remap") != 0 )
        {
          if ( idStr::Cmp(s1: v169.data, s2: "exclude") == 0 )
          {
            idLexer::ExpectTokenType(this: &v179, type: 5, subtype: 46, token: &v169);
            v174.floatvalue = -3.4028235e38;
            v174.allocedAndFlag = 20;
            v174.data = v174.baseBuffer;
            v174.len = 0;
            v174.baseBuffer[0] = 0;
            v174.intvalue = 0;
            memset(&v174.whiteSpaceStart_p, 0, 12);
            idLexer::ExpectTokenType(this: &v179, type: 1, subtype: 0, token: &v174);
            idLexer::ExpectTokenType(this: &v179, type: 5, subtype: 47, token: &v169);
            v28 = idList<idRemap,5>::Alloc(this: &v126);
            idStr::operator=(this: &v28->match, text: &v174);
            v28->exclude = true;
            idStr::FreeData(this: &v174);
          }
        }
        else
        {
          idLexer::ExpectTokenType(this: &v179, type: 5, subtype: 46, token: &v169);
          v173.floatvalue = -3.4028235e38;
          v173.allocedAndFlag = 20;
          v173.data = v173.baseBuffer;
          v173.len = 0;
          v173.baseBuffer[0] = 0;
          v173.intvalue = 0;
          memset(&v173.whiteSpaceStart_p, 0, 12);
          v171.floatvalue = -3.4028235e38;
          v171.allocedAndFlag = 20;
          v171.data = v171.baseBuffer;
          v171.len = 0;
          v171.baseBuffer[0] = 0;
          v171.intvalue = 0;
          memset(&v171.whiteSpaceStart_p, 0, 12);
          idLexer::ExpectTokenType(this: &v179, type: 1, subtype: 0, token: &v173);
          idLexer::ExpectTokenType(this: &v179, type: 1, subtype: 0, token: &v171);
          idLexer::ExpectTokenType(this: &v179, type: 5, subtype: 47, token: &v169);
          v21 = idList<idRemap,5>::Alloc(this: &v126);
          len = v173.len;
          idStr::EnsureAlloced(this: &v21->match, amount: v173.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v21->match.data, Src: v173.data, Size: len);
          p_replace = &v21->replace;
          v24 = &v21->replace;
          v21->match.data[len] = 0;
          v21->match.len = len;
          v25 = v171.len;
          idStr::EnsureAlloced(this: v24, amount: v171.len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: p_replace->data, Src: v171.data, Size: v25);
          p_replace->data[v25] = 0;
          p_replace->len = v25;
          idStr::FreeData(this: &v171);
          idStr::FreeData(this: &v173);
        }
      }
      idStr::FreeData(this: &v169);
    }
    else
    {
      idLib::Warning(fmt: "Failed to load remap file '%s'", v160.data);
      v20 = -3.4028235e38;
    }
    idLexer::~idLexer(this: &v179);
    listStatic = v126.listStatic;
    size = v126.size;
    v18 = v126.list;
  }
  else
  {
    v20 = -3.4028235e38;
  }
  idStr::idStr(this: &v175, text: ".md6mesh|.md6anim");
  v29 = nullptr;
  v30 = 0;
  *(_WORD *)&v125.memTag = 1280;
  memset(&v125, 0, 14);
  v31 = v115.list;
  v32 = 0;
  v120 = &fileSystem;
  while ( v32 < num )
  {
    v98 = fileSystem->ListFilesTree(this: fileSystem, a2: v31[v32].data, a3: v175.data, a4: 0);
    v99 = v98;
    if ( v98 != nullptr )
    {
      v100 = 0;
      if ( v98->list.num > 0 )
      {
        v101 = 0;
        do
        {
          idStr::idStr(this: &v177, text: v99->list.list[v101].data);
          if ( idList<idStr,5>::FindIndex(this: &v125, obj: &v177, startIndex: 0) < 0 )
            idList<idStr,5>::Append(this: &v125, obj: &v177);
          idStr::FreeData(this: &v177);
          ++v100;
          ++v101;
        }
        while ( v100 < v99->list.num );
        v30 = v125.size;
        v29 = v125.list;
      }
      fileSystem->FreeFileList(this: fileSystem, a2: v99);
    }
    ++v32;
  }
  if ( v125.num != 0 )
  {
    v33 = fileSystem->OpenFileWrite(this: fileSystem, a2: v159.data, a3: 0);
    v121 = v33;
    if ( v33 != nullptr )
    {
      v34 = v33;
      v33->Printf(this: v33, a2: "float $t0 = `timerX`;\n\n");
      idStr::idStr(this: &v176, text: &v159);
      idStr::StripFileExtension(this: &v176);
      idStr::Append(this: &v176, text: ".log");
      v34->Printf(
        this: v34,
        a2: "exportmd6 \"-logFileName %s -deleteLogFile -logOut \\\"******** START EXPORT %s ********\\\"\"\n\n",
        v176.data,
        v159.data);
      common->SetRefreshOnPrint(this: common, a2: true);
      common->ClearWarnings(this: common, a2: "anim_genScripts");
      v117 = "w:\\tech5\\shared\\idlib\\text/Str.h";
      v118 = "amount <= GetAlloced()";
      v119 = &mem;
      v157 = "no export commands found in file '%s'";
      v135 = "// no export commands found in file '%s'\n";
      v150 = "success!\n";
      v143 = "%sexportmd6 \"%s -out %s\";\n\n";
      v129 = 0;
      v122 = 0;
      v127 = 0;
      v116 = 0;
      v147 = "%sfile -f -type \"mayaAscii\" -prompt false -o \"%s\";\n";
      v146 = "/// ERROR: %s\n";
      v148 = "^1Error parsing command line for '%s'!\n";
      v138 = "endframe";
      v136 = ".MB";
      v145 = " -meshNamespace ";
      v139 = "//";
      v141 = "^1Source file not found: '%s'\n";
      v140 = "Processing mesh '%s'... ";
      v149 = "startframe";
      v137 = "%sfile -f -type \"mayaBinary\" -prompt false -o \"%s\";\n";
      v151 = (char *)-2111797896;
      v144 = "out";
      v155 = "-";
      v154 = "commandline";
      v152 = "Source file not found: '%s'";
      v123 = "-ex anim";
      v133 = &MD6_VERSION_STRING;
      v142 = "subtractiveAnim";
      v153 = "sourceAnim";
      v132 = "init";
      v35 = v120;
      v36 = 0;
      v37 = v126.list;
      v156 = "Processing anim '%s'... ";
      v112 = &MD6_MESH_EXT;
      v113 = &MD6_ANIM_EXT;
      v111 = "^2Parsing animations...\n";
      while ( v36 < 2 )
      {
        if ( v36 != 0 )
        {
          if ( v36 == 1 )
            idLib::Printf(fmt: v111);
        }
        else
        {
          idLib::Printf(fmt: "^2Parsing meshes...\n");
        }
        v38 = 0;
        while ( 2 )
        {
          v131 = v38;
          if ( v38 < v125.num )
          {
            v158.allocedAndFlag = 20;
            v39 = &v125.list[v38];
            v158.len = 0;
            v158.data = v158.baseBuffer;
            v158.baseBuffer[0] = 0;
            v40 = v39->len;
            v41 = v39->len + 1;
            if ( v41 > 20 )
              idStr::ReAllocate(this: &v158, amount: v41, keepold: true);
            v42 = v39->data - 1;
            v43 = v158.data - 1;
            do
            {
              v44 = *++v42;
              *++v43 = *v42;
            }
            while ( v44 != 0 );
            v158.len = v40;
            idStr::ToLower(this: &v158);
            v163.allocedAndFlag = 20;
            v163.data = v163.baseBuffer;
            v163.len = 0;
            v163.baseBuffer[0] = 0;
            idStr::ExtractFileExtension(this: &v158, dest: &v163);
            if ( v36 != 0 )
            {
              if ( v36 == 1 && idStr::Cmp(s1: v163.data, s2: *v112) == 0 )
                goto LABEL_113;
            }
            else if ( idStr::Cmp(s1: v163.data, s2: *v113) == 0 )
            {
LABEL_113:
              idStr::FreeData(this: &v163);
              idStr::FreeData(this: &v158);
              ++v38;
              continue;
            }
            v110.allocedAndFlag = 20;
            v110.len = 0;
            v110.data = v110.baseBuffer;
            v110.baseBuffer[0] = 0;
            v114.allocedAndFlag = 20;
            v114.data = v114.baseBuffer;
            v114.len = 0;
            v114.baseBuffer[0] = 0;
            v161.allocedAndFlag = 20;
            v161.data = v161.baseBuffer;
            v161.len = 0;
            v161.baseBuffer[0] = 0;
            v164.allocedAndFlag = 20;
            v164.data = v164.baseBuffer;
            v164.len = 0;
            v164.baseBuffer[0] = 0;
            v134.floatvalue = v20;
            v134.allocedAndFlag = 20;
            v134.data = v134.baseBuffer;
            v134.len = 0;
            v134.baseBuffer[0] = 0;
            v134.intvalue = 0;
            memset(&v134.whiteSpaceStart_p, 0, 12);
            idParser::idParser(this: &v180, flags: 262704);
            if ( !idParser::LoadFile(this: &v180, filename: v158.data, OSPath: false) )
            {
              idLib::Printf(fmt: "error reading file.\n");
              idParser::~idParser(this: &v180);
              idStr::FreeData(this: &v134);
              idStr::FreeData(this: &v164);
              idStr::FreeData(this: &v161);
              idStr::FreeData(this: &v114);
              idStr::FreeData(this: &v110);
              idStr::FreeData(this: &v163);
              idStr::FreeData(this: &v158);
              ++v38;
              continue;
            }
            if ( v36 == 1 )
            {
              if ( v108 == 0 )
                idLib::Printf(fmt: v156, v158.data);
              idParser::ExpectTokenString(this: &v180, string: *v133);
              idParser::ParseInt(this: &v180);
              v170.allocedAndFlag = 20;
              v170.len = 0;
              v170.data = v170.baseBuffer;
              v170.baseBuffer[0] = 0;
              v167.allocedAndFlag = 20;
              v167.data = v167.baseBuffer;
              v167.len = 0;
              v167.baseBuffer[0] = 0;
              v166.allocedAndFlag = 20;
              v166.data = v166.baseBuffer;
              v166.len = 0;
              v166.baseBuffer[0] = 0;
              v45 = v151;
              v46 = v142;
              while ( idParser::ReadToken(this: &v180, token: &v134) && v134.type != 5 && v134.subtype != 47 )
              {
                if ( idStr::Cmp(s1: v134.data, s2: v132) != 0 )
                {
                  idParser::SkipBracedSection(this: &v180, parseFirstBrace: true);
                }
                else
                {
                  idParser::ExpectTokenType(this: &v180, type: 5, subtype: 46, token: &v134);
                  while ( idParser::ReadToken(this: &v180, token: &v134) && v134.type != 5 && v134.subtype != 47 )
                  {
                    if ( idStr::Cmp(s1: v134.data, s2: "commandLine") != 0 )
                    {
                      if ( idStr::Cmp(s1: v134.data, s2: v153) != 0 )
                      {
                        if ( idStr::Cmp(s1: v134.data, s2: v46) != 0 )
                        {
                          if ( idStr::Cmp(s1: v134.data, s2: v45) != 0 )
                          {
                            if ( idStr::Cmp(s1: v134.data, s2: "meshName") != 0 )
                            {
                              idParser::ParseRestOfLine(this: &v180, out: &v164);
                            }
                            else
                            {
                              idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                              idStr::operator=(this: &v170, text: &v134);
                            }
                          }
                          else
                          {
                            idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                            v52 = v134.len;
                            idStr::EnsureAlloced(
                              this: &v166,
                              amount: v134.len + 1,
                              keepold: false,
                              geometricGrowth: false);
                            memcpy(Dst: v166.data, Src: v134.data, Size: v52);
                            v166.data[v52] = 0;
                            v166.len = v52;
                          }
                        }
                        else
                        {
                          idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                          v51 = v134.len;
                          idStr::EnsureAlloced(
                            this: &v167,
                            amount: v134.len + 1,
                            keepold: false,
                            geometricGrowth: false);
                          memcpy(Dst: v167.data, Src: v134.data, Size: v51);
                          v167.data[v51] = 0;
                          v167.len = v51;
                        }
                      }
                      else
                      {
                        idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                        v49 = v134.len;
                        idStr::EnsureAlloced(this: &v114, amount: v134.len + 1, keepold: false, geometricGrowth: false);
                        memcpy(Dst: v114.data, Src: v134.data, Size: v49);
                        v114.data[v49] = 0;
                        v114.len = v49;
                        idStr::EnsureAlloced(this: &v161, amount: v49 + 1, keepold: false, geometricGrowth: false);
                        memcpy(Dst: v161.data, Src: v114.data, Size: v49);
                        v161.data[v49] = 0;
                        v161.len = v49;
                        (*v35)->OSPathToRelativePath(this: *v35, a2: v114.data, a3: (char *)&v179.loaded, a4: 256);
                        ((void (__fastcall *)(idFileSystem *, idLexer *, char *, int, _DWORD, int))(*v35)->RelativePathToOSPath_2)(
                          a1: *v35,
                          a2: &v179,
                          a3: v181,
                          a4: 256,
                          a5: 0,
                          a6: v50);
                        idStr::operator=(this: &v114, text: v181);
                      }
                    }
                    else
                    {
                      idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                      v47 = v134.len;
                      idStr::EnsureAlloced(this: &v110, amount: v134.len + 1, keepold: false, geometricGrowth: false);
                      memcpy(Dst: v110.data, Src: v134.data, Size: v47);
                      v110.data[v47] = 0;
                      v110.len = v47;
                      if ( idStr::Find(
                             searchIn: v110.data,
                             searchFor: "-skipDialog",
                             casesensitive: true,
                             start: 0,
                             end: v47) == -1 )
                      {
                        v48 = idStr::Find(
                                searchIn: v110.data,
                                searchFor: v123,
                                casesensitive: true,
                                start: 0,
                                end: v110.len);
                        idStr::Insert(this: &v110, text: " -skipDialog", index: v48 + 8);
                      }
                    }
                  }
                }
              }
              idStr::FreeData(this: &v166);
              idStr::FreeData(this: &v167);
              idStr::FreeData(this: &v170);
            }
            else
            {
              if ( v36 != 0 )
              {
                idParser::~idParser(this: &v180);
                idStr::FreeData(this: &v134);
                idStr::FreeData(this: &v164);
                idStr::FreeData(this: &v161);
                idStr::FreeData(this: &v114);
                idStr::FreeData(this: &v110);
                idStr::FreeData(this: &v163);
                idStr::FreeData(this: &v158);
                ++v38;
                continue;
              }
              if ( v108 == 0 )
                idLib::Printf(fmt: v140, v158.data);
              idParser::ExpectTokenString(this: &v180, string: *v133);
              idParser::ParseInt(this: &v180);
              while ( idParser::ReadToken(this: &v180, token: &v134) && v134.type != 5 && v134.subtype != 47 )
              {
                if ( idStr::Cmp(s1: v134.data, s2: v132) != 0 )
                {
                  idParser::ParseRestOfLine(this: &v180, out: &v164);
                }
                else
                {
                  idParser::ExpectTokenType(this: &v180, type: 5, subtype: 46, token: &v134);
                  while ( idParser::ReadToken(this: &v180, token: &v134) && v134.type != 5 && v134.subtype != 47 )
                  {
                    if ( idStr::Cmp(s1: v134.data, s2: "commandLine") != 0 )
                    {
                      if ( idStr::Cmp(s1: v134.data, s2: "sourceFile") != 0 )
                      {
                        idParser::ParseRestOfLine(this: &v180, out: &v164);
                      }
                      else
                      {
                        idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                        v59 = v134.len;
                        idStr::EnsureAlloced(this: &v114, amount: v134.len + 1, keepold: false, geometricGrowth: false);
                        memcpy(Dst: v114.data, Src: v134.data, Size: v59);
                        v114.data[v59] = 0;
                        v114.len = v59;
                      }
                    }
                    else
                    {
                      idParser::ExpectTokenType(this: &v180, type: 1, subtype: 0, token: &v134);
                      v57 = v134.len;
                      idStr::EnsureAlloced(this: &v110, amount: v134.len + 1, keepold: false, geometricGrowth: false);
                      memcpy(Dst: v110.data, Src: v134.data, Size: v57);
                      v110.data[v57] = 0;
                      v110.len = v57;
                      if ( idStr::Find(
                             searchIn: v110.data,
                             searchFor: "-skipDialog",
                             casesensitive: true,
                             start: 0,
                             end: v57) == -1 )
                      {
                        v58 = idStr::Find(
                                searchIn: v110.data,
                                searchFor: "-ex mesh",
                                casesensitive: true,
                                start: 0,
                                end: v110.len);
                        idStr::Insert(this: &v110, text: " -skipDialog", index: v58 + 8);
                      }
                    }
                  }
                }
              }
            }
            if ( v110.len == 0 || v114.len == 0 )
            {
              v121->Printf(this: v121, a2: v135, v158.data);
              idLib::Warning(fmt: v157, v158.data);
              ++v122;
              goto LABEL_269;
            }
            v165.len = 0;
            v165.baseBuffer[0] = 0;
            v165.data = v165.baseBuffer;
            v165.allocedAndFlag = 20;
            v53 = v130;
            v54 = 0;
            for ( i = 0; ; ++i )
            {
              if ( i >= v126.num )
                goto LABEL_150;
              v56 = &v37[i];
              if ( idStr::Find(
                     searchIn: v114.data,
                     searchFor: v56->match.data,
                     casesensitive: true,
                     start: 0,
                     end: v114.len) != -1 )
                break;
            }
            if ( v56->exclude )
              v54 = 1;
            else
              idStr::Replace(this: &v114, old: v56->match.data, nw: v56->replace.data);
LABEL_150:
            if ( v54 != 0 )
            {
              idStr::FreeData(this: &v165);
              idParser::~idParser(this: &v180);
              idStr::FreeData(this: &v134);
              idStr::FreeData(this: &v164);
              idStr::FreeData(this: &v161);
              idStr::FreeData(this: &v114);
              idStr::FreeData(this: &v110);
              idStr::FreeData(this: &v163);
              idStr::FreeData(this: &v158);
              ++v38;
              continue;
            }
            if ( !(*v35)->FileExists(this: *v35, a2: v114.data, a3: false) )
            {
              v168.len = 0;
              v168.allocedAndFlag = 20;
              v168.data = v168.baseBuffer;
              v60 = v114.len;
              v168.baseBuffer[0] = 0;
              if ( v114.len + 1 > 20 )
                idStr::ReAllocate(this: &v168, amount: v114.len + 1, keepold: true);
              data = v114.data;
              v62 = v168.data;
              do
              {
                v63 = *data;
                *v62++ = *data++;
              }
              while ( v63 != 0 );
              v168.len = v60;
              if ( idStr::Find(searchIn: v114.data, searchFor: ".mb", casesensitive: true, start: 0, end: v114.len) == -1 )
              {
                if ( idStr::Find(searchIn: v114.data, searchFor: ".ma", casesensitive: true, start: 0, end: v114.len) != -1 )
                  idStr::Replace(this: &v114, old: ".ma", nw: ".mb");
              }
              else
              {
                idStr::Replace(this: &v114, old: ".mb", nw: ".ma");
              }
              if ( !(*v35)->FileExists(this: *v35, a2: v114.data, a3: false)
                && (*v35)->OSPathToRelativePath(this: *v35, a2: v168.data, a3: v181, a4: 256) )
              {
                idStr::operator=(this: &v114, text: v181);
                if ( !(*v35)->FileExists(this: *v35, a2: v114.data, a3: false) )
                {
                  if ( idStr::Find(searchIn: v114.data, searchFor: ".mb", casesensitive: true, start: 0, end: v114.len) == -1 )
                  {
                    if ( idStr::Find(
                           searchIn: v114.data,
                           searchFor: ".ma",
                           casesensitive: true,
                           start: 0,
                           end: v114.len) != -1 )
                      idStr::Replace(this: &v114, old: ".ma", nw: ".mb");
                  }
                  else
                  {
                    idStr::Replace(this: &v114, old: ".mb", nw: ".ma");
                  }
                  if ( !(*v35)->FileExists(this: *v35, a2: v114.data, a3: false) )
                  {
                    HIDWORD(v66) = v161.data;
                    v67 = va::va(
                            this: &v183,
                            fmt: v152,
                            a3: v66,
                            a4: v65,
                            a5: v64,
                            a6: v102,
                            a7: v103,
                            a8: v104,
                            a9: v105,
                            a10: v106,
                            a11: v107);
                    v68 = v67;
                    for ( j = 0; v67->buffer[j] != 0; ++j )
                      ;
                    idStr::EnsureAlloced(this: &v165, amount: j + 1, keepold: false, geometricGrowth: false);
                    memcpy(Dst: v165.data, Src: v68, Size: j);
                    v70 = v141;
                    v165.data[j] = 0;
                    v165.len = j;
                    idLib::Printf(fmt: v70, v161.data);
                    v53 = v139;
                    ++v127;
                  }
                }
              }
              idStr::FreeData(this: &v168);
            }
            idParser::idParser(this: &v182, flags: 544);
            idParser::LoadMemory(this: &v182, ptr: v110.data, length: v110.len, name: v154);
            v172.floatvalue = v20;
            v172.len = 0;
            v172.data = v172.baseBuffer;
            v172.allocedAndFlag = 20;
            v172.baseBuffer[0] = 0;
            v172.intvalue = 0;
            memset(&v172.whiteSpaceStart_p, 0, 12);
            v71 = nullptr;
            *(_WORD *)&v124.memTag = 1280;
            v72 = 0;
            v73 = 0;
            memset(&v124, 0, 14);
            while ( idParser::ReadToken(this: &v182, token: &v172) )
            {
              idList<idToken,5>::Append(this: &v124, obj: &v172);
              v72 = v124.size;
              v73 = v124.num;
              v71 = v124.list;
            }
            v74 = 0;
            if ( v110.allocedAndFlag >= 0 )
            {
              if ( (v110.allocedAndFlag & 0x7FFFFFFF) == 0 )
                idStr::ReAllocate(this: &v110, amount: 1, keepold: true);
            }
            else if ( (v110.allocedAndFlag & 0x7FFFFFFF) == 0
                   && AssertFailed(file: v117, line: 463, expression: v118, inlineBreak: true) )
            {
              __trap();
            }
            v75 = 0;
            *v110.data = 0;
            v110.len = 0;
LABEL_205:
            if ( v75 >= v73 )
            {
LABEL_209:
              if ( v74 != 0 )
              {
                idLib::Printf(fmt: v148, v114.data);
                if ( v124.listStatic == 0 || v124.listStatic == 2 )
                {
                  if ( v71 != nullptr )
                  {
                    for ( k = 0; k < v72; ++k )
                      idStr::FreeData(this: &v71[k]);
                    idMem::Free(this: v119, ptr: v71, align: ALIGN_16);
                  }
                  v124.list = nullptr;
                  v124.size = 0;
                }
                v124.num = 0;
                idStr::FreeData(this: &v172);
                idParser::~idParser(this: &v182);
                idStr::FreeData(this: &v165);
                idParser::~idParser(this: &v180);
                idStr::FreeData(this: &v134);
                idStr::FreeData(this: &v164);
                idStr::FreeData(this: &v161);
                idStr::FreeData(this: &v114);
                idStr::FreeData(this: &v110);
                idStr::FreeData(this: &v163);
                idStr::FreeData(this: &v158);
                v35 = v120;
                v36 = v116;
                v38 = v131 + 1;
                v37 = v126.list;
                continue;
              }
              idStr::StripTrailingWhitespace(this: &v110);
              if ( v116 == 1 && v162.len != 0 )
              {
                idStr::Append(this: &v110, text: v145);
                idStr::Append(this: &v110, text: &v162);
              }
              (*v120)->RelativePathToOSPath_2(
                this: *v120,
                a2: v114.data,
                a3: (char *)&v179.loaded,
                a4: 256,
                a5: FSPATH_BASE);
              idStr::operator=(this: &v114, text: (const char *)&v179.loaded);
              idStr::BackSlashesToSlashes(this: &v114);
              if ( v108 == 0 || *v53 != 0 )
              {
                v85 = v121;
                if ( *v53 != 0 )
                  v121->Printf(this: v121, a2: v146, v165.data);
                if ( idStr::Find(searchIn: v114.data, searchFor: ".mb", casesensitive: true, start: 0, end: v114.len) == -1
                  && idStr::Find(searchIn: v114.data, searchFor: v136, casesensitive: true, start: 0, end: v114.len) == -1 )
                {
                  v85->Printf(this: v85, a2: v147, v53, v114.data);
                }
                else
                {
                  v85->Printf(this: v85, a2: v137, v53, v114.data);
                }
                v85->Printf(this: v85, a2: v143, v53, v110.data, v158.data);
              }
              ++v129;
              if ( v108 == 0 )
                idLib::Printf(fmt: v150);
              if ( v124.listStatic == 0 || v124.listStatic == 2 )
              {
                if ( v71 != nullptr )
                {
                  for ( m = 0; m < v72; ++m )
                    idStr::FreeData(this: &v71[m]);
                  idMem::Free(this: v119, ptr: v71, align: ALIGN_16);
                }
                v124.list = nullptr;
                v124.size = 0;
              }
              v124.num = 0;
              idStr::FreeData(this: &v172);
              idParser::~idParser(this: &v182);
              idStr::FreeData(this: &v165);
LABEL_269:
              idParser::~idParser(this: &v180);
              idStr::FreeData(this: &v134);
              idStr::FreeData(this: &v164);
              idStr::FreeData(this: &v161);
              idStr::FreeData(this: &v114);
              idStr::FreeData(this: &v110);
              idStr::FreeData(this: &v163);
              idStr::FreeData(this: &v158);
              v35 = v120;
              v36 = v116;
              v38 = v131 + 1;
              v37 = v126.list;
              continue;
            }
            v128 = &v71[v75];
            if ( idStr::Icmp(s1: v128->data, s2: v155) != 0 )
            {
              v128 = &v71[v75];
              idStr::Append(this: &v110, text: v128);
              v82 = v110.len + 2;
              v84 = v110.allocedAndFlag & 0x7FFFFFFF;
              if ( v110.allocedAndFlag < 0 )
              {
                if ( v82 > v84 && AssertFailed(file: v117, line: 463, expression: v118, inlineBreak: true) )
LABEL_231:
                  __trap();
LABEL_240:
                ++v75;
                v110.data[v110.len] = 32;
                v110.data[++v110.len] = 0;
                goto LABEL_205;
              }
              if ( v82 <= v84 )
                goto LABEL_240;
            }
            else
            {
              if ( ++v75 >= v73 )
              {
                v74 = 1;
                goto LABEL_209;
              }
              v77 = &v71[v75];
              v128 = (idToken *)v77;
              if ( idStr::Icmp(s1: v77->data, s2: v144) == 0 )
                goto _M242907;
              if ( v109 != 0 )
              {
                v78 = v77->data;
                v128 = &v71[v75];
                if ( idStr::Icmp(s1: v78, s2: v149) == 0 )
                {
                  v75 += 2;
                  goto LABEL_205;
                }
                v79 = v77->data;
                v128 = &v71[v75];
                if ( idStr::Icmp(s1: v79, s2: v138) == 0 )
                {
_M242907:
                  v75 += 2;
                  goto LABEL_205;
                }
              }
              v80 = v110.len + 2;
              v81 = v110.allocedAndFlag & 0x7FFFFFFF;
              if ( v110.allocedAndFlag >= 0 )
              {
                if ( v80 > v81 )
                  idStr::ReAllocate(this: &v110, amount: (v80 >> 1) + v80, keepold: true);
              }
              else if ( v80 > v81 && AssertFailed(file: v117, line: 463, expression: v118, inlineBreak: true) )
              {
                __trap();
              }
              v128 = &v71[v75];
              v110.data[v110.len] = 45;
              v110.data[++v110.len] = 0;
              idStr::Append(this: &v110, text: &v71[v75]);
              v82 = v110.len + 2;
              v83 = v110.allocedAndFlag & 0x7FFFFFFF;
              if ( v110.allocedAndFlag < 0 )
              {
                if ( v82 > v83 && AssertFailed(file: v117, line: 463, expression: v118, inlineBreak: true) )
                  goto LABEL_231;
                goto LABEL_240;
              }
              if ( v82 <= v83 )
                goto LABEL_240;
            }
            idStr::ReAllocate(this: &v110, amount: (v82 >> 1) + v82, keepold: true);
            goto LABEL_240;
          }
          break;
        }
        v116 = ++v36;
      }
      v87 = v121;
      v121->Printf(this: v121, a2: "float $elapsed = `timerX -st $t0`;\n");
      v87->Printf(this: v87, a2: "float $hours = `floor( $elapsed / 3600 )`;\n");
      v87->Printf(this: v87, a2: "float $mins = `floor( ( $elapsed - ( $hours * 3600 ) ) / 60 )`;\n");
      v87->Printf(this: v87, a2: "float $secs = $elapsed - ( ( $hours * 3600 ) + ( $mins * 60 ) );\n");
      v87->Printf(this: v87, a2: "print( \"================================\\n\" );\n");
      v87->Printf(
        this: v87,
        a2: "print( \"Elapsed Time: \" + $hours + \" hours : \" + $mins + \" mins : \" + $secs + \" secs\\n\" );\n");
      idLib::Printf(fmt: "%d total exports in script.\n", v129);
      if ( v127 <= 0 )
        idLib::Printf(fmt: "All source files accounted for. This makes Nelno happy!\n");
      else
        idLib::Printf(fmt: "^1%d source files were not found. This makes Nelno sad.\n", v127);
      if ( v122 > 0 )
        idLib::Printf(fmt: "^1%d files failed to parse.\n", v122);
      common->SetRefreshOnPrint(this: common, a2: false);
      ((void (__fastcall *)(idFile *, int))v87->dtr_idFile)(a1: v87, a2: 1);
      idStr::FreeData(this: &v176);
      if ( v125.listStatic == 0 || v125.listStatic == 2 )
      {
        v88 = v125.list;
        if ( v125.list != nullptr )
        {
          v89 = v125.size;
          if ( v125.size > 0 )
          {
            v90 = v125.list;
            do
            {
              idStr::FreeData(this: v90);
              --v89;
              ++v90;
            }
            while ( v89 != 0 );
          }
          idMem::Free(this: v119, ptr: v88, align: ALIGN_16);
        }
      }
      idStr::FreeData(this: &v175);
      if ( (v126.listStatic == 0 || v126.listStatic == 2) && v37 != nullptr )
        idListArrayDelete<idDeclRollBones::idDeclRollBoneInstance>(ptr: &v37->match, num: v126.size);
      idStr::FreeData(this: &v162);
      if ( v115.listStatic == 0 || v115.listStatic == 2 )
      {
        v91 = v115.list;
        if ( v115.list != nullptr )
        {
          v92 = v115.size;
          if ( v115.size > 0 )
          {
            v93 = v115.list;
            do
            {
              idStr::FreeData(this: v93);
              --v92;
              ++v93;
            }
            while ( v92 != 0 );
          }
          idMem::Free(this: v119, ptr: v91, align: ALIGN_16);
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "Could not open output file '%s'", v159.data);
      if ( (v125.listStatic == 0 || v125.listStatic == 2) && v29 != nullptr )
        idListArrayDelete<idStr>(ptr: v29, num: v30);
      idStr::FreeData(this: &v175);
      if ( (listStatic == 0 || listStatic == 2) && v18 != nullptr )
        idListArrayDelete<idDeclRollBones::idDeclRollBoneInstance>(ptr: &v18->match, num: size);
      idStr::FreeData(this: &v162);
      if ( (v115.listStatic == 0 || v115.listStatic == 2) && v31 != nullptr )
        idListArrayDelete<idStr>(ptr: v31, num: v115.size);
    }
  }
  else
  {
    idLib::Printf(fmt: "No animation files found.");
    if ( (v125.listStatic == 0 || v125.listStatic == 2) && v29 != nullptr )
    {
      if ( v30 > 0 )
      {
        v94 = v29;
        for ( n = v30; n != 0; --n )
          idStr::FreeData(this: v94++);
      }
      idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    }
    idStr::FreeData(this: &v175);
    if ( (listStatic == 0 || listStatic == 2) && v18 != nullptr )
      idListArrayDelete<idDeclRollBones::idDeclRollBoneInstance>(ptr: &v18->match, num: size);
    idStr::FreeData(this: &v162);
    if ( (v115.listStatic == 0 || v115.listStatic == 2) && v31 != nullptr )
    {
      v96 = v115.size;
      if ( v115.size > 0 )
      {
        v97 = v31;
        do
        {
          idStr::FreeData(this: v97);
          --v96;
          ++v97;
        }
        while ( v96 != 0 );
      }
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    }
  }
  idStr::FreeData(this: &v160);
  idStr::FreeData(this: &v159);
}


// ========================================================================
// $M243089
// EA  : 0x8280BCBC
// RVA : 0x0080BCBC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M243089()
{
  int v0; // r12

  idLib::Warning(fmt: "Failed to load remap file '%s'", *(const char **)(v0 - 7552 + 580));
  return &_M242679;
}


// ========================================================================
// $M243092
// EA  : 0x8280BCFC
// RVA : 0x0080BCFC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void *_M243092()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 7552;
  idLib::Warning(fmt: "parsing error:  %s", idException::error);
  ++*(_DWORD *)(v1 + 232);
  return &_M243028;
}


// ========================================================================
// __unwind$240015
// EA  : 0x8280BD44
// RVA : 0x0080BD44
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240015()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 544));
}


// ========================================================================
// __unwind$240016
// EA  : 0x8280BD6C
// RVA : 0x0080BD6C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240016()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 576));
}


// ========================================================================
// __unwind$240017
// EA  : 0x8280BD94
// RVA : 0x0080BD94
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240017()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 7552 + 192));
}


// ========================================================================
// __unwind$240018
// EA  : 0x8280BDBC
// RVA : 0x0080BDBC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240018()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 640));
}


// ========================================================================
// __unwind$240019
// EA  : 0x8280BDE4
// RVA : 0x0080BDE4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240019()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1424));
}


// ========================================================================
// __unwind$240020
// EA  : 0x8280BE0C
// RVA : 0x0080BE0C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240020()
{
  int v0; // r12

  idList<idPlaytestStorage::inventoryElement_t,5>::Clear(this: (idList<idPlaytestStorage::inventoryElement_t,5> *)(v0 - 7552 + 272));
}


// ========================================================================
// __unwind$240021
// EA  : 0x8280BE34
// RVA : 0x0080BE34
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240021()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 7552 + 1456));
}


// ========================================================================
// __unwind$240022
// EA  : 0x8280BE5C
// RVA : 0x0080BE5C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240022()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 864));
}


// ========================================================================
// __unwind$240023
// EA  : 0x8280BE84
// RVA : 0x0080BE84
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240023()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1168));
}


// ========================================================================
// __unwind$240024
// EA  : 0x8280BEAC
// RVA : 0x0080BEAC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240024()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1008));
}


// ========================================================================
// __unwind$240025
// EA  : 0x8280BED4
// RVA : 0x0080BED4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240025()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1248));
}


// ========================================================================
// __unwind$240026
// EA  : 0x8280BEFC
// RVA : 0x0080BEFC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1328));
}


// ========================================================================
// __unwind$240027
// EA  : 0x8280BF24
// RVA : 0x0080BF24
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240027()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 7552 + 256));
}


// ========================================================================
// __unwind$240029
// EA  : 0x8280BF4C
// RVA : 0x0080BF4C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240029()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1360));
}


// ========================================================================
// __unwind$240030
// EA  : 0x8280BF74
// RVA : 0x0080BF74
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240030()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 512));
}


// ========================================================================
// __unwind$240031
// EA  : 0x8280BF9C
// RVA : 0x0080BF9C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240031()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 672));
}


// ========================================================================
// __unwind$240032
// EA  : 0x8280BFC4
// RVA : 0x0080BFC4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240032()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 112));
}


// ========================================================================
// __unwind$240033
// EA  : 0x8280BFEC
// RVA : 0x0080BFEC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 160));
}


// ========================================================================
// __unwind$240034
// EA  : 0x8280C014
// RVA : 0x0080C014
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 608));
}


// ========================================================================
// __unwind$240035
// EA  : 0x8280C03C
// RVA : 0x0080C03C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 704));
}


// ========================================================================
// __unwind$240036
// EA  : 0x8280C064
// RVA : 0x0080C064
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240036()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 336));
}


// ========================================================================
// __unwind$240037
// EA  : 0x8280C08C
// RVA : 0x0080C08C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240037()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 7552 + 1712));
}


// ========================================================================
// __unwind$240038
// EA  : 0x8280C0B4
// RVA : 0x0080C0B4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 976));
}


// ========================================================================
// __unwind$240039
// EA  : 0x8280C0DC
// RVA : 0x0080C0DC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240039()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 800));
}


// ========================================================================
// __unwind$240040
// EA  : 0x8280C104
// RVA : 0x0080C104
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 768));
}


// ========================================================================
// __unwind$240041
// EA  : 0x8280C12C
// RVA : 0x0080C12C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240041()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 736));
}


// ========================================================================
// __unwind$240042
// EA  : 0x8280C154
// RVA : 0x0080C154
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240042()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 832));
}


// ========================================================================
// __unwind$240043
// EA  : 0x8280C17C
// RVA : 0x0080C17C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240043()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 7552 + 2624));
}


// ========================================================================
// __unwind$240044
// EA  : 0x8280C1A4
// RVA : 0x0080C1A4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1088));
}


// ========================================================================
// __unwind$240045
// EA  : 0x8280C1CC
// RVA : 0x0080C1CC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240045()
{
  int v0; // r12

  idList<idToken,5>::Clear(this: (idList<idToken,5> *)(v0 - 7552 + 240));
}


// ========================================================================
// __unwind$240028
// EA  : 0x8280C1F4
// RVA : 0x0080C1F4
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_240028()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7552 + 1392));
}


// ========================================================================
// ??0idAnimationLocal@@QAA@XZ
// EA  : 0x8280C8B8
// RVA : 0x0080C8B8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::idAnimationLocal(idAnimationLocal *this)
{
  this->randomNumberGenerator.seed = 0;
  this->__vftable = (idAnimationLocal_vtbl *)&idAnimationLocal::`vftable';
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&this->jointHash);
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&this->userChannelHash);
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>(this: &this->aliasHash);
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(this: &this->jointConversionHash);
  this->originJointHandle.value = -1;
  this->strongAliasRefs.list = nullptr;
  this->strongAliasRefs.granularity = 0;
  this->strongAliasRefs.memTag = 30;
  this->strongAliasRefs.listStatic = 0;
  this->strongAliasRefs.size = 0;
  this->strongAliasRefs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->strongAliasRefs);
  return this;
}


// ========================================================================
// __unwind$243638
// EA  : 0x8280C94C
// RVA : 0x0080C94C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243638()
{
  int v0; // r12

  idAnimation::~idAnimation(this: *(idAnimation **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$243639
// EA  : 0x8280C974
// RVA : 0x0080C974
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243639()
{
  int v0; // r12

  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::~idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(this: (idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$243640
// EA  : 0x8280C9A0
// RVA : 0x0080C9A0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243640()
{
  int v0; // r12

  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::~idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>(this: (idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidUserChannelHandle_t,65535>,enum idAnimationLocal::userChannelTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::userChannelTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::userChannelTypeId> > *)(*(_DWORD *)(v0 - 128 + 148) + 60));
}


// ========================================================================
// __unwind$243641
// EA  : 0x8280C9CC
// RVA : 0x0080C9CC
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243641()
{
  int v0; // r12

  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::~idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>(this: (idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > *)(*(_DWORD *)(v0 - 128 + 148) + 112));
}


// ========================================================================
// __unwind$243642
// EA  : 0x8280C9F8
// RVA : 0x0080C9F8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243642()
{
  int v0; // r12

  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::~idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>(this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ?GetOriginJointName@idAnimationLocal@@UBAPBDXZ
// EA  : 0x8280CA28
// RVA : 0x0080CA28
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

const char *__fastcall idAnimationLocal::GetOriginJointName(idAnimationLocal *this)
{
  return "origin";
}


// ========================================================================
// ?GetOriginJointHandle@idAnimationLocal@@UBAABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@XZ
// EA  : 0x8280CA38
// RVA : 0x0080CA38
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

const idHandle<unsigned short,enum invalidJointHandle_t,65535> *__fastcall idAnimationLocal::GetOriginJointHandle(
        idAnimationLocal *this)
{
  return &this->originJointHandle;
}


// ========================================================================
// ?RegisterJoint@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280CAA8
// RVA : 0x0080CAA8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::RegisterJoint(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *result,
        const char *name)
{
  int v5; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *v6; // r29
  __int16 list_high; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v8; // r3
  const idJointConversion *v9; // r6
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > var30; // [sp+50h] [-30h] BYREF

  if ( name != nullptr )
  {
    v5 = 0;
    if ( *name != 0 )
    {
      do
        ++v5;
      while ( name[v5] != 0 );
      if ( v5 != 0 )
      {
        v6 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[4];
        idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
          this: &var30,
          result: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[4],
          typeId: JOINTCONVERSION_ANY,
          name);
        list_high = HIWORD(var30.list.list);
        if ( HIWORD(var30.list.list) != 0xFFFF )
        {
LABEL_11:
          HIWORD(this->__vftable) = list_high;
          return this;
        }
        v8 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *)idMem::AllocWithLocation(this: &mem, location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag", size: 0x20u, tag: TAG_ANIMATION, zeroBuffer: false, align: ALIGN_16, heap: HEAP_DEFAULTHEAP);
        var30.list.list = v8;
        if ( v8 != nullptr )
          v9 = (const idJointConversion *)idStr::idStr(this: (idStr *)v8, text: name);
        else
          v9 = nullptr;
        HIWORD(this->__vftable) = HIWORD(idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Add(
                                           this: &var30,
                                           result: v6,
                                           typeId: JOINTCONVERSION_ANY,
                                           obj: v9,
                                           parent: nullptr,
                                           name,
                                           e: nullptr)->list.list);
        return this;
      }
    }
  }
  list_high = -1;
  goto LABEL_11;
}


// ========================================================================
// __unwind$243716
// EA  : 0x8280CB9C
// RVA : 0x0080CB9C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243716()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_ANIMATION);
}


// ========================================================================
// ?RegisterUserChannel@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidUserChannelHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280CBD0
// RVA : 0x0080CBD0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::RegisterUserChannel(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *result,
        const char *name)
{
  int v5; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *v6; // r29
  __int16 list_high; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v8; // r3
  idStr *v9; // r30
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > var30; // [sp+50h] [-30h] BYREF

  if ( name != nullptr )
  {
    v5 = 0;
    if ( *name != 0 )
    {
      do
        ++v5;
      while ( name[v5] != 0 );
      if ( v5 != 0 )
      {
        v6 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[30];
        idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
          this: &var30,
          result: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[30],
          typeId: JOINTCONVERSION_ANY,
          name);
        list_high = HIWORD(var30.list.list);
        if ( HIWORD(var30.list.list) != 0xFFFF )
        {
LABEL_11:
          HIWORD(this->__vftable) = list_high;
          return this;
        }
        v8 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *)idMem::AllocWithLocation(this: &mem, location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag", size: 0x20u, tag: TAG_ANIMATION, zeroBuffer: false, align: ALIGN_16, heap: HEAP_DEFAULTHEAP);
        var30.list.list = v8;
        if ( v8 != nullptr )
          v9 = idStr::idStr(this: (idStr *)v8, text: name);
        else
          v9 = nullptr;
        idStr::ToLower(this: v9);
        HIWORD(this->__vftable) = HIWORD(idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Add(
                                           this: &var30,
                                           result: v6,
                                           typeId: JOINTCONVERSION_ANY,
                                           obj: (const idJointConversion *)v9,
                                           parent: nullptr,
                                           name: v9->data,
                                           e: nullptr)->list.list);
        return this;
      }
    }
  }
  list_high = -1;
  goto LABEL_11;
}


// ========================================================================
// __unwind$243759
// EA  : 0x8280CCD0
// RVA : 0x0080CCD0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243759()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_ANIMATION);
}


// ========================================================================
// ?LoadJointConversion@idAnimationLocal@@QAA?AV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280CD08
// RVA : 0x0080CD08
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::LoadJointConversion(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *result,
        const char *name)
{
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *v5; // r29
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *Entry; // r3
  int num; // r30
  unsigned __int16 value; // r29
  idResource *v9; // r3
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > v11; // [sp+50h] [-60h] BYREF

  if ( name == nullptr || *name == 0 )
  {
    HIWORD(this->__vftable) = -1;
    return this;
  }
  idStr::idStr(this: (idStr *)&v11.nameHash, text: name);
  idStr::BackSlashesToSlashes(this: (idStr *)&v11.nameHash);
  v5 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[82];
  Entry = idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::FindEntry(
            this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[82],
            typeId: JOINTCONVERSION_ANY,
            name: (const char *)v11.nameHash.indexChain);
  num = (int)Entry;
  v11.list.num = (int)Entry;
  if ( Entry != nullptr )
  {
    value = Entry->handle.value;
    if ( Entry->ptr != nullptr )
    {
      HIWORD(this->__vftable) = Entry->handle.value;
      idStr::FreeData(this: (idStr *)&v11.nameHash);
      return this;
    }
  }
  else
  {
    value = HIWORD(idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::Add(
                     this: &v11,
                     result: v5,
                     typeId: JOINTCONVERSION_ANY,
                     obj: nullptr,
                     parent: nullptr,
                     name: (const char *)v11.nameHash.indexChain,
                     e: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t **)&v11.list.num)->list.list);
    num = v11.list.num;
  }
  v9 = idResourceList::Load(
         this: &idJointConversion::resourceList,
         name: *(char **)(num + 12),
         makeDefault: true,
         skipStaleCheck: false);
  if ( v9 != nullptr )
  {
    HIWORD(v9[1].__vftable) = -1;
    *(_DWORD *)num = v9;
    *(_DWORD *)(num + 4) = v9;
    HIWORD(v9[1].__vftable) = *(_WORD *)(num + 44);
    HIWORD(this->__vftable) = value;
  }
  else
  {
    HIWORD(this->__vftable) = -1;
  }
  idStr::FreeData(this: (idStr *)&v11.nameHash);
  return this;
}


// ========================================================================
// __unwind$243802
// EA  : 0x8280CE24
// RVA : 0x0080CE24
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243802()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?RegisterAlias@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBVidDeclMD6@@PBD@Z
// EA  : 0x8280CE58
// RVA : 0x0080CE58
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::RegisterAlias(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *result,
        const idDeclMD6 *modelDef,
        const char *aliasName,
        int a5,
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
        const idDeclMD6 *a16)
{
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *v19; // r27
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *Entry; // r3
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> >::entry_t *v21; // r24
  idList<enum encounterGroupRole_t,5> *ptr; // r29
  int num; // r8
  int v24; // r10
  int v25; // r11
  int v26; // r10
  encounterGroupRole_t *list; // r9
  int v28; // r11
  int v29; // r9
  int v30; // r10
  int v31; // r11
  __int16 list_high; // r11
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *v33; // r3
  idList<enum encounterGroupRole_t,5> *v34; // r30
  idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> > v36; // [sp+50h] [-50h] BYREF

  a16 = modelDef;
  if ( aliasName == nullptr || *aliasName == 0 )
  {
    list_high = -1;
    goto LABEL_29;
  }
  v19 = (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[56];
  Entry = idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId>>::FindEntry(
            this: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[56],
            typeId: JOINTCONVERSION_ANY,
            name: aliasName);
  v21 = Entry;
  if ( Entry == nullptr || (ptr = (idList<enum encounterGroupRole_t,5> *)Entry->ptr, Entry->ptr == nullptr) )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v33 = (idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId> >::entry_t *)idMem::AllocWithLocation(this: &mem, location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag", size: 0x10u, tag: TAG_ANIMATION, zeroBuffer: false, align: ALIGN_16, heap: HEAP_DEFAULTHEAP);
    v36.list.list = v33;
    if ( v33 != nullptr )
      v34 = (idList<enum encounterGroupRole_t,5> *)idList<idMD6Blend::jointMod_t,30>::idList<idMD6Blend::jointMod_t,30>(this: (idList<idMD6Blend::jointMod_t,30> *)v33);
    else
      v34 = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(this: v34, obj: (const encounterGroupRole_t *)&a16);
    idMem::PopHeap(this: &mem);
    idAnimHash<idAliasGroup,idDeclMD6,idHandle<unsigned short,enum invalidAliasHandle_t,65535>,enum idAnimationLocal::aliasTypeId,4096,4096,idAnimationLocal::idAllocNew<idAliasGroup,enum idAnimationLocal::aliasTypeId>,idAnimationLocal::idGenNameNormal<idAliasGroup,enum idAnimationLocal::aliasTypeId>>::Add(
      this: &v36,
      result: v19,
      typeId: JOINTCONVERSION_ANY,
      obj: (const idAliasGroup *)v34,
      parent: modelDef,
      name: aliasName,
      e: nullptr);
    list_high = HIWORD(v36.list.list);
    goto LABEL_29;
  }
  if ( modelDef == nullptr )
  {
LABEL_23:
    list_high = v21->handle.value;
LABEL_29:
    HIWORD(this->__vftable) = list_high;
    return this;
  }
  num = ptr->num;
  v24 = 0;
  if ( num > 0 )
  {
    v25 = 0;
    while ( (const idDeclMD6 *)ptr->list[v25] != modelDef )
    {
      ++v24;
      ++v25;
      if ( v24 >= num )
        goto LABEL_10;
    }
    goto LABEL_23;
  }
LABEL_10:
  v26 = 0;
  if ( num <= 0 )
  {
LABEL_14:
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v29 = ptr->num;
    v30 = 0;
    if ( v29 <= 0 )
      goto LABEL_21;
    v31 = 0;
    while ( (const idDeclMD6 *)ptr->list[v31] != modelDef )
    {
      ++v30;
      ++v31;
      if ( v30 >= v29 )
        goto LABEL_21;
    }
    if ( v30 < 0 )
LABEL_21:
      idList<idAnimWebBlendTree *,5>::Append(this: ptr, obj: (const encounterGroupRole_t *)&a16);
    idMem::PopHeap(this: &mem);
    goto LABEL_23;
  }
  list = ptr->list;
  v28 = 0;
  while ( list[v28] != ROLE_NONE )
  {
    ++v26;
    ++v28;
    if ( v26 >= num )
      goto LABEL_14;
  }
  list[v26] = (encounterGroupRole_t)modelDef;
  HIWORD(this->__vftable) = Entry->handle.value;
  return this;
}


// ========================================================================
// __unwind$243902
// EA  : 0x8280D04C
// RVA : 0x0080D04C
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void _unwind_243902()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_ANIMATION);
}


// ========================================================================
// ?FindJointConversionHandle@idAnimationLocal@@UAA?AV?$idHandle@GW4invalidJointConversionHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280D078
// RVA : 0x0080D078
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idAnimationLocal *__fastcall idAnimationLocal::FindJointConversionHandle(
        idAnimationLocal *this,
        idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *result,
        const char *name)
{
  idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> *v3; // r31
  _DWORD *v7; // r11
  idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > var30; // [sp+50h] [-30h] BYREF

  v3 = result + 82;
  idAnimHash<idStr,idStr,idHandle<unsigned short,enum invalidJointHandle_t,65535>,enum idAnimationLocal::jointTypeId,256,256,idAnimationLocal::idAllocNew<idStr,enum idAnimationLocal::jointTypeId>,idAnimationLocal::idGenNameNormal<idStr,enum idAnimationLocal::jointTypeId>>::FindHandle(
    this: &var30,
    result: (idAnimHash<idJointConversion,idJointConversion,idHandle<unsigned short,enum invalidJointConversionHandle_t,65535>,enum idAnimationLocal::jointConversionTypeId,256,256,idAnimationLocal::idAllocNew<void,enum idAnimationLocal::jointConversionTypeId>,idAnimationLocal::idGenNameNormal<void,enum idAnimationLocal::jointConversionTypeId> > *)&result[82],
    typeId: JOINTCONVERSION_ANY,
    name);
  if ( HIWORD(var30.list.list) != 0xFFFF
    && HIWORD(var30.list.list) < *(int *)&v3[2].value
    && (v7 = (_DWORD *)(52 * HIWORD(var30.list.list) + *(_DWORD *)&v3->value)) != nullptr
    && *v7 != 0 )
  {
    HIWORD(this->__vftable) = HIWORD(var30.list.list);
    return this;
  }
  else
  {
    idAnimationLocal::LoadJointConversion(this, result, name);
    return this;
  }
}


// ========================================================================
// `dynamic initializer for 'anim_showLoads''
// EA  : 0x83343BE8
// RVA : 0x01343BE8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_showLoads__()
{
  idCVar::idCVar(
    this: &anim_showLoads,
    name: "anim_showLoads",
    value: "0",
    flags: 1,
    description: "1 = show debug info while loading animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_showLoads__);
}


// ========================================================================
// `dynamic initializer for 'anim_debugAnimName''
// EA  : 0x83343C40
// RVA : 0x01343C40
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugAnimName__()
{
  idCVar::idCVar(
    this: &anim_debugAnimName,
    name: "anim_debugAnimName",
    value: "ginny/facial/viseme_A.md6anim",
    flags: 0,
    description: "name of anim to debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugAnimName__);
}


// ========================================================================
// `dynamic initializer for 'anim_forceReload''
// EA  : 0x83343C98
// RVA : 0x01343C98
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_forceReload__()
{
  idCVar::idCVar(
    this: &anim_forceReload,
    name: "anim_forceReload",
    value: "0",
    flags: 1,
    description: "if != 0, then anims will always be reloaded from text if available.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_forceReload__);
}


// ========================================================================
// `dynamic initializer for 'anim_allowWeakRefs''
// EA  : 0x83343CF0
// RVA : 0x01343CF0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_allowWeakRefs__()
{
  idCVar::idCVar(
    this: &anim_allowWeakRefs,
    name: "anim_allowWeakRefs",
    value: "1",
    flags: 1,
    description: "1 = allow weak references to .md6anim resources, 0 = force strong references for all .md6anims",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_allowWeakRefs__);
}


// ========================================================================
// `dynamic initializer for 'idJointConversion::resourceList''
// EA  : 0x83343D48
// RVA : 0x01343D48
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idJointConversion::resourceList__()
{
  idResourceList::idResourceList(this: &idJointConversion::resourceList, typeName: "jointconversion");
  idJointConversion::resourceList.__vftable = (idTypedResourceList<idJointConversion>_vtbl *)&idTypedResourceList<idJointConversion>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idJointConversion::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'animationLocal''
// EA  : 0x83343D98
// RVA : 0x01343D98
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationLocal__()
{
  idAnimationLocal::idAnimationLocal(this: &animationLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationLocal__);
}


// ========================================================================
// `dynamic initializer for 'idJointResource::resourceList''
// EA  : 0x83343DD0
// RVA : 0x01343DD0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idJointResource::resourceList__()
{
  idResourceList::idResourceList(this: &idJointResource::resourceList, typeName: "joint");
  idJointResource::resourceList.__vftable = (idTypedResourceList<idJointResource>_vtbl *)&idTypedResourceList<idJointResource>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idJointResource::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'anim_genScripts_v''
// EA  : 0x83343E20
// RVA : 0x01343E20
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_genScripts_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_genScripts_v,
           cmdName: "anim_genScripts",
           function: anim_genScripts_f,
           description: "auto-generates Maya MEL scripts for re-exporting existing models",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_bumpFormat2to3_v''
// EA  : 0x83343E48
// RVA : 0x01343E48
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_bumpFormat2to3_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_bumpFormat2to3_v,
           cmdName: "anim_bumpFormat2to3",
           function: anim_bumpFormat2to3_f,
           description: "bump the anim format of all animations in the base/md6 folder. This is a one-time use command and will need t"
           "o be customized each time the anim needs bumping.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_bumpFormat3to4_v''
// EA  : 0x83343E70
// RVA : 0x01343E70
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_bumpFormat3to4_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_bumpFormat3to4_v,
           cmdName: "anim_bumpFormat3to4",
           function: anim_bumpFormat3to4_f,
           description: "bump the anim format of all animations in the base/md6 folder. This is a one-time use command and will need t"
           "o be customized each time the anim needs bumping.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_checkVersions_v''
// EA  : 0x83343E98
// RVA : 0x01343E98
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_checkVersions_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_checkVersions_v,
           cmdName: "anim_checkVersions",
           function: anim_checkVersions_f,
           description: "check version info for all animations in the specified path",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_fixProps_v''
// EA  : 0x83343EC0
// RVA : 0x01343EC0
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_fixProps_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_fixProps_v,
           cmdName: "anim_fixProps",
           function: anim_fixProps_f,
           description: "fixes props that are in Maya space so that they're in idSpace",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_listWeakRefs_v''
// EA  : 0x83343EE8
// RVA : 0x01343EE8
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_listWeakRefs_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_listWeakRefs_v,
           cmdName: "anim_listWeakRefs",
           function: anim_listWeakRefs_f,
           description: "list all weak .md6anim references",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'anim_verifySources_v''
// EA  : 0x83343F10
// RVA : 0x01343F10
// PDB : w:\tech5\engine\models\skeletalanimation\animation.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__anim_verifySources_v__()
{
  return idCommandLink::idCommandLink(
           this: &anim_verifySources_v,
           cmdName: "anim_verifySources",
           function: anim_verifySources_f,
           description: "examines source references in .md6anim files to see how many are valid",
           argCompletion: nullptr);
}

