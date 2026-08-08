
// ========================================================================
// ?LoadAllDecls@idDeclAchievement@@SAXXZ
// EA  : 0x82BBB188
// RVA : 0x00BBB188
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

static void __fastcall idDeclAchievement::LoadAllDecls()
{
  int i; // r30
  idStr v1; // [sp+50h] [-70h] BYREF
  char v2; // [sp+70h] [-50h] BYREF

  v1.baseBuffer[0] = 0;
  v2 = 0;
  v1.data = &v2;
  v1.len = 0;
  v1.allocedAndFlag = -2147483616;
  for ( i = 1; i < 51; ++i )
  {
    idStr::Format(this: &v1, fmt: "achievement_%02d", i);
    idResourceList::Load(
      this: &idDeclAchievement::resourceList,
      name: v1.data,
      makeDefault: false,
      skipStaleCheck: false);
  }
  idStr::FreeData(this: &v1);
}


// ========================================================================
// __unwind$487688
// EA  : 0x82BBB210
// RVA : 0x00BBB210
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_487688()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??0idDeclAchievement@@QAA@XZ
// EA  : 0x82BBB240
// RVA : 0x00BBB240
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

idDeclAchievement *__fastcall idDeclAchievement::idDeclAchievement(idDeclAchievement *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclAchievement_vtbl *)&idDeclAchievement::`vftable';
  this->achievementName.index = -1;
  this->description.index = -1;
  this->id = GAME_ACHIEVEMENT_NONE;
  this->flags = (idDeclAchievement::flags_t)(*(_BYTE *)&this->flags & 7 | 0x78);
  this->item.granularity = 0;
  this->item.memTag = 5;
  this->item.listStatic = 0;
  this->item.list = nullptr;
  this->item.size = 0;
  this->item.num = 0;
  this->jobDecl.granularity = 0;
  this->jobDecl.memTag = 5;
  this->jobDecl.listStatic = 0;
  this->jobDecl.list = nullptr;
  this->jobDecl.size = 0;
  this->jobDecl.num = 0;
  this->trigger.list = nullptr;
  this->trigger.granularity = 0;
  this->trigger.memTag = 5;
  this->trigger.listStatic = 0;
  this->trigger.size = 0;
  this->trigger.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trigger);
  this->races.granularity = 0;
  this->races.memTag = 5;
  this->races.listStatic = 0;
  this->races.list = nullptr;
  this->races.size = 0;
  this->races.num = 0;
  this->allRacesRequired = true;
  this->events.list = nullptr;
  this->events.granularity = 0;
  this->events.memTag = 5;
  this->events.listStatic = 0;
  this->events.size = 0;
  this->events.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->events);
  this->allEventsRequired = true;
  this->achievements.list = nullptr;
  this->achievements.granularity = 0;
  this->achievements.memTag = 5;
  this->achievements.listStatic = 0;
  this->achievements.size = 0;
  this->achievements.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->achievements);
  this->avatarAwardId = AVATAR_AWARD_NONE;
  return this;
}


// ========================================================================
// __unwind$488003_0
// EA  : 0x82BBB384
// RVA : 0x00BBB384
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488003_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$488004
// EA  : 0x82BBB3AC
// RVA : 0x00BBB3AC
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488004()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                         + 80));
}


// ========================================================================
// __unwind$488005
// EA  : 0x82BBB3D8
// RVA : 0x00BBB3D8
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488005()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$488006
// EA  : 0x82BBB404
// RVA : 0x00BBB404
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488006()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 112));
}


// ========================================================================
// __unwind$488007
// EA  : 0x82BBB430
// RVA : 0x00BBB430
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488007()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                         + 128));
}


// ========================================================================
// __unwind$488008_1
// EA  : 0x82BBB45C
// RVA : 0x00BBB45C
// PDB : w:\tech5\tungsten\game\decls\declachievements.cpp
// ========================================================================

void _unwind_488008_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 148));
}

