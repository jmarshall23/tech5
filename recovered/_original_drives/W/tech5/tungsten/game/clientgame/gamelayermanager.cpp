
// ========================================================================
// ?FindRetainedEntityState@idGameLayerManager@@QAAPAVidEntityRetainedState@@PBD@Z
// EA  : 0x82B5CF00
// RVA : 0x00B5CF00
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

idEntityRetainedState *__fastcall idGameLayerManager::FindRetainedEntityState(
        idGameLayerManager *this,
        const char *entityName)
{
  int v4; // r29
  int i; // r30

  v4 = 0;
  if ( this->entityRetainedStates.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Cmp(s1: this->entityRetainedStates.list[i].entityName.data, s2: entityName) != 0; ++i )
  {
    if ( ++v4 >= this->entityRetainedStates.num )
      return nullptr;
  }
  return &this->entityRetainedStates.list[v4];
}


// ========================================================================
// ?PrintItemMemoryInfo@idGameLayerManager@@QAAXXZ
// EA  : 0x82B5CF78
// RVA : 0x00B5CF78
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::PrintItemMemoryInfo(idGameLayerManager *this)
{
  int v2; // r28
  idRetainedItemMemoryForMap *list; // r11
  int v4; // r29
  idRetainedItemMemoryForMap *v5; // r11
  int v6; // r31
  idRetainedItemMemoryForMap *v7; // r10
  int v8; // r30

  v2 = 0;
  if ( this->retainedItemMemoryForMap.num > 0 )
  {
    list = this->retainedItemMemoryForMap.list;
    v4 = 0;
    do
    {
      idLib::Warning(fmt: "%d: %s", v2, list->mapName.data);
      v5 = this->retainedItemMemoryForMap.list;
      v6 = 0;
      v7 = &v5[v4];
      if ( v5[v4].itemsList.num > 0 )
      {
        v8 = 0;
        do
        {
          idLib::Printf(fmt: "%d: \t%d: %s\n", v2, v6, v7->itemsList.list[v8].data);
          v5 = this->retainedItemMemoryForMap.list;
          ++v6;
          ++v8;
          v7 = &v5[v4];
        }
        while ( v6 < v5[v4].itemsList.num );
      }
      ++v2;
      list = &v5[++v4];
    }
    while ( v2 < this->retainedItemMemoryForMap.num );
  }
}


// ========================================================================
// ?WriteToFile@idGameLayerManager@@QBAXPAVidFile@@@Z
// EA  : 0x82B5D198
// RVA : 0x00B5D198
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::WriteToFile(idGameLayerManager *this, idFile *file)
{
  idFile_vtbl *v3; // r10
  int v5; // r28
  int v6; // r27
  idLayer *v7; // r29
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  char v9; // r11
  char v10; // r7
  idFile_vtbl *v11; // r10
  int v12; // r28
  int v13; // r27
  idStr *v14; // r29
  unsigned int (__fastcall *v15)(idFile *, const void *, unsigned int); // r8
  char v16; // r10
  char v17; // r7
  idFile_vtbl *v18; // r10
  int v19; // r28
  int v20; // r27
  idStr *v21; // r29
  unsigned int (__fastcall *v22)(idFile *, const void *, unsigned int); // r8
  char v23; // r10
  char v24; // r11
  idFile_vtbl *v25; // r10
  int v26; // r27
  int v27; // r29
  idEntityRetainedState *v28; // r28
  unsigned int (__fastcall *v29)(idFile *, const void *, unsigned int); // r8
  char v30; // r11
  char v31; // r10
  idFile_vtbl *v32; // r10
  int v33; // r25
  int v34; // r26
  idRetainedItemMemoryForMap *v35; // r29
  unsigned int (__fastcall *v36)(idFile *, const void *, unsigned int); // ctr
  char v37; // r10
  char v38; // r6
  int v39; // r28
  int v40; // r27
  idStr *v41; // r29
  unsigned int (__fastcall *v42)(idFile *, const void *, unsigned int); // ctr
  char v43; // r9
  char v44; // r11
  int len; // [sp+50h] [-70h] BYREF
  unsigned int v46; // [sp+54h] [-6Ch] BYREF
  unsigned int v47; // [sp+58h] [-68h] BYREF
  unsigned int v48; // [sp+5Ch] [-64h] BYREF
  int v49; // [sp+60h] [-60h] BYREF
  unsigned int v50; // [sp+64h] [-5Ch] BYREF
  int num; // [sp+68h] [-58h] BYREF
  int v52; // [sp+6Ch] [-54h] BYREF
  int v53; // [sp+70h] [-50h] BYREF
  int v54; // [sp+74h] [-4Ch] BYREF
  int v55; // [sp+78h] [-48h] BYREF
  int v56; // [sp+7Ch] [-44h] BYREF

  v3 = file->__vftable;
  num = this->playerLayers.num;
  v3->Write(this: file, a2: &num, a3: 4u);
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->playerLayers.list[v6];
      Write = file->Write;
      len = v7->layerDeclName.len;
      v9 = BYTE1(len);
      v10 = HIBYTE(len);
      BYTE1(len) = BYTE2(len);
      HIBYTE(len) = len;
      LOBYTE(len) = v10;
      BYTE2(len) = v9;
      Write(this: file, a2: &len, a3: 4u);
      file->Write(this: file, a2: v7->layerDeclName.data, a3: v7->layerDeclName.len);
      file->Write(this: file, a2: &v7->layerState, a3: 4u);
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
  v11 = file->__vftable;
  v52 = this->layers_ToMarkActiveNextMapLoad.num;
  v11->Write(this: file, a2: &v52, a3: 4u);
  v12 = 0;
  if ( v52 > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &this->layers_ToMarkActiveNextMapLoad.list[v13];
      v15 = file->Write;
      v46 = v14->len;
      v16 = HIBYTE(v46);
      v17 = BYTE1(v46);
      BYTE1(v46) = BYTE2(v46);
      BYTE2(v46) = v17;
      HIBYTE(v46) = v46;
      LOBYTE(v46) = v16;
      v15(this: file, a2: &v46, a3: 4u);
      file->Write(this: file, a2: v14->data, a3: v14->len);
      ++v12;
      ++v13;
    }
    while ( v12 < v52 );
  }
  v18 = file->__vftable;
  v53 = this->layers_ToMarkDeactiveNextMapLoad.num;
  v18->Write(this: file, a2: &v53, a3: 4u);
  v19 = 0;
  if ( v53 > 0 )
  {
    v20 = 0;
    do
    {
      v21 = &this->layers_ToMarkDeactiveNextMapLoad.list[v20];
      v22 = file->Write;
      v47 = v21->len;
      v23 = v47;
      v24 = BYTE1(v47);
      BYTE1(v47) = BYTE2(v47);
      LOBYTE(v47) = HIBYTE(v47);
      BYTE2(v47) = v24;
      HIBYTE(v47) = v23;
      v22(this: file, a2: &v47, a3: 4u);
      file->Write(this: file, a2: v21->data, a3: v21->len);
      ++v19;
      ++v20;
    }
    while ( v19 < v53 );
  }
  v25 = file->__vftable;
  v54 = this->entityRetainedStates.num;
  v25->Write(this: file, a2: &v54, a3: 4u);
  v26 = 0;
  if ( v54 > 0 )
  {
    v27 = 0;
    do
    {
      v28 = &this->entityRetainedStates.list[v27];
      v29 = file->Write;
      v48 = v28->entityName.len;
      v30 = BYTE1(v48);
      v31 = v48;
      LOBYTE(v48) = HIBYTE(v48);
      BYTE1(v48) = BYTE2(v48);
      BYTE2(v48) = v30;
      HIBYTE(v48) = v31;
      v29(this: file, a2: &v48, a3: 4u);
      file->Write(this: file, a2: v28->entityName.data, a3: v28->entityName.len);
      file->Write(this: file, a2: &this->entityRetainedStates.list[v27].state, a3: 4u);
      file->Write(this: file, a2: &this->entityRetainedStates.list[v27].targetState, a3: 4u);
      file->Write(this: file, a2: &this->entityRetainedStates.list[v27].timeStarted, a3: 8u);
      ++v26;
      ++v27;
    }
    while ( v26 < v54 );
  }
  v32 = file->__vftable;
  v56 = this->retainedItemMemoryForMap.num;
  v32->Write(this: file, a2: &v56, a3: 4u);
  v33 = 0;
  if ( v56 > 0 )
  {
    v34 = 0;
    do
    {
      v35 = &this->retainedItemMemoryForMap.list[v34];
      v36 = file->Write;
      v49 = v35->mapName.len;
      v37 = v49;
      LOBYTE(v49) = HIBYTE(v49);
      v38 = BYTE2(v49);
      HIBYTE(v49) = v37;
      BYTE2(v49) = BYTE1(v49);
      BYTE1(v49) = v38;
      v36(this: file, a2: &v49, a3: 4u);
      file->Write(this: file, a2: v35->mapName.data, a3: v35->mapName.len);
      v55 = this->retainedItemMemoryForMap.list[v34].itemsList.num;
      file->Write(this: file, a2: &v55, a3: 4u);
      v39 = 0;
      if ( v55 > 0 )
      {
        v40 = 0;
        do
        {
          v41 = &this->retainedItemMemoryForMap.list[v34].itemsList.list[v40];
          v42 = file->Write;
          v50 = v41->len;
          v43 = HIBYTE(v50);
          HIBYTE(v50) = v50;
          v44 = BYTE2(v50);
          LOBYTE(v50) = v43;
          BYTE2(v50) = BYTE1(v50);
          BYTE1(v50) = v44;
          v42(this: file, a2: &v50, a3: 4u);
          file->Write(this: file, a2: v41->data, a3: v41->len);
          ++v39;
          ++v40;
        }
        while ( v39 < v55 );
      }
      ++v33;
      ++v34;
    }
    while ( v33 < v56 );
  }
}


// ========================================================================
// ?ContainsItemMemory@idGameLayerManager@@QBA_NPBD@Z
// EA  : 0x82B5D6A0
// RVA : 0x00B5D6A0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

int __fastcall idGameLayerManager::ContainsItemMemory(idGameLayerManager *this, const char *itemName)
{
  const char *v4; // r3
  int v5; // r29
  int v6; // r30
  int v8; // r27
  idRetainedItemMemoryForMap *v9; // r11
  int v10; // r29
  int v11; // r30
  idStr v12[3]; // [sp+60h] [-60h] BYREF

  if ( gameLocal == nullptr )
    return 0;
  v4 = gameLocal->GetMapName(this: gameLocal);
  idStr::idStr(this: v12, text: v4);
  v5 = 0;
  if ( this->retainedItemMemoryForMap.num <= 0 )
    goto LABEL_6;
  v6 = 0;
  while ( idStr::Icmp(s1: v12[0].data, s2: this->retainedItemMemoryForMap.list[v6].mapName.data) != 0 )
  {
    ++v5;
    ++v6;
    if ( v5 >= this->retainedItemMemoryForMap.num )
      goto LABEL_6;
  }
  v8 = v5;
  v9 = &this->retainedItemMemoryForMap.list[v5];
  v10 = 0;
  if ( v9->itemsList.num <= 0 )
  {
LABEL_6:
    idStr::FreeData(this: v12);
    return 0;
  }
  v11 = 0;
  while ( idStr::Icmp(s1: v9->itemsList.list[v11].data, s2: itemName) != 0 )
  {
    ++v10;
    ++v11;
    v9 = &this->retainedItemMemoryForMap.list[v8];
    if ( v10 >= v9->itemsList.num )
      goto LABEL_6;
  }
  idStr::FreeData(this: v12);
  return 1;
}


// ========================================================================
// __unwind$490984
// EA  : 0x82B5D7AC
// RVA : 0x00B5D7AC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_490984()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?GameLayerActiveItemMemories_f@idGameLayerManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82B5D7D8
// RVA : 0x00B5D7D8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::GameLayerActiveItemMemories_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  idLib::Warning(fmt: "Active item memories in the game layer manager:");
  if ( DebugPlayer != nullptr )
    idGameLayerManager::PrintItemMemoryInfo(this: &DebugPlayer->gameLayerManager);
  idLib::Warning(fmt: "---");
}


