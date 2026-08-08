
// ========================================================================
// ?DefaultDefinition@idDeclMD6@@UBAPBDXZ
// EA  : 0x8280D118
// RVA : 0x0080D118
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const char *__fastcall idDeclMD6::DefaultDefinition(idDeclMD6 *this)
{
  return "{\n"
         "\tinit {\n"
         "\tmesh \"md6/default.md6mesh\"\n"
         "\t}\n"
         "\tuserProps {\n"
         "\t}\n"
         "\tjointGroups {\n"
         "\t}\n"
         "\tevents {\n"
         "\t}\n"
         "\taliases {\n"
         "\t}\n"
         "\tprops {\n"
         "\tprop \"_info\" {\n"
         "\t\t}\n"
         "\t}\n"
         "\teyeInfoCollection 0 {\n"
         "\t}\n"
         "}\n";
}


// ========================================================================
// ?StrongLoadAlias@idDeclMD6@@QBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280D128
// RVA : 0x0080D128
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::StrongLoadAlias(idDeclMD6 *this, const idDeclMD6 *result, const char *aliasName)
{
  animation->StrongLoadAlias(
    (idAnimation *)this,
    result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
    a3: result,
    a4: aliasName);
  return this;
}


// ========================================================================
// ?GetJointsForAnimTime@idDeclMD6@@QBA_NPAVidJointMat@@PBVidMD6Anim@@HABVidVec3@@_N@Z
// EA  : 0x8280D178
// RVA : 0x0080D178
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

BOOL __fastcall idDeclMD6::GetJointsForAnimTime(
        idDeclMD6 *this,
        idJointMat *joints,
        const idMD6Anim *anim,
        int timeMS,
        const idVec3 *offset,
        bool removeOriginOffset)
{
  return idMD6Model::GetJointsForAnimTime(this: this->model, joints, anim, timeMS, offset, removeOriginOffset);
}


// ========================================================================
// ?FindAliasHandle@idDeclMD6@@QBA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x8280D180
// RVA : 0x0080D180
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::FindAliasHandle(idDeclMD6 *this, const idDeclMD6 *result, const char *aliasName)
{
  animation->FindAliasHandle(
    (idAnimation *)this,
    result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
    a3: result,
    a4: aliasName);
  return this;
}


// ========================================================================
// ?Compare@idSort_AnimEventSort@@QBAHABH0@Z
// EA  : 0x8280DBE8
// RVA : 0x0080DBE8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idSort_AnimEventSort::Compare(idSort_AnimEventSort *this, int *a, int *b)
{
  const char *EventNameForNum; // r28
  const char *v7; // r3
  int result; // r3
  int v9; // r11
  int v10; // r10

  EventNameForNum = idEventDef::GetEventNameForNum(eventNum: this->animEventInfo->events.list[*a].eventNum);
  v7 = idEventDef::GetEventNameForNum(eventNum: this->animEventInfo->events.list[*b].eventNum);
  result = idStr::Cmp(s1: EventNameForNum, s2: v7);
  if ( result == 0 )
  {
    v9 = *a;
    v10 = *b;
    if ( this->animEventInfo->events.list[v9].frameNum >= this->animEventInfo->events.list[v10].frameNum )
    {
      if ( this->animEventInfo->events.list[v9].frameNum <= this->animEventInfo->events.list[v10].frameNum )
        return this->animEventInfo->events.list[v9].row - this->animEventInfo->events.list[v10].row;
      else
        return 1;
    }
    else
    {
      return -1;
    }
  }
  return result;
}


// ========================================================================
// ?FindAnimEventInfoIndex@idAnimEvents@@ABAHABV?$idAtomicStringT@W4md6AnimAtomicString_t@@@@@Z
// EA  : 0x8280DD08
// RVA : 0x0080DD08
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idAnimEvents::FindAnimEventInfoIndex(
        idAnimEvents *this,
        const idAtomicStringT<enum md6AnimAtomicString_t> *animRef)
{
  int lookupMask; // r7
  int v3; // r11

  lookupMask = this->hashIndex.lookupMask;
  v3 = this->hashIndex.hash[this->hashIndex.hashMask & lookupMask & (int)animRef->str];
  if ( v3 == -1 )
    return -1;
  while ( this->list.list[v3].animRef.str != animRef->str )
  {
    v3 = this->hashIndex.indexChain[lookupMask & v3];
    if ( v3 == -1 )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?GetNextEventId@idAnimEvents@@SA?AV?$idHandle@IW4invalidAnimEventId_t@@$0A@@@XZ
// EA  : 0x8280DD78
// RVA : 0x0080DD78
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idHandle<unsigned int,enum invalidAnimEventId_t,0> *__fastcall idAnimEvents::GetNextEventId(
        idHandle<unsigned int,enum invalidAnimEventId_t,0> *result)
{
  unsigned int v1; // r10

  v1 = ++idAnimEvents::curEventId.value;
  if ( idAnimEvents::curEventId.value == 0 )
  {
    v1 = 1;
    idAnimEvents::curEventId.value = 1;
  }
  result->value = v1;
  return result;
}


// ========================================================================
// ??8animEventInfo_t@idAnimEvents@@QBA_NABU01@@Z
// EA  : 0x8280DDA0
// RVA : 0x0080DDA0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idAnimEvents::animEventInfo_t::operator==(
        idAnimEvents::animEventInfo_t *this,
        const idAnimEvents::animEventInfo_t *other)
{
  int num; // r11
  int v6; // r28
  int i; // r31

  if ( idStr::Icmp(s1: this->animRef.str, s2: other->animRef.str) != 0 )
    return 0;
  num = this->events.num;
  if ( num != other->events.num )
    return 0;
  v6 = 0;
  if ( num > 0 )
  {
    for ( i = 0; !idMD6AnimEvent::operator!=(this: &this->events.list[i], other: &other->events.list[i]); ++i )
    {
      if ( ++v6 >= this->events.num )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?HasIncludedDecl@idDeclMD6@@AAA_NPBV1@@Z
// EA  : 0x8280DE38
// RVA : 0x0080DE38
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idDeclMD6::HasIncludedDecl(idDeclMD6 *this, const idDeclMD6 *includeDecl)
{
  int num; // r8
  int v3; // r10
  int i; // r11

  if ( includeDecl != this && this->parentDecl != includeDecl )
  {
    num = this->declsToIncludeAnimDataFrom.num;
    v3 = 0;
    if ( num <= 0 )
      return 0;
    for ( i = 0; this->declsToIncludeAnimDataFrom.list[i].includeDecl != includeDecl; ++i )
    {
      if ( ++v3 >= num )
        return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?FindAlias@idDeclMD6@@QBAPBVidMD6Alias@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_N@Z
// EA  : 0x8280DE90
// RVA : 0x0080DE90
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const idMD6Alias *__fastcall idDeclMD6::FindAlias(
        idDeclMD6 *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        bool includeInherited)
{
  int lookupMask; // r7
  int value; // r9
  int v7; // r11
  idMD6Alias *list; // r8
  const idMD6Alias *result; // r3
  idDeclMD6 *parentDecl; // r3
  int v11; // r29
  int i; // r30

  lookupMask = this->aliasHash.lookupMask;
  value = aliasHandle->value;
  v7 = this->aliasHash.hash[this->aliasHash.hashMask & lookupMask & value];
  if ( v7 == -1 )
  {
LABEL_5:
    if ( !includeInherited )
      return nullptr;
    parentDecl = this->parentDecl;
    if ( parentDecl != nullptr )
    {
      result = idDeclMD6::FindAlias(this: parentDecl, aliasHandle, includeInherited: true);
      if ( result != nullptr )
        return result;
    }
    v11 = 0;
    if ( this->declsToIncludeAnimDataFrom.num <= 0 )
      return nullptr;
    for ( i = 0; ; ++i )
    {
      result = idDeclMD6::FindAlias(
                 this: this->declsToIncludeAnimDataFrom.list[i].includeDecl,
                 aliasHandle,
                 includeInherited: false);
      if ( result != nullptr )
        break;
      if ( ++v11 >= this->declsToIncludeAnimDataFrom.num )
        return nullptr;
    }
  }
  else
  {
    list = this->aliases.list;
    while ( 1 )
    {
      result = &list[v7];
      if ( result->aliasHandle.value == value )
        break;
      v7 = this->aliasHash.indexChain[lookupMask & v7];
      if ( v7 == -1 )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ?GetJointName@idDeclMD6@@QBAPBDV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x8280DF80
// RVA : 0x0080DF80
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const char *__fastcall idDeclMD6::GetJointName(idDeclMD6 *this, const idIndex<short,enum invalidJointIndex_t> *idx)
{
  _WORD v3[4]; // [sp+50h] [-10h] BYREF

  idMD6Skel::GetJointHandle(
    this: (idMD6Skel *)v3,
    result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this->model->skeleton,
    jointIdx: (__int16)idx);
  if ( v3[0] == 0xFFFF )
    return nullptr;
  else
    return animation->GetJointName(
             this: animation,
             a2: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v3);
}


// ========================================================================
// ?FindUserProp@idDeclMD6@@QBAPBV?$idVarArgs@$05@@PBD@Z
// EA  : 0x8280DFF0
// RVA : 0x0080DFF0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const idVarArgs<6> *__fastcall idDeclMD6::FindUserProp(idDeclMD6 *this, const char *name)
{
  int v4; // r29
  int i; // r30
  const char *v6; // r4
  idVarArgs<6> *v7; // r11

  v4 = 0;
  if ( this->userProps.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = nullptr;
    v7 = &this->userProps.list[i];
    if ( v7->numArgs != 0 && v7->argTypes[0] == 8 )
      v6 = (const char *)&v7->args[v7->argOffsets[0]];
    if ( idStr::Icmp(s1: name, s2: v6) == 0 )
      break;
    if ( ++v4 >= this->userProps.num )
      return nullptr;
  }
  return &this->userProps.list[v4];
}


// ========================================================================
// __unwind$229630
// EA  : 0x8280E4B4
// RVA : 0x0080E4B4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_229630()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 760);
}


// ========================================================================
// __unwind$229631
// EA  : 0x8280E4DC
// RVA : 0x0080E4DC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_229631()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 759);
}


// ========================================================================
// ?GetHeadTrackGroupIndex@idDeclMD6@@QBAHPBD@Z
// EA  : 0x8280E508
// RVA : 0x0080E508
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idDeclMD6::GetHeadTrackGroupIndex(idDeclMD6 *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->headTrackGroups.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: this->headTrackGroups.list[i].name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->headTrackGroups.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?IsChildOf@idDeclMD6@@QBA_NPBV1@@Z
// EA  : 0x8280E578
// RVA : 0x0080E578
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idDeclMD6::IsChildOf(idDeclMD6 *this, const idDeclMD6 *decl)
{
  const idDeclMD6 *parentDecl; // r11
  int num; // r7
  int v4; // r9
  int i; // r10
  const idDeclMD6 *includeDecl; // r11

  parentDecl = this->parentDecl;
  if ( parentDecl != nullptr )
  {
    while ( parentDecl != decl )
    {
      parentDecl = parentDecl->parentDecl;
      if ( parentDecl == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    num = this->declsToIncludeAnimDataFrom.num;
    v4 = 0;
    if ( num <= 0 )
      return 0;
    for ( i = 0; ; ++i )
    {
      includeDecl = this->declsToIncludeAnimDataFrom.list[i].includeDecl;
      if ( includeDecl != nullptr )
        break;
LABEL_9:
      if ( ++v4 >= num )
        return 0;
    }
    while ( includeDecl != decl )
    {
      includeDecl = includeDecl->parentDecl;
      if ( includeDecl == nullptr )
        goto LABEL_9;
    }
  }
  return 1;
}


// ========================================================================
// ?GetJointList@idDeclMD6@@QBAXPBDAAV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@@Z
// EA  : 0x8280E5F0
// RVA : 0x0080E5F0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::GetJointList(
        idDeclMD6 *this,
        const char *joints,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *jointList)
{
  const idMD6Model *model; // r11
  idMD6Skel *skeleton; // r3

  model = this->model;
  if ( model != nullptr )
    skeleton = model->skeleton;
  else
    skeleton = nullptr;
  if ( skeleton != nullptr )
    idMD6Skel::GetJointList(this: skeleton, model, jointNames: joints, jointList);
}


// ========================================================================
// ?GetUserChannelWeightGroup@idDeclMD6@@QBA?AW4md6WeightGroup_t@@XZ
// EA  : 0x8280E628
// RVA : 0x0080E628
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idDeclMD6::GetUserChannelWeightGroup(idDeclMD6 *this)
{
  int userChannelWeightGroupOverride; // r9
  char v3; // r10

  while ( 1 )
  {
    userChannelWeightGroupOverride = this->userChannelWeightGroupOverride;
    if ( userChannelWeightGroupOverride < 0 || (v3 = 1, userChannelWeightGroupOverride >= 8) )
      v3 = 0;
    if ( v3 != 0 )
      break;
    this = this->parentDecl;
    if ( this == nullptr )
      return 0;
  }
  return this->userChannelWeightGroupOverride;
}


// ========================================================================
// ?SplitPath@idAnimWebPath@@SAXPBDAAVidStr@@11@Z
// EA  : 0x8280E670
// RVA : 0x0080E670
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::SplitPath(const char *path, idStr *webName, idStr *subWebName, idStr *stateName)
{
  int v8; // r26
  int v9; // r31
  int v10; // r30
  int v11; // r5
  const char *v12; // r4

  idStr::EnsureAlloced(this: webName, amount: 1, keepold: true, geometricGrowth: false);
  *webName->data = 0;
  webName->len = 0;
  idStr::EnsureAlloced(this: subWebName, amount: 1, keepold: true, geometricGrowth: false);
  *subWebName->data = 0;
  subWebName->len = 0;
  idStr::EnsureAlloced(this: stateName, amount: 1, keepold: true, geometricGrowth: false);
  *stateName->data = 0;
  stateName->len = 0;
  if ( path != nullptr && *path != 0 )
  {
    v8 = 0;
    do
      ++v8;
    while ( path[v8] != 0 );
    if ( path[v8 - 1] == 47 )
    {
      idStr::operator=(this: webName, text: path);
    }
    else
    {
      if ( v8 > 0 )
      {
        v9 = v8 - 1;
        while ( path[v9] != 0 )
        {
          if ( path[v9] == 47 )
          {
            if ( v9 == -1 )
              break;
            if ( v9 > 0 )
            {
              v10 = v9 - 1;
              while ( path[v10] != 0 )
              {
                if ( path[v10] == 47 )
                {
                  if ( v10 == -1 )
                    break;
                  idStr::Append(this: webName, text: path, l: v10);
                  v12 = &path[v10 + 1];
                  v11 = v9 - v10 - 1;
                  goto LABEL_24;
                }
                if ( --v10 < 0 )
                {
                  v11 = v9;
                  v12 = path;
                  goto LABEL_24;
                }
              }
            }
            v11 = v9;
            v12 = path;
LABEL_24:
            idStr::Append(this: subWebName, text: v12, l: v11);
            idStr::Append(this: stateName, text: &path[v9 + 1], l: v8 - v9 - 1);
            return;
          }
          if ( --v9 < 0 )
            break;
        }
      }
      idStr::operator=(this: stateName, text: path);
    }
  }
}


// ========================================================================
// ?GetWebName@idAnimWebPath@@QBAXAAVidStr@@@Z
// EA  : 0x8280E840
// RVA : 0x0080E840
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::GetWebName(idAnimWebPath *this, idStr *webName)
{
  idStr v2; // [sp+50h] [-50h] BYREF
  idStr v3; // [sp+70h] [-30h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  v2.allocedAndFlag = 20;
  v2.data = v2.baseBuffer;
  v2.len = 0;
  v2.baseBuffer[0] = 0;
  idAnimWebPath::SplitPath(path: this->data, webName, subWebName: &v3, stateName: &v2);
  idStr::FreeData(this: &v2);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$230087
// EA  : 0x8280E8B8
// RVA : 0x0080E8B8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_230087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$230088_0
// EA  : 0x8280E8E0
// RVA : 0x0080E8E0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_230088_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetSubWebName@idAnimWebPath@@QBAXAAVidStr@@@Z
// EA  : 0x8280E910
// RVA : 0x0080E910
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::GetSubWebName(idAnimWebPath *this, idStr *subWebName)
{
  idStr v2; // [sp+50h] [-50h] BYREF
  idStr v3; // [sp+70h] [-30h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  v2.allocedAndFlag = 20;
  v2.data = v2.baseBuffer;
  v2.len = 0;
  v2.baseBuffer[0] = 0;
  idAnimWebPath::SplitPath(path: this->data, webName: &v3, subWebName, stateName: &v2);
  idStr::FreeData(this: &v2);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$230164
// EA  : 0x8280E98C
// RVA : 0x0080E98C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_230164()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$230165
// EA  : 0x8280E9B4
// RVA : 0x0080E9B4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_230165()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetWebPathNames@idAnimWebPath@@QBAXAAVidStr@@00@Z
// EA  : 0x8280E9E0
// RVA : 0x0080E9E0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::GetWebPathNames(
        idAnimWebPath *this,
        idStr *webName,
        idStr *subWebName,
        idStr *stateName)
{
  idAnimWebPath::SplitPath(path: this->data, webName, subWebName, stateName);
}


// ========================================================================
// ?GetWebPathNames@idAnimWebPath@@QBAXAAVidStr@@0@Z
// EA  : 0x8280E9F0
// RVA : 0x0080E9F0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::GetWebPathNames(idAnimWebPath *this, idStr *subWebName, idStr *stateName)
{
  idStr v3; // [sp+50h] [-30h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  idAnimWebPath::SplitPath(path: this->data, webName: &v3, subWebName, stateName);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$230324
// EA  : 0x8280EA50
// RVA : 0x0080EA50
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_230324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?GenMorphVerts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8280EE68
// RVA : 0x0080EE68
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall GenMorphVerts_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idDecl *v2; // r30
  idResource *declSource; // r4

  if ( args->argc == 2 )
  {
    v1 = args->argv[1];
    if ( v1 != nullptr )
    {
      v2 = (idDecl *)idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: v1, makeDefault: false);
      if ( v2 != nullptr )
      {
        idCVar::SetBool(this: &md6_ForceGenMorphVerts, newValue: true, force: true);
        declSource = (idResource *)v2[11].declSource;
        if ( declSource != nullptr )
          idResourceList::Remove(this: &idMorphVertices::resourceList, ptr: declSource);
        idDecl::ReParse(this: v2, fromDisk: true);
        cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "reloaddecls");
        idCVar::SetBool(this: &md6_ForceGenMorphVerts, newValue: false, force: true);
      }
    }
  }
}


// ========================================================================
// ?FindAlias@idDeclMD6@@QBAPBVidMD6Alias@@PBD_N@Z
// EA  : 0x8280EF90
// RVA : 0x0080EF90
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const idMD6Alias *__fastcall idDeclMD6::FindAlias(idDeclMD6 *this, const char *aliasName, bool includeInherited)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v6[4]; // [sp+50h] [-20h] BYREF

  ((void (__fastcall *)(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *))animation->FindAliasHandle_2)(a1: v6);
  if ( v6[0].value == 0xFFFF )
    return nullptr;
  else
    return idDeclMD6::FindAlias(this, aliasHandle: v6, includeInherited);
}


// ========================================================================
// ?AnimForAlias@idDeclMD6@@QBAPBVidMD6Anim@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_N@Z
// EA  : 0x8280F008
// RVA : 0x0080F008
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

const idMD6Anim *__fastcall idDeclMD6::AnimForAlias(
        idDeclMD6 *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        const bool load)
{
  const idMD6Alias *Alias; // r3
  char *v7; // r3

  if ( aliasHandle->value == 0xFFFF )
    return nullptr;
  Alias = idDeclMD6::FindAlias(this, aliasHandle, includeInherited: true);
  if ( Alias != nullptr )
    return (const idMD6Anim *)idResourceList::FindExisting(
                                this: &idMD6Anim::resourceList,
                                name: (char *)Alias->animRefs.list->str,
                                skipStaleCheck: true);
  if ( !load )
    return nullptr;
  v7 = (char *)animation->FindAliasName(this: animation, a2: aliasHandle);
  return (const idMD6Anim *)idResourceList::Load(
                              this: &idMD6Anim::resourceList,
                              name: v7,
                              makeDefault: true,
                              skipStaleCheck: true);
}


// ========================================================================
// ?SetPath@idAnimWebPath@@QAAXPBD00@Z
// EA  : 0x8280F0C0
// RVA : 0x0080F0C0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimWebPath::SetPath(idAnimWebPath *this, char *webName, char *subWebName, char *stateName)
{
  idStr::EnsureAlloced(this, amount: 1, keepold: true, geometricGrowth: false);
  *this->data = 0;
  this->len = 0;
  if ( webName != nullptr && *webName != 0 )
  {
    idStr::Append(this, text: webName);
    idStr::Append(this, a: 47);
  }
  if ( subWebName != nullptr && *subWebName != 0 )
  {
    idStr::Append(this, text: subWebName);
    idStr::Append(this, a: 47);
  }
  idStr::Append(this, text: stateName);
}


// ========================================================================
// ?reportMD6boneCounts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8280F1D8
// RVA : 0x0080F1D8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall reportMD6boneCounts_f(const idCmdArgs *args)
{
  int i; // r30
  int j; // r30
  idResource *v3; // r3
  int v4; // r11
  unsigned int v5; // r5
  char v6; // r11

  for ( i = 0; i < idDeclMD6::resourceList.declSources.num; ++i )
    idResourceList::Load(
      this: &idDeclMD6::resourceList,
      name: (char *)idDeclMD6::resourceList.declSources.list[i]->name.str,
      makeDefault: true,
      skipStaleCheck: false);
  for ( j = 0; j < idMD6Model::resourceList.num; ++j )
  {
    v3 = idResourceList::Index(this: &idMD6Model::resourceList, index: j);
    v4 = *((_DWORD *)&v3[5] + 8);
    if ( v4 != 0 )
    {
      v5 = *(unsigned __int16 *)(*(_DWORD *)(v4 + 40) + 2);
      v6 = 42;
      if ( v5 <= 0x91 )
        v6 = 32;
      idLib::Printf(fmt: "%c%3i %s\n", v6, v5, v3->name.str);
    }
  }
}


// ========================================================================
// $M232424
// EA  : 0x8280F2D8
// RVA : 0x0080F2D8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void *_M232424()
{
  return &_LN16_0;
}


// ========================================================================
// ?Write@idAnimEvents@@QBAXPBVidDeclMD6@@AAVidFile_String@@PBD@Z
// EA  : 0x8280F920
// RVA : 0x0080F920
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimEvents::Write(idAnimEvents *this, const idDeclMD6 *decl, __int64 indent, __int64 a4, __int64 a5)
{
  char *data; // r4
  idFile_String *v8; // r26
  int v9; // r23
  const idDecl *v10; // r3
  idAnimEvents *v11; // r22
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  va *v16; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  int v20; // r17
  idAnimEvents::animEventInfo_t *list; // r11
  idSort_Quick<int,idSort_AnimEventSort>_vtbl *v22; // r28
  int AnimEventInfoIndex; // r3
  const idAnimEvents::animEventInfo_t *v24; // r4
  __int64 v25; // r6
  va *v26; // r3
  unsigned int i; // r5
  __int64 v28; // r8
  __int64 v29; // r6
  int *v30; // r27
  signed int num; // r30
  __int64 v32; // r10
  int v33; // r29
  void (__fastcall *v34)(struct idSort_Quick<int,idSort_AnimEventSort> *); // r11
  int *v35; // r29
  va *v36; // r3
  unsigned int j; // r5
  va *v38; // r3
  unsigned int k; // r5
  int v40; // [sp+8h] [-2128h]
  int v41; // [sp+8h] [-2128h]
  int v42; // [sp+8h] [-2128h]
  int v43; // [sp+8h] [-2128h]
  int v44; // [sp+Ch] [-2124h]
  int v45; // [sp+Ch] [-2124h]
  int v46; // [sp+Ch] [-2124h]
  int v47; // [sp+Ch] [-2124h]
  int v48; // [sp+10h] [-2120h]
  int v49; // [sp+10h] [-2120h]
  int v50; // [sp+10h] [-2120h]
  int v51; // [sp+10h] [-2120h]
  int v52; // [sp+14h] [-211Ch]
  int v53; // [sp+14h] [-211Ch]
  int v54; // [sp+14h] [-211Ch]
  int v55; // [sp+14h] [-211Ch]
  int v56; // [sp+18h] [-2118h]
  int v57; // [sp+18h] [-2118h]
  int v58; // [sp+18h] [-2118h]
  int v59; // [sp+18h] [-2118h]
  int v60; // [sp+1Ch] [-2114h]
  int v61; // [sp+1Ch] [-2114h]
  int v62; // [sp+1Ch] [-2114h]
  int v63; // [sp+1Ch] [-2114h]
  idList<enum encounterGroupRole_t,5> v64; // [sp+50h] [-20E0h] BYREF
  int v65; // [sp+60h] [-20D0h] BYREF
  int v66; // [sp+64h] [-20CCh]
  idSort_Quick<int,idSort_AnimEventSort> v67[2]; // [sp+68h] [-20C8h] BYREF
  idStr v68; // [sp+70h] [-20C0h] BYREF
  va v69; // [sp+90h] [-20A0h] BYREF
  va v70; // [sp+1090h] [-10A0h] BYREF

  data = decl->parent.data;
  v8 = (idFile_String *)HIDWORD(indent);
  v9 = indent;
  if ( data == nullptr
    || *data == 0
    || (v10 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: data, makeDefault: true),
        v11 = (idAnimEvents *)((char *)&v10[6].idResource + 32),
        v10 == nullptr) )
  {
    v11 = nullptr;
  }
  HIDWORD(indent) = v9;
  v12 = va::va(
          this: &v69,
          fmt: "%sevents {\n",
          a3: indent,
          a4,
          a5,
          a6: v40,
          a7: v44,
          a8: v48,
          a9: v52,
          a10: v56,
          a11: v60);
  idFile_String::operator+=(this: v8, str: v12->buffer);
  LODWORD(v13) = byte_821B0000;
  HIDWORD(v14) = v9;
  v16 = va::va(
          this: &v69,
          fmt: "%s\t\t",
          a3: v14,
          a4: v15,
          a5: v13,
          a6: v41,
          a7: v45,
          a8: v49,
          a9: v53,
          a10: v57,
          a11: v61);
  idStr::idStr(this: &v68, text: v16);
  HIDWORD(v19) = this->list.num;
  v66 = 0;
  if ( SHIDWORD(v19) > 0 )
  {
    LODWORD(v19) = &unk_82210000;
    HIDWORD(v19) = allocationCurrent[242];
    LODWORD(v17) = byte_821B0000;
    HIDWORD(v17) = &unk_82210000;
    v20 = 0;
    do
    {
      list = this->list.list;
      v22 = (idSort_Quick<int,idSort_AnimEventSort>_vtbl *)&list[v20];
      if ( v11 == nullptr
        || (AnimEventInfoIndex = idAnimEvents::FindAnimEventInfoIndex(this: v11, animRef: &list[v20].animRef)) < 0
        || (LODWORD(v19) = v11->list.list,
            (v24 = (const idAnimEvents::animEventInfo_t *)(20 * AnimEventInfoIndex + v19)) == nullptr)
        || (unsigned __int8)idAnimEvents::animEventInfo_t::operator==(
                              this: (idAnimEvents::animEventInfo_t *)v22,
                              other: v24) == 0 )
      {
        LODWORD(v25) = v22->dtr_idSort<int>;
        HIDWORD(v25) = v9;
        v26 = va::va(
                this: &v70,
                fmt: "%s\tanim \"%s\" {\n",
                a3: v25,
                a4: v17,
                a5: v19,
                a6: v42,
                a7: v46,
                a8: v50,
                a9: v54,
                a10: v58,
                a11: v62);
        for ( i = 0; v26->buffer[i] != 0; ++i )
          ;
        v8->Write(this: v8, a2: v26, a3: i);
        v30 = nullptr;
        num = 0;
        *(_WORD *)&v64.memTag = 1280;
        memset(&v64, 0, 14);
        HIDWORD(v32) = v22[1].dtr_idSort<int>;
        v33 = 0;
        v65 = 0;
        if ( SHIDWORD(v32) > 0 )
        {
          do
          {
            idList<idAnimWebBlendTree *,5>::Append(this: &v64, obj: (const encounterGroupRole_t *)&v65);
            v34 = v22[1].dtr_idSort<int>;
            v65 = ++v33;
          }
          while ( v33 < (int)v34 );
          num = v64.num;
          v30 = (int *)v64.list;
        }
        v67[1].__vftable = v22;
        v67[0].__vftable = (idSort_Quick<int,idSort_AnimEventSort>_vtbl *)&idSort_AnimEventSort::`vftable';
        if ( v30 != nullptr )
          idSort_Quick<int,idSort_AnimEventSort>::Sort(
            this: v67,
            base: v30,
            num,
            a4: v29,
            a5: SHIDWORD(v28),
            a6: v28,
            a7: v32);
        v67[0].__vftable = (idSort_Quick<int,idSort_AnimEventSort>_vtbl *)&idSort<int>::`vftable';
        if ( num > 0 )
        {
          v35 = v30 - 1;
          do
          {
            idMD6AnimEvent::Write(this: (idMD6AnimEvent *)v22->Sort + *++v35, md6: decl, file: v8, indent: v68.data);
            --num;
          }
          while ( num != 0 );
        }
        HIDWORD(v29) = v9;
        v36 = va::va(
                this: &v70,
                fmt: "%s\t}\n",
                a3: v29,
                a4: v28,
                a5: v32,
                a6: v43,
                a7: v47,
                a8: v51,
                a9: v55,
                a10: v59,
                a11: v63);
        for ( j = 0; v36->buffer[j] != 0; ++j )
          ;
        v8->Write(this: v8, a2: v36, a3: j);
        if ( v64.listStatic == 0 || v64.listStatic == 2 )
        {
          if ( v30 != nullptr )
            idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
          v64.list = nullptr;
          v64.size = 0;
        }
        v64.num = 0;
      }
      ++v20;
      LODWORD(v19) = this->list.num;
      ++v66;
    }
    while ( v66 < (int)v19 );
  }
  HIDWORD(v18) = v9;
  v38 = va::va(
          this: &v70,
          fmt: "%s}\n",
          a3: v18,
          a4: v17,
          a5: v19,
          a6: v42,
          a7: v46,
          a8: v50,
          a9: v54,
          a10: v58,
          a11: v62);
  for ( k = 0; v38->buffer[k] != 0; ++k )
    ;
  v8->Write(this: v8, a2: v38, a3: k);
  idStr::FreeData(this: &v68);
}


// ========================================================================
// __unwind$233362
// EA  : 0x8280FC60
// RVA : 0x0080FC60
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_233362()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8496 + 112));
}


// ========================================================================
// __unwind$233363
// EA  : 0x8280FC88
// RVA : 0x0080FC88
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_233363()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8496 + 80));
}


// ========================================================================
// __unwind$233364
// EA  : 0x8280FCB0
// RVA : 0x0080FCB0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_233364()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 8496 + 104));
}


// ========================================================================
// ?CacheTransforms@idAnimEvents@@QAA_NPAVidDeclMD6@@@Z
// EA  : 0x8280FCE0
// RVA : 0x0080FCE0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

