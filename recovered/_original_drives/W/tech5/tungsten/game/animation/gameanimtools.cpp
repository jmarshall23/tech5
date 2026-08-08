
// ========================================================================
// ??1idGameAnimToolsLocal@@UAA@XZ
// EA  : 0x82B34570
// RVA : 0x00B34570
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __fastcall idGameAnimToolsLocal::~idGameAnimToolsLocal(idGameAnimToolsLocal *this)
{
  idRenderModelGui *guiModel; // r3

  this->__vftable = (idGameAnimToolsLocal_vtbl *)&idGameAnimToolsLocal::`vftable';
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
  }
  this->__vftable = (idGameAnimToolsLocal_vtbl *)&idGameAnimTools::`vftable';
}


// ========================================================================
// __unwind$488283
// EA  : 0x82B345E0
// RVA : 0x00B345E0
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_488283()
{
  int v0; // r12

  idGameAnimTools::~idGameAnimTools(this: *(idGameAnimTools **)(v0 - 112 + 132));
}


// ========================================================================
// ?DrawBlendTreeBranch@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Branch@@@Z
// EA  : 0x82B34668
// RVA : 0x00B34668
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameAnimToolsLocal::DrawBlendTreeBranch(
        idGameAnimToolsLocal *this,
        idDeviceContext *context,
        double x,
        double y,
        const idMD6Branch *branch,
        int a6,
        int a7)
{
  idGameAnimToolsLocal *v7; // r31
  double v11; // fp29
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  const idVec4 *v16; // r4
  __int128 v17; // r9 OVERLAPPED
  double v18; // fp28
  int v19; // r29
  va *v20; // r3
  __int64 v21; // r11
  int v22; // r6
  const char *v23; // r5
  __int64 v24; // r8
  __int64 v25; // r10
  int v26; // r29
  __int64 v27; // r6
  va *v28; // r3
  __int64 v29; // r6
  const idVec4 *v30; // r4
  __int64 v31; // r10
  int v32; // r29
  __int64 v33; // r6
  __int64 v34; // r8
  va *v35; // r3
  __int64 v36; // r7
  const char *v37; // r5
  const idVec4 *v38; // r4
  __int64 v39; // r6
  __int64 v40; // r10
  int v41; // r29
  __int64 v42; // r8
  va *v43; // r3
  int v44; // r6
  const char *v45; // r5
  const idVec4 *v46; // r4
  __int64 v47; // r6
  __int64 v48; // r10
  __int64 v49; // r8
  va *v50; // r3
  __int64 v51; // r6
  const idVec4 *v52; // r4
  int v53; // [sp+8h] [-10B8h]
  int v54; // [sp+8h] [-10B8h]
  int v55; // [sp+8h] [-10B8h]
  int v56; // [sp+8h] [-10B8h]
  int v57; // [sp+8h] [-10B8h]
  int v58; // [sp+Ch] [-10B4h]
  int v59; // [sp+Ch] [-10B4h]
  int v60; // [sp+Ch] [-10B4h]
  int v61; // [sp+Ch] [-10B4h]
  int v62; // [sp+Ch] [-10B4h]
  int v63; // [sp+10h] [-10B0h]
  int v64; // [sp+10h] [-10B0h]
  int v65; // [sp+10h] [-10B0h]
  int v66; // [sp+10h] [-10B0h]
  int v67; // [sp+10h] [-10B0h]
  int v68; // [sp+14h] [-10ACh]
  int v69; // [sp+14h] [-10ACh]
  int v70; // [sp+14h] [-10ACh]
  int v71; // [sp+14h] [-10ACh]
  int v72; // [sp+14h] [-10ACh]
  int v73; // [sp+18h] [-10A8h]
  int v74; // [sp+18h] [-10A8h]
  int v75; // [sp+18h] [-10A8h]
  int v76; // [sp+18h] [-10A8h]
  int v77; // [sp+18h] [-10A8h]
  int v78; // [sp+1Ch] [-10A4h]
  int v79; // [sp+1Ch] [-10A4h]
  int v80; // [sp+1Ch] [-10A4h]
  int v81; // [sp+1Ch] [-10A4h]
  int v82; // [sp+1Ch] [-10A4h]
  double v83; // [sp+20h] [-10A0h]
  va v84; // [sp+60h] [-1060h] BYREF

  v7 = this;
  v11 = (float)-(float)((float)(this->nodeWidth * (float)0.5) - (float)x);
  idDeviceContext::DrawFilledRect(
    this: context,
    x: v11,
    y,
    w: this->nodeWidth,
    h: this->nodeHeight,
    color: (const idVec4 *)context,
    a7: (int)branch,
    a8: a6,
    a9: a7,
    a10: (const idVec4 *)&this->branchColor);
  idDeviceContext::DrawRect(
    this: context,
    x: v11,
    y,
    w: v7->nodeWidth,
    h: v7->nodeHeight,
    size: 1.0,
    color: v16,
    a8: v15,
    a9: v14,
    a10: v13,
    a11: v12,
    a12: (const idVec4 *)&v7->outlineColor);
  *((_QWORD *)&v17 + 1) = __PAIR64__(off_82010000, idDeviceContext::TextHeight(this: context, scale: 0.30000001));
  DWORD1(v17) = &joystick.joyAxis[0][2];
  v18 = (float)(__int64)v17;
  v19 = (int)(float)((float)((float)-(float)((float)((float)(__int64)v17 * (float)4.0) - v7->nodeHeight) * (float)0.5)
                   + (float)y);
  v20 = va::va(
          this: &v84,
          fmt: idGameAnimToolsLocal::TEXT_LINES[0],
          a3: __SPAIR64__(&byte_8200D768, a7),
          a4: *(__int64 *)((char *)&v17 + 4),
          a5: *(__int64 *)((char *)&v17 - 4),
          a6: v53,
          a7: v58,
          a8: v63,
          a9: v68,
          a10: v73,
          a11: v78);
  LODWORD(v21) = v19;
  v7 = (idGameAnimToolsLocal *)((char *)v7 + 68);
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v11 + (float)2.0),
    y: (float)v21,
    scale: 0.30000001,
    color: (const idVec4 *)off_82010000,
    text: v23,
    a7: v22,
    a8: (const idVec4 *)v7,
    a9: (const unsigned __int8 *)v20);
  LODWORD(v24) = *(unsigned __int8 *)(a7 + 21);
  LODWORD(v25) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  HIDWORD(v25) = idMD6Blend::blendOpNames;
  HIDWORD(v24) = __ROL4__(v24, 2);
  v26 = (int)v18 + v19;
  HIDWORD(v27) = *(const char **)((char *)idMD6Blend::blendOpNames + HIDWORD(v24));
  v28 = va::va(
          this: &v84,
          fmt: idGameAnimToolsLocal::TEXT_LINES[1],
          a3: v27,
          a4: v24,
          a5: v25,
          a6: v54,
          a7: v59,
          a8: v64,
          a9: v69,
          a10: v74,
          a11: v79);
  LODWORD(v29) = v26;
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v11 + (float)2.0),
    y: (float)v29,
    scale: 0.30000001,
    color: v30,
    text: (const char *)HIDWORD(v29),
    a7: v26,
    a8: (const idVec4 *)v7,
    a9: (const unsigned __int8 *)v28);
  LODWORD(v31) = *(unsigned __int8 *)(a7 + 22);
  HIDWORD(v31) = __ROL4__(v31, 2);
  v32 = (int)v18 + v26;
  HIDWORD(v33) = *(const char **)((char *)idMD6Blend::originBlendNames + HIDWORD(v31));
  v35 = va::va(
          this: &v84,
          fmt: idGameAnimToolsLocal::TEXT_LINES[2],
          a3: v33,
          a4: v34,
          a5: v31,
          a6: v55,
          a7: v60,
          a8: v65,
          a9: v70,
          a10: v75,
          a11: v80);
  LODWORD(v36) = v32;
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v11 + (float)2.0),
    y: (float)v36,
    scale: 0.30000001,
    color: v38,
    text: v37,
    a7: SHIDWORD(v36),
    a8: (const idVec4 *)v7,
    a9: (const unsigned __int8 *)v35);
  LODWORD(v39) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  LODWORD(v40) = __ROL4__(*(unsigned __int8 *)(a7 + 20), 2);
  v41 = (int)v18 + v32;
  HIDWORD(v39) = *(const char **)((char *)idMD6Skel::weightGroupNames + v40);
  v43 = va::va(
          this: &v84,
          fmt: idGameAnimToolsLocal::TEXT_LINES[7],
          a3: v39,
          a4: v42,
          a5: v40,
          a6: v56,
          a7: v61,
          a8: v66,
          a9: v71,
          a10: v76,
          a11: v81);
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v11 + (float)2.0),
    y: (float)__SPAIR64__((unsigned int)v43, v41),
    scale: 0.30000001,
    color: v46,
    text: v45,
    a7: v44,
    a8: (const idVec4 *)v7,
    a9: (const unsigned __int8 *)v43);
  v83 = *(float *)(a7 + 24);
  HIDWORD(v47) = LODWORD(v83);
  v50 = va::va(
          this: &v84,
          fmt: idGameAnimToolsLocal::TEXT_LINES[4],
          a3: v47,
          a4: v49,
          a5: v48,
          a6: v57,
          a7: v62,
          a8: v67,
          a9: v72,
          a10: v77,
          a11: v82);
  LODWORD(v51) = (int)v18 + v41;
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v11 + (float)2.0),
    y: (float)v51,
    scale: 0.30000001,
    color: v52,
    text: (const char *)HIDWORD(v51),
    a7: v51,
    a8: (const idVec4 *)v7,
    a9: (const unsigned __int8 *)v50);
}


