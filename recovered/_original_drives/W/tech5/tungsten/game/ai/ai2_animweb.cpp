
// ========================================================================
// ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@@Z
// EA  : 0x82A32EC0
// RVA : 0x00A32EC0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

int __fastcall idAI2::ChangeAnimState(
        idAI2 *this,
        const aiAnimWeb_t web,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend)
{
  return idAnimator_AnimWeb::ChangeState(
           this: &this->aiVolatile.animation.animWebAnimator.ptr[web],
           subWebIndex,
           stateIndex,
           interruptPath_: interruptPath,
           interruptBlend_: interruptBlend,
           blendEventMask_: 0);
}


// ========================================================================
// ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@12W4interruptPath_t@@W4interruptBlend_t@@@Z
// EA  : 0x82A32EF0
// RVA : 0x00A32EF0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

int __fastcall idAI2::ChangeAnimStateVia(
        idAI2 *this,
        const aiAnimWeb_t web,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *viaSubWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *viaStateIndex,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend)
{
  return idAnimator_AnimWeb::ChangeStateVia(
           this: &this->aiVolatile.animation.animWebAnimator.ptr[web],
           subWebIndex_: subWebIndex,
           stateIndex_: stateIndex,
           _viaSubWebIndex: viaSubWebIndex,
           _viaStateIndex: viaStateIndex,
           interruptPath_: interruptPath,
           interruptBlend_: interruptBlend,
           blendEventMask_: 0);
}


// ========================================================================
// ?GetWeaponPrefix@idAI2@@QBAXPBVidWeapon@@AAVidStr@@@Z
// EA  : 0x82A32F48
// RVA : 0x00A32F48
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetWeaponPrefix(idAI2 *this, const idWeapon *weapon, idStr *subWebPrefix)
{
  const idDeclInventory *decl; // r29
  size_t guiModel; // r31
  idAmmoItem *ammoClip; // r11
  const idStr *p_data; // r4

  idStr::operator=(this: subWebPrefix, text: "hands_");
  if ( weapon != nullptr )
  {
    decl = weapon->decl;
    guiModel = (size_t)decl[1].guiModel;
    idStr::EnsureAlloced(this: subWebPrefix, amount: guiModel + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: subWebPrefix->data, Src: (const void *)LODWORD(decl[1].thirdPersonScale), Size: guiModel);
    subWebPrefix->data[guiModel] = 0;
    subWebPrefix->len = guiModel;
    ammoClip = weapon->ammoClip;
    if ( ammoClip != nullptr )
    {
      p_data = (const idStr *)&ammoClip->decl[1].internalName.data;
      if ( p_data->len != 0 )
        idStr::operator=(this: subWebPrefix, text: p_data);
    }
  }
}


// ========================================================================
// ?GetWeaponPrefix@idAI2@@QBAXAAVidStr@@@Z
// EA  : 0x82A32FE0
// RVA : 0x00A32FE0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetWeaponPrefix(idAI2 *this, idStr *subWebPrefix)
{
  const idWeapon *v4; // r3

  v4 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v4, subWebPrefix);
}


// ========================================================================
// ?GetSubWebName@idAI2@@QBAXABVidStr@@AAV2@@Z
// EA  : 0x82A33040
// RVA : 0x00A33040
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetSubWebName(idAI2 *this, const idStr *inSubWebName, idStr *subWebName)
{
  int len; // r30
  int i; // r3
  idWeapon *v8; // r29
  const idDeclInventory *decl; // r28
  size_t guiModel; // r30
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *v12; // r10
  const idDeclInventory *v13; // r29
  size_t data; // r30
  idStr v15[4]; // [sp+60h] [-80h] BYREF

  len = inSubWebName->len;
  idStr::EnsureAlloced(this: subWebName, amount: inSubWebName->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: subWebName->data, Src: inSubWebName->data, Size: len);
  subWebName->data[len] = 0;
  subWebName->len = len;
  for ( i = idStr::Find(str: subWebName->data, c: 36, start: 0, end: len);
        i != -1;
        i = idStr::Find(str: subWebName->data, c: 36, start: 0, end: subWebName->len) )
  {
    if ( strstr(str1: &subWebName->data[i], str2: "$weapon") != nullptr )
    {
      v15[0].allocedAndFlag = 20;
      v15[0].len = 0;
      v15[0].data = v15[0].baseBuffer;
      v15[0].baseBuffer[0] = 0;
      v8 = this->GetEquippedWeapon(this);
      idStr::operator=(this: v15, text: "hands_");
      if ( v8 != nullptr )
      {
        decl = v8->decl;
        guiModel = (size_t)decl[1].guiModel;
        idStr::EnsureAlloced(this: v15, amount: guiModel + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v15[0].data, Src: (const void *)LODWORD(decl[1].thirdPersonScale), Size: guiModel);
        v15[0].data[guiModel] = 0;
        v15[0].len = guiModel;
        ammoClip = v8->ammoClip;
        if ( ammoClip != nullptr )
        {
          v12 = ammoClip->decl;
          if ( v12[1].internalName.data != nullptr )
          {
            v13 = ammoClip->decl;
            data = (size_t)v12[1].internalName.data;
            idStr::EnsureAlloced(this: v15, amount: data + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: v15[0].data, Src: (const void *)v13[1].internalName.allocedAndFlag, Size: data);
            v15[0].data[data] = 0;
            v15[0].len = data;
          }
        }
      }
      idStr::Replace(this: subWebName, old: "$weapon", nw: v15[0].data);
      idStr::FreeData(this: v15);
    }
  }
}


