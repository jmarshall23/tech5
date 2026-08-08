
// ========================================================================
// ?SetGoalPathPosition@idNavPathPosTracker@@QAAXVidNavSplinePosition@@_N@Z
// EA  : 0x82CC4850
// RVA : 0x00CC4850
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetGoalPathPosition(
        idNavPathPosTracker *this,
        idNavSpline *pathPos,
        bool doPathSearch,
        char a4)
{
  navSplinePath_t *p_pathToGoal; // r31
  idNavSpline *navSpline; // r28
  float distance; // [sp+50h] [-40h]
  float rightDistance; // [sp+54h] [-3Ch]

  LODWORD(this->goalPathPosition.rightDistance) = pathPos;
  this->goalPathPosition.navSpline = pathPos;
  LODWORD(this->goalPathPosition.distance) = this;
  if ( a4 != 0 )
  {
    p_pathToGoal = &this->pathToGoal;
    navSpline = this->pathPosition.navSpline;
    distance = this->pathPosition.distance;
    rightDistance = this->pathPosition.rightDistance;
    idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType);
    idNavSplinePathMgr::GetShortestPath(
      this: (idNavSplinePathMgr *)LODWORD(distance),
      start: (idNavSpline *)LODWORD(rightDistance),
      end: (idNavSplinePosition *)__ROL4__(navSpline, 32),
      path: (idNavSplinePosition *)pathPos,
      a5: 0,
      a6: p_pathToGoal);
  }
}


// ========================================================================
// ?Init@idNavPathPosTracker@@QAAXXZ
// EA  : 0x82CC48D8
// RVA : 0x00CC48D8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::Init(idNavPathPosTracker *this)
{
  this->pathPosition.navSpline = nullptr;
  this->pathPosition.distance = 0.0;
  this->pathPosition.rightDistance = 0.0;
  this->worldPosition = vec3_origin;
  this->goalPathPosition.navSpline = nullptr;
  this->goalPathPosition.distance = 0.0;
  this->goalPathPosition.rightDistance = 0.0;
  this->goalWorldPosition = vec3_origin;
  this->allowSplineJumping = true;
  this->recalcTime = 0.0;
  this->nextSpline = nullptr;
  this->prevSpline = nullptr;
  this->right = vec3_origin;
  this->forward = this->right;
  this->pathTraversalType = NAVSP_RANDOM;
  this->useVelocityToGetClosestSpline = true;
  this->canChooseSimilarSplit = true;
  this->lastGoalNode = nullptr;
  this->lastNavSpline = nullptr;
  this->lastRecalcPosition = vec3_origin;
}


// ========================================================================
// ?ChooseSimilarSplit@idNavPathPosTracker@@QAAXAAPAVidNavSpline@@0@Z
// EA  : 0x82CC49B0
// RVA : 0x00CC49B0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::ChooseSimilarSplit(
        idNavPathPosTracker *this,
        idNavSpline **nextSpline,
        idNavSpline **prevSpline)
{
  idNavSpline *v6; // r31
  idNavSpline *navSpline; // r30
  idNavSplinePathMgr *NavSplinePathMgr; // r3
  navSplinePathNode_t *SharedNode; // r3
  idNavSpline *v10; // r10
  signed int v11; // r7
  int num; // r30
  int v13; // r31
  int v14; // r6
  navSplineLink_t *v15; // r4
  _DWORD *v16; // r8
  idNavSpline *v17; // r5
  navSplineLink_t *v18; // r9
  idNavSpline *v19; // r11
  idNavSpline *v20; // r11
  idNavSpline *v21; // r11
  idNavSpline *v22; // r11
  navSplineLink_t *list; // r6
  int v24; // r8
  idNavSpline *v25; // r5
  _DWORD *v26; // r4
  idNavSpline *v27; // r11
  idNavSpline *v28; // r10
  unsigned int seed; // r10
  unsigned int v30; // r6
  int v31; // r5
  idNavSpline *v32; // r31
  idNavSpline *v33; // r30
  idNavSplinePathMgr *v34; // r3
  navSplinePathNode_t *v35; // r3
  idNavSpline *v36; // r10
  signed int v37; // r7
  int v38; // r30
  int v39; // r31
  int v40; // r6
  navSplineLink_t *v41; // r4
  _DWORD *v42; // r8
  idNavSpline *v43; // r5
  navSplineLink_t *v44; // r9
  idNavSpline *v45; // r11
  idNavSpline *v46; // r11
  idNavSpline *v47; // r11
  idNavSpline *v48; // r11
  navSplineLink_t *v49; // r6
  int v50; // r8
  idNavSpline *v51; // r5
  _DWORD *v52; // r4
  idNavSpline *v53; // r11
  idNavSpline *v54; // r10
  idClientGame *v55; // r11
  unsigned int v56; // r5
  int v57; // r4
  _DWORD v58[6]; // [sp+50h] [-80h] BYREF

  if ( this->pathToGoal.path.num >= 1 )
  {
    v6 = *nextSpline;
    if ( *nextSpline != nullptr )
    {
      navSpline = this->pathPosition.navSpline;
      NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType);
      SharedNode = idNavSplinePathMgr::GetSharedNode(this: NavSplinePathMgr, spline1: navSpline, spline2: v6);
      if ( SharedNode != nullptr )
      {
        v10 = *nextSpline;
        v11 = 1;
        num = SharedNode->links.num;
        v13 = 0;
        v58[0] = *nextSpline;
        if ( num < 4 )
        {
LABEL_27:
          if ( v13 < num )
          {
            list = SharedNode->links.list;
            v24 = v13;
            v25 = this->pathToGoal.path.list->navSpline;
            v26 = &v58[v11 - 1];
            do
            {
              v27 = list[v24].navSpline;
              if ( v27 != v25 )
              {
                v28 = *nextSpline;
                if ( v27 != *nextSpline
                  && list[v24].node == v28->endNode
                  && __fabs((float)(v27->length - v28->length)) <= 2500.0 )
                {
                  ++v11;
                  *++v26 = v27;
                  if ( v11 == 4 )
                    break;
                }
              }
              ++v13;
              ++v24;
            }
            while ( v13 < num );
          }
        }
        else
        {
          v14 = 0;
          v15 = SharedNode->links.list;
          v16 = v58;
          v17 = this->pathToGoal.path.list->navSpline;
          while ( 1 )
          {
            v18 = &v15[v14];
            v19 = v15[v14].navSpline;
            if ( v19 != v17
              && v19 != v10
              && v18->node == v10->endNode
              && __fabs((float)(v19->length - v10->length)) <= 2500.0 )
            {
              ++v11;
              v16[1] = v19;
              ++v16;
              if ( v11 == 4 )
                break;
            }
            v20 = v18[1].navSpline;
            if ( v20 != v17
              && v20 != v10
              && v18[1].node == v10->endNode
              && __fabs((float)(v20->length - v10->length)) <= 2500.0 )
            {
              ++v11;
              v16[1] = v20;
              ++v16;
              if ( v11 == 4 )
                break;
            }
            v21 = v18[2].navSpline;
            if ( v21 != v17
              && v21 != v10
              && v15[v14 + 2].node == v10->endNode
              && __fabs((float)(v21->length - v10->length)) <= 2500.0 )
            {
              ++v11;
              v16[1] = v21;
              ++v16;
              if ( v11 == 4 )
                break;
            }
            v22 = v18[3].navSpline;
            if ( v22 != v17
              && v22 != v10
              && v15[v14 + 3].node == v10->endNode
              && __fabs((float)(v22->length - v10->length)) <= 2500.0 )
            {
              ++v11;
              *++v16 = v22;
              if ( v11 == 4 )
                break;
            }
            v13 += 4;
            v14 += 4;
            if ( v13 >= num - 3 )
              goto LABEL_27;
          }
        }
        if ( v11 > 1 )
        {
          seed = clientGame->random.seed;
          __twllei(v11, 0);
          v30 = 1664525 * seed + 1013904223;
          clientGame->random.seed = v30;
          v31 = (v30 >> 10) & 0x7FFF;
          __twlgei(v11 & ~(__ROL4__(v31, 1) - 1), 0xFFFFFFFF);
          *nextSpline = (idNavSpline *)v58[v31 % v11];
        }
      }
    }
    v32 = *prevSpline;
    if ( *prevSpline != nullptr )
    {
      v33 = this->pathPosition.navSpline;
      v34 = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType);
      v35 = idNavSplinePathMgr::GetSharedNode(this: v34, spline1: v33, spline2: v32);
      if ( v35 != nullptr )
      {
        v36 = *prevSpline;
        v37 = 1;
        v38 = v35->links.num;
        v39 = 0;
        v58[0] = *prevSpline;
        if ( v38 < 4 )
        {
LABEL_62:
          if ( v39 < v38 )
          {
            v49 = v35->links.list;
            v50 = v39;
            v51 = this->pathToGoal.path.list->navSpline;
            v52 = &v58[v37 - 1];
            do
            {
              v53 = v49[v50].navSpline;
              if ( v53 != v51 )
              {
                v54 = *prevSpline;
                if ( v53 != *prevSpline
                  && v49[v50].node == v54->startNode
                  && __fabs((float)(v53->length - v54->length)) <= 2500.0 )
                {
                  ++v37;
                  *++v52 = v53;
                  if ( v37 == 4 )
                    break;
                }
              }
              ++v39;
              ++v50;
            }
            while ( v39 < v38 );
          }
        }
        else
        {
          v40 = 0;
          v41 = v35->links.list;
          v42 = v58;
          v43 = this->pathToGoal.path.list->navSpline;
          while ( 1 )
          {
            v44 = &v41[v40];
            v45 = v41[v40].navSpline;
            if ( v45 != v43
              && v45 != v36
              && v44->node == v36->startNode
              && __fabs((float)(v45->length - v36->length)) <= 2500.0 )
            {
              ++v37;
              v42[1] = v45;
              ++v42;
              if ( v37 == 4 )
                break;
            }
            v46 = v44[1].navSpline;
            if ( v46 != v43
              && v46 != v36
              && v44[1].node == v36->startNode
              && __fabs((float)(v46->length - v36->length)) <= 2500.0 )
            {
              ++v37;
              v42[1] = v46;
              ++v42;
              if ( v37 == 4 )
                break;
            }
            v47 = v44[2].navSpline;
            if ( v47 != v43
              && v47 != v36
              && v41[v40 + 2].node == v36->startNode
              && __fabs((float)(v47->length - v36->length)) <= 2500.0 )
            {
              ++v37;
              v42[1] = v47;
              ++v42;
              if ( v37 == 4 )
                break;
            }
            v48 = v44[3].navSpline;
            if ( v48 != v43
              && v48 != v36
              && v41[v40 + 3].node == v36->startNode
              && __fabs((float)(v48->length - v36->length)) <= 2500.0 )
            {
              ++v37;
              *++v42 = v48;
              if ( v37 == 4 )
                break;
            }
            v39 += 4;
            v40 += 4;
            if ( v39 >= v38 - 3 )
              goto LABEL_62;
          }
        }
        if ( v37 != 0 )
        {
          v55 = clientGame;
          __twllei(v37, 0);
          v56 = 1664525 * v55->random.seed + 1013904223;
          v55->random.seed = v56;
          v57 = (v56 >> 10) & 0x7FFF;
          __twlgei(v37 & ~(__ROL4__(v57, 1) - 1), 0xFFFFFFFF);
          *prevSpline = (idNavSpline *)v58[v57 % v37];
        }
      }
    }
  }
}


