
// ========================================================================
// ?IsPositionObstructed@idSpawnManager@@ABA_NABVidVec3@@V2@@Z
// EA  : 0x82EA6140
// RVA : 0x00EA6140
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

int __fastcall idSpawnManager::IsPositionObstructed(idSpawnManager *this, const idVec3 *pos, const idVec3 *size)
{
  double x; // fp11
  double y; // fp10
  double z; // fp9
  const char *ClipModelsTouchingBounds; // r27
  int v7; // r29
  idClipModel **i; // r30
  unsigned __int8 *v9; // r3
  unsigned __int8 *v10; // r31
  idBounds v12; // [sp+50h] [-D0h] BYREF
  idClipModel *v13[44]; // [sp+70h] [-B0h] BYREF

  x = pos->x;
  y = pos->y;
  z = pos->z;
  v12.b[1].z = pos->z + *(float *)&size;
  v12.b[0].z = z;
  v12.b[1].x = (float)x + (float)(*(float *)&pos * (float)0.5);
  v12.b[1].y = (float)y + (float)(*(float *)&size * (float)0.5);
  v12.b[0].x = (float)x + (float)-(float)(*(float *)&pos * (float)0.5);
  v12.b[0].y = (float)y + (float)-(float)(*(float *)&size * (float)0.5);
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: &clientGame->clip,
                               bounds: &v12,
                               clipMask: 107529,
                               clipModelList: v13,
                               maxCount: (const char *)0x20);
  v7 = 0;
  if ( (int)ClipModelsTouchingBounds <= 0 )
    return 0;
  for ( i = v13; ; ++i )
  {
    v9 = (unsigned __int8 *)idActor::CastTo(c: (idActor *)gameLocal->entities.ptr[(*i)->entityNumber]);
    v10 = v9;
    if ( v9 != nullptr && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v9) == 0 && (v10[93] & 0x80) == 0 )
      break;
    if ( ++v7 >= (int)ClipModelsTouchingBounds )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?JitterAndSort@idSpawnManager@@AAAXAAVContext@1@@Z
