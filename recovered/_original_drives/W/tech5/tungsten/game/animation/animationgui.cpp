
// ========================================================================
// ??0idAnimationGUI@@QAA@XZ
// EA  : 0x82B2C680
// RVA : 0x00B2C680
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

idAnimationGUI *__fastcall idAnimationGUI::idAnimationGUI(idAnimationGUI *this)
{
  this->guiModel = nullptr;
  this->font = nullptr;
  this->font = (const idFont *)idResourceList::Load(
                                 this: &idFont::resourceList,
                                 name: "arial_black",
                                 makeDefault: true,
                                 skipStaleCheck: false);
  return this;
}


// ========================================================================
// ?GetAnimTime@@YAMPBVidMD6Leaf@@HH@Z
// EA  : 0x82B2C6D8
// RVA : 0x00B2C6D8
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

float __fastcall GetAnimTime(idMD6LeafPlay *leaf, int timeMSec, unsigned int ticksPerSec)
{
  const idMD6Anim *anim; // r11
  double v7; // fp30
  double v8; // fp31
  double v9; // fp1
  idMD6AnimData *animData; // r11
  int numFrames; // r29
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int FrameRate; // r3
  _BYTE v17[12]; // r11
  int v18; // r30
  int FrameTime; // r3
  unsigned int v20; // r5

  anim = leaf->anim;
  v7 = 0.0;
  v8 = 0.0;
  if ( anim != nullptr )
  {
    animData = anim->animData;
    numFrames = 0;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    FrameRate = idMD6Leaf::GetFrameRate(this: leaf);
    *(_DWORD *)&v17[8] = leaf->type;
    v18 = FrameRate;
    if ( *(_DWORD *)&v17[8] == 1 )
    {
      v8 = *(float *)&leaf[2].anim;
    }
    else if ( *(_DWORD *)&v17[8] == 2 )
    {
      FrameTime = idMD6LeafPlay::GetFrameTime(
                    this: leaf,
                    gameTime: timeMSec,
                    a3: v15,
                    a4: v14,
                    a5: v13,
                    a6: v12,
                    a7: *(__int64 *)v17);
      *(_DWORD *)v17 = FrameTime * v18 / ticksPerSec;
      __twllei(ticksPerSec, 0);
      __twllei(numFrames - 1, 0);
      if ( (int)(*(_DWORD *)v17 / (unsigned int)(numFrames - 1)) < 1 || leaf->wrapMode != 0 )
      {
        *(_QWORD *)v17 = __PAIR64__(ticksPerSec, v18);
        v8 = (float)((float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, ticksPerSec))
                           * (float)__SPAIR64__(v18, FrameTime))
                   * (float)__SPAIR64__(ticksPerSec, v18));
      }
      else
      {
        *(_DWORD *)&v17[4] = numFrames - 1;
        v8 = (float)*(__int64 *)v17;
      }
    }
    *(_DWORD *)&v17[4] = leaf->wrapMode;
    *(_DWORD *)&v17[8] = 0;
    if ( leaf->wrapMode != 0 )
    {
      if ( *(_DWORD *)&v17[4] == 1 )
      {
        *(_DWORD *)&v17[8] = (int)v8;
        *(_DWORD *)&v17[4] = (int)v8;
        v7 = (float)((float)v8 - (float)*(__int64 *)v17);
        if ( numFrames > 1 )
        {
          v20 = (numFrames - 1) & ~(__ROL4__(*(_DWORD *)&v17[8], 1) - 1);
          __twllei(numFrames - 1, 0);
          *(int *)&v17[8] %= numFrames - 1;
          __twlgei(v20, 0xFFFFFFFF);
        }
      }
    }
    else if ( v8 >= 0.0 )
    {
      *(_DWORD *)&v17[8] = numFrames;
      if ( v8 < (float)*(__int64 *)&v17[4] )
      {
        *(_DWORD *)&v17[8] = (int)v8;
        *(_DWORD *)&v17[4] = (int)v8;
        v7 = (float)((float)v8 - (float)*(__int64 *)v17);
      }
      else
      {
        *(_DWORD *)&v17[8] = numFrames - 1;
      }
    }
    else
    {
      *(_DWORD *)&v17[8] = 0;
    }
    *(_DWORD *)&v17[4] = byte_821B0000;
    v9 = (float)((float)((float)*(__int64 *)&v17[4] + (float)v7) * (float)0.033333335);
  }
  else
  {
    v9 = 0.0;
  }
  return *((float *)&v9 + 1);
}