// ========================================================================
// ?SetGoalWorldPosition@idNavPathPosTracker@@QAAXVidVec3@@VidNavSplinePosition@@@Z
// EA  : 0x82CC4F50
// RVA : 0x00CC4F50
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetGoalWorldPosition(
        idNavPathPosTracker *this,
        idVec3 *pos,
        idNavSplinePosition *pathPos,
        idNavSpline *a4)
{
  this->goalWorldPosition.x = *(float *)&this;
  this->goalWorldPosition.y = *(float *)&pos;
  this->goalWorldPosition.z = *(float *)&pos;
  idNavPathPosTracker::SetGoalPathPosition(this, pathPos: a4, doPathSearch: __ROL4__(a4, 32), a4: 1);
}


// ========================================================================
// ?GetSplineWidth@idNavPathPosTracker@@QAAMXZ
// EA  : 0x82CC4FA8
// RVA : 0x00CC4FA8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetSplineWidth(idNavPathPosTracker *this)
{
  double Width; // fp1

  Width = idNavSpline::GetWidth(this: this->pathPosition.navSpline, distance: this->pathPosition.distance);
  return *((float *)&Width + 1);
}


// ========================================================================
// ?GetOwner@idNavPathPosTracker@@QBAPAVidEntity@@XZ
// EA  : 0x82CC4FE8
// RVA : 0x00CC4FE8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