// EA  : 0x82EA6328
// RVA : 0x00EA6328
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::JitterAndSort(idSpawnManager *this, idSpawnManager::Context *context)
{
  idSort_Quick<idSpawnLocation,idSort_LocationValue>_vtbl *v2; // r6
  int v4; // r9
  idSpawnLocation *list; // r7
  int v6; // r10
  idSpawnLocation *v7; // r8
  double v12; // fp12
  int v13; // r5
  int v14; // r9
  double sortValue; // fp0
  __int64 v16; // r4
  double v17; // fp0
  idSpawnLocation *v18; // r4
  unsigned int num; // r5
  idSort_Quick<idSpawnLocation,idSort_LocationValue> v20; // [sp+50h] [-20h] BYREF
  __int64 v21; // [sp+58h] [-18h]

  v4 = 0;
  v20.__vftable = (idSort_Quick<idSpawnLocation,idSort_LocationValue>_vtbl *)context->spawnLocations.num;
  v2 = v20.__vftable;
  if ( (int)v20.__vftable > 0 )
  {
    list = context->spawnLocations.list;
    v6 = 0;
    v7 = context->spawnLocations.list;
    do
    {
      ++v4;
      ++v6;
      _FP11 = (float)(context->maxLocactionValue - v7->sortValue);
      _FP10 = (float)(context->minLocationValue - v7->sortValue);
      v7 = &list[v6];
      __asm { fsel      f9, f11, f13, f0 }
      context->maxLocactionValue = _FP9;
      __asm { fsel      f8, f10, f0, f12 }
      context->minLocationValue = _FP8;
    }
    while ( v4 < context->spawnLocations.num );
  }
  if ( g_spawnMPEnemyAI.valueInteger >= 2 )
    v12 = 1.0;
  else
    v12 = (float)((float)((float)(context->maxLocactionValue - context->minLocationValue) * g_spawnJitter.valueFloat)
                * (float)0.5);
  v13 = 0;
  v20.__vftable = v2;
  if ( (int)v2 > 0 )
  {
    v14 = 0;
    do
    {
      sortValue = context->spawnLocations.list[v14].sortValue;
      if ( sortValue > 0.0 )
      {
        HIDWORD(v16) = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = HIDWORD(v16);
        LODWORD(v16) = (HIDWORD(v16) >> 10) & 0x7FFF;
        v21 = v16;
        v17 = (float)((float)((float)((float)((float)v16 * (float)((float)v12 - (float)-v12)) * (float)0.000030518509)
                            + (float)-v12)
                    + (float)sortValue);
        if ( v17 >= 0.0 )
        {
          if ( v17 > 1.0 )
            v17 = 1.0;
        }
        else
        {
          v17 = 0.0;
        }
        context->spawnLocations.list[v14].sortValue = v17;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < context->spawnLocations.num );
  }
  v20.__vftable = (idSort_Quick<idSpawnLocation,idSort_LocationValue>_vtbl *)&idSort_LocationValue::`vftable';
  v18 = context->spawnLocations.list;
  if ( context->spawnLocations.list != nullptr )
  {
    num = context->spawnLocations.num;
    HIDWORD(v21) = context->spawnLocations.list;
    idSort_Quick<idSpawnLocation,idSort_LocationValue>::Sort(this: &v20, base: v18, num);
  }
}


// ========================================================================
// __unwind$488845_2
// EA  : 0x82EA64F8
// RVA : 0x00EA64F8
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void _unwind_488845_2()
{
  int v0; // r12

  idSort_LocationValue::~idSort_LocationValue(this: (idSort_LocationValue *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetSpawnResult@idSpawnManager@@QBAPBVidSpawnResult@@I@Z
// EA  : 0x82EA6520
// RVA : 0x00EA6520
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

const idSpawnResult *__fastcall idSpawnManager::GetSpawnResult(idSpawnManager *this, unsigned int handle)
{
  if ( handle != 0 && *(unsigned int *)((char *)this->spawnResults.handles + ((handle >> 20) & 0xFFC)) == handle )
    return &this->spawnResults.data[handle >> 22];
  else
    return nullptr;
}


// ========================================================================
// ?ReleaseSpawnResult@idSpawnManager@@QAAXI@Z
// EA  : 0x82EA6560
// RVA : 0x00EA6560
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::ReleaseSpawnResult(idSpawnManager *this, unsigned int handle)
{
  unsigned int *handles; // r10
  unsigned int v3; // r11

  if ( handle != 0 )
  {
    handles = this->spawnResults.handles;
    v3 = (handle >> 20) & 0xFFC;
    if ( *(unsigned int *)((char *)handles + v3) == handle )
      *(unsigned int *)((char *)handles + v3) = 0;
  }
}


// ========================================================================
// ?DrawSpawnNodes@idSpawnManager@@AAAXXZ
// EA  : 0x82EA6588
// RVA : 0x00EA6588
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::DrawSpawnNodes(idSpawnManager *this)
{
  int i; // r31
  unsigned int *v2; // r3

  for ( i = 86252; i < 119020; i += 4 )
  {
    v2 = (unsigned int *)idSpawnNode::CastTo(c: *(idSpawnNode **)((char *)&gameLocal->__vftable + i));
    if ( v2 != nullptr && (g_spawnDebugNodeType.valueInteger != 0 || (_cntlzw(v2[200]) & 0x20) != 0) )
      (*(void (__fastcall **)(unsigned int *, int))(*v2 + 644))(a1: v2, a2: g_spawnDebugLevel.valueInteger);
  }
}


// ========================================================================
// ?DrawSpawnEvaluations@idSpawnManager@@AAAXXZ
// EA  : 0x82EA6628
// RVA : 0x00EA6628
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::DrawSpawnEvaluations(idSpawnManager *this, int a2, __int64 a3, __int64 a4)
{
  int v5; // r28
  __int64 v6; // r10
  int v7; // r30
  va *v8; // r3
  idRenderWorld *v9; // r3
  int v10; // [sp+8h] [-10E8h]
  int v11; // [sp+Ch] [-10E4h]
  int v12; // [sp+10h] [-10E0h]
  int v13; // [sp+14h] [-10DCh]
  int v14; // [sp+18h] [-10D8h]
  int v15; // [sp+1Ch] [-10D4h]
  idStr v16; // [sp+70h] [-1080h] BYREF
  va v17; // [sp+90h] [-1060h] BYREF

  if ( g_spawnDebugLevel.valueInteger >= 2 )
  {
    v5 = 0;
    if ( this->context.spawnLocations.num > 0 )
    {
      HIDWORD(v6) = &unk_82150000;
      LODWORD(a4) = &unk_82150000;
      LODWORD(v6) = 0x82000000;
      v7 = 0;
      do
      {
        HIDWORD(a3) = (int)(float)(this->context.spawnLocations.list[v7].sortValue * (float)1000.0);
        v8 = va::va(this: &v17, fmt: "%d", a3, a4, a5: v6, a6: v10, a7: v11, a8: v12, a9: v13, a10: v14, a11: v15);
        idStr::idStr(this: &v16, text: v8);
        v9 = gameLocal->GetRenderWorld(this: gameLocal);
        ((void (__fastcall *)(idRenderWorld *, char *, idSpawnLocation *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v9->DebugText)(
          a1: v9,
          a2: v16.data,
          a3: &this->context.spawnLocations.list[v7],
          a4: v9->__vftable,
          a5: &idColor::colorRed,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.40000001);
        idStr::FreeData(this: &v16);
        LODWORD(v6) = this->context.spawnLocations.num;
        ++v5;
        ++v7;
      }
      while ( v5 < (int)v6 );
    }
  }
}


// ========================================================================
// __unwind$489069
// EA  : 0x82EA6740
// RVA : 0x00EA6740
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void _unwind_489069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 112));
}


// ========================================================================
// ??1idSpawnManager@@UAA@XZ
// EA  : 0x82EA6938
// RVA : 0x00EA6938
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::~idSpawnManager(idSpawnManager *this)
{
  this->__vftable = (idSpawnManager_vtbl *)&idSpawnManager::`vftable';
  idMem::Free(this: &mem, ptr: this->spawnResults.data, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->spawnResults.handles, align: ALIGN_16);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->context);
}