// ========================================================================
// __unwind$488286
// EA  : 0x82A331FC
// RVA : 0x00A331FC
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_488286()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?GetSubWebAndStateFromAnimWebPath@idAI2@@QBA_NPBDAAVidStr@@1@Z
// EA  : 0x82A33230
// RVA : 0x00A33230
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

int __fastcall idAI2::GetSubWebAndStateFromAnimWebPath(
        idAI2 *this,
        const char *animWebPath,
        idStr *subWebName,
        idStr *stateName)
{
  int len; // r6
  char *data; // r3
  int i; // r28
  const idWeapon *v11; // r3
  const char *v12; // r3
  int j; // r28
  const idWeapon *v14; // r3
  const char *v15; // r3
  _DWORD v17[4]; // [sp+50h] [-F0h] BYREF
  idStr v18; // [sp+60h] [-E0h] BYREF
  idStr v19; // [sp+80h] [-C0h] BYREF
  idStr v20; // [sp+A0h] [-A0h] BYREF
  idStr v21[4]; // [sp+C0h] [-80h] BYREF

  v18.len = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.baseBuffer[0] = 0;
  idStr::idStr(this: v21, text: animWebPath);
  idStr::ReplaceChar(this: v21, oldChar: 58, newChar: 47);
  idAnimWebPath::SplitPath(path: v21[0].data, webName: &v18, subWebName, stateName);
  len = subWebName->len;
  if ( subWebName->len != 0 )
  {
    data = subWebName->data;
    v17[0] = subWebName->len;
    for ( i = idStr::Find(str: data, c: 36, start: 0, end: len);
          i != -1;
          i = idStr::Find(str: subWebName->data, c: 36, start: 0, end: subWebName->len) )
    {
      if ( strstr(str1: &subWebName->data[i], str2: "$weapon") != nullptr )
      {
        v19.allocedAndFlag = 20;
        v19.len = 0;
        v19.data = v19.baseBuffer;
        v19.baseBuffer[0] = 0;
        v11 = this->GetEquippedWeapon(this);
        idAI2::GetWeaponPrefix(this, weapon: v11, subWebPrefix: &v19);
        idStr::Replace(this: subWebName, old: "$weapon", nw: v19.data);
        idStr::FreeData(this: &v19);
      }
      else
      {
        if ( strstr(str1: &subWebName->data[i], str2: "$subweb") == nullptr )
        {
LABEL_16:
          idLib::Warning(fmt: "Unknown variable name in anim web path '%s'", animWebPath);
          idStr::FreeData(this: v21);
          idStr::FreeData(this: &v18);
          return 0;
        }
        idAnimator_AnimWeb::GetCurSubWebIndex(
          this: (idAnimator_AnimWeb *)v17,
          result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&this->aiVolatile.animation);
        v12 = idDeclAnimWeb::GetSubWebName(
                this: this->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v17[0]));
        idStr::Replace(this: subWebName, old: "$subweb", nw: v12);
      }
    }
  }
  for ( j = idStr::Find(str: stateName->data, c: 36, start: 0, end: stateName->len);
        j != -1;
        j = idStr::Find(str: subWebName->data, c: 36, start: 0, end: subWebName->len) )
  {
    if ( strstr(str1: &stateName->data[j], str2: "$weapon") != nullptr )
    {
      v20.allocedAndFlag = 20;
      v20.len = 0;
      v20.data = v20.baseBuffer;
      v20.baseBuffer[0] = 0;
      v14 = this->GetEquippedWeapon(this);
      idAI2::GetWeaponPrefix(this, weapon: v14, subWebPrefix: &v20);
      idStr::Replace(this: stateName, old: "$weapon", nw: v20.data);
      idStr::FreeData(this: &v20);
    }
    else
    {
      if ( strstr(str1: &stateName->data[j], str2: "$state") == nullptr )
        goto LABEL_16;
      idAnimator_AnimWeb::GetCurStateIndex(
        this: (idAnimator_AnimWeb *)v17,
        result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)&this->aiVolatile.animation);
      v15 = idDeclAnimWeb::GetStateName(
              this: this->aiVolatile.animation.animWebAnimator.ptr[0].decl,
              index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(v17[0]));
      idStr::Replace(this: stateName, old: "$state", nw: v15);
    }
  }
  idStr::FreeData(this: v21);
  idStr::FreeData(this: &v18);
  return 1;
}


// ========================================================================
// __unwind$488502
// EA  : 0x82A33510
// RVA : 0x00A33510
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_488502()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$488503
// EA  : 0x82A33538
// RVA : 0x00A33538
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_488503()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 192));
}


// ========================================================================
// __unwind$488504
// EA  : 0x82A33560
// RVA : 0x00A33560
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_488504()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$488505
// EA  : 0x82A33588
// RVA : 0x00A33588
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_488505()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// ?GetAnimForAnimWebNode@idAI2@@QBAPBVidMD6Anim@@ABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A335B0
// RVA : 0x00A335B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

const idMD6Anim *__fastcall idAI2::GetAnimForAnimWebNode(
        idAI2 *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r31
  idDeclAnimWebNode *v5; // r11
  idDeclAnimWebNode::idModelInfo *list; // r11
  idMD6AnimProps *v8; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  __int16 v10; // [sp+50h] [-20h] BYREF

  p_animation = &this->aiVolatile.animation;
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v10,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)swi->value,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)si->value);
  if ( v10 == -1 )
    return nullptr;
  v5 = p_animation->animWebAnimator.ptr[0].decl->nodes.list[v10];
  if ( v5 == nullptr )
    return nullptr;
  if ( v5->modelInfo.num <= 0 )
    return nullptr;
  list = v5->modelInfo.list;
  if ( list == nullptr )
    return nullptr;
  v8 = nullptr;
  if ( list->animProps.num > 0 )
    v8 = list->animProps.list;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  return idMD6AnimProps::SelectAnim(this: v8, declMD6: TreeAnimatorFromPresentable->decl, index: 0);
}


