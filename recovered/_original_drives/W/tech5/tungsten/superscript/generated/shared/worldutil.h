
// ========================================================================
// ??0ssWorldUtil@@QAA@XZ
// EA  : 0x82EE2810
// RVA : 0x00EE2810
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssWorldUtil *__fastcall ssWorldUtil::ssWorldUtil(ssWorldUtil *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (ssWorldUtil_vtbl *)&ssWorldUtil::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->world);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player1);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player2);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player3);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player4);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player5);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player6);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player7);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->player8);
  return this;
}


// ========================================================================
// __unwind$22119
// EA  : 0x82EE28A4
// RVA : 0x00EE28A4
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

void _unwind_22119()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@ssWorldUtil@@UBAPBDXZ
// EA  : 0x82EE28D0
// RVA : 0x00EE28D0
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

const char *__fastcall ssWorldUtil::_name(ssWorldUtil *this)
{
  return "ssWorldUtil";
}


// ========================================================================
// ?_isTypeOf@ssWorldUtil@@UAA_NPBD@Z
// EA  : 0x82EE28E0
// RVA : 0x00EE28E0
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

BOOL __fastcall ssWorldUtil::_isTypeOf(ssWorldUtil *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "ssWorldUtil")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@ssWorldUtil@@UAAPAXXZ
// EA  : 0x82EE2918
// RVA : 0x00EE2918
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssDeclInfo_t *__fastcall ssWorldUtil::_getDeclPtr(ssWorldUtil *this)
{
  return `ssWorldUtil::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0ssComment@@QAA@XZ
// EA  : 0x82EE2930
// RVA : 0x00EE2930
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssComment *__fastcall ssComment::ssComment(ssComment *this)
{
  ssColor v3; // [sp+60h] [-40h] BYREF

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (ssComment_vtbl *)&ssComment::`vftable';
  ssString::Init(this: &this->comment);
  this->commentOffset.x = 0.0;
  this->commentOffset.y = 0.0;
  this->commentOffset.z = 0.0;
  this->commentColor.a = 1.0;
  this->commentColor.r = 0.0;
  this->commentColor.g = 0.0;
  this->commentColor.b = 0.0;
  this->commentBoxSize.x = 0.0;
  this->commentBoxSize.y = 0.0;
  this->commentBoxSize.z = 0.0;
  this->alwaysShow = true;
  this->showCommentDragPoint = true;
  this->commentOffset.x = 20.0;
  this->commentOffset.y = 0.0;
  this->commentOffset.z = 40.0;
  this->commentColor = *ssColor::ssColor(this: &v3, r_: 1, g_: 1, b_: 0, a_: 1);
  this->showCommentBox = false;
  this->commentBoxSize.x = 256.0;
  this->commentBoxSize.y = -192.0;
  this->commentBoxSize.z = -64.0;
  return this;
}


// ========================================================================
// __unwind$22185
// EA  : 0x82EE2A50
// RVA : 0x00EE2A50
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

void _unwind_22185()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$22186
// EA  : 0x82EE2A78
// RVA : 0x00EE2A78
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

void _unwind_22186()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(*(_DWORD *)(v0 - 160 + 180) + 8));
}


// ========================================================================
// ?_name@ssComment@@UBAPBDXZ
// EA  : 0x82EE2AA8
// RVA : 0x00EE2AA8
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

const char *__fastcall ssComment::_name(ssComment *this)
{
  return "ssComment";
}


// ========================================================================
// ?_isTypeOf@ssComment@@UAA_NPBD@Z
// EA  : 0x82EE2AB8
// RVA : 0x00EE2AB8
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

BOOL __fastcall ssComment::_isTypeOf(ssComment *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "ssComment")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@ssComment@@UAAPAXXZ
// EA  : 0x82EE2AF0
// RVA : 0x00EE2AF0
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssDeclInfo_t *__fastcall ssComment::_getDeclPtr(ssComment *this)
{
  return `ssComment::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?GetWorld@?$ssObject@VssWorldUtil@@@@QAA?AVssEntity@@XZ
// EA  : 0x82EEAE70
// RVA : 0x00EEAE70
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssObject<ssWorldUtil> *__fastcall ssObject<ssWorldUtil>::GetWorld(ssObject<ssWorldUtil> *this, ssEntity *result)
{
  idSSObject *v3; // r3
  const ssEntity *v4; // r3

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: result->spawnId, a3: result[1].spawnId);
  v4 = (const ssEntity *)_RTDynamicCast(
                           inptr: v3,
                           VfDelta: 0,
                           SrcType: &idSSObject `RTTI Type Descriptor',
                           TargetType: &ssWorldUtil `RTTI Type Descriptor',
                           isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity((ssEntity *)this, e: v4 + 2);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
    idMD6PhaseTrack::idMD6PhaseTrack((idStreamFileLog *)this);
  }
  return this;
}


// ========================================================================
// ?GetPlayer1@?$ssObject@VssWorldUtil@@@@QAA?AVssEntity@@XZ
// EA  : 0x82EEAF08
// RVA : 0x00EEAF08
// PDB : w:\tech5\tungsten\superscript\generated\shared\worldutil.h
// ========================================================================

ssObject<ssWorldUtil> *__fastcall ssObject<ssWorldUtil>::GetPlayer1(ssObject<ssWorldUtil> *this, ssEntity *result)
{
  idSSObject *v3; // r3
  const ssEntity *v4; // r3

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: result->spawnId, a3: result[1].spawnId);
  v4 = (const ssEntity *)_RTDynamicCast(
                           inptr: v3,
                           VfDelta: 0,
                           SrcType: &idSSObject `RTTI Type Descriptor',
                           TargetType: &ssWorldUtil `RTTI Type Descriptor',
                           isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity((ssEntity *)this, e: v4 + 3);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
    idMD6PhaseTrack::idMD6PhaseTrack((idStreamFileLog *)this);
  }
  return this;
}

