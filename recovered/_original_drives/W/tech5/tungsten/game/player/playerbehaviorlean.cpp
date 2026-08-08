
// ========================================================================
// ?PlayerBehavior_Lean_CanLean@idPlayer@@QBA_NXZ
// EA  : 0x82E45DF0
// RVA : 0x00E45DF0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Lean_CanLean(idPlayer *this)
{
  idPhysics *Physics; // r30
  int result; // r3

  if ( pb_lean_Enable.valueInteger == 0 )
    return 0;
  Physics = idEntity::GetPhysics(this);
  if ( idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this) )
    return 0;
  if ( idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this) )
    return 0;
  if ( idPlayer::PlayerBehavior_SprintSlide_IsSliding(this) )
    return 0;
  result = 1;
  if ( BYTE6(Physics[21].residencyQuery.index) == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?PlayerBehavior_Lean_IsLeaning@idPlayer@@QBA_N_N@Z
// EA  : 0x82E45E90
// RVA : 0x00E45E90
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_Lean_IsLeaning(idPlayer *this, bool bAny)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idPlayer::idPlayerBehaviorLeanState_t state; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  if ( (*(_BYTE *)(v5 + 47032) & 0x20) != 0 )
    return false;
  state = this->behaviors.lean.state;
  if ( bAny )
    return state != LEAN_STATE_NONE;
  else
    return (_cntlzw(state - 1) & 0x20) != 0;
}


// ========================================================================
// ?PlayerBehavior_Lean_ShouldEndLean@idPlayer@@QBA?AW4idPlayerBehaviorLeanState_t@1@XZ
// EA  : 0x82E45F38
// RVA : 0x00E45F38
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Lean_ShouldEndLean(idPlayer *this)
{
  char v2; // r28
  int v3; // r29
  idPresentable *presentable; // r3
  int v5; // r3
  __int64 v6; // r9
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3

  v2 = 0;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Lean_CanLean(this) == 0 || this->behaviors.lean.endLean )
    goto LABEL_17;
  v3 = idPlayer::GetUCmdTracker1(this) + 68;
  presentable = this->presentable;
  v5 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
  HIDWORD(v6) = *(_BYTE *)(v5 + 48520) & 3;
  if ( (*(_BYTE *)(v5 + 48520) & 3) == 0 || (LODWORD(v6) = *(char *)(v3 + 7), __fabs((float)v6) <= 0.1) )
  {
    v7 = this->presentable;
    v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
    if ( (*(_BYTE *)(v8 + 48520) & 0xC) == 0 || (LODWORD(v6) = *(char *)(v3 + 6), __fabs((float)v6) <= 0.1) )
    {
      v9 = this->presentable;
      v10 = v9 != nullptr ? (int)v9->GetPlayerInterface_2(this: v9) : 0;
      if ( (*(_BYTE *)(v10 + 48520) & 0x10) == 0 )
LABEL_17:
        v2 = 1;
    }
  }
  return v2 == 0 ? 0 : 3;
}


// ========================================================================
// ?PlayerBehavior_Lean_GetHandsOffsetScale@idPlayer@@QAAXAAVidVec2@@@Z
// EA  : 0x82E46090
// RVA : 0x00E46090
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_GetHandsOffsetScale(
        idPlayer *this,
        idVec2 *scale,
        int a3,
        __int64 a4,
        __int64 a5)
{
  idPresentable *presentable; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idPresentable *v11; // r11
  int v12; // r30
  double v13; // fp31
  int v14; // r3
  double v15; // fp0
  double v16; // fp9
  double v17; // fp8
  double v20; // fp2
  double v21; // fp3
  double v22; // fp2
  idPhysics_Player *v23; // r3
  idCVar *v24; // r10
  idPhysics_Player *PhysicsObj; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = 0;
  if ( *(_BYTE *)(v8 + 48520) != 0 )
  {
    v9 = this->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    v11 = this->presentable;
    v12 = v10 + 46028;
    LODWORD(a4) = *(char *)(v10 + 46035);
    v13 = (float)((float)a4 * (float)0.0078740157);
    if ( v11 != nullptr )
      v14 = (int)v11->GetPlayerInterface_2(this: v11);
    else
      v14 = 0;
    if ( (*(_BYTE *)(v14 + 48520) & 0x10) != 0 )
    {
      v15 = 1.0;
    }
    else
    {
      LODWORD(a5) = *(char *)(v12 + 6);
      v15 = (float)((float)a5 * (float)0.0078740157);
    }
    v16 = __fabs(v13);
    v17 = __fabs(v15);
    scale->x = v16;
    scale->y = v17;
    _FP5 = (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f5, f6, f13 }
    v20 = __frsqrte(_FP4);
    v21 = (float)((float)v17
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)) * (float)0.5))
                                                                                        * (float)v20)
                                                                                - (float)1.5)
                                                                * (float)v20)
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v20
                                                                                        * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))
                                                                                                * (float)0.5))
                                                                                * (float)v20)
                                                                        - (float)1.5)
                                                        * (float)v20))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v20
                                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                                + (float)((float)v16 * (float)v16))
                                                                        * (float)0.5))
                                                        * (float)v20)
                                                - (float)1.5)
                                * (float)v20)));
    v22 = (float)((float)((float)v16
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)) * (float)0.5))
                                                                                                * (float)v20)
                                                                                        - (float)1.5)
                                                                        * (float)v20)
                                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                                + (float)((float)v16 * (float)v16))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v20
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)) * (float)0.5))
                                                                                        * (float)v20)
                                                                                - (float)1.5)
                                                                * (float)v20))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v20
                                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                                        + (float)((float)v16 * (float)v16))
                                                                                * (float)0.5))
                                                                * (float)v20)
                                                        - (float)1.5)
                                        * (float)v20)))
                * (float)v13);
    scale->x = v22;
    scale->y = (float)v21 * (float)v15;
    scale->x = (float)(this->behaviors.lean.maxLeanDistRight / pb_lean_OffsetLeftRight.valueFloat) * (float)v22;
    if ( v15 <= 0.0 )
    {
      PhysicsObj = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
      if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: PhysicsObj) != 0 )
        v24 = &pb_lean_crouch_OffsetDown;
      else
        v24 = &pb_lean_OffsetDown;
    }
    else
    {
      v23 = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
      if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: v23) != 0 )
        v24 = &pb_lean_crouch_OffsetUp;
      else
        v24 = &pb_lean_OffsetUp;
    }
    scale->y = (float)(this->behaviors.lean.maxLeanDistUp / v24->valueFloat) * scale->y;
  }
  else
  {
    *scale = vec2_origin;
  }
}


