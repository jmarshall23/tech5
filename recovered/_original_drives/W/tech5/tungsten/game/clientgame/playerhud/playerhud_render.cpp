
// ========================================================================
// ?NoteSwfForBuildGame@idPlayerHud_Render@@SAXXZ
// EA  : 0x82B64118
// RVA : 0x00B64118
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

static void __fastcall idPlayerHud_Render::NoteSwfForBuildGame()
{
  idSWF::RegisterSWFResources(filename: "tunghud");
}


// ========================================================================
// ??0idPlayerHud_Render@@QAA@XZ
// EA  : 0x82B64128
// RVA : 0x00B64128
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

idPlayerHud_Render *__fastcall idPlayerHud_Render::idPlayerHud_Render(idPlayerHud_Render *this)
{
  this->hud = nullptr;
  this->playerNum = -1;
  this->__vftable = (idPlayerHud_Render_vtbl *)&idPlayerHud_Render::`vftable';
  this->showScoreboard = false;
  this->minigameResult = -1;
  return this;
}


// ========================================================================
// ?IsPlayerControlInhibited@idPlayerHud_Render@@QAA_NXZ
// EA  : 0x82B64150
// RVA : 0x00B64150
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

int __fastcall idPlayerHud_Render::IsPlayerControlInhibited(idPlayerHud_Render *this)
{
  if ( this->hud == nullptr )
    return 0;
  if ( common->IsMainMenuActive(this: common) )
    return 1;
  return idSWF::IsPlayerControlInhibited(this: this->hud);
}


// ========================================================================
// ?Cleanup@idPlayerHud_Render@@QAAXXZ
// EA  : 0x82B641E0
// RVA : 0x00B641E0
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::Cleanup(idPlayerHud_Render *this)
{
  idSWF *hud; // r3

  hud = this->hud;
  if ( hud != nullptr )
    idSWF::ClearEmitter(this: hud, instant: true);
}


// ========================================================================
// ?HandleGuiEvent@idPlayerHud_Render@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82B641F8
// RVA : 0x00B641F8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

idSWF *__fastcall idPlayerHud_Render::HandleGuiEvent(idPlayerHud_Render *this, const sysEvent_t *ev)
{
  idSWF *result; // r3

  result = this->hud;
  if ( result != nullptr )
    return (idSWF *)idSWF::HandleEvent(this: result, event: ev);
  return result;
}


// ========================================================================
// ?SetPlayerNum@idPlayerHud_Render@@QAAXH@Z
// EA  : 0x82B64210
// RVA : 0x00B64210
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::SetPlayerNum(idPlayerHud_Render *this, int p)
{
  this->playerNum = p;
  idSWF::SetListener(this: this->hud, id: p + 1);
}


// ========================================================================
// ?Init@idPlayerHud_Render@@QAAXPBVidStr@@@Z
// EA  : 0x82B64228
// RVA : 0x00B64228
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::Init(idPlayerHud_Render *this, const idStr *mapName)
{
  idSWF *v3; // r3

  v3 = (idSWF *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x27Cu,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    this->hud = idSWF::idSWF(this: v3, filename_: "tunghud", soundWorld: clientGame->soundWorld, atlasPurgable_: false);
  else
    this->hud = nullptr;
}


// ========================================================================
// __unwind$487712
// EA  : 0x82B642BC
// RVA : 0x00B642BC
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall _unwind_487712(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ??1idPlayerHud_Render@@UAA@XZ
// EA  : 0x82B642E8
// RVA : 0x00B642E8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::~idPlayerHud_Render(idPlayerHud_Render *this)
{
  idSWF *hud; // r31

  hud = this->hud;
  this->__vftable = (idPlayerHud_Render_vtbl *)&idPlayerHud_Render::`vftable';
  if ( hud != nullptr )
  {
    idSWF::~idSWF(this: hud);
    idMem::Free(this: &mem, ptr: hud, align: ALIGN_16);
  }
}


