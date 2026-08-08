
// ========================================================================
// CollisionMergeJob
// EA  : 0x825DCA48
// RVA : 0x005DCA48
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall CollisionMergeJob(modelQuery_t *mq)
{
  const queryResults_t *v2; // [sp+8h] [-68h]

  idCollisionDetectionMerge::MergeQueryResults(
    finalResult: mq->finalResultsPtr,
    resultSize: mq->resultSize,
    type: mq->type,
    mergeResults: mq->mergeResults,
    numMergeResults: mq->numMergeResults,
    slideMoveState: mq->slideMoveState,
    dependencyType: mq->dependencyType,
    dependency1: mq->dependency1,
    dependency2: v2);
  mq->finalResultsPtr->query.mergeThreadId = 0;
}


// ========================================================================
// ?Shutdown@idCollisionQueryJobManager@@QAAXXZ
// EA  : 0x825DCAA8
// RVA : 0x005DCAA8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::Shutdown(idCollisionQueryJobManager *this)
{
  queryResults_t *dummyQueryResults; // r4

  idMem::Free(this: &mem, ptr: this->queryData, align: ALIGN_128);
  dummyQueryResults = this->dummyQueryResults;
  this->queryData = nullptr;
  idMem::Free(this: &mem, ptr: dummyQueryResults, align: ALIGN_128);
  this->dummyQueryResults = nullptr;
  idMem::Free(this: &mem, ptr: this->jobGroups, align: ALIGN_16);
  this->jobGroups = nullptr;
  parallelJobManager->FreeJobList(this: parallelJobManager, a2: this->jobList);
}


// ========================================================================
// ?WaitForQueryResults@idCollisionQueryJobManager@@AAA_NPAUqueryResults_t@@@Z
// EA  : 0x825DCB28
// RVA : 0x005DCB28
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

int __fastcall idCollisionQueryJobManager::WaitForQueryResults(
        idCollisionQueryJobManager *this,
        queryResults_t *results)
{
  int result; // r3
  unsigned __int64 firstWaitTime; // r10
  unsigned __int64 v6; // r3

  result = 0;
  if ( results->query.merged == 0 )
  {
    do
    {
      firstWaitTime = this->firstWaitTime;
      this->stalledFrameNumber = this->queryFrameNumber;
      if ( (_DWORD)firstWaitTime == 0 )
      {
        LODWORD(v6) = Sys_Microseconds() >> 32;
        this->firstWaitTime = v6;
      }
      Sys_Yield();
    }
    while ( results->query.merged == 0 );
    return 1;
  }
  return result;
}


// ========================================================================
// ?WaitForAllQueries@idCollisionQueryJobManager@@QAAXXZ
// EA  : 0x825DCB88
// RVA : 0x005DCB88
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::WaitForAllQueries(idCollisionQueryJobManager *this)
{
  unsigned __int64 v2; // r6

  idParallelJobList::Wait(this: this->jobList);
  idQueryData::ReleaseQueryOnlyData(this: this->queryData, a2: v2);
}


// ========================================================================
// ?Init@idCollisionQueryJobManager@@QAAXXZ
// EA  : 0x825DD1B0
// RVA : 0x005DD1B0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::Init(idCollisionQueryJobManager *this)
{
  idQueryData *v2; // r3
  int v3; // r9
  signed int v4; // r30
  _DWORD *v5; // r10
  int v6; // r11
  queryResults_t *v7; // r3
  _DWORD v8[24]; // [sp+50h] [-60h] BYREF

  cm_useJobs.flags &= ~0x20000u;
  v2 = (idQueryData *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\cm\\CollisionQueryJobManager.cpp(166) : TAG_COLLISION_QUERY",
                        size: 0x2458E0u,
                        tag: TAG_COLLISION_QUERY,
                        zeroBuffer: false,
                        align: ALIGN_128,
                        heap: HEAP_DEFAULTHEAP);
  this->queryData = v2;
  idQueryData::Clear(this: v2);
  v3 = 9;
  v8[5] = 8;
  v8[8] = 9;
  v8[0] = 1;
  v8[1] = 2;
  v8[2] = 3;
  v8[3] = 4;
  v8[4] = 7;
  v8[6] = 5;
  v4 = 0;
  v8[7] = 6;
  v5 = v8;
  do
  {
    if ( (unsigned int)(*v5 - 1) > 8 )
    {
      v6 = 0;
    }
    else if ( *v5 == 2 || *v5 == 3 || *v5 == 4 || *v5 == 5 || *v5 == 6 || *v5 == 1 )
    {
      v6 = 192;
    }
    else
    {
      v6 = 992;
    }
    if ( v6 > v4 )
      v4 = v6;
    --v3;
    ++v5;
  }
  while ( v3 != 0 );
  v7 = (queryResults_t *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\cm\\CollisionQueryJobManager.cpp(187) : TAG_COLLISION_QUERY",
                           size: v4,
                           tag: TAG_COLLISION_QUERY,
                           zeroBuffer: false,
                           align: ALIGN_128,
                           heap: HEAP_DEFAULTHEAP);
  this->dummyQueryResults = v7;
  memset(Dst: v7, Val: 0, Size: v4);
  this->dummyQueryResults->query.done = 1;
  this->dummyQueryResults->query.merged = 1;
  this->dummyQueryResults->query.status = QUERY_STATUS_SUCCESS;
  this->queryFrameNumber = 0;
  this->stalledFrameNumber = 0;
  this->jobGroups = (jobGroup_t *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\cm\\CollisionQueryJobManager.cpp(196) : TAG_COLLISION_QUERY",
                                    size: 0x5FE8u,
                                    tag: TAG_COLLISION_QUERY,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  this->jobList = parallelJobManager->AllocJobList(
                    this: parallelJobManager,
                    a2: 0,
                    a3: 3,
                    a4: 4096,
                    a5: 256,
                    a6: &idColor::colorGreen);
}


// ========================================================================
// ?AllocModelQuery@idCollisionQueryJobManager@@AAAPAUmodelQuery_t@@ABVidPositionedCollisionModel@@@Z
// EA  : 0x825DD380
// RVA : 0x005DD380
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

modelQuery_t *__fastcall idCollisionQueryJobManager::AllocModelQuery(
        idCollisionQueryJobManager *this,
        const idPositionedCollisionModel *model)
{
  idCollisionModel *v3; // r28
  modelQuery_t *v5; // r30
  queryParms_t *Parms; // r3

  v3 = model->model;
  v5 = idQueryData::AllocModelQuery(this: this->queryData);
  Parms = idQueryData::AllocQueryParms(this: this->queryData);
  if ( v5 == nullptr || Parms == nullptr )
    return nullptr;
  v5->parms = Parms;
  v5->modelType = (cmType_t)v3[1].name.str;
  v5->polygonModel = (const cm_polygonModel_t *)&v3[2].nextOnHashChain;
  v5->sphereModel = *((const cm_sphereModel_t **)&v3[2].idResource + 8);
  v5->modelJoints = model->modelJoints;
  v5->mergeResults = this->dummyQueryResults;
  v5->resultsPtr = this->dummyQueryResults;
  v5->executePriority = 1023;
  v5->mergePriority = 1023;
  v5->frameNumber = this->queryFrameNumber;
  Parms->modelOrigin.x = model->modelOrigin.x;
  Parms->modelOrigin.y = model->modelOrigin.y;
  Parms->modelOrigin.z = model->modelOrigin.z;
  Parms->modelAxis.mat[0].x = model->modelAxis.mat[0].x;
  Parms->modelAxis.mat[0].y = model->modelAxis.mat[0].y;
  Parms->modelAxis.mat[0].z = model->modelAxis.mat[0].z;
  Parms->modelAxis.mat[1].x = model->modelAxis.mat[1].x;
  Parms->modelAxis.mat[1].y = model->modelAxis.mat[1].y;
  Parms->modelAxis.mat[1].z = model->modelAxis.mat[1].z;
  Parms->modelAxis.mat[2].x = model->modelAxis.mat[2].x;
  Parms->modelAxis.mat[2].y = model->modelAxis.mat[2].y;
  Parms->modelAxis.mat[2].z = model->modelAxis.mat[2].z;
  Parms->modelEntityNum = model->modelEntityNum;
  Parms->modelPhysicsId = model->modelPhysicsId;
  Parms->modelBodyId = model->modelBodyId;
  Parms->modelContentsOverride = model->modelContentsOverride;
  Parms->testQuery = cm_testQueries.valueInteger != 0;
  return v5;
}


// ========================================================================
// ?AllocFinishedFinalResult@idCollisionQueryJobManager@@AAA?AVidCollisionQuery@@W4traceType_t@@0ABVidVec3@@ABVidMat3@@PBD@Z
// EA  : 0x825DD4C0
// RVA : 0x005DD4C0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::AllocFinishedFinalResult(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        unsigned __int64 type2,
        const idVec3 *endpos,
        const idMat3 *endAxis,
        __int64 userName)
{
  __int64 v6; // r23
  traceType_t v8; // r21
  traceType_t v9; // r20
  __int64 v12; // r27
  traceType_t v13; // r29
  queryResults_t *v14; // r3
  int v15; // r10
  int v16; // r7
  _QWORD v18[3]; // [sp+50h] [-90h] BYREF

  LODWORD(v6) = 0;
  LODWORD(userName) = 1023;
  v18[0] = v6;
  HIDWORD(v6) = result;
  v18[1] = v6;
  v8 = HIDWORD(type2);
  v9 = (int)type2;
  v12 = userName << 54;
  while ( 1 )
  {
    v13 = v8;
    if ( HIDWORD(v12) != 0 )
      v13 = v9;
    if ( v13 == TRACE_INVALID )
    {
LABEL_19:
      *(_QWORD *)&this->queryData = v18[0];
      return this;
    }
    v14 = idQueryData::AllocFinalResult(this: *(idQueryData **)HIDWORD(v6), totalSize: type2);
    if ( v14 == nullptr )
      break;
    v15 = idCollisionQuery::finalResultsLastAllocedOffset;
    v14->query.type = v13;
    v16 = v15 | v12;
    v14->query.done = 1;
    v14->query.merged = 1;
    v14->query.status = QUERY_STATUS_SUCCESS;
    v18[HIDWORD(v12)] = *(unsigned __int64 *)((char *)&type2 - 4);
    if ( (unsigned int)(v13 - 1) <= 8 )
    {
      if ( v13 != TRACE_TRANSLATION_POINT
        && v13 != TRACE_ROTATION
        && v13 != TRACE_ROTATION_POINT
        && v13 != TRACE_CONTENTS
        && v13 != TRACE_CONTENTS_POINT )
      {
        if ( v13 == TRACE_CONTACTS_UNI_DIR || v13 == TRACE_CONTACTS_OMNI_DIR )
          goto LABEL_17;
        if ( v13 != TRACE_TRANSLATION )
        {
          *(_DWORD *)&v14->data[4] = 0;
LABEL_17:
          *(_DWORD *)v14->data = 0;
          goto LABEL_18;
        }
      }
      *(float *)v14->data = 1.0;
      *(float *)&v14->data[4] = endpos->x;
      *(float *)&v14->data[8] = endpos->y;
      *(float *)&v14->data[12] = endpos->z;
      *(float *)&v14->data[16] = endAxis->mat[0].x;
      *(float *)&v14->data[20] = endAxis->mat[0].y;
      *(float *)&v14->data[24] = endAxis->mat[0].z;
      *(float *)&v14->data[28] = endAxis->mat[1].x;
      *(float *)&v14->data[32] = endAxis->mat[1].y;
      *(float *)&v14->data[36] = endAxis->mat[1].z;
      *(float *)&v14->data[40] = endAxis->mat[2].x;
      *(float *)&v14->data[44] = endAxis->mat[2].y;
      *(float *)&v14->data[48] = endAxis->mat[2].z;
      memset(Dst: &v14->data[52], Val: 0, Size: 0x4Cu);
    }
LABEL_18:
    ++HIDWORD(v12);
    if ( SHIDWORD(v12) >= 2 )
      goto LABEL_19;
  }
  *(_QWORD *)&this->queryData = v6;
  return this;
}


// ========================================================================
// ?AddModelQueryToMergeList@idCollisionQueryJobManager@@AAA?AVidCollisionQuery@@PAUmodelQuery_t@@HPAUslideMoveState_t@@@Z
// EA  : 0x825DD698
// RVA : 0x005DD698
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::AddModelQueryToMergeList(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        unsigned __int64 mergePriority,
        slideMoveState_t *slideMoveState)
{
  _DWORD *v6; // r31
  int v7; // r28
  __int64 v8; // r27
  unsigned int v9; // r30
  queryResults_t *v10; // r3
  int v12; // r5
  __int64 v13; // r4
  int v14; // r8
  unsigned int v15; // r10
  __int64 v16; // r7
  signed int v17; // r4
  __int64 v18; // r9
  __int64 v19; // r7
  unsigned int v20; // r11
  int v21; // r11
  queryResults_t *v22; // r3

  v6 = (_DWORD *)HIDWORD(mergePriority);
  v7 = mergePriority;
  HIDWORD(v8) = slideMoveState;
  LODWORD(v8) = 0;
  if ( (unsigned int)(*(_DWORD *)HIDWORD(mergePriority) - 1) > 8 )
  {
    v9 = 0;
  }
  else if ( *(_DWORD *)HIDWORD(mergePriority) == 2
         || *(_DWORD *)HIDWORD(mergePriority) == 3
         || *(_DWORD *)HIDWORD(mergePriority) == 4
         || *(_DWORD *)HIDWORD(mergePriority) == 5
         || *(_DWORD *)HIDWORD(mergePriority) == 6
         || *(_DWORD *)HIDWORD(mergePriority) == 1 )
  {
    v9 = 192;
  }
  else
  {
    v9 = 992;
  }
  v10 = idQueryData::AllocFinalResult(this: (idQueryData *)HIDWORD(result->offset), totalSize: mergePriority);
  if ( v10 == nullptr )
    goto LABEL_12;
  v6[9] = v10;
  v12 = v6[24];
  v16 = *(_QWORD *)(HIDWORD(result->offset) + 2381976);
  v13 = *(_QWORD *)(HIDWORD(result->offset) + 2381952);
  v14 = v16;
  v15 = (v16 & 0xFFFFF) + HIDWORD(result->offset) + 808960;
  LODWORD(v16) = v13 - v16 + 1048448;
  if ( (int)v16 >= SHIDWORD(v16) )
    LODWORD(v16) = HIDWORD(v16);
  v17 = 0;
  HIDWORD(v18) = (v14 & 0xFFFFF) + v16 + HIDWORD(result->offset) + 808960;
  v19 = (unsigned int)v6;
  while ( *(_DWORD *)(v19 + 96) == v12 )
  {
    v20 = v9 + v15;
    *(_DWORD *)(v19 + 56) = v7;
    if ( v9 + v15 > HIDWORD(v18) )
      goto LABEL_18;
    if ( *(int *)(v19 + 48) <= 0 )
    {
      *(_DWORD *)(v19 + 32) = v15;
      v15 += v9;
      ++v17;
      goto LABEL_25;
    }
    LODWORD(v18) = *(_DWORD *)(v19 + 44);
    if ( (_DWORD)v18 != 0 )
    {
      while ( 1 )
      {
        *(_DWORD *)(v18 + 20) = v15;
        v15 = v20;
        v20 += v9;
        ++v17;
        if ( v20 > HIDWORD(v18) )
          break;
        LODWORD(v18) = *(_DWORD *)(v18 + 28);
        if ( (_DWORD)v18 == 0 )
          goto LABEL_25;
      }
LABEL_18:
      HIDWORD(v19) = 1;
    }
LABEL_25:
    LODWORD(v19) = *(_DWORD *)(v19 + 40);
    if ( (_DWORD)v19 == 0 )
      break;
  }
  if ( HIDWORD(v19) != 0 )
  {
    ++*(_DWORD *)(HIDWORD(result->offset) + 2382044);
    if ( v17 == 0 )
    {
LABEL_12:
      *(_QWORD *)&this->queryData = v8;
      return this;
    }
  }
  v6[20] = v9;
  v6[19] = v17;
  v6[17] = HIDWORD(v8);
  if ( v17 > 1 || v12 != 0 )
  {
    v22 = idQueryData::AllocIntermediateResults(
            this: (idQueryData *)HIDWORD(result->offset),
            numResults: v17,
            resultSize: v9);
    v6[8] = v22;
    v6[18] = v22;
    v6[16] = *(_DWORD *)(LODWORD(result[3].offset) + 24 * v7 + 12);
    HIDWORD(v18) = LODWORD(result[3].offset) + 24 * v7;
    *(_DWORD *)(HIDWORD(v18) + 12) = v6;
    ++*(_DWORD *)(LODWORD(result[3].offset) + 24 * v7 + 20);
  }
  else
  {
    *(_BYTE *)(v6[1] + 4) = 1;
    v21 = v6[11];
    v6[18] = HIDWORD(v13);
    v6[8] = HIDWORD(v13);
    if ( v21 != 0 )
      *(_DWORD *)(v21 + 20) = HIDWORD(v13);
  }
  LODWORD(v18) = HIDWORD(idCollisionQuery::finalResultsLastAllocedOffset)
               | idCollisionQuery::finalResultsLastAllocedOffset;
  *(_QWORD *)&this->queryData = v18;
  return this;
}


// ========================================================================
// ?CreateMergeJobs@idCollisionQueryJobManager@@AAAXPAVidParallelJobList@@PAUmodelQuery_t@@@Z
// EA  : 0x825DDA30
// RVA : 0x005DDA30
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::CreateMergeJobs(
        idCollisionQueryJobManager *this,
        idParallelJobList *jobList,
        modelQuery_t *mq)
{
  modelQuery_t *v4; // r31
  const queryResults_t *v5; // [sp+8h] [-68h]

  v4 = mq;
  if ( cm_useJobs.valueInteger == 1 )
  {
    if ( mq != nullptr )
    {
      do
      {
        if ( v4->mergePriority != 1023 )
          idParallelJobList::AddJob(this: jobList, function: (void (__fastcall *)(void *))CollisionMergeJob, data: v4);
        v4 = v4->nextInMergeList;
      }
      while ( v4 != nullptr );
    }
  }
  else if ( mq != nullptr )
  {
    do
    {
      if ( v4->mergePriority != 1023 )
      {
        idCollisionDetectionMerge::MergeQueryResults(
          finalResult: v4->finalResultsPtr,
          resultSize: v4->resultSize,
          type: v4->type,
          mergeResults: v4->mergeResults,
          numMergeResults: v4->numMergeResults,
          slideMoveState: v4->slideMoveState,
          dependencyType: v4->dependencyType,
          dependency1: v4->dependency1,
          dependency2: v5);
        v4->finalResultsPtr->query.mergeThreadId = 0;
      }
      v4 = v4->nextInMergeList;
    }
    while ( v4 != nullptr );
  }
}


// ========================================================================
// CollisionExecuteJob
// EA  : 0x825DDBF8
// RVA : 0x005DDBF8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall CollisionExecuteJob(modelQuery_t *mq)
{
  subModelQuery_t *subModelQueries; // r30
  int v3; // r12
  cmType_t modelType; // r11
  queryResults_t *dependency2; // r8
  queryResults_t *dependency1; // r7
  dependencyType_t dependencyType; // r6
  queryResults_t *modelPosition; // r5
  int v9; // r12
  _DWORD back_chain[20]; // [sp+0h] [-140h]
  queryParms_t v11; // [sp+50h] [-F0h] BYREF

  if ( mq->numSubModelQueries <= 0 )
  {
    modelType = mq->modelType;
    if ( modelType != CM_POLYGONMODEL )
    {
      if ( modelType == CM_SPHEREMODEL )
      {
        idCollisionQueryExecute::SetupDependentParms(
          resultParms: &v11,
          sourceParms: mq->parms,
          modelPosition: mq->modelPosition,
          dependencyType: (const dependencyType_t)mq->dependencyType,
          dependency1: mq->dependency1,
          dependency2: mq->dependency2);
        idCollisionQueryExecute::ExecuteSphereModelQuery(
          results: mq->resultsPtr,
          parms: &v11,
          modelJoints: mq->modelJoints,
          sphereModel: mq->sphereModel);
        mq->resultsPtr->query.executeThreadId = 0;
      }
    }
    else
    {
      idPolygonModelCollisionDetection::GetTraceWorkSPUSize();
      ((void (*)(void))RtlCheckStack12)();
      dependency2 = mq->dependency2;
      dependency1 = mq->dependency1;
      dependencyType = mq->dependencyType;
      modelPosition = mq->modelPosition;
      *(_DWORD *)((char *)back_chain + v9) = back_chain[0];
      idCollisionQueryExecute::SetupDependentParms(
        resultParms: &v11,
        sourceParms: mq->parms,
        modelPosition,
        dependencyType,
        dependency1,
        dependency2);
      idCollisionQueryExecute::ExecutePolygonModelQuery(
        tw: (idTraceWork *)&v11,
        results: mq->resultsPtr,
        parms: &v11,
        trm: mq->trm,
        polygonModel: mq->polygonModel);
      mq->resultsPtr->query.executeThreadId = 0;
    }
  }
  else
  {
    idPolygonModelCollisionDetection::GetTraceWorkSPUSize();
    ((void (*)(void))RtlCheckStack12)();
    subModelQueries = mq->subModelQueries;
    for ( *(_DWORD *)((char *)back_chain + v3) = back_chain[0];
          subModelQueries != nullptr;
          subModelQueries = subModelQueries->nextOnModelQuery )
    {
      idCollisionQueryExecute::SetupDependentParms(
        resultParms: &v11,
        sourceParms: subModelQueries->parms,
        modelPosition: mq->modelPosition,
        dependencyType: (const dependencyType_t)mq->dependencyType,
        dependency1: mq->dependency1,
        dependency2: mq->dependency2);
      idCollisionQueryExecute::ExecuteSubModelQuery(
        tw: (idTraceWork *)&v11,
        results: subModelQueries->resultsPtr,
        parms: &v11,
        trm: subModelQueries->trm,
        subModelData: subModelQueries->subModelData,
        subModelNum: subModelQueries->subModelNum);
      subModelQueries->resultsPtr->query.executeThreadId = 0;
    }
  }
}


