
// ========================================================================
// ??0aiObjectTest@@QAA@XZ
// EA  : 0x82EE2210
// RVA : 0x00EE2210
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

aiObjectTest *__fastcall aiObjectTest::aiObjectTest(aiObjectTest *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (aiObjectTest_vtbl *)&aiObjectTest::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->focusEnt);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->goalEnt);
  return this;
}


// ========================================================================
// __unwind$21798
// EA  : 0x82EE226C
// RVA : 0x00EE226C
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

void _unwind_21798()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@aiObjectTest@@UBAPBDXZ
// EA  : 0x82EE2298
// RVA : 0x00EE2298
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

const char *__fastcall aiObjectTest::_name(aiObjectTest *this)
{
  return "aiObjectTest";
}


// ========================================================================
// ?_isTypeOf@aiObjectTest@@UAA_NPBD@Z
// EA  : 0x82EE22A8
// RVA : 0x00EE22A8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

BOOL __fastcall aiObjectTest::_isTypeOf(aiObjectTest *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "aiObjectTest")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@aiObjectTest@@UAAPAXXZ
// EA  : 0x82EE22E0
// RVA : 0x00EE22E0
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

ssDeclInfo_t *__fastcall aiObjectTest::_getDeclPtr(aiObjectTest *this)
{
  return `aiObjectTest::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@aiObjectTest@@UBA_NPBD@Z
// EA  : 0x82EE22F0
// RVA : 0x00EE22F0
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

BOOL __fastcall aiObjectTest::_isNotifyFunction(aiObjectTest *this, const char *name)
{
  return (_cntlzw(ssString::Icmp(text: "OnDamage", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0dy_world@@QAA@XZ
// EA  : 0x82EE3838
// RVA : 0x00EE3838
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

dy_world *__fastcall dy_world::dy_world(dy_world *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->testSoundDecl = nullptr;
  this->__vftable = (dy_world_vtbl *)&dy_world::`vftable';
  this->speakerDecl = nullptr;
  this->infoDecl = nullptr;
  this->hudImage1 = nullptr;
  this->REBUILD = 0;
  return this;
}


// ========================================================================
// ?_name@dy_world@@UBAPBDXZ
// EA  : 0x82EE3890
// RVA : 0x00EE3890
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

const char *__fastcall dy_world::_name(dy_world *this)
{
  return "dy_world";
}


// ========================================================================
// ?_isTypeOf@dy_world@@UAA_NPBD@Z
// EA  : 0x82EE38A0
// RVA : 0x00EE38A0
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

BOOL __fastcall dy_world::_isTypeOf(dy_world *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "dy_world")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@dy_world@@UAAPAXXZ
// EA  : 0x82EE38D8
// RVA : 0x00EE38D8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

ssDeclInfo_t *__fastcall dy_world::_getDeclPtr(dy_world *this)
{
  return `dy_world::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?Update@dy_world@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EE38E8
// RVA : 0x00EE38E8
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

void __fastcall dy_world::Update(idSSObject *object, void *__formal)
{
  dy_world *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (dy_world *)_RTDynamicCast(
                     inptr: object,
                     VfDelta: 0,
                     SrcType: &idSSObject `RTTI Type Descriptor',
                     TargetType: &dy_world `RTTI Type Descriptor',
                     isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  dy_world::Update(this: v3);
}


// ========================================================================
// ?_getThreadFunction@dy_world@@UAAP6AXPAVidSSObject@@PAX@ZPBD@Z
// EA  : 0x82EE3968
// RVA : 0x00EE3968
// PDB : w:\tech5\tungsten\superscript\generated\maps\user\dyoung\dy_world.h
// ========================================================================

void (__fastcall *__fastcall dy_world::_getThreadFunction(dy_world *this, const char *name))(idSSObject *, void *)
{
  return ssString::Icmp(text: "Update", text2: name) != 0 ? nullptr : dy_world::Update;
}