// ========================================================================
// ?SetIconMaterial@idPlayerHud_Render@@AAAXPBDPBVidMaterial@@@Z
// EA  : 0x82B643C0
// RVA : 0x00B643C0
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::SetIconMaterial(idPlayerHud_Render *this, char *name, const idMaterial *material)
{
  idSWFSpriteInstance *v5; // r30
  long double v6; // fp2
  unsigned __int16 Width; // r11
  idMaterial *materialOverride; // r3
  long double v9; // fp2
  idSWFScriptVar v10; // [sp+50h] [-30h] BYREF
  idSWFScriptVar v11[5]; // [sp+58h] [-28h] BYREF

  idSWF::GetGlobal(this: (idSWF *)v11, result: (idSWFScriptVar *)this->hud, name: "_root");
  if ( v11[0].type == SWF_VAR_OBJECT )
  {
    idSWFScriptObject::Get(this: (idSWFScriptObject *)&v10, result: v11[0].value.object, name);
    if ( v10.type == SWF_VAR_OBJECT )
    {
      v5 = idSWFScriptVar::ToSprite(this: &v10);
      v5->materialOverride = material;
      if ( material != nullptr )
      {
        Width = idMaterial::GetWidth(this: material, a2: v6);
        materialOverride = v5->materialOverride;
        v5->materialWidth = Width;
        v5->materialHeight = idMaterial::GetHeight(this: materialOverride, a2: v9);
      }
    }
    idSWFScriptVar::Free(this: &v10);
  }
  idSWFScriptVar::Free(this: v11);
}


