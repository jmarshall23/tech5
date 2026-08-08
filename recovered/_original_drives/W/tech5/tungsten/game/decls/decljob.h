
// ========================================================================
// ??0jobSpawnInfo_t@idDeclJob@@QAA@XZ
// EA  : 0x82BC70A8
// RVA : 0x00BC70A8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJob::jobSpawnInfo_t *__fastcall idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t(idDeclJob::jobSpawnInfo_t *this)
{
  this->spawnSpot.len = 0;
  this->spawnSpot.data = this->spawnSpot.baseBuffer;
  this->spawnSpot.allocedAndFlag = 20;
  this->spawnSpot.baseBuffer[0] = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.len = 0;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  this->layerList.list = nullptr;
  this->layerList.granularity = 0;
  this->layerList.memTag = 5;
  this->layerList.listStatic = 0;
  this->layerList.size = 0;
  this->layerList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layerList);
  this->layerListDeactive.list = nullptr;
  this->layerListDeactive.granularity = 0;
  this->layerListDeactive.memTag = 5;
  this->layerListDeactive.listStatic = 0;
  this->layerListDeactive.size = 0;
  this->layerListDeactive.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->layerListDeactive);
  this->hideVehicles = false;
  this->delayTime = 1500;
  return this;
}


// ========================================================================
// __unwind$489969
// EA  : 0x82BC7150
// RVA : 0x00BC7150
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_489969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489970
// EA  : 0x82BC7178
// RVA : 0x00BC7178
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_489970()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$489971
// EA  : 0x82BC71A4
// RVA : 0x00BC71A4
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_489971()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// ??0jobNoteInfo_t@idDeclJob@@QAA@XZ
// EA  : 0x82BC71D8
// RVA : 0x00BC71D8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJob::jobNoteInfo_t *__fastcall idDeclJob::jobNoteInfo_t::jobNoteInfo_t(idDeclJob::jobNoteInfo_t *this)
{
  this->acceptJobNotes.list = nullptr;
  this->acceptJobNotes.granularity = 0;
  this->acceptJobNotes.memTag = 5;
  this->acceptJobNotes.listStatic = 0;
  this->acceptJobNotes.size = 0;
  this->acceptJobNotes.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->acceptJobNotesRemove.list = nullptr;
  this->acceptJobNotesRemove.granularity = 0;
  this->acceptJobNotesRemove.memTag = 5;
  this->acceptJobNotesRemove.listStatic = 0;
  this->acceptJobNotesRemove.size = 0;
  this->acceptJobNotesRemove.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->acceptJobNotesRemove);
  this->readyJobNotes.list = nullptr;
  this->readyJobNotes.granularity = 0;
  this->readyJobNotes.memTag = 5;
  this->readyJobNotes.listStatic = 0;
  this->readyJobNotes.size = 0;
  this->readyJobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->readyJobNotes);
  this->readyJobNotesRemove.list = nullptr;
  this->readyJobNotesRemove.granularity = 0;
  this->readyJobNotesRemove.memTag = 5;
  this->readyJobNotesRemove.listStatic = 0;
  this->readyJobNotesRemove.size = 0;
  this->readyJobNotesRemove.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->readyJobNotesRemove);
  this->completeJobNotes.list = nullptr;
  this->completeJobNotes.granularity = 0;
  this->completeJobNotes.memTag = 5;
  this->completeJobNotes.listStatic = 0;
  this->completeJobNotes.size = 0;
  this->completeJobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->completeJobNotes);
  this->completeJobNotesRemove.list = nullptr;
  this->completeJobNotesRemove.granularity = 0;
  this->completeJobNotesRemove.memTag = 5;
  this->completeJobNotesRemove.listStatic = 0;
  this->completeJobNotesRemove.size = 0;
  this->completeJobNotesRemove.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->completeJobNotesRemove);
  this->relevantMapNotesRemove.list = nullptr;
  this->relevantMapNotesRemove.granularity = 0;
  this->relevantMapNotesRemove.memTag = 5;
  this->relevantMapNotesRemove.listStatic = 0;
  this->relevantMapNotesRemove.size = 0;
  this->relevantMapNotesRemove.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relevantMapNotesRemove);
  this->relevantMapNotes.list = nullptr;
  this->relevantMapNotes.granularity = 0;
  this->relevantMapNotes.memTag = 5;
  this->relevantMapNotes.listStatic = 0;
  this->relevantMapNotes.size = 0;
  this->relevantMapNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relevantMapNotes);
  return this;
}