// ========================================================================
// ?DrawAnimTree_r@idAnimationGUI@@AAAXAAVidStr@@AAVidGUIRect@@PBVidMD6Node@@@Z
// EA  : 0x82B2C900
// RVA : 0x00B2C900
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __fastcall idAnimationGUI::DrawAnimTree_r(
        idAnimationGUI *this,
        idStr *tabLvl,
        idGUIRect *rect,
        idMD6LeafPlay *treeNode)
{
  unsigned int type; // r11
  unsigned int v9; // r29
  int v10; // r3
  double v11; // fp1
  const idMD6Anim *v12; // r11
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  unsigned int v16; // r29
  int v17; // r3
  double AnimTime; // fp1
  const idMD6Anim *anim; // r11
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r10
  int v26; // [sp+8h] [-98h]
  int v27; // [sp+Ch] [-94h]
  int v28; // [sp+10h] [-90h]
  int v29; // [sp+14h] [-8Ch]
  int v30; // [sp+18h] [-88h]
  int v31; // [sp+1Ch] [-84h]
  int v32; // [sp+20h] [-80h]
  int v33; // [sp+24h] [-7Ch]
  double v34; // [sp+30h] [-70h]
  idStr v35[2]; // [sp+50h] [-50h] BYREF

  if ( treeNode != nullptr )
  {
    type = treeNode->type;
    if ( treeNode->type != 0 )
    {
      if ( type == 1 )
      {
        v16 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        AnimTime = GetAnimTime(leaf: treeNode, timeMSec: v17, ticksPerSec: v16);
        anim = treeNode->anim;
        LODWORD(v20) = &off_82010000;
        if ( anim != nullptr )
          LODWORD(v21) = anim->name.str;
        else
          LODWORD(v21) = &byte_8200D768;
        HIDWORD(v21) = LODWORD(AnimTime);
        LODWORD(v22) = tabLvl->data;
        HIDWORD(v22) = "%sLeafPause: (%.3f) %s";
        idGUIRect::Printf(
          this: rect,
          heading: &byte_8200D768,
          fmt: v22,
          a4: v21,
          a5: v20,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31,
          a12: v32,
          a13: v33);
      }
      else if ( type < 3 )
      {
        v9 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        v11 = GetAnimTime(leaf: treeNode, timeMSec: v10, ticksPerSec: v9);
        v12 = treeNode->anim;
        LODWORD(v13) = &off_82010000;
        if ( v12 != nullptr )
          LODWORD(v14) = v12->name.str;
        else
          LODWORD(v14) = &byte_8200D768;
        HIDWORD(v14) = LODWORD(v11);
        LODWORD(v15) = tabLvl->data;
        HIDWORD(v15) = "%sLeafPlay: (%.3f) %s";
        idGUIRect::Printf(
          this: rect,
          heading: &byte_8200D768,
          fmt: v15,
          a4: v14,
          a5: v13,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31,
          a12: v32,
          a13: v33);
      }
    }
    else
    {
      operator+(result: v35, a: tabLvl, b: "\t");
      v34 = *(float *)&treeNode[1].type;
      HIDWORD(v23) = LODWORD(v34);
      LODWORD(v24) = tabLvl->data;
      v25 = __PAIR64__(&off_82010000, __ROL4__(treeNode->syncEnabled, 2));
      HIDWORD(v24) = "%sBranch - blend: %.2f Op: %s";
      LODWORD(v23) = *(const char **)((char *)idMD6Blend::blendOpNames + v25);
      idGUIRect::Printf(
        this: rect,
        heading: &byte_8200D768,
        fmt: v24,
        a4: v23,
        a5: v25,
        a6: v26,
        a7: v27,
        a8: v28,
        a9: v29,
        a10: v30,
        a11: v31,
        a12: v32,
        a13: v33);
      idAnimationGUI::DrawAnimTree_r(this, tabLvl: v35, rect, treeNode: *(const idMD6Node **)&treeNode->weightGroup);
      idAnimationGUI::DrawAnimTree_r(this, tabLvl: v35, rect, treeNode: (const idMD6Node *)treeNode->anim);
      idStr::FreeData(this: v35);
    }
  }
}


