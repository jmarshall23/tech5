
// ========================================================================
// ?GetNavSplineList@idNavSplinePathMgr@@QAAAAV?$idList@VidNavSpline@@$04@@XZ
// EA  : 0x82CBDF50
// RVA : 0x00CBDF50
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idStaticList<idNavSpline,200> *__fastcall idNavSplinePathMgr::GetNavSplineList(idNavSplinePathMgr *this)
{
  if ( com_production.valueInteger != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
    || spl_useBuildGameList.valueInteger != 0 )
  {
    return (idStaticList<idNavSpline,200> *)&this->navSplineList_BuildGame;
  }
  else
  {
    return &this->navSplineList;
  }
}


// ========================================================================
// ?GetNavSplineFromIndex@idNavSplinePathMgr@@QAAPAVidNavSpline@@H@Z
// EA  : 0x82CBE000
// RVA : 0x00CBE000
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSpline *__fastcall idNavSplinePathMgr::GetNavSplineFromIndex(idNavSplinePathMgr *this, int index)
{
  if ( index < 0 || index > idNavSplinePathMgr::GetNavSplineList(this)->num - 1 )
    return nullptr;
  else
    return &idNavSplinePathMgr::GetNavSplineList(this)->list[index];
}


// ========================================================================
// ?GetFacingDir@idNavSplinePathMgr@@QAAMAAUnavSplinePath_t@@M@Z
// EA  : 0x82CBE070
// RVA : 0x00CBE070
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

float __fastcall idNavSplinePathMgr::GetFacingDir(
        idNavSplinePathMgr *this,
        navSplinePath_t *splinePath,
        double maxLength)
{
  int num; // r10
  double startDistance; // fp0
  double v6; // fp1
  double v7; // fp13
  navSplinePath_t::path_t *list; // r11
  int v9; // r5
  int v10; // r6
  navSplinePath_t::path_t *v11; // r7
  int v12; // r8
  idNavSpline *navSpline; // r10
  idNavSpline *v14; // r11
  idNavSpline *v15; // r9
  idNavSpline *v16; // r11
  idNavSpline *v17; // r10
  navSplinePath_t::path_t *v18; // r8
  int v19; // r10
  idNavSpline *v20; // r9
  idNavSpline *v21; // r11

  num = splinePath->path.num;
  startDistance = 0.0;
  v6 = 1.0;
  v7 = 0.0;
  if ( num != 0 )
  {
    list = splinePath->path.list;
    startDistance = splinePath->startDistance;
    if ( list->dir > 0.0 )
      startDistance = (float)(list->navSpline->length - splinePath->startDistance);
  }
  v9 = num - 1;
  v10 = 0;
  if ( num - 1 >= 4 )
  {
    v11 = splinePath->path.list;
    v12 = 3;
    do
    {
      navSpline = v11[v12 - 2].navSpline;
      v14 = v11[v12 - 3].navSpline;
      if ( maxLength < 1.0e30 )
      {
        v7 = (float)((float)startDistance + (float)v7);
        if ( v7 >= maxLength )
          return *((float *)&v6 + 1);
        startDistance = navSpline->length;
      }
      if ( v14 != navSpline && (v14->startNode == navSpline->startNode || v14->endNode == navSpline->endNode) )
        v6 = -v6;
      v15 = v11[v12 - 1].navSpline;
      if ( maxLength < 1.0e30 )
      {
        v7 = (float)((float)startDistance + (float)v7);
        if ( v7 >= maxLength )
          return *((float *)&v6 + 1);
        startDistance = v15->length;
      }
      if ( navSpline != v15 && (navSpline->startNode == v15->startNode || navSpline->endNode == v15->endNode) )
        v6 = -v6;
      v16 = v11[v12].navSpline;
      if ( maxLength < 1.0e30 )
      {
        v7 = (float)((float)startDistance + (float)v7);
        if ( v7 >= maxLength )
          return *((float *)&v6 + 1);
        startDistance = v16->length;
      }
      if ( v15 != v16 && (v15->startNode == v16->startNode || v15->endNode == v16->endNode) )
        v6 = -v6;
      v17 = v11[v12 + 1].navSpline;
      if ( maxLength < 1.0e30 )
      {
        v7 = (float)((float)startDistance + (float)v7);
        if ( v7 >= maxLength )
          return *((float *)&v6 + 1);
        startDistance = v17->length;
      }
      if ( v16 != v17 && (v16->startNode == v17->startNode || v16->endNode == v17->endNode) )
        v6 = -v6;
      v10 += 4;
      v12 += 4;
    }
    while ( v10 < v9 - 3 );
  }
  if ( v10 < v9 )
  {
    v18 = splinePath->path.list;
    v19 = v10;
    do
    {
      v20 = v18[v19].navSpline;
      v21 = v18[v19 + 1].navSpline;
      if ( maxLength < 1.0e30 )
      {
        v7 = (float)((float)startDistance + (float)v7);
        if ( v7 >= maxLength )
          break;
        startDistance = v21->length;
      }
      if ( v20 != v21 && (v20->startNode == v21->startNode || v20->endNode == v21->endNode) )
        v6 = -v6;
      ++v10;
      ++v19;
    }
    while ( v10 < v9 );
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?MovingToStartOfSpline@idNavSplinePathMgr@@QAA_NVidNavSplinePosition@@PAVidNavSpline@@@Z
// EA  : 0x82CBE290
// RVA : 0x00CBE290
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

int __fastcall idNavSplinePathMgr::MovingToStartOfSpline(
        idNavSplinePathMgr *this,
        idNavSplinePosition *splinePos,
        idNavSpline *newNavSpline,
        int a4)
{
  if ( *(float *)&this < 0.0 )
    return (_cntlzw(*(_DWORD *)(a4 + 68) - (unsigned int)splinePos[5].navSpline) & 0x20) != 0;
  if ( *(float *)&this <= (double)splinePos[1].distance )
    return 1;
  return (_cntlzw(*(_DWORD *)(a4 + 68) - LODWORD(splinePos[6].distance)) & 0x20) != 0;
}


// ========================================================================
// ?CleanupSplineEntities@idNavSplinePathMgr@@IAAXXZ
// EA  : 0x82CBE2F8
// RVA : 0x00CBE2F8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::CleanupSplineEntities(idNavSplinePathMgr *this)
{
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  int *p_cleanupIndex; // r31
  int cleanupIndex; // r10
  int v5; // r28
  int v6; // r30
  idStaticList<idNavSpline,200> *v7; // r3

  p_cleanupIndex = &this->cleanupIndex;
  NavSplineList = idNavSplinePathMgr::GetNavSplineList(this);
  cleanupIndex = this->cleanupIndex;
  v5 = cleanupIndex + 10;
  if ( cleanupIndex + 10 >= NavSplineList->num - 1 )
    v5 = NavSplineList->num - 1;
  if ( cleanupIndex <= v5 )
  {
    do
    {
      v6 = (*p_cleanupIndex)++;
      v7 = idNavSplinePathMgr::GetNavSplineList(this);
      idNavSpline::CleanupEntityList(this: &v7->list[v6]);
    }
    while ( *p_cleanupIndex <= v5 );
  }
  if ( *p_cleanupIndex >= idNavSplinePathMgr::GetNavSplineList(this)->num )
    *p_cleanupIndex = 0;
}


// ========================================================================
// ?GetSharedNode@idNavSplinePathMgr@@QAAPAUnavSplinePathNode_t@@PAVidNavSpline@@0@Z
// EA  : 0x82CBE390
// RVA : 0x00CBE390
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

navSplinePathNode_t *__fastcall idNavSplinePathMgr::GetSharedNode(
        idNavSplinePathMgr *this,
        idNavSpline *spline1,
        idNavSpline *spline2)
{
  navSplinePathNode_t *result; // r3
  int num; // r7
  int v5; // r10
  int v6; // r11
  navSplineLink_t *v7; // r9
  int v8; // r10
  int v9; // r7
  int v10; // r11
  navSplineLink_t *list; // r9

  if ( spline1 == nullptr
    || spline2 == nullptr
    || (result = spline1->startNode) == nullptr
    || spline2->startNode == nullptr )
  {
    idLib::Warning(fmt: "Bad spline data in idNavSplinePathMgr::GetSharedNode!");
    return nullptr;
  }
  num = result->links.num;
  v5 = 0;
  if ( num <= 0 )
  {
LABEL_9:
    result = spline1->endNode;
    v8 = 0;
    v9 = result->links.num;
    if ( v9 > 0 )
    {
      v10 = 0;
      list = result->links.list;
      while ( list->navSpline != spline2 )
      {
        ++v8;
        list = &result->links.list[++v10];
        if ( v8 >= v9 )
          return nullptr;
      }
      return result;
    }
    return nullptr;
  }
  v6 = 0;
  v7 = result->links.list;
  while ( v7->navSpline != spline2 )
  {
    ++v5;
    v7 = &result->links.list[++v6];
    if ( v5 >= num )
      goto LABEL_9;
  }
  return result;
}


// ========================================================================
// ?Evaluate@idClosestNavSplineEvaluator@@QAAXVidNavSplinePosition@@MVidVec3@@H@Z
// EA  : 0x82CBE478
// RVA : 0x00CBE478
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClosestNavSplineEvaluator::Evaluate(
        idClosestNavSplineEvaluator *this,
        __int64 forward,
        double distSqrToWorldPos,
        int force_cl_dist,
        __int64 a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  double v19; // fp30
  double v20; // fp29
  double v21; // fp28
  char v22; // r11
  double SplineWidth; // fp1
  double v24; // fp0
  idVec3 *v25; // r3
  float *v26; // r11
  double v27; // fp0
  double v28; // fp12
  bool v29; // r10
  int v30; // r10
  int v31; // r9
  int v32; // r8
  float *v33; // r11
  int v34; // r10
  int v35; // r9
  int v36; // r8
  idNavSplinePosition v37; // [sp+50h] [-70h] BYREF
  idNavSplinePosition v38; // [sp+60h] [-60h] BYREF
  idNavSplinePosition v39[4]; // [sp+70h] [-50h] BYREF

  a11 = *(__int64 *)((char *)&forward + 4);
  a12 = forward;
  a15 = *(__int64 *)((char *)&a5 + 4);
  a16 = a5;
  idNavSplinePosition::GetSplineWorldPos(this: &v37, result: (idVec3 *)&a11);
  if ( a6 < 0 )
  {
    if ( (float)(this->worldPos.z - *(float *)&v37.navSpline) <= -100.0 )
    {
      a6 = 1;
      distSqrToWorldPos = (float)((float)((float)((float)(this->worldPos.z - *(float *)&v37.navSpline)
                                                * (float)(this->worldPos.z - *(float *)&v37.navSpline))
                                        * (float)20.0)
                                + (float)distSqrToWorldPos);
    }
    else
    {
      a6 = 0;
    }
  }
  v19 = *(float *)&a15;
  v20 = *(float *)&a16;
  v21 = *((float *)&a15 + 1);
  if ( *(float *)&a15 != vec3_origin.x || v21 != vec3_origin.y || (v22 = 1, v20 != vec3_origin.z) )
    v22 = 0;
  if ( v22 == 0 )
  {
    SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&a11, dist: -1.0);
    if ( distSqrToWorldPos < (float)((float)((float)SplineWidth + (float)200.0)
                                   * (float)((float)SplineWidth + (float)200.0)) )
    {
      idNavSplinePosition::GetForward(this: &v38, result: (idVec3 *)&a11);
      v24 = (float)((float)((float)((float)(this->worldPos.x - v37.distance) * v38.distance)
                          + (float)((float)(*(float *)&v38.navSpline
                                          * (float)(this->worldPos.z - *(float *)&v37.navSpline))
                                  + (float)(v38.rightDistance * (float)(this->worldPos.y - v37.rightDistance))))
                  + *(float *)&a11);
      if ( v24 >= 0.0 && v24 <= *(float *)(HIDWORD(a12) + 12) )
      {
        v25 = idNavSplinePosition::GetForward(this: v39, result: (idVec3 *)&a11);
        v26 = &this->worldPos.x + 5 * a6;
        v27 = v26[3];
        v28 = __fabs((float)((float)(v25->x * (float)v19)
                           + (float)((float)(v25->z * (float)v20) + (float)(v25->y * (float)v21))));
        v29 = distSqrToWorldPos < v27;
        if ( distSqrToWorldPos < 250000.0 && v27 < 250000.0 )
          v29 = v28 > v26[4];
        if ( v29 )
        {
          v30 = HIDWORD(a11);
          v26[4] = v28;
          v31 = a11;
          v26[3] = distSqrToWorldPos;
          v32 = HIDWORD(a12);
          *((_DWORD *)v26 + 5) = v30;
          *((_DWORD *)v26 + 6) = v31;
          *((_DWORD *)v26 + 7) = v32;
        }
      }
    }
  }
  v33 = &this->worldPos.x + 5 * a6;
  if ( v33[4] == 0.0 && distSqrToWorldPos < v33[3] )
  {
    v34 = HIDWORD(a11);
    v33[3] = distSqrToWorldPos;
    v35 = a11;
    v36 = HIDWORD(a12);
    *((_DWORD *)v33 + 5) = v34;
    *((_DWORD *)v33 + 6) = v35;
    *((_DWORD *)v33 + 7) = v36;
  }
}


// ========================================================================
// ?GetClosestPathPosition@idClosestNavSplineEvaluator@@QAA?AVidNavSplinePosition@@XZ
// EA  : 0x82CBE6F0
// RVA : 0x00CBE6F0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idClosestNavSplineEvaluator *__fastcall idClosestNavSplineEvaluator::GetClosestPathPosition(
        idClosestNavSplineEvaluator *this,
        idNavSplinePosition *result)
{
  float distance; // r11
  float rightDistance; // r11
  bool v4; // zf
  float v5; // r10
  float v6; // r9
  float v7; // r10
  float v8; // r9
  float v9; // r11
  double v10; // fp0
  float v11; // r10
  float v12; // r9
  idNavSpline *navSpline; // r10
  float v14; // r9

  distance = result[4].distance;
  if ( spl_testClosestDist.valueInteger != 0 )
  {
    v4 = LODWORD(distance) == 0;
    rightDistance = result[2].rightDistance;
    if ( v4 )
    {
      if ( rightDistance != 0.0 )
      {
        v7 = result[2].distance;
        v8 = result[2].rightDistance;
        LODWORD(this->worldPos.x) = result[1].navSpline;
        this->worldPos.y = v7;
        this->worldPos.z = v8;
        return this;
      }
    }
    else if ( rightDistance != 0.0 && result[1].distance < (double)*(float *)&result[2].navSpline )
    {
      goto LABEL_5;
    }
LABEL_14:
    navSpline = result[3].navSpline;
    v14 = result[4].distance;
    this->worldPos.x = result[3].rightDistance;
    LODWORD(this->worldPos.y) = navSpline;
    this->worldPos.z = v14;
    return this;
  }
  v4 = LODWORD(distance) == 0;
  v9 = result[2].rightDistance;
  if ( !v4 )
  {
    if ( v9 != 0.0 )
    {
      v10 = *(float *)&result[2].navSpline;
      if ( v10 > 1000000.0 && result[1].distance < v10 )
      {
        v11 = result[2].distance;
        v12 = result[2].rightDistance;
        LODWORD(this->worldPos.x) = result[1].navSpline;
        this->worldPos.y = v11;
        this->worldPos.z = v12;
        return this;
      }
    }
    goto LABEL_14;
  }
  if ( v9 == 0.0 )
    goto LABEL_14;
LABEL_5:
  v5 = result[2].distance;
  v6 = result[2].rightDistance;
  LODWORD(this->worldPos.x) = result[1].navSpline;
  this->worldPos.y = v5;
  this->worldPos.z = v6;
  return this;
}