// ========================================================================
// __unwind$490051
// EA  : 0x82BC7300
// RVA : 0x00BC7300
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490051()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490052_0
// EA  : 0x82BC7328
// RVA : 0x00BC7328
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490052_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$490053_1
// EA  : 0x82BC7354
// RVA : 0x00BC7354
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490053_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$490054_0
// EA  : 0x82BC7380
// RVA : 0x00BC7380
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490054_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$490055
// EA  : 0x82BC73AC
// RVA : 0x00BC73AC
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490055()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$490056
// EA  : 0x82BC73D8
// RVA : 0x00BC73D8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490056()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// __unwind$490057
// EA  : 0x82BC7404
// RVA : 0x00BC7404
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490057()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 96));
}


// ========================================================================
// ??0jobAutoTransitionInfo_t@idDeclJob@@QAA@XZ
// EA  : 0x82BC7778
// RVA : 0x00BC7778
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJob::jobAutoTransitionInfo_t *__fastcall idDeclJob::jobAutoTransitionInfo_t::jobAutoTransitionInfo_t(
        idDeclJob::jobAutoTransitionInfo_t *this)
{
  idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t(this: &this->acceptSpawnInfo);
  idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t(this: &this->readySpawnInfo);
  idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t(this: &this->completeSpawnInfo);
  idDeclJob::jobSpawnInfo_t::jobSpawnInfo_t(this: &this->failSpawnInfo);
  return this;
}


