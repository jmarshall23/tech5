
// ========================================================================
// ??0util_entityFlagActivate@@QAA@XZ
// EA  : 0x82EE4E18
// RVA : 0x00EE4E18
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

util_entityFlagActivate *__fastcall util_entityFlagActivate::util_entityFlagActivate(util_entityFlagActivate *this)
{
  int v2; // r3
  int v3; // r3

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_entityFlagActivate_vtbl *)&util_entityFlagActivate::`vftable';
  ssString::Init(this: &this->targetEntity);
  this->defineFlags.data = nullptr;
  this->defineFlags.num = 0;
  this->defineFlags.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->defineFlags.threadId = v2;
  this->activateFlags.data = nullptr;
  this->activateFlags.num = 0;
  this->activateFlags.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->activateFlags.threadId = v3;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->target);
  ssString::operator=(this: &this->targetEntity, text: "world");
  this->activateBehavior = UNCHANGED;
  this->activatedCount = 0;
  this->count = 1;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// __unwind$23986
// EA  : 0x82EE4F00
// RVA : 0x00EE4F00
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_23986()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$23987
// EA  : 0x82EE4F28
// RVA : 0x00EE4F28
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_23987()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 144 + 164) + 8));
}


// ========================================================================
// __unwind$23988
// EA  : 0x82EE4F54
// RVA : 0x00EE4F54
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_23988()
{
  int v0; // r12

  ssList<ssString>::~ssList<ssString>(this: (ssList<ssString> *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// __unwind$23989
// EA  : 0x82EE4F80
// RVA : 0x00EE4F80
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_23989()
{
  int v0; // r12

  ssList<ssString>::~ssList<ssString>(this: (ssList<ssString> *)(*(_DWORD *)(v0 - 144 + 164) + 44));
}


// ========================================================================
// ?_name@util_entityFlagActivate@@UBAPBDXZ
// EA  : 0x82EE4FB0
// RVA : 0x00EE4FB0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

const char *__fastcall util_entityFlagActivate::_name(util_entityFlagActivate *this)
{
  return "util_entityFlagActivate";
}


// ========================================================================
// ?_isTypeOf@util_entityFlagActivate@@UAA_NPBD@Z
// EA  : 0x82EE4FC0
// RVA : 0x00EE4FC0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlagActivate::_isTypeOf(util_entityFlagActivate *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_entityFlagActivate")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_entityFlagActivate@@UAAPAXXZ
// EA  : 0x82EE4FF8
// RVA : 0x00EE4FF8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

ssDeclInfo_t *__fastcall util_entityFlagActivate::_getDeclPtr(util_entityFlagActivate *this)
{
  return `util_entityFlagActivate::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_entityFlagActivate@@UBA_NPBD@Z