// ========================================================================
// ?GetAnimNumFrames@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBVidMD6Anim@@@Z
// EA  : 0x82B348D0
// RVA : 0x00B348D0
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::GetAnimNumFrames(
        idGameAnimToolsLocal *this,
        const idTreeAnimator *treeAnimator,
        const idMD6Anim *anim)
{
  int result; // r3
  idMD6AnimData *animData; // r11

  result = 0;
  if ( anim != nullptr )
  {
    animData = anim->animData;
    if ( animData != nullptr )
      return animData->numFrames;
  }
  return result;
}


// ========================================================================
// ?TreeMaxNodeWidth_r@idGameAnimToolsLocal@@AAAHAAVidDeviceContext@@PBVidMD6Node@@@Z
// EA  : 0x82B348F8
// RVA : 0x00B348F8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::TreeMaxNodeWidth_r(
        idGameAnimToolsLocal *this,
        idDeviceContext *context,
        const idMD6Node *node)
{
  int type; // r11
  char v7; // r10
  int v8; // r30
  const char *v9; // r4
  int v10; // r3
  int result; // r3
  char v12; // r11
  bool v13; // zf
  const char *v14; // r4
  int v15; // r30
  int v16; // [sp+50h] [-80h]
  idStr v17; // [sp+60h] [-70h] BYREF
  idStr v18[2]; // [sp+80h] [-50h] BYREF

  if ( node == nullptr )
    return 0;
  type = node->type;
  if ( node->type == 0 || type == 3 || type == 4 || (v7 = 0, type == 5) )
    v7 = 1;
  if ( v7 == 0 )
  {
    if ( type == 1 || (v13 = type != 2, v12 = 0, !v13) )
      v12 = 1;
    if ( v12 != 0 )
    {
      v16 = *(_DWORD *)&node[4].type;
      if ( v16 != 0 )
      {
        idStr::idStr(this: v18, text: *(const char **)(v16 + 8));
        if ( v18[0].len != 0 )
        {
          v17.len = 0;
          v17.baseBuffer[0] = 0;
          v17.allocedAndFlag = 20;
          v17.data = v17.baseBuffer;
          idStr::ExtractFileBase(this: v18, dest: &v17);
          v15 = idDeviceContext::TextWidth(
                  this: context,
                  scale: 0.30000001,
                  text: v14,
                  limit: (const unsigned __int8 *)v17.data,
                  a5: 0);
          idStr::FreeData(this: &v17);
          idStr::FreeData(this: v18);
          return v15;
        }
        idStr::FreeData(this: v18);
      }
    }
    return 0;
  }
  v8 = idGameAnimToolsLocal::TreeMaxNodeWidth_r(this, context, node: *(const idMD6Node **)&node[4].type);
  v10 = idGameAnimToolsLocal::TreeMaxNodeWidth_r(this, context, node: *(const idMD6Node **)&node[8].type);
  if ( v8 <= v10 )
    v8 = v10;
  result = idDeviceContext::TextWidth(
             this: context,
             scale: 0.30000001,
             text: v9,
             limit: (const unsigned __int8 *)&byte_8200D768,
             a5: 0);
  if ( v8 > result )
    return v8;
  return result;
}


// ========================================================================
// __unwind$488549
// EA  : 0x82B34A70
// RVA : 0x00B34A70
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_488549()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$488550
// EA  : 0x82B34A98
// RVA : 0x00B34A98
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_488550()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?TreeDepth_r@idGameAnimToolsLocal@@AAAHPBVidMD6Node@@@Z
// EA  : 0x82B34AC0
// RVA : 0x00B34AC0
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::TreeDepth_r(idGameAnimToolsLocal *this, const idMD6Node *node)
{
  int type; // r11
  char v5; // r11
  bool v6; // zf
  int v7; // r31
  int v8; // r3

  if ( node == nullptr )
    return 0;
  type = node->type;
  if ( node->type == 0 || type == 3 || type == 4 || (v6 = type != 5, v5 = 0, !v6) )
    v5 = 1;
  if ( v5 == 0 )
    return 0;
  v7 = idGameAnimToolsLocal::TreeDepth_r(this, node: *(const idMD6Node **)&node[4].type);
  v8 = idGameAnimToolsLocal::TreeDepth_r(this, node: *(const idMD6Node **)&node[8].type);
  if ( v7 > v8 )
    v8 = v7;
  return v8 + 1;
}


// ========================================================================
// ?TreeDepth@idGameAnimToolsLocal@@UAAHPBVidMD6Node@@@Z
// EA  : 0x82B34B58
// RVA : 0x00B34B58
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::TreeDepth(idGameAnimToolsLocal *this, const idMD6Node *root)
{
  if ( root != nullptr )
    return idGameAnimToolsLocal::TreeDepth_r(this, node: root);
  else
    return -1;
}


// ========================================================================
// ?GetAnimData@idGameAnimToolsLocal@@AAAPBVidMD6AnimData@@PBVidTreeAnimator@@PBD@Z
// EA  : 0x82B34B70
// RVA : 0x00B34B70
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

