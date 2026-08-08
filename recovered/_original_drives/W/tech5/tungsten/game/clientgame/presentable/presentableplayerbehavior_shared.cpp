
// ========================================================================
// ?PresentablePlayerBehavior_PostEvent@idPresentablePlayer@@QAAXW4idPlayerBehaviorEvent_t@@@Z
// EA  : 0x82B7FE18
// RVA : 0x00B7FE18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayerbehavior_shared.cpp
// ========================================================================

void __fastcall idPresentablePlayer::PresentablePlayerBehavior_PostEvent(
        idPresentablePlayer *this,
        idPlayerBehaviorEvent_t event)
{
  if ( common->IsServer(this: common) )
    idPlayer::PlayerBehavior_PostEvent(this: (idPlayer *)this->entity, event);
}


// ========================================================================
// ?PlayerBehavior_Shared_CheckBlocked@idPresentablePlayer@@SA_NABVidVec3@@0AAMH_NPAUtrace_t@@H@Z
// EA  : 0x82B7FE80
// RVA : 0x00B7FE80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayerbehavior_shared.cpp
// ========================================================================

int __fastcall idPresentablePlayer::PlayerBehavior_Shared_CheckBlocked(
        const idVec3 *startPos,
        const idVec3 *endPos,
        float *blockDist,
        int entityNum,
        bool bDebug,
        trace_t *tr,
        int contentMask)
{
  trace_t *v11; // r29
  int v12; // r27
  double v13; // fp12
  double v14; // fp9
  float x; // r8
  double v16; // fp6
  float z; // r4
  double v18; // fp31
  double v19; // fp31
  double y; // fp30
  double v21; // fp29
  double v22; // fp11
  double v23; // fp9
  double v24; // fp2
  double v25; // fp0
  idRenderWorld *renderWorld; // r26
  idRenderWorld *v27; // r28
  idRenderWorld *v28; // r31
  int GameMsPerFrame; // r3
  idRenderWorld *v30; // r30
  int v32; // [sp+8h] [-188h]
  bool v33; // [sp+Fh] [-181h]
  const char *v34; // [sp+10h] [-180h]
  int v35; // [sp+14h] [-17Ch]
  int v36; // [sp+18h] [-178h]
  int v37; // [sp+1Ch] [-174h]
  int v38; // [sp+20h] [-170h]
  int v39; // [sp+24h] [-16Ch]
  int v40; // [sp+28h] [-168h]
  int v41; // [sp+2Ch] [-164h]
  int v42; // [sp+30h] [-160h]
  int v43; // [sp+34h] [-15Ch]
  int v44; // [sp+38h] [-158h]
  int v45; // [sp+3Ch] [-154h]
  int v46; // [sp+40h] [-150h]
  int v47; // [sp+44h] [-14Ch]
  int v48; // [sp+48h] [-148h]
  int v49; // [sp+4Ch] [-144h]
  int v50; // [sp+50h] [-140h]
  int v51; // [sp+58h] [-138h]
  int v52; // [sp+60h] [-130h]
  idVec3 v53; // [sp+70h] [-120h] BYREF
  float v54; // [sp+80h] [-110h] BYREF
  float v55; // [sp+84h] [-10Ch]
  float v56; // [sp+88h] [-108h]
  idVec3 v57; // [sp+90h] [-100h] BYREF
  float v58[4]; // [sp+A0h] [-F0h] BYREF
  char v59; // [sp+B0h] [-E0h] BYREF

  v11 = tr;
  v12 = 0;
  if ( tr == nullptr )
    v11 = (trace_t *)&v59;
  v13 = (float)(endPos->z - startPos->z);
  v14 = (float)(endPos->y - startPos->y);
  x = startPos->x;
  v16 = (float)(endPos->x - startPos->x);
  z = startPos->z;
  v57.y = startPos->y;
  v57.x = x;
  v57.z = z;
  v18 = __fsqrts((float)((float)((float)v16 * (float)v16)
                       + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))));
  if ( pb_BlockCheckUse8x8.valueInteger != 0 )
    idClip::Translation(
      this: (idClip *)&v53,
      result: &clientGame->clip,
      a3: v11,
      start: &v57,
      end: endPos,
      clipModel: clientGame->clip.clip8x8,
      startAxis: &mat3_identity,
      clipMask: contentMask,
      passEntityNumber: v32,
      moveClipModel: v33,
      userName: v34,
      a12: v35,
      a13: v36,
      a14: v37,
      a15: v38,
      a16: v39,
      a17: v40,
      a18: v41,
      a19: v42,
      a20: v43,
      a21: v44,
      a22: v45,
      a23: v46,
      a24: v47,
      a25: v48,
      a26: v49,
      a27: v50,
      a28: entityNum,
      a29: v51,
      a30: false,
      a31: v52,
      a32: 0);
  else
    idClip::Translation(
      this: (idClip *)&v53,
      result: &clientGame->clip,
      a3: v11,
      start: &v57,
      end: endPos,
      clipModel: nullptr,
      startAxis: &mat3_identity,
      clipMask: contentMask,
      passEntityNumber: v32,
      moveClipModel: v33,
      userName: v34,
      a12: v35,
      a13: v36,
      a14: v37,
      a15: v38,
      a16: v39,
      a17: v40,
      a18: v41,
      a19: v42,
      a20: v43,
      a21: v44,
      a22: v45,
      a23: v46,
      a24: v47,
      a25: v48,
      a26: v49,
      a27: v50,
      a28: entityNum,
      a29: v51,
      a30: false,
      a31: v52,
      a32: 0);
  if ( v11->fraction >= 1.0 )
  {
    *blockDist = v18;
  }
  else
  {
    *blockDist = v11->fraction * (float)v18;
    v12 = 1;
  }
  if ( bDebug )
  {
    if ( (_BYTE)v12 != 0 )
    {
      v19 = startPos->x;
      y = startPos->y;
      v21 = startPos->z;
      v22 = (float)(endPos->y - startPos->y);
      v23 = (float)(endPos->z - startPos->z);
      v53.x = endPos->x - startPos->x;
      v53.y = v22;
      v53.z = v23;
      idVec3::NormalizeFast(this: &v53);
      v24 = (float)(v53.z * *blockDist);
      v25 = (float)((float)y + (float)(v53.y * *blockDist));
      v54 = (float)v19 + (float)(v53.x * *blockDist);
      v55 = v25;
      v56 = (float)v21 + (float)v24;
      renderWorld = clientGame->renderWorld;
      idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))renderWorld->DebugArrow)(
        a1: renderWorld,
        a2: &idColor::colorGreen,
        a3: startPos,
        a4: &v54,
        a5: 4.0);
      v27 = clientGame->renderWorld;
      idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, const idVec3 *, double))v27->DebugArrow)(
        a1: v27,
        a2: &idColor::colorRed,
        a3: &v54,
        a4: endPos,
        a5: 4.0);
      v28 = clientGame->renderWorld;
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v58[0] = v54;
      v58[1] = v55;
      v58[2] = v56;
      v58[3] = 2.0;
      v28->DebugSphere(
        this: v28,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: (const idSphere *)v58,
        a4: 4,
        a5: GameMsPerFrame,
        a6: true);
    }
    else
    {
      v30 = clientGame->renderWorld;
      idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, const idVec3 *, double))v30->DebugArrow)(
        a1: v30,
        a2: &idColor::colorGreen,
        a3: startPos,
        a4: endPos,
        a5: 4.0);
    }
  }
  return v12;
}