int __fastcall idAnimEvents::CacheTransforms(idAnimEvents *this, idDeclMD6 *decl)
{
  int num; // r10
  idAnimEvents *v3; // r29
  int v5; // r23
  idAnimEvents::animEventInfo_t *list; // r11
  const char **p_str; // r21
  idMD6AnimEvent *v8; // r30
  const idEventDef *EventCommand; // r3
  const char **p_name; // r25
  int numargs; // r15
  int v12; // r29
  unsigned __int16 *argOffsets; // r22
  int v14; // r20
  char v15; // r11
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  idResource *v18; // r3
  const idMD6Anim *v19; // r5
  int trackedMemory; // r11
  signed int v21; // r9
  int frameNum; // r6
  int value; // r11
  idMD6Model *v24; // r3
  double v25; // fp13
  double v26; // fp12
  double v27; // fp11
  double v28; // fp10
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6
  double v33; // fp5
  double v34; // fp4
  double v35; // fp3
  const idQuat *v36; // r7
  const idVec3 *p_resourceError; // r6
  int v38; // r5
  char v39; // r11
  int v40; // r29
  const idTagInfo *Tag; // r3
  const idMD6Model *v42; // r11
  idIndex<short,enum invalidJointIndex_t> *v43; // r3
  idResource *v44; // r3
  const idMD6Anim *v45; // r5
  int v46; // r11
  signed int v47; // r9
  int v48; // r6
  int v49; // r11
  idMD6Model *v50; // r3
  double v51; // fp13
  double v52; // fp12
  double v53; // fp11
  double v54; // fp10
  double v55; // fp9
  double v56; // fp8
  double v57; // fp7
  double v58; // fp6
  double v59; // fp5
  double v60; // fp4
  double v61; // fp3
  const idQuat *p_y; // r7
  const idVec3 *p_trackedMemory; // r6
  int v64; // r5
  const char *v65; // r9
  int v66; // r9
  idIndex<short,enum invalidJointIndex_t> v68; // [sp+50h] [-31B0h] BYREF
  idIndex<short,enum invalidJointIndex_t> v69; // [sp+52h] [-31AEh] BYREF
  idIndex<short,enum invalidJointIndex_t> *skeleton; // [sp+54h] [-31ACh]
  int v71; // [sp+58h] [-31A8h]
  unsigned int v72; // [sp+5Ch] [-31A4h]
  __int16 v73; // [sp+60h] [-31A0h] BYREF
  __int16 v74; // [sp+62h] [-319Eh] BYREF
  int v75; // [sp+64h] [-319Ch]
  int v76; // [sp+68h] [-3198h]
  const char *v77; // [sp+6Ch] [-3194h]
  const char *v78; // [sp+70h] [-3190h]
  idMD6Skel v79; // [sp+74h] [-318Ch] BYREF
  int v80; // [sp+A8h] [-3158h]
  char v81; // [sp+ACh] [-3154h] BYREF
  idStr v82; // [sp+C0h] [-3140h] BYREF
  idQuat v83; // [sp+E0h] [-3120h] BYREF
  float v84; // [sp+F0h] [-3110h]
  float v85; // [sp+F4h] [-310Ch]
  float v86; // [sp+F8h] [-3108h]
  float v87; // [sp+FCh] [-3104h]
  float v88; // [sp+100h] [-3100h]
  idQuat v89; // [sp+110h] [-30F0h] BYREF
  float v90; // [sp+120h] [-30E0h]
  float v91; // [sp+124h] [-30DCh]
  float v92; // [sp+128h] [-30D8h]
  float v93; // [sp+12Ch] [-30D4h]
  float v94; // [sp+130h] [-30D0h]
  idMat3 v95[5]; // [sp+140h] [-30C0h] BYREF

  num = this->list.num;
  v76 = 0;
  v3 = this;
  v5 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  if ( num > 0 )
  {
    v72 = 0;
    v78 = "Anim event '%s' specifies an invalid joint tag '%s' in MD6 decl '%s'";
    v77 = "Anim event '%s' specifies an invalid joint name '%s' in MD6 decl '%s'";
    do
    {
      list = v3->list.list;
      v75 = 0;
      p_str = &list[v72 / 0x14].animRef.str;
      if ( list[v72 / 0x14].events.num > 0 )
      {
        v71 = 0;
        do
        {
          v8 = (idMD6AnimEvent *)&p_str[1][v71];
          EventCommand = idEventDef::GetEventCommand(eventnum: v8->eventNum);
          p_name = &EventCommand->name;
          if ( EventCommand != nullptr )
          {
            numargs = EventCommand->numargs;
            if ( numargs > 1 )
            {
              v12 = 0;
              argOffsets = v8->args.argOffsets;
              do
              {
                v14 = v12 + 1;
                if ( p_name[1][v12 + 1] == 50 )
                {
                  v80 = 20;
                  v79.timestamp = 0;
                  *(_DWORD *)&v79.jointConversion.value = &v81;
                  v81 = 0;
                  if ( v12 < 0 || (v15 = 1, v12 >= v8->args.numArgs) )
                    v15 = 0;
                  if ( v15 != 0 && v8->args.argTypes[v12] == 8 )
                    idStr::operator=(this: (idStr *)&v79.timestamp, text: (const char *)&v8->args.args[*argOffsets]);
                  model = decl->model;
                  if ( model != nullptr
                    && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
                  {
                    JointIndex = idMD6Skel::GetJointIndex(
                                   this: &v79,
                                   result: skeleton,
                                   name: *(const char **)&v79.jointConversion.value);
                  }
                  else
                  {
                    JointIndex = (idIndex<short,enum invalidJointIndex_t> *)&v74;
                    v74 = -1;
                  }
                  v69.value = JointIndex->value;
                  if ( v69.value >= 0 )
                  {
                    v18 = idResourceList::Load(
                            this: &idMD6Anim::resourceList,
                            name: (char *)*p_str,
                            makeDefault: true,
                            skipStaleCheck: false);
                    v19 = (const idMD6Anim *)v18;
                    if ( v18 != nullptr && (trackedMemory = v18[1].trackedMemory) != 0 )
                    {
                      v21 = *(unsigned __int16 *)(trackedMemory + 10);
                      frameNum = v8->frameNum;
                      value = timeManager.gameTimePerFrame.value;
                      __twllei(v21, 0);
                      v24 = decl->model;
                      __twlgei(v21 & ~(__ROL4__(frameNum * v5, 1) - 1), 0xFFFFFFFF);
                      idMD6Model::GetJointsForAnimTime(
                        this: v24,
                        joints: (idJointMat *)&v95[0].mat[2].z,
                        anim: v19,
                        timeMS: frameNum * v5 / v21 - value,
                        offset: &vec3_origin,
                        removeOriginOffset: false);
                      skeleton = (idIndex<short,enum invalidJointIndex_t> *)&v95[0].mat[4 * v69.value + 2].z;
                      v25 = *(float *)&skeleton[2].value;
                      v26 = *(float *)&skeleton[4].value;
                      v27 = *(float *)&skeleton[8].value;
                      v28 = *(float *)&skeleton[10].value;
                      v29 = *(float *)&skeleton[12].value;
                      v30 = *(float *)&skeleton[16].value;
                      v31 = *(float *)&skeleton[18].value;
                      v32 = *(float *)&skeleton[20].value;
                      v33 = *(float *)&skeleton[6].value;
                      v34 = *(float *)&skeleton[14].value;
                      v35 = *(float *)&skeleton[22].value;
                      v89.x = *(float *)&skeleton->value;
                      v89.w = v25;
                      v92 = v26;
                      v89.y = v27;
                      v90 = v28;
                      v93 = v29;
                      v89.z = v30;
                      v91 = v31;
                      v94 = v32;
                      *(float *)&v79.resourceError = v33;
                      *(float *)&v79.networkID = v34;
                      *(float *)&v79.staleCount = v35;
                      idMat3::ToQuat(this: v95, result: &v89);
                      v36 = (const idQuat *)v95;
                      p_resourceError = (const idVec3 *)&v79.resourceError;
                      v38 = v8->frameNum;
                    }
                    else
                    {
                      idLib::Warning(
                        fmt: "Anim event '%s' requires joint caching but references an invalid animation '%s'",
                        *p_name,
                        *p_str);
                      v36 = &quat_identity;
                      p_resourceError = &vec3_origin;
                      v38 = v8->frameNum;
                    }
                    idMD6AnimEvent::SetCachedJoint(this: v8, ji: &v69, frameNum: v38, trans: p_resourceError, rot: v36);
                  }
                  else if ( v79.timestamp != 0 )
                  {
                    idLib::Warning(fmt: v77, *p_name, *(_DWORD *)&v79.jointConversion.value, decl->name.str);
                  }
                  idStr::FreeData(this: (idStr *)&v79.timestamp);
                }
                if ( p_name[1][v14] == 53 )
                {
                  v82.allocedAndFlag = 20;
                  v82.len = 0;
                  v82.data = v82.baseBuffer;
                  v82.baseBuffer[0] = 0;
                  if ( v12 < 0 || (v39 = 1, v12 >= v8->args.numArgs) )
                    v39 = 0;
                  if ( v39 != 0 && v8->args.argTypes[v12] == 8 )
                    idStr::operator=(this: &v82, text: (const char *)&v8->args.args[*argOffsets]);
                  v68.value = -1;
                  if ( decl != (idDeclMD6 *)-352 )
                  {
                    v40 = 0;
                    if ( decl->props.props.num > 0 )
                    {
                      while ( 1 )
                      {
                        Tag = idPropsCollection::FindTag(this: &decl->props, propIdx: v40, tagName: v82.data);
                        if ( Tag != nullptr )
                          break;
                        if ( ++v40 >= decl->props.props.num )
                          goto LABEL_45;
                      }
                      v42 = decl->model;
                      if ( v42 != nullptr
                        && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)v42->skeleton) != nullptr )
                      {
                        v43 = idMD6Skel::GetJointIndex(
                                this: (idMD6Skel *)((char *)&v79.__vftable + 2),
                                result: skeleton,
                                handle: &Tag->tagData.parentJoint);
                      }
                      else
                      {
                        v43 = (idIndex<short,enum invalidJointIndex_t> *)&v73;
                        v73 = -1;
                      }
                      v68.value = v43->value;
                    }
                  }
LABEL_45:
                  if ( v68.value >= 0 )
                  {
                    v44 = idResourceList::Load(
                            this: &idMD6Anim::resourceList,
                            name: (char *)*p_str,
                            makeDefault: true,
                            skipStaleCheck: false);
                    v45 = (const idMD6Anim *)v44;
                    if ( v44 != nullptr && (v46 = v44[1].trackedMemory) != 0 )
                    {
                      v47 = *(unsigned __int16 *)(v46 + 10);
                      v48 = v8->frameNum;
                      v49 = timeManager.gameTimePerFrame.value;
                      __twllei(v47, 0);
                      v50 = decl->model;
                      __twlgei(v47 & ~(__ROL4__(v48 * v5, 1) - 1), 0xFFFFFFFF);
                      idMD6Model::GetJointsForAnimTime(
                        this: v50,
                        joints: (idJointMat *)&v95[0].mat[2].z,
                        anim: v45,
                        timeMS: v48 * v5 / v47 - v49,
                        offset: &vec3_origin,
                        removeOriginOffset: false);
                      skeleton = (idIndex<short,enum invalidJointIndex_t> *)&v95[0].mat[4 * v68.value + 2].z;
                      v51 = *(float *)&skeleton[2].value;
                      v52 = *(float *)&skeleton[4].value;
                      v53 = *(float *)&skeleton[8].value;
                      v54 = *(float *)&skeleton[10].value;
                      v55 = *(float *)&skeleton[12].value;
                      v56 = *(float *)&skeleton[16].value;
                      v57 = *(float *)&skeleton[18].value;
                      v58 = *(float *)&skeleton[20].value;
                      v59 = *(float *)&skeleton[6].value;
                      v60 = *(float *)&skeleton[14].value;
                      v61 = *(float *)&skeleton[22].value;
                      v83.x = *(float *)&skeleton->value;
                      v83.w = v51;
                      v86 = v52;
                      v83.y = v53;
                      v84 = v54;
                      v87 = v55;
                      v83.z = v56;
                      v85 = v57;
                      v88 = v58;
                      *(float *)&v79.trackedMemory = v59;
                      *(float *)&v79.name.str = v60;
                      *(float *)&v79.nextOnHashChain = v61;
                      idMat3::ToQuat(this: (idMat3 *)&v95[0].mat[1].y, result: &v83);
                      p_y = (const idQuat *)&v95[0].mat[1].y;
                      p_trackedMemory = (const idVec3 *)&v79.trackedMemory;
                      v64 = v8->frameNum;
                    }
                    else
                    {
                      idLib::Warning(
                        fmt: "Anim event '%s' requires joint caching but references an invalid animation '%s'",
                        *p_name,
                        *p_str);
                      p_y = &quat_identity;
                      p_trackedMemory = &vec3_origin;
                      v64 = v8->frameNum;
                    }
                    idMD6AnimEvent::SetCachedJoint(this: v8, ji: &v68, frameNum: v64, trans: p_trackedMemory, rot: p_y);
                  }
                  else
                  {
                    idLib::Warning(fmt: v78, *p_name, v82.data, decl->name.str);
                  }
                  idStr::FreeData(this: &v82);
                }
                ++argOffsets;
                v12 = v14;
              }
              while ( v14 + 1 < numargs );
              v3 = this;
            }
          }
          v65 = p_str[2];
          ++v75;
          v71 += 44;
        }
        while ( v75 < (int)v65 );
      }
      v66 = v3->list.num;
      ++v76;
      v72 += 20;
    }
    while ( v76 < v66 );
  }
  return 1;
}


// ========================================================================
// __unwind$233705
// EA  : 0x828102D4
// RVA : 0x008102D4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_233705()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12800 + 160));
}


// ========================================================================
// __unwind$233706
// EA  : 0x828102FC
// RVA : 0x008102FC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_233706()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12800 + 192));
}


// ========================================================================
// ?ReadUserProp@idDeclMD6@@QBAXAAVidParser@@AAV?$idVarArgs@$05@@@Z
// EA  : 0x82810330
// RVA : 0x00810330
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::ReadUserProp(idDeclMD6 *this, idParser *src, idVarArgs<6> *prop)
{
  unsigned __int8 v5; // r3
  int v6; // r3
  idToken v7; // [sp+50h] [-100h] BYREF
  int v9; // [sp+9Ch] [-B4h]
  idAngles v10; // [sp+A0h] [-B0h] BYREF
  idVec3 v11; // [sp+B0h] [-A0h] BYREF
  idVec4 v12; // [sp+C0h] [-90h] BYREF
  idQuat v13[8]; // [sp+D0h] [-80h] BYREF

  idVarArgs<6>::ClearArgs(this: prop);
  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.floatvalue = -3.4028235e38;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idParser::ReadToken(this: src, token: &v7);
  idVarArgs<6>::AddArg(this: prop, val: v7.data, exType: 0);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v7);
  if ( idParser::ReadToken(this: src, token: &v7) )
  {
    while ( v7.type != 5 || v7.subtype != 47 )
    {
      if ( idStr::Cmp(s1: v7.data, s2: "bool") != 0 )
      {
        if ( idStr::Cmp(s1: v7.data, s2: "int") != 0 )
        {
          if ( idStr::Cmp(s1: v7.data, s2: "float") != 0 )
          {
            if ( idStr::Cmp(s1: v7.data, s2: "vec3") != 0 )
            {
              if ( idStr::Cmp(s1: v7.data, s2: "quat") != 0 )
              {
                if ( idStr::Cmp(s1: v7.data, s2: "vec4") != 0 )
                {
                  if ( idStr::Cmp(s1: v7.data, s2: "angles") != 0 )
                  {
                    if ( idStr::Cmp(s1: v7.data, s2: "string") != 0 )
                    {
                      if ( idStr::Cmp(s1: v7.data, s2: "decl") == 0 )
                      {
                        idLib::Error(fmt: "Decl references are no longer supported in userProps.");
                        _LN91();
                        return;
                      }
                    }
                    else
                    {
                      idParser::ReadToken(this: src, token: &v7);
                      idVarArgs<6>::AddArg(this: prop, val: v7.data, exType: 0);
                    }
                  }
                  else
                  {
                    idParser::Parse1DMatrix(this: src, x: 3, m: &v10.pitch);
                    idVarArgs<6>::AddArg(this: prop, val: &v10, exType: 0);
                  }
                }
                else
                {
                  idParser::Parse1DMatrix(this: src, x: 4, m: &v12.x);
                  idVarArgs<6>::AddArg(this: prop, val: &v12, exType: 0);
                }
              }
              else
              {
                idParser::Parse1DMatrix(this: src, x: 4, m: &v13[0].x);
                idVarArgs<6>::AddArg(this: prop, val: v13, exType: 0);
              }
            }
            else
            {
              idParser::Parse1DMatrix(this: src, x: 3, m: &v11.x);
              idVarArgs<6>::AddArg(this: prop, val: &v11, exType: 0);
            }
          }
          else
          {
            v9 = (int)idParser::ParseFloat(this: src, errorFlag: nullptr);
            idVarArgs<6>::AddArg(this: prop, val: v9, exType: 0);
          }
        }
        else
        {
          v6 = idParser::ParseInt(this: src);
          idVarArgs<6>::AddArg(this: prop, val: v6, exType: 0);
        }
      }
      else
      {
        v5 = idParser::ParseBool(this: src);
        idVarArgs<6>::AddArg(this: prop, val: v5, exType: 0);
      }
      if ( !idParser::ReadToken(this: src, token: &v7) )
        break;
    }
  }
  idStr::FreeData(this: &v7);
}


// ========================================================================
// $LN91
// EA  : 0x82810628
// RVA : 0x00810628
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _LN91()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// ?PrintNode@md6AncestryNode_t@@SAXAAU1@ABVidStr@@1@Z
// EA  : 0x828106B8
// RVA : 0x008106B8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall md6AncestryNode_t::PrintNode(md6AncestryNode_t *node, const idStr *prefix, const idStr *childPrefix)
{
  md6AncestryNode_t *list; // r4
  unsigned int num; // r5
  int v7; // r11
  int v8; // r26
  int v9; // r29
  const idStr *v10; // r3
  const idStr *v11; // r23
  const idStr *v12; // r3
  const idStr *v13; // r3
  idStr *v14; // r3
  const idStr *v15; // r3
  const idStr *v16; // r23
  const idStr *v17; // r3
  const idStr *v18; // r3
  idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName> v19; // [sp+50h] [-160h] BYREF
  md6AncestryNode_t *v20; // [sp+54h] [-15Ch]
  idStr v21; // [sp+60h] [-150h] BYREF
  idStr v22; // [sp+80h] [-130h] BYREF
  idStr v23; // [sp+A0h] [-110h] BYREF
  idStr v24; // [sp+C0h] [-F0h] BYREF
  idStr v25; // [sp+E0h] [-D0h] BYREF
  idStr v26; // [sp+100h] [-B0h] BYREF
  idStr v27; // [sp+120h] [-90h] BYREF
  idStr v28[3]; // [sp+140h] [-70h] BYREF

  idLib::Printf(fmt: "%s%s\n", prefix->data, node->decl->name.str);
  v19.__vftable = (idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>_vtbl *)&md6AncestryNode_t::SortByName::`vftable';
  list = node->children.list;
  if ( list != nullptr )
  {
    num = node->children.num;
    v20 = node->children.list;
    idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>::Sort(this: &v19, base: list, num);
  }
  v8 = 0;
  v20 = (md6AncestryNode_t *)node->children.num;
  v7 = (int)v20;
  v19.__vftable = (idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>_vtbl *)&idSort<md6AncestryNode_t>::`vftable';
  if ( (int)v20 > 0 )
  {
    v9 = 0;
    do
    {
      v20 = (md6AncestryNode_t *)v7;
      if ( v8 == v7 - 1 )
      {
        v10 = idStr::idStr(this: &v25, text: "    ");
        v11 = operator+(result: &v21, a: childPrefix, b: v10);
        v12 = idStr::idStr(this: &v23, text: "+-- ");
        v13 = operator+(result: &v27, a: childPrefix, b: v12);
        md6AncestryNode_t::PrintNode(node: &node->children.list[v9], prefix: v13, childPrefix: v11);
        idStr::FreeData(this: &v27);
        idStr::FreeData(this: &v23);
        idStr::FreeData(this: &v21);
        v14 = &v25;
      }
      else
      {
        v15 = idStr::idStr(this: v28, text: "|   ");
        v16 = operator+(result: &v26, a: childPrefix, b: v15);
        v17 = idStr::idStr(this: &v24, text: "+-- ");
        v18 = operator+(result: &v22, a: childPrefix, b: v17);
        md6AncestryNode_t::PrintNode(node: &node->children.list[v9], prefix: v18, childPrefix: v16);
        idStr::FreeData(this: &v22);
        idStr::FreeData(this: &v24);
        idStr::FreeData(this: &v26);
        v14 = v28;
      }
      idStr::FreeData(this: v14);
      v7 = node->children.num;
      ++v8;
      ++v9;
    }
    while ( v8 < v7 );
  }
}


// ========================================================================
// __unwind$234712
// EA  : 0x82810860
// RVA : 0x00810860
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234712()
{
  int v0; // r12

  md6AncestryNode_t::SortByName::~SortByName(this: (md6AncestryNode_t::SortByName *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$234713
// EA  : 0x82810888
// RVA : 0x00810888
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$234714
// EA  : 0x828108B0
// RVA : 0x008108B0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$234715
// EA  : 0x828108D8
// RVA : 0x008108D8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234715()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 160));
}


// ========================================================================
// __unwind$234716
// EA  : 0x82810900
// RVA : 0x00810900
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234716()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 288));
}


// ========================================================================
// __unwind$234717
// EA  : 0x82810928
// RVA : 0x00810928
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234717()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 320));
}


// ========================================================================
// __unwind$234718
// EA  : 0x82810950
// RVA : 0x00810950
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234718()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 256));
}


// ========================================================================
// __unwind$234719
// EA  : 0x82810978
// RVA : 0x00810978
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 192));
}


// ========================================================================
// __unwind$234720
// EA  : 0x828109A0
// RVA : 0x008109A0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_234720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 128));
}


// ========================================================================
// ?InsertEventSorted@@YAXAAV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@PBVidMD6AnimEvent@@@Z
// EA  : 0x82810EA0
// RVA : 0x00810EA0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall InsertEventSorted(
        idList<idVec1,116> *events,
        const idMD6AnimEvent *event,
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
        idVec1 a14)
{
  int num; // r6
  int v15; // r5
  int v16; // r10
  int frameNum; // r8
  const idMD6AnimEvent *x_low; // r9
  int v19; // r11

  num = events->num;
  LODWORD(a14.x) = (idVec1)event;
  if ( num == 0 )
    goto LABEL_9;
  if ( num >= events->size )
    return;
  v15 = 0;
  if ( num > 0 )
  {
    v16 = 0;
    frameNum = event->frameNum;
    while ( 1 )
    {
      x_low = (const idMD6AnimEvent *)LODWORD(events->list[v16].x);
      v19 = x_low->frameNum;
      if ( frameNum < v19 || frameNum == v19 && event->row < (unsigned int)x_low->row )
        break;
      ++v15;
      ++v16;
      if ( v15 >= num )
        goto LABEL_9;
    }
    idList<idVec1,116>::Insert(this: events, obj: &a14, index: v15);
  }
  else
  {
LABEL_9:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)events,
      obj: (const encounterGroupRole_t *)&a14);
  }
}


// ========================================================================
// ?FindAnimEvents@idAnimEvents@@QBA_NABV?$idAtomicStringT@W4md6AnimAtomicString_t@@@@HHAAV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@@Z
// EA  : 0x82810F50
// RVA : 0x00810F50
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

unsigned int __fastcall idAnimEvents::FindAnimEvents(
        idAnimEvents *this,
        const idAtomicStringT<enum md6AnimAtomicString_t> *animRef,
        int startFrame,
        int endFrame,
        idList<idVehicleState *,5> *events)
{
  int v10; // r29
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int AnimEventInfoIndex; // r3
  idAnimEvents::animEventInfo_t *v18; // r31
  int num; // r11
  int v20; // r30
  int v21; // r10
  const idMD6AnimEvent *v22; // r4
  int v23; // r11
  int v24; // r30
  int size; // r10
  const idMD6AnimEvent *v26; // r4
  int frameNum; // r11
  int v28; // [sp+8h] [-88h]
  int v29; // [sp+Ch] [-84h]
  int v30; // [sp+10h] [-80h]
  int v31; // [sp+14h] [-7Ch]
  int v32; // [sp+18h] [-78h]
  idVec1 *v33; // [sp+1Ch] [-74h]

  if ( events->size < 0 )
    idList<idThread *,58>::Clear(this: events);
  v10 = 0;
  events->num = __CFADD__(-events->size, events->size ^ 0x80000000) ? 0 : events->size;
  AnimEventInfoIndex = idAnimEvents::FindAnimEventInfoIndex(this, animRef);
  if ( AnimEventInfoIndex < 0 )
    return 0;
  v18 = &this->list.list[AnimEventInfoIndex];
  num = v18->events.num;
  if ( startFrame > endFrame )
  {
    if ( num > 0 )
    {
      v24 = 0;
      do
      {
        size = events->size;
        if ( events->num >= size )
          break;
        v26 = &v18->events.list[v24];
        frameNum = v26->frameNum;
        if ( frameNum >= startFrame || frameNum <= endFrame )
          InsertEventSorted(
            (idList<idVec1,116> *)events,
            event: v26,
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v12,
            a7: v11,
            a8: size,
            a9: v28,
            a10: v29,
            a11: v30,
            a12: v31,
            a13: v32,
            a14: v33);
        ++v10;
        ++v24;
      }
      while ( v10 < v18->events.num );
    }
  }
  else if ( num > 0 )
  {
    v20 = 0;
    do
    {
      v21 = events->size;
      if ( events->num >= v21 )
        break;
      v22 = &v18->events.list[v20];
      v23 = v22->frameNum;
      if ( v23 >= startFrame && v23 <= endFrame )
        InsertEventSorted(
          (idList<idVec1,116> *)events,
          event: v22,
          a3: v15,
          a4: v14,
          a5: v13,
          a6: v12,
          a7: v11,
          a8: v21,
          a9: v28,
          a10: v29,
          a11: v30,
          a12: v31,
          a13: v32,
          a14: v33);
      ++v10;
      ++v20;
    }
    while ( v10 < v18->events.num );
  }
  return (-events->num & (unsigned int)~events->num) >> 31;
}


// ========================================================================
// ?FindAnimEvents@idAnimEvents@@QBA_NABV?$idAtomicStringT@W4md6AnimAtomicString_t@@@@HHHAAV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@@Z
// EA  : 0x828110B0
// RVA : 0x008110B0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

unsigned int __fastcall idAnimEvents::FindAnimEvents(
        idAnimEvents *this,
        const idAtomicStringT<enum md6AnimAtomicString_t> *animRef,
        int startFrame,
        int endFrame,
        const int eventNum,
        idList<idVehicleState *,5> *events)
{
  int v12; // r29
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int AnimEventInfoIndex; // r3
  idAnimEvents::animEventInfo_t *v20; // r31
  int num; // r11
  int v22; // r30
  const idMD6AnimEvent *v23; // r4
  int v24; // r10
  int v25; // r11
  int v26; // r30
  const idMD6AnimEvent *v27; // r4
  int v28; // r10
  int frameNum; // r11
  int v30; // [sp+8h] [-88h]
  int v31; // [sp+Ch] [-84h]
  int v32; // [sp+10h] [-80h]
  int v33; // [sp+14h] [-7Ch]
  int v34; // [sp+18h] [-78h]
  idVec1 *v35; // [sp+1Ch] [-74h]

  if ( events->size < 0 )
    idList<idThread *,58>::Clear(this: events);
  v12 = 0;
  events->num = __CFADD__(-events->size, events->size ^ 0x80000000) ? 0 : events->size;
  AnimEventInfoIndex = idAnimEvents::FindAnimEventInfoIndex(this, animRef);
  if ( AnimEventInfoIndex < 0 )
    return 0;
  v20 = &this->list.list[AnimEventInfoIndex];
  num = v20->events.num;
  if ( startFrame > endFrame )
  {
    if ( num > 0 )
    {
      v26 = 0;
      do
      {
        if ( events->num >= events->size )
          break;
        v27 = &v20->events.list[v26];
        v28 = v27->eventNum;
        if ( v28 == eventNum )
        {
          frameNum = v27->frameNum;
          if ( frameNum >= startFrame || frameNum <= endFrame )
            InsertEventSorted(
              (idList<idVec1,116> *)events,
              event: v27,
              a3: v17,
              a4: v16,
              a5: v15,
              a6: v14,
              a7: v13,
              a8: v28,
              a9: v30,
              a10: v31,
              a11: v32,
              a12: v33,
              a13: v34,
              a14: v35);
        }
        ++v12;
        ++v26;
      }
      while ( v12 < v20->events.num );
    }
  }
  else if ( num > 0 )
  {
    v22 = 0;
    do
    {
      if ( events->num >= events->size )
        break;
      v23 = &v20->events.list[v22];
      v24 = v23->eventNum;
      if ( v24 == eventNum )
      {
        v25 = v23->frameNum;
        if ( v25 >= startFrame && v25 <= endFrame )
          InsertEventSorted(
            (idList<idVec1,116> *)events,
            event: v23,
            a3: v17,
            a4: v16,
            a5: v15,
            a6: v14,
            a7: v13,
            a8: v24,
            a9: v30,
            a10: v31,
            a11: v32,
            a12: v33,
            a13: v34,
            a14: v35);
      }
      ++v12;
      ++v22;
    }
    while ( v12 < v20->events.num );
  }
  return (-events->num & (unsigned int)~events->num) >> 31;
}


// ========================================================================
// ??4animEventInfo_t@idAnimEvents@@QAAAAU01@ABU01@@Z
// EA  : 0x82811238
// RVA : 0x00811238
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idAnimEvents::animEventInfo_t *__fastcall idAnimEvents::animEventInfo_t::operator=(
        idAnimEvents::animEventInfo_t *this,
        const idAnimEvents::animEventInfo_t *other)
{
  this->animRef.str = other->animRef.str;
  idList<idMD6AnimEvent,28>::operator=(this: &this->events, other: &other->events);
  return this;
}


// ========================================================================
// ?GetCachedJoints@animEventInfo_t@idAnimEvents@@QBA_NHAAV?$idStaticList@PBVidCachedJoint@@$07@@@Z
// EA  : 0x82811278
// RVA : 0x00811278
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

unsigned int __fastcall idAnimEvents::animEventInfo_t::GetCachedJoints(
        idAnimEvents::animEventInfo_t *this,
        const int eventNum,
        idList<idVehicleState *,5> *list)
{
  int v6; // r31
  int v7; // r28
  idMD6AnimEvent *v8; // r3
  unsigned int NumLocalUsers; // [sp+50h] [-40h] BYREF

  if ( list->size < 0 )
    idList<idThread *,58>::Clear(this: list);
  v6 = 0;
  v7 = 0;
  for ( list->num = __CFADD__(-list->size, list->size ^ 0x80000000) ? 0 : list->size; v7 < this->events.num; ++v6 )
  {
    v8 = &this->events.list[v6];
    if ( v8->eventNum == eventNum && idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v8) != 0 )
    {
      NumLocalUsers = idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)&this->events.list[v6]);
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)list,
        obj: (const encounterGroupRole_t *)&NumLocalUsers);
    }
    ++v7;
  }
  return (-list->num & (unsigned int)~list->num) >> 31;
}


