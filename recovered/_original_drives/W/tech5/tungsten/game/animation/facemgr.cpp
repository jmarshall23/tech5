
// ========================================================================
// ?SetEnableEyeTracking@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2D238
// RVA : 0x00B2D238
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableEyeTracking(idFaceMgr *this, idEntity *owner, const bool enable)
{
  unsigned __int16 flags; // r11

  if ( enable )
  {
    flags = this->flags;
    this->initEyeTracking = true;
    this->flags = flags | 8;
  }
  else
  {
    this->flags &= ~8u;
  }
}


// ========================================================================
// ?SuppressBlinking@idFaceMgr@@QAAX_N@Z
// EA  : 0x82B2D270
// RVA : 0x00B2D270
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SuppressBlinking(idFaceMgr *this, const bool suppress)
{
  if ( suppress )
    this->flags |= 0x80u;
  else
    this->flags &= ~0x80u;
}


// ========================================================================
// ?SuppressLidDeformation@idFaceMgr@@QAAX_N@Z
// EA  : 0x82B2D2A0
// RVA : 0x00B2D2A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SuppressLidDeformation(idFaceMgr *this, const bool suppress)
{
  if ( suppress )
    this->flags |= 0x100u;
  else
    this->flags &= ~0x100u;
}


// ========================================================================
// ?GetFacialAnimSetDecl@idFaceMgr@@QBAPBVidDeclFacialAnimationSet@@PAVidEntity@@@Z
// EA  : 0x82B2D2D0
// RVA : 0x00B2D2D0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

const idDeclFacialAnimationSet *__fastcall idFaceMgr::GetFacialAnimSetDecl(idFaceMgr *this, idAnimatedEntity *owner)
{
  idAnimatedEntity *v2; // r3

  v2 = idAnimatedEntity::CastTo(c: owner);
  if ( v2 != nullptr )
    return v2->GetFacialAnimationSet(this: v2);
  else
    return nullptr;
}


// ========================================================================
// ?Shutdown@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2D320
// RVA : 0x00B2D320
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Shutdown(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  idAnimStack *v5; // r3
  idAnimStack *v6; // r31

  v5 = (idAnimStack *)((int (__fastcall *)(idEntity *, idFaceMgr *))owner->GetAnimStack_2)(a1: owner, a2: fm);
  v6 = v5;
  if ( v5 != nullptr )
  {
    idAnimator_Base::Shutdown(this: &this->lipAnimator, stack: v5);
    idAnimator_Base::Shutdown(this: &this->lidDeformAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->eyeAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->moodAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->headAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->faceAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->torsoAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->legsAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->bodyAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->mouthEmoteAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->browEmoteAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->faceEmoteAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->glanceAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->idleCycleAnimator, stack: v6);
    idAnimator_Base::Shutdown(this: &this->idleFidgetAnimator, stack: v6);
  }
}


// ========================================================================
// ?SortAliasesAndWeights@@YAXPAV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAMH@Z
// EA  : 0x82B2D428
// RVA : 0x00B2D428
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall SortAliasesAndWeights(
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliases,
        float *weights,
        int num)
{
  int v3; // r6
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v4; // r7
  float *v5; // r8
  double v6; // fp0
  unsigned __int16 value; // r31
  int v8; // r11
  float *v9; // r10
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v10; // r9
  unsigned __int16 v11; // r10

  v3 = 1;
  if ( num > 1 )
  {
    v4 = aliases + 1;
    v5 = weights;
    do
    {
      v6 = v5[1];
      value = v4->value;
      v8 = v3 - 1;
      if ( v6 > *v5 )
      {
        v9 = v5;
        v10 = v4 + 1;
        do
        {
          if ( v8 < 0 )
            break;
          --v8;
          v9[1] = *v9;
          v11 = v10[-2].value;
          --v10;
          v10->value = v11;
          v9 = &weights[v8];
        }
        while ( v6 > *v9 );
      }
      ++v3;
      ++v4;
      ++v5;
      weights[v8 + 1] = v6;
      aliases[v8 + 1].value = value;
    }
    while ( v3 < num );
  }
}


// ========================================================================
// ?SetEnableAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA  : 0x82B2D4C8
// RVA : 0x00B2D4C8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::SetEnableAnimation(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        const bool enable)
{
  idAnimStack *v6; // r3
  idAnimStack *v7; // r31
  idAnimator_Channel *p_bodyAnimator; // r4

  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    v7 = v6;
    if ( v6 != nullptr )
    {
      p_bodyAnimator = &this->bodyAnimator;
      if ( enable )
      {
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_bodyAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->legsAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->torsoAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->headAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->faceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->moodAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->eyeAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->lipAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->mouthEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->browEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->faceEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->glanceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->idleCycleAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
      }
      else
      {
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_bodyAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->legsAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->torsoAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->headAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->faceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->moodAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->eyeAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->lipAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->mouthEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->browEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->faceEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->glanceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->idleCycleAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
      }
    }
  }
}


// ========================================================================
// ?SetEnableGestures@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA  : 0x82B2D6F0
// RVA : 0x00B2D6F0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::SetEnableGestures(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        const bool enable)
{
  idAnimStack *v6; // r3
  idAnimStack *v7; // r31
  idAnimator_Channel *p_bodyAnimator; // r4

  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    v7 = v6;
    if ( v6 != nullptr )
    {
      p_bodyAnimator = &this->bodyAnimator;
      if ( enable )
      {
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_bodyAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->legsAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->torsoAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->headAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->faceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->mouthEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->browEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::SetAnimatorFlag(this: v7, animator: &this->faceEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
      }
      else
      {
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_bodyAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->legsAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->torsoAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->headAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->faceAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->mouthEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->browEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
        idAnimStack::ClearAnimatorFlag(this: v7, animator: &this->faceEmoteAnimator, flag: ANIMATORFLAG_ENABLED);
      }
    }
  }
}


// ========================================================================
// ?SetEnableGlancing@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA  : 0x82B2D838
// RVA : 0x00B2D838
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::SetEnableGlancing(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        const bool enable)
{
  idAnimStack *v6; // r3
  idAnimator_Channel *p_glanceAnimator; // r4

  if ( owner != nullptr )
  {
    v6 = (idAnimStack *)((int (__fastcall *)(idEntity *, idFaceMgr *))owner->GetAnimStack_2)(a1: owner, a2: fm);
    if ( v6 != nullptr )
    {
      p_glanceAnimator = &this->glanceAnimator;
      if ( enable )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_glanceAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_glanceAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?SetEnableIdleCycles@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA  : 0x82B2D8B0
// RVA : 0x00B2D8B0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::SetEnableIdleCycles(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        const bool enable)
{
  idAnimStack *v6; // r3
  idAnimator_Channel *p_idleCycleAnimator; // r4

  if ( owner != nullptr )
  {
    v6 = (idAnimStack *)((int (__fastcall *)(idEntity *, idFaceMgr *))owner->GetAnimStack_2)(a1: owner, a2: fm);
    if ( v6 != nullptr )
    {
      p_idleCycleAnimator = &this->idleCycleAnimator;
      if ( enable )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_idleCycleAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_idleCycleAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?SetEnableIdleFidgets@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA  : 0x82B2D928
// RVA : 0x00B2D928
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::SetEnableIdleFidgets(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        const bool enable)
{
  idAnimStack *v6; // r3
  idAnimator_Channel *p_idleFidgetAnimator; // r4

  if ( owner != nullptr )
  {
    v6 = (idAnimStack *)((int (__fastcall *)(idEntity *, idFaceMgr *))owner->GetAnimStack_2)(a1: owner, a2: fm);
    if ( v6 != nullptr )
    {
      p_idleFidgetAnimator = &this->idleFidgetAnimator;
      if ( enable )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?Shutdown@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2D9A0
// RVA : 0x00B2D9A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::Shutdown(idFaceMgr *this, idEntity *owner, idTreeAnimator *ta)
{
  idFaceAnimator::Shutdown(this: &this->faceAnimator, fm: this, owner, ta);
}


// ========================================================================
// ?DormantEnd@idFaceMgr@@QAAXPAVidEntity@@H@Z
// EA  : 0x82B2D9B8
// RVA : 0x00B2D9B8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::DormantEnd(idFaceMgr *this, idAI2 *owner, const int timeDormant)
{
  idAI2 *v4; // r3
  const idDeclAIBehavior *decl; // r29
  __int16 maxBlinkInterval; // r11
  int v7; // r28
  int v8; // r27
  int GameMs; // r25
  double valueFloat; // fp31
  __int64 v11; // r7
  int jitterMinInterval; // r28
  int jitterMaxInterval; // r29
  int v14; // r31

  v4 = idAI2::CastTo(c: owner);
  if ( v4 != nullptr )
  {
    decl = v4->aiEditable.behaviors.decl;
    if ( decl != nullptr )
    {
      maxBlinkInterval = decl->maxBlinkInterval;
      v7 = maxBlinkInterval;
      v8 = maxBlinkInterval;
    }
    else
    {
      v7 = 500;
      v8 = 7500;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    valueFloat = face_blinkScale.valueFloat;
    LODWORD(v11) = GetRandomInterval(_min: v7, _max: v8);
    this->nextBlinkTime = (int)(float)((float)((float)v11 * (float)valueFloat) + (float)__SPAIR64__(v11, GameMs));
    if ( decl != nullptr )
    {
      jitterMinInterval = decl->jitterMinInterval;
      jitterMaxInterval = decl->jitterMaxInterval;
    }
    else
    {
      jitterMinInterval = 100;
      jitterMaxInterval = 1500;
    }
    v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->nextJitterTime = GetRandomInterval(_min: jitterMinInterval, _max: jitterMaxInterval) + v14;
  }
}


// ========================================================================
// ?SetEnableAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DAC8
// RVA : 0x00B2DAC8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableAnimation(idFaceMgr *this, idEntity *owner, bool enable)
{
  unsigned __int16 v5; // r10

  idFaceAnimator::SetEnableAnimation(this: &this->faceAnimator, fm: this, owner, enable);
  if ( enable )
    v5 = this->flags | 0x200;
  else
    v5 = this->flags & 0xFDFF;
  this->flags = v5;
}


// ========================================================================
// ?SetEnableMoodAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DB38
// RVA : 0x00B2DB38
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableMoodAnimation(idFaceMgr *this, idEntity *owner, bool enable)
{
  BOOL v3; // r30
  unsigned __int16 v4; // r9
  idFaceAnimator *p_faceAnimator; // r31
  idAnimStack *v6; // r3
  const idAnimator_Base *p_moodAnimator; // r4

  v3 = enable;
  if ( enable )
    v4 = this->flags | 1;
  else
    v4 = this->flags & 0xFFFE;
  this->flags = v4;
  p_faceAnimator = &this->faceAnimator;
  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    if ( v6 != nullptr )
    {
      p_moodAnimator = &p_faceAnimator->moodAnimator;
      if ( v3 )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_moodAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_moodAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?SetEnableLipSyncAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DBD0
// RVA : 0x00B2DBD0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableLipSyncAnimation(idFaceMgr *this, idEntity *owner, bool enable)
{
  BOOL v3; // r30
  unsigned __int16 v4; // r9
  idFaceAnimator *p_faceAnimator; // r31
  idAnimStack *v6; // r3
  const idAnimator_Base *p_lipAnimator; // r4

  v3 = enable;
  if ( enable )
    v4 = this->flags | 2;
  else
    v4 = this->flags & 0xFFFD;
  this->flags = v4;
  p_faceAnimator = &this->faceAnimator;
  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    if ( v6 != nullptr )
    {
      p_lipAnimator = &p_faceAnimator->lipAnimator;
      if ( v3 )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_lipAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_lipAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?SetEnableGestureAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DC70
// RVA : 0x00B2DC70
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableGestureAnimation(idFaceMgr *this, idEntity *owner, bool enable)
{
  unsigned __int16 v3; // r10

  if ( enable )
    v3 = this->flags | 4;
  else
    v3 = this->flags & 0xFFFB;
  this->flags = v3;
  idFaceAnimator::SetEnableGestures(this: &this->faceAnimator, fm: this, owner, enable);
}


// ========================================================================
// ?SetEnableBlinking@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DCB0
// RVA : 0x00B2DCB0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableBlinking(idFaceMgr *this, idEntity *owner, bool enable)
{
  BOOL v3; // r30
  unsigned __int16 v4; // r9
  idFaceAnimator *p_faceAnimator; // r31
  idAnimStack *v6; // r3
  const idAnimator_Base *p_eyeAnimator; // r4

  v3 = enable;
  if ( enable )
    v4 = this->flags | 0x10;
  else
    v4 = this->flags & 0xFFEF;
  this->flags = v4;
  p_faceAnimator = &this->faceAnimator;
  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    if ( v6 != nullptr )
    {
      p_eyeAnimator = &p_faceAnimator->eyeAnimator;
      if ( v3 )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_eyeAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_eyeAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?SetEnableLidDeformation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82B2DD50
// RVA : 0x00B2DD50
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::SetEnableLidDeformation(idFaceMgr *this, idEntity *owner, bool enable)
{
  BOOL v3; // r30
  unsigned __int16 v4; // r9
  idFaceAnimator *p_faceAnimator; // r31
  idAnimStack *v6; // r3
  const idAnimator_Base *p_lidDeformAnimator; // r4

  v3 = enable;
  if ( enable )
    v4 = this->flags | 0x20;
  else
    v4 = this->flags & 0xFFDF;
  this->flags = v4;
  p_faceAnimator = &this->faceAnimator;
  if ( owner != nullptr )
  {
    v6 = owner->GetAnimStack_2(this: owner);
    if ( v6 != nullptr )
    {
      p_lidDeformAnimator = &p_faceAnimator->lidDeformAnimator;
      if ( v3 )
        idAnimStack::SetAnimatorFlag(this: v6, animator: p_lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v6, animator: p_lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
}


// ========================================================================
// ?CalcEyeFocusPoint@idFaceMgr@@AAA?AVidVec3@@ABV2@0PBVidEyeInfo@@W4eye_t@3@@Z
// EA  : 0x82B2DDF0
// RVA : 0x00B2DDF0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

idFaceMgr *__fastcall idFaceMgr::CalcEyeFocusPoint(
        idFaceMgr *this,
        idVec3 *result,
        const idVec3 *focusPoint,
        const idVec3 *eyeDelta,
        const idEyeInfo *eyeInfo,
        const idEyeInfo::eye_t eye)
{
  idEyeInfo::perEyeInfo_t *v9; // r29
  double v10; // fp0
  double v11; // fp5
  double wanderRate; // fp7
  double v13; // fp1
  double v14; // fp10
  double v15; // fp12
  __int32 v16; // r28
  long double v17; // fp2
  long double v18; // fp2
  long double v19; // fp2
  float *p_z; // r11
  double x; // fp11
  double y; // fp8
  __int64 v24; // [sp+50h] [-40h]

  v9 = &eyeInfo->perEyeInfo[eye];
  if ( eye != EYE_LEFT )
    v10 = -1.0;
  else
    v10 = 1.0;
  v11 = (float)(result[154].z * eyeInfo->perEyeInfo[eye].jitterScale);
  wanderRate = eyeInfo->perEyeInfo[eye].wanderRate;
  v13 = (float)(result[155].y * eyeInfo->perEyeInfo[eye].jitterScale);
  v14 = (float)(focusPoint->z
              + (float)(eyeDelta->z * (float)((float)(v9->focusScale * (float)v10) * face_eyeSpreadScale.valueFloat)));
  v15 = (float)(focusPoint->x
              + (float)(eyeDelta->x * (float)((float)(v9->focusScale * (float)v10) * face_eyeSpreadScale.valueFloat)));
  *(float *)&this->mood = (float)(focusPoint->y
                                + (float)(eyeDelta->y
                                        * (float)((float)(eyeInfo->perEyeInfo[eye].focusScale * (float)v10)
                                                * face_eyeSpreadScale.valueFloat)))
                        + (float)(result[155].x * eyeInfo->perEyeInfo[eye].jitterScale);
  *(float *)&this->lastMood = (float)v14 + (float)v13;
  *(float *)&this->__vftable = (float)v15 + (float)v11;
  if ( wanderRate != 0.0 )
  {
    v24 = __PAIR64__(
            &unk_82390000,
            idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
    v16 = 4 * (eye + 473);
    *(double *)&v17 = idMath::AngleNormalize360(angle: (float)((float)(v9->wanderRate
                                                                     * (float)((float)v24 * (float)0.001))
                                                             + *(float *)((char *)&result->x + v16)));
    *(float *)((char *)&result->x + v16) = *(double *)&v17;
    v18 = sin(x: v17);
    result[eye + 155].z = (float)(v9->maxWanderPitch * (float)*(double *)&v18) + result[eye + 155].z;
    *(double *)&v18 = *(float *)((char *)&result->x + v16);
    v19 = cos(x: v18);
    result[eye + 156].x = (float)(v9->maxWanderYaw * (float)*(double *)&v19) + result[eye + 156].x;
  }
  p_z = &result[eye + 155].z;
  x = result[eye + 156].x;
  *p_z = v9->angleOffset.pitch + *p_z;
  y = result[eye + 156].y;
  p_z[1] = v9->angleOffset.yaw + (float)x;
  p_z[2] = v9->angleOffset.roll + (float)y;
  return this;
}


// ========================================================================
// ?AlignEye@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@ABVidVec3@@ABVidMat3@@3PBVidEyeInfo@@W4eye_t@7@AAVidAngles@@@Z
// EA  : 0x82B2DFC0
// RVA : 0x00B2DFC0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::AlignEye(
        idFaceMgr *this,
        idEntity *owner,
        idTreeAnimator *ta,
        idIndex<short,enum invalidJointIndex_t> *eyeJoint,
        const idVec3 *eyeJointPos,
        const idMat3 *eyeJointAxis,
        const idVec3 *focusPoint,
        const idEyeInfo *eyeInfo,
        const idEyeInfo::eye_t eye,
        idAngles *offsetAngle,
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
        int a28,
        int a29,
        idQuat *a30)
{
  double v36; // fp9
  double v37; // fp6
  double v38; // fp11
  double v41; // fp5
  double v42; // fp7
  double v43; // fp5
  double v44; // fp0
  double v45; // fp27
  double z; // fp8
  double v47; // fp4
  double v48; // fp7
  double v49; // fp5
  double v50; // fp1
  double v51; // fp31
  double v52; // fp1
  idQuat *v53; // r3
  double minEyeYaw; // fp0
  double x; // fp12
  double minEyePitch; // fp0
  double v57; // fp13
  const idMat3 *v58; // r3
  bool v59; // r27
  double v60; // fp7
  bool v61; // r30
  double v62; // fp3
  double v63; // fp7
  double v64; // fp10
  double v65; // fp5
  idMat3 *p_deferredAxis; // r4
  idAngles *v67; // r3
  double v68; // fp9
  double v69; // fp7
  idColor *v70; // r30
  idVec3 *v71; // r3
  double v72; // fp6
  double v73; // fp12
  double v74; // fp4
  idAngles v75; // [sp+50h] [-1D0h] BYREF
  idQuat v76; // [sp+60h] [-1C0h] BYREF
  float v77[4]; // [sp+70h] [-1B0h] BYREF
  float v78[4]; // [sp+80h] [-1A0h] BYREF
  float v79[4]; // [sp+90h] [-190h] BYREF
  idQuat v80; // [sp+A0h] [-180h] BYREF
  idVec3 v81; // [sp+B0h] [-170h] BYREF
  float v82[4]; // [sp+C0h] [-160h] BYREF
  float v83[4]; // [sp+D0h] [-150h] BYREF
  idMat3 v84; // [sp+E0h] [-140h] BYREF
  idMat3 v85; // [sp+110h] [-110h] BYREF
  idQuat v86; // [sp+150h] [-D0h] BYREF
  idAngles v87; // [sp+160h] [-C0h] BYREF
  float w; // [sp+16Ch] [-B4h]
  idVec3 v89; // [sp+170h] [-B0h] BYREF
  idAngles v90[6]; // [sp+180h] [-A0h] BYREF

  idTreeAnimator::GetWorldSpaceJointTransform(
    this: ta,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)eyeInfo->basisJointIndex.value,
    origin: &v89,
    axis: (idMat3 *)&v85.mat[1].y);
  v36 = (float)(focusPoint->z - eyeJointPos->z);
  v37 = (float)(focusPoint->y - eyeJointPos->y);
  v38 = (float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x))
              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)));
  _FP10 = (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x))
                        + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f10, f11, f13 }
  v41 = __frsqrte(_FP7);
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x)) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41)
                                              * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x)
                                                                      * (float)(focusPoint->x - eyeJointPos->x))
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                              * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x))
                                                                                              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                      * (float)0.5))
                                                                      * (float)v41)
                                                              - (float)1.5)
                                              * (float)v41))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v41
                                                      * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x)
                                                                              * (float)(focusPoint->x - eyeJointPos->x))
                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41));
  v43 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x)) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41)
                                                      * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x)
                                                                              * (float)(focusPoint->x - eyeJointPos->x))
                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x)) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v41
                                                              * (float)((float)((float)((float)(focusPoint->x
                                                                                              - eyeJointPos->x)
                                                                                      * (float)(focusPoint->x
                                                                                              - eyeJointPos->x))
                                                                              + (float)((float)((float)v37 * (float)v37)
                                                                                      + (float)((float)v36 * (float)v36)))
                                                                      * (float)0.5))
                                                      * (float)v41)
                                              - (float)1.5)
                              * (float)v41))
              * (float)((float)((float)((float)(focusPoint->x - eyeJointPos->x) * (float)(focusPoint->x - eyeJointPos->x))
                              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                      * (float)0.5));
  v44 = (float)((float)(focusPoint->y - eyeJointPos->y)
              * (float)((float)-(float)((float)((float)v43 * (float)v42) - (float)1.5) * (float)v42));
  v75.pitch = (float)(focusPoint->x - eyeJointPos->x)
            * (float)((float)-(float)((float)((float)v43 * (float)v42) - (float)1.5) * (float)v42);
  v75.yaw = v44;
  v75.roll = (float)v36 * (float)((float)-(float)((float)((float)v43 * (float)v42) - (float)1.5) * (float)v42);
  v45 = (float)((float)((float)-(float)((float)((float)v43 * (float)v42) - (float)1.5) * (float)v42) * (float)v38);
  idVec3::ToAngles(this: (idVec3 *)&v84.mat[1].y, result: &v75);
  idMat3::ToAngles(this: &v84, result: (idAngles *)&v85.mat[1].y);
  if ( face_debugEyes.valueInteger > 0 )
  {
    z = eyeJointPos->z;
    v47 = (float)(eyeJointPos->y + (float)(v85.mat[1].z * (float)128.0));
    v83[0] = eyeJointPos->x + (float)(v85.mat[1].y * (float)128.0);
    v83[1] = v47;
    v83[2] = (float)z + (float)(v85.mat[2].x * (float)128.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorBlue,
      a3: eyeJointPos,
      a4: v83,
      a5: 4.0);
    v48 = eyeJointPos->z;
    v49 = (float)(eyeJointPos->y + (float)(v75.yaw * (float)128.0));
    v82[0] = eyeJointPos->x + (float)(v75.pitch * (float)128.0);
    v82[1] = v49;
    v82[2] = (float)v48 + (float)(v75.roll * (float)128.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: eyeJointPos,
      a4: v82,
      a5: 4.0);
  }
  v50 = idMath::AngleNormalize360(angle: (float)(v84.mat[1].z - v84.mat[0].y));
  v51 = v50;
  if ( v50 > 180.0 )
    v51 = (float)((float)v50 - (float)360.0);
  v52 = idMath::AngleNormalize360(angle: (float)(v84.mat[1].y - v84.mat[0].x));
  if ( v52 > 180.0 )
    v52 = (float)((float)v52 - (float)360.0);
  v80.x = v52;
  v80.y = v51;
  v80.z = 0.0;
  idAngles::ToQuat(this: (idAngles *)&v86, result: &v80);
  idAngles::ToQuat(this: (idAngles *)&v84.mat[2].z, result: a30);
  v53 = idQuat::Slerp(
          this: (idQuat *)&v84.mat[2].z,
          from: (const idQuat *)&v84.mat[2].z,
          to: &v86,
          t: eyeInfo->perEyeInfo[a28].slerpScale);
  v87.pitch = v53->x;
  v87.yaw = v53->y;
  v87.roll = v53->z;
  w = v53->w;
  idQuat::ToAngles(this: &v76, result: &v87);
  minEyeYaw = eyeInfo->minEyeYaw;
  if ( v76.y >= minEyeYaw )
  {
    if ( v76.y <= (double)eyeInfo->maxEyeYaw )
      minEyeYaw = v76.y;
    else
      minEyeYaw = eyeInfo->maxEyeYaw;
  }
  x = v76.x;
  a30->y = minEyeYaw;
  minEyePitch = eyeInfo->minEyePitch;
  if ( x >= minEyePitch )
  {
    if ( x <= eyeInfo->maxEyePitch )
      minEyePitch = x;
    else
      minEyePitch = eyeInfo->maxEyePitch;
  }
  v57 = v76.z;
  a30->x = minEyePitch;
  a30->z = v57;
  v58 = idAngles::ToMat3(this: v90, result: (idMat3 *)a30);
  idTreeAnimator::SetJointAxis(
    this: ta,
    pose: (animationPose_t)0,
    jointIndex: eyeJoint,
    type: JOINTMOD_LOCAL_OVERRIDE,
    axis: v58);
  if ( face_debugEyes.valueInteger > 0 )
  {
    v59 = a30->y != v76.y;
    v60 = eyeJointPos->z;
    v61 = a30->x != v76.x;
    v62 = (float)(eyeJointPos->y + (float)(v75.yaw * (float)v45));
    v78[0] = eyeJointPos->x + (float)(v75.pitch * (float)v45);
    v78[1] = v62;
    v78[2] = (float)v60 + (float)(v75.roll * (float)v45);
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorMagenta,
      a3: eyeJointPos,
      a4: v78,
      a5: 4.0);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: eyeJointPos,
      a4: 0,
      a5: false);
    v63 = eyeJointPos->z;
    v64 = (float)(eyeJointAxis->mat[0].z * (float)32.0);
    v65 = (float)(eyeJointPos->y + (float)(eyeJointAxis->mat[0].y * (float)32.0));
    v79[0] = eyeJointPos->x + (float)(eyeJointAxis->mat[0].x * (float)32.0);
    v79[1] = v65;
    v79[2] = (float)v63 + (float)v64;
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorCyan,
      a3: eyeJointPos,
      a4: v79,
      a5: 4.0);
    p_deferredAxis = &ta->deferredAxis;
    if ( !ta->useDeferredPosition )
      p_deferredAxis = &ta->g.axis;
    v67 = idMat3::ToAngles(this: &v85, result: (idAngles *)p_deferredAxis);
    v68 = (float)(v67->roll + a30->z);
    v69 = (float)(v67->yaw + a30->y);
    v81.x = a30->x + v67->pitch;
    v81.z = v68;
    v81.y = v69;
    if ( v59 || v61 )
      v70 = &idColor::colorRed;
    else
      v70 = &idColor::colorOrange;
    v71 = idAngles::ToForward(this: (idAngles *)&v85, result: &v81);
    v72 = (float)(v71->z * (float)32.0);
    v73 = eyeJointPos->z;
    v74 = (float)(eyeJointPos->y + (float)(v71->y * (float)32.0));
    v77[0] = eyeJointPos->x + (float)(v71->x * (float)32.0);
    v77[1] = v74;
    v77[2] = (float)v73 + (float)v72;
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: v70,
      a3: eyeJointPos,
      a4: v77,
      a5: 4.0);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorWhite,
      a3: focusPoint,
      a4: 0,
      a5: false);
  }
}