// ========================================================================
// ?GetAnimForAnimWebNodeIndex@idAI2@@QBAPBVidMD6Anim@@ABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x82A33678
// RVA : 0x00A33678
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

const idMD6Anim *__fastcall idAI2::GetAnimForAnimWebNodeIndex(
        idAI2 *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si,
        int index)
{
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r30
  idDeclAnimWebNode *v7; // r11
  idDeclAnimWebNode::idModelInfo *list; // r10
  idMD6AnimProps *v10; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  __int16 v12; // [sp+50h] [-30h] BYREF

  p_animation = &this->aiVolatile.animation;
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v12,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)swi->value,
    stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)si->value);
  if ( v12 == -1 )
    return nullptr;
  v7 = p_animation->animWebAnimator.ptr[0].decl->nodes.list[v12];
  if ( v7 == nullptr )
    return nullptr;
  if ( v7->modelInfo.num <= 0 )
    return nullptr;
  list = v7->modelInfo.list;
  if ( list == nullptr )
    return nullptr;
  v10 = index < 0 || index >= list->animProps.num ? nullptr : &list->animProps.list[index];
  if ( v10 == nullptr )
    return nullptr;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  return idMD6AnimProps::SelectAnim(this: v10, declMD6: TreeAnimatorFromPresentable->decl, index: 0);
}


// ========================================================================
// ?GetCurrentSubWebAndStateIndices@idAI2@@QBAXAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A33750
// RVA : 0x00A33750
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetCurrentSubWebAndStateIndices(
        idAI2 *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  int value; // r10
  idDeclAnimWebNode *v4; // r11

  value = this->aiVolatile.animation.animWebAnimator.ptr[0].curNodeIndex.value;
  if ( value != -1 )
  {
    v4 = this->aiVolatile.animation.animWebAnimator.ptr[0].decl->nodes.list[value];
    if ( v4 != nullptr )
    {
      swi->value = (__int16)v4->subWebIndex;
      si->value = (__int16)v4->states.stateIndex[0];
    }
  }
}


// ========================================================================
// ?GetSubWebPrefix@idAI2@@QBAXPBVidWeapon@@W4aiSubWeb_t@@AAVidStr@@@Z
// EA  : 0x82A33798
// RVA : 0x00A33798
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetSubWebPrefix(idAI2 *this, const idWeapon *weapon, int swt, idStr *subWebPrefix)
{
  if ( swt < 23 )
  {
    idAI2::GetWeaponPrefix(this, weapon, subWebPrefix);
    idStr::Append(this: subWebPrefix, text: (char *)aiSubWebNames[swt]);
  }
}


// ========================================================================
// ?GetSubWebPrefix@idAI2@@QBAXW4aiSubWeb_t@@AAVidStr@@@Z
// EA  : 0x82A337F8
// RVA : 0x00A337F8
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetSubWebPrefix(idAI2 *this, const aiSubWeb_t swt, idStr *subWebPrefix)
{
  const idWeapon *v6; // r3

  v6 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v6, subWebPrefix);
  idStr::Append(this: subWebPrefix, text: (char *)aiSubWebNames[swt]);
}


// ========================================================================
// ?GetSubWebPrefix@idAI2@@QBAXAAVidStr@@@Z
// EA  : 0x82A33850
// RVA : 0x00A33850
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetSubWebPrefix(idAI2 *this, idStr *subWebPrefix)
{
  aiSubWeb_t subWeb; // r29
  const idWeapon *v5; // r3

  subWeb = this->aiVolatile.animation.subWeb;
  v5 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v5, subWebPrefix);
  idStr::Append(this: subWebPrefix, text: (char *)aiSubWebNames[subWeb]);
}


// ========================================================================
// ?GetMovementStateName@idAI2@@QBAXAAVidStr@@@Z
// EA  : 0x82A338B0
// RVA : 0x00A338B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetMovementStateName(idAI2 *this, idStr *name)
{
  walkState_t v4; // r28
  idAI2_vtbl *v5; // r11
  int v6; // r3
  int v7; // r27
  posture_t v8; // r3

  v4 = this->GetWalkState(this);
  v5 = this->__vftable;
  if ( v4 == WALKSTATE_WALKING )
    v6 = v5->GetWalkModifier(this);
  else
    v6 = v5->GetRunModifier(this);
  v7 = v6;
  idStr::EnsureAlloced(this: name, amount: 1, keepold: true, geometricGrowth: false);
  *name->data = 0;
  name->len = 0;
  idStr::operator=(this: name, text: walkStateNames[v4]);
  if ( this->GetPosture(this) == POSTURE_CROUCHED && v4 == WALKSTATE_RUNNING )
  {
    idLib::Warning(fmt: "idAI2::GetMovementStateName trying to run while crouched, fixing to walk, try to resolve root cause");
    idStr::operator=(this: name, text: walkStateNames[1]);
  }
  v8 = this->GetPosture(this);
  idStr::Append(this: name, text: (char *)postureAnimStateNames[v8]);
  if ( v7 != 0 )
    idStr::Append(this: name, text: (char *)aiWalkModifierNames[v7]);
}