// ========================================================================
// ?PlayerBehavior_Lean_UpdateViewOffset@idPlayer@@QAA_NAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E462E0
// RVA : 0x00E462E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Lean_UpdateViewOffset(idPlayer *this, idVec3 *offsetTrans, idMat3 *offsetDir)
{
  double y; // fp10
  float x; // r9
  double z; // fp9
  float v7; // r6
  double v8; // fp8
  double v9; // fp11
  double v10; // fp5
  double v11; // fp1
  double v12; // fp0
  double v13; // fp10
  double v14; // fp6
  double v15; // fp13
  double v16; // fp11
  idMat3 v17; // [sp+50h] [-50h] BYREF

  if ( this->behaviors.lean.state == LEAN_STATE_NONE )
    return 0;
  y = this->behaviors.lean.forwardDir.y;
  x = this->behaviors.lean.leanOffset.p1.x;
  z = this->behaviors.lean.forwardDir.z;
  v7 = this->behaviors.lean.leanOffset.p1.z;
  v8 = this->behaviors.lean.forwardDir.x;
  v17.mat[0].y = this->behaviors.lean.leanOffset.p1.y;
  v9 = v17.mat[0].y;
  v17.mat[0].x = 0.0;
  v17.mat[0].z = v7;
  v10 = (float)(v17.mat[0].y * (float)0.0);
  v17.mat[0].y = 0.0;
  v11 = -(float)((float)((float)v8 * (float)0.0) - (float)((float)y * (float)0.0));
  v12 = -(float)((float)y - (float)((float)z * (float)0.0));
  v13 = -(float)((float)((float)z * (float)0.0) - (float)v8);
  offsetTrans->z = (float)v11 * x;
  offsetTrans->x = (float)v12 * x;
  offsetTrans->y = (float)v13 * x;
  v14 = (float)((float)v9 + (float)((float)v11 * x));
  offsetTrans->z = (float)v9 + (float)((float)v11 * x);
  offsetTrans->x = (float)v10 + (float)((float)v12 * x);
  offsetTrans->y = (float)v10 + (float)((float)v13 * x);
  v15 = (float)(this->behaviors.lean.forwardDir.z * v7);
  v16 = (float)(this->behaviors.lean.forwardDir.y * v7);
  offsetTrans->x = (float)((float)v10 + (float)((float)v12 * x)) + (float)(v7 * this->behaviors.lean.forwardDir.x);
  offsetTrans->z = (float)v14 + (float)v15;
  offsetTrans->y = (float)((float)v10 + (float)((float)v13 * x)) + (float)v16;
  v17.mat[0].z = this->behaviors.lean.rollOffset.p1.x;
  *offsetDir = *idAngles::ToMat3(this: (idAngles *)&v17.mat[1].y, result: &v17);
  return 1;
}


// ========================================================================
// ?PlayerBehavior_Lean_DebugHandle@idPlayer@@QAAXXZ
// EA  : 0x82E46460
// RVA : 0x00E46460
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_DebugHandle(idPlayer *this, int a2, __int64 a3)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  idPresentable *presentable; // r3
  int v10; // r3
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  idPhysics *Physics; // r3
  __int64 v15; // r8
  __int128 v16; // r6
  __int64 v17; // r10
  int v18; // [sp+8h] [-A8h]
  int v19; // [sp+8h] [-A8h]
  int v20; // [sp+8h] [-A8h]
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+Ch] [-A4h]
  int v24; // [sp+Ch] [-A4h]
  int v25; // [sp+Ch] [-A4h]
  int v26; // [sp+10h] [-A0h]
  int v27; // [sp+10h] [-A0h]
  int v28; // [sp+10h] [-A0h]
  int v29; // [sp+10h] [-A0h]
  int v30; // [sp+14h] [-9Ch]
  int v31; // [sp+14h] [-9Ch]
  int v32; // [sp+14h] [-9Ch]
  int v33; // [sp+14h] [-9Ch]
  int v34; // [sp+18h] [-98h]
  int v35; // [sp+18h] [-98h]
  int v36; // [sp+18h] [-98h]
  int v37; // [sp+18h] [-98h]
  int v38; // [sp+1Ch] [-94h]
  int v39; // [sp+1Ch] [-94h]
  int v40; // [sp+1Ch] [-94h]
  int v41; // [sp+1Ch] [-94h]
  double x; // [sp+20h] [-90h]
  double y; // [sp+28h] [-88h]
  double v44; // [sp+28h] [-88h]
  double z; // [sp+30h] [-80h]
  double v46; // [sp+30h] [-80h]
  idVec3 v47; // [sp+50h] [-60h] BYREF
  float v48[4]; // [sp+60h] [-50h] BYREF
  idMat3 v49; // [sp+70h] [-40h] BYREF

  if ( pb_lean_Debug.valueInteger != 0 )
  {
    LODWORD(v4) = &aAvSsobjectVCom[20];
    HIDWORD(v4) = &off_82350000;
    LODWORD(v5) = debugLeanStateNames;
    HIDWORD(v5) = 4 * this->behaviors.lean.state;
    HIDWORD(a3) = *(const char **)((char *)debugLeanStateNames + HIDWORD(v5));
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Lean State: %s",
      a3,
      a4: v5,
      a5: v4,
      a6: v18,
      a7: v22,
      a8: v26,
      a9: v30,
      a10: v34,
      a11: v38);
    LODWORD(v6) = off_82010000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: &byte_8200D768,
      a3: v6,
      a4: v8,
      a5: v7,
      a6: v19,
      a7: v23,
      a8: v27,
      a9: v31,
      a10: v35,
      a11: v39);
    presentable = this->presentable;
    if ( presentable != nullptr )
      v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = 0;
    idView::GetViewPos(this: (idView *)(v10 + 16224), origin: &v47, axis: &v49);
    z = v47.z;
    HIDWORD(v11) = LODWORD(z);
    y = v47.y;
    LODWORD(v12) = LODWORD(y);
    x = v47.x;
    HIDWORD(v12) = LODWORD(x);
    idPlayer::debugHUDPrintf(
      this,
      fmt: "View Pos   : x=%4.3f y=%4.3f z=%4.3f",
      a3: v12,
      a4: v11,
      a5: v13,
      a6: v20,
      a7: v24,
      a8: v28,
      a9: v32,
      a10: v36,
      a11: v40);
    Physics = idEntity::GetPhysics(this);
    Physics->GetLinearVelocity(this: (idPhysics *)v48, result: (idVec3 *)Physics, a3: 0);
    v46 = v48[2];
    HIDWORD(v15) = LODWORD(v46);
    v44 = v48[1];
    LODWORD(v16) = LODWORD(v44);
    *(double *)((char *)&v16 + 4) = v48[0];
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v48[0])),
      a3: v16,
      a4: v15,
      a5: v17,
      a6: v21,
      a7: v25,
      a8: v29,
      a9: v33,
      a10: v37,
      a11: v41);
  }
}


