
// ========================================================================
// ?UpdateDeathFade@idGoreComponent@@AAAXXZ
// EA  : 0x82C5B748
// RVA : 0x00C5B748
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::UpdateDeathFade(idGoreComponent *this)
{
  const idDeclGore *goreDecl; // r11
  __int64 v3; // r11
  double deathFadeStartTime; // fp0
  idPresentablePtr<idPresentable> *p_presentable; // r31
  idPresentable *v6; // r3
  double v7; // fp30
  __int64 v8; // r8
  __int64 v9; // r11
  double v10; // fp31
  const idDeclRenderParm *r; // r31
  idPresentable *v12; // r3

  goreDecl = this->goreDecl;
  if ( goreDecl != nullptr )
  {
    HIDWORD(v3) = 0x82000000;
    deathFadeStartTime = goreDecl->deathFadeInfo.deathFadeStartTime;
    if ( deathFadeStartTime >= 0.0 )
    {
      LODWORD(v3) = this->deathTime;
      if ( (_DWORD)v3 == -1 )
      {
        p_presentable = (idPresentablePtr<idPresentable> *)&this->presentable;
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable)->entity != nullptr )
        {
          v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
          if ( v6->entity->IsDead(this: v6->entity) )
            this->deathTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        }
      }
      else
      {
        v7 = (float)((float)((float)deathFadeStartTime * (float)1000.0) + (float)v3);
        LODWORD(v8) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( (float)v8 > v7 )
        {
          LODWORD(v9) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          HIDWORD(v9) = this->goreDecl;
          v10 = (float)((float)((float)v9 - (float)v7) / (float)(*(float *)(HIDWORD(v9) + 116) * (float)1000.0));
          if ( v10 >= 0.0 )
          {
            if ( v10 > 1.0 )
              v10 = 1.0;
          }
          else
          {
            v10 = 0.0;
          }
          r = (const idDeclRenderParm *)rp_DeathFadeOpacity.r;
          v12 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
          idPresentable::SetParm(this: v12, parm: r, scalar: (float)((float)1.0 - (float)v10));
        }
      }
    }
  }
}


// ========================================================================
// ?SetClipSphereRenderParms@idGoreComponent@@AAAXABVidVec4@@H@Z
// EA  : 0x82C5B8E0
// RVA : 0x00C5B8E0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGoreComponent::SetClipSphereRenderParms(
        idGoreComponent *this,
        const idVec4 *woundSphere,
        int clipSphereIndex)
{
  int v6; // r28
  int v7; // r11
  idPresentable *v8; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r10 OVERLAPPED
  __int128 v14; // r9 OVERLAPPED
  va *v15; // r3
  unsigned int spawnId; // r11
  int v17; // r29
  idPresentable *PresentableByIndex; // r3
  __int64 v19; // [sp+8h] [-1098h]
  __int64 v20; // [sp+10h] [-1090h]
  __int64 v21; // [sp+18h] [-1088h]
  __int64 v22; // [sp+20h] [-1080h]
  __int64 v23; // [sp+28h] [-1078h]
  double v24; // [sp+28h] [-1078h]
  double z; // [sp+38h] [-1068h]
  float x; // [sp+50h] [-1050h]
  float y; // [sp+54h] [-104Ch]
  float w; // [sp+5Ch] [-1044h]
  int v29[4]; // [sp+60h] [-1040h] BYREF
  va v30; // [sp+70h] [-1030h] BYREF

  if ( this->wounds.num == 0 )
  {
    v29[0] = -1;
    idList<idRenderModelCommitted *,5>::SetNum(this: &this->wounds, newNum: 11, initValue: v29);
  }
  v6 = 0;
  v7 = 0;
  while ( this->wounds.list[v7] != -1 )
  {
    ++v7;
    ++v6;
    if ( v7 >= 10 )
      goto LABEL_11;
  }
  switch ( v6 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      x = woundSphere->x;
      y = woundSphere->y;
      w = woundSphere->w;
      v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
      idPresentable::SetParm(
        this: v8,
        parm: (const idDeclRenderParm *)LODWORD(x),
        v4: __SPAIR64__(LODWORD(y), LODWORD(w)),
        a4: v12,
        a5: v11,
        a6: v10,
        a7: v9,
        a8: v19,
        a9: v20,
        a10: v21,
        a11: v22,
        a12: v23);
      break;
    default:
      break;
  }
  v13 = 4 * v6;
  *(int *)((char *)this->wounds.list + v13) = clipSphereIndex;
  v24 = woundSphere->x;
  z = woundSphere->z;
  DWORD1(v14) = HIDWORD(z);
  *((double *)&v14 + 1) = woundSphere->w;
  v15 = va::va(
          this: &v30,
          fmt: "\tAdding clipping sphere at index %d at %.2f %.2f %.2f with radius %.2f",
          a3: __SPAIR64__(HIDWORD(v24), HIDWORD(COERCE_UNSIGNED_INT64(woundSphere->y))),
          a4: *(__int64 *)((char *)&v14 + 4),
          a5: *(__int64 *)&v13,
          a6: SHIDWORD(v19),
          a7: v19,
          a8: SHIDWORD(v20),
          a9: v20,
          a10: SHIDWORD(v21),
          a11: v21);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v15->buffer);
LABEL_11:
  spawnId = this->presentable.spawnId;
  v17 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v17))->spawnId != this->presentable.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  *((_BYTE *)&PresentableByIndex->model->g + 106) |= 0x20u;
}


// ========================================================================
// ?SetClipEllipsoidRenderParms@idGoreComponent@@AAAXABVidVec3@@ABVidMat3@@H@Z
// EA  : 0x82C5BB20
// RVA : 0x00C5BB20
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGoreComponent::SetClipEllipsoidRenderParms(
        idGoreComponent *this,
        const idVec3 *pos,
        const idMat3 *axis,
        int clipEllipsoidIndex)
{
  int *list; // r11
  int v9; // r5
  double x; // fp13
  double v11; // fp12
  double y; // fp11
  idPresentablePtr<idPresentable> *p_presentable; // r29
  double z; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  double v19; // fp5
  double v20; // fp4
  double v21; // fp3
  idPresentable *v22; // r3
  int v23; // r10
  int v24; // r9
  int v25; // r8
  int v26; // r7
  idPresentable *v27; // r3
  int v28; // r10
  int v29; // r9
  int v30; // r8
  int v31; // r7
  idPresentable *v32; // r3
  int v33; // r10
  int v34; // r9
  int v35; // r8
  int v36; // r7
  idPresentable *v37; // r3
  int v38; // r10 OVERLAPPED
  double v39; // r9 OVERLAPPED
  __int128 v40; // r7 OVERLAPPED
  va *v41; // r3
  __int64 v42; // [sp+8h] [-10F8h]
  __int64 v43; // [sp+8h] [-10F8h]
  __int64 v44; // [sp+8h] [-10F8h]
  int v45; // [sp+8h] [-10F8h]
  int v46; // [sp+Ch] [-10F4h]
  __int64 v47; // [sp+10h] [-10F0h]
  __int64 v48; // [sp+10h] [-10F0h]
  __int64 v49; // [sp+10h] [-10F0h]
  int v50; // [sp+10h] [-10F0h]
  int v51; // [sp+14h] [-10ECh]
  __int64 v52; // [sp+18h] [-10E8h]
  __int64 v53; // [sp+18h] [-10E8h]
  __int64 v54; // [sp+18h] [-10E8h]
  int v55; // [sp+18h] [-10E8h]
  int v56; // [sp+1Ch] [-10E4h]
  __int64 v57; // [sp+20h] [-10E0h]
  __int64 v58; // [sp+20h] [-10E0h]
  __int64 v59; // [sp+20h] [-10E0h]
  __int64 v60; // [sp+28h] [-10D8h]
  __int64 v61; // [sp+28h] [-10D8h]
  __int64 v62; // [sp+28h] [-10D8h]
  double v63; // [sp+48h] [-10B8h]
  int v64[4]; // [sp+90h] [-1070h] BYREF
  float v65; // [sp+A0h] [-1060h]
  float v66; // [sp+A4h] [-105Ch]
  __int64 v67; // [sp+A8h] [-1058h]
  float v68; // [sp+B0h] [-1050h]
  float v69; // [sp+B4h] [-104Ch]
  __int64 v70; // [sp+B8h] [-1048h]
  float v71; // [sp+C0h] [-1040h]
  float v72; // [sp+C4h] [-103Ch]
  __int64 v73; // [sp+C8h] [-1038h]
  va v74; // [sp+D0h] [-1030h] BYREF

  if ( this->wounds.num == 0 )
  {
    v64[0] = -1;
    idList<idRenderModelCommitted *,5>::SetNum(this: &this->wounds, newNum: 11, initValue: v64);
  }
  list = this->wounds.list;
  v9 = list[10];
  if ( v9 == -1 )
  {
    list[10] = clipEllipsoidIndex;
    x = pos->x;
    v11 = axis->mat[1].x;
    y = axis->mat[1].y;
    p_presentable = (idPresentablePtr<idPresentable> *)&this->presentable;
    z = axis->mat[1].z;
    v15 = pos->y;
    v16 = axis->mat[2].x;
    v17 = axis->mat[2].y;
    v18 = axis->mat[2].z;
    v19 = pos->z;
    v20 = axis->mat[0].x;
    v21 = axis->mat[0].y;
    *(float *)&v73 = axis->mat[0].z;
    v72 = v21;
    v71 = v20;
    *((float *)&v73 + 1) = x;
    v65 = v11;
    v66 = y;
    *(float *)&v67 = z;
    *((float *)&v67 + 1) = v15;
    v68 = v16;
    v69 = v17;
    *(float *)&v70 = v18;
    *((float *)&v70 + 1) = v19;
    v22 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
    idPresentable::SetParm(
      this: v22,
      parm: (const idDeclRenderParm *)LODWORD(v71),
      v4: v73,
      a4: v26,
      a5: v25,
      a6: v24,
      a7: v23,
      a8: v42,
      a9: v47,
      a10: v52,
      a11: v57,
      a12: v60);
    v27 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
    idPresentable::SetParm(
      this: v27,
      parm: (const idDeclRenderParm *)LODWORD(v65),
      v4: v67,
      a4: v31,
      a5: v30,
      a6: v29,
      a7: v28,
      a8: v43,
      a9: v48,
      a10: v53,
      a11: v58,
      a12: v61);
    v32 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
    idPresentable::SetParm(
      this: v32,
      parm: (const idDeclRenderParm *)LODWORD(v68),
      v4: v70,
      a4: v36,
      a5: v35,
      a6: v34,
      a7: v33,
      a8: v44,
      a9: v49,
      a10: v54,
      a11: v59,
      a12: v62);
    v37 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
    *((_BYTE *)&v37->model->g + 106) |= 0x20u;
    v63 = axis->mat[1].y;
    v38 = LODWORD(v63);
    v39 = axis->mat[1].x;
    DWORD1(v40) = clipEllipsoidIndex;
    *((double *)&v40 + 1) = axis->mat[0].y;
    v41 = va::va(
            this: &v74,
            fmt: "\tAdding clipping ellipsoid %d - ( %.2f %.2f %.2f ), ( %.2f %.2f %.2f ), ( %.2f %.2f %.2f ) at position ( %.2f %.2f %.2f ) ",
            a3: *(__int64 *)((char *)&v40 + 4),
            a4: *(__int64 *)((char *)&v39 + 4),
            a5: *(__int64 *)&v38,
            a6: v45,
            a7: v46,
            a8: v50,
            a9: v51,
            a10: v55,
            a11: v56);
    if ( g_debugGore.valueInteger != 0 )
      idLib::Printf(fmt: "%s\n", v41->buffer);
  }
  else
  {
    idLib::Warning(fmt: "%s already has ellipsoid %d", "idGoreComponent::SetClipEllipsoidRenderParms", v9);
  }
}


// ========================================================================
// ?UpdateFloorTrace@idGoreComponent@@AAAXXZ
// EA  : 0x82C5BD30
// RVA : 0x00C5BD30
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::UpdateFloorTrace(idGoreComponent *this)
{
  int num; // r7
  unsigned __int64 v2; // r26
  char v4; // r6
  int v5; // r10
  int v6; // r11
  idGoreComponent::goredPiecesInUse_t *list; // r8
  idClipQuery *clipQueries; // r30
  double z; // fp29
  double y; // fp30
  double x; // fp31
  float *v12; // r28
  int v13; // r18
  unsigned __int64 index; // r11
  unsigned int v15; // r11
  char v16; // r11
  bool v17; // zf
  unsigned __int64 v18; // r11
  idClientGame *v19; // r9
  unsigned int spawnId; // r11
  double v21; // fp27
  int v22; // r31
  idPresentable *PresentableByIndex; // r11
  double v24; // fp12
  double v25; // fp9
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v29; // fp13
  __int64 v30; // r10
  int valueInteger; // r11
  idRenderWorld *v32; // r3
  double v33; // fp31
  double v34; // fp30
  double v35; // fp29
  idRenderWorld *v36; // r3
  int v37; // r8
  int v38; // r10
  idClothSim *clothSim; // r11
  int currentDeferred; // r6
  float *v41; // r11
  float v42; // r3
  float v43; // r9
  float v44; // r7
  int v45; // [sp+8h] [-278h]
  bool v46; // [sp+Fh] [-271h]
  const char *v47; // [sp+10h] [-270h]
  int v48; // [sp+14h] [-26Ch]
  int v49; // [sp+18h] [-268h]
  int v50; // [sp+1Ch] [-264h]
  int v51; // [sp+20h] [-260h]
  int v52; // [sp+24h] [-25Ch]
  int v53; // [sp+28h] [-258h]
  int v54; // [sp+2Ch] [-254h]
  int v55; // [sp+30h] [-250h]
  int v56; // [sp+34h] [-24Ch]
  int v57; // [sp+38h] [-248h]
  int v58; // [sp+3Ch] [-244h]
  int v59; // [sp+40h] [-240h]
  int v60; // [sp+44h] [-23Ch]
  int v61; // [sp+48h] [-238h]
  int v62; // [sp+4Ch] [-234h]
  int v63; // [sp+50h] [-230h]
  int v64; // [sp+58h] [-228h]
  int v65; // [sp+60h] [-220h]
  idVec3 v66; // [sp+70h] [-210h] BYREF
  idVec3 v67; // [sp+80h] [-200h] BYREF
  float v68; // [sp+8Ch] [-1F4h]
  __int64 v69; // [sp+90h] [-1F0h]
  idVec3 v70; // [sp+98h] [-1E8h] BYREF
  idVec3 v71; // [sp+A8h] [-1D8h] BYREF
  float v72[6]; // [sp+B8h] [-1C8h] BYREF
  float v73[4]; // [sp+D0h] [-1B0h] BYREF
  float v74[6]; // [sp+E0h] [-1A0h] BYREF
  float v75[14]; // [sp+F8h] [-188h] BYREF
  trace_t v76; // [sp+130h] [-150h] BYREF

  num = this->goredPiecesInUse.num;
  LODWORD(v2) = 0;
  v4 = 0;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    list = this->goredPiecesInUse.list;
    while ( list->clothSim == nullptr )
    {
      ++v5;
      list = &this->goredPiecesInUse.list[++v6];
      if ( v5 >= num )
        goto LABEL_7;
    }
    v4 = 1;
  }
LABEL_7:
  if ( v4 != 0 )
  {
    HIDWORD(v69) = 0;
    clipQueries = this->clipQueries;
    v74[4] = 0.0;
    v74[5] = 0.0;
    v75[0] = -1.0;
    v75[1] = -1.0;
    v67 = vec3_origin;
    v66 = vec3_origin;
    z = vec3_origin.z;
    y = vec3_origin.y;
    x = vec3_origin.x;
    v75[2] = -1.0;
    v12 = v75;
    v75[3] = -1.0;
    v13 = 5;
    v75[4] = -1.0;
    v75[5] = 1.0;
    v75[6] = -1.0;
    v75[7] = 1.0;
    v75[8] = 1.0;
    v75[9] = -1.0;
    v75[10] = 1.0;
    v75[11] = -1.0;
    v75[12] = -1.0;
    HIDWORD(v2) = &mat3_identity;
    do
    {
      index = clipQueries->index;
      if ( LODWORD(clipQueries->index) < *(_DWORD *)(HIDWORD(clipQueries->index) + 387900)
        || (unsigned int)index > *(_DWORD *)(HIDWORD(clipQueries->index) + 387908) )
      {
        v16 = 0;
      }
      else
      {
        v15 = *(_DWORD *)(8 * (HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset) + ((2 * index) & 0x1FFE))
                        + HIDWORD(clipQueries->index)
                        + 10688
                        + 278924);
        if ( v15 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v17 = v15 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v16 = 1, !v17) )
        {
          v16 = 0;
        }
      }
      if ( v16 != 0 )
      {
        v18 = clipQueries->index;
        v19 = clientGame;
        clipQueries->index = v2;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v76,
          query: &v19->clip.collisionQueries[v18 & 0xFFF].query,
          peek: false);
        if ( v76.fraction < 1.0 )
        {
          ++HIDWORD(v69);
          x = (float)(v76.c.normal.x + (float)x);
          v66.x = v76.endpos.x + v66.x;
          y = (float)(v76.c.normal.y + (float)y);
          v66.y = v76.endpos.y + v66.y;
          z = (float)(v76.c.normal.z + (float)z);
          v66.z = v76.endpos.z + v66.z;
        }
      }
      spawnId = this->presentable.spawnId;
      v21 = upOffset;
      v22 = spawnId & 0x3FFF;
      if ( spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v22))->spawnId != this->presentable.spawnId )
      {
        PresentableByIndex = nullptr;
      }
      v24 = (float)(PresentableByIndex->origin.z + (float)v21);
      v25 = (float)(*(v12 - 2) * traceLength);
      v26 = (float)(*(v12 - 1) * traceLength);
      v27 = (float)(*v12 * traceLength);
      v28 = PresentableByIndex->origin.y;
      v29 = PresentableByIndex->origin.x;
      v70.y = PresentableByIndex->origin.y;
      v70.x = v29;
      v70.z = v24;
      v71.x = (float)v25 + (float)v29;
      v71.y = (float)v26 + (float)v28;
      v71.z = (float)v27 + (float)v24;
      clipQueries->index = *(unsigned __int64 *)&idClip::Translation(
                                                   this: (idClip *)&v67,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &v70,
                                                   end: &v71,
                                                   clipModel: nullptr,
                                                   startAxis: &mat3_identity,
                                                   clipMask: 1,
                                                   passEntityNumber: v45,
                                                   moveClipModel: v46,
                                                   userName: v47,
                                                   a12: v48,
                                                   a13: v49,
                                                   a14: v50,
                                                   a15: v51,
                                                   a16: v52,
                                                   a17: v53,
                                                   a18: v54,
                                                   a19: v55,
                                                   a20: v56,
                                                   a21: v57,
                                                   a22: v58,
                                                   a23: v59,
                                                   a24: v60,
                                                   a25: v61,
                                                   a26: v62,
                                                   a27: v63,
                                                   a28: 0x1FFF,
                                                   a29: v64,
                                                   a30: false,
                                                   a31: v65,
                                                   a32: (int)"w:\\tech5\\tungsten\\game\\entities\\gore.cpp(1256) : Gore")->world;
      valueInteger = g_debugGoreCloth.valueInteger;
      if ( g_debugGoreCloth.valueInteger == 2 )
      {
        v32 = gameLocal->GetRenderWorld(this: gameLocal);
        v73[0] = 1.0;
        v73[1] = 1.0;
        v73[2] = 0.0;
        v73[3] = 1.0;
        v32->DebugLine(this: v32, a2: (const idVec4 *)v73, a3: &v70, a4: &v71, a5: 0, a6: false);
        valueInteger = g_debugGoreCloth.valueInteger;
      }
      --v13;
      ++clipQueries;
      v12 += 3;
    }
    while ( v13 != 0 );
    LODWORD(v30) = HIDWORD(v69);
    if ( SHIDWORD(v69) > 0 )
    {
      v69 = v30;
      v66.x = (float)((float)1.0 / (float)v30) * v66.x;
      v66.y = v66.y * (float)((float)1.0 / (float)v30);
      v66.z = v66.z * (float)((float)1.0 / (float)v30);
      v33 = (float)((float)((float)1.0 / (float)v30) * (float)x);
      v34 = (float)((float)y * (float)((float)1.0 / (float)v30));
      v35 = (float)((float)z * (float)((float)1.0 / (float)v30));
      if ( valueInteger == 2 )
      {
        v36 = gameLocal->GetRenderWorld(this: gameLocal);
        v72[0] = v66.x;
        v72[1] = v66.y;
        v72[2] = v66.z + (float)5.0;
        v74[0] = 0.0;
        v74[1] = 1.0;
        v74[2] = 0.0;
        v74[3] = 1.0;
        v36->DebugLine(this: v36, a2: (const idVec4 *)v74, a3: &v66, a4: (const idVec3 *)v72, a5: 0, a6: false);
      }
      v37 = 0;
      if ( this->goredPiecesInUse.num > 0 )
      {
        v38 = 0;
        do
        {
          clothSim = this->goredPiecesInUse.list[v38].clothSim;
          if ( clothSim != nullptr )
          {
            currentDeferred = clothSim->currentDeferred;
            v67.y = v34;
            v67.z = v35;
            v67.x = v33;
            v41 = (float *)((char *)clothSim + 16 * currentDeferred);
            v68 = -(float)((float)((float)v33 * v66.x)
                         + (float)((float)((float)v35 * v66.z) + (float)((float)v34 * v66.y)));
            v42 = v67.z;
            v43 = v68;
            v44 = v67.y;
            v41[61] = v67.x;
            v41[62] = v44;
            v41[63] = v42;
            v41[64] = v43;
          }
          ++v37;
          ++v38;
        }
        while ( v37 < this->goredPiecesInUse.num );
      }
    }
  }
}