// ========================================================================
// ?GetIdleStateName@idAI2@@QBAXAAVidStr@@@Z
// EA  : 0x82A339D0
// RVA : 0x00A339D0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetIdleStateName(idAI2 *this, idStr *name)
{
  posture_t v4; // r3
  sitState_t sitState; // r11
  standState_t standState; // r11
  const char *v7; // r4
  posture_t v8; // r3
  char v9[264]; // [sp+50h] [-120h] BYREF

  v4 = this->GetPosture(this);
  if ( v4 > POSTURE_NONE )
  {
    if ( v4 <= POSTURE_CROUCHED )
    {
      standState = this->actorEditable.standState;
      if ( standState != STANDSTATE_DEFAULT )
      {
        idStr::snPrintf(dest: v9, size: 256, fmt: "idle%d", standState + 1);
        v7 = v9;
      }
      else
      {
        v7 = "idle";
      }
      idStr::operator=(this: name, text: v7);
      v8 = this->GetPosture(this);
      idStr::Append(this: name, text: (char *)postureAnimStateNames[v8]);
    }
    else if ( v4 == POSTURE_SITTING )
    {
      sitState = this->actorEditable.sitState;
      if ( sitState != SITSTATE_DEFAULT )
      {
        idStr::snPrintf(dest: v9, size: 256, fmt: "idle_sit%d", sitState + 1);
        idStr::operator=(this: name, text: v9);
      }
      else
      {
        idStr::operator=(this: name, text: "idle_sit");
      }
    }
  }
  idStr::Append(this: name, text: (char *)mentalStateAnimStateNames[this->actorEditable.mentalState]);
}


// ========================================================================
// ?GetIdleTurnStateName@idAI2@@QBAXW4turnDirection_t@@MPBVidDeclAITurnParms@@AAVidStr@@@Z
// EA  : 0x82A33AF8
// RVA : 0x00A33AF8
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetIdleTurnStateName(
        idAI2 *this,
        const turnDirection_t turnDir,
        double turnDeltaDot,
        const idDeclAITurnParms *turnParms,
        idStr *name,
        idStr *a6)
{
  char *v8; // r28
  char *v9; // r29
  posture_t v10; // r3

  if ( turnDir != TURN_NONE )
  {
    if ( turnDir == TURN_LEFT )
      v8 = "_left";
    else
      v8 = "_right";
    if ( turnDeltaDot < -0.70710677 && (*((_BYTE *)this->aiEditable.behaviors.decl + 428) & 2) != 0 )
      v9 = "_157";
    else
      v9 = &byte_8200D768;
    idStr::operator=(this: a6, text: name[2].data);
    idStr::Append(this: a6, text: v8);
    idStr::Append(this: a6, text: v9);
    v10 = this->GetPosture(this);
    idStr::Append(this: a6, text: (char *)postureAnimStateNames[v10]);
    idStr::Append(this: a6, text: (char *)turnAnimStateNames[this->actorEditable.turnState]);
    idStr::Append(this: a6, text: (char *)mentalStateAnimStateNames[this->actorEditable.mentalState]);
  }
  else
  {
    idAI2::GetIdleStateName(this, name: a6);
  }
}


// ========================================================================
// ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A33C10
// RVA : 0x00A33C10
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

int __fastcall idAI2::ChangeAnimState(
        idAI2 *this,
        const aiAnimWeb_t web,
        const aiSubWeb_t subWeb,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex)
{
  const idWeapon *v14; // r3
  char *v15; // r30
  int v17; // r30
  __int16 v18; // [sp+50h] [-80h] BYREF
  idStr v19[3]; // [sp+60h] [-70h] BYREF

  v19[0].len = 0;
  v19[0].allocedAndFlag = 20;
  v19[0].data = v19[0].baseBuffer;
  v19[0].baseBuffer[0] = 0;
  v14 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v14, subWebPrefix: v19);
  idStr::Append(this: v19, text: (char *)aiSubWebNames[subWeb]);
  v15 = (char *)this + 820 * web;
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v18,
    result: *((idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)v15 + 8250),
    subWebName: v19[0].data);
  if ( v18 >= 0 )
  {
    v17 = idAnimator_AnimWeb::ChangeState(
            this: (idAnimator_AnimWeb *)(v15 + 32960),
            subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v18,
            stateIndex,
            interruptPath_: interruptPath,
            interruptBlend_: interruptBlend,
            blendEventMask_: 0);
    if ( subWebIndex != nullptr )
      subWebIndex->value = v18;
    idStr::FreeData(this: v19);
    return v17;
  }
  else
  {
    idLib::Warning(
      fmt: "Subweb '%s' does not exist in animWeb '%s'",
      v19[0].data,
      *(const char **)(*((_DWORD *)v15 + 8250) + 8));
    idStr::FreeData(this: v19);
    return 0;
  }
}


// ========================================================================
// __unwind$489196
// EA  : 0x82A33D2C
// RVA : 0x00A33D2C
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?ChangeAnimState@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@PBDW4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A33D58
// RVA : 0x00A33D58
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

