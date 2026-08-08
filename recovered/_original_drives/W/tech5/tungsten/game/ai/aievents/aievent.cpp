
// ========================================================================
// ??0idDeclAiEvent@@QAA@XZ
// EA  : 0x82A42BC8
// RVA : 0x00A42BC8
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idDeclAiEvent *__fastcall idDeclAiEvent::idDeclAiEvent(idDeclAiEvent *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->initialPoolSize = 8;
  this->lookAheadTime = 0.0;
  this->__vftable = (idDeclAiEvent_vtbl *)&idDeclAiEvent::`vftable';
  this->volume = 1.0;
  this->eventClass = AIEVENT_NONE;
  this->intensityScale = 1.0;
  this->priority = AIPRIORITY_VERY_LOW;
  this->radius = 0.0;
  this->duration = 0;
  this->distance = 0.0;
  this->attached = false;
  this->instigatorStimulus = false;
  idContents::idContents(this: &this->clipMask);
  this->arcWidthDegrees = 0.0;
  this->heightMin = 0.0;
  this->heightMax = 0.0;
  this->voiceMessage = VOICEMSG_MAX;
  this->delayedMessage = AIVOICE_MAX;
  this->painType = PAIN_NONE;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  return this;
}


// ========================================================================
// __unwind$487531
// EA  : 0x82A42CA8
// RVA : 0x00A42CA8
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

void _unwind_487531()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// ?GetDuration@idAIEvent@@QBAHXZ
// EA  : 0x82A42CE0
// RVA : 0x00A42CE0
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

int __fastcall idAIEvent::GetDuration(idAIEvent *this)
{
  const idDeclAiEvent *eventDecl; // r11
  int result; // r3

  eventDecl = this->eventDecl;
  result = 0;
  if ( eventDecl != nullptr )
    return eventDecl->duration;
  return result;
}


// ========================================================================
// ?GetPriority@idAIEvent@@QBAHXZ
// EA  : 0x82A42CF8
// RVA : 0x00A42CF8
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent::aiEventPriority_t __fastcall idAIEvent::GetPriority(idAIEvent *this)
{
  const idDeclAiEvent *eventDecl; // r11
  idAIEvent::aiEventPriority_t result; // r3

  eventDecl = this->eventDecl;
  result = AIPRIORITY_VERY_LOW;
  if ( eventDecl != nullptr )
    return eventDecl->priority;
  return result;
}


// ========================================================================
// ?GetInstigatorStimulus@idAIEvent@@QBA_NXZ
// EA  : 0x82A42D10
// RVA : 0x00A42D10
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

BOOL __fastcall idAIEvent::GetInstigatorStimulus(idAIEvent *this)
{
  const idDeclAiEvent *eventDecl; // r11
  BOOL result; // r3

  eventDecl = this->eventDecl;
  result = false;
  if ( eventDecl != nullptr )
    return eventDecl->instigatorStimulus;
  return result;
}


// ========================================================================
// ?GetEventClass@idAIEvent@@QBA?AW4aiEventClass_t@1@XZ
// EA  : 0x82A42D28
// RVA : 0x00A42D28
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent::aiEventClass_t __fastcall idAIEvent::GetEventClass(idAIEvent *this)
{
  const idDeclAiEvent *eventDecl; // r11
  idAIEvent::aiEventClass_t result; // r3

  eventDecl = this->eventDecl;
  result = AIEVENT_NONE;
  if ( eventDecl != nullptr )
    return eventDecl->eventClass;
  return result;
}


// ========================================================================
// ?UpdateAttached@idAIEvent@@AAA?AW4aiEventUpdateResult_t@1@H@Z
// EA  : 0x82A42D40
// RVA : 0x00A42D40
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEvent::UpdateAttached(idAIEvent *this, int curTime)
{
  int value; // r10
  idEntity *v5; // r3

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v5) != nullptr )
  {
    return this->InternalUpdateAttached(this, a2: curTime);
  }
  else
  {
    return AIUPDATE_REMOVE;
  }
}


// ========================================================================
// ?Update@idAIEvent@@QAA?AW4aiEventUpdateResult_t@1@H@Z
// EA  : 0x82A42DE0
// RVA : 0x00A42DE0
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEvent::Update(idAIEvent *this, int curTime)
{
  const idDeclAiEvent *eventDecl; // r11
  idAIEvent::aiEventUpdateResult_t result; // r3

  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    LOBYTE(eventDecl) = eventDecl->attached;
  if ( (unsigned __int8)eventDecl != 1 )
    return this->InternalUpdate(this, a2: curTime);
  result = idAIEvent::UpdateAttached(this, curTime);
  if ( result != AIUPDATE_REMOVE )
    return this->InternalUpdate(this, a2: curTime);
  return result;
}


// ========================================================================
// ??0idAIEvent@@QAA@XZ
// EA  : 0x82A42E60
// RVA : 0x00A42E60
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent *__fastcall idAIEvent::idAIEvent(idAIEvent *this)
{
  float z; // r10
  int v2; // r9

  this->__vftable = (idAIEvent_vtbl *)&idAIEvent::`vftable';
  this->eventDecl = nullptr;
  this->enabled = true;
  this->originator.spawnId.value = 0x1FFF;
  this->instigator.spawnId.value = 0x1FFF;
  this->origin = vec3_origin;
  this->stimulusOrigin.x = vec3_origin.x;
  this->stimulusOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->startTime = -1;
  this->stimulusOrigin.z = z;
  this->handle.value = -1;
  v2 = idAIEvent::numEvents++;
  this->handle.value = v2;
  return this;
}


// ========================================================================
// ?Init@idAIEvent@@QAAXPBVidDeclAiEvent@@PBVidEntity@@1ABVidVec3@@@Z
// EA  : 0x82A42EF0
// RVA : 0x00A42EF0
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

void __fastcall idAIEvent::Init(
        idAIEvent *this,
        const idDeclAiEvent *decl,
        const idEntity *originator,
        const idEntity *instigator,
        const idVec3 *origin)
{
  this->eventDecl = decl;
  if ( originator != nullptr )
    this->originator.spawnId.value = (gameLocal->spawnIds.ptr[originator->entityNumber] << 13)
                                   | originator->entityNumber;
  else
    this->originator.spawnId.value = 0x1FFF;
  if ( instigator != nullptr )
    this->instigator.spawnId.value = (gameLocal->spawnIds.ptr[instigator->entityNumber] << 13)
                                   | instigator->entityNumber;
  else
    this->instigator.spawnId.value = 0x1FFF;
  this->origin = *origin;
}


// ========================================================================
// ?InternalUpdateAttached@idAIEvent@@MAA?AW4aiEventUpdateResult_t@1@H@Z
// EA  : 0x82A42F78
// RVA : 0x00A42F78
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEvent::InternalUpdateAttached(idAIEvent *this, const int curTime)
{
  int value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r3
  idPhysics *Physics; // r3
  float *v7; // r3

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v5);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  this->origin.x = *v7;
  this->origin.y = v7[1];
  this->origin.z = v7[2];
  return AIUPDATE_OK;
}