// ========================================================================
// __unwind$488008_0
// EA  : 0x82B2CAD8
// RVA : 0x00B2CAD8
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488008_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?DrawDebugGUI@idAnimationGUI@@QAAPAVidRenderModelGui@@PAVidEntity@@@Z
// EA  : 0x82B2CB08
// RVA : 0x00B2CB08
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idRenderModelGui *__fastcall idAnimationGUI::DrawDebugGUI(idAnimationGUI *this, idAnimatedEntity *ent)
{
  idAnimatedEntity *v3; // r18
  char valueInteger; // r29
  idPlayer *v5; // r16
  int v6; // r7
  unsigned __int64 v7; // r6
  int v9; // r26
  idRenderModelGui *v10; // r3
  idRenderModelGui *v11; // r3
  unsigned int v12; // r30
  unsigned int v13; // r3
  int v14; // r3
  int v15; // r21
  int v16; // r20
  int v17; // r11
  int v18; // r20
  int v19; // r29
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r8 OVERLAPPED
  int v27; // r11
  int v28; // r30
  __int64 v29; // r10
  int v30; // r28
  __int64 v31; // r6
  idMD6LeafPlay *tree; // r29
  idPlayer *v33; // r3
  idPlayer *v34; // r30
  idPresentable *presentable; // r3
  int v36; // r3
  idPresentable *v37; // r11
  int v38; // r3
  __int64 v39; // r6
  __int64 v40; // r10
  int v41; // r8
  int v42; // r7
  const idMD6Model *v43; // r21
  unsigned int v44; // r16
  int GameMs; // r17
  int PreviousGameMs; // r3
  int v47; // r30
  __int64 v48; // r6
  __int64 v49; // r10
  __int64 v50; // r8
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  __int64 v54; // r10
  int v55; // r8
  int v56; // r7
  int v57; // r29
  float *p_z; // r30
  __int64 v59; // r8
  __int64 v60; // r10
  __int64 v61; // r6
  __int64 v62; // r6
  idBounds *v63; // [sp+8h] [-27C8h]
  int v64; // [sp+8h] [-27C8h]
  int v65; // [sp+8h] [-27C8h]
  int v66; // [sp+8h] [-27C8h]
  int v67; // [sp+8h] [-27C8h]
  idBounds *v68; // [sp+Ch] [-27C4h]
  int v69; // [sp+Ch] [-27C4h]
  int v70; // [sp+Ch] [-27C4h]
  int v71; // [sp+Ch] [-27C4h]
  int v72; // [sp+Ch] [-27C4h]
  md6OriginDelta_t *v73; // [sp+10h] [-27C0h]
  int v74; // [sp+10h] [-27C0h]
  int v75; // [sp+10h] [-27C0h]
  int v76; // [sp+10h] [-27C0h]
  int v77; // [sp+10h] [-27C0h]
  int v78; // [sp+14h] [-27BCh]
  int v79; // [sp+14h] [-27BCh]
  int v80; // [sp+14h] [-27BCh]
  int v81; // [sp+14h] [-27BCh]
  int v82; // [sp+14h] [-27BCh]
  int v83; // [sp+18h] [-27B8h]
  int v84; // [sp+18h] [-27B8h]
  int v85; // [sp+18h] [-27B8h]
  int v86; // [sp+18h] [-27B8h]
  int v87; // [sp+18h] [-27B8h]
  int v88; // [sp+1Ch] [-27B4h]
  int v89; // [sp+1Ch] [-27B4h]
  int v90; // [sp+1Ch] [-27B4h]
  int v91; // [sp+1Ch] [-27B4h]
  int v92; // [sp+1Ch] [-27B4h]
  int v93; // [sp+20h] [-27B0h]
  int v94; // [sp+20h] [-27B0h]
  int v95; // [sp+20h] [-27B0h]
  int v96; // [sp+20h] [-27B0h]
  int v97; // [sp+20h] [-27B0h]
  int v98; // [sp+24h] [-27ACh]
  int v99; // [sp+24h] [-27ACh]
  int v100; // [sp+24h] [-27ACh]
  int v101; // [sp+24h] [-27ACh]
  int v102; // [sp+24h] [-27ACh]
  int v103; // [sp+28h] [-27A8h]
  int v104; // [sp+2Ch] [-27A4h]
  double v105; // [sp+30h] [-27A0h]
  int v106; // [sp+38h] [-2798h]
  double v107; // [sp+38h] [-2798h]
  int v108; // [sp+3Ch] [-2794h]
  int v109; // [sp+40h] [-2790h]
  int v110; // [sp+44h] [-278Ch]
  int v111; // [sp+48h] [-2788h]
  int v112; // [sp+4Ch] [-2784h]
  int v113; // [sp+50h] [-2780h]
  int v114; // [sp+58h] [-2778h]
  int v115; // [sp+60h] [-2770h]
  int v116; // [sp+68h] [-2768h]
  char v117; // [sp+7Bh] [-2755h]
  idStr v118; // [sp+80h] [-2750h] BYREF
  idGUIRect v119; // [sp+A0h] [-2730h] BYREF
  idGUIRect v120; // [sp+130h] [-26A0h] BYREF
  idBounds v121; // [sp+1C0h] [-2610h] BYREF
  idBounds v122; // [sp+1E0h] [-25F0h] BYREF
  idBounds v123; // [sp+200h] [-25D0h] BYREF
  idDeviceContext v124; // [sp+220h] [-25B0h] BYREF
  md6AnimCommand_t v125[2]; // [sp+730h] [-20A0h] BYREF

  v3 = ent;
  valueInteger = animationGui_show.valueInteger;
  v117 = animationGui_show.valueInteger;
  if ( animationGui_show.valueInteger == 0 )
    return nullptr;
  if ( ent == nullptr )
    return nullptr;
  v5 = (idPlayer *)idAnimatedEntity::CastTo(c: ent);
  if ( v5 == nullptr )
    return nullptr;
  if ( this->font == nullptr )
  {
    idLib::Warning(fmt: "AnimWebGUI has an invalid font '%s'", animationGui_font.valueString.data);
    return nullptr;
  }
  if ( (animationGui_font.flags & 0x20000) != 0 )
  {
    animationGui_font.flags &= ~0x20000u;
    v9 = cvarSystem->GetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: 0);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: 0, a4: 0);
    this->font = (const idFont *)idResourceList::Load(
                                   this: &idFont::resourceList,
                                   name: animationGui_font.valueString.data,
                                   makeDefault: true,
                                   skipStaleCheck: false);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: v9, a4: 0);
  }
  if ( this->guiModel == nullptr )
  {
    v10 = (idRenderModelGui *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA410u,
                                tag: TAG_GUI_MODEL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    if ( v10 != nullptr )
      v11 = idRenderModelGui::idRenderModelGui(this: v10);
    else
      v11 = nullptr;
    this->guiModel = v11;
  }
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: v7,
    a4: v6);
  v12 = renderSystem->GetHeight(this: renderSystem);
  v13 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v13, height: v12);
  idDeviceContext::idDeviceContext(this: &v124, guiModel: this->guiModel);
  idDeviceContext::SetFont(this: &v124, font: this->font);
  v14 = (int)v5->GetAnimStack_2(this: v5);
  v15 = v14;
  v16 = 8;
  if ( (valueInteger & 2) != 0 )
  {
    v17 = *(_DWORD *)(v14 + 4);
    v18 = ((16 * *(_DWORD *)(v17 + 2060)) ^ 0x10) + v17;
    v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v17 + 2032) + 60) + 212);
    idGUIRect::idGUIRect(
      this: &v120,
      title_: "UserChannels",
      borderWidth_: 4,
      borderHeight_: 4,
      bgColor_: &idColor::colorBlack,
      textColor_: &idColor::colorLtGrey,
      titleBarColor_: &idColor::colorBlue,
      titleTextColor_: &idColor::colorWhite,
      alpha_: animationGui_alpha.valueFloat,
      textAlpha_: animationGui_textAlpha.valueFloat);
    HIDWORD(v20) = v3->name.data;
    idGUIRect::Printf(
      this: &v120,
      heading: "Name:",
      fmt: v20,
      a4: v22,
      a5: v21,
      a6: (int)v63,
      a7: (int)v68,
      a8: (int)v73,
      a9: v78,
      a10: v83,
      a11: v88,
      a12: v93,
      a13: v98);
    HIDWORD(v23) = "%d";
    LODWORD(v23) = v3->entityNumber;
    idGUIRect::Printf(
      this: &v120,
      heading: "Entity#:",
      fmt: v23,
      a4: v25,
      a5: v24,
      a6: v64,
      a7: v69,
      a8: v74,
      a9: v79,
      a10: v84,
      a11: v89,
      a12: v94,
      a13: v99);
    v27 = *(_DWORD *)(v19 + 40);
    v28 = 0;
    HIDWORD(v29) = *(unsigned __int16 *)(v27 + 4);
    if ( *(_WORD *)(v27 + 4) != 0 )
    {
      LODWORD(v29) = "Could not find AI state, idVS_ds_Car_Chase! ";
      v30 = 0;
      do
      {
        HIDWORD(v31) = "%.2d %.3f";
        v105 = *(float *)(*(_DWORD *)(v18 + 2120) + v30);
        *(double *)((char *)&v26 + 4) = v105;
        idGUIRect::Printf(
          this: &v120,
          heading: "Channel",
          fmt: v31,
          a4: v26,
          a5: v29,
          a6: (int)v63,
          a7: (int)v68,
          a8: (int)v73,
          a9: v78,
          a10: v83,
          a11: v88,
          a12: v93,
          a13: v98);
        LODWORD(v29) = *(_DWORD *)(v19 + 40);
        ++v28;
        v30 += 4;
        HIDWORD(v29) = *(unsigned __int16 *)(v29 + 4);
        LODWORD(v26) = HIDWORD(v29);
      }
      while ( v28 < SHIDWORD(v29) );
      v3 = ent;
    }
    idGUIRect::Render(
      this: &v120,
      context: &v124,
      y: 0x800000008LL,
      scale: animationGui_scale.valueFloat,
      a5: SHIDWORD(v26),
      a6: v26,
      a7: v29);
    v16 = 400;
    idGUIRect::~idGUIRect(this: &v120);
  }
  tree = (idMD6LeafPlay *)v5->GetAnimStack_2(this: v5)->tree;
  v33 = idPlayer::CastTo(c: v5);
  v34 = v33;
  if ( v33 != nullptr )
  {
    presentable = v33->presentable;
    if ( presentable != nullptr )
      v36 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v36 = 0;
    v37 = v34->presentable;
    tree = *(idMD6LeafPlay **)(v36 + 37868);
    if ( v37 != nullptr )
      v38 = (int)v37->GetPlayerInterface_2(this: v34->presentable);
    else
      v38 = 0;
    v15 = v38 + 37632;
  }
  if ( (v117 & 1) != 0 && tree != nullptr )
  {
    idGUIRect::idGUIRect(
      this: &v119,
      title_: "Animtree",
      borderWidth_: 2,
      borderHeight_: 2,
      bgColor_: &idColor::colorBlack,
      textColor_: &idColor::colorLtGrey,
      titleBarColor_: &idColor::colorBlue,
      titleTextColor_: &idColor::colorWhite,
      alpha_: animationGui_alpha.valueFloat,
      textAlpha_: animationGui_textAlpha.valueFloat);
    v118.len = 0;
    v118.allocedAndFlag = 20;
    v118.data = v118.baseBuffer;
    v118.baseBuffer[0] = 0;
    idAnimationGUI::DrawAnimTree_r(this, tabLvl: &v118, rect: &v119, treeNode: tree);
    LODWORD(v39) = 8;
    HIDWORD(v39) = v16;
    idGUIRect::Render(
      this: &v119,
      context: &v124,
      y: v39,
      scale: animationGui_scale.valueFloat,
      a5: v42,
      a6: v41,
      a7: v40);
    idStr::FreeData(this: &v118);
    idGUIRect::~idGUIRect(this: &v119);
  }
  if ( (v117 & 4) != 0 && tree != nullptr )
  {
    v43 = *(const idMD6Model **)(*(_DWORD *)(*(_DWORD *)(v15 + 4) + 2032) + 60);
    md6OriginDelta_t::md6OriginDelta_t(this: (md6OriginDelta_t *)&v120);
    v44 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v47 = ParseTree(
            model: v43,
            lastTimeMSec: PreviousGameMs,
            timeMSec: GameMs,
            ticksPerSec: v44,
            tree,
            cmds: v125,
            maxCmds: 128,
            frameBounds: &v123,
            translatedBounds: v63,
            normalizedBounds: v68,
            originDelta: v73,
            animatorFlags: v78,
            a13: v83,
            a14: v88,
            a15: v93,
            a16: v98,
            a17: v103,
            a18: v104,
            a19: SHIDWORD(v105),
            a20: SLODWORD(v105),
            a21: v106,
            a22: v108,
            a23: v109,
            a24: v110,
            a25: v111,
            a26: v112,
            a27: v113,
            a28: &v121,
            a29: v114,
            a30: &v122,
            a31: v115,
            a32: (int)&v120,
            a33: v116,
            a34: 0);
    idGUIRect::idGUIRect(
      this: &v119,
      title_: "BlendCommands",
      borderWidth_: 4,
      borderHeight_: 4,
      bgColor_: &idColor::colorBlack,
      textColor_: &idColor::colorLtGrey,
      titleBarColor_: &idColor::colorBlue,
      titleTextColor_: &idColor::colorWhite,
      alpha_: animationGui_alpha.valueFloat,
      textAlpha_: animationGui_textAlpha.valueFloat);
    HIDWORD(v48) = v3->name.data;
    idGUIRect::Printf(
      this: &v119,
      heading: "Name:",
      fmt: v48,
      a4: v50,
      a5: v49,
      a6: v65,
      a7: v70,
      a8: v75,
      a9: v80,
      a10: v85,
      a11: v90,
      a12: v95,
      a13: v100);
    HIDWORD(v51) = "%d";
    LODWORD(v51) = v3->entityNumber;
    idGUIRect::Printf(
      this: &v119,
      heading: "Entity#:",
      fmt: v51,
      a4: v53,
      a5: v52,
      a6: v66,
      a7: v71,
      a8: v76,
      a9: v81,
      a10: v86,
      a11: v91,
      a12: v96,
      a13: v101);
    if ( v47 > 0 )
    {
      v57 = v47;
      p_z = &v124.origin.z;
      do
      {
        v107 = p_z[17];
        LODWORD(v59) = LODWORD(v107);
        *(float *)&v59 = p_z[19];
        LODWORD(v60) = 4 * *((_DWORD *)p_z + 4);
        p_z += 16;
        HIDWORD(v61) = "%s Anim: %s Alpha: %.2f BlendOp: %s";
        LODWORD(v61) = *(const char **)((char *)opNames + v60);
        HIDWORD(v60) = *(const char **)((char *)idMD6Blend::blendOpNames + __ROL4__(*(unsigned __int8 *)p_z, 2));
        idGUIRect::Printf(
          this: &v119,
          heading: "Command:",
          fmt: v61,
          a4: v59,
          a5: v60,
          a6: v67,
          a7: v72,
          a8: v77,
          a9: v82,
          a10: v87,
          a11: v92,
          a12: v97,
          a13: v102);
        --v57;
      }
      while ( v57 != 0 );
    }
    LODWORD(v62) = 8;
    HIDWORD(v62) = v16;
    idGUIRect::Render(
      this: &v119,
      context: &v124,
      y: v62,
      scale: animationGui_scale.valueFloat,
      a5: v56,
      a6: v55,
      a7: v54);
    idGUIRect::~idGUIRect(this: &v119);
  }
  return this->guiModel;
}