// ========================================================================
// ?DisableCloth@idGoreComponent@@AAAXHABVidVec3@@0@Z
// EA  : 0x82C5C268
// RVA : 0x00C5C268
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::DisableCloth(
        idGoreComponent *this,
        int iPieceInUse,
        const idVec3 *pos,
        const idVec3 *dir)
{
  int v4; // r26
  __int64 v5; // r10
  __int64 v7; // r8
  __int64 v10; // r6
  int v11; // r11
  int v12; // r30
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  int v17; // r11
  va *v18; // r4
  __int128 v19; // r10
  idClientGame *v20; // r6
  __int64 v21; // r6
  double v22; // fp9
  double y; // fp7
  double x; // fp8
  unsigned int spawnId; // r7
  int v26; // r30
  idPresentable *PresentableByIndex; // r3
  idGoreComponent::goredPiecesInUse_t *v28; // r31
  idAttachmentCollection *v29; // r3
  int v30; // [sp+8h] [-1148h]
  int v31; // [sp+8h] [-1148h]
  int v32; // [sp+Ch] [-1144h]
  int v33; // [sp+Ch] [-1144h]
  int v34; // [sp+10h] [-1140h]
  int v35; // [sp+10h] [-1140h]
  int v36; // [sp+14h] [-113Ch]
  int v37; // [sp+14h] [-113Ch]
  int v38; // [sp+18h] [-1138h]
  int v39; // [sp+18h] [-1138h]
  int v40; // [sp+1Ch] [-1134h]
  int v41; // [sp+1Ch] [-1134h]
  float v42[4]; // [sp+58h] [-10F8h] BYREF
  idVec3 v43; // [sp+68h] [-10E8h] BYREF
  idMat3 v44; // [sp+80h] [-10D0h] BYREF
  idMat3 v45; // [sp+B0h] [-10A0h] BYREF
  idVec3 v46[2]; // [sp+D8h] [-1078h] BYREF
  va v47; // [sp+F0h] [-1060h] BYREF

  v4 = iPieceInUse;
  LODWORD(v5) = this->goreDecl->gorePieces.list;
  HIDWORD(v5) = &this->goredPiecesInUse.list[iPieceInUse];
  LODWORD(v7) = &off_822E0000;
  HIDWORD(v7) = *(unsigned __int16 *)(HIDWORD(v5) + 100);
  LODWORD(v10) = SWORD1(v7);
  v11 = 248 * SWORD1(v7);
  HIDWORD(v10) = *(_DWORD *)(v11 + v5);
  v12 = v11 + v5;
  v16 = va::va(
          this: &v47,
          fmt: "\tDisabling cloth for %s",
          a3: v10,
          a4: v7,
          a5: v5,
          a6: v30,
          a7: v32,
          a8: v34,
          a9: v36,
          a10: v38,
          a11: v40);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v16->buffer);
  v17 = *(_DWORD *)(v12 + 244);
  if ( v17 != 0 )
  {
    LODWORD(v13) = &off_822E0000;
    HIDWORD(v15) = *(_DWORD *)(v17 + 8);
    v18 = va::va(
            this: &v47,
            fmt: "\t\tSpawning gib %s after removing cloth",
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v31,
            a7: v33,
            a8: v35,
            a9: v37,
            a10: v39,
            a11: v41);
    if ( g_debugGore.valueInteger != 0 )
      idLib::Printf(fmt: "%s\n", v18->buffer);
    idClothSimManager::GetGeneralOriginAxis(
      this: &gameLocal->clothSimManager,
      clothSim: this->goredPiecesInUse.list[v4].clothSim,
      origin: v46,
      axis: &v45);
    v44.mat[0].x = v45.mat[2].x;
    v44.mat[0].y = v45.mat[2].y;
    v44.mat[0].z = v45.mat[2].z;
    v44.mat[1].x = v45.mat[0].x;
    v44.mat[1].y = v45.mat[0].y;
    v44.mat[1].z = v45.mat[0].z;
    v44.mat[2].x = v45.mat[1].x;
    v44.mat[2].y = v45.mat[1].y;
    v44.mat[2].z = v45.mat[1].z;
    if ( (unsigned __int8)idGorePieceInfo_t::clothInfo_t::EntityToSpawnIsABreakable(this: (idGorePieceInfo_t::clothInfo_t *)(v12 + 216)) != 0 )
    {
      idBreakableManager::UseBreakable(
        this: &gameLocal->breakableManager,
        decl: *(const idDeclEntityDef **)(v12 + 244),
        origin: v46,
        axis: &v44,
        dir,
        pos,
        impulse: 200.0,
        fadeTime: 0.0);
    }
    else
    {
      *(_QWORD *)((char *)&v19 + 4) = __PAIR64__(v42, (unsigned int)clientGame);
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      v20 = clientGame;
      DWORD2(v19) = (*(_DWORD *)DWORD2(v19) >> 10) & 0x7FFF;
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      HIDWORD(v21) = 1664525 * clientGame->random.seed + 1013904223;
      v22 = (float)*(__int64 *)((char *)&v19 + 4);
      DWORD2(v19) = clientGame->random.seed;
      LODWORD(v19) = (v20->random.seed >> 10) & 0x7FFF;
      clientGame->random.seed = HIDWORD(v21);
      y = dir->y;
      x = dir->x;
      LODWORD(v21) = (HIDWORD(v21) >> 10) & 0x7FFF;
      v43.z = dir->z * (float)350.0;
      v43.y = (float)y * (float)350.0;
      v43.x = (float)x * (float)350.0;
      v42[2] = (float)((float)v22 * (float)0.000030518509) * (float)25.0;
      v42[1] = (float)((float)(__int64)v19 * (float)0.000030518509) * (float)25.0;
      v42[0] = (float)((float)v21 * (float)0.000030518509) * (float)25.0;
      idSpawnablePropManager::UseSpawnable(
        this: &gameLocal->spawnablePropManager,
        decl: *(const idDeclEntityDef **)(v12 + 244),
        origin: v46,
        axis: &v44,
        linearVelocity: &v43,
        angularVelocity: (const idVec3 *)DWORD1(v19));
    }
  }
  idClothSimManager::FreeCloth(this: &gameLocal->clothSimManager, clothSim: this->goredPiecesInUse.list[v4].clothSim);
  this->goredPiecesInUse.list[v4].clothSim = nullptr;
  spawnId = this->presentable.spawnId;
  v26 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v26))->spawnId != this->presentable.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v28 = &this->goredPiecesInUse.list[v4];
  v29 = PresentableByIndex->entity->GetAttachments_2(this: PresentableByIndex->entity);
  idAttachmentCollection::RemoveAttachment(this: v29, handle: &v28->clothAttachmentHandle);
}


// ========================================================================
// ?DisableGorePiece@idGoreComponent@@AAAXHABVidVec3@@0@Z
// EA  : 0x82C5C668
// RVA : 0x00C5C668
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::DisableGorePiece(
        idGoreComponent *this,
        int gibIdx,
        const idVec3 *pos,
        const idVec3 *impulse,
        __int64 a5)
{
  __int64 v5; // r10
  int v6; // r20
  va *v9; // r3
  int num; // r8
  unsigned int v11; // r7
  int v12; // r11
  idGoreComponent::goredPiecesInUse_t *list; // r10
  unsigned int spawnId; // r11
  int v15; // r31
  idPresentableAnimatedEntity *PresentableByIndex; // r3
  __int64 v17; // r8
  __int64 v18; // r6
  idTreeAnimator *TreeAnimator; // r3
  __int64 v20; // r10
  idTreeAnimator *v21; // r27
  int v22; // r28
  int v23; // r30
  int v24; // r31
  char *v25; // r5
  char v26; // r11
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  va *v30; // r3
  int v31; // r28
  int v32; // r30
  int v33; // r31
  char v34; // r11
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r8
  va *v38; // r3
  int v39; // r28
  int v40; // r30
  va *v41; // r4
  unsigned int v42; // r11
  int v43; // r29
  int v44; // r31
  idPresentable *v45; // r3
  __int64 v46; // r10
  __int64 v47; // r8
  int v48; // r25
  int v49; // r31
  int v50; // r11
  __int64 v51; // r6
  va *v52; // r4
  __int64 v53; // r6
  va *v54; // r3
  unsigned int v55; // r11
  const idDeclRenderParm *r; // r30
  int v57; // r31
  idPresentable *v58; // r3
  __int64 v59; // r6
  int v60; // r31
  int v61; // r31
  int v62; // r31
  int v63; // r31
  unsigned int v64; // r11
  int v65; // r31
  unsigned int v66; // r11
  int v67; // r31
  unsigned int v68; // r11
  int v69; // r31
  unsigned int v70; // r11
  int v71; // r31
  unsigned int v72; // r11
  int v73; // r31
  unsigned int v74; // r11
  int v75; // r31
  idPresentable *v76; // r3
  int v77; // r10
  int v78; // r9
  int v79; // r8
  int v80; // r7
  unsigned int v81; // r11
  int v82; // r31
  idPresentable *v83; // r3
  unsigned int v84; // r11
  int v85; // r31
  idGoreComponent::goredPiecesInUse_t *v86; // r11
  int v87; // [sp+8h] [-1208h]
  __int64 v88; // [sp+8h] [-1208h]
  __int64 v89; // [sp+8h] [-1208h]
  int v90; // [sp+Ch] [-1204h]
  int v91; // [sp+10h] [-1200h]
  __int64 v92; // [sp+10h] [-1200h]
  __int64 v93; // [sp+10h] [-1200h]
  int v94; // [sp+14h] [-11FCh]
  int v95; // [sp+18h] [-11F8h]
  __int64 v96; // [sp+18h] [-11F8h]
  __int64 v97; // [sp+18h] [-11F8h]
  int v98; // [sp+1Ch] [-11F4h]
  __int64 v99; // [sp+20h] [-11F0h]
  __int64 v100; // [sp+20h] [-11F0h]
  __int64 v101; // [sp+28h] [-11E8h]
  __int64 v102; // [sp+28h] [-11E8h]
  int v103; // [sp+50h] [-11C0h]
  int v104; // [sp+5Ch] [-11B4h]
  __int64 v105; // [sp+78h] [-1198h]
  __int64 v106; // [sp+88h] [-1188h]
  __int64 v107; // [sp+98h] [-1178h]
  __int64 v108; // [sp+A8h] [-1168h]
  __int64 v109; // [sp+B8h] [-1158h]
  __int64 v110; // [sp+C8h] [-1148h]
  __int64 v111; // [sp+D8h] [-1138h]
  __int64 v112; // [sp+E8h] [-1128h]
  __int64 v113; // [sp+F8h] [-1118h]
  __int64 v114; // [sp+108h] [-1108h]
  __int64 v115; // [sp+118h] [-10F8h]
  __int64 v116; // [sp+128h] [-10E8h]
  __int64 v117; // [sp+138h] [-10D8h]
  idTreeAnimator v118; // [sp+140h] [-10D0h] BYREF

  LODWORD(v5) = this->goreDecl->gorePieces.list;
  v6 = v5 + 248 * gibIdx;
  HIDWORD(v5) = &off_822E0000;
  v9 = va::va(
         this: (va *)&v118.deferredOrigin.z,
         fmt: "\t\tAttempting to disable already active '%s - with level %d",
         a3: *(_QWORD *)v6,
         a4: a5,
         a5: v5,
         a6: v87,
         a7: v90,
         a8: v91,
         a9: v94,
         a10: v95,
         a11: v98);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v9->buffer);
  num = this->goredPiecesInUse.num;
  v11 = 0;
  v103 = 0;
  if ( num > 0 )
  {
    v12 = 0;
    list = this->goredPiecesInUse.list;
    do
    {
      if ( list->goreIndex == gibIdx )
        break;
      ++v11;
      list = &this->goredPiecesInUse.list[++v12];
    }
    while ( (int)v11 < num );
    v103 = v11;
  }
  if ( (((((num ^ v11) & 0x80000000) == 0) + (v11 >= num)) & 1) != 0 )
  {
    spawnId = this->presentable.spawnId;
    v15 = spawnId & 0x3FFF;
    if ( spawnId == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      || (PresentableByIndex = (idPresentableAnimatedEntity *)idClientGame::GetPresentableByIndex(
                                                                this: clientGame,
                                                                index: v15))->spawnId != this->presentable.spawnId )
    {
      PresentableByIndex = nullptr;
    }
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: PresentableByIndex);
    LODWORD(v20) = *(_DWORD *)(v6 + 24);
    v21 = TreeAnimator;
    v22 = 0;
    if ( (int)v20 > 0 )
    {
      v23 = 0;
      do
      {
        LODWORD(v20) = &byte_8200D768;
        v24 = v23 + *(_DWORD *)(v6 + 20);
        v25 = *(char **)v24;
        if ( *(char **)v24 == &byte_8200D768 || (v26 = 0, *v25 == 0) )
          v26 = 1;
        if ( v26 == 0 )
        {
          idTreeAnimator::HideKit(this: v21, kitType: *(meshKitComponents_t *)(v24 + 4), name: v25);
          LODWORD(v27) = *(_DWORD *)v24;
          LODWORD(v28) = 4 * *(_DWORD *)(v24 + 4);
          HIDWORD(v27) = *(const char **)((char *)goreKitTypeNames + v28);
          v30 = va::va(
                  this: (va *)&v118.deferredOrigin.z,
                  fmt: "\tDisabling mesh kit (hiding) [%s] %s",
                  a3: v27,
                  a4: v29,
                  a5: v28,
                  a6: SHIDWORD(v88),
                  a7: v88,
                  a8: SHIDWORD(v92),
                  a9: v92,
                  a10: SHIDWORD(v96),
                  a11: v96);
          HIDWORD(v20) = g_debugGore.valueInteger;
          if ( g_debugGore.valueInteger != 0 )
            idLib::Printf(fmt: "%s\n", v30->buffer);
        }
        ++v22;
        v23 += 8;
      }
      while ( v22 < *(_DWORD *)(v6 + 24) );
    }
    v31 = 0;
    if ( *(int *)(v6 + 40) > 0 )
    {
      v32 = 0;
      do
      {
        LODWORD(v20) = &byte_8200D768;
        v33 = v32 + *(_DWORD *)(v6 + 36);
        LODWORD(v18) = *(_DWORD *)v33;
        if ( *(char **)v33 == &byte_8200D768 || (v34 = 0, *(_BYTE *)v18 == 0) )
          v34 = 1;
        if ( v34 == 0 )
        {
          idTreeAnimator::ShowKit(
            this: &v118,
            result: (idStr *)v21,
            kitType: *(meshKitComponents_t *)(v33 + 4),
            name: (const char *)v18);
          idStr::FreeData(this: (idStr *)&v118);
          LODWORD(v35) = *(_DWORD *)v33;
          LODWORD(v36) = 4 * *(_DWORD *)(v33 + 4);
          HIDWORD(v35) = *(const char **)((char *)goreKitTypeNames + v36);
          v38 = va::va(
                  this: (va *)&v118.deferredOrigin.z,
                  fmt: "\tDisabling mesh kit (showing) [%s] %s",
                  a3: v35,
                  a4: v37,
                  a5: v36,
                  a6: SHIDWORD(v88),
                  a7: v88,
                  a8: SHIDWORD(v92),
                  a9: v92,
                  a10: SHIDWORD(v96),
                  a11: v96);
          HIDWORD(v20) = g_debugGore.valueInteger;
          if ( g_debugGore.valueInteger != 0 )
            idLib::Printf(fmt: "%s\n", v38->buffer);
        }
        ++v31;
        v32 += 8;
      }
      while ( v31 < *(_DWORD *)(v6 + 40) );
    }
    v39 = 0;
    if ( *(int *)(v6 + 88) > 0 )
    {
      v40 = 0;
      do
      {
        HIDWORD(v18) = *(_DWORD *)(v40 + *(_DWORD *)(v6 + 84));
        v41 = va::va(
                this: (va *)&v118.deferredOrigin.z,
                fmt: "\t\tStopping spray effect %d",
                a3: v18,
                a4: v17,
                a5: v20,
                a6: SHIDWORD(v88),
                a7: v88,
                a8: SHIDWORD(v92),
                a9: v92,
                a10: SHIDWORD(v96),
                a11: v96);
        if ( g_debugGore.valueInteger != 0 )
          idLib::Printf(fmt: "%s\n", v41->buffer);
        v42 = this->presentable.spawnId;
        v43 = *(_DWORD *)(v6 + 84);
        v44 = v42 & 0x3FFF;
        if ( v42 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v42 & 0x3FFF)
          || (v45 = idClientGame::GetPresentableByIndex(this: clientGame, index: v44))->spawnId != this->presentable.spawnId )
        {
          v45 = nullptr;
        }
        idPresentable::StopFX(this: v45, condition: *(_DWORD *)(v40 + v43), extraCondition: FX_EXTRA_COND_NONE);
        ++v39;
        v40 += 4;
      }
      while ( v39 < *(_DWORD *)(v6 + 88) );
    }
    v104 = 0;
    if ( *(int *)(v6 + 120) > 0 )
    {
      HIDWORD(v46) = &joystick.joyAxis[0][2];
      HIDWORD(v47) = &joystick.joyAxis[0][2];
      v48 = 0;
      do
      {
        LODWORD(v47) = this->wounds.num;
        LODWORD(v46) = &this->wounds;
        v49 = 0;
        if ( (int)v47 <= 0 )
          goto LABEL_48;
        v50 = 0;
        LODWORD(v46) = *(_DWORD *)v46;
        HIDWORD(v46) = *(_DWORD *)(*(_DWORD *)(v6 + 116) + v48);
        while ( 1 )
        {
          HIDWORD(v47) = *(_DWORD *)(v46 + v50);
          if ( HIDWORD(v47) == HIDWORD(v46) )
            break;
          ++v49;
          v50 += 4;
          if ( v49 >= (int)v47 )
            goto LABEL_48;
        }
        if ( v49 == -1 )
        {
LABEL_48:
          LODWORD(v51) = -1;
          HIDWORD(v51) = *(_DWORD *)(*(_DWORD *)(v6 + 116) + v48);
          v52 = va::va(
                  this: (va *)&v118.deferredOrigin.z,
                  fmt: "\t\tDid not remove clip sphere/ellipsoid %d from index %d",
                  a3: v51,
                  a4: v47,
                  a5: v46,
                  a6: SHIDWORD(v88),
                  a7: v88,
                  a8: SHIDWORD(v92),
                  a9: v92,
                  a10: SHIDWORD(v96),
                  a11: v96);
          if ( g_debugGore.valueInteger != 0 )
            idLib::Printf(fmt: "%s\n", v52);
        }
        else
        {
          HIDWORD(v46) = -1;
          LODWORD(v53) = v49;
          *(_DWORD *)(4 * v49 + v46) = -1;
          HIDWORD(v53) = *(_DWORD *)(*(_DWORD *)(v6 + 116) + v48);
          v54 = va::va(
                  this: (va *)&v118.deferredOrigin.z,
                  fmt: "\t\tRemoving clip sphere/ellipsoid %d from index %d",
                  a3: v53,
                  a4: v47,
                  a5: v46,
                  a6: SHIDWORD(v88),
                  a7: v88,
                  a8: SHIDWORD(v92),
                  a9: v92,
                  a10: SHIDWORD(v96),
                  a11: v96);
          LODWORD(v47) = g_debugGore.valueInteger;
          if ( g_debugGore.valueInteger != 0 )
            idLib::Printf(fmt: "%s\n", v54);
          switch ( v49 )
          {
            case 0:
              v55 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosA.r;
              v57 = v55 & 0x3FFF;
              if ( v55 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v55 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v57),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v114 + 1) = 1.0;
              *(float *)&v114 = 0.0;
              v59 = v114;
              goto LABEL_116;
            case 1:
              LODWORD(v46) = this->presentable.spawnId;
              v60 = v46 & 0x3FFF;
              r = (const idDeclRenderParm *)rp_Wound3PosB.r;
              if ( (_DWORD)v46 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v46 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v60),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v116 + 1) = 1.0;
              *(float *)&v116 = 0.0;
              v59 = v116;
              goto LABEL_116;
            case 2:
              LODWORD(v46) = this->presentable.spawnId;
              v61 = v46 & 0x3FFF;
              r = (const idDeclRenderParm *)rp_Wound3PosC.r;
              if ( (_DWORD)v46 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v46 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v61),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v108 + 1) = 1.0;
              *(float *)&v108 = 0.0;
              v59 = v108;
              goto LABEL_116;
            case 3:
              LODWORD(v46) = this->presentable.spawnId;
              v62 = v46 & 0x3FFF;
              r = (const idDeclRenderParm *)rp_Wound3PosD.r;
              if ( (_DWORD)v46 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v46 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v62),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v105 + 1) = 1.0;
              *(float *)&v105 = 0.0;
              v59 = v105;
              goto LABEL_116;
            case 4:
              LODWORD(v46) = this->presentable.spawnId;
              v63 = v46 & 0x3FFF;
              r = (const idDeclRenderParm *)rp_Wound3PosE.r;
              if ( (_DWORD)v46 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v46 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v63),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v110 + 1) = 1.0;
              *(float *)&v110 = 0.0;
              v59 = v110;
              goto LABEL_116;
            case 5:
              v64 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosF.r;
              v65 = v64 & 0x3FFF;
              if ( v64 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v64 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v65),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v117 + 1) = 1.0;
              *(float *)&v117 = 0.0;
              v59 = v117;
              goto LABEL_116;
            case 6:
              v66 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosG.r;
              v67 = v66 & 0x3FFF;
              if ( v66 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v66 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v67),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v112 + 1) = 1.0;
              *(float *)&v112 = 0.0;
              v59 = v112;
              goto LABEL_116;
            case 7:
              v68 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosH.r;
              v69 = v68 & 0x3FFF;
              if ( v68 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v68 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v69),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v106 + 1) = 1.0;
              *(float *)&v106 = 0.0;
              v59 = v106;
              goto LABEL_116;
            case 8:
              v70 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosI.r;
              v71 = v70 & 0x3FFF;
              if ( v70 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v70 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v71),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v107 + 1) = 1.0;
              *(float *)&v107 = 0.0;
              v59 = v107;
              goto LABEL_116;
            case 9:
              v72 = this->presentable.spawnId;
              r = (const idDeclRenderParm *)rp_Wound3PosJ.r;
              v73 = v72 & 0x3FFF;
              if ( v72 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v72 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v73),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v109 + 1) = 1.0;
              *(float *)&v109 = 0.0;
              v59 = v109;
              goto LABEL_116;
            case 10:
              v74 = this->presentable.spawnId;
              v75 = v74 & 0x3FFF;
              if ( v74 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v74 & 0x3FFF)
                || (v76 = idClientGame::GetPresentableByIndex(this: clientGame, index: v75),
                    LODWORD(v46) = v76->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v76 = nullptr;
              }
              *((float *)&v111 + 1) = 0.0;
              *(float *)&v111 = 0.0;
              idPresentable::SetParm(
                this: v76,
                parm: COERCE_CONST_IDDECLRENDERPARM_(1.0),
                v4: v111,
                a4: SHIDWORD(v47),
                a5: v47,
                a6: SHIDWORD(v46),
                a7: v46,
                a8: v88,
                a9: v92,
                a10: v96,
                a11: v99,
                a12: v101);
              v81 = this->presentable.spawnId;
              v82 = v81 & 0x3FFF;
              if ( v81 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v81 & 0x3FFF)
                || (v83 = idClientGame::GetPresentableByIndex(this: clientGame, index: v82),
                    (v77 = v83->spawnId) != this->presentable.spawnId) )
              {
                v83 = nullptr;
              }
              *((float *)&v113 + 1) = -999.0;
              *(float *)&v113 = 0.0;
              idPresentable::SetParm(
                this: v83,
                parm: COERCE_CONST_IDDECLRENDERPARM_(0.0),
                v4: v113,
                a4: v80,
                a5: v79,
                a6: v78,
                a7: v77,
                a8: v89,
                a9: v93,
                a10: v97,
                a11: v100,
                a12: v102);
              v84 = this->presentable.spawnId;
              v85 = v84 & 0x3FFF;
              r = (const idDeclRenderParm *)rp_WoundEllipsoidZ.r;
              if ( v84 == 0
                || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v84 & 0x3FFF)
                || (v58 = idClientGame::GetPresentableByIndex(this: clientGame, index: v85),
                    LODWORD(v46) = v58->spawnId,
                    (_DWORD)v46 != this->presentable.spawnId) )
              {
                v58 = nullptr;
              }
              *((float *)&v115 + 1) = 0.0;
              *(float *)&v115 = 1.0;
              v59 = v115;
