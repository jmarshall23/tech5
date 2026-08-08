
// ========================================================================
// ??0musicManager@@QAA@XZ
// EA  : 0x82EE2F80
// RVA : 0x00EE2F80
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

musicManager *__fastcall musicManager::musicManager(musicManager *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (musicManager_vtbl *)&musicManager::`vftable';
  this->transOffToLow.transitionMusic = nullptr;
  this->transOffToLow.fadeTime = 0.0;
  this->transOffToMedium.transitionMusic = nullptr;
  this->transOffToMedium.fadeTime = 0.0;
  this->transOffToHigh.transitionMusic = nullptr;
  this->transOffToHigh.fadeTime = 0.0;
  this->transLowToMedium.transitionMusic = nullptr;
  this->transLowToMedium.fadeTime = 0.0;
  this->transLowToHigh.transitionMusic = nullptr;
  this->transLowToHigh.fadeTime = 0.0;
  this->transMediumToHigh.transitionMusic = nullptr;
  this->transMediumToHigh.fadeTime = 0.0;
  this->transHighToMedium.transitionMusic = nullptr;
  this->transHighToMedium.fadeTime = 0.0;
  this->transHighToLow.transitionMusic = nullptr;
  this->transHighToLow.fadeTime = 0.0;
  this->transHighToOff.transitionMusic = nullptr;
  this->transHighToOff.fadeTime = 0.0;
  this->transMediumToLow.transitionMusic = nullptr;
  this->transMediumToLow.fadeTime = 0.0;
  this->transMediumToOff.transitionMusic = nullptr;
  this->transMediumToOff.fadeTime = 0.0;
  this->transLowToOff.transitionMusic = nullptr;
  this->transLowToOff.fadeTime = 0.0;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->eLowSpeaker);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->eMediumSpeaker);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->eHighSpeaker);
  this->lowTensionMusic = nullptr;
  this->medTensionMusic = nullptr;
  this->highTensionMusic = nullptr;
  this->currentTensionLevel = MUSIC_TENSION_STATE_OFF;
  this->infoNull = nullptr;
  return this;
}


// ========================================================================
// __unwind$22499
// EA  : 0x82EE30AC
// RVA : 0x00EE30AC
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void _unwind_22499()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 128 + 148));
}


// ========================================================================
// ?_name@musicManager@@UBAPBDXZ
// EA  : 0x82EE30D8
// RVA : 0x00EE30D8
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

const char *__fastcall musicManager::_name(musicManager *this)
{
  return "musicManager";
}


// ========================================================================
// ?_isTypeOf@musicManager@@UAA_NPBD@Z
// EA  : 0x82EE30E8
// RVA : 0x00EE30E8
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

BOOL __fastcall musicManager::_isTypeOf(musicManager *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "musicManager")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@musicManager@@UAAPAXXZ
// EA  : 0x82EE3120
// RVA : 0x00EE3120
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

ssDeclInfo_t *__fastcall musicManager::_getDeclPtr(musicManager *this)
{
  return `musicManager::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0musicModifier@@QAA@XZ
// EA  : 0x82EE3138
// RVA : 0x00EE3138
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

musicModifier *__fastcall musicModifier::musicModifier(musicModifier *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (musicModifier_vtbl *)&musicModifier::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->manager);
  this->newState = MUSIC_TENSION_STATE_OFF;
  this->transitionMusic = nullptr;
  this->fadeTime = -1.0;
  return this;
}


// ========================================================================
// __unwind$22611
// EA  : 0x82EE31A4
// RVA : 0x00EE31A4
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void _unwind_22611()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@musicModifier@@UBAPBDXZ
// EA  : 0x82EE31D0
// RVA : 0x00EE31D0
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

const char *__fastcall musicModifier::_name(musicModifier *this)
{
  return "musicModifier";
}


// ========================================================================
// ?_isTypeOf@musicModifier@@UAA_NPBD@Z
// EA  : 0x82EE31E0
// RVA : 0x00EE31E0
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

BOOL __fastcall musicModifier::_isTypeOf(musicModifier *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "musicModifier")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@musicModifier@@UAAPAXXZ
// EA  : 0x82EE3218
// RVA : 0x00EE3218
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

