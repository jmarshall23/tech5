
// ========================================================================
// ?GetDistanceToPath@idAnimWebTransitions@@SAMABV?$idStaticList@VidVec3@@$0BP@@@ABVidVec3@@1AAV3@2@Z
// EA  : 0x82A63418
// RVA : 0x00A63418
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

float __fastcall idAnimWebTransitions::GetDistanceToPath(
        const idStaticList<idVec3,31> *path,
        const idVec3 *startOrigin,
        const idVec3 *testPoint,
        idVec3 *outPositionOnPath,
        idVec3 *outDirectionOnPath)
{
  double v9; // fp5
  double v10; // fp4
  double v11; // fp1
  float y; // r10
  float z; // r9
  idVec3 *list; // r8
  double v15; // fp13
  float v16; // r11
  float v17; // r10
  double v18; // fp30
  double v19; // fp29
  double v20; // fp28
  int v21; // r28
  double v22; // fp31
  double v23; // fp9
  int v24; // r29
  double v25; // fp8
  double x; // fp7
  idVec3 *v27; // r11
  double v28; // fp9
  double v29; // fp8
  double v32; // fp2
  double v33; // fp7
  idVec3 v35; // [sp+50h] [-A0h] BYREF
  idVec3 v36; // [sp+60h] [-90h] BYREF
  idVec3 v37; // [sp+70h] [-80h] BYREF
  idVec3 v38; // [sp+80h] [-70h] BYREF

  if ( path->num != 0 )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    list = path->list;
    v36.x = startOrigin->x;
    v36.y = y;
    v15 = y;
    v36.z = z;
    v16 = list->y;
    v17 = list->z;
    v35.x = list->x;
    v35.z = v17;
    v35.y = v16;
    v18 = (float)(v35.x - v36.x);
    v19 = (float)(v16 - (float)v15);
    v20 = (float)(v17 - z);
    idGeometry::ClosestPointOnLineSegment(point: testPoint, start: &v36, end: &v35, closest: &v37);
    v21 = 1;
    v22 = (float)((float)((float)(testPoint->x - v37.x) * (float)(testPoint->x - v37.x))
                + (float)((float)((float)(testPoint->z - v37.z) * (float)(testPoint->z - v37.z))
                        + (float)((float)(testPoint->y - v37.y) * (float)(testPoint->y - v37.y))));
    if ( path->num > 1 )
    {
      v23 = v35.z;
      v24 = 1;
      v25 = v35.y;
      x = v35.x;
      do
      {
        v36.x = x;
        v27 = &path->list[v24];
        v36.y = v25;
        v36.z = v23;
        v35.x = v27->x;
        v35.y = v27->y;
        v35.z = v27->z;
        idGeometry::ClosestPointOnLineSegment(point: testPoint, start: &v36, end: &v35, closest: &v38);
        v23 = v35.z;
        v25 = v35.y;
        x = v35.x;
        if ( (float)((float)((float)(testPoint->y - v38.y) * (float)(testPoint->y - v38.y))
                   + (float)((float)(testPoint->x - v38.x) * (float)(testPoint->x - v38.x))) < v22 )
        {
          v22 = (float)((float)((float)(testPoint->y - v38.y) * (float)(testPoint->y - v38.y))
                      + (float)((float)(testPoint->x - v38.x) * (float)(testPoint->x - v38.x)));
          v37.x = v38.x;
          v37.z = v38.z;
          v37.y = v38.y;
          v19 = (float)(v35.y - v36.y);
          v18 = (float)(v35.x - v36.x);
          v20 = (float)(v35.z - v36.z);
        }
        ++v21;
        ++v24;
      }
      while ( v21 < path->num );
    }
    v28 = v37.y;
    v29 = v37.z;
    outPositionOnPath->x = v37.x;
    outPositionOnPath->y = v28;
    v11 = __fsqrts(v22);
    outPositionOnPath->z = v29;
    _FP5 = (float)((float)((float)((float)v18 * (float)v18)
                         + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v32 = __frsqrte(_FP3);
    v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                                * (float)0.5))
                                                                                * (float)v32)
                                                                        - (float)1.5)
                                                        * (float)v32)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v20 * (float)v20)
                                                                        + (float)((float)v19 * (float)v19)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v32
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                        * (float)0.5))
                                                                        * (float)v32)
                                                                - (float)1.5)
                                                * (float)v32))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v32
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)v20 * (float)v20)
                                                                                + (float)((float)v19 * (float)v19)))
                                                                * (float)0.5))
                                                * (float)v32)
                                        - (float)1.5)
                        * (float)v32));
    outDirectionOnPath->x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32)
                                                                                                  - (float)1.5)
                                                                                  * (float)v32))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v20
                                                                                                  * (float)v20)
                                                                                          + (float)((float)v19
                                                                                                  * (float)v19)))
                                                                          * (float)0.5))
                                                          * (float)v33)
                                                  - (float)1.5)
                                  * (float)v33)
                          * (float)v18;
    outDirectionOnPath->y = (float)v19
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32)
                                                                                                  - (float)1.5)
                                                                                  * (float)v32))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v20
                                                                                                  * (float)v20)
                                                                                          + (float)((float)v19
                                                                                                  * (float)v19)))
                                                                          * (float)0.5))
                                                          * (float)v33)
                                                  - (float)1.5)
                                  * (float)v33);
    outDirectionOnPath->z = (float)v20
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32) - (float)1.5) * (float)v32))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v32)
                                                                                                  - (float)1.5)
                                                                                  * (float)v32))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v20
                                                                                                  * (float)v20)
                                                                                          + (float)((float)v19
                                                                                                  * (float)v19)))
                                                                          * (float)0.5))
                                                          * (float)v33)
                                                  - (float)1.5)
                                  * (float)v33);
  }
  else
  {
    *outPositionOnPath = *startOrigin;
    outDirectionOnPath->x = 0.0;
    outDirectionOnPath->y = 0.0;
    outDirectionOnPath->z = 1.0;
    v9 = (float)(testPoint->y - startOrigin->y);
    v10 = (float)(testPoint->z - startOrigin->z);
    v11 = __fsqrts((float)((float)((float)(testPoint->x - startOrigin->x) * (float)(testPoint->x - startOrigin->x))
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?GetPathPositionAndDirection@idAnimWebTransitions@@SAHABV?$idStaticList@VidVec3@@$0BP@@@MABVidVec3@@1AAV3@2@Z
// EA  : 0x82A636E0
// RVA : 0x00A636E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::GetPathPositionAndDirection(
        const idStaticList<idVec3,31> *path,
        double distanceAhead,
        const idVec3 *startPosition,
        const idVec3 *startDirection,
        idVec3 *outPosition,
        idVec3 *outDirection,
        float *a7)
{
  int num; // r9
  int v10; // r10
  double v11; // fp11
  double v12; // fp12
  double x; // fp10
  idVec3 *list; // r6
  int v15; // r11
  double v16; // fp3
  double v17; // fp5
  double v18; // fp11
  double v19; // fp12
  double v22; // fp10
  double v23; // fp1
  double v24; // fp1
  double v25; // fp12
  double v26; // fp3
  double v27; // fp4
  double v28; // fp5
  float v29; // [sp+0h] [-50h]
  float v30; // [sp+4h] [-4Ch]
  float v31; // [sp+8h] [-48h]
  float y; // [sp+14h] [-3Ch]
  float z; // [sp+18h] [-38h]

  num = path->num;
  y = startDirection->y;
  z = startDirection->z;
  if ( num != 0 )
  {
    v10 = 0;
    v11 = startDirection->y;
    v12 = startDirection->z;
    x = startDirection->x;
    if ( num <= 0 )
    {
      v28 = outPosition->z;
      v27 = outPosition->y;
      v26 = outPosition->x;
LABEL_10:
      outDirection->x = x;
      outDirection->y = v11;
      outDirection->z = v12;
      a7[2] = v28;
      a7[1] = v27;
      *a7 = v26;
      return 0;
    }
    else
    {
      list = path->list;
      v15 = 0;
      while ( 1 )
      {
        v29 = list[v15].x;
        v16 = (float)(v29 - (float)x);
        v30 = list[v15].y;
        v31 = list[v15].z;
        v17 = (float)(v31 - (float)v12);
        v18 = (float)(v30 - (float)v11);
        v19 = (float)((float)((float)(v29 - (float)x) * (float)(v29 - (float)x))
                    + (float)((float)((float)(v31 - (float)v12) * (float)(v31 - (float)v12))
                            + (float)((float)v18 * (float)v18)));
        _FP10 = (float)((float)v19 - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f1, f10, f12, f9 }
        v22 = __frsqrte(_FP1);
        v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                            * (float)((float)v19 * (float)0.5))
                                                                                    * (float)v22)
                                                                            - (float)1.5)
                                                            * (float)v22)
                                                    * (float)((float)v19 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v22
                                                                                    * (float)((float)v19 * (float)0.5))
                                                                            * (float)v22)
                                                                    - (float)1.5)
                                                    * (float)v22))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22)
                                            - (float)1.5)
                            * (float)v22));
        v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                            * (float)((float)v19 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                            * (float)v22))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)v19 * (float)0.5))
                                                                                            * (float)v22)
                                                                                    - (float)1.5)
                                                                    * (float)v22))
                                                    * (float)((float)v19 * (float)0.5))
                                            * (float)v23)
                                    - (float)1.5)
                    * (float)v23);
        v25 = (float)((float)v24 * (float)v19);
        v26 = (float)((float)v16 * (float)v24);
        v27 = (float)((float)v18 * (float)v24);
        v28 = (float)((float)v17 * (float)v24);
        if ( distanceAhead <= v25 )
          break;
        ++v10;
        distanceAhead = (float)((float)distanceAhead - (float)v25);
        ++v15;
        x = v29;
        v11 = v30;
        v12 = v31;
        if ( v10 >= num )
          goto LABEL_10;
      }
      outDirection->x = (float)((float)v26 * (float)distanceAhead) + startDirection->x;
      outDirection->y = y + (float)((float)((float)v18 * (float)v24) * (float)distanceAhead);
      outDirection->z = z + (float)((float)v28 * (float)distanceAhead);
      a7[2] = v28;
      a7[1] = (float)v18 * (float)v24;
      *a7 = v26;
      return 0;
    }
  }
  else
  {
    *outDirection = *startDirection;
    *(idVec3 *)a7 = *outPosition;
    return -1;
  }
}


// ========================================================================
// ?Clear@transitionCache_t@idAnimWebTransitions@@QAAXXZ
// EA  : 0x82A638D8
// RVA : 0x00A638D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __fastcall idAnimWebTransitions::transitionCache_t::Clear(idAnimWebTransitions::transitionCache_t *this)
{
  idAnimWebState::Clear(this: &this->srcState);
  idAnimWebState::Clear(this: &this->dstState);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transitions);
  this->nodeIndex.value = -1;
}


// ========================================================================
// ?CleanupNavTraces@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@@Z
// EA  : 0x82A63920
// RVA : 0x00A63920
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __fastcall idAnimWebTransitions::CleanupNavTraces(idAI2 *ai, idAnimWebTransitions::transitionCache_t *cache)
{
  int v2; // r31
  int v3; // r5
  int v4; // r6
  int i; // ctr
  int v6; // r8
  char *v7; // r9
  int v8; // r10
  int v9; // r10
  char *v10; // r9
  int v11; // r10
  int v12; // r10
  char *v13; // r9
  int v14; // r10
  int v15; // r10
  char *v16; // r9
  int v17; // r10
  int v18; // r10

  v2 = 0;
  if ( cache->transitions.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = 0;
      for ( i = 2; i != 0; --i )
      {
        v6 = 40 * (v3 + v4);
        v7 = (char *)cache->transitions.list + v6;
        v8 = *((_DWORD *)v7 + 66);
        if ( v8 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v8].used = false;
        v9 = *((_DWORD *)v7 + 67);
        if ( v9 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v9].used = false;
        v10 = (char *)cache->transitions.list + v6;
        v11 = *((_DWORD *)v10 + 76);
        if ( v11 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v11].used = false;
        v12 = *((_DWORD *)v10 + 77);
        if ( v12 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v12].used = false;
        v13 = (char *)cache->transitions.list + v6;
        v14 = *((_DWORD *)v13 + 86);
        if ( v14 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v14].used = false;
        v15 = *((_DWORD *)v13 + 87);
        if ( v15 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v15].used = false;
        v16 = (char *)cache->transitions.list + v6;
        v17 = *((_DWORD *)v16 + 96);
        if ( v17 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v17].used = false;
        v18 = *((_DWORD *)v16 + 97);
        if ( v18 > -1 )
          ai->aiVolatile.animation.animFSM.navTraces.ptr[v18].used = false;
        v4 += 4;
      }
      ++v2;
      v3 += 14;
    }
    while ( v2 < cache->transitions.num );
  }
}


// ========================================================================
// ?FindDepartureTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@AA_N@Z
// EA  : 0x82A63A70
// RVA : 0x00A63A70
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::FindDepartureTransition(
        const idAI2 *ai,
        const idAnimWebTransitions::transitionQueryValidation_t *validation,
        idAnimWebTransitions::transitionCache_t *cache,
        const idAnimWebTransitions::transitionQueryParms_t *parms,
        idAnimWebTransitions::transitionQueryResult_t *out,
        bool *wasRejectedBasedOnDistanceAlone)
{
  int entityNumber; // r8
  float y; // r4
  float z; // r29
  int *v11; // r10
  float *p_z; // r9
  int v13; // ctr
  bool v14; // r11
  int debugDrawTime; // r27
  int num; // r10
  double v17; // fp15
  double v18; // fp14
  int v19; // r28
  idAnimWebTransitions::transitionData_t *v20; // r26
  int flags; // r11
  double v22; // fp13
  double v23; // fp11
  double v24; // fp9
  double v25; // fp6
  double v26; // fp5
  const idMat3 *v27; // r3
  const idVec3 *v28; // r4
  double v29; // fp12
  double v30; // fp9
  idStaticList<idVec3,31> *p_cachedCorners; // r24
  idStaticList<idVec3,31> *v32; // r3
  double v35; // fp3
  double v36; // fp13
  double v37; // fp12
  double v38; // fp27
  double v39; // fp25
  double v40; // fp24
  double x; // fp23
  double v42; // fp28
  char CustomFlags; // r3
  int v44; // r11
  double v45; // fp12
  int v46; // r30
  double requiredMoveAlignAngleDot; // fp0
  double v48; // fp7
  double v49; // fp4
  double v50; // fp3
  double v51; // fp1
  double v52; // fp8
  double v53; // fp6
  double requiredApexAlignAngleDot; // fp31
  double v55; // fp0
  idRenderWorld *v56; // r3
  idRenderWorld_vtbl *v57; // r9
  idRenderWorld *v58; // r3
  idRenderWorld_vtbl *v59; // r9
  void (*DebugSphere)(void); // r11
  idRenderWorld *v61; // r3
  idRenderWorld *v62; // r3
  idRenderWorld_vtbl *v63; // r11
  idRenderWorld *v64; // r3
  idRenderWorld *v65; // r3
  idRenderWorld *v66; // r3
  idRenderWorld *v67; // r3
  double v68; // fp14
  double v69; // fp31
  double v70; // fp30
  idRenderWorld *v71; // r3
  idColor *v72; // r4
  float *v73; // r5
  idRenderWorld *v74; // r3
  double v75; // fp14
  double v76; // fp30
  idRenderWorld_vtbl *v77; // r11
  int suggestedFlags; // r11
  double v79; // fp31
  double v80; // fp30
  double DistanceToPath; // fp1
  double v82; // fp0
  idColor *v83; // r30
  const char *v84; // r4
  idRenderWorld *v85; // r3
  idRenderWorld_vtbl *v86; // r6
  idRenderWorld *v87; // r3
  idRenderWorld *v88; // r3
  idRenderWorld *v89; // r3
  int v90; // r7
  idAnimWebTransitions::transitionData_t *v91; // r30
  idRenderWorld *v92; // r3
  __int64 v93; // r11
  idRenderWorld_vtbl *v94; // r6
  double v95; // fp10
  float v96; // r27
  idRenderWorld *v97; // r3
  idRenderWorld *v98; // r3
  idRenderWorld *v99; // r3
  idAtomicString *p_debugState; // r11
  double v101; // fp13
  double v102; // fp12
  double v103; // fp11
  double v104; // fp10
  double v105; // fp9
  const idMD6Anim **p_anim; // r10
  int v107; // ctr
  const char **p_approximatePathDistance; // r11
  idAtomicString *v109; // r10
  int i; // ctr
  BOOL v112; // [sp+60h] [-460h]
  idVec3 v113; // [sp+68h] [-458h] BYREF
  idVec3 v114; // [sp+78h] [-448h] BYREF
  idVec3 v115; // [sp+88h] [-438h] BYREF
  idVec3 v116; // [sp+98h] [-428h] BYREF
  float v117; // [sp+A8h] [-418h] BYREF
  float v118; // [sp+ACh] [-414h]
  float v119; // [sp+B0h] [-410h]
  unsigned int v120; // [sp+B4h] [-40Ch]
  int v121; // [sp+B8h] [-408h]
  float v122; // [sp+BCh] [-404h]
  idVec3 v123; // [sp+C0h] [-400h] BYREF
  int v124; // [sp+CCh] [-3F4h]
  float v125; // [sp+D0h] [-3F0h]
  int v126; // [sp+DCh] [-3E4h] BYREF
  idMat3 v127; // [sp+E0h] [-3E0h] BYREF
  idVec3 v128; // [sp+108h] [-3B8h] BYREF
  idVec3 v129; // [sp+118h] [-3A8h] BYREF
  idColor *v130; // [sp+124h] [-39Ch]
  idVec3 v131; // [sp+128h] [-398h]
  float valueFloat; // [sp+134h] [-38Ch]
  float v133; // [sp+138h] [-388h]
  idColor *v134; // [sp+13Ch] [-384h]
  float totalPathDistance; // [sp+140h] [-380h]
  idVec3 v136; // [sp+148h] [-378h] BYREF
  float v137; // [sp+158h] [-368h]
  float v138; // [sp+15Ch] [-364h]
  float v139; // [sp+160h] [-360h]
  float v140[4]; // [sp+168h] [-358h] BYREF
  float v141[4]; // [sp+178h] [-348h] BYREF
  float v142[4]; // [sp+188h] [-338h] BYREF
  idVec3 v143; // [sp+198h] [-328h] BYREF
  float v144[4]; // [sp+1A8h] [-318h] BYREF
  float v145[4]; // [sp+1B8h] [-308h] BYREF
  float v146[4]; // [sp+1C8h] [-2F8h] BYREF
  float v147[8]; // [sp+1D8h] [-2E8h] BYREF
  float v148[4]; // [sp+1F8h] [-2C8h] BYREF
  float v149[4]; // [sp+208h] [-2B8h] BYREF
  float v150[2]; // [sp+218h] [-2A8h] BYREF
  float v151; // [sp+220h] [-2A0h]
  float v152[4]; // [sp+228h] [-298h] BYREF
  float v153[2]; // [sp+238h] [-288h] BYREF
  float v154; // [sp+240h] [-280h]
  float v155; // [sp+248h] [-278h]
  float v156; // [sp+24Ch] [-274h]
  float v157; // [sp+250h] [-270h]
  float v158[4]; // [sp+258h] [-268h] BYREF
  float v159[10]; // [sp+268h] [-258h] BYREF
  float v160[4]; // [sp+290h] [-230h] BYREF
  float v161[8]; // [sp+2A0h] [-220h] BYREF
  float v162[4]; // [sp+2C0h] [-200h] BYREF
  float v163[4]; // [sp+2D0h] [-1F0h] BYREF
  idStr v164; // [sp+2E0h] [-1E0h] BYREF
  float v165[4]; // [sp+300h] [-1C0h] BYREF
  idStr v166; // [sp+310h] [-1B0h] BYREF
  idMat3 v167; // [sp+330h] [-190h] BYREF
  idVec3 v168[2]; // [sp+358h] [-168h] BYREF
  idMat3 v169[5]; // [sp+370h] [-150h] BYREF

  *wasRejectedBasedOnDistanceAlone = false;
  if ( cache->transitions.num == 0 || ai_forceNoTransitions.valueInteger > 0 )
    return 0;
  entityNumber = ai->entityNumber;
  y = parms->sourceOrigin1.y;
  z = parms->sourceOrigin1.z;
  v11 = &v126;
  p_z = &parms->sourceOrigin2.z;
  v13 = 9;
  v116.x = parms->sourceOrigin1.x;
  v116.y = y;
  v116.z = z;
  v14 = (_cntlzw(entityNumber - ai_debugAnimWebTransitions.valueInteger) & 0x20) != 0;
  do
  {
    *++v11 = *(_DWORD *)++p_z;
    --v13;
  }
  while ( v13 != 0 );
  totalPathDistance = parms->totalPathDistance;
  debugDrawTime = parms->debugDrawTime;
  v112 = v14;
  v131 = v127.mat[0];
  if ( v14 && validation->selectType == CHOOSE_CLOSEST_TO_PATH_RELATIVE )
    idAnimBaseFSM::DebugDrawCurrentCorners(
      this: &ai->aiVolatile.animation.animFSM,
      startOrigin: (const idVec3 *)LODWORD(idColor::colorCyan.r),
      color: (const idColor *)LODWORD(idColor::colorCyan.b),
      lifetime: SLODWORD(idColor::colorCyan.a));
  num = cache->transitions.num;
  v121 = 0;
  v124 = -1;
  valueFloat = ai_departureAngleInfluence.valueFloat;
  v122 = 3.4028235e38;
  if ( num <= 0 )
    return 0;
  v17 = v137;
  v120 = 0;
  v18 = 0.99000001;
  v133 = 1.1;
  v125 = 0.99000001;
  v134 = &idColor::colorYellow;
  v130 = &idColor::colorRed;
  do
  {
    v19 = 0;
    v20 = &cache->transitions.list[v120 / 0x230];
    flags = v20->flags;
    if ( (validation->allowedFlags | flags) != validation->allowedFlags )
    {
      if ( !v112 )
        goto LABEL_89;
      v19 = 8;
    }
    if ( (validation->requiredFlags & flags) != validation->requiredFlags )
    {
      if ( !v112 )
        goto LABEL_89;
      v19 = 7;
    }
    v22 = (float)((float)(v127.mat[0].z * v20->deltaCorrectGoalTranslation.x)
                + (float)(v127.mat[2].z * v20->deltaCorrectGoalTranslation.z));
    v23 = (float)((float)(v127.mat[0].y * v20->deltaCorrectGoalTranslation.x)
                + (float)(v127.mat[2].y * v20->deltaCorrectGoalTranslation.z));
    v24 = (float)((float)(v127.mat[0].x * v20->deltaCorrectGoalTranslation.x)
                + (float)(v127.mat[2].x * v20->deltaCorrectGoalTranslation.z));
    LODWORD(v115.x) = &v20->deltaCorrectGoalTranslation;
    v25 = (float)((float)(v127.mat[1].y * v20->deltaCorrectGoalTranslation.y) + (float)v23);
    v26 = (float)((float)(v127.mat[1].x * v20->deltaCorrectGoalTranslation.y) + (float)v24);
    v113.z = v116.z + (float)((float)(v127.mat[1].z * v20->deltaCorrectGoalTranslation.y) + (float)v22);
    v113.y = v116.y + (float)v25;
    v113.x = v116.x + (float)v26;
    v27 = idMat3::Inverse(this: v169, result: &v20->deltaCorrectGoalAxis);
    idMat3::operator*(this: &v167, result: &v127, a: v27);
    v29 = (float)(v116.y - v113.y);
    v30 = (float)(v116.x - v113.x);
    p_cachedCorners = &parms->cachedCorners;
    v32 = &parms->cachedCorners;
    _FP6 = (float)((float)((float)((float)(v116.x - v113.x) * (float)(v116.x - v113.x))
                         + (float)((float)(v116.y - v113.y) * (float)(v116.y - v113.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f0 }
    v35 = __frsqrte(_FP4);
    v36 = (float)((float)-(float)((float)((float)((float)v35
                                                * (float)((float)((float)((float)(v116.x - v113.x)
                                                                        * (float)(v116.x - v113.x))
                                                                + (float)((float)(v116.y - v113.y)
                                                                        * (float)(v116.y - v113.y)))
                                                        * (float)0.5))
                                        * (float)v35)
                                - (float)1.5)
                * (float)v35);
    v37 = (float)((float)((float)-(float)((float)((float)((float)v35
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)v29 * (float)v29))
                                                                * (float)0.5))
                                                * (float)v35)
                                        - (float)1.5)
                        * (float)v35)
                * (float)((float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29)) * (float)0.5));
    v38 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v37 * (float)v36)
                                                                                - (float)1.5)
                                                                * (float)v36)
                                                        * (float)((float)((float)((float)(v116.x - v113.x)
                                                                                * (float)(v116.x - v113.x))
                                                                        + (float)((float)(v116.y - v113.y)
                                                                                * (float)(v116.y - v113.y)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5)
                                                        * (float)v36))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5) * (float)v36))
                * (float)((float)((float)(v116.x - v113.x) * (float)(v116.x - v113.x))
                        + (float)((float)(v116.y - v113.y) * (float)(v116.y - v113.y))));
    if ( validation->usePathDirectionForMoveAlign )
      idAnimWebTransitions::GetDistanceToPath(
        path: v32,
        startOrigin: &v116,
        testPoint: &v113,
        outPositionOnPath: &v128,
        outDirectionOnPath: &v136);
    else
      idAnimWebTransitions::GetPathPositionAndDirection(
        path: v32,
        distanceAhead: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v37 * (float)v36)
                                                                              - (float)1.5)
                                                              * (float)v36)
                                                      * (float)((float)((float)((float)(v116.x - v113.x)
                                                                              * (float)(v116.x - v113.x))
                                                                      + (float)((float)(v116.y - v113.y)
                                                                              * (float)(v116.y - v113.y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5)
                                                      * (float)v36))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)v37 * (float)v36) - (float)1.5) * (float)v36))
              * (float)((float)((float)(v116.x - v113.x) * (float)(v116.x - v113.x))
                      + (float)((float)(v116.y - v113.y) * (float)(v116.y - v113.y)))),
        startPosition: v28,
        startDirection: &v116,
        outPosition: v127.mat,
        outDirection: &v128,
        a7: &v136.x);
    v39 = v167.mat[0].z;
    v40 = v167.mat[0].y;
    x = v167.mat[0].x;
    v42 = (float)((float)(v167.mat[0].x * v136.x)
                + (float)((float)(v167.mat[0].y * v136.y) + (float)(v167.mat[0].z * v136.z)));
    if ( !validation->allowRejections
      || (CustomFlags = idAnimWebState::GetCustomFlags(this: &v20->src), LOBYTE(v44) = 1, (CustomFlags & 0x10) != 0) )
    {
      LOBYTE(v44) = 0;
    }
    v44 = (unsigned __int8)v44;
    v45 = -1.0;
    v46 = v44;
    if ( (_BYTE)v44 != 0
      && (requiredMoveAlignAngleDot = validation->requiredMoveAlignAngleDot) > -1.0
      && v42 < requiredMoveAlignAngleDot )
    {
      if ( !v112 )
        goto LABEL_89;
      v19 = 2;
    }
    else if ( v19 == 0 && (_BYTE)v44 != 0 && v20->approximatePathDistance > (double)totalPathDistance )
    {
      *wasRejectedBasedOnDistanceAlone = true;
      if ( !v112 )
        goto LABEL_89;
      v45 = -1.0;
      v19 = 4;
    }
    v114 = v113;
    if ( v20->hasApex )
    {
      v48 = (float)(v127.mat[2].z * v20->apex.z);
      v49 = (float)(v127.mat[2].x * v20->apex.z);
      v50 = v20->apex.x;
      v51 = (float)((float)(v127.mat[0].y * v20->apex.x) + (float)(v127.mat[2].y * v20->apex.z));
      LODWORD(v115.x) = &v20->apex;
      v52 = (float)((float)(v127.mat[1].z * v20->apex.y) + (float)((float)(v127.mat[0].z * (float)v50) + (float)v48));
      v53 = (float)((float)(v127.mat[1].x * v20->apex.y) + (float)((float)(v127.mat[0].x * (float)v50) + (float)v49));
      v114.y = v116.y + (float)((float)(v127.mat[1].y * v20->apex.y) + (float)v51);
      v114.z = v116.z + (float)v52;
      v114.x = (float)v53 + v116.x;
    }
    requiredApexAlignAngleDot = validation->requiredApexAlignAngleDot;
    if ( requiredApexAlignAngleDot > v45 && (_BYTE)v44 != 0 )
    {
      if ( v19 != 0 )
        goto LABEL_61;
      v123.z = v114.z - v116.z;
      v123.y = v114.y - v116.y;
      v123.x = v114.x - v116.x;
      idVec3::NormalizeFast(this: &v123);
      if ( validation->usePathDirectionForApexAlign )
      {
        idAnimWebTransitions::GetDistanceToPath(
          path: p_cachedCorners,
          startOrigin: &v116,
          testPoint: &v114,
          outPositionOnPath: &v143,
          outDirectionOnPath: &v115);
        v129.x = v143.x - v116.x;
        v129.z = v143.z - v116.z;
        v129.y = v143.y - v116.y;
        idVec3::NormalizeFast(this: &v129);
        v55 = (float)((float)(v129.y * v123.y) + (float)((float)(v129.x * v123.x) + (float)(v129.z * v123.z)));
      }
      else
      {
        v55 = (float)((float)(v131.y * v123.y) + (float)((float)(v123.x * v131.x) + (float)(v131.z * v123.z)));
      }
      if ( v55 < requiredApexAlignAngleDot )
      {
        if ( !v112 )
          goto LABEL_89;
        v19 = 3;
        goto LABEL_61;
      }
    }
    else if ( v19 != 0 )
    {
      goto LABEL_61;
    }
    if ( v46 == 0 || !validation->navProbeAnimApex )
      goto LABEL_61;
    if ( v20->hasApex )
    {
      if ( v20->navTraces.ptr[0].fraction <= v18 )
      {
        if ( !v112 )
          goto LABEL_89;
        v19 = 9;
        v56 = gameLocal->GetRenderWorld(this: gameLocal);
        v146[0] = v114.x;
        v146[1] = v114.y;
        v152[0] = v113.x;
        v152[1] = v113.y;
        v146[2] = v114.z + (float)5.0;
        v152[2] = v113.z + (float)5.0;
        v57 = v56->__vftable;
        v115.x = v113.y;
        v57->DebugLine(
          this: v56,
          a2: (const idVec4 *)&idColor::colorOrange,
          a3: (const idVec3 *)v152,
          a4: (const idVec3 *)v146,
          a5: debugDrawTime,
          a6: false);
        if ( v20->hasApex )
        {
          v58 = gameLocal->GetRenderWorld(this: gameLocal);
          v159[6] = v114.x;
          v159[7] = v114.y;
          v159[9] = 5.0;
          v159[8] = v114.z + (float)5.0;
          v59 = v58->__vftable;
          v115.x = v114.y;
          DebugSphere = (void (*)(void))v59->DebugSphere;
          goto LABEL_60;
        }
        goto LABEL_61;
      }
      if ( v112 )
      {
        v61 = gameLocal->GetRenderWorld(this: gameLocal);
        v140[0] = v114.x;
        v140[1] = v114.y;
        v144[0] = v113.x;
        v144[1] = v113.y;
        v140[2] = v114.z + (float)5.0;
        v144[2] = v113.z + (float)5.0;
        v115.x = v113.y;
        v61->DebugLine(
          this: v61,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idVec3 *)v144,
          a4: (const idVec3 *)v140,
          a5: debugDrawTime,
          a6: false);
        v62 = gameLocal->GetRenderWorld(this: gameLocal);
        v163[0] = v114.x;
        v163[1] = v114.y;
        v163[3] = 2.0;
        v163[2] = v114.z + (float)5.0;
        v63 = v62->__vftable;
        v115.x = v114.y;
        v63->DebugSphere(
          this: v62,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idSphere *)v163,
          a4: 12,
          a5: debugDrawTime,
          a6: false);
      }
    }
    if ( v20->navTraces.ptr[1].fraction > v18 )
    {
      if ( !v112 || !v20->hasApex )
        goto LABEL_61;
      v66 = gameLocal->GetRenderWorld(this: gameLocal);
      v147[6] = v114.z + (float)5.0;
      v157 = v116.z + (float)5.0;
      v156 = v116.y;
      v147[4] = v114.x;
      v155 = v116.x;
      v147[5] = v114.y;
      v115.x = v116.y;
      DebugSphere = (void (*)(void))v66->DebugLine;
LABEL_60:
      DebugSphere();
      goto LABEL_61;
    }
    if ( !v112 )
      goto LABEL_89;
    v19 = 9;
    v64 = gameLocal->GetRenderWorld(this: gameLocal);
    v147[1] = v114.y;
    v145[2] = v116.z + (float)5.0;
    v147[0] = v114.x;
    v145[0] = v116.x;
    v147[2] = v114.z + (float)5.0;
    v145[1] = v116.y;
    v115.x = v116.y;
    v64->DebugLine(
      this: v64,
      a2: (const idVec4 *)&idColor::colorOrange,
      a3: (const idVec3 *)v145,
      a4: (const idVec3 *)v147,
      a5: debugDrawTime,
      a6: false);
    if ( v20->hasApex )
    {
      v65 = gameLocal->GetRenderWorld(this: gameLocal);
      v161[4] = v114.x;
      v161[7] = 5.0;
      v161[6] = v114.z + (float)5.0;
      v161[5] = v114.y;
      v115.x = v114.y;
      DebugSphere = (void (*)(void))v65->DebugSphere;
      goto LABEL_60;
    }
