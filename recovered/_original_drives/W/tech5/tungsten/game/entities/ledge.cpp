
// ========================================================================
// ?GetUsableState@idUseLedge@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C68AD0
// RVA : 0x00C68AD0
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

usableState_t __fastcall idUseLedge::GetUsableState(idUseLedge *this, idPlayer *activator, const idFocusTrace *ft)
{
  idPlayer *v6; // r3
  idPlayer::idPlayerBehaviorContextualShimmyState_t mountType; // r11

  v6 = idPlayer::CastTo(c: activator);
  if ( v6 != nullptr
    && (!idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: v6)
     || (mountType = this->mountType) == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT
     || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD
     || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT
     || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM) )
  {
    return idUse::GetUsableState(this, activator, ft);
  }
  else
  {
    return USABLE_NOT_USABLE;
  }
}


// ========================================================================
// ?DebugRender@idLedge@@AAAXXZ
// EA  : 0x82C68B50
// RVA : 0x00C68B50
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

void __fastcall idLedge::DebugRender(idLedge *this)
{
  int v2; // r19
  int v3; // r25
  idLedge::idLedgeBit *v4; // r31
  idRenderWorld *v5; // r3
  float *p_x; // r26
  float *v7; // r30
  double x; // fp7
  double v9; // fp4
  double v10; // fp2
  idRenderWorld *v11; // r3
  double v12; // fp9
  float *v13; // r29
  double v14; // fp4
  idColor *v15; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  double v19; // fp24
  double v20; // fp21
  double v21; // fp20
  double v22; // fp19
  double v23; // fp23
  double v24; // fp22
  double v25; // fp18
  double v26; // fp17
  double v27; // fp25
  int v28; // r3
  double v29; // fp25
  idRenderWorld *v30; // r3
  idColor *v31; // r11
  float v32; // r8
  float v33; // r7
  float v34; // r6
  double v35; // fp19
  double v36; // fp24
  double v37; // fp21
  double v38; // fp18
  double v39; // fp23
  double v40; // fp17
  double v41; // fp20
  double v42; // fp22
  int v43; // r3
  double v44; // fp25
  idRenderWorld *v45; // r3
  idColor *v46; // r11
  float v47; // r8
  float v48; // r7
  float v49; // r6
  double v50; // fp20
  double v51; // fp18
  double v52; // fp17
  double v53; // fp21
  double v54; // fp24
  double v55; // fp23
  double v56; // fp19
  double v57; // fp22
  double v58; // fp25
  int v59; // r3
  double v60; // fp25
  idRenderWorld *v61; // r3
  idColor *v62; // r11
  float v63; // r8
  float v64; // r7
  float v65; // r6
  double v66; // fp19
  double v67; // fp24
  double v68; // fp23
  double v69; // fp22
  double v70; // fp21
  double v71; // fp20
  double v72; // fp18
  double v73; // fp17
  double v74; // fp25
  int v75; // r3
  double v76; // fp25
  idRenderWorld *v77; // r3
  float v78; // [sp+50h] [-250h] BYREF
  float v79; // [sp+54h] [-24Ch]
  float v80; // [sp+58h] [-248h]
  float v81[4]; // [sp+60h] [-240h] BYREF
  float v82[4]; // [sp+70h] [-230h] BYREF
  float v83[4]; // [sp+80h] [-220h] BYREF
  float v84[4]; // [sp+90h] [-210h] BYREF
  float v85[4]; // [sp+A0h] [-200h] BYREF
  float v86[4]; // [sp+B0h] [-1F0h] BYREF
  float v87[4]; // [sp+C0h] [-1E0h] BYREF
  float v88[4]; // [sp+D0h] [-1D0h] BYREF
  float v89[4]; // [sp+E0h] [-1C0h] BYREF
  float v90[4]; // [sp+F0h] [-1B0h] BYREF
  float v91[4]; // [sp+100h] [-1A0h] BYREF
  float v92[4]; // [sp+110h] [-190h] BYREF
  float v93[4]; // [sp+120h] [-180h] BYREF
  float v94[4]; // [sp+130h] [-170h] BYREF
  float v95[4]; // [sp+140h] [-160h] BYREF
  float v96[4]; // [sp+150h] [-150h] BYREF
  float v97[4]; // [sp+160h] [-140h] BYREF
  float v98[4]; // [sp+170h] [-130h] BYREF
  float v99[4]; // [sp+180h] [-120h] BYREF
  float v100[4]; // [sp+190h] [-110h] BYREF
  float v101[36]; // [sp+1A0h] [-100h] BYREF

  v2 = 0;
  if ( this->ledgeBits.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->ledgeBits.list[v3];
      v5 = gameLocal->GetRenderWorld(this: gameLocal);
      p_x = &v4->secondPoint.x;
      v5->DebugLine(
        this: v5,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &v4->firstPoint,
        a4: &v4->secondPoint,
        a5: 100000,
        a6: false);
      v7 = &v4->direction.x;
      x = v4->firstPoint.x;
      v9 = (float)((float)(v4->length * (float)0.5) * v4->direction.x);
      v10 = (float)((float)(v4->direction.z * (float)(v4->length * (float)0.5)) + v4->firstPoint.z);
      v79 = (float)(v4->direction.y * (float)(v4->length * (float)0.5)) + v4->firstPoint.y;
      v80 = v10;
      v78 = (float)x + (float)v9;
      v11 = gameLocal->GetRenderWorld(this: gameLocal);
      v12 = (float)(v4->normal.z * (float)15.0);
      v13 = &v4->normal.x;
      v14 = (float)((float)(v4->normal.y * (float)15.0) + v79);
      v96[0] = (float)(v4->normal.x * (float)15.0) + v78;
      v96[1] = v14;
      v96[2] = (float)v12 + v80;
      v11->DebugLine(
        this: v11,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idVec3 *)&v78,
        a4: (const idVec3 *)v96,
        a5: 100000,
        a6: false);
      if ( (v4->flags & 5) != 0 )
      {
        v15 = &idColor::colorYellow;
        if ( (v4->flags & 4) == 0 )
          v15 = &idColor::colorBlue;
        g = v15->g;
        b = v15->b;
        a = v15->a;
        v98[0] = v15->r;
        v98[1] = g;
        v98[2] = b;
        v98[3] = a;
        v19 = (float)((float)(v4->firstPoint.x + (float)(*v13 * (float)2.0)) + (float)(*v7 * (float)6.0));
        v20 = (float)((float)(v4->firstPoint.x + (float)(*v13 * (float)6.0)) + (float)(*v7 * (float)2.0));
        v21 = (float)((float)((float)(v4->normal.y * (float)6.0) + v4->firstPoint.y)
                    + (float)(v4->direction.y * (float)2.0));
        v22 = (float)((float)((float)(v4->normal.z * (float)6.0) + v4->firstPoint.z)
                    + (float)(v4->direction.z * (float)2.0));
        v23 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->firstPoint.y)
                    + (float)(v4->direction.y * (float)6.0));
        v24 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->firstPoint.z)
                    + (float)(v4->direction.z * (float)6.0));
        v25 = (float)((float)(v4->firstPoint.x + (float)(*v13 * (float)2.0)) + (float)(*v7 * (float)2.0));
        v26 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->firstPoint.y)
                    + (float)(v4->direction.y * (float)2.0));
        v27 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->firstPoint.z)
                    + (float)(v4->direction.z * (float)2.0));
        v28 = ((int (*)(void))gameLocal->GetRenderWorld)();
        v84[0] = v25;
        v29 = (float)((float)v27 + (float)1.0);
        v84[1] = v26;
        v92[0] = v19;
        v92[1] = v23;
        v92[2] = (float)v24 + (float)1.0;
        v84[2] = v29;
        (*(void (__fastcall **)(int, float *, float *, float *, int, _DWORD))(*(_DWORD *)v28 + 176))(
          a1: v28,
          a2: v98,
          a3: v92,
          a4: v84,
          a5: 100000,
          a6: 0);
        v30 = gameLocal->GetRenderWorld(this: gameLocal);
        v95[0] = v20;
        v95[1] = v21;
        v95[2] = (float)v22 + (float)1.0;
        v86[0] = v25;
        v86[1] = v26;
        v86[2] = v29;
        ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))v30->DebugArrow)(
          a1: v30,
          a2: v98,
          a3: v86,
          a4: v95,
          a5: 1.0);
      }
      if ( (v4->flags & 0xA) != 0 )
      {
        v31 = &idColor::colorYellow;
        if ( (v4->flags & 8) == 0 )
          v31 = &idColor::colorBlue;
        v32 = v31->g;
        v33 = v31->b;
        v34 = v31->a;
        v100[0] = v31->r;
        v100[1] = v32;
        v100[2] = v33;
        v100[3] = v34;
        v35 = (float)((float)(v4->firstPoint.z - (float)(v4->normal.z * (float)4.0))
                    - (float)(v4->direction.z * (float)2.0));
        v36 = (float)((float)(v4->firstPoint.x + (float)(*v13 * (float)2.0)) + (float)(*v7 * (float)4.0));
        v37 = (float)((float)(v4->firstPoint.x - (float)(*v13 * (float)4.0)) - (float)(*v7 * (float)2.0));
        v38 = (float)((float)(v4->firstPoint.x + (float)(*v13 * (float)2.0)) - (float)(*v7 * (float)2.0));
        v39 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->firstPoint.y)
                    + (float)(v4->direction.y * (float)4.0));
        v40 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->firstPoint.y)
                    - (float)(v4->direction.y * (float)2.0));
        v41 = (float)((float)(v4->firstPoint.y - (float)(v4->normal.y * (float)4.0))
                    - (float)(v4->direction.y * (float)2.0));
        v42 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->firstPoint.z)
                    + (float)(v4->direction.z * (float)4.0));
        v44 = (float)((float)((float)((float)(v4->normal.z * (float)2.0) + v4->firstPoint.z)
                            - (float)(v4->direction.z * (float)2.0))
                    + (float)1.0);
        v43 = ((int (*)(void))gameLocal->GetRenderWorld)();
        v94[2] = v44;
        v94[0] = v38;
        v94[1] = v40;
        v88[0] = v36;
        v88[1] = v39;
        v88[2] = (float)v42 + (float)1.0;
        (*(void (__fastcall **)(int, float *, float *, float *, int, _DWORD))(*(_DWORD *)v43 + 176))(
          a1: v43,
          a2: v100,
          a3: v88,
          a4: v94,
          a5: 100000,
          a6: 0);
        v45 = gameLocal->GetRenderWorld(this: gameLocal);
        v97[0] = v37;
        v90[0] = v38;
        v90[1] = v40;
        v97[2] = (float)v35 + (float)1.0;
        v90[2] = v44;
        v97[1] = v41;
        ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))v45->DebugArrow)(
          a1: v45,
          a2: v100,
          a3: v90,
          a4: v97,
          a5: 1.0);
      }
      if ( (v4->flags & 0x50) != 0 )
      {
        v46 = &idColor::colorYellow;
        if ( (v4->flags & 0x40) == 0 )
          v46 = &idColor::colorBlue;
        v47 = v46->g;
        v48 = v46->b;
        v49 = v46->a;
        v99[0] = v46->r;
        v99[1] = v47;
        v99[2] = v48;
        v99[3] = v49;
        v50 = (float)((float)(*p_x + (float)(*v13 * (float)6.0)) - (float)(*v7 * (float)2.0));
        v51 = (float)((float)(*p_x + (float)(*v13 * (float)2.0)) - (float)(*v7 * (float)2.0));
        v52 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->secondPoint.y)
                    - (float)(v4->direction.y * (float)2.0));
        v53 = (float)((float)((float)(v4->normal.z * (float)6.0) + v4->secondPoint.z)
                    - (float)(v4->direction.z * (float)2.0));
        v54 = (float)((float)(*p_x + (float)(*v13 * (float)2.0)) - (float)(*v7 * (float)6.0));
        v55 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->secondPoint.y)
                    - (float)(v4->direction.y * (float)6.0));
        v56 = (float)((float)((float)(v4->normal.y * (float)6.0) + v4->secondPoint.y)
                    - (float)(v4->direction.y * (float)2.0));
        v57 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->secondPoint.z)
                    - (float)(v4->direction.z * (float)6.0));
        v58 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->secondPoint.z)
                    - (float)(v4->direction.z * (float)2.0));
        v59 = ((int (*)(void))gameLocal->GetRenderWorld)();
        v81[0] = v51;
        v81[1] = v52;
        v60 = (float)((float)v58 - (float)1.0);
        v82[0] = v54;
        v82[1] = v55;
        v82[2] = (float)v57 - (float)1.0;
        v81[2] = v60;
        (*(void (__fastcall **)(int, float *, float *, float *, int, _DWORD))(*(_DWORD *)v59 + 176))(
          a1: v59,
          a2: v99,
          a3: v82,
          a4: v81,
          a5: 100000,
          a6: 0);
        v61 = gameLocal->GetRenderWorld(this: gameLocal);
        v83[0] = v50;
        v83[2] = (float)v53 - (float)1.0;
        v85[0] = v51;
        v85[1] = v52;
        v85[2] = v60;
        v83[1] = v56;
        ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))v61->DebugArrow)(
          a1: v61,
          a2: v99,
          a3: v85,
          a4: v83,
          a5: 1.0);
      }
      if ( (v4->flags & 0xA0) != 0 )
      {
        v62 = &idColor::colorYellow;
        if ( (v4->flags & 0x80) == 0 )
          v62 = &idColor::colorBlue;
        v63 = v62->g;
        v64 = v62->b;
        v65 = v62->a;
        v101[0] = v62->r;
        v101[1] = v63;
        v101[2] = v64;
        v101[3] = v65;
        v66 = (float)((float)(v4->secondPoint.z - (float)(v4->normal.z * (float)6.0))
                    + (float)(v4->direction.z * (float)2.0));
        v67 = (float)((float)(*p_x + (float)(*v13 * (float)2.0)) - (float)(*v7 * (float)6.0));
        v68 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->secondPoint.y)
                    - (float)(v4->direction.y * (float)6.0));
        v69 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->secondPoint.z)
                    - (float)(v4->direction.z * (float)6.0));
        v70 = (float)((float)(*p_x - (float)(*v13 * (float)6.0)) + (float)(*v7 * (float)2.0));
        v71 = (float)((float)(v4->secondPoint.y - (float)(v4->normal.y * (float)6.0))
                    + (float)(v4->direction.y * (float)2.0));
        v72 = (float)((float)(*p_x + (float)(*v13 * (float)2.0)) + (float)(*v7 * (float)2.0));
        v73 = (float)((float)((float)(v4->normal.y * (float)2.0) + v4->secondPoint.y)
                    + (float)(v4->direction.y * (float)2.0));
        v74 = (float)((float)((float)(v4->normal.z * (float)2.0) + v4->secondPoint.z)
                    + (float)(v4->direction.z * (float)2.0));
        v75 = ((int (*)(void))gameLocal->GetRenderWorld)();
        v87[0] = v72;
        v76 = (float)((float)v74 - (float)1.0);
        v87[1] = v73;
        v89[0] = v67;
        v89[1] = v68;
        v89[2] = (float)v69 - (float)1.0;
        v87[2] = v76;
        (*(void (__fastcall **)(int, float *, float *, float *, int, _DWORD))(*(_DWORD *)v75 + 176))(
          a1: v75,
          a2: v101,
          a3: v89,
          a4: v87,
          a5: 100000,
          a6: 0);
        v77 = gameLocal->GetRenderWorld(this: gameLocal);
        v91[0] = v70;
        v91[1] = v71;
        v91[2] = (float)v66 - (float)1.0;
        v93[0] = v72;
        v93[1] = v73;
        v93[2] = v76;
        ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))v77->DebugArrow)(
          a1: v77,
          a2: v101,
          a3: v93,
          a4: v91,
          a5: 1.0);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->ledgeBits.num );
  }
}


