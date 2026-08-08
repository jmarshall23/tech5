
// ========================================================================
// ?ArgCompletion_PlayTestModel@idTestModel2@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82CE2D18
// RVA : 0x00CE2D18
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::ArgCompletion_PlayTestModel(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "playtest/", a4: ".model", a5: false);
}


// ========================================================================
// ?ArgCompletion_Anim@idTestModel2@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82CE2D48
// RVA : 0x00CE2D48
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::ArgCompletion_Anim(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "md6/", a4: "md6anim", a5: false);
}


// ========================================================================
// ?tm_removeBlendVariable_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE2D78
// RVA : 0x00CE2D78
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_removeBlendVariable_f(const idCmdArgs *args)
{
  idGameLocal::CheckCheats(this: gameLocal, player: nullptr);
}


// ========================================================================
// ?GetOriginAxis@idTestModel2@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CE2D88
// RVA : 0x00CE2D88
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::GetOriginAxis(idTestModel2 *this, idVec3 *origin, idMat3 *axis)
{
  idTestModel2 *v3; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r28
  float *v9; // r11
  float *v10; // r11
  idPhysics *Physics; // r3
  float *v12; // r3
  idPhysics *v13; // r3
  float *v14; // r3

  v3 = this;
  if ( tm_modifyRenderModel.valueInteger == 0 )
    goto LABEL_11;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = v3->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v3);
    presentable = v3->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 == nullptr )
  {
    this = v3;
LABEL_11:
    Physics = idEntity::GetPhysics(this);
    v12 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    axis->mat[0].x = *v12;
    axis->mat[0].y = v12[1];
    axis->mat[0].z = v12[2];
    axis->mat[1].x = v12[3];
    axis->mat[1].y = v12[4];
    axis->mat[1].z = v12[5];
    axis->mat[2].x = v12[6];
    axis->mat[2].y = v12[7];
    axis->mat[2].z = v12[8];
    v13 = idEntity::GetPhysics(this: v3);
    v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
    origin->x = *v14;
    origin->y = v14[1];
    origin->z = v14[2];
    return;
  }
  v9 = (float *)v3->presentable;
  if ( v9 == nullptr )
  {
    idEntity::InitPresentableInternal(this: v3);
    v9 = (float *)v3->presentable;
  }
  axis->mat[0].x = v9[33];
  axis->mat[0].y = v9[34];
  axis->mat[0].z = v9[35];
  axis->mat[1].x = v9[36];
  axis->mat[1].y = v9[37];
  axis->mat[1].z = v9[38];
  axis->mat[2].x = v9[39];
  axis->mat[2].y = v9[40];
  axis->mat[2].z = v9[41];
  v10 = (float *)v3->presentable;
  if ( v10 == nullptr )
  {
    idEntity::InitPresentableInternal(this: v3);
    v10 = (float *)v3->presentable;
  }
  origin->x = v10[30];
  origin->y = v10[31];
  origin->z = v10[32];
}


// ========================================================================
// ?SetOriginAxis@idTestModel2@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82CE2F20
// RVA : 0x00CE2F20
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SetOriginAxis(idTestModel2 *this, const idVec3 *origin, const idMat3 *axis)
{
  idPhysics *Physics; // r3
  idPhysics *v7; // r3
  float *presentable; // r11
  idPresentable *v9; // r11

  if ( tm_modifyRenderModel.valueInteger != 0 )
  {
    presentable = (float *)this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = (float *)this->presentable;
    }
    presentable[33] = axis->mat[0].x;
    presentable[34] = axis->mat[0].y;
    presentable[35] = axis->mat[0].z;
    presentable[36] = axis->mat[1].x;
    presentable[37] = axis->mat[1].y;
    presentable[38] = axis->mat[1].z;
    presentable[39] = axis->mat[2].x;
    presentable[40] = axis->mat[2].y;
    presentable[41] = axis->mat[2].z;
    v9 = this->presentable;
    if ( v9 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    v9->origin.x = origin->x;
    v9->origin.y = origin->y;
    v9->origin.z = origin->z;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetAxis(this: Physics, a2: axis, a3: -1);
    v7 = idEntity::GetPhysics(this);
    v7->SetOrigin(this: v7, a2: origin, a3: -1);
  }
}


// ========================================================================
// ?UpdateFixed@idTestModel2@@AAAXXZ
// EA  : 0x82CE3030
// RVA : 0x00CE3030
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::UpdateFixed(idTestModel2 *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: v4, removeRotation: false);
    idTreeAnimator::SetRemoveOriginRotation(this: v4, removeRotation: false);
  }
}


// ========================================================================
// ?PlayVoiceOver@idTestModel2@@QAAXPBVidDeclVoiceOver@@@Z
// EA  : 0x82CE30A8
// RVA : 0x00CE30A8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::PlayVoiceOver(idTestModel2 *this, const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r29

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
  {
    idFaceMgr::Reset(this: &this->faceMgr, owner: this, ta: v6);
    idFaceMgr::StartVoiceOver(this: &this->faceMgr, owner: (idAI2 *)this, ta: v6, vo);
    idEntity::BecomeActive(this, flags: 4);
  }
  else
  {
    idLib::Warning(fmt: "Only animated models can play voice overs.");
  }
}


// ========================================================================
// ?GetModelTransform@idTestModel2@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CE3140
// RVA : 0x00CE3140
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::GetModelTransform(idTestModel2 *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  const idMat3 *v5; // r29
  idMat3 *v6; // r3
  idMat3 *v7; // r3
  idMat3 v8; // [sp+50h] [-F0h] BYREF
  idMat3 v9; // [sp+90h] [-B0h] BYREF
  idAngles v10[4]; // [sp+C0h] [-80h] BYREF
  idMat3 v11[2]; // [sp+F0h] [-50h] BYREF

  v8.mat[0].x = tm_pitchOffset.valueFloat;
  v8.mat[0].y = tm_yawOffset.valueFloat;
  v8.mat[0].z = tm_rollOffset.valueFloat;
  idTestModel2::GetOriginAxis(this, origin: modelOrigin, axis: modelAxis);
  v5 = idAngles::ToMat3(this: v10, result: &v8);
  v6 = idAngles::ToMat3(this: (idAngles *)&v8.mat[1].y, result: (idMat3 *)&this->rotationAngles);
  v7 = idMat3::operator*(this: &v9, result: v6, a: v5);
  *modelAxis = *idMat3::operator*(this: v11, result: v7, a: modelAxis);
}


// ========================================================================
// ?SetCurFrame@idTestModel2@@QAAXM@Z
// EA  : 0x82CE3218
// RVA : 0x00CE3218
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SetCurFrame(idTestModel2 *this, double frame)
{
  __int64 v4; // r10
  idMD6LeafPlay *LastPlayedLeaf; // r3
  const idMD6Anim *anim; // r11
  idMD6AnimData *v7; // r11
  double v8; // fp0

  LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
  if ( LastPlayedLeaf != nullptr )
  {
    anim = LastPlayedLeaf->anim;
    v7 = anim != nullptr ? anim->animData : nullptr;
    if ( v7 != nullptr )
    {
      LODWORD(v4) = v7->numFrames;
      v8 = 0.0;
      if ( frame >= (float)v4 )
      {
LABEL_9:
        this->curFrame = v8;
        return;
      }
      if ( frame < 0.0 )
      {
        v8 = (float)((float)v4 - (float)1.0);
        goto LABEL_9;
      }
      this->curFrame = frame;
    }
  }
}


// ========================================================================
// ?ParseAnimCommand@@YA_NABVidCmdArgs@@PBVidTestModel2@@PBVidTreeAnimator@@HAAVidNamedAnim@idAnimator_BlendEq@@AAI@Z
// EA  : 0x82CE32C8
// RVA : 0x00CE32C8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

int __fastcall ParseAnimCommand(
        const idCmdArgs *args,
        const idTestModel2 *curTestModel,
        const idTreeAnimator *ta,
        int startIndex,
        idAnimator_BlendEq::idNamedAnim *namedAnim,
        unsigned int *parseFlags)
{
  int argc; // r4
  int v10; // r30
  int v11; // r27
  const char **i; // r28
  const char *v13; // r3
  const char **v14; // r31
  unsigned __int8 v15; // r29
  const char *v16; // r16
  char *v17; // r3
  const char *v18; // r3
  const char **v19; // r31
  unsigned __int8 v20; // r29
  const char *v21; // r16
  char *v22; // r3
  const char *v23; // r3
  const char *v24; // r3
  long double v25; // fp2
  unsigned int v26; // r10
  char *v27; // r4
  const idMD6Anim *v28; // r3

  *parseFlags = 0;
  argc = args->argc;
  v10 = startIndex;
  if ( startIndex >= args->argc )
    return 1;
  v11 = startIndex + 1;
  for ( i = (const char **)&args->argv[startIndex]; ; ++i )
  {
    if ( v10 < 0 || v10 >= argc )
      v13 = &byte_8200D768;
    else
      v13 = *i;
    if ( idStr::Icmp(s1: v13, s2: "-wrap") == 0 )
    {
      if ( args->argc <= v11 )
      {
        idLib::Warning(fmt: "No value specified for -wrap");
        return 0;
      }
      v14 = idMD6Leaf::wrapModeNames;
      ++v10;
      ++v11;
      ++i;
      v15 = 0;
      while ( 1 )
      {
        v16 = *v14;
        v17 = idCmdArgs::Argv(this: args, arg: v10);
        if ( idStr::Icmp(s1: v17, s2: v16) == 0 )
          break;
        ++v14;
        ++v15;
        if ( (int)v14 >= (int)idMD6Branch::blendTypeNames )
          goto LABEL_43;
      }
      namedAnim->wrapMode = v15;
      *parseFlags |= 1u;
      goto LABEL_43;
    }
    v18 = v10 < 0 || v10 >= args->argc ? &byte_8200D768 : *i;
    if ( idStr::Icmp(s1: v18, s2: "-wg") != 0 )
      break;
    if ( args->argc <= v11 )
    {
      idLib::Warning(fmt: "No value specified for -wg");
      return 0;
    }
    v19 = idMD6Skel::weightGroupNames;
    ++v10;
    ++v11;
    ++i;
    v20 = 0;
    while ( 1 )
    {
      v21 = *v19;
      v22 = idCmdArgs::Argv(this: args, arg: v10);
      if ( idStr::Icmp(s1: v22, s2: v21) == 0 )
        break;
      ++v19;
      ++v20;
      if ( (int)v19 >= (int)&NULL_JOINT )
        goto LABEL_43;
    }
    namedAnim->weightGroup = v20;
    *parseFlags |= 2u;
LABEL_43:
    argc = args->argc;
    ++v10;
    ++v11;
    if ( v10 >= args->argc )
      return 1;
  }
  if ( v10 < 0 || v10 >= args->argc )
    v23 = &byte_8200D768;
  else
    v23 = *i;
  if ( idStr::Icmp(s1: v23, s2: "-rate") == 0 )
  {
    if ( args->argc <= v11 )
    {
      idLib::Warning(fmt: "No value specified for -rate");
      return 0;
    }
    ++v10;
    ++v11;
    ++i;
    if ( v10 < 0 || v10 >= args->argc )
      v24 = &byte_8200D768;
    else
      v24 = *i;
    v25 = atof(nptr: v24);
    namedAnim->rate = *(double *)&v25;
    v26 = *parseFlags | 4;
    goto LABEL_42;
  }
  if ( v10 < 0 || v10 >= args->argc )
    v27 = &byte_8200D768;
  else
    v27 = (char *)*i;
  v28 = (const idMD6Anim *)idResourceList::Load(
                             this: &idMD6Anim::resourceList,
                             name: v27,
                             makeDefault: true,
                             skipStaleCheck: false);
  namedAnim->anim = v28;
  if ( v28 != nullptr )
  {
    v26 = *parseFlags | 8;
LABEL_42:
    *parseFlags = v26;
    goto LABEL_43;
  }
  if ( v10 < 0 || v10 >= args->argc )
  {
    idLib::Warning(fmt: "Animation '%s' was not found", &byte_8200D768);
    return 0;
  }
  else
  {
    idLib::Warning(fmt: "Animation '%s' was not found", args->argv[v10]);
    return 0;
  }
}


// ========================================================================
// ?StartAnim@idTestModel2@@QAAXPBD_N@Z
// EA  : 0x82CE3600
// RVA : 0x00CE3600
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::StartAnim(idTestModel2 *this, char *name, const bool cycle)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r27
  idMD6LeafPlay *LastPlayedLeaf; // r30
  int v10; // r29
  int v11; // r3
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  bool IsPlaying; // r3
  char v17; // r11
  bool v18; // r24
  const idMD6Alias *Alias; // r30
  int v20; // r3
  const idMD6Anim *Existing; // r30
  int GameMs; // r29
  __int64 v23; // r8
  const idAnimStack *v24; // r3
  idPhysics *Physics; // r3
  idPhysics *v26; // r3
  idPresentable *v27; // r11
  float *v28; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v29[8]; // [sp+50h] [-80h] BYREF
  blendParms_t v30[5]; // [sp+60h] [-70h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
    if ( LastPlayedLeaf == nullptr
      || (v10 = gameLocal->GetGameMsPerRealSec(this: gameLocal),
          v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED),
          IsPlaying = idMD6LeafPlay::IsPlaying(
                        this: LastPlayedLeaf,
                        gameTime: v11,
                        ticksPerSec: v10,
                        a4: v15,
                        a5: v14,
                        a6: v13,
                        a7: v12),
          v17 = 1,
          !IsPlaying) )
    {
      v17 = 0;
    }
    v18 = v17;
    idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)v29, result: v8->decl, aliasName: name);
    if ( v29[0].value != 0xFFFF )
    {
      animation->StrongLoadAlias_2(this: animation, a2: v8->decl, a3: v29);
      Alias = idDeclMD6::FindAlias(this: v8->decl, aliasHandle: v29, includeInherited: true);
      if ( Alias == nullptr )
      {
        idLib::Warning(fmt: "ERROR: failed to look up alias handle");
        return;
      }
      v20 = idRandom2::RandomInt(this: &clientGame->random, max: Alias->animRefs.num);
      Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                      this: &idMD6Anim::resourceList,
                                      name: (char *)Alias->animRefs.list[v20].str,
                                      skipStaleCheck: true);
      if ( Existing != nullptr )
        goto LABEL_13;
    }
    Existing = (const idMD6Anim *)idResourceList::Load(
                                    this: &idMD6Anim::resourceList,
                                    name,
                                    makeDefault: true,
                                    skipStaleCheck: false);
    if ( Existing != nullptr )
    {
LABEL_13:
      blendParms_t::blendParms_t(this: v30);
      blendParms_t::SetDurationMS(this: v30, ms: tm_blendInTime.valueInteger);
      blendParms_t::SetDestStartFrame(this: v30, frame: 0);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v24 = this->GetAnimStack_2(this);
      if ( cycle )
      {
        LODWORD(v23) = v30;
        idAnimator_Channel::CycleAnim(
          this: &this->channelAnimator,
          stack: v24,
          ah: Existing,
          curTime: GameMs,
          rateScale: 1.0,
          leafStarted: v23,
          a7: nullptr);
      }
      else
      {
        idAnimator_Channel::PlayAnim(
          this: &this->channelAnimator,
          stack: v24,
          ah: Existing,
          curTime: GameMs,
          rateScale: 1.0,
          blendParms: (const blendParms_t *)HIDWORD(v23),
          blendOutDurationMS_: v30,
          leafStarted: nullptr,
          a9: nullptr);
      }
      Physics = idEntity::GetPhysics(this);
      Physics->SetOrigin(this: Physics, a2: &this->resetOrigin, a3: -1);
      v26 = idEntity::GetPhysics(this);
      v26->SetAxis(this: v26, a2: &this->resetAxis, a3: -1);
      v27 = this->presentable;
      if ( v27 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v27 = this->presentable;
      }
      v27->origin.x = this->resetOrigin.x;
      v27->origin.y = this->resetOrigin.y;
      v27->origin.z = this->resetOrigin.z;
      v28 = (float *)this->presentable;
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v28 = (float *)this->presentable;
      }
      v28[33] = this->resetAxis.mat[0].x;
      v28[34] = this->resetAxis.mat[0].y;
      v28[35] = this->resetAxis.mat[0].z;
      v28[36] = this->resetAxis.mat[1].x;
      v28[37] = this->resetAxis.mat[1].y;
      v28[38] = this->resetAxis.mat[1].z;
      v28[39] = this->resetAxis.mat[2].x;
      v28[40] = this->resetAxis.mat[2].y;
      v28[41] = this->resetAxis.mat[2].z;
      idEntity::BecomeActive(this, flags: 4);
      this->ignoreFirstDelta = v18;
      this->curLoopCount = 0;
      this->accumulatedDeltaTrans.z = 0.0;
      this->accumulatedDeltaTrans.y = 0.0;
      this->accumulatedDeltaTrans.x = 0.0;
      this->accumulatedDeltaRot = quat_identity;
    }
    else
    {
      idLib::Warning(fmt: "Could not find an alias or animation file named '%s'.", name);
    }
  }
}