const idMD6AnimData *__fastcall idGameAnimToolsLocal::GetAnimData(
        idGameAnimToolsLocal *this,
        const idTreeAnimator *treeAnimator,
        const char *aliasName)
{
  const idMD6AnimData *result; // r3
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v8[4]; // [sp+50h] [-20h] BYREF

  result = nullptr;
  if ( treeAnimator != nullptr && aliasName != nullptr )
  {
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)v8, result: treeAnimator->decl, aliasName);
    if ( v8[0].value == 0xFFFF )
    {
      idLib::Warning(fmt: "%s - unable to find alias handle for <%s>", "idGameAnimToolsLocal::GetAnimData", aliasName);
    }
    else
    {
      Alias = idDeclMD6::FindAlias(this: treeAnimator->decl, aliasHandle: v8, includeInherited: true);
      if ( Alias != nullptr )
      {
        Existing = idResourceList::FindExisting(
                     this: &idMD6Anim::resourceList,
                     name: (char *)Alias->animRefs.list->str,
                     skipStaleCheck: true);
        if ( Existing != nullptr )
        {
          result = (const idMD6AnimData *)Existing[1].trackedMemory;
          if ( result != nullptr )
            return result;
          idLib::Warning(
            fmt: "%s - unable to find MD6 anim data for <%s>",
            "idGameAnimToolsLocal::GetAnimData",
            aliasName);
        }
        else
        {
          idLib::Warning(
            fmt: "%s - unable to find anim handle for <%s>",
            "idGameAnimToolsLocal::GetAnimData",
            aliasName);
        }
      }
      else
      {
        idLib::Warning(fmt: "%s - unable to find alias for <%s>", "idGameAnimToolsLocal::GetAnimData", aliasName);
      }
    }
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetAnimNumFrames@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBD@Z
// EA  : 0x82B34C58
// RVA : 0x00B34C58
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::GetAnimNumFrames(
        idGameAnimToolsLocal *this,
        const idTreeAnimator *treeAnimator,
        const char *aliasName)
{
  const idMD6AnimData *AnimData; // r3

  AnimData = idGameAnimToolsLocal::GetAnimData(this, treeAnimator, aliasName);
  if ( AnimData != nullptr )
    return AnimData->numFrames;
  else
    return 0;
}


// ========================================================================
// ?GetAnimFrameRate@idGameAnimToolsLocal@@UAAHPBVidTreeAnimator@@PBD@Z
// EA  : 0x82B34CA8
// RVA : 0x00B34CA8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::GetAnimFrameRate(
        idGameAnimToolsLocal *this,
        const idTreeAnimator *treeAnimator,
        const char *aliasName)
{
  const idMD6AnimData *AnimData; // r3

  AnimData = idGameAnimToolsLocal::GetAnimData(this, treeAnimator, aliasName);
  if ( AnimData != nullptr )
    return AnimData->frameRate;
  else
    return 0;
}


// ========================================================================
// ?VerifyStrongAliasRefs@idGameAnimToolsLocal@@UAA_NPBVidTreeAnimator@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBD@Z
// EA  : 0x82B34CF8
// RVA : 0x00B34CF8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

int __fastcall idGameAnimToolsLocal::VerifyStrongAliasRefs(
        idGameAnimToolsLocal *this,
        const idTreeAnimator *ta,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        const char *entityName)
{
  const char *v7; // r26
  const idMD6Alias *Alias; // r3
  const idMD6Alias *v10; // r30
  int v11; // r28
  const char **p_str; // r31
  char *v13; // r4
  char v14; // r11

  if ( aliasHandle->value == 0xFFFF )
    return 0;
  v7 = animation->FindAliasName(this: animation, a2: aliasHandle);
  if ( v7 == nullptr )
  {
    idLib::Warning(fmt: "NULL alias name for entity '%s'", entityName);
    return 0;
  }
  Alias = idDeclMD6::FindAlias(this: ta->decl, aliasHandle, includeInherited: true);
  v10 = Alias;
  if ( Alias != nullptr )
  {
    v11 = 0;
    if ( Alias->animRefs.num <= 0 )
    {
      return 1;
    }
    else
    {
      while ( 1 )
      {
        p_str = &v10->animRefs.list->str;
        v13 = (char *)*p_str;
        if ( *p_str == &byte_8200D768 || (v14 = 0, *v13 == 0) )
          v14 = 1;
        if ( v14 != 0 )
          break;
        if ( idResourceList::FindExisting(this: &idMD6Anim::resourceList, name: v13, skipStaleCheck: false) == nullptr )
        {
          idLib::Warning(
            fmt: "Anim alias '%s' in entity '%s' has an weak reference for anim '%s'",
            v10->name.str,
            entityName,
            *p_str);
          return 0;
        }
        if ( ++v11 >= v10->animRefs.num )
          return 1;
      }
      idLib::Warning(fmt: "Anim alias '%s' in entity '%s' has an invalid weak anim ref", v7, entityName);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "ModelDef '%s' does not define alias '%s'", ta->decl->name.str, v7);
    return 0;
  }
}


// ========================================================================
// ?WalkTree_r@idGameAnimToolsLocal@@AAAXPBVidMD6Node@@@Z
// EA  : 0x82B34E68
// RVA : 0x00B34E68
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __fastcall idGameAnimToolsLocal::WalkTree_r(idGameAnimToolsLocal *this, idMD6LeafPlay *node)
{
  unsigned int type; // r5
  const char *str; // r30
  int wrapMode; // r29
  int startTime; // r28
  signed int v8; // r27
  int GameMs; // r3
  int v10; // r6
  __int64 v11; // r10
  int v12; // r4
  idMD6LeafPlay *v13; // r3
  int v14; // r29
  idDebugHUD_vtbl *v15; // r31
  int v16; // r8
  unsigned __int16 Frame; // r3
  double v18; // [sp+28h] [-68h]

  type = node->type;
  if ( node->type != 0 )
  {
    if ( type == 1 )
    {
      debugHUD->Printf(
        this: debugHUD,
        a2: "^2PAUSE: ^8anim = '^7%s^8', frame = ^7%g^8\n",
        (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&node[2].anim)),
        (unsigned int)COERCE_UNSIGNED_INT64(*(float *)&node[2].anim));
    }
    else if ( type < 3 )
    {
      str = node->anim->name.str;
      if ( str == nullptr )
        str = "< unknown >";
      wrapMode = node->wrapMode;
      startTime = node->startTime;
      v8 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v10 = __ROL4__(wrapMode, 2);
      LODWORD(v11) = idMD6Leaf::wrapModeNames;
      v12 = GameMs;
      v13 = node;
      v14 = *(int *)((char *)idMD6Leaf::wrapModeNames + v10);
      v15 = debugHUD->__vftable;
      Frame = idMD6LeafPlay::GetFrame(
                this: v13,
                gameTime: v12,
                ticksPerSec: v8,
                a4: v10,
                a5: (int)&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor',
                a6: v16,
                a7: v11);
      v15->Printf(
        this: debugHUD,
        a2: "^2PLAY: ^8anim = '^7%s^8', lastFrame = ^7%d^8, startTime = ^7%d^8, wrapMode = '^7%s^8'\n",
        str,
        Frame,
        startTime,
        v14);
    }
    else
    {
      debugHUD->Printf(this: debugHUD, a2: "^2UNKNOWN: ^8type = ^7%d^8\n");
    }
  }
  else
  {
    idGameAnimToolsLocal::WalkTree_r(this, node: (const idMD6Node *)node->anim);
    idGameAnimToolsLocal::WalkTree_r(this, node: *(const idMD6Node **)&node->weightGroup);
    debugHUD->Printf(
      this: debugHUD,
      a2: "^2BRANCH: op = '^7%s^8'",
      *(const char **)((char *)idMD6Blend::blendOpNames + __ROL4__(node->syncEnabled, 2)));
    v18 = *(float *)&node[1].type;
    debugHUD->Printf(
      this: debugHUD,
      a2: (const char *)(HIDWORD(v18) + 19024),
      *(const char **)((char *)idMD6Blend::blendOpNames + __ROL4__(node->syncEnabled, 2)),
      LODWORD(v18),
      COERCE_UNSIGNED_INT64(*(float *)&node[1].anim),
      COERCE_UNSIGNED_INT64(*(float *)&node[1].weightGroup));
  }
}