// ========================================================================
// __unwind$487964
// EA  : 0x82B64460
// RVA : 0x00B64460
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_487964()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$487965
// EA  : 0x82B64488
// RVA : 0x00B64488
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_487965()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?Render@idPlayerHud_Render@@QAAXPAVidRenderModelGui@@AAVidHudInfo@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA  : 0x82B644B8
// RVA : 0x00B644B8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __fastcall idPlayerHud_Render::Render(
        idPlayerHud_Render *this,
        idRenderModelGui *guiModel,
        idHudInfo *current,
        int currentTime,
        const renderView_t *renderView,
        const idRenderWorld *rw)
{
  char v8; // r30
  idSWFScriptVar::swfScriptVarValue_t *v9; // r26
  idSWFScriptVar *list; // r28
  int size; // r27
  int v12; // r9
  char **v13; // r23
  int v14; // r24
  idSWFScriptVar *v15; // r29
  int i; // r30
  bool *v17; // r29
  idSWFScriptVar::swfScriptVarValue_t **v18; // r28
  int j; // r30
  int v20; // r11
  idSWFScriptObject *v21; // r3
  int v22; // r11
  int v23; // r27
  idSWFScriptObject *object; // r23
  char **v25; // r26
  idMaterial **v26; // r28
  idSWFSpriteInstance *v27; // r3
  long double v28; // fp2
  idSWFSpriteInstance *v29; // r30
  long double v30; // fp2
  int v31; // r11
  idSWFScriptVar *v32; // r29
  int k; // r30
  idSWFScriptVar *v34; // r29
  int v35; // r30
  idSWFScriptVar *v36; // r28
  idSWFScriptVar *v37; // r29
  int v38; // r30
  idSWFScriptVar *v39; // r28
  idSWFScriptVar *v40; // r29
  int v41; // r30
  idSWFScriptVar *v42; // r28
  idSWFScriptVar *v43; // r29
  int v44; // r30
  idSWFScriptVar *v45; // r28
  idSWFScriptVar *v46; // r29
  int v47; // r30
  idSWFScriptVar *v48; // r28
  int iconIndex; // r11
  BOOL v50; // r4
  char v51; // r11
  int m; // r30
  const idMaterial *buttonImage; // r5
  int v54; // r29
  int n; // r30
  int itemCount; // r4
  const idMaterial *material; // r5
  const idMaterial *v58; // r5
  const idMaterial *v59; // r5
  idSWFScriptVar *v60; // r29
  int v61; // r30
  idSWFScriptVar *v62; // r28
  int action; // r11
  idSWFScriptVar *v64; // r29
  int v65; // r30
  idSWFScriptVar *v66; // r28
  const char *v67; // r4
  idSWFScriptVar *v68; // r29
  int v69; // r30
  idSWFScriptVar *v70; // r28
  idSWFScriptVar *Global; // r3
  idSWFScriptVar *v72; // r3
  __int64 v73; // r10
  int v74; // r8
  int v75; // r7
  int v76; // r6
  int v77; // r5
  int v78; // r4
  idSWFScriptVar *v79; // r3
  idStaticList<idSWFScriptVar,16> v80; // [sp+60h] [-1D0h] BYREF
  idSWFScriptVar v81; // [sp+F0h] [-140h] BYREF
  int *v82; // [sp+F8h] [-138h]
  idSWFScriptVar::swfScriptVarValue_t *v83; // [sp+FCh] [-134h]
  int v84; // [sp+100h] [-130h]
  idSWFScriptVar v85; // [sp+108h] [-128h] BYREF
  const char *v86; // [sp+110h] [-120h]
  idSWFScriptVar v87; // [sp+118h] [-118h] BYREF
  idSWFScriptVar v88; // [sp+120h] [-110h] BYREF
  idSWFScriptObject v89; // [sp+128h] [-108h] BYREF
  idSWFScriptVar v90; // [sp+188h] [-A8h] BYREF
  idSWFScriptVar v91[20]; // [sp+190h] [-A0h] BYREF

  if ( this->hud == nullptr )
    return;
  if ( g_showHud.valueInteger == 0 )
    return;
  v8 = idSaveGameManager::GotWork(this: session->saveGameManager);
  if ( gameLocal->GetGamePaused(this: gameLocal) && v8 == 0 )
    return;
  idSWF::Activate(this: this->hud, b: true);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v80);
  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v80);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->showBottomBar);
  idSWF::Invoke(this: this->hud, functionName: "UpdateBottomBar", parms: (const idSWFParmList *)&v80);
  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v80);
  v81.value.i = (int)current->healthIndicator.health;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)v81.value.i);
  v81.value.i = (int)current->healthIndicator.armor;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)v81.value.i);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->damageLocator.direction.x);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->damageLocator.direction.y);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->damageLocator.intensity);
  idSWF::Invoke(this: this->hud, functionName: "UpdateHealthAndArmor", parms: (const idSWFParmList *)&v80);
  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v80);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[0].show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[1].show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[0].staticCounter);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[0].nextAnimState);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[0].ammoClipCount);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)(current->weaponAmmoStatus[0].ammoTotalCount
                                          - current->weaponAmmoStatus[0].ammoClipCount));
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[0].burstMode);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[1].ammoClipCount);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)(current->weaponAmmoStatus[1].ammoTotalCount
                                          - current->weaponAmmoStatus[1].ammoClipCount));
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[1].burstMode);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[0].dwAvailable);
  idSWF::Invoke(this: this->hud, functionName: "UpdateAmmoGroupRight", parms: (const idSWFParmList *)&v80);
  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v80);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[2].show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[3].show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->weaponAmmoStatus[2].staticCounter);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[2].nextAnimState);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[2].ammoClipCount);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[2].burstMode);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[3].ammoClipCount);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->weaponAmmoStatus[3].burstMode);
  idSWF::Invoke(this: this->hud, functionName: "UpdateAmmoGroupLeft", parms: (const idSWFParmList *)&v80);
  v9 = nullptr;
  current->weaponAmmoStatus[0].renderReceipt = true;
  current->weaponAmmoStatus[1].renderReceipt = true;
  current->weaponAmmoStatus[2].renderReceipt = true;
  current->weaponAmmoStatus[3].renderReceipt = true;
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    if ( v80.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v80.list, num: v80.size);
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: v8);
  idSWF::Invoke(this: this->hud, functionName: "UpdateSaving", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic != 0 && v80.listStatic != 2 )
  {
    size = v80.size;
    list = v80.list;
  }
  else
  {
    if ( v80.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v80.list, num: v80.size);
    list = nullptr;
    v80.list = nullptr;
    size = 0;
    v80.size = 0;
  }
  v12 = current->combiners.size;
  v80.num = 0;
  v83 = nullptr;
  v86 = "_root";
  if ( v12 > 0 )
  {
    v84 = 0;
    v82 = &v89.variablesHash[5];
    v13 = (char **)&v89.variablesHash[5];
    v14 = 0;
    v89.variables.num = (int)"UpdateCombinerHide";
    v89.variablesHash[1] = (int)"UpdateCombinerCombine";
    do
    {
      if ( v80.listStatic == 0 || v80.listStatic == 2 )
      {
        if ( list != nullptr )
        {
          if ( size > 0 )
          {
            v15 = list;
            for ( i = size; i != 0; --i )
              idSWFScriptVar::Free(this: v15++);
          }
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        }
        v80.list = nullptr;
        v80.size = 0;
      }
      v80.num = 0;
      idSWFParmList::Append(this: (idSWFParmList *)&v80, i: v9);
      if ( (int)v9 >= current->combiners.num )
      {
        idSWF::Invoke(
          this: this->hud,
          functionName: (const char *)v89.variables.num,
          parms: (const idSWFParmList *)&v80);
      }
      else
      {
        v17 = &current->combiners.list->hovered + v14;
        idSWFParmList::Append(this: (idSWFParmList *)&v80, b: *v17);
        idSWFParmList::Append(this: (idSWFParmList *)&v80, i: *((idSWFScriptVar::swfScriptVarValue_t **)v17 + 1));
        v18 = (idSWFScriptVar::swfScriptVarValue_t **)(v17 + 8);
        for ( j = 5; j != 0; --j )
          idSWFParmList::Append(this: (idSWFParmList *)&v80, i: *++v18);
        idSWF::Invoke(
          this: this->hud,
          functionName: (const char *)v89.variablesHash[1],
          parms: (const idSWFParmList *)&v80);
        v20 = *((_DWORD *)v17 + 1);
        if ( v20 >= 1 && v20 <= 5 )
        {
          idSWF::GetGlobal(this: (idSWF *)&v87, result: (idSWFScriptVar *)this->hud, name: v86);
          v81.type = SWF_VAR_UNDEF;
          if ( v87.type == SWF_VAR_OBJECT )
          {
            v89.variablesHash[5] = (int)"_combiner1";
            v89.variablesHash[6] = (int)"_combiner2";
            v89.variablesHash[7] = (int)"_combiner3";
            v21 = idSWFScriptObject::Get(
                    this: (idSWFScriptObject *)&v89.variablesHash[15],
                    result: v87.value.object,
                    name: *v13);
            idSWFScriptVar::operator=(this: &v81, other: (const idSWFScriptVar *)v21);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v89.variablesHash[15]);
            if ( v81.type == SWF_VAR_OBJECT )
            {
              v22 = *((_DWORD *)v17 + 1);
              v23 = 0;
              v89.variablesHash[9] = (int)"item1";
              v89.variablesHash[10] = (int)"item2";
              v89.variablesHash[11] = (int)"item3";
              v89.variablesHash[12] = (int)"item4";
              v89.variablesHash[13] = (int)"item5";
              if ( v22 > 0 )
              {
                object = v81.value.object;
                v25 = (char **)&v89.variablesHash[9];
                v26 = (idMaterial **)(v17 + 32);
                do
                {
                  if ( v23 >= 5 )
                    break;
                  idSWFScriptObject::Get(
                    this: (idSWFScriptObject *)&v89.variables.granularity,
                    result: object,
                    name: *v25);
                  if ( *(_DWORD *)&v89.variables.granularity == 8 )
                  {
                    idSWFScriptObject::Get(
                      this: (idSWFScriptObject *)&v89.variablesHash[3],
                      result: (idSWFScriptObject *)v89.variablesHash[0],
                      name: "icon");
                    v27 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v89.variablesHash[3]);
                    v29 = v27;
                    if ( v27 != nullptr && *((_DWORD *)v17 + 8) != 0 )
                    {
                      v27->materialOverride = *v26;
                      v27->materialWidth = idMaterial::GetWidth(this: *v26, a2: v28);
                      v29->materialHeight = idMaterial::GetHeight(this: *v26, a2: v30);
                      idSWFSpriteInstance::SetVisible(this: v29, visible: true);
                    }
                    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v89.variablesHash[3]);
                  }
                  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v89.variables.granularity);
                  ++v23;
                  ++v25;
                  ++v26;
                }
                while ( v23 < *((_DWORD *)v17 + 1) );
              }
            }
          }
          idSWFScriptVar::Free(this: &v81);
          idSWFScriptVar::Free(this: &v87);
          v9 = v83;
          v13 = (char **)v82;
          v14 = v84;
        }
      }
      v31 = current->combiners.size;
      v9 = (idSWFScriptVar::swfScriptVarValue_t *)((char *)v9 + 1);
      v14 += 52;
      size = v80.size;
      ++v13;
      list = v80.list;
      v83 = v9;
      v84 = v14;
      v82 = (int *)v13;
    }
    while ( (int)v9 < v31 );
  }
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    if ( list != nullptr )
    {
      if ( size > 0 )
      {
        v32 = list;
        for ( k = size; k != 0; --k )
          idSWFScriptVar::Free(this: v32++);
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v80.list = nullptr;
      v80.size = 0;
    }
    else
    {
      v80.list = nullptr;
      v80.size = 0;
    }
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->reticle.show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)current->reticle.pulsate);
  idSWF::Invoke(this: this->hud, functionName: "UpdateCrosshair", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v34 = v80.list;
    if ( v80.list != nullptr )
    {
      v35 = v80.size;
      v36 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v34);
          --v35;
          ++v34;
        }
        while ( v35 != 0 );
      }
      idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->airSupply.show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: (float)(current->airSupply.percent * (float)100.0));
  idSWF::Invoke(this: this->hud, functionName: "UpdateAirSupply", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v37 = v80.list;
    if ( v80.list != nullptr )
    {
      v38 = v80.size;
      v39 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v37);
          --v38;
          ++v37;
        }
        while ( v38 != 0 );
      }
      idMem::Free(this: &mem, ptr: v39, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)current->boss.numBars);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->boss.visibleBars);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->boss.amount);
  idSWF::Invoke(this: this->hud, functionName: "UpdateBoss", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v40 = v80.list;
    if ( v80.list != nullptr )
    {
      v41 = v80.size;
      v42 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v40);
          --v41;
          ++v40;
        }
        while ( v41 != 0 );
      }
      idMem::Free(this: &mem, ptr: v42, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterStatus.show);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->laserCutterStatus.charge);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterStatus.canShoot);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->laserCutterStatus.nextAnimState);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterStatus.cuttingMode);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterStatus.shootingFullAuto);
  idSWF::Invoke(this: this->hud, functionName: "UpdateLaserCutter", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v43 = v80.list;
    if ( v80.list != nullptr )
    {
      v44 = v80.size;
      v45 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v43);
          --v44;
          ++v43;
        }
        while ( v44 != 0 );
      }
      idMem::Free(this: &mem, ptr: v45, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterFuncLensStatus.showPrim);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterFuncLensStatus.showSec);
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->laserCutterFuncLensStatus.showStatic);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->laserCutterFuncLensStatus.nextAnimState);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->laserCutterFuncLensStatus.iconPrim);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->laserCutterFuncLensStatus.iconSec);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v80,
    i: (idSWFScriptVar::swfScriptVarValue_t *)current->laserCutterFuncLensStatus.iconStatic);
  idSWF::Invoke(this: this->hud, functionName: "UpdateFunctionalityLenses", parms: (const idSWFParmList *)&v80);
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v46 = v80.list;
    if ( v80.list != nullptr )
    {
      v47 = v80.size;
      v48 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v46);
          --v47;
          ++v46;
        }
        while ( v47 != 0 );
      }
      idMem::Free(this: &mem, ptr: v48, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  iconIndex = current->reticle.iconIndex;
  v80.num = 0;
  v50 = ++iconIndex != 0;
  if ( iconIndex != 0 || (v51 = 1, !current->help.show) )
    v51 = 0;
  if ( v51 != 0 )
  {
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, s: &byte_8200D768);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)0xFFFFFFFF);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: nullptr);
    for ( m = 2; m != 0; --m )
    {
      idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)0xFFFFFFFF);
      idSWFParmList::Append(this: (idSWFParmList *)&v80, i: nullptr);
    }
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: nullptr);
    idSWF::Invoke(this: this->hud, functionName: "UpdateInteraction", parms: (const idSWFParmList *)&v80);
    idPlayerHud_Render::SetIconMaterial(this, name: "_interaction_icon0", material: current->help.icon);
    buttonImage = current->help.buttonImage;
    if ( buttonImage != nullptr )
      idPlayerHud_Render::SetIconMaterial(this, name: "_interaction_usebutton", material: buttonImage);
  }
  else
  {
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)v50);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, s: &byte_8200D768);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, f: current->reticle.useAmount);
    v54 = 0;
    for ( n = 0; n < 3; ++n )
    {
      if ( current->interact.icons.num <= v54 )
      {
        idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)0xFFFFFFFF);
        itemCount = -1;
      }
      else
      {
        idSWFParmList::Append(
          this: (idSWFParmList *)&v80,
          i: (idSWFScriptVar::swfScriptVarValue_t *)current->interact.icons.list[n].usable);
        itemCount = current->interact.icons.list[n].itemCount;
      }
      idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)itemCount);
      ++v54;
    }
    idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->interact.useCheckbox);
    idSWF::Invoke(this: this->hud, functionName: "UpdateInteraction", parms: (const idSWFParmList *)&v80);
    if ( current->interact.icons.num <= 0 )
      material = nullptr;
    else
      material = current->interact.icons.list->material;
    idPlayerHud_Render::SetIconMaterial(this, name: "_interaction_icon0", material);
    if ( current->interact.icons.num <= 1 )
      v58 = nullptr;
    else
      v58 = current->interact.icons.list[1].material;
    idPlayerHud_Render::SetIconMaterial(this, name: "_interaction_icon1", material: v58);
    if ( current->interact.icons.num <= 2 )
      v59 = nullptr;
    else
      v59 = current->interact.icons.list[2].material;
    idPlayerHud_Render::SetIconMaterial(this, name: "_interaction_icon2", material: v59);
    idSWF::GetGlobal(this: (idSWF *)&v88, result: (idSWFScriptVar *)this->hud, name: v86);
    if ( v88.type == SWF_VAR_OBJECT )
    {
      idSWFScriptObject::Get(this: &v89, result: v88.value.object, name: "_interaction_usebutton");
      if ( v89.refCount == 8 )
        idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v89)->materialOverride = nullptr;
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v89);
    }
    idSWFScriptVar::Free(this: &v88);
  }
  if ( v80.listStatic == 0 || v80.listStatic == 2 )
  {
    v60 = v80.list;
    if ( v80.list != nullptr )
    {
      v61 = v80.size;
      v62 = v80.list;
      if ( v80.size > 0 )
      {
        do
        {
          idSWFScriptVar::Free(this: v60);
          --v61;
          ++v60;
        }
        while ( v61 != 0 );
      }
      idMem::Free(this: &mem, ptr: v62, align: ALIGN_16);
    }
    v80.list = nullptr;
    v80.size = 0;
  }
  v80.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->showJournalIcon);
  idSWF::Invoke(this: this->hud, functionName: "UpdateJobNotification", parms: (const idSWFParmList *)&v80);
  action = current->minigame.action;
  if ( action == 1 )
  {
    if ( v80.listStatic == 0 || v80.listStatic == 2 )
    {
      v64 = v80.list;
      if ( v80.list != nullptr )
      {
        v65 = v80.size;
        v66 = v80.list;
        if ( v80.size > 0 )
        {
          do
          {
            idSWFScriptVar::Free(this: v64);
            --v65;
            ++v64;
          }
          while ( v65 != 0 );
        }
        idMem::Free(this: &mem, ptr: v66, align: ALIGN_16);
      }
      v80.list = nullptr;
      v80.size = 0;
    }
    v80.num = 0;
    idSWFParmList::Append(this: (idSWFParmList *)&v80, i: (idSWFScriptVar::swfScriptVarValue_t *)current->minigame.type);
    idSWFParmList::Append(
      this: (idSWFParmList *)&v80,
      i: (idSWFScriptVar::swfScriptVarValue_t *)current->minigame.level);
    idSWFParmList::Append(this: (idSWFParmList *)&v80, b: current->minigame.showHelp);
    v85.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v85);
    v85.type = SWF_VAR_INTEGER;
    v85.value.i = -1;
    idSWFScriptObject::Set(this: this->hud->globals, name: "minigame_result", value: &v85);
    idSWFScriptVar::Free(this: &v85);
    v67 = "Minigame_Start";