idEntity *__fastcall idNavPathPosTracker::GetOwner(idNavPathPosTracker *this)
{
  idEntity *v1; // r3

  if ( gameLocal != nullptr
    && gameLocal->spawnIds.ptr[this->owner.spawnId.value & 0x1FFF] == this->owner.spawnId.value >> 13
    && (v1 = gameLocal->entities.ptr[this->owner.spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?ValidateIntersection@idNavPathPosTracker@@QAA?AVidNavSplinePosition@@V2@@Z
// EA  : 0x82CC5060
// RVA : 0x00CC5060
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idNavPathPosTracker *__fastcall idNavPathPosTracker::ValidateIntersection(
        idNavPathPosTracker *this,
        idNavPathPosTracker *result,
        __int64 splinePos,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  float v15; // r9
  int v16; // r30
  int v17; // r11
  float v18; // r9
  idNavSplinePath *splinePath; // r27
  idCurve_Spline<idVec3> *curve; // r26
  float width; // r25
  float *SplineWorldPos; // r3
  double v23; // fp31
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v26; // r28
  int v27; // r29
  idNavSpline *v28; // r31
  float *v29; // r8
  int v30; // r7
  float *v31; // r3
  int v32; // [sp+8h] [-108h]
  int v33; // [sp+Ch] [-104h]
  int v34; // [sp+10h] [-100h]
  int v35; // [sp+14h] [-FCh]
  int v36; // [sp+18h] [-F8h]
  int v37; // [sp+1Ch] [-F4h]
  int v38; // [sp+20h] [-F0h]
  int v39; // [sp+24h] [-ECh]
  int v40; // [sp+28h] [-E8h]
  int v41; // [sp+2Ch] [-E4h]
  int v42; // [sp+30h] [-E0h]
  int v43; // [sp+34h] [-DCh]
  int v44; // [sp+38h] [-D8h]
  int v45; // [sp+3Ch] [-D4h]
  int v46; // [sp+40h] [-D0h]
  int v47; // [sp+44h] [-CCh]
  int v48; // [sp+48h] [-C8h]
  int v49; // [sp+4Ch] [-C4h]
  int v50; // [sp+50h] [-C0h]
  float *v51; // [sp+58h] [-B8h]
  float v52; // [sp+60h] [-B0h] BYREF
  float v53; // [sp+64h] [-ACh] BYREF
  idNavSplinePosition v54; // [sp+68h] [-A8h] BYREF
  idNavSpline v55; // [sp+78h] [-98h] BYREF

  a11 = *(__int64 *)((char *)&splinePos + 4);
  a12 = splinePos;
  if ( idNavPathPosTracker::GetOwner(this: result) != nullptr )
  {
    if ( *(float *)&a11 >= (double)(float)(*(float *)(HIDWORD(a12) + 12) - *(float *)&a11) )
      v16 = *(_DWORD *)(HIDWORD(a12) + 72);
    else
      v16 = *(_DWORD *)(HIDWORD(a12) + 68);
    if ( v16 != 0 )
    {
      idNavSplinePosition::GetWorldPos(this: &v54, result: (idVec3 *)&a11);
      splinePath = (idNavSplinePath *)HIDWORD(a11);
      curve = (idCurve_Spline<idVec3> *)a11;
      width = *(float *)&a12;
      SplineWorldPos = (float *)idNavSplinePosition::GetSplineWorldPos(
                                  this: (idNavSplinePosition *)&v55,
                                  result: (idVec3 *)&a11);
      v23 = (float)((float)((float)(*SplineWorldPos - v54.distance) * (float)(*SplineWorldPos - v54.distance))
                  + (float)((float)((float)(SplineWorldPos[2] - *(float *)&v54.navSpline)
                                  * (float)(SplineWorldPos[2] - *(float *)&v54.navSpline))
                          + (float)((float)(SplineWorldPos[1] - v54.rightDistance)
                                  * (float)(SplineWorldPos[1] - v54.rightDistance))));
      Owner = idNavPathPosTracker::GetOwner(this: result);
      Physics = idEntity::GetPhysics(this: Owner);
      Physics->GetLinearVelocity(this: (idPhysics *)&v55.traversed, result: (idVec3 *)Physics, a3: 0);
      idVec3::NormalizeFast(this: (idVec3 *)&v55.traversed);
      v26 = 0;
      if ( *(int *)(v16 + 16) > 0 )
      {
        v27 = 0;
        do
        {
          v28 = *(idNavSpline **)(v27 + *(_DWORD *)(v16 + 12) + 8);
          if ( v28 != (idNavSpline *)HIDWORD(a12) )
          {
            idNavSpline::GetClosestSection(
              this: v28,
              worldPos: (idVec3 *)LODWORD(v54.rightDistance),
              minDist: (float *)__ROL4__(v54.navSpline, 32),
              maxDist: &v53,
              distanceToWorldPos: &v52);
            idNavSpline::GetClosestPositionFromSection(
              this: &v55,
              worldPos: __SPAIR64__(LODWORD(v54.rightDistance), __ROL4__(v54.navSpline, 32)),
              minDist: v53,
              maxDist: v52,
              iterations: v30,
              epsilon: 0.1,
              distSqrToWorldPos: v29,
              a8: 8,
              a9: (int)v54.navSpline,
              a10: v32,
              a11: v33,
              a12: v34,
              a13: v35,
              a14: v36,
              a15: v37,
              a16: v38,
              a17: v39,
              a18: v40,
              a19: v41,
              a20: v42,
              a21: v43,
              a22: v44,
              a23: v45,
              a24: v46,
              a25: v47,
              a26: v48,
              a27: v49,
              a28: v50,
              a29: 0,
              a30: v51);
            v31 = (float *)idNavSplinePosition::GetSplineWorldPos(
                             this: (idNavSplinePosition *)&v55.next.granularity,
                             result: (idVec3 *)&v55);
            if ( (float)((float)((float)(*v31 - v54.distance) * (float)(*v31 - v54.distance))
                       + (float)((float)((float)(v31[2] - *(float *)&v54.navSpline)
                                       * (float)(v31[2] - *(float *)&v54.navSpline))
                               + (float)((float)(v31[1] - v54.rightDistance) * (float)(v31[1] - v54.rightDistance)))) < v23 )
            {
              splinePath = v55.splinePath;
              v23 = (float)((float)((float)(*v31 - v54.distance) * (float)(*v31 - v54.distance))
                          + (float)((float)((float)(v31[2] - *(float *)&v54.navSpline)
                                          * (float)(v31[2] - *(float *)&v54.navSpline))
                                  + (float)((float)(v31[1] - v54.rightDistance) * (float)(v31[1] - v54.rightDistance))));
              curve = v55.curve;
              width = v55.width;
            }
          }
          ++v26;
          v27 += 16;
        }
        while ( v26 < *(_DWORD *)(v16 + 16) );
      }
      this->owner.spawnId.value = (int)splinePath;
      LODWORD(this->pathPosition.distance) = curve;
      this->pathPosition.rightDistance = width;
      return this;
    }
    else
    {
      v17 = HIDWORD(a11);
      v18 = *((float *)&a11 + 1);
      this->pathPosition.rightDistance = *(float *)&a12;
      this->owner.spawnId.value = v17;
      this->pathPosition.distance = v18;
      return this;
    }
  }
  else
  {
    v15 = *(float *)&a12;
    *(_QWORD *)&this->owner.spawnId.value = a11;
    this->pathPosition.rightDistance = v15;
    return this;
  }
}


// ========================================================================
// ?GetCurrentSpeedInMPH@idNavPathPosTracker@@QAAMXZ
// EA  : 0x82CC52C0
// RVA : 0x00CC52C0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetCurrentSpeedInMPH(idNavPathPosTracker *this)
{
  idEntity *Owner; // r3
  idEntity *BindMaster; // r3
  idEntity *v4; // r3
  idEntity *v5; // r31
  idPhysics *Physics; // r30
  idPhysics *v7; // r31
  float *v8; // r30
  float *v9; // r3
  double v10; // fp1
  char v12; // [sp+50h] [-30h] BYREF

  if ( idNavPathPosTracker::GetOwner(this) != nullptr )
  {
    Owner = idNavPathPosTracker::GetOwner(this);
    if ( idEntity::GetBindMaster(this: Owner) != nullptr )
    {
      v4 = idNavPathPosTracker::GetOwner(this);
      BindMaster = idEntity::GetBindMaster(this: v4);
    }
    else
    {
      BindMaster = idNavPathPosTracker::GetOwner(this);
    }
    v5 = BindMaster;
    Physics = idEntity::GetPhysics(this: BindMaster);
    v7 = idEntity::GetPhysics(this: v5);
    v8 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    v9 = (float *)v7->GetLinearVelocity(this: (idPhysics *)&v12, result: (idVec3 *)v7, a3: 0);
    v10 = __fabs((float)((float)((float)(*v8 * *v9) + (float)((float)(v8[2] * v9[2]) + (float)(v8[1] * v9[1])))
                       * (float)0.056818184));
  }
  else
  {
    v10 = 0.0;
  }
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?RemoveFromEntityList@idNavPathPosTracker@@QAAXPAVidEntity@@@Z
// EA  : 0x82CC53B8
// RVA : 0x00CC53B8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::RemoveFromEntityList(idNavPathPosTracker *this, idEntity *entity)
{
  idNavSpline *navSpline; // r11
  int v5; // r31
  int v6; // r30
  idGameLocal *v7; // r10
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  idList<idEntityPtr<idEntity>,5> *p_entityList; // r10
  int num; // r11
  int v13; // r11

  navSpline = this->pathPosition.navSpline;
  if ( navSpline != nullptr && entity != nullptr )
  {
    v5 = 0;
    if ( navSpline->entityList.num > 0 )
    {
      v6 = 0;
      v7 = gameLocal;
      while ( 1 )
      {
        value = navSpline->entityList.list[v6].spawnId.value;
        if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v9 = v7->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v10 = idEntity::CastTo(c: v9);
          v7 = gameLocal;
        }
        else
        {
          v10 = nullptr;
        }
        navSpline = this->pathPosition.navSpline;
        if ( v10 == entity )
          break;
        ++v5;
        ++v6;
        if ( v5 >= navSpline->entityList.num )
          return;
      }
      p_entityList = &navSpline->entityList;
      if ( v5 >= 0 )
      {
        num = navSpline->entityList.num;
        if ( v5 < num )
        {
          v13 = num - 1;
          p_entityList->num = v13;
          if ( v5 != v13 )
            p_entityList->list[v5].spawnId.value = p_entityList->list[v13].spawnId.value;
        }
      }
    }
  }
}


// ========================================================================
// ?GetFacing@idNavPathPosTracker@@QAAMXZ
// EA  : 0x82CC54B0
// RVA : 0x00CC54B0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetFacing(idNavPathPosTracker *this)
{
  idEntity *v2; // r3
  idEntity *v3; // r31
  idEntity *BindMaster; // r3
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  idEntity *v8; // r3
  idPresentable *presentable; // r3
  float *v10; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  idEntity *v14; // r3
  idPhysics *Physics; // r3
  float *v16; // r3
  float rightDistance; // r10
  idNavSpline *navSpline; // r9
  float *Forward; // r3
  double v20; // fp1
  idVec3 v22; // [sp+50h] [-60h] BYREF
  idNavSplinePosition v23[2]; // [sp+60h] [-50h] BYREF

  if ( gameLocal->spawnIds.ptr[this->owner.spawnId.value & 0x1FFF] == this->owner.spawnId.value >> 13
    && (v2 = gameLocal->entities.ptr[this->owner.spawnId.value & 0x1FFF]) != nullptr )
  {
    v3 = idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  if ( idEntity::GetBindMaster(this: v3) != nullptr )
  {
    BindMaster = idEntity::GetBindMaster(this: v3);
    v5 = *(_DWORD *)(BindMaster->GetType(this: BindMaster) + 36);
    if ( v5 < idVehicle::Type.typeNum || (v7 = v5 <= idVehicle::Type.lastChild, v6 = 1, !v7) )
      v6 = 0;
    if ( v6 != 0 )
    {
      v8 = idEntity::GetBindMaster(this: v3);
LABEL_20:
      Physics = idEntity::GetPhysics(this: v8);
      v16 = (float *)Physics->GetAxis(this: Physics, a2: 0);
      v13 = v16[2];
      v12 = v16[1];
      v11 = *v16;
      goto LABEL_21;
    }
  }
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: v3) == 0 )
  {
    if ( gameLocal->spawnIds.ptr[this->owner.spawnId.value & 0x1FFF] == this->owner.spawnId.value >> 13
      && (v14 = gameLocal->entities.ptr[this->owner.spawnId.value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v14);
    }
    else
    {
      v8 = nullptr;
    }
    goto LABEL_20;
  }
  presentable = v3->presentable;
  if ( presentable != nullptr )
    v10 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v10 = nullptr;
  v11 = v10[11636];
  v12 = v10[11637];
  v13 = v10[11638];
LABEL_21:
  rightDistance = this->pathPosition.rightDistance;
  navSpline = this->pathPosition.navSpline;
  v22.x = this->pathPosition.distance;
  v22.y = rightDistance;
  LODWORD(v22.z) = navSpline;
  Forward = (float *)idNavSplinePosition::GetForward(this: v23, result: &v22);
  v20 = (float)((float)(*Forward * (float)v11)
              + (float)((float)(Forward[2] * (float)v13) + (float)(Forward[1] * (float)v12)));
  return *((float *)&v20 + 1);
}


// ========================================================================
// ?GetFacingDir@idNavPathPosTracker@@QAAMXZ
// EA  : 0x82CC5690
// RVA : 0x00CC5690
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetFacingDir(idNavPathPosTracker *this)
{
  double v1; // fp1

  if ( idNavPathPosTracker::GetFacing(this) <= 0.0 )
    v1 = -1.0;
  else
    v1 = 1.0;
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetVelFacing@idNavPathPosTracker@@QAAMXZ
// EA  : 0x82CC56E0
// RVA : 0x00CC56E0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetVelFacing(idNavPathPosTracker *this)
{
  idEntity *v2; // r3
  idEntity *v3; // r31
  idEntity *BindMaster; // r3
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  idEntity *v8; // r3
  idEntity *v9; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp29
  float rightDistance; // r10
  double v14; // fp30
  idNavSpline *navSpline; // r9
  double v16; // fp31
  float *Forward; // r3
  idVec3 v21; // [sp+50h] [-60h] BYREF
  idNavSplinePosition v22[2]; // [sp+60h] [-50h] BYREF

  if ( gameLocal->spawnIds.ptr[this->owner.spawnId.value & 0x1FFF] == this->owner.spawnId.value >> 13
    && (v2 = gameLocal->entities.ptr[this->owner.spawnId.value & 0x1FFF]) != nullptr )
  {
    v3 = idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  if ( idEntity::GetBindMaster(this: v3) == nullptr )
    goto LABEL_21;
  BindMaster = idEntity::GetBindMaster(this: v3);
  v5 = *(_DWORD *)(BindMaster->GetType(this: BindMaster) + 36);
  if ( v5 < idVehicle::Type.typeNum || (v7 = v5 <= idVehicle::Type.lastChild, v6 = 1, !v7) )
    v6 = 0;
  if ( v6 != 0 )
  {
    v8 = idEntity::GetBindMaster(this: v3);
  }
  else
  {
LABEL_21:
    if ( gameLocal->spawnIds.ptr[this->owner.spawnId.value & 0x1FFF] == this->owner.spawnId.value >> 13
      && (v9 = gameLocal->entities.ptr[this->owner.spawnId.value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v9);
    }
    else
    {
      v8 = nullptr;
    }
  }
  Physics = idEntity::GetPhysics(this: v8);
  v11 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)v22, result: (idVec3 *)Physics, a3: 0);
  v12 = v11[2];
  rightDistance = this->pathPosition.rightDistance;
  v14 = v11[1];
  navSpline = this->pathPosition.navSpline;
  v16 = *v11;
  v21.x = this->pathPosition.distance;
  v21.y = rightDistance;
  LODWORD(v21.z) = navSpline;
  Forward = (float *)idNavSplinePosition::GetForward(this: v22, result: &v21);
  _FP0 = (float)((float)(*Forward * (float)v16)
               + (float)((float)(Forward[2] * (float)v12) + (float)(Forward[1] * (float)v14)));
  if ( _FP0 <= 0.0 )
    __asm { fsel      f1, f0, f13, f12 }
  else
    _FP1 = 1.0;
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ??1idNavPathPosTracker@@QAA@XZ
// EA  : 0x82CC58B8
// RVA : 0x00CC58B8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::~idNavPathPosTracker(idNavPathPosTracker *this)
{
  idEntity *Owner; // r3

  Owner = idNavPathPosTracker::GetOwner(this);
  idNavPathPosTracker::RemoveFromEntityList(this, entity: Owner);
  `eh vector destructor iterator'(
    ptr: this->userPath,
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idFireParms::~idFireParms);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeUserPath.path);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pathToGoal.path);
}


// ========================================================================
// __unwind$489435
// EA  : 0x82CC592C
// RVA : 0x00CC592C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489435()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$489436
// EA  : 0x82CC5958
// RVA : 0x00CC5958
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489436()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// __unwind$489437_0
// EA  : 0x82CC5984
// RVA : 0x00CC5984
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489437_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 152),
    size: 0x20u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idFireParms::~idFireParms);
}


// ========================================================================
// ?ValidatePathPosition@idNavPathPosTracker@@QAA?AVidNavSplinePosition@@V2@@Z
// EA  : 0x82CC59C0
// RVA : 0x00CC59C0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idNavPathPosTracker::ValidatePathPosition(
        idNavPathPosTracker *this,
        __int64 splinePos,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  double v7; // fp31
  idNavSplinePosition *rightDistance_low; // r31
  idNavPathPosTracker *v10; // r29
  int *v11; // r11
  int v12; // r30
  idNavSplinePathMgr *v13; // r3
  __int64 v14; // r6
  idNavPathPosTracker *v15; // r3
  int *v17; // r11
  idNavSplinePathMgr *NavSplinePathMgr; // r3
  __int64 v19; // [sp+8h] [-98h]
  __int64 v20; // [sp+10h] [-90h]
  __int64 v21; // [sp+18h] [-88h]
  __int64 v22; // [sp+20h] [-80h]
  __int64 v23; // [sp+28h] [-78h]
  char v24; // [sp+50h] [-50h] BYREF
  __int64 v25; // [sp+C0h] [+20h]

  v25 = splinePos;
  v7 = *(float *)&splinePos;
  rightDistance_low = (idNavSplinePosition *)splinePos;
  v10 = (idNavPathPosTracker *)HIDWORD(splinePos);
  if ( *(float *)&splinePos <= (double)*(float *)(splinePos + 12) )
  {
    if ( v7 >= 0.0 )
      goto LABEL_13;
    if ( *(_DWORD *)(HIDWORD(splinePos) + 88) == 0 && *(_DWORD *)(splinePos + 40) != 0 )
    {
      v17 = *(int **)(splinePos + 36);
      a7 = *v17;
      *(_DWORD *)(HIDWORD(splinePos) + 88) = *v17;
    }
    v12 = *(_DWORD *)(HIDWORD(splinePos) + 88);
    if ( v12 == 0 )
      goto LABEL_15;
    NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(
                         this: gameLocal,
                         splineType: *(navSplineType_t *)(HIDWORD(splinePos) + 308));
    a7 = (unsigned __int8)idNavSplinePathMgr::MovingToStartOfSpline(
                            this: NavSplinePathMgr,
                            splinePos: rightDistance_low,
                            newNavSpline: nullptr,
                            a4: v12);
    if ( a7 != 0 )
      v7 = -v7;
    else
      v7 = (float)(*(float *)(v12 + 12) - (float)-v7);
  }
  else
  {
    if ( *(_DWORD *)(HIDWORD(splinePos) + 84) == 0 && *(_DWORD *)(splinePos + 24) != 0 )
    {
      v11 = *(int **)(splinePos + 20);
      a7 = *v11;
      *(_DWORD *)(HIDWORD(splinePos) + 84) = *v11;
    }
    v12 = *(_DWORD *)(HIDWORD(splinePos) + 84);
    if ( v12 == 0 )
    {
      v7 = *(float *)(splinePos + 12);
      *(float *)&v25 = *(float *)(splinePos + 12);
      goto LABEL_13;
    }
    v13 = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *(navSplineType_t *)(HIDWORD(splinePos) + 308));
    a7 = (unsigned __int8)idNavSplinePathMgr::MovingToStartOfSpline(
                            this: v13,
                            splinePos: rightDistance_low,
                            newNavSpline: nullptr,
                            a4: v12);
    if ( a7 != 0 )
      v7 = (float)((float)v7 - rightDistance_low[1].distance);
    else
      v7 = (float)(*(float *)(v12 + 12) - (float)((float)v7 - rightDistance_low[1].distance));
  }
  *(float *)&v25 = v7;
  if ( (idNavSplinePosition *)v12 == rightDistance_low )
  {
LABEL_13:
    if ( v7 >= 1000.0 && (float)(rightDistance_low[1].distance - (float)v7) >= 1000.0 )
      goto LABEL_16;
LABEL_15:
    LODWORD(v14) = 0;
    HIDWORD(v14) = v25;
    v15 = idNavPathPosTracker::ValidateIntersection(
            this: (idNavPathPosTracker *)&v24,
            result: v10,
            splinePos: v14,
            a4,
            a5,
            a6,
            a7,
            a8: v19,
            a9: v20,
            a10: v21,
            a11: v22,
            a12: v23);
    rightDistance_low = (idNavSplinePosition *)LODWORD(v15->pathPosition.rightDistance);
    v25 = *(_QWORD *)&v15->owner.spawnId.value;
    goto LABEL_16;
  }
  rightDistance_low = (idNavSplinePosition *)v12;
  if ( v7 >= 0.0 )
  {
    if ( v7 > *(float *)(v12 + 12) )
      *(float *)&v25 = *(float *)(v12 + 12);
  }
  else
  {
    *(float *)&v25 = 0.0;
  }
LABEL_16:
  LODWORD(this->pathPosition.rightDistance) = rightDistance_low;
  *(_QWORD *)&this->owner.spawnId.value = v25;
  return this;
}


// ========================================================================
// ?GetMoveAheadDist@idNavPathPosTracker@@QAAMPAV1@@Z
// EA  : 0x82CC5BA8
// RVA : 0x00CC5BA8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

float __fastcall idNavPathPosTracker::GetMoveAheadDist(idNavPathPosTracker *this, idNavPathPosTracker *otherTracker)
{
  idEntity *v4; // r3
  idPhysics *v5; // r3
  double v6; // fp30
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  double v9; // fp0
  double v10; // fp30
  double v11; // fp1
  idVec3 v13; // [sp+50h] [-50h] BYREF
  float v14[4]; // [sp+60h] [-40h] BYREF

  if ( idNavPathPosTracker::GetOwner(this) != nullptr
    && idNavPathPosTracker::GetOwner(this: otherTracker) != nullptr
    && (v4 = idNavPathPosTracker::GetOwner(this: otherTracker),
        v5 = idEntity::GetPhysics(this: v4),
        v5->GetLinearVelocity(this: (idPhysics *)&v13, result: (idVec3 *)v5, a3: 0),
        (v6 = (float)(idVec3::NormalizeFast(this: &v13) * (float)0.056818184)) >= 10.0) )
  {
    Owner = idNavPathPosTracker::GetOwner(this);
    Physics = idEntity::GetPhysics(this: Owner);
    Physics->GetLinearVelocity(this: (idPhysics *)v14, result: (idVec3 *)Physics, a3: 0);
    v9 = (float)((float)((float)(v13.z * v14[2]) + (float)((float)(v14[1] * v13.y) + (float)(v13.x * v14[0])))
               * 0.056818184);
    if ( v9 < 0.0 )
      v9 = 0.0;
    v10 = (float)((float)((float)v6 - (float)v9) * (float)((float)v6 * (float)0.69999999));
    if ( v10 >= 0.0 )
    {
      if ( idNavPathPosTracker::GetVelFacing(this: otherTracker) < 0.0 )
        v10 = -v10;
      v11 = v10;
    }
    else
    {
      v11 = 0.0;
    }
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ??0idNavPathPosTracker@@QAA@XZ
// EA  : 0x82CC5D18
// RVA : 0x00CC5D18
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::idNavPathPosTracker(idNavPathPosTracker *this)
{
  this->owner.spawnId.value = 0x1FFF;
  this->pathPosition.navSpline = nullptr;
  this->pathPosition.distance = 0.0;
  this->pathPosition.rightDistance = 0.0;
  this->goalPathPosition.navSpline = nullptr;
  this->goalPathPosition.distance = 0.0;
  this->goalPathPosition.rightDistance = 0.0;
  navSplinePath_t::navSplinePath_t(this: &this->pathToGoal);
  navSplinePath_t::navSplinePath_t(this: &this->activeUserPath);
  `eh vector constructor iterator'(
    ptr: this->userPath,
    size: 0x20u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))navSplinePath_t::navSplinePath_t,
    pDtor: (void (__fastcall *)(void *))idFireParms::~idFireParms);
  this->navSplineType = NAV_SPLINE_TYPE_DEFAULT;
  idNavPathPosTracker::Init(this);
}


// ========================================================================
// __unwind$489598_0
// EA  : 0x82CC5DB0
// RVA : 0x00CC5DB0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489598_0()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$489599_0
// EA  : 0x82CC5DDC
// RVA : 0x00CC5DDC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489599_0()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 128 + 148) + 116));
}


// ========================================================================
// ?DetermineRandomLinks@idNavPathPosTracker@@QAAXPAVidNavSpline@@PAPAV2@1@Z
// EA  : 0x82CC5E10
// RVA : 0x00CC5E10
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::DetermineRandomLinks(
        idNavPathPosTracker *this,
        idVec3 *curspline,
        idNavSpline **nextSpline,
        idNavSpline **prevSpline)
{
  int v7; // r29
  int v8; // r30
  idNavSpline *v9; // r4
  idNavSplinePath *splinePath; // r10
  char v11; // r11
  char v12; // r11
  float *Forward; // r3
  int size; // r10
  _DWORD *num; // r30
  idClientGame *v16; // r11
  unsigned int v17; // r7
  int v18; // r5
  idNavSpline *v19; // r3
  int y_low; // r11
  int v21; // r29
  int v22; // r30
  idNavSpline *v23; // r4
  idNavSplinePath *v24; // r10
  char v25; // r11
  char v26; // r11
  float *v27; // r3
  int v28; // r10
  idClientGame *v29; // r11
  unsigned int v30; // r7
  int v31; // r5
  encounterGroupRole_t v32[2]; // [sp+50h] [-A0h] BYREF
  idNavSpline v33; // [sp+58h] [-98h] BYREF

  if ( curspline != nullptr )
  {
    memset(&v33.prev.num, 0, 12);
    v33.entityList.list = (idEntityPtr<idEntity> *)1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v33.prev.num);
    idNavSpline::GetForward(this: &v33, result: curspline, distance: curspline[1].x);
    v7 = 0;
    if ( SLODWORD(curspline[2].x) > 0 )
    {
      v8 = 0;
      do
      {
        v9 = *(idNavSpline **)(v8 + LODWORD(curspline[1].z));
        splinePath = v9->splinePath;
        v32[0] = (encounterGroupRole_t)v9;
        if ( (*(_BYTE *)&splinePath->splineFlags & 0x40) != 0
          || (v11 = 0, (*(_BYTE *)&splinePath->splineFlags & 0x20) != 0) )
        {
          v11 = 1;
        }
        if ( v11 != 0 )
        {
          if ( v9->startNode == nullptr || (v12 = 1, v9->endNode == nullptr) )
            v12 = 0;
          if ( v12 != 0 )
          {
            Forward = (float *)idNavSpline::GetForward(
                                 this: (idNavSpline *)&v33.traversed,
                                 result: (idVec3 *)v9,
                                 distance: 0.0);
            if ( (float)((float)(*(float *)&v33.splinePath * *Forward)
                       + (float)((float)(v33.width * Forward[2]) + (float)(*(float *)&v33.curve * Forward[1]))) > 0.0 )
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&v33.prev.num,
                obj: v32);
          }
        }
        ++v7;
        v8 += 16;
      }
      while ( v7 < SLODWORD(curspline[2].x) );
    }
    size = v33.prev.size;
    num = (_DWORD *)v33.prev.num;
    if ( v33.prev.size != 0 )
    {
      v16 = clientGame;
      __twllei(v33.prev.size, 0);
      v17 = 1664525 * v16->random.seed + 1013904223;
      v16->random.seed = v17;
      v18 = (v17 >> 10) & 0x7FFF;
      __twlgei(size & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
      *nextSpline = (idNavSpline *)num[v18 % size];
    }
    else
    {
      *nextSpline = nullptr;
    }
    if ( LOBYTE(v33.entityList.list) == 0 || LOBYTE(v33.entityList.list) == 2 )
    {
      if ( num != nullptr )
        idMem::Free(this: &mem, ptr: num, align: ALIGN_16);
      num = nullptr;
      *(_DWORD *)&v33.prev.granularity = 0;
      v33.prev.num = 0;
    }
    v33.prev.size = 0;
    v19 = idNavSpline::GetForward(this: (idNavSpline *)&v33.traversed, result: curspline, distance: 0.0);
    v33.splinePath = v19->splinePath;
    y_low = LODWORD(curspline[3].y);
    v21 = 0;
    v33.curve = v19->curve;
    v33.width = v19->width;
    if ( y_low <= 0 )
      goto LABEL_39;
    v22 = 0;
    do
    {
      v23 = *(idNavSpline **)(v22 + LODWORD(curspline[3].x));
      v24 = v23->splinePath;
      v32[0] = (encounterGroupRole_t)v23;
      if ( (*(_BYTE *)&v24->splineFlags & 0x40) != 0 || (v25 = 0, (*(_BYTE *)&v24->splineFlags & 0x20) != 0) )
        v25 = 1;
      if ( v25 != 0 )
      {
        if ( v23->startNode == nullptr || (v26 = 1, v23->endNode == nullptr) )
          v26 = 0;
        if ( v26 != 0 )
        {
          v27 = (float *)idNavSpline::GetForward(
                           this: (idNavSpline *)&v33.traversed,
                           result: (idVec3 *)v23,
                           distance: v23->length);
          if ( (float)((float)(*(float *)&v33.splinePath * *v27)
                     + (float)((float)(v33.width * v27[2]) + (float)(*(float *)&v33.curve * v27[1]))) > 0.0 )
            idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v33.prev.num, obj: v32);
        }
      }
      ++v21;
      v22 += 16;
    }
    while ( v21 < SLODWORD(curspline[3].y) );
    v28 = v33.prev.size;
    num = (_DWORD *)v33.prev.num;
    if ( v33.prev.size != 0 )
    {
      v29 = clientGame;
      __twllei(v33.prev.size, 0);
      v30 = 1664525 * v29->random.seed + 1013904223;
      v29->random.seed = v30;
      v31 = (v30 >> 10) & 0x7FFF;
      __twlgei(v28 & ~(__ROL4__(v31, 1) - 1), 0xFFFFFFFF);
      *prevSpline = (idNavSpline *)num[v31 % v28];
    }
    else
    {
LABEL_39:
      *prevSpline = nullptr;
    }
    if ( (LOBYTE(v33.entityList.list) == 0 || LOBYTE(v33.entityList.list) == 2) && num != nullptr )
      idMem::Free(this: &mem, ptr: num, align: ALIGN_16);
  }
  else
  {
    *nextSpline = nullptr;
    *prevSpline = nullptr;
  }
}