awPathResult_t __fastcall idAI2::ChangeAnimState(
        idAI2 *this,
        aiAnimWeb_t web,
        aiSubWeb_t subWeb,
        const char *stateName,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> **p_decl; // r28
  awPathResult_t result; // r3
  __int16 v18; // [sp+50h] [-60h] BYREF

  p_decl = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> **)&this->aiVolatile.animation.animWebAnimator.ptr[web].decl;
  idDeclAnimWeb::GetStateIndexForName(this: (idDeclAnimWeb *)&v18, result: *p_decl, name: stateName);
  if ( v18 >= 0 )
  {
    result = idAI2::ChangeAnimState(
               this,
               web,
               subWeb,
               stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v18,
               interruptPath,
               interruptBlend,
               subWebIndex);
    if ( stateIndex != nullptr )
      stateIndex->value = v18;
  }
  else
  {
    idLib::Warning(fmt: "State '%s' does not exist in animWeb '%s'", stateName, *(const char **)&(*p_decl)[4].value);
    return AWPATH_FAILED;
  }
  return result;
}


// ========================================================================
// ?FindAnimWebAndStateIndices@idAI2@@QBAXW4aiAnimWeb_t@@W4aiSubWeb_t@@PBD_NPBVidWeapon@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A33E18
// RVA : 0x00A33E18
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::FindAnimWebAndStateIndices(
        idAI2 *this,
        const aiAnimWeb_t web,
        __int32 subWeb,
        const char *stateName,
        const bool changeWeapon,
        const idWeapon *newWeapon,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex)
{
  _WORD v15[8]; // [sp+50h] [-80h] BYREF
  idStr v16[3]; // [sp+60h] [-70h] BYREF

  if ( stateIndex != nullptr )
  {
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)v15,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->aiVolatile.animation.animWebAnimator.ptr[web].decl,
      name: stateName);
    stateIndex->value = v15[0];
  }
  if ( subWebIndex != nullptr )
  {
    v16[0].len = 0;
    v16[0].allocedAndFlag = 20;
    v16[0].data = v16[0].baseBuffer;
    v16[0].baseBuffer[0] = 0;
    if ( changeWeapon )
      idAI2::GetSubWebPrefix(this, weapon: newWeapon, swt: subWeb, subWebPrefix: v16);
    else
      idAI2::GetSubWebPrefix(this, swt: (const aiSubWeb_t)subWeb, subWebPrefix: v16);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)v15,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->aiVolatile.animation.animWebAnimator.ptr[web].decl,
      subWebName: v16[0].data);
    subWebIndex->value = v15[0];
    idStr::FreeData(this: v16);
  }
}


// ========================================================================
// __unwind$489340
// EA  : 0x82A33EFC
// RVA : 0x00A33EFC
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489340()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@12W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@5@Z
// EA  : 0x82A33F30
// RVA : 0x00A33F30
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

int __fastcall idAI2::ChangeAnimStateVia(
        idAI2 *this,
        const aiAnimWeb_t web,
        const aiSubWeb_t subWeb,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const aiSubWeb_t viaSubWeb,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *viaStateIndex,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *viaSubWebIndex,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        __int16 *a28,
        int a29,
        __int16 *a30)
{
  const idWeapon *v38; // r3
  const idWeapon *v39; // r3
  char *v40; // r29
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **v41; // r30
  int v42; // r30
  __int16 v44; // [sp+50h] [-B0h] BYREF
  __int16 v45; // [sp+52h] [-AEh] BYREF
  idStr v46; // [sp+60h] [-A0h] BYREF
  idStr v47[4]; // [sp+80h] [-80h] BYREF

  v47[0].len = 0;
  v47[0].allocedAndFlag = 20;
  v47[0].data = v47[0].baseBuffer;
  v47[0].baseBuffer[0] = 0;
  v38 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v38, subWebPrefix: v47);
  idStr::Append(this: v47, text: (char *)aiSubWebNames[subWeb]);
  v46.allocedAndFlag = 20;
  v46.len = 0;
  v46.data = v46.baseBuffer;
  v46.baseBuffer[0] = 0;
  v39 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v39, subWebPrefix: &v46);
  idStr::Append(this: &v46, text: (char *)aiSubWebNames[viaSubWeb]);
  v40 = (char *)this + 820 * web;
  v41 = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)(v40 + 33000);
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v44,
    result: *((idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> **)v40 + 8250),
    subWebName: v47[0].data);
  if ( v44 < 0 )
    idLib::Warning(
      fmt: "idAI2::ChangeAnimStateVia - animweb '%s' has no subweb '%s'",
      *(const char **)&(*v41)[4].value,
      v47[0].data);
  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v45, result: *v41, subWebName: v46.data);
  if ( v45 < 0 )
    idLib::Warning(
      fmt: "idAI2::ChangeAnimStateVia - animweb '%s' has no subweb '%s'",
      *(const char **)&(*v41)[4].value,
      v46.data);
  v42 = idAnimator_AnimWeb::ChangeStateVia(
          this: (idAnimator_AnimWeb *)(v40 + 32960),
          subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v44,
          stateIndex_: stateIndex,
          _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v45,
          _viaStateIndex: viaStateIndex,
          interruptPath_: interruptPath,
          interruptBlend_: interruptBlend,
          blendEventMask_: 0);
  if ( a28 != nullptr )
    *a28 = v44;
  if ( a30 != nullptr )
    *a30 = v45;
  idStr::FreeData(this: &v46);
  idStr::FreeData(this: v47);
  return v42;
}


// ========================================================================
// __unwind$489407
// EA  : 0x82A340EC
// RVA : 0x00A340EC
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$489408
// EA  : 0x82A34114
// RVA : 0x00A34114
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?ChangeAnimStateVia@idAI2@@QAA?AW4awPathResult_t@@W4aiAnimWeb_t@@W4aiSubWeb_t@@PBD12W4interruptPath_t@@W4interruptBlend_t@@PAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@56@Z
// EA  : 0x82A34140
// RVA : 0x00A34140
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