LABEL_140:
    idSWF::Invoke(this: this->hud, functionName: v67, parms: (const idSWFParmList *)&v80);
    goto LABEL_141;
  }
  if ( action == 2 )
  {
    if ( v80.listStatic == 0 || v80.listStatic == 2 )
    {
      v68 = v80.list;
      if ( v80.list != nullptr )
      {
        v69 = v80.size;
        v70 = v80.list;
        if ( v80.size > 0 )
        {
          do
          {
            idSWFScriptVar::Free(this: v68);
            --v69;
            ++v68;
          }
          while ( v69 != 0 );
        }
        idMem::Free(this: &mem, ptr: v70, align: ALIGN_16);
      }
      v80.list = nullptr;
      v80.size = 0;
    }
    v80.num = 0;
    v67 = "Minigame_End";
    goto LABEL_140;
  }
LABEL_141:
  Global = (idSWFScriptVar *)idSWF::GetGlobal(
                               this: (idSWF *)&v90,
                               result: (idSWFScriptVar *)this->hud,
                               name: "minigame_result");
  this->minigameResult = idSWFScriptVar::ToInteger(this: Global);
  idSWFScriptVar::Free(this: &v90);
  v72 = (idSWFScriptVar *)idSWF::GetGlobal(
                            this: (idSWF *)&v89.objectType,
                            result: (idSWFScriptVar *)this->hud,
                            name: "minigame_rangeindicator");
  this->minigameRangeIndicator = idSWFScriptVar::ToFloat(
                                   this: v72,
                                   a2: v78,
                                   a3: v77,
                                   a4: v76,
                                   a5: v75,
                                   a6: v74,
                                   a7: v73);
  idSWFScriptVar::Free(this: (idSWFScriptVar *)&v89.objectType);
  v79 = (idSWFScriptVar *)idSWF::GetGlobal(
                            this: (idSWF *)v91,
                            result: (idSWFScriptVar *)this->hud,
                            name: "minigame_stage");
  this->minigameStage = idSWFScriptVar::ToInteger(this: v79);
  idSWFScriptVar::Free(this: v91);
  if ( !idMainMenu::IsActive(this: gameLocal->mainMenu) )
    idSWF::Render(this: this->hud, gui: guiModel, time: currentTime, isSplitscreen: false, a5: nullptr);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v80);
}


