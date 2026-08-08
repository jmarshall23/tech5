
// ========================================================================
// ?GetMapModelName@idMapFile@@SA?AVidStr@@PBD0@Z
// EA  : 0x825C75B0
// RVA : 0x005C75B0
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

idStr *__fastcall idMapFile::GetMapModelName(idStr *result, __int64 entityName, int a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v8; // [sp+8h] [-1058h]
  int v9; // [sp+Ch] [-1054h]
  int v10; // [sp+10h] [-1050h]
  int v11; // [sp+14h] [-104Ch]
  int v12; // [sp+18h] [-1048h]
  int v13; // [sp+1Ch] [-1044h]
  va v14; // [sp+50h] [-1010h] BYREF

  LODWORD(a5) = &unk_821B0000;
  v6 = va::va(this: &v14, fmt: "%s/%s", a3: entityName, a4, a5, a6: v8, a7: v9, a8: v10, a9: v11, a10: v12, a11: v13);
  idStr::idStr(this: result, text: v6);
  return result;
}


// ========================================================================
// ??0idRefMapDef@@QAA@PBD0@Z
// EA  : 0x8279E9F0
// RVA : 0x0079E9F0
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

idRefMapDef *__fastcall idRefMapDef::idRefMapDef(idRefMapDef *this, const char *name, const char *entityText)
{
  idStr *p_worldSpawnText; // r29

  this->mapName.len = 0;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.allocedAndFlag = 20;
  this->mapName.baseBuffer[0] = 0;
  p_worldSpawnText = &this->worldSpawnText;
  this->worldSpawnText.allocedAndFlag = 20;
  this->worldSpawnText.len = 0;
  this->worldSpawnText.data = this->worldSpawnText.baseBuffer;
  this->worldSpawnText.baseBuffer[0] = 0;
  idStr::operator=(this: &this->mapName, text: name);
  idStr::operator=(this: p_worldSpawnText, text: entityText);
  return this;
}


// ========================================================================
// __unwind$229696
// EA  : 0x8279EA60
// RVA : 0x0079EA60
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_229696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$229697
// EA  : 0x8279EA88
// RVA : 0x0079EA88
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_229697()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// ??1idMapGroups@@UAA@XZ
// EA  : 0x827A3770
// RVA : 0x007A3770
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapGroups::~idMapGroups(idMapGroups *this)
{
  idStr *list; // r3
  idStr *v3; // r3

  this->__vftable = (idMapGroups_vtbl *)&idMapGroups::`vftable';
  if ( this->groupList.listStatic == 0 || this->groupList.listStatic == 2 )
  {
    list = this->groupList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->groupList.size);
    this->groupList.list = nullptr;
    this->groupList.size = 0;
  }
  this->groupList.num = 0;
  if ( this->groupList.listStatic == 0 || this->groupList.listStatic == 2 )
  {
    v3 = this->groupList.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->groupList.size);
    this->groupList.list = nullptr;
    this->groupList.size = 0;
  }
  this->groupList.num = 0;
}


// ========================================================================
// __unwind$237432
// EA  : 0x827A3808
// RVA : 0x007A3808
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_237432()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??1idMapPrimitive@@UAA@XZ
// EA  : 0x827A3898
// RVA : 0x007A3898
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapPrimitive::~idMapPrimitive(idMapPrimitive *this)
{
  this->__vftable = (idMapPrimitive_vtbl *)&idMapPrimitive::`vftable';
  idMapGroups::~idMapGroups(this);
}


// ========================================================================
// ??1idMapPatch@@UAA@XZ
// EA  : 0x827A48C0
// RVA : 0x007A48C0
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapPatch::~idMapPatch(idMapPatch *this)
{
  this->__vftable = (idMapPatch_vtbl *)&idMapPatch::`vftable';
  idStr::FreeData(this: &this->material);
  idSurface::~idSurface(this: (splineMoverModifier_t::splineMoverModifierSound_t *)&this->idSurface_Patch);
  this->__vftable = (idMapPatch_vtbl *)&idMapPrimitive::`vftable';
  idMapGroups::~idMapGroups(this);
}


