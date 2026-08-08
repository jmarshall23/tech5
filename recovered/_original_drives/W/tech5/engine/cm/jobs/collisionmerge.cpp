
// ========================================================================
// ?MergeContentsResults@idCollisionDetectionMerge@@CAXPAUqueryResults_t@@PBU2@HH@Z
// EA  : 0x825E3570
// RVA : 0x005E3570
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeContentsResults(
        queryResults_t *finalResult,
        const queryResults_t *mergeResults,
        int numMergeResults,
        int resultSize)
{
  unsigned __int8 *data; // r30
  int v9; // r27
  int v10; // r29
  unsigned __int8 *v11; // r31
  int v12; // r11

  data = finalResult->data;
  trace_t::operator=(this: (trace_t *)finalResult->data, __that: (const trace_t *)mergeResults->data);
  v9 = 0;
  if ( numMergeResults > 1 )
  {
    v10 = numMergeResults - 1;
    v11 = &mergeResults->data[resultSize + 12];
    do
    {
      if ( *((_DWORD *)v11 + 19) != 0 && *(_DWORD *)&finalResult->data[88] == 0 )
      {
        *(float *)data = *((float *)v11 - 3);
        *((float *)data + 1) = *((float *)v11 - 2);
        *((float *)data + 2) = *((float *)v11 - 1);
        *((float *)data + 3) = *(float *)v11;
        *((float *)data + 4) = *((float *)v11 + 1);
        *((float *)data + 5) = *((float *)v11 + 2);
        *((float *)data + 6) = *((float *)v11 + 3);
        *((float *)data + 7) = *((float *)v11 + 4);
        *((float *)data + 8) = *((float *)v11 + 5);
        *((float *)data + 9) = *((float *)v11 + 6);
        *((float *)data + 10) = *((float *)v11 + 7);
        *((float *)data + 11) = *((float *)v11 + 8);
        *((float *)data + 12) = *((float *)v11 + 9);
        contactInfo_t::operator=(this: (contactInfo_t *)(data + 52), __that: (const contactInfo_t *)(v11 + 40));
      }
      v12 = *((_DWORD *)v11 + 19);
      --v10;
      v11 += resultSize;
      v9 |= v12;
    }
    while ( v10 != 0 );
  }
  *(_DWORD *)&finalResult->data[88] |= v9;
}


// ========================================================================
// ?MergeMotionResults@idCollisionDetectionMerge@@SAXPAUtrace_t@@PBU2@1@Z
// EA  : 0x825E3670
// RVA : 0x005E3670
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeMotionResults(
        trace_t *result,
        const trace_t *rotation,
        const trace_t *translation)
{
  double fraction; // fp0
  char *v4; // r10
  float *p_z; // r11
  int v7; // ctr
  double v8; // fp31
  double v9; // fp9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  char v18; // [sp+5Ch] [-44h] BYREF
  float v19; // [sp+60h] [-40h]
  float v20; // [sp+64h] [-3Ch]
  float v21; // [sp+68h] [-38h]
  float v22; // [sp+6Ch] [-34h]
  float v23; // [sp+70h] [-30h]
  float v24; // [sp+74h] [-2Ch]
  float v25; // [sp+78h] [-28h]
  float v26; // [sp+7Ch] [-24h]
  float v27; // [sp+80h] [-20h]
  idVec3 endpos; // 0:^50.12

  fraction = rotation->fraction;
  v4 = &v18;
  p_z = &rotation->endpos.z;
  endpos = rotation->endpos;
  v7 = 9;
  v8 = (float)((float)(rotation->fraction + translation->fraction) * (float)0.5);
  do
  {
    ++p_z;
    v4 += 4;
    *(float *)v4 = *p_z;
    --v7;
  }
  while ( v7 != 0 );
  if ( fraction >= 1.0 )
    rotation = translation;
  trace_t::operator=(this: result, __that: rotation);
  result->fraction = v8;
  result->endpos = endpos;
  result->endAxis.mat[0].x = v19;
  v9 = v20;
  v10 = v21;
  result->endAxis.mat[1].x = v22;
  v11 = v23;
  result->endAxis.mat[0].y = v9;
  result->endAxis.mat[0].z = v10;
  v12 = v24;
  result->endAxis.mat[1].y = v11;
  v13 = v25;
  result->endAxis.mat[1].z = v12;
  v14 = v26;
  result->endAxis.mat[2].x = v13;
  v15 = v27;
  result->endAxis.mat[2].y = v14;
  result->endAxis.mat[2].z = v15;
}


// ========================================================================
// ?MergeStepMoveResults@idCollisionDetectionMerge@@SAXPAUtrace_t@@PBU2@11_N@Z
// EA  : 0x825E3770
// RVA : 0x005E3770
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeStepMoveResults(
        trace_t *result,
        const trace_t *down,
        const trace_t *forward2,
        const trace_t *forward1,
        bool slideMove)
{
  char v8; // r28
  double v9; // fp13
  double v10; // fp11
  double v11; // fp8

  v8 = 0;
  if ( down->fraction < 1.0 )
  {
    v8 = 2;
    if ( (float)((float)((float)(down->c.normal.y + down->c.normal.x) * (float)0.0) + down->c.normal.z) > 0.70710677 )
      v8 = 6;
  }
  if ( slideMove && (v8 & 2) != 0 && (v8 & 4) == 0 )
  {
    trace_t::operator=(this: result, __that: forward1);
    result->c.separation = 0.0;
  }
  else
  {
    if ( forward1->fraction >= 1.0 || forward2->fraction >= 1.0 )
      result->fraction = 1.0;
    else
      result->fraction = (float)((float)((float)1.0 - forward1->fraction) * forward2->fraction) + forward1->fraction;
    result->endpos = down->endpos;
    result->endAxis = down->endAxis;
    contactInfo_t::operator=(this: &result->c, __that: &forward2->c);
    v9 = (float)(down->endpos.x - forward1->endpos.x);
    v10 = (float)(down->endpos.y - forward1->endpos.y);
    v11 = (float)(down->endpos.z - forward1->endpos.z);
    result->c.flags |= v8;
    result->c.separation = (float)((float)((float)v10 + (float)v9) * (float)0.0) + (float)v11;
  }
}


// ========================================================================
// ClipVelocity
// EA  : 0x825E3908
// RVA : 0x005E3908
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

