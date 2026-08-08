
// ========================================================================
// ?SetAchievement@idPlayerProfile@@QAAXH@Z
// EA  : 0x8267B4B8
// RVA : 0x0067B4B8
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayerProfile::SetAchievement(idPlayerProfile *this, int id, int a3, unsigned __int64 a4, __int64 a5)
{
  __int128 v5; // r10
  int v6; // r6

  if ( id < 128 )
  {
    if ( id >= 64 )
    {
      *((_QWORD *)&v5 + 1) = this->achievementBits2;
      DWORD1(v5) = id - 64;
      v6 = (*(_QWORD *)((char *)&v5 + 4) << SBYTE7(v5)) | LODWORD(this->achievementBits2);
      this->achievementBits2 = *(_QWORD *)(&a3 - 1);
    }
    else
    {
      *(__int64 *)((char *)&a5 - 4) = this->achievementBits;
      LODWORD(a4) = (a5 << id) | LODWORD(this->achievementBits);
      this->achievementBits = a4;
    }
  }
}


// ========================================================================
// ?GetAchievement@idPlayerProfile@@QBA_NH@Z
// EA  : 0x8267B500
// RVA : 0x0067B500
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idPlayerProfile::GetAchievement(idPlayerProfile *this, int id)
{
  __int64 v3; // r11 OVERLAPPED
  bool v4; // cr58

  if ( id >= 128 )
    return 0;
  LODWORD(v3) = 1;
  if ( id >= 64 )
  {
    HIDWORD(v3) = id - 64;
    v4 = ((unsigned int)(v3 << ((unsigned __int8)id - 64)) & this->achievementBits2) == 0;
  }
  else
  {
    *(__int64 *)((char *)&v3 + 4) = this->achievementBits;
    v4 = ((unsigned int)(v3 << HIDWORD(this->achievementBits)) & this->achievementBits) == 0;
  }
  if ( v4 )
    LOBYTE(v3) = 0;
  return (unsigned __int8)v3;
}


// ========================================================================
// ?StatSetInt@idPlayerProfile@@AAAXHH@Z
// EA  : 0x8267B560
// RVA : 0x0067B560
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::StatSetInt(idPlayerProfile *this, const int stat, profileStatValue_t value)
{
  this->stats.list[stat] = value;
}


// ========================================================================
// ?StatSetFloat@idPlayerProfile@@AAAXHM@Z
// EA  : 0x8267B570
// RVA : 0x0067B570
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::StatSetFloat(idPlayerProfile *this, const int stat, double value)
{
  this->stats.list[stat].f = value;
}


// ========================================================================
// ?StatGetInt@idPlayerProfile@@ABAHH@Z
// EA  : 0x8267B580
// RVA : 0x0067B580
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

int __fastcall idPlayerProfile::StatGetInt(idPlayerProfile *this, const int stat)
{
  return this->stats.list[stat].i;
}


// ========================================================================
// ?StatGetFloat@idPlayerProfile@@ABAMH@Z
// EA  : 0x8267B590
// RVA : 0x0067B590
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

float __fastcall idPlayerProfile::StatGetFloat(idPlayerProfile *this, const int stat)
{
  double f; // fp1

  f = this->stats.list[stat].f;
  return *((float *)&f + 1);
}


// ========================================================================
// ?SaveSettings@idPlayerProfile@@QAAXXZ
// EA  : 0x8267B5A0
// RVA : 0x0067B5A0
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::SaveSettings(idPlayerProfile *this)
{
  if ( this->state != SAVING && this->requestedState == 0 )
    this->requestedState = SAVE_REQUESTED;
}


// ========================================================================
// ?LoadSettings@idPlayerProfile@@QAAXXZ
// EA  : 0x8267B5C8
// RVA : 0x0067B5C8
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::LoadSettings(idPlayerProfile *this)
{
  if ( this->hasUser && this->state != LOADING && this->requestedState == 0 )
    this->requestedState = LOAD_REQUESTED;
}


// ========================================================================
// ?setProfileDefaults_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8267B5F8
// RVA : 0x0067B5F8
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall setProfileDefaults_f(const idCmdArgs *args)
{
  idPlayerProfile *v1; // r3
  idPlayerProfile *v2; // r31

  v1 = common->GetProfileFromMasterLocalUser(this: common);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v1->SetDefaults(this: v1);
    if ( v2->state != SAVING && v2->requestedState == 0 )
      v2->requestedState = SAVE_REQUESTED;
  }
}


// ========================================================================
// ??1idPlayerProfile@@UAA@XZ
// EA  : 0x8267B670
// RVA : 0x0067B670
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::~idPlayerProfile(idPlayerProfile *this)
{
  this->__vftable = (idPlayerProfile_vtbl *)&idPlayerProfile::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stats);
}


// ========================================================================
// ?SetDefaults@idPlayerProfile@@UAAXXZ
// EA  : 0x8267B6F8
// RVA : 0x0067B6F8
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void __fastcall idPlayerProfile::SetDefaults(idPlayerProfile *this)
{
  unsigned __int64 v1; // r30
  idStaticList<profileStatValue_t,500> *p_stats; // r31
  int size; // r11
  int v4; // r11
  int i; // ctr

  LODWORD(v1) = 0;
  this->achievementBits = v1;
  p_stats = &this->stats;
  this->hasUser = true;
  this->achievementBits2 = v1;
  this->dlcReleaseVersion = 0;
  if ( this->stats.size >= 500
    || idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->stats, newsize: 500) )
  {
    size = p_stats->size;
    if ( size > 500 )
      size = 500;
    p_stats->num = size;
  }
  v4 = 0;
  for ( i = 500; i != 0; --i )
    p_stats->list[v4++].i = 0;
}


// ========================================================================
// ??0idPlayerProfile@@IAA@XZ
// EA  : 0x8267B7A0
// RVA : 0x0067B7A0
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

idPlayerProfile *__fastcall idPlayerProfile::idPlayerProfile(idPlayerProfile *this)
{
  this->__vftable = (idPlayerProfile_vtbl *)&idPlayerProfile::`vftable';
  this->stats.granularity = 1;
  this->stats.num = 0;
  this->stats.size = 500;
  this->stats.memTag = 5;
  this->stats.list = this->stats.staticList;
  this->stats.listStatic = 1;
  idPlayerProfile::SetDefaults(this);
  this->state = 0;
  this->requestedState = 0;
  this->deviceNum = -1;
  return this;
}


// ========================================================================
// __unwind$219550
// EA  : 0x8267B814
// RVA : 0x0067B814
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

void _unwind_219550()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// `dynamic initializer for 'setProfileDefaults_v''
// EA  : 0x8333BB58
// RVA : 0x0133BB58
// PDB : w:\tech5\engine\framework\playerprofile.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setProfileDefaults_v__()
{
  return idCommandLink::idCommandLink(
           this: &setProfileDefaults_v,
           cmdName: "setProfileDefaults",
           function: setProfileDefaults_f,
           description: "sets profile settings to default and saves",
           argCompletion: nullptr);
}