// ========================================================================
// __unwind$488138
// EA  : 0x82B653B8
// RVA : 0x00B653B8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488138()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 560 + 96));
}


// ========================================================================
// __unwind$488139
// EA  : 0x82B653E0
// RVA : 0x00B653E0
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488139()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 280));
}


// ========================================================================
// __unwind$488140
// EA  : 0x82B65408
// RVA : 0x00B65408
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488140()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 240));
}


// ========================================================================
// __unwind$488141
// EA  : 0x82B65430
// RVA : 0x00B65430
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488141()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 376));
}


// ========================================================================
// __unwind$488142_0
// EA  : 0x82B65458
// RVA : 0x00B65458
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488142_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 312));
}


// ========================================================================
// __unwind$488143
// EA  : 0x82B65480
// RVA : 0x00B65480
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488143()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 328));
}


// ========================================================================
// __unwind$488603
// EA  : 0x82B654A8
// RVA : 0x00B654A8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488603()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 288));
}


// ========================================================================
// __unwind$488604
// EA  : 0x82B654D0
// RVA : 0x00B654D0
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488604()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 296));
}


// ========================================================================
// __unwind$488144
// EA  : 0x82B654F8
// RVA : 0x00B654F8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488144()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 264));
}


// ========================================================================
// __unwind$488145
// EA  : 0x82B65520
// RVA : 0x00B65520
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488145()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 392));
}