int __fastcall ClipVelocity(idVec3 *velocity, const idVec3 *planes, int numPlanes)
{
  int v4; // r3
  float *p_y; // r4
  float *i; // r7
  double v7; // fp12
  double y; // fp11
  double v9; // fp10
  double z; // fp9
  double v11; // fp0
  double v12; // fp0
  int v13; // r6
  float *v14; // r9
  double v15; // fp0
  double v16; // fp0
  double x; // fp10
  double v18; // fp1
  double v19; // fp13
  double v20; // fp0
  double v21; // fp12
  double v22; // fp11
  double v23; // fp13
  int v24; // r11
  float *v25; // r8
  double v26; // fp8
  double v27; // fp9
  double v28; // fp0
  double v31; // fp1
  double v32; // fp10
  double v33; // fp10
  double v34; // fp8
  double v35; // fp1
  double v36; // fp0
  double v37; // fp10
  double v38; // fp0

  v4 = 0;
  if ( numPlanes <= 0 )
    return 0;
  p_y = &planes->y;
  for ( i = p_y; ; i += 3 )
  {
    v7 = *i;
    y = velocity->y;
    v9 = i[1];
    z = velocity->z;
    v11 = (float)((float)(velocity->z * i[1]) + (float)((float)(velocity->y * *i) + (float)(velocity->x * *(i - 1))));
    if ( v11 < 0.050000001 )
      break;
LABEL_20:
    if ( ++v4 >= numPlanes )
      return 0;
  }
  if ( v11 >= 0.0 )
    v12 = (float)((float)((float)(velocity->z * i[1])
                        + (float)((float)(velocity->y * *i) + (float)(velocity->x * *(i - 1))))
                * (float)0.99900097);
  else
    v12 = (float)((float)((float)(velocity->z * i[1])
                        + (float)((float)(velocity->y * *i) + (float)(velocity->x * *(i - 1))))
                * (float)1.001);
  v13 = 0;
  v14 = p_y;
  velocity->x = velocity->x - (float)(*(i - 1) * (float)v12);
  velocity->y = (float)y - (float)((float)v7 * (float)v12);
  velocity->z = (float)z - (float)((float)v9 * (float)v12);
  while ( 1 )
  {
    if ( v13 != v4 )
    {
      v15 = (float)((float)(v14[1] * velocity->z)
                  + (float)((float)(velocity->y * *v14) + (float)(velocity->x * *(v14 - 1))));
      if ( v15 < 0.050000001 )
      {
        v16 = v15 >= 0.0
            ? (float)((float)((float)(v14[1] * velocity->z)
                            + (float)((float)(velocity->y * *v14) + (float)(velocity->x * *(v14 - 1))))
                    * (float)0.99900097)
            : (float)((float)((float)(v14[1] * velocity->z)
                            + (float)((float)(velocity->y * *v14) + (float)(velocity->x * *(v14 - 1))))
                    * (float)1.001);
        x = velocity->x;
        v18 = (float)(v14[1] * (float)v16);
        v19 = (float)(*(v14 - 1) * (float)v16);
        v21 = (float)(velocity->y - (float)(*v14 * (float)v16));
        v20 = velocity->z;
        velocity->y = v21;
        v22 = (float)((float)v20 - (float)v18);
        velocity->z = (float)v20 - (float)v18;
        v23 = (float)((float)x - (float)v19);
        velocity->x = v23;
        if ( (float)((float)((float)v21 * *i)
                   + (float)((float)(i[1] * (float)((float)v20 - (float)v18)) + (float)(*(i - 1) * (float)v23))) < 0.0 )
          break;
      }
    }
LABEL_19:
    ++v13;
    v14 += 3;
    if ( v13 >= numPlanes )
      goto LABEL_20;
  }
  v24 = 0;
  v25 = p_y;
  v26 = (float)((float)(i[1] * *(v14 - 1)) - (float)(*(i - 1) * v14[1]));
  v27 = (float)((float)(*i * v14[1]) - (float)(i[1] * *v14));
  v28 = (float)((float)(*(i - 1) * *v14) - (float)(*i * *(v14 - 1)));
  _FP31 = (float)((float)((float)((float)v27 * (float)v27)
                        + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f31, f1, f10 }
  v31 = __frsqrte(_FP10);
  v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                      * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)))
                                                                                              * (float)0.5))
                                                                              * (float)v31)
                                                                      - (float)1.5)
                                                      * (float)v31)
                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                              + (float)((float)((float)v28 * (float)v28)
                                                                      + (float)((float)v26 * (float)v26)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                                                              + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)))
                                                                                      * (float)0.5))
                                                                      * (float)v31)
                                                              - (float)1.5)
                                              * (float)v31))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v28 * (float)v28)
                                                                              + (float)((float)v26 * (float)v26)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                              * (float)v31)
                                                                                      * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                      * (float)v31))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                      * (float)v31)
                                                                              - (float)1.5)
                                                              * (float)v31))
                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                              + (float)((float)((float)v28 * (float)v28)
                                                                      + (float)((float)v26 * (float)v26)))
                                                      * (float)0.5))
                                      * (float)v32)
                              - (float)1.5)
              * (float)v32);
  v34 = (float)((float)((float)(i[1] * *(v14 - 1)) - (float)(*(i - 1) * v14[1])) * (float)v33);
  v35 = (float)((float)((float)(*(i - 1) * *v14) - (float)(*i * *(v14 - 1))) * (float)v33);
  v36 = (float)((float)v33 * (float)((float)(*i * v14[1]) - (float)(i[1] * *v14)));
  v37 = (float)((float)((float)v23 * (float)((float)v33 * (float)((float)(*i * v14[1]) - (float)(i[1] * *v14))))
              + (float)((float)((float)v22
                              * (float)((float)((float)(*(i - 1) * *v14) - (float)(*i * *(v14 - 1))) * (float)v33))
                      + (float)((float)v21
                              * (float)((float)((float)(i[1] * *(v14 - 1)) - (float)(*(i - 1) * v14[1])) * (float)v33))));
  v38 = (float)((float)v36 * (float)v37);
  velocity->x = v38;
  velocity->y = (float)v34 * (float)v37;
  velocity->z = (float)v35 * (float)v37;
  while ( v24 == v4
       || v24 == v13
       || (float)((float)(*v25 * (float)((float)v34 * (float)v37))
                + (float)((float)(v25[1] * (float)((float)v35 * (float)v37)) + (float)(*(v25 - 1) * (float)v38))) >= 0.050000001 )
  {
    ++v24;
    v25 += 3;
    if ( v24 >= numPlanes )
      goto LABEL_19;
  }
  velocity->z = 0.0;
  velocity->y = 0.0;
  velocity->x = 0.0;
  return 1;
}