ssDeclInfo_t *__fastcall musicModifier::_getDeclPtr(musicModifier *this)
{
  return `musicModifier::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0musicManagerSwitch@@QAA@XZ
// EA  : 0x82EE32C8
// RVA : 0x00EE32C8
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

musicManagerSwitch *__fastcall musicManagerSwitch::musicManagerSwitch(musicManagerSwitch *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (musicManagerSwitch_vtbl *)&musicManagerSwitch::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->old_manager);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->new_manager);
  this->newState = MUSIC_TENSION_STATE_OFF;
  this->transitionMusic = nullptr;
  this->fadeTime = 3.0;
  return this;
}


// ========================================================================
// __unwind$22681
// EA  : 0x82EE333C
// RVA : 0x00EE333C
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void _unwind_22681()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@musicManagerSwitch@@UBAPBDXZ
// EA  : 0x82EE3368
// RVA : 0x00EE3368
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

const char *__fastcall musicManagerSwitch::_name(musicManagerSwitch *this)
{
  return "musicManagerSwitch";
}


// ========================================================================
// ?_isTypeOf@musicManagerSwitch@@UAA_NPBD@Z
// EA  : 0x82EE3378
// RVA : 0x00EE3378
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

BOOL __fastcall musicManagerSwitch::_isTypeOf(musicManagerSwitch *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "musicManagerSwitch")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@musicManagerSwitch@@UAAPAXXZ
// EA  : 0x82EE33B0
// RVA : 0x00EE33B0
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

ssDeclInfo_t *__fastcall musicManagerSwitch::_getDeclPtr(musicManagerSwitch *this)
{
  return `musicManagerSwitch::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?DelayRemoval@musicManager@@SAXPAVidSSObject@@VssEntity@@M@Z
// EA  : 0x82EF19B0
// RVA : 0x00EF19B0
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void __fastcall musicManager::DelayRemoval(idSSObject *object, ssEntity *ent, double time)
{
  ssEntity *v6; // r3
  ssEntity *v7; // r31
  ssEntity v8; // [sp+50h] [-30h] BYREF

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  if ( _RTDynamicCast(
         inptr: object,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &musicManager `RTTI Type Descriptor',
         isReference: 0) == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssEntity::ssEntity(this: &v8, e: ent);
  v7 = v6;
  gameInterface->Wait(this: gameInterface, a2: time);
  ssEntity::Remove(this: v7);
}


// ========================================================================
// ?DebugUpdate@musicManager@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EF1A70
// RVA : 0x00EF1A70
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void __fastcall musicManager::DebugUpdate(idSSObject *object, void *__formal)
{
  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  if ( _RTDynamicCast(
         inptr: object,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &musicManager `RTTI Type Descriptor',
         isReference: 0) == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
}


// ========================================================================
// ?FadeInLogScale@musicManager@@SAXPAVidSSObject@@VssEntity@@M_N@Z
// EA  : 0x82EF1AE0
// RVA : 0x00EF1AE0
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void __fastcall musicManager::FadeInLogScale(
        idSSObject *object,
        ssEntity *speaker,
        double duration,
        bool constantVoltage,
        unsigned __int8 a5)
{
  musicManager *v9; // r31
  long double v10; // fp2
  bool v11; // r5
  ssEntity *v12; // r3
  long double v13; // fp4
  ssEntity v14; // [sp+50h] [-30h] BYREF

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v9 = (musicManager *)_RTDynamicCast(
                         inptr: object,
                         VfDelta: 0,
                         SrcType: &idSSObject `RTTI Type Descriptor',
                         TargetType: &musicManager `RTTI Type Descriptor',
                         isReference: 0);
  if ( v9 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssEntity::ssEntity(this: &v14, e: speaker);
  *(double *)&v10 = duration;
  musicManager::FadeInLogScale(this: v9, speaker: v12, duration: v10, constantVoltage: v11, a5, a6: v13);
}


// ========================================================================
// ?FadeOutLogScale@musicManager@@SAXPAVidSSObject@@VssEntity@@M_N@Z
// EA  : 0x82EF1B78
// RVA : 0x00EF1B78
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void __fastcall musicManager::FadeOutLogScale(
        idSSObject *object,
        ssEntity *speaker,
        double duration,
        bool constantVoltage,
        unsigned __int8 a5)
{
  musicManager *v9; // r31
  long double v10; // fp2
  bool v11; // r5
  ssEntity *v12; // r3
  long double v13; // fp4
  ssEntity v14; // [sp+50h] [-30h] BYREF

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v9 = (musicManager *)_RTDynamicCast(
                         inptr: object,
                         VfDelta: 0,
                         SrcType: &idSSObject `RTTI Type Descriptor',
                         TargetType: &musicManager `RTTI Type Descriptor',
                         isReference: 0);
  if ( v9 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssEntity::ssEntity(this: &v14, e: speaker);
  *(double *)&v10 = duration;
  musicManager::FadeOutLogScale(this: v9, speaker: v12, duration: v10, constantVoltage: v11, a5, a6: v13);
}


// ========================================================================
// ?ChangeState@musicManager@@SAXPAVidSSObject@@W4musicTensionStates_t@@UtensionTransition_t@@@Z
// EA  : 0x82EF2958
// RVA : 0x00EF2958
// PDB : w:\tech5\tungsten\superscript\generated\util\musicmanager.h
// ========================================================================

void __fastcall musicManager::ChangeState(
        idSSObject *object,
        musicTensionStates_t newLevel,
        tensionTransition_t *overrideTransition)
{
  musicManager *v5; // r31
  __int64 v6; // r6

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v5 = (musicManager *)_RTDynamicCast(
                         inptr: object,
                         VfDelta: 0,
                         SrcType: &idSSObject `RTTI Type Descriptor',
                         TargetType: &musicManager `RTTI Type Descriptor',
                         isReference: 0);
  if ( v5 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  HIDWORD(v6) = overrideTransition;
  musicManager::ChangeState(this: v5, overrideTransition: v6);
}