// ========================================================================
// __unwind$489456_0
// EA  : 0x82EA699C
// RVA : 0x00EA699C
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void _unwind_489456_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 2060));
}


// ========================================================================
// ?Update@idSpawnManager@@QAAXXZ
// EA  : 0x82EA69C8
// RVA : 0x00EA69C8
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __fastcall idSpawnManager::Update(idSpawnManager *this, int a2, __int64 a3, __int64 a4)
{
  idSpawnManager::Command *v5; // r27
  idSpawnManager::CommandExecutor *v6; // r30
  idSpawnManager::Command::commandState_t state; // r11
  idSpawnManager::Context *p_context; // r31
  int v9; // r28
  idSpawnLocation *v10; // r11
  idSpawnNode *sourceNode; // r3
  const idVec3 **v12; // r3
  int v13; // r10
  int v14; // r3
  int num; // r11
  int head; // r10
  unsigned int resultHandle; // r10
  idSpawnResult *v18; // r11
  int v19; // r11
  int v20; // r10
  unsigned int v21; // r10
  idSpawnResult *v22; // r11
  char v23; // [sp+50h] [-40h] BYREF

  if ( g_spawnDebugLevel.valueInteger > 0 )
  {
    idSpawnManager::DrawSpawnEvaluations(this, a2, a3, a4);
    idSpawnManager::DrawSpawnNodes(this);
  }
  if ( this->commandQueue.num > 0 )
  {
    v5 = &this->commandQueue.buffer[this->commandQueue.head % 128];
    v6 = this->GetExecutor(this, a2: v5->type);
    if ( v6 == nullptr )
      idLib::Error(fmt: "Unknown spawn command type: (%d).", v5->type);
    state = v5->state;
    if ( v5->state <= (unsigned int)CS_FAIL_COMMAND )
    {
      switch ( state )
      {
        case CS_EVALUATE_LOCATIONS:
          if ( v6->EvaluateContext(this: v6, a2: v5, a3: &this->context) )
          {
            v5->state = CS_JITTER_AND_SORT_LOCATIONS;
            this->context.currentLocationIndex = 0;
          }
          break;
        case CS_JITTER_AND_SORT_LOCATIONS:
          idSpawnManager::JitterAndSort(this, context: &this->context);
          v5->state = CS_FIND_BEST_LOCATION;
          break;
        case CS_FIND_BEST_LOCATION:
          v9 = 0;
          if ( this->context.currentLocationIndex < this->context.spawnLocations.num )
          {
            while ( v9 < 10 )
            {
              v10 = &this->context.spawnLocations.list[this->context.currentLocationIndex];
              sourceNode = v10->sourceNode;
              if ( sourceNode != nullptr )
                sourceNode->ReportBlockedLocation(this: sourceNode, a2: v10->locationID);
              v12 = (const idVec3 **)v6->GetActorSize(
                                       this: (idSpawnManager::CommandExecutor *)&v23,
                                       result: (const idVec3 *)v6,
                                       a3: v5);
              if ( (unsigned __int8)idSpawnManager::IsPositionObstructed(this, pos: *v12, size: v12[1]) == 0 )
              {
                v5->state = CS_COMPLETE_COMMAND;
                break;
              }
              ++v9;
              v13 = this->context.currentLocationIndex + 1;
              this->context.currentLocationIndex = v13;
              if ( v13 >= this->context.spawnLocations.num )
                break;
            }
          }
          if ( this->context.currentLocationIndex >= this->context.spawnLocations.num )
            v5->state = CS_FAIL_COMMAND;
          break;
        case CS_COMPLETE_COMMAND:
          v14 = (int)v6->Complete(
                       this: v6,
                       a2: v5,
                       a3: &this->context,
                       a4: &this->context.spawnLocations.list[this->context.currentLocationIndex]);
          num = this->commandQueue.num;
          if ( num > 0 )
          {
            head = this->commandQueue.head;
            this->commandQueue.num = num - 1;
            this->commandQueue.head = (head + 1) % 128;
          }
          resultHandle = v5->resultHandle;
          if ( resultHandle != 0
            && *(unsigned int *)((char *)this->spawnResults.handles + ((resultHandle >> 20) & 0xFFC)) == resultHandle )
          {
            v18 = &this->spawnResults.data[resultHandle >> 22];
            if ( v18 != nullptr )
            {
              v18->status = S_COMPLETE;
              if ( v14 != 0 )
                v18->entity.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(v14 + 492)] << 13)
                                          | *(_DWORD *)(v14 + 492);
              else
                v18->entity.spawnId.value = 0x1FFF;
              v18->location = &this->context.spawnLocations.list[this->context.currentLocationIndex];
            }
          }
          break;
        default:
          if ( state != CS_GENERATE_LOCATIONS )
          {
            v6->Fail(this: v6, a2: v5, a3: &this->context);
            v19 = this->commandQueue.num;
            if ( v19 > 0 )
            {
              v20 = this->commandQueue.head;
              this->commandQueue.num = v19 - 1;
              this->commandQueue.head = (v20 + 1) % 128;
            }
            v21 = v5->resultHandle;
            if ( v21 != 0 && *(unsigned int *)((char *)this->spawnResults.handles + ((v21 >> 20) & 0xFFC)) == v21 )
            {
              v22 = &this->spawnResults.data[v21 >> 22];
              if ( v22 != nullptr )
                v22->status = S_FAILED;
            }
            idLib::Warning(fmt: "Spawn command (%d) failed.", v5->type);
          }
          else
          {
            p_context = &this->context;
            idSpawnManager::Context::Reset(this: p_context);
            v6->GenerateLocations(this: v6, a2: v5, a3: p_context, a4: &p_context->spawnLocations);
            v5->state = CS_EVALUATE_LOCATIONS;
          }
          break;
      }
    }
  }
}