LABEL_61:
    if ( validation->navProbeToPathPosition && v19 == 0 && v46 != 0 )
    {
      if ( v20->navTraces.ptr[2].fraction <= v18 )
      {
        if ( !v112 )
          goto LABEL_89;
        v19 = 11;
        v67 = gameLocal->GetRenderWorld(this: gameLocal);
        v68 = (float)(v128.z + (float)5.0);
        v69 = v128.y;
        v70 = v128.x;
        v153[1] = v128.y;
        v159[1] = v113.y;
        v154 = v128.z + (float)5.0;
        v159[2] = v113.z + (float)5.0;
        v153[0] = v128.x;
        v159[0] = v113.x;
        v115.x = v154;
        v67->DebugLine(
          this: v67,
          a2: (const idVec4 *)&idColor::colorOrange,
          a3: (const idVec3 *)v159,
          a4: (const idVec3 *)v153,
          a5: debugDrawTime,
          a6: false);
        v71 = gameLocal->GetRenderWorld(this: gameLocal);
        v165[0] = v70;
        v72 = &idColor::colorOrange;
        v165[1] = v69;
        v73 = v165;
        v165[2] = v68;
        v165[3] = 5.0;
        goto LABEL_69;
      }
      if ( v112 )
      {
        v74 = gameLocal->GetRenderWorld(this: gameLocal);
        v75 = (float)(v128.z + (float)5.0);
        v69 = v128.y;
        v76 = v128.x;
        v150[0] = v128.x;
        v150[1] = v128.y;
        v151 = v128.z + (float)5.0;
        v158[0] = v113.x;
        v158[1] = v113.y;
        v158[2] = v113.z + (float)5.0;
        v115.x = v151;
        v74->DebugLine(
          this: v74,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idVec3 *)v158,
          a4: (const idVec3 *)v150,
          a5: debugDrawTime,
          a6: false);
        v71 = gameLocal->GetRenderWorld(this: gameLocal);
        v160[0] = v76;
        v72 = &idColor::colorBlue;
        v160[1] = v69;
        v73 = v160;
        v160[2] = v75;
        v160[3] = 2.0;
LABEL_69:
        v77 = v71->__vftable;
        v115.x = v69;
        v77->DebugSphere(
          this: v71,
          a2: (const idVec4 *)v72,
          a3: (const idSphere *)v73,
          a4: 12,
          a5: debugDrawTime,
          a6: false);
        v18 = v125;
      }
    }
    suggestedFlags = validation->suggestedFlags;
    v79 = 1.0;
    if ( suggestedFlags != 0 && (v20->flags & suggestedFlags) != suggestedFlags )
      v79 = v133;
    v80 = 0.0;
    if ( validation->selectType == CHOOSE_CLOSEST_ANGLE_START )
    {
      v80 = (float)((float)((float)1.0 - (float)v42) + (float)v79);
    }
    else if ( validation->selectType == CHOOSE_CLOSEST_TO_PATH_RELATIVE )
    {
      DistanceToPath = idAnimWebTransitions::GetDistanceToPath(
                         path: p_cachedCorners,
                         startOrigin: &v116,
                         testPoint: &v113,
                         outPositionOnPath: v168,
                         outDirectionOnPath: &v115);
      v82 = 0.0;
      if ( v20->hasApex )
        v82 = __fsqrts((float)((float)((float)(v113.z - v114.z) * (float)(v113.z - v114.z))
                             + (float)((float)((float)(v113.x - v114.x) * (float)(v113.x - v114.x))
                                     + (float)((float)(v113.y - v114.y) * (float)(v113.y - v114.y)))));
      v80 = (float)((float)-(float)((float)((float)((float)__fsqrts((float)((float)((float)(v114.z - v116.z)
                                                                                  * (float)(v114.z - v116.z))
                                                                          + (float)((float)((float)(v114.x - v116.x)
                                                                                          * (float)(v114.x - v116.x))
                                                                                  + (float)((float)(v114.y - v116.y)
                                                                                          * (float)(v114.y - v116.y)))))
                                                  + (float)v82)
                                          * (float)0.0015)
                                  - (float)1.0)
                  * (float)((float)((float)((float)((float)1.0 - (float)v42) * valueFloat) * (float)v79)
                          + (float)((float)DistanceToPath / (float)v38)));
    }
    if ( v112 )
    {
      v83 = v130;
      if ( v19 == 0 )
        v83 = v134;
      v164.len = 0;
      v164.baseBuffer[0] = 0;
      v164.data = v164.baseBuffer;
      v164.allocedAndFlag = 20;
      idStr::Format(this: &v164, fmt: "%s : %f %s", v20->anim->name.str, v80, (const char *)LODWORD(v80));
      v84 = "^1";
      if ( v19 == 0 )
        v84 = "^3";
      idLib::Printf(fmt: "%s%s\n", v84, v164.data);
      v85 = gameLocal->GetRenderWorld(this: gameLocal);
      v148[0] = v113.x;
      v148[1] = v113.y;
      v148[2] = v113.z + (float)1.0;
      v86 = v85->__vftable;
      v115.x = v113.y;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v86->DebugText)(
        a1: v85,
        a2: v164.data,
        a3: v148,
        a4: v86,
        a5: v83,
        a6: 1,
        a7: debugDrawTime,
        a8: 0,
        a9: 0.125);
      v87 = gameLocal->GetRenderWorld(this: gameLocal);
      v161[0] = v113.x;
      v161[2] = v113.z;
      v161[1] = v113.y;
      v161[3] = 1.0;
      v87->DebugSphere(
        this: v87,
        a2: (const idVec4 *)v83,
        a3: (const idSphere *)v161,
        a4: 12,
        a5: debugDrawTime,
        a6: false);
      v88 = gameLocal->GetRenderWorld(this: gameLocal);
      v88->DebugLine(this: v88, a2: (const idVec4 *)v83, a3: &v113, a4: &v116, a5: debugDrawTime, a6: false);
      v89 = gameLocal->GetRenderWorld(this: gameLocal);
      v149[2] = v113.z + (float)((float)v39 * (float)10.0);
      v149[1] = v113.y + (float)((float)v40 * (float)10.0);
      v149[0] = (float)((float)x * (float)10.0) + v113.x;
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v89->DebugArrow)(
        a1: v89,
        a2: v83,
        a3: &v113,
        a4: v149,
        a5: 2.0);
      if ( v19 != 0 )
      {
        idStr::FreeData(this: &v164);
        goto LABEL_89;
      }
      idStr::FreeData(this: &v164);
    }
    if ( v80 < v122 )
    {
      v17 = x;
      v117 = v113.x;
      v118 = v113.y;
      v119 = v113.z;
      v124 = v121;
      v122 = v80;
      v138 = v40;
      v139 = v39;
    }
LABEL_89:
    v90 = cache->transitions.num;
    ++v121;
    v120 += 560;
  }
  while ( v121 < v90 );
  if ( v124 < 0 )
    return 0;
  v91 = &cache->transitions.list[v124];
  if ( v112 )
  {
    v166.len = 0;
    v166.baseBuffer[0] = 0;
    v166.data = v166.baseBuffer;
    v166.allocedAndFlag = 20;
    idStr::Format(
      this: &v166,
      fmt: "%s : %f",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v122)),
      (unsigned int)COERCE_UNSIGNED_INT64(v122));
    idLib::Printf(fmt: "> %s%s\n", "^2", v166.data);
    v92 = gameLocal->GetRenderWorld(this: gameLocal);
    LODWORD(v93) = debugDrawTime;
    *(_QWORD *)&v115.x = v93;
    v141[2] = v119 + (float)10.0;
    v141[0] = v117;
    v141[1] = v118;
    v94 = v92->__vftable;
    v95 = (double)v93;
    LODWORD(v93) = v92->DebugText;
    LODWORD(v115.y) = (int)(float)((float)v95 * (float)2.0);
    v96 = v115.y;
    ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v93)(
      a1: v92,
      a2: v166.data,
      a3: v141,
      a4: v94,
      a5: &idColor::colorGreen,
      a6: 1,
      a7: LODWORD(v115.y),
      a8: 0,
      a9: 0.125);
    v97 = gameLocal->GetRenderWorld(this: gameLocal);
    v162[0] = v117;
    v162[1] = v118;
    v162[2] = v119;
    v162[3] = 1.0;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, double, _DWORD))v97->DebugSphere)(
      a1: v97,
      a2: &idColor::colorGreen,
      a3: v162,
      a4: 12,
      a5: COERCE_DOUBLE(LODWORD(v96)),
      a6: 0);
    v98 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double, _DWORD))v98->DebugLine)(
      a1: v98,
      a2: &idColor::colorGreen,
      a3: &v117,
      a4: &v116,
      a5: COERCE_DOUBLE(LODWORD(v96)),
      a6: 0);
    v99 = gameLocal->GetRenderWorld(this: gameLocal);
    v142[0] = (float)((float)v17 * (float)10.0) + v117;
    v142[2] = v119 + (float)(v139 * (float)10.0);
    v142[1] = v118 + (float)(v138 * (float)10.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v99->DebugArrow)(
      a1: v99,
      a2: &idColor::colorGreen,
      a3: &v117,
      a4: v142,
      a5: 2.0);
    idStr::FreeData(this: &v166);
  }
  p_debugState = &v91->via.debugState;
  v101 = v116.y;
  v102 = v116.z;
  v103 = v117;
  v104 = v118;
  LODWORD(v115.x) = &out->destOrigin;
  v105 = v119;
  p_anim = &out[-1].anim;
  out->startOrigin.x = v116.x;
  v107 = 5;
  out->startOrigin.y = v101;
  out->startOrigin.z = v102;
  out->destOrigin.x = v103;
  out->destOrigin.y = v104;
  out->destOrigin.z = v105;
  do
  {
    ++p_debugState;
    *++p_anim = (const idMD6Anim *)p_debugState->str;
    --v107;
  }
  while ( v107 != 0 );
  p_approximatePathDistance = (const char **)&v91->approximatePathDistance;
  v109 = &out->dst.debugState;
  for ( i = 5; i != 0; --i )
  {
    ++p_approximatePathDistance;
    ++v109;
    v109->str = *p_approximatePathDistance;
  }
  out->selectionIndex = v91->selectionIndex;
  out->approximatePathDistance = v91->approximatePathDistance;
  out->anim = v91->anim;
  return 1;
}


// ========================================================================
// __unwind$490760
// EA  : 0x82A64BF4
// RVA : 0x00A64BF4
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_490760()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1216 + 736));
}


// ========================================================================
// __unwind$490761
// EA  : 0x82A64C1C
// RVA : 0x00A64C1C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_490761()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1216 + 784));
}