awPathResult_t __fastcall idAI2::ChangeAnimStateVia(
        idAI2 *this,
        aiAnimWeb_t web,
        aiSubWeb_t subWeb,
        const char *stateName,
        aiSubWeb_t viaSubWeb,
        const char *viaStateName,
        interruptPath_t interruptPath,
        interruptBlend_t interruptBlend,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *viaSubWebIndex,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *viaStateIndex,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        __int16 *a28,
        int a29,
        __int16 *a30,
        int a31,
        __int16 *a32,
        int a33,
        __int16 *a34)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> **p_decl; // r31
  awPathResult_t result; // r3
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v44; // [sp+8h] [-B8h]
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v45; // [sp+Ch] [-B4h]
  int v46; // [sp+10h] [-B0h]
  int v47; // [sp+14h] [-ACh]
  int v48; // [sp+18h] [-A8h]
  int v49; // [sp+1Ch] [-A4h]
  int v50; // [sp+20h] [-A0h]
  int v51; // [sp+24h] [-9Ch]
  int v52; // [sp+28h] [-98h]
  int v53; // [sp+2Ch] [-94h]
  int v54; // [sp+30h] [-90h]
  int v55; // [sp+34h] [-8Ch]
  int v56; // [sp+38h] [-88h]
  int v57; // [sp+3Ch] [-84h]
  int v58; // [sp+40h] [-80h]
  int v59; // [sp+44h] [-7Ch]
  int v60; // [sp+48h] [-78h]
  int v61; // [sp+4Ch] [-74h]
  int v62; // [sp+50h] [-70h]
  int v63; // [sp+58h] [-68h]
  __int16 v64; // [sp+60h] [-60h] BYREF
  __int16 v65; // [sp+62h] [-5Eh] BYREF

  p_decl = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> **)&this->aiVolatile.animation.animWebAnimator.ptr[web].decl;
  idDeclAnimWeb::GetStateIndexForName(this: (idDeclAnimWeb *)&v64, result: *p_decl, name: stateName);
  if ( v64 < 0 )
    idLib::Warning(
      fmt: "idAI2::ChangeAnimStateVia - animweb '%s' has no state '%s'",
      *(const char **)&(*p_decl)[4].value,
      stateName);
  idDeclAnimWeb::GetStateIndexForName(this: (idDeclAnimWeb *)&v65, result: *p_decl, name: viaStateName);
  if ( v65 < 0 )
    idLib::Warning(
      fmt: "idAI2::ChangeAnimStateVia - animweb '%s' has no state '%s'",
      *(const char **)&(*p_decl)[4].value,
      viaStateName);
  result = idAI2::ChangeAnimStateVia(
             this,
             web,
             subWeb,
             stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v64,
             viaSubWeb,
             viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v65,
             interruptPath,
             interruptBlend,
             subWebIndex: v44,
             viaSubWebIndex: v45,
             a11: v46,
             a12: v47,
             a13: v48,
             a14: v49,
             a15: v50,
             a16: v51,
             a17: v52,
             a18: v53,
             a19: v54,
             a20: v55,
             a21: v56,
             a22: v57,
             a23: v58,
             a24: v59,
             a25: v60,
             a26: v61,
             a27: v62,
             a28,
             a29: v63,
             a30: a32);
  if ( a30 != nullptr )
    *a30 = v64;
  if ( a34 != nullptr )
    *a34 = v65;
  return result;
}


// ========================================================================
// ?ResetAnimState@idAI2@@QAAXW4aiAnimWeb_t@@W4aiSubWeb_t@@PBD@Z
// EA  : 0x82A34258
// RVA : 0x00A34258
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::ResetAnimState(
        idAI2 *this,
        const aiAnimWeb_t web,
        const aiSubWeb_t subWeb,
        const char *stateName)
{
  const idWeapon *v8; // r3
  int GameMs; // r3
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  v8 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v8, subWebPrefix: v10);
  idStr::Append(this: v10, text: (char *)aiSubWebNames[subWeb]);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_AnimWeb::Reset(
    this: &this->aiVolatile.animation.animWebAnimator.ptr[web],
    initialSubWebName: v10[0].data,
    initialStateName: stateName,
    curTime: GameMs);
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$489729
// EA  : 0x82A34314
// RVA : 0x00A34314
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489729()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetAnimWebGrenadeThrowNode@idAI2@@QBA_NW4aiAnimWeb_t@@W4aiSubWeb_t@@W4coverAction_t@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A34348
// RVA : 0x00A34348
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

