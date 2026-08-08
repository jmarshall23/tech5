
// ========================================================================
// ?IsJobHidden@idDeclJob@@QBA_NXZ
// EA  : 0x82BC59B0
// RVA : 0x00BC59B0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

BOOL __fastcall idDeclJob::IsJobHidden(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11

  jobType = this->jobType;
  return jobType == JOBTYPE_APPROACHVO || jobType == JOBTYPE_RADIOVO || (_cntlzw(jobType - 8) & 0x20) != 0;
}


// ========================================================================
// ?IsJobImportant@idDeclJob@@QBA_NXZ
// EA  : 0x82BC59E0
// RVA : 0x00BC59E0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::IsJobImportant(idDeclJob *this)
{
  unsigned __int8 v1; // r11

  if ( this->jobType == JOBTYPE_REQUIRED )
    return 1;
  v1 = 0;
  if ( this->treatAsImportantIfNotRequired )
    return 1;
  return v1;
}


// ========================================================================
// ?IsJobImportantForActiveJob@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5A08
// RVA : 0x00BC5A08
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::IsJobImportantForActiveJob(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  jobType = this->jobType;
  switch ( jobType )
  {
    case JOBTYPE_REQUIRED:
      return 1;
    case JOBTYPE_OPTIONAL:
      return 1;
    case JOBTYPE_OPTIONAL_POSTED:
      return 1;
    default:
      break;
  }
  v3 = jobType != JOBTYPE_SIMPLE;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?UseDynamicJobHud@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5A40
// RVA : 0x00BC5A40
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::UseDynamicJobHud(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  jobType = this->jobType;
  if ( jobType == JOBTYPE_DYNAMIC_COMBAT )
    return 1;
  v3 = jobType != JOBTYPE_DYNAMIC_OTHER;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?DontSaveProgressToFile@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5A68
// RVA : 0x00BC5A68
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

BOOL __fastcall idDeclJob::DontSaveProgressToFile(idDeclJob *this)
{
  return (_cntlzw(this->jobType - 10) & 0x20) != 0;
}


// ========================================================================
// ?ShowsGUI@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5A80
// RVA : 0x00BC5A80
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

BOOL __fastcall idDeclJob::ShowsGUI(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11

  jobType = this->jobType;
  return (jobType == JOBTYPE_REQUIRED
       || jobType == JOBTYPE_OPTIONAL
       || jobType == JOBTYPE_OPTIONAL_POSTED
       || jobType == JOBTYPE_REPEATING
       || jobType == JOBTYPE_JUSTGUI)
      && this->normalFlowVars.showsGUI;
}


// ========================================================================
// ?IsQuestJob@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5AC0
// RVA : 0x00BC5AC0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::IsQuestJob(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  jobType = this->jobType;
  switch ( jobType )
  {
    case JOBTYPE_OPTIONAL:
      return 1;
    case JOBTYPE_OPTIONAL_POSTED:
      return 1;
    case JOBTYPE_REQUIRED:
      return 1;
    case JOBTYPE_SIMPLE:
      return 1;
    default:
      break;
  }
  v3 = jobType != JOBTYPE_REPEATING;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?IsSimple@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5B00
// RVA : 0x00BC5B00
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

BOOL __fastcall idDeclJob::IsSimple(idDeclJob *this)
{
  return (_cntlzw(this->jobType - 2) & 0x20) != 0;
}


// ========================================================================
// ?IsOptionalQuestJob@idDeclJob@@QBA_NXZ
// EA  : 0x82BC5B18
// RVA : 0x00BC5B18
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::IsOptionalQuestJob(idDeclJob *this)
{
  idDeclJob::jobType_t jobType; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  jobType = this->jobType;
  if ( jobType == JOBTYPE_OPTIONAL )
    return 1;
  v3 = jobType != JOBTYPE_OPTIONAL_POSTED;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?GetJobName@idDeclJob@@QBA?AVidStrId@@XZ
// EA  : 0x82BC5B40
// RVA : 0x00BC5B40
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobName(idDeclJob *this, idStrId *result)
{
  this->__vftable = (idDeclJob_vtbl *)result[16].index;
  return this;
}


// ========================================================================
// ?GetJobSummary@idDeclJob@@QBA?AVidStrId@@XZ
// EA  : 0x82BC5B50
// RVA : 0x00BC5B50
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobSummary(idDeclJob *this, idStrId *result)
{
  this->__vftable = (idDeclJob_vtbl *)result[17].index;
  return this;
}


// ========================================================================
// ?GetJobRequirements@idDeclJob@@QBA?AVidStrId@@XZ
// EA  : 0x82BC5B60
// RVA : 0x00BC5B60
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobRequirements(idDeclJob *this, idStrId *result)
{
  this->__vftable = (idDeclJob_vtbl *)result[18].index;
  return this;
}


// ========================================================================
// ?GetJobReward@idDeclJob@@QBA?AVidStrId@@XZ
// EA  : 0x82BC5B70
// RVA : 0x00BC5B70
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobReward(idDeclJob *this, idStrId *result)
{
  this->__vftable = (idDeclJob_vtbl *)result[19].index;
  return this;
}


// ========================================================================
// ?GetMaterial@idMapPatch@@QBAPBDXZ
// EA  : 0x82BC5B80
// RVA : 0x00BC5B80
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

XGRAPHICS::__AS_STATE_MAP_INFO *__fastcall idMapPatch::GetMaterial(_DWORD *hSSMDev)
{
  return (XGRAPHICS::__AS_STATE_MAP_INFO *)hSSMDev[31];
}


// ========================================================================
// ?GetJobPrecondition@idDeclJob@@QBAPBVjobPreCondition_t@1@H@Z
// EA  : 0x82BC5B88
// RVA : 0x00BC5B88
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

const idDeclJob::jobPreCondition_t *__fastcall idDeclJob::GetJobPrecondition(idDeclJob *this, int idx)
{
  return &this->preconditions.list[idx];
}


// ========================================================================
// ?GetNumJobRewards@idDeclJob@@QBAHXZ
// EA  : 0x82BC5B98
// RVA : 0x00BC5B98
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::GetNumJobRewards(idDeclJob *this)
{
  return this->rewards.num;
}


// ========================================================================
// ?GetJobReward@idDeclJob@@QBAPBVjobReward_t@1@H@Z
// EA  : 0x82BC5BA0
// RVA : 0x00BC5BA0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

const idDeclJob::jobReward_t *__fastcall idDeclJob::GetJobReward(idDeclJob *this, int idx)
{
  return &this->rewards.list[idx];
}


// ========================================================================
// ?GetNumDebugRewards@idDeclJob@@QBAHXZ
// EA  : 0x82BC5BB8
// RVA : 0x00BC5BB8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::GetNumDebugRewards(idDeclJob *this)
{
  return this->debugInfo.debug_completed.debugRewards.num
       + this->debugInfo.debug_readyToTurnIn.debugRewards.num
       + this->debugInfo.debug_accepted.debugRewards.num;
}


// ========================================================================
// ?ProcessingStage@CX2SubmixVoice@XAUDIO2@@UBAIXZ
// EA  : 0x82BC5BD0
// RVA : 0x00BC5BD0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

ILeapFilter *__fastcall XAUDIO2::CX2SubmixVoice::ProcessingStage(XAUDIO2::CX2SubmixVoice *this)
{
  return this->m_pPreSubmixMarker;
}


// ========================================================================
// ?GetNumConstraints@idPhysics_AF@@QBAHXZ
// EA  : 0x82BC5BD8
// RVA : 0x00BC5BD8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idPhysics_AF::GetNumConstraints(idPhysics_AF *this)
{
  return this->constraints.num;
}


// ========================================================================
// ?GetNumCompletionRequirements@idDeclJob@@QBAHXZ
// EA  : 0x82BC5BE0
// RVA : 0x00BC5BE0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::GetNumCompletionRequirements(idDeclJob *this)
{
  return this->completion.num;
}


// ========================================================================
// ?GetCompletionRequirement@idDeclJob@@QBAPBVjobComplete_t@1@H@Z
// EA  : 0x82BC5BE8
// RVA : 0x00BC5BE8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

const idDeclJob::jobComplete_t *__fastcall idDeclJob::GetCompletionRequirement(idDeclJob *this, int idx)
{
  return &this->completion.list[idx];
}


// ========================================================================
// ?AIMatchesJobCompleteNPC@idDeclJob@@QBA_NPBVidAI2@@@Z
// EA  : 0x82BC5BF8
// RVA : 0x00BC5BF8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

int __fastcall idDeclJob::AIMatchesJobCompleteNPC(idDeclJob *this, const idAI2 *inAI2)
{
  int index; // r11
  int result; // r3

  if ( inAI2 == nullptr )
    return 0;
  index = this->completeNPCName.index;
  result = 1;
  if ( index != inAI2->npcName.index )
    return 0;
  return result;
}


// ========================================================================
// ??0idGameStateInt@@QAA@XZ
// EA  : 0x82BC5C20
// RVA : 0x00BC5C20
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idGameStateInt *__fastcall idGameStateInt::idGameStateInt(idGameStateInt *this)
{
  this->decl = nullptr;
  this->__vftable = (idGameStateInt_vtbl *)&idGameStateInt::`vftable';
  this->gameStateValue = 0;
  return this;
}


// ========================================================================
// ??0idGameStateInt@@QAA@PBVidDeclGameStateInt@@@Z
// EA  : 0x82BC5C40
// RVA : 0x00BC5C40
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idGameStateInt *__fastcall idGameStateInt::idGameStateInt(
        idGameStateInt *this,
        const idDeclGameStateInt *gameStateDecl)
{
  this->decl = gameStateDecl;
  this->gameStateValue = 0;
  this->__vftable = (idGameStateInt_vtbl *)&idGameStateInt::`vftable';
  return this;
}


// ========================================================================
// ?BuildRewardDebugString@idDeclJob@@QBA?AVidStr@@VjobReward_t@1@AAV2@@Z
// EA  : 0x82BC5CD8
// RVA : 0x00BC5CD8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idDeclJob *__fastcall idDeclJob::BuildRewardDebugString(
        idDeclJob *this,
        idStr *result,
        const idDeclJob::jobReward_t *reward,
        __int64 debugString,
        int a5,
        int a6,
        idStr *a7)
{
  char *v9; // r4
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  char *LocalizedString; // r4
  va *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  char *count; // r4
  va *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  int v25; // [sp+8h] [-3078h]
  int v26; // [sp+Ch] [-3074h]
  int v27; // [sp+10h] [-3070h]
  int v28; // [sp+14h] [-306Ch]
  int v29; // [sp+18h] [-3068h]
  int v30; // [sp+1Ch] [-3064h]
  idStrId v31; // [sp+50h] [-3030h] BYREF
  idStrId v32; // [sp+54h] [-302Ch] BYREF
  idStrId v33; // [sp+58h] [-3028h] BYREF
  idStrId v34; // [sp+5Ch] [-3024h] BYREF
  va v35; // [sp+60h] [-3020h] BYREF
  va v36; // [sp+1060h] [-2020h] BYREF
  va v37; // [sp+2060h] [-1020h] BYREF
  __int64 v39; // [sp+30A8h] [+28h]

  v39 = *(__int64 *)((char *)&debugString + 4);
  switch ( (unsigned int)result )
  {
    case 0u:
      v9 = "NONE ? : ";
      break;
    case 1u:
      idStr::Append(this: a7, text: "ITEM : ");
      if ( reward != nullptr )
      {
        if ( (int)reward[4].gameStateIntDecl >= 0 )
          LocalizedString = (char *)idStrId::GetLocalizedString(this: (idStrId *)&reward[4].gameStateIntDecl);
        else
          LocalizedString = (char *)reward->count;
        idStr::Append(this: a7, text: LocalizedString);
      }
      HIDWORD(v12) = HIDWORD(v39);
      v14 = va::va(
              this: &v35,
              fmt: " %d",
              a3: v12,
              a4: v11,
              a5: v10,
              a6: v25,
              a7: v26,
              a8: v27,
              a9: v28,
              a10: v29,
              a11: v30);
      idStr::Append(this: a7, text: v14);
      goto LABEL_32;
    case 2u:
      idStr::Append(this: a7, text: "REMOVE ITEM : ");
      if ( reward != nullptr )
      {
        if ( (int)reward[4].gameStateIntDecl >= 0 )
          count = (char *)idStrId::GetLocalizedString(this: (idStrId *)&reward[4].gameStateIntDecl);
        else
          count = (char *)reward->count;
        idStr::Append(this: a7, text: count);
      }
      HIDWORD(v17) = HIDWORD(v39);
      v19 = va::va(
              this: &v36,
              fmt: " %d",
              a3: v17,
              a4: v16,
              a5: v15,
              a6: v25,
              a7: v26,
              a8: v27,
              a9: v28,
              a10: v29,
              a11: v30);
      idStr::Append(this: a7, text: v19);
      goto LABEL_32;
    case 3u:
      idStr::Append(this: a7, text: "FACTION : ");
      if ( (_DWORD)v39 == 0 )
        goto LABEL_32;
      v9 = *(char **)(v39 + 8);
      break;
    case 4u:
      idStr::Append(this: a7, text: "JOB COMPLETION: ");
      if ( HIDWORD(debugString) == 0 )
        goto LABEL_32;
      v32.index = *(_DWORD *)(HIDWORD(debugString) + 64);
      v9 = (char *)idStrId::GetLocalizedString(this: &v32);
      break;
    case 5u:
      idStr::Append(this: a7, text: "JOB ACCEPT: ");
      if ( HIDWORD(debugString) == 0 )
        goto LABEL_32;
      v34.index = *(_DWORD *)(HIDWORD(debugString) + 64);
      v9 = (char *)idStrId::GetLocalizedString(this: &v34);
      break;
    case 6u:
      idStr::Append(this: a7, text: "JOB REMVOE: ");
      if ( HIDWORD(debugString) == 0 )
        goto LABEL_32;
      v33.index = *(_DWORD *)(HIDWORD(debugString) + 64);
      v9 = (char *)idStrId::GetLocalizedString(this: &v33);
      break;
    case 7u:
      idStr::Append(this: a7, text: "JOB REMVOE IN PROGRESS: ");
      if ( HIDWORD(debugString) == 0 )
        goto LABEL_32;
      v31.index = *(_DWORD *)(HIDWORD(debugString) + 64);
      v9 = (char *)idStrId::GetLocalizedString(this: &v31);
      break;
    case 8u:
      v9 = "Use alternate hands: ";
      break;
    case 9u:
      idStr::Append(this: a7, text: "GAME STATE INT: ");
      if ( (_DWORD)debugString != 0 )
      {
        idStr::Append(this: a7, text: *(char **)(debugString + 8));
        HIDWORD(v20) = HIDWORD(v39);
        v23 = va::va(
                this: &v37,
                fmt: " %d",
                a3: v20,
                a4: v22,
                a5: v21,
                a6: v25,
                a7: v26,
                a8: v27,
                a9: v28,
                a10: v29,
                a11: v30);
        idStr::Append(this: a7, text: v23);
      }
      goto LABEL_32;
    case 0xAu:
      v9 = "Garage Reward";
      break;
    case 0xBu:
      v9 = "Activate Job";
      break;
    default:
      v9 = "ERROR!";
      break;
  }
  idStr::Append(this: a7, text: v9);
LABEL_32:
  idStr::idStr((idStr *)this, text: a7);
  return this;
}


// ========================================================================
// ?GetJobRewardDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC5FE8
// RVA : 0x00BC5FE8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobRewardDebugString(idDeclJob *this, idStr *result, int idx)
{
  char *v4; // r9
  int v5; // ctr
  _DWORD *v6; // r11
  idStr *v8; // [sp+8h] [-B8h]
  idStr v9; // [sp+60h] [-60h] BYREF
  idStr *v10; // [sp+80h] [-40h]
  const idDeclJob::jobReward_t *v11; // [sp+88h] [-38h]
  __int64 v12; // [sp+98h] [-28h]
  int v13; // [sp+A0h] [-20h]

  v4 = &v9.baseBuffer[16];
  v5 = 9;
  v6 = (_DWORD *)(*(_DWORD *)&result[5].baseBuffer[12] + 36 * idx - 4);
  do
  {
    ++v6;
    v4 += 4;
    *(_DWORD *)v4 = *v6;
    --v5;
  }
  while ( v5 != 0 );
  this->__vftable = nullptr;
  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  HIBYTE(this->nextOnHashChain) = 0;
  idDeclJob::BuildRewardDebugString(
    this: (idDeclJob *)&v9,
    result: v10,
    reward: v11,
    debugString: v12,
    a5: __ROL4__(v13, 32),
    a6: (int)this,
    a7: v8);
  idStr::FreeData(this: &v9);
  return this;
}


// ========================================================================
// __unwind$488952_0
// EA  : 0x82BC60A8
// RVA : 0x00BC60A8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_488952_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// ?GetJobDebugRewardDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC60F8
// RVA : 0x00BC60F8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobDebugRewardDebugString(idDeclJob *this, idStr *result, int idx)
{
  int v5; // r10
  char *v6; // r8
  int v7; // ctr
  char *v8; // r11
  char *v9; // r4
  int v10; // r11
  char *v11; // r7
  int v12; // ctr
  _DWORD *v13; // r11
  int v14; // r11
  char *v15; // r7
  int v16; // ctr
  char *v17; // r11
  idStr *v19; // [sp+8h] [-E8h]
  int allocedAndFlag; // [sp+54h] [-9Ch]
  int v21; // [sp+54h] [-9Ch]
  idStr v22; // [sp+60h] [-90h] BYREF
  idStr v23; // [sp+80h] [-70h] BYREF
  const idDeclJob::jobReward_t *v24; // [sp+A8h] [-48h]
  __int64 v25; // [sp+B8h] [-38h]
  int v26; // [sp+C0h] [-30h]

  v22.allocedAndFlag = 20;
  v22.data = v22.baseBuffer;
  v22.len = 0;
  v22.baseBuffer[0] = 0;
  allocedAndFlag = result[29].allocedAndFlag;
  v5 = allocedAndFlag;
  if ( idx >= allocedAndFlag )
  {
    v10 = idx - allocedAndFlag;
    v21 = *(_DWORD *)&result[29].baseBuffer[12];
    if ( idx - v5 >= v21 )
    {
      v14 = v10 - v21;
      if ( v14 >= result[30].allocedAndFlag )
      {
        idStr::Append(this: &v22, text: "Error finding debug reward");
        idStr::idStr((idStr *)this, text: &v22);
        goto LABEL_15;
      }
      v15 = &v23.baseBuffer[16];
      v16 = 9;
      v17 = &result[30].data[36 * v14 - 4];
      do
      {
        v17 += 4;
        v15 += 4;
        *(_DWORD *)v15 = *(_DWORD *)v17;
        --v16;
      }
      while ( v16 != 0 );
      v9 = "COMPLETE _ ";
    }
    else
    {
      v11 = &v23.baseBuffer[16];
      v12 = 9;
      v13 = (_DWORD *)(*(_DWORD *)&result[29].baseBuffer[8] + 36 * v10 - 4);
      do
      {
        ++v13;
        v11 += 4;
        *(_DWORD *)v11 = *v13;
        --v12;
      }
      while ( v12 != 0 );
      v9 = "READY _ ";
    }
  }
  else
  {
    v6 = &v23.baseBuffer[16];
    v7 = 9;
    v8 = &result[29].data[36 * idx - 4];
    do
    {
      v8 += 4;
      v6 += 4;
      *(_DWORD *)v6 = *(_DWORD *)v8;
      --v7;
    }
    while ( v7 != 0 );
    v9 = "ACCEPTED _ ";
  }
  idStr::Append(this: &v22, text: v9);
  idDeclJob::BuildRewardDebugString(
    this: (idDeclJob *)&v23,
    result,
    reward: v24,
    debugString: v25,
    a5: __ROL4__(v26, 32),
    a6: (int)&v22,
    a7: v19);
  idStr::FreeData(this: &v23);
  idStr::idStr((idStr *)this, text: &v22);
LABEL_15:
  idStr::FreeData(this: &v22);
  return this;
}


// ========================================================================
// __unwind$489002
// EA  : 0x82BC62B4
// RVA : 0x00BC62B4
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489002()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$489003
// EA  : 0x82BC62DC
// RVA : 0x00BC62DC
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489003()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 240;
  if ( (*(_DWORD *)(v0 - 240 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 260));
  }
}


// ========================================================================
// ?GetJobAcceptRewardDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC6328
// RVA : 0x00BC6328
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobAcceptRewardDebugString(idDeclJob *this, idStr *result, int idx)
{
  char *v4; // r9
  int v5; // ctr
  _DWORD *v6; // r11
  idStr *v8; // [sp+8h] [-B8h]
  idStr v9; // [sp+60h] [-60h] BYREF
  idStr *v10; // [sp+80h] [-40h]
  const idDeclJob::jobReward_t *v11; // [sp+88h] [-38h]
  __int64 v12; // [sp+98h] [-28h]
  int v13; // [sp+A0h] [-20h]

  v4 = &v9.baseBuffer[16];
  v5 = 9;
  v6 = (_DWORD *)(result[4].allocedAndFlag + 36 * idx - 4);
  do
  {
    ++v6;
    v4 += 4;
    *(_DWORD *)v4 = *v6;
    --v5;
  }
  while ( v5 != 0 );
  this->__vftable = nullptr;
  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  HIBYTE(this->nextOnHashChain) = 0;
  idDeclJob::BuildRewardDebugString(
    this: (idDeclJob *)&v9,
    result: v10,
    reward: v11,
    debugString: v12,
    a5: __ROL4__(v13, 32),
    a6: (int)this,
    a7: v8);
  idStr::FreeData(this: &v9);
  return this;
}


// ========================================================================
// __unwind$489099_0
// EA  : 0x82BC63E8
// RVA : 0x00BC63E8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489099_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// ?GetJobReadyRewardDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC6438
// RVA : 0x00BC6438
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobReadyRewardDebugString(idDeclJob *this, idStr *result, int idx)
{
  char *v4; // r9
  int v5; // ctr
  _DWORD *v6; // r11
  idStr *v8; // [sp+8h] [-B8h]
  idStr v9; // [sp+60h] [-60h] BYREF
  idStr *v10; // [sp+80h] [-40h]
  const idDeclJob::jobReward_t *v11; // [sp+88h] [-38h]
  __int64 v12; // [sp+98h] [-28h]
  int v13; // [sp+A0h] [-20h]

  v4 = &v9.baseBuffer[16];
  v5 = 9;
  v6 = (_DWORD *)(*(_DWORD *)&result[4].baseBuffer[12] + 36 * idx - 4);
  do
  {
    ++v6;
    v4 += 4;
    *(_DWORD *)v4 = *v6;
    --v5;
  }
  while ( v5 != 0 );
  this->__vftable = nullptr;
  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  HIBYTE(this->nextOnHashChain) = 0;
  idDeclJob::BuildRewardDebugString(
    this: (idDeclJob *)&v9,
    result: v10,
    reward: v11,
    debugString: v12,
    a5: __ROL4__(v13, 32),
    a6: (int)this,
    a7: v8);
  idStr::FreeData(this: &v9);
  return this;
}


// ========================================================================
// __unwind$489148
// EA  : 0x82BC64F8
// RVA : 0x00BC64F8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489148()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// ?GetJobPreconditionDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC6C18
// RVA : 0x00BC6C18
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetJobPreconditionDebugString(idDeclJob *this, idStr *result, int idx)
{
  idStr *v4; // r3
  char *v5; // r4
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  char *LocalizedString; // r4
  va *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  va *v14; // r3
  int v16; // [sp+8h] [-20B8h]
  int v17; // [sp+Ch] [-20B4h]
  int v18; // [sp+10h] [-20B0h]
  int v19; // [sp+14h] [-20ACh]
  int v20; // [sp+18h] [-20A8h]
  int v21; // [sp+1Ch] [-20A4h]
  idDeclJob::jobPreCondition_t v22; // [sp+60h] [-2060h] BYREF
  va v23; // [sp+A0h] [-2020h] BYREF
  va v24; // [sp+10A0h] [-1020h] BYREF

  idDeclJob::jobPreCondition_t::jobPreCondition_t(
    this: &v22,
    __that: (const idDeclJob::jobPreCondition_t *)(*(_DWORD *)&result[3].baseBuffer[12] + 56 * idx));
  this->__vftable = nullptr;
  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  HIBYTE(this->nextOnHashChain) = 0;
  if ( v22.precondition > (unsigned int)JOBPRECONDITION_GAMESTATEINT )
  {
    v5 = "ERROR!";
    goto LABEL_24;
  }
  switch ( v22.precondition )
  {
    case JOBPRECONDITION_JOB:
      idStr::Append((idStr *)this, text: "JOB : ");
      idStr::Append((idStr *)this, text: &v22.jobDecl);
      switch ( v22.jobStatus )
      {
        case JOBPRECONDITIONSTATUS_ACCEPTED:
          v5 = " _ ACCEPTED";
LABEL_24:
          v4 = (idStr *)this;
          goto LABEL_25;
        case JOBPRECONDITIONSTATUS_READYTOTURNIN:
          v5 = " _ READY";
          goto LABEL_24;
        case JOBPRECONDITIONSTATUS_COMPLETED:
          v5 = " _ COMPLETE";
          goto LABEL_24;
        default:
          break;
      }
      break;
    case JOBPRECONDITION_ITEM:
      idStr::Append((idStr *)this, text: "ITEM : ");
      if ( v22.inventoryDecl != nullptr )
      {
        if ( v22.inventoryDecl->displayName.index >= 0 )
          LocalizedString = (char *)idStrId::GetLocalizedString(this: &v22.inventoryDecl->displayName);
        else
          LocalizedString = (char *)v22.inventoryDecl->name.str;
        idStr::Append((idStr *)this, text: LocalizedString);
      }
      HIDWORD(v8) = v22.count;
      v10 = va::va(
              this: &v23,
              fmt: " %d",
              a3: v8,
              a4: v7,
              a5: v6,
              a6: v16,
              a7: v17,
              a8: v18,
              a9: v19,
              a10: v20,
              a11: v21);
      idStr::Append((idStr *)this, text: v10);
      if ( v22.removeInventory )
      {
        v5 = " _ REMOVE";
        goto LABEL_24;
      }
      break;
    case JOBPRECONDITION_NONE:
      v4 = (idStr *)this;
      v5 = "NONE ? : ";
LABEL_25:
      idStr::Append(this: v4, text: v5);
      break;
    default:
      idStr::Append((idStr *)this, text: "GAMESTATEINT: ");
      if ( v22.gameStateIntDecl != nullptr )
      {
        LODWORD(v11) = &unk_821C0000;
        HIDWORD(v13) = v22.gameStateIntDecl->name.str;
        LODWORD(v13) = v22.count;
        v14 = va::va(
                this: &v24,
                fmt: "%s %d",
                a3: v13,
                a4: v12,
                a5: v11,
                a6: v16,
                a7: v17,
                a8: v18,
                a9: v19,
                a10: v20,
                a11: v21);
        idStr::Append((idStr *)this, text: v14);
      }
      break;
  }
  idStr::FreeData(this: &v22.jobDecl);
  return this;
}


// ========================================================================
// __unwind$489747
// EA  : 0x82BC6DE4
// RVA : 0x00BC6DE4
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489747()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 8384 + 96));
}


