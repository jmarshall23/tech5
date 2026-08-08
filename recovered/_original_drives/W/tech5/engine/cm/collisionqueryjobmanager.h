
// ========================================================================
// ?AdvanceSubModelQueryFirstSubmittedIndex@idQueryData@@QAAX_K@Z
// EA  : 0x825D3838
// RVA : 0x005D3838
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idQueryData::AdvanceSubModelQueryFirstSubmittedIndex(
        idQueryData *this,
        unsigned int a2,
        unsigned __int64 newIndex)
{
  unsigned __int64 *p_subModelQueryFirstSubmittedIndex; // r26
  unsigned __int64 subModelQueryFirstSubmittedIndex; // r30 OVERLAPPED
  subModelQuery_t *v6; // r31

  p_subModelQueryFirstSubmittedIndex = &this->subModelQueryFirstSubmittedIndex;
  subModelQueryFirstSubmittedIndex = this->subModelQueryFirstSubmittedIndex;
  if ( (unsigned int)subModelQueryFirstSubmittedIndex < a2 )
  {
    do
    {
      v6 = &this->subModelQueries[subModelQueryFirstSubmittedIndex & 0xFFF];
      ReleaseSubModelData(subModel: (const cm_subModelData_t *)v6->subModel, data: v6->subModelData);
      LODWORD(subModelQueryFirstSubmittedIndex) = subModelQueryFirstSubmittedIndex + 1;
      v6->subModelData = nullptr;
    }
    while ( (unsigned int)subModelQueryFirstSubmittedIndex < HIDWORD(subModelQueryFirstSubmittedIndex) );
  }
  *p_subModelQueryFirstSubmittedIndex = *(unsigned __int64 *)((char *)&subModelQueryFirstSubmittedIndex + 4);
}


// ========================================================================
// ?StartFrame@idQueryData@@QAAXXZ
// EA  : 0x825D38A0
// RVA : 0x005D38A0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idQueryData::StartFrame(idQueryData *this)
{
  __int128 v1; // r10 OVERLAPPED
  int v2; // r6
  __int128 v3; // r6
  int v4; // r11

  *(_QWORD *)((char *)&v1 + 4) = this->subModelQueryLastAllocedIndex;
  *((_QWORD *)&v1 + 1) = this->queryParmsLastAllocedIndex;
  *(_QWORD *)((char *)&v1 - 4) = this->slideMoveStateLastAllocedIndex;
  *(_QWORD *)((char *)&v1 + 12) = this->intermediateResultsLastAllocedOffset;
  *((_QWORD *)&v3 + 1) = *(_QWORD *)((char *)&this->modelQueries[0].type + v2);
  ++DWORD1(v1);
  *((_BYTE *)&this->modelQueries[0].type + DWORD2(v3)) = 1;
  this->modelQueryFirstAllocedIndex = *(_QWORD *)&v1;
  ++DWORD2(v1);
  DWORD2(v3) = v1 + 1;
  DWORD1(v3) = v4 + 1;
  this->subModelQueryFirstAllocedIndex = *(_QWORD *)((char *)&v1 + 4);
  this->queryParmsFirstAllocedIndex = *(_QWORD *)((char *)&v3 + 4);
  this->slideMoveStateFirstAllocedIndex = *(_QWORD *)(&this - 1);
  this->intermediateResultsFirstAllocedOffset = *(_QWORD *)((char *)&v1 + 12);
  this->finalResultsFirstAllocedOffset = v3;
}


// ========================================================================
// ?UpdateQueryDataStats@idQueryData@@QAAHPAUqueryDataStats_t@@AAHHAAU2@@Z
// EA  : 0x825D4130
// RVA : 0x005D4130
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