LABEL_116:
              idPresentable::SetParm(
                this: v58,
                parm: r,
                v4: v59,
                a4: SHIDWORD(v47),
                a5: v47,
                a6: SHIDWORD(v46),
                a7: v46,
                a8: v88,
                a9: v92,
                a10: v96,
                a11: v99,
                a12: v101);
              break;
            default:
              break;
          }
        }
        v48 += 4;
        ++v104;
      }
      while ( v104 < *(_DWORD *)(v6 + 120) );
    }
    if ( this->goredPiecesInUse.list[v103].clothSim != nullptr )
    {
      if ( g_debugGore.valueInteger != 0 )
        idLib::Printf(fmt: "%s\n", "\t\tDisabling cloth");
      idGoreComponent::DisableCloth(this, iPieceInUse: v103, pos, dir: impulse);
    }
    v86 = &this->goredPiecesInUse.list[v103];
    v86->initialGibJointAxis = quat_identity;
    v86->initialGibJointPos = vec3_origin;
    v86->frameCountSinceSpawn = 0;
    v86->clothSim = nullptr;
    v86->goreIndex = -1;
    v86->gibMeshSpawned = false;
    v86->activated = false;
  }
}


// ========================================================================
// ?Init@idGoreComponent@@QAAXPAVidPresentableAnimatedEntity@@PBVidDeclGore@@@Z
// EA  : 0x82C5D250
// RVA : 0x00C5D250
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::Init(
        idGoreComponent *this,
        idPresentableAnimatedEntity *inPresentable,
        const idDeclGore *inGoreDecl)
{
  idGorePieceInfo_t::clothInfo_t *p_cloth; // r28
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idPresentablePtr<idPresentable> *p_presentable; // r3
  unsigned int spawnId; // r11
  idPresentableAnimatedEntity *v11; // r3
  idTreeAnimator *TreeAnimator; // r27
  int v13; // r21
  int v14; // r22
  idGorePieceInfo_t *v15; // r30
  char *str; // r5
  char v17; // r11
  int v18; // r29
  const char *v19; // r17
  idJointGroupCollection *JointGroupCollection; // r3
  int v21; // r9
  int v22; // r11
  idDeclEntityDef *entityToSpawn; // r11
  const char *classname; // r29
  const char *v25; // r3
  idRenderModelParms *v26; // r3
  idRenderModelParms *v27; // r3
  idDeclEntityDef *gibEntity; // r11
  const char *v29; // r29
  const char *v30; // r3
  int v31; // r3
  char v32; // r11
  idRenderModelParms *v33; // r3
  idRenderModelParms *v34; // r3
  int v35; // r29
  int v36; // r30
  idRenderModelParms *Origin; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v39; // r30
  int v40; // r3
  __int64 totalTicks; // r11
  __int64 v42; // r9
  __int16 v43; // [sp+50h] [-A0h] BYREF
  int num; // [sp+54h] [-9Ch]
  idPLogScope v45[19]; // [sp+58h] [-98h] BYREF

  p_cloth = (idGorePieceInfo_t::clothInfo_t *)"idGoreComponent::Init";
  RD_EventBegin(name: "idGoreComponent::Init");
  LODWORD(v7) = "idGoreComponent::Init";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: v45, pl: &::pLog, gMask: v7, label: v8);
  p_presentable = (idPresentablePtr<idPresentable> *)&this->presentable;
  spawnId = 0;
  if ( inPresentable != nullptr )
    spawnId = inPresentable->spawnId;
  p_presentable->spawnId = spawnId;
  this->goreDecl = inGoreDecl;
  if ( inGoreDecl == nullptr || inPresentable == nullptr )
    goto _LN147_1;
  v11 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v11);
  v13 = 0;
  if ( inGoreDecl->gorePieces.num <= 0 )
  {
LABEL_35:
    v35 = 0;
    if ( inGoreDecl->fullBodyBreakableGibs.num > 0 )
    {
      v36 = 0;
      do
      {
        Origin = idRenderModel::GetOrigin(this: TreeAnimator);
        idBreakableManager::AddBreakable(
          this: &gameLocal->breakableManager,
          decl: inGoreDecl->fullBodyBreakableGibs.list[v36],
          origin: &Origin->origin);
        ++v35;
        ++v36;
      }
      while ( v35 < inGoreDecl->fullBodyBreakableGibs.num );
    }
    if ( v45[0].logIndex >= 0 )
    {
      pLog = v45[0].pLog;
      v39 = &v45[0].pLog->logEntries.list[v45[0].logIndex];
      v40 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v39->totalTicks;
      HIDWORD(totalTicks) = v39->parent;
      LODWORD(v42) = v40 - totalTicks;
      v39->totalTicks = v42;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    goto _M494569_2;
  }
  v14 = 0;
  while ( 1 )
  {
    v15 = &inGoreDecl->gorePieces.list[v14];
    str = (char *)v15->jointToZeroOut.str;
    if ( str == &byte_8200D768 || (v17 = 0, *str == 0) )
      v17 = 1;
    if ( v17 == 0 )
    {
      num = (int)v15->jointToZeroOut.str;
      idTreeAnimator::GetJointIndex(
        this: (idTreeAnimator *)&v43,
        result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator,
        jointName: str);
      if ( v43 < 0 )
      {
        idLib::Error(
          fmt: "idGoreComponent::Init failed for decl %s at index %d.  Needs to have a zero out joint gore type GORETYPE_WOUND",
          inGoreDecl->name.str,
          v13);
_LN145_0:
        idLib::Error(
          fmt: "idGoreComponent::Init failed for decl %s at index %d.  Bad damage group '%s' in its gore setup.",
          inGoreDecl->name.str,
          v13,
          v15->damageGroups.list[(_DWORD)p_cloth].str);
        goto _LN146_0;
      }
    }
    p_cloth = nullptr;
    if ( v15->damageGroups.num > 0 )
    {
      v18 = 0;
      do
      {
        v19 = v15->damageGroups.list[v18].str;
        JointGroupCollection = idTreeAnimator::GetJointGroupCollection(this: TreeAnimator);
        if ( idJointGroupCollection::GetJointGroupForName(this: JointGroupCollection, type: 0, name: v19) == nullptr )
          goto _LN145_0;
        p_cloth = (idGorePieceInfo_t::clothInfo_t *)((char *)p_cloth + 1);
        ++v18;
      }
      while ( (int)p_cloth < v15->damageGroups.num );
    }
    v21 = 0;
    num = v15->fxToPlay.num;
    if ( num > 0 )
      break;
LABEL_20:
    entityToSpawn = v15->entityToSpawn;
    if ( entityToSpawn != nullptr )
    {
      classname = idBreakable::Type.classname;
      v25 = (const char *)((int (*)(void))entityToSpawn->GetClass)();
      if ( (_cntlzw(idStr::Cmp(s1: v25, s2: classname)) & 0x20) != 0 )
      {
        v26 = idRenderModel::GetOrigin(this: TreeAnimator);
        idBreakableManager::AddBreakable(
          this: &gameLocal->breakableManager,
          decl: v15->entityToSpawn,
          origin: &v26->origin);
      }
      else
      {
        v27 = idRenderModel::GetOrigin(this: TreeAnimator);
        idSpawnablePropManager::AddSpawnable(
          this: &gameLocal->spawnablePropManager,
          decl: v15->entityToSpawn,
          origin: &v27->origin);
      }
    }
    p_cloth = &v15->cloth;
    if ( v15->cloth.clothDecl != nullptr && v15->cloth.gibEntity != nullptr )
    {
      gibEntity = v15->cloth.gibEntity;
      if ( gibEntity == nullptr
        || (v29 = idBreakable::Type.classname,
            v30 = (const char *)((int (*)(void))gibEntity->GetClass)(),
            v31 = idStr::Cmp(s1: v30, s2: v29),
            v32 = 1,
            v31 != 0) )
      {
        v32 = 0;
      }
      if ( v32 != 0 )
      {
        v33 = idRenderModel::GetOrigin(this: TreeAnimator);
        idBreakableManager::AddBreakable(
          this: &gameLocal->breakableManager,
          decl: v15->cloth.gibEntity,
          origin: &v33->origin);
      }
      else
      {
        v34 = idRenderModel::GetOrigin(this: TreeAnimator);
        idSpawnablePropManager::AddSpawnable(
          this: &gameLocal->spawnablePropManager,
          decl: v15->cloth.gibEntity,
          origin: &v34->origin);
      }
    }
    if ( p_cloth->clothDecl != nullptr )
      idClothSimManager::AddCloth(this: &gameLocal->clothSimManager, decl: p_cloth->clothDecl);
    ++v13;
    ++v14;
    if ( v13 >= inGoreDecl->gorePieces.num )
      goto LABEL_35;
  }
  v22 = 0;
  while ( v15->fxToPlay.list[v22] <= (unsigned int)FX_SUMMON_DEMON_IMP )
  {
    ++v21;
    ++v22;
    if ( v21 >= num )
      goto LABEL_20;
  }
_LN146_0:
  idLib::Error(
    fmt: "idGoreComponent::Init failed for decl %s at index %d.  Bad fx condition its gore setup.",
    inGoreDecl->name.str,
    v13);
_LN147_1:
  idPLogScope::~idPLogScope(this: v45);
_M494569_2:
  RD_EventEnd();
}


// ========================================================================
// $LN127_1
// EA  : 0x82C5D600
// RVA : 0x00C5D600
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _LN127_1()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$494380_0
// EA  : 0x82C5D628
// RVA : 0x00C5D628
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494380_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?ActivateBFGExplosion@idGoreComponent@@AAAXPBVidDeclDamage@@ABVidVec3@@1@Z
// EA  : 0x82C5D658
// RVA : 0x00C5D658
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::ActivateBFGExplosion(
        idGoreComponent *this,
        const idDeclDamage *damageDecl,
        const idVec3 *impactPoint,
        const idVec3 *dir)
{
  const idDeclGore *goreDecl; // r11
  const idDeclEntityDef *v8; // r25
  idPresentableAnimatedEntity *v9; // r3
  idTreeAnimator *TreeAnimator; // r3
  const idDeclMD6 *decl; // r11
  idTreeAnimator *v12; // r29
  idJointGroupCollection *p_jointGroupCollection; // r3
  const idJointGroup *JointGroupForIndex; // r30
  const idTreeAnimator *v15; // r8
  int v16; // r11
  int v17; // r10
  int v18; // r7
  int v19; // r9
  double v20; // fp0
  const idVec3 *p_deferredOrigin; // r5
  double y; // fp9
  double x; // fp7
  double v24; // fp6
  double ragdollImpulseMag; // fp1
  double v26; // fp5
  idVec3 v27; // [sp+50h] [-60h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v28[5]; // [sp+60h] [-50h] BYREF

  goreDecl = this->goreDecl;
  if ( goreDecl->fullBodyBreakableGibs.num >= 1 && damageDecl != nullptr )
  {
    v8 = *goreDecl->fullBodyBreakableGibs.list;
    v9 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v9);
    decl = TreeAnimator->decl;
    v12 = TreeAnimator;
    p_jointGroupCollection = &decl->jointGroupCollection;
    if ( decl == nullptr )
      p_jointGroupCollection = nullptr;
    JointGroupForIndex = idJointGroupCollection::GetJointGroupForIndex(this: p_jointGroupCollection, type: 4, index: 0);
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v28);
    idList<breakableJoint_t,5>::SetNum(this: (idList<breakableJoint_t,5> *)v28, newNum: JointGroupForIndex->joints.num);
    v16 = 0;
    if ( JointGroupForIndex->joints.num > 0 )
    {
      v17 = 0;
      v18 = 0;
      v19 = 0;
      do
      {
        HIWORD(v28[0].list[v17]) = JointGroupForIndex->joints.list[v19].value;
        if ( v16 < 0 || v16 >= JointGroupForIndex->jointScalars.num )
          v20 = 1.0;
        else
          v20 = JointGroupForIndex->jointScalars.list[v18];
        ++v16;
        v15 = (const idTreeAnimator *)&v28[0].list[v17];
        ++v19;
        ++v18;
        v28[0].list[v17 + 1] = (const idDeclVehicleUpgrade *)(int)(float)((float)v20 - (float)1.0);
        v17 += 2;
      }
      while ( v16 < JointGroupForIndex->joints.num );
    }
    p_deferredOrigin = &v12->deferredOrigin;
    y = impactPoint->y;
    x = impactPoint->x;
    v24 = (float)(dir->y * offset_0);
    ragdollImpulseMag = damageDecl->ragdollImpulseMag;
    v26 = (float)(dir->x * offset_0);
    v27.z = impactPoint->z - (float)(dir->z * offset_0);
    v27.y = (float)y - (float)v24;
    v27.x = (float)x - (float)v26;
    if ( !v12->useDeferredPosition )
      p_deferredOrigin = &v12->g.origin;
    idBreakableManager::OrientAndUseBreakable(
      this: &gameLocal->breakableManager,
      decl: v8,
      origin: p_deferredOrigin,
      axis: &v12->g.axis,
      explosionOrigin: &v27,
      impulse: ragdollImpulseMag,
      ta: v15,
      jointList: v12,
      a9: (const idList<breakableJoint_t,5> *)v28);
    if ( (v28[0].listStatic == 0 || v28[0].listStatic == 2) && v28[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v28[0].list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$494595
// EA  : 0x82C5D824
// RVA : 0x00C5D824
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494595()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ??0idGoreComponent@@QAA@XZ
// EA  : 0x82C5DA50
// RVA : 0x00C5DA50
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

idGoreComponent *__fastcall idGoreComponent::idGoreComponent(idGoreComponent *this)
{
  this->frameDamage.list = nullptr;
  this->frameDamage.granularity = 0;
  this->frameDamage.memTag = 5;
  this->frameDamage.listStatic = 0;
  this->frameDamage.size = 0;
  this->frameDamage.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->goredPiecesInUse.granularity = 0;
  this->goredPiecesInUse.memTag = 5;
  this->goredPiecesInUse.listStatic = 0;
  this->goredPiecesInUse.list = nullptr;
  this->goredPiecesInUse.size = 0;
  this->goredPiecesInUse.num = 0;
  this->jointsGoredThisFrame.list = nullptr;
  this->jointsGoredThisFrame.granularity = 0;
  this->jointsGoredThisFrame.memTag = 5;
  this->jointsGoredThisFrame.listStatic = 0;
  this->jointsGoredThisFrame.size = 0;
  this->jointsGoredThisFrame.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointsGoredThisFrame);
  this->wounds.list = nullptr;
  this->wounds.granularity = 0;
  this->wounds.memTag = 5;
  this->wounds.listStatic = 0;
  this->wounds.size = 0;
  this->wounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->wounds);
  this->presentable.spawnId = 0;
  this->goreDecl = nullptr;
  this->deathTime = -1;
  this->clipQueries[0].index = 0x500000000LL;
  this->clipQueries[1].index = 0x500000000LL;
  this->clipQueries[2].index = 0x500000000LL;
  this->clipQueries[3].index = 0x500000000LL;
  this->clipQueries[4].index = 0x500000000LL;
  return this;
}


// ========================================================================
// __unwind$494813
// EA  : 0x82C5DB2C
// RVA : 0x00C5DB2C
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494813()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$494814
// EA  : 0x82C5DB54
// RVA : 0x00C5DB54
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494814()
{
  int v0; // r12

  idList<idGoreComponent::goredPiecesInUse_t,5>::~idList<idGoreComponent::goredPiecesInUse_t,5>(this: (idList<idGoreComponent::goredPiecesInUse_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$494815
// EA  : 0x82C5DB80
// RVA : 0x00C5DB80
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494815()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// ??1idGoreComponent@@QAA@XZ
// EA  : 0x82C5DBB8
// RVA : 0x00C5DBB8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::~idGoreComponent(idGoreComponent *this)
{
  int v2; // r27
  int v3; // r29
  idClothSim *clothSim; // r4
  int *list; // r4
  idIndex<short,enum invalidJointIndex_t> *v6; // r4
  char *v7; // r3

  v2 = 0;
  if ( this->goredPiecesInUse.num > 0 )
  {
    v3 = 0;
    do
    {
      clothSim = this->goredPiecesInUse.list[v3].clothSim;
      if ( clothSim != nullptr )
        idClothSimManager::FreeCloth(this: &gameLocal->clothSimManager, clothSim);
      ++v2;
      ++v3;
    }
    while ( v2 < this->goredPiecesInUse.num );
  }
  if ( this->wounds.listStatic == 0 || this->wounds.listStatic == 2 )
  {
    list = this->wounds.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->wounds.list = nullptr;
    this->wounds.size = 0;
  }
  this->wounds.num = 0;
  if ( this->jointsGoredThisFrame.listStatic == 0 || this->jointsGoredThisFrame.listStatic == 2 )
  {
    v6 = this->jointsGoredThisFrame.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->jointsGoredThisFrame.list = nullptr;
    this->jointsGoredThisFrame.size = 0;
  }
  this->jointsGoredThisFrame.num = 0;
  if ( this->goredPiecesInUse.listStatic == 0 || this->goredPiecesInUse.listStatic == 2 )
  {
    v7 = (char *)this->goredPiecesInUse.list;
    if ( v7 != nullptr )
      idListArrayDelete<idGoreComponent::goredPiecesInUse_t>(ptr: v7, num: this->goredPiecesInUse.size);
    this->goredPiecesInUse.list = nullptr;
    this->goredPiecesInUse.size = 0;
  }
  this->goredPiecesInUse.num = 0;
  if ( this->frameDamage.listStatic == 0 || this->frameDamage.listStatic == 2 )
  {
    if ( this->frameDamage.list != nullptr )
      idMem::Free(this: &mem, ptr: this->frameDamage.list, align: ALIGN_16);
    this->frameDamage.list = nullptr;
    this->frameDamage.size = 0;
  }
  this->frameDamage.num = 0;
}


// ========================================================================
// __unwind$494892
// EA  : 0x82C5DD20
// RVA : 0x00C5DD20
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494892()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$494893
// EA  : 0x82C5DD48
// RVA : 0x00C5DD48
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494893()
{
  int v0; // r12

  idList<idGoreComponent::goredPiecesInUse_t,5>::~idList<idGoreComponent::goredPiecesInUse_t,5>(this: (idList<idGoreComponent::goredPiecesInUse_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 16));
}


// ========================================================================
// __unwind$494894
// EA  : 0x82C5DD74
// RVA : 0x00C5DD74
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494894()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 32));
}