// ========================================================================
// ?FindTurnTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@@Z
// EA  : 0x82A64C50
// RVA : 0x00A64C50
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::FindTurnTransition(
        const idAI2 *ai,
        const idAnimWebTransitions::transitionQueryValidation_t *validation,
        idAnimWebTransitions::transitionCache_t *cache,
        const idAnimWebTransitions::transitionQueryParms_t *parms,
        idAnimWebTransitions::transitionQueryResult_t *out)
{
  int num; // r11
  const idAnimWebTransitions::transitionQueryValidation_t *v6; // r30
  idAnimWebTransitions::transitionCache_t *v7; // r29
  int entityNumber; // r9
  idMat3 *p_sourceAxis; // r26
  bool v11; // r11
  bool v12; // zf
  BOOL v13; // r3
  double v14; // fp16
  double v15; // fp17
  int v16; // r27
  int allowedFlags; // r9
  idAnimWebTransitions::transitionData_t *v18; // r30
  int flags; // r11
  double z; // fp0
  double v21; // fp13
  double v22; // fp12
  double y; // fp11
  double v24; // fp10
  double v25; // fp9
  double x; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp2
  double v30; // fp1
  double v31; // fp6
  double v32; // fp9
  double v33; // fp8
  float v34; // r5
  double v35; // fp30
  double v37; // fp7
  double v38; // fp26
  double v39; // fp15
  double v40; // fp14
  double v42; // fp5
  double v43; // fp10
  double v44; // fp8
  double v45; // fp12
  double v46; // fp9
  double v47; // fp22
  double v48; // fp28
  double v49; // fp1
  double v52; // fp4
  double v53; // fp2
  double v54; // fp7
  double v55; // fp7
  double v56; // fp23
  double v57; // fp24
  double v58; // fp25
  double v59; // fp2
  double v60; // fp6
  double v61; // fp2
  double v62; // fp3
  double v63; // fp1
  double v64; // fp5
  double v66; // fp26
  double v68; // fp27
  double v69; // fp21
  double v70; // fp13
  double v71; // fp4
  double v72; // fp13
  const idVec3 *v73; // r4
  double v74; // fp2
  double v75; // fp3
  double v76; // fp26
  double v77; // fp27
  double v78; // fp7
  double v79; // fp13
  double v80; // fp11
  idVec3 *p_turnPoint; // r29
  double v82; // fp5
  double v83; // fp1
  double v84; // fp3
  double v85; // fp12
  double v88; // fp7
  double v90; // fp6
  double v94; // fp13
  double v95; // fp4
  double v96; // fp9
  double v97; // fp2
  double v98; // fp10
  double v99; // fp5
  double v100; // fp2
  double v101; // fp11
  double v102; // fp13
  double v103; // fp1
  double v106; // fp6
  double v107; // fp10
  double v108; // fp7
  double v109; // fp6
  double v110; // fp12
  double v111; // fp13
  double v112; // fp12
  double v113; // fp9
  double v114; // fp5
  double v115; // fp3
  double v117; // fp1
  double v119; // fp13
  double v120; // fp9
  double v121; // fp30
  idColor *v122; // r29
  const char *v123; // r4
  idRenderWorld *v124; // r3
  idRenderWorld_vtbl *v125; // r6
  idRenderWorld *v126; // r3
  idRenderWorld *v127; // r3
  idRenderWorld *v128; // r3
  idRenderWorld *v129; // r3
  idRenderWorld *v130; // r3
  int v131; // r9
  int v132; // r29
  idRenderWorld *v133; // r3
  idRenderWorld *v134; // r3
  idRenderWorld *v135; // r3
  idRenderWorld *v136; // r3
  idRenderWorld *v137; // r3
  double v138; // fp13
  double v139; // fp12
  double v140; // fp11
  _DWORD *v141; // r11
  const idMD6Anim **p_anim; // r10
  int v143; // ctr
  const char **v144; // r11
  idAtomicString *p_debugState; // r10
  int i; // ctr
  bool hasApex; // [sp+60h] [-300h]
  BOOL v149; // [sp+64h] [-2FCh]
  int debugDrawTime; // [sp+68h] [-2F8h]
  float v151; // [sp+70h] [-2F0h] BYREF
  float v152; // [sp+74h] [-2ECh]
  float v153; // [sp+78h] [-2E8h]
  float v154; // [sp+80h] [-2E0h] BYREF
  float v155; // [sp+84h] [-2DCh]
  float v156; // [sp+88h] [-2D8h]
  idMat3 *p_deltaAxis; // [sp+8Ch] [-2D4h] BYREF
  float v158; // [sp+90h] [-2D0h]
  unsigned int v159; // [sp+94h] [-2CCh]
  int v160; // [sp+98h] [-2C8h]
  idVec3 v161; // [sp+A0h] [-2C0h] BYREF
  float v162; // [sp+ACh] [-2B4h]
  float v163; // [sp+B0h] [-2B0h]
  int v164; // [sp+B4h] [-2ACh]
  float v165; // [sp+B8h] [-2A8h] BYREF
  float v166; // [sp+BCh] [-2A4h]
  float v167; // [sp+C0h] [-2A0h]
  float v168; // [sp+C4h] [-29Ch]
  float v169; // [sp+C8h] [-298h]
  float valueFloat; // [sp+CCh] [-294h]
  float v171; // [sp+D0h] [-290h]
  float v172; // [sp+D8h] [-288h] BYREF
  float v173; // [sp+DCh] [-284h]
  float v174[4]; // [sp+E8h] [-278h] BYREF
  float v175[4]; // [sp+F8h] [-268h] BYREF
  float v176[4]; // [sp+108h] [-258h] BYREF
  idVec3 v177; // [sp+118h] [-248h]
  float v178; // [sp+128h] [-238h]
  float v179; // [sp+12Ch] [-234h]
  float v180; // [sp+130h] [-230h]
  float v181[4]; // [sp+138h] [-228h] BYREF
  float v182[6]; // [sp+148h] [-218h] BYREF
  idPlane v183; // [sp+160h] [-200h] BYREF
  idStr v184; // [sp+170h] [-1F0h] BYREF
  float v185[4]; // [sp+190h] [-1D0h] BYREF
  float v186[4]; // [sp+1A0h] [-1C0h] BYREF
  idStr v187; // [sp+1B0h] [-1B0h] BYREF
  idMat3 v188; // [sp+1D0h] [-190h] BYREF
  idMat3 v189; // [sp+200h] [-160h] BYREF
  idVec3 v190[13]; // [sp+228h] [-138h] BYREF

  v6 = validation;
  v7 = cache;
  num = cache->transitions.num;
  if ( num == 0 )
    return 0;
  if ( ai_forceNoTransitions.valueInteger > 0 )
    return 0;
  entityNumber = ai->entityNumber;
  debugDrawTime = parms->debugDrawTime;
  p_sourceAxis = &parms->sourceAxis;
  hasApex = false;
  v164 = -1;
  valueFloat = ai_turnAngleInfluence.valueFloat;
  v158 = 3.4028235e38;
  v160 = 0;
  v12 = num <= 0;
  v11 = (_cntlzw(entityNumber - ai_debugAnimWebTransitions.valueInteger) & 0x20) != 0;
  if ( v12 )
    return 0;
  v13 = v11;
  v14 = v179;
  v15 = v178;
  v159 = 0;
  v149 = v11;
  v168 = 2.0;
  v163 = 0.125;
  v162 = 32.0;
  v169 = 0.99000001;
  v171 = 100.0;
  while ( 1 )
  {
    v16 = 0;
    allowedFlags = v6->allowedFlags;
    v18 = &v7->transitions.list[v159 / 0x230];
    flags = v18->flags;
    if ( (allowedFlags | flags) != allowedFlags )
    {
      if ( !v13 )
        goto LABEL_39;
      v16 = 8;
    }
    if ( (validation->requiredFlags & flags) != validation->requiredFlags )
    {
      if ( !v13 )
        goto LABEL_39;
      v16 = 7;
    }
    z = v18->deltaAxis.mat[2].z;
    v21 = v18->deltaAxis.mat[1].z;
    v22 = v18->deltaAxis.mat[0].z;
    y = v18->deltaAxis.mat[2].y;
    v24 = v18->deltaAxis.mat[1].y;
    p_deltaAxis = &v18->deltaAxis;
    v25 = v18->deltaAxis.mat[0].y;
    x = v18->deltaAxis.mat[2].x;
    v27 = v18->deltaAxis.mat[1].x;
    v28 = v18->deltaAxis.mat[0].x;
    v188.mat[2].z = z;
    v188.mat[2].y = v21;
    v188.mat[2].x = v22;
    v188.mat[1].z = y;
    v188.mat[1].y = v24;
    v188.mat[1].x = v25;
    v188.mat[0].z = x;
    v188.mat[0].x = v28;
    v188.mat[0].y = v27;
    idMat3::operator*(this: &v189, result: &parms->sourceAxis, a: &v188);
    v29 = v18->deltaOrigin.y;
    v30 = v18->deltaOrigin.z;
    v161.y = parms->sourceAxis.mat[0].y;
    v31 = parms->sourceAxis.mat[1].z;
    v32 = (float)(parms->sourceAxis.mat[2].x * (float)v30);
    v33 = v18->deltaOrigin.x;
    v34 = parms->sourceAxis.mat[0].z;
    v161.x = p_sourceAxis->mat[0].x;
    v177 = v189.mat[0];
    v161.z = v34;
    v35 = idMath::FLT_SMALLEST_NON_DENORMAL;
    _FP3 = (float)((float)((float)(v189.mat[0].y * v189.mat[0].y) + (float)(v189.mat[0].x * v189.mat[0].x))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v37 = (float)((float)((float)(v189.mat[0].y * v189.mat[0].y) + (float)(v189.mat[0].x * v189.mat[0].x)) * (float)0.5);
    v38 = parms->sourceOrigin1.z;
    v39 = parms->sourceOrigin1.y;
    v40 = parms->sourceOrigin1.x;
    __asm { fsel      f4, f3, f4, f30 }
    v42 = (float)((float)(parms->sourceAxis.mat[0].y * (float)v33) + (float)(parms->sourceAxis.mat[1].y * (float)v29));
    v43 = (float)((float)(parms->sourceAxis.mat[2].z * (float)v30)
                + (float)((float)(parms->sourceAxis.mat[0].z * (float)v33) + (float)((float)v31 * (float)v29)));
    v44 = (float)((float)((float)v33 * parms->sourceAxis.mat[0].x)
                + (float)((float)(parms->sourceAxis.mat[1].x * (float)v29) + (float)v32));
    v45 = __frsqrte(_FP4);
    v46 = (float)((float)(parms->sourceAxis.mat[2].y * (float)v30) + (float)v42);
    v47 = (float)(parms->sourceOrigin1.x + (float)v44);
    v151 = parms->sourceOrigin1.x + (float)v44;
    v153 = (float)v38 + (float)v43;
    v48 = (float)((float)v39 + (float)v46);
    v152 = (float)v39 + (float)v46;
    v49 = (float)((float)-(float)((float)((float)((float)v45
                                                * (float)((float)((float)(v189.mat[0].y * v189.mat[0].y)
                                                                + (float)(v189.mat[0].x * v189.mat[0].x))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45);
    *(float *)&p_deltaAxis = 0.0;
    _FP6 = (float)((float)((float)(v161.x * v161.x) + (float)(v161.y * v161.y)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f6, f2, f30 }
    v52 = __frsqrte(_FP2);
    v53 = (float)((float)-(float)((float)((float)((float)v49
                                                * (float)((float)((float)(v189.mat[0].y * v189.mat[0].y)
                                                                + (float)(v189.mat[0].x * v189.mat[0].x))
                                                        * (float)0.5))
                                        * (float)v49)
                                - (float)1.5)
                * (float)v49);
    v54 = (float)((float)((float)-(float)((float)((float)((float)v49 * (float)v37) * (float)v49) - (float)1.5)
                        * (float)v49)
                * (float)v37);
    v56 = (float)((float)((float)-(float)((float)((float)v54 * (float)v53) - (float)1.5) * (float)v53) * (float)0.0);
    v57 = (float)(v189.mat[0].y * (float)((float)-(float)((float)((float)v54 * (float)v53) - (float)1.5) * (float)v53));
    v58 = (float)(v189.mat[0].x * (float)((float)-(float)((float)((float)v54 * (float)v53) - (float)1.5) * (float)v53));
    v59 = (float)(vec3_up.x
                * (float)((float)((float)-(float)((float)((float)v54 * (float)v53) - (float)1.5) * (float)v53)
                        * (float)0.0));
    v55 = (float)-(float)((float)((float)((float)v52
                                        * (float)((float)((float)(v161.x * v161.x) + (float)(v161.y * v161.y))
                                                * (float)0.5))
                                * (float)v52)
                        - (float)1.5);
    v60 = (float)((float)((float)v58 * vec3_up.z) - (float)v59);
    v61 = (float)((float)(vec3_up.y * (float)v56) - (float)((float)v57 * vec3_up.z));
    v62 = (float)((float)((float)v57 * vec3_up.x) - (float)((float)v58 * vec3_up.y));
    v63 = (float)((float)-(float)((float)((float)((float)((float)v55 * (float)v52)
                                                * (float)((float)((float)(v161.x * v161.x) + (float)(v161.y * v161.y))
                                                        * (float)0.5))
                                        * (float)((float)v55 * (float)v52))
                                - (float)1.5)
                * (float)((float)v55 * (float)v52));
    v64 = (float)((float)-(float)((float)((float)((float)v63
                                                * (float)((float)((float)(v161.x * v161.x) + (float)(v161.y * v161.y))
                                                        * (float)0.5))
                                        * (float)v63)
                                - (float)1.5)
                * (float)v63);
    _FP4 = (float)((float)((float)((float)v62 * (float)v62)
                         + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v66 = (float)(v161.y
                * (float)((float)-(float)((float)((float)((float)v63
                                                        * (float)((float)((float)(v161.x * v161.x)
                                                                        + (float)(v161.y * v161.y))
                                                                * (float)0.5))
                                                * (float)v63)
                                        - (float)1.5)
                        * (float)v63));
    __asm { fsel      f0, f4, f7, f30 }
    v68 = (float)(v161.x
                * (float)((float)-(float)((float)((float)((float)v63
                                                        * (float)((float)((float)(v161.x * v161.x)
                                                                        + (float)(v161.y * v161.y))
                                                                * (float)0.5))
                                                * (float)v63)
                                        - (float)1.5)
                        * (float)v63));
    v161.y = v161.y
           * (float)((float)-(float)((float)((float)((float)v63
                                                   * (float)((float)((float)(v161.x * v161.x) + (float)(v161.y * v161.y))
                                                           * (float)0.5))
                                           * (float)v63)
                                   - (float)1.5)
                   * (float)v63);
    v161.x = v161.x * (float)v64;
    v69 = (float)((float)v64 * (float)0.0);
    v161.z = (float)v64 * (float)0.0;
    v70 = __frsqrte(_FP0);
    v71 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                                                                                                * (float)0.5))
                                                                                * (float)v70)
                                                                        - (float)1.5)
                                                        * (float)v70)
                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                + (float)((float)((float)v61 * (float)v61)
                                                                        + (float)((float)v60 * (float)v60)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v70
                                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                                + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                                                                                        * (float)0.5))
                                                                        * (float)v70)
                                                                - (float)1.5)
                                                * (float)v70))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v70
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)v61 * (float)v61)
                                                                                + (float)((float)v60 * (float)v60)))
                                                                * (float)0.5))
                                                * (float)v70)
                                        - (float)1.5)
                        * (float)v70));
    v72 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v70) - (float)1.5)
                                                                                                * (float)v70)
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v70 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v70) - (float)1.5)
                                                                                        * (float)v70))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v70
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) * (float)0.5))
                                                                                        * (float)v70)
                                                                                - (float)1.5)
                                                                * (float)v70))
                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                + (float)((float)((float)v61 * (float)v61)
                                                                        + (float)((float)v60 * (float)v60)))
                                                        * (float)0.5))
                                        * (float)v71)
                                - (float)1.5)
                * (float)v71);
    v183.b = (float)v60 * (float)v72;
    v183.a = (float)((float)(vec3_up.y * (float)v56) - (float)((float)v57 * vec3_up.z)) * (float)v72;
    v183.c = (float)((float)((float)v57 * vec3_up.x) - (float)((float)v58 * vec3_up.y)) * (float)v72;
    v183.d = -(float)((float)(v183.c * v153) + (float)((float)(v183.a * (float)v47) + (float)(v183.b * v152)));
    idPlane::RayIntersection(this: &v183, start: &parms->sourceOrigin1, dir: &v161, scale: (float *)&p_deltaAxis);
    v74 = parms->sourceOrigin1.z;
    v75 = (float)((float)v66 * *(float *)&p_deltaAxis);
    v78 = (float)((float)v39 - (float)((float)v39 + (float)((float)v66 * *(float *)&p_deltaAxis)));
    v79 = (float)((float)v39 - parms->turnPoint.y);
    v80 = (float)((float)v40 - parms->turnPoint.x);
    v166 = (float)v39 + (float)((float)v66 * *(float *)&p_deltaAxis);
    v76 = (float)((float)((float)v68 * *(float *)&p_deltaAxis) + (float)v40);
    v165 = (float)((float)v68 * *(float *)&p_deltaAxis) + (float)v40;
    v77 = (float)((float)v39 + (float)v75);
    p_turnPoint = &parms->turnPoint;
    v82 = (float)((float)v48 - (float)((float)v39 + (float)v75));
    v167 = (float)v74 + (float)(*(float *)&p_deltaAxis * (float)v69);
    v83 = (float)((float)((float)((float)v40 - (float)v76) * (float)((float)v40 - (float)v76))
                + (float)((float)v78 * (float)v78));
    v84 = (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79));
    v85 = (float)((float)((float)((float)v47 - (float)v76) * (float)((float)v47 - (float)v76))
                + (float)((float)v82 * (float)v82));
    _FP10 = (float)((float)((float)((float)((float)v40 - (float)v76) * (float)((float)v40 - (float)v76))
                          + (float)((float)v78 * (float)v78))
                  - (float)v35);
    _FP13 = (float)((float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)) - (float)v35);
    v88 = (float)((float)((float)((float)((float)v40 - (float)v76) * (float)((float)v40 - (float)v76))
                        + (float)((float)v78 * (float)v78))
                * (float)0.5);
    _FP8 = (float)((float)((float)((float)((float)v47 - (float)v76) * (float)((float)v47 - (float)v76))
                         + (float)((float)v82 * (float)v82))
                 - (float)v35);
    v90 = (float)((float)((float)((float)((float)v47 - (float)v76) * (float)((float)v47 - (float)v76))
                        + (float)((float)v82 * (float)v82))
                * (float)0.5);
    __asm
    {
      fsel      f5, f10, f1, f30
      fsel      f9, f13, f3, f30
      fsel      f2, f8, f12, f30
    }
    v94 = __frsqrte(_FP5);
    v95 = __frsqrte(_FP9);
    v96 = __frsqrte(_FP2);
    v97 = (float)((float)-(float)((float)((float)((float)v95 * (float)((float)v84 * (float)0.5)) * (float)v95)
                                - (float)1.5)
                * (float)v95);
    v98 = (float)((float)-(float)((float)((float)((float)v94 * (float)v88) * (float)v94) - (float)1.5) * (float)v94);
    v99 = (float)((float)-(float)((float)((float)((float)v97 * (float)((float)v84 * (float)0.5)) * (float)v97)
                                - (float)1.5)
                * (float)v97);
    v101 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v96 * (float)v90)
                                                                                 * (float)v96)
                                                                         - (float)1.5)
                                                         * (float)v96)
                                                 * (float)v90)
                                         * (float)((float)-(float)((float)((float)((float)v96 * (float)v90) * (float)v96)
                                                                 - (float)1.5)
                                                 * (float)v96))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v96 * (float)v90) * (float)v96) - (float)1.5)
                         * (float)v96));
    v102 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v97
                                                                                                 * (float)((float)v84 * (float)0.5))
                                                                                         * (float)v97)
                                                                                 - (float)1.5)
                                                                 * (float)v97)
                                                         * (float)((float)v84 * (float)0.5))
                                                 * (float)v99)
                                         - (float)1.5)
                         * (float)v99)
                 * (float)v84);
    v100 = (float)((float)-(float)((float)((float)((float)v98 * (float)v88) * (float)v98) - (float)1.5) * (float)v98);
    v103 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v96 * (float)v90) * (float)v96) - (float)1.5) * (float)v96) * (float)v90)
                                                                                                 * (float)((float)-(float)((float)((float)((float)v96 * (float)v90) * (float)v96) - (float)1.5) * (float)v96))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v96 * (float)v90) * (float)v96)
                                                                                                 - (float)1.5)
                                                                                 * (float)v96))
                                                                 * (float)v90)
                                                         * (float)v101)
                                                 - (float)1.5)
                                 * (float)v101)
                         * (float)v85)
                 + (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)v88)
                                                                                                 * (float)v98)
                                                                                         - (float)1.5)
                                                                         * (float)v98)
                                                                 * (float)v88)
                                                         * (float)v100)
                                                 - (float)1.5)
                                 * (float)v100)
                         * (float)v83));
    if ( v102 > *(float *)&p_deltaAxis || v102 < (float)(*(float *)&p_deltaAxis - v171) )
    {
      if ( !v149 )
        goto LABEL_38;
      v16 = 4;
    }
    idAnimWebTransitions::GetPathPositionAndDirection(
      path: &parms->cachedCorners,
      distanceAhead: v103,
      startPosition: v73,
      startDirection: &parms->sourceOrigin1,
      outPosition: parms->sourceAxis.mat,
      outDirection: v190,
      a7: &v172);
    _FP9 = (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f0 }
    v106 = __frsqrte(_FP7);
    v107 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v106
                                                                                         * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                                                                 * (float)0.5))
                                                                                 * (float)v106)
                                                                         - (float)1.5)
                                                         * (float)v106)
                                                 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v106
                                                                                 * (float)((float)((float)(v172 * v172)
                                                                                                 + (float)(v173 * v173))
                                                                                         * (float)0.5))
                                                                         * (float)v106)
                                                                 - (float)1.5)
                                                 * (float)v106))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v106
                                                         * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                                 * (float)0.5))
                                                 * (float)v106)
                                         - (float)1.5)
                         * (float)v106));
    v108 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5)
                                                                                                 * (float)v106)
                                                                                         * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5)
                                                                                         * (float)v106))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v106
                                                                                                 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5))
                                                                                         * (float)v106)
                                                                                 - (float)1.5)
                                                                 * (float)v106))
                                                 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                         * (float)0.5))
                                         * (float)v107)
                                 - (float)1.5)
                 * (float)v107);
    v110 = (float)(v172
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5) * (float)v106)
                                                                                                 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5)
                                                                                                 * (float)v106))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5))
                                                                                                 * (float)v106)
                                                                                         - (float)1.5)
                                                                         * (float)v106))
                                                         * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                                 * (float)0.5))
                                                 * (float)v107)
                                         - (float)1.5)
                         * (float)v107));
    v109 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5) * (float)v106)
                                                                                                 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5)) * (float)v106) - (float)1.5)
                                                                                                 * (float)v106))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v106 * (float)((float)((float)(v172 * v172) + (float)(v173 * v173)) * (float)0.5))
                                                                                                 * (float)v106)
                                                                                         - (float)1.5)
                                                                         * (float)v106))
                                                         * (float)((float)((float)(v172 * v172) + (float)(v173 * v173))
                                                                 * (float)0.5))
                                                 * (float)v107)
                                         - (float)1.5)
                         * (float)v107)
                 * (float)0.0);
    v172 = v110;
    v173 = v173 * (float)v108;
    v111 = (float)((float)(v173 * (float)v57)
                 + (float)((float)((float)v110 * (float)v58) + (float)((float)v109 * (float)v56)));
    if ( v16 == 0 )
    {
      if ( v111 >= 0.86602539 )
      {
        if ( v18->navTraces.ptr[0].fraction <= (double)v169 )
        {
          if ( !v149 )
            goto LABEL_38;
          v16 = 6;
        }
      }
      else
      {
        if ( !v149 )
          goto LABEL_38;
        v16 = 2;
      }
    }
    v112 = 0.0;
    if ( validation->suggestedFlags != 0 && (validation->suggestedFlags & v18->flags) != validation->suggestedFlags )
      v112 = 0.1;
    v113 = (float)(parms->turnPoint.y - (float)v77);
    v114 = (float)((float)((float)1.0 - (float)v111) + (float)v112);
    v115 = (float)((float)((float)(p_turnPoint->x - (float)v76) * (float)(p_turnPoint->x - (float)v76))
                 + (float)((float)v113 * (float)v113));
    _FP2 = (float)((float)((float)((float)(p_turnPoint->x - (float)v76) * (float)(p_turnPoint->x - (float)v76))
                         + (float)((float)v113 * (float)v113))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v117 = (float)((float)((float)((float)(p_turnPoint->x - (float)v76) * (float)(p_turnPoint->x - (float)v76))
                         + (float)((float)v113 * (float)v113))
                 * (float)0.5);
    __asm { fsel      f0, f2, f3, f0 }
    v119 = __frsqrte(_FP0);
    v120 = (float)((float)-(float)((float)((float)((float)v119
                                                 * (float)((float)((float)((float)(p_turnPoint->x - (float)v76)
                                                                         * (float)(p_turnPoint->x - (float)v76))
                                                                 + (float)((float)v113 * (float)v113))
                                                         * (float)0.5))
                                         * (float)v119)
                                 - (float)1.5)
                 * (float)v119);
    v121 = (float)((float)((float)v114 * valueFloat)
                 + (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v120 * (float)v117)
                                                                                                 * (float)v120)
                                                                                         - (float)1.5)
                                                                         * (float)v120)
                                                                 * (float)v117)
                                                         * (float)((float)-(float)((float)((float)((float)v120
                                                                                                 * (float)v117)
                                                                                         * (float)v120)
                                                                                 - (float)1.5)
                                                                 * (float)v120))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v120 * (float)v117) * (float)v120)
                                                         - (float)1.5)
                                         * (float)v120))
                         * (float)v115));
    if ( !v149 )
      goto LABEL_36;
    v122 = &idColor::colorRed;
    if ( v16 == 0 )
      v122 = &idColor::colorYellow;
    v184.len = 0;
    v184.baseBuffer[0] = 0;
    v184.data = v184.baseBuffer;
    v184.allocedAndFlag = 20;
    idStr::Format(this: &v184, fmt: "%s : %f %s", v18->anim->name.str, v121, (const char *)LODWORD(v121));
    v123 = "^1";
    if ( v16 == 0 )
      v123 = "^3";
    idLib::Printf(fmt: "%s%s\n", v123, v184.data);
    v124 = gameLocal->GetRenderWorld(this: gameLocal);
    v175[0] = v151;
    v175[1] = v152;
    v175[2] = v153 + v162;
    v125 = v124->__vftable;
    *(float *)&p_deltaAxis = v152;
    ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v125->DebugText)(
      a1: v124,
      a2: v184.data,
      a3: v175,
      a4: v125,
      a5: v122,
      a6: 1,
      a7: 1,
      a8: 0,
      a9: v163);
    v126 = gameLocal->GetRenderWorld(this: gameLocal);
    v185[0] = v151;
    v185[1] = v152;
    v185[2] = v153;
    v185[3] = 1.0;
    v126->DebugSphere(this: v126, a2: (const idVec4 *)v122, a3: (const idSphere *)v185, a4: 12, a5: 1, a6: false);
    v127 = gameLocal->GetRenderWorld(this: gameLocal);
    v127->DebugLine(
      this: v127,
      a2: (const idVec4 *)v122,
      a3: (const idVec3 *)&v151,
      a4: (const idVec3 *)&v165,
      a5: 1,
      a6: false);
    v128 = gameLocal->GetRenderWorld(this: gameLocal);
    v181[2] = v153 + (float)((float)v56 * (float)10.0);
    v181[1] = v152 + (float)((float)v57 * (float)10.0);
    v181[0] = (float)((float)v58 * (float)10.0) + v151;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v128->DebugArrow)(
      a1: v128,
      a2: v122,
      a3: &v151,
      a4: v181,
      a5: v168);
    if ( v18->hasApex )
    {
      v129 = gameLocal->GetRenderWorld(this: gameLocal);
      v129->DebugLine(
        this: v129,
        a2: (const idVec4 *)v122,
        a3: &parms->sourceOrigin1,
        a4: (const idVec3 *)&v165,
        a5: 1,
        a6: false);
    }
    v130 = gameLocal->GetRenderWorld(this: gameLocal);
    v130->DebugLine(
      this: v130,
      a2: (const idVec4 *)v122,
      a3: (const idVec3 *)&v151,
      a4: (const idVec3 *)&v165,
      a5: 1,
      a6: false);
    if ( v16 == 0 )
    {
      idStr::FreeData(this: &v184);
      v47 = v151;
LABEL_36:
      if ( v121 < v158 )
      {
        v15 = v58;
        v14 = v57;
        v174[0] = v165;
        v164 = v160;
        v174[1] = v166;
        v155 = v152;
        v154 = v47;
        v174[2] = v167;
        v156 = v153;
        hasApex = v18->hasApex;
        v158 = v121;
        v180 = v56;
      }
      goto LABEL_38;
    }
    idStr::FreeData(this: &v184);