// ========================================================================
// ?PrintLayerInfo@idGameLayerManager@@QAAXXZ
// EA  : 0x82B5D840
// RVA : 0x00B5D840
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::PrintLayerInfo(idGameLayerManager *this)
{
  int v2; // r30
  int v3; // r29
  idStr *v4; // r4
  idStr *v5; // r3
  idStr *v6; // r3
  idStr *Name; // r3
  idLayer v8[3]; // [sp+60h] [-80h] BYREF

  if ( idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
  {
    v2 = 0;
    if ( this->playerLayers.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = (idStr *)&this->playerLayers.list[v3];
        if ( v4[1].data != nullptr )
        {
          Name = idLayer::GetName(this: (idLayer *)&v8[0].layerDeclName.baseBuffer[16], result: v4);
          idLib::Printf(fmt: "\t%d: %s\n", v2, Name->data);
          v6 = (idStr *)&v8[0].layerDeclName.baseBuffer[16];
        }
        else
        {
          v5 = idLayer::GetName(this: v8, result: v4);
          idLib::Printf(fmt: "^5\t%d: %s\n", v2, v5->data);
          v6 = (idStr *)v8;
        }
        idStr::FreeData(this: v6);
        ++v2;
        ++v3;
      }
      while ( v2 < this->playerLayers.num );
    }
  }
}


// ========================================================================
// __unwind$491067
// EA  : 0x82B5D900
// RVA : 0x00B5D900
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491067()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$491068
// EA  : 0x82B5D928
// RVA : 0x00B5D928
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491068()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?ClearLayers@idGameLayerManager@@QAAXXZ
// EA  : 0x82B5DBA0
// RVA : 0x00B5DBA0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::ClearLayers(idGameLayerManager *this)
{
  char *list; // r3
  idStr *v3; // r3
  idStr *v4; // r3
  idStr *v5; // r3
  idStr *v6; // r3

  if ( this->playerLayers.listStatic == 0 || this->playerLayers.listStatic == 2 )
  {
    list = (char *)this->playerLayers.list;
    if ( list != nullptr )
      idListArrayDelete<idLayer>(ptr: list, num: this->playerLayers.size);
    this->playerLayers.list = nullptr;
    this->playerLayers.size = 0;
  }
  this->playerLayers.num = 0;
  if ( this->layers_DeactiveToActive.listStatic == 0 || this->layers_DeactiveToActive.listStatic == 2 )
  {
    v3 = this->layers_DeactiveToActive.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->layers_DeactiveToActive.size);
    this->layers_DeactiveToActive.list = nullptr;
    this->layers_DeactiveToActive.size = 0;
  }
  this->layers_DeactiveToActive.num = 0;
  if ( this->layers_ActiveToDeactivate.listStatic == 0 || this->layers_ActiveToDeactivate.listStatic == 2 )
  {
    v4 = this->layers_ActiveToDeactivate.list;
    if ( v4 != nullptr )
      idListArrayDelete<idStr>(ptr: v4, num: this->layers_ActiveToDeactivate.size);
    this->layers_ActiveToDeactivate.list = nullptr;
    this->layers_ActiveToDeactivate.size = 0;
  }
  this->layers_ActiveToDeactivate.num = 0;
  if ( this->layers_ToRemove.listStatic == 0 || this->layers_ToRemove.listStatic == 2 )
  {
    v5 = this->layers_ToRemove.list;
    if ( v5 != nullptr )
      idListArrayDelete<idStr>(ptr: v5, num: this->layers_ToRemove.size);
    this->layers_ToRemove.list = nullptr;
    this->layers_ToRemove.size = 0;
  }
  this->layers_ToRemove.num = 0;
  if ( this->layers_ToRemoveFromGameLocalLists.listStatic == 0
    || this->layers_ToRemoveFromGameLocalLists.listStatic == 2 )
  {
    v6 = this->layers_ToRemoveFromGameLocalLists.list;
    if ( v6 != nullptr )
      idListArrayDelete<idStr>(ptr: v6, num: this->layers_ToRemoveFromGameLocalLists.size);
    this->layers_ToRemoveFromGameLocalLists.list = nullptr;
    this->layers_ToRemoveFromGameLocalLists.size = 0;
  }
  this->layers_ToRemoveFromGameLocalLists.num = 0;
}


// ========================================================================
// ?GameLayerActiveLayers_f@idGameLayerManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x82B5DCD8
// RVA : 0x00B5DCD8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::GameLayerActiveLayers_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31
  int v2; // r31
  idGameLocal *v3; // r11
  int v4; // r30
  idGameLocal *v5; // r11
  int v6; // r31
  int v7; // r30

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  idLib::Warning(fmt: "Active Layers in the game layer manager:");
  if ( DebugPlayer != nullptr )
    idGameLayerManager::PrintLayerInfo(this: &DebugPlayer->gameLayerManager);
  idLib::Warning(fmt: "---");
  idLib::Warning(fmt: "Deactive Layers in the current map:");
  v2 = 0;
  v3 = gameLocal;
  if ( gameLocal->deactiveLayers.num > 0 )
  {
    v4 = 0;
    do
    {
      idLib::Printf(fmt: "\t%d: %s\n", v2, v3->deactiveLayers.list[v4].data);
      v3 = gameLocal;
      ++v2;
      ++v4;
    }
    while ( v2 < gameLocal->deactiveLayers.num );
  }
  idLib::Warning(fmt: "---");
  idLib::Warning(fmt: "Active Layers in the current map:");
  v5 = gameLocal;
  v6 = 0;
  if ( gameLocal->activeLayers.num > 0 )
  {
    v7 = 0;
    do
    {
      idLib::Printf(fmt: "\t%d: %s\n", v6, v5->activeLayers.list[v7].data);
      v5 = gameLocal;
      ++v6;
      ++v7;
    }
    while ( v6 < gameLocal->activeLayers.num );
  }
}


// ========================================================================
// ?RemoveLayerFromTransientLists@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5E278
// RVA : 0x00B5E278
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayerFromTransientLists(idGameLayerManager *this, const char *layerName)
{
  int Index; // r4
  int v5; // r4
  int v6; // r4
  int v7; // r4
  int v8; // r4
  idList<idStr,5> *p_layers_ToMarkDeactiveNextMapLoad; // r30
  int v10; // r4
  idStr v11; // [sp+50h] [-F0h] BYREF
  idStr v12; // [sp+70h] [-D0h] BYREF
  idStr v13; // [sp+90h] [-B0h] BYREF
  idStr v14; // [sp+B0h] [-90h] BYREF
  idStr v15; // [sp+D0h] [-70h] BYREF
  idStr v16[2]; // [sp+F0h] [-50h] BYREF

  idStr::idStr(this: &v15, text: layerName);
  Index = idList<idStr,5>::FindIndex(this: &this->layers_DeactiveToActive, obj: &v15, startIndex: 0);
  if ( Index >= 0 )
    idList<idStr,5>::RemoveIndex(this: &this->layers_DeactiveToActive, index: Index);
  idStr::FreeData(this: &v15);
  idStr::idStr(this: &v13, text: layerName);
  v5 = idList<idStr,5>::FindIndex(this: &this->layers_ActiveToDeactivate, obj: &v13, startIndex: 0);
  if ( v5 >= 0 )
    idList<idStr,5>::RemoveIndex(this: &this->layers_ActiveToDeactivate, index: v5);
  idStr::FreeData(this: &v13);
  idStr::idStr(this: &v11, text: layerName);
  v6 = idList<idStr,5>::FindIndex(this: &this->layers_ToRemove, obj: &v11, startIndex: 0);
  if ( v6 >= 0 )
    idList<idStr,5>::RemoveIndex(this: &this->layers_ToRemove, index: v6);
  idStr::FreeData(this: &v11);
  idStr::idStr(this: &v12, text: layerName);
  v7 = idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v12, startIndex: 0);
  if ( v7 >= 0 )
    idList<idStr,5>::RemoveIndex(this: &this->layers_ToRemoveFromGameLocalLists, index: v7);
  idStr::FreeData(this: &v12);
  idStr::idStr(this: &v14, text: layerName);
  v8 = idList<idStr,5>::FindIndex(this: &this->layers_ToMarkActiveNextMapLoad, obj: &v14, startIndex: 0);
  if ( v8 >= 0 )
    idList<idStr,5>::RemoveIndex(this: &this->layers_ToMarkActiveNextMapLoad, index: v8);
  idStr::FreeData(this: &v14);
  idStr::idStr(this: v16, text: layerName);
  p_layers_ToMarkDeactiveNextMapLoad = &this->layers_ToMarkDeactiveNextMapLoad;
  v10 = idList<idStr,5>::FindIndex(this: p_layers_ToMarkDeactiveNextMapLoad, obj: v16, startIndex: 0);
  if ( v10 >= 0 )
    idList<idStr,5>::RemoveIndex(this: p_layers_ToMarkDeactiveNextMapLoad, index: v10);
  idStr::FreeData(this: v16);
}


// ========================================================================
// __unwind$491769_0
// EA  : 0x82B5E3FC
// RVA : 0x00B5E3FC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491769_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 208));
}


// ========================================================================
// __unwind$491770_0
// EA  : 0x82B5E424
// RVA : 0x00B5E424
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491770_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$491771
// EA  : 0x82B5E44C
// RVA : 0x00B5E44C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491771()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$491772
// EA  : 0x82B5E474
// RVA : 0x00B5E474
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491772()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$491773
// EA  : 0x82B5E49C
// RVA : 0x00B5E49C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491773()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 176));
}


// ========================================================================
// __unwind$491774
// EA  : 0x82B5E4C4
// RVA : 0x00B5E4C4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491774()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 240));
}


// ========================================================================
// ?ActivateDeactiveLayer@idGameLayerManager@@QAA_NPBD@Z
// EA  : 0x82B5E4F8
// RVA : 0x00B5E4F8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

int __fastcall idGameLayerManager::ActivateDeactiveLayer(idGameLayerManager *this, const char *layerName)
{
  int v4; // r29
  int v5; // r28
  idLayer *v7; // r11
  idList<idStr,5> *p_layers_DeactiveToActive; // r30
  idStr v9; // [sp+50h] [-70h] BYREF
  idStr v10[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: &v9, text: layerName);
  idStr::ToLower(this: &v9);
  v4 = 0;
  if ( this->playerLayers.num <= 0 )
  {
LABEL_5:
    idLib::Printf(
      fmt: "idGameLayerManager::ActivateDeactiveLayer not activating %s because it is not on the player\n",
      layerName);
LABEL_6:
    idStr::FreeData(this: &v9);
    return 0;
  }
  v5 = 0;
  while ( idStr::Icmp(s1: v9.data, s2: this->playerLayers.list[v5].layerDeclName.data) != 0 )
  {
    ++v4;
    ++v5;
    if ( v4 >= this->playerLayers.num )
      goto LABEL_5;
  }
  v7 = &this->playerLayers.list[v4];
  if ( v7->layerState == LAYERSTATE_ACTIVE )
  {
    idLib::Printf(
      fmt: "idGameLayerManager::ActivateDeactiveLayer not activating %s because it is already active\n",
      layerName);
    goto LABEL_6;
  }
  v7->layerState = LAYERSTATE_ACTIVE;
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: v10, text: layerName);
  p_layers_DeactiveToActive = &this->layers_DeactiveToActive;
  if ( idList<idStr,5>::FindIndex(this: p_layers_DeactiveToActive, obj: v10, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: p_layers_DeactiveToActive, obj: v10);
  idStr::FreeData(this: v10);
  idStr::FreeData(this: &v9);
  return 1;
}


// ========================================================================
// $M491970
// EA  : 0x82B5E640
// RVA : 0x00B5E640
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _M491970()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$491881
// EA  : 0x82B5E668
// RVA : 0x00B5E668
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491881()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?DeactivateActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5E698
// RVA : 0x00B5E698
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::DeactivateActiveLayer(idGameLayerManager *this, const char *layerName)
{
  char v4; // r27
  int v5; // r29
  int v6; // r28
  idLayer *v7; // r11
  idList<idStr,5> *p_layers_ActiveToDeactivate; // r30
  idStr v9; // [sp+50h] [-80h] BYREF
  idStr v10[3]; // [sp+70h] [-60h] BYREF

  idStr::idStr(this: v10, text: layerName);
  idStr::ToLower(this: v10);
  v4 = 0;
  v5 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v6 = 0;
    while ( idStr::Icmp(s1: v10[0].data, s2: this->playerLayers.list[v6].layerDeclName.data) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->playerLayers.num )
        goto LABEL_9;
    }
    v4 = 1;
    v7 = &this->playerLayers.list[v5];
    if ( v7->layerState == LAYERSTATE_ACTIVE )
      v7->layerState = LAYERSTATE_DEACTIVE;
    else
      idLib::Printf(
        fmt: "idGameLayerManager::DeactivateActiveLayer not deactivating %s because it is not active\n",
        layerName);
  }