// ========================================================================
// ?GetClosestPoint@idLedge@@QBAHABVidVec3@@AAV2@@Z
// EA  : 0x82C69360
// RVA : 0x00C69360
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

int __fastcall idLedge::GetClosestPoint(idLedge *this, const idVec3 *playerPos, idVec3 *point)
{
  int v3; // r6
  int v4; // r8
  int num; // r30
  double v6; // fp0
  double y; // fp5
  double z; // fp4
  double x; // fp6
  idLedge::idLedgeBit *list; // r31
  int v11; // r9
  int v12; // r7
  float *p_x; // r11
  double v14; // fp10
  double v15; // fp3
  double v16; // fp2
  double v17; // fp10
  double v18; // fp10
  double v19; // fp3
  double v20; // fp2
  double v21; // fp10
  float *v22; // r11
  double v23; // fp3
  double v24; // fp2
  double v25; // fp10
  double v26; // fp3
  double v27; // fp2
  double v28; // fp10
  int v29; // r10
  float *v30; // r11
  double v31; // fp3
  double v32; // fp2
  double v33; // fp10
  double v34; // fp3
  double v35; // fp2
  double v36; // fp10
  float *v37; // r11
  double v38; // fp10
  double v39; // fp3
  double v40; // fp2
  double v41; // fp10
  double v42; // fp10
  double v43; // fp3
  double v44; // fp2
  double v45; // fp10
  idLedge::idLedgeBit *v46; // r9
  int v47; // r10
  int v48; // ctr
  float *v49; // r11
  double v50; // fp10
  double v51; // fp3
  double v52; // fp2
  double v53; // fp10
  double v54; // fp10
  double v55; // fp3
  double v56; // fp2
  double v57; // fp10

  v3 = -1;
  v4 = 0;
  num = this->ledgeBits.num;
  v6 = 1.0e30;
  y = playerPos->y;
  z = playerPos->z;
  x = playerPos->x;
  if ( num >= 4 )
  {
    list = this->ledgeBits.list;
    v11 = 2;
    v12 = 0;
    do
    {
      p_x = &list[v12].firstPoint.x;
      v14 = (float)(list[v12].firstPoint.x - playerPos->x);
      v15 = (float)(list[v12].firstPoint.y - playerPos->y);
      v16 = (float)(list[v12].firstPoint.z - playerPos->z);
      v17 = (float)((float)((float)v16 * (float)v16)
                  + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
      if ( v17 < v6 )
      {
        v6 = v17;
        v3 = v4;
        x = list[v12].firstPoint.x;
        y = list[v12].firstPoint.y;
        z = list[v12].firstPoint.z;
      }
      v18 = (float)(p_x[4] - playerPos->y);
      v19 = (float)(p_x[5] - playerPos->z);
      v20 = (float)(p_x[3] - playerPos->x);
      v21 = (float)((float)((float)v20 * (float)v20)
                  + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
      if ( v21 < v6 )
      {
        v6 = v21;
        v3 = v4;
        x = p_x[3];
        y = p_x[4];
        z = p_x[5];
      }
      v22 = p_x + 14;
      v23 = (float)(v22[1] - playerPos->y);
      v24 = (float)(v22[2] - playerPos->z);
      if ( (float)((float)((float)v24 * (float)v24)
                 + (float)((float)((float)v23 * (float)v23)
                         + (float)((float)(*v22 - playerPos->x) * (float)(*v22 - playerPos->x)))) < v6 )
      {
        v6 = (float)((float)((float)v24 * (float)v24)
                   + (float)((float)((float)v23 * (float)v23)
                           + (float)((float)(*v22 - playerPos->x) * (float)(*v22 - playerPos->x))));
        v3 = v11 - 1;
        x = *v22;
        y = v22[1];
        z = v22[2];
      }
      v25 = (float)(v22[4] - playerPos->y);
      v26 = (float)(v22[5] - playerPos->z);
      v27 = (float)(v22[3] - playerPos->x);
      v28 = (float)((float)((float)v27 * (float)v27)
                  + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
      if ( v28 < v6 )
      {
        v6 = v28;
        v3 = v11 - 1;
        x = v22[3];
        y = v22[4];
        z = v22[5];
      }
      v29 = v12 * 56 + 168;
      v30 = &list[v12 + 2].firstPoint.x;
      v31 = (float)(v30[1] - playerPos->y);
      v32 = (float)(v30[2] - playerPos->z);
      if ( (float)((float)((float)v32 * (float)v32)
                 + (float)((float)((float)v31 * (float)v31)
                         + (float)((float)(*v30 - playerPos->x) * (float)(*v30 - playerPos->x)))) < v6 )
      {
        v6 = (float)((float)((float)v32 * (float)v32)
                   + (float)((float)((float)v31 * (float)v31)
                           + (float)((float)(*v30 - playerPos->x) * (float)(*v30 - playerPos->x))));
        v3 = v11;
        x = *v30;
        y = v30[1];
        z = v30[2];
      }
      v33 = (float)(v30[4] - playerPos->y);
      v34 = (float)(v30[5] - playerPos->z);
      v35 = (float)(v30[3] - playerPos->x);
      v36 = (float)((float)((float)v35 * (float)v35)
                  + (float)((float)((float)v34 * (float)v34) + (float)((float)v33 * (float)v33)));
      if ( v36 < v6 )
      {
        v6 = v36;
        v3 = v11;
        x = v30[3];
        y = v30[4];
        z = v30[5];
      }
      v37 = (float *)((char *)&list->firstPoint.x + v29);
      v38 = (float)(*(float *)((char *)&list->firstPoint.x + v29) - playerPos->x);
      v39 = (float)(*(float *)((char *)&list->firstPoint.y + v29) - playerPos->y);
      v40 = (float)(*(float *)((char *)&list->firstPoint.z + v29) - playerPos->z);
      v41 = (float)((float)((float)v40 * (float)v40)
                  + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)));
      if ( v41 < v6 )
      {
        v6 = v41;
        v3 = v11 + 1;
        x = *(float *)((char *)&list->firstPoint.x + v29);
        y = *(float *)((char *)&list->firstPoint.y + v29);
        z = *(float *)((char *)&list->firstPoint.z + v29);
      }
      v42 = (float)(v37[4] - playerPos->y);
      v43 = (float)(v37[5] - playerPos->z);
      v44 = (float)(v37[3] - playerPos->x);
      v45 = (float)((float)((float)v44 * (float)v44)
                  + (float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)));
      if ( v45 < v6 )
      {
        v6 = v45;
        v3 = v11 + 1;
        x = v37[3];
        y = v37[4];
        z = v37[5];
      }
      v4 += 4;
      v12 += 4;
      v11 += 4;
    }
    while ( v4 < num - 3 );
  }
  if ( v4 < num )
  {
    v46 = this->ledgeBits.list;
    v47 = v4;
    v48 = num - v4;
    do
    {
      v49 = &v46[v47].firstPoint.x;
      v50 = (float)(v46[v47].firstPoint.x - playerPos->x);
      v51 = (float)(v46[v47].firstPoint.y - playerPos->y);
      v52 = (float)(v46[v47].firstPoint.z - playerPos->z);
      v53 = (float)((float)((float)v52 * (float)v52)
                  + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)));
      if ( v53 < v6 )
      {
        v6 = v53;
        v3 = v4;
        x = v46[v47].firstPoint.x;
        y = v46[v47].firstPoint.y;
        z = v46[v47].firstPoint.z;
      }
      v54 = (float)(v49[4] - playerPos->y);
      v55 = (float)(v49[5] - playerPos->z);
      v56 = (float)(v49[3] - playerPos->x);
      v57 = (float)((float)((float)v56 * (float)v56)
                  + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54)));
      if ( v57 < v6 )
      {
        v6 = v57;
        v3 = v4;
        x = v49[3];
        y = v49[4];
        z = v49[5];
      }
      ++v4;
      ++v47;
      --v48;
    }
    while ( v48 != 0 );
  }
  point->x = x;
  point->y = y;
  point->z = z;
  return v3;
}