// ========================================================================
// __unwind$494895
// EA  : 0x82C5DDA0
// RVA : 0x00C5DDA0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_494895()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 48));
}


// ========================================================================
// ?EnableGorePiece@idGoreComponent@@AAA_NHABVidVec3@@@Z
// EA  : 0x82C5DDD8
// RVA : 0x00C5DDD8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

int __fastcall idGoreComponent::EnableGorePiece(idGoreComponent *this, int gibIdx, const idVec3 *impulse)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  __int64 v8; // r8
  idTreeAnimator_vtbl *num; // r4
  idGorePieceInfo_t *list; // r3
  idGorePieceInfo_t *v11; // r22
  int v12; // r9
  int v13; // r11
  int v14; // r10
  int v15; // r30
  __int16 *p_goreIndex; // r5
  idGorePieceInfo_t *v17; // r6
  __int64 v18; // r10
  int v19; // r11
  char v20; // r11
  unsigned int spawnId; // r11
  int v22; // r30
  idPresentableAnimatedEntity *PresentableByIndex; // r3
  idTreeAnimator *TreeAnimator; // r24
  __int64 v25; // r10
  __int64 v26; // r8
  va *v27; // r3
  idList<idGoreComponent::goredPiecesInUse_t,5> *p_goredPiecesInUse; // r29
  int v29; // r11
  int size; // r10
  int v31; // r30
  int v32; // r29
  int v33; // r30
  int v34; // r3
  __int64 v35; // r11
  __int64 v36; // r9
  __int64 v38; // r6
  va *v39; // r3
  int v40; // r29
  int v41; // r30
  int v42; // r3
  __int64 v43; // r11
  __int64 v44; // r9
  char *str; // r3
  int v46; // r3
  char v47; // r11
  char *v48; // r3
  int v49; // r3
  char v50; // r11
  unsigned int v51; // r11
  int v52; // r29
  idPresentable *v53; // r3
  unsigned int v54; // r11
  int v55; // r29
  idPresentable *v56; // r3
  float *p_y; // r10
  float *v58; // r11
  int i; // ctr
  __int16 v60; // r27
  char *v61; // r5
  char v62; // r11
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  __int64 v66; // r10
  __int64 v67; // r6
  const tagData_t *v68; // r29
  __int64 v69; // r8
  va *v70; // r3
  int valueInteger; // r11
  int v72; // r29
  int v73; // r30
  int v74; // r3
  __int64 v75; // r11
  __int64 v76; // r9
  int v77; // [sp+8h] [-1148h]
  int v78; // [sp+8h] [-1148h]
  int v79; // [sp+Ch] [-1144h]
  int v80; // [sp+Ch] [-1144h]
  int v81; // [sp+10h] [-1140h]
  int v82; // [sp+10h] [-1140h]
  int v83; // [sp+14h] [-113Ch]
  int v84; // [sp+14h] [-113Ch]
  int v85; // [sp+18h] [-1138h]
  int v86; // [sp+18h] [-1138h]
  int v87; // [sp+1Ch] [-1134h]
  int v88; // [sp+1Ch] [-1134h]
  idTreeAnimator v89; // [sp+50h] [-1100h] BYREF

  RD_EventBegin(name: "idGoreComponent::EnableGorePiece() - Enable a specific gib");
  LODWORD(v6) = "idGoreComponent::EnableGorePiece() - Enable a specific gib";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v89.__vftable + 1, pl: &pLog, gMask: v6, label: v7);
  num = (idTreeAnimator_vtbl *)this->goredPiecesInUse.num;
  list = this->goreDecl->gorePieces.list;
  v89.__vftable = num;
  v11 = &list[gibIdx];
  v12 = 0;
  if ( (int)num > 0 )
  {
    LODWORD(v8) = this->goredPiecesInUse.list;
    v13 = 0;
    HIDWORD(v8) = v11->name.str;
    v14 = v8;
    while ( list[*(__int16 *)(v14 + 100)].name.str != (const char *)HIDWORD(v8) )
    {
      ++v12;
      v13 += 104;
      v14 = v8 + v13;
      if ( v12 >= (int)num )
        goto LABEL_5;
    }
    if ( *((int *)&v89.__vftable + 2) >= 0 )
    {
      v32 = *((_DWORD *)&v89.__vftable + 3);
      v33 = *(_DWORD *)(*((_DWORD *)&v89.__vftable + 3) + 16) + 16 * *((_DWORD *)&v89.__vftable + 2);
      v34 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v35 = *(_QWORD *)(v33 + 8);
      HIDWORD(v35) = *(_DWORD *)(v33 + 4);
      LODWORD(v36) = v34 - v35;
      *(_QWORD *)(v33 + 8) = v36;
      *(_DWORD *)(v32 + 32) = HIDWORD(v35);
    }
    goto LABEL_24;
  }
LABEL_5:
  v15 = 0;
  v89.__vftable = num;
  if ( (int)num > 0 )
  {
    p_goreIndex = &this->goredPiecesInUse.list->goreIndex;
    while ( 1 )
    {
      v17 = &list[*p_goreIndex];
      v89.__vftable = (idTreeAnimator_vtbl *)v17->exclusionList.num;
      v18 = (unsigned int)v89.__vftable;
      if ( (int)v89.__vftable <= 0 )
      {
LABEL_11:
        v20 = 0;
      }
      else
      {
        LODWORD(v8) = v17->exclusionList.list;
        v19 = 0;
        HIDWORD(v8) = v11->name.str;
        while ( HIDWORD(v8) != *(_DWORD *)(v8 + v19) )
        {
          ++HIDWORD(v18);
          v19 += 4;
          if ( SHIDWORD(v18) >= (int)v89.__vftable )
            goto LABEL_11;
        }
        v20 = 1;
      }
      if ( v20 != 0 )
        break;
      ++v15;
      p_goreIndex += 52;
      if ( v15 >= (int)num )
        goto LABEL_14;
    }
    LODWORD(v38) = v17->name.str;
    HIDWORD(v38) = v11->name.str;
    v39 = va::va(
            this: (va *)&v89.g.axis,
            fmt: "\tPiece %s was in %s's exclusion list",
            a3: v38,
            a4: v8,
            a5: v18,
            a6: v77,
            a7: v79,
            a8: v81,
            a9: v83,
            a10: v85,
            a11: v87);
    if ( g_debugGore.valueInteger != 0 )
      idLib::Printf(fmt: "%s\n", v39->buffer);
    if ( *((int *)&v89.__vftable + 2) >= 0 )
    {
      v40 = *((_DWORD *)&v89.__vftable + 3);
      v41 = *(_DWORD *)(*((_DWORD *)&v89.__vftable + 3) + 16) + 16 * *((_DWORD *)&v89.__vftable + 2);
      v42 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v43 = *(_QWORD *)(v41 + 8);
      HIDWORD(v43) = *(_DWORD *)(v41 + 4);
      LODWORD(v44) = v42 - v43;
      *(_QWORD *)(v41 + 8) = v44;
      *(_DWORD *)(v40 + 32) = HIDWORD(v43);
    }
LABEL_24:
    RD_EventEnd();
    return 0;
  }
LABEL_14:
  spawnId = this->presentable.spawnId;
  v22 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = (idPresentableAnimatedEntity *)idClientGame::GetPresentableByIndex(
                                                              this: clientGame,
                                                              index: v22))->spawnId != this->presentable.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: PresentableByIndex);
  v27 = va::va(
          this: (va *)&v89.g.axis,
          fmt: "\tGoring %s with gore level %d",
          a3: *(_QWORD *)&v11->name.str,
          a4: v26,
          a5: v25,
          a6: v77,
          a7: v79,
          a8: v81,
          a9: v83,
          a10: v85,
          a11: v87);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v27->buffer);
  p_goredPiecesInUse = &this->goredPiecesInUse;
  idList<idGoreComponent::goredPiecesInUse_t,5>::PreAllocateWithGranularity(
    this: &this->goredPiecesInUse,
    newSize: this->goredPiecesInUse.num + 1);
  v29 = this->goredPiecesInUse.num;
  size = this->goredPiecesInUse.size;
  if ( v29 >= size )
  {
    v31 = (int)&p_goredPiecesInUse->list[size - 1];
  }
  else
  {
    v31 = (int)&p_goredPiecesInUse->list[v29];
    this->goredPiecesInUse.num = v29 + 1;
  }
  *(idQuat *)v31 = quat_identity;
  *(idVec3 *)(v31 + 16) = vec3_origin;
  *(_WORD *)(v31 + 100) = -1;
  *(_DWORD *)(v31 + 40) = 0;
  *(_DWORD *)(v31 + 96) = 0;
  *(_BYTE *)(v31 + 102) = 0;
  *(_BYTE *)(v31 + 103) = 0;
  str = (char *)v11->jointToZeroOut.str;
  if ( str == "head" || (v46 = idStr::Cmp(s1: str, s2: "head"), v47 = 0, v46 == 0) )
    v47 = 1;
  if ( v47 != 0 )
    goto LABEL_40;
  v48 = (char *)v11->jointToZeroOut.str;
  if ( v48 == "neck" || (v49 = idStr::Cmp(s1: v48, s2: "neck"), v50 = 0, v49 == 0) )
    v50 = 1;
  if ( v50 != 0 )
  {
LABEL_40:
    v51 = this->presentable.spawnId;
    v52 = v51 & 0x3FFF;
    if ( v51 == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v51 & 0x3FFF)
      || (v53 = idClientGame::GetPresentableByIndex(this: clientGame, index: v52))->spawnId != this->presentable.spawnId )
    {
      v53 = nullptr;
    }
    idPresentable::StopSound(this: v53, channel: SND_CHANNEL_VOICE, peerMask: 0xFFu);
    v54 = this->presentable.spawnId;
    v55 = v54 & 0x3FFF;
    if ( v54 == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v54 & 0x3FFF)
      || (v56 = idClientGame::GetPresentableByIndex(this: clientGame, index: v55))->spawnId != this->presentable.spawnId )
    {
      v56 = nullptr;
    }
    idPresentable::StopSound(this: v56, channel: SND_CHANNEL_VOICE2, peerMask: 0);
  }
  if ( v11->entityToSpawn != nullptr )
  {
    p_y = &v89.deferredOrigin.y;
    v58 = &mat2_identity.mat[1].y;
    for ( i = 9; i != 0; --i )
      *++p_y = *++v58;
    *(float *)(v31 + 16) = vec3_origin.x;
    v60 = -1;
    *(float *)(v31 + 20) = vec3_origin.y;
    *((_WORD *)&v89.__vftable + 2) = -1;
    *(float *)(v31 + 24) = vec3_origin.z;
    v61 = (char *)v11->fxTagJoint.str;
    if ( v61 == &byte_8200D768 || (v62 = 0, *v61 == 0) )
      v62 = 1;
    if ( v62 == 0 )
    {
      decl = TreeAnimator->decl;
      p_props = &decl->props;
      if ( decl == nullptr )
        p_props = nullptr;
      Tag = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: v61);
      LODWORD(v66) = &off_822E0000;
      HIDWORD(v67) = v11->fxTagJoint.str;
      v68 = Tag;
      v70 = va::va(
              this: (va *)&v89.g.axis,
              fmt: "\t\tChecking for fx tag %s",
              a3: v67,
              a4: v69,
              a5: v66,
              a6: v78,
              a7: v80,
              a8: v82,
              a9: v84,
              a10: v86,
              a11: v88);
      valueInteger = g_debugGore.valueInteger;
      if ( g_debugGore.valueInteger != 0 )
      {
        idLib::Printf(fmt: "%s\n", v70->buffer);
        valueInteger = g_debugGore.valueInteger;
      }
      if ( v68->parentJoint.value == 0xFFFF )
      {
        idLib::Warning(fmt: "Unable to find tag '%s'", v11->fxTagJoint.str);
      }
      else
      {
        if ( valueInteger != 0 )
          idLib::Printf(fmt: "%s\n", "\t\t\tFound!");
        idTreeAnimator::GetWorldSpaceTagTransform(
          this: TreeAnimator,
          tagData: v68,
          origin: (idVec3 *)(v31 + 16),
          axis: (idMat3 *)&v89.deferredOrigin.z);
        *(idQuat *)v31 = *idMat3::ToQuat(this: (idMat3 *)&v89.name, result: (idQuat *)&v89.deferredOrigin.z);
        v60 = HIWORD(idTreeAnimator::GetJointIndex(
                       this: &v89,
                       result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator,
                       jointHandle: &v68->parentJoint)->__vftable);
        *((_WORD *)&v89.__vftable + 2) = v60;
      }
    }
    if ( v60 < 0 )
    {
      idTreeAnimator::GetJointIndex(
        this: &v89,
        result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator,
        jointName: v11->jointToZeroOut.str);
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: TreeAnimator,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v89.__vftable),
        origin: (idVec3 *)(v31 + 16),
        axis: (idMat3 *)&v89.nextOnCommitList);
      *(idQuat *)v31 = *idMat3::ToQuat(this: (idMat3 *)&v89.name, result: (idQuat *)&v89.nextOnCommitList);
    }
    idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
      this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->jointsGoredThisFrame,
      obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v89.__vftable + 2);
  }
  *(_WORD *)(v31 + 100) = gibIdx;
  v89.__vftable = (idTreeAnimator_vtbl *)(v31 + 28);
  *(float *)(v31 + 28) = impulse->x;
  *(float *)(v31 + 32) = impulse->y;
  *(float *)(v31 + 36) = impulse->z;
  if ( *((int *)&v89.__vftable + 2) >= 0 )
  {
    v72 = *((_DWORD *)&v89.__vftable + 3);
    v73 = *(_DWORD *)(*((_DWORD *)&v89.__vftable + 3) + 16) + 16 * *((_DWORD *)&v89.__vftable + 2);
    v74 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v75 = *(_QWORD *)(v73 + 8);
    HIDWORD(v75) = *(_DWORD *)(v73 + 4);
    LODWORD(v76) = v74 - v75;
    *(_QWORD *)(v73 + 8) = v76;
    *(_DWORD *)(v72 + 32) = HIDWORD(v75);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$495087
// EA  : 0x82C5E464
// RVA : 0x00C5E464
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_495087()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4432 + 4304));
}


// ========================================================================
// __unwind$495088
// EA  : 0x82C5E48C
// RVA : 0x00C5E48C
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_495088()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4432 + 88));
}


// ========================================================================
// ?UpdateKillshot@idGoreComponent@@QAAXV?$idIndex@FW4invalidJointIndex_t@@@@PBVidDeclDamage@@MABVidVec3@@22PBVidDamageGroup@@@Z
// EA  : 0x82C5E4C0
// RVA : 0x00C5E4C0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::UpdateKillshot(
        idGoreComponent *this,
        idIndex<short,enum invalidJointIndex_t> *hitJoint,
        const idDeclDamage *damageDecl,
        double damage,
        const idVec3 *impulse,
        const idVec3 *pos,
        const idVec3 *normal,
        const idDamageGroup *damageGroup,
        int a9)
{
  int v16; // r9
  int v17; // r11
  idGoreComponent::goredPiecesInUse_t *v18; // r10
  float x; // r9
  float z; // r7
  double v23; // fp3
  double v24; // fp9
  double v25; // fp8
  double v26; // fp5
  const idDeclGore *goreDecl; // r11
  int v28; // r30
  int v29; // r7
  int v30; // r11
  int v31; // r10
  int v32; // r11
  char v33; // r11
  unsigned int spawnId; // r11
  int v35; // r29
  idPresentable *PresentableByIndex; // r3
  unsigned int v37; // r11
  unsigned int v38; // r29
  idPresentableAnimatedEntity *v39; // r3
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v41; // r30
  idMorphVertices *morphVertices; // r25
  double v43; // fp31
  double v44; // fp30
  double v45; // fp29
  int v46; // r26
  int v47; // r28
  double v48; // fp9
  encounterGroupRole_t *list; // r4
  int num; // r30
  encounterGroupRole_t *v51; // r29
  idGorePieceInfo_t *v52; // r27
  int v53; // r3
  idGorePieceInfo_t *v54; // r5
  int v55; // r6
  idMorphVertices::vertSet *v56; // r7
  int v57; // r10
  int v58; // r11
  char v59; // r11
  double v60; // fp8
  double v61; // fp6
  double v62; // fp3
  double v63; // fp2
  double v64; // fp0
  encounterGroupRole_t v65[2]; // [sp+50h] [-260h] BYREF
  idVec3 v66[2]; // [sp+58h] [-258h] BYREF
  idMat3 v67; // [sp+70h] [-240h] BYREF
  int p_pos; // [sp+94h] [-21Ch]
  idAtomicString v69; // [sp+98h] [-218h] BYREF
  idVec3 v70; // [sp+A0h] [-210h] BYREF
  idVec3 v71; // [sp+B0h] [-200h] BYREF
  idMat3 v72; // [sp+C0h] [-1F0h] BYREF
  idMat3 v73; // [sp+F0h] [-1C0h] BYREF
  idList<enum encounterGroupRole_t,5> v74; // [sp+120h] [-190h] BYREF
  int v75; // [sp+130h] [-180h] BYREF

  if ( common->IsMultiplayer(this: common) || a9 == 0 )
    return;
  v16 = 0;
  v65[0] = (encounterGroupRole_t)this->goredPiecesInUse.num;
  if ( v65[0] <= ROLE_NONE )
  {
LABEL_7:
    x = pos->x;
    z = pos->z;
    v66[0].y = pos->y;
    v66[0].z = z;
    v74.size = 64;
    v74.granularity = 1;
    v74.num = 0;
    v74.list = (encounterGroupRole_t *)&v75;
    v74.memTag = 5;
    v74.listStatic = 1;
    _FP6 = (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v23 = __frsqrte(_FP4);
    v24 = (float)((float)-(float)((float)((float)((float)v23
                                                * (float)((float)((float)(x * x)
                                                                + (float)((float)(v66[0].y * v66[0].y)
                                                                        + (float)(v66[0].z * v66[0].z)))
                                                        * (float)0.5))
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    v25 = (float)((float)((float)-(float)((float)((float)((float)v23
                                                        * (float)((float)((float)(x * x)
                                                                        + (float)((float)(v66[0].y * v66[0].y)
                                                                                + (float)(v66[0].z * v66[0].z)))
                                                                * (float)0.5))
                                                * (float)v23)
                                        - (float)1.5)
                        * (float)v23)
                * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z)))
                        * (float)0.5));
    v26 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                                * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z))) * (float)0.5))
                                                                                        * (float)v23)
                                                                                - (float)1.5)
                                                                * (float)v23)
                                                        * (float)((float)((float)(x * x)
                                                                        + (float)((float)(v66[0].y * v66[0].y)
                                                                                + (float)(v66[0].z * v66[0].z)))
                                                                * (float)0.5))
                                                * (float)v24)
                                        - (float)1.5)
                        * (float)v24)
                * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z)))
                        * (float)0.5));
    v66[0].x = x
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z))) * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                             * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z))) * (float)0.5))
                                                                                     * (float)v24)
                                                                             - (float)1.5)
                                                             * (float)v24)
                                                     * (float)((float)((float)(x * x)
                                                                     + (float)((float)(v66[0].y * v66[0].y)
                                                                             + (float)(v66[0].z * v66[0].z)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                     * (float)v24))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24));
    v66[0].y = v66[0].y
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z))) * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                             * (float)((float)((float)(x * x) + (float)((float)(v66[0].y * v66[0].y) + (float)(v66[0].z * v66[0].z))) * (float)0.5))
                                                                                     * (float)v24)
                                                                             - (float)1.5)
                                                             * (float)v24)
                                                     * (float)((float)((float)(x * x)
                                                                     + (float)((float)(v66[0].y * v66[0].y)
                                                                             + (float)(v66[0].z * v66[0].z)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                     * (float)v24))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24));
    v66[0].z = z
             * (float)((float)-(float)((float)((float)v26
                                             * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                     * (float)v24))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24));
    idAtomicString::Set(this: &v69, str_: *(const char *const *)(a9 + 4));
    goreDecl = this->goreDecl;
    v28 = 0;
    for ( v65[0] = ROLE_NONE; v28 < goreDecl->gorePieces.num; v65[0] = v28 )
    {
      v29 = (int)&goreDecl->gorePieces.list[v28];
      v30 = *(_DWORD *)(v29 + 8);
      if ( (v30 == 0 || (damageDecl->goreTypes & v30) != 0) && damage >= *(float *)(v29 + 80) )
      {
        v31 = 0;
        p_pos = *(_DWORD *)(v29 + 56);
        if ( p_pos <= 0 )
        {
LABEL_15:
          v33 = 0;
        }
        else
        {
          v32 = 0;
          while ( v69.str != *(const char **)(*(_DWORD *)(v29 + 52) + v32) )
          {
            ++v31;
            v32 += 4;
            if ( v31 >= p_pos )
              goto LABEL_15;
          }
          v33 = 1;
        }
        if ( v33 != 0 )
        {
          if ( *(int *)(v29 + 120) > 0 )
          {
            idList<idAnimWebBlendTree *,5>::Append(this: &v74, obj: v65);
            if ( v74.num >= v74.size )
              break;
          }
          else
          {
            idGoreComponent::EnableGorePiece(this, gibIdx: v28, impulse: v66);
          }
        }
      }
      goreDecl = this->goreDecl;
      ++v28;
    }
    spawnId = this->presentable.spawnId;
    v35 = spawnId & 0x3FFF;
    if ( spawnId != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    {
      PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v35);
      v37 = this->presentable.spawnId;
      if ( PresentableByIndex->spawnId == v37 )
      {
        v38 = this->presentable.spawnId & 0x3FFF;
        if ( v37 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: this->presentable.spawnId & 0x3FFF)
          || (v39 = (idPresentableAnimatedEntity *)idClientGame::GetPresentableByIndex(this: clientGame, index: v38))->spawnId != this->presentable.spawnId )
        {
          v39 = nullptr;
        }
        TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v39);
        v41 = TreeAnimator;
        if ( TreeAnimator != nullptr )
        {
          morphVertices = TreeAnimator->decl->morphVertices;
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: TreeAnimator,
            pose: DRIVER_MODEL,
            jointIndex: hitJoint,
            origin: &v70,
            axis: &v72);
          v67.mat[0].x = v72.mat[0].x;
          v67.mat[0].y = v72.mat[0].y;
          v67.mat[0].z = v72.mat[0].z;
          v67.mat[1].x = v72.mat[1].x;
          v67.mat[1].y = v72.mat[1].y;
          v67.mat[1].z = v72.mat[1].z;
          v67.mat[2].x = v72.mat[2].x;
          v67.mat[2].y = v72.mat[2].y;
          v67.mat[2].z = v72.mat[2].z;
          idMat3::InverseSelf(this: &v67);
          v43 = (float)((float)(v67.mat[0].x * (float)(normal->x - v70.x))
                      + (float)((float)(v67.mat[1].x * (float)(normal->y - v70.y))
                              + (float)(v67.mat[2].x * (float)(normal->z - v70.z))));
          v44 = (float)((float)(v67.mat[2].z * (float)(normal->z - v70.z))
                      + (float)((float)(v67.mat[0].z * (float)(normal->x - v70.x))
                              + (float)(v67.mat[1].z * (float)(normal->y - v70.y))));
          v45 = (float)((float)(v67.mat[2].y * (float)(normal->z - v70.z))
                      + (float)((float)(v67.mat[0].y * (float)(normal->x - v70.x))
                              + (float)(v67.mat[1].y * (float)(normal->y - v70.y))));
          idTreeAnimator::GetModelSpaceJointBindTransform(this: v41, jointIndex: hitJoint, origin: &v71, axis: &v73);
          v46 = -1;
          v47 = 0;
          v48 = 1.0e30;
          if ( v74.num > 0 )
          {
            list = v74.list;
            num = morphVertices->morphVertSet.num;
            v51 = v74.list;
            v52 = this->goreDecl->gorePieces.list;
            do
            {
              v53 = 0;
              v54 = &v52[*v51];
              if ( num > 0 )
              {
                v55 = v54->clipSphereIndex.num;
                v56 = morphVertices->morphVertSet.list;
                do
                {
                  v57 = 0;
                  if ( v55 <= 0 )
                  {
LABEL_38:
                    v59 = 0;
                  }
                  else
                  {
                    v58 = 0;
                    while ( v54->clipSphereIndex.list[v58] != v56->jointGroupIndex )
                    {
                      ++v57;
                      ++v58;
                      if ( v57 >= v55 )
                        goto LABEL_38;
                    }
                    v59 = 1;
                  }
                  if ( v59 != 0 && v56->flags == 8 )
                  {
                    v60 = (float)(v56->pos.y
                                - (float)(v71.y
                                        + (float)((float)(v73.mat[2].y * (float)v44)
                                                + (float)((float)(v73.mat[0].y * (float)v43)
                                                        + (float)(v73.mat[1].y * (float)v45)))));
                    v61 = (float)(v56->pos.x
                                - (float)((float)((float)((float)v43 * v73.mat[0].x)
                                                + (float)((float)(v73.mat[1].x * (float)v45)
                                                        + (float)(v73.mat[2].x * (float)v44)))
                                        + v71.x));
                    v62 = (float)(v56->pos.z
                                - (float)(v71.z
                                        + (float)((float)(v73.mat[2].z * (float)v44)
                                                + (float)((float)(v73.mat[0].z * (float)v43)
                                                        + (float)(v73.mat[1].z * (float)v45)))));
                    v63 = (float)(v56->size.x * (float)1.75);
                    p_pos = (int)&v56->pos;
                    v64 = (float)((float)((float)v62 * (float)v62)
                                + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)));
                    if ( v64 <= (float)((float)v63 * (float)v63) && v64 <= v48 )
                    {
                      v46 = v47;
                      v48 = (float)((float)((float)v62 * (float)v62)
                                  + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)));
                    }
                  }
                  ++v53;
                  ++v56;
                }
                while ( v53 < num );
              }
              ++v47;
              ++v51;
            }
            while ( v47 < v74.num );
            if ( v46 < 0 )
              goto LABEL_49;
            idGoreComponent::EnableGorePiece(this, gibIdx: v74.list[v46], impulse: v66);
          }
        }
      }
    }
    list = v74.list;