LABEL_38:
    v7 = cache;
LABEL_39:
    v131 = v7->transitions.num;
    ++v160;
    v159 += 560;
    if ( v160 >= v131 )
      break;
    v6 = validation;
    v13 = v149;
  }
  if ( v164 < 0 )
    return 0;
  v132 = (int)&v7->transitions.list[v164];
  if ( v149 )
  {
    v187.len = 0;
    v187.baseBuffer[0] = 0;
    v187.data = v187.baseBuffer;
    v187.allocedAndFlag = 20;
    idStr::Format(
      this: &v187,
      fmt: "%s : %f",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v158)),
      (unsigned int)COERCE_UNSIGNED_INT64(v158));
    idLib::Printf(fmt: "> %s%s\n", "^2", v187.data);
    v133 = gameLocal->GetRenderWorld(this: gameLocal);
    v176[0] = v154;
    v176[1] = v155;
    v176[2] = v156 + v162;
    ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v133->DebugText)(
      a1: v133,
      a2: v187.data,
      a3: v176,
      a4: v133->DebugText,
      a5: &idColor::colorGreen,
      a6: 1,
      a7: debugDrawTime,
      a8: 0,
      a9: v163);
    v134 = gameLocal->GetRenderWorld(this: gameLocal);
    v186[0] = v154;
    v186[1] = v155;
    v186[2] = v156;
    v186[3] = 1.0;
    v134->DebugSphere(
      this: v134,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idSphere *)v186,
      a4: 12,
      a5: debugDrawTime,
      a6: false);
    v135 = gameLocal->GetRenderWorld(this: gameLocal);
    v135->DebugLine(
      this: v135,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&v154,
      a4: (const idVec3 *)v174,
      a5: debugDrawTime,
      a6: false);
    v136 = gameLocal->GetRenderWorld(this: gameLocal);
    v182[1] = v155 + (float)((float)v14 * (float)10.0);
    v182[0] = (float)((float)v15 * (float)10.0) + v154;
    v182[2] = v156 + (float)(v180 * (float)10.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v136->DebugArrow)(
      a1: v136,
      a2: &idColor::colorGreen,
      a3: &v154,
      a4: v182,
      a5: v168);
    if ( hasApex )
    {
      v137 = gameLocal->GetRenderWorld(this: gameLocal);
      v137->DebugLine(
        this: v137,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: &parms->sourceOrigin1,
        a4: (const idVec3 *)v174,
        a5: debugDrawTime,
        a6: false);
    }
    idStr::FreeData(this: &v187);
  }
  v138 = v154;
  v139 = v155;
  v140 = v156;
  v141 = (_DWORD *)(v132 + 208);
  out->startOrigin.x = parms->sourceOrigin1.x;
  p_anim = &out[-1].anim;
  out->startOrigin.y = parms->sourceOrigin1.y;
  v143 = 5;
  out->startOrigin.z = parms->sourceOrigin1.z;
  out->destOrigin.x = v138;
  out->destOrigin.y = v139;
  out->destOrigin.z = v140;
  do
  {
    *++p_anim = (const idMD6Anim *)*++v141;
    --v143;
  }
  while ( v143 != 0 );
  v144 = (const char **)(v132 + 168);
  p_debugState = &out->dst.debugState;
  for ( i = 5; i != 0; --i )
  {
    ++v144;
    ++p_debugState;
    p_debugState->str = *v144;
  }
  out->selectionIndex = *(_DWORD *)(v132 + 556);
  out->approximatePathDistance = *(float *)(v132 + 168);
  out->anim = *(const idMD6Anim **)(v132 + 232);
  return 1;
}


// ========================================================================
// __unwind$491671
// EA  : 0x82A65928
// RVA : 0x00A65928
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_491671()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 368));
}


// ========================================================================
// __unwind$491672
// EA  : 0x82A65950
// RVA : 0x00A65950
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_491672()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 432));
}


// ========================================================================
// ?FindCommonArrivalTransition@idAnimWebTransitions@@SA_NPBVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@AAUtransitionQueryResult_t@1@@Z
// EA  : 0x82A65980
// RVA : 0x00A65980
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::FindCommonArrivalTransition(
        const idAI2 *ai,
        const idAnimWebTransitions::transitionQueryValidation_t *validation,
        idAnimWebTransitions::transitionCache_t *cache,
        const idAnimWebTransitions::transitionQueryParms_t *parms,
        idAnimWebTransitions::transitionQueryResult_t *out)
{
  int entityNumber; // r8
  float y; // r4
  float z; // r3
  int *v11; // r10
  float *p_z; // r9
  int v13; // ctr
  bool v14; // r8
  float v15; // r5
  int *v16; // r10
  float v17; // r4
  float *v18; // r11
  int v19; // ctr
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double movementDistanceFudge; // fp7
  double v24; // fp9
  double v27; // fp8
  double v28; // fp5
  double v31; // fp30
  double v32; // fp29
  double v33; // fp28
  int debugDrawTime; // r26
  idRenderWorld *v35; // r3
  idRenderWorld *v36; // r3
  int num; // r10
  int v38; // r18
  idAnimWebTransitions::transitionData_t *v39; // r29
  int v40; // r28
  int flags; // r11
  double v42; // fp20
  double v43; // fp13
  double v44; // fp11
  double v45; // fp9
  char v46; // r25
  BOOL usePathDirectionForMoveAlign; // r8
  double v48; // fp31
  double v49; // fp30
  double v50; // fp29
  double v51; // fp16
  double v52; // fp15
  double v53; // fp14
  double v54; // fp28
  double v55; // fp27
  double v56; // fp26
  double DistanceToPath; // fp1
  double v58; // fp23
  double v59; // fp22
  double v60; // fp21
  double v61; // fp17
  double requiredSourceAlignAngleDot; // fp0
  double v63; // fp18
  BOOL hasApex; // r30
  double v65; // fp28
  double v66; // fp31
  double v67; // fp30
  double requiredMoveAlignAngleDot; // fp29
  double requiredApexAlignAngleDot; // fp29
  double v70; // fp0
  int *v71; // r3
  int v72; // r9
  idRenderWorld *v73; // r3
  idRenderWorld_vtbl *v74; // r9
  idRenderWorld *v75; // r3
  void (*DebugLine)(void); // r11
  idRenderWorld *v77; // r3
  int suggestedFlags; // r11
  double v79; // fp27
  double v80; // fp29
  idAnimWebTransitions::transitionQueryValidation_t::selectionType_t selectType; // r11
  double v82; // fp26
  double v83; // fp0
  int v84; // r3
  idColor *v85; // r30
  idRenderWorld *v86; // r3
  idRenderWorld_vtbl *v87; // r11
  int v88; // r3
  idRenderWorld *v89; // r3
  double v91; // fp2
  double v93; // fp13
  double v94; // fp8
  double v95; // fp3
  double v96; // fp1
  double v97; // fp0
  double v98; // fp13
  double v99; // fp1
  double v100; // fp0
  double v101; // fp3
  double v102; // fp31
  idColor *v103; // r30
  const char *v104; // r4
  idRenderWorld *v105; // r3
  idRenderWorld *v106; // r3
  idRenderWorld *v107; // r3
  idRenderWorld *v108; // r3
  idAnimWebTransitions::transitionData_t *v109; // r30
  idRenderWorld *v110; // r3
  double v111; // fp31
  void (__fastcall *DebugText)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool); // r6
  float v113; // r28
  idRenderWorld *v114; // r3
  idRenderWorld *v115; // r3
  idRenderWorld *v116; // r3
  idAtomicString *p_debugState; // r11
  double v118; // fp13
  double v119; // fp12
  double v120; // fp11
  double v121; // fp10
  double v122; // fp9
  const idMD6Anim **p_anim; // r10
  int v124; // ctr
  const char **p_approximatePathDistance; // r11
  idAtomicString *v126; // r10
  int i; // ctr
  char v129; // [sp+60h] [-460h]
  BOOL v130; // [sp+64h] [-45Ch]
  idVec3 v131; // [sp+68h] [-458h] BYREF
  float x; // [sp+78h] [-448h] BYREF
  float v133; // [sp+7Ch] [-444h]
  float v134; // [sp+80h] [-440h]
  char v135; // [sp+84h] [-43Ch]
  idVec3 v136; // [sp+88h] [-438h] BYREF
  idVec3 v137; // [sp+98h] [-428h] BYREF
  float v138; // [sp+A8h] [-418h] BYREF
  float v139; // [sp+ACh] [-414h]
  float v140; // [sp+B0h] [-410h]
  idVec3 v141; // [sp+B8h] [-408h] BYREF
  float v142; // [sp+C4h] [-3FCh]
  float v143; // [sp+C8h] [-3F8h]
  float v144; // [sp+CCh] [-3F4h]
  float v145; // [sp+D0h] [-3F0h]
  idVec3 v146; // [sp+D8h] [-3E8h] BYREF
  float v147; // [sp+E4h] [-3DCh]
  float v148; // [sp+E8h] [-3D8h]
  idColor *v149; // [sp+ECh] [-3D4h]
  float v150; // [sp+F0h] [-3D0h]
  int v151; // [sp+F4h] [-3CCh]
  float v152; // [sp+F8h] [-3C8h]
  float v153; // [sp+FCh] [-3C4h]
  float valueFloat; // [sp+100h] [-3C0h]
  float v155; // [sp+108h] [-3B8h]
  float v156; // [sp+10Ch] [-3B4h]
  float v157; // [sp+110h] [-3B0h]
  int v158; // [sp+11Ch] [-3A4h] BYREF
  idVec3 v159; // [sp+120h] [-3A0h]
  float v160; // [sp+12Ch] [-394h]
  float v161; // [sp+130h] [-390h]
  float v162; // [sp+134h] [-38Ch]
  float v163; // [sp+138h] [-388h]
  float v164; // [sp+13Ch] [-384h]
  float v165; // [sp+140h] [-380h]
  idVec3 v166; // [sp+148h] [-378h] BYREF
  idVec3 v167; // [sp+158h] [-368h] BYREF
  idColor *v168; // [sp+164h] [-35Ch]
  float v169; // [sp+168h] [-358h]
  float v170; // [sp+170h] [-350h]
  float v171; // [sp+174h] [-34Ch]
  float v172; // [sp+178h] [-348h]
  idColor *v173; // [sp+17Ch] [-344h]
  float v174; // [sp+180h] [-340h]
  float v175; // [sp+184h] [-33Ch]
  float v176; // [sp+188h] [-338h]
  float v177; // [sp+18Ch] [-334h]
  float v178; // [sp+190h] [-330h]
  float v179; // [sp+198h] [-328h]
  float v180; // [sp+19Ch] [-324h]
  float v181; // [sp+1A0h] [-320h]
  float v182[4]; // [sp+1A8h] [-318h] BYREF
  float v183[2]; // [sp+1B8h] [-308h] BYREF
  float v184; // [sp+1C0h] [-300h]
  float v185[4]; // [sp+1C8h] [-2F8h] BYREF
  float v186[2]; // [sp+1D8h] [-2E8h] BYREF
  float v187; // [sp+1E0h] [-2E0h]
  float v188[4]; // [sp+1E8h] [-2D8h] BYREF
  float v189[2]; // [sp+1F8h] [-2C8h] BYREF
  float v190; // [sp+200h] [-2C0h]
  float v191[4]; // [sp+208h] [-2B8h] BYREF
  float v192[4]; // [sp+218h] [-2A8h] BYREF
  float v193[4]; // [sp+228h] [-298h] BYREF
  float v194[4]; // [sp+238h] [-288h] BYREF
  float v195[4]; // [sp+248h] [-278h] BYREF
  float v196[8]; // [sp+258h] [-268h] BYREF
  float v197[4]; // [sp+278h] [-248h] BYREF
  float v198[6]; // [sp+288h] [-238h] BYREF
  float v199[4]; // [sp+2A0h] [-220h] BYREF
  float v200[4]; // [sp+2B0h] [-210h] BYREF
  idStr v201; // [sp+2C0h] [-200h] BYREF
  float v202; // [sp+2E0h] [-1E0h]
  float v203; // [sp+2E4h] [-1DCh]
  float v204; // [sp+2E8h] [-1D8h]
  float v205; // [sp+2ECh] [-1D4h]
  float v206[4]; // [sp+2F0h] [-1D0h] BYREF
  float v207[4]; // [sp+300h] [-1C0h] BYREF
  idStr v208; // [sp+310h] [-1B0h] BYREF
  idMat3 v209; // [sp+330h] [-190h] BYREF
  int v210; // [sp+35Ch] [-164h] BYREF
  idMat3 v211; // [sp+360h] [-160h] BYREF
  idVec3 v212[13]; // [sp+388h] [-138h] BYREF

  if ( cache->transitions.num == 0 || ai_forceNoTransitions.valueInteger > 0 )
    return 0;
  entityNumber = ai->entityNumber;
  y = parms->sourceOrigin1.y;
  z = parms->sourceOrigin1.z;
  v11 = &v158;
  p_z = &parms->sourceOrigin2.z;
  v13 = 9;
  v137.x = parms->sourceOrigin1.x;
  v137.y = y;
  v137.z = z;
  v14 = (_cntlzw(entityNumber - ai_debugAnimWebTransitions.valueInteger) & 0x20) != 0;
  do
  {
    *++v11 = *(_DWORD *)++p_z;
    --v13;
  }
  while ( v13 != 0 );
  v15 = parms->destinationOrigin.y;
  v16 = &v210;
  v17 = parms->destinationOrigin.z;
  v18 = &parms->destinationOrigin.z;
  x = parms->destinationOrigin.x;
  v19 = 9;
  v133 = v15;
  v134 = v17;
  do
  {
    *++v16 = *(_DWORD *)++v18;
    --v19;
  }
  while ( v19 != 0 );
  v20 = (float)(v133 - v137.y);
  v21 = (float)(x - v137.x);
  v22 = (float)(v134 - v137.z);
  v150 = 0.5;
  movementDistanceFudge = validation->movementDistanceFudge;
  v148 = 1.5;
  v24 = 0.0;
  v169 = 0.0;
  _FP3 = (float)((float)((float)((float)(v134 - v137.z) * (float)(v134 - v137.z))
                       + (float)((float)((float)(x - v137.x) * (float)(x - v137.x))
                               + (float)((float)(v133 - v137.y) * (float)(v133 - v137.y))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f13 }
  v27 = __frsqrte(_FP1);
  v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                      * (float)((float)((float)((float)v22 * (float)v22) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)))
                                                                                              * (float)0.5))
                                                                              * (float)v27)
                                                                      - (float)1.5)
                                                      * (float)v27)
                                              * (float)((float)((float)((float)v22 * (float)v22)
                                                              + (float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)v20 * (float)v20)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v27
                                                                              * (float)((float)((float)((float)v22 * (float)v22)
                                                                                              + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)))
                                                                                      * (float)0.5))
                                                                      * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v27
                                                      * (float)((float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)((float)v21 * (float)v21)
                                                                              + (float)((float)v20 * (float)v20)))
                                                              * (float)0.5))
                                              * (float)v27)
                                      - (float)1.5)
                      * (float)v27));
  _FP0 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v22 * (float)v22) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27) * (float)((float)((float)((float)v22 * (float)v22) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v22 * (float)v22) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v22 * (float)v22) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v27)
                                                                                               - (float)1.5)
                                                                               * (float)v27))
                                                               * (float)((float)((float)((float)v22 * (float)v22)
                                                                               + (float)((float)((float)v21 * (float)v21)
                                                                                       + (float)((float)v20 * (float)v20)))
                                                                       * (float)0.5))
                                                       * (float)v28)
                                               - (float)1.5)
                               * (float)v28)
                       * (float)((float)((float)v22 * (float)v22)
                               + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))))
               - (float)movementDistanceFudge);
  __asm { fsel      f0, f0, f0, f9 }
  v143 = 1.0;
  if ( __fabs(_FP0) >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v24 = (float)((float)_FP0 * (float)_FP0);
    v31 = (float)((float)((float)1.0 / (float)_FP0) * (float)(x - v137.x));
    v32 = (float)((float)((float)1.0 / (float)_FP0) * (float)(v133 - v137.y));
    v33 = (float)((float)((float)1.0 / (float)_FP0) * (float)(v134 - v137.z));
  }
  else
  {
    v31 = v159.x;
    v32 = v159.y;
    v33 = v159.z;
  }
  debugDrawTime = parms->debugDrawTime;
  v157 = v33;
  v156 = v32;
  v155 = v31;
  v144 = v24;
  v130 = v14;
  v142 = 2.0;
  v149 = &idColor::colorBlue;
  if ( v14 )
  {
    v35 = gameLocal->GetRenderWorld(this: gameLocal);
    v198[2] = v134 + (float)(v211.mat[0].z * (float)20.0);
    v198[1] = v133 + (float)(v211.mat[0].y * (float)20.0);
    v198[0] = (float)(v211.mat[0].x * (float)20.0) + x;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v35->DebugArrow)(
      a1: v35,
      a2: &idColor::colorBlue,
      a3: &x,
      a4: v198,
      a5: 2.0);
    v36 = gameLocal->GetRenderWorld(this: gameLocal);
    v196[2] = v134 + (float)((float)v33 * (float)20.0);
    v196[1] = v133 + (float)((float)v32 * (float)20.0);
    v196[0] = (float)((float)v31 * (float)20.0) + x;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v36->DebugArrow)(
      a1: v36,
      a2: &idColor::colorOrange,
      a3: &x,
      a4: v196,
      a5: 2.0);
    if ( validation->selectType == CHOOSE_CLOSEST_TO_PATH_RELATIVE )
      idAnimBaseFSM::DebugDrawCurrentCorners(
        this: &ai->aiVolatile.animation.animFSM,
        startOrigin: (const idVec3 *)LODWORD(idColor::colorCyan.r),
        color: (const idColor *)LODWORD(idColor::colorCyan.b),
        lifetime: SLODWORD(idColor::colorCyan.a));
  }
  num = cache->transitions.num;
  v135 = 0;
  v129 = 0;
  v38 = 0;
  v151 = -1;
  valueFloat = ai_arrivalAngleInfluence.valueFloat;
  v147 = 3.4028235e38;
  if ( num <= 0 )
    return 0;
  v153 = 10.0;
  v152 = 0.125;
  v177 = 0.001;
  v178 = 1.1;
  v145 = 0.99000001;
  v173 = &idColor::colorYellow;
  v168 = &idColor::colorRed;
  do
  {
    v39 = &cache->transitions.list[v38];
    v40 = 0;
    flags = v39->flags;
    if ( (validation->allowedFlags | flags) != validation->allowedFlags )
    {
      if ( !v130 )
        goto LABEL_117;
      v40 = 8;
    }
    if ( (validation->requiredFlags & flags) != validation->requiredFlags )
    {
      if ( !v130 )
        goto LABEL_117;
      v40 = 7;
    }
    v42 = (float)((float)(v39->deltaOrigin.z * v39->deltaOrigin.z)
                + (float)((float)(v39->deltaOrigin.x * v39->deltaOrigin.x)
                        + (float)(v39->deltaOrigin.y * v39->deltaOrigin.y)));
    if ( validation->checkMaxMovementDistance
      && validation->allowRejections
      && v39->deltaCorrectEndDistanceSqr > (double)v144 )
    {
      if ( !v130 )
        goto LABEL_117;
      v40 = 4;
    }
    idMat3::operator*(this: &v209, result: &v211, a: &v39->deltaAxis);
    v43 = -v39->deltaOrigin.y;
    v44 = -v39->deltaOrigin.x;
    v45 = -v39->deltaOrigin.z;
    v46 = 0;
    usePathDirectionForMoveAlign = validation->usePathDirectionForMoveAlign;
    v167 = v159;
    v48 = v209.mat[1].z;
    v49 = v209.mat[1].y;
    v50 = v209.mat[1].x;
    v51 = v209.mat[0].z;
    v52 = v209.mat[0].y;
    v53 = v209.mat[0].x;
    v54 = v209.mat[2].z;
    v55 = v209.mat[2].y;
    v56 = v209.mat[2].x;
    DistanceToPath = (float)((float)((float)v44 * v209.mat[0].y) + (float)((float)v43 * v209.mat[1].y));
    v131.z = v134
           + (float)((float)(v209.mat[2].z * (float)v45)
                   + (float)((float)((float)v44 * v209.mat[0].z) + (float)(v209.mat[1].z * (float)v43)));
    v131.y = v133
           + (float)((float)((float)v45 * v209.mat[2].y)
                   + (float)((float)((float)v44 * v209.mat[0].y) + (float)((float)v43 * v209.mat[1].y)));
    v131.x = (float)((float)((float)v45 * v209.mat[2].x)
                   + (float)((float)(v209.mat[0].x * (float)v44) + (float)((float)v43 * v209.mat[1].x)))
           + x;
    v166 = v131;
    if ( usePathDirectionForMoveAlign
      || validation->usePathDirectionForSourceAlign
      || validation->usePathDirectionForApexAlign )
    {
      DistanceToPath = idAnimWebTransitions::GetDistanceToPath(
                         path: &parms->cachedCorners,
                         startOrigin: &v137,
                         testPoint: &v131,
                         outPositionOnPath: &v166,
                         outDirectionOnPath: &v167);
    }
    v58 = v167.z;
    v59 = v167.y;
    v60 = v167.x;
    if ( validation->usePathDirectionForSourceAlign )
      v61 = (float)((float)(v167.z * (float)v51) + (float)((float)((float)v53 * v167.x) + (float)(v167.y * (float)v52)));
    else
      v61 = (float)((float)(v159.z * (float)v51) + (float)((float)(v159.x * (float)v53) + (float)(v159.y * (float)v52)));
    requiredSourceAlignAngleDot = validation->requiredSourceAlignAngleDot;
    if ( requiredSourceAlignAngleDot > -1.0 && validation->allowRejections && v40 == 0 )
    {
      v46 = v61 > 0.86602539;
      if ( v61 < requiredSourceAlignAngleDot )
      {
        if ( !v130 )
          goto LABEL_117;
        v40 = 1;
      }
    }
    v63 = v61;
    hasApex = v39->hasApex;
    v170 = x;
    v171 = v133;
    v172 = v134;
    if ( hasApex )
    {
      DistanceToPath = (float)((float)(v39->apex.y * (float)v49)
                             + (float)((float)(v39->apex.x * (float)v52) + (float)(v39->apex.z * (float)v55)));
      v65 = (float)((float)((float)((float)v48 * v39->apex.y)
                          + (float)((float)(v39->apex.x * (float)v51) + (float)((float)v54 * v39->apex.z)))
                  + v131.z);
      v66 = (float)((float)((float)(v39->apex.y * (float)v49)
                          + (float)((float)(v39->apex.x * (float)v52) + (float)(v39->apex.z * (float)v55)))
                  + v131.y);
      v67 = (float)((float)((float)(v39->apex.x * (float)v53)
                          + (float)((float)(v39->apex.z * (float)v56) + (float)(v39->apex.y * (float)v50)))
                  + v131.x);
      LODWORD(v136.x) = &v39->apex;
    }
    else
    {
      v65 = v172;
      v66 = v171;
      v67 = v170;
    }
    requiredMoveAlignAngleDot = validation->requiredMoveAlignAngleDot;
    if ( requiredMoveAlignAngleDot > -1.0 && validation->allowRejections && v40 == 0 )
    {
      if ( v42 > v143 )
      {
        v146.z = (float)v65 - v131.z;
        v146.y = (float)v66 - v131.y;
        v146.x = (float)v67 - v131.x;
        DistanceToPath = idVec3::NormalizeFast(this: &v146);
        if ( validation->usePathDirectionForMoveAlign )
          v63 = (float)((float)(v146.z * (float)v58)
                      + (float)((float)(v146.x * (float)v60) + (float)(v146.y * (float)v59)));
        else
          v63 = (float)((float)(v146.x * v155) + (float)((float)(v157 * v146.z) + (float)(v156 * v146.y)));
      }
      v46 &= v63 > 0.86602539;
      if ( v63 < requiredMoveAlignAngleDot )
      {
        if ( !v130 )
          goto LABEL_117;
        v40 = 2;
      }
    }
    requiredApexAlignAngleDot = validation->requiredApexAlignAngleDot;
    if ( requiredApexAlignAngleDot > -1.0 && validation->allowRejections )
    {
      if ( v40 != 0 )
        goto LABEL_72;
      if ( validation->usePathDirectionForApexAlign )
      {
        v141.x = (float)v67 - v166.x;
        v141.z = (float)v65 - v166.z;
        v141.y = (float)v66 - v166.y;
        DistanceToPath = idVec3::NormalizeFast(this: &v141);
        v70 = (float)((float)(v141.z * (float)v58) + (float)((float)(v141.x * (float)v60) + (float)(v141.y * (float)v59)));
      }
      else
      {
        v141.z = (float)v65 - v137.z;
        v141.y = (float)v66 - v137.y;
        v141.x = (float)v67 - v137.x;
        idVec3::NormalizeFast(this: &v141);
        DistanceToPath = (float)((float)(v159.x * v141.x) + (float)(v159.y * v141.y));
        v70 = (float)((float)(v159.z * v141.z) + (float)((float)(v159.x * v141.x) + (float)(v159.y * v141.y)));
      }
      if ( v70 < requiredApexAlignAngleDot )
      {
        if ( !v130 )
          goto LABEL_117;
        v40 = 3;
        goto LABEL_72;
      }
    }
    else if ( v40 != 0 )
    {
      goto LABEL_72;
    }
    if ( !validation->navProbeAnimApex )
      goto LABEL_72;
    if ( hasApex )
    {
      if ( v39->navTraces.ptr[0].fraction <= (double)v145 )
      {
        if ( !v130 )
          goto LABEL_117;
        v40 = 9;
        v71 = (int *)((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(
                       a1: gameLocal,
                       a2: DistanceToPath);
        v195[0] = x;
        v183[0] = v67;
        v183[1] = v66;
        v195[1] = v133;
        v184 = (float)v65 + (float)5.0;
        v195[2] = v134 + (float)5.0;
        v72 = *v71;
        v136.x = v184;
        (*(void (__fastcall **)(int *, idColor *, float *, float *, int, _DWORD))(v72 + 176))(
          a1: v71,
          a2: &idColor::colorOrange,
          a3: v195,
          a4: v183,
          a5: debugDrawTime,
          a6: 0);
        if ( v39->hasApex )
        {
          v73 = gameLocal->GetRenderWorld(this: gameLocal);
          v199[0] = v67;
          v199[1] = v66;
          v199[2] = (float)v65 + (float)5.0;
          v199[3] = 5.0;
          v74 = v73->__vftable;
          v136.x = v66;
          v74->DebugSphere(
            this: v73,
            a2: (const idVec4 *)&idColor::colorOrange,
            a3: (const idSphere *)v199,
            a4: 12,
            a5: debugDrawTime,
            a6: false);
        }
LABEL_68:
        if ( !v130 || !v39->hasApex )
          goto LABEL_72;
        v75 = gameLocal->GetRenderWorld(this: gameLocal);
        v181 = (float)v65 + (float)5.0;
        v196[5] = v131.y;
        v179 = v67;
        v180 = v66;
        v196[4] = v131.x;
        v196[6] = v131.z + (float)5.0;
        v136.x = v131.y;
        DebugLine = (void (*)(void))v75->DebugLine;
LABEL_71:
        DebugLine();
        goto LABEL_72;
      }
      if ( v130 )
      {
        v84 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(a1: gameLocal, a2: DistanceToPath);
        v188[0] = x;
        v85 = v149;
        v188[1] = v133;
        v187 = (float)v65 + (float)5.0;
        v186[0] = v67;
        v186[1] = v66;
        v188[2] = v134 + (float)5.0;
        v136.x = v187;
        (*(void (__fastcall **)(int, idColor *, float *, float *, int, _DWORD))(*(_DWORD *)v84 + 176))(
          a1: v84,
          a2: v149,
          a3: v188,
          a4: v186,
          a5: debugDrawTime,
          a6: 0);
        v86 = gameLocal->GetRenderWorld(this: gameLocal);
        v206[0] = v67;
        v206[1] = v66;
        v206[2] = (float)v65 + (float)5.0;
        v206[3] = v142;
        v87 = v86->__vftable;
        v136.x = v66;
        v87->DebugSphere(
          this: v86,
          a2: (const idVec4 *)v85,
          a3: (const idSphere *)v206,
          a4: 12,
          a5: debugDrawTime,
          a6: false);
      }
    }
    if ( v39->navTraces.ptr[1].fraction > (double)v145 )
      goto LABEL_68;
    if ( !v130 )
      goto LABEL_117;
    v40 = 9;
    v88 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(a1: gameLocal, a2: DistanceToPath);
    v189[1] = v66;
    v191[0] = v131.x;
    v190 = (float)v65 + (float)5.0;
    v191[1] = v131.y;
    v191[2] = v131.z + (float)5.0;
    v189[0] = v67;
    v136.x = v190;
    (*(void (__fastcall **)(int, idColor *, float *, float *, int, _DWORD))(*(_DWORD *)v88 + 176))(
      a1: v88,
      a2: &idColor::colorOrange,
      a3: v191,
      a4: v189,
      a5: debugDrawTime,
      a6: 0);
    if ( v39->hasApex )
    {
      v89 = gameLocal->GetRenderWorld(this: gameLocal);
      v203 = v66;
      v202 = v67;
      v205 = 5.0;
      v204 = (float)v65 + (float)5.0;
      v136.x = v66;
      DebugLine = (void (*)(void))v89->DebugSphere;
      goto LABEL_71;
    }
LABEL_72:
    if ( validation->checkAnimTooShort && validation->allowRejections && v40 == 0 )
    {
      v129 |= v46;
      if ( v144 > (double)(float)((float)(v39->deltaOrigin.x * v39->deltaOrigin.x)
                                + (float)((float)(v39->deltaOrigin.y * v39->deltaOrigin.y)
                                        + (float)(v39->deltaOrigin.z * v39->deltaOrigin.z))) )
      {
        if ( !v130 )
          goto LABEL_117;
        v40 = 4;
      }
    }
    if ( validation->navProbeAnimTranslation
      && !validation->navProbeAnimApex
      && validation->allowRejections
      && v39->navTraces.ptr[2].fraction <= (double)v145 )
    {
      if ( !v130 )
        goto LABEL_117;
      v40 = 10;
      v77 = gameLocal->GetRenderWorld(this: gameLocal);
      v197[1] = v133;
      v197[0] = x;
      v194[2] = v131.z + (float)5.0;
      v197[2] = v134 + (float)5.0;
      v194[0] = v131.x;
      v194[1] = v131.y;
      v136.x = v133;
      v77->DebugLine(
        this: v77,
        a2: (const idVec4 *)&idColor::colorOrange,
        a3: (const idVec3 *)v197,
        a4: (const idVec3 *)v194,
        a5: debugDrawTime,
        a6: false);
    }
    suggestedFlags = validation->suggestedFlags;
    v79 = v143;
    v80 = v143;
    if ( suggestedFlags != 0 && (v39->flags & suggestedFlags) != suggestedFlags )
      v80 = v178;
    selectType = validation->selectType;
    v82 = v169;
    v83 = v169;
    if ( validation->selectType <= (unsigned int)CHOOSE_CLOSEST_TO_PATH_RELATIVE )
    {
      switch ( selectType )
      {
        case CHOOSE_ANGLE_DISTANCE_ERROR:
          goto LABEL_99;
        case CHOOSE_CLOSEST_TO_DESTINATION:
          v96 = (float)(v133
                      - (float)(v137.y
                              + (float)((float)(v39->deltaOrigin.y * v161)
                                      + (float)((float)(v39->deltaOrigin.x * v159.y) + (float)(v39->deltaOrigin.z * v164)))));
          v97 = (float)(x
                      - (float)((float)((float)(v39->deltaOrigin.y * v160)
                                      + (float)((float)(v159.x * v39->deltaOrigin.x) + (float)(v39->deltaOrigin.z * v163)))
                              + v137.x));
          v98 = (float)(v134
                      - (float)(v137.z
                              + (float)((float)(v39->deltaOrigin.y * v162)
                                      + (float)((float)(v39->deltaOrigin.x * v159.z) + (float)(v39->deltaOrigin.z * v165)))));
          v83 = (float)((float)((float)v98 * (float)v98)
                      + (float)((float)((float)v97 * (float)v97) + (float)((float)v96 * (float)v96)));
          break;
        case CHOOSE_CLOSEST_TO_SEGMENT:
LABEL_99:
          _FP3 = (float)((float)((float)((float)(v137.x - v131.x) * (float)(v137.x - v131.x))
                               + (float)((float)(v137.y - v131.y) * (float)(v137.y - v131.y)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v91 = (float)((float)((float)((float)(v137.x - v131.x) * (float)(v137.x - v131.x))
                              + (float)((float)(v137.y - v131.y) * (float)(v137.y - v131.y)))
                      * v150);
          __asm { fsel      f1, f3, f4, f0 }
          v93 = __frsqrte(_FP1);
          v94 = (float)((float)-(float)((float)((float)((float)v93
                                                      * (float)((float)((float)((float)(v137.x - v131.x)
                                                                              * (float)(v137.x - v131.x))
                                                                      + (float)((float)(v137.y - v131.y)
                                                                              * (float)(v137.y - v131.y)))
                                                              * v150))
                                              * (float)v93)
                                      - v148)
                      * (float)v93);
          v95 = (float)((float)-(float)((float)((float)((float)v94
                                                      * (float)((float)((float)((float)(v137.x - v131.x)
                                                                              * (float)(v137.x - v131.x))
                                                                      + (float)((float)(v137.y - v131.y)
                                                                              * (float)(v137.y - v131.y)))
                                                              * v150))
                                              * (float)v94)
                                      - v148)
                      * (float)v94);
          v83 = (float)((float)((float)(v143 - (float)v63) * valueFloat)
                      + (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v94 * (float)v91) * (float)v94)
                                                                                              - v148)
                                                                              * (float)v94)
                                                                      * (float)v91)
                                                              * (float)v95)
                                                      - v148)
                                      * (float)v95)
                              * (float)((float)((float)(v137.x - v131.x) * (float)(v137.x - v131.x))
                                      + (float)((float)(v137.y - v131.y) * (float)(v137.y - v131.y)))));
          break;
        case CHOOSE_CLOSEST_ANGLE_START:
          v83 = (float)(v143 - (float)v61);
          break;
        default:
          v99 = idAnimWebTransitions::GetDistanceToPath(
                  path: &parms->cachedCorners,
                  startOrigin: &v137,
                  testPoint: &v131,
                  outPositionOnPath: v212,
                  outDirectionOnPath: &v136);
          v100 = v82;
          if ( v39->hasApex )
            v100 = __fsqrts((float)((float)((float)(v134 - (float)v65) * (float)(v134 - (float)v65))
                                  + (float)((float)((float)(x - (float)v67) * (float)(x - (float)v67))
                                          + (float)((float)(v133 - (float)v66) * (float)(v133 - (float)v66)))));
          v101 = __fsqrts((float)((float)((float)((float)v65 - v131.z) * (float)((float)v65 - v131.z))
                                + (float)((float)((float)((float)v67 - v131.x) * (float)((float)v67 - v131.x))
                                        + (float)((float)((float)v66 - v131.y) * (float)((float)v66 - v131.y)))));
          v83 = (float)((float)-(float)((float)((float)((float)v101 + (float)v100) * v177) - (float)v79)
                      * (float)((float)v99 / (float)((float)v101 + (float)v100)));
          break;
      }
    }
    v102 = (float)((float)v83 * (float)v80);
    if ( v130 )
    {
      v103 = v168;
      if ( v40 == 0 )
        v103 = v173;
      v201.len = 0;
      v201.baseBuffer[0] = 0;
      v201.data = v201.baseBuffer;
      v201.allocedAndFlag = 20;
      idStr::Format(
        this: &v201,
        fmt: "%s : %s( %.1f )",
        v39->anim->name.str,
        rejectReasons[v40],
        (float)((float)v83 * (float)v80));
      v104 = "^1";
      if ( v40 == 0 )
        v104 = "^3";
      idLib::Printf(fmt: "%s%s\n", v104, v201.data);
      v105 = gameLocal->GetRenderWorld(this: gameLocal);
      v192[2] = v131.z + (float)v79;
      v192[0] = v131.x;
      v192[1] = v131.y;
      v136.x = v131.y;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v105->DebugText)(
        a1: v105,
        a2: v201.data,
        a3: v192,
        a4: v105->__vftable,
        a5: v103,
        a6: 1,
        a7: debugDrawTime,
        a8: 0,
        a9: v152);
      v106 = gameLocal->GetRenderWorld(this: gameLocal);
      v207[1] = v131.y;
      v207[2] = v131.z;
      v207[0] = v131.x;
      v207[3] = v79;
      v106->DebugSphere(
        this: v106,
        a2: (const idVec4 *)v103,
        a3: (const idSphere *)v207,
        a4: 12,
        a5: debugDrawTime,
        a6: false);
      v107 = gameLocal->GetRenderWorld(this: gameLocal);
      v107->DebugLine(
        this: v107,
        a2: (const idVec4 *)v103,
        a3: &v131,
        a4: (const idVec3 *)&x,
        a5: debugDrawTime,
        a6: false);
      v108 = gameLocal->GetRenderWorld(this: gameLocal);
      v193[2] = (float)((float)v51 * v153) + v131.z;
      v193[1] = (float)((float)v52 * v153) + v131.y;
      v193[0] = (float)((float)v53 * v153) + v131.x;
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v108->DebugArrow)(
        a1: v108,
        a2: v103,
        a3: &v131,
        a4: v193,
        a5: v142);
      if ( v40 != 0 )
      {
        idStr::FreeData(this: &v201);
        goto LABEL_117;
      }
      idStr::FreeData(this: &v201);
    }
    if ( v102 < v147 && (!validation->checkAnimTooShort || v46 == v129) )
    {
      v151 = v38;
      v135 = v46;
      v138 = v131.x;
      v139 = v131.y;
      v140 = v131.z;
      v147 = v102;
      v174 = v53;
      v175 = v52;
      v176 = v51;
    }