// ========================================================================
// ?AnimateBlinks@idFaceMgr@@QBA_NXZ
// EA  : 0x82B2E5A0
// RVA : 0x00B2E5A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceMgr::AnimateBlinks(idFaceMgr *this)
{
  unsigned __int16 flags; // r11
  unsigned __int8 v2; // r11

  flags = this->flags;
  if ( (flags & 0x10) == 0 )
    return 0;
  if ( (flags & 0x80) != 0 )
    return 0;
  if ( face_skipBlink.valueInteger != 0 )
    return 0;
  v2 = 1;
  if ( face_skipProcedural.valueInteger != 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?StartLipSync@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2E5F8
// RVA : 0x00B2E5F8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::StartLipSync(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  idAnimator_EndAdditiveChannels *p_lipAnimator; // r31
  idAnimStack *v5; // r30
  __int64 v6; // r8
  int v7; // r4
  double valueFloat; // fp31
  int GameMs; // r3
  int v10; // r6

  p_lipAnimator = &this->lipAnimator;
  v5 = (idAnimStack *)((int (__fastcall *)(idEntity *, idFaceMgr *))owner->GetAnimStack_2)(a1: owner, a2: fm);
  if ( idAnimator_Base::IsEnabled(this: p_lipAnimator, animStack: v5) )
  {
    idAnimator_EndAdditiveChannels::SetExternalBlend(
      this: p_lipAnimator,
      blendTarget: 1.0,
      blendMS: v7,
      a4: 0xFAu,
      a5: v6);
    valueFloat = face_lipsyncWeight.valueFloat;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimator_Base::Blend(
      this: p_lipAnimator,
      stack: v5,
      curTime: GameMs,
      targetAlpha: valueFloat,
      blendDurationMS: v10,
      reset: 250,
      a7: 1);
  }
}


// ========================================================================
// ?AnimateMood@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2E6B8
// RVA : 0x00B2E6B8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::AnimateMood(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  const idAnimStack *v6; // r29
  char v7; // r11
  mood_t mood; // r11
  int v9; // r3
  __int64 v10; // r8
  int GameMs; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v12; // [sp+50h] [-50h] BYREF
  blendParms_t v13[3]; // [sp+60h] [-40h] BYREF

  v6 = owner->GetAnimStack_2(this: owner);
  if ( (fm->flags & 1) == 0 || (v7 = 1, face_skipMood.valueInteger != 0) )
    v7 = 0;
  if ( v7 != 0 )
  {
    mood = fm->mood;
    if ( (unsigned int)mood < MOOD_HAPPY || mood == MOOD_MAX || (v12.value = fm->moodTable[mood].value) == 0xFFFF )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Base::End(this: &this->moodAnimator, stack: v6, curTime: GameMs, blendDurationMS: 250, reset: true);
    }
    else
    {
      blendParms_t::blendParms_t(this: v13);
      blendParms_t::SetDurationMS(this: v13, ms: 0xFAu);
      v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v10) = v13;
      idAnimator_Channel::CycleAnim(
        this: &this->moodAnimator,
        stack: v6,
        ah: &v12,
        curTime: v9,
        rateScale: 1.0,
        leafStarted: v10,
        a7: nullptr);
    }
  }
}


// ========================================================================
// ?Reset@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2E7E0
// RVA : 0x00B2E7E0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Reset(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  const idAnimStack *v5; // r28
  int GameMs; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r3

  v5 = owner->GetAnimStack_2(this: owner);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->bodyAnimator, stack: v5, curTime: GameMs, blendDurationMS: 250, reset: true);
  v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->legsAnimator, stack: v5, curTime: v7, blendDurationMS: 250, reset: true);
  v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->torsoAnimator, stack: v5, curTime: v8, blendDurationMS: 250, reset: true);
  v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->headAnimator, stack: v5, curTime: v9, blendDurationMS: 250, reset: true);
  v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->faceAnimator, stack: v5, curTime: v10, blendDurationMS: 250, reset: true);
  v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->lipAnimator, stack: v5, curTime: v11, blendDurationMS: 250, reset: true);
  v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->glanceAnimator, stack: v5, curTime: v12, blendDurationMS: 250, reset: true);
  v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->idleCycleAnimator, stack: v5, curTime: v13, blendDurationMS: 250, reset: true);
  v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->idleFidgetAnimator, stack: v5, curTime: v14, blendDurationMS: 250, reset: true);
}


// ========================================================================
// ?LipSyncFinished@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2E988
// RVA : 0x00B2E988
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::LipSyncFinished(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta)
{
  idAnimStack *v6; // r3
  faceChannel_t clearChannel; // r11
  const idAnimStack *v8; // r29
  int GameMs; // r5
  idAnimator_Channel *p_legsAnimator; // r3
  int v11; // r3

  v6 = owner->GetAnimStack_2(this: owner);
  clearChannel = fm->clearChannel;
  v8 = v6;
  if ( (unsigned int)clearChannel <= FACECHANNEL_FACE )
  {
    switch ( clearChannel )
    {
      case FACECHANNEL_LEGS:
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        p_legsAnimator = &this->legsAnimator;
LABEL_15:
        idAnimator_Base::End(this: p_legsAnimator, stack: v8, curTime: GameMs, blendDurationMS: 250, reset: true);
        goto LABEL_16;
      case FACECHANNEL_TORSO:
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        p_legsAnimator = &this->torsoAnimator;
        goto LABEL_15;
      case FACECHANNEL_HEAD:
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        p_legsAnimator = &this->headAnimator;
        goto LABEL_15;
      default:
        break;
    }
    if ( clearChannel != FACECHANNEL_EYES
      && clearChannel != FACECHANNEL_EMOTE_MOUTH
      && clearChannel != FACECHANNEL_EMOTE_BROW
      && clearChannel != FACECHANNEL_EMOTE_FACE )
    {
      if ( clearChannel != FACECHANNEL_BODY )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        p_legsAnimator = &this->faceAnimator;
      }
      else
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        p_legsAnimator = &this->bodyAnimator;
      }
      goto LABEL_15;
    }
  }
LABEL_16:
  v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Base::End(this: &this->lipAnimator, stack: v8, curTime: v11, blendDurationMS: 250, reset: true);
}


// ========================================================================
// ?PlayAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4faceChannel_t@@MHHH_N@Z
// EA  : 0x82B2EAC0
// RVA : 0x00B2EAC0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::PlayAnimation(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        const faceChannel_t channel,
        double rateScale,
        const int startFrame,
        int blendInDurationMS,
        const int blendOutDurationMS,
        const bool cycleAnim,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        idHandle<unsigned short,enum invalidAliasHandle_t,65535> a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        unsigned int a29,
        int a30,
        idMD6LeafPlay **a31,
        int a32,
        char a33)
{
  const idAnimStack *v37; // r29
  idAnimator_Channel *p_bodyAnimator; // r31
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  __int64 v41; // r8
  int v42; // r3
  const blendParms_t *v43; // r7
  blendParms_t v44; // [sp+50h] [-50h] BYREF

  a21.value = (unsigned __int16)aliasHandle;
  v37 = owner->GetAnimStack_2(this: owner);
  blendParms_t::blendParms_t(this: &v44);
  blendParms_t::SetDurationMS(this: &v44, ms: a29);
  blendParms_t::SetDestStartFrame(this: &v44, frame: blendInDurationMS);
  switch ( channel )
  {
    case FACECHANNEL_BODY:
    case FACECHANNEL_MAX:
      p_bodyAnimator = &this->bodyAnimator;
      goto LABEL_11;
    case FACECHANNEL_LEGS:
      p_bodyAnimator = &this->legsAnimator;
      goto LABEL_11;
    case FACECHANNEL_TORSO:
      p_bodyAnimator = &this->torsoAnimator;
      goto LABEL_11;
    case FACECHANNEL_HEAD:
      p_bodyAnimator = &this->headAnimator;
      goto LABEL_11;
    case FACECHANNEL_EYES:
      p_bodyAnimator = &this->eyeAnimator;
      goto LABEL_11;
    case FACECHANNEL_EMOTE_MOUTH:
      p_bodyAnimator = &this->mouthEmoteAnimator;
      goto LABEL_11;
    case FACECHANNEL_EMOTE_BROW:
      p_bodyAnimator = &this->browEmoteAnimator;
      goto LABEL_11;
    case FACECHANNEL_EMOTE_FACE:
      p_bodyAnimator = &this->faceEmoteAnimator;
      goto LABEL_11;
    case FACECHANNEL_FACE:
      p_bodyAnimator = &this->faceAnimator;
LABEL_11:
      p_gameTimeManager = &clientGame->gameTimeManager;
      if ( a33 != 0 )
      {
        GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        LODWORD(v41) = &v44;
        idAnimator_Channel::CycleAnim(
          this: p_bodyAnimator,
          stack: v37,
          ah: &a21,
          curTime: GameMs,
          rateScale,
          leafStarted: v41,
          a7: nullptr);
      }
      else
      {
        v42 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        idAnimator_Channel::PlayAnim(
          this: p_bodyAnimator,
          stack: v37,
          ah: &a21,
          curTime: v42,
          rateScale,
          blendParms: v43,
          blendOutDurationMS_: &v44,
          leafStarted: a31,
          a9: nullptr);
      }
      break;
    default:
      return;
  }
}


// ========================================================================
// ?PlayWebAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@PAVidAnimator_AnimWeb@@ABVidAnimWebPath@@@Z
// EA  : 0x82B2EC40
// RVA : 0x00B2EC40
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::PlayWebAnimation(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta,
        idAnimator_AnimWeb *webAnimator,
        idAnimWebPath *webPath)
{
  idStr v8; // [sp+50h] [-80h] BYREF
  idStr v9; // [sp+70h] [-60h] BYREF
  idStr v10[2]; // [sp+90h] [-40h] BYREF

  if ( webAnimator != nullptr )
  {
    v10[0].len = 0;
    v10[0].allocedAndFlag = 20;
    v10[0].data = v10[0].baseBuffer;
    v10[0].baseBuffer[0] = 0;
    v9.allocedAndFlag = 20;
    v9.data = v9.baseBuffer;
    v9.len = 0;
    v9.baseBuffer[0] = 0;
    v8.allocedAndFlag = 20;
    v8.data = v8.baseBuffer;
    v8.len = 0;
    v8.baseBuffer[0] = 0;
    idAnimWebPath::GetWebPathNames(this: webPath, webName: v10, subWebName: &v9, stateName: &v8);
    if ( idAnimator_AnimWeb::ChangeState(
           this: webAnimator,
           subWebName: v9.data,
           stateName: v8.data,
           interruptPath_: INTR_PATH_YES,
           interruptBlend_: INTR_BLEND_NO,
           blendEventMask_: 0) == 0 )
      idLib::Warning(fmt: "idFaceAnimator::PlayWebAnimation - failed to path to '%s'", webPath->data);
    idStr::FreeData(this: &v8);
    idStr::FreeData(this: &v9);
    idStr::FreeData(this: v10);
  }
}


// ========================================================================
// __unwind$492382
// EA  : 0x82B2ED0C
// RVA : 0x00B2ED0C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_492382()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$492383
// EA  : 0x82B2ED34
// RVA : 0x00B2ED34
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_492383()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$492384
// EA  : 0x82B2ED5C
// RVA : 0x00B2ED5C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_492384()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?AnimateEyes@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@PBVidEyeInfo@@PBV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBMH@Z
// EA  : 0x82B2ED88
// RVA : 0x00B2ED88
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::AnimateEyes(
        idFaceAnimator *this,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta,
        const idEyeInfo *eyeInfo,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *lidAliases,
        const float *lidWeights,
        int numAliases)
{
  char *v10; // r10
  int v13; // ctr
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v16; // r9
  char *v17; // r10
  const float *v18; // r11
  int i; // ctr
  int v20; // r5
  int v21; // r31
  int v22; // r11
  float *v23; // r10
  float *v24; // r10
  const idAnimStack *v25; // r30
  char v26; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int v28; // r3
  int GameMs; // r3
  char v30; // [sp+4Eh] [-62h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v31[6]; // [sp+50h] [-60h] BYREF
  char v32; // [sp+5Ch] [-54h] BYREF
  float v33; // [sp+60h] [-50h] BYREF
  char v34; // [sp+64h] [-4Ch] BYREF

  v10 = &v30;
  v13 = 5;
  v16 = lidAliases - 1;
  do
  {
    ++v16;
    v10 += 2;
    *(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v10 = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)v16->value;
    --v13;
  }
  while ( v13 != 0 );
  v17 = &v32;
  v18 = lidWeights - 1;
  for ( i = 5; i != 0; --i )
  {
    ++v18;
    v17 += 4;
    *(float *)v17 = *v18;
  }
  SortAliasesAndWeights(aliases: v31, weights: &v33, num: numAliases);
  v21 = 0;
  v22 = 0;
  if ( v20 < 4 )
  {
LABEL_12:
    if ( v22 < v20 )
    {
      v24 = &v33 + v22;
      do
      {
        if ( *v24 <= 0.0 )
          break;
        ++v22;
        ++v21;
        ++v24;
      }
      while ( v22 < v20 );
    }
  }
  else
  {
    v23 = (float *)&v34;
    while ( *(v23 - 1) > 0.0 )
    {
      if ( *v23 <= 0.0 )
      {
        ++v21;
        break;
      }
      if ( v23[1] <= 0.0 )
      {
        v21 += 2;
        break;
      }
      if ( v23[2] <= 0.0 )
      {
        v21 += 3;
        break;
      }
      v22 += 4;
      v21 += 4;
      v23 += 4;
      if ( v22 >= v20 - 3 )
        goto LABEL_12;
    }
  }
  v25 = owner->GetAnimStack_2(this: owner);
  if ( (fm->flags & 0x100) != 0
    || face_skipLidDeform.valueInteger != 0
    || (v26 = 1, face_skipProcedural.valueInteger != 0) )
  {
    v26 = 0;
  }
  if ( v26 != 0 )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( *lidWeights < 1.0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Synced::SetAnimHandlesAndWeights(
        this: &this->lidDeformAnimator,
        animator: ta,
        curTime: GameMs,
        handles: v31,
        numAnims: v21,
        weights: &v33,
        numWeights: v21);
    }
    else
    {
      v28 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Base::End(this: &this->lidDeformAnimator, stack: v25, curTime: v28, blendDurationMS: 250, reset: true);
    }
  }
}


// ========================================================================
// ?Blink@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2EF80
// RVA : 0x00B2EF80
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Blink(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  idEntity_vtbl *v5; // r10
  const idAnimStack *v6; // r30
  int GameMs; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v8; // [sp+50h] [-40h] BYREF
  blendParms_t v9; // [sp+60h] [-30h] BYREF

  v5 = owner->__vftable;
  v8.value = fm->blinkAlias.value;
  v6 = v5->GetAnimStack_2(this: owner);
  blendParms_t::blendParms_t(this: &v9);
  blendParms_t::SetDurationMS(this: &v9, ms: 0x64u);
  blendParms_t::SetDestStartFrame(this: &v9, frame: 0);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Channel::PlayAnim(
    this: &this->eyeAnimator,
    stack: v6,
    ah: &v8,
    curTime: GameMs,
    rateScale: 1.0,
    blendParms: (const blendParms_t *)0x82000000,
    blendOutDurationMS_: &v9,
    leafStarted: (idMD6LeafPlay **)0x64,
    a9: nullptr);
}


// ========================================================================
// ?Glance@idFaceAnimator@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F030
// RVA : 0x00B2F030
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Glance(
        idFaceAnimator *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta)
{
  const idAnimStack *v7; // r29
  int GameMs; // r3
  const blendParms_t *v9; // r7
  blendParms_t v10[3]; // [sp+50h] [-40h] BYREF

  v7 = owner->GetAnimStack_2(this: owner);
  blendParms_t::blendParms_t(this: v10);
  blendParms_t::SetDurationMS(this: v10, ms: 0x64u);
  blendParms_t::SetDestStartFrame(this: v10, frame: 0);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Channel::PlayAnim(
    this: &this->glanceAnimator,
    stack: v7,
    ah: aliasHandle,
    curTime: GameMs,
    rateScale: 1.0,
    blendParms: v9,
    blendOutDurationMS_: v10,
    leafStarted: (idMD6LeafPlay **)0x64,
    a9: nullptr);
}


// ========================================================================
// ?Fidget@idFaceAnimator@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F0C8
// RVA : 0x00B2F0C8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Fidget(
        idFaceAnimator *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasHandle,
        idFaceMgr *fm,
        idEntity *owner,
        idTreeAnimator *ta)
{
  const idAnimStack *v7; // r29
  int GameMs; // r3
  const blendParms_t *v9; // r7
  blendParms_t v10[3]; // [sp+50h] [-40h] BYREF

  v7 = owner->GetAnimStack_2(this: owner);
  blendParms_t::blendParms_t(this: v10);
  blendParms_t::SetDurationMS(this: v10, ms: 0x64u);
  blendParms_t::SetDestStartFrame(this: v10, frame: 0);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_Channel::PlayAnim(
    this: &this->idleFidgetAnimator,
    stack: v7,
    ah: aliasHandle,
    curTime: GameMs,
    rateScale: 1.0,
    blendParms: v9,
    blendOutDurationMS_: v10,
    leafStarted: (idMD6LeafPlay **)0x64,
    a9: nullptr);
}


// ========================================================================
// ?IsCurrentlyGlancing@idFaceAnimator@@QBA_NPAVidEntity@@@Z
// EA  : 0x82B2F160
// RVA : 0x00B2F160
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

BOOL __fastcall idFaceAnimator::IsCurrentlyGlancing(idFaceAnimator *this, idEntity *owner)
{
  const idAnimStack *v3; // r30
  int GameMs; // r3

  v3 = owner->GetAnimStack_2(this: owner);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (_cntlzw(idAnimator_Channel::IsDone(this: &this->glanceAnimator, stack: v3, curTime: GameMs)) & 0x20) != 0;
}


// ========================================================================
// ?IsCurrentlyFidgeting@idFaceAnimator@@QBA_NPAVidEntity@@@Z
// EA  : 0x82B2F1E0
// RVA : 0x00B2F1E0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

BOOL __fastcall idFaceAnimator::IsCurrentlyFidgeting(idFaceAnimator *this, idEntity *owner)
{
  const idAnimStack *v3; // r30
  int GameMs; // r3

  v3 = owner->GetAnimStack_2(this: owner);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (_cntlzw(idAnimator_Channel::IsDone(this: &this->idleFidgetAnimator, stack: v3, curTime: GameMs)) & 0x20) != 0;
}


