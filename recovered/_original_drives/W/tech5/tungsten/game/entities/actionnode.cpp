
// ========================================================================
// ?IsActionNodeAvailable@idActionNode@@QBA_NPBVidEntity@@@Z
// EA  : 0x82BE1900
// RVA : 0x00BE1900
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

int __fastcall idActionNode::IsActionNodeAvailable(idActionNode *this, const idEntity *user)
{
  int v5; // r9
  idAnimatedEntity *v6; // r3
  int v7; // r29
  int i; // r30
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3

  if ( !this->isActive )
    return 0;
  if ( this->touching.num != 0
    || (v5 = this->reservingEntity.spawnId.value, gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13)
    && (v6 = (idAnimatedEntity *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr
    && idAnimatedEntity::CastTo(c: v6) != nullptr )
  {
    if ( this->touching.num != 1 || idEntityPtr<idEntity const>::operator->(this: this->touching.list) != user )
    {
      v7 = 0;
      if ( this->touching.num > 0 )
      {
        for ( i = 0; ; ++i )
        {
          value = this->touching.list[i].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v11 = idEntity::CastTo(c: v10);
          }
          else
          {
            v11 = nullptr;
          }
          if ( !v11->IsDead(this: v11) )
            break;
          if ( ++v7 >= this->touching.num )
            return 1;
        }
        return 0;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?Event_Untouch@idActionNode@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82BE1A38
// RVA : 0x00BE1A38
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

idActionNode *__fastcall idActionNode::Event_Untouch(
        idActionNode *this,
        eventVoid *result,
        idEntity *toucher,
        int clipModelId)
{
  int v5; // r8
  idList<idEntityPtr<idEntity>,58> *v6; // r3
  int v7; // r4
  int v8; // r10
  int i; // r11

  if ( toucher != nullptr )
    v5 = (gameLocal->spawnIds.ptr[toucher->entityNumber] << 13) | toucher->entityNumber;
  else
    v5 = 0x1FFF;
  v6 = (idList<idEntityPtr<idEntity>,58> *)&result[892];
  v8 = *(_DWORD *)&result[896];
  v7 = 0;
  if ( v8 > 0 )
  {
    for ( i = 0; v6->list[i].spawnId.value != v5; ++i )
    {
      if ( ++v7 >= v8 )
        return this;
    }
    if ( v7 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: v6, index: v7);
  }
  return this;
}


// ========================================================================
// ?ReserveActionNode@idActionNode@@QAA_NPAVidAnimatedEntity@@@Z
// EA  : 0x82BE1AE0
// RVA : 0x00BE1AE0
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

int __fastcall idActionNode::ReserveActionNode(idActionNode *this, idAnimatedEntity *user)
{
  if ( (unsigned __int8)idActionNode::IsActionNodeAvailable(this, user) == 0 )
    return 0;
  if ( user != nullptr )
    this->reservingEntity.spawnId.value = (gameLocal->spawnIds.ptr[user->entityNumber] << 13) | user->entityNumber;
  else
    this->reservingEntity.spawnId.value = 0x1FFF;
  return 1;
}


// ========================================================================
// ?LeaveActionNode@idActionNode@@QAA_NPAVidAnimatedEntity@@@Z
// EA  : 0x82BE1B68
// RVA : 0x00BE1B68
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

int __fastcall idActionNode::LeaveActionNode(idActionNode *this, idAnimatedEntity *user)
{
  int value; // r10
  idAnimatedEntity *v5; // r3
  idAnimatedEntity *v6; // r3

  value = this->reservingEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idAnimatedEntity *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idAnimatedEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( user != v6 )
    return 0;
  this->reservingEntity.spawnId.value = 0x1FFF;
  return 1;
}


// ========================================================================
// ?DisableClip@idActionNode@@AAAXXZ
// EA  : 0x82BE1C00
// RVA : 0x00BE1C00
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void __fastcall idActionNode::DisableClip(idActionNode *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->DisableClip(this: v3);
  this->reservingEntity.spawnId.value = 0x1FFF;
  if ( this->touching.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  this->touching.num = __CFADD__(-this->touching.size, this->touching.size ^ 0x80000000) ? 0 : this->touching.size;
}


// ========================================================================
// ?OnActivate@idActionNode@@EAAXPAVidEntity@@@Z
// EA  : 0x82BE1CA8
// RVA : 0x00BE1CA8
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void __fastcall idActionNode::OnActivate(idActionNode *this, idEntity *activator)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r3

  if ( this->isActive )
  {
    this->isActive = false;
    idActionNode::DisableClip(this);
  }
  else
  {
    this->isActive = true;
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
    v4 = idEntity::GetPhysics(this);
    v4->EnableClip(this: v4);
  }
}


// ========================================================================
// ?Spawn@idActionNode@@QAAXXZ
// EA  : 0x82BE1DA8
// RVA : 0x00BE1DA8
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void __fastcall idActionNode::Spawn(idActionNode *this)
{
  idClipModel *v2; // r28
  idAAS2 *AAS; // r3
  idAAS2 *v4; // r30
  idAAS2_vtbl *v5; // r25
  int v6; // r3
  int v7; // r3
  float *p_z; // r10
  int v9; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  double z; // fp12
  double x; // fp10
  double y; // fp9
  idClipModel *v14; // r3
  idPhysics *Physics; // r3
  idPhysics *v16; // r3
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idBounds v20; // [sp+50h] [-680h] BYREF
  idClipModel *v21; // [sp+68h] [-668h]
  int v22; // [sp+70h] [-660h] BYREF
  idTraceModel v23; // [sp+90h] [-640h] BYREF

  if ( this->anims.num >= 32 )
    idLib::Error(fmt: "Action node '%s' has more than %d anims.", this->name.data, 32);
  v2 = nullptr;
  if ( this->shouldCheckAAS )
  {
    AAS = idGameLocal::LoadAAS(this: gameLocal, type: (const aasType_t)this->aasType);
    v4 = AAS;
    if ( AAS == nullptr || AAS->IsDefault(this: AAS) )
    {
      idLib::Warning(fmt: "idActionNode '%s' - failed to load appropriate AAS.", this->name.data);
    }
    else
    {
      v5 = v4->__vftable;
      v6 = (int)v4->DefaultSearchBounds(this: (idAAS2 *)&v22, result: (idBounds *)v4);
      if ( v5->PointReachableAreaNum(
             this: v4,
             a2: nullptr,
             a3: &this->spawnPosition,
             a4: (const idBounds *)v6,
             a5: 2,
             a6: 1) <= 0 )
      {
        v7 = (int)v4->GetSettings(this: v4);
        idLib::Warning(fmt: "idActionNode '%s' is outside of aas %s'", this->name.data, *(const char **)(v7 + 8));
      }
    }
  }
  if ( this->startOff )
    this->isActive = false;
  memset(&v23.type, 0, 20);
  p_z = &v23.offset.z;
  v9 = 6;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  v23.offset.x = 0.0;
  v23.offset.y = 0.0;
  v23.offset.z = 0.0;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v9;
  }
  while ( v9 != 0 );
  v23.radius = 0.0;
  z = this->clipModelInfo.size.z;
  x = this->clipModelInfo.size.x;
  v23.isConvex = false;
  y = this->clipModelInfo.size.y;
  v23.pad[2] = 0;
  v23.pad[1] = 0;
  v23.pad[0] = 0;
  v20.b[1].x = (float)x * (float)0.5;
  v20.b[1].y = (float)y * (float)0.5;
  v20.b[0].x = (float)x * (float)-0.5;
  v20.b[0].y = (float)y * (float)-0.5;
  v20.b[1].z = (float)((float)z * (float)0.5) + (float)((float)z * (float)0.5);
  v20.b[0].z = (float)((float)z * (float)-0.5) + (float)((float)z * (float)0.5);
  idTraceModel::SetupBox(this: &v23, boxBounds: &v20);
  v14 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v21 = v14;
  if ( v14 != nullptr )
    v2 = idClipModel::idClipModel(this: v14, clip: &clientGame->clip, trm: &v23, numTraceModels: 1, material: nullptr);
  Physics = idEntity::GetPhysics(this);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))Physics->SetClipModel)(a1: Physics, a2: v2, a3: 1.0);
  v16 = idEntity::GetPhysics(this);
  v16->SetContents(this: v16, a2: 0x4000, a3: -1);
  v17 = idEntity::GetPhysics(this);
  v17->SetClipMask(this: v17, a2: 0, a3: -1);
  v18 = idEntity::GetPhysics(this);
  v18->SetOrigin(this: v18, a2: &this->spawnPosition, a3: -1);
  v19 = idEntity::GetPhysics(this);
  v19->SetAxis(this: v19, a2: &this->spawnOrientation, a3: -1);
  if ( !this->isActive )
    idActionNode::DisableClip(this);
}


// ========================================================================
// $LN81_1
// EA  : 0x82BE20A8
// RVA : 0x00BE20A8
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _LN81_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1744 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Event_Touch@idActionNode@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82BE20D8
// RVA : 0x00BE20D8
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

idActionNode *__fastcall idActionNode::Event_Touch(
        idActionNode *this,
        eventVoid *result,
        idAI2 *toucher,
        int clipModelId)
{
  idAI2 *v7; // r30
  int v8; // r7
  int v9; // r9
  idList<idEntityPtr<idEntity>,58> *v10; // r3
  int v11; // r10
  int i; // r11
  idEntityPtr<idEntity> v14[12]; // [sp+50h] [-30h] BYREF

  v7 = idAI2::CastTo(c: toucher);
  if ( idPlayer::CastTo(c: (idPlayer *)toucher) != nullptr || *(_BYTE *)&result[885] != 0 && v7 != nullptr )
  {
    v8 = toucher != nullptr ? (gameLocal->spawnIds.ptr[toucher->entityNumber] << 13) | toucher->entityNumber : 0x1FFF;
    v9 = *(_DWORD *)&result[896];
    v10 = (idList<idEntityPtr<idEntity>,58> *)&result[892];
    v14[0].spawnId.value = v8;
    v11 = 0;
    if ( v9 <= 0 )
      goto LABEL_13;
    for ( i = 0; v10->list[i].spawnId.value != v8; ++i )
    {
      if ( ++v11 >= v9 )
      {
        idList<idEntityPtr<idEntity>,58>::Append(this: v10, obj: v14);
        return this;
      }
    }
    if ( v11 < 0 )
LABEL_13:
      idList<idEntityPtr<idEntity>,58>::Append(this: v10, obj: v14);
  }
  return this;
}


// ========================================================================
// ??0idActionNode@@QAA@XZ
// EA  : 0x82BE21C8
// RVA : 0x00BE21C8
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

idActionNode *__fastcall idActionNode::idActionNode(idActionNode *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idActionNode_vtbl *)&idActionNode::`vftable';
  this->reservingEntity.spawnId.value = 0x1FFF;
  this->groupName.len = 0;
  this->groupName.allocedAndFlag = 20;
  this->groupName.data = this->groupName.baseBuffer;
  this->groupName.baseBuffer[0] = 0;
  this->actionScript.granularity = 0;
  this->actionScript.listStatic = 0;
  this->actionScript.memTag = 5;
  this->actionScript.list = nullptr;
  this->actionScript.size = 0;
  this->actionScript.num = 0;
  this->standState = STANDSTATE_DEFAULT;
  this->sitState = SITSTATE_DEFAULT;
  this->posture = POSTURE_STANDING;
  this->anims.granularity = 0;
  this->anims.memTag = 5;
  this->anims.listStatic = 0;
  this->anims.list = nullptr;
  this->anims.size = 0;
  this->anims.num = 0;
  this->shouldCheckAAS = true;
  this->canBeBlockedByAI = false;
  this->aasType = AAS_MONSTER48;
  this->startOff = false;
  this->isActive = true;
  this->reachedPointTolerance = 0.1;
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  return this;
}


// ========================================================================
// __unwind$490151
// EA  : 0x82BE22DC
// RVA : 0x00BE22DC
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490151()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490152
// EA  : 0x82BE2304
// RVA : 0x00BE2304
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490152()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 804));
}


// ========================================================================
// __unwind$490153
// EA  : 0x82BE2330
// RVA : 0x00BE2330
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490153()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(*(_DWORD *)(v0 - 112 + 132) + 836));
}


// ========================================================================
// __unwind$490154_0
// EA  : 0x82BE235C
// RVA : 0x00BE235C
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490154_0()
{
  int v0; // r12

  idList<idActionNode::anim_t,5>::~idList<idActionNode::anim_t,5>(this: (idList<idActionNode::anim_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 864));
}


// ========================================================================
// ??1idActionNode@@UAA@XZ
// EA  : 0x82BE2390
// RVA : 0x00BE2390
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void __fastcall idActionNode::~idActionNode(idActionNode *this)
{
  idActionNode::anim_t *list; // r3
  char *v3; // r3

  this->__vftable = (idActionNode_vtbl *)&idActionNode::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  if ( this->anims.listStatic == 0 || this->anims.listStatic == 2 )
  {
    list = this->anims.list;
    if ( list != nullptr )
      idListArrayDelete<idPair<serverInfo_t,int>>(ptr: &list->animWebNode, num: this->anims.size);
    this->anims.list = nullptr;
    this->anims.size = 0;
  }
  this->anims.num = 0;
  if ( this->actionScript.listStatic == 0 || this->actionScript.listStatic == 2 )
  {
    v3 = (char *)this->actionScript.list;
    if ( v3 != nullptr )
      idListArrayDelete<idScriptAction>(ptr: v3, num: this->actionScript.size);
    this->actionScript.list = nullptr;
    this->actionScript.size = 0;
  }
  this->actionScript.num = 0;
  idStr::FreeData(this: &this->groupName);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$490520
// EA  : 0x82BE2440
// RVA : 0x00BE2440
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490520()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490521
// EA  : 0x82BE2468
// RVA : 0x00BE2468
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 804));
}


// ========================================================================
// __unwind$490522_0
// EA  : 0x82BE2494
// RVA : 0x00BE2494
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490522_0()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(*(_DWORD *)(v0 - 112 + 132) + 836));
}


// ========================================================================
// __unwind$490523_0
// EA  : 0x82BE24C0
// RVA : 0x00BE24C0
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void _unwind_490523_0()
{
  int v0; // r12

  idList<idActionNode::anim_t,5>::~idList<idActionNode::anim_t,5>(this: (idList<idActionNode::anim_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 864));
}


// ========================================================================
// `dynamic initializer for 'ai_debugActionNodes''
// EA  : 0x83374600
// RVA : 0x01374600
// PDB : w:\tech5\tungsten\game\entities\actionnode.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugActionNodes__()
{
  idCVar::idCVar(
    this: &ai_debugActionNodes,
    name: "ai_debugActionNodes",
    value: "0",
    flags: 2,
    description: "1 = debug actions node animation selection, 2 = verbose",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugActionNodes__);
}