LABEL_9:
  if ( v4 == 0 )
    idLib::Printf(
      fmt: "idGameLayerManager::DeactivateActiveLayer not deactivating %s because it is not on the player\n",
      layerName);
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v9, text: layerName);
  p_layers_ActiveToDeactivate = &this->layers_ActiveToDeactivate;
  if ( idList<idStr,5>::FindIndex(this: p_layers_ActiveToDeactivate, obj: &v9, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: p_layers_ActiveToDeactivate, obj: &v9);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$491989
// EA  : 0x82B5E7E4
// RVA : 0x00B5E7E4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491989()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$491990
// EA  : 0x82B5E80C
// RVA : 0x00B5E80C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_491990()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?RemoveActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5E840
// RVA : 0x00B5E840
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveActiveLayer(idGameLayerManager *this, const char *layerName)
{
  int v4; // r28
  int v5; // r30
  idStr v6; // [sp+50h] [-80h] BYREF
  idStr v7[3]; // [sp+70h] [-60h] BYREF

  idStr::idStr(this: v7, text: layerName);
  idStr::ToLower(this: v7);
  v4 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v5 = 0;
    while ( idStr::Icmp(s1: v7[0].data, s2: this->playerLayers.list[v5].layerDeclName.data) != 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->playerLayers.num )
        goto LABEL_7;
    }
    idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v4);
  }
LABEL_7:
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v6, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$492086
// EA  : 0x82B5E918
// RVA : 0x00B5E918
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492086()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$492087
// EA  : 0x82B5E940
// RVA : 0x00B5E940
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?RemoveActiveLayerFromMap@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5E970
// RVA : 0x00B5E970
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveActiveLayerFromMap(idGameLayerManager *this, const char *layerName)
{
  int v4; // r28
  int v5; // r30
  idStr v6; // [sp+50h] [-80h] BYREF
  idStr v7[3]; // [sp+70h] [-60h] BYREF

  idStr::idStr(this: v7, text: layerName);
  idStr::ToLower(this: v7);
  v4 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v5 = 0;
    while ( idStr::Icmp(s1: v7[0].data, s2: this->playerLayers.list[v5].layerDeclName.data) != 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->playerLayers.num )
        goto LABEL_7;
    }
    idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v4);
  }
LABEL_7:
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v6, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemove, obj: &v6, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToRemove, obj: &v6);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$492156
// EA  : 0x82B5EA48
// RVA : 0x00B5EA48
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492156()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$492157
// EA  : 0x82B5EA70
// RVA : 0x00B5EA70
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492157()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?RemoveLayerMarkActiveNextMapLoad@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5EAA0
// RVA : 0x00B5EAA0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayerMarkActiveNextMapLoad(idGameLayerManager *this, const char *layerName)
{
  int v4; // r28
  int v5; // r30
  idStr v6; // [sp+50h] [-A0h] BYREF
  idStr v7; // [sp+70h] [-80h] BYREF
  idStr v8[3]; // [sp+90h] [-60h] BYREF

  idStr::idStr(this: v8, text: layerName);
  idStr::ToLower(this: v8);
  v4 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v5 = 0;
    while ( idStr::Icmp(s1: v8[0].data, s2: this->playerLayers.list[v5].layerDeclName.data) != 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->playerLayers.num )
        goto LABEL_7;
    }
    idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v4);
  }
LABEL_7:
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v6, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6);
  idStr::FreeData(this: &v6);
  idStr::idStr(this: &v7, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToMarkActiveNextMapLoad, obj: &v7, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToMarkActiveNextMapLoad, obj: &v7);
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$492227
// EA  : 0x82B5EBB4
// RVA : 0x00B5EBB4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492227()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$492228
// EA  : 0x82B5EBDC
// RVA : 0x00B5EBDC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492228()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$492229
// EA  : 0x82B5EC04
// RVA : 0x00B5EC04
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492229()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?RemoveLayerMarkDeactiveNextMapLoad@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B5EC38
// RVA : 0x00B5EC38
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayerMarkDeactiveNextMapLoad(idGameLayerManager *this, const char *layerName)
{
  int v4; // r28
  int v5; // r30
  idStr v6; // [sp+50h] [-A0h] BYREF
  idStr v7; // [sp+70h] [-80h] BYREF
  idStr v8[3]; // [sp+90h] [-60h] BYREF

  idStr::idStr(this: v8, text: layerName);
  idStr::ToLower(this: v8);
  v4 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v5 = 0;
    while ( idStr::Icmp(s1: v8[0].data, s2: this->playerLayers.list[v5].layerDeclName.data) != 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->playerLayers.num )
        goto LABEL_7;
    }
    idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v4);
  }
LABEL_7:
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v6, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v6);
  idStr::FreeData(this: &v6);
  idStr::idStr(this: &v7, text: layerName);
  if ( idList<idStr,5>::FindIndex(this: &this->layers_ToMarkDeactiveNextMapLoad, obj: &v7, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: &this->layers_ToMarkDeactiveNextMapLoad, obj: &v7);
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$492314
// EA  : 0x82B5ED4C
// RVA : 0x00B5ED4C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492314()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$492315
// EA  : 0x82B5ED74
// RVA : 0x00B5ED74
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$492316
// EA  : 0x82B5ED9C
// RVA : 0x00B5ED9C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492316()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ??0idGameLayerManager@@QAA@XZ
// EA  : 0x82B5F010
// RVA : 0x00B5F010
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

idGameLayerManager *__fastcall idGameLayerManager::idGameLayerManager(idGameLayerManager *this)
{
  this->entityRetainedStates.granularity = 0;
  this->entityRetainedStates.memTag = 5;
  this->entityRetainedStates.listStatic = 0;
  this->entityRetainedStates.list = nullptr;
  this->entityRetainedStates.size = 0;
  this->entityRetainedStates.num = 0;
  this->retainedItemMemoryForMap.granularity = 0;
  this->retainedItemMemoryForMap.memTag = 5;
  this->retainedItemMemoryForMap.listStatic = 0;
  this->retainedItemMemoryForMap.list = nullptr;
  this->retainedItemMemoryForMap.size = 0;
  this->retainedItemMemoryForMap.num = 0;
  this->owner = nullptr;
  this->playerLayers.granularity = 0;
  this->playerLayers.memTag = 5;
  this->playerLayers.listStatic = 0;
  this->playerLayers.list = nullptr;
  this->playerLayers.size = 0;
  this->playerLayers.num = 0;
  this->layers_DeactiveToActive.granularity = 0;
  this->layers_DeactiveToActive.memTag = 5;
  this->layers_DeactiveToActive.listStatic = 0;
  this->layers_DeactiveToActive.list = nullptr;
  this->layers_DeactiveToActive.size = 0;
  this->layers_DeactiveToActive.num = 0;
  this->layers_ActiveToDeactivate.granularity = 0;
  this->layers_ActiveToDeactivate.memTag = 5;
  this->layers_ActiveToDeactivate.listStatic = 0;
  this->layers_ActiveToDeactivate.list = nullptr;
  this->layers_ActiveToDeactivate.size = 0;
  this->layers_ActiveToDeactivate.num = 0;
  this->layers_ToRemove.granularity = 0;
  this->layers_ToRemove.memTag = 5;
  this->layers_ToRemove.listStatic = 0;
  this->layers_ToRemove.list = nullptr;
  this->layers_ToRemove.size = 0;
  this->layers_ToRemove.num = 0;
  this->layers_ToRemoveFromGameLocalLists.granularity = 0;
  this->layers_ToRemoveFromGameLocalLists.memTag = 5;
  this->layers_ToRemoveFromGameLocalLists.listStatic = 0;
  this->layers_ToRemoveFromGameLocalLists.list = nullptr;
  this->layers_ToRemoveFromGameLocalLists.size = 0;
  this->layers_ToRemoveFromGameLocalLists.num = 0;
  this->layers_ToMarkActiveNextMapLoad.granularity = 0;
  this->layers_ToMarkActiveNextMapLoad.memTag = 5;
  this->layers_ToMarkActiveNextMapLoad.listStatic = 0;
  this->layers_ToMarkActiveNextMapLoad.list = nullptr;
  this->layers_ToMarkActiveNextMapLoad.size = 0;
  this->layers_ToMarkActiveNextMapLoad.num = 0;
  this->layers_ToMarkDeactiveNextMapLoad.granularity = 0;
  this->layers_ToMarkDeactiveNextMapLoad.memTag = 5;
  this->layers_ToMarkDeactiveNextMapLoad.listStatic = 0;
  this->layers_ToMarkDeactiveNextMapLoad.list = nullptr;
  this->layers_ToMarkDeactiveNextMapLoad.size = 0;
  this->layers_ToMarkDeactiveNextMapLoad.num = 0;
  this->inDebug = false;
  this->inInitState = false;
  return this;
}


// ========================================================================
// __unwind$492658
// EA  : 0x82B5F154
// RVA : 0x00B5F154
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492658()
{
  int v0; // r12

  idList<lobbyPlayerInfo_t,5>::~idList<lobbyPlayerInfo_t,5>(this: *(idList<idEntityRetainedState,5> **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$492659
// EA  : 0x82B5F17C
// RVA : 0x00B5F17C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492659()
{
  int v0; // r12

  idList<idRetainedItemMemoryForMap,5>::~idList<idRetainedItemMemoryForMap,5>(this: (idList<idRetainedItemMemoryForMap,5> *)(*(_DWORD *)(v0 - 32 + 52) + 16));
}


// ========================================================================
// __unwind$492660
// EA  : 0x82B5F1A8
// RVA : 0x00B5F1A8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492660()
{
  int v0; // r12

  idList<idLayer,5>::Clear(this: (idList<idAIVar_Int,5> *)(*(_DWORD *)(v0 - 32 + 52) + 36));
}


// ========================================================================
// __unwind$492661
// EA  : 0x82B5F1D4
// RVA : 0x00B5F1D4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492661()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 52));
}


// ========================================================================
// __unwind$492662
// EA  : 0x82B5F200
// RVA : 0x00B5F200
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492662()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 68));
}


// ========================================================================
// __unwind$492663
// EA  : 0x82B5F22C
// RVA : 0x00B5F22C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492663()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 84));
}


// ========================================================================
// __unwind$492664
// EA  : 0x82B5F258
// RVA : 0x00B5F258
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492664()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 100));
}


// ========================================================================
// __unwind$492665
// EA  : 0x82B5F284
// RVA : 0x00B5F284
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492665()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 116));
}


