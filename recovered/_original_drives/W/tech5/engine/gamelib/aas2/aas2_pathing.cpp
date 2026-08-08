
// ========================================================================
// ?GetTraversalsForReachability@idAAS2Local@@UBAHV?$idIndex@FW4invalidReachability_t@@@@AAV?$idList@H$04@@@Z
// EA  : 0x826B1DD0
// RVA : 0x006B1DD0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

int __fastcall idAAS2Local::GetTraversalsForReachability(
        idAAS2Local *this,
        const idIndex<short,enum invalidReachability_t> *reachIndex,
        idList<idVehicleState *,5> *traversalList)
{
  return idAAS2File::GetTraversalsForReachability(this: this->file, reachIndex, traversals: traversalList);
}


// ========================================================================
// ?GetTraversalsForInteractableEntity@idAAS2Local@@UBAHV?$idIndex@FW4invalidAASInteractionEntIndex_t@@@@AAV?$idList@H$04@@@Z
// EA  : 0x826B1DD8
// RVA : 0x006B1DD8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

int __fastcall idAAS2Local::GetTraversalsForInteractableEntity(
        idAAS2Local *this,
        const idIndex<short,enum invalidAASInteractionEntIndex_t> *intrEntIndex,
        idList<idVehicleState *,5> *traveralList)
{
  return idAAS2File::GetTraversalsForInteractableEntity(this: this->file, intrEntIndex, traversals: traveralList);
}


// ========================================================================
// ?HopPathIsValid@idAAS2Local@@ABA_NHABVidVec3@@H0ABUidAAS2HopPathParms@@@Z
// EA  : 0x826B1E58
// RVA : 0x006B1E58
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

