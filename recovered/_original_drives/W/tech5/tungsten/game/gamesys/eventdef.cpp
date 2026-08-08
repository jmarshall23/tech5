
// ========================================================================
// ?GetNumEvents@idEventDef@@SAHXZ
// EA  : 0x82D5F848
// RVA : 0x00D5F848
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

int __fastcall idEventDef::GetNumEvents()
{
  return idEventDef::numEventDefs;
}


// ========================================================================
// ?GetEventCommand@idEventDef@@SAPBV1@H@Z
// EA  : 0x82D5F858
// RVA : 0x00D5F858
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

const idEventDef *__fastcall idEventDef::GetEventCommand(unsigned int eventnum)
{
  if ( eventnum < 0x1000 )
    return idEventDef::eventDefList[eventnum];
  idLib::Warning(fmt: "Event command out of range %i", eventnum);
  return nullptr;
}


// ========================================================================
// ?FindEvent@idEventDef@@SAPBV1@PBD@Z
// EA  : 0x82D5F8B8
// RVA : 0x00D5F8B8
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

const idEventDef *__fastcall idEventDef::FindEvent(const char *name)
{
  int v1; // r6
  idEventDef **i; // r8
  const char *v3; // r11
  const char *v4; // r10
  int v5; // r9
  int v6; // r9
  bool v7; // zf

  v1 = 0;
  if ( idEventDef::numEventDefs <= 0 )
    return nullptr;
  for ( i = idEventDef::eventDefList; ; ++i )
  {
    v3 = name;
    v4 = (*i)->name;
    do
    {
      v5 = *(unsigned __int8 *)v3;
      v7 = v5 == 0;
      v6 = v5 - *(unsigned __int8 *)v4;
      if ( v7 )
        break;
      ++v3;
      ++v4;
    }
    while ( v6 == 0 );
    if ( v6 == 0 )
      break;
    if ( ++v1 >= idEventDef::numEventDefs )
      return nullptr;
  }
  return *i;
}


// ========================================================================
// ?GetArgTypeName@idEventDef@@QBA_NHAAVidStr@@@Z
// EA  : 0x82D5F930
// RVA : 0x00D5F930
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

int __fastcall idEventDef::GetArgTypeName(idEventDef *this, int arg, idStr *typeName)
{
  const char *argTypes; // r3
  int v7; // r30
  int v8; // r31
  int v9; // r3
  size_t v11; // r30
  char v12[304]; // [sp+50h] [-130h] BYREF

  argTypes = this->argTypes;
  if ( argTypes == nullptr )
    return 0;
  v7 = 0;
  v8 = 0;
  v9 = idStr::Find(str: argTypes, c: 59, start: 0, end: -1);
  if ( v9 == -1 )
    return 0;
  while ( v7 != arg )
  {
    v8 = v9 + 1;
    ++v7;
    v9 = idStr::Find(str: this->argTypes, c: 59, start: v9 + 1, end: -1);
    if ( v9 == -1 )
      return 0;
  }
  v11 = v9 - v8;
  if ( (unsigned int)(v9 - v8) > 0xFF )
    v11 = 255;
  memcpy(Dst: v12, Src: &this->argTypes[v8], Size: v11);
  v12[v11] = 0;
  idStr::operator=(this: typeName, text: v12);
  return 1;
}


// ========================================================================
// ??0idEventDef@@QAA@W4eventType_t@@PBD_N2111DPBV0@@Z
// EA  : 0x82D5F9F8
// RVA : 0x00D5F9F8
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

