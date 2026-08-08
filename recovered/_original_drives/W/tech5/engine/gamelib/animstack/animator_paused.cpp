
// ========================================================================
// ??0idAnimator_Paused@@QAA@XZ
// EA  : 0x826E8B78
// RVA : 0x006E8B78
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

idAnimator_Paused *__fastcall idAnimator_Paused::idAnimator_Paused(idAnimator_Paused *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->leaf = nullptr;
  this->__vftable = (idAnimator_Paused_vtbl *)&idAnimator_Paused::`vftable';
  this->mergeBranch = nullptr;
  this->anim = nullptr;
  return this;
}


// ========================================================================
// ??1idAnimator_Paused@@UAA@XZ
// EA  : 0x826E8BC8
// RVA : 0x006E8BC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

void __fastcall idAnimator_Paused::~idAnimator_Paused(idAnimator_Paused *this)
{
  this->leaf = nullptr;
  this->__vftable = (idAnimator_Paused_vtbl *)&idAnimator_Paused::`vftable';
  this->mergeBranch = nullptr;
  this->anim = nullptr;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ?Timestamp@idFile_Stat@@UBAIXZ
// EA  : 0x826E8BE8
// RVA : 0x006E8BE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

const idMD6Anim *__fastcall idFile_Stat::Timestamp(idAnimator_Paused *this)
{
  return this->anim;
}


// ========================================================================
// ?GetScriptP@idLexer@@QBAPBDXZ
// EA  : 0x826E8BF0
// RVA : 0x006E8BF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

cmType_t __fastcall idLexer::GetScriptP(idCollisionModelLocal *this)
{
  return this->modelType;
}


// ========================================================================
// ?SetAnim@idAnimator_Paused@@QAAXPBVidMD6Anim@@@Z
// EA  : 0x826E8C70
// RVA : 0x006E8C70
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

void __fastcall idAnimator_Paused::SetAnim(idAnimator_Paused *this, const idMD6Anim *anim_, idMD6Leaf::wrapMode_t a3)
{
  const idMD6Anim *anim; // r10

  this->anim = anim_;
  if ( anim_ != nullptr )
  {
    idMD6LeafPause::Init(
      this: this->leaf,
      anim: anim_,
      frame: this->leaf->frame,
      wrapMode: a3,
      weightGroup: MD6_WEIGHTGROUP_ALL);
    anim = this->anim;
  }
  else
  {
    anim = nullptr;
  }
  this->leaf->anim = anim;
}


// ========================================================================
// ?SetFrame@idAnimator_Paused@@QAAXM@Z
// EA  : 0x826E8CD0
// RVA : 0x006E8CD0
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

void __fastcall idAnimator_Paused::SetFrame(idAnimator_Paused *this, double frame)
{
  this->leaf->frame = frame;
}


// ========================================================================
// ?GetFrame@idAnimator_Paused@@QBAMXZ
// EA  : 0x826E8CE0
// RVA : 0x006E8CE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

float __fastcall idAnimator_Paused::GetFrame(idAnimator_Paused *this)
{
  double frame; // fp1

  frame = this->leaf->frame;
  return *((float *)&frame + 1);
}


// ========================================================================
// ?SetNormalizedFrame@idAnimator_Paused@@QAAXM@Z
// EA  : 0x826E8CF0
// RVA : 0x006E8CF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

void __fastcall idAnimator_Paused::SetNormalizedFrame(idAnimator_Paused *this, double nf, int a3, __int64 a4)
{
  idMD6LeafPause *leaf; // r10

  leaf = this->leaf;
  LODWORD(a4) = leaf->anim->animData->numFrames - 1;
  leaf->frame = (float)a4 * (float)nf;
}


// ========================================================================
// ?InternalInit@idAnimator_Paused@@UAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E8D28
// RVA : 0x006E8D28
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

int __fastcall idAnimator_Paused::InternalInit(idAnimator_Paused *this, const idAnimatorParms_Base *parms)
{
  __int64 v4; // r6
  idMD6LeafPause *v5; // r3
  idMD6Branch *mergeBranch; // r7
  idAnimStack *animStack; // r4
  const idMD6Anim *anim; // r10
  int result; // r3
  idMD6LeafPause *leaf; // r10

  this->mergeBranch = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  v5 = (idMD6LeafPause *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 1);
  mergeBranch = this->mergeBranch;
  this->leaf = v5;
  mergeBranch->right = v5;
  animStack = parms[1].animStack;
  this->anim = (const idMD6Anim *)animStack;
  if ( animStack != nullptr )
  {
    idMD6LeafPause::Init(
      this: this->leaf,
      anim: (const idMD6Anim *)animStack,
      frame: this->leaf->frame,
      wrapMode: SHIDWORD(v4),
      weightGroup: MD6_WEIGHTGROUP_ALL);
    anim = this->anim;
  }
  else
  {
    anim = nullptr;
  }
  result = 1;
  this->leaf->anim = anim;
  if ( *(float *)&parms[1].name.data < 0.0 )
  {
    this->leaf->frame = *(float *)&parms[1].name.len;
  }
  else
  {
    leaf = this->leaf;
    LODWORD(v4) = leaf->anim->animData->numFrames - 1;
    leaf->frame = (float)v4 * *(float *)&parms[1].name.data;
  }
  return result;
}


// ========================================================================
// ?InternalShutdown@idAnimator_Paused@@UAAXPAVidAnimStack@@@Z
// EA  : 0x826E8E38
// RVA : 0x006E8E38
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

void __fastcall idAnimator_Paused::InternalShutdown(idAnimator_Paused *this, idAnimStack *animStack)
{
  idMD6BlockAlloc *p_md6Allocator; // r30

  p_md6Allocator = &animStack->md6Allocator;
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->mergeBranch = nullptr;
  }
  if ( this->leaf != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->leaf = nullptr;
  }
}


// ========================================================================
// ?InternalIsContributing@idAnimator_Paused@@UBA_NXZ
// EA  : 0x826E8EA0
// RVA : 0x006E8EA0
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.cpp
// ========================================================================

int __fastcall idAnimator_Paused::InternalIsContributing(idAnimator_Paused *this)
{
  idMD6LeafPause *leaf; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  leaf = this->leaf;
  if ( leaf == nullptr )
    return 0;
  v3 = leaf->anim != nullptr;
  v2 = 1;
  if ( !v3 )
    return 0;
  return v2;
}