LABEL_49:
    if ( (v74.listStatic == 0 || v74.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return;
  }
  v17 = 0;
  v18 = this->goredPiecesInUse.list;
  while ( this->goreDecl->gorePieces.list[v18->goreIndex].goreLevel <= GORELEVEL_HEAVY_DAMAGE )
  {
    ++v16;
    v18 = &this->goredPiecesInUse.list[++v17];
    if ( v16 >= v65[0] )
      goto LABEL_7;
  }
}


// ========================================================================
// __unwind$495491
// EA  : 0x82C5EAA8
// RVA : 0x00C5EAA8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_495491()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 688 + 288));
}


// ========================================================================
// ?CheckForGoreByDamageGroup@idGoreComponent@@QAA_NABVidAtomicString@@W4goreLevel_t@@ABVidVec3@@@Z
// EA  : 0x82C5EAD8
// RVA : 0x00C5EAD8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

int __fastcall idGoreComponent::CheckForGoreByDamageGroup(
        idGoreComponent *this,
        const idAtomicString *name,
        goreLevel_t level,
        const idVec3 *dir)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  const idDeclGore *goreDecl; // r11
  __int64 v11; // r8
  idPresentable *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r6
  char v15; // r11
  va *v16; // r3
  const idDeclGore *v17; // r11
  int v18; // r27
  int v19; // r26
  idGorePieceInfo_t *v20; // r30
  int v21; // r28
  int v22; // r29
  int v24; // [sp+8h] [-10B8h]
  int v25; // [sp+Ch] [-10B4h]
  int v26; // [sp+10h] [-10B0h]
  int v27; // [sp+14h] [-10ACh]
  int v28; // [sp+18h] [-10A8h]
  int v29; // [sp+1Ch] [-10A4h]
  idPLogScope v30; // [sp+50h] [-1070h] BYREF
  const char *str; // [sp+58h] [-1068h]
  va v32; // [sp+60h] [-1060h] BYREF

  RD_EventBegin(name: "idGoreComponent::CheckForGoreByDamageGroup");
  LODWORD(v8) = "idGoreComponent::CheckForGoreByDamageGroup";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: &v30, pl: &pLog, gMask: v8, label: v9);
  if ( g_EnableGore.valueInteger == 0 )
    goto LABEL_24;
  if ( common->IsMultiplayer(this: common) )
    goto LABEL_24;
  goreDecl = this->goreDecl;
  if ( goreDecl == nullptr )
    goto LABEL_24;
  if ( goreDecl->gorePieces.num == 0 )
    goto LABEL_24;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable) == nullptr )
    goto LABEL_24;
  v12 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
  LODWORD(v13) = &unk_82150000;
  if ( v12->model->g.modelFade < 0.75 )
    goto LABEL_24;
  HIDWORD(v14) = (idAtomicString)name->str;
  if ( name->str == &byte_8200D768 || (v15 = 0, *(_BYTE *)HIDWORD(v14) == 0) )
    v15 = 1;
  if ( v15 != 0 )
    goto LABEL_24;
  str = name->str;
  LODWORD(v14) = level;
  v16 = va::va(
          this: &v32,
          fmt: "//***************************************/\nChecking for gore with damage group '%s' - level %d",
          a3: v14,
          a4: v11,
          a5: v13,
          a6: v24,
          a7: v25,
          a8: v26,
          a9: v27,
          a10: v28,
          a11: v29);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v16->buffer);
  v17 = this->goreDecl;
  v18 = 0;
  if ( v17->gorePieces.num > 0 )
  {
    v19 = 0;
    while ( 1 )
    {
      v20 = &v17->gorePieces.list[v19];
      if ( v20->goreLevel == level )
      {
        v21 = 0;
        if ( v20->damageGroups.num > 0 )
          break;
      }
LABEL_21:
      v17 = this->goreDecl;
      ++v18;
      ++v19;
      if ( v18 >= v17->gorePieces.num )
        goto LABEL_24;
    }
    v22 = 0;
    while ( v20->damageGroups.list[v22].str != name->str
         || (unsigned __int8)idGoreComponent::EnableGorePiece(this, gibIdx: v18, impulse: dir) == 0 )
    {
      ++v21;
      ++v22;
      if ( v21 >= v20->damageGroups.num )
        goto LABEL_21;
    }
    idPLogScope::~idPLogScope(this: &v30);
    RD_EventEnd();
    return 1;
  }
  else
  {
LABEL_24:
    idPLogScope::~idPLogScope(this: &v30);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$495908
// EA  : 0x82C5ECEC
// RVA : 0x00C5ECEC
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_495908()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4288 + 4192));
}


// ========================================================================
// __unwind$495909
// EA  : 0x82C5ED14
// RVA : 0x00C5ED14
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_495909()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4288 + 80));
}


// ========================================================================
// ?CheckForGoreByName@idGoreComponent@@QAA_NABVidAtomicString@@@Z
// EA  : 0x82C5ED48
// RVA : 0x00C5ED48
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

int __fastcall idGoreComponent::CheckForGoreByName(idGoreComponent *this, const idAtomicString *name)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  const idDeclGore *goreDecl; // r11
  __int64 v7; // r8
  __int64 v8; // r6
  idPresentable *v9; // r3
  __int64 v10; // r10
  char v11; // r11
  va *v12; // r3
  const idDeclGore *v13; // r11
  int v14; // r30
  int v15; // r29
  int v17; // [sp+8h] [-1098h]
  int v18; // [sp+Ch] [-1094h]
  int v19; // [sp+10h] [-1090h]
  int v20; // [sp+14h] [-108Ch]
  int v21; // [sp+18h] [-1088h]
  int v22; // [sp+1Ch] [-1084h]
  idPLogScope v23; // [sp+50h] [-1050h] BYREF
  const char *str; // [sp+58h] [-1048h]
  va v25; // [sp+60h] [-1040h] BYREF

  RD_EventBegin(name: "idGoreComponent::CheckForGoreByName");
  LODWORD(v4) = "idGoreComponent::CheckForGoreByName";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v23, pl: &pLog, gMask: v4, label: v5);
  if ( g_EnableGore.valueInteger == 0 )
    goto LABEL_20;
  if ( common->IsMultiplayer(this: common) )
    goto LABEL_20;
  goreDecl = this->goreDecl;
  if ( goreDecl == nullptr )
    goto LABEL_20;
  if ( goreDecl->gorePieces.num == 0 )
    goto LABEL_20;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable) == nullptr )
    goto LABEL_20;
  v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
  LODWORD(v10) = &unk_82150000;
  if ( v9->model->g.modelFade < 0.75 )
    goto LABEL_20;
  HIDWORD(v8) = (idAtomicString)name->str;
  if ( name->str == &byte_8200D768 || (v11 = 0, *(_BYTE *)HIDWORD(v8) == 0) )
    v11 = 1;
  if ( v11 != 0 )
    goto LABEL_20;
  str = name->str;
  v12 = va::va(
          this: &v25,
          fmt: "//***************************************/\nChecking for gore with name '%s'",
          a3: v8,
          a4: v7,
          a5: v10,
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", v12->buffer);
  v13 = this->goreDecl;
  v14 = 0;
  if ( v13->gorePieces.num > 0 )
  {
    v15 = 0;
    while ( v13->gorePieces.list[v15].name.str != name->str
         || (unsigned __int8)idGoreComponent::EnableGorePiece(this, gibIdx: v14, impulse: &vec3_origin) == 0 )
    {
      v13 = this->goreDecl;
      ++v14;
      ++v15;
      if ( v14 >= v13->gorePieces.num )
        goto LABEL_20;
    }
    idPLogScope::~idPLogScope(this: &v23);
    RD_EventEnd();
    return 1;
  }
  else
  {
LABEL_20:
    idPLogScope::~idPLogScope(this: &v23);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$496021
// EA  : 0x82C5EF1C
// RVA : 0x00C5EF1C
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_496021()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4256 + 4192));
}


// ========================================================================
// __unwind$496022
// EA  : 0x82C5EF44
// RVA : 0x00C5EF44
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_496022()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4256 + 80));
}


// ========================================================================
// ?ActivateFullBodyExplosion@idGoreComponent@@AAAXPBVidDeclDamage@@MABVidVec3@@@Z
// EA  : 0x82C5EF78
// RVA : 0x00C5EF78
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::ActivateFullBodyExplosion(
        idGoreComponent *this,
        const idDeclDamage *damageDecl,
        double damage,
        const idVec3 *impulse,
        const idVec3 *a5)
{
  idPresentablePtr<idPresentable> *p_presentable; // r29
  idDeclGoreBehavior *declGoreBehavior; // r28
  idPresentable *v11; // r3
  int v12; // r3
  int v13; // r29
  double v14; // fp30
  __int64 v15; // r10
  double v17; // fp0
  int maxPieces; // r11
  int num; // r22
  int v21; // r23
  int v22; // r26
  int v23; // r25
  int v24; // r24
  int v25; // r3
  const idDeclVehicleUpgrade **list; // r6
  int v27; // r11
  const idDeclVehicleUpgrade **v28; // r9
  const idDeclGore *goreDecl; // r8
  signed int v30; // r4
  idGorePieceInfo_t *v31; // r7
  int v32; // r27
  int v33; // r29
  const idDeclVehicleUpgrade **v34; // r28
  const char *str; // r11
  idList<idDeclVehicleUpgrade const *,5> v36; // [sp+50h] [-80h] BYREF

  if ( damageDecl != nullptr )
  {
    p_presentable = (idPresentablePtr<idPresentable> *)&this->presentable;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable) != nullptr
      && idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable)->entity != nullptr )
    {
      if ( g_debugGore.valueInteger != 0 )
        idLib::Printf(fmt: "%s\n", "\tActivating full body explosion");
      declGoreBehavior = damageDecl->declGoreBehavior;
      if ( declGoreBehavior != nullptr )
      {
        v11 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
        v12 = (int)v11->entity->GetHealthComponent_2(this: v11->entity);
        v13 = v12;
        if ( v12 != 0 )
        {
          v14 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v12 + 60))(a1: v12);
          _FP12 = (float)((float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v13 + 64))(a1: v13) - (float)v14);
          v17 = 0.64999998;
          __asm { fsel      f11, f12, f1, f30 }
          if ( _FP11 > 0.0 )
            v17 = (float)((float)damage / (float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v13 + 64))(a1: v13));
          maxPieces = declGoreBehavior->bodyExplosion.maxPieces;
          LODWORD(v15) = maxPieces;
          v36.num = (int)(float)((float)v15 * (float)v17);
          num = v36.num;
          if ( maxPieces < v36.num )
            num = maxPieces;
          LODWORD(v15) = declGoreBehavior->bodyExplosion.maxWounds;
          v36.num = (int)(float)((float)v15 * (float)v17);
          v21 = v36.num;
          if ( v36.num > 10 )
            v21 = 10;
          v22 = 0;
          v23 = 0;
          v24 = 0;
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v36);
          idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v36, newNum: this->goreDecl->gorePieces.num);
          v25 = idRandom2::RandomInt(this: &clientGame->random, min: 0, max: this->goreDecl->gorePieces.num - 1);
          list = v36.list;
          v27 = 0;
          if ( this->goreDecl->gorePieces.num > 0 )
          {
            v28 = v36.list - 1;
            do
            {
              goreDecl = this->goreDecl;
              ++v27;
              v30 = goreDecl->gorePieces.num;
              v31 = goreDecl->gorePieces.list;
              __twlgei(v30 & ~(__ROL4__(v25, 1) - 1), 0xFFFFFFFF);
              __twllei(v30, 0);
              *++v28 = (const idDeclVehicleUpgrade *)&v31[v25 % v30];
              v25 = v25 % v30 + 1;
            }
            while ( v27 < this->goreDecl->gorePieces.num );
          }
          v32 = v36.num;
          v33 = 0;
          if ( v36.num > 0 )
          {
            v34 = list;
            while ( 1 )
            {
              if ( *v34 == nullptr )
                goto LABEL_35;
              str = (*v34)->name.str;
              if ( ((unsigned __int8)str & 6) != 0 )
              {
                if ( v23 < num && (unsigned __int8)idGoreComponent::EnableGorePiece(this, gibIdx: v33, impulse: a5) != 0 )
                  ++v23;
                goto LABEL_32;
              }
              if ( ((unsigned __int8)str & 0x60) == 0 )
                break;
              if ( v22 < v21 )
              {
                if ( (unsigned __int8)idGoreComponent::EnableGorePiece(this, gibIdx: v33, impulse: a5) != 0 )
                  ++v22;
                goto LABEL_32;
              }
LABEL_33:
              if ( v23 >= num && v24 >= 1 )
                goto LABEL_36;
LABEL_35:
              ++v33;
              ++v34;
              if ( v33 >= v32 )
                goto LABEL_36;
            }
            if ( ((unsigned __int8)str & 0x10) != 0
              && v24 < 1
              && (unsigned __int8)idGoreComponent::EnableGorePiece(this, gibIdx: v33, impulse: a5) != 0 )
            {
              ++v24;
            }
LABEL_32:
            if ( v22 < v21 )
              goto LABEL_35;
            goto LABEL_33;
          }
LABEL_36:
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v36);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$496119
// EA  : 0x82C5F2B0
// RVA : 0x00C5F2B0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_496119()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 80));
}


// ========================================================================
// ?AddDamage@idGoreComponent@@QAAXV?$idIndex@FW4invalidJointIndex_t@@@@PBVidDeclDamage@@MABVidVec3@@22PBVidDamageGroup@@@Z
// EA  : 0x82C5F2D8
// RVA : 0x00C5F2D8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::AddDamage(
        idGoreComponent *this,
        idIndex<short,enum invalidJointIndex_t> *hitJoint,
        const idDeclDamage *damageDecl,
        double damage,
        const idVec3 *impulse,
        const idVec3 *pos,
        const idVec3 *normal,
        const idDamageGroup *damageGroup,
        int a9)
{
  idAtomicString v12[12]; // [sp+50h] [-30h] BYREF

  if ( !common->IsMultiplayer(this: common) && a9 != 0 )
  {
    idAtomicString::Set(this: v12, str_: *(const char *const *)(a9 + 4));
    idGoreComponent::CheckForGoreByDamageGroup(this, name: v12, level: GORELEVEL_BLOOD, dir: pos);
  }
}


// ========================================================================
// ?TestGoreCheat@idGoreComponent@@AAAXXZ
// EA  : 0x82C5F348
// RVA : 0x00C5F348
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __fastcall idGoreComponent::TestGoreCheat(idGoreComponent *this)
{
  int valueInteger; // r27
  __int64 v3; // r8
  int v4; // r29
  int v5; // r30
  const idDeclGore *goreDecl; // r11
  idPresentable *v7; // r3

  valueInteger = g_testGoreIndex.valueInteger;
  idCVar::SetInteger(this: &g_testGoreIndex, newValue: -1, force: true);
  if ( valueInteger != -1
    && idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable) != nullptr
    && this->goreDecl != nullptr )
  {
    v4 = 0;
    if ( this->goredPiecesInUse.num > 0 )
    {
      v5 = 0;
      do
      {
        idGoreComponent::DisableGorePiece(
          this,
          gibIdx: this->goredPiecesInUse.list[v5].goreIndex,
          pos: &vec3_origin,
          impulse: &vec3_origin,
          a5: v3);
        ++v4;
        ++v5;
      }
      while ( v4 < this->goredPiecesInUse.num );
    }
    idList<idGoreComponent::goredPiecesInUse_t,5>::~idList<idGoreComponent::goredPiecesInUse_t,5>(this: &this->goredPiecesInUse);
    if ( valueInteger < 0 || (goreDecl = this->goreDecl, valueInteger >= goreDecl->gorePieces.num) )
    {
      v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
      idLib::Warning(fmt: "%s has no gore index %d", v7->model->name.str, valueInteger);
    }
    else
    {
      idGoreComponent::CheckForGoreByName(this, name: &goreDecl->gorePieces.list[valueInteger].name);
    }
  }
}


// ========================================================================
// ?UpdateGore@idGoreComponent@@QAA_NXZ
// EA  : 0x82C5F460
// RVA : 0x00C5F460
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