idEventDef *__fastcall idEventDef::idEventDef(
        idEventDef *this,
        eventType_t type,
        const char *command,
        bool canSkip,
        bool isClientSafe,
        const char *formatspec,
        const char *argTypes,
        const char *argNames,
        char returnType,
        const idEventDef *noticeEventDef,
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
        char a28,
        int a29,
        const idEventDef *a30)
{
  idEventDef *v30; // r31
  const char *v32; // r29
  int v33; // r11
  int v34; // r10
  unsigned int v35; // r11
  int v36; // r7
  int v37; // r11
  idEventDef **v38; // r8
  idEventDef *v39; // r30
  const char *v40; // r11
  const char *name; // r10
  int v42; // r9
  int v43; // r9
  bool v44; // zf
  int v45; // r11
  unsigned __int8 *v46; // r7
  const char *v47; // r7
  unsigned __int8 *v48; // r7

  v30 = this;
  v32 = formatspec;
  this->noticeEvent = a30;
  if ( formatspec == nullptr )
    v32 = &byte_8200D768;
  v33 = 0;
  this->name = command;
  this->formatspec = v32;
  this->argTypes = argTypes;
  this->argNames = argNames;
  this->returnType = a28;
  this->type = type;
  this->canSkip = canSkip;
  this->isClientSafe = isClientSafe;
  if ( *v32 != 0 )
  {
    do
      ++v33;
    while ( v32[v33] != 0 );
  }
  this->numargs = v33;
  if ( v33 > 8 )
  {
    eventError = true;
    sprintf_0(string: eventErrorMsg, format: "idEventDef::idEventDef : Too many args for '%s' event.", command);
    return v30;
  }
  v34 = 0;
  this->numstrings = 0;
  if ( v33 > 0 )
  {
    while ( 1 )
    {
      v35 = (unsigned __int8)v32[v34];
      if ( v35 <= 0x35 )
        break;
      if ( v35 == 115 )
        goto LABEL_14;
LABEL_15:
      if ( ++v34 >= this->numargs )
        goto LABEL_16;
    }
    if ( v35 != 53 && (v35 < 0x31 || v35 > 0x32) )
      goto LABEL_15;
LABEL_14:
    ++this->numstrings;
    goto LABEL_15;
  }
LABEL_16:
  v36 = 0;
  v37 = idEventDef::numEventDefs;
  this->eventnum = idEventDef::numEventDefs;
  if ( v37 <= 0 )
  {
LABEL_23:
    v45 = idEventDef::numEventDefs;
    if ( idEventDef::numEventDefs < 4096 )
    {
      ++idEventDef::numEventDefs;
      idEventDef::eventDefList[v45] = this;
    }
    else
    {
      eventError = true;
      sprintf_0(string: eventErrorMsg, format: "numEventDefs >= MAX_EVENTS", idEventDef::eventDefList);
      return v30;
    }
  }
  else
  {
    v38 = idEventDef::eventDefList;
    while ( 1 )
    {
      v39 = *v38;
      v40 = command;
      name = (*v38)->name;
      do
      {
        v42 = *(unsigned __int8 *)v40;
        v44 = v42 == 0;
        v43 = v42 - *(unsigned __int8 *)name;
        if ( v44 )
          break;
        ++v40;
        ++name;
      }
      while ( v43 == 0 );
      if ( v43 == 0 )
        break;
      ++v36;
      ++v38;
      if ( v36 >= this->eventnum )
        goto LABEL_23;
    }
    v46 = (unsigned __int8 *)v39->type;
    if ( v46 == (unsigned __int8 *)type )
    {
      if ( idStr::Cmp(s1: v32, s2: v39->formatspec) != 0 )
      {
        v47 = v39->formatspec;
        eventError = true;
        sprintf_0(
          string: eventErrorMsg,
          format: "idEvent '%s' defined twice with same name but differing format strings ('%s'!='%s').",
          command,
          v32,
          v47);
        return v30;
      }
      else
      {
        v48 = (unsigned __int8 *)v39->returnType;
        if ( v48 == (unsigned __int8 *)a28 )
        {
          v30->eventnum = v39->eventnum;
        }
        else
        {
          eventError = true;
          sprintf_0(
            string: eventErrorMsg,
            format: "idEvent '%s' defined twice with same name but differing return types ('%c'!='%c').",
            command,
            a28,
            v48);
        }
        return v30;
      }
    }
    else
    {
      eventError = true;
      sprintf_0(
        string: eventErrorMsg,
        format: "idEvent '%s' defined twice with same name but differing types ('%c'!='%c').",
        command,
        type,
        v46);
      return v30;
    }
  }
  return this;
}


// ========================================================================
// ?GetEventNumForName@idEventDef@@SAHPBD@Z
// EA  : 0x82D5FCA8
// RVA : 0x00D5FCA8
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

int __fastcall idEventDef::GetEventNumForName(const char *name)
{
  const idEventDef *Event; // r3

  Event = idEventDef::FindEvent(name);
  if ( Event != nullptr )
    return Event->eventnum;
  else
    return -1;
}


// ========================================================================
// ?GetEventNameForNum@idEventDef@@SAPBDH@Z
// EA  : 0x82D5FCE8
// RVA : 0x00D5FCE8
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

const char *__fastcall idEventDef::GetEventNameForNum(unsigned int eventNum)
{
  idEventDef *v1; // r11

  if ( eventNum >= 0x1000 )
  {
    idLib::Warning(fmt: "Event command out of range %i", eventNum);
    return nullptr;
  }
  else
  {
    v1 = idEventDef::eventDefList[eventNum];
    if ( v1 != nullptr )
      return v1->name;
    else
      return nullptr;
  }
}


// ========================================================================
// ?GetEventArgTypeName@idEventDef@@SA_NHHAAVidStr@@@Z
// EA  : 0x82D5FD68
// RVA : 0x00D5FD68
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

idEventDef *__fastcall idEventDef::GetEventArgTypeName(unsigned int eventNum, int argNum, idStr *argType)
{
  idEventDef *result; // r3

  if ( eventNum >= 0x1000 )
  {
    idLib::Warning(fmt: "Event command out of range %i", eventNum);
    return nullptr;
  }
  else
  {
    result = idEventDef::eventDefList[eventNum];
    if ( result != nullptr )
      return (idEventDef *)idEventDef::GetArgTypeName(this: result, arg: argNum, typeName: argType);
  }
  return result;
}


// ========================================================================
// ?InvalidDeclWarning@idEventDef@@SAXPBDPBVidDecl@@ABVidDeclInfo@@@Z
// EA  : 0x82D5FDE8
// RVA : 0x00D5FDE8
// PDB : w:\tech5\tungsten\game\gamesys\eventdef.cpp
// ========================================================================

void __fastcall idEventDef::InvalidDeclWarning(const char *eventName, const idDecl *decl, const idDeclInfo *declInfo)
{
  idDeclInfo *v5; // r3

  if ( decl != nullptr )
  {
    v5 = decl->GetDeclInfo(this: decl);
    idLib::Warning(
      fmt: "Incorrect decl type passed to event %s. Expected a %s but got a %s.",
      eventName,
      declInfo->name,
      v5->name);
  }
  else
  {
    idLib::Warning(fmt: "NULL decl passed from script.");
  }
}