int __fastcall idAAS2Local::HopPathIsValid(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        const idAAS2HopPathParms *parms)
{
  __int64 v11; // r8
  idAAS2File *file; // r3
  float *p_x; // r31
  double v14; // fp5
  double v15; // fp3
  double v16; // fp2
  int v17; // r10
  idResource **i; // r11
  double v19; // fp0
  double v20; // fp2
  double v21; // fp1
  double maxHeight; // fp0
  idAAS2File v23[2]; // [sp+50h] [-1860h] BYREF

  if ( (this->file->areas.list[goalAreaNum].flags & 4) == 0 )
    return 0;
  idAAS2File::GetTreeForArea(this: v23, result: (idIndex<int,enum invalidAASTree_t> *)this->file, areaNum: startAreaNum);
  file = this->file;
  p_x = &file->trees.list[(int)v23[0].__vftable].floorNormal.x;
  v14 = (float)((float)(goalOrigin->y - startOrigin->y)
              - (float)(p_x[1]
                      * (float)((float)(*p_x * (float)(goalOrigin->x - startOrigin->x))
                              + (float)((float)(p_x[2] * (float)(goalOrigin->z - startOrigin->z))
                                      + (float)(p_x[1] * (float)(goalOrigin->y - startOrigin->y))))));
  v15 = (float)((float)(goalOrigin->z - startOrigin->z)
              - (float)(p_x[2]
                      * (float)((float)(*p_x * (float)(goalOrigin->x - startOrigin->x))
                              + (float)((float)(p_x[2] * (float)(goalOrigin->z - startOrigin->z))
                                      + (float)(p_x[1] * (float)(goalOrigin->y - startOrigin->y))))));
  v16 = (float)((float)(goalOrigin->x - startOrigin->x)
              - (float)(*p_x
                      * (float)((float)(*p_x * (float)(goalOrigin->x - startOrigin->x))
                              + (float)((float)(p_x[2] * (float)(goalOrigin->z - startOrigin->z))
                                      + (float)(p_x[1] * (float)(goalOrigin->y - startOrigin->y))))));
  if ( (float)((float)((float)v16 * (float)v16)
             + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) > (double)(float)(parms->maxDistance * parms->maxDistance) )
    return 0;
  v23[0].name.str = (const char *)512;
  HIDWORD(v11) = goalOrigin;
  v23[0].resourceListPtr = (idResourceList *)((char *)&v23[0].idResource + 32);
  idAAS2File::TraceHeight(this: file, tree: (int)v23[0].__vftable, trace: (aas2TraceHeight_t *)&v23[0].name, end: v11);
  if ( (int)v23[0].nextOnHashChain >= 512 )
    return 0;
  v17 = 1;
  if ( (int)v23[0].nextOnHashChain > 1 )
  {
    for ( i = v23[0].resourceListPtr->hashTable; ; i += 3 )
    {
      v19 = (float)((float)(*((float *)i - 1) - startOrigin->y)
                  - (float)(p_x[1]
                          * (float)((float)(*p_x * (float)(*((float *)i - 2) - startOrigin->x))
                                  + (float)((float)(p_x[1] * (float)(*((float *)i - 1) - startOrigin->y))
                                          + (float)(p_x[2] * (float)(*(float *)i - startOrigin->z))))));
      v20 = (float)((float)(*(float *)i - startOrigin->z)
                  - (float)(p_x[2]
                          * (float)((float)(*p_x * (float)(*((float *)i - 2) - startOrigin->x))
                                  + (float)((float)(p_x[1] * (float)(*((float *)i - 1) - startOrigin->y))
                                          + (float)(p_x[2] * (float)(*(float *)i - startOrigin->z))))));
      v21 = (float)((float)(*((float *)i - 2) - startOrigin->x)
                  - (float)(*p_x
                          * (float)((float)(*p_x * (float)(*((float *)i - 2) - startOrigin->x))
                                  + (float)((float)(p_x[1] * (float)(*((float *)i - 1) - startOrigin->y))
                                          + (float)(p_x[2] * (float)(*(float *)i - startOrigin->z))))));
      maxHeight = (float)((float)__fsqrts((float)((float)((float)v21 * (float)v21)
                                                + (float)((float)((float)v20 * (float)v20)
                                                        + (float)((float)v19 * (float)v19))))
                        * parms->maxSlope);
      if ( maxHeight >= parms->minHeight )
      {
        if ( maxHeight > parms->maxHeight )
          maxHeight = parms->maxHeight;
      }
      else
      {
        maxHeight = parms->minHeight;
      }
      if ( (float)((float)((float)(*((float *)i - 2) * *p_x)
                         + (float)((float)(*((float *)i - 1) * p_x[1]) + (float)(*(float *)i * p_x[2])))
                 - (float)((float)(*p_x * startOrigin->x)
                         + (float)((float)(startOrigin->z * p_x[2]) + (float)(startOrigin->y * p_x[1])))) > maxHeight )
        break;
      if ( ++v17 >= (int)v23[0].nextOnHashChain )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?ExtendHopPathToGoal@idAAS2Local@@UBA_NAAUidAAS2Path@@HABVidVec3@@H1HHABUidAAS2HopPathParms@@@Z
// EA  : 0x826B2080
// RVA : 0x006B2080
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::ExtendHopPathToGoal(
        idAAS2Local *this,
        idAAS2Path *path,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags,
        const idAAS2HopPathParms *parms,
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
        const idAAS2HopPathParms *a28)
{
  idAAS2File *file; // r10
  aas2Area_t *list; // r10
  idVec3 *p_moveGoal; // r29
  char v39; // r11
  int v40; // r21
  int IsValid; // r20
  int v42; // r23
  __int64 v43; // r6
  aas2Reachability_t *v44; // r31
  __int128 v45; // r11
  __int64 v46; // r5 OVERLAPPED
  int v47; // r2 OVERLAPPED
  int v48; // r6
  __int16 v49; // r10
  int v50; // r3
  __int64 v51; // fp0
  int toAreaNum; // r11
  int v53; // r4
  int v54; // r10
  int *v55; // r11
  char v56; // r11
  __int16 v57; // [sp+50h] [-E0h] BYREF
  _BYTE v58[4]; // [sp+54h] [-DCh] BYREF
  __int64 v59; // [sp+58h] [-D8h]
  __int64 v60; // [sp+60h] [-D0h]
  __int64 v61; // [sp+68h] [-C8h]
  __int64 v62; // [sp+70h] [-C0h]
  __int64 v63; // [sp+78h] [-B8h]
  __int64 v64; // [sp+80h] [-B0h]
  idVec3 v65; // [sp+88h] [-A8h] BYREF
  int v66; // [sp+A0h] [-90h] BYREF
  int moveAreaNum; // [sp+A4h] [-8Ch]
  int v68; // [sp+A8h] [-88h]
  int v69; // [sp+ACh] [-84h]
  int v70; // [sp+B0h] [-80h]

  file = this->file;
  v57 = -1;
  list = file->areas.list;
  if ( (list[startAreaNum].flags & 4) == 0 )
    return 0;
  p_moveGoal = &path->moveGoal;
  if ( path->moveGoal.x != goalOrigin->x
    || path->moveGoal.y != goalOrigin->y
    || (v39 = 1, path->moveGoal.z != goalOrigin->z) )
  {
    v39 = 0;
  }
  if ( v39 != 0 )
    return idAAS2Local::HopPathIsValid(
             this,
             startAreaNum,
             startOrigin,
             goalAreaNum: path->moveAreaNum,
             goalOrigin: &path->moveGoal,
             parms: a28);
  if ( (list[goalAreaNum].flags & 4) == 0
    || (unsigned __int8)idAAS2Local::HopPathIsValid(
                          this,
                          startAreaNum,
                          startOrigin,
                          goalAreaNum,
                          goalOrigin,
                          parms: a28) == 0 )
  {
    v40 = 0;
    moveAreaNum = path->moveAreaNum;
    v66 = moveAreaNum;
    v68 = moveAreaNum;
    v69 = moveAreaNum;
    v70 = 0;
    IsValid = idAAS2Local::HopPathIsValid(
                this,
                startAreaNum,
                startOrigin,
                goalAreaNum: moveAreaNum,
                goalOrigin: &path->moveGoal,
                parms: a28);
    v42 = 0;
    while ( this->RouteToGoalArea(
              this,
              a2: path->moveAreaNum,
              a3: &path->moveGoal,
              a4: goalAreaNum,
              a5: goalOrigin,
              a6: travelFlags,
              a7: (int *)v58,
              a8: (idIndex<short,enum invalidReachability_t> *)&v57)
         && v57 >= 0 )
    {
      HIDWORD(v43) = startOrigin;
      v44 = &this->file->reachabilities.list[v57];
      DWORD1(v45) = (unsigned __int16)v44->end[2];
      LODWORD(v45) = v44->end[1];
      DWORD2(v45) = v44->end[0];
      LODWORD(v43) = SWORD3(v45);
      v59 = v45;
      v61 = *(_QWORD *)((char *)&v45 + 4);
      v60 = v43;
      v65.y = (float)(__int64)v45;
      v65.z = (float)v43;
      v65.x = (float)*(__int64 *)((char *)&v45 + 4);
      LODWORD(v46) = (unsigned __int8)idAAS2Local::HopPathIsValid(
                                        this,
                                        startAreaNum,
                                        startOrigin,
                                        goalAreaNum: v44->toAreaNum,
                                        goalOrigin: &v65,
                                        parms: a28);
      if ( (_DWORD)v46 == 0 )
        return IsValid;
      IsValid = 1;
      v48 = v44->end[2];
      v49 = v44->end[1];
      v50 = v44->end[0];
      v62 = *(__int64 *)((char *)&v46 - 4);
      v51 = *(__int64 *)((char *)&v46 - 4);
      v64 = *(_QWORD *)(&v47 - 1);
      LODWORD(v46) = v49;
      v63 = v46;
      path->moveGoal.y = (float)v46;
      p_moveGoal->x = (float)*(__int64 *)(&v47 - 1);
      path->moveGoal.z = (float)v51;
      toAreaNum = v44->toAreaNum;
      path->moveAreaNum = toAreaNum;
      if ( v44->toAreaNum == goalAreaNum )
        return 1;
      v53 = toAreaNum;
      v54 = 0;
      v55 = &v66;
      while ( v53 != *v55 )
      {
        ++v54;
        ++v55;
        if ( v54 >= 4 )
        {
          v56 = 0;
          goto LABEL_21;
        }
      }
      v56 = 1;
LABEL_21:
      if ( v56 != 0 )
      {
        idLib::Warning(
          fmt: "idAAS2Local::HopPathToGoal: local routing minimum at area %d while going from area %d to area %d",
          v53,
          startAreaNum,
          goalAreaNum);
        return IsValid;
      }
      ++v42;
      *(&v66 + v40) = v53;
      v40 = (v70 + 1) & 3;
      v70 = v40;
      if ( v42 >= 11 )
        return 1;
    }
    return 0;
  }
  p_moveGoal->x = goalOrigin->x;
  path->moveGoal.y = goalOrigin->y;
  path->moveGoal.z = goalOrigin->z;
  path->moveAreaNum = goalAreaNum;
  return 1;
}


// ========================================================================
// ?GetPath@idAAS2Local@@UBA_NABVidVec3@@0HHHPAUidAAS2PathPoint@@HAAH@Z
// EA  : 0x826B23E8
// RVA : 0x006B23E8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::GetPath(
        idAAS2Local *this,
        const idVec3 *startPos,
        const idVec3 *goalPos,
        int startAreaNum,
        int goalAreaNum,
        int travelFlags,
        idAAS2PathPoint *pointList,
        int maxPoints,
        int *numPoints,
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
        int *a28)
{
  idAAS2PathPoint *v33; // r31
  int v34; // r29
  float *p_z; // r30
  idIndex<short,enum invalidReachability_t> *p_nextReachIndex; // r26
  bool v37; // r3
  int value; // r11
  __int128 v39; // r11 OVERLAPPED
  int v40; // r10
  int v41; // r11
  _WORD *v42; // r11
  __int16 v43; // r4
  int v44; // r7
  int v45; // r11
  int v47; // [sp+50h] [-90h] BYREF
  __int64 v48; // [sp+58h] [-88h]
  __int64 v49; // [sp+60h] [-80h]
  __int64 v50; // [sp+68h] [-78h]

  if ( pointList != nullptr && (-maxPoints & ~maxPoints) < 0 )
  {
    pointList->areaNum = startAreaNum;
    pointList->nextReachIndex.value = -1;
    v33 = pointList;
    pointList->travelTime = 0;
    pointList->origin = *startPos;
    if ( this->file != nullptr && (-startAreaNum & ~startAreaNum) < 0 && (-goalAreaNum & ~goalAreaNum) < 0 )
    {
      v34 = 0;
      *a28 = 1;
      if ( maxPoints > 1 )
      {
        p_z = &pointList->origin.z;
        do
        {
          v47 = 0;
          p_nextReachIndex = &v33->nextReachIndex;
          p_z += 6;
          v37 = this->RouteToGoalArea(
                  this,
                  a2: v33->areaNum,
                  a3: &v33->origin,
                  a4: goalAreaNum,
                  a5: goalPos,
                  a6: travelFlags,
                  a7: &v47,
                  a8: &v33->nextReachIndex);
          ++v33;
          if ( !v37 )
            break;
          value = p_nextReachIndex->value;
          if ( value < 0 )
            break;
          DWORD1(v39) = this->file;
          v40 = 32 * value;
          v34 += v47;
          v41 = *(_DWORD *)(DWORD1(v39) + 432);
          *((_DWORD *)p_z + 2) = v34;
          v42 = (_WORD *)(v41 + v40);
          v33->areaNum = (unsigned __int16)v42[4];
          v43 = v42[8];
          v44 = (unsigned __int16)v42[7];
          DWORD2(v39) = (__int16)v44;
          LODWORD(v39) = (__int16)v42[6];
          v49 = *(_QWORD *)((char *)&v39 + 4);
          HIDWORD(v39) = v43;
          v48 = v39;
          v50 = *(_QWORD *)((char *)&v39 + 12);
          *(p_z - 1) = (float)*(__int64 *)((char *)&v39 + 4);
          *(p_z - 2) = (float)(__int64)v39;
          *p_z = (float)*(__int64 *)((char *)&v39 + 12);
          *((_WORD *)p_z + 2) = -1;
          v45 = *a28 + 1;
          *a28 = v45;
          if ( v33->areaNum == goalAreaNum )
          {
            if ( v45 < maxPoints )
            {
              *a28 = v45 + 1;
              v33[1].areaNum = goalAreaNum;
              v33[1].travelTime = v34;
              v33[1].origin.x = goalPos->x;
              v33[1].origin.y = goalPos->y;
              v33[1].origin.z = goalPos->z;
              v33[1].nextReachIndex.value = -1;
            }
            return 1;
          }
        }
        while ( v45 < maxPoints );
      }
    }
  }
  return 0;
}


// ========================================================================
// ?GetOptimizedWalkPath@idAAS2Local@@UBA_NHABVidVec3@@H0HHAAV?$idList@VidVec3@@$04@@@Z
// EA  : 0x826B25F0
// RVA : 0x006B25F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::GetOptimizedWalkPath(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags,
        idList<idVec3,5> *path)
{
  int toAreaNum; // r30
  float y; // r10
  float z; // r9
  int v18; // r2 OVERLAPPED
  __int64 v19; // r10
  int v20; // r11
  __int64 v21; // r8
  int v22; // r3
  idVec3 v23; // [sp+50h] [-240h] BYREF
  idVec3 v24; // [sp+60h] [-230h] BYREF
  __int64 v25; // [sp+70h] [-220h]
  __int64 v26; // [sp+78h] [-218h]
  __int64 v27; // [sp+80h] [-210h]
  idAAS2Path v28; // [sp+90h] [-200h] BYREF

  if ( this->file == nullptr )
    return 0;
  toAreaNum = startAreaNum;
  y = startOrigin->y;
  z = startOrigin->z;
  v23.x = startOrigin->x;
  v23.y = y;
  v23.z = z;
  while ( toAreaNum != goalAreaNum )
  {
    idAAS2Path::idAAS2Path(this: &v28);
    if ( !this->WalkPathToGoal(
            this,
            a2: &v28,
            a3: toAreaNum,
            a4: &v23,
            a5: goalAreaNum,
            a6: goalOrigin,
            a7: travelFlags,
            a8: walkTravelFlags) )
      return 0;
    idList<idAngles,5>::Append(this: path, obj: &v23);
    if ( v28.reachIndex.value >= 0 )
    {
      HIDWORD(v19) = this->file;
      v20 = 32 * v28.reachIndex.value + *(_DWORD *)(HIDWORD(v19) + 432);
      HIDWORD(v21) = *(unsigned __int16 *)(v20 + 20);
      v22 = *(__int16 *)(v20 + 18);
      LODWORD(v19) = SWORD1(v21);
      LODWORD(v21) = *(__int16 *)(v20 + 22);
      v26 = *(_QWORD *)(&v18 - 1);
      v27 = v19;
      v25 = v21;
      v23.x = (float)*(__int64 *)(&v18 - 1);
      v23.z = (float)v21;
      v23.y = (float)v19;
      toAreaNum = *(unsigned __int16 *)(v20 + 8);
    }
    else
    {
      if ( v28.firstEdge.edgeNum != 0
        && (float)((float)((float)(v28.firstEdge.edgePoint.x - v23.x) * (float)(v28.firstEdge.edgePoint.x - v23.x))
                 + (float)((float)((float)(v28.firstEdge.edgePoint.z - v23.z)
                                 * (float)(v28.firstEdge.edgePoint.z - v23.z))
                         + (float)((float)(v28.firstEdge.edgePoint.y - v23.y)
                                 * (float)(v28.firstEdge.edgePoint.y - v23.y)))) > 0.010000001 )
      {
        v24.x = v28.firstEdge.edgePoint.x;
        v24.y = v28.firstEdge.edgePoint.y;
        v24.z = v28.firstEdge.edgePoint.z;
        toAreaNum = v28.firstEdge.toAreaNum;
        idAAS2File::PushPointIntoAreaNum(this: this->file, areaNum: v28.firstEdge.toAreaNum, point: &v24);
      }
      else
      {
        toAreaNum = v28.moveAreaNum;
        v24.x = v28.moveGoal.x;
        v24.y = v28.moveGoal.y;
        v24.z = v28.moveGoal.z;
      }
      v23.x = v24.x;
      v23.y = v24.y;
      v23.z = v24.z;
    }
  }
  idList<idAngles,5>::Append(this: path, obj: goalOrigin);
  return 1;
}


// ========================================================================
// ?WalkPathIsValid@idAAS2Local@@ABA_NHABVidVec3@@H0HAAHAAUaas2EdgeCrossed_t@@@Z
// EA  : 0x826B27F8
// RVA : 0x006B27F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

int __fastcall idAAS2Local::WalkPathIsValid(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int *endAreaNum,
        aas2EdgeCrossed_t *firstEdgeCrossed)
{
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idAAS2File *file; // r3
  int toAreaNum; // r11
  int edgeNum; // r9
  double x; // fp0
  double y; // fp13
  double z; // fp12
  bool v25; // [sp+Bh] [-115h]
  bool v26; // [sp+Fh] [-111h]
  int v27; // [sp+10h] [-110h]
  int v28; // [sp+14h] [-10Ch]
  int v29; // [sp+18h] [-108h]
  int v30; // [sp+1Ch] [-104h]
  int v31; // [sp+20h] [-100h]
  int v32; // [sp+24h] [-FCh]
  int v33; // [sp+28h] [-F8h]
  int v34; // [sp+2Ch] [-F4h]
  int v35; // [sp+30h] [-F0h]
  int v36; // [sp+34h] [-ECh]
  int v37; // [sp+38h] [-E8h]
  int v38; // [sp+3Ch] [-E4h]
  int v39; // [sp+40h] [-E0h]
  int v40; // [sp+44h] [-DCh]
  int v41; // [sp+48h] [-D8h]
  int v42; // [sp+4Ch] [-D4h]
  int v43; // [sp+50h] [-D0h]
  int v44; // [sp+58h] [-C8h]
  idPLogScope v45; // [sp+68h] [-B8h] BYREF
  aas2TraceFloor_t v46; // [sp+70h] [-B0h] BYREF

  RD_EventBegin(name: "idAAS2Local::WalkPathIsValid");
  LODWORD(v16) = "idAAS2Local::WalkPathIsValid";
  HIDWORD(v16) = 2;
  idPLogScope::idPLogScope(this: &v45, pl: &pLog, gMask: v16, label: v17);
  file = this->file;
  v46.lastAreaNum = 0;
  v46.firstEdge.toAreaNum = 0;
  v46.fraction = 0.0;
  v46.endpos.x = 0.0;
  v46.endpos.y = 0.0;
  v46.endpos.z = 0.0;
  v46.firstEdge.edgePoint.x = 0.0;
  v46.firstEdge.edgeNum = 0;
  v46.firstEdge.edgePoint.y = 0.0;
  v46.lastEdge.toAreaNum = 0;
  v46.firstEdge.edgePoint.z = 0.0;
  v46.lastEdge.edgeNum = 0;
  v46.lastEdge.edgePoint.x = 0.0;
  v46.maxAreas = 0;
  v46.lastEdge.edgePoint.y = 0.0;
  v46.numAreas = 0;
  v46.lastEdge.edgePoint.z = 0.0;
  v46.maxReachIndices = 0;
  v46.numReachIndices = 0;
  v46.areas = nullptr;
  v46.reachIndices = nullptr;
  idAAS2File::TraceFloor(
    this: file,
    trace: &v46,
    start: startOrigin,
    startAreaNum,
    end: goalOrigin,
    endAreaNum: goalAreaNum,
    travelFlags,
    allowFloorNormalChange: false,
    ignoreGravityDirectionDistance: v25,
    ignoreSameArea: v26,
    a11: v27,
    a12: v28,
    a13: v29,
    a14: v30,
    a15: v31,
    a16: v32,
    a17: v33,
    a18: v34,
    a19: v35,
    a20: v36,
    a21: v37,
    a22: v38,
    a23: v39,
    a24: v40,
    a25: v41,
    a26: v42,
    a27: v43,
    a28: 0,
    a29: v44,
    a30: 1);
  toAreaNum = v46.lastEdge.toAreaNum;
  *endAreaNum = v46.lastEdge.toAreaNum;
  if ( toAreaNum == goalAreaNum )
  {
    edgeNum = v46.firstEdge.edgeNum;
    x = v46.firstEdge.edgePoint.x;
    y = v46.firstEdge.edgePoint.y;
    z = v46.firstEdge.edgePoint.z;
    firstEdgeCrossed->toAreaNum = v46.firstEdge.toAreaNum;
    firstEdgeCrossed->edgeNum = edgeNum;
    firstEdgeCrossed->edgePoint.x = x;
    firstEdgeCrossed->edgePoint.y = y;
    firstEdgeCrossed->edgePoint.z = z;
    idPLogScope::~idPLogScope(this: &v45);
    RD_EventEnd();
    return 1;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v45);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$248262
// EA  : 0x826B294C
// RVA : 0x006B294C
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248262()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 288 + 196));
}


