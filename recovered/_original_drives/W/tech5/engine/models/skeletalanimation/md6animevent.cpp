
// ========================================================================
// ??8idCachedJoint@@QBA_NABV0@@Z
// EA  : 0x82839918
// RVA : 0x00839918
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

int __fastcall idCachedJoint::operator==(idCachedJoint *this, const idCachedJoint *other)
{
  char v2; // r11
  char v3; // r3
  unsigned __int8 v4; // r11

  if ( this->jointIndex.value != other->jointIndex.value || this->frameNum != other->frameNum )
    return 0;
  if ( this->trans.x != other->trans.x || this->trans.y != other->trans.y || (v2 = 1, this->trans.z != other->trans.z) )
    v2 = 0;
  if ( v2 == 0 )
    return 0;
  v3 = idQuat::operator==(this: &this->rot, a: &other->rot);
  v4 = 1;
  if ( v3 == 0 )
    return 0;
  return v4;
}


// ========================================================================
// ?SetCachedJoint@idMD6AnimEvent@@QAAXABV?$idIndex@FW4invalidJointIndex_t@@@@HABVidVec3@@ABVidQuat@@@Z
// EA  : 0x828399C0
// RVA : 0x008399C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void __fastcall idMD6AnimEvent::SetCachedJoint(
        idMD6AnimEvent *this,
        const idIndex<short,enum invalidJointIndex_t> *ji,
        __int16 frameNum,
        const idVec3 *trans,
        const idQuat *rot)
{
  idCachedJoint *cachedJoint; // r11
  idCachedJoint *v11; // r3
  __int16 value; // r10

  cachedJoint = this->cachedJoint;
  if ( cachedJoint != nullptr )
  {
    cachedJoint->jointIndex = (idIndex<short,enum invalidJointIndex_t>)ji->value;
    this->cachedJoint->frameNum = frameNum;
    this->cachedJoint->trans = *trans;
    this->cachedJoint->rot = *rot;
  }
  else
  {
    v11 = (idCachedJoint *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6AnimEvent.cpp(703) : TAG_MD6_JOINTCACHE",
                             size: 0x20u,
                             tag: TAG_MD6_JOINTCACHE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
    {
      value = ji->value;
      v11->frameNum = frameNum;
      v11->jointIndex.value = value;
      v11->trans.x = trans->x;
      v11->trans.y = trans->y;
      v11->trans.z = trans->z;
      v11->rot.x = rot->x;
      v11->rot.y = rot->y;
      v11->rot.z = rot->z;
      v11->rot.w = rot->w;
      this->cachedJoint = v11;
    }
    else
    {
      this->cachedJoint = nullptr;
    }
  }
}


// ========================================================================
// ??1idMD6AnimEvent@@QAA@XZ
// EA  : 0x82839CC0
// RVA : 0x00839CC0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void __fastcall idMD6AnimEvent::~idMD6AnimEvent(idMD6AnimEvent *this)
{
  idCachedJoint *cachedJoint; // r4
  unsigned __int8 *args; // r4

  cachedJoint = this->cachedJoint;
  if ( cachedJoint != nullptr )
  {
    idMem::Free(this: &mem, ptr: cachedJoint, align: ALIGN_16);
    this->cachedJoint = nullptr;
  }
  args = this->args.args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    this->args.args = nullptr;
  }
  this->args.argSize = 0;
  this->args.buffSize = 0;
  this->args.numArgs = 0;
}


// ========================================================================
// __unwind$220360
// EA  : 0x82839D30
// RVA : 0x00839D30
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220360()
{
  int v0; // r12

  idVarArgs<4>::~idVarArgs<4>(this: *(idVarArgs<4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$220427_0
// EA  : 0x8283A40C
// RVA : 0x0083A40C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220427_0()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 760);
}


// ========================================================================
// __unwind$220428
// EA  : 0x8283A434
// RVA : 0x0083A434
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220428()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 759);
}


// ========================================================================
// __unwind$220429
// EA  : 0x8283A45C
// RVA : 0x0083A45C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220429()
{
  idStr *v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: v0 + 761);
}