// ========================================================================
// ?AnimDebugHud@idGameAnimToolsLocal@@UAAXPAVidClass@@PBVidTreeAnimator@@PBVidMD6Node@@@Z
// EA  : 0x82B35058
// RVA : 0x00B35058
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __fastcall idGameAnimToolsLocal::AnimDebugHud(
        idGameAnimToolsLocal *this,
        idClass *owner,
        const idTreeAnimator *animator,
        idMD6LeafPlay *tree)
{
  debugHUD->Clear(this: debugHUD, a2: false);
  debugHUD->SetTextPosition(this: debugHUD, a2: 0, a3: 0);
  debugHUD->SetTextColor(this: debugHUD, a2: &idColor::colorGreen);
  debugHUD->Printf(this: debugHUD, a2: "MD6 Debug HUD\n\n");
  debugHUD->Printf(this: debugHUD, a2: "Tree Walk:\n");
  idGameAnimToolsLocal::WalkTree_r(this, node: tree);
}


// ========================================================================
// ?DrawBlendTreeLeaf@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Leaf@@@Z
// EA  : 0x82B35118
// RVA : 0x00B35118
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameAnimToolsLocal::DrawBlendTreeLeaf(
        idGameAnimToolsLocal *this,
        idDeviceContext *context,
        double x,
        double y,
        const idMD6Leaf *leaf,
        int a6,
        idMD6LeafPlay *a7)
{
  const char *str; // r4
  int v13; // r7
  int v14; // r6
  int v15; // r5
  const idVec4 *v16; // r4
  double v17; // fp29
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  const idVec4 *v22; // r4
  __int128 v23; // r9 OVERLAPPED
  double v24; // fp28
  int v25; // r24
  va *v26; // r3
  __int64 v27; // r6
  idColor *p_textColor; // r26
  const idVec4 *v29; // r4
  int v30; // r25
  int v31; // r24
  signed int v32; // r23
  int GameMs; // r3
  __int64 v34; // r10
  int v35; // r8
  int v36; // r7
  int v37; // r6
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  va *v41; // r3
  __int64 v42; // r7
  const char *v43; // r5
  const idVec4 *v44; // r4
  __int64 v45; // r6
  __int64 v46; // r10
  int v47; // r24
  __int64 v48; // r8
  va *v49; // r3
  int v50; // r6
  const char *v51; // r5
  const idVec4 *v52; // r4
  int v53; // r24
  __int64 v54; // r6
  __int64 v55; // r10
  __int64 v56; // r8
  va *v57; // r3
  __int64 v58; // r7
  const char *v59; // r5
  const idVec4 *v60; // r4
  __int64 v61; // r6
  __int64 v62; // r10
  __int64 v63; // r8
  va *v64; // r3
  __int64 v65; // r10
  int v66; // r6
  const char *v67; // r5
  const idVec4 *v68; // r4
  int v69; // [sp+8h] [-1108h]
  int v70; // [sp+8h] [-1108h]
  int v71; // [sp+8h] [-1108h]
  int v72; // [sp+8h] [-1108h]
  int v73; // [sp+8h] [-1108h]
  int v74; // [sp+Ch] [-1104h]
  int v75; // [sp+Ch] [-1104h]
  int v76; // [sp+Ch] [-1104h]
  int v77; // [sp+Ch] [-1104h]
  int v78; // [sp+Ch] [-1104h]
  int v79; // [sp+10h] [-1100h]
  int v80; // [sp+10h] [-1100h]
  int v81; // [sp+10h] [-1100h]
  int v82; // [sp+10h] [-1100h]
  int v83; // [sp+10h] [-1100h]
  int v84; // [sp+14h] [-10FCh]
  int v85; // [sp+14h] [-10FCh]
  int v86; // [sp+14h] [-10FCh]
  int v87; // [sp+14h] [-10FCh]
  int v88; // [sp+14h] [-10FCh]
  int v89; // [sp+18h] [-10F8h]
  int v90; // [sp+18h] [-10F8h]
  int v91; // [sp+18h] [-10F8h]
  int v92; // [sp+18h] [-10F8h]
  int v93; // [sp+18h] [-10F8h]
  int v94; // [sp+1Ch] [-10F4h]
  int v95; // [sp+1Ch] [-10F4h]
  int v96; // [sp+1Ch] [-10F4h]
  int v97; // [sp+1Ch] [-10F4h]
  int v98; // [sp+1Ch] [-10F4h]
  double VolumeAdjustment; // [sp+20h] [-10F0h]
  const idMD6Anim *anim; // [sp+50h] [-10C0h]
  idStr v101; // [sp+60h] [-10B0h] BYREF
  idStr v102; // [sp+80h] [-1090h] BYREF
  va v103; // [sp+A0h] [-1070h] BYREF

  anim = a7->anim;
  if ( anim != nullptr )
    str = anim->name.str;
  else
    str = "skeleton";
  idStr::idStr(this: &v102, text: str);
  v101.len = 0;
  v101.allocedAndFlag = 20;
  v101.data = v101.baseBuffer;
  v101.baseBuffer[0] = 0;
  if ( v102.len != 0 )
    idStr::ExtractFileBase(this: &v102, dest: &v101);
  v17 = (float)-(float)((float)(this->nodeWidth * (float)0.5) - (float)x);
  idDeviceContext::DrawFilledRect(
    this: context,
    x: v17,
    y,
    w: this->nodeWidth,
    h: this->nodeHeight,
    color: v16,
    a7: v15,
    a8: v14,
    a9: v13,
    a10: (const idVec4 *)&this->leafColor);
  idDeviceContext::DrawRect(
    this: context,
    x: v17,
    y,
    w: this->nodeWidth,
    h: this->nodeHeight,
    size: 1.0,
    color: v22,
    a8: v21,
    a9: v20,
    a10: v19,
    a11: v18,
    a12: (const idVec4 *)&this->outlineColor);
  *((_QWORD *)&v23 + 1) = __PAIR64__(off_82010000, idDeviceContext::TextHeight(this: context, scale: 0.30000001));
  v24 = (float)(__int64)v23;
  v25 = (int)(float)((float)((float)-(float)((float)((float)(__int64)v23 * (float)4.0) - this->nodeHeight) * (float)0.5)
                   + (float)y);
  v26 = va::va(
          this: &v103,
          fmt: idGameAnimToolsLocal::TEXT_LINES[0],
          a3: __SPAIR64__((unsigned int)v101.data, (unsigned int)a7),
          a4: *(__int64 *)((char *)&v23 + 4),
          a5: *(__int64 *)((char *)&v23 - 4),
          a6: v69,
          a7: v74,
          a8: v79,
          a9: v84,
          a10: v89,
          a11: v94);
  LODWORD(v27) = v25;
  p_textColor = &this->textColor;
  idDeviceContext::DrawTextA(
    this: context,
    x: (float)((float)v17 + (float)2.0),
    y: (float)v27,
    scale: 0.30000001,
    color: v29,
    text: (const char *)HIDWORD(v27),
    a7: v25,
    a8: (const idVec4 *)p_textColor,
    a9: (const unsigned __int8 *)v26);
  v30 = (int)v24;
  v31 = (int)v24 + v25;
  if ( a7->type == 2 )
  {
    v32 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v38) = (unsigned __int16)idMD6LeafPlay::GetFrame(
                                       this: a7,
                                       gameTime: GameMs,
                                       ticksPerSec: v32,
                                       a4: v37,
                                       a5: v36,
                                       a6: v35,
                                       a7: v34);
    v41 = va::va(
            this: &v103,
            fmt: idGameAnimToolsLocal::TEXT_LINES[3],
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v70,
            a7: v75,
            a8: v80,
            a9: v85,
            a10: v90,
            a11: v95);
    LODWORD(v42) = v31;
    idDeviceContext::DrawTextA(
      this: context,
      x: (float)((float)v17 + (float)2.0),
      y: (float)v42,
      scale: 0.30000001,
      color: v44,
      text: v43,
      a7: SHIDWORD(v42),
      a8: (const idVec4 *)p_textColor,
      a9: (const unsigned __int8 *)v41);
    LODWORD(v45) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
    LODWORD(v46) = __ROL4__(a7->wrapMode, 2);
    v47 = v30 + v31;
    HIDWORD(v45) = *(const char **)((char *)idMD6Leaf::wrapModeNames + v46);
    v49 = va::va(
            this: &v103,
            fmt: idGameAnimToolsLocal::TEXT_LINES[5],
            a3: v45,
            a4: v48,
            a5: v46,
            a6: v71,
            a7: v76,
            a8: v81,
            a9: v86,
            a10: v91,
            a11: v96);
    idDeviceContext::DrawTextA(
      this: context,
      x: (float)((float)v17 + (float)2.0),
      y: (float)__SPAIR64__((unsigned int)v49, v47),
      scale: 0.30000001,
      color: v52,
      text: v51,
      a7: v50,
      a8: (const idVec4 *)p_textColor,
      a9: (const unsigned __int8 *)v49);
    v53 = v30 + v47;
    VolumeAdjustment = idSoundEmitterLocal::GetVolumeAdjustment(this: (bfx::Orienter *)a7);
    HIDWORD(v54) = LODWORD(VolumeAdjustment);
    v57 = va::va(
            this: &v103,
            fmt: idGameAnimToolsLocal::TEXT_LINES[6],
            a3: v54,
            a4: v56,
            a5: v55,
            a6: v72,
            a7: v77,
            a8: v82,
            a9: v87,
            a10: v92,
            a11: v97);
    LODWORD(v58) = v53;
    idDeviceContext::DrawTextA(
      this: context,
      x: (float)((float)v17 + (float)2.0),
      y: (float)v58,
      scale: 0.30000001,
      color: v60,
      text: v59,
      a7: SHIDWORD(v58),
      a8: (const idVec4 *)p_textColor,
      a9: (const unsigned __int8 *)v57);
    LODWORD(v61) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
    HIDWORD(v61) = *(const char **)((char *)idMD6Skel::weightGroupNames + __ROL4__(a7->weightGroup, 2));
    v64 = va::va(
            this: &v103,
            fmt: idGameAnimToolsLocal::TEXT_LINES[7],
            a3: v61,
            a4: v63,
            a5: v62,
            a6: v73,
            a7: v78,
            a8: v83,
            a9: v88,
            a10: v93,
            a11: v98);
    LODWORD(v65) = v30 + v53;
    idDeviceContext::DrawTextA(
      this: context,
      x: (float)((float)v17 + (float)2.0),
      y: (float)v65,
      scale: 0.30000001,
      color: v68,
      text: v67,
      a7: v66,
      a8: (const idVec4 *)p_textColor,
      a9: (const unsigned __int8 *)v64);
  }
  idStr::FreeData(this: &v101);
  idStr::FreeData(this: &v102);
}