// ========================================================================
// ?Update@idQuestNavSplinePathMgr@@UAAXXZ
// EA  : 0x82CBE7E0
// RVA : 0x00CBE7E0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idQuestNavSplinePathMgr::Update(idQuestNavSplinePathMgr *this)
{
  __int64 v2; // r10
  double updatetime; // fp0
  __int64 v4; // r26
  int v5; // r27
  int v6; // r30
  float *v7; // r11
  idList<idEventReceiver *,5> *v8; // r8
  idList<idEventReceiver *,5> *v9; // r7
  int v10; // r6
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  idColor *v12; // r4
  idQuestNavSplinePath *DrawColor; // r3
  idList<idEventReceiver *,5> *listenerList; // r9
  idList<idEventReceiver *,5> *listeningToList; // r8
  int len; // r7
  BOOL v17; // r28
  idNavSpline *v18; // r29
  idStaticList<idNavSpline,200> *v19; // r3
  __int64 v20; // r6
  char v21; // r10
  int v22; // r8
  int v23; // r7
  idNavSpline *v24; // r9
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  float *v27; // r3
  int v28; // r29
  double v41; // fp28
  double v42; // fp27
  double v43; // fp29
  double v44; // fp25
  double v45; // fp24
  double v46; // fp26
  int v47; // r30
  float *v48; // r11
  double v49; // fp0
  char v50; // r11
  idStaticList<idNavSpline,200> *v51; // r3
  double clockTicks; // fp31
  __int64 v53; // r3
  double v54; // r5
  __int64 v55; // r11
  int v56; // [sp+8h] [-148h]
  __int64 v57; // [sp+10h] [-140h]
  __int64 v58; // [sp+18h] [-138h]
  __int64 v59; // [sp+20h] [-130h]
  __int64 v60; // [sp+28h] [-128h]
  __int64 v61; // [sp+30h] [-120h]
  __int64 v62; // [sp+50h] [-100h] BYREF
  float v63; // [sp+58h] [-F8h]
  float v64; // [sp+5Ch] [-F4h]
  float v65; // [sp+60h] [-F0h] BYREF
  float v66; // [sp+64h] [-ECh]
  float v67; // [sp+68h] [-E8h]
  float v68; // [sp+6Ch] [-E4h]
  float v69; // [sp+70h] [-E0h] BYREF
  float v70; // [sp+74h] [-DCh]
  float v71; // [sp+78h] [-D8h]
  float v72; // [sp+7Ch] [-D4h]
  idQuestNavSplinePath_vtbl *v73; // [sp+80h] [-D0h]
  idList<idEventReceiver *,5> *v74; // [sp+84h] [-CCh]
  idList<idEventReceiver *,5> *v75; // [sp+88h] [-C8h]
  int v76; // [sp+8Ch] [-C4h]
  char v77; // [sp+90h] [-C0h] BYREF

  if ( gameLocal != nullptr )
  {
    LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    updatetime = this->updatetime;
    v62 = v2;
    if ( (float)v2 != updatetime )
    {
      idNavSplinePathMgr::CleanupSplineEntities(this);
      if ( spl_qn_timer.valueInteger != 0 )
      {
        cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
        debugHUD->Clear(this: debugHUD, a2: false);
        debugHUD->Printf_3(this: debugHUD, a2: 0, a3: 0, a4: &byte_8200D768);
      }
      HIDWORD(v4) = &spl_qn_showAllPaths;
      LODWORD(v4) = 0;
      if ( spl_qn_showAllPaths.valueFloat != 0.0 )
      {
        v5 = 0;
        if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
        {
          v6 = 0;
          do
          {
            if ( idNavSplinePathMgr::GetNavSplineList(this)->list[v6].startNode != nullptr
              || idNavSplinePathMgr::GetNavSplineList(this)->list[v6].endNode != nullptr )
            {
              v69 = 1.0;
              v7 = &v69;
              v70 = 1.0;
              v71 = 1.0;
              v72 = 1.0;
            }
            else
            {
              *(float *)&v62 = 0.25;
              v7 = (float *)&v62;
              *((float *)&v62 + 1) = 0.25;
              v63 = 0.25;
              v64 = 0.25;
            }
            v8 = *((idList<idEventReceiver *,5> **)v7 + 1);
            v9 = *((idList<idEventReceiver *,5> **)v7 + 2);
            v10 = *((_DWORD *)v7 + 3);
            v73 = *(idQuestNavSplinePath_vtbl **)v7;
            v74 = v8;
            v75 = v9;
            v76 = v10;
            NavSplineList = idNavSplinePathMgr::GetNavSplineList(this);
            v12 = (idColor *)idQuestNavSplinePath::CastTo(c: (idQuestNavSplinePath *)NavSplineList->list[v6].splinePath);
            if ( v12 != nullptr )
            {
              DrawColor = idQuestNavSplinePath::GetDrawColor(this: (idQuestNavSplinePath *)&v77, result: v12);
              listenerList = DrawColor->listenerList;
              listeningToList = DrawColor->listeningToList;
              len = DrawColor->name.len;
              v73 = DrawColor->__vftable;
              v74 = listenerList;
              v75 = listeningToList;
              v76 = len;
            }
            v17 = spl_qn_showAllPaths.valueFloat > 1.0;
            v18 = &idNavSplinePathMgr::GetNavSplineList(this)->list[v6];
            v19 = idNavSplinePathMgr::GetNavSplineList(this);
            HIDWORD(v20) = v76;
            idNavSpline::Draw(
              this: &v19->list[v6],
              showRight: v20,
              startDist: 0.0,
              endDist: v18->length,
              stepSize: 100.0,
              a6: v23,
              a7: v22,
              a8: v17,
              a9: v21,
              a10: v56,
              a11: v57,
              a12: v58,
              a13: v59,
              a14: v60,
              a15: v61);
            ++v5;
            v24 = &idNavSplinePathMgr::GetNavSplineList(this)->list[v6++];
            v24->drawtime = 0;
          }
          while ( v5 < idNavSplinePathMgr::GetNavSplineList(this)->num );
        }
      }
      if ( spl_qn_showPathBounds.valueInteger != 0 )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        Physics = idEntity::GetPhysics(this: DebugPlayer);
        v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v28 = 0;
        _FP8 = (float)((float)1.0e30 - v27[1]);
        _FP6 = (float)((float)1.0e30 - v27[2]);
        _FP10 = (float)((float)1.0e30 - *v27);
        _FP3 = (float)(v27[1] - (float)-1.0e30);
        _FP2 = (float)(v27[2] - (float)-1.0e30);
        _FP4 = (float)(*v27 - (float)-1.0e30);
        __asm
        {
          fsel      f13, f8, f11, f28
          fsel      f11, f6, f9, f28
          fsel      f1, f10, f12, f28
          fsel      f9, f3, f7, f25
          fsel      f8, f2, f5, f25
          fsel      f10, f4, f12, f25
        }
        v41 = (float)((float)_FP13 - (float)1000.0);
        v42 = (float)((float)_FP11 - (float)1000.0);
        v43 = (float)((float)_FP1 - (float)1000.0);
        v44 = (float)((float)_FP9 + (float)1000.0);
        v45 = (float)((float)_FP8 + (float)1000.0);
        v46 = (float)((float)_FP10 + (float)1000.0);
        if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
        {
          v47 = 0;
          do
          {
            v65 = 0.5;
            v66 = 0.5;
            v67 = 0.5;
            v68 = 1.0;
            v48 = (float *)&idNavSplinePathMgr::GetNavSplineList(this)->list[v47];
            if ( v48[24] < v43
              || v48[25] < v41
              || v48[26] < v42
              || v48[21] > v46
              || v48[22] > v44
              || (v49 = v48[23], v50 = 1, v49 > v45) )
            {
              v50 = 0;
            }
            if ( v50 == 0 )
            {
              v69 = 1.0;
              v70 = 1.0;
              v71 = 1.0;
              v72 = 1.0;
              v68 = 1.0;
              v66 = 1.0;
              v65 = 1.0;
              v67 = 1.0;
            }
            v51 = idNavSplinePathMgr::GetNavSplineList(this);
            clientGame->renderWorld->DebugBounds(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&v65,
              a3: &v51->list[v47].bounds,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            ++v28;
            ++v47;
          }
          while ( v28 < idNavSplinePathMgr::GetNavSplineList(this)->num );
        }
      }
      if ( spl_qn_graph.valueInteger != 0 )
        idNavSplineGraph::Draw(this: &this->splineGraph);
      if ( spl_qn_timer.valueInteger != 0 )
      {
        debugHUD->Printf(this: debugHUD, a2: "\n^3-- PATH TIMING --\n");
        clockTicks = (float)this->navSplinePathTimer.clockTicks;
        LODWORD(v53) = Sys_ClockTicksPerSecond();
        v62 = v53;
        v54 = (float)((float)clockTicks / (float)((float)v53 * (float)0.001));
        debugHUD->Printf(
          this: debugHUD,
          a2: (const char *)HIDWORD(v54),
          LODWORD(v54),
          this->navSplinePathCount,
          this->navSplinePathCount2);
        this->navSplinePathTimer.clockTicks = v4;
        this->navSplinePathCount = 0;
        this->navSplinePathCount2 = 0;
      }
      LODWORD(v55) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->updatetime = (float)v55;
    }
  }
}


// ========================================================================
// ?GetNextRecalcTime@idNavSplinePathMgr@@UAAMXZ
// EA  : 0x82CBED70
// RVA : 0x00CBED70
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

float __fastcall idNavSplinePathMgr::GetNextRecalcTime(idQuestNavSplinePathMgr *this)
{
  int nextRecalcTime; // r29
  __int64 v3; // r10
  double v4; // fp1

  nextRecalcTime = this->nextRecalcTime;
  if ( nextRecalcTime >= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
  {
    if ( (spl_updateTracker_rateMS.flags & 0x20000) != 0 )
      this->nextRecalcTime = nextRecalcTime + spl_updateTracker_rateMS.valueInteger;
    else
      this->nextRecalcTime += GameFramesToMS(frameNum: 1, type: GAMETIME_SCALED);
  }
  else
  {
    this->nextRecalcTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
  LODWORD(v3) = this->nextRecalcTime;
  v4 = (float)v3;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Evaluate@idClosestQuestNavSplineEvaluator@@QAAXVidNavSplinePosition@@M@Z
// EA  : 0x82CBEE28
// RVA : 0x00CBEE28
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClosestQuestNavSplineEvaluator::Evaluate(
        idClosestQuestNavSplineEvaluator *this,
        __int64 pathPos,
        double distSqrToWorldPos,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  double v15; // fp30
  double SplineWidth; // fp1
  float v17; // r11
  float v18; // r10
  idNavSpline *v19; // r9
  idNavSplinePosition v20; // [sp+50h] [-30h] BYREF

  a12 = *(__int64 *)((char *)&pathPos + 4);
  HIDWORD(pathPos) = &a12;
  a13 = pathPos;
  idNavSplinePosition::GetSplineWorldPos(this: &v20, result: (idVec3 *)&a12);
  v15 = (float)(this->worldPos.z - *(float *)&v20.navSpline);
  SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&a12, dist: -1.0);
  if ( distSqrToWorldPos < (float)((float)SplineWidth * (float)SplineWidth) )
    distSqrToWorldPos = (float)(spl_qn_pathbonus.valueFloat * (float)distSqrToWorldPos);
  if ( (float)((float)((float)(spl_qn_zpenelty.valueFloat * (float)v15) * (float)v15) + (float)distSqrToWorldPos) < (double)this->closest.distance )
  {
    v17 = *(float *)&a12;
    this->closest.distance = (float)((float)(spl_qn_zpenelty.valueFloat * (float)v15) * (float)v15)
                           + (float)distSqrToWorldPos;
    v18 = *((float *)&a12 + 1);
    v19 = (idNavSpline *)HIDWORD(a13);
    this->closest.pathPos.distance = v17;
    this->closest.pathPos.rightDistance = v18;
    this->closest.pathPos.navSpline = v19;
  }
}


// ========================================================================
// ?GetClosestPathPosition@idNavSplinePathMgr@@UAA?AVidNavSplinePosition@@VidVec3@@PAVidNavSpline@@MM0_N@Z
// EA  : 0x82CBEFB8
// RVA : 0x00CBEFB8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePathMgr *__fastcall idNavSplinePathMgr::GetClosestPathPosition(
        idNavSplinePathMgr *this,
        __int64 worldPos,
        idNavSpline *navSpline,
        double boundsRadius,
        double epsilon,
        idNavSpline *forward,
        bool useClosestZ,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        char a33)
{
  idTimer *v36; // r20
  __int64 v38; // r3
  char v39; // r11
  int v40; // r10
  float *v41; // r8
  int v42; // r7
  idCurve_Spline<idVec3> *curve; // r9
  int width_low; // r8
  __int64 v52; // r27
  double v55; // fp30
  double v56; // fp29
  double v57; // fp28
  double v58; // fp31
  int v59; // r30
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  idNavSpline *v61; // r31
  char v62; // r11
  char v63; // r11
  char v64; // r11
  int v65; // r10
  float *v66; // r8
  int v67; // r7
  __int64 v68; // r6
  idClosestNavSplineEvaluator *ClosestPathPosition; // r3
  int z_low; // r31
  idNavSplinePathMgr_vtbl *x_low; // r30
  float y; // r29
  int v73; // [sp+8h] [-148h]
  int v74; // [sp+8h] [-148h]
  int v75; // [sp+Ch] [-144h]
  int v76; // [sp+Ch] [-144h]
  int v77; // [sp+10h] [-140h]
  __int64 v78; // [sp+10h] [-140h]
  int v79; // [sp+14h] [-13Ch]
  int v80; // [sp+18h] [-138h]
  __int64 v81; // [sp+18h] [-138h]
  int v82; // [sp+1Ch] [-134h]
  int v83; // [sp+20h] [-130h]
  __int64 v84; // [sp+20h] [-130h]
  int v85; // [sp+24h] [-12Ch]
  int v86; // [sp+28h] [-128h]
  __int64 v87; // [sp+28h] [-128h]
  int v88; // [sp+2Ch] [-124h]
  int v89; // [sp+30h] [-120h]
  __int64 v90; // [sp+30h] [-120h]
  int v91; // [sp+34h] [-11Ch]
  int v92; // [sp+38h] [-118h]
  __int64 v93; // [sp+38h] [-118h]
  int v94; // [sp+3Ch] [-114h]
  int v95; // [sp+40h] [-110h]
  __int64 v96; // [sp+40h] [-110h]
  int v97; // [sp+44h] [-10Ch]
  int v98; // [sp+48h] [-108h]
  __int64 v99; // [sp+48h] [-108h]
  int v100; // [sp+4Ch] [-104h]
  int v101; // [sp+50h] [-100h]
  __int64 v102; // [sp+50h] [-100h]
  float *v103; // [sp+58h] [-F8h]
  float v104; // [sp+60h] [-F0h] BYREF
  float v105; // [sp+64h] [-ECh] BYREF
  float v106[2]; // [sp+68h] [-E8h] BYREF
  idNavSpline v107; // [sp+70h] [-E0h] BYREF
  int v109; // [sp+178h] [+28h]

  v109 = worldPos;
  *(_DWORD *)(HIDWORD(worldPos) + 64) = 0;
  v36 = (idTimer *)(HIDWORD(worldPos) + 56);
  LODWORD(v38) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  *(_QWORD *)(HIDWORD(worldPos) + 72) = v38;
  ++*(_DWORD *)(HIDWORD(worldPos) + 88);
  if ( forward == nullptr )
    goto LABEL_7;
  if ( forward->startNode == nullptr || (v39 = 1, forward->endNode == nullptr) )
    v39 = 0;
  if ( v39 != 0 )
  {
    idNavSpline::GetClosestSection(
      this: forward,
      (idVec3 *)worldPos,
      minDist: (float *)__ROL4__(v109, 32),
      maxDist: &v105,
      distanceToWorldPos: &v104);
    idNavSpline::GetClosestPositionFromSection(
      this: &v107,
      worldPos: __SPAIR64__(worldPos, __ROL4__(v109, 32)),
      minDist: v105,
      maxDist: v104,
      iterations: v42,
      epsilon: 0.1,
      distSqrToWorldPos: v41,
      a8: 8,
      a9: v40,
      a10: v73,
      a11: v75,
      a12: v77,
      a13: v79,
      a14: v80,
      a15: v82,
      a16: v83,
      a17: v85,
      a18: v86,
      a19: v88,
      a20: v89,
      a21: v91,
      a22: v92,
      a23: v94,
      a24: v95,
      a25: v97,
      a26: v98,
      a27: v100,
      a28: v101,
      a29: 0,
      a30: v103);
    idTimer::Stop(this: v36);
    curve = v107.curve;
    width_low = LODWORD(v107.width);
    this->__vftable = (idNavSplinePathMgr_vtbl *)v107.splinePath;
    *((_DWORD *)&this->__vftable + 1) = curve;
    this->nextRecalcTime = width_low;
    return this;
  }
  else
  {
LABEL_7:
    v107.prev.size = 0;
    _FP4 = (float)((float)1.0e30 - *(float *)&worldPos);
    _FP5 = (float)((float)1.0e30 - *((float *)&worldPos + 1));
    *(float *)&v107.prev.list = 0.0;
    *(float *)&v107.prev.num = 0.0;
    *(float *)&v107.entityList.num = 0.0;
    *(float *)&v107.entityList.size = 0.0;
    *(float *)&v107.next.granularity = 0.0;
    *(float *)&v107.entityList.list = 0.0;
    *(float *)&v107.next.size = 1.0e30;
    *(float *)&v107.prev.granularity = 1.0e30;
    *(_DWORD *)&v107.entityList.granularity = 0;
    _FP3 = (float)(*((float *)&worldPos + 1) - (float)-1.0e30);
    *(float *)&v107.traversed = *(float *)&worldPos;
    _FP2 = (float)(*(float *)&worldPos - (float)-1.0e30);
    __asm { fsel      f0, f4, f12, f13 }
    __asm { fsel      f1, f5, f11, f13 }
    v107.next.list = (navSplineConnection_t *)worldPos;
    v107.next.num = v109;
    HIDWORD(v52) = 0;
    __asm
    {
      fsel      f13, f3, f11, f9
      fsel      f12, f2, f12, f9
    }
    v55 = (float)((float)_FP0 - (float)boundsRadius);
    v56 = (float)((float)_FP1 - (float)boundsRadius);
    v57 = (float)((float)_FP13 + (float)boundsRadius);
    v58 = (float)((float)_FP12 + (float)boundsRadius);
    if ( idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)HIDWORD(worldPos))->num > 0 )
    {
      LODWORD(v52) = v109;
      v59 = 0;
      do
      {
        NavSplineList = idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)HIDWORD(worldPos));
        v61 = &NavSplineList->list[v59];
        if ( (*(_BYTE *)&v61->splinePath->splineFlags & 0x40) != 0
          || (v62 = 0, (*(_BYTE *)&v61->splinePath->splineFlags & 0x20) != 0) )
        {
          v62 = 1;
        }
        if ( v62 != 0 )
        {
          if ( v61->startNode == nullptr || (v63 = 1, v61->endNode == nullptr) )
            v63 = 0;
          if ( v63 != 0 && (*(_BYTE *)&v61->splinePath->splineFlags & 2) != 0 )
          {
            if ( v61->bounds.b[1].x < v55
              || v61->bounds.b[1].y < v56
              || v61->bounds.b[0].x > v58
              || (v64 = 1, v61->bounds.b[0].y > v57) )
            {
              v64 = 0;
            }
            if ( v64 != 0 )
            {
              idNavSpline::GetClosestSection(
                this: &NavSplineList->list[v59],
                worldPos: (idVec3 *)v109,
                minDist: nullptr,
                maxDist: &v104,
                distanceToWorldPos: &v105);
              idNavSpline::GetClosestPositionFromSection(
                this: &v107,
                worldPos: v52 << 32,
                minDist: v104,
                maxDist: v105,
                iterations: v67,
                epsilon: 0.1,
                distSqrToWorldPos: v66,
                a8: 8,
                a9: v65,
                a10: v73,
                a11: v75,
                a12: v77,
                a13: v79,
                a14: v80,
                a15: v82,
                a16: v83,
                a17: v85,
                a18: v86,
                a19: v88,
                a20: v89,
                a21: v91,
                a22: v92,
                a23: v94,
                a24: v95,
                a25: v97,
                a26: v98,
                a27: v100,
                a28: v101,
                a29: (int)v106,
                a30: v103);
              HIDWORD(v68) = __ROL4__(LODWORD(v107.width), 32);
              idClosestNavSplineEvaluator::Evaluate(
                this: (idClosestNavSplineEvaluator *)&v107.traversed,
                forward: v68,
                distSqrToWorldPos: v106[0],
                force_cl_dist: a30,
                a5: __SPAIR64__((unsigned int)(a33 == 0) - 1, LODWORD(v107.width)),
                a6: v74,
                a7: v76,
                a8: v78,
                a9: v81,
                a10: v84,
                a11: v87,
                a12: v90,
                a13: v93,
                a14: v96,
                a15: v99,
                a16: v102);
            }
          }
        }
        ++HIDWORD(v52);
        ++v59;
      }
      while ( SHIDWORD(v52) < idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)HIDWORD(worldPos))->num );
    }
    ClosestPathPosition = (idClosestNavSplineEvaluator *)&v107;
    if ( a33 != 0 )
    {
      ClosestPathPosition = idClosestNavSplineEvaluator::GetClosestPathPosition(
                              this: (idClosestNavSplineEvaluator *)&v107,
                              result: (idNavSplinePosition *)&v107.traversed);
    }
    else
    {
      *(_QWORD *)&v107.splinePath = *(_QWORD *)&v107.prev.list;
      LODWORD(v107.width) = v107.prev.size;
    }
    z_low = LODWORD(ClosestPathPosition->worldPos.z);
    x_low = (idNavSplinePathMgr_vtbl *)LODWORD(ClosestPathPosition->worldPos.x);
    y = ClosestPathPosition->worldPos.y;
    if ( z_low == 0 )
      z_low = HIDWORD(worldPos) + 103572;
    idTimer::Stop(this: v36);
    this->__vftable = x_low;
    *((float *)&this->__vftable + 1) = y;
    this->nextRecalcTime = z_low;
    return this;
  }
}