// ========================================================================
// ?InitSlideMoveState@idCollisionDetectionMerge@@SAXPAUslideMoveState_t@@ABVidVec3@@1@Z
// EA  : 0x825E3BA0
// RVA : 0x005E3BA0
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::InitSlideMoveState(
        slideMoveState_t *state,
        const idVec3 *velocity,
        const idVec3 *gravityVector)
{
  idVec3 *p_endVelocity; // r29
  double x; // fp6
  double y; // fp10
  double v9; // fp2
  double z; // fp5
  double v11; // fp1
  double v14; // fp3
  double v15; // fp2
  double v18; // fp6
  double v19; // fp4
  double v20; // fp6
  double v21; // fp8
  double v22; // fp7
  double v23; // fp3
  double v24; // fp6
  double v25; // fp7
  const idVec3 v26; // [sp+50h] [-40h]

  state->velocity = *velocity;
  state->endVelocity.z = 0.0;
  p_endVelocity = &state->endVelocity;
  state->endVelocity.y = 0.0;
  state->endVelocity.x = 0.0;
  memset(Dst: &state->firstContact, Val: 0, Size: sizeof(state->firstContact));
  state->steppedUp = 0.0;
  state->fractionRemaining = 1.0;
  x = velocity->x;
  state->startNormal.x = velocity->x;
  y = velocity->y;
  v9 = (float)((float)((float)x * (float)x) + (float)(velocity->y * velocity->y));
  state->startNormal.y = velocity->y;
  z = velocity->z;
  v11 = (float)((float)(velocity->z * velocity->z) + (float)v9);
  state->startNormal.z = velocity->z;
  _FP11 = (float)((float)v11 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f11, f1, f12 }
  v14 = __frsqrte(_FP9);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)v11 * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)v11 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)v11 * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  state->startNormal.x = (float)x
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)v11 * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14)
                                                                                               - (float)1.5)
                                                                               * (float)v14))
                                                               * (float)((float)v11 * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                               * (float)((float)v11 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                               * (float)v14))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5))
                                                                                               * (float)v14)
                                                                                       - (float)1.5)
                                                                       * (float)v14)))
                                               - (float)1.5)
                               * (float)v15);
  state->startNormal.y = (float)y
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)v11 * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14)
                                                                                               - (float)1.5)
                                                                               * (float)v14))
                                                               * (float)((float)v11 * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                               * (float)((float)v11 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                               * (float)v14))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5))
                                                                                               * (float)v14)
                                                                                       - (float)1.5)
                                                                       * (float)v14)))
                                               - (float)1.5)
                               * (float)v15);
  state->startNormal.z = (float)z
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14) * (float)((float)v11 * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14)
                                                                                               - (float)1.5)
                                                                               * (float)v14))
                                                               * (float)((float)v11 * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                               * (float)((float)v11 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                               * (float)v14))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5))
                                                                                               * (float)v14)
                                                                                       - (float)1.5)
                                                                       * (float)v14)))
                                               - (float)1.5)
                               * (float)v15);
  state->numPlanes = 0;
  v26 = *gravityVector;
  _FP2 = (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f12, f2, f3, f12 }
  v18 = __frsqrte(_FP12);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(v26.y * v26.y)
                                                              + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(v26.y * v26.y)
                                                                                              + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(v26.y * v26.y)
                                                                      + (float)((float)(v26.z * v26.z)
                                                                              + (float)(v26.x * v26.x)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))) * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18))
                                              * (float)((float)((float)(v26.y * v26.y)
                                                              + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  if ( (float)((float)v20 * (float)((float)(v26.y * v26.y) + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x)))) > 1.01 )
  {
    v21 = velocity->y;
    v22 = velocity->z;
    v23 = (float)(velocity->x
                + (float)((float)((float)((float)v20
                                        * (float)((float)(v26.y * v26.y)
                                                + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                - (float)1.0)
                        * (float)(v26.x * (float)v20)));
    p_endVelocity->x = velocity->x
                     + (float)((float)((float)((float)v20
                                             * (float)((float)(v26.y * v26.y)
                                                     + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                     - (float)1.0)
                             * (float)(v26.x * (float)v20));
    p_endVelocity->y = (float)v21
                     + (float)((float)((float)((float)v20
                                             * (float)((float)(v26.y * v26.y)
                                                     + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                     - (float)1.0)
                             * (float)((float)v20 * v26.y));
    p_endVelocity->z = (float)((float)(v26.z * (float)v20)
                             * (float)((float)((float)v20
                                             * (float)((float)(v26.y * v26.y)
                                                     + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                     - (float)1.0))
                     + (float)v22;
    v25 = (float)((float)((float)((float)(v26.z * (float)v20)
                                * (float)((float)((float)v20
                                                * (float)((float)(v26.y * v26.y)
                                                        + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                        - (float)1.0))
                        + (float)v22)
                + velocity->z);
    v24 = (float)(velocity->y
                + (float)((float)v21
                        + (float)((float)((float)((float)v20
                                                * (float)((float)(v26.y * v26.y)
                                                        + (float)((float)(v26.z * v26.z) + (float)(v26.x * v26.x))))
                                        - (float)1.0)
                                * (float)((float)v20 * v26.y))));
    state->velocity.x = (float)(velocity->x + (float)v23) * (float)0.5;
    state->velocity.y = (float)v24 * (float)0.5;
    state->velocity.z = (float)v25 * (float)0.5;
  }
}


// ========================================================================
// ?UpdateSlideMoveState@idCollisionDetectionMerge@@SA_NPAUslideMoveState_t@@PAUtrace_t@@@Z
// EA  : 0x825E3DB8
// RVA : 0x005E3DB8
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

int __fastcall idCollisionDetectionMerge::UpdateSlideMoveState(slideMoveState_t *state, trace_t *trace)
{
  double steppedUp; // fp11
  contactType_t type; // r11
  contactInfo_t *p_firstContact; // r3
  int numPlanes; // r9
  char v9; // r8
  int v10; // r10
  double z; // fp13
  double y; // fp12
  float *p_y; // r11
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp0
  idVec3 *v18; // r11
  int v19; // r5

  steppedUp = state->steppedUp;
  state->fractionRemaining = -(float)((float)(state->fractionRemaining * trace->fraction) - state->fractionRemaining);
  state->steppedUp = trace->c.separation + (float)steppedUp;
  if ( trace->fraction >= 1.0 )
  {
    state->fractionRemaining = 0.0;
    trace->c.flags |= 0x20u;
    return 1;
  }
  type = state->firstContact.type;
  p_firstContact = &state->firstContact;
  if ( type == CONTACT_NONE )
    contactInfo_t::operator=(this: p_firstContact, __that: &trace->c);
  numPlanes = state->numPlanes;
  v9 = 0;
  v10 = 0;
  if ( numPlanes > 0 )
  {
    z = trace->c.normal.z;
    y = trace->c.normal.y;
    p_y = &state->planes[0].y;
    while ( (float)((float)(*p_y * trace->c.normal.y)
                  + (float)((float)(trace->c.normal.x * *(p_y - 1)) + (float)(trace->c.normal.z * p_y[1]))) <= 0.99900001 )
    {
      ++v10;
      p_y += 3;
      if ( v10 >= state->numPlanes )
        goto LABEL_14;
    }
    v14 = state->velocity.y;
    v15 = state->velocity.z;
    if ( (float)((float)(trace->c.normal.z * state->velocity.z)
               + (float)((float)(trace->c.normal.x * state->velocity.x) + (float)(trace->c.normal.y * state->velocity.y))) >= 0.0 )
      v16 = 0.99900097;
    else
      v16 = 1.001;
    v17 = (float)((float)((float)(trace->c.normal.z * state->velocity.z)
                        + (float)((float)(trace->c.normal.x * state->velocity.x)
                                + (float)(trace->c.normal.y * state->velocity.y)))
                * (float)v16);
    v9 = 1;
    state->velocity.x = state->velocity.x
                      - (float)(trace->c.normal.x
                              * (float)((float)((float)(trace->c.normal.z * state->velocity.z)
                                              + (float)((float)(trace->c.normal.x * state->velocity.x)
                                                      + (float)(trace->c.normal.y * state->velocity.y)))
                                      * (float)v16));
    state->velocity.y = (float)v14 - (float)((float)y * (float)v17);
    state->velocity.z = (float)v15 - (float)((float)z * (float)v17);
  }
LABEL_14:
  if ( v9 == 0 )
  {
    if ( numPlanes >= 4
      || (v18 = &state->planes[numPlanes],
          v18->x = trace->c.normal.x,
          v18->y = trace->c.normal.y,
          v18->z = trace->c.normal.z,
          v19 = state->numPlanes + 1,
          state->numPlanes = v19,
          (unsigned __int8)ClipVelocity(velocity: &state->velocity, planes: state->planes, numPlanes: v19) != 0) )
    {
      state->fractionRemaining = 0.0;
      state->velocity.z = 0.0;
      state->velocity.y = 0.0;
      state->velocity.x = 0.0;
      trace->c.flags |= 0x20u;
      return 1;
    }
    if ( (float)((float)(state->startNormal.x * state->velocity.x)
               + (float)((float)(state->startNormal.z * state->velocity.z)
                       + (float)(state->startNormal.y * state->velocity.y))) < 0.0099999998 )
      idVec3::ProjectOntoPlane(this: &state->velocity, normal: &state->startNormal, overBounce: 1.0);
  }
  trace->c.normal.x = state->velocity.x;
  trace->c.normal.y = state->velocity.y;
  trace->c.normal.z = state->velocity.z;
  trace->c.dist = state->fractionRemaining;
  return 0;
}


// ========================================================================
// ?FinishSlideMoveState@idCollisionDetectionMerge@@SAXPAUslideMoveState_t@@PAUtrace_t@@@Z
// EA  : 0x825E4028
// RVA : 0x005E4028
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::FinishSlideMoveState(slideMoveState_t *state, trace_t *trace)
{
  idVec3 *p_endVelocity; // r30

  if ( ((LODWORD(state->velocity.y) | LODWORD(state->velocity.x) | LODWORD(state->velocity.z)) & 0x7FFFFFFF) != 0 )
  {
    p_endVelocity = &state->endVelocity;
    if ( ((LODWORD(state->endVelocity.z) | LODWORD(state->endVelocity.y) | LODWORD(state->endVelocity.x)) & 0x7FFFFFFF) != 0 )
    {
      ClipVelocity(velocity: &state->endVelocity, planes: state->planes, numPlanes: state->numPlanes);
      state->velocity.x = p_endVelocity->x;
      state->velocity.y = p_endVelocity->y;
      state->velocity.z = p_endVelocity->z;
    }
  }
  contactInfo_t::operator=(this: &trace->c, __that: &state->firstContact);
  trace->c.normal.x = state->velocity.x;
  trace->c.normal.y = state->velocity.y;
  trace->c.normal.z = state->velocity.z;
  trace->c.dist = state->fractionRemaining;
  trace->c.separation = state->steppedUp;
}


// ========================================================================
// ?MergeTraceResults@idCollisionDetectionMerge@@CAXPAUqueryResults_t@@PBU2@HH@Z
// EA  : 0x825E40E8
// RVA : 0x005E40E8
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeTraceResults(
        queryResults_t *finalResult,
        const queryResults_t *mergeResults,
        int numMergeResults,
        int resultSize)
{
  unsigned __int8 *data; // r31
  unsigned __int8 *v8; // r11
  int v9; // ctr

  data = finalResult->data;
  trace_t::operator=(this: (trace_t *)finalResult->data, __that: (const trace_t *)mergeResults->data);
  if ( numMergeResults > 1 )
  {
    v8 = &mergeResults->data[resultSize + 64];
    v9 = numMergeResults - 1;
    do
    {
      if ( *((float *)v8 - 16) < (double)*(float *)data )
      {
        *(float *)data = *((float *)v8 - 16);
        *((float *)data + 1) = *((float *)v8 - 15);
        *((float *)data + 2) = *((float *)v8 - 14);
        *((float *)data + 3) = *((float *)v8 - 13);
        *((float *)data + 4) = *((float *)v8 - 12);
        *((float *)data + 5) = *((float *)v8 - 11);
        *((float *)data + 6) = *((float *)v8 - 10);
        *((float *)data + 7) = *((float *)v8 - 9);
        *((float *)data + 8) = *((float *)v8 - 8);
        *((float *)data + 9) = *((float *)v8 - 7);
        *((float *)data + 10) = *((float *)v8 - 6);
        *((float *)data + 11) = *((float *)v8 - 5);
        *((float *)data + 12) = *((float *)v8 - 4);
        *((_DWORD *)data + 13) = *((_DWORD *)v8 - 3);
        *((float *)data + 14) = *((float *)v8 - 2);
        *((float *)data + 15) = *((float *)v8 - 1);
        *((float *)data + 16) = *(float *)v8;
        *((float *)data + 17) = *((float *)v8 + 1);
        *((float *)data + 18) = *((float *)v8 + 2);
        *((float *)data + 19) = *((float *)v8 + 3);
        *((float *)data + 20) = *((float *)v8 + 4);
        *((float *)data + 21) = *((float *)v8 + 5);
        *((_DWORD *)data + 22) = *((_DWORD *)v8 + 6);
        *((_DWORD *)data + 23) = *((_DWORD *)v8 + 7);
        *((_DWORD *)data + 24) = *((_DWORD *)v8 + 8);
        *((_DWORD *)data + 25) = *((_DWORD *)v8 + 9);
        *((_DWORD *)data + 26) = *((_DWORD *)v8 + 10);
        *((_DWORD *)data + 27) = *((_DWORD *)v8 + 11);
        *((_DWORD *)data + 28) = *((_DWORD *)v8 + 12);
        *((_DWORD *)data + 29) = *((_DWORD *)v8 + 13);
        *((_DWORD *)data + 30) = *((_DWORD *)v8 + 14);
        data[124] = v8[60];
        data[125] = v8[61];
        data[126] = v8[62];
        data[127] = v8[63];
      }
      v8 += resultSize;
      --v9;
    }
    while ( v9 != 0 );
  }
}


// ========================================================================
// ?MergeContactsResults@idCollisionDetectionMerge@@CAXPAUqueryResults_t@@PBU2@HH@Z
// EA  : 0x825E4268
// RVA : 0x005E4268
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeContactsResults(
        queryResults_t *finalResult,
        const queryResults_t *mergeResults,
        int numMergeResults,
        int resultSize)
{
  int v5; // r7
  unsigned __int8 *v6; // r30
  int v7; // ctr
  float *v8; // r3
  _DWORD *v9; // r31
  float *v10; // r4
  char v11; // r9
  int v12; // r11
  _DWORD *v13; // r10
  int v14; // r8
  double v15; // fp31
  int *v16; // r22
  int i; // r21
  signed int v18; // r31
  float *v19; // r29
  int v20; // r27
  float **v21; // r28
  float *v22; // r6
  char v23; // r9
  signed int v24; // r11
  float **v25; // r10
  double v26; // fp10
  double v27; // fp8
  double v28; // fp6
  float *v29; // r11
  float *v30; // r10
  double v31; // fp11
  double v32; // fp9
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  double v36; // fp1
  double v37; // fp11
  double v38; // fp7
  double v39; // fp10
  double v40; // fp0
  double v41; // fp13
  double v42; // fp12
  int v43; // r10
  double v44; // fp0
  double v45; // fp13
  int *v46; // r8
  double v47; // fp12
  float *v48; // r11
  signed int j; // ctr
  double v50; // fp11
  double v51; // fp10
  double v52; // fp9
  float *v53; // r9
  double v54; // fp3
  double v55; // fp4
  double v56; // fp2
  double v57; // fp1
  double v58; // fp8
  double v59; // fp10
  double v60; // fp7
  double v62; // fp11
  double v64; // fp9
  double v65; // fp9
  char v66; // r8
  int v67; // r11
  double v68; // fp0
  signed int v69; // ctr
  double v70; // fp13
  float **v71; // r9
  double v72; // fp12
  float *v73; // r10
  signed int v74; // r30
  int v75; // r11
  int v76; // r8
  int v77; // r30
  signed int v78; // ctr
  unsigned int v79; // r6
  int v80; // r11
  _DWORD *v81; // r7
  int v82; // r10
  int v83; // r9
  int v84; // r6
  int v85; // r11
  int v86; // r4
  double v87; // fp11
  int v88; // r3
  int v89; // r30
  int v90; // r5
  float **v91; // r28
  int v92; // r24
  signed int v93; // r25
  int v94; // r7
  float **v95; // r29
  int v96; // r26
  signed int v97; // r27
  signed int v98; // r11
  float *v99; // r8
  _DWORD *v100; // r9
  float *v101; // r10
  double v102; // fp1
  double v103; // fp7
  double v104; // fp3
  double v105; // fp1
  double v106; // fp2
  double v107; // fp7
  double v108; // fp3
  double v109; // fp7
  float *v110; // r10
  double v111; // fp2
  double v112; // fp7
  double v113; // fp3
  double v114; // fp7
  float *v115; // r10
  double v116; // fp1
  double v117; // fp0
  double v118; // fp13
  double v119; // fp0
  float *v120; // r6
  float **v121; // r9
  int v122; // ctr
  double v123; // fp1
  double v124; // fp0
  double v125; // fp9
  double v126; // fp0
  signed int v127; // r9
  int *v128; // r6
  int v129; // r11
  char v130; // r7
  float *v131; // r10
  char *v132; // r11
  _BYTE v133[13]; // [sp+4Fh] [-441h] BYREF
  int v134; // [sp+5Ch] [-434h] BYREF
  float *v135; // [sp+60h] [-430h] BYREF
  float *v136; // [sp+64h] [-42Ch]
  float *v137; // [sp+68h] [-428h]
  _DWORD v138[13]; // [sp+90h] [-400h] BYREF
  char v139; // [sp+C4h] [-3CCh] BYREF
  _DWORD v140[12]; // [sp+150h] [-340h] BYREF
  _DWORD v141[164]; // [sp+180h] [-310h] BYREF

  *(_DWORD *)finalResult->data = 0;
  v5 = 0;
  if ( numMergeResults > 0 )
  {
    v6 = &mergeResults->data[36];
    do
    {
      if ( *((int *)v6 - 9) > 0 )
      {
        v7 = *((_DWORD *)v6 - 9);
        v8 = (float *)v6;
        v9 = &v141[13 * v5 - 13];
        do
        {
          v10 = v8 - 5;
          v11 = 0;
          v12 = 0;
          if ( v5 > 0 )
          {
            v13 = v140;
            while ( (float)((float)(*(float *)(*v13 + 16) * *(v8 - 1))
                          + (float)((float)(*(float *)(*v13 + 24) * v8[1]) + (float)(*(float *)(*v13 + 20) * *v8))) <= 0.90630776 )
            {
              ++v12;
              v13 += 13;
              if ( v12 >= v5 )
                goto LABEL_13;
            }
            v14 = v141[13 * v12];
            if ( v14 < 12 )
            {
              v140[13 * v12 + v14] = v10;
              ++v141[13 * v12];
            }
            v11 = 1;
          }
LABEL_13:
          if ( v11 == 0 && v5 < 12 )
          {
            v9[1] = v10;
            ++v5;
            v9 += 13;
            *v9 = 1;
          }
          v8 += 19;
          --v7;
        }
        while ( v7 != 0 );
      }
      --numMergeResults;
      v6 += resultSize;
    }
    while ( numMergeResults != 0 );
  }
  if ( v5 > 0 )
  {
    v15 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v16 = v141;
    for ( i = v5; i != 0; --i )
    {
      v18 = 0;
      if ( *v16 > 0 )
      {
        v19 = v135;
        v20 = *v16;
        v21 = (float **)(v16 - 12);
        do
        {
          v22 = *v21;
          if ( v18 != 0 )
          {
            v23 = 0;
            v24 = 0;
            if ( v18 > 0 )
            {
              v25 = &v135;
              while ( 1 )
              {
                v26 = (float)(v22[3] - (*v25)[3]);
                v27 = (float)(v22[1] - (*v25)[1]);
                v28 = (float)(v22[2] - (*v25)[2]);
                if ( (float)((float)((float)v28 * (float)v28)
                           + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) < 1.0 )
                  break;
                ++v24;
                ++v25;
                if ( v24 >= v18 )
                  goto LABEL_30;
              }
              v23 = 1;
            }
LABEL_30:
            if ( v23 == 0 )
            {
              if ( v18 > 1 )
              {
                if ( v18 > 2 )
                {
                  v43 = 0;
                  v44 = v19[6];
                  v45 = v19[4];
                  v46 = &v134;
                  v47 = v19[5];
                  v48 = (float *)&v138[11];
                  for ( j = v18; j != 0; --j )
                  {
                    ++v43;
                    v50 = *(float *)(*++v46 + 4);
                    v51 = *(float *)(*v46 + 8);
                    v52 = *(float *)(*v46 + 12);
                    __twllei(v18, 0);
                    __twlgei(v18 & ~(__ROL4__(v43, 1) - 1), 0xFFFFFFFF);
                    v53 = (&v135)[v43 % v18];
                    v54 = (float)(v53[3] - (float)v52);
                    v55 = (float)(v53[2] - (float)v51);
                    v56 = (float)((float)v47 * (float)(v53[1] - (float)v50));
                    v57 = (float)((float)v44 * (float)(v53[2] - (float)v51));
                    v58 = (float)((float)((float)v44 * (float)(v53[1] - (float)v50))
                                - (float)((float)v45 * (float)(v53[3] - (float)v52)));
                    v48[2] = (float)((float)v44 * (float)(v53[1] - (float)v50))
                           - (float)((float)v45 * (float)(v53[3] - (float)v52));
                    v59 = (float)((float)((float)v45 * (float)v55) - (float)v56);
                    v48[3] = (float)((float)v45 * (float)v55) - (float)v56;
                    v48[1] = (float)((float)v47 * (float)v54) - (float)v57;
                    v60 = (float)((float)((float)v47 * (float)v54) - (float)v57);
                    _FP1 = (float)((float)((float)((float)v59 * (float)v59)
                                         + (float)((float)((float)v60 * (float)v60) + (float)((float)v58 * (float)v58)))
                                 - (float)v15);
                    v62 = (float)((float)((float)((float)v59 * (float)v59)
                                        + (float)((float)((float)v60 * (float)v60) + (float)((float)v58 * (float)v58)))
                                * (float)0.5);
                    __asm { fsel      f10, f1, f2, f31 }
                    v64 = __frsqrte(_FP10);
                    v65 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)v62)
                                                                                                * (float)v64)
                                                                                        - (float)1.5)
                                                                        * (float)v64)
                                                                * (float)v62)
                                                        * (float)((float)-(float)((float)((float)((float)v64 * (float)v62)
                                                                                        * (float)v64)
                                                                                - (float)1.5)
                                                                * (float)v64))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v64 * (float)v62) * (float)v64)
                                                        - (float)1.5)
                                        * (float)v64));
                    v48[1] = (float)v60
                           * (float)((float)-(float)((float)((float)((float)v65 * (float)v62) * (float)v65) - (float)1.5)
                                   * (float)v65);
                    v48[2] = (float)v58
                           * (float)((float)-(float)((float)((float)((float)v65 * (float)v62) * (float)v65) - (float)1.5)
                                   * (float)v65);
                    v48 += 3;
                    *v48 = (float)((float)((float)v45 * (float)v55) - (float)v56)
                         * (float)((float)-(float)((float)((float)((float)v65 * (float)v62) * (float)v65) - (float)1.5)
                                 * (float)v65);
                  }
                  v66 = 0;
                  v67 = 0;
                  v68 = v22[1];
                  v69 = v18;
                  v70 = v22[2];
                  v71 = &v135;
                  v72 = v22[3];
                  v73 = (float *)&v139;
                  do
                  {
                    if ( (float)((float)(*(v73 - 1) * (float)((float)v68 - (*v71)[1]))
                               + (float)((float)(*v73 * (float)((float)v70 - (*v71)[2]))
                                       + (float)(v73[1] * (float)((float)v72 - (*v71)[3])))) < 1.0 )
                    {
                      v133[v67 + 1] = 0;
                    }
                    else
                    {
                      v66 = 1;
                      v133[v67 + 1] = 1;
                    }
                    ++v67;
                    ++v71;
                    v73 += 3;
                    --v69;
                  }
                  while ( v69 != 0 );
                  if ( v66 != 0 )
                  {
                    v74 = 0;
                    v75 = 1;
                    while ( 1 )
                    {
                      if ( v133[v75] == 0 )
                      {
                        __twllei(v18, 0);
                        v76 = (unsigned __int8)v133[v75 % v18 + 1];
                        __twlgei(v18 & ~(__ROL4__(v75, 1) - 1), 0xFFFFFFFF);
                        if ( v76 != 0 )
                          break;
                      }
                      ++v74;
                      ++v75;
                      if ( v74 >= v18 )
                        goto LABEL_66;
                    }
                    if ( v74 < v18 )
                    {
                      v138[0] = v22;
                      memset(Dst: &v138[1], Val: 0, Size: 0x2Cu);
                      v78 = v18;
                      v79 = v18 & ~(__ROL4__(v74 + 1, 1) - 1);
                      v80 = (v74 + 1) % v18;
                      v77 = 1;
                      __twllei(v18, 0);
                      __twlgei(v79, 0xFFFFFFFF);
                      v81 = v138;
                      do
                      {
                        v82 = v80 + 1;
                        v84 = (unsigned __int8)v133[v80 % v18 + 1];
                        __twllei(v18, 0);
                        __twllei(v18, 0);
                        __twlgei(v18 & ~(__ROL4__(v80 + 1, 1) - 1), 0xFFFFFFFF);
                        v83 = __ROL4__(v80, 1) - 1;
                        v85 = (v80 + 1) % v18;
                        __twlgei(v18 & ~v83, 0xFFFFFFFF);
                        if ( v84 == 0 || v133[v85 + 1] == 0 )
                        {
                          ++v77;
                          *++v81 = (&v135)[v85];
                        }
                        v80 = v82;
                        --v78;
                      }
                      while ( v78 != 0 );
                      if ( v77 > 0 )
                      {
                        blkmov(a1: &v135, a2: v138, a3: 4 * v77);
                        v19 = v135;
                      }
                      v18 = v77;
                    }
                  }
                }
                else
                {
                  v29 = v19 + 1;
                  v30 = v136 + 1;
                  v31 = (float)((float)((float)(v136[2] - v19[2]) * (float)(v22[1] - v19[1]))
                              - (float)((float)(v22[2] - v19[2]) * (float)(v136[1] - v19[1])));
                  v32 = (float)((float)((float)(v22[3] - v19[3]) * (float)(v136[1] - v19[1]))
                              - (float)((float)(v136[3] - v19[3]) * (float)(v22[1] - v19[1])));
                  v33 = (float)((float)((float)(v136[3] - v19[3]) * (float)(v22[2] - v19[2]))
                              - (float)((float)(v136[2] - v19[2]) * (float)(v22[3] - v19[3])));
                  if ( (float)((float)((float)v32 * (float)v32)
                             + (float)((float)((float)v33 * (float)v33) + (float)((float)v31 * (float)v31))) >= v15 )
                  {
                    if ( (float)((float)(v19[4]
                                       * (float)((float)((float)(v136[3] - v19[3]) * (float)(v22[2] - v19[2]))
                                               - (float)((float)(v136[2] - v19[2]) * (float)(v22[3] - v19[3]))))
                               + (float)((float)(v19[6]
                                               * (float)((float)((float)(v136[2] - v19[2]) * (float)(v22[1] - v19[1]))
                                                       - (float)((float)(v22[2] - v19[2]) * (float)(v136[1] - v19[1]))))
                                       + (float)(v19[5]
                                               * (float)((float)((float)(v22[3] - v19[3]) * (float)(v136[1] - v19[1]))
                                                       - (float)((float)(v136[3] - v19[3]) * (float)(v22[1] - v19[1])))))) <= 0.0 )
                    {
                      v137 = v136;
                      ++v18;
                      v136 = v22;
                    }
                    else
                    {
                      v137 = *v21;
                      ++v18;
                    }
                  }
                  else
                  {
                    v34 = (float)(v22[3] - v19[3]);
                    v35 = (float)(v22[3] - v136[3]);
                    v36 = (float)(v19[3] - v136[3]);
                    v37 = (float)(v22[2] - v19[2]);
                    v38 = (float)(v22[2] - v136[2]);
                    v39 = (float)(v19[2] - v136[2]);
                    v40 = (float)((float)((float)v37 * (float)v37)
                                + (float)((float)((float)(v22[1] - *v29) * (float)(v22[1] - *v29))
                                        + (float)((float)v34 * (float)v34)));
                    v41 = (float)((float)((float)v38 * (float)v38)
                                + (float)((float)((float)(v22[1] - *v30) * (float)(v22[1] - *v30))
                                        + (float)((float)v35 * (float)v35)));
                    v42 = (float)((float)((float)v39 * (float)v39)
                                + (float)((float)((float)(*v29 - *v30) * (float)(*v29 - *v30))
                                        + (float)((float)v36 * (float)v36)));
                    if ( v40 <= v41 || v40 <= v42 )
                    {
                      if ( v41 > v40 && v41 > v42 )
                      {
                        v19 = *v21;
                        v135 = *v21;
                      }
                    }
                    else
                    {
                      v136 = *v21;
                    }
                  }
                }
              }
              else
              {
                (&v135)[v18++] = v22;
                v19 = v135;
              }
            }
          }
          else
          {
            v19 = *v21;
            v135 = *v21;
            v18 = 1;
          }
LABEL_66:
          --v20;
          ++v21;
        }
        while ( v20 != 0 );
      }
      v86 = 0;
      v87 = 0.0;
      v88 = 1;
      v89 = 2;
      v90 = 0;
      if ( v18 > 0 )
      {
        v91 = &v135;
        v92 = v18 - 2;
        do
        {
          v93 = v90 + 1;
          v94 = v90 + 1;
          if ( v90 + 1 < v18 )
          {
            v95 = v91 + 1;
            v96 = v92;
            do
            {
              v97 = v94 + 1;
              v98 = v94 + 1;
              if ( v94 + 1 < v18 )
              {
                if ( v96 >= 4 )
                {
                  v99 = *v91;
                  v100 = v95 + 2;
                  do
                  {
                    v101 = (float *)*(v100 - 1);
                    v102 = (float)((float)((float)((*v95)[3] - v99[3]) * (float)(v101[1] - v99[1]))
                                 - (float)((float)(v101[3] - v99[3]) * (float)((*v95)[1] - v99[1])));
                    v103 = (float)((float)((float)(v101[2] - v99[2]) * (float)((*v95)[1] - v99[1]))
                                 - (float)((float)((*v95)[2] - v99[2]) * (float)(v101[1] - v99[1])));
                    v104 = (float)((float)((float)(v101[3] - v99[3]) * (float)((*v95)[2] - v99[2]))
                                 - (float)((float)(v101[2] - v99[2]) * (float)((*v95)[3] - v99[3])));
                    v105 = (float)((float)((float)v103 * (float)v103) + (float)((float)v102 * (float)v102));
                    if ( (float)((float)((float)v104 * (float)v104) + (float)v105) > v87 )
                    {
                      v87 = (float)((float)((float)v104 * (float)v104) + (float)v105);
                      v86 = v90;
                      v88 = v94;
                      v89 = v98;
                    }
                    v106 = (float)((float)((float)((*v95)[3] - v99[3]) * (float)(*(float *)(*v100 + 4) - v99[1]))
                                 - (float)((float)(*(float *)(*v100 + 12) - v99[3]) * (float)((*v95)[1] - v99[1])));
                    v107 = (float)((float)((float)(*(float *)(*v100 + 8) - v99[2]) * (float)((*v95)[1] - v99[1]))
                                 - (float)((float)((*v95)[2] - v99[2]) * (float)(*(float *)(*v100 + 4) - v99[1])));
                    v108 = (float)((float)((float)(*(float *)(*v100 + 12) - v99[3]) * (float)((*v95)[2] - v99[2]))
                                 - (float)((float)(*(float *)(*v100 + 8) - v99[2]) * (float)((*v95)[3] - v99[3])));
                    v109 = (float)((float)((float)v108 * (float)v108)
                                 + (float)((float)((float)v107 * (float)v107) + (float)((float)v106 * (float)v106)));
                    if ( v109 > v87 )
                    {
                      v87 = v109;
                      v86 = v90;
                      v88 = v94;
                      v89 = v98 + 1;
                    }
                    v110 = (float *)v100[1];
                    v111 = (float)((float)((float)((*v95)[3] - v99[3]) * (float)(v110[1] - v99[1]))
                                 - (float)((float)(v110[3] - v99[3]) * (float)((*v95)[1] - v99[1])));
                    v112 = (float)((float)((float)(v110[2] - v99[2]) * (float)((*v95)[1] - v99[1]))
                                 - (float)((float)((*v95)[2] - v99[2]) * (float)(v110[1] - v99[1])));
                    v113 = (float)((float)((float)(v110[3] - v99[3]) * (float)((*v95)[2] - v99[2]))
                                 - (float)((float)(v110[2] - v99[2]) * (float)((*v95)[3] - v99[3])));
                    v114 = (float)((float)((float)v113 * (float)v113)
                                 + (float)((float)((float)v112 * (float)v112) + (float)((float)v111 * (float)v111)));
                    if ( v114 > v87 )
                    {
                      v87 = v114;
                      v86 = v90;
                      v88 = v94;
                      v89 = v98 + 2;
                    }
                    v115 = (float *)v100[2];
                    v116 = (float)((float)((float)((*v95)[3] - v99[3]) * (float)(v115[1] - v99[1]))
                                 - (float)((float)(v115[3] - v99[3]) * (float)((*v95)[1] - v99[1])));
                    v117 = (float)((float)((float)(v115[2] - v99[2]) * (float)((*v95)[1] - v99[1]))
                                 - (float)((float)((*v95)[2] - v99[2]) * (float)(v115[1] - v99[1])));
                    v118 = (float)((float)((float)(v115[3] - v99[3]) * (float)((*v95)[2] - v99[2]))
                                 - (float)((float)(v115[2] - v99[2]) * (float)((*v95)[3] - v99[3])));
                    v119 = (float)((float)((float)v118 * (float)v118)
                                 + (float)((float)((float)v117 * (float)v117) + (float)((float)v116 * (float)v116)));
                    if ( v119 > v87 )
                    {
                      v87 = v119;
                      v86 = v90;
                      v88 = v94;
                      v89 = v98 + 3;
                    }
                    v98 += 4;
                    v100 += 4;
                  }
                  while ( v98 < v18 - 3 );
                }
                if ( v98 < v18 )
                {
                  v120 = *v91;
                  v121 = &(&v135)[v98];
                  v122 = v18 - v98;
                  do
                  {
                    v123 = (float)((float)((float)((*v95)[3] - v120[3]) * (float)((*v121)[1] - v120[1]))
                                 - (float)((float)((*v121)[3] - v120[3]) * (float)((*v95)[1] - v120[1])));
                    v124 = (float)((float)((float)((*v121)[2] - v120[2]) * (float)((*v95)[1] - v120[1]))
                                 - (float)((float)((*v95)[2] - v120[2]) * (float)((*v121)[1] - v120[1])));
                    v125 = (float)((float)((float)((*v121)[3] - v120[3]) * (float)((*v95)[2] - v120[2]))
                                 - (float)((float)((*v121)[2] - v120[2]) * (float)((*v95)[3] - v120[3])));
                    v126 = (float)((float)((float)v125 * (float)v125)
                                 + (float)((float)((float)v124 * (float)v124) + (float)((float)v123 * (float)v123)));
                    if ( v126 > v87 )
                    {
                      v87 = v126;
                      v86 = v90;
                      v88 = v94;
                      v89 = v98;
                    }
                    ++v98;
                    ++v121;
                    --v122;
                  }
                  while ( v122 != 0 );
                }
              }
              ++v94;
              --v96;
              ++v95;
            }
            while ( v97 < v18 );
          }
          ++v90;
          --v92;
          ++v91;
        }
        while ( v93 < v18 );
      }
      v127 = 0;
      if ( v18 > 0 )
      {
        v128 = &v134;
        do
        {
          v129 = *(_DWORD *)finalResult->data;
          if ( v129 >= 12 )
            break;
          if ( v127 != v86 && v127 != v88 )
          {
            v130 = 16;
            if ( v127 != v89 )
              continue;
          }
          v130 = 0;
          v131 = (float *)*++v128;
          v132 = (char *)finalResult + 76 * v129;
          ++v127;
          *((_DWORD *)v132 + 16) = *(_DWORD *)*v128;
          *((float *)v132 + 17) = v131[1];
          *((float *)v132 + 18) = v131[2];
          *((float *)v132 + 19) = v131[3];
          *((float *)v132 + 20) = v131[4];
          *((float *)v132 + 21) = v131[5];
          *((float *)v132 + 22) = v131[6];
          *((float *)v132 + 23) = v131[7];
          *((float *)v132 + 24) = v131[8];
          *((float *)v132 + 25) = v131[9];
          *((float *)v132 + 26) = v131[10];
          *((float *)v132 + 27) = v131[11];
          *((float *)v132 + 28) = v131[12];
          *((float *)v132 + 29) = v131[13];
          *((float *)v132 + 30) = v131[14];
          *((float *)v132 + 31) = v131[15];
          *((float *)v132 + 32) = v131[16];
          *((float *)v132 + 33) = v131[17];
          v132[136] = *((_BYTE *)v131 + 72);
          v132[137] = *((_BYTE *)v131 + 73);
          v132[138] = *((_BYTE *)v131 + 74);
          v132[139] = *((_BYTE *)v131 + 75);
          finalResult->data[76 * (*(_DWORD *)finalResult->data)++ + 88] |= v130;
        }
        while ( v127 < v18 );
        v15 = idMath::FLT_SMALLEST_NON_DENORMAL;
      }
      v16 += 13;
    }
  }
}