// ========================================================================
// __unwind$489162_0
// EA  : 0x82B35434
// RVA : 0x00B35434
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_489162_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 128));
}


// ========================================================================
// __unwind$489163
// EA  : 0x82B3545C
// RVA : 0x00B3545C
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_489163()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 96));
}


// ========================================================================
// ?DrawTree_r@idGameAnimToolsLocal@@AAAXAAVidDeviceContext@@MMPBVidMD6Node@@H@Z
// EA  : 0x82B35488
// RVA : 0x00B35488
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __fastcall idGameAnimToolsLocal::DrawTree_r(
        idGameAnimToolsLocal *this,
        idDeviceContext *context,
        double x,
        double y,
        const idMD6Leaf *node,
        int depth,
        unsigned __int8 *a7,
        char a8)
{
  int v8; // r11
  char v14; // r10
  double nodeWidth; // fp12
  double v16; // fp10
  __int64 v17; // r7
  double v20; // fp30
  double v21; // fp28
  double v22; // fp27
  double v23; // fp11
  const idVec4 *v24; // r6
  int v25; // r6
  const idMD6Branch *v26; // r5
  int v27; // r6
  const idMD6Node *v28; // r5
  char v29; // r11
  bool v30; // zf
  idVec2 v31; // [sp+50h] [-80h] BYREF
  idVec2 v32; // [sp+58h] [-78h] BYREF
  idVec2 v33; // [sp+60h] [-70h] BYREF
  __int64 v34; // [sp+68h] [-68h] BYREF

  v8 = *a7;
  if ( *a7 == 0 || v8 == 3 || v8 == 4 || (v14 = 0, v8 == 5) )
    v14 = 1;
  if ( v14 != 0 )
  {
    nodeWidth = this->nodeWidth;
    v16 = (float)(this->nodeHeight + (float)y);
    v31.y = this->nodeHeight + (float)y;
    v31.x = x;
    LODWORD(v17) = (1 << a8) - 1;
    HIDWORD(v17) = 0x82000000;
    v34 = v17;
    _FP6 = (float)((float)nodeWidth - blendTree_maxNodeSpacing.valueFloat);
    __asm { fsel      f5, f6, f0, f12 }
    v20 = (float)((float)v16 + (float)32.0);
    v32.y = (float)v16 + (float)32.0;
    v21 = (float)((float)((float)x - (float)((float)((float)v17 * (float)_FP5) * (float)0.5))
                - (float)((float)_FP5 * (float)0.5));
    v32.x = (float)((float)x - (float)((float)((float)v17 * (float)_FP5) * (float)0.5))
          - (float)((float)_FP5 * (float)0.5);
    v22 = (float)((float)((float)((float)_FP5 * (float)0.5) + (float)((float)((float)v17 * (float)_FP5) * (float)0.5))
                + (float)x);
    idDeviceContext::DrawLine(
      this: context,
      start: &v31,
      end: &v32,
      width: 1.0,
      color: (const idVec4 *)0x82000000,
      a6: (const idVec4 *)&this->linkColor);
    v23 = (float)(this->nodeHeight + (float)y);
    v33.x = v22;
    v33.y = v20;
    *(float *)&v34 = x;
    *((float *)&v34 + 1) = v23;
    idDeviceContext::DrawLine(
      this: context,
      start: (const idVec2 *)&v34,
      end: &v33,
      width: 1.0,
      color: v24,
      a6: (const idVec4 *)&this->linkColor);
    idGameAnimToolsLocal::DrawBlendTreeBranch(this, context, x, y, branch: v26, a6: v25, (int)a7);
    if ( *((_DWORD *)a7 + 1) != 0 )
      idGameAnimToolsLocal::DrawTree_r(this, context, x: v21, y: v20, node: v28, depth: v27);
    if ( *((_DWORD *)a7 + 2) != 0 )
      idGameAnimToolsLocal::DrawTree_r(this, context, x: v22, y: v20, node: v28, depth: v27);
  }
  else
  {
    if ( v8 == 1 || (v30 = v8 != 2, v29 = 0, !v30) )
      v29 = 1;
    if ( v29 != 0 )
      idGameAnimToolsLocal::DrawBlendTreeLeaf(this, context, x, y, leaf: node, a6: depth, (idMD6LeafPlay *)a7);
  }
}