// ========================================================================
// ?ArgCompletion_Model@idTestModel2@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82CE39B8
// RVA : 0x00CE39B8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::ArgCompletion_Model(idAutoComplete *autoComplete)
{
  int num; // r30
  int v3; // r29
  int v4; // r30
  int v5; // r29
  idStr v6; // [sp+50h] [-70h] BYREF
  idStr v7[2]; // [sp+70h] [-50h] BYREF

  num = idDeclMD6::resourceList.declSources.num;
  if ( idDeclMD6::resourceList.declSources.num > 0 )
  {
    v3 = 0;
    do
    {
      idStr::idStr(this: &v6, text: idDeclMD6::resourceList.declSources.list[v3]->name.str);
      idAutoComplete::Append(this: autoComplete, suggestion: &v6, completingArg: -1);
      idStr::FreeData(this: &v6);
      --num;
      ++v3;
    }
    while ( num != 0 );
  }
  v4 = idDeclParticle::resourceList.declSources.num;
  if ( idDeclParticle::resourceList.declSources.num > 0 )
  {
    v5 = 0;
    do
    {
      idStr::idStr(this: v7, text: idDeclParticle::resourceList.declSources.list[v5]->name.str);
      idAutoComplete::Append(this: autoComplete, suggestion: v7, completingArg: -1);
      idStr::FreeData(this: v7);
      --v4;
      ++v5;
    }
    while ( v4 != 0 );
  }
  cmdSystem->ArgCompletion_FolderExtension(
    this: cmdSystem,
    a2: autoComplete,
    a3: "models/;terrain/",
    a4: ".lwo|ase|obj|md6mesh",
    a5: false);
}