// ========================================================================
// ?GetVoiceTrackTime@idFaceMgr@@ABA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@PAVidEntity@@PBVidVoiceTrack@@@Z
// EA  : 0x82B2F260
// RVA : 0x00B2F260
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

idFaceMgr *__fastcall idFaceMgr::GetVoiceTrackTime(
        idFaceMgr *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result,
        idEntity *owner,
        const idVoiceTrack *voiceTrack)
{
  idFaceMgr_vtbl *framenum; // r11
  const idTypesafeNumber<int,enum millisecondUnique_t> *v6; // r3
  idTypesafeNumber<int,enum gameTimeUnique_t> v8; // [sp+50h] [-20h] BYREF
  char v9; // [sp+54h] [-1Ch] BYREF

  if ( face_syncToGameTime.valueInteger == 0
    && ((*(_BYTE *)&voiceTrack->flags & 2) != 0 || face_syncToRealTime.valueInteger != 0) )
  {
    if ( result[27].value >= 0 )
    {
      framenum = (idFaceMgr_vtbl *)(clientGame->soundWorld->GetSoundTime(this: clientGame->soundWorld) - result[27].value);
      goto LABEL_9;
    }
  }
  else if ( result[29].value >= 0 )
  {
    v8.value = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
             - result[29].value;
    v6 = (const idTypesafeNumber<int,enum millisecondUnique_t> *)gameLocal->GetGameTimeManager(this: gameLocal);
    framenum = (idFaceMgr_vtbl *)idGameTimeManager::ConvertTimeGameToReal(
                                   this: (idGameTimeManager *)&v9,
                                   result: v6,
                                   ticks: &v8)->framenum;
    goto LABEL_9;
  }
  framenum = nullptr;
LABEL_9:
  this->__vftable = framenum;
  return this;
}


// ========================================================================
// ?LipSyncFinished@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F370
// RVA : 0x00B2F370
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::LipSyncFinished(idFaceMgr *this, idEntity *owner, idTreeAnimator *ta)
{
  char *data; // r29
  const char *str; // r25
  int GameMs; // r3
  int v9; // r3
  unsigned __int16 flags; // r11
  mood_t defaultMood; // r10

  if ( face_debug.valueInteger > 0 )
  {
    data = owner->name.data;
    str = this->voiceOver->name.str;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d) %s - LipSyncFinished VO '%s'.\n", GameMs, data, str);
  }
  idFaceAnimator::LipSyncFinished(this: &this->faceAnimator, fm: this, owner, ta);
  this->lastSoundShader = nullptr;
  this->voiceOver = nullptr;
  this->voiceTrackIndex = -1;
  this->vtrackStartTime.value = -1;
  this->lastSampleTime.value = -1;
  this->startedVO = false;
  v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  flags = this->flags;
  defaultMood = this->defaultMood;
  this->endLipsyncTime.value = v9;
  this->flags = flags & 0xF77F;
  this->mood = defaultMood;
  idFaceAnimator::SetEnableGlancing(this: &this->faceAnimator, fm: this, owner, enable: true);
  this->flags &= ~0x2000u;
  idFaceAnimator::SetEnableIdleCycles(this: &this->faceAnimator, fm: this, owner, enable: true);
  this->flags &= ~0x8000u;
  idFaceAnimator::SetEnableIdleFidgets(this: &this->faceAnimator, fm: this, owner, enable: true);
}


// ========================================================================
// ?ReallyStartVoiceOver@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F4B0
// RVA : 0x00B2F4B0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::ReallyStartVoiceOver(idFaceMgr *this, idAI2 *owner, idTreeAnimator *ta)
{
  int GameMs; // r3
  int v7; // r3
  int voiceTrackIndex; // r11
  const idDeclVoiceOver *voiceOver; // r10
  const idVoiceTrack *v10; // r28
  mood_t defaultMood; // r10
  unsigned __int16 v12; // r10
  const char *data; // r27
  faceChannel_t faceChannel; // r24
  idAI2 *v15; // r26
  faceChannel_t v16; // r11
  idVoiceTrack *v17; // r3
  const char *str; // r29
  const char *v19; // r28
  const char *v20; // r27
  int v21; // r3
  idPresentable *presentable; // r4
  int v23; // r3
  int value; // r11
  int v25; // [sp+8h] [-F8h]
  bool v26; // [sp+Fh] [-F1h]
  int v27; // [sp+10h] [-F0h]
  int v28; // [sp+14h] [-ECh]
  int v29; // [sp+18h] [-E8h]
  int v30; // [sp+1Ch] [-E4h]
  int v31; // [sp+20h] [-E0h]
  int v32; // [sp+24h] [-DCh]
  int v33; // [sp+28h] [-D8h]
  int v34; // [sp+2Ch] [-D4h]
  int v35; // [sp+30h] [-D0h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v36; // [sp+34h] [-CCh]
  int v37; // [sp+38h] [-C8h]
  int v38; // [sp+3Ch] [-C4h]
  int v39; // [sp+40h] [-C0h]
  int v40; // [sp+44h] [-BCh]
  int v41; // [sp+48h] [-B8h]
  int v42; // [sp+4Ch] [-B4h]
  int v43; // [sp+50h] [-B0h]
  int v44; // [sp+58h] [-A8h]
  int v45; // [sp+60h] [-A0h]
  unsigned __int16 v46; // [sp+70h] [-90h] BYREF
  idStrId v47; // [sp+74h] [-8Ch] BYREF
  idStr v48[4]; // [sp+80h] [-80h] BYREF

  if ( face_debugTime.valueInteger != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d)idFaceMgr: ReallyStartVoiceOver\n", GameMs);
  }
  v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  voiceTrackIndex = this->voiceTrackIndex;
  voiceOver = this->voiceOver;
  this->vtrackStartTime.value = v7;
  this->startedVO = true;
  if ( voiceTrackIndex < 0 || voiceTrackIndex >= voiceOver->tracks.num )
    v10 = nullptr;
  else
    v10 = voiceOver->tracks.list[voiceTrackIndex];
  v47.index = v10->soundOffsetMS;
  if ( v47.index != 0 )
  {
    this->startSoundTime.value = v47.index;
  }
  else
  {
    idEntity::StartSoundShader(
      this: owner,
      channel: (const soundChannel_t)this->voiceChannel,
      shader: this->lastSoundShader,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    this->startSoundTime.value = -1;
  }
  this->lastSampleTime.value = 0;
  defaultMood = v10->defaultMood;
  if ( defaultMood != MOOD_NONE )
  {
    this->mood = defaultMood;
    this->defaultMood = v10->defaultMood;
  }
  if ( (*(_BYTE *)&v10->flags & 0x10) != 0 )
    v12 = this->flags | 0x80;
  else
    v12 = this->flags & 0xFF7F;
  this->flags = v12;
  this->flags = v12 | 0x800;
  idFaceAnimator::SetEnableGlancing(this: &this->faceAnimator, fm: this, owner, enable: false);
  this->flags |= 0x2000u;
  idFaceAnimator::SetEnableIdleCycles(this: &this->faceAnimator, fm: this, owner, enable: false);
  this->flags |= 0x8000u;
  idFaceAnimator::SetEnableIdleFidgets(this: &this->faceAnimator, fm: this, owner, enable: false);
  data = v10->animName.data;
  if ( data != nullptr && *data != 0 )
  {
    faceChannel = v10->faceChannel;
    if ( faceChannel == FACECHANNEL_BODYWEB )
    {
      v15 = idAI2::CastTo(c: owner);
      if ( v15 != nullptr )
      {
        idStr::idStr(this: v48, text: data);
        idFaceAnimator::PlayWebAnimation(
          this: &this->faceAnimator,
          fm: this,
          owner,
          ta,
          webAnimator: (idAnimator_AnimWeb *)&v15->aiVolatile.animation,
          webPath: (idAnimWebPath *)v48);
        idStr::FreeData(this: v48);
      }
    }
    else
    {
      idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)&v46, result: ta->decl, aliasName: v10->animName.data);
      idFaceAnimator::PlayAnimation(
        this: &this->faceAnimator,
        fm: this,
        owner,
        ta,
        aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v46,
        channel: faceChannel,
        rateScale: 1.0,
        startFrame: *(_BYTE *)&v10->flags >> 7,
        blendInDurationMS: 0,
        blendOutDurationMS: v25,
        cycleAnim: v26,
        a12: v27,
        a13: v28,
        a14: v29,
        a15: v30,
        a16: v31,
        a17: v32,
        a18: v33,
        a19: v34,
        a20: v35,
        a21: v36,
        a22: v37,
        a23: v38,
        a24: v39,
        a25: v40,
        a26: v41,
        a27: v42,
        a28: v43,
        a29: v10->blendInMS,
        a30: v44,
        a31: (idMD6LeafPlay **)v10->blendOutMS,
        a32: v45,
        a33: *(_BYTE *)&v10->flags >> 7);
    }
    v16 = faceChannel;
    if ( (*(_BYTE *)&v10->flags & 0x40) == 0 )
      v16 = FACECHANNEL_MAX;
    this->clearChannel = v16;
  }
  if ( (this->flags & 2) != 0 )
    idFaceAnimator::StartLipSync(this: &this->faceAnimator, fm: this, owner, ta);
  if ( face_debug.valueInteger > 0 )
  {
    v17 = v10;
    str = v10->name.str;
    v19 = this->lastSoundShader->name.str;
    v20 = this->voiceOver->name.str;
    v21 = idVoiceTrack::Memory(this: v17);
    idLib::Printf(fmt: "StartVoiceOver:\n  vo: %s\n  voiceTrack: %s size: %d\n  soundShader: %s\n", v20, str, v21, v19);
  }
  presentable = owner->presentable;
  v47.index = -1;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: owner);
    presentable = owner->presentable;
  }
  idGameLocal::PlayedVoiceOver(
    this: gameLocal,
    whoStartedMe: presentable,
    target: nullptr,
    vo: this->voiceOver,
    voiceTrackIndex: this->voiceTrackIndex,
    whoStartedMeText: &v47);
  v23 = clientGame->soundWorld->GetSoundTime(this: clientGame->soundWorld);
  value = this->vtrackDuration.value;
  this->realStartTime.value = v23;
  this->realEndTime.value = value + v23;
}


// ========================================================================
// __unwind$493250
// EA  : 0x82B2F808
// RVA : 0x00B2F808
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_493250()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?Reset@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F830
// RVA : 0x00B2F830
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::Reset(idFaceMgr *this, idEntity *owner, idTreeAnimator *ta)
{
  idFaceAnimator::Reset(this: &this->faceAnimator, fm: this, owner, ta);
  this->lastSoundShader = nullptr;
  this->voiceOver = nullptr;
  this->voiceTrackIndex = -1;
}


// ========================================================================
// ?RecentlyPlayedVoiceOver@idFaceMgr@@QBA_NV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82B2F880
// RVA : 0x00B2F880
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

unsigned int __fastcall idFaceMgr::RecentlyPlayedVoiceOver(
        idFaceMgr *this,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *threshold)
{
  int GameMs; // r3

  if ( this->endLipsyncTime.value <= 0 )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (threshold->value >> 31)
       + (threshold->value >= (unsigned int)(GameMs - this->endLipsyncTime.value))
       + ((unsigned int)(GameMs - this->endLipsyncTime.value) >> 31);
}


// ========================================================================
// ?StartVOIfStreamedSampleIsReady@idFaceMgr@@AAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidVoiceTrack@@@Z
// EA  : 0x82B2F900
// RVA : 0x00B2F900
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceMgr::StartVOIfStreamedSampleIsReady(
        idFaceMgr *this,
        idAI2 *owner,
        idTreeAnimator *ta,
        const idVoiceTrack *voiceTrack)
{
  const idSoundShader *soundShader; // r11
  idSoundSample_XAudio2 *v9; // r3

  soundShader = voiceTrack->soundShader;
  this->lastSoundShader = soundShader;
  if ( soundShader == nullptr )
  {
    if ( s_noSound.valueInteger == 0 )
      idLib::Warning(fmt: "voiceTrack '%s' has no sound shader!", voiceTrack->name.str);
    return 0;
  }
  if ( soundShader->entries.num <= 0 )
    return 0;
  v9 = *soundShader->entries.list;
  if ( v9 == nullptr )
    return 0;
  if ( v9->streamedLength == 0 || (int)idSoundSample_XAudio2::PreCacheStreamData(this: v9, highPriority: true) > 0 )
    idFaceMgr::ReallyStartVoiceOver(this, owner, ta);
  return 1;
}


// ========================================================================
// ?SelectNewGlanceIndex@idFaceMgr@@ABAHPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2F9B8
// RVA : 0x00B2F9B8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

encounterGroupRole_t __fastcall idFaceMgr::SelectNewGlanceIndex(
        idFaceMgr *this,
        idAnimatedEntity *owner,
        idTreeAnimator *ta)
{
  idAnimatedEntity *v5; // r3
  int v6; // r3
  idFaceMgr::attentionLevel_t focusAttentionLevel; // r11
  _DWORD *v8; // r29
  double v9; // fp0
  idDeclMD6 *decl; // r28
  int v11; // r10
  int v12; // r30
  int v13; // r11
  int v14; // r11
  unsigned int seed; // r8
  int num; // r7
  unsigned int v17; // r3
  int v18; // r10
  encounterGroupRole_t v19; // r30
  int v21; // [sp+50h] [-50h] BYREF
  idList<enum encounterGroupRole_t,5> v22[4]; // [sp+60h] [-40h] BYREF

  v5 = idAnimatedEntity::CastTo(c: owner);
  if ( v5 != nullptr )
    v6 = (int)v5->GetFacialAnimationSet(this: v5);
  else
    v6 = 0;
  focusAttentionLevel = this->focusAttentionLevel;
  v8 = (_DWORD *)(v6 + 64);
  if ( focusAttentionLevel != ATTENTION_LOW )
  {
    if ( focusAttentionLevel == ATTENTION_MODERATE )
    {
      v9 = 0.70710677;
    }
    else
    {
      if ( (unsigned int)focusAttentionLevel >= ATTENTION_MAX )
        goto LABEL_11;
      v9 = 0.9238795;
    }
  }
  else
  {
    v9 = -1.0;
  }
  minGlanceDot = v9;
LABEL_11:
  memset(v22, 0, 14);
  v22[0].memTag = 5;
  v22[0].listStatic = 0;
  decl = ta->decl;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v22);
  v11 = v8[1];
  v12 = 0;
  v21 = 0;
  if ( v11 > 0 )
  {
    do
    {
      if ( idDeclMD6::AnimForAlias(
             this: decl,
             aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)(2 * v12 + *v8),
             load: false) != nullptr )
        idList<idAnimWebBlendTree *,5>::Append(this: v22, obj: (const encounterGroupRole_t *)&v21);
      v13 = v8[1];
      v21 = ++v12;
    }
    while ( v12 < v13 );
  }
  if ( v22[0].num <= 0 )
  {
    if ( (v22[0].listStatic == 0 || v22[0].listStatic == 2) && v22[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v22[0].list, align: ALIGN_16);
    return -1;
  }
  else
  {
    if ( v22[0].num - 1 > 0 )
    {
      seed = clientGame->random.seed;
      num = v22[0].num;
      __twllei(v22[0].num, 0);
      v17 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v17;
      v18 = (v17 >> 10) & 0x7FFF;
      v14 = v18 % num;
      __twlgei(num & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      v14 = 0;
    }
    v19 = v22[0].list[v14];
    if ( (v22[0].listStatic == 0 || v22[0].listStatic == 2) && v22[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v22[0].list, align: ALIGN_16);
    return v19;
  }
}


// ========================================================================
// __unwind$493787
// EA  : 0x82B2FBA4
// RVA : 0x00B2FBA4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_493787()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ?SelectNewFidgetIndex@idFaceMgr@@ABAHPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B2FBD8
// RVA : 0x00B2FBD8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

encounterGroupRole_t __fastcall idFaceMgr::SelectNewFidgetIndex(
        idFaceMgr *this,
        idAnimatedEntity *owner,
        idTreeAnimator *ta)
{
  idAnimatedEntity *v4; // r3
  int v5; // r11
  _DWORD *v6; // r29
  idDeclMD6 *decl; // r28
  int v8; // r9
  int v9; // r30
  int v10; // r11
  int v11; // r11
  unsigned int seed; // r8
  int num; // r7
  unsigned int v14; // r3
  int v15; // r10
  encounterGroupRole_t v16; // r30
  int v18; // [sp+50h] [-50h] BYREF
  idList<enum encounterGroupRole_t,5> v19[4]; // [sp+60h] [-40h] BYREF

  v4 = idAnimatedEntity::CastTo(c: owner);
  if ( v4 != nullptr )
    v5 = (int)v4->GetFacialAnimationSet(this: v4);
  else
    v5 = 0;
  memset(v19, 0, 14);
  v19[0].memTag = 5;
  v6 = (_DWORD *)(v5 + 64);
  v19[0].listStatic = 0;
  decl = ta->decl;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v19);
  v8 = v6[1];
  v9 = 0;
  v18 = 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( idDeclMD6::AnimForAlias(
             this: decl,
             aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)(2 * v9 + *v6),
             load: false) != nullptr )
        idList<idAnimWebBlendTree *,5>::Append(this: v19, obj: (const encounterGroupRole_t *)&v18);
      v10 = v6[1];
      v18 = ++v9;
    }
    while ( v9 < v10 );
  }
  if ( v19[0].num <= 0 )
  {
    if ( (v19[0].listStatic == 0 || v19[0].listStatic == 2) && v19[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v19[0].list, align: ALIGN_16);
    return -1;
  }
  else
  {
    if ( v19[0].num - 1 > 0 )
    {
      seed = clientGame->random.seed;
      num = v19[0].num;
      __twllei(v19[0].num, 0);
      v14 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v14;
      v15 = (v14 >> 10) & 0x7FFF;
      v11 = v15 % num;
      __twlgei(num & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      v11 = 0;
    }
    v16 = v19[0].list[v11];
    if ( (v19[0].listStatic == 0 || v19[0].listStatic == 2) && v19[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v19[0].list, align: ALIGN_16);
    return v16;
  }
}


// ========================================================================
// __unwind$493932_0
// EA  : 0x82B2FD84
// RVA : 0x00B2FD84
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_493932_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ??1idFaceAnimator@@UAA@XZ
// EA  : 0x82B2FDB8
// RVA : 0x00B2FDB8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::~idFaceAnimator(idFaceAnimator *this)
{
  this->__vftable = (idFaceAnimator_vtbl *)&idFaceAnimator::`vftable';
  idAnimator_Channel::~idAnimator_Channel(this: &this->idleFidgetAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->idleCycleAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->glanceAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->faceEmoteAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->browEmoteAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->mouthEmoteAnimator);
  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: &this->lipAnimator);
  idAnimator_Synced::~idAnimator_Synced(this: &this->lidDeformAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->eyeAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->moodAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->faceAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->headAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->torsoAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->legsAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->bodyAnimator);
  this->__vftable = (idFaceAnimator_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$494122
// EA  : 0x82B2FE80
// RVA : 0x00B2FE80
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494122()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$494123
// EA  : 0x82B2FEA8
// RVA : 0x00B2FEA8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494123()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$494124
// EA  : 0x82B2FED4
// RVA : 0x00B2FED4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494124()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$494125
// EA  : 0x82B2FF00
// RVA : 0x00B2FF00
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494125()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 196));
}


// ========================================================================
// __unwind$494126
// EA  : 0x82B2FF2C
// RVA : 0x00B2FF2C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494126()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 292));
}


// ========================================================================
// __unwind$494127
// EA  : 0x82B2FF58
// RVA : 0x00B2FF58
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494127()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$494128
// EA  : 0x82B2FF84
// RVA : 0x00B2FF84
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494128()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 484));
}


// ========================================================================
// __unwind$494129
// EA  : 0x82B2FFB0
// RVA : 0x00B2FFB0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494129()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 580));
}


// ========================================================================
// __unwind$494130
// EA  : 0x82B2FFDC
// RVA : 0x00B2FFDC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494130()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 112 + 132) + 676));
}


// ========================================================================
// __unwind$494131
// EA  : 0x82B30008
// RVA : 0x00B30008
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494131()
{
  int v0; // r12

  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: (idAnimator_EndAdditiveChannels *)(*(_DWORD *)(v0 - 112 + 132) + 964));
}


// ========================================================================
// __unwind$494132
// EA  : 0x82B30034
// RVA : 0x00B30034
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494132()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1132));
}


// ========================================================================
// __unwind$494133
// EA  : 0x82B30060
// RVA : 0x00B30060
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494133()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1228));
}


// ========================================================================
// __unwind$494134
// EA  : 0x82B3008C
// RVA : 0x00B3008C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494134()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1324));
}


// ========================================================================
// __unwind$494135
// EA  : 0x82B300B8
// RVA : 0x00B300B8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494135()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1420));
}


// ========================================================================
// __unwind$494136
// EA  : 0x82B300E4
// RVA : 0x00B300E4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494136()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1516));
}


// ========================================================================
// ??1idFaceMgr@@UAA@XZ
// EA  : 0x82B30118
// RVA : 0x00B30118
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::~idFaceMgr(idFaceMgr *this)
{
  this->__vftable = (idFaceMgr_vtbl *)&idFaceMgr::`vftable';
  idFaceAnimator::~idFaceAnimator(this: &this->faceAnimator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemeTable);
  this->__vftable = (idFaceMgr_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$494278
// EA  : 0x82B30178
// RVA : 0x00B30178
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494278()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$494279
// EA  : 0x82B301A0
// RVA : 0x00B301A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494279()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// ??0idFaceAnimator@@QAA@XZ
// EA  : 0x82B301D8
// RVA : 0x00B301D8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

idFaceAnimator *__fastcall idFaceAnimator::idFaceAnimator(idFaceAnimator *this)
{
  this->__vftable = (idFaceAnimator_vtbl *)&idFaceAnimator::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->bodyAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->legsAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->torsoAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->headAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->faceAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->moodAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->eyeAnimator);
  idAnimator_Synced::idAnimator_Synced(this: &this->lidDeformAnimator);
  idAnimator_EndAdditiveChannels::idAnimator_EndAdditiveChannels(this: &this->lipAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->mouthEmoteAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->browEmoteAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->faceEmoteAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->glanceAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->idleCycleAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->idleFidgetAnimator);
  return this;
}


// ========================================================================
// __unwind$494307
// EA  : 0x82B30298
// RVA : 0x00B30298
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494307()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$494308
// EA  : 0x82B302C0
// RVA : 0x00B302C0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494308()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$494309
// EA  : 0x82B302EC
// RVA : 0x00B302EC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494309()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$494310
// EA  : 0x82B30318
// RVA : 0x00B30318
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494310()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 196));
}


// ========================================================================
// __unwind$494311
// EA  : 0x82B30344
// RVA : 0x00B30344
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494311()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 292));
}


// ========================================================================
// __unwind$494312
// EA  : 0x82B30370
// RVA : 0x00B30370
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494312()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$494313
// EA  : 0x82B3039C
// RVA : 0x00B3039C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494313()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 484));
}


// ========================================================================
// __unwind$494314
// EA  : 0x82B303C8
// RVA : 0x00B303C8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494314()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 580));
}