// ========================================================================
// __unwind$248263_0
// EA  : 0x826B2974
// RVA : 0x006B2974
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248263_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 288 + 104));
}


// ========================================================================
// ?SubSampleWalkPath@idAAS2Local@@ABAXHABVidVec3@@H00HAAV2@AAHAAUaas2EdgeCrossed_t@@@Z
// EA  : 0x826B29A0
// RVA : 0x006B29A0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void __fastcall idAAS2Local::SubSampleWalkPath(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int pathAreaNum,
        const idVec3 *pathStart,
        const idVec3 *pathEnd,
        int travelFlags,
        idVec3 *endPos,
        int *endAreaNum,
        aas2EdgeCrossed_t *firstEdgeCrossed,
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
        int *a28,
        int a29,
        aas2EdgeCrossed_t *a30)
{
  double v31; // fp28
  double v33; // fp29
  float x; // r9
  double v35; // fp27
  float y; // r8
  float z; // r7
  double v39; // fp30
  double v40; // fp26
  double v41; // fp25
  double v43; // fp24
  double v47; // fp31
  int v48; // r23
  int i; // r24
  double v50; // fp9
  double v51; // fp7
  int v52; // [sp+50h] [-D0h] BYREF
  idVec3 v53; // [sp+58h] [-C8h] BYREF

  v31 = (float)(pathEnd->y - pathStart->y);
  v33 = (float)(pathEnd->x - pathStart->x);
  x = pathStart->x;
  v35 = (float)(pathEnd->z - pathStart->z);
  y = pathStart->y;
  z = pathStart->z;
  v39 = 0.25;
  v53.x = x;
  v40 = x;
  v53.y = y;
  v41 = y;
  v53.z = z;
  v43 = z;
  v47 = 0.5;
  v48 = pathAreaNum;
  for ( i = 0; i < 8; ++i )
  {
    if ( (float)((float)v39
               * (float)((float)((float)v35 * (float)v35)
                       + (float)((float)((float)v33 * (float)v33) + (float)((float)v31 * (float)v31)))) <= 16.0 )
      break;
    v50 = pathStart->z;
    v51 = (float)(pathStart->y + (float)((float)v31 * (float)v47));
    v53.x = pathStart->x + (float)((float)v33 * (float)v47);
    v53.y = v51;
    v53.z = (float)((float)v35 * (float)v47) + (float)v50;
    if ( (unsigned __int8)idAAS2Local::WalkPathIsValid(
                            this,
                            startAreaNum,
                            startOrigin,
                            goalAreaNum: pathAreaNum,
                            goalOrigin: &v53,
                            travelFlags,
                            endAreaNum: &v52,
                            firstEdgeCrossed: a30) != 0 )
    {
      v40 = v53.x;
      v48 = v52;
      v41 = v53.y;
      v47 = (float)((float)v47 + (float)v39);
      v43 = v53.z;
    }
    else
    {
      v47 = (float)((float)v47 - (float)v39);
    }
    v39 = (float)((float)v39 * (float)0.5);
  }
  endPos->x = v40;
  endPos->y = v41;
  endPos->z = v43;
  *a28 = v48;
}