// ========================================================================
// ?FindNavSpline@idNavSplinePathMgr@@QAAPAVidNavSpline@@VidStr@@_N@Z
// EA  : 0x82CBF370
// RVA : 0x00CBF370
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSpline *__fastcall idNavSplinePathMgr::FindNavSpline(
        idNavSplinePathMgr *this,
        idStr *splineName,
        bool searchExact)
{
  int v6; // r28
  BOOL v7; // r26
  int v8; // r30
  char *data; // r4
  int v10; // r5
  idNavSpline *v12; // r30

  v6 = 0;
  if ( idNavSplinePathMgr::GetNavSplineList(this)->num <= 0 )
  {
LABEL_10:
    idStr::FreeData(this: splineName);
    return nullptr;
  }
  v7 = searchExact;
  v8 = 0;
  while ( 1 )
  {
    data = idNavSplinePathMgr::GetNavSplineList(this)->list[v8].splinePath->name.data;
    if ( !v7 )
      break;
    if ( idStr::Icmp(s1: splineName->data, s2: data) == 0 )
      goto LABEL_11;
LABEL_9:
    ++v6;
    ++v8;
    if ( v6 >= idNavSplinePathMgr::GetNavSplineList(this)->num )
      goto LABEL_10;
  }
  v10 = 0;
  if ( *data != 0 )
  {
    do
      ++v10;
    while ( data[v10] != 0 );
  }
  if ( idStr::Icmpn(s1: splineName->data, s2: data, n: v10) != 0 )
    goto LABEL_9;
LABEL_11:
  v12 = &idNavSplinePathMgr::GetNavSplineList(this)->list[v6];
  idStr::FreeData(this: splineName);
  return v12;
}


// ========================================================================
// __unwind$495615
// EA  : 0x82CBF480
// RVA : 0x00CBF480
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_495615()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 172));
}


// ========================================================================
// ?GetTrackerIndex@idNavSplinePathMgr@@IBAHABVidSpawnId@@@Z
// EA  : 0x82CBF4A8
// RVA : 0x00CBF4A8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

int __fastcall idNavSplinePathMgr::GetTrackerIndex(idNavSplinePathMgr *this, const idSpawnId *ownerSpawnId)
{
  int value; // r6
  int lookupMask; // r7
  int v4; // r11
  int v5; // r10
  char *v6; // r4

  value = ownerSpawnId->value;
  lookupMask = this->trackerHash.lookupMask;
  v4 = this->trackerHash.hash[this->trackerHash.hashMask & lookupMask & ownerSpawnId->value];
  if ( v4 == -1 )
    return -1;
  v5 = v4;
  while ( 1 )
  {
    v6 = (char *)this + 312 * this->usedTrackers.list[v5].value;
    if ( v6 != (char *)-140 && value == *((_DWORD *)v6 + 35) )
      break;
    v4 = this->trackerHash.indexChain[lookupMask & v4];
    v5 = v4;
    if ( v4 == -1 )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?GetClosestPathPosition@idQuestNavSplinePathMgr@@UAA?AVidNavSplinePosition@@VidVec3@@PAVidNavSpline@@MM0_N@Z
// EA  : 0x82CBF540
// RVA : 0x00CBF540
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePosition *__fastcall idQuestNavSplinePathMgr::GetClosestPathPosition(
        idQuestNavSplinePathMgr *this,
        navSplineConnection_t *result,
        idVec3 *worldPos,
        idNavSpline *navSpline,
        double boundsRadius,
        double epsilon,
        idVec3 *forward,
        bool useClosestZ)
{
  __int64 v8; // r25
  double v16; // fp31
  double v19; // fp28
  double v20; // fp30
  double v21; // fp29
  int v22; // r27
  int v23; // r28
  idNavSpline *v24; // r30
  idNavSplinePath *splinePath; // r10
  idNavSplinePath::splineFlags_t splineFlags; // r11
  char v27; // r11
  bool v28; // zf
  char v29; // r11
  char v30; // r11
  int v31; // r10
  float *v32; // r8
  int v33; // r7
  __int64 v34; // r6
  int v35; // r9
  int v36; // r8
  int v37; // r7
  navSplineConnection_t *list; // r10
  int num; // r9
  int size; // r8
  int v42; // [sp+8h] [-108h]
  int v43; // [sp+8h] [-108h]
  int v44; // [sp+Ch] [-104h]
  int v45; // [sp+10h] [-100h]
  __int64 v46; // [sp+10h] [-100h]
  int v47; // [sp+14h] [-FCh]
  int v48; // [sp+18h] [-F8h]
  __int64 v49; // [sp+18h] [-F8h]
  int v50; // [sp+1Ch] [-F4h]
  int v51; // [sp+20h] [-F0h]
  __int64 v52; // [sp+20h] [-F0h]
  int v53; // [sp+24h] [-ECh]
  int v54; // [sp+28h] [-E8h]
  __int64 v55; // [sp+28h] [-E8h]
  int v56; // [sp+2Ch] [-E4h]
  int v57; // [sp+30h] [-E0h]
  __int64 v58; // [sp+30h] [-E0h]
  int v59; // [sp+34h] [-DCh]
  int v60; // [sp+38h] [-D8h]
  int v61; // [sp+3Ch] [-D4h]
  int v62; // [sp+40h] [-D0h]
  int v63; // [sp+44h] [-CCh]
  int v64; // [sp+48h] [-C8h]
  int v65; // [sp+4Ch] [-C4h]
  int v66; // [sp+50h] [-C0h]
  float *v67; // [sp+58h] [-B8h]
  float v68; // [sp+60h] [-B0h] BYREF
  float v69; // [sp+64h] [-ACh] BYREF
  float v70[2]; // [sp+68h] [-A8h] BYREF
  idNavSpline v71; // [sp+70h] [-A0h] BYREF

  HIDWORD(v8) = this;
  *(float *)&v71.prev.list = 0.0;
  *(float *)&v71.prev.num = 0.0;
  _FP6 = (float)((float)1.0e30 - *(float *)&result);
  _FP4 = (float)(*(float *)&result - (float)-1.0e30);
  *(_DWORD *)&v71.traversed = &idClosestQuestNavSplineEvaluator::`vftable';
  __asm { fsel      f2, f6, f12, f0 }
  _FP7 = (float)((float)1.0e30 - *(float *)&worldPos);
  _FP5 = (float)(*(float *)&worldPos - (float)-1.0e30);
  __asm { fsel      f9, f4, f12, f11 }
  v16 = (float)((float)_FP2 - (float)boundsRadius);
  __asm
  {
    fsel      f3, f7, f13, f0
    fsel      f10, f5, f13, f11
  }
  v19 = (float)((float)_FP9 + (float)boundsRadius);
  v20 = (float)((float)_FP3 - (float)boundsRadius);
  v21 = (float)((float)_FP10 + (float)boundsRadius);
  v71.next.list = result;
  v71.prev.size = 0;
  v71.next.num = (int)worldPos;
  v22 = 0;
  v71.next.size = (int)worldPos;
  *(float *)&v71.next.granularity = 1.0e30;
  if ( idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)result)->num > 0 )
  {
    LODWORD(v8) = worldPos;
    v23 = 0;
    do
    {
      v24 = &idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)result)->list[v23];
      splinePath = v24->splinePath;
      splineFlags = v24->splinePath->splineFlags;
      v70[1] = *(float *)&v24->splinePath;
      if ( (*(_BYTE *)&splineFlags & 0x40) != 0 || (v28 = (*(_BYTE *)&splineFlags & 0x20) == 0, v27 = 0, !v28) )
        v27 = 1;
      if ( v27 != 0 )
      {
        if ( v24->startNode == nullptr || (v29 = 1, v24->endNode == nullptr) )
          v29 = 0;
        if ( v29 != 0 && (*(_BYTE *)&splinePath->splineFlags & 2) != 0 )
        {
          if ( v24->bounds.b[1].x < v16
            || v24->bounds.b[1].y < v20
            || v24->bounds.b[0].x > v19
            || (v30 = 1, v24->bounds.b[0].y > v21) )
          {
            v30 = 0;
          }
          if ( v30 != 0 )
          {
            idNavSpline::GetClosestSection(
              this: v24,
              worldPos,
              minDist: nullptr,
              maxDist: &v69,
              distanceToWorldPos: &v68);
            idNavSpline::GetClosestPositionFromSection(
              this: &v71,
              worldPos: v8 << 32,
              minDist: v69,
              maxDist: v68,
              iterations: v33,
              epsilon: 0.1,
              distSqrToWorldPos: v32,
              a8: 8,
              a9: v31,
              a10: v42,
              a11: v44,
              a12: v45,
              a13: v47,
              a14: v48,
              a15: v50,
              a16: v51,
              a17: v53,
              a18: v54,
              a19: v56,
              a20: v57,
              a21: v59,
              a22: v60,
              a23: v61,
              a24: v62,
              a25: v63,
              a26: v64,
              a27: v65,
              a28: v66,
              a29: (int)v70,
              a30: v67);
            HIDWORD(v34) = __ROL4__(LODWORD(v71.width), 32);
            idClosestQuestNavSplineEvaluator::Evaluate(
              this: (idClosestQuestNavSplineEvaluator *)v71.splinePath,
              pathPos: v34,
              distSqrToWorldPos: v70[0],
              a4: v37,
              a5: v36,
              a6: v35,
              a7: SLODWORD(v71.width),
              a8: v43,
              a9: v46,
              a10: v49,
              a11: v52,
              a12: v55,
              a13: v58);
          }
        }
      }
      ++v22;
      ++v23;
    }
    while ( v22 < idNavSplinePathMgr::GetNavSplineList(this: (idNavSplinePathMgr *)result)->num );
  }
  list = v71.prev.list;
  num = v71.prev.num;
  size = v71.prev.size;
  *(_DWORD *)(HIDWORD(v8) + 8) = v71.prev.size;
  *(_DWORD *)HIDWORD(v8) = list;
  *(_DWORD *)(HIDWORD(v8) + 4) = num;
  if ( size == 0 )
    *(_DWORD *)(HIDWORD(v8) + 8) = (char *)result + 103572;
  return (idNavSplinePosition *)HIDWORD(v8);
}


// ========================================================================
// __unwind$495760
// EA  : 0x82CBF7C8
// RVA : 0x00CBF7C8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_495760()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 272 + 128));
}


// ========================================================================
// ??1idNavPathPosTrackerPool@@QAA@XZ
// EA  : 0x82CBF9C0
// RVA : 0x00CBF9C0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavPathPosTrackerPool::~idNavPathPosTrackerPool(idNavPathPosTrackerPool *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->freeTrackers);
  `eh vector destructor iterator'(
    ptr: this,
    size: 0x138u,
    count: 256,
    pDtor: (void (__fastcall *)(void *))idNavPathPosTracker::~idNavPathPosTracker);
}


// ========================================================================
// __unwind$496639_0
// EA  : 0x82CBFA1C
// RVA : 0x00CBFA1C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_496639_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: *(void **)(v0 - 112 + 132),
    size: 0x138u,
    count: 256,
    pDtor: (void (__fastcall *)(void *))idNavPathPosTracker::~idNavPathPosTracker);
}


// ========================================================================
// ?Clear@idNavPathPosTrackerPool@@QAAXXZ
// EA  : 0x82CBFC40
// RVA : 0x00CBFC40
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavPathPosTrackerPool::Clear(idNavPathPosTrackerPool *this)
{
  idStaticList<unsigned short,256> *p_freeTrackers; // r31
  int size; // r11
  int v3; // r11
  int v4; // r10
  int i; // ctr

  p_freeTrackers = &this->freeTrackers;
  if ( this->freeTrackers.size >= 256
    || (unsigned __int8)idList<unsigned short,30>::Resize(this: &this->freeTrackers, newsize: 256) != 0 )
  {
    size = p_freeTrackers->size;
    if ( size > 256 )
      size = 256;
    p_freeTrackers->num = size;
  }
  v3 = 0;
  v4 = 0;
  for ( i = 256; i != 0; --i )
    p_freeTrackers->list[v4++] = v3++;
}


// ========================================================================
// ?GetShortestPath@idNavSplinePathMgr@@QAAPAUnavSplinePath_t@@VidNavSplinePosition@@0PAU2@@Z
// EA  : 0x82CBFCD0
// RVA : 0x00CBFCD0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

navSplinePath_t *__fastcall idNavSplinePathMgr::GetShortestPath(
        idNavSplinePathMgr *this,
        idNavSpline *start,
        idNavSplinePosition *end,
        idNavSplinePosition *path,
        int a5,
        navSplinePath_t *a6)
{
  navSplinePath_t *p_splinePath; // r31
  char v9; // r11
  char v10; // r11
  int num; // r10
  idNavSplinePosition **list; // r11
  __int64 v14; // r3
  navSplinePath_t::path_t v15[10]; // [sp+50h] [-50h] BYREF

  p_splinePath = a6;
  if ( start == nullptr || path == nullptr )
    return nullptr;
  if ( start->startNode == nullptr || (v9 = 1, start->endNode == nullptr) )
    v9 = 0;
  if ( v9 == 0 )
    return nullptr;
  if ( path[5].navSpline == nullptr || (v10 = 1, LODWORD(path[6].distance) == 0) )
    v10 = 0;
  if ( v10 == 0 )
    return nullptr;
  if ( a6 == nullptr )
    p_splinePath = &this->splinePath;
  if ( spl_disablePathing.valueInteger != 0 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&p_splinePath->path);
    v15[0].navSpline = start;
    v15[0].dir = 1.0;
    idList<navSplinePath_t::path_t,5>::Append(this: &p_splinePath->path, obj: v15);
    v15[0].dir = -1.0;
    idList<navSplinePath_t::path_t,5>::Append(this: &p_splinePath->path, obj: v15);
    return p_splinePath;
  }
  num = p_splinePath->path.num;
  if ( num > 1 && *(float *)&this == p_splinePath->startDistance && *(float *)&end == p_splinePath->endDistance )
  {
    list = (idNavSplinePosition **)p_splinePath->path.list;
    if ( start == (idNavSpline *)*list && path == list[2 * num - 2] )
      return p_splinePath;
  }
  this->navSplinePathTimer.state = TS_STARTED;
  LODWORD(v14) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  this->navSplinePathTimer.start = v14;
  ++this->navSplinePathCount;
  idNavSplineGraph::GetShortestPath(
    this: &this->splineGraph,
    start,
    splinePath: (unsigned int)path,
    a4: 0,
    a5: (int)p_splinePath);
  idTimer::Stop(this: &this->navSplinePathTimer);
  return p_splinePath;
}


// ========================================================================
// ?GetShortestPathByList@idNavSplinePathMgr@@QAAPAUnavSplinePath_t@@VidNavSplinePosition@@AAV?$idList@PBVidSplineWaypoint@@$04@@PAU2@@Z
// EA  : 0x82CBFEA0
// RVA : 0x00CBFEA0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

navSplinePath_t *__fastcall idNavSplinePathMgr::GetShortestPathByList(
        idNavSplinePathMgr *this,
        idNavSpline *start,
        idList<idSplineWaypoint const *,5> *waypoints,
        navSplinePath_t *path,
        navSplinePath_t *a5)
{
  navSplinePath_t *p_splinePath; // r22
  int v8; // r10
  char v9; // r11
  char v10; // r11
  idTimer *p_navSplinePathTimer; // r30
  __int64 v12; // r3
  int *p_navSplinePathCount; // r27
  int v14; // r29
  int v15; // r26
  int v16; // r25
  int v17; // r28
  __int64 v18; // r3
  __int64 v19; // r6
  navSplinePath_t v21[4]; // [sp+50h] [-80h] BYREF

  p_splinePath = a5;
  if ( LODWORD(path->endDistance) == 0 )
    return nullptr;
  if ( start == nullptr )
    return nullptr;
  v8 = *(_DWORD *)(*(_DWORD *)LODWORD(path->startDistance) + 824);
  if ( v8 == 0 )
    return nullptr;
  if ( start->startNode == nullptr || (v9 = 1, start->endNode == nullptr) )
    v9 = 0;
  if ( v9 == 0 )
    return nullptr;
  if ( *(_DWORD *)(v8 + 68) == 0 || (v10 = 1, *(_DWORD *)(v8 + 72) == 0) )
    v10 = 0;
  if ( v10 == 0 )
    return nullptr;
  if ( a5 == nullptr )
    p_splinePath = &this->splinePath;
  p_navSplinePathTimer = &this->navSplinePathTimer;
  this->navSplinePathTimer.state = TS_STARTED;
  LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  this->navSplinePathTimer.start = v12;
  p_navSplinePathCount = &this->navSplinePathCount;
  ++this->navSplinePathCount;
  LODWORD(v12) = &this->splineGraph;
  v14 = *(_DWORD *)LODWORD(path->startDistance);
  idNavSplineGraph::GetShortestPath(
    this: (idNavSplineGraph *)v12,
    start,
    splinePath: *(_QWORD *)(v14 + 816),
    a4: __ROL4__(*(_DWORD *)(v14 + 824), 32),
    a5: (int)p_splinePath);
  idTimer::Stop(this: p_navSplinePathTimer);
  v15 = 1;
  if ( SLODWORD(path->endDistance) > 1 )
  {
    v16 = 4;
    do
    {
      v17 = *(_DWORD *)(LODWORD(path->startDistance) + v16);
      p_navSplinePathTimer->state = TS_STARTED;
      LODWORD(v18) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      p_navSplinePathTimer->start = v18;
      ++*p_navSplinePathCount;
      navSplinePath_t::navSplinePath_t(this: v21);
      v19 = *(_QWORD *)(v17 + 816);
      HIDWORD(v19) = __ROL4__(HIDWORD(v19), 32);
      idNavSplineGraph::GetShortestPath(
        this: *(idNavSplineGraph **)(v14 + 816),
        start: *(idNavSpline **)(v14 + 820),
        splinePath: v19,
        a4: __ROL4__(*(_DWORD *)(v17 + 824), 32),
        a5: (int)v21);
      navSplinePath_t::operator+=(this: p_splinePath, that: v21);
      idTimer::Stop(this: p_navSplinePathTimer);
      v14 = v17;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v21[0].path);
      ++v15;
      v16 += 4;
    }
    while ( v15 < SLODWORD(path->endDistance) );
  }
  return p_splinePath;
}


// ========================================================================
// __unwind$497146
// EA  : 0x82CC0064
// RVA : 0x00CC0064
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497146()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 208 + 80));
}


// ========================================================================
// ?GetPathDirection@idNavSplinePathMgr@@QAAMVidNavSplinePosition@@0@Z
// EA  : 0x82CC0090
// RVA : 0x00CC0090
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

float __fastcall idNavSplinePathMgr::GetPathDirection(
        idNavSplinePathMgr *this,
        idNavSpline *startPos,
        idNavSplinePosition *endPos,
        idNavSplinePosition *a4)
{
  navSplinePath_t *ShortestPath; // r3
  double dir; // fp1

  ShortestPath = idNavSplinePathMgr::GetShortestPath(
                   this,
                   start: startPos,
                   end: (idNavSplinePosition *)__ROL4__(startPos, 32),
                   path: a4,
                   a5: __ROL4__(a4, 32),
                   a6: nullptr);
  if ( ShortestPath != nullptr && ShortestPath->path.num != 0 )
  {
    dir = ShortestPath->path.list->dir;
  }
  else
  {
    idLib::Warning(
      fmt: "No path from %s to %s.",
      startPos->splinePath->name.data,
      *(const char **)(LODWORD(a4->distance) + 16));
    dir = 1.0;
  }
  return *((float *)&dir + 1);
}