LABEL_117:
    ++v38;
  }
  while ( v38 < cache->transitions.num );
  if ( v151 < 0 || validation->checkAnimTooShort && v135 != v129 )
    return 0;
  v109 = &cache->transitions.list[v151];
  if ( v130 )
  {
    v208.len = 0;
    v208.baseBuffer[0] = 0;
    v208.data = v208.baseBuffer;
    v208.allocedAndFlag = 20;
    idStr::Format(this: &v208, fmt: "%s", v109->anim->name.str);
    idLib::Printf(fmt: "> %s%s\n", "^2", v208.data);
    v110 = gameLocal->GetRenderWorld(this: gameLocal);
    v111 = v153;
    LODWORD(v136.y) = debugDrawTime;
    v182[0] = v138;
    v182[1] = v139;
    v182[2] = v140 + v153;
    v136.x = v139;
    DebugText = v110->DebugText;
    LODWORD(v136.y) = (int)(float)((float)__SPAIR64__(&unk_82150000, debugDrawTime) * (float)50.0);
    v113 = v136.y;
    ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))DebugText)(
      a1: v110,
      a2: v208.data,
      a3: v182,
      a4: DebugText,
      a5: &idColor::colorGreen,
      a6: 1,
      a7: LODWORD(v136.y),
      a8: 0,
      a9: v152);
    v114 = gameLocal->GetRenderWorld(this: gameLocal);
    v200[0] = v138;
    v200[1] = v139;
    v200[2] = v140;
    v200[3] = v143;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, double, _DWORD))v114->DebugSphere)(
      a1: v114,
      a2: &idColor::colorGreen,
      a3: v200,
      a4: 12,
      a5: COERCE_DOUBLE(LODWORD(v113)),
      a6: 0);
    v115 = gameLocal->GetRenderWorld(this: gameLocal);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double, _DWORD))v115->DebugLine)(
      a1: v115,
      a2: &idColor::colorGreen,
      a3: &v138,
      a4: &x,
      a5: COERCE_DOUBLE(LODWORD(v113)),
      a6: 0);
    v116 = gameLocal->GetRenderWorld(this: gameLocal);
    v185[1] = (float)(v175 * (float)v111) + v139;
    v185[2] = (float)(v176 * (float)v111) + v140;
    v185[0] = (float)(v174 * (float)v111) + v138;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v116->DebugArrow)(
      a1: v116,
      a2: &idColor::colorGreen,
      a3: &v138,
      a4: v185,
      a5: v142);
    idStr::FreeData(this: &v208);
  }
  p_debugState = &v109->via.debugState;
  v118 = v139;
  v119 = v140;
  v120 = x;
  v121 = v133;
  LODWORD(v136.x) = &out->destOrigin;
  v122 = v134;
  p_anim = &out[-1].anim;
  out->startOrigin.x = v138;
  v124 = 5;
  out->startOrigin.y = v118;
  out->startOrigin.z = v119;
  out->destOrigin.x = v120;
  out->destOrigin.y = v121;
  out->destOrigin.z = v122;
  do
  {
    ++p_debugState;
    *++p_anim = (const idMD6Anim *)p_debugState->str;
    --v124;
  }
  while ( v124 != 0 );
  p_approximatePathDistance = (const char **)&v109->approximatePathDistance;
  v126 = &out->dst.debugState;
  for ( i = 5; i != 0; --i )
  {
    ++p_approximatePathDistance;
    ++v126;
    v126->str = *p_approximatePathDistance;
  }
  out->selectionIndex = v109->selectionIndex;
  out->approximatePathDistance = v109->approximatePathDistance;
  out->anim = v109->anim;
  return 1;
}


// ========================================================================
// __unwind$492532
// EA  : 0x82A66DD0
// RVA : 0x00A66DD0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_492532()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1216 + 704));
}


// ========================================================================
// __unwind$492533
// EA  : 0x82A66DF8
// RVA : 0x00A66DF8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_492533()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1216 + 784));
}


// ========================================================================
// ?ResolveAndSubmitNavTrace@idAnimWebTransitions@@SA?AW4navTraceResult_t@1@PAVidAI2@@AAUnavTraceData_t@1@@Z
// EA  : 0x82A66E20
// RVA : 0x00A66E20
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::ResolveAndSubmitNavTrace(idAI2 *ai, idAnimWebTransitions::navTraceData_t *trace)
{
  unsigned __int8 v2; // r24
  char v5; // r25
  int v6; // r29
  int v7; // r28
  int v8; // r30
  int v9; // r4
  double NavTraceResult; // fp1

  v2 = 0;
  v5 = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = (trace->numIndex + v6) % 2;
    v8 = 4 * (v7 + 7);
    v9 = *(_DWORD *)((char *)&trace->start.x + v8);
    if ( v9 > -1 )
    {
      NavTraceResult = idAnimBaseFSM::GetNavTraceResult(this: &ai->aiVolatile.animation.animFSM, queryNum: v9);
      trace->fraction = NavTraceResult;
      if ( NavTraceResult > -1.0 )
        break;
    }
    if ( ++v6 >= 2 )
      goto LABEL_8;
  }
  v5 = 1;
  ai->aiVolatile.animation.animFSM.navTraces.ptr[*(_DWORD *)((char *)&trace->start.x + v8)].used = false;
  if ( trace->fraction == 1.0 )
    v2 = 1;
LABEL_8:
  trace->numIndex = v7;
  trace->num[trace->numIndex] = idAnimBaseFSM::AddNavTrace(
                                  this: &ai->aiVolatile.animation.animFSM,
                                  start: &trace->start,
                                  stop: &trace->stop);
  if ( v5 != 0 )
    return (_cntlzw(v2) & 0x20) != 0;
  else
    return 2;
}