// ========================================================================
// __unwind$491934_0
// EA  : 0x82CE3AA4
// RVA : 0x00CE3AA4
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_491934_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$491935_0
// EA  : 0x82CE3ACC
// RVA : 0x00CE3ACC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_491935_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?ArgCompletion_VO@idTestModel2@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82CE3B00
// RVA : 0x00CE3B00
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::ArgCompletion_VO(idAutoComplete *autoComplete)
{
  int num; // r30
  int v3; // r29
  idStr v4[2]; // [sp+50h] [-50h] BYREF

  num = idDeclVoiceOver::resourceList.declSources.num;
  if ( idDeclVoiceOver::resourceList.declSources.num > 0 )
  {
    v3 = 0;
    do
    {
      idStr::idStr(this: v4, text: idDeclVoiceOver::resourceList.declSources.list[v3]->name.str);
      idAutoComplete::Append(this: autoComplete, suggestion: v4, completingArg: -1);
      idStr::FreeData(this: v4);
      --num;
      ++v3;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// __unwind$492025
// EA  : 0x82CE3B6C
// RVA : 0x00CE3B6C
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492025()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ??1idTestModel2@@UAA@XZ
// EA  : 0x82CE3DA8
// RVA : 0x00CE3DA8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::~idTestModel2(idTestModel2 *this)
{
  idAttachmentCollection *p_attachments; // r27
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v4; // r28
  int v5; // r29
  idAnimWebScalar *list; // r4
  idAnimator_BlendEq::idNamedAnim *v7; // r4
  float *scalarPtr; // [sp+50h] [-60h]

  this->__vftable = (idTestModel2_vtbl *)&idTestModel2::`vftable';
  p_attachments = &this->attachments;
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idFaceMgr::Shutdown(this: &this->faceMgr, owner: this, ta: TreeAnimatorFromPresentable);
  idAnimator_Base::Shutdown(this: &this->blendEqAnimator, stack: &this->animStack);
  idAnimator_Base::Shutdown(this: &this->channelAnimator, stack: &this->animStack);
  v4 = 0;
  if ( this->blendVariables.num > 0 )
  {
    v5 = 0;
    do
    {
      scalarPtr = this->blendVariables.list[v5].scalarPtr;
      if ( scalarPtr != nullptr )
      {
        idMem::Free(this: &mem, ptr: scalarPtr, align: ALIGN_16);
        idAnimWebScalar::SetScalarPtr(this: &this->blendVariables.list[v5], scalar: nullptr);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->blendVariables.num );
  }
  if ( p_attachments->attachments.listStatic == 0 || p_attachments->attachments.listStatic == 2 )
  {
    if ( p_attachments->attachments.list != nullptr )
      idMem::Free(this: &mem, ptr: p_attachments->attachments.list, align: ALIGN_16);
    p_attachments->attachments.list = nullptr;
    p_attachments->attachments.size = 0;
  }
  p_attachments->attachments.num = 0;
  idFaceMgr::~idFaceMgr(this: &this->faceMgr);
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idScalarMemBlock::Free(this: &this->scalarMem);
  if ( this->blendVariables.listStatic == 0 || this->blendVariables.listStatic == 2 )
  {
    list = this->blendVariables.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->blendVariables.list = nullptr;
    this->blendVariables.size = 0;
  }
  this->blendVariables.num = 0;
  if ( this->namedAnims.listStatic == 0 || this->namedAnims.listStatic == 2 )
  {
    v7 = this->namedAnims.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->namedAnims.list = nullptr;
    this->namedAnims.size = 0;
  }
  this->namedAnims.num = 0;
  idAnimator_BlendEq::~idAnimator_BlendEq(this: &this->blendEqAnimator);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$492351
// EA  : 0x82CE3F68
// RVA : 0x00CE3F68
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492351()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$492352_0
// EA  : 0x82CE3F90
// RVA : 0x00CE3F90
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492352_0()
{
  int v0; // r12

  idAnimator_BlendEq::~idAnimator_BlendEq(this: (idAnimator_BlendEq *)(*(_DWORD *)(v0 - 176 + 196) + 5200));
}


// ========================================================================
// __unwind$492353_0
// EA  : 0x82CE3FBC
// RVA : 0x00CE3FBC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492353_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 5328));
}


// ========================================================================
// __unwind$492354_0
// EA  : 0x82CE3FE8
// RVA : 0x00CE3FE8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492354_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 5344));
}


// ========================================================================
// __unwind$492355
// EA  : 0x82CE4014
// RVA : 0x00CE4014
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492355()
{
  int v0; // r12

  idScalarMemBlock::~idScalarMemBlock(this: (idScalarMemBlock *)(*(_DWORD *)(v0 - 176 + 196) + 5360));
}


// ========================================================================
// __unwind$492356
// EA  : 0x82CE4040
// RVA : 0x00CE4040
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492356()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 176 + 196) + 5368));
}


// ========================================================================
// __unwind$492357
// EA  : 0x82CE406C
// RVA : 0x00CE406C
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492357()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 176 + 196) + 5464));
}


// ========================================================================
// __unwind$492358
// EA  : 0x82CE4098
// RVA : 0x00CE4098
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_492358()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 7456));
}


// ========================================================================
// ?UpdateResetOrContinuous@idTestModel2@@AAAXW4translation_t@1@@Z
// EA  : 0x82CE41B0
// RVA : 0x00CE41B0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::UpdateResetOrContinuous(idTestModel2 *this, const idTestModel2::translation_t tm)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r29
  int GameMs; // r30
  const idAnimStack *v8; // r3
  idMD6LeafPlay *LastPlayedLeaf; // r28
  int v10; // r27
  int v11; // r3
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  bool IsPlaying; // r26
  signed int v17; // r27
  int v18; // r3
  __int64 v19; // r10
  int v20; // r8
  int v21; // r7
  int v22; // r6
  const idMat3 *v23; // r5
  const idVec3 *p_z; // r4
  double v25; // fp7
  double v26; // fp6
  idQuat *v27; // r3
  double z; // fp1
  double x; // fp3
  double v30; // fp2
  double y; // fp9
  double v32; // fp10
  double v33; // fp8
  double v34; // fp7
  double v35; // fp9
  double v36; // fp3
  double v37; // fp6
  double v38; // fp5
  double v39; // fp4
  double v40; // fp2
  double v41; // fp1
  double v42; // fp0
  double v43; // fp13
  double v44; // fp12
  double v45; // fp11
  double v46; // fp31
  double v47; // fp30
  double v48; // fp29
  signed int v49; // r29
  int v50; // r3
  signed int LoopCount; // r3
  int v52; // r29
  int v53; // r30
  const idAnimStack *v54; // r3
  double v55; // fp31
  double v56; // fp30
  double v57; // fp29
  float *v58; // r3
  double v59; // fp9
  double v60; // fp8
  double v61; // fp30
  double v62; // fp31
  double v63; // fp29
  const idMat3 *v64; // r3
  idAngles *v65; // r3
  idMD6AnimData *animData; // r11
  float *endDelta; // r30
  float v68; // r10
  float v69; // r9
  idMat3 v70; // [sp+60h] [-230h] BYREF
  float v71; // [sp+84h] [-20Ch]
  idMat3 v72; // [sp+90h] [-200h] BYREF
  float v73; // [sp+B4h] [-1DCh]
  float v74; // [sp+B8h] [-1D8h]
  idVec3 v75; // [sp+C0h] [-1D0h] BYREF
  idVec3 v76; // [sp+D0h] [-1C0h] BYREF
  idMat3 v77; // [sp+E0h] [-1B0h] BYREF
  idVec3 v78[2]; // [sp+108h] [-188h] BYREF
  idMat3 v79; // [sp+120h] [-170h] BYREF
  idMat3 v80; // [sp+150h] [-140h] BYREF
  idMat3 v81; // [sp+180h] [-110h] BYREF
  idMat3 v82[2]; // [sp+1B0h] [-E0h] BYREF
  idMat3 v83; // [sp+200h] [-90h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: v6, removeRotation: true);
    idTreeAnimator::SetRemoveOriginRotation(this: v6, removeRotation: true);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = this->GetAnimStack_2(this);
    if ( !idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v8, curTime: GameMs) )
    {
      LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
      v10 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      IsPlaying = idMD6LeafPlay::IsPlaying(
                    this: LastPlayedLeaf,
                    gameTime: v11,
                    ticksPerSec: v10,
                    a4: v15,
                    a5: v14,
                    a6: v13,
                    a7: v12);
      idTestModel2::GetOriginAxis(this, origin: v78, axis: &v83);
      v17 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idMD6LeafPlay::GetFrame(this: LastPlayedLeaf, gameTime: v18, ticksPerSec: v17, a4: v22, a5: v21, a6: v20, a7: v19);
      if ( !this->ignoreFirstDelta )
      {
        if ( tm_useQuats.valueInteger != 0 )
        {
          idMat3::ToQuat(this: &v70, result: (idQuat *)&v83);
          v76.x = 1.0;
          v76.y = 1.0;
          v76.z = 1.0;
          idTreeAnimator::ApplyOriginDeltas(
            this: v6,
            axis: (const idQuat *)&v70,
            origin: v78,
            outAxis: v82[0].mat,
            outOrigin: (idVec3 *)&v79.mat[2].z,
            extraScale: &v76);
          v23 = idQuat::ToMat3(this: (idQuat *)&v81, result: v82);
          p_z = (const idVec3 *)&v79.mat[2].z;
        }
        else
        {
          v72.mat[2].z = 1.0;
          v73 = 1.0;
          v74 = 1.0;
          idTreeAnimator::ApplyOriginDeltas(
            this: v6,
            axis: &v83,
            origin: v78,
            outAxis: &v80,
            outOrigin: (idVec3 *)&v79.mat[1].y,
            extraScale: (const idVec3 *)&v72.mat[2].z);
          v23 = &v80;
          p_z = (const idVec3 *)&v79.mat[1].y;
        }
        idTestModel2::SetOriginAxis(this, origin: p_z, axis: v23);
      }
      if ( tm_showDeltas.valueInteger > 1 && g_stopTime.valueInteger == 0 )
      {
        idTreeAnimator::GetLastOriginDeltas(this: v6, rot: &v80, trans: (idVec3 *)&v72.mat[1].y);
        idMat3::ToAngles(this: (idMat3 *)&v70.mat[1].y, result: (idAngles *)&v80);
        v25 = (float)(this->accumulatedDeltaTrans.y + v72.mat[1].z);
        v26 = (float)(this->accumulatedDeltaTrans.z + v72.mat[2].x);
        this->accumulatedDeltaTrans.x = this->accumulatedDeltaTrans.x + v72.mat[1].y;
        this->accumulatedDeltaTrans.y = v25;
        this->accumulatedDeltaTrans.z = v26;
        v27 = idMat3::ToQuat(this: &v79, result: (idQuat *)&v80);
        z = v27->z;
        x = this->accumulatedDeltaRot.x;
        v30 = this->accumulatedDeltaRot.z;
        y = v27->y;
        v32 = (float)((float)(v27->z * this->accumulatedDeltaRot.y)
                    + (float)((float)(v27->w * this->accumulatedDeltaRot.x)
                            + (float)(v27->x * this->accumulatedDeltaRot.w)));
        v33 = (float)((float)(this->accumulatedDeltaRot.w * v27->y)
                    + (float)((float)(v27->x * this->accumulatedDeltaRot.z)
                            + (float)(v27->w * this->accumulatedDeltaRot.y)));
        v34 = (float)-(float)((float)(this->accumulatedDeltaRot.y * v27->y)
                            - (float)((float)(v27->w * this->accumulatedDeltaRot.w)
                                    - (float)(v27->x * this->accumulatedDeltaRot.x)));
        this->accumulatedDeltaRot.z = -(float)((float)(v27->x * this->accumulatedDeltaRot.y)
                                             - (float)((float)(this->accumulatedDeltaRot.x * v27->y)
                                                     + (float)((float)(v27->w * this->accumulatedDeltaRot.z)
                                                             + (float)(v27->z * this->accumulatedDeltaRot.w))));
        this->accumulatedDeltaRot.x = -(float)((float)((float)v30 * (float)y) - (float)v32);
        this->accumulatedDeltaRot.y = -(float)((float)((float)z * (float)x) - (float)v33);
        this->accumulatedDeltaRot.w = -(float)((float)((float)z * (float)v30) - (float)v34);
        if ( IsPlaying )
        {
          idLib::Printf(
            fmt: "frame %d origin deltas: t( %.4f %.4f %.4f ) r( %.4f %.4f %.4f ) %s\n",
            (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v72.mat[1].y)),
            v72.mat[1].y,
            v72.mat[1].z,
            v72.mat[2].x,
            v70.mat[1].y,
            v70.mat[1].z,
            v70.mat[2].x,
            (const char *)COERCE_UNSIGNED_INT64(v72.mat[1].y));
          idTreeAnimator::GetTotalOriginTransform(this: v6, rot: (idQuat *)&v82[0].mat[1].y, trans: &v75);
          idQuat::ToAngles(this: (idQuat *)&v70.mat[2].z, result: (idAngles *)&v82[0].mat[1].y);
          idLib::Printf(
            fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v75.x)),
            (unsigned int)COERCE_UNSIGNED_INT64(v75.x),
            (unsigned int)COERCE_UNSIGNED_INT64(v75.y),
            (unsigned int)COERCE_UNSIGNED_INT64(v75.z),
            (unsigned int)COERCE_UNSIGNED_INT64(v70.mat[2].z),
            (unsigned int)COERCE_UNSIGNED_INT64(v71),
            __fsqrts((float)((float)(v75.z * v75.z) + (float)((float)(v75.x * v75.x) + (float)(v75.y * v75.y)))),
            v75.x);
          idTestModel2::GetOriginAxis(this, origin: v72.mat, axis: (idMat3 *)&v82[0].mat[2].z);
          v35 = this->resetOrigin.x;
          v36 = this->resetAxis.mat[1].x;
          v37 = this->resetOrigin.y;
          v38 = this->resetOrigin.z;
          v39 = this->resetAxis.mat[2].x;
          v40 = this->resetAxis.mat[2].z;
          v41 = this->resetAxis.mat[1].z;
          v42 = this->resetAxis.mat[0].z;
          v43 = this->resetAxis.mat[2].y;
          v44 = this->resetAxis.mat[1].y;
          v45 = this->resetAxis.mat[0].y;
          v77.mat[0].x = this->resetAxis.mat[0].x;
          v77.mat[0].y = v36;
          v46 = (float)(v72.mat[0].x - (float)v35);
          v77.mat[0].z = v39;
          v77.mat[1].x = v45;
          v77.mat[1].y = v44;
          v47 = (float)(v72.mat[0].y - (float)v37);
          v77.mat[1].z = v43;
          v77.mat[2].x = v42;
          v77.mat[2].y = v41;
          v77.mat[2].z = v40;
          v48 = (float)(v72.mat[0].z - (float)v38);
          idMat3::operator*(this: &v81, result: (idMat3 *)&v82[0].mat[2].z, a: &v77);
          idMat3::ToAngles(this: &v70, result: (idAngles *)&v81);
          idLib::Printf(
            fmt: "         actual deltas: t( %.4f %.4f %.4f ) r( %.4f %.4f %.4f ), len = %.4f\n",
            v46,
            v47,
            v48,
            v70.mat[0].x,
            v70.mat[0].y,
            v70.mat[0].z,
            __fsqrts((float)((float)((float)v48 * (float)v48)
                           + (float)((float)((float)v46 * (float)v46) + (float)((float)v47 * (float)v47)))));
        }
      }
      this->ignoreFirstDelta = false;
      if ( LastPlayedLeaf != nullptr )
      {
        v49 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v50 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        LoopCount = idMD6LeafPlay::GetLoopCount(this: LastPlayedLeaf, gameTime: v50, ticksPerSec: v49);
        v52 = LoopCount;
        if ( LoopCount > this->curLoopCount || !IsPlaying )
        {
          if ( tm_maxLoops.valueInteger > 0 && LoopCount >= tm_maxLoops.valueInteger )
          {
            v53 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            v54 = this->GetAnimStack_2(this);
            idAnimator_Base::End(
              this: &this->channelAnimator,
              stack: v54,
              curTime: v53,
              blendDurationMS: 0,
              reset: true);
          }
          this->curLoopCount = v52;
          idTestModel2::GetOriginAxis(this, origin: v70.mat, axis: &v81);
          if ( tm_showDeltas.valueInteger != 0 )
          {
            v55 = (float)(v70.mat[0].x - this->resetOrigin.x);
            v56 = (float)(v70.mat[0].y - this->resetOrigin.y);
            v57 = (float)(v70.mat[0].z - this->resetOrigin.z);
            v58 = (float *)idMat3::Inverse(this: (idMat3 *)&v82[0].mat[2].z, result: &this->resetAxis);
            v59 = (float)((float)(v58[3] * (float)v56) + (float)(v58[6] * (float)v57));
            v60 = (float)((float)(v58[2] * (float)v55) + (float)(v58[5] * (float)v56));
            v61 = (float)((float)(v58[7] * (float)v57)
                        + (float)((float)(v58[1] * (float)v55) + (float)(v58[4] * (float)v56)));
            v62 = (float)((float)((float)v55 * *v58) + (float)v59);
            v63 = (float)((float)(v58[8] * (float)v57) + (float)v60);
            v64 = idMat3::Inverse(this: &v80, result: &this->resetAxis);
            v65 = (idAngles *)idMat3::operator*(this: (idMat3 *)&v82[0].mat[2].z, result: &v81, a: v64);
            idMat3::ToAngles(this: &v72, result: v65);
            animData = LastPlayedLeaf->anim->animData;
            endDelta = animData->endDelta;
            v79.mat[0] = *(idVec3 *)animData->endDelta;
            v79.mat[1].x = animData->endDelta[3];
            idQuat::ToAngles(this: (idQuat *)&v70, result: (idAngles *)&v79);
            v68 = endDelta[9];
            v69 = endDelta[10];
            v70.mat[1].y = endDelta[8];
            v70.mat[1].z = v68;
            v70.mat[2].x = v69;
            idQuat::ToAngles(this: (idQuat *)&v70.mat[2].z, result: (idAngles *)&this->accumulatedDeltaRot);
            idLib::Printf(
              fmt: "Anim: rot = ( %g %g %g ), trans = ( %g %g %g )\n",
              v70.mat[0].x,
              v70.mat[0].y,
              v70.mat[0].z,
              v70.mat[1].y,
              v70.mat[1].z,
              v70.mat[2].x);
            idLib::Printf(
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v72.mat[0].x)),
              (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v72.mat[0].y)),
              (unsigned int)COERCE_UNSIGNED_INT64(v72.mat[0].y),
              HIDWORD(v62),
              v61,
              LODWORD(v63));
            idLib::Printf(
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v70.mat[2].z)),
              (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v71)),
              (unsigned int)COERCE_UNSIGNED_INT64(v71),
              (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->accumulatedDeltaTrans.x)),
              (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->accumulatedDeltaTrans.y)),
              (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->accumulatedDeltaTrans.z)),
              (unsigned int)COERCE_UNSIGNED_INT64(this->accumulatedDeltaTrans.z));
          }
          if ( tm != TRANSLATE_CONTINUOUS && LastPlayedLeaf->wrapMode != 0 )
          {
            idTestModel2::SetOriginAxis(this, origin: &this->resetOrigin, axis: &this->resetAxis);
            this->accumulatedDeltaTrans.z = 0.0;
            this->accumulatedDeltaTrans.x = 0.0;
            this->accumulatedDeltaTrans.y = 0.0;
            this->accumulatedDeltaRot = quat_identity;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?tm_fixed_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4A40
// RVA : 0x00CE4A40
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_fixed_f(const idCmdArgs *args)
{
  int value; // r8
  idTestModel2 *v2; // r3
  idTestModel2 *v3; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v3 = idTestModel2::CastTo(c: v2)) != nullptr )
    {
      v3->translationMode = TRANSLATE_FIXED;
      idTestModel2::SetOriginAxis(this: v3, origin: &v3->resetOrigin, axis: &v3->resetAxis);
    }
    else
    {
      idLib::Warning(fmt: "No current test model.");
    }
  }
}


// ========================================================================
// ?tm_reset_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4B00
// RVA : 0x00CE4B00
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_reset_f(const idCmdArgs *args)
{
  int value; // r8
  idTestModel2 *v2; // r3
  idTestModel2 *v3; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v3 = idTestModel2::CastTo(c: v2)) != nullptr )
    {
      v3->translationMode = TRANSLATE_RESET;
      idTestModel2::SetOriginAxis(this: v3, origin: &v3->resetOrigin, axis: &v3->resetAxis);
    }
    else
    {
      idLib::Warning(fmt: "No current test model.");
    }
  }
}


// ========================================================================
// ?tm_continuous_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4BC0
// RVA : 0x00CE4BC0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_continuous_f(const idCmdArgs *args)
{
  int value; // r8
  idTestModel2 *v2; // r3
  idTestModel2 *v3; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v3 = idTestModel2::CastTo(c: v2)) != nullptr )
    {
      v3->translationMode = TRANSLATE_CONTINUOUS;
      idTestModel2::SetOriginAxis(this: v3, origin: &v3->resetOrigin, axis: &v3->resetAxis);
    }
    else
    {
      idLib::Warning(fmt: "No current test model.");
    }
  }
}


// ========================================================================
// ?tm_play_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4C80
// RVA : 0x00CE4C80
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_play_f(const idCmdArgs *args)
{
  int value; // r8
  idTestModel2 *v3; // r3
  idTestModel2 *v4; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v4 = idTestModel2::CastTo(c: v3)) != nullptr )
    {
      if ( args->argc == 2 )
        idTestModel2::StartAnim(this: v4, name: args->argv[1], cycle: false);
      else
        idLib::Printf(fmt: "USAGE: tm_play <anim or alias name>\n");
    }
    else
    {
      idLib::Warning(fmt: "No current test model.");
    }
  }
}


// ========================================================================
// ?tm_loop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4D50
// RVA : 0x00CE4D50
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_loop_f(const idCmdArgs *args)
{
  int value; // r8
  idTestModel2 *v3; // r3
  idTestModel2 *v4; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v4 = idTestModel2::CastTo(c: v3)) != nullptr )
    {
      if ( args->argc == 2 )
        idTestModel2::StartAnim(this: v4, name: args->argv[1], cycle: true);
      else
        idLib::Printf(fmt: "USAGE: tm_loop <anim or alias name>\n");
    }
    else
    {
      idLib::Warning(fmt: "No current test model.");
    }
  }
}


// ========================================================================
// ?tm_vo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4E20
// RVA : 0x00CE4E20
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_vo_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const idDeclVoiceOver *v3; // r29
  idAI2 *DebugEntity; // r3
  idAI2 *v5; // r3
  idAI2 *v6; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idVehicleOccupant *v8; // r3
  idVehicleOccupant *v9; // r3
  idTestModel2 *CurTestModel; // r3
  idStrId v11; // [sp+50h] [-30h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
    {
      v2 = args->argv[1];
      if ( v2 != nullptr
        && (v3 = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                            this: &idDeclVoiceOver::resourceList,
                                            name: v2,
                                            makeDefault: true)) != nullptr )
      {
        animation->FinalizeAliasRefs(this: animation);
        DebugEntity = (idAI2 *)idGameLocal::GetDebugEntity(this: gameLocal);
        v5 = idAI2::CastTo(c: DebugEntity);
        v6 = v5;
        if ( v5 != nullptr )
        {
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v5);
          idFaceMgr::StartVoiceOver(this: &v6->aiVolatile.faceMgr, owner: v6, ta: TreeAnimatorFromPresentable, vo: v3);
        }
        else
        {
          v8 = (idVehicleOccupant *)idGameLocal::GetDebugEntity(this: gameLocal);
          v9 = idVehicleOccupant::CastTo(c: v8);
          if ( v9 != nullptr )
          {
            v11.index = -1;
            idVehicleOccupant::PlayVoiceOver(this: v9, vo: v3, whoStartedMeTextId: &v11);
          }
          else if ( idGameLocal::GetCurTestModel(this: gameLocal) != nullptr )
          {
            CurTestModel = idGameLocal::GetCurTestModel(this: gameLocal);
            idTestModel2::PlayVoiceOver(this: CurTestModel, vo: v3);
          }
          else
          {
            idLib::Printf(fmt: "No testModel is active and no current AI debug target was found.\n");
          }
        }
      }
      else if ( args->argc <= 1 )
      {
        idLib::Printf(fmt: "Could not find voice over decl '%s'\n", &byte_8200D768);
      }
      else
      {
        idLib::Printf(fmt: "Could not find voice over decl '%s'\n", args->argv[1]);
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_vo [voice over decl]\n");
    }
  }
}


// ========================================================================
// ?tm_addAttach_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE4F98
// RVA : 0x00CE4F98
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_addAttach_f(const idCmdArgs *args)
{
  idTestModel2 *CurTestModel; // r3
  idList<idAttachment,5> *v3; // r3
  const char *v4; // r5
  const char *v5; // r6
  idAttachmentCollection v6; // [sp+50h] [-20h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 3 )
    {
      CurTestModel = idGameLocal::GetCurTestModel(this: gameLocal);
      if ( CurTestModel != nullptr )
      {
        v3 = (idList<idAttachment,5> *)CurTestModel->GetAttachments_2(this: CurTestModel);
        v4 = &byte_8200D768;
        if ( args->argc <= 2 )
          v5 = &byte_8200D768;
        else
          v5 = args->argv[2];
        if ( args->argc > 1 )
          v4 = args->argv[1];
        idAttachmentCollection::AddAttachment(this: &v6, result: v3, modelName: v4, tag: v5);
      }
      else
      {
        idLib::Warning(fmt: "No current test model.");
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addAttach <modelName> <tagName>\n");
    }
  }
}


// ========================================================================
// ?tm_removeAttach_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5068
// RVA : 0x00CE5068
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_removeAttach_f(const idCmdArgs *args)
{
  idTestModel2 *CurTestModel; // r3
  idAttachmentCollection *v3; // r3
  idAttachmentCollection *v4; // r31
  const char *v5; // r5
  idAttachmentCollection v6[2]; // [sp+50h] [-30h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 2 )
    {
      CurTestModel = idGameLocal::GetCurTestModel(this: gameLocal);
      if ( CurTestModel != nullptr )
      {
        v3 = CurTestModel->GetAttachments_2(this: CurTestModel);
        v4 = v3;
        if ( args->argc <= 1 )
          v5 = &byte_8200D768;
        else
          v5 = args->argv[1];
        idAttachmentCollection::FindAttachment(this: v6, result: v3, modelName: v5);
        if ( v6[0].attachments.list == (idAttachment *)-1 )
        {
          if ( args->argc <= 1 )
            idLib::Printf(fmt: "Could not find attachment '%s'", &byte_8200D768);
          else
            idLib::Printf(fmt: "Could not find attachment '%s'", args->argv[1]);
        }
        else
        {
          idAttachmentCollection::RemoveAttachment(
            this: v4,
            handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v6);
        }
      }
      else
      {
        idLib::Warning(fmt: "No current test model.");
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addAttach <modelName>\n");
    }
  }
}


// ========================================================================
// ?SetCurAliasIndex@idTestModel2@@QAAXH@Z
// EA  : 0x82CE5180
// RVA : 0x00CE5180
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTestModel2::SetCurAliasIndex(idTestModel2 *this, int aliasIndex)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r30
  const idDeclMD6 *decl; // r29
  encounterGroupRole_t v8; // r30
  __int64 v9; // r9 OVERLAPPED
  idResource *Existing; // r3
  idResource *v11; // r30
  double curFrame; // fp0
  int v13; // r10
  idList<enum encounterGroupRole_t,5> v14[4]; // [sp+60h] [-40h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
  {
    decl = v6->decl;
    if ( decl != nullptr )
    {
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v14);
      idDeclMD6::GetAliases(this: decl, list: v14, includeParent: true);
      if ( aliasIndex < v14[0].num )
      {
        v8 = v14[0].list[aliasIndex];
        if ( v8 != ROLE_NONE )
        {
          animation->StrongLoadAlias_2(
            this: animation,
            a2: decl,
            a3: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)(v8 + 4));
          Existing = idResourceList::FindExisting(
                       this: &idMD6Anim::resourceList,
                       name: **(char ***)(v8 + 8),
                       skipStaleCheck: true);
          v11 = Existing;
          if ( Existing != nullptr )
          {
            curFrame = this->curFrame;
            if ( curFrame >= 0.0 )
            {
              LODWORD(v9) = *(unsigned __int16 *)(Existing[1].trackedMemory + 8);
              if ( curFrame >= (float)v9 )
              {
                v13 = *(unsigned __int16 *)(Existing[1].trackedMemory + 8) - 1;
                idTestModel2::SetCurFrame(this, frame: (float)*(__int64 *)((char *)&v9 - 4));
              }
            }
            idTestModel2::StartAnim(this, name: (char *)v11->name.str, cycle: false);
            this->curAliasIndex = aliasIndex;
          }
          else
          {
            idLib::Warning(fmt: "Alias specifies invalid animation.");
          }
        }
        else
        {
          idLib::Warning(fmt: "Alias is NULL");
        }
      }
      else
      {
        idLib::Warning(fmt: "Alias index %d out of range. Max is %d.", aliasIndex, v14[0].num);
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v14);
    }
  }
  else
  {
    idLib::Warning(fmt: "Current test model is not an animated model.");
  }
}


// ========================================================================
// __unwind$493697
// EA  : 0x82CE5324
// RVA : 0x00CE5324
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_493697()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ?GetCurTestModel@@YA_NAAPAVidTestModel2@@AAPAVidTreeAnimator@@@Z
// EA  : 0x82CE5350
// RVA : 0x00CE5350
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

int __fastcall GetCurTestModel(idEntity **curTestModel, idTreeAnimator **ta)
{
  idTestModel2 *v3; // r3
  int value; // r8
  idTestModel2 *v6; // r11
  idEntity *v8; // r31
  idPresentable *presentable; // r11

  *curTestModel = nullptr;
  v3 = nullptr;
  *ta = nullptr;
  value = gameLocal->curTestModel.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
      v3 = idTestModel2::CastTo(c: v6);
  }
  *curTestModel = v3;
  if ( v3 != nullptr )
  {
    *ta = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v3);
    v8 = *curTestModel;
    presentable = v8->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v8);
      presentable = v8->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( *ta != nullptr )
    {
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Current test model is not an animated model.");
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "No current test model.");
    return 0;
  }
}


// ========================================================================
// ?tm_addYaw_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5450
// RVA : 0x00CE5450
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_addYaw_f(const idCmdArgs *args)
{
  idTestModel2 *v2; // r31
  const char *v3; // r3
  long double v4; // fp2
  const idMat3 *v5; // r3
  idMat3 *v6; // r3
  idTestModel2 *v7; // [sp+50h] [-A0h] BYREF
  idTreeAnimator *v8; // [sp+54h] [-9Ch] BYREF
  idMat3 v9; // [sp+58h] [-98h] BYREF
  idMat3 v10; // [sp+80h] [-70h] BYREF
  idAngles v11[3]; // [sp+B0h] [-40h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v7, ta: &v8) != 0 )
      {
        v2 = v7;
        idTestModel2::GetOriginAxis(this: v7, origin: (idVec3 *)&v9.mat[1].y, axis: &v10);
        idMat3::ToAngles(this: &v9, result: (idAngles *)&v10);
        if ( args->argc <= 1 )
          v3 = &byte_8200D768;
        else
          v3 = args->argv[1];
        v4 = atof(nptr: v3);
        v9.mat[0].y = *(double *)&v4 + v9.mat[0].y;
        v5 = idAngles::ToMat3(this: v11, result: &v9);
        idTestModel2::SetOriginAxis(this: v2, origin: (const idVec3 *)&v9.mat[1].y, axis: v5);
        v6 = idAngles::ToMat3(this: v11, result: &v9);
        v2->resetOrigin.x = v9.mat[1].y;
        v2->resetOrigin.y = v9.mat[1].z;
        v2->resetOrigin.z = v9.mat[2].x;
        v2->resetAxis = *v6;
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addYaw <angle in degrees>\n");
    }
  }
}


// ========================================================================
// ?tm_addPitch_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE55B0
// RVA : 0x00CE55B0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_addPitch_f(const idCmdArgs *args)
{
  idTestModel2 *v2; // r31
  const char *v3; // r3
  long double v4; // fp2
  const idMat3 *v5; // r3
  idMat3 *v6; // r3
  idTestModel2 *v7; // [sp+50h] [-A0h] BYREF
  idTreeAnimator *v8; // [sp+54h] [-9Ch] BYREF
  idMat3 v9; // [sp+58h] [-98h] BYREF
  idMat3 v10; // [sp+80h] [-70h] BYREF
  idAngles v11[3]; // [sp+B0h] [-40h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v7, ta: &v8) != 0 )
      {
        v2 = v7;
        idTestModel2::GetOriginAxis(this: v7, origin: (idVec3 *)&v9.mat[1].y, axis: &v10);
        idMat3::ToAngles(this: &v9, result: (idAngles *)&v10);
        if ( args->argc <= 1 )
          v3 = &byte_8200D768;
        else
          v3 = args->argv[1];
        v4 = atof(nptr: v3);
        v9.mat[0].x = *(double *)&v4 + v9.mat[0].x;
        v5 = idAngles::ToMat3(this: v11, result: &v9);
        idTestModel2::SetOriginAxis(this: v2, origin: (const idVec3 *)&v9.mat[1].y, axis: v5);
        v6 = idAngles::ToMat3(this: v11, result: &v9);
        v2->resetOrigin.x = v9.mat[1].y;
        v2->resetOrigin.y = v9.mat[1].z;
        v2->resetOrigin.z = v9.mat[2].x;
        v2->resetAxis = *v6;
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addPitch <angle in degrees>\n");
    }
  }
}


// ========================================================================
// ?tm_addRoll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5710
// RVA : 0x00CE5710
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_addRoll_f(const idCmdArgs *args)
{
  idTestModel2 *v2; // r31
  const char *v3; // r3
  long double v4; // fp2
  const idMat3 *v5; // r3
  idMat3 *v6; // r3
  idTestModel2 *v7; // [sp+50h] [-A0h] BYREF
  idTreeAnimator *v8; // [sp+54h] [-9Ch] BYREF
  idMat3 v9; // [sp+58h] [-98h] BYREF
  idMat3 v10; // [sp+80h] [-70h] BYREF
  idAngles v11[3]; // [sp+B0h] [-40h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v7, ta: &v8) != 0 )
      {
        v2 = v7;
        idTestModel2::GetOriginAxis(this: v7, origin: (idVec3 *)&v9.mat[1].y, axis: &v10);
        idMat3::ToAngles(this: &v9, result: (idAngles *)&v10);
        if ( args->argc <= 1 )
          v3 = &byte_8200D768;
        else
          v3 = args->argv[1];
        v4 = atof(nptr: v3);
        v9.mat[0].z = *(double *)&v4 + v9.mat[0].z;
        v5 = idAngles::ToMat3(this: v11, result: &v9);
        idTestModel2::SetOriginAxis(this: v2, origin: (const idVec3 *)&v9.mat[1].y, axis: v5);
        v6 = idAngles::ToMat3(this: v11, result: &v9);
        v2->resetOrigin.x = v9.mat[1].y;
        v2->resetOrigin.y = v9.mat[1].z;
        v2->resetOrigin.z = v9.mat[2].x;
        v2->resetAxis = *v6;
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addPitch <angle in degrees>\n");
    }
  }
}


// ========================================================================
// ?tm_nudge_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5870
// RVA : 0x00CE5870
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_nudge_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r29
  const char *v3; // r3
  long double v4; // fp2
  double v5; // fp29
  const char *v6; // r3
  long double v7; // fp2
  double v8; // fp30
  double v9; // fp31
  const char *v10; // r3
  long double v11; // fp2
  idTestModel2 *v12; // r31
  idTestModel2 *v13; // [sp+50h] [-C0h] BYREF
  idTreeAnimator *v14; // [sp+54h] [-BCh] BYREF
  idVec3 v15; // [sp+58h] [-B8h] BYREF
  char v16; // [sp+68h] [-A8h] BYREF
  idMat3 v17; // [sp+80h] [-90h] BYREF
  float v18[10]; // [sp+B0h] [-60h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 3 || args->argc == 4 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v13, ta: &v14) != 0 )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        if ( DebugPlayer != nullptr )
        {
          if ( args->argc <= 1 )
            v3 = &byte_8200D768;
          else
            v3 = args->argv[1];
          v4 = atof(nptr: v3);
          v5 = (float)*(double *)&v4;
          if ( args->argc <= 2 )
            v6 = &byte_8200D768;
          else
            v6 = args->argv[2];
          v7 = atof(nptr: v6);
          v8 = (float)*(double *)&v7;
          if ( args->argc >= 4 )
          {
            if ( args->argc <= 3 )
              v10 = &byte_8200D768;
            else
              v10 = args->argv[3];
            v11 = atof(nptr: v10);
            v9 = (float)*(double *)&v11;
          }
          else
          {
            v9 = 0.0;
          }
          v12 = v13;
          idTestModel2::GetOriginAxis(this: v13, origin: &v15, axis: &v17);
          DebugPlayer->GetViewTransform(this: DebugPlayer, a2: (idVec3 *)&v16, a3: (idMat3 *)v18);
          v15.x = (float)((float)(v18[0] * (float)v5)
                        + (float)((float)(v18[6] * (float)v9) + (float)(v18[3] * (float)v8)))
                + v15.x;
          v15.y = v15.y
                + (float)((float)(v18[1] * (float)v5)
                        + (float)((float)(v18[7] * (float)v9) + (float)(v18[4] * (float)v8)));
          v15.z = v15.z
                + (float)((float)(v18[5] * (float)v8)
                        + (float)((float)(v18[2] * (float)v5) + (float)(v18[8] * (float)v9)));
          idTestModel2::SetOriginAxis(this: v12, origin: &v15, axis: &v17);
          v12->resetOrigin.x = v15.x;
          v12->resetOrigin.y = v15.y;
          v12->resetOrigin.z = v15.z;
          v12->resetAxis = v17;
        }
        else
        {
          idLib::Warning(fmt: "No player available.");
        }
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_nudge <x> <y> <z>\n");
      idLib::Printf(fmt: "  <x> <y> <z> - distance to push the model in screen space. <z> is optional.\n");
    }
  }
}


// ========================================================================
// ?tm_frame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5AD8
// RVA : 0x00CE5AD8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_frame_f(const idCmdArgs *args)
{
  const char *v2; // r3
  long double v3; // fp2
  idTestModel2 *v4; // [sp+50h] [-20h] BYREF
  idTreeAnimator *v5; // [sp+54h] [-1Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v4, ta: &v5) != 0 )
      {
        if ( args->argc <= 1 )
          v2 = &byte_8200D768;
        else
          v2 = args->argv[1];
        v3 = atof(nptr: v2);
        idTestModel2::SetCurFrame(this: v4, frame: (float)*(double *)&v3);
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_frame <frame number>\n");
    }
  }
}


// ========================================================================
// ?tm_nextframe_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5B90
// RVA : 0x00CE5B90
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_nextframe_f(const idCmdArgs *args)
{
  idTestModel2 *v2; // [sp+50h] [-20h] BYREF
  idTreeAnimator *v3; // [sp+54h] [-1Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 1 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v2, ta: &v3) != 0 )
        idTestModel2::SetCurFrame(this: v2, frame: (float)(v2->curFrame + (float)1.0));
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_nextframe\n");
    }
  }
}


// ========================================================================
// ?tm_prevframe_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5C30
// RVA : 0x00CE5C30
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_prevframe_f(const idCmdArgs *args)
{
  idTestModel2 *v2; // [sp+50h] [-20h] BYREF
  idTreeAnimator *v3; // [sp+54h] [-1Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 1 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v2, ta: &v3) != 0 )
        idTestModel2::SetCurFrame(this: v2, frame: (float)(v2->curFrame - (float)1.0));
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_prevframe\n");
    }
  }
}


// ========================================================================
// ?tm_nextAlias_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5CD8
// RVA : 0x00CE5CD8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_nextAlias_f(const idCmdArgs *args)
{
  idDeclMD6 *decl; // r28
  idTestModel2 *v3; // r29
  unsigned int v4; // r30
  __int64 v5; // r11
  idTreeAnimator *v6; // [sp+50h] [-50h] BYREF
  idTestModel2 *v7; // [sp+54h] [-4Ch] BYREF
  idList<enum encounterGroupRole_t,5> v8[4]; // [sp+60h] [-40h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 1 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v7, ta: &v6) != 0 )
      {
        decl = v6->decl;
        if ( decl != nullptr )
        {
          v3 = v7;
          v4 = v7->curAliasIndex + 1;
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v8);
          idDeclMD6::GetAliases(this: decl, list: v8, includeParent: true);
          LODWORD(v5) = v8[0].num;
          HIDWORD(v5) = v4 >> 31;
          idTestModel2::SetCurAliasIndex(
            this: v3,
            aliasIndex: ((__PAIR64__((unsigned int)v8[0].num >> 31, v4) - v5) >> 32) & v4);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v8);
        }
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_addPitch <angle in degrees>\n");
    }
  }
}


// ========================================================================
// __unwind$494213_0
// EA  : 0x82CE5DA0
// RVA : 0x00CE5DA0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494213_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ?tm_listAnims_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE5DC8
// RVA : 0x00CE5DC8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_listAnims_f(const idCmdArgs *args)
{
  int v1; // r31
  idClip **p_clip; // r29
  int v3; // r30
  idEntity *v4; // [sp+50h] [-50h] BYREF
  idTreeAnimator *v5; // [sp+54h] [-4Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr)
    && (unsigned __int8)GetCurTestModel(curTestModel: &v4, ta: &v5) != 0 )
  {
    v1 = 0;
    p_clip = &v4[6].defaultPhysicsObj.clip;
    if ( (int)v4[6].defaultPhysicsObj.callbacks > 0 )
    {
      v3 = 0;
      do
      {
        idLib::Printf(
          fmt: "%d: %s %s %.2f %s\n",
          v1++,
          *(const char **)((char *)idMD6Leaf::wrapModeNames
                         + __ROL4__(*((unsigned __int8 *)&(*p_clip)->temporaryClipModel + v3), 2)),
          *(const char **)((char *)idMD6Skel::weightGroupNames
                         + __ROL4__(*((unsigned __int8 *)&(*p_clip)->temporaryClipModel + v3 + 1), 2)),
          *(float *)((char *)&(*p_clip)->defaultClipModel + v3),
          (const char *)COERCE_UNSIGNED_INT64(*(float *)((char *)&(*p_clip)->defaultClipModel + v3)));
        v3 += 12;
      }
      while ( v1 < (int)p_clip[1] );
    }
  }
}


// ========================================================================
// ??0idTestModel2@@QAA@XZ
// EA  : 0x82CE6190
// RVA : 0x00CE6190
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idTestModel2 *__fastcall idTestModel2::idTestModel2(idTestModel2 *this)
{
  int *p_currentFluffInterval; // r9
  float *p_y; // r10
  int i; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idTestModel2_vtbl *)&idTestModel2::`vftable';
  idAnimator_BlendEq::idAnimator_BlendEq(this: &this->blendEqAnimator);
  this->namedAnims.list = nullptr;
  this->namedAnims.granularity = 0;
  this->namedAnims.memTag = 5;
  this->namedAnims.listStatic = 0;
  this->namedAnims.size = 0;
  this->namedAnims.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->namedAnims);
  this->blendVariables.list = nullptr;
  this->blendVariables.granularity = 0;
  this->blendVariables.memTag = 5;
  this->blendVariables.listStatic = 0;
  this->blendVariables.size = 0;
  this->blendVariables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->blendVariables);
  this->scalarMem.floats = nullptr;
  this->scalarMem.num = 0;
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  p_currentFluffInterval = &this->faceMgr.currentFluffInterval;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_currentFluffInterval = *(_DWORD *)++p_y;
  this->resetOrigin.x = 0.0;
  this->resetOrigin.y = 0.0;
  this->resetOrigin.z = 0.0;
  this->translationMode = TRANSLATE_RESET;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->curLoopCount = 0;
  this->curAliasIndex = 0;
  this->curFrame = -1.0;
  this->rotationAngles.pitch = 0.0;
  this->rotationAngles.yaw = 0.0;
  this->rotationAngles.roll = 0.0;
  this->accumulatedDeltaTrans.x = 0.0;
  this->accumulatedDeltaTrans.y = 0.0;
  this->accumulatedDeltaTrans.z = 0.0;
  this->accumulatedDeltaRot = quat_identity;
  this->ignoreFirstDelta = false;
  this->attachments.parent = this;
  return this;
}


// ========================================================================
// __unwind$494418
// EA  : 0x82CE62F8
// RVA : 0x00CE62F8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494418()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$494419
// EA  : 0x82CE6320
// RVA : 0x00CE6320
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494419()
{
  int v0; // r12

  idAnimator_BlendEq::~idAnimator_BlendEq(this: (idAnimator_BlendEq *)(*(_DWORD *)(v0 - 144 + 164) + 5200));
}


// ========================================================================
// __unwind$494420
// EA  : 0x82CE634C
// RVA : 0x00CE634C
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494420()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5328));
}