// ========================================================================
// ?Write@idDeclMD6@@UAAXAAVidFile_String@@PBD@Z
// EA  : 0x82811348
// RVA : 0x00811348
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeclMD6::Write(idDeclMD6 *this, idFile_String *out, const char *indent)
{
  idDeclMD6 *v3; // r20
  const char *v5; // r15
  idDeclMD6 *v6; // r18
  char *data; // r4
  const idDecl *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r6
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r6
  va *v17; // r3
  int v18; // r28
  int v19; // r30
  idDeclMD6::includeDecl_t *v20; // r11
  __int64 v21; // r6
  va *v22; // r3
  unsigned int i; // r5
  const idMD6Model *model; // r11
  __int64 v25; // r6
  va *v26; // r3
  unsigned int j; // r5
  float *visualOffset; // r11
  float *v29; // r10
  double v30; // fp0
  char v31; // r11
  va *v32; // r3
  unsigned int k; // r5
  __int64 v34; // r10
  BOOL calcRefBoundsFromJoints; // r11
  __int64 v36; // r10
  __int64 v37; // r6
  va *v38; // r3
  unsigned int m; // r5
  const char *v40; // r16
  va *v41; // r3
  unsigned int n; // r5
  __int64 v43; // r6
  __int64 v44; // r10
  __int64 v45; // r8
  va *v46; // r3
  __int64 v47; // r10
  __int64 v48; // r6
  __int64 v49; // r8
  va *v50; // r3
  unsigned int ii; // r5
  __int64 v52; // r6
  __int64 v53; // r10
  __int64 v54; // r8
  va *v55; // r3
  unsigned int jj; // r5
  va *v57; // r3
  unsigned int kk; // r5
  va *v59; // r3
  unsigned int mm; // r5
  va *v61; // r3
  unsigned int nn; // r5
  va *v63; // r3
  unsigned int i1; // r5
  __int64 v65; // r8
  __int64 v66; // r6
  __int64 v67; // r10
  double attachmentOverrideScale; // fp1
  va *v69; // r3
  unsigned int i2; // r5
  va *v71; // r3
  unsigned int i3; // r5
  __int64 v73; // r8
  __int64 v74; // r6
  __int64 v75; // r10
  int v76; // r28
  int v77; // r30
  idVarArgs<6> *v78; // r11
  const idVarArgs<6> *UserProp; // r4
  va *v80; // r3
  unsigned int i4; // r5
  __int64 v82; // r10
  __int64 v83; // r8
  __int64 v84; // r10
  __int64 v85; // r6
  __int64 v86; // r8
  va *v87; // r3
  unsigned int i5; // r5
  __int64 v89; // r6
  __int64 v90; // r10
  __int64 v91; // r8
  va *v92; // r3
  __int64 v93; // r8
  __int64 v94; // r6
  __int64 v95; // r10
  int v96; // r28
  int v97; // r29
  idMD6Alias *v98; // r30
  const idMD6Alias *Alias; // r4
  const char *v100; // r19
  va *v101; // r3
  unsigned int i6; // r5
  __int64 v103; // r8
  __int64 v104; // r6
  __int64 v105; // r10
  va *v106; // r3
  unsigned int i7; // r5
  __int64 v108; // r8
  __int64 v109; // r6
  __int64 v110; // r10
  int v111; // r22
  int v112; // r30
  const char *p_num; // r27
  idMorphDef *v114; // r11
  va *v115; // r3
  va *v116; // r4
  unsigned int i8; // r5
  va *v118; // r3
  unsigned int i9; // r5
  __int64 v120; // r6
  __int64 v121; // r10
  int v122; // r11
  __int64 v123; // r8
  va *v124; // r3
  va *v125; // r4
  unsigned int i10; // r5
  va *v127; // r3
  __int64 v128; // r6
  __int64 v129; // r10
  __int64 v130; // r8
  va *v131; // r3
  unsigned int i11; // r5
  __int64 v133; // r10
  va *v134; // r3
  unsigned int i12; // r5
  int v136; // r8 OVERLAPPED
  __int128 v137; // r7 OVERLAPPED
  __int64 v138; // r10
  va *v139; // r3
  unsigned int i13; // r5
  __int64 v141; // r6
  __int64 v142; // r10
  __int64 v143; // r8
  va *v144; // r3
  va *v145; // r3
  unsigned int i14; // r5
  char v147; // r25
  int v148; // r29
  int *v149; // r28
  idList<idPair<idStr,idList<int,19> >,19> *meshKitGroups; // r30
  va *v151; // r3
  unsigned int i15; // r5
  const char **v153; // r17
  __int64 v154; // r10
  __int64 v155; // r8
  const char **p_data; // r23
  __int64 v157; // r6
  __int64 v158; // r6
  va *v159; // r3
  unsigned int i16; // r5
  __int64 v161; // r8
  __int64 v162; // r6
  __int64 v163; // r10
  int v164; // r24
  int v165; // r28
  int v166; // r30
  idStr *list; // r25
  int size; // r26
  idStr *v169; // r11
  int v170; // r29
  int len; // r10
  const idMD6Model *v172; // r9
  const char *v173; // r3
  const char *v174; // r4
  unsigned int v175; // r3
  char *v176; // r29
  bool v177; // r30
  const char *v178; // r3
  __int64 v179; // r10
  __int64 v180; // r8
  va *v181; // r3
  unsigned int i17; // r5
  idStr *v183; // r3
  char *v184; // r29
  const char *v185; // r3
  __int64 v186; // r10
  __int64 v187; // r8
  va *v188; // r3
  unsigned int i18; // r5
  __int64 v190; // r8
  __int64 v191; // r6
  __int64 v192; // r10
  va *v193; // r3
  unsigned int i19; // r5
  va *v195; // r3
  unsigned int i20; // r5
  idStr *v197; // r29
  int i21; // r30
  int v199; // r11
  va *v200; // r3
  unsigned int i22; // r5
  va *v202; // r3
  unsigned int i23; // r5
  va *v204; // r3
  unsigned int i24; // r5
  __int64 v206; // r10
  __int64 v207; // r6
  __int64 v208; // r8
  va *v209; // r3
  unsigned int i25; // r5
  __int64 v211; // r8
  __int64 v212; // r6
  __int64 v213; // r10
  int v214; // r30
  int v215; // r29
  idStr *v216; // r11
  va *v217; // r3
  unsigned int i26; // r5
  va *v219; // r3
  unsigned int i27; // r5
  __int64 v221; // r6
  __int64 v222; // r10
  __int64 v223; // r8
  va *v224; // r3
  unsigned int i28; // r5
  int num; // r30
  va *v227; // r3
  unsigned int i29; // r5
  int v229; // r29
  int i30; // r27
  idMD6Model *v231; // r3
  idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> > *v232; // r11
  const idIndex<short,enum invalidUserChannelIndex_t> *value; // r4
  const char *UserChannelName; // r30
  __int64 v235; // r10
  __int64 v236; // r6
  const char *v237; // r3
  __int64 v238; // r8
  va *v239; // r3
  unsigned int i31; // r5
  va *v241; // r3
  unsigned int i32; // r5
  const char *v243; // r30
  va *v244; // r3
  unsigned int i33; // r5
  __int64 v246; // r10
  __int64 v247; // r8
  va *v248; // r3
  unsigned int i34; // r5
  __int64 v250; // r6
  __int64 v251; // r10
  __int64 v252; // r8
  va *v253; // r3
  unsigned int i35; // r5
  int userChannelWeightGroupOverride; // r11
  char v256; // r11
  bool v257; // zf
  const enumTypeInfo_t *EnumInfo; // r30
  va *v259; // r3
  unsigned int i36; // r5
  __int64 v261; // r10
  __int64 v262; // r8
  __int64 v263; // r6
  va *v264; // r3
  unsigned int i37; // r5
  __int64 v266; // r6
  __int64 v267; // r10
  __int64 v268; // r8
  va *v269; // r3
  unsigned int i38; // r5
  va *v271; // r3
  unsigned int i39; // r5
  int v273; // [sp+8h] [-31D8h]
  int v274; // [sp+8h] [-31D8h]
  int v275; // [sp+8h] [-31D8h]
  int v276; // [sp+8h] [-31D8h]
  int v277; // [sp+8h] [-31D8h]
  int v278; // [sp+8h] [-31D8h]
  int v279; // [sp+8h] [-31D8h]
  int v280; // [sp+8h] [-31D8h]
  int v281; // [sp+8h] [-31D8h]
  int v282; // [sp+8h] [-31D8h]
  int v283; // [sp+8h] [-31D8h]
  int v284; // [sp+8h] [-31D8h]
  int v285; // [sp+8h] [-31D8h]
  int v286; // [sp+8h] [-31D8h]
  int v287; // [sp+8h] [-31D8h]
  int v288; // [sp+8h] [-31D8h]
  int v289; // [sp+8h] [-31D8h]
  int v290; // [sp+8h] [-31D8h]
  int v291; // [sp+8h] [-31D8h]
  int v292; // [sp+8h] [-31D8h]
  int v293; // [sp+8h] [-31D8h]
  int v294; // [sp+8h] [-31D8h]
  int v295; // [sp+8h] [-31D8h]
  int v296; // [sp+8h] [-31D8h]
  int v297; // [sp+8h] [-31D8h]
  int v298; // [sp+8h] [-31D8h]
  int v299; // [sp+8h] [-31D8h]
  int v300; // [sp+8h] [-31D8h]
  int v301; // [sp+Ch] [-31D4h]
  int v302; // [sp+Ch] [-31D4h]
  int v303; // [sp+Ch] [-31D4h]
  int v304; // [sp+Ch] [-31D4h]
  int v305; // [sp+Ch] [-31D4h]
  int v306; // [sp+Ch] [-31D4h]
  int v307; // [sp+Ch] [-31D4h]
  int v308; // [sp+Ch] [-31D4h]
  int v309; // [sp+Ch] [-31D4h]
  int v310; // [sp+Ch] [-31D4h]
  int v311; // [sp+Ch] [-31D4h]
  int v312; // [sp+Ch] [-31D4h]
  int v313; // [sp+Ch] [-31D4h]
  int v314; // [sp+Ch] [-31D4h]
  int v315; // [sp+Ch] [-31D4h]
  int v316; // [sp+Ch] [-31D4h]
  int v317; // [sp+Ch] [-31D4h]
  int v318; // [sp+Ch] [-31D4h]
  int v319; // [sp+Ch] [-31D4h]
  int v320; // [sp+Ch] [-31D4h]
  int v321; // [sp+Ch] [-31D4h]
  int v322; // [sp+Ch] [-31D4h]
  int v323; // [sp+Ch] [-31D4h]
  int v324; // [sp+Ch] [-31D4h]
  int v325; // [sp+Ch] [-31D4h]
  int v326; // [sp+Ch] [-31D4h]
  int v327; // [sp+Ch] [-31D4h]
  int v328; // [sp+Ch] [-31D4h]
  int v329; // [sp+10h] [-31D0h]
  int v330; // [sp+10h] [-31D0h]
  int v331; // [sp+10h] [-31D0h]
  int v332; // [sp+10h] [-31D0h]
  int v333; // [sp+10h] [-31D0h]
  int v334; // [sp+10h] [-31D0h]
  int v335; // [sp+10h] [-31D0h]
  int v336; // [sp+10h] [-31D0h]
  int v337; // [sp+10h] [-31D0h]
  int v338; // [sp+10h] [-31D0h]
  int v339; // [sp+10h] [-31D0h]
  int v340; // [sp+10h] [-31D0h]
  int v341; // [sp+10h] [-31D0h]
  int v342; // [sp+10h] [-31D0h]
  int v343; // [sp+10h] [-31D0h]
  int v344; // [sp+10h] [-31D0h]
  int v345; // [sp+10h] [-31D0h]
  int v346; // [sp+10h] [-31D0h]
  int v347; // [sp+10h] [-31D0h]
  int v348; // [sp+10h] [-31D0h]
  int v349; // [sp+10h] [-31D0h]
  int v350; // [sp+10h] [-31D0h]
  int v351; // [sp+10h] [-31D0h]
  int v352; // [sp+10h] [-31D0h]
  int v353; // [sp+10h] [-31D0h]
  int v354; // [sp+10h] [-31D0h]
  int v355; // [sp+10h] [-31D0h]
  int v356; // [sp+10h] [-31D0h]
  int v357; // [sp+14h] [-31CCh]
  int v358; // [sp+14h] [-31CCh]
  int v359; // [sp+14h] [-31CCh]
  int v360; // [sp+14h] [-31CCh]
  int v361; // [sp+14h] [-31CCh]
  int v362; // [sp+14h] [-31CCh]
  int v363; // [sp+14h] [-31CCh]
  int v364; // [sp+14h] [-31CCh]
  int v365; // [sp+14h] [-31CCh]
  int v366; // [sp+14h] [-31CCh]
  int v367; // [sp+14h] [-31CCh]
  int v368; // [sp+14h] [-31CCh]
  int v369; // [sp+14h] [-31CCh]
  int v370; // [sp+14h] [-31CCh]
  int v371; // [sp+14h] [-31CCh]
  int v372; // [sp+14h] [-31CCh]
  int v373; // [sp+14h] [-31CCh]
  int v374; // [sp+14h] [-31CCh]
  int v375; // [sp+14h] [-31CCh]
  int v376; // [sp+14h] [-31CCh]
  int v377; // [sp+14h] [-31CCh]
  int v378; // [sp+14h] [-31CCh]
  int v379; // [sp+14h] [-31CCh]
  int v380; // [sp+14h] [-31CCh]
  int v381; // [sp+14h] [-31CCh]
  int v382; // [sp+14h] [-31CCh]
  int v383; // [sp+14h] [-31CCh]
  int v384; // [sp+14h] [-31CCh]
  int v385; // [sp+18h] [-31C8h]
  int v386; // [sp+18h] [-31C8h]
  int v387; // [sp+18h] [-31C8h]
  int v388; // [sp+18h] [-31C8h]
  int v389; // [sp+18h] [-31C8h]
  int v390; // [sp+18h] [-31C8h]
  int v391; // [sp+18h] [-31C8h]
  int v392; // [sp+18h] [-31C8h]
  int v393; // [sp+18h] [-31C8h]
  int v394; // [sp+18h] [-31C8h]
  int v395; // [sp+18h] [-31C8h]
  int v396; // [sp+18h] [-31C8h]
  int v397; // [sp+18h] [-31C8h]
  int v398; // [sp+18h] [-31C8h]
  int v399; // [sp+18h] [-31C8h]
  int v400; // [sp+18h] [-31C8h]
  int v401; // [sp+18h] [-31C8h]
  int v402; // [sp+18h] [-31C8h]
  int v403; // [sp+18h] [-31C8h]
  int v404; // [sp+18h] [-31C8h]
  int v405; // [sp+18h] [-31C8h]
  int v406; // [sp+18h] [-31C8h]
  int v407; // [sp+18h] [-31C8h]
  int v408; // [sp+18h] [-31C8h]
  int v409; // [sp+18h] [-31C8h]
  int v410; // [sp+18h] [-31C8h]
  int v411; // [sp+18h] [-31C8h]
  int v412; // [sp+18h] [-31C8h]
  int v413; // [sp+1Ch] [-31C4h]
  int v414; // [sp+1Ch] [-31C4h]
  int v415; // [sp+1Ch] [-31C4h]
  int v416; // [sp+1Ch] [-31C4h]
  int v417; // [sp+1Ch] [-31C4h]
  int v418; // [sp+1Ch] [-31C4h]
  int v419; // [sp+1Ch] [-31C4h]
  int v420; // [sp+1Ch] [-31C4h]
  int v421; // [sp+1Ch] [-31C4h]
  int v422; // [sp+1Ch] [-31C4h]
  int v423; // [sp+1Ch] [-31C4h]
  int v424; // [sp+1Ch] [-31C4h]
  int v425; // [sp+1Ch] [-31C4h]
  int v426; // [sp+1Ch] [-31C4h]
  int v427; // [sp+1Ch] [-31C4h]
  int v428; // [sp+1Ch] [-31C4h]
  int v429; // [sp+1Ch] [-31C4h]
  int v430; // [sp+1Ch] [-31C4h]
  int v431; // [sp+1Ch] [-31C4h]
  int v432; // [sp+1Ch] [-31C4h]
  int v433; // [sp+1Ch] [-31C4h]
  int v434; // [sp+1Ch] [-31C4h]
  int v435; // [sp+1Ch] [-31C4h]
  int v436; // [sp+1Ch] [-31C4h]
  int v437; // [sp+1Ch] [-31C4h]
  int v438; // [sp+1Ch] [-31C4h]
  int v439; // [sp+1Ch] [-31C4h]
  int v440; // [sp+1Ch] [-31C4h]
  double v441; // [sp+28h] [-31B8h]
  double v442; // [sp+38h] [-31A8h]
  float *p_len; // [sp+50h] [-3190h]
  idStr v444; // [sp+60h] [-3180h] BYREF
  idDeclMD6 *v445; // [sp+80h] [-3160h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v446[6]; // [sp+84h] [-315Ch] BYREF
  idList<idStr,5> v447; // [sp+90h] [-3150h] BYREF
  idStr *v448; // [sp+A0h] [-3140h]
  const char *v449; // [sp+A4h] [-313Ch]
  const char *v450; // [sp+A8h] [-3138h]
  idMem *v451; // [sp+ACh] [-3134h]
  int v452; // [sp+B0h] [-3130h]
  idStr v453; // [sp+C0h] [-3120h] BYREF
  idStr v454; // [sp+E0h] [-3100h] BYREF
  idStr v455; // [sp+100h] [-30E0h] BYREF
  idStr v456; // [sp+120h] [-30C0h] BYREF
  va v457; // [sp+140h] [-30A0h] BYREF
  va v458; // [sp+1140h] [-20A0h] BYREF
  va v459; // [sp+2140h] [-10A0h] BYREF

  v3 = this;
  v5 = indent;
  if ( this->parent.len != 0 )
  {
    data = this->parent.data;
    if ( data != nullptr )
      v8 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: data, makeDefault: false);
    else
      v8 = nullptr;
    v6 = (idDeclMD6 *)v8;
  }
  else
  {
    v6 = nullptr;
  }
  v445 = v6;
  idFile_String::operator+=(this: out, str: "{\n");
  LODWORD(v9) = &unk_82210000;
  HIDWORD(v10) = v5;
  v12 = va::va(
          this: &v459,
          fmt: "%s\tinit {\n",
          a3: v10,
          a4: v11,
          a5: v9,
          a6: v273,
          a7: v301,
          a8: v329,
          a9: v357,
          a10: v385,
          a11: v413);
  idFile_String::operator+=(this: out, str: v12->buffer);
  if ( v6 != nullptr )
  {
    LODWORD(v16) = v6->name.str;
    HIDWORD(v16) = v5;
    v17 = va::va(
            this: &v459,
            fmt: "%s\t\tinherit \"%s\"\n",
            a3: v16,
            a4: v14,
            a5: v13,
            a6: v274,
            a7: v302,
            a8: v330,
            a9: v358,
            a10: v386,
            a11: v414);
    idFile_String::operator+=(this: out, str: v17->buffer);
  }
  v18 = 0;
  if ( v3->declsToIncludeAnimDataFrom.num > 0 )
  {
    v19 = 0;
    do
    {
      v20 = &v3->declsToIncludeAnimDataFrom.list[v19];
      if ( v20->isOriginalInclude )
      {
        LODWORD(v13) = v20->includeDecl;
        HIDWORD(v21) = v5;
        LODWORD(v21) = v20->includeDecl->name.str;
        v22 = va::va(
                this: &v459,
                fmt: "%s\t\tincludeAnimDataFrom \"%s\"\n",
                a3: v21,
                a4: v14,
                a5: v13,
                a6: v274,
                a7: v302,
                a8: v330,
                a9: v358,
                a10: v386,
                a11: v414);
        for ( i = 0; v22->buffer[i] != 0; ++i )
          ;
        out->Write(this: out, a2: v22, a3: i);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v3->declsToIncludeAnimDataFrom.num );
  }
  model = v3->model;
  if ( model != nullptr && (v6 == nullptr || model != v6->model) )
  {
    LODWORD(v13) = &unk_82210000;
    LODWORD(v25) = model->name.str;
    HIDWORD(v25) = v5;
    v26 = va::va(
            this: &v459,
            fmt: "%s\t\tmesh \"%s\"\n",
            a3: v25,
            a4: v14,
            a5: v13,
            a6: v274,
            a7: v302,
            a8: v330,
            a9: v358,
            a10: v386,
            a11: v414);
    for ( j = 0; v26->buffer[j] != 0; ++j )
      ;
    out->Write(this: out, a2: v26, a3: j);
  }
  if ( v6 == nullptr )
    goto LABEL_28;
  visualOffset = v6->config->visualOffset;
  v29 = v3->config->visualOffset;
  if ( *visualOffset != *v29 || visualOffset[1] != v29[1] || (v30 = visualOffset[2], v31 = 1, v30 != v29[2]) )
    v31 = 0;
  if ( v31 == 0 )
  {
LABEL_28:
    LODWORD(v13) = &unk_82210000;
    v32 = va::va(
            this: &v459,
            fmt: "%s\t\toffset ( %g %g %g )\n",
            a3: COERCE__INT64(v3->config->visualOffset[0]),
            a4: __SPAIR64__(
              COERCE_UNSIGNED_INT64(v3->config->visualOffset[1]),
              COERCE_UNSIGNED_INT64(v3->config->visualOffset[2])),
            a5: v13,
            a6: v274,
            a7: v302,
            a8: v330,
            a9: v358,
            a10: v386,
            a11: v414);
    for ( k = 0; v32->buffer[k] != 0; ++k )
      ;
    out->Write(this: out, a2: v32, a3: k);
  }
  if ( v6 == nullptr
    || (HIDWORD(v34) = v6->calcRefBoundsFromJoints,
        LODWORD(v34) = v3->calcRefBoundsFromJoints,
        HIDWORD(v34) != (_DWORD)v34) )
  {
    calcRefBoundsFromJoints = v3->calcRefBoundsFromJoints;
    LODWORD(v36) = &unk_82210000;
    HIDWORD(v37) = v5;
    HIDWORD(v36) = calcRefBoundsFromJoints - 1;
    LODWORD(v37) = calcRefBoundsFromJoints;
    v38 = va::va(
            this: &v459,
            fmt: "%s\t\tcalcRefBoundsFromJoints %d\n",
            a3: v37,
            a4: v14,
            a5: v36,
            a6: v274,
            a7: v302,
            a8: v330,
            a9: v358,
            a10: v386,
            a11: v414);
    for ( m = 0; v38->buffer[m] != 0; ++m )
      ;
    out->Write(this: out, a2: v38, a3: m);
  }
  HIDWORD(v15) = v5;
  v40 = "%s\t}\n";
  v450 = "%s\t}\n";
  v41 = va::va(
          this: &v459,
          fmt: "%s\t}\n",
          a3: v15,
          a4: v14,
          a5: v34,
          a6: v274,
          a7: v302,
          a8: v330,
          a9: v358,
          a10: v386,
          a11: v414);
  for ( n = 0; v41->buffer[n] != 0; ++n )
    ;
  out->Write(this: out, a2: v41, a3: n);
  HIDWORD(v43) = v5;
  v46 = va::va(
          this: &v459,
          fmt: "%s\t",
          a3: v43,
          a4: v45,
          a5: v44,
          a6: v275,
          a7: v303,
          a8: v331,
          a9: v359,
          a10: v387,
          a11: v415);
  idStr::idStr(this: &v444, text: v46);
  HIDWORD(v47) = &unk_82210000;
  HIDWORD(v48) = v5;
  v50 = va::va(
          this: &v458,
          fmt: "%s\tmodelCaps {\n",
          a3: v48,
          a4: v49,
          a5: v47,
          a6: v276,
          a7: v304,
          a8: v332,
          a9: v360,
          a10: v388,
          a11: v416);
  for ( ii = 0; v50->buffer[ii] != 0; ++ii )
    ;
  out->Write(this: out, a2: v50, a3: ii);
  HIDWORD(v53) = v3->modelCaps;
  LODWORD(v54) = BYTE3(v53) & 1;
  if ( (v53 & 0x100000000LL) != 0 )
  {
    HIDWORD(v52) = v444.data;
    v55 = va::va(
            this: &v458,
            fmt: "%s\tlipsync\n",
            a3: v52,
            a4: v54,
            a5: v53,
            a6: v277,
            a7: v305,
            a8: v333,
            a9: v361,
            a10: v389,
            a11: v417);
    for ( jj = 0; v55->buffer[jj] != 0; ++jj )
      ;
    out->Write(this: out, a2: v55, a3: jj);
  }
  LODWORD(v53) = v3->modelCaps & 2;
  if ( (_DWORD)v53 != 0 )
  {
    HIDWORD(v52) = v444.data;
    v57 = va::va(
            this: &v458,
            fmt: "%s\tfaceSetup\n",
            a3: v52,
            a4: v54,
            a5: v53,
            a6: v277,
            a7: v305,
            a8: v333,
            a9: v361,
            a10: v389,
            a11: v417);
    for ( kk = 0; v57->buffer[kk] != 0; ++kk )
      ;
    out->Write(this: out, a2: v57, a3: kk);
  }
  LODWORD(v53) = v3->modelCaps & 4;
  if ( (_DWORD)v53 != 0 )
  {
    HIDWORD(v52) = v444.data;
    v59 = va::va(
            this: &v458,
            fmt: "%s\tmoods\n",
            a3: v52,
            a4: v54,
            a5: v53,
            a6: v277,
            a7: v305,
            a8: v333,
            a9: v361,
            a10: v389,
            a11: v417);
    for ( mm = 0; v59->buffer[mm] != 0; ++mm )
      ;
    out->Write(this: out, a2: v59, a3: mm);
  }
  LODWORD(v53) = v3->modelCaps & 8;
  if ( (_DWORD)v53 != 0 )
  {
    HIDWORD(v52) = v444.data;
    v61 = va::va(
            this: &v458,
            fmt: "%s\tgestures\n",
            a3: v52,
            a4: v54,
            a5: v53,
            a6: v277,
            a7: v305,
            a8: v333,
            a9: v361,
            a10: v389,
            a11: v417);
    for ( nn = 0; v61->buffer[nn] != 0; ++nn )
      ;
    out->Write(this: out, a2: v61, a3: nn);
  }
  HIDWORD(v52) = v5;
  v63 = va::va(
          this: &v458,
          fmt: "%s\t}\n",
          a3: v52,
          a4: v54,
          a5: v53,
          a6: v277,
          a7: v305,
          a8: v333,
          a9: v361,
          a10: v389,
          a11: v417);
  for ( i1 = 0; v63->buffer[i1] != 0; ++i1 )
    ;
  out->Write(this: out, a2: v63, a3: i1);
  HIDWORD(v67) = 0x82000000;
  attachmentOverrideScale = v3->attachmentOverrideScale;
  if ( attachmentOverrideScale != -1.0 )
  {
    v69 = va::va(
            this: &v458,
            fmt: "%s\tattachmentOverrideScale %.6f\n",
            a3: __SPAIR64__((unsigned int)v5, LODWORD(attachmentOverrideScale)),
            a4: v65,
            a5: v67,
            a6: v278,
            a7: v306,
            a8: v334,
            a9: v362,
            a10: v390,
            a11: v418);
    for ( i2 = 0; v69->buffer[i2] != 0; ++i2 )
      ;
    out->Write(this: out, a2: v69, a3: i2);
  }
  HIDWORD(v66) = v5;
  v71 = va::va(
          this: &v458,
          fmt: "%s\tuserProps {\n",
          a3: v66,
          a4: v65,
          a5: v67,
          a6: v278,
          a7: v306,
          a8: v334,
          a9: v362,
          a10: v390,
          a11: v418);
  for ( i3 = 0; v71->buffer[i3] != 0; ++i3 )
    ;
  out->Write(this: out, a2: v71, a3: i3);
  HIDWORD(v75) = v3->userProps.num;
  v76 = 0;
  if ( SHIDWORD(v75) > 0 )
  {
    v77 = 0;
    do
    {
      v453.allocedAndFlag = 20;
      v453.len = 0;
      v453.data = v453.baseBuffer;
      v453.baseBuffer[0] = 0;
      v78 = &v3->userProps.list[v77];
      if ( v78->numArgs != 0 && v78->argTypes[0] == 8 )
        idStr::operator=(this: &v453, text: (const char *)&v78->args[v78->argOffsets[0]]);
      if ( v6 == nullptr
        || (UserProp = idDeclMD6::FindUserProp(this: v6, name: v453.data)) == nullptr
        || (unsigned __int8)idVarArgs<6>::Equal(this: &v3->userProps.list[v77], other: UserProp) == 0 )
      {
        idDeclMD6::WriteUserProp(this: v3, prop: &v3->userProps.list[v77], out, indent: v444.data);
      }
      idStr::FreeData(this: &v453);
      ++v76;
      ++v77;
    }
    while ( v76 < v3->userProps.num );
  }
  HIDWORD(v74) = v5;
  v80 = va::va(
          this: &v458,
          fmt: "%s\t}\n",
          a3: v74,
          a4: v73,
          a5: v75,
          a6: v279,
          a7: v307,
          a8: v335,
          a9: v363,
          a10: v391,
          a11: v419);
  for ( i4 = 0; v80->buffer[i4] != 0; ++i4 )
    ;
  out->Write(this: out, a2: v80, a3: i4);
  idJointGroupCollection::Write(this: &v3->jointGroupCollection, file: out, decl: v3, indent: v444.data);
  idAnimEvents::Write(
    this: &v3->animEvents,
    decl: v3,
    indent: __SPAIR64__((unsigned int)out, (unsigned int)v444.data),
    a4: v83,
    a5: v82);
  HIDWORD(v84) = &unk_82210000;
  HIDWORD(v85) = v444.data;
  v87 = va::va(
          this: &v458,
          fmt: "%saliases {\n",
          a3: v85,
          a4: v86,
          a5: v84,
          a6: v280,
          a7: v308,
          a8: v336,
          a9: v364,
          a10: v392,
          a11: v420);
  for ( i5 = 0; v87->buffer[i5] != 0; ++i5 )
    ;
  out->Write(this: out, a2: v87, a3: i5);
  HIDWORD(v89) = v444.data;
  v92 = va::va(
          this: &v458,
          fmt: "%s\t",
          a3: v89,
          a4: v91,
          a5: v90,
          a6: v281,
          a7: v309,
          a8: v337,
          a9: v365,
          a10: v393,
          a11: v421);
  idStr::idStr(this: &v455, text: v92);
  HIDWORD(v95) = v3->aliases.num;
  v96 = 0;
  if ( SHIDWORD(v95) > 0 )
  {
    v97 = 0;
    do
    {
      v98 = &v3->aliases.list[v97];
      if ( v6 == nullptr
        || (animation->FindAliasHandle(
              this: (idAnimation *)v446,
              result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
              a3: v6,
              a4: v98->name.str),
            (Alias = idDeclMD6::FindAlias(this: v6, aliasHandle: v446, includeInherited: true)) == nullptr)
        || !idMD6Alias::IsInherited(this: v98, other: Alias) )
      {
        idMD6Alias::Write(this: v98, decl: v3, out, indent: v455.data);
      }
      ++v96;
      ++v97;
    }
    while ( v96 < v3->aliases.num );
  }
  HIDWORD(v94) = v444.data;
  v100 = "%s}\n";
  v449 = "%s}\n";
  v101 = va::va(
           this: &v457,
           fmt: "%s}\n",
           a3: v94,
           a4: v93,
           a5: v95,
           a6: v282,
           a7: v310,
           a8: v338,
           a9: v366,
           a10: v394,
           a11: v422);
  for ( i6 = 0; v101->buffer[i6] != 0; ++i6 )
    ;
  out->Write(this: out, a2: v101, a3: i6);
  idPropsCollection::Write(this: &v3->props, file: out, decl: v3, indent: v444.data);
  idEyeInfoCollection::Write(this: &v3->eyeInfoCollection, declmd6: v3, out, indent: v444.data);
  HIDWORD(v105) = v3->morphVertices;
  if ( HIDWORD(v105) != 0 )
  {
    HIDWORD(v104) = v444.data;
    v106 = va::va(
             this: &v457,
             fmt: "%smorphVerts {\n",
             a3: v104,
             a4: v103,
             a5: v105,
             a6: v283,
             a7: v311,
             a8: v339,
             a9: v367,
             a10: v395,
             a11: v423);
    for ( i7 = 0; v106->buffer[i7] != 0; ++i7 )
      ;
    out->Write(this: out, a2: v106, a3: i7);
    HIDWORD(v110) = v3->morphDefList.num;
    v111 = 0;
    if ( SHIDWORD(v110) > 0 )
    {
      HIDWORD(v110) = &unk_82210000;
      LODWORD(v108) = &unk_82210000;
      HIDWORD(v108) = &unk_82210000;
      LODWORD(v109) = &unk_82210000;
      v112 = 0;
      p_num = "%s\t\tjointname \"%s\"\n";
      do
      {
        HIDWORD(v109) = v444.data;
        v114 = &v3->morphDefList.list[v112];
        LODWORD(v110) = v114->fileName.len;
        if ( (_DWORD)v110 != 0 )
        {
          LODWORD(v109) = v114->fileName.data;
          v115 = va::va(
                   this: &v457,
                   fmt: "%s\tmorphFile \"%s\"\n",
                   a3: v109,
                   a4: v108,
                   a5: v110,
                   a6: v284,
                   a7: v312,
                   a8: v340,
                   a9: v368,
                   a10: v396,
                   a11: v424);
          v116 = v115;
          for ( i8 = 0; v115->buffer[i8] != 0; ++i8 )
            ;
        }
        else
        {
          v118 = va::va(
                   this: &v457,
                   fmt: "%s\tmorphVert {\n",
                   a3: v109,
                   a4: v108,
                   a5: v110,
                   a6: v284,
                   a7: v312,
                   a8: v340,
                   a9: v368,
                   a10: v396,
                   a11: v424);
          for ( i9 = 0; v118->buffer[i9] != 0; ++i9 )
            ;
          out->Write(this: out, a2: v118, a3: i9);
          HIDWORD(v121) = &v3->morphDefList.list[v112];
          v122 = *(_DWORD *)(HIDWORD(v121) + 56);
          LODWORD(v123) = v122 & 1;
          if ( (v122 & 1) != 0 )
          {
            HIDWORD(v120) = v444.data;
            v124 = va::va(
                     this: &v457,
                     fmt: "%s\t\tsphere\n",
                     a3: v120,
                     a4: v123,
                     a5: v121,
                     a6: v283,
                     a7: v311,
                     a8: v339,
                     a9: v367,
                     a10: v395,
                     a11: v423);
            v125 = v124;
            for ( i10 = 0; v124->buffer[i10] != 0; ++i10 )
              ;
          }
          else
          {
            if ( (v122 & 2) == 0 )
            {
              idLib::Error(fmt: "%s has bad info in it's morphVert definition", v3->name.str);
              goto _LN1111;
            }
            HIDWORD(v120) = v444.data;
            v127 = va::va(
                     this: &v457,
                     fmt: "%s\t\tbox\n",
                     a3: v120,
                     a4: v123,
                     a5: v121,
                     a6: v283,
                     a7: v311,
                     a8: v339,
                     a9: v367,
                     a10: v395,
                     a11: v423);
            v125 = v127;
            for ( i10 = 0; v127->buffer[i10] != 0; ++i10 )
              ;
          }
          out->Write(this: out, a2: v125, a3: i10);
          HIDWORD(v128) = v444.data;
          LODWORD(v128) = v3->morphDefList.list[v112].jointName.data;
          v131 = va::va(
                   this: &v457,
                   fmt: "%s\t\tjointname \"%s\"\n",
                   a3: v128,
                   a4: v130,
                   a5: v129,
                   a6: v285,
                   a7: v313,
                   a8: v341,
                   a9: v369,
                   a10: v397,
                   a11: v425);
          for ( i11 = 0; v131->buffer[i11] != 0; ++i11 )
            ;
          out->Write(this: out, a2: v131, a3: i11);
          v134 = va::va(
                   this: &v457,
                   fmt: "%s\t\tpos ( %.3f %.3f %.3f )\n",
                   a3: COERCE__INT64(v3->morphDefList.list[v112].pos.x),
                   a4: __SPAIR64__(
                     COERCE_UNSIGNED_INT64(v3->morphDefList.list[v112].pos.y),
                     COERCE_UNSIGNED_INT64(v3->morphDefList.list[v112].pos.z)),
                   a5: v133,
                   a6: v286,
                   a7: v314,
                   a8: v342,
                   a9: v370,
                   a10: v398,
                   a11: v426);
          for ( i12 = 0; v134->buffer[i12] != 0; ++i12 )
            ;
          out->Write(this: out, a2: v134, a3: i12);
          p_len = (float *)&v3->morphDefList.list[v112].jointName.len;
          v442 = p_len[13];
          v136 = LODWORD(v442);
          v441 = p_len[11];
          DWORD1(v137) = HIDWORD(v441);
          *((double *)&v137 + 1) = p_len[12];
          v139 = va::va(
                   this: &v457,
                   fmt: "%s\t\tsize ( %.3f %.3f %.3f )\n",
                   a3: *(__int64 *)((char *)&v137 + 4),
                   a4: *(__int64 *)&v136,
                   a5: v138,
                   a6: v287,
                   a7: v315,
                   a8: v343,
                   a9: v371,
                   a10: v399,
                   a11: v427);
          for ( i13 = 0; v139->buffer[i13] != 0; ++i13 )
            ;
          out->Write(this: out, a2: v139, a3: i13);
          HIDWORD(v141) = v444.data;
          v144 = va::va(
                   this: &v457,
                   fmt: "%s\t}\n",
                   a3: v141,
                   a4: v143,
                   a5: v142,
                   a6: v288,
                   a7: v316,
                   a8: v344,
                   a9: v372,
                   a10: v400,
                   a11: v428);
          v116 = v144;
          for ( i8 = 0; v144->buffer[i8] != 0; ++i8 )
            ;
        }
        out->Write(this: out, a2: v116, a3: i8);
        ++v111;
        ++v112;
      }
      while ( v111 < v3->morphDefList.num );
    }
    HIDWORD(v109) = v444.data;
    v145 = va::va(
             this: &v457,
             fmt: "%s}\n",
             a3: v109,
             a4: v108,
             a5: v110,
             a6: v284,
             a7: v312,
             a8: v340,
             a9: v368,
             a10: v396,
             a11: v424);
    for ( i14 = 0; v145->buffer[i14] != 0; ++i14 )
      ;
    out->Write(this: out, a2: v145, a3: i14);
  }
  p_num = (const char *)&v3->meshKitGroups[0].num;
  v147 = 0;
  v148 = 0;
  v149 = &v3->meshKitGroups[0].num;
  meshKitGroups = v6->meshKitGroups;
  while ( v6 != nullptr
       && (unsigned __int8)idList<idPair<idStr,idList<int,19>>,19>::operator==(
                             this: meshKitGroups,
                             other: (idList<idPair<idStr,idList<int,19> >,19> *)((char *)meshKitGroups + (char *)v3
                                                                                                - (char *)v6)) != 0
       || *v149 <= 0 )
  {
    ++v148;
    ++meshKitGroups;
    v149 += 4;
    if ( v148 >= 3 )
      goto LABEL_125;
  }
_LN1111:
  v147 = 1;
LABEL_125:
  if ( v147 != 0 && v3->model != nullptr )
  {
    HIDWORD(v104) = v444.data;
    v151 = va::va(
             this: &v457,
             fmt: "%smeshKits {\n",
             a3: v104,
             a4: v103,
             a5: v105,
             a6: v283,
             a7: v311,
             a8: v339,
             a9: v367,
             a10: v395,
             a11: v423);
    for ( i15 = 0; v151->buffer[i15] != 0; ++i15 )
      ;
    out->Write(this: out, a2: v151, a3: i15);
    v153 = idDeclMD6::meshKitGroupNames;
    v452 = (char *)v6 - (char *)v3;
    LODWORD(v154) = byte_821B0000;
    HIDWORD(v154) = &unk_82210000;
    LODWORD(v155) = &unk_82210000;
    p_data = (const char **)&v3->meshKitDefault[0].data;
    v451 = &mem;
    do
    {
      if ( v445 == nullptr
        || (LODWORD(v154) = (unsigned __int8)idList<idPair<idStr,idList<int,19>>,19>::operator==(
                                               this: (idList<idPair<idStr,idList<int,19> >,19> *)&p_num[v452 - 4],
                                               other: (const idList<idPair<idStr,idList<int,19> >,19> *)(p_num - 4)),
            (_DWORD)v154 == 0) )
      {
        HIDWORD(v155) = *(_DWORD *)p_num;
        LODWORD(v158) = *v153;
        HIDWORD(v158) = v444.data;
        v159 = va::va(
                 this: &v457,
                 fmt: "%s\t%s %d {\n",
                 a3: v158,
                 a4: v155,
                 a5: v154,
                 a6: v289,
                 a7: v317,
                 a8: v345,
                 a9: v373,
                 a10: v401,
                 a11: v429);
        for ( i16 = 0; v159->buffer[i16] != 0; ++i16 )
          ;
        out->Write(this: out, a2: v159, a3: i16);
        HIDWORD(v163) = *(_DWORD *)p_num;
        v164 = 0;
        if ( *(int *)p_num > 0 )
        {
          v165 = 0;
          do
          {
            v166 = 0;
            list = nullptr;
            *(_WORD *)&v447.memTag = 1280;
            size = 0;
            memset(&v447, 0, 14);
            v169 = (idStr *)(v165 + *((_DWORD *)p_num - 1));
            if ( (int)v169[1].data > 0 )
            {
              v170 = 0;
              do
              {
                len = v169[1].len;
                v172 = this->model;
                v448 = v169;
                idStr::idStr(this: &v454, text: v172->meshes.list[*(_DWORD *)(len + v170)]->name.data);
                if ( idList<idStr,5>::FindIndex(this: &v447, obj: &v454, startIndex: 0) < 0 )
                  idList<idStr,5>::Append(this: &v447, obj: &v454);
                idStr::FreeData(this: &v454);
                ++v166;
                v169 = (idStr *)(v165 + *((_DWORD *)p_num - 1));
                v170 += 4;
              }
              while ( v166 < (int)v169[1].data );
              size = v447.size;
              list = v447.list;
            }
            v173 = *p_data;
            v174 = v169->data;
            v448 = v169;
            v175 = idStr::Cmp(s1: v173, s2: v174);
            v176 = v444.data;
            v177 = (_cntlzw(v175) & 0x20) != 0;
            v178 = idStr::CStyleQuote(str: *(const char **)(v165 + *((_DWORD *)p_num - 1) + 4));
            v181 = va::va(
                     this: &v457,
                     fmt: "%s\t\tmeshKit %s {\n",
                     a3: __SPAIR64__((unsigned int)v176, (unsigned int)v178),
                     a4: v180,
                     a5: v179,
                     a6: v290,
                     a7: v318,
                     a8: v346,
                     a9: v374,
                     a10: v402,
                     a11: v430);
            for ( i17 = 0; v181->buffer[i17] != 0; ++i17 )
              ;
            out->Write(this: out, a2: v181, a3: i17);
            v183 = idStrListCombineString(result: &v456, list: &v447, separator: " ");
            v184 = v444.data;
            v185 = idStr::CStyleQuote(str: v183->data);
            v188 = va::va(
                     this: &v457,
                     fmt: "%s\t\t\tmeshes %s\n",
                     a3: __SPAIR64__((unsigned int)v184, (unsigned int)v185),
                     a4: v187,
                     a5: v186,
                     a6: v291,
                     a7: v319,
                     a8: v347,
                     a9: v375,
                     a10: v403,
                     a11: v431);
            for ( i18 = 0; v188->buffer[i18] != 0; ++i18 )
              ;
            out->Write(this: out, a2: v188, a3: i18);
            idStr::FreeData(this: &v456);
            HIDWORD(v192) = v177;
            if ( v177 )
            {
              HIDWORD(v191) = v444.data;
              v193 = va::va(
                       this: &v457,
                       fmt: "%s\t\t\tisDefault true\n",
                       a3: v191,
                       a4: v190,
                       a5: v192,
                       a6: v292,
                       a7: v320,
                       a8: v348,
                       a9: v376,
                       a10: v404,
                       a11: v432);
              for ( i19 = 0; v193->buffer[i19] != 0; ++i19 )
                ;
              out->Write(this: out, a2: v193, a3: i19);
            }
            HIDWORD(v191) = v444.data;
            v195 = va::va(
                     this: &v457,
                     fmt: "%s\t\t}\n",
                     a3: v191,
                     a4: v190,
                     a5: v192,
                     a6: v292,
                     a7: v320,
                     a8: v348,
                     a9: v376,
                     a10: v404,
                     a11: v432);
            for ( i20 = 0; v195->buffer[i20] != 0; ++i20 )
              ;
            out->Write(this: out, a2: v195, a3: i20);
            if ( v447.listStatic == 0 || v447.listStatic == 2 )
            {
              if ( list != nullptr )
              {
                if ( size > 0 )
                {
                  v197 = list;
                  for ( i21 = size; i21 != 0; --i21 )
                    idStr::FreeData(this: v197++);
                }
                idMem::Free(this: v451, ptr: list, align: ALIGN_16);
              }
              v447.list = nullptr;
              v447.size = 0;
            }
            v199 = *(_DWORD *)p_num;
            ++v164;
            v165 += 48;
            v447.num = 0;
          }
          while ( v164 < v199 );
        }
        HIDWORD(v162) = v444.data;
        v200 = va::va(
                 this: &v457,
                 fmt: v450,
                 a3: v162,
                 a4: v161,
                 a5: v163,
                 a6: v290,
                 a7: v318,
                 a8: v346,
                 a9: v374,
                 a10: v402,
                 a11: v430);
        for ( i22 = 0; v200->buffer[i22] != 0; ++i22 )
          ;
        out->Write(this: out, a2: v200, a3: i22);
      }
      ++v153;
      p_data += 8;
      LODWORD(v154) = &idSort<md6AncestryNode_t> `RTTI Type Descriptor';
      p_num += 16;
    }
    while ( (int)v153 < (int)&idSort<md6AncestryNode_t> `RTTI Type Descriptor' );
    HIDWORD(v157) = v444.data;
    v202 = va::va(
             this: &v457,
             fmt: v449,
             a3: v157,
             a4: v155,
             a5: v154,
             a6: v289,
             a7: v317,
             a8: v345,
             a9: v373,
             a10: v401,
             a11: v429);
    for ( i23 = 0; v202->buffer[i23] != 0; ++i23 )
      ;
    out->Write(this: out, a2: v202, a3: i23);
    v40 = v450;
    v100 = v449;
    v5 = indent;
    v3 = this;
  }
  if ( v3->wrinkleMapRegionExpressions.num != 0 )
  {
    HIDWORD(v104) = v444.data;
    v204 = va::va(
             this: &v457,
             fmt: "%swrinkleExpressions {\n",
             a3: v104,
             a4: v103,
             a5: v105,
             a6: v283,
             a7: v311,
             a8: v339,
             a9: v367,
             a10: v395,
             a11: v423);
    for ( i24 = 0; v204->buffer[i24] != 0; ++i24 )
      ;
    out->Write(this: out, a2: v204, a3: i24);
    HIDWORD(v206) = &unk_82210000;
    HIDWORD(v207) = v444.data;
    LODWORD(v207) = v3->wrinkleMapRegionExpressions.num;
    v209 = va::va(
             this: &v457,
             fmt: "%s\tregions %d {\n",
             a3: v207,
             a4: v208,
             a5: v206,
             a6: v293,
             a7: v321,
             a8: v349,
             a9: v377,
             a10: v405,
             a11: v433);
    for ( i25 = 0; v209->buffer[i25] != 0; ++i25 )
      ;
    out->Write(this: out, a2: v209, a3: i25);
    HIDWORD(v213) = v3->wrinkleMapRegionExpressions.num;
    v214 = 0;
    if ( SHIDWORD(v213) > 0 )
    {
      v215 = 0;
      do
      {
        v216 = &v3->wrinkleMapRegionExpressions.list[v215];
        LODWORD(v213) = v216->len;
        if ( v216->len > 0 )
        {
          HIDWORD(v211) = v216->data;
          v448 = &v3->wrinkleMapRegionExpressions.list[v215];
          v217 = va::va(
                   this: &v457,
                   fmt: "%s\t\t%d \"%s\"\n",
                   a3: __SPAIR64__((unsigned int)v444.data, v214),
                   a4: v211,
                   a5: v213,
                   a6: v294,
                   a7: v322,
                   a8: v350,
                   a9: v378,
                   a10: v406,
                   a11: v434);
          for ( i26 = 0; v217->buffer[i26] != 0; ++i26 )
            ;
          out->Write(this: out, a2: v217, a3: i26);
        }
        ++v214;
        ++v215;
      }
      while ( v214 < v3->wrinkleMapRegionExpressions.num );
    }
    HIDWORD(v212) = v444.data;
    v219 = va::va(
             this: &v457,
             fmt: v40,
             a3: v212,
             a4: v211,
             a5: v213,
             a6: v294,
             a7: v322,
             a8: v350,
             a9: v378,
             a10: v406,
             a11: v434);
    for ( i27 = 0; v219->buffer[i27] != 0; ++i27 )
      ;
    out->Write(this: out, a2: v219, a3: i27);
    HIDWORD(v221) = v444.data;
    v224 = va::va(
             this: &v457,
             fmt: v100,
             a3: v221,
             a4: v223,
             a5: v222,
             a6: v295,
             a7: v323,
             a8: v351,
             a9: v379,
             a10: v407,
             a11: v435);
    for ( i28 = 0; v224->buffer[i28] != 0; ++i28 )
      ;
    out->Write(this: out, a2: v224, a3: i28);
  }
  num = v3->userChannelToAnimationAliasOverrides.num;
  if ( num > 0 && v3->model != nullptr )
  {
    HIDWORD(v104) = v444.data;
    v227 = va::va(
             this: &v457,
             fmt: "%suserChannelToAnimationAliasOverrides {\n",
             a3: v104,
             a4: v103,
             a5: v105,
             a6: v283,
             a7: v311,
             a8: v339,
             a9: v367,
             a10: v395,
             a11: v423);
    for ( i29 = 0; v227->buffer[i29] != 0; ++i29 )
      ;
    out->Write(this: out, a2: v227, a3: i29);
    v229 = 0;
    for ( i30 = num; i30 != 0; --i30 )
    {
      v231 = v3->model;
      v232 = &v3->userChannelToAnimationAliasOverrides.list[v229];
      value = (const idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)v232->first.value;
      HIWORD(v445) = v232->second.value;
      UserChannelName = idMD6Model::GetUserChannelName(this: v231, index: value);
      v237 = animation->FindAliasName(this: animation, a2: &v445);
      HIDWORD(v238) = v237;
      if ( UserChannelName != nullptr && v237 != nullptr )
      {
        v239 = va::va(
                 this: &v457,
                 fmt: "%s\t\"%s\" = \"%s\"\n",
                 a3: __SPAIR64__((unsigned int)v444.data, (unsigned int)UserChannelName),
                 a4: v238,
                 a5: v235,
                 a6: v296,
                 a7: v324,
                 a8: v352,
                 a9: v380,
                 a10: v408,
                 a11: v436);
        for ( i31 = 0; v239->buffer[i31] != 0; ++i31 )
          ;
        out->Write(this: out, a2: v239, a3: i31);
      }
      ++v229;
    }
    HIDWORD(v236) = v444.data;
    v241 = va::va(
             this: &v457,
             fmt: v100,
             a3: v236,
             a4: v238,
             a5: v235,
             a6: v296,
             a7: v324,
             a8: v352,
             a9: v380,
             a10: v408,
             a11: v436);
    for ( i32 = 0; v241->buffer[i32] != 0; ++i32 )
      ;
    out->Write(this: out, a2: v241, a3: i32);
  }
  LODWORD(v105) = v3->baseUserChannelAlias.value;
  if ( (_DWORD)v105 != 0xFFFF )
  {
    v243 = animation->FindAliasName(this: animation, a2: &v3->baseUserChannelAlias);
    if ( v243 != nullptr )
    {
      HIDWORD(v104) = v444.data;
      v244 = va::va(
               this: &v457,
               fmt: "%sbaseUserChannel {\n",
               a3: v104,
               a4: v103,
               a5: v105,
               a6: v283,
               a7: v311,
               a8: v339,
               a9: v367,
               a10: v395,
               a11: v423);
      for ( i33 = 0; v244->buffer[i33] != 0; ++i33 )
        ;
      out->Write(this: out, a2: v244, a3: i33);
      v248 = va::va(
               this: &v457,
               fmt: "%s\t\"%s\"\n",
               a3: __SPAIR64__((unsigned int)v444.data, (unsigned int)v243),
               a4: v247,
               a5: v246,
               a6: v297,
               a7: v325,
               a8: v353,
               a9: v381,
               a10: v409,
               a11: v437);
      for ( i34 = 0; v248->buffer[i34] != 0; ++i34 )
        ;
      out->Write(this: out, a2: v248, a3: i34);
      HIDWORD(v250) = v444.data;
      v253 = va::va(
               this: &v457,
               fmt: v100,
               a3: v250,
               a4: v252,
               a5: v251,
               a6: v298,
               a7: v326,
               a8: v354,
               a9: v382,
               a10: v410,
               a11: v438);
      for ( i35 = 0; v253->buffer[i35] != 0; ++i35 )
        ;
      out->Write(this: out, a2: v253, a3: i35);
    }
  }
  userChannelWeightGroupOverride = v3->userChannelWeightGroupOverride;
  if ( userChannelWeightGroupOverride < 0 || (v257 = userChannelWeightGroupOverride < 8, v256 = 1, !v257) )
    v256 = 0;
  if ( v256 != 0 )
  {
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "md6WeightGroup_t");
    if ( EnumInfo != nullptr )
    {
      HIDWORD(v104) = v444.data;
      v259 = va::va(
               this: &v457,
               fmt: "%suserChannelWeightGroupOverride {\n",
               a3: v104,
               a4: v103,
               a5: v105,
               a6: v283,
               a7: v311,
               a8: v339,
               a9: v367,
               a10: v395,
               a11: v423);
      for ( i36 = 0; v259->buffer[i36] != 0; ++i36 )
        ;
      out->Write(this: out, a2: v259, a3: i36);
      HIDWORD(v261) = v3->userChannelWeightGroupOverride;
      LODWORD(v262) = EnumInfo->values;
      HIDWORD(v262) = 8 * HIDWORD(v261);
      HIDWORD(v263) = v444.data;
      LODWORD(v263) = *(_DWORD *)(v262 + 8 * HIDWORD(v261));
      v264 = va::va(
               this: &v457,
               fmt: "%s\t\"%s\"\n",
               a3: v263,
               a4: v262,
               a5: v261,
               a6: v299,
               a7: v327,
               a8: v355,
               a9: v383,
               a10: v411,
               a11: v439);
      for ( i37 = 0; v264->buffer[i37] != 0; ++i37 )
        ;
      out->Write(this: out, a2: v264, a3: i37);
      HIDWORD(v266) = v444.data;
      v269 = va::va(
               this: &v457,
               fmt: v100,
               a3: v266,
               a4: v268,
               a5: v267,
               a6: v300,
               a7: v328,
               a8: v356,
               a9: v384,
               a10: v412,
               a11: v440);
      for ( i38 = 0; v269->buffer[i38] != 0; ++i38 )
        ;
      out->Write(this: out, a2: v269, a3: i38);
    }
  }
  HIDWORD(v104) = v5;
  v271 = va::va(
           this: &v457,
           fmt: v100,
           a3: v104,
           a4: v103,
           a5: v105,
           a6: v283,
           a7: v311,
           a8: v339,
           a9: v367,
           a10: v395,
           a11: v423);
  for ( i39 = 0; v271->buffer[i39] != 0; ++i39 )
    ;
  out->Write(this: out, a2: v271, a3: i39);
  idStr::FreeData(this: &v455);
  idStr::FreeData(this: &v444);
}