// EA  : 0x82EE5008
// RVA : 0x00EE5008
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlagActivate::_isNotifyFunction(util_entityFlagActivate *this, const char *name)
{
  return ssString::Icmp(text: "OnTrigger", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "OnActivate", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0util_entityFlagVolume@@QAA@XZ
// EA  : 0x82EE5168
// RVA : 0x00EE5168
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

util_entityFlagVolume *__fastcall util_entityFlagVolume::util_entityFlagVolume(util_entityFlagVolume *this)
{
  int v2; // r3

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_entityFlagVolume_vtbl *)&util_entityFlagVolume::`vftable';
  ssString::Init(this: &this->flag);
  this->filter.data = nullptr;
  this->filter.num = 0;
  this->filter.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->filter.threadId = v2;
  ssString::Init(this: &this->callEnter);
  ssString::Init(this: &this->callExit);
  ssString::operator=(this: &this->flag, text: "VolumeOccupied");
  this->enteredCount = 0;
  return this;
}


// ========================================================================
// __unwind$24104
// EA  : 0x82EE520C
// RVA : 0x00EE520C
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24104()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$24105
// EA  : 0x82EE5234
// RVA : 0x00EE5234
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24105()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$24106
// EA  : 0x82EE5260
// RVA : 0x00EE5260
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24106()
{
  int v0; // r12

  ssList<ssString>::~ssList<ssString>(this: (ssList<ssString> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// __unwind$24107
// EA  : 0x82EE528C
// RVA : 0x00EE528C
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24107()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// __unwind$24108
// EA  : 0x82EE52B8
// RVA : 0x00EE52B8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24108()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// ?_name@util_entityFlagVolume@@UBAPBDXZ
// EA  : 0x82EE52E8
// RVA : 0x00EE52E8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

const char *__fastcall util_entityFlagVolume::_name(util_entityFlagVolume *this)
{
  return "util_entityFlagVolume";
}


// ========================================================================
// ?_isTypeOf@util_entityFlagVolume@@UAA_NPBD@Z
// EA  : 0x82EE52F8
// RVA : 0x00EE52F8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlagVolume::_isTypeOf(util_entityFlagVolume *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_entityFlagVolume")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_entityFlagVolume@@UAAPAXXZ
// EA  : 0x82EE5330
// RVA : 0x00EE5330
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

ssDeclInfo_t *__fastcall util_entityFlagVolume::_getDeclPtr(util_entityFlagVolume *this)
{
  return `util_entityFlagVolume::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_entityFlagVolume@@UBA_NPBD@Z
// EA  : 0x82EE5340
// RVA : 0x00EE5340
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlagVolume::_isNotifyFunction(util_entityFlagVolume *this, const char *name)
{
  return ssString::Icmp(text: "OnEnter", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "OnExit", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0util_entityFlag@@QAA@XZ
// EA  : 0x82EE58E0
// RVA : 0x00EE58E0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

util_entityFlag *__fastcall util_entityFlag::util_entityFlag(util_entityFlag *this)
{
  int v2; // r11

  idSuperScriptObject::idSuperScriptObject(this);
  v2 = 0;
  this->__vftable = (util_entityFlag_vtbl *)&util_entityFlag::`vftable';
  this->flags.data = nullptr;
  this->flags.num = 0;
  this->flags.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->flags.threadId = v2;
  return this;
}


// ========================================================================
// __unwind$24372
// EA  : 0x82EE5964
// RVA : 0x00EE5964
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_24372()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@util_entityFlag@@UBAPBDXZ
// EA  : 0x82EE5990
// RVA : 0x00EE5990
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

const char *__fastcall util_entityFlag::_name(util_entityFlag *this)
{
  return "util_entityFlag";
}


// ========================================================================
// ?_isTypeOf@util_entityFlag@@UAA_NPBD@Z
// EA  : 0x82EE59A0
// RVA : 0x00EE59A0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlag::_isTypeOf(util_entityFlag *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_entityFlag")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_entityFlag@@UAAPAXXZ
// EA  : 0x82EE59D8
// RVA : 0x00EE59D8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

ssDeclInfo_t *__fastcall util_entityFlag::_getDeclPtr(util_entityFlag *this)
{
  return `util_entityFlag::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@util_entityFlag@@UBA_NPBD@Z
// EA  : 0x82EE59E8
// RVA : 0x00EE59E8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall util_entityFlag::_isNotifyFunction(util_entityFlag *this, const char *name)
{
  return ssString::Icmp(text: "OnActivate", text2: name) == 0
      || ssString::Icmp(text: "OnTrigger", text2: name) == 0
      || ssString::Icmp(text: "OnAnimNotify", text2: name) == 0
      || ssString::Icmp(text: "OnAnimEnd", text2: name) == 0
      || ssString::Icmp(text: "OnAnimStart", text2: name) == 0
      || ssString::Icmp(text: "OnDamage", text2: name) == 0
      || ssString::Icmp(text: "OnDeath", text2: name) == 0
      || ssString::Icmp(text: "OnLeftGoal", text2: name) == 0
      || ssString::Icmp(text: "OnReachGoal", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "OnGoalReach", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0?$ssObject@Vutil_entityFlag@@@@QAA@VssEntity@@_N@Z
// EA  : 0x82EEB888
// RVA : 0x00EEB888
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

ssObject<util_entityFlag> *__fastcall ssObject<util_entityFlag>::ssObject<util_entityFlag>(
        ssObject<util_entityFlag> *this,
        ssEntity *e,
        bool create)
{
  int spawnId; // r11

  spawnId = e->spawnId;
  this->objectId = 0;
  this->spawnId = spawnId;
  this->objectId = gameInterface->FindObject(this: gameInterface, a2: spawnId, a3: "util_entityFlag", a4: create);
  return this;
}


// ========================================================================
// ?IsDefined@?$ssObject@Vutil_entityFlag@@@@QAA_NABVssString@@@Z
// EA  : 0x82EEB8F0
// RVA : 0x00EEB8F0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

BOOL __fastcall ssObject<util_entityFlag>::IsDefined(ssObject<util_entityFlag> *this, const ssString *name)
{
  idSSObject *v3; // r3
  util_entityFlag *v4; // r3

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v3,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v4 != nullptr )
    return util_entityFlag::IsDefined(this: v4, name);
  AssertionFailed(msg: "Assertion failed: 0");
  return false;
}


// ========================================================================
// ?Define@?$ssObject@Vutil_entityFlag@@@@QAAXABVssString@@_N1@Z
// EA  : 0x82EEB988
// RVA : 0x00EEB988
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Define(
        ssObject<util_entityFlag> *this,
        const ssString *name,
        bool animNotify,
        bool state)
{
  idSSObject *v7; // r3
  util_entityFlag *v8; // r3

  v7 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v8 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v7,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v8 != nullptr )
    util_entityFlag::Define(this: v8, name, animNotify, state);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?Set@?$ssObject@Vutil_entityFlag@@@@QAAXABVssString@@M@Z
// EA  : 0x82EEBA10
// RVA : 0x00EEBA10
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Set(ssObject<util_entityFlag> *this, const ssString *name, double delay)
{
  idSSObject *v5; // r3
  util_entityFlag *v6; // r3

  v5 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 != nullptr )
    util_entityFlag::Set(this: v6, name, delay);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?Clear@?$ssObject@Vutil_entityFlag@@@@QAAXABVssString@@M@Z
// EA  : 0x82EEBAA8
// RVA : 0x00EEBAA8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Clear(ssObject<util_entityFlag> *this, const ssString *name, double delay)
{
  idSSObject *v5; // r3
  util_entityFlag *v6; // r3

  v5 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 != nullptr )
    util_entityFlag::Clear(this: v6, name, delay);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?SetDeferredThread@util_entityFlag@@SAXPAVidSSObject@@VssString@@M@Z
// EA  : 0x82EEE6E8
// RVA : 0x00EEE6E8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall util_entityFlag::SetDeferredThread(idSSObject *object, ssString *name, double delay)
{
  util_entityFlag *v6; // r30
  ssString v7; // [sp+50h] [-40h] BYREF

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: object,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssString::Init(this: &v7);
  ssString::operator=(this: &v7, text: name);
  util_entityFlag::SetDeferredThread(this: v6, name: &v7, delay);
  ssString::Empty(this: name);
}


// ========================================================================
// __unwind$20708
// EA  : 0x82EEE790
// RVA : 0x00EEE790
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_20708()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 144 + 172));
}


// ========================================================================
// ?ClearDeferredThread@util_entityFlag@@SAXPAVidSSObject@@VssString@@M@Z
// EA  : 0x82EEE7C0
// RVA : 0x00EEE7C0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall util_entityFlag::ClearDeferredThread(idSSObject *object, ssString *name, double delay)
{
  util_entityFlag *v6; // r30
  ssString v7; // [sp+50h] [-40h] BYREF

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: object,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssString::Init(this: &v7);
  ssString::operator=(this: &v7, text: name);
  util_entityFlag::ClearDeferredThread(this: v6, name: &v7, delay);
  ssString::Empty(this: name);
}


// ========================================================================
// __unwind$20735
// EA  : 0x82EEE868
// RVA : 0x00EEE868
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_20735()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 144 + 172));
}