// ========================================================================
// ?DrawBlendTree@idGameAnimToolsLocal@@UAAPAVidRenderModelGui@@PBDPBVidMD6Node@@@Z
// EA  : 0x82B35680
// RVA : 0x00B35680
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idRenderModelGui *__fastcall idGameAnimToolsLocal::DrawBlendTree(
        idGameAnimToolsLocal *this,
        const char *name,
        unsigned __int64 tree,
        int a4)
{
  idMD6Node *v6; // r26
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  unsigned int v10; // r29
  unsigned int v11; // r3
  const idMaterial *whiteMaterial; // r9
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  __int64 v17; // r10
  double v18; // fp26
  int v19; // r27
  int v20; // r3
  __int128 v21; // r10
  __int64 v22; // r6 OVERLAPPED
  va *v23; // r3
  const char *v24; // r4
  int v25; // r3
  __int64 v26; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  va *v31; // r3
  const char *v32; // r4
  __int64 v33; // r4
  __int64 v34; // r6
  __int64 v37; // r10
  __int64 v38; // r8
  va *v39; // r3
  const char *v40; // r4
  __int64 v41; // r3
  __int64 v44; // r10
  __int64 v45; // r8
  unsigned int v46; // r6
  va *v47; // r3
  const char *v48; // r4
  int v49; // r3
  __int64 v52; // r6
  __int64 v53; // r8
  va *v54; // r3
  const char *v55; // r4
  int v56; // r3
  __int64 v57; // r6
  __int64 v60; // r10
  va *v61; // r3
  const char *v62; // r4
  __int64 v63; // r6
  idRenderModelGui *gui; // r3
  int v67; // r11
  int v68; // r4
  __int64 v69; // r8
  __int64 v70; // r6
  __int64 v71; // r8
  double valueFloat; // fp29
  double v74; // fp28
  double VirtualWidth; // fp1
  double v77; // fp31
  double v78; // fp29
  __int64 v79; // r8
  int v80; // r5
  int v81; // r4
  const char *v82; // r4
  double VirtualHeight; // fp1
  double v84; // fp28
  __int64 v85; // r11
  int v86; // r6
  const char *v87; // r5
  const idVec4 *v88; // r4
  int v89; // r6
  const idMD6Leaf *v90; // r5
  idRenderModelGui *guiModel; // r30
  double v92; // fp27
  double v93; // fp29
  double v94; // fp30
  __int64 v95; // r8 OVERLAPPED
  int v96; // r5
  int v97; // r4
  double v98; // fp1
  double v99; // fp1
  int v100; // r9
  double v101; // fp28
  __int64 v102; // r8
  int v103; // r5
  int v104; // r4
  double v105; // fp1
  double v106; // fp1
  __int64 v108; // r8
  int v109; // r5
  int v110; // r4
  double v111; // fp1
  double v112; // fp1
  double v113; // fp1
  int v114; // [sp+8h] [-25F8h]
  int v115; // [sp+8h] [-25F8h]
  int v116; // [sp+8h] [-25F8h]
  int v117; // [sp+8h] [-25F8h]
  int v118; // [sp+8h] [-25F8h]
  int v119; // [sp+8h] [-25F8h]
  int v120; // [sp+8h] [-25F8h]
  int v121; // [sp+Ch] [-25F4h]
  int v122; // [sp+Ch] [-25F4h]
  int v123; // [sp+Ch] [-25F4h]
  int v124; // [sp+Ch] [-25F4h]
  int v125; // [sp+Ch] [-25F4h]
  int v126; // [sp+Ch] [-25F4h]
  int v127; // [sp+Ch] [-25F4h]
  int v128; // [sp+10h] [-25F0h]
  int v129; // [sp+10h] [-25F0h]
  int v130; // [sp+10h] [-25F0h]
  int v131; // [sp+10h] [-25F0h]
  int v132; // [sp+10h] [-25F0h]
  int v133; // [sp+10h] [-25F0h]
  int v134; // [sp+10h] [-25F0h]
  int v135; // [sp+14h] [-25ECh]
  int v136; // [sp+14h] [-25ECh]
  int v137; // [sp+14h] [-25ECh]
  int v138; // [sp+14h] [-25ECh]
  int v139; // [sp+14h] [-25ECh]
  int v140; // [sp+14h] [-25ECh]
  int v141; // [sp+14h] [-25ECh]
  int v142; // [sp+18h] [-25E8h]
  int v143; // [sp+18h] [-25E8h]
  int v144; // [sp+18h] [-25E8h]
  int v145; // [sp+18h] [-25E8h]
  int v146; // [sp+18h] [-25E8h]
  int v147; // [sp+18h] [-25E8h]
  int v148; // [sp+18h] [-25E8h]
  int v149; // [sp+1Ch] [-25E4h]
  int v150; // [sp+1Ch] [-25E4h]
  int v151; // [sp+1Ch] [-25E4h]
  int v152; // [sp+1Ch] [-25E4h]
  int v153; // [sp+1Ch] [-25E4h]
  int v154; // [sp+1Ch] [-25E4h]
  int v155; // [sp+1Ch] [-25E4h]
  idStr v156; // [sp+60h] [-25A0h] BYREF
  idDeviceContext v157; // [sp+80h] [-2580h] BYREF
  va v158; // [sp+590h] [-2070h] BYREF
  va v159; // [sp+1590h] [-1070h] BYREF

  v6 = (idMD6Node *)HIDWORD(tree);
  if ( HIDWORD(tree) == 0 )
    return nullptr;
  if ( this->guiModel == nullptr )
  {
    v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA410u,
                               tag: TAG_GUI_MODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
      v9 = idRenderModelGui::idRenderModelGui(this: v8);
    else
      v9 = nullptr;
    this->guiModel = v9;
  }
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: tree,
    a4);
  v10 = renderSystem->GetHeight(this: renderSystem);
  v11 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v11, height: v10);
  idDeviceContext::idDeviceContext(this: &v157, guiModel: this->guiModel);
  whiteMaterial = this->whiteMaterial;
  v157.uiScale.x = blendTree_scale.valueFloat;
  v157.uiScale.y = blendTree_scale.valueFloat;
  v157.uiOffset.x = blendTree_x.valueFloat;
  v157.uiOffset.y = blendTree_y.valueFloat;
  if ( whiteMaterial == nullptr )
    this->whiteMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                this: &idMaterial::resourceList,
                                                name: "_white",
                                                makeDefault: true);
  HIDWORD(v13) = 0x82000000;
  HIDWORD(v14) = &this->branchColor;
  LODWORD(v14) = "Could not find AI state, idVS_ds_Car_Chase! ";
  this->branchColor.b = 0.30000001;
  LODWORD(v15) = &this->leafColor;
  LODWORD(v13) = &this->outlineColor;
  this->branchColor.r = 0.0;
  this->branchColor.g = 0.0;
  this->branchColor.a = 0.75;
  HIDWORD(v15) = name;
  this->leafColor.g = 0.30000001;
  this->leafColor.r = 0.0;
  this->leafColor.b = 0.0;
  this->leafColor.a = 0.75;
  this->outlineColor.r = 1.0;
  this->outlineColor.g = 1.0;
  this->outlineColor.b = 1.0;
  this->outlineColor.a = 0.75;
  this->textColor.r = 1.0;
  this->textColor.g = 1.0;
  this->textColor.b = 1.0;
  this->textColor.a = 0.75;
  this->linkColor.r = 1.0;
  this->linkColor.g = 1.0;
  this->linkColor.b = 1.0;
  this->linkColor.a = 0.75;
  v16 = va::va(
          this: &v159,
          fmt: "Blend Tree for %s",
          a3: v15,
          a4: v14,
          a5: v13,
          a6: v114,
          a7: v121,
          a8: v128,
          a9: v135,
          a10: v142,
          a11: v149);
  idStr::idStr(this: &v156, text: v16);
  LODWORD(v17) = idDeviceContext::TextHeight(this: &v157, scale: 0.30000001);
  HIDWORD(v17) = this->__vftable;
  v18 = (float)v17;
  v19 = this->TreeDepth(this, a2: v6);
  if ( blendTree_panZoomNodeWidth.valueFloat == 0.0 )
  {
    v20 = idGameAnimToolsLocal::TreeMaxNodeWidth_r(this, context: &v157, node: v6);
    LODWORD(v21) = &joystick.joyAxis[0][2];
    DWORD2(v21) = v20 + 4;
    DWORD1(v21) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
    this->nodeWidth = (float)*(__int64 *)((char *)&v21 + 4);
    HIDWORD(v21) = idMD6Blend::blendOpNames;
    *(const char **)&v22 = idMD6Blend::blendOpNames[6];
    v23 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[1],
            a3: v22,
            a4: *(__int64 *)&v21,
            a5: v21,
            a6: v115,
            a7: v122,
            a8: v129,
            a9: v136,
            a10: v143,
            a11: v150);
    v25 = idDeviceContext::TextWidth(
            this: &v157,
            scale: 0.30000001,
            text: v24,
            limit: (const unsigned __int8 *)v23,
            a5: 0);
    LODWORD(v26) = v25;
    _FP7 = (float)(this->nodeWidth
                 - (float)__SPAIR64__(&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor', v25));
    __asm { fsel      f6, f7, f11, f8 }
    this->nodeWidth = _FP6;
    *(const char **)&v26 = idMD6Blend::originBlendNames[0];
    v31 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[2],
            a3: v26,
            a4: v30,
            a5: v29,
            a6: v116,
            a7: v123,
            a8: v130,
            a9: v137,
            a10: v144,
            a11: v151);
    HIDWORD(v33) = idDeviceContext::TextWidth(
                     this: &v157,
                     scale: 0.30000001,
                     text: v32,
                     limit: (const unsigned __int8 *)v31,
                     a5: 0);
    LODWORD(v33) = HIDWORD(v33);
    HIDWORD(v34) = 1000;
    _FP1 = (float)(this->nodeWidth - (float)v33);
    __asm { fsel      f0, f1, f5, f2 }
    this->nodeWidth = _FP0;
    v39 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[3],
            a3: v34,
            a4: v38,
            a5: v37,
            a6: v117,
            a7: v124,
            a8: v131,
            a9: v138,
            a10: v145,
            a11: v152);
    LODWORD(v41) = idDeviceContext::TextWidth(
                     this: &v157,
                     scale: 0.30000001,
                     text: v40,
                     limit: (const unsigned __int8 *)v39,
                     a5: 0);
    _FP9 = (float)(this->nodeWidth - (float)v41);
    __asm { fsel      f8, f9, f13, f10 }
    this->nodeWidth = _FP8;
    v47 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[4],
            a3: v46,
            a4: v45,
            a5: v44,
            a6: v118,
            a7: v125,
            a8: v132,
            a9: v139,
            a10: v146,
            a11: v153);
    v49 = idDeviceContext::TextWidth(
            this: &v157,
            scale: 0.30000001,
            text: v48,
            limit: (const unsigned __int8 *)v47,
            a5: 0);
    _FP3 = (float)(this->nodeWidth
                 - (float)__SPAIR64__(&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor', v49));
    __asm { fsel      f2, f3, f7, f4 }
    this->nodeWidth = _FP2;
    *(const char **)&v52 = idMD6Leaf::wrapModeNames[0];
    v54 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[5],
            a3: v52,
            a4: v53,
            a5: __SPAIR64__(&idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor', v49),
            a6: v119,
            a7: v126,
            a8: v133,
            a9: v140,
            a10: v147,
            a11: v154);
    v56 = idDeviceContext::TextWidth(
            this: &v157,
            scale: 0.30000001,
            text: v55,
            limit: (const unsigned __int8 *)v54,
            a5: 0);
    HIDWORD(v57) = 0x40000000;
    _FP10 = (float)(this->nodeWidth - (float)__SPAIR64__("Could not find AI state, idVS_ds_Car_Chase! ", v56));
    __asm { fsel      f9, f10, f0, f11 }
    this->nodeWidth = _FP9;
    v61 = va::va(
            this: &v158,
            fmt: idGameAnimToolsLocal::TEXT_LINES[6],
            a3: v57,
            a4: __SPAIR64__("Could not find AI state, idVS_ds_Car_Chase! ", v56),
            a5: v60,
            a6: v120,
            a7: v127,
            a8: v134,
            a9: v141,
            a10: v148,
            a11: v155);
    LODWORD(v63) = idDeviceContext::TextWidth(
                     this: &v157,
                     scale: 0.30000001,
                     text: v62,
                     limit: (const unsigned __int8 *)v61,
                     a5: 0);
    _FP4 = (float)(this->nodeWidth - (float)v63);
    __asm { fsel      f3, f4, f8, f5 }
    this->nodeWidth = _FP3;
  }
  else
  {
    this->nodeWidth = blendTree_panZoomNodeWidth.valueFloat;
  }
  v67 = (idDeviceContext::TextHeight(this: &v157, scale: 0.30000001) + 1) * MAX_ROWS;
  gui = v157.gui;
  HIDWORD(v69) = v67 + 1;
  LODWORD(v70) = v67 + 1;
  this->nodeHeight = (float)v70;
  if ( blendTree_panZoomEnable.valueInteger != 0 )
  {
    LODWORD(v71) = &ai_useTurnTransitions.valueString.baseBuffer[12];
    HIDWORD(v71) = &ai_useTurnTransitions.valueString.baseBuffer[12];
    _FP12 = (float)(blendTree_panZoomScale.valueFloat - (float)0.0099999998);
    valueFloat = blendTree_panZoomXOffset.valueFloat;
    v74 = blendTree_panZoomYOffset.valueFloat;
    __asm { fsel      f30, f12, f0, f13 }
    VirtualWidth = idRenderModelGui::GetVirtualWidth(this: gui, a2: v68, a3: (int)&blendTree_panZoomYOffset, a4: v71);
    v77 = 0.5;
    v78 = (float)((float)((float)((float)VirtualWidth * (float)((float)((float)1.0 / (float)_FP30) / v157.uiScale.x))
                        * (float)0.5)
                + (float)valueFloat);
    VirtualHeight = idRenderModelGui::GetVirtualHeight(this: v157.gui, a2: v81, a3: v80, a4: v79);
    v84 = (float)((float)((float)((float)VirtualHeight * (float)((float)((float)1.0 / (float)_FP30) / v157.uiScale.y))
                        * (float)0.5)
                + (float)v74);
    if ( blendTree_panZoomFixedDepth.valueInteger > 0 )
      LOBYTE(v19) = blendTree_panZoomFixedDepth.valueInteger;
  }
  else
  {
    v92 = 1.0;
    v93 = 1.0;
    LODWORD(v69) = 2 * (1 << v19) - 1;
    v94 = (float)((float)v69 * this->nodeWidth);
    v98 = idRenderModelGui::GetVirtualWidth(this: gui, a2: v68, a3: SHIDWORD(v70), a4: v69);
    if ( v94 > (float)((float)v98 / v157.uiScale.x) )
    {
      v99 = idRenderModelGui::GetVirtualWidth(this: v157.gui, a2: v97, a3: v96, a4: v95);
      v92 = (float)((float)v99 * (float)((float)((float)1.0 / (float)v94) / v157.uiScale.x));
    }
    LODWORD(v95) = v19 + 1;
    v100 = 32 * v19;
    v101 = (float)((float)((float)((float)v95 * this->nodeHeight) + (float)*(__int64 *)((char *)&v95 - 4)) + (float)v18);
    v105 = idRenderModelGui::GetVirtualHeight(this: v157.gui, a2: v97, a3: v96, a4: v95);
    if ( v101 > (float)((float)v105 / v157.uiScale.y) )
    {
      v106 = idRenderModelGui::GetVirtualHeight(this: v157.gui, a2: v104, a3: v103, a4: v102);
      v93 = (float)((float)v106 * (float)((float)((float)1.0 / (float)v101) / v157.uiScale.y));
    }
    _FP0 = (float)((float)v92 - (float)v93);
    __asm { fsel      f30, f0, f29, f27 }
    v111 = idRenderModelGui::GetVirtualWidth(this: v157.gui, a2: v104, a3: v103, a4: v102);
    v77 = 0.5;
    if ( _FP30 == 1.0 )
    {
      v78 = (float)((float)((float)v111 / v157.uiScale.x) * (float)0.5);
      v113 = idRenderModelGui::GetVirtualHeight(this: v157.gui, a2: v110, a3: v109, a4: v108);
      v84 = (float)((float)((float)((float)v113 / v157.uiScale.y) - (float)v101) * (float)0.5);
    }
    else
    {
      v78 = (float)((float)((float)v111 * (float)((float)((float)1.0 / (float)_FP30) / v157.uiScale.x)) * (float)0.5);
      v112 = idRenderModelGui::GetVirtualHeight(this: v157.gui, a2: v110, a3: v109, a4: v108);
      v84 = (float)((float)((float)((float)v112 * (float)((float)((float)1.0 / (float)_FP30) / v157.uiScale.y))
                          - (float)v101)
                  * (float)0.5);
    }
  }
  v157.uiScale.x = _FP30;
  v157.uiScale.y = _FP30;
  LODWORD(v85) = idDeviceContext::TextWidth(
                   this: &v157,
                   scale: 0.30000001,
                   text: v82,
                   limit: (const unsigned __int8 *)v156.data,
                   a5: 0);
  idDeviceContext::DrawTextA(
    this: &v157,
    x: (float)-(float)((float)((float)v85 * (float)v77) - (float)v78),
    y: v84,
    scale: 0.30000001,
    color: v88,
    text: v87,
    a7: v86,
    a8: (const idVec4 *)&this->textColor,
    a9: (const unsigned __int8 *)v156.data);
  idGameAnimToolsLocal::DrawTree_r(
    this,
    context: &v157,
    x: v78,
    y: (float)((float)v18 + (float)v84),
    node: v90,
    depth: v89,
    a7: &v6->type,
    a8: v19);
  guiModel = this->guiModel;
  idStr::FreeData(this: &v156);
  return guiModel;
}


