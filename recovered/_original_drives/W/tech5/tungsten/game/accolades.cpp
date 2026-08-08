
// ========================================================================
// ??0idAccolade@@QAA@ABVidDeclAccolade@@H@Z
// EA  : 0x829EE238
// RVA : 0x009EE238
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

idAccolade *__fastcall idAccolade::idAccolade(idAccolade *this, const idDeclAccolade *decl_, int count_)
{
  this->count = count_;
  this->decl = decl_;
  return this;
}


// ========================================================================
// ?Icon@idAccolade@@QBAPBDXZ
// EA  : 0x829EE248
// RVA : 0x009EE248
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

const char *__fastcall idAccolade::Icon(idAccolade *this)
{
  return idDeclAccolade::GetIconName(this: this->decl);
}


// ========================================================================
// ?Name@idAccolade@@QBAPBDXZ
// EA  : 0x829EE250
// RVA : 0x009EE250
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

char *__fastcall idAccolade::Name(idAccolade *this)
{
  return this->decl->accoladeName.data;
}


// ========================================================================
// ?Description@idAccolade@@QBAPBDXZ
// EA  : 0x829EE260
// RVA : 0x009EE260
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

char *__fastcall idAccolade::Description(idAccolade *this)
{
  return this->decl->description.data;
}


// ========================================================================
// ?Num@idAccolades@@SAHXZ
// EA  : 0x829EE270
// RVA : 0x009EE270
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

int __fastcall idAccolades::Num()
{
  return idDeclAccolade::resourceList.num;
}


// ========================================================================
// ?GetLifetime@idAccolades@@SA?AVidAccolade@@AAVidLocalUser@@H@Z
// EA  : 0x829EE280
// RVA : 0x009EE280
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

idAccolade *__fastcall idAccolades::GetLifetime(idAccolade *result, idLocalUser *user, int index)
{
  const idDeclAccolade *v4; // r30

  v4 = idDeclAccolade::orderedList.list[index];
  result->count = GetStatAsInt(user, stat: v4->stat);
  result->decl = v4;
  return result;
}


// ========================================================================
// ?GetSession@idAccolades@@SA?AVidAccolade@@HH@Z
// EA  : 0x829EE2D8
// RVA : 0x009EE2D8
// PDB : w:\tech5\tungsten\game\accolades.cpp
// ========================================================================

idAccolade *__fastcall idAccolades::GetSession(idAccolade *result, int playerId, int index)
{
  const idDeclAccolade *v4; // r30

  v4 = idDeclAccolade::orderedList.list[index];
  result->count = idRageMetrics::GetSessionStat(this: clientGame->rageMetrics, playerId, stat: v4->stat);
  result->decl = v4;
  return result;
}

