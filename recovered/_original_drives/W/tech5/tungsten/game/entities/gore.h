
// ========================================================================
// ?GetDeclInfo@idDeclGore@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD6D18
// RVA : 0x00BD6D18
// PDB : w:\tech5\tungsten\game\entities\gore.h
// ========================================================================

idDeclInfoTemplate<idDeclGore> *__fastcall idDeclGore::GetDeclInfo(idDeclGore *this)
{
  return &idDeclGore::resourceList;
}


// ========================================================================
// ?EntityToSpawnIsABreakable@idGorePieceInfo_t@@QBA_NXZ
// EA  : 0x82C5B678
// RVA : 0x00C5B678
// PDB : w:\tech5\tungsten\game\entities\gore.h
// ========================================================================

int __fastcall idGorePieceInfo_t::EntityToSpawnIsABreakable(idGorePieceInfo_t *this)
{
  idDeclEntityDef *entityToSpawn; // r11
  const char *classname; // r31
  const char *v3; // r3
  int v4; // r3
  unsigned __int8 v5; // r11

  entityToSpawn = this->entityToSpawn;
  if ( entityToSpawn == nullptr )
    return 0;
  classname = idBreakable::Type.classname;
  v3 = (const char *)((int (*)(void))entityToSpawn->GetClass)();
  v4 = idStr::Cmp(s1: v3, s2: classname);
  v5 = 1;
  if ( v4 != 0 )
    return 0;
  return v5;
}


// ========================================================================
// ?EntityToSpawnIsABreakable@clothInfo_t@idGorePieceInfo_t@@QBA_NXZ
// EA  : 0x82C5B6E0
// RVA : 0x00C5B6E0
// PDB : w:\tech5\tungsten\game\entities\gore.h
// ========================================================================

int __fastcall idGorePieceInfo_t::clothInfo_t::EntityToSpawnIsABreakable(idGorePieceInfo_t::clothInfo_t *this)
{
  idDeclEntityDef *gibEntity; // r11
  const char *classname; // r31
  const char *v3; // r3
  int v4; // r3
  unsigned __int8 v5; // r11

  gibEntity = this->gibEntity;
  if ( gibEntity == nullptr )
    return 0;
  classname = idBreakable::Type.classname;
  v3 = (const char *)((int (*)(void))gibEntity->GetClass)();
  v4 = idStr::Cmp(s1: v3, s2: classname);
  v5 = 1;
  if ( v4 != 0 )
    return 0;
  return v5;
}