// ========================================================================
// __unwind$238763
// EA  : 0x827A4928
// RVA : 0x007A4928
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_238763()
{
  int v0; // r12

  idMapPrimitive::~idMapPrimitive(this: *(idMapPrimitive **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$238764
// EA  : 0x827A4950
// RVA : 0x007A4950
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_238764()
{
  int v0; // r12

  idSurface_Patch::~idSurface_Patch(this: (idSurface_Patch *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ??0idMapEditorStates@@QAA@XZ
// EA  : 0x827A5668
// RVA : 0x007A5668
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

idMapEditorStates *__fastcall idMapEditorStates::idMapEditorStates(idMapEditorStates *this)
{
  this->__vftable = (idMapEditorStates_vtbl *)&idMapEditorStates::`vftable';
  this->groupStates.granularity = 0;
  this->groupStates.memTag = 5;
  this->groupStates.listStatic = 0;
  this->groupStates.list = nullptr;
  this->groupStates.size = 0;
  this->groupStates.num = 0;
  this->layerStates.granularity = 0;
  this->layerStates.memTag = 5;
  this->layerStates.listStatic = 0;
  this->layerStates.list = nullptr;
  this->layerStates.size = 0;
  this->layerStates.num = 0;
  this->groupColors.granularity = 0;
  this->groupColors.memTag = 5;
  this->groupColors.listStatic = 0;
  this->groupColors.list = nullptr;
  this->groupColors.size = 0;
  this->groupColors.num = 0;
  return this;
}


// ========================================================================
// __unwind$240370
// EA  : 0x827A56F4
// RVA : 0x007A56F4
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240370()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// __unwind$240371
// EA  : 0x827A5720
// RVA : 0x007A5720
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240371()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 32 + 52) + 20));
}


// ========================================================================
// ??1idMapEditorStates@@UAA@XZ
// EA  : 0x827A5758
// RVA : 0x007A5758
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapEditorStates::~idMapEditorStates(idMapEditorStates *this)
{
  idGroupState *list; // r3
  idGroupState *v3; // r3
  idGroupState *v4; // r3
  idGroupState *v5; // r3

  this->__vftable = (idMapEditorStates_vtbl *)&idMapEditorStates::`vftable';
  if ( this->groupStates.listStatic == 0 || this->groupStates.listStatic == 2 )
  {
    list = this->groupStates.list;
    if ( list != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &list->groupName, num: this->groupStates.size);
    this->groupStates.list = nullptr;
    this->groupStates.size = 0;
  }
  this->groupStates.num = 0;
  if ( this->groupColors.listStatic == 0 || this->groupColors.listStatic == 2 )
  {
    v3 = this->groupColors.list;
    if ( v3 != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &v3->groupName, num: this->groupColors.size);
    this->groupColors.list = nullptr;
    this->groupColors.size = 0;
  }
  this->groupColors.num = 0;
  if ( this->layerStates.listStatic == 0 || this->layerStates.listStatic == 2 )
  {
    v4 = this->layerStates.list;
    if ( v4 != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &v4->groupName, num: this->layerStates.size);
    this->layerStates.list = nullptr;
    this->layerStates.size = 0;
  }
  this->layerStates.num = 0;
  if ( this->groupStates.listStatic == 0 || this->groupStates.listStatic == 2 )
  {
    v5 = this->groupStates.list;
    if ( v5 != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &v5->groupName, num: this->groupStates.size);
    this->groupStates.list = nullptr;
    this->groupStates.size = 0;
  }
  this->groupStates.num = 0;
}


// ========================================================================
// __unwind$240435
// EA  : 0x827A5858
// RVA : 0x007A5858
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240435()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                         + 4));
}


// ========================================================================
// __unwind$240436
// EA  : 0x827A5884
// RVA : 0x007A5884
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240436()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                         + 20));
}


// ========================================================================
// __unwind$240437
// EA  : 0x827A58B0
// RVA : 0x007A58B0
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240437()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                         + 36));
}


// ========================================================================
// ?AddReferenceMap@idMapFile@@QAAXPBD0@Z
// EA  : 0x827A5DD0
// RVA : 0x007A5DD0
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapFile::AddReferenceMap(idMapFile *this, const char *name, const char *worldSpawnText)
{
  const idXMLAttribute *v3; // r30
  idList<idXMLAttribute,44> *p_referenceMaps; // r29
  idXMLAttribute v5; // [sp+50h] [-60h] BYREF

  p_referenceMaps = (idList<idXMLAttribute,44> *)&this->referenceMaps;
  v3 = (const idXMLAttribute *)idRefMapDef::idRefMapDef(this: (idRefMapDef *)&v5, name, entityText: worldSpawnText);
  if ( idList<idRefMapDef,5>::FindIndex(
         this: (idList<idRefMapDef,5> *)p_referenceMaps,
         obj: (const idRefMapDef *)v3,
         startIndex: 0) < 0 )
    idList<idXMLAttribute,44>::Append(this: p_referenceMaps, obj: v3);
  idKeyValue::~idKeyValue(this: &v5);
}


// ========================================================================
// __unwind$240768
// EA  : 0x827A5E28
// RVA : 0x007A5E28
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void _unwind_240768()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(v0 - 176 + 80));
}


// ========================================================================
// ?ClearLayerList@idMapEntity@@QAAXXZ
// EA  : 0x82D9D438
// RVA : 0x00D9D438
// PDB : w:\tech5\engine\mapfile\mapfile.h
// ========================================================================

void __fastcall idMapEntity::ClearLayerList(idMapEntity *this)
{
  idStr *list; // r3

  if ( this->layerList.listStatic == 0 || this->layerList.listStatic == 2 )
  {
    list = this->layerList.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->layerList.size);
    this->layerList.list = nullptr;
    this->layerList.size = 0;
  }
  this->layerList.num = 0;
}