// ========================================================================
// __unwind$490355
// EA  : 0x82BC77D0
// RVA : 0x00BC77D0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490355()
{
  int v0; // r12

  idDeclJob::jobSpawnInfo_t::~jobSpawnInfo_t(this: *(idDeclJob::jobSpawnInfo_t **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490356
// EA  : 0x82BC77F8
// RVA : 0x00BC77F8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490356()
{
  int v0; // r12

  idDeclJob::jobSpawnInfo_t::~jobSpawnInfo_t(this: (idDeclJob::jobSpawnInfo_t *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$490357
// EA  : 0x82BC7824
// RVA : 0x00BC7824
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490357()
{
  int v0; // r12

  idDeclJob::jobSpawnInfo_t::~jobSpawnInfo_t(this: (idDeclJob::jobSpawnInfo_t *)(*(_DWORD *)(v0 - 112 + 132) + 208));
}


// ========================================================================
// ??0jobDebugMasterInfo_t@idDeclJob@@QAA@XZ
// EA  : 0x82BC7858
// RVA : 0x00BC7858
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJob::jobDebugMasterInfo_t *__fastcall idDeclJob::jobDebugMasterInfo_t::jobDebugMasterInfo_t(
        idDeclJob::jobDebugMasterInfo_t *this)
{
  this->debug_accepted.debugRewards.list = nullptr;
  this->debug_accepted.debugRewards.granularity = 0;
  this->debug_accepted.debugRewards.memTag = 5;
  this->debug_accepted.debugRewards.listStatic = 0;
  this->debug_accepted.debugRewards.size = 0;
  this->debug_accepted.debugRewards.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->debug_readyToTurnIn.debugRewards.list = nullptr;
  this->debug_readyToTurnIn.debugRewards.granularity = 0;
  this->debug_readyToTurnIn.debugRewards.memTag = 5;
  this->debug_readyToTurnIn.debugRewards.listStatic = 0;
  this->debug_readyToTurnIn.debugRewards.size = 0;
  this->debug_readyToTurnIn.debugRewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debug_readyToTurnIn);
  this->debug_completed.debugRewards.list = nullptr;
  this->debug_completed.debugRewards.granularity = 0;
  this->debug_completed.debugRewards.memTag = 5;
  this->debug_completed.debugRewards.listStatic = 0;
  this->debug_completed.debugRewards.size = 0;
  this->debug_completed.debugRewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debug_completed);
  return this;
}


// ========================================================================
// __unwind$490384_0
// EA  : 0x82BC78E0
// RVA : 0x00BC78E0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490384_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490385_0
// EA  : 0x82BC7908
// RVA : 0x00BC7908
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_490385_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?GetDeclInfo@idDeclJob@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC7EA0
// RVA : 0x00BC7EA0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclJob> *__fastcall idDeclJob::GetDeclInfo(idDeclJob *this)
{
  return &idDeclJob::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclGameStateInt@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC400
// RVA : 0x00BCC400
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclGameStateInt> *__fastcall idDeclGameStateInt::GetDeclInfo(idDeclGameStateInt *this)
{
  return &idDeclGameStateInt::resourceList;
}


// ========================================================================
// ??0idDeclJobNote@@QAA@XZ
// EA  : 0x82BCC410
// RVA : 0x00BCC410
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJobNote *__fastcall idDeclJobNote::idDeclJobNote(idDeclJobNote *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclJobNote_vtbl *)&idDeclJobNote::`vftable';
  this->jobDeclReference.len = 0;
  this->jobDeclReference.allocedAndFlag = 20;
  this->jobDeclReference.data = this->jobDeclReference.baseBuffer;
  this->jobDeclReference.baseBuffer[0] = 0;
  this->hudInformation.index = -1;
  this->removeNote = nullptr;
  this->waypointEntOverride.allocedAndFlag = 20;
  this->waypointEntOverride.data = this->waypointEntOverride.baseBuffer;
  this->waypointEntOverride.len = 0;
  this->waypointEntOverride.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclJobNote@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC490
// RVA : 0x00BCC490
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclJobNote> *__fastcall idDeclJobNote::GetDeclInfo(idDeclJobNote *this)
{
  return &idDeclJobNote::resourceList;
}


// ========================================================================
// ??0idDeclJobTimerEvent@@QAA@XZ
// EA  : 0x82BCC550
// RVA : 0x00BCC550
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJobTimerEvent *__fastcall idDeclJobTimerEvent::idDeclJobTimerEvent(idDeclJobTimerEvent *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclJobTimerEvent_vtbl *)&idDeclJobTimerEvent::`vftable';
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.len = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.baseBuffer[0] = 0;
  this->spawnSpot.allocedAndFlag = 20;
  this->spawnSpot.data = this->spawnSpot.baseBuffer;
  this->spawnSpot.len = 0;
  this->spawnSpot.baseBuffer[0] = 0;
  this->countDownTimer = false;
  this->countDownTime = 300000;
  this->garage = GARAGE_WELLSPRING;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclJobTimerEvent@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC5E0
// RVA : 0x00BCC5E0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclJobTimerEvent> *__fastcall idDeclJobTimerEvent::GetDeclInfo(idDeclJobTimerEvent *this)
{
  return &idDeclJobTimerEvent::resourceList;
}


// ========================================================================
// ??0idDeclRecipe@@QAA@XZ
// EA  : 0x82BD2A90
// RVA : 0x00BD2A90
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclRecipe *__fastcall idDeclRecipe::idDeclRecipe(idDeclRecipe *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclRecipe_vtbl *)&idDeclRecipe::`vftable';
  this->ingredients.list = nullptr;
  this->ingredients.granularity = 0;
  this->ingredients.memTag = 5;
  this->ingredients.listStatic = 0;
  this->ingredients.size = 0;
  this->ingredients.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->ingredients);
  this->produces = nullptr;
  this->recipeToReplace = nullptr;
  this->minCount = 1;
  this->maxCount = 1;
  this->boostMinCount = 1;
  this->boostMaxCount = 1;
  return this;
}


// ========================================================================
// __unwind$500958
// EA  : 0x82BD2B08
// RVA : 0x00BD2B08
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_500958()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclRecipe@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD2B30
// RVA : 0x00BD2B30
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclRecipe> *__fastcall idDeclRecipe::GetDeclInfo(idDeclRecipe *this)
{
  return &idDeclRecipe::resourceList;
}


// ========================================================================
// ??0idDeclSpecialEvent@@QAA@XZ
// EA  : 0x82BD2BC0
// RVA : 0x00BD2BC0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclSpecialEvent *__fastcall idDeclSpecialEvent::idDeclSpecialEvent(idDeclSpecialEvent *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->specialEventType = SPECIAL_EVENT_JUMP;
  this->__vftable = (idDeclSpecialEvent_vtbl *)&idDeclSpecialEvent::`vftable';
  this->eventHudText.index = -1;
  this->eventShortText.index = -1;
  this->addLayers.list = nullptr;
  this->addLayers.granularity = 0;
  this->addLayers.memTag = 5;
  this->addLayers.listStatic = 0;
  this->addLayers.size = 0;
  this->addLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->addLayers);
  this->addDeactiveLayers.list = nullptr;
  this->addDeactiveLayers.granularity = 0;
  this->addDeactiveLayers.memTag = 5;
  this->addDeactiveLayers.listStatic = 0;
  this->addDeactiveLayers.size = 0;
  this->addDeactiveLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->addDeactiveLayers);
  this->removeLayers.list = nullptr;
  this->removeLayers.granularity = 0;
  this->removeLayers.memTag = 5;
  this->removeLayers.listStatic = 0;
  this->removeLayers.size = 0;
  this->removeLayers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeLayers);
  this->rewards.list = nullptr;
  this->rewards.granularity = 0;
  this->rewards.memTag = 5;
  this->rewards.listStatic = 0;
  this->rewards.size = 0;
  this->rewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rewards);
  this->cameras.list = nullptr;
  this->cameras.granularity = 0;
  this->cameras.memTag = 5;
  this->cameras.listStatic = 0;
  this->cameras.size = 0;
  this->cameras.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cameras);
  this->cameraIndex = -1;
  return this;
}