// ========================================================================
// ??1idGameLayerManager@@QAA@XZ
// EA  : 0x82B5F2B8
// RVA : 0x00B5F2B8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::~idGameLayerManager(idGameLayerManager *this)
{
  idStr *list; // r3
  idStr *v3; // r3
  idStr *v4; // r3
  idStr *v5; // r3
  idStr *v6; // r3
  idStr *v7; // r3
  char *v8; // r3
  char *v9; // r3

  idGameLayerManager::ClearLayers(this);
  if ( this->layers_ToMarkDeactiveNextMapLoad.listStatic == 0 || this->layers_ToMarkDeactiveNextMapLoad.listStatic == 2 )
  {
    list = this->layers_ToMarkDeactiveNextMapLoad.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->layers_ToMarkDeactiveNextMapLoad.size);
    this->layers_ToMarkDeactiveNextMapLoad.list = nullptr;
    this->layers_ToMarkDeactiveNextMapLoad.size = 0;
  }
  this->layers_ToMarkDeactiveNextMapLoad.num = 0;
  if ( this->layers_ToMarkActiveNextMapLoad.listStatic == 0 || this->layers_ToMarkActiveNextMapLoad.listStatic == 2 )
  {
    v3 = this->layers_ToMarkActiveNextMapLoad.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->layers_ToMarkActiveNextMapLoad.size);
    this->layers_ToMarkActiveNextMapLoad.list = nullptr;
    this->layers_ToMarkActiveNextMapLoad.size = 0;
  }
  this->layers_ToMarkActiveNextMapLoad.num = 0;
  if ( this->layers_ToRemoveFromGameLocalLists.listStatic == 0
    || this->layers_ToRemoveFromGameLocalLists.listStatic == 2 )
  {
    v4 = this->layers_ToRemoveFromGameLocalLists.list;
    if ( v4 != nullptr )
      idListArrayDelete<idStr>(ptr: v4, num: this->layers_ToRemoveFromGameLocalLists.size);
    this->layers_ToRemoveFromGameLocalLists.list = nullptr;
    this->layers_ToRemoveFromGameLocalLists.size = 0;
  }
  this->layers_ToRemoveFromGameLocalLists.num = 0;
  if ( this->layers_ToRemove.listStatic == 0 || this->layers_ToRemove.listStatic == 2 )
  {
    v5 = this->layers_ToRemove.list;
    if ( v5 != nullptr )
      idListArrayDelete<idStr>(ptr: v5, num: this->layers_ToRemove.size);
    this->layers_ToRemove.list = nullptr;
    this->layers_ToRemove.size = 0;
  }
  this->layers_ToRemove.num = 0;
  if ( this->layers_ActiveToDeactivate.listStatic == 0 || this->layers_ActiveToDeactivate.listStatic == 2 )
  {
    v6 = this->layers_ActiveToDeactivate.list;
    if ( v6 != nullptr )
      idListArrayDelete<idStr>(ptr: v6, num: this->layers_ActiveToDeactivate.size);
    this->layers_ActiveToDeactivate.list = nullptr;
    this->layers_ActiveToDeactivate.size = 0;
  }
  this->layers_ActiveToDeactivate.num = 0;
  if ( this->layers_DeactiveToActive.listStatic == 0 || this->layers_DeactiveToActive.listStatic == 2 )
  {
    v7 = this->layers_DeactiveToActive.list;
    if ( v7 != nullptr )
      idListArrayDelete<idStr>(ptr: v7, num: this->layers_DeactiveToActive.size);
    this->layers_DeactiveToActive.list = nullptr;
    this->layers_DeactiveToActive.size = 0;
  }
  this->layers_DeactiveToActive.num = 0;
  if ( this->playerLayers.listStatic == 0 || this->playerLayers.listStatic == 2 )
  {
    v8 = (char *)this->playerLayers.list;
    if ( v8 != nullptr )
      idListArrayDelete<idLayer>(ptr: v8, num: this->playerLayers.size);
    this->playerLayers.list = nullptr;
    this->playerLayers.size = 0;
  }
  this->playerLayers.num = 0;
  if ( this->retainedItemMemoryForMap.listStatic == 0 || this->retainedItemMemoryForMap.listStatic == 2 )
  {
    v9 = (char *)this->retainedItemMemoryForMap.list;
    if ( v9 != nullptr )
      idListArrayDelete<idRetainedItemMemoryForMap>(ptr: v9, num: this->retainedItemMemoryForMap.size);
    this->retainedItemMemoryForMap.list = nullptr;
    this->retainedItemMemoryForMap.size = 0;
  }
  this->retainedItemMemoryForMap.num = 0;
  if ( this->entityRetainedStates.listStatic == 0 || this->entityRetainedStates.listStatic == 2 )
  {
    if ( this->entityRetainedStates.list != nullptr )
      idListArrayDelete<lobbyPlayerInfo_t>(
        ptr: &this->entityRetainedStates.list->entityName,
        num: this->entityRetainedStates.size);
    this->entityRetainedStates.list = nullptr;
    this->entityRetainedStates.size = 0;
  }
  this->entityRetainedStates.num = 0;
}


// ========================================================================
// __unwind$492842
// EA  : 0x82B5F4B4
// RVA : 0x00B5F4B4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492842()
{
  int v0; // r12

  idList<lobbyPlayerInfo_t,5>::~idList<lobbyPlayerInfo_t,5>(this: *(idList<idEntityRetainedState,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$492843
// EA  : 0x82B5F4DC
// RVA : 0x00B5F4DC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492843()
{
  int v0; // r12

  idList<idRetainedItemMemoryForMap,5>::~idList<idRetainedItemMemoryForMap,5>(this: (idList<idRetainedItemMemoryForMap,5> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$492844
// EA  : 0x82B5F508
// RVA : 0x00B5F508
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492844()
{
  int v0; // r12

  idList<idLayer,5>::Clear(this: (idList<idAIVar_Int,5> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$492845
// EA  : 0x82B5F534
// RVA : 0x00B5F534
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492845()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$492846
// EA  : 0x82B5F560
// RVA : 0x00B5F560
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492846()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$492847
// EA  : 0x82B5F58C
// RVA : 0x00B5F58C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492847()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$492848
// EA  : 0x82B5F5B8
// RVA : 0x00B5F5B8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492848()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$492849
// EA  : 0x82B5F5E4
// RVA : 0x00B5F5E4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492849()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// __unwind$492850
// EA  : 0x82B5F610
// RVA : 0x00B5F610
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_492850()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 132));
}


// ========================================================================
// ?ActivateDeactiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B5F648
// RVA : 0x00B5F648
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::ActivateDeactiveLayers(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r21
  int v5; // r26
  const idDeclLayer **v6; // r11
  const char *str; // r27
  int v8; // r30
  int v9; // r29
  idLayer *v10; // r11
  idStr v11; // [sp+60h] [-B0h] BYREF
  idStr v12[4]; // [sp+80h] [-90h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::ActivateDeactiveLayers\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &layerlist->list[v5];
      if ( *v6 != nullptr )
      {
        str = (*v6)->name.str;
        idStr::idStr(this: &v11, text: str);
        idStr::ToLower(this: &v11);
        v8 = 0;
        if ( this->playerLayers.num <= 0 )
        {
LABEL_11:
          idLib::Printf(
            fmt: "idGameLayerManager::ActivateDeactiveLayer not activating %s because it is not on the player\n",
            str);
        }
        else
        {
          v9 = 0;
          while ( idStr::Icmp(s1: v11.data, s2: this->playerLayers.list[v9].layerDeclName.data) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->playerLayers.num )
              goto LABEL_11;
          }
          v10 = &this->playerLayers.list[v8];
          if ( v10->layerState == LAYERSTATE_ACTIVE )
          {
            idLib::Printf(
              fmt: "idGameLayerManager::ActivateDeactiveLayer not activating %s because it is already active\n",
              str);
          }
          else
          {
            v10->layerState = LAYERSTATE_ACTIVE;
            idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
            idStr::idStr(this: v12, text: str);
            if ( idList<idStr,5>::FindIndex(this: &this->layers_DeactiveToActive, obj: v12, startIndex: 0) < 0 )
              idList<idStr,5>::Append(this: &this->layers_DeactiveToActive, obj: v12);
            idStr::FreeData(this: v12);
          }
        }
        idStr::FreeData(this: &v11);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// $M493228_0
// EA  : 0x82B5F80C
// RVA : 0x00B5F80C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _M493228_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$493082
// EA  : 0x82B5F834
// RVA : 0x00B5F834
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// ?DeactiveateActiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B5F868
// RVA : 0x00B5F868
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::DeactiveateActiveLayers(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r19
  int v5; // r25
  const char *str; // r27
  char v7; // r26
  int v8; // r30
  int v9; // r29
  idLayer *v10; // r11
  idStr v11; // [sp+50h] [-C0h] BYREF
  idStr v12[5]; // [sp+70h] [-A0h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::DeactiveateActiveLayers\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: v12, text: str);
        idStr::ToLower(this: v12);
        v7 = 0;
        v8 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v9 = 0;
          while ( idStr::Icmp(s1: v12[0].data, s2: this->playerLayers.list[v9].layerDeclName.data) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->playerLayers.num )
              goto LABEL_15;
          }
          v7 = 1;
          v10 = &this->playerLayers.list[v8];
          if ( v10->layerState == LAYERSTATE_ACTIVE )
            v10->layerState = LAYERSTATE_DEACTIVE;
          else
            idLib::Printf(
              fmt: "idGameLayerManager::DeactivateActiveLayer not deactivating %s because it is not active\n",
              str);
        }
LABEL_15:
        if ( v7 == 0 )
          idLib::Printf(
            fmt: "idGameLayerManager::DeactivateActiveLayer not deactivating %s because it is not on the player\n",
            str);
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v11, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ActiveToDeactivate, obj: &v11, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ActiveToDeactivate, obj: &v11);
        idStr::FreeData(this: &v11);
        idStr::FreeData(this: v12);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$493277
// EA  : 0x82B5FA38
// RVA : 0x00B5FA38
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493277()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$493278
// EA  : 0x82B5FA60
// RVA : 0x00B5FA60
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493278()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// ?RemoveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B5FA90
// RVA : 0x00B5FA90
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayers(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r23
  int v5; // r25
  const char *str; // r26
  int v7; // r29
  int v8; // r30
  idStr v9; // [sp+50h] [-A0h] BYREF
  idStr v10[4]; // [sp+70h] [-80h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::RemoveLayers\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: v10, text: str);
        idStr::ToLower(this: v10);
        v7 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v8 = 0;
          while ( idStr::Icmp(s1: v10[0].data, s2: this->playerLayers.list[v8].layerDeclName.data) != 0 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->playerLayers.num )
              goto LABEL_13;
          }
          idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v7);
        }
LABEL_13:
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v9, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9);
        idStr::FreeData(this: &v9);
        idStr::FreeData(this: v10);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$493455
// EA  : 0x82B5FBE0
// RVA : 0x00B5FBE0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493455()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$493456
// EA  : 0x82B5FC08
// RVA : 0x00B5FC08
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493456()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?RemoveLayersMarkActiveNextMapLoad@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B5FC38
// RVA : 0x00B5FC38
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayersMarkActiveNextMapLoad(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r23
  int v5; // r25
  const char *str; // r26
  int v7; // r29
  int v8; // r30
  idStr v9; // [sp+50h] [-C0h] BYREF
  idStr v10; // [sp+70h] [-A0h] BYREF
  idStr v11[4]; // [sp+90h] [-80h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::RemoveLayersMarkActiveNextMapLoad\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: v11, text: str);
        idStr::ToLower(this: v11);
        v7 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v8 = 0;
          while ( idStr::Icmp(s1: v11[0].data, s2: this->playerLayers.list[v8].layerDeclName.data) != 0 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->playerLayers.num )
              goto LABEL_13;
          }
          idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v7);
        }
LABEL_13:
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v9, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9);
        idStr::FreeData(this: &v9);
        idStr::idStr(this: &v10, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToMarkActiveNextMapLoad, obj: &v10, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToMarkActiveNextMapLoad, obj: &v10);
        idStr::FreeData(this: &v10);
        idStr::FreeData(this: v11);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$493589
// EA  : 0x82B5FDC4
// RVA : 0x00B5FDC4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493589()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$493590
// EA  : 0x82B5FDEC
// RVA : 0x00B5FDEC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493590()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$493591
// EA  : 0x82B5FE14
// RVA : 0x00B5FE14
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493591()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// ?RemoveLayersMarkDeactiveNextMapLoad@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B5FE48
// RVA : 0x00B5FE48
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayersMarkDeactiveNextMapLoad(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r23
  int v5; // r25
  const char *str; // r26
  int v7; // r29
  int v8; // r30
  idStr v9; // [sp+50h] [-C0h] BYREF
  idStr v10; // [sp+70h] [-A0h] BYREF
  idStr v11[4]; // [sp+90h] [-80h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::RemoveLayersMarkDeactiveNextMapLoad\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: v11, text: str);
        idStr::ToLower(this: v11);
        v7 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v8 = 0;
          while ( idStr::Icmp(s1: v11[0].data, s2: this->playerLayers.list[v8].layerDeclName.data) != 0 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->playerLayers.num )
              goto LABEL_13;
          }
          idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v7);
        }
LABEL_13:
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v9, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToRemoveFromGameLocalLists, obj: &v9);
        idStr::FreeData(this: &v9);
        idStr::idStr(this: &v10, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToMarkDeactiveNextMapLoad, obj: &v10, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToMarkDeactiveNextMapLoad, obj: &v10);
        idStr::FreeData(this: &v10);
        idStr::FreeData(this: v11);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$493744
// EA  : 0x82B5FFD4
// RVA : 0x00B5FFD4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493744()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$493745
// EA  : 0x82B5FFFC
// RVA : 0x00B5FFFC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493745()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$493746
// EA  : 0x82B60024
// RVA : 0x00B60024
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493746()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// ?RemoveLayersFromGame@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B60058
// RVA : 0x00B60058
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::RemoveLayersFromGame(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r23
  int v5; // r25
  const char *str; // r26
  int v7; // r29
  int v8; // r30
  idStr v9; // [sp+50h] [-A0h] BYREF
  idStr v10[4]; // [sp+70h] [-80h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::RemoveLayersFromGame\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: v10, text: str);
        idStr::ToLower(this: v10);
        v7 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v8 = 0;
          while ( idStr::Icmp(s1: v10[0].data, s2: this->playerLayers.list[v8].layerDeclName.data) != 0 )
          {
            ++v7;
            ++v8;
            if ( v7 >= this->playerLayers.num )
              goto LABEL_13;
          }
          idList<idLayer,5>::RemoveIndex(this: &this->playerLayers, index: v7);
        }