// ========================================================================
// $LN1082
// EA  : 0x82812B44
// RVA : 0x00812B44
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _LN1082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12768 + 96));
}


// ========================================================================
// __unwind$236270
// EA  : 0x82812B6C
// RVA : 0x00812B6C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_236270()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12768 + 192));
}


// ========================================================================
// __unwind$236271
// EA  : 0x82812B94
// RVA : 0x00812B94
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_236271()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12768 + 256));
}


// ========================================================================
// __unwind$236272
// EA  : 0x82812BBC
// RVA : 0x00812BBC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_236272()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 12768 + 144));
}


// ========================================================================
// __unwind$236273
// EA  : 0x82812BE4
// RVA : 0x00812BE4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_236273()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12768 + 224));
}


// ========================================================================
// __unwind$236274
// EA  : 0x82812C0C
// RVA : 0x00812C0C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_236274()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 12768 + 288));
}


// ========================================================================
// ?GetAliases@idDeclMD6@@QBAXAAV?$idList@PBVidMD6Alias@@$04@@_N@Z
// EA  : 0x82812C38
// RVA : 0x00812C38
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::GetAliases(idDeclMD6 *this, idList<enum encounterGroupRole_t,5> *list, bool includeParent)
{
  int num; // r26
  int v7; // r24
  int v8; // r28
  char v9; // r25
  int v10; // r30
  int v11; // r31
  idDeclMD6 *parentDecl; // r3
  int v13; // r30
  int v14; // r31
  idMD6Alias *v15; // [sp+50h] [-60h] BYREF

  num = list->num;
  v7 = 0;
  if ( this->aliases.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = 0;
      v10 = 0;
      if ( num > 0 )
      {
        v11 = 0;
        while ( idStr::Icmp(s1: *(const char **)list->list[v11], s2: this->aliases.list[v8].name.str) != 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= num )
            goto LABEL_9;
        }
        v9 = 1;
      }
LABEL_9:
      if ( v9 == 0 )
      {
        v15 = &this->aliases.list[v8];
        idList<idAnimWebBlendTree *,5>::Append(this: list, obj: (const encounterGroupRole_t *)&v15);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->aliases.num );
  }
  if ( includeParent )
  {
    parentDecl = this->parentDecl;
    if ( parentDecl != nullptr )
      idDeclMD6::GetAliases(this: parentDecl, (idList<idMD6Alias const *,5> *)list, includeParent: true);
    v13 = 0;
    if ( this->declsToIncludeAnimDataFrom.num > 0 )
    {
      v14 = 0;
      do
      {
        idDeclMD6::GetAliases(
          this: this->declsToIncludeAnimDataFrom.list[v14].includeDecl,
          (idList<idMD6Alias const *,5> *)list,
          includeParent: false);
        ++v13;
        ++v14;
      }
      while ( v13 < this->declsToIncludeAnimDataFrom.num );
    }
  }
}


// ========================================================================
// ?MergeEvents@@YAXABV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@AAV1@@Z
// EA  : 0x82812D58
// RVA : 0x00812D58
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall MergeEvents(const idList<idMD6Node *,5> *newEvents, idList<enum encounterGroupRole_t,5> *events)
{
  int v4; // r28
  int v5; // r30
  int v6; // r5
  int num; // r4
  const idMD6AnimEvent *v8; // r7
  int v9; // r9
  int frameNum; // r8
  const idMD6AnimEvent *v11; // r11
  int v12; // r10
  unsigned int row; // r11
  unsigned int v14; // r10
  idVec1 v15[12]; // [sp+50h] [-30h] BYREF

  if ( events->num != 0 )
  {
    v4 = 0;
    if ( newEvents->num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = 0;
        num = events->num;
        v8 = (const idMD6AnimEvent *)newEvents->list[v5];
        LODWORD(v15[0].x) = v8;
        if ( num <= 0 )
        {
LABEL_12:
          idList<idAnimWebBlendTree *,5>::Append(this: events, obj: (const encounterGroupRole_t *)v15);
        }
        else
        {
          v9 = 0;
          frameNum = v8->frameNum;
          while ( 1 )
          {
            v11 = (const idMD6AnimEvent *)events->list[v9];
            v12 = v11->frameNum;
            if ( frameNum < v12 )
              break;
            if ( frameNum == v12 )
            {
              row = v11->row;
              v14 = v8->row;
              if ( v14 == row )
                goto ExitLoop;
              if ( v14 <= row )
                break;
            }
            ++v6;
            ++v9;
            if ( v6 >= num )
              goto LABEL_12;
          }
          idList<idVec1,116>::Insert(this: (idList<idVec1,116> *)events, obj: v15, index: v4);
        }
ExitLoop:
        ++v4;
        ++v5;
      }
      while ( v4 < newEvents->num );
    }
  }
  else
  {
    idStaticList<idRibbon *,16>::operator=(this: (idStaticList<idEntity *,16> *)events, __that: newEvents);
  }
}


// ========================================================================
// ?FindAnimEvents@idDeclMD6@@QBA_NPBVidMD6Anim@@HHAAV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@@Z
// EA  : 0x82812E50
// RVA : 0x00812E50
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

BOOL __fastcall idDeclMD6::FindAnimEvents(
        idDeclMD6 *this,
        const idMD6Anim *anim,
        int startFrame,
        int endFrame,
        idList<idVehicleState *,5> *events)
{
  const idDeclMD6 *i; // r30
  int v12; // r21
  int v13; // r22
  const idDeclMD6 *j; // r30
  idAtomicStringT<enum md6AnimAtomicString_t> v15[4]; // [sp+50h] [-120h] BYREF
  idList<idVehicleState *,5> v16; // [sp+60h] [-110h] BYREF
  int v17; // [sp+70h] [-100h] BYREF
  idList<idVehicleState *,5> v18; // [sp+B0h] [-C0h] BYREF
  int v19; // [sp+C0h] [-B0h] BYREF

  if ( events->size < 0 )
    idList<idThread *,58>::Clear(this: events);
  events->num = __CFADD__(-events->size, events->size ^ 0x80000000) ? 0 : events->size;
  if ( anim == nullptr )
    return false;
  v15[0] = (idAtomicStringT<enum md6AnimAtomicString_t>)anim->name.str;
  idAnimEvents::FindAnimEvents(this: &this->animEvents, animRef: v15, startFrame, endFrame, events);
  for ( i = this->parentDecl; i != nullptr; v16.num = 0 )
  {
    v16.size = 16;
    v16.num = 0;
    v16.granularity = 1;
    v16.list = (idVehicleState **)&v17;
    v16.memTag = 5;
    v16.listStatic = 1;
    idAnimEvents::FindAnimEvents(this: &i->animEvents, animRef: v15, startFrame, endFrame, events: &v16);
    MergeEvents(newEvents: (const idList<idMD6Node *,5> *)&v16, (idList<enum encounterGroupRole_t,5> *)events);
    i = i->parentDecl;
    if ( v16.listStatic == 0 || v16.listStatic == 2 )
    {
      if ( v16.list != nullptr )
        idMem::Free(this: &mem, ptr: v16.list, align: ALIGN_16);
      v16.list = nullptr;
      v16.size = 0;
    }
  }
  v12 = 0;
  if ( this->declsToIncludeAnimDataFrom.num > 0 )
  {
    v13 = 0;
    do
    {
      for ( j = this->declsToIncludeAnimDataFrom.list[v13].includeDecl; j != nullptr; v18.num = 0 )
      {
        v18.size = 16;
        v18.num = 0;
        v18.granularity = 1;
        v18.list = (idVehicleState **)&v19;
        v18.memTag = 5;
        v18.listStatic = 1;
        idAnimEvents::FindAnimEvents(this: &j->animEvents, animRef: v15, startFrame, endFrame, events: &v18);
        MergeEvents(newEvents: (const idList<idMD6Node *,5> *)&v18, (idList<enum encounterGroupRole_t,5> *)events);
        j = j->parentDecl;
        if ( v18.listStatic == 0 || v18.listStatic == 2 )
        {
          if ( v18.list != nullptr )
            idMem::Free(this: &mem, ptr: v18.list, align: ALIGN_16);
          v18.list = nullptr;
          v18.size = 0;
        }
      }
      ++v12;
      ++v13;
    }
    while ( v12 < this->declsToIncludeAnimDataFrom.num );
  }
  return events->num != 0;
}


// ========================================================================
// __unwind$238586
// EA  : 0x8281304C
// RVA : 0x0081304C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_238586()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$238587
// EA  : 0x82813074
// RVA : 0x00813074
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_238587()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 176));
}


// ========================================================================
// ?FindAnimEvents@idDeclMD6@@QBA_NPBVidMD6Anim@@HHHAAV?$idStaticList@PBVidMD6AnimEvent@@$0BA@@@@Z
// EA  : 0x828130A8
// RVA : 0x008130A8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

BOOL __fastcall idDeclMD6::FindAnimEvents(
        idDeclMD6 *this,
        const idMD6Anim *anim,
        int startFrame,
        int endFrame,
        int eventNum,
        idList<idVehicleState *,5> *events)
{
  const idDeclMD6 *i; // r30
  int v13; // r20
  int v14; // r21
  const idDeclMD6 *j; // r30
  idAtomicStringT<enum md6AnimAtomicString_t> v17[4]; // [sp+50h] [-130h] BYREF
  idList<idVehicleState *,5> v18; // [sp+60h] [-120h] BYREF
  int v19; // [sp+70h] [-110h] BYREF
  idList<idVehicleState *,5> v20; // [sp+B0h] [-D0h] BYREF
  int v21; // [sp+C0h] [-C0h] BYREF

  if ( events->size < 0 )
    idList<idThread *,58>::Clear(this: events);
  events->num = __CFADD__(-events->size, events->size ^ 0x80000000) ? 0 : events->size;
  v17[0] = (idAtomicStringT<enum md6AnimAtomicString_t>)anim->name.str;
  idAnimEvents::FindAnimEvents(this: &this->animEvents, animRef: v17, startFrame, endFrame, eventNum, events);
  for ( i = this->parentDecl; i != nullptr; v18.num = 0 )
  {
    v18.size = 16;
    v18.num = 0;
    v18.granularity = 1;
    v18.list = (idVehicleState **)&v19;
    v18.memTag = 5;
    v18.listStatic = 1;
    idAnimEvents::FindAnimEvents(this: &i->animEvents, animRef: v17, startFrame, endFrame, eventNum, events: &v18);
    MergeEvents(newEvents: (const idList<idMD6Node *,5> *)&v18, (idList<enum encounterGroupRole_t,5> *)events);
    i = i->parentDecl;
    if ( v18.listStatic == 0 || v18.listStatic == 2 )
    {
      if ( v18.list != nullptr )
        idMem::Free(this: &mem, ptr: v18.list, align: ALIGN_16);
      v18.list = nullptr;
      v18.size = 0;
    }
  }
  v13 = 0;
  if ( this->declsToIncludeAnimDataFrom.num > 0 )
  {
    v14 = 0;
    do
    {
      for ( j = this->declsToIncludeAnimDataFrom.list[v14].includeDecl; j != nullptr; v20.num = 0 )
      {
        v20.size = 16;
        v20.num = 0;
        v20.granularity = 1;
        v20.list = (idVehicleState **)&v21;
        v20.memTag = 5;
        v20.listStatic = 1;
        idAnimEvents::FindAnimEvents(this: &j->animEvents, animRef: v17, startFrame, endFrame, eventNum, events: &v20);
        MergeEvents(newEvents: (const idList<idMD6Node *,5> *)&v20, (idList<enum encounterGroupRole_t,5> *)events);
        j = j->parentDecl;
        if ( v20.listStatic == 0 || v20.listStatic == 2 )
        {
          if ( v20.list != nullptr )
            idMem::Free(this: &mem, ptr: v20.list, align: ALIGN_16);
          v20.list = nullptr;
          v20.size = 0;
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->declsToIncludeAnimDataFrom.num );
  }
  return events->num != 0;
}


// ========================================================================
// __unwind$238961
// EA  : 0x828132A4
// RVA : 0x008132A4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_238961()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$238962
// EA  : 0x828132CC
// RVA : 0x008132CC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_238962()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 176));
}


// ========================================================================
// ?MergeJoints@@YAXABV?$idStaticList@PBVidCachedJoint@@$07@@AAV1@@Z
// EA  : 0x828132F8
// RVA : 0x008132F8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall MergeJoints(
        const idStaticList<idCachedJoint const *,8> *newJoints,
        idList<enum encounterGroupRole_t,5> *joints)
{
  int v4; // r28
  int v5; // r30
  char v6; // r4
  int num; // r6
  int v8; // r9
  const idCachedJoint *v9; // r5
  int v10; // r11
  const idCachedJoint *v11; // r10
  const idCachedJoint *v12; // [sp+50h] [-30h] BYREF

  v4 = 0;
  if ( newJoints->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = 0;
      num = joints->num;
      v8 = 0;
      v9 = newJoints->list[v5];
      v12 = v9;
      if ( num > 0 )
      {
        v10 = 0;
        while ( 1 )
        {
          v11 = (const idCachedJoint *)joints->list[v10];
          if ( v9->frameNum != v11->frameNum && v9->jointIndex.value != v11->jointIndex.value )
            break;
          ++v8;
          ++v10;
          if ( v8 >= num )
            goto LABEL_10;
        }
        v6 = 1;
      }
LABEL_10:
      if ( v6 == 0 )
        idList<idAnimWebBlendTree *,5>::Append(this: joints, obj: (const encounterGroupRole_t *)&v12);
      ++v4;
      ++v5;
    }
    while ( v4 < newJoints->num );
  }
}