BOOL __fastcall idAI2::GetAnimWebGrenadeThrowNode(
        idAI2 *this,
        const aiAnimWeb_t web,
        const aiSubWeb_t subWeb,
        const coverAction_t coverAction,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex)
{
  aiSubWeb_t v13; // r24
  const idWeapon *v14; // r3
  const char *v15; // r4
  posture_t v16; // r3
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *decl; // r30
  __int16 *SubWebIndexForName; // r3
  char *data; // r5
  __int16 *StateIndexForName; // r3
  __int16 v21; // r11
  __int16 *v22; // r3
  __int16 v23; // r11
  BOOL v24; // r30
  __int128 v26; // [sp+50h] [-A0h] BYREF
  idStr v27; // [sp+60h] [-90h] BYREF
  idStr v28[3]; // [sp+80h] [-70h] BYREF

  v28[0].len = 0;
  v28[0].allocedAndFlag = 20;
  v28[0].data = v28[0].baseBuffer;
  v28[0].baseBuffer[0] = 0;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v13 = this->aiVolatile.animation.subWeb;
  v14 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v14, subWebPrefix: v28);
  idStr::Append(this: v28, text: (char *)aiSubWebNames[v13]);
  if ( coverAction != COVERACTION_NONE )
  {
    switch ( coverAction )
    {
      case COVERACTION_FIRE_OVER:
      case COVERACTION_BLINDFIRE_OVER:
      case COVERACTION_PEEK_OVER:
        v15 = "grenade_throw_over";
        goto LABEL_7;
      case COVERACTION_FIRE_LEAN_LEFT:
      case COVERACTION_FIRE_STEP_LEFT:
      case COVERACTION_BLINDFIRE_LEFT:
      case COVERACTION_PEEK_LEFT:
        v15 = "grenade_throw_left";
        goto LABEL_7;
      case COVERACTION_FIRE_LEAN_RIGHT:
      case COVERACTION_FIRE_STEP_RIGHT:
      case COVERACTION_BLINDFIRE_RIGHT:
      case COVERACTION_PEEK_RIGHT:
        v15 = "grenade_throw_right";
        goto LABEL_7;
      default:
        break;
    }
  }
  else
  {
    v15 = "grenade_throw";
LABEL_7:
    idStr::operator=(this: &v27, text: v15);
  }
  v16 = this->GetPosture(this);
  idStr::Append(this: &v27, text: (char *)postureAnimStateNames[v16]);
  decl = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->aiVolatile.animation.animWebAnimator.ptr[web].decl;
  SubWebIndexForName = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                                    this: (idDeclAnimWeb *)&v26,
                                    result: decl,
                                    subWebName: v28[0].data);
  data = v27.data;
  swi->value = *SubWebIndexForName;
  StateIndexForName = (__int16 *)idDeclAnimWeb::GetStateIndexForName(
                                   this: (idDeclAnimWeb *)((char *)&v26 + 2),
                                   result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)decl,
                                   name: data);
  v21 = *StateIndexForName;
  si->value = *StateIndexForName;
  if ( (unsigned __int16)swi->value >= 0x8000u || v21 < 0 )
  {
    idStr::FreeData(this: &v27);
    idStr::FreeData(this: v28);
    return false;
  }
  else
  {
    v22 = (__int16 *)idDeclAnimWeb::FindNodeIndex(
                       this: (idDeclAnimWeb *)((char *)&v26 + 2),
                       result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
                       subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)swi->value,
                       stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)si->value);
    v23 = *v22;
    nodeIndex->value = *v22;
    v24 = v23 >= 0;
    idStr::FreeData(this: &v27);
    idStr::FreeData(this: v28);
    return v24;
  }
}


// ========================================================================
// __unwind$489810
// EA  : 0x82A34558
// RVA : 0x00A34558
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489810()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$489811
// EA  : 0x82A34580
// RVA : 0x00A34580
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?GetAnimWebNodeForOverride@idAI2@@QBA_NW4overrideAnim_t@@AAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A345B0
// RVA : 0x00A345B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

BOOL __fastcall idAI2::GetAnimWebNodeForOverride(
        idAI2 *this,
        const overrideAnim_t ot,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  bool v4; // r29
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r25
  overrideWebInfo_t *v9; // r30
  aiSubWeb_t subWeb; // r24
  const idWeapon *v11; // r3
  __int16 *StateIndexForName; // r3
  __int16 v13; // r11
  int v15; // [sp+50h] [-80h] BYREF
  idStr v16[3]; // [sp+60h] [-70h] BYREF

  v4 = false;
  v16[0].len = 0;
  v16[0].baseBuffer[0] = 0;
  v16[0].allocedAndFlag = 20;
  v16[0].data = v16[0].baseBuffer;
  p_animation = &this->aiVolatile.animation;
  v9 = &overrideWebInfo[ot];
  subWeb = v9->subWeb;
  v11 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v11, subWebPrefix: v16);
  idStr::Append(this: v16, text: (char *)aiSubWebNames[subWeb]);
  swi->value = (__int16)HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                                 this: (idDeclAnimWeb *)&v15,
                                 result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                                 subWebName: v16[0].data)->__vftable);
  StateIndexForName = (__int16 *)idDeclAnimWeb::GetStateIndexForName(
                                   this: (idDeclAnimWeb *)((char *)&v15 + 2),
                                   result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                                   name: v9->stateName);
  v13 = *StateIndexForName;
  si->value = *StateIndexForName;
  if ( (unsigned __int16)swi->value < 0x8000u )
    v4 = v13 >= 0;
  idStr::FreeData(this: v16);
  return v4;
}