// ========================================================================
// ?GetPathDistance@idNavSplinePathMgr@@QAAMVidNavSplinePosition@@0VidVec3@@_N@Z
// EA  : 0x82CC0120
// RVA : 0x00CC0120
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idNavSplinePathMgr::GetPathDistance(
        idNavSplinePathMgr *this,
        __int64 end,
        idNavSplinePosition *forward,
        __int64 includeRightDistance,
        unsigned int a5,
        char a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  navSplinePath_t *ShortestPath; // r3
  navSplinePath_t *v17; // r30
  double distance; // fp28
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  char v22; // r11
  idVec3 *v23; // r3
  double v24; // fp1
  idNavSplinePosition v26[4]; // [sp+50h] [-50h] BYREF

  a10 = *(__int64 *)((char *)&end + 4);
  a13 = *(__int64 *)((char *)&includeRightDistance + 4);
  a11 = end;
  HIDWORD(includeRightDistance) = HIDWORD(end);
  a14 = includeRightDistance;
  a15 = a5;
  ShortestPath = idNavSplinePathMgr::GetShortestPath(
                   this,
                   start: (idNavSpline *)HIDWORD(end),
                   end: (idNavSplinePosition *)__ROL4__(HIDWORD(end), 32),
                   path: forward,
                   a5: __ROL4__(forward, 32),
                   a6: nullptr);
  v17 = ShortestPath;
  if ( ShortestPath != nullptr && ShortestPath->path.num >= 1 )
  {
    distance = ShortestPath->distance;
    if ( a6 != 0 )
      distance = (float)((float)__fabs(ShortestPath->rightDelta) + ShortestPath->distance);
    v19 = *(float *)&a14;
    v20 = *(float *)&a15;
    v21 = *((float *)&a14 + 1);
    if ( *(float *)&a14 != vec3_origin.x || v21 != vec3_origin.y || (v22 = 1, v20 != vec3_origin.z) )
      v22 = 0;
    if ( v22 == 0 )
    {
      v23 = idNavSplinePosition::GetForward(this: v26, result: (idVec3 *)&a10);
      if ( (float)((float)((float)(v23->x * (float)v19)
                         + (float)((float)(v23->y * (float)v21) + (float)(v23->z * (float)v20)))
                 * v17->path.list->dir) < 0.0 )
        distance = -distance;
    }
    v24 = distance;
  }
  else
  {
    v24 = 0.0;
  }
  return *((float *)&v24 + 1);
}


// ========================================================================
// ?GetWorldPosAlongPath@idNavSplinePathMgr@@QAA?AVidVec3@@PBUnavSplinePath_t@@M@Z
// EA  : 0x82CC0268
// RVA : 0x00CC0268
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePathMgr *__fastcall idNavSplinePathMgr::GetWorldPosAlongPath(
        idNavSplinePathMgr *this,
        idVec3 *result,
        const navSplinePath_t *splinePath,
        double distance)
{
  double startDistance; // fp0
  double endDistance; // fp13
  double v7; // fp12
  double rightDelta; // fp11
  navSplinePath_t v11; // [sp+50h] [-40h] BYREF

  startDistance = splinePath->startDistance;
  endDistance = splinePath->endDistance;
  v7 = splinePath->distance;
  v11.path.list = nullptr;
  rightDelta = splinePath->rightDelta;
  v11.path.listStatic = 0;
  v11.startDistance = startDistance;
  v11.endDistance = endDistance;
  v11.distance = v7;
  v11.rightDelta = rightDelta;
  idList<navSplinePath_t::path_t,5>::operator=(this: &v11.path, other: &splinePath->path);
  navSplinePath_t::Step(this: &v11, stepdist: distance);
  idNavSpline::GetWorldPos((idNavSpline *)this, result: (idVec3 *)v11.path.list->navSpline, distance: v11.startDistance);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v11.path);
  return this;
}


// ========================================================================
// __unwind$497350_0
// EA  : 0x82CC030C
// RVA : 0x00CC030C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497350_0()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 144 + 80));
}


// ========================================================================
// ?CreateTracker@idNavSplinePathMgr@@QAAPAVidNavPathPosTracker@@PBVidEntity@@@Z
// EA  : 0x82CC0338
// RVA : 0x00CC0338
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idNavSplinePathMgr::CreateTracker(idNavSplinePathMgr *this, const idEntity *owner)
{
  __int16 v5; // r11
  int num; // r10
  unsigned __int16 v7; // r9
  int v8; // r10
  char *v9; // r11
  const idEntity *v10; // r5
  char *v11; // r30
  int v12; // r28
  int v13; // r29
  idIndex<short,enum invalidUserChannelIndex_t> v14; // [sp+50h] [-30h] BYREF
  int v15; // [sp+54h] [-2Ch] BYREF

  if ( idNavSplinePathMgr::GetNavSplineList(this)->num < 1 )
    return nullptr;
  if ( this->trackerPool.freeTrackers.num != 0 )
  {
    num = this->trackerPool.freeTrackers.num;
    v7 = *this->trackerPool.freeTrackers.list;
    if ( num > 0 )
    {
      v8 = num - 1;
      this->trackerPool.freeTrackers.num = v8;
      if ( v8 != 0 )
        *this->trackerPool.freeTrackers.list = this->trackerPool.freeTrackers.list[v8];
    }
    v5 = v7;
  }
  else
  {
    v5 = -1;
  }
  v14.value = v5;
  if ( v5 == -1 )
    return nullptr;
  v9 = (char *)this + 312 * v5;
  v10 = owner;
  v11 = v9 + 140;
  *((_DWORD *)v9 + 112) = this->navSplineType;
  idGameLocal::GetSpawnId(this: (idGameLocal *)&v15, result: (idSpawnId *)gameLocal, ent: v10);
  v12 = v15;
  v13 = this->usedTrackers.num;
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
    this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->usedTrackers,
    obj: &v14);
  idHashIndex::Add(this: &this->trackerHash, key: v12, index: v13);
  return (idNavPathPosTracker *)v11;
}


// ========================================================================
// ?NormalizeRightDistance@idNavSplinePathMgr@@QAAMVidNavSplinePosition@@0PAUnavSplinePath_t@@@Z
// EA  : 0x82CC0450
// RVA : 0x00CC0450
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

float __fastcall idNavSplinePathMgr::NormalizeRightDistance(
        idNavSplinePathMgr *this,
        idNavSpline *start,
        idNavSplinePosition *end,
        idNavSplinePosition *path,
        int a5,
        navSplinePath_t *a6)
{
  double v10; // fp31
  double v11; // fp1
  navSplinePath_t v13; // [sp+50h] [-60h] BYREF

  navSplinePath_t::navSplinePath_t(this: &v13);
  if ( a6 == nullptr )
  {
    idNavSplinePathMgr::GetShortestPath(
      this,
      start,
      end: (idNavSplinePosition *)__ROL4__(start, 32),
      path,
      a5: __ROL4__(path, 32),
      a6: &v13);
    a6 = &v13;
  }
  v10 = (float)(*(float *)&start * idNavSplinePathMgr::GetFacingDir(this, splinePath: a6, maxLength: 1.0e30));
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13.path);
  v11 = v10;
  return *((float *)&v11 + 1);
}


// ========================================================================
// __unwind$497471
// EA  : 0x82CC04EC
// RVA : 0x00CC04EC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497471()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 176 + 80));
}


