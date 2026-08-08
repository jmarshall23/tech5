
// ========================================================================
// ??0util_removeActorOnTriggerTouched@@QAA@XZ
// EA  : 0x82EE33C0
// RVA : 0x00EE33C0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_removeActorOnTriggerTouched *__fastcall util_removeActorOnTriggerTouched::util_removeActorOnTriggerTouched(
        util_removeActorOnTriggerTouched *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->killActor = false;
  this->__vftable = (util_removeActorOnTriggerTouched_vtbl *)&util_removeActorOnTriggerTouched::`vftable';
  this->onlyRemoveIfHidden = false;
  this->runCheckReplenishment = false;
  this->suicide = nullptr;
  return this;
}


// ========================================================================
// ?_name@util_removeActorOnTriggerTouched@@UBAPBDXZ
// EA  : 0x82EE3410
// RVA : 0x00EE3410
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_removeActorOnTriggerTouched::_name(util_removeActorOnTriggerTouched *this)
{
  return "util_removeActorOnTriggerTouched";
}


// ========================================================================
// ?_isTypeOf@util_removeActorOnTriggerTouched@@UAA_NPBD@Z
// EA  : 0x82EE3420
// RVA : 0x00EE3420
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_removeActorOnTriggerTouched::_isTypeOf(
        util_removeActorOnTriggerTouched *this,
        const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_removeActorOnTriggerTouched")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_removeActorOnTriggerTouched@@UAAPAXXZ
// EA  : 0x82EE3458
// RVA : 0x00EE3458
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_removeActorOnTriggerTouched::_getDeclPtr(util_removeActorOnTriggerTouched *this)
{
  return `util_removeActorOnTriggerTouched::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0util_triggerVisibility@@QAA@XZ
// EA  : 0x82EE3470
// RVA : 0x00EE3470
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_triggerVisibility *__fastcall util_triggerVisibility::util_triggerVisibility(util_triggerVisibility *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_triggerVisibility_vtbl *)&util_triggerVisibility::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->triggerOnVisible);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->triggerOnHidden);
  this->active = false;
  this->testLOS = true;
  this->visible = false;
  this->testFrequency = 0.0;
  this->tolerance = 1.0;
  return this;
}


// ========================================================================
// __unwind$22810
// EA  : 0x82EE34F8
// RVA : 0x00EE34F8
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_22810()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@util_triggerVisibility@@UBAPBDXZ
// EA  : 0x82EE3520
// RVA : 0x00EE3520
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_triggerVisibility::_name(util_triggerVisibility *this)
{
  return "util_triggerVisibility";
}