// ========================================================================
// ??0animEventInfo_t@idAnimEvents@@QAA@XZ
// EA  : 0x82813B20
// RVA : 0x00813B20
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idAnimEvents::animEventInfo_t *__fastcall idAnimEvents::animEventInfo_t::animEventInfo_t(
        idAnimEvents::animEventInfo_t *this)
{
  this->animRef.str = &byte_8200D768;
  this->events.granularity = 0;
  this->events.memTag = 28;
  this->events.listStatic = 0;
  this->events.list = nullptr;
  this->events.size = 0;
  this->events.num = 0;
  return this;
}


// ========================================================================
// ??1animEventInfo_t@idAnimEvents@@QAA@XZ
// EA  : 0x82813B58
// RVA : 0x00813B58
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimEvents::animEventInfo_t::~animEventInfo_t(idAnimEvents::animEventInfo_t *this)
{
  idMD6AnimEvent *list; // r3
  idMD6AnimEvent *v3; // r3

  idAtomicString::Set(this: &this->animRef, str_: &byte_8200D768);
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    list = this->events.list;
    if ( list != nullptr )
      idListArrayDelete<idMD6AnimEvent>(ptr: list, num: this->events.size);
    this->events.list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    v3 = this->events.list;
    if ( v3 != nullptr )
      idListArrayDelete<idMD6AnimEvent>(ptr: v3, num: this->events.size);
    this->events.list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
}


// ========================================================================
// __unwind$240049
// EA  : 0x82813BF0
// RVA : 0x00813BF0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_240049()
{
  int v0; // r12

  idList<idMD6AnimEvent,28>::~idList<idMD6AnimEvent,28>(this: (idList<idMD6AnimEvent,28> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                          + 4));
}


// ========================================================================
// ?IncludeAnimDataFrom@idDeclMD6@@AAAXPBV1@@Z
// EA  : 0x82813C20
// RVA : 0x00813C20
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::IncludeAnimDataFrom(idDeclMD6 *this, const idDeclMD6 *includeDecl)
{
  breakableIsland_t *v4; // r3
  const idDeclMD6 *parentDecl; // r4
  breakableIsland_t *v6; // r3
  int v7; // r26
  int i; // r28
  const idDeclMD6 *v9; // r7
  int num; // r8
  int v11; // r10
  int v12; // r11
  char v13; // r11
  int v14; // r11
  int size; // r10
  idDeclMD6::includeDecl_t *list; // r9
  int v17; // r11

  if ( (unsigned __int8)idDeclMD6::HasIncludedDecl(this, includeDecl) == 0 )
  {
    v4 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&this->declsToIncludeAnimDataFrom);
    v4->index = (int)includeDecl;
    HIBYTE(v4->lowestPoint) = 1;
  }
  parentDecl = includeDecl->parentDecl;
  if ( parentDecl != nullptr && (unsigned __int8)idDeclMD6::HasIncludedDecl(this, includeDecl: parentDecl) == 0 )
  {
    v6 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&this->declsToIncludeAnimDataFrom);
    HIBYTE(v6->lowestPoint) = 0;
    v6->index = (int)includeDecl->parentDecl;
  }
  v7 = 0;
  if ( includeDecl->declsToIncludeAnimDataFrom.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v9 = includeDecl->declsToIncludeAnimDataFrom.list[i].includeDecl;
      if ( v9 == this || this->parentDecl == v9 )
        goto LABEL_15;
      num = this->declsToIncludeAnimDataFrom.num;
      v11 = 0;
      if ( num > 0 )
        break;
LABEL_14:
      v13 = 0;
LABEL_16:
      if ( v13 == 0 )
      {
        idList<cockpitSeatInfo_t,5>::PreAllocateWithGranularity(
          this: (idList<breakableIsland_t,59> *)&this->declsToIncludeAnimDataFrom,
          newSize: this->declsToIncludeAnimDataFrom.num + 1);
        v14 = this->declsToIncludeAnimDataFrom.num;
        size = this->declsToIncludeAnimDataFrom.size;
        list = this->declsToIncludeAnimDataFrom.list;
        if ( v14 >= size )
        {
          v17 = (int)&list[size - 1];
        }
        else
        {
          this->declsToIncludeAnimDataFrom.num = v14 + 1;
          v17 = (int)&list[v14];
        }
        *(_BYTE *)(v17 + 4) = 0;
        *(_DWORD *)v17 = includeDecl->declsToIncludeAnimDataFrom.list[i].includeDecl;
      }
      if ( ++v7 >= includeDecl->declsToIncludeAnimDataFrom.num )
        return;
    }
    v12 = 0;
    while ( this->declsToIncludeAnimDataFrom.list[v12].includeDecl != v9 )
    {
      ++v11;
      ++v12;
      if ( v11 >= num )
        goto LABEL_14;
    }
LABEL_15:
    v13 = 1;
    goto LABEL_16;
  }
}


// ========================================================================
// ?InitUserChannelToAnimationAliasMap@idDeclMD6@@AAAXXZ
// EA  : 0x82813D80
// RVA : 0x00813D80
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::InitUserChannelToAnimationAliasMap(idDeclMD6 *this)
{
  const idMD6Skel *skeleton; // r10
  const idDeclMD6 *parentDecl; // r11
  int num; // r29
  int v5; // r25
  idMD6SkelData *data; // r11
  int numUserChannels; // r27
  int v8; // r31
  int v9; // r30
  unsigned __int16 value; // r7
  int v11; // r9
  idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> > *list; // r8
  int v13; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v14; // [sp+50h] [-50h] BYREF

  skeleton = this->model->skeleton;
  if ( skeleton != nullptr )
  {
    parentDecl = this->parentDecl;
    num = this->userChannelToAnimationAliasOverrides.num;
    if ( parentDecl != nullptr )
      v5 = parentDecl->userChannelToAnimationAliasMap.num;
    else
      v5 = 0;
    data = skeleton->data;
    numUserChannels = data->numUserChannels;
    if ( numUserChannels > this->userChannelToAnimationAliasMap.size )
      idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
        this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *)&this->userChannelToAnimationAliasMap,
        newsize: data->numUserChannels);
    v8 = 0;
    if ( numUserChannels > 0 )
    {
      v9 = 0;
      do
      {
        value = -1;
        v11 = 0;
        v14.value = -1;
        if ( num > 0 )
        {
          list = this->userChannelToAnimationAliasOverrides.list;
          v13 = 0;
          while ( list[v13].first.value != v8 )
          {
            ++v11;
            ++v13;
            if ( v11 >= num )
              goto LABEL_15;
          }
          value = list[v13].second.value;
          v14.value = value;
        }
LABEL_15:
        if ( value == 0xFFFF && v8 < v5 )
          v14.value = this->parentDecl->userChannelToAnimationAliasMap.list[v9].value;
        idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Append(
          this: (idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,30> *)&this->userChannelToAnimationAliasMap,
          obj: &v14);
        ++v8;
        ++v9;
      }
      while ( v8 < numUserChannels );
    }
  }
}


// ========================================================================
// ?GetCachedJoints@idDeclMD6@@QBA_NHPBVidMD6Anim@@AAV?$idStaticList@PBVidCachedJoint@@$07@@@Z
// EA  : 0x82813E90
// RVA : 0x00813E90
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

BOOL __fastcall idDeclMD6::GetCachedJoints(
        idDeclMD6 *this,
        int eventNum,
        const idMD6Anim *anim,
        idList<idVehicleState *,5> *joints)
{
  int AnimEventInfoIndex; // r3
  idAnimEvents::animEventInfo_t *v9; // r3
  const idDeclMD6 *i; // r29
  int v11; // r3
  idAnimEvents::animEventInfo_t *v12; // r3
  idAtomicStringT<enum md6AnimAtomicString_t> v14[4]; // [sp+50h] [-A0h] BYREF
  idStaticList<idCachedJoint const *,8> v15[3]; // [sp+60h] [-90h] BYREF

  if ( joints->size < 0 )
    idList<idThread *,58>::Clear(this: joints);
  joints->num = __CFADD__(-joints->size, joints->size ^ 0x80000000) ? 0 : joints->size;
  if ( anim != nullptr )
  {
    v14[0] = (idAtomicStringT<enum md6AnimAtomicString_t>)anim->name.str;
    AnimEventInfoIndex = idAnimEvents::FindAnimEventInfoIndex(this: &this->animEvents, animRef: v14);
    if ( AnimEventInfoIndex >= 0 )
    {
      v9 = &this->animEvents.list.list[AnimEventInfoIndex];
      if ( v9 != nullptr )
        idAnimEvents::animEventInfo_t::GetCachedJoints(this: v9, eventNum, list: joints);
    }
  }
  for ( i = this->parentDecl; i != nullptr; v15[0].num = 0 )
  {
    v15[0].size = 8;
    v15[0].num = 0;
    v15[0].granularity = 1;
    v15[0].list = v15[0].staticList;
    v15[0].memTag = 5;
    v15[0].listStatic = 1;
    if ( anim != nullptr )
    {
      v14[0] = (idAtomicStringT<enum md6AnimAtomicString_t>)anim->name.str;
      v11 = idAnimEvents::FindAnimEventInfoIndex(this: &i->animEvents, animRef: v14);
      if ( v11 >= 0 )
      {
        v12 = &i->animEvents.list.list[v11];
        if ( v12 != nullptr )
          idAnimEvents::animEventInfo_t::GetCachedJoints(this: v12, eventNum, list: (idList<idVehicleState *,5> *)v15);
      }
    }
    MergeJoints(newJoints: v15, (idList<enum encounterGroupRole_t,5> *)joints);
    i = i->parentDecl;
    if ( v15[0].listStatic == 0 || v15[0].listStatic == 2 )
    {
      if ( v15[0].list != nullptr )
        idMem::Free(this: &mem, ptr: v15[0].list, align: ALIGN_16);
      v15[0].list = nullptr;
      v15[0].size = 0;
    }
  }
  return joints->num != 0;
}


// ========================================================================
// __unwind$240489
// EA  : 0x82814024
// RVA : 0x00814024
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_240489()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ?AddAlias@idDeclMD6@@QAA?AV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@ABVidMD6Alias@@_N@Z
// EA  : 0x82814B28
// RVA : 0x00814B28
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::AddAlias(
        idDeclMD6 *this,
        const idDeclMD6 *result,
        idMD6Alias *inAlias,
        const bool overload)
{
  idDeclMD6 *parentDecl; // r3
  const idMD6Alias *Alias; // r3
  const idMD6Alias *v9; // r29
  int v11; // r26
  int v12; // r29
  idDeclMD6 *includeDecl; // r28
  const idMD6Alias *v14; // r3
  const idMD6Alias *v15; // r28
  const idMD6Alias *v16; // r4
  int v17; // r30
  unsigned __int16 v18; // [sp+50h] [-50h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v19[39]; // [sp+52h] [-4Eh] BYREF

  if ( overload )
    goto LABEL_12;
  parentDecl = result->parentDecl;
  if ( parentDecl != nullptr )
  {
    Alias = idDeclMD6::FindAlias(this: parentDecl, aliasName: inAlias->name.str, includeInherited: true);
    v9 = Alias;
    if ( Alias != nullptr && idMD6Alias::IsInherited(this: inAlias, other: Alias) )
    {
      HIWORD(this->__vftable) = v9->aliasHandle.value;
      return this;
    }
  }
  v11 = 0;
  if ( result->declsToIncludeAnimDataFrom.num <= 0 )
  {
LABEL_12:
    animation->RegisterAlias(
      this: (idAnimation *)&v18,
      result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
      a3: result,
      a4: inAlias->name.str);
    v16 = inAlias;
    v17 = v18;
    idList<idMD6Alias,19>::Append(this: &result->aliases, obj: v16);
    result->aliases.list[result->aliases.num - 1].aliasHandle.value = v18;
    idHashIndex::Add(this: &result->aliasHash, key: v17, index: result->aliases.num - 1);
    HIWORD(this->__vftable) = v18;
    return this;
  }
  else
  {
    v12 = 0;
    while ( 1 )
    {
      includeDecl = result->declsToIncludeAnimDataFrom.list[v12].includeDecl;
      ((void (__fastcall *)(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *))animation->FindAliasHandle_2)(a1: v19);
      if ( v19[0].value != 0xFFFF )
      {
        v14 = idDeclMD6::FindAlias(this: includeDecl, aliasHandle: v19, includeInherited: true);
        v15 = v14;
        if ( v14 != nullptr && idMD6Alias::IsInherited(this: inAlias, other: v14) )
          break;
      }
      ++v11;
      ++v12;
      if ( v11 >= result->declsToIncludeAnimDataFrom.num )
        goto LABEL_12;
    }
    HIWORD(this->__vftable) = v15->aliasHandle.value;
    return this;
  }
}


// ========================================================================
// ?Free@idAnimEvents@@QAAXXZ
// EA  : 0x82814EE0
// RVA : 0x00814EE0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimEvents::Free(idAnimEvents *this)
{
  idAnimEvents::animEventInfo_t *list; // r3

  idHashIndex::Free(this: &this->hashIndex);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimEvents::animEventInfo_t>(ptr: list, num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ?FreeData@idDeclMD6@@UAAXXZ
// EA  : 0x82814F50
// RVA : 0x00814F50
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::FreeData(idDeclMD6 *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3

  this->model = nullptr;
  idStr::operator=(this: &this->parent, text: &byte_8200D768);
  this->parentDecl = nullptr;
  idJointGroupCollection::Free(this: &this->jointGroupCollection);
  idEyeInfoCollection::Free(this: &this->eyeInfoCollection);
  idList<idPropInfo,82>::Clear(this: &this->props.props);
  idAnimEvents::Free(this: &this->animEvents);
  if ( this->userProps.listStatic == 0 || this->userProps.listStatic == 2 )
  {
    list = (char *)this->userProps.list;
    if ( list != nullptr )
      idListArrayDelete<idVarArgs<6>>(ptr: list, num: this->userProps.size);
    this->userProps.list = nullptr;
    this->userProps.size = 0;
  }
  this->userProps.num = 0;
  if ( this->aliases.listStatic == 0 || this->aliases.listStatic == 2 )
  {
    v3 = (char *)this->aliases.list;
    if ( v3 != nullptr )
      idListArrayDelete<idMD6Alias>(ptr: v3, num: this->aliases.size);
    this->aliases.list = nullptr;
    this->aliases.size = 0;
  }
  this->aliases.num = 0;
  idHashIndex::Clear(this: &this->aliasHash);
  this->morphVertices = nullptr;
  if ( this->morphDefList.listStatic == 0 || this->morphDefList.listStatic == 2 )
  {
    v4 = (char *)this->morphDefList.list;
    if ( v4 != nullptr )
      idListArrayDelete<idMorphDef>(ptr: v4, num: this->morphDefList.size);
    this->morphDefList.list = nullptr;
    this->morphDefList.size = 0;
  }
  this->morphDefList.num = 0;
}


// ========================================================================
// ?InitHeadTrackGroups@idDeclMD6@@AAAXXZ
// EA  : 0x82815070
// RVA : 0x00815070
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::InitHeadTrackGroups(idDeclMD6 *this)
{
  const idMD6Model *model; // r11
  idJointGroupCollection *p_jointGroupCollection; // r30
  idMD6Skel *skeleton; // r21
  int v5; // r3
  int listStatic; // r11
  int v7; // r29
  char **p_headTrackGroups; // r30
  int size; // r11
  int networkID; // r19
  idResourceList *resourceListPtr; // r24
  int v12; // r20
  int i; // r11
  const char *resourceError; // r25
  idDeclMD6::idHeadTrackGroup *v15; // r23
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  const idJointGroup *JointGroupForIndex; // r3
  const idJointGroup *v20; // r29
  int v21; // r30
  float *v22; // r11
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  idJointGroup *JointGroupForName; // r3
  idJointGroup *v27; // r30
  __int64 v28; // r6
  va *v29; // r3
  int num; // r11
  __int64 v31; // r10
  va *v32; // r3
  const char *v33; // r4
  __int64 v34; // r10
  __int64 v35; // r8
  __int64 v36; // r6
  idJointGroup *v37; // r3
  idJointGroup *v38; // r30
  __int64 v39; // r6
  va *v40; // r3
  int v41; // r11
  __int64 v42; // r10
  va *v43; // r3
  const char *str; // r3
  int v45; // r3
  int v46; // r11
  _DWORD *v47; // r26
  int j; // r30
  int v49; // r29
  idList<idDeclMD6::idHeadTrackJoint,5> *p_trackJoints; // r29
  double v51; // fp31
  int v52; // r27
  const idMD6Anim *defaultAnim; // r28
  int v54; // r9
  int v55; // r30
  int k; // r11
  int v57; // r11
  int v58; // r10
  idDeclMD6::idHeadTrackJoint *list; // r9
  int v60; // r10
  char *v61; // r11
  double v62; // fp30
  int m; // r28
  idIndex<short,enum invalidJointIndex_t> *v64; // r5
  idIndex<short,enum invalidJointIndex_t> *v65; // r4
  const char *v66; // r27
  __int64 v67; // r8
  __int64 v68; // r10
  __int64 v69; // r6
  va *v70; // r3
  int n; // r11
  va *v72; // r3
  int v73; // [sp+8h] [-11D8h]
  int v74; // [sp+Ch] [-11D4h]
  int v75; // [sp+10h] [-11D0h]
  int v76; // [sp+14h] [-11CCh]
  int v77; // [sp+18h] [-11C8h]
  int v78; // [sp+1Ch] [-11C4h]
  idMD6Skel v79; // [sp+50h] [-1190h] BYREF
  const char *v80; // [sp+84h] [-115Ch]
  const char *v81; // [sp+88h] [-1158h]
  const char *v82; // [sp+8Ch] [-1154h]
  int v83; // [sp+90h] [-1150h]
  const char *v84; // [sp+94h] [-114Ch]
  idStr v85; // [sp+A0h] [-1140h] BYREF
  idStr v86; // [sp+C0h] [-1120h] BYREF
  idStr v87; // [sp+E0h] [-1100h] BYREF
  idStr v88; // [sp+100h] [-10E0h] BYREF
  va v89; // [sp+120h] [-10C0h] BYREF

  model = this->model;
  memset(&v79.resourceListPtr, 0, 12);
  p_jointGroupCollection = &this->jointGroupCollection;
  v79.staleCount = 1280;
  skeleton = model->skeleton;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v79.resourceListPtr);
  v5 = idJointGroupCollection::NumJointGroupsForType(this: p_jointGroupCollection, type: JOINTGROUP_HEADTRACKING);
  listStatic = this->headTrackGroups.listStatic;
  v7 = v5;
  v83 = v5;
  p_headTrackGroups = (char **)&this->headTrackGroups;
  if ( listStatic == 0 || listStatic == 2 )
  {
    if ( *p_headTrackGroups != nullptr )
      idListArrayDelete<idDeclMD6::idHeadTrackGroup>(ptr: *p_headTrackGroups, num: this->headTrackGroups.size);
    *p_headTrackGroups = nullptr;
    this->headTrackGroups.size = 0;
  }
  this->headTrackGroups.num = 0;
  if ( v7 <= this->headTrackGroups.size
    || (unsigned __int8)idList<idDeclMD6::idHeadTrackGroup,5>::Resize(this: &this->headTrackGroups, newsize: v7) != 0 )
  {
    size = this->headTrackGroups.size;
    if ( v7 < size )
      size = v7;
    this->headTrackGroups.num = size;
  }
  networkID = v79.networkID;
  resourceListPtr = v79.resourceListPtr;
  v84 = "Head tracking group '%s' from model '%s' has no weights.";
  v80 = "More than one joint was found in the orientation group for model '%s'. The first joint will be used.";
  *(_DWORD *)&v79.jointConversion.value = "_orientation";
  v81 = "More than one joint was found in the focus group for model '%s'. The first joint will be used.";
  v12 = 0;
  v82 = "_focus";
  while ( v12 < v7 )
  {
    if ( LOBYTE(v79.staleCount) == 0 || LOBYTE(v79.staleCount) == 2 )
    {
      if ( resourceListPtr != nullptr )
      {
        for ( i = 0; i < networkID; ++i )
          ;
        idMem::Free(this: &mem, ptr: resourceListPtr, align: ALIGN_16);
      }
      resourceListPtr = nullptr;
      v79.resourceListPtr = nullptr;
      networkID = 0;
      v79.networkID = 0;
    }
    v79.resourceError = nullptr;
    resourceError = nullptr;
    v15 = &this->headTrackGroups.list[v12];
    JointGroupForIndex = idJointGroupCollection::GetJointGroupForIndex(
                           this: &this->jointGroupCollection,
                           type: JOINTGROUP_HEADTRACKING,
                           index: v12);
    v20 = JointGroupForIndex;
    if ( JointGroupForIndex == nullptr || JointGroupForIndex->joints.num == 0 )
    {
      HIDWORD(v18) = this->name.str;
      v72 = va::va(
              this: &v89,
              fmt: "No joints were found in the head tracking group for model '%s'.",
              a3: v18,
              a4: v17,
              a5: v16,
              a6: v73,
              a7: v74,
              a8: v75,
              a9: v76,
              a10: v77,
              a11: v78);
      strncpy(dest: idException::error, source: v72->buffer, count: 0x800u);
      BYTE2(v79.__vftable) = HIBYTE(v79.__vftable);
      CxxThrowException(
        pExceptionObject: (char *)&v79.__vftable + 2,
        pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
    v21 = 0;
    v15->name.str = JointGroupForIndex->groupName.str;
    while ( v21 < v20->joints.num )
    {
      idList<breakableJoint_t,5>::PreAllocateWithGranularity(
        this: (idList<lookJointInfo_t,5> *)&v79.resourceListPtr,
        newSize: (int)(resourceError + 1));
      resourceError = v79.resourceError;
      networkID = v79.networkID;
      resourceListPtr = v79.resourceListPtr;
      if ( (int)v79.resourceError >= v79.networkID )
      {
        v22 = (float *)((char *)v79.resourceListPtr + 8 * v79.networkID - 8);
      }
      else
      {
        v22 = (float *)((char *)v79.resourceListPtr + 8 * (int)v79.resourceError);
        resourceError = ++v79.resourceError;
      }
      *(_WORD *)v22 = v20->joints.list[v21].value;
      if ( v21 < 0 || v21 >= v20->jointScalars.num )
      {
        v22[1] = 1.0;
        ++v21;
      }
      else
      {
        v22[1] = v20->jointScalars.list[v21++];
      }
    }
    idStr::idStr(this: &v87, text: v82);
    operator+(result: &v86, a: v15->name.str, b: &v87);
    idStr::FreeData(this: &v87);
    JointGroupForName = idJointGroupCollection::GetJointGroupForName(
                          this: &this->jointGroupCollection,
                          type: JOINTGROUP_FOCUS,
                          name: v86.data);
    v27 = JointGroupForName;
    if ( JointGroupForName == nullptr )
    {
      HIDWORD(v28) = v15->name.str;
      LODWORD(v28) = v86.data;
      v29 = va::va(
              this: &v89,
              fmt: "No focus joint group found for head tracking group '%s'. Expect focus group to be named '%s'",
              a3: v28,
              a4: v24,
              a5: v23,
              a6: v73,
              a7: v74,
              a8: v75,
              a9: v76,
              a10: v77,
              a11: v78);
      strncpy(dest: idException::error, source: v29->buffer, count: 0x800u);
      LOBYTE(v79.trackedMemory) = HIBYTE(v79.__vftable);
      CxxThrowException(
        pExceptionObject: (char *)&v79.trackedMemory + 3,
        pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
    num = JointGroupForName->joints.num;
    HIDWORD(v31) = -num & ~num;
    v79.name.str = (const char *)num;
    if ( v31 >= 0 )
    {
      HIDWORD(v25) = this->name.str;
      LODWORD(v31) = -num;
      LODWORD(v24) = HIDWORD(v31) >> 31;
      v32 = va::va(
              this: &v89,
              fmt: "No joints were found in the focus group for model '%s'.",
              a3: v25,
              a4: v24,
              a5: v31,
              a6: v73,
              a7: v74,
              a8: v75,
              a9: v76,
              a10: v77,
              a11: v78);
      strncpy(dest: idException::error, source: v32->buffer, count: 0x800u);
      LOBYTE(v79.__vftable) = HIBYTE(v79.__vftable);
      CxxThrowException(
        pExceptionObject: (char *)&v79.__vftable + 3,
        pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
    v79.name.str = (const char *)num;
    if ( num != 1 )
      idLib::Warning(fmt: v81, this->name.str);
    v33 = *(const char **)&v79.jointConversion.value;
    v15->focusJointIdx.value = v27->joints.list->value;
    idStr::idStr(this: &v88, text: v33);
    operator+(result: &v85, a: v15->name.str, b: &v88);
    idStr::FreeData(this: &v88);
    v37 = idJointGroupCollection::GetJointGroupForName(
            this: &this->jointGroupCollection,
            type: JOINTGROUP_ORIENTATION,
            name: v85.data);
    v38 = v37;
    if ( v37 == nullptr )
    {
      HIDWORD(v39) = v15->name.str;
      LODWORD(v39) = v85.data;
      v40 = va::va(
              this: &v89,
              fmt: "No orientation joint group found for head tracking group '%s'. Expect orientation group to be named '%s'",
              a3: v39,
              a4: v35,
              a5: v34,
              a6: v73,
              a7: v74,
              a8: v75,
              a9: v76,
              a10: v77,
              a11: v78);
      strncpy(dest: idException::error, source: v40->buffer, count: 0x800u);
      HIBYTE(v79.trackedMemory) = HIBYTE(v79.__vftable);
      CxxThrowException(pExceptionObject: &v79.trackedMemory, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
    v41 = v37->joints.num;
    HIDWORD(v42) = -v41 & ~v41;
    v79.name.str = (const char *)v41;
    if ( v42 >= 0 )
    {
      HIDWORD(v36) = this->name.str;
      LODWORD(v42) = -v41;
      LODWORD(v35) = HIDWORD(v42) >> 31;
      v43 = va::va(
              this: &v89,
              fmt: "No joints were found in the orientation group for model '%s'.",
              a3: v36,
              a4: v35,
              a5: v42,
              a6: v73,
              a7: v74,
              a8: v75,
              a9: v76,
              a10: v77,
              a11: v78);
      strncpy(dest: idException::error, source: v43->buffer, count: 0x800u);
      BYTE1(v79.trackedMemory) = HIBYTE(v79.__vftable);
      CxxThrowException(
        pExceptionObject: (char *)&v79.trackedMemory + 1,
        pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
    }
    v79.name.str = (const char *)v41;
    if ( v41 != 1 )
      idLib::Warning(fmt: v80, this->name.str);
    str = v15->name.str;
    v15->orientationJointIdx.value = v38->joints.list->value;
    v45 = idStr::Find(searchIn: str, searchFor: "look", casesensitive: false, start: 0, end: -1);
    v46 = 500;
    if ( v45 == -1 )
      v46 = 250;
    v15->blendTime = v46;
    memset((char *)&v79.idResource + 32, 0, 12);
    v79.timestamp = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v79.idResource + 2);
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v79.idResource + 2, newNum: (int)resourceError);
    v47 = *((_DWORD **)&v79.idResource + 8);
    for ( j = 0; j < (int)resourceError; ++j )
    {
      v49 = 0;
      v47[j] = 0;
      while ( v49 < (int)resourceError )
      {
        if ( v49 != j
          && idMD6Skel::IsJointChildOf(
               this: skeleton,
               joint: (idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&resourceListPtr->__vftable + 4 * j),
               parent: (idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)&resourceListPtr->__vftable + 4 * v49)) )
        {
          ++v47[j];
        }
        ++v49;
      }
    }
    p_trackJoints = &v15->trackJoints;
    v51 = 0.0;
    if ( v15->trackJoints.size < 0 )
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v15->trackJoints);
    v52 = (int)(resourceError - 1);
    defaultAnim = v79.defaultAnim;
    v15->trackJoints.num = __CFADD__(-v15->trackJoints.size, v15->trackJoints.size ^ 0x80000000)
                         ? 0
                         : v15->trackJoints.size;
    while ( v52 >= 0 )
    {
      v54 = 0x7FFFFFFF;
      v55 = -1;
      for ( k = 0; k < (int)resourceError; ++k )
      {
        if ( v47[k] < v54 )
        {
          v54 = v47[k];
          v55 = k;
        }
      }
      p_trackJoints = &v15->trackJoints;
      idList<idDeclMD6::idHeadTrackJoint,5>::PreAllocateWithGranularity(
        this: &v15->trackJoints,
        newSize: v15->trackJoints.num + 1);
      v57 = v15->trackJoints.num;
      v58 = v15->trackJoints.size;
      list = v15->trackJoints.list;
      if ( v57 >= v58 )
      {
        v60 = (int)&list[v58 - 1];
      }
      else
      {
        v15->trackJoints.num = v57 + 1;
        v60 = (int)&list[v57];
      }
      v61 = (char *)resourceListPtr + 8 * v55;
      v79.name.str = v61;
      *(_WORD *)v60 = *(_WORD *)v61;
      *(float *)(v60 + 4) = *((float *)v61 + 1);
      *(float *)(v60 + 8) = *((float *)v61 + 1);
      v51 = (float)(*((float *)v61 + 1) + (float)v51);
      if ( v55 >= 0 )
      {
        if ( v55 < (int)resourceError )
        {
          v79.resourceError = --resourceError;
          if ( (const char *)v55 != resourceError )
          {
            *(_DWORD *)v61 = *((_DWORD *)&resourceListPtr->__vftable + 2 * (_DWORD)resourceError);
            *((_DWORD *)v61 + 1) = *((_DWORD *)&resourceListPtr->resourceTypeName + 2 * (_DWORD)resourceError);
          }
        }
        if ( v55 < (int)defaultAnim )
        {
          defaultAnim = (const idMD6Anim *)((char *)defaultAnim - 1);
          v79.defaultAnim = defaultAnim;
          if ( (const idMD6Anim *)v55 != defaultAnim )
            v47[v55] = v47[(_DWORD)defaultAnim];
        }
      }
      --v52;
    }
    if ( v51 <= 0.0 )
      v62 = 1.0;
    else
      v62 = (float)((float)1.0 / (float)v51);
    if ( v51 == 0.0 )
    {
      idLib::Warning(fmt: v84, v15->name.str, this->name.str);
    }
    else if ( v51 > 1.0 )
    {
      idLib::Warning(
        fmt: "Head tracking group '%s' from model '%s' has weights totaling > 1.0.",
        v15->name.str,
        this->name.str);
    }
    for ( m = 1; m < v15->trackJoints.num; ++m )
    {
      p_trackJoints->list[m].pitchScale = (float)v62 * p_trackJoints->list[m].pitchScale;
      p_trackJoints->list[m].yawScale = (float)v62 * p_trackJoints->list[m].yawScale;
      v79.name.str = (const char *)&p_trackJoints->list[m];
      v64 = (idIndex<short,enum invalidJointIndex_t> *)*((unsigned __int16 *)v79.name.str - 6);
      v65 = (idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)v79.name.str;
      v79.name.str -= 12;
      if ( !idMD6Skel::IsJointChildOf(this: skeleton, joint: v65, parent: v64) )
      {
        idMD6Skel::GetJointHandle(
          this: &v79,
          result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this->model->skeleton,
          jointIdx: p_trackJoints->list[m - 1].jointIdx.value);
        if ( HIWORD(v79.__vftable) == 0xFFFF )
          v66 = nullptr;
        else
          v66 = animation->GetJointName(this: animation, a2: &v79);
        idMD6Skel::GetJointHandle(
          this: (idMD6Skel *)&v79.nextOnHashChain,
          result: (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)this->model->skeleton,
          jointIdx: p_trackJoints->list[m].jointIdx.value);
        LODWORD(v68) = HIWORD(v79.nextOnHashChain);
        if ( HIWORD(v79.nextOnHashChain) == 0xFFFF )
          LODWORD(v69) = 0;
        else
          LODWORD(v69) = animation->GetJointName(this: animation, a2: &v79.nextOnHashChain);
        HIDWORD(v69) = this->name.str;
        HIDWORD(v67) = v66;
        v70 = va::va(
                this: &v89,
                fmt: "headTrackJoints for '%s' are not in hierarchy order.\n"
                " '%s' is not a child of '%s'.\n"
                " Head tracking will be disabled.",
                a3: v69,
                a4: v67,
                a5: v68,
                a6: v73,
                a7: v74,
                a8: v75,
                a9: v76,
                a10: v77,
                a11: v78);
        strncpy(dest: idException::error, source: v70->buffer, count: 0x800u);
        BYTE2(v79.trackedMemory) = HIBYTE(v79.__vftable);
        CxxThrowException(
          pExceptionObject: (char *)&v79.trackedMemory + 2,
          pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
      }
    }
    if ( LOBYTE(v79.timestamp) == 0 || LOBYTE(v79.timestamp) == 2 )
    {
      if ( v47 != nullptr )
      {
        for ( n = 0; n < (int)v79.data; ++n )
          ;
        idMem::Free(this: &mem, ptr: v47, align: ALIGN_16);
      }
      *((_DWORD *)&v79.idResource + 8) = 0;
      v79.data = nullptr;
    }
    v79.defaultAnim = nullptr;
    idStr::FreeData(this: &v85);
    idStr::FreeData(this: &v86);
    v7 = v83;
    ++v12;
  }
  if ( (LOBYTE(v79.staleCount) == 0 || LOBYTE(v79.staleCount) == 2) && resourceListPtr != nullptr )
    idMem::Free(this: &mem, ptr: resourceListPtr, align: ALIGN_16);
}


// ========================================================================
// $M242938_0
// EA  : 0x82815A9C
// RVA : 0x00815A9C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void *_M242938_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4576;
  idLib::Warning(fmt: idException::error);
  idList<idDeclMD6::idHeadTrackGroup,5>::RemoveIndexFast(
    this: (idList<idDeclMD6::idHeadTrackGroup,5> *)(*(_DWORD *)(v1 + 4596) + 508),
    index: *(_DWORD *)(*(_DWORD *)(v1 + 4596) + 512) - 1);
  return &_LN501;
}


// ========================================================================
// $LN380
// EA  : 0x82815AE4
// RVA : 0x00815AE4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _LN380()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4576 + 96));
}


// ========================================================================
// __unwind$242131
// EA  : 0x82815B0C
// RVA : 0x00815B0C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_242131()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 224));
}


// ========================================================================
// __unwind$242132
// EA  : 0x82815B34
// RVA : 0x00815B34
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_242132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 192));
}


// ========================================================================
// __unwind$242133
// EA  : 0x82815B5C
// RVA : 0x00815B5C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_242133()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 256));
}