// ========================================================================
// ?WalkPathToGoal@idAAS2Local@@UBA_NAAUidAAS2Path@@HABVidVec3@@H1HH@Z
// EA  : 0x826B2B10
// RVA : 0x006B2B10
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::WalkPathToGoal(
        idAAS2Local *this,
        idAAS2Path *path,
        unsigned int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int walkTravelFlags)
{
  __int64 v12; // r26
  unsigned __int64 v14; // r6
  const char *v15; // r7
  idVec3 *p_moveGoal; // r24
  int *p_moveAreaNum; // r15
  idVec3 *p_traversalStart; // r20
  idVec3 *p_obstacleGoal; // r23
  idVec3 *p_end; // r27
  float x; // r9
  float y; // r7
  float z; // r5
  int v26; // r18
  double v27; // fp0
  unsigned __int64 v28; // r6
  const char *v29; // r7
  int v30; // r28
  int toAreaNum; // r4
  _WORD *v32; // r19
  int v33; // r2 OVERLAPPED
  __int64 v34; // r9
  aas2Reachability_t *v35; // r11
  float *v36; // r10
  __int128 v37; // r6 OVERLAPPED
  __int16 v38; // r7
  __int16 v39; // r4
  int v40; // r3
  double v41; // fp8
  double pathMaxHeight; // fp10
  int v43; // r7
  __int64 v48; // r7
  unsigned int v49; // r11
  __int64 v50; // r9
  __int64 v51; // r11
  char v52; // r11
  idPLog *pLog; // r21
  idPLog::logEntry_t *v55; // r28
  int v56; // r3
  __int64 totalTicks; // r11
  __int64 v58; // r9
  __int64 v59; // r6
  int v60; // r2 OVERLAPPED
  __int64 v61; // r28
  int v62; // r6
  int v63; // r16
  __int64 v64; // r4
  __int64 v65; // r6
  int v66; // r2 OVERLAPPED
  __int16 v67; // r10
  __int64 v68; // r4
  unsigned int v69; // r11
  __int16 v70; // r11
  __int128 v71; // r11
  __int64 v72; // r6
  __int16 v73; // r11
  __int128 v74; // r11
  __int64 v75; // r6
  double v76; // fp10
  int v77; // r10
  __int16 v78; // r11
  __int128 v79; // r11
  int v80; // r3
  int v81; // r4
  int v82; // r3
  float *v83; // r11
  __int16 v84; // r11
  __int128 v85; // r11
  int v86; // r3
  __int16 v87; // r11
  int v88; // r18
  int v89; // r20
  __int16 *v90; // r21
  __int64 v91; // r8
  __int64 v92; // r10 OVERLAPPED
  __int64 v95; // r5
  int v96; // r2 OVERLAPPED
  __int64 v97; // r11
  int v98; // r6
  aas2Reachability_t *v99; // r11
  double v100; // fp29
  double v101; // fp0
  double v102; // fp13
  double v103; // fp12
  __int64 v104; // r11
  int v105; // r3
  int v106; // r6
  __int128 v107; // r7
  idAAS2File *file; // r11
  double v109; // fp12
  double v110; // fp7
  double v111; // fp4
  double v112; // fp0
  double v113; // fp11
  double v114; // fp31
  double v115; // fp3
  double v116; // fp6
  double v117; // fp7
  double v118; // fp5
  double v119; // fp7
  double v120; // fp5
  double v121; // fp4
  double v122; // fp1
  double v123; // fp10
  idPLog *v124; // r29
  idPLog::logEntry_t *v125; // r30
  int v126; // r3
  __int64 v127; // r11
  __int64 v128; // r9
  int *v129; // [sp+8h] [-1F8h]
  aas2EdgeCrossed_t *v130; // [sp+Ch] [-1F4h]
  int v131; // [sp+10h] [-1F0h]
  int v132; // [sp+14h] [-1ECh]
  int v133; // [sp+18h] [-1E8h]
  int v134; // [sp+1Ch] [-1E4h]
  int v135; // [sp+20h] [-1E0h]
  int v136; // [sp+24h] [-1DCh]
  int v137; // [sp+28h] [-1D8h]
  int v138; // [sp+2Ch] [-1D4h]
  int v139; // [sp+30h] [-1D0h]
  int v140; // [sp+34h] [-1CCh]
  int v141; // [sp+38h] [-1C8h]
  int v142; // [sp+3Ch] [-1C4h]
  int v143; // [sp+40h] [-1C0h]
  int v144; // [sp+44h] [-1BCh]
  int v145; // [sp+48h] [-1B8h]
  int v146; // [sp+4Ch] [-1B4h]
  int v147; // [sp+50h] [-1B0h]
  int v148; // [sp+58h] [-1A8h]
  __int16 v149[4]; // [sp+60h] [-1A0h] BYREF
  __int64 v150; // [sp+68h] [-198h]
  idVec3 v151; // [sp+70h] [-190h] BYREF
  idVec3 v152; // [sp+80h] [-180h] BYREF
  char *v153; // [sp+8Ch] [-174h] BYREF
  idPLogScope v154; // [sp+90h] [-170h] BYREF
  idVec3 *p_edgePoint; // [sp+98h] [-168h] BYREF
  int v156; // [sp+9Ch] [-164h]
  idVec3 v157; // [sp+A0h] [-160h] BYREF
  _WORD v158[13]; // [sp+AEh] [-152h] BYREF
  idPLogScope v159; // [sp+C8h] [-138h] BYREF
  float v160[4]; // [sp+D0h] [-130h] BYREF
  idVec3 v161; // [sp+E0h] [-120h] BYREF
  _DWORD v162[4]; // [sp+F0h] [-110h] BYREF
  int v163; // [sp+100h] [-100h]
  __int64 v164; // [sp+108h] [-F8h]
  __int64 v165; // [sp+110h] [-F0h]
  __int64 v166; // [sp+118h] [-E8h]
  __int64 v167; // [sp+120h] [-E0h]
  __int64 v168; // [sp+128h] [-D8h]
  __int64 v169; // [sp+130h] [-D0h]
  __int64 v170; // [sp+138h] [-C8h]
  __int64 v171; // [sp+140h] [-C0h]

  v12 = __PAIR64__(startAreaNum, (unsigned int)goalOrigin);
  RD_EventBegin(name: "idAAS2Local::WalkPathToGoal");
  LODWORD(v14) = "idAAS2Local::WalkPathToGoal";
  HIDWORD(v14) = 2;
  idPLogScope::idPLogScope(this: &v154, pl: &::pLog, gMask: v14, label: v15);
  path->type = 0;
  path->moveGoal = *startOrigin;
  path->reachIndex.value = -1;
  path->moveAreaNum = HIDWORD(v12);
  path->travelTime = 0;
  path->firstEdge.toAreaNum = HIDWORD(v12);
  p_moveGoal = &path->moveGoal;
  path->firstEdge.edgeNum = 0;
  path->firstEdge.edgePoint.x = startOrigin->x;
  p_edgePoint = &path->firstEdge.edgePoint;
  p_moveAreaNum = &path->moveAreaNum;
  path->firstEdge.edgePoint.y = startOrigin->y;
  p_traversalStart = &path->traversalStart;
  path->firstEdge.edgePoint.z = startOrigin->z;
  path->traversalIndex = 0;
  path->traversalStart.x = vec3_origin.x;
  p_obstacleGoal = &path->obstacleGoal;
  p_edgePoint = &path->obstacleRoute.endAlignDir;
  path->traversalStart.y = vec3_origin.y;
  p_end = &path->obstacleRoute.areas[0].end;
  path->traversalStart.z = vec3_origin.z;
  path->traversalEnd = vec3_origin;
  path->obstacleGoal = *startOrigin;
  path->obstacleAreaNum = HIDWORD(v12);
  path->obstacleRoute.endAlignDir.z = 0.0;
  path->obstacleRoute.endAlignDir.y = 0.0;
  path->obstacleRoute.endAlignDir.x = 0.0;
  path->obstacleRoute.numAreas = 1;
  path->obstacleRoute.endTurnRadius = 0.0;
  path->obstacleRoute.areas[0].areaNum = HIDWORD(v12);
  path->obstacleRoute.areas[0].start = *startOrigin;
  path->obstacleRoute.areas[0].end = *(idVec3 *)v12;
  _FP11 = (float)(startOrigin->z - *(float *)(v12 + 8));
  __asm { fsel      f10, f11, f12, f13 }
  path->pathMaxHeight = _FP10;
  if ( this->file != nullptr )
  {
    if ( HIDWORD(v12) == goalAreaNum )
    {
      p_moveGoal->x = *(float *)v12;
      path->moveGoal.y = *(float *)(v12 + 4);
      path->moveGoal.z = *(float *)(v12 + 8);
      p_obstacleGoal->x = *(float *)v12;
      path->obstacleGoal.y = *(float *)(v12 + 4);
      path->obstacleGoal.z = *(float *)(v12 + 8);
      path->travelTime = idAAS2Local::AreaTravelTime(
                           this,
                           areaNum: SHIDWORD(v12),
                           start: startOrigin,
                           end: (const idVec3 *)v12);
      idPLogScope::~idPLogScope(this: &v154);
      goto LABEL_79;
    }
    x = startOrigin->x;
    y = startOrigin->y;
    z = startOrigin->z;
    v26 = 0;
    path->obstacleRoute.areas[0].areaNum = HIDWORD(v12);
    v149[0] = -1;
    v160[0] = x;
    v160[1] = y;
    v160[2] = z;
    v162[0] = HIDWORD(v12);
    v162[1] = HIDWORD(v12);
    v162[2] = HIDWORD(v12);
    v162[3] = HIDWORD(v12);
    memset(&v158[1], 255, 20);
    v163 = 0;
    v27 = startOrigin->x;
    v156 = 0;
    path->obstacleRoute.areas[0].start.x = v27;
    path->obstacleRoute.areas[0].start.y = startOrigin->y;
    path->obstacleRoute.areas[0].start.z = startOrigin->z;
    p_end->x = startOrigin->x;
    path->obstacleRoute.areas[0].end.y = startOrigin->y;
    path->obstacleRoute.areas[0].end.z = startOrigin->z;
    path->obstacleRoute.numAreas = 0;
    RD_EventBegin(name: "Routing");
    LODWORD(v28) = "Routing";
    HIDWORD(v28) = 2;
    idPLogScope::idPLogScope(this: &v159, pl: &::pLog, gMask: v28, label: v29);
    v30 = 0;
    toAreaNum = HIDWORD(v12);
    v32 = v158;
    do
    {
      if ( !this->RouteToGoalArea(
              this,
              a2: toAreaNum,
              a3: (const idVec3 *)v160,
              a4: goalAreaNum,
              a5: (const idVec3 *)v12,
              a6: travelFlags,
              a7: (int *)&p_edgePoint,
              a8: (idIndex<short,enum invalidReachability_t> *)v149)
        || (HIDWORD(v34) = (unsigned __int16)v149[0], v149[0] < 0) )
      {
        idPLogScope::~idPLogScope(this: &v159);
        RD_EventEnd();
        idPLogScope::~idPLogScope(this: &v154);
        RD_EventEnd();
        return 0;
      }
      v35 = &this->file->reachabilities.list[v149[0]];
      v36 = (float *)(&path->type + 7 * v30);
      DWORD2(v37) = v36 + 40;
      v38 = v35->start[0];
      v153 = (char *)(v36 + 36);
      LODWORD(v37) = v38;
      LOWORD(v34) = v35->start[2];
      v39 = v35->start[1];
      v171 = v37;
      v40 = (__int16)v34;
      LODWORD(v34) = v39;
      v153 = (char *)(v36 + 40);
      v168 = *(_QWORD *)(&v33 - 1);
      v166 = v34;
      v36[37] = (float)v34;
      v41 = (double)v168;
      v36[36] = (float)(__int64)v37;
      v36[38] = v41;
      *((_DWORD *)v36 + 39) = v35->toAreaNum;
      LOWORD(v37) = v35->end[0];
      HIDWORD(v37) = (unsigned __int16)v35->end[2];
      DWORD2(v37) = SWORD1(v37);
      DWORD1(v37) = v35->end[1];
      v170 = *(_QWORD *)((char *)&v37 + 4);
      LODWORD(v34) = (__int16)v37;
      v164 = *(_QWORD *)&v37;
      v165 = v34;
      v36[42] = (float)*(__int64 *)((char *)&v37 + 4);
      v36[41] = (float)*(__int64 *)&v37;
      v36[40] = (float)v165;
      ++path->obstacleRoute.numAreas;
      pathMaxHeight = path->pathMaxHeight;
      LODWORD(v37) = (unsigned __int16)v35->start[2];
      HIDWORD(v37) = (__int16)v37;
      v43 = v35->end[2];
      v167 = *(_QWORD *)(&v33 - 1);
      v169 = *(_QWORD *)((char *)&v37 - 4);
      _FP3 = (float)((float)*(__int64 *)(&v33 - 1) - (float)*(__int64 *)((char *)&v37 - 4));
      __asm { fsel      f2, f3, f7, f4 }
      _FP1 = (float)((float)pathMaxHeight - (float)_FP2);
      __asm { fsel      f0, f1, f10, f2 }
      path->pathMaxHeight = _FP0;
      if ( v30 == 0 )
        path->travelTime = (int)p_edgePoint;
      if ( (v35->travelFlags & walkTravelFlags) == 0 || (v35->travelFlags & ~walkTravelFlags) != 0 )
        break;
      toAreaNum = v35->toAreaNum;
      HIDWORD(v48) = goalAreaNum;
      LODWORD(v48) = v156 + 1;
      *++v32 = WORD1(v34);
      v156 = v48;
      if ( toAreaNum == goalAreaNum )
      {
        v36[43] = *(float *)v12;
        v153 = (char *)(v36 + 43);
        v36[44] = *(float *)(v12 + 4);
        v36[45] = *(float *)(v12 + 8);
        ++path->obstacleRoute.numAreas;
        break;
      }
      v49 = v35->end[2];
      HIDWORD(v50) = *(unsigned __int16 *)(v49 + 18);
      v51 = v49;
      LODWORD(v48) = *(__int16 *)(v49 + 20);
      *(_QWORD *)&v151.x = v49;
      LODWORD(v50) = SWORD1(v50);
      *(_QWORD *)&v152.x = v48;
      v150 = v50;
      v160[0] = (float)v50;
      v160[1] = (float)v48;
      v160[2] = (float)v49;
      LODWORD(v51) = v162;
      while ( toAreaNum != *(_DWORD *)v51 )
      {
        ++HIDWORD(v51);
        LODWORD(v51) = v51 + 4;
        if ( SHIDWORD(v51) >= 4 )
        {
          v52 = 0;
          goto LABEL_17;
        }
      }
      v52 = 1;
LABEL_17:
      if ( v52 != 0 )
      {
        idLib::Warning(
          fmt: "idAAS2Local::WalkPathToGoal: local routing minimum at area %d while going from area %d to area %d",
          toAreaNum,
          HIDWORD(v12),
          goalAreaNum);
        break;
      }
      ++v30;
      v162[v26] = toAreaNum;
      v26 = (v163 + 1) & 3;
      v163 = v26;
    }
    while ( v30 < 10 );
    if ( v159.logIndex >= 0 )
    {
      pLog = v159.pLog;
      v55 = &v159.pLog->logEntries.list[v159.logIndex];
      v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v55->totalTicks;
      HIDWORD(totalTicks) = v55->parent;
      LODWORD(v58) = v56 - totalTicks;
      v55->totalTicks = v58;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    LODWORD(v61) = &this->file->reachabilities.list[v149[0]];
    if ( (*(_DWORD *)v61 & walkTravelFlags) != 0 && (*(_DWORD *)v61 & ~walkTravelFlags) == 0 )
    {
      v62 = *(unsigned __int16 *)(v61 + 8);
      v63 = goalAreaNum;
      if ( v62 == goalAreaNum
        && (unsigned __int8)idAAS2Local::WalkPathIsValid(
                              this,
                              startAreaNum: SHIDWORD(v12),
                              startOrigin,
                              goalAreaNum: v62,
                              goalOrigin: (const idVec3 *)v12,
                              travelFlags: walkTravelFlags,
                              endAreaNum: (int *)&v153,
                              firstEdgeCrossed: &path->firstEdge) != 0 )
      {
        p_moveGoal->x = *(float *)v12;
        path->moveGoal.y = *(float *)(v12 + 4);
        path->moveGoal.z = *(float *)(v12 + 8);
        *p_moveAreaNum = goalAreaNum;
        p_obstacleGoal->x = *(float *)v12;
        path->obstacleGoal.y = *(float *)(v12 + 4);
        path->obstacleGoal.z = *(float *)(v12 + 8);
        path->obstacleAreaNum = goalAreaNum;
        idPLogScope::~idPLogScope(this: &v154);
        goto LABEL_79;
      }
_M249124:
      p_moveGoal->x = p_end->x;
      path->moveGoal.y = path->obstacleRoute.areas[0].end.y;
      path->moveGoal.z = path->obstacleRoute.areas[0].end.z;
      *p_moveAreaNum = path->obstacleRoute.areas[0].areaNum;
      p_obstacleGoal->x = p_end->x;
      path->obstacleGoal.y = path->obstacleRoute.areas[0].end.y;
      path->obstacleGoal.z = path->obstacleRoute.areas[0].end.z;
      path->obstacleAreaNum = path->obstacleRoute.areas[0].areaNum;
      if ( aas_simplifyPath.valueInteger != 0 )
      {
        v88 = v156 - 1;
        v89 = v156 - 1;
        if ( v156 - 1 >= 0 )
        {
          v90 = &v158[v88 + 1];
          while ( 1 )
          {
            HIDWORD(v61) = &this->file->reachabilities.list[*v90];
            HIDWORD(v91) = *(unsigned __int16 *)(HIDWORD(v61) + 22);
            LODWORD(v92) = SWORD1(v91);
            HIDWORD(v92) = *(__int16 *)(HIDWORD(v61) + 20);
            LODWORD(v91) = *(__int16 *)(HIDWORD(v61) + 18);
            *(_QWORD *)&v151.x = v92;
            v150 = *(__int64 *)((char *)&v92 + 4);
            *(_QWORD *)&v152.x = v91;
            v157.z = (float)v92;
            v157.y = (float)*(__int64 *)((char *)&v92 + 4);
            v157.x = (float)v91;
            if ( (travelFlags & 0x200000) != 0 )
            {
              _FP12 = (float)(startOrigin->z - (float)v92);
              __asm { fsel      f11, f12, f13, f0 }
              v157.z = _FP11;
            }
            if ( (unsigned __int8)idAAS2Local::WalkPathIsValid(
                                    this,
                                    startAreaNum: SHIDWORD(v12),
                                    startOrigin,
                                    goalAreaNum: *(unsigned __int16 *)(HIDWORD(v61) + 8),
                                    goalOrigin: &v157,
                                    travelFlags: walkTravelFlags,
                                    endAreaNum: (int *)&v153,
                                    firstEdgeCrossed: &path->firstEdge) != 0 )
              break;
            --v89;
            --v90;
            if ( v89 < 0 )
              goto LABEL_73;
          }
          if ( v89 >= v88 )
          {
            if ( (*(_DWORD *)v61 & walkTravelFlags) == 0 || (*(_DWORD *)v61 & ~walkTravelFlags) != 0 )
            {
              HIDWORD(v104) = &path->moveGoal;
              v105 = *(__int16 *)(v61 + 14);
              LODWORD(v104) = *(__int16 *)(v61 + 12);
              LODWORD(v95) = *(__int16 *)(v61 + 16);
              *(_QWORD *)&v151.x = *(_QWORD *)(&v96 - 1);
              v150 = v104;
              *(_QWORD *)&v152.x = v95;
              v106 = *(unsigned __int16 *)(HIDWORD(v61) + 8);
              v152.y = (float)*(__int64 *)(&v96 - 1);
              v152.x = (float)v104;
              v152.z = (float)v95;
              idAAS2Local::SubSampleWalkPath(
                this,
                startAreaNum: SHIDWORD(v12),
                startOrigin,
                pathAreaNum: v106,
                pathStart: &v157,
                pathEnd: &v152,
                travelFlags: walkTravelFlags,
                endPos: &path->moveGoal,
                endAreaNum: v129,
                firstEdgeCrossed: v130,
                a11: v131,
                a12: v132,
                a13: v133,
                a14: v134,
                a15: v135,
                a16: v136,
                a17: v137,
                a18: v138,
                a19: v139,
                a20: v140,
                a21: v141,
                a22: v142,
                a23: v143,
                a24: v144,
                a25: v145,
                a26: v146,
                a27: v147,
                a28: &path->moveAreaNum,
                a29: v148,
                a30: &path->firstEdge);
              HIDWORD(v107) = *(unsigned __int16 *)(v61 + 16);
              LODWORD(v107) = SWORD1(v107);
              DWORD2(v107) = *(__int16 *)(v61 + 14);
              DWORD1(v107) = *(__int16 *)(v61 + 12);
              *(_QWORD *)&v151.x = v107;
              v150 = *(_QWORD *)((char *)&v107 + 4);
              *(_QWORD *)&v152.x = *(_QWORD *)&v107;
              path->obstacleGoal.z = (float)(__int64)v107;
              path->obstacleGoal.y = (float)*(__int64 *)((char *)&v107 + 4);
              p_obstacleGoal->x = (float)*(__int64 *)&v107;
              *p_moveAreaNum = *(unsigned __int16 *)(HIDWORD(v61) + 8);
            }
            else if ( *(unsigned __int16 *)(v61 + 8) == v63 )
            {
              idAAS2Local::SubSampleWalkPath(
                this,
                startAreaNum: SHIDWORD(v12),
                startOrigin,
                pathAreaNum: *(unsigned __int16 *)(HIDWORD(v61) + 8),
                pathStart: &v157,
                pathEnd: (const idVec3 *)v12,
                travelFlags: walkTravelFlags,
                endPos: &path->moveGoal,
                endAreaNum: v129,
                firstEdgeCrossed: v130,
                a11: v131,
                a12: v132,
                a13: v133,
                a14: v134,
                a15: v135,
                a16: v136,
                a17: v137,
                a18: v138,
                a19: v139,
                a20: v140,
                a21: v141,
                a22: v142,
                a23: v143,
                a24: v144,
                a25: v145,
                a26: v146,
                a27: v147,
                a28: &path->moveAreaNum,
                a29: v148,
                a30: &path->firstEdge);
              p_obstacleGoal->x = *(float *)v12;
              path->obstacleGoal.y = *(float *)(v12 + 4);
              path->obstacleGoal.z = *(float *)(v12 + 8);
              *p_moveAreaNum = v63;
            }
            else
            {
              v101 = v157.x;
              v102 = v157.y;
              v103 = v157.z;
              p_moveGoal->x = v157.x;
              path->moveGoal.y = v102;
              path->moveGoal.z = v103;
              *p_moveAreaNum = *(unsigned __int16 *)(HIDWORD(v61) + 8);
              p_obstacleGoal->x = v101;
              path->obstacleGoal.z = v103;
              path->obstacleGoal.y = v102;
              path->obstacleAreaNum = *(unsigned __int16 *)(HIDWORD(v61) + 8);
            }
          }
          else
          {
            HIDWORD(v97) = &path->moveGoal;
            v98 = *(unsigned __int16 *)(HIDWORD(v61) + 8);
            v99 = &this->file->reachabilities.list[(__int16)v158[v89 + 2]];
            LODWORD(v61) = v99->start[0];
            LODWORD(v12) = v99->start[1];
            LODWORD(v97) = v99->start[2];
            v150 = v12;
            *(_QWORD *)&v152.x = v97;
            v151.x = (float)v61;
            v151.y = (float)v12;
            v100 = (float)v97;
            v151.z = (float)v97;
            idAAS2Local::SubSampleWalkPath(
              this,
              startAreaNum: SHIDWORD(v12),
              startOrigin,
              pathAreaNum: v98,
              pathStart: &v157,
              pathEnd: &v151,
              travelFlags: walkTravelFlags,
              endPos: &path->moveGoal,
              endAreaNum: v129,
              firstEdgeCrossed: v130,
              a11: v131,
              a12: v132,
              a13: v133,
              a14: v134,
              a15: v135,
              a16: v136,
              a17: v137,
              a18: v138,
              a19: v139,
              a20: v140,
              a21: v141,
              a22: v142,
              a23: v143,
              a24: v144,
              a25: v145,
              a26: v146,
              a27: v147,
              a28: &path->moveAreaNum,
              a29: v148,
              a30: &path->firstEdge);
            path->obstacleGoal.y = (float)v12;
            path->obstacleGoal.z = v100;
            p_obstacleGoal->x = (float)v61;
            *p_moveAreaNum = *(unsigned __int16 *)(HIDWORD(v61) + 8);
          }
        }
      }
LABEL_73:
      file = this->file;
      v109 = path->moveGoal.y;
      v110 = (float)(path->moveGoal.y - startOrigin->y);
      v111 = (float)(path->obstacleGoal.y - startOrigin->y);
      v112 = (float)(file->settings.obstaclePVSRadius * (float)0.75);
      v113 = path->moveGoal.z;
      v114 = (float)(path->moveGoal.z - startOrigin->z);
      v115 = (float)(path->obstacleGoal.z - startOrigin->z);
      v116 = (float)((float)v112 * (float)v112);
      v117 = (float)((float)((float)v114 * (float)v114)
                   + (float)((float)((float)(p_moveGoal->x - startOrigin->x) * (float)(p_moveGoal->x - startOrigin->x))
                           + (float)((float)v110 * (float)v110)));
      v118 = (float)((float)((float)v115 * (float)v115)
                   + (float)((float)((float)(p_obstacleGoal->x - startOrigin->x)
                                   * (float)(p_obstacleGoal->x - startOrigin->x))
                           + (float)((float)v111 * (float)v111)));
      if ( v117 <= v116 )
      {
        if ( v118 > v116 )
        {
          v119 = __fsqrts(v117);
          v120 = __fsqrts(v118);
          v121 = (float)((float)((float)(file->settings.obstaclePVSRadius * (float)0.75) - (float)v119) / (float)v120);
          v122 = (float)(path->obstacleGoal.y - path->moveGoal.y);
          v123 = (float)((float)(path->obstacleGoal.z - path->moveGoal.z)
                       * (float)((float)((float)(file->settings.obstaclePVSRadius * (float)0.75) - (float)v119)
                               / (float)v120));
          p_obstacleGoal->x = p_moveGoal->x
                            + (float)((float)(p_obstacleGoal->x - p_moveGoal->x)
                                    * (float)((float)((float)(file->settings.obstaclePVSRadius * (float)0.75)
                                                    - (float)v119)
                                            / (float)v120));
          path->obstacleGoal.z = (float)v113 + (float)v123;
          path->obstacleGoal.y = (float)v109 + (float)((float)v122 * (float)v121);
        }
      }
      else
      {
        p_obstacleGoal->x = p_moveGoal->x;
        path->obstacleGoal.y = path->moveGoal.y;
        path->obstacleGoal.z = path->moveGoal.z;
        path->obstacleAreaNum = *p_moveAreaNum;
      }
      if ( v154.logIndex >= 0 )
      {
        v124 = v154.pLog;
        v125 = &v154.pLog->logEntries.list[v154.logIndex];
        v126 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v127 = v125->totalTicks;
        HIDWORD(v127) = v125->parent;
        LODWORD(v128) = v126 - v127;
        v125->totalTicks = v128;
        v124->lastEntry = HIDWORD(v127);
      }
      goto LABEL_79;
    }
    HIDWORD(v64) = *(__int16 *)(v61 + 14);
    LODWORD(v64) = *(__int16 *)(v61 + 16);
    LODWORD(v59) = *(__int16 *)(v61 + 12);
    *(_QWORD *)&v152.x = *(_QWORD *)(&v60 - 1);
    v150 = v64;
    *(_QWORD *)&v151.x = v59;
    v161.y = (float)*(__int64 *)(&v60 - 1);
    v161.z = (float)v64;
    v161.x = (float)v59;
    HIDWORD(v65) = (unsigned __int8)idAAS2Local::WalkPathIsValid(
                                      this,
                                      startAreaNum: SHIDWORD(v12),
                                      startOrigin,
                                      goalAreaNum: *(unsigned __int16 *)(v61 + 6),
                                      goalOrigin: &v161,
                                      travelFlags: walkTravelFlags,
                                      endAreaNum: (int *)&v153,
                                      firstEdgeCrossed: &path->firstEdge);
    if ( HIDWORD(v65) == 0 )
    {
      v63 = goalAreaNum;
      goto _M249124;
    }
    LODWORD(v65) = *(__int16 *)(v61 + 16);
    v67 = *(_WORD *)(v61 + 12);
    HIDWORD(v68) = *(__int16 *)(v61 + 14);
    *(_QWORD *)&v151.x = v65;
    LODWORD(v68) = v67;
    *(_QWORD *)&v152.x = *(_QWORD *)(&v66 - 1);
    v150 = v68;
    path->moveGoal.z = (float)v65;
    path->moveGoal.y = (float)*(__int64 *)(&v66 - 1);
    p_moveGoal->x = (float)v68;
    *p_moveAreaNum = *(unsigned __int16 *)(v61 + 6);
    v69 = *(_DWORD *)v61;
    if ( *(_DWORD *)v61 > 0x400u )
    {
      switch ( v69 )
      {
        case 0x1000u:
          v77 = 6;
          break;
        case 0x2000u:
          v77 = 7;
          break;
        case 0x200000u:
          v84 = v149[0];
          path->type = 8;
          path->reachIndex.value = v84;
          DWORD1(v85) = *(unsigned __int16 *)(v61 + 12);
          v86 = SWORD3(v85);
          LODWORD(v85) = *(__int16 *)(v61 + 16);
          DWORD2(v85) = *(__int16 *)(v61 + 14);
          *(_QWORD *)&v151.x = *(_QWORD *)(&v66 - 1);
          v150 = v85;
          *(_QWORD *)&v152.x = *(_QWORD *)((char *)&v85 + 4);
          p_moveGoal->x = (float)*(__int64 *)(&v66 - 1);
          path->moveGoal.z = (float)(__int64)v85;
          path->moveGoal.y = (float)*(__int64 *)((char *)&v85 + 4);
          *p_moveAreaNum = *(unsigned __int16 *)(v61 + 8);
          goto LABEL_55;
        default:
          goto LABEL_48;
      }
    }
    else
    {
      if ( *(_DWORD *)v61 == 1024 )
      {
        v78 = v149[0];
        path->type = 5;
        path->reachIndex.value = v78;
        DWORD1(v79) = *(unsigned __int16 *)(v61 + 22);
        v80 = SWORD3(v79);
        WORD1(v79) = *(_WORD *)(v61 + 20);
        DWORD2(v79) = *(__int16 *)(v61 + 18);
        *(_QWORD *)&v151.x = *(_QWORD *)(&v66 - 1);
        LODWORD(v79) = SWORD1(v79);
        *(_QWORD *)&v152.x = *(_QWORD *)((char *)&v79 + 4);
        v150 = v79;
        path->moveGoal.y = (float)(__int64)v79;
        path->moveGoal.z = (float)*(__int64 *)(&v66 - 1);
        p_moveGoal->x = (float)*(__int64 *)((char *)&v79 + 4);
        *p_moveAreaNum = *(unsigned __int16 *)(v61 + 8);
        goto LABEL_55;
      }
      if ( v69 > 0x100 )
      {
        if ( v69 != 512 )
          goto LABEL_48;
        v77 = 4;
      }
      else
      {
        if ( v69 != 256 )
        {
          if ( v69 == 64 )
          {
            v73 = v149[0];
            path->type = 1;
            path->reachIndex.value = v73;
            DWORD1(v74) = *(unsigned __int16 *)(v61 + 18);
            LODWORD(v75) = SWORD3(v74);
            HIDWORD(v75) = *(unsigned __int16 *)(v61 + 20);
            LODWORD(v74) = *(__int16 *)(v61 + 22);
            *(_QWORD *)&v151.x = v75;
            DWORD2(v74) = SWORD1(v75);
            v150 = v74;
            *(_QWORD *)&v152.x = *(_QWORD *)((char *)&v74 + 4);
            path->moveGoal.y = (float)*(__int64 *)((char *)&v74 + 4);
            v76 = (double)v150;
            p_moveGoal->x = (float)v75;
            path->moveGoal.z = v76;
            *p_moveAreaNum = *(unsigned __int16 *)(v61 + 8);
            goto LABEL_55;
          }
          if ( v69 == 128 )
          {
            v70 = v149[0];
            path->type = 2;
            path->reachIndex.value = v70;
            DWORD1(v71) = *(unsigned __int16 *)(v61 + 18);
            LODWORD(v72) = SWORD3(v71);
            HIDWORD(v72) = *(unsigned __int16 *)(v61 + 20);
            LODWORD(v71) = *(__int16 *)(v61 + 22);
            DWORD2(v71) = SWORD1(v72);
            v150 = *(_QWORD *)((char *)&v71 + 4);
            *(_QWORD *)&v151.x = v71;
            p_moveGoal->x = (float)v72;
            path->moveGoal.y = (float)*(__int64 *)((char *)&v71 + 4);
            path->moveGoal.z = (float)*(__int64 *)&v151.x;
            *p_moveAreaNum = *(unsigned __int16 *)(v61 + 8);
LABEL_55:
            p_obstacleGoal->x = p_moveGoal->x;
            path->obstacleGoal.y = path->moveGoal.y;
            path->obstacleGoal.z = path->moveGoal.z;
            path->obstacleAreaNum = *p_moveAreaNum;
            idPLogScope::~idPLogScope(this: &v154);
            goto LABEL_79;
          }
LABEL_48:
          if ( (v69 & 0x1870000) != 0 )
          {
            v81 = (unsigned __int16)v149[0];
            path->type = 9;
            path->reachIndex.value = v81;
            v82 = ((int (__fastcall *)(idAAS2Local *, int, const idVec3 *, _DWORD, idVec3 *, idVec3 *, idIndex<short,enum invalidAASDependencyIndex_t> *, int))this->FindBestTraversalForReachability)(
                    a1: this,
                    a2: v81,
                    a3: startOrigin,
                    a4: v12,
                    a5: &path->traversalStart,
                    a6: &path->traversalEnd,
                    a7: &path->dependencyIndex,
                    a8: travelFlags);
            path->traversalIndex = v82;
            if ( (-v82 & ~v82) < 0 )
            {
              p_moveGoal->x = p_traversalStart->x;
              path->moveGoal.y = path->traversalStart.y;
              path->moveGoal.z = path->traversalStart.z;
              v83 = (float *)(&path->type + 7 * path->obstacleRoute.numAreas);
              v83[29] = p_traversalStart->x;
              v83[30] = path->traversalStart.y;
              v83[31] = path->traversalStart.z;
            }
          }
          goto LABEL_55;
        }
        v77 = 3;
      }
    }
    v87 = v149[0];
    path->type = v77;
    path->reachIndex.value = v87;
    goto LABEL_55;
  }
  p_moveGoal->x = *(float *)v12;
  path->moveGoal.y = *(float *)(v12 + 4);
  path->moveGoal.z = *(float *)(v12 + 8);
  *p_moveAreaNum = goalAreaNum;
  p_obstacleGoal->x = *(float *)v12;
  path->obstacleGoal.y = *(float *)(v12 + 4);
  path->obstacleGoal.z = *(float *)(v12 + 8);
  path->obstacleAreaNum = goalAreaNum;
  idPLogScope::~idPLogScope(this: &v154);
LABEL_79:
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$248437
// EA  : 0x826B3AD0
// RVA : 0x006B3AD0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248437()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 512 + 328));
}


// ========================================================================
// __unwind$248438
// EA  : 0x826B3AF8
// RVA : 0x006B3AF8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248438()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$248439
// EA  : 0x826B3B20
// RVA : 0x006B3B20
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248439()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 512 + 329));
}