// ========================================================================
// ??0idNavPathPosTrackerPool@@QAA@XZ
// EA  : 0x82CC0780
// RVA : 0x00CC0780
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavPathPosTrackerPool *__fastcall idNavPathPosTrackerPool::idNavPathPosTrackerPool(idNavPathPosTrackerPool *this)
{
  `eh vector constructor iterator'(
    ptr: this,
    size: 0x138u,
    count: 256,
    pCtor: (void (__fastcall *)(void *))idNavPathPosTracker::idNavPathPosTracker,
    pDtor: (void (__fastcall *)(void *))idNavPathPosTracker::~idNavPathPosTracker);
  this->freeTrackers.size = 256;
  this->freeTrackers.num = 0;
  this->freeTrackers.granularity = 1;
  this->freeTrackers.list = this->freeTrackers.staticList;
  this->freeTrackers.memTag = 5;
  this->freeTrackers.listStatic = 1;
  idNavPathPosTrackerPool::Clear(this);
  return this;
}


// ========================================================================
// __unwind$497760
// EA  : 0x82CC0814
// RVA : 0x00CC0814
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497760()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: *(void **)(v0 - 112 + 132),
    size: 0x138u,
    count: 256,
    pDtor: (void (__fastcall *)(void *))idNavPathPosTracker::~idNavPathPosTracker);
}


// ========================================================================
// __unwind$497761
// EA  : 0x82CC084C
// RVA : 0x00CC084C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497761()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 79872));
}


// ========================================================================
// ?Free@idNavPathPosTrackerPool@@QAAXABV?$idHandle@FW4invalidTrackerHandle_t@@$0?0@@@Z
// EA  : 0x82CC0880
// RVA : 0x00CC0880
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavPathPosTrackerPool::Free(
        idNavPathPosTrackerPool *this,
        const idHandle<short,enum invalidTrackerHandle_t,-1> *handle)
{
  unsigned __int16 value; // r11
  int v3; // r10
  idStaticList<unsigned short,256> *p_freeTrackers; // r3
  int num; // r7
  int v6; // r8
  int v7; // r11
  unsigned __int16 v8[4]; // [sp+50h] [-10h] BYREF

  value = handle->value;
  v3 = 0;
  p_freeTrackers = &this->freeTrackers;
  v8[0] = handle->value;
  num = p_freeTrackers->num;
  if ( num <= 0 )
    goto LABEL_7;
  v6 = value;
  v7 = 0;
  while ( p_freeTrackers->list[v7] != v6 )
  {
    ++v3;
    ++v7;
    if ( v3 >= num )
      goto LABEL_7;
  }
  if ( v3 < 0 )
LABEL_7:
    idList<unsigned short,72>::Append(this: p_freeTrackers, obj: v8);
}


// ========================================================================
// ?GetClosestDistWithinAngle@idNavSplinePathMgr@@QAA?AVidNavSplinePosition@@PAUnavSplinePath_t@@VidVec3@@MMHPAM@Z
// EA  : 0x82CC09C0
// RVA : 0x00CC09C0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePathMgr *__fastcall idNavSplinePathMgr::GetClosestDistWithinAngle(
        idNavSplinePathMgr *this,
        idNavSplinePosition *result,
        __int64 forward,
        double cosangle,
        double step,
        int iterations,
        float *distanceMoved,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        float *a31)
{
  int v31; // r28
  double v32; // fp0
  double v33; // fp13
  const idList<navSplinePath_t::path_t,5> *v34; // r26
  double v35; // fp12
  double v36; // fp11
  float *v38; // r29
  double dir; // fp28
  int num; // r9
  int size; // r8
  double v45; // fp30
  double v46; // fp29
  double v47; // fp31
  int v48; // r10
  int v49; // r9
  navSplinePath_t *StartPathPos; // r3
  int endDistance_low; // r7
  int distance_low; // r6
  double v53; // fp13
  double v54; // fp12
  double v55; // fp11
  __int64 v56; // r11
  navSplinePath_t *v57; // r3
  float endDistance; // r9
  int v59; // r8
  navSplinePath_t v61; // [sp+50h] [-C0h] BYREF
  idNavSplinePosition v62; // [sp+70h] [-A0h] BYREF
  navSplinePath_t v63[2]; // [sp+80h] [-90h] BYREF
  float v65; // [sp+148h] [+38h]

  v31 = 0;
  v32 = *(float *)HIDWORD(forward);
  v33 = *(float *)(HIDWORD(forward) + 4);
  v34 = (const idList<navSplinePath_t::path_t,5> *)(HIDWORD(forward) + 16);
  v35 = *(float *)(HIDWORD(forward) + 8);
  v63[0].path.list = nullptr;
  v36 = *(float *)(HIDWORD(forward) + 12);
  v63[0].path.listStatic = 0;
  v63[0].startDistance = v32;
  v63[0].endDistance = v33;
  v63[0].distance = v35;
  v63[0].rightDelta = v36;
  v38 = (float *)HIDWORD(forward);
  v65 = *((float *)&forward + 1);
  idList<navSplinePath_t::path_t,5>::operator=(
    this: &v63[0].path,
    other: (const idList<navSplinePath_t::path_t,5> *)(HIDWORD(forward) + 16));
  dir = v63[0].path.list->dir;
  navSplinePath_t::Step(this: v63, stepdist: step);
  navSplinePath_t::GetStartPathPos(this: (navSplinePath_t *)&v61.path, result: (idNavSplinePosition *)v63);
  num = v61.path.num;
  size = v61.path.size;
  this->__vftable = (idNavSplinePathMgr_vtbl *)v61.path.list;
  *((_DWORD *)&this->__vftable + 1) = num;
  this->nextRecalcTime = size;
  if ( a9 > 0 )
  {
    v45 = v65;
    v46 = *((float *)&forward + 1);
    v47 = *(float *)&forward;
    do
    {
      if ( v63[0].path.list->dir != dir )
      {
        v45 = -v45;
        v46 = -v46;
        v47 = -v47;
        dir = v63[0].path.list->dir;
      }
      idNavSplinePosition::GetForward(this: &v62, result: (idVec3 *)&v61.path);
      if ( (float)((float)(v62.distance * (float)v47)
                 + (float)((float)(v62.rightDistance * (float)v46) + (float)(*(float *)&v62.navSpline * (float)v45))) < cosangle )
        break;
      v48 = v61.path.num;
      v49 = v61.path.size;
      this->__vftable = (idNavSplinePathMgr_vtbl *)v61.path.list;
      *((_DWORD *)&this->__vftable + 1) = v48;
      this->nextRecalcTime = v49;
      navSplinePath_t::Step(this: v63, stepdist: step);
      StartPathPos = navSplinePath_t::GetStartPathPos(this: &v61, result: (idNavSplinePosition *)v63);
      endDistance_low = LODWORD(StartPathPos->endDistance);
      ++v31;
      distance_low = LODWORD(StartPathPos->distance);
      v61.path.list = (navSplinePath_t::path_t *)LODWORD(StartPathPos->startDistance);
      v61.path.num = endDistance_low;
      v61.path.size = distance_low;
    }
    while ( v31 < a9 );
  }
  if ( v31 == a9 )
  {
    v53 = v38[1];
    v54 = v38[2];
    v55 = v38[3];
    v63[0].startDistance = *v38;
    v63[0].endDistance = v53;
    v63[0].distance = v54;
    v63[0].rightDelta = v55;
    idList<navSplinePath_t::path_t,5>::operator=(this: &v63[0].path, other: v34);
    LODWORD(v56) = a9;
    *(_QWORD *)&v61.startDistance = v56;
    navSplinePath_t::Step(this: v63, stepdist: (float)((float)v56 * (float)step));
    v57 = navSplinePath_t::GetStartPathPos(this: &v61, result: (idNavSplinePosition *)v63);
    endDistance = v57->endDistance;
    v59 = LODWORD(v57->distance);
    this->__vftable = (idNavSplinePathMgr_vtbl *)LODWORD(v57->startDistance);
    *((float *)&this->__vftable + 1) = endDistance;
    this->nextRecalcTime = v59;
  }
  if ( a31 != nullptr )
    *a31 = v38[2] - v63[0].distance;
  if ( (v63[0].path.listStatic == 0 || v63[0].path.listStatic == 2) && v63[0].path.list != nullptr )
    idMem::Free(this: &mem, ptr: v63[0].path.list, align: ALIGN_16);
  return this;
}


// ========================================================================
// __unwind$497881
// EA  : 0x82CC0BF4
// RVA : 0x00CC0BF4
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_497881()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 272 + 128));
}


// ========================================================================
// ?GetFurthestPositionAlongPath@idNavSplinePathMgr@@QAA?AVidNavSplinePosition@@PAUnavSplinePath_t@@MMMHPAM@Z
// EA  : 0x82CC0C28
// RVA : 0x00CC0C28
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePathMgr *__fastcall idNavSplinePathMgr::GetFurthestPositionAlongPath(
        idNavSplinePathMgr *this,
        idNavSplinePosition *result,
        navSplinePath_t *splinePath,
        double rightDistance,
        double adjustWidth,
        double step,
        int iterations,
        float *distanceMoved,
        int a9,
        int a10,
        float *a11)
{
  double startDistance; // fp0
  double endDistance; // fp13
  double rightDelta; // fp12
  double distance; // fp11
  double dir; // fp24
  float v23; // r9
  int distance_low; // r8
  int v25; // r22
  navSplinePath_t *StartPathPos; // r3
  float v27; // r9
  float v28; // r8
  double SplineWidth; // fp1
  double v30; // fp29
  idVec3 *WorldPos; // r3
  double v32; // fp9
  int v33; // r30
  double v34; // fp7
  double v35; // fp5
  double v38; // fp6
  double v39; // fp6
  double v40; // fp10
  double v41; // fp11
  double v42; // fp9
  float *p_y; // r11
  double v44; // fp5
  double v45; // fp6
  double v46; // fp4
  double v47; // fp2
  double v48; // fp5
  float v49; // r10
  int v50; // r9
  idRenderWorld_vtbl *v51; // r28
  idVec3 *SplineWorldPos; // r3
  int v53; // r30
  navSplinePath_t v55; // [sp+50h] [-2A0h] BYREF
  idNavSplinePosition v56; // [sp+70h] [-280h] BYREF
  navSplinePath_t v57; // [sp+80h] [-270h] BYREF
  float v58[2]; // [sp+A0h] [-250h] BYREF
  float v59; // [sp+A8h] [-248h]
  idSphere v60; // [sp+B0h] [-240h] BYREF
  idNavSplinePosition v61; // [sp+C0h] [-230h] BYREF
  navSplinePath_t v62; // [sp+D0h] [-220h] BYREF
  idList<idSphere,81> v63; // [sp+F0h] [-200h] BYREF
  int v64; // [sp+100h] [-1F0h] BYREF

  startDistance = splinePath->startDistance;
  endDistance = splinePath->endDistance;
  rightDelta = splinePath->rightDelta;
  v57.path.list = nullptr;
  distance = splinePath->distance;
  v57.path.listStatic = 0;
  v57.startDistance = startDistance;
  v57.endDistance = endDistance;
  v57.rightDelta = rightDelta;
  v57.distance = distance;
  idList<navSplinePath_t::path_t,5>::operator=(this: &v57.path, other: &splinePath->path);
  dir = v57.path.list->dir;
  navSplinePath_t::GetStartPathPos(this: &v55, result: (idNavSplinePosition *)&v57);
  v23 = v55.startDistance;
  v55.endDistance = rightDistance;
  distance_low = LODWORD(v55.distance);
  *((_DWORD *)&this->__vftable + 1) = LODWORD(v55.endDistance);
  *(float *)&this->__vftable = v23;
  this->nextRecalcTime = distance_low;
  idNavSplinePosition::GetForward(this: (idNavSplinePosition *)&v55.path, result: (idVec3 *)&v55);
  v63.num = 0;
  v63.granularity = 1;
  v63.size = 20;
  v63.list = (idSphere *)&v64;
  v63.memTag = 5;
  v63.listStatic = 1;
  if ( a10 > 20 )
    a10 = 20;
  idNavSplinePosition::GetWorldPos(this: &v56, result: (idVec3 *)&v55);
  v25 = 0;
  if ( a10 > 0 )
  {
    while ( 1 )
    {
      navSplinePath_t::Step(this: &v57, stepdist: step);
      StartPathPos = navSplinePath_t::GetStartPathPos(this: &v62, result: (idNavSplinePosition *)&v57);
      v27 = StartPathPos->endDistance;
      v28 = StartPathPos->distance;
      v55.startDistance = StartPathPos->startDistance;
      v55.endDistance = v27;
      v55.distance = v28;
      SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&v55, dist: -1.0);
      v30 = (float)((float)SplineWidth + (float)adjustWidth);
      if ( v30 < __fabs(rightDistance) )
      {
        if ( rightDistance <= 0.0 )
          rightDistance = -v30;
        else
          rightDistance = (float)((float)SplineWidth + (float)adjustWidth);
      }
      v55.endDistance = rightDistance;
      if ( v57.path.list->dir != dir )
      {
        *(float *)&v55.path.list = -*(float *)&v55.path.list;
        *(float *)&v55.path.size = -*(float *)&v55.path.size;
        *(float *)&v55.path.num = -*(float *)&v55.path.num;
        dir = v57.path.list->dir;
      }
      WorldPos = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&v62.path, result: (idVec3 *)&v55);
      v32 = (float)(WorldPos->y - v56.rightDistance);
      v33 = 0;
      v34 = (float)(WorldPos->x - v56.distance);
      v35 = (float)(WorldPos->z - *(float *)&v56.navSpline);
      _FP1 = (float)((float)((float)((float)(WorldPos->z - *(float *)&v56.navSpline)
                                   * (float)(WorldPos->z - *(float *)&v56.navSpline))
                           + (float)((float)((float)(WorldPos->x - v56.distance) * (float)(WorldPos->x - v56.distance))
                                   + (float)((float)(WorldPos->y - v56.rightDistance)
                                           * (float)(WorldPos->y - v56.rightDistance))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f8, f1, f2, f11 }
      v38 = __frsqrte(_FP8);
      v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                          * (float)((float)((float)((float)v35 * (float)v35) + (float)((float)((float)v34 * (float)v34) + (float)((float)v32 * (float)v32)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v38)
                                                                          - (float)1.5)
                                                          * (float)v38)
                                                  * (float)((float)((float)((float)v35 * (float)v35)
                                                                  + (float)((float)((float)v34 * (float)v34)
                                                                          + (float)((float)v32 * (float)v32)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v38
                                                                                  * (float)((float)((float)((float)v35 * (float)v35)
                                                                                                  + (float)((float)((float)v34 * (float)v34) + (float)((float)v32 * (float)v32)))
                                                                                          * (float)0.5))
                                                                          * (float)v38)
                                                                  - (float)1.5)
                                                  * (float)v38))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v38
                                                          * (float)((float)((float)((float)v35 * (float)v35)
                                                                          + (float)((float)((float)v34 * (float)v34)
                                                                                  + (float)((float)v32 * (float)v32)))
                                                                  * (float)0.5))
                                                  * (float)v38)
                                          - (float)1.5)
                          * (float)v38));
      v40 = (float)((float)v32
                  * (float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)((float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline)
                                                                                  * (float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline))
                                                                          + (float)((float)((float)(WorldPos->x
                                                                                                  - v56.distance)
                                                                                          * (float)(WorldPos->x
                                                                                                  - v56.distance))
                                                                                  + (float)((float)v32 * (float)v32)))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39));
      v41 = (float)((float)(WorldPos->x - v56.distance)
                  * (float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)((float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline)
                                                                                  * (float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline))
                                                                          + (float)((float)((float)(WorldPos->x
                                                                                                  - v56.distance)
                                                                                          * (float)(WorldPos->x
                                                                                                  - v56.distance))
                                                                                  + (float)((float)(WorldPos->y
                                                                                                  - v56.rightDistance)
                                                                                          * (float)(WorldPos->y
                                                                                                  - v56.rightDistance))))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39));
      v42 = (float)((float)(WorldPos->z - *(float *)&v56.navSpline)
                  * (float)((float)-(float)((float)((float)((float)v39
                                                          * (float)((float)((float)((float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline)
                                                                                  * (float)(WorldPos->z
                                                                                          - *(float *)&v56.navSpline))
                                                                          + (float)((float)((float)(WorldPos->x
                                                                                                  - v56.distance)
                                                                                          * (float)(WorldPos->x
                                                                                                  - v56.distance))
                                                                                  + (float)((float)(WorldPos->y
                                                                                                  - v56.rightDistance)
                                                                                          * (float)(WorldPos->y
                                                                                                  - v56.rightDistance))))
                                                                  * (float)0.5))
                                                  * (float)v39)
                                          - (float)1.5)
                          * (float)v39));
      if ( v63.num > 0 )
      {
        p_y = &v63.list->origin.y;
        while ( 1 )
        {
          v44 = (float)((float)v40
                      * (float)((float)((float)(*(p_y - 1) - v56.distance) * (float)v41)
                              + (float)((float)((float)v40 * (float)(*p_y - v56.rightDistance))
                                      + (float)((float)v42 * (float)(p_y[1] - *(float *)&v56.navSpline)))));
          v45 = (float)((float)v42
                      * (float)((float)((float)(*(p_y - 1) - v56.distance) * (float)v41)
                              + (float)((float)((float)v40 * (float)(*p_y - v56.rightDistance))
                                      + (float)((float)v42 * (float)(p_y[1] - *(float *)&v56.navSpline)))));
          v46 = (float)((float)((float)v41
                              * (float)((float)((float)(*(p_y - 1) - v56.distance) * (float)v41)
                                      + (float)((float)((float)v40 * (float)(*p_y - v56.rightDistance))
                                              + (float)((float)v42 * (float)(p_y[1] - *(float *)&v56.navSpline)))))
                      + v56.distance);
          v47 = (float)(v56.rightDistance
                      + (float)((float)v40
                              * (float)((float)((float)(*(p_y - 1) - v56.distance) * (float)v41)
                                      + (float)((float)((float)v40 * (float)(*p_y - v56.rightDistance))
                                              + (float)((float)v42 * (float)(p_y[1] - *(float *)&v56.navSpline))))));
          v58[0] = (float)((float)v41
                         * (float)((float)((float)(*(p_y - 1) - v56.distance) * (float)v41)
                                 + (float)((float)((float)v40 * (float)(*p_y - v56.rightDistance))
                                         + (float)((float)v42 * (float)(p_y[1] - *(float *)&v56.navSpline)))))
                 + v56.distance;
          v58[1] = v56.rightDistance + (float)v44;
          v59 = *(float *)&v56.navSpline + (float)v45;
          v48 = (float)((float)v46 - *(p_y - 1));
          if ( (float)((float)((float)(v59 - p_y[1]) * (float)(v59 - p_y[1]))
                     + (float)((float)((float)v48 * (float)v48)
                             + (float)((float)((float)v47 - *p_y) * (float)((float)v47 - *p_y)))) > (double)p_y[2] )
            break;
          ++v33;
          p_y += 4;
          if ( v33 >= v63.num )
            goto LABEL_16;
        }
        if ( v33 < v63.num )
          break;
      }
LABEL_16:
      v49 = v55.endDistance;
      v50 = LODWORD(v55.distance);
      this->__vftable = (idNavSplinePathMgr_vtbl *)LODWORD(v55.startDistance);
      *((float *)&this->__vftable + 1) = v49;
      this->nextRecalcTime = v50;
      v60.origin = *idNavSplinePosition::GetSplineWorldPos(this: &v61, result: (idVec3 *)&v55);
      v60.radius = (float)v30 * (float)v30;
      idList<idSphere,5>::Append(this: &v63, obj: &v60);
      if ( spl_showFurthestPositionSamples.valueInteger != 0 )
        clientGame->renderWorld->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: (const idVec3 *)&v60,
          a4: 0,
          a5: false);
      if ( ++v25 >= a10 )
        goto LABEL_22;
    }
    if ( spl_showFurthestPositionSamples.valueInteger != 0 )
    {
      v51 = clientGame->renderWorld->__vftable;
      SplineWorldPos = idNavSplinePosition::GetSplineWorldPos(this: &v61, result: (idVec3 *)&v55);
      v51->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorMagenta,
        a3: (const idVec3 *)&v56,
        a4: SplineWorldPos,
        a5: 0,
        a6: false);
      v53 = v33;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v56,
        a4: (const idVec3 *)&v63.list[v53],
        a5: 0,
        a6: false);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v63.list[v53],
        a4: (const idVec3 *)v58,
        a5: 0,
        a6: false);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idVec3 *)v58,
        a4: 0,
        a5: false);
    }
  }
LABEL_22:
  if ( a11 != nullptr )
    *a11 = splinePath->distance - v57.distance;
  if ( v63.listStatic == 0 || v63.listStatic == 2 )
  {
    if ( v63.list != nullptr )
      idMem::Free(this: &mem, ptr: v63.list, align: ALIGN_16);
    v63.list = nullptr;
    v63.size = 0;
  }
  v63.num = 0;
  if ( (v57.path.listStatic == 0 || v57.path.listStatic == 2) && v57.path.list != nullptr )
    idMem::Free(this: &mem, ptr: v57.path.list, align: ALIGN_16);
  return this;
}


// ========================================================================
// __unwind$498012
// EA  : 0x82CC113C
// RVA : 0x00CC113C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_498012()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 752 + 128));
}


// ========================================================================
// __unwind$498013_0
// EA  : 0x82CC1164
// RVA : 0x00CC1164
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_498013_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 240));
}


// ========================================================================
// ?ReleaseTracker@idNavSplinePathMgr@@QAAXPAVidNavPathPosTracker@@@Z
// EA  : 0x82CC1190
// RVA : 0x00CC1190
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::ReleaseTracker(idNavSplinePathMgr *this, idNavPathPosTracker *tracker)
{
  idEntity *Owner; // r3
  int value; // r31
  int TrackerIndex; // r3
  int num; // r10
  int v8; // r10
  idSpawnId v9[2]; // [sp+50h] [-20h] BYREF

  if ( tracker != nullptr )
  {
    Owner = idNavPathPosTracker::GetOwner(this: tracker);
    idNavPathPosTracker::RemoveFromEntityList(this: tracker, entity: Owner);
    value = tracker->owner.spawnId.value;
    v9[0].value = value;
    TrackerIndex = idNavSplinePathMgr::GetTrackerIndex(this, ownerSpawnId: v9);
    if ( TrackerIndex >= 0 )
    {
      num = this->usedTrackers.num;
      HIWORD(v9[0].value) = this->usedTrackers.list[TrackerIndex].value;
      if ( TrackerIndex < num )
      {
        v8 = num - 1;
        this->usedTrackers.num = v8;
        if ( TrackerIndex != v8 )
          this->usedTrackers.list[TrackerIndex].value = this->usedTrackers.list[v8].value;
      }
      idHashIndex::RemoveIndexFast(this: &this->trackerHash, key: value, index: TrackerIndex);
      idNavPathPosTrackerPool::Free(
        this: &this->trackerPool,
        handle: (const idHandle<short,enum invalidTrackerHandle_t,-1> *)v9);
    }
  }
}


// ========================================================================
// ?ConnectSplineFromLinks@idNavSplinePathMgr@@QAAXPAUnavSplineLink_t@@0@Z
// EA  : 0x82CC1578
// RVA : 0x00CC1578
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::ConnectSplineFromLinks(
        idNavSplinePathMgr *this,
        navSplineLink_t *link1,
        navSplineLink_t *link2)
{
  idNavSpline *navSpline; // r9
  idNavSpline *v5; // r6
  navSplinePathNode_t *endNode; // r11
  navSplinePathNode_t *startNode; // r8
  navSplinePathNode_t *v8; // r10
  navSplinePathNode_t *v9; // r11
  int v10; // r7
  int v11; // r10
  int v12; // r11
  navSplineConnection_t *v13; // r3
  idVec3 *v14; // r4
  float *v15; // r31
  float *v16; // r3
  int num; // r7
  int v18; // r10
  int v19; // r11
  idList<navSplineConnection_t,5> *p_next; // r31
  int v21; // r11
  int size; // r10
  int v23; // r30
  idVec3 *v24; // r4
  float *Forward; // r3
  _BYTE v26[48]; // [sp+50h] [-30h] BYREF

  if ( link1 != link2 )
  {
    navSpline = link1->navSpline;
    v5 = link2->navSpline;
    endNode = navSpline->endNode;
    startNode = v5->startNode;
    if ( endNode == startNode || (v8 = v5->endNode, endNode == v8) )
    {
      num = navSpline->next.num;
      v18 = 0;
      if ( num <= 0 )
      {
LABEL_15:
        p_next = &navSpline->next;
        idList<navSplineConnection_t,5>::PreAllocateWithGranularity(
          this: &navSpline->next,
          newSize: navSpline->next.num + 1);
        v21 = p_next->num;
        size = p_next->size;
        if ( v21 >= size )
        {
          v23 = (int)&p_next->list[size - 1];
        }
        else
        {
          v23 = (int)&p_next->list[v21];
          p_next->num = v21 + 1;
        }
        v24 = (idVec3 *)link2->navSpline;
        *(_DWORD *)v23 = v24;
        Forward = (float *)idNavSpline::GetForward(this: (idNavSpline *)v26, result: v24, distance: 100.0);
        *(float *)(v23 + 4) = *Forward;
        *(float *)(v23 + 8) = Forward[1];
        *(float *)(v23 + 12) = Forward[2];
      }
      else
      {
        v19 = 0;
        while ( navSpline->next.list[v19].navSpline != v5 )
        {
          ++v18;
          ++v19;
          if ( v18 >= num )
            goto LABEL_15;
        }
      }
    }
    else
    {
      v9 = navSpline->startNode;
      if ( v9 == v8 || v9 == startNode )
      {
        v10 = navSpline->prev.num;
        v11 = 0;
        if ( v10 <= 0 )
        {
LABEL_10:
          v13 = idList<navSplineConnection_t,5>::Alloc(this: &navSpline->prev);
          v14 = (idVec3 *)link2->navSpline;
          v15 = (float *)v13;
          v13->navSpline = (idNavSpline *)v14;
          v16 = (float *)idNavSpline::GetForward(
                           this: (idNavSpline *)v26,
                           result: v14,
                           distance: (float)(v14[1].x - (float)100.0));
          v15[1] = *v16;
          v15[2] = v16[1];
          v15[3] = v16[2];
        }
        else
        {
          v12 = 0;
          while ( navSpline->prev.list[v12].navSpline != v5 )
          {
            ++v11;
            ++v12;
            if ( v11 >= v10 )
              goto LABEL_10;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?FindTracker@idNavSplinePathMgr@@QAAPAVidNavPathPosTracker@@ABVidSpawnId@@_N@Z
// EA  : 0x82CC1708
// RVA : 0x00CC1708
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idNavSplinePathMgr::FindTracker(
        idNavSplinePathMgr *this,
        const idSpawnId *ownerSpawnId,
        bool createTrackerIfNotFound)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int TrackerIndex; // r3
  idNavPathPosTracker *v10; // r30
  idEntity *v11; // r3
  idEntity *v12; // r24
  const idEntity *BindMaster; // r3
  int v14; // r28
  int v15; // r29
  idStaticList<idHandle<short,enum invalidTrackerHandle_t,-1>,256> *p_usedTrackers; // r27
  char *v17; // r8
  _DWORD *v18; // r11
  idEntity *v19; // r3
  idNavPathPosTracker *Tracker; // r3
  int v21; // [sp+50h] [-70h] BYREF
  idPLogScope v22[13]; // [sp+58h] [-68h] BYREF

  RD_EventBegin(name: "idNavSplinePathMgr::FindTracker");
  LODWORD(v6) = "idNavSplinePathMgr::FindTracker";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v22, pl: &pLog, gMask: v6, label: v7);
  if ( idNavSplinePathMgr::GetNavSplineList(this)->num == 0 )
    goto LABEL_2;
  TrackerIndex = idNavSplinePathMgr::GetTrackerIndex(this, ownerSpawnId);
  if ( TrackerIndex < 0 )
  {
    v11 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: ownerSpawnId->value);
    v12 = v11;
    if ( v11 == nullptr )
    {
      idPLogScope::~idPLogScope(this: v22);
      RD_EventEnd();
      return nullptr;
    }
    BindMaster = idEntity::GetBindMaster(this: v11);
    idGameLocal::GetSpawnId(this: (idGameLocal *)&v21, result: (idSpawnId *)gameLocal, ent: BindMaster);
    v14 = 0;
    if ( this->usedTrackers.num <= 0 )
      goto LABEL_15;
    v15 = 0;
    p_usedTrackers = &this->usedTrackers;
    while ( 1 )
    {
      v17 = (char *)this + 312 * p_usedTrackers->list[v15].value;
      v18 = v17 + 140;
      if ( v17 != (char *)-140 && *v18 != 0x1FFF )
      {
        if ( *v18 == v21 )
          break;
        v19 = (idEntity *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId)(a1: gameLocal);
        if ( v19 != nullptr && idEntity::GetBindMaster(this: v19) == v12 )
          break;
      }
      ++v14;
      ++v15;
      if ( v14 >= this->usedTrackers.num )
        goto LABEL_15;
    }
    if ( v14 <= -1 )
    {
LABEL_15:
      if ( !createTrackerIfNotFound )
      {
LABEL_2:
        idPLogScope::~idPLogScope(this: v22);
        RD_EventEnd();
        return nullptr;
      }
      Tracker = idNavSplinePathMgr::CreateTracker(this, owner: v12);
      v10 = Tracker;
      if ( Tracker != nullptr )
        idNavPathPosTracker::Init(this: Tracker, pathName: nullptr, owner: v12);
      idPLogScope::~idPLogScope(this: v22);
    }
    else
    {
      v10 = &this->trackerPool.trackers[p_usedTrackers->list[v14].value];
      idPLogScope::~idPLogScope(this: v22);
    }
  }
  else
  {
    v10 = &this->trackerPool.trackers[this->usedTrackers.list[TrackerIndex].value];
    idPLogScope::~idPLogScope(this: v22);
  }
  RD_EventEnd();
  return v10;
}


// ========================================================================
// __unwind$498654
// EA  : 0x82CC192C
// RVA : 0x00CC192C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_498654()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$498655
// EA  : 0x82CC1954
// RVA : 0x00CC1954
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_498655()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?SetupLinks@idNavSplinePathMgr@@QAAXXZ
// EA  : 0x82CC1B20
// RVA : 0x00CC1B20
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::SetupLinks(idNavSplinePathMgr *this)
{
  idStaticList<navSplinePathNode_t,180> *NodeList; // r23
  int v3; // r20
  int v4; // r25
  navSplinePathNode_t *list; // r9
  int v6; // r21
  int v7; // r22
  navSplinePathNode_t *v8; // r10
  int v9; // r27
  int num; // r11
  navSplineLink_t *v11; // r28
  int v12; // r26
  navSplineLink_t *v13; // r11
  navSplineLink_t *v14; // r29
  navSplinePathNode_t *node; // r11
  int v16; // r30
  int v17; // r31
  navSplineLink_t *v18; // r5

  NodeList = idNavSplineGraph::GetNodeList(this: &this->splineGraph);
  v3 = 0;
  if ( NodeList->num > 0 )
  {
    v4 = 0;
    do
    {
      list = NodeList->list;
      v6 = 0;
      if ( NodeList->list[v4].links.num > 0 )
      {
        v7 = 0;
        do
        {
          v8 = &list[v4];
          v9 = 0;
          num = list[v4].links.num;
          v11 = &list[v4].links.list[v7];
          if ( num > 0 )
          {
            v12 = 0;
            do
            {
              v13 = v8->links.list;
              v14 = &v13[v12];
              if ( v11->navSpline == v13[v12].navSpline )
              {
                node = v14->node;
                v16 = 0;
                if ( v14->node->links.num > 0 )
                {
                  v17 = 0;
                  do
                  {
                    v18 = &node->links.list[v17];
                    if ( v11->navSpline != v18->navSpline )
                      idNavSplinePathMgr::ConnectSplineFromLinks(this, link1: v11, link2: v18);
                    node = v14->node;
                    ++v16;
                    ++v17;
                  }
                  while ( v16 < v14->node->links.num );
                }
              }
              else
              {
                idNavSplinePathMgr::ConnectSplineFromLinks(this, link1: v11, link2: &v13[v12]);
              }
              list = NodeList->list;
              ++v9;
              ++v12;
              v8 = &NodeList->list[v4];
              num = v8->links.num;
            }
            while ( v9 < num );
          }
          ++v6;
          ++v7;
        }
        while ( v6 < num );
      }
      ++v3;
      ++v4;
    }
    while ( v3 < NodeList->num );
  }
}


// ========================================================================
// ?FindTracker@idNavSplinePathMgr@@QAAPAVidNavPathPosTracker@@PAVidEntity@@_N@Z
// EA  : 0x82CC1C58
// RVA : 0x00CC1C58
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idNavSplinePathMgr::FindTracker(
        idNavSplinePathMgr *this,
        idEntity *owner,
        bool createTrackerIfNotFound)
{
  idSpawnId v6[2]; // [sp+50h] [-20h] BYREF

  if ( owner == nullptr )
    return nullptr;
  idGameLocal::GetSpawnId(this: (idGameLocal *)v6, result: (idSpawnId *)gameLocal, ent: owner);
  return idNavSplinePathMgr::FindTracker(this, ownerSpawnId: v6, createTrackerIfNotFound);
}


// ========================================================================
// ?GetTracker@idNavSplinePathMgr@@QAAPAVidNavPathPosTracker@@PAVidEntity@@@Z
// EA  : 0x82CC1CC0
// RVA : 0x00CC1CC0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idNavSplinePathMgr::GetTracker(idNavSplinePathMgr *this, idEntity *owner)
{
  idSpawnId v4[4]; // [sp+50h] [-20h] BYREF

  if ( owner == nullptr )
    return nullptr;
  idGameLocal::GetSpawnId(this: (idGameLocal *)v4, result: (idSpawnId *)gameLocal, ent: owner);
  return idNavSplinePathMgr::FindTracker(this, ownerSpawnId: v4, createTrackerIfNotFound: true);
}


// ========================================================================
// ?GetNavSpline@idNavSplinePathMgr@@QAAPAVidNavSpline@@PBD@Z
// EA  : 0x82CC1E20
// RVA : 0x00CC1E20
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSpline *__fastcall idNavSplinePathMgr::GetNavSpline(idNavSplinePathMgr *this, const char *splineName)
{
  idNavSpline *p_tempNavSpline; // r23
  int v5; // r11
  int v6; // r29
  bool v7; // r31
  BOOL v8; // r28
  int v9; // r30
  idNavSplinePath *splinePath; // r10
  const char *data; // r31
  bool v12; // cr58
  idNavSplinePath *v13; // r30
  int v14; // r27
  int v15; // r29
  idEntity *v16; // r31
  idEntity *v17; // r3
  char *v18; // r11
  const char *v19; // r10
  int v20; // r9
  int v21; // r9
  bool v22; // zf
  const char *v24; // r11
  const char *v25; // r10
  int v26; // r9
  int v27; // r9
  int value; // r9
  idNavSplinePath *v29; // r3
  int v30; // r9
  idNavSplinePath *v31; // r3
  idNavSplinePath *v32; // r3
  idNavSplinePath *v33; // r29
  bool v34; // r11
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  idStaticList<idNavSpline,200> *v36; // r3
  idCurve_Spline<idVec3> *v37; // r3
  idCurve<idVec3> *v38; // r30
  int v39; // r4
  double v40; // fp31
  int v41; // r31
  idCurve_Spline<idVec3> *curve; // r3

  p_tempNavSpline = nullptr;
  v5 = 0;
  if ( *splineName != 0 )
  {
    do
      ++v5;
    while ( splineName[v5] != 0 );
  }
  v6 = 0;
  v7 = splineName[v5 - 1] != 95;
  if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
  {
    v8 = v7;
    v9 = 0;
    do
    {
      splinePath = idNavSplinePathMgr::GetNavSplineList(this)->list[v9].splinePath;
      if ( v8 )
      {
        v12 = idStr::Icmp(s1: splineName, s2: splinePath->name.data) == 0;
      }
      else
      {
        data = splinePath->name.data;
        v12 = strstr(str1: data, str2: splineName) == data;
      }
      if ( v12 )
        return &idNavSplinePathMgr::GetNavSplineList(this)->list[v6];
      ++v6;
      ++v9;
    }
    while ( v6 < idNavSplinePathMgr::GetNavSplineList(this)->num );
  }
  v13 = nullptr;
  if ( (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0 )
  {
    v14 = 0;
    if ( idClientGame::GetObjectListSize(this: clientGame) > 0 )
    {
      v15 = 0;
      do
      {
        v16 = (idEntity *)idClientGame::GetObjectList(this: clientGame)[v15];
        if ( (unsigned __int8)idEntity::IsTypeOf(c: v16) != 0 )
        {
          v17 = idEntity::CastTo(c: v16);
          v18 = v17->name.data;
          v13 = (idNavSplinePath *)v17;
          v19 = splineName;
          do
          {
            v20 = (unsigned __int8)*v18;
            v22 = v20 == 0;
            v21 = v20 - *(unsigned __int8 *)v19;
            if ( v22 )
              break;
            ++v18;
            ++v19;
          }
          while ( v21 == 0 );
          if ( v21 == 0 )
            break;
          v13 = nullptr;
        }
        ++v14;
        ++v15;
      }
      while ( v14 < idClientGame::GetObjectListSize(this: clientGame) );
    }
  }
  else
  {
    v13 = (idNavSplinePath *)gameLocal->FindEntity(this: gameLocal, a2: splineName);
  }
  if ( (unsigned __int8)idNavSplinePath::IsTypeOf(c: v13) == 0 )
  {
    v24 = splineName;
    v25 = "temp";
    do
    {
      v26 = *(unsigned __int8 *)v24;
      v22 = v26 == 0;
      v27 = v26 - *(unsigned __int8 *)v25;
      if ( v22 )
        break;
      ++v24;
      ++v25;
    }
    while ( v27 == 0 );
    if ( v27 != 0 )
      return nullptr;
    value = this->tempNavSplinePath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v29 = (idNavSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v13 = idNavSplinePath::CastTo(c: v29);
    }
    else
    {
      v13 = nullptr;
    }
    idEntity::SetName(this: v13, newName: this->tempNavSplinePathName.data);
    p_tempNavSpline = &this->tempNavSpline;
    this->tempNavSpline.isTempSpline = true;
  }
  if ( v13->entityDef == nullptr )
  {
    v30 = this->tempNavSplinePath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
      && (v31 = (idNavSplinePath *)gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
    {
      v32 = idNavSplinePath::CastTo(c: v31);
    }
    else
    {
      v32 = nullptr;
    }
    if ( v13 != v32 )
      return nullptr;
  }
  v33 = idNavSplinePath::CastTo(c: v13);
  if ( v33 != nullptr )
  {
    if ( p_tempNavSpline == nullptr )
    {
      if ( com_production.valueInteger != 0
        || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
        || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
        || spl_useBuildGameList.valueInteger != 0 )
      {
        v34 = warningIssued;
        if ( !warningIssued )
        {
          NavSplineList = idNavSplinePathMgr::GetNavSplineList(this);
          if ( (((NavSplineList->num >= 0) + (NavSplineList->num >= 0x1F4u)) & 1) != 0 )
          {
            v34 = warningIssued;
          }
          else
          {
            v34 = true;
            warningIssued = true;
          }
        }
        if ( v34 )
          return &this->tempNavSpline;
      }
      v36 = idNavSplinePathMgr::GetNavSplineList(this);
      p_tempNavSpline = idList<idNavSpline,5>::Alloc(this: v36);
    }
    v37 = idSplinePath::AllocSpline(this: v33);
    v38 = v37;
    if ( v37 != nullptr )
    {
      v39 = 0;
      v40 = 0.0;
      if ( v37->values.num - 1 > 0 )
      {
        do
        {
          v41 = v39 + 1;
          v40 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this: v38, i0: v39, i1: v39 + 1) + (float)v40);
          v39 = v41;
        }
        while ( v41 < v38->values.num - 1 );
      }
      idCurve<idVec3>::SetConstantSpeed(this: v38, totalTime: v40);
      p_tempNavSpline->length = v40;
      p_tempNavSpline->width = 300.0;
    }
    curve = p_tempNavSpline->curve;
    if ( curve != nullptr )
    {
      ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))curve->dtr_idCurve<idVec3>)(a1: curve, a2: 1);
      p_tempNavSpline->curve = nullptr;
    }
    p_tempNavSpline->splinePath = v33;
    p_tempNavSpline->curve = (idCurve_Spline<idVec3> *)v38;
  }
  if ( p_tempNavSpline != nullptr )
    idNavSpline::CalcBounds(this: p_tempNavSpline);
  return p_tempNavSpline;
}


// ========================================================================
// ?GetSplinesWithinDistance@idNavSplinePathMgr@@QAAAAV?$idList@UnavSplineSegment_t@@$04@@VidNavSplinePosition@@M@Z
// EA  : 0x82CC22E0
// RVA : 0x00CC22E0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idList<navSplineSegment_t,5> *__fastcall idNavSplinePathMgr::GetSplinesWithinDistance(
        idNavSplinePathMgr *this,
        idNavSpline *pathPos,
        double distance)
{
  idNavSplinePathMgr *v4; // r3
  idNavSplinePathMgr *v5; // r25
  __int64 v6; // r3
  idNavSpline *v7; // r27
  int v8; // r10
  cachedSegList_t *v9; // r8
  int v10; // r11
  float *p_distance; // r30
  int *p_num; // r23
  idList<cachedSegList_t,5> *p_segListTable; // r28
  int v14; // r11
  int v15; // r15
  idList<aas2Edge_t,37> *v16; // r20
  int v17; // r11
  int v18; // r18
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  int num; // r29
  navSplineTrav_t *list; // r24
  int v22; // r10
  int v23; // r11
  double v24; // fp13
  float *p_traversalDist; // r9
  int v26; // ctr
  int v27; // r8
  navSplineTrav_t *v28; // r11
  float v29; // r28
  double traversalDist; // fp30
  float rightDistance; // r26
  int navSpline; // r27
  int dir; // r23
  int *p_dir; // r9
  int v35; // ctr
  int *v36; // r11
  int v37; // r30
  double v38; // fp31
  double v39; // fp0
  double v41; // fp30
  int v42; // r26
  int v43; // r28
  idNavSpline *NextSplines; // r3
  idNavSpline *v45; // r30
  int v46; // r29
  int v47; // r6
  int v48; // r5
  int v49; // r7
  int v50; // r9
  int *v51; // r10
  aas2Edge_t *v52; // r11
  double v53; // fp0
  double v54; // fp12
  double v55; // fp13
  aas2Edge_t *v56; // r10
  int *v57; // r11
  int v58; // r11
  int v59; // r11
  _DWORD *v60; // r8
  aas2Edge_t *v61; // r4
  int v62; // r11
  int v63; // r3
  __int64 v64; // r11
  int p_segList; // r30
  int v66; // [sp+60h] [-110h]
  aas2Edge_t v67; // [sp+68h] [-108h] BYREF
  int distance_low; // [sp+78h] [-F8h]
  idList<navSplineTrav_t,5> v69; // [sp+90h] [-E0h] BYREF
  navSplineTrav_t v70; // [sp+A0h] [-D0h] BYREF
  __int64 v71; // [sp+190h] [+20h]

  v71 = *(_QWORD *)&pathPos;
  v5 = v4;
  vaiTimer.findEnemy_spliWithinDist.state = TS_STARTED;
  LODWORD(v6) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.findEnemy_spliWithinDist.start = v6;
  v7 = pathPos;
  if ( !v5->isStaticPathPos || (v8 = 0, (v66 = v5->segListTable.num) <= 0) )
  {
LABEL_7:
    memset(Dst: v5->floodBits, Val: 0, Size: v5->floodBitSize);
    p_num = &v5->segListTable.num;
    p_segListTable = &v5->segListTable;
    v14 = (int)&v5->segListTable.list[v5->segListTable.num];
    v15 = v14 - 32;
    v16 = (idList<aas2Edge_t,37> *)(v14 - 32 + 16);
    v17 = *(unsigned __int8 *)(v14 - 1);
    if ( v17 == 0 || v17 == 2 )
    {
      if ( v16->list != nullptr )
        idMem::Free(this: &mem, ptr: v16->list, align: ALIGN_16);
      v16->list = nullptr;
      v16->size = 0;
    }
    *(_DWORD *)&v69.granularity = 1280;
    v16->num = 0;
    memset(&v69, 0, 12);
    v18 = 0;
    while ( 1 )
    {
      v70.traversalDist = distance;
      *(_QWORD *)&v70.pathPos.distance = v71;
      v70.pathPos.navSpline = v7;
      v70.dir = v18 == 0 ? 1 : -1;
      idList<navSplineTrav_t,5>::Append(this: &v69, obj: &v70);
      NavSplineList = idNavSplinePathMgr::GetNavSplineList(this: v5);
      list = v69.list;
      num = v69.num;
      v5->floodBits[v7 - NavSplineList->list] = (idNavSplinePathMgr::navSplineFloodBits_t)(*(_DWORD *)&v5->floodBits[v7 - NavSplineList->list]
                                                                                         & 0x9FFFFFFF
                                                                                         | ((*(_DWORD *)&v5->floodBits[v7 - NavSplineList->list]
                                                                                           & 0xE0000000)
                                                                                          + 0x20000000)
                                                                                         & 0x60000000);
      if ( num != 0 )
      {
        do
        {
          v22 = 0;
          v23 = 1;
          v24 = (float)(list->traversalDist - list->pathPos.navSpline->length);
          if ( num > 1 )
          {
            p_traversalDist = &list[1].traversalDist;
            v26 = num - 1;
            do
            {
              v27 = *((_DWORD *)p_traversalDist - 1);
              if ( (float)(*p_traversalDist - *(float *)(v27 + 12)) > v24 )
              {
                v22 = v23;
                v24 = (float)(*p_traversalDist - *(float *)(v27 + 12));
              }
              ++v23;
              p_traversalDist += 5;
              --v26;
            }
            while ( v26 != 0 );
          }
          v28 = &list[v22];
          v29 = v28->pathPos.distance;
          traversalDist = v28->traversalDist;
          rightDistance = v28->pathPos.rightDistance;
          navSpline = (int)v28->pathPos.navSpline;
          dir = v28->dir;
          distance_low = SLODWORD(v28->pathPos.distance);
          if ( v22 >= 0 && v22 < num )
          {
            v69.num = --num;
            if ( v22 != num )
            {
              p_dir = &v28[-1].dir;
              v35 = 5;
              v36 = &list[num - 1].dir;
              do
              {
                *++p_dir = *++v36;
                --v35;
              }
              while ( v35 != 0 );
            }
          }
          v37 = (signed int)(navSpline - (unsigned int)idNavSplinePathMgr::GetNavSplineList(this: v5)->list) / 112;
          v5->floodBits[v37] = (idNavSplinePathMgr::navSplineFloodBits_t)(*(_DWORD *)&v5->floodBits[v37] & 0x9FFFFFFF
                                                                        | ((*(_DWORD *)&v5->floodBits[v37] & 0xE0000000)
                                                                         - 1)
                                                                        & 0x60000000);
          if ( *(_DWORD *)&v5->floodBits[v37] >= 0 )
          {
            v38 = *(float *)&distance_low;
            if ( dir == 1 )
              v39 = (float)(*(float *)(navSpline + 12) - *(float *)&distance_low);
            else
              v39 = *(float *)&distance_low;
            v67.vertexNum[0] = navSpline;
            if ( v39 >= traversalDist )
            {
              if ( dir == 1 )
              {
                v67.vertexNum[1] = distance_low;
                *(float *)&v67.flags = *(float *)&distance_low + (float)traversalDist;
              }
              else
              {
                v67.flags = distance_low;
                *(float *)&v67.vertexNum[1] = *(float *)&distance_low - (float)traversalDist;
              }
              idList<idRenderModelEffects::deferredStage_t,5>::Append(this: v16, obj: &v67);
            }
            else
            {
              v41 = (float)((float)traversalDist - (float)v39);
              if ( dir == 1 )
              {
                v67.flags = *(int *)(navSpline + 12);
                v67.vertexNum[1] = distance_low;
              }
              else
              {
                *(float *)&v67.vertexNum[1] = 0.0;
                v67.flags = distance_low;
              }
              idList<idRenderModelEffects::deferredStage_t,5>::Append(this: v16, obj: &v67);
              if ( v38 == 0.0 || v38 == *(float *)(navSpline + 12) )
                *(_DWORD *)&v5->floodBits[v37] |= 0x80000000;
              v70.traversalDist = v41;
              v70.pathPos.distance = v29;
              v70.pathPos.rightDistance = rightDistance;
              v70.pathPos.navSpline = (idNavSpline *)navSpline;
              if ( dir == 1 )
                v42 = *(_DWORD *)(navSpline + 24);
              else
                v42 = *(_DWORD *)(navSpline + 40);
              v43 = 0;
              if ( v42 > 0 )
              {
                while ( 1 )
                {
                  if ( dir == 1 )
                    NextSplines = idNavSpline::GetNextSplines(this: (idNavSpline *)navSpline, num: v43);
                  else
                    NextSplines = idNavSpline::GetPrevSplines(this: (idNavSpline *)navSpline, num: v43);
                  v45 = NextSplines;
                  v46 = NextSplines - idNavSplinePathMgr::GetNavSplineList(this: v5)->list;
                  if ( *(_DWORD *)&v5->floodBits[v46] < 0 )
                    goto LABEL_51;
                  v70.pathPos.navSpline = v45;
                  if ( dir == 1 )
                  {
                    if ( *(navSplinePathNode_t **)(navSpline + 72) == v45->startNode )
                      goto LABEL_49;
                    v70.pathPos.distance = v45->length;
                    v70.dir = -1;
                  }
                  else
                  {
                    if ( *(navSplinePathNode_t **)(navSpline + 68) != v45->endNode )
                    {
LABEL_49:
                      v70.pathPos.distance = 0.0;
                      v70.dir = 1;
                      goto LABEL_50;
                    }
                    v70.pathPos.distance = v45->length;
                    v70.dir = -1;
                  }
LABEL_50:
                  idList<navSplineTrav_t,5>::Append(this: &v69, obj: &v70);
                  v5->floodBits[v46] = (idNavSplinePathMgr::navSplineFloodBits_t)(*(_DWORD *)&v5->floodBits[v46]
                                                                                & 0x9FFFFFFF
                                                                                | ((*(_DWORD *)&v5->floodBits[v46]
                                                                                  & 0xE0000000)
                                                                                 + 0x20000000)
                                                                                & 0x60000000);
LABEL_51:
                  if ( ++v43 >= v42 )
                  {
                    num = v69.num;
                    list = v69.list;
                    break;
                  }
                }
              }
            }
          }
        }
        while ( num != 0 );
        p_segListTable = &v5->segListTable;
        p_num = &v5->segListTable.num;
        v7 = pathPos;
      }
      if ( ++v18 >= 2 )
      {
        if ( *(int *)(v15 + 20) > 0 )
        {
          v47 = 0;
          v48 = 1;
          do
          {
            v49 = v48;
            if ( v48 < *(_DWORD *)(v15 + 20) )
            {
              v50 = v47 * 12 + 12;
              do
              {
                v51 = (int *)((char *)v16->list->vertexNum + v50);
                v52 = &v16->list[v47];
                if ( v52->vertexNum[0] == *v51 )
                {
                  if ( (v53 = *((float *)v51 + 1), (v54 = *(float *)&v52->vertexNum[1]) >= v53)
                    && v54 <= *((float *)v51 + 2)
                    || (v55 = *(float *)&v52->flags) >= v53 && v55 <= *((float *)v51 + 2) )
                  {
                    if ( v53 < v54 )
                      v52->vertexNum[1] = v51[1];
                    v56 = &v16->list[v47];
                    v57 = (int *)((char *)v16->list->vertexNum + v50);
                    if ( *((float *)v57 + 2) > (double)*(float *)&v56->flags )
                      v56->flags = v57[2];
                    if ( v49 >= 0 )
                    {
                      v58 = v16->num;
                      if ( v49 < v58 )
                      {
                        v59 = v58 - 1;
                        v16->num = v59;
                        if ( v49 != v59 )
                        {
                          v60 = (int *)((char *)v16->list->vertexNum + v50);
                          v61 = &v16->list[v59];
                          *v60 = v61->vertexNum[0];
                          v60[1] = v61->vertexNum[1];
                          v60[2] = v61->flags;
                        }
                      }
                    }
                    --v49;
                    v50 -= 12;
                  }
                }
                ++v49;
                v50 += 12;
              }
              while ( v49 < *(_DWORD *)(v15 + 20) );
            }
            ++v48;
            ++v47;
          }
          while ( v48 - 1 < *(_DWORD *)(v15 + 20) );
        }
        if ( v5->isStaticPathPos )
        {
          *(float *)(v15 + 12) = distance;
          *(_DWORD *)(v15 + 4) = v71;
          *(_DWORD *)(v15 + 8) = v7;
          *(_DWORD *)v15 = HIDWORD(v71);
          idList<cachedSegList_t,5>::PreAllocateWithGranularity(this: p_segListTable, newSize: p_segListTable->num + 1);
          v62 = p_segListTable->num;
          if ( v62 < p_segListTable->size )
            p_segListTable->num = v62 + 1;
        }
        v63 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        HIDWORD(v64) = HIDWORD(vaiTimer.findEnemy_spliWithinDist.start);
        LODWORD(v64) = v63
                     + HIDWORD(vaiTimer.findEnemy_spliWithinDist.start)
                     - LODWORD(vaiTimer.findEnemy_spliWithinDist.start);
        vaiTimer.findEnemy_spliWithinDist.clockTicks = v64;
        if ( (float)idTimer::base < 0.0 )
        {
          idTimer::InitBaseClockTicks(this: &vaiTimer.findEnemy_spliWithinDist);
          LODWORD(v64) = vaiTimer.findEnemy_spliWithinDist.clockTicks;
        }
        HIDWORD(v64) = idTimer::base;
        if ( (int)v64 > (int)idTimer::base )
        {
          LODWORD(v64) = v64 - idTimer::base;
          vaiTimer.findEnemy_spliWithinDist.clockTicks = v64;
        }
        vaiTimer.findEnemy_spliWithinDist.state = TS_STOPPED;
        p_segList = (int)&p_segListTable->list[*p_num - 1].segList;
        if ( (v69.listStatic == 0 || v69.listStatic == 2) && list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        return (idList<navSplineSegment_t,5> *)p_segList;
      }
    }
  }
  v9 = v5->segListTable.list;
  v10 = 0;
  while ( 1 )
  {
    p_distance = &v9[v10].pathPos.distance;
    if ( pathPos == v9[v10].pathPos.navSpline && __fabs((float)(*(float *)&v71 - *p_distance)) < 1.0 )
      break;
    ++v8;
    ++v10;
    if ( v8 >= v66 )
      goto LABEL_7;
  }
  idTimer::Stop(this: &vaiTimer.findEnemy_spliWithinDist);
  return (idList<navSplineSegment_t,5> *)(p_distance + 4);
}


// ========================================================================
// __unwind$499674
// EA  : 0x82CC2A18
// RVA : 0x00CC2A18
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_499674()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 144));
}


// ========================================================================
// ??1idNavSplinePathMgr@@UAA@XZ
// EA  : 0x82CC2A48
// RVA : 0x00CC2A48
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::~idNavSplinePathMgr(idNavSplinePathMgr *this)
{
  idNavSplinePathMgr::navSplineFloodBits_t *floodBits; // r4
  char **p_segListTable; // r29
  idList<idNavSpline,5> *p_navSplineList_BuildGame; // r29

  this->__vftable = (idNavSplinePathMgr_vtbl *)&idNavSplinePathMgr::`vftable';
  floodBits = this->floodBits;
  if ( floodBits != nullptr )
  {
    idMem::Free(this: &mem, ptr: floodBits, align: ALIGN_16);
    this->floodBits = nullptr;
  }
  p_segListTable = (char **)&this->segListTable;
  if ( this->segListTable.listStatic == 0 || this->segListTable.listStatic == 2 )
  {
    if ( *p_segListTable != nullptr )
      idListArrayDelete<cachedSegList_t>(ptr: *p_segListTable, num: this->segListTable.size);
    *p_segListTable = nullptr;
    this->segListTable.size = 0;
  }
  this->segListTable.num = 0;
  idNavSplineGraph::~idNavSplineGraph(this: &this->splineGraph);
  this->navSplinePathTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  idStr::FreeData(this: &this->tempNavSplinePathName);
  idNavSpline::~idNavSpline(this: &this->tempNavSpline);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinePath.path);
  p_navSplineList_BuildGame = &this->navSplineList_BuildGame;
  if ( this->navSplineList_BuildGame.listStatic == 0 || this->navSplineList_BuildGame.listStatic == 2 )
  {
    if ( p_navSplineList_BuildGame->list != nullptr )
      idListArrayDelete<idNavSpline>(ptr: p_navSplineList_BuildGame->list, num: this->navSplineList_BuildGame.size);
    p_navSplineList_BuildGame->list = nullptr;
    this->navSplineList_BuildGame.size = 0;
  }
  this->navSplineList_BuildGame.num = 0;
  idStaticList<idNavSpline,200>::~idStaticList<idNavSpline,200>(this: &this->navSplineList);
  idHashIndex::Free(this: &this->trackerHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->usedTrackers);
  idNavPathPosTrackerPool::~idNavPathPosTrackerPool(this: &this->trackerPool);
  this->navSplineClosestPosSectionTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplineClosestPosTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplineTrackerTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
}