// ========================================================================
// ?PrepareDepartureTraces@idAnimWebTransitions@@SA_NPAVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@@Z
// EA  : 0x82A66F30
// RVA : 0x00A66F30
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::PrepareDepartureTraces(
        idAI2 *ai,
        const idAnimWebTransitions::transitionQueryValidation_t *validation,
        idAnimWebTransitions::transitionCache_t *cache,
        const idAnimWebTransitions::transitionQueryParms_t *parms)
{
  int num; // r8
  float y; // r5
  char *v10; // r10
  float z; // r4
  float *p_z; // r11
  int v13; // ctr
  int v14; // r30
  int v15; // r25
  double v16; // fp26
  double v17; // fp31
  double x; // fp30
  idStaticList<idVec3,31> *p_cachedCorners; // r23
  double v20; // fp25
  int v21; // r29
  double v22; // fp24
  double v23; // fp23
  double v24; // fp22
  double v25; // fp21
  double v26; // fp20
  double v27; // fp19
  double v28; // fp18
  double v29; // fp17
  idAnimWebTransitions::transitionData_t *v30; // r31
  double v31; // fp3
  double v32; // fp1
  const idVec3 *v33; // r4
  double v36; // fp9
  double v37; // fp12
  BOOL hasApex; // r11
  double v39; // fp27
  double v40; // fp28
  double v41; // fp29
  double v42; // fp13
  double v43; // fp12
  double v44; // fp11
  idVec3 v45; // [sp+50h] [-1B0h] BYREF
  idVec3 v46; // [sp+60h] [-1A0h] BYREF
  char v47; // [sp+6Ch] [-194h] BYREF
  idMat3 v48; // [sp+70h] [-190h] BYREF
  idVec3 v49; // [sp+98h] [-168h]
  idVec3 v50[2]; // [sp+A8h] [-158h] BYREF
  idMat3 v51; // [sp+C0h] [-140h] BYREF
  idVec3 v52[2]; // [sp+E8h] [-118h] BYREF
  idMat3 v53[4]; // [sp+100h] [-100h] BYREF

  num = cache->transitions.num;
  if ( num == 0 )
    return 0;
  y = parms->sourceOrigin1.y;
  v10 = &v47;
  z = parms->sourceOrigin1.z;
  p_z = &parms->sourceOrigin2.z;
  v46.x = parms->sourceOrigin1.x;
  v13 = 9;
  v46.y = y;
  v46.z = z;
  do
  {
    ++p_z;
    v10 += 4;
    *(float *)v10 = *p_z;
    --v13;
  }
  while ( v13 != 0 );
  v14 = 1;
  v15 = 0;
  if ( num > 0 )
  {
    v16 = v46.z;
    v17 = v46.y;
    x = v46.x;
    p_cachedCorners = &parms->cachedCorners;
    v20 = v48.mat[2].z;
    v21 = 0;
    v22 = v48.mat[2].y;
    v23 = v48.mat[2].x;
    v24 = v48.mat[1].z;
    v25 = v48.mat[1].y;
    v26 = v48.mat[1].x;
    v27 = v48.mat[0].z;
    v28 = v48.mat[0].y;
    v29 = v48.mat[0].x;
    do
    {
      v30 = &cache->transitions.list[v21];
      v31 = (float)((float)(v30->deltaCorrectGoalTranslation.z * (float)v20)
                  + (float)((float)(v30->deltaCorrectGoalTranslation.x * (float)v27)
                          + (float)(v30->deltaCorrectGoalTranslation.y * (float)v24)));
      v32 = (float)((float)v17
                  + (float)((float)(v30->deltaCorrectGoalTranslation.y * (float)v25)
                          + (float)((float)(v30->deltaCorrectGoalTranslation.x * (float)v28)
                                  + (float)(v30->deltaCorrectGoalTranslation.z * (float)v22))));
      v45.x = (float)x
            + (float)((float)(v30->deltaCorrectGoalTranslation.x * (float)v29)
                    + (float)((float)(v30->deltaCorrectGoalTranslation.z * (float)v23)
                            + (float)(v30->deltaCorrectGoalTranslation.y * (float)v26)));
      v45.y = v32;
      v45.z = (float)v16 + (float)v31;
      v51.mat[0].x = v30->deltaCorrectGoalAxis.mat[0].x;
      v51.mat[0].y = v30->deltaCorrectGoalAxis.mat[0].y;
      v51.mat[0].z = v30->deltaCorrectGoalAxis.mat[0].z;
      v51.mat[1].x = v30->deltaCorrectGoalAxis.mat[1].x;
      v51.mat[1].y = v30->deltaCorrectGoalAxis.mat[1].y;
      v51.mat[1].z = v30->deltaCorrectGoalAxis.mat[1].z;
      v51.mat[2].x = v30->deltaCorrectGoalAxis.mat[2].x;
      v51.mat[2].y = v30->deltaCorrectGoalAxis.mat[2].y;
      v51.mat[2].z = v30->deltaCorrectGoalAxis.mat[2].z;
      idMat3::InverseSelf(this: &v51);
      idMat3::operator*(this: v53, result: &v48, a: &v51);
      _FP11 = (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y))
                            + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f10, f11, f0, f12 }
      v36 = __frsqrte(_FP10);
      if ( validation->usePathDirectionForMoveAlign )
      {
        idAnimWebTransitions::GetDistanceToPath(
          path: p_cachedCorners,
          startOrigin: &v46,
          testPoint: &v45,
          outPositionOnPath: v50,
          outDirectionOnPath: v52);
      }
      else
      {
        v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                            * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x))) * (float)0.5))
                                                                                    * (float)v36)
                                                                            - (float)1.5)
                                                            * (float)v36)
                                                    * (float)((float)((float)((float)((float)v17 - v45.y)
                                                                            * (float)((float)v17 - v45.y))
                                                                    + (float)((float)((float)x - v45.x)
                                                                            * (float)((float)x - v45.x)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v36
                                                                                    * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x)))
                                                                                            * (float)0.5))
                                                                            * (float)v36)
                                                                    - (float)1.5)
                                                    * (float)v36))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v36
                                                            * (float)((float)((float)((float)((float)v17 - v45.y)
                                                                                    * (float)((float)v17 - v45.y))
                                                                            + (float)((float)((float)x - v45.x)
                                                                                    * (float)((float)x - v45.x)))
                                                                    * (float)0.5))
                                                    * (float)v36)
                                            - (float)1.5)
                            * (float)v36));
        idAnimWebTransitions::GetPathPositionAndDirection(
          path: p_cachedCorners,
          distanceAhead: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x))) * (float)0.5)) * (float)v36) - (float)1.5) * (float)v36)
                                                                                                * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x))) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                                * (float)v36))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y)) + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x))) * (float)0.5))
                                                                                                * (float)v36)
                                                                                        - (float)1.5)
                                                                        * (float)v36))
                                                        * (float)((float)((float)((float)((float)v17 - v45.y)
                                                                                * (float)((float)v17 - v45.y))
                                                                        + (float)((float)((float)x - v45.x)
                                                                                * (float)((float)x - v45.x)))
                                                                * (float)0.5))
                                                * (float)v37)
                                        - (float)1.5)
                        * (float)v37)
                * (float)((float)((float)((float)v17 - v45.y) * (float)((float)v17 - v45.y))
                        + (float)((float)((float)x - v45.x) * (float)((float)x - v45.x)))),
          startPosition: v33,
          startDirection: &v46,
          outPosition: v48.mat,
          outDirection: v50,
          a7: &v52[0].x);
        v16 = v46.z;
        v17 = v46.y;
        x = v46.x;
      }
      v20 = v48.mat[2].z;
      v22 = v48.mat[2].y;
      v23 = v48.mat[2].x;
      hasApex = v30->hasApex;
      v24 = v48.mat[1].z;
      v25 = v48.mat[1].y;
      v26 = v48.mat[1].x;
      v49 = v45;
      v27 = v48.mat[0].z;
      v28 = v48.mat[0].y;
      v29 = v48.mat[0].x;
      if ( hasApex )
      {
        v39 = (float)((float)((float)(v30->apex.y * v48.mat[1].x)
                            + (float)((float)(v30->apex.x * v48.mat[0].x) + (float)(v30->apex.z * v48.mat[2].x)))
                    + (float)x);
        v40 = (float)((float)((float)(v30->apex.y * v48.mat[1].y)
                            + (float)((float)(v30->apex.x * v48.mat[0].y) + (float)(v30->apex.z * v48.mat[2].y)))
                    + (float)v17);
        v41 = (float)((float)((float)(v30->apex.y * v48.mat[1].z)
                            + (float)((float)(v30->apex.z * v48.mat[2].z) + (float)(v30->apex.x * v48.mat[0].z)))
                    + (float)v16);
      }
      else
      {
        v41 = v49.z;
        v40 = v49.y;
        v39 = v49.x;
      }
      if ( validation->navProbeAnimApex )
      {
        if ( hasApex )
        {
          v30->navTraces.ptr[0].start = v45;
          v30->navTraces.ptr[0].stop.x = v39;
          v30->navTraces.ptr[0].stop.y = v40;
          v30->navTraces.ptr[0].stop.z = v41;
          v14 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: v30->navTraces.ptr) == 2 ? 0 : v14;
        }
        v30->navTraces.ptr[1].start.x = v39;
        v30->navTraces.ptr[1].start.y = v40;
        v30->navTraces.ptr[1].start.z = v41;
        v30->navTraces.ptr[1].stop.x = x;
        v30->navTraces.ptr[1].stop.y = v17;
        v30->navTraces.ptr[1].stop.z = v16;
        v14 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: &v30->navTraces.ptr[1]) == 2 ? 0 : v14;
      }
      if ( validation->navProbeToPathPosition )
      {
        v30->navTraces.ptr[2].start.x = v45.x;
        v30->navTraces.ptr[2].start.y = v45.y;
        v42 = v50[0].x;
        v43 = v50[0].y;
        v44 = v50[0].z;
        v30->navTraces.ptr[2].start.z = v45.z;
        v30->navTraces.ptr[2].stop.x = v42;
        v30->navTraces.ptr[2].stop.y = v43;
        v30->navTraces.ptr[2].stop.z = v44;
        v14 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: &v30->navTraces.ptr[2]) == 2 ? 0 : v14;
      }
      ++v15;
      ++v21;
    }
    while ( v15 < cache->transitions.num );
  }
  return v14;
}


// ========================================================================
// ?PrepareArrivalTraces@idAnimWebTransitions@@SA_NPAVidAI2@@ABUtransitionQueryValidation_t@1@AAUtransitionCache_t@1@ABUtransitionQueryParms_t@1@@Z
// EA  : 0x82A672F0
// RVA : 0x00A672F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

int __fastcall idAnimWebTransitions::PrepareArrivalTraces(
        idAI2 *ai,
        const idAnimWebTransitions::transitionQueryValidation_t *validation,
        idAnimWebTransitions::transitionCache_t *cache,
        const idAnimWebTransitions::transitionQueryParms_t *parms)
{
  int num; // r8
  float x; // r26
  float y; // r25
  char *v11; // r10
  float z; // r24
  float *p_z; // r11
  int i; // ctr
  int v15; // r30
  int v16; // r23
  int v17; // r29
  idAnimWebTransitions::transitionData_t *v18; // r31
  double v19; // fp4
  double v20; // fp2
  double v21; // fp5
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  double v25; // fp26
  double v26; // fp27
  double v27; // fp28
  idMat3 v28; // [sp+60h] [-100h] BYREF
  char v29; // [sp+8Ch] [-D4h] BYREF
  idMat3 v30[3]; // [sp+90h] [-D0h] BYREF

  num = cache->transitions.num;
  if ( num == 0 )
    return 1;
  x = parms->destinationOrigin.x;
  y = parms->destinationOrigin.y;
  v11 = &v29;
  z = parms->destinationOrigin.z;
  p_z = &parms->destinationOrigin.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v11 += 4;
    *(float *)v11 = *p_z;
  }
  v15 = 1;
  v16 = 0;
  if ( num > 0 )
  {
    v17 = 0;
    do
    {
      v18 = &cache->transitions.list[v17];
      idMat3::operator*(this: &v28, result: v30, a: &v18->deltaAxis);
      v19 = -v18->deltaOrigin.y;
      v20 = -v18->deltaOrigin.z;
      v21 = -v18->deltaOrigin.x;
      v22 = (float)((float)((float)(v28.mat[0].x * (float)v21)
                          + (float)((float)(v28.mat[2].x * (float)v20) + (float)(v28.mat[1].x * (float)v19)))
                  + x);
      v23 = (float)(y
                  + (float)((float)(v28.mat[0].y * (float)v21)
                          + (float)((float)(v28.mat[2].y * (float)v20) + (float)(v28.mat[1].y * (float)v19))));
      v24 = (float)(z
                  + (float)((float)(v28.mat[0].z * (float)v21)
                          + (float)((float)(v28.mat[2].z * (float)v20) + (float)(v28.mat[1].z * (float)v19))));
      if ( v18->hasApex )
      {
        v25 = (float)((float)((float)(v18->apex.x * v28.mat[0].x)
                            + (float)((float)(v18->apex.z * v28.mat[2].x) + (float)(v18->apex.y * v28.mat[1].x)))
                    + (float)((float)((float)(v28.mat[0].x * (float)v21)
                                    + (float)((float)(v28.mat[2].x * (float)v20) + (float)(v28.mat[1].x * (float)v19)))
                            + x));
        v26 = (float)((float)((float)(v18->apex.y * v28.mat[1].y)
                            + (float)((float)(v18->apex.x * v28.mat[0].y) + (float)(v18->apex.z * v28.mat[2].y)))
                    + (float)(y
                            + (float)((float)(v28.mat[0].y * (float)v21)
                                    + (float)((float)(v28.mat[2].y * (float)v20) + (float)(v28.mat[1].y * (float)v19)))));
        v27 = (float)((float)((float)(v18->apex.y * v28.mat[1].z)
                            + (float)((float)(v18->apex.x * v28.mat[0].z) + (float)(v18->apex.z * v28.mat[2].z)))
                    + (float)(z
                            + (float)((float)(v28.mat[0].z * (float)v21)
                                    + (float)((float)(v28.mat[2].z * (float)v20) + (float)(v28.mat[1].z * (float)v19)))));
      }
      else
      {
        v27 = z;
        v26 = y;
        v25 = x;
      }
      if ( validation->navProbeAnimApex )
      {
        if ( v18->hasApex )
        {
          v18->navTraces.ptr[0].start.x = x;
          v18->navTraces.ptr[0].start.y = y;
          v18->navTraces.ptr[0].start.z = z;
          v18->navTraces.ptr[0].stop.x = v25;
          v18->navTraces.ptr[0].stop.y = v26;
          v18->navTraces.ptr[0].stop.z = v27;
          v15 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: v18->navTraces.ptr) == 2 ? 0 : v15;
        }
        v18->navTraces.ptr[1].start.x = v25;
        v18->navTraces.ptr[1].start.y = v26;
        v18->navTraces.ptr[1].start.z = v27;
        v18->navTraces.ptr[1].stop.x = v22;
        v18->navTraces.ptr[1].stop.y = v23;
        v18->navTraces.ptr[1].stop.z = v24;
        v15 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: &v18->navTraces.ptr[1]) == 2 ? 0 : v15;
      }
      if ( validation->navProbeAnimTranslation && !validation->navProbeAnimApex )
      {
        v18->navTraces.ptr[2].start.x = x;
        v18->navTraces.ptr[2].start.y = y;
        v18->navTraces.ptr[2].start.z = z;
        v18->navTraces.ptr[2].stop.x = v22;
        v18->navTraces.ptr[2].stop.y = v23;
        v18->navTraces.ptr[2].stop.z = v24;
        v15 = idAnimWebTransitions::ResolveAndSubmitNavTrace(ai, trace: &v18->navTraces.ptr[2]) == 2 ? 0 : v15;
      }
      ++v16;
      ++v17;
    }
    while ( v16 < cache->transitions.num );
  }
  return v15;
}


