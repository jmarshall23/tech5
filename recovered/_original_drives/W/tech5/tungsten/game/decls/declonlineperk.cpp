
// ========================================================================
// ??0idDeclOnlinePerk@@QAA@XZ
// EA  : 0x82BCA730
// RVA : 0x00BCA730
// PDB : w:\tech5\tungsten\game\decls\declonlineperk.cpp
// ========================================================================

idDeclOnlinePerk *__fastcall idDeclOnlinePerk::idDeclOnlinePerk(idDeclOnlinePerk *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->overLoadModifier = 0;
  this->__vftable = (idDeclOnlinePerk_vtbl *)&idDeclOnlinePerk::`vftable';
  this->boostUpModifier = 1.0;
  this->duraBumpModifier = 1.0;
  this->jumpManModifier = 1.0;
  this->overAmmoModifier = 1.0;
  this->lockJackModifier = 1.0;
  this->fasterFasterModifier = 1.0;
  this->theSnapperModifier = 1.0;
  return this;
}


// ========================================================================
// ?LoadAllDecls@idDeclOnlinePerk@@SAXXZ
// EA  : 0x82BCA810
// RVA : 0x00BCA810
// PDB : w:\tech5\tungsten\game\decls\declonlineperk.cpp
// ========================================================================

static void __fastcall idDeclOnlinePerk::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclOnlinePerk::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclOnlinePerk::resourceList.declSources.num;
    do
    {
      str = idDeclOnlinePerk::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclOnlinePerk::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}