// ========================================================================
// __unwind$500139
// EA  : 0x82CC2B94
// RVA : 0x00CC2B94
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500139()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// __unwind$500140
// EA  : 0x82CC2BC0
// RVA : 0x00CC2BC0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500140()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$500141
// EA  : 0x82CC2BEC
// RVA : 0x00CC2BEC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500141()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$500142
// EA  : 0x82CC2C18
// RVA : 0x00CC2C18
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500142()
{
  int v0; // r12

  idNavPathPosTrackerPool::~idNavPathPosTrackerPool(this: (idNavPathPosTrackerPool *)(*(_DWORD *)(v0 - 144 + 164) + 140));
}


// ========================================================================
// __unwind$500143
// EA  : 0x82CC2C44
// RVA : 0x00CC2C44
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500143()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 80540));
}


// ========================================================================
// __unwind$500144
// EA  : 0x82CC2C78
// RVA : 0x00CC2C78
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500144()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 81068));
}


// ========================================================================
// __unwind$500145
// EA  : 0x82CC2CAC
// RVA : 0x00CC2CAC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500145()
{
  int v0; // r12

  idStaticList<idNavSpline,200>::~idStaticList<idNavSpline,200>(this: (idStaticList<idNavSpline,200> *)(*(_DWORD *)(v0 - 144 + 164) + 81100));
}


