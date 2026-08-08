
// ========================================================================
// ??0idAnimator_Proxy@@QAA@XZ
// EA  : 0x826EAD50
// RVA : 0x006EAD50
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

idAnimator_Proxy *__fastcall idAnimator_Proxy::idAnimator_Proxy(idAnimator_Proxy *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->mergeBranch = nullptr;
  this->__vftable = (idAnimator_Proxy_vtbl *)&idAnimator_Proxy::`vftable';
  return this;
}


// ========================================================================
// ??1idAnimator_Proxy@@UAA@XZ
// EA  : 0x826EAD98
// RVA : 0x006EAD98
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

void __fastcall idAnimator_Proxy::~idAnimator_Proxy(idAnimator_Proxy *this)
{
  this->mergeBranch = nullptr;
  this->__vftable = (idAnimator_Proxy_vtbl *)&idAnimator_Proxy::`vftable';
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ?SetTree@idAnimator_Proxy@@QAAXPAVidMD6Node@@@Z
// EA  : 0x826EAE20
// RVA : 0x006EAE20
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

void __fastcall idAnimator_Proxy::SetTree(idAnimator_Proxy *this, idMD6Node *tree)
{
  idMD6Branch *mergeBranch; // r11

  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
    mergeBranch->right = tree;
}


// ========================================================================
// ?InternalInit@idAnimator_Proxy@@UAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826EAE38
// RVA : 0x006EAE38
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

int __fastcall idAnimator_Proxy::InternalInit(idAnimator_Proxy *this, const idAnimatorParms_Base *parms)
{
  this->mergeBranch = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  return 1;
}


// ========================================================================
// ?InternalShutdown@idAnimator_Proxy@@UAAXPAVidAnimStack@@@Z
// EA  : 0x826EAE88
// RVA : 0x006EAE88
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

void __fastcall idAnimator_Proxy::InternalShutdown(idAnimator_Proxy *this, idAnimStack *animStack)
{
  if ( animStack != nullptr && this->mergeBranch != nullptr && animStack != (idAnimStack *)-8 )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))animStack->md6Allocator.Free)(a1: &animStack->md6Allocator);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?InternalIsContributing@idAnimator_Proxy@@UBA_NXZ
// EA  : 0x826EAEE8
// RVA : 0x006EAEE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_proxy.cpp
// ========================================================================

BOOL __fastcall idAnimator_Proxy::InternalIsContributing(idAnimator_Proxy *this)
{
  idMD6Branch *mergeBranch; // r11

  mergeBranch = this->mergeBranch;
  return mergeBranch != nullptr && mergeBranch->right != nullptr;
}