// ========================================================================
// ?MergeClipResults@idCollisionDetectionMerge@@CAXPAUqueryResults_t@@PBU2@HH@Z
// EA  : 0x825E4D50
// RVA : 0x005E4D50
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeClipResults(
        queryResults_t *finalResult,
        const queryResults_t *mergeResults,
        int numMergeResults,
        int resultSize)
{
  unsigned __int8 *data; // r27
  unsigned __int8 *v9; // r25
  unsigned __int8 *v10; // r23
  int i; // ctr
  unsigned __int8 *v12; // r22
  int v13; // r5
  _WORD *v14; // r6
  float *v15; // r9
  int v16; // r7
  int v17; // r8
  float *v18; // r10
  bool v19; // r11
  int v20; // r11
  float *v21; // r11
  int v22; // r28
  __int16 *v23; // r29
  int v24; // r7
  __int16 v25; // r3
  __int16 v26; // r31
  __int16 v27; // r30
  int v28; // r6
  unsigned __int8 *v29; // r11
  int v30; // r9
  __int16 v31; // r10
  bool v32; // cr58
  unsigned __int8 *v33; // r11
  _WORD v34[88]; // [sp+50h] [-B0h] BYREF

  data = finalResult->data;
  clipResult_t::operator=(this: (clipResult_t *)finalResult->data, __that: (const clipResult_t *)mergeResults->data);
  if ( numMergeResults > 1 )
  {
    v9 = &finalResult->data[400];
    v10 = &mergeResults->data[resultSize];
    for ( i = numMergeResults - 1; i != 0; --i )
    {
      v12 = v10 - 48;
      v13 = 0;
      if ( *(int *)v10 > 0 )
      {
        v14 = v34;
        v15 = (float *)(v10 + 16);
        do
        {
          v16 = *(_DWORD *)data;
          v17 = 0;
          *v14 = -1;
          if ( v16 > 0 )
          {
            v18 = (float *)&finalResult->data[24];
            while ( 1 )
            {
              v19 = false;
              if ( __fabs((float)(*v15 - *(v18 - 2))) <= 0.1 && __fabs((float)(v15[1] - *(v18 - 1))) <= 0.1 )
                v19 = __fabs((float)(v15[2] - *v18)) <= 0.1;
              if ( v19 )
                break;
              ++v17;
              v18 += 3;
              if ( v17 >= v16 )
                goto LABEL_14;
            }
            *v14 = v17;
          }
LABEL_14:
          if ( (unsigned __int16)*v14 == 0xFFFF && v16 < 32 )
          {
            v20 = *(_DWORD *)data;
            *v14 = v16;
            *(_DWORD *)data = v20 + 1;
            v21 = (float *)&finalResult->data[12 * v20 + 16];
            *v21 = *v15;
            v21[1] = v15[1];
            v21[2] = v15[2];
          }
          ++v13;
          ++v14;
          v15 += 3;
        }
        while ( v13 < *(_DWORD *)v10 );
      }
      v22 = 0;
      if ( *((int *)v12 + 13) <= 0 )
        goto LABEL_41;
      v23 = (__int16 *)(v12 + 450);
      do
      {
        v24 = *(_DWORD *)&finalResult->data[4];
        if ( v24 + 3 >= 264 )
          break;
        v25 = v34[*(v23 - 1)];
        v26 = v34[*v23];
        v27 = v34[v23[1]];
        if ( v25 == -1 || v26 == -1 || v27 == -1 )
          goto LABEL_40;
        v28 = 0;
        if ( v24 <= 0 )
          goto LABEL_39;
        v29 = &finalResult->data[402];
        while ( 1 )
        {
          v30 = *((__int16 *)v29 - 1);
          v31 = *(_WORD *)v29;
          if ( v25 == v30 )
          {
            if ( v26 == v31 )
            {
              v32 = v27 == *((__int16 *)v29 + 1);
              goto LABEL_35;
            }
            goto LABEL_36;
          }
          if ( v25 != v31 )
            break;
          if ( v26 == *((__int16 *)v29 + 1) )
          {
            v32 = v27 == v30;
            goto LABEL_35;
          }
LABEL_36:
          v28 += 3;
          v29 += 6;
          if ( v28 >= v24 )
            goto LABEL_39;
        }
        if ( v25 != *((__int16 *)v29 + 1) || v26 != v30 )
          goto LABEL_36;
        v32 = v27 == v31;
LABEL_35:
        if ( !v32 )
          goto LABEL_36;
        if ( v28 >= v24 )
        {
LABEL_39:
          v33 = &v9[2 * v24];
          *(_WORD *)v33 = v25;
          *((_WORD *)v33 + 1) = v26;
          *(_WORD *)&v9[2 * v24 + 4] = v27;
          *(_DWORD *)&finalResult->data[4] += 3;
        }
LABEL_40:
        v22 += 3;
        v23 += 3;
      }
      while ( v22 < *((_DWORD *)v12 + 13) );
LABEL_41:
      v10 += resultSize;
    }
  }
}