// ========================================================================
// ??8idMD6AnimEvent@@QBA_NABV0@@Z
// EA  : 0x8283A488
// RVA : 0x0083A488
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

int __fastcall idMD6AnimEvent::operator==(idMD6AnimEvent *this, const idMD6AnimEvent *other)
{
  idCachedJoint *cachedJoint; // r3
  idCachedJoint *v5; // r4
  int result; // r3

  if ( (unsigned __int8)idVarArgs<4>::Equal(this: &this->args, other: &other->args) != 0
    && this->eventNum == other->eventNum
    && this->frameNum == other->frameNum
    && this->eventId.value == other->eventId.value
    && this->locked == other->locked
    && this->row == other->row )
  {
    cachedJoint = this->cachedJoint;
    if ( cachedJoint != nullptr )
    {
      v5 = other->cachedJoint;
      if ( v5 != nullptr )
        return idCachedJoint::operator==(this: cachedJoint, other: v5);
    }
    else
    {
      result = 1;
      if ( other->cachedJoint == nullptr )
        return result;
    }
  }
  return 0;
}


// ========================================================================
// ??9idMD6AnimEvent@@QBA_NABV0@@Z
// EA  : 0x8283A558
// RVA : 0x0083A558
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

BOOL __fastcall idMD6AnimEvent::operator!=(idMD6AnimEvent *this, const idMD6AnimEvent *other)
{
  return (_cntlzw((unsigned __int8)idMD6AnimEvent::operator==(this, other)) & 0x20) != 0;
}


// ========================================================================
// ??0idMD6AnimEvent@@QAA@XZ
// EA  : 0x8283AA08
// RVA : 0x0083AA08
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

idMD6AnimEvent *__fastcall idMD6AnimEvent::idMD6AnimEvent(idMD6AnimEvent *this)
{
  this->args.numArgs = 0;
  this->args.argSize = 0;
  this->args.buffSize = 0;
  this->args.args = nullptr;
  this->args.argOffsets[0] = 0;
  this->args.argOffsets[1] = 0;
  this->args.argOffsets[2] = 0;
  this->args.argOffsets[3] = 0;
  *(_WORD *)this->args.argTypes = 0;
  *(_WORD *)&this->args.argTypes[2] = 0;
  *(_WORD *)this->args.argExTypes = 0;
  *(_WORD *)&this->args.argExTypes[2] = 0;
  idVarArgs<4>::Grow(this: &this->args, newArgSize: 0);
  this->cachedJoint = nullptr;
  this->eventNum = -1;
  this->frameNum = 0;
  idAnimEvents::GetNextEventId(result: &this->eventId);
  this->locked = false;
  this->row = 0;
  return this;
}


