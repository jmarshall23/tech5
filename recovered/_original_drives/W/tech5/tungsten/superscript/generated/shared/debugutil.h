
// ========================================================================
// ??0ssDebugUtil@@QAA@XZ
// EA  : 0x82EE26A8
// RVA : 0x00EE26A8
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

ssDebugUtil *__fastcall ssDebugUtil::ssDebugUtil(ssDebugUtil *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->debugActionsThreadId = 0;
  this->__vftable = (ssDebugUtil_vtbl *)&ssDebugUtil::`vftable';
  this->suicide = nullptr;
  return this;
}


// ========================================================================
// ?_name@ssDebugUtil@@UBAPBDXZ
// EA  : 0x82EE26F0
// RVA : 0x00EE26F0
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

const char *__fastcall ssDebugUtil::_name(ssDebugUtil *this)
{
  return "ssDebugUtil";
}


// ========================================================================
// ?_isTypeOf@ssDebugUtil@@UAA_NPBD@Z
// EA  : 0x82EE2700
// RVA : 0x00EE2700
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

BOOL __fastcall ssDebugUtil::_isTypeOf(ssDebugUtil *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "ssDebugUtil")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@ssDebugUtil@@UAAPAXXZ
// EA  : 0x82EE2738
// RVA : 0x00EE2738
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

ssDeclInfo_t *__fastcall ssDebugUtil::_getDeclPtr(ssDebugUtil *this)
{
  return `ssDebugUtil::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?ReadDebugActions@ssDebugUtil@@SAXPAVidSSObject@@PAX@Z
// EA  : 0x82EE2748
// RVA : 0x00EE2748
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void __fastcall ssDebugUtil::ReadDebugActions(idSSObject *object, void *__formal)
{
  ssDebugUtil *v3; // r31

  if ( object == nullptr )
    AssertionFailed(msg: "Assertion failed: object != NULL");
  v3 = (ssDebugUtil *)_RTDynamicCast(
                        inptr: object,
                        VfDelta: 0,
                        SrcType: &idSSObject `RTTI Type Descriptor',
                        TargetType: &ssDebugUtil `RTTI Type Descriptor',
                        isReference: 0);
  if ( v3 == nullptr )
    AssertionFailed(msg: "Assertion failed: o != NULL");
  ssDebugUtil::ReadDebugActions(this: v3);
}


// ========================================================================
// ?_getThreadFunction@ssDebugUtil@@UAAP6AXPAVidSSObject@@PAX@ZPBD@Z
// EA  : 0x82EE27C8
// RVA : 0x00EE27C8
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void (__fastcall *__fastcall ssDebugUtil::_getThreadFunction(
        ssDebugUtil *this,
        const char *name))(idSSObject *, void *)
{
  return ssString::Icmp(text: "ReadDebugActions", text2: name) != 0 ? nullptr : ssDebugUtil::ReadDebugActions;
}


// ========================================================================
// ??0util_debugMetaData@@QAA@XZ
// EA  : 0x82EE48F8
// RVA : 0x00EE48F8
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

util_debugMetaData *__fastcall util_debugMetaData::util_debugMetaData(util_debugMetaData *this)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (util_debugMetaData_vtbl *)&util_debugMetaData::`vftable';
  this->circleInfo.showLayingCircleAlways = false;
  this->circleInfo.layingCircleRadius = 0.0;
  this->circleInfo.standingCircleRadius = 0.0;
  this->cylinderInfo.radius = 0.0;
  this->cylinderInfo.height = 0.0;
  this->fovInfo.fovDegrees = 0.0;
  this->fovInfo.innerRadius = 0.0;
  this->fovInfo.outerRadius = 0.0;
  this->lines.data = nullptr;
  this->lines.num = 0;
  this->lines.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->lines.threadId = v2;
  this->planes.data = nullptr;
  this->planes.num = 0;
  this->planes.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->planes.threadId = v3;
  this->sectorInfo.arclengthInfo.arclength = 0.0;
  this->sectorInfo.radius = 0.0;
  this->strings.data = nullptr;
  this->strings.num = 0;
  this->strings.size = 0;
  if ( gameInterface != nullptr )
    v4 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v4 = 0;
  this->strings.threadId = v4;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->targetEntity);
  this->actions.size = 0;
  this->actions.num = 0;
  this->actions.data = nullptr;
  if ( gameInterface != nullptr )
    v5 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v5 = 0;
  this->actions.threadId = v5;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->lightEntity);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->nonLightEntity);
  this->sphereRadius = 0.0;
  this->entityDef = nullptr;
  this->alwaysShowOrienation = false;
  this->drawingTestEnum1 = VALUE_1;
  this->drawingTestEnum2 = FLAG_1AND3;
  return this;
}


// ========================================================================
// __unwind$23796
// EA  : 0x82EE4A90
// RVA : 0x00EE4A90
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void _unwind_23796()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$23797
// EA  : 0x82EE4AB8
// RVA : 0x00EE4AB8
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void _unwind_23797()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 144 + 164) + 44));
}


// ========================================================================
// __unwind$23798
// EA  : 0x82EE4AE4
// RVA : 0x00EE4AE4
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void _unwind_23798()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// __unwind$23799
// EA  : 0x82EE4B10
// RVA : 0x00EE4B10
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void _unwind_23799()
{
  int v0; // r12

  ssList<ssString>::~ssList<ssString>(this: (ssList<ssString> *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}


// ========================================================================
// __unwind$23800
// EA  : 0x82EE4B3C
// RVA : 0x00EE4B3C
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

void _unwind_23800()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 144 + 164) + 120));
}


// ========================================================================
// ?_name@util_debugMetaData@@UBAPBDXZ
// EA  : 0x82EE4B68
// RVA : 0x00EE4B68
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

const char *__fastcall util_debugMetaData::_name(util_debugMetaData *this)
{
  return "util_debugMetaData";
}


// ========================================================================
// ?_isTypeOf@util_debugMetaData@@UAA_NPBD@Z
// EA  : 0x82EE4B78
// RVA : 0x00EE4B78
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

BOOL __fastcall util_debugMetaData::_isTypeOf(util_debugMetaData *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "util_debugMetaData")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@util_debugMetaData@@UAAPAXXZ
// EA  : 0x82EE4BB0
// RVA : 0x00EE4BB0
// PDB : w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// ========================================================================

ssDeclInfo_t *__fastcall util_debugMetaData::_getDeclPtr(util_debugMetaData *this)
{
  return `util_debugMetaData::_getDeclPtr'::`2'::varInfo;
}