// ========================================================================
// __unwind$494421
// EA  : 0x82CE6378
// RVA : 0x00CE6378
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494421()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5344));
}


// ========================================================================
// __unwind$494422
// EA  : 0x82CE63A4
// RVA : 0x00CE63A4
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494422()
{
  int v0; // r12

  idScalarMemBlock::~idScalarMemBlock(this: (idScalarMemBlock *)(*(_DWORD *)(v0 - 144 + 164) + 5360));
}


// ========================================================================
// __unwind$494423
// EA  : 0x82CE63D0
// RVA : 0x00CE63D0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494423()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 144 + 164) + 5368));
}


// ========================================================================
// __unwind$494424
// EA  : 0x82CE63FC
// RVA : 0x00CE63FC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494424()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 144 + 164) + 5464));
}


// ========================================================================
// ?Spawn@idTestModel2@@QAAXXZ
// EA  : 0x82CE6490
// RVA : 0x00CE6490
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::Spawn(idTestModel2 *this)
{
  idScalarMemBlock *p_scalarMem; // r29
  idAnimStack *v3; // r3
  const char *v4; // r10
  idGameTimeManager *v5; // r3
  idGameTimeManager *v6; // r3
  idScalarMemBlock *v7; // [sp+8h] [-148h]
  int v8; // [sp+Ch] [-144h]
  int v9; // [sp+10h] [-140h]
  int v10; // [sp+14h] [-13Ch]
  int v11; // [sp+18h] [-138h]
  int v12; // [sp+1Ch] [-134h]
  int v13; // [sp+20h] [-130h]
  int v14; // [sp+24h] [-12Ch]
  int v15; // [sp+28h] [-128h]
  int v16; // [sp+2Ch] [-124h]
  int v17; // [sp+30h] [-120h]
  int v18; // [sp+34h] [-11Ch]
  int v19; // [sp+38h] [-118h]
  int v20; // [sp+3Ch] [-114h]
  int v21; // [sp+40h] [-110h]
  int v22; // [sp+44h] [-10Ch]
  int v23; // [sp+48h] [-108h]
  int v24; // [sp+4Ch] [-104h]
  int v25; // [sp+50h] [-100h]
  int v26; // [sp+58h] [-F8h]
  idAnimatorParms_Base v27; // [sp+60h] [-F0h] BYREF
  idAnimatorParms_BlendEq v28; // [sp+A0h] [-B0h] BYREF

  p_scalarMem = &this->scalarMem;
  v3 = this->GetAnimStack_2(this);
  idAnimatorParms_BlendEq::idAnimatorParms_BlendEq(
    this: &v28,
    animStack_: v3,
    name_: "blendEq",
    blendOp_: BOP_LERP,
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 0.0,
    blendEq_: v4,
    scalarMem_: v7,
    a11: v8,
    a12: v9,
    a13: v10,
    a14: v11,
    a15: v12,
    a16: v13,
    a17: v14,
    a18: v15,
    a19: v16,
    a20: v17,
    a21: v18,
    a22: v19,
    a23: v20,
    a24: v21,
    a25: v22,
    a26: v23,
    a27: v24,
    a28: v25,
    a29: &byte_8200D768,
    a30: v26,
    a31: p_scalarMem);
  idList<idAnimator_BlendEq::idNamedAnim,5>::operator=(
    this: (idList<idAnimator_BlendEq::idNamedAnim,33> *)&v28.anims,
    other: (const idList<idAnimator_BlendEq::idNamedAnim,33> *)&this->namedAnims);
  idList<idAnimWebScalar,5>::operator=(
    this: (idList<idAnimWebScalar,33> *)&v28.scalars,
    other: (const idList<idAnimWebScalar,33> *)&this->blendVariables);
  v5 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->blendEqAnimator, gametimeManager: v5, parms: &v28);
  v27.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v27.name, text: "channel");
  v27.alpha = 0.0;
  memset(&v27.originBlend, 0, 12);
  v27.blendOp = BOP_LERP;
  v6 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v6, parms: &v27);
  idStr::FreeData(this: &v27.name);
  idAnimatorParms_BlendEq::~idAnimatorParms_BlendEq(this: &v28);
}