// ========================================================================
// __unwind$248440
// EA  : 0x826B3B48
// RVA : 0x006B3B48
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_248440()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 512 + 200));
}


// ========================================================================
// ?FindBestTraversalForReachability@idAAS2Local@@UBAHV?$idIndex@FW4invalidReachability_t@@@@ABVidVec3@@1AAV3@2AAV?$idIndex@FW4invalidAASDependencyIndex_t@@@@H_N@Z
// EA  : 0x826B3B78
// RVA : 0x006B3B78
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

int __fastcall idAAS2Local::FindBestTraversalForReachability(
        idAAS2Local *this,
        const idIndex<short,enum invalidReachability_t> *reachIndex,
        const idVec3 *curPoint,
        const idVec3 *goalPoint,
        idVec3 *outTraversalStart,
        idVec3 *outTraversalEnd,
        idIndex<short,enum invalidAASDependencyIndex_t> *dependencyIndex,
        int travelFlags,
        bool useClosestPointOnFail,
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
        char a28)
{
  idIndex<short,enum invalidAASDependencyIndex_t> *v34; // r29
  int v35; // r28
  unsigned __int64 v36; // r6
  const char *v37; // r7
  int v38; // r15
  int TraversalsForReachability; // r3
  aas2Traversal_t *v40; // r18
  double v42; // fp28
  int v43; // r19
  aas2Traversal_t *v44; // r30
  const idVec3 *v45; // r3
  float x; // r5
  float y; // r4
  float z; // r3
  int v49; // r29
  double v50; // fp7
  double v51; // fp6
  double v52; // fp4
  double v53; // fp3
  idRenderWorld *v54; // r3
  idRenderWorld *v55; // r3
  idRenderWorld *v56; // r3
  idRenderWorld *v57; // r3
  idRenderWorld *v58; // r3
  idRenderWorld *v59; // r3
  idRenderWorld *v60; // r3
  idRenderWorld *v61; // r3
  unsigned int flags; // r11
  float v63; // r10
  float v64; // r9
  unsigned __int64 v65; // r6
  const char *v66; // r7
  const idVec3 *v67; // r3
  float v68; // r6
  float v69; // r5
  idMat3 *v70; // r3
  double v71; // fp3
  double v72; // fp2
  double v73; // fp6
  double v74; // fp26
  double v75; // fp1
  double v76; // fp5
  double v77; // fp4
  double v78; // fp2
  double v79; // fp1
  double v80; // fp7
  double v82; // fp4
  double v84; // fp8
  double v85; // fp3
  double v86; // fp7
  double v87; // fp7
  double v88; // fp12
  double v89; // fp8
  double v90; // fp26
  double v91; // fp25
  double v92; // fp24
  float *v93; // r3
  double v94; // fp6
  double v95; // fp5
  double v96; // fp0
  double v97; // fp13
  double v98; // fp12
  double v99; // fp6
  double v100; // fp5
  double v101; // fp1
  double v102; // fp8
  double v103; // fp6
  double v104; // fp6
  double v105; // fp1
  double v106; // fp9
  double v107; // fp4
  idRenderWorld *v108; // r3
  idRenderWorld *v109; // r3
  idRenderWorld *v110; // r3
  idRenderWorld *v111; // r3
  idRenderWorld *v112; // r3
  idRenderWorld *v113; // r3
  int v114; // r29
  int v115; // r30
  int v116; // r3
  __int64 v117; // r11
  __int64 v118; // r9
  idVec3 v119; // [sp+50h] [-250h] BYREF
  int v120; // [sp+5Ch] [-244h]
  int i; // [sp+60h] [-240h]
  idVec2 v122; // [sp+68h] [-238h] BYREF
  idMat3 v123; // [sp+70h] [-230h] BYREF
  int v124; // [sp+94h] [-20Ch]
  idVec2 v125; // [sp+98h] [-208h] BYREF
  float v126; // [sp+A0h] [-200h] BYREF
  float v127[4]; // [sp+A8h] [-1F8h] BYREF
  idVec3 v128; // [sp+B8h] [-1E8h] BYREF
  idVec3 v129; // [sp+C8h] [-1D8h] BYREF
  idVec2 v130; // [sp+D8h] [-1C8h] BYREF
  float v131; // [sp+E0h] [-1C0h]
  idVec2 v132; // [sp+E8h] [-1B8h] BYREF
  float v133; // [sp+F0h] [-1B0h]
  idMat3 v134; // [sp+100h] [-1A0h] BYREF
  idVec2 v135; // [sp+128h] [-178h]
  idPLogScope v136; // [sp+138h] [-168h] BYREF
  idList<idVehicleState *,5> v137; // [sp+140h] [-160h] BYREF
  int v138; // [sp+150h] [-150h] BYREF
  idMat3 v139[3]; // [sp+190h] [-110h] BYREF

  v34 = dependencyIndex;
  v35 = travelFlags;
  RD_EventBegin(name: "idAAS2Local::FindBestTraversalForReachability");
  LODWORD(v36) = "idAAS2Local::FindBestTraversalForReachability";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v123.mat[2].z, pl: &pLog, gMask: v36, label: v37);
  v38 = 0;
  *(_QWORD *)&v137.num = 16;
  v137.list = (idVehicleState **)&v138;
  *(_DWORD *)&v137.granularity = 66817;
  TraversalsForReachability = idAAS2File::GetTraversalsForReachability(this: this->file, reachIndex, traversals: &v137);
  v120 = 0;
  v40 = nullptr;
  *outTraversalStart = vec3_origin;
  *outTraversalEnd = vec3_origin;
  if ( TraversalsForReachability > 0 )
  {
    v42 = 0.0;
    for ( i = TraversalsForReachability; i != 0; --i )
    {
      v43 = (int)v137.list[v38];
      v44 = &this->file->traversalPoints.list[v43];
      v45 = this->GetFloorNormalForArea(this, a2: v44->startAreaNum);
      x = v45->x;
      y = v45->y;
      z = v45->z;
      v128.x = x;
      v128.y = y;
      v128.z = z;
      if ( aas_debugTraversals.valueInteger != 0 )
      {
        v49 = 1000 * aas_debugTraversals.valueInteger - 1000;
        aas2Traversal_t::CalcExtrusionPoint(this: v44, extrusionPoint: (idVec3 *)&v123.mat[1].y, up: &v128);
        v50 = (float)(v44->endPoint.z + v123.mat[2].x);
        v51 = (float)(v44->endPoint.y + v123.mat[1].z);
        v52 = v44->startPoint.z;
        v53 = v44->startPoint.y;
        v127[0] = (float)(v123.mat[1].y + v44->endPoint.x) - v44->startPoint.x;
        v127[2] = (float)v50 - (float)v52;
        v127[1] = (float)v51 - (float)v53;
        v54 = common->RW(this: common);
        v54->DebugPoint(this: v54, a2: (const idVec4 *)&idColor::colorMdGrey, a3: &v44->startPoint, a4: v49, a5: false);
        v55 = common->RW(this: common);
        v55->DebugPoint(this: v55, a2: (const idVec4 *)&idColor::colorMdGrey, a3: &v44->endPoint, a4: v49, a5: false);
        v56 = common->RW(this: common);
        v56->DebugPoint(
          this: v56,
          a2: (const idVec4 *)&idColor::colorMdGrey,
          a3: (const idVec3 *)&v123.mat[1].y,
          a4: v49,
          a5: false);
        v57 = common->RW(this: common);
        v57->DebugPoint(
          this: v57,
          a2: (const idVec4 *)&idColor::colorMdGrey,
          a3: (const idVec3 *)v127,
          a4: v49,
          a5: false);
        v58 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, aas2Traversal_t *, idVec3 *, double))v58->DebugArrow)(
          a1: v58,
          a2: &idColor::colorMdGrey,
          a3: v44,
          a4: &v44->endPoint,
          a5: 5.0);
        v59 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, aas2Traversal_t *, float *, double))v59->DebugArrow)(
          a1: v59,
          a2: &idColor::colorMdGrey,
          a3: v44,
          a4: &v123.mat[1].y,
          a5: 5.0);
        v60 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v60->DebugArrow)(
          a1: v60,
          a2: &idColor::colorMdGrey,
          a3: &v123.mat[1].y,
          a4: v127,
          a5: 5.0);
        v61 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v61->DebugArrow)(
          a1: v61,
          a2: &idColor::colorMdGrey,
          a3: &v44->endPoint,
          a4: v127,
          a5: 5.0);
        v34 = dependencyIndex;
        v35 = travelFlags;
      }
      flags = v44->flags;
      if ( (flags & 1) != 0
        && ((flags & 0x2000000) != 0 && (v35 & 0x10000) != 0
         || (flags & 0x4000000) != 0 && (v35 & 0x20000) != 0
         || (flags & 0x8000000) != 0 && (v35 & 0x40000) != 0
         || (flags & 0x10000000) != 0 && (v35 & 0x800000) != 0
         || (flags & 0x20000000) != 0 && (v35 & 0x1000000) != 0) )
      {
        v63 = v44->startPoint.y;
        v64 = v44->startPoint.z;
        v119.x = v44->startPoint.x;
        v119.y = v63;
        v119.z = v64;
        if ( v44->extrusionDistance > 0 )
        {
          RD_EventBegin(name: "Extrusion Test");
          LODWORD(v65) = "Extrusion Test";
          HIDWORD(v65) = 2;
          idPLogScope::idPLogScope(this: &v136, pl: &pLog, gMask: v65, label: v66);
          aas2Traversal_t::CalcExtrusionPoint(this: v44, extrusionPoint: &v129, up: &v128);
          v67 = this->GetFloorNormalForArea(this, a2: v44->startAreaNum);
          v68 = v67->y;
          v69 = v67->z;
          v123.mat[0].x = v67->x;
          v123.mat[0].y = v68;
          v123.mat[0].z = v69;
          v70 = idVec3::ToZAxis(this: v139[0].mat, result: &v123);
          idMat3::Inverse(this: &v134, result: v70);
          v71 = (float)((float)(curPoint->x * v134.mat[0].x) + (float)(v134.mat[2].x * curPoint->z));
          v72 = (float)((float)(goalPoint->x * v134.mat[0].x) + (float)(v134.mat[2].x * goalPoint->z));
          v73 = curPoint->y;
          v74 = goalPoint->y;
          v75 = (float)((float)(v134.mat[1].y * curPoint->y)
                      + (float)((float)(v134.mat[0].y * curPoint->x) + (float)(v134.mat[2].y * curPoint->z)));
          v76 = (float)((float)(v134.mat[1].y * goalPoint->y)
                      + (float)((float)(v134.mat[0].y * goalPoint->x) + (float)(v134.mat[2].y * goalPoint->z)));
          v135.y = (float)(v134.mat[1].y * curPoint->y)
                 + (float)((float)(v134.mat[0].y * curPoint->x) + (float)(v134.mat[2].y * curPoint->z));
          v135.x = (float)(v134.mat[1].x * (float)v73) + (float)v71;
          v77 = (float)((float)(v134.mat[1].x * (float)v74) + (float)v72);
          v125 = v135;
          v78 = (float)((float)v76 - (float)v75);
          v80 = (float)((float)((float)v76 - (float)v75) * (float)((float)v76 - (float)v75));
          _FP5 = (float)((float)((float)((float)((float)v77 - v135.x) * (float)((float)v77 - v135.x))
                               + (float)((float)((float)v76 - (float)v75) * (float)((float)v76 - (float)v75)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v79 = (float)((float)v77 - v135.x);
          __asm { fsel      f3, f5, f6, f8 }
          v84 = __frsqrte(_FP3);
          v85 = (float)((float)-(float)((float)((float)((float)v84
                                                      * (float)((float)((float)((float)((float)v77 - v135.x)
                                                                              * (float)((float)v77 - v135.x))
                                                                      + (float)v80)
                                                              * (float)0.5))
                                              * (float)v84)
                                      - (float)1.5)
                      * (float)v84);
          v82 = (float)((float)((float)((float)((float)v77 - v135.x) * (float)((float)v77 - v135.x)) + (float)v80)
                      * (float)0.5);
          v86 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84
                                                                                      * (float)((float)((float)((float)v79 * (float)v79) + (float)v80)
                                                                                              * (float)0.5))
                                                                              * (float)v84)
                                                                      - (float)1.5)
                                                      * (float)v84)
                                              * (float)((float)((float)((float)v79 * (float)v79) + (float)v80)
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v84
                                                                              * (float)((float)((float)((float)v79 * (float)v79)
                                                                                              + (float)v80)
                                                                                      * (float)0.5))
                                                                      * (float)v84)
                                                              - (float)1.5)
                                              * (float)v84))
                              - (float)1.5);
          v132.y = (float)(v134.mat[0].y * v129.x)
                 + (float)((float)(v129.y * v134.mat[1].y) + (float)(v129.z * v134.mat[2].y));
          v133 = (float)(v134.mat[0].z * v129.x)
               + (float)((float)(v129.y * v134.mat[1].z) + (float)(v129.z * v134.mat[2].z));
          v122.y = (float)v78
                 * (float)((float)-(float)((float)((float)((float)((float)v86 * (float)v85) * (float)v82)
                                                 * (float)((float)v86 * (float)v85))
                                         - (float)1.5)
                         * (float)((float)v86 * (float)v85));
          v132.x = (float)(v129.z * v134.mat[2].x)
                 + (float)((float)(v129.x * v134.mat[0].x) + (float)(v129.y * v134.mat[1].x));
          v122.x = (float)v79
                 * (float)((float)-(float)((float)((float)((float)((float)v86 * (float)v85) * (float)v82)
                                                 * (float)((float)v86 * (float)v85))
                                         - (float)1.5)
                         * (float)((float)v86 * (float)v85));
          v87 = v44->startPoint.y;
          v88 = (float)((float)(v134.mat[0].x * v44->startPoint.x) + (float)(v134.mat[2].x * v44->startPoint.z));
          v89 = (float)((float)(v134.mat[0].y * v44->startPoint.x)
                      + (float)((float)(v134.mat[2].y * v44->startPoint.z) + (float)(v134.mat[1].y * v44->startPoint.y)));
          v131 = (float)(v134.mat[0].z * v44->startPoint.x)
               + (float)((float)(v134.mat[2].z * v44->startPoint.z) + (float)(v134.mat[1].z * v44->startPoint.y));
          v130.y = v89;
          v130.x = (float)(v134.mat[1].x * (float)v87) + (float)v88;
          if ( idGeometry::IntersectRayWithLineSegment2D(
                 rayStart: &v125,
                 rayDir: &v122,
                 segStart: &v130,
                 segEnd: &v132,
                 dist: &v126) )
          {
            v119.z = 0.0;
            v119.y = v125.y + (float)(v122.y * v126);
            v119.x = (float)(v122.x * v126) + v125.x;
            v90 = (float)(v123.mat[0].z
                        * (float)((float)(v123.mat[0].y * v44->startPoint.y)
                                + (float)((float)(v44->startPoint.x * v123.mat[0].x)
                                        + (float)(v123.mat[0].z * v44->startPoint.z))));
            v91 = (float)(v123.mat[0].y
                        * (float)((float)(v123.mat[0].y * v44->startPoint.y)
                                + (float)((float)(v44->startPoint.x * v123.mat[0].x)
                                        + (float)(v123.mat[0].z * v44->startPoint.z))));
            v92 = (float)((float)((float)(v123.mat[0].y * v44->startPoint.y)
                                + (float)((float)(v44->startPoint.x * v123.mat[0].x)
                                        + (float)(v123.mat[0].z * v44->startPoint.z)))
                        * v123.mat[0].x);
            v93 = (float *)idMat3::Inverse(this: v139, result: &v134);
            v94 = (float)((float)(v93[1] * v119.x) + (float)((float)(v93[7] * v119.z) + (float)(v93[4] * v119.y)));
            v95 = (float)((float)(v119.x * *v93) + (float)((float)(v93[6] * v119.z) + (float)(v93[3] * v119.y)));
            v119.z = (float)((float)(v93[2] * v119.x) + (float)((float)(v93[8] * v119.z) + (float)(v93[5] * v119.y)))
                   + (float)v90;
            v119.y = (float)v94 + (float)v91;
            v119.x = (float)v95 + (float)v92;
          }
          else if ( a28 != 0 )
          {
            idGeometry::ClosestPointOnLineSegment(point: curPoint, start: &v44->startPoint, end: &v129, closest: &v119);
          }
          idPLogScope::~idPLogScope(this: &v136);
          RD_EventEnd();
        }
        v96 = v119.y;
        v97 = v119.x;
        v98 = v119.z;
        v99 = (float)((float)(v119.y + (float)(v44->endPoint.y - v44->startPoint.y)) - goalPoint->y);
        v101 = (float)((float)(v119.z + (float)(v44->endPoint.z - v44->startPoint.z)) - goalPoint->z);
        v100 = (float)((float)((float)(v44->endPoint.x - v44->startPoint.x) + v119.x) - goalPoint->x);
        v102 = __fsqrts((float)((float)((float)(v119.z - curPoint->z) * (float)(v119.z - curPoint->z))
                              + (float)((float)((float)(v119.x - curPoint->x) * (float)(v119.x - curPoint->x))
                                      + (float)((float)(v119.y - curPoint->y) * (float)(v119.y - curPoint->y)))));
        v103 = __fsqrts((float)((float)((float)v101 * (float)v101)
                              + (float)((float)((float)v100 * (float)v100) + (float)((float)v99 * (float)v99))));
        if ( v120 <= 0 || (float)((float)v103 + (float)v102) < v42 )
        {
          outTraversalStart->x = v119.x;
          v42 = (float)((float)v103 + (float)v102);
          outTraversalStart->z = v98;
          v120 = v43;
          outTraversalStart->y = v96;
          v40 = v44;
          v104 = v44->startPoint.x;
          v105 = (float)((float)v97 + v44->endPoint.x);
          v106 = v44->startPoint.y;
          v107 = (float)((float)v96 + v44->endPoint.y);
          outTraversalEnd->z = (float)(v44->endPoint.z + (float)v98) - v44->startPoint.z;
          outTraversalEnd->x = (float)v105 - (float)v104;
          outTraversalEnd->y = (float)v107 - (float)v106;
          v34->value = (__int16)v44->dependencyIndex;
        }
      }
      ++v38;
    }
    if ( aas_debugTraversals.valueInteger != 0 && v40 != nullptr )
    {
      v108 = common->RW(this: common);
      v108->DebugPoint(this: v108, a2: (const idVec4 *)&idColor::colorGreen, a3: &v40->startPoint, a4: 0, a5: false);
      v109 = common->RW(this: common);
      v109->DebugPoint(this: v109, a2: (const idVec4 *)&idColor::colorGreen, a3: &v40->endPoint, a4: 0, a5: false);
      v110 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, aas2Traversal_t *, idVec3 *, double))v110->DebugArrow)(
        a1: v110,
        a2: &idColor::colorGreen,
        a3: v40,
        a4: &v40->endPoint,
        a5: 2.0);
      v111 = common->RW(this: common);
      v111->DebugPoint(this: v111, a2: (const idVec4 *)&idColor::colorPurple, a3: outTraversalStart, a4: 0, a5: false);
      v112 = common->RW(this: common);
      v112->DebugPoint(this: v112, a2: (const idVec4 *)&idColor::colorPurple, a3: outTraversalEnd, a4: 0, a5: false);
      v113 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v113->DebugArrow)(
        a1: v113,
        a2: &idColor::colorPurple,
        a3: outTraversalStart,
        a4: outTraversalEnd,
        a5: 2.0);
    }
    if ( v137.listStatic == 0 || v137.listStatic == 2 )
    {
      if ( v137.list != nullptr )
        idMem::Free(this: &mem, ptr: v137.list, align: ALIGN_16);
      v137.list = nullptr;
      v137.size = 0;
    }
    v137.num = 0;
    if ( v123.mat[2].z >= 0.0 )
    {
      v114 = v124;
      v115 = *(_DWORD *)(v124 + 16) + 16 * LODWORD(v123.mat[2].z);
      v116 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v117 = *(_QWORD *)(v115 + 8);
      HIDWORD(v117) = *(_DWORD *)(v115 + 4);
      LODWORD(v118) = v116 - v117;
      *(_QWORD *)(v115 + 8) = v118;
      *(_DWORD *)(v114 + 32) = HIDWORD(v117);
    }
    RD_EventEnd();
    return v120;
  }
  else
  {
    idList<idThread *,58>::Clear(this: &v137);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v123.mat[2].z);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$249172
