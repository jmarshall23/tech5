
// ========================================================================
// ??0idDeclMapInfo@@QAA@XZ
// EA  : 0x82629070
// RVA : 0x00629070
// PDB : w:\tech5\engine\decls\declmapinfo.cpp
// ========================================================================

idDeclMapInfo *__fastcall idDeclMapInfo::idDeclMapInfo(idDeclMapInfo *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclMapInfo_vtbl *)&idDeclMapInfo::`vftable';
  this->prettyMapName.index = -1;
  this->discNumber = -1;
  this->dlcId = 0;
  this->loadingVideos.list = nullptr;
  this->loadingVideos.granularity = 0;
  this->loadingVideos.memTag = 5;
  this->loadingVideos.listStatic = 0;
  this->loadingVideos.size = 0;
  this->loadingVideos.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loadingVideos);
  return this;
}


// ========================================================================
// __unwind$219173
// EA  : 0x826290FC
// RVA : 0x006290FC
// PDB : w:\tech5\engine\decls\declmapinfo.cpp
// ========================================================================

void _unwind_219173()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

