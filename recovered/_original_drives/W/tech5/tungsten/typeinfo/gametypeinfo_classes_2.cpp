
// ========================================================================
// ?Get_idAnimator_TrackerBase_yawClamped@@YAHPAX@Z
// EA  : 0x8255ADA0
// RVA : 0x0055ADA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAnimator_TrackerBase_yawClamped(unsigned __int8 *ptr)
{
  return ptr[180] >> 7;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_yawClamped@@YAXPAXH@Z
// EA  : 0x8255ADB0
// RVA : 0x0055ADB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_yawClamped(_BYTE *ptr, int value)
{
  ptr[180] = ((value != 0) << 7) | ptr[180] & 0x7F;
}


// ========================================================================
// ?Get_idAnimator_TrackerBase_pitchClamped@@YAHPAX@Z
// EA  : 0x8255ADC8
// RVA : 0x0055ADC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_TrackerBase_pitchClamped(_BYTE *ptr)
{
  return (ptr[180] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_pitchClamped@@YAXPAXH@Z
// EA  : 0x8255ADD8
// RVA : 0x0055ADD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_pitchClamped(_BYTE *ptr, int value)
{
  ptr[180] = ((value != 0) << 6) & 0x40 | ptr[180] & 0xBF;
}


// ========================================================================
// ?Get_idAnimator_TrackerBase_enableConstraints@@YAHPAX@Z
// EA  : 0x8255ADF0
// RVA : 0x0055ADF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_TrackerBase_enableConstraints(_BYTE *ptr)
{
  return (ptr[180] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_enableConstraints@@YAXPAXH@Z
// EA  : 0x8255AE00
// RVA : 0x0055AE00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_enableConstraints(_BYTE *ptr, int value)
{
  ptr[180] = (32 * (value != 0)) & 0x20 | ptr[180] & 0xDF;
}


// ========================================================================
// ?Get_idAnimator_TrackerBase_projectReferenceOrientation@@YAHPAX@Z
// EA  : 0x8255AE18
// RVA : 0x0055AE18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_TrackerBase_projectReferenceOrientation(_BYTE *ptr)
{
  return (ptr[180] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_projectReferenceOrientation@@YAXPAXH@Z
// EA  : 0x8255AE28
// RVA : 0x0055AE28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_projectReferenceOrientation(_BYTE *ptr, int value)
{
  ptr[180] = (16 * (value != 0)) & 0x10 | ptr[180] & 0xEF;
}


// ========================================================================
// ?Get_idAnimator_TrackerBase_clientSnapFocusPoint@@YAHPAX@Z
// EA  : 0x8255AE40
// RVA : 0x0055AE40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_TrackerBase_clientSnapFocusPoint(_BYTE *ptr)
{
  return (ptr[180] & 8) != 0;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_clientSnapFocusPoint@@YAXPAXH@Z
// EA  : 0x8255AE50
// RVA : 0x0055AE50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_clientSnapFocusPoint(_BYTE *ptr, int value)
{
  ptr[180] = (8 * (value != 0)) & 8 | ptr[180] & 0xF7;
}


// ========================================================================
// ?Get_idAnimator_TrackerBase_lockTracking@@YAHPAX@Z
// EA  : 0x8255AE68
// RVA : 0x0055AE68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimator_TrackerBase_lockTracking(_BYTE *ptr)
{
  return (ptr[180] & 4) != 0;
}


// ========================================================================
// ?Set_idAnimator_TrackerBase_lockTracking@@YAXPAXH@Z
// EA  : 0x8255AE78
// RVA : 0x0055AE78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimator_TrackerBase_lockTracking(_BYTE *ptr, int value)
{
  ptr[180] = (4 * (value != 0)) & 4 | ptr[180] & 0xFB;
}


// ========================================================================
// ?Get_idPlayer_hidden@@YAHPAX@Z
// EA  : 0x8255AE90
// RVA : 0x0055AE90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPlayer_hidden(unsigned __int8 *ptr)
{
  return ptr[12824] >> 7;
}


// ========================================================================
// ?Set_idPlayer_hidden@@YAXPAXH@Z
// EA  : 0x8255AEA0
// RVA : 0x0055AEA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_hidden(_BYTE *ptr, int value)
{
  ptr[12824] = ((value != 0) << 7) | ptr[12824] & 0x7F;
}


// ========================================================================
// ?Get_idPlayer_godMode@@YAHPAX@Z
// EA  : 0x8255AEB8
// RVA : 0x0055AEB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_godMode(_BYTE *ptr)
{
  return (ptr[12824] & 0x40) != 0;
}


// ========================================================================
// ?Set_idPlayer_godMode@@YAXPAXH@Z
// EA  : 0x8255AEC8
// RVA : 0x0055AEC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_godMode(_BYTE *ptr, int value)
{
  ptr[12824] = ((value != 0) << 6) & 0x40 | ptr[12824] & 0xBF;
}


// ========================================================================
// ?Get_idPlayer_infiniteHealth@@YAHPAX@Z
// EA  : 0x8255AEE0
// RVA : 0x0055AEE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_infiniteHealth(_BYTE *ptr)
{
  return (ptr[12824] & 0x20) != 0;
}


// ========================================================================
// ?Set_idPlayer_infiniteHealth@@YAXPAXH@Z
// EA  : 0x8255AEF0
// RVA : 0x0055AEF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_infiniteHealth(_BYTE *ptr, int value)
{
  ptr[12824] = (32 * (value != 0)) & 0x20 | ptr[12824] & 0xDF;
}


// ========================================================================
// ?Get_idPlayer_noPlayerDeath@@YAHPAX@Z
// EA  : 0x8255AF08
// RVA : 0x0055AF08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_noPlayerDeath(_BYTE *ptr)
{
  return (ptr[12824] & 0x10) != 0;
}


// ========================================================================
// ?Set_idPlayer_noPlayerDeath@@YAXPAXH@Z
// EA  : 0x8255AF18
// RVA : 0x0055AF18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_noPlayerDeath(_BYTE *ptr, int value)
{
  ptr[12824] = (16 * (value != 0)) & 0x10 | ptr[12824] & 0xEF;
}


// ========================================================================
// ?Get_idPlayer_noTarget@@YAHPAX@Z
// EA  : 0x8255AF30
// RVA : 0x0055AF30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_noTarget(_BYTE *ptr)
{
  return (ptr[12824] & 8) != 0;
}


// ========================================================================
// ?Set_idPlayer_noTarget@@YAXPAXH@Z
// EA  : 0x8255AF40
// RVA : 0x0055AF40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_noTarget(_BYTE *ptr, int value)
{
  ptr[12824] = (8 * (value != 0)) & 8 | ptr[12824] & 0xF7;
}


// ========================================================================
// ?Get_idPlayer_transitioning@@YAHPAX@Z
// EA  : 0x8255AF58
// RVA : 0x0055AF58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_transitioning(_BYTE *ptr)
{
  return (ptr[12824] & 4) != 0;
}


// ========================================================================
// ?Set_idPlayer_transitioning@@YAXPAXH@Z
// EA  : 0x8255AF68
// RVA : 0x0055AF68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_transitioning(_BYTE *ptr, int value)
{
  ptr[12824] = (4 * (value != 0)) & 4 | ptr[12824] & 0xFB;
}


// ========================================================================
// ?Get_idPlayer_readingLevelStateFromFile@@YAHPAX@Z
// EA  : 0x8255AF80
// RVA : 0x0055AF80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPlayer_readingLevelStateFromFile(_BYTE *ptr)
{
  return (ptr[12824] & 2) != 0;
}


// ========================================================================
// ?Set_idPlayer_readingLevelStateFromFile@@YAXPAXH@Z
// EA  : 0x8255AF90
// RVA : 0x0055AF90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPlayer_readingLevelStateFromFile(_BYTE *ptr, int value)
{
  ptr[12824] = (2 * (value != 0)) & 2 | ptr[12824] & 0xFD;
}


// ========================================================================
// ?Get_idEntity_idBindInfo_bindOrientated@@YAHPAX@Z
// EA  : 0x8255AFA8
// RVA : 0x0055AFA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idEntity_idBindInfo_bindOrientated(unsigned __int8 *ptr)
{
  return ptr[112] >> 7;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_translationGoalPriorToEnd@@YAHPAX@Z
// EA  : 0x8255AFB8
// RVA : 0x0055AFB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_animDeltaCorrection_t_translationGoalPriorToEnd(unsigned __int8 *ptr)
{
  return ptr[372] >> 7;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_translationGoalPriorToEnd@@YAXPAXH@Z
// EA  : 0x8255AFC8
// RVA : 0x0055AFC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_translationGoalPriorToEnd(_BYTE *ptr, int value)
{
  ptr[372] = ((value != 0) << 7) | ptr[372] & 0x7F;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_rotationGoalPriorToEnd@@YAHPAX@Z
// EA  : 0x8255AFE0
// RVA : 0x0055AFE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_rotationGoalPriorToEnd(_BYTE *ptr)
{
  return (ptr[372] & 0x40) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_rotationGoalPriorToEnd@@YAXPAXH@Z
// EA  : 0x8255AFF0
// RVA : 0x0055AFF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_rotationGoalPriorToEnd(_BYTE *ptr, int value)
{
  ptr[372] = ((value != 0) << 6) & 0x40 | ptr[372] & 0xBF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_useDeltaCorrection@@YAHPAX@Z
// EA  : 0x8255B008
// RVA : 0x0055B008
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_useDeltaCorrection(_BYTE *ptr)
{
  return (ptr[372] & 0x20) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_useDeltaCorrection@@YAXPAXH@Z
// EA  : 0x8255B018
// RVA : 0x0055B018
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_useDeltaCorrection(_BYTE *ptr, int value)
{
  ptr[372] = (32 * (value != 0)) & 0x20 | ptr[372] & 0xDF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_animHasRemainingDelta@@YAHPAX@Z
// EA  : 0x8255B030
// RVA : 0x0055B030
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_animHasRemainingDelta(_BYTE *ptr)
{
  return (ptr[372] & 0x10) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_animHasRemainingDelta@@YAXPAXH@Z
// EA  : 0x8255B040
// RVA : 0x0055B040
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_animHasRemainingDelta(_BYTE *ptr, int value)
{
  ptr[372] = (16 * (value != 0)) & 0x10 | ptr[372] & 0xEF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_translationIgnoresRemaningFrames@@YAHPAX@Z
// EA  : 0x8255B058
// RVA : 0x0055B058
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_animDeltaCorrection_t_input_t_translationIgnoresRemaningFrames(unsigned __int8 *ptr)
{
  return ptr[40] >> 7;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_restrictRotationDirectionYaw@@YAHPAX@Z
// EA  : 0x8255B068
// RVA : 0x0055B068
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_restrictRotationDirectionYaw(_BYTE *ptr)
{
  return (ptr[40] & 0x40) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idMovementBehaviors_allowTransitionOvershoot@@YAHPAX@Z
// EA  : 0x8255B078
// RVA : 0x0055B078
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idMovementBehaviors_allowTransitionOvershoot(_BYTE *ptr)
{
  return (ptr[40] & 0x20) != 0;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_restrictRotationDirectionRoll@@YAHPAX@Z
// EA  : 0x8255B088
// RVA : 0x0055B088
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_restrictRotationDirectionRoll(_BYTE *ptr)
{
  return (ptr[40] & 0x10) != 0;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_noReverseRotation@@YAHPAX@Z
// EA  : 0x8255B098
// RVA : 0x0055B098
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_noReverseRotation(_BYTE *ptr)
{
  return (ptr[40] & 8) != 0;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_rotationIgnoresRemainingFrames@@YAHPAX@Z
// EA  : 0x8255B0A8
// RVA : 0x0055B0A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_rotationIgnoresRemainingFrames(_BYTE *ptr)
{
  return (ptr[40] & 4) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idMovementBehaviors_enemyCloseObscurityTest@@YAHPAX@Z
// EA  : 0x8255B0B8
// RVA : 0x0055B0B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idMovementBehaviors_enemyCloseObscurityTest(_BYTE *ptr)
{
  return (ptr[40] & 2) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idMovementBehaviors_allowEnemySightedCrouchIdle@@YAHPAX@Z
// EA  : 0x8255B0C8
// RVA : 0x0055B0C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_idMovementBehaviors_allowEnemySightedCrouchIdle(_BYTE *ptr)
{
  return ptr[40] & 1;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idMovementBehaviors_obstacleAvoid_IgnorePlayer@@YAHPAX@Z
// EA  : 0x8255B0D8
// RVA : 0x0055B0D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_idMovementBehaviors_obstacleAvoid_IgnorePlayer(unsigned __int8 *ptr)
{
  return ptr[41] >> 7;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_allowYawCorrection@@YAHPAX@Z
// EA  : 0x8255B0E8
// RVA : 0x0055B0E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_allowYawCorrection(_BYTE *ptr)
{
  return (ptr[41] & 0x40) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_allowYawCorrection@@YAXPAXH@Z
// EA  : 0x8255B0F8
// RVA : 0x0055B0F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_allowYawCorrection(_BYTE *ptr, int value)
{
  ptr[41] = ((value != 0) << 6) & 0x40 | ptr[41] & 0xBF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_allowPitchCorrection@@YAHPAX@Z
// EA  : 0x8255B110
// RVA : 0x0055B110
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_allowPitchCorrection(_BYTE *ptr)
{
  return (ptr[41] & 0x20) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_allowPitchCorrection@@YAXPAXH@Z
// EA  : 0x8255B120
// RVA : 0x0055B120
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_allowPitchCorrection(_BYTE *ptr, int value)
{
  ptr[41] = (32 * (value != 0)) & 0x20 | ptr[41] & 0xDF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_allowRollCorrection@@YAHPAX@Z
// EA  : 0x8255B138
// RVA : 0x0055B138
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_allowRollCorrection(_BYTE *ptr)
{
  return (ptr[41] & 0x10) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_allowRollCorrection@@YAXPAXH@Z
// EA  : 0x8255B148
// RVA : 0x0055B148
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_allowRollCorrection(_BYTE *ptr, int value)
{
  ptr[41] = (16 * (value != 0)) & 0x10 | ptr[41] & 0xEF;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_correctTranslatedRotation@@YAHPAX@Z
// EA  : 0x8255B160
// RVA : 0x0055B160
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_correctTranslatedRotation(_BYTE *ptr)
{
  return (ptr[41] & 8) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_correctTranslatedRotation@@YAXPAXH@Z
// EA  : 0x8255B170
// RVA : 0x0055B170
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_correctTranslatedRotation(_BYTE *ptr, int value)
{
  ptr[41] = (8 * (value != 0)) & 8 | ptr[41] & 0xF7;
}


// ========================================================================
// ?Get_animDeltaCorrection_t_input_t_noDeltaRebuild@@YAHPAX@Z
// EA  : 0x8255B188
// RVA : 0x0055B188
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_animDeltaCorrection_t_input_t_noDeltaRebuild(_BYTE *ptr)
{
  return (ptr[41] & 4) != 0;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_noDeltaRebuild@@YAXPAXH@Z
// EA  : 0x8255B198
// RVA : 0x0055B198
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_noDeltaRebuild(_BYTE *ptr, int value)
{
  ptr[41] = (4 * (value != 0)) & 4 | ptr[41] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelInfo_allowInline@@YAHPAX@Z
// EA  : 0x8255B1B0
// RVA : 0x0055B1B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idRenderModelInfo_allowInline(unsigned __int8 *ptr)
{
  return ptr[4] >> 7;
}


// ========================================================================
// ?Get_idRenderModelInfo_noAmbient@@YAHPAX@Z
// EA  : 0x8255B1C0
// RVA : 0x0055B1C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_noAmbient(_BYTE *ptr)
{
  return (ptr[4] & 0x40) != 0;
}


// ========================================================================
// ?Get_idPhysics_RigidBody_rigidBodyFlags_t_noImpact@@YAHPAX@Z
// EA  : 0x8255B1D0
// RVA : 0x0055B1D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPhysics_RigidBody_rigidBodyFlags_t_noImpact(_BYTE *ptr)
{
  return (ptr[4] & 0x20) != 0;
}


// ========================================================================
// ?Get_idPhysics_RigidBody_rigidBodyFlags_t_hasMaster@@YAHPAX@Z
// EA  : 0x8255B1E0
// RVA : 0x0055B1E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPhysics_RigidBody_rigidBodyFlags_t_hasMaster(_BYTE *ptr)
{
  return (ptr[4] & 0x10) != 0;
}


// ========================================================================
// ?Get_idCoverActions_fireStepRight@@YAHPAX@Z
// EA  : 0x8255B1F0
// RVA : 0x0055B1F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverActions_fireStepRight(_BYTE *ptr)
{
  return (ptr[4] & 8) != 0;
}


// ========================================================================
// ?Get_idNavSplinePath_splineFlags_t_mainRoad@@YAHPAX@Z
// EA  : 0x8255B200
// RVA : 0x0055B200
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idNavSplinePath_splineFlags_t_mainRoad(unsigned __int8 *ptr)
{
  return *ptr >> 7;
}


// ========================================================================
// ?Get_idCoverTransitions_left@@YAHPAX@Z
// EA  : 0x8255B210
// RVA : 0x0055B210
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverTransitions_left(_BYTE *ptr)
{
  return (*ptr & 0x40) != 0;
}


// ========================================================================
// ?Get_idAnimatedSimple_idFacialOptions_t_useBlinking@@YAHPAX@Z
// EA  : 0x8255B220
// RVA : 0x0055B220
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_idFacialOptions_t_useBlinking(_BYTE *ptr)
{
  return (*ptr & 0x10) != 0;
}


// ========================================================================
// ?Get_idCoverTransitions_right@@YAHPAX@Z
// EA  : 0x8255B230
// RVA : 0x0055B230
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverTransitions_right(_BYTE *ptr)
{
  return (*ptr & 8) != 0;
}


// ========================================================================
// ?Get_idContents_vehicleClip@@YAHPAX@Z
// EA  : 0x8255B240
// RVA : 0x0055B240
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idContents_vehicleClip(_BYTE *ptr)
{
  return (*ptr & 4) != 0;
}


// ========================================================================
// ?Get_idAFBody_afBodyFlags_t_noSyncCollide@@YAHPAX@Z
// EA  : 0x8255B250
// RVA : 0x0055B250
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAFBody_afBodyFlags_t_noSyncCollide(_BYTE *ptr)
{
  return (*ptr & 2) != 0;
}


// ========================================================================
// ?Get_idContents_shotClip@@YAHPAX@Z
// EA  : 0x8255B260
// RVA : 0x0055B260
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idContents_shotClip(_BYTE *ptr)
{
  return *ptr & 1;
}


// ========================================================================
// ?Get_idAIEditable_idAICoverInfo_canUseExposedCover@@YAHPAX@Z
// EA  : 0x8255B270
// RVA : 0x0055B270
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAIEditable_idAICoverInfo_canUseExposedCover(unsigned __int8 *ptr)
{
  return ptr[8] >> 7;
}


// ========================================================================
// ?Get_idCoverCapabilities_blindfireRight@@YAHPAX@Z
// EA  : 0x8255B280
// RVA : 0x0055B280
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_blindfireRight(_BYTE *ptr)
{
  return (ptr[8] & 0x40) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_blindfireRight@@YAXPAXH@Z
// EA  : 0x8255B290
// RVA : 0x0055B290
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_blindfireRight(_BYTE *ptr, int value)
{
  ptr[8] = ((value != 0) << 6) & 0x40 | ptr[8] & 0xBF;
}


// ========================================================================
// ?Get_idCoverCapabilities_blindfireOver@@YAHPAX@Z
// EA  : 0x8255B2A8
// RVA : 0x0055B2A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_blindfireOver(_BYTE *ptr)
{
  return (ptr[8] & 0x20) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_blindfireOver@@YAXPAXH@Z
// EA  : 0x8255B2B8
// RVA : 0x0055B2B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_blindfireOver(_BYTE *ptr, int value)
{
  ptr[8] = (32 * (value != 0)) & 0x20 | ptr[8] & 0xDF;
}


// ========================================================================
// ?Get_idCoverCapabilities_peekLeft@@YAHPAX@Z
// EA  : 0x8255B2D0
// RVA : 0x0055B2D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_peekLeft(_BYTE *ptr)
{
  return (ptr[8] & 0x10) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_peekLeft@@YAXPAXH@Z
// EA  : 0x8255B2E0
// RVA : 0x0055B2E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_peekLeft(_BYTE *ptr, int value)
{
  ptr[8] = (16 * (value != 0)) & 0x10 | ptr[8] & 0xEF;
}


// ========================================================================
// ?Get_idCoverCapabilities_peekRight@@YAHPAX@Z
// EA  : 0x8255B2F8
// RVA : 0x0055B2F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_peekRight(_BYTE *ptr)
{
  return (ptr[8] & 8) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_peekRight@@YAXPAXH@Z
// EA  : 0x8255B308
// RVA : 0x0055B308
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_peekRight(_BYTE *ptr, int value)
{
  ptr[8] = (8 * (value != 0)) & 8 | ptr[8] & 0xF7;
}


// ========================================================================
// ?Get_idCoverCapabilities_peekOver@@YAHPAX@Z
// EA  : 0x8255B320
// RVA : 0x0055B320
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_peekOver(_BYTE *ptr)
{
  return (ptr[8] & 4) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_peekOver@@YAXPAXH@Z
// EA  : 0x8255B330
// RVA : 0x0055B330
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_peekOver(_BYTE *ptr, int value)
{
  ptr[8] = (4 * (value != 0)) & 4 | ptr[8] & 0xFB;
}


// ========================================================================
// ?Get_idCoverCapabilities_hide@@YAHPAX@Z
// EA  : 0x8255B348
// RVA : 0x0055B348
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idCoverCapabilities_hide(_BYTE *ptr)
{
  return (ptr[8] & 2) != 0;
}


// ========================================================================
// ?Set_idCoverCapabilities_hide@@YAXPAXH@Z
// EA  : 0x8255B358
// RVA : 0x0055B358
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idCoverCapabilities_hide(_BYTE *ptr, int value)
{
  ptr[8] = (2 * (value != 0)) & 2 | ptr[8] & 0xFD;
}


// ========================================================================
// ?Get_idVoiceInfo_dontPlayIfGroupDead@@YAHPAX@Z
// EA  : 0x8255B370
// RVA : 0x0055B370
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVoiceInfo_dontPlayIfGroupDead(unsigned __int8 *ptr)
{
  return ptr[25] >> 7;
}


// ========================================================================
// ?Set_idVoiceInfo_dontPlayIfGroupDead@@YAXPAXH@Z
// EA  : 0x8255B380
// RVA : 0x0055B380
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVoiceInfo_dontPlayIfGroupDead(_BYTE *ptr, int value)
{
  ptr[25] = ((value != 0) << 7) | ptr[25] & 0x7F;
}


// ========================================================================
// ?Get_idVoiceInfo_playOnce@@YAHPAX@Z
// EA  : 0x8255B398
// RVA : 0x0055B398
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVoiceInfo_playOnce(_BYTE *ptr)
{
  return (ptr[25] & 0x40) != 0;
}


// ========================================================================
// ?Set_idVoiceInfo_playOnce@@YAXPAXH@Z
// EA  : 0x8255B3A8
// RVA : 0x0055B3A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVoiceInfo_playOnce(_BYTE *ptr, int value)
{
  ptr[25] = ((value != 0) << 6) & 0x40 | ptr[25] & 0xBF;
}


// ========================================================================
// ?Get_idNpCornerInfo_isGoal@@YAHPAX@Z
// EA  : 0x8255B3C0
// RVA : 0x0055B3C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idNpCornerInfo_isGoal(unsigned __int8 *ptr)
{
  return ptr[56] >> 7;
}


// ========================================================================
// ?Set_idNpCornerInfo_isGoal@@YAXPAXH@Z
// EA  : 0x8255B3D0
// RVA : 0x0055B3D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpCornerInfo_isGoal(_BYTE *ptr, int value)
{
  ptr[56] = ((value != 0) << 7) | ptr[56] & 0x7F;
}


// ========================================================================
// ?Get_idNpCornerInfo_stopToUse@@YAHPAX@Z
// EA  : 0x8255B3E8
// RVA : 0x0055B3E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idNpCornerInfo_stopToUse(_BYTE *ptr)
{
  return (ptr[56] & 0x40) != 0;
}


// ========================================================================
// ?Set_idNpCornerInfo_stopToUse@@YAXPAXH@Z
// EA  : 0x8255B3F8
// RVA : 0x0055B3F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpCornerInfo_stopToUse(_BYTE *ptr, int value)
{
  ptr[56] = ((value != 0) << 6) & 0x40 | ptr[56] & 0xBF;
}


// ========================================================================
// ?Get_idNpCornerInfo_jumpLink@@YAHPAX@Z
// EA  : 0x8255B410
// RVA : 0x0055B410
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idNpCornerInfo_jumpLink(_BYTE *ptr)
{
  return (ptr[56] & 0x20) != 0;
}


// ========================================================================
// ?Set_idNpCornerInfo_jumpLink@@YAXPAXH@Z
// EA  : 0x8255B420
// RVA : 0x0055B420
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpCornerInfo_jumpLink(_BYTE *ptr, int value)
{
  ptr[56] = (32 * (value != 0)) & 0x20 | ptr[56] & 0xDF;
}


// ========================================================================
// ?Get_idNpCornerInfo_biDirectional@@YAHPAX@Z
// EA  : 0x8255B438
// RVA : 0x0055B438
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idNpCornerInfo_biDirectional(_BYTE *ptr)
{
  return (ptr[56] & 0x10) != 0;
}


// ========================================================================
// ?Set_idNpCornerInfo_biDirectional@@YAXPAXH@Z
// EA  : 0x8255B448
// RVA : 0x0055B448
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpCornerInfo_biDirectional(_BYTE *ptr, int value)
{
  ptr[56] = (16 * (value != 0)) & 0x10 | ptr[56] & 0xEF;
}


// ========================================================================
// ?Get_idNpCornerInfo_isPointGrounded@@YAHPAX@Z
// EA  : 0x8255B460
// RVA : 0x0055B460
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idNpCornerInfo_isPointGrounded(_BYTE *ptr)
{
  return (ptr[56] & 8) != 0;
}


// ========================================================================
// ?Set_idNpCornerInfo_isPointGrounded@@YAXPAXH@Z
// EA  : 0x8255B470
// RVA : 0x0055B470
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpCornerInfo_isPointGrounded(_BYTE *ptr, int value)
{
  ptr[56] = (8 * (value != 0)) & 8 | ptr[56] & 0xF7;
}


// ========================================================================
// ?Set_idNpMover_idLinkUseParms_isJumpLink@@YAXPAXH@Z
// EA  : 0x8255B488
// RVA : 0x0055B488
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idNpMover_idLinkUseParms_isJumpLink(_BYTE *ptr, int value)
{
  ptr[72] = ((value != 0) << 7) | ptr[72] & 0x7F;
}


// ========================================================================
// ?Set_idMaterial_materialIsTwoSided@@YAXPAXH@Z
// EA  : 0x8255B4A0
// RVA : 0x0055B4A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idMaterial_materialIsTwoSided(_BYTE *ptr, int value)
{
  ptr[72] = ((value != 0) << 6) & 0x40 | ptr[72] & 0xBF;
}


// ========================================================================
// ?Get_idAIFormation_canLead@@YAHPAX@Z
// EA  : 0x8255B4B8
// RVA : 0x0055B4B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAIFormation_canLead(unsigned __int8 *ptr)
{
  return ptr[32] >> 7;
}


// ========================================================================
// ?Get_idAIFormation_canFollow@@YAHPAX@Z
// EA  : 0x8255B4C8
// RVA : 0x0055B4C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIFormation_canFollow(_BYTE *ptr)
{
  return (ptr[32] & 0x40) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_canTakeDamage@@YAHPAX@Z
// EA  : 0x8255B4D8
// RVA : 0x0055B4D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_idDamageBehaviors_canTakeDamage(unsigned __int8 *ptr)
{
  return ptr[84] >> 7;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_hasAdditivePains@@YAHPAX@Z
// EA  : 0x8255B4E8
// RVA : 0x0055B4E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idDamageBehaviors_hasAdditivePains(_BYTE *ptr)
{
  return (ptr[84] & 0x40) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_hasMovingPainAnims@@YAHPAX@Z
// EA  : 0x8255B4F8
// RVA : 0x0055B4F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idDamageBehaviors_hasMovingPainAnims(_BYTE *ptr)
{
  return (ptr[84] & 0x20) != 0;
}


// ========================================================================
// ?Get_idEntityDefEditorVars_showInRenderMode@@YAHPAX@Z
// EA  : 0x8255B508
// RVA : 0x0055B508
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntityDefEditorVars_showInRenderMode(_BYTE *ptr)
{
  return (ptr[84] & 0x10) != 0;
}


// ========================================================================
// ?Get_idAIEditable_idAIDeath_canBecomeIntimidated@@YAHPAX@Z
// EA  : 0x8255B518
// RVA : 0x0055B518
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIEditable_idAIDeath_canBecomeIntimidated(_BYTE *ptr)
{
  return (ptr[84] & 8) != 0;
}


// ========================================================================
// ?Get_idEntityDefEditorVars_instantiable@@YAHPAX@Z
// EA  : 0x8255B528
// RVA : 0x0055B528
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntityDefEditorVars_instantiable(_BYTE *ptr)
{
  return (ptr[84] & 4) != 0;
}


// ========================================================================
// ?Get_idEntityDefEditorVars_noClip@@YAHPAX@Z
// EA  : 0x8255B538
// RVA : 0x0055B538
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntityDefEditorVars_noClip(_BYTE *ptr)
{
  return (ptr[84] & 2) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_hasBlood@@YAHPAX@Z
// EA  : 0x8255B548
// RVA : 0x0055B548
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_idDamageBehaviors_hasBlood(_BYTE *ptr)
{
  return ptr[84] & 1;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canJump@@YAHPAX@Z
// EA  : 0x8255B558
// RVA : 0x0055B558
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_canJump(unsigned __int8 *ptr)
{
  return ptr[85] >> 7;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canSwim@@YAHPAX@Z
// EA  : 0x8255B568
// RVA : 0x0055B568
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_canSwim(_BYTE *ptr)
{
  return (ptr[85] & 0x40) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canUseTraversals@@YAHPAX@Z
// EA  : 0x8255B578
// RVA : 0x0055B578
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_canUseTraversals(_BYTE *ptr)
{
  return (ptr[85] & 0x20) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canUseTraversalEvasions@@YAHPAX@Z
// EA  : 0x8255B588
// RVA : 0x0055B588
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_canUseTraversalEvasions(_BYTE *ptr)
{
  return (ptr[85] & 0x10) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_usesExplosionPains@@YAHPAX@Z
// EA  : 0x8255B598
// RVA : 0x0055B598
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idDamageBehaviors_usesExplosionPains(_BYTE *ptr)
{
  return (ptr[85] & 8) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_idDamageBehaviors_fourDirExplosionPain@@YAHPAX@Z
// EA  : 0x8255B5A8
// RVA : 0x0055B5A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_idDamageBehaviors_fourDirExplosionPain(_BYTE *ptr)
{
  return (ptr[85] & 4) != 0;
}


// ========================================================================
// ?Get_idDeclAIBehavior_isVehicleChaser@@YAHPAX@Z
// EA  : 0x8255B5B8
// RVA : 0x0055B5B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_isVehicleChaser(_BYTE *ptr)
{
  return (ptr[85] & 2) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_isVehicleChaser@@YAXPAXH@Z
// EA  : 0x8255B5C8
// RVA : 0x0055B5C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_isVehicleChaser(_BYTE *ptr, int value)
{
  ptr[85] = (2 * (value != 0)) & 2 | ptr[85] & 0xFD;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesSearch@@YAHPAX@Z
// EA  : 0x8255B5E0
// RVA : 0x0055B5E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesSearch(_BYTE *ptr)
{
  return ptr[85] & 1;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesSearch@@YAXPAXH@Z
// EA  : 0x8255B5F0
// RVA : 0x0055B5F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesSearch(_BYTE *ptr, int value)
{
  ptr[85] = (value != 0) | ptr[85] & 0xFE;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAvoid@@YAHPAX@Z
// EA  : 0x8255B608
// RVA : 0x0055B608
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesAvoid(unsigned __int8 *ptr)
{
  return ptr[86] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAvoid@@YAXPAXH@Z
// EA  : 0x8255B618
// RVA : 0x0055B618
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAvoid(_BYTE *ptr, int value)
{
  ptr[86] = ((value != 0) << 7) | ptr[86] & 0x7F;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAvoidRun@@YAHPAX@Z
// EA  : 0x8255B630
// RVA : 0x0055B630
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesAvoidRun(_BYTE *ptr)
{
  return (ptr[86] & 0x40) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAvoidRun@@YAXPAXH@Z
// EA  : 0x8255B640
// RVA : 0x0055B640
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAvoidRun(_BYTE *ptr, int value)
{
  ptr[86] = ((value != 0) << 6) & 0x40 | ptr[86] & 0xBF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAvoidCover@@YAHPAX@Z
// EA  : 0x8255B658
// RVA : 0x0055B658
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesAvoidCover(_BYTE *ptr)
{
  return (ptr[86] & 0x20) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAvoidCover@@YAXPAXH@Z
// EA  : 0x8255B668
// RVA : 0x0055B668
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAvoidCover(_BYTE *ptr, int value)
{
  ptr[86] = (32 * (value != 0)) & 0x20 | ptr[86] & 0xDF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAvoidDive@@YAHPAX@Z
// EA  : 0x8255B680
// RVA : 0x0055B680
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesAvoidDive(_BYTE *ptr)
{
  return (ptr[86] & 0x10) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAvoidDive@@YAXPAXH@Z
// EA  : 0x8255B690
// RVA : 0x0055B690
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAvoidDive(_BYTE *ptr, int value)
{
  ptr[86] = (16 * (value != 0)) & 0x10 | ptr[86] & 0xEF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAvoidCower@@YAHPAX@Z
// EA  : 0x8255B6A8
// RVA : 0x0055B6A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesAvoidCower(_BYTE *ptr)
{
  return (ptr[86] & 8) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAvoidCower@@YAXPAXH@Z
// EA  : 0x8255B6B8
// RVA : 0x0055B6B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAvoidCower(_BYTE *ptr, int value)
{
  ptr[86] = (8 * (value != 0)) & 8 | ptr[86] & 0xF7;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesPanic@@YAHPAX@Z
// EA  : 0x8255B6D0
// RVA : 0x0055B6D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesPanic(_BYTE *ptr)
{
  return (ptr[86] & 4) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesPanic@@YAXPAXH@Z
// EA  : 0x8255B6E0
// RVA : 0x0055B6E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesPanic(_BYTE *ptr, int value)
{
  ptr[86] = (4 * (value != 0)) & 4 | ptr[86] & 0xFB;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesBackStand@@YAHPAX@Z
// EA  : 0x8255B6F8
// RVA : 0x0055B6F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesBackStand(_BYTE *ptr)
{
  return (ptr[86] & 2) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesBackStand@@YAXPAXH@Z
// EA  : 0x8255B708
// RVA : 0x0055B708
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesBackStand(_BYTE *ptr, int value)
{
  ptr[86] = (2 * (value != 0)) & 2 | ptr[86] & 0xFD;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesOnElevator@@YAHPAX@Z
// EA  : 0x8255B720
// RVA : 0x0055B720
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesOnElevator(_BYTE *ptr)
{
  return ptr[86] & 1;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesOnElevator@@YAXPAXH@Z
// EA  : 0x8255B730
// RVA : 0x0055B730
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesOnElevator(_BYTE *ptr, int value)
{
  ptr[86] = (value != 0) | ptr[86] & 0xFE;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canBeTagged@@YAHPAX@Z
// EA  : 0x8255B748
// RVA : 0x0055B748
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_canBeTagged(unsigned __int8 *ptr)
{
  return ptr[87] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canBeTagged@@YAXPAXH@Z
// EA  : 0x8255B758
// RVA : 0x0055B758
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canBeTagged(_BYTE *ptr, int value)
{
  ptr[87] = ((value != 0) << 7) | ptr[87] & 0x7F;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesCombatLookFocus@@YAHPAX@Z
// EA  : 0x8255B770
// RVA : 0x0055B770
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesCombatLookFocus(_BYTE *ptr)
{
  return (ptr[87] & 0x40) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesCombatLookFocus@@YAXPAXH@Z
// EA  : 0x8255B780
// RVA : 0x0055B780
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesCombatLookFocus(_BYTE *ptr, int value)
{
  ptr[87] = ((value != 0) << 6) & 0x40 | ptr[87] & 0xBF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesCombatLookFocusRelaxed@@YAHPAX@Z
// EA  : 0x8255B798
// RVA : 0x0055B798
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesCombatLookFocusRelaxed(_BYTE *ptr)
{
  return (ptr[87] & 0x20) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesCombatLookFocusRelaxed@@YAXPAXH@Z
// EA  : 0x8255B7A8
// RVA : 0x0055B7A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesCombatLookFocusRelaxed(_BYTE *ptr, int value)
{
  ptr[87] = (32 * (value != 0)) & 0x20 | ptr[87] & 0xDF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesCombat@@YAHPAX@Z
// EA  : 0x8255B7C0
// RVA : 0x0055B7C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesCombat(unsigned __int8 *ptr)
{
  return ptr[196] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesCombat@@YAXPAXH@Z
// EA  : 0x8255B7D0
// RVA : 0x0055B7D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesCombat(_BYTE *ptr, int value)
{
  ptr[196] = ((value != 0) << 7) | ptr[196] & 0x7F;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesScenePoints@@YAHPAX@Z
// EA  : 0x8255B7E8
// RVA : 0x0055B7E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesScenePoints(_BYTE *ptr)
{
  return (ptr[196] & 0x40) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesScenePoints@@YAXPAXH@Z
// EA  : 0x8255B7F8
// RVA : 0x0055B7F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesScenePoints(_BYTE *ptr, int value)
{
  ptr[196] = ((value != 0) << 6) & 0x40 | ptr[196] & 0xBF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesAdvance@@YAHPAX@Z
// EA  : 0x8255B810
// RVA : 0x0055B810
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesAdvance(_BYTE *ptr)
{
  return (ptr[196] & 0x20) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesAdvance@@YAXPAXH@Z
// EA  : 0x8255B820
// RVA : 0x0055B820
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesAdvance(_BYTE *ptr, int value)
{
  ptr[196] = (32 * (value != 0)) & 0x20 | ptr[196] & 0xDF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesFallback@@YAHPAX@Z
// EA  : 0x8255B838
// RVA : 0x0055B838
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesFallback(_BYTE *ptr)
{
  return (ptr[196] & 0x10) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesFallback@@YAXPAXH@Z
// EA  : 0x8255B848
// RVA : 0x0055B848
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesFallback(_BYTE *ptr, int value)
{
  ptr[196] = (16 * (value != 0)) & 0x10 | ptr[196] & 0xEF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesOpenCombat@@YAHPAX@Z
// EA  : 0x8255B860
// RVA : 0x0055B860
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesOpenCombat(_BYTE *ptr)
{
  return (ptr[196] & 8) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesOpenCombat@@YAXPAXH@Z
// EA  : 0x8255B870
// RVA : 0x0055B870
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesOpenCombat(_BYTE *ptr, int value)
{
  ptr[196] = (8 * (value != 0)) & 8 | ptr[196] & 0xF7;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesMelee@@YAHPAX@Z
// EA  : 0x8255B888
// RVA : 0x0055B888
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesMelee(_BYTE *ptr)
{
  return (ptr[196] & 4) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesMelee@@YAXPAXH@Z
// EA  : 0x8255B898
// RVA : 0x0055B898
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesMelee(_BYTE *ptr, int value)
{
  ptr[196] = (4 * (value != 0)) & 4 | ptr[196] & 0xFB;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesSneakUpOnEnemy@@YAHPAX@Z
// EA  : 0x8255B8B0
// RVA : 0x0055B8B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesSneakUpOnEnemy(_BYTE *ptr)
{
  return (ptr[196] & 2) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesSneakUpOnEnemy@@YAXPAXH@Z
// EA  : 0x8255B8C0
// RVA : 0x0055B8C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesSneakUpOnEnemy(_BYTE *ptr, int value)
{
  ptr[196] = (2 * (value != 0)) & 2 | ptr[196] & 0xFD;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesStrafeApproach@@YAHPAX@Z
// EA  : 0x8255B8D8
// RVA : 0x0055B8D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesStrafeApproach(_BYTE *ptr)
{
  return ptr[196] & 1;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesStrafeApproach@@YAXPAXH@Z
// EA  : 0x8255B8E8
// RVA : 0x0055B8E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesStrafeApproach(_BYTE *ptr, int value)
{
  ptr[196] = (value != 0) | ptr[196] & 0xFE;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesTurrets@@YAHPAX@Z
// EA  : 0x8255B900
// RVA : 0x0055B900
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_usesTurrets(unsigned __int8 *ptr)
{
  return ptr[197] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesTurrets@@YAXPAXH@Z
// EA  : 0x8255B910
// RVA : 0x0055B910
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesTurrets(_BYTE *ptr, int value)
{
  ptr[197] = ((value != 0) << 7) | ptr[197] & 0x7F;
}


// ========================================================================
// ?Get_idDeclAIBehavior_dontLeaveTurretsEasily@@YAHPAX@Z
// EA  : 0x8255B928
// RVA : 0x0055B928
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_dontLeaveTurretsEasily(_BYTE *ptr)
{
  return (ptr[197] & 0x40) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_dontLeaveTurretsEasily@@YAXPAXH@Z
// EA  : 0x8255B938
// RVA : 0x0055B938
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_dontLeaveTurretsEasily(_BYTE *ptr, int value)
{
  ptr[197] = ((value != 0) << 6) & 0x40 | ptr[197] & 0xBF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_usesShootIdle@@YAHPAX@Z
// EA  : 0x8255B950
// RVA : 0x0055B950
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_usesShootIdle(_BYTE *ptr)
{
  return (ptr[197] & 0x20) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_usesShootIdle@@YAXPAXH@Z
// EA  : 0x8255B960
// RVA : 0x0055B960
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_usesShootIdle(_BYTE *ptr, int value)
{
  ptr[197] = (32 * (value != 0)) & 0x20 | ptr[197] & 0xDF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_subtitlesInCombat@@YAHPAX@Z
// EA  : 0x8255B978
// RVA : 0x0055B978
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_subtitlesInCombat(_BYTE *ptr)
{
  return (ptr[197] & 0x10) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_subtitlesInCombat@@YAXPAXH@Z
// EA  : 0x8255B988
// RVA : 0x0055B988
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_subtitlesInCombat(_BYTE *ptr, int value)
{
  ptr[197] = (16 * (value != 0)) & 0x10 | ptr[197] & 0xEF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canCharge@@YAHPAX@Z
// EA  : 0x8255B9A0
// RVA : 0x0055B9A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_canCharge(unsigned __int8 *ptr)
{
  return ptr[428] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canCharge@@YAXPAXH@Z
// EA  : 0x8255B9B0
// RVA : 0x0055B9B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canCharge(_BYTE *ptr, int value)
{
  ptr[428] = ((value != 0) << 7) | ptr[428] & 0x7F;
}


// ========================================================================
// ?Get_idDeclAIBehavior_canRetreat@@YAHPAX@Z
// EA  : 0x8255B9C8
// RVA : 0x0055B9C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_canRetreat(_BYTE *ptr)
{
  return (ptr[428] & 0x40) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_canRetreat@@YAXPAXH@Z
// EA  : 0x8255B9D8
// RVA : 0x0055B9D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_canRetreat(_BYTE *ptr, int value)
{
  ptr[428] = ((value != 0) << 6) & 0x40 | ptr[428] & 0xBF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasCombatWalks@@YAHPAX@Z
// EA  : 0x8255B9F0
// RVA : 0x0055B9F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_hasCombatWalks(_BYTE *ptr)
{
  return (ptr[428] & 0x20) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasCombatWalks@@YAXPAXH@Z
// EA  : 0x8255BA00
// RVA : 0x0055BA00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasCombatWalks(_BYTE *ptr, int value)
{
  ptr[428] = (32 * (value != 0)) & 0x20 | ptr[428] & 0xDF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasSyncedWalks@@YAHPAX@Z
// EA  : 0x8255BA18
// RVA : 0x0055BA18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_hasSyncedWalks(_BYTE *ptr)
{
  return (ptr[428] & 0x10) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasSyncedWalks@@YAXPAXH@Z
// EA  : 0x8255BA28
// RVA : 0x0055BA28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasSyncedWalks(_BYTE *ptr, int value)
{
  ptr[428] = (16 * (value != 0)) & 0x10 | ptr[428] & 0xEF;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasWalkInserts@@YAHPAX@Z
// EA  : 0x8255BA40
// RVA : 0x0055BA40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_hasWalkInserts(_BYTE *ptr)
{
  return (ptr[428] & 8) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasWalkInserts@@YAXPAXH@Z
// EA  : 0x8255BA50
// RVA : 0x0055BA50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasWalkInserts(_BYTE *ptr, int value)
{
  ptr[428] = (8 * (value != 0)) & 8 | ptr[428] & 0xF7;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasCombatSprints@@YAHPAX@Z
// EA  : 0x8255BA68
// RVA : 0x0055BA68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_hasCombatSprints(_BYTE *ptr)
{
  return (ptr[428] & 4) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasCombatSprints@@YAXPAXH@Z
// EA  : 0x8255BA78
// RVA : 0x0055BA78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasCombatSprints(_BYTE *ptr, int value)
{
  ptr[428] = (4 * (value != 0)) & 4 | ptr[428] & 0xFB;
}


// ========================================================================
// ?Get_idDeclAIBehavior_has157Turns@@YAHPAX@Z
// EA  : 0x8255BA90
// RVA : 0x0055BA90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idDeclAIBehavior_has157Turns(_BYTE *ptr)
{
  return (ptr[428] & 2) != 0;
}


// ========================================================================
// ?Set_idDeclAIBehavior_has157Turns@@YAXPAXH@Z
// EA  : 0x8255BAA0
// RVA : 0x0055BAA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_has157Turns(_BYTE *ptr, int value)
{
  ptr[428] = (2 * (value != 0)) & 2 | ptr[428] & 0xFD;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasCrouches@@YAHPAX@Z
// EA  : 0x8255BAB8
// RVA : 0x0055BAB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_hasCrouches(_BYTE *ptr)
{
  return ptr[428] & 1;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasCrouches@@YAXPAXH@Z
// EA  : 0x8255BAC8
// RVA : 0x0055BAC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasCrouches(_BYTE *ptr, int value)
{
  ptr[428] = (value != 0) | ptr[428] & 0xFE;
}


// ========================================================================
// ?Get_idDeclAIBehavior_hasBackStandLerps@@YAHPAX@Z
// EA  : 0x8255BAE0
// RVA : 0x0055BAE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idDeclAIBehavior_hasBackStandLerps(unsigned __int8 *ptr)
{
  return ptr[429] >> 7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_hasBackStandLerps@@YAXPAXH@Z
// EA  : 0x8255BAF0
// RVA : 0x0055BAF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_hasBackStandLerps(_BYTE *ptr, int value)
{
  ptr[429] = ((value != 0) << 7) | ptr[429] & 0x7F;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_explodesOnStrike@@YAXPAXH@Z
// EA  : 0x8255BB08
// RVA : 0x0055BB08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_explodesOnStrike(_BYTE *ptr, int value)
{
  ptr[85] = ((value != 0) << 6) & 0x40 | ptr[85] & 0xBF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_deathStopsAmbientSound@@YAXPAXH@Z
// EA  : 0x8255BB20
// RVA : 0x0055BB20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_deathStopsAmbientSound(_BYTE *ptr, int value)
{
  ptr[85] = (32 * (value != 0)) & 0x20 | ptr[85] & 0xDF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_ignoreDeathRagdoll@@YAXPAXH@Z
// EA  : 0x8255BB38
// RVA : 0x0055BB38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_ignoreDeathRagdoll(_BYTE *ptr, int value)
{
  ptr[85] = (16 * (value != 0)) & 0x10 | ptr[85] & 0xEF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idDamageBehaviors_usesExplosionPains@@YAXPAXH@Z
// EA  : 0x8255BB50
// RVA : 0x0055BB50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idDamageBehaviors_usesExplosionPains(_BYTE *ptr, int value)
{
  ptr[85] = (8 * (value != 0)) & 8 | ptr[85] & 0xF7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_useTurningCircles@@YAXPAXH@Z
// EA  : 0x8255BB68
// RVA : 0x0055BB68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_useTurningCircles(_BYTE *ptr, int value)
{
  ptr[85] = (4 * (value != 0)) & 4 | ptr[85] & 0xFB;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_translationIgnoresRemaningFrames@@YAXPAXH@Z
// EA  : 0x8255BB80
// RVA : 0x0055BB80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_translationIgnoresRemaningFrames(_BYTE *ptr, int value)
{
  ptr[40] = ((value != 0) << 7) | ptr[40] & 0x7F;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_restrictRotationDirectionYaw@@YAXPAXH@Z
// EA  : 0x8255BB98
// RVA : 0x0055BB98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_restrictRotationDirectionYaw(_BYTE *ptr, int value)
{
  ptr[40] = ((value != 0) << 6) & 0x40 | ptr[40] & 0xBF;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_restrictRotationDirectionPitch@@YAXPAXH@Z
// EA  : 0x8255BBB0
// RVA : 0x0055BBB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_restrictRotationDirectionPitch(_BYTE *ptr, int value)
{
  ptr[40] = (32 * (value != 0)) & 0x20 | ptr[40] & 0xDF;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idMovementBehaviors_useOldAlignToPoint@@YAXPAXH@Z
// EA  : 0x8255BBC8
// RVA : 0x0055BBC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idMovementBehaviors_useOldAlignToPoint(_BYTE *ptr, int value)
{
  ptr[40] = (16 * (value != 0)) & 0x10 | ptr[40] & 0xEF;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_noReverseRotation@@YAXPAXH@Z
// EA  : 0x8255BBE0
// RVA : 0x0055BBE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_noReverseRotation(_BYTE *ptr, int value)
{
  ptr[40] = (8 * (value != 0)) & 8 | ptr[40] & 0xF7;
}


// ========================================================================
// ?Set_idDeclAIBehavior_idMovementBehaviors_strafeMoveToEntity@@YAXPAXH@Z
// EA  : 0x8255BBF8
// RVA : 0x0055BBF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idDeclAIBehavior_idMovementBehaviors_strafeMoveToEntity(_BYTE *ptr, int value)
{
  ptr[40] = (4 * (value != 0)) & 4 | ptr[40] & 0xFB;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceX@@YAXPAXH@Z
// EA  : 0x8255BC10
// RVA : 0x0055BC10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceX(_BYTE *ptr, int value)
{
  ptr[40] = (2 * (value != 0)) & 2 | ptr[40] & 0xFD;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceY@@YAXPAXH@Z
// EA  : 0x8255BC28
// RVA : 0x0055BC28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceY(_BYTE *ptr, int value)
{
  ptr[40] = (value != 0) | ptr[40] & 0xFE;
}


// ========================================================================
// ?Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceZ@@YAXPAXH@Z
// EA  : 0x8255BC40
// RVA : 0x0055BC40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_animDeltaCorrection_t_input_t_lerpOnlyModelSpaceZ(_BYTE *ptr, int value)
{
  ptr[41] = ((value != 0) << 7) | ptr[41] & 0x7F;
}


// ========================================================================
// ?Get_weaponStatsTag_t_entitynum@@YAHPAX@Z
// EA  : 0x8255BC58
// RVA : 0x0055BC58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_weaponStatsTag_t_entitynum(_DWORD *ptr)
{
  return *ptr >> 26;
}


// ========================================================================
// ?Set_weaponStatsTag_t_entitynum@@YAXPAXH@Z
// EA  : 0x8255BC68
// RVA : 0x0055BC68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_weaponStatsTag_t_entitynum(int *ptr, int value)
{
  *ptr = (value << 26) | *ptr & 0x3FFFFFF;
}


// ========================================================================
// ?Get_weaponStatsTag_t_shotnum@@YAHPAX@Z
// EA  : 0x8255BC78
// RVA : 0x0055BC78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_weaponStatsTag_t_shotnum(_DWORD *ptr)
{
  return (*ptr >> 22) & 0xF;
}


// ========================================================================
// ?Set_weaponStatsTag_t_shotnum@@YAXPAXH@Z
// EA  : 0x8255BC88
// RVA : 0x0055BC88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_weaponStatsTag_t_shotnum(unsigned int *ptr, int value)
{
  *ptr = (value << 22) & 0x3C00000 | *ptr & 0xFC3FFFFF;
}


// ========================================================================
// ?Get_weaponStatsTag_t_gametime@@YAHPAX@Z
// EA  : 0x8255BC98
// RVA : 0x0055BC98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_weaponStatsTag_t_gametime(_DWORD *ptr)
{
  return *ptr & 0x3FFFFF;
}


// ========================================================================
// ?Set_weaponStatsTag_t_gametime@@YAXPAXH@Z
// EA  : 0x8255BCA8
// RVA : 0x0055BCA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_weaponStatsTag_t_gametime(unsigned int *ptr, int value)
{
  *ptr = *ptr & 0xFFC00000 | value & 0x3FFFFF;
}


// ========================================================================
// ?Get_idWeapon_canEjectFromBothSides@@YAHPAX@Z
// EA  : 0x8255BCB8
// RVA : 0x0055BCB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idWeapon_canEjectFromBothSides(unsigned __int8 *ptr)
{
  return ptr[452] >> 7;
}


// ========================================================================
// ?Set_idWeapon_canEjectFromBothSides@@YAXPAXH@Z
// EA  : 0x8255BCC8
// RVA : 0x0055BCC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_canEjectFromBothSides(_BYTE *ptr, int value)
{
  ptr[452] = ((value != 0) << 7) | ptr[452] & 0x7F;
}


// ========================================================================
// ?Get_idWeapon_ejectedFromLeftSide@@YAHPAX@Z
// EA  : 0x8255BCE0
// RVA : 0x0055BCE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_ejectedFromLeftSide(_BYTE *ptr)
{
  return (ptr[452] & 0x40) != 0;
}


// ========================================================================
// ?Set_idWeapon_ejectedFromLeftSide@@YAXPAXH@Z
// EA  : 0x8255BCF0
// RVA : 0x0055BCF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_ejectedFromLeftSide(_BYTE *ptr, int value)
{
  ptr[452] = ((value != 0) << 6) & 0x40 | ptr[452] & 0xBF;
}


// ========================================================================
// ?Get_idWeapon_silenced@@YAHPAX@Z
// EA  : 0x8255BD08
// RVA : 0x0055BD08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_silenced(_BYTE *ptr)
{
  return (ptr[452] & 0x20) != 0;
}


// ========================================================================
// ?Set_idWeapon_silenced@@YAXPAXH@Z
// EA  : 0x8255BD18
// RVA : 0x0055BD18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_silenced(_BYTE *ptr, int value)
{
  ptr[452] = (32 * (value != 0)) & 0x20 | ptr[452] & 0xDF;
}


// ========================================================================
// ?Get_idWeapon_hasScopeUpgrade@@YAHPAX@Z
// EA  : 0x8255BD30
// RVA : 0x0055BD30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_hasScopeUpgrade(_BYTE *ptr)
{
  return (ptr[452] & 0x10) != 0;
}


// ========================================================================
// ?Set_idWeapon_hasScopeUpgrade@@YAXPAXH@Z
// EA  : 0x8255BD40
// RVA : 0x0055BD40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_hasScopeUpgrade(_BYTE *ptr, int value)
{
  ptr[452] = (16 * (value != 0)) & 0x10 | ptr[452] & 0xEF;
}


// ========================================================================
// ?Get_idWeapon_isZoomed@@YAHPAX@Z
// EA  : 0x8255BD58
// RVA : 0x0055BD58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_isZoomed(_BYTE *ptr)
{
  return (ptr[452] & 8) != 0;
}


// ========================================================================
// ?Set_idWeapon_isZoomed@@YAXPAXH@Z
// EA  : 0x8255BD68
// RVA : 0x0055BD68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_isZoomed(_BYTE *ptr, int value)
{
  ptr[452] = (8 * (value != 0)) & 8 | ptr[452] & 0xF7;
}


// ========================================================================
// ?Get_idWeapon_hasMagazineUpgrade@@YAHPAX@Z
// EA  : 0x8255BD80
// RVA : 0x0055BD80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_hasMagazineUpgrade(_BYTE *ptr)
{
  return (ptr[452] & 4) != 0;
}


// ========================================================================
// ?Set_idWeapon_hasMagazineUpgrade@@YAXPAXH@Z
// EA  : 0x8255BD90
// RVA : 0x0055BD90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_hasMagazineUpgrade(_BYTE *ptr, int value)
{
  ptr[452] = (4 * (value != 0)) & 4 | ptr[452] & 0xFB;
}


// ========================================================================
// ?Get_idWeapon_hasLaserUpgrade@@YAHPAX@Z
// EA  : 0x8255BDA8
// RVA : 0x0055BDA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_hasLaserUpgrade(_BYTE *ptr)
{
  return (ptr[452] & 2) != 0;
}


// ========================================================================
// ?Set_idWeapon_hasLaserUpgrade@@YAXPAXH@Z
// EA  : 0x8255BDB8
// RVA : 0x0055BDB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_hasLaserUpgrade(_BYTE *ptr, int value)
{
  ptr[452] = (2 * (value != 0)) & 2 | ptr[452] & 0xFD;
}


// ========================================================================
// ?Get_idWeapon_hasDualWieldUpgrade@@YAHPAX@Z
// EA  : 0x8255BDD0
// RVA : 0x0055BDD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idWeapon_hasDualWieldUpgrade(_BYTE *ptr)
{
  return ptr[452] & 1;
}


// ========================================================================
// ?Set_idWeapon_hasDualWieldUpgrade@@YAXPAXH@Z
// EA  : 0x8255BDE0
// RVA : 0x0055BDE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_hasDualWieldUpgrade(_BYTE *ptr, int value)
{
  ptr[452] = (value != 0) | ptr[452] & 0xFE;
}


// ========================================================================
// ?Get_idWeapon_weaponIsDualWieldable@@YAHPAX@Z
// EA  : 0x8255BDF8
// RVA : 0x0055BDF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idWeapon_weaponIsDualWieldable(unsigned __int8 *ptr)
{
  return ptr[453] >> 7;
}


// ========================================================================
// ?Set_idWeapon_weaponIsDualWieldable@@YAXPAXH@Z
// EA  : 0x8255BE08
// RVA : 0x0055BE08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_weaponIsDualWieldable(_BYTE *ptr, int value)
{
  ptr[453] = ((value != 0) << 7) | ptr[453] & 0x7F;
}


// ========================================================================
// ?Get_idWeapon_hasWeaponModeUpgrade@@YAHPAX@Z
// EA  : 0x8255BE20
// RVA : 0x0055BE20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_hasWeaponModeUpgrade(_BYTE *ptr)
{
  return (ptr[453] & 0x40) != 0;
}


// ========================================================================
// ?Set_idWeapon_hasWeaponModeUpgrade@@YAXPAXH@Z
// EA  : 0x8255BE30
// RVA : 0x0055BE30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_hasWeaponModeUpgrade(_BYTE *ptr, int value)
{
  ptr[453] = ((value != 0) << 6) & 0x40 | ptr[453] & 0xBF;
}


// ========================================================================
// ?Get_idWeapon_isBreechOpen@@YAHPAX@Z
// EA  : 0x8255BE48
// RVA : 0x0055BE48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idWeapon_isBreechOpen(_BYTE *ptr)
{
  return (ptr[453] & 0x20) != 0;
}


// ========================================================================
// ?Set_idWeapon_isBreechOpen@@YAXPAXH@Z
// EA  : 0x8255BE58
// RVA : 0x0055BE58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_isBreechOpen(_BYTE *ptr, int value)
{
  ptr[453] = (32 * (value != 0)) & 0x20 | ptr[453] & 0xDF;
}


// ========================================================================
// ?Set_idWeapon_shouldSwitchWeaponWhenOutOfAmmo@@YAXPAXH@Z
// EA  : 0x8255BE70
// RVA : 0x0055BE70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idWeapon_shouldSwitchWeaponWhenOutOfAmmo(_BYTE *ptr, int value)
{
  ptr[453] = (16 * (value != 0)) & 0x10 | ptr[453] & 0xEF;
}


// ========================================================================
// ?Get_idFireParms_simulateProjectiles@@YAHPAX@Z
// EA  : 0x8255BE88
// RVA : 0x0055BE88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idFireParms_simulateProjectiles(unsigned __int8 *ptr)
{
  return ptr[128] >> 7;
}


// ========================================================================
// ?Set_idFireParms_simulateProjectiles@@YAXPAXH@Z
// EA  : 0x8255BE98
// RVA : 0x0055BE98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_simulateProjectiles(_BYTE *ptr, int value)
{
  ptr[128] = ((value != 0) << 7) | ptr[128] & 0x7F;
}


// ========================================================================
// ?Get_idFireParms_silenced@@YAHPAX@Z
// EA  : 0x8255BEB0
// RVA : 0x0055BEB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_silenced(_BYTE *ptr)
{
  return (ptr[128] & 0x40) != 0;
}


// ========================================================================
// ?Set_idFireParms_silenced@@YAXPAXH@Z
// EA  : 0x8255BEC0
// RVA : 0x0055BEC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_silenced(_BYTE *ptr, int value)
{
  ptr[128] = ((value != 0) << 6) & 0x40 | ptr[128] & 0xBF;
}


// ========================================================================
// ?Get_idFireParms_freeAmmo@@YAHPAX@Z
// EA  : 0x8255BED8
// RVA : 0x0055BED8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_freeAmmo(_BYTE *ptr)
{
  return (ptr[128] & 0x20) != 0;
}


// ========================================================================
// ?Set_idFireParms_freeAmmo@@YAXPAXH@Z
// EA  : 0x8255BEE8
// RVA : 0x0055BEE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_freeAmmo(_BYTE *ptr, int value)
{
  ptr[128] = (32 * (value != 0)) & 0x20 | ptr[128] & 0xDF;
}


// ========================================================================
// ?Get_idFireParms_fromPlayer@@YAHPAX@Z
// EA  : 0x8255BF00
// RVA : 0x0055BF00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_fromPlayer(_BYTE *ptr)
{
  return (ptr[128] & 0x10) != 0;
}


// ========================================================================
// ?Set_idFireParms_fromPlayer@@YAXPAXH@Z
// EA  : 0x8255BF10
// RVA : 0x0055BF10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_fromPlayer(_BYTE *ptr, int value)
{
  ptr[128] = (16 * (value != 0)) & 0x10 | ptr[128] & 0xEF;
}


// ========================================================================
// ?Get_idFireParms_alwaysTracer@@YAHPAX@Z
// EA  : 0x8255BF28
// RVA : 0x0055BF28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_alwaysTracer(_BYTE *ptr)
{
  return (ptr[128] & 8) != 0;
}


// ========================================================================
// ?Set_idFireParms_alwaysTracer@@YAXPAXH@Z
// EA  : 0x8255BF38
// RVA : 0x0055BF38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_alwaysTracer(_BYTE *ptr, int value)
{
  ptr[128] = (8 * (value != 0)) & 8 | ptr[128] & 0xF7;
}


// ========================================================================
// ?Get_idFireParms_useTargetPos@@YAHPAX@Z
// EA  : 0x8255BF50
// RVA : 0x0055BF50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_useTargetPos(_BYTE *ptr)
{
  return (ptr[128] & 4) != 0;
}


// ========================================================================
// ?Set_idFireParms_useTargetPos@@YAXPAXH@Z
// EA  : 0x8255BF60
// RVA : 0x0055BF60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_useTargetPos(_BYTE *ptr, int value)
{
  ptr[128] = (4 * (value != 0)) & 4 | ptr[128] & 0xFB;
}


// ========================================================================
// ?Get_idFireParms_forceNoSpread@@YAHPAX@Z
// EA  : 0x8255BF78
// RVA : 0x0055BF78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_forceNoSpread(_BYTE *ptr)
{
  return (ptr[128] & 2) != 0;
}


// ========================================================================
// ?Set_idFireParms_forceNoSpread@@YAXPAXH@Z
// EA  : 0x8255BF88
// RVA : 0x0055BF88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_forceNoSpread(_BYTE *ptr, int value)
{
  ptr[128] = (2 * (value != 0)) & 2 | ptr[128] & 0xFD;
}


// ========================================================================
// ?Get_idFireParms_noDecals@@YAHPAX@Z
// EA  : 0x8255BFA0
// RVA : 0x0055BFA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idFireParms_noDecals(_BYTE *ptr)
{
  return ptr[128] & 1;
}


// ========================================================================
// ?Set_idFireParms_noDecals@@YAXPAXH@Z
// EA  : 0x8255BFB0
// RVA : 0x0055BFB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_noDecals(_BYTE *ptr, int value)
{
  ptr[128] = (value != 0) | ptr[128] & 0xFE;
}


// ========================================================================
// ?Get_idFireParms_noDamage@@YAHPAX@Z
// EA  : 0x8255BFC8
// RVA : 0x0055BFC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idFireParms_noDamage(unsigned __int8 *ptr)
{
  return ptr[129] >> 7;
}


// ========================================================================
// ?Set_idFireParms_noDamage@@YAXPAXH@Z
// EA  : 0x8255BFD8
// RVA : 0x0055BFD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_noDamage(_BYTE *ptr, int value)
{
  ptr[129] = ((value != 0) << 7) | ptr[129] & 0x7F;
}


// ========================================================================
// ?Get_idFireParms_fromWithinVehicle@@YAHPAX@Z
// EA  : 0x8255BFF0
// RVA : 0x0055BFF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_fromWithinVehicle(_BYTE *ptr)
{
  return (ptr[129] & 0x40) != 0;
}


// ========================================================================
// ?Set_idFireParms_fromWithinVehicle@@YAXPAXH@Z
// EA  : 0x8255C000
// RVA : 0x0055C000
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_fromWithinVehicle(_BYTE *ptr, int value)
{
  ptr[129] = ((value != 0) << 6) & 0x40 | ptr[129] & 0xBF;
}


// ========================================================================
// ?Get_idFireParms_secondaryAmmo@@YAHPAX@Z
// EA  : 0x8255C018
// RVA : 0x0055C018
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idFireParms_secondaryAmmo(_BYTE *ptr)
{
  return (ptr[129] & 0x20) != 0;
}


// ========================================================================
// ?Set_idFireParms_secondaryAmmo@@YAXPAXH@Z
// EA  : 0x8255C028
// RVA : 0x0055C028
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idFireParms_secondaryAmmo(_BYTE *ptr, int value)
{
  ptr[129] = (32 * (value != 0)) & 0x20 | ptr[129] & 0xDF;
}


// ========================================================================
// ?Get_idPresentablePlayer_isDead@@YAHPAX@Z
// EA  : 0x8255C040
// RVA : 0x0055C040
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPresentablePlayer_isDead(unsigned __int8 *ptr)
{
  return ptr[47032] >> 7;
}


// ========================================================================
// ?Set_idPresentablePlayer_isDead@@YAXPAXH@Z
// EA  : 0x8255C058
// RVA : 0x0055C058
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_isDead(_BYTE *ptr, int value)
{
  ptr[47032] = ((value != 0) << 7) | ptr[47032] & 0x7F;
}


// ========================================================================
// ?Set_idPresentablePlayer_zoomedIn@@YAXPAXH@Z
// EA  : 0x8255C078
// RVA : 0x0055C078
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_zoomedIn(_BYTE *ptr, int value)
{
  ptr[47032] = ((value != 0) << 6) & 0x40 | ptr[47032] & 0xBF;
}


// ========================================================================
// ?Get_idPresentablePlayer_noClip@@YAHPAX@Z
// EA  : 0x8255C098
// RVA : 0x0055C098
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_noClip(_BYTE *ptr)
{
  return (ptr[47032] & 0x20) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_noClip@@YAXPAXH@Z
// EA  : 0x8255C0B0
// RVA : 0x0055C0B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_noClip(_BYTE *ptr, int value)
{
  ptr[47032] = (32 * (value != 0)) & 0x20 | ptr[47032] & 0xDF;
}


// ========================================================================
// ?Get_idPresentablePlayer_inhibited@@YAHPAX@Z
// EA  : 0x8255C0D0
// RVA : 0x0055C0D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_inhibited(_BYTE *ptr)
{
  return (ptr[47032] & 0x10) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_inhibited@@YAXPAXH@Z
// EA  : 0x8255C0E8
// RVA : 0x0055C0E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_inhibited(_BYTE *ptr, int value)
{
  ptr[47032] = (16 * (value != 0)) & 0x10 | ptr[47032] & 0xEF;
}


// ========================================================================
// ?Get_idPresentablePlayer_spectating@@YAHPAX@Z
// EA  : 0x8255C108
// RVA : 0x0055C108
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_spectating(_BYTE *ptr)
{
  return (ptr[47032] & 8) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_spectating@@YAXPAXH@Z
// EA  : 0x8255C120
// RVA : 0x0055C120
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_spectating(_BYTE *ptr, int value)
{
  ptr[47032] = (8 * (value != 0)) & 8 | ptr[47032] & 0xF7;
}


// ========================================================================
// ?Get_idPresentablePlayer_incapacitated@@YAHPAX@Z
// EA  : 0x8255C140
// RVA : 0x0055C140
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_incapacitated(_BYTE *ptr)
{
  return (ptr[47032] & 4) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_incapacitated@@YAXPAXH@Z
// EA  : 0x8255C158
// RVA : 0x0055C158
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_incapacitated(_BYTE *ptr, int value)
{
  ptr[47032] = (4 * (value != 0)) & 4 | ptr[47032] & 0xFB;
}


// ========================================================================
// ?Get_idPresentablePlayer_hasQuad@@YAHPAX@Z
// EA  : 0x8255C178
// RVA : 0x0055C178
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_hasQuad(_BYTE *ptr)
{
  return (ptr[47032] & 2) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_hasQuad@@YAXPAXH@Z
// EA  : 0x8255C190
// RVA : 0x0055C190
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_hasQuad(_BYTE *ptr, int value)
{
  ptr[47032] = (2 * (value != 0)) & 2 | ptr[47032] & 0xFD;
}


// ========================================================================
// ?Get_idPresentablePlayer_hasOddball@@YAHPAX@Z
// EA  : 0x8255C1B0
// RVA : 0x0055C1B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPresentablePlayer_hasOddball(_BYTE *ptr)
{
  return ptr[47032] & 1;
}


// ========================================================================
// ?Set_idPresentablePlayer_hasOddball@@YAXPAXH@Z
// EA  : 0x8255C1C8
// RVA : 0x0055C1C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_hasOddball(_BYTE *ptr, int value)
{
  ptr[47032] = (value != 0) | ptr[47032] & 0xFE;
}


// ========================================================================
// ?Get_idPresentablePlayer_isBully@@YAHPAX@Z
// EA  : 0x8255C1E8
// RVA : 0x0055C1E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPresentablePlayer_isBully(unsigned __int8 *ptr)
{
  return ptr[47033] >> 7;
}


// ========================================================================
// ?Set_idPresentablePlayer_isBully@@YAXPAXH@Z
// EA  : 0x8255C200
// RVA : 0x0055C200
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_isBully(_BYTE *ptr, int value)
{
  ptr[47033] = ((value != 0) << 7) | ptr[47033] & 0x7F;
}


// ========================================================================
// ?Get_idPresentablePlayer_canRespawn@@YAHPAX@Z
// EA  : 0x8255C220
// RVA : 0x0055C220
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_canRespawn(_BYTE *ptr)
{
  return (ptr[47033] & 0x40) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_canRespawn@@YAXPAXH@Z
// EA  : 0x8255C238
// RVA : 0x0055C238
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_canRespawn(_BYTE *ptr, int value)
{
  ptr[47033] = ((value != 0) << 6) & 0x40 | ptr[47033] & 0xBF;
}


// ========================================================================
// ?Get_idPresentablePlayer_showDeadBody@@YAHPAX@Z
// EA  : 0x8255C258
// RVA : 0x0055C258
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_showDeadBody(_BYTE *ptr)
{
  return (ptr[47033] & 0x20) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_showDeadBody@@YAXPAXH@Z
// EA  : 0x8255C270
// RVA : 0x0055C270
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_showDeadBody(_BYTE *ptr, int value)
{
  ptr[47033] = (32 * (value != 0)) & 0x20 | ptr[47033] & 0xDF;
}


// ========================================================================
// ?Get_idPresentablePlayer_isAFK@@YAHPAX@Z
// EA  : 0x8255C290
// RVA : 0x0055C290
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_isAFK(_BYTE *ptr)
{
  return (ptr[47033] & 0x10) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_isAFK@@YAXPAXH@Z
// EA  : 0x8255C2A8
// RVA : 0x0055C2A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_isAFK(_BYTE *ptr, int value)
{
  ptr[47033] = (16 * (value != 0)) & 0x10 | ptr[47033] & 0xEF;
}


// ========================================================================
// ?Get_idPresentablePlayer_inhibitFireControl@@YAHPAX@Z
// EA  : 0x8255C2C8
// RVA : 0x0055C2C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_inhibitFireControl(_BYTE *ptr)
{
  return (ptr[47033] & 8) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_inhibitFireControl@@YAXPAXH@Z
// EA  : 0x8255C2E0
// RVA : 0x0055C2E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_inhibitFireControl(_BYTE *ptr, int value)
{
  ptr[47033] = (8 * (value != 0)) & 8 | ptr[47033] & 0xF7;
}


// ========================================================================
// ?Get_idPresentablePlayer_perfectMovement@@YAHPAX@Z
// EA  : 0x8255C300
// RVA : 0x0055C300
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_perfectMovement(_BYTE *ptr)
{
  return (ptr[47033] & 4) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_perfectMovement@@YAXPAXH@Z
// EA  : 0x8255C318
// RVA : 0x0055C318
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_perfectMovement(_BYTE *ptr, int value)
{
  ptr[47033] = (4 * (value != 0)) & 4 | ptr[47033] & 0xFB;
}


// ========================================================================
// ?Get_idPresentablePlayer_restrictedGamePlay@@YAHPAX@Z
// EA  : 0x8255C338
// RVA : 0x0055C338
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_restrictedGamePlay(_BYTE *ptr)
{
  return (ptr[47033] & 2) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_restrictedGamePlay@@YAXPAXH@Z
// EA  : 0x8255C350
// RVA : 0x0055C350
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_restrictedGamePlay(_BYTE *ptr, int value)
{
  ptr[47033] = (2 * (value != 0)) & 2 | ptr[47033] & 0xFD;
}


// ========================================================================
// ?Get_idPresentablePlayer_restrictedGamePlayCanRun@@YAHPAX@Z
// EA  : 0x8255C370
// RVA : 0x0055C370
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPresentablePlayer_restrictedGamePlayCanRun(_BYTE *ptr)
{
  return ptr[47033] & 1;
}


// ========================================================================
// ?Set_idPresentablePlayer_restrictedGamePlayCanRun@@YAXPAXH@Z
// EA  : 0x8255C388
// RVA : 0x0055C388
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_restrictedGamePlayCanRun(_BYTE *ptr, int value)
{
  ptr[47033] = (value != 0) | ptr[47033] & 0xFE;
}


// ========================================================================
// ?Get_idPresentablePlayer_inhibitRaiseWeapon@@YAHPAX@Z
// EA  : 0x8255C3A8
// RVA : 0x0055C3A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idPresentablePlayer_inhibitRaiseWeapon(unsigned __int8 *ptr)
{
  return ptr[47034] >> 7;
}


// ========================================================================
// ?Set_idPresentablePlayer_inhibitRaiseWeapon@@YAXPAXH@Z
// EA  : 0x8255C3C0
// RVA : 0x0055C3C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_inhibitRaiseWeapon(_BYTE *ptr, int value)
{
  ptr[47034] = ((value != 0) << 7) | ptr[47034] & 0x7F;
}


// ========================================================================
// ?Get_idPresentablePlayer_inhibitChangeWeapon@@YAHPAX@Z
// EA  : 0x8255C3E0
// RVA : 0x0055C3E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_inhibitChangeWeapon(_BYTE *ptr)
{
  return (ptr[47034] & 0x40) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_inhibitChangeWeapon@@YAXPAXH@Z
// EA  : 0x8255C3F8
// RVA : 0x0055C3F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_inhibitChangeWeapon(_BYTE *ptr, int value)
{
  ptr[47034] = ((value != 0) << 6) & 0x40 | ptr[47034] & 0xBF;
}


// ========================================================================
// ?Get_idPresentablePlayer_forceSoftLanding@@YAHPAX@Z
// EA  : 0x8255C418
// RVA : 0x0055C418
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_forceSoftLanding(_BYTE *ptr)
{
  return (ptr[47034] & 0x20) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_forceSoftLanding@@YAXPAXH@Z
// EA  : 0x8255C430
// RVA : 0x0055C430
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_forceSoftLanding(_BYTE *ptr, int value)
{
  ptr[47034] = (32 * (value != 0)) & 0x20 | ptr[47034] & 0xDF;
}


// ========================================================================
// ?Get_idPresentablePlayer_forceIgnoreLanding@@YAHPAX@Z
// EA  : 0x8255C450
// RVA : 0x0055C450
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idPresentablePlayer_forceIgnoreLanding(_BYTE *ptr)
{
  return (ptr[47034] & 0x10) != 0;
}


// ========================================================================
// ?Set_idPresentablePlayer_forceIgnoreLanding@@YAXPAXH@Z
// EA  : 0x8255C468
// RVA : 0x0055C468
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idPresentablePlayer_forceIgnoreLanding(_BYTE *ptr, int value)
{
  ptr[47034] = (16 * (value != 0)) & 0x10 | ptr[47034] & 0xEF;
}


// ========================================================================
// ?Get_idProp_Moveable_uniqueInWorld@@YAHPAX@Z
// EA  : 0x8255C488
// RVA : 0x0055C488
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idProp_Moveable_uniqueInWorld(unsigned __int8 *ptr)
{
  return ptr[5296] >> 7;
}


// ========================================================================
// ?Set_idProp_Moveable_uniqueInWorld@@YAXPAXH@Z
// EA  : 0x8255C498
// RVA : 0x0055C498
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_uniqueInWorld(_BYTE *ptr, int value)
{
  ptr[5296] = ((value != 0) << 7) | ptr[5296] & 0x7F;
}


// ========================================================================
// ?Get_idProp_Moveable_uniqueInventoryItem@@YAHPAX@Z
// EA  : 0x8255C4B0
// RVA : 0x0055C4B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_uniqueInventoryItem(_BYTE *ptr)
{
  return (ptr[5296] & 0x40) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_uniqueInventoryItem@@YAXPAXH@Z
// EA  : 0x8255C4C0
// RVA : 0x0055C4C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_uniqueInventoryItem(_BYTE *ptr, int value)
{
  ptr[5296] = ((value != 0) << 6) & 0x40 | ptr[5296] & 0xBF;
}


// ========================================================================
// ?Get_idProp_Moveable_hasCheckedUniqueInWorld@@YAHPAX@Z
// EA  : 0x8255C4D8
// RVA : 0x0055C4D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_hasCheckedUniqueInWorld(_BYTE *ptr)
{
  return (ptr[5296] & 0x20) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_hasCheckedUniqueInWorld@@YAXPAXH@Z
// EA  : 0x8255C4E8
// RVA : 0x0055C4E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_hasCheckedUniqueInWorld(_BYTE *ptr, int value)
{
  ptr[5296] = (32 * (value != 0)) & 0x20 | ptr[5296] & 0xDF;
}


// ========================================================================
// ?Get_idProp_Moveable_barrelCollision@@YAHPAX@Z
// EA  : 0x8255C500
// RVA : 0x0055C500
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_barrelCollision(_BYTE *ptr)
{
  return (ptr[5296] & 0x10) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_barrelCollision@@YAXPAXH@Z
// EA  : 0x8255C510
// RVA : 0x0055C510
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_barrelCollision(_BYTE *ptr, int value)
{
  ptr[5296] = (16 * (value != 0)) & 0x10 | ptr[5296] & 0xEF;
}


// ========================================================================
// ?Get_idProp_Moveable_allowStep@@YAHPAX@Z
// EA  : 0x8255C528
// RVA : 0x0055C528
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_allowStep(_BYTE *ptr)
{
  return (ptr[5296] & 8) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_allowStep@@YAXPAXH@Z
// EA  : 0x8255C538
// RVA : 0x0055C538
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_allowStep(_BYTE *ptr, int value)
{
  ptr[5296] = (8 * (value != 0)) & 8 | ptr[5296] & 0xF7;
}


// ========================================================================
// ?Get_idProp_Moveable_actorPushable@@YAHPAX@Z
// EA  : 0x8255C550
// RVA : 0x0055C550
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_actorPushable(_BYTE *ptr)
{
  return (ptr[5296] & 4) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_actorPushable@@YAXPAXH@Z
// EA  : 0x8255C560
// RVA : 0x0055C560
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_actorPushable(_BYTE *ptr, int value)
{
  ptr[5296] = (4 * (value != 0)) & 4 | ptr[5296] & 0xFB;
}


// ========================================================================
// ?Get_idProp_Moveable_vehiclePushable@@YAHPAX@Z
// EA  : 0x8255C578
// RVA : 0x0055C578
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_vehiclePushable(_BYTE *ptr)
{
  return (ptr[5296] & 2) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_vehiclePushable@@YAXPAXH@Z
// EA  : 0x8255C588
// RVA : 0x0055C588
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_vehiclePushable(_BYTE *ptr, int value)
{
  ptr[5296] = (2 * (value != 0)) & 2 | ptr[5296] & 0xFD;
}


// ========================================================================
// ?Get_idProp_Moveable_dropToFloor@@YAHPAX@Z
// EA  : 0x8255C5A0
// RVA : 0x0055C5A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idProp_Moveable_dropToFloor(_BYTE *ptr)
{
  return ptr[5296] & 1;
}


// ========================================================================
// ?Set_idProp_Moveable_dropToFloor@@YAXPAXH@Z
// EA  : 0x8255C5B0
// RVA : 0x0055C5B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_dropToFloor(_BYTE *ptr, int value)
{
  ptr[5296] = (value != 0) | ptr[5296] & 0xFE;
}


// ========================================================================
// ?Get_idProp_Moveable_triggerOnDamage@@YAHPAX@Z
// EA  : 0x8255C5C8
// RVA : 0x0055C5C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idProp_Moveable_triggerOnDamage(unsigned __int8 *ptr)
{
  return ptr[5297] >> 7;
}


// ========================================================================
// ?Set_idProp_Moveable_triggerOnDamage@@YAXPAXH@Z
// EA  : 0x8255C5D8
// RVA : 0x0055C5D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_triggerOnDamage(_BYTE *ptr, int value)
{
  ptr[5297] = ((value != 0) << 7) | ptr[5297] & 0x7F;
}


// ========================================================================
// ?Get_idProp_Moveable_destroyOnDamage@@YAHPAX@Z
// EA  : 0x8255C5F0
// RVA : 0x0055C5F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_destroyOnDamage(_BYTE *ptr)
{
  return (ptr[5297] & 0x40) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_destroyOnDamage@@YAXPAXH@Z
// EA  : 0x8255C600
// RVA : 0x0055C600
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_destroyOnDamage(_BYTE *ptr, int value)
{
  ptr[5297] = ((value != 0) << 6) & 0x40 | ptr[5297] & 0xBF;
}


// ========================================================================
// ?Get_idProp_Moveable_removeWhenDroped@@YAHPAX@Z
// EA  : 0x8255C618
// RVA : 0x0055C618
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_removeWhenDroped(_BYTE *ptr)
{
  return (ptr[5297] & 0x20) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_removeWhenDroped@@YAXPAXH@Z
// EA  : 0x8255C628
// RVA : 0x0055C628
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_removeWhenDroped(_BYTE *ptr, int value)
{
  ptr[5297] = (32 * (value != 0)) & 0x20 | ptr[5297] & 0xDF;
}


// ========================================================================
// ?Get_idProp_Moveable_skipThink@@YAHPAX@Z
// EA  : 0x8255C640
// RVA : 0x0055C640
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_skipThink(_BYTE *ptr)
{
  return (ptr[5297] & 0x10) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_skipThink@@YAXPAXH@Z
// EA  : 0x8255C650
// RVA : 0x0055C650
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_skipThink(_BYTE *ptr, int value)
{
  ptr[5297] = (16 * (value != 0)) & 0x10 | ptr[5297] & 0xEF;
}


// ========================================================================
// ?Get_idProp_Moveable_impulseOnActivate@@YAHPAX@Z
// EA  : 0x8255C668
// RVA : 0x0055C668
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_Moveable_impulseOnActivate(_BYTE *ptr)
{
  return (ptr[5297] & 8) != 0;
}


// ========================================================================
// ?Set_idProp_Moveable_impulseOnActivate@@YAXPAXH@Z
// EA  : 0x8255C678
// RVA : 0x0055C678
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_Moveable_impulseOnActivate(_BYTE *ptr, int value)
{
  ptr[5297] = (8 * (value != 0)) & 8 | ptr[5297] & 0xF7;
}


// ========================================================================
// ?Get_idHands_deleteWeaponOnBringDown@@YAHPAX@Z
// EA  : 0x8255C690
// RVA : 0x0055C690
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idHands_deleteWeaponOnBringDown(unsigned __int8 *ptr)
{
  return ptr[7912] >> 7;
}


// ========================================================================
// ?Set_idHands_deleteWeaponOnBringDown@@YAXPAXH@Z
// EA  : 0x8255C6A0
// RVA : 0x0055C6A0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_deleteWeaponOnBringDown(_BYTE *ptr, int value)
{
  ptr[7912] = ((value != 0) << 7) | ptr[7912] & 0x7F;
}


// ========================================================================
// ?Get_idHands_lastShotRight@@YAHPAX@Z
// EA  : 0x8255C6B8
// RVA : 0x0055C6B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idHands_lastShotRight(_BYTE *ptr)
{
  return (ptr[7912] & 0x40) != 0;
}


// ========================================================================
// ?Set_idHands_lastShotRight@@YAXPAXH@Z
// EA  : 0x8255C6C8
// RVA : 0x0055C6C8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_lastShotRight(_BYTE *ptr, int value)
{
  ptr[7912] = ((value != 0) << 6) & 0x40 | ptr[7912] & 0xBF;
}


// ========================================================================
// ?Get_idHands_lastShotLeft@@YAHPAX@Z
// EA  : 0x8255C6E0
// RVA : 0x0055C6E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idHands_lastShotLeft(_BYTE *ptr)
{
  return (ptr[7912] & 0x20) != 0;
}


// ========================================================================
// ?Set_idHands_lastShotLeft@@YAXPAXH@Z
// EA  : 0x8255C6F0
// RVA : 0x0055C6F0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_lastShotLeft(_BYTE *ptr, int value)
{
  ptr[7912] = (32 * (value != 0)) & 0x20 | ptr[7912] & 0xDF;
}


// ========================================================================
// ?Get_idHands_isIdle@@YAHPAX@Z
// EA  : 0x8255C708
// RVA : 0x0055C708
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idHands_isIdle(_BYTE *ptr)
{
  return (ptr[7912] & 0x10) != 0;
}


// ========================================================================
// ?Set_idHands_isIdle@@YAXPAXH@Z
// EA  : 0x8255C718
// RVA : 0x0055C718
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_isIdle(_BYTE *ptr, int value)
{
  ptr[7912] = (16 * (value != 0)) & 0x10 | ptr[7912] & 0xEF;
}


// ========================================================================
// ?Get_idHands_meleeTraceHit@@YAHPAX@Z
// EA  : 0x8255C730
// RVA : 0x0055C730
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idHands_meleeTraceHit(_BYTE *ptr)
{
  return (ptr[7912] & 8) != 0;
}


// ========================================================================
// ?Set_idHands_meleeTraceHit@@YAXPAXH@Z
// EA  : 0x8255C740
// RVA : 0x0055C740
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_meleeTraceHit(_BYTE *ptr, int value)
{
  ptr[7912] = (8 * (value != 0)) & 8 | ptr[7912] & 0xF7;
}


// ========================================================================
// ?Get_idHands_isWallClimbing@@YAHPAX@Z
// EA  : 0x8255C758
// RVA : 0x0055C758
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idHands_isWallClimbing(_BYTE *ptr)
{
  return (ptr[7912] & 4) != 0;
}


// ========================================================================
// ?Set_idHands_isWallClimbing@@YAXPAXH@Z
// EA  : 0x8255C768
// RVA : 0x0055C768
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idHands_isWallClimbing(_BYTE *ptr, int value)
{
  ptr[7912] = (4 * (value != 0)) & 4 | ptr[7912] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelInfo_allowUpShadows@@YAHPAX@Z
// EA  : 0x8255C780
// RVA : 0x0055C780
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_allowUpShadows(_BYTE *ptr)
{
  return (ptr[4] & 4) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_allowUpShadows@@YAXPAXH@Z
// EA  : 0x8255C790
// RVA : 0x0055C790
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_allowUpShadows(_BYTE *ptr, int value)
{
  ptr[4] = (4 * (value != 0)) & 4 | ptr[4] & 0xFB;
}


// ========================================================================
// ?Get_idRenderModelInfo_forceAcceptDimShadows@@YAHPAX@Z
// EA  : 0x8255C7A8
// RVA : 0x0055C7A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_forceAcceptDimShadows(_BYTE *ptr)
{
  return (ptr[4] & 2) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_forceAcceptDimShadows@@YAXPAXH@Z
// EA  : 0x8255C7B8
// RVA : 0x0055C7B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_forceAcceptDimShadows(_BYTE *ptr, int value)
{
  ptr[4] = (2 * (value != 0)) & 2 | ptr[4] & 0xFD;
}


// ========================================================================
// ?Get_idRenderModelInfo_staticShadowsFromDynamicModel@@YAHPAX@Z
// EA  : 0x8255C7D0
// RVA : 0x0055C7D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idRenderModelInfo_staticShadowsFromDynamicModel(_BYTE *ptr)
{
  return ptr[4] & 1;
}


// ========================================================================
// ?Set_idRenderModelInfo_staticShadowsFromDynamicModel@@YAXPAXH@Z
// EA  : 0x8255C7E0
// RVA : 0x0055C7E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_staticShadowsFromDynamicModel(_BYTE *ptr, int value)
{
  ptr[4] = (value != 0) | ptr[4] & 0xFE;
}


// ========================================================================
// ?Get_idRenderModelInfo_privateLightOnly@@YAHPAX@Z
// EA  : 0x8255C7F8
// RVA : 0x0055C7F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idRenderModelInfo_privateLightOnly(unsigned __int8 *ptr)
{
  return ptr[5] >> 7;
}


// ========================================================================
// ?Set_idRenderModelInfo_privateLightOnly@@YAXPAXH@Z
// EA  : 0x8255C808
// RVA : 0x0055C808
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_privateLightOnly(_BYTE *ptr, int value)
{
  ptr[5] = ((value != 0) << 7) | ptr[5] & 0x7F;
}


// ========================================================================
// ?Get_idRenderModelInfo_noLocalLighting@@YAHPAX@Z
// EA  : 0x8255C820
// RVA : 0x0055C820
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_noLocalLighting(_BYTE *ptr)
{
  return (ptr[5] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_noLocalLighting@@YAXPAXH@Z
// EA  : 0x8255C830
// RVA : 0x0055C830
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_noLocalLighting(_BYTE *ptr, int value)
{
  ptr[5] = ((value != 0) << 6) & 0x40 | ptr[5] & 0xBF;
}


// ========================================================================
// ?Get_idRenderModelInfo_occluder@@YAHPAX@Z
// EA  : 0x8255C848
// RVA : 0x0055C848
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_occluder(_BYTE *ptr)
{
  return (ptr[5] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_occluder@@YAXPAXH@Z
// EA  : 0x8255C858
// RVA : 0x0055C858
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_occluder(_BYTE *ptr, int value)
{
  ptr[5] = (32 * (value != 0)) & 0x20 | ptr[5] & 0xDF;
}


// ========================================================================
// ?Get_idRenderModelInfo_megatexturedModel@@YAHPAX@Z
// EA  : 0x8255C870
// RVA : 0x0055C870
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_megatexturedModel(_BYTE *ptr)
{
  return (ptr[5] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_megatexturedModel@@YAXPAXH@Z
// EA  : 0x8255C880
// RVA : 0x0055C880
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_megatexturedModel(_BYTE *ptr, int value)
{
  ptr[5] = (16 * (value != 0)) & 0x10 | ptr[5] & 0xEF;
}


// ========================================================================
// ?Get_idRenderModelInfo_rebakeModel@@YAHPAX@Z
// EA  : 0x8255C898
// RVA : 0x0055C898
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRenderModelInfo_rebakeModel(_BYTE *ptr)
{
  return (ptr[5] & 8) != 0;
}


// ========================================================================
// ?Set_idRenderModelInfo_rebakeModel@@YAXPAXH@Z
// EA  : 0x8255C8A8
// RVA : 0x0055C8A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelInfo_rebakeModel(_BYTE *ptr, int value)
{
  ptr[5] = (8 * (value != 0)) & 8 | ptr[5] & 0xF7;
}


// ========================================================================
// ?Get_idProp_WeaponStatic_damageOccupant@@YAHPAX@Z
// EA  : 0x8255C8C0
// RVA : 0x0055C8C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idProp_WeaponStatic_damageOccupant(unsigned __int8 *ptr)
{
  return ptr[5748] >> 7;
}


// ========================================================================
// ?Set_idProp_WeaponStatic_damageOccupant@@YAXPAXH@Z
// EA  : 0x8255C8D0
// RVA : 0x0055C8D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_WeaponStatic_damageOccupant(_BYTE *ptr, int value)
{
  ptr[5748] = ((value != 0) << 7) | ptr[5748] & 0x7F;
}


// ========================================================================
// ?Get_idProp_WeaponStatic_removeUser@@YAHPAX@Z
// EA  : 0x8255C8E8
// RVA : 0x0055C8E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_WeaponStatic_removeUser(_BYTE *ptr)
{
  return (ptr[5748] & 0x40) != 0;
}


// ========================================================================
// ?Set_idProp_WeaponStatic_removeUser@@YAXPAXH@Z
// EA  : 0x8255C8F8
// RVA : 0x0055C8F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_WeaponStatic_removeUser(_BYTE *ptr, int value)
{
  ptr[5748] = ((value != 0) << 6) & 0x40 | ptr[5748] & 0xBF;
}


// ========================================================================
// ?Get_idProp_WeaponStatic_noManualExit@@YAHPAX@Z
// EA  : 0x8255C910
// RVA : 0x0055C910
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_WeaponStatic_noManualExit(_BYTE *ptr)
{
  return (ptr[5748] & 0x20) != 0;
}


// ========================================================================
// ?Set_idProp_WeaponStatic_noManualExit@@YAXPAXH@Z
// EA  : 0x8255C920
// RVA : 0x0055C920
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_WeaponStatic_noManualExit(_BYTE *ptr, int value)
{
  ptr[5748] = (32 * (value != 0)) & 0x20 | ptr[5748] & 0xDF;
}


// ========================================================================
// ?Get_idProp_WeaponStatic_disableCrosshair@@YAHPAX@Z
// EA  : 0x8255C938
// RVA : 0x0055C938
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_WeaponStatic_disableCrosshair(_BYTE *ptr)
{
  return (ptr[5748] & 0x10) != 0;
}


// ========================================================================
// ?Set_idProp_WeaponStatic_disableCrosshair@@YAXPAXH@Z
// EA  : 0x8255C948
// RVA : 0x0055C948
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_WeaponStatic_disableCrosshair(_BYTE *ptr, int value)
{
  ptr[5748] = (16 * (value != 0)) & 0x10 | ptr[5748] & 0xEF;
}


// ========================================================================
// ?Get_idProp_WeaponStatic_useEllipticLimit@@YAHPAX@Z
// EA  : 0x8255C960
// RVA : 0x0055C960
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idProp_WeaponStatic_useEllipticLimit(_BYTE *ptr)
{
  return (ptr[5748] & 8) != 0;
}


// ========================================================================
// ?Set_idProp_WeaponStatic_useEllipticLimit@@YAXPAXH@Z
// EA  : 0x8255C970
// RVA : 0x0055C970
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idProp_WeaponStatic_useEllipticLimit(_BYTE *ptr, int value)
{
  ptr[5748] = (8 * (value != 0)) & 8 | ptr[5748] & 0xF7;
}


// ========================================================================
// ?Get_idAttachment_isAnimated@@YAHPAX@Z
// EA  : 0x8255C988
// RVA : 0x0055C988
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAttachment_isAnimated(unsigned __int8 *ptr)
{
  return ptr[104] >> 7;
}


// ========================================================================
// ?Set_idRenderModelParms_allowHighQualityDimShadows@@YAXPAXH@Z
// EA  : 0x8255C998
// RVA : 0x0055C998
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_allowHighQualityDimShadows(_BYTE *ptr, int value)
{
  ptr[104] = ((value != 0) << 7) | ptr[104] & 0x7F;
}


// ========================================================================
// ?Get_idAttachment_isHidden@@YAHPAX@Z
// EA  : 0x8255C9B0
// RVA : 0x0055C9B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAttachment_isHidden(_BYTE *ptr)
{
  return (ptr[104] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_allowUpShadows@@YAXPAXH@Z
// EA  : 0x8255C9C0
// RVA : 0x0055C9C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_allowUpShadows(_BYTE *ptr, int value)
{
  ptr[104] = ((value != 0) << 6) & 0x40 | ptr[104] & 0xBF;
}


// ========================================================================
// ?Get_idAttachment_wasLinked@@YAHPAX@Z
// EA  : 0x8255C9D8
// RVA : 0x0055C9D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAttachment_wasLinked(_BYTE *ptr)
{
  return (ptr[104] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_isStatic@@YAXPAXH@Z
// EA  : 0x8255C9E8
// RVA : 0x0055C9E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_isStatic(_BYTE *ptr, int value)
{
  ptr[104] = (32 * (value != 0)) & 0x20 | ptr[104] & 0xDF;
}


// ========================================================================
// ?Get_idAttachment_isParticleFX@@YAHPAX@Z
// EA  : 0x8255CA00
// RVA : 0x0055CA00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAttachment_isParticleFX(_BYTE *ptr)
{
  return (ptr[104] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_isWorld@@YAXPAXH@Z
// EA  : 0x8255CA10
// RVA : 0x0055CA10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_isWorld(_BYTE *ptr, int value)
{
  ptr[104] = (16 * (value != 0)) & 0x10 | ptr[104] & 0xEF;
}


// ========================================================================
// ?Get_idAttachment_ignoreShowAll@@YAHPAX@Z
// EA  : 0x8255CA28
// RVA : 0x0055CA28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAttachment_ignoreShowAll(_BYTE *ptr)
{
  return (ptr[104] & 8) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_isSky@@YAXPAXH@Z
// EA  : 0x8255CA38
// RVA : 0x0055CA38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_isSky(_BYTE *ptr, int value)
{
  ptr[104] = (8 * (value != 0)) & 8 | ptr[104] & 0xF7;
}


// ========================================================================
// ?Get_idAttachment_isDetached@@YAHPAX@Z
// EA  : 0x8255CA50
// RVA : 0x0055CA50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAttachment_isDetached(_BYTE *ptr)
{
  return (ptr[104] & 4) != 0;
}


// ========================================================================
// ?Set_idRenderModelParms_isSceneModel@@YAXPAXH@Z
// EA  : 0x8255CA60
// RVA : 0x0055CA60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRenderModelParms_isSceneModel(_BYTE *ptr, int value)
{
  ptr[104] = (4 * (value != 0)) & 4 | ptr[104] & 0xFB;
}


// ========================================================================
// ?Set_idEntity_idBindInfo_bindOrientated@@YAXPAXH@Z
// EA  : 0x8255CA78
// RVA : 0x0055CA78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idEntity_idBindInfo_bindOrientated(_BYTE *ptr, int value)
{
  ptr[112] = ((value != 0) << 7) | ptr[112] & 0x7F;
}


// ========================================================================
// ?Get_idEntity_idBindInfo_bindLighting@@YAHPAX@Z
// EA  : 0x8255CA90
// RVA : 0x0055CA90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_idBindInfo_bindLighting(_BYTE *ptr)
{
  return (ptr[112] & 0x40) != 0;
}


// ========================================================================
// ?Set_idEntity_idBindInfo_bindLighting@@YAXPAXH@Z
// EA  : 0x8255CAA0
// RVA : 0x0055CAA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idEntity_idBindInfo_bindLighting(_BYTE *ptr, int value)
{
  ptr[112] = ((value != 0) << 6) & 0x40 | ptr[112] & 0xBF;
}


// ========================================================================
// ?Get_idEntity_idBindInfo_solidForTeam@@YAHPAX@Z
// EA  : 0x8255CAB8
// RVA : 0x0055CAB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_idBindInfo_solidForTeam(_BYTE *ptr)
{
  return (ptr[112] & 0x20) != 0;
}


// ========================================================================
// ?Set_idEntity_idBindInfo_solidForTeam@@YAXPAXH@Z
// EA  : 0x8255CAC8
// RVA : 0x0055CAC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idEntity_idBindInfo_solidForTeam(_BYTE *ptr, int value)
{
  ptr[112] = (32 * (value != 0)) & 0x20 | ptr[112] & 0xDF;
}


// ========================================================================
// ?Get_idEntity_idBindInfo_snapToParent@@YAHPAX@Z
// EA  : 0x8255CAE0
// RVA : 0x0055CAE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idEntity_idBindInfo_snapToParent(_BYTE *ptr)
{
  return (ptr[112] & 0x10) != 0;
}


// ========================================================================
// ?Set_idEntity_idBindInfo_snapToParent@@YAXPAXH@Z
// EA  : 0x8255CAF0
// RVA : 0x0055CAF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idEntity_idBindInfo_snapToParent(_BYTE *ptr, int value)
{
  ptr[112] = (16 * (value != 0)) & 0x10 | ptr[112] & 0xEF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_disableIK@@YAHPAX@Z
// EA  : 0x8255CB08
// RVA : 0x0055CB08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAIScriptedAnimWeb_animWebState_t_disableIK(unsigned __int8 *ptr)
{
  return ptr[160] >> 7;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_disableIK@@YAXPAXH@Z
// EA  : 0x8255CB18
// RVA : 0x0055CB18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_disableIK(_BYTE *ptr, int value)
{
  ptr[160] = ((value != 0) << 7) | ptr[160] & 0x7F;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_disableWorldCollsion@@YAHPAX@Z
// EA  : 0x8255CB30
// RVA : 0x0055CB30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_disableWorldCollsion(_BYTE *ptr)
{
  return (ptr[160] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_disableWorldCollsion@@YAXPAXH@Z
// EA  : 0x8255CB40
// RVA : 0x0055CB40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_disableWorldCollsion(_BYTE *ptr, int value)
{
  ptr[160] = ((value != 0) << 6) & 0x40 | ptr[160] & 0xBF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_disableSolid@@YAHPAX@Z
// EA  : 0x8255CB58
// RVA : 0x0055CB58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_disableSolid(_BYTE *ptr)
{
  return (ptr[160] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_disableSolid@@YAXPAXH@Z
// EA  : 0x8255CB68
// RVA : 0x0055CB68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_disableSolid(_BYTE *ptr, int value)
{
  ptr[160] = (32 * (value != 0)) & 0x20 | ptr[160] & 0xDF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_loop@@YAHPAX@Z
// EA  : 0x8255CB80
// RVA : 0x0055CB80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_loop(_BYTE *ptr)
{
  return (ptr[160] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_loop@@YAXPAXH@Z
// EA  : 0x8255CB90
// RVA : 0x0055CB90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_loop(_BYTE *ptr, int value)
{
  ptr[160] = (16 * (value != 0)) & 0x10 | ptr[160] & 0xEF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_perfectOrigin@@YAHPAX@Z
// EA  : 0x8255CBA8
// RVA : 0x0055CBA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_perfectOrigin(_BYTE *ptr)
{
  return (ptr[160] & 8) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_perfectOrigin@@YAXPAXH@Z
// EA  : 0x8255CBB8
// RVA : 0x0055CBB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_perfectOrigin(_BYTE *ptr, int value)
{
  ptr[160] = (8 * (value != 0)) & 8 | ptr[160] & 0xF7;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_releaseAI@@YAHPAX@Z
// EA  : 0x8255CBD0
// RVA : 0x0055CBD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_releaseAI(_BYTE *ptr)
{
  return (ptr[160] & 4) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_releaseAI@@YAXPAXH@Z
// EA  : 0x8255CBE0
// RVA : 0x0055CBE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_releaseAI(_BYTE *ptr, int value)
{
  ptr[160] = (4 * (value != 0)) & 4 | ptr[160] & 0xFB;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_clearPerceptionFlagsOnExit@@YAHPAX@Z
// EA  : 0x8255CBF8
// RVA : 0x0055CBF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_clearPerceptionFlagsOnExit(_BYTE *ptr)
{
  return (ptr[160] & 2) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_clearPerceptionFlagsOnExit@@YAXPAXH@Z
// EA  : 0x8255CC08
// RVA : 0x0055CC08
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_clearPerceptionFlagsOnExit(_BYTE *ptr, int value)
{
  ptr[160] = (2 * (value != 0)) & 2 | ptr[160] & 0xFD;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_setPerceptionFlagsOnExit@@YAHPAX@Z
// EA  : 0x8255CC20
// RVA : 0x0055CC20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAIScriptedAnimWeb_animWebState_t_setPerceptionFlagsOnExit(_BYTE *ptr)
{
  return ptr[160] & 1;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_setPerceptionFlagsOnExit@@YAXPAXH@Z
// EA  : 0x8255CC30
// RVA : 0x0055CC30
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_setPerceptionFlagsOnExit(_BYTE *ptr, int value)
{
  ptr[160] = (value != 0) | ptr[160] & 0xFE;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_keepIKState@@YAHPAX@Z
// EA  : 0x8255CC48
// RVA : 0x0055CC48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAIScriptedAnimWeb_animWebState_t_keepIKState(unsigned __int8 *ptr)
{
  return ptr[161] >> 7;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_keepIKState@@YAXPAXH@Z
// EA  : 0x8255CC58
// RVA : 0x0055CC58
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_keepIKState(_BYTE *ptr, int value)
{
  ptr[161] = ((value != 0) << 7) | ptr[161] & 0x7F;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_enableHeadTracking@@YAHPAX@Z
// EA  : 0x8255CC70
// RVA : 0x0055CC70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_enableHeadTracking(_BYTE *ptr)
{
  return (ptr[161] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_enableHeadTracking@@YAXPAXH@Z
// EA  : 0x8255CC80
// RVA : 0x0055CC80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_enableHeadTracking(_BYTE *ptr, int value)
{
  ptr[161] = ((value != 0) << 6) & 0x40 | ptr[161] & 0xBF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_forceTransition@@YAHPAX@Z
// EA  : 0x8255CC98
// RVA : 0x0055CC98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_forceTransition(_BYTE *ptr)
{
  return (ptr[161] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_forceTransition@@YAXPAXH@Z
// EA  : 0x8255CCA8
// RVA : 0x0055CCA8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_forceTransition(_BYTE *ptr, int value)
{
  ptr[161] = (32 * (value != 0)) & 0x20 | ptr[161] & 0xDF;
}


// ========================================================================
// ?Get_idAIScriptedAnimWeb_animWebState_t_useAnimationOrigin@@YAHPAX@Z
// EA  : 0x8255CCC0
// RVA : 0x0055CCC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAIScriptedAnimWeb_animWebState_t_useAnimationOrigin(_BYTE *ptr)
{
  return (ptr[161] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAIScriptedAnimWeb_animWebState_t_useAnimationOrigin@@YAXPAXH@Z
// EA  : 0x8255CCD0
// RVA : 0x0055CCD0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAIScriptedAnimWeb_animWebState_t_useAnimationOrigin(_BYTE *ptr, int value)
{
  ptr[161] = (16 * (value != 0)) & 0x10 | ptr[161] & 0xEF;
}


// ========================================================================
// ?Get_idVehicleOccupant_Car_isLooking@@YAHPAX@Z
// EA  : 0x8255CCE8
// RVA : 0x0055CCE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVehicleOccupant_Car_isLooking(unsigned __int8 *ptr)
{
  return ptr[10026] >> 7;
}


// ========================================================================
// ?Set_idVehicleOccupant_Car_isLooking@@YAXPAXH@Z
// EA  : 0x8255CCF8
// RVA : 0x0055CCF8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicleOccupant_Car_isLooking(_BYTE *ptr, int value)
{
  ptr[10026] = ((value != 0) << 7) | ptr[10026] & 0x7F;
}


// ========================================================================
// ?Get_idVehicleOccupant_Car_reactionEnabled@@YAHPAX@Z
// EA  : 0x8255CD10
// RVA : 0x0055CD10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicleOccupant_Car_reactionEnabled(_BYTE *ptr)
{
  return (ptr[10026] & 0x40) != 0;
}


// ========================================================================
// ?Set_idVehicleOccupant_Car_reactionEnabled@@YAXPAXH@Z
// EA  : 0x8255CD20
// RVA : 0x0055CD20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicleOccupant_Car_reactionEnabled(_BYTE *ptr, int value)
{
  ptr[10026] = ((value != 0) << 6) & 0x40 | ptr[10026] & 0xBF;
}


// ========================================================================
// ?Get_idVehicleOccupant_Car_additiveShakeEnabled@@YAHPAX@Z
// EA  : 0x8255CD38
// RVA : 0x0055CD38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicleOccupant_Car_additiveShakeEnabled(_BYTE *ptr)
{
  return (ptr[10026] & 0x20) != 0;
}


// ========================================================================
// ?Set_idVehicleOccupant_Car_additiveShakeEnabled@@YAXPAXH@Z
// EA  : 0x8255CD48
// RVA : 0x0055CD48
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicleOccupant_Car_additiveShakeEnabled(_BYTE *ptr, int value)
{
  ptr[10026] = (32 * (value != 0)) & 0x20 | ptr[10026] & 0xDF;
}


// ========================================================================
// ?Get_idVehicleOccupant_Car_painAnimsEnabled@@YAHPAX@Z
// EA  : 0x8255CD60
// RVA : 0x0055CD60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicleOccupant_Car_painAnimsEnabled(_BYTE *ptr)
{
  return (ptr[10026] & 0x10) != 0;
}


// ========================================================================
// ?Set_idVehicleOccupant_Car_painAnimsEnabled@@YAXPAXH@Z
// EA  : 0x8255CD70
// RVA : 0x0055CD70
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicleOccupant_Car_painAnimsEnabled(_BYTE *ptr, int value)
{
  ptr[10026] = (16 * (value != 0)) & 0x10 | ptr[10026] & 0xEF;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_unbindAnimation@@YAHPAX@Z
// EA  : 0x8255CD88
// RVA : 0x0055CD88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_unbindAnimation(_BYTE *ptr)
{
  return (ptr[36] & 0x40) != 0;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_unbindAnimation@@YAXPAXH@Z
// EA  : 0x8255CD98
// RVA : 0x0055CD98
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_unbindAnimation(_BYTE *ptr, int value)
{
  ptr[36] = ((value != 0) << 6) & 0x40 | ptr[36] & 0xBF;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_snapAnimEndToGround@@YAHPAX@Z
// EA  : 0x8255CDB0
// RVA : 0x0055CDB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_snapAnimEndToGround(_BYTE *ptr)
{
  return (ptr[36] & 0x20) != 0;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_snapAnimEndToGround@@YAXPAXH@Z
// EA  : 0x8255CDC0
// RVA : 0x0055CDC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_snapAnimEndToGround(_BYTE *ptr, int value)
{
  ptr[36] = (32 * (value != 0)) & 0x20 | ptr[36] & 0xDF;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_sprintSpeed@@YAHPAX@Z
// EA  : 0x8255CDD8
// RVA : 0x0055CDD8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_sprintSpeed(_BYTE *ptr)
{
  return (ptr[36] & 0x10) != 0;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_sprintSpeed@@YAXPAXH@Z
// EA  : 0x8255CDE8
// RVA : 0x0055CDE8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_sprintSpeed(_BYTE *ptr, int value)
{
  ptr[36] = (16 * (value != 0)) & 0x10 | ptr[36] & 0xEF;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_leapPoint@@YAHPAX@Z
// EA  : 0x8255CE00
// RVA : 0x0055CE00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_leapPoint(_BYTE *ptr)
{
  return (ptr[36] & 8) != 0;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_leapPoint@@YAXPAXH@Z
// EA  : 0x8255CE10
// RVA : 0x0055CE10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_leapPoint(_BYTE *ptr, int value)
{
  ptr[36] = (8 * (value != 0)) & 8 | ptr[36] & 0xF7;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_removeEntirely@@YAHPAX@Z
// EA  : 0x8255CE28
// RVA : 0x0055CE28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_removeEntirely(_BYTE *ptr)
{
  return (ptr[36] & 4) != 0;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_removeEntirely@@YAXPAXH@Z
// EA  : 0x8255CE38
// RVA : 0x0055CE38
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_removeEntirely(_BYTE *ptr, int value)
{
  ptr[36] = (4 * (value != 0)) & 4 | ptr[36] & 0xFB;
}


// ========================================================================
// ?Get_idVehicle_eventAnimEntry_t_useAnimationOrigin@@YAHPAX@Z
// EA  : 0x8255CE50
// RVA : 0x0055CE50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVehicle_eventAnimEntry_t_useAnimationOrigin(unsigned __int8 *ptr)
{
  return ptr[168] >> 7;
}


// ========================================================================
// ?Set_idVehicle_eventAnimEntry_t_useAnimationOrigin@@YAXPAXH@Z
// EA  : 0x8255CE60
// RVA : 0x0055CE60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicle_eventAnimEntry_t_useAnimationOrigin(_BYTE *ptr, int value)
{
  ptr[168] = ((value != 0) << 7) | ptr[168] & 0x7F;
}


// ========================================================================
// ?Get_idVehicle_eventAnimEntry_t_useDeltaMovement@@YAHPAX@Z
// EA  : 0x8255CE78
// RVA : 0x0055CE78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicle_eventAnimEntry_t_useDeltaMovement(_BYTE *ptr)
{
  return (ptr[168] & 0x40) != 0;
}


// ========================================================================
// ?Set_idVehicle_eventAnimEntry_t_useDeltaMovement@@YAXPAXH@Z
// EA  : 0x8255CE88
// RVA : 0x0055CE88
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicle_eventAnimEntry_t_useDeltaMovement(_BYTE *ptr, int value)
{
  ptr[168] = ((value != 0) << 6) & 0x40 | ptr[168] & 0xBF;
}


// ========================================================================
// ?Get_idVehicle_eventAnimEntry_t_loop@@YAHPAX@Z
// EA  : 0x8255CEA0
// RVA : 0x0055CEA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicle_eventAnimEntry_t_loop(_BYTE *ptr)
{
  return (ptr[168] & 0x20) != 0;
}


// ========================================================================
// ?Set_idVehicle_eventAnimEntry_t_loop@@YAXPAXH@Z
// EA  : 0x8255CEB0
// RVA : 0x0055CEB0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicle_eventAnimEntry_t_loop(_BYTE *ptr, int value)
{
  ptr[168] = (32 * (value != 0)) & 0x20 | ptr[168] & 0xDF;
}


// ========================================================================
// ?Get_idVehicle_eventAnimEntry_t_turnOffPhysics@@YAHPAX@Z
// EA  : 0x8255CEC8
// RVA : 0x0055CEC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVehicle_eventAnimEntry_t_turnOffPhysics(_BYTE *ptr)
{
  return (ptr[168] & 0x10) != 0;
}


// ========================================================================
// ?Set_idVehicle_eventAnimEntry_t_turnOffPhysics@@YAXPAXH@Z
// EA  : 0x8255CED8
// RVA : 0x0055CED8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVehicle_eventAnimEntry_t_turnOffPhysics(_BYTE *ptr, int value)
{
  ptr[168] = (16 * (value != 0)) & 0x10 | ptr[168] & 0xEF;
}


// ========================================================================
// ?Get_idAnimatedSimple_applyAnimTransform@@YAHPAX@Z
// EA  : 0x8255CEF0
// RVA : 0x0055CEF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAnimatedSimple_applyAnimTransform(unsigned __int8 *ptr)
{
  return ptr[5292] >> 7;
}


// ========================================================================
// ?Set_idAnimatedSimple_applyAnimTransform@@YAXPAXH@Z
// EA  : 0x8255CF00
// RVA : 0x0055CF00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_applyAnimTransform(_BYTE *ptr, int value)
{
  ptr[5292] = ((value != 0) << 7) | ptr[5292] & 0x7F;
}


// ========================================================================
// ?Get_idAnimatedSimple_applyAnimTransformLocal@@YAHPAX@Z
// EA  : 0x8255CF18
// RVA : 0x0055CF18
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_applyAnimTransformLocal(_BYTE *ptr)
{
  return (ptr[5292] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_applyAnimTransformLocal@@YAXPAXH@Z
// EA  : 0x8255CF28
// RVA : 0x0055CF28
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_applyAnimTransformLocal(_BYTE *ptr, int value)
{
  ptr[5292] = ((value != 0) << 6) & 0x40 | ptr[5292] & 0xBF;
}


// ========================================================================
// ?Get_idAnimatedSimple_playerShouldLowerWeapon@@YAHPAX@Z
// EA  : 0x8255CF40
// RVA : 0x0055CF40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_playerShouldLowerWeapon(_BYTE *ptr)
{
  return (ptr[5292] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_playerShouldLowerWeapon@@YAXPAXH@Z
// EA  : 0x8255CF50
// RVA : 0x0055CF50
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_playerShouldLowerWeapon(_BYTE *ptr, int value)
{
  ptr[5292] = (32 * (value != 0)) & 0x20 | ptr[5292] & 0xDF;
}


// ========================================================================
// ?Get_idAnimatedSimple_ignoreMovement@@YAHPAX@Z
// EA  : 0x8255CF68
// RVA : 0x0055CF68
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_ignoreMovement(_BYTE *ptr)
{
  return (ptr[5292] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_ignoreMovement@@YAXPAXH@Z
// EA  : 0x8255CF78
// RVA : 0x0055CF78
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_ignoreMovement(_BYTE *ptr, int value)
{
  ptr[5292] = (16 * (value != 0)) & 0x10 | ptr[5292] & 0xEF;
}


// ========================================================================
// ?Get_idAnimatedSimple_isOkWithoutModel@@YAHPAX@Z
// EA  : 0x8255CF90
// RVA : 0x0055CF90
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_isOkWithoutModel(_BYTE *ptr)
{
  return (ptr[5292] & 8) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_isOkWithoutModel@@YAXPAXH@Z
// EA  : 0x8255CFA0
// RVA : 0x0055CFA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_isOkWithoutModel(_BYTE *ptr, int value)
{
  ptr[5292] = (8 * (value != 0)) & 8 | ptr[5292] & 0xF7;
}


// ========================================================================
// ?Get_idAnimatedSimple_sceneModel@@YAHPAX@Z
// EA  : 0x8255CFB8
// RVA : 0x0055CFB8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_sceneModel(_BYTE *ptr)
{
  return (ptr[5292] & 4) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_sceneModel@@YAXPAXH@Z
// EA  : 0x8255CFC8
// RVA : 0x0055CFC8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_sceneModel(_BYTE *ptr, int value)
{
  ptr[5292] = (4 * (value != 0)) & 4 | ptr[5292] & 0xFB;
}


// ========================================================================
// ?Get_idAnimatedSimple_noDeferredPositon@@YAHPAX@Z
// EA  : 0x8255CFE0
// RVA : 0x0055CFE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_noDeferredPositon(_BYTE *ptr)
{
  return (ptr[5292] & 2) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_noDeferredPositon@@YAXPAXH@Z
// EA  : 0x8255CFF0
// RVA : 0x0055CFF0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_noDeferredPositon(_BYTE *ptr, int value)
{
  ptr[5292] = (2 * (value != 0)) & 2 | ptr[5292] & 0xFD;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_playDefault@@YAHPAX@Z
// EA  : 0x8255D008
// RVA : 0x0055D008
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idAnimatedSimple_animEntry_t_playDefault(unsigned __int8 *ptr)
{
  return ptr[124] >> 7;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_playDefault@@YAXPAXH@Z
// EA  : 0x8255D018
// RVA : 0x0055D018
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_playDefault(_BYTE *ptr, int value)
{
  ptr[124] = ((value != 0) << 7) | ptr[124] & 0x7F;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_useAnimationOrigin@@YAHPAX@Z
// EA  : 0x8255D030
// RVA : 0x0055D030
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_useAnimationOrigin(_BYTE *ptr)
{
  return (ptr[124] & 0x40) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_useAnimationOrigin@@YAXPAXH@Z
// EA  : 0x8255D040
// RVA : 0x0055D040
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_useAnimationOrigin(_BYTE *ptr, int value)
{
  ptr[124] = ((value != 0) << 6) & 0x40 | ptr[124] & 0xBF;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_loop@@YAHPAX@Z
// EA  : 0x8255D058
// RVA : 0x0055D058
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_loop(_BYTE *ptr)
{
  return (ptr[124] & 0x20) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_loop@@YAXPAXH@Z
// EA  : 0x8255D068
// RVA : 0x0055D068
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_loop(_BYTE *ptr, int value)
{
  ptr[124] = (32 * (value != 0)) & 0x20 | ptr[124] & 0xDF;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_useDeltaMovement@@YAHPAX@Z
// EA  : 0x8255D080
// RVA : 0x0055D080
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_useDeltaMovement(_BYTE *ptr)
{
  return (ptr[124] & 0x10) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_useDeltaMovement@@YAXPAXH@Z
// EA  : 0x8255D090
// RVA : 0x0055D090
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_useDeltaMovement(_BYTE *ptr, int value)
{
  ptr[124] = (16 * (value != 0)) & 0x10 | ptr[124] & 0xEF;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_hideWhenDone@@YAHPAX@Z
// EA  : 0x8255D0A8
// RVA : 0x0055D0A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_hideWhenDone(_BYTE *ptr)
{
  return (ptr[124] & 8) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_hideWhenDone@@YAXPAXH@Z
// EA  : 0x8255D0B8
// RVA : 0x0055D0B8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_hideWhenDone(_BYTE *ptr, int value)
{
  ptr[124] = (8 * (value != 0)) & 8 | ptr[124] & 0xF7;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_useAnimationScale@@YAHPAX@Z
// EA  : 0x8255D0D0
// RVA : 0x0055D0D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_useAnimationScale(_BYTE *ptr)
{
  return (ptr[124] & 4) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_useAnimationScale@@YAXPAXH@Z
// EA  : 0x8255D0E0
// RVA : 0x0055D0E0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_useAnimationScale(_BYTE *ptr, int value)
{
  ptr[124] = (4 * (value != 0)) & 4 | ptr[124] & 0xFB;
}


// ========================================================================
// ?Get_idAnimatedSimple_animEntry_t_useTimeControl@@YAHPAX@Z
// EA  : 0x8255D0F8
// RVA : 0x0055D0F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idAnimatedSimple_animEntry_t_useTimeControl(_BYTE *ptr)
{
  return (ptr[124] & 2) != 0;
}


// ========================================================================
// ?Set_idAnimatedSimple_animEntry_t_useTimeControl@@YAXPAXH@Z
// EA  : 0x8255D108
// RVA : 0x0055D108
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idAnimatedSimple_animEntry_t_useTimeControl(_BYTE *ptr, int value)
{
  ptr[124] = (2 * (value != 0)) & 2 | ptr[124] & 0xFD;
}


// ========================================================================
// ?Get_splineMoverModifier_t_splineMoverModifierAiProps_t_aiChange@@YAHPAX@Z
// EA  : 0x8255D120
// RVA : 0x0055D120
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_splineMoverModifier_t_splineMoverModifierAiProps_t_aiChange(unsigned __int8 *ptr)
{
  return ptr[36] >> 7;
}


// ========================================================================
// ?Set_splineMoverModifier_t_splineMoverModifierAiProps_t_aiChange@@YAXPAXH@Z
// EA  : 0x8255D130
// RVA : 0x0055D130
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_splineMoverModifier_t_splineMoverModifierAiProps_t_aiChange(_BYTE *ptr, int value)
{
  ptr[36] = ((value != 0) << 7) | ptr[36] & 0x7F;
}


// ========================================================================
// ?Get_idRotatableCamera_bindPlayerToCamera@@YAHPAX@Z
// EA  : 0x8255D148
// RVA : 0x0055D148
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idRotatableCamera_bindPlayerToCamera(unsigned __int8 *ptr)
{
  return ptr[1028] >> 7;
}


// ========================================================================
// ?Set_idRotatableCamera_bindPlayerToCamera@@YAXPAXH@Z
// EA  : 0x8255D158
// RVA : 0x0055D158
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRotatableCamera_bindPlayerToCamera(_BYTE *ptr, int value)
{
  ptr[1028] = ((value != 0) << 7) | ptr[1028] & 0x7F;
}


// ========================================================================
// ?Get_idRotatableCamera_inhibitUse@@YAHPAX@Z
// EA  : 0x8255D170
// RVA : 0x0055D170
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRotatableCamera_inhibitUse(_BYTE *ptr)
{
  return (ptr[1028] & 0x40) != 0;
}


// ========================================================================
// ?Set_idRotatableCamera_inhibitUse@@YAXPAXH@Z
// EA  : 0x8255D180
// RVA : 0x0055D180
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRotatableCamera_inhibitUse(_BYTE *ptr, int value)
{
  ptr[1028] = ((value != 0) << 6) & 0x40 | ptr[1028] & 0xBF;
}


// ========================================================================
// ?Get_idRotatableCamera_useLocalPlayer@@YAHPAX@Z
// EA  : 0x8255D198
// RVA : 0x0055D198
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRotatableCamera_useLocalPlayer(_BYTE *ptr)
{
  return (ptr[1028] & 0x20) != 0;
}


// ========================================================================
// ?Set_idRotatableCamera_useLocalPlayer@@YAXPAXH@Z
// EA  : 0x8255D1A8
// RVA : 0x0055D1A8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRotatableCamera_useLocalPlayer(_BYTE *ptr, int value)
{
  ptr[1028] = (32 * (value != 0)) & 0x20 | ptr[1028] & 0xDF;
}


// ========================================================================
// ?Get_idRotatableCamera_useEllipticLimits@@YAHPAX@Z
// EA  : 0x8255D1C0
// RVA : 0x0055D1C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idRotatableCamera_useEllipticLimits(_BYTE *ptr)
{
  return (ptr[1028] & 0x10) != 0;
}


// ========================================================================
// ?Set_idRotatableCamera_useEllipticLimits@@YAXPAXH@Z
// EA  : 0x8255D1D0
// RVA : 0x0055D1D0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idRotatableCamera_useEllipticLimits(_BYTE *ptr, int value)
{
  ptr[1028] = (16 * (value != 0)) & 0x10 | ptr[1028] & 0xEF;
}


// ========================================================================
// ?Get_idVolume_touchable@@YAHPAX@Z
// EA  : 0x8255D1E8
// RVA : 0x0055D1E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVolume_touchable(unsigned __int8 *ptr)
{
  return ptr[816] >> 7;
}


// ========================================================================
// ?Set_idVolume_touchable@@YAXPAXH@Z
// EA  : 0x8255D1F8
// RVA : 0x0055D1F8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_touchable(_BYTE *ptr, int value)
{
  ptr[816] = ((value != 0) << 7) | ptr[816] & 0x7F;
}


// ========================================================================
// ?Get_idVolume_EnterExit_aiCanActivate@@YAHPAX@Z
// EA  : 0x8255D210
// RVA : 0x0055D210
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVolume_EnterExit_aiCanActivate(unsigned __int8 *ptr)
{
  return ptr[824] >> 7;
}


// ========================================================================
// ?Set_idVolume_EnterExit_aiCanActivate@@YAXPAXH@Z
// EA  : 0x8255D220
// RVA : 0x0055D220
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_aiCanActivate(_BYTE *ptr, int value)
{
  ptr[824] = ((value != 0) << 7) | ptr[824] & 0x7F;
}


// ========================================================================
// ?Get_idVolume_EnterExit_playerCanActivate@@YAHPAX@Z
// EA  : 0x8255D238
// RVA : 0x0055D238
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVolume_EnterExit_playerCanActivate(_BYTE *ptr)
{
  return (ptr[824] & 0x40) != 0;
}


// ========================================================================
// ?Set_idVolume_EnterExit_playerCanActivate@@YAXPAXH@Z
// EA  : 0x8255D248
// RVA : 0x0055D248
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_playerCanActivate(_BYTE *ptr, int value)
{
  ptr[824] = ((value != 0) << 6) & 0x40 | ptr[824] & 0xBF;
}


// ========================================================================
// ?Get_idVolume_EnterExit_individualTriggers@@YAHPAX@Z
// EA  : 0x8255D260
// RVA : 0x0055D260
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVolume_EnterExit_individualTriggers(_BYTE *ptr)
{
  return (ptr[824] & 0x20) != 0;
}


// ========================================================================
// ?Set_idVolume_EnterExit_individualTriggers@@YAXPAXH@Z
// EA  : 0x8255D270
// RVA : 0x0055D270
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_individualTriggers(_BYTE *ptr, int value)
{
  ptr[824] = (32 * (value != 0)) & 0x20 | ptr[824] & 0xDF;
}


// ========================================================================
// ?Get_idVolume_EnterExit_enterTriggerOnce@@YAHPAX@Z
// EA  : 0x8255D288
// RVA : 0x0055D288
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVolume_EnterExit_enterTriggerOnce(_BYTE *ptr)
{
  return (ptr[824] & 0x10) != 0;
}


// ========================================================================
// ?Set_idVolume_EnterExit_enterTriggerOnce@@YAXPAXH@Z
// EA  : 0x8255D298
// RVA : 0x0055D298
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_enterTriggerOnce(_BYTE *ptr, int value)
{
  ptr[824] = (16 * (value != 0)) & 0x10 | ptr[824] & 0xEF;
}


// ========================================================================
// ?Get_idVolume_EnterExit_exitTriggerOnce@@YAHPAX@Z
// EA  : 0x8255D2B0
// RVA : 0x0055D2B0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVolume_EnterExit_exitTriggerOnce(_BYTE *ptr)
{
  return (ptr[824] & 8) != 0;
}


// ========================================================================
// ?Set_idVolume_EnterExit_exitTriggerOnce@@YAXPAXH@Z
// EA  : 0x8255D2C0
// RVA : 0x0055D2C0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_exitTriggerOnce(_BYTE *ptr, int value)
{
  ptr[824] = (8 * (value != 0)) & 8 | ptr[824] & 0xF7;
}


// ========================================================================
// ?Get_idVolume_EnterExit_enterTriggered@@YAHPAX@Z
// EA  : 0x8255D2D8
// RVA : 0x0055D2D8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

int __fastcall Get_idVolume_EnterExit_enterTriggered(unsigned __int8 *ptr)
{
  return ptr[884] >> 7;
}


// ========================================================================
// ?Set_idVolume_EnterExit_enterTriggered@@YAXPAXH@Z
// EA  : 0x8255D2E8
// RVA : 0x0055D2E8
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_enterTriggered(_BYTE *ptr, int value)
{
  ptr[884] = ((value != 0) << 7) | ptr[884] & 0x7F;
}


// ========================================================================
// ?Get_idVolume_EnterExit_exitTriggered@@YAHPAX@Z
// EA  : 0x8255D300
// RVA : 0x0055D300
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

BOOL __fastcall Get_idVolume_EnterExit_exitTriggered(_BYTE *ptr)
{
  return (ptr[884] & 0x40) != 0;
}


// ========================================================================
// ?Set_idVolume_EnterExit_exitTriggered@@YAXPAXH@Z
// EA  : 0x8255D310
// RVA : 0x0055D310
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void __fastcall Set_idVolume_EnterExit_exitTriggered(_BYTE *ptr, int value)
{
  ptr[884] = ((value != 0) << 6) & 0x40 | ptr[884] & 0xBF;
}


// ========================================================================
// `dynamic initializer for 'idAnimator_TrackerBase_typeInfo''
// EA  : 0x83334DC0
// RVA : 0x01334DC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idAnimator_TrackerBase_typeInfo__()
{
  idAnimator_TrackerBase_typeInfo[22].get = nullptr;
  idAnimator_TrackerBase_typeInfo[22].set = nullptr;
  idAnimator_TrackerBase_typeInfo[22].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAnimatedEntity_typeInfo''
// EA  : 0x83334DE0
// RVA : 0x01334DE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idAnimatedEntity_typeInfo__()
{
  idAnimatedEntity_typeInfo[15].get = nullptr;
  idAnimatedEntity_typeInfo[15].set = nullptr;
  idAnimatedEntity_typeInfo[15].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAIVoiceController_typeInfo''
// EA  : 0x83334E00
// RVA : 0x01334E00
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idAIVoiceController_typeInfo__()
{
  idAIVoiceController_typeInfo[5].get = nullptr;
  idAIVoiceController_typeInfo[5].set = nullptr;
  idAIVoiceController_typeInfo[5].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'trackingParms_t_typeInfo''
// EA  : 0x83334E20
// RVA : 0x01334E20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__trackingParms_t_typeInfo__()
{
  trackingParms_t_typeInfo[10].get = nullptr;
  trackingParms_t_typeInfo[10].set = nullptr;
  trackingParms_t_typeInfo[10].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idRotationTracker_typeInfo''
// EA  : 0x83334E40
// RVA : 0x01334E40
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idRotationTracker_typeInfo__()
{
  idRotationTracker_typeInfo[14].get = nullptr;
  idRotationTracker_typeInfo[14].set = nullptr;
  idRotationTracker_typeInfo[14].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idFaceMgr_typeInfo''
// EA  : 0x83334E60
// RVA : 0x01334E60
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idFaceMgr_typeInfo__()
{
  idFaceMgr_typeInfo[45].get = nullptr;
  idFaceMgr_typeInfo[45].set = nullptr;
  idFaceMgr_typeInfo[45].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idInfo_Trigger_Facing_Target_typeInfo''
// EA  : 0x83334E80
// RVA : 0x01334E80
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idInfo_Trigger_Facing_Target_typeInfo__()
{
  idInfo_Trigger_Facing_Target_typeInfo[2].get = nullptr;
  idInfo_Trigger_Facing_Target_typeInfo[2].set = nullptr;
  idInfo_Trigger_Facing_Target_typeInfo[2].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idSector_typeInfo''
// EA  : 0x83334EA0
// RVA : 0x01334EA0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idSector_typeInfo__()
{
  idSector_typeInfo[2].get = nullptr;
  idSector_typeInfo[2].set = nullptr;
  idSector_typeInfo[2].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idFieldOfView_typeInfo''
// EA  : 0x83334EC0
// RVA : 0x01334EC0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idFieldOfView_typeInfo__()
{
  idFieldOfView_typeInfo[3].get = nullptr;
  idFieldOfView_typeInfo[3].set = nullptr;
  idFieldOfView_typeInfo[3].reallocate = nullptr;
}


// ========================================================================
// `dynamic initializer for 'idAIHintPrimitive_typeInfo''
// EA  : 0x83334EE0
// RVA : 0x01334EE0
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_2.cpp
// ========================================================================

void _dynamic_initializer_for__idAIHintPrimitive_typeInfo__()
{
  idAIHintPrimitive_typeInfo[5].get = nullptr;
  idAIHintPrimitive_typeInfo[5].set = nullptr;
  idAIHintPrimitive_typeInfo[5].reallocate = nullptr;
}