// ========================================================================
// __unwind$489668_0
// EA  : 0x82CC61AC
// RVA : 0x00CC61AC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void _unwind_489668_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 128));
}


// ========================================================================
// ?DetermineLinks@idNavPathPosTracker@@QAAXXZ
// EA  : 0x82CC61D8
// RVA : 0x00CC61D8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::DetermineLinks(idNavPathPosTracker *this)
{
  navSplinePathNode_t *startNode; // r29
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v5; // r3
  idNavSpline *navSpline; // r11
  navPathTraversal_t pathTraversalType; // r11
  idNavSpline *v8; // r11
  idEntity *v9; // r3
  idPhysics *v10; // r3
  navSplinePath_t::path_t *v11; // r11
  double dir; // fp13
  idNavSpline *v13; // r11
  idNavSpline **p_prevSpline; // r5
  idNavSpline **p_nextSpline; // r4
  idNavSpline *v16; // r11
  navSplinePath_t::path_t *list; // r11
  idNavSpline *v18; // r10
  idNavSpline *v19; // r11
  idNavSpline *v20; // r11
  idNavSpline *v21; // r11
  float x; // [sp+50h] [-40h]
  float y; // [sp+54h] [-3Ch]
  float z; // [sp+58h] [-38h]
  char v25; // [sp+60h] [-30h] BYREF

  startNode = nullptr;
  if ( idNavPathPosTracker::GetOwner(this) != nullptr
    && (unsigned __int8)navSplinePath_t::IsSingleSpline(this: &this->pathToGoal) == 0 )
  {
    Owner = idNavPathPosTracker::GetOwner(this);
    Physics = idEntity::GetPhysics(this: Owner);
    x = this->forward.x;
    y = this->forward.y;
    z = this->forward.z;
    v5 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v25, result: (idVec3 *)Physics, a3: 0);
    navSpline = this->pathPosition.navSpline;
    if ( (float)((float)(*v5 * x) + (float)((float)(v5[1] * y) + (float)(v5[2] * z))) <= 0.0 )
      startNode = navSpline->startNode;
    else
      startNode = navSpline->endNode;
  }
  if ( startNode != this->lastGoalNode || this->pathPosition.navSpline != this->lastNavSpline )
  {
    pathTraversalType = this->pathTraversalType;
    if ( pathTraversalType == NAVSP_RANDOM )
    {
      idNavPathPosTracker::DetermineRandomLinks(
        this,
        curspline: (idVec3 *)this->pathPosition.navSpline,
        nextSpline: &this->nextSpline,
        prevSpline: &this->prevSpline);
      v8 = this->pathPosition.navSpline;
      this->lastGoalNode = startNode;
      this->lastNavSpline = v8;
      return;
    }
    if ( pathTraversalType != NAVSP_SHORTEST )
    {
      if ( pathTraversalType == NAVSP_USERDEFINED )
      {
        list = this->activeUserPath.path.list;
        this->prevSpline = nullptr;
        v18 = list[1].navSpline;
        v19 = this->pathPosition.navSpline;
        this->nextSpline = v18;
        this->lastGoalNode = startNode;
        this->lastNavSpline = v19;
        return;
      }
      if ( pathTraversalType == NAVSP_USERCONTROL )
      {
        v20 = this->pathPosition.navSpline;
        this->nextSpline = v20->bestNext;
        this->prevSpline = v20->bestPrev;
      }
      goto LABEL_27;
    }
    if ( idNavPathPosTracker::GetOwner(this) != nullptr )
    {
      v9 = idNavPathPosTracker::GetOwner(this);
      v10 = idEntity::GetPhysics(this: v9);
      v10->GetAxis(this: v10, a2: 0);
    }
    if ( (unsigned __int8)navSplinePath_t::IsSingleSpline(this: &this->pathToGoal) != 0 )
    {
      this->prevSpline = nullptr;
    }
    else
    {
      v11 = this->pathToGoal.path.list;
      dir = v11->dir;
      v13 = v11[1].navSpline;
      if ( dir == 1.0 )
      {
        this->prevSpline = nullptr;
        this->nextSpline = v13;
LABEL_19:
        p_prevSpline = &this->prevSpline;
        p_nextSpline = &this->nextSpline;
        if ( this->canChooseSimilarSplit && (*p_prevSpline != nullptr || *p_nextSpline != nullptr) )
        {
          idNavPathPosTracker::ChooseSimilarSplit(this, nextSpline: p_nextSpline, prevSpline: p_prevSpline);
          v16 = this->pathPosition.navSpline;
          this->lastGoalNode = startNode;
          this->lastNavSpline = v16;
          return;
        }
LABEL_27:
        v21 = this->pathPosition.navSpline;
        this->lastGoalNode = startNode;
        this->lastNavSpline = v21;
        return;
      }
      this->prevSpline = v13;
    }
    this->nextSpline = nullptr;
    goto LABEL_19;
  }
}


