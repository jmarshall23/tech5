
// ========================================================================
// ??0phook_test1@@QAA@XZ
// EA  : 0x82EE25A8
// RVA : 0x00EE25A8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

phook_test1 *__fastcall phook_test1::phook_test1(phook_test1 *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->fullyAccessible = 0;
  this->__vftable = (phook_test1_vtbl *)&phook_test1::`vftable';
  this->totallyHidden = 0;
  this->seenInEditor = 0;
  this->hasAccessors = 0;
  return this;
}


// ========================================================================
// ?_name@phook_test1@@UBAPBDXZ
// EA  : 0x82EE25F8
// RVA : 0x00EE25F8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

const char *__fastcall phook_test1::_name(phook_test1 *this)
{
  return "phook_test1";
}


// ========================================================================
// ?_isTypeOf@phook_test1@@UAA_NPBD@Z
// EA  : 0x82EE2608
// RVA : 0x00EE2608
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

BOOL __fastcall phook_test1::_isTypeOf(phook_test1 *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "phook_test1")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@phook_test1@@UAAPAXXZ
// EA  : 0x82EE2640
// RVA : 0x00EE2640
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

ssDeclInfo_t *__fastcall phook_test1::_getDeclPtr(phook_test1 *this)
{
  return `phook_test1::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_name@phook_test1_derrived@@UBAPBDXZ
// EA  : 0x82EE2650
// RVA : 0x00EE2650
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

const char *__fastcall phook_test1_derrived::_name(phook_test1_derrived *this)
{
  return "phook_test1_derrived";
}


// ========================================================================
// ?_isTypeOf@phook_test1_derrived@@UAA_NPBD@Z
// EA  : 0x82EE2660
// RVA : 0x00EE2660
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

BOOL __fastcall phook_test1_derrived::_isTypeOf(phook_test1_derrived *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "phook_test1_derrived")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@phook_test1_derrived@@UAAPAXXZ
// EA  : 0x82EE2698
// RVA : 0x00EE2698
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

ssDeclInfo_t *__fastcall phook_test1_derrived::_getDeclPtr(phook_test1_derrived *this)
{
  return `phook_test1_derrived::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?SetHasAccessors@?$ssObject@Vphook_test1@@@@QAAXH@Z
// EA  : 0x82EE9468
// RVA : 0x00EE9468
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

void __fastcall ssObject<phook_test1>::SetHasAccessors(ssObject<phook_test1> *this, int hasAccessors)
{
  idSSObject *v3; // r3
  _DWORD *v4; // r3

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = _RTDynamicCast(
         inptr: v3,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &phook_test1 `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    v4[5] = hasAccessors;
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?GetHasAccessors@?$ssObject@Vphook_test1@@@@QAAHXZ
// EA  : 0x82EE94F8
// RVA : 0x00EE94F8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

int __fastcall ssObject<phook_test1>::GetHasAccessors(ssObject<phook_test1> *this)
{
  idSSObject *v1; // r3
  _DWORD *v2; // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = _RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &phook_test1 `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    return v2[5];
  AssertionFailed(msg: "Assertion failed: 0");
  return 0;
}


// ========================================================================
// ?Destroy@?$ssObject@Vphook_test1@@@@UAAXXZ
// EA  : 0x82EE9580
// RVA : 0x00EE9580
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\phook\phook_test.h
// ========================================================================

void __fastcall ssObject<phook_test1>::Destroy(ssObject<phook_test1> *this)
{
  idSSObject *v1; // r3
  void *v2; // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = _RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &phook_test1 `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__fastcall **)(void *))(*(_DWORD *)v2 + 4))(a1: v2);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}