// ========================================================================
// ??0flagDef_t@util_entityFlag@@QAA@XZ
// EA  : 0x82EF0518
// RVA : 0x00EF0518
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

util_entityFlag::flagDef_t *__fastcall util_entityFlag::flagDef_t::flagDef_t(util_entityFlag::flagDef_t *this)
{
  int v2; // r3
  int v3; // r3

  ssString::Init(this: &this->name);
  this->terminateThreads.data = nullptr;
  this->terminateThreads.num = 0;
  this->terminateThreads.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->terminateThreads.threadId = v2;
  this->callFunctions.data = nullptr;
  this->callFunctions.num = 0;
  this->callFunctions.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->callFunctions.threadId = v3;
  this->animNotify = false;
  this->state = false;
  this->count = 0;
  this->lastTime = -1.0;
  return this;
}


// ========================================================================
// __unwind$22674
// EA  : 0x82EF05C8
// RVA : 0x00EF05C8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_22674()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$22675
// EA  : 0x82EF05F0
// RVA : 0x00EF05F0
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void _unwind_22675()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 128 + 148) + 28));
}


// ========================================================================
// ?Set@?$ssObject@Vutil_entityFlag@@@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EF0620
// RVA : 0x00EF0620
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Set(
        ssObject<util_entityFlag> *this,
        const ssList<ssString> *names,
        double delay)
{
  idSSObject *v5; // r3
  util_entityFlag *v6; // r3
  double v7; // fp8
  double v8; // fp7
  double v9; // fp6
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2

  v5 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 != nullptr )
    util_entityFlag::Set(this: v6, names, delay, a4: v13, a5: v12, a6: v11, a7: v10, a8: v9, a9: v8, a10: v7);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?Clear@?$ssObject@Vutil_entityFlag@@@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EF06B8
// RVA : 0x00EF06B8
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Clear(
        ssObject<util_entityFlag> *this,
        const ssList<ssString> *names,
        double delay)
{
  idSSObject *v5; // r3
  util_entityFlag *v6; // r3
  double v7; // fp8
  double v8; // fp7
  double v9; // fp6
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2

  v5 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 != nullptr )
    util_entityFlag::Clear(this: v6, names, delay, a4: v13, a5: v12, a6: v11, a7: v10, a8: v9, a9: v8, a10: v7);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?Toggle@?$ssObject@Vutil_entityFlag@@@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EF0750
// RVA : 0x00EF0750
// PDB : w:\tech5\tungsten\superscript\generated\util\entityflag.h
// ========================================================================

void __fastcall ssObject<util_entityFlag>::Toggle(
        ssObject<util_entityFlag> *this,
        const ssList<ssString> *names,
        double delay)
{
  idSSObject *v5; // r3
  util_entityFlag *v6; // r3

  v5 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v6 = (util_entityFlag *)_RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &idSSObject `RTTI Type Descriptor',
                            TargetType: &util_entityFlag `RTTI Type Descriptor',
                            isReference: 0);
  if ( v6 != nullptr )
    util_entityFlag::Toggle(this: v6, names, delay);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}