// ========================================================================
// ?GetNewResultHandle@idSpawnManager@@QAAIXZ
// EA  : 0x82EA6DD0
// RVA : 0x00EA6DD0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

unsigned int __fastcall idSpawnManager::GetNewResultHandle(idSpawnManager *this)
{
  idSpawnResult v2; // [sp+50h] [-20h] BYREF

  v2.status = S_PENDING;
  v2.entity.spawnId.value = 0x1FFF;
  v2.location = nullptr;
  return idHandleArray<idSpawnResult,10>::Add(this: &this->spawnResults, element: &v2);
}


// ========================================================================
// ?PushCommand@idSpawnManager@@IAAIHH_N@Z
// EA  : 0x82EA6E10
// RVA : 0x00EA6E10
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

unsigned int __fastcall idSpawnManager::PushCommand(idSpawnManager *this, int type, int dataIndex, bool returnHandle)
{
  unsigned int v7; // r31
  idSpawnManager::Command v9[4]; // [sp+50h] [-40h] BYREF

  v7 = 0;
  if ( returnHandle )
  {
    v9[0].dataIndex = 0;
    v9[0].state = CS_EVALUATE_LOCATIONS;
    v9[0].type = 0x1FFF;
    v7 = idHandleArray<idSpawnResult,10>::Add(this: &this->spawnResults, element: (const idSpawnResult *)v9);
  }
  v9[0].type = type;
  v9[0].dataIndex = dataIndex;
  v9[0].state = CS_GENERATE_LOCATIONS;
  v9[0].resultHandle = v7;
  idCircularBuffer<idSpawnManager::Command,128>::Add(this: &this->commandQueue, obj: v9);
  return v7;
}