// ========================================================================
// __unwind$488146_0
// EA  : 0x82B65548
// RVA : 0x00B65548
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488146_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 384));
}


// ========================================================================
// __unwind$488147
// EA  : 0x82B65570
// RVA : 0x00B65570
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void _unwind_488147()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 560 + 400));
}


// ========================================================================
// `dynamic initializer for 'g_drawTVSafe''
// EA  : 0x8336D738
// RVA : 0x0136D738
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawTVSafe__()
{
  idCVar::idCVar(
    this: &g_drawTVSafe,
    name: "g_drawTVSafe",
    value: "0",
    flags: 1,
    description: "draws a tv-save overlay on the HUD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawTVSafe__);
}


// ========================================================================
// `dynamic initializer for 'g_showAreaText''
// EA  : 0x8336D790
// RVA : 0x0136D790
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showAreaText__()
{
  idCVar::idCVar(
    this: &g_showAreaText,
    name: "g_showAreaText",
    value: "1",
    flags: 1,
    description: "if true we draw a text when entering an area",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showAreaText__);
}


// ========================================================================
// `dynamic initializer for 'g_showMiniMap''
// EA  : 0x8336D7E8
// RVA : 0x0136D7E8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showMiniMap__()
{
  idCVar::idCVar(
    this: &g_showMiniMap,
    name: "g_showMiniMap",
    value: "1",
    flags: 1,
    description: "if true we draw a minimap in the wasteland",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showMiniMap__);
}


// ========================================================================
// `dynamic initializer for 'gc_coop_results_tempHUD''
// EA  : 0x8336D840
// RVA : 0x0136D840
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_coop_results_tempHUD__()
{
  idCVar::idCVar(
    this: &gc_coop_results_tempHUD,
    name: "gc_coop_results_tempHUD",
    value: "1",
    flags: 1,
    description: "Draw temp hud for coop results",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_coop_results_tempHUD__);
}


// ========================================================================
// `dynamic initializer for 'g_useMPReferenceHUD''
// EA  : 0x8336D898
// RVA : 0x0136D898
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_useMPReferenceHUD__()
{
  idCVar::idCVar(
    this: &g_useMPReferenceHUD,
    name: "g_useMPReferenceHUD",
    value: "1",
    flags: 1,
    description: "Runs MP hud through reference path that skips as much SWF as possible",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_useMPReferenceHUD__);
}