LABEL_13:
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v9, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_ToRemove, obj: &v9, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_ToRemove, obj: &v9);
        idStr::FreeData(this: &v9);
        idStr::FreeData(this: v10);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$493898
// EA  : 0x82B601A8
// RVA : 0x00B601A8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493898()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$493899
// EA  : 0x82B601D0
// RVA : 0x00B601D0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_493899()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?AddActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B60200
// RVA : 0x00B60200
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::AddActiveLayer(idGameLayerManager *this, const char *layerName)
{
  char v4; // r27
  int v5; // r29
  int v6; // r28
  idLayer *v7; // r11
  idStr *v8; // r3
  idLayer *v9; // r29
  idList<idStr,5> *p_layers_DeactiveToActive; // r30
  idLayer v11; // [sp+50h] [-100h] BYREF
  idStr v12; // [sp+80h] [-D0h] BYREF
  idStr v13; // [sp+A0h] [-B0h] BYREF
  idLayer v14; // [sp+C0h] [-90h] BYREF
  idStr v15[3]; // [sp+F0h] [-60h] BYREF

  idStr::idStr(this: &v12, text: layerName);
  idStr::ToLower(this: &v12);
  v4 = 0;
  v5 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v6 = 0;
    while ( idStr::Icmp(s1: v12.data, s2: this->playerLayers.list[v6].layerDeclName.data) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->playerLayers.num )
        goto LABEL_9;
    }
    v4 = 1;
    v7 = &this->playerLayers.list[v5];
    if ( v7->layerState == LAYERSTATE_ACTIVE )
      idLib::Warning(fmt: "idLayer SetState for %s, already %d", v7->layerDeclName.data, 1);
    else
      v7->layerState = LAYERSTATE_ACTIVE;
  }
LABEL_9:
  if ( v4 == 0 )
  {
    v8 = idStr::idStr(this: v15, text: layerName);
    v9 = idLayer::idLayer(this: &v14, declName: v8, layerState_: LAYERSTATE_ACTIVE);
    v11.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
    idStr::idStr(this: &v11.layerDeclName, text: &v9->layerDeclName);
    v11.layerState = v9->layerState;
    idStr::FreeData(this: &v14.layerDeclName);
    v14.__vftable = (idLayer_vtbl *)&idClass::`vftable';
    idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v11);
    idStr::FreeData(this: &v11.layerDeclName);
    v11.__vftable = (idLayer_vtbl *)&idClass::`vftable';
  }
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::idStr(this: &v13, text: layerName);
  p_layers_DeactiveToActive = &this->layers_DeactiveToActive;
  if ( idList<idStr,5>::FindIndex(this: p_layers_DeactiveToActive, obj: &v13, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: p_layers_DeactiveToActive, obj: &v13);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v12);
}


// ========================================================================
// __unwind$494001
// EA  : 0x82B60384
// RVA : 0x00B60384
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494001()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$494003
// EA  : 0x82B603AC
// RVA : 0x00B603AC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494003()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$494057_0
// EA  : 0x82B603D4
// RVA : 0x00B603D4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494057_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$494004
// EA  : 0x82B603FC
// RVA : 0x00B603FC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494004()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$494068
// EA  : 0x82B60424
// RVA : 0x00B60424
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494068()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$494083
// EA  : 0x82B6044C
// RVA : 0x00B6044C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494083()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$494005
// EA  : 0x82B60474
// RVA : 0x00B60474
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494005()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// ?AddDeactiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B604A8
// RVA : 0x00B604A8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::AddDeactiveLayer(idGameLayerManager *this, const char *layerName)
{
  char v4; // r27
  int v5; // r29
  int v6; // r28
  idLayer *v7; // r11
  idStr *v8; // r3
  idLayer *v9; // r29
  idLayer v10; // [sp+50h] [-E0h] BYREF
  idStr v11; // [sp+80h] [-B0h] BYREF
  idLayer v12; // [sp+A0h] [-90h] BYREF
  idStr v13[3]; // [sp+D0h] [-60h] BYREF

  idStr::idStr(this: &v11, text: layerName);
  idStr::ToLower(this: &v11);
  v4 = 0;
  v5 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v6 = 0;
    while ( idStr::Icmp(s1: v11.data, s2: this->playerLayers.list[v6].layerDeclName.data) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->playerLayers.num )
        goto LABEL_9;
    }
    v4 = 1;
    v7 = &this->playerLayers.list[v5];
    if ( v7->layerState != LAYERSTATE_DEACTIVE )
      v7->layerState = LAYERSTATE_DEACTIVE;
    else
      idLib::Warning(fmt: "idLayer SetState for %s, already %d", v7->layerDeclName.data, 0);
  }
LABEL_9:
  if ( v4 == 0 )
  {
    v8 = idStr::idStr(this: v13, text: layerName);
    v9 = idLayer::idLayer(this: &v12, declName: v8, layerState_: LAYERSTATE_DEACTIVE);
    v10.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
    idStr::idStr(this: &v10.layerDeclName, text: &v9->layerDeclName);
    v10.layerState = v9->layerState;
    idStr::FreeData(this: &v12.layerDeclName);
    v12.__vftable = (idLayer_vtbl *)&idClass::`vftable';
    idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v10);
    idStr::FreeData(this: &v10.layerDeclName);
    v10.__vftable = (idLayer_vtbl *)&idClass::`vftable';
  }
  idGameLayerManager::RemoveLayerFromTransientLists(this, layerName);
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$494162
// EA  : 0x82B605F4
// RVA : 0x00B605F4
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494162()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$494164
// EA  : 0x82B6061C
// RVA : 0x00B6061C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494164()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$494217_1
// EA  : 0x82B60644
// RVA : 0x00B60644
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494217_1()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$494165
// EA  : 0x82B6066C
// RVA : 0x00B6066C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494165()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$494228_0
// EA  : 0x82B60694
// RVA : 0x00B60694
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494228_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$494243
// EA  : 0x82B606BC
// RVA : 0x00B606BC
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494243()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 304 + 80));
}


