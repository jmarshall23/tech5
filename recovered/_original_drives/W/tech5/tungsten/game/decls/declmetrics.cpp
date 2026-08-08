
// ========================================================================
// ?GetXPValue@idDeclMetric@@QBAHH@Z
// EA  : 0x82BC8900
// RVA : 0x00BC8900
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

int __fastcall idDeclMetric::GetXPValue(idDeclMetric *this, int delta)
{
  return this->xp * delta;
}


// ========================================================================
// ?GetXPBonus@idDeclMetric@@QBAHH@Z
// EA  : 0x82BC8968
// RVA : 0x00BC8968
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

int __fastcall idDeclMetric::GetXPBonus(idDeclMetric *this, int delta)
{
  int num; // r8
  int v3; // r10
  rageStatXpBonus *list; // r9
  int i; // r11

  num = this->xpBonus.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->xpBonus.list;
  for ( i = 0; delta < list[i].min; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  return list[v3].xp;
}


// ========================================================================
// ?Find@idDeclMetric@@SAPBV1@W4rageStat_t@@@Z
// EA  : 0x82BC8C38
// RVA : 0x00BC8C38
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

const idDeclMetric *__fastcall idDeclMetric::Find(rageStat_t stat)
{
  int v2; // r31
  int num; // r28
  const idDeclMetric *result; // r3

  v2 = 0;
  num = idDeclMetric::resourceList.num;
  if ( idDeclMetric::resourceList.num <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (const idDeclMetric *)idResourceList::Index(this: &idDeclMetric::resourceList, index: v2);
    if ( result->stat == stat )
      break;
    if ( ++v2 >= num )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?IsWeaponListed@idDeclMetric@@QBA_NABVidDeclWeapon@@@Z
// EA  : 0x82BC8C98
// RVA : 0x00BC8C98
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

BOOL __fastcall idDeclMetric::IsWeaponListed(idDeclMetric *this, const idDeclWeapon *decl)
{
  idList<idStr,5> *p_weaponDecls; // r30
  int Index; // r3
  int v4; // r11
  BOOL v5; // r30
  idStr v7; // [sp+50h] [-40h] BYREF

  p_weaponDecls = &this->weaponDecls;
  idStr::idStr(this: &v7, text: decl->name.str);
  Index = idList<idStr,5>::FindIndex(this: p_weaponDecls, obj: &v7, startIndex: 0);
  if ( Index < 0 )
    v4 = 0;
  else
    v4 = (int)&p_weaponDecls->list[Index];
  v5 = v4 != 0;
  idStr::FreeData(this: &v7);
  return v5;
}


// ========================================================================
// __unwind$487922
// EA  : 0x82BC8D1C
// RVA : 0x00BC8D1C
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

void _unwind_487922()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idDeclMetric@@QAA@XZ
// EA  : 0x82BC8D60
// RVA : 0x00BC8D60
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

idDeclMetric *__fastcall idDeclMetric::idDeclMetric(idDeclMetric *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->stat = RAGE_STAT_INVALID;
  this->__vftable = (idDeclMetric_vtbl *)&idDeclMetric::`vftable';
  this->aggregate.stat = RAGE_STAT_INVALID;
  this->aggregate.method = AGGREGATE_SUM;
  this->weaponDecls.granularity = 0;
  this->weaponDecls.listStatic = 0;
  this->weaponDecls.memTag = 5;
  this->weaponDecls.list = nullptr;
  this->weaponDecls.size = 0;
  this->weaponDecls.num = 0;
  this->isWeaponStat = false;
  this->xp = 0;
  this->xpBonus.list = nullptr;
  this->xpBonus.granularity = 0;
  this->xpBonus.memTag = 5;
  this->xpBonus.listStatic = 0;
  this->xpBonus.size = 0;
  this->xpBonus.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->xpBonus);
  this->displayName.index = -1;
  return this;
}


// ========================================================================
// __unwind$488141_0
// EA  : 0x82BC8E0C
// RVA : 0x00BC8E0C
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

void _unwind_488141_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488142_1
// EA  : 0x82BC8E34
// RVA : 0x00BC8E34
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

void _unwind_488142_1()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// ?LoadAllDecls@idDeclMetric@@SAXXZ
// EA  : 0x82BC8F40
// RVA : 0x00BC8F40
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

static void __fastcall idDeclMetric::LoadAllDecls()
{
  int num; // r28
  idDeclSource **list; // r11
  int v2; // r30
  const char **p_str; // r10
  int i; // r30
  idResource *v5; // r11
  __int64 v6; // r10
  unsigned __int64 v7; // r8
  int v8; // r6
  rageStatXpBonus *staleCount; // r4
  unsigned int v10; // r5
  idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus> v11; // [sp+50h] [-40h] BYREF
  idDeclSource **v12; // [sp+54h] [-3Ch]

  if ( idDeclMetric::resourceList.declSources.num > 0 )
  {
    num = idDeclMetric::resourceList.declSources.num;
    list = idDeclMetric::resourceList.declSources.list;
    v2 = 0;
    do
    {
      p_str = &list[v2]->name.str;
      v12 = &list[v2];
      if ( *p_str != nullptr )
      {
        idDeclInfo::FindWithInheritance(this: &idDeclMetric::resourceList, name: *p_str, makeDefault: false);
        list = idDeclMetric::resourceList.declSources.list;
      }
      --num;
      ++v2;
    }
    while ( num != 0 );
  }
  for ( i = 0;
        i < idDeclMetric::resourceList.num;
        v11.__vftable = (idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus>_vtbl *)&idSort<rageStatXpBonus>::`vftable' )
  {
    v5 = idResourceList::Index(this: &idDeclMetric::resourceList, index: i);
    v11.__vftable = (idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus>_vtbl *)&idSort_RageStatXpBonus::`vftable';
    staleCount = (rageStatXpBonus *)v5[2].staleCount;
    if ( staleCount != nullptr )
    {
      LODWORD(v6) = idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus>::Sort;
      v10 = *((_DWORD *)&v5[2] + 8);
      v12 = (idDeclSource **)v5[2].staleCount;
      idSort_Quick<rageStatXpBonus,idSort_RageStatXpBonus>::Sort(
        this: &v11,
        base: staleCount,
        num: v10,
        a4: v8,
        a5: v7,
        a6: v6);
    }
    ++i;
  }
}


// ========================================================================
// __unwind$488305_0
// EA  : 0x82BC9018
// RVA : 0x00BC9018
// PDB : w:\tech5\tungsten\game\decls\declmetrics.cpp
// ========================================================================

void _unwind_488305_0()
{
  int v0; // r12

  idSort_RageStatXpBonus::~idSort_RageStatXpBonus(this: (idSort_RageStatXpBonus *)(v0 - 144 + 80));
}