// ========================================================================
// __unwind$242134
// EA  : 0x82815B84
// RVA : 0x00815B84
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_242134()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 160));
}


// ========================================================================
// __unwind$242135
// EA  : 0x82815BAC
// RVA : 0x00815BAC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_242135()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4576 + 112));
}


// ========================================================================
// ??0idAnimEvents@@QAA@XZ
// EA  : 0x82815D70
// RVA : 0x00815D70
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idAnimEvents *__fastcall idAnimEvents::idAnimEvents(idAnimEvents *this)
{
  this->__vftable = (idAnimEvents_vtbl *)&idAnimEvents::`vftable';
  this->list.granularity = 0;
  this->list.memTag = 28;
  this->list.listStatic = 0;
  this->list.list = nullptr;
  this->list.size = 0;
  this->list.num = 0;
  this->hashIndex.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->hashIndex, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$243026
// EA  : 0x82815DF8
// RVA : 0x00815DF8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243026()
{
  int v0; // r12

  idList<idAnimEvents::animEventInfo_t,28>::~idList<idAnimEvents::animEventInfo_t,28>(this: (idList<idAnimEvents::animEventInfo_t,28> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??1idAnimEvents@@UAA@XZ
// EA  : 0x82815E30
// RVA : 0x00815E30
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimEvents::~idAnimEvents(idAnimEvents *this)
{
  idHashIndex *p_hashIndex; // r28
  idAnimEvents::animEventInfo_t *list; // r3
  idAnimEvents::animEventInfo_t *v4; // r3

  this->__vftable = (idAnimEvents_vtbl *)&idAnimEvents::`vftable';
  p_hashIndex = &this->hashIndex;
  idHashIndex::Free(this: &this->hashIndex);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    list = this->list.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimEvents::animEventInfo_t>(ptr: list, num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
  idHashIndex::Free(this: p_hashIndex);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    v4 = this->list.list;
    if ( v4 != nullptr )
      idListArrayDelete<idAnimEvents::animEventInfo_t>(ptr: v4, num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// __unwind$243062
// EA  : 0x82815EDC
// RVA : 0x00815EDC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243062()
{
  int v0; // r12

  idList<idAnimEvents::animEventInfo_t,28>::~idList<idAnimEvents::animEventInfo_t,28>(this: (idList<idAnimEvents::animEventInfo_t,28> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$243063
// EA  : 0x82815F08
// RVA : 0x00815F08
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243063()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ??0idDeclMD6@@QAA@XZ
// EA  : 0x82815F40
// RVA : 0x00815F40
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idDeclMD6 *__fastcall idDeclMD6::idDeclMD6(idDeclMD6 *this)
{
  int *p_allocedAndFlag; // r28
  int i; // r27
  _BYTE *v4; // r11
  idEyeInfoCollection v6[11]; // [sp+50h] [-E0h] BYREF

  idDecl::idDecl(this: &this->idDecl);
  this->config = nullptr;
  this->__vftable = (idDeclMD6_vtbl *)&idDeclMD6::`vftable';
  this->model = nullptr;
  this->parent.allocedAndFlag = 20;
  this->parent.data = this->parent.baseBuffer;
  this->parent.len = 0;
  this->parent.baseBuffer[0] = 0;
  this->parentDecl = nullptr;
  this->declsToIncludeAnimDataFrom.list = nullptr;
  this->declsToIncludeAnimDataFrom.granularity = 0;
  this->declsToIncludeAnimDataFrom.memTag = 5;
  this->declsToIncludeAnimDataFrom.listStatic = 0;
  this->declsToIncludeAnimDataFrom.size = 0;
  this->declsToIncludeAnimDataFrom.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declsToIncludeAnimDataFrom);
  this->numLoadErrors = 0;
  idJointGroupCollection::idJointGroupCollection(this: &this->jointGroupCollection);
  idPropsCollection::idPropsCollection(this: &this->props);
  idAnimEvents::idAnimEvents(this: &this->animEvents);
  idEyeInfoCollection::idEyeInfoCollection(this: &this->eyeInfoCollection);
  this->userProps.granularity = 0;
  this->userProps.memTag = 19;
  this->userProps.listStatic = 0;
  this->userProps.list = nullptr;
  this->userProps.size = 0;
  this->userProps.num = 0;
  this->aliases.granularity = 0;
  *(_DWORD *)&v6[0].curHandle = &this->aliases;
  this->aliases.memTag = 19;
  this->aliases.listStatic = 0;
  this->aliases.list = nullptr;
  this->aliases.size = 0;
  this->aliases.num = 0;
  this->aliasHash.memTag = TAG_MD6;
  idHashIndex::InternalInit(this: &this->aliasHash, initialHashSize: 128, initialIndexSize: 128);
  this->curAliasHandle = 0;
  this->headTrackGroups.granularity = 0;
  this->headTrackGroups.memTag = 5;
  this->headTrackGroups.listStatic = 0;
  this->headTrackGroups.list = nullptr;
  this->headTrackGroups.size = 0;
  this->headTrackGroups.num = 0;
  *(_DWORD *)&v6[0].curHandle = &this->headTrackGroups;
  `eh vector constructor iterator'(
    ptr: this->meshKitGroups,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idList<idPair<idStr,idList<int,19>>,19>::idList<idPair<idStr,idList<int,19>>,19>,
    pDtor: (void (__fastcall *)(void *))idList<idPair<idStr,idList<int,19>>,19>::~idList<idPair<idStr,idList<int,19>>,19>);
  `eh vector constructor iterator'(
    ptr: this->meshKitDefault,
    size: 0x20u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->morphVertices = nullptr;
  this->morphDefList.granularity = 0;
  this->morphDefList.memTag = 115;
  this->morphDefList.listStatic = 0;
  this->morphDefList.list = nullptr;
  this->morphDefList.size = 0;
  this->morphDefList.num = 0;
  this->calcRefBoundsFromJoints = false;
  this->wrinkleMapRegionExpressions.granularity = 0;
  this->wrinkleMapRegionExpressions.memTag = 5;
  this->wrinkleMapRegionExpressions.listStatic = 0;
  this->wrinkleMapRegionExpressions.list = nullptr;
  this->wrinkleMapRegionExpressions.size = 0;
  this->wrinkleMapRegionExpressions.num = 0;
  this->modelCaps = 0;
  this->userChannelWeightGroupOverride = 0;
  *(_DWORD *)&v6[0].curHandle = &this->baseUserChannelAlias;
  this->attachmentOverrideScale = -1.0;
  this->baseUserChannelAlias.value = -1;
  this->userChannelToAnimationAliasMap.list = nullptr;
  this->userChannelToAnimationAliasMap.granularity = 0;
  this->userChannelToAnimationAliasMap.memTag = 19;
  this->userChannelToAnimationAliasMap.listStatic = 0;
  this->userChannelToAnimationAliasMap.size = 0;
  this->userChannelToAnimationAliasMap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToAnimationAliasMap);
  this->userChannelToAnimationAliasOverrides.list = nullptr;
  this->userChannelToAnimationAliasOverrides.granularity = 0;
  this->userChannelToAnimationAliasOverrides.memTag = 19;
  this->userChannelToAnimationAliasOverrides.listStatic = 0;
  this->userChannelToAnimationAliasOverrides.size = 0;
  this->userChannelToAnimationAliasOverrides.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToAnimationAliasOverrides);
  this->aliasHash.granularity = 128;
  this->config = (idMD6Blend::configInfo_t *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\engine\\models\\skeletalanimation\\DeclMD6.cpp(864) : TAG_MD6_MISC",
                                               size: 0x10u,
                                               tag: TAG_MD6_MISC,
                                               zeroBuffer: true,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
  *(_DWORD *)&v6[0].curHandle = &this->referenceBounds;
  this->referenceBounds.b[0].z = 1.0e30;
  this->referenceBounds.b[0].y = 1.0e30;
  this->referenceBounds.b[0].x = 1.0e30;
  this->referenceBounds.b[1].z = -1.0e30;
  this->referenceBounds.b[1].y = -1.0e30;
  this->referenceBounds.b[1].x = -1.0e30;
  idEyeInfo::idEyeInfo(this: (idEyeInfo *)&v6[0].eyeInfos.granularity);
  idStr::operator=(this: (idStr *)&v6[0].eyeInfos.granularity, text: idEyeInfoCollection::DEFAULT_NAME);
  idEyeInfoCollection::AddEyeInfo(
    this: v6,
    result: (idHandle<unsigned short,enum invalidEyeInfo_t,65535> *)&this->eyeInfoCollection,
    info: (const idEyeInfo *)&v6[0].eyeInfos.granularity);
  p_allocedAndFlag = &this->meshKitDefault[0].allocedAndFlag;
  for ( i = 3; i != 0; --i )
  {
    if ( *p_allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: (idStr *)(p_allocedAndFlag - 2));
      *p_allocedAndFlag = 20;
      *(p_allocedAndFlag - 1) = (int)(p_allocedAndFlag + 1);
      *(p_allocedAndFlag - 2) = 0;
      *((_BYTE *)p_allocedAndFlag + 4) = 0;
    }
    else
    {
      v4 = (_BYTE *)*(p_allocedAndFlag - 1);
      *(p_allocedAndFlag - 2) = 0;
      *v4 = 0;
    }
    p_allocedAndFlag += 8;
  }
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&v6[0].eyeInfos.granularity);
  return this;
}


// ========================================================================
// __unwind$243113
// EA  : 0x82816244
// RVA : 0x00816244
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243113()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 304 + 324));
}


// ========================================================================
// __unwind$243114
// EA  : 0x8281626C
// RVA : 0x0081626C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243114()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 304 + 324) + 64));
}


// ========================================================================
// __unwind$243115
// EA  : 0x82816298
// RVA : 0x00816298
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243115()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 304 + 324) + 100));
}


// ========================================================================
// __unwind$243116
// EA  : 0x828162C4
// RVA : 0x008162C4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243116()
{
  int v0; // r12

  idJointGroupCollection::~idJointGroupCollection(this: (idJointGroupCollection *)(*(_DWORD *)(v0 - 304 + 324) + 144));
}


// ========================================================================
// __unwind$243117
// EA  : 0x828162F0
// RVA : 0x008162F0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243117()
{
  int v0; // r12

  idPropsCollection::~idPropsCollection(this: (idPropsCollection *)(*(_DWORD *)(v0 - 304 + 324) + 352));
}


// ========================================================================
// __unwind$243118
// EA  : 0x8281631C
// RVA : 0x0081631C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243118()
{
  int v0; // r12

  idAnimEvents::~idAnimEvents(this: (idAnimEvents *)(*(_DWORD *)(v0 - 304 + 324) + 368));
}


// ========================================================================
// __unwind$243119
// EA  : 0x82816348
// RVA : 0x00816348
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243119()
{
  int v0; // r12

  idEyeInfoCollection::~idEyeInfoCollection(this: (idEyeInfoCollection *)(*(_DWORD *)(v0 - 304 + 324) + 420));
}


// ========================================================================
// __unwind$243120
// EA  : 0x82816374
// RVA : 0x00816374
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243120()
{
  int v0; // r12

  idList<idVarArgs<6>,19>::~idList<idVarArgs<6>,19>(this: (idList<idVarArgs<6>,19> *)(*(_DWORD *)(v0 - 304 + 324) + 440));
}


// ========================================================================
// __unwind$243121
// EA  : 0x828163A0
// RVA : 0x008163A0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243121()
{
  int v0; // r12

  idList<idMD6Alias,19>::~idList<idMD6Alias,19>(this: (idList<idMD6Alias,19> *)(*(_DWORD *)(v0 - 304 + 324) + 456));
}


// ========================================================================
// __unwind$243122
// EA  : 0x828163CC
// RVA : 0x008163CC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243122()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 304 + 324) + 472));
}


// ========================================================================
// __unwind$243123
// EA  : 0x828163F8
// RVA : 0x008163F8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243123()
{
  int v0; // r12

  idList<idDeclMD6::idHeadTrackGroup,5>::Clear(this: (idList<idDeclMD6::idHeadTrackGroup,5> *)(*(_DWORD *)(v0 - 304 + 324)
                                                                                             + 508));
}


// ========================================================================
// __unwind$243124
// EA  : 0x82816424
// RVA : 0x00816424
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243124()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 304 + 324) + 524),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idPair<idStr,idList<int,19>>,19>::~idList<idPair<idStr,idList<int,19>>,19>);
}


// ========================================================================
// __unwind$243125
// EA  : 0x82816460
// RVA : 0x00816460
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243125()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 304 + 324) + 572),
    size: 0x20u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$243126
// EA  : 0x8281649C
// RVA : 0x0081649C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243126()
{
  int v0; // r12

  idList<idMorphDef,115>::Clear(this: (idList<idMorphDef,115> *)(*(_DWORD *)(v0 - 304 + 324) + 672));
}


// ========================================================================
// __unwind$243127
// EA  : 0x828164C8
// RVA : 0x008164C8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243127()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 304 + 324) + 692));
}


// ========================================================================
// __unwind$243128
// EA  : 0x828164F4
// RVA : 0x008164F4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243128()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 304 + 324) + 724));
}


// ========================================================================
// __unwind$243129
// EA  : 0x82816520
// RVA : 0x00816520
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243129()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 304 + 324) + 740));
}


// ========================================================================
// __unwind$243130
// EA  : 0x8281654C
// RVA : 0x0081654C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243130()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 96));
}


// ========================================================================
// ??1idDeclMD6@@UAA@XZ
// EA  : 0x82816590
// RVA : 0x00816590
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::~idDeclMD6(idDeclMD6 *this)
{
  char *list; // r3
  idStr *v3; // r3
  char *v4; // r3
  char *v5; // r3
  char *v6; // r3
  char *v7; // r3

  this->__vftable = (idDeclMD6_vtbl *)&idDeclMD6::`vftable';
  idMem::Free(this: &mem, ptr: this->config, align: ALIGN_16);
  animation->UnregisterAliases(this: animation, a2: this);
  if ( this->aliases.listStatic == 0 || this->aliases.listStatic == 2 )
  {
    list = (char *)this->aliases.list;
    if ( list != nullptr )
      idListArrayDelete<idMD6Alias>(ptr: list, num: this->aliases.size);
    this->aliases.list = nullptr;
    this->aliases.size = 0;
  }
  this->aliases.num = 0;
  idHashIndex::Clear(this: &this->aliasHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToAnimationAliasOverrides);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToAnimationAliasMap);
  if ( this->wrinkleMapRegionExpressions.listStatic == 0 || this->wrinkleMapRegionExpressions.listStatic == 2 )
  {
    v3 = this->wrinkleMapRegionExpressions.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->wrinkleMapRegionExpressions.size);
    this->wrinkleMapRegionExpressions.list = nullptr;
    this->wrinkleMapRegionExpressions.size = 0;
  }
  this->wrinkleMapRegionExpressions.num = 0;
  if ( this->morphDefList.listStatic == 0 || this->morphDefList.listStatic == 2 )
  {
    v4 = (char *)this->morphDefList.list;
    if ( v4 != nullptr )
      idListArrayDelete<idMorphDef>(ptr: v4, num: this->morphDefList.size);
    this->morphDefList.list = nullptr;
    this->morphDefList.size = 0;
  }
  this->morphDefList.num = 0;
  `eh vector destructor iterator'(
    ptr: this->meshKitDefault,
    size: 0x20u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  `eh vector destructor iterator'(
    ptr: this->meshKitGroups,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idPair<idStr,idList<int,19>>,19>::~idList<idPair<idStr,idList<int,19>>,19>);
  if ( this->headTrackGroups.listStatic == 0 || this->headTrackGroups.listStatic == 2 )
  {
    v5 = (char *)this->headTrackGroups.list;
    if ( v5 != nullptr )
      idListArrayDelete<idDeclMD6::idHeadTrackGroup>(ptr: v5, num: this->headTrackGroups.size);
    this->headTrackGroups.list = nullptr;
    this->headTrackGroups.size = 0;
  }
  this->headTrackGroups.num = 0;
  idHashIndex::Free(this: &this->aliasHash);
  if ( this->aliases.listStatic == 0 || this->aliases.listStatic == 2 )
  {
    v6 = (char *)this->aliases.list;
    if ( v6 != nullptr )
      idListArrayDelete<idMD6Alias>(ptr: v6, num: this->aliases.size);
    this->aliases.list = nullptr;
    this->aliases.size = 0;
  }
  this->aliases.num = 0;
  if ( this->userProps.listStatic == 0 || this->userProps.listStatic == 2 )
  {
    v7 = (char *)this->userProps.list;
    if ( v7 != nullptr )
      idListArrayDelete<idVarArgs<6>>(ptr: v7, num: this->userProps.size);
    this->userProps.list = nullptr;
    this->userProps.size = 0;
  }
  this->userProps.num = 0;
  idEyeInfoCollection::~idEyeInfoCollection(this: &this->eyeInfoCollection);
  idAnimEvents::~idAnimEvents(this: &this->animEvents);
  idPropsCollection::~idPropsCollection(this: &this->props);
  idJointGroupCollection::~idJointGroupCollection(this: &this->jointGroupCollection);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declsToIncludeAnimDataFrom);
  idStr::FreeData(this: &this->parent);
  idDecl::~idDecl(this: &this->idDecl);
}


// ========================================================================
// __unwind$243463
// EA  : 0x828167B4
// RVA : 0x008167B4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243463()
{
  int v0; // r12

  idDecl::~idDecl(this: *(idDecl **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$243464
// EA  : 0x828167DC
// RVA : 0x008167DC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243464()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$243465
// EA  : 0x82816808
// RVA : 0x00816808
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243465()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 100));
}


// ========================================================================
// __unwind$243466
// EA  : 0x82816834
// RVA : 0x00816834
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243466()
{
  int v0; // r12

  idJointGroupCollection::~idJointGroupCollection(this: (idJointGroupCollection *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}


// ========================================================================
// __unwind$243467
// EA  : 0x82816860
// RVA : 0x00816860
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243467()
{
  int v0; // r12

  idPropsCollection::~idPropsCollection(this: (idPropsCollection *)(*(_DWORD *)(v0 - 128 + 148) + 352));
}


// ========================================================================
// __unwind$243468
// EA  : 0x8281688C
// RVA : 0x0081688C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243468()
{
  int v0; // r12

  idAnimEvents::~idAnimEvents(this: (idAnimEvents *)(*(_DWORD *)(v0 - 128 + 148) + 368));
}


// ========================================================================
// __unwind$243469
// EA  : 0x828168B8
// RVA : 0x008168B8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243469()
{
  int v0; // r12

  idEyeInfoCollection::~idEyeInfoCollection(this: (idEyeInfoCollection *)(*(_DWORD *)(v0 - 128 + 148) + 420));
}


// ========================================================================
// __unwind$243470
// EA  : 0x828168E4
// RVA : 0x008168E4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243470()
{
  int v0; // r12

  idList<idVarArgs<6>,19>::~idList<idVarArgs<6>,19>(this: (idList<idVarArgs<6>,19> *)(*(_DWORD *)(v0 - 128 + 148) + 440));
}


// ========================================================================
// __unwind$243471
// EA  : 0x82816910
// RVA : 0x00816910
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243471()
{
  int v0; // r12

  idList<idMD6Alias,19>::~idList<idMD6Alias,19>(this: (idList<idMD6Alias,19> *)(*(_DWORD *)(v0 - 128 + 148) + 456));
}


// ========================================================================
// __unwind$243472
// EA  : 0x8281693C
// RVA : 0x0081693C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243472()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$243473
// EA  : 0x82816968
// RVA : 0x00816968
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243473()
{
  int v0; // r12

  idList<idDeclMD6::idHeadTrackGroup,5>::Clear(this: (idList<idDeclMD6::idHeadTrackGroup,5> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 508));
}


// ========================================================================
// __unwind$243474
// EA  : 0x82816994
// RVA : 0x00816994
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243474()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 524),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idPair<idStr,idList<int,19>>,19>::~idList<idPair<idStr,idList<int,19>>,19>);
}


// ========================================================================
// __unwind$243475
// EA  : 0x828169D0
// RVA : 0x008169D0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243475()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 572),
    size: 0x20u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$243476
// EA  : 0x82816A0C
// RVA : 0x00816A0C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243476()
{
  int v0; // r12

  idList<idMorphDef,115>::Clear(this: (idList<idMorphDef,115> *)(*(_DWORD *)(v0 - 128 + 148) + 672));
}


// ========================================================================
// __unwind$243477
// EA  : 0x82816A38
// RVA : 0x00816A38
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243477()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 692));
}


// ========================================================================
// __unwind$243478
// EA  : 0x82816A64
// RVA : 0x00816A64
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243478()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 724));
}


// ========================================================================
// __unwind$243479
// EA  : 0x82816A90
// RVA : 0x00816A90
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243479()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 740));
}


// ========================================================================
// ?Parse@idAnimEvents@@QAAXPBVidDeclMD6@@AAVidParser@@AAH@Z
// EA  : 0x82816CC0
// RVA : 0x00816CC0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idAnimEvents::Parse(idAnimEvents *this, const idDeclMD6 *decl, idParser *src, int *loadErrors)
{
  idList<idAnimEvents::animEventInfo_t,28> *p_list; // r30
  int num; // r25
  int v10; // r11
  int size; // r10
  idAnimEvents::animEventInfo_t *list; // r10
  int v13; // r29
  bool v14; // r26
  int v15; // r11
  int v16; // r10
  int v17; // r9
  idMD6AnimEvent *v18; // r3
  idHashIndex *p_hashIndex; // r30
  idAtomicString v20; // r29
  int indexSize; // r11
  int v22; // r6
  idToken v23; // [sp+60h] [-130h] BYREF
  idToken v24; // [sp+B0h] [-E0h] BYREF

  v23.len = 0;
  v23.allocedAndFlag = 20;
  v23.floatvalue = -3.4028235e38;
  v23.data = v23.baseBuffer;
  v23.baseBuffer[0] = 0;
  v23.intvalue = 0;
  memset(&v23.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v23);
  while ( idParser::ReadToken(this: src, token: &v23) )
  {
    if ( v23.type == 5 && v23.subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v23.data, s2: "anim") != 0 )
    {
      idParser::Error(this: src, str: "Unknown token '%s' while reading 'animEvents' block.", v23.data);
    }
    else
    {
      v24.floatvalue = -3.4028235e38;
      v24.allocedAndFlag = 20;
      v24.data = v24.baseBuffer;
      v24.len = 0;
      v24.baseBuffer[0] = 0;
      v24.intvalue = 0;
      memset(&v24.whiteSpaceStart_p, 0, 12);
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v24);
      idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v23);
      idStr::MakeNameCanonical(this: &v24);
      p_list = &this->list;
      num = this->list.num;
      idList<idAnimEvents::animEventInfo_t,28>::PreAllocateWithGranularity(this: &this->list, newSize: num + 1);
      v10 = this->list.num;
      size = this->list.size;
      if ( v10 >= size )
      {
        v13 = (int)&p_list->list[size - 1];
      }
      else
      {
        list = p_list->list;
        this->list.num = v10 + 1;
        v13 = (int)&list[v10];
      }
      idAtomicString::Set(this: (idAtomicString *)v13, str_: v24.data);
      v14 = idLib::PushWarningInfo(type: "AnimEvent", name: *(const char **)v13);
      while ( idParser::ReadToken(this: src, token: &v23) )
      {
        if ( v23.type == 5 && v23.subtype == 47 )
          break;
        if ( idStr::Cmp(s1: v23.data, s2: "event") != 0 )
        {
          idParser::Error(this: src, str: "Unknown token '%s' while reading 'anim' block.", v23.data);
        }
        else
        {
          idList<idMD6AnimEvent,28>::PreAllocateWithGranularity(
            this: (idList<idMD6AnimEvent,28> *)(v13 + 4),
            newSize: *(_DWORD *)(v13 + 8) + 1);
          v15 = *(_DWORD *)(v13 + 8);
          v16 = *(_DWORD *)(v13 + 12);
          v17 = *(_DWORD *)(v13 + 4);
          if ( v15 >= v16 )
          {
            v18 = (idMD6AnimEvent *)(44 * v16 + v17 - 44);
          }
          else
          {
            v18 = (idMD6AnimEvent *)(44 * v15 + v17);
            *(_DWORD *)(v13 + 8) = v15 + 1;
          }
          if ( !idMD6AnimEvent::Parse(this: v18, md6: decl, src, loadErrors) )
            idList<idMD6AnimEvent,28>::RemoveIndex(
              this: (idList<idMD6AnimEvent,28> *)(v13 + 4),
              index: *(_DWORD *)(v13 + 8) - 1);
        }
      }
      if ( v14 )
        idLib::PopWarningInfo();
      p_hashIndex = &this->hashIndex;
      v20.str = *(const char **)v13;
      indexSize = this->hashIndex.indexSize;
      if ( this->hashIndex.hash == idHashIndex::INVALID_INDEX )
      {
        if ( num >= indexSize )
          indexSize = num + 1;
        idHashIndex::Allocate(this: &this->hashIndex, newHashSize: this->hashIndex.hashSize, newIndexSize: indexSize);
      }
      else if ( num >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->hashIndex, newIndexSize: num + 1);
      }
      v22 = this->hashIndex.hashMask & (unsigned int)v20.str;
      this->hashIndex.indexChain[num] = p_hashIndex->hash[v22];
      p_hashIndex->hash[v22] = num;
      idStr::FreeData(this: &v24);
    }
  }
  idStr::FreeData(this: &v23);
}


// ========================================================================
// __unwind$243759_0
// EA  : 0x8281702C
// RVA : 0x0081702C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243759_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$243760
// EA  : 0x82817054
// RVA : 0x00817054
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243760()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$243761
// EA  : 0x8281707C
// RVA : 0x0081707C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_243761()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 400 + 80));
}