// ========================================================================
// ?GetPointOnLedge@idLedgeBit@idLedge@@QBA?AW4ledgeEdgeType_t@2@PBVidPlayer@@AAVidVec3@@_N@Z
// EA  : 0x82C696B8
// RVA : 0x00C696B8
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

idLedge::ledgeEdgeType_t __fastcall idLedge::idLedgeBit::GetPointOnLedge(
        idLedge::idLedgeBit *this,
        const idPlayer *player,
        idVec3 *pointOut,
        bool bFlipped)
{
  idPhysics *Physics; // r3
  float *v8; // r3
  int v9; // r11
  int v10; // r10
  double v11; // fp12
  double v12; // fp13
  double x; // fp8
  double v14; // fp11
  double y; // fp9
  double z; // fp10
  idLedge::ledgeEdgeType_t result; // r3
  float v18; // [sp+70h] [-40h]
  float v19; // [sp+74h] [-3Ch]
  float v20; // [sp+78h] [-38h]

  Physics = idEntity::GetPhysics(this: &player->idActor);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = 15;
  v10 = 240;
  v18 = *v8;
  v19 = v8[1];
  v20 = v8[2];
  if ( bFlipped )
  {
    v9 = 240;
    v11 = -this->direction.y;
    v12 = -this->direction.z;
    x = this->secondPoint.x;
    v14 = -this->direction.x;
    y = this->secondPoint.y;
    v10 = 15;
    z = this->secondPoint.z;
  }
  else
  {
    v12 = this->direction.z;
    v11 = this->direction.y;
    v14 = this->direction.x;
    z = this->firstPoint.z;
    y = this->firstPoint.y;
    x = this->firstPoint.x;
  }
  result = EDGETYPE_NONE;
  pointOut->z = (float)((float)v12
                      * (float)((float)((float)(v18 - (float)x) * (float)v14)
                              + (float)((float)((float)(v20 - (float)z) * (float)v12)
                                      + (float)((float)(v19 - (float)y) * (float)v11))))
              + (float)z;
  pointOut->x = (float)((float)v14
                      * (float)((float)((float)(v18 - (float)x) * (float)v14)
                              + (float)((float)((float)(v20 - (float)z) * (float)v12)
                                      + (float)((float)(v19 - (float)y) * (float)v11))))
              + (float)x;
  pointOut->y = (float)((float)v11
                      * (float)((float)((float)(v18 - (float)x) * (float)v14)
                              + (float)((float)((float)(v20 - (float)z) * (float)v12)
                                      + (float)((float)(v19 - (float)y) * (float)v11))))
              + (float)y;
  if ( (float)((float)((float)((float)(v18 - (float)x) * (float)v14)
                     + (float)((float)((float)(v20 - (float)z) * (float)v12)
                             + (float)((float)(v19 - (float)y) * (float)v11)))
             - ledge_playerWidth.valueFloat) < 0.0 )
    return (this->flags & v9) == 0 ? 1 : 3;
  if ( (float)(ledge_playerWidth.valueFloat
             + (float)((float)((float)(v18 - (float)x) * (float)v14)
                     + (float)((float)((float)(v20 - (float)z) * (float)v12)
                             + (float)((float)(v19 - (float)y) * (float)v11)))) > (double)this->length )
    return (this->flags & v10) == 0 ? 2 : 4;
  return result;
}


