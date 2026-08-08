
// ========================================================================
// ?StopAnimEvent@mgTimelineController@@AAAXAAUrunContext_t@1@@Z
// EA  : 0x82CEADB0
// RVA : 0x00CEADB0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::StopAnimEvent(
        mgTimelineController *this,
        mgTimelineController::runContext_t *context)
{
  idEntity *entity; // r29
  int v5; // r28
  const idAnimStack *v6; // r3
  idAnimCamera *v7; // r3

  entity = context->entity;
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v6 = entity->GetAnimStack_2(this: entity);
  idAnimator_Base::End(this: context->track->animator, stack: v6, curTime: v5, blendDurationMS: 0, reset: true);
  if ( !this->timeLeap )
  {
    v7 = idAnimCamera::CastTo(c: (idAnimCamera *)context->entity);
    if ( v7 != nullptr )
      idCamera::Deactivate(this: v7);
  }
}


// ========================================================================
// ?ReInit@mgEditorTimelineInterface@@UAAXXZ
// EA  : 0x82CEAE40
// RVA : 0x00CEAE40
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgEditorTimelineInterface::ReInit(mgEditorTimelineInterface *this)
{
  mgTimelineController *v1; // r3
  mgTimelineController *v2; // r3
  mgTimelineController *v3; // r31

  v1 = (mgTimelineController *)this->GetEntity(this);
  v2 = mgTimelineController::CastTo(c: v1);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->initDone = false;
    idLib::Printf(fmt: "NOTE: timeline ontroller was modified and will now run Init() again...\n");
    v3->Think(this: v3);
  }
}


