
// ========================================================================
// ??0idAAS2Callback_FindFlaggedArea@@QAA@H_N@Z
// EA  : 0x826AAEA8
// RVA : 0x006AAEA8
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_findflaggedarea.cpp
// ========================================================================

idAAS2Callback_FindFlaggedArea *__fastcall idAAS2Callback_FindFlaggedArea::idAAS2Callback_FindFlaggedArea(
        idAAS2Callback_FindFlaggedArea *this,
        int areaFlag,
        bool set)
{
  idAAS2Callback_AvoidLocation::idAAS2Callback_AvoidLocation(this);
  this->areaFlag = areaFlag;
  this->__vftable = (idAAS2Callback_FindFlaggedArea_vtbl *)&idAAS2Callback_FindFlaggedArea::`vftable';
  this->test = set;
  return this;
}


// ========================================================================
// ??1idAAS2Callback_FindFlaggedArea@@UAA@XZ
// EA  : 0x826AAEF0
// RVA : 0x006AAEF0
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_findflaggedarea.cpp
// ========================================================================

void __fastcall idAAS2Callback_FindFlaggedArea::~idAAS2Callback_FindFlaggedArea(idAAS2Callback_FindFlaggedArea *this)
{
  this->__vftable = (idAAS2Callback_FindFlaggedArea_vtbl *)&idAAS2Callback_FindFlaggedArea::`vftable';
  idAAS2Callback_AvoidLocation::~idAAS2Callback_AvoidLocation(this);
}


// ========================================================================
// ?AreaIsGoal@idAAS2Callback_FindFlaggedArea@@UAA_NPBVidAAS2@@HABVidVec3@@@Z
// EA  : 0x826AAF00
// RVA : 0x006AAF00
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_findflaggedarea.cpp
// ========================================================================

BOOL __fastcall idAAS2Callback_FindFlaggedArea::AreaIsGoal(
        idAAS2Callback_FindFlaggedArea *this,
        idAAS2 *aas,
        int areaNum,
        const idVec3 *potentialGoal)
{
  return (_cntlzw(this->test - (aas->GetAreaFlags(this: aas, a2: areaNum) & this->areaFlag)) & 0x20) != 0;
}