// ========================================================================
// ??0idCollisionQueryJobManager@@QAA@XZ
// EA  : 0x825DDD78
// RVA : 0x005DDD78
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::idCollisionQueryJobManager(
        idCollisionQueryJobManager *this)
{
  int v1; // r29
  char *threadProfile; // r28

  v1 = 7;
  threadProfile = (char *)this->threadProfile;
  this->dummyQueryResults = nullptr;
  this->queryFrameNumber = 0;
  this->stalledFrameNumber = 0;
  this->firstWaitTime = 0x700000000LL;
  *(_QWORD *)&this->numJobGroups = 0;
  do
  {
    `vector constructor iterator'(
      __t: threadProfile,
      __s: 0x10u,
      __n: 5,
      __f: (void *(__fastcall *)(void *))timings_t::timings_t);
    --v1;
    threadProfile += 80;
  }
  while ( v1 >= 0 );
  *(_QWORD *)&this->translationProfile.timings[0].max = 0;
  this->translationProfile.timings[0].min = -1;
  this->translationProfile.timings[0].count = 0;
  this->translationProfile.timings[1].min = -1;
  *(_QWORD *)&this->translationProfile.timings[1].max = 0;
  this->translationProfile.timings[1].count = 0;
  this->translationProfile.timings[2].min = -1;
  *(_QWORD *)&this->translationProfile.timings[2].max = 0;
  this->translationProfile.timings[2].count = 0;
  this->translationProfile.timings[3].min = -1;
  *(_QWORD *)&this->translationProfile.timings[3].max = 0;
  this->translationProfile.timings[3].count = 0;
  this->translationProfile.timings[4].min = -1;
  *(_QWORD *)&this->translationProfile.timings[4].max = 0;
  this->translationProfile.timings[4].count = 0;
  this->rotationProfile.timings[0].min = -1;
  *(_QWORD *)&this->rotationProfile.timings[0].max = 0;
  this->rotationProfile.timings[0].count = 0;
  this->rotationProfile.timings[1].min = -1;
  *(_QWORD *)&this->rotationProfile.timings[1].max = 0;
  this->rotationProfile.timings[1].count = 0;
  this->rotationProfile.timings[2].min = -1;
  *(_QWORD *)&this->rotationProfile.timings[2].max = 0;
  this->rotationProfile.timings[2].count = 0;
  this->rotationProfile.timings[3].min = -1;
  *(_QWORD *)&this->rotationProfile.timings[3].max = 0;
  this->rotationProfile.timings[3].count = 0;
  this->rotationProfile.timings[4].min = -1;
  *(_QWORD *)&this->rotationProfile.timings[4].max = 0;
  this->rotationProfile.timings[4].count = 0;
  this->contentsProfile.timings[0].min = -1;
  *(_QWORD *)&this->contentsProfile.timings[0].max = 0;
  this->contentsProfile.timings[0].count = 0;
  this->contentsProfile.timings[1].min = -1;
  *(_QWORD *)&this->contentsProfile.timings[1].max = 0;
  this->contentsProfile.timings[1].count = 0;
  this->contentsProfile.timings[2].min = -1;
  *(_QWORD *)&this->contentsProfile.timings[2].max = 0;
  this->contentsProfile.timings[2].count = 0;
  this->contentsProfile.timings[3].min = -1;
  *(_QWORD *)&this->contentsProfile.timings[3].max = 0;
  this->contentsProfile.timings[3].count = 0;
  this->contentsProfile.timings[4].min = -1;
  *(_QWORD *)&this->contentsProfile.timings[4].max = 0;
  this->contentsProfile.timings[4].count = 0;
  this->contactsProfile.timings[0].min = -1;
  *(_QWORD *)&this->contactsProfile.timings[0].max = 0;
  this->contactsProfile.timings[0].count = 0;
  this->contactsProfile.timings[1].min = -1;
  *(_QWORD *)&this->contactsProfile.timings[1].max = 0;
  this->contactsProfile.timings[1].count = 0;
  this->contactsProfile.timings[2].min = -1;
  *(_QWORD *)&this->contactsProfile.timings[2].max = 0;
  this->contactsProfile.timings[2].count = 0;
  this->contactsProfile.timings[3].min = -1;
  *(_QWORD *)&this->contactsProfile.timings[3].max = 0;
  this->contactsProfile.timings[3].count = 0;
  this->contactsProfile.timings[4].min = -1;
  *(_QWORD *)&this->contactsProfile.timings[4].max = 0;
  this->contactsProfile.timings[4].count = 0;
  this->clipProfile.timings[0].min = -1;
  *(_QWORD *)&this->clipProfile.timings[0].max = 0;
  this->clipProfile.timings[0].count = 0;
  this->clipProfile.timings[1].min = -1;
  *(_QWORD *)&this->clipProfile.timings[1].max = 0;
  this->clipProfile.timings[1].count = 0;
  this->clipProfile.timings[2].min = -1;
  *(_QWORD *)&this->clipProfile.timings[2].max = 0;
  this->clipProfile.timings[2].count = 0;
  this->clipProfile.timings[3].min = -1;
  *(_QWORD *)&this->clipProfile.timings[3].max = 0;
  this->clipProfile.timings[3].count = 0;
  this->clipProfile.timings[4].min = -1;
  *(_QWORD *)&this->clipProfile.timings[4].max = 0;
  this->clipProfile.timings[4].count = 0;
  this->failedQuery.valid = false;
  return this;
}


// ========================================================================
// ?AddModelQueryToExecuteList@idCollisionQueryJobManager@@AAAXPAUmodelQuery_t@@VidCollisionQuery@@11W4dependencyType_t@@ABVidVec3@@3ABVidBounds@@AAH@Z
// EA  : 0x825DDF78
// RVA : 0x005DDF78
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCollisionQueryJobManager::AddModelQueryToExecuteList(
        idCollisionQueryJobManager *this,
        modelQuery_t *modelQuery,
        unsigned __int64 dependency1,
        unsigned int dependency2,
        dependencyType_t dependencyType,
        const idVec3 *globalStart,
        const idVec3 *globalEnd,
        const idBounds *globalBounds,
        int *mergePriority,
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
        const idBounds *a27,
        int a28,
        int *a29)
{
  int v29; // r4
  int v30; // r30
  unsigned __int64 v32; // r11
  int v33; // r31
  unsigned int v34; // r3
  char v35; // r4
  char *v36; // r4
  int v37; // r4
  char v38; // r11
  int v39; // ctr
  int *p_numJobs; // r11
  int SubModelsForTrace; // r26
  double v42; // fp11
  double v43; // fp10
  double v44; // fp5
  double v45; // fp4
  double v46; // fp9
  double v47; // fp2
  double v48; // fp31
  double v49; // fp6
  double v50; // fp3
  double v51; // fp0
  double v52; // fp11
  double v53; // fp10
  double v54; // fp6
  double v55; // fp3
  double v56; // fp1
  int v57; // r29
  int *v58; // r28
  subModelQuery_t *v59; // r3
  subModelQuery_t *v60; // r31
  const cm_subModel_t *v61; // r3
  queryResults_t *dummyQueryResults; // r7
  idVec3 v63; // [sp+50h] [-270h] BYREF
  idVec3 v64; // [sp+60h] [-260h] BYREF
  idVec3 v65; // [sp+70h] [-250h] BYREF
  int v66; // [sp+7Ch] [-244h] BYREF
  int v67[128]; // [sp+80h] [-240h] BYREF

  v30 = v29;
  v32 = idCollisionQuery::finalResultsLastSubmittedOffset;
  v33 = 0;
  v34 = idCollisionQuery::finalResultsLastAllocedOffset;
  if ( HIDWORD(dependency1) < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset
    || (v35 = 1, HIDWORD(dependency1) > (unsigned int)idCollisionQuery::finalResultsLastAllocedOffset) )
  {
    v35 = 0;
  }
  if ( v35 != 0 )
  {
    v36 = (char *)this->queryData + (HIDWORD(dependency1) & 0x7FFFF);
    if ( *(unsigned __int64 *)((char *)&dependency1 + 4) >> 54 != 1023 )
      v33 = (*(unsigned __int64 *)((char *)&dependency1 + 4) >> 54) + 1;
    *(_DWORD *)(v30 + 84) = v37 + 1857536;
    v32 = idCollisionQuery::finalResultsLastSubmittedOffset;
    v34 = idCollisionQuery::finalResultsLastAllocedOffset;
  }
  if ( (unsigned int)dependency1 < (unsigned int)v32 || (BYTE3(dependency1) = 1, (unsigned int)dependency1 > v34) )
    BYTE3(dependency1) = 0;
  HIDWORD(dependency1) = BYTE3(dependency1);
  if ( BYTE3(dependency1) != 0 )
  {
    if ( dependency1 >> 54 != 1023 && (int)((dependency1 >> 54) + 1) > v33 )
      v33 = (dependency1 >> 54) + 1;
    *(_DWORD *)(v30 + 88) = &this->queryData->finalResults[dependency1 & 0x7FFFF];
    v32 = idCollisionQuery::finalResultsLastSubmittedOffset;
    v34 = idCollisionQuery::finalResultsLastAllocedOffset;
  }
  if ( dependency2 < (unsigned int)v32 || (v38 = 1, dependency2 > v34) )
    v38 = 0;
  if ( v38 != 0 )
    *(_DWORD *)(v30 + 92) = &this->queryData->finalResults[dependency2 & 0x7FFFF];
  if ( v33 >= 1023 )
    idLib::Error(fmt: "more than %d total collision dependencies", 1023);
  if ( v33 > *a29 )
    *a29 = v33;
  *(_DWORD *)(v30 + 96) = dependencyType;
  *(_DWORD *)(v30 + 52) = v33;
  if ( v33 >= this->numJobGroups )
  {
    v39 = 6;
    p_numJobs = &this->jobGroups[v33 - 1].numJobs;
    do
    {
      *++p_numJobs = 0;
      --v39;
    }
    while ( v39 != 0 );
    this->numJobGroups = v33 + 1;
  }
  *(_DWORD *)(v30 + 60) = this->jobGroups[v33].stallingExecuteJobs;
  this->jobGroups[v33].stallingExecuteJobs = (modelQuery_t *)v30;
  ++this->jobGroups[v33].numJobs;
  if ( cm_useSubModelQueries.valueInteger != 0 && *(_DWORD *)(v30 + 12) == 0 )
  {
    if ( *(int *)(*(_DWORD *)(v30 + 16) + 4) > 1 )
    {
      LODWORD(v32) = *(_DWORD *)(v30 + 4);
      v42 = *(float *)(HIDWORD(v32) + 4);
      v43 = *(float *)(HIDWORD(v32) + 8);
      v44 = (float)(globalStart->z - *(float *)(v32 + 132));
      v45 = (float)(globalStart->y - *(float *)(v32 + 128));
      v46 = *(float *)(v32 + 164);
      v47 = *(float *)(v32 + 144);
      v48 = *(float *)HIDWORD(v32);
      v49 = (float)((float)(*(float *)(v32 + 160) * (float)(globalStart->x - *(float *)(v32 + 124)))
                  + (float)(*(float *)(v32 + 168) * (float)(globalStart->z - *(float *)(v32 + 132))));
      v50 = (float)((float)((float)(globalStart->x - *(float *)(v32 + 124)) * *(float *)(v32 + 136))
                  + (float)(*(float *)(v32 + 140) * (float)(globalStart->y - *(float *)(v32 + 128))));
      v63.y = (float)((float)(globalStart->z - *(float *)(v32 + 132)) * *(float *)(v32 + 156))
            + (float)((float)(*(float *)(v32 + 152) * (float)(globalStart->y - *(float *)(v32 + 128)))
                    + (float)(*(float *)(v32 + 148) * (float)(globalStart->x - *(float *)(v32 + 124))));
      v63.z = (float)((float)v46 * (float)v45) + (float)v49;
      v63.x = (float)((float)v47 * (float)v44) + (float)v50;
      v51 = *(float *)(v32 + 136);
      v52 = (float)((float)v42 - *(float *)(v32 + 128));
      v53 = (float)((float)v43 - *(float *)(v32 + 132));
      v54 = (float)((float)v48 - *(float *)(v32 + 124));
      v55 = (float)((float)(*(float *)(v32 + 144) * (float)v53) + (float)(*(float *)(v32 + 140) * (float)v52));
      v56 = (float)((float)(*(float *)(v32 + 148) * (float)((float)v48 - *(float *)(v32 + 124)))
                  + (float)((float)((float)v53 * *(float *)(v32 + 156)) + (float)(*(float *)(v32 + 152) * (float)v52)));
      v64.z = (float)(*(float *)(v32 + 160) * (float)((float)v48 - *(float *)(v32 + 124)))
            + (float)((float)(*(float *)(v32 + 168) * (float)v53) + (float)(*(float *)(v32 + 164) * (float)v52));
      v64.y = v56;
      v64.x = (float)((float)v54 * (float)v51) + (float)v55;
      idPolygonModelCollisionDetection::LocalExtentsFromUnTransformedBounds(
        result: &v65,
        globalBounds: a27,
        globalStart,
        globalEnd: (const idVec3 *)HIDWORD(v32),
        modelAxis: (const idMat3 *)(v32 + 136));
      SubModelsForTrace = idPolygonModelCollisionDetection::GetSubModelsForTrace(
                            model: *(const cm_polygonModel_t **)(v30 + 16),
                            start: &v63,
                            end: &v64,
                            extents: &v65,
                            subModelNums: v67);
    }
    else
    {
      SubModelsForTrace = 1;
      v67[0] = 0;
    }
    v57 = 0;
    *(_DWORD *)(v30 + 48) = SubModelsForTrace;
    if ( SubModelsForTrace > 0 )
    {
      v58 = &v66;
      while ( 1 )
      {
        v59 = idQueryData::AllocSubModelQuery(this: this->queryData);
        v60 = v59;
        if ( v59 == nullptr )
          break;
        v59->parms = *(queryParms_t **)(v30 + 4);
        v59->trm = *(const idTraceModel **)(v30 + 8);
        v61 = (const cm_subModel_t *)(48 * v58[1] + *(_DWORD *)(*(_DWORD *)(v30 + 16) + 12));
        v60->subModel = v61;
        v60->subModelData = AcquireSubModelData(subModel: v61);
        ++v58;
        ++v57;
        v60->subModelNum = *v58;
        dummyQueryResults = this->dummyQueryResults;
        v60->modelQuery = (modelQuery_t *)v30;
        v60->resultsPtr = dummyQueryResults;
        v60->nextOnModelQuery = *(subModelQuery_t **)(v30 + 44);
        *(_DWORD *)(v30 + 44) = v60;
        if ( v57 >= SubModelsForTrace )
          return;
      }
      *(_DWORD *)(v30 + 48) = v57;
    }
  }
}


// ========================================================================
// ?SubmitTranslationQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@0ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DE360
// RVA : 0x005DE360
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitTranslationQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idVec3 *end,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        __int64 trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        const char *a33)
{
  int v38; // r17
  float *v39; // r31
  __int64 v41; // r14
  modelQuery_t *v42; // r25
  int v43; // r23
  int v45; // r27
  const idPositionedCollisionModel *v46; // r28
  modelQuery_t *v47; // r3
  _DWORD *parms; // r10
  int v49; // r11
  float *v50; // r11
  float *v51; // r11
  float *v52; // r11
  float *v53; // r11
  float *v54; // r11
  double radius; // fp0
  float *v56; // r11
  __int128 v57; // r6
  const idBounds *v58; // [sp+8h] [-108h]
  int *v59; // [sp+Ch] [-104h]
  int v60; // [sp+10h] [-100h]
  int v61; // [sp+14h] [-FCh]
  int v62; // [sp+18h] [-F8h]
  int v63; // [sp+1Ch] [-F4h]
  int v64; // [sp+20h] [-F0h]
  int v65; // [sp+24h] [-ECh]
  int v66; // [sp+28h] [-E8h]
  int v67; // [sp+2Ch] [-E4h]
  int v68; // [sp+30h] [-E0h]
  int v69; // [sp+34h] [-DCh]
  int v70; // [sp+38h] [-D8h]
  int v71; // [sp+3Ch] [-D4h]
  int v72; // [sp+40h] [-D0h]
  int v73; // [sp+44h] [-CCh]
  int v74; // [sp+48h] [-C8h]
  int v75; // [sp+4Ch] [-C4h]
  int v76; // [sp+50h] [-C0h]
  int v77; // [sp+58h] [-B8h]
  unsigned int v78[4]; // [sp+60h] [-B0h] BYREF

  v38 = HIDWORD(trmAxis);
  v39 = (float *)trmAxis;
  if ( a31 > 0 )
  {
    LODWORD(v41) = 0;
    v78[0] = 0;
    v42 = nullptr;
    v43 = 0;
    if ( SHIDWORD(trmAxis) > 0 )
    {
      while ( 2 )
      {
        v45 = a31 - 1;
        v46 = (const idPositionedCollisionModel *)(80 * (a31 - 1) + a29);
        do
        {
          v47 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v46);
          if ( v47 == nullptr )
          {
            *(_QWORD *)&this->queryData = v41;
            return this;
          }
          parms = v47->parms;
          v49 = ((_cntlzw((unsigned int)*trms) & 0x20) != 0) + 1;
          v47->type = v49;
          *parms = v49;
          v50 = (float *)v47->parms;
          v50[4] = start->x;
          v50[5] = start->y;
          v50[6] = start->z;
          v51 = (float *)v47->parms;
          v51[7] = end->x;
          v51[8] = end->y;
          v51[9] = end->z;
          v52 = (float *)v47->parms;
          v52[12] = 0.0;
          v52[11] = 0.0;
          v52[10] = 0.0;
          v53 = (float *)v47->parms;
          v53[15] = 0.0;
          v53[14] = 0.0;
          v53[13] = 0.0;
          v47->parms->rotationAngle = 0.0;
          v54 = (float *)v47->parms;
          v54[19] = 0.0;
          v54[18] = 0.0;
          v54[17] = 0.0;
          if ( *trms != nullptr )
            radius = (*trms)->radius;
          else
            radius = 0.0;
          v47->parms->depth = radius;
          v56 = (float *)v47->parms;
          v56[21] = *v39;
          v56[22] = v39[1];
          v56[23] = v39[2];
          v56[24] = v39[3];
          v56[25] = v39[4];
          v56[26] = v39[5];
          v56[27] = v39[6];
          v56[28] = v39[7];
          v56[29] = v39[8];
          v47->parms->contentMask = a27;
          v47->parms->selfId = v43;
          v47->userName = a33;
          v47->trm = *trms;
          v47->nextOnQuery = v42;
          v42 = v47;
          *(_QWORD *)((char *)&v57 + 4) = v46->modelQuery.offset;
          LODWORD(v57) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v46->modelQuery.offset),
            dependency1: v57,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_NONE,
            globalStart: start,
            globalEnd: end,
            globalBounds: v58,
            mergePriority: v59,
            a10: v60,
            a11: v61,
            a12: v62,
            a13: v63,
            a14: v64,
            a15: v65,
            a16: v66,
            a17: v67,
            a18: v68,
            a19: v69,
            a20: v70,
            a21: v71,
            a22: v72,
            a23: v73,
            a24: v74,
            a25: v75,
            a26: v76,
            a27: globalBounds,
            a28: v77,
            a29: (int *)v78);
          --v45;
          --v46;
        }
        while ( v45 >= 0 );
        ++v43;
        ++trms;
        if ( v43 < v38 )
          continue;
        break;
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v42, v78[0]),
      slideMoveState: nullptr);
    return this;
  }
  else
  {
    HIDWORD(trmAxis) = a33;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: 0x100000000uLL,
      endpos: end,
      endAxis: (const idMat3 *)trmAxis,
      userName: trmAxis);
    return this;
  }
}


// ========================================================================
// ?SubmitLocalTranslationQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@V2@ABVidVec3@@1ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DE5D0
// RVA : 0x005DE5D0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitLocalTranslationQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        idCollisionQuery *localSpace,
        const idVec3 *start,
        const idVec3 *end,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const int a8,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        float *a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const idMat3 *trmAxisa)
{
  __int64 numTrms; // r11 OVERLAPPED
  int v42; // r15
  unsigned int *v43; // r9 OVERLAPPED
  int v44; // r23
  double y; // fp12
  double v46; // fp11
  double v47; // fp10
  modelQuery_t *v48; // r27
  double v49; // fp6
  unsigned int *v50; // r28
  int v51; // r29
  const idPositionedCollisionModel *v52; // r30
  modelQuery_t *v53; // r3
  _DWORD *parms; // r10
  int v55; // r11
  float *v56; // r11
  float *v57; // r11
  float *v58; // r11
  float *v59; // r11
  float *v60; // r11
  double v61; // fp0
  float *v62; // r11
  unsigned int v63; // r11
  __int128 v64; // r6
  const idBounds *v66; // [sp+8h] [-118h]
  int *v67; // [sp+Ch] [-114h]
  int v68; // [sp+10h] [-110h]
  int v69; // [sp+14h] [-10Ch]
  int v70; // [sp+18h] [-108h]
  int v71; // [sp+1Ch] [-104h]
  int v72; // [sp+20h] [-100h]
  int v73; // [sp+24h] [-FCh]
  int v74; // [sp+28h] [-F8h]
  int v75; // [sp+2Ch] [-F4h]
  int v76; // [sp+30h] [-F0h]
  int v77; // [sp+34h] [-ECh]
  int v78; // [sp+38h] [-E8h]
  int v79; // [sp+3Ch] [-E4h]
  int v80; // [sp+40h] [-E0h]
  int v81; // [sp+44h] [-DCh]
  int v82; // [sp+48h] [-D8h]
  int v83; // [sp+4Ch] [-D4h]
  int v84; // [sp+50h] [-D0h]
  int v85; // [sp+58h] [-C8h]
  unsigned int v86; // [sp+60h] [-C0h] BYREF
  idVec3 v87[2]; // [sp+68h] [-B8h] BYREF

  v42 = HIDWORD(numTrms);
  if ( a34 > 0 )
  {
    *(__int64 *)((char *)&numTrms + 4) = idCollisionQuery::finalResultsLastSubmittedOffset;
    if ( (unsigned int)localSpace < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset
      || (*(__int64 *)((char *)&numTrms + 4) = idCollisionQuery::finalResultsLastAllocedOffset,
          LOBYTE(numTrms) = 1,
          (unsigned int)localSpace > (unsigned int)idCollisionQuery::finalResultsLastAllocedOffset) )
    {
      LOBYTE(numTrms) = 0;
    }
    if ( (_BYTE)numTrms != 0 )
    {
      v44 = 0;
      y = globalBounds->b[1].y;
      v46 = (float)(globalBounds->b[1].x + globalBounds->b[0].x);
      v47 = globalBounds->b[0].y;
      v86 = 0;
      v48 = nullptr;
      v49 = (float)(globalBounds->b[1].z + globalBounds->b[0].z);
      v87[0].x = (float)v46 * (float)0.5;
      v87[0].y = (float)((float)y + (float)v47) * (float)0.5;
      v87[0].z = (float)v49 * (float)0.5;
      if ( v42 <= 0 )
      {
LABEL_15:
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this,
          result,
          mergePriority: __PAIR64__((unsigned int)v48, v86),
          slideMoveState: nullptr);
        return this;
      }
      v50 = v43;
LABEL_8:
      v51 = a34 - 1;
      v52 = (const idPositionedCollisionModel *)(80 * (a34 - 1) + a32);
      while ( 1 )
      {
        v53 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v52);
        if ( v53 == nullptr )
          break;
        parms = v53->parms;
        v55 = ((_cntlzw(*v50) & 0x20) != 0) + 1;
        v53->type = v55;
        *parms = v55;
        v56 = (float *)v53->parms;
        v56[4] = start->x;
        v56[5] = start->y;
        v56[6] = start->z;
        v57 = (float *)v53->parms;
        v57[7] = end->x;
        v57[8] = end->y;
        v57[9] = end->z;
        v58 = (float *)v53->parms;
        v58[12] = 0.0;
        v58[11] = 0.0;
        v58[10] = 0.0;
        v59 = (float *)v53->parms;
        v59[15] = 0.0;
        v59[14] = 0.0;
        v59[13] = 0.0;
        v53->parms->rotationAngle = 0.0;
        v60 = (float *)v53->parms;
        v60[19] = 0.0;
        v60[18] = 0.0;
        v60[17] = 0.0;
        if ( *v50 != 0 )
          v61 = *(float *)(*v50 + 1528);
        else
          v61 = 0.0;
        v53->parms->depth = v61;
        v62 = (float *)v53->parms;
        v62[21] = *a28;
        v62[22] = a28[1];
        v62[23] = a28[2];
        v62[24] = a28[3];
        v62[25] = a28[4];
        v62[26] = a28[5];
        v62[27] = a28[6];
        v62[28] = a28[7];
        v62[29] = a28[8];
        v53->parms->contentMask = a30;
        v53->parms->selfId = v44;
        v53->userName = (const char *)trmAxisa;
        v63 = *v50;
        v53->nextOnQuery = v48;
        v48 = v53;
        v53->trm = (const idTraceModel *)v63;
        *(_QWORD *)((char *)&v64 + 4) = v52->modelQuery.offset;
        LODWORD(v64) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v52->modelQuery.offset),
          dependency1: v64,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_LOCAL_SPACE,
          globalStart: v87,
          globalEnd: v87,
          globalBounds: v66,
          mergePriority: v67,
          a10: v68,
          a11: v69,
          a12: v70,
          a13: v71,
          a14: v72,
          a15: v73,
          a16: v74,
          a17: v75,
          a18: v76,
          a19: v77,
          a20: v78,
          a21: v79,
          a22: v80,
          a23: v81,
          a24: v82,
          a25: v83,
          a26: v84,
          a27: globalBounds,
          a28: v85,
          a29: (int *)&v86);
        --v51;
        --v52;
        if ( v51 < 0 )
        {
          ++v44;
          ++v50;
          if ( v44 < v42 )
            goto LABEL_8;
          goto LABEL_15;
        }
      }
    }
  }
  LODWORD(numTrms) = 0;
  *(_QWORD *)&this->queryData = numTrms;
  return this;
}


// ========================================================================
// ?SubmitRotationQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@ABVidRotation@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DE898
// RVA : 0x005DE898
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitRotationQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        idRotation *rotation,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        int a33,
        const char *a34)
{
  float y; // r7
  char *v42; // r10
  float z; // r6
  _DWORD *p_z; // r11
  int v45; // ctr
  __int64 v46; // r10
  __int64 v48; // r14
  modelQuery_t *v49; // r25
  int v50; // r24
  int v52; // r27
  const idPositionedCollisionModel *v53; // r28
  modelQuery_t *v54; // r3
  _DWORD *parms; // r7
  int v56; // r11
  float *v57; // r11
  float *v58; // r11
  float *v59; // r11
  float *v60; // r11
  float *v61; // r11
  float *v62; // r11
  __int128 v63; // r6
  const idBounds *v64; // [sp+8h] [-148h]
  int *v65; // [sp+Ch] [-144h]
  int v66; // [sp+10h] [-140h]
  int v67; // [sp+14h] [-13Ch]
  int v68; // [sp+18h] [-138h]
  int v69; // [sp+1Ch] [-134h]
  int v70; // [sp+20h] [-130h]
  int v71; // [sp+24h] [-12Ch]
  int v72; // [sp+28h] [-128h]
  int v73; // [sp+2Ch] [-124h]
  int v74; // [sp+30h] [-120h]
  int v75; // [sp+34h] [-11Ch]
  int v76; // [sp+38h] [-118h]
  int v77; // [sp+3Ch] [-114h]
  int v78; // [sp+40h] [-110h]
  int v79; // [sp+44h] [-10Ch]
  int v80; // [sp+48h] [-108h]
  int v81; // [sp+4Ch] [-104h]
  int v82; // [sp+50h] [-100h]
  int v83; // [sp+58h] [-F8h]
  unsigned int v84; // [sp+60h] [-F0h] BYREF
  idVec3 v85; // [sp+68h] [-E8h] BYREF
  char v86; // [sp+7Ch] [-D4h] BYREF
  idMat3 v87; // [sp+80h] [-D0h] BYREF

  if ( a32 > 0 )
  {
    LODWORD(v48) = 0;
    v84 = 0;
    v49 = nullptr;
    v50 = 0;
    if ( numTrms > 0 )
    {
      while ( 2 )
      {
        v52 = a32 - 1;
        v53 = (const idPositionedCollisionModel *)(80 * (a32 - 1) + a30);
        do
        {
          v54 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v53);
          if ( v54 == nullptr )
          {
            *(_QWORD *)&this->queryData = v48;
            return this;
          }
          parms = v54->parms;
          v56 = ((_cntlzw((unsigned int)*trms) & 0x20) != 0) + 3;
          v54->type = v56;
          *parms = v56;
          v57 = (float *)v54->parms;
          v57[4] = start->x;
          v57[5] = start->y;
          v57[6] = start->z;
          v58 = (float *)v54->parms;
          v58[7] = start->x;
          v58[8] = start->y;
          v58[9] = start->z;
          v59 = (float *)v54->parms;
          v59[10] = rotation->origin.x;
          v59[11] = rotation->origin.y;
          v59[12] = rotation->origin.z;
          v60 = (float *)v54->parms;
          v60[13] = rotation->vec.x;
          v60[14] = rotation->vec.y;
          v60[15] = rotation->vec.z;
          v54->parms->rotationAngle = rotation->angle;
          v61 = (float *)v54->parms;
          v61[19] = 0.0;
          v61[18] = 0.0;
          v61[17] = 0.0;
          v54->parms->depth = 0.0;
          v62 = (float *)v54->parms;
          v62[21] = trmAxis->mat[0].x;
          v62[22] = trmAxis->mat[0].y;
          v62[23] = trmAxis->mat[0].z;
          v62[24] = trmAxis->mat[1].x;
          v62[25] = trmAxis->mat[1].y;
          v62[26] = trmAxis->mat[1].z;
          v62[27] = trmAxis->mat[2].x;
          v62[28] = trmAxis->mat[2].y;
          v62[29] = trmAxis->mat[2].z;
          v54->parms->contentMask = a28;
          v54->parms->selfId = v50;
          v54->userName = a34;
          v54->trm = *trms;
          v54->nextOnQuery = v49;
          v49 = v54;
          *(_QWORD *)((char *)&v63 + 4) = v53->modelQuery.offset;
          LODWORD(v63) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v53->modelQuery.offset),
            dependency1: v63,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_NONE,
            globalStart: start,
            globalEnd: start,
            globalBounds: v64,
            mergePriority: v65,
            a10: v66,
            a11: v67,
            a12: v68,
            a13: v69,
            a14: v70,
            a15: v71,
            a16: v72,
            a17: v73,
            a18: v74,
            a19: v75,
            a20: v76,
            a21: v77,
            a22: v78,
            a23: v79,
            a24: v80,
            a25: v81,
            a26: v82,
            a27: globalBounds,
            a28: v83,
            a29: (int *)&v84);
          --v52;
          --v53;
        }
        while ( v52 >= 0 );
        ++v50;
        ++trms;
        if ( v50 < numTrms )
          continue;
        break;
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v49, v84),
      slideMoveState: nullptr);
    return this;
  }
  else
  {
    y = start->y;
    v42 = &v86;
    z = start->z;
    p_z = (_DWORD *)&trmAxis[-1].mat[2].z;
    v85.x = start->x;
    v45 = 9;
    v85.y = y;
    v85.z = z;
    do
    {
      ++p_z;
      v42 += 4;
      *(_DWORD *)v42 = *p_z;
      --v45;
    }
    while ( v45 != 0 );
    idRotation::RotatePoint(this: rotation, point: &v85);
    if ( !rotation->axisValid )
      idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &v87, a: &rotation->axis);
    idMat3::OrthoNormalizeSelf(this: &v87);
    HIDWORD(v46) = a34;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: 0x300000000uLL,
      endpos: &v85,
      endAxis: &v87,
      userName: v46);
    return this;
  }
}


// ========================================================================
// ?SubmitMotionQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@0ABVidRotation@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DEB78
// RVA : 0x005DEB78
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitMotionQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        const idVec3 *start,
        const idVec3 *end,
        idRotation *rotation,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        float *a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        const idMat3 *trmAxisa)
{
  idCollisionQueryJobManager *v36; // r26
  const idTraceModel **v42; // r22
  int v43; // r27
  _DWORD *v44; // r10
  float *v45; // r11
  int i; // ctr
  __int64 v47; // r10
  int v49; // r23
  modelQuery_t *v50; // r25
  const idTraceModel **v51; // r24
  int v52; // r26
  const idPositionedCollisionModel *v53; // r27
  __int64 v54; // r11
  modelQuery_t *v55; // r3
  queryParms_t *v56; // r11
  float *v57; // r11
  float *v58; // r11
  float *v59; // r11
  float *v60; // r11
  float *v61; // r11
  double radius; // fp0
  float *v63; // r11
  const idTraceModel *v64; // r5
  __int128 v65; // r6
  int v66; // r19
  int v67; // r23
  int v68; // r26
  const idPositionedCollisionModel *v69; // r27
  modelQuery_t *v70; // r3
  queryParms_t *parms; // r11
  float *v72; // r11
  float *v73; // r11
  float *v74; // r11
  float *v75; // r11
  float *v76; // r11
  float *v77; // r11
  __int128 v78; // r7
  const idBounds *v79; // [sp+8h] [-138h]
  int *v80; // [sp+Ch] [-134h]
  int v81; // [sp+10h] [-130h]
  int v82; // [sp+14h] [-12Ch]
  int v83; // [sp+18h] [-128h]
  int v84; // [sp+1Ch] [-124h]
  int v85; // [sp+20h] [-120h]
  int v86; // [sp+24h] [-11Ch]
  int v87; // [sp+28h] [-118h]
  int v88; // [sp+2Ch] [-114h]
  int v89; // [sp+30h] [-110h]
  int v90; // [sp+34h] [-10Ch]
  int v91; // [sp+38h] [-108h]
  int v92; // [sp+3Ch] [-104h]
  int v93; // [sp+40h] [-100h]
  int v94; // [sp+44h] [-FCh]
  int v95; // [sp+48h] [-F8h]
  int v96; // [sp+4Ch] [-F4h]
  int v97; // [sp+50h] [-F0h]
  int v98; // [sp+58h] [-E8h]
  int v99[2]; // [sp+60h] [-E0h] BYREF
  __int64 v100; // [sp+68h] [-D8h] BYREF
  idMat3 v101; // [sp+70h] [-D0h] BYREF

  v36 = this;
  v42 = trms;
  v43 = numTrms;
  if ( a34 > 0 )
  {
    v49 = 0;
    v99[0] = 0;
    v50 = nullptr;
    if ( numTrms <= 0 )
    {
LABEL_17:
      idCollisionQueryJobManager::AddModelQueryToMergeList(
        this: (idCollisionQueryJobManager *)&v100,
        result,
        mergePriority: __PAIR64__((unsigned int)v50, v99[0]),
        slideMoveState: nullptr);
      v66 = HIDWORD(v100);
      if ( (_DWORD)v100 == 0 )
      {
        *(_QWORD *)&v36->queryData = v100;
        return v36;
      }
      v67 = 0;
      if ( v43 <= 0 )
      {
LABEL_26:
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: v36,
          result,
          mergePriority: __PAIR64__((unsigned int)v50, v99[0]),
          slideMoveState: nullptr);
        return v36;
      }
LABEL_21:
      v68 = a34 - 1;
      v69 = (const idPositionedCollisionModel *)(80 * (a34 - 1) + a32);
      while ( 1 )
      {
        v70 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v69);
        if ( v70 == nullptr )
          break;
        parms = v70->parms;
        v70->type = TRACE_ROTATION;
        parms->type = TRACE_ROTATION;
        v72 = (float *)v70->parms;
        v72[4] = start->x;
        v72[5] = start->y;
        v72[6] = start->z;
        v73 = (float *)v70->parms;
        v73[7] = end->x;
        v73[8] = end->y;
        v73[9] = end->z;
        v74 = (float *)v70->parms;
        v74[10] = rotation->origin.x;
        v74[11] = rotation->origin.y;
        v74[12] = rotation->origin.z;
        v75 = (float *)v70->parms;
        v75[13] = rotation->vec.x;
        v75[14] = rotation->vec.y;
        v75[15] = rotation->vec.z;
        v70->parms->rotationAngle = rotation->angle;
        v76 = (float *)v70->parms;
        v76[19] = 0.0;
        v76[18] = 0.0;
        v76[17] = 0.0;
        v70->parms->depth = 0.0;
        v77 = (float *)v70->parms;
        v77[21] = *a28;
        v77[22] = a28[1];
        v77[23] = a28[2];
        v77[24] = a28[3];
        v77[25] = a28[4];
        v77[26] = a28[5];
        v77[27] = a28[6];
        v77[28] = a28[7];
        v77[29] = a28[8];
        v70->parms->contentMask = a30;
        v70->parms->selfId = v67;
        v70->userName = (const char *)trmAxisa;
        v70->trm = *v42;
        v70->nextOnQuery = v50;
        v50 = v70;
        *((_QWORD *)&v78 + 1) = *(_QWORD *)(v66 - 17560);
        *(_QWORD *)&v78 = v69->modelQuery.offset;
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v69->modelQuery.offset),
          dependency1: *(unsigned __int64 *)((char *)&v78 + 4),
          dependency2: *(_DWORD *)(v66 - 17556),
          dependencyType: DEPENDENCY_MOTION_ROTATION,
          globalStart: start,
          globalEnd: end,
          globalBounds: v79,
          mergePriority: v80,
          a10: v81,
          a11: v82,
          a12: v83,
          a13: v84,
          a14: v85,
          a15: v86,
          a16: v87,
          a17: v88,
          a18: v89,
          a19: v90,
          a20: v91,
          a21: v92,
          a22: v93,
          a23: v94,
          a24: v95,
          a25: v96,
          a26: v97,
          a27: globalBounds,
          a28: v98,
          a29: v99);
        --v68;
        --v69;
        if ( v68 < 0 )
        {
          ++v67;
          ++v42;
          if ( v67 < numTrms )
            goto LABEL_21;
          v36 = this;
          goto LABEL_26;
        }
      }
    }
    else
    {
      v51 = trms;
LABEL_9:
      v52 = a34 - 1;
      v53 = (const idPositionedCollisionModel *)(80 * (a34 - 1) + a32);
      while ( 1 )
      {
        v55 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v53);
        if ( v55 == nullptr )
          break;
        v56 = v55->parms;
        v55->type = TRACE_TRANSLATION;
        v56->type = TRACE_TRANSLATION;
        v57 = (float *)v55->parms;
        v57[4] = start->x;
        v57[5] = start->y;
        v57[6] = start->z;
        v58 = (float *)v55->parms;
        v58[7] = end->x;
        v58[8] = end->y;
        v58[9] = end->z;
        v59 = (float *)v55->parms;
        v59[12] = 0.0;
        v59[11] = 0.0;
        v59[10] = 0.0;
        v60 = (float *)v55->parms;
        v60[15] = 0.0;
        v60[14] = 0.0;
        v60[13] = 0.0;
        v55->parms->rotationAngle = 0.0;
        v61 = (float *)v55->parms;
        v61[19] = 0.0;
        v61[18] = 0.0;
        v61[17] = 0.0;
        if ( *v51 != nullptr )
          radius = (*v51)->radius;
        else
          radius = 0.0;
        v55->parms->depth = radius;
        v63 = (float *)v55->parms;
        v63[21] = *a28;
        v63[22] = a28[1];
        v63[23] = a28[2];
        v63[24] = a28[3];
        v63[25] = a28[4];
        v63[26] = a28[5];
        v63[27] = a28[6];
        v63[28] = a28[7];
        v63[29] = a28[8];
        v55->parms->contentMask = a30;
        v55->parms->selfId = v49;
        v55->userName = (const char *)trmAxisa;
        v64 = *v51;
        v55->nextOnQuery = v50;
        v50 = v55;
        v55->trm = v64;
        *(_QWORD *)((char *)&v65 + 4) = v53->modelQuery.offset;
        LODWORD(v65) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v53->modelQuery.offset),
          dependency1: v65,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_NONE,
          globalStart: start,
          globalEnd: end,
          globalBounds: v79,
          mergePriority: v80,
          a10: v81,
          a11: v82,
          a12: v83,
          a13: v84,
          a14: v85,
          a15: v86,
          a16: v87,
          a17: v88,
          a18: v89,
          a19: v90,
          a20: v91,
          a21: v92,
          a22: v93,
          a23: v94,
          a24: v95,
          a25: v96,
          a26: v97,
          a27: globalBounds,
          a28: v98,
          a29: v99);
        --v52;
        --v53;
        if ( v52 < 0 )
        {
          v43 = numTrms;
          ++v49;
          ++v51;
          if ( v49 < numTrms )
            goto LABEL_9;
          v36 = this;
          goto LABEL_17;
        }
      }
    }
    LODWORD(v54) = 0;
    *(_QWORD *)&this->queryData = v54;
    return this;
  }
  v44 = (_DWORD *)&v100 + 1;
  v45 = a28 - 1;
  for ( i = 9; i != 0; --i )
    *++v44 = *(_DWORD *)++v45;
  if ( !rotation->axisValid )
    idRotation::ToMat3(this: rotation);
  idMat3::operator*=(this: &v101, a: &rotation->axis);
  idMat3::OrthoNormalizeSelf(this: &v101);
  HIDWORD(v47) = trmAxisa;
  idCollisionQueryJobManager::AllocFinishedFinalResult(
    this: v36,
    result,
    type2: 0x300000000uLL,
    endpos: end,
    endAxis: &v101,
    userName: v47);
  return v36;
}


// ========================================================================
// ?SubmitMotionContactsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@0ABVidRotation@@MABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DF038
// RVA : 0x005DF038
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitMotionContactsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idVec3 *end,
        idRotation *rotation,
        double depth,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        const idTraceModel **numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        float *a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int numTrms_0,
        int a38,
        const idMat3 *trmAxisa)
{
  idCollisionQueryJobManager *v39; // r25
  _DWORD *v47; // r10
  float *v48; // r11
  int i; // ctr
  __int64 v50; // r10
  int v52; // r26
  int v53; // r22
  modelQuery_t *v54; // r27
  int v55; // r24
  int v56; // r25
  const idPositionedCollisionModel *v57; // r26
  __int64 v58; // r11
  modelQuery_t *v59; // r3
  queryParms_t *parms; // r10
  float *v61; // r11
  float *v62; // r11
  float *v63; // r11
  float *v64; // r11
  float *v65; // r11
  double v66; // fp0
  float *v67; // r11
  const idTraceModel *v68; // r5
  __int128 v69; // r6
  int v70; // r15
  int v71; // r22
  int v72; // r15
  const idTraceModel **v73; // r21
  int v74; // r25
  const idPositionedCollisionModel *v75; // r26
  modelQuery_t *v76; // r3
  queryParms_t *v77; // r11
  float *v78; // r11
  float *v79; // r11
  float *v80; // r11
  float *v81; // r11
  float *v82; // r11
  float *v83; // r11
  __int128 v84; // r6
  __int64 v85; // r21
  int v86; // r24
  int v87; // r16
  const idTraceModel **v88; // r22
  int v89; // r26
  const idPositionedCollisionModel *v90; // r29
  modelQuery_t *v91; // r3
  queryParms_t *v92; // r11
  float *v93; // r11
  float *v94; // r11
  float *v95; // r11
  float *v96; // r11
  float *v97; // r11
  float *v98; // r11
  const idTraceModel *v99; // r5
  unsigned __int64 offset; // r5 OVERLAPPED
  __int64 v101; // r7 OVERLAPPED
  const idBounds *v102; // [sp+8h] [-138h]
  int *v103; // [sp+Ch] [-134h]
  int v104; // [sp+10h] [-130h]
  int v105; // [sp+14h] [-12Ch]
  int v106; // [sp+18h] [-128h]
  int v107; // [sp+1Ch] [-124h]
  int v108; // [sp+20h] [-120h]
  int v109; // [sp+24h] [-11Ch]
  int v110; // [sp+28h] [-118h]
  int v111; // [sp+2Ch] [-114h]
  int v112; // [sp+30h] [-110h]
  int v113; // [sp+34h] [-10Ch]
  int v114; // [sp+38h] [-108h]
  int v115; // [sp+3Ch] [-104h]
  int v116; // [sp+40h] [-100h]
  int v117; // [sp+44h] [-FCh]
  int v118; // [sp+48h] [-F8h]
  int v119; // [sp+4Ch] [-F4h]
  int v120; // [sp+50h] [-F0h]
  int v121; // [sp+58h] [-E8h]
  int v122[2]; // [sp+60h] [-E0h] BYREF
  __int64 v123; // [sp+68h] [-D8h] BYREF
  idMat3 v124; // [sp+70h] [-D0h] BYREF

  v39 = this;
  if ( numTrms_0 > 0 )
  {
    v52 = a29;
    v53 = 0;
    v54 = nullptr;
    v122[0] = 0;
    if ( a29 > 0 )
    {
      v55 = (int)numTrms;
LABEL_9:
      v56 = numTrms_0 - 1;
      v57 = (const idPositionedCollisionModel *)(80 * (numTrms_0 - 1) + a35);
      while ( 1 )
      {
        v59 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v57);
        if ( v59 == nullptr )
          goto LABEL_19;
        parms = v59->parms;
        v59->type = TRACE_TRANSLATION;
        parms->type = TRACE_TRANSLATION;
        v61 = (float *)v59->parms;
        v61[4] = start->x;
        v61[5] = start->y;
        v61[6] = start->z;
        v62 = (float *)v59->parms;
        v62[7] = end->x;
        v62[8] = end->y;
        v62[9] = end->z;
        v63 = (float *)v59->parms;
        v63[12] = 0.0;
        v63[11] = 0.0;
        v63[10] = 0.0;
        v64 = (float *)v59->parms;
        v64[15] = 0.0;
        v64[14] = 0.0;
        v64[13] = 0.0;
        v59->parms->rotationAngle = 0.0;
        v65 = (float *)v59->parms;
        v65[19] = 0.0;
        v65[18] = 0.0;
        v65[17] = 0.0;
        if ( *(_DWORD *)v55 != 0 )
          v66 = *(float *)(*(_DWORD *)v55 + 1528);
        else
          v66 = 0.0;
        v59->parms->depth = v66;
        v67 = (float *)v59->parms;
        v67[21] = *a31;
        v67[22] = a31[1];
        v67[23] = a31[2];
        v67[24] = a31[3];
        v67[25] = a31[4];
        v67[26] = a31[5];
        v67[27] = a31[6];
        v67[28] = a31[7];
        v67[29] = a31[8];
        v59->parms->contentMask = a33;
        v59->parms->selfId = v53;
        v59->userName = (const char *)trmAxisa;
        v68 = *(const idTraceModel **)v55;
        v59->nextOnQuery = v54;
        v54 = v59;
        v59->trm = v68;
        *(_QWORD *)((char *)&v69 + 4) = v57->modelQuery.offset;
        LODWORD(v69) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: result,
          modelQuery: (modelQuery_t *)HIDWORD(v57->modelQuery.offset),
          dependency1: v69,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_NONE,
          globalStart: start,
          globalEnd: end,
          globalBounds: v102,
          mergePriority: v103,
          a10: v104,
          a11: v105,
          a12: v106,
          a13: v107,
          a14: v108,
          a15: v109,
          a16: v110,
          a17: v111,
          a18: v112,
          a19: v113,
          a20: v114,
          a21: v115,
          a22: v116,
          a23: v117,
          a24: v118,
          a25: v119,
          a26: v120,
          a27: (const idBounds *)trms,
          a28: v121,
          a29: v122);
        --v56;
        --v57;
        if ( v56 < 0 )
        {
          v52 = a29;
          ++v53;
          v55 += 4;
          if ( v53 < a29 )
            goto LABEL_9;
          v39 = this;
          break;
        }
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v123,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v54, v122[0]),
      slideMoveState: nullptr);
    v70 = HIDWORD(v123);
    if ( (_DWORD)v123 == 0 )
    {
      *(_QWORD *)&v39->queryData = v123;
      return v39;
    }
    v71 = 0;
    if ( v52 > 0 )
    {
      v72 = HIDWORD(v123) - 1;
      v73 = numTrms;
      while ( 1 )
      {
        v74 = v72;
        if ( v72 >= 0 )
          break;
LABEL_26:
        ++v71;
        ++v73;
        if ( v71 >= a29 )
        {
          v70 = numTrms_0;
          v52 = a29;
          v39 = this;
          goto LABEL_28;
        }
      }
      v75 = (const idPositionedCollisionModel *)(80 * v72 + a35);
      while ( 1 )
      {
        v76 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v75);
        if ( v76 == nullptr )
          goto LABEL_19;
        v77 = v76->parms;
        v76->type = TRACE_ROTATION;
        v77->type = TRACE_ROTATION;
        v78 = (float *)v76->parms;
        v78[4] = start->x;
        v78[5] = start->y;
        v78[6] = start->z;
        v79 = (float *)v76->parms;
        v79[7] = end->x;
        v79[8] = end->y;
        v79[9] = end->z;
        v80 = (float *)v76->parms;
        v80[10] = rotation->origin.x;
        v80[11] = rotation->origin.y;
        v80[12] = rotation->origin.z;
        v81 = (float *)v76->parms;
        v81[13] = rotation->vec.x;
        v81[14] = rotation->vec.y;
        v81[15] = rotation->vec.z;
        v76->parms->rotationAngle = rotation->angle;
        v82 = (float *)v76->parms;
        v82[19] = 0.0;
        v82[18] = 0.0;
        v82[17] = 0.0;
        v76->parms->depth = 0.0;
        v83 = (float *)v76->parms;
        v83[21] = *a31;
        v83[22] = a31[1];
        v83[23] = a31[2];
        v83[24] = a31[3];
        v83[25] = a31[4];
        v83[26] = a31[5];
        v83[27] = a31[6];
        v83[28] = a31[7];
        v83[29] = a31[8];
        v76->parms->contentMask = a33;
        v76->parms->selfId = v71;
        v76->userName = (const char *)trmAxisa;
        v76->trm = *v73;
        v76->nextOnQuery = v54;
        v54 = v76;
        LODWORD(v84) = HIDWORD(null_query.offset);
        *(_QWORD *)((char *)&v84 + 4) = v75->modelQuery.offset;
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: result,
          modelQuery: (modelQuery_t *)HIDWORD(v75->modelQuery.offset),
          dependency1: v84,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_MOTION_ROTATION,
          globalStart: start,
          globalEnd: end,
          globalBounds: v102,
          mergePriority: v103,
          a10: v104,
          a11: v105,
          a12: v106,
          a13: v107,
          a14: v108,
          a15: v109,
          a16: v110,
          a17: v111,
          a18: v112,
          a19: v113,
          a20: v114,
          a21: v115,
          a22: v116,
          a23: v117,
          a24: v118,
          a25: v119,
          a26: v120,
          a27: (const idBounds *)trms,
          a28: v121,
          a29: v122);
        --v74;
        --v75;
        if ( v74 < 0 )
          goto LABEL_26;
      }
    }
LABEL_28:
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v123,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v54, v122[0]),
      slideMoveState: nullptr);
    v85 = v123;
    if ( (_DWORD)v123 != 0 )
    {
      v86 = 0;
      if ( v52 > 0 )
      {
        v87 = v70 - 1;
        v88 = numTrms;
        while ( 1 )
        {
          v89 = v70 - 1;
          if ( v87 >= 0 )
            break;
LABEL_35:
          ++v86;
          ++v88;
          if ( v86 >= a29 )
          {
            v39 = this;
            goto LABEL_37;
          }
        }
        v90 = (const idPositionedCollisionModel *)(80 * v87 + a35);
        while ( 1 )
        {
          v91 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v90);
          if ( v91 == nullptr )
            break;
          v92 = v91->parms;
          v91->type = TRACE_CONTACTS_OMNI_DIR;
          v92->type = TRACE_CONTACTS_OMNI_DIR;
          v93 = (float *)v91->parms;
          v93[4] = start->x;
          v93[5] = start->y;
          v93[6] = start->z;
          v94 = (float *)v91->parms;
          v94[7] = start->x;
          v94[8] = start->y;
          v94[9] = start->z;
          v95 = (float *)v91->parms;
          v95[12] = 0.0;
          v95[11] = 0.0;
          v95[10] = 0.0;
          v96 = (float *)v91->parms;
          v96[15] = 0.0;
          v96[14] = 0.0;
          v96[13] = 0.0;
          v91->parms->rotationAngle = 0.0;
          v97 = (float *)v91->parms;
          v97[19] = 0.0;
          v97[17] = 0.0;
          v97[18] = 0.0;
          v91->parms->depth = depth;
          v98 = (float *)v91->parms;
          v98[21] = *a31;
          v98[22] = a31[1];
          v98[23] = a31[2];
          v98[24] = a31[3];
          v98[25] = a31[4];
          v98[26] = a31[5];
          v98[27] = a31[6];
          v98[28] = a31[7];
          v98[29] = a31[8];
          v91->parms->contentMask = a33;
          v91->parms->selfId = v86;
          v91->userName = (const char *)trmAxisa;
          v99 = *v88;
          v91->nextOnQuery = v54;
          v54 = v91;
          v91->trm = v99;
          offset = v90->modelQuery.offset;
          v101 = *(_QWORD *)(HIDWORD(v85) - 17560);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v90->modelQuery.offset),
            dependency1: *(unsigned __int64 *)((char *)&offset - 4),
            dependency2: *(_DWORD *)(HIDWORD(v85) - 17556),
            dependencyType: DEPENDENCY_MOTION_CONTACTS,
            globalStart: start,
            globalEnd: end,
            globalBounds: v102,
            mergePriority: v103,
            a10: v104,
            a11: v105,
            a12: v106,
            a13: v107,
            a14: v108,
            a15: v109,
            a16: v110,
            a17: v111,
            a18: v112,
            a19: v113,
            a20: v114,
            a21: v115,
            a22: v116,
            a23: v117,
            a24: v118,
            a25: v119,
            a26: v120,
            a27: (const idBounds *)trms,
            a28: v121,
            a29: v122);
          --v89;
          --v90;
          if ( v89 < 0 )
            goto LABEL_35;
        }
LABEL_19:
        LODWORD(v58) = 0;
        *(_QWORD *)&this->queryData = v58;
        return this;
      }
LABEL_37:
      idCollisionQueryJobManager::AddModelQueryToMergeList(
        this: (idCollisionQueryJobManager *)&v123,
        (idCollisionQuery *)result,
        mergePriority: __PAIR64__((unsigned int)v54, v122[0]),
        slideMoveState: nullptr);
      if ( (_DWORD)v123 == 0 )
      {
        *(_QWORD *)&v39->queryData = v123;
        return v39;
      }
    }
    *(_QWORD *)&v39->queryData = v85;
    return v39;
  }
  v47 = (_DWORD *)&v123 + 1;
  v48 = a31 - 1;
  for ( i = 9; i != 0; --i )
    *++v47 = *(_DWORD *)++v48;
  if ( !rotation->axisValid )
    idRotation::ToMat3(this: rotation);
  idMat3::operator*=(this: &v124, a: &rotation->axis);
  idMat3::OrthoNormalizeSelf(this: &v124);
  HIDWORD(v50) = trmAxisa;
  idCollisionQueryJobManager::AllocFinishedFinalResult(
    this: v39,
    (idCollisionQuery *)result,
    type2: 0x300000008uLL,
    endpos: end,
    endAxis: &v124,
    userName: v50);
  return v39;
}


// ========================================================================
// ?SubmitContentsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DF720
// RVA : 0x005DF720
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitContentsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        __int64 contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        const char *a31)
{
  __int64 v31; // r15
  float *v37; // r31
  int v38; // r20
  const idMat3 *v39; // r8
  modelQuery_t *v41; // r26
  int v42; // r24
  int v44; // r28
  const idPositionedCollisionModel *v45; // r29
  modelQuery_t *v46; // r3
  _DWORD *parms; // r7
  int v48; // r11
  float *v49; // r11
  float *v50; // r11
  float *v51; // r11
  float *v52; // r11
  float *v53; // r11
  float *v54; // r11
  __int128 v55; // r6
  const idBounds *v56; // [sp+8h] [-F8h]
  int *v57; // [sp+Ch] [-F4h]
  int v58; // [sp+10h] [-F0h]
  int v59; // [sp+14h] [-ECh]
  int v60; // [sp+18h] [-E8h]
  int v61; // [sp+1Ch] [-E4h]
  int v62; // [sp+20h] [-E0h]
  int v63; // [sp+24h] [-DCh]
  int v64; // [sp+28h] [-D8h]
  int v65; // [sp+2Ch] [-D4h]
  int v66; // [sp+30h] [-D0h]
  int v67; // [sp+34h] [-CCh]
  int v68; // [sp+38h] [-C8h]
  int v69; // [sp+3Ch] [-C4h]
  int v70; // [sp+40h] [-C0h]
  int v71; // [sp+44h] [-BCh]
  int v72; // [sp+48h] [-B8h]
  int v73; // [sp+4Ch] [-B4h]
  int v74; // [sp+50h] [-B0h]
  int v75; // [sp+58h] [-A8h]
  unsigned int v76; // [sp+60h] [-A0h] BYREF

  v37 = (float *)HIDWORD(contentMask);
  v38 = contentMask;
  if ( a29 > 0 )
  {
    LODWORD(v31) = 0;
    v76 = 0;
    v41 = nullptr;
    v42 = 0;
    if ( numTrms > 0 )
    {
      while ( 2 )
      {
        v44 = a29 - 1;
        v45 = (const idPositionedCollisionModel *)(80 * (a29 - 1) + a27);
        do
        {
          v46 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v45);
          if ( v46 == nullptr )
          {
            *(_QWORD *)&this->queryData = v31;
            return this;
          }
          parms = v46->parms;
          v48 = ((_cntlzw((unsigned int)*trms) & 0x20) != 0) + 5;
          v46->type = v48;
          *parms = v48;
          v49 = (float *)v46->parms;
          v49[4] = start->x;
          v49[5] = start->y;
          v49[6] = start->z;
          v50 = (float *)v46->parms;
          v50[7] = start->x;
          v50[8] = start->y;
          v50[9] = start->z;
          v51 = (float *)v46->parms;
          v51[12] = 0.0;
          v51[11] = 0.0;
          v51[10] = 0.0;
          v52 = (float *)v46->parms;
          v52[15] = 0.0;
          v52[14] = 0.0;
          v52[13] = 0.0;
          v46->parms->rotationAngle = 0.0;
          v53 = (float *)v46->parms;
          v53[19] = 0.0;
          v53[18] = 0.0;
          v53[17] = 0.0;
          v46->parms->depth = 0.0;
          v54 = (float *)v46->parms;
          v54[21] = *v37;
          v54[22] = v37[1];
          v54[23] = v37[2];
          v54[24] = v37[3];
          v54[25] = v37[4];
          v54[26] = v37[5];
          v54[27] = v37[6];
          v54[28] = v37[7];
          v54[29] = v37[8];
          v46->parms->contentMask = v38;
          v46->parms->selfId = v42;
          v46->userName = a31;
          v46->trm = *trms;
          v46->nextOnQuery = v41;
          v41 = v46;
          *(_QWORD *)((char *)&v55 + 4) = v45->modelQuery.offset;
          LODWORD(v55) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v45->modelQuery.offset),
            dependency1: v55,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_NONE,
            globalStart: start,
            globalEnd: start,
            globalBounds: v56,
            mergePriority: v57,
            a10: v58,
            a11: v59,
            a12: v60,
            a13: v61,
            a14: v62,
            a15: v63,
            a16: v64,
            a17: v65,
            a18: v66,
            a19: v67,
            a20: v68,
            a21: v69,
            a22: v70,
            a23: v71,
            a24: v72,
            a25: v73,
            a26: v74,
            a27: globalBounds,
            a28: v75,
            a29: (int *)&v76);
          --v44;
          --v45;
        }
        while ( v44 >= 0 );
        ++v42;
        ++trms;
        if ( v42 < numTrms )
          continue;
        break;
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v41, v76),
      slideMoveState: nullptr);
    return this;
  }
  else
  {
    v39 = (const idMat3 *)HIDWORD(contentMask);
    HIDWORD(contentMask) = a31;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: 0x500000000uLL,
      endpos: start,
      endAxis: v39,
      userName: contentMask);
    return this;
  }
}


// ========================================================================
// ?SubmitLocalContentsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@V2@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DF970
// RVA : 0x005DF970
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitLocalContentsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        idCollisionQuery *localSpace,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        int a33,
        const char *a34)
{
  __int64 v34; // r14
  int v41; // r9
  char v42; // r11
  double x; // fp0
  double v44; // fp13
  modelQuery_t *v45; // r26
  int v46; // r24
  double v47; // fp6
  int v48; // r17
  int v50; // r28
  const idPositionedCollisionModel *v51; // r29
  modelQuery_t *v52; // r3
  _DWORD *parms; // r7
  int v54; // r11
  float *v55; // r11
  float *v56; // r11
  float *v57; // r11
  float *v58; // r11
  float *v59; // r11
  float *v60; // r11
  __int128 v61; // r6
  const idBounds *v63; // [sp+8h] [-118h]
  int *v64; // [sp+Ch] [-114h]
  int v65; // [sp+10h] [-110h]
  int v66; // [sp+14h] [-10Ch]
  int v67; // [sp+18h] [-108h]
  int v68; // [sp+1Ch] [-104h]
  int v69; // [sp+20h] [-100h]
  int v70; // [sp+24h] [-FCh]
  int v71; // [sp+28h] [-F8h]
  int v72; // [sp+2Ch] [-F4h]
  int v73; // [sp+30h] [-F0h]
  int v74; // [sp+34h] [-ECh]
  int v75; // [sp+38h] [-E8h]
  int v76; // [sp+3Ch] [-E4h]
  int v77; // [sp+40h] [-E0h]
  int v78; // [sp+44h] [-DCh]
  int v79; // [sp+48h] [-D8h]
  int v80; // [sp+4Ch] [-D4h]
  int v81; // [sp+50h] [-D0h]
  int v82; // [sp+58h] [-C8h]
  unsigned int v83; // [sp+60h] [-C0h] BYREF
  idVec3 v84[2]; // [sp+68h] [-B8h] BYREF

  LODWORD(v34) = 0;
  if ( a32 > 0 )
  {
    v41 = HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset);
    if ( (unsigned int)localSpace < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset
      || (v41 = HIDWORD(idCollisionQuery::finalResultsLastAllocedOffset),
          v42 = 1,
          (unsigned int)localSpace > (unsigned int)idCollisionQuery::finalResultsLastAllocedOffset) )
    {
      v42 = 0;
    }
    if ( v42 != 0 )
    {
      x = globalBounds->b[1].x;
      v44 = globalBounds->b[0].x;
      v83 = 0;
      v45 = nullptr;
      v46 = 0;
      v47 = (float)(globalBounds->b[1].z + globalBounds->b[0].z);
      v84[0].y = (float)(globalBounds->b[1].y + globalBounds->b[0].y) * (float)0.5;
      v84[0].x = (float)((float)x + (float)v44) * (float)0.5;
      v84[0].z = (float)v47 * (float)0.5;
      if ( numTrms <= 0 )
      {
LABEL_13:
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this,
          result,
          mergePriority: __PAIR64__((unsigned int)v45, v83),
          slideMoveState: nullptr);
        return this;
      }
      v48 = v41 - 1;
      while ( 1 )
      {
        v50 = v48;
        if ( v48 >= 0 )
          break;
LABEL_12:
        ++v46;
        ++trms;
        if ( v46 >= numTrms )
          goto LABEL_13;
      }
      v51 = (const idPositionedCollisionModel *)(80 * v48 + a30);
      while ( 1 )
      {
        v52 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v51);
        if ( v52 == nullptr )
          break;
        parms = v52->parms;
        v54 = ((_cntlzw((unsigned int)*trms) & 0x20) != 0) + 5;
        v52->type = v54;
        *parms = v54;
        v55 = (float *)v52->parms;
        v55[4] = start->x;
        v55[5] = start->y;
        v55[6] = start->z;
        v56 = (float *)v52->parms;
        v56[7] = start->x;
        v56[8] = start->y;
        v56[9] = start->z;
        v57 = (float *)v52->parms;
        v57[12] = 0.0;
        v57[11] = 0.0;
        v57[10] = 0.0;
        v58 = (float *)v52->parms;
        v58[15] = 0.0;
        v58[14] = 0.0;
        v58[13] = 0.0;
        v52->parms->rotationAngle = 0.0;
        v59 = (float *)v52->parms;
        v59[19] = 0.0;
        v59[18] = 0.0;
        v59[17] = 0.0;
        v52->parms->depth = 0.0;
        v60 = (float *)v52->parms;
        v60[21] = trmAxis->mat[0].x;
        v60[22] = trmAxis->mat[0].y;
        v60[23] = trmAxis->mat[0].z;
        v60[24] = trmAxis->mat[1].x;
        v60[25] = trmAxis->mat[1].y;
        v60[26] = trmAxis->mat[1].z;
        v60[27] = trmAxis->mat[2].x;
        v60[28] = trmAxis->mat[2].y;
        v60[29] = trmAxis->mat[2].z;
        v52->parms->contentMask = a28;
        v52->parms->selfId = v46;
        v52->userName = a34;
        v52->trm = *trms;
        v52->nextOnQuery = v45;
        v45 = v52;
        *(_QWORD *)((char *)&v61 + 4) = v51->modelQuery.offset;
        LODWORD(v61) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v51->modelQuery.offset),
          dependency1: v61,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_LOCAL_SPACE,
          globalStart: v84,
          globalEnd: v84,
          globalBounds: v63,
          mergePriority: v64,
          a10: v65,
          a11: v66,
          a12: v67,
          a13: v68,
          a14: v69,
          a15: v70,
          a16: v71,
          a17: v72,
          a18: v73,
          a19: v74,
          a20: v75,
          a21: v76,
          a22: v77,
          a23: v78,
          a24: v79,
          a25: v80,
          a26: v81,
          a27: globalBounds,
          a28: v82,
          a29: (int *)&v83);
        --v50;
        --v51;
        if ( v50 < 0 )
          goto LABEL_12;
      }
    }
  }
  *(_QWORD *)&this->queryData = v34;
  return this;
}


// ========================================================================
// ?SubmitContactsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@0MABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DFC18
// RVA : 0x005DFC18
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitContactsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idVec3 *dir,
        double depth,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        __int64 trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        int a33,
        int a34,
        int a35,
        const idMat3 *trmAxis_0)
{
  int v42; // r17
  __int64 v44; // r14
  modelQuery_t *v45; // r26
  int v46; // r24
  const idTraceModel **v47; // r23
  int v48; // r27
  const idPositionedCollisionModel *v49; // r28
  modelQuery_t *v50; // r4
  _DWORD *parms; // r6
  int v52; // r11
  float *v53; // r11
  float *v54; // r11
  float *v55; // r11
  float *v56; // r11
  float *v57; // r11
  float *v58; // r11
  __int128 v59; // r6
  const idBounds *v60; // [sp+8h] [-108h]
  int *v61; // [sp+Ch] [-104h]
  int v62; // [sp+10h] [-100h]
  int v63; // [sp+14h] [-FCh]
  int v64; // [sp+18h] [-F8h]
  int v65; // [sp+1Ch] [-F4h]
  int v66; // [sp+20h] [-F0h]
  int v67; // [sp+24h] [-ECh]
  int v68; // [sp+28h] [-E8h]
  int v69; // [sp+2Ch] [-E4h]
  int v70; // [sp+30h] [-E0h]
  int v71; // [sp+34h] [-DCh]
  int v72; // [sp+38h] [-D8h]
  int v73; // [sp+3Ch] [-D4h]
  int v74; // [sp+40h] [-D0h]
  int v75; // [sp+44h] [-CCh]
  int v76; // [sp+48h] [-C8h]
  int v77; // [sp+4Ch] [-C4h]
  int v78; // [sp+50h] [-C0h]
  int v79; // [sp+58h] [-B8h]
  unsigned int v80; // [sp+60h] [-B0h] BYREF

  v42 = trmAxis;
  if ( a34 > 0 )
  {
    LODWORD(v44) = 0;
    v80 = 0;
    v45 = nullptr;
    v46 = 0;
    if ( (int)trmAxis > 0 )
    {
      v47 = (const idTraceModel **)HIDWORD(trmAxis);
      while ( 2 )
      {
        v48 = a34 - 1;
        v49 = (const idPositionedCollisionModel *)(80 * (a34 - 1) + a32);
        do
        {
          v50 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v49);
          if ( v50 == nullptr )
          {
            *(_QWORD *)&this->queryData = v44;
            return this;
          }
          parms = v50->parms;
          v52 = ((_cntlzw((LODWORD(dir->z) | LODWORD(dir->y) | LODWORD(dir->x)) & 0x7FFFFFFF) & 0x20) != 0) + 7;
          v50->type = v52;
          *parms = v52;
          v53 = (float *)v50->parms;
          v53[4] = start->x;
          v53[5] = start->y;
          v53[6] = start->z;
          v54 = (float *)v50->parms;
          v54[7] = start->x;
          v54[8] = start->y;
          v54[9] = start->z;
          v55 = (float *)v50->parms;
          v55[12] = 0.0;
          v55[11] = 0.0;
          v55[10] = 0.0;
          v56 = (float *)v50->parms;
          v56[15] = 0.0;
          v56[14] = 0.0;
          v56[13] = 0.0;
          v50->parms->rotationAngle = 0.0;
          v57 = (float *)v50->parms;
          v57[17] = dir->x;
          v57[18] = dir->y;
          v57[19] = dir->z;
          v50->parms->depth = depth;
          v58 = (float *)v50->parms;
          v58[21] = *(float *)a28;
          v58[22] = *(float *)(a28 + 4);
          v58[23] = *(float *)(a28 + 8);
          v58[24] = *(float *)(a28 + 12);
          v58[25] = *(float *)(a28 + 16);
          v58[26] = *(float *)(a28 + 20);
          v58[27] = *(float *)(a28 + 24);
          v58[28] = *(float *)(a28 + 28);
          v58[29] = *(float *)(a28 + 32);
          v50->parms->contentMask = a30;
          v50->parms->selfId = v46;
          v50->userName = (const char *)trmAxis_0;
          v50->trm = *v47;
          v50->nextOnQuery = v45;
          v45 = v50;
          *(_QWORD *)((char *)&v59 + 4) = v49->modelQuery.offset;
          LODWORD(v59) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v49->modelQuery.offset),
            dependency1: v59,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_NONE,
            globalStart: start,
            globalEnd: start,
            globalBounds: v60,
            mergePriority: v61,
            a10: v62,
            a11: v63,
            a12: v64,
            a13: v65,
            a14: v66,
            a15: v67,
            a16: v68,
            a17: v69,
            a18: v70,
            a19: v71,
            a20: v72,
            a21: v73,
            a22: v74,
            a23: v75,
            a24: v76,
            a25: v77,
            a26: v78,
            a27: (const idBounds *)trms,
            a28: v79,
            a29: (int *)&v80);
          --v48;
          --v49;
        }
        while ( v48 >= 0 );
        ++v46;
        ++v47;
        if ( v46 < v42 )
          continue;
        break;
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v45, v80),
      slideMoveState: nullptr);
    return this;
  }
  else
  {
    HIDWORD(trmAxis) = trmAxis_0;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: 0x800000000uLL,
      endpos: start,
      endAxis: (const idMat3 *)a28,
      userName: trmAxis);
    return this;
  }
}


// ========================================================================
// ?SubmitClipQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@ABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825DFEA0
// RVA : 0x005DFEA0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitClipQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idBounds *globalBounds,
        const idTraceModel **trms,
        int numTrms,
        __int64 contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        const char *a31)
{
  float *v36; // r31
  int v37; // r19
  const idMat3 *v38; // r8
  __int64 v40; // r14
  modelQuery_t *v41; // r27
  int v42; // r24
  int v44; // r28
  const idPositionedCollisionModel *v45; // r29
  modelQuery_t *v46; // r3
  queryParms_t *parms; // r11
  float *v48; // r11
  float *v49; // r11
  float *v50; // r11
  float *v51; // r11
  float *v52; // r11
  float *v53; // r11
  __int128 v54; // r6
  const idBounds *v55; // [sp+8h] [-108h]
  int *v56; // [sp+Ch] [-104h]
  int v57; // [sp+10h] [-100h]
  int v58; // [sp+14h] [-FCh]
  int v59; // [sp+18h] [-F8h]
  int v60; // [sp+1Ch] [-F4h]
  int v61; // [sp+20h] [-F0h]
  int v62; // [sp+24h] [-ECh]
  int v63; // [sp+28h] [-E8h]
  int v64; // [sp+2Ch] [-E4h]
  int v65; // [sp+30h] [-E0h]
  int v66; // [sp+34h] [-DCh]
  int v67; // [sp+38h] [-D8h]
  int v68; // [sp+3Ch] [-D4h]
  int v69; // [sp+40h] [-D0h]
  int v70; // [sp+44h] [-CCh]
  int v71; // [sp+48h] [-C8h]
  int v72; // [sp+4Ch] [-C4h]
  int v73; // [sp+50h] [-C0h]
  int v74; // [sp+58h] [-B8h]
  unsigned int v75[4]; // [sp+60h] [-B0h] BYREF

  v36 = (float *)HIDWORD(contentMask);
  v37 = contentMask;
  if ( a29 > 0 )
  {
    LODWORD(v40) = 0;
    v75[0] = 0;
    v41 = nullptr;
    v42 = 0;
    if ( numTrms > 0 )
    {
      while ( 2 )
      {
        v44 = a29 - 1;
        v45 = (const idPositionedCollisionModel *)(80 * (a29 - 1) + a27);
        do
        {
          v46 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v45);
          if ( v46 == nullptr )
          {
            *(_QWORD *)&this->queryData = v40;
            return this;
          }
          parms = v46->parms;
          v46->type = TRACE_CLIP;
          parms->type = TRACE_CLIP;
          v48 = (float *)v46->parms;
          v48[4] = start->x;
          v48[5] = start->y;
          v48[6] = start->z;
          v49 = (float *)v46->parms;
          v49[7] = start->x;
          v49[8] = start->y;
          v49[9] = start->z;
          v50 = (float *)v46->parms;
          v50[12] = 0.0;
          v50[11] = 0.0;
          v50[10] = 0.0;
          v51 = (float *)v46->parms;
          v51[15] = 0.0;
          v51[14] = 0.0;
          v51[13] = 0.0;
          v46->parms->rotationAngle = 0.0;
          v52 = (float *)v46->parms;
          v52[19] = 0.0;
          v52[18] = 0.0;
          v52[17] = 0.0;
          v46->parms->depth = 0.0;
          v53 = (float *)v46->parms;
          v53[21] = *v36;
          v53[22] = v36[1];
          v53[23] = v36[2];
          v53[24] = v36[3];
          v53[25] = v36[4];
          v53[26] = v36[5];
          v53[27] = v36[6];
          v53[28] = v36[7];
          v53[29] = v36[8];
          v46->parms->contentMask = v37;
          v46->parms->selfId = v42;
          v46->userName = a31;
          v46->trm = *trms;
          v46->nextOnQuery = v41;
          v41 = v46;
          *(_QWORD *)((char *)&v54 + 4) = v45->modelQuery.offset;
          LODWORD(v54) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: result,
            modelQuery: (modelQuery_t *)HIDWORD(v45->modelQuery.offset),
            dependency1: v54,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_NONE,
            globalStart: start,
            globalEnd: start,
            globalBounds: v55,
            mergePriority: v56,
            a10: v57,
            a11: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: globalBounds,
            a28: v74,
            a29: (int *)v75);
          --v44;
          --v45;
        }
        while ( v44 >= 0 );
        ++v42;
        ++trms;
        if ( v42 < numTrms )
          continue;
        break;
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this,
      (idCollisionQuery *)result,
      mergePriority: __PAIR64__((unsigned int)v41, v75[0]),
      slideMoveState: nullptr);
    return this;
  }
  else
  {
    v38 = (const idMat3 *)HIDWORD(contentMask);
    HIDWORD(contentMask) = a31;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: 0x900000000uLL,
      endpos: start,
      endAxis: v38,
      userName: contentMask);
    return this;
  }
}


// ========================================================================
// ?SubmitStepMoveQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@00MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825E00E8
// RVA : 0x005E00E8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitStepMoveQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        __int64 numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        const idTraceModel **a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        const idTraceModel **trms_0,
        int a38,
        int numTrms_0,
        int a40,
        const idMat3 *trmAxisa)
{
  idCollisionQueryJobManager *v41; // r23
  const idBounds *v48; // r20
  int v49; // r24
  int v50; // r18
  modelQuery_t *v51; // r27
  const idTraceModel **v52; // r17
  int v53; // r23
  const idPositionedCollisionModel *v54; // r24
  __int64 v55; // r11
  modelQuery_t *v56; // r3
  queryParms_t *v57; // r11
  float *v58; // r11
  float *v59; // r11
  float *v60; // r11
  float *v61; // r11
  float *v62; // r11
  float *v63; // r11
  __int128 v64; // r6
  int v65; // r14
  int v67; // r18
  const idTraceModel **v68; // r17
  int v69; // r16
  int v70; // r23
  const idPositionedCollisionModel *v71; // r24
  modelQuery_t *v72; // r3
  queryParms_t *v73; // r11
  float *v74; // r11
  float *v75; // r11
  float *v76; // r11
  float *v77; // r11
  float *v78; // r11
  float *v79; // r11
  __int128 v80; // r6
  unsigned int v81; // r15
  int v82; // r18
  const idTraceModel **v83; // r17
  int v84; // r14
  int v85; // r23
  const idPositionedCollisionModel *v86; // r24
  modelQuery_t *v87; // r3
  queryParms_t *v88; // r11
  float *v89; // r11
  float *v90; // r11
  float *v91; // r11
  float *v92; // r11
  float *v93; // r11
  float *v94; // r11
  const idTraceModel *v95; // r5
  __int128 v96; // r6
  int v97; // r17
  int v98; // r19
  const idTraceModel **v99; // r18
  int v100; // r16
  int v101; // r23
  const idPositionedCollisionModel *v102; // r24
  modelQuery_t *v103; // r3
  queryParms_t *parms; // r11
  __int128 v105; // r6
  float *v106; // r11
  float *v107; // r11
  float *v108; // r11
  float *v109; // r11
  float *v110; // r11
  float *p_trmAxis; // r11
  const idTraceModel *v112; // r5
  const idBounds *v113; // [sp+8h] [-118h]
  int *v114; // [sp+Ch] [-114h]
  int v115; // [sp+10h] [-110h]
  int v116; // [sp+14h] [-10Ch]
  int v117; // [sp+18h] [-108h]
  int v118; // [sp+1Ch] [-104h]
  int v119; // [sp+20h] [-100h]
  int v120; // [sp+24h] [-FCh]
  int v121; // [sp+28h] [-F8h]
  int v122; // [sp+2Ch] [-F4h]
  int v123; // [sp+30h] [-F0h]
  int v124; // [sp+34h] [-ECh]
  int v125; // [sp+38h] [-E8h]
  int v126; // [sp+3Ch] [-E4h]
  int v127; // [sp+40h] [-E0h]
  int v128; // [sp+44h] [-DCh]
  int v129; // [sp+48h] [-D8h]
  int v130; // [sp+4Ch] [-D4h]
  int v131; // [sp+50h] [-D0h]
  int v132; // [sp+58h] [-C8h]
  int v133[2]; // [sp+60h] [-C0h] BYREF
  __int64 v134; // [sp+68h] [-B8h] BYREF

  v41 = this;
  v48 = (const idBounds *)numTrms;
  if ( numTrms_0 > 0 )
  {
    v49 = a31;
    v50 = 0;
    v51 = nullptr;
    v133[0] = 0;
    if ( a31 <= 0 )
    {
LABEL_10:
      idCollisionQueryJobManager::AddModelQueryToMergeList(
        this: (idCollisionQueryJobManager *)&v134,
        result,
        mergePriority: __PAIR64__((unsigned int)v51, v133[0]),
        slideMoveState: nullptr);
      v65 = HIDWORD(v134);
      if ( (_DWORD)v134 == 0 )
      {
        *(_QWORD *)&v41->queryData = v134;
        return v41;
      }
      v67 = 0;
      if ( v49 <= 0 )
      {
LABEL_22:
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: (idCollisionQueryJobManager *)&v134,
          result,
          mergePriority: __PAIR64__((unsigned int)v51, v133[0]),
          slideMoveState: nullptr);
        v81 = HIDWORD(v134);
        if ( (_DWORD)v134 == 0 )
        {
          *(_QWORD *)&v41->queryData = v134;
          return v41;
        }
        v82 = 0;
        if ( v49 <= 0 )
        {
LABEL_32:
          idCollisionQueryJobManager::AddModelQueryToMergeList(
            this: (idCollisionQueryJobManager *)&v134,
            result,
            mergePriority: __PAIR64__((unsigned int)v51, v133[0]),
            slideMoveState: nullptr);
          v97 = v134;
          if ( (_DWORD)v134 == 0 )
          {
            *(_QWORD *)&v41->queryData = v134;
            return v41;
          }
          v98 = 0;
          if ( v49 <= 0 )
          {
LABEL_43:
            idCollisionQueryJobManager::AddModelQueryToMergeList(
              this: v41,
              result,
              mergePriority: __PAIR64__((unsigned int)v51, v133[0]),
              slideMoveState: nullptr);
            return v41;
          }
          v99 = a29;
          v100 = v65 - 1;
          while ( 1 )
          {
            v101 = v65 - 1;
            if ( v100 >= 0 )
              break;
LABEL_41:
            ++v98;
            ++v99;
            if ( v98 >= v49 )
            {
              v41 = this;
              goto LABEL_43;
            }
          }
          v102 = (const idPositionedCollisionModel *)&trms_0[20 * v100];
          while ( 1 )
          {
            v103 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v102);
            if ( v103 == nullptr )
              break;
            parms = v103->parms;
            v103->type = TRACE_TRANSLATION;
            parms->type = TRACE_TRANSLATION;
            LODWORD(v105) = v97;
            v106 = (float *)v103->parms;
            v106[4] = start->x;
            v106[5] = start->y;
            v106[6] = start->z;
            v107 = (float *)v103->parms;
            v107[7] = end->x;
            v107[8] = end->y;
            v107[9] = end->z;
            v108 = (float *)v103->parms;
            v108[12] = 0.0;
            v108[11] = 0.0;
            v108[10] = 0.0;
            v109 = (float *)v103->parms;
            v109[15] = 0.0;
            v109[14] = 0.0;
            v109[13] = 0.0;
            v103->parms->rotationAngle = 0.0;
            v110 = (float *)v103->parms;
            v110[17] = downNormal->x;
            v110[18] = downNormal->y;
            v110[19] = downNormal->z;
            v103->parms->depth = stepDown;
            p_trmAxis = (float *)&v103->parms->trmAxis;
            *p_trmAxis = *(float *)a33;
            p_trmAxis[1] = *(float *)(a33 + 4);
            p_trmAxis[2] = *(float *)(a33 + 8);
            p_trmAxis[3] = *(float *)(a33 + 12);
            p_trmAxis[4] = *(float *)(a33 + 16);
            p_trmAxis[5] = *(float *)(a33 + 20);
            p_trmAxis[6] = *(float *)(a33 + 24);
            p_trmAxis[7] = *(float *)(a33 + 28);
            p_trmAxis[8] = *(float *)(a33 + 32);
            v103->parms->contentMask = a35;
            v103->parms->selfId = v98;
            v103->userName = (const char *)trmAxisa;
            v112 = *v99;
            v103->nextOnQuery = v51;
            v51 = v103;
            v103->trm = v112;
            *(_QWORD *)((char *)&v105 + 4) = v102->modelQuery.offset;
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: (idCollisionQueryJobManager *)result,
              modelQuery: (modelQuery_t *)HIDWORD(v102->modelQuery.offset),
              dependency1: v105,
              dependency2: v81,
              dependencyType: DEPENDENCY_STEPMOVE_STEP_DOWN,
              globalStart: start,
              globalEnd: end,
              globalBounds: v113,
              mergePriority: v114,
              a10: v115,
              a11: v116,
              a12: v117,
              a13: v118,
              a14: v119,
              a15: v120,
              a16: v121,
              a17: v122,
              a18: v123,
              a19: v124,
              a20: v125,
              a21: v126,
              a22: v127,
              a23: v128,
              a24: v129,
              a25: v130,
              a26: v131,
              a27: v48,
              a28: v132,
              a29: v133);
            --v101;
            --v102;
            if ( v101 < 0 )
            {
              v49 = a31;
              goto LABEL_41;
            }
          }
        }
        else
        {
          v83 = a29;
          v84 = v65 - 1;
          while ( 1 )
          {
            v85 = v84;
            if ( v84 >= 0 )
              break;
LABEL_30:
            ++v82;
            ++v83;
            if ( v82 >= a31 )
            {
              v65 = numTrms_0;
              v49 = a31;
              v41 = this;
              goto LABEL_32;
            }
          }
          v86 = (const idPositionedCollisionModel *)&trms_0[20 * v84];
          while ( 1 )
          {
            v87 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v86);
            if ( v87 == nullptr )
              break;
            v88 = v87->parms;
            v87->type = TRACE_TRANSLATION;
            v88->type = TRACE_TRANSLATION;
            v89 = (float *)v87->parms;
            v89[4] = start->x;
            v89[5] = start->y;
            v89[6] = start->z;
            v90 = (float *)v87->parms;
            v90[7] = end->x;
            v90[8] = end->y;
            v90[9] = end->z;
            v91 = (float *)v87->parms;
            v91[12] = 0.0;
            v91[11] = 0.0;
            v91[10] = 0.0;
            v92 = (float *)v87->parms;
            v92[15] = 0.0;
            v92[14] = 0.0;
            v92[13] = 0.0;
            v87->parms->rotationAngle = 0.0;
            v93 = (float *)v87->parms;
            v93[17] = downNormal->x;
            v93[18] = downNormal->y;
            v93[19] = downNormal->z;
            v87->parms->depth = -stepUp;
            v94 = (float *)v87->parms;
            v94[21] = *(float *)a33;
            v94[22] = *(float *)(a33 + 4);
            v94[23] = *(float *)(a33 + 8);
            v94[24] = *(float *)(a33 + 12);
            v94[25] = *(float *)(a33 + 16);
            v94[26] = *(float *)(a33 + 20);
            v94[27] = *(float *)(a33 + 24);
            v94[28] = *(float *)(a33 + 28);
            v94[29] = *(float *)(a33 + 32);
            v87->parms->contentMask = a35;
            v87->parms->selfId = v82;
            v87->userName = (const char *)trmAxisa;
            v95 = *v83;
            v87->nextOnQuery = v51;
            v51 = v87;
            v87->trm = v95;
            *(_QWORD *)((char *)&v96 + 4) = v86->modelQuery.offset;
            LODWORD(v96) = HIDWORD(null_query.offset);
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: (idCollisionQueryJobManager *)result,
              modelQuery: (modelQuery_t *)HIDWORD(v86->modelQuery.offset),
              dependency1: v96,
              dependency2: null_query.offset,
              dependencyType: DEPENDENCY_STEPMOVE_2ND_MOVE,
              globalStart: start,
              globalEnd: end,
              globalBounds: v113,
              mergePriority: v114,
              a10: v115,
              a11: v116,
              a12: v117,
              a13: v118,
              a14: v119,
              a15: v120,
              a16: v121,
              a17: v122,
              a18: v123,
              a19: v124,
              a20: v125,
              a21: v126,
              a22: v127,
              a23: v128,
              a24: v129,
              a25: v130,
              a26: v131,
              a27: v48,
              a28: v132,
              a29: v133);
            --v85;
            --v86;
            if ( v85 < 0 )
              goto LABEL_30;
          }
        }
      }
      else
      {
        v68 = a29;
        v69 = HIDWORD(v134) - 1;
        while ( 1 )
        {
          v70 = v65 - 1;
          if ( v69 >= 0 )
            break;
LABEL_20:
          ++v67;
          ++v68;
          if ( v67 >= v49 )
          {
            v41 = this;
            goto LABEL_22;
          }
        }
        v71 = (const idPositionedCollisionModel *)&trms_0[20 * v69];
        while ( 1 )
        {
          v72 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v71);
          if ( v72 == nullptr )
            break;
          v73 = v72->parms;
          v72->type = TRACE_TRANSLATION;
          v73->type = TRACE_TRANSLATION;
          v74 = (float *)v72->parms;
          v74[4] = start->x;
          v74[5] = start->y;
          v74[6] = start->z;
          v75 = (float *)v72->parms;
          v75[7] = end->x;
          v75[8] = end->y;
          v75[9] = end->z;
          v76 = (float *)v72->parms;
          v76[12] = 0.0;
          v76[10] = 0.0;
          v76[11] = 0.0;
          v77 = (float *)v72->parms;
          v77[14] = 0.0;
          v77[13] = 0.0;
          v77[15] = 0.0;
          v72->parms->rotationAngle = 0.0;
          v78 = (float *)v72->parms;
          v78[17] = downNormal->x;
          v78[18] = downNormal->y;
          v78[19] = downNormal->z;
          v72->parms->depth = -stepUp;
          v79 = (float *)v72->parms;
          v79[21] = *(float *)a33;
          v79[22] = *(float *)(a33 + 4);
          v79[23] = *(float *)(a33 + 8);
          v79[24] = *(float *)(a33 + 12);
          v79[25] = *(float *)(a33 + 16);
          v79[26] = *(float *)(a33 + 20);
          v79[27] = *(float *)(a33 + 24);
          v79[28] = *(float *)(a33 + 28);
          v79[29] = *(float *)(a33 + 32);
          v72->parms->contentMask = a35;
          v72->parms->selfId = v67;
          v72->userName = (const char *)trmAxisa;
          v72->trm = *v68;
          v72->nextOnQuery = v51;
          v51 = v72;
          *(_QWORD *)((char *)&v80 + 4) = v71->modelQuery.offset;
          LODWORD(v80) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: (idCollisionQueryJobManager *)result,
            modelQuery: (modelQuery_t *)HIDWORD(v71->modelQuery.offset),
            dependency1: v80,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_STEPMOVE_STEP_UP,
            globalStart: start,
            globalEnd: end,
            globalBounds: v113,
            mergePriority: v114,
            a10: v115,
            a11: v116,
            a12: v117,
            a13: v118,
            a14: v119,
            a15: v120,
            a16: v121,
            a17: v122,
            a18: v123,
            a19: v124,
            a20: v125,
            a21: v126,
            a22: v127,
            a23: v128,
            a24: v129,
            a25: v130,
            a26: v131,
            a27: v48,
            a28: v132,
            a29: v133);
          --v70;
          --v71;
          if ( v70 < 0 )
          {
            v49 = a31;
            goto LABEL_20;
          }
        }
      }
    }
    else
    {
      v52 = a29;
LABEL_5:
      v53 = numTrms_0 - 1;
      v54 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
      while ( 1 )
      {
        v56 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v54);
        if ( v56 == nullptr )
          break;
        v57 = v56->parms;
        v56->type = TRACE_TRANSLATION;
        v57->type = TRACE_TRANSLATION;
        v58 = (float *)v56->parms;
        v58[4] = start->x;
        v58[5] = start->y;
        v58[6] = start->z;
        v59 = (float *)v56->parms;
        v59[7] = end->x;
        v59[8] = end->y;
        v59[9] = end->z;
        v60 = (float *)v56->parms;
        v60[12] = 0.0;
        v60[11] = 0.0;
        v60[10] = 0.0;
        v61 = (float *)v56->parms;
        v61[15] = 0.0;
        v61[14] = 0.0;
        v61[13] = 0.0;
        v56->parms->rotationAngle = 0.0;
        v62 = (float *)v56->parms;
        v62[17] = downNormal->x;
        v62[18] = downNormal->y;
        v62[19] = downNormal->z;
        v56->parms->depth = 0.0;
        v63 = (float *)v56->parms;
        v63[21] = *(float *)a33;
        v63[22] = *(float *)(a33 + 4);
        v63[23] = *(float *)(a33 + 8);
        v63[24] = *(float *)(a33 + 12);
        v63[25] = *(float *)(a33 + 16);
        v63[26] = *(float *)(a33 + 20);
        v63[27] = *(float *)(a33 + 24);
        v63[28] = *(float *)(a33 + 28);
        v63[29] = *(float *)(a33 + 32);
        v56->parms->contentMask = a35;
        v56->parms->selfId = v50;
        v56->userName = (const char *)trmAxisa;
        v56->trm = *v52;
        v56->nextOnQuery = v51;
        v51 = v56;
        *(_QWORD *)((char *)&v64 + 4) = v54->modelQuery.offset;
        LODWORD(v64) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v54->modelQuery.offset),
          dependency1: v64,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_NONE,
          globalStart: start,
          globalEnd: end,
          globalBounds: v113,
          mergePriority: v114,
          a10: v115,
          a11: v116,
          a12: v117,
          a13: v118,
          a14: v119,
          a15: v120,
          a16: v121,
          a17: v122,
          a18: v123,
          a19: v124,
          a20: v125,
          a21: v126,
          a22: v127,
          a23: v128,
          a24: v129,
          a25: v130,
          a26: v131,
          a27: v48,
          a28: v132,
          a29: v133);
        --v53;
        --v54;
        if ( v53 < 0 )
        {
          v49 = a31;
          ++v50;
          ++v52;
          if ( v50 < a31 )
            goto LABEL_5;
          v41 = this;
          goto LABEL_10;
        }
      }
    }
    LODWORD(v55) = 0;
    *(_QWORD *)&this->queryData = v55;
    return this;
  }
  HIDWORD(numTrms) = trmAxisa;
  idCollisionQueryJobManager::AllocFinishedFinalResult(
    this,
    result,
    type2: 0x100000000uLL,
    endpos: end,
    endAxis: (const idMat3 *)a33,
    userName: numTrms);
  return v41;
}


// ========================================================================
// ?SubmitStepMoveContactsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@00MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825E0908
// RVA : 0x005E0908
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitStepMoveContactsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        __int64 numTrms,
        const idMat3 *trmAxis,
        int contentMask,
        const idPositionedCollisionModel *models,
        int numModels,
        const char *userName,
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
        const idTraceModel **a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        const idTraceModel **trms_0,
        int a38,
        int numTrms_0,
        int a40,
        const idMat3 *trmAxisa)
{
  int v41; // r24
  const idBounds *v49; // r20
  int v51; // r19
  modelQuery_t *v52; // r27
  unsigned __int8 v53; // r26
  const idTraceModel **v54; // r18
  int v55; // r23
  const idPositionedCollisionModel *v56; // r24
  __int64 v57; // r11
  modelQuery_t *v58; // r3
  queryParms_t *parms; // r11
  float *v60; // r11
  float *v61; // r11
  float *v62; // r11
  float *v63; // r11
  float *v64; // r11
  float *v65; // r11
  __int128 v66; // r6
  __int64 v67; // r17
  int v68; // r19
  const idTraceModel **v69; // r18
  int v70; // r15
  int v71; // r23
  const idPositionedCollisionModel *v72; // r24
  __int64 v73; // r11
  modelQuery_t *v74; // r3
  queryParms_t *v75; // r11
  float *v76; // r11
  float *v77; // r11
  float *v78; // r11
  float *v79; // r11
  float *v80; // r11
  float *v81; // r11
  unsigned __int64 offset; // r5 OVERLAPPED
  __int64 v83; // r7 OVERLAPPED
  __int64 v84; // r15
  int v85; // r19
  const idTraceModel **v86; // r18
  int v87; // r23
  const idPositionedCollisionModel *v88; // r24
  modelQuery_t *v89; // r3
  queryParms_t *v90; // r11
  float *v91; // r11
  float *v92; // r11
  float *v93; // r11
  float *v94; // r11
  float *v95; // r11
  float *v96; // r11
  const idTraceModel *v97; // r5
  unsigned __int64 v98; // r5 OVERLAPPED
  __int64 v99; // r7 OVERLAPPED
  int v100; // r19
  const idTraceModel **v101; // r18
  int v102; // r23
  const idPositionedCollisionModel *v103; // r24
  modelQuery_t *v104; // r3
  queryParms_t *v105; // r11
  __int128 v106; // r6
  float *v107; // r11
  float *v108; // r11
  float *v109; // r11
  float *v110; // r11
  float *v111; // r11
  float *p_trmAxis; // r11
  const idTraceModel *v113; // r5
  int v114; // r18
  int v115; // r23
  const idPositionedCollisionModel *v116; // r24
  modelQuery_t *v117; // r3
  queryParms_t *v118; // r11
  float *v119; // r11
  float *v120; // r11
  float *v121; // r11
  float *v122; // r11
  float *v123; // r11
  float *v124; // r11
  const idTraceModel *v125; // r5
  __int128 v126; // r7
  __int64 v127; // r11
  const idBounds *v128; // [sp+8h] [-118h]
  int *v129; // [sp+Ch] [-114h]
  int v130; // [sp+10h] [-110h]
  int v131; // [sp+14h] [-10Ch]
  int v132; // [sp+18h] [-108h]
  int v133; // [sp+1Ch] [-104h]
  int v134; // [sp+20h] [-100h]
  int v135; // [sp+24h] [-FCh]
  int v136; // [sp+28h] [-F8h]
  int v137; // [sp+2Ch] [-F4h]
  int v138; // [sp+30h] [-F0h]
  int v139; // [sp+34h] [-ECh]
  int v140; // [sp+38h] [-E8h]
  int v141; // [sp+3Ch] [-E4h]
  int v142; // [sp+40h] [-E0h]
  int v143; // [sp+44h] [-DCh]
  int v144; // [sp+48h] [-D8h]
  int v145; // [sp+4Ch] [-D4h]
  int v146; // [sp+50h] [-D0h]
  int v147; // [sp+58h] [-C8h]
  int v148[2]; // [sp+60h] [-C0h] BYREF
  __int64 v149; // [sp+68h] [-B8h] BYREF

  v41 = numTrms_0;
  v49 = (const idBounds *)numTrms;
  if ( numTrms_0 <= 0 )
  {
    HIDWORD(numTrms) = trmAxisa;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      result,
      type2: 0x100000007uLL,
      endpos: end,
      endAxis: (const idMat3 *)a33,
      userName: numTrms);
    return this;
  }
  v51 = 0;
  v52 = nullptr;
  v148[0] = 0;
  v53 = 1;
  if ( a31 > 0 )
  {
    v54 = a29;
    while ( 2 )
    {
      v55 = numTrms_0 - 1;
      v56 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
      do
      {
        v58 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v56);
        if ( v58 == nullptr )
        {
          LODWORD(v57) = 0;
          *(_QWORD *)&this->queryData = v57;
          return this;
        }
        parms = v58->parms;
        v58->type = TRACE_TRANSLATION;
        parms->type = TRACE_TRANSLATION;
        v60 = (float *)v58->parms;
        v60[4] = start->x;
        v60[5] = start->y;
        v60[6] = start->z;
        v61 = (float *)v58->parms;
        v61[7] = end->x;
        v61[8] = end->y;
        v61[9] = end->z;
        v62 = (float *)v58->parms;
        v62[12] = 0.0;
        v62[11] = 0.0;
        v62[10] = 0.0;
        v63 = (float *)v58->parms;
        v63[15] = 0.0;
        v63[14] = 0.0;
        v63[13] = 0.0;
        v58->parms->rotationAngle = 0.0;
        v64 = (float *)v58->parms;
        v64[17] = downNormal->x;
        v64[18] = downNormal->y;
        v64[19] = downNormal->z;
        v58->parms->depth = 0.0;
        v65 = (float *)v58->parms;
        v65[21] = *(float *)a33;
        v65[22] = *(float *)(a33 + 4);
        v65[23] = *(float *)(a33 + 8);
        v65[24] = *(float *)(a33 + 12);
        v65[25] = *(float *)(a33 + 16);
        v65[26] = *(float *)(a33 + 20);
        v65[27] = *(float *)(a33 + 24);
        v65[28] = *(float *)(a33 + 28);
        v65[29] = *(float *)(a33 + 32);
        v58->parms->contentMask = a35;
        v58->parms->selfId = v51;
        v58->userName = (const char *)trmAxisa;
        v58->trm = *v54;
        v58->nextOnQuery = v52;
        v52 = v58;
        *(_QWORD *)((char *)&v66 + 4) = v56->modelQuery.offset;
        LODWORD(v66) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v56->modelQuery.offset),
          dependency1: v66,
          dependency2: null_query.offset,
          dependencyType: DEPENDENCY_NONE,
          globalStart: start,
          globalEnd: end,
          globalBounds: v128,
          mergePriority: v129,
          a10: v130,
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
          a27: v49,
          a28: v147,
          a29: v148);
        --v55;
        --v56;
      }
      while ( v55 >= 0 );
      ++v51;
      ++v54;
      if ( v51 < a31 )
        continue;
      break;
    }
    v41 = numTrms_0;
  }
  idCollisionQueryJobManager::AddModelQueryToMergeList(
    this: (idCollisionQueryJobManager *)&v149,
    result,
    mergePriority: __PAIR64__((unsigned int)v52, v148[0]),
    slideMoveState: nullptr);
  v67 = v149;
  if ( (_DWORD)v149 == 0 )
  {
    *(_QWORD *)&this->queryData = v149;
    return this;
  }
  v68 = 0;
  if ( a31 > 0 )
  {
    v69 = a29;
    v70 = v41 - 1;
    while ( 1 )
    {
      v71 = v70;
      if ( v70 >= 0 )
        break;
LABEL_19:
      ++v68;
      ++v69;
      if ( v68 >= a31 )
        goto LABEL_20;
    }
    v72 = (const idPositionedCollisionModel *)&trms_0[20 * v70];
    while ( 1 )
    {
      v74 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v72);
      if ( v74 == nullptr )
        goto LABEL_45;
      v75 = v74->parms;
      v74->type = TRACE_TRANSLATION;
      v75->type = TRACE_TRANSLATION;
      v76 = (float *)v74->parms;
      v76[4] = start->x;
      v76[5] = start->y;
      v76[6] = start->z;
      v77 = (float *)v74->parms;
      v77[7] = end->x;
      v77[8] = end->y;
      v77[9] = end->z;
      v78 = (float *)v74->parms;
      v78[12] = 0.0;
      v78[10] = 0.0;
      v78[11] = 0.0;
      v79 = (float *)v74->parms;
      v79[14] = 0.0;
      v79[13] = 0.0;
      v79[15] = 0.0;
      v74->parms->rotationAngle = 0.0;
      v80 = (float *)v74->parms;
      v80[17] = downNormal->x;
      v80[18] = downNormal->y;
      v80[19] = downNormal->z;
      v74->parms->depth = -stepUp;
      v81 = (float *)v74->parms;
      v81[21] = *(float *)a33;
      v81[22] = *(float *)(a33 + 4);
      v81[23] = *(float *)(a33 + 8);
      v81[24] = *(float *)(a33 + 12);
      v81[25] = *(float *)(a33 + 16);
      v81[26] = *(float *)(a33 + 20);
      v81[27] = *(float *)(a33 + 24);
      v81[28] = *(float *)(a33 + 28);
      v81[29] = *(float *)(a33 + 32);
      v74->parms->contentMask = a35;
      v74->parms->selfId = v68;
      v74->userName = (const char *)trmAxisa;
      v74->trm = *v69;
      v74->nextOnQuery = v52;
      v52 = v74;
      offset = v72->modelQuery.offset;
      v83 = *(_QWORD *)(HIDWORD(v67) - 17560);
      idCollisionQueryJobManager::AddModelQueryToExecuteList(
        this: (idCollisionQueryJobManager *)result,
        modelQuery: (modelQuery_t *)HIDWORD(v72->modelQuery.offset),
        dependency1: *(unsigned __int64 *)((char *)&offset - 4),
        dependency2: *(_DWORD *)(HIDWORD(v67) - 17556),
        dependencyType: DEPENDENCY_STEPMOVE_STEP_UP,
        globalStart: start,
        globalEnd: end,
        globalBounds: v128,
        mergePriority: v129,
        a10: v130,
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
        a27: v49,
        a28: v147,
        a29: v148);
      --v71;
      --v72;
      if ( v71 < 0 )
        goto LABEL_19;
    }
  }
LABEL_20:
  idCollisionQueryJobManager::AddModelQueryToMergeList(
    this: (idCollisionQueryJobManager *)&v149,
    result,
    mergePriority: __PAIR64__((unsigned int)v52, v148[0]),
    slideMoveState: nullptr);
  v84 = v149;
  if ( (_DWORD)v149 != 0 )
  {
    v85 = 0;
    if ( SHIDWORD(v149) > 0 )
    {
      v86 = a29;
LABEL_23:
      v87 = numTrms_0 - 1;
      v88 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
      while ( 1 )
      {
        v89 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v88);
        if ( v89 == nullptr )
          goto LABEL_45;
        v90 = v89->parms;
        v89->type = TRACE_TRANSLATION;
        v90->type = TRACE_TRANSLATION;
        v91 = (float *)v89->parms;
        v91[4] = start->x;
        v91[5] = start->y;
        v91[6] = start->z;
        v92 = (float *)v89->parms;
        v92[7] = end->x;
        v92[8] = end->y;
        v92[9] = end->z;
        v93 = (float *)v89->parms;
        v93[12] = 0.0;
        v93[11] = 0.0;
        v93[10] = 0.0;
        v94 = (float *)v89->parms;
        v94[15] = 0.0;
        v94[14] = 0.0;
        v94[13] = 0.0;
        v89->parms->rotationAngle = 0.0;
        v95 = (float *)v89->parms;
        v95[17] = downNormal->x;
        v95[18] = downNormal->y;
        v95[19] = downNormal->z;
        v89->parms->depth = -stepUp;
        v96 = (float *)v89->parms;
        v96[21] = *(float *)a33;
        v96[22] = *(float *)(a33 + 4);
        v96[23] = *(float *)(a33 + 8);
        v96[24] = *(float *)(a33 + 12);
        v96[25] = *(float *)(a33 + 16);
        v96[26] = *(float *)(a33 + 20);
        v96[27] = *(float *)(a33 + 24);
        v96[28] = *(float *)(a33 + 28);
        v96[29] = *(float *)(a33 + 32);
        v89->parms->contentMask = a35;
        v89->parms->selfId = v85;
        v89->userName = (const char *)trmAxisa;
        v97 = *v86;
        v89->nextOnQuery = v52;
        v52 = v89;
        v89->trm = v97;
        v98 = v88->modelQuery.offset;
        v99 = *(_QWORD *)(HIDWORD(v67) - 17560);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v88->modelQuery.offset),
          dependency1: *(unsigned __int64 *)((char *)&v98 - 4),
          dependency2: *(_DWORD *)(HIDWORD(v67) - 17556),
          dependencyType: DEPENDENCY_STEPMOVE_2ND_MOVE,
          globalStart: start,
          globalEnd: end,
          globalBounds: v128,
          mergePriority: v129,
          a10: v130,
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
          a27: v49,
          a28: v147,
          a29: v148);
        --v87;
        --v88;
        if ( v87 < 0 )
        {
          ++v85;
          ++v86;
          if ( v85 < a31 )
            goto LABEL_23;
          break;
        }
      }
    }
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v149,
      result,
      mergePriority: __PAIR64__((unsigned int)v52, v148[0]),
      slideMoveState: nullptr);
    v84 = v149;
    if ( (_DWORD)v149 != 0 )
    {
      v100 = 0;
      if ( SHIDWORD(v149) > 0 )
      {
        v101 = a29;
LABEL_30:
        v102 = numTrms_0 - 1;
        v103 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
        while ( 1 )
        {
          v104 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v103);
          if ( v104 == nullptr )
            goto LABEL_45;
          v105 = v104->parms;
          v104->type = TRACE_TRANSLATION;
          v105->type = TRACE_TRANSLATION;
          LODWORD(v106) = v84;
          v107 = (float *)v104->parms;
          v107[4] = start->x;
          v107[5] = start->y;
          v107[6] = start->z;
          v108 = (float *)v104->parms;
          v108[7] = end->x;
          v108[8] = end->y;
          v108[9] = end->z;
          v109 = (float *)v104->parms;
          v109[12] = 0.0;
          v109[11] = 0.0;
          v109[10] = 0.0;
          v110 = (float *)v104->parms;
          v110[15] = 0.0;
          v110[14] = 0.0;
          v110[13] = 0.0;
          v104->parms->rotationAngle = 0.0;
          v111 = (float *)v104->parms;
          v111[17] = downNormal->x;
          v111[18] = downNormal->y;
          v111[19] = downNormal->z;
          v104->parms->depth = stepDown;
          p_trmAxis = (float *)&v104->parms->trmAxis;
          *p_trmAxis = *(float *)a33;
          p_trmAxis[1] = *(float *)(a33 + 4);
          p_trmAxis[2] = *(float *)(a33 + 8);
          p_trmAxis[3] = *(float *)(a33 + 12);
          p_trmAxis[4] = *(float *)(a33 + 16);
          p_trmAxis[5] = *(float *)(a33 + 20);
          p_trmAxis[6] = *(float *)(a33 + 24);
          p_trmAxis[7] = *(float *)(a33 + 28);
          p_trmAxis[8] = *(float *)(a33 + 32);
          v104->parms->contentMask = a35;
          v104->parms->selfId = v100;
          v104->userName = (const char *)trmAxisa;
          v113 = *v101;
          v104->nextOnQuery = v52;
          v52 = v104;
          v104->trm = v113;
          *(_QWORD *)((char *)&v106 + 4) = v103->modelQuery.offset;
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: (idCollisionQueryJobManager *)result,
            modelQuery: (modelQuery_t *)HIDWORD(v103->modelQuery.offset),
            dependency1: v106,
            dependency2: v67,
            dependencyType: DEPENDENCY_STEPMOVE_STEP_DOWN,
            globalStart: start,
            globalEnd: end,
            globalBounds: v128,
            mergePriority: v129,
            a10: v130,
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
            a27: v49,
            a28: v147,
            a29: v148);
          --v102;
          --v103;
          if ( v102 < 0 )
          {
            ++v100;
            ++v101;
            if ( v100 < a31 )
              goto LABEL_30;
            break;
          }
        }
      }
      idCollisionQueryJobManager::AddModelQueryToMergeList(
        this: (idCollisionQueryJobManager *)&v149,
        result,
        mergePriority: __PAIR64__((unsigned int)v52, v148[0]),
        slideMoveState: nullptr);
      v84 = v149;
      if ( (_DWORD)v149 != 0 )
      {
        v114 = 0;
        if ( SHIDWORD(v149) > 0 )
        {
          LODWORD(v67) = a29;
          HIDWORD(v84) = numTrms_0 - 1;
LABEL_37:
          v115 = numTrms_0 - 1;
          v116 = (const idPositionedCollisionModel *)&trms_0[20 * HIDWORD(v84)];
          while ( 1 )
          {
            v117 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v116);
            if ( v117 == nullptr )
              break;
            v118 = v117->parms;
            v117->type = TRACE_CONTACTS_UNI_DIR;
            v118->type = TRACE_CONTACTS_UNI_DIR;
            v119 = (float *)v117->parms;
            v119[4] = start->x;
            v119[5] = start->y;
            v119[6] = start->z;
            v120 = (float *)v117->parms;
            v120[7] = start->x;
            v120[8] = start->y;
            v120[9] = start->z;
            v121 = (float *)v117->parms;
            v121[12] = 0.0;
            v121[11] = 0.0;
            v121[10] = 0.0;
            v122 = (float *)v117->parms;
            v122[15] = 0.0;
            v122[14] = 0.0;
            v122[13] = 0.0;
            v117->parms->rotationAngle = 0.0;
            v123 = (float *)v117->parms;
            v123[17] = downNormal->x;
            v123[18] = downNormal->y;
            v123[19] = downNormal->z;
            v117->parms->depth = 0.5;
            v124 = (float *)&v117->parms->trmAxis;
            *v124 = *(float *)a33;
            v124[1] = *(float *)(a33 + 4);
            v124[2] = *(float *)(a33 + 8);
            v124[3] = *(float *)(a33 + 12);
            v124[4] = *(float *)(a33 + 16);
            v124[5] = *(float *)(a33 + 20);
            v124[6] = *(float *)(a33 + 24);
            v124[7] = *(float *)(a33 + 28);
            v124[8] = *(float *)(a33 + 32);
            v117->parms->contentMask = a35;
            v117->parms->selfId = v114;
            v117->userName = (const char *)trmAxisa;
            v125 = *(const idTraceModel **)v67;
            v117->nextOnQuery = v52;
            v52 = v117;
            v117->trm = v125;
            *((_QWORD *)&v126 + 1) = *(_QWORD *)(HIDWORD(v67) - 17560);
            *(_QWORD *)&v126 = v116->modelQuery.offset;
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: (idCollisionQueryJobManager *)result,
              modelQuery: (modelQuery_t *)HIDWORD(v116->modelQuery.offset),
              dependency1: *(unsigned __int64 *)((char *)&v126 + 4),
              dependency2: *(_DWORD *)(HIDWORD(v67) - 17556),
              dependencyType: DEPENDENCY_STEPMOVE_CONTACTS,
              globalStart: start,
              globalEnd: end,
              globalBounds: v128,
              mergePriority: v129,
              a10: v130,
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
              a27: v49,
              a28: v147,
              a29: v148);
            --v115;
            --v116;
            if ( v115 < 0 )
            {
              ++v114;
              LODWORD(v67) = v67 + 4;
              if ( v114 < a31 )
                goto LABEL_37;
              goto LABEL_41;
            }
          }
LABEL_45:
          LODWORD(v73) = 0;
          *(_QWORD *)&this->queryData = v73;
          return this;
        }
LABEL_41:
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: (idCollisionQueryJobManager *)&v149,
          result,
          mergePriority: __PAIR64__((unsigned int)v52, v148[0]),
          slideMoveState: nullptr);
        LODWORD(v127) = v149;
        if ( (_DWORD)v149 != 0 )
          v53 = 0;
        if ( v53 != 0 )
        {
          HIDWORD(v127) = v53;
          *(_QWORD *)&this->queryData = v127;
          return this;
        }
      }
    }
  }
  *(_QWORD *)&this->queryData = v84;
  return this;
}


// ========================================================================
// ?SubmitSlideMoveQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@00MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825E1378
// RVA : 0x005E1378
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitSlideMoveQuery(
        idCollisionQueryJobManager *this,
        idCollisionQueryJobManager *result,
        const idVec3 *start,
        const idVec3 *velocity,
        const idVec3 *gravityVector,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        __int64 numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
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
        const idTraceModel **a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        const idTraceModel **trms_0,
        int a38,
        int numTrms_0,
        int a40,
        const idMat3 *trmAxisa)
{
  idCollisionQueryJobManager *v41; // r25
  const idBounds *v48; // r21
  unsigned __int64 v49; // r6
  double v50; // fp11
  double v51; // fp8
  double v52; // fp6
  __int64 v53; // r11
  slideMoveState_t *v54; // r3
  slideMoveState_t *v55; // r26
  __int64 v56; // r15
  double v57; // fp9
  double v58; // fp7
  int v59; // r17
  modelQuery_t *v60; // r28
  char v61; // r11
  int v62; // r14
  int v63; // r20
  dependencyType_t v64; // r18
  const idTraceModel **v65; // r19
  int v66; // r25
  const idPositionedCollisionModel *v67; // r26
  __int64 v68; // r11
  modelQuery_t *v69; // r3
  queryParms_t *parms; // r11
  float *v71; // r11
  float *v72; // r11
  float *v73; // r11
  float *v74; // r11
  float *v75; // r11
  __int128 v76; // r6
  __int64 v77; // r16
  int v78; // r20
  const idTraceModel **v79; // r19
  int v80; // r25
  const idPositionedCollisionModel *v81; // r26
  modelQuery_t *v82; // r3
  queryParms_t *v83; // r11
  float *v84; // r11
  float *v85; // r11
  float *v86; // r11
  float *v87; // r11
  float *v88; // r11
  const idTraceModel *v89; // r7
  __int128 v90; // r6
  __int64 v91; // r18
  int v92; // r20
  const idTraceModel **v93; // r19
  int v94; // r25
  const idPositionedCollisionModel *v95; // r26
  modelQuery_t *v96; // r3
  queryParms_t *v97; // r11
  __int128 v98; // r6
  float *v99; // r11
  float *v100; // r11
  float *v101; // r11
  float *v102; // r11
  float *v103; // r11
  int v104; // r20
  const idTraceModel **v105; // r19
  int v106; // r25
  const idPositionedCollisionModel *v107; // r26
  modelQuery_t *v108; // r3
  queryParms_t *v109; // r11
  __int128 v110; // r6
  float *v111; // r11
  float *v112; // r11
  float *v113; // r11
  float *v114; // r11
  float *p_trmAxis; // r11
  const idTraceModel *v116; // r5
  idCollisionQueryJobManager *v117; // r3
  const idBounds *v119; // [sp+8h] [-148h]
  int *v120; // [sp+Ch] [-144h]
  int v121; // [sp+10h] [-140h]
  int v122; // [sp+14h] [-13Ch]
  int v123; // [sp+18h] [-138h]
  int v124; // [sp+1Ch] [-134h]
  int v125; // [sp+20h] [-130h]
  int v126; // [sp+24h] [-12Ch]
  int v127; // [sp+28h] [-128h]
  int v128; // [sp+2Ch] [-124h]
  int v129; // [sp+30h] [-120h]
  int v130; // [sp+34h] [-11Ch]
  int v131; // [sp+38h] [-118h]
  int v132; // [sp+3Ch] [-114h]
  int v133; // [sp+40h] [-110h]
  int v134; // [sp+44h] [-10Ch]
  int v135; // [sp+48h] [-108h]
  int v136; // [sp+4Ch] [-104h]
  int v137; // [sp+50h] [-100h]
  int v138; // [sp+58h] [-F8h]
  unsigned int v139; // [sp+60h] [-F0h] BYREF
  slideMoveState_t *v140; // [sp+64h] [-ECh]
  __int64 v141; // [sp+68h] [-E8h] BYREF
  __int64 v142; // [sp+70h] [-E0h] BYREF
  __int64 v143; // [sp+78h] [-D8h] BYREF
  idVec3 v144; // [sp+80h] [-D0h] BYREF
  idVec3 v145; // [sp+90h] [-C0h] BYREF

  v41 = this;
  v48 = (const idBounds *)numTrms;
  if ( numTrms_0 > 0 )
  {
    v54 = idQueryData::AllocSlideMoveState(this: result->queryData);
    v55 = v54;
    v140 = v54;
    if ( v54 != nullptr )
    {
      idCollisionDetectionMerge::InitSlideMoveState(state: v54, velocity, gravityVector);
      LODWORD(v56) = 0;
      v57 = (float)(v55->velocity.z + start->z);
      v58 = (float)(v55->velocity.y + start->y);
      v145.x = start->x + v55->velocity.x;
      v59 = 11;
      v145.z = v57;
      v139 = 0;
      v145.y = v58;
      v60 = nullptr;
      while ( 1 )
      {
        if ( (unsigned int)v56 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset
          || (v61 = 1, (unsigned int)v56 > (unsigned int)idCollisionQuery::finalResultsLastAllocedOffset) )
        {
          v61 = 0;
        }
        v62 = a31;
        v63 = 0;
        v64 = v61 == 0 ? DEPENDENCY_NONE : DEPENDENCY_SLIDEMOVE_SLIDE;
        if ( a31 > 0 )
        {
          v65 = a29;
LABEL_11:
          v66 = numTrms_0 - 1;
          v67 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
          while ( 1 )
          {
            v69 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v67);
            if ( v69 == nullptr )
              goto LABEL_44;
            parms = v69->parms;
            v69->type = TRACE_TRANSLATION;
            parms->type = TRACE_TRANSLATION;
            v71 = (float *)v69->parms;
            v71[4] = start->x;
            v71[5] = start->y;
            v71[6] = start->z;
            v69->parms->end = v145;
            v72 = (float *)v69->parms;
            v72[12] = 0.0;
            v72[11] = 0.0;
            v72[10] = 0.0;
            v73 = (float *)v69->parms;
            v73[15] = 0.0;
            v73[14] = 0.0;
            v73[13] = 0.0;
            v69->parms->rotationAngle = 0.0;
            v74 = (float *)v69->parms;
            v74[17] = gravityVector->x;
            v74[18] = gravityVector->y;
            v74[19] = gravityVector->z;
            v69->parms->depth = 0.0;
            v75 = (float *)v69->parms;
            v75[21] = *(float *)a33;
            v75[22] = *(float *)(a33 + 4);
            v75[23] = *(float *)(a33 + 8);
            v75[24] = *(float *)(a33 + 12);
            v75[25] = *(float *)(a33 + 16);
            v75[26] = *(float *)(a33 + 20);
            v75[27] = *(float *)(a33 + 24);
            v75[28] = *(float *)(a33 + 28);
            v75[29] = *(float *)(a33 + 32);
            v69->parms->contentMask = a35;
            v69->parms->selfId = v63;
            v69->userName = (const char *)trmAxisa;
            v69->trm = *v65;
            v69->nextOnQuery = v60;
            v60 = v69;
            *(_QWORD *)((char *)&v76 + 4) = v67->modelQuery.offset;
            LODWORD(v76) = HIDWORD(null_query.offset);
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: result,
              modelQuery: (modelQuery_t *)HIDWORD(v67->modelQuery.offset),
              dependency1: v76,
              dependency2: null_query.offset,
              dependencyType: v64,
              globalStart: start,
              globalEnd: &v145,
              globalBounds: v119,
              mergePriority: v120,
              a10: v121,
              a11: v122,
              a12: v123,
              a13: v124,
              a14: v125,
              a15: v126,
              a16: v127,
              a17: v128,
              a18: v129,
              a19: v130,
              a20: v131,
              a21: v132,
              a22: v133,
              a23: v134,
              a24: v135,
              a25: v136,
              a26: v137,
              a27: v48,
              a28: v138,
              a29: (int *)&v139);
            --v66;
            --v67;
            if ( v66 < 0 )
            {
              v55 = v140;
              ++v63;
              ++v65;
              if ( v63 < a31 )
                goto LABEL_11;
              v41 = this;
              break;
            }
          }
        }
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: (idCollisionQueryJobManager *)&v141,
          (idCollisionQuery *)result,
          mergePriority: __PAIR64__((unsigned int)v60, v139),
          slideMoveState: v55);
        v77 = v141;
        if ( (_DWORD)v141 == 0 )
        {
          *(_QWORD *)&v41->queryData = v141;
          return v41;
        }
        v78 = 0;
        if ( a31 > 0 )
        {
          v79 = a29;
LABEL_19:
          v80 = numTrms_0 - 1;
          v81 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
          while ( 1 )
          {
            v82 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v81);
            if ( v82 == nullptr )
              goto LABEL_44;
            v83 = v82->parms;
            v82->type = TRACE_TRANSLATION;
            v83->type = TRACE_TRANSLATION;
            v84 = (float *)v82->parms;
            v84[4] = start->x;
            v84[5] = start->y;
            v84[6] = start->z;
            v82->parms->end = v145;
            v85 = (float *)v82->parms;
            v85[12] = 0.0;
            v85[11] = 0.0;
            v85[10] = 0.0;
            v86 = (float *)v82->parms;
            v86[13] = 0.0;
            v86[15] = 0.0;
            v86[14] = 0.0;
            v82->parms->rotationAngle = 0.0;
            v87 = (float *)v82->parms;
            v87[17] = gravityVector->x;
            v87[18] = gravityVector->y;
            v87[19] = gravityVector->z;
            v82->parms->depth = -stepUp;
            v88 = (float *)v82->parms;
            v88[21] = *(float *)a33;
            v88[22] = *(float *)(a33 + 4);
            v88[23] = *(float *)(a33 + 8);
            v88[24] = *(float *)(a33 + 12);
            v88[25] = *(float *)(a33 + 16);
            v88[26] = *(float *)(a33 + 20);
            v88[27] = *(float *)(a33 + 24);
            v88[28] = *(float *)(a33 + 28);
            v88[29] = *(float *)(a33 + 32);
            v82->parms->contentMask = a35;
            v82->parms->selfId = v78;
            v82->userName = (const char *)trmAxisa;
            v89 = *v79;
            v82->nextOnQuery = v60;
            v60 = v82;
            v82->trm = v89;
            *(_QWORD *)((char *)&v90 + 4) = v81->modelQuery.offset;
            LODWORD(v90) = HIDWORD(null_query.offset);
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: result,
              modelQuery: (modelQuery_t *)HIDWORD(v81->modelQuery.offset),
              dependency1: v90,
              dependency2: null_query.offset,
              dependencyType: (dependencyType_t)(v59 - 4),
              globalStart: start,
              globalEnd: &v145,
              globalBounds: v119,
              mergePriority: v120,
              a10: v121,
              a11: v122,
              a12: v123,
              a13: v124,
              a14: v125,
              a15: v126,
              a16: v127,
              a17: v128,
              a18: v129,
              a19: v130,
              a20: v131,
              a21: v132,
              a22: v133,
              a23: v134,
              a24: v135,
              a25: v136,
              a26: v137,
              a27: v48,
              a28: v138,
              a29: (int *)&v139);
            --v80;
            --v81;
            if ( v80 < 0 )
            {
              v55 = v140;
              ++v78;
              ++v79;
              if ( v78 < a31 )
                goto LABEL_19;
              v41 = this;
              break;
            }
          }
        }
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: (idCollisionQueryJobManager *)&v142,
          (idCollisionQuery *)result,
          mergePriority: __PAIR64__((unsigned int)v60, v139),
          slideMoveState: v55);
        v91 = v142;
        if ( (_DWORD)v142 == 0 )
          break;
        v92 = 0;
        if ( a31 > 0 )
        {
          v93 = a29;
LABEL_27:
          v94 = numTrms_0 - 1;
          v95 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
          while ( 1 )
          {
            v96 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v95);
            if ( v96 == nullptr )
              goto LABEL_44;
            v97 = v96->parms;
            v96->type = TRACE_TRANSLATION;
            v97->type = TRACE_TRANSLATION;
            LODWORD(v98) = v91;
            v99 = (float *)v96->parms;
            v99[4] = start->x;
            v99[5] = start->y;
            v99[6] = start->z;
            v96->parms->end = v145;
            v100 = (float *)v96->parms;
            v100[12] = 0.0;
            v100[11] = 0.0;
            v100[10] = 0.0;
            v101 = (float *)v96->parms;
            v101[15] = 0.0;
            v101[14] = 0.0;
            v101[13] = 0.0;
            v96->parms->rotationAngle = 0.0;
            v102 = (float *)v96->parms;
            v102[17] = gravityVector->x;
            v102[18] = gravityVector->y;
            v102[19] = gravityVector->z;
            v96->parms->depth = -stepUp;
            v103 = (float *)v96->parms;
            v103[21] = *(float *)a33;
            v103[22] = *(float *)(a33 + 4);
            v103[23] = *(float *)(a33 + 8);
            v103[24] = *(float *)(a33 + 12);
            v103[25] = *(float *)(a33 + 16);
            v103[26] = *(float *)(a33 + 20);
            v103[27] = *(float *)(a33 + 24);
            v103[28] = *(float *)(a33 + 28);
            v103[29] = *(float *)(a33 + 32);
            v96->parms->contentMask = a35;
            v96->parms->selfId = v92;
            v96->userName = (const char *)trmAxisa;
            v96->trm = *v93;
            v96->nextOnQuery = v60;
            v60 = v96;
            *(_QWORD *)((char *)&v98 + 4) = v95->modelQuery.offset;
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: result,
              modelQuery: (modelQuery_t *)HIDWORD(v95->modelQuery.offset),
              dependency1: v98,
              dependency2: HIDWORD(v77),
              dependencyType: SHIDWORD(v91),
              globalStart: start,
              globalEnd: &v145,
              globalBounds: v119,
              mergePriority: v120,
              a10: v121,
              a11: v122,
              a12: v123,
              a13: v124,
              a14: v125,
              a15: v126,
              a16: v127,
              a17: v128,
              a18: v129,
              a19: v130,
              a20: v131,
              a21: v132,
              a22: v133,
              a23: v134,
              a24: v135,
              a25: v136,
              a26: v137,
              a27: v48,
              a28: v138,
              a29: (int *)&v139);
            --v94;
            --v95;
            if ( v94 < 0 )
            {
              ++v92;
              ++v93;
              if ( v92 < a31 )
                goto LABEL_27;
              v55 = v140;
              v62 = a31;
              v41 = this;
              break;
            }
          }
        }
        idCollisionQueryJobManager::AddModelQueryToMergeList(
          this: (idCollisionQueryJobManager *)&v143,
          (idCollisionQuery *)result,
          mergePriority: __PAIR64__((unsigned int)v60, v139),
          slideMoveState: v55);
        v91 = v143;
        if ( (_DWORD)v143 == 0 )
          break;
        v104 = 0;
        if ( v62 > 0 )
        {
          v105 = a29;
LABEL_35:
          v106 = numTrms_0 - 1;
          v107 = (const idPositionedCollisionModel *)&trms_0[20 * numTrms_0 - 20];
          while ( 1 )
          {
            v108 = idCollisionQueryJobManager::AllocModelQuery(this: result, model: v107);
            if ( v108 == nullptr )
              break;
            v109 = v108->parms;
            v108->type = TRACE_TRANSLATION;
            v109->type = TRACE_TRANSLATION;
            LODWORD(v110) = v91;
            v111 = (float *)v108->parms;
            v111[4] = start->x;
            v111[5] = start->y;
            v111[6] = start->z;
            v108->parms->end = v145;
            v112 = (float *)v108->parms;
            v112[12] = 0.0;
            v112[11] = 0.0;
            v112[10] = 0.0;
            v113 = (float *)v108->parms;
            v113[15] = 0.0;
            v113[14] = 0.0;
            v113[13] = 0.0;
            v108->parms->rotationAngle = 0.0;
            v114 = (float *)v108->parms;
            v114[17] = gravityVector->x;
            v114[18] = gravityVector->y;
            v114[19] = gravityVector->z;
            v108->parms->depth = stepDown;
            p_trmAxis = (float *)&v108->parms->trmAxis;
            *p_trmAxis = *(float *)a33;
            p_trmAxis[1] = *(float *)(a33 + 4);
            p_trmAxis[2] = *(float *)(a33 + 8);
            p_trmAxis[3] = *(float *)(a33 + 12);
            p_trmAxis[4] = *(float *)(a33 + 16);
            p_trmAxis[5] = *(float *)(a33 + 20);
            p_trmAxis[6] = *(float *)(a33 + 24);
            p_trmAxis[7] = *(float *)(a33 + 28);
            p_trmAxis[8] = *(float *)(a33 + 32);
            v108->parms->contentMask = a35;
            v108->parms->selfId = v104;
            v108->userName = (const char *)trmAxisa;
            v116 = *v105;
            v108->nextOnQuery = v60;
            v60 = v108;
            v108->trm = v116;
            *(_QWORD *)((char *)&v110 + 4) = v107->modelQuery.offset;
            idCollisionQueryJobManager::AddModelQueryToExecuteList(
              this: result,
              modelQuery: (modelQuery_t *)HIDWORD(v107->modelQuery.offset),
              dependency1: v110,
              dependency2: v77,
              dependencyType: (dependencyType_t)(HIDWORD(v91) + 4),
              globalStart: start,
              globalEnd: &v145,
              globalBounds: v119,
              mergePriority: v120,
              a10: v121,
              a11: v122,
              a12: v123,
              a13: v124,
              a14: v125,
              a15: v126,
              a16: v127,
              a17: v128,
              a18: v129,
              a19: v130,
              a20: v131,
              a21: v132,
              a22: v133,
              a23: v134,
              a24: v135,
              a25: v136,
              a26: v137,
              a27: v48,
              a28: v138,
              a29: (int *)&v139);
            --v106;
            --v107;
            if ( v106 < 0 )
            {
              v55 = v140;
              ++v104;
              ++v105;
              if ( v104 < v62 )
                goto LABEL_35;
              v41 = this;
              goto LABEL_40;
            }
          }
LABEL_44:
          LODWORD(v68) = 0;
          *(_QWORD *)&this->queryData = v68;
          return this;
        }
LABEL_40:
        v117 = idCollisionQueryJobManager::AddModelQueryToMergeList(
                 this: (idCollisionQueryJobManager *)&v144,
                 (idCollisionQuery *)result,
                 mergePriority: __PAIR64__((unsigned int)v60, v139),
                 slideMoveState: v55);
        v56 = *(_QWORD *)&v117->queryData;
        if ( v117->dummyQueryResults != nullptr )
        {
          v59 = HIDWORD(v91) + 1;
          if ( v59 < 15 )
            continue;
        }
        *(_QWORD *)&v41->queryData = v56;
        return v41;
      }
      *(_QWORD *)&v41->queryData = v91;
    }
    else
    {
      LODWORD(v53) = 0;
      *(_QWORD *)&v41->queryData = v53;
    }
  }
  else
  {
    v50 = (float)(start->x + velocity->x);
    LODWORD(v49) = 0;
    v51 = (float)(start->y + velocity->y);
    HIDWORD(v49) = 1;
    HIDWORD(numTrms) = trmAxisa;
    v52 = (float)(start->z + velocity->z);
    v144.x = v50;
    v144.y = v51;
    v144.z = v52;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      (idCollisionQuery *)result,
      type2: v49,
      endpos: &v144,
      endAxis: (const idMat3 *)a33,
      userName: numTrms);
  }
  return v41;
}


// ========================================================================
// ?SubmitSlideMoveContactsQuery@idCollisionQueryJobManager@@QAA?AVidCollisionQuery@@ABVidVec3@@00MMABVidBounds@@QAPBVidTraceModel@@HABVidMat3@@HPBVidPositionedCollisionModel@@HPBD@Z
// EA  : 0x825E1CB0
// RVA : 0x005E1CB0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idCollisionQueryJobManager *__fastcall idCollisionQueryJobManager::SubmitSlideMoveContactsQuery(
        idCollisionQueryJobManager *this,
        idCollisionQuery *result,
        const idVec3 *start,
        const idVec3 *velocity,
        const idVec3 *gravityVector,
        double stepUp,
        double stepDown,
        const idBounds *globalBounds,
        __int64 numTrms,
        const idMat3 *trmAxis,
        const int contentMask,
        const idPositionedCollisionModel *models,
        const int numModels,
        const char *userName,
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
        const idTraceModel **a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        const idTraceModel **trms_0,
        int a38,
        int numTrms_0,
        int a40,
        const idMat3 *trmAxisa)
{
  int v41; // r24
  idCollisionQueryJobManager *v42; // r19
  const idBounds *v49; // r21
  unsigned __int64 v50; // r6
  double v51; // fp11
  double v52; // fp8
  double v53; // fp6
  __int64 v55; // r11
  slideMoveState_t *v56; // r3
  slideMoveState_t *v57; // r25
  __int64 v58; // r16
  double v59; // fp9
  double v60; // fp7
  int v61; // r17
  modelQuery_t *v62; // r28
  unsigned __int8 v63; // r27
  char v64; // r11
  int v65; // r20
  dependencyType_t v66; // r18
  const idTraceModel **v67; // r19
  int v68; // r15
  int v69; // r24
  const idPositionedCollisionModel *v70; // r25
  __int64 v71; // r11
  modelQuery_t *v72; // r3
  queryParms_t *parms; // r11
  float *v74; // r11
  float *v75; // r11
  float *v76; // r11
  float *v77; // r11
  float *v78; // r11
  __int128 v79; // r6
  __int64 v80; // r15
  int v81; // r20
  const idTraceModel **v82; // r19
  int v83; // r18
  int v84; // r24
  const idPositionedCollisionModel *v85; // r25
  modelQuery_t *v86; // r3
  queryParms_t *v87; // r11
  float *v88; // r11
  float *v89; // r11
  float *v90; // r11
  float *v91; // r11
  float *v92; // r11
  const idTraceModel *v93; // r7
  __int128 v94; // r6
  __int64 v95; // r18
  int v96; // r20
  const idTraceModel **v97; // r19
  int v98; // r14
  int v99; // r24
  const idPositionedCollisionModel *v100; // r25
  modelQuery_t *v101; // r3
  queryParms_t *v102; // r11
  __int128 v103; // r6
  float *v104; // r11
  float *v105; // r11
  float *v106; // r11
  float *v107; // r11
  float *v108; // r11
  int v109; // r20
  const idTraceModel **v110; // r19
  int v111; // r16
  int v112; // r24
  const idPositionedCollisionModel *v113; // r25
  modelQuery_t *v114; // r3
  queryParms_t *v115; // r11
  __int128 v116; // r6
  float *v117; // r11
  float *v118; // r11
  float *v119; // r11
  float *v120; // r11
  float *p_trmAxis; // r11
  const idTraceModel *v122; // r5
  idCollisionQueryJobManager *v123; // r3
  float y; // r9
  float x; // r11
  int v126; // r20
  double v129; // fp4
  double v130; // fp7
  double v131; // fp4
  double v132; // fp29
  double v133; // fp28
  double v134; // fp27
  int v135; // r18
  const idTraceModel **v136; // r19
  int v137; // r25
  const idPositionedCollisionModel *v138; // r29
  modelQuery_t *v139; // r3
  queryParms_t *v140; // r11
  float *v141; // r11
  float *v142; // r11
  float *v143; // r11
  float *v144; // r11
  float *v145; // r11
  float *v146; // r11
  const idTraceModel *v147; // r5
  __int128 v148; // r6
  const idBounds *v149; // [sp+8h] [-158h]
  int *v150; // [sp+Ch] [-154h]
  int v151; // [sp+10h] [-150h]
  int v152; // [sp+14h] [-14Ch]
  int v153; // [sp+18h] [-148h]
  int v154; // [sp+1Ch] [-144h]
  int v155; // [sp+20h] [-140h]
  int v156; // [sp+24h] [-13Ch]
  int v157; // [sp+28h] [-138h]
  int v158; // [sp+2Ch] [-134h]
  int v159; // [sp+30h] [-130h]
  int v160; // [sp+34h] [-12Ch]
  int v161; // [sp+38h] [-128h]
  int v162; // [sp+3Ch] [-124h]
  int v163; // [sp+40h] [-120h]
  int v164; // [sp+44h] [-11Ch]
  int v165; // [sp+48h] [-118h]
  int v166; // [sp+4Ch] [-114h]
  int v167; // [sp+50h] [-110h]
  int v168; // [sp+58h] [-108h]
  unsigned int v169; // [sp+60h] [-100h] BYREF
  slideMoveState_t *v170; // [sp+64h] [-FCh]
  __int64 v171; // [sp+68h] [-F8h] BYREF
  __int64 v172; // [sp+70h] [-F0h] BYREF
  __int64 v173; // [sp+78h] [-E8h] BYREF
  idVec3 v174; // [sp+80h] [-E0h] BYREF
  idVec3 v175[4]; // [sp+90h] [-D0h] BYREF

  v41 = numTrms_0;
  v42 = this;
  v49 = (const idBounds *)numTrms;
  if ( numTrms_0 <= 0 )
  {
    v51 = (float)(start->x + velocity->x);
    LODWORD(v50) = 7;
    v52 = (float)(start->y + velocity->y);
    HIDWORD(v50) = 1;
    HIDWORD(numTrms) = trmAxisa;
    v53 = (float)(start->z + velocity->z);
    v174.x = v51;
    v174.y = v52;
    v174.z = v53;
    idCollisionQueryJobManager::AllocFinishedFinalResult(
      this,
      result,
      type2: v50,
      endpos: &v174,
      endAxis: (const idMat3 *)a33,
      userName: numTrms);
    return v42;
  }
  v56 = idQueryData::AllocSlideMoveState(this: (idQueryData *)HIDWORD(result->offset));
  v57 = v56;
  v170 = v56;
  if ( v56 == nullptr )
  {
    LODWORD(v55) = 0;
    goto LABEL_5;
  }
  idCollisionDetectionMerge::InitSlideMoveState(state: v56, velocity, gravityVector);
  LODWORD(v58) = 0;
  v59 = (float)(v57->velocity.z + start->z);
  v60 = (float)(v57->velocity.y + start->y);
  v175[0].x = start->x + v57->velocity.x;
  v61 = 11;
  v175[0].z = v59;
  v169 = 0;
  v175[0].y = v60;
  v62 = nullptr;
  v63 = 1;
  while ( 1 )
  {
    if ( (unsigned int)v58 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset
      || (v64 = 1, (unsigned int)v58 > (unsigned int)idCollisionQuery::finalResultsLastAllocedOffset) )
    {
      v64 = 0;
    }
    v65 = 0;
    v66 = v64 == 0 ? DEPENDENCY_NONE : DEPENDENCY_SLIDEMOVE_SLIDE;
    if ( a31 > 0 )
    {
      v67 = a29;
      v68 = v41 - 1;
      while ( 1 )
      {
        v69 = v68;
        if ( v68 >= 0 )
          break;
LABEL_17:
        ++v65;
        ++v67;
        if ( v65 >= a31 )
        {
          v42 = this;
          v41 = numTrms_0;
          goto LABEL_19;
        }
      }
      v70 = (const idPositionedCollisionModel *)&trms_0[20 * v68];
      while ( 1 )
      {
        v72 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v70);
        if ( v72 == nullptr )
          goto LABEL_62;
        parms = v72->parms;
        v72->type = TRACE_TRANSLATION;
        parms->type = TRACE_TRANSLATION;
        v74 = (float *)v72->parms;
        v74[4] = start->x;
        v74[5] = start->y;
        v74[6] = start->z;
        v72->parms->end = v175[0];
        v75 = (float *)v72->parms;
        v75[12] = 0.0;
        v75[11] = 0.0;
        v75[10] = 0.0;
        v76 = (float *)v72->parms;
        v76[15] = 0.0;
        v76[14] = 0.0;
        v76[13] = 0.0;
        v72->parms->rotationAngle = 0.0;
        v77 = (float *)v72->parms;
        v77[17] = gravityVector->x;
        v77[18] = gravityVector->y;
        v77[19] = gravityVector->z;
        v72->parms->depth = 0.0;
        v78 = (float *)v72->parms;
        v78[21] = *(float *)a33;
        v78[22] = *(float *)(a33 + 4);
        v78[23] = *(float *)(a33 + 8);
        v78[24] = *(float *)(a33 + 12);
        v78[25] = *(float *)(a33 + 16);
        v78[26] = *(float *)(a33 + 20);
        v78[27] = *(float *)(a33 + 24);
        v78[28] = *(float *)(a33 + 28);
        v78[29] = *(float *)(a33 + 32);
        v72->parms->contentMask = a35;
        v72->parms->selfId = v65;
        v72->userName = (const char *)trmAxisa;
        v72->trm = *v67;
        v72->nextOnQuery = v62;
        v62 = v72;
        *(_QWORD *)((char *)&v79 + 4) = v70->modelQuery.offset;
        LODWORD(v79) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v70->modelQuery.offset),
          dependency1: v79,
          dependency2: null_query.offset,
          dependencyType: v66,
          globalStart: start,
          globalEnd: v175,
          globalBounds: v149,
          mergePriority: v150,
          a10: v151,
          a11: v152,
          a12: v153,
          a13: v154,
          a14: v155,
          a15: v156,
          a16: v157,
          a17: v158,
          a18: v159,
          a19: v160,
          a20: v161,
          a21: v162,
          a22: v163,
          a23: v164,
          a24: v165,
          a25: v166,
          a26: v167,
          a27: v49,
          a28: v168,
          a29: (int *)&v169);
        --v69;
        --v70;
        if ( v69 < 0 )
        {
          v57 = v170;
          goto LABEL_17;
        }
      }
    }
LABEL_19:
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v171,
      result,
      mergePriority: __PAIR64__((unsigned int)v62, v169),
      slideMoveState: v57);
    v80 = v171;
    if ( (_DWORD)v171 == 0 )
    {
      *(_QWORD *)&v42->queryData = v171;
      return v42;
    }
    v81 = 0;
    if ( SHIDWORD(v171) > 0 )
    {
      v82 = a29;
      v83 = v41 - 1;
      while ( 1 )
      {
        v84 = v83;
        if ( v83 >= 0 )
          break;
LABEL_27:
        ++v81;
        ++v82;
        if ( v81 >= SHIDWORD(v80) )
        {
          v42 = this;
          v41 = numTrms_0;
          goto LABEL_29;
        }
      }
      v85 = (const idPositionedCollisionModel *)&trms_0[20 * v83];
      while ( 1 )
      {
        v86 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v85);
        if ( v86 == nullptr )
          goto LABEL_62;
        v87 = v86->parms;
        v86->type = TRACE_TRANSLATION;
        v87->type = TRACE_TRANSLATION;
        v88 = (float *)v86->parms;
        v88[4] = start->x;
        v88[5] = start->y;
        v88[6] = start->z;
        v86->parms->end = v175[0];
        v89 = (float *)v86->parms;
        v89[12] = 0.0;
        v89[11] = 0.0;
        v89[10] = 0.0;
        v90 = (float *)v86->parms;
        v90[13] = 0.0;
        v90[15] = 0.0;
        v90[14] = 0.0;
        v86->parms->rotationAngle = 0.0;
        v91 = (float *)v86->parms;
        v91[17] = gravityVector->x;
        v91[18] = gravityVector->y;
        v91[19] = gravityVector->z;
        v86->parms->depth = -stepUp;
        v92 = (float *)v86->parms;
        v92[21] = *(float *)a33;
        v92[22] = *(float *)(a33 + 4);
        v92[23] = *(float *)(a33 + 8);
        v92[24] = *(float *)(a33 + 12);
        v92[25] = *(float *)(a33 + 16);
        v92[26] = *(float *)(a33 + 20);
        v92[27] = *(float *)(a33 + 24);
        v92[28] = *(float *)(a33 + 28);
        v92[29] = *(float *)(a33 + 32);
        v86->parms->contentMask = a35;
        v86->parms->selfId = v81;
        v86->userName = (const char *)trmAxisa;
        v93 = *v82;
        v86->nextOnQuery = v62;
        v62 = v86;
        v86->trm = v93;
        *(_QWORD *)((char *)&v94 + 4) = v85->modelQuery.offset;
        LODWORD(v94) = HIDWORD(null_query.offset);
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v85->modelQuery.offset),
          dependency1: v94,
          dependency2: null_query.offset,
          dependencyType: (dependencyType_t)(v61 - 4),
          globalStart: start,
          globalEnd: v175,
          globalBounds: v149,
          mergePriority: v150,
          a10: v151,
          a11: v152,
          a12: v153,
          a13: v154,
          a14: v155,
          a15: v156,
          a16: v157,
          a17: v158,
          a18: v159,
          a19: v160,
          a20: v161,
          a21: v162,
          a22: v163,
          a23: v164,
          a24: v165,
          a25: v166,
          a26: v167,
          a27: v49,
          a28: v168,
          a29: (int *)&v169);
        --v84;
        --v85;
        if ( v84 < 0 )
        {
          v57 = v170;
          goto LABEL_27;
        }
      }
    }
LABEL_29:
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v172,
      result,
      mergePriority: __PAIR64__((unsigned int)v62, v169),
      slideMoveState: v57);
    v95 = v172;
    if ( (_DWORD)v172 == 0 )
      break;
    v96 = 0;
    if ( SHIDWORD(v80) > 0 )
    {
      v97 = a29;
      v98 = v41 - 1;
      while ( 1 )
      {
        v99 = v98;
        if ( v98 >= 0 )
          break;
LABEL_36:
        ++v96;
        ++v97;
        if ( v96 >= a31 )
        {
          v57 = v170;
          HIDWORD(v80) = a31;
          v42 = this;
          v41 = numTrms_0;
          goto LABEL_38;
        }
      }
      v100 = (const idPositionedCollisionModel *)&trms_0[20 * v98];
      while ( 1 )
      {
        v101 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v100);
        if ( v101 == nullptr )
          goto LABEL_62;
        v102 = v101->parms;
        v101->type = TRACE_TRANSLATION;
        v102->type = TRACE_TRANSLATION;
        LODWORD(v103) = v95;
        v104 = (float *)v101->parms;
        v104[4] = start->x;
        v104[5] = start->y;
        v104[6] = start->z;
        v101->parms->end = v175[0];
        v105 = (float *)v101->parms;
        v105[12] = 0.0;
        v105[11] = 0.0;
        v105[10] = 0.0;
        v106 = (float *)v101->parms;
        v106[15] = 0.0;
        v106[14] = 0.0;
        v106[13] = 0.0;
        v101->parms->rotationAngle = 0.0;
        v107 = (float *)v101->parms;
        v107[17] = gravityVector->x;
        v107[18] = gravityVector->y;
        v107[19] = gravityVector->z;
        v101->parms->depth = -stepUp;
        v108 = (float *)v101->parms;
        v108[21] = *(float *)a33;
        v108[22] = *(float *)(a33 + 4);
        v108[23] = *(float *)(a33 + 8);
        v108[24] = *(float *)(a33 + 12);
        v108[25] = *(float *)(a33 + 16);
        v108[26] = *(float *)(a33 + 20);
        v108[27] = *(float *)(a33 + 24);
        v108[28] = *(float *)(a33 + 28);
        v108[29] = *(float *)(a33 + 32);
        v101->parms->contentMask = a35;
        v101->parms->selfId = v96;
        v101->userName = (const char *)trmAxisa;
        v101->trm = *v97;
        v101->nextOnQuery = v62;
        v62 = v101;
        *(_QWORD *)((char *)&v103 + 4) = v100->modelQuery.offset;
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v100->modelQuery.offset),
          dependency1: v103,
          dependency2: v58,
          dependencyType: SHIDWORD(v95),
          globalStart: start,
          globalEnd: v175,
          globalBounds: v149,
          mergePriority: v150,
          a10: v151,
          a11: v152,
          a12: v153,
          a13: v154,
          a14: v155,
          a15: v156,
          a16: v157,
          a17: v158,
          a18: v159,
          a19: v160,
          a20: v161,
          a21: v162,
          a22: v163,
          a23: v164,
          a24: v165,
          a25: v166,
          a26: v167,
          a27: v49,
          a28: v168,
          a29: (int *)&v169);
        --v99;
        --v100;
        if ( v99 < 0 )
          goto LABEL_36;
      }
    }
LABEL_38:
    idCollisionQueryJobManager::AddModelQueryToMergeList(
      this: (idCollisionQueryJobManager *)&v173,
      result,
      mergePriority: __PAIR64__((unsigned int)v62, v169),
      slideMoveState: v57);
    v95 = v173;
    if ( (_DWORD)v173 == 0 )
      break;
    v109 = 0;
    if ( SHIDWORD(v80) > 0 )
    {
      v110 = a29;
      v111 = v41 - 1;
      while ( 1 )
      {
        v112 = v111;
        if ( v111 >= 0 )
          break;
LABEL_46:
        ++v109;
        ++v110;
        if ( v109 >= SHIDWORD(v80) )
        {
          v42 = this;
          v41 = numTrms_0;
          goto LABEL_48;
        }
      }
      v113 = (const idPositionedCollisionModel *)&trms_0[20 * v111];
      while ( 1 )
      {
        v114 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v113);
        if ( v114 == nullptr )
          goto LABEL_62;
        v115 = v114->parms;
        v114->type = TRACE_TRANSLATION;
        v115->type = TRACE_TRANSLATION;
        LODWORD(v116) = v95;
        v117 = (float *)v114->parms;
        v117[4] = start->x;
        v117[5] = start->y;
        v117[6] = start->z;
        v114->parms->end = v175[0];
        v118 = (float *)v114->parms;
        v118[12] = 0.0;
        v118[11] = 0.0;
        v118[10] = 0.0;
        v119 = (float *)v114->parms;
        v119[15] = 0.0;
        v119[14] = 0.0;
        v119[13] = 0.0;
        v114->parms->rotationAngle = 0.0;
        v120 = (float *)v114->parms;
        v120[17] = gravityVector->x;
        v120[18] = gravityVector->y;
        v120[19] = gravityVector->z;
        v114->parms->depth = stepDown;
        p_trmAxis = (float *)&v114->parms->trmAxis;
        *p_trmAxis = *(float *)a33;
        p_trmAxis[1] = *(float *)(a33 + 4);
        p_trmAxis[2] = *(float *)(a33 + 8);
        p_trmAxis[3] = *(float *)(a33 + 12);
        p_trmAxis[4] = *(float *)(a33 + 16);
        p_trmAxis[5] = *(float *)(a33 + 20);
        p_trmAxis[6] = *(float *)(a33 + 24);
        p_trmAxis[7] = *(float *)(a33 + 28);
        p_trmAxis[8] = *(float *)(a33 + 32);
        v114->parms->contentMask = a35;
        v114->parms->selfId = v109;
        v114->userName = (const char *)trmAxisa;
        v122 = *v110;
        v114->nextOnQuery = v62;
        v62 = v114;
        v114->trm = v122;
        *(_QWORD *)((char *)&v116 + 4) = v113->modelQuery.offset;
        idCollisionQueryJobManager::AddModelQueryToExecuteList(
          this: (idCollisionQueryJobManager *)result,
          modelQuery: (modelQuery_t *)HIDWORD(v113->modelQuery.offset),
          dependency1: v116,
          dependency2: v80,
          dependencyType: (dependencyType_t)(HIDWORD(v95) + 4),
          globalStart: start,
          globalEnd: v175,
          globalBounds: v149,
          mergePriority: v150,
          a10: v151,
          a11: v152,
          a12: v153,
          a13: v154,
          a14: v155,
          a15: v156,
          a16: v157,
          a17: v158,
          a18: v159,
          a19: v160,
          a20: v161,
          a21: v162,
          a22: v163,
          a23: v164,
          a24: v165,
          a25: v166,
          a26: v167,
          a27: v49,
          a28: v168,
          a29: (int *)&v169);
        --v112;
        --v113;
        if ( v112 < 0 )
        {
          v57 = v170;
          goto LABEL_46;
        }
      }
    }
LABEL_48:
    v123 = idCollisionQueryJobManager::AddModelQueryToMergeList(
             this: (idCollisionQueryJobManager *)&v174,
             result,
             mergePriority: __PAIR64__((unsigned int)v62, v169),
             slideMoveState: v57);
    v58 = *(_QWORD *)&v123->queryData;
    if ( v123->dummyQueryResults == nullptr )
      goto LABEL_61;
    v61 = HIDWORD(v95) + 1;
    if ( v61 >= 15 )
    {
      y = gravityVector->y;
      x = gravityVector->x;
      v126 = 0;
      v174.z = gravityVector->z;
      v174.y = y;
      v174.x = x;
      _FP7 = (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f5, f7, f8, f13 }
      v129 = __frsqrte(_FP5);
      v130 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v129
                                                                                           * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z))) * (float)0.5))
                                                                                   * (float)v129)
                                                                           - (float)1.5)
                                                           * (float)v129)
                                                   * (float)((float)((float)(y * y)
                                                                   + (float)((float)(x * x) + (float)(v174.z * v174.z)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v129
                                                                                   * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z)))
                                                                                           * (float)0.5))
                                                                           * (float)v129)
                                                                   - (float)1.5)
                                                   * (float)v129))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v129
                                                           * (float)((float)((float)(y * y)
                                                                           + (float)((float)(x * x)
                                                                                   + (float)(v174.z * v174.z)))
                                                                   * (float)0.5))
                                                   * (float)v129)
                                           - (float)1.5)
                           * (float)v129));
      v131 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v129 * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z))) * (float)0.5)) * (float)v129) - (float)1.5) * (float)v129)
                                                                                           * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v129 * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z))) * (float)0.5)) * (float)v129) - (float)1.5)
                                                                                           * (float)v129))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v129 * (float)((float)((float)(y * y) + (float)((float)(x * x) + (float)(v174.z * v174.z))) * (float)0.5))
                                                                                           * (float)v129)
                                                                                   - (float)1.5)
                                                                   * (float)v129))
                                                   * (float)((float)((float)(y * y)
                                                                   + (float)((float)(x * x) + (float)(v174.z * v174.z)))
                                                           * (float)0.5))
                                           * (float)v130)
                                   - (float)1.5)
                   * (float)v130);
      v132 = (float)(x * (float)v131);
      v133 = (float)(y * (float)v131);
      v134 = (float)(v174.z * (float)v131);
      if ( a31 > 0 )
      {
        v135 = v41 - 1;
        v136 = a29;
        while ( 1 )
        {
          v137 = v41 - 1;
          if ( v135 >= 0 )
            break;
LABEL_56:
          ++v126;
          ++v136;
          if ( v126 >= a31 )
          {
            v42 = this;
            goto LABEL_58;
          }
        }
        v138 = (const idPositionedCollisionModel *)&trms_0[20 * v135];
        while ( 1 )
        {
          v139 = idCollisionQueryJobManager::AllocModelQuery(this: (idCollisionQueryJobManager *)result, model: v138);
          if ( v139 == nullptr )
            break;
          v140 = v139->parms;
          v139->type = TRACE_CONTACTS_UNI_DIR;
          v140->type = TRACE_CONTACTS_UNI_DIR;
          v141 = (float *)v139->parms;
          v141[4] = start->x;
          v141[5] = start->y;
          v141[6] = start->z;
          v142 = (float *)v139->parms;
          v142[7] = start->x;
          v142[8] = start->y;
          v142[9] = start->z;
          v143 = (float *)v139->parms;
          v143[12] = 0.0;
          v143[11] = 0.0;
          v143[10] = 0.0;
          v144 = (float *)v139->parms;
          v144[15] = 0.0;
          v144[14] = 0.0;
          v144[13] = 0.0;
          v139->parms->rotationAngle = 0.0;
          v145 = (float *)v139->parms;
          v145[17] = v132;
          v145[18] = v133;
          v145[19] = v134;
          v139->parms->depth = 0.5;
          v146 = (float *)&v139->parms->trmAxis;
          *v146 = *(float *)a33;
          v146[1] = *(float *)(a33 + 4);
          v146[2] = *(float *)(a33 + 8);
          v146[3] = *(float *)(a33 + 12);
          v146[4] = *(float *)(a33 + 16);
          v146[5] = *(float *)(a33 + 20);
          v146[6] = *(float *)(a33 + 24);
          v146[7] = *(float *)(a33 + 28);
          v146[8] = *(float *)(a33 + 32);
          v139->parms->contentMask = a35;
          v139->parms->selfId = v126;
          v139->userName = (const char *)trmAxisa;
          v147 = *v136;
          v139->nextOnQuery = v62;
          v62 = v139;
          v139->trm = v147;
          *(_QWORD *)((char *)&v148 + 4) = v138->modelQuery.offset;
          LODWORD(v148) = HIDWORD(null_query.offset);
          idCollisionQueryJobManager::AddModelQueryToExecuteList(
            this: (idCollisionQueryJobManager *)result,
            modelQuery: (modelQuery_t *)HIDWORD(v138->modelQuery.offset),
            dependency1: v148,
            dependency2: null_query.offset,
            dependencyType: DEPENDENCY_SLIDEMOVE_CONTACTS,
            globalStart: start,
            globalEnd: v175,
            globalBounds: v149,
            mergePriority: v150,
            a10: v151,
            a11: v152,
            a12: v153,
            a13: v154,
            a14: v155,
            a15: v156,
            a16: v157,
            a17: v158,
            a18: v159,
            a19: v160,
            a20: v161,
            a21: v162,
            a22: v163,
            a23: v164,
            a24: v165,
            a25: v166,
            a26: v167,
            a27: v49,
            a28: v168,
            a29: (int *)&v169);
          --v137;
          --v138;
          if ( v137 < 0 )
            goto LABEL_56;
        }
LABEL_62:
        LODWORD(v71) = 0;
        *(_QWORD *)&this->queryData = v71;
        return this;
      }
LABEL_58:
      idCollisionQueryJobManager::AddModelQueryToMergeList(
        this: (idCollisionQueryJobManager *)&v173,
        result,
        mergePriority: __PAIR64__((unsigned int)v62, v169),
        slideMoveState: nullptr);
      LODWORD(v55) = v173;
      if ( (_DWORD)v173 != 0 )
        v63 = 0;
      HIDWORD(v55) = v63;
      if ( v63 == 0 )
      {
LABEL_61:
        *(_QWORD *)&v42->queryData = v58;
        return v42;
      }
LABEL_5:
      *(_QWORD *)&v42->queryData = v55;
      return v42;
    }
  }
  *(_QWORD *)&v42->queryData = v95;
  return v42;
}


// ========================================================================
// ?GetRotationResult@idCollisionQueryJobManager@@QAA_NPAVidTraceWork@@PAUtrace_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825E2878
// RVA : 0x005E2878
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

int __fastcall idCollisionQueryJobManager::GetRotationResult(
        idCollisionQueryJobManager *this,
        idTraceWork *tw,
        trace_t *result,
        idCollisionQuery *query,
        bool peek)
{
  unsigned int offset; // r11
  char v9; // r11
  bool v10; // zf
  unsigned __int8 *v12; // r31

  offset = query->offset;
  if ( offset < *(_DWORD *)(HIDWORD(query->offset) - 18140)
    || (v10 = offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v9 = 1, !v10) )
  {
    v9 = 0;
  }
  if ( v9 == 0 )
    return 0;
  v12 = &this->queryData->finalResults[query->offset & 0x7FFFF];
  idCollisionQueryJobManager::WaitForQueryResults(this, results: (queryResults_t *)v12);
  trace_t::operator=(this: result, __that: (const trace_t *)(v12 + 48));
  if ( !peek )
    query->offset = 0;
  return 1;
}


// ========================================================================
// ?GetMotionContactsResult@idCollisionQueryJobManager@@QAA_NPAVidTraceWork@@PAUtrace_t@@PAUcontactsResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825E2920
// RVA : 0x005E2920
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

int __fastcall idCollisionQueryJobManager::GetMotionContactsResult(
        idCollisionQueryJobManager *this,
        idTraceWork *tw,
        trace_t *result,
        contactsResult_t *contacts,
        idCollisionQuery *query,
        bool peek)
{
  unsigned __int64 offset; // r11
  unsigned __int8 v11; // r25
  char v12; // r10
  bool v13; // zf
  unsigned __int8 *v15; // r29
  unsigned __int64 v16; // r11
  unsigned int v17; // r11
  idCollisionQueryJobManager *v18; // r3
  unsigned __int8 *v19; // r31

  offset = query->offset;
  HIDWORD(offset) = query->offset;
  v11 = BYTE3(idCollisionQuery::finalResultsFirstSubmittedOffset);
  if ( HIDWORD(offset) < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
    || (v13 = HIDWORD(offset) < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v12 = 1, !v13) )
  {
    v12 = 0;
  }
  if ( v12 == 0 )
    return 0;
  v15 = &this->queryData->finalResults[offset & 0x7FFFF];
  idCollisionQueryJobManager::WaitForQueryResults(this, results: (queryResults_t *)v15);
  trace_t::operator=(this: result, __that: (const trace_t *)(v15 + 48));
  if ( contacts != nullptr )
  {
    v17 = LODWORD(query->offset) + 192;
    if ( ((LODWORD(query->offset) + 1184) & 0xFFF80000) > (v17 & 0xFFF80000) )
      v17 = (LODWORD(query->offset) + 1184) & 0xFFF80000;
    v18 = this;
    v19 = &this->queryData->finalResults[v17 & 0x7FFFF];
    idCollisionQueryJobManager::WaitForQueryResults(this: v18, results: (queryResults_t *)v19);
    contactsResult_t::CopyFrom(this: contacts, other: (const contactsResult_t *)(v19 + 48));
    if ( result != nullptr && contacts->numContacts == 0 && result->fraction != 1.0 )
      idLib::Warning(fmt: "There were collisions without contacts.");
  }
  if ( v11 == 0 )
  {
    LODWORD(v16) = v11;
    query->offset = v16;
  }
  return 1;
}


// ========================================================================
// ?GetClipResult@idCollisionQueryJobManager@@QAA_NPAVidTraceWork@@PAUclipResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825E2A60
// RVA : 0x005E2A60
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

int __fastcall idCollisionQueryJobManager::GetClipResult(
        idCollisionQueryJobManager *this,
        idTraceWork *tw,
        clipResult_t *result,
        idCollisionQuery *query,
        bool peek)
{
  unsigned int offset; // r11
  char v9; // r11
  bool v10; // zf
  unsigned __int8 *v12; // r31

  offset = query->offset;
  if ( offset < *(_DWORD *)(HIDWORD(query->offset) - 18140)
    || (v10 = offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v9 = 1, !v10) )
  {
    v9 = 0;
  }
  if ( v9 == 0 )
    return 0;
  v12 = &this->queryData->finalResults[query->offset & 0x7FFFF];
  idCollisionQueryJobManager::WaitForQueryResults(this, results: (queryResults_t *)v12);
  clipResult_t::operator=(this: result, __that: (const clipResult_t *)(v12 + 48));
  if ( !peek )
    query->offset = 0;
  return 1;
}


// ========================================================================
// ?GetSlideMoveContactsResult@idCollisionQueryJobManager@@QAA_NPAVidTraceWork@@PAUtrace_t@@PAUcontactsResult_t@@AAVidCollisionQuery@@_N@Z
// EA  : 0x825E2B08
// RVA : 0x005E2B08
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

int __fastcall idCollisionQueryJobManager::GetSlideMoveContactsResult(
        idCollisionQueryJobManager *this,
        idTraceWork *tw,
        trace_t *result,
        contactsResult_t *contacts,
        idCollisionQuery *query,
        bool peek)
{
  unsigned __int64 offset; // r11
  unsigned __int8 v11; // r25
  char v12; // r10
  bool v13; // zf
  unsigned __int8 *v15; // r30
  unsigned __int64 v16; // r11
  unsigned int v17; // r11
  idCollisionQueryJobManager *v18; // r3
  unsigned __int8 *v19; // r31

  offset = query->offset;
  HIDWORD(offset) = query->offset;
  v11 = BYTE3(idCollisionQuery::finalResultsFirstSubmittedOffset);
  if ( HIDWORD(offset) < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
    || (v13 = HIDWORD(offset) < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v12 = 1, !v13) )
  {
    v12 = 0;
  }
  if ( v12 == 0 )
    return 0;
  v15 = &this->queryData->finalResults[offset & 0x7FFFF];
  idCollisionQueryJobManager::WaitForQueryResults(this, results: (queryResults_t *)v15);
  trace_t::operator=(this: result, __that: (const trace_t *)(v15 + 48));
  if ( contacts != nullptr )
  {
    v17 = LODWORD(query->offset) + 192;
    if ( ((LODWORD(query->offset) + 1184) & 0xFFF80000) > (v17 & 0xFFF80000) )
      v17 = (LODWORD(query->offset) + 1184) & 0xFFF80000;
    v18 = this;
    v19 = &this->queryData->finalResults[v17 & 0x7FFFF];
    idCollisionQueryJobManager::WaitForQueryResults(this: v18, results: (queryResults_t *)v19);
    contactsResult_t::CopyFrom(this: contacts, other: (const contactsResult_t *)(v19 + 48));
  }
  if ( v11 == 0 )
  {
    LODWORD(v16) = v11;
    query->offset = v16;
  }
  return 1;
}


// ========================================================================
// ?CreateExecuteJobs@idCollisionQueryJobManager@@AAAXPAVidParallelJobList@@PAUmodelQuery_t@@@Z
// EA  : 0x825E2C10
// RVA : 0x005E2C10
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::CreateExecuteJobs(
        idCollisionQueryJobManager *this,
        idParallelJobList *jobList,
        modelQuery_t *mq)
{
  modelQuery_t *v4; // r31

  v4 = mq;
  if ( cm_useJobs.valueInteger == 1 )
  {
    if ( mq != nullptr )
    {
      do
      {
        if ( v4->mergePriority != 1023 )
          idParallelJobList::AddJob(this: jobList, function: (void (__fastcall *)(void *))CollisionExecuteJob, data: v4);
        v4 = v4->nextInExecuteList;
      }
      while ( v4 != nullptr );
    }
  }
  else if ( mq != nullptr )
  {
    do
    {
      if ( v4->mergePriority != 1023 )
        CollisionExecuteJob(mq: v4);
      v4 = v4->nextInExecuteList;
    }
    while ( v4 != nullptr );
  }
}


// ========================================================================
// ?ShowDebugInfo@idCollisionQueryJobManager@@AAAXXZ
// EA  : 0x825E2CC0
// RVA : 0x005E2CC0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::ShowDebugInfo(
        idCollisionQueryJobManager *this,
        int a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  int valueInteger; // r25
  unsigned int v8; // r27
  unsigned int v9; // r21
  int v10; // r26
  int v11; // r28
  int v12; // r24
  __int64 v13; // r6
  int v14; // r30
  jobGroup_t *v15; // r4
  int v16; // r29
  modelQuery_t *i; // r11
  subModelQuery_t *j; // r10
  modelQuery_t *k; // r10
  subModelQuery_t *m; // r11
  modelQuery_t *n; // r10
  subModelQuery_t *ii; // r11
  int v23; // r3
  int jj; // r11
  int v25; // r5
  modelQuery_t *kk; // r5
  va *v27; // r3
  va *v28; // r3
  __int64 v29; // r8
  __int64 v30; // r6
  int queryFrameNumber; // r11
  __int64 v32; // r10
  va *v33; // r3
  int v34; // r28
  void (__fastcall **p_valueCompletion)(idAutoComplete *); // r29
  __int64 v36; // r6
  __int64 v37; // r8
  __int64 v38; // r10
  va *v39; // r3
  va *v40; // r3
  __int64 v41; // r10
  va *v42; // r3
  int v43; // r28
  int v44; // r27
  int mm; // r30
  idCollisionModelLocal *v46; // r26
  int v47; // r7
  int v48; // [sp+8h] [-1128h]
  int v49; // [sp+8h] [-1128h]
  int v50; // [sp+Ch] [-1124h]
  int v51; // [sp+Ch] [-1124h]
  int v52; // [sp+10h] [-1120h]
  int v53; // [sp+10h] [-1120h]
  int v54; // [sp+14h] [-111Ch]
  int v55; // [sp+14h] [-111Ch]
  int v56; // [sp+18h] [-1118h]
  int v57; // [sp+18h] [-1118h]
  int v58; // [sp+1Ch] [-1114h]
  int v59; // [sp+1Ch] [-1114h]
  int v60; // [sp+30h] [-1100h]
  int v61; // [sp+38h] [-10F8h]
  idStr v62; // [sp+80h] [-10B0h] BYREF
  va v63; // [sp+A0h] [-1090h] BYREF

  LODWORD(a6) = v62.baseBuffer;
  v62.len = 0;
  v62.allocedAndFlag = 20;
  v62.data = v62.baseBuffer;
  v62.baseBuffer[0] = 0;
  valueInteger = cm_showDependencies.valueInteger;
  if ( cm_showDependencies.valueInteger > 0 )
  {
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    if ( this->numJobGroups > 0 )
    {
      v12 = 0;
      do
      {
        LODWORD(v13) = 0;
        v14 = 0;
        v15 = &this->jobGroups[v12];
        HIDWORD(a5) = 0;
        v16 = 0;
        for ( i = v15->stallingExecuteJobs; i != nullptr; i = i->nextInExecuteList )
        {
          v14 += i->parms->autoMerge;
          if ( i->numSubModelQueries <= 0 )
          {
            LODWORD(v13) = v13 + 1;
          }
          else
          {
            for ( j = i->subModelQueries; j != nullptr; LODWORD(v13) = v13 + 1 )
              j = j->nextOnModelQuery;
          }
        }
        for ( k = v15->notStallingExecuteJobs1; k != nullptr; k = k->nextInExecuteList )
        {
          v14 += k->parms->autoMerge;
          if ( k->numSubModelQueries <= 0 )
          {
            ++HIDWORD(a5);
            LODWORD(v13) = v13 + 1;
          }
          else
          {
            for ( m = k->subModelQueries; m != nullptr; LODWORD(v13) = v13 + 1 )
            {
              m = m->nextOnModelQuery;
              ++HIDWORD(a5);
            }
          }
        }
        for ( n = v15->notStallingExecuteJobs2; n != nullptr; n = n->nextInExecuteList )
        {
          v14 += n->parms->autoMerge;
          if ( n->numSubModelQueries <= 0 )
          {
            ++v16;
            LODWORD(v13) = v13 + 1;
          }
          else
          {
            for ( ii = n->subModelQueries; ii != nullptr; LODWORD(v13) = v13 + 1 )
            {
              ii = ii->nextOnModelQuery;
              ++v16;
            }
          }
        }
        HIDWORD(a6) = v15->stallingMergeJobs;
        v8 += v13;
        v10 += v14;
        LODWORD(a5) = 0;
        v23 = 0;
        LODWORD(a6) = 0;
        for ( jj = 0; HIDWORD(a6) != 0; HIDWORD(a6) = *(_DWORD *)(HIDWORD(a6) + 64) )
        {
          v25 = *(_DWORD *)(HIDWORD(a6) + 76);
          LODWORD(a5) = a5 + 1;
          jj += v25;
          if ( v25 > (int)a6 )
            LODWORD(a6) = *(_DWORD *)(HIDWORD(a6) + 76);
        }
        for ( kk = v15->notStallingMergeJobs; kk != nullptr; kk = kk->nextInMergeList )
        {
          HIDWORD(a6) = kk->numMergeResults;
          LODWORD(a5) = a5 + 1;
          ++v23;
          jj += HIDWORD(a6);
          if ( SHIDWORD(a6) > (int)a6 )
            LODWORD(a6) = kk->numMergeResults;
        }
        v9 += a5;
        if ( (_DWORD)a5 != 0 )
        {
          __twllei(a5, 0);
          __twlgei(a5 & ~(__ROL4__((int)a5 / 2 + jj, 1) - 1), 0xFFFFFFFF);
        }
        HIDWORD(a6) = valueInteger - 1;
        if ( v11 >= valueInteger - 1 )
        {
          HIDWORD(a6) = v23 + v16;
          HIDWORD(v13) = v11;
          v27 = va::va(
                  this: &v63,
                  fmt: "level %d: %d/%d queries, %d/%d merges (%d/%d), %d auto\n",
                  a3: v13,
                  a4: a5,
                  a5: a6,
                  a6: v48,
                  a7: v50,
                  a8: v52,
                  a9: v54,
                  a10: v56,
                  a11: v58);
          idStr::Append(this: &v62, text: v27);
          valueInteger = cm_showDependencies.valueInteger;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < this->numJobGroups );
    }
    HIDWORD(a5) = v10;
    v28 = va::va(
            this: &v63,
            fmt: "-----------------------------------\ntotal: %d queries, %d merges, %d auto merges\n",
            a3: __SPAIR64__(v8, v9),
            a4: a5,
            a5: a6,
            a6: v48,
            a7: v50,
            a8: v52,
            a9: v54,
            a10: v56,
            a11: v58);
    idStr::Append(this: &v62, text: v28);
    queryFrameNumber = this->queryFrameNumber;
    LODWORD(v32) = this->stalledFrameNumber;
    if ( (int)v32 > queryFrameNumber - 10 )
    {
      HIDWORD(v32) = &unk_821B0000;
      HIDWORD(v30) = queryFrameNumber - v32;
      v33 = va::va(
              this: &v63,
              fmt: "^1STALLED (%d)\n",
              a3: v30,
              a4: v29,
              a5: v32,
              a6: v48,
              a7: v50,
              a8: v52,
              a9: v54,
              a10: v56,
              a11: v58);
      idStr::Append(this: &v62, text: v33);
    }
  }
  if ( cm_showMemory.valueInteger != 0 )
  {
    if ( (cm_showMemory.flags & 0x20000) != 0 )
    {
      numStats = 0;
      cm_showMemory.flags &= ~0x20000u;
      memset(Dst: &totalStats, Val: 0, Size: sizeof(totalStats));
    }
    idQueryData::UpdateQueryDataStats(
      this: this->queryData,
      stats: stats,
      numStats: &numStats,
      maxStats: 128,
      totalStats: &totalStats);
    idStr::Append(this: &v62, text: ".............................................\n");
    v34 = 0;
    if ( numStats > 0 )
    {
      p_valueCompletion = &cm_catchLargeQueries.valueCompletion;
      do
      {
        HIDWORD(v36) = p_valueCompletion[12];
        LODWORD(v36) = p_valueCompletion[17];
        HIDWORD(v37) = p_valueCompletion[13];
        LODWORD(v37) = p_valueCompletion[18];
        HIDWORD(v38) = p_valueCompletion[14];
        LODWORD(v38) = p_valueCompletion[19];
        p_valueCompletion += 11;
        v39 = va::va(
                this: &v63,
                fmt: "%4d/%4d queries, %4d/%4d mdl queries, %4d/%4d sub-mdl queries, %4d/%4d kB temp, %4d/%4d kB final, %s\n",
                a3: v36,
                a4: v37,
                a5: v38,
                a6: v48,
                a7: v50,
                a8: v52,
                a9: v54,
                a10: v56,
                a11: v58);
        idStr::Append(this: &v62, text: v39);
        ++v34;
      }
      while ( v34 < numStats );
    }
    idStr::Append(this: &v62, text: ".............................................\n");
    v40 = va::va(
            this: &v63,
            fmt: "%4d/%4d queries, %4d/%4d mdl queries, %4d/%4d sub-mdl queries, %4d/%4d kB temp, %4d/%4d kB final, total\n",
            a3: __SPAIR64__(totalStats.numCollisionQueries, totalStats.maxCollisionQueries),
            a4: __SPAIR64__(totalStats.numModelQueries, totalStats.maxModelQueries),
            a5: __SPAIR64__(totalStats.numSubModelQueries, totalStats.maxSubModelQueries),
            a6: v48,
            a7: v50,
            a8: v52,
            a9: v54,
            a10: v56,
            a11: v58);
    idStr::Append(this: &v62, text: v40);
    LODWORD(v41) = &unk_821B0000;
    HIDWORD(v41) = 512;
    v42 = va::va(
            this: &v63,
            fmt: "     %4d queries,      %4d mdl queries,      %4d sub-mdl queries,      %4d kB temp,      %4d kB final, maximum\n",
            a3: 0x80000000800LL,
            a4: 0x100000000400LL,
            a5: v41,
            a6: v49,
            a7: v51,
            a8: v53,
            a9: v55,
            a10: v57,
            a11: v59);
    idStr::Append(this: &v62, text: v42);
    v43 = 0;
    v44 = 0;
    for ( mm = 0; mm < idCollisionModelLocal::resourceList.num; v44 += idCollisionModelLocal::GetLoadedMemory(this: v46) )
    {
      v46 = (idCollisionModelLocal *)idResourceList::Index(this: &idCollisionModelLocal::resourceList, index: mm);
      v43 += idCollisionModelLocal::GetTotalMemory(this: v46);
      ++mm;
    }
    if ( (_S16 & 1) == 0 )
    {
      handle_0.time = 0;
      _S16 |= 1u;
      handle_0.index = -1;
    }
    ((void (*)(idConsole *, idOverlayHandle *, int, int, int, const char *, ...))console->PrintOverlay)(
      a1: console,
      a2: &handle_0,
      a3: 1,
      a4: v60,
      a5: v61,
      a6: "%d kB collision maximum\n%d kB collision current\n",
      v43 >> 10,
      v44 >> 10,
      1.0,
      1.0);
  }
  if ( v62.len != 0 )
  {
    if ( (_S16 & 2) == 0 )
    {
      handle.time = 0;
      _S16 |= 2u;
      handle.index = -1;
    }
    ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, _DWORD, int, char *, double, double))console->PrintOverlay)(
      a1: console,
      a2: &handle,
      a3: 1.0,
      a4: 1.0,
      a5: v61,
      a6: v62.data,
      a7: 1.0,
      a8: 1.0);
  }
  if ( LODWORD(this->firstWaitTime) != 0 )
    v47 = (idParallelJobList::GetFinishTimeMicroSec(this: this->jobList) >> 32) - LODWORD(this->firstWaitTime);
  else
    v47 = 0;
  console->AddJobListTimeRange(this: console, a2: RANGE_JBL_COLL, a3: &idColor::colorGreen, a4: this->jobList, a5: v47);
  idStr::FreeData(this: &v62);
}


// ========================================================================
// __unwind$227096
// EA  : 0x825E3310
// RVA : 0x005E3310
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void _unwind_227096()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 128));
}


// ========================================================================
// ?SubmitQueries@idCollisionQueryJobManager@@QAAXXZ
// EA  : 0x825E3338
// RVA : 0x005E3338
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __fastcall idCollisionQueryJobManager::SubmitQueries(
        idCollisionQueryJobManager *this,
        int a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v7; // r6
  unsigned __int64 v8; // r28
  int v9; // r29
  int v10; // r30
  idQueryData *queryData; // r26
  __int128 v12; // r11
  __int128 v13; // r5

  idCollisionQueryJobManager::ShowDebugInfo(this, a2, a3, a4, a5, a6);
  idParallelJobList::Wait(this: this->jobList);
  idQueryData::ReleaseQueryOnlyData(this: this->queryData, a2: v7);
  LODWORD(v8) = 0;
  v9 = 0;
  if ( this->numJobGroups > 0 )
  {
    v10 = 0;
    do
    {
      idCollisionQueryJobManager::CreateExecuteJobs(
        this,
        jobList: this->jobList,
        mq: this->jobGroups[v10].stallingExecuteJobs);
      idParallelJobList::InsertSyncPoint(this: this->jobList, syncType: SYNC_SIGNAL);
      idCollisionQueryJobManager::CreateExecuteJobs(
        this,
        jobList: this->jobList,
        mq: this->jobGroups[v10].notStallingExecuteJobs1);
      idParallelJobList::InsertSyncPoint(this: this->jobList, syncType: SYNC_SYNCHRONIZE);
      idCollisionQueryJobManager::CreateMergeJobs(
        this,
        jobList: this->jobList,
        mq: this->jobGroups[v10].stallingMergeJobs);
      idParallelJobList::InsertSyncPoint(this: this->jobList, syncType: SYNC_SIGNAL);
      idCollisionQueryJobManager::CreateMergeJobs(
        this,
        jobList: this->jobList,
        mq: this->jobGroups[v10].notStallingMergeJobs);
      idCollisionQueryJobManager::CreateExecuteJobs(
        this,
        jobList: this->jobList,
        mq: this->jobGroups[v10].notStallingExecuteJobs2);
      idParallelJobList::InsertSyncPoint(this: this->jobList, syncType: SYNC_SYNCHRONIZE);
      ++v9;
      ++v10;
    }
    while ( v9 < this->numJobGroups );
  }
  idParallelJobList::Submit(this: this->jobList, waitForJobList: nullptr, parallelism: -1);
  queryData = this->queryData;
  HIDWORD(v8) = 2381992;
  *((_QWORD *)&v12 + 1) = this->queryData->finalResultsLastAllocedOffset;
  *((_QWORD *)&v13 + 1) = this->queryData->modelQueryLastAllocedIndex;
  *(_QWORD *)((char *)&v13 + 4) = *(_QWORD *)((char *)&this->queryData->modelQueries[0].type + DWORD2(v13));
  *(_QWORD *)&v13 = *(_QWORD *)((char *)&this->queryData->modelQueries[0].type + DWORD1(v13));
  *(_QWORD *)((char *)&v12 + 4) = *(_QWORD *)((char *)&this->queryData->modelQueries[0].type + DWORD2(v12));
  *(_QWORD *)&v12 = *(_QWORD *)((char *)&this->queryData->modelQueries[0].type + DWORD1(v12));
  queryData->modelQueryLastSubmittedIndex = v13;
  queryData->subModelQueryLastSubmittedIndex = *(_QWORD *)((char *)&v13 + 4);
  queryData->queryParmsLastSubmittedIndex = *(_QWORD *)&v13;
  queryData->slideMoveStateLastSubmittedIndex = *(_QWORD *)((char *)&v12 + 4);
  queryData->intermediateResultsLastSubmittedOffset = *(_QWORD *)&v12;
  queryData->finalResultsLastSubmittedOffset = v12;
  idCollisionQuery::finalResultsLastSubmittedOffset = v12;
  HIDWORD(v12) = this->queryFrameNumber + 1;
  this->numJobGroups = 0;
  this->firstWaitTime = v8;
  this->queryFrameNumber = HIDWORD(v12);
}


// ========================================================================
// `dynamic initializer for 'cm_useJobs''
// EA  : 0x83335E10
// RVA : 0x01335E10
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_useJobs__()
{
  idCVar::idCVar(
    this: &cm_useJobs,
    name: "cm_useJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_useJobs__);
}


// ========================================================================
// `dynamic initializer for 'cm_useSubModelQueries''
// EA  : 0x83335E78
// RVA : 0x01335E78
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_useSubModelQueries__()
{
  idCVar::idCVar(
    this: &cm_useSubModelQueries,
    name: "cm_useSubModelQueries",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_useSubModelQueries__);
}


// ========================================================================
// `dynamic initializer for 'cm_showDependencies''
// EA  : 0x83335ED0
// RVA : 0x01335ED0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_showDependencies__()
{
  idCVar::idCVar(
    this: &cm_showDependencies,
    name: "cm_showDependencies",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_showDependencies__);
}


// ========================================================================
// `dynamic initializer for 'cm_showMemory''
// EA  : 0x83335F28
// RVA : 0x01335F28
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_showMemory__()
{
  idCVar::idCVar(
    this: &cm_showMemory,
    name: "cm_showMemory",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_showMemory__);
}


// ========================================================================
// `dynamic initializer for 'cm_showProfile''
// EA  : 0x83335F80
// RVA : 0x01335F80
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_showProfile__()
{
  idCVar::idCVar(
    this: &cm_showProfile,
    name: "cm_showProfile",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_showProfile__);
}


// ========================================================================
// `dynamic initializer for 'cm_testQueries''
// EA  : 0x83335FD8
// RVA : 0x01335FD8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_testQueries__()
{
  idCVar::idCVar(
    this: &cm_testQueries,
    name: "cm_testQueries",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_testQueries__);
}


// ========================================================================
// `dynamic initializer for 'cm_catchLargeQueries''
// EA  : 0x83336030
// RVA : 0x01336030
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cm_catchLargeQueries__()
{
  idCVar::idCVar(
    this: &cm_catchLargeQueries,
    name: "cm_catchLargeQueries",
    value: "64",
    flags: 2,
    description: "Catch queries which intersect more than this many submodels",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cm_catchLargeQueries__);
}


// ========================================================================
// `dynamic initializer for 'register_CollisionExecuteJob''
// EA  : 0x83336088
// RVA : 0x01336088
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_CollisionExecuteJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_CollisionExecuteJob,
           function: (void (__fastcall *)(void *))CollisionExecuteJob,
           name: "CollisionExecuteJob");
}


// ========================================================================
// `dynamic initializer for 'register_CollisionMergeJob''
// EA  : 0x833360A8
// RVA : 0x013360A8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_CollisionMergeJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_CollisionMergeJob,
           function: (void (__fastcall *)(void *))CollisionMergeJob,
           name: "CollisionMergeJob");
}