// ========================================================================
// __unwind$489498
// EA  : 0x82B35DAC
// RVA : 0x00B35DAC
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_489498()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 9728 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$489499
// EA  : 0x82B35DD8
// RVA : 0x00B35DD8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void _unwind_489499()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9728 + 96));
}


// ========================================================================
// `dynamic initializer for 'blendTree_x''
// EA  : 0x8336C5B8
// RVA : 0x0136C5B8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_x__()
{
  idCVar::idCVar(
    this: &blendTree_x,
    name: "blendTree_x",
    value: "0",
    flags: 4,
    description: "x offset for blend tree rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_x__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_y''
// EA  : 0x8336C610
// RVA : 0x0136C610
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_y__()
{
  idCVar::idCVar(
    this: &blendTree_y,
    name: "blendTree_y",
    value: "0",
    flags: 4,
    description: "y offset for blend tree rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_y__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_scale''
// EA  : 0x8336C668
// RVA : 0x0136C668
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_scale__()
{
  idCVar::idCVar(
    this: &blendTree_scale,
    name: "blendTree_scale",
    value: "1.0f",
    flags: 4,
    description: "scale multiplier form blend tree rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_scale__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomEnable''
// EA  : 0x8336C6C0
// RVA : 0x0136C6C0
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomEnable__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomEnable,
    name: "blendTree_panZoomEnable",
    value: "0",
    flags: 1,
    description: "disables dynamic sizing and instead allows panning and zooming around the blend tree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomEnable__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomNodeWidth''
// EA  : 0x8336C718
// RVA : 0x0136C718
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomNodeWidth__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomNodeWidth,
    name: "blendTree_panZoomNodeWidth",
    value: "0",
    flags: 4,
    description: "fixed node width for pan and zoom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomNodeWidth__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomXOffset''
// EA  : 0x8336C770
// RVA : 0x0136C770
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomXOffset__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomXOffset,
    name: "blendTree_panZoomXOffset",
    value: "0",
    flags: 4,
    description: "additional x offset for pan and zoom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomXOffset__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomYOffset''
// EA  : 0x8336C7C8
// RVA : 0x0136C7C8
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomYOffset__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomYOffset,
    name: "blendTree_panZoomYOffset",
    value: "0",
    flags: 4,
    description: "additional y offset for pan and zoom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomYOffset__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomScale''
// EA  : 0x8336C820
// RVA : 0x0136C820
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomScale__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomScale,
    name: "blendTree_panZoomScale",
    value: "1",
    flags: 4,
    description: "scale value for pan and zoom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomScale__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_panZoomFixedDepth''
// EA  : 0x8336C878
// RVA : 0x0136C878
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_panZoomFixedDepth__()
{
  idCVar::idCVar(
    this: &blendTree_panZoomFixedDepth,
    name: "blendTree_panZoomFixedDepth",
    value: "0",
    flags: 2,
    description: "allows a fixed depth to be specified, to prevent dynamic resizing of blend tree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_panZoomFixedDepth__);
}


// ========================================================================
// `dynamic initializer for 'blendTree_maxNodeSpacing''
// EA  : 0x8336C8D0
// RVA : 0x0136C8D0
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__blendTree_maxNodeSpacing__()
{
  idCVar::idCVar(
    this: &blendTree_maxNodeSpacing,
    name: "blendTree_maxNodeSpacing",
    value: "100",
    flags: 4,
    description: "maximum distance to offset nodes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__blendTree_maxNodeSpacing__);
}


// ========================================================================
// `dynamic initializer for 'gameAnimToolsLocal''
// EA  : 0x8336C928
// RVA : 0x0136C928
// PDB : w:\tech5\tungsten\game\animation\gameanimtools.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gameAnimToolsLocal__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gameAnimToolsLocal__);
}