// ========================================================================
// ?Parse@idDeclMD6@@UAAXAAVidParser@@@Z
// EA  : 0x82817110
// RVA : 0x00817110
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall idDeclMD6::Parse(idDeclMD6 *this, idClientGame *src)
{
  char v4; // r15
  idParser *v5; // r29
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int staleCount; // r29
  __int64 v10; // r10
  __int64 v11; // r8
  char *v12; // r4
  const idDeclMD6 *v13; // r11
  __int64 v14; // r6
  va *v15; // r3
  const idMD6Model *v16; // r11
  const idMD6Skel *v17; // r3
  const idMD6Model *v18; // r11
  idMD6SkelData *v19; // r9
  const idMD6Skel *v20; // r8
  int value; // r6
  int v22; // r30
  idMD6Blend::configInfo_t *config; // r10
  idMD6Blend::configInfo_t *v24; // r9
  char **p_morphDefList; // r30
  __int64 v26; // r8
  __int64 v27; // r6
  const idMD6Model *v28; // r3
  _DWORD *v29; // r11
  __int64 v30; // r10
  va *v31; // r3
  const idMD6Model *model; // r10
  const idDeclMD6 *parentDecl; // r11
  const idMD6Model *v34; // r11
  const idMD6Skel *skeleton; // r4
  const idMD6Skel *v36; // r3
  idMD6SkelData *data; // r11
  idMD6SkelData *v38; // r10
  const char *v39; // r6
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r10
  __int64 v43; // r8
  int v44; // r11
  const idDeclMD6 *v45; // r30
  __int64 v46; // r6
  va *v47; // r3
  __int64 v48; // r6
  va *v49; // r3
  const idMD6Model *v50; // r11
  const idMD6Skel *v51; // r27
  int i; // r28
  const idDeclMD6 *includeDecl; // r29
  const idMD6Model *v54; // r30
  const idMD6Skel *v55; // r4
  const char *str; // r5
  const idMD6Model *v57; // r10
  idMD6Blend::configInfo_t *v58; // r10
  double v59; // fp0
  double v60; // fp0
  int j; // r30
  const idDeclMD6 *v62; // r11
  va *v63; // r3
  idParser *v64; // r28
  idList<idJointGroup *,30> *v65; // r11
  int k; // ctr
  const idDeclMD6 *v67; // r24
  idDeclMD6::includeDecl_t *list; // r25
  int v69; // r26
  idDeclMD6::includeDecl_t *v70; // r27
  const idVarArgs<6> *v71; // r29
  char v72; // r28
  int m; // r30
  idVarArgs<6> *v74; // r11
  unsigned int v75; // r10
  idBounds *p_defaultBounds; // r6
  const idDeclMD6 *v77; // r5
  idDeclMD6_vtbl *v78; // r19
  int n; // r11
  idParser *v80; // r29
  const idDeclMD6 *v81; // r11
  const idDeclMD6 *v82; // r11
  char **v83; // r28
  const char *trackedMemory; // r25
  size_t v85; // r30
  int v86; // r4
  int v87; // r11
  const char *v88; // r4
  int v89; // r28
  int ii; // r24
  char *v91; // r11
  idList<idPair<idStr,idList<int,19> >,19> *v92; // r30
  int v93; // r11
  int v94; // r4
  char *v95; // r11
  int *v96; // r30
  int v97; // r11
  int v98; // r10
  int v99; // r9
  int v100; // r26
  unsigned int v101; // r11
  size_t v102; // r30
  int v103; // r4
  int v104; // r11
  bool v105; // zf
  float v106; // r25
  float z; // r28
  int mm; // r29
  int v109; // r30
  char v110; // r27
  const idMD6Model *v111; // r11
  float y; // r29
  int nn; // r30
  size_t v114; // r29
  char *v115; // r11
  int v116; // r4
  idStr *v117; // r30
  unsigned int v118; // r11
  int v119; // r11
  char *v120; // r11
  int *v121; // r30
  int v122; // r11
  int v123; // r10
  int v124; // r9
  int v125; // r27
  unsigned int v126; // r11
  size_t v127; // r30
  int v128; // r4
  int v129; // r11
  int v130; // r25
  const char **size; // r28
  int jj; // r29
  int v133; // r30
  char v134; // r26
  const idMD6Model *v135; // r11
  float x; // r29
  int kk; // r30
  idMem *v138; // r26
  idStr *v139; // r29
  int v140; // r28
  int i1; // r30
  idJointGroup **v142; // r4
  int v143; // r11
  idStr *v144; // r30
  size_t numLoadErrors; // r29
  int v146; // r4
  unsigned int allocedAndFlag; // r11
  int v148; // r11
  const idDeclMD6 *v149; // r11
  idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> > *v150; // r4
  int i2; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v152; // r4
  int i3; // r11
  int v154; // r30
  char *v155; // r11
  idJointGroup **v156; // r10
  char v157; // r9
  int v158; // r30
  char *v159; // r11
  idJointGroup **v160; // r10
  char v161; // r9
  idList<idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> >,19> *p_userChannelToAnimationAliasOverrides; // r30
  int num; // r11
  int v164; // r10
  idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> > *v165; // r10
  idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> > *v166; // r11
  const enumTypeInfo_t *EnumInfo; // r29
  int i4; // r28
  const idDeclMD6 *v169; // r10
  int v170; // r8
  int userChannelWeightGroupOverride; // r11
  char v172; // r9
  idDeclMD6 *v173; // r3
  idMorphVertices *v174; // r3
  float *p_x; // r9
  float *v176; // r8
  int v177; // [sp+8h] [-1408h]
  int v178; // [sp+Ch] [-1404h]
  int v179; // [sp+10h] [-1400h]
  int v180; // [sp+14h] [-13FCh]
  int v181; // [sp+18h] [-13F8h]
  int v182; // [sp+1Ch] [-13F4h]
  _DWORD *v183; // [sp+50h] [-13C0h] BYREF
  idDeclMD6 v184; // [sp+54h] [-13BCh] BYREF
  float v185; // [sp+348h] [-10C8h]
  int v186; // [sp+34Ch] [-10C4h]
  int v187; // [sp+350h] [-10C0h]
  int v188; // [sp+354h] [-10BCh]
  va v189; // [sp+360h] [-10B0h] BYREF

  v184.declsToIncludeAnimDataFrom.list = (idDeclMD6::includeDecl_t *)idParser::GetFlags(this: src);
  idParser::SetFlags(this: (idParser *)src, flags: (int)v184.declsToIncludeAnimDataFrom.list | 0x40000);
  this->FreeData(this);
  v184.wrinkleMapRegionExpressions.size = 0;
  LODWORD(v184.attachmentOverrideScale) = 20;
  *(_DWORD *)&v184.wrinkleMapRegionExpressions.granularity = &v184.modelCaps;
  v185 = -3.4028235e38;
  HIBYTE(v184.modelCaps) = 0;
  *(_DWORD *)&v184.userChannelToAnimationAliasOverrides.granularity = 0;
  v186 = 0;
  v187 = 0;
  v188 = 0;
  *(float *)&v184.morphDefList.num = -3.4028235e38;
  *(_DWORD *)&v184.meshKitDefault[1].baseBuffer[12] = 20;
  *(_DWORD *)&v184.meshKitDefault[1].baseBuffer[8] = &v184.meshKitDefault[1].baseBuffer[16];
  *(_DWORD *)&v184.meshKitDefault[1].baseBuffer[4] = 0;
  v184.meshKitDefault[1].baseBuffer[16] = 0;
  v184.morphDefList.list = nullptr;
  memset(&v184.morphDefList.size, 0, 12);
  *(float *)&v184.parent.baseBuffer[8] = -3.4028235e38;
  v184.textSource = (char *)20;
  *((_DWORD *)&v184.idResource + 8) = &v184.textLength;
  v184.staleCount = 0;
  HIBYTE(v184.textLength) = 0;
  *(_DWORD *)&v184.parent.baseBuffer[4] = 0;
  memset(&v184.parent.baseBuffer[12], 0, 12);
  idParser::ExpectTokenString(this: (idParser *)src, string: "init");
  idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
  v4 = 0;
LABEL_2:
  v5 = (idParser *)src;
  while ( idParser::ReadToken(this: v5, token: (idToken *)&v184.staleCount)
       && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
  {
    if ( idStr::Icmp(s1: *((const char **)&v184.idResource + 8), s2: "inherit") != 0 )
    {
      if ( idStr::Icmp(s1: *((const char **)&v184.idResource + 8), s2: "mesh") != 0 )
      {
_LN1737:
        if ( idStr::Icmp(s1: *((const char **)&v184.idResource + 8), s2: "offset") != 0 )
        {
          if ( idStr::Icmp(s1: *((const char **)&v184.idResource + 8), s2: "calcRefBoundsFromJoints") != 0 )
          {
            if ( idStr::Icmp(s1: *((const char **)&v184.idResource + 8), s2: "includeAnimDataFrom") != 0 )
            {
              LODWORD(v48) = this->name.str;
              HIDWORD(v48) = *((_DWORD *)&v184.idResource + 8);
              v49 = va::va(
                      this: &v189,
                      fmt: "Unknown token '%s' in 'init' block in md6Def '%s'",
                      a3: v48,
                      a4: v41,
                      a5: v40,
                      a6: v177,
                      a7: v178,
                      a8: v179,
                      a9: v180,
                      a10: v181,
                      a11: v182);
              idParser::Error(this: v5, str: v49->buffer);
            }
            else
            {
              idParser::ExpectTokenType(this: v5, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
              if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: &byte_8200D768) != 0 )
              {
                v44 = *((_DWORD *)&v184.idResource + 8);
                if ( *((_DWORD *)&v184.idResource + 8) != 0 )
                {
                  v45 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclMD6::resourceList,
                                             name: *((const char **)&v184.idResource + 8),
                                             makeDefault: false);
                  if ( v45 != nullptr )
                    goto LABEL_58;
                  v44 = *((_DWORD *)&v184.idResource + 8);
                }
                else
                {
                  v45 = nullptr;
                }
                LODWORD(v46) = this->name.str;
                HIDWORD(v46) = v44;
                v47 = va::va(
                        this: &v189,
                        fmt: "md6Def '%s' does not exist for including animations for '%s'",
                        a3: v46,
                        a4: v43,
                        a5: v42,
                        a6: v177,
                        a7: v178,
                        a8: v179,
                        a9: v180,
                        a10: v181,
                        a11: v182);
                idParser::Error(this: v5, str: v47->buffer);
LABEL_58:
                declManager->AddDependency_2(this: declManager, a2: (idDecl *)this, a3: v45);
                idDeclMD6::IncludeAnimDataFrom(this, includeDecl: v45);
              }
            }
          }
          else
          {
            this->calcRefBoundsFromJoints = idParser::ParseBool(this: v5);
          }
        }
        else
        {
          idParser::Parse1DMatrix(this: v5, x: 3, m: this->config->visualOffset);
          v4 = 1;
        }
      }
      else
      {
        idParser::ExpectTokenType(this: v5, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
        v28 = (const idMD6Model *)idResourceList::Load(
                                    this: &idMD6Model::resourceList,
                                    name: *((char **)&v184.idResource + 8),
                                    makeDefault: true,
                                    skipStaleCheck: false);
        this->model = v28;
        if ( v28 == nullptr )
          idLib::Error(
            fmt: "Failed to load model '%s' for md6def '%s'",
            *((const char **)&v184.idResource + 8),
            this->name.str);
        v183 = &v28->skeleton->__vftable;
        v29 = v183;
        if ( v183 == nullptr )
          goto _LN1736;
        LODWORD(v30) = v183[10];
        if ( (_DWORD)v30 == 0 )
          goto _LN1736;
        HIDWORD(v30) = *(unsigned __int16 *)(v30 + 2) + 7;
        if ( (v30 & 0xFFF800000000LL) == 0 )
        {
          HIDWORD(v27) = this->name.str;
          LODWORD(v26) = WORD1(v30) & 0xFFF8;
          v31 = va::va(
                  this: &v189,
                  fmt: "Model '%s' has no joints",
                  a3: v27,
                  a4: v26,
                  a5: v30,
                  a6: v177,
                  a7: v178,
                  a8: v179,
                  a9: v180,
                  a10: v181,
                  a11: v182);
          idParser::Error(this: v5, str: v31->buffer);
        }
        model = this->model;
        if ( model != nullptr )
        {
          parentDecl = this->parentDecl;
          if ( parentDecl != nullptr )
          {
            v34 = parentDecl->model;
            if ( v34 != nullptr )
            {
              skeleton = v34->skeleton;
              v36 = model->skeleton;
              data = skeleton->data;
              v38 = v36->data;
              v183 = &v36->__vftable;
              if ( v38->parentTblCrc.value != data->parentTblCrc.value )
              {
                v183 = &v36->__vftable;
                if ( !IsJointConversionEqual(_pS1: v36, _pS2: skeleton) )
                {
                  idLib::Error(
                    fmt: "Skeleton mismatch: md6def '%s', model '%s' != md6def decl '%s', parent model '%s'",
                    this->name.str,
                    this->model->name.str,
                    this->parentDecl->name.str,
                    this->parentDecl->model->name.str);
_LN1736:
                  v183 = v29;
                  if ( v29 != nullptr )
                    v39 = "valid";
                  else
                    v39 = &byte_8200D768;
                  idLib::Error(
                    fmt: "Model '%s' for md6def '%s' does not have a %s skeleton.",
                    *((const char **)&v184.idResource + 8),
                    this->name.str,
                    v39);
                  goto _LN1737;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      idParser::ExpectTokenType(this: v5, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
      staleCount = v184.staleCount;
      idStr::EnsureAlloced(this: &this->parent, amount: v184.staleCount + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->parent.data, Src: *((const void **)&v184.idResource + 8), Size: staleCount);
      this->parent.data[staleCount] = 0;
      this->parent.len = staleCount;
      if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: &byte_8200D768) == 0 )
        goto LABEL_2;
      v12 = this->parent.data;
      if ( v12 != nullptr )
        v13 = (const idDeclMD6 *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclMD6::resourceList,
                                   name: v12,
                                   makeDefault: false);
      else
        v13 = nullptr;
      this->parentDecl = v13;
      if ( v13 != nullptr )
      {
        v5 = (idParser *)src;
      }
      else
      {
        LODWORD(v14) = this->name.str;
        HIDWORD(v14) = this->parent.data;
        v15 = va::va(
                this: &v189,
                fmt: "Parent md6Def '%s' does not exist for '%s'",
                a3: v14,
                a4: v11,
                a5: v10,
                a6: v177,
                a7: v178,
                a8: v179,
                a9: v180,
                a10: v181,
                a11: v182);
        v5 = (idParser *)src;
        idParser::Error(this: (idParser *)src, str: v15->buffer);
      }
      v16 = this->model;
      if ( v16 != nullptr )
      {
        v17 = v16->skeleton;
        v18 = this->parentDecl->model;
        v19 = v17->data;
        v183 = &v17->__vftable;
        v20 = v18->skeleton;
        value = v19->parentTblCrc.value;
        v183 = &v18->__vftable;
        if ( value != v20->data->parentTblCrc.value )
        {
          v183 = &v17->__vftable;
          if ( !IsJointConversionEqual(_pS1: v17, _pS2: v20) )
            idLib::Error(
              fmt: "Skeleton mismatch: md6def '%s', model '%s' != parent md6def '%s', parent model '%s'",
              this->name.str,
              this->model->name.str,
              this->parentDecl->name.str,
              this->parentDecl->model->name.str);
        }
      }
      declManager->AddDependency_2(this: declManager, a2: (idDecl *)this, a3: this->parentDecl);
      if ( this->model == nullptr )
        this->model = this->parentDecl->model;
      v22 = 0;
      config = this->config;
      v24 = this->parentDecl->config;
      *(_QWORD *)config->visualOffset = *(_QWORD *)v24->visualOffset;
      *(_QWORD *)&config->visualOffset[2] = *(_QWORD *)&v24->visualOffset[2];
      this->calcRefBoundsFromJoints = this->parentDecl->calcRefBoundsFromJoints;
      while ( v22 < 3 )
      {
        idStr::operator=(this: &this->meshKitDefault[v22], text: this->parentDecl->meshKitDefault[v22].data);
        ++v22;
      }
      if ( this->parentDecl->morphDefList.num > 0 )
      {
        p_morphDefList = (char **)&this->morphDefList;
        if ( this->morphDefList.listStatic == 0 || this->morphDefList.listStatic == 2 )
        {
          if ( *p_morphDefList != nullptr )
            idListArrayDelete<idMorphDef>(ptr: *p_morphDefList, num: this->morphDefList.size);
          *p_morphDefList = nullptr;
          this->morphDefList.size = 0;
        }
        this->morphDefList.num = 0;
        idList<idMorphDef,115>::Append(this: &this->morphDefList, other: &this->parentDecl->morphDefList);
      }
    }
  }
  v50 = this->model;
  if ( v50 != nullptr )
  {
    v51 = v50->skeleton;
    for ( i = 0; i < this->declsToIncludeAnimDataFrom.num; ++i )
    {
      includeDecl = this->declsToIncludeAnimDataFrom.list[i].includeDecl;
      if ( includeDecl != nullptr )
        v54 = includeDecl->model;
      else
        v54 = nullptr;
      if ( v54 != nullptr )
        v55 = v54->skeleton;
      else
        v55 = nullptr;
      if ( v55 == nullptr )
      {
        if ( includeDecl != nullptr )
          str = includeDecl->name.str;
        else
          str = "<unknown";
        idLib::Error(
          fmt: "md6Def '%s' including data from decl '%s' which does not have a valid skeleton",
          this->name.str,
          str);
      }
      LODWORD(v6) = v51->data;
      HIDWORD(v7) = v55->data->parentTblCrc.value;
      LODWORD(v8) = *(unsigned __int16 *)(v6 + 6);
      if ( (_DWORD)v8 != HIDWORD(v7) && !IsJointConversionEqual(_pS1: this->model->skeleton, _pS2: v55) )
        idLib::Error(
          fmt: "Skeleton mismatch: md6def '%s', model '%s' != md6def for included animations'%s', included animations model '%s'",
          this->name.str,
          this->model->name.str,
          includeDecl->name.str,
          v54->name.str);
      v5 = (idParser *)src;
    }
  }
  HIDWORD(v6) = this->parentDecl;
  if ( HIDWORD(v6) != 0 )
  {
    v57 = this->model;
    if ( v57 == nullptr )
      v57 = *(const idMD6Model **)(HIDWORD(v6) + 60);
    this->model = v57;
    if ( v4 != 0 )
      v58 = this->config;
    else
      v58 = *(idMD6Blend::configInfo_t **)(HIDWORD(v6) + 56);
    this->config->visualOffset[0] = v58->visualOffset[0];
    if ( v4 != 0 )
      v59 = this->config->visualOffset[1];
    else
      v59 = this->parentDecl->config->visualOffset[1];
    this->config->visualOffset[1] = v59;
    if ( v4 != 0 )
      v60 = this->config->visualOffset[2];
    else
      v60 = this->parentDecl->config->visualOffset[2];
    this->config->visualOffset[2] = v60;
    HIDWORD(v6) = this->model;
    LODWORD(v7) = this->parentDecl->model;
    if ( HIDWORD(v6) == (_DWORD)v7 )
    {
      for ( j = 0; j < 3; ++j )
        idList<idPair<idStr,idList<int,19>>,19>::operator=(
          this: &this->meshKitGroups[j],
          other: &this->parentDecl->meshKitGroups[j]);
    }
    v62 = this->parentDecl;
    LODWORD(v6) = v62->modelCaps;
    this->modelCaps = v6;
    this->attachmentOverrideScale = v62->attachmentOverrideScale;
  }
  if ( this->model == nullptr )
  {
    HIDWORD(v8) = this->name.str;
    v63 = va::va(
            this: &v189,
            fmt: "No md6model specified for md6Def '%s'",
            a3: v8,
            a4: v7,
            a5: v6,
            a6: v177,
            a7: v178,
            a8: v179,
            a9: v180,
            a10: v181,
            a11: v182);
    idParser::Error(this: v5, str: v63->buffer);
  }
  if ( idParser::CheckTokenString(this: v5, string: "modelCaps") != 0 )
  {
    idParser::ExpectTokenType(this: v5, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    while ( idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.staleCount)
         && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
    {
      if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "lipsync") != 0 )
      {
        if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "faceSetup") != 0 )
        {
          if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "moods") != 0 )
          {
            if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "gestures") != 0 )
              idParser::Error(
                this: (idParser *)src,
                str: "Unknown token '%s' in props block in md6Def '%s'",
                *((const char **)&v184.idResource + 8),
                this->name.str);
            else
              this->modelCaps |= 8u;
          }
          else
          {
            this->modelCaps |= 4u;
          }
        }
        else
        {
          this->modelCaps |= 2u;
        }
      }
      else
      {
        this->modelCaps |= 1u;
      }
    }
  }
  v64 = (idParser *)src;
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "attachmentOverrideScale") != 0 )
    this->attachmentOverrideScale = idParser::ParseFloat(this: (idParser *)src, errorFlag: nullptr);
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "userProps") != 0 )
  {
    idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    v184.name.str = (const char *)&mem;
    while ( idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.staleCount)
         && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
    {
      if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "prop") != 0 )
      {
        idParser::Error(
          this: (idParser *)src,
          str: "Unknown token '%s' in props block in md6Def '%s'",
          *((const char **)&v184.idResource + 8),
          this->name.str);
      }
      else
      {
        v184.jointGroupCollection.jointGroupsByType[5].granularity = 0;
        v65 = &v184.jointGroupCollection.jointGroupsByType[6];
        *(_WORD *)&v184.jointGroupCollection.jointGroupsByType[5].memTag = 0;
        HIWORD(v184.jointGroupCollection.jointGroupsByType[6].list) = 0;
        *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[7].granularity = 0;
        for ( k = 6; k != 0; --k )
        {
          v65 = (idList<idJointGroup *,30> *)((char *)v65 + 2);
          HIWORD(v65->list) = 0;
        }
        memset(&v184.jointGroupCollection.jointGroupsByType[6].memTag, 0, 12);
        idDeclMD6::ReadUserProp(
          this,
          (idParser *)src,
          prop: (idVarArgs<6> *)&v184.jointGroupCollection.jointGroupsByType[5].granularity);
        idList<idVarArgs<6>,19>::Append(
          this: &this->userProps,
          obj: (const idVarArgs<6> *)&v184.jointGroupCollection.jointGroupsByType[5].granularity);
        if ( *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[7].granularity != 0 )
        {
          idMem::Free(
            this: (idMem *)v184.name.str,
            ptr: *(void **)&v184.jointGroupCollection.jointGroupsByType[7].granularity,
            align: ALIGN_16);
          *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[7].granularity = 0;
        }
        *(_WORD *)&v184.jointGroupCollection.jointGroupsByType[5].memTag = 0;
        HIWORD(v184.jointGroupCollection.jointGroupsByType[6].list) = 0;
        v184.jointGroupCollection.jointGroupsByType[5].granularity = 0;
      }
    }
  }
  else
  {
    v184.name.str = (const char *)&mem;
  }
  v67 = this->parentDecl;
  if ( v67 != nullptr )
  {
    list = v184.declsToIncludeAnimDataFrom.list;
    v69 = 0;
    v70 = v184.declsToIncludeAnimDataFrom.list;
    while ( v69 < v67->userProps.num )
    {
      v71 = &v67->userProps.list[v69];
      if ( v71->numArgs != 0 && v71->argTypes[0] == 8 )
        list = (idDeclMD6::includeDecl_t *)&v71->args[v71->argOffsets[0]];
      v72 = 0;
      for ( m = 0; ; ++m )
      {
        if ( m >= this->userProps.num )
          goto LABEL_139;
        v74 = &this->userProps.list[m];
        if ( v74->numArgs != 0 && v74->argTypes[0] == 8 )
          v70 = (idDeclMD6::includeDecl_t *)&v74->args[v74->argOffsets[0]];
        if ( idStr::Icmp(s1: (const char *)v70, s2: (const char *)list) == 0 )
          break;
      }
      v72 = 1;
LABEL_139:
      if ( v72 == 0 )
        idList<idVarArgs<6>,19>::Append(this: &this->userProps, obj: v71);
      v64 = (idParser *)src;
      ++v69;
    }
  }
  v75 = 0;
  p_defaultBounds = &this->model->defaultBounds;
  while ( v75 < 2 )
  {
    p_x = &p_defaultBounds->b[v75].x;
    v176 = &this->referenceBounds.b[v75].x;
    *v176 = *p_x;
    ++v75;
    v176[1] = p_x[1];
    v176[2] = p_x[2];
  }
  if ( idParser::CheckTokenString(this: v64, string: "jointGroups") != 0 )
    idJointGroupCollection::Parse(this: &this->jointGroupCollection, src: v64, decl: this);
  v77 = this->parentDecl;
  if ( v77 != nullptr )
    idJointGroupCollection::DuplicateInherited(
      this: &this->jointGroupCollection,
      myDecl: this,
      parentDecl: v77,
      parentCollection: &v77->jointGroupCollection);
  idJointGroupCollection::Condense(this: &this->jointGroupCollection);
  if ( idParser::CheckTokenString(this: v64, string: "events") != 0 )
    idAnimEvents::Parse(this: &this->animEvents, decl: this, src: v64, loadErrors: &this->numLoadErrors);
  if ( idParser::CheckTokenString(this: v64, string: "aliases") != 0 )
  {
    idParser::ExpectTokenType(this: v64, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    v78 = (idDeclMD6_vtbl *)&animation;
    while ( idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.staleCount)
         && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
    {
      if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "alias") != 0 )
      {
        idParser::Error(
          this: (idParser *)src,
          str: "Unknown token '%s', expected 'alias'",
          *((const char **)&v184.idResource + 8));
      }
      else
      {
        idMD6Alias::idMD6Alias(this: (idMD6Alias *)&v184.jointGroupCollection.jointGroupsByType[8].granularity);
        idMD6Alias::Parse(
          this: (idMD6Alias *)&v184.jointGroupCollection.jointGroupsByType[8].granularity,
          decl: this,
          (idParser *)src,
          loadErrors: &this->numLoadErrors);
        ((void (__fastcall *)(idResourceList **))animation->FindAliasHandle_2)(a1: &v184.resourceListPtr);
        if ( HIWORD(v184.resourceListPtr) == 0xFFFF
          || idDeclMD6::FindAlias(
               this,
               aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v184.resourceListPtr,
               includeInherited: false) == nullptr )
        {
          idDeclMD6::AddAlias(
            this: &v184,
            result: this,
            inAlias: (idMD6Alias *)&v184.jointGroupCollection.jointGroupsByType[8].granularity,
            overload: false);
        }
        else
        {
          idLib::Warning(
            fmt: "Alias '%s' is defined more than once in decl '%s'",
            *(const char **)&v184.jointGroupCollection.jointGroupsByType[8].granularity,
            this->name.str);
        }
        if ( LOBYTE(v184.jointGroupCollection.jointGroupsByType[10].list) == 0
          || LOBYTE(v184.jointGroupCollection.jointGroupsByType[10].list) == 2 )
        {
          if ( v184.jointGroupCollection.jointGroupsByType[9].num != 0 )
          {
            for ( n = 0; n < *(int *)&v184.jointGroupCollection.jointGroupsByType[9].granularity; ++n )
              ;
            idMem::Free(
              this: (idMem *)v184.name.str,
              ptr: (void *)v184.jointGroupCollection.jointGroupsByType[9].num,
              align: ALIGN_16);
          }
          v184.jointGroupCollection.jointGroupsByType[9].num = 0;
          *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[9].granularity = 0;
        }
        v184.jointGroupCollection.jointGroupsByType[9].size = 0;
      }
    }
  }
  else
  {
    v78 = (idDeclMD6_vtbl *)&animation;
  }
  v80 = (idParser *)src;
  v184.__vftable = (idDeclMD6_vtbl *)&animation;
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "props") != 0 )
    idPropsCollection::Parse(this: &this->props, (idParser *)src, decl: this);
  v81 = this->parentDecl;
  if ( v81 != nullptr )
    idPropsCollection::DuplicateInherited(this: &this->props, other: &v81->props);
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "eyeInfoCollection") != 0 )
    idEyeInfoCollection::Parse(
      this: &this->eyeInfoCollection,
      decl: this,
      (idParser *)src,
      loadErrors: &this->numLoadErrors);
  v82 = this->parentDecl;
  if ( v82 != nullptr )
    idEyeInfoCollection::DuplicateInherited(
      this: &this->eyeInfoCollection,
      declmd6: this,
      parentCollection: &v82->eyeInfoCollection);
  if ( idParser::CheckTokenString(this: (idParser *)src, string: "morphVerts") != 0 )
  {
    v83 = (char **)&this->morphDefList;
    if ( this->morphDefList.listStatic == 0 || this->morphDefList.listStatic == 2 )
    {
      if ( *v83 != nullptr )
        idListArrayDelete<idMorphDef>(ptr: *v83, num: this->morphDefList.size);
      *v83 = nullptr;
      this->morphDefList.size = 0;
    }
    *(float *)&v184.eyeInfoCollection.curHandle = -3.4028235e38;
    this->morphDefList.num = 0;
    v184.animEvents.__vftable = (idAnimEvents_vtbl *)&v184.animEvents.list.num;
    v184.animEvents.list.list = (idAnimEvents::animEventInfo_t *)20;
    *(_DWORD *)&v184.props.props.granularity = 0;
    HIBYTE(v184.animEvents.list.num) = 0;
    v184.animEvents.hashIndex.memTag = TAG_UNSET;
    memset(&v184.eyeInfoCollection.eyeInfos, 0, 12);
    idParser::ExpectTokenType(
      this: (idParser *)src,
      type: 5,
      subtype: 46,
      token: (idToken *)&v184.props.props.granularity);
    trackedMemory = "amount <= GetAlloced()";
    while ( 1 )
    {
      if ( !idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.props.props.granularity)
        || v184.animEvents.hashIndex.hashSize == 5 && v184.animEvents.hashIndex.indexSize == 47 )
      {
        goto _LN1740;
      }
      if ( idStr::Cmp(s1: (const char *)v184.animEvents.__vftable, s2: "morphFile") != 0 )
        break;
      v184.meshKitGroups[0].list = nullptr;
      v184.meshKitGroups[0].num = (int)&v184.meshKitGroups[0].granularity;
      v184.meshKitGroups[0].size = 20;
      HIBYTE(v184.meshKitGroups[0].granularity) = 0;
      v184.meshKitDefault[0].allocedAndFlag = 0;
      *(_DWORD *)&v184.meshKitDefault[0].baseBuffer[4] = &v184.meshKitDefault[0].baseBuffer[12];
      *(_DWORD *)v184.meshKitDefault[0].baseBuffer = 0;
      v184.meshKitDefault[0].baseBuffer[12] = 0;
      *(_DWORD *)&v184.meshKitDefault[0].baseBuffer[8] = 20;
      idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.props.props.granularity);
      v85 = *(_DWORD *)&v184.props.props.granularity;
      v86 = *(_DWORD *)&v184.props.props.granularity + 1;
      v87 = *(_DWORD *)&v184.meshKitDefault[0].baseBuffer[8] & 0x7FFFFFFF;
      if ( *(int *)&v184.meshKitDefault[0].baseBuffer[8] >= 0 )
      {
        if ( v86 > v87 )
          idStr::ReAllocate(this: (idStr *)v184.meshKitDefault[0].baseBuffer, amount: v86, keepold: false);
      }
      else if ( v86 > v87
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: *(void **)&v184.meshKitDefault[0].baseBuffer[4], Src: v184.animEvents.__vftable, Size: v85);
      *(_BYTE *)(*(_DWORD *)&v184.meshKitDefault[0].baseBuffer[4] + v85) = 0;
      *(_DWORD *)v184.meshKitDefault[0].baseBuffer = v85;
      idList<idMorphDef,115>::Append(this: &this->morphDefList, obj: (const idMorphDef *)v184.meshKitGroups);
      idStr::FreeData(this: (idStr *)v184.meshKitDefault[0].baseBuffer);
      idStr::FreeData(this: (idStr *)v184.meshKitGroups);
    }
    v88 = this->name.str;
    v184.trackedMemory = (int)"amount <= GetAlloced()";
    idLib::Error(fmt: "Read Bad morph data for %s", v88);