// ========================================================================
// ?SetPathTraversal@idNavPathPosTracker@@QAAXW4navPathTraversal_t@@_N@Z
// EA  : 0x82CC6410
// RVA : 0x00CC6410
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetPathTraversal(
        idNavPathPosTracker *this,
        navPathTraversal_t traversalType,
        bool forceRecalcLinks)
{
  if ( forceRecalcLinks || this->pathTraversalType != traversalType )
  {
    this->pathTraversalType = traversalType;
    idNavPathPosTracker::DetermineLinks(this);
  }
}


// ========================================================================
// ?AddToEntityList@idNavPathPosTracker@@QAAXPAVidEntity@@@Z
// EA  : 0x82CC6438
// RVA : 0x00CC6438
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::AddToEntityList(idNavPathPosTracker *this, idEntity *entity)
{
  idNavSpline *navSpline; // r11

  if ( entity != nullptr )
  {
    navSpline = this->pathPosition.navSpline;
    if ( navSpline != nullptr )
      idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&navSpline->entityList)->spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  }
}


// ========================================================================
// ?SetNavSpline@idNavPathPosTracker@@QAAXPAVidNavSpline@@MPAVidEntity@@@Z
// EA  : 0x82CC64A0
// RVA : 0x00CC64A0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetNavSpline(
        idNavPathPosTracker *this,
        idNavSpline *navSpline,
        double distance,
        idEntity *owner,
        int a5)
{
  idEntity *v9; // r3
  idEntity *v10; // r3
  idNavSpline *v11; // r29
  float v12; // [sp+50h] [-60h]
  float v13; // [sp+54h] [-5Ch]
  float v14; // [sp+60h] [-50h]
  float rightDistance; // [sp+64h] [-4Ch]

  if ( a5 != 0 )
    this->owner.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(a5 + 492)] << 13) | *(_DWORD *)(a5 + 492);
  else
    this->owner.spawnId.value = 0x1FFF;
  if ( navSpline == this->pathPosition.navSpline )
  {
    this->pathPosition.distance = distance;
  }
  else
  {
    v9 = idNavPathPosTracker::GetOwner(this);
    idNavPathPosTracker::RemoveFromEntityList(this, entity: v9);
    if ( a5 != 0 )
      this->owner.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(a5 + 492)] << 13) | *(_DWORD *)(a5 + 492);
    else
      this->owner.spawnId.value = 0x1FFF;
    this->pathPosition.distance = distance;
    this->pathPosition.navSpline = navSpline;
    v10 = idNavPathPosTracker::GetOwner(this);
    idNavPathPosTracker::AddToEntityList(this, entity: v10);
    v14 = this->goalPathPosition.distance;
    rightDistance = this->goalPathPosition.rightDistance;
    v12 = this->pathPosition.distance;
    v13 = this->pathPosition.rightDistance;
    v11 = this->goalPathPosition.navSpline;
    idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType);
    idNavSplinePathMgr::GetShortestPath(
      this: (idNavSplinePathMgr *)LODWORD(v12),
      start: (idNavSpline *)LODWORD(v13),
      end: (idNavSplinePosition *)LODWORD(v14),
      path: (idNavSplinePosition *)LODWORD(rightDistance),
      a5: __ROL4__(v11, 32),
      a6: &this->pathToGoal);
    idNavPathPosTracker::DetermineLinks(this);
  }
}


