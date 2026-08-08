
// ========================================================================
// ?Get_idUse_disableAfterUse@@YAHPAX@Z
// EA  : 0x8255D328
// RVA : 0x0055D328
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idUse_disableAfterUse(unsigned __int8 *ptr)
{
  return ptr[844] >> 7;
}


// ========================================================================
// ?Set_idUse_disableAfterUse@@YAXPAXH@Z
// EA  : 0x8255D338
// RVA : 0x0055D338
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idUse_disableAfterUse(_BYTE *ptr, int value)
{
  ptr[844] = ((value != 0) << 7) | ptr[844] & 0x7F;
}


// ========================================================================
// ?Get_idUse_ignoreLineTrace@@YAHPAX@Z
// EA  : 0x8255D350
// RVA : 0x0055D350
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idUse_ignoreLineTrace(_BYTE *ptr)
{
  return (ptr[844] & 0x40) != 0;
}


// ========================================================================
// ?Set_idUse_ignoreLineTrace@@YAXPAXH@Z
// EA  : 0x8255D360
// RVA : 0x0055D360
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idUse_ignoreLineTrace(_BYTE *ptr, int value)
{
  ptr[844] = ((value != 0) << 6) & 0x40 | ptr[844] & 0xBF;
}


// ========================================================================
// ?Get_idUse_noBlink@@YAHPAX@Z
// EA  : 0x8255D378
// RVA : 0x0055D378
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idUse_noBlink(_BYTE *ptr)
{
  return (ptr[844] & 0x20) != 0;
}


// ========================================================================
// ?Set_idUse_noBlink@@YAXPAXH@Z
// EA  : 0x8255D388
// RVA : 0x0055D388
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idUse_noBlink(_BYTE *ptr, int value)
{
  ptr[844] = (32 * (value != 0)) & 0x20 | ptr[844] & 0xDF;
}


// ========================================================================
// ?Get_idUse_hideCrossHairInfo@@YAHPAX@Z
// EA  : 0x8255D3A0
// RVA : 0x0055D3A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idUse_hideCrossHairInfo(_BYTE *ptr)
{
  return (ptr[844] & 0x10) != 0;
}


// ========================================================================
// ?Set_idUse_hideCrossHairInfo@@YAXPAXH@Z
// EA  : 0x8255D3B0
// RVA : 0x0055D3B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idUse_hideCrossHairInfo(_BYTE *ptr, int value)
{
  ptr[844] = (16 * (value != 0)) & 0x10 | ptr[844] & 0xEF;
}


// ========================================================================
// ?Get_idProp_BreakableLoot_uniqueInWorld@@YAHPAX@Z
// EA  : 0x8255D3C8
// RVA : 0x0055D3C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idProp_BreakableLoot_uniqueInWorld(unsigned __int8 *ptr)
{
  return ptr[5436] >> 7;
}


// ========================================================================
// ?Set_idProp_BreakableLoot_uniqueInWorld@@YAXPAXH@Z
// EA  : 0x8255D3D8
// RVA : 0x0055D3D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idProp_BreakableLoot_uniqueInWorld(_BYTE *ptr, int value)
{
  ptr[5436] = ((value != 0) << 7) | ptr[5436] & 0x7F;
}


// ========================================================================
// ?Get_idProp_BreakableLoot_hasCheckedUniqueInWorld@@YAHPAX@Z
// EA  : 0x8255D3F0
// RVA : 0x0055D3F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idProp_BreakableLoot_hasCheckedUniqueInWorld(_BYTE *ptr)
{
  return (ptr[5436] & 0x40) != 0;
}


// ========================================================================
// ?Set_idProp_BreakableLoot_hasCheckedUniqueInWorld@@YAXPAXH@Z
// EA  : 0x8255D400
// RVA : 0x0055D400
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idProp_BreakableLoot_hasCheckedUniqueInWorld(_BYTE *ptr, int value)
{
  ptr[5436] = ((value != 0) << 6) & 0x40 | ptr[5436] & 0xBF;
}


// ========================================================================
// ?Get_idAIEntityState_valid@@YAHPAX@Z
// EA  : 0x8255D418
// RVA : 0x0055D418
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAIEntityState_valid(unsigned __int8 *ptr)
{
  return ptr[541] >> 7;
}


// ========================================================================
// ?Set_idAIEntityState_valid@@YAXPAXH@Z
// EA  : 0x8255D428
// RVA : 0x0055D428
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIEntityState_valid(_BYTE *ptr, int value)
{
  ptr[541] = ((value != 0) << 7) | ptr[541] & 0x7F;
}