// ========================================================================
// ?GetLayerStrings@idGameLayerManager@@QAAXAAVidStr@@0_N@Z
// EA  : 0x82B606F0
// RVA : 0x00B606F0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::GetLayerStrings(
        idGameLayerManager *this,
        idStr *activeLayerString,
        idStr *deactiveLayerString,
        int propagateTheNextMapLayers,
        void (__fastcall **a5)(idPhysics_StaticMulti *__hidden this, int),
        int layerState,
        __int64 a7)
{
  char v10; // r26
  int v11; // r23
  int v12; // r25
  char v13; // r27
  int v14; // r29
  int v15; // r30
  idLayer *v16; // r11
  idStr *list; // r11
  idStr *v18; // r30
  int len; // r27
  int v20; // r29
  char *v21; // r10
  char *v22; // r9
  char v23; // r11
  char *v24; // r10
  char *v25; // r9
  char v26; // r11
  int v27; // r30
  char *v28; // r10
  char *v29; // r9
  char v30; // r11
  idStr *v31; // r3
  int v32; // r23
  int v33; // r25
  char v34; // r27
  int v35; // r29
  int v36; // r30
  idLayer *v37; // r11
  idStr *v38; // r30
  int v39; // r27
  int v40; // r29
  char *v41; // r10
  char *v42; // r9
  char v43; // r11
  char *v44; // r10
  char *v45; // r9
  char v46; // r11
  int v47; // r30
  char *v48; // r10
  char *v49; // r9
  char v50; // r11
  idStr *v51; // r27
  int size; // r30
  idStr *v53; // r29
  idLayer *v54; // r4
  unsigned int num; // r5
  int allocedAndFlag; // r11
  char v57; // r27
  char *data; // r11
  char *v59; // r11
  int v60; // r29
  int v61; // r30
  const idStr *Name; // r3
  const idStr *v63; // r3
  idSort_Quick<idLayer,idSort_GameLayer> v64; // [sp+50h] [-1E0h] BYREF
  idStr v65; // [sp+60h] [-1D0h] BYREF
  idLayer *v66; // [sp+80h] [-1B0h]
  void **v67; // [sp+90h] [-1A0h]
  idStr v68; // [sp+94h] [-19Ch] BYREF
  idLayer::layerState_t v69; // [sp+B4h] [-17Ch]
  void **v70; // [sp+C0h] [-170h]
  idStr v71; // [sp+C4h] [-16Ch] BYREF
  idLayer::layerState_t v72; // [sp+E4h] [-14Ch]
  idLayer v73; // [sp+F0h] [-140h] BYREF
  idLayer v74; // [sp+120h] [-110h] BYREF
  idLayer v75[5]; // [sp+150h] [-E0h] BYREF

  v10 = 0;
  if ( (_BYTE)propagateTheNextMapLayers != 0 )
  {
    propagateTheNextMapLayers = this->layers_ToMarkActiveNextMapLoad.num;
    LODWORD(a7) = &off_82040000;
    HIDWORD(a7) = 0x82000000;
    layerState = 0x82000000;
    a5 = &off_822B0000;
    v11 = 0;
    if ( propagateTheNextMapLayers > 0 )
    {
      v12 = 0;
      do
      {
        v13 = 0;
        v14 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v15 = 0;
          while ( idStr::Icmp(
                    s1: this->layers_ToMarkActiveNextMapLoad.list[v12].data,
                    s2: this->playerLayers.list[v15].layerDeclName.data) != 0 )
          {
            ++v14;
            ++v15;
            if ( v14 >= this->playerLayers.num )
              goto LABEL_13;
          }
          idLib::Warning(
            fmt: "layers_ToMarkActiveNextMapLoad already found in list with status: %s, %d",
            this->layers_ToMarkActiveNextMapLoad.list[v12].data,
            this->playerLayers.list[v14].layerState);
          v16 = &this->playerLayers.list[v14];
          layerState = v16->layerState;
          if ( layerState == 1 )
            idLib::Warning(fmt: "idLayer SetState for %s, already %d", v16->layerDeclName.data, 1);
          else
            v16->layerState = LAYERSTATE_ACTIVE;
          v13 = 1;
        }
LABEL_13:
        if ( v13 == 0 )
        {
          v65.len = 0;
          v65.data = v65.baseBuffer;
          list = this->layers_ToMarkActiveNextMapLoad.list;
          v65.baseBuffer[0] = 0;
          v18 = &list[v12];
          v65.allocedAndFlag = 20;
          len = list[v12].len;
          v20 = len + 1;
          if ( len + 1 > 20 )
            idStr::ReAllocate(this: &v65, amount: v18->len + 1, keepold: true);
          v21 = v18->data - 1;
          v22 = v65.data - 1;
          do
          {
            v23 = *++v21;
            *++v22 = *v21;
          }
          while ( v23 != 0 );
          v65.len = len;
          v66 = (idLayer *)&v65;
          v70 = &idLayer::`vftable';
          v71.len = 0;
          v71.data = v71.baseBuffer;
          v71.baseBuffer[0] = 0;
          v71.allocedAndFlag = 20;
          if ( v20 > 20 )
            idStr::ReAllocate(this: &v71, amount: v20, keepold: true);
          v24 = v65.data - 1;
          v25 = v71.data - 1;
          do
          {
            v26 = *++v24;
            *++v25 = *v24;
          }
          while ( v26 != 0 );
          v71.len = len;
          v72 = LAYERSTATE_ACTIVE;
          idStr::FreeData(this: &v65);
          v74.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
          v74.layerDeclName.len = 0;
          v27 = v71.len;
          v74.layerDeclName.data = v74.layerDeclName.baseBuffer;
          v74.layerDeclName.baseBuffer[0] = 0;
          v74.layerDeclName.allocedAndFlag = 20;
          if ( v71.len + 1 > 20 )
            idStr::ReAllocate(this: &v74.layerDeclName, amount: v71.len + 1, keepold: true);
          v28 = v71.data - 1;
          v29 = v74.layerDeclName.data - 1;
          do
          {
            v30 = *++v28;
            *++v29 = *v28;
          }
          while ( v30 != 0 );
          v74.layerDeclName.len = v27;
          v74.layerState = v72;
          idStr::FreeData(this: &v71);
          v70 = &idClass::`vftable';
          idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v74);
          idStr::FreeData(this: &v74.layerDeclName);
          v74.__vftable = (idLayer_vtbl *)&idClass::`vftable';
        }
        ++v11;
        ++v12;
      }
      while ( v11 < this->layers_ToMarkActiveNextMapLoad.num );
    }
    if ( this->layers_ToMarkActiveNextMapLoad.listStatic == 0 || this->layers_ToMarkActiveNextMapLoad.listStatic == 2 )
    {
      v31 = this->layers_ToMarkActiveNextMapLoad.list;
      if ( v31 != nullptr )
        idListArrayDelete<idStr>(ptr: v31, num: this->layers_ToMarkActiveNextMapLoad.size);
      this->layers_ToMarkActiveNextMapLoad.list = nullptr;
      this->layers_ToMarkActiveNextMapLoad.size = 0;
    }
    this->layers_ToMarkActiveNextMapLoad.num = 0;
    v32 = 0;
    if ( this->layers_ToMarkDeactiveNextMapLoad.num > 0 )
    {
      v33 = 0;
      do
      {
        v34 = 0;
        v35 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v36 = 0;
          while ( idStr::Icmp(
                    s1: this->layers_ToMarkDeactiveNextMapLoad.list[v33].data,
                    s2: this->playerLayers.list[v36].layerDeclName.data) != 0 )
          {
            ++v35;
            ++v36;
            if ( v35 >= this->playerLayers.num )
              goto LABEL_44;
          }
          idLib::Warning(
            fmt: "layers_ToMarkDeactiveNextMapLoad already found in list with status: %s, %d",
            this->layers_ToMarkDeactiveNextMapLoad.list[v33].data,
            this->playerLayers.list[v35].layerState);
          v37 = &this->playerLayers.list[v35];
          layerState = v37->layerState;
          if ( layerState != 0 )
            v37->layerState = LAYERSTATE_DEACTIVE;
          else
            idLib::Warning(fmt: "idLayer SetState for %s, already %d", v37->layerDeclName.data, 0);
          v34 = 1;
        }
LABEL_44:
        if ( v34 == 0 )
        {
          v38 = &this->layers_ToMarkDeactiveNextMapLoad.list[v33];
          v65.data = v65.baseBuffer;
          v65.baseBuffer[0] = 0;
          v65.len = 0;
          v65.allocedAndFlag = 20;
          v39 = v38->len;
          v40 = v38->len + 1;
          if ( v40 > 20 )
            idStr::ReAllocate(this: &v65, amount: v38->len + 1, keepold: true);
          v41 = v38->data - 1;
          v42 = v65.data - 1;
          do
          {
            v43 = *++v41;
            *++v42 = *v41;
          }
          while ( v43 != 0 );
          v65.len = v39;
          v66 = (idLayer *)&v65;
          v67 = &idLayer::`vftable';
          v68.len = 0;
          v68.data = v68.baseBuffer;
          v68.baseBuffer[0] = 0;
          v68.allocedAndFlag = 20;
          if ( v40 > 20 )
            idStr::ReAllocate(this: &v68, amount: v40, keepold: true);
          v44 = v65.data - 1;
          v45 = v68.data - 1;
          do
          {
            v46 = *++v44;
            *++v45 = *v44;
          }
          while ( v46 != 0 );
          v68.len = v39;
          v69 = LAYERSTATE_DEACTIVE;
          idStr::FreeData(this: &v65);
          v73.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
          v73.layerDeclName.len = 0;
          v47 = v68.len;
          v73.layerDeclName.data = v73.layerDeclName.baseBuffer;
          v73.layerDeclName.baseBuffer[0] = 0;
          v73.layerDeclName.allocedAndFlag = 20;
          if ( v68.len + 1 > 20 )
            idStr::ReAllocate(this: &v73.layerDeclName, amount: v68.len + 1, keepold: true);
          v48 = v68.data - 1;
          v49 = v73.layerDeclName.data - 1;
          do
          {
            v50 = *++v48;
            *++v49 = *v48;
          }
          while ( v50 != 0 );
          v73.layerDeclName.len = v47;
          v73.layerState = v69;
          idStr::FreeData(this: &v68);
          v67 = &idClass::`vftable';
          idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v73);
          idStr::FreeData(this: &v73.layerDeclName);
          v73.__vftable = (idLayer_vtbl *)&idClass::`vftable';
        }
        ++v32;
        ++v33;
      }
      while ( v32 < this->layers_ToMarkDeactiveNextMapLoad.num );
    }
    if ( this->layers_ToMarkDeactiveNextMapLoad.listStatic == 0
      || this->layers_ToMarkDeactiveNextMapLoad.listStatic == 2 )
    {
      v51 = this->layers_ToMarkDeactiveNextMapLoad.list;
      if ( v51 != nullptr )
      {
        size = this->layers_ToMarkDeactiveNextMapLoad.size;
        if ( size > 0 )
        {
          v53 = this->layers_ToMarkDeactiveNextMapLoad.list;
          do
          {
            idStr::FreeData(this: v53);
            --size;
            ++v53;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v51, align: ALIGN_16);
      }
      this->layers_ToMarkDeactiveNextMapLoad.list = nullptr;
      this->layers_ToMarkDeactiveNextMapLoad.size = 0;
    }
    this->layers_ToMarkDeactiveNextMapLoad.num = 0;
  }
  v64.__vftable = (idSort_Quick<idLayer,idSort_GameLayer>_vtbl *)&idSort_GameLayer::`vftable';
  v54 = this->playerLayers.list;
  if ( v54 != nullptr )
  {
    num = this->playerLayers.num;
    v66 = this->playerLayers.list;
    idSort_Quick<idLayer,idSort_GameLayer>::Sort(
      this: &v64,
      base: v54,
      num,
      a4: (unsigned __int8)propagateTheNextMapLayers,
      (int)a5,
      a6: layerState,
      a7);
  }
  allocedAndFlag = activeLayerString->allocedAndFlag;
  v64.__vftable = (idSort_Quick<idLayer,idSort_GameLayer>_vtbl *)&idSort<idLayer>::`vftable';
  v57 = 0;
  if ( allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: activeLayerString);
    activeLayerString->allocedAndFlag = 20;
    activeLayerString->data = activeLayerString->baseBuffer;
    activeLayerString->len = 0;
    activeLayerString->baseBuffer[0] = 0;
  }
  else
  {
    data = activeLayerString->data;
    activeLayerString->len = 0;
    *data = 0;
  }
  if ( deactiveLayerString->allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: deactiveLayerString);
    deactiveLayerString->allocedAndFlag = 20;
    deactiveLayerString->data = deactiveLayerString->baseBuffer;
    deactiveLayerString->len = 0;
    deactiveLayerString->baseBuffer[0] = 0;
  }
  else
  {
    v59 = deactiveLayerString->data;
    deactiveLayerString->len = 0;
    *v59 = 0;
  }
  v60 = 0;
  if ( this->playerLayers.num > 0 )
  {
    v61 = 0;
    do
    {
      if ( this->playerLayers.list[v61].layerState == LAYERSTATE_ACTIVE )
      {
        if ( v10 != 0 )
          idStr::Append(this: activeLayerString, text: ",");
        Name = idLayer::GetName(
                 this: (idLayer *)&v75[0].layerDeclName.baseBuffer[16],
                 result: (idStr *)&this->playerLayers.list[v61]);
        idStr::Append(this: activeLayerString, text: Name);
        idStr::FreeData(this: (idStr *)&v75[0].layerDeclName.baseBuffer[16]);
        v10 = 1;
      }
      else
      {
        if ( v57 != 0 )
          idStr::Append(this: deactiveLayerString, text: ",");
        v63 = idLayer::GetName(this: v75, result: (idStr *)&this->playerLayers.list[v61]);
        idStr::Append(this: deactiveLayerString, text: v63);
        idStr::FreeData(this: (idStr *)v75);
        v57 = 1;
      }
      ++v60;
      ++v61;
    }
    while ( v60 < this->playerLayers.num );
  }
}


// ========================================================================
// __unwind$494462
// EA  : 0x82B60FD8
// RVA : 0x00B60FD8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494462()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$494463
// EA  : 0x82B61000
// RVA : 0x00B61000
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494463()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 192));
}


// ========================================================================
// __unwind$494312_0
// EA  : 0x82B61028
// RVA : 0x00B61028
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494312_0()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 560 + 192));
}


// ========================================================================
// __unwind$494569
// EA  : 0x82B61050
// RVA : 0x00B61050
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494569()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 288));
}


// ========================================================================
// __unwind$494313_0
// EA  : 0x82B61078
// RVA : 0x00B61078
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494313_0()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 560 + 288));
}


// ========================================================================
// __unwind$494671
// EA  : 0x82B610A0
// RVA : 0x00B610A0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494671()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 192));
}


// ========================================================================
// __unwind$494686
// EA  : 0x82B610C8
// RVA : 0x00B610C8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494686()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 288));
}


// ========================================================================
// __unwind$494849
// EA  : 0x82B610F0
// RVA : 0x00B610F0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494849()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$494850
// EA  : 0x82B61118
// RVA : 0x00B61118
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494850()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 144));
}


// ========================================================================
// __unwind$494315_0
// EA  : 0x82B61140
// RVA : 0x00B61140
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494315_0()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 560 + 144));
}


// ========================================================================
// __unwind$494956
// EA  : 0x82B61168
// RVA : 0x00B61168
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494956()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$494316_0
// EA  : 0x82B61190
// RVA : 0x00B61190
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494316_0()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$495058
// EA  : 0x82B611B8
// RVA : 0x00B611B8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495058()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 144));
}


// ========================================================================
// __unwind$495073
// EA  : 0x82B611E0
// RVA : 0x00B611E0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495073()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$494317_0
// EA  : 0x82B61208
// RVA : 0x00B61208
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494317_0()
{
  int v0; // r12

  idSort_GameLayer::~idSort_GameLayer(this: (idSort_GameLayer *)(v0 - 560 + 80));
}


// ========================================================================
// __unwind$494318_0
// EA  : 0x82B61230
// RVA : 0x00B61230
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494318_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 368));
}


// ========================================================================
// __unwind$494319_0
// EA  : 0x82B61258
// RVA : 0x00B61258
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_494319_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 560 + 336));
}