unsigned int __fastcall idGoreComponent::UpdateGore(idGoreComponent *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned int spawnId; // r9
  int v5; // r30
  idPresentableAnimatedEntity *v6; // r3
  idTreeAnimator *TreeAnimator; // r16
  int v8; // r24
  int num; // r11
  int v10; // r27
  idGoreComponent::goredPiecesInUse_t *v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idGorePieceInfo_t *v14; // r29
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r4
  int v18; // r26
  int v19; // r28
  __int16 goreIndex; // r10
  int v21; // r9
  _DWORD *v22; // r30
  __int64 v23; // r10
  int v24; // r11
  char v25; // r11
  __int64 v26; // r6
  __int64 v27; // r8
  va *v28; // r4
  unsigned __int8 v29; // r10
  int v30; // r30
  int v31; // r10
  int v32; // r26
  idGoreComponent::goredPiecesInUse_t *v33; // r11
  __int64 v34; // r10
  __int64 v35; // r8
  __int64 v36; // r6
  idGoreComponent::goredPiecesInUse_t *list; // r11
  idGorePieceInfo_t *v38; // r28
  va *v39; // r4
  idGoreComponent::goredPiecesInUse_t *v40; // r11
  unsigned int spawnedEntityImpulseBehavior; // r10
  double v42; // fp13
  double v43; // fp0
  double v44; // fp12
  idGoreComponent::goredPiecesInUse_t *v45; // r30
  idBreakableManager *p_breakableManager; // r27
  const idMat3 *v47; // r3
  __int64 v48; // r11
  __int64 v49; // r9
  __int64 v50; // r6
  double v51; // fp12
  unsigned int v52; // r7
  double v53; // fp1
  int v54; // r30
  idSpawnablePropManager *p_spawnablePropManager; // r27
  const idMat3 *v56; // r3
  int v57; // r27
  int v58; // r29
  unsigned int v59; // r11
  int v60; // r30
  idPresentable *v61; // r3
  __int64 v62; // r6
  __int64 v63; // r10
  __int64 v64; // r8
  va *v65; // r3
  int v66; // r27
  int v67; // r29
  goreKitInfo_t *v68; // r30
  char *v69; // r6
  char v70; // r11
  __int64 v71; // r10
  __int64 v72; // r6
  __int64 v73; // r8
  int v74; // r27
  int v75; // r29
  goreKitInfo_t *v76; // r30
  char *v77; // r5
  char v78; // r11
  __int64 v79; // r10
  __int64 v80; // r6
  __int64 v81; // r8
  char *v82; // r11
  char v83; // r11
  bool v84; // zf
  unsigned int v85; // r11
  int v86; // r30
  idPresentable *v87; // r3
  idEntity *entity; // r30
  const char *v89; // r27
  idGoreComponent::goredPiecesInUse_t *v90; // r29
  idAnimator_AF *v91; // r3
  int v92; // r29
  int v93; // r3
  int v94; // r10
  int v95; // r11
  int v96; // r3
  int v97; // r30
  int v98; // r29
  int v99; // r3
  __int64 v100; // r6
  __int64 v101; // r10
  __int64 v102; // r8
  int v103; // r29
  int v104; // r30
  __int64 v105; // r6
  __int64 v106; // r10
  __int64 v107; // r8
  clipShapeType_t type; // r11
  double v109; // fp11
  double x; // fp9
  double z; // fp8
  double v112; // fp6
  double v113; // fp5
  double v114; // fp4
  double v115; // fp3
  int v116; // r5
  double v117; // fp0
  double v118; // fp13
  int v123; // r11
  idMorphVertices *v124; // r9
  int v125; // r27
  int v126; // r29
  int *v127; // r11
  int *v128; // r30
  int v129; // r6
  int v130; // r9
  idMorphVertices *morphVertices; // r11
  idMorphVertices::vertSet *v132; // r7
  int v133; // r11
  idMorphVertices::vertSet *v134; // r11
  unsigned int flags; // r10
  double v136; // fp12
  double y; // fp11
  double v138; // fp10
  unsigned int v139; // r11
  int v140; // r30
  idPresentable *v141; // r3
  const idDeclCloth *clothDecl; // r29
  unsigned int v143; // r11
  idPresentablePtr<idPresentableAnimatedEntity> *p_presentable; // r24
  int v145; // r30
  idPresentable *v146; // r3
  int v147; // r30
  idPresentable *v148; // r3
  const char *v149; // r30
  idPropsCollection *PropsCollection; // r3
  const tagData_t *Tag; // r30
  __int64 v152; // r6
  __int64 v153; // r10
  __int64 v154; // r8
  va *v155; // r4
  idClothSim *v156; // r3
  idClothSim *v157; // r27
  idGoreComponent::goredPiecesInUse_t *v158; // r11
  int v159; // r30
  idPresentable *v160; // r11
  const idDeclMD6 *clothMD6; // r10
  idGoreComponent::goredPiecesInUse_t *v162; // r30
  const char *v163; // r29
  const char *v164; // r25
  const char *v165; // r24
  idList<idAttachment,5> *v166; // r3
  idAttachmentCollection *v167; // r3
  int *p_firstVisibleFrameCount; // r8
  idTreeAnimator *p_z; // r9
  int v170; // ctr
  float v171; // r3
  char *str; // r11
  char v173; // r11
  unsigned int v174; // r11
  int v175; // r30
  idPresentable *PresentableByIndex; // r3
  idGoreComponent::goredPiecesInUse_t *v177; // r30
  idAttachmentCollection *v178; // r3
  const idAttachment *v179; // r3
  const idVec3 **v180; // r30
  idClothParticle *cloth; // r10
  int v182; // r9
  char v183; // r10
  idTreeAnimator *model; // r30
  idGoreComponent::goredPiecesInUse_t *v185; // r11
  idClothSim *clothSim; // r3
  idGoreComponent::goredPiecesInUse_t *v187; // r30
  idRenderWorld *v188; // r3
  int v189; // r29
  idList<idGoreComponent::goredPiecesInUse_t,5> *p_goredPiecesInUse; // r30
  int v191; // r28
  int v192; // r11
  int v193; // r11
  unsigned int v194; // r28
  float v195; // r29
  int v196; // r30
  int v197; // r3
  __int64 v198; // r11
  __int64 v199; // r9
  int v201; // [sp+8h] [-1248h]
  int v202; // [sp+Ch] [-1244h]
  int v203; // [sp+10h] [-1240h]
  int v204; // [sp+14h] [-123Ch]
  int v205; // [sp+18h] [-1238h]
  int v206; // [sp+1Ch] [-1234h]
  int v207; // [sp+50h] [-1200h]
  int v208; // [sp+54h] [-11FCh]
  idTreeAnimator v209; // [sp+60h] [-11F0h] BYREF

  RD_EventBegin(name: "idGoreComponent::UpdateGore");
  LODWORD(v2) = "idGoreComponent::UpdateGore";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v209.deferredOrigin, pl: &pLog, gMask: v2, label: v3);
  idGoreComponent::UpdateDeathFade(this);
  idGoreComponent::TestGoreCheat(this);
  spawnId = this->presentable.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == this->presentable.spawnId
    && this->goreDecl != nullptr
    && this->goredPiecesInUse.num != 0
    && !common->IsMultiplayer(this: common) )
  {
    v6 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v6);
    idGoreComponent::UpdateFloorTrace(this);
    v8 = 0;
    num = this->goredPiecesInUse.num;
    if ( num > 0 )
    {
      v10 = 0;
      do
      {
        v11 = &this->goredPiecesInUse.list[v10];
        LODWORD(v12) = (unsigned __int16)v11->goreIndex;
        HIDWORD(v12) = v11->activated;
        LODWORD(v13) = (__int16)v12;
        v14 = &this->goreDecl->gorePieces.list[(__int16)v12];
        if ( !v11->activated )
        {
          LODWORD(v15) = &this->goredPiecesInUse.list[v10];
          HIDWORD(v15) = *(_DWORD *)(v15 + 40);
          if ( SHIDWORD(v15) > 1 )
          {
            HIDWORD(v13) = v14->name.str;
            v17 = va::va(
                    this: (va *)&v209.gameParmBlock,
                    fmt: "%s is about to come online.  Checking override list...",
                    a3: v13,
                    a4: v12,
                    a5: v15,
                    a6: v201,
                    a7: v202,
                    a8: v203,
                    a9: v204,
                    a10: v205,
                    a11: v206);
            if ( g_debugGore.valueInteger != 0 )
              idLib::Printf(fmt: "%s\n", v17->buffer);
            v18 = 0;
            num = this->goredPiecesInUse.num;
            if ( num > 0 )
            {
              v19 = 0;
              do
              {
                goreIndex = this->goredPiecesInUse.list[v19].goreIndex;
                if ( goreIndex != -1 )
                {
                  LODWORD(v16) = this->goreDecl;
                  v21 = 248 * goreIndex;
                  LODWORD(v23) = v14->overrideList.num;
                  v22 = (_DWORD *)(v21 + *(_DWORD *)(v16 + 64));
                  HIDWORD(v23) = 0;
                  if ( (int)v23 <= 0 )
                  {
LABEL_20:
                    v25 = 0;
                  }
                  else
                  {
                    LODWORD(v16) = v14->overrideList.list;
                    v24 = 0;
                    HIDWORD(v16) = *v22;
                    while ( HIDWORD(v16) != *(_DWORD *)(v24 + v16) )
                    {
                      ++HIDWORD(v23);
                      v24 += 4;
                      if ( SHIDWORD(v23) >= (int)v23 )
                        goto LABEL_20;
                    }
                    v25 = 1;
                  }
                  if ( v25 != 0 )
                  {
                    LODWORD(v26) = *v22;
                    HIDWORD(v26) = v14->name.str;
                    v28 = va::va(
                            this: (va *)&v209.gameParmBlock,
                            fmt: "\t%s overrides %s",
                            a3: v26,
                            a4: v16,
                            a5: v23,
                            a6: v201,
                            a7: v202,
                            a8: v203,
                            a9: v204,
                            a10: v205,
                            a11: v206);
                    if ( g_debugGore.valueInteger != 0 )
                      idLib::Printf(fmt: "%s\n", v28->buffer);
                    if ( !this->goredPiecesInUse.list[v19].activated || (v29 = 1, v22[61] == 0) )
                      v29 = 0;
                    v30 = v29;
                    idGoreComponent::DisableGorePiece(
                      this,
                      gibIdx: this->goredPiecesInUse.list[v19].goreIndex,
                      pos: &this->goredPiecesInUse.list[v10].initialGibJointPos,
                      impulse: &this->goredPiecesInUse.list[v10].impulse,
                      a5: v27);
                    if ( v30 != 0 )
                      this->goredPiecesInUse.list[v10].gibMeshSpawned = true;
                  }
                }
                ++v18;
                ++v19;
                num = this->goredPiecesInUse.num;
              }
              while ( v18 < num );
            }
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < num );
    }
    v208 = 0;
    if ( num > 0 )
    {
      v31 = 0;
      v209.debugName = (const char *)&g_debugGoreCloth;
      LODWORD(v209.deferredAxis.mat[0].y) = &mat3_identity;
      v209.nextOnCommitList = (idRenderModel *)"\tCloth was directly shot off";
      LODWORD(v209.deferredAxis.mat[1].z) = "Gore decl '%s' Failed to find valid tag '%s'";
      *(_DWORD *)&v209.useDeferredPosition = "\tAdding cloth %s";
      LODWORD(v209.deferredAxis.mat[1].x) = "Couldn't find valid clip shape '%d' in '%s'";
      LODWORD(v209.deferredAxis.mat[0].z) = "Invalid clip sphere index %d";
      LODWORD(v209.deferredAxis.mat[2].z) = "%s with goreLevel %d at index %d has clip spheres, but no morph vertices";
      LODWORD(v209.deferredAxis.mat[2].x) = "\tBreaking constraint %s";
      LODWORD(v209.deferredOrigin.z) = "\tHiding mesh kit [%s] %s";
      *(_DWORD *)&v209.needWriteToSnapshot = "\tShowing mesh kit [%s] %s";
      LODWORD(v209.deferredAxis.mat[0].x) = "\tPlaying fx %d";
      LODWORD(v209.deferredAxis.mat[2].y) = "Performing more gore work after 2 frames for %s";
      while ( 1 )
      {
        v32 = v31;
        if ( (unsigned __int16)this->goredPiecesInUse.list[v31].goreIndex != 0xFFFF )
          break;
LABEL_175:
        v31 = v208 + 1;
        num = this->goredPiecesInUse.num;
        v208 = v31;
        if ( v31 >= num )
          goto LABEL_176;
      }
      v33 = &this->goredPiecesInUse.list[v32];
      HIDWORD(v34) = this->goreDecl->gorePieces.list;
      LODWORD(v35) = (unsigned __int16)v33->goreIndex;
      HIDWORD(v35) = v33->frameCountSinceSpawn + 1;
      LODWORD(v36) = (__int16)v35;
      v33->frameCountSinceSpawn = HIDWORD(v35);
      list = this->goredPiecesInUse.list;
      v38 = (idGorePieceInfo_t *)(248 * (__int16)v35 + HIDWORD(v34));
      if ( list[v32].activated || (LODWORD(v34) = list[v32].frameCountSinceSpawn, (int)v34 <= 2) )
      {
LABEL_149:
        str = (char *)v38->jointToZeroOut.str;
        if ( str == &byte_8200D768 || (v84 = *str != 0, v173 = 0, !v84) )
          v173 = 1;
        if ( v173 == 0 )
        {
          idTreeAnimator::GetJointIndex(
            this: &v209,
            result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimator,
            jointName: this->goreDecl->gorePieces.list[this->goredPiecesInUse.list[v32].goreIndex].jointToZeroOut.str);
          if ( SHIWORD(v209.__vftable) >= 0 )
          {
            idTreeAnimator::SetJointScale(
              this: TreeAnimator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v209.__vftable),
              type: JOINTMOD_LOCAL_OVERRIDE,
              scale: &vec3_origin);
            idTreeAnimator::SetJointPos(
              this: TreeAnimator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v209.__vftable),
              type: JOINTMOD_LOCAL_OVERRIDE,
              pos: &vec3_origin);
          }
        }
        if ( this->goredPiecesInUse.list[v32].clothSim != nullptr )
        {
          v174 = this->presentable.spawnId;
          v175 = v174 & 0x3FFF;
          if ( v174 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v174 & 0x3FFF)
            || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v175))->spawnId != this->presentable.spawnId )
          {
            PresentableByIndex = nullptr;
          }
          v177 = &this->goredPiecesInUse.list[v32];
          v178 = PresentableByIndex->entity->GetAttachments_2(this: PresentableByIndex->entity);
          v179 = idAttachmentCollection::Get(this: v178, handle: &v177->clothAttachmentHandle);
          v180 = (const idVec3 **)v179;
          if ( v179->presentable != nullptr )
          {
            cloth = this->goredPiecesInUse.list[v32].clothSim->cloth;
            if ( cloth == nullptr || (v182 = cloth->state & 1, v183 = 1, v182 == 0) )
              v183 = 0;
            if ( v183 != 0 )
            {
              if ( g_debugGore.valueInteger != 0 )
                idLib::Printf(fmt: "%s\n", v209.nextOnCommitList);
              idGoreComponent::DisableCloth(this, iPieceInUse: v208, pos: *v180 + 10, dir: &vec3_origin);
            }
            else
            {
              model = (idTreeAnimator *)v179->presentable->model;
              model->useDeferredPosition = true;
              v185 = &this->goredPiecesInUse.list[v32];
              if ( this->goreDecl->gorePieces.list[v185->goreIndex].cloth.gibEntity != nullptr
                && v185->frameCountSinceSpawn > 120 )
              {
                idClothSimManager::UpdateWeaponTraces(this: &gameLocal->clothSimManager, clothSim: v185->clothSim);
              }
              idClothSimManager::UpdateJointsWithClothSim(
                this: &gameLocal->clothSimManager,
                ta: model,
                clothSim: this->goredPiecesInUse.list[v32].clothSim);
            }
          }
          clothSim = this->goredPiecesInUse.list[v32].clothSim;
          if ( clothSim != nullptr )
          {
            idClothSim::Run(this: clothSim, parallelJobList: gameLocal->parallelJobList);
            if ( *((_DWORD *)v209.debugName + 8) == 1 )
            {
              v187 = &this->goredPiecesInUse.list[v32];
              v188 = gameLocal->GetRenderWorld(this: gameLocal);
              idClothSim::DebugDraw(
                this: v187->clothSim,
                offset: &vec3_origin,
                axis: (const idMat3 *)LODWORD(v209.deferredAxis.mat[0].y),
                renderWorld: v188,
                debugLevel: 4);
            }
          }
        }
        goto LABEL_175;
      }
      HIDWORD(v36) = v38->name.str;
      v39 = va::va(
              this: (va *)&v209.gameParmBlock,
              fmt: (const char *)LODWORD(v209.deferredAxis.mat[2].y),
              a3: v36,
              a4: v35,
              a5: v34,
              a6: v201,
              a7: v202,
              a8: v203,
              a9: v204,
              a10: v205,
              a11: v206);
      if ( g_debugGore.valueInteger != 0 )
        idLib::Printf(fmt: "%s\n", v39);
      this->goredPiecesInUse.list[v32].activated = true;
      if ( v38->entityToSpawn == nullptr || (v40 = &this->goredPiecesInUse.list[v32])->gibMeshSpawned )
      {
LABEL_52:
        v57 = 0;
        if ( v38->fxToPlay.num > 0 )
        {
          v58 = 0;
          do
          {
            v59 = this->presentable.spawnId;
            v60 = v59 & 0x3FFF;
            if ( v59 == 0
              || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v59 & 0x3FFF)
              || (v61 = idClientGame::GetPresentableByIndex(this: clientGame, index: v60))->spawnId != this->presentable.spawnId )
            {
              v61 = nullptr;
            }
            v61->StartFX(this: v61, a2: v38->fxToPlay.list[v58], a3: FX_EXTRA_COND_NONE);
            HIDWORD(v62) = v38->fxToPlay.list[v58];
            v65 = va::va(
                    this: (va *)&v209.gameParmBlock,
                    fmt: (const char *)LODWORD(v209.deferredAxis.mat[0].x),
                    a3: v62,
                    a4: v64,
                    a5: v63,
                    a6: v201,
                    a7: v202,
                    a8: v203,
                    a9: v204,
                    a10: v205,
                    a11: v206);
            v39 = v65;
            if ( g_debugGore.valueInteger != 0 )
              idLib::Printf(fmt: "%s\n", v65);
            ++v57;
            ++v58;
          }
          while ( v57 < v38->fxToPlay.num );
        }
        v66 = 0;
        if ( v38->showKitInfo.num > 0 )
        {
          v67 = 0;
          do
          {
            v68 = &v38->showKitInfo.list[v67];
            v69 = (char *)v68->meshKit.str;
            if ( v68->meshKit.str == &byte_8200D768 || (v70 = 0, *v69 == 0) )
              v70 = 1;
            if ( v70 == 0 )
            {
              idTreeAnimator::ShowKit(
                this: (idTreeAnimator *)&v209.g.maxVisibleRange,
                result: (idStr *)TreeAnimator,
                kitType: v68->kitType,
                name: v69);
              idStr::FreeData(this: (idStr *)&v209.g.maxVisibleRange);
              LODWORD(v71) = 4 * v68->kitType;
              LODWORD(v72) = v68->meshKit.str;
              HIDWORD(v72) = *(const char **)((char *)goreKitTypeNames + v71);
              v39 = va::va(
                      this: (va *)&v209.gameParmBlock,
                      fmt: *(const char **)&v209.needWriteToSnapshot,
                      a3: v72,
                      a4: v73,
                      a5: v71,
                      a6: v201,
                      a7: v202,
                      a8: v203,
                      a9: v204,
                      a10: v205,
                      a11: v206);
              if ( g_debugGore.valueInteger != 0 )
                idLib::Printf(fmt: "%s\n", v39);
            }
            ++v66;
            ++v67;
          }
          while ( v66 < v38->showKitInfo.num );
        }
        v74 = 0;
        if ( v38->hideKitInfo.num > 0 )
        {
          v75 = 0;
          do
          {
            v76 = &v38->hideKitInfo.list[v75];
            v77 = (char *)v76->meshKit.str;
            if ( v76->meshKit.str == &byte_8200D768 || (v78 = 0, *v77 == 0) )
              v78 = 1;
            if ( v78 == 0 )
            {
              idTreeAnimator::HideKit(this: TreeAnimator, kitType: v76->kitType, name: v77);
              LODWORD(v79) = 4 * v76->kitType;
              LODWORD(v80) = v76->meshKit.str;
              HIDWORD(v80) = *(const char **)((char *)goreKitTypeNames + v79);
              v39 = va::va(
                      this: (va *)&v209.gameParmBlock,
                      fmt: (const char *)LODWORD(v209.deferredOrigin.z),
                      a3: v80,
                      a4: v81,
                      a5: v79,
                      a6: v201,
                      a7: v202,
                      a8: v203,
                      a9: v204,
                      a10: v205,
                      a11: v206);
              if ( g_debugGore.valueInteger != 0 )
                idLib::Printf(fmt: "%s\n", v39);
            }
            ++v74;
            ++v75;
          }
          while ( v74 < v38->hideKitInfo.num );
        }
        if ( (v38->goreType & 0x80) != 0 )
        {
          v82 = (char *)v38->constraintToBreak.str;
          if ( v82 == &byte_8200D768 || (v84 = *v82 != 0, v83 = 0, !v84) )
            v83 = 1;
          if ( v83 == 0 )
          {
            v85 = this->presentable.spawnId;
            v86 = v85 & 0x3FFF;
            if ( v85 == 0
              || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v85 & 0x3FFF)
              || (v87 = idClientGame::GetPresentableByIndex(this: clientGame, index: v86))->spawnId != this->presentable.spawnId )
            {
              v87 = nullptr;
            }
            entity = v87->entity;
            if ( entity != nullptr && entity->GetAF_2(this: v87->entity) != nullptr )
            {
              v89 = v38->constraintToBreak.str;
              v90 = &this->goredPiecesInUse.list[v32];
              v91 = entity->GetAF_2(this: entity);
              idAnimator_AF::BreakConstraint(this: v91, constraintName: v89, impulse: &v90->impulse);
              v92 = (int)entity->GetAF_2(this: entity);
              v93 = (int)entity->GetAF_2(this: entity);
              v94 = *(_DWORD *)(v92 + 288);
              v95 = v93;
              v97 = v93 + 288;
              v96 = v92 + 288;
              v98 = *(_DWORD *)(v95 + 288);
              v99 = (*(int (__fastcall **)(int, int))(v94 + 36))(a1: v96, a2: -1);
              (*(void (__fastcall **)(int, unsigned int, int))(v98 + 32))(a1: v97, a2: v99 & 0xFFFFFF7F, a3: -1);
              HIDWORD(v100) = v38->constraintToBreak.str;
              v39 = va::va(
                      this: (va *)&v209.gameParmBlock,
                      fmt: (const char *)LODWORD(v209.deferredAxis.mat[2].x),
                      a3: v100,
                      a4: v102,
                      a5: v101,
                      a6: v201,
                      a7: v202,
                      a8: v203,
                      a9: v204,
                      a10: v205,
                      a11: v206);
              if ( g_debugGore.valueInteger != 0 )
                idLib::Printf(fmt: "%s\n", v39);
            }
          }
        }
        v103 = 0;
        if ( v38->morphVertIndex.num > 0 )
        {
          v104 = 0;
          do
          {
            idTreeAnimator::MorphLocation(
              this: TreeAnimator,
              morphAmount: 1.0,
              morphIndex: (int)v39,
              a4: v38->morphVertIndex.list[v104]);
            HIDWORD(v105) = v38->morphVertIndex.list[v104];
            v39 = va::va(
                    this: (va *)&v209.gameParmBlock,
                    fmt: "\tMorphing verts with index %d",
                    a3: v105,
                    a4: v107,
                    a5: v106,
                    a6: v201,
                    a7: v202,
                    a8: v203,
                    a9: v204,
                    a10: v205,
                    a11: v206);
            if ( g_debugGore.valueInteger != 0 )
              idLib::Printf(fmt: "%s\n", v39);
            ++v103;
            ++v104;
          }
          while ( v103 < v38->morphVertIndex.num );
        }
        type = v38->clipShape.type;
        if ( type == CLIPSHAPETYPE_SPHERE )
        {
          v109 = (float)(v38->clipShape.axis.mat[0].y * v38->clipShape.axis.mat[0].y);
          x = v38->clipShape.axis.mat[0].x;
          z = v38->clipShape.axis.mat[1].z;
          v112 = v38->clipShape.axis.mat[0].z;
          v113 = (float)(v38->clipShape.axis.mat[2].y * v38->clipShape.axis.mat[2].y);
          v114 = v38->clipShape.axis.mat[2].x;
          v115 = v38->clipShape.axis.mat[2].z;
          v116 = this->goredPiecesInUse.list[v32].goreIndex;
          v117 = (float)((float)(v38->clipShape.axis.mat[1].x * v38->clipShape.axis.mat[1].x)
                       + (float)(v38->clipShape.axis.mat[1].y * v38->clipShape.axis.mat[1].y));
          v209.g.axis.mat[2].z = v38->clipShape.origin.x;
          v118 = v38->clipShape.origin.z;
          v209.g.scale.x = v38->clipShape.origin.y;
          v209.g.scale.y = v118;
          _FP7 = (float)((float)((float)((float)v112 * (float)v112) + (float)((float)((float)x * (float)x) + (float)v109))
                       - (float)((float)((float)z * (float)z) + (float)v117));
          __asm { fsel      f6, f7, f9, f10 }
          _FP5 = (float)((float)_FP6
                       - (float)((float)((float)v115 * (float)v115)
                               + (float)((float)((float)v114 * (float)v114) + (float)v113)));
          __asm { fsel      f4, f5, f6, f8 }
          v209.g.scale.z = (float)1.0 / (float)__fsqrts(_FP4);
          idGoreComponent::SetClipSphereRenderParms(
            this,
            woundSphere: (const idVec4 *)&v209.g.axis.mat[2].z,
            clipSphereIndex: v116);
        }
        else if ( type == CLIPSHAPETYPE_ELLIPSOID )
        {
          idGoreComponent::SetClipEllipsoidRenderParms(
            this,
            pos: &v38->clipShape.origin,
            axis: &v38->clipShape.axis,
            clipEllipsoidIndex: this->goredPiecesInUse.list[v32].goreIndex);
        }
        v123 = v38->clipSphereIndex.num;
        if ( v123 <= 0 || (v124 = TreeAnimator->decl->morphVertices) != nullptr && v124->morphVertSet.num != 0 )
        {
          v125 = 0;
          if ( v123 > 0 )
          {
            v126 = 0;
            do
            {
              v127 = v38->clipSphereIndex.list;
              v128 = &v127[v126];
              v129 = v127[v126];
              if ( v129 >= 0 )
              {
                v130 = 0;
                morphVertices = TreeAnimator->decl->morphVertices;
                v207 = morphVertices->morphVertSet.num;
                if ( v207 > 0 )
                {
                  v132 = morphVertices->morphVertSet.list;
                  v133 = 0;
                  while ( (v132[v133].flags & 0x18) == 0 || v132[v133].jointGroupIndex != v129 )
                  {
                    ++v130;
                    ++v133;
                    if ( v130 >= v207 )
                      goto LABEL_124;
                  }
                  v134 = &v132[v130];
                  flags = v134->flags;
                  if ( flags == 8 )
                  {
                    v136 = (float)((float)1.0 / v134->size.x);
                    y = v134->pos.y;
                    v138 = v134->pos.z;
                    v209.g.axis.mat[1].y = v134->pos.x;
                    v209.g.axis.mat[1].z = y;
                    v209.g.axis.mat[2].x = v138;
                    v209.g.axis.mat[2].y = v136;
                    idGoreComponent::SetClipSphereRenderParms(
                      this,
                      woundSphere: (const idVec4 *)&v209.g.axis.mat[1].y,
                      clipSphereIndex: *v128);
                  }
                  else if ( flags == 16 )
                  {
                    idGoreComponent::SetClipEllipsoidRenderParms(
                      this,
                      pos: &v134->pos,
                      axis: &v134->axis,
                      clipEllipsoidIndex: v129);
                  }
                  else
                  {
                    v139 = this->presentable.spawnId;
                    v140 = v139 & 0x3FFF;
                    if ( v139 == 0
                      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v139 & 0x3FFF)
                      || (v141 = idClientGame::GetPresentableByIndex(this: clientGame, index: v140))->spawnId != this->presentable.spawnId )
                    {
                      v141 = nullptr;
                    }
                    idLib::Warning(
                      fmt: (const char *)LODWORD(v209.deferredAxis.mat[1].x),
                      v38->clipSphereIndex.list[v126],
                      v141->model->name.str);
                  }
                }
              }
              else
              {
                idLib::Warning(fmt: (const char *)LODWORD(v209.deferredAxis.mat[0].z), v127[v126]);
              }
LABEL_124:
              ++v125;
              ++v126;
            }
            while ( v125 < v38->clipSphereIndex.num );
          }
        }
        else
        {
          idLib::Warning(
            fmt: (const char *)LODWORD(v209.deferredAxis.mat[2].z),
            v38->name.str,
            v38->goreLevel,
            this->goredPiecesInUse.list[v32].goreIndex);
        }
        clothDecl = v38->cloth.clothDecl;
        if ( clothDecl != nullptr && clothDecl->clothMD6 != nullptr )
        {
          v143 = this->presentable.spawnId;
          p_presentable = &this->presentable;
          v145 = v143 & 0x3FFF;
          if ( v143 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v143 & 0x3FFF)
            || (v146 = idClientGame::GetPresentableByIndex(this: clientGame, index: v145))->spawnId != p_presentable->spawnId )
          {
            v146 = nullptr;
          }
          if ( v146->entity != nullptr )
          {
            v147 = p_presentable->spawnId & 0x3FFF;
            if ( p_presentable->spawnId == 0
              || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_presentable->spawnId & 0x3FFF)
              || (v148 = idClientGame::GetPresentableByIndex(this: clientGame, index: v147))->spawnId != p_presentable->spawnId )
            {
              v148 = nullptr;
            }
            if ( v148->entity->GetAttachments_2(this: v148->entity) != nullptr )
            {
              v149 = v38->cloth.clothAttachTag.str;
              PropsCollection = idTreeAnimator::GetPropsCollection(this: TreeAnimator);
              Tag = idPropsCollection::GetTag(
                      this: PropsCollection,
                      propName: idPropInfo::INFO_PROP_NAME,
                      tagName: v149);
              HIDWORD(v152) = clothDecl->name.str;
              v155 = va::va(
                       this: (va *)&v209.gameParmBlock,
                       fmt: *(const char **)&v209.useDeferredPosition,
                       a3: v152,
                       a4: v154,
                       a5: v153,
                       a6: v201,
                       a7: v202,
                       a8: v203,
                       a9: v204,
                       a10: v205,
                       a11: v206);
              if ( g_debugGore.valueInteger != 0 )
                idLib::Printf(fmt: "%s\n", v155);
              v156 = idClothSimManager::ReserveCloth(this: &gameLocal->clothSimManager, decl: clothDecl);
              v157 = v156;
              if ( Tag->parentJoint.value == 0xFFFF )
              {
                idLib::Warning(
                  fmt: (const char *)LODWORD(v209.deferredAxis.mat[1].z),
                  this->goreDecl->name.str,
                  v38->cloth.clothAttachTag.str);
              }
              else if ( v156 != nullptr )
              {
                v158 = &this->goredPiecesInUse.list[v32];
                v158->clothTagData.trans.x = Tag->trans.x;
                v158->clothTagData.trans.y = Tag->trans.y;
                v158->clothTagData.trans.z = Tag->trans.z;
                v158->clothTagData.rot.x = Tag->rot.x;
                v158->clothTagData.rot.y = Tag->rot.y;
                v158->clothTagData.rot.z = Tag->rot.z;
                v158->clothTagData.rot.w = Tag->rot.w;
                v158->clothTagData.parentJoint.value = Tag->parentJoint.value;
                v159 = p_presentable->spawnId & 0x3FFF;
                if ( p_presentable->spawnId == 0
                  || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_presentable->spawnId & 0x3FFF)
                  || (v160 = idClientGame::GetPresentableByIndex(this: clientGame, index: v159))->spawnId != p_presentable->spawnId )
                {
                  v160 = nullptr;
                }
                clothMD6 = clothDecl->clothMD6;
                v162 = &this->goredPiecesInUse.list[v32];
                v163 = idPropInfo::INFO_PROP_NAME;
                v164 = v38->cloth.clothAttachTag.str;
                v165 = clothMD6->name.str;
                v166 = (idList<idAttachment,5> *)v160->entity->GetAttachments_2(this: v160->entity);
                v167 = idAttachmentCollection::AddAttachment(
                         this: (idAttachmentCollection *)&v209.deferredAxis.mat[1].y,
                         result: v166,
                         modelName: v165,
                         propName: v163,
                         tag: v164,
                         tagInfo: nullptr,
                         allowDuplicate: true);
                p_firstVisibleFrameCount = &v209.g.firstVisibleFrameCount;
                p_z = (idTreeAnimator *)&TreeAnimator->g.origin.z;
                v162->clothAttachmentHandle.value = (int)v167->attachments.list;
                this->goredPiecesInUse.list[v32].clothSim = v157;
                v170 = 9;
                v209.referenceBounds.b[0].y = TreeAnimator->g.origin.z;
                v171 = TreeAnimator->g.origin.y;
                v209.committed = (idRenderModelCommitted *)LODWORD(TreeAnimator->g.origin.x);
                v209.referenceBounds.b[0].x = v171;
                do
                {
                  p_z = (idTreeAnimator *)((char *)p_z + 4);
                  *++p_firstVisibleFrameCount = (int)p_z->__vftable;
                  --v170;
                }
                while ( v170 != 0 );
                idClothSim::SetOriginAxis(
                  this: v157,
                  newOrigin: (const idVec3 *)&v209.committed,
                  newAxis: (const idMat3 *)&v209.g.fovScale,
                  updateParticles: true);
              }
            }
          }
        }
        goto LABEL_149;
      }
      spawnedEntityImpulseBehavior = v38->spawnedEntityImpulseBehavior;
      if ( spawnedEntityImpulseBehavior != 0 )
      {
        if ( spawnedEntityImpulseBehavior == 1 )
        {
          v42 = v40->impulse.y;
          v43 = v40->impulse.z;
          *((float *)&v209.__vftable + 2) = -v40->impulse.x;
          v44 = -v43;
          *((float *)&v209.__vftable + 3) = -v42;
LABEL_47:
          *(float *)&v209.name.str = v44;
          goto LABEL_48;
        }
        if ( spawnedEntityImpulseBehavior < 3 )
        {
          *((float *)&v209.__vftable + 2) = 0.0;
          *((float *)&v209.__vftable + 3) = 0.0;
          *(float *)&v209.name.str = 1.0;
LABEL_48:
          if ( (unsigned __int8)idGorePieceInfo_t::EntityToSpawnIsABreakable(this: v38) != 0 )
          {
            p_breakableManager = &gameLocal->breakableManager;
            v45 = &this->goredPiecesInUse.list[v32];
            v47 = idQuat::ToMat3(this: (idQuat *)&v209.g.fovScale, result: (idMat3 *)v45);
            idBreakableManager::UseBreakable(
              this: p_breakableManager,
              decl: v38->entityToSpawn,
              origin: &v45->initialGibJointPos,
              axis: v47,
              dir: (const idVec3 *)(&v209.__vftable + 2),
              pos: &v45->initialGibJointPos,
              impulse: 200.0,
              fadeTime: 0.0);
          }
          else
          {
            v48 = __PAIR64__((idCVar *)&ai_useTurnTransitions.valueString.baseBuffer[12], (unsigned int)clientGame);
            HIDWORD(v49) = clientGame->random.seed;
            clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
            LODWORD(v49) = (*(_DWORD *)v48 >> 10) & 0x7FFF;
            LODWORD(v48) = clientGame;
            *(_QWORD *)&v209.g.customMaterial = v49;
            HIDWORD(v50) = 1664525 * clientGame->random.seed + 1013904223;
            v51 = (double)v49;
            clientGame->random.seed = HIDWORD(v50);
            LODWORD(v50) = (*(_DWORD *)v48 >> 10) & 0x7FFF;
            LODWORD(v49) = clientGame->random.seed;
            v52 = 1664525 * clientGame->random.seed + 1013904223;
            *(_QWORD *)&v209.g.suppressSurfaceInViewID = v50;
            clientGame->random.seed = v52;
            LODWORD(v48) = ((unsigned int)(1664525 * v49 + 1013904223) >> 10) & 0x7FFF;
            v209.referenceBounds.b[1].z = *(float *)&v209.name.str * (float)350.0;
            *(_QWORD *)&v209.g.groupMasterIndex = v48;
            v53 = (double)v48;
            LODWORD(v48) = this->goredPiecesInUse.list;
            v209.g.axis.mat[0].x = (float)((float)v51 * (float)0.000030518509) * (float)25.0;
            v209.referenceBounds.b[1].y = *((float *)&v209.__vftable + 3) * (float)350.0;
            v209.referenceBounds.b[1].x = *((float *)&v209.__vftable + 2) * (float)350.0;
            v209.g.origin.z = (float)((float)v50 * (float)0.000030518509) * (float)25.0;
            v54 = v32 * 104 + v48;
            p_spawnablePropManager = &gameLocal->spawnablePropManager;
            v209.g.origin.y = (float)((float)v53 * (float)0.000030518509) * (float)25.0;
            v56 = idQuat::ToMat3(this: (idQuat *)&v209.g.fovScale, result: (idMat3 *)(v32 * 104 + v48));
            idSpawnablePropManager::UseSpawnable(
              this: p_spawnablePropManager,
              decl: v38->entityToSpawn,
              origin: (const idVec3 *)(v54 + 16),
              axis: v56,
              linearVelocity: &v209.referenceBounds.b[1],
              angularVelocity: (const idVec3 *)&v209.g.origin.y);
          }
          this->goredPiecesInUse.list[v32].gibMeshSpawned = true;
          goto LABEL_52;
        }
      }
      *((float *)&v209.__vftable + 2) = v40->impulse.x;
      *((float *)&v209.__vftable + 3) = v40->impulse.y;
      v44 = v40->impulse.z;
      goto LABEL_47;
    }