// ========================================================================
// __unwind$501002_0
// EA  : 0x82BD2CC0
// RVA : 0x00BD2CC0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_501002_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$501003_0
// EA  : 0x82BD2CE8
// RVA : 0x00BD2CE8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_501003_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 76));
}


// ========================================================================
// __unwind$501004
// EA  : 0x82BD2D14
// RVA : 0x00BD2D14
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_501004()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}


// ========================================================================
// __unwind$501005
// EA  : 0x82BD2D40
// RVA : 0x00BD2D40
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_501005()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 108));
}


// ========================================================================
// __unwind$501006
// EA  : 0x82BD2D6C
// RVA : 0x00BD2D6C
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_501006()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 124));
}


// ========================================================================
// ?GetDeclInfo@idDeclSpecialEvent@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD2D98
// RVA : 0x00BD2D98
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclSpecialEvent> *__fastcall idDeclSpecialEvent::GetDeclInfo(idDeclSpecialEvent *this)
{
  return &idDeclSpecialEvent::resourceList;
}


// ========================================================================
// ??0idDeclSpecialEvent_Area@@QAA@XZ
// EA  : 0x82BD4028
// RVA : 0x00BD4028
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclSpecialEvent_Area *__fastcall idDeclSpecialEvent_Area::idDeclSpecialEvent_Area(idDeclSpecialEvent_Area *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclSpecialEvent_Area_vtbl *)&idDeclSpecialEvent_Area::`vftable';
  this->areaHudText.index = -1;
  this->jobStingers.granularity = 0;
  this->jobStingers.listStatic = 0;
  this->jobStingers.memTag = 5;
  this->jobStingers.list = nullptr;
  this->jobStingers.size = 0;
  this->jobStingers.num = 0;
  this->defaultStinger = nullptr;
  this->relevantJobs.granularity = 0;
  this->relevantJobs.memTag = 5;
  this->relevantJobs.listStatic = 0;
  this->relevantJobs.list = nullptr;
  this->relevantJobs.size = 0;
  this->relevantJobs.num = 0;
  this->removeJobNotes.list = nullptr;
  this->removeJobNotes.granularity = 0;
  this->removeJobNotes.memTag = 5;
  this->removeJobNotes.listStatic = 0;
  this->removeJobNotes.size = 0;
  this->removeJobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->removeJobNotes);
  this->addJobNotes.list = nullptr;
  this->addJobNotes.granularity = 0;
  this->addJobNotes.memTag = 5;
  this->addJobNotes.listStatic = 0;
  this->addJobNotes.size = 0;
  this->addJobNotes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->addJobNotes);
  return this;
}


// ========================================================================
// __unwind$502140
// EA  : 0x82BD40F8
// RVA : 0x00BD40F8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502140()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$502141
// EA  : 0x82BD4120
// RVA : 0x00BD4120
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502141()
{
  int v0; // r12

  idList<idDeclSpecialEvent_Area::jobStinger_t,5>::~idList<idDeclSpecialEvent_Area::jobStinger_t,5>(this: (idList<idDeclPonytail::idPonytailJointInfo,30> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$502142
// EA  : 0x82BD414C
// RVA : 0x00BD414C
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502142()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$502143
// EA  : 0x82BD4178
// RVA : 0x00BD4178
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502143()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// ?GetDeclInfo@idDeclSpecialEvent_Area@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD41A8
// RVA : 0x00BD41A8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclSpecialEvent_Area> *__fastcall idDeclSpecialEvent_Area::GetDeclInfo(
        idDeclSpecialEvent_Area *this)
{
  return &idDeclSpecialEvent_Area::resourceList;
}


// ========================================================================
// ??0idDeclTutorialEvent@@QAA@XZ
// EA  : 0x82BD4318
// RVA : 0x00BD4318
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclTutorialEvent *__fastcall idDeclTutorialEvent::idDeclTutorialEvent(idDeclTutorialEvent *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclTutorialEvent_vtbl *)&idDeclTutorialEvent::`vftable';
  this->headingText.index = -1;
  this->bodyText.index = -1;
  this->action.allocedAndFlag = 20;
  this->action.data = this->action.baseBuffer;
  this->action.len = 0;
  this->action.baseBuffer[0] = 0;
  this->cancelActions.granularity = 0;
  this->cancelActions.memTag = 5;
  this->cancelActions.listStatic = 0;
  this->cancelActions.list = nullptr;
  this->cancelActions.size = 0;
  this->cancelActions.num = 0;
  this->tutorialImage = nullptr;
  this->type = TUTORIAL_TEXT;
  this->special = TUTORIAL_SPECIAL_NONE;
  this->bindset = 0;
  this->lowPriorityTutorial = false;
  this->skipPause = false;
  this->removeAfterMS = 5000;
  this->gameStateInt = nullptr;
  this->inventoryDecl = nullptr;
  return this;
}


