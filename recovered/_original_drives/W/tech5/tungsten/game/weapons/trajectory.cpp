
// ========================================================================
// ?HasResults@idTrajectory_Parabolic@@UBA_NXZ
// EA  : 0x82EDD598
// RVA : 0x00EDD598
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

int __fastcall idTrajectory_Parabolic::HasResults(idTrajectory_Parabolic *this)
{
  unsigned __int8 v1; // r11

  if ( this->results[0].impactSteps >= 0 )
    return 1;
  v1 = 0;
  if ( this->results[1].impactSteps >= 0 )
    return 1;
  return v1;
}


// ========================================================================
// ?ClearResults@idTrajectory_Parabolic@@UAAXXZ
// EA  : 0x82EDD5C0
// RVA : 0x00EDD5C0
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::ClearResults(idTrajectory_Parabolic *this)
{
  this->results[0].impactSteps = -1;
  this->results[1].impactSteps = -1;
}


// ========================================================================
// ?Calc@idTrajectory_Parabolic@@QAAXABVidVec3@@0MM@Z
// EA  : 0x82EDD5E0
// RVA : 0x00EDD5E0
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::Calc(
        idTrajectory_Parabolic *this,
        const idVec3 *start,
        const idVec3 *target,
        double g,
        double t)
{
  double v6; // fp8
  double v7; // fp29
  long double v12; // fp4
  double v13; // fp28
  double v14; // fp27
  long double v15; // fp2
  long double v16; // fp2
  double v17; // fp0

  v6 = (float)(target->y - start->y);
  v7 = (float)(target->z - start->z);
  *((double *)&v12 + 1) = (float)((float)((float)g * (float)t) * (float)t);
  *(double *)&v12 = (float)((float)(target->x - start->x) * (float)(target->x - start->x));
  v13 = (float)((float)((float)((float)((float)((float)g * (float)t) * (float)t) * (float)-0.5)
                      - (float)(target->z - start->z))
              * (float)((float)1.0 / (float)t));
  v14 = (float)((float)__fsqrts((float)((float)((float)v6 * (float)v6)
                                      + (float)((float)(target->x - start->x) * (float)(target->x - start->x))))
              * (float)((float)1.0 / (float)t));
  *(double *)&v15 = v13;
  *((double *)&v15 + 1) = v14;
  v16 = atan2(v: v15, u: v12);
  v17 = idMath::M_RAD2DEG;
  this->start = *start;
  this->dest = *target;
  this->results[0].impacted = false;
  this->parms[0].angle = (float)v17 * (float)*(double *)&v16;
  this->parms[0].time = t;
  this->results[0].impactSteps = -1;
  this->parms[0].maxHeight = (float)((float)((float)v13 * (float)v13) / (float)((float)g * (float)2.0)) + (float)v7;
  this->parms[0].speed = __fsqrts((float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
  this->parms[0].vertSpeed = v13;
  this->parms[0].horizSpeed = v14;
  this->parms[0].gravity = g;
  memset(Dst: this->results, Val: 0, Size: 0x80u);
  this->numTrajectories = 1;
}


// ========================================================================
// ?Draw@idTrajectory_Parabolic@@SAXABVidColor@@ABVidVec3@@1ABUparabolicParms_t@1@MH_N@Z
// EA  : 0x82EDD720
// RVA : 0x00EDD720
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::Draw(
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *target,
        const idTrajectory_Parabolic::parabolicParms_t *parms,
        double timeStep,
        const int duration,
        int depthTest,
        BOOL a8)
{
  double y; // fp12
  double v16; // fp0
  int v17; // r31
  float v18; // r10
  float z; // r9
  double v20; // fp0
  double v21; // fp13
  double v22; // fp31
  double v23; // fp29
  double v24; // fp12
  double v25; // fp28
  double v26; // fp13
  double v27; // fp0
  double v28; // fp7
  float x; // [sp+58h] [-B8h] BYREF
  float v30; // [sp+5Ch] [-B4h]
  float v31; // [sp+60h] [-B0h]
  float v32; // [sp+68h] [-A8h] BYREF
  float v33; // [sp+6Ch] [-A4h]
  float v34; // [sp+70h] [-A0h]
  idAngles v35; // [sp+78h] [-98h] BYREF
  idAngles v36; // [sp+88h] [-88h] BYREF
  idVec3 v37[4]; // [sp+98h] [-78h] BYREF

  y = target->y;
  v35.pitch = target->x - start->x;
  v35.yaw = (float)y - start->y;
  v35.roll = 0.0;
  idVec3::ToAngles(this: v37, result: &v35);
  clientGame->renderWorld->DebugPoint(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&idColor::colorRed,
    a3: start,
    a4: depthTest,
    a5: a8);
  clientGame->renderWorld->DebugPoint(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&idColor::colorGreen,
    a3: target,
    a4: depthTest,
    a5: a8);
  v16 = (float)(parms->time / (float)timeStep);
  if ( (float)((float)(parms->time / (float)timeStep) - (float)__fabs(v16)) != 0.0 )
    v16 = (float)((float)(parms->time / (float)timeStep) + (float)1.0);
  v37[0].x = parms->angle;
  v17 = (int)v16;
  idAngles::ToForward(this: &v36, result: v37);
  v18 = start->y;
  z = start->z;
  v20 = (float)(v36.pitch * parms->speed);
  v21 = (float)(v36.yaw * parms->speed);
  v22 = (float)(v36.roll * parms->speed);
  x = start->x;
  v30 = v18;
  v31 = z;
  if ( v17 > 0 )
  {
    v23 = (float)((float)v20 * (float)timeStep);
    v24 = v31;
    v25 = (float)((float)v21 * (float)timeStep);
    v26 = v30;
    v27 = x;
    do
    {
      v32 = (float)v23 + (float)v27;
      v33 = (float)v26 + (float)v25;
      v28 = (float)((float)v24 + (float)((float)v22 * (float)timeStep));
      v22 = (float)-(float)((float)((float)timeStep * parms->gravity) - (float)v22);
      v34 = v28;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: color,
        a3: (const idVec3 *)&x,
        a4: (const idVec3 *)&v32,
        a5: depthTest,
        a6: a8);
      v27 = v32;
      v26 = v33;
      --v17;
      v24 = v34;
      x = v32;
      v30 = v33;
      v31 = v34;
    }
    while ( v17 != 0 );
  }
}


// ========================================================================
// ?SelectTrajectory@idTrajectory_Parabolic@@SAPBV1@PBV1@HAAH@Z
// EA  : 0x82EDD8F8
// RVA : 0x00EDD8F8
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
const idTrajectory_Parabolic *__fastcall idTrajectory_Parabolic::SelectTrajectory(
        const idTrajectory_Parabolic *trajectories,
        int num,
        int *parmsIndex)
{
  double v6; // fp31
  int v7; // r26
  double v8; // fp30
  int v9; // r25
  int v10; // r28
  const idTrajectory_Parabolic *v11; // r30
  int v12; // r27
  int v13; // r31
  float *p_angle; // r29
  __int64 v15; // r7 OVERLAPPED
  double v16; // fp0
  double v17; // fp13

  v6 = 0.0;
  v7 = -1;
  v8 = 360.0;
  v9 = -1;
  v10 = 0;
  if ( num <= 0 )
    return nullptr;
  v11 = trajectories;
  do
  {
    if ( v11->HasResults(this: (struct idTrajectory_Parabolic *)v11) )
    {
      v12 = v11->NumTrajectories(this: (struct idTrajectory_Parabolic *)v11);
      v13 = 0;
      if ( v12 > 0 )
      {
        p_angle = &v11->parms[0].angle;
        do
        {
          v15 = *(_QWORD *)&v11->GetSimulationResults(this: v11, a2: v13)[1].impactResult.fraction;
          v16 = (float)((float)*(__int64 *)((char *)&v15 + 4) / (float)v15);
          if ( v16 > 0.75 )
          {
            v17 = __fabs((float)((float)-45.0 - *p_angle));
            if ( v16 > v6 || v16 == v6 && v17 < v8 )
            {
              v7 = v10;
              v6 = (float)((float)*(__int64 *)((char *)&v15 + 4) / (float)v15);
              v9 = v13;
              v8 = v17;
            }
          }
          ++v13;
          p_angle += 7;
        }
        while ( v13 < v12 );
      }
    }
    ++v10;
    ++v11;
  }
  while ( v10 < num );
  if ( v7 < 0 )
    return nullptr;
  *parmsIndex = v9;
  return &trajectories[v7];
}


// ========================================================================
// ??0idTrajectory_Parabolic@@QAA@XZ
// EA  : 0x82EDDA78
// RVA : 0x00EDDA78
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

idTrajectory_Parabolic *__fastcall idTrajectory_Parabolic::idTrajectory_Parabolic(idTrajectory_Parabolic *this)
{
  bool *p_impacted; // r29
  float *p_vertSpeed; // r26
  float *p_numTrajectories; // r30
  int v5; // r27

  this->__vftable = (idTrajectory_Parabolic_vtbl *)&idTrajectory_Parabolic::`vftable';
  this->start.x = 0.0;
  p_impacted = &this->results[0].impacted;
  this->start.y = 0.0;
  p_vertSpeed = &this->parms[1].vertSpeed;
  this->start.z = 0.0;
  p_numTrajectories = (float *)&this->numTrajectories;
  this->dest.x = 0.0;
  v5 = 2;
  this->dest.y = 0.0;
  this->dest.z = 0.0;
  this->numTrajectories = 0;
  this->gravity = 0.0;
  this->parms[0].time = 0.0;
  this->parms[0].speed = 0.0;
  this->parms[0].gravity = 0.0;
  this->parms[0].angle = 0.0;
  this->parms[0].maxHeight = 0.0;
  this->parms[0].horizSpeed = 0.0;
  this->parms[0].vertSpeed = 0.0;
  this->parms[1].time = 0.0;
  this->parms[1].speed = 0.0;
  this->parms[1].gravity = 0.0;
  this->parms[1].angle = 0.0;
  this->parms[1].maxHeight = 0.0;
  this->parms[1].horizSpeed = 0.0;
  this->parms[1].vertSpeed = 0.0;
  this->results[0].impacted = false;
  this->results[0].impactSteps = -1;
  this->results[0].numSteps = 0;
  this->results[1].impacted = false;
  this->results[1].impactSteps = -1;
  this->results[1].numSteps = 0;
  do
  {
    p_numTrajectories[4] = 0.0;
    p_numTrajectories[1] = 0.0;
    p_numTrajectories[5] = 0.0;
    p_numTrajectories[2] = 0.0;
    p_numTrajectories[6] = 0.0;
    p_numTrajectories += 7;
    *p_numTrajectories = 0.0;
    *++p_vertSpeed = 0.0;
    *((_DWORD *)p_impacted + 1) = -1;
    *p_impacted = false;
    *((_DWORD *)p_impacted + 2) = 0;
    memset(Dst: p_impacted - 128, Val: 0, Size: 0x80u);
    --v5;
    p_impacted += 140;
  }
  while ( v5 != 0 );
  return this;
}


// ========================================================================
// ?WaitingOnJob@idTrajectory_Parabolic@@UBA_NXZ
// EA  : 0x82EDDBA0
// RVA : 0x00EDDBA0
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

int __fastcall idTrajectory_Parabolic::WaitingOnJob(idTrajectory_Parabolic *this)
{
  idStaticList<idClipQuery,32> **queries; // r26
  int v2; // r25
  idStaticList<idClipQuery,32> *v3; // r11
  int num; // r31
  _BYTE v5[12]; // r11
  idClipQuery *list; // r6
  int v7; // r8
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r5
  __int64 v9; // r11
  char v10; // r11
  bool v11; // zf

  queries = this->queries;
  v2 = 0;
  while ( 1 )
  {
    v3 = *queries;
    if ( *queries != nullptr && v3->num > 0 )
      break;
LABEL_14:
    ++v2;
    ++queries;
    if ( v2 >= 2 )
      return 0;
  }
  num = v3->num;
  *(_DWORD *)v5 = &clientGame->clip;
  list = v3->list;
  v7 = 0;
  collisionQueryFirstSubmittedIndex = clientGame->clip.collisionQueryFirstSubmittedIndex;
  while ( 1 )
  {
    *(idClipQuery *)&v5[4] = list[v7];
    if ( *(_DWORD *)&v5[8] < (unsigned int)collisionQueryFirstSubmittedIndex
      || (*(_QWORD *)v5 = *(_QWORD *)(*(_DWORD *)v5 + 377216), *(_DWORD *)&v5[8] > *(_DWORD *)&v5[4]) )
    {
      v10 = 0;
    }
    else
    {
      v9 = *(_QWORD *)(8 * ((*(_WORD *)&v5[10] & 0xFFF) + ((2 * *(_DWORD *)&v5[8]) & 0x1FFE)) + *(_DWORD *)v5 + 278920);
      if ( (unsigned int)v9 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
        || (v11 = (unsigned int)v9 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v10 = 1, !v11) )
      {
        v10 = 0;
      }
    }
    if ( v10 != 0 )
      return 1;
    ++HIDWORD(collisionQueryFirstSubmittedIndex);
    ++v7;
    if ( SHIDWORD(collisionQueryFirstSubmittedIndex) >= num )
      goto LABEL_14;
  }
}


// ========================================================================
// ?Free@idTrajectory_Parabolic@@QAAXXZ
// EA  : 0x82EDDCB0
// RVA : 0x00EDDCB0
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::Free(idTrajectory_Parabolic *this)
{
  int v1; // r27
  __int64 v2; // r30
  _DWORD *v3; // r9
  int v4; // r10
  int v5; // r11
  int v6; // r31

  HIDWORD(v2) = this->queries;
  v1 = 2;
  LODWORD(v2) = 0;
  do
  {
    v3 = *(_DWORD **)HIDWORD(v2);
    if ( *(_DWORD *)HIDWORD(v2) != 0 )
    {
      v4 = 0;
      if ( (int)v3[1] > 0 )
      {
        v5 = 0;
        do
        {
          ++v4;
          *(_QWORD *)(*v3 + v5) = v2;
          v5 += 8;
        }
        while ( v4 < v3[1] );
      }
      v6 = *(_DWORD *)HIDWORD(v2);
      if ( *(_DWORD *)HIDWORD(v2) != 0 )
      {
        if ( *(_BYTE *)(v6 + 15) == 0 || *(_BYTE *)(v6 + 15) == 2 )
        {
          if ( *(_DWORD *)v6 != 0 )
            idMem::Free(this: &mem, ptr: *(void **)v6, align: ALIGN_16);
          *(_DWORD *)v6 = 0;
          *(_DWORD *)(v6 + 8) = 0;
        }
        *(_DWORD *)(v6 + 4) = 0;
        idMem::Free(this: &mem, ptr: (void *)v6, align: ALIGN_16);
      }
      *(_DWORD *)HIDWORD(v2) = 0;
    }
    --v1;
    HIDWORD(v2) += 4;
  }
  while ( v1 != 0 );
}


// ========================================================================
// ?Clear@idTrajectory_Parabolic@@QAAXXZ
// EA  : 0x82EDDD78
// RVA : 0x00EDDD78
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::Clear(idTrajectory_Parabolic *this)
{
  int v1; // r28
  __int64 v2; // r30
  int v3; // r31
  int v4; // r10
  int v5; // r11

  HIDWORD(v2) = this->queries;
  v1 = 2;
  LODWORD(v2) = 0;
  do
  {
    v3 = *(_DWORD *)HIDWORD(v2);
    if ( *(_DWORD *)HIDWORD(v2) != 0 && *(int *)(v3 + 4) > 0 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        ++v4;
        *(_QWORD *)(*(_DWORD *)v3 + v5) = v2;
        v5 += 8;
      }
      while ( v4 < *(_DWORD *)(v3 + 4) );
      if ( *(int *)(v3 + 8) < 0 )
      {
        if ( *(_BYTE *)(v3 + 15) == 0 || *(_BYTE *)(v3 + 15) == 2 )
        {
          if ( *(_DWORD *)v3 != 0 )
            idMem::Free(this: &mem, ptr: *(void **)v3, align: ALIGN_16);
          *(_DWORD *)v3 = 0;
          *(_DWORD *)(v3 + 8) = 0;
        }
        *(_DWORD *)(v3 + 4) = 0;
      }
      *(_DWORD *)(v3 + 4) = __CFADD__(-*(_DWORD *)(v3 + 8), *(_DWORD *)(v3 + 8) ^ 0x80000000) ? 0 : *(_DWORD *)(v3 + 8);
    }
    --v1;
    HIDWORD(v2) += 4;
  }
  while ( v1 != 0 );
}


// ========================================================================
// ?Test@idTrajectory_Parabolic@@QAAXMPAVidClipModel@@ABVidMat3@@HPBVidEntity@@_N@Z
// EA  : 0x82EDDE58
// RVA : 0x00EDDE58
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::Test(
        idTrajectory_Parabolic *this,
        double timeStep,
        idClipModel *clipModel,
        idClipModel *modelAxis,
        idMat3 *clipMask,
        const idEntity *ignoreEnt,
        int deferred,
        unsigned __int8 a8)
{
  int v8; // r23
  int v15; // r27
  idStaticList<idClipQuery,32> **queries; // r28
  __int64 v17; // r9
  char *v18; // r3
  _QWORD *v19; // r11
  int i; // ctr
  double v21; // fp9
  unsigned __int8 v22; // r11
  int v23; // r14
  int v24; // r17
  idList<idClipQuery,5> **v25; // r26
  int *p_impactSteps; // r30
  idTrajectory_Parabolic::parabolicParms_t *parms; // r25
  double v28; // fp30
  double v29; // fp0
  int v30; // r27
  float x; // r11
  float y; // r10
  double speed; // fp11
  float z; // r9
  double yaw; // fp9
  int v36; // r28
  double roll; // fp8
  double v38; // fp27
  double v39; // fp26
  double v40; // fp31
  double v41; // fp12
  double v42; // fp13
  double v43; // fp0
  double gravity; // fp10
  int v45; // r4
  double v46; // fp0
  double v47; // fp13
  double v48; // fp12
  double v49; // fp11
  int v50; // [sp+8h] [-258h]
  bool v51; // [sp+Fh] [-251h]
  const char *v52; // [sp+10h] [-250h]
  int v53; // [sp+14h] [-24Ch]
  int v54; // [sp+18h] [-248h]
  int v55; // [sp+1Ch] [-244h]
  int v56; // [sp+20h] [-240h]
  int v57; // [sp+24h] [-23Ch]
  int v58; // [sp+28h] [-238h]
  int v59; // [sp+2Ch] [-234h]
  int v60; // [sp+30h] [-230h]
  int v61; // [sp+34h] [-22Ch]
  int v62; // [sp+38h] [-228h]
  int v63; // [sp+3Ch] [-224h]
  int v64; // [sp+40h] [-220h]
  int v65; // [sp+44h] [-21Ch]
  int v66; // [sp+48h] [-218h]
  int v67; // [sp+4Ch] [-214h]
  int v68; // [sp+50h] [-210h]
  int v69; // [sp+58h] [-208h]
  int v70; // [sp+60h] [-200h]
  idVec3 v71; // [sp+70h] [-1F0h] BYREF
  idVec3 v72; // [sp+80h] [-1E0h] BYREF
  int v73; // [sp+8Ch] [-1D4h]
  idAngles v74; // [sp+90h] [-1D0h] BYREF
  idAngles v75; // [sp+A0h] [-1C0h] BYREF
  int v77; // [sp+B4h] [-1ACh]
  idClipQuery v78; // [sp+B8h] [-1A8h] BYREF
  idVec3 v79; // [sp+C0h] [-1A0h] BYREF
  char v80; // [sp+D0h] [-190h] BYREF
  trace_t v81; // [sp+E0h] [-180h] BYREF

  v8 = a8;
  v73 = a8;
  if ( a8 != 0 )
  {
    v15 = 0;
    if ( this->numTrajectories > 0 )
    {
      queries = this->queries;
      do
      {
        if ( *queries == nullptr )
        {
          v18 = (char *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x110u,
                          tag: TAG_COLLISION,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
          if ( v18 != nullptr )
          {
            *((_DWORD *)v18 + 2) = 32;
            *((_DWORD *)v18 + 1) = 0;
            *((_WORD *)v18 + 6) = 1;
            *(_DWORD *)v18 = v18 + 16;
            v19 = v18 + 8;
            v18[15] = 1;
            LODWORD(v17) = 0;
            v18[14] = 5;
            for ( i = 32; i != 0; --i )
              *++v19 = v17;
          }
          else
          {
            v18 = nullptr;
          }
          *queries = (idStaticList<idClipQuery,32> *)v18;
        }
        ++v15;
        ++queries;
      }
      while ( v15 < this->numTrajectories );
    }
  }
  idTrajectory_Parabolic::Clear(this);
  v21 = (float)(this->dest.y - this->start.y);
  v75.pitch = this->dest.x - this->start.x;
  v75.roll = 0.0;
  v75.yaw = v21;
  idVec3::ToAngles(this: &v79, result: &v75);
  if ( g_showTrajectories.valueInteger == 0 || (v22 = 1, v8 != 0) )
    v22 = 0;
  v23 = v22;
  if ( v22 != 0 )
  {
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: &this->start,
      a4: 5000,
      a5: true);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: &this->dest,
      a4: 5000,
      a5: true);
  }
  v24 = 0;
  if ( this->numTrajectories <= 0 )
    return;
  v25 = this->queries;
  p_impactSteps = &this->results[0].impactSteps;
  parms = this->parms;
  do
  {
    v28 = timeStep;
    v29 = (float)((float)((float)1.0 / (float)timeStep) * parms->time);
    if ( v73 != 0 && v29 >= 32.0 )
    {
      v28 = (float)(parms->time * (float)0.03125);
      v29 = 32.0;
    }
    else if ( (float)((float)((float)((float)1.0 / (float)timeStep) * parms->time) - (float)__fabs(v29)) != 0.0 )
    {
      v29 = (float)((float)((float)((float)1.0 / (float)timeStep) * parms->time) + (float)1.0);
    }
    v79.x = parms->angle;
    v77 = (int)v29;
    v30 = (int)v29;
    idAngles::ToForward(this: &v74, result: &v79);
    x = this->start.x;
    y = this->start.y;
    speed = parms->speed;
    z = this->start.z;
    yaw = v74.yaw;
    v36 = 0;
    roll = v74.roll;
    v38 = (float)(v74.pitch * parms->speed);
    *p_impactSteps = -1;
    v39 = (float)((float)yaw * (float)speed);
    v71.x = x;
    v40 = (float)((float)roll * (float)speed);
    v71.y = y;
    v71.z = z;
    *((_BYTE *)p_impactSteps - 4) = 0;
    p_impactSteps[1] = v30;
    if ( v30 <= 0 )
    {
LABEL_36:
      if ( v23 != 0 )
        clientGame->renderWorld->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorLtGrey,
          a3: &v72,
          a4: 5000,
          a5: true);
      goto LABEL_38;
    }
    v41 = v71.z;
    v42 = v71.y;
    v43 = v71.x;
    while ( 1 )
    {
      gravity = parms->gravity;
      v45 = *(_DWORD *)(deferred + 492);
      v72.x = (float)((float)v38 * (float)v28) + (float)v43;
      v72.y = (float)v42 + (float)((float)v39 * (float)v28);
      v72.z = (float)v41 + (float)((float)v40 * (float)v28);
      v40 = (float)-(float)((float)((float)gravity * (float)v28) - (float)v40);
      if ( v73 == 0 )
        break;
      idClip::Translation(
        this: (idClip *)&v78,
        result: &clientGame->clip,
        a3: nullptr,
        start: &v71,
        end: &v72,
        clipModel: modelAxis,
        startAxis: clipMask,
        clipMask: (int)ignoreEnt,
        passEntityNumber: v50,
        moveClipModel: v51,
        userName: v52,
        a12: v53,
        a13: v54,
        a14: v55,
        a15: v56,
        a16: v57,
        a17: v58,
        a18: v59,
        a19: v60,
        a20: v61,
        a21: v62,
        a22: v63,
        a23: v64,
        a24: v65,
        a25: v66,
        a26: v67,
        a27: v68,
        a28: v45,
        a29: v69,
        a30: false,
        a31: v70,
        a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\Trajectory.cpp(195) : Translation");
      idList<idClipQuery,5>::Append(this: *v25, obj: &v78);
LABEL_32:
      ++v36;
      v43 = v72.x;
      v42 = v72.y;
      v41 = v72.z;
      v71.x = v72.x;
      v71.y = v72.y;
      v71.z = v72.z;
      if ( v36 >= v30 )
        goto LABEL_36;
    }
    idClip::Translation(
      this: (idClip *)&v80,
      result: &clientGame->clip,
      a3: &v81,
      start: &v71,
      end: &v72,
      clipModel: modelAxis,
      startAxis: clipMask,
      clipMask: (int)ignoreEnt,
      passEntityNumber: v50,
      moveClipModel: v51,
      userName: v52,
      a12: v53,
      a13: v54,
      a14: v55,
      a15: v56,
      a16: v57,
      a17: v58,
      a18: v59,
      a19: v60,
      a20: v61,
      a21: v62,
      a22: v63,
      a23: v64,
      a24: v65,
      a25: v66,
      a26: v67,
      a27: v68,
      a28: v45,
      a29: v69,
      a30: false,
      a31: v70,
      a32: 0);
    if ( v81.fraction >= 1.0 )
    {
      if ( v23 != 0 )
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorLtGrey,
          a3: &v71,
          a4: &v72,
          a5: 5000,
          a6: true);
      *p_impactSteps = v36;
      goto LABEL_32;
    }
    v46 = (float)(v81.fraction * (float)v28);
    v47 = v71.x;
    v48 = v71.y;
    v49 = v71.z;
    *((_BYTE *)p_impactSteps - 4) = 1;
    v72.x = (float)((float)v46 * (float)v38) + (float)v47;
    v72.y = (float)((float)v39 * (float)v46) + (float)v48;
    v72.z = (float)((float)v46 * (float)v40) + (float)v49;
    trace_t::operator=(this: (trace_t *)(p_impactSteps - 33), __that: &v81);
    if ( v23 != 0 )
    {
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorLtGrey,
        a3: &v71,
        a4: &v72,
        a5: 5000,
        a6: true);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &v72,
        a4: 5000,
        a5: true);
      goto LABEL_36;
    }
LABEL_38:
    ++v24;
    ++parms;
    ++v25;
    p_impactSteps += 35;
  }
  while ( v24 < this->numTrajectories );
}


// ========================================================================
// ?UpdateDeferredQueries@idTrajectory_Parabolic@@QAAX_N@Z
// EA  : 0x82EDE340
// RVA : 0x00EDE340
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::UpdateDeferredQueries(idTrajectory_Parabolic *this, const bool draw)
{
  unsigned __int64 v2; // r20
  int numTrajectories; // r11
  int v5; // r21
  int v6; // r23
  idTrajectory_Parabolic::parabolicResults_t *results; // r27
  idStaticList<idClipQuery,32> **queries; // r24
  idStaticList<idClipQuery,32> *v9; // r28
  double y; // fp13
  int v11; // r29
  double z; // fp12
  int v13; // r31
  idClientGame *v14; // r10
  unsigned __int64 index; // r9
  double fraction; // fp0
  idTrajectory_Parabolic::parabolicResults_t *v17; // r28
  idStaticList<idClipQuery,32> **v18; // r27
  int v19; // r30
  int v20; // r29
  unsigned __int64 v21; // r11
  unsigned int v22; // r11
  char v23; // r11
  bool v24; // zf
  __int64 v25; // r11
  idClientGame *v26; // r9
  double v27; // fp0
  int v28; // r28
  int *p_impactSteps; // r30
  idStaticList<idClipQuery,32> **v30; // r29
  idStaticList<idClipQuery,32> *v31; // r31
  int v32; // r11
  int v33; // r10
  trace_t v34; // [sp+50h] [-200h] BYREF
  trace_t v35; // [sp+D0h] [-180h] BYREF
  trace_t v36; // [sp+150h] [-100h] BYREF

  LODWORD(v2) = 0;
  numTrajectories = this->numTrajectories;
  v5 = 0;
  if ( draw )
  {
    v6 = 0;
    if ( numTrajectories > 0 )
    {
      results = this->results;
      queries = this->queries;
      do
      {
        v9 = *queries;
        if ( *queries != nullptr && v9->num > 0 )
        {
          ++v5;
          y = this->start.y;
          v11 = 0;
          z = this->start.z;
          v35.endpos.x = this->start.x;
          v35.endpos.y = y;
          v35.endpos.z = z;
          if ( v9->num > 0 )
          {
            v13 = 0;
            while ( 1 )
            {
              v14 = clientGame;
              index = v9->list[v13].index;
              v9->list[v13].index = v2;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v34,
                query: &v14->clip.collisionQueries[index & 0xFFF].query,
                peek: false);
              clientGame->renderWorld->DebugLine(
                this: clientGame->renderWorld,
                a2: (const idVec4 *)&idColor::colorLtGrey,
                a3: &v35.endpos,
                a4: &v34.endpos,
                a5: 5000,
                a6: true);
              fraction = v34.fraction;
              results->impactSteps = v11;
              if ( fraction < 1.0 )
                break;
              trace_t::operator=(this: &v35, __that: &v34);
              ++v11;
              ++v13;
              if ( v11 >= v9->num )
                goto LABEL_12;
            }
            clientGame->renderWorld->DebugPoint(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorRed,
              a3: &v34.endpos,
              a4: 5000,
              a5: true);
            trace_t::operator=(this: &results->impactResult, __that: &v34);
          }
        }
LABEL_12:
        ++v6;
        ++queries;
        ++results;
      }
      while ( v6 < this->numTrajectories );
      if ( v5 > 0 )
      {
        clientGame->renderWorld->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: &this->start,
          a4: 5000,
          a5: true);
        clientGame->renderWorld->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: &this->dest,
          a4: 5000,
          a5: true);
      }
    }
  }
  else if ( numTrajectories > 0 )
  {
    v17 = this->results;
    v18 = this->queries;
    HIDWORD(v2) = &idDeclReachIK::resourceList.hashTable[243];
    do
    {
      if ( *v18 != nullptr )
      {
        v19 = 0;
        if ( (*v18)->num > 0 )
        {
          v20 = 0;
          while ( 1 )
          {
            v21 = (*v18)->list[v20].index;
            if ( (unsigned int)v21 < LODWORD(clientGame->clip.collisionQueryFirstSubmittedIndex)
              || (unsigned int)v21 > LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
            {
              v23 = 0;
            }
            else
            {
              v22 = *((_DWORD *)&clientGame->clip.collisionQueries[0].query.offset
                    + 2 * (v21 & 0xFFF)
                    + 2 * ((2 * v21) & 0x1FFE)
                    + 1);
              if ( v22 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
                || (v24 = v22 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v23 = 1, !v24) )
              {
                v23 = 0;
              }
            }
            if ( v23 != 0 )
            {
              v25 = *(_QWORD *)HIDWORD(v21);
              v26 = clientGame;
              *(_QWORD *)HIDWORD(v25) = v2;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v36,
                query: &v26->clip.collisionQueries[v25 & 0xFFF].query,
                peek: false);
              v27 = v36.fraction;
              v17->impactSteps = v19;
              if ( v27 < 1.0 )
                break;
            }
            ++v19;
            ++v20;
            if ( v19 >= (*v18)->num )
              goto LABEL_32;
          }
          trace_t::operator=(this: &v17->impactResult, __that: &v36);
        }
      }
LABEL_32:
      ++v5;
      ++v18;
      ++v17;
    }
    while ( v5 < this->numTrajectories );
  }
  v28 = 0;
  if ( this->numTrajectories > 0 )
  {
    p_impactSteps = &this->results[0].impactSteps;
    v30 = this->queries;
    do
    {
      v31 = *v30;
      if ( *v30 != nullptr && v31->num > 0 )
      {
        v32 = *p_impactSteps + 1;
        if ( v32 < v31->num )
        {
          v33 = v32;
          do
          {
            ++v32;
            v31->list[v33++].index = v2;
          }
          while ( v32 < v31->num );
        }
        if ( v31->size < 0 )
        {
          if ( v31->listStatic == 0 || v31->listStatic == 2 )
          {
            if ( v31->list != nullptr )
              idMem::Free(this: &mem, ptr: v31->list, align: ALIGN_16);
            v31->list = nullptr;
            v31->size = 0;
          }
          v31->num = 0;
        }
        v31->num = __CFADD__(-v31->size, v31->size ^ 0x80000000) ? 0 : v31->size;
      }
      ++v28;
      ++v30;
      p_impactSteps += 35;
    }
    while ( v28 < this->numTrajectories );
  }
}


// ========================================================================
// ??1idTrajectory_Parabolic@@UAA@XZ
// EA  : 0x82EDE790
// RVA : 0x00EDE790
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __fastcall idTrajectory_Parabolic::~idTrajectory_Parabolic(idTrajectory_Parabolic *this)
{
  this->__vftable = (idTrajectory_Parabolic_vtbl *)&idTrajectory_Parabolic::`vftable';
  idTrajectory_Parabolic::Free(this);
  this->__vftable = (idTrajectory_Parabolic_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$489728_0
// EA  : 0x82EDE7E4
// RVA : 0x00EDE7E4
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void _unwind_489728_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'g_showTrajectories''
// EA  : 0x83393CC0
// RVA : 0x01393CC0
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showTrajectories__()
{
  idCVar::idCVar(
    this: &g_showTrajectories,
    name: "g_showTrajectories",
    value: "0",
    flags: 1,
    description: "1 = show projectile trajectory tests.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showTrajectories__);
}


// ========================================================================
// `dynamic initializer for 'g_showTrajectoryTime''
// EA  : 0x83393D18
// RVA : 0x01393D18
// PDB : w:\tech5\tungsten\game\weapons\trajectory.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showTrajectoryTime__()
{
  idCVar::idCVar(
    this: &g_showTrajectoryTime,
    name: "g_showTrajectoryTime",
    value: "5000",
    flags: 2,
    description: "how long in MS to display the trajectories",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showTrajectoryTime__);
}