// ========================================================================
// ?PlayerBehavior_Lean_EndLean@idPlayer@@QAAXXZ
// EA  : 0x82E46590
// RVA : 0x00E46590
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_EndLean(idPlayer *this)
{
  idPlayer::idPlayerBehaviorLean *p_lean; // r31
  idPresentable *presentable; // r3
  int v3; // r3

  p_lean = &this->behaviors.lean;
  this->behaviors.lean.startLean = false;
  this->behaviors.lean.endLean = false;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  *(idVec3 *)(v3 + 45212) = vec3_origin;
  *(idMat3 *)(v3 + 45224) = mat3_identity;
  idPlayer::idPlayerBehaviorLean::Clear(this: p_lean);
}


// ========================================================================
// ?PlayerBehavior_Lean_HandleMovement@idPlayer@@QAAXXZ
// EA  : 0x82E46670
// RVA : 0x00E46670
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_HandleMovement(idPlayer *this, int a2, int a3, __int64 a4, __int64 a5)
{
  idPlayer::idPlayerBehaviorLean *p_lean; // r25
  double v7; // fp28
  double v8; // fp26
  double v9; // fp24
  double v10; // fp25
  idPresentable *presentable; // r3
  int v12; // r3
  idPresentable *v13; // r11
  int v14; // r27
  double v15; // fp31
  int v16; // r3
  double v17; // fp30
  idPresentable *v18; // r3
  int v19; // r3
  char v20; // r11
  idPresentable *v21; // r3
  unsigned __int8 v22; // r30
  int v23; // r3
  char v24; // r11
  idPresentable *v25; // r3
  char v26; // r28
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  bool v30; // r11
  idPresentable *v31; // r3
  bool v32; // r29
  int v33; // r3
  char v34; // r11
  int v35; // r31
  char v36; // r30
  double v39; // fp6
  long double v40; // fp2
  double v41; // fp31
  double v42; // fp29
  bool v43; // zf
  idPresentable *v44; // r3
  float *v45; // r3
  double v46; // fp0
  double valueFloat; // fp30
  double v48; // fp1
  double maxLeanDistUp; // fp0
  idPhysics_Player *PhysicsObj; // r3
  idCVar *v51; // r10
  double v52; // fp1
  double v53; // fp1
  float v54; // [sp+50h] [-90h]

  p_lean = &this->behaviors.lean;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  if ( this->behaviors.lean.state != LEAN_STATE_LEANING )
    goto LABEL_68;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v12 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v12 = 0;
  v13 = this->presentable;
  v14 = v12 + 46028;
  LODWORD(a4) = *(char *)(v12 + 46035);
  v15 = (float)((float)__fabs((float)a4) * (float)0.0078740157);
  if ( v13 != nullptr )
    v16 = (int)v13->GetPlayerInterface_2(this: v13);
  else
    v16 = 0;
  if ( (*(_BYTE *)(v16 + 48520) & 0x10) != 0 )
  {
    v17 = 1.0;
  }
  else
  {
    LODWORD(a5) = *(char *)(v14 + 6);
    v17 = (float)((float)__fabs((float)a5) * (float)0.0078740157);
  }
  v18 = this->presentable;
  if ( v18 != nullptr )
    v19 = (int)v18->GetPlayerInterface_2(this: v18);
  else
    v19 = 0;
  if ( (*(_BYTE *)(v19 + 48520) & 1) == 0 || (LODWORD(a5) = *(char *)(v14 + 7), v20 = 1, (float)a5 >= -0.1) )
    v20 = 0;
  v21 = this->presentable;
  v22 = v20;
  if ( v21 != nullptr )
    v23 = (int)v21->GetPlayerInterface_2(this: v21);
  else
    v23 = 0;
  if ( (*(_BYTE *)(v23 + 48520) & 2) == 0 || (LODWORD(a5) = *(char *)(v14 + 7), v24 = 1, (float)a5 <= 0.1) )
    v24 = 0;
  v25 = this->presentable;
  v26 = v24;
  if ( v25 != nullptr )
    v27 = (int)v25->GetPlayerInterface_2(this: v25);
  else
    v27 = 0;
  v30 = false;
  if ( (*(_BYTE *)(v27 + 48520) & 4) != 0 )
  {
    LODWORD(a5) = *(char *)(v14 + 6);
    if ( (float)a5 > 0.1
      || ((v28 = this->presentable) == nullptr ? (v29 = 0) : (v29 = (int)v28->GetPlayerInterface_2(this: v28)),
          (*(_BYTE *)(v29 + 48520) & 0x10) != 0) )
    {
      v30 = true;
    }
  }
  v31 = this->presentable;
  v32 = v30;
  if ( v31 != nullptr )
    v33 = (int)v31->GetPlayerInterface_2(this: v31);
  else
    v33 = 0;
  if ( (*(_BYTE *)(v33 + 48520) & 8) == 0 || (LODWORD(a5) = *(char *)(v14 + 6), v34 = 1, (float)a5 >= -0.1) )
    v34 = 0;
  v35 = v22;
  _FP9 = (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f0 }
  v39 = __frsqrte(_FP7);
  *((double *)&v40 + 1) = (float)((float)-(float)((float)((float)((float)v39
                                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                                + (float)((float)v15 * (float)v15))
                                                                        * (float)0.5))
                                                        * (float)v39)
                                                - (float)1.5)
                                * (float)v39);
  v42 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                              * (float)v39)
                                                                                      - (float)1.5)
                                                                      * (float)v39)
                                                              * (float)((float)((float)((float)v17 * (float)v17)
                                                                              + (float)((float)v15 * (float)v15))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v39
                                                                                              * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                      * (float)v39)
                                                                              - (float)1.5)
                                                              * (float)v39))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v39
                                                                      * (float)((float)((float)((float)v17 * (float)v17)
                                                                                      + (float)((float)v15 * (float)v15))
                                                                              * (float)0.5))
                                                              * (float)v39)
                                                      - (float)1.5)
                                      * (float)v39))
                      * (float)v17)
              * (float)v17);
  v41 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                              * (float)v39)
                                                                                      - (float)1.5)
                                                                      * (float)v39)
                                                              * (float)((float)((float)((float)v17 * (float)v17)
                                                                              + (float)((float)v15 * (float)v15))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v39
                                                                                              * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)v15 * (float)v15)) * (float)0.5))
                                                                                      * (float)v39)
                                                                              - (float)1.5)
                                                              * (float)v39))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v39
                                                                      * (float)((float)((float)((float)v17 * (float)v17)
                                                                                      + (float)((float)v15 * (float)v15))
                                                                              * (float)0.5))
                                                              * (float)v39)
                                                      - (float)1.5)
                                      * (float)v39))
                      * (float)v15)
              * (float)v15);
  v43 = v22 == 0;
  v36 = v34;
  if ( !v43 )
  {
    if ( v26 == 0 )
    {
      v8 = (float)(p_lean->maxLeanDistLeft * (float)v41);
      v10 = -(float)(pb_lean_RollOffset.valueFloat * (float)v41);
      goto LABEL_46;
    }
    if ( v35 != 0 )
    {
LABEL_48:
      v44 = this->presentable;
      if ( v44 != nullptr )
        v45 = (float *)v44->GetPlayerInterface_2(this: v44);
      else
        v45 = nullptr;
      v46 = (float)((float)(p_lean->forwardDir.x * v45[11639])
                  + (float)((float)(p_lean->forwardDir.y * v45[11640]) + (float)(p_lean->forwardDir.z * v45[11641])));
      if ( v46 < 0.0 && v26 != 0 || v46 > 0.0 && v35 != 0 )
      {
        *(double *)&v40 = __fnabs(v46);
        valueFloat = pb_lean_ViewConstraintYawLeft.valueFloat;
        v48 = idMath::ACos(a: v40);
        v7 = (float)((float)((float)__fabs((float)((float)((float)((float)v48 * idMath::M_RAD2DEG) - (float)90.0)
                                                 / (float)valueFloat))
                           * pb_lean_OffsetLeftRightForward.valueFloat)
                   * (float)v41);
        if ( v26 != 0 )
          v8 = (float)-(float)((float)(pb_lean_OffsetLeftRightForward.valueFloat
                                     * (float)((float)((float)((float)v48 * idMath::M_RAD2DEG) - (float)90.0)
                                             / (float)valueFloat))
                             - (float)v8);
        else
          v8 = (float)((float)(pb_lean_OffsetLeftRightForward.valueFloat
                             * (float)((float)((float)((float)v48 * idMath::M_RAD2DEG) - (float)90.0) / (float)valueFloat))
                     + (float)v8);
      }
      goto LABEL_58;
    }
  }
  if ( v26 != 0 )
  {
    v10 = (float)(pb_lean_RollOffset.valueFloat * (float)v41);
    v8 = -(float)(p_lean->maxLeanDistRight * (float)v41);
  }