LABEL_176:
    v189 = num - 1;
    LODWORD(v209.deferredAxis.mat[1].y) = num;
    if ( num - 1 >= 0 )
    {
      p_goredPiecesInUse = &this->goredPiecesInUse;
      v191 = v189;
      do
      {
        if ( (unsigned __int16)p_goredPiecesInUse->list[v191].goreIndex == 0xFFFF && v189 >= 0 )
        {
          v192 = this->goredPiecesInUse.num;
          if ( v189 < v192 )
          {
            v193 = v192 - 1;
            this->goredPiecesInUse.num = v193;
            if ( v189 != v193 )
              idGoreComponent::goredPiecesInUse_t::operator=(
                this: &p_goredPiecesInUse->list[v191],
                __that: &p_goredPiecesInUse->list[v193]);
          }
        }
        --v189;
        --v191;
      }
      while ( v189 >= 0 );
    }
    v194 = (-this->goredPiecesInUse.num & (unsigned int)~this->goredPiecesInUse.num) >> 31;
    if ( v209.deferredOrigin.x >= 0.0 )
    {
      v195 = v209.deferredOrigin.y;
      v196 = *(_DWORD *)(LODWORD(v209.deferredOrigin.y) + 16) + 16 * LODWORD(v209.deferredOrigin.x);
      v197 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v198 = *(_QWORD *)(v196 + 8);
      HIDWORD(v198) = *(_DWORD *)(v196 + 4);
      LODWORD(v199) = v197 - v198;
      *(_QWORD *)(v196 + 8) = v199;
      *(_DWORD *)(LODWORD(v195) + 32) = HIDWORD(v198);
    }
    RD_EventEnd();
    return v194;
  }
  else
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v209.deferredOrigin);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$496336
// EA  : 0x82C60848
// RVA : 0x00C60848
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_496336()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4688 + 4480));
}


// ========================================================================
// __unwind$496337
// EA  : 0x82C60870
// RVA : 0x00C60870
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_496337()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4688 + 120));
}


// ========================================================================
// ?CheckForGore@idGoreComponent@@QAA_NXZ
// EA  : 0x82C608A0
// RVA : 0x00C608A0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