// ========================================================================
// __unwind$489748
// EA  : 0x82BC6E0C
// RVA : 0x00BC6E0C
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489748()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 8384;
  if ( (*(_DWORD *)(v0 - 8384 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 8404));
  }
}


// ========================================================================
// ?GetCompletionRequirementDebugString@idDeclJob@@QBA?AVidStr@@H@Z
// EA  : 0x82BC6E58
// RVA : 0x00BC6E58
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::GetCompletionRequirementDebugString(idDeclJob *this, idStr *result, int idx)
{
  idStr *v4; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  char *LocalizedString; // r4
  va *v9; // r3
  char *v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  va *v14; // r3
  int v16; // [sp+8h] [-20B8h]
  int v17; // [sp+Ch] [-20B4h]
  int v18; // [sp+10h] [-20B0h]
  int v19; // [sp+14h] [-20ACh]
  int v20; // [sp+18h] [-20A8h]
  int v21; // [sp+1Ch] [-20A4h]
  idDeclJob::jobComplete_t v22; // [sp+60h] [-2060h] BYREF
  va v23; // [sp+A0h] [-2020h] BYREF
  va v24; // [sp+10A0h] [-1020h] BYREF

  idDeclJob::jobComplete_t::jobComplete_t(
    this: &v22,
    __that: (const idDeclJob::jobComplete_t *)(result[5].allocedAndFlag + 56 * idx));
  this->__vftable = nullptr;
  this->name.str = (const char *)20;
  this->trackedMemory = (int)&this->nextOnHashChain;
  HIBYTE(this->nextOnHashChain) = 0;
  if ( v22.completion > (unsigned int)JOBCOMPLETE_GAMESTATEINT )
  {
    v10 = "ERROR!";
    goto LABEL_22;
  }
  switch ( v22.completion )
  {
    case JOBCOMPLETE_ITEM:
      idStr::Append((idStr *)this, text: "ITEM : ");
      if ( v22.inventoryDecl != nullptr )
      {
        if ( v22.inventoryDecl->displayName.index >= 0 )
          LocalizedString = (char *)idStrId::GetLocalizedString(this: &v22.inventoryDecl->displayName);
        else
          LocalizedString = (char *)v22.inventoryDecl->name.str;
        idStr::Append((idStr *)this, text: LocalizedString);
      }
      HIDWORD(v7) = v22.count;
      v9 = va::va(
             this: &v23,
             fmt: " %d",
             a3: v7,
             a4: v6,
             a5: v5,
             a6: v16,
             a7: v17,
             a8: v18,
             a9: v19,
             a10: v20,
             a11: v21);
      idStr::Append((idStr *)this, text: v9);
      if ( v22.removeInventory )
      {
        v10 = " _ REMOVE";
        goto LABEL_22;
      }
      break;
    case JOBCOMPLETE_TRIGGER:
      idStr::Append((idStr *)this, text: "TRIGGER : ");
      v10 = (char *)idStrId::GetLocalizedString(this: &v22.triggerMessage);
LABEL_22:
      v4 = (idStr *)this;
      goto LABEL_23;
    case JOBCOMPLETE_JOB:
      idStr::Append((idStr *)this, text: "JOB COMPLETE : ");
      idStr::Append((idStr *)this, text: &v22.jobDecl);
      break;
    case JOBCOMPLETE_JOB_ACCEPTED:
      idStr::Append((idStr *)this, text: "JOB ACCEPTED : ");
      idStr::Append((idStr *)this, text: &v22.jobDecl);
      break;
    case JOBCOMPLETE_NONE:
      v4 = (idStr *)this;
      v10 = "NONE ? : ";
LABEL_23:
      idStr::Append(this: v4, text: v10);
      break;
    default:
      idStr::Append((idStr *)this, text: "GAMESTATEINT : ");
      if ( v22.gameStateIntDecl != nullptr )
      {
        LODWORD(v11) = &unk_821C0000;
        HIDWORD(v13) = v22.gameStateIntDecl->name.str;
        LODWORD(v13) = v22.count;
        v14 = va::va(
                this: &v24,
                fmt: "%s %d",
                a3: v13,
                a4: v12,
                a5: v11,
                a6: v16,
                a7: v17,
                a8: v18,
                a9: v19,
                a10: v20,
                a11: v21);
        idStr::Append((idStr *)this, text: v14);
      }
      break;
  }
  idStr::FreeData(this: &v22.jobDecl);
  return this;
}