// ========================================================================
// __unwind$500146
// EA  : 0x82CC2CE0
// RVA : 0x00CC2CE0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500146()
{
  int v0; // r12

  idList<idNavSpline,5>::~idList<idNavSpline,5>(this: (idList<idNavSpline,5> *)(*(_DWORD *)(v0 - 144 + 164) + 103516));
}


// ========================================================================
// __unwind$500147
// EA  : 0x82CC2D14
// RVA : 0x00CC2D14
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500147()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 144 + 164) + 103532));
}


// ========================================================================
// __unwind$500148
// EA  : 0x82CC2D48
// RVA : 0x00CC2D48
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500148()
{
  int v0; // r12

  idNavSpline::~idNavSpline(this: (idNavSpline *)(*(_DWORD *)(v0 - 144 + 164) + 103572));
}


// ========================================================================
// __unwind$500149
// EA  : 0x82CC2D7C
// RVA : 0x00CC2D7C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500149()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 103688));
}


// ========================================================================
// __unwind$500150
// EA  : 0x82CC2DB0
// RVA : 0x00CC2DB0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500150()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 144 + 164) + 103720));
}


// ========================================================================
// __unwind$500151
// EA  : 0x82CC2DE4
// RVA : 0x00CC2DE4
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500151()
{
  int v0; // r12

  idNavSplineGraph::~idNavSplineGraph(this: (idNavSplineGraph *)(*(_DWORD *)(v0 - 144 + 164) + 103760));
}


// ========================================================================
// ?Init@idNavSplinePathMgr@@QAAXXZ
// EA  : 0x82CC2E18
// RVA : 0x00CC2E18
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::Init(idNavSplinePathMgr *this)
{
  idStaticList<idNavSpline,200> *NavSplineList; // r3
  int v3; // r11
  idNavSplinePathMgr::navSplineFloodBits_t *floodBits; // r4
  unsigned int floodBitSize; // r11
  unsigned int v6; // r5
  idNavSplinePathMgr::navSplineFloodBits_t *v7; // r3
  int v8; // r9
  idLinkList<idSplinePath> *next; // r11
  idNavSplinePath *owner; // r30
  idNavSplinePath *v11; // r3
  idLinkList<idSplinePath> *v12; // r11
  int v13; // r30
  int v14; // r29
  idStaticList<idNavSpline,200> *v15; // r3
  idNavSplinePath *v16; // r3
  idNavSplinePath *v17; // r3
  idNavSplinePath *v18; // r30
  idEntityPtr<idNavSplinePath> *p_tempNavSplinePath; // r28
  double v20; // fp31
  idList<float,13> *p_pathWidth; // r30
  idNavSplinePath *v22; // r3
  idNavSplinePath *v23; // r3
  idCurve_Spline<idVec3> *v24; // r3
  idCurve<idVec3> *v25; // r29
  int v26; // r4
  int v27; // r30
  idCurve_Spline<idVec3> **p_curve; // r30
  idCurve_Spline<idVec3> *curve; // r3
  idNavSplinePath *v30; // r3
  idNavSplinePath *v31; // r3
  int i; // r30
  idPlayer *Player; // r5
  idSpawnId v34[2]; // [sp+50h] [-70h] BYREF
  idVec3 v35; // [sp+58h] [-68h] BYREF
  idVec3 v36; // [sp+68h] [-58h] BYREF

  if ( com_production.valueInteger != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
    || spl_useBuildGameList.valueInteger != 0 )
  {
    if ( this->navSplineList_BuildGame.size < 500 )
      idList<idNavSpline,5>::Resize(this: &this->navSplineList_BuildGame, newsize: 500);
    v3 = 500;
  }
  else
  {
    NavSplineList = idNavSplinePathMgr::GetNavSplineList(this);
    idList<idNavSpline,5>::~idList<idNavSpline,5>(this: NavSplineList);
    v3 = 180;
  }
  this->floodBitSize = v3;
  floodBits = this->floodBits;
  if ( floodBits != nullptr )
    idMem::Free(this: &mem, ptr: floodBits, align: ALIGN_16);
  floodBitSize = this->floodBitSize;
  v6 = 4 * floodBitSize;
  if ( floodBitSize > 0x3FFFFFFF )
    v6 = -1;
  v7 = (idNavSplinePathMgr::navSplineFloodBits_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                                     size: v6,
                                                     tag: TAG_SPLINE,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  v8 = this->floodBitSize;
  this->floodBits = v7;
  this->floodBitSize = 4 * v8;
  if ( this->segListTable.num != 0 )
    idList<cachedSegList_t,5>::Clear(this: &this->segListTable);
  idList<cachedSegList_t,5>::Alloc(this: &this->segListTable);
  next = gameLocal->splinePathEntities.next;
  if ( next != nullptr && next != gameLocal->splinePathEntities.head )
  {
    owner = (idNavSplinePath *)next->owner;
    while ( owner != nullptr )
    {
      v11 = idNavSplinePath::CastTo(c: owner);
      if ( v11 != nullptr && v11->navSplineType == this->navSplineType )
        idNavSplinePathMgr::GetNavSpline(this, splineName: owner->name.data);
      v12 = owner->controlNode.next;
      if ( v12 == nullptr || v12 == owner->controlNode.head )
        owner = nullptr;
      else
        owner = (idNavSplinePath *)v12->owner;
    }
  }
  this->nextRecalcTime = 0;
  idNavPathPosTrackerPool::Clear(this: &this->trackerPool);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->usedTrackers);
  idHashIndex::Clear(this: &this->trackerHash);
  idNavSplineGraph::BuildGraph(this: &this->splineGraph, splineType: this->navSplineType);
  idNavSplinePathMgr::SetupLinks(this);
  this->SpecialSetup(this);
  v13 = 0;
  if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = idNavSplinePathMgr::GetNavSplineList(this);
      idNavSpline::Init(this: &v15->list[v14]);
      ++v13;
      ++v14;
    }
    while ( v13 < idNavSplinePathMgr::GetNavSplineList(this)->num );
  }
  if ( gameLocal != nullptr )
  {
    if ( gameLocal->FindEntity(this: gameLocal, a2: this->tempNavSplinePathName.data) == nullptr )
    {
      v16 = (idNavSplinePath *)idGameLocal::SpawnEntityType(
                                 this: gameLocal,
                                 typeInfo: &idNavSplinePath::Type,
                                 forceEntityNumber: -1,
                                 _model: nullptr);
      v17 = idNavSplinePath::CastTo(c: v16);
      v18 = v17;
      p_tempNavSplinePath = &this->tempNavSplinePath;
      if ( v17 != nullptr )
        p_tempNavSplinePath->spawnId.value = (gameLocal->spawnIds.ptr[v17->entityNumber] << 13) | v17->entityNumber;
      else
        p_tempNavSplinePath->spawnId.value = 0x1FFF;
      v20 = 0.0;
      if ( v17->controlPoints.num == 0 )
      {
        v35.x = 0.0;
        v35.y = 0.0;
        v35.z = 0.0;
        idList<idAngles,5>::Append(this: &v17->controlPoints, obj: &v35);
        v35.z = 0.0;
        v35.y = 0.0;
        v36.y = 0.0;
        v36.z = 0.0;
        v35.x = 10.0;
        v36.x = 10.0;
        idList<idAngles,5>::Append(this: &v18->controlPoints, obj: &v36);
        idNavSplinePathMgr::GetNavSpline(this, splineName: "temp");
        p_pathWidth = (idList<float,13> *)&v18->pathWidth;
        *(float *)&v34[0].value = 100.0;
        idList<float,13>::Append(this: p_pathWidth, obj: (float *)&v34[0].value);
        *(float *)&v34[0].value = 100.0;
        idList<float,13>::Append(this: p_pathWidth, obj: (float *)&v34[0].value);
      }
      if ( gameLocal->spawnIds.ptr[p_tempNavSplinePath->spawnId.value & 0x1FFF] == p_tempNavSplinePath->spawnId.value >> 13
        && (v22 = (idNavSplinePath *)gameLocal->entities.ptr[p_tempNavSplinePath->spawnId.value & 0x1FFF]) != nullptr )
      {
        v23 = idNavSplinePath::CastTo(c: v22);
      }
      else
      {
        v23 = nullptr;
      }
      v24 = idSplinePath::AllocSpline(this: v23);
      v25 = v24;
      if ( v24 != nullptr )
      {
        v26 = 0;
        if ( v24->values.num - 1 > 0 )
        {
          do
          {
            v27 = v26 + 1;
            v20 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this: v25, i0: v26, i1: v26 + 1) + (float)v20);
            v26 = v27;
          }
          while ( v27 < v25->values.num - 1 );
        }
        idCurve<idVec3>::SetConstantSpeed(this: v25, totalTime: v20);
        this->tempNavSpline.length = v20;
        this->tempNavSpline.width = 300.0;
      }
      p_curve = &this->tempNavSpline.curve;
      curve = this->tempNavSpline.curve;
      if ( curve != nullptr )
      {
        ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))curve->dtr_idCurve<idVec3>)(a1: curve, a2: 1);
        *p_curve = nullptr;
      }
      if ( gameLocal->spawnIds.ptr[p_tempNavSplinePath->spawnId.value & 0x1FFF] == p_tempNavSplinePath->spawnId.value >> 13
        && (v30 = (idNavSplinePath *)gameLocal->entities.ptr[p_tempNavSplinePath->spawnId.value & 0x1FFF]) != nullptr )
      {
        v31 = idNavSplinePath::CastTo(c: v30);
      }
      else
      {
        v31 = nullptr;
      }
      *p_curve = (idCurve_Spline<idVec3> *)v25;
      this->tempNavSpline.splinePath = v31;
    }
    for ( i = 0; i < 6; ++i )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i);
      if ( Player != nullptr )
      {
        idGameLocal::GetSpawnId(this: (idGameLocal *)v34, result: (idSpawnId *)gameLocal, ent: Player);
        idNavSplinePathMgr::FindTracker(this, ownerSpawnId: v34, createTrackerIfNotFound: true);
      }
    }
  }
  this->cleanupIndex = 0;
}


