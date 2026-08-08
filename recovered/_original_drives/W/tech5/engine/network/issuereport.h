
// ========================================================================
// ??1idIssueReport@@UAA@XZ
// EA  : 0x82893FD0
// RVA : 0x00893FD0
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void __fastcall idIssueReport::~idIssueReport(idIssueReport *this)
{
  this->__vftable = (idIssueReport_vtbl *)&idIssueReport::`vftable';
  idStr::FreeData(this: &this->attachFileName);
}


// ========================================================================
// ??0idReportData@@QAA@XZ
// EA  : 0x82899528
// RVA : 0x00899528
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

idReportData *__fastcall idReportData::idReportData(idReportData *this)
{
  this->userName.len = 0;
  this->userName.allocedAndFlag = 20;
  this->userName.data = this->userName.baseBuffer;
  this->userName.baseBuffer[0] = 0;
  this->platform.allocedAndFlag = 20;
  this->platform.len = 0;
  this->platform.data = this->platform.baseBuffer;
  this->platform.baseBuffer[0] = 0;
  this->buildMessage.allocedAndFlag = 20;
  this->buildMessage.len = 0;
  this->buildMessage.data = this->buildMessage.baseBuffer;
  this->buildMessage.baseBuffer[0] = 0;
  this->cpuID.allocedAndFlag = 20;
  this->cpuID.len = 0;
  this->cpuID.data = this->cpuID.baseBuffer;
  this->cpuID.baseBuffer[0] = 0;
  this->launchCommand.allocedAndFlag = 20;
  this->launchCommand.len = 0;
  this->launchCommand.data = this->launchCommand.baseBuffer;
  this->launchCommand.baseBuffer[0] = 0;
  this->vtFilePathCvar.allocedAndFlag = 20;
  this->vtFilePathCvar.len = 0;
  this->vtFilePathCvar.data = this->vtFilePathCvar.baseBuffer;
  this->vtFilePathCvar.baseBuffer[0] = 0;
  this->vtFilePathVmtrOverrideCvar.allocedAndFlag = 20;
  this->vtFilePathVmtrOverrideCvar.len = 0;
  this->vtFilePathVmtrOverrideCvar.data = this->vtFilePathVmtrOverrideCvar.baseBuffer;
  this->vtFilePathVmtrOverrideCvar.baseBuffer[0] = 0;
  this->title.allocedAndFlag = 20;
  this->title.len = 0;
  this->title.data = this->title.baseBuffer;
  this->title.baseBuffer[0] = 0;
  this->steps.allocedAndFlag = 20;
  this->steps.len = 0;
  this->steps.data = this->steps.baseBuffer;
  this->steps.baseBuffer[0] = 0;
  this->details.allocedAndFlag = 20;
  this->details.len = 0;
  this->details.data = this->details.baseBuffer;
  this->details.baseBuffer[0] = 0;
  this->severity.allocedAndFlag = 20;
  this->severity.len = 0;
  this->severity.data = this->severity.baseBuffer;
  this->severity.baseBuffer[0] = 0;
  this->component.allocedAndFlag = 20;
  this->component.len = 0;
  this->component.data = this->component.baseBuffer;
  this->component.baseBuffer[0] = 0;
  this->reproduced.allocedAndFlag = 20;
  this->reproduced.len = 0;
  this->reproduced.data = this->reproduced.baseBuffer;
  this->reproduced.baseBuffer[0] = 0;
  this->style.allocedAndFlag = 20;
  this->style.len = 0;
  this->style.data = this->style.baseBuffer;
  this->style.baseBuffer[0] = 0;
  this->mapPath.allocedAndFlag = 20;
  this->mapPath.len = 0;
  this->mapPath.data = this->mapPath.baseBuffer;
  this->mapPath.baseBuffer[0] = 0;
  this->priority.allocedAndFlag = 20;
  this->priority.len = 0;
  this->priority.data = this->priority.baseBuffer;
  this->priority.baseBuffer[0] = 0;
  this->systemInfo.allocedAndFlag = 20;
  this->systemInfo.len = 0;
  this->systemInfo.data = this->systemInfo.baseBuffer;
  this->systemInfo.baseBuffer[0] = 0;
  this->localFilename.allocedAndFlag = 20;
  this->localFilename.len = 0;
  this->localFilename.data = this->localFilename.baseBuffer;
  this->localFilename.baseBuffer[0] = 0;
  this->dmpPath.allocedAndFlag = 20;
  this->dmpPath.len = 0;
  this->dmpPath.data = this->dmpPath.baseBuffer;
  this->dmpPath.baseBuffer[0] = 0;
  this->originalCallstack.granularity = 0;
  this->originalCallstack.memTag = 5;
  this->originalCallstack.listStatic = 0;
  this->originalCallstack.list = nullptr;
  this->originalCallstack.size = 0;
  this->originalCallstack.num = 0;
  this->callstack.data = this->callstack.baseBuffer;
  this->callstack.allocedAndFlag = 20;
  this->callstack.len = 0;
  this->callstack.baseBuffer[0] = 0;
  this->exception.data = this->exception.baseBuffer;
  this->exception.allocedAndFlag = 20;
  this->exception.len = 0;
  this->exception.baseBuffer[0] = 0;
  this->registers.data = this->registers.baseBuffer;
  this->registers.allocedAndFlag = 20;
  this->registers.len = 0;
  this->registers.baseBuffer[0] = 0;
  this->attachFilename.data = this->attachFilename.baseBuffer;
  this->attachFilename.allocedAndFlag = 20;
  this->attachFilename.len = 0;
  this->attachFilename.baseBuffer[0] = 0;
  this->fullFunctionDetails.data = this->fullFunctionDetails.baseBuffer;
  this->fullFunctionDetails.allocedAndFlag = 20;
  this->fullFunctionDetails.len = 0;
  this->fullFunctionDetails.baseBuffer[0] = 0;
  this->someFunctionDetails.allocedAndFlag = 20;
  this->someFunctionDetails.data = this->someFunctionDetails.baseBuffer;
  this->someFunctionDetails.len = 0;
  this->someFunctionDetails.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$220278
// EA  : 0x828997C0
// RVA : 0x008997C0
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220278()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$220279
// EA  : 0x828997E8
// RVA : 0x008997E8
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220279()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 32));
}


// ========================================================================
// __unwind$220280
// EA  : 0x82899814
// RVA : 0x00899814
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220280()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 64));
}


// ========================================================================
// __unwind$220281
// EA  : 0x82899840
// RVA : 0x00899840
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220281()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 104));
}


// ========================================================================
// __unwind$220282
// EA  : 0x8289986C
// RVA : 0x0089986C
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220282()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 152));
}


// ========================================================================
// __unwind$220283
// EA  : 0x82899898
// RVA : 0x00899898
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220283()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 184));
}


// ========================================================================
// __unwind$220284
// EA  : 0x828998C4
// RVA : 0x008998C4
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220284()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 216));
}


// ========================================================================
// __unwind$220285
// EA  : 0x828998F0
// RVA : 0x008998F0
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220285()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 248));
}


// ========================================================================
// __unwind$220286
// EA  : 0x8289991C
// RVA : 0x0089991C
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220286()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 280));
}


// ========================================================================
// __unwind$220287
// EA  : 0x82899948
// RVA : 0x00899948
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220287()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 312));
}


// ========================================================================
// __unwind$220288
// EA  : 0x82899974
// RVA : 0x00899974
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220288()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 344));
}


// ========================================================================
// __unwind$220289
// EA  : 0x828999A0
// RVA : 0x008999A0
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220289()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 376));
}


// ========================================================================
// __unwind$220290
// EA  : 0x828999CC
// RVA : 0x008999CC
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220290()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 408));
}


// ========================================================================
// __unwind$220291
// EA  : 0x828999F8
// RVA : 0x008999F8
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220291()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 440));
}


// ========================================================================
// __unwind$220292
// EA  : 0x82899A24
// RVA : 0x00899A24
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220292()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 472));
}


// ========================================================================
// __unwind$220293
// EA  : 0x82899A50
// RVA : 0x00899A50
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220293()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 504));
}


// ========================================================================
// __unwind$220294
// EA  : 0x82899A7C
// RVA : 0x00899A7C
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220294()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 536));
}


// ========================================================================
// __unwind$220295
// EA  : 0x82899AA8
// RVA : 0x00899AA8
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220295()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 568));
}


// ========================================================================
// __unwind$220296
// EA  : 0x82899AD4
// RVA : 0x00899AD4
// PDB : w:\tech5\engine\network\issuereport.h
// ========================================================================

void _unwind_220296()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 600));
}