// ========================================================================
// __unwind$494511
// EA  : 0x82CE65C0
// RVA : 0x00CE65C0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494511()
{
  int v0; // r12

  idAnimatorParms_BlendEq::~idAnimatorParms_BlendEq(this: (idAnimatorParms_BlendEq *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$494512
// EA  : 0x82CE65E8
// RVA : 0x00CE65E8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494512()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 336 + 96));
}


// ========================================================================
// ?Event_InitTestModel@idTestModel2@@QAA?AVeventVoid@@_N0@Z
// EA  : 0x82CE6618
// RVA : 0x00CE6618
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idTestModel2 *__fastcall idTestModel2::Event_InitTestModel(
        idTestModel2 *this,
        idAnimatedEntity *result,
        bool atOrigin,
        bool dropToFloor)
{
  idPlayer *DebugPlayer; // r22
  int GameMs; // r28
  const idAnimStack *v10; // r3
  int v11; // r28
  const idAnimStack *v12; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v15; // r28
  idAnimStack *v16; // r28
  int v17; // r3
  int v18; // r3
  int v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  idGameTimeManager *p_gameTimeManager; // r27
  idGameTimeManager *v24; // r24
  int GameMsPerFrame; // r18
  int PreviousGameMs; // r17
  int v27; // r3
  idPresentable *v28; // r11
  idPresentable *v29; // r11
  int entityNumber; // r28
  idClip *p_clip; // r27
  idPhysics *Physics; // r3
  idPresentable *v33; // r11
  idClipModel *v34; // r28
  idRenderModel *model; // r29
  idTreeAnimator *v36; // r28
  idClipModel *v37; // r3
  idClipModel *v38; // r3
  idClipModel *v39; // r28
  const char *str; // r29
  const idMaterial *RenderModelMaterial; // r3
  idClipModel *v42; // r3
  idPhysics *v43; // r3
  idPresentable *v44; // r11
  int *v45; // r10
  idRenderModelCommitted **p_committed; // r11
  int i; // ctr
  float *p_z; // r10
  int v49; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idClipModel *v51; // r3
  idClipModel *v52; // r24
  float *v53; // r29
  float *v54; // r28
  idPresentable *v55; // r3
  int v56; // r3
  float *v57; // r10
  _DWORD *v58; // r11
  int j; // ctr
  idPresentable *v60; // r3
  int v61; // r3
  double v62; // fp27
  float *v63; // r10
  double v64; // fp26
  idVec3 *p_gravity; // r8
  double v66; // fp30
  float v67; // r3
  float v68; // r5
  double v69; // fp28
  float v70; // r11
  double v71; // fp7
  double v72; // fp9
  double v73; // fp5
  double v76; // fp12
  double v77; // fp2
  double v78; // fp12
  double v79; // fp25
  double v80; // fp24
  double v81; // fp23
  double y; // fp12
  double v85; // fp5
  double v86; // fp9
  double v87; // fp6
  double v88; // fp4
  double z; // fp1
  double v90; // fp8
  idClip *v91; // r4
  double v92; // fp7
  double v93; // fp6
  double v94; // fp1
  double v95; // fp3
  double v96; // fp0
  double v97; // fp12
  double v98; // fp3
  double v99; // fp2
  float v100; // r4
  float v101; // r3
  int v102; // r27
  double v103; // fp7
  double v104; // fp6
  idPhysics *v105; // r3
  idPhysics *v106; // r3
  float *v107; // r11
  double v108; // fp13
  float *v109; // r11
  float *v111; // [sp+8h] [-888h]
  float *v112; // [sp+Ch] [-884h]
  float *v113; // [sp+10h] [-880h]
  int v114; // [sp+14h] [-87Ch]
  int v115; // [sp+18h] [-878h]
  int v116; // [sp+1Ch] [-874h]
  int v117; // [sp+20h] [-870h]
  int v118; // [sp+24h] [-86Ch]
  int v119; // [sp+28h] [-868h]
  int v120; // [sp+2Ch] [-864h]
  int v121; // [sp+30h] [-860h]
  int v122; // [sp+34h] [-85Ch]
  int v123; // [sp+38h] [-858h]
  int v124; // [sp+3Ch] [-854h]
  int v125; // [sp+40h] [-850h]
  int v126; // [sp+44h] [-84Ch]
  int v127; // [sp+48h] [-848h]
  int v128; // [sp+4Ch] [-844h]
  int v129; // [sp+50h] [-840h]
  int v130; // [sp+54h] [-83Ch]
  int v131; // [sp+58h] [-838h]
  int v132; // [sp+60h] [-830h]
  int v133; // [sp+68h] [-828h]
  idVec3 v134; // [sp+70h] [-820h] BYREF
  idVec3 v135; // [sp+80h] [-810h] BYREF
  idVec3 v136; // [sp+90h] [-800h] BYREF
  idVec3 v137; // [sp+A0h] [-7F0h] BYREF
  idVec3 v138; // [sp+B0h] [-7E0h] BYREF
  idDeclAnimWebNode::idModelInfo v139; // [sp+C0h] [-7D0h] BYREF
  float v140[12]; // [sp+ECh] [-7A4h] BYREF
  int v141; // [sp+11Ch] [-774h] BYREF
  idBounds v142; // [sp+120h] [-770h] BYREF
  trace_t v143; // [sp+140h] [-750h] BYREF
  idTraceModel v144; // [sp+1C0h] [-6D0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v10 = result->GetAnimStack_2(this: result);
  idAnimator_Base::End(
    this: (idAnimator_Base *)&result[1],
    stack: v10,
    curTime: GameMs,
    blendDurationMS: 0,
    reset: true);
  v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v12 = result->GetAnimStack_2(this: result);
  idAnimator_Base::End(
    this: (idAnimator_Base *)&result[1].renderModelInfo.renderParms,
    stack: v12,
    curTime: v11,
    blendDurationMS: 0,
    reset: true);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v15 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v15 != nullptr )
    idFaceMgr::Init(
      this: (idFaceMgr *)&result[1].clipModelInfo.offset.z,
      owner: result,
      ta: v15,
      mood: MOOD_NONE,
      voiceChannel: SND_CHANNEL_VOICE,
      enableMoodAnimation: true,
      enableLipSyncAnimation: true,
      enableGestureAnimation: true,
      enableEyeTracking: (const bool)v111,
      useFaceSetupEyeTracking_: (const bool)v112,
      enableBlinking: (const bool)v113,
      enableLidDeformation: v114,
      a13: v115,
      a14: v116,
      a15: v117,
      a16: v118,
      a17: v119,
      a18: v120,
      a19: v121,
      a20: v122,
      a21: v123,
      a22: v124,
      a23: v125,
      a24: v126,
      a25: v127,
      a26: v128,
      a27: v129,
      a28: 1,
      a29: v131,
      a30: false,
      a31: v132,
      a32: 1u,
      a33: v133,
      a34: 1);
  v16 = result->GetAnimStack_2(this: result);
  idDeclAnimWebNode::idModelInfo::idModelInfo(this: &v139);
  v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_BlendEq::SetBlendEquation(
    this: (idAnimator_BlendEq *)&result[1],
    animStack: v16,
    startTime: v17,
    blendEq: &byte_8200D768,
    modelInfo: &v139);
  v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_BlendEq::ParseBlendEquation(
    this: (idAnimator_BlendEq *)&result[1],
    animStack: v16,
    startTime: v18,
    modelInfo: &v139,
    a5: v22,
    a6: v21,
    a7: v20,
    a8: v19);
  if ( v16 != nullptr )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    LODWORD(v134.x) = &clientGame->gameTimeManager;
    v24 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v27 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimStack::BlendStackInternal(
      this: v16,
      currentTime: v27,
      previousTime: PreviousGameMs,
      gameMsPerFrame: GameMsPerFrame,
      ticksPerSec: v24,
      game: p_gameTimeManager,
      parallelJobList: nullptr,
      localR: nullptr,
      localS: v111,
      localT: v112,
      localU: v113);
  }
  LODWORD(v134.x) = &result[1].animStack.rememberedNodes.staticList[107];
  *(float *)&result[1].animStack.rememberedNodes.staticList[107] = 0.0;
  *(float *)&result[1].animStack.rememberedNodes.staticList[108] = 0.0;
  *(float *)&result[1].animStack.rememberedNodes.staticList[109] = 0.0;
  v28 = result->presentable;
  if ( v28 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v28 = result->presentable;
  }
  v28->model->g.castDimShadows = DIMSHADOW_HIGH_QUALITY;
  v29 = result->presentable;
  if ( v29 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v29 = result->presentable;
  }
  *((_BYTE *)&v29->model->g + 105) |= 0x10u;
  entityNumber = result->entityNumber;
  p_clip = &clientGame->clip;
  Physics = idEntity::GetPhysics(this: result);
  idPhysics::InitPhysics(
    this: Physics,
    clip_: p_clip,
    callbacks_: &result->physicsCallbacks,
    entityNumber_: entityNumber);
  v33 = result->presentable;
  v34 = nullptr;
  if ( v33 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v33 = result->presentable;
  }
  model = v33->model;
  if ( model != nullptr )
  {
    v36 = (idTreeAnimator *)_RTDynamicCast(
                              inptr: model,
                              VfDelta: 0,
                              SrcType: &idRenderModel `RTTI Type Descriptor',
                              TargetType: &idTreeAnimator `RTTI Type Descriptor',
                              isReference: 0);
    if ( v36 != nullptr )
    {
      v37 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xD8u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      LODWORD(v134.x) = v37;
      v38 = v37 != nullptr ? idClipModel::idClipModel(this: v37, clip: &clientGame->clip, animatedModel: v36) : nullptr;
      v34 = v38;
    }
    else
    {
      v39 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xD8u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      LODWORD(v134.x) = v39;
      if ( v39 != nullptr )
      {
        str = model->name.str;
        RenderModelMaterial = idEntity::GetRenderModelMaterial(this: result);
        v42 = idClipModel::idClipModel(
                this: v39,
                clip: &clientGame->clip,
                name: str,
                overrideClipMaterial: RenderModelMaterial);
      }
      else
      {
        v42 = nullptr;
      }
      v34 = v42;
    }
    if ( v34 != nullptr )
      idClipModel::SetContents(this: v34, newContents: 128);
  }
  v43 = idEntity::GetPhysics(this: result);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))v43->SetClipModel)(a1: v43, a2: v34, a3: 1.0);
  v44 = result->presentable;
  if ( v44 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v44 = result->presentable;
  }
  v45 = &v141;
  p_committed = &v44->model->committed;
  for ( i = 6; i != 0; --i )
    *++v45 = (int)*++p_committed;
  v144.offset.x = 0.0;
  v144.offset.y = 0.0;
  p_z = &v144.offset.z;
  v144.offset.z = 0.0;
  memset(&v144.type, 0, 20);
  v49 = 6;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v49;
  }
  while ( v49 != 0 );
  v144.radius = 0.0;
  v144.isConvex = false;
  v144.pad[2] = 0;
  v144.pad[1] = 0;
  v144.pad[0] = 0;
  idTraceModel::SetupBox(this: &v144, boxBounds: &v142);
  v51 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0xD8u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  LODWORD(v134.x) = v51;
  if ( v51 != nullptr )
    v52 = idClipModel::idClipModel(this: v51, clip: &clientGame->clip, trm: &v144, numTraceModels: 1, material: nullptr);
  else
    v52 = nullptr;
  if ( v52 != nullptr )
    idClipModel::SetContents(this: v52, newContents: 1);
  v53 = (float *)&result[1].animStack.rememberedNodes.staticList[86];
  *(float *)&result[1].animStack.rememberedNodes.staticList[86] = mat3_identity.mat[0].x;
  *(float *)&result[1].animStack.rememberedNodes.staticList[87] = mat3_identity.mat[0].y;
  v54 = (float *)&result[1].animStack.rememberedNodes.staticList[95];
  *(float *)&result[1].animStack.rememberedNodes.staticList[88] = mat3_identity.mat[0].z;
  LODWORD(v134.x) = &result[1].animStack.rememberedNodes.staticList[92];
  *(idVec3 *)&result[1].animStack.rememberedNodes.staticList[89] = mat3_identity.mat[1];
  *(idVec3 *)&result[1].animStack.rememberedNodes.staticList[92] = mat3_identity.mat[2];
  *(idVec3 *)&result[1].animStack.rememberedNodes.staticList[95] = vec3_origin;
  if ( !atOrigin )
  {
    v55 = DebugPlayer->presentable;
    if ( v55 != nullptr )
      v56 = (int)v55->GetPlayerInterface_2(this: v55);
    else
      v56 = 0;
    v57 = v140;
    v58 = (_DWORD *)(v56 + 46540);
    for ( j = 9; j != 0; --j )
      *++v57 = *(float *)++v58;
    v60 = DebugPlayer->presentable;
    if ( v60 != nullptr )
      v61 = (int)v60->GetPlayerInterface_2(this: v60);
    else
      v61 = 0;
    v62 = v140[2];
    v63 = (float *)(v61 + 46532);
    v134.y = -v140[2];
    v64 = v140[1];
    p_gravity = &gameLocal->clientGame.gravity;
    v66 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v67 = *(float *)(v61 + 46536);
    v134.x = -v140[1];
    v68 = v63[2];
    v69 = v140[3];
    v70 = *v63;
    v134.z = -v140[3];
    v136.y = v67;
    v136.z = v68;
    v136.x = v70;
    v71 = -p_gravity->y;
    v72 = -p_gravity->x;
    v73 = -p_gravity->z;
    _FP2 = (float)((float)((float)((float)v73 * (float)v73)
                         + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f30 }
    v76 = __frsqrte(_FP13);
    v77 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76
                                                                                        * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                                * (float)0.5))
                                                                                * (float)v76)
                                                                        - (float)1.5)
                                                        * (float)v76)
                                                * (float)((float)((float)((float)v73 * (float)v73)
                                                                + (float)((float)((float)v72 * (float)v72)
                                                                        + (float)((float)v71 * (float)v71)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v76
                                                                                * (float)((float)((float)((float)v73 * (float)v73)
                                                                                                + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                        * (float)0.5))
                                                                        * (float)v76)
                                                                - (float)1.5)
                                                * (float)v76))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v76
                                                        * (float)((float)((float)((float)v73 * (float)v73)
                                                                        + (float)((float)((float)v72 * (float)v72)
                                                                                + (float)((float)v71 * (float)v71)))
                                                                * (float)0.5))
                                                * (float)v76)
                                        - (float)1.5)
                        * (float)v76));
    v78 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                                * (float)v76)
                                                                                        * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                        * (float)v76))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v76
                                                                                                * (float)((float)((float)((float)v73 * (float)v73) + (float)((float)((float)v72 * (float)v72) + (float)((float)v71 * (float)v71))) * (float)0.5))
                                                                                        * (float)v76)
                                                                                - (float)1.5)
                                                                * (float)v76))
                                                * (float)((float)((float)((float)v73 * (float)v73)
                                                                + (float)((float)((float)v72 * (float)v72)
                                                                        + (float)((float)v71 * (float)v71)))
                                                        * (float)0.5))
                                        * (float)v77)
                                - (float)1.5)
                * (float)v77);
    v79 = (float)((float)v78 * (float)v72);
    v135.x = (float)v78 * (float)v72;
    v80 = (float)((float)v78 * (float)v71);
    v135.y = (float)v78 * (float)v71;
    v81 = (float)((float)v78 * (float)v73);
    v135.z = (float)v78 * (float)v73;
    idVec3::ProjectOntoPlane(this: &v134, normal: &v135, overBounce: 1.0);
    y = v134.y;
    _FP8 = (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z)))
                 - (float)v66);
    __asm { fsel      f6, f8, f9, f30 }
    v85 = __frsqrte(_FP6);
    v86 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v85
                                                                                        * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z)))
                                                                                                * (float)0.5))
                                                                                * (float)v85)
                                                                        - (float)1.5)
                                                        * (float)v85)
                                                * (float)((float)((float)(v134.y * v134.y)
                                                                + (float)((float)(v134.x * v134.x)
                                                                        + (float)(v134.z * v134.z)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v85
                                                                                * (float)((float)((float)(v134.y * v134.y)
                                                                                                + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z)))
                                                                                        * (float)0.5))
                                                                        * (float)v85)
                                                                - (float)1.5)
                                                * (float)v85))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v85
                                                        * (float)((float)((float)(v134.y * v134.y)
                                                                        + (float)((float)(v134.x * v134.x)
                                                                                + (float)(v134.z * v134.z)))
                                                                * (float)0.5))
                                                * (float)v85)
                                        - (float)1.5)
                        * (float)v85));
    v87 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5)
                                                                                                * (float)v85)
                                                                                        * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5)
                                                                                        * (float)v85))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v85
                                                                                                * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5))
                                                                                        * (float)v85)
                                                                                - (float)1.5)
                                                                * (float)v85))
                                                * (float)((float)((float)(v134.y * v134.y)
                                                                + (float)((float)(v134.x * v134.x)
                                                                        + (float)(v134.z * v134.z)))
                                                        * (float)0.5))
                                        * (float)v86)
                                - (float)1.5)
                * (float)v86);
    v88 = (float)(v134.z
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5) * (float)v85)
                                                                                                * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5)
                                                                                                * (float)v85))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5))
                                                                                                * (float)v85)
                                                                                        - (float)1.5)
                                                                        * (float)v85))
                                                        * (float)((float)((float)(v134.y * v134.y)
                                                                        + (float)((float)(v134.x * v134.x)
                                                                                + (float)(v134.z * v134.z)))
                                                                * (float)0.5))
                                                * (float)v86)
                                        - (float)1.5)
                        * (float)v86));
    *v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5)
                                                                                                 * (float)v85)
                                                                                         * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z)))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v85 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5)) * (float)v85) - (float)1.5)
                                                                                         * (float)v85))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v85
                                                                                                 * (float)((float)((float)(v134.y * v134.y) + (float)((float)(v134.x * v134.x) + (float)(v134.z * v134.z))) * (float)0.5))
                                                                                         * (float)v85)
                                                                                 - (float)1.5)
                                                                 * (float)v85))
                                                 * (float)((float)((float)(v134.y * v134.y)
                                                                 + (float)((float)(v134.x * v134.x)
                                                                         + (float)(v134.z * v134.z)))
                                                         * (float)0.5))
                                         * (float)v86)
                                 - (float)1.5)
                 * (float)v86)
         * v134.x;
    *(float *)&result[1].animStack.rememberedNodes.staticList[88] = v88;
    *(float *)&result[1].animStack.rememberedNodes.staticList[87] = (float)y * (float)v87;
    *(float *)&result[1].animStack.rememberedNodes.staticList[94] = v81;
    *(float *)&result[1].animStack.rememberedNodes.staticList[92] = v79;
    z = v136.z;
    *(float *)&result[1].animStack.rememberedNodes.staticList[93] = v80;
    LODWORD(v134.x) = &result[1].animStack.rememberedNodes.staticList[89];
    v90 = (float)((float)z + (float)((float)v69 * (float)96.0));
    v91 = &clientGame->clip;
    v92 = (float)(v136.y + (float)((float)v62 * (float)96.0));
    v93 = (float)(v136.x + (float)((float)v64 * (float)96.0));
    v94 = *(float *)&result[1].animStack.rememberedNodes.staticList[88];
    v95 = *v53;
    v96 = (float)(*(float *)&result[1].animStack.rememberedNodes.staticList[88] * (float)v79);
    v97 = (float)((float)v81 * *(float *)&result[1].animStack.rememberedNodes.staticList[87]);
    *(float *)&result[1].animStack.rememberedNodes.staticList[91] = (float)((float)v79
                                                                          * *(float *)&result[1].animStack.rememberedNodes.staticList[87])
                                                                  - (float)(*(float *)&result[1].animStack.rememberedNodes.staticList[86]
                                                                          * (float)v80);
    *(float *)&result[1].animStack.rememberedNodes.staticList[90] = (float)((float)v81 * (float)v95) - (float)v96;
    *(float *)&result[1].animStack.rememberedNodes.staticList[89] = (float)((float)v94 * (float)v80) - (float)v97;
    v130 = DebugPlayer->entityNumber;
    v138.x = v93;
    v138.y = v92;
    v138.z = v90;
    idClip::Translation(
      this: (idClip *)&v134,
      result: v91,
      a3: &v143,
      start: &v136,
      end: &v138,
      clipModel: v52,
      startAxis: &mat3_identity,
      clipMask: 1,
      passEntityNumber: (int)v111,
      moveClipModel: (bool)v112,
      userName: (const char *)v113,
      a12: v114,
      a13: v115,
      a14: v116,
      a15: v117,
      a16: v118,
      a17: v119,
      a18: v120,
      a19: v121,
      a20: v122,
      a21: v123,
      a22: v124,
      a23: v125,
      a24: v126,
      a25: v127,
      a26: v128,
      a27: v129,
      a28: v130,
      a29: v131,
      a30: false,
      a31: v132,
      a32: 0);
    v98 = v143.endpos.y;
    v99 = v143.endpos.z;
    *v54 = v143.endpos.x;
    *(float *)&result[1].animStack.rememberedNodes.staticList[96] = v98;
    *(float *)&result[1].animStack.rememberedNodes.staticList[97] = v99;
  }
  if ( dropToFloor )
  {
    v100 = *v54;
    v101 = *(float *)&result[1].animStack.rememberedNodes.staticList[96];
    v102 = DebugPlayer->entityNumber;
    LODWORD(v137.z) = result[1].animStack.rememberedNodes.staticList[97];
    v135.x = v100;
    v137.y = v101;
    v137.x = v100;
    v135.z = v137.z + (float)32.0;
    v137.z = v137.z - (float)256.0;
    v135.y = v101;
    idClip::Translation(
      this: (idClip *)&v134,
      result: &clientGame->clip,
      a3: &v143,
      start: &v135,
      end: &v137,
      clipModel: v52,
      startAxis: &mat3_identity,
      clipMask: 1,
      passEntityNumber: (int)v111,
      moveClipModel: (bool)v112,
      userName: (const char *)v113,
      a12: v114,
      a13: v115,
      a14: v116,
      a15: v117,
      a16: v118,
      a17: v119,
      a18: v120,
      a19: v121,
      a20: v122,
      a21: v123,
      a22: v124,
      a23: v125,
      a24: v126,
      a25: v127,
      a26: v128,
      a27: v129,
      a28: v102,
      a29: v131,
      a30: false,
      a31: v132,
      a32: 0);
    v103 = v143.endpos.y;
    v104 = v143.endpos.z;
    *v54 = v143.endpos.x;
    *(float *)&result[1].animStack.rememberedNodes.staticList[96] = v103;
    *(float *)&result[1].animStack.rememberedNodes.staticList[97] = v104;
  }
  if ( v52 != nullptr )
    idClipModel::Delete(this: v52);
  v105 = idEntity::GetPhysics(this: result);
  v105->SetOrigin(this: v105, a2: (const idVec3 *)&result[1].animStack.rememberedNodes.staticList[95], a3: -1);
  v106 = idEntity::GetPhysics(this: result);
  v106->SetAxis(this: v106, a2: (const idMat3 *)&result[1].animStack.rememberedNodes.staticList[86], a3: -1);
  v107 = (float *)result->presentable;
  if ( v107 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v107 = (float *)result->presentable;
  }
  v107[30] = *v54;
  v108 = *(float *)&result[1].animStack.rememberedNodes.staticList[96];
  LODWORD(v134.x) = v107 + 30;
  v107[31] = v108;
  v107[32] = *(float *)&result[1].animStack.rememberedNodes.staticList[97];
  v109 = (float *)result->presentable;
  if ( v109 == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    v109 = (float *)result->presentable;
  }
  v109[33] = *v53;
  LODWORD(v134.x) = v109 + 39;
  v109[34] = *(float *)&result[1].animStack.rememberedNodes.staticList[87];
  v109[35] = *(float *)&result[1].animStack.rememberedNodes.staticList[88];
  v109[36] = *(float *)&result[1].animStack.rememberedNodes.staticList[89];
  v109[37] = *(float *)&result[1].animStack.rememberedNodes.staticList[90];
  v109[38] = *(float *)&result[1].animStack.rememberedNodes.staticList[91];
  v109[39] = *(float *)&result[1].animStack.rememberedNodes.staticList[92];
  v109[40] = *(float *)&result[1].animStack.rememberedNodes.staticList[93];
  v109[41] = *(float *)&result[1].animStack.rememberedNodes.staticList[94];
  result->Show(this: result);
  idEntity::BecomeActive(this: result, flags: 5);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: &v139);
  return this;
}


