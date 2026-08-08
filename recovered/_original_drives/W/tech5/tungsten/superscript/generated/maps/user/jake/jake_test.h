
// ========================================================================
// ?_name@jake_test1@@UBAPBDXZ
// EA  : 0x82EE2320
// RVA : 0x00EE2320
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

const char *__fastcall jake_test1::_name(jake_test1 *this)
{
  return "jake_test1";
}


// ========================================================================
// ?_isTypeOf@jake_test1@@UAA_NPBD@Z
// EA  : 0x82EE2330
// RVA : 0x00EE2330
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

BOOL __fastcall jake_test1::_isTypeOf(jake_test1 *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "jake_test1")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@jake_test1@@UAAPAXXZ
// EA  : 0x82EE2368
// RVA : 0x00EE2368
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

ssDeclInfo_t *__fastcall jake_test1::_getDeclPtr(jake_test1 *this)
{
  return `jake_test1::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?startMoverTest@jake_test1@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EE2378
// RVA : 0x00EE2378
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

void __fastcall jake_test1::startMoverTest(idSSObject *object, void *__formal)
{
  jake_test1 *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (jake_test1 *)_RTDynamicCast(
                       inptr: object,
                       VfDelta: 0,
                       SrcType: &idSSObject `RTTI Type Descriptor',
                       TargetType: &jake_test1 `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  jake_test1::startMoverTest(this: v3);
}


// ========================================================================
// ?toGoal1@jake_test1@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EE23F8
// RVA : 0x00EE23F8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

void __fastcall jake_test1::toGoal1(idSSObject *object, void *__formal)
{
  jake_test1 *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (jake_test1 *)_RTDynamicCast(
                       inptr: object,
                       VfDelta: 0,
                       SrcType: &idSSObject `RTTI Type Descriptor',
                       TargetType: &jake_test1 `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  jake_test1::toGoal1(this: v3);
}


// ========================================================================
// ?toGoal2@jake_test1@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EE2478
// RVA : 0x00EE2478
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

void __fastcall jake_test1::toGoal2(idSSObject *object, void *__formal)
{
  jake_test1 *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (jake_test1 *)_RTDynamicCast(
                       inptr: object,
                       VfDelta: 0,
                       SrcType: &idSSObject `RTTI Type Descriptor',
                       TargetType: &jake_test1 `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  jake_test1::toGoal2(this: v3);
}


// ========================================================================
// ?_getThreadFunction@jake_test1@@UAAP6AXPAVidSSObject@@PAX@ZPBD@Z
// EA  : 0x82EE24F8
// RVA : 0x00EE24F8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\jake\jake_test.h
// ========================================================================

void (__fastcall *__fastcall jake_test1::_getThreadFunction(jake_test1 *this, const char *name))(idSSObject *, void *)
{
  if ( ssString::Icmp(text: "startMoverTest", text2: name) == 0 )
    return jake_test1::startMoverTest;
  if ( ssString::Icmp(text: "toGoal1", text2: name) != 0 )
    return ssString::Icmp(text: "toGoal2", text2: name) != 0 ? nullptr : jake_test1::toGoal2;
  return jake_test1::toGoal1;
}

