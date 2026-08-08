
// ========================================================================
// ?GetNumLoadouts@idDeclOnlineLevel@@QBAHH@Z
// EA  : 0x82BCA300
// RVA : 0x00BCA300
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

int __fastcall idDeclOnlineLevel::GetNumLoadouts(idDeclOnlineLevel *this, int level)
{
  int v2; // r11
  onlineLevel_t *list; // r9
  int v4; // r10
  onlineLevel_t *v5; // r8

  v2 = level - 1;
  if ( level - 1 >= 0 )
  {
    if ( v2 > this->levelList.num - 1 )
      v2 = this->levelList.num - 1;
    if ( v2 > 0 )
    {
      list = this->levelList.list;
      v4 = v2;
      v5 = &list[v2];
      do
      {
        if ( v5->loadouts != 0 )
          break;
        --v4;
        --v2;
        v5 = &list[v4];
      }
      while ( v2 > 0 );
    }
  }
  else
  {
    v2 = 0;
  }
  return this->levelList.list[v2].loadouts;
}


// ========================================================================
// ?GetXpRequiredForLevel@idDeclOnlineLevel@@QBAHH@Z
// EA  : 0x82BCA378
// RVA : 0x00BCA378
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

int __fastcall idDeclOnlineLevel::GetXpRequiredForLevel(
        idDeclOnlineLevel *this,
        int level,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  double globalXpScale; // fp0
  onlineLevel_t *list; // r10
  unsigned int v10; // r9
  __int64 v11; // r4
  onlineLevel_t *v12; // r5

  globalXpScale = this->globalXpScale;
  if ( level <= this->levelList.num )
  {
    list = this->levelList.list;
    v10 = ((level == 1) + ((unsigned int)(level - 1) >> 31) - 1) & (level - 1);
    HIDWORD(v11) = 3 * v10;
    v12 = &list[v10];
    LODWORD(v11) = v12->baseXp;
    return (int)(float)((float)((float)v11 * v12->localXpScale) * (float)globalXpScale);
  }
  else
  {
    LODWORD(a7) = this->xpCap;
    return (int)(float)((float)a7 * this->globalXpScale);
  }
}


// ========================================================================
// ?GetLevelForXp@idDeclOnlineLevel@@QBAHH@Z
// EA  : 0x82BCA430
// RVA : 0x00BCA430
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idDeclOnlineLevel::GetLevelForXp(idDeclOnlineLevel *this, int xp, int a3, int a4, int a5, __int64 a6)
{
  int num; // r5
  int result; // r3
  unsigned int i; // r11
  int v10; // r10
  onlineLevel_t *list; // r10
  float *v12; // r6
  int v13; // r10

  num = this->levelList.num;
  result = 0;
  if ( num <= 0 )
    return num;
  for ( i = 0; ; ++i )
  {
    if ( (int)(i + 1) <= num )
    {
      list = this->levelList.list;
      LODWORD(a6) = 12 * (((i == 0) + (i >> 31) - 1) & i);
      HIDWORD(a6) = *(int *)((char *)&list->baseXp + a6);
      v12 = (float *)((char *)&list->baseXp + a6);
      v13 = HIDWORD(a6);
      v10 = (int)(float)((float)((float)*(__int64 *)((char *)&a6 - 4) * v12[1]) * this->globalXpScale);
    }
    else
    {
      LODWORD(a6) = this->xpCap;
      v10 = (int)(float)((float)a6 * this->globalXpScale);
    }
    if ( xp < v10 )
      break;
    if ( ++result >= num )
      return num;
  }
  return result;
}


// ========================================================================
// ??0idDeclOnlineLevel@@QAA@XZ
// EA  : 0x82BCA520
// RVA : 0x00BCA520
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

idDeclOnlineLevel *__fastcall idDeclOnlineLevel::idDeclOnlineLevel(idDeclOnlineLevel *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclOnlineLevel_vtbl *)&idDeclOnlineLevel::`vftable';
  this->levelList.list = nullptr;
  this->levelList.granularity = 0;
  this->levelList.memTag = 5;
  this->levelList.listStatic = 0;
  this->levelList.size = 0;
  this->levelList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->levelList);
  this->xpCap = 0x7FFFFFFF;
  this->globalXpScale = 1.0;
  return this;
}


// ========================================================================
// __unwind$487541
// EA  : 0x82BCA5AC
// RVA : 0x00BCA5AC
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

void _unwind_487541()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?LoadAllDecls@idDeclOnlineLevel@@SAXXZ
// EA  : 0x82BCA5E8
// RVA : 0x00BCA5E8
// PDB : w:\tech5\tungsten\game\decls\declonlinelevel.cpp
// ========================================================================

static void __fastcall idDeclOnlineLevel::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclOnlineLevel::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclOnlineLevel::resourceList.declSources.num;
    do
    {
      str = idDeclOnlineLevel::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclOnlineLevel::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}