LABEL_46:
  if ( v35 != 0 || v26 != 0 )
    goto LABEL_48;
LABEL_58:
  if ( !v32 )
    goto LABEL_62;
  if ( v36 == 0 )
  {
    maxLeanDistUp = p_lean->maxLeanDistUp;
LABEL_67:
    v9 = (float)((float)maxLeanDistUp * (float)v42);
    goto LABEL_68;
  }
  if ( !v32 )
  {
LABEL_62:
    if ( v36 != 0 )
    {
      PhysicsObj = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
      if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: PhysicsObj) != 0 )
        v51 = &pb_lean_crouch_OffsetDown;
      else
        v51 = &pb_lean_OffsetDown;
      maxLeanDistUp = -v51->valueFloat;
      goto LABEL_67;
    }
  }
LABEL_68:
  p_lean->leanOffset.p0.x = v8;
  p_lean->leanOffset.p0.y = v9;
  p_lean->leanOffset.p0.z = v7;
  v52 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec3>::Update(this: &p_lean->leanOffset, dt: v52);
  v54 = v10;
  p_lean->rollOffset.p0.x = v54;
  v53 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec1>::Update(this: &p_lean->rollOffset, dt: v53);
}


// ========================================================================
// ?PlayerBehavior_Lean_StartLean@idPlayer@@QAAXXZ
// EA  : 0x82E46BD8
// RVA : 0x00E46BD8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_StartLean(idPlayer *this)
{
  idPlayer::idPlayerBehaviorLean *p_lean; // r31
  idPresentable *presentable; // r3
  int v4; // r3
  idPhysics *Physics; // r3
  idPresentable *v6; // r3
  float *v7; // r3
  float *p_x; // r30
  double y; // fp9
  double v12; // fp2
  double v13; // fp5
  double v14; // fp3
  double v15; // fp2
  idPhysics *v16; // r3
  float *v17; // r3
  float v18; // r7
  float v19; // r10
  double x; // fp12
  double v21; // fp11
  int entityNumber; // r6
  double v23; // fp7
  double v24; // fp1
  double v25; // fp0
  double v26; // fp13
  double v27; // fp12
  idPresentable *v28; // r3
  int v29; // r3
  double v30; // fp10
  double v31; // fp9
  idPresentable *v32; // r3
  float *v33; // r3
  double v34; // fp13
  double v35; // fp12
  double v36; // fp10
  double v37; // fp9
  float v38; // r8
  float v39; // r7
  double valueFloat; // fp0
  float v41; // r6
  double v42; // fp28
  double v43; // fp29
  double v44; // fp27
  idPresentable *v45; // r3
  int v46; // r3
  idCVar *v47; // r10
  double v48; // fp12
  double v49; // fp11
  double v50; // fp10
  double v51; // fp9
  double v52; // fp8
  double z; // fp7
  int v54; // r6
  double v55; // fp13
  double v56; // fp11
  double v57; // fp9
  int v58; // r6
  double v59; // fp8
  double v60; // fp7
  double v61; // fp6
  int v62; // r6
  float v63[2]; // [sp+60h] [-160h] BYREF
  idVec3 v64; // [sp+68h] [-158h] BYREF
  idVec3 v65; // [sp+78h] [-148h] BYREF
  idVec3 v66; // [sp+88h] [-138h] BYREF
  idVec3 v67; // [sp+98h] [-128h] BYREF
  float v68[4]; // [sp+A8h] [-118h] BYREF
  idVec3 v69; // [sp+B8h] [-108h] BYREF
  idVec3 v70; // [sp+C8h] [-F8h] BYREF
  trace_t v71; // [sp+E0h] [-E0h] BYREF

  this->behaviors.lean.startLean = false;
  this->behaviors.lean.endLean = false;
  p_lean = &this->behaviors.lean;
  this->behaviors.lean.leanStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  this->behaviors.lean.leanOffset.restLength = 0.0;
  this->behaviors.lean.leanOffset.p0.z = 0.0;
  this->behaviors.lean.leanOffset.p0.y = 0.0;
  this->behaviors.lean.leanOffset.p0.x = 0.0;
  this->behaviors.lean.leanOffset.k = 1.0;
  this->behaviors.lean.leanOffset.m = 1.0;
  this->behaviors.lean.leanOffset.c = 2.0;
  this->behaviors.lean.leanOffset.p1.z = 0.0;
  this->behaviors.lean.leanOffset.p1.y = 0.0;
  this->behaviors.lean.leanOffset.p1.x = 0.0;
  this->behaviors.lean.leanOffset.vel.z = 0.0;
  this->behaviors.lean.leanOffset.vel.y = 0.0;
  this->behaviors.lean.leanOffset.vel.x = 0.0;
  this->behaviors.lean.leanOffset.maxSpeed = 0.0;
  this->behaviors.lean.leanOffset.pMin.z = 0.0;
  this->behaviors.lean.leanOffset.pMin.y = 0.0;
  this->behaviors.lean.leanOffset.pMin.x = 0.0;
  this->behaviors.lean.leanOffset.hasPMin = false;
  this->behaviors.lean.leanOffset.pMax.z = 0.0;
  this->behaviors.lean.leanOffset.pMax.y = 0.0;
  this->behaviors.lean.leanOffset.pMax.x = 0.0;
  this->behaviors.lean.leanOffset.hasPMax = false;
  idSpring<idVec3>::SetConstants(this: &p_lean->leanOffset, _k: pb_lean_LeanSpringK.valueFloat, _c: -1.0);
  this->behaviors.lean.leanOffset.p0.x = 0.0;
  this->behaviors.lean.leanOffset.p0.y = 0.0;
  this->behaviors.lean.leanOffset.p0.z = 0.0;
  this->behaviors.lean.rollOffset.hasPMin = false;
  this->behaviors.lean.rollOffset.restLength = 0.0;
  this->behaviors.lean.rollOffset.hasPMax = false;
  this->behaviors.lean.rollOffset.k = 1.0;
  this->behaviors.lean.rollOffset.m = 1.0;
  this->behaviors.lean.rollOffset.c = 2.0;
  this->behaviors.lean.rollOffset.p0.x = 0.0;
  this->behaviors.lean.rollOffset.p1.x = 0.0;
  this->behaviors.lean.rollOffset.vel.x = 0.0;
  this->behaviors.lean.rollOffset.maxSpeed = 0.0;
  this->behaviors.lean.rollOffset.pMin.x = 0.0;
  this->behaviors.lean.rollOffset.pMax.x = 0.0;
  idSpring<idVec1>::SetConstants(this: &p_lean->rollOffset, _k: pb_lean_LeanSpringK.valueFloat, _c: -1.0);
  this->behaviors.lean.rollOffset.p0.x = 0.0;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  *(idVec3 *)(v4 + 45212) = vec3_origin;
  *(idMat3 *)(v4 + 45224) = mat3_identity;
  Physics = idEntity::GetPhysics(this);
  v68[0] = 0.0;
  v68[1] = 0.0;
  v68[2] = 0.0;
  Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v68, a3: 0);
  v6 = this->presentable;
  if ( v6 != nullptr )
    v7 = (float *)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = nullptr;
  p_x = &p_lean->forwardDir.x;
  p_lean->forwardDir.x = v7[11636];
  p_lean->forwardDir.y = v7[11637];
  p_lean->forwardDir.z = v7[11638];
  p_lean->forwardDir.z = 0.0;
  y = p_lean->forwardDir.y;
  _FP5 = (float)((float)((float)((float)0.0 * (float)0.0)
                       + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x)
                               + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v12 = __frsqrte(_FP3);
  v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12)
                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                              + (float)((float)(p_lean->forwardDir.x
                                                                              * p_lean->forwardDir.x)
                                                                      + (float)(p_lean->forwardDir.y
                                                                              * p_lean->forwardDir.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v12
                                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                                              + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v12)
                                                              - (float)1.5)
                                              * (float)v12))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v12
                                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                      + (float)((float)(p_lean->forwardDir.x
                                                                                      * p_lean->forwardDir.x)
                                                                              + (float)(p_lean->forwardDir.y
                                                                                      * p_lean->forwardDir.y)))
                                                              * (float)0.5))
                                              * (float)v12)
                                      - (float)1.5)
                      * (float)v12));
  v14 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y))) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                      * (float)v12)
                                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                                              + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y))) * (float)0.5)) * (float)v12)
                                                                                              - (float)1.5)
                                                                              * (float)v12))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v12
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12))
                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                      + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x)
                                                              + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                              * (float)0.5))
                              * (float)v13)
                      - (float)1.5);
  v15 = (float)((float)v14
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                              * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y))) * (float)0.5))
                                                                                      * (float)v12)
                                                                              - (float)1.5)
                                                              * (float)v12)
                                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                      + (float)((float)(p_lean->forwardDir.x
                                                                                      * p_lean->forwardDir.x)
                                                                              + (float)(p_lean->forwardDir.y
                                                                                      * p_lean->forwardDir.y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v12
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_lean->forwardDir.x * p_lean->forwardDir.x) + (float)(p_lean->forwardDir.y * p_lean->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v12
                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                              + (float)((float)(p_lean->forwardDir.x
                                                                                              * p_lean->forwardDir.x)
                                                                                      + (float)(p_lean->forwardDir.y
                                                                                              * p_lean->forwardDir.y)))
                                                                      * (float)0.5))
                                                      * (float)v12)
                                              - (float)1.5)
                              * (float)v12)));
  p_lean->forwardDir.x = p_lean->forwardDir.x * (float)v15;
  p_lean->forwardDir.y = (float)y * (float)v15;
  p_lean->forwardDir.z = (float)0.0 * (float)v15;
  v16 = idEntity::GetPhysics(this);
  v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
  v18 = v17[2];
  v19 = *v17;
  x = p_lean->forwardDir.x;
  v21 = p_lean->forwardDir.y;
  entityNumber = this->entityNumber;
  v23 = (float)(p_lean->forwardDir.z * (float)30.0);
  v65.y = v17[1];
  v65.x = v19;
  v63[0] = 0.0;
  v65.z = v18 + (float)25.0;
  v66.x = v19 + (float)((float)x * (float)30.0);
  v66.y = v65.y + (float)((float)v21 * (float)30.0);
  v66.z = (float)v23 + v65.z;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v65,
                          endPos: &v66,
                          blockDist: v63,
                          entityNum: entityNumber,
                          bDebug: false,
                          tr: &v71,
                          contentMask: 107529) != 0
    && v71.fraction < 1.0 )
  {
    v25 = -v71.c.normal.z;
    v26 = -v71.c.normal.x;
    v27 = -v71.c.normal.y;
    if ( (float)((float)(p_lean->forwardDir.y * (float)v27)
               + (float)((float)(p_lean->forwardDir.x * (float)v26) + (float)(p_lean->forwardDir.z * (float)v25))) > 0.85000002 )
    {
      *p_x = v26;
      p_lean->forwardDir.y = v27;
      p_lean->forwardDir.z = v25;
      p_lean->forwardDir.z = 0.0;
      v24 = idVec3::NormalizeFast(this: &p_lean->forwardDir);
    }
  }
  v28 = this->presentable;
  if ( v28 != nullptr )
    v29 = ((int (__fastcall *)(idPresentable *, double))v28->GetPlayerInterface_2)(a1: v28, a2: v24);
  else
    v29 = 0;
  if ( (unsigned __int8)idEnvironmentAnalyzer::GetWallNormal(
                          this: (idEnvironmentAnalyzer *)(v29 + 47840),
                          res: &p_lean->forwardDir) != 0 )
  {
    v30 = -p_lean->forwardDir.y;
    v31 = -p_lean->forwardDir.z;
    *p_x = -*p_x;
    p_lean->forwardDir.y = v30;
    p_lean->forwardDir.z = v31;
  }
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = (float *)v32->GetPlayerInterface_2(this: v32);
  else
    v33 = nullptr;
  v34 = p_lean->forwardDir.y;
  v35 = *p_x;
  v36 = (float)(p_lean->forwardDir.z * (float)0.0);
  v37 = (float)(p_lean->forwardDir.y * (float)0.0);
  v38 = v33[11633];
  v39 = v33[11634];
  valueFloat = pb_lean_OffsetLeftRight.valueFloat;
  v41 = v33[11635];
  p_lean->maxLeanDistLeft = pb_lean_OffsetLeftRight.valueFloat;
  p_lean->maxLeanDistRight = valueFloat;
  v64.x = v38;
  v64.y = v39;
  v42 = (float)((float)v34 - (float)v36);
  v64.z = v41;
  v43 = (float)((float)((float)v35 * (float)0.0) - (float)v37);
  v44 = (float)((float)v36 - (float)v35);
  v45 = this->presentable;
  if ( v45 != nullptr )
    v46 = (int)v45->GetPlayerInterface_2(this: v45);
  else
    v46 = 0;
  if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v46 + 36264)) != 0 )
    v47 = &pb_lean_crouch_OffsetUp;
  else
    v47 = &pb_lean_OffsetUp;
  v48 = (float)(p_lean->maxLeanDistRight * (float)v42);
  v49 = v64.x;
  v50 = (float)((float)v44 * p_lean->maxLeanDistRight);
  v51 = v64.y;
  v52 = (float)((float)v43 * p_lean->maxLeanDistRight);
  z = v64.z;
  p_lean->maxLeanDistUp = v47->valueFloat;
  v63[0] = 0.0;
  v54 = this->entityNumber;
  v70.x = (float)((float)v48 * (float)1.1) + (float)v49;
  v70.y = (float)v51 + (float)((float)v50 * (float)1.1);
  v70.z = (float)z + (float)((float)v52 * (float)1.1);
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v64,
                          endPos: &v70,
                          blockDist: v63,
                          entityNum: v54,
                          bDebug: false,
                          tr: &v71,
                          contentMask: 107529) != 0 )
    p_lean->maxLeanDistRight = v63[0] * (float)0.5;
  v55 = (float)(p_lean->maxLeanDistLeft * (float)v42);
  v56 = (float)((float)v44 * p_lean->maxLeanDistLeft);
  v57 = (float)((float)v43 * p_lean->maxLeanDistLeft);
  v63[0] = 0.0;
  v58 = this->entityNumber;
  v67.x = v64.x - (float)((float)v55 * (float)1.1);
  v67.y = v64.y - (float)((float)v56 * (float)1.1);
  v67.z = v64.z - (float)((float)v57 * (float)1.1);
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v64,
                          endPos: &v67,
                          blockDist: v63,
                          entityNum: v58,
                          bDebug: false,
                          tr: &v71,
                          contentMask: 107529) != 0 )
    p_lean->maxLeanDistLeft = v63[0] * (float)0.5;
  v59 = (float)(p_lean->maxLeanDistUp * vec3_up.x);
  v60 = (float)(p_lean->maxLeanDistUp * vec3_up.y);
  v61 = (float)(p_lean->maxLeanDistUp * vec3_up.z);
  v63[0] = 0.0;
  v62 = this->entityNumber;
  v69.x = (float)((float)v59 * (float)1.1) + v64.x;
  v69.y = (float)((float)v60 * (float)1.1) + v64.y;
  v69.z = (float)((float)v61 * (float)1.1) + v64.z;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v64,
                          endPos: &v69,
                          blockDist: v63,
                          entityNum: v62,
                          bDebug: false,
                          tr: &v71,
                          contentMask: 107529) != 0 )
    p_lean->maxLeanDistUp = v63[0] * (float)0.5;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraintExplicit(
    this,
    constrain: true,
    heading: (idAngles *)&p_lean->forwardDir,
    minDeltaPitch: pb_lean_ViewConstraintPitchUp.valueFloat,
    maxDeltaPitch: pb_lean_ViewConstraintPitchDown.valueFloat,
    minDeltaYaw: pb_lean_ViewConstraintYawRight.valueFloat,
    maxDeltaYaw: pb_lean_ViewConstraintYawLeft.valueFloat,
    minDeltaRoll: 0.0,
    maxDeltaRoll: 0.0,
    rate: pb_lean_ConstraintBlend.valueFloat);
}