// ========================================================================
// ?Event_PostSpawn@idUseLedge@@QAA?AVeventVoid@@XZ
// EA  : 0x82C69850
// RVA : 0x00C69850
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

idUseLedge *__fastcall idUseLedge::Event_PostSpawn(idUseLedge *this, eventVoid *result)
{
  idPlayer *Player; // r3
  idPlayer *v5; // r31
  idAnimatedEntity *thirdPersonLegs; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idAnimatedEntity *thirdPersonHands; // r3
  idTreeAnimator *v9; // r29
  idUseLedge *v10; // r3
  __int16 v11; // [sp+50h] [-50h] BYREF
  __int16 v12; // [sp+52h] [-4Eh] BYREF
  char v13; // [sp+54h] [-4Ch] BYREF
  char v14; // [sp+56h] [-4Ah] BYREF
  char v15; // [sp+58h] [-48h] BYREF
  char v16; // [sp+5Ah] [-46h] BYREF
  char v17; // [sp+5Ch] [-44h] BYREF
  char v18; // [sp+5Eh] [-42h] BYREF
  char v19; // [sp+60h] [-40h] BYREF
  char v20; // [sp+62h] [-3Eh] BYREF
  char v21; // [sp+64h] [-3Ch] BYREF
  char v22; // [sp+66h] [-3Ah] BYREF
  char v23; // [sp+68h] [-38h] BYREF
  char v24; // [sp+6Ah] [-36h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  v5 = Player;
  if ( Player == nullptr )
    return this;
  thirdPersonLegs = Player->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs);
  else
    TreeAnimatorFromPresentable = nullptr;
  thirdPersonHands = v5->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
    v9 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
  else
    v9 = nullptr;
  if ( *(_DWORD *)&result[868] != 0 && TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::StrongLoadAlias(
      this: (idDeclMD6 *)&v11,
      result: TreeAnimatorFromPresentable->decl,
      aliasName: *(const char **)&result[872]);
    *(_WORD *)&result[932] = v11;
  }
  if ( *(_DWORD *)&result[900] != 0 && v9 != nullptr )
  {
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v12, result: v9->decl, aliasName: *(const char **)&result[904]);
    *(_WORD *)&result[934] = v12;
  }
  if ( TreeAnimatorFromPresentable == nullptr )
    return this;
  switch ( *(_DWORD *)&result[856] )
  {
    case 1:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v13,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_0_left");
      v10 = this;
      break;
    case 2:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v14,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_0_right");
      v10 = this;
      break;
    case 3:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v15,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_0_back");
      v10 = this;
      break;
    case 4:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v16,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_90_left");
      v10 = this;
      break;
    case 5:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v17,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_90_right");
      v10 = this;
      break;
    case 6:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v18,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_180_left");
      v10 = this;
      break;
    case 7:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v19,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/mount_180_right");
      v10 = this;
      break;
    case 8:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v20,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/insidesshq_climbout");
      if ( v9 == nullptr )
        return this;
      idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v21, result: v9->decl, aliasName: "shimmy/insidesshq_climbout");
      v10 = this;
      break;
    case 0xD:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v22,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/dismount_right");
      v10 = this;
      break;
    case 0xE:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v23,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/dismount_forward");
      v10 = this;
      break;
    case 0xF:
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v24,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "shimmy/dismount_left");
      return this;
    default:
      return this;
  }
  return v10;
}


