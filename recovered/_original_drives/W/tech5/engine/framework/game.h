
// ========================================================================
// ??0gameReturnPlayer_t@@QAA@XZ
// EA  : 0x82643AA8
// RVA : 0x00643AA8
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

gameReturnPlayer_t *__fastcall gameReturnPlayer_t::gameReturnPlayer_t(gameReturnPlayer_t *this)
{
  double valueFloat; // fp13
  double v4; // fp12
  double v5; // fp11
  int valueInteger; // r10

  renderView_t::renderView_t(this: &this->view, threadId: THREAD_MAIN);
  valueFloat = m_sensitivity.valueFloat;
  v4 = joy_yawSpeed.valueFloat;
  v5 = joy_pitchSpeed.valueFloat;
  valueInteger = in_invertLook.valueInteger;
  this->inputSettings.mouseSensScale = 1.0;
  this->inputSettings.joySensScale = 1.0;
  this->inputSettings.bindset = BIND_DEFAULT;
  this->inputSettings.joyPitchSpeed = v5;
  this->inputSettings.joyYawSpeed = v4;
  this->inputSettings.absoluteAngles = false;
  this->inputSettings.mouseSens = valueFloat;
  this->inputSettings.lookInvert = valueInteger != 0;
  this->valid = false;
  this->gui = nullptr;
  this->inventoryModel = nullptr;
  this->hudModel = nullptr;
  this->vibrationLow = 0;
  this->vibrationHigh = 0;
  this->visMask = 0;
  return this;
}


// ========================================================================
// ??0gameReturn_t@@QAA@XZ
// EA  : 0x826440C0
// RVA : 0x006440C0
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