// ========================================================================
// __unwind$488098
// EA  : 0x82B2D16C
// RVA : 0x00B2D16C
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488098()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 10192 + 116), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$488099
// EA  : 0x82B2D198
// RVA : 0x00B2D198
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488099()
{
  int v0; // r12

  idGUIRect::~idGUIRect(this: (idGUIRect *)(v0 - 10192 + 304));
}


// ========================================================================
// __unwind$488100
// EA  : 0x82B2D1C0
// RVA : 0x00B2D1C0
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488100()
{
  int v0; // r12

  idGUIRect::~idGUIRect(this: (idGUIRect *)(v0 - 10192 + 160));
}


// ========================================================================
// __unwind$488101
// EA  : 0x82B2D1E8
// RVA : 0x00B2D1E8
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488101()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 10192 + 128));
}


// ========================================================================
// __unwind$488102
// EA  : 0x82B2D210
// RVA : 0x00B2D210
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void _unwind_488102()
{
  int v0; // r12

  idGUIRect::~idGUIRect(this: (idGUIRect *)(v0 - 10192 + 160));
}


// ========================================================================
// `dynamic initializer for 'animationGui_show''
// EA  : 0x8336B8A8
// RVA : 0x0136B8A8
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationGui_show__()
{
  idCVar::idCVar(
    this: &animationGui_show,
    name: "animationGui_show",
    value: "0",
    flags: 2,
    description: "0 = off, 1 = animTree GUI active, 2 = userchannels GUI active, 3 = userchannels + animTree GUI active",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationGui_show__);
}