int __fastcall idGoreComponent::CheckForGore(idGoreComponent *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  const idDeclGore *goreDecl; // r11
  idCVar *v5; // r25
  const char *v6; // r24
  idPresentableAnimatedEntity *v7; // r3
  idTreeAnimator *TreeAnimator; // r28
  const idVec3 *v9; // r5
  int num; // r11
  int v11; // r30
  idGoreComponent::goreFrameDamage_t *v12; // r11
  const idDeclDamage *damageDecl; // r4
  idDeclDamage::goreType_t goreTypes; // r10
  idDeclGoreBehavior *declGoreBehavior; // r9
  int v16; // r11
  int v17; // r3
  int v18; // r16
  const idVec3 *p_deferredOrigin; // r5
  idPresentable *v20; // r3
  idPresentable *v21; // r3
  double v23; // fp11
  double v24; // fp9
  double damage; // fp1
  const idDeclGore *v26; // r10
  int v27; // r4
  __int64 v28; // r6
  __int64 v29; // r8
  __int64 v30; // r10
  int v31; // r23
  int v32; // r28
  int v33; // r11
  int v34; // r11
  encounterGroupRole_t *v35; // r11
  va *v36; // r4
  __int64 v37; // r8
  double v38; // fp28
  char v39; // r24
  __int64 v40; // r10
  int v41; // r25
  double z; // fp29
  int v43; // r27
  double y; // fp30
  double x; // fp31
  unsigned __int64 v46; // r6
  const char *v47; // r7
  int v48; // r29
  encounterGroupRole_t *list; // r8
  int v50; // r30
  int v51; // r3
  idGoreComponent::goreFrameDamage_t *v52; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v54; // r30
  int v55; // r3
  __int64 totalTicks; // r11
  __int64 v57; // r9
  double v60; // fp7
  double v61; // fp0
  idPLog *v62; // r29
  idPLog::logEntry_t *v63; // r30
  int v64; // r3
  __int64 v65; // r11
  __int64 v66; // r9
  __int64 v67; // r6
  va *v68; // r4
  idPLog *v69; // r29
  idPLog::logEntry_t *v70; // r30
  int v71; // r3
  __int64 v72; // r11
  __int64 v73; // r9
  int v74; // [sp+8h] [-1208h]
  int v75; // [sp+Ch] [-1204h]
  int v76; // [sp+10h] [-1200h]
  int v77; // [sp+14h] [-11FCh]
  int v78; // [sp+18h] [-11F8h]
  int v79; // [sp+1Ch] [-11F4h]
  encounterGroupRole_t *v80; // [sp+50h] [-11C0h] BYREF
  idVec3 v81; // [sp+58h] [-11B8h] BYREF
  idPLog *p_impulse; // [sp+64h] [-11ACh]
  idCVar *v83; // [sp+68h] [-11A8h]
  idPLogScope v84; // [sp+70h] [-11A0h] BYREF
  idPLogScope v85; // [sp+78h] [-1198h] BYREF
  const char *v86; // [sp+80h] [-1190h]
  idList<enum encounterGroupRole_t,5> v87; // [sp+90h] [-1180h] BYREF
  int v88; // [sp+A0h] [-1170h] BYREF
  idList<enum encounterGroupRole_t,5> v89; // [sp+E0h] [-1130h] BYREF
  int v90; // [sp+F0h] [-1120h] BYREF
  va v91; // [sp+130h] [-10E0h] BYREF

  RD_EventBegin(name: "idGoreComponent::CheckForGore");
  LODWORD(v2) = "idGoreComponent::CheckForGore";
  HIDWORD(v2) = 2;
  p_impulse = &::pLog;
  idPLogScope::idPLogScope(this: &v85, pl: &::pLog, gMask: v2, label: v3);
  if ( g_EnableGore.valueInteger == 0
    || common->IsMultiplayer(this: common)
    || (goreDecl = this->goreDecl) == nullptr
    || goreDecl->gorePieces.num == 0
    || this->frameDamage.num == 0
    || idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable) == nullptr
    || idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable)->model->g.modelFade < 0.5 )
  {
    if ( this->frameDamage.size < 0 )
      idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
    this->frameDamage.num = __CFADD__(-this->frameDamage.size, this->frameDamage.size ^ 0x80000000)
                          ? 0
                          : this->frameDamage.size;
    idPLogScope::~idPLogScope(this: &v85);
    goto LABEL_86;
  }
  v5 = &g_debugGore;
  v6 = "%s\n";
  v83 = &g_debugGore;
  v86 = "%s\n";
  if ( g_debugGore.valueInteger != 0 )
    idLib::Printf(fmt: "%s\n", "CheckForGore()");
  v87.granularity = 1;
  v87.size = 16;
  v87.num = 0;
  v87.memTag = 5;
  v87.list = (encounterGroupRole_t *)&v88;
  v87.listStatic = 1;
  v89.size = 16;
  v89.num = 0;
  v89.granularity = 1;
  v89.list = (encounterGroupRole_t *)&v90;
  v89.memTag = 5;
  v89.listStatic = 1;
  idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5>::SetNum(
    this: (idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5> *)&this->jointsGoredThisFrame,
    newNum: 0);
  v7 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v7);
  if ( this->goredPiecesInUse.num < 16 )
  {
    num = this->frameDamage.num;
    v11 = 0;
    v80 = nullptr;
    if ( num > 0 )
    {
      do
      {
        if ( v11 >= 16 )
          break;
        v12 = &this->frameDamage.list[v11];
        damageDecl = v12->damageDecl;
        if ( damageDecl != nullptr )
        {
          goreTypes = damageDecl->goreTypes;
          declGoreBehavior = damageDecl->declGoreBehavior;
          if ( (goreTypes & 0x100) != 0 )
          {
            p_deferredOrigin = &TreeAnimator->deferredOrigin;
            if ( !TreeAnimator->useDeferredPosition )
              p_deferredOrigin = &TreeAnimator->g.origin;
            idGoreComponent::ActivateBFGExplosion(this, damageDecl, impactPoint: p_deferredOrigin, dir: &v12->impulse);
            if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable)->entity != nullptr )
            {
              v20 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
              v20->entity->Hide_2(this: v20->entity);
            }
            v21 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
            v21->Hide(this: v21, a2: true);
            idList<idGoreComponent::goreFrameDamage_t,5>::SetNum(this: &this->frameDamage, newNum: 0);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v89);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v87);
            idPLogScope::~idPLogScope(this: &v85);
            RD_EventEnd();
            return 1;
          }
          if ( declGoreBehavior != nullptr && declGoreBehavior->enableFullBodyExplosion )
          {
            v23 = (float)(v12->impulse.z * damageDecl->ragdollImpulseMag);
            v24 = (float)(v12->impulse.y * damageDecl->ragdollImpulseMag);
            v81.x = v12->impulse.x * damageDecl->ragdollImpulseMag;
            v81.z = v23;
            v81.y = v24;
            p_impulse = (idPLog *)v12;
            damage = v12->damage;
            p_impulse = (idPLog *)&v12->impulse;
            idGoreComponent::ActivateFullBodyExplosion(this, damageDecl, damage, impulse: v9, a5: &v81);
            idList<idGoreComponent::goreFrameDamage_t,5>::SetNum(this: &this->frameDamage, newNum: 0);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v89);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v87);
            idPLogScope::~idPLogScope(this: &v85);
            RD_EventEnd();
            return 1;
          }
          if ( (goreTypes & 0x7FFFFFFF) != 0 )
          {
            idList<idAnimWebBlendTree *,5>::Append(this: &v87, obj: (encounterGroupRole_t *)&v80);
            idList<idAnimWebBlendTree *,5>::Append(
              this: &v89,
              obj: (encounterGroupRole_t *)&this->frameDamage.list[v11]);
          }
        }
        v16 = this->frameDamage.num;
        v80 = (encounterGroupRole_t *)++v11;
      }
      while ( v11 < v16 );
    }
  }
  if ( v87.num <= 0 )
  {
    if ( g_debugGore.valueInteger != 0 )
      idLib::Printf(fmt: "%s\n", "No valid impulses found");
    idList<idGoreComponent::goreFrameDamage_t,5>::SetNum(this: &this->frameDamage, newNum: 0);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v89);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v87);
    idPLogScope::~idPLogScope(this: &v85);
LABEL_86:
    RD_EventEnd();
    return 0;
  }
  v17 = idRandom2::RandomInt(this: &clientGame->random, min: 0, max: this->goreDecl->gorePieces.num - 1);
  v18 = 0;
  if ( this->goreDecl->gorePieces.num <= 0 )
    goto LABEL_65;
  while ( 1 )
  {
    v26 = this->goreDecl;
    v27 = this->goredPiecesInUse.num;
    LODWORD(v29) = 0;
    HIDWORD(v30) = __ROL4__(v17, 1) - 1;
    LODWORD(v28) = v26->gorePieces.num;
    HIDWORD(v29) = v26->gorePieces.list;
    v80 = (encounterGroupRole_t *)v27;
    LODWORD(v30) = v17 / (int)v28 * v28;
    v31 = v17 % (int)v28;
    __twlgei(v28 & ~HIDWORD(v30), 0xFFFFFFFF);
    __twllei(v28, 0);
    v32 = 248 * (v17 % (int)v28) + HIDWORD(v29);
    if ( v27 > 0 )
    {
      HIDWORD(v28) = this->goredPiecesInUse.list;
      HIDWORD(v30) = 0;
      LODWORD(v28) = &byte_8200D768;
      v33 = HIDWORD(v28);
      do
      {
        v34 = *(__int16 *)(v33 + 100);
        if ( v34 == v31 )
          break;
        v35 = (encounterGroupRole_t *)(248 * v34 + HIDWORD(v29) + 12);
        v80 = v35;
        if ( *(char **)v35 != &byte_8200D768 )
        {
          LOBYTE(v30) = 0;
          if ( **(_BYTE **)v35 != 0 )
            goto LABEL_89;
        }
        LOBYTE(v30) = 1;
LABEL_89:
        LODWORD(v30) = (unsigned __int8)v30;
        if ( (_BYTE)v30 == 0 )
        {
          LODWORD(v30) = *(_DWORD *)(v32 + 12);
          if ( *v35 == (_DWORD)v30 )
            break;
        }
        LODWORD(v29) = v29 + 1;
        HIDWORD(v30) += 104;
        v33 = HIDWORD(v30) + HIDWORD(v28);
      }
      while ( (int)v29 < this->goredPiecesInUse.num );
    }
    v80 = (encounterGroupRole_t *)v27;
    if ( (int)v29 < v27 )
    {
      HIDWORD(v28) = *(_DWORD *)v32;
      v36 = va::va(
              this: &v91,
              fmt: "Piece '%s' already gored",
              a3: v28,
              a4: v29,
              a5: v30,
              a6: v74,
              a7: v75,
              a8: v76,
              a9: v77,
              a10: v78,
              a11: v79);
      if ( v5->valueInteger != 0 )
        idLib::Printf(fmt: v6, v36);
      goto LABEL_62;
    }
    *(float *)&v40 = vec3_origin.x;
    v37 = __PAIR64__(LODWORD(vec3_origin.z), LODWORD(vec3_origin.y));
    v38 = 0.0;
    v39 = 0;
    LODWORD(v40) = *(_DWORD *)(v32 + 56);
    v41 = 0;
    v81 = vec3_origin;
    if ( (int)v40 > 0 )
    {
      z = v81.z;
      v43 = 0;
      y = v81.y;
      x = v81.x;
      while ( 1 )
      {
        RD_EventBegin(name: "idAI2::CheckForGore() - Checking Damage Groups");
        LODWORD(v46) = "idAI2::CheckForGore() - Checking Damage Groups";
        HIDWORD(v46) = 2;
        idPLogScope::idPLogScope(this: &v84, pl: p_impulse, gMask: v46, label: v47);
        v48 = 0;
        if ( v87.num > 0 )
        {
          list = v87.list;
          v50 = 0;
          do
          {
            if ( (this->frameDamage.list[list[v50]].damageDecl->goreTypes & *(_DWORD *)(v32 + 8) & 0xFFFFFFF7) != 0 )
            {
              v80 = &v89.list[v50];
              v51 = idStr::Icmp(
                      s1: *(const char **)(*(_DWORD *)(v32 + 52) + v43),
                      s2: *(const char **)(v89.list[v50] + 4));
              list = v87.list;
              if ( v51 == 0 )
              {
                v52 = &this->frameDamage.list[v87.list[v50]];
                v80 = (encounterGroupRole_t *)&v52->impulse;
                x = (float)((float)x + v52->impulse.x);
                y = (float)(v52->impulse.y + (float)y);
                z = (float)(v52->impulse.z + (float)z);
                v38 = (float)(v52->damage + (float)v38);
              }
            }
            ++v48;
            ++v50;
          }
          while ( v48 < v87.num );
        }
        if ( v38 >= *(float *)(v32 + 80) )
          break;
        if ( v84.logIndex >= 0 )
        {
          pLog = v84.pLog;
          v54 = &v84.pLog->logEntries.list[v84.logIndex];
          v55 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          totalTicks = v54->totalTicks;
          HIDWORD(totalTicks) = v54->parent;
          LODWORD(v57) = v55 - totalTicks;
          v84.logIndex = -1;
          v54->totalTicks = v57;
          pLog->lastEntry = HIDWORD(totalTicks);
        }
        RD_EventEnd();
        ++v41;
        v43 += 4;
        if ( v41 >= *(_DWORD *)(v32 + 56) )
        {
          v81.z = z;
          v81.y = y;
          v81.x = x;
          goto LABEL_58;
        }
      }
      v39 = 1;
      _FP10 = (float)((float)((float)((float)x * (float)x)
                            + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f8, f10, f11, f0 }
      v60 = __frsqrte(_FP8);
      v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                          * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v60)
                                                                          - (float)1.5)
                                                          * (float)v60)
                                                  * (float)((float)((float)((float)x * (float)x)
                                                                  + (float)((float)((float)z * (float)z)
                                                                          + (float)((float)y * (float)y)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v60
                                                                                  * (float)((float)((float)((float)x * (float)x)
                                                                                                  + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                          * (float)0.5))
                                                                          * (float)v60)
                                                                  - (float)1.5)
                                                  * (float)v60))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v60
                                                          * (float)((float)((float)((float)x * (float)x)
                                                                          + (float)((float)((float)z * (float)z)
                                                                                  + (float)((float)y * (float)y)))
                                                                  * (float)0.5))
                                                  * (float)v60)
                                          - (float)1.5)
                          * (float)v60));
      v81.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5) * (float)v60)
                                                                                            * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                            * (float)v60))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    * (float)((float)((float)((float)x * (float)x)
                                                                    + (float)((float)((float)z * (float)z)
                                                                            + (float)((float)y * (float)y)))
                                                            * (float)0.5))
                                            * (float)v61)
                                    - (float)1.5)
                    * (float)v61)
            * (float)x;
      v81.y = (float)y
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5) * (float)v60)
                                                                                            * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                            * (float)v60))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    * (float)((float)((float)((float)x * (float)x)
                                                                    + (float)((float)((float)z * (float)z)
                                                                            + (float)((float)y * (float)y)))
                                                            * (float)0.5))
                                            * (float)v61)
                                    - (float)1.5)
                    * (float)v61);
      v81.z = (float)z
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5) * (float)v60)
                                                                                            * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                            * (float)v60))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                            * (float)v60)
                                                                                    - (float)1.5)
                                                                    * (float)v60))
                                                    * (float)((float)((float)((float)x * (float)x)
                                                                    + (float)((float)((float)z * (float)z)
                                                                            + (float)((float)y * (float)y)))
                                                            * (float)0.5))
                                            * (float)v61)
                                    - (float)1.5)
                    * (float)v61);
      if ( v84.logIndex >= 0 )
      {
        v62 = v84.pLog;
        v63 = &v84.pLog->logEntries.list[v84.logIndex];
        v64 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v65 = v63->totalTicks;
        HIDWORD(v65) = v63->parent;
        LODWORD(v66) = v64 - v65;
        v84.logIndex = -1;
        v63->totalTicks = v66;
        v62->lastEntry = HIDWORD(v65);
      }
      RD_EventEnd();
    }
LABEL_58:
    if ( v39 != 0 )
      break;
    LODWORD(v67) = LODWORD(v38);
    HIDWORD(v67) = *(_DWORD *)v32;
    v68 = va::va(
            this: &v91,
            fmt: "Piece '%s' was not gored -- total damage = %f",
            a3: v67,
            a4: v37,
            a5: v40,
            a6: v74,
            a7: v75,
            a8: v76,
            a9: v77,
            a10: v78,
            a11: v79,
            v38);
    if ( v83->valueInteger != 0 )
      idLib::Printf(fmt: v86, v68);
    v5 = v83;
LABEL_62:
    ++v18;
    v17 = v31 + 1;
    if ( v18 >= this->goreDecl->gorePieces.num )
      goto LABEL_65;
    v6 = v86;
  }
  idGoreComponent::EnableGorePiece(this, gibIdx: v31, impulse: &v81);
LABEL_65:
  if ( this->frameDamage.size < 0 )
    idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->frameDamage.num = __CFADD__(-this->frameDamage.size, this->frameDamage.size ^ 0x80000000)
                        ? 0
                        : this->frameDamage.size;
  if ( v89.listStatic == 0 || v89.listStatic == 2 )
  {
    if ( v89.list != nullptr )
      idMem::Free(this: &mem, ptr: v89.list, align: ALIGN_16);
    v89.list = nullptr;
    v89.size = 0;
  }
  v89.num = 0;
  if ( v87.listStatic == 0 || v87.listStatic == 2 )
  {
    if ( v87.list != nullptr )
      idMem::Free(this: &mem, ptr: v87.list, align: ALIGN_16);
    v87.list = nullptr;
    v87.size = 0;
  }
  v87.num = 0;
  if ( v85.logIndex >= 0 )
  {
    v69 = v85.pLog;
    v70 = &v85.pLog->logEntries.list[v85.logIndex];
    v71 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v72 = v70->totalTicks;
    HIDWORD(v72) = v70->parent;
    LODWORD(v73) = v71 - v72;
    v70->totalTicks = v73;
    v69->lastEntry = HIDWORD(v72);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$497576
// EA  : 0x82C61194
// RVA : 0x00C61194
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497576()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4624 + 4400));
}


// ========================================================================
// __unwind$497577
// EA  : 0x82C611BC
// RVA : 0x00C611BC
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497577()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4624 + 120));
}


// ========================================================================
// __unwind$497578
// EA  : 0x82C611E4
// RVA : 0x00C611E4
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497578()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4624 + 144));
}


// ========================================================================
// __unwind$497579
// EA  : 0x82C6120C
// RVA : 0x00C6120C
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497579()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4624 + 224));
}


// ========================================================================
// __unwind$497580
// EA  : 0x82C61234
// RVA : 0x00C61234
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497580()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4624 + 4401));
}


// ========================================================================
// __unwind$497581
// EA  : 0x82C6125C
// RVA : 0x00C6125C
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _unwind_497581()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4624 + 112));
}


// ========================================================================
// `dynamic initializer for 'g_EnableGore''
// EA  : 0x833773E0
// RVA : 0x013773E0
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_EnableGore__()
{
  idCVar::idCVar(
    this: &g_EnableGore,
    name: "g_EnableGore",
    value: "1",
    flags: 2,
    description: "0 = only blood particles unless overridden, 1 = gore, 2 = no gore at all",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_EnableGore__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugGPUGore''
// EA  : 0x83377438
// RVA : 0x01377438
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugGPUGore__()
{
  idCVar::idCVar(
    this: &ai_debugGPUGore,
    name: "ai_debugGPUGore",
    value: "0",
    flags: 2,
    description: "shows the projection axis of wounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugGPUGore__);
}


// ========================================================================
// `dynamic initializer for 'g_debugGore''
// EA  : 0x83377490
// RVA : 0x01377490
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugGore__()
{
  idCVar::idCVar(
    this: &g_debugGore,
    name: "g_debugGore",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugGore__);
}


// ========================================================================
// `dynamic initializer for 'g_debugGoreCloth''
// EA  : 0x833774E8
// RVA : 0x013774E8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugGoreCloth__()
{
  idCVar::idCVar(
    this: &g_debugGoreCloth,
    name: "g_debugGoreCloth",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugGoreCloth__);
}


// ========================================================================
// `dynamic initializer for 'g_testGoreIndex''
// EA  : 0x83377540
// RVA : 0x01377540
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testGoreIndex__()
{
  idCVar::idCVar(
    this: &g_testGoreIndex,
    name: "g_testGoreIndex",
    value: "-1",
    flags: 10,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testGoreIndex__);
}


// ========================================================================
// `dynamic initializer for 'rp_Wound1Pos''
// EA  : 0x83377598
// RVA : 0x01377598
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound1Pos__()
{
  rp_Wound1Pos.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound1Pos;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound1Size''
// EA  : 0x833775B8
// RVA : 0x013775B8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound1Size__()
{
  rp_Wound1Size.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound1Size;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound1dirX''
// EA  : 0x833775D8
// RVA : 0x013775D8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound1dirX__()
{
  rp_Wound1dirX.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound1dirX;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound1dirY''
// EA  : 0x833775F8
// RVA : 0x013775F8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound1dirY__()
{
  rp_Wound1dirY.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound1dirY;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound1dirZ''
// EA  : 0x83377618
// RVA : 0x01377618
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound1dirZ__()
{
  rp_Wound1dirZ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound1dirZ;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosA''
// EA  : 0x83377638
// RVA : 0x01377638
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosA__()
{
  rp_Wound3PosA.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosA;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosB''
// EA  : 0x83377658
// RVA : 0x01377658
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosB__()
{
  rp_Wound3PosB.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosB;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosC''
// EA  : 0x83377678
// RVA : 0x01377678
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosC__()
{
  rp_Wound3PosC.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosC;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosD''
// EA  : 0x83377698
// RVA : 0x01377698
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosD__()
{
  rp_Wound3PosD.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosD;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosE''
// EA  : 0x833776B8
// RVA : 0x013776B8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosE__()
{
  rp_Wound3PosE.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosE;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosF''
// EA  : 0x833776D8
// RVA : 0x013776D8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosF__()
{
  rp_Wound3PosF.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosF;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosG''
// EA  : 0x833776F8
// RVA : 0x013776F8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosG__()
{
  rp_Wound3PosG.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosG;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosH''
// EA  : 0x83377718
// RVA : 0x01377718
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosH__()
{
  rp_Wound3PosH.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosH;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosI''
// EA  : 0x83377738
// RVA : 0x01377738
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosI__()
{
  rp_Wound3PosI.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosI;
}


// ========================================================================
// `dynamic initializer for 'rp_Wound3PosJ''
// EA  : 0x83377758
// RVA : 0x01377758
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_Wound3PosJ__()
{
  rp_Wound3PosJ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_Wound3PosJ;
}


// ========================================================================
// `dynamic initializer for 'rp_WoundEllipsoidX''
// EA  : 0x83377778
// RVA : 0x01377778
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_WoundEllipsoidX__()
{
  rp_WoundEllipsoidX.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_WoundEllipsoidX;
}


// ========================================================================
// `dynamic initializer for 'rp_WoundEllipsoidY''
// EA  : 0x83377798
// RVA : 0x01377798
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_WoundEllipsoidY__()
{
  rp_WoundEllipsoidY.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_WoundEllipsoidY;
}


// ========================================================================
// `dynamic initializer for 'rp_WoundEllipsoidZ''
// EA  : 0x833777B8
// RVA : 0x013777B8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_WoundEllipsoidZ__()
{
  rp_WoundEllipsoidZ.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_WoundEllipsoidZ;
}


// ========================================================================
// `dynamic initializer for 'rp_DeathFadeOpacity''
// EA  : 0x833777D8
// RVA : 0x013777D8
// PDB : w:\tech5\tungsten\game\entities\gore.cpp
// ========================================================================

void _dynamic_initializer_for__rp_DeathFadeOpacity__()
{
  rp_DeathFadeOpacity.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_DeathFadeOpacity;
}