int __fastcall idQueryData::UpdateQueryDataStats(
        idQueryData *this,
        queryDataStats_t *stats,
        int *numStats,
        int maxStats,
        queryDataStats_t *totalStats)
{
  int v10; // r10
  int *p_finalResultSize; // r11
  int v12; // r27
  queryDataStats_t *v13; // r29
  int v14; // r28
  const char **p_userName; // r30
  unsigned __int64 i; // r5
  _DWORD *v17; // r10
  const char *v18; // r7
  int v19; // r11
  queryDataStats_t *v20; // r9
  int v21; // r9
  int v22; // r6
  queryDataStats_t *v23; // r11
  int numSubModelQueries; // r8
  int v25; // r7
  int v26; // r9
  int finalResultSize; // r9
  int v28; // r8
  int v29; // r5
  int *v30; // r11
  int v31; // r7
  int v32; // r8
  int v33; // r9
  int v34; // r10
  int v35; // r8
  int v36; // r9
  int v37; // r10
  int v38; // r8
  int v39; // r9
  int v40; // r10
  int v41; // r8
  int v42; // r10
  int v43; // r9
  int numModelQueries; // r8
  int v45; // r7
  int queryDataSize; // r10
  int v47; // r9
  int maxCollisionQueries; // r10
  int maxModelQueries; // r10
  int maxSubModelQueries; // r10
  int maxQueryDataSize; // r10
  int v52; // r11
  int maxFinalResultSize; // r10
  _BYTE v55[44]; // [sp+50h] [-90h] BYREF

  totalStats->numCollisionQueries = 0;
  totalStats->numModelQueries = 0;
  totalStats->numSubModelQueries = 0;
  totalStats->queryDataSize = 0;
  totalStats->finalResultSize = 0;
  v10 = 0;
  if ( *numStats > 0 )
  {
    p_finalResultSize = &stats[-1].finalResultSize;
    do
    {
      p_finalResultSize[7] = 0;
      ++v10;
      p_finalResultSize[8] = 0;
      p_finalResultSize[9] = 0;
      p_finalResultSize[10] = 0;
      p_finalResultSize += 11;
      *p_finalResultSize = 0;
    }
    while ( v10 < *numStats );
  }
  if ( *numStats > 0 )
  {
    v12 = 1;
    v13 = stats;
    do
    {
      v14 = v12;
      if ( v12 < *numStats )
      {
        p_userName = &v13[1].userName;
        do
        {
          if ( idStr::Cmp(s1: *p_userName, s2: v13->userName) < 0 )
          {
            memcpy(Dst: v55, Src: p_userName, Size: sizeof(v55));
            memcpy(Dst: p_userName, Src: v13, Size: 0x2Cu);
            memcpy(Dst: v13, Src: v55, Size: sizeof(queryDataStats_t));
          }
          ++v14;
          p_userName += 11;
        }
        while ( v14 < *numStats );
      }
      ++v12;
      ++v13;
    }
    while ( v12 - 1 < *numStats );
  }
  for ( i = this->modelQueryFirstSubmittedIndex;
        (unsigned int)i <= LODWORD(this->modelQueryLastAllocedIndex);
        LODWORD(i) = i + 1 )
  {
    v17 = (_DWORD *)((char *)this + (((_DWORD)i << 7) & 0x3FF80));
    v18 = (const char *)v17[7];
    if ( v18 == nullptr )
      v18 = "*Unknown*";
    v19 = 0;
    if ( *numStats > 0 )
    {
      v20 = stats;
      do
      {
        if ( v18 == v20->userName )
          break;
        ++v19;
        ++v20;
      }
      while ( v19 < *numStats );
    }
    if ( v19 < maxStats )
    {
      v21 = v19 + 1;
      if ( *numStats > v19 + 1 )
        v21 = *numStats;
      *numStats = v21;
      if ( (unsigned int)(*v17 - 1) > 8 )
      {
        v22 = 0;
      }
      else if ( *v17 == 2 || *v17 == 3 || *v17 == 4 || *v17 == 5 || *v17 == 6 || *v17 == 1 )
      {
        v22 = 192;
      }
      else
      {
        v22 = 992;
      }
      v23 = &stats[v19];
      v23->userName = v18;
      numSubModelQueries = v23->numSubModelQueries;
      v25 = v23->numModelQueries + 1;
      v23->numCollisionQueries += (_cntlzw(v17[10]) & 0x20) != 0;
      v23->numModelQueries = v25;
      v23->numSubModelQueries = numSubModelQueries + v17[12];
      v26 = v17[12];
      if ( v26 < 1 )
        v26 = 1;
      v28 = v26 * v22 + v23->queryDataSize;
      finalResultSize = v23->finalResultSize;
      v23->queryDataSize = v28;
      v23->finalResultSize = (v17[9] == 0 ? 0 : v22) + finalResultSize;
    }
  }
  v29 = 0;
  if ( *numStats > 0 )
  {
    v30 = &stats[-1].finalResultSize;
    do
    {
      v31 = v30[7];
      v32 = v30[12];
      if ( v32 <= v31 )
        v32 = v30[7];
      v33 = v30[13];
      v34 = v30[8];
      v30[12] = v32;
      v35 = v33;
      if ( v33 <= v34 )
        v35 = v34;
      v36 = v30[14];
      v37 = v30[9];
      v30[13] = v35;
      v38 = v36;
      if ( v36 <= v37 )
        v38 = v37;
      v39 = v30[15];
      v40 = v30[10];
      v30[14] = v38;
      v41 = v39;
      if ( v39 <= v40 )
        v41 = v40;
      v42 = v30[11];
      v43 = v30[16];
      v30[15] = v41;
      if ( v43 > v42 )
        v42 = v43;
      v30[16] = v42;
      ++v29;
      numModelQueries = totalStats->numModelQueries;
      totalStats->numCollisionQueries += v31;
      v45 = totalStats->numSubModelQueries;
      totalStats->numModelQueries = numModelQueries + v30[8];
      queryDataSize = totalStats->queryDataSize;
      totalStats->numSubModelQueries = v30[9] + v45;
      v47 = totalStats->finalResultSize;
      totalStats->queryDataSize = queryDataSize + v30[10];
      v30 += 11;
      totalStats->finalResultSize = *v30 + v47;
    }
    while ( v29 < *numStats );
  }
  maxCollisionQueries = totalStats->maxCollisionQueries;
  if ( maxCollisionQueries <= totalStats->numCollisionQueries )
    maxCollisionQueries = totalStats->numCollisionQueries;
  totalStats->maxCollisionQueries = maxCollisionQueries;
  maxModelQueries = totalStats->maxModelQueries;
  if ( maxModelQueries <= totalStats->numModelQueries )
    maxModelQueries = totalStats->numModelQueries;
  totalStats->maxModelQueries = maxModelQueries;
  maxSubModelQueries = totalStats->maxSubModelQueries;
  if ( maxSubModelQueries <= totalStats->numSubModelQueries )
    maxSubModelQueries = totalStats->numSubModelQueries;
  totalStats->maxSubModelQueries = maxSubModelQueries;
  maxQueryDataSize = totalStats->maxQueryDataSize;
  if ( maxQueryDataSize <= totalStats->queryDataSize )
    maxQueryDataSize = totalStats->queryDataSize;
  totalStats->maxQueryDataSize = maxQueryDataSize;
  v52 = totalStats->finalResultSize;
  maxFinalResultSize = totalStats->maxFinalResultSize;
  if ( maxFinalResultSize <= v52 )
    totalStats->maxFinalResultSize = v52;
  else
    totalStats->maxFinalResultSize = maxFinalResultSize;
  return *numStats;
}


