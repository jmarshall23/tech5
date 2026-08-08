
// ========================================================================
// ?Event_Get@idScriptList@@QAA?AVeventEntity@@H@Z
// EA  : 0x82EA0FE8
// RVA : 0x00EA0FE8
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

idScriptList *__fastcall idScriptList::Event_Get(idScriptList *this, eventEntity *result, int index)
{
  idEntity *value; // r5
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r4

  value = result[4].value;
  if ( index >= (int)value )
  {
    idLib::Error(fmt: "Script ERROR: Attempted to index a script list at %d when size is %d", index, value);
    JUMPOUT(0x82EA1090);
  }
  v6 = *((_DWORD *)&result[3].value->__vftable + index);
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
    && (v7 = gameLocal->entities.ptr[(int)*(&result[3].value->__vftable + index) & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v8);
  return this;
}


// ========================================================================
// ??0idScriptList@@QAA@XZ
// EA  : 0x82EA1098
// RVA : 0x00EA1098
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

idScriptList *__fastcall idScriptList::idScriptList(idScriptList *this)
{
  idLinkList<idScriptList> *head; // r5

  idEventReceiver::idEventReceiver(this: &this->idEventReceiver);
  this->__vftable = (idScriptList_vtbl *)&idScriptList::`vftable';
  this->mList.list = nullptr;
  this->mList.granularity = 0;
  this->mList.memTag = 58;
  this->mList.listStatic = 0;
  this->mList.size = 0;
  this->mList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mList);
  this->id = 0;
  this->scriptObj.owner = nullptr;
  this->scriptObj.head = &this->scriptObj;
  this->scriptObj.next = &this->scriptObj;
  this->scriptObj.prev = &this->scriptObj;
  this->scriptObj.owner = this;
  head = gameLocal->scriptTypes.head;
  this->scriptObj.prev->next = this->scriptObj.next;
  this->scriptObj.next->prev = this->scriptObj.prev;
  this->scriptObj.prev = &this->scriptObj;
  this->scriptObj.head = &this->scriptObj;
  this->scriptObj.next = head;
  this->scriptObj.prev = head->prev;
  head->prev = &this->scriptObj;
  this->scriptObj.prev->next = &this->scriptObj;
  this->scriptObj.head = head->head;
  this->isMember = false;
  return this;
}


// ========================================================================
// __unwind$488202_0
// EA  : 0x82EA1170
// RVA : 0x00EA1170
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

void _unwind_488202_0()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idScriptList@@UAA@XZ
// EA  : 0x82EA11A0
// RVA : 0x00EA11A0
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

void __fastcall idScriptList::~idScriptList(idScriptList *this)
{
  __int64 v2; // r8
  __int64 v3; // r6
  __int64 v4; // r10
  int i; // r11
  va *v6; // r3
  int v7; // [sp+8h] [-1078h]
  int v8; // [sp+Ch] [-1074h]
  int v9; // [sp+10h] [-1070h]
  int v10; // [sp+14h] [-106Ch]
  int v11; // [sp+18h] [-1068h]
  int v12; // [sp+1Ch] [-1064h]
  va v13; // [sp+60h] [-1020h] BYREF

  this->__vftable = (idScriptList_vtbl *)&idScriptList::`vftable';
  if ( cvarSystem->GetCVarInteger(this: cvarSystem, a2: "script_debug", a3: 0) == 1 )
  {
    LODWORD(v3) = 0;
    HIDWORD(v4) = 152036;
    LODWORD(v4) = gameLocal->scriptTypes.head;
    for ( i = *(_DWORD *)(v4 + 4); i != (_DWORD)v4; LODWORD(v3) = v3 + 1 )
      i = *(_DWORD *)(i + 4);
    HIDWORD(v3) = this->id;
    v6 = va::va(
           this: &v13,
           fmt: "Script: REMOVE LIST %d | TOTAL : %d\n",
           a3: v3,
           a4: v2,
           a5: v4,
           a6: v7,
           a7: v8,
           a8: v9,
           a9: v10,
           a10: v11,
           a11: v12);
    console->Print(this: console, a2: (const char *)v6);
  }
  this->scriptObj.prev->next = this->scriptObj.next;
  this->scriptObj.next->prev = this->scriptObj.prev;
  this->scriptObj.next = &this->scriptObj;
  this->scriptObj.prev = &this->scriptObj;
  this->scriptObj.head = &this->scriptObj;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->scriptObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mList);
  idEventReceiver::~idEventReceiver(this: &this->idEventReceiver);
}


// ========================================================================
// __unwind$488262
// EA  : 0x82EA12B8
// RVA : 0x00EA12B8
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

void _unwind_488262()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 4224 + 4244));
}


// ========================================================================
// __unwind$488263_0
// EA  : 0x82EA12E0
// RVA : 0x00EA12E0
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

void _unwind_488263_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 4224 + 4244) + 12));
}


// ========================================================================
// __unwind$488264_0
// EA  : 0x82EA130C
// RVA : 0x00EA130C
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