// ========================================================================
// __unwind$502291
// EA  : 0x82BD43E8
// RVA : 0x00BD43E8
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502291()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$502292
// EA  : 0x82BD4410
// RVA : 0x00BD4410
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

void _unwind_502292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ?GetDeclInfo@idDeclTutorialEvent@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD4440
// RVA : 0x00BD4440
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclTutorialEvent> *__fastcall idDeclTutorialEvent::GetDeclInfo(idDeclTutorialEvent *this)
{
  return &idDeclTutorialEvent::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclDevMenuList@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD7290
// RVA : 0x00BD7290
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclInfoTemplate<idDeclDevMenuList> *__fastcall idDeclDevMenuList::GetDeclInfo(idDeclDevMenuList *this)
{
  return &idDeclDevMenuList::resourceList;
}


// ========================================================================
// ?GetJobStinger@idDeclSpecialEvent_Area@@QBA?AUjobStinger_t@1@H@Z
// EA  : 0x82E16DD0
// RVA : 0x00E16DD0
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclSpecialEvent_Area *__fastcall idDeclSpecialEvent_Area::GetJobStinger(
        idDeclSpecialEvent_Area *this,
        idDeclSpecialEvent_Area::jobStinger_t *result,
        int i)
{
  const idStr *v3; // r31

  v3 = (const idStr *)(*(_DWORD *)&result[1].job.baseBuffer[12] + 44 * i);
  idStr::idStr((idStr *)this, text: v3);
  *((_DWORD *)&this->idResource + 8) = v3[1].len;
  this->textSource = v3[1].data;
  this->textLength = v3[1].allocedAndFlag;
  return this;
}


// ========================================================================
// ?GetDebugInfo@idDeclJob@@QBA?AVjobDebugMasterInfo_t@1@XZ
// EA  : 0x82E19218
// RVA : 0x00E19218
// PDB : w:\tech5\tungsten\game\decls\decljob.h
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetDebugInfo(idDeclJob *this, idDeclJob::jobDebugMasterInfo_t *result)
{
  idDeclJob::jobDebugMasterInfo_t::jobDebugMasterInfo_t(
    (idDeclJob::jobDebugMasterInfo_t *)this,
    __that: (idDeclJob::jobDebugMasterInfo_t *)((char *)result + 932));
  return this;
}