// ========================================================================
// ??0idUseLedge@@QAA@XZ
// EA  : 0x82C69AF8
// RVA : 0x00C69AF8
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

idUseLedge *__fastcall idUseLedge::idUseLedge(idUseLedge *this)
{
  idUse::idUse(this);
  this->mountType = CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0;
  this->__vftable = (idUseLedge_vtbl *)&idUseLedge::`vftable';
  this->targetPositionEntity.spawnId.value = 0x1FFF;
  this->endPositionEntity.spawnId.value = 0x1FFF;
  this->customLegsAnimation.data = this->customLegsAnimation.baseBuffer;
  this->customLegsAnimation.len = 0;
  this->customLegsAnimation.allocedAndFlag = 20;
  this->customLegsAnimation.baseBuffer[0] = 0;
  this->customHandsAnimation.allocedAndFlag = 20;
  this->customHandsAnimation.data = this->customHandsAnimation.baseBuffer;
  this->customHandsAnimation.len = 0;
  this->customHandsAnimation.baseBuffer[0] = 0;
  this->customLegsAnimationHandle.value = -1;
  this->customHandsAnimationHandle.value = -1;
  return this;
}


// ========================================================================
// ??0idLedge@@QAA@XZ
// EA  : 0x82C69CB0
// RVA : 0x00C69CB0
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

idLedge *__fastcall idLedge::idLedge(idLedge *this)
{
  idSplinePath::idSplinePath(this);
  this->__vftable = (idLedge_vtbl *)&idLedge::`vftable';
  this->ledgeBits.list = nullptr;
  this->ledgeBits.granularity = 0;
  this->ledgeBits.memTag = 5;
  this->ledgeBits.listStatic = 0;
  this->ledgeBits.size = 0;
  this->ledgeBits.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->ledgeBits);
  this->ledgeNormalHint = LEDGETYPE_CLOCKWISE;
  this->type = Linear;
  this->maxDeltaYaw = -1.0;
  this->maxDeltaPitch = -1.0;
  return this;
}