// ========================================================================
// __unwind$489960
// EA  : 0x82A346A4
// RVA : 0x00A346A4
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_489960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?GetMovementSubWebAndStateIndices@idAI2@@QBAXAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A346D8
// RVA : 0x00A346D8
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void __fastcall idAI2::GetMovementSubWebAndStateIndices(
        idAI2 *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r28
  aiSubWeb_t subWeb; // r24
  const idWeapon *v8; // r3
  __int16 v9; // r3
  __int16 *StateIndexForName; // r3
  __int16 v11; // r11
  const idDeclAnimWeb *decl; // r11
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  va *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r6
  __int64 v19; // r8
  va *v20; // r3
  va *v21; // r3
  int v22; // [sp+8h] [-2128h]
  int v23; // [sp+8h] [-2128h]
  int v24; // [sp+Ch] [-2124h]
  int v25; // [sp+Ch] [-2124h]
  int v26; // [sp+10h] [-2120h]
  int v27; // [sp+10h] [-2120h]
  int v28; // [sp+14h] [-211Ch]
  int v29; // [sp+14h] [-211Ch]
  int v30; // [sp+18h] [-2118h]
  int v31; // [sp+18h] [-2118h]
  int v32; // [sp+1Ch] [-2114h]
  int v33; // [sp+1Ch] [-2114h]
  idDeclAnimWeb v34[15]; // [sp+50h] [-20E0h] BYREF
  va v35; // [sp+10E0h] [-1050h] BYREF

  v34[0].resourceListPtr = nullptr;
  v34[0].networkID = 20;
  v34[0].resourceError = (const char *)&v34[0].staleCount;
  HIBYTE(v34[0].staleCount) = 0;
  p_animation = &this->aiVolatile.animation;
  subWeb = this->aiVolatile.animation.subWeb;
  v8 = this->GetEquippedWeapon(this);
  idAI2::GetWeaponPrefix(this, weapon: v8, subWebPrefix: (idStr *)&v34[0].resourceListPtr);
  idStr::Append(this: (idStr *)&v34[0].resourceListPtr, text: (char *)aiSubWebNames[subWeb]);
  v9 = HIWORD(idDeclAnimWeb::GetSubWebIndexForName(
                this: v34,
                result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                subWebName: v34[0].resourceError)->__vftable);
  v34[0].nodes.list = (idDeclAnimWebNode **)20;
  *(_DWORD *)&v34[0].programaticallyDefined = 0;
  v34[0].declSource = (idDeclSource *)&v34[0].nodes.num;
  HIBYTE(v34[0].nodes.num) = 0;
  swi->value = v9;
  idAI2::GetMovementStateName(this, name: (idStr *)&v34[0].programaticallyDefined);
  StateIndexForName = (__int16 *)idDeclAnimWeb::GetStateIndexForName(
                                   this: v34,
                                   result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
                                   name: (const char *)v34[0].declSource);
  v11 = *StateIndexForName;
  si->value = *StateIndexForName;
  if ( (unsigned __int16)swi->value >= 0x8000u || v11 < 0 )
  {
    decl = p_animation->animWebAnimator.ptr[0].decl;
    if ( decl != nullptr )
    {
      v34[0].states.list = (idDeclAnimWeb::idStateInfo *)20;
      v34[0].subWebs.size = 0;
      *(_DWORD *)&v34[0].subWebs.granularity = &v34[0].states.num;
      HIBYTE(v34[0].states.num) = 0;
      idAnimWebPath::SetPath(
        this: (idAnimWebPath *)&v34[0].subWebs.size,
        webName: (char *)decl->name.str,
        subWebName: (char *)v34[0].resourceError,
        stateName: (char *)v34[0].declSource);
      HIDWORD(v13) = "ound traces";
      HIDWORD(v14) = *(_DWORD *)&v34[0].subWebs.granularity;
      v16 = va::va(
              this: (va *)&v34[0].edgeCache.size,
              fmt: "GetMovementSubWebAndStateIndices - invalid destination node for move '%s'. ",
              a3: v14,
              a4: v15,
              a5: v13,
              a6: v22,
              a7: v24,
              a8: v26,
              a9: v28,
              a10: v30,
              a11: v32);
      idStr::idStr(this: (idStr *)&v34[0].models.size, text: v16);
      LODWORD(v19) = (unsigned __int16)swi->value;
      if ( (unsigned int)v19 >= 0x8000 )
      {
        HIDWORD(v18) = v34[0].resourceError;
        v20 = va::va(
                this: &v35,
                fmt: "Subweb '%s' is not valid. ",
                a3: v18,
                a4: v19,
                a5: v17,
                a6: v23,
                a7: v25,
                a8: v27,
                a9: v29,
                a10: v31,
                a11: v33);
        idStr::Append(this: (idStr *)&v34[0].models.size, text: v20);
      }
      if ( (unsigned __int16)si->value >= 0x8000u )
      {
        HIDWORD(v18) = v34[0].resourceError;
        v21 = va::va(
                this: &v35,
                fmt: "State '%s' is not valid.",
                a3: v18,
                a4: v19,
                a5: v17,
                a6: v23,
                a7: v25,
                a8: v27,
                a9: v29,
                a10: v31,
                a11: v33);
        idStr::Append(this: (idStr *)&v34[0].models.size, text: v21);
      }
      idLib::Warning(fmt: *(const char **)&v34[0].models.granularity);
      idStr::FreeData(this: (idStr *)&v34[0].models.size);
      idStr::FreeData(this: (idStr *)&v34[0].subWebs.size);
    }
  }
  idStr::FreeData(this: (idStr *)&v34[0].programaticallyDefined);
  idStr::FreeData(this: (idStr *)&v34[0].resourceListPtr);
}


// ========================================================================
// __unwind$490272
// EA  : 0x82A348A8
// RVA : 0x00A348A8
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_490272()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8496 + 96));
}


// ========================================================================
// __unwind$490273
// EA  : 0x82A348D0
// RVA : 0x00A348D0
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_490273()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8496 + 128));
}


// ========================================================================
// __unwind$490274
// EA  : 0x82A348F8
// RVA : 0x00A348F8
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_490274()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8496 + 160));
}


// ========================================================================
// __unwind$490275
// EA  : 0x82A34920
// RVA : 0x00A34920
// PDB : w:\tech5\tungsten\game\ai\ai2_animweb.cpp
// ========================================================================

void _unwind_490275()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8496 + 192));
}