void _unwind_488264_0()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 4224 + 4244)
                                                                                           + 32));
}


// ========================================================================
// ?Event_Insert@idScriptList@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82EA1538
// RVA : 0x00EA1538
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

idScriptList *__fastcall idScriptList::Event_Insert(idScriptList *this, eventVoid *result, idEntity *toAdd, int index)
{
  int v7; // r5
  idEntityPtr<idEntity> v9[12]; // [sp+50h] [-30h] BYREF

  v7 = *(_DWORD *)&result[16];
  if ( index >= 0 )
  {
    if ( index >= v7 )
    {
      if ( index != v7 )
        idLib::Warning(
          fmt: "SCRIPT LIST: Attempted to insert at %d in a list that is %d long, appending instead",
          index,
          v7);
      if ( toAdd != nullptr )
        v9[0].spawnId.value = (gameLocal->spawnIds.ptr[toAdd->entityNumber] << 13) | toAdd->entityNumber;
      else
        v9[0].spawnId.value = 0x1FFF;
      idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&result[12], obj: v9);
      return this;
    }
    else
    {
      if ( toAdd != nullptr )
        v9[0].spawnId.value = (gameLocal->spawnIds.ptr[toAdd->entityNumber] << 13) | toAdd->entityNumber;
      else
        v9[0].spawnId.value = 0x1FFF;
      idList<idEntityPtr<idEntity>,58>::Insert(
        this: (idList<idEntityPtr<idAICombatHint>,5> *)&result[12],
        obj: (const idEntityPtr<idAICombatHint> *)v9,
        index);
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "SCRIPT LIST: Attempted to insert at %d in a list that is %d long", index, v7);
    return this;
  }
}


// ========================================================================
// ?Event_Copy@idScriptList@@QAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82EA1650
// RVA : 0x00EA1650
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

idScriptList *__fastcall idScriptList::Event_Copy(idScriptList *this, eventVoid *result, idScriptList *otherList)
{
  idList<idEntityPtr<idEntity>,58> *v5; // r28
  int v6; // r31
  int v7; // r30

  if ( otherList != nullptr )
  {
    v5 = (idList<idEntityPtr<idEntity>,58> *)&result[12];
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&result[12]);
    v6 = 0;
    if ( otherList->mList.num > 0 )
    {
      v7 = 0;
      do
      {
        idList<idEntityPtr<idEntity>,58>::Append(this: v5, obj: &otherList->mList.list[v7]);
        ++v6;
        ++v7;
      }
      while ( v6 < otherList->mList.num );
    }
  }
  return this;
}


// ========================================================================
// ?Event_AppendList@idScriptList@@QAA?AVeventVoid@@PAV1@@Z
// EA  : 0x82EA16C0
// RVA : 0x00EA16C0
// PDB : w:\tech5\tungsten\game\script\scripttype.cpp
// ========================================================================

idScriptList *__fastcall idScriptList::Event_AppendList(idScriptList *this, eventVoid *result, idScriptList *toAdd)
{
  int v5; // r27
  idList<idEntityPtr<idEntity>,58> *v6; // r31
  int v7; // r30
  idEntityPtr<idEntity> *list; // r29
  int granularity; // r4
  int size; // r11
  bool v11; // cr58
  signed int v12; // r10
  int v13; // r4
  int v14; // r11
  int num; // r11

  v5 = 0;
  if ( toAdd->mList.num > 0 )
  {
    v6 = (idList<idEntityPtr<idEntity>,58> *)&result[12];
    v7 = 0;
    do
    {
      list = toAdd->mList.list;
      if ( v6->list != nullptr )
        goto LABEL_7;
      granularity = v6->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<idEntityPtr<idPlayer>,5>::Resize(this: v6, newsize: granularity) != 0 )
      {
LABEL_7:
        size = v6->size;
        if ( v6->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v11 = (unsigned __int8)idList<idEntityPtr<idPlayer>,5>::Resize(this: v6, newsize: size + 1) == 0;
        }
        else
        {
          v12 = v6->granularity;
          if ( v6->granularity != 0 )
          {
            v14 = size + v12;
            __twllei(v12, 0);
            __twlgei(v12 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
            v11 = (unsigned __int8)idList<idEntityPtr<idPlayer>,5>::Resize(this: v6, newsize: v14 - v14 % v12) == 0;
          }
          else
          {
            v13 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v13 == 0 )
                v13 = 1;
              v11 = (unsigned __int8)idList<idEntityPtr<idPlayer>,5>::Resize(this: v6, newsize: v13) == 0;
            }
            else
            {
              v11 = (unsigned __int8)idList<idEntityPtr<idPlayer>,5>::Resize(this: v6, newsize: 0x7FFFFFFF) == 0;
            }
          }
        }
        if ( !v11 )
        {
LABEL_18:
          num = v6->num;
          if ( num < v6->size )
          {
            v6->list[num] = list[v7];
            ++v6->num;
          }
        }
      }
      ++v5;
      ++v7;
    }
    while ( v5 < toAdd->mList.num );
  }
  return this;
}