// ========================================================================
// __unwind$494568
// EA  : 0x82CE7054
// RVA : 0x00CE7054
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_494568()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 2192 + 192));
}


// ========================================================================
// __unwind$494569_0
// EA  : 0x82CE707C
// RVA : 0x00CE707C
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall _unwind_494569_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2192 + 112), tag: a2);
}


// ========================================================================
// __unwind$494570
// EA  : 0x82CE70A4
// RVA : 0x00CE70A4
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall _unwind_494570(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2192 + 112), tag: a2);
}


// ========================================================================
// __unwind$494571
// EA  : 0x82CE70CC
// RVA : 0x00CE70CC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall _unwind_494571(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2192 + 112), tag: a2);
}


// ========================================================================
// ?Think@idTestModel2@@UAAXXZ
// EA  : 0x82CE70F8
// RVA : 0x00CE70F8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::Think(idTestModel2 *this)
{
  double valueFloat; // fp30
  __int64 v3; // r9
  double v4; // fp29
  __int64 v5; // r6
  double v6; // fp30
  __int64 v7; // r9
  double v8; // fp29
  __int64 v9; // r6
  double v10; // fp30
  __int64 v11; // r9
  double v12; // fp29
  __int64 v13; // r6
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v16; // r28
  idMD6LeafPlay *LastPlayedLeaf; // r3
  idMD6LeafPlay *v18; // r29
  int frameRate; // r30
  idMD6AnimData *animData; // r11
  __int64 v21; // r8
  unsigned int v22; // r30
  unsigned int GameMs; // r3
  __int64 v24; // r10
  int v25; // r8
  int v26; // r7
  int v27; // r6
  idTestModel2::translation_t translationMode; // r4
  idPlayer *Player; // r3
  idMD6LeafPlay *v30; // r30
  signed int v31; // r25
  int v32; // r3
  __int64 v33; // r10
  int v34; // r8
  int v35; // r7
  int v36; // r6
  int Frame; // r4
  const idMat3 *p_deferredAxis; // r5
  float *p_axis; // r11
  float *p_x; // r11
  double v41; // fp13
  double v42; // fp12
  double v43; // fp0
  double v44; // fp7
  double v45; // fp6
  int valueInteger; // r30
  idRenderWorld_vtbl *v47; // r29
  idMat3 *v48; // r3
  int v49; // r29
  idRenderWorld *v50; // r30
  int v51; // r30
  unsigned __int16 v52; // [sp+58h] [-118h] BYREF
  idVec3 v53; // [sp+60h] [-110h] BYREF
  idVec3 v54; // [sp+70h] [-100h] BYREF
  float v55[4]; // [sp+80h] [-F0h] BYREF
  idVec3 v56; // [sp+90h] [-E0h] BYREF
  idVec3 v57; // [sp+A0h] [-D0h] BYREF
  idMat3 v58; // [sp+B0h] [-C0h] BYREF
  idVec3 v59[2]; // [sp+D8h] [-98h] BYREF
  idMat3 v60; // [sp+F0h] [-80h] BYREF

  valueFloat = tm_yawRate.valueFloat;
  if ( tm_yawRate.valueFloat != 0.0 )
  {
    LODWORD(v3) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v4 = (float)v3;
    LODWORD(v5) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
    this->rotationAngles.yaw = idMath::AngleNormalize360(angle: (float)((float)((float)((float)v4 / (float)v5)
                                                                              * (float)valueFloat)
                                                                      + this->rotationAngles.yaw));
  }
  v6 = tm_pitchRate.valueFloat;
  if ( tm_pitchRate.valueFloat != 0.0 )
  {
    LODWORD(v7) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v8 = (float)v7;
    LODWORD(v9) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
    this->rotationAngles.pitch = idMath::AngleNormalize360(angle: (float)((float)((float)((float)v8 / (float)v9)
                                                                                * (float)v6)
                                                                        + this->rotationAngles.pitch));
  }
  v10 = tm_rollRate.valueFloat;
  if ( tm_rollRate.valueFloat != 0.0 )
  {
    LODWORD(v11) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v12 = (float)v11;
    LODWORD(v13) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
    this->rotationAngles.roll = idMath::AngleNormalize360(angle: (float)((float)((float)((float)v12 / (float)v13)
                                                                               * (float)v10)
                                                                       + this->rotationAngles.roll));
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v16 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v16 != nullptr )
  {
    v16->useDeferredPosition = tm_useDeferredPosition.valueInteger != 0;
    idTestModel2::GetOriginAxis(this, origin: v59, axis: &v58);
    if ( this->curFrame < 0.0 )
    {
      translationMode = this->translationMode;
      if ( translationMode != TRANSLATE_FIXED )
      {
        if ( (unsigned int)translationMode < TRANSLATE_MAX )
          idTestModel2::UpdateResetOrContinuous(this, tm: translationMode);
      }
      else
      {
        idTestModel2::UpdateFixed(this);
      }
    }
    else
    {
      LastPlayedLeaf = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
      v18 = LastPlayedLeaf;
      if ( LastPlayedLeaf != nullptr )
      {
        frameRate = 30;
        animData = LastPlayedLeaf->anim->animData;
        if ( animData != nullptr )
          frameRate = animData->frameRate;
        LODWORD(v21) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        v22 = (int)(float)((float)((float)v21 * this->curFrame) / (float)__SPAIR64__(v21, frameRate));
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idMD6LeafPlay::SetFrameTime(this: v18, gameTime: GameMs, targetTime: v22, a4: v27, a5: v26, a6: v25, a7: v24);
        idTreeAnimator::SetRemoveOriginRotation(this: v16, removeRotation: false);
        idTreeAnimator::SetRemoveOriginRotation(this: v16, removeRotation: false);
        idTestModel2::SetOriginAxis(this, origin: &this->resetOrigin, axis: &this->resetAxis);
      }
    }
    v54.x = 0.0;
    v54.y = 0.0;
    v54.z = 0.0;
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
      Player->GetViewTransform(this: Player, a2: &v54, a3: &v58);
    idFaceMgr::Update(this: &this->faceMgr, owner: (idAI2 *)this, ta: v16, focusPoint: &v54);
    if ( *tm_joint.valueString.data != 0 )
    {
      idDeclMD6::GetJointIndex(
        this: (idDeclMD6 *)&v52,
        result: (idIndex<short,enum invalidJointIndex_t> *)v16->decl,
        jointName: tm_joint.valueString.data);
      idTreeAnimator::GetModelSpaceJointTransform(
        this: v16,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v52,
        origin: &v53,
        axis: &v58);
      v30 = idAnimator_Channel::GetLastPlayedLeaf(this: &this->channelAnimator);
      if ( v30 != nullptr )
      {
        v31 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v32 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        Frame = (unsigned __int16)idMD6LeafPlay::GetFrame(
                                    this: v30,
                                    gameTime: v32,
                                    ticksPerSec: v31,
                                    a4: v36,
                                    a5: v35,
                                    a6: v34,
                                    a7: v33);
      }
      else
      {
        Frame = 0;
      }
      idLib::Printf(
        fmt: "frame(%d): joint '%s' ( %g %g %g )\n",
        Frame,
        (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v53.x)),
        v53.x,
        v53.y,
        v53.z);
      p_deferredAxis = &v16->deferredAxis;
      if ( v16->useDeferredPosition )
      {
        p_axis = (float *)&v16->deferredAxis;
      }
      else
      {
        p_deferredAxis = &v16->g.axis;
        p_axis = (float *)&v16->g.axis;
      }
      v41 = (float)((float)(*p_axis * v53.x) + (float)((float)(p_axis[3] * v53.y) + (float)(p_axis[6] * v53.z)));
      v42 = (float)((float)(p_axis[7] * v53.z) + (float)((float)(p_axis[1] * v53.x) + (float)(p_axis[4] * v53.y)));
      v43 = (float)((float)(p_axis[8] * v53.z) + (float)((float)(p_axis[2] * v53.x) + (float)(p_axis[5] * v53.y)));
      p_x = &v16->deferredOrigin.x;
      if ( !v16->useDeferredPosition )
        p_x = &v16->g.origin.x;
      v44 = (float)(p_x[2] + (float)v43);
      v45 = (float)(*p_x + (float)v41);
      v55[1] = p_x[1] + (float)v42;
      v55[0] = v45;
      v55[2] = v44;
      valueInteger = tm_jointTime.valueInteger;
      v47 = clientGame->renderWorld->__vftable;
      v48 = idMat3::operator*(this: &v60, result: &v58, a: p_deferredAxis);
      v47->DebugAxis_2(this: clientGame->renderWorld, a2: (const idVec3 *)v55, a3: v48, a4: valueInteger, a5: false);
    }
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    idEntity::UpdateVisuals(this);
    if ( tm_showOrigin.valueInteger > 0 )
    {
      v49 = 5000 * tm_showOrigin.valueInteger - 5000;
      v50 = gameLocal->GetRenderWorld(this: gameLocal);
      idTestModel2::GetOriginAxis(this, origin: &v56, axis: &v58);
      v50->DebugAxis_2(this: v50, a2: &v56, a3: &v58, a4: v49, a5: false);
      if ( v49 > 0 )
        v50->DebugLine(this: v50, a2: (const idVec4 *)&idColor::colorLtGrey, a3: v59, a4: &v56, a5: v49, a6: false);
    }
    if ( tm_showOriginFudge.valueInteger > 0 && idTreeAnimator::IsDeltaFudged(this: v16) )
    {
      v51 = tm_showOriginFudge.valueInteger;
      idTestModel2::GetOriginAxis(this, origin: &v57, axis: &v60);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorPink,
        a3: &v57,
        a4: 5000 * v51 - 5000,
        a5: false);
    }
  }
  else
  {
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ?SpawnTestModel@idTestModel2@@SAXPBD_N1@Z
// EA  : 0x82CE7760
// RVA : 0x00CE7760
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SpawnTestModel(const char *modelName, bool atOrigin, bool dropToFloor)
{
  idPlayer *DebugPlayer; // r4
  idRenderWorld *v5; // r3
  idRenderModel *v6; // r28
  const idDeclEntityDef *v7; // r4
  idTestModel2 *v8; // r3
  idTestModel2 *v9; // r29
  idTestModel2 *CurTestModel; // r3
  __int64 v11; // [sp+70h] [-D0h]
  int v12; // [sp+A8h] [-98h]
  const idEventArg *v13; // [sp+ACh] [-94h]
  idStr v14; // [sp+C0h] [-80h] BYREF
  idStr v15[3]; // [sp+E0h] [-60h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    v5 = gameLocal->GetRenderWorld(this: gameLocal);
    v6 = v5->AllocRenderModel(this: v5, a2: modelName, a3: false, a4: -1);
    if ( v6 != nullptr )
    {
      v7 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclEntityDef::resourceList,
                                      name: "test/testmodel2",
                                      makeDefault: false);
      if ( v7 != nullptr )
      {
        v8 = (idTestModel2 *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v7, a3: -1, a4: -1, a5: -1);
        v9 = idTestModel2::CastTo(c: v8);
        if ( v9 != nullptr )
        {
          if ( tm_removeCurrentOnSpawn.valueInteger != 0 )
          {
            CurTestModel = idGameLocal::GetCurTestModel(this: gameLocal);
            if ( CurTestModel != nullptr )
              idEventReceiver::PostEventMS(this: CurTestModel, ev: &EV_Remove, time: 0);
          }
          gameLocal->curTestModel.spawnId.value = (gameLocal->spawnIds.ptr[v9->entityNumber] << 13) | v9->entityNumber;
          v9->SetModel(this: v9, a2: v6);
          idStr::idStr(this: v15, text: modelName);
          v14.len = 0;
          v14.allocedAndFlag = 20;
          v14.data = v14.baseBuffer;
          v14.baseBuffer[0] = 0;
          idStr::ExtractFileExtension(this: v15, dest: &v14);
          if ( idStr::Cmp(s1: v14.data, s2: "prt") == 0 )
          {
            idRenderModel::SetParm(this: v6, parm: rp->TimeStop, scalar: 0.0);
            v11 = __PAIR64__(&unk_82390000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
            idRenderModel::SetParm(this: v6, parm: rp->TimeOffset, scalar: (float)((float)v11 * (float)0.001));
          }
          idEventReceiver::PostEventMS(
            this: v9,
            ev: &EV_InitTestModel,
            time: *(_DWORD *)v12,
            arg1: *(const idEventArg **)(v12 + 4),
            arg2: v13);
          idStr::FreeData(this: &v14);
          idStr::FreeData(this: v15);
        }
        else
        {
          idLib::Warning(fmt: "Failed to spawn test model.");
        }
      }
      else
      {
        idLib::Warning(fmt: "Decl 'test/testmodel2' was not found!");
      }
    }
    else
    {
      idLib::Printf(fmt: "Could not load model '%s'\n", modelName);
    }
  }
}