// ========================================================================
// ?MergeQueryResults@idCollisionDetectionMerge@@SAXPAUqueryResults_t@@HW4traceType_t@@PBU2@HPAUslideMoveState_t@@W4dependencyType_t@@22@Z
// EA  : 0x825E5028
// RVA : 0x005E5028
// PDB : w:\tech5\engine\cm\jobs\collisionmerge.cpp
// ========================================================================

void __fastcall idCollisionDetectionMerge::MergeQueryResults(
        queryResults_t *finalResult,
        int resultSize,
        traceType_t type,
        const queryResults_t *mergeResults,
        int numMergeResults,
        slideMoveState_t *slideMoveState,
        dependencyType_t dependencyType,
        const queryResults_t *dependency1,
        const queryResults_t *dependency2,
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
        int a28)
{
  if ( (unsigned int)(type - 1) <= 8 )
  {
    switch ( type )
    {
      case TRACE_TRANSLATION_POINT:
      case TRACE_ROTATION:
      case TRACE_ROTATION_POINT:
        goto LABEL_10;
      case TRACE_CONTENTS:
      case TRACE_CONTENTS_POINT:
        idCollisionDetectionMerge::MergeContentsResults(finalResult, mergeResults, numMergeResults, resultSize);
        break;
      case TRACE_CONTACTS_UNI_DIR:
      case TRACE_CONTACTS_OMNI_DIR:
        idCollisionDetectionMerge::MergeContactsResults(finalResult, mergeResults, numMergeResults, resultSize);
        break;
      case TRACE_TRANSLATION:
LABEL_10:
        idCollisionDetectionMerge::MergeTraceResults(finalResult, mergeResults, numMergeResults, resultSize);
        break;
      default:
        idCollisionDetectionMerge::MergeClipResults(finalResult, mergeResults, numMergeResults, resultSize);
        break;
    }
  }
  switch ( dependencyType )
  {
    case DEPENDENCY_MOTION_ROTATION:
      idCollisionDetectionMerge::MergeMotionResults(
        result: (trace_t *)finalResult->data,
        rotation: (const trace_t *)finalResult->data,
        translation: (const trace_t *)dependency1->data);
      break;
    case DEPENDENCY_MOTION_CONTACTS:
      if ( *(float *)dependency1->data < 1.0 && *(_DWORD *)finalResult->data == 0 )
      {
        contactInfo_t::operator=(
          this: (contactInfo_t *)&finalResult->data[16],
          __that: (const contactInfo_t *)&dependency1->data[52]);
        *(_DWORD *)finalResult->data = 1;
      }
      break;
    case DEPENDENCY_STEPMOVE_STEP_DOWN:
      idCollisionDetectionMerge::MergeStepMoveResults(
        result: (trace_t *)finalResult->data,
        down: (const trace_t *)finalResult->data,
        forward2: (const trace_t *)dependency1->data,
        forward1: (const trace_t *)(a28 + 48),
        slideMove: false);
      break;
    case DEPENDENCY_SLIDEMOVE_STEP_UP_2:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_3:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_4:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_2:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_3:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_4:
    case DEPENDENCY_SLIDEMOVE_SLIDE:
      if ( slideMoveState->fractionRemaining <= 0.0 )
        finalResult->data[124] |= 0x20u;
      break;
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_1:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_2:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_3:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_4:
      idCollisionDetectionMerge::MergeStepMoveResults(
        result: (trace_t *)finalResult->data,
        down: (const trace_t *)finalResult->data,
        forward2: (const trace_t *)dependency1->data,
        forward1: (const trace_t *)(a28 + 48),
        slideMove: true);
      if ( slideMoveState->fractionRemaining > 0.0 )
        idCollisionDetectionMerge::UpdateSlideMoveState(state: slideMoveState, trace: (trace_t *)finalResult->data);
      else
        finalResult->data[124] |= 0x20u;
      if ( dependencyType == DEPENDENCY_SLIDEMOVE_STEP_DOWN_4 )
        idCollisionDetectionMerge::FinishSlideMoveState(state: slideMoveState, trace: (trace_t *)finalResult->data);
      break;
    default:
      break;
  }
  finalResult->query.type = type;
  finalResult->query.done = 1;
  finalResult->query.merged = 1;
  finalResult->query.status = mergeResults->query.status;
}

