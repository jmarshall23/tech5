
// ========================================================================
// ??1idDeclBot@@UAA@XZ
// EA  : 0x82BBC950
// RVA : 0x00BBC950
// PDB : w:\tech5\tungsten\game\decls\declbot.cpp
// ========================================================================

void __fastcall idDeclBot::~idDeclBot(idDeclBot *this)
{
  this->__vftable = (idDeclBot_vtbl *)&idDeclBot::`vftable';
  idStr::FreeData(this: &this->botName);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$487203
// EA  : 0x82BBC9A4
// RVA : 0x00BBC9A4
// PDB : w:\tech5\tungsten\game\decls\declbot.cpp
// ========================================================================

void _unwind_487203()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idDeclBot@@QAA@XZ
// EA  : 0x82BBC9E8
// RVA : 0x00BBC9E8
// PDB : w:\tech5\tungsten\game\decls\declbot.cpp
// ========================================================================

idDeclBot *__fastcall idDeclBot::idDeclBot(idDeclBot *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclBot_vtbl *)&idDeclBot::`vftable';
  idStr::idStr(this: &this->botName, text: "Phobos");
  return this;
}


// ========================================================================
// __unwind$487289
// EA  : 0x82BBCA44
// RVA : 0x00BBCA44
// PDB : w:\tech5\tungsten\game\decls\declbot.cpp
// ========================================================================

void _unwind_487289()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?LoadAllDecls@idDeclBot@@SAXXZ
// EA  : 0x82BBCAD0
// RVA : 0x00BBCAD0
// PDB : w:\tech5\tungsten\game\decls\declbot.cpp
// ========================================================================

static void __fastcall idDeclBot::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclBot::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclBot::resourceList.declSources.num;
    do
    {
      str = idDeclBot::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclBot::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}