// ========================================================================
// __unwind$490160_0
// EA  : 0x82C69D24
// RVA : 0x00C69D24
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

void _unwind_490160_0()
{
  int v0; // r12

  idSplinePath::~idSplinePath(this: *(idSplinePath **)(v0 - 128 + 148));
}


// ========================================================================
// ?Use@idUseLedge@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C69D50
// RVA : 0x00C69D50
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

int __fastcall idUseLedge::Use(idUseLedge *this, idPlayer *activator, usableState_t usable)
{
  idPlayer *v6; // r3
  idPlayer *v7; // r28
  idLedge *Target; // r3
  idLedge *v9; // r31
  idEntity *v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  int ClosestPoint; // r30
  idPhysics *v14; // r3
  const idVec3 *v15; // r3
  int v16; // r3
  idVec3 v18; // [sp+50h] [-50h] BYREF
  idVec3 v19[5]; // [sp+60h] [-40h] BYREF

  v6 = idPlayer::CastTo(c: activator);
  v7 = v6;
  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return 0;
  if ( v6 == nullptr )
    return 0;
  if ( this->targets.num < 1 )
    return 0;
  Target = (idLedge *)idEntity::GetTarget(this, i: 0);
  v9 = idLedge::CastTo(c: Target);
  if ( v9 == nullptr )
    return 0;
  idEntity::Use(this, activator, usable);
  if ( idEntityPtr<idEntity const>::operator->(this: &this->targetPositionEntity) != nullptr )
  {
    v10 = idEntityPtr<idEntity const>::operator->(this: &this->targetPositionEntity);
    Physics = idEntity::GetPhysics(this: v10);
    v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v18.x = *v12;
    v18.y = v12[1];
    v18.z = v12[2];
    ClosestPoint = idLedge::GetClosestPoint(this: v9, playerPos: &v18, point: v19);
  }
  else
  {
    v14 = idEntity::GetPhysics(this: v7);
    v15 = v14->GetOrigin(this: v14, a2: 0);
    v16 = idLedge::GetClosestPoint(this: v9, playerPos: v15, point: &v18);
    ClosestPoint = v16;
    if ( v16 != -1 )
      idLedge::idLedgeBit::GetPointOnLedge(
        this: &v9->ledgeBits.list[v16],
        player: v7,
        pointOut: &v18,
        bFlipped: (_cntlzw(v9->ledgeNormalHint) & 0x20) != 0);
  }
  idPlayer::PlayerBehavior_ContextualShimmy_MountLedge(
    this: v7,
    ledge: v9,
    startLedgeBit: ClosestPoint,
    closestLedgePoint: &v18,
    useLedge: this);
  if ( (*((_BYTE *)&this->idUse + 844) & 0x80) != 0 )
    this->Hide_2(this);
  return 1;
}


