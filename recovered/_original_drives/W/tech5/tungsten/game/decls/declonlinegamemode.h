
// ========================================================================
// ?GetDeclInfo@idDeclGameMode@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC9AD8
// RVA : 0x00BC9AD8
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

idDeclInfoTemplate<idDeclGameMode> *__fastcall idDeclGameMode::GetDeclInfo(idDeclGameMode *this)
{
  return &idDeclGameMode::resourceList;
}


// ========================================================================
// ??1idDeclGameMode@@UAA@XZ
// EA  : 0x82BC9AF0
// RVA : 0x00BC9AF0
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void __fastcall idDeclGameMode::~idDeclGameMode(idDeclGameMode *this)
{
  this->__vftable = (idDeclGameMode_vtbl *)&idDeclGameMode::`vftable';
  idStr::FreeData(this: &this->titleStorageModeName);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->migrationStats);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$488178
// EA  : 0x82BC9B4C
// RVA : 0x00BC9B4C
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488178()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488179
// EA  : 0x82BC9B74
// RVA : 0x00BC9B74
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488179()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ?GetDeclInfo@idDeclPvPMap@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BC9D58
// RVA : 0x00BC9D58
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

idDeclInfoTemplate<idDeclPvPMap> *__fastcall idDeclPvPMap::GetDeclInfo(idDeclPvPMap *this)
{
  return &idDeclPvPMap::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclCoopMap@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCA058
// RVA : 0x00BCA058
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

idDeclInfoTemplate<idDeclCoopMap> *__fastcall idDeclCoopMap::GetDeclInfo(idDeclCoopMap *this)
{
  return &idDeclCoopMap::resourceList;
}


// ========================================================================
// ??1idDeclPvPMap@@UAA@XZ
// EA  : 0x82BCA070
// RVA : 0x00BCA070
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void __fastcall idDeclPvPMap::~idDeclPvPMap(idDeclPvPMap *this)
{
  char *list; // r3

  this->__vftable = (idDeclPvPMap_vtbl *)&idDeclPvPMap::`vftable';
  if ( this->modes.listStatic == 0 || this->modes.listStatic == 2 )
  {
    list = (char *)this->modes.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnRenderParm>(ptr: list, num: this->modes.size);
    this->modes.list = nullptr;
    this->modes.size = 0;
  }
  this->modes.num = 0;
  idStr::FreeData(this: &this->titleStorageMapName);
  idStr::FreeData(this: &this->mapFile);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$488633
// EA  : 0x82BCA0EC
// RVA : 0x00BCA0EC
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488633()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488634
// EA  : 0x82BCA114
// RVA : 0x00BCA114
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488634()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$488635
// EA  : 0x82BCA140
// RVA : 0x00BCA140
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488635()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// ??1idDeclCoopMap@@UAA@XZ
// EA  : 0x82BCA1D8
// RVA : 0x00BCA1D8
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void __fastcall idDeclCoopMap::~idDeclCoopMap(idDeclCoopMap *this)
{
  char *list; // r3

  this->__vftable = (idDeclCoopMap_vtbl *)&idDeclCoopMap::`vftable';
  if ( this->challenges.listStatic == 0 || this->challenges.listStatic == 2 )
  {
    list = (char *)this->challenges.list;
    if ( list != nullptr )
      idListArrayDelete<idOnlineChallenge>(ptr: list, num: this->challenges.size);
    this->challenges.list = nullptr;
    this->challenges.size = 0;
  }
  this->challenges.num = 0;
  idStr::FreeData(this: &this->map);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$488695
// EA  : 0x82BCA24C
// RVA : 0x00BCA24C
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488695()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488696
// EA  : 0x82BCA274
// RVA : 0x00BCA274
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

void _unwind_488696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}


// ========================================================================
// ?GetMapLayers@idOnlineChallenge@@QBA?AVidStr@@XZ
// EA  : 0x82DBF048
// RVA : 0x00DBF048
// PDB : w:\tech5\tungsten\game\decls\declonlinegamemode.h
// ========================================================================

idOnlineChallenge *__fastcall idOnlineChallenge::GetMapLayers(idOnlineChallenge *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (const idStr *)&result->allocedAndFlag);
  return this;
}