// ========================================================================
// ?SetPathPosition@idNavPathPosTracker@@QAAXVidNavSplinePosition@@@Z
// EA  : 0x82CC65D8
// RVA : 0x00CC65D8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetPathPosition(idNavPathPosTracker *this, idNavSpline *pathpos)
{
  int v3; // r11
  idEntity *v4; // r5
  idEntity *v5; // r3
  idEntity *v6; // r6

  v3 = this->owner.spawnId.value & 0x1FFF;
  v4 = (idEntity *)gameLocal->spawnIds.ptr[v3];
  if ( v4 == (idEntity *)(this->owner.spawnId.value >> 13) && (v5 = gameLocal->entities.ptr[v3]) != nullptr )
    v6 = idEntity::CastTo(c: v5);
  else
    v6 = nullptr;
  idNavPathPosTracker::SetNavSpline(this, navSpline: pathpos, distance: *(float *)&this, owner: v4, a5: (int)v6);
}


// ========================================================================
// ?SetWorldPosition@idNavPathPosTracker@@QAAXVidVec3@@PAVidNavSpline@@@Z
// EA  : 0x82CC6668
// RVA : 0x00CC6668
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idNavPathPosTracker::SetWorldPosition(
        idNavPathPosTracker *this,
        idVec3 *position,
        idNavSpline *gs,
        int a4)
{
  int v4; // r3
  int v5; // r31
  idNavPathPosTracker *v7; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp9
  double v14; // fp3
  double v15; // fp6
  double v16; // fp3
  idNavSplinePathMgr *NavSplinePathMgr; // r3
  int v18; // r3
  idVec3 v19; // [sp+70h] [-40h] BYREF
  idPhysics v20; // [sp+80h] [-30h] BYREF
  __int64 v21; // [sp+D0h] [+20h]

  v5 = v4;
  v21 = *(_QWORD *)&position;
  if ( *(_BYTE *)(v4 + 297) != 0 )
  {
    Owner = idNavPathPosTracker::GetOwner(this: v7);
    Physics = idEntity::GetPhysics(this: Owner);
    v10 = (float *)Physics->GetLinearVelocity(this: &v20, result: (idVec3 *)Physics, a3: 0);
    v19.x = *v10;
    v19.y = v10[1];
    v11 = v10[2];
    _FP6 = (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f11 }
    v14 = __frsqrte(_FP4);
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x)))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)((float)((float)(v19.y * v19.y)
                                                                + (float)((float)(v10[2] * v10[2])
                                                                        + (float)(v19.x * v19.x)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                * (float)((float)((float)(v19.y * v19.y)
                                                                                                + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x)))
                                                                                        * (float)0.5))
                                                                        * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14
                                                        * (float)((float)((float)(v19.y * v19.y)
                                                                        + (float)((float)(v10[2] * v10[2])
                                                                                + (float)(v19.x * v19.x)))
                                                                * (float)0.5))
                                                * (float)v14)
                                        - (float)1.5)
                        * (float)v14));
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                                * (float)v14)
                                                                                        * (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                        * (float)v14))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                                * (float)((float)((float)(v19.y * v19.y) + (float)((float)(v10[2] * v10[2]) + (float)(v19.x * v19.x))) * (float)0.5))
                                                                                        * (float)v14)
                                                                                - (float)1.5)
                                                                * (float)v14))
                                                * (float)((float)((float)(v19.y * v19.y)
                                                                + (float)((float)(v10[2] * v10[2])
                                                                        + (float)(v19.x * v19.x)))
                                                        * (float)0.5))
                                        * (float)v15)
                                - (float)1.5)
                * (float)v15);
    v19.x = (float)v16 * v19.x;
    v19.y = (float)v16 * v19.y;
    v19.z = (float)v11 * (float)v16;
  }
  else
  {
    v19.x = vec3_origin.x;
    v19.y = vec3_origin.y;
    v19.z = vec3_origin.z;
  }
  *(_QWORD *)(v5 + 16) = v21;
  *(float *)(v5 + 24) = *(float *)&position;
  NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *(navSplineType_t *)(v5 + 308));
  v18 = ((int (__fastcall *)(idPhysics *, idNavSplinePathMgr *, _DWORD, _DWORD, int, double, double))LODWORD(v19.x))(
          a1: &v20,
          a2: NavSplinePathMgr,
          a3: *(_DWORD *)(v5 + 20),
          a4: __ROL4__(*(_DWORD *)(v5 + 24), 32),
          a5: a4,
          a6: *(float *)(*(_DWORD *)(v5 + 16) - 30392),
          a7: 0.1);
  idNavPathPosTracker::SetPathPosition(this: *(idNavPathPosTracker **)v18, pathpos: *(idNavSpline **)(v18 + 4));
  idNavSplinePosition::GetVectors(this: (idNavSplinePosition *)(v5 + 4), forward: &v19, right: (idVec3 *)(v5 + 104));
}