// ========================================================================
// __unwind$495343
// EA  : 0x82CE7A0C
// RVA : 0x00CE7A0C
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_495343()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 224));
}


// ========================================================================
// __unwind$495344
// EA  : 0x82CE7A34
// RVA : 0x00CE7A34
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_495344()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 192));
}


// ========================================================================
// ?SpawnTestModel_f@idTestModel2@@SAXABVidCmdArgs@@@Z
// EA  : 0x82CE7A60
// RVA : 0x00CE7A60
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SpawnTestModel_f(const idCmdArgs *args)
{
  int argc; // r10
  bool v3; // r28
  int v4; // r31
  const char *v5; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    argc = args->argc;
    if ( args->argc == 2 || argc == 3 )
    {
      v3 = false;
      v4 = tm_onGround.valueInteger != 0;
      if ( argc > 2 )
      {
        v4 = idStr::Icmp(s1: args->argv[2], s2: "nodrop") == 0 ? 0 : v4;
        if ( args->argc <= 2 )
          v5 = &byte_8200D768;
        else
          v5 = args->argv[2];
        if ( idStr::Icmp(s1: v5, s2: "origin") == 0 )
        {
          LOBYTE(v4) = 0;
          v3 = true;
        }
      }
      if ( args->argc <= 1 )
        idTestModel2::SpawnTestModel(modelName: &byte_8200D768, atOrigin: v3, dropToFloor: v4);
      else
        idTestModel2::SpawnTestModel(modelName: args->argv[1], atOrigin: v3, dropToFloor: v4);
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_spawn < test model name > [nodrop|origin]\n");
    }
  }
}


// ========================================================================
// ?tm_spawn_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE7B68
// RVA : 0x00CE7B68
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

// attributes: thunk
void __fastcall tm_spawn_f(const idCmdArgs *args)
{
  idTestModel2::SpawnTestModel_f(args);
}


// ========================================================================
// ?playTestModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE7B70
// RVA : 0x00CE7B70
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall playTestModel_f(const idCmdArgs *args)
{
  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 2 )
      idTestModel2::SpawnTestModel(modelName: args->argv[1], atOrigin: true, dropToFloor: false);
    else
      idLib::Printf(fmt: "USAGE: playtestModel < test model name >\n");
  }
}


// ========================================================================
// ?tm_remove_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE7BF0
// RVA : 0x00CE7BF0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_remove_f(const idCmdArgs *args)
{
  int value; // r9
  idTestModel2 *v2; // r3
  idTestModel2 *v3; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->curTestModel.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v2 = (idTestModel2 *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v2 != nullptr )
      {
        v3 = idTestModel2::CastTo(c: v2);
        if ( v3 != nullptr )
        {
          idEventReceiver::PostEventMS(this: v3, ev: &EV_Remove, time: 0);
          gameLocal->curTestModel.spawnId.value = 0x1FFF;
        }
      }
    }
  }
}


// ========================================================================
// ?tm_keep_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE7CA0
// RVA : 0x00CE7CA0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_keep_f(const idCmdArgs *args)
{
  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    idLib::Printf(fmt: "Keeping current test model...");
    gameLocal->curTestModel.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?AddAnim@idTestModel2@@QAAXABVidNamedAnim@idAnimator_BlendEq@@@Z
// EA  : 0x82CE7D08
// RVA : 0x00CE7D08
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::AddAnim(idTestModel2 *this, const idAnimator_BlendEq::idNamedAnim *namedAnim)
{
  idList<idAnimator_BlendEq::idNamedAnim,5> *p_namedAnims; // r29
  int GameMs; // r29
  idAnimStack *v5; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  idDeclAnimWebNode::idModelInfo v10[2]; // [sp+50h] [-50h] BYREF

  p_namedAnims = &this->namedAnims;
  idList<idAnimator_BlendEq::idNamedAnim,5>::Append(this: &this->namedAnims, obj: namedAnim);
  idAnimator_BlendEq::SetNamedAnims(
    this: &this->blendEqAnimator,
    anims: (const idList<idAnimator_BlendEq::idNamedAnim,33> *)p_namedAnims);
  idDeclAnimWebNode::idModelInfo::idModelInfo(this: v10);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = this->GetAnimStack_2(this);
  idAnimator_BlendEq::ParseBlendEquation(
    this: &this->blendEqAnimator,
    animStack: v5,
    startTime: GameMs,
    modelInfo: v10,
    a5: v9,
    a6: v8,
    a7: v7,
    a8: v6);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v10);
}


// ========================================================================
// __unwind$495923
// EA  : 0x82CE7D94
// RVA : 0x00CE7D94
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_495923()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 160 + 80));
}


// ========================================================================
// ?RemoveAnim@idTestModel2@@QAAXH@Z
// EA  : 0x82CE7DC8
// RVA : 0x00CE7DC8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::RemoveAnim(idTestModel2 *this, int index)
{
  int v3; // r11
  const idList<idAnimator_BlendEq::idNamedAnim,33> *p_namedAnims; // r4
  int num; // r10
  int v6; // r10
  idAnimator_BlendEq::idNamedAnim *v7; // r7
  idAnimator_BlendEq::idNamedAnim *v8; // r6
  int GameMs; // r28
  idAnimStack *v10; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  idDeclAnimWebNode::idModelInfo v15[2]; // [sp+50h] [-50h] BYREF

  v3 = index;
  if ( index < 0 )
    v3 = this->namedAnims.num - 1;
  p_namedAnims = (const idList<idAnimator_BlendEq::idNamedAnim,33> *)&this->namedAnims;
  if ( v3 >= 0 )
  {
    num = this->namedAnims.num;
    if ( v3 < num )
    {
      v6 = num - 1;
      this->namedAnims.num = v6;
      if ( v3 != v6 )
      {
        v7 = &p_namedAnims->list[v6];
        v8 = &p_namedAnims->list[v3];
        v8->anim = v7->anim;
        *(_DWORD *)&v8->wrapMode = *(_DWORD *)&v7->wrapMode;
        v8->rate = v7->rate;
      }
    }
  }
  idAnimator_BlendEq::SetNamedAnims(this: &this->blendEqAnimator, anims: p_namedAnims);
  idDeclAnimWebNode::idModelInfo::idModelInfo(this: v15);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v10 = this->GetAnimStack_2(this);
  idAnimator_BlendEq::ParseBlendEquation(
    this: &this->blendEqAnimator,
    animStack: v10,
    startTime: GameMs,
    modelInfo: v15,
    a5: v14,
    a6: v13,
    a7: v12,
    a8: v11);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v15);
}


// ========================================================================
// __unwind$495948
// EA  : 0x82CE7EBC
// RVA : 0x00CE7EBC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_495948()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetAnimProperties@idTestModel2@@QAAXHABVidNamedAnim@idAnimator_BlendEq@@I@Z
// EA  : 0x82CE7EF0
// RVA : 0x00CE7EF0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SetAnimProperties(
        idTestModel2 *this,
        int index,
        const idAnimator_BlendEq::idNamedAnim *namedAnim,
        char parseFlags)
{
  char v5; // r10
  idAnimator_BlendEq::idNamedAnim *v6; // r11
  int GameMs; // r28
  idAnimStack *v8; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  idDeclAnimWebNode::idModelInfo v13[2]; // [sp+50h] [-50h] BYREF

  if ( index < 0 || (v5 = 1, index >= this->namedAnims.num) )
    v5 = 0;
  if ( v5 != 0 )
  {
    v6 = &this->namedAnims.list[index];
    if ( (parseFlags & 1) != 0 )
      v6->wrapMode = namedAnim->wrapMode;
    if ( (parseFlags & 2) != 0 )
      v6->weightGroup = namedAnim->weightGroup;
    if ( (parseFlags & 4) != 0 )
      v6->rate = namedAnim->rate;
    if ( (parseFlags & 8) != 0 )
      v6->anim = namedAnim->anim;
    idAnimator_BlendEq::SetNamedAnims(
      this: &this->blendEqAnimator,
      anims: (const idList<idAnimator_BlendEq::idNamedAnim,33> *)&this->namedAnims);
    idDeclAnimWebNode::idModelInfo::idModelInfo(this: v13);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = this->GetAnimStack_2(this);
    idAnimator_BlendEq::ParseBlendEquation(
      this: &this->blendEqAnimator,
      animStack: v8,
      startTime: GameMs,
      modelInfo: v13,
      a5: v12,
      a6: v11,
      a7: v10,
      a8: v9);
    idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v13);
  }
}


// ========================================================================
// __unwind$495986
// EA  : 0x82CE8000
// RVA : 0x00CE8000
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_495986()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 160 + 80));
}


// ========================================================================
// ?ClearNamedAnims@idTestModel2@@QAAXXZ
// EA  : 0x82CE8030
// RVA : 0x00CE8030
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::ClearNamedAnims(idTestModel2 *this)
{
  idList<idAnimator_BlendEq::idNamedAnim,5> *p_namedAnims; // r29
  int GameMs; // r29
  idAnimStack *v4; // r3
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  idDeclAnimWebNode::idModelInfo v9[2]; // [sp+50h] [-50h] BYREF

  p_namedAnims = &this->namedAnims;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->namedAnims);
  idAnimator_BlendEq::SetNamedAnims(
    this: &this->blendEqAnimator,
    anims: (const idList<idAnimator_BlendEq::idNamedAnim,33> *)p_namedAnims);
  idDeclAnimWebNode::idModelInfo::idModelInfo(this: v9);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v4 = this->GetAnimStack_2(this);
  idAnimator_BlendEq::ParseBlendEquation(
    this: &this->blendEqAnimator,
    animStack: v4,
    startTime: GameMs,
    modelInfo: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v9);
}


// ========================================================================
// __unwind$496018
// EA  : 0x82CE80BC
// RVA : 0x00CE80BC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_496018()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetBlendEquation@idTestModel2@@QAAXPBD@Z
// EA  : 0x82CE80F0
// RVA : 0x00CE80F0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall idTestModel2::SetBlendEquation(idTestModel2 *this, const char *blendEq)
{
  int GameMs; // r25
  idAnimStack *v5; // r3
  int v6; // r27
  idAnimStack *v7; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r29
  const idAnimStack *v13; // r3
  idDeclAnimWebNode::idModelInfo v14[3]; // [sp+50h] [-70h] BYREF

  idDeclAnimWebNode::idModelInfo::idModelInfo(this: v14);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = this->GetAnimStack_2(this);
  idAnimator_BlendEq::SetBlendEquation(
    this: &this->blendEqAnimator,
    animStack: v5,
    startTime: GameMs,
    blendEq,
    modelInfo: v14);
  v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = this->GetAnimStack_2(this);
  idAnimator_BlendEq::ParseBlendEquation(
    this: &this->blendEqAnimator,
    animStack: v7,
    startTime: v6,
    modelInfo: v14,
    a5: v11,
    a6: v10,
    a7: v9,
    a8: v8);
  v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v13 = this->GetAnimStack_2(this);
  idAnimator_Base::Start(this: &this->blendEqAnimator, stack: v13, curTime: v12, blendDurationMS: 250, reset: false);
  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: v14);
}


// ========================================================================
// __unwind$496043
// EA  : 0x82CE81EC
// RVA : 0x00CE81EC
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void _unwind_496043()
{
  int v0; // r12

  idDeclAnimWebNode::idModelInfo::~idModelInfo(this: (idDeclAnimWebNode::idModelInfo *)(v0 - 192 + 80));
}


// ========================================================================
// ?tm_addAnim_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE8218
// RVA : 0x00CE8218
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_addAnim_f(const idCmdArgs *args)
{
  const idTreeAnimator *v2; // r5
  idTestModel2 *v3; // r30
  const idTestModel2 *v4; // [sp+50h] [-30h] BYREF
  idTreeAnimator *v5; // [sp+54h] [-2Ch] BYREF
  idAnimator_BlendEq::idNamedAnim v6; // [sp+58h] [-28h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 1 )
    {
      idLib::Printf(fmt: "USAGE: tm_addAnim [-wrap wrap_mode_name] [-wg weight_group_name] [-rate rate] <md6anim file name>\n");
    }
    else if ( (unsigned __int8)GetCurTestModel(curTestModel: (idEntity **)&v4, ta: &v5) != 0 )
    {
      v2 = v5;
      v3 = (idTestModel2 *)v4;
      v6.anim = nullptr;
      v6.wrapMode = 1;
      v6.weightGroup = 0;
      v6.rate = 1.0;
      v5 = nullptr;
      if ( (unsigned __int8)ParseAnimCommand(
                              args,
                              curTestModel: v4,
                              ta: v2,
                              startIndex: 1,
                              namedAnim: &v6,
                              parseFlags: (unsigned int *)&v5) != 0 )
        idTestModel2::AddAnim(this: v3, namedAnim: &v6);
    }
  }
}


// ========================================================================
// ?tm_removeAnim_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE82F8
// RVA : 0x00CE82F8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_removeAnim_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  idTestModel2 *v4; // [sp+50h] [-20h] BYREF
  idTreeAnimator *v5; // [sp+54h] [-1Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc == 1 )
    {
      idLib::Printf(fmt: "USAGE: tm_removeAnim <index>\n");
      idLib::Printf(fmt: "If <index> is < 0 then the last anim is removed.\n");
    }
    else if ( (unsigned __int8)GetCurTestModel(curTestModel: &v4, ta: &v5) != 0 )
    {
      if ( args->argc <= 1 )
        v2 = &byte_8200D768;
      else
        v2 = args->argv[1];
      v3 = atol(nptr: v2);
      idTestModel2::RemoveAnim(this: v4, index: v3);
    }
  }
}


// ========================================================================
// ?tm_setAnim_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE83B8
// RVA : 0x00CE83B8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_setAnim_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  idTestModel2 *v4; // r29
  int v5; // r30
  const idTestModel2 *v6; // r4
  idTestModel2 *v7; // [sp+50h] [-40h] BYREF
  idTreeAnimator *v8; // [sp+54h] [-3Ch] BYREF
  idAnimator_BlendEq::idNamedAnim v9[4]; // [sp+58h] [-38h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 3 )
    {
      if ( (unsigned __int8)GetCurTestModel(curTestModel: &v7, ta: &v8) != 0 )
      {
        if ( args->argc <= 1 )
          v2 = &byte_8200D768;
        else
          v2 = args->argv[1];
        v3 = atol(nptr: v2);
        v4 = v7;
        v9[0].anim = nullptr;
        v5 = v3;
        v9[0].wrapMode = 1;
        v9[0].weightGroup = 0;
        v9[0].rate = 1.0;
        v6 = v7;
        v7 = nullptr;
        if ( (unsigned __int8)ParseAnimCommand(
                                args,
                                curTestModel: v6,
                                ta: v8,
                                startIndex: 2,
                                namedAnim: v9,
                                parseFlags: (unsigned int *)&v7) != 0 )
          idTestModel2::SetAnimProperties(this: v4, index: v5, namedAnim: v9, parseFlags: (char)v7);
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: tm_removeAnim <index> [-wrap wrap_mode_name] [-wg weight_group_name] [-rate rate] [md6anim file name]\n");
    }
  }
}