// ========================================================================
// ?GetEntitiesWithinDistance@idNavSplinePathMgr@@QAAXVidNavSplinePosition@@MAAV?$idList@PAVidEntity@@$04@@_N@Z
// EA  : 0x82CC3380
// RVA : 0x00CC3380
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __fastcall idNavSplinePathMgr::GetEntitiesWithinDistance(
        idNavSplinePathMgr *this,
        idNavSpline *pathPos,
        double distance,
        idList<idEntity *,5> *entityList,
        bool clearList,
        idList<idVehicleState *,5> *a6,
        unsigned __int8 a7)
{
  __int64 v12; // r3
  int v13; // r21
  idList<navSplineSegment_t,5> *SplinesWithinDistance; // r28
  int v15; // r22
  int v16; // r30
  navSplineSegment_t *list; // r11
  int v18; // r27
  int v19; // r29
  int value; // r9
  idEntity *v21; // r3
  idEntity *v22; // r31
  idNavPathPosTracker *Tracker; // r3
  encounterGroupRole_t distance_low; // r9
  navSplineSegment_t *v25; // r10
  encounterGroupRole_t rightDistance_low; // r8
  encounterGroupRole_t navSpline; // r7
  double start; // fp13
  double end; // fp0
  idNavSpline *v30; // r8
  float v31; // r10
  idNavSpline *v32; // r4
  double excessEdgeLimit; // fp29
  double SplineWidth; // fp1
  int num; // r9
  int v36; // r10
  int v37; // r11
  idSpawnId v38; // [sp+50h] [-C0h] BYREF
  encounterGroupRole_t v39[9]; // [sp+54h] [-BCh] BYREF
  idNavSplinePosition v40; // [sp+78h] [-98h] BYREF
  float v41; // [sp+88h] [-88h]
  float rightDistance; // [sp+8Ch] [-84h]
  idNavSpline *v43; // [sp+90h] [-80h]

  vaiTimer.findEnemy_entsWithinDist.state = TS_STARTED;
  LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.findEnemy_entsWithinDist.start = v12;
  ++vaiTimer.entsWithinDist_count;
  v13 = a7;
  SplinesWithinDistance = idNavSplinePathMgr::GetSplinesWithinDistance(this, pathPos, distance);
  if ( a7 != 0 )
    idList<idThread *,58>::Clear(this: a6);
  v15 = 0;
  if ( SplinesWithinDistance->num > 0 )
  {
    v16 = 0;
    do
    {
      list = SplinesWithinDistance->list;
      v18 = 0;
      if ( SplinesWithinDistance->list[v16].navSpline->entityList.num > 0 )
      {
        v19 = 0;
        do
        {
          value = list[v16].navSpline->entityList.list[v19].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v21 = gameLocal->entities.ptr[list[v16].navSpline->entityList.list[v19].spawnId.value & 0x1FFF]) != nullptr )
          {
            v22 = idEntity::CastTo(c: v21);
          }
          else
          {
            v22 = nullptr;
          }
          v39[0] = (encounterGroupRole_t)v22;
          if ( v22 != nullptr )
          {
            idGameLocal::GetSpawnId(this: (idGameLocal *)&v38, result: (idSpawnId *)gameLocal, ent: v22);
            Tracker = idNavSplinePathMgr::FindTracker(this, ownerSpawnId: &v38, createTrackerIfNotFound: false);
            if ( Tracker != nullptr )
            {
              distance_low = SLODWORD(Tracker->pathPosition.distance);
              v25 = &SplinesWithinDistance->list[v16];
              rightDistance_low = LODWORD(Tracker->pathPosition.rightDistance);
              navSpline = (encounterGroupRole_t)Tracker->pathPosition.navSpline;
              v39[1] = distance_low;
              start = v25->start;
              v39[2] = rightDistance_low;
              v39[3] = navSpline;
              if ( *(float *)&distance_low >= start )
              {
                end = v25->end;
                v39[5] = distance_low;
                v39[6] = rightDistance_low;
                v39[7] = navSpline;
                if ( *(float *)&distance_low <= end )
                {
                  if ( Tracker->pathPosition.navSpline->splinePath->excessEdgeLimit < 0.0 )
                    goto LABEL_17;
                  v30 = Tracker->pathPosition.navSpline;
                  v31 = Tracker->pathPosition.distance;
                  v40.rightDistance = Tracker->pathPosition.rightDistance;
                  v40.navSpline = v30;
                  v40.distance = v31;
                  v32 = Tracker->pathPosition.navSpline;
                  v41 = v31;
                  rightDistance = v40.rightDistance;
                  v43 = v30;
                  excessEdgeLimit = v32->splinePath->excessEdgeLimit;
                  SplineWidth = idNavSplinePosition::GetSplineWidth(this: &v40, dist: -1.0);
                  if ( rightDistance <= (double)(float)((float)SplineWidth + (float)excessEdgeLimit) )
                  {
LABEL_17:
                    if ( v13 != 0 )
                      goto LABEL_23;
                    num = a6->num;
                    v36 = 0;
                    if ( num > 0 )
                    {
                      v37 = 0;
                      do
                      {
                        if ( (idEntity *)a6->list[v37] == v22 )
                          break;
                        ++v36;
                        ++v37;
                      }
                      while ( v36 < num );
                    }
                    if ( v36 >= num )
LABEL_23:
                      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)a6, obj: v39);
                  }
                }
              }
            }
          }
          list = SplinesWithinDistance->list;
          ++v18;
          ++v19;
        }
        while ( v18 < SplinesWithinDistance->list[v16].navSpline->entityList.num );
      }
      ++v15;
      ++v16;
    }
    while ( v15 < SplinesWithinDistance->num );
  }
  idTimer::Stop(this: &vaiTimer.findEnemy_entsWithinDist);
}


// ========================================================================
// ??0idNavSplinePathMgr@@QAA@XZ
// EA  : 0x82CC3640
// RVA : 0x00CC3640
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idNavSplinePathMgr *__fastcall idNavSplinePathMgr::idNavSplinePathMgr(idNavSplinePathMgr *this)
{
  __int64 v1; // r29
  idNavPathPosTrackerPool *p_trackerPool; // r24
  __int64 v4; // r29
  int v5; // ctr
  unsigned __int8 *p_memTag; // r10
  idNavSplinePathMgr::navSplineFloodBits_t *v7; // r3
  int floodBitSize; // r4

  LODWORD(v1) = 0;
  this->__vftable = (idNavSplinePathMgr_vtbl *)&idNavSplinePathMgr::`vftable';
  this->navSplineTrackerTimer.state = TS_STOPPED;
  this->navSplineTrackerTimer.clockTicks = v1;
  this->navSplineTrackerTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplineClosestPosTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplineClosestPosTimer.state = TS_STOPPED;
  this->navSplineClosestPosTimer.clockTicks = v1;
  this->navSplineClosestPosSectionTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplineClosestPosSectionTimer.state = TS_STOPPED;
  this->navSplineClosestPosSectionTimer.clockTicks = v1;
  p_trackerPool = &this->trackerPool;
  HIDWORD(v4) = &this->usedTrackers;
  idNavPathPosTrackerPool::idNavPathPosTrackerPool(this: &this->trackerPool);
  v5 = 256;
  this->usedTrackers.size = 256;
  p_memTag = &this->usedTrackers.memTag;
  this->usedTrackers.num = 0;
  this->usedTrackers.granularity = 1;
  this->usedTrackers.list = this->usedTrackers.staticList;
  this->usedTrackers.memTag = 5;
  this->usedTrackers.listStatic = 1;
  do
  {
    p_memTag += 2;
    *(_WORD *)p_memTag = -1;
    --v5;
  }
  while ( v5 != 0 );
  this->trackerHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->trackerHash, initialHashSize: 128, initialIndexSize: 128);
  idStaticList<idNavSpline,200>::idStaticList<idNavSpline,200>(this: &this->navSplineList);
  this->navSplineList_BuildGame.granularity = 0;
  this->navSplineList_BuildGame.memTag = 5;
  this->navSplineList_BuildGame.listStatic = 0;
  this->navSplineList_BuildGame.list = nullptr;
  this->navSplineList_BuildGame.size = 0;
  this->navSplineList_BuildGame.num = 0;
  navSplinePath_t::navSplinePath_t(this: &this->splinePath);
  this->tempNavSplinePath.spawnId.value = 0x1FFF;
  idNavSpline::idNavSpline(this: &this->tempNavSpline);
  this->tempNavSplinePathName.allocedAndFlag = 20;
  this->tempNavSplinePathName.data = this->tempNavSplinePathName.baseBuffer;
  this->tempNavSplinePathName.len = 0;
  this->tempNavSplinePathName.baseBuffer[0] = 0;
  this->navSplinePathTimer.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  this->navSplinePathTimer.state = TS_STOPPED;
  this->navSplinePathTimer.clockTicks = v4;
  idNavSplineGraph::idNavSplineGraph(this: &this->splineGraph);
  this->segListTable.granularity = 0;
  this->segListTable.memTag = 5;
  this->segListTable.listStatic = 0;
  this->segListTable.list = nullptr;
  this->segListTable.size = 0;
  this->segListTable.num = 0;
  this->navSplinePathTimer.clockTicks = v4;
  this->debugTracker = nullptr;
  this->navSplineTrackerTimer.clockTicks = v4;
  this->navSplineTrackerCount = 0;
  this->navSplineClosestPosTimer.clockTicks = v4;
  this->navSplineClosestPosCount = 0;
  this->navSplinePathCount = 0;
  this->navSplinePathCount2 = 0;
  this->navSplineClosestPosSectionTimer.clockTicks = v4;
  this->navSplineClosestPosSectionCount = 0;
  this->freeAngles = ang_zero;
  this->currentViewAngles = ang_zero;
  this->lastCarAngles = ang_zero;
  this->wildSpinTime = 0;
  this->lastDrawTime = 0;
  this->viewAnglesDeltaPerc = 0.0;
  this->nextRecalcTime = 0;
  this->updatetime = 0.0;
  this->cleanupIndex = 0;
  this->floodBitSize = 180;
  v7 = (idNavSplinePathMgr::navSplineFloodBits_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                                     size: 0x2D0u,
                                                     tag: TAG_SPLINE,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  floodBitSize = this->floodBitSize;
  this->floodBits = v7;
  this->floodBitSize = 4 * floodBitSize;
  this->navSplineType = NAV_SPLINE_TYPE_DEFAULT;
  idStr::operator=(this: &this->tempNavSplinePathName, text: "tempNavSplinePath");
  this->isStaticPathPos = false;
  idNavPathPosTrackerPool::Clear(this: p_trackerPool);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->usedTrackers);
  idHashIndex::Clear(this: &this->trackerHash);
  return this;
}


// ========================================================================
// __unwind$500756
// EA  : 0x82CC395C
// RVA : 0x00CC395C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500756()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 208 + 228) + 16));
}


// ========================================================================
// __unwind$500757
// EA  : 0x82CC3988
// RVA : 0x00CC3988
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500757()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 208 + 228) + 56));
}


// ========================================================================
// __unwind$500758
// EA  : 0x82CC39B4
// RVA : 0x00CC39B4
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500758()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 208 + 228) + 96));
}


// ========================================================================
// __unwind$500759
// EA  : 0x82CC39E0
// RVA : 0x00CC39E0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500759()
{
  int v0; // r12

  idNavPathPosTrackerPool::~idNavPathPosTrackerPool(this: (idNavPathPosTrackerPool *)(*(_DWORD *)(v0 - 208 + 228) + 140));
}


// ========================================================================
// __unwind$500760
// EA  : 0x82CC3A0C
// RVA : 0x00CC3A0C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500760()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 80540));
}


// ========================================================================
// __unwind$500761
// EA  : 0x82CC3A40
// RVA : 0x00CC3A40
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500761()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 208 + 228) + 81068));
}


// ========================================================================
// __unwind$500762
// EA  : 0x82CC3A74
// RVA : 0x00CC3A74
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500762()
{
  int v0; // r12

  idStaticList<idNavSpline,200>::~idStaticList<idNavSpline,200>(this: (idStaticList<idNavSpline,200> *)(*(_DWORD *)(v0 - 208 + 228) + 81100));
}


// ========================================================================
// __unwind$500763
// EA  : 0x82CC3AA8
// RVA : 0x00CC3AA8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500763()
{
  int v0; // r12

  idList<idNavSpline,5>::~idList<idNavSpline,5>(this: (idList<idNavSpline,5> *)(*(_DWORD *)(v0 - 208 + 228) + 103516));
}


// ========================================================================
// __unwind$500764
// EA  : 0x82CC3ADC
// RVA : 0x00CC3ADC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500764()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 208 + 228) + 103532));
}


// ========================================================================
// __unwind$500765
// EA  : 0x82CC3B10
// RVA : 0x00CC3B10
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500765()
{
  int v0; // r12

  idNavSpline::~idNavSpline(this: (idNavSpline *)(*(_DWORD *)(v0 - 208 + 228) + 103572));
}


// ========================================================================
// __unwind$500766
// EA  : 0x82CC3B44
// RVA : 0x00CC3B44
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 208 + 228) + 103688));
}


// ========================================================================
// __unwind$500767
// EA  : 0x82CC3B78
// RVA : 0x00CC3B78
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500767()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(*(_DWORD *)(v0 - 208 + 228) + 103720));
}


// ========================================================================
// __unwind$500768
// EA  : 0x82CC3BAC
// RVA : 0x00CC3BAC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500768()
{
  int v0; // r12

  idNavSplineGraph::~idNavSplineGraph(this: (idNavSplineGraph *)(*(_DWORD *)(v0 - 208 + 228) + 103760));
}


// ========================================================================
// __unwind$500769
// EA  : 0x82CC3BE0
// RVA : 0x00CC3BE0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_500769()
{
  int v0; // r12

  idList<cachedSegList_t,5>::Clear(this: (idList<cachedSegList_t,5> *)(*(_DWORD *)(v0 - 208 + 228) + 158456));
}


// ========================================================================
// ??0idQuestNavSplinePathMgr@@QAA@XZ
// EA  : 0x82CC3C80
// RVA : 0x00CC3C80
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

idQuestNavSplinePathMgr *__fastcall idQuestNavSplinePathMgr::idQuestNavSplinePathMgr(idQuestNavSplinePathMgr *this)
{
  idNavSplinePathMgr::idNavSplinePathMgr(this);
  this->__vftable = (idQuestNavSplinePathMgr_vtbl *)&idQuestNavSplinePathMgr::`vftable';
  this->navSplineType = NAV_SPLINE_TYPE_QUEST;
  idStr::operator=(this: &this->tempNavSplinePathName, text: "tempQuestNavSplinePath");
  this->splineDistanceToJob = 0.0;
  this->totalDistanceToJob = 0.0;
  return this;
}


// ========================================================================
// __unwind$501044
// EA  : 0x82CC3D10
// RVA : 0x00CC3D10
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void _unwind_501044()
{
  int v0; // r12

  idNavSplinePathMgr::~idNavSplinePathMgr(this: *(idNavSplinePathMgr **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'spl_qn_graph''
// EA  : 0x83378B20
// RVA : 0x01378B20
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_graph__()
{
  idCVar::idCVar(
    this: &spl_qn_graph,
    name: "spl_qn_graph",
    value: "0",
    flags: 1,
    description: "Draw spline graph",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_graph__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_timer''
// EA  : 0x83378B78
// RVA : 0x01378B78
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_timer__()
{
  idCVar::idCVar(
    this: &spl_qn_timer,
    name: "spl_qn_timer",
    value: "0",
    flags: 1,
    description: "Show spline timing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_timer__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_showAllPaths''
// EA  : 0x83378BD0
// RVA : 0x01378BD0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_showAllPaths__()
{
  idCVar::idCVar(
    this: &spl_qn_showAllPaths,
    name: "spl_qn_showAllPaths",
    value: "0",
    flags: 4,
    description: "Display all quest nav splines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_showAllPaths__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_showPathBounds''
// EA  : 0x83378C28
// RVA : 0x01378C28
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_showPathBounds__()
{
  idCVar::idCVar(
    this: &spl_qn_showPathBounds,
    name: "spl_qn_showPathBounds",
    value: "0",
    flags: 1,
    description: "Show spline bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_showPathBounds__);
}


// ========================================================================
// `dynamic initializer for 'spl_updateTracker_rateMS''
// EA  : 0x83378C80
// RVA : 0x01378C80
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_updateTracker_rateMS__()
{
  idCVar::idCVar(
    this: &spl_updateTracker_rateMS,
    name: "spl_updateTracker_rateMS",
    value: "16",
    flags: 2,
    description: "Min MS between update (assumes 60hz)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_updateTracker_rateMS__);
}


// ========================================================================
// `dynamic initializer for 'spl_updateTracker_distance''
// EA  : 0x83378CD8
// RVA : 0x01378CD8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_updateTracker_distance__()
{
  idCVar::idCVar(
    this: &spl_updateTracker_distance,
    name: "spl_updateTracker_distance",
    value: "5",
    flags: 2,
    description: "Distance at which spline position will be totally recalculated (rather than simply adjusted).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_updateTracker_distance__);
}


// ========================================================================
// `dynamic initializer for 'spl_showFurthestPositionSamples''
// EA  : 0x83378D30
// RVA : 0x01378D30
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_showFurthestPositionSamples__()
{
  idCVar::idCVar(
    this: &spl_showFurthestPositionSamples,
    name: "spl_showFurthestPositionSamples",
    value: "0",
    flags: 1,
    description: "Draw furthest pos sample info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_showFurthestPositionSamples__);
}


// ========================================================================
// `dynamic initializer for 'spl_useBuildGameList''
// EA  : 0x83378D88
// RVA : 0x01378D88
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_useBuildGameList__()
{
  idCVar::idCVar(
    this: &spl_useBuildGameList,
    name: "spl_useBuildGameList",
    value: "0",
    flags: 1,
    description: "Uses navSplineList_BuildGame (for testing)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_useBuildGameList__);
}


// ========================================================================
// `dynamic initializer for 'vai_timer''
// EA  : 0x83378DE0
// RVA : 0x01378DE0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_timer__()
{
  idCVar::idCVar(
    this: &vai_timer,
    name: "vai_timer",
    value: "0",
    flags: 4,
    description: "Show vehicle AI timing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_timer__);
}


// ========================================================================
// `dynamic initializer for 'vaiTimer''
// EA  : 0x83378E38
// RVA : 0x01378E38
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vaiTimer__()
{
  VaiTiming::VaiTiming(this: &vaiTimer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vaiTimer__);
}


// ========================================================================
// `dynamic initializer for 'spl_disablePathing''
// EA  : 0x83378E70
// RVA : 0x01378E70
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_disablePathing__()
{
  idCVar::idCVar(
    this: &spl_disablePathing,
    name: "spl_disablePathing",
    value: "0",
    flags: 1,
    description: "Disables vehicle AI pathing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_disablePathing__);
}


// ========================================================================
// `dynamic initializer for 'spl_testClosestDist''
// EA  : 0x83378EC8
// RVA : 0x01378EC8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_testClosestDist__()
{
  idCVar::idCVar(
    this: &spl_testClosestDist,
    name: "spl_testClosestDist",
    value: "0",
    flags: 1,
    description: "Testing closest dist to spline calculation.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_testClosestDist__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_debug''
// EA  : 0x83378F20
// RVA : 0x01378F20
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_debug__()
{
  idCVar::idCVar(
    this: &spl_qn_debug,
    name: "spl_qn_debug",
    value: "0",
    flags: 1,
    description: "Debug the quest navigation splines",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_debug__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_addDistToStep''
// EA  : 0x83378F78
// RVA : 0x01378F78
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_addDistToStep__()
{
  idCVar::idCVar(
    this: &spl_qn_addDistToStep,
    name: "spl_qn_addDistToStep",
    value: "0",
    flags: 1,
    description: "add the distance to the closest spline to the spline step",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_addDistToStep__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_zpenelty''
// EA  : 0x83378FD0
// RVA : 0x01378FD0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_zpenelty__()
{
  idCVar::idCVar(
    this: &spl_qn_zpenelty,
    name: "spl_qn_zpenelty",
    value: "1.0f",
    flags: 4,
    description: "additional penalty for z differences",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_zpenelty__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathbonus''
// EA  : 0x83379028
// RVA : 0x01379028
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathbonus__()
{
  idCVar::idCVar(
    this: &spl_qn_pathbonus,
    name: "spl_qn_pathbonus",
    value: "0.5f",
    flags: 4,
    description: "bonus for being within the bounds of the spline",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathbonus__);
}