// ========================================================================
// ?SetWorldPosition@idNavPathPosTracker@@QAAXVidVec3@@VidNavSplinePosition@@@Z
// EA  : 0x82CC6808
// RVA : 0x00CC6808
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::SetWorldPosition(
        idNavPathPosTracker *this,
        idVec3 *pos,
        idNavSplinePosition *splineDistance,
        idNavSpline *a4)
{
  this->worldPosition.x = *(float *)&this;
  this->worldPosition.y = *(float *)&pos;
  this->worldPosition.z = *(float *)&pos;
  idNavPathPosTracker::SetPathPosition(this, pathpos: a4);
}


// ========================================================================
// ?UpdatePosition@idNavPathPosTracker@@QAAXXZ
// EA  : 0x82CC6858
// RVA : 0x00CC6858
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::UpdatePosition(idNavPathPosTracker *this)
{
  double v2; // fp12
  double v3; // fp8
  double v4; // fp4
  __int128 v5; // r6
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  float rightDistance; // r9
  idNavSpline *navSpline; // r8
  char v12; // r11
  float *SplineWorldPos; // r3
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  float *Right; // r3
  int v18; // [sp+8h] [-C8h]
  idVec3 v19; // [sp+50h] [-80h] BYREF
  idVec3 v20; // [sp+60h] [-70h] BYREF
  idVec3 v21; // [sp+70h] [-60h] BYREF
  idNavSplinePosition v22; // [sp+80h] [-50h] BYREF
  idNavSplinePosition v23; // [sp+90h] [-40h] BYREF

  if ( spl_gen_updateTracker.valueInteger != 0 )
  {
    idNavSplinePosition::GetWorldPositionAndForward(this: &this->pathPosition, pos: &v20, forward: &v21);
    v2 = (float)(this->worldPosition.y - v20.y);
    v3 = (float)(this->worldPosition.z - v20.z);
    v4 = (float)(this->worldPosition.x - v20.x);
    this->pathPosition.distance = (float)((float)((float)(this->worldPosition.x - v20.x) * v21.x)
                                        + (float)((float)(v21.z * (float)(this->worldPosition.z - v20.z))
                                                + (float)(v21.y * (float)(this->worldPosition.y - v20.y))))
                                + this->pathPosition.distance;
    LODWORD(v5) = __ROL4__(this->pathPosition.navSpline, 32);
    this->pathPosition.rightDistance = (float)(this->right.x * (float)v4)
                                     + (float)((float)(this->right.z * (float)v3) + (float)(this->right.y * (float)v2));
    *(_QWORD *)((char *)&v5 + 4) = *(_QWORD *)&this->pathPosition.distance;
    idNavPathPosTracker::ValidatePathPosition(
      this: (idNavPathPosTracker *)&v19,
      splinePos: v5,
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v18);
    rightDistance = this->pathPosition.rightDistance;
    navSpline = this->pathPosition.navSpline;
    v22.distance = this->pathPosition.distance;
    v22.rightDistance = rightDistance;
    if ( (idNavSpline *)LODWORD(v19.z) != navSpline || (v12 = 0, __fabs((float)(v19.x - v22.distance)) > 0.1) )
      v12 = 1;
    if ( v12 != 0 )
    {
      SplineWorldPos = (float *)idNavSplinePosition::GetSplineWorldPos(this: &v22, result: &v19);
      v14 = (float)(this->worldPosition.x - *SplineWorldPos);
      v15 = (float)(this->worldPosition.y - SplineWorldPos[1]);
      v16 = (float)(this->worldPosition.z - SplineWorldPos[2]);
      Right = (float *)idNavSplinePosition::GetRight(this: &v23, result: &v19);
      v19.y = (float)(*Right * (float)v14) + (float)((float)(Right[2] * (float)v16) + (float)(Right[1] * (float)v15));
    }
    idNavPathPosTracker::SetPathPosition(
      this: (idNavPathPosTracker *)LODWORD(v19.x),
      pathpos: (idNavSpline *)LODWORD(v19.y));
  }
}


