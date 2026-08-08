
// ========================================================================
// ??0idScriptMapEntity@@QAA@XZ
// EA  : 0x82CB6110
// RVA : 0x00CB6110
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

idScriptMapEntity *__fastcall idScriptMapEntity::idScriptMapEntity(idScriptMapEntity *this)
{
  idEntity::idEntity(this);
  this->startActive = false;
  this->__vftable = (idScriptMapEntity_vtbl *)&idScriptMapEntity::`vftable';
  this->stateThread = nullptr;
  return this;
}


// ========================================================================
// ??1idScriptMapEntity@@UAA@XZ
// EA  : 0x82CB6160
// RVA : 0x00CB6160
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void __fastcall idScriptMapEntity::~idScriptMapEntity(idScriptMapEntity *this)
{
  idStateThread *stateThread; // r3

  this->__vftable = (idScriptMapEntity_vtbl *)&idScriptMapEntity::`vftable';
  stateThread = this->stateThread;
  if ( stateThread != nullptr )
    ((void (__fastcall *)(idStateThread *, int))stateThread->dtr_idClass)(a1: stateThread, a2: 1);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$487395
// EA  : 0x82CB61D0
// RVA : 0x00CB61D0
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void _unwind_487395()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idScriptMapEntity@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB61F8
// RVA : 0x00CB61F8
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void __fastcall idScriptMapEntity::OnActivate(idScriptMapEntity *this, idEntity *activator)
{
  idScriptObject *v3; // r3

  v3 = (idScriptObject *)((int (__fastcall *)(idScriptMapEntity *, idEntity *))this->GetScriptObject_2)(
                           a1: this,
                           a2: activator);
  if ( idScriptObject::GetFunction(this: v3, name: "Think") != nullptr )
    idStateThread::SetState(this: this->stateThread, statename: "Think");
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Think@idScriptMapEntity@@UAAXXZ
// EA  : 0x82CB62C8
// RVA : 0x00CB62C8
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void __fastcall idScriptMapEntity::Think(idScriptMapEntity *this)
{
  idStateThread *stateThread; // r3

  if ( (this->thinkFlags & 1) != 0 )
  {
    stateThread = this->stateThread;
    if ( stateThread != nullptr )
      idStateThread::UpdateScript(this: stateThread);
  }
}


// ========================================================================
// ?Event_Deactivate@idScriptMapEntity@@QAA?AVeventVoid@@XZ
// EA  : 0x82CB62F0
// RVA : 0x00CB62F0
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

idScriptMapEntity *__fastcall idScriptMapEntity::Event_Deactivate(idScriptMapEntity *this, idEntity *result)
{
  idEntity::BecomeInactive(this: result, flags: 7);
  return this;
}


// ========================================================================
// ?Spawn@idScriptMapEntity@@QAAXXZ
// EA  : 0x82CB6330
// RVA : 0x00CB6330
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void __fastcall idScriptMapEntity::Spawn(idScriptMapEntity *this)
{
  idStateThread *v2; // r3
  idStateThread *v3; // r3
  idScriptObject *v4; // r3
  idScriptObject *v5; // r3

  v2 = (idStateThread *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x1BA0u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idStateThread::idStateThread(this: v2);
  else
    v3 = nullptr;
  this->stateThread = v3;
  idThread::ManualDelete(this: v3);
  idThread::SetThreadName(this: this->stateThread, name: this->name.data);
  this->stateThread->entity.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  v4 = this->GetScriptObject_2(this);
  if ( idScriptObject::GetFunction(this: v4, name: "init") != nullptr )
    idStateThread::CallConstructor(this: this->stateThread);
  if ( this->startActive )
  {
    v5 = this->GetScriptObject_2(this);
    if ( idScriptObject::GetFunction(this: v5, name: "Think") != nullptr )
      idStateThread::SetState(this: this->stateThread, statename: "Think");
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 7);
  }
}


// ========================================================================
// __unwind$487821_0
// EA  : 0x82CB6454
// RVA : 0x00CB6454
// PDB : w:\tech5\tungsten\game\entities\scriptmapentity.cpp
// ========================================================================

void __fastcall _unwind_487821_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}