// ========================================================================
// ?_isTypeOf@util_triggerVisibility@@UAA_NPBD@Z
// EA  : 0x82EE3530
// RVA : 0x00EE3530
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerVisibility::_isTypeOf(util_triggerVisibility *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_triggerVisibility")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_triggerVisibility@@UAAPAXXZ
// EA  : 0x82EE3568
// RVA : 0x00EE3568
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_triggerVisibility::_getDeclPtr(util_triggerVisibility *this)
{
  return `util_triggerVisibility::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0util_triggerLookAtSafety@@QAA@XZ
// EA  : 0x82EE3580
// RVA : 0x00EE3580
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_triggerLookAtSafety *__fastcall util_triggerLookAtSafety::util_triggerLookAtSafety(util_triggerLookAtSafety *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_triggerLookAtSafety_vtbl *)&util_triggerLookAtSafety::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->lookAtEntity);
  return this;
}


// ========================================================================
// __unwind$22879
// EA  : 0x82EE35D4
// RVA : 0x00EE35D4
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_22879()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@util_triggerLookAtSafety@@UBAPBDXZ
// EA  : 0x82EE3600
// RVA : 0x00EE3600
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_triggerLookAtSafety::_name(util_triggerLookAtSafety *this)
{
  return "util_triggerLookAtSafety";
}


// ========================================================================
// ?_isTypeOf@util_triggerLookAtSafety@@UAA_NPBD@Z
// EA  : 0x82EE3610
// RVA : 0x00EE3610
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerLookAtSafety::_isTypeOf(util_triggerLookAtSafety *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_triggerLookAtSafety")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_triggerLookAtSafety@@UAAPAXXZ
// EA  : 0x82EE3648
// RVA : 0x00EE3648
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_triggerLookAtSafety::_getDeclPtr(util_triggerLookAtSafety *this)
{
  return `util_triggerLookAtSafety::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_name@util_triggerTeleport@@UBAPBDXZ
// EA  : 0x82EE3658
// RVA : 0x00EE3658
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_triggerTeleport::_name(util_triggerTeleport *this)
{
  return "util_triggerTeleport";
}


// ========================================================================
// ?_isTypeOf@util_triggerTeleport@@UAA_NPBD@Z
// EA  : 0x82EE3668
// RVA : 0x00EE3668
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerTeleport::_isTypeOf(util_triggerTeleport *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_triggerTeleport")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_triggerTeleport@@UAAPAXXZ
// EA  : 0x82EE36A0
// RVA : 0x00EE36A0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_triggerTeleport::_getDeclPtr(util_triggerTeleport *this)
{
  return `util_triggerTeleport::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_removeActorOnTriggerTouched@@UBA_NPBD@Z
// EA  : 0x82EE36B0
// RVA : 0x00EE36B0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_removeActorOnTriggerTouched::_isNotifyFunction(util_triggerTeleport *this, const char *name)
{
  return (_cntlzw(ssString::Icmp(text: "onTrigger", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ?_name@util_nodeModifierTrigger@@UBAPBDXZ
// EA  : 0x82EE36E0
// RVA : 0x00EE36E0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_nodeModifierTrigger::_name(util_nodeModifierTrigger *this)
{
  return "util_nodeModifierTrigger";
}


// ========================================================================
// ?_isTypeOf@util_nodeModifierTrigger@@UAA_NPBD@Z
// EA  : 0x82EE36F0
// RVA : 0x00EE36F0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_nodeModifierTrigger::_isTypeOf(util_nodeModifierTrigger *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_nodeModifierTrigger")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_nodeModifierTrigger@@UAAPAXXZ
// EA  : 0x82EE3728
// RVA : 0x00EE3728
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_nodeModifierTrigger::_getDeclPtr(util_nodeModifierTrigger *this)
{
  return `util_nodeModifierTrigger::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_nodeModifierTrigger@@UBA_NPBD@Z
// EA  : 0x82EE3738
// RVA : 0x00EE3738
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_nodeModifierTrigger::_isNotifyFunction(util_nodeModifierTrigger *this, const char *name)
{
  return ssString::Icmp(text: "onTrigger", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "OnActivate", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0util_triggerLookAt@@QAA@XZ
// EA  : 0x82EE4000
// RVA : 0x00EE4000
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_triggerLookAt *__fastcall util_triggerLookAt::util_triggerLookAt(util_triggerLookAt *this)
{
  int v2; // r3

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_triggerLookAt_vtbl *)&util_triggerLookAt::`vftable';
  ssString::Init(this: &this->call);
  this->safetyTriggers.data = nullptr;
  this->safetyTriggers.num = 0;
  this->safetyTriggers.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->safetyTriggers.threadId = v2;
  this->active = false;
  this->testLOS = false;
  this->inverse = false;
  this->triggerOnce = true;
  this->safetyTriggerHit = false;
  this->triggered = false;
  this->activePeriod = -1.0;
  this->tolerance = 0.0;
  this->lookTime = 0.0;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// __unwind$23433
// EA  : 0x82EE40B4
// RVA : 0x00EE40B4
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23433()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$23434
// EA  : 0x82EE40DC
// RVA : 0x00EE40DC
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23434()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ?_name@util_triggerLookAt@@UBAPBDXZ
// EA  : 0x82EE4108
// RVA : 0x00EE4108
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_triggerLookAt::_name(util_triggerLookAt *this)
{
  return "util_triggerLookAt";
}


// ========================================================================
// ?_isTypeOf@util_triggerLookAt@@UAA_NPBD@Z
// EA  : 0x82EE4118
// RVA : 0x00EE4118
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerLookAt::_isTypeOf(util_triggerLookAt *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_triggerLookAt")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_triggerLookAt@@UAAPAXXZ
// EA  : 0x82EE4150
// RVA : 0x00EE4150
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_triggerLookAt::_getDeclPtr(util_triggerLookAt *this)
{
  return `util_triggerLookAt::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0util_triggerLookAtManagerVolume@@QAA@XZ
// EA  : 0x82EE4218
// RVA : 0x00EE4218
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_triggerLookAtManagerVolume *__fastcall util_triggerLookAtManagerVolume::util_triggerLookAtManagerVolume(
        util_triggerLookAtManagerVolume *this)
{
  int v2; // r11

  idSuperScriptObject::idSuperScriptObject(this);
  v2 = 0;
  this->__vftable = (util_triggerLookAtManagerVolume_vtbl *)&util_triggerLookAtManagerVolume::`vftable';
  this->triggers.data = nullptr;
  this->triggers.num = 0;
  this->triggers.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->triggers.threadId = v2;
  this->enabled = true;
  return this;
}


// ========================================================================
// __unwind$23523
// EA  : 0x82EE42A4
// RVA : 0x00EE42A4
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23523()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@util_triggerLookAtManagerVolume@@UBAPBDXZ
// EA  : 0x82EE42D0
// RVA : 0x00EE42D0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_triggerLookAtManagerVolume::_name(util_triggerLookAtManagerVolume *this)
{
  return "util_triggerLookAtManagerVolume";
}


// ========================================================================
// ?_isTypeOf@util_triggerLookAtManagerVolume@@UAA_NPBD@Z
// EA  : 0x82EE42E0
// RVA : 0x00EE42E0
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerLookAtManagerVolume::_isTypeOf(
        util_triggerLookAtManagerVolume *this,
        const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_triggerLookAtManagerVolume")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_triggerLookAtManagerVolume@@UAAPAXXZ
// EA  : 0x82EE4318
// RVA : 0x00EE4318
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_triggerLookAtManagerVolume::_getDeclPtr(util_triggerLookAtManagerVolume *this)
{
  return `util_triggerLookAtManagerVolume::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_triggerLookAtManagerVolume@@UBA_NPBD@Z
// EA  : 0x82EE4328
// RVA : 0x00EE4328
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_triggerLookAtManagerVolume::_isNotifyFunction(
        util_triggerLookAtManagerVolume *this,
        const char *name)
{
  return ssString::Icmp(text: "onEnter", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "onExit", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0util_distanceTrigger@@QAA@XZ
// EA  : 0x82EE4420
// RVA : 0x00EE4420
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_distanceTrigger *__fastcall util_distanceTrigger::util_distanceTrigger(util_distanceTrigger *this)
{
  int v2; // r3
  int v3; // r3

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_distanceTrigger_vtbl *)&util_distanceTrigger::`vftable';
  this->ignore.x = false;
  this->ignore.y = false;
  this->ignore.z = false;
  this->targets.data = nullptr;
  this->targets.num = 0;
  this->targets.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->targets.threadId = v2;
  this->distances.data = nullptr;
  this->distances.num = 0;
  this->distances.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->distances.threadId = v3;
  this->reverse = false;
  this->speed = 50.0;
  this->ramp = 0.0;
  this->frameSpeed = 0.0;
  return this;
}


// ========================================================================
// __unwind$23593
// EA  : 0x82EE44F8
// RVA : 0x00EE44F8
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23593()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$23594
// EA  : 0x82EE4520
// RVA : 0x00EE4520
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23594()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?_name@util_distanceTrigger@@UBAPBDXZ
// EA  : 0x82EE4550
// RVA : 0x00EE4550
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_distanceTrigger::_name(util_distanceTrigger *this)
{
  return "util_distanceTrigger";
}


// ========================================================================
// ?_isTypeOf@util_distanceTrigger@@UAA_NPBD@Z
// EA  : 0x82EE4560
// RVA : 0x00EE4560
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_distanceTrigger::_isTypeOf(util_distanceTrigger *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_distanceTrigger")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_distanceTrigger@@UAAPAXXZ
// EA  : 0x82EE4598
// RVA : 0x00EE4598
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_distanceTrigger::_getDeclPtr(util_distanceTrigger *this)
{
  return `util_distanceTrigger::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0util_replaceTargets@@QAA@XZ
// EA  : 0x82EE4660
// RVA : 0x00EE4660
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

util_replaceTargets *__fastcall util_replaceTargets::util_replaceTargets(util_replaceTargets *this)
{
  int v2; // r11

  idSuperScriptObject::idSuperScriptObject(this);
  v2 = 0;
  this->__vftable = (util_replaceTargets_vtbl *)&util_replaceTargets::`vftable';
  this->newTargets.data = nullptr;
  this->newTargets.num = 0;
  this->newTargets.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->newTargets.threadId = v2;
  return this;
}


// ========================================================================
// __unwind$23693
// EA  : 0x82EE46E4
// RVA : 0x00EE46E4
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void _unwind_23693()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@util_replaceTargets@@UBAPBDXZ
// EA  : 0x82EE4710
// RVA : 0x00EE4710
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

const char *__fastcall util_replaceTargets::_name(util_replaceTargets *this)
{
  return "util_replaceTargets";
}


// ========================================================================
// ?_isTypeOf@util_replaceTargets@@UAA_NPBD@Z
// EA  : 0x82EE4720
// RVA : 0x00EE4720
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_replaceTargets::_isTypeOf(util_replaceTargets *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_replaceTargets")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_replaceTargets@@UAAPAXXZ
// EA  : 0x82EE4758
// RVA : 0x00EE4758
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_replaceTargets::_getDeclPtr(util_replaceTargets *this)
{
  return `util_replaceTargets::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_replaceTargets@@UBA_NPBD@Z
// EA  : 0x82EE4768
// RVA : 0x00EE4768
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

BOOL __fastcall util_replaceTargets::_isNotifyFunction(util_replaceTargets *this, const char *name)
{
  return ssString::Icmp(text: "OnActivate", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "onTrigger", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ?Think@util_triggerVisibility@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EF33C8
// RVA : 0x00EF33C8
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void __fastcall util_triggerVisibility::Think(idSSObject *object, void *__formal)
{
  util_triggerVisibility *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (util_triggerVisibility *)_RTDynamicCast(
                                   inptr: object,
                                   VfDelta: 0,
                                   SrcType: &idSSObject `RTTI Type Descriptor',
                                   TargetType: &util_triggerVisibility `RTTI Type Descriptor',
                                   isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  util_triggerVisibility::Think(this: v3);
}


// ========================================================================
// ?SetLookAtEntity@?$ssObject@Vutil_triggerLookAtSafety@@@@QAAXVssEntity@@@Z
// EA  : 0x82EF3448
// RVA : 0x00EF3448
// PDB : w:\tech5\tungsten\superscript\generated\util\triggerutil.h
// ========================================================================

void __fastcall ssObject<util_triggerLookAtSafety>::SetLookAtEntity(
        ssObject<util_triggerLookAtSafety> *this,
        ssEntity *ent)
{
  idSSObject *v3; // r3
  ssEntity *v4; // r31
  const ssEntity *v5; // r3
  ssEntity v6; // [sp+50h] [-20h] BYREF

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (ssEntity *)_RTDynamicCast(
                     inptr: v3,
                     VfDelta: 0,
                     SrcType: &idSSObject `RTTI Type Descriptor',
                     TargetType: &util_triggerLookAtSafety `RTTI Type Descriptor',
                     isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity(this: &v6, e: ent);
    ssEntity::ssEntity(this: v4 + 2, e: v5);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
  }
}