// ========================================================================
// ?FillTransitionCache@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@ABVidAnimWebState@@@Z
// EA  : 0x82A676F8
// RVA : 0x00A676F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __fastcall idAnimWebTransitions::FillTransitionCache(
        idAI2 *ai,
        idAnimWebTransitions::transitionCache_t *cache,
        idAnimWebState *transitionState)
{
  idAI2 *v3; // r25
  const idDeclMD6 *decl; // r29
  char Flags; // r30
  int v8; // r26
  idList<idAnimWebTransitions::transitionData_t,5> *p_transitions; // r16
  const idMD6Anim *AnimByIndex; // r3
  idMD6AnimData *animData; // r11
  const idMD6Anim *v12; // r24
  float *startDelta; // r29
  float *endDelta; // r28
  int size; // r10
  int num; // r11
  int v17; // r30
  float v18; // r9
  float v19; // r8
  double v20; // fp9
  float v21; // r7
  double v22; // fp8
  double v23; // fp7
  double v24; // fp6
  double v25; // fp0
  double v26; // fp3
  double v28; // fp4
  double v30; // fp1
  double v31; // fp1
  float v32; // r6
  double v33; // fp2
  float v34; // r11
  double v35; // fp1
  float v36; // r10
  double v37; // fp10
  double v38; // fp9
  double v39; // fp8
  double v40; // fp6
  double v41; // fp1
  double v43; // fp7
  double v45; // fp5
  double v46; // fp1
  double v47; // fp9
  double v48; // fp7
  idQuat *v49; // r3
  double x; // fp13
  double y; // fp12
  double z; // fp9
  double minimumDeltaOriginDistanceSqr; // fp6
  _DWORD *v54; // r9
  int v55; // ctr
  idAtomicString *p_debugState; // r10
  const char *str; // r27
  int v62; // r3
  char v63; // r11
  const char *v64; // r3
  char v65; // t0
  int v66; // r3
  int v67; // r11
  idMD6AnimData *v68; // r11
  idVec3 *v69; // r23
  float v70; // r9
  float v71; // r7
  float v72; // r5
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idMD6AnimData *v74; // r11
  idDeclMD6 *v75; // r22
  int numFrames; // r6
  int v77; // r26
  int v78; // r25
  int v79; // r27
  idVehicleState *v80; // r28
  double v81; // fp22
  double v82; // fp23
  double v83; // fp24
  double v84; // fp25
  double v85; // fp16
  double v86; // fp17
  idMD6AnimData *v87; // r11
  idVec3 *v88; // r11
  double v89; // fp0
  double v90; // fp12
  float *NumLocalUsers; // r3
  float *v92; // r3
  float v93; // r8
  float v94; // r6
  float v95; // r5
  double v97; // fp4
  double v99; // fp2
  double v100; // fp10
  double v101; // fp4
  double v102; // fp0
  int v103; // r6
  idMD6AnimData *v104; // r11
  D3DXShader::CTErrors *v105; // r28
  float *v106; // r3
  double v107; // fp18
  double v108; // fp19
  double v109; // fp20
  float *v110; // r3
  float v111; // r7
  float v112; // r6
  double v113; // fp30
  float v114; // r5
  double v115; // fp8
  double v118; // fp3
  double v119; // fp10
  double v120; // fp8
  double v121; // fp3
  double v122; // fp2
  double v123; // fp1
  double v124; // fp27
  double v125; // fp28
  double v126; // fp29
  double v127; // fp21
  float v128; // r9
  int v129; // r6
  float v130; // r8
  idMD6AnimData *v131; // r11
  float *v132; // r3
  double v133; // fp11
  double v134; // fp12
  double v135; // fp13
  double v136; // fp10
  double v137; // fp6
  double v138; // fp0
  double v139; // fp3
  double v141; // fp1
  double v143; // fp9
  double v144; // fp10
  idMD6AnimData *v145; // r11
  idVec3 *v146; // r11
  double v147; // fp9
  double v148; // fp5
  double v149; // fp10
  double v151; // fp8
  double v153; // fp6
  double v154; // fp6
  double v155; // fp0
  float v158; // r6
  float v159; // r5
  float v160; // r3
  double v161; // fp0
  double v163; // fp3
  double v165; // fp1
  double v166; // fp7
  double v167; // fp12
  float v168; // r11
  float v169; // r3
  double v171; // fp4
  double v173; // fp1
  float v174; // [sp+58h] [-2F8h]
  float v175; // [sp+5Ch] [-2F4h]
  float v176; // [sp+60h] [-2F0h]
  int v177; // [sp+68h] [-2E8h]
  float v178; // [sp+70h] [-2E0h]
  float v179; // [sp+74h] [-2DCh]
  float v180; // [sp+78h] [-2D8h]
  float v181; // [sp+7Ch] [-2D4h]
  idVec3 v182; // [sp+80h] [-2D0h] BYREF
  float v183; // [sp+8Ch] [-2C4h]
  float v184; // [sp+90h] [-2C0h]
  float v185; // [sp+94h] [-2BCh]
  float v186; // [sp+98h] [-2B8h]
  float v187; // [sp+9Ch] [-2B4h]
  float v188; // [sp+A0h] [-2B0h]
  float v189; // [sp+A4h] [-2ACh]
  float v190; // [sp+A8h] [-2A8h]
  float v191; // [sp+ACh] [-2A4h]
  float v192; // [sp+B0h] [-2A0h]
  float v193; // [sp+B4h] [-29Ch]
  float v194; // [sp+B8h] [-298h]
  float v195; // [sp+BCh] [-294h]
  float v196; // [sp+C0h] [-290h]
  float v197; // [sp+C4h] [-28Ch]
  float v198; // [sp+C8h] [-288h]
  float v199; // [sp+CCh] [-284h]
  float v200; // [sp+D0h] [-280h]
  float v201; // [sp+D4h] [-27Ch]
  float v202; // [sp+D8h] [-278h]
  float v203; // [sp+DCh] [-274h]
  float v204; // [sp+E0h] [-270h]
  float v205; // [sp+E4h] [-26Ch]
  float v206; // [sp+E8h] [-268h]
  float v207; // [sp+ECh] [-264h]
  int NumAnims; // [sp+F0h] [-260h]
  idEventDef *v209; // [sp+F4h] [-25Ch]
  float v210; // [sp+F8h] [-258h]
  float v211; // [sp+FCh] [-254h]
  float v212; // [sp+100h] [-250h]
  idMem *v213; // [sp+104h] [-24Ch]
  int v214; // [sp+108h] [-248h]
  const idDeclMD6 *v215; // [sp+10Ch] [-244h]
  const char *v216; // [sp+110h] [-240h]
  const char *v217; // [sp+114h] [-23Ch]
  idEventDef *v218; // [sp+118h] [-238h]
  float v219; // [sp+120h] [-230h]
  float v220; // [sp+124h] [-22Ch]
  float v221; // [sp+128h] [-228h]
  idVec3 v222; // [sp+130h] [-220h] BYREF
  idMat3 v223; // [sp+140h] [-210h] BYREF
  float v224; // [sp+164h] [-1ECh]
  float v225; // [sp+168h] [-1E8h]
  float v226; // [sp+16Ch] [-1E4h]
  idList<idVehicleState *,5> v227; // [sp+170h] [-1E0h] BYREF
  int v228; // [sp+180h] [-1D0h] BYREF
  idQuat v229; // [sp+1C0h] [-190h] BYREF
  idQuat v230[3]; // [sp+1D0h] [-180h] BYREF
  idQuat v231; // [sp+200h] [-150h] BYREF

  v3 = ai;
  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai)->decl;
  cache->maximumDeltaOriginDistanceSqr = 0.0;
  cache->nodeIndex.value = transitionState->node.value;
  v215 = decl;
  Flags = idAnimWebState::GetFlags(this: transitionState);
  NumAnims = idAnimWebState::GetNumAnims(this: transitionState, md6: decl);
  v8 = 0;
  v177 = 0;
  if ( NumAnims > 0 )
  {
    v214 = Flags & 9;
    v213 = &mem;
    v209 = &AE_JointKeyframe;
    v218 = &AE_AnimDeltaCorrectionGoal;
    p_transitions = &cache->transitions;
    v216 = "injured";
    v217 = "scramble";
    while ( 1 )
    {
      AnimByIndex = idAnimWebState::GetAnimByIndex(this: transitionState, md6: decl, animIndex: v8, modelIndex: 0);
      animData = AnimByIndex->animData;
      v12 = AnimByIndex;
      startDelta = nullptr;
      if ( animData != nullptr )
      {
        startDelta = animData->startDelta;
        endDelta = animData->endDelta;
      }
      else
      {
        endDelta = nullptr;
      }
      idList<idAnimWebTransitions::transitionData_t,5>::PreAllocateWithGranularity(
        this: &cache->transitions,
        newSize: cache->transitions.num + 1);
      size = cache->transitions.size;
      num = cache->transitions.num;
      if ( num >= size )
      {
        v17 = (int)&p_transitions->list[size - 1];
      }
      else
      {
        v17 = (int)&p_transitions->list[num];
        cache->transitions.num = num + 1;
      }
      v18 = startDelta[1];
      v19 = startDelta[2];
      v20 = *endDelta;
      v21 = startDelta[3];
      v22 = endDelta[2];
      v23 = endDelta[3];
      v184 = *startDelta;
      v24 = endDelta[1];
      v185 = v18;
      v186 = v19;
      v187 = v21;
      v25 = startDelta[3];
      v26 = (float)(startDelta[3] * (float)v22);
      _FP5 = (float)((float)((float)(v18 * v18)
                           + (float)((float)(v19 * v19) + (float)((float)(v184 * v184) + (float)(v187 * v187))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v28 = (float)((float)((float)(v18 * v18)
                          + (float)((float)(v19 * v19) + (float)((float)(v184 * v184) + (float)(v187 * v187))))
                  * (float)0.5);
      __asm { fsel      f2, f5, f1, f13 }
      v30 = __frsqrte(_FP2);
      v31 = (float)((float)-(float)((float)((float)((float)v30
                                                  * (float)((float)((float)(v18 * v18)
                                                                  + (float)((float)(v19 * v19)
                                                                          + (float)((float)(v184 * v184)
                                                                                  + (float)(v187 * v187))))
                                                          * (float)0.5))
                                          * (float)v30)
                                  - (float)1.5)
                  * (float)v30);
      v187 = startDelta[3];
      v184 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                            * (float)v31)
                                                                                    - (float)1.5)
                                                                    * (float)v31)
                                                            * (float)v28)
                                                    * (float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                    * (float)v31)
                                                                            - (float)1.5)
                                                            * (float)v31))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v31 * (float)v28) * (float)v31) - (float)1.5)
                                    * (float)v31))
                    * v184);
      v185 = -(float)(v18
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                            * (float)v31)
                                                                                    - (float)1.5)
                                                                    * (float)v31)
                                                            * (float)v28)
                                                    * (float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                    * (float)v31)
                                                                            - (float)1.5)
                                                            * (float)v31))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v31 * (float)v28) * (float)v31) - (float)1.5)
                                    * (float)v31)));
      v186 = -(float)(v19
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                            * (float)v31)
                                                                                    - (float)1.5)
                                                                    * (float)v31)
                                                            * (float)v28)
                                                    * (float)((float)-(float)((float)((float)((float)v31 * (float)v28)
                                                                                    * (float)v31)
                                                                            - (float)1.5)
                                                            * (float)v31))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v31 * (float)v28) * (float)v31) - (float)1.5)
                                    * (float)v31)));
      v225 = -(float)((float)(v185 * (float)v20)
                    - (float)((float)(v186 * (float)v23) + (float)((float)((float)v24 * v184) + (float)v26)));
      v226 = -(float)((float)(v186 * (float)v22)
                    - (float)-(float)((float)(v185 * (float)v24)
                                    - (float)((float)((float)v25 * (float)v23) - (float)((float)v20 * v184))));
      v223.mat[2].z = -(float)((float)(v186 * (float)v24)
                             - (float)((float)((float)v25 * (float)v20)
                                     + (float)((float)((float)v23 * v184) + (float)(v185 * (float)v22))));
      v224 = -(float)((float)((float)v22 * v184)
                    - (float)((float)(v185 * (float)v23)
                            + (float)((float)((float)v25 * (float)v24) + (float)(v186 * (float)v20))));
      *(idMat3 *)(v17 + 12) = *idQuat::ToMat3(this: v230, result: (idMat3 *)&v223.mat[2].z);
      v32 = startDelta[2];
      v33 = endDelta[10];
      v34 = startDelta[3];
      v35 = startDelta[10];
      v36 = *startDelta;
      v37 = endDelta[9];
      v38 = startDelta[9];
      v182.y = startDelta[1];
      v39 = startDelta[3];
      v182.x = v36;
      v40 = (float)((float)v33 - (float)v35);
      v182.z = v32;
      v183 = v34;
      v41 = (float)((float)(v182.x * v182.x) + (float)(v183 * v183));
      v183 = v39;
      v222.z = v40;
      v222.y = (float)v37 - (float)v38;
      v222.x = endDelta[8] - startDelta[8];
      _FP8 = (float)((float)((float)(v182.y * v182.y) + (float)((float)(v32 * v32) + (float)v41))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v43 = (float)((float)((float)(v182.y * v182.y) + (float)((float)(v32 * v32) + (float)v41)) * (float)0.5);
      __asm { fsel      f6, f8, f9, f0 }
      v45 = __frsqrte(_FP6);
      v46 = (float)((float)-(float)((float)((float)((float)v45
                                                  * (float)((float)((float)(v182.y * v182.y)
                                                                  + (float)((float)(v32 * v32) + (float)v41))
                                                          * (float)0.5))
                                          * (float)v45)
                                  - (float)1.5)
                  * (float)v45);
      v47 = (float)((float)-(float)((float)((float)((float)v46 * (float)v43) * (float)v46) - (float)1.5) * (float)v46);
      v48 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)v43) * (float)v46)
                                                                  - (float)1.5)
                                                  * (float)v46)
                                          * (float)v43)
                                  * (float)((float)-(float)((float)((float)((float)v46 * (float)v43) * (float)v46)
                                                          - (float)1.5)
                                          * (float)v46))
                          - (float)1.5);
      v182.x = -(float)((float)((float)v48 * (float)v47) * v36);
      v182.y = -(float)(v182.y * (float)((float)v48 * (float)v47));
      v182.z = -(float)(v32 * (float)((float)v48 * (float)v47));
      v49 = idQuat::operator*(this: &v229, result: &v182, a: &v222);
      x = v49->x;
      *(float *)v17 = v49->x;
      y = v49->y;
      *(float *)(v17 + 4) = v49->y;
      z = v49->z;
      *(float *)(v17 + 8) = v49->z;
      minimumDeltaOriginDistanceSqr = cache->minimumDeltaOriginDistanceSqr;
      v54 = (_DWORD *)(v17 + 168);
      v55 = 5;
      p_debugState = &transitionState[-1].debugState;
      _FP3 = (float)(cache->maximumDeltaOriginDistanceSqr
                   - (float)((float)((float)z * (float)z)
                           + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y))));
      __asm { fsel      f2, f3, f7, f4 }
      cache->maximumDeltaOriginDistanceSqr = _FP2;
      _FP9 = (float)((float)minimumDeltaOriginDistanceSqr
                   - (float)((float)(*(float *)(v17 + 8) * *(float *)(v17 + 8))
                           + (float)((float)(*(float *)v17 * *(float *)v17)
                                   + (float)(*(float *)(v17 + 4) * *(float *)(v17 + 4)))));
      __asm { fsel      f8, f9, f10, f6 }
      cache->minimumDeltaOriginDistanceSqr = _FP8;
      *(_DWORD *)(v17 + 232) = v12;
      do
      {
        ++p_debugState;
        *++v54 = p_debugState->str;
        --v55;
      }
      while ( v55 != 0 );
      idAnimWebState::Clear(this: (idAnimWebState *)(v17 + 192));
      idAnimWebState::Clear(this: (idAnimWebState *)(v17 + 212));
      str = v12->name.str;
      v62 = idStr::Find(searchIn: str, searchFor: v217, casesensitive: false, start: 0, end: -1);
      v63 = v62 + 1;
      v65 = v62 + (v62 == -1);
      v64 = str;
      LOBYTE(str) = v63 - v65;
      v66 = idStr::Find(searchIn: v64, searchFor: v216, casesensitive: false, start: 0, end: -1);
      v67 = v12->animData->flags;
      *(_DWORD *)(v17 + 164) = v67;
      if ( (_BYTE)str != 0 )
        *(_DWORD *)(v17 + 164) = v67 | 0x4000;
      if ( v66 != -1 )
        *(_DWORD *)(v17 + 164) |= 0x2000u;
      *(_DWORD *)(v17 + 556) = v8;
      v68 = v12->animData;
      v69 = &vec3_origin;
      if ( v68 != nullptr )
        v69 = (idVec3 *)&v68->endDelta[8];
      v70 = endDelta[1];
      v71 = endDelta[2];
      v72 = endDelta[3];
      v178 = *endDelta;
      v174 = v69->x;
      v175 = v69->y;
      v176 = v69->z;
      v227.size = 16;
      v227.num = 0;
      v179 = v70;
      v227.granularity = 1;
      v180 = v71;
      v227.list = (idVehicleState **)&v228;
      v181 = v72;
      v227.memTag = 5;
      v227.listStatic = 1;
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v3);
      v74 = v12->animData;
      v75 = TreeAnimatorFromPresentable->decl;
      numFrames = 0;
      if ( v74 != nullptr )
        numFrames = v74->numFrames;
      idDeclMD6::FindAnimEvents(
        this: TreeAnimatorFromPresentable->decl,
        anim: v12,
        startFrame: 0,
        endFrame: numFrames,
        eventNum: AE_AnimDeltaCorrectionEnd.eventnum,
        events: &v227);
      v77 = 0;
      v78 = v227.num;
      if ( v227.num <= 0 )
      {
LABEL_27:
        v81 = v178;
        v82 = v179;
        v83 = v180;
        v84 = v181;
        v85 = v174;
        v86 = v175;
      }
      else
      {
        v79 = 0;
        while ( 1 )
        {
          v80 = v227.list[v79];
          if ( HIWORD(v80->__vftable) > 1u
            && LOBYTE(v80->stateData) == 3
            && *(_DWORD *)(HIWORD(v80->listeningToList) + *(_DWORD *)&v80->enterFailed) != 0
            && idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v227.list[v79]) != 0 )
          {
            break;
          }
          ++v77;
          ++v79;
          if ( v77 >= v78 )
            goto LABEL_27;
        }
        NumLocalUsers = (float *)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v80);
        v85 = NumLocalUsers[1];
        v86 = NumLocalUsers[2];
        v174 = NumLocalUsers[1];
        v175 = NumLocalUsers[2];
        v176 = NumLocalUsers[3];
        v92 = (float *)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v80);
        v93 = v92[4];
        v94 = v92[6];
        v84 = v92[7];
        v95 = v92[7];
        v181 = v95;
        v189 = v92[5];
        v191 = v84;
        _FP5 = (float)((float)((float)(v93 * v93)
                             + (float)((float)(v189 * v189) + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v97 = (float)((float)((float)(v93 * v93)
                            + (float)((float)(v189 * v189) + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                    * (float)0.5);
        __asm { fsel      f3, f5, f6, f0 }
        v99 = __frsqrte(_FP3);
        v100 = (float)-(float)((float)((float)((float)v99
                                             * (float)((float)((float)(v93 * v93)
                                                             + (float)((float)(v189 * v189)
                                                                     + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                                                     * (float)0.5))
                                     * (float)v99)
                             - (float)1.5);
        v101 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v100 * (float)v99)
                                                                                     * (float)v97)
                                                                             * (float)((float)v100 * (float)v99))
                                                                     - (float)1.5)
                                                     * (float)((float)v100 * (float)v99))
                                             * (float)v97)
                                     * (float)((float)-(float)((float)((float)((float)((float)v100 * (float)v99)
                                                                             * (float)v97)
                                                                     * (float)((float)v100 * (float)v99))
                                                             - (float)1.5)
                                             * (float)((float)v100 * (float)v99)))
                             - (float)1.5);
        v102 = (float)(v94
                     * (float)((float)v101
                             * (float)((float)-(float)((float)((float)((float)((float)v100 * (float)v99)
                                                                     * (float)((float)((float)(v93 * v93)
                                                                                     + (float)((float)(v189 * v189)
                                                                                             + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                                                                             * (float)0.5))
                                                             * (float)((float)v100 * (float)v99))
                                                     - (float)1.5)
                                     * (float)((float)v100 * (float)v99))));
        v81 = -(float)((float)((float)v101
                             * (float)((float)-(float)((float)((float)((float)((float)v100 * (float)v99)
                                                                     * (float)((float)((float)(v93 * v93)
                                                                                     + (float)((float)(v189 * v189)
                                                                                             + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                                                                             * (float)0.5))
                                                             * (float)((float)v100 * (float)v99))
                                                     - (float)1.5)
                                     * (float)((float)v100 * (float)v99)))
                     * v93);
        v188 = v81;
        v82 = -(float)(v189
                     * (float)((float)v101
                             * (float)((float)-(float)((float)((float)((float)((float)v100 * (float)v99)
                                                                     * (float)((float)((float)(v93 * v93)
                                                                                     + (float)((float)(v189 * v189)
                                                                                             + (float)((float)(v95 * v95) + (float)(v94 * v94))))
                                                                             * (float)0.5))
                                                             * (float)((float)v100 * (float)v99))
                                                     - (float)1.5)
                                     * (float)((float)v100 * (float)v99))));
        v189 = v82;
        v83 = -v102;
        v190 = -v102;
        v178 = v81;
        v179 = v82;
        v180 = v190;
      }
      if ( v214 != 0 )
      {
        v87 = v12->animData;
        if ( v87 != nullptr )
          v88 = (idVec3 *)&v87->startDelta[8];
        else
          v88 = &vec3_origin;
        v89 = v88->y;
        v90 = v88->x;
      }
      else
      {
        v89 = v69->y;
        v90 = v69->x;
      }
      v219 = v174;
      v204 = v178;
      v220 = v175;
      v103 = 0;
      v221 = v176;
      v205 = v179;
      v206 = v180;
      v207 = v181;
      *(float *)(v17 + 48) = (float)((float)((float)v85 - (float)v90) * (float)((float)v85 - (float)v90))
                           + (float)((float)((float)v86 - (float)v89) * (float)((float)v86 - (float)v89));
      v104 = v12->animData;
      if ( v104 != nullptr )
        v103 = v104->numFrames;
      idDeclMD6::FindAnimEvents(
        this: v75,
        anim: v12,
        startFrame: 0,
        endFrame: v103,
        eventNum: v218->eventnum,
        events: &v227);
      if ( v227.num <= 0 )
      {
        v109 = v221;
        v108 = v220;
        v107 = v219;
        v113 = v207;
        v126 = v206;
        v125 = v205;
        v124 = v204;
      }
      else
      {
        v105 = (D3DXShader::CTErrors *)*v227.list;
        v106 = (float *)idSignInManagerXbox::GetNumLocalUsers(this: *(D3DXShader::CTErrors **)v227.list);
        v107 = v106[1];
        v108 = v106[2];
        v109 = v106[3];
        v110 = (float *)idSignInManagerXbox::GetNumLocalUsers(this: v105);
        v111 = v110[5];
        v112 = v110[6];
        v113 = v110[7];
        v114 = v110[7];
        v196 = v110[4];
        v207 = v114;
        v198 = v112;
        v199 = v114;
        v115 = (float)((float)(v198 * v198) + (float)((float)(v196 * v196) + (float)(v199 * v199)));
        _FP6 = (float)((float)((float)(v111 * v111)
                             + (float)((float)(v198 * v198) + (float)((float)(v196 * v196) + (float)(v199 * v199))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f4, f6, f7, f0 }
        v118 = __frsqrte(_FP4);
        v119 = (float)((float)-(float)((float)((float)((float)v118
                                                     * (float)((float)((float)(v111 * v111)
                                                                     + (float)((float)(v198 * v198)
                                                                             + (float)((float)(v196 * v196)
                                                                                     + (float)(v199 * v199))))
                                                             * (float)0.5))
                                             * (float)v118)
                                     - (float)1.5)
                     * (float)v118);
        v120 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                     * (float)((float)((float)(v111 * v111) + (float)v115)
                                                                                             * (float)0.5))
                                                                             * (float)v118)
                                                                     - (float)1.5)
                                                     * (float)v118)
                                             * (float)((float)((float)(v111 * v111) + (float)v115) * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v118
                                                                             * (float)((float)((float)(v111 * v111)
                                                                                             + (float)v115)
                                                                                     * (float)0.5))
                                                                     * (float)v118)
                                                             - (float)1.5)
                                             * (float)v118))
                             - (float)1.5);
        v121 = (float)((float)((float)-(float)((float)((float)((float)((float)v120 * (float)v119)
                                                             * (float)((float)((float)(v111 * v111)
                                                                             + (float)((float)(v198 * v198)
                                                                                     + (float)((float)(v196 * v196)
                                                                                             + (float)(v199 * v199))))
                                                                     * (float)0.5))
                                                     * (float)((float)v120 * (float)v119))
                                             - (float)1.5)
                             * (float)((float)v120 * (float)v119))
                     * v196);
        v122 = (float)(v111
                     * (float)((float)-(float)((float)((float)((float)((float)v120 * (float)v119)
                                                             * (float)((float)((float)(v111 * v111)
                                                                             + (float)((float)(v198 * v198)
                                                                                     + (float)((float)(v196 * v196)
                                                                                             + (float)(v199 * v199))))
                                                                     * (float)0.5))
                                                     * (float)((float)v120 * (float)v119))
                                             - (float)1.5)
                             * (float)((float)v120 * (float)v119)));
        v123 = (float)(v112
                     * (float)((float)-(float)((float)((float)((float)((float)v120 * (float)v119)
                                                             * (float)((float)((float)(v111 * v111)
                                                                             + (float)((float)(v198 * v198)
                                                                                     + (float)((float)(v196 * v196)
                                                                                             + (float)(v199 * v199))))
                                                                     * (float)0.5))
                                                     * (float)((float)v120 * (float)v119))
                                             - (float)1.5)
                             * (float)((float)v120 * (float)v119)));
        v199 = v113;
        v124 = -v121;
        v196 = -v121;
        v125 = -v122;
        v197 = -v122;
        v126 = -v123;
        v198 = -v123;
        v204 = v196;
        v205 = v197;
        v206 = v198;
      }
      v127 = 0.0;
      v128 = v69->y;
      v129 = 0;
      v130 = v69->z;
      v131 = v12->animData;
      v210 = v69->x;
      v211 = v128;
      v212 = v130;
      if ( v131 != nullptr )
        v129 = v131->numFrames;
      idDeclMD6::FindAnimEvents(
        this: v75,
        anim: v12,
        startFrame: 0,
        endFrame: v129,
        eventNum: v209->eventnum,
        events: &v227);
      if ( v227.num <= 0 )
      {
        v138 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v135 = v212;
        v134 = v211;
        v133 = v210;
      }
      else
      {
        v132 = (float *)idSignInManagerXbox::GetNumLocalUsers(this: *(D3DXShader::CTErrors **)v227.list);
        v133 = v132[1];
        v134 = v132[2];
        v135 = v132[3];
        *(_BYTE *)(v17 + 160) = 1;
        v136 = (float)((float)v134 - v69->y);
        v137 = (float)((float)v135 - v69->z);
        v138 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v139 = (float)((float)((float)v137 * (float)v137)
                     + (float)((float)((float)((float)v133 - v69->x) * (float)((float)v133 - v69->x))
                             + (float)((float)v136 * (float)v136)));
        _FP2 = (float)((float)((float)((float)v137 * (float)v137)
                             + (float)((float)((float)((float)v133 - v69->x) * (float)((float)v133 - v69->x))
                                     + (float)((float)v136 * (float)v136)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v141 = (float)((float)((float)((float)v137 * (float)v137)
                             + (float)((float)((float)((float)v133 - v69->x) * (float)((float)v133 - v69->x))
                                     + (float)((float)v136 * (float)v136)))
                     * (float)0.5);
        __asm { fsel      f10, f2, f3, f0 }
        v143 = __frsqrte(_FP10);
        v144 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v143 * (float)v141)
                                                                                     * (float)v143)
                                                                             - (float)1.5)
                                                             * (float)v143)
                                                     * (float)v141)
                                             * (float)((float)-(float)((float)((float)((float)v143 * (float)v141)
                                                                             * (float)v143)
                                                                     - (float)1.5)
                                                     * (float)v143))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v143 * (float)v141) * (float)v143) - (float)1.5)
                             * (float)v143));
        v127 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v143 * (float)v141) * (float)v143) - (float)1.5) * (float)v143) * (float)v141)
                                                                                             * (float)((float)-(float)((float)((float)((float)v143 * (float)v141) * (float)v143) - (float)1.5) * (float)v143))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v143 * (float)v141) * (float)v143)
                                                                                             - (float)1.5)
                                                                             * (float)v143))
                                                             * (float)v141)
                                                     * (float)v144)
                                             - (float)1.5)
                             * (float)v144)
                     * (float)v139);
      }
      v145 = v12->animData;
      if ( v145 != nullptr )
        v146 = (idVec3 *)&v145->startDelta[8];
      else
        v146 = &vec3_origin;
      v147 = (float)(v146->y - (float)v134);
      v148 = (float)(v146->z - (float)v135);
      v149 = (float)((float)((float)v148 * (float)v148)
                   + (float)((float)((float)(v146->x - (float)v133) * (float)(v146->x - (float)v133))
                           + (float)((float)v147 * (float)v147)));
      v151 = (float)((float)((float)((float)v148 * (float)v148)
                           + (float)((float)((float)(v146->x - (float)v133) * (float)(v146->x - (float)v133))
                                   + (float)((float)v147 * (float)v147)))
                   * (float)0.5);
      _FP9 = (float)((float)((float)((float)v148 * (float)v148)
                           + (float)((float)((float)(v146->x - (float)v133) * (float)(v146->x - (float)v133))
                                   + (float)((float)v147 * (float)v147)))
                   - (float)v138);
      __asm { fsel      f7, f9, f10, f0 }
      v153 = __frsqrte(_FP7);
      v154 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v153 * (float)v151)
                                                                                   * (float)v153)
                                                                           - (float)1.5)
                                                           * (float)v153)
                                                   * (float)v151)
                                           * (float)((float)-(float)((float)((float)((float)v153 * (float)v151)
                                                                           * (float)v153)
                                                                   - (float)1.5)
                                                   * (float)v153))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v153 * (float)v151) * (float)v153) - (float)1.5)
                           * (float)v153));
      v155 = (float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)v151) * (float)v154)
                                                   - (float)1.5)
                                   * (float)v154)
                           * (float)v149)
                   + (float)v127);
      _FP10 = (float)(cache->maximumPathDistance
                    - (float)((float)((float)((float)-(float)((float)((float)((float)v154 * (float)v151) * (float)v154)
                                                            - (float)1.5)
                                            * (float)v154)
                                    * (float)v149)
                            + (float)v127));
      __asm { fsel      f9, f10, f4, f0 }
      cache->maximumPathDistance = _FP9;
      *(float *)(v17 + 168) = v155;
      *(float *)(v17 + 60) = v135;
      *(float *)(v17 + 52) = v133;
      *(float *)(v17 + 56) = v134;
      *(float *)(v17 + 72) = v176;
      *(float *)(v17 + 64) = v85;
      *(float *)(v17 + 68) = v86;
      *(float *)(v17 + 112) = v107;
      *(float *)(v17 + 116) = v108;
      *(float *)(v17 + 120) = v109;
      v158 = startDelta[1];
      v159 = startDelta[2];
      v160 = startDelta[3];
      v200 = *startDelta;
      v203 = v160;
      v201 = v158;
      v202 = v159;
      v161 = startDelta[3];
      _FP4 = (float)((float)((float)(v158 * v158)
                           + (float)((float)(v159 * v159) + (float)((float)(v200 * v200) + (float)(v203 * v203))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v163 = (float)((float)((float)(v158 * v158)
                           + (float)((float)(v159 * v159) + (float)((float)(v200 * v200) + (float)(v203 * v203))))
                   * (float)0.5);
      __asm { fsel      f2, f4, f5, f13 }
      v165 = __frsqrte(_FP2);
      v166 = (float)((float)-(float)((float)((float)((float)v165
                                                   * (float)((float)((float)(v158 * v158)
                                                                   + (float)((float)(v159 * v159)
                                                                           + (float)((float)(v200 * v200)
                                                                                   + (float)(v203 * v203))))
                                                           * (float)0.5))
                                           * (float)v165)
                                   - (float)1.5)
                   * (float)v165);
      v203 = startDelta[3];
      v200 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                            * (float)v166)
                                                                                    - (float)1.5)
                                                                    * (float)v166)
                                                            * (float)v163)
                                                    * (float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                    * (float)v166)
                                                                            - (float)1.5)
                                                            * (float)v166))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v166 * (float)v163) * (float)v166)
                                                    - (float)1.5)
                                    * (float)v166))
                    * v200);
      v201 = -(float)(v158
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                            * (float)v166)
                                                                                    - (float)1.5)
                                                                    * (float)v166)
                                                            * (float)v163)
                                                    * (float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                    * (float)v166)
                                                                            - (float)1.5)
                                                            * (float)v166))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v166 * (float)v163) * (float)v166)
                                                    - (float)1.5)
                                    * (float)v166)));
      v202 = -(float)(v159
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                            * (float)v166)
                                                                                    - (float)1.5)
                                                                    * (float)v166)
                                                            * (float)v163)
                                                    * (float)((float)-(float)((float)((float)((float)v166 * (float)v163)
                                                                                    * (float)v166)
                                                                            - (float)1.5)
                                                            * (float)v166))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v166 * (float)v163) * (float)v166)
                                                    - (float)1.5)
                                    * (float)v166)));
      v223.mat[1].y = -(float)((float)(v202 * (float)v82)
                             - (float)((float)(v201 * (float)v83)
                                     + (float)((float)((float)v84 * v200) + (float)((float)v161 * (float)v81))));
      v223.mat[2].y = -(float)((float)(v202 * (float)v83)
                             - (float)-(float)((float)(v201 * (float)v82)
                                             - (float)((float)((float)v161 * (float)v84) - (float)(v200 * (float)v81))));
      v223.mat[1].z = -(float)((float)((float)v83 * v200)
                             - (float)((float)((float)v161 * (float)v82)
                                     + (float)((float)(v202 * (float)v81) + (float)(v201 * (float)v84))));
      v223.mat[2].x = -(float)((float)(v201 * (float)v81)
                             - (float)((float)((float)v161 * (float)v83)
                                     + (float)((float)((float)v82 * v200) + (float)(v202 * (float)v84))));
      *(idMat3 *)(v17 + 76) = *idQuat::ToMat3(this: v230, result: (idMat3 *)&v223.mat[1].y);
      v167 = startDelta[3];
      v168 = *startDelta;
      v195 = startDelta[3];
      v192 = v168;
      v169 = startDelta[1];
      v194 = startDelta[2];
      v193 = v169;
      _FP5 = (float)((float)((float)(v193 * v193)
                           + (float)((float)(v194 * v194) + (float)((float)(v192 * v192) + (float)(v195 * v195))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v171 = (float)((float)((float)(v193 * v193)
                           + (float)((float)(v194 * v194) + (float)((float)(v192 * v192) + (float)(v195 * v195))))
                   * (float)0.5);
      __asm { fsel      f3, f5, f6, f0 }
      v173 = __frsqrte(_FP3);
      v195 = v167;
      v192 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173) * (float)v171)
                                                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173))
                                                            * (float)v171)
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173)
                                                                                            * (float)v171)
                                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5)
                                                                                            * (float)v173))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173)))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173)
                                                                    * (float)v171)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                            - (float)1.5)
                                            * (float)v173)))
                    * v168);
      v193 = -(float)(v169
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173) * (float)v171)
                                                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173))
                                                            * (float)v171)
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173)
                                                                                            * (float)v171)
                                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5)
                                                                                            * (float)v173))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173)))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173)
                                                                    * (float)v171)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                            - (float)1.5)
                                            * (float)v173))));
      v194 = -(float)(v194
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173) * (float)v171)
                                                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173))
                                                            * (float)v171)
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5) * (float)v173)
                                                                                            * (float)v171)
                                                                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173) - (float)1.5)
                                                                                            * (float)v173))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173)))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                                                            - (float)1.5)
                                                                            * (float)v173)
                                                                    * (float)v171)
                                                            * (float)((float)-(float)((float)((float)((float)v173 * (float)v171)
                                                                                            * (float)v173)
                                                                                    - (float)1.5)
                                                                    * (float)v173))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v173 * (float)v171) * (float)v173)
                                                            - (float)1.5)
                                            * (float)v173))));
      v223.mat[0].x = -(float)((float)(v194 * (float)v125)
                             - (float)((float)(v193 * (float)v126)
                                     + (float)((float)((float)v113 * v192) + (float)((float)v167 * (float)v124))));
      v223.mat[1].x = -(float)((float)(v194 * (float)v126)
                             - (float)-(float)((float)(v193 * (float)v125)
                                             - (float)((float)((float)v167 * (float)v113) - (float)(v192 * (float)v124))));
      v223.mat[0].y = -(float)((float)((float)v126 * v192)
                             - (float)((float)((float)v167 * (float)v125)
                                     + (float)((float)(v194 * (float)v124) + (float)(v193 * (float)v113))));
      v223.mat[0].z = -(float)((float)(v193 * (float)v124)
                             - (float)((float)((float)v167 * (float)v126)
                                     + (float)((float)((float)v125 * v192) + (float)(v194 * (float)v113))));
      *(idMat3 *)(v17 + 124) = *idQuat::ToMat3(this: &v231, result: &v223);
      if ( v227.listStatic == 0 || v227.listStatic == 2 )
      {
        if ( v227.list != nullptr )
          idMem::Free(this: v213, ptr: v227.list, align: ALIGN_16);
        v227.list = nullptr;
        v227.size = 0;
      }
      v227.num = 0;
      if ( ++v177 >= NumAnims )
        break;
      v3 = ai;
      v8 = v177;
      decl = v215;
    }
  }
}