// ========================================================================
// ?tm_blendEq_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE84B0
// RVA : 0x00CE84B0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_blendEq_f(const idCmdArgs *args)
{
  const char *data; // r4
  idTestModel2 *v3; // [sp+50h] [-20h] BYREF
  idTreeAnimator *v4; // [sp+54h] [-1Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr)
    && (unsigned __int8)GetCurTestModel(curTestModel: &v3, ta: &v4) != 0 )
  {
    if ( args->argc == 1 )
    {
      data = v3->blendEqAnimator.blendEq.data;
      if ( data == nullptr )
        data = &byte_8200D768;
      idLib::Printf(fmt: "tm_blendEq = '%s'\n", data);
    }
    else if ( args->argc == 2 )
    {
      idTestModel2::SetBlendEquation(this: v3, blendEq: args->argv[1]);
    }
    else
    {
      idLib::Warning(fmt: "Incorrect number of parameters");
    }
  }
}


// ========================================================================
// ?tm_clearAnims_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CE8588
// RVA : 0x00CE8588
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __fastcall tm_clearAnims_f(const idCmdArgs *args)
{
  idTestModel2 *v1; // [sp+50h] [-10h] BYREF
  idTreeAnimator *v2; // [sp+54h] [-Ch] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr)
    && (unsigned __int8)GetCurTestModel(curTestModel: &v1, ta: &v2) != 0 )
  {
    idTestModel2::ClearNamedAnims(this: v1);
    idLib::Printf(fmt: "Anims for current test model were cleared.\n");
  }
}


// ========================================================================
// `dynamic initializer for 'tm_blendInTime''
// EA  : 0x833796B0
// RVA : 0x013796B0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_blendInTime__()
{
  idCVar::idCVar(
    this: &tm_blendInTime,
    name: "tm_blendInTime",
    value: "100",
    flags: 2,
    description: "the time (in milliseconds) that animations played on a test model will take to blend in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_blendInTime__);
}


// ========================================================================
// `dynamic initializer for 'tm_showOrigin''
// EA  : 0x83379708
// RVA : 0x01379708
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_showOrigin__()
{
  idCVar::idCVar(
    this: &tm_showOrigin,
    name: "tm_showOrigin",
    value: "0",
    flags: 2,
    description: "0 = don't show origin position and rotation\n"
    "1 = show origin position and rotation\n"
    "2 = trace origin position and rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_showOrigin__);
}


// ========================================================================
// `dynamic initializer for 'tm_showOriginFudge''
// EA  : 0x83379760
// RVA : 0x01379760
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_showOriginFudge__()
{
  idCVar::idCVar(
    this: &tm_showOriginFudge,
    name: "tm_showOriginFudge",
    value: "1",
    flags: 2,
    description: "0 = don't show origin position and rotation\n"
    "1 = draw origin locations where the delta was fudged for frameset boundaries",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_showOriginFudge__);
}


// ========================================================================
// `dynamic initializer for 'tm_yawOffset''
// EA  : 0x833797B8
// RVA : 0x013797B8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_yawOffset__()
{
  idCVar::idCVar(
    this: &tm_yawOffset,
    name: "tm_yawOffset",
    value: "0",
    flags: 4,
    description: "extra offset to apply around yaw axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_yawOffset__);
}


// ========================================================================
// `dynamic initializer for 'tm_pitchOffset''
// EA  : 0x83379810
// RVA : 0x01379810
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_pitchOffset__()
{
  idCVar::idCVar(
    this: &tm_pitchOffset,
    name: "tm_pitchOffset",
    value: "0",
    flags: 4,
    description: "extra offset to apply around pitch axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_pitchOffset__);
}


// ========================================================================
// `dynamic initializer for 'tm_rollOffset''
// EA  : 0x83379868
// RVA : 0x01379868
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_rollOffset__()
{
  idCVar::idCVar(
    this: &tm_rollOffset,
    name: "tm_rollOffset",
    value: "0",
    flags: 4,
    description: "extra offset to apply around roll axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_rollOffset__);
}


// ========================================================================
// `dynamic initializer for 'tm_removeCurrentOnSpawn''
// EA  : 0x833798C0
// RVA : 0x013798C0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_removeCurrentOnSpawn__()
{
  idCVar::idCVar(
    this: &tm_removeCurrentOnSpawn,
    name: "tm_removeCurrentOnSpawn",
    value: "1",
    flags: 1,
    description: "1 = remove last test model when a new one is spawned, 0 = don't remove.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_removeCurrentOnSpawn__);
}


// ========================================================================
// `dynamic initializer for 'tm_showDeltas''
// EA  : 0x83379918
// RVA : 0x01379918
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_showDeltas__()
{
  idCVar::idCVar(
    this: &tm_showDeltas,
    name: "tm_showDeltas",
    value: "0",
    flags: 2,
    description: "1 = show translation and rotation deltas for each loop, 2 = also so deltas each frame, 0 = don't show any delta info.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_showDeltas__);
}


// ========================================================================
// `dynamic initializer for 'tm_maxLoops''
// EA  : 0x83379970
// RVA : 0x01379970
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_maxLoops__()
{
  idCVar::idCVar(
    this: &tm_maxLoops,
    name: "tm_maxLoops",
    value: "-1",
    flags: 2,
    description: "number of loops to play after tm_loop is executed. -1 means loop forever.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_maxLoops__);
}


// ========================================================================
// `dynamic initializer for 'tm_yawRate''
// EA  : 0x833799C8
// RVA : 0x013799C8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_yawRate__()
{
  idCVar::idCVar(
    this: &tm_yawRate,
    name: "tm_yawRate",
    value: "0",
    flags: 4,
    description: "rate to rotate model around yaw ( in degrees per second ).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_yawRate__);
}


// ========================================================================
// `dynamic initializer for 'tm_pitchRate''
// EA  : 0x83379A20
// RVA : 0x01379A20
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_pitchRate__()
{
  idCVar::idCVar(
    this: &tm_pitchRate,
    name: "tm_pitchRate",
    value: "0",
    flags: 4,
    description: "rate to rotate model around pitch ( in degrees per second ).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_pitchRate__);
}


// ========================================================================
// `dynamic initializer for 'tm_rollRate''
// EA  : 0x83379A78
// RVA : 0x01379A78
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_rollRate__()
{
  idCVar::idCVar(
    this: &tm_rollRate,
    name: "tm_rollRate",
    value: "0",
    flags: 4,
    description: "rate to rotate model around roll ( in degrees per second ).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_rollRate__);
}


// ========================================================================
// `dynamic initializer for 'tm_onGround''
// EA  : 0x83379AD0
// RVA : 0x01379AD0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_onGround__()
{
  idCVar::idCVar(
    this: &tm_onGround,
    name: "tm_onGround",
    value: "1",
    flags: 1,
    description: "0 = place model directly in front of view point, 1 = place model in front of view point, but on the ground.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_onGround__);
}


// ========================================================================
// `dynamic initializer for 'tm_joint''
// EA  : 0x83379B28
// RVA : 0x01379B28
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_joint__()
{
  idCVar::idCVar(
    this: &tm_joint,
    name: "tm_joint",
    value: &byte_8200D768,
    flags: 0,
    description: "name of joint to display the model-space location of",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_joint__);
}


// ========================================================================
// `dynamic initializer for 'tm_jointTime''
// EA  : 0x83379B80
// RVA : 0x01379B80
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_jointTime__()
{
  idCVar::idCVar(
    this: &tm_jointTime,
    name: "tm_jointTime",
    value: "1",
    flags: 2,
    description: "amount of time in millseconds that joint positions will remain visible",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_jointTime__);
}


// ========================================================================
// `dynamic initializer for 'tm_useDeferredPosition''
// EA  : 0x83379BD8
// RVA : 0x01379BD8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_useDeferredPosition__()
{
  idCVar::idCVar(
    this: &tm_useDeferredPosition,
    name: "tm_useDeferredPosition",
    value: "1",
    flags: 1,
    description: "1 = render the model with most recent origin",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_useDeferredPosition__);
}


// ========================================================================
// `dynamic initializer for 'tm_modifyRenderModel''
// EA  : 0x83379C30
// RVA : 0x01379C30
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_modifyRenderModel__()
{
  idCVar::idCVar(
    this: &tm_modifyRenderModel,
    name: "tm_modifyRenderModel",
    value: "1",
    flags: 1,
    description: "0 = modify the physics origin / axis, 1 = modify the render model origin / axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_modifyRenderModel__);
}


// ========================================================================
// `dynamic initializer for 'tm_useQuats''
// EA  : 0x83379C88
// RVA : 0x01379C88
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tm_useQuats__()
{
  idCVar::idCVar(
    this: &tm_useQuats,
    name: "tm_useQuats",
    value: "1",
    flags: 1,
    description: "1 = use quaternion version of ApplyOriginDeltas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tm_useQuats__);
}


// ========================================================================
// `dynamic initializer for 'tm_fixed_v''
// EA  : 0x83379CE0
// RVA : 0x01379CE0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_fixed_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_fixed_v,
           cmdName: "tm_fixed",
           function: tm_fixed_f,
           description: "selects the translation mode of the current model's origin to be fixed in place",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_reset_v''
// EA  : 0x83379D08
// RVA : 0x01379D08
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_reset_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_reset_v,
           cmdName: "tm_reset",
           function: tm_reset_f,
           description: "selects the translation mode of the current model's origin to translate but reset when anim loops",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_continuous_v''
// EA  : 0x83379D30
// RVA : 0x01379D30
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_continuous_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_continuous_v,
           cmdName: "tm_continuous",
           function: tm_continuous_f,
           description: "selects the translation mode of the current model's origin to translate continuously without resetting",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_spawn_v''
// EA  : 0x83379D58
// RVA : 0x01379D58
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_spawn_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_spawn_v,
           cmdName: "tm_spawn",
           function: tm_spawn_f,
           description: "spawns a test model",
           argCompletion: idTestModel2::ArgCompletion_Model);
}


// ========================================================================
// `dynamic initializer for 'playTestModel_v''
// EA  : 0x83379D88
// RVA : 0x01379D88
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playTestModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &playTestModel_v,
           cmdName: "playTestModel",
           function: playTestModel_f,
           description: "spawns a playtest test model",
           argCompletion: idTestModel2::ArgCompletion_PlayTestModel);
}


// ========================================================================
// `dynamic initializer for 'tm_play_v''
// EA  : 0x83379DB8
// RVA : 0x01379DB8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_play_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_play_v,
           cmdName: "tm_play",
           function: tm_play_f,
           description: "plays a non-looping animation on the current test model",
           argCompletion: idTestModel2::ArgCompletion_Anim);
}


// ========================================================================
// `dynamic initializer for 'tm_loop_v''
// EA  : 0x83379DE8
// RVA : 0x01379DE8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_loop_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_loop_v,
           cmdName: "tm_loop",
           function: tm_loop_f,
           description: "plays a looping animation on the current test model",
           argCompletion: idTestModel2::ArgCompletion_Anim);
}


// ========================================================================
// `dynamic initializer for 'tm_select_v''
// EA  : 0x83379E18
// RVA : 0x01379E18
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_select_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_select_v,
           cmdName: "tm_select",
           function: tm_removeBlendVariable_f,
           description: "selects the test model the player is looking at as the current test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_remove_v''
// EA  : 0x83379E40
// RVA : 0x01379E40
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_remove_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_remove_v,
           cmdName: "tm_remove",
           function: tm_remove_f,
           description: "removes the current test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_keep_v''
// EA  : 0x83379E68
// RVA : 0x01379E68
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_keep_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_keep_v,
           cmdName: "tm_keep",
           function: tm_keep_f,
           description: "keeps the current testmodel around even if a new one is spawned",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_vo_v''
// EA  : 0x83379E90
// RVA : 0x01379E90
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_vo_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_vo_v,
           cmdName: "tm_vo",
           function: tm_vo_f,
           description: "plays a voice over with lip-sync on the current test model",
           argCompletion: idTestModel2::ArgCompletion_VO);
}


// ========================================================================
// `dynamic initializer for 'tm_addAttach_v''
// EA  : 0x83379EC0
// RVA : 0x01379EC0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addAttach_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addAttach_v,
           cmdName: "tm_addAttach",
           function: tm_addAttach_f,
           description: "adds an attachment to the current test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_removeAttach_v''
// EA  : 0x83379EE8
// RVA : 0x01379EE8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_removeAttach_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_removeAttach_v,
           cmdName: "tm_removeAttach",
           function: tm_removeAttach_f,
           description: "removes an attachment from the current test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_addYaw_v''
// EA  : 0x83379F10
// RVA : 0x01379F10
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addYaw_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addYaw_v,
           cmdName: "tm_addYaw",
           function: tm_addYaw_f,
           description: "add the specified angle (in degrees) to the selected test model's current yaw",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_addPitch_v''
// EA  : 0x83379F38
// RVA : 0x01379F38
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addPitch_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addPitch_v,
           cmdName: "tm_addPitch",
           function: tm_addPitch_f,
           description: "add the specified angle (in degrees) to the selected test model's current pitch",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_addRoll_v''
// EA  : 0x83379F60
// RVA : 0x01379F60
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addRoll_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addRoll_v,
           cmdName: "tm_addRoll",
           function: tm_addRoll_f,
           description: "add the specified angle (in degrees) to the selected test model's current roll",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_nudge_v''
// EA  : 0x83379F88
// RVA : 0x01379F88
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_nudge_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_nudge_v,
           cmdName: "tm_nudge",
           function: tm_nudge_f,
           description: "push or pull the test model along a line from the player to the testmodel. Postive values push, negative values pull.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_frame_v''
// EA  : 0x83379FB0
// RVA : 0x01379FB0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_frame_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_frame_v,
           cmdName: "tm_frame",
           function: tm_frame_f,
           description: "set the current frame of the selected test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_nextframe_v''
// EA  : 0x83379FD8
// RVA : 0x01379FD8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_nextframe_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_nextframe_v,
           cmdName: "tm_nextframe",
           function: tm_nextframe_f,
           description: "advance the current frame by 1. Will wrap if the frame exceeds the animation length.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_prevframe_v''
// EA  : 0x8337A000
// RVA : 0x0137A000
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_prevframe_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_prevframe_v,
           cmdName: "tm_prevframe",
           function: tm_prevframe_f,
           description: "go to the previous frame. If at frame 0 this will wrap to the last frame of the animation.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_nextAlias_v''
// EA  : 0x8337A028
// RVA : 0x0137A028
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_nextAlias_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_nextAlias_v,
           cmdName: "tm_nextAlias",
           function: tm_nextAlias_f,
           description: "change the animation to the next alias in the modelDef",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_addBlendVariable_v''
// EA  : 0x8337A050
// RVA : 0x0137A050
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addBlendVariable_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addBlendVariable_v,
           cmdName: "tm_addBlendVariable",
           function: tm_removeBlendVariable_f,
           description: "add a blend variable to the blend equation animator",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_removeBlendVariable_v''
// EA  : 0x8337A078
// RVA : 0x0137A078
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_removeBlendVariable_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_removeBlendVariable_v,
           cmdName: "tm_removeBlendVariable",
           function: tm_removeBlendVariable_f,
           description: "remove a blend variable from the blend equation animator",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_addAnim_v''
// EA  : 0x8337A0A0
// RVA : 0x0137A0A0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_addAnim_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_addAnim_v,
           cmdName: "tm_addAnim",
           function: tm_addAnim_f,
           description: "add a named anim to the current test model's blend equation animator",
           argCompletion: idTestModel2::ArgCompletion_Anim);
}


// ========================================================================
// `dynamic initializer for 'tm_removeAnim_v''
// EA  : 0x8337A0D0
// RVA : 0x0137A0D0
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_removeAnim_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_removeAnim_v,
           cmdName: "tm_removeAnim",
           function: tm_removeAnim_f,
           description: "remove a named anim from the current test model's blend equation animator",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_setAnim_v''
// EA  : 0x8337A0F8
// RVA : 0x0137A0F8
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_setAnim_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_setAnim_v,
           cmdName: "tm_setAnim",
           function: tm_setAnim_f,
           description: "set the animation for a named anim in the current test model's blend equation animator",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_blendEq_v''
// EA  : 0x8337A120
// RVA : 0x0137A120
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_blendEq_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_blendEq_v,
           cmdName: "tm_blendEq",
           function: tm_blendEq_f,
           description: "set the blend equaton for the current test model",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_listAnims_v''
// EA  : 0x8337A148
// RVA : 0x0137A148
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_listAnims_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_listAnims_v,
           cmdName: "tm_listAnims",
           function: tm_listAnims_f,
           description: "lists named anims for the test model blend equation animator",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'tm_clearAnims_v''
// EA  : 0x8337A170
// RVA : 0x0137A170
// PDB : w:\tech5\tungsten\game\entities\testmodel2.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__tm_clearAnims_v__()
{
  return idCommandLink::idCommandLink(
           this: &tm_clearAnims_v,
           cmdName: "tm_clearAnims",
           function: tm_clearAnims_f,
           description: "clears all named anims for the test model blend equation animator",
           argCompletion: nullptr);
}

