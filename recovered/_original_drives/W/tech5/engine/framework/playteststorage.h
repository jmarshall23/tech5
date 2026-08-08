
// ========================================================================
// ??0playerNormalBreadCrumbList_t@idPlaytestStorage@@QAA@XZ
// EA  : 0x825921C8
// RVA : 0x005921C8
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

idPlaytestStorage::playerNormalBreadCrumbList_t *__fastcall idPlaytestStorage::playerNormalBreadCrumbList_t::playerNormalBreadCrumbList_t(
        idPlaytestStorage::playerNormalBreadCrumbList_t *this)
{
  this->interactionEntity.len = 0;
  this->interactionEntity.allocedAndFlag = 20;
  this->interactionEntity.data = this->interactionEntity.baseBuffer;
  this->interactionEntity.baseBuffer[0] = 0;
  this->interactionName.allocedAndFlag = 20;
  this->interactionName.len = 0;
  this->interactionName.data = this->interactionName.baseBuffer;
  this->interactionName.baseBuffer[0] = 0;
  this->breadCrumbs.list = nullptr;
  this->breadCrumbs.granularity = 0;
  this->breadCrumbs.memTag = 5;
  this->breadCrumbs.listStatic = 0;
  this->breadCrumbs.size = 0;
  this->breadCrumbs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->breadCrumbs);
  this->inInteraction = false;
  return this;
}


// ========================================================================
// __unwind$688385
// EA  : 0x8259224C
// RVA : 0x0059224C
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_688385()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$688386
// EA  : 0x82592278
// RVA : 0x00592278
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_688386()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ??0aiVehicleInfo_t@idPlaytestStorage@@QAA@XZ
// EA  : 0x825922B0
// RVA : 0x005922B0
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

idPlaytestStorage::aiVehicleInfo_t *__fastcall idPlaytestStorage::aiVehicleInfo_t::aiVehicleInfo_t(
        idPlaytestStorage::aiVehicleInfo_t *this)
{
  this->entName.len = 0;
  this->entName.allocedAndFlag = 20;
  this->entName.data = this->entName.baseBuffer;
  this->entName.baseBuffer[0] = 0;
  this->breadCrumbs.list = nullptr;
  this->breadCrumbs.granularity = 0;
  this->breadCrumbs.memTag = 5;
  this->breadCrumbs.listStatic = 0;
  this->breadCrumbs.size = 0;
  this->breadCrumbs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->breadCrumbs);
  this->entNum = -1;
  this->creationTimeStamp = -1;
  return this;
}


// ========================================================================
// __unwind$688458
// EA  : 0x8259233C
// RVA : 0x0059233C
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_688458()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0playerMainBreadCrumbInfo_t@idPlaytestStorage@@QAA@XZ
// EA  : 0x825AC400
// RVA : 0x005AC400
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

idPlaytestStorage::playerMainBreadCrumbInfo_t *__fastcall idPlaytestStorage::playerMainBreadCrumbInfo_t::playerMainBreadCrumbInfo_t(
        idPlaytestStorage::playerMainBreadCrumbInfo_t *this)
{
  this->normalBreadCrumbs.granularity = 0;
  this->normalBreadCrumbs.listStatic = 0;
  this->normalBreadCrumbs.memTag = 5;
  this->normalBreadCrumbs.list = nullptr;
  this->normalBreadCrumbs.size = 0;
  this->normalBreadCrumbs.num = 0;
  this->miscBreadCrumbs.granularity = 0;
  this->miscBreadCrumbs.memTag = 5;
  this->miscBreadCrumbs.listStatic = 0;
  this->miscBreadCrumbs.list = nullptr;
  this->miscBreadCrumbs.size = 0;
  this->miscBreadCrumbs.num = 0;
  this->vehicleBreadCrumbs.granularity = 0;
  this->vehicleBreadCrumbs.memTag = 5;
  this->vehicleBreadCrumbs.listStatic = 0;
  this->vehicleBreadCrumbs.list = nullptr;
  this->vehicleBreadCrumbs.size = 0;
  this->vehicleBreadCrumbs.num = 0;
  this->state = PLAYERBREADCRUMBSTATE_NONE;
  return this;
}


// ========================================================================
// __unwind$726733
// EA  : 0x825AC484
// RVA : 0x005AC484
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_726733()
{
  int v0; // r12

  idList<idPlaytestStorage::playerNormalBreadCrumbList_t,5>::~idList<idPlaytestStorage::playerNormalBreadCrumbList_t,5>(this: (idList<idPlaytestStorage::playerNormalBreadCrumbList_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// __unwind$726734
// EA  : 0x825AC4B0
// RVA : 0x005AC4B0
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_726734()
{
  int v0; // r12

  idList<idPlaytestStorage::playerMiscControlBreadCrumbList_t,5>::Clear(this: (idList<idPlaytestStorage::playerMiscControlBreadCrumbList_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 20));
}


// ========================================================================
// ??0ai2Info_t@idPlaytestStorage@@QAA@XZ
// EA  : 0x825AC4E8
// RVA : 0x005AC4E8
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

idPlaytestStorage::ai2Info_t *__fastcall idPlaytestStorage::ai2Info_t::ai2Info_t(idPlaytestStorage::ai2Info_t *this)
{
  this->entName.len = 0;
  this->entName.allocedAndFlag = 20;
  this->entName.data = this->entName.baseBuffer;
  this->entName.baseBuffer[0] = 0;
  this->stateLog.granularity = 0;
  this->stateLog.listStatic = 0;
  this->stateLog.memTag = 5;
  this->stateLog.list = nullptr;
  this->stateLog.size = 0;
  this->stateLog.num = 0;
  this->breadCrumbs.granularity = 0;
  this->breadCrumbs.memTag = 5;
  this->breadCrumbs.listStatic = 0;
  this->breadCrumbs.list = nullptr;
  this->breadCrumbs.size = 0;
  this->breadCrumbs.num = 0;
  this->dormantTimeStamps.list = nullptr;
  this->dormantTimeStamps.granularity = 0;
  this->dormantTimeStamps.memTag = 5;
  this->dormantTimeStamps.listStatic = 0;
  this->dormantTimeStamps.size = 0;
  this->dormantTimeStamps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dormantTimeStamps);
  this->entNum = -1;
  this->creationTimeStamp = -1;
  this->isDormant = true;
  return this;
}


// ========================================================================
// __unwind$726798
// EA  : 0x825AC5BC
// RVA : 0x005AC5BC
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_726798()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$726799
// EA  : 0x825AC5E8
// RVA : 0x005AC5E8
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_726799()
{
  int v0; // r12

  idList<idPlaytestStorage::ai2StateInfo_t,5>::~idList<idPlaytestStorage::ai2StateInfo_t,5>(this: (idList<idPlaytestStorage::ai2StateInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$726800
// EA  : 0x825AC614
// RVA : 0x005AC614
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

void _unwind_726800()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 60));
}


// ========================================================================
// ?GetPlayMapName@idPlaytestStorage@@QBA?AVidStr@@XZ
// EA  : 0x8267D1E8
// RVA : 0x0067D1E8
// PDB : w:\tech5\engine\framework\playteststorage.h
// ========================================================================

idPlaytestStorage *__fastcall idPlaytestStorage::GetPlayMapName(idPlaytestStorage *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 336));
  return this;
}