// ========================================================================
// __unwind$494881
// EA  : 0x82A6852C
// RVA : 0x00A6852C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_494881()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 848 + 368));
}


// ========================================================================
// ?InitTransitionCache@idAnimWebTransitions@@SAXPAVidAI2@@AAUtransitionCache_t@1@ABVidAnimWebState@@2HPBD@Z
// EA  : 0x82A68560
// RVA : 0x00A68560
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __fastcall idAnimWebTransitions::InitTransitionCache(
        idAI2 *ai,
        idAnimWebTransitions::transitionCache_t *cache,
        idAnimWebPath *srcState,
        idAnimWebPath *dstState,
        int nodeCheckFlags,
        const char *additionalSubweb)
{
  char *v12; // r10
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *p_nodeIndex; // r9
  int i; // ctr
  idAtomicString *p_debugState; // r10
  const char **v16; // r11
  int j; // ctr
  int allocedAndFlag_high; // r11
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *p_allocedAndFlag; // r24
  char v20; // r19
  const idDeclAnimWeb *decl; // r25
  _WORD *v22; // r10
  int k; // ctr
  idDeclAnimWeb *SubWebIndexForName; // r3
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r27
  idAnimWebPath *AnimPath; // r30
  idAnimWebPath *v30; // r3
  int size; // r10
  int m; // r30
  idAnimWebPath *v33; // r3
  idAnimWebPath *v34; // r3
  int v35; // r11
  int v36; // r30
  idResource **p_nextOnHashChain; // r10
  unsigned int *p_md5Checksum; // r11
  int n; // ctr
  idDeclAnimWeb::idNodeCache *v40; // r28
  int v41; // r27
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *edgeIndexCache; // r29
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v43; // r30
  idDeclAnimWeb::idEdgeCache *list; // r4
  idDeclAnimWeb::idEdgeCache *v45; // r5
  idDeclAnimWebNode *v46; // r10
  int flags; // r10
  idDeclAnimWeb::idNodeCache *v48; // r11
  int v49; // r8
  int numEdges; // r7
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v51; // r10
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v52; // r11
  idAnimWebState *v53; // r3
  idResource **v54; // r10
  idAtomicString *v55; // r11
  int ii; // ctr
  idAnimWebPath *v57; // r30
  idAnimWebPath *v58; // r3
  idAnimWebPath *v59; // r3
  idStr *p_changeId; // r3
  idAnimWebPath *v61; // r30
  idAnimWebPath *v62; // r3
  int v63; // [sp+8h] [-298h]
  int v64; // [sp+Ch] [-294h]
  int v65; // [sp+10h] [-290h]
  int v66; // [sp+14h] [-28Ch]
  int v67; // [sp+18h] [-288h]
  int v68; // [sp+1Ch] [-284h]
  int v69; // [sp+20h] [-280h]
  idIndex<short,enum invalidUserChannelIndex_t> *v70; // [sp+24h] [-27Ch]
  idDeclAnimWeb v71; // [sp+50h] [-250h] BYREF
  idStr v72; // [sp+170h] [-130h] BYREF
  idStr v73; // [sp+190h] [-110h] BYREF
  idAnimWebState v74; // [sp+1B0h] [-F0h] BYREF
  idStr v75; // [sp+1D0h] [-D0h] BYREF
  idStr v76[5]; // [sp+1F0h] [-B0h] BYREF

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&cache->transitions);
  v12 = &srcState[-1].baseBuffer[16];
  p_nodeIndex = &cache[-1].nodeIndex;
  for ( i = 5; i != 0; --i )
  {
    v12 += 4;
    p_nodeIndex += 2;
    *(_DWORD *)&p_nodeIndex->value = *(_DWORD *)v12;
  }
  p_debugState = &cache->srcState.debugState;
  v16 = (const char **)&dstState[-1].baseBuffer[16];
  for ( j = 5; j != 0; --j )
  {
    ++v16;
    ++p_debugState;
    p_debugState->str = *v16;
  }
  cache->lastCheckFlags = nodeCheckFlags;
  idAnimWebState::idAnimWebState(this: (idAnimWebState *)&v71.resourceListPtr);
  allocedAndFlag_high = SHIWORD(dstState->allocedAndFlag);
  p_allocedAndFlag = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)&srcState->allocedAndFlag;
  v20 = 0;
  decl = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
  if ( allocedAndFlag_high != SHIWORD(srcState->allocedAndFlag) )
  {
    v22 = (_WORD *)&v71.models.num + 1;
    for ( k = 32; k != 0; --k )
      *++v22 = -1;
    v71.scalars.size = 0;
    *(_DWORD *)&v71.scalars.granularity = 0x7FFFFFFF;
    if ( allocedAndFlag_high >= 0 )
    {
      SubWebIndexForName = idDeclAnimWeb::GetSubWebIndexForName(
                             this: &v71,
                             result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)decl,
                             subWebName: additionalSubweb);
      if ( (unsigned __int8)idAnimator_AnimWeb::FindPath(
                              this: (idAnimator_AnimWeb *)&ai->aiVolatile.animation,
                              startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)p_allocedAndFlag->value,
                              destNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(dstState->allocedAndFlag),
                              otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(SubWebIndexForName->__vftable),
                              path: (idAnimWebRoute *)&v71.models.size,
                              a6: v27,
                              a7: v26,
                              a8: v25,
                              a9: v63,
                              a10: v64,
                              a11: v65,
                              a12: v66,
                              a13: v67,
                              a14: v68,
                              a15: v69,
                              a16: v70) != 0 )
      {
        LOWORD(v28) = 0;
        if ( ai_debugAnimWebTransitions.valueInteger == ai->entityNumber )
        {
          AnimPath = idAnimWebState::GetAnimPath(this: (idAnimWebState *)v76, result: dstState);
          v30 = idAnimWebState::GetAnimPath(this: (idAnimWebState *)v71.settings.nodeProps, result: srcState);
          idLib::Printf(fmt: "\nInitTransitionCache, path from '%s' to '%s' \n", v30->data, AnimPath->data);
          idStr::FreeData(this: (idStr *)v71.settings.nodeProps);
          idStr::FreeData(this: v76);
          v71.subWebs.size = 0;
          v71.states.list = (idDeclAnimWeb::idStateInfo *)20;
          *(_DWORD *)&v71.subWebs.granularity = &v71.states.num;
          HIBYTE(v71.states.num) = 0;
          size = v71.scalars.size;
          for ( m = 0; m < v71.scalars.size; ++m )
          {
            if ( (m & 0x8000u) != 0 || (__int16)m >= size )
              HIWORD(v71.__vftable) = -1;
            else
              HIWORD(v71.__vftable) = *((_WORD *)&v71.models.size + (__int16)m);
            v33 = (idAnimWebPath *)idAnimWebState::idAnimWebState(
                                     this: (idAnimWebState *)&v71.programaticallyDefined,
                                     decl,
                                     _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(v71.__vftable));
            v34 = idAnimWebState::GetAnimPath(this: (idAnimWebState *)&v71.editorModels.size, result: v33);
            idLib::Printf(fmt: "     %d: %s\n", m, v34->data);
            idStr::FreeData(this: (idStr *)&v71.editorModels.size);
            size = v71.scalars.size;
          }
          idStr::FreeData(this: (idStr *)&v71.subWebs.size);
        }
        v35 = v71.scalars.size;
        if ( v71.scalars.size > 0 )
        {
          v36 = 0;
          while ( 1 )
          {
            HIWORD(v71.__vftable) = v36 < 0 || v36 >= v35 ? -1 : *((_WORD *)&v71.models.size + v36);
            idAnimWebState::idAnimWebState(
              this: (idAnimWebState *)&v71.programaticallyDefined,
              decl,
              _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(v71.__vftable));
            if ( (idAnimWebState::GetFlags(this: (idAnimWebState *)&v71.programaticallyDefined) & nodeCheckFlags) != 0 )
              break;
            v35 = v71.scalars.size;
            v28 = (__int16)(v36 + 1);
            v36 = v28;
            if ( v28 >= v71.scalars.size )
              goto LABEL_30;
          }
          p_nextOnHashChain = &v71.nextOnHashChain;
          p_md5Checksum = &v71.md5Checksum;
          for ( n = 5; n != 0; --n )
            *++p_nextOnHashChain = (idResource *)*++p_md5Checksum;
          v35 = v71.scalars.size;
        }
LABEL_30:
        if ( (__int16)v28 >= v35
          && v35 != 0
          && !idAnimWebState::Verify(this: (idAnimWebState *)&v71.resourceListPtr, errorMsg: nullptr) )
        {
          v20 = 1;
        }
      }
    }
  }
  if ( !idAnimWebState::Verify(this: (idAnimWebState *)&v71.resourceListPtr, errorMsg: nullptr) )
  {
    v40 = &decl->nodeCache.list[p_allocedAndFlag->value];
    if ( v40 != nullptr )
    {
      v41 = 0;
      edgeIndexCache = decl->edgeIndexCache;
      if ( v40->numEdges != 0 )
      {
        v43 = &edgeIndexCache[v40->edgeIndexOffset];
        do
        {
          list = decl->edgeCache.list;
          v45 = &list[v43->value];
          if ( v45 != nullptr )
          {
            HIWORD(v71.__vftable) = v45->destNodeIndex.value;
            if ( SHIWORD(v71.__vftable) == -1 || (v46 = decl->nodes.list[SHIWORD(v71.__vftable)]) == nullptr )
              flags = 0;
            else
              flags = v46->flags;
            if ( (flags & nodeCheckFlags) != 0 )
            {
              v48 = &decl->nodeCache.list[SHIWORD(v71.__vftable)];
              if ( v48 != nullptr )
              {
                v49 = 0;
                numEdges = v48->numEdges;
                if ( v48->numEdges != 0 )
                {
                  v51 = &edgeIndexCache[v48->edgeIndexOffset];
                  while ( 1 )
                  {
                    v52 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)&srcState->allocedAndFlag;
                    if ( v20 == 0 )
                      v52 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)&dstState->allocedAndFlag;
                    if ( list[v51->value].destNodeIndex.value == v52->value )
                      break;
                    ++v49;
                    ++v51;
                    if ( v49 >= numEdges )
                      goto LABEL_54;
                  }
                  v53 = idAnimWebState::idAnimWebState(
                          this: (idAnimWebState *)&v71.programaticallyDefined,
                          decl,
                          _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v45->destNodeIndex.value);
                  v54 = &v71.nextOnHashChain;
                  v55 = &v53[-1].debugState;
                  for ( ii = 5; ii != 0; --ii )
                  {
                    ++v55;
                    *++v54 = (idResource *)v55->str;
                  }
                }
              }
            }
LABEL_54:
            if ( idAnimWebState::Verify(this: (idAnimWebState *)&v71.resourceListPtr, errorMsg: nullptr) )
              break;
          }
          ++v41;
          ++v43;
        }
        while ( v41 < v40->numEdges );
      }
    }
    if ( ai_debugAnimWebTransitions.valueInteger == ai->entityNumber )
    {
      if ( idAnimWebState::Verify(this: (idAnimWebState *)&v71.resourceListPtr, errorMsg: nullptr) )
      {
        v57 = idAnimWebState::GetAnimPath(this: (idAnimWebState *)&v73, result: dstState);
        v58 = idAnimWebState::GetAnimPath(this: (idAnimWebState *)&v75, result: srcState);
        idLib::Printf(fmt: "\nInitTransitionCache, one step transition path from '%s' to '%s' \n", v58->data, v57->data);
        idStr::FreeData(this: &v75);
        idStr::FreeData(this: &v73);
        v59 = idAnimWebState::GetAnimPath(
                this: (idAnimWebState *)&v71.changeId,
                result: (idAnimWebPath *)&v71.resourceListPtr);
        idLib::Printf(fmt: "     : %s\n", v59->data);
        p_changeId = (idStr *)&v71.changeId;
      }
      else
      {
        v61 = idAnimWebState::GetAnimPath(this: &v74, result: dstState);
        v62 = idAnimWebState::GetAnimPath(this: (idAnimWebState *)&v72, result: srcState);
        idLib::Printf(
          fmt: "\nInitTransitionCache, no one step transition path from '%s' to '%s' \n",
          v62->data,
          v61->data);
        idStr::FreeData(this: &v72);
        p_changeId = (idStr *)&v74;
      }
      idStr::FreeData(this: p_changeId);
    }
  }
  if ( idAnimWebState::Verify(this: (idAnimWebState *)&v71.resourceListPtr, errorMsg: nullptr) )
    idAnimWebTransitions::FillTransitionCache(ai, cache, transitionState: (idAnimWebState *)&v71.resourceListPtr);
}


// ========================================================================
// __unwind$495661
// EA  : 0x82A68ACC
// RVA : 0x00A68ACC
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495661()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 496));
}


// ========================================================================
// __unwind$495662
// EA  : 0x82A68AF4
// RVA : 0x00A68AF4
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495662()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 336));
}


// ========================================================================
// __unwind$495663
// EA  : 0x82A68B1C
// RVA : 0x00A68B1C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495663()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 160));
}


// ========================================================================
// __unwind$495664
// EA  : 0x82A68B44
// RVA : 0x00A68B44
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495664()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 272));
}


// ========================================================================
// __unwind$495665
// EA  : 0x82A68B6C
// RVA : 0x00A68B6C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 400));
}


// ========================================================================
// __unwind$495666
// EA  : 0x82A68B94
// RVA : 0x00A68B94
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 464));
}


// ========================================================================
// __unwind$495667
// EA  : 0x82A68BBC
// RVA : 0x00A68BBC
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495667()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 304));
}


// ========================================================================
// __unwind$495668
// EA  : 0x82A68BE4
// RVA : 0x00A68BE4
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495668()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 432));
}


// ========================================================================
// __unwind$495669
// EA  : 0x82A68C0C
// RVA : 0x00A68C0C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void _unwind_495669()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 368));
}


// ========================================================================
// `dynamic initializer for 'ai_debugAnimWebTransitions''
// EA  : 0x83367D00
// RVA : 0x01367D00
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugAnimWebTransitions__()
{
  idCVar::idCVar(
    this: &ai_debugAnimWebTransitions,
    name: "ai_debugAnimWebTransitions",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugAnimWebTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_arrivalAngleInfluence''
// EA  : 0x83367D58
// RVA : 0x01367D58
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_arrivalAngleInfluence__()
{
  idCVar::idCVar(
    this: &ai_arrivalAngleInfluence,
    name: "ai_arrivalAngleInfluence",
    value: "150.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_arrivalAngleInfluence__);
}


// ========================================================================
// `dynamic initializer for 'ai_turnAngleInfluence''
// EA  : 0x83367DB0
// RVA : 0x01367DB0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_turnAngleInfluence__()
{
  idCVar::idCVar(
    this: &ai_turnAngleInfluence,
    name: "ai_turnAngleInfluence",
    value: "500.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_turnAngleInfluence__);
}


// ========================================================================
// `dynamic initializer for 'ai_forceNoTransitions''
// EA  : 0x83367E08
// RVA : 0x01367E08
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_forceNoTransitions__()
{
  idCVar::idCVar(
    this: &ai_forceNoTransitions,
    name: "ai_forceNoTransitions",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_forceNoTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_arrivalMinAlignDot''
// EA  : 0x83367E60
// RVA : 0x01367E60
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_arrivalMinAlignDot__()
{
  idCVar::idCVar(
    this: &ai_arrivalMinAlignDot,
    name: "ai_arrivalMinAlignDot",
    value: "0.7071",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_arrivalMinAlignDot__);
}


// ========================================================================
// `dynamic initializer for 'ai_departureAngleInfluence''
// EA  : 0x83367EB8
// RVA : 0x01367EB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_departureAngleInfluence__()
{
  idCVar::idCVar(
    this: &ai_departureAngleInfluence,
    name: "ai_departureAngleInfluence",
    value: "3.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_departureAngleInfluence__);
}


// ========================================================================
// `dynamic initializer for 'idAnimWebTransitions::defaultStepTransitionValidation''
// EA  : 0x83367F10
// RVA : 0x01367F10
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void *_dynamic_initializer_for__idAnimWebTransitions::defaultStepTransitionValidation__()
{
  float v1[13]; // [sp+50h] [-40h] BYREF

  v1[0] = 0.0;
  v1[6] = NAN;
  v1[5] = 1.0;
  v1[3] = 20.0;
  HIWORD(v1[4]) = 0;
  v1[1] = -0.000000050005699;
  v1[7] = 0.0;
  v1[2] = -1.0;
  v1[8] = 0.0;
  v1[10] = -1.0;
  HIBYTE(v1[9]) = 1;
  LODWORD(v1[11]) = 65537;
  HIWORD(v1[12]) = 1;
  return memcpy(
           Dst: &idAnimWebTransitions::defaultStepTransitionValidation,
           Src: v1,
           Size: sizeof(idAnimWebTransitions::defaultStepTransitionValidation));
}


// ========================================================================
// `dynamic initializer for 'idAnimWebTransitions::defaultArrivalTransitionValidation''
// EA  : 0x83367FB8
// RVA : 0x01367FB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void *_dynamic_initializer_for__idAnimWebTransitions::defaultArrivalTransitionValidation__()
{
  float v1[13]; // [sp+50h] [-40h] BYREF

  v1[6] = NAN;
  LODWORD(v1[0]) = 4;
  v1[5] = 1.0;
  v1[3] = 5.0;
  v1[7] = 0.0;
  v1[1] = -0.000000050005699;
  v1[8] = 0.0;
  v1[2] = -0.000000050005699;
  HIBYTE(v1[9]) = 1;
  v1[10] = -0.000000050005699;
  *(_WORD *)((char *)&v1[11] + 1) = 0;
  LOBYTE(v1[11]) = 1;
  HIWORD(v1[12]) = 1;
  HIWORD(v1[4]) = 257;
  HIBYTE(v1[11]) = 1;
  return memcpy(
           Dst: &idAnimWebTransitions::defaultArrivalTransitionValidation,
           Src: v1,
           Size: sizeof(idAnimWebTransitions::defaultArrivalTransitionValidation));
}


// ========================================================================
// `dynamic initializer for 'idAnimWebTransitions::defaultFlightTransitionValidation''
// EA  : 0x83368058
// RVA : 0x01368058
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void *_dynamic_initializer_for__idAnimWebTransitions::defaultFlightTransitionValidation__()
{
  float v1[13]; // [sp+50h] [-40h] BYREF

  HIWORD(v1[4]) = 0;
  v1[3] = 5.0;
  v1[6] = NAN;
  v1[1] = -1.0;
  memset(&v1[7], 0, 9);
  v1[2] = -1.0;
  v1[10] = -1.0;
  HIBYTE(v1[11]) = 0;
  v1[5] = 2.0;
  *(_WORD *)((char *)&v1[11] + 1) = 0;
  LOBYTE(v1[11]) = 1;
  HIWORD(v1[12]) = 1;
  LODWORD(v1[0]) = 1;
  return memcpy(
           Dst: &idAnimWebTransitions::defaultFlightTransitionValidation,
           Src: v1,
           Size: sizeof(idAnimWebTransitions::defaultFlightTransitionValidation));
}


// ========================================================================
// `dynamic initializer for 'idAnimWebTransitions::defaultSoftStopTransitionValidation''
// EA  : 0x833680F8
// RVA : 0x013680F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void *_dynamic_initializer_for__idAnimWebTransitions::defaultSoftStopTransitionValidation__()
{
  float v1[13]; // [sp+50h] [-40h] BYREF

  v1[0] = 0.0;
  v1[5] = 1.0;
  HIWORD(v1[4]) = 0;
  v1[3] = 5.0;
  v1[6] = NAN;
  v1[1] = -1.0;
  memset(&v1[7], 0, 9);
  v1[2] = -1.0;
  v1[10] = -1.0;
  HIBYTE(v1[11]) = 0;
  *(_WORD *)((char *)&v1[11] + 1) = 0;
  LOBYTE(v1[11]) = 1;
  HIWORD(v1[12]) = 1;
  return memcpy(
           Dst: &idAnimWebTransitions::defaultSoftStopTransitionValidation,
           Src: v1,
           Size: sizeof(idAnimWebTransitions::defaultSoftStopTransitionValidation));
}


// ========================================================================
// `dynamic initializer for 'idAnimWebTransitions::defaultDepartureTransitionValidation''
// EA  : 0x83368198
// RVA : 0x01368198
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.cpp
// ========================================================================

void *_dynamic_initializer_for__idAnimWebTransitions::defaultDepartureTransitionValidation__()
{
  float v1[13]; // [sp+50h] [-40h] BYREF

  HIWORD(v1[4]) = 256;
  v1[6] = NAN;
  v1[1] = 0.86602539;
  v1[7] = 0.0;
  v1[5] = 1.0;
  v1[8] = 0.0;
  v1[3] = 5.0;
  *(_WORD *)((char *)&v1[11] + 1) = 256;
  v1[2] = 0.70710677;
  LODWORD(v1[0]) = 4;
  v1[10] = 0.70710677;
  HIBYTE(v1[9]) = 1;
  LOBYTE(v1[11]) = 1;
  HIWORD(v1[12]) = 257;
  HIBYTE(v1[11]) = 1;
  return memcpy(
           Dst: &idAnimWebTransitions::defaultDepartureTransitionValidation,
           Src: v1,
           Size: sizeof(idAnimWebTransitions::defaultDepartureTransitionValidation));
}