// ========================================================================
// ?Init@idGameLayerManager@@QAAXPAVidPlayer@@_N@Z
// EA  : 0x82B61280
// RVA : 0x00B61280
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::Init(idGameLayerManager *this, idPlayer *player, bool firstLoad)
{
  idGameLocal *v5; // r11
  int v6; // r28
  idStaticList<idStrStatic<128>,256> *p_layersActive; // r30
  int v8; // r31
  idStrStatic<128> *v9; // r11
  int v10; // r28
  idStaticList<idStrStatic<128>,256> *p_layersDeactive; // r30
  int v12; // r31
  idStrStatic<128> *v13; // r11
  idStr *list; // r29
  int size; // r31
  idStr *v16; // r30
  idStr *v17; // r29
  int v18; // r31
  idStr *v19; // r30
  idStr *v20; // r29
  int v21; // r31
  idStr *v22; // r30
  idStr *v23; // r29
  int v24; // r31
  idStr *v25; // r30

  this->owner = player;
  if ( com_production.valueInteger == 0 )
    gameLocal->GetGameFlags(this: gameLocal);
  if ( firstLoad )
  {
    if ( g_debugLayers.valueInteger != 0 )
      idLib::Printf(fmt: "idGameLayerManager::Init: adding layers\n");
    v5 = gameLocal;
    v6 = 0;
    p_layersActive = &gameLocal->gameSpawnInfo.layersActive;
    if ( gameLocal->gameSpawnInfo.layersActive.num > 0 )
    {
      v8 = 0;
      do
      {
        v9 = &p_layersActive->list[v8];
        if ( v9->len != 0 )
        {
          idLib::Printf(fmt: "idGameLayerManager::Init: add active layer  %s\n", v9->data);
          idGameLayerManager::AddActiveLayer(this, layerName: p_layersActive->list[v8].data);
        }
        ++v6;
        ++v8;
      }
      while ( v6 < p_layersActive->num );
      v5 = gameLocal;
    }
    v10 = 0;
    p_layersDeactive = &v5->gameSpawnInfo.layersDeactive;
    if ( p_layersDeactive->num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = &p_layersDeactive->list[v12];
        if ( v13->len != 0 )
        {
          idLib::Printf(fmt: "idGameLayerManager::Init: add deactive layer  %s\n", v13->data);
          idGameLayerManager::AddDeactiveLayer(this, layerName: p_layersDeactive->list[v12].data);
        }
        ++v10;
        ++v12;
      }
      while ( v10 < p_layersDeactive->num );
    }
  }
  if ( this->layers_DeactiveToActive.listStatic == 0 || this->layers_DeactiveToActive.listStatic == 2 )
  {
    list = this->layers_DeactiveToActive.list;
    if ( list != nullptr )
    {
      size = this->layers_DeactiveToActive.size;
      if ( size > 0 )
      {
        v16 = this->layers_DeactiveToActive.list;
        do
        {
          idStr::FreeData(this: v16);
          --size;
          ++v16;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->layers_DeactiveToActive.list = nullptr;
    this->layers_DeactiveToActive.size = 0;
  }
  this->layers_DeactiveToActive.num = 0;
  if ( this->layers_ActiveToDeactivate.listStatic == 0 || this->layers_ActiveToDeactivate.listStatic == 2 )
  {
    v17 = this->layers_ActiveToDeactivate.list;
    if ( v17 != nullptr )
    {
      v18 = this->layers_ActiveToDeactivate.size;
      if ( v18 > 0 )
      {
        v19 = this->layers_ActiveToDeactivate.list;
        do
        {
          idStr::FreeData(this: v19);
          --v18;
          ++v19;
        }
        while ( v18 != 0 );
      }
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    }
    this->layers_ActiveToDeactivate.list = nullptr;
    this->layers_ActiveToDeactivate.size = 0;
  }
  this->layers_ActiveToDeactivate.num = 0;
  if ( this->layers_ToRemove.listStatic == 0 || this->layers_ToRemove.listStatic == 2 )
  {
    v20 = this->layers_ToRemove.list;
    if ( v20 != nullptr )
    {
      v21 = this->layers_ToRemove.size;
      if ( v21 > 0 )
      {
        v22 = this->layers_ToRemove.list;
        do
        {
          idStr::FreeData(this: v22);
          --v21;
          ++v22;
        }
        while ( v21 != 0 );
      }
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
    }
    this->layers_ToRemove.list = nullptr;
    this->layers_ToRemove.size = 0;
  }
  this->layers_ToRemove.num = 0;
  if ( this->layers_ToRemoveFromGameLocalLists.listStatic == 0
    || this->layers_ToRemoveFromGameLocalLists.listStatic == 2 )
  {
    v23 = this->layers_ToRemoveFromGameLocalLists.list;
    if ( v23 != nullptr )
    {
      v24 = this->layers_ToRemoveFromGameLocalLists.size;
      if ( v24 > 0 )
      {
        v25 = this->layers_ToRemoveFromGameLocalLists.list;
        do
        {
          idStr::FreeData(this: v25);
          --v24;
          ++v25;
        }
        while ( v24 != 0 );
      }
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    }
    this->layers_ToRemoveFromGameLocalLists.list = nullptr;
    this->layers_ToRemoveFromGameLocalLists.size = 0;
  }
  this->layers_ToRemoveFromGameLocalLists.num = 0;
}


// ========================================================================
// ?Think@idGameLayerManager@@QAAXXZ
// EA  : 0x82B616E0
// RVA : 0x00B616E0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::Think(idGameLayerManager *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  bool v4; // [sp+50h] [-40h] BYREF
  bool v5; // [sp+51h] [-3Fh] BYREF
  idPLogScope v6[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idGameLayerManager::Think");
  LODWORD(v2) = "idGameLayerManager::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v2, label: v3);
  if ( this->layers_DeactiveToActive.num > 0 )
  {
    v4 = false;
    v5 = false;
    idGameLocal::SpawnEntitiesForLayers(
      this: gameLocal,
      inSpawnLayers: &this->layers_DeactiveToActive,
      initialMapLoad: &v5,
      spawnAllLayers: &v4);
    idList<idStr,99>::~idList<idStr,99>(this: &this->layers_DeactiveToActive);
  }
  if ( this->layers_ActiveToDeactivate.num > 0 )
  {
    idGameLocal::RemoveEntitiesForLayers(
      this: gameLocal,
      inLayerList: &this->layers_ActiveToDeactivate,
      allowNonActiveLayers: false);
    idGameLocal::MoveLayersFromActiveToDeactiveLists(this: gameLocal, layerList: &this->layers_ActiveToDeactivate);
    idList<idStr,99>::~idList<idStr,99>(this: &this->layers_ActiveToDeactivate);
  }
  if ( this->layers_ToRemove.num > 0 )
  {
    idGameLocal::RemoveEntitiesForLayers(
      this: gameLocal,
      inLayerList: &this->layers_ToRemove,
      allowNonActiveLayers: false);
    idGameLocal::RemoveLayersFromActiveLayerList(this: gameLocal, layerList: &this->layers_ToRemove);
    idList<idStr,99>::~idList<idStr,99>(this: &this->layers_ToRemove);
  }
  if ( this->layers_ToRemoveFromGameLocalLists.num > 0 )
  {
    idGameLocal::RemoveLayersFromLayerLists(this: gameLocal, layerList: &this->layers_ToRemoveFromGameLocalLists);
    idList<idStr,99>::~idList<idStr,99>(this: &this->layers_ToRemoveFromGameLocalLists);
  }
  idPLogScope::~idPLogScope(this: v6);
  RD_EventEnd();
}


// ========================================================================
// __unwind$495808
// EA  : 0x82B617F8
// RVA : 0x00B617F8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495808()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$495809
// EA  : 0x82B61820
// RVA : 0x00B61820
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495809()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?AddActiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B61850
// RVA : 0x00B61850
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::AddActiveLayers(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r14
  int v5; // r21
  const char *str; // r25
  char v7; // r28
  int v8; // r30
  int v9; // r29
  idLayer *v10; // r11
  idStr *v11; // r30
  int len; // r29
  int v13; // r4
  char *v14; // r10
  char *v15; // r9
  char v16; // r11
  int v17; // r30
  char *v18; // r10
  char *v19; // r9
  char v20; // r11
  idStr v21; // [sp+54h] [-15Ch] BYREF
  idLayer::layerState_t v22; // [sp+74h] [-13Ch]
  idLayer v23; // [sp+80h] [-130h] BYREF
  idStr *v24; // [sp+A8h] [-108h]
  idStr v25; // [sp+B0h] [-100h] BYREF
  idStr v26; // [sp+D0h] [-E0h] BYREF
  idStr v27[6]; // [sp+F0h] [-C0h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::AddActiveLayers\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: &v25, text: str);
        idStr::ToLower(this: &v25);
        v7 = 0;
        v8 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v9 = 0;
          while ( idStr::Icmp(s1: v25.data, s2: this->playerLayers.list[v9].layerDeclName.data) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->playerLayers.num )
              goto LABEL_15;
          }
          v7 = 1;
          v10 = &this->playerLayers.list[v8];
          if ( v10->layerState == LAYERSTATE_ACTIVE )
            idLib::Warning(fmt: "idLayer SetState for %s, already %d", v10->layerDeclName.data, 1);
          else
            v10->layerState = LAYERSTATE_ACTIVE;
        }
LABEL_15:
        if ( v7 == 0 )
        {
          v11 = idStr::idStr(this: v27, text: str);
          v24 = v11;
          v21.len = 0;
          v21.data = v21.baseBuffer;
          v21.baseBuffer[0] = 0;
          v21.allocedAndFlag = 20;
          len = v11->len;
          v13 = v11->len + 1;
          if ( v13 > 20 )
            idStr::ReAllocate(this: &v21, amount: v13, keepold: true);
          v14 = v11->data - 1;
          v15 = v21.data - 1;
          do
          {
            v16 = *++v14;
            *++v15 = *v14;
          }
          while ( v16 != 0 );
          v21.len = len;
          v22 = LAYERSTATE_ACTIVE;
          idStr::FreeData(this: v11);
          v23.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
          v23.layerDeclName.len = 0;
          v17 = v21.len;
          v23.layerDeclName.data = v23.layerDeclName.baseBuffer;
          v23.layerDeclName.baseBuffer[0] = 0;
          v23.layerDeclName.allocedAndFlag = 20;
          if ( v21.len + 1 > 20 )
            idStr::ReAllocate(this: &v23.layerDeclName, amount: v21.len + 1, keepold: true);
          v18 = v21.data - 1;
          v19 = v23.layerDeclName.data - 1;
          do
          {
            v20 = *++v18;
            *++v19 = *v18;
          }
          while ( v20 != 0 );
          v23.layerDeclName.len = v17;
          v23.layerState = v22;
          idStr::FreeData(this: &v21);
          idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v23);
          idStr::FreeData(this: &v23.layerDeclName);
          v23.__vftable = (idLayer_vtbl *)&idClass::`vftable';
        }
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::idStr(this: &v26, text: str);
        if ( idList<idStr,5>::FindIndex(this: &this->layers_DeactiveToActive, obj: &v26, startIndex: 0) < 0 )
          idList<idStr,5>::Append(this: &this->layers_DeactiveToActive, obj: &v26);
        idStr::FreeData(this: &v26);
        idStr::FreeData(this: &v25);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$495888
// EA  : 0x82B61BB8
// RVA : 0x00B61BB8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495888()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$495944
// EA  : 0x82B61BE0
// RVA : 0x00B61BE0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495944()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 432 + 168));
}


// ========================================================================
// __unwind$495945
// EA  : 0x82B61C08
// RVA : 0x00B61C08
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495945()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$495890
// EA  : 0x82B61C30
// RVA : 0x00B61C30
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495890()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$496051
// EA  : 0x82B61C58
// RVA : 0x00B61C58
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496051()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 432 + 128));
}


// ========================================================================
// __unwind$495891
// EA  : 0x82B61C80
// RVA : 0x00B61C80
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495891()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 432 + 128));
}


// ========================================================================
// __unwind$496153
// EA  : 0x82B61CA8
// RVA : 0x00B61CA8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496153()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$496168
// EA  : 0x82B61CD0
// RVA : 0x00B61CD0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496168()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 432 + 128));
}


// ========================================================================
// __unwind$495892
// EA  : 0x82B61CF8
// RVA : 0x00B61CF8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_495892()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 208));
}


// ========================================================================
// ?AddDeactiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA  : 0x82B61D28
// RVA : 0x00B61D28
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::AddDeactiveLayers(
        idGameLayerManager *this,
        const idList<idDeclLayer const *,5> *layerlist)
{
  int v4; // r15
  int v5; // r22
  const char *str; // r25
  char v7; // r28
  int v8; // r30
  int v9; // r29
  idLayer *v10; // r11
  idStr *v11; // r30
  int len; // r29
  int v13; // r4
  char *v14; // r10
  char *v15; // r9
  char v16; // r11
  int v17; // r30
  char *v18; // r10
  char *v19; // r9
  char v20; // r11
  idStr v21; // [sp+54h] [-12Ch] BYREF
  idLayer::layerState_t v22; // [sp+74h] [-10Ch]
  idLayer v23; // [sp+80h] [-100h] BYREF
  idStr *v24; // [sp+A8h] [-D8h]
  idStr v25; // [sp+B0h] [-D0h] BYREF
  idStr v26[5]; // [sp+D0h] [-B0h] BYREF

  if ( g_debugLayers.valueInteger != 0 )
    idLib::Printf(fmt: "idGameLayerManager::AddDeactiveLayers\n");
  v4 = 0;
  if ( layerlist->num > 0 )
  {
    v5 = 0;
    do
    {
      if ( layerlist->list[v5] != nullptr )
      {
        str = layerlist->list[v5]->name.str;
        idStr::idStr(this: &v25, text: str);
        idStr::ToLower(this: &v25);
        v7 = 0;
        v8 = 0;
        if ( this->playerLayers.num > 0 )
        {
          v9 = 0;
          while ( idStr::Icmp(s1: v25.data, s2: this->playerLayers.list[v9].layerDeclName.data) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->playerLayers.num )
              goto LABEL_15;
          }
          v7 = 1;
          v10 = &this->playerLayers.list[v8];
          if ( v10->layerState != LAYERSTATE_DEACTIVE )
            v10->layerState = LAYERSTATE_DEACTIVE;
          else
            idLib::Warning(fmt: "idLayer SetState for %s, already %d", v10->layerDeclName.data, 0);
        }
LABEL_15:
        if ( v7 == 0 )
        {
          v11 = idStr::idStr(this: v26, text: str);
          v24 = v11;
          v21.len = 0;
          v21.data = v21.baseBuffer;
          v21.baseBuffer[0] = 0;
          v21.allocedAndFlag = 20;
          len = v11->len;
          v13 = v11->len + 1;
          if ( v13 > 20 )
            idStr::ReAllocate(this: &v21, amount: v13, keepold: true);
          v14 = v11->data - 1;
          v15 = v21.data - 1;
          do
          {
            v16 = *++v14;
            *++v15 = *v14;
          }
          while ( v16 != 0 );
          v21.len = len;
          v22 = LAYERSTATE_DEACTIVE;
          idStr::FreeData(this: v11);
          v23.__vftable = (idLayer_vtbl *)&idLayer::`vftable';
          v23.layerDeclName.len = 0;
          v17 = v21.len;
          v23.layerDeclName.data = v23.layerDeclName.baseBuffer;
          v23.layerDeclName.baseBuffer[0] = 0;
          v23.layerDeclName.allocedAndFlag = 20;
          if ( v21.len + 1 > 20 )
            idStr::ReAllocate(this: &v23.layerDeclName, amount: v21.len + 1, keepold: true);
          v18 = v21.data - 1;
          v19 = v23.layerDeclName.data - 1;
          do
          {
            v20 = *++v18;
            *++v19 = *v18;
          }
          while ( v20 != 0 );
          v23.layerDeclName.len = v17;
          v23.layerState = v22;
          idStr::FreeData(this: &v21);
          idList<idLayer,5>::Append(this: &this->playerLayers, obj: &v23);
          idStr::FreeData(this: &v23.layerDeclName);
          v23.__vftable = (idLayer_vtbl *)&idClass::`vftable';
        }
        idGameLayerManager::RemoveLayerFromTransientLists(this, layerName: str);
        idStr::FreeData(this: &v25);
      }
      else
      {
        idLib::Warning(fmt: "NULL layerDecl");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < layerlist->num );
  }
}


// ========================================================================
// __unwind$496408
// EA  : 0x82B62050
// RVA : 0x00B62050
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 176));
}


// ========================================================================
// __unwind$496463
// EA  : 0x82B62078
// RVA : 0x00B62078
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496463()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 384 + 168));
}


// ========================================================================
// __unwind$496464
// EA  : 0x82B620A0
// RVA : 0x00B620A0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496464()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$496410
// EA  : 0x82B620C8
// RVA : 0x00B620C8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496410()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$496570
// EA  : 0x82B620F0
// RVA : 0x00B620F0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496570()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$496411
// EA  : 0x82B62118
// RVA : 0x00B62118
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496411()
{
  int v0; // r12

  idRaceStatusMemory::~idRaceStatusMemory(this: (idLayer *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$496672
// EA  : 0x82B62140
// RVA : 0x00B62140
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496672()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$496687
// EA  : 0x82B62168
// RVA : 0x00B62168
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496687()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 384 + 128));
}


// ========================================================================
// ?ReadFromFile@idGameLayerManager@@QAAXPAVidFile@@@Z
// EA  : 0x82B623D0
// RVA : 0x00B623D0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::ReadFromFile(idGameLayerManager *this, idFile *file)
{
  idFile_vtbl *v4; // r11
  int v5; // r4
  __int64 v6; // r29
  char v7; // r3
  int size; // r11
  int v9; // r26
  int v10; // r27
  idLayer *v11; // r28
  int v12; // r4
  int v13; // r28
  bool v14; // r3
  int v15; // r11
  int v16; // r27
  int v17; // r28
  int v18; // r4
  int v19; // r28
  bool v20; // r3
  int v21; // r11
  int v22; // r27
  int v23; // r28
  int v24; // r24
  idList<idRetainedItemMemoryForMap,5> *p_retainedItemMemoryForMap; // r23
  int i; // r28
  int v27; // [sp+50h] [-110h] BYREF
  int v28; // [sp+54h] [-10Ch] BYREF
  int v29; // [sp+58h] [-108h] BYREF
  int v30; // [sp+5Ch] [-104h] BYREF
  int v31; // [sp+60h] [-100h] BYREF
  int v32[3]; // [sp+64h] [-FCh] BYREF
  idRetainedItemMemoryForMap v33; // [sp+70h] [-F0h] BYREF
  idStr v34; // [sp+B0h] [-B0h] BYREF
  idEntityRetainedState v35[2]; // [sp+D0h] [-90h] BYREF

  idGameLayerManager::ClearLayers(this);
  LODWORD(v6) = 0;
  v4 = file->__vftable;
  v28 = 0;
  v4->Read(this: file, a2: &v28, a3: 4u);
  v5 = v28;
  HIDWORD(v6) = v28;
  if ( v28 <= this->playerLayers.size
    || (v7 = idList<idLayer,5>::Resize(this: &this->playerLayers, newsize: v28), v5 = v28, v7 != 0) )
  {
    size = this->playerLayers.size;
    if ( SHIDWORD(v6) < size )
      size = HIDWORD(v6);
    this->playerLayers.num = size;
  }
  v9 = 0;
  if ( v5 > 0 )
  {
    v10 = 0;
    do
    {
      v11 = &this->playerLayers.list[v10];
      idFile::ReadString(this: file, string: &v11->layerDeclName);
      file->Read(this: file, a2: &v11->layerState, a3: 4u);
      idLib::Printf(fmt: "Read Layer From File %d %s\n", v11->layerState, v11->layerDeclName.data);
      ++v9;
      ++v10;
    }
    while ( v9 < v28 );
  }
  v27 = 0;
  file->Read(this: file, a2: &v27, a3: 4u);
  v12 = v27;
  v13 = v27;
  if ( v27 <= this->layers_ToMarkActiveNextMapLoad.size
    || (v14 = idList<idStr,3>::Resize(this: &this->layers_ToMarkActiveNextMapLoad, newsize: v27), v12 = v27, v14) )
  {
    v15 = this->layers_ToMarkActiveNextMapLoad.size;
    if ( v13 < v15 )
      v15 = v13;
    this->layers_ToMarkActiveNextMapLoad.num = v15;
  }
  v16 = 0;
  if ( v12 > 0 )
  {
    v17 = 0;
    do
    {
      idFile::ReadString(this: file, string: &this->layers_ToMarkActiveNextMapLoad.list[v17]);
      ++v16;
      ++v17;
    }
    while ( v16 < v27 );
  }
  v29 = 0;
  file->Read(this: file, a2: &v29, a3: 4u);
  v18 = v29;
  v19 = v29;
  if ( v29 <= this->layers_ToMarkDeactiveNextMapLoad.size
    || (v20 = idList<idStr,3>::Resize(this: &this->layers_ToMarkDeactiveNextMapLoad, newsize: v29), v18 = v29, v20) )
  {
    v21 = this->layers_ToMarkDeactiveNextMapLoad.size;
    if ( v19 < v21 )
      v21 = v19;
    this->layers_ToMarkDeactiveNextMapLoad.num = v21;
  }
  v22 = 0;
  if ( v18 > 0 )
  {
    v23 = 0;
    do
    {
      idFile::ReadString(this: file, string: &this->layers_ToMarkDeactiveNextMapLoad.list[v23]);
      ++v22;
      ++v23;
    }
    while ( v22 < v29 );
  }
  v32[0] = 0;
  file->Read(this: file, a2: v32, a3: 4u);
  HIDWORD(v6) = 0;
  if ( v32[0] > 0 )
  {
    do
    {
      idStr::idStr(this: &v35[0].entityName, text: &byte_8200D768);
      v35[0].state = -1;
      v35[0].targetState = -1;
      v35[0].timeStarted = v6;
      v35[0].entity = nullptr;
      idFile::ReadString(this: file, string: &v35[0].entityName);
      file->Read(this: file, a2: &v35[0].state, a3: 4u);
      file->Read(this: file, a2: &v35[0].targetState, a3: 4u);
      file->Read(this: file, a2: &v35[0].timeStarted, a3: 8u);
      idList<idEntityRetainedState,5>::Append(this: &this->entityRetainedStates, obj: v35);
      idStr::FreeData(this: &v35[0].entityName);
      ++HIDWORD(v6);
    }
    while ( SHIDWORD(v6) < v32[0] );
  }
  v31 = 0;
  file->Read(this: file, a2: &v31, a3: 4u);
  v24 = 0;
  if ( v31 > 0 )
  {
    p_retainedItemMemoryForMap = &this->retainedItemMemoryForMap;
    do
    {
      v33.__vftable = (idRetainedItemMemoryForMap_vtbl *)&idRetainedItemMemoryForMap::`vftable';
      v33.mapName.data = v33.mapName.baseBuffer;
      v33.mapName.len = 0;
      v33.mapName.baseBuffer[0] = 0;
      v33.mapName.allocedAndFlag = 20;
      v33.itemsList.memTag = 5;
      v33.itemsList.listStatic = 0;
      memset(&v33.itemsList, 0, 14);
      idFile::ReadString(this: file, string: &v33.mapName);
      v30 = 0;
      file->Read(this: file, a2: &v30, a3: 4u);
      for ( i = 0; i < v30; ++i )
      {
        v34.allocedAndFlag = 20;
        v34.len = 0;
        v34.data = v34.baseBuffer;
        v34.baseBuffer[0] = 0;
        idFile::ReadString(this: file, string: &v34);
        idList<idStr,5>::Append(this: &v33.itemsList, obj: &v34);
        idStr::FreeData(this: &v34);
      }
      idList<idRetainedItemMemoryForMap,5>::Append(this: p_retainedItemMemoryForMap, obj: &v33);
      idRetainedItemMemoryForMap::~idRetainedItemMemoryForMap(this: &v33);
      ++v24;
    }
    while ( v24 < v31 );
  }
}