// ========================================================================
// __unwind$489842
// EA  : 0x82BC7030
// RVA : 0x00BC7030
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489842()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(v0 - 8384 + 96));
}


// ========================================================================
// __unwind$489843
// EA  : 0x82BC7058
// RVA : 0x00BC7058
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_489843()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 8384;
  if ( (*(_DWORD *)(v0 - 8384 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 8404));
  }
}


// ========================================================================
// ??0idDeclJob@@QAA@XZ
// EA  : 0x82BC7940
// RVA : 0x00BC7940
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

idDeclJob *__fastcall idDeclJob::idDeclJob(idDeclJob *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclJob_vtbl *)&idDeclJob::`vftable';
  this->jobNameId.index = -1;
  this->jobSummaryId.index = -1;
  this->jobRequirementsId.index = -1;
  this->jobRewardId.index = -1;
  this->jobStanleyObjId.index = -1;
  this->relevantMaps.granularity = 0;
  this->relevantMaps.memTag = 5;
  this->relevantMaps.listStatic = 0;
  this->relevantMaps.list = nullptr;
  this->relevantMaps.size = 0;
  this->relevantMaps.num = 0;
  this->jobType = JOBTYPE_NONE;
  this->treatAsImportantIfNotRequired = false;
  *(_WORD *)&this->acceptNeedsVerification = 1;
  this->sniperMission = false;
  this->challengeLevel = 0;
  this->normalFlowVars.showsGUI = true;
  this->giveAndCompleteOnApproach = false;
  this->jobTimerEvent = nullptr;
  this->preconditions.granularity = 0;
  this->preconditions.memTag = 5;
  this->preconditions.listStatic = 0;
  this->preconditions.list = nullptr;
  this->preconditions.size = 0;
  this->preconditions.num = 0;
  this->acceptRewards.list = nullptr;
  this->acceptRewards.granularity = 0;
  this->acceptRewards.memTag = 5;
  this->acceptRewards.listStatic = 0;
  this->acceptRewards.size = 0;
  this->acceptRewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->acceptRewards);
  this->readyRewards.list = nullptr;
  this->readyRewards.granularity = 0;
  this->readyRewards.memTag = 5;
  this->readyRewards.listStatic = 0;
  this->readyRewards.size = 0;
  this->readyRewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->readyRewards);
  this->completion.granularity = 0;
  this->completion.memTag = 5;
  this->completion.listStatic = 0;
  this->completion.list = nullptr;
  this->completion.size = 0;
  this->completion.num = 0;
  this->rewards.list = nullptr;
  this->rewards.granularity = 0;
  this->rewards.memTag = 5;
  this->rewards.listStatic = 0;
  this->rewards.size = 0;
  this->rewards.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rewards);
  this->acceptedMiniMapTravelEnt.granularity = 0;
  this->acceptedMiniMapTravelEnt.memTag = 5;
  this->acceptedMiniMapTravelEnt.listStatic = 0;
  this->acceptedMiniMapTravelEnt.list = nullptr;
  this->acceptedMiniMapTravelEnt.size = 0;
  this->acceptedMiniMapTravelEnt.num = 0;
  this->readyToTurnInMiniMapCompletionEnt.granularity = 0;
  this->readyToTurnInMiniMapCompletionEnt.memTag = 5;
  this->readyToTurnInMiniMapCompletionEnt.listStatic = 0;
  this->readyToTurnInMiniMapCompletionEnt.list = nullptr;
  this->readyToTurnInMiniMapCompletionEnt.size = 0;
  this->readyToTurnInMiniMapCompletionEnt.num = 0;
  this->completeNPCName.index = -1;
  idDeclJob::jobLayerInfo_t::jobLayerInfo_t(this: &this->jobLayerInfo);
  idDeclJob::jobNoteInfo_t::jobNoteInfo_t(this: &this->jobNoteInfo);
  idDeclJob::jobAutoTransitionInfo_t::jobAutoTransitionInfo_t(this: &this->jobAutoTransitionInfo);
  this->discSwappingJob = false;
  this->jobGiverFaction = JOBFACTION_NONE;
  idDeclJob::jobDebugMasterInfo_t::jobDebugMasterInfo_t(this: &this->debugInfo);
  this->parentWithoutPrecondition.len = 0;
  this->parentWithoutPrecondition.allocedAndFlag = 20;
  this->parentWithoutPrecondition.data = this->parentWithoutPrecondition.baseBuffer;
  this->parentWithoutPrecondition.baseBuffer[0] = 0;
  this->cameras.list = nullptr;
  this->cameras.granularity = 0;
  this->cameras.memTag = 5;
  this->cameras.listStatic = 0;
  this->cameras.size = 0;
  this->cameras.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cameras);
  this->cameraIndex = -1;
  this->showOnDebugJobGUI = true;
  this->jobImage = nullptr;
  this->doesFakeJob = false;
  this->fakeJobName.index = -1;
  this->fakeJobObj.index = -1;
  this->fakeJobCompleteNPC.index = -1;
  this->fakeJobMiniMapEnt.allocedAndFlag = 20;
  this->fakeJobMiniMapEnt.data = this->fakeJobMiniMapEnt.baseBuffer;
  this->fakeJobMiniMapEnt.len = 0;
  this->fakeJobMiniMapEnt.baseBuffer[0] = 0;
  this->ignoreFakeJob = false;
  this->breakFakeJobCheck = false;
  this->requiredDLC = GAME_DLC_STATE_DEFAULT;
  this->autoCompletes = true;
  this->autoCompleteDistance = 160;
  this->demoStates.list = nullptr;
  this->demoStates.granularity = 0;
  this->demoStates.memTag = 5;
  this->demoStates.listStatic = 0;
  this->demoStates.size = 0;
  this->demoStates.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->demoStates);
  return this;
}


// ========================================================================
// __unwind$490437_1
// EA  : 0x82BC7BE0
// RVA : 0x00BC7BE0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490437_1()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$490438_0
// EA  : 0x82BC7C08
// RVA : 0x00BC7C08
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490438_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 160 + 180) + 84));
}


// ========================================================================
// __unwind$490439_0
// EA  : 0x82BC7C34
// RVA : 0x00BC7C34
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490439_0()
{
  int v0; // r12

  idList<idDeclJob::jobPreCondition_t,5>::~idList<idDeclJob::jobPreCondition_t,5>(this: (idList<idDeclJob::jobPreCondition_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 120));
}


// ========================================================================
// __unwind$490440_0
// EA  : 0x82BC7C60
// RVA : 0x00BC7C60
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490440_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 136));
}


// ========================================================================
// __unwind$490441
// EA  : 0x82BC7C8C
// RVA : 0x00BC7C8C
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490441()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 152));
}


// ========================================================================
// __unwind$490442
// EA  : 0x82BC7CB8
// RVA : 0x00BC7CB8
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490442()
{
  int v0; // r12

  idList<idDeclJob::jobComplete_t,5>::~idList<idDeclJob::jobComplete_t,5>(this: (idList<idDeclJob::jobComplete_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 168));
}


// ========================================================================
// __unwind$490443
// EA  : 0x82BC7CE4
// RVA : 0x00BC7CE4
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490443()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 184));
}


// ========================================================================
// __unwind$490444
// EA  : 0x82BC7D10
// RVA : 0x00BC7D10
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490444()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 160 + 180) + 200));
}


// ========================================================================
// __unwind$490445
// EA  : 0x82BC7D3C
// RVA : 0x00BC7D3C
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490445()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 160 + 180) + 216));
}


// ========================================================================
// __unwind$490446
// EA  : 0x82BC7D68
// RVA : 0x00BC7D68
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490446()
{
  int v0; // r12

  idDeclJob::jobLayerInfo_t::~jobLayerInfo_t(this: (idDeclJob::jobLayerInfo_t *)(*(_DWORD *)(v0 - 160 + 180) + 236));
}


// ========================================================================
// __unwind$490447
// EA  : 0x82BC7D94
// RVA : 0x00BC7D94
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490447()
{
  int v0; // r12

  idDeclJob::jobNoteInfo_t::~jobNoteInfo_t(this: (idDeclJob::jobNoteInfo_t *)(*(_DWORD *)(v0 - 160 + 180) + 380));
}


// ========================================================================
// __unwind$490448
// EA  : 0x82BC7DC0
// RVA : 0x00BC7DC0
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490448()
{
  int v0; // r12

  idDeclJob::jobAutoTransitionInfo_t::~jobAutoTransitionInfo_t(this: (idDeclJob::jobAutoTransitionInfo_t *)(*(_DWORD *)(v0 - 160 + 180) + 508));
}


// ========================================================================
// __unwind$490449
// EA  : 0x82BC7DEC
// RVA : 0x00BC7DEC
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490449()
{
  int v0; // r12

  idDeclCloth::ropeInfo::~ropeInfo(this: (idDeclCloth::ropeInfo *)(*(_DWORD *)(v0 - 160 + 180) + 932));
}


// ========================================================================
// __unwind$490450
// EA  : 0x82BC7E18
// RVA : 0x00BC7E18
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490450()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 980));
}


// ========================================================================
// __unwind$490451
// EA  : 0x82BC7E44
// RVA : 0x00BC7E44
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490451()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1012));
}


// ========================================================================
// __unwind$490452
// EA  : 0x82BC7E70
// RVA : 0x00BC7E70
// PDB : w:\tech5\tungsten\game\decls\decljob.cpp
// ========================================================================

void _unwind_490452()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 1056));
}