// ========================================================================
// `dynamic initializer for 'animationGui_scale''
// EA  : 0x8336B900
// RVA : 0x0136B900
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationGui_scale__()
{
  idCVar::idCVar(
    this: &animationGui_scale,
    name: "animationGui_scale",
    value: "0.2",
    flags: 4,
    description: "scale for Animation GUI text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationGui_scale__);
}


// ========================================================================
// `dynamic initializer for 'animationGui_font''
// EA  : 0x8336B958
// RVA : 0x0136B958
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationGui_font__()
{
  idCVar::idCVar(
    this: &animationGui_font,
    name: "animationGui_font",
    value: "arial_black",
    flags: 0,
    description: "font for AnimatedFace GUI text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationGui_font__);
}


// ========================================================================
// `dynamic initializer for 'animationGui_alpha''
// EA  : 0x8336B9B0
// RVA : 0x0136B9B0
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationGui_alpha__()
{
  idCVar::idCVar(
    this: &animationGui_alpha,
    name: "animationGui_alpha",
    value: "0.6",
    flags: 4,
    description: "alpha for AnimatedFace guis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationGui_alpha__);
}


// ========================================================================
// `dynamic initializer for 'animationGui_textAlpha''
// EA  : 0x8336BA08
// RVA : 0x0136BA08
// PDB : w:\tech5\tungsten\game\animation\animationgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animationGui_textAlpha__()
{
  idCVar::idCVar(
    this: &animationGui_textAlpha,
    name: "animationGui_textAlpha",
    value: "1.75",
    flags: 4,
    description: "alpha for text in AnimatedFace guis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animationGui_textAlpha__);
}

