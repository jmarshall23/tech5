
// ========================================================================
// ??0idRetainedItemMemoryForMap@@QAA@XZ
// EA  : 0x824FD050
// RVA : 0x004FD050
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

idRetainedItemMemoryForMap *__fastcall idRetainedItemMemoryForMap::idRetainedItemMemoryForMap(
        idRetainedItemMemoryForMap *this)
{
  this->__vftable = (idRetainedItemMemoryForMap_vtbl *)&idRetainedItemMemoryForMap::`vftable';
  this->mapName.len = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  this->itemsList.granularity = 0;
  this->itemsList.listStatic = 0;
  this->itemsList.memTag = 5;
  this->itemsList.list = nullptr;
  this->itemsList.size = 0;
  this->itemsList.num = 0;
  return this;
}


// ========================================================================
// __unwind$586881
// EA  : 0x824FD0B8
// RVA : 0x004FD0B8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_586881()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$586882
// EA  : 0x824FD0E0
// RVA : 0x004FD0E0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_586882()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// ??0idLayer@@QAA@VidStr@@W4layerState_t@0@@Z
// EA  : 0x82B5D040
// RVA : 0x00B5D040
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

idLayer *__fastcall idLayer::idLayer(idLayer *this, idStr *declName, idLayer::layerState_t layerState_)
{
  this->__vftable = (idLayer_vtbl *)&idLayer::`vftable';
  idStr::idStr(this: &this->layerDeclName, text: declName);
  this->layerState = layerState_;
  idStr::FreeData(this: declName);
  return this;
}


// ========================================================================
// __unwind$489875_1
// EA  : 0x82B5D090
// RVA : 0x00B5D090
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_489875_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 156));
}


// ========================================================================
// __unwind$489876
// EA  : 0x82B5D0B8
// RVA : 0x00B5D0B8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_489876()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 128 + 148));
}


// ========================================================================
// ?Compare@idSort_GameLayer@@QBAHABVidLayer@@0@Z
// EA  : 0x82B5D0E8
// RVA : 0x00B5D0E8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

int __fastcall idSort_GameLayer::Compare(idSort_GameLayer *this, idStr *a, idStr *b)
{
  idStr *Name; // r29
  idStr *v5; // r3
  int v6; // r30
  idLayer v8[2]; // [sp+50h] [-60h] BYREF

  Name = idLayer::GetName(this: (idLayer *)&v8[0].layerDeclName.baseBuffer[16], result: b);
  v5 = idLayer::GetName(this: v8, result: a);
  v6 = idStr::Icmp(s1: v5->data, s2: Name->data);
  idStr::FreeData(this: (idStr *)v8);
  idStr::FreeData(this: (idStr *)&v8[0].layerDeclName.baseBuffer[16]);
  return v6;
}


// ========================================================================
// __unwind$489927
// EA  : 0x82B5D144
// RVA : 0x00B5D144
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_489927()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$489928
// EA  : 0x82B5D16C
// RVA : 0x00B5D16C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.h
// ========================================================================

void _unwind_489928()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}