_LN1740:
    v184.trackedMemory = (int)"amount <= GetAlloced()";
    idStr::FreeData(this: (idStr *)&v184.props.props.granularity);
    v80 = (idParser *)src;
  }
  else
  {
    trackedMemory = "amount <= GetAlloced()";
    v184.trackedMemory = (int)"amount <= GetAlloced()";
  }
  if ( idParser::CheckTokenString(this: v80, string: "morphSkin") != 0 )
  {
    *(float *)&v184.aliasHash.memTag = -3.4028235e38;
    v184.userProps.num = 0;
    v184.userProps.size = (int)&v184.aliases;
    *(_DWORD *)&v184.userProps.granularity = 20;
    HIBYTE(v184.aliases.list) = 0;
    v184.aliasHash.lookupMask = 0;
    memset(&v184.curAliasHandle, 0, 12);
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.userProps.num);
    while ( idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.userProps.num)
         && (v184.aliasHash.indexChain != (int *)5 || v184.aliasHash.hashSize != 47) )
    {
      if ( idStr::Cmp(s1: (const char *)v184.userProps.size, s2: "projectionModel") != 0 )
      {
        if ( idStr::Cmp(s1: (const char *)v184.userProps.size, s2: "outputPath") == 0 )
          idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.meshKitDefault[1].baseBuffer[4]);
      }
      else
      {
        idParser::ReadToken(this: (idParser *)src, token: (idToken *)&v184.wrinkleMapRegionExpressions.size);
      }
    }
    idStr::FreeData(this: (idStr *)&v184.userProps.num);
    v80 = (idParser *)src;
  }
  if ( idParser::CheckTokenString(this: v80, string: "meshKits") != 0 )
  {
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    v89 = 0;
    for ( ii = 0; ii < 3; ++ii )
    {
      if ( idParser::CheckTokenString(this: v80, string: idDeclMD6::meshKitGroupNames[ii]) != 0 )
      {
        v91 = (char *)this + 16 * ii;
        v92 = (idList<idPair<idStr,idList<int,19> >,19> *)(v91 + 524);
        v93 = (unsigned __int8)v91[539];
        if ( v93 == 0 || v93 == 2 )
        {
          if ( v92->list != nullptr )
            idListArrayDelete<idPair<idStr,idList<int,19>>>(ptr: v92->list, num: v92->size);
          v92->list = nullptr;
          v92->size = 0;
        }
        v92->num = 0;
        if ( idParser::CheckTokenType(this: v80, type: 3, subtype: 0, token: (idToken *)&v184.staleCount) != 0 )
        {
          if ( v184.model == (const idMD6Model *)3 )
          {
            if ( (v184.parent.len & 0x10000) == 0 )
              idToken::NumberValue(this: (idToken *)&v184.staleCount);
            v94 = *(_DWORD *)&v184.parent.baseBuffer[4];
          }
          else
          {
            v94 = 0;
          }
          if ( v94 > v92->size )
            idList<idPair<idStr,idList<int,19>>,19>::Resize(this: v92, newsize: v94);
        }
        idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
        while ( idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount)
             && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
        {
          if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "meshKit") != 0 )
          {
            v120 = (char *)this + 16 * ii;
            v121 = (int *)(v120 + 524);
            idList<idPair<idStr,idList<int,19>>,19>::PreAllocateWithGranularity(
              this: (idList<idPair<idStr,idList<int,19> >,19> *)(v120 + 524),
              newSize: *((_DWORD *)v120 + 132) + 1);
            v122 = v121[1];
            v123 = v121[2];
            v124 = *v121;
            if ( v122 >= v123 )
            {
              v125 = 48 * v123 + v124 - 48;
            }
            else
            {
              v121[1] = v122 + 1;
              v125 = 48 * v122 + v124;
            }
            v126 = *(_DWORD *)(v125 + 8);
            v127 = v184.staleCount;
            v128 = v184.staleCount + 1;
            v105 = v126 >> 31 == 0;
            v129 = v126 & 0x7FFFFFFF;
            if ( v105 )
            {
              if ( v128 > v129 )
                idStr::ReAllocate(this: (idStr *)v125, amount: v128, keepold: false);
            }
            else if ( v128 > v129
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: trackedMemory,
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v125 + 4), Src: *((const void **)&v184.idResource + 8), Size: v127);
            *(_BYTE *)(*(_DWORD *)(v125 + 4) + v127) = 0;
            *(_DWORD *)v125 = v127;
            idParser::ExpectTokenType(this: v80, type: 5, subtype: 32, token: (idToken *)&v184.staleCount);
            idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount);
            if ( v184.staleCount != 0 )
            {
              LODWORD(v184.referenceBounds.b[0].y) = 1280;
              memset(&v184.declsToIncludeAnimDataFrom.size, 0, 12);
              idStrListBreakupString(
                list: (idList<idStr,5> *)&v184.declsToIncludeAnimDataFrom.size,
                string: *((const char **)&v184.idResource + 8),
                separator: 32);
              v130 = *(_DWORD *)&v184.declsToIncludeAnimDataFrom.granularity;
              size = (const char **)v184.declsToIncludeAnimDataFrom.size;
              for ( jj = 0; jj < v130; ++jj )
              {
                v133 = 0;
                v134 = 0;
                while ( 1 )
                {
                  v135 = this->model;
                  v183 = (_DWORD *)v133;
                  if ( v133 >= v135->meshes.num )
                    break;
                  if ( idStr::Cmp(s1: size[8 * jj + 1], s2: v135->meshes.list[v133]->name.data) == 0 )
                  {
                    v134 = 1;
                    idList<idAnimWebBlendTree *,5>::Append(
                      this: (idList<enum encounterGroupRole_t,5> *)(v125 + 32),
                      obj: (const encounterGroupRole_t *)&v183);
                  }
                  ++v133;
                }
                if ( v134 == 0 )
                  idParser::Warning(
                    this: (idParser *)src,
                    str: "MeshKit Group(%s) Kit(%s) specifies an unknown mesh %s",
                    idDeclMD6::meshKitGroupNames[ii],
                    *(const char **)(v125 + 4),
                    size[8 * jj + 1]);
              }
              if ( LOBYTE(v184.referenceBounds.b[0].y) == 0 || LOBYTE(v184.referenceBounds.b[0].y) == 2 )
              {
                if ( size != nullptr )
                {
                  x = v184.referenceBounds.b[0].x;
                  for ( kk = 0; kk < SLODWORD(x); ++kk )
                    idStr::FreeData(this: (idStr *)&size[8 * kk]);
                  idMem::Free(this: (idMem *)v184.name.str, ptr: size, align: ALIGN_16);
                }
                v184.declsToIncludeAnimDataFrom.size = 0;
                v184.referenceBounds.b[0].x = 0.0;
              }
              v80 = (idParser *)src;
              v89 = 0;
              trackedMemory = (const char *)v184.trackedMemory;
              *(_DWORD *)&v184.declsToIncludeAnimDataFrom.granularity = 0;
            }
          }
          else
          {
            idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount);
            v95 = (char *)this + 16 * ii;
            v96 = (int *)(v95 + 524);
            idList<idPair<idStr,idList<int,19>>,19>::PreAllocateWithGranularity(
              this: (idList<idPair<idStr,idList<int,19> >,19> *)(v95 + 524),
              newSize: *((_DWORD *)v95 + 132) + 1);
            v97 = v96[1];
            v98 = v96[2];
            v99 = *v96;
            if ( v97 >= v98 )
            {
              v100 = 48 * v98 + v99 - 48;
            }
            else
            {
              v96[1] = v97 + 1;
              v100 = 48 * v97 + v99;
            }
            v101 = *(_DWORD *)(v100 + 8);
            v102 = v184.staleCount;
            v103 = v184.staleCount + 1;
            v105 = v101 >> 31 == 0;
            v104 = v101 & 0x7FFFFFFF;
            if ( v105 )
            {
              if ( v103 > v104 )
                idStr::ReAllocate(this: (idStr *)v100, amount: v103, keepold: false);
            }
            else if ( v103 > v104
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: trackedMemory,
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v100 + 4), Src: *((const void **)&v184.idResource + 8), Size: v102);
            *(_BYTE *)(*(_DWORD *)(v100 + 4) + v102) = 0;
            *(_DWORD *)v100 = v102;
            idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
            while ( idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount)
                 && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
            {
              if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "meshes") != 0 )
              {
                if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: "isDefault") == 0 )
                {
                  v114 = *(_DWORD *)v100;
                  v115 = (char *)this + 32 * ii;
                  v116 = *(_DWORD *)v100 + 1;
                  v117 = (idStr *)(v115 + 572);
                  v118 = *((_DWORD *)v115 + 145);
                  v105 = v118 >> 31 == 0;
                  v119 = v118 & 0x7FFFFFFF;
                  if ( v105 )
                  {
                    if ( v116 > v119 )
                      idStr::ReAllocate(this: v117, amount: v116, keepold: false);
                  }
                  else if ( v116 > v119
                         && AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              line: 463,
                              expression: trackedMemory,
                              inlineBreak: true) )
                  {
                    __trap();
                  }
                  memcpy(Dst: v117->data, Src: *(const void **)(v100 + 4), Size: v114);
                  v89 = 0;
                  v117->data[v114] = 0;
                  v117->len = v114;
                  v80 = (idParser *)src;
                }
              }
              else
              {
                idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount);
                if ( v184.staleCount != 0 )
                {
                  LODWORD(v184.referenceBounds.b[1].z) = 1280;
                  memset(&v184.referenceBounds.b[0].z, 0, 12);
                  idStrListBreakupString(
                    list: (idList<idStr,5> *)&v184.referenceBounds.b[0].z,
                    string: *((const char **)&v184.idResource + 8),
                    separator: 32);
                  v106 = v184.referenceBounds.b[1].x;
                  z = v184.referenceBounds.b[0].z;
                  for ( mm = 0; mm < SLODWORD(v106); ++mm )
                  {
                    v109 = 0;
                    v110 = 0;
                    while ( 1 )
                    {
                      v111 = this->model;
                      v183 = (_DWORD *)v109;
                      if ( v109 >= v111->meshes.num )
                        break;
                      if ( idStr::Cmp(
                             s1: *(const char **)(32 * mm + LODWORD(z) + 4),
                             s2: v111->meshes.list[v109]->name.data) == 0 )
                      {
                        v110 = 1;
                        idList<idAnimWebBlendTree *,5>::Append(
                          this: (idList<enum encounterGroupRole_t,5> *)(v100 + 32),
                          obj: (const encounterGroupRole_t *)&v183);
                      }
                      ++v109;
                    }
                    if ( v110 == 0 )
                      idParser::Warning(
                        this: (idParser *)src,
                        str: "MeshKit Group(%s) Kit(%s) specifies an unknown mesh %s",
                        idDeclMD6::meshKitGroupNames[ii],
                        *(const char **)(v100 + 4),
                        *(const char **)(32 * mm + LODWORD(z) + 4));
                  }
                  if ( LOBYTE(v184.referenceBounds.b[1].z) == 0 || LOBYTE(v184.referenceBounds.b[1].z) == 2 )
                  {
                    if ( z != 0.0 )
                    {
                      y = v184.referenceBounds.b[1].y;
                      for ( nn = 0; nn < SLODWORD(y); ++nn )
                        idStr::FreeData(this: (idStr *)(32 * nn + LODWORD(z)));
                      idMem::Free(this: (idMem *)v184.name.str, ptr: (void *)LODWORD(z), align: ALIGN_16);
                    }
                    v184.referenceBounds.b[0].z = 0.0;
                    v184.referenceBounds.b[1].y = 0.0;
                  }
                  v80 = (idParser *)src;
                  v89 = 0;
                  trackedMemory = (const char *)v184.trackedMemory;
                  v184.referenceBounds.b[1].x = 0.0;
                }
              }
            }
          }
        }
        v78 = v184.__vftable;
      }
    }
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 47, token: (idToken *)&v184.staleCount);
  }
  else
  {
    v89 = 0;
  }
  if ( idParser::CheckTokenString(this: v80, string: "wrinkleExpressions") != 0 )
  {
    *(float *)&v184.jointGroupCollection.jointGroupsByType[2].num = -3.4028235e38;
    v184.numLoadErrors = 0;
    v184.jointGroupCollection.jointGroups.list = (idJointGroup **)&v184.jointGroupCollection.jointGroups.size;
    v184.jointGroupCollection.jointGroups.num = 20;
    HIBYTE(v184.jointGroupCollection.jointGroups.size) = 0;
    v184.jointGroupCollection.jointGroupsByType[2].list = nullptr;
    memset(&v184.jointGroupCollection.jointGroupsByType[2].size, 0, 12);
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.numLoadErrors);
    v138 = (idMem *)v184.name.str;
LABEL_310:
    while ( idParser::ReadToken(this: v80, token: (idToken *)&v184.numLoadErrors)
         && (*(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[0].granularity != 5
          || v184.jointGroupCollection.jointGroupsByType[1].list != (idJointGroup **)47) )
    {
      if ( idStr::Cmp(s1: (const char *)v184.jointGroupCollection.jointGroups.list, s2: "regions") == 0 )
      {
        if ( this->wrinkleMapRegionExpressions.listStatic == 0 || this->wrinkleMapRegionExpressions.listStatic == 2 )
        {
          v139 = this->wrinkleMapRegionExpressions.list;
          if ( v139 != nullptr )
          {
            v140 = this->wrinkleMapRegionExpressions.size;
            for ( i1 = 0; i1 < v140; ++i1 )
              idStr::FreeData(this: &v139[i1]);
            idMem::Free(this: v138, ptr: v139, align: ALIGN_16);
          }
          v80 = (idParser *)src;
          v89 = 0;
          this->wrinkleMapRegionExpressions.list = nullptr;
          this->wrinkleMapRegionExpressions.size = 0;
        }
        this->wrinkleMapRegionExpressions.num = 0;
        if ( idParser::CheckTokenType(this: v80, type: 3, subtype: 0, token: (idToken *)&v184.numLoadErrors) != 0 )
        {
          if ( *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[0].granularity == 3 )
          {
            if ( ((int)v184.jointGroupCollection.jointGroupsByType[1].list & 0x10000) == 0 )
              idToken::NumberValue(this: (idToken *)&v184.numLoadErrors);
            v142 = v184.jointGroupCollection.jointGroupsByType[2].list;
          }
          else
          {
            v142 = nullptr;
          }
          if ( (int)v142 > this->wrinkleMapRegionExpressions.size )
            idList<idStr,3>::Resize(this: &this->wrinkleMapRegionExpressions, newsize: (int)v142);
        }
        idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.numLoadErrors);
        while ( idParser::ReadToken(this: v80, token: (idToken *)&v184.numLoadErrors) )
        {
          if ( *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[0].granularity == 5 )
          {
            if ( v184.jointGroupCollection.jointGroupsByType[1].list == (idJointGroup **)47 )
              goto LABEL_310;
          }
          else if ( *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[0].granularity == 3 )
          {
            if ( ((int)v184.jointGroupCollection.jointGroupsByType[1].list & 0x10000) == 0 )
              idToken::NumberValue(this: (idToken *)&v184.numLoadErrors);
            v89 = (int)v184.jointGroupCollection.jointGroupsByType[2].list;
          }
          if ( v89 >= this->wrinkleMapRegionExpressions.num
            && (v89 + 1 <= this->wrinkleMapRegionExpressions.size
             || idList<idStr,3>::Resize(this: &this->wrinkleMapRegionExpressions, newsize: v89 + 1)) )
          {
            v143 = this->wrinkleMapRegionExpressions.size;
            if ( v89 + 1 < v143 )
              v143 = v89 + 1;
            this->wrinkleMapRegionExpressions.num = v143;
          }
          idParser::ExpectTokenType(this: (idParser *)src, type: 1, subtype: 0, token: (idToken *)&v184.numLoadErrors);
          v144 = &this->wrinkleMapRegionExpressions.list[v89];
          numLoadErrors = v184.numLoadErrors;
          v146 = v184.numLoadErrors + 1;
          allocedAndFlag = v144->allocedAndFlag;
          v105 = allocedAndFlag >> 31 == 0;
          v148 = allocedAndFlag & 0x7FFFFFFF;
          if ( v105 )
          {
            if ( v146 > v148 )
              idStr::ReAllocate(this: &this->wrinkleMapRegionExpressions.list[v89], amount: v146, keepold: false);
          }
          else if ( v146 > v148
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: trackedMemory,
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v144->data, Src: v184.jointGroupCollection.jointGroups.list, Size: numLoadErrors);
          v89 = 0;
          v144->data[numLoadErrors] = 0;
          v144->len = numLoadErrors;
          v80 = (idParser *)src;
        }
      }
    }
    idStr::FreeData(this: (idStr *)&v184.numLoadErrors);
  }
  else
  {
    v149 = this->parentDecl;
    if ( v149 != nullptr && v149->wrinkleMapRegionExpressions.num != 0 )
      idList<idStr,58>::operator=(this: &this->wrinkleMapRegionExpressions, other: &v149->wrinkleMapRegionExpressions);
    v138 = (idMem *)v184.name.str;
  }
  if ( this->userChannelToAnimationAliasOverrides.listStatic == 0
    || this->userChannelToAnimationAliasOverrides.listStatic == 2 )
  {
    v150 = this->userChannelToAnimationAliasOverrides.list;
    if ( v150 != nullptr )
    {
      for ( i2 = 0; i2 < this->userChannelToAnimationAliasOverrides.size; ++i2 )
        ;
      idMem::Free(this: v138, ptr: v150, align: ALIGN_16);
    }
    this->userChannelToAnimationAliasOverrides.list = nullptr;
    this->userChannelToAnimationAliasOverrides.size = 0;
  }
  this->userChannelToAnimationAliasOverrides.num = 0;
  if ( this->userChannelToAnimationAliasMap.listStatic == 0 || this->userChannelToAnimationAliasMap.listStatic == 2 )
  {
    v152 = this->userChannelToAnimationAliasMap.list;
    if ( v152 != nullptr )
    {
      for ( i3 = 0; i3 < this->userChannelToAnimationAliasMap.size; ++i3 )
        ;
      idMem::Free(this: v138, ptr: v152, align: ALIGN_16);
    }
    this->userChannelToAnimationAliasMap.list = nullptr;
    this->userChannelToAnimationAliasMap.size = 0;
  }
  this->userChannelToAnimationAliasMap.num = 0;
  if ( idParser::CheckTokenString(this: v80, string: "userChannelToAnimationAliasOverrides") != 0 )
  {
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    while ( idParser::ReadToken(this: v80, token: (idToken *)&v184.staleCount)
         && (v184.model != (const idMD6Model *)5 || v184.parent.len != 47) )
    {
      v184.jointGroupCollection.jointGroupsByType[4].num = 20;
      v184.jointGroupCollection.jointGroupsByType[4].list = (idJointGroup **)&v184.jointGroupCollection.jointGroupsByType[4].size;
      *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[3].granularity = 0;
      v154 = v184.staleCount;
      HIBYTE(v184.jointGroupCollection.jointGroupsByType[4].size) = 0;
      if ( v184.staleCount + 1 > 20 )
        idStr::ReAllocate(
          this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[3].granularity,
          amount: v184.staleCount + 1,
          keepold: true);
      v155 = *((char **)&v184.idResource + 8);
      v156 = v184.jointGroupCollection.jointGroupsByType[4].list;
      do
      {
        v157 = *v155;
        *(_BYTE *)v156 = *v155++;
        v156 = (idJointGroup **)((char *)v156 + 1);
      }
      while ( v157 != 0 );
      *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[3].granularity = v154;
      idParser::ExpectTokenType(this: v80, type: 5, subtype: 32, token: (idToken *)&v184.staleCount);
      idParser::ExpectTokenType(this: v80, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
      v184.jointGroupCollection.jointGroupsByType[11].num = 20;
      v184.jointGroupCollection.jointGroupsByType[11].list = (idJointGroup **)&v184.jointGroupCollection.jointGroupsByType[11].size;
      *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[10].granularity = 0;
      v158 = v184.staleCount;
      HIBYTE(v184.jointGroupCollection.jointGroupsByType[11].size) = 0;
      if ( v184.staleCount + 1 > 20 )
        idStr::ReAllocate(
          this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[10].granularity,
          amount: v184.staleCount + 1,
          keepold: true);
      v159 = *((char **)&v184.idResource + 8);
      v160 = v184.jointGroupCollection.jointGroupsByType[11].list;
      do
      {
        v161 = *v159;
        *(_BYTE *)v160 = *v159++;
        v160 = (idJointGroup **)((char *)v160 + 1);
      }
      while ( v161 != 0 );
      *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[10].granularity = v158;
      if ( *(_DWORD *)&v184.jointGroupCollection.jointGroupsByType[3].granularity != 0
        && v158 != 0
        && (idMD6Skel::GetUserChannelIndex(
              this: (idMD6Skel *)((char *)&v184.nextOnHashChain + 2),
              result: (idIndex<short,enum invalidUserChannelIndex_t> *)this->model->skeleton,
              name: (const char *)v184.jointGroupCollection.jointGroupsByType[4].list),
            (*(void (__fastcall **)(idResource **, void (__fastcall *)(struct idDeclMD6 *), idDeclMD6 *, idJointGroup **))(*(_DWORD *)v78->dtr_idResource + 96))(
              a1: &v184.nextOnHashChain,
              a2: v78->dtr_idResource,
              a3: this,
              a4: v184.jointGroupCollection.jointGroupsByType[11].list),
            SLOWORD(v184.nextOnHashChain) >= 0)
        && HIWORD(v184.nextOnHashChain) != 0xFFFF )
      {
        p_userChannelToAnimationAliasOverrides = &this->userChannelToAnimationAliasOverrides;
        idList<idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535>>,19>::PreAllocateWithGranularity(
          this: &this->userChannelToAnimationAliasOverrides,
          newSize: this->userChannelToAnimationAliasOverrides.num + 1);
        num = this->userChannelToAnimationAliasOverrides.num;
        v164 = this->userChannelToAnimationAliasOverrides.size;
        if ( num >= v164 )
        {
          v166 = &p_userChannelToAnimationAliasOverrides->list[v164 - 1];
        }
        else
        {
          v165 = p_userChannelToAnimationAliasOverrides->list;
          this->userChannelToAnimationAliasOverrides.num = num + 1;
          v166 = &v165[num];
        }
        v166->first.value = (__int16)v184.nextOnHashChain;
        v166->second.value = HIWORD(v184.nextOnHashChain);
        idStr::FreeData(this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[10].granularity);
        idStr::FreeData(this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[3].granularity);
      }
      else
      {
        idStr::FreeData(this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[10].granularity);
        idStr::FreeData(this: (idStr *)&v184.jointGroupCollection.jointGroupsByType[3].granularity);
      }
    }
  }
  idDeclMD6::InitUserChannelToAnimationAliasMap(this);
  if ( idParser::CheckTokenString(this: v80, string: "baseUserChannel") != 0 )
  {
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    idParser::ExpectTokenType(this: v80, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
    this->baseUserChannelAlias.value = *(_WORD *)(*(int (__fastcall **)(idDeclMD6 *, void (__fastcall *)(struct idDeclMD6 *), idDeclMD6 *, _DWORD))(*(_DWORD *)v78->dtr_idResource + 96))(
                                                   a1: &v184,
                                                   a2: v78->dtr_idResource,
                                                   a3: this,
                                                   a4: *((_DWORD *)&v184.idResource + 8));
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 47, token: (idToken *)&v184.staleCount);
  }
  if ( idParser::CheckTokenString(this: v80, string: "userChannelWeightGroupOverride") != 0 )
  {
    idParser::ExpectTokenType(this: v80, type: 5, subtype: 46, token: (idToken *)&v184.staleCount);
    idParser::ExpectTokenType(this: v80, type: 1, subtype: 0, token: (idToken *)&v184.staleCount);
    EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "md6WeightGroup_t");
    if ( EnumInfo != nullptr )
    {
      for ( i4 = 0; ; ++i4 )
      {
        if ( i4 >= 8 )
          goto LABEL_414;
        if ( idStr::Cmp(s1: *((const char **)&v184.idResource + 8), s2: EnumInfo->values[i4].name) == 0 )
          break;
LABEL_413:
        ;
      }
      v169 = this->parentDecl;
      v170 = EnumInfo->values[i4].value;
      if ( v169 == nullptr )
        goto _M246902;
      userChannelWeightGroupOverride = v169->userChannelWeightGroupOverride;
      if ( userChannelWeightGroupOverride < 0 || (v172 = 1, userChannelWeightGroupOverride >= 8) )
        v172 = 0;
      if ( v172 == 0 )
      {
        v173 = v169->parentDecl;
        if ( v173 != nullptr )
          userChannelWeightGroupOverride = idDeclMD6::GetUserChannelWeightGroup(this: v173);
        else
_M246902:
          userChannelWeightGroupOverride = 0;
      }
      if ( v170 != userChannelWeightGroupOverride )
        this->userChannelWeightGroupOverride = v170;
      goto LABEL_413;
    }
LABEL_414:
    idParser::ExpectTokenType(this: (idParser *)src, type: 5, subtype: 47, token: (idToken *)&v184.staleCount);
    v80 = (idParser *)src;
  }
  idAnimEvents::CacheTransforms(this: &this->animEvents, decl: this);
  idStr::FreeData(this: (idStr *)&v184.staleCount);
  if ( this->morphDefList.num > 0 )
  {
    v174 = (idMorphVertices *)idResourceList::Load(
                                this: &idMorphVertices::resourceList,
                                name: (char *)this->name.str,
                                makeDefault: true,
                                skipStaleCheck: false);
    this->morphVertices = v174;
    idLib::WarningIf(
      condition: (_cntlzw((unsigned int)v174) & 0x20) != 0,
      fmt: "'%s' failed to Load it's morph vertices",
      this->name.str);
  }
  idDeclMD6::InitHeadTrackGroups(this);
  idParser::SetFlags(this: v80, flags: (int)v184.declsToIncludeAnimDataFrom.list);
  idStr::FreeData(this: (idStr *)&v184.meshKitDefault[1].baseBuffer[4]);
  JUMPOUT(0x82819614);
}


// ========================================================================
// $M246923_1
// EA  : 0x8281959C
// RVA : 0x0081959C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void *_M246923_1()
{
  int v0; // r12
  int v1; // r31
  idParser *v2; // r29

  v1 = v0 - 5136;
  v2 = *(idParser **)(v0 - 5136 + 5164);
  if ( idParser::HadError(this: v2) )
    idLib::Warning(fmt: idException::error);
  idParser::Warning(this: v2, str: idException::error);
  idParser::SetFlags(this: v2, flags: *(_DWORD *)(v1 + 184));
  return &_M246916_2;
}


// ========================================================================
// $LN1257
// EA  : 0x82819628
// RVA : 0x00819628
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _LN1257()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 784));
}


// ========================================================================
// __unwind$244049
// EA  : 0x82819650
// RVA : 0x00819650
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244049()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 704));
}


// ========================================================================
// __unwind$244050
// EA  : 0x82819678
// RVA : 0x00819678
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244050()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 112));
}


// ========================================================================
// __unwind$244051
// EA  : 0x828196A0
// RVA : 0x008196A0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244051()
{
  int v0; // r12

  idVarArgs<6>::Free(this: (idVarArgs<6> *)(v0 - 5136 + 336));
}


// ========================================================================
// __unwind$244052
// EA  : 0x828196C8
// RVA : 0x008196C8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244052()
{
  int v0; // r12

  idMD6Alias::~idMD6Alias(this: (idMD6Alias *)(v0 - 5136 + 384));
}


// ========================================================================
// __unwind$244053
// EA  : 0x828196F0
// RVA : 0x008196F0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244053()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 448));
}


// ========================================================================
// __unwind$244054
// EA  : 0x82819718
// RVA : 0x00819718
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244054()
{
  int v0; // r12

  idMorphDef::~idMorphDef(this: (idMorphDef *)(v0 - 5136 + 608));
}


// ========================================================================
// __unwind$245149
// EA  : 0x82819740
// RVA : 0x00819740
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_245149()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 608));
}


// ========================================================================
// __unwind$244055
// EA  : 0x82819768
// RVA : 0x00819768
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244055()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 528));
}


// ========================================================================
// __unwind$244056
// EA  : 0x82819790
// RVA : 0x00819790
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244056()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 5136 + 208));
}


// ========================================================================
// __unwind$244057
// EA  : 0x828197B8
// RVA : 0x008197B8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244057()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 5136 + 192));
}


// ========================================================================
// __unwind$244058
// EA  : 0x828197E0
// RVA : 0x008197E0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244058()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 224));
}


// ========================================================================
// __unwind$244059
// EA  : 0x82819808
// RVA : 0x00819808
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244059()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 304));
}


// ========================================================================
// __unwind$244060
// EA  : 0x82819830
// RVA : 0x00819830
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_244060()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5136 + 416));
}


// ========================================================================
// ?GetNode@md6AncestryNode_t@@SAAAU1@AAU1@PBVidDeclMD6@@@Z
// EA  : 0x82819BB0
// RVA : 0x00819BB0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

md6AncestryNode_t *__fastcall md6AncestryNode_t::GetNode(md6AncestryNode_t *root, const idDeclMD6 *decl)
{
  const idDeclMD6 *parentDecl; // r4
  int num; // r8
  int v5; // r10
  md6AncestryNode_t *v6; // r9
  int v7; // r11
  idList<md6AncestryNode_t,5> *p_children; // r31
  int v9; // r11
  int size; // r10
  md6AncestryNode_t *list; // r10
  md6AncestryNode_t *result; // r3

  parentDecl = decl->parentDecl;
  if ( parentDecl != nullptr )
    root = md6AncestryNode_t::GetNode(root, decl: parentDecl);
  num = root->children.num;
  v5 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    p_children = &root->children;
    idList<md6AncestryNode_t,5>::PreAllocateWithGranularity(this: &root->children, newSize: root->children.num + 1);
    v9 = p_children->num;
    size = p_children->size;
    if ( v9 >= size )
    {
      result = &p_children->list[size - 1];
    }
    else
    {
      list = p_children->list;
      p_children->num = v9 + 1;
      result = &list[v9];
    }
    result->decl = decl;
  }
  else
  {
    v6 = root->children.list;
    v7 = 0;
    while ( v6[v7].decl != decl )
    {
      ++v5;
      ++v7;
      if ( v5 >= num )
        goto LABEL_7;
    }
    return &v6[v5];
  }
  return result;
}


// ========================================================================
// ?md6Ancestry_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82819CA0
// RVA : 0x00819CA0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __fastcall md6Ancestry_f(const idCmdArgs *args, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r29
  md6AncestryNode_t *list; // r11
  __int64 v8; // r10
  int v9; // r29
  const idDeclMD6 *v10; // r3
  int v11; // r29
  int v12; // r30
  int size; // r30
  md6AncestryNode_t *v14; // r28
  md6AncestryNode_t *v15; // r29
  idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName> v16[3]; // [sp+54h] [-9Ch] BYREF
  md6AncestryNode_t v17; // [sp+60h] [-90h] BYREF
  idStr v18; // [sp+80h] [-70h] BYREF
  idStr v19[2]; // [sp+A0h] [-50h] BYREF

  v6 = 0;
  v16[1].__vftable = (idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>_vtbl *)&idDeclMD6::resourceList;
  while ( v6 < idDeclMD6::resourceList.declSources.num )
    idResourceList::Load(
      this: &idDeclMD6::resourceList,
      name: (char *)idDeclMD6::resourceList.declSources.list[v6++]->name.str,
      makeDefault: true,
      skipStaleCheck: false);
  v17.children.listStatic = 0;
  list = nullptr;
  v17.children.memTag = 5;
  HIDWORD(v8) = idDeclMD6::resourceList.num;
  v9 = 0;
  memset(&v17, 0, 18);
  if ( idDeclMD6::resourceList.num > 0 )
  {
    do
    {
      v10 = (const idDeclMD6 *)idResourceList::Index(this: &idDeclMD6::resourceList, index: v9);
      md6AncestryNode_t::GetNode(root: &v17, decl: v10);
      ++v9;
    }
    while ( v9 < idDeclMD6::resourceList.num );
    list = v17.children.list;
  }
  v16[0].__vftable = (idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>_vtbl *)&md6AncestryNode_t::SortByName::`vftable';
  if ( list != nullptr )
  {
    LODWORD(v8) = idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>::Sort;
    idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>::Sort(
      this: v16,
      base: list,
      num: v17.children.num,
      a4,
      a5,
      a6,
      a7: v8);
    list = v17.children.list;
  }
  v11 = 0;
  v16[0].__vftable = (idSort_Quick<md6AncestryNode_t,md6AncestryNode_t::SortByName>_vtbl *)&idSort<md6AncestryNode_t>::`vftable';
  if ( v17.children.num > 0 )
  {
    v12 = 0;
    while ( 1 )
    {
      v19[0].allocedAndFlag = 20;
      v19[0].len = 0;
      v19[0].data = v19[0].baseBuffer;
      v19[0].baseBuffer[0] = 0;
      v18.allocedAndFlag = 20;
      v18.data = v18.baseBuffer;
      v18.len = 0;
      v18.baseBuffer[0] = 0;
      md6AncestryNode_t::PrintNode(node: &list[v12], prefix: &v18, childPrefix: v19);
      idStr::FreeData(this: &v18);
      idStr::FreeData(this: v19);
      ++v11;
      ++v12;
      if ( v11 >= v17.children.num )
        break;
      list = v17.children.list;
    }
    list = v17.children.list;
  }
  if ( (v17.children.listStatic == 0 || v17.children.listStatic == 2) && list != nullptr )
  {
    size = v17.children.size;
    v14 = list;
    if ( v17.children.size > 0 )
    {
      v15 = list;
      do
      {
        md6AncestryNode_t::~md6AncestryNode_t(this: v15);
        --size;
        ++v15;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
  }
}


// ========================================================================
// $M247588
// EA  : 0x82819EA8
// RVA : 0x00819EA8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void *_M247588()
{
  return &_LN20_1;
}


// ========================================================================
// __unwind$247211
// EA  : 0x82819EBC
// RVA : 0x00819EBC
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_247211()
{
  int v0; // r12

  md6AncestryNode_t::~md6AncestryNode_t(this: (md6AncestryNode_t *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$247212
// EA  : 0x82819EE4
// RVA : 0x00819EE4
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_247212()
{
  int v0; // r12

  md6AncestryNode_t::SortByName::~SortByName(this: (md6AncestryNode_t::SortByName *)(v0 - 240 + 84));
}


// ========================================================================
// __unwind$247213
// EA  : 0x82819F0C
// RVA : 0x00819F0C
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_247213()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// __unwind$247214
// EA  : 0x82819F34
// RVA : 0x00819F34
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void _unwind_247214()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// `dynamic initializer for 'md6_ForceGenMorphVerts''
// EA  : 0x83343F38
// RVA : 0x01343F38
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__md6_ForceGenMorphVerts__()
{
  idCVar::idCVar(
    this: &md6_ForceGenMorphVerts,
    name: "md6_ForceGenMorphVerts",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__md6_ForceGenMorphVerts__);
}


// ========================================================================
// `dynamic initializer for 'GenMorphVerts_v''
// EA  : 0x83343F90
// RVA : 0x01343F90
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GenMorphVerts_v__()
{
  return idCommandLink::idCommandLink(
           this: &GenMorphVerts_v,
           cmdName: "GenMorphVerts",
           function: GenMorphVerts_f,
           description: "Generates Morph Verts",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclMD6>);
}


// ========================================================================
// `dynamic initializer for 'md6Ancestry_v''
// EA  : 0x83343FC0
// RVA : 0x01343FC0
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__md6Ancestry_v__()
{
  return idCommandLink::idCommandLink(
           this: &md6Ancestry_v,
           cmdName: "md6Ancestry",
           function: (void (__fastcall *)(const idCmdArgs *))md6Ancestry_f,
           description: "Print ancestry information for all md6 defs",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportMD6boneCounts_v''
// EA  : 0x83343FE8
// RVA : 0x01343FE8
// PDB : w:\tech5\engine\models\skeletalanimation\declmd6.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportMD6boneCounts_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportMD6boneCounts_v,
           cmdName: "reportMD6boneCounts",
           function: reportMD6boneCounts_f,
           description: "Scan all md6 decls and report bone counts",
           argCompletion: nullptr);
}