// ========================================================================
// ?EndFrame@idQueryData@@QAAXXZ
// EA  : 0x825D7498
// RVA : 0x005D7498
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idQueryData::EndFrame(idQueryData *this)
{
  __int64 v1; // r28
  int *p_failedModelQuery; // r24
  int v4; // r27
  int *p_numCollisionQueries; // r30
  int v6; // r8
  int v7; // r4
  int v8; // r7
  int v9; // r5
  int v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  va *v14; // r3
  int failedSubModelQuery; // r11
  __int64 v16; // r6
  va *v17; // r3
  int failedQueryParms; // r11
  __int64 v19; // r6
  va *v20; // r3
  int failedSlideMoveState; // r11
  __int64 v22; // r6
  va *v23; // r3
  int failedIntermediateResults; // r11
  __int64 v25; // r6
  va *v26; // r3
  int failedFinalResults; // r11
  __int64 v28; // r6
  va *v29; // r3
  int failedMergeResults; // r4
  int v31; // r6 OVERLAPPED
  __int128 v32; // r5 OVERLAPPED
  unsigned __int64 finalResultsFirstAllocedOffset; // r11
  __int128 v34; // r9
  int v35; // r3
  int v36; // [sp+8h] [-1728h]
  int v37; // [sp+Ch] [-1724h]
  int v38; // [sp+10h] [-1720h]
  int v39; // [sp+14h] [-171Ch]
  int v40; // [sp+18h] [-1718h]
  int v41; // [sp+1Ch] [-1714h]
  int v42[4]; // [sp+50h] [-16E0h] BYREF
  idStr v43; // [sp+60h] [-16D0h] BYREF
  queryDataStats_t v44; // [sp+80h] [-16B0h] BYREF
  _BYTE v45[5632]; // [sp+B0h] [-1680h] BYREF

  p_failedModelQuery = &this->failedModelQuery;
  LODWORD(v1) = 0;
  this->started = false;
  if ( this->failedModelQuery > 0
    || this->failedSubModelQuery > 0
    || this->failedQueryParms > 0
    || this->failedSlideMoveState > 0
    || this->failedIntermediateResults > 0
    || this->failedFinalResults > 0
    || this->failedMergeResults > 0 )
  {
    v42[0] = 0;
    memset(Dst: v45, Val: 0, Size: sizeof(v45));
    *(_QWORD *)&v44.userName = v1;
    *(_QWORD *)&v44.numModelQueries = v1;
    *(_QWORD *)&v44.queryDataSize = v1;
    *(_QWORD *)&v44.maxCollisionQueries = v1;
    *(_QWORD *)&v44.maxSubModelQueries = v1;
    v44.maxFinalResultSize = 0;
    idQueryData::UpdateQueryDataStats(
      this,
      stats: (queryDataStats_t *)v45,
      numStats: v42,
      maxStats: 128,
      totalStats: &v44);
    idLib::Printf(fmt: ".............................................\n");
    v4 = v42[0];
    if ( v42[0] > 0 )
    {
      p_numCollisionQueries = &v44.numCollisionQueries;
      do
      {
        v6 = p_numCollisionQueries[16] >> 10;
        v7 = p_numCollisionQueries[12];
        v8 = p_numCollisionQueries[15] >> 10;
        v9 = p_numCollisionQueries[13];
        v10 = p_numCollisionQueries[14];
        p_numCollisionQueries += 11;
        idLib::Printf(
          fmt: "%4d queries, %4d mdl queries, %4d sub-mdl queries, %4d kB temp, %4d kB final, %s\n",
          v7,
          v9,
          v10,
          v8,
          v6,
          (const char *)*p_numCollisionQueries);
        --v4;
      }
      while ( v4 != 0 );
    }
    idLib::Printf(fmt: ".............................................\n");
    idLib::Printf(
      fmt: "%4d queries, %4d mdl queries, %4d sub-mdl queries, %4d kB temp, %4d kB final, total\n",
      v44.numCollisionQueries,
      v44.numModelQueries,
      v44.numSubModelQueries,
      v44.queryDataSize >> 10,
      v44.finalResultSize >> 10);
    idLib::Printf(
      fmt: "%4d queries, %4d mdl queries, %4d sub-mdl queries, %4d kB temp, %4d kB final, maximum\n",
      2048,
      2048,
      4096,
      1024,
      512);
    v43.len = 0;
    v43.allocedAndFlag = 20;
    v43.data = v43.baseBuffer;
    v43.baseBuffer[0] = 0;
    if ( *p_failedModelQuery > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v13) = 2048;
      HIDWORD(v13) = *p_failedModelQuery + 2048;
      v14 = va::va(
              this: (va *)v45,
              fmt: " Model Queries (%d/%d)",
              a3: v13,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v14);
      *p_failedModelQuery = 0;
    }
    failedSubModelQuery = this->failedSubModelQuery;
    if ( failedSubModelQuery > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v16) = 4096;
      HIDWORD(v16) = failedSubModelQuery + 4096;
      v17 = va::va(
              this: (va *)v45,
              fmt: " Sub-Model Queries (%d/%d)",
              a3: v16,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v17);
      this->failedSubModelQuery = 0;
    }
    failedQueryParms = this->failedQueryParms;
    if ( failedQueryParms > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v19) = 2048;
      HIDWORD(v19) = failedQueryParms + 2048;
      v20 = va::va(
              this: (va *)v45,
              fmt: " Query Parms (%d/%d)",
              a3: v19,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v20);
      this->failedQueryParms = 0;
    }
    failedSlideMoveState = this->failedSlideMoveState;
    if ( failedSlideMoveState > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v22) = 128;
      HIDWORD(v22) = failedSlideMoveState + 128;
      v23 = va::va(
              this: (va *)v45,
              fmt: " Slide Move States (%d/%d)",
              a3: v22,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v23);
      this->failedSlideMoveState = 0;
    }
    failedIntermediateResults = this->failedIntermediateResults;
    if ( failedIntermediateResults > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v25) = 1024;
      HIDWORD(v25) = (failedIntermediateResults + 0x100000) >> 10;
      v26 = va::va(
              this: (va *)v45,
              fmt: " Intermediate Result Bytes (%d kB/%d kB)",
              a3: v25,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v26);
      this->failedIntermediateResults = 0;
    }
    failedFinalResults = this->failedFinalResults;
    if ( failedFinalResults > 0 )
    {
      LODWORD(v11) = &unk_821B0000;
      LODWORD(v28) = 512;
      HIDWORD(v28) = (failedFinalResults + 0x80000) >> 10;
      v29 = va::va(
              this: (va *)v45,
              fmt: " Final Result Bytes (%d kB/%d kB)",
              a3: v28,
              a4: v12,
              a5: v11,
              a6: v36,
              a7: v37,
              a8: v38,
              a9: v39,
              a10: v40,
              a11: v41);
      idStr::Append(this: &v43, text: v29);
      this->failedFinalResults = 0;
    }
    if ( v43.len != 0 )
      idLib::Warning(fmt: "Collision Detection system ran out of free%s", v43.data);
    failedMergeResults = this->failedMergeResults;
    if ( failedMergeResults > 0 )
    {
      idLib::Warning(
        fmt: "%d collision detection querie(s) needed more than %d kB of merge results",
        failedMergeResults,
        32);
      this->failedMergeResults = 0;
    }
    idStr::FreeData(this: &v43);
  }
  v31 = 2381872;
  *((_QWORD *)&v32 + 1) = this->modelQueryFirstAllocedIndex;
  *(_QWORD *)((char *)&v32 + 4) = this->subModelQueryFirstAllocedIndex;
  this->modelQueryFirstSubmittedIndex = v32;
  idQueryData::AdvanceSubModelQueryFirstSubmittedIndex(
    this: (idQueryData *)DWORD1(v32),
    a2: DWORD2(v32),
    newIndex: *(unsigned __int64 *)&v31);
  finalResultsFirstAllocedOffset = this->finalResultsFirstAllocedOffset;
  *((_QWORD *)&v34 + 1) = this->queryParmsFirstAllocedIndex;
  *(_QWORD *)((char *)&v34 + 4) = *(_QWORD *)((char *)&this->modelQueries[0].type + DWORD2(v34));
  *(_QWORD *)&v34 = *(_QWORD *)((char *)&this->modelQueries[0].type + DWORD1(v34));
  v35 = HIDWORD(finalResultsFirstAllocedOffset) | 0x58A0;
  HIDWORD(finalResultsFirstAllocedOffset) = &idDeclReachIK::resourceList.hashTable[243];
  *(_QWORD *)((char *)&this->modelQueries[0].type + HIDWORD(v34)) = v34;
  this->slideMoveStateFirstSubmittedIndex = *(_QWORD *)((char *)&v34 + 4);
  *(_QWORD *)((char *)&this->modelQueries[0].type + v35) = finalResultsFirstAllocedOffset;
  this->intermediateResultsFirstSubmittedOffset = *(_QWORD *)&v34;
  *(_QWORD *)(HIDWORD(finalResultsFirstAllocedOffset) - 18144) = finalResultsFirstAllocedOffset;
}