// EA  : 0x826B4620
// RVA : 0x006B4620
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_249172()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 436));
}


// ========================================================================
// __unwind$249173
// EA  : 0x826B4648
// RVA : 0x006B4648
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_249173()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 144));
}


// ========================================================================
// __unwind$249174
// EA  : 0x826B4670
// RVA : 0x006B4670
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_249174()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 672 + 320));
}


// ========================================================================
// __unwind$249175
// EA  : 0x826B4698
// RVA : 0x006B4698
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_249175()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 437));
}


// ========================================================================
// __unwind$249176
// EA  : 0x826B46C0
// RVA : 0x006B46C0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void _unwind_249176()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 312));
}


// ========================================================================
// `dynamic initializer for 'aas_debugTraversals''
// EA  : 0x8333E468
// RVA : 0x0133E468
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_debugTraversals__()
{
  idCVar::idCVar(
    this: &aas_debugTraversals,
    name: "aas_debugTraversals",
    value: "0",
    flags: 2,
    description: "if > 0, traversal debug info will be shown for value * 1000 milliseconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_debugTraversals__);
}


// ========================================================================
// `dynamic initializer for 'aas_simplifyPath''
// EA  : 0x8333E4C0
// RVA : 0x0133E4C0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pathing.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_simplifyPath__()
{
  idCVar::idCVar(
    this: &aas_simplifyPath,
    name: "aas_simplifyPath",
    value: "0",
    flags: 2,
    description: "1 = simplify the AAS2 route returning it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_simplifyPath__);
}