// ========================================================================
// ?PlayerBehavior_Lean_SetState@idPlayer@@QAAXW4idPlayerBehaviorLeanState_t@1@@Z
// EA  : 0x82E47300
// RVA : 0x00E47300
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_SetState(idPlayer *this, idPlayer::idPlayerBehaviorLeanState_t state)
{
  idPlayer::idPlayerBehaviorLeanState_t v2; // r31
  idPlayer::idPlayerBehaviorLean *p_lean; // r30
  const char *v4; // r31
  int v5; // r3

  v2 = state;
  p_lean = &this->behaviors.lean;
  switch ( state )
  {
    case LEAN_STATE_LEANING:
      idPlayer::PlayerBehavior_Lean_StartLean(this);
      break;
    case LEAN_STATE_RESTART:
      v2 = LEAN_STATE_LEANING;
      idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraintExplicit(
        this,
        constrain: true,
        heading: (idAngles *)&this->behaviors.lean.forwardDir,
        minDeltaPitch: pb_lean_ViewConstraintPitchUp.valueFloat,
        maxDeltaPitch: pb_lean_ViewConstraintPitchDown.valueFloat,
        minDeltaYaw: pb_lean_ViewConstraintYawRight.valueFloat,
        maxDeltaYaw: pb_lean_ViewConstraintYawLeft.valueFloat,
        minDeltaRoll: 0.0,
        maxDeltaRoll: 0.0,
        rate: pb_lean_ConstraintBlend.valueFloat);
      break;
    case LEAN_STATE_END:
      idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
        this,
        constrain: false,
        heading: nullptr,
        maxDeltaPitch: 0.0,
        maxDeltaYaw: 0.0,
        rate: 0.0);
      break;
    default:
      break;
  }
  p_lean->state = v2;
  if ( pb_lean_DebugTraceStates.valueInteger != 0 )
  {
    v4 = debugLeanStateNames[v2];
    v5 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)%s - Setting sprint slide state <%s>\n", v5, "idPlayer::PlayerBehavior_Lean_SetState", v4);
  }
}