// ========================================================================
// __unwind$220830_1
// EA  : 0x8283AA88
// RVA : 0x0083AA88
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220830_1()
{
  int v0; // r12

  idVarArgs<4>::~idVarArgs<4>(this: *(idVarArgs<4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Copy@idMD6AnimEvent@@QAAXABV1@@Z
// EA  : 0x8283AAB0
// RVA : 0x0083AAB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void __fastcall idMD6AnimEvent::Copy(idMD6AnimEvent *this, const idMD6AnimEvent *other)
{
  idCachedJoint *cachedJoint; // r10
  idCachedJoint *v5; // r4
  idCachedJoint *v6; // r11
  idCachedJoint *v7; // r3
  _DWORD *p_w; // r10
  _DWORD *v9; // r11
  int i; // ctr

  if ( other != this )
  {
    cachedJoint = other->cachedJoint;
    if ( cachedJoint != nullptr )
    {
      v6 = this->cachedJoint;
      if ( v6 != nullptr )
      {
        v6->jointIndex.value = cachedJoint->jointIndex.value;
        v6->frameNum = cachedJoint->frameNum;
        v6->trans.x = cachedJoint->trans.x;
        v6->trans.y = cachedJoint->trans.y;
        v6->trans.z = cachedJoint->trans.z;
        v6->rot.x = cachedJoint->rot.x;
        v6->rot.y = cachedJoint->rot.y;
        v6->rot.z = cachedJoint->rot.z;
        v6->rot.w = cachedJoint->rot.w;
      }
      else
      {
        v7 = (idCachedJoint *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\skeletalanimation\\MD6AnimEvent.cpp(138) : TAG_MD6_JOINTCACHE",
                                size: 0x20u,
                                tag: TAG_MD6_JOINTCACHE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        if ( v7 != nullptr )
        {
          p_w = (_DWORD *)&v7[-1].rot.w;
          v9 = (_DWORD *)&other->cachedJoint[-1].rot.w;
          for ( i = 8; i != 0; --i )
            *++p_w = *++v9;
          this->cachedJoint = v7;
        }
        else
        {
          this->cachedJoint = nullptr;
        }
      }
    }
    else
    {
      v5 = this->cachedJoint;
      if ( v5 != nullptr )
      {
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
        this->cachedJoint = nullptr;
      }
    }
    idVarArgs<4>::Copy(this: &this->args, other: &other->args);
    this->eventNum = other->eventNum;
    this->frameNum = other->frameNum;
    this->eventId.value = other->eventId.value;
    this->locked = other->locked;
    this->row = other->row;
  }
}


// ========================================================================
// ?Parse@idMD6AnimEvent@@QAA_NPBVidDeclMD6@@AAVidParser@@AAH@Z
// EA  : 0x8283AC18
// RVA : 0x0083AC18
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

int __fastcall idMD6AnimEvent::Parse(
        idMD6AnimEvent *this,
        idIndex<short,enum invalidJointIndex_t> *md6,
        idParser *src,
        int *loadErrors)
{
  __int16 EventNumForName; // r3
  int v9; // r15
  const char *EventNameForNum; // r3
  const idEventDef *Event; // r3
  idLexer *scriptstack; // r11
  idEventDef *v13; // r18
  char v14; // r8
  int v15; // r28
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  unsigned __int8 v19; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  va *v22; // r3
  int value; // r30
  unsigned __int8 v24; // r29
  const enumValueInfo_t *v25; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  va *v28; // r3
  double v29; // fp1
  unsigned __int8 v30; // r4
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  va *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  va *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  idDeclInfo *v42; // r29
  __int64 v43; // r10
  __int64 v44; // r8
  va *v45; // r3
  const idDecl *v46; // r30
  const enumTypeInfo_t *EnumInfo; // r30
  __int64 v48; // r10
  __int64 v49; // r8
  va *v50; // r3
  const enumValueInfo_t *EnumValueInfo; // r3
  va *v52; // r3
  int v53; // r30
  idDeclSource *v54; // r3
  char *FileName; // r5
  const char *v57; // r5
  int v58; // [sp+8h] [-1268h]
  int v59; // [sp+Ch] [-1264h]
  int v60; // [sp+10h] [-1260h]
  int v61; // [sp+14h] [-125Ch]
  int v62; // [sp+18h] [-1258h]
  int v63; // [sp+1Ch] [-1254h]
  unsigned __int16 v64; // [sp+50h] [-1220h] BYREF
  idEventDef *v65; // [sp+54h] [-121Ch]
  int line; // [sp+58h] [-1218h]
  idToken v67; // [sp+60h] [-1210h] BYREF
  idStr v68; // [sp+B0h] [-11C0h] BYREF
  const char *v69; // [sp+D0h] [-11A0h]
  const char *v70; // [sp+D4h] [-119Ch]
  const char *v71; // [sp+D8h] [-1198h]
  const char *v72; // [sp+DCh] [-1194h]
  const char *v73; // [sp+E0h] [-1190h]
  const char *v74; // [sp+E4h] [-118Ch]
  const char *v75; // [sp+E8h] [-1188h]
  const char *v76; // [sp+ECh] [-1184h]
  const char *v77; // [sp+F0h] [-1180h]
  idDeclMD6 v78[5]; // [sp+F4h] [-117Ch] BYREF

  v67.len = 0;
  v67.data = v67.baseBuffer;
  v67.floatvalue = -3.4028235e38;
  v67.allocedAndFlag = 20;
  v67.baseBuffer[0] = 0;
  v67.intvalue = 0;
  memset(&v67.whiteSpaceStart_p, 0, 12);
  idParser::ReadToken(this: src, token: &v67);
  idStr::idStr(this: (idStr *)&v78[0].numLoadErrors, text: &v67);
  EventNumForName = idEventDef::GetEventNumForName(name: v67.data);
  this->eventNum = EventNumForName;
  if ( EventNumForName < 0 )
  {
    ++*loadErrors;
    if ( md6 != nullptr )
      v57 = *(const char **)&md6[4].value;
    else
      v57 = "< NULL >";
    idLib::Warning(fmt: "Unmatched frame command name '%s' in md6 '%s'", v67.data, v57);
    idParser::SkipBracedSection(this: src, parseFirstBrace: true);
    idStr::FreeData(this: (idStr *)&v78[0].numLoadErrors);
    idStr::FreeData(this: &v67);
    return 0;
  }
  else
  {
    v9 = 1;
    EventNameForNum = idEventDef::GetEventNameForNum(eventNum: EventNumForName);
    Event = idEventDef::FindEvent(name: EventNameForNum);
    scriptstack = src->scriptstack;
    v65 = Event;
    if ( scriptstack != nullptr )
      line = scriptstack->line;
    else
      line = 0;
    idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v67);
    v69 = "jointName";
    v78[0].trackedMemory = (int)"joint";
    v77 = "animalias";
    v72 = "Error unknown event arg: '%s' while parsing md6 anim event %s block in %s.";
    v75 = "Invalid argument for event arg %d: found string, expected %s.";
    v76 = "string";
    v73 = "Invalid argument for event arg %d: found angles, expected %s.";
    v78[0].resourceListPtr = (idResourceList *)"angles";
    v71 = "vec3";
    v70 = "Error unknown event enum value: '%s::%s' while parsing md6 anim event %s block in %s.";
    v78[0].resourceError = "frame command '%s' references unknown decl '%s', type '%s'";
    v13 = v65;
    v78[0].name.str = "Invalid argument for event arg %d: found enum, expected %s.";
    v74 = "frame command '%s' references unknown joint '%s'";
    v78[0].networkID = (int)"float";
    v78[0].nextOnHashChain = (idResource *)"bool";
    while ( idParser::ReadToken(this: src, token: &v67) && (v67.type != 5 || v67.subtype != 47) )
    {
      if ( idStr::Icmp(s1: v67.data, s2: "frame") != 0
        && idStr::Icmp(s1: v67.data, s2: "row") != 0
        && idStr::Icmp(s1: v67.data, s2: "locked") != 0 )
      {
        v14 = v13->formatspec[v9];
        v68.allocedAndFlag = 20;
        v68.data = v68.baseBuffer;
        v15 = v14;
        v68.len = 0;
        v68.baseBuffer[0] = 0;
        idEventDef::GetArgTypeName(this: v13, arg: v9, typeName: &v68);
        if ( idStr::Icmp(s1: v67.data, s2: (const char *)v78[0].nextOnHashChain) != 0 )
        {
          if ( idStr::Icmp(s1: v67.data, s2: "int") != 0 )
          {
            if ( idStr::Icmp(s1: v67.data, s2: (const char *)v78[0].networkID) != 0 )
            {
              if ( idStr::Icmp(s1: v67.data, s2: v71) != 0 )
              {
                if ( idStr::Icmp(s1: v67.data, s2: (const char *)v78[0].resourceListPtr) != 0 )
                {
                  if ( idStr::Icmp(s1: v67.data, s2: v76) != 0 )
                  {
                    if ( idStr::Icmp(s1: v67.data, s2: v77) != 0 )
                    {
                      if ( idStr::Icmp(s1: v67.data, s2: (const char *)v78[0].trackedMemory) != 0
                        && idStr::Icmp(s1: v67.data, s2: v69) != 0 )
                      {
                        v42 = declManager->GetDeclType(this: declManager, a2: v67.data);
                        if ( v42 != nullptr )
                        {
                          if ( v15 != 100 )
                          {
                            v45 = va::va(
                                    this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                                    fmt: "Invalid argument for event arg %d: found int, expected %s.",
                                    a3: __SPAIR64__(v9, (unsigned int)v68.data),
                                    a4: v44,
                                    a5: v43,
                                    a6: v58,
                                    a7: v59,
                                    a8: v60,
                                    a9: v61,
                                    a10: v62,
                                    a11: v63);
                            idParser::Error(this: src, str: v45->buffer);
                          }
                          idParser::ReadToken(this: src, token: &v67);
                          if ( v67.data != nullptr )
                            v46 = idDeclInfo::FindWithInheritance(this: v42, name: v67.data, makeDefault: false);
                          else
                            v46 = nullptr;
                          idVarArgs<4>::AddHandleArg(this: &this->args, val: (const int)v46, type: 9u, exType: 0);
                          if ( v46 == nullptr && v67.len != 0 )
                            idLib::Warning(
                              fmt: v78[0].resourceError,
                              v78[0].jointGroupCollection.jointGroups.list,
                              v67.data,
                              v42->name);
                        }
                        else
                        {
                          EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: v67.data);
                          if ( EnumInfo != nullptr )
                          {
                            if ( v15 != 105 )
                            {
                              v50 = va::va(
                                      this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                                      fmt: v78[0].name.str,
                                      a3: __SPAIR64__(v9, (unsigned int)v68.data),
                                      a4: v49,
                                      a5: v48,
                                      a6: v58,
                                      a7: v59,
                                      a8: v60,
                                      a9: v61,
                                      a10: v62,
                                      a11: v63);
                              idParser::Error(this: src, str: v50->buffer);
                            }
                            v78[0].referenceBounds.b[0].x = -3.4028235e38;
                            v78[0].model = nullptr;
                            v78[0].parent.len = (int)&v78[0].parent.allocedAndFlag;
                            v78[0].parent.data = (char *)20;
                            HIBYTE(v78[0].parent.allocedAndFlag) = 0;
                            *(_DWORD *)&v78[0].declsToIncludeAnimDataFrom.granularity = 0;
                            v78[0].referenceBounds.b[0].y = 0.0;
                            v78[0].referenceBounds.b[0].z = 0.0;
                            v78[0].referenceBounds.b[1].x = 0.0;
                            idParser::ReadToken(this: src, token: (idToken *)&v78[0].model);
                            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                                              this: typeInfoTools,
                                              enumInfo: EnumInfo,
                                              name: (const char *)v78[0].parent.len,
                                              defaultIfNotFound: true);
                            if ( EnumValueInfo != nullptr )
                              idVarArgs<4>::AddArg(this: &this->args, val: EnumValueInfo->value, exType: 3u);
                            else
                              idLib::Warning(
                                fmt: v70,
                                EnumInfo->name,
                                v78[0].parent.len,
                                v13->name,
                                *(_DWORD *)&md6[4].value);
                            idStr::FreeData(this: (idStr *)&v78[0].model);
                          }
                          else
                          {
                            v78[0].staleCount = 0;
                            HIBYTE(v78[0].textLength) = 0;
                            *((_DWORD *)&v78[0].idResource + 8) = &v78[0].textLength;
                            v78[0].textSource = (char *)20;
                            idParser::ParseRestOfLine(this: src, out: (idStr *)&v78[0].staleCount);
                            idLib::Warning(fmt: v72, v67.data, v13->name, *(_DWORD *)&md6[4].value);
                            idStr::FreeData(this: (idStr *)&v78[0].staleCount);
                          }
                        }
                      }
                      else
                      {
                        if ( v15 != 50 )
                        {
                          v52 = va::va(
                                  this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                                  fmt: "Invalid argument for event arg %d: found jointName, expected %s.",
                                  a3: __SPAIR64__(v9, (unsigned int)v68.data),
                                  a4: v41,
                                  a5: v40,
                                  a6: v58,
                                  a7: v59,
                                  a8: v60,
                                  a9: v61,
                                  a10: v62,
                                  a11: v63);
                          idParser::Error(this: src, str: v52->buffer);
                        }
                        idParser::ReadToken(this: src, token: &v67);
                        v53 = SHIWORD(idDeclMD6::GetJointIndex(this: v78, result: md6, jointName: v67.data)->__vftable);
                        if ( v53 == -1 )
                          idLib::Warning(fmt: v74, v78[0].jointGroupCollection.jointGroups.list, v67.data);
                        idVarArgs<4>::AddArg(this: &this->args, val: v53, exType: 1u);
                      }
                    }
                    else
                    {
                      idParser::ReadToken(this: src, token: &v67);
                      ((void (__fastcall *)(unsigned __int16 *))animation->AddStrongAliasRef)(a1: &v64);
                      idVarArgs<4>::AddHandleArg(this: &this->args, val: v64, type: 0xDu, exType: 0);
                    }
                  }
                  else
                  {
                    if ( v15 != 115 && v15 != 50 && v15 != 53 && v15 != 49 )
                    {
                      v39 = va::va(
                              this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                              fmt: v75,
                              a3: __SPAIR64__(v9, (unsigned int)v68.data),
                              a4: v38,
                              a5: v37,
                              a6: v58,
                              a7: v59,
                              a8: v60,
                              a9: v61,
                              a10: v62,
                              a11: v63);
                      idParser::Error(this: src, str: v39->buffer);
                    }
                    idParser::ReadToken(this: src, token: &v67);
                    idVarArgs<4>::AddArg(this: &this->args, val: v67.data, exType: 0);
                  }
                }
                else
                {
                  if ( v15 != 97 )
                  {
                    v36 = va::va(
                            this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                            fmt: v73,
                            a3: __SPAIR64__(v9, (unsigned int)v68.data),
                            a4: v35,
                            a5: v34,
                            a6: v58,
                            a7: v59,
                            a8: v60,
                            a9: v61,
                            a10: v62,
                            a11: v63);
                    idParser::Error(this: src, str: v36->buffer);
                  }
                  idParser::Parse1DMatrix(
                    this: src,
                    x: 3,
                    m: (float *)&v78[0].jointGroupCollection.jointGroupsByType[1].granularity);
                  idVarArgs<4>::AddArg(
                    this: &this->args,
                    val: (const idAngles *)&v78[0].jointGroupCollection.jointGroupsByType[1].granularity,
                    exType: 0);
                }
              }
              else
              {
                if ( v15 != 118 )
                {
                  v33 = va::va(
                          this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                          fmt: "Invalid argument for event arg %d: found vector, expected %s.",
                          a3: __SPAIR64__(v9, (unsigned int)v68.data),
                          a4: v32,
                          a5: v31,
                          a6: v58,
                          a7: v59,
                          a8: v60,
                          a9: v61,
                          a10: v62,
                          a11: v63);
                  idParser::Error(this: src, str: v33->buffer);
                }
                idParser::Parse1DMatrix(
                  this: src,
                  x: 3,
                  m: (float *)&v78[0].jointGroupCollection.jointGroupsByType[0].granularity);
                idVarArgs<4>::AddArg(
                  this: &this->args,
                  val: (const idVec3 *)&v78[0].jointGroupCollection.jointGroupsByType[0].granularity,
                  exType: 0);
              }
            }
            else
            {
              if ( v15 != 102 )
              {
                v28 = va::va(
                        this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                        fmt: "Invalid argument for event arg %d: found float, expected %s.",
                        a3: __SPAIR64__(v9, (unsigned int)v68.data),
                        a4: v27,
                        a5: v26,
                        a6: v58,
                        a7: v59,
                        a8: v60,
                        a9: v61,
                        a10: v62,
                        a11: v63);
                idParser::Error(this: src, str: v28->buffer);
              }
              v29 = idParser::ParseFloat(this: src, errorFlag: nullptr);
              idVarArgs<4>::AddArg(this: &this->args, val: v29, exType: v30, a4: 0);
            }
          }
          else
          {
            if ( v15 != 105 )
            {
              v22 = va::va(
                      this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                      fmt: "Invalid argument for event arg %d: found int, expected %s.",
                      a3: __SPAIR64__(v9, (unsigned int)v68.data),
                      a4: v21,
                      a5: v20,
                      a6: v58,
                      a7: v59,
                      a8: v60,
                      a9: v61,
                      a10: v62,
                      a11: v63);
              idParser::Error(this: src, str: v22->buffer);
            }
            value = idParser::ParseInt(this: src);
            v24 = 0;
            if ( idStr::Cmp(s1: v68.data, s2: "int") != 0 )
            {
              v25 = idTypeInfoTools::FindEnumValueInfo(
                      this: typeInfoTools,
                      enumName: v68.data,
                      value,
                      defaultIfNotFound: true);
              if ( v25 != nullptr )
              {
                value = v25->value;
                v24 = 3;
              }
            }
            idVarArgs<4>::AddArg(this: &this->args, val: value, exType: v24);
          }
        }
        else
        {
          if ( v15 != 98 )
          {
            v18 = va::va(
                    this: (va *)&v78[0].jointGroupCollection.jointGroupsByType[2].granularity,
                    fmt: "Invalid argument for event arg %d: found int, expected %s.",
                    a3: __SPAIR64__(v9, (unsigned int)v68.data),
                    a4: v17,
                    a5: v16,
                    a6: v58,
                    a7: v59,
                    a8: v60,
                    a9: v61,
                    a10: v62,
                    a11: v63);
            idParser::Error(this: src, str: v18->buffer);
          }
          v19 = idParser::ParseBool(this: src);
          idVarArgs<4>::AddArg(this: &this->args, val: v19, exType: 0);
        }
        ++v9;
        idStr::FreeData(this: &v68);
      }
      else if ( idStr::Icmp(s1: v67.data, s2: "frame") != 0 )
      {
        if ( idStr::Icmp(s1: v67.data, s2: "row") != 0 )
        {
          if ( idStr::Icmp(s1: v67.data, s2: "locked") == 0 )
            this->locked = idParser::ParseInt(this: src) != 0;
        }
        else
        {
          this->row = idParser::ParseInt(this: src);
        }
      }
      else
      {
        this->frameNum = idParser::ParseInt(this: src);
      }
    }
    if ( v13->numargs - 1 != this->args.numArgs )
    {
      if ( md6 != nullptr && function_t::Name(this: (idDecl *)md6) != nullptr )
      {
        v54 = function_t::Name(this: (idDecl *)md6);
        FileName = idDeclSource::GetFileName(this: v54);
      }
      else
      {
        FileName = "NULL";
      }
      idLib::Warning(
        fmt: "event '%s', %s(line %d), has %d args, expecting %d",
        v13->name,
        FileName,
        line,
        this->args.numArgs,
        v13->numargs - 1);
    }
    idStr::FreeData(this: (idStr *)&v78[0].numLoadErrors);
    idStr::FreeData(this: &v67);
    return 1;
  }
}


// ========================================================================
// $M221654_1
// EA  : 0x8283B6AC
// RVA : 0x0083B6AC
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void *_M221654_1()
{
  int v0; // r12
  int v1; // r31
  const char **v2; // r9

  v1 = v0 - 4720;
  v2 = *(const char ***)(v0 - 4720 + 84);
  ++**(_DWORD **)(v0 - 4720 + 4764);
  idLib::Warning(fmt: "Error '%s' while parsing md6 anim event block, %s.", idException::error, *v2);
  idParser::SkipBracedSection(this: *(idParser **)(v1 + 4756), parseFirstBrace: false);
  return &_LN70;
}


// ========================================================================
// __unwind$220907
// EA  : 0x8283B70C
// RVA : 0x0083B70C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220907()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 96));
}


// ========================================================================
// __unwind$220908
// EA  : 0x8283B734
// RVA : 0x0083B734
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220908()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 384));
}


// ========================================================================
// __unwind$220909
// EA  : 0x8283B75C
// RVA : 0x0083B75C
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220909()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 176));
}


// ========================================================================
// __unwind$220910
// EA  : 0x8283B784
// RVA : 0x0083B784
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220910()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 304));
}


// ========================================================================
// __unwind$220911
// EA  : 0x8283B7AC
// RVA : 0x0083B7AC
// PDB : w:\tech5\engine\models\skeletalanimation\md6animevent.cpp
// ========================================================================

void _unwind_220911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4720 + 272));
}