// ========================================================================
// ?Get_idAIEntityState_newlyAware@@YAHPAX@Z
// EA  : 0x8255D440
// RVA : 0x0055D440
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAIEntityState_newlyAware(_BYTE *ptr)
{
  return (ptr[541] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAIEntityState_newlyAware@@YAXPAXH@Z
// EA  : 0x8255D450
// RVA : 0x0055D450
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIEntityState_newlyAware(_BYTE *ptr, int value)
{
  ptr[541] = ((value != 0) << 6) & 0x40 | ptr[541] & 0xBF;
}


// ========================================================================
// ?Get_idAIMoveState_alignToTraversalOrientation@@YAHPAX@Z
// EA  : 0x8255D468
// RVA : 0x0055D468
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAIMoveState_alignToTraversalOrientation(unsigned __int8 *ptr)
{
  return ptr[352] >> 7;
}


// ========================================================================
// ?Set_idAIMoveState_alignToTraversalOrientation@@YAXPAXH@Z
// EA  : 0x8255D478
// RVA : 0x0055D478
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIMoveState_alignToTraversalOrientation(_BYTE *ptr, int value)
{
  ptr[352] = ((value != 0) << 7) | ptr[352] & 0x7F;
}


// ========================================================================
// ?Get_idAIMoveState_inControl@@YAHPAX@Z
// EA  : 0x8255D490
// RVA : 0x0055D490
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAIMoveState_inControl(_BYTE *ptr)
{
  return (ptr[352] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAIMoveState_inControl@@YAXPAXH@Z
// EA  : 0x8255D4A0
// RVA : 0x0055D4A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIMoveState_inControl(_BYTE *ptr, int value)
{
  ptr[352] = ((value != 0) << 6) & 0x40 | ptr[352] & 0xBF;
}


// ========================================================================
// ?Get_idAIMoveState_aligningToGoal@@YAHPAX@Z
// EA  : 0x8255D4B8
// RVA : 0x0055D4B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAIMoveState_aligningToGoal(_BYTE *ptr)
{
  return (ptr[352] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAIMoveState_aligningToGoal@@YAXPAXH@Z
// EA  : 0x8255D4C8
// RVA : 0x0055D4C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIMoveState_aligningToGoal(_BYTE *ptr, int value)
{
  ptr[352] = (32 * (value != 0)) & 0x20 | ptr[352] & 0xDF;
}


// ========================================================================
// ?Set_idAIMoveState_isPlayingTraversalAnim@@YAXPAXH@Z
// EA  : 0x8255D4E0
// RVA : 0x0055D4E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIMoveState_isPlayingTraversalAnim(_BYTE *ptr, int value)
{
  ptr[352] = (16 * (value != 0)) & 0x10 | ptr[352] & 0xEF;
}


// ========================================================================
// ?Get_idAIMoveState_startedMovementAnim@@YAHPAX@Z
// EA  : 0x8255D4F8
// RVA : 0x0055D4F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAIMoveState_startedMovementAnim(_BYTE *ptr)
{
  return (ptr[352] & 8) != 0;
}


// ========================================================================
// ?Set_idAIMoveState_startedMovementAnim@@YAXPAXH@Z
// EA  : 0x8255D508
// RVA : 0x0055D508
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIMoveState_startedMovementAnim(_BYTE *ptr, int value)
{
  ptr[352] = (8 * (value != 0)) & 8 | ptr[352] & 0xF7;
}


// ========================================================================
// ?Get_idAnimWebCmdWaitHandle_eventFired@@YAHPAX@Z
// EA  : 0x8255D520
// RVA : 0x0055D520
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAnimWebCmdWaitHandle_eventFired(unsigned __int8 *ptr)
{
  return ptr[149] >> 7;
}


// ========================================================================
// ?Set_idAnimWebCmdWaitHandle_eventFired@@YAXPAXH@Z
// EA  : 0x8255D530
// RVA : 0x0055D530
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAnimWebCmdWaitHandle_eventFired(_BYTE *ptr, int value)
{
  ptr[149] = ((value != 0) << 7) | ptr[149] & 0x7F;
}


// ========================================================================
// ?Get_idAnimWebCmdWaitHandle_allowInterruptPathImmediate@@YAHPAX@Z
// EA  : 0x8255D548
// RVA : 0x0055D548
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAnimWebCmdWaitHandle_allowInterruptPathImmediate(_BYTE *ptr)
{
  return (ptr[149] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAnimWebCmdWaitHandle_allowInterruptPathImmediate@@YAXPAXH@Z
// EA  : 0x8255D558
// RVA : 0x0055D558
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAnimWebCmdWaitHandle_allowInterruptPathImmediate(_BYTE *ptr, int value)
{
  ptr[149] = ((value != 0) << 6) & 0x40 | ptr[149] & 0xBF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canUseStairs@@YAXPAXH@Z
// EA  : 0x8255D570
// RVA : 0x0055D570
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canUseStairs(_BYTE *ptr, int value)
{
  ptr[84] = ((value != 0) << 7) | ptr[84] & 0x7F;
}


// ========================================================================
// ?Set_idEntityDefEditorVars_showOrientation@@YAXPAXH@Z
// EA  : 0x8255D588
// RVA : 0x0055D588
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idEntityDefEditorVars_showOrientation(_BYTE *ptr, int value)
{
  ptr[84] = ((value != 0) << 6) & 0x40 | ptr[84] & 0xBF;
}


// ========================================================================
// ?Set_idAIEditable_idAIDeath_canBecomeInjured@@YAXPAXH@Z
// EA  : 0x8255D5A0
// RVA : 0x0055D5A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIEditable_idAIDeath_canBecomeInjured(_BYTE *ptr, int value)
{
  ptr[84] = (32 * (value != 0)) & 0x20 | ptr[84] & 0xDF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_hasDeathAnims@@YAXPAXH@Z
// EA  : 0x8255D5B8
// RVA : 0x0055D5B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_hasDeathAnims(_BYTE *ptr, int value)
{
  ptr[84] = (16 * (value != 0)) & 0x10 | ptr[84] & 0xEF;
}


// ========================================================================
// ?Set_idEntityDefEditorVars_placeable@@YAXPAXH@Z
// EA  : 0x8255D5D0
// RVA : 0x0055D5D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idEntityDefEditorVars_placeable(_BYTE *ptr, int value)
{
  ptr[84] = (8 * (value != 0)) & 8 | ptr[84] & 0xF7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canUseTeleporters@@YAXPAXH@Z
// EA  : 0x8255D5E8
// RVA : 0x0055D5E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canUseTeleporters(_BYTE *ptr, int value)
{
  ptr[84] = (value != 0) | ptr[84] & 0xFE;
}


// ========================================================================
// ?Set_idAIEditable_idAIDeath_noBodyRemoval@@YAXPAXH@Z
// EA  : 0x8255D600
// RVA : 0x0055D600
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAIEditable_idAIDeath_noBodyRemoval(_BYTE *ptr, int value)
{
  ptr[85] = ((value != 0) << 7) | ptr[85] & 0x7F;
}


// ========================================================================
// ?Set_idCoverCapabilities_blindfireLeft@@YAXPAXH@Z
// EA  : 0x8255D618
// RVA : 0x0055D618
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_blindfireLeft(_BYTE *ptr, int value)
{
  ptr[8] = ((value != 0) << 7) | ptr[8] & 0x7F;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useMoods@@YAXPAXH@Z
// EA  : 0x8255D630
// RVA : 0x0055D630
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useMoods(_BYTE *ptr, int value)
{
  ptr[92] = ((value != 0) << 7) | ptr[92] & 0x7F;
}


// ========================================================================
// ?Get_idCombatStage_useSearchChatterVO@@YAHPAX@Z
// EA  : 0x8255D648
// RVA : 0x0055D648
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idCombatStage_useSearchChatterVO(_BYTE *ptr)
{
  return (ptr[92] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useLipsync@@YAXPAXH@Z
// EA  : 0x8255D658
// RVA : 0x0055D658
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useLipsync(_BYTE *ptr, int value)
{
  ptr[92] = ((value != 0) << 6) & 0x40 | ptr[92] & 0xBF;
}


// ========================================================================
// ?Get_idCombatStage_useTauntChatterVO@@YAHPAX@Z
// EA  : 0x8255D670
// RVA : 0x0055D670
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idCombatStage_useTauntChatterVO(_BYTE *ptr)
{
  return (ptr[92] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useGestures@@YAXPAXH@Z
// EA  : 0x8255D680
// RVA : 0x0055D680
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useGestures(_BYTE *ptr, int value)
{
  ptr[92] = (32 * (value != 0)) & 0x20 | ptr[92] & 0xDF;
}


// ========================================================================
// ?Get_idCombatStage_useRoleChangeVO@@YAHPAX@Z
// EA  : 0x8255D698
// RVA : 0x0055D698
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idCombatStage_useRoleChangeVO(_BYTE *ptr)
{
  return (ptr[92] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useEyeTracking@@YAXPAXH@Z
// EA  : 0x8255D6A8
// RVA : 0x0055D6A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useEyeTracking(_BYTE *ptr, int value)
{
  ptr[92] = (16 * (value != 0)) & 0x10 | ptr[92] & 0xEF;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTracking@@YAXPAXH@Z
// EA  : 0x8255D6C0
// RVA : 0x0055D6C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTracking(_BYTE *ptr, int value)
{
  ptr[92] = (8 * (value != 0)) & 8 | ptr[92] & 0xF7;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useBlinking@@YAHPAX@Z
// EA  : 0x8255D6D8
// RVA : 0x0055D6D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useBlinking(_BYTE *ptr)
{
  return (ptr[92] & 4) != 0;
}


// ========================================================================
// ?Set_idCombatStage_useFormationCover@@YAXPAXH@Z
// EA  : 0x8255D6E8
// RVA : 0x0055D6E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idCombatStage_useFormationCover(_BYTE *ptr, int value)
{
  ptr[92] = (4 * (value != 0)) & 4 | ptr[92] & 0xFB;
}


// ========================================================================
// ?TakesDamage@idEntity@@UBA_NXZ
// EA  : 0x8255D700
// RVA : 0x0055D700
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall idEntity::TakesDamage(idEntity *this)
{
  return (*(_BYTE *)&this->flags & 2) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useLidDeformation@@YAXPAXH@Z
// EA  : 0x8255D710
// RVA : 0x0055D710
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useLidDeformation(_BYTE *ptr, int value)
{
  ptr[92] = (2 * (value != 0)) & 2 | ptr[92] & 0xFD;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useFaceManager@@YAHPAX@Z
// EA  : 0x8255D728
// RVA : 0x0055D728
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIConstant_idAIAnimation_useFaceManager(_BYTE *ptr)
{
  return ptr[92] & 1;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useFaceManager@@YAXPAXH@Z
// EA  : 0x8255D738
// RVA : 0x0055D738
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useFaceManager(_BYTE *ptr, int value)
{
  ptr[92] = (value != 0) | ptr[92] & 0xFE;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useFacialAnims@@YAHPAX@Z
// EA  : 0x8255D750
// RVA : 0x0055D750
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIConstant_idAIAnimation_useFacialAnims(unsigned __int8 *ptr)
{
  return ptr[93] >> 7;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useFacialAnims@@YAXPAXH@Z
// EA  : 0x8255D760
// RVA : 0x0055D760
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useFacialAnims(_BYTE *ptr, int value)
{
  ptr[93] = ((value != 0) << 7) | ptr[93] & 0x7F;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useMoodsEnabled@@YAHPAX@Z
// EA  : 0x8255D778
// RVA : 0x0055D778
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useMoodsEnabled(_BYTE *ptr)
{
  return (ptr[93] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useMoodsEnabled@@YAXPAXH@Z
// EA  : 0x8255D788
// RVA : 0x0055D788
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useMoodsEnabled(_BYTE *ptr, int value)
{
  ptr[93] = ((value != 0) << 6) & 0x40 | ptr[93] & 0xBF;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useLipsyncEnabled@@YAHPAX@Z
// EA  : 0x8255D7A0
// RVA : 0x0055D7A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useLipsyncEnabled(_BYTE *ptr)
{
  return (ptr[93] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useLipsyncEnabled@@YAXPAXH@Z
// EA  : 0x8255D7B0
// RVA : 0x0055D7B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useLipsyncEnabled(_BYTE *ptr, int value)
{
  ptr[93] = (32 * (value != 0)) & 0x20 | ptr[93] & 0xDF;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useGesturesEnabled@@YAHPAX@Z
// EA  : 0x8255D7C8
// RVA : 0x0055D7C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useGesturesEnabled(_BYTE *ptr)
{
  return (ptr[93] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useGesturesEnabled@@YAXPAXH@Z
// EA  : 0x8255D7D8
// RVA : 0x0055D7D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useGesturesEnabled(_BYTE *ptr, int value)
{
  ptr[93] = (16 * (value != 0)) & 0x10 | ptr[93] & 0xEF;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useFacialAnimsEnabled@@YAHPAX@Z
// EA  : 0x8255D7F0
// RVA : 0x0055D7F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useFacialAnimsEnabled(_BYTE *ptr)
{
  return (ptr[93] & 8) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useFacialAnimsEnabled@@YAXPAXH@Z
// EA  : 0x8255D800
// RVA : 0x0055D800
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useFacialAnimsEnabled(_BYTE *ptr, int value)
{
  ptr[93] = (8 * (value != 0)) & 8 | ptr[93] & 0xF7;
}


// ========================================================================
// ?Get_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTrackingEnabled@@YAHPAX@Z
// EA  : 0x8255D818
// RVA : 0x0055D818
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTrackingEnabled(_BYTE *ptr)
{
  return (ptr[93] & 4) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTrackingEnabled@@YAXPAXH@Z
// EA  : 0x8255D828
// RVA : 0x0055D828
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIConstant_idAIAnimation_useFaceSetupEyeTrackingEnabled(_BYTE *ptr, int value)
{
  ptr[93] = (4 * (value != 0)) & 4 | ptr[93] & 0xFB;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_firstThink@@YAHPAX@Z
// EA  : 0x8255D840
// RVA : 0x0055D840
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_firstThink(unsigned __int8 *ptr)
{
  return ptr[49704] >> 7;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_firstThink@@YAXPAXH@Z
// EA  : 0x8255D858
// RVA : 0x0055D858
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_firstThink(_BYTE *ptr, int value)
{
  ptr[49704] = ((value != 0) << 7) | ptr[49704] & 0x7F;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_incapacitatedPlayer@@YAHPAX@Z
// EA  : 0x8255D878
// RVA : 0x0055D878
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_incapacitatedPlayer(_BYTE *ptr)
{
  return (ptr[49704] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_incapacitatedPlayer@@YAXPAXH@Z
// EA  : 0x8255D890
// RVA : 0x0055D890
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_incapacitatedPlayer(_BYTE *ptr, int value)
{
  ptr[49704] = ((value != 0) << 6) & 0x40 | ptr[49704] & 0xBF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_isInteracting@@YAHPAX@Z
// EA  : 0x8255D8B0
// RVA : 0x0055D8B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_isInteracting(_BYTE *ptr)
{
  return (ptr[49704] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_isInteracting@@YAXPAXH@Z
// EA  : 0x8255D8C8
// RVA : 0x0055D8C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_isInteracting(_BYTE *ptr, int value)
{
  ptr[49704] = (32 * (value != 0)) & 0x20 | ptr[49704] & 0xDF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_isIdleTracking@@YAHPAX@Z
// EA  : 0x8255D8E8
// RVA : 0x0055D8E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_isIdleTracking(_BYTE *ptr)
{
  return (ptr[49704] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_isIdleTracking@@YAXPAXH@Z
// EA  : 0x8255D900
// RVA : 0x0055D900
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_isIdleTracking(_BYTE *ptr, int value)
{
  ptr[49704] = (16 * (value != 0)) & 0x10 | ptr[49704] & 0xEF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_activateWhenVisibleOverride@@YAHPAX@Z
// EA  : 0x8255D920
// RVA : 0x0055D920
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_activateWhenVisibleOverride(_BYTE *ptr)
{
  return (ptr[49704] & 8) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_activateWhenVisibleOverride@@YAXPAXH@Z
// EA  : 0x8255D938
// RVA : 0x0055D938
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_activateWhenVisibleOverride(_BYTE *ptr, int value)
{
  ptr[49704] = (8 * (value != 0)) & 8 | ptr[49704] & 0xF7;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_receivedPlayerInteractionEvent@@YAHPAX@Z
// EA  : 0x8255D958
// RVA : 0x0055D958
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_receivedPlayerInteractionEvent(_BYTE *ptr)
{
  return (ptr[49704] & 4) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_receivedPlayerInteractionEvent@@YAXPAXH@Z
// EA  : 0x8255D970
// RVA : 0x0055D970
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_receivedPlayerInteractionEvent(_BYTE *ptr, int value)
{
  ptr[49704] = (4 * (value != 0)) & 4 | ptr[49704] & 0xFB;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_leftPlayerInteractionRadius@@YAHPAX@Z
// EA  : 0x8255D990
// RVA : 0x0055D990
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_leftPlayerInteractionRadius(_BYTE *ptr)
{
  return (ptr[49704] & 2) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_leftPlayerInteractionRadius@@YAXPAXH@Z
// EA  : 0x8255D9A8
// RVA : 0x0055D9A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_leftPlayerInteractionRadius(_BYTE *ptr, int value)
{
  ptr[49704] = (2 * (value != 0)) & 2 | ptr[49704] & 0xFD;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_isInCombatForSubtitles@@YAHPAX@Z
// EA  : 0x8255D9C8
// RVA : 0x0055D9C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_isInCombatForSubtitles(_BYTE *ptr)
{
  return ptr[49704] & 1;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_isInCombatForSubtitles@@YAXPAXH@Z
// EA  : 0x8255D9E0
// RVA : 0x0055D9E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_isInCombatForSubtitles(_BYTE *ptr, int value)
{
  ptr[49704] = (value != 0) | ptr[49704] & 0xFE;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_isObstacleAvoiding_Player@@YAHPAX@Z
// EA  : 0x8255DA00
// RVA : 0x0055DA00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_isObstacleAvoiding_Player(unsigned __int8 *ptr)
{
  return ptr[49705] >> 7;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_isObstacleAvoiding_Player@@YAXPAXH@Z
// EA  : 0x8255DA18
// RVA : 0x0055DA18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_isObstacleAvoiding_Player(_BYTE *ptr, int value)
{
  ptr[49705] = ((value != 0) << 7) | ptr[49705] & 0x7F;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_disableDeathAnims@@YAHPAX@Z
// EA  : 0x8255DA38
// RVA : 0x0055DA38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_idAIDeath_disableDeathAnims(unsigned __int8 *ptr)
{
  return ptr[1760] >> 7;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_disableDeathAnims@@YAXPAXH@Z
// EA  : 0x8255DA48
// RVA : 0x0055DA48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_disableDeathAnims(_BYTE *ptr, int value)
{
  ptr[1760] = ((value != 0) << 7) | ptr[1760] & 0x7F;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_isSmoking@@YAHPAX@Z
// EA  : 0x8255DA60
// RVA : 0x0055DA60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_isSmoking(_BYTE *ptr)
{
  return (ptr[1760] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_isSmoking@@YAXPAXH@Z
// EA  : 0x8255DA70
// RVA : 0x0055DA70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_isSmoking(_BYTE *ptr, int value)
{
  ptr[1760] = ((value != 0) << 6) & 0x40 | ptr[1760] & 0xBF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_oneShotted@@YAHPAX@Z
// EA  : 0x8255DA88
// RVA : 0x0055DA88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_oneShotted(_BYTE *ptr)
{
  return (ptr[1760] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_oneShotted@@YAXPAXH@Z
// EA  : 0x8255DA98
// RVA : 0x0055DA98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_oneShotted(_BYTE *ptr, int value)
{
  ptr[1760] = (32 * (value != 0)) & 0x20 | ptr[1760] & 0xDF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_droppedLootBox@@YAHPAX@Z
// EA  : 0x8255DAB0
// RVA : 0x0055DAB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_droppedLootBox(_BYTE *ptr)
{
  return (ptr[1760] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_droppedLootBox@@YAXPAXH@Z
// EA  : 0x8255DAC0
// RVA : 0x0055DAC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_droppedLootBox(_BYTE *ptr, int value)
{
  ptr[1760] = (16 * (value != 0)) & 0x10 | ptr[1760] & 0xEF;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_retryDeath@@YAHPAX@Z
// EA  : 0x8255DAD8
// RVA : 0x0055DAD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_retryDeath(_BYTE *ptr)
{
  return (ptr[1760] & 8) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_retryDeath@@YAXPAXH@Z
// EA  : 0x8255DAE8
// RVA : 0x0055DAE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_retryDeath(_BYTE *ptr, int value)
{
  ptr[1760] = (8 * (value != 0)) & 8 | ptr[1760] & 0xF7;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_isRagdolling@@YAHPAX@Z
// EA  : 0x8255DB00
// RVA : 0x0055DB00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_isRagdolling(_BYTE *ptr)
{
  return (ptr[1760] & 4) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_isRagdolling@@YAXPAXH@Z
// EA  : 0x8255DB10
// RVA : 0x0055DB10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_isRagdolling(_BYTE *ptr, int value)
{
  ptr[1760] = (4 * (value != 0)) & 4 | ptr[1760] & 0xFB;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_noRagdoll@@YAHPAX@Z
// EA  : 0x8255DB28
// RVA : 0x0055DB28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_noRagdoll(_BYTE *ptr)
{
  return (ptr[1760] & 2) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_noRagdoll@@YAXPAXH@Z
// EA  : 0x8255DB38
// RVA : 0x0055DB38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_noRagdoll(_BYTE *ptr, int value)
{
  ptr[1760] = (2 * (value != 0)) & 2 | ptr[1760] & 0xFD;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_lootBoxEvent@@YAHPAX@Z
// EA  : 0x8255DB50
// RVA : 0x0055DB50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_idAIDeath_lootBoxEvent(_BYTE *ptr)
{
  return ptr[1760] & 1;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_lootBoxEvent@@YAXPAXH@Z
// EA  : 0x8255DB60
// RVA : 0x0055DB60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_lootBoxEvent(_BYTE *ptr, int value)
{
  ptr[1760] = (value != 0) | ptr[1760] & 0xFE;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_removeEventCalled@@YAHPAX@Z
// EA  : 0x8255DB78
// RVA : 0x0055DB78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idAI2_idAIVolatile_idAIDeath_removeEventCalled(unsigned __int8 *ptr)
{
  return ptr[1761] >> 7;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_removeEventCalled@@YAXPAXH@Z
// EA  : 0x8255DB88
// RVA : 0x0055DB88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_removeEventCalled(_BYTE *ptr, int value)
{
  ptr[1761] = ((value != 0) << 7) | ptr[1761] & 0x7F;
}


// ========================================================================
// ?Get_idAI2_idAIVolatile_idAIDeath_forceAllowLooting@@YAHPAX@Z
// EA  : 0x8255DBA0
// RVA : 0x0055DBA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idAI2_idAIVolatile_idAIDeath_forceAllowLooting(_BYTE *ptr)
{
  return (ptr[1761] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAI2_idAIVolatile_idAIDeath_forceAllowLooting@@YAXPAXH@Z
// EA  : 0x8255DBB0
// RVA : 0x0055DBB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idAI2_idAIVolatile_idAIDeath_forceAllowLooting(_BYTE *ptr, int value)
{
  ptr[1761] = ((value != 0) << 6) & 0x40 | ptr[1761] & 0xBF;
}


// ========================================================================
// ?Get_idNavSplinePathMgr_navSplineFloodBits_t_traversed@@YAHPAX@Z
// EA  : 0x8255DBC8
// RVA : 0x0055DBC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idNavSplinePathMgr_navSplineFloodBits_t_traversed(int *ptr)
{
  return *ptr >> 31;
}


// ========================================================================
// ?Set_idNavSplinePathMgr_navSplineFloodBits_t_traversed@@YAXPAXH@Z
// EA  : 0x8255DBD8
// RVA : 0x0055DBD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idNavSplinePathMgr_navSplineFloodBits_t_traversed(int *ptr, int value)
{
  *ptr = (value << 31) | *ptr & 0x7FFFFFFF;
}


// ========================================================================
// ?Get_idNavSplinePathMgr_navSplineFloodBits_t_queued@@YAHPAX@Z
// EA  : 0x8255DBE8
// RVA : 0x0055DBE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idNavSplinePathMgr_navSplineFloodBits_t_queued(_DWORD *ptr)
{
  return (2 * *ptr) >> 30;
}


// ========================================================================
// ?Set_idNavSplinePathMgr_navSplineFloodBits_t_queued@@YAXPAXH@Z
// EA  : 0x8255DBF8
// RVA : 0x0055DBF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idNavSplinePathMgr_navSplineFloodBits_t_queued(unsigned int *ptr, int value)
{
  *ptr = (value << 29) & 0x60000000 | *ptr & 0x9FFFFFFF;
}


// ========================================================================
// ?Get_idTarget_ChangeAnimState_queueChangeState@@YAHPAX@Z
// EA  : 0x8255DC08
// RVA : 0x0055DC08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idTarget_ChangeAnimState_queueChangeState(unsigned __int8 *ptr)
{
  return ptr[812] >> 7;
}


// ========================================================================
// ?Set_idTarget_ChangeAnimState_queueChangeState@@YAXPAXH@Z
// EA  : 0x8255DC18
// RVA : 0x0055DC18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_ChangeAnimState_queueChangeState(_BYTE *ptr, int value)
{
  ptr[812] = ((value != 0) << 7) | ptr[812] & 0x7F;
}


// ========================================================================
// ?Get_idTarget_ChangeAnimState_showIfHidden@@YAHPAX@Z
// EA  : 0x8255DC30
// RVA : 0x0055DC30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idTarget_ChangeAnimState_showIfHidden(_BYTE *ptr)
{
  return (ptr[812] & 0x40) != 0;
}


// ========================================================================
// ?Set_idTarget_ChangeAnimState_showIfHidden@@YAXPAXH@Z
// EA  : 0x8255DC40
// RVA : 0x0055DC40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_ChangeAnimState_showIfHidden(_BYTE *ptr, int value)
{
  ptr[812] = ((value != 0) << 6) & 0x40 | ptr[812] & 0xBF;
}


// ========================================================================
// ?Get_idTarget_ChangeAnimState_checkPoint@@YAHPAX@Z
// EA  : 0x8255DC58
// RVA : 0x0055DC58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idTarget_ChangeAnimState_checkPoint(_BYTE *ptr)
{
  return (ptr[812] & 0x20) != 0;
}


// ========================================================================
// ?Set_idTarget_ChangeAnimState_checkPoint@@YAXPAXH@Z
// EA  : 0x8255DC68
// RVA : 0x0055DC68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_ChangeAnimState_checkPoint(_BYTE *ptr, int value)
{
  ptr[812] = (32 * (value != 0)) & 0x20 | ptr[812] & 0xDF;
}


// ========================================================================
// ?Get_idTarget_ChangeAnimState_forceStartScriptedAnimWeb@@YAHPAX@Z
// EA  : 0x8255DC80
// RVA : 0x0055DC80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idTarget_ChangeAnimState_forceStartScriptedAnimWeb(_BYTE *ptr)
{
  return (ptr[812] & 0x10) != 0;
}


// ========================================================================
// ?Set_idTarget_ChangeAnimState_forceStartScriptedAnimWeb@@YAXPAXH@Z
// EA  : 0x8255DC90
// RVA : 0x0055DC90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_ChangeAnimState_forceStartScriptedAnimWeb(_BYTE *ptr, int value)
{
  ptr[812] = (16 * (value != 0)) & 0x10 | ptr[812] & 0xEF;
}


// ========================================================================
// ?Get_idTarget_PlayerOverrideFocus_toggle@@YAHPAX@Z
// EA  : 0x8255DCA8
// RVA : 0x0055DCA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idTarget_PlayerOverrideFocus_toggle(_BYTE *ptr)
{
  return (ptr[800] & 0x40) != 0;
}


// ========================================================================
// ?Set_idTarget_PlayerOverrideFocus_toggle@@YAXPAXH@Z
// EA  : 0x8255DCB8
// RVA : 0x0055DCB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_PlayerOverrideFocus_toggle(_BYTE *ptr, int value)
{
  ptr[800] = ((value != 0) << 6) & 0x40 | ptr[800] & 0xBF;
}


// ========================================================================
// ?Get_idTarget_SetSceneModelFlag_setFlag@@YAHPAX@Z
// EA  : 0x8255DCD0
// RVA : 0x0055DCD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idTarget_SetSceneModelFlag_setFlag(unsigned __int8 *ptr)
{
  return ptr[800] >> 7;
}


// ========================================================================
// ?Set_idTarget_PlayerOverrideFocus_set@@YAXPAXH@Z
// EA  : 0x8255DCE0
// RVA : 0x0055DCE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idTarget_PlayerOverrideFocus_set(_BYTE *ptr, int value)
{
  ptr[800] = ((value != 0) << 7) | ptr[800] & 0x7F;
}


// ========================================================================
// ?Get_idFirstPersonEvent_useAnimationOrigin@@YAHPAX@Z
// EA  : 0x8255DCF8
// RVA : 0x0055DCF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idFirstPersonEvent_useAnimationOrigin(unsigned __int8 *ptr)
{
  return ptr[1092] >> 7;
}


// ========================================================================
// ?Set_idFirstPersonEvent_useAnimationOrigin@@YAXPAXH@Z
// EA  : 0x8255DD08
// RVA : 0x0055DD08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_useAnimationOrigin(_BYTE *ptr, int value)
{
  ptr[1092] = ((value != 0) << 7) | ptr[1092] & 0x7F;
}


// ========================================================================
// ?Get_idFirstPersonEvent_useAnimationEndPos@@YAHPAX@Z
// EA  : 0x8255DD20
// RVA : 0x0055DD20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idFirstPersonEvent_useAnimationEndPos(_BYTE *ptr)
{
  return (ptr[1092] & 0x40) != 0;
}


// ========================================================================
// ?Set_idFirstPersonEvent_useAnimationEndPos@@YAXPAXH@Z
// EA  : 0x8255DD30
// RVA : 0x0055DD30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_useAnimationEndPos(_BYTE *ptr, int value)
{
  ptr[1092] = ((value != 0) << 6) & 0x40 | ptr[1092] & 0xBF;
}


// ========================================================================
// ?Get_idFirstPersonEvent_forceActivateOnPlayer@@YAHPAX@Z
// EA  : 0x8255DD48
// RVA : 0x0055DD48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idFirstPersonEvent_forceActivateOnPlayer(_BYTE *ptr)
{
  return (ptr[1092] & 0x20) != 0;
}


// ========================================================================
// ?Set_idFirstPersonEvent_forceActivateOnPlayer@@YAXPAXH@Z
// EA  : 0x8255DD58
// RVA : 0x0055DD58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_forceActivateOnPlayer(_BYTE *ptr, int value)
{
  ptr[1092] = (32 * (value != 0)) & 0x20 | ptr[1092] & 0xDF;
}


// ========================================================================
// ?Get_idFirstPersonEvent_shouldEndInCrouch@@YAHPAX@Z
// EA  : 0x8255DD70
// RVA : 0x0055DD70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idFirstPersonEvent_shouldEndInCrouch(_BYTE *ptr)
{
  return (ptr[1092] & 0x10) != 0;
}


// ========================================================================
// ?Set_idFirstPersonEvent_shouldEndInCrouch@@YAXPAXH@Z
// EA  : 0x8255DD80
// RVA : 0x0055DD80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_shouldEndInCrouch(_BYTE *ptr, int value)
{
  ptr[1092] = (16 * (value != 0)) & 0x10 | ptr[1092] & 0xEF;
}


// ========================================================================
// ?Get_idFirstPersonEvent_makePlayerFollowAlong@@YAHPAX@Z
// EA  : 0x8255DD98
// RVA : 0x0055DD98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idFirstPersonEvent_makePlayerFollowAlong(_BYTE *ptr)
{
  return (ptr[1092] & 8) != 0;
}


// ========================================================================
// ?Set_idFirstPersonEvent_makePlayerFollowAlong@@YAXPAXH@Z
// EA  : 0x8255DDA8
// RVA : 0x0055DDA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_makePlayerFollowAlong(_BYTE *ptr, int value)
{
  ptr[1092] = (8 * (value != 0)) & 8 | ptr[1092] & 0xF7;
}


// ========================================================================
// ?Get_idRenderModelParms_radiosityPreview@@YAHPAX@Z
// EA  : 0x8255DDC0
// RVA : 0x0055DDC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

int __fastcall Get_idRenderModelParms_radiosityPreview(unsigned __int8 *ptr)
{
  return ptr[116] >> 7;
}


// ========================================================================
// ?Set_idFirstPersonEvent_animEntry_t_loop@@YAXPAXH@Z
// EA  : 0x8255DDD0
// RVA : 0x0055DDD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idFirstPersonEvent_animEntry_t_loop(_BYTE *ptr, int value)
{
  ptr[116] = ((value != 0) << 7) | ptr[116] & 0x7F;
}


// ========================================================================
// ?Get_idFirstPersonEvent_animEntry_t_useTimeControl@@YAHPAX@Z
// EA  : 0x8255DDE8
// RVA : 0x0055DDE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

BOOL __fastcall Get_idFirstPersonEvent_animEntry_t_useTimeControl(_BYTE *ptr)
{
  return (ptr[116] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_rebakeModel@@YAXPAXH@Z
// EA  : 0x8255DDF8
// RVA : 0x0055DDF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_rebakeModel(_BYTE *ptr, int value)
{
  ptr[116] = ((value != 0) << 6) & 0x40 | ptr[116] & 0xBF;
}


// ========================================================================
// `dynamic initializer for 'idAISearchHintAuto_typeInfo''
// EA  : 0x83334F00
// RVA : 0x01334F00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idAISearchHintAuto_typeInfo__()
{
  idAISearchHintAuto_typeInfo[1].get = nullptr;
  idAISearchHintAuto_typeInfo[1].set = nullptr;
  idAISearchHintAuto_typeInfo[1].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idUseConstraints_typeInfo''
// EA  : 0x83334F20
// RVA : 0x01334F20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idUseConstraints_typeInfo__()
{
  idUseConstraints_typeInfo[4].get = nullptr;
  idUseConstraints_typeInfo[4].set = nullptr;
  idUseConstraints_typeInfo[4].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idUse_typeInfo''
// EA  : 0x83334F40
// RVA : 0x01334F40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idUse_typeInfo__()
{
  idUse_typeInfo[12].get = nullptr;
  idUse_typeInfo[12].set = nullptr;
  idUse_typeInfo[12].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idTest_MetaData_Circle_typeInfo''
// EA  : 0x83334F60
// RVA : 0x01334F60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idTest_MetaData_Circle_typeInfo__()
{
  idTest_MetaData_Circle_typeInfo[3].get = nullptr;
  idTest_MetaData_Circle_typeInfo[3].set = nullptr;
  idTest_MetaData_Circle_typeInfo[3].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idTest_MetaData_FovPitch_typeInfo''
// EA  : 0x83334F80
// RVA : 0x01334F80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idTest_MetaData_FovPitch_typeInfo__()
{
  idTest_MetaData_FovPitch_typeInfo[1].get = nullptr;
  idTest_MetaData_FovPitch_typeInfo[1].set = nullptr;
  idTest_MetaData_FovPitch_typeInfo[1].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idTest_MetaData_FovYaw_typeInfo''
// EA  : 0x83334FA0
// RVA : 0x01334FA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idTest_MetaData_FovYaw_typeInfo__()
{
  idTest_MetaData_FovYaw_typeInfo[1].get = nullptr;
  idTest_MetaData_FovYaw_typeInfo[1].set = nullptr;
  idTest_MetaData_FovYaw_typeInfo[1].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'moveFailureInfo_t_typeInfo''
// EA  : 0x83334FC0
// RVA : 0x01334FC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__moveFailureInfo_t_typeInfo__()
{
  moveFailureInfo_t_typeInfo[4].get = nullptr;
  moveFailureInfo_t_typeInfo[4].set = nullptr;
  moveFailureInfo_t_typeInfo[4].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAIEditable_idAIPerception_typeInfo''
// EA  : 0x83334FE0
// RVA : 0x01334FE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idAIEditable_idAIPerception_typeInfo__()
{
  idAIEditable_idAIPerception_typeInfo[14].get = nullptr;
  idAIEditable_idAIPerception_typeInfo[14].set = nullptr;
  idAIEditable_idAIPerception_typeInfo[14].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAI2_idAIConstant_idAIMovement_typeInfo''
// EA  : 0x83335000
// RVA : 0x01335000
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idAI2_idAIConstant_idAIMovement_typeInfo__()
{
  idAI2_idAIConstant_idAIMovement_typeInfo[11].get = nullptr;
  idAI2_idAIConstant_idAIMovement_typeInfo[11].set = nullptr;
  idAI2_idAIConstant_idAIMovement_typeInfo[11].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idTarget_ApplyExplosionImpulse_typeInfo''
// EA  : 0x83335020
// RVA : 0x01335020
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_3.cpp
// ========================================================================

void _dynamic_initializer_for__idTarget_ApplyExplosionImpulse_typeInfo__()
{
  idTarget_ApplyExplosionImpulse_typeInfo[8].get = nullptr;
  idTarget_ApplyExplosionImpulse_typeInfo[8].set = nullptr;
  idTarget_ApplyExplosionImpulse_typeInfo[8].reallocate = nullptr;
}