// ========================================================================
// ?PlayerBehavior_Lean_Update@idPlayer@@QAAXXZ
// EA  : 0x82E47438
// RVA : 0x00E47438
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_Update(idPlayer *this)
{
  idPlayer::idPlayerBehaviorLean *p_lean; // r30
  unsigned __int64 v3; // r6
  const char *v4; // r7
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idPlayer::idPlayerBehaviorLeanState_t ShouldEndLean; // r4
  idGameLocal *v9; // r3
  double v10; // fp1
  double v11; // fp1
  const char *v12; // r30
  int v13; // r3
  int UCmdTracker1; // r29
  idPresentable *presentable; // r3
  int v16; // r3
  __int64 v17; // r9
  idPresentable *v18; // r3
  int v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  int v22; // r29
  idPresentable *v23; // r3
  int v24; // r3
  __int64 v25; // r9
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idPLogScope v30[2]; // [sp+58h] [-48h] BYREF

  p_lean = &this->behaviors.lean;
  if ( !common->IsMultiplayer(this: common) )
  {
    RD_EventBegin(name: "idPlayer::PlayerBehavior_Lean_Update");
    LODWORD(v3) = "idPlayer::PlayerBehavior_Lean_Update";
    HIDWORD(v3) = 2;
    idPLogScope::idPLogScope(this: v30, pl: &pLog, gMask: v3, label: v4);
    if ( p_lean->state != LEAN_STATE_NONE )
    {
      if ( p_lean->state != LEAN_STATE_LEANING )
      {
        if ( p_lean->state == LEAN_STATE_END )
        {
          p_lean->leanOffset.p0.x = 0.0;
          v9 = gameLocal;
          p_lean->leanOffset.p0.y = 0.0;
          p_lean->leanOffset.p0.z = 0.0;
          v10 = ((double (__fastcall *)(idGameLocal *, int))v9->GetGameSecPerFrame)(a1: v9, a2: 1);
          idSpring<idVec3>::Update(this: &p_lean->leanOffset, dt: v10);
          p_lean->rollOffset.p0.x = 0.0;
          v11 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
          idSpring<idVec1>::Update(this: &p_lean->rollOffset, dt: v11);
          if ( (float)((float)(p_lean->leanOffset.p1.z * p_lean->leanOffset.p1.z)
                     + (float)((float)(p_lean->leanOffset.p1.x * p_lean->leanOffset.p1.x)
                             + (float)(p_lean->leanOffset.p1.y * p_lean->leanOffset.p1.y))) < 0.000099999997 )
          {
            idPlayer::PlayerBehavior_Lean_EndLean(this);
            p_lean->state = LEAN_STATE_NONE;
            if ( pb_lean_DebugTraceStates.valueInteger != 0 )
            {
              v12 = debugLeanStateNames[0];
              v13 = gameLocal->GetGameFrame(this: gameLocal);
              idLib::Printf(
                fmt: "(%d)%s - Setting sprint slide state <%s>\n",
                v13,
                "idPlayer::PlayerBehavior_Lean_SetState",
                v12);
            }
            goto LABEL_43;
          }
          UCmdTracker1 = idPlayer::GetUCmdTracker1(this);
          presentable = this->presentable;
          if ( presentable != nullptr )
            v16 = (int)presentable->GetPlayerInterface_2(this: presentable);
          else
            v16 = 0;
          HIDWORD(v17) = *(_BYTE *)(v16 + 48520) & 3;
          if ( (*(_BYTE *)(v16 + 48520) & 3) == 0
            || (LODWORD(v17) = *(char *)(UCmdTracker1 + 75), __fabs((float)v17) <= 0.1) )
          {
            v18 = this->presentable;
            v19 = v18 != nullptr ? (int)v18->GetPlayerInterface_2(this: v18) : 0;
            if ( (*(_BYTE *)(v19 + 48520) & 0xC) == 0
              || (LODWORD(v17) = *(char *)(UCmdTracker1 + 74), __fabs((float)v17) <= 0.1) )
            {
              v20 = this->presentable;
              v21 = v20 != nullptr ? (int)v20->GetPlayerInterface_2(this: v20) : 0;
              if ( (*(_BYTE *)(v21 + 48520) & 0x10) == 0 )
                goto LABEL_43;
            }
          }
          ShouldEndLean = LEAN_STATE_RESTART;
          goto LABEL_42;
        }
LABEL_43:
        idPlayer::PlayerBehavior_Lean_DebugHandle(this, a2: ShouldEndLean, a3: v7);
        idPLogScope::~idPLogScope(this: v30);
LABEL_45:
        RD_EventEnd();
        return;
      }
      idPlayer::PlayerBehavior_Lean_HandleMovement(this, a2: ShouldEndLean, a3: SHIDWORD(v7), a4: v6, a5: v5);
      ShouldEndLean = idPlayer::PlayerBehavior_Lean_ShouldEndLean(this);
      if ( ShouldEndLean == LEAN_STATE_NONE )
        goto LABEL_43;
    }
    else
    {
      v22 = idPlayer::GetUCmdTracker1(this);
      if ( (unsigned __int8)idPlayer::PlayerBehavior_Lean_CanLean(this) == 0 )
        goto _M491048_3;
      if ( !p_lean->startLean )
      {
        v23 = this->presentable;
        v24 = v23 != nullptr ? (int)v23->GetPlayerInterface_2(this: v23) : 0;
        HIDWORD(v25) = *(_BYTE *)(v24 + 48520) & 3;
        if ( (*(_BYTE *)(v24 + 48520) & 3) == 0 || (LODWORD(v25) = *(char *)(v22 + 75), __fabs((float)v25) <= 0.1) )
        {
          v26 = this->presentable;
          v27 = v26 != nullptr ? (int)v26->GetPlayerInterface_2(this: v26) : 0;
          if ( (*(_BYTE *)(v27 + 48520) & 0xC) == 0 || (LODWORD(v25) = *(char *)(v22 + 74), __fabs((float)v25) <= 0.1) )
          {
            v28 = this->presentable;
            v29 = v28 != nullptr ? (int)v28->GetPlayerInterface_2(this: v28) : 0;
            if ( (*(_BYTE *)(v29 + 48520) & 0x10) == 0 )
            {
_M491048_3:
              idPLogScope::~idPLogScope(this: v30);
              goto LABEL_45;
            }
          }
        }
      }
      ShouldEndLean = LEAN_STATE_LEANING;
    }
LABEL_42:
    idPlayer::PlayerBehavior_Lean_SetState(this, state: ShouldEndLean);
    goto LABEL_43;
  }
}