// ========================================================================
// ??0idSpawnManager@@QAA@XZ
// EA  : 0x82EA7550
// RVA : 0x00EA7550
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

idSpawnManager *__fastcall idSpawnManager::idSpawnManager(idSpawnManager *this)
{
  this->__vftable = (idSpawnManager_vtbl *)&idSpawnManager::`vftable';
  idCircularBuffer<idSpawnManager::Command,128>::idCircularBuffer<idSpawnManager::Command,128>(this: &this->commandQueue);
  idSpawnManager::Context::Context(this: &this->context);
  idHandleArray<idSpawnResult,10>::idHandleArray<idSpawnResult,10>(this: &this->spawnResults);
  this->debugNodeTimeout = 0.0;
  return this;
}


// ========================================================================
// __unwind$490259_0
// EA  : 0x82EA75BC
// RVA : 0x00EA75BC
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void _unwind_490259_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2060));
}


// ========================================================================
// `dynamic initializer for 'g_spawnDebugLevel''
// EA  : 0x83392698
// RVA : 0x01392698
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnDebugLevel__()
{
  idCVar::idCVar(
    this: &g_spawnDebugLevel,
    name: "g_spawnDebugLevel",
    value: "0",
    flags: 2,
    description: "Show spawn system debugging information. 0 = off, 1 = low, 2 = high",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnDebugLevel__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnDebugNodeType''
// EA  : 0x833926F0
// RVA : 0x013926F0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnDebugNodeType__()
{
  idCVar::idCVar(
    this: &g_spawnDebugNodeType,
    name: "g_spawnDebugNodeType",
    value: "0",
    flags: 2,
    description: "0:Standard, 1:Initial, 2:All",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnDebugNodeType__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnDebugUserTeam''
// EA  : 0x83392748
// RVA : 0x01392748
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnDebugUserTeam__()
{
  idCVar::idCVar(
    this: &g_spawnDebugUserTeam,
    name: "g_spawnDebugUserTeam",
    value: "0",
    flags: 2,
    description: "Set team used to evaluate spawn locations.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnDebugUserTeam__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnDebugUpdate''
// EA  : 0x833927A0
// RVA : 0x013927A0
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnDebugUpdate__()
{
  idCVar::idCVar(
    this: &g_spawnDebugUpdate,
    name: "g_spawnDebugUpdate",
    value: "1",
    flags: 1,
    description: "Set to false to freeze spawn debug view.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnDebugUpdate__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnDebugNormalize''
// EA  : 0x833927F8
// RVA : 0x013927F8
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnDebugNormalize__()
{
  idCVar::idCVar(
    this: &g_spawnDebugNormalize,
    name: "g_spawnDebugNormalize",
    value: "1",
    flags: 1,
    description: "Normalize output color of spawn locations to use full range (red -> green.)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnDebugNormalize__);
}


// ========================================================================
// `dynamic initializer for 'g_spawnJitter''
// EA  : 0x83392850
// RVA : 0x01392850
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spawnJitter__()
{
  idCVar::idCVar(
    this: &g_spawnJitter,
    name: "g_spawnJitter",
    value: "0.1",
    flags: 4,
    description: "Amount of random variation in spawn location values.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spawnJitter__);
}


// ========================================================================
// `dynamic initializer for 'mp_spawnDebugNodeTimeout''
// EA  : 0x833928A8
// RVA : 0x013928A8
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_spawnDebugNodeTimeout__()
{
  idCVar::idCVar(
    this: &mp_spawnDebugNodeTimeout,
    name: "mp_spawnDebugNodeTimeout",
    value: "-1.0",
    flags: 4,
    description: "Number of seconds that a player stays at a spawn node before teleporting to the next one.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_spawnDebugNodeTimeout__);
}


// ========================================================================
// `dynamic initializer for 'mp_spawnDebugNodeIndex''
// EA  : 0x83392900
// RVA : 0x01392900
// PDB : w:\tech5\tungsten\game\spawning\spawnmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_spawnDebugNodeIndex__()
{
  idCVar::idCVar(
    this: &mp_spawnDebugNodeIndex,
    name: "mp_spawnDebugNodeIndex",
    value: "0",
    flags: 2,
    description: "Index of the next node to debug.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_spawnDebugNodeIndex__);
}