// ========================================================================
// __unwind$496931
// EA  : 0x82B627F8
// RVA : 0x00B627F8
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 208));
}


// ========================================================================
// __unwind$497127
// EA  : 0x82B62820
// RVA : 0x00B62820
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_497127()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: (idAimAssist *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$497128
// EA  : 0x82B62848
// RVA : 0x00B62848
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_497128()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 116));
}


// ========================================================================
// __unwind$496932
// EA  : 0x82B62874
// RVA : 0x00B62874
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496932()
{
  int v0; // r12

  idRetainedItemMemoryForMap::~idRetainedItemMemoryForMap(this: (idRetainedItemMemoryForMap *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$496933
// EA  : 0x82B6289C
// RVA : 0x00B6289C
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_496933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 176));
}


// ========================================================================
// ?AddItemMemory@idGameLayerManager@@QAAXPBD@Z
// EA  : 0x82B628D0
// RVA : 0x00B628D0
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void __fastcall idGameLayerManager::AddItemMemory(idGameLayerManager *this, const char *itemName)
{
  const char *v3; // r3
  int v4; // r28
  int v5; // r29
  int len; // r29
  idStr v7; // [sp+50h] [-A0h] BYREF
  idStr v8; // [sp+70h] [-80h] BYREF
  idRetainedItemMemoryForMap v9; // [sp+90h] [-60h] BYREF

  if ( gameLocal != nullptr )
  {
    idStr::idStr(this: &v8, text: itemName);
    v3 = gameLocal->GetMapName(this: gameLocal);
    idStr::idStr(this: &v7, text: v3);
    v4 = 0;
    if ( this->retainedItemMemoryForMap.num <= 0 )
    {
LABEL_6:
      idRetainedItemMemoryForMap::idRetainedItemMemoryForMap(this: &v9);
      len = v7.len;
      idStr::EnsureAlloced(this: &v9.mapName, amount: v7.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v9.mapName.data, Src: v7.data, Size: len);
      v9.mapName.data[len] = 0;
      v9.mapName.len = len;
      idList<idStr,5>::Append(this: &v9.itemsList, obj: &v8);
      idList<idRetainedItemMemoryForMap,5>::Append(this: &this->retainedItemMemoryForMap, obj: &v9);
      idRetainedItemMemoryForMap::~idRetainedItemMemoryForMap(this: &v9);
      idStr::FreeData(this: &v7);
      idStr::FreeData(this: &v8);
    }
    else
    {
      v5 = 0;
      while ( idStr::Icmp(s1: v7.data, s2: this->retainedItemMemoryForMap.list[v5].mapName.data) != 0 )
      {
        ++v4;
        ++v5;
        if ( v4 >= this->retainedItemMemoryForMap.num )
          goto LABEL_6;
      }
      idList<idStr,5>::Append(this: &this->retainedItemMemoryForMap.list[v4].itemsList, obj: &v8);
      idStr::FreeData(this: &v7);
      idStr::FreeData(this: &v8);
    }
  }
  else
  {
    idLib::Warning(fmt: "AddItemMemory %s, encountered failure", itemName);
  }
}


// ========================================================================
// __unwind$497350
// EA  : 0x82B62A18
// RVA : 0x00B62A18
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_497350()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$497351
// EA  : 0x82B62A40
// RVA : 0x00B62A40
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_497351()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$497352
// EA  : 0x82B62A68
// RVA : 0x00B62A68
// PDB : w:\tech5\tungsten\game\clientgame\gamelayermanager.cpp
// ========================================================================

void _unwind_497352()
{
  int v0; // r12

  idRetainedItemMemoryForMap::~idRetainedItemMemoryForMap(this: (idRetainedItemMemoryForMap *)(v0 - 240 + 144));
}