// ========================================================================
// ?Init@idNavPathPosTracker@@QAAXPAVidNavSpline@@W4navSplineType_t@@PAVidEntity@@@Z
// EA  : 0x82CC6A08
// RVA : 0x00CC6A08
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::Init(
        idNavPathPosTracker *this,
        idNavSpline *gs,
        idEntity *splineType,
        idEntity *owner)
{
  idPhysics *Physics; // r3
  idNavSpline *navSpline; // r30
  int v8; // r3
  __int64 v9; // r4
  idNavSpline *v10; // r9
  float y; // [sp+54h] [-3Ch]
  float z; // [sp+58h] [-38h]

  this->goalPathPosition.navSpline = gs;
  this->navSplineType = (navSplineType_t)splineType;
  this->goalPathPosition.distance = 0.0;
  this->goalPathPosition.rightDistance = 0.0;
  this->pathPosition.distance = 0.0;
  idNavPathPosTracker::SetNavSpline(this, navSpline: gs, distance: 0.0, owner: splineType, a5: (int)owner);
  if ( this->pathPosition.navSpline == nullptr )
    idLib::Error(fmt: "idNavPathPosTracker Init(): Spline path not found!");
  if ( owner != nullptr )
  {
    if ( (unsigned __int8)idPlayer::IsTypeOf(c: owner) != 0 && this->pathTraversalType != NAVSP_USERCONTROL )
    {
      this->pathTraversalType = NAVSP_USERCONTROL;
      idNavPathPosTracker::DetermineLinks(this);
    }
    Physics = idEntity::GetPhysics(this: owner);
    navSpline = this->pathPosition.navSpline;
    v8 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    idNavPathPosTracker::SetWorldPosition(
      this: *(idNavPathPosTracker **)v8,
      position: *(idVec3 **)(v8 + 4),
      gs: (idNavSpline *)__ROL4__(*(_DWORD *)(v8 + 8), 32),
      a4: (int)navSpline);
    z = this->worldPosition.z;
    y = this->worldPosition.y;
    v9 = *(_QWORD *)&this->pathPosition.distance;
    v10 = this->pathPosition.navSpline;
    this->goalWorldPosition.x = this->worldPosition.x;
    this->goalWorldPosition.y = y;
    this->goalWorldPosition.z = z;
    idNavPathPosTracker::SetGoalPathPosition(
      this: (idNavPathPosTracker *)HIDWORD(v9),
      pathPos: (idNavSpline *)v9,
      doPathSearch: __ROL4__(v10, 32),
      a4: 1);
  }
  idNavPathPosTracker::UpdatePosition(this);
}


// ========================================================================
// ?Update@idNavPathPosTracker@@QAAX_N@Z
// EA  : 0x82CC6B48
// RVA : 0x00CC6B48
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::Update(idNavPathPosTracker *this, const bool fullUpdate)
{
  idNavSplinePathMgr *NavSplinePathMgr; // r30
  __int64 v5; // r3
  idNavSpline *navSpline; // r11
  char allowSplineJumping; // r29
  idNavSplinePath *splinePath; // r11
  idEntity *Owner; // r3
  idVec3 *p_lastRecalcPosition; // r11
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  idPhysics *Physics; // r3
  int v15; // r3
  idPhysics *v16; // r3
  int v17; // r3

  NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: NAV_SPLINE_TYPE_VEHICLE_AI);
  NavSplinePathMgr->navSplineTrackerTimer.state = TS_STARTED;
  LODWORD(v5) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  NavSplinePathMgr->navSplineTrackerTimer.start = v5;
  idNavSplinePosition::GetVectors(this: &this->pathPosition, forward: &this->forward, right: &this->right);
  navSpline = this->pathPosition.navSpline;
  allowSplineJumping = this->allowSplineJumping;
  if ( navSpline != nullptr )
  {
    splinePath = navSpline->splinePath;
    if ( splinePath != nullptr )
      allowSplineJumping = (*(_BYTE *)&splinePath->splineFlags & 1) == 0 ? 0 : allowSplineJumping;
  }
  Owner = idNavPathPosTracker::GetOwner(this);
  p_lastRecalcPosition = &this->lastRecalcPosition;
  v11 = (float)(this->lastRecalcPosition.x - this->worldPosition.x);
  v12 = (float)(this->lastRecalcPosition.y - this->worldPosition.y);
  v13 = (float)(this->lastRecalcPosition.z - this->worldPosition.z);
  if ( this->navSplineType == NAV_SPLINE_TYPE_QUEST )
  {
    if ( Owner != nullptr
      && (float)((float)((float)v11 * (float)v11)
               + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) > 1.0 )
    {
      p_lastRecalcPosition->x = this->worldPosition.x;
      this->lastRecalcPosition.y = this->worldPosition.y;
      this->lastRecalcPosition.z = this->worldPosition.z;
      Physics = idEntity::GetPhysics(this: Owner);
      v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      idNavPathPosTracker::SetWorldPosition(
        this: *(idNavPathPosTracker **)v15,
        position: *(idVec3 **)(v15 + 4),
        gs: (idNavSpline *)__ROL4__(*(_DWORD *)(v15 + 8), 32),
        a4: 0);
      ++NavSplinePathMgr->navSplineTrackerCount;
    }
  }
  else
  {
    if ( fullUpdate
      && allowSplineJumping != 0
      && Owner != nullptr
      && (float)((float)((float)v11 * (float)v11)
               + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) > (double)(float)(spl_updateTracker_distance.valueFloat * spl_updateTracker_distance.valueFloat) )
    {
      p_lastRecalcPosition->x = this->worldPosition.x;
      this->lastRecalcPosition.y = this->worldPosition.y;
      this->lastRecalcPosition.z = this->worldPosition.z;
      v16 = idEntity::GetPhysics(this: Owner);
      v17 = (int)v16->GetOrigin(this: v16, a2: 0);
      idNavPathPosTracker::SetWorldPosition(
        this: *(idNavPathPosTracker **)v17,
        position: *(idVec3 **)(v17 + 4),
        gs: (idNavSpline *)__ROL4__(*(_DWORD *)(v17 + 8), 32),
        a4: 0);
      ++NavSplinePathMgr->navSplineTrackerCount;
    }
    if ( (float)((float)((float)v11 * (float)v11)
               + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) > 0.1 )
      idNavPathPosTracker::UpdatePosition(this);
  }
  idTimer::Stop(this: &NavSplinePathMgr->navSplineTrackerTimer);
}


// ========================================================================
// ?Init@idNavPathPosTracker@@QAAXPADPAVidEntity@@@Z
// EA  : 0x82CC6D68
// RVA : 0x00CC6D68
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __fastcall idNavPathPosTracker::Init(idNavPathPosTracker *this, char *pathName, idEntity *owner)
{
  idNavSpline *NavSpline; // r30
  int v7; // r4
  idNavSplinePathMgr *v8; // r3
  idPhysics *Physics; // r30
  idNavSplinePathMgr *NavSplinePathMgr; // r29
  idPhysics *v11; // r3
  idNavSplinePathMgr_vtbl *v12; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  _DWORD *v14; // r3
  _BYTE v15[8]; // [sp+70h] [-40h] BYREF
  idNavSpline *v16; // [sp+78h] [-38h]

  idNavPathPosTracker::Init(this);
  NavSpline = nullptr;
  if ( v7 == 0
    || gameLocal != nullptr
    && (v8 = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType),
        (NavSpline = idNavSplinePathMgr::GetNavSpline(this: v8, splineName: pathName)) == nullptr) )
  {
    if ( gameLocal != nullptr && owner != nullptr && idEntity::GetPhysics(this: owner) != nullptr )
    {
      Physics = idEntity::GetPhysics(this: owner);
      NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: this->navSplineType);
      v11 = Physics;
      GetOrigin = Physics->GetOrigin;
      v12 = NavSplinePathMgr->__vftable;
      v14 = (_DWORD *)GetOrigin(this: v11, a2: 0);
      ((void (__fastcall *)(_BYTE *, _DWORD, _DWORD, _DWORD, _DWORD, idNavSplinePosition *(__fastcall *)(idNavSplinePathMgr *, idNavSplinePosition *, idVec3 *__struct_ptr, idNavSpline *, float, float, idVec3 *__struct_ptr, bool), _DWORD, _DWORD, double, double))v12->GetClosestPathPosition)(
        a1: v15,
        a2: *v14,
        a3: v14[1],
        a4: __ROL4__(v14[2], 32),
        a5: 0,
        a6: v12->GetClosestPathPosition,
        a7: v14[2],
        a8: LODWORD(vec3_origin.y),
        a9: 3000.0,
        a10: 0.1);
      NavSpline = v16;
    }
  }
  idNavPathPosTracker::Init(this, gs: NavSpline, splineType: (idEntity *)this->navSplineType, owner);
}


// ========================================================================
// `dynamic initializer for 'spl_gen_updateTracker''
// EA  : 0x83379080
// RVA : 0x01379080
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathtracker.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_gen_updateTracker__()
{
  idCVar::idCVar(
    this: &spl_gen_updateTracker,
    name: "spl_gen_updateTracker",
    value: "1",
    flags: 1,
    description: "Spline tracker is updated between recalcs.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_gen_updateTracker__);
}