// ========================================================================
// __unwind$229616
// EA  : 0x825D7890
// RVA : 0x005D7890
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

void _unwind_229616()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5936 + 96));
}


// ========================================================================
// ?Clear@idQueryData@@QAAXXZ
// EA  : 0x825DC7F8
// RVA : 0x005DC7F8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

void __fastcall idQueryData::Clear(idQueryData *this)
{
  this->modelQueryFirstAllocedIndex = 0x24581000000001LL;
  this->subModelQueryFirstSubmittedIndex = 0x24581000000001LL;
  this->slideMoveStateFirstAllocedIndex = 0x24581000000001LL;
  this->subModelQueryFirstAllocedIndex = 0x24581000000001LL;
  this->queryParmsFirstSubmittedIndex = 0x24581000000001LL;
  this->queryParmsFirstAllocedIndex = 0x24581000000001LL;
  this->slideMoveStateFirstSubmittedIndex = 0x24582800000001LL;
  this->modelQueryLastAllocedIndex = 0x100000000LL;
  this->subModelQueryLastSubmittedIndex = 0x100000000LL;
  this->subModelQueryLastAllocedIndex = 0x100000000LL;
  this->queryParmsLastSubmittedIndex = 0x100000000LL;
  this->queryParmsLastAllocedIndex = 0x100000000LL;
  this->slideMoveStateLastSubmittedIndex = 0x100000000LL;
  this->slideMoveStateLastAllocedIndex = 0x100000000LL;
  this->modelQueryFirstSubmittedIndex = 0x24588000000001LL;
  this->intermediateResultsFirstSubmittedOffset = 16;
  this->intermediateResultsLastSubmittedOffset = 16;
  this->modelQueryLastSubmittedIndex = 0x24000000000000LL;
  this->intermediateResultsFirstAllocedOffset = 16;
  this->intermediateResultsLastAllocedOffset = 16;
  this->finalResultsFirstSubmittedOffset = 16;
  this->finalResultsLastSubmittedOffset = 16;
  this->finalResultsFirstAllocedOffset = 16;
  this->finalResultsLastAllocedOffset = 16;
  this->started = false;
  this->failedModelQuery = 0;
  this->failedSubModelQuery = 0;
  this->failedQueryParms = 0;
  this->failedIntermediateResults = 0;
  this->failedFinalResults = 0;
  this->failedSlideMoveState = 0;
  this->failedMergeResults = 0;
}