// ========================================================================
// ?Spawn@idLedge@@QAAXXZ
// EA  : 0x82C69FA0
// RVA : 0x00C69FA0
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

void __fastcall idLedge::Spawn(idLedge *this)
{
  int num; // r11
  idList<idLedge::idLedgeBit,5> *p_ledgeBits; // r29
  int v4; // r31
  int size; // r11
  int v6; // r5
  int v7; // r6
  int v8; // r4
  idLedge::idLedgeBit *v9; // r11
  idLedge::idLedgeBit *v10; // r8
  float *p_x; // r10
  idVec3 *v12; // r9
  idVec3 *v13; // r9
  double x; // fp8
  double y; // fp7
  double z; // fp6
  double v17; // fp1
  double v18; // fp8
  double v19; // fp10
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp2
  double v26; // fp10
  double v27; // fp8
  float *v28; // r9
  double v29; // fp9
  double v30; // fp7
  double v31; // fp4
  double v32; // fp9
  double v33; // fp7
  double v34; // fp4
  double v35; // fp10
  double v36; // fp9
  int flags; // r10
  bool v38; // mr_fpscr49
  double v39; // fp3
  int v40; // r7
  float v41[4]; // [sp+50h] [-40h] BYREF
  float v42[12]; // [sp+60h] [-30h] BYREF

  num = this->controlPoints.num;
  p_ledgeBits = &this->ledgeBits;
  v4 = num - 1;
  if ( num - 1 <= this->ledgeBits.size
    || (unsigned __int8)idList<idLedge::idLedgeBit,5>::Resize(this: &this->ledgeBits, newsize: num - 1) != 0 )
  {
    size = p_ledgeBits->size;
    if ( v4 < size )
      size = v4;
    p_ledgeBits->num = size;
  }
  v6 = 0;
  if ( this->ledgeBits.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v9 = &p_ledgeBits->list[v8];
      v10 = v9 - 1;
      if ( v6 <= 0 )
        v10 = nullptr;
      p_x = &v9->direction.x;
      v12 = &this->controlPoints.list[v7];
      v9->firstPoint.x = v12->x;
      v9->firstPoint.y = v12->y;
      v9->firstPoint.z = v12->z;
      v13 = &this->controlPoints.list[v7];
      x = v13[1].x;
      v9->secondPoint.x = v13[1].x;
      y = v13[1].y;
      v9->secondPoint.y = v13[1].y;
      z = v13[1].z;
      v9->secondPoint.z = v13[1].z;
      v17 = v9->firstPoint.z;
      v18 = (float)((float)x - v9->firstPoint.x);
      v19 = (float)((float)y - v9->firstPoint.y);
      v9->direction.x = v18;
      v9->direction.z = (float)z - (float)v17;
      v9->direction.y = v19;
      v20 = v18;
      v21 = (float)((float)z - (float)v17);
      v22 = v19;
      v23 = (float)((float)((float)v21 * (float)v21)
                  + (float)((float)((float)v18 * (float)v18) + (float)((float)v19 * (float)v19)));
      _FP1 = (float)((float)((float)((float)v21 * (float)v21)
                           + (float)((float)((float)v18 * (float)v18) + (float)((float)v19 * (float)v19)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f9, f1, f2, f13 }
      v26 = (float)((float)((float)((float)v21 * (float)v21)
                          + (float)((float)((float)v18 * (float)v18) + (float)((float)v19 * (float)v19)))
                  * (float)0.5);
      v27 = __frsqrte(_FP9);
      v9->direction.x = (float)v20
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27) * (float)v26)
                                                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27))
                                                              * (float)v26)
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27)
                                                                                              * (float)v26)
                                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                              * (float)v27))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27)))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27)
                                                                      * (float)v26)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27)));
      v9->direction.z = (float)v21
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27) * (float)v26)
                                                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27))
                                                              * (float)v26)
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27)
                                                                                              * (float)v26)
                                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                              * (float)v27))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27)))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27)
                                                                      * (float)v26)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27)));
      v9->direction.y = (float)v22
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27) * (float)v26)
                                                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27))
                                                              * (float)v26)
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27)
                                                                                              * (float)v26)
                                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                              * (float)v27))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27)))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27)
                                                                      * (float)v26)
                                                              * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                              * (float)v27)
                                                                                      - (float)1.5)
                                                                      * (float)v27))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27)));
      v9->length = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5) * (float)v27)
                                                                                                 * (float)v26)
                                                                                         * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                                 * (float)v27))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                                 * (float)v27)
                                                                                         - (float)1.5)
                                                                         * (float)v27))
                                                         * (float)v26)
                                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                                 * (float)v27)
                                                                                         * (float)v26)
                                                                                 * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27) - (float)1.5)
                                                                                         * (float)v27))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v27
                                                                                                 * (float)v26)
                                                                                         * (float)v27)
                                                                                 - (float)1.5)
                                                                 * (float)v27)))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)v26)
                                                                                                 * (float)v27)
                                                                                         - (float)1.5)
                                                                         * (float)v27)
                                                                 * (float)v26)
                                                         * (float)((float)-(float)((float)((float)((float)v27
                                                                                                 * (float)v26)
                                                                                         * (float)v27)
                                                                                 - (float)1.5)
                                                                 * (float)v27))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v27 * (float)v26) * (float)v27)
                                                         - (float)1.5)
                                         * (float)v27)))
                 * (float)v23;
      if ( this->ledgeNormalHint != LEDGETYPE_CLOCKWISE )
      {
        v28 = v42;
        v32 = (float)(*p_x * (float)0.0);
        v33 = v9->direction.y;
        v34 = (float)(*p_x - (float)(v9->direction.z * (float)0.0));
        v42[0] = (float)(v9->direction.z * (float)0.0) - v9->direction.y;
        v42[1] = v34;
        v42[2] = (float)((float)v33 * (float)0.0) - (float)v32;
      }
      else
      {
        v28 = v41;
        v29 = (float)(v9->direction.y * (float)0.0);
        v30 = *p_x;
        v31 = (float)((float)(v9->direction.z * (float)0.0) - *p_x);
        v41[0] = v9->direction.y - (float)(v9->direction.z * (float)0.0);
        v41[1] = v31;
        v41[2] = (float)((float)v30 * (float)0.0) - (float)v29;
      }
      v35 = v28[1];
      v36 = v28[2];
      v9->normal.x = *v28;
      v9->normal.y = v35;
      v9->normal.z = v36;
      v9->flags = 0;
      if ( v10 != nullptr )
      {
        v38 = (float)((float)((float)((float)((float)(*p_x * v10->direction.z) - (float)(p_x[2] * v10->direction.x))
                                    + (float)((float)(p_x[2] * v10->direction.y) - (float)(p_x[1] * v10->direction.z)))
                            * (float)0.0)
                    + (float)((float)(p_x[1] * v10->direction.x) - (float)(*p_x * v10->direction.y))) > 0.0;
        v39 = (float)((float)(v9->direction.x * v10->normal.x)
                    + (float)((float)(v10->normal.z * v9->direction.z) + (float)(v10->normal.y * v9->direction.y)));
        flags = v10->flags;
        if ( v38 )
        {
          if ( v39 <= 0.0 )
          {
            v10->flags = flags | 0x20;
            v40 = v9->flags | 8;
          }
          else
          {
            v10->flags = flags | 0x10;
            v40 = v9->flags | 4;
          }
        }
        else if ( v39 <= 0.0 )
        {
          v10->flags = flags | 0x80;
          v40 = v9->flags | 2;
        }
        else
        {
          v10->flags = flags | 0x40;
          v40 = v9->flags | 1;
        }
        v9->flags = v40;
      }
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < this->ledgeBits.num );
  }
  if ( ledge_debugRender.valueInteger != 0 )
    idLedge::DebugRender(this);
}


// ========================================================================
// `dynamic initializer for 'ledge_playerWidth''
// EA  : 0x833778A8
// RVA : 0x013778A8
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ledge_playerWidth__()
{
  idCVar::idCVar(
    this: &ledge_playerWidth,
    name: "ledge_playerWidth",
    value: "26.0",
    flags: 4,
    description: "How bit the player is on the ledge",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ledge_playerWidth__);
}


// ========================================================================
// `dynamic initializer for 'ledge_debugRender''
// EA  : 0x83377900
// RVA : 0x01377900
// PDB : w:\tech5\tungsten\game\entities\ledge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ledge_debugRender__()
{
  idCVar::idCVar(
    this: &ledge_debugRender,
    name: "ledge_debugRender",
    value: "0",
    flags: 1,
    description: "If ledge debug drawing should be on (need map restart, draws once)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ledge_debugRender__);
}