// ========================================================================
// __unwind$490774_1
// EA  : 0x82E47838
// RVA : 0x00E47838
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void _unwind_490774_1()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$490775_1
// EA  : 0x82E47860
// RVA : 0x00E47860
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void _unwind_490775_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?PlayerBehavior_Lean_HandleEvent@idPlayer@@QAAXW4idPlayerBehaviorEvent_t@@@Z
// EA  : 0x82E47888
// RVA : 0x00E47888
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_HandleEvent(idPlayer *this, idPlayerBehaviorEvent_t event)
{
  if ( event == PBE_PHYSICS_UPDATED && pb_lean_UpdateAfterPhysics.valueInteger != 0 )
    idPlayer::PlayerBehavior_Lean_Update(this);
}


// ========================================================================
// ?PlayerBehavior_Lean_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E478B0
// RVA : 0x00E478B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Lean_Handle(idPlayer *this)
{
  if ( pb_lean_UpdateAfterPhysics.valueInteger == 0 )
    idPlayer::PlayerBehavior_Lean_Update(this);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_Enable''
// EA  : 0x8338D6A0
// RVA : 0x0138D6A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_Enable__()
{
  idCVar::idCVar(
    this: &pb_lean_Enable,
    name: "pb_lean_Enable",
    value: "1",
    flags: 1,
    description: "Enable player contextual lean behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_Enable__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_Debug''
// EA  : 0x8338D6F8
// RVA : 0x0138D6F8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_Debug__()
{
  idCVar::idCVar(
    this: &pb_lean_Debug,
    name: "pb_lean_Debug",
    value: "0",
    flags: 1,
    description: "Debug player contextual lean behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_Debug__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_DebugTraceStates''
// EA  : 0x8338D750
// RVA : 0x0138D750
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_DebugTraceStates__()
{
  idCVar::idCVar(
    this: &pb_lean_DebugTraceStates,
    name: "pb_lean_DebugTraceStates",
    value: "0",
    flags: 1,
    description: "Debug player contextual lean behavior states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_DebugTraceStates__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_OffsetLeftRight''
// EA  : 0x8338D7A8
// RVA : 0x0138D7A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_OffsetLeftRight__()
{
  idCVar::idCVar(
    this: &pb_lean_OffsetLeftRight,
    name: "pb_lean_OffsetLeftRight",
    value: "20.0",
    flags: 4,
    description: "Offset in left/right direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_OffsetLeftRight__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_OffsetLeftRightForward''
// EA  : 0x8338D800
// RVA : 0x0138D800
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_OffsetLeftRightForward__()
{
  idCVar::idCVar(
    this: &pb_lean_OffsetLeftRightForward,
    name: "pb_lean_OffsetLeftRightForward",
    value: "15.0",
    flags: 4,
    description: "Offset in forward dir when having left/right direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_OffsetLeftRightForward__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_OffsetUp''
// EA  : 0x8338D858
// RVA : 0x0138D858
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_OffsetUp__()
{
  idCVar::idCVar(
    this: &pb_lean_OffsetUp,
    name: "pb_lean_OffsetUp",
    value: "10.0",
    flags: 4,
    description: "Offset in up direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_OffsetUp__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_OffsetDown''
// EA  : 0x8338D8B0
// RVA : 0x0138D8B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_OffsetDown__()
{
  idCVar::idCVar(
    this: &pb_lean_OffsetDown,
    name: "pb_lean_OffsetDown",
    value: "71.0",
    flags: 4,
    description: "Offset in down direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_OffsetDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_crouch_OffsetDown''
// EA  : 0x8338D908
// RVA : 0x0138D908
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_crouch_OffsetDown__()
{
  idCVar::idCVar(
    this: &pb_lean_crouch_OffsetDown,
    name: "pb_lean_Crouch_OffsetDown",
    value: "30.0",
    flags: 4,
    description: "Offset in down direction when crouching",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_crouch_OffsetDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_crouch_OffsetUp''
// EA  : 0x8338D960
// RVA : 0x0138D960
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_crouch_OffsetUp__()
{
  idCVar::idCVar(
    this: &pb_lean_crouch_OffsetUp,
    name: "pb_lean_crouch_OffsetUp",
    value: "40.0",
    flags: 4,
    description: "Offset in up direction when crouching",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_crouch_OffsetUp__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_RollOffset''
// EA  : 0x8338D9B8
// RVA : 0x0138D9B8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_RollOffset__()
{
  idCVar::idCVar(
    this: &pb_lean_RollOffset,
    name: "pb_lean_RollOffset",
    value: "15.0",
    flags: 4,
    description: "Roll offset in when leaning left/right",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_RollOffset__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_LeanSpringK''
// EA  : 0x8338DA10
// RVA : 0x0138DA10
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_LeanSpringK__()
{
  idCVar::idCVar(
    this: &pb_lean_LeanSpringK,
    name: "pb_lean_LeanSpringK",
    value: "500.0",
    flags: 4,
    description: "Spring constant for the offset",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_LeanSpringK__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_UpdateAfterPhysics''
// EA  : 0x8338DA68
// RVA : 0x0138DA68
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_UpdateAfterPhysics__()
{
  idCVar::idCVar(
    this: &pb_lean_UpdateAfterPhysics,
    name: "pb_lean_UpdateAfterPhysics",
    value: "1",
    flags: 1,
    description: "If this is true the slide update happens after the physics update",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_UpdateAfterPhysics__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_ViewConstraintYawLeft''
// EA  : 0x8338DAC0
// RVA : 0x0138DAC0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_ViewConstraintYawLeft__()
{
  idCVar::idCVar(
    this: &pb_lean_ViewConstraintYawLeft,
    name: "pb_lean_ViewConstraintYawLeft",
    value: "60.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_ViewConstraintYawLeft__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_ViewConstraintYawRight''
// EA  : 0x8338DB18
// RVA : 0x0138DB18
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_ViewConstraintYawRight__()
{
  idCVar::idCVar(
    this: &pb_lean_ViewConstraintYawRight,
    name: "pb_lean_ViewConstraintYawRight",
    value: "60.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_ViewConstraintYawRight__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_ViewConstraintPitchUp''
// EA  : 0x8338DB70
// RVA : 0x0138DB70
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_ViewConstraintPitchUp__()
{
  idCVar::idCVar(
    this: &pb_lean_ViewConstraintPitchUp,
    name: "pb_lean_ViewConstraintPitchUp",
    value: "60.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_ViewConstraintPitchUp__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_ViewConstraintPitchDown''
// EA  : 0x8338DBC8
// RVA : 0x0138DBC8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_ViewConstraintPitchDown__()
{
  idCVar::idCVar(
    this: &pb_lean_ViewConstraintPitchDown,
    name: "pb_lean_ViewConstraintPitchDown",
    value: "50.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_ViewConstraintPitchDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_lean_ConstraintBlend''
// EA  : 0x8338DC20
// RVA : 0x0138DC20
// PDB : w:\tech5\tungsten\game\player\playerbehaviorlean.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_lean_ConstraintBlend__()
{
  idCVar::idCVar(
    this: &pb_lean_ConstraintBlend,
    name: "pb_lean_Tweak1",
    value: "400.0",
    flags: 4,
    description: "How fast the angles are constrained",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_lean_ConstraintBlend__);
}