// ========================================================================
// ?ReleaseQueryOnlyData@idQueryData@@QAAXXZ
// EA  : 0x825DC9A0
// RVA : 0x005DC9A0
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idQueryData::ReleaseQueryOnlyData(idQueryData *this, unsigned __int64 a2)
{
  int v2; // r6
  unsigned __int64 intermediateResultsLastSubmittedOffset; // r5 OVERLAPPED
  __int64 v5; // r7 OVERLAPPED

  v2 = 2381864;
  LODWORD(a2) = LODWORD(this->modelQueryLastSubmittedIndex) + 1;
  this->modelQueryFirstSubmittedIndex = a2;
  idQueryData::AdvanceSubModelQueryFirstSubmittedIndex(
    this,
    a2: LODWORD(this->subModelQueryLastSubmittedIndex) + 1,
    newIndex: *(unsigned __int64 *)((char *)&a2 - 4));
  intermediateResultsLastSubmittedOffset = this->intermediateResultsLastSubmittedOffset;
  LODWORD(v5) = LODWORD(this->queryParmsLastSubmittedIndex) + 1;
  HIDWORD(v5) = LODWORD(this->slideMoveStateLastSubmittedIndex) + 1;
  *(_QWORD *)((char *)&this->modelQueries[0].type + HIDWORD(intermediateResultsLastSubmittedOffset)) = v5;
  this->slideMoveStateFirstSubmittedIndex = *(unsigned __int64 *)((char *)&intermediateResultsLastSubmittedOffset - 4);
  this->intermediateResultsFirstSubmittedOffset = intermediateResultsLastSubmittedOffset;
}