// ========================================================================
// __unwind$494315
// EA  : 0x82B303F4
// RVA : 0x00B303F4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494315()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 112 + 132) + 676));
}


// ========================================================================
// __unwind$494316
// EA  : 0x82B30420
// RVA : 0x00B30420
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494316()
{
  int v0; // r12

  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: (idAnimator_EndAdditiveChannels *)(*(_DWORD *)(v0 - 112 + 132) + 964));
}


// ========================================================================
// __unwind$494317
// EA  : 0x82B3044C
// RVA : 0x00B3044C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494317()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1132));
}


// ========================================================================
// __unwind$494318
// EA  : 0x82B30478
// RVA : 0x00B30478
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494318()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1228));
}


// ========================================================================
// __unwind$494319
// EA  : 0x82B304A4
// RVA : 0x00B304A4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494319()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1324));
}


// ========================================================================
// __unwind$494320
// EA  : 0x82B304D0
// RVA : 0x00B304D0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494320()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1420));
}


// ========================================================================
// __unwind$494321
// EA  : 0x82B304FC
// RVA : 0x00B304FC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494321()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 1516));
}


// ========================================================================
// ??0idFaceMgr@@QAA@XZ
// EA  : 0x82B30590
// RVA : 0x00B30590
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

idFaceMgr *__fastcall idFaceMgr::idFaceMgr(idFaceMgr *this)
{
  int v2; // ctr
  _WORD *v3; // r9
  float *p_roll; // r8
  float *p_z; // r11

  this->mood = MOOD_NONE;
  this->lastMood = MOOD_NONE;
  this->__vftable = (idFaceMgr_vtbl *)&idFaceMgr::`vftable';
  this->voiceChannel = NUM_SND_CHANNELS;
  this->defaultMood = MOOD_CLEAR;
  this->clearChannel = FACECHANNEL_MAX;
  this->flags = 0;
  this->moodTable[0].value = -1;
  this->moodTable[1].value = -1;
  this->moodTable[2].value = -1;
  this->moodTable[3].value = -1;
  this->moodTable[4].value = -1;
  this->moodTable[5].value = -1;
  this->moodTable[6].value = -1;
  this->moodTable[7].value = -1;
  this->moodTable[8].value = -1;
  this->visemeTable.list = nullptr;
  this->visemeTable.granularity = 0;
  this->visemeTable.memTag = 5;
  this->visemeTable.listStatic = 0;
  this->visemeTable.size = 0;
  this->visemeTable.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemeTable);
  this->blinkAlias.value = -1;
  this->lidDeformationAliases[0].value = -1;
  this->lidDeformationAliases[1].value = -1;
  this->lidDeformationAliases[2].value = -1;
  this->lidDeformationAliases[3].value = -1;
  this->lidDeformationAliases[4].value = -1;
  this->eyeLidUserChannels[0].value = -1;
  this->eyeLidUserChannels[1].value = -1;
  this->voiceOver = nullptr;
  this->voiceTrackIndex = -1;
  this->lastSoundShader = nullptr;
  this->curVisemeSet = nullptr;
  this->vtrackDuration.value = -1;
  this->realStartTime.value = -1;
  this->realEndTime.value = -1;
  this->vtrackStartTime.value = -1;
  this->startSoundTime.value = -1;
  this->lastSampleTime.value = -1;
  this->endLipsyncTime.value = -1;
  idFaceAnimator::idFaceAnimator(this: &this->faceAnimator);
  this->eyeJointIndex[0].value = -1;
  this->eyeJointIndex[1].value = -1;
  this->headJointIndex.value = -1;
  this->nextBlinkTime = -1;
  this->nextJitterTime = -1;
  v2 = 2;
  this->eyeJitterOffset.x = 0.0;
  v3 = (_WORD *)((char *)&this->faceAnimator.idleFidgetAnimator + 94);
  this->eyeJitterOffset.y = 0.0;
  this->eyeJitterOffset.z = 0.0;
  this->initEyeTracking = false;
  this->useFaceSetupEyeTracking = false;
  p_roll = &this->eyeAngles[1].roll;
  this->useFaceSetupBlinking = false;
  p_z = &this->eyeJitterOffset.z;
  this->startedVO = false;
  this->focusAttentionLevel = ATTENTION_MODERATE;
  this->lastGlanceTime = -1;
  this->currentGlanceInterval = -1;
  this->glancingPreviousFrame = false;
  this->lastFidgetTime = -1;
  this->currentFidgetInterval = -1;
  this->fidgetingPreviousFrame = false;
  this->nextCycleSelectTime = -1;
  do
  {
    *++v3 = -1;
    *++p_roll = 0.0;
    p_z[1] = ang_zero.pitch;
    p_z[2] = ang_zero.yaw;
    p_z += 3;
    *p_z = ang_zero.roll;
    --v2;
  }
  while ( v2 != 0 );
  this->eyeFaceChannels[0] = -1;
  this->eyeFaceChannels[1] = -1;
  this->eyeFaceChannels[2] = -1;
  this->eyeFaceChannels[3] = -1;
  return this;
}


// ========================================================================
// __unwind$494449
// EA  : 0x82B307AC
// RVA : 0x00B307AC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494449()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$494450
// EA  : 0x82B307D4
// RVA : 0x00B307D4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494450()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 48));
}


// ========================================================================
// ?LoadVisemeSetAnims@idFaceMgr@@AAAXPAVidTreeAnimator@@PBVidDeclVisemeSet@@_N@Z
// EA  : 0x82B30860
// RVA : 0x00B30860
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::LoadVisemeSetAnims(
        idFaceMgr *this,
        idTreeAnimator *ta,
        const idDeclVisemeSet *vset,
        bool load)
{
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *p_visemeTable; // r29
  int v8; // r24
  BOOL v9; // r22
  int v10; // r31
  int v11; // r28
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *list; // r27
  const idDeclMD6 *decl; // r5
  idAnimation_vtbl *v14; // r10
  const char *str; // r6
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v16; // r3
  char v17; // [sp+50h] [-60h] BYREF
  char v18; // [sp+52h] [-5Eh] BYREF

  p_visemeTable = &this->visemeTable;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visemeTable);
  if ( vset != nullptr )
  {
    idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5>::SetNum(
      this: p_visemeTable,
      newNum: vset->visemes.num);
    v8 = 0;
    if ( vset->visemes.num > 0 )
    {
      v9 = load;
      v10 = 0;
      v11 = 0;
      do
      {
        list = p_visemeTable->list;
        decl = ta->decl;
        v14 = animation->__vftable;
        str = vset->visemes.list[v11].aliasName.str;
        if ( v9 )
          v16 = v14->StrongLoadAlias(
                  this: (idAnimation *)&v17,
                  result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
                  a3: decl,
                  a4: str);
        else
          v16 = v14->FindAliasHandle(
                  this: (idAnimation *)&v18,
                  result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
                  a3: decl,
                  a4: str);
        list[v10] = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)v16->value;
        if ( p_visemeTable->list[v10].value == NULL_ALIAS.value )
          p_visemeTable->list[v10].value = p_visemeTable->list[vset->silenceViseme].value;
        ++v8;
        ++v11;
        ++v10;
      }
      while ( v8 < vset->visemes.num );
    }
  }
}


// ========================================================================
// ?UpdateLipSync@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B30958
// RVA : 0x00B30958
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceMgr::UpdateLipSync(idFaceMgr *this, idAI2 *owner, idTreeAnimator *ta)
{
  idFaceMgr *v3; // r18
  idTreeAnimator *v5; // r14
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const idDeclVoiceOver *voiceOver; // r11
  int voiceTrackIndex; // r10
  const idVoiceTrack *v10; // r19
  int v11; // r15
  int value; // r11
  const idSoundShader *lastSoundShader; // r11
  const char *str; // r30
  char *data; // r27
  int GameMs; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int num; // r11
  int v21; // r22
  int v22; // r25
  const idVoiceEvent *v23; // r30
  int eventType; // r11
  idAI2 *v25; // r29
  idVoiceAnimEvent *v26; // r3
  char v27; // r29
  faceChannel_t startMS_high; // r15
  int startMS_low; // r11
  idMD6LeafPlay **durationMS; // r16
  int v31; // r30
  double Rate; // fp1
  int v33; // r9
  const idMD6Alias *Alias; // r3
  int v35; // r9
  int v36; // r23
  int v37; // r26
  const idVoiceEvent **list; // r4
  int v39; // r24
  idVoiceEvent *v40; // r30
  int GameMsPerFrame; // r3
  long double v42; // fp2
  int v43; // r27
  float *v44; // r11
  int v45; // r11
  int v46; // r4
  int v47; // r11
  int v48; // r10
  int v49; // r10
  int v50; // r10
  int v51; // r10
  int v52; // r6
  int v53; // r11
  int v54; // ctr
  int v55; // r5
  int v56; // r10
  int v57; // r10
  double v58; // fp0
  _WORD *v59; // r9
  int v60; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v61; // r8
  int v62; // r7
  int v63; // r3
  int v64; // r7
  int v65; // r7
  int v66; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v67; // r9
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v68; // r7
  int v69; // r3
  double v70; // fp0
  int v71; // r24
  int v72; // r25
  float *v73; // r11
  int v74; // r9
  _WORD *v75; // r10
  int v76; // r11
  __int16 v77; // r22
  __int16 v78; // r21
  int v79; // r20
  int v80; // r18
  __int16 v81; // r17
  double v82; // fp13
  int v83; // r16
  double v84; // fp12
  int v85; // r15
  __int16 v86; // r14
  double v87; // fp10
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v88; // r10
  int v89; // r11
  int v90; // ctr
  int v91; // r3
  double v92; // fp13
  const idDeclVisemeSet *curVisemeSet; // r11
  int v94; // r10
  unsigned __int16 v95; // r9
  int v96; // r30
  int i; // r29
  char v98; // r11
  int v99; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v101; // r30
  int v102; // r3
  __int64 totalTicks; // r11
  __int64 v104; // r9
  int v105; // [sp+8h] [-2E8h]
  bool v106; // [sp+Fh] [-2E1h]
  int v107; // [sp+10h] [-2E0h]
  int v108; // [sp+14h] [-2DCh]
  int v109; // [sp+18h] [-2D8h]
  int v110; // [sp+1Ch] [-2D4h]
  int v111; // [sp+20h] [-2D0h]
  int v112; // [sp+24h] [-2CCh]
  int v113; // [sp+28h] [-2C8h]
  int v114; // [sp+2Ch] [-2C4h]
  int v115; // [sp+30h] [-2C0h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v116; // [sp+34h] [-2BCh]
  int v117; // [sp+38h] [-2B8h]
  int v118; // [sp+3Ch] [-2B4h]
  int v119; // [sp+40h] [-2B0h]
  int v120; // [sp+44h] [-2ACh]
  int v121; // [sp+48h] [-2A8h]
  int v122; // [sp+4Ch] [-2A4h]
  int v123; // [sp+50h] [-2A0h]
  int v124; // [sp+58h] [-298h]
  int v125; // [sp+60h] [-290h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v126[3]; // [sp+72h] [-27Eh] BYREF
  idPLogScope v127; // [sp+78h] [-278h] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v128[4]; // [sp+80h] [-270h] BYREF
  float v129[5]; // [sp+90h] [-260h] BYREF
  int v130; // [sp+A4h] [-24Ch] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v131[38]; // [sp+A8h] [-248h] BYREF
  _WORD v132[11]; // [sp+AAh] [-246h] BYREF
  int v133; // [sp+C0h] [-230h] BYREF
  int v134; // [sp+C4h] [-22Ch] BYREF
  int v135; // [sp+C8h] [-228h] BYREF
  _DWORD v136[10]; // [sp+CCh] [-224h] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v137; // [sp+F4h] [-1FCh] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v138; // [sp+F8h] [-1F8h] BYREF
  idStaticList<idVoiceEvent const *,32> v139; // [sp+100h] [-1F0h] BYREF
  idStaticList<idVoiceEvent const *,32> v140; // [sp+190h] [-160h] BYREF
  idStr v141; // [sp+220h] [-D0h] BYREF

  v3 = this;
  v5 = ta;
  RD_EventBegin(name: "idFaceManager::UpdateLipSync");
  LODWORD(v6) = "idFaceManager::UpdateLipSync";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v127, pl: &::pLog, gMask: v6, label: v7);
  voiceOver = v3->voiceOver;
  if ( voiceOver == nullptr )
    goto LABEL_29;
  voiceTrackIndex = v3->voiceTrackIndex;
  if ( voiceTrackIndex < 0 || v3->lastSoundShader == nullptr )
    goto LABEL_29;
  if ( voiceTrackIndex >= voiceOver->tracks.num || (v10 = voiceOver->tracks.list[voiceTrackIndex]) == nullptr )
  {
    v3->voiceTrackIndex = -1;
    idPLogScope::~idPLogScope(this: &v127);
    goto LABEL_135;
  }
  if ( !v3->startedVO
    && (unsigned __int8)idFaceMgr::StartVOIfStreamedSampleIsReady(this: v3, owner, ta: v5, voiceTrack: v10) == 0 )
  {
    goto LABEL_29;
  }
  idFaceMgr::GetVoiceTrackTime(
    this: (idFaceMgr *)&v130,
    result: (idTypesafeNumber<int,enum millisecondUnique_t> *)v3,
    owner,
    voiceTrack: v10);
  v11 = v130;
  if ( v3->lastSampleTime.value >= v130 )
    v3->lastSampleTime.value = v130 - 1;
  if ( v11 >= v3->vtrackDuration.value )
  {
    idFaceMgr::LipSyncFinished(this: v3, owner, ta: v5);
    idPLogScope::~idPLogScope(this: &v127);
    goto LABEL_135;
  }
  value = v3->startSoundTime.value;
  if ( value >= 0 && v11 >= value )
  {
    if ( ai_debugVoice.valueInteger != 0 && ai_debugLevel.valueInteger >= 2 )
    {
      lastSoundShader = v3->lastSoundShader;
      if ( lastSoundShader != nullptr )
        str = lastSoundShader->name.str;
      else
        str = "<NULL>";
      data = owner->name.data;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d) %s - starting sound shader '%s'\n", GameMs, data, str);
    }
    if ( face_debugTime.valueInteger != 0 )
    {
      v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d)idFaceMgr: start sample\n", v17);
    }
    idEntity::StartSoundShader(
      this: owner,
      channel: (const soundChannel_t)v3->voiceChannel,
      shader: v3->lastSoundShader,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    v3->startSoundTime.value = -1;
  }
  if ( face_debugTime.valueInteger > 1 )
  {
    v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "(%d)idFaceMgr: sample time = %d\n", v18, v11);
  }
  if ( (v3->flags & 0x200) == 0 )
  {
LABEL_29:
    idPLogScope::~idPLogScope(this: &v127);
    goto LABEL_135;
  }
  v139.granularity = 1;
  v139.size = 32;
  v139.num = 0;
  v139.memTag = 5;
  v139.list = v139.staticList;
  v139.listStatic = 1;
  v140.num = 0;
  v140.size = 32;
  v140.granularity = 1;
  v140.list = v140.staticList;
  v140.memTag = 5;
  v140.listStatic = 1;
  v19 = v3->lastSampleTime.value;
  v137.value = 0;
  v138.value = v11;
  v128[0].value = v19;
  idVoiceTrack::GetEvents(
    this: v10,
    curTimeMS: &v138,
    lastTimeMS: v128,
    loopLengthMS: &v137,
    type: VOICEEVENT_MAX,
    visemeEvents: &v139,
    nonVisemeEvents: &v140);
  num = v140.num;
  v3->lastSampleTime.value = v11;
  v21 = 0;
  if ( num > 0 )
  {
    v22 = 0;
    do
    {
      v23 = v140.list[v22];
      eventType = v23->eventType;
      switch ( eventType )
      {
        case 3:
          idStr::Icmp(s1: (const char *)v23[1].startMS, s2: face_debugTextEvent.valueString.data);
          break;
        case 5:
          if ( face_skipGestures.valueInteger == 0 )
          {
            if ( HIWORD(v23[1].startMS) == 9 )
            {
              v25 = idAI2::CastTo(c: owner);
              if ( v25 != nullptr )
              {
                idStr::idStr(this: &v141, text: (const char *)v23[1].__vftable);
                idFaceAnimator::PlayWebAnimation(
                  this: &v3->faceAnimator,
                  fm: v3,
                  owner,
                  ta: v5,
                  webAnimator: (idAnimator_AnimWeb *)&v25->aiVolatile.animation,
                  webPath: (idAnimWebPath *)&v141);
                idStr::FreeData(this: &v141);
              }
            }
            else
            {
              idDeclMD6::FindAliasHandle(
                this: (idDeclMD6 *)v126,
                result: v5->decl,
                aliasName: (const char *)v23[1].__vftable);
              if ( v126[0].value != 0xFFFF )
              {
                v26 = (idVoiceAnimEvent *)v23;
                v27 = BYTE2(v23[2].__vftable);
                startMS_high = SHIWORD(v23[1].startMS);
                startMS_low = LOWORD(v23[1].startMS);
                durationMS = (idMD6LeafPlay **)(unsigned __int16)v23[1].durationMS;
                v31 = *(unsigned __int16 *)&v23[1].eventType;
                v128[0].value = startMS_low;
                Rate = idVoiceAnimEvent::GetRate(this: v26);
                v5 = ta;
                idFaceAnimator::PlayAnimation(
                  this: &v3->faceAnimator,
                  fm: v3,
                  owner,
                  ta,
                  aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v126[0].value,
                  channel: startMS_high,
                  rateScale: Rate,
                  startFrame: v33,
                  blendInDurationMS: v31,
                  blendOutDurationMS: v105,
                  cycleAnim: v106,
                  a12: v107,
                  a13: v108,
                  a14: v109,
                  a15: v110,
                  a16: v111,
                  a17: v112,
                  a18: v113,
                  a19: v114,
                  a20: v115,
                  a21: v116,
                  a22: v117,
                  a23: v118,
                  a24: v119,
                  a25: v120,
                  a26: v121,
                  a27: v122,
                  a28: v123,
                  a29: v128[0].value,
                  a30: v124,
                  a31: durationMS,
                  a32: v125,
                  a33: v27);
                if ( face_debug.valueInteger > 1 )
                {
                  Alias = idDeclMD6::FindAlias(this: ta->decl, aliasHandle: v126, includeInherited: true);
                  idLib::Printf(fmt: "Gesture: %s( %s )\n", Alias->name.str, Alias->animRefs.list->str);
                }
                v11 = v130;
              }
            }
          }
          break;
        case 6:
          v3->mood = (mood_t)v23[1].__vftable;
          break;
        default:
          break;
      }
      ++v21;
      ++v22;
    }
    while ( v21 < v140.num );
  }
  v35 = *(_BYTE *)&v10->flags & 0x20;
  v128[0].value = (int)&v10->flags;
  if ( v35 != 32 && (v3->flags & 2) != 0 && v139.num != 0 )
  {
    v36 = 0;
    v37 = 0;
    memset(v129, 0, sizeof(v129));
    v133 = -1;
    v134 = -1;
    v135 = -1;
    v136[0] = -1;
    v136[1] = -1;
    if ( v139.num <= 0 )
    {
      list = v139.list;
    }
    else
    {
      list = v139.list;
      v39 = 0;
      do
      {
        v40 = (idVoiceEvent *)list[v39];
        if ( v40->eventType == 0 )
        {
          GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                             this: &clientGame->gameTimeManager,
                             type: GAMETIME_SCALED);
          v40->GetWeight(this: v40, a2: v11, a3: GameMsPerFrame);
          if ( face_mapWeightsToSine.valueInteger != 0 )
          {
            *(float *)&v128[0].value = 3.1415927;
            *(double *)&v42 = (float)((float)((float)3.1415927 * (float)*(double *)&v42)
                                    - (float)(3.1415927 * (float)0.5));
            v42 = sin(x: v42);
            *(double *)&v42 = (float)((float)((float)*(double *)&v42 * (float)0.5) + (float)0.5);
          }
          v43 = 0;
          v44 = v129;
          while ( *(double *)&v42 <= *v44 )
          {
            ++v43;
            ++v44;
            if ( v43 >= 5 )
              goto LABEL_80;
          }
          v45 = v36;
          if ( v36 >= 5 )
            v45 = 4;
          v46 = v45;
          if ( v45 > v43 )
          {
            if ( v45 - v43 >= 4 )
            {
              v47 = 4 * v45 - 4;
              do
              {
                if ( v46 - 1 >= 0 )
                {
                  v48 = *(int *)((char *)&v133 + v47);
                  *(float *)((char *)&v129[1] + v47) = *(float *)((char *)v129 + v47);
                  *(int *)((char *)&v134 + v47) = v48;
                }
                if ( v46 >= 2 )
                {
                  v49 = *(_DWORD *)((char *)&v132[9] + v47);
                  *(float *)((char *)v129 + v47) = *(float *)((char *)&v128[3].value + v47);
                  *(int *)((char *)&v133 + v47) = v49;
                }
                if ( v46 - 3 >= 0 )
                {
                  v50 = *(_DWORD *)((char *)&v132[7] + v47);
                  *(idTypesafeNumber<int,enum millisecondUnique_t> *)((char *)&v128[3] + v47) = *(idTypesafeNumber<int,enum millisecondUnique_t> *)((char *)&v128[2] + v47);
                  *(_DWORD *)((char *)&v132[9] + v47) = v50;
                }
                v51 = v46 - 4;
                if ( v46 - 4 >= 0 )
                {
                  v52 = *(_DWORD *)((char *)&v132[5] + v47);
                  *(idTypesafeNumber<int,enum millisecondUnique_t> *)((char *)&v128[2] + v47) = *(idTypesafeNumber<int,enum millisecondUnique_t> *)((char *)&v128[1] + v47);
                  *(_DWORD *)((char *)&v132[7] + v47) = v52;
                }
                v46 -= 4;
                v47 -= 16;
              }
              while ( v51 > v43 + 3 );
            }
            if ( v46 > v43 )
            {
              v53 = 4 * v46 - 4;
              v54 = v46 - v43;
              do
              {
                if ( v46 - 1 >= 0 )
                {
                  v55 = *(int *)((char *)&v133 + v53);
                  *(float *)((char *)&v129[1] + v53) = *(float *)((char *)v129 + v53);
                  *(int *)((char *)&v134 + v53) = v55;
                }
                --v46;
                v53 -= 4;
                --v54;
              }
              while ( v54 != 0 );
            }
          }
          v56 = v43;
          v129[v56] = *(double *)&v42;
          *(int *)((char *)&v133 + v56 * 4) = v37;
          v36 += ((v36 >= 0) + ((unsigned int)v36 >= 5)) & 1;
LABEL_80:
          list = v139.list;
        }
        ++v37;
        ++v39;
      }
      while ( v37 < v139.num );
    }
    v57 = 0;
    v58 = 0.0;
    v131[0].value = -1;
    v132[0] = -1;
    v132[1] = -1;
    v132[2] = -1;
    v132[3] = -1;
    if ( v36 < 4 )
    {
LABEL_91:
      if ( v57 < v36 )
      {
        v66 = v57;
        v67 = &v131[v57 - 1];
        do
        {
          if ( v66 >= 5 )
            break;
          v68 = v3->visemeTable.list;
          ++v57;
          v58 = (float)(v129[v66] + (float)v58);
          v69 = HIBYTE(list[*(int *)((char *)&v133 + v66 * 4)][1].__vftable);
          v136[v66 + 5] = v69;
          ++v66;
          ++v67;
          v67->value = *(unsigned __int16 *)((char *)v68 + __ROL4__(v69, 1));
        }
        while ( v57 < v36 );
      }
    }
    else
    {
      v59 = (_WORD *)&v130 + 1;
      v60 = 0;
      while ( v57 < 5 )
      {
        v61 = v3->visemeTable.list;
        v58 = (float)(v129[v60] + (float)v58);
        v62 = HIBYTE(list[*(int *)((char *)&v133 + v60 * 4)][1].__vftable);
        v136[v60 + 5] = v62;
        v59[1] = *(unsigned __int16 *)((char *)&v61->value + __ROL4__(v62, 1));
        if ( v57 + 1 >= 5 )
          break;
        v58 = (float)(v129[v60 + 1] + (float)v58);
        v63 = HIBYTE(list[*(int *)((char *)&v134 + v60 * 4)][1].__vftable);
        v136[v60 + 6] = v63;
        v59[2] = *(unsigned __int16 *)((char *)&v61->value + __ROL4__(v63, 1));
        if ( v57 >= 3 )
          break;
        v58 = (float)(v129[v60 + 2] + (float)v58);
        v64 = HIBYTE(list[v136[v60 - 1]][1].__vftable);
        v136[v60 + 7] = v64;
        v59[3] = *(unsigned __int16 *)((char *)&v61->value + __ROL4__(v64, 1));
        if ( v57 + 3 >= 5 )
          break;
        v57 += 4;
        v58 = (float)(v129[v60 + 3] + (float)v58);
        v65 = HIBYTE(list[v136[v60]][1].__vftable);
        v136[v60 + 8] = v65;
        v60 += 4;
        v59 += 4;
        *v59 = *(unsigned __int16 *)((char *)&v61->value + __ROL4__(v65, 1));
        if ( v57 >= v36 - 3 )
          goto LABEL_91;
      }
    }
    if ( v36 < 5 && v58 < 1.0 )
    {
      v70 = (float)((float)1.0 - (float)v58);
      v71 = v36;
      v72 = 0;
      if ( v36 > 0 )
      {
        v73 = v129;
        while ( v70 <= *v73 )
        {
          ++v72;
          ++v73;
          if ( v72 >= v36 )
            goto LABEL_111;
        }
        v71 = v72;
        if ( v36 != v72 )
        {
          v74 = v36;
          if ( v36 > v72 )
          {
            if ( v36 - v72 >= 4 )
            {
              v75 = &v132[v36];
              v76 = 4 * v36 - 4;
              do
              {
                v77 = *(v75 - 2);
                v78 = *(v75 - 3);
                v79 = *(_DWORD *)((char *)&v136[3] + v76);
                v80 = *(_DWORD *)((char *)&v136[4] + v76);
                v74 -= 4;
                v81 = *(v75 - 4);
                v82 = *(float *)((char *)&v128[3].value + v76);
                v83 = *(_DWORD *)((char *)&v136[5] + v76);
                v84 = *(float *)((char *)&v128[2].value + v76);
                v85 = *(_DWORD *)((char *)&v136[2] + v76);
                v86 = *(v75 - 5);
                v87 = *(float *)((char *)&v128[1].value + v76);
                *(float *)((char *)&v129[1] + v76) = *(float *)((char *)v129 + v76);
                *(v75 - 1) = v77;
                *(float *)((char *)&v128[3].value + v76) = v84;
                *(v75 - 2) = v78;
                *(float *)((char *)&v128[2].value + v76) = v87;
                *(v75 - 3) = v81;
                *(float *)((char *)v129 + v76) = v82;
                *(_DWORD *)((char *)&v136[4] + v76) = v79;
                *(_DWORD *)((char *)&v136[6] + v76) = v83;
                *(_DWORD *)((char *)&v136[3] + v76) = v85;
                *(_DWORD *)((char *)&v136[5] + v76) = v80;
                v76 -= 16;
                v75 -= 4;
                *v75 = v86;
              }
              while ( v74 > v72 + 3 );
              v11 = v130;
              v5 = ta;
              v3 = this;
            }
            if ( v74 > v72 )
            {
              v88 = &v131[v74];
              v89 = 4 * v74 - 4;
              v90 = v74 - v72;
              do
              {
                v91 = *(_DWORD *)((char *)&v136[5] + v89);
                v92 = *(float *)((char *)v129 + v89);
                v88->value = v88[-1].value;
                *(float *)((char *)&v129[1] + v89) = v92;
                --v88;
                *(_DWORD *)((char *)&v136[6] + v89) = v91;
                v89 -= 4;
                --v90;
              }
              while ( v90 != 0 );
            }
          }
        }
      }
LABEL_111:
      curVisemeSet = v3->curVisemeSet;
      v94 = v71;
      ++v36;
      v95 = v3->visemeTable.list[curVisemeSet->silenceViseme].value;
      v129[v94] = v70;
      v131[v71].value = v95;
      v136[v94 + 5] = curVisemeSet->silenceViseme;
    }
    if ( face_debugWeights.valueInteger >= 1 )
    {
      idLib::Printf(fmt: "(%d) raw weights: ", v11);
      if ( v36 > 0 )
      {
        v96 = 0;
        for ( i = v36; i != 0; --i )
        {
          idLib::Printf(fmt: "%s %g ", v3->curVisemeSet->visemes.list[v136[v96 + 5]].name.str, v129[v96]);
          ++v96;
        }
      }
      idLib::Printf(fmt: "\n");
      list = v139.list;
    }
    if ( (v3->flags & 2) == 0 || face_skipLipsync.valueInteger != 0 || (v98 = 1, face_skipProcedural.valueInteger != 0) )
      v98 = 0;
    if ( v98 != 0 )
    {
      v99 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_EndAdditiveChannels::SetAnimHandlesAndWeights(
        this: &v3->faceAnimator.lipAnimator,
        animator: v5,
        curTime: v99,
        handles: v131,
        numAnims: v36,
        weights: v129,
        numWeights: v36);
      list = v139.list;
    }
    if ( v140.listStatic == 0 || v140.listStatic == 2 )
    {
      if ( v140.list != nullptr )
      {
        idMem::Free(this: &mem, ptr: v140.list, align: ALIGN_16);
        list = v139.list;
      }
      v140.list = nullptr;
      v140.size = 0;
    }
    v140.num = 0;
    if ( v139.listStatic == 0 || v139.listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v139.list = nullptr;
      v139.size = 0;
    }
    v139.num = 0;
    if ( v127.logIndex >= 0 )
    {
      pLog = v127.pLog;
      v101 = &v127.pLog->logEntries.list[v127.logIndex];
      v102 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v101->totalTicks;
      HIDWORD(totalTicks) = v101->parent;
      LODWORD(v104) = v102 - totalTicks;
      v101->totalTicks = v104;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v140);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v139);
    idPLogScope::~idPLogScope(this: &v127);
  }
LABEL_135:
  RD_EventEnd();
}


// ========================================================================
// __unwind$494794
// EA  : 0x82B316BC
// RVA : 0x00B316BC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494794()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 752 + 576));
}


// ========================================================================
// __unwind$494795
// EA  : 0x82B316E4
// RVA : 0x00B316E4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494795()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 752 + 120));
}


// ========================================================================
// __unwind$494796
// EA  : 0x82B3170C
// RVA : 0x00B3170C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494796()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 256));
}


// ========================================================================
// __unwind$494797
// EA  : 0x82B31734
// RVA : 0x00B31734
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494797()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 400));
}


// ========================================================================
// __unwind$494798
// EA  : 0x82B3175C
// RVA : 0x00B3175C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_494798()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 544));
}


// ========================================================================
// ?StartVoiceTrack@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidDeclVoiceOver@@H@Z
// EA  : 0x82B31790
// RVA : 0x00B31790
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceMgr::StartVoiceTrack(
        idFaceMgr *this,
        idAI2 *owner,
        idTreeAnimator *ta,
        const idDeclVoiceOver *vo,
        int trackIndex)
{
  int v9; // r30
  const idVoiceTrack *v10; // r26
  idVoiceTrack_vtbl *value; // r11
  int GameMs; // r3
  int v13; // r28
  idVoiceTrack::idSubtitleText *list; // r11
  const idDeclVisemeSet *declVisemeSet; // r30
  int v16; // [sp+50h] [-70h] BYREF
  idList<idVoiceTrack::idSubtitleText,5> v17[6]; // [sp+60h] [-60h] BYREF

  if ( vo == nullptr || vo->tracks.num == 0 )
    return 0;
  this->voiceOver = vo;
  v9 = 0;
  this->voiceTrackIndex = trackIndex;
  this->vtrackDuration.value = -1;
  this->realStartTime.value = -1;
  this->vtrackStartTime.value = -1;
  this->startSoundTime.value = -1;
  this->lastSampleTime.value = -1;
  this->startedVO = false;
  if ( trackIndex >= 0 && trackIndex < vo->tracks.num && (v10 = vo->tracks.list[trackIndex]) != nullptr )
  {
    if ( (*(_BYTE *)&v10->flags & 1) != 0 )
      value = idVoiceTrack::FindExactDuration(
                this: (idVoiceTrack *)&v16,
                result: (idTypesafeNumber<int,enum millisecondUnique_t> *)v10,
                declMD6: ta->decl)->__vftable;
    else
      value = (idVoiceTrack_vtbl *)v10->approximateDuration.value;
    this->vtrackDuration.value = (int)value;
    if ( face_debugTime.valueInteger != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "(%d)idFaceMgr: StartVoiceTrack\n", GameMs);
    }
    if ( face_debug.valueInteger > 0 )
    {
      v17[0].listStatic = 0;
      v17[0].memTag = 5;
      memset(v17, 0, 14);
      idVoiceTrack::GetSubtitles(this: v10, subtitles: v17, mergePunctuation: true);
      idLib::Printf(fmt: "Subtitle Text:\n");
      v13 = 0;
      if ( v17[0].num > 0 )
      {
        list = v17[0].list;
        do
        {
          idLib::Printf(fmt: "%s ", list->word.data);
          ++v13;
          list = &v17[0].list[++v9];
        }
        while ( v13 < v17[0].num );
      }
      idList<idPlayer::jobMessage_t,5>::Clear(this: v17);
    }
    declVisemeSet = v10->declVisemeSet;
    if ( this->curVisemeSet != declVisemeSet )
    {
      idFaceMgr::LoadVisemeSetAnims(this, ta, vset: v10->declVisemeSet, load: false);
      this->curVisemeSet = declVisemeSet;
    }
    return idFaceMgr::StartVOIfStreamedSampleIsReady(this, owner, ta, voiceTrack: v10);
  }
  else
  {
    this->voiceTrackIndex = -1;
    return 0;
  }
}


// ========================================================================
// __unwind$495547
// EA  : 0x82B31970
// RVA : 0x00B31970
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495547()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 192 + 96));
}


// ========================================================================
// ?Init@idFaceAnimator@@QAA_NPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B319A0
// RVA : 0x00B319A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceAnimator::Init(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idAnimStack *v8; // r3
  idAnimStack *v9; // r28
  idAnimator_Channel *p_bodyAnimator; // r23
  idGameTimeManager *v12; // r3
  idAnimator_Channel *p_legsAnimator; // r22
  idGameTimeManager *v14; // r3
  idAnimator_Channel *p_torsoAnimator; // r21
  idGameTimeManager *v16; // r3
  idAnimator_Channel *p_headAnimator; // r20
  idGameTimeManager *v18; // r3
  idAnimator_Channel *p_faceAnimator; // r19
  idGameTimeManager *v20; // r3
  idAnimator_Synced *p_lidDeformAnimator; // r24
  idGameTimeManager *v22; // r3
  idAnimator_Channel *p_eyeAnimator; // r18
  idGameTimeManager *v24; // r3
  idAnimator_EndAdditiveChannels *p_lipAnimator; // r27
  idGameTimeManager *v26; // r3
  idAnimator_Channel *p_glanceAnimator; // r26
  idGameTimeManager *v28; // r3
  idAnimator_Channel *p_idleCycleAnimator; // r25
  idGameTimeManager *v30; // r3
  idAnimator_Channel *p_idleFidgetAnimator; // r17
  idGameTimeManager *v32; // r3
  idAnimator_Channel *p_moodAnimator; // r16
  idGameTimeManager *v34; // r3
  idAnimator_Channel *p_faceEmoteAnimator; // r15
  idGameTimeManager *v36; // r3
  idGameTimeManager *v37; // r3
  idAnimator_Channel *p_mouthEmoteAnimator; // r29
  idGameTimeManager *v39; // r3
  int GameMs; // r3
  idAnimator_Channel *p_browEmoteAnimator; // [sp+50h] [-130h]
  idPLogScope v42; // [sp+58h] [-128h] BYREF
  idAnimatorParms_Base v43; // [sp+60h] [-120h] BYREF
  idAnimatorParms_Base v44; // [sp+A0h] [-E0h] BYREF
  int v45; // [sp+D8h] [-A8h]

  RD_EventBegin(name: "idFaceAnimator::Init");
  LODWORD(v6) = "idFaceAnimator::Init";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v42, pl: &pLog, gMask: v6, label: v7);
  v8 = owner->GetAnimStack_2(this: owner);
  v9 = v8;
  if ( v8 != nullptr )
  {
    v43.animStack = v8;
    idStr::idStr(this: &v43.name, text: "fm_body");
    memset(&v43.originBlend, 0, 12);
    v43.blendOp = BOP_LERP;
    v43.alpha = 0.0;
    p_bodyAnimator = &this->bodyAnimator;
    v12 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->bodyAnimator, gametimeManager: v12, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_legs");
    v43.weightGroup = MD6_WEIGHTGROUP_LEGS;
    v43.filterGroup = MD6_WEIGHTGROUP_LEGS;
    p_legsAnimator = &this->legsAnimator;
    v14 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->legsAnimator, gametimeManager: v14, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_torso");
    p_torsoAnimator = &this->torsoAnimator;
    v43.weightGroup = MD6_WEIGHTGROUP_TORSO;
    v43.filterGroup = MD6_WEIGHTGROUP_TORSO;
    v16 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->torsoAnimator, gametimeManager: v16, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_head");
    p_headAnimator = &this->headAnimator;
    v43.weightGroup = MD6_WEIGHTGROUP_HEAD;
    v43.filterGroup = MD6_WEIGHTGROUP_HEAD;
    v18 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->headAnimator, gametimeManager: v18, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_face");
    p_faceAnimator = &this->faceAnimator;
    v43.weightGroup = MD6_WEIGHTGROUP_FACE;
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    v20 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->faceAnimator, gametimeManager: v20, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_lids");
    p_lidDeformAnimator = &this->lidDeformAnimator;
    v43.weightGroup = MD6_WEIGHTGROUP_EYELIDS;
    v43.filterGroup = MD6_WEIGHTGROUP_EYELIDS;
    v22 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->lidDeformAnimator, gametimeManager: v22, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_blink");
    v43.weightGroup = MD6_WEIGHTGROUP_EYELIDS;
    v43.filterGroup = MD6_WEIGHTGROUP_EYELIDS;
    p_eyeAnimator = &this->eyeAnimator;
    v24 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->eyeAnimator, gametimeManager: v24, parms: &v43);
    v44.animStack = v9;
    idStr::idStr(this: &v44.name, text: "fm_lipsync");
    v44.blendOp = BOP_ADD_RIGHT;
    v44.originBlend = ORIGINBLEND_BRANCH;
    v44.weightGroup = MD6_WEIGHTGROUP_FACE;
    v44.filterGroup = MD6_WEIGHTGROUP_FACE;
    v45 = 5;
    v44.alpha = 1.0;
    p_lipAnimator = &this->lipAnimator;
    v26 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->lipAnimator, gametimeManager: v26, parms: &v44);
    idStr::operator=(this: &v43.name, text: "fm_glance");
    v43.weightGroup = MD6_WEIGHTGROUP_TORSO;
    v43.filterGroup = MD6_WEIGHTGROUP_TORSO;
    p_glanceAnimator = &this->glanceAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v28 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->glanceAnimator, gametimeManager: v28, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_cycle");
    v43.weightGroup = MD6_WEIGHTGROUP_FACE;
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    p_idleCycleAnimator = &this->idleCycleAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v30 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->idleCycleAnimator, gametimeManager: v30, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_fidget");
    v43.weightGroup = MD6_WEIGHTGROUP_FACE;
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    p_idleFidgetAnimator = &this->idleFidgetAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v32 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->idleFidgetAnimator, gametimeManager: v32, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_mood");
    v43.weightGroup = MD6_WEIGHTGROUP_FACE;
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    p_moodAnimator = &this->moodAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v34 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->moodAnimator, gametimeManager: v34, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_faceEmote");
    v43.weightGroup = MD6_WEIGHTGROUP_FACE;
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    p_faceEmoteAnimator = &this->faceEmoteAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v36 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->faceEmoteAnimator, gametimeManager: v36, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_browEmote");
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    v43.blendOp = BOP_ADD_RIGHT;
    v43.weightGroup = MD6_WEIGHTGROUP_MAX;
    p_browEmoteAnimator = &this->browEmoteAnimator;
    v37 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->browEmoteAnimator, gametimeManager: v37, parms: &v43);
    idStr::operator=(this: &v43.name, text: "fm_mouthEmote");
    v43.filterGroup = MD6_WEIGHTGROUP_FACE;
    p_mouthEmoteAnimator = &this->mouthEmoteAnimator;
    v43.blendOp = BOP_ADD_RIGHT;
    v43.weightGroup = MD6_WEIGHTGROUP_MAX;
    v39 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: p_mouthEmoteAnimator, gametimeManager: v39, parms: &v43);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idAnimator_Base::Start(this: p_lidDeformAnimator, stack: v9, curTime: GameMs, blendDurationMS: 0, reset: true);
    if ( face_serialize.valueInteger == 0 )
    {
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_bodyAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_legsAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_torsoAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_headAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_faceAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_moodAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_eyeAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_lidDeformAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_lipAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_mouthEmoteAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_browEmoteAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_faceEmoteAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_glanceAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_idleCycleAnimator, flag: ANIMATORFLAG_SERIALIZE);
      idAnimStack::ClearAnimatorFlag(this: v9, animator: p_idleFidgetAnimator, flag: ANIMATORFLAG_SERIALIZE);
    }
    idStr::FreeData(this: &v44.name);
    idStr::FreeData(this: &v43.name);
    idPLogScope::~idPLogScope(this: &v42);
    RD_EventEnd();
    return 1;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v42);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$495701
// EA  : 0x82B31FAC
// RVA : 0x00B31FAC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495701()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 384 + 220));
}


// ========================================================================
// __unwind$495702
// EA  : 0x82B31FD4
// RVA : 0x00B31FD4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495702()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 384 + 88));
}


// ========================================================================
// __unwind$495703
// EA  : 0x82B31FFC
// RVA : 0x00B31FFC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495703()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$495704
// EA  : 0x82B32024
// RVA : 0x00B32024
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495704()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 384 + 160));
}


// ========================================================================
// ?Update@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA  : 0x82B32058
// RVA : 0x00B32058
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __fastcall idFaceAnimator::Update(idFaceAnimator *this, idFaceMgr *fm, idEntity *owner, idTreeAnimator *ta)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idAnimStack *v9; // r3
  int lastFlags; // r28
  int flags; // r30
  idAnimStack *v12; // r25
  char v13; // r11
  char v14; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  int v16; // r3
  int GameMs; // r3
  char v18; // r11
  char v19; // r11
  int v20; // r3
  double valueFloat; // fp31
  int v22; // r3
  int v23; // r6
  idPLogScope v24[2]; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idFaceAnimator::Update");
  LODWORD(v7) = "idFaceAnimator::Update";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: v24, pl: &pLog, gMask: v7, label: v8);
  v9 = owner->GetAnimStack_2(this: owner);
  lastFlags = fm->lastFlags;
  flags = fm->flags;
  v12 = v9;
  if ( ((lastFlags ^ flags) & 0x100) != 0
    || (face_skipLidDeform.flags & 0x20000) != 0
    || (v13 = 0, (face_skipProcedural.flags & 0x20000) != 0) )
  {
    v13 = 1;
  }
  if ( v13 != 0 )
  {
    if ( (flags & 0x100) != 0
      || face_skipLidDeform.valueInteger != 0
      || (v14 = 1, face_skipProcedural.valueInteger != 0) )
    {
      v14 = 0;
    }
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( v14 != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Base::Start(
        this: &this->lidDeformAnimator,
        stack: v12,
        curTime: GameMs,
        blendDurationMS: 0,
        reset: true);
    }
    else
    {
      v16 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Base::End(this: &this->lidDeformAnimator, stack: v12, curTime: v16, blendDurationMS: 0, reset: true);
    }
  }
  if ( ((lastFlags ^ flags) & 2) != 0
    || (face_skipLipsync.flags & 0x20000) != 0
    || (v18 = 0, (face_skipProcedural.flags & 0x20000) != 0) )
  {
    v18 = 1;
  }
  if ( v18 != 0 && idAnimator_Base::IsEnabled(this: &this->lipAnimator, animStack: v12) )
  {
    if ( (fm->flags & 2) == 0 || face_skipLipsync.valueInteger != 0 || (v19 = 1, face_skipProcedural.valueInteger != 0) )
      v19 = 0;
    if ( v19 != 0 )
    {
      if ( face_skipLipsync.valueInteger == 0 && face_skipProcedural.valueInteger == 0 )
      {
        valueFloat = face_lipsyncWeight.valueFloat;
        v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idAnimator_Base::Blend(
          this: &this->lipAnimator,
          stack: v12,
          curTime: v22,
          targetAlpha: valueFloat,
          blendDurationMS: v23,
          reset: 250,
          a7: 1);
      }
    }
    else
    {
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAnimator_Base::End(this: &this->lipAnimator, stack: v12, curTime: v20, blendDurationMS: 0, reset: true);
    }
  }
  if ( (face_skipLidDeform.flags & 0x20000) != 0 )
    face_skipLidDeform.flags &= ~0x20000u;
  if ( (face_skipLipsync.flags & 0x20000) != 0 )
    face_skipLipsync.flags &= ~0x20000u;
  if ( (face_skipProcedural.flags & 0x20000) != 0 )
    face_skipProcedural.flags &= ~0x20000u;
  idPLogScope::~idPLogScope(this: v24);
  RD_EventEnd();
}


// ========================================================================
// __unwind$495805
// EA  : 0x82B32324
// RVA : 0x00B32324
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495805()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$495806
// EA  : 0x82B3234C
// RVA : 0x00B3234C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495806()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?Init@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@W4mood_t@@W4soundChannel_t@@_N444444@Z
// EA  : 0x82B32380
// RVA : 0x00B32380
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceMgr::Init(
        idFaceMgr *this,
        idEntity *owner,
        idTreeAnimator *ta,
        const mood_t mood,
        soundChannel_t voiceChannel,
        bool enableMoodAnimation,
        const bool enableLipSyncAnimation,
        bool enableGestureAnimation,
        const bool enableEyeTracking,
        const bool useFaceSetupEyeTracking_,
        const bool enableBlinking,
        const bool enableLidDeformation,
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
        char a28,
        int a29,
        bool a30,
        int a31,
        unsigned __int8 a32,
        int a33,
        char a34)
{
  unsigned __int64 v38; // r6
  const char *v39; // r7
  int v40; // r22
  unsigned __int64 v41; // r6
  const char *v42; // r7
  BOOL v43; // r24
  unsigned int v44; // r29
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v45; // r30
  const idDeclMD6 *decl; // r23
  idAnimation_vtbl *v47; // r28
  const char *MoodAnimName; // r3
  unsigned __int64 v49; // r6
  const char *v50; // r7
  __int16 *UserChannelIndex; // r3
  __int16 v52; // r11
  unsigned int value; // r7
  unsigned __int64 v54; // r6
  const char *v55; // r7
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *lidDeformationAliases; // r30
  const char **v57; // r29
  int i; // r28
  int staleCount; // r29
  int v60; // r30
  int v61; // r3
  __int64 v62; // r11
  __int64 v63; // r9
  int v64; // r24
  idPLog::logEntry_t *v65; // r30
  __int64 v66; // r3
  idIndex<short,enum invalidJointIndex_t> *v67; // r27
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v68; // r28
  int v69; // r30
  const char **v70; // r29
  idIndex<short,enum invalidJointIndex_t> *eyeJointIndex; // r29
  const char **v72; // r30
  int j; // r28
  idJointGroupCollection *JointGroupCollection; // r3
  idJointGroup *JointGroupForName; // r3
  const char *v76; // r25
  char *ModelDefName; // r3
  const idDeclMD6 *v78; // r11
  idJointGroupCollection *p_jointGroupCollection; // r27
  idIndex<short,enum invalidJointIndex_t> *v80; // r30
  const char **v81; // r29
  int k; // r28
  idJointGroup *v83; // r3
  idPLog::logEntry_t *v84; // r30
  int v85; // r3
  int parent; // r11
  __int64 v87; // r9
  int v88; // r28
  idPLog::logEntry_t *v89; // r30
  __int64 v90; // r3
  int v91; // r30
  int m; // r27
  const idDeclVisemeSet *v93; // r5
  idPLog::logEntry_t *v94; // r30
  int v95; // r3
  int v96; // r11
  __int64 v97; // r9
  int v98; // r27
  idPLog::logEntry_t *v99; // r30
  __int64 v100; // r3
  int trackedMemory; // r30
  unsigned __int16 v102; // r10
  idAnimStack *v103; // r3
  idAnimator_Channel *p_moodAnimator; // r4
  unsigned __int16 v105; // r10
  idAnimStack *v106; // r3
  idAnimator_EndAdditiveChannels *p_lipAnimator; // r4
  unsigned __int16 v108; // r10
  unsigned __int16 flags; // r11
  unsigned __int16 v110; // r10
  const char *str; // r30
  unsigned __int16 v112; // r10
  idAnimStack *v113; // r3
  idAnimator_Channel *p_eyeAnimator; // r4
  unsigned __int16 v115; // r10
  idAnimStack *v116; // r3
  idAnimator_Synced *p_lidDeformAnimator; // r4
  unsigned __int16 v118; // r10
  idAnimStack *v119; // r3
  idAnimator_Channel *p_glanceAnimator; // r4
  unsigned __int16 v121; // r10
  idAnimStack *v122; // r3
  idAnimator_Channel *p_idleFidgetAnimator; // r4
  idPLog::logEntry_t *v124; // r30
  int v125; // r3
  int v126; // r11
  __int64 v127; // r9
  const char *v128; // r29
  int v129; // r30
  int v130; // r3
  __int64 v131; // r11
  __int64 v132; // r9
  const char *resourceError; // r29
  int v135; // r30
  int v136; // r3
  __int64 v137; // r11
  __int64 v138; // r9
  idMD6Skel v139[3]; // [sp+50h] [-C0h] BYREF

  RD_EventBegin(name: "idFaceMgr::Init");
  LODWORD(v38) = "idFaceMgr::Init";
  HIDWORD(v38) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v139[0].resourceListPtr, pl: &pLog, gMask: v38, label: v39);
  if ( ta == nullptr
    || (v139[0].name.str = (const char *)ta->decl, v139[0].name.str == nullptr)
    || *((_DWORD *)v139[0].name.str + 15) == 0 )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v139[0].resourceListPtr);
LABEL_130:
    RD_EventEnd();
    return 0;
  }
  v40 = *((_DWORD *)v139[0].name.str + 15);
  this->flags = 531;
  RD_EventBegin(name: "idFaceMgr::Init - moods");
  LODWORD(v41) = "idFaceMgr::Init - moods";
  HIDWORD(v41) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v139[0].networkID, pl: &pLog, gMask: v41, label: v42);
  v43 = enableMoodAnimation;
  v44 = 2;
  v139[0].trackedMemory = enableMoodAnimation;
  v45 = &this->moodTable[2];
  this->moodTable[0] = NULL_ALIAS;
  this->moodTable[1] = NULL_ALIAS;
  do
  {
    if ( v43 )
    {
      decl = ta->decl;
      v47 = animation->__vftable;
      MoodAnimName = idVoiceTrack::GetMoodAnimName(mood: v44);
      v45->value = v47->StrongLoadAlias(
                     this: (idAnimation *)v139,
                     result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
                     a3: decl,
                     a4: MoodAnimName)->value;
    }
    else
    {
      v45->value = NULL_ALIAS.value;
    }
    ++v44;
    ++v45;
  }
  while ( v44 < 9 );
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v139[0].networkID);
  RD_EventEnd();
  RD_EventBegin(name: "idFaceMgr::Init - blink");
  LODWORD(v49) = "idFaceMgr::Init - blink";
  HIDWORD(v49) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v139[0].networkID, pl: &pLog, gMask: v49, label: v50);
  v139[0].name.str = (const char *)a32;
  if ( a32 != 0 )
  {
    this->useFaceSetupBlinking = a30;
    if ( a30 )
    {
      this->eyeLidUserChannels[0].value = HIWORD(idMD6Skel::GetUserChannelIndex(
                                                   this: v139,
                                                   result: *(idIndex<short,enum invalidUserChannelIndex_t> **)(v40 + 212),
                                                   name: "facedata_L_eyelidsClose")->__vftable);
      UserChannelIndex = (__int16 *)idMD6Skel::GetUserChannelIndex(
                                      this: (idMD6Skel *)((char *)&v139[0].__vftable + 2),
                                      result: *(idIndex<short,enum invalidUserChannelIndex_t> **)(v40 + 212),
                                      name: "facedata_R_eyelidsClose");
      v52 = *UserChannelIndex;
      value = (unsigned __int16)this->eyeLidUserChannels[0].value;
      this->eyeLidUserChannels[1].value = *UserChannelIndex;
      if ( value >= 0x8000 || v52 < 0 )
      {
        this->eyeLidUserChannels[0].value = -1;
        this->eyeLidUserChannels[1].value = -1;
      }
    }
    else
    {
      this->blinkAlias.value = animation->StrongLoadAlias(
                                 this: (char *)&v139[0].__vftable + 2,
                                 result: animation,
                                 a3: ta->decl,
                                 a4: idFaceMgr::BLINK_ANIM_NAME)->value;
    }
  }
  else
  {
    this->blinkAlias = NULL_ALIAS;
  }
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v139[0].networkID);
  RD_EventEnd();
  RD_EventBegin(name: "idFaceMgr::Init - Lids");
  LODWORD(v54) = "idFaceMgr::Init - Lids";
  HIDWORD(v54) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v139[0].networkID, pl: &pLog, gMask: v54, label: v55);
  lidDeformationAliases = this->lidDeformationAliases;
  v57 = idFaceMgr::LID_DEFORM_ALIAS_NAMES;
  for ( i = 5; i != 0; --i )
  {
    if ( a34 != 0 )
      lidDeformationAliases->value = animation->StrongLoadAlias(
                                       this: (char *)&v139[0].__vftable + 2,
                                       result: animation,
                                       a3: ta->decl,
                                       a4: *v57)->value;
    else
      lidDeformationAliases->value = NULL_ALIAS.value;
    ++lidDeformationAliases;
    ++v57;
  }
  if ( v139[0].networkID >= 0 )
  {
    staleCount = v139[0].staleCount;
    v60 = *(_DWORD *)(v139[0].staleCount + 16) + 16 * v139[0].networkID;
    v61 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v62 = *(_QWORD *)(v60 + 8);
    HIDWORD(v62) = *(_DWORD *)(v60 + 4);
    LODWORD(v63) = v61 - v62;
    *(_QWORD *)(v60 + 8) = v63;
    *(_DWORD *)(staleCount + 32) = HIDWORD(v62);
  }
  RD_EventEnd();
  RD_EventBegin(name: "idFaceMgr::Init - eye tracking");
  v139[0].staleCount = (int)&pLog;
  v139[0].networkID = -1;
  v64 = -1;
  if ( (pLog.groupMask & 2) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v65 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v65 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v65->label = "idFaceMgr::Init - eye tracking";
    v65->parent = pLog.lastEntry;
    v64 = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    v139[0].networkID = pLog.logEntries.num - 1;
    LODWORD(v66) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v65->totalTicks = v66;
  }
  if ( a28 != 0 )
  {
    v67 = *(idIndex<short,enum invalidJointIndex_t> **)(v40 + 212);
    this->useFaceSetupEyeTracking = a30;
    this->headJointIndex.value = HIWORD(idMD6Skel::GetJointIndex(
                                          this: (idMD6Skel *)((char *)&v139[0].__vftable + 2),
                                          result: v67,
                                          name: idFaceMgr::HEAD_JOINT_NAME)->__vftable);
    v68 = &this->lidDeformationAliases[4];
    v69 = 4;
    v70 = &idFaceMgr::LID_DEFORM_ALIAS_NAMES[4];
    do
    {
      ++v70;
      --v69;
      ++v68;
      v68->value = (unsigned __int16)HIWORD(idMD6Skel::GetUserChannelIndex(
                                              this: (idMD6Skel *)((char *)&v139[0].__vftable + 2),
                                              result: (idIndex<short,enum invalidUserChannelIndex_t> *)v67,
                                              name: *v70)->__vftable);
    }
    while ( v69 != 0 );
    eyeJointIndex = this->eyeJointIndex;
    v72 = idEyeInfo::eyeNames;
    for ( j = 2; j != 0; --j )
    {
      JointGroupCollection = idTreeAnimator::GetJointGroupCollection(this: ta);
      JointGroupForName = idJointGroupCollection::GetJointGroupForName(this: JointGroupCollection, type: 9, name: *v72);
      if ( JointGroupForName != nullptr && JointGroupForName->joints.num > 0 )
      {
        eyeJointIndex->value = JointGroupForName->joints.list->value;
      }
      else
      {
        v76 = *v72;
        ModelDefName = idTreeAnimator::GetModelDefName(this: ta);
        idLib::Warning(fmt: "modelDef '%s' is missing the '%s' joint group.", ModelDefName, v76);
      }
      ++eyeJointIndex;
      ++v72;
    }
    this->initEyeTracking = true;
  }
  else
  {
    v78 = ta->decl;
    p_jointGroupCollection = &v78->jointGroupCollection;
    if ( v78 == nullptr )
      p_jointGroupCollection = nullptr;
    v80 = this->eyeJointIndex;
    v81 = idEyeInfo::eyeNames;
    for ( k = 2; k != 0; --k )
    {
      if ( p_jointGroupCollection != nullptr
        && (v83 = idJointGroupCollection::GetJointGroupForName(this: p_jointGroupCollection, type: 9, name: *v81)) != nullptr
        && v83->joints.num > 0 )
      {
        v80->value = v83->joints.list->value;
      }
      else
      {
        v80->value = NULL_JOINT_INDEX.value;
      }
      ++v80;
      ++v81;
    }
  }
  if ( v64 >= 0 )
  {
    v84 = &pLog.logEntries.list[v64];
    v85 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    parent = v84->parent;
    LODWORD(v87) = v85 - LODWORD(v84->totalTicks);
    v84->totalTicks = v87;
    pLog.lastEntry = parent;
  }
  RD_EventEnd();
  RD_EventBegin(name: "idFaceMgr::Init - visemes");
  v88 = -1;
  v139[0].staleCount = (int)&pLog;
  v139[0].networkID = -1;
  if ( (pLog.groupMask & 2) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v89 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v89 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v89->label = "idFaceMgr::Init - visemes";
    v89->parent = pLog.lastEntry;
    v88 = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    v139[0].networkID = pLog.logEntries.num - 1;
    LODWORD(v90) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v89->totalTicks = v90;
  }
  if ( enableLipSyncAnimation )
  {
    v91 = 0;
    for ( m = idDeclVisemeSet::resourceList.num; v91 < m; ++v91 )
    {
      v93 = (const idDeclVisemeSet *)idResourceList::Index(this: &idDeclVisemeSet::resourceList, index: v91);
      if ( v93 != nullptr )
        idFaceMgr::LoadVisemeSetAnims(this, ta, vset: v93, load: true);
    }
  }
  if ( v88 >= 0 )
  {
    v94 = &pLog.logEntries.list[v88];
    v95 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v96 = v94->parent;
    LODWORD(v97) = v95 - LODWORD(v94->totalTicks);
    v94->totalTicks = v97;
    pLog.lastEntry = v96;
  }
  RD_EventEnd();
  if ( (unsigned __int8)idFaceAnimator::Init(this: &this->faceAnimator, fm: this, owner, ta) == 0 )
  {
    this->lastFidgetTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->lastGlanceTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( (int)v139[0].resourceListPtr >= 0 )
    {
      resourceError = v139[0].resourceError;
      v135 = *((_DWORD *)v139[0].resourceError + 4) + 16 * (int)v139[0].resourceListPtr;
      v136 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v137 = *(_QWORD *)(v135 + 8);
      HIDWORD(v137) = *(_DWORD *)(v135 + 4);
      LODWORD(v138) = v136 - v137;
      *(_QWORD *)(v135 + 8) = v138;
      *((_DWORD *)resourceError + 8) = HIDWORD(v137);
    }
    goto LABEL_130;
  }
  RD_EventBegin(name: "idFaceMgr::Init - enable");
  v98 = -1;
  v139[0].staleCount = (int)&pLog;
  v139[0].networkID = -1;
  if ( (pLog.groupMask & 2) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v99 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v99 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v99->label = "idFaceMgr::Init - enable";
    v99->parent = pLog.lastEntry;
    v98 = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    v139[0].networkID = pLog.logEntries.num - 1;
    LODWORD(v100) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v99->totalTicks = v100;
  }
  trackedMemory = v139[0].trackedMemory;
  if ( v139[0].trackedMemory != 0 )
    v102 = this->flags | 1;
  else
    v102 = this->flags & 0xFFFE;
  this->flags = v102;
  if ( owner != nullptr )
  {
    v103 = owner->GetAnimStack_2(this: owner);
    if ( v103 != nullptr )
    {
      p_moodAnimator = &this->faceAnimator.moodAnimator;
      if ( trackedMemory != 0 )
        idAnimStack::SetAnimatorFlag(this: v103, animator: p_moodAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v103, animator: p_moodAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  if ( enableLipSyncAnimation )
    v105 = this->flags | 2;
  else
    v105 = this->flags & 0xFFFD;
  this->flags = v105;
  if ( owner != nullptr )
  {
    v106 = owner->GetAnimStack_2(this: owner);
    if ( v106 != nullptr )
    {
      p_lipAnimator = &this->faceAnimator.lipAnimator;
      if ( enableLipSyncAnimation )
        idAnimStack::SetAnimatorFlag(this: v106, animator: p_lipAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v106, animator: p_lipAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  if ( enableGestureAnimation )
    v108 = this->flags | 4;
  else
    v108 = this->flags & 0xFFFB;
  this->flags = v108;
  idFaceAnimator::SetEnableGestures(this: &this->faceAnimator, fm: this, owner, enable: enableGestureAnimation);
  if ( a28 != 0 )
  {
    flags = this->flags;
    this->initEyeTracking = true;
    v110 = flags | 8;
  }
  else
  {
    v110 = this->flags & 0xFFF7;
  }
  str = v139[0].name.str;
  this->flags = v110;
  if ( str != nullptr )
    v112 = v110 | 0x10;
  else
    v112 = this->flags & 0xFFEF;
  this->flags = v112;
  if ( owner != nullptr )
  {
    v113 = owner->GetAnimStack_2(this: owner);
    if ( v113 != nullptr )
    {
      p_eyeAnimator = &this->faceAnimator.eyeAnimator;
      if ( str != nullptr )
        idAnimStack::SetAnimatorFlag(this: v113, animator: p_eyeAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v113, animator: p_eyeAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  if ( a34 != 0 )
    v115 = this->flags | 0x20;
  else
    v115 = this->flags & 0xFFDF;
  this->flags = v115;
  if ( owner != nullptr )
  {
    v116 = owner->GetAnimStack_2(this: owner);
    if ( v116 != nullptr )
    {
      p_lidDeformAnimator = &this->faceAnimator.lidDeformAnimator;
      if ( a34 != 0 )
        idAnimStack::SetAnimatorFlag(this: v116, animator: p_lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v116, animator: p_lidDeformAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  this->voiceChannel = voiceChannel;
  if ( str != nullptr )
    v118 = this->flags | 0x400;
  else
    v118 = this->flags & 0xFBFF;
  this->flags = v118;
  if ( owner != nullptr )
  {
    v119 = owner->GetAnimStack_2(this: owner);
    if ( v119 != nullptr )
    {
      p_glanceAnimator = &this->faceAnimator.glanceAnimator;
      if ( str != nullptr )
        idAnimStack::SetAnimatorFlag(this: v119, animator: p_glanceAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v119, animator: p_glanceAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  if ( str != nullptr )
    v121 = this->flags | 0x4000;
  else
    v121 = this->flags & 0xBFFF;
  this->flags = v121;
  if ( owner != nullptr )
  {
    v122 = owner->GetAnimStack_2(this: owner);
    if ( v122 != nullptr )
    {
      p_idleFidgetAnimator = &this->faceAnimator.idleFidgetAnimator;
      if ( str != nullptr )
        idAnimStack::SetAnimatorFlag(this: v122, animator: p_idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
      else
        idAnimStack::ClearAnimatorFlag(this: v122, animator: p_idleFidgetAnimator, flag: ANIMATORFLAG_ENABLED);
    }
  }
  if ( v98 >= 0 )
  {
    v124 = &pLog.logEntries.list[v98];
    v125 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v126 = v124->parent;
    LODWORD(v127) = v125 - LODWORD(v124->totalTicks);
    v124->totalTicks = v127;
    pLog.lastEntry = v126;
  }
  RD_EventEnd();
  if ( (int)v139[0].resourceListPtr >= 0 )
  {
    v128 = v139[0].resourceError;
    v129 = *((_DWORD *)v139[0].resourceError + 4) + 16 * (int)v139[0].resourceListPtr;
    v130 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v131 = *(_QWORD *)(v129 + 8);
    HIDWORD(v131) = *(_DWORD *)(v129 + 4);
    LODWORD(v132) = v130 - v131;
    *(_QWORD *)(v129 + 8) = v132;
    *((_DWORD *)v128 + 8) = HIDWORD(v131);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$495950
// EA  : 0x82B32E84
// RVA : 0x00B32E84
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495950()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$495951
// EA  : 0x82B32EAC
// RVA : 0x00B32EAC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495951()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$495952
// EA  : 0x82B32ED4
// RVA : 0x00B32ED4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495952()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 113));
}


// ========================================================================
// __unwind$495953
// EA  : 0x82B32EFC
// RVA : 0x00B32EFC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495953()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$495954
// EA  : 0x82B32F24
// RVA : 0x00B32F24
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495954()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 114));
}


// ========================================================================
// __unwind$495955
// EA  : 0x82B32F4C
// RVA : 0x00B32F4C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495955()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$495956
// EA  : 0x82B32F74
// RVA : 0x00B32F74
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495956()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 115));
}


// ========================================================================
// __unwind$495957
// EA  : 0x82B32F9C
// RVA : 0x00B32F9C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495957()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$495958
// EA  : 0x82B32FC4
// RVA : 0x00B32FC4
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495958()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 116));
}


// ========================================================================
// __unwind$495959
// EA  : 0x82B32FEC
// RVA : 0x00B32FEC
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495959()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$495960
// EA  : 0x82B33014
// RVA : 0x00B33014
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495960()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 117));
}


// ========================================================================
// __unwind$495961
// EA  : 0x82B3303C
// RVA : 0x00B3303C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495961()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$495962
// EA  : 0x82B33064
// RVA : 0x00B33064
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495962()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 118));
}


// ========================================================================
// __unwind$495963
// EA  : 0x82B3308C
// RVA : 0x00B3308C
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_495963()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// ?Update@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@ABVidVec3@@@Z
// EA  : 0x82B330C0
// RVA : 0x00B330C0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idFaceMgr::Update(idFaceMgr *this, idAI2 *owner, idTreeAnimator *ta, const idVec3 *focusPoint)
{
  idTreeAnimator *v6; // r14
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idAI2 *v9; // r3
  _DWORD *v10; // r28
  mood_t mood; // r11
  char v12; // r16
  unsigned __int64 v13; // r6
  const char *v14; // r7
  bool v15; // r10
  char v16; // r29
  bool IsCurrentlyGlancing; // r17
  bool IsCurrentlyFidgeting; // r3
  char v19; // r18
  unsigned __int16 flags; // r9
  BOOL v21; // r20
  char v22; // r10
  BOOL v23; // r21
  char v24; // r8
  char v25; // r23
  bool v26; // r25
  int v27; // r14
  double RandomInterval; // fp1
  __int64 v29; // r7
  int v30; // r14
  double v31; // fp1
  __int64 v32; // r6
  int v33; // r23
  double v34; // fp1
  __int64 v35; // r7
  int v36; // r28
  double v37; // fp1
  __int64 v38; // r6
  int lastGlanceTime; // r28
  int GameMs; // r3
  char v41; // r11
  encounterGroupRole_t v42; // r28
  const idDeclFacialAnimationSet *FacialAnimSetDecl; // r3
  int v44; // r28
  idDeclMD6 *decl; // r27
  const idDeclFacialAnimationSet *v46; // r3
  const idMD6Anim *v47; // r3
  encounterGroupRole_t v48; // r28
  const idDeclFacialAnimationSet *v49; // r3
  int v50; // r28
  idDeclMD6 *v51; // r27
  const idDeclFacialAnimationSet *v52; // r3
  const idMD6Anim *v53; // r3
  char v54; // r21
  idGameTimeManager *p_gameTimeManager; // r3
  __int64 v56; // r9 OVERLAPPED
  __int64 v57; // r6 OVERLAPPED
  int v58; // r25
  __int16 y_high; // r11
  int x_high; // r26
  int v61; // r28
  int v62; // r27
  int v63; // r3
  unsigned __int16 v64; // r11
  int v65; // r26
  double valueFloat; // fp31
  __int64 v67; // r9
  __int64 v68; // r7
  int v69; // r27
  __int64 v70; // r7
  double v71; // fp10
  double v72; // fp31
  int v73; // r3
  __int64 v74; // r8
  int v75; // r5
  int v76; // r3
  __int64 v77; // r8
  int v78; // r5
  int v79; // r25
  __int16 v80; // r11
  int v81; // r26
  int v82; // r28
  int v83; // r27
  int v84; // r3
  unsigned __int16 v85; // r11
  int v86; // r26
  double v87; // fp31
  __int64 v88; // r9
  const idDeclMD6 *v89; // r11
  idEyeInfoCollection *p_eyeInfoCollection; // r28
  idEyeInfoCollection *EyeInfoHandle; // r3
  const idEyeInfo *EyeInfo; // r23
  idPhysics *Physics; // r3
  float *v94; // r3
  double v95; // fp0
  double v96; // fp13
  idIndex<short,enum invalidJointIndex_t> *v97; // r28
  int *p_size; // r24
  idMat3 *v99; // r25
  idIndex<short,enum invalidJointIndex_t> *v100; // r26
  int v101; // r27
  long double v102; // fp4
  double v103; // fp28
  double v104; // fp30
  double v105; // fp29
  int y_low; // r26
  int z_high; // r27
  long double v108; // fp2
  long double v109; // fp2
  double v110; // fp13
  double v111; // fp9
  double v112; // fp30
  long double v113; // fp2
  double v114; // fp30
  double v115; // fp28
  double v116; // fp25
  idClientGame *v117; // r11
  int v118; // r29
  idAngles *eyeAngles; // r22
  idEyeInfo::eye_t v120; // r29
  int *v121; // r25
  const idMat3 *v122; // r27
  idAngles *v123; // r26
  double v124; // fp0
  double v125; // fp10
  double v126; // fp11
  double v127; // fp12
  double v128; // fp0
  double v129; // fp12
  double v130; // fp13
  double v131; // fp0
  int v132; // r29
  const idAnimStack *v133; // r3
  idVec3 *v134; // r26
  idMat3 *v135; // r27
  idIndex<short,enum invalidJointIndex_t> *eyeJointIndex; // r28
  int v137; // r29
  double y; // fp4
  double x; // fp3
  int v140; // r29
  int v141; // r28
  int v142; // r27
  int v143; // r26
  long double v144; // fp2
  double v145; // fp30
  double v146; // fp12
  long double v147; // fp2
  double v148; // fp30
  double v149; // fp1
  char *v150; // r11
  int v151; // r10
  double v152; // fp0
  int v153; // r10
  double v154; // fp0
  int v155; // r10
  double v156; // fp0
  int v157; // r11
  double v158; // fp0
  idPLog *pLog; // r28
  idPLog::logEntry_t *v160; // r29
  int v161; // r3
  __int64 totalTicks; // r11
  __int64 v163; // r9
  int num; // r29
  int v165; // r30
  int v166; // r3
  __int64 v167; // r11
  __int64 v168; // r9
  idEyeInfo::eye_t v169; // [sp+8h] [-238h]
  idAngles *v170; // [sp+Ch] [-234h]
  int v171; // [sp+10h] [-230h]
  int v172; // [sp+14h] [-22Ch]
  int v173; // [sp+18h] [-228h]
  int v174; // [sp+1Ch] [-224h]
  int v175; // [sp+20h] [-220h]
  int v176; // [sp+24h] [-21Ch]
  int v177; // [sp+28h] [-218h]
  int v178; // [sp+2Ch] [-214h]
  int v179; // [sp+30h] [-210h]
  int v180; // [sp+34h] [-20Ch]
  int v181; // [sp+38h] [-208h]
  int v182; // [sp+3Ch] [-204h]
  int v183; // [sp+40h] [-200h]
  int v184; // [sp+44h] [-1FCh]
  int v185; // [sp+48h] [-1F8h]
  int v186; // [sp+4Ch] [-1F4h]
  int v187; // [sp+50h] [-1F0h]
  int v188; // [sp+58h] [-1E8h]
  idVec3 v189; // [sp+60h] [-1E0h] BYREF
  idHandle<unsigned short,enum invalidEyeInfo_t,65535> v190; // [sp+6Ch] [-1D4h] BYREF
  idVec3 *p_eyeJitterOffset; // [sp+70h] [-1D0h]
  idVec3 v192; // [sp+80h] [-1C0h] BYREF
  float v193; // [sp+8Ch] [-1B4h]
  float v194; // [sp+90h] [-1B0h]
  idEyeInfoCollection v195; // [sp+94h] [-1ACh] BYREF
  float v196; // [sp+A8h] [-198h]
  float v197; // [sp+ACh] [-194h]
  float v198; // [sp+B0h] [-190h]
  float v199; // [sp+B4h] [-18Ch]
  idPLogScope v200; // [sp+B8h] [-188h] BYREF
  float v201[8]; // [sp+C0h] [-180h] BYREF
  idMat3 v202; // [sp+E0h] [-160h] BYREF
  idVec3 v203[2]; // [sp+108h] [-138h] BYREF
  _BYTE v204[136]; // [sp+120h] [-120h] BYREF

  v6 = ta;
  RD_EventBegin(name: "idFaceMgr::Update");
  LODWORD(v7) = "idFaceMgr::Update";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v195.eyeInfos, pl: &::pLog, gMask: v7, label: v8);
  if ( v6 == nullptr
    || (v9 = idAI2::CastTo(c: owner), v10 = &v9->__vftable, *(_DWORD *)&v195.curHandle = v9, v9 != nullptr)
    && (v9->IsDead(this: v9) || (*(unsigned __int8 (__fastcall **)(_DWORD *))(*v10 + 512))(a1: v10) != 0)
    && (int)v10[4817] > 0 )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v195.eyeInfos);
    goto LABEL_164;
  }
  idFaceMgr::UpdateLipSync(this, owner, ta: v6);
  if ( (this->flags & 1) != 0 )
  {
    mood = this->mood;
    if ( mood != MOOD_NONE && mood != this->lastMood )
    {
      this->lastMood = mood;
      idFaceAnimator::AnimateMood(this: &this->faceAnimator, fm: this, owner, ta: v6);
    }
  }
  v12 = 0;
  p_eyeJitterOffset = nullptr;
  if ( v10 != nullptr && v10[1786] != 1 )
    p_eyeJitterOffset = (idVec3 *)v10[2850];
  RD_EventBegin(name: "idFaceManager::Update - eyes");
  LODWORD(v13) = "idFaceManager::Update - eyes";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v200, pl: &::pLog, gMask: v13, label: v14);
  v15 = idFaceMgr::GetFacialAnimSetDecl(this, owner) != nullptr;
  if ( face_enableGlancing.valueInteger == 0 || (this->flags & 0x400) == 0 || (v16 = 1, !v15) )
    v16 = 0;
  if ( face_enableFidgeting.valueInteger != 0 && (this->flags & 0x4000) != 0 && v15 )
    v12 = 1;
  IsCurrentlyGlancing = idFaceAnimator::IsCurrentlyGlancing(this: &this->faceAnimator, owner);
  IsCurrentlyFidgeting = idFaceAnimator::IsCurrentlyFidgeting(this: &this->faceAnimator, owner);
  v19 = IsCurrentlyFidgeting;
  if ( v16 != 0 || v12 != 0 )
  {
    flags = this->flags;
    v21 = (flags & 0x800) != 0;
    if ( (flags & 0x800) != 0 || IsCurrentlyGlancing || (v22 = 1, !this->glancingPreviousFrame) )
      v22 = 0;
    v23 = (flags & 0x8000) != 0;
    this->glancingPreviousFrame = (flags & 0x800) == 0 && IsCurrentlyGlancing;
    if ( (flags & 0x8000) != 0 || IsCurrentlyFidgeting || (v24 = 1, !this->fidgetingPreviousFrame) )
      v24 = 0;
    this->fidgetingPreviousFrame = (flags & 0x8000) == 0 && IsCurrentlyFidgeting;
    v25 = v24;
    v26 = (_cntlzw(owner->entityNumber - face_debugFluff.valueInteger) & 0x20) != 0;
    if ( v22 != 0 || this->currentGlanceInterval < 0 )
    {
      this->lastGlanceTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v27 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      RandomInterval = GetRandomInterval(
                         _min: face_glanceIntervalMin.valueFloat,
                         _max: face_glanceIntervalMax.valueFloat);
      LODWORD(v29) = v27;
      this->currentGlanceInterval = (int)(float)((float)RandomInterval * (float)v29);
      v30 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v31 = GetRandomInterval(_min: face_fluffMinIntervalMin.valueFloat, _max: face_fluffMinIntervalMax.valueFloat);
      LODWORD(v32) = v30;
      HIDWORD(v32) = v26;
      *(_QWORD *)&v189.x = v32;
      this->currentFluffInterval = (int)(float)((float)v31 * (float)v32);
      if ( v26 )
        idLib::Printf(
          fmt: " face fluff -- glance finished, new glance interval chosen, %i\n ",
          this->currentGlanceInterval);
      v6 = ta;
    }
    if ( v25 != 0 || this->currentFidgetInterval < 0 )
    {
      this->lastFidgetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v33 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v34 = GetRandomInterval(_min: face_fidgetIntervalMin.valueFloat, _max: face_fidgetIntervalMax.valueFloat);
      LODWORD(v35) = v33;
      this->currentFidgetInterval = (int)(float)((float)v34 * (float)v35);
      v36 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v37 = GetRandomInterval(_min: face_fluffMinIntervalMin.valueFloat, _max: face_fluffMinIntervalMax.valueFloat);
      LODWORD(v38) = v36;
      HIDWORD(v38) = v26;
      *(_QWORD *)&v189.x = v38;
      this->currentFluffInterval = (int)(float)((float)v37 * (float)v38);
      if ( v26 )
        idLib::Printf(
          fmt: " face fluff -- fidget finished, new fidget interval chosen, %i\n ",
          this->currentGlanceInterval);
    }
    lastGlanceTime = this->lastGlanceTime;
    if ( lastGlanceTime <= this->lastFidgetTime )
      lastGlanceTime = this->lastFidgetTime;
    if ( this->currentFluffInterval <= -1
      || (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
          v41 = 1,
          GameMs - lastGlanceTime <= this->currentFluffInterval) )
    {
      v41 = 0;
    }
    if ( v41 != 0 && !IsCurrentlyGlancing && v19 == 0 )
    {
      if ( v16 != 0
        && !v21
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - this->lastGlanceTime >= this->currentGlanceInterval )
      {
        v42 = idFaceMgr::SelectNewGlanceIndex(this, owner, ta: v6);
        if ( v42 >= ROLE_NONE )
        {
          FacialAnimSetDecl = idFaceMgr::GetFacialAnimSetDecl(this, owner);
          v44 = v42;
          idFaceAnimator::Glance(
            this: &this->faceAnimator,
            aliasHandle: &FacialAnimSetDecl->normalGlances.list[v44],
            fm: this,
            owner,
            ta: v6);
          IsCurrentlyGlancing = true;
          this->currentGlanceInterval = idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED)
                                      + 10000;
          if ( v26 )
          {
            decl = v6->decl;
            v46 = idFaceMgr::GetFacialAnimSetDecl(this, owner);
            v47 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &v46->normalGlances.list[v44], load: false);
            idLib::Printf(fmt: " face fluff -- starting glance, %s\n ", v47->name.str);
          }
        }
      }
      if ( !IsCurrentlyGlancing
        && v12 != 0
        && !v23
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - this->lastFidgetTime >= this->currentFidgetInterval )
      {
        v48 = idFaceMgr::SelectNewFidgetIndex(this, owner, ta: v6);
        if ( v48 >= ROLE_NONE )
        {
          v49 = idFaceMgr::GetFacialAnimSetDecl(this, owner);
          v50 = v48;
          idFaceAnimator::Fidget(
            this: &this->faceAnimator,
            aliasHandle: &v49->focusFidgets.list[v50],
            fm: this,
            owner,
            ta: v6);
          v19 = 1;
          this->currentFidgetInterval = idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED)
                                      + 10000;
          if ( v26 )
          {
            v51 = v6->decl;
            v52 = idFaceMgr::GetFacialAnimSetDecl(this, owner);
            v53 = idDeclMD6::AnimForAlias(this: v51, aliasHandle: &v52->focusFidgets.list[v50], load: false);
            idLib::Printf(fmt: " face fluff -- starting fidget, %s\n ", v53->name.str);
          }
        }
      }
    }
  }
  if ( !IsCurrentlyGlancing )
  {
    v54 = 0;
    if ( v19 == 0 )
    {
      p_gameTimeManager = &clientGame->gameTimeManager;
      if ( this->useFaceSetupBlinking )
      {
        LODWORD(v56) = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        HIDWORD(v56) = this->nextBlinkTime;
        LODWORD(v57) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        HIDWORD(v57) = &unk_82150000;
        *(_QWORD *)&v189.x = v57;
        if ( (float)v56 >= (double)(float)((float)((float)v57 * (float)0.40000001)
                                         + (float)*(__int64 *)((char *)&v56 + 4)) )
        {
          if ( p_eyeJitterOffset != nullptr )
          {
            v58 = BYTE2(p_eyeJitterOffset[35].z);
            y_high = HIWORD(p_eyeJitterOffset[36].y);
            x_high = SHIWORD(p_eyeJitterOffset[36].x);
            v61 = y_high;
            v62 = y_high;
          }
          else
          {
            v58 = 25;
            x_high = 300;
            v61 = 2500;
            v62 = 10000;
          }
          if ( (this->flags & 0x40) != 0 || idRandom2::RandomInt(this: &clientGame->random, min: 0, max: 100) >= v58 )
          {
            v65 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            valueFloat = face_blinkScale.valueFloat;
            LODWORD(v67) = GetRandomInterval(_min: v61, _max: v62);
            HIDWORD(v67) = this->flags;
            LODWORD(v68) = v65;
            *(_QWORD *)&v189.x = v68;
            this->flags = WORD1(v67) & 0xFFBF;
            this->nextBlinkTime = (int)(float)((float)((float)v67 * (float)valueFloat) + (float)v68);
          }
          else
          {
            v63 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v64 = this->flags;
            this->nextBlinkTime = v63 + x_high;
            this->flags = v64 | 0x40;
          }
        }
        v69 = *(_DWORD *)&v195.curHandle;
        if ( *(_DWORD *)&v195.curHandle != 0 && (unsigned __int16)this->eyeLidUserChannels[0].value < 0x8000u )
        {
          LODWORD(v70) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                       - this->nextBlinkTime;
          *(_QWORD *)&v189.x = v70;
          v71 = (float)((float)((float)v70 * (float)0.001) * (float)-5.0);
          v72 = (float)-(float)((float)((float)v71 * (float)v71) - (float)1.0);
          if ( v72 > 0.0 )
          {
            v73 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idAnimator_FaceTracks::AddUserChannelMod(
              this: (idAnimator_FaceTracks *)(*(_DWORD *)&v195.curHandle + 34520),
              userChannel: (idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)this->eyeLidUserChannels[0].value,
              value: v72,
              curTime: v75,
              a5: v73,
              a6: v74);
            v76 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idAnimator_FaceTracks::AddUserChannelMod(
              this: (idAnimator_FaceTracks *)(*(_DWORD *)&v195.curHandle + 34520),
              userChannel: (idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)this->eyeLidUserChannels[1].value,
              value: v72,
              curTime: v78,
              a5: v76,
              a6: v77);
          }
        }
        goto LABEL_92;
      }
      if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED) >= this->nextBlinkTime
        && this->blinkAlias.value != NULL_ALIAS.value )
      {
        if ( p_eyeJitterOffset != nullptr )
        {
          v79 = BYTE2(p_eyeJitterOffset[35].z);
          v80 = HIWORD(p_eyeJitterOffset[36].y);
          v81 = SHIWORD(p_eyeJitterOffset[36].x);
          v82 = v80;
          v83 = v80;
        }
        else
        {
          v79 = 25;
          v81 = 300;
          v82 = 2500;
          v83 = 10000;
        }
        if ( (this->flags & 0x40) != 0 || idRandom2::RandomInt(this: &clientGame->random, min: 0, max: 100) >= v79 )
        {
          v86 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v87 = face_blinkScale.valueFloat;
          LODWORD(v88) = GetRandomInterval(_min: v82, _max: v83);
          HIDWORD(v88) = this->flags;
          *(_QWORD *)&v192.x = v88;
          *(_QWORD *)&v189.x = __PAIR64__(HIDWORD(v88), v86);
          this->flags = WORD1(v88) & 0xFFBF;
          this->nextBlinkTime = (int)(float)((float)((float)v88 * (float)v87) + (float)__SPAIR64__(HIDWORD(v88), v86));
        }
        else
        {
          v84 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v85 = this->flags;
          this->nextBlinkTime = v84 + v81;
          this->flags = v85 | 0x40;
        }
        if ( (unsigned __int8)idFaceMgr::AnimateBlinks(this) != 0 )
        {
          if ( face_skipBlink.valueInteger == 0 && face_skipProcedural.valueInteger == 0 )
            idFaceAnimator::Blink(this: &this->faceAnimator, fm: this, owner, ta: v6);
          v54 = 1;
        }
      }
    }
    v69 = *(_DWORD *)&v195.curHandle;
LABEL_92:
    if ( (this->flags & 8) != 0 )
    {
      if ( this->useFaceSetupEyeTracking )
      {
        v134 = (idVec3 *)v201;
        v135 = (idMat3 *)v204;
        eyeJointIndex = this->eyeJointIndex;
        v137 = 2;
        do
        {
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: v6,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)eyeJointIndex->value,
            origin: v134,
            axis: v135);
          --v137;
          ++eyeJointIndex;
          ++v135;
          ++v134;
        }
        while ( v137 != 0 );
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v6,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->headJointIndex.value,
          origin: v203,
          axis: &v202);
        y = focusPoint->y;
        x = focusPoint->x;
        v192.z = focusPoint->z - (float)(v201[2] + (float)((float)(v201[5] - v201[2]) * (float)0.5));
        v192.x = (float)x - (float)((float)((float)(v201[3] - v201[0]) * (float)0.5) + v201[0]);
        v192.y = (float)y - (float)(v201[1] + (float)((float)(v201[4] - v201[1]) * (float)0.5));
        idVec3::NormalizeFast(this: &v192);
        if ( (float)((float)(v192.x * v202.mat[0].x)
                   + (float)((float)(v202.mat[0].z * v192.z) + (float)(v202.mat[0].y * v192.y))) > 0.1 )
        {
          v140 = this->eyeFaceChannels[2];
          v141 = this->eyeFaceChannels[3];
          v142 = this->eyeFaceChannels[1];
          v143 = this->eyeFaceChannels[0];
          *((double *)&v144 + 1) = (float)((float)(v202.mat[2].z * v192.z) + (float)(v202.mat[2].y * v192.y));
          *(double *)&v144 = (float)((float)(v202.mat[1].x * v192.x)
                                   + (float)((float)(v202.mat[1].z * v192.z) + (float)(v202.mat[1].y * v192.y)));
          v145 = (float)((float)(v202.mat[2].x * v192.x)
                       + (float)((float)(v202.mat[2].z * v192.z) + (float)(v202.mat[2].y * v192.y)));
          v146 = (float)((float)(idMath::ACos(a: v144) * (float)((float)1.0 / (float)3.1415927)) - (float)0.5);
          *(double *)&v147 = -v145;
          v148 = (float)((float)v146 * (float)4.5454545);
          v149 = idMath::ACos(a: v147);
          v150 = (char *)v6 + ((16 * v6->currentDeferred) ^ 0x10);
          if ( v140 != -1 )
          {
            v151 = *((_DWORD *)v150 + 530);
            v152 = (float)((float)((float)((float)((float)v149 * (float)((float)1.0 / 3.1415927)) - (float)0.5)
                                 * (float)5.1546392)
                         + *(float *)(4 * v140 + v151));
            if ( v152 >= 0.0 )
            {
              if ( v152 > 1.0 )
                v152 = 1.0;
            }
            else
            {
              v152 = 0.0;
            }
            *(float *)(4 * v140 + v151) = (float)((float)v152 - *(float *)(4 * v140 + v151))
                                        + *(float *)(4 * v140 + v151);
          }
          if ( v141 != -1 )
          {
            v153 = *((_DWORD *)v150 + 530);
            v154 = (float)(*(float *)(4 * v141 + v153)
                         - (float)((float)((float)((float)v149 * (float)((float)1.0 / 3.1415927)) - (float)0.5)
                                 * (float)5.1546392));
            if ( v154 >= 0.0 )
            {
              if ( v154 > 1.0 )
                v154 = 1.0;
            }
            else
            {
              v154 = 0.0;
            }
            *(float *)(4 * v141 + v153) = (float)((float)v154 - *(float *)(4 * v141 + v153))
                                        + *(float *)(4 * v141 + v153);
          }
          if ( v142 != -1 )
          {
            v155 = *((_DWORD *)v150 + 530);
            v156 = (float)((float)v148 + *(float *)(4 * v142 + v155));
            if ( v156 >= 0.0 )
            {
              if ( v156 > 1.0 )
                v156 = 1.0;
            }
            else
            {
              v156 = 0.0;
            }
            *(float *)(4 * v142 + v155) = (float)((float)v156 - *(float *)(4 * v142 + v155))
                                        + *(float *)(4 * v142 + v155);
          }
          if ( v143 != -1 )
          {
            v157 = *((_DWORD *)v150 + 530);
            v158 = (float)(*(float *)(4 * v143 + v157) - (float)v148);
            if ( v158 >= 0.0 )
            {
              if ( v158 > 1.0 )
                v158 = 1.0;
            }
            else
            {
              v158 = 0.0;
            }
            *(float *)(4 * v143 + v157) = (float)((float)v158 - *(float *)(4 * v143 + v157))
                                        + *(float *)(4 * v143 + v157);
          }
        }
      }
      else
      {
        v89 = v6->decl;
        p_eyeInfoCollection = &v89->eyeInfoCollection;
        if ( v89 == nullptr )
          p_eyeInfoCollection = nullptr;
        if ( v69 != 0 )
        {
          EyeInfoHandle = (idEyeInfoCollection *)&v190;
          v190.value = *(_WORD *)(v69 + 13336);
        }
        else
        {
          EyeInfoHandle = idEyeInfoCollection::FindEyeInfoHandle(
                            this: &v195,
                            result: p_eyeInfoCollection,
                            name: idEyeInfoCollection::DEFAULT_NAME);
        }
        v190.value = EyeInfoHandle->curHandle;
        EyeInfo = idEyeInfoCollection::GetEyeInfo(this: p_eyeInfoCollection, handle: &v190);
        Physics = idEntity::GetPhysics(this: owner);
        v94 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        if ( EyeInfo != nullptr )
        {
          v95 = (float)(focusPoint->z - v94[2]);
          v96 = (float)(focusPoint->y - v94[1]);
          if ( (float)((float)((float)v95 * (float)v95)
                     + (float)((float)((float)(focusPoint->x - *v94) * (float)(focusPoint->x - *v94))
                             + (float)((float)v96 * (float)v96))) < 1048576.0 )
          {
            v97 = this->eyeJointIndex;
            p_size = &v195.eyeInfos.size;
            v99 = (idMat3 *)v204;
            v100 = this->eyeJointIndex;
            v101 = 2;
            do
            {
              idTreeAnimator::GetWorldSpaceJointTransform(
                this: v6,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v100->value,
                origin: (idVec3 *)p_size,
                axis: v99);
              --v101;
              ++v100;
              ++v99;
              p_size += 3;
            }
            while ( v101 != 0 );
            *((double *)&v102 + 1) = (float)((float)(v199 - v196) * (float)0.5);
            *(double *)&v102 = (float)((float)(v198 - *(float *)&v195.eyeInfos.granularity) * (float)0.5);
            v103 = (float)((float)((float)(v197 - *(float *)&v195.eyeInfos.size) * (float)0.5)
                         + *(float *)&v195.eyeInfos.size);
            v104 = (float)(v196 + (float)((float)(v199 - v196) * (float)0.5));
            v105 = (float)(*(float *)&v195.eyeInfos.granularity
                         + (float)((float)(v198 - *(float *)&v195.eyeInfos.granularity) * (float)0.5));
            if ( p_eyeJitterOffset != nullptr )
            {
              y_low = SLOWORD(p_eyeJitterOffset[36].y);
              z_high = SHIWORD(p_eyeJitterOffset[36].z);
            }
            else
            {
              y_low = 100;
              z_high = 1500;
            }
            if ( v54 != 0
              || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextJitterTime )
            {
              *((double *)&v108 + 1) = face_jitterMinDist.valueFloat;
              *(double *)&v108 = face_eyeJitter.valueFloat;
              v109 = atan2(v: v108, u: v102);
              *(double *)&v109 = (float)*(double *)&v109;
              v110 = (float)(focusPoint->y - (float)v105);
              v111 = (float)(focusPoint->z - (float)v104);
              v112 = __fsqrts((float)((float)((float)v111 * (float)v111)
                                    + (float)((float)((float)(focusPoint->x - (float)v103)
                                                    * (float)(focusPoint->x - (float)v103))
                                            + (float)((float)v110 * (float)v110))));
              v113 = tan(x: v109);
              v114 = (float)((float)*(double *)&v113 * (float)v112);
              v115 = GetRandomInterval(_min: -v114, _max: v114);
              v116 = GetRandomInterval(_min: -v114, _max: v114);
              this->eyeJitterOffset.x = GetRandomInterval(_min: -v114, _max: v114);
              v117 = clientGame;
              this->eyeJitterOffset.y = v116;
              this->eyeJitterOffset.z = v115;
              p_eyeJitterOffset = &this->eyeJitterOffset;
              v118 = idGameTimeManager::GetGameMs(this: &v117->gameTimeManager, type: GAMETIME_SCALED);
              this->nextJitterTime = GetRandomInterval(_min: y_low, _max: z_high) + v118;
            }
            if ( this->initEyeTracking )
            {
              this->eyeAngles[0].pitch = 0.0;
              this->eyeAngles[0].roll = 0.0;
              this->eyeAngles[0].yaw = 0.0;
              this->eyeAngles[1].roll = 0.0;
              this->eyeAngles[1].yaw = 0.0;
              p_eyeJitterOffset = (idVec3 *)&this->eyeAngles[1];
              this->eyeAngles[1].pitch = 0.0;
              this->initEyeTracking = false;
            }
            eyeAngles = this->eyeAngles;
            v120 = EYE_LEFT;
            v121 = &v195.eyeInfos.size;
            v192.x = *(float *)&v195.eyeInfos.size - v197;
            v192.z = v196 - v199;
            v122 = (const idMat3 *)v204;
            v192.y = *(float *)&v195.eyeInfos.granularity - v198;
            v123 = this->eyeAngles;
            do
            {
              idFaceMgr::CalcEyeFocusPoint(
                this: (idFaceMgr *)&v189,
                result: (idVec3 *)this,
                focusPoint,
                eyeDelta: &v192,
                eyeInfo: EyeInfo,
                eye: v120);
              v189.z = face_eyeZOffset.valueFloat + v189.z;
              idFaceMgr::AlignEye(
                this,
                owner,
                ta: v6,
                eyeJoint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v97->value,
                eyeJointPos: (const idVec3 *)v121,
                eyeJointAxis: v122,
                focusPoint: &v189,
                eyeInfo: EyeInfo,
                eye: v169,
                offsetAngle: v170,
                a11: v171,
                a12: v172,
                a13: v173,
                a14: v174,
                a15: v175,
                a16: v176,
                a17: v177,
                a18: v178,
                a19: v179,
                a20: v180,
                a21: v181,
                a22: v182,
                a23: v183,
                a24: v184,
                a25: v185,
                a26: v186,
                a27: v187,
                a28: v120++,
                a29: v188,
                a30: (idQuat *)v123);
              ++v97;
              ++v122;
              ++v123;
              v121 += 3;
            }
            while ( v120 < EYE_MAX );
            v124 = (float)((float)(this->eyeAngles[1].pitch + eyeAngles->pitch) * (float)0.5);
            if ( v124 <= 0.0 )
              v125 = 0.0;
            else
              v125 = (float)((float)((float)(this->eyeAngles[1].pitch + eyeAngles->pitch) * (float)0.5)
                           / EyeInfo->lidMaxPitch);
            v192.z = v125;
            if ( v124 >= 0.0 )
              v126 = 0.0;
            else
              v126 = (float)((float)v124 / EyeInfo->lidMinPitch);
            v127 = (float)(this->eyeAngles[1].yaw + this->eyeAngles[0].yaw);
            v128 = (float)((float)(this->eyeAngles[1].yaw + this->eyeAngles[0].yaw) * (float)0.5);
            v192.y = v126;
            if ( v128 <= 0.0 )
              v129 = 0.0;
            else
              v129 = (float)((float)((float)v127 * (float)0.5) / EyeInfo->lidMaxYaw);
            v194 = v129;
            if ( v128 >= 0.0 )
              v130 = 0.0;
            else
              v130 = (float)((float)v128 / EyeInfo->lidMinYaw);
            v193 = v130;
            v131 = (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125);
            if ( v131 == 0.0 )
            {
              v192.x = 1.0;
            }
            else if ( v131 <= 1.0 )
            {
              v192.x = (float)1.0 - (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125);
            }
            else
            {
              v192.x = 0.0;
              v192.y = (float)((float)1.0
                             / (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125))
                     * (float)v126;
              v192.z = (float)((float)1.0
                             / (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125))
                     * (float)v125;
              v193 = (float)((float)1.0
                           / (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125))
                   * (float)v130;
              v194 = (float)((float)1.0
                           / (float)((float)((float)((float)v130 + (float)v129) + (float)v126) + (float)v125))
                   * (float)v129;
            }
            if ( (this->flags & 0x80) != 0 )
            {
              v132 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
              v133 = owner->GetAnimStack_2(this: owner);
              idAnimator_Base::End(
                this: &this->faceAnimator.lidDeformAnimator,
                stack: v133,
                curTime: v132,
                blendDurationMS: 250,
                reset: true);
            }
            else
            {
              idFaceAnimator::AnimateEyes(
                this: &this->faceAnimator,
                fm: this,
                owner,
                ta: v6,
                eyeInfo: EyeInfo,
                lidAliases: this->lidDeformationAliases,
                lidWeights: &v192.x,
                numAliases: 5);
            }
          }
        }
      }
    }
  }
  if ( v200.logIndex >= 0 )
  {
    pLog = v200.pLog;
    v160 = &v200.pLog->logEntries.list[v200.logIndex];
    v161 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v160->totalTicks;
    HIDWORD(totalTicks) = v160->parent;
    LODWORD(v163) = v161 - totalTicks;
    v160->totalTicks = v163;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  idFaceAnimator::Update(this: &this->faceAnimator, fm: this, owner, ta: v6);
  this->lastFlags = this->flags;
  if ( (int)v195.eyeInfos.list >= 0 )
  {
    num = v195.eyeInfos.num;
    v165 = *(_DWORD *)(v195.eyeInfos.num + 16) + 16 * (int)v195.eyeInfos.list;
    v166 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v167 = *(_QWORD *)(v165 + 8);
    HIDWORD(v167) = *(_DWORD *)(v165 + 4);
    LODWORD(v168) = v166 - v167;
    *(_QWORD *)(v165 + 8) = v168;
    *(_DWORD *)(num + 32) = HIDWORD(v167);
  }
LABEL_164:
  RD_EventEnd();
}


// ========================================================================
// __unwind$496596
// EA  : 0x82B34390
// RVA : 0x00B34390
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_496596()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 576 + 360));
}


// ========================================================================
// __unwind$496597
// EA  : 0x82B343B8
// RVA : 0x00B343B8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_496597()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 576 + 152));
}


// ========================================================================
// __unwind$496598
// EA  : 0x82B343E0
// RVA : 0x00B343E0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_496598()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 576 + 361));
}


// ========================================================================
// __unwind$496599
// EA  : 0x82B34408
// RVA : 0x00B34408
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void _unwind_496599()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 576 + 184));
}


// ========================================================================
// ?StartVoiceOver@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82B34430
// RVA : 0x00B34430
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

int __fastcall idFaceMgr::StartVoiceOver(idFaceMgr *this, idAI2 *owner, idTreeAnimator *ta, const idDeclVoiceOver *vo)
{
  int num; // r4
  const idDeclVoiceOver *voiceOver; // r11
  int nextSampleToPlay; // r30
  int v12; // r11
  char v13; // r3

  if ( vo == nullptr )
    return 0;
  num = vo->tracks.num;
  if ( num == 0 )
    return 0;
  voiceOver = this->voiceOver;
  if ( voiceOver != nullptr && voiceOver == vo )
    return 1;
  nextSampleToPlay = vo->nextSampleToPlay;
  if ( nextSampleToPlay == -1 )
    nextSampleToPlay = idRandom2::RandomInt(this: &clientGame->random, max: num);
  v12 = vo->tracks.num;
  if ( v12 > 1 )
  {
    v13 = idRandom2::RandomInt(this: &clientGame->random, max: v12 - 1);
    vo->nextSampleToPlay = v13;
    if ( v13 >= nextSampleToPlay )
      vo->nextSampleToPlay = v13 + 1;
  }
  return idFaceMgr::StartVoiceTrack(this, owner, ta, vo, trackIndex: nextSampleToPlay);
}


// ========================================================================
// `dynamic initializer for 'face_lipsyncWeight''
// EA  : 0x8336BA60
// RVA : 0x0136BA60
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_lipsyncWeight__()
{
  idCVar::idCVar(
    this: &face_lipsyncWeight,
    name: "face_lipsyncWeight",
    value: "1.0",
    flags: 4,
    description: "max weight for lips",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_lipsyncWeight__);
}


// ========================================================================
// `dynamic initializer for 'face_blinkScale''
// EA  : 0x8336BAB8
// RVA : 0x0136BAB8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_blinkScale__()
{
  idCVar::idCVar(
    this: &face_blinkScale,
    name: "face_blinkScale",
    value: "0.5",
    flags: 4,
    description: "scale blink intervals by this much",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_blinkScale__);
}


// ========================================================================
// `dynamic initializer for 'face_eyeJitter''
// EA  : 0x8336BB10
// RVA : 0x0136BB10
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_eyeJitter__()
{
  idCVar::idCVar(
    this: &face_eyeJitter,
    name: "face_eyeJitter",
    value: "2.0",
    flags: 4,
    description: "maximum jitter offset at a distance of eyeJitterMinDist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_eyeJitter__);
}


// ========================================================================
// `dynamic initializer for 'face_jitterMinDist''
// EA  : 0x8336BB68
// RVA : 0x0136BB68
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_jitterMinDist__()
{
  idCVar::idCVar(
    this: &face_jitterMinDist,
    name: "face_jitterMinDist",
    value: "32.0",
    flags: 4,
    description: "distance at which eye jitter clamps to minimum",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_jitterMinDist__);
}


// ========================================================================
// `dynamic initializer for 'face_eyeDampen''
// EA  : 0x8336BBC0
// RVA : 0x0136BBC0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_eyeDampen__()
{
  idCVar::idCVar(
    this: &face_eyeDampen,
    name: "face_eyeDampen",
    value: "0.5",
    flags: 4,
    description: "dampen factor for eye tracking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_eyeDampen__);
}


// ========================================================================
// `dynamic initializer for 'face_eyeSpreadScale''
// EA  : 0x8336BC18
// RVA : 0x0136BC18
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_eyeSpreadScale__()
{
  idCVar::idCVar(
    this: &face_eyeSpreadScale,
    name: "face_eyeSpreadScale",
    value: "0.1",
    flags: 4,
    description: "scale to apply to the delta between the AI's eyes when offsetting the left eye's focus point",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_eyeSpreadScale__);
}


// ========================================================================
// `dynamic initializer for 'face_skipLidDeform''
// EA  : 0x8336BC70
// RVA : 0x0136BC70
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipLidDeform__()
{
  idCVar::idCVar(
    this: &face_skipLidDeform,
    name: "face_skipLidDeform",
    value: "0",
    flags: 1,
    description: "1 = don't do eye lid deformation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipLidDeform__);
}


// ========================================================================
// `dynamic initializer for 'face_skipLipsync''
// EA  : 0x8336BCC8
// RVA : 0x0136BCC8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipLipsync__()
{
  idCVar::idCVar(
    this: &face_skipLipsync,
    name: "face_skipLipsync",
    value: "0",
    flags: 1,
    description: "1 = don't do eye lip syncing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipLipsync__);
}


// ========================================================================
// `dynamic initializer for 'face_skipBlink''
// EA  : 0x8336BD20
// RVA : 0x0136BD20
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipBlink__()
{
  idCVar::idCVar(
    this: &face_skipBlink,
    name: "face_skipBlink",
    value: "0",
    flags: 1,
    description: "1 = don't blink",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipBlink__);
}


// ========================================================================
// `dynamic initializer for 'face_skipMood''
// EA  : 0x8336BD78
// RVA : 0x0136BD78
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipMood__()
{
  idCVar::idCVar(
    this: &face_skipMood,
    name: "face_skipMood",
    value: "1",
    flags: 1,
    description: "1 = don't play mood anims",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipMood__);
}


// ========================================================================
// `dynamic initializer for 'face_skipHead''
// EA  : 0x8336BDD0
// RVA : 0x0136BDD0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipHead__()
{
  idCVar::idCVar(
    this: &face_skipHead,
    name: "face_skipHead",
    value: "0",
    flags: 1,
    description: "1 = don't play head anims",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipHead__);
}


// ========================================================================
// `dynamic initializer for 'face_skipGestures''
// EA  : 0x8336BE28
// RVA : 0x0136BE28
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipGestures__()
{
  idCVar::idCVar(
    this: &face_skipGestures,
    name: "face_skipGestures",
    value: "0",
    flags: 1,
    description: "1 = don't play gestures",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipGestures__);
}


// ========================================================================
// `dynamic initializer for 'face_skipProcedural''
// EA  : 0x8336BE80
// RVA : 0x0136BE80
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_skipProcedural__()
{
  idCVar::idCVar(
    this: &face_skipProcedural,
    name: "face_skipProcedural",
    value: "0",
    flags: 1,
    description: "1 = don't play procedurally triggered anims (blink, lid deform, lip sync, and mood )",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_skipProcedural__);
}


// ========================================================================
// `dynamic initializer for 'face_debugWeights''
// EA  : 0x8336BED8
// RVA : 0x0136BED8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debugWeights__()
{
  idCVar::idCVar(
    this: &face_debugWeights,
    name: "face_debugWeights",
    value: "0",
    flags: 2,
    description: "1 = show unnormalized weights for each frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debugWeights__);
}


// ========================================================================
// `dynamic initializer for 'face_debug''
// EA  : 0x8336BF30
// RVA : 0x0136BF30
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debug__()
{
  idCVar::idCVar(
    this: &face_debug,
    name: "face_debug",
    value: "0",
    flags: 2,
    description: "1 = show debugging info for face / lip-sync animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debug__);
}


// ========================================================================
// `dynamic initializer for 'face_debugEyes''
// EA  : 0x8336BF88
// RVA : 0x0136BF88
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debugEyes__()
{
  idCVar::idCVar(
    this: &face_debugEyes,
    name: "face_debugEyes",
    value: "0",
    flags: 2,
    description: "1 = show debugging info for eye alignment",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debugEyes__);
}


// ========================================================================
// `dynamic initializer for 'face_eyeZOffset''
// EA  : 0x8336BFE0
// RVA : 0x0136BFE0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_eyeZOffset__()
{
  idCVar::idCVar(
    this: &face_eyeZOffset,
    name: "face_eyeZOffset",
    value: "0",
    flags: 4,
    description: "offset to apply to focus Z",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_eyeZOffset__);
}


// ========================================================================
// `dynamic initializer for 'face_voStreamDelay''
// EA  : 0x8336C038
// RVA : 0x0136C038
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_voStreamDelay__()
{
  idCVar::idCVar(
    this: &face_voStreamDelay,
    name: "face_voStreamDelay",
    value: "250",
    flags: 2,
    description: "delay ( in ms ) to suspend vo starts to accommodate sound streaming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_voStreamDelay__);
}


// ========================================================================
// `dynamic initializer for 'face_debugTextEvent''
// EA  : 0x8336C090
// RVA : 0x0136C090
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debugTextEvent__()
{
  idCVar::idCVar(
    this: &face_debugTextEvent,
    name: "face_debugTextEvent",
    value: &byte_8200D768,
    flags: 0,
    description: "break when the text in a text event matches this value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debugTextEvent__);
}


// ========================================================================
// `dynamic initializer for 'face_mapWeightsToSine''
// EA  : 0x8336C0E8
// RVA : 0x0136C0E8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_mapWeightsToSine__()
{
  idCVar::idCVar(
    this: &face_mapWeightsToSine,
    name: "face_mapWeightsToSine",
    value: "0",
    flags: 1,
    description: "if true, alpha values for visemes are mapped to sine waves for to ease blends in and out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_mapWeightsToSine__);
}


// ========================================================================
// `dynamic initializer for 'face_syncToGameTime''
// EA  : 0x8336C140
// RVA : 0x0136C140
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_syncToGameTime__()
{
  idCVar::idCVar(
    this: &face_syncToGameTime,
    name: "face_syncToGameTime",
    value: "0",
    flags: 1,
    description: "if true, sync lipsync and gestures to game time instead of real time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_syncToGameTime__);
}


// ========================================================================
// `dynamic initializer for 'face_syncToRealTime''
// EA  : 0x8336C198
// RVA : 0x0136C198
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_syncToRealTime__()
{
  idCVar::idCVar(
    this: &face_syncToRealTime,
    name: "face_syncToRealTime",
    value: "0",
    flags: 1,
    description: "if true, sync lipsync and gestures to real time instead of game time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_syncToRealTime__);
}


// ========================================================================
// `dynamic initializer for 'face_debugTime''
// EA  : 0x8336C1F0
// RVA : 0x0136C1F0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debugTime__()
{
  idCVar::idCVar(
    this: &face_debugTime,
    name: "face_debugTime",
    value: "0",
    flags: 2,
    description: "if true, so debugging info for timing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debugTime__);
}


// ========================================================================
// `dynamic initializer for 'face_serialize''
// EA  : 0x8336C248
// RVA : 0x0136C248
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_serialize__()
{
  idCVar::idCVar(
    this: &face_serialize,
    name: "face_serialize",
    value: "0",
    flags: 1,
    description: "Serialize face animators",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_serialize__);
}


// ========================================================================
// `dynamic initializer for 'face_enableGlancing''
// EA  : 0x8336C2A0
// RVA : 0x0136C2A0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_enableGlancing__()
{
  idCVar::idCVar(
    this: &face_enableGlancing,
    name: "face_enableGlancing",
    value: "1",
    flags: 1,
    description: "enable glancing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_enableGlancing__);
}


// ========================================================================
// `dynamic initializer for 'face_enableFidgeting''
// EA  : 0x8336C2F8
// RVA : 0x0136C2F8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_enableFidgeting__()
{
  idCVar::idCVar(
    this: &face_enableFidgeting,
    name: "face_enableFidgeting",
    value: "1",
    flags: 1,
    description: "enable fidgeting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_enableFidgeting__);
}


// ========================================================================
// `dynamic initializer for 'face_debugFluff''
// EA  : 0x8336C350
// RVA : 0x0136C350
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_debugFluff__()
{
  idCVar::idCVar(
    this: &face_debugFluff,
    name: "face_debugFluff",
    value: "0",
    flags: 2,
    description: "entity number to display debug info regarding facial fluff",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_debugFluff__);
}


// ========================================================================
// `dynamic initializer for 'face_glanceIntervalMin''
// EA  : 0x8336C3A8
// RVA : 0x0136C3A8
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_glanceIntervalMin__()
{
  idCVar::idCVar(
    this: &face_glanceIntervalMin,
    name: "face_glanceIntervalMin",
    value: "3",
    flags: 4,
    description: "minimum interval between glances",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_glanceIntervalMin__);
}


// ========================================================================
// `dynamic initializer for 'face_glanceIntervalMax''
// EA  : 0x8336C400
// RVA : 0x0136C400
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_glanceIntervalMax__()
{
  idCVar::idCVar(
    this: &face_glanceIntervalMax,
    name: "face_glanceIntervalMax",
    value: "5",
    flags: 4,
    description: "maximum interval between glances",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_glanceIntervalMax__);
}


// ========================================================================
// `dynamic initializer for 'face_fidgetIntervalMin''
// EA  : 0x8336C458
// RVA : 0x0136C458
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_fidgetIntervalMin__()
{
  idCVar::idCVar(
    this: &face_fidgetIntervalMin,
    name: "face_fidgetIntervalMin",
    value: "6",
    flags: 4,
    description: "minimum interval between fidgets",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_fidgetIntervalMin__);
}


// ========================================================================
// `dynamic initializer for 'face_fidgetIntervalMax''
// EA  : 0x8336C4B0
// RVA : 0x0136C4B0
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_fidgetIntervalMax__()
{
  idCVar::idCVar(
    this: &face_fidgetIntervalMax,
    name: "face_fidgetIntervalMax",
    value: "10",
    flags: 4,
    description: "maximum interval between fidgets",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_fidgetIntervalMax__);
}


// ========================================================================
// `dynamic initializer for 'face_fluffMinIntervalMin''
// EA  : 0x8336C508
// RVA : 0x0136C508
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_fluffMinIntervalMin__()
{
  idCVar::idCVar(
    this: &face_fluffMinIntervalMin,
    name: "face_fluffIntervalMin",
    value: "1",
    flags: 4,
    description: "minimum min interval between any fluff",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_fluffMinIntervalMin__);
}


// ========================================================================
// `dynamic initializer for 'face_fluffMinIntervalMax''
// EA  : 0x8336C560
// RVA : 0x0136C560
// PDB : w:\tech5\tungsten\game\animation\facemgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__face_fluffMinIntervalMax__()
{
  idCVar::idCVar(
    this: &face_fluffMinIntervalMax,
    name: "face_fluffIntervalMax",
    value: "3",
    flags: 4,
    description: "maximum min interval between any fluff",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__face_fluffMinIntervalMax__);
}