// ========================================================================
// ?Spawn@mgTimelineController@@QAAXXZ
// EA  : 0x82CEAEB0
// RVA : 0x00CEAEB0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::Spawn(mgTimelineController *this)
{
  this->timeSpan.min = -1;
  this->timeSpan.max = -1;
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?CreateEntityInterface@mgTimelineController@@UAAPAVidEntityInterface@@PAVidGame@@@Z
// EA  : 0x82CEAED0
// RVA : 0x00CEAED0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

idEntityInterface *__fastcall mgTimelineController::CreateEntityInterface(mgTimelineController *this, idGame *game)
{
  idEntityInterfaceLocal *v4; // r3
  _DWORD *v5; // r30

  v4 = (idEntityInterfaceLocal *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x14u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  v5 = &v4->__vftable;
  if ( v4 == nullptr )
    return nullptr;
  idEntityInterfaceLocal::idEntityInterfaceLocal(this: v4, game, ent: this);
  *v5 = &mgEditorTimelineInterface::`vftable';
  return (idEntityInterface *)v5;
}


// ========================================================================
// __unwind$498448
// EA  : 0x82CEAF4C
// RVA : 0x00CEAF4C
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall _unwind_498448(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?CheckClearEnvOverride@mgTimelineController@@AAAXXZ
// EA  : 0x82CEAF78
// RVA : 0x00CEAF78
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::CheckClearEnvOverride(mgTimelineController *this)
{
  int v1; // r5
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v4; // r3

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr && clientGame->renderWorld[35042].__vftable != nullptr )
  {
    presentable = Player->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    idView::SetEnvironmentOverride(this: (idView *)(v4 + 16224), env: nullptr, blendDuration: -1.0, modelIndex: v1);
  }
}


// ========================================================================
// ??0tlEvent_t@mgTimelineController@@QAA@XZ
// EA  : 0x82CEB008
// RVA : 0x00CEB008
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

mgTimelineController::tlEvent_t *__fastcall mgTimelineController::tlEvent_t::tlEvent_t(
        mgTimelineController::tlEvent_t *this)
{
  tlEventData_t::tlEventData_t(this);
  this->animHandle.value = -1;
  return this;
}


// ========================================================================
// ?Init@mgTimelineController@@AAAXXZ
// EA  : 0x82CEB048
// RVA : 0x00CEB048
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::Init(mgTimelineController *this)
{
  int num; // r9
  int v3; // r10
  int v4; // r9
  mgTimelineController::tlTrack_t *v5; // r11
  int v6; // r11
  int v7; // r24
  const char *v8; // r14
  int v9; // r25
  char *v10; // r28
  idEntity *v11; // r3
  idEntity *v12; // r27
  int v13; // r21
  int *v14; // r25
  int v15; // r24
  int *v16; // r30
  int v17; // r11
  int v18; // r9
  int v19; // r8
  int v20; // r11
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v22; // r3
  idTreeAnimator *v23; // r29
  idAnimator_Channel *v24; // r3
  idAnimator_Channel *v25; // r3
  idGameTimeManager *v26; // r3
  idAnimator_FaceTracks *v27; // r3
  idAnimator_FaceTracks *v28; // r3
  idGameTimeManager *v29; // r3
  void *data; // r6
  int v31; // r14
  int min; // r11
  int max; // r10
  int v34; // r11
  int v35; // r11
  __int16 v36; // [sp+50h] [-150h] BYREF
  const char *p_timeSpan; // [sp+54h] [-14Ch]
  int v38; // [sp+58h] [-148h]
  int v39; // [sp+5Ch] [-144h]
  const char *v40; // [sp+60h] [-140h]
  struct idTreeAnimator *v41; // [sp+64h] [-13Ch]
  const char *v42; // [sp+68h] [-138h]
  void *v43; // [sp+6Ch] [-134h]
  const char *v44; // [sp+70h] [-130h]
  struct idRenderModel *v45; // [sp+74h] [-12Ch]
  idAnimatorParms_Base v46; // [sp+80h] [-120h] BYREF
  idAnimatorParms_Base v47; // [sp+C0h] [-E0h] BYREF

  if ( !this->initDone )
  {
    num = this->tracks.num;
    v3 = 0;
    this->initDone = true;
    if ( num > 0 )
    {
      v4 = 0;
      do
      {
        ++v3;
        v5 = &this->tracks.list[v4++];
        v5->pos.z = 0.0;
        p_timeSpan = (const char *)&v5->timeSpan;
        v5->pos.y = 0.0;
        v5->pos.x = 0.0;
        v5->timeSpan.min = -1;
        v5->timeSpan.max = -1;
      }
      while ( v3 < this->tracks.num );
    }
    v6 = this->tracks.num;
    v7 = 0;
    v38 = 0;
    if ( v6 > 0 )
    {
      v39 = 0;
      p_timeSpan = "NOTE: removing bad animkey event on timeline controller (mismatching data types)\n";
      v44 = "NOTE: removing bad animation event on timeline controller '%s' (anim: '%s', entity: '%s')\n";
      v8 = "null";
      v40 = "null";
      v45 = &idRenderModel `RTTI Type Descriptor';
      v9 = 0;
      v41 = &idTreeAnimator `RTTI Type Descriptor';
      v42 = "NOTE: removing bad event on timeline controller '%s' (invalid target entity)\n";
      do
      {
        v10 = (char *)this->tracks.list + v9;
        if ( gameLocal->spawnIds.ptr[*(_DWORD *)v10 & 0x1FFF] == *(int *)v10 >> 13
          && (v11 = gameLocal->entities.ptr[*(_DWORD *)v10 & 0x1FFF]) != nullptr )
        {
          v12 = idEntity::CastTo(c: v11);
        }
        else
        {
          v12 = nullptr;
        }
        v13 = 0;
        if ( *((int *)v10 + 2) > 0 )
        {
          v14 = (int *)(v10 + 28);
          v15 = 0;
          do
          {
            v16 = (int *)(v15 + *((_DWORD *)v10 + 1));
            v17 = *v16;
            v18 = v16[1] + *v16 + 33;
            if ( *v14 < *v16 )
              v17 = *v14;
            v19 = *((_DWORD *)v10 + 8);
            *v14 = v17;
            if ( v19 > v18 )
              v18 = v19;
            *((_DWORD *)v10 + 8) = v18;
            v20 = v16[2];
            if ( v20 == 2 || v20 == 7 || v12 != nullptr )
            {
              switch ( v20 )
              {
                case 1:
                  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v12);
                  v22 = (idTreeAnimator *)_RTDynamicCast(
                                            inptr: RenderModelFromPresentable,
                                            VfDelta: 0,
                                            SrcType: v45,
                                            TargetType: v41,
                                            isReference: 0);
                  v23 = v22;
                  if ( v16[3] != 0 && v22 != nullptr )
                  {
                    idTreeAnimator::SetRemoveOriginRotation(this: v22, removeRotation: false);
                    idTreeAnimator::SetRemoveOriginRotation(this: v23, removeRotation: false);
                    idDeclMD6::StrongLoadAlias(
                      this: (idDeclMD6 *)&v36,
                      result: v23->decl,
                      aliasName: (const char *)v16[4]);
                    *((_WORD *)v16 + 80) = v36;
                    if ( *((_DWORD *)v10 + 9) == 0 )
                    {
                      v24 = (idAnimator_Channel *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                    size: 0x60u,
                                                    tag: TAG_NEW,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
                      v43 = v24;
                      if ( v24 != nullptr )
                        v25 = idAnimator_Channel::idAnimator_Channel(this: v24);
                      else
                        v25 = nullptr;
                      *((_DWORD *)v10 + 9) = v25;
                      v47.animStack = v12->GetAnimStack_2(this: v12);
                      idStr::idStr(this: &v47.name, text: "base");
                      v47.alpha = 0.0;
                      memset(&v47.originBlend, 0, 12);
                      v47.blendOp = BOP_LERP;
                      v26 = gameLocal->GetGameTimeManager(this: gameLocal);
                      idAnimator_Base::Init(this: *((idAnimator_Base **)v10 + 9), gametimeManager: v26, parms: &v47);
                      if ( (unsigned __int8)idAnimator_FaceTracks::HasFaceTracks(decl: v23->decl) != 0 )
                      {
                        v27 = (idAnimator_FaceTracks *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                         size: 0x8Cu,
                                                         tag: TAG_NEW,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
                        v43 = v27;
                        if ( v27 != nullptr )
                          v28 = idAnimator_FaceTracks::idAnimator_FaceTracks(this: v27);
                        else
                          v28 = nullptr;
                        *((_DWORD *)v10 + 10) = v28;
                        v46.animStack = v12->GetAnimStack_2(this: v12);
                        idStr::idStr(this: &v46.name, text: "facetracks");
                        v46.alpha = 1.0;
                        v46.blendOp = BOP_ADD_RIGHT;
                        v46.originBlend = ORIGINBLEND_BRANCH;
                        v46.weightGroup = MD6_WEIGHTGROUP_FACE;
                        v46.filterGroup = MD6_WEIGHTGROUP_FACE;
                        v29 = gameLocal->GetGameTimeManager(this: gameLocal);
                        idAnimator_Base::Init(this: *((idAnimator_Base **)v10 + 10), gametimeManager: v29, parms: &v46);
                        idStr::FreeData(this: &v46.name);
                      }
                      idStr::FreeData(this: &v47.name);
                    }
                  }
                  else
                  {
                    if ( v12 != nullptr )
                      data = v12->name.data;
                    else
                      data = (void *)v8;
                    idLib::Printf(fmt: v44, this->name.data, v16[4], data);
                    v16[2] = 0;
                  }
                  break;
                case 2:
                  if ( v16[12] == 0 )
                  {
                    if ( v12 != nullptr )
                      idLib::Printf(
                        fmt: "NOTE: removing bad sound event on timeline controller '%s' (entity: '%s')\n",
                        this->name.data,
                        v12->name.data);
                    else
                      idLib::Printf(
                        fmt: "NOTE: removing bad sound event on timeline controller '%s' (entity: '%s')\n",
                        this->name.data,
                        v8);
                    v16[2] = 0;
                  }
                  break;
                case 5:
                  v31 = v16[28];
                  if ( v31 == mgTimelineKeyUtil::GetType(key: (tlKeyId_t)v16[19]) )
                  {
                    mgTimelineKeyAnimData::PostLoadInit(this: (mgTimelineKeyAnimData *)(v16 + 28));
                  }
                  else
                  {
                    idLib::Printf(fmt: p_timeSpan);
                    v16[2] = 0;
                  }
                  break;
                default:
                  break;
              }
            }
            else
            {
              idLib::Printf(fmt: v42, this->name.data);
              v16[2] = 0;
            }
            ++v13;
            v8 = v40;
            v15 += 164;
          }
          while ( v13 < *((_DWORD *)v10 + 2) );
          v9 = v39;
          v7 = v38;
        }
        min = this->timeSpan.min;
        if ( min >= *((_DWORD *)v10 + 7) )
          min = *((_DWORD *)v10 + 7);
        max = this->timeSpan.max;
        this->timeSpan.min = min;
        v34 = *((_DWORD *)v10 + 8);
        if ( max > v34 )
          v34 = max;
        ++v7;
        this->timeSpan.max = v34;
        v9 += 56;
        v35 = this->tracks.num;
        v38 = v7;
        v39 = v9;
      }
      while ( v7 < v35 );
    }
  }
}


// ========================================================================
// __unwind$498748
// EA  : 0x82CEB550
// RVA : 0x00CEB550
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall _unwind_498748(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 108), tag: a2);
}


// ========================================================================
// __unwind$498749
// EA  : 0x82CEB578
// RVA : 0x00CEB578
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void _unwind_498749()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$498750
// EA  : 0x82CEB5A0
// RVA : 0x00CEB5A0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall _unwind_498750(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 108), tag: a2);
}


// ========================================================================
// __unwind$498751
// EA  : 0x82CEB5C8
// RVA : 0x00CEB5C8
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void _unwind_498751()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 128));
}


// ========================================================================
// ?StartAnimEvent@mgTimelineController@@AAAXAAUrunContext_t@1@@Z
// EA  : 0x82CEB5F0
// RVA : 0x00CEB5F0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::StartAnimEvent(
        mgTimelineController *this,
        mgTimelineController::runContext_t *context)
{
  const mgTimelineController::tlEvent_t *event; // r29
  int eventTime; // r30
  int v6; // r27
  idAnimStack *v7; // r3
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r3
  idResource *v10; // r30
  idMat3 *v11; // r4
  idEntity_vtbl *v12; // r30
  idMat3 *v13; // r3
  idAnimCamera *v14; // r3
  idCamera *v15; // r30
  int value; // r9
  idEntity *v17; // r3
  idEntity *v18; // r3
  const idAnimStack *v19; // r3
  blendParms_t v20[4]; // [sp+50h] [-60h] BYREF

  event = context->event;
  eventTime = 0;
  if ( !context->timeLeap )
    eventTime = context->eventTime;
  v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - eventTime;
  if ( event->useAnimPos && event->animHandle.value != 0xFFFF )
  {
    v7 = context->entity->GetAnimStack_2(this: context->entity);
    Alias = idDeclMD6::FindAlias(this: v7->treeAnimator->decl, aliasHandle: &event->animHandle, includeInherited: true);
    if ( Alias != nullptr )
    {
      Existing = idResourceList::FindExisting(
                   this: &idMD6Anim::resourceList,
                   name: (char *)Alias->animRefs.list->str,
                   skipStaleCheck: true);
      v10 = Existing;
      if ( Existing != nullptr )
      {
        idEntity::SetOrigin(this: context->entity, org: (const idVec3 *)&Existing[2].resourceError);
        v11 = (idMat3 *)((char *)&v10[2] + 32);
        v12 = context->entity->__vftable;
        v13 = idAngles::ToMat3(this: (idAngles *)v20, result: v11);
        v12->SetAxis(this: context->entity, a2: v13);
      }
    }
  }
  v14 = idAnimCamera::CastTo(c: (idAnimCamera *)context->entity);
  v15 = v14;
  if ( v14 != nullptr )
  {
    idAnimCamera::SetCameraAnim(this: v14, name: event->anim.data);
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v17 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v18 = idEntity::CastTo(c: v17);
      idCamera::Activate(this: v15, activator_: v18);
    }
    else
    {
      idCamera::Activate(this: v15, activator_: nullptr);
    }
  }
  else
  {
    if ( event->animHandle.value != 0xFFFF )
    {
      blendParms_t::blendParms_t(this: v20);
      blendParms_t::SetDestStartFrame(this: v20, frame: 0);
      blendParms_t::SetDuration(this: v20, frame: 0);
      v19 = context->entity->GetAnimStack_2(this: context->entity);
      idAnimator_Channel::PlayAnim(
        this: context->track->animator,
        stack: v19,
        ah: &event->animHandle,
        curTime: v6,
        rateScale: 1.0,
        blendParms: (const blendParms_t *)context->track,
        blendOutDurationMS_: v20,
        leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
        a9: nullptr);
    }
    idEntity::BecomeActive(this: context->entity, flags: 5);
  }
}


// ========================================================================
// ?StartSoundEvent@mgTimelineController@@AAAXAAUrunContext_t@1@@Z
// EA  : 0x82CEB7E8
// RVA : 0x00CEB7E8
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::StartSoundEvent(
        mgTimelineController *this,
        mgTimelineController::runContext_t *context)
{
  int value; // r9
  idGameLocal *v5; // r11
  idEntity *v6; // r3
  int v7; // r3

  value = context->track->target.spawnId.value;
  v5 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      if ( idEntity::CastTo(c: v6) != nullptr )
      {
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ANY,
          shader: context->event->sound,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
        return;
      }
      v5 = gameLocal;
    }
  }
  v7 = (int)v5->GetSoundWorld(this: v5);
  (*(void (__fastcall **)(int, const idSoundShader *, _DWORD, double))(*(_DWORD *)v7 + 64))(
    a1: v7,
    a2: context->event->sound,
    a3: 0,
    a4: 0.0);
}


// ========================================================================
// ?UpdateVisuals@mgEditorTimelineInterface@@UAAXXZ
// EA  : 0x82CEB8B0
// RVA : 0x00CEB8B0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgEditorTimelineInterface::UpdateVisuals(mgEditorTimelineInterface *this)
{
  mgTimelineController *v1; // r3
  mgTimelineController *v2; // r3
  mgTimelineController *v3; // r31

  v1 = (mgTimelineController *)this->GetEntity(this);
  v2 = mgTimelineController::CastTo(c: v1);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idEntity::UpdateVisuals(this: v2);
    mgTimelineController::CheckClearEnvOverride(this: v3);
  }
}


// ========================================================================
// ?SetPreviewTime@mgTimelineController@@QAAXH@Z
// EA  : 0x82CEB900
// RVA : 0x00CEB900
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall mgTimelineController::SetPreviewTime(mgTimelineController *this, int time, long double a3)
{
  idEntity *v3; // r3
  idEntity *v4; // r31
  __int64 v5; // r4
  long double v6; // fp2
  idPlayer *Player; // r3
  idEntity_vtbl *v8; // r10

  v4 = v3;
  if ( time != *(_DWORD *)&v3[1].name.baseBuffer[8] )
  {
    LODWORD(v5) = timeManager.gameTimePerFrame.value * timeManager.gameHz * time;
    *(double *)&a3 = (float)((float)((double)v5 * 0.001041666666666667) + (float)0.5);
    v6 = floor(x: a3);
    if ( *(int *)&v4[1].name.baseBuffer[4] < 0 )
      *(_DWORD *)&v4[1].name.baseBuffer[4] = 0;
    idGameTimeManager::SetGameMs(
      this: &clientGame->gameTimeManager,
      newtime: *(_DWORD *)&v4[1].name.baseBuffer[4] + (int)(float)*(double *)&v6);
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
      *(_DWORD *)&v4[1].name.baseBuffer[12] = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13)
                                            | Player->entityNumber;
    else
      *(_DWORD *)&v4[1].name.baseBuffer[12] = 0x1FFF;
    idEntity::BecomeActive(this: v4, flags: 1);
    v8 = v4->__vftable;
    v4[1].name.baseBuffer[1] = 1;
    v8->Think(this: v4);
  }
}


// ========================================================================
// ?GetPreviewTime@mgTimelineController@@QBAHXZ
// EA  : 0x82CEBA30
// RVA : 0x00CEBA30
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

int __fastcall mgTimelineController::GetPreviewTime(mgTimelineController *this)
{
  int GameMs; // r3
  __int64 v3; // r11
  __int64 v4; // r3
  long double v5; // fp2
  long double v6; // fp2

  if ( this->startTime < 0 )
    return -1;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v3) = timeManager.gameHz;
  LODWORD(v3) = 960 * (GameMs - this->startTime);
  LODWORD(v4) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  *(double *)&v5 = (float)((float)((double)v3 / (double)v4) + (float)0.5);
  v6 = floor(x: v5);
  return (int)(float)*(double *)&v6;
}


// ========================================================================
// ?TimeLeapAnimEvent@mgTimelineController@@AAAXAAUrunContext_t@1@@Z
// EA  : 0x82CEBB00
// RVA : 0x00CEBB00
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::TimeLeapAnimEvent(
        mgTimelineController *this,
        mgTimelineController::runContext_t *context)
{
  idAnimator_Channel *animator; // r30
  idAnimCamera *v5; // r3
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v7; // r30
  int v8; // r31
  int v9; // r29
  int GameMs; // r3

  mgTimelineController::StopAnimEvent(this, context);
  mgTimelineController::StartAnimEvent(this, context);
  animator = context->track->animator;
  v5 = idAnimCamera::CastTo(c: (idAnimCamera *)context->entity);
  if ( v5 != nullptr )
    animator = &v5->channelAnimator;
  if ( animator != nullptr )
  {
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: animator);
    v7 = LastPlayedLeaf;
    if ( LastPlayedLeaf != nullptr )
    {
      v8 = idMD6Leaf::GetFrameRate(this: LastPlayedLeaf) * context->eventTime / 960;
      v9 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idMD6LeafPlay::SetFrame(this: v7, gameTime: GameMs, ticksPerSec: v9, targetFrame: v8);
    }
  }
}


// ========================================================================
// ?SetPreviewTime@mgEditorTimelineInterface@@UAAXH@Z
// EA  : 0x82CEBBB8
// RVA : 0x00CEBBB8
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgEditorTimelineInterface::SetPreviewTime(mgEditorTimelineInterface *this, int time)
{
  mgTimelineController *v3; // r3
  mgTimelineController *v4; // r3
  long double v5; // fp2

  v3 = (mgTimelineController *)this->GetEntity(this);
  v4 = mgTimelineController::CastTo(c: v3);
  if ( v4 != nullptr )
    mgTimelineController::SetPreviewTime(this: v4, time, a3: v5);
}


// ========================================================================
// ?GetPreviewTime@mgEditorTimelineInterface@@UBAHXZ
// EA  : 0x82CEBC08
// RVA : 0x00CEBC08
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

int __fastcall mgEditorTimelineInterface::GetPreviewTime(mgEditorTimelineInterface *this)
{
  mgTimelineController *v1; // r3
  mgTimelineController *v2; // r3

  v1 = (mgTimelineController *)this->GetEntity(this);
  v2 = mgTimelineController::CastTo(c: v1);
  if ( v2 != nullptr )
    return mgTimelineController::GetPreviewTime(this: v2);
  else
    return -1;
}


// ========================================================================
// ?HandleEvent@mgTimelineController@@AAAXAAUrunContext_t@1@@Z
// EA  : 0x82CEBC58
// RVA : 0x00CEBC58
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::HandleEvent(
        mgTimelineController *this,
        mgTimelineController::runContext_t *context,
        int a3)
{
  const mgTimelineController::tlEvent_t *event; // r30
  tlEventType_t type; // r10
  idEntity *v6; // r3
  idMat3 *p_worldRot; // r4
  idEntity_vtbl *v8; // r30
  idMat3 *v9; // r3
  idAnimCamera *entity; // r3
  char v11; // r11
  __int64 v12; // r10
  const idEntity *v13; // r3
  idEventArg *v14; // r3
  idPlayer *player; // r11
  idPresentable *presentable; // r3
  int v17; // r3
  const idDeclEnv *env; // r4
  idView *v19; // r3
  double blendDuration; // fp1
  idEventArg v21; // [sp+60h] [-A0h] BYREF
  idEventReceiver v22[2]; // [sp+80h] [-80h] BYREF
  idEventReceiver v23[2]; // [sp+A0h] [-60h] BYREF
  idAngles v24[3]; // [sp+C0h] [-40h] BYREF

  event = context->event;
  type = event->type;
  if ( (unsigned int)(type - 1) > 6 )
    return;
  if ( type == TL_EVENT_SOUND )
  {
    if ( context->eventStart )
      mgTimelineController::StartSoundEvent(this, context);
  }
  else
  {
    if ( type != TL_EVENT_TELEPORT )
    {
      if ( type != TL_EVENT_SETKEY && type != TL_EVENT_ANIMKEY )
      {
        if ( type == TL_EVENT_ACTIVATE )
        {
          if ( context->entity != nullptr )
          {
            if ( context->eventStart && event->activateStart )
            {
              v13 = idEntityPtr<idEntity const>::operator->(this: &this->activator);
              v14 = idEventArg::idEventArg(this: &v21, data: v13);
              idEventReceiver::ProcessEvent(
                this: v22,
                result: (idEventArg *)context->entity,
                ev: *(const idEventDef **)&v14->type,
                arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
            }
            if ( context->eventStop && event->activateEnd )
              idEventReceiver::ProcessEvent(this: v23, result: (idEventArg *)context->entity, ev: &EV_Deactivate);
          }
        }
        else if ( type == TL_EVENT_ANIM )
        {
          if ( context->timeLeap )
          {
            mgTimelineController::TimeLeapAnimEvent(this, context);
          }
          else if ( context->eventStart )
          {
            mgTimelineController::StartAnimEvent(this, context);
          }
          else if ( context->eventStop )
          {
            mgTimelineController::StopAnimEvent(this, context);
          }
        }
        else
        {
          player = context->player;
          if ( player != nullptr )
          {
            presentable = player->presentable;
            if ( presentable != nullptr )
              v17 = (int)presentable->GetPlayerInterface_2(this: presentable);
            else
              v17 = 0;
            env = event->env;
            v19 = (idView *)(v17 + 16224);
            if ( env != nullptr )
              blendDuration = env->blendDuration;
            else
              blendDuration = -1.0;
            idView::SetEnvironmentOverride(this: v19, env, blendDuration, modelIndex: a3);
          }
        }
        return;
      }
      entity = (idAnimCamera *)context->entity;
      if ( entity == nullptr )
        return;
      v11 = 0;
      if ( context->eventStop )
      {
        mgEntityValueAccess::ResetKey(entity, key: event->keyName);
      }
      else if ( type == TL_EVENT_SETKEY )
      {
        if ( !context->eventStart && !context->timeLeap )
        {
LABEL_29:
          if ( v11 != 0 && event->keyName == TL_KEY_VISIBILITY )
            context->updateVisibility = true;
          return;
        }
        mgEntityValueAccess::SetValueStr(entity, key: event->keyName, valueStr: &event->keyValue);
      }
      else
      {
        LODWORD(v12) = context->eventTime;
        HIDWORD(v12) = context->eventStop;
        mgEntityValueAccess::Animate(entity, key: event->keyName, anim: &event->keyAnimData, time: (float)v12);
      }
      v11 = 1;
      goto LABEL_29;
    }
    if ( context->eventStart || context->timeLeap )
    {
      v6 = context->entity;
      if ( v6 != nullptr )
      {
        idEntity::SetOrigin(this: v6, org: &event->worldPos);
        p_worldRot = (idMat3 *)&event->worldRot;
        v8 = context->entity->__vftable;
        v9 = idAngles::ToMat3(this: v24, result: p_worldRot);
        v8->SetAxis(this: context->entity, a2: v9);
      }
    }
  }
}


// ========================================================================
// ?Stop@mgTimelineController@@QAAXXZ
// EA  : 0x82CEBF00
// RVA : 0x00CEBF00
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::Stop(mgTimelineController *this)
{
  int v2; // r24
  int v3; // r27
  mgTimelineController::runContext_t *v4; // r9
  mgTimelineController::tlTrack_t *v5; // r29
  int i; // ctr
  int v7; // r11
  int v8; // r8
  int v9; // r5
  idEntity *v10; // r3
  idEntity *v11; // r3
  int num; // r11
  int v13; // r31
  int v14; // r30
  mgTimelineController::tlEvent_t *list; // r11
  mgTimelineController::runContext_t v16[4]; // [sp+50h] [-70h] BYREF

  v2 = 0;
  if ( this->tracks.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = v16;
      v5 = &this->tracks.list[v3];
      for ( i = 6; i != 0; --i )
      {
        v4 = (mgTimelineController::runContext_t *)((char *)v4 + 4);
        v4->track = nullptr;
      }
      v7 = v5->target.spawnId.value & 0x1FFF;
      v8 = v5->target.spawnId.value >> 13;
      v16[0].track = v5;
      v9 = gameLocal->spawnIds.ptr[v7];
      if ( v9 == v8 && (v10 = gameLocal->entities.ptr[v7]) != nullptr )
        v11 = idEntity::CastTo(c: v10);
      else
        v11 = nullptr;
      num = v5->events.num;
      v13 = 0;
      v16[0].entity = v11;
      if ( num > 0 )
      {
        v14 = 0;
        do
        {
          list = v5->events.list;
          v16[0].eventStop = true;
          v16[0].event = &list[v14];
          mgTimelineController::HandleEvent(this, context: v16, a3: v9);
          ++v13;
          ++v14;
        }
        while ( v13 < v5->events.num );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->tracks.num );
  }
  this->startTime = -1;
}


// ========================================================================
// ?RunEvents@mgTimelineController@@AAAXHH@Z
// EA  : 0x82CEC008
// RVA : 0x00CEC008
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::RunEvents(mgTimelineController *this, int time, unsigned int deltaTime)
{
  mgTimelineController::runContext_t *v3; // r11
  int i; // ctr
  idPlayer *Player; // r3
  bool timeLeap; // r10
  int num; // r11
  int v11; // r26
  int v12; // r27
  mgTimelineController::tlTrack_t *v13; // r29
  char v14; // r11
  int v15; // r11
  int v16; // r8
  int v17; // r5
  idEntity *v18; // r3
  idEntity *v19; // r3
  int v20; // r11
  int v21; // r28
  int v22; // r30
  mgTimelineController::tlEvent_t *v23; // r31
  int v24; // r11
  int v25; // r11
  int duration; // r10
  int v27; // r11
  char v28; // r9
  char v29; // r11
  bool v30; // zf
  int v31; // r25
  int v32; // r26
  mgTimelineController::tlTrack_t *v33; // r29
  char v34; // r11
  int v35; // r11
  int v36; // r8
  int v37; // r5
  idEntity *v38; // r3
  idEntity *v39; // r3
  int v40; // r11
  idLight *entity; // r27
  int v42; // r28
  int v43; // r30
  mgTimelineController::tlEvent_t *v44; // r31
  int v45; // r11
  int v46; // r11
  int v47; // r11
  unsigned __int8 *v48; // r3
  idLight *v49; // r31
  int v50; // r5
  idPlayer *v51; // r3
  idPresentable *presentable; // r3
  int v53; // r3
  mgTimelineController::runContext_t v54[5]; // [sp+50h] [-90h] BYREF

  v3 = v54;
  v54[0].track = nullptr;
  for ( i = 6; i != 0; --i )
  {
    v3 = (mgTimelineController::runContext_t *)((char *)v3 + 4);
    v3->track = nullptr;
  }
  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  timeLeap = this->timeLeap;
  num = this->tracks.num;
  v11 = 0;
  v54[0].player = Player;
  v54[0].deltaTime = deltaTime;
  v54[0].timeLeap = timeLeap;
  if ( num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = &this->tracks.list[v12];
      if ( time < v13->timeSpan.min || (v14 = 1, time >= v13->timeSpan.max) )
        v14 = 0;
      if ( v14 != 0 || this->timeLeap )
      {
        v15 = v13->target.spawnId.value & 0x1FFF;
        v16 = v13->target.spawnId.value >> 13;
        v54[0].track = &this->tracks.list[v12];
        v17 = gameLocal->spawnIds.ptr[v15];
        if ( v17 == v16 && (v18 = gameLocal->entities.ptr[v15]) != nullptr )
          v19 = idEntity::CastTo(c: v18);
        else
          v19 = nullptr;
        v20 = v13->events.num;
        v21 = 0;
        v54[0].entity = v19;
        if ( v20 > 0 )
        {
          v22 = 0;
          do
          {
            v23 = &v13->events.list[v22];
            if ( this->timeLeap )
            {
              v24 = v23->time;
            }
            else
            {
              v25 = 32;
              if ( v23->type == TL_EVENT_ANIM )
              {
                idAnimCamera::IsTypeOf(c: v54[0].entity);
                v25 = 0;
              }
              v24 = v23->time + v25;
            }
            duration = v23->duration;
            v27 = time - v24;
            if ( v27 < duration || (v28 = 1, v27 >= (int)(duration + deltaTime)) )
              v28 = 0;
            if ( v27 < 0 || (v30 = v27 < (int)(duration + deltaTime), v29 = 0, !v30) )
              v29 = 1;
            if ( v28 != 0 || this->timeLeap && v29 != 0 )
            {
              v54[0].event = v23;
              v54[0].eventStop = true;
              mgTimelineController::HandleEvent(this, context: v54, a3: v17);
            }
            ++v21;
            ++v22;
          }
          while ( v21 < v13->events.num );
        }
      }
      num = this->tracks.num;
      ++v11;
      ++v12;
    }
    while ( v11 < num );
  }
  v31 = 0;
  if ( num > 0 )
  {
    v32 = 0;
    do
    {
      v33 = &this->tracks.list[v32];
      if ( time < v33->timeSpan.min || (v34 = 1, time >= v33->timeSpan.max) )
        v34 = 0;
      if ( v34 != 0 )
      {
        v35 = v33->target.spawnId.value & 0x1FFF;
        v36 = v33->target.spawnId.value >> 13;
        v54[0].track = &this->tracks.list[v32];
        v37 = gameLocal->spawnIds.ptr[v35];
        if ( v37 == v36 && (v38 = gameLocal->entities.ptr[v35]) != nullptr )
          v39 = idEntity::CastTo(c: v38);
        else
          v39 = nullptr;
        v40 = v33->events.num;
        entity = (idLight *)v39;
        v54[0].updateVisibility = false;
        v42 = 0;
        v54[0].entity = v39;
        v54[0].eventStop = false;
        if ( v40 > 0 )
        {
          v43 = 0;
          do
          {
            v44 = &v33->events.list[v43];
            if ( this->timeLeap )
            {
              v45 = v44->time;
            }
            else
            {
              v46 = 32;
              if ( v44->type == TL_EVENT_ANIM )
              {
                idAnimCamera::IsTypeOf(c: entity);
                v46 = 0;
              }
              v45 = v46 + v44->time;
            }
            v47 = time - v45;
            if ( v47 >= 0 && v47 < v44->duration )
            {
              v54[0].event = v44;
              v54[0].eventTime = v47;
              v54[0].eventStart = ((((deltaTime ^ v47) & 0x80000000) == 0) + (v47 >= deltaTime)) & 1;
              mgTimelineController::HandleEvent(this, context: v54, a3: v37);
              entity = (idLight *)v54[0].entity;
            }
            ++v42;
            ++v43;
          }
          while ( v42 < v33->events.num );
        }
        if ( v54[0].updateVisibility && entity != nullptr )
        {
          v48 = (unsigned __int8 *)idLight::CastTo(c: entity);
          v49 = (idLight *)v48;
          if ( v48 != nullptr )
          {
            if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v48) != 0 )
              idLight::Off(this: v49);
            else
              idLight::On(this: v49);
          }
        }
      }
      ++v31;
      ++v32;
    }
    while ( v31 < this->tracks.num );
  }
  v51 = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( v51 != nullptr && clientGame->renderWorld[35042].__vftable != nullptr )
  {
    presentable = v51->presentable;
    if ( presentable != nullptr )
      v53 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v53 = 0;
    idView::SetEnvironmentOverride(this: (idView *)(v53 + 16224), env: nullptr, blendDuration: -1.0, modelIndex: v50);
  }
}


// ========================================================================
// ?StopPlayback@mgEditorTimelineInterface@@UAAXXZ
// EA  : 0x82CEC420
// RVA : 0x00CEC420
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgEditorTimelineInterface::StopPlayback(mgEditorTimelineInterface *this)
{
  mgTimelineController *v1; // r3
  mgTimelineController *v2; // r3

  v1 = (mgTimelineController *)this->GetEntity(this);
  v2 = mgTimelineController::CastTo(c: v1);
  if ( v2 != nullptr )
    mgTimelineController::Stop(this: v2);
}


// ========================================================================
// ??0tlTrack_t@mgTimelineController@@QAA@XZ
// EA  : 0x82CEC4C8
// RVA : 0x00CEC4C8
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

mgTimelineController::tlTrack_t *__fastcall mgTimelineController::tlTrack_t::tlTrack_t(
        mgTimelineController::tlTrack_t *this)
{
  this->target.spawnId.value = 0x1FFF;
  this->events.granularity = 0;
  this->events.memTag = 5;
  this->events.listStatic = 0;
  this->events.list = nullptr;
  this->events.size = 0;
  this->events.num = 0;
  this->animator = nullptr;
  this->faceAnimator = nullptr;
  this->grouping.groupId = -1;
  this->grouping.belongsToId = -1;
  return this;
}


// ========================================================================
// ??1tlTrack_t@mgTimelineController@@QAA@XZ
// EA  : 0x82CEC510
// RVA : 0x00CEC510
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::tlTrack_t::~tlTrack_t(mgTimelineController::tlTrack_t *this)
{
  idEntity *v2; // r3
  idEntity *v3; // r3
  idEntity *v4; // r29
  idAnimator_Channel *animator; // r28
  idAnimStack *v6; // r3
  idAnimator_FaceTracks *faceAnimator; // r28
  idAnimStack *v8; // r3
  idAnimator_Channel *v9; // r3
  idAnimator_FaceTracks *v10; // r3
  mgTimelineController::tlEvent_t *list; // r3

  if ( gameLocal != nullptr
    && gameLocal->spawnIds.ptr[this->target.spawnId.value & 0x1FFF] == this->target.spawnId.value >> 13 )
  {
    v2 = gameLocal->entities.ptr[this->target.spawnId.value & 0x1FFF];
    if ( v2 != nullptr )
    {
      v3 = idEntity::CastTo(c: v2);
      v4 = v3;
      if ( v3 != nullptr )
      {
        animator = this->animator;
        if ( animator != nullptr )
        {
          v6 = v3->GetAnimStack_2(this: v3);
          idAnimStack::RemoveAnimator(this: v6, animator);
        }
        faceAnimator = this->faceAnimator;
        if ( faceAnimator != nullptr )
        {
          v8 = v4->GetAnimStack_2(this: v4);
          idAnimStack::RemoveAnimator(this: v8, animator: faceAnimator);
        }
      }
    }
  }
  v9 = this->animator;
  if ( v9 != nullptr )
    ((void (__fastcall *)(idAnimator_Channel *, int))v9->dtr_idAnimator_Base)(a1: v9, a2: 1);
  v10 = this->faceAnimator;
  this->animator = nullptr;
  if ( v10 != nullptr )
    ((void (__fastcall *)(idAnimator_FaceTracks *, int))v10->dtr_idAnimator_Base)(a1: v10, a2: 1);
  this->faceAnimator = nullptr;
  if ( this->events.listStatic == 0 || this->events.listStatic == 2 )
  {
    list = this->events.list;
    if ( list != nullptr )
      idListArrayDelete<mgTimelineController::tlEvent_t>(ptr: list, num: this->events.size);
    this->events.list = nullptr;
    this->events.size = 0;
  }
  this->events.num = 0;
}


// ========================================================================
// __unwind$500183
// EA  : 0x82CEC650
// RVA : 0x00CEC650
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void _unwind_500183()
{
  int v0; // r12

  idList<mgTimelineController::tlEvent_t,5>::Clear(this: (idList<mgTimelineController::tlEvent_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?OnActivate@mgTimelineController@@UAAXPAVidEntity@@@Z
// EA  : 0x82CEC680
// RVA : 0x00CEC680
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::OnActivate(mgTimelineController *this, idEntity *entity)
{
  int GameMsPerFrame; // r29
  signed int v5; // r30

  gameLocal->GetGameTimeManager(this: gameLocal);
  idGameTimeManager::SetGameHz(hz: 30);
  if ( entity != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  this->startTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->prevTime = 0;
  idEntity::BecomeActive(this, flags: 1);
  mgTimelineController::Init(this);
  __twllei(v5, 0);
  __twlgei(v5 & ~(__ROL4__(960 * GameMsPerFrame, 1) - 1), 0xFFFFFFFF);
  mgTimelineController::RunEvents(this, time: 0, deltaTime: 960 * GameMsPerFrame / v5);
}


// ========================================================================
// ?Think@mgTimelineController@@UAAXXZ
// EA  : 0x82CEC780
// RVA : 0x00CEC780
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::Think(mgTimelineController *this)
{
  int GameMs; // r3
  int prevTime; // r8
  int v4; // r7
  BOOL timeLeap; // r6
  int v6; // r29
  unsigned int v7; // r11
  unsigned int v8; // r5
  int GameMsPerFrame; // r3
  unsigned int v10; // r5
  unsigned int v11; // r11

  mgTimelineController::Init(this);
  if ( this->startTime >= 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    prevTime = this->prevTime;
    v4 = GameMs - this->startTime;
    timeLeap = this->timeLeap;
    v6 = 960 * v4 / (timeManager.gameTimePerFrame.value * timeManager.gameHz);
    v7 = (timeManager.gameTimePerFrame.value * timeManager.gameHz) & ~(__ROL4__(960 * v4, 1) - 1);
    __twllei(timeManager.gameTimePerFrame.value * timeManager.gameHz, 0);
    this->prevTime = v6;
    v8 = v6 - prevTime;
    __twlgei(v7, 0xFFFFFFFF);
    if ( timeLeap )
    {
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v10 = 960 * GameMsPerFrame / (timeManager.gameTimePerFrame.value * timeManager.gameHz);
      v11 = (timeManager.gameTimePerFrame.value * timeManager.gameHz) & ~(__ROL4__(960 * GameMsPerFrame, 1) - 1);
      __twllei(timeManager.gameTimePerFrame.value * timeManager.gameHz, 0);
      __twlgei(v11, 0xFFFFFFFF);
      mgTimelineController::RunEvents(this, time: v6, deltaTime: v10);
      this->timeLeap = false;
    }
    else if ( v6 <= this->timeSpan.max )
    {
      if ( v6 > 0 && v8 != 0 )
        mgTimelineController::RunEvents(this, time: v6, deltaTime: v8);
    }
    else
    {
      idEntity::BecomeInactive(this, flags: 1);
      this->startTime = -1;
    }
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// ?Restart@mgTimelineController@@QAAXXZ
// EA  : 0x82CEC8C0
// RVA : 0x00CEC8C0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::Restart(mgTimelineController *this)
{
  idPlayer *Player; // r3

  if ( this->startTime >= 0 )
    mgTimelineController::Stop(this);
  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  this->OnActivate(this, a2: Player);
}


// ========================================================================
// ?RestartPlayback@mgEditorTimelineInterface@@UAAXXZ
// EA  : 0x82CEC920
// RVA : 0x00CEC920
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgEditorTimelineInterface::RestartPlayback(mgEditorTimelineInterface *this)
{
  mgTimelineController *v1; // r3
  mgTimelineController *v2; // r3

  v1 = (mgTimelineController *)this->GetEntity(this);
  v2 = mgTimelineController::CastTo(c: v1);
  if ( v2 != nullptr )
    mgTimelineController::Restart(this: v2);
}


// ========================================================================
// ??4tlTrack_t@mgTimelineController@@QAAAAU01@ABU01@@Z
// EA  : 0x82CECA40
// RVA : 0x00CECA40
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

mgTimelineController::tlTrack_t *__fastcall mgTimelineController::tlTrack_t::operator=(
        mgTimelineController::tlTrack_t *this,
        const mgTimelineController::tlTrack_t *rhs)
{
  this->target.spawnId.value = rhs->target.spawnId.value;
  idList<mgTimelineController::tlEvent_t,5>::operator=(this: &this->events, other: &rhs->events);
  this->grouping = rhs->grouping;
  this->timeSpan = rhs->timeSpan;
  this->pos = rhs->pos;
  return this;
}


// ========================================================================
// ??0mgTimelineController@@QAA@XZ
// EA  : 0x82CECAD0
// RVA : 0x00CECAD0
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

mgTimelineController *__fastcall mgTimelineController::mgTimelineController(mgTimelineController *this)
{
  idEntity::idEntity(this);
  this->__vftable = (mgTimelineController_vtbl *)&mgTimelineController::`vftable';
  this->tracks.granularity = 0;
  this->tracks.memTag = 5;
  this->tracks.listStatic = 0;
  this->tracks.list = nullptr;
  this->tracks.size = 0;
  this->tracks.num = 0;
  this->activator.spawnId.value = 0x1FFF;
  this->initDone = false;
  this->timeLeap = false;
  this->startTime = -1;
  this->prevTime = -1;
  return this;
}


// ========================================================================
// __unwind$500636
// EA  : 0x82CECB64
// RVA : 0x00CECB64
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void _unwind_500636()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1mgTimelineController@@UAA@XZ
// EA  : 0x82CECB98
// RVA : 0x00CECB98
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void __fastcall mgTimelineController::~mgTimelineController(mgTimelineController *this)
{
  mgTimelineController::tlTrack_t *list; // r3

  this->__vftable = (mgTimelineController_vtbl *)&mgTimelineController::`vftable';
  if ( this->tracks.listStatic == 0 || this->tracks.listStatic == 2 )
  {
    list = this->tracks.list;
    if ( list != nullptr )
      idListArrayDelete<mgTimelineController::tlTrack_t>(ptr: list, num: this->tracks.size);
    this->tracks.list = nullptr;
    this->tracks.size = 0;
  }
  this->tracks.num = 0;
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$500892
// EA  : 0x82CECC04
// RVA : 0x00CECC04
// PDB : w:\tech5\tungsten\game\entities\timeline\timelinecontroller.cpp
// ========================================================================

void _unwind_500892()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}