// ========================================================================
// ??0timings_t@@QAA@XZ
// EA  : 0x825DCDC8
// RVA : 0x005DCDC8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

timings_t *__fastcall timings_t::timings_t(timings_t *this)
{
  this->max = 0;
  this->min = -1;
  this->total = 0;
  this->count = 0;
  return this;
}


// ========================================================================
// ?AllocModelQuery@idQueryData@@QAAPAUmodelQuery_t@@XZ
// EA  : 0x825DCDE8
// RVA : 0x005DCDE8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

modelQuery_t *__fastcall idQueryData::AllocModelQuery(idQueryData *this)
{
  unsigned __int64 modelQueryLastAllocedIndex; // r11
  modelQuery_t *result; // r3
  unsigned int v3; // r10

  modelQueryLastAllocedIndex = this->modelQueryLastAllocedIndex;
  if ( (unsigned int)(modelQueryLastAllocedIndex - LODWORD(this->modelQueryFirstSubmittedIndex) + 1) < 0x800 )
  {
    LODWORD(modelQueryLastAllocedIndex) = modelQueryLastAllocedIndex + 1;
    this->modelQueryLastAllocedIndex = modelQueryLastAllocedIndex;
    result = (modelQuery_t *)((((_DWORD)modelQueryLastAllocedIndex << 7) & 0x3FF80) + HIDWORD(modelQueryLastAllocedIndex));
    v3 = ((unsigned int)&result->pad[5] + 3) & 0xFFFFFF80;
    do
    {
      __asm { dcbz128   0, r10 }
      v3 += 128;
    }
    while ( v3 <= (((unsigned int)&result->pad[5] + 3) & 0xFFFFFF80) );
  }
  else
  {
    ++*(_DWORD *)(HIDWORD(modelQueryLastAllocedIndex) + 2382020);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?AllocSubModelQuery@idQueryData@@QAAPAUsubModelQuery_t@@XZ
// EA  : 0x825DCE68
// RVA : 0x005DCE68
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

subModelQuery_t *__fastcall idQueryData::AllocSubModelQuery(idQueryData *this)
{
  unsigned __int64 subModelQueryLastAllocedIndex; // r11
  subModelQuery_t *result; // r3
  unsigned int v3; // r11
  unsigned int i; // r10

  subModelQueryLastAllocedIndex = this->subModelQueryLastAllocedIndex;
  if ( (unsigned int)(subModelQueryLastAllocedIndex - LODWORD(this->subModelQueryFirstSubmittedIndex) + 5) < 0x1000 )
  {
    LODWORD(subModelQueryLastAllocedIndex) = subModelQueryLastAllocedIndex + 1;
    this->subModelQueryLastAllocedIndex = subModelQueryLastAllocedIndex;
    result = (subModelQuery_t *)(32 * ((subModelQueryLastAllocedIndex & 0xFFF) + 0x2000)
                               + HIDWORD(subModelQueryLastAllocedIndex));
    v3 = ((unsigned int)&result[3].nextOnModelQuery + 3) & 0xFFFFFF80;
    for ( i = ((unsigned int)&result->nextOnModelQuery + 3) & 0xFFFFFF80; v3 <= i; v3 += 128 )
      __asm { dcbz128   0, r11 }
  }
  else
  {
    ++*(_DWORD *)(HIDWORD(subModelQueryLastAllocedIndex) + 2382024);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?AllocQueryParms@idQueryData@@QAAPAUqueryParms_t@@XZ
// EA  : 0x825DCEF8
// RVA : 0x005DCEF8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

queryParms_t *__fastcall idQueryData::AllocQueryParms(idQueryData *this)
{
  unsigned __int64 queryParmsLastAllocedIndex; // r11
  queryParms_t *result; // r3
  unsigned int v3; // r11
  unsigned int i; // r10

  queryParmsLastAllocedIndex = this->queryParmsLastAllocedIndex;
  if ( (unsigned int)(queryParmsLastAllocedIndex - LODWORD(this->queryParmsFirstSubmittedIndex) + 2) < 0x800 )
  {
    LODWORD(queryParmsLastAllocedIndex) = queryParmsLastAllocedIndex + 1;
    this->queryParmsLastAllocedIndex = queryParmsLastAllocedIndex;
    result = (queryParms_t *)(192 * ((queryParmsLastAllocedIndex & 0x7FF) + 2048) + HIDWORD(queryParmsLastAllocedIndex));
    v3 = ((unsigned int)&result->modelOrigin.x + 3) & 0xFFFFFF80;
    for ( i = ((unsigned int)&result->selfId + 3) & 0xFFFFFF80; v3 <= i; v3 += 128 )
      __asm { dcbz128   0, r11 }
  }
  else
  {
    ++*(_DWORD *)(HIDWORD(queryParmsLastAllocedIndex) + 2382028);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?AllocSlideMoveState@idQueryData@@QAAPAUslideMoveState_t@@XZ
// EA  : 0x825DCF90
// RVA : 0x005DCF90
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

slideMoveState_t *__fastcall idQueryData::AllocSlideMoveState(idQueryData *this)
{
  unsigned __int64 slideMoveStateLastAllocedIndex; // r11
  slideMoveState_t *result; // r3
  int v3; // r7
  unsigned int v4; // r11
  unsigned int i; // r10

  slideMoveStateLastAllocedIndex = this->slideMoveStateLastAllocedIndex;
  if ( (unsigned int)(slideMoveStateLastAllocedIndex - LODWORD(this->slideMoveStateFirstSubmittedIndex) + 2) < 0x80 )
  {
    LODWORD(slideMoveStateLastAllocedIndex) = slideMoveStateLastAllocedIndex + 1;
    this->slideMoveStateLastAllocedIndex = slideMoveStateLastAllocedIndex;
    v3 = 176 * (slideMoveStateLastAllocedIndex & 0x7F) + HIDWORD(slideMoveStateLastAllocedIndex);
    result = (slideMoveState_t *)(v3 + 786432);
    v4 = (v3 + 786559) & 0xFFFFFF80;
    for ( i = (v3 + 786607) & 0xFFFFFF80; v4 <= i; v4 += 128 )
      __asm { dcbz128   0, r11 }
  }
  else
  {
    ++*(_DWORD *)(HIDWORD(slideMoveStateLastAllocedIndex) + 2382040);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?AllocIntermediateResults@idQueryData@@QAAPAUqueryResults_t@@II@Z
// EA  : 0x825DD020
// RVA : 0x005DD020
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

queryResults_t *__fastcall idQueryData::AllocIntermediateResults(
        idQueryData *this,
        unsigned int numResults,
        unsigned int resultSize)
{
  unsigned int v3; // r6
  unsigned __int64 intermediateResultsFirstSubmittedOffset; // r4
  unsigned __int64 *p_intermediateResultsLastAllocedOffset; // r8
  __int64 v6; // r11
  unsigned __int64 v7; // r9
  queryResults_t *result; // r3
  unsigned int v9; // r7
  unsigned int i; // r10

  v3 = numResults * resultSize;
  p_intermediateResultsLastAllocedOffset = &this->intermediateResultsLastAllocedOffset;
  LODWORD(v6) = numResults * resultSize;
  intermediateResultsFirstSubmittedOffset = this->intermediateResultsFirstSubmittedOffset;
  HIDWORD(v6) = HIDWORD(intermediateResultsFirstSubmittedOffset);
  v7 = *p_intermediateResultsLastAllocedOffset;
  if ( (unsigned int)(v6 - intermediateResultsFirstSubmittedOffset + v7 + 128) < 0x100000 )
  {
    LODWORD(v6) = v6 + v7;
    LODWORD(v7) = v7 & 0xFFFFF;
    *(_QWORD *)HIDWORD(v7) = v6;
    v9 = v6 & 0xFFF00000;
    LODWORD(v6) = (v6 + 0x8000) & 0xFFF00000;
    result = (queryResults_t *)(v7 + HIDWORD(intermediateResultsFirstSubmittedOffset) + 808960);
    if ( (unsigned int)v6 > v9 )
      *(_QWORD *)HIDWORD(v7) = v6;
    _R11 = (v7 + HIDWORD(v6) + 809087) & 0xFFFFFF80;
    for ( i = ((unsigned int)result + v3 - 1) & 0xFFFFFF80; _R11 <= i; _R11 += 128 )
    {
      __asm
      {
        dcbz128   0, r11
        dcbf      0, r11
      }
    }
  }
  else
  {
    *(_DWORD *)(HIDWORD(intermediateResultsFirstSubmittedOffset) + 2382032) += v3;
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?AllocFinalResult@idQueryData@@QAAPAUqueryResults_t@@I@Z
// EA  : 0x825DD0E8
// RVA : 0x005DD0E8
// PDB : w:\tech5\engine\cm\collisionqueryjobmanager.h
// ========================================================================

queryResults_t *__fastcall idQueryData::AllocFinalResult(idQueryData *this, unsigned __int64 totalSize)
{
  unsigned __int64 *p_finalResultsLastAllocedOffset; // r11
  unsigned int v3; // r6
  unsigned __int64 finalResultsLastAllocedOffset; // r10
  queryResults_t *result; // r3
  int v6; // r6
  unsigned int v8; // r10

  p_finalResultsLastAllocedOffset = &this->finalResultsLastAllocedOffset;
  finalResultsLastAllocedOffset = this->finalResultsLastAllocedOffset;
  v3 = finalResultsLastAllocedOffset & 0xFFF80000;
  LODWORD(finalResultsLastAllocedOffset) = (HIDWORD(totalSize) + finalResultsLastAllocedOffset) & 0xFFF80000;
  if ( (unsigned int)finalResultsLastAllocedOffset > v3 )
    *p_finalResultsLastAllocedOffset = finalResultsLastAllocedOffset;
  if ( (unsigned int)(HIDWORD(totalSize)
                    - *(_DWORD *)(HIDWORD(this->finalResultsLastAllocedOffset) + 2381988)
                    + LODWORD(this->finalResultsLastAllocedOffset)
                    + 128) < 0x80000 )
  {
    idCollisionQuery::finalResultsLastAllocedOffset = *p_finalResultsLastAllocedOffset;
    v6 = (this->finalResultsLastAllocedOffset & 0x7FFFF) + HIDWORD(this->finalResultsLastAllocedOffset);
    LODWORD(totalSize) = HIDWORD(totalSize) + LODWORD(this->finalResultsLastAllocedOffset);
    *p_finalResultsLastAllocedOffset = totalSize;
    result = (queryResults_t *)(v6 + 1857536);
    v8 = (v6 + 1857536 + HIDWORD(totalSize) - 1) & 0xFFFFFF80;
    for ( _R11 = (v6 + 1857663) & 0xFFFFFF80; _R11 <= v8; _R11 += 128 )
    {
      __asm
      {
        dcbz128   0, r11
        dcbf      0, r11
      }
    }
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)p_finalResultsLastAllocedOffset + 2382036) += HIDWORD(totalSize);
    return nullptr;
  }
  return result;
}