gameReturn_t *__fastcall gameReturn_t::gameReturn_t(gameReturn_t *this)
{
  this->localTime = 0;
  this->serverTime = 0;
  this->forceOneView = false;
  `eh vector constructor iterator'(
    ptr: &this->players,
    size: 0x7A0u,
    count: 6,
    pCtor: (void (__fastcall *)(void *))gameReturnPlayer_t::gameReturnPlayer_t,
    pDtor: (void (__fastcall *)(void *))gameReturnPlayer_t::~gameReturnPlayer_t);
  this->debugGuis.num = 0;
  this->debugGuis.granularity = 1;
  this->debugGuis.list = this->debugGuis.staticList;
  this->debugGuis.size = 8;
  this->debugGuis.memTag = 5;
  this->debugGuis.listStatic = 1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debugGuis);
  return this;
}


// ========================================================================
// __unwind$237275
// EA  : 0x82644148
// RVA : 0x00644148
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_237275()
{
  int v0; // r12

  idArray<gameReturnPlayer_t,6>::~idArray<gameReturnPlayer_t,6>(this: (idArray<gameReturnPlayer_t,6> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$237276
// EA  : 0x82644174
// RVA : 0x00644174
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_237276()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 11728));
}


// ========================================================================
// ?ReadLayersFromCommaSeparatedStrings@idGameSpawnInfo@@QAAXPBD0@Z
// EA  : 0x82652800
// RVA : 0x00652800
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void __fastcall idGameSpawnInfo::ReadLayersFromCommaSeparatedStrings(
        idGameSpawnInfo *this,
        const char *activeString,
        const char *deactiveString)
{
  idStaticList<idStrStatic<128>,256> *p_layersActive; // r28
  char *data; // r11
  int v8; // r10
  int v9; // r29
  idStaticList<idStrStatic<128>,256> *p_layersDeactive; // r28
  idStrStatic<128> *list; // r25
  int size; // r29
  idStr *v13; // r26
  char *v14; // r10
  int v15; // r11
  int v16; // r29
  idStr v17; // [sp+50h] [-310h] BYREF
  idStr v18; // [sp+70h] [-2F0h] BYREF
  idStrStatic<128> v19; // [sp+90h] [-2D0h] BYREF
  idStrStatic<128> v20; // [sp+130h] [-230h] BYREF
  idStrStatic<128> v21; // [sp+1D0h] [-190h] BYREF
  idStrStatic<128> v22; // [sp+270h] [-F0h] BYREF

  p_layersActive = &this->layersActive;
  if ( this->layersActive.listStatic == 0 || this->layersActive.listStatic == 2 )
  {
    if ( p_layersActive->list != nullptr )
      idListArrayDelete<idStrStatic<128>>(ptr: this->layersActive.list, num: this->layersActive.size);
    p_layersActive->list = nullptr;
    p_layersActive->size = 0;
  }
  p_layersActive->num = 0;
  idStr::idStr(this: &v18, text: activeString);
  data = v18.data;
  v8 = 0;
  v9 = 0;
  if ( *v18.data != 0 )
  {
    do
    {
      if ( data[v9] == 44 )
      {
        data[v9] = 0;
        idStrStatic<128>::idStrStatic<128>(this: &v22, text: &v18.data[v8]);
        idList<idStrStatic<128>,5>::Append(this: p_layersActive, obj: &v22);
        idStr::FreeData(this: &v22);
        ++v9;
        data = v18.data;
        v8 = v9;
      }
      ++v9;
    }
    while ( data[v9] != 0 );
  }
  v19.baseBuffer[0] = 0;
  v19.buffer[0] = 0;
  v19.len = 0;
  v19.data = v19.buffer;
  v19.allocedAndFlag = -2147483520;
  idStr::operator=(this: &v19, text: &data[v8]);
  idList<idStrStatic<128>,5>::Append(this: p_layersActive, obj: &v19);
  idStr::FreeData(this: &v19);
  p_layersDeactive = &this->layersDeactive;
  if ( this->layersDeactive.listStatic == 0 || this->layersDeactive.listStatic == 2 )
  {
    list = p_layersDeactive->list;
    if ( p_layersDeactive->list != nullptr )
    {
      size = this->layersDeactive.size;
      if ( size > 0 )
      {
        v13 = p_layersDeactive->list;
        do
        {
          idStr::FreeData(this: v13);
          --size;
          v13 += 5;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    p_layersDeactive->list = nullptr;
    p_layersDeactive->size = 0;
  }
  p_layersDeactive->num = 0;
  idStr::idStr(this: &v17, text: deactiveString);
  v14 = v17.data;
  v15 = 0;
  v16 = 0;
  if ( *v17.data != 0 )
  {
    do
    {
      if ( v14[v16] == 44 )
      {
        v14[v16] = 0;
        v21.baseBuffer[0] = 0;
        v21.buffer[0] = 0;
        v21.data = v21.buffer;
        v21.len = 0;
        v21.allocedAndFlag = -2147483520;
        idStr::operator=(this: &v21, text: &v17.data[v15]);
        idList<idStrStatic<128>,5>::Append(this: p_layersDeactive, obj: &v21);
        idStr::FreeData(this: &v21);
        ++v16;
        v14 = v17.data;
        v15 = v16;
      }
      ++v16;
    }
    while ( v14[v16] != 0 );
  }
  v20.baseBuffer[0] = 0;
  v20.buffer[0] = 0;
  v20.len = 0;
  v20.data = v20.buffer;
  v20.allocedAndFlag = -2147483520;
  idStr::operator=(this: &v20, text: &v14[v15]);
  idList<idStrStatic<128>,5>::Append(this: p_layersDeactive, obj: &v20);
  idStr::FreeData(this: &v20);
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: &v18);
}


// ========================================================================
// __unwind$226597
// EA  : 0x82652A54
// RVA : 0x00652A54
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 112));
}


// ========================================================================
// __unwind$226598
// EA  : 0x82652A7C
// RVA : 0x00652A7C
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226598()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 624));
}


// ========================================================================
// __unwind$226637
// EA  : 0x82652AA4
// RVA : 0x00652AA4
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226637()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 144));
}


// ========================================================================
// __unwind$226599
// EA  : 0x82652ACC
// RVA : 0x00652ACC
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 144));
}


// ========================================================================
// __unwind$226600
// EA  : 0x82652AF4
// RVA : 0x00652AF4
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 80));
}


// ========================================================================
// __unwind$226775
// EA  : 0x82652B1C
// RVA : 0x00652B1C
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226775()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 464));
}


// ========================================================================
// __unwind$226601
// EA  : 0x82652B44
// RVA : 0x00652B44
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226601()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 464));
}


// ========================================================================
// __unwind$226841
// EA  : 0x82652B6C
// RVA : 0x00652B6C
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226841()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 304));
}


// ========================================================================
// __unwind$226602
// EA  : 0x82652B94
// RVA : 0x00652B94
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_226602()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 304));
}


// ========================================================================
// ??0idGameSpawnInfo@@QAA@PBDH@Z
// EA  : 0x82653650
// RVA : 0x00653650
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

idGameSpawnInfo *__fastcall idGameSpawnInfo::idGameSpawnInfo(
        idGameSpawnInfo *this,
        const char *mapName_,
        int gameFlags_)
{
  this->gameFlags = gameFlags_;
  idStrStatic<1024>::idStrStatic<1024>(this: &this->mapName, text: mapName_);
  this->spawnSpot.allocedAndFlag = 20;
  this->spawnSpot.baseBuffer[0] = 0;
  this->spawnSpot.buffer[0] = 0;
  this->spawnSpot.data = this->spawnSpot.buffer;
  this->spawnSpot.len = 0;
  this->spawnSpot.allocedAndFlag = -2147482624;
  this->spawnSpotOverride.allocedAndFlag = 20;
  this->spawnSpotOverride.baseBuffer[0] = 0;
  this->spawnSpotOverride.buffer[0] = 0;
  this->spawnSpotOverride.data = this->spawnSpotOverride.buffer;
  this->spawnSpotOverride.len = 0;
  this->spawnSpotOverride.allocedAndFlag = -2147482624;
  idStaticList<idStrStatic<128>,256>::idStaticList<idStrStatic<128>,256>(this: &this->layersActive);
  idStaticList<idStrStatic<128>,256>::idStaticList<idStrStatic<128>,256>(this: &this->layersDeactive);
  this->comboMap = false;
  this->devmap = false;
  this->isTransitionalMapRequest = false;
  this->initialMap = false;
  this->useLoadingVideo = true;
  this->numPlayers = 1;
  this->debugJobName.allocedAndFlag = 20;
  this->debugJobName.baseBuffer[0] = 0;
  this->debugJobName.data = this->debugJobName.buffer;
  this->debugJobName.buffer[0] = 0;
  this->debugJobName.len = 0;
  this->debugJobName.allocedAndFlag = -2147482624;
  this->debugJobState = 0;
  this->skipToCheckpoint = false;
  this->loadingSequentialMap = false;
  return this;
}


// ========================================================================
// __unwind$227310
// EA  : 0x82653778
// RVA : 0x00653778
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_227310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$227311
// EA  : 0x826537A4
// RVA : 0x006537A4
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_227311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 1060));
}


// ========================================================================
// __unwind$227312
// EA  : 0x826537D0
// RVA : 0x006537D0
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_227312()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 2116));
}


// ========================================================================
// __unwind$227313
// EA  : 0x826537FC
// RVA : 0x006537FC
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void _unwind_227313()
{
  int v0; // r12

  idStaticList<idStrStatic<128>,256>::~idStaticList<idStrStatic<128>,256>(this: (idStaticList<idStrStatic<128>,256> *)(*(_DWORD *)(v0 - 128 + 148) + 3172));
}


// ========================================================================
// ?WriteLayersToCommaSeparatedStrings@idGameSpawnInfo@@QBAXAAVidStr@@0@Z
// EA  : 0x8265F1B0
// RVA : 0x0065F1B0
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void __fastcall idGameSpawnInfo::WriteLayersToCommaSeparatedStrings(
        idGameSpawnInfo *this,
        idStr *activeString,
        idStr *deactiveString)
{
  int v6; // r29
  int num; // r11
  int v8; // r28
  int *p_num; // r28
  int v10; // r29
  int v11; // r11
  int v12; // r30

  idStr::operator=(this: activeString, text: &byte_8200D768);
  v6 = 0;
  num = this->layersActive.num;
  if ( num - 1 > 0 )
  {
    v8 = 0;
    do
    {
      idStr::Append(this: activeString, text: &this->layersActive.list[v8]);
      idStr::Append(this: activeString, text: ",");
      num = this->layersActive.num;
      ++v6;
      ++v8;
    }
    while ( v6 < num - 1 );
  }
  if ( num > 0 )
    idStr::Append(this: activeString, text: &this->layersActive.list[num - 1]);
  idStr::operator=(this: deactiveString, text: &byte_8200D768);
  p_num = &this->layersDeactive.num;
  v10 = 0;
  v11 = this->layersDeactive.num;
  if ( v11 - 1 > 0 )
  {
    v12 = 0;
    do
    {
      idStr::Append(this: deactiveString, text: &this->layersDeactive.list[v12]);
      idStr::Append(this: deactiveString, text: ",");
      v11 = *p_num;
      ++v10;
      ++v12;
    }
    while ( v10 < *p_num - 1 );
  }
  if ( v11 > 0 )
    idStr::Append(this: deactiveString, text: &this->layersDeactive.list[v11 - 1]);
}


// ========================================================================
// ??1idGame@@UAA@XZ
// EA  : 0x82D78D20
// RVA : 0x00D78D20
// PDB : w:\tech5\engine\framework\game.h
// ========================================================================

void __fastcall idGame::~idGame(idGame *this)
{
  this->__vftable = (idGame_vtbl *)&idGame::`vftable';
}

