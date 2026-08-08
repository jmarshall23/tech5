
// ========================================================================
// ??1idCoverActions@@UAA@XZ
// EA  : 0x829F0760
// RVA : 0x009F0760
// PDB : w:\tech5\tungsten\game\ai\cover\coveractions.h
// ========================================================================

void __fastcall idCoverActions::~idCoverActions(idCoverActions *this)
{
  this->__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
}


// ========================================================================
// ?Clear@idCoverActions@@UAAXXZ
// EA  : 0x829F0770
// RVA : 0x009F0770
// PDB : w:\tech5\tungsten\game\ai\cover\coveractions.h
// ========================================================================

void __fastcall idCoverActions::Clear(idCoverActions *this)
{
  *((_BYTE *)this + 4) &= 7u;
}


// ========================================================================
// ?Init@idCoverActions@@QAAXABUaas2Cover_t@@@Z
// EA  : 0x82A887C0
// RVA : 0x00A887C0
// PDB : w:\tech5\tungsten\game\ai\cover\coveractions.h
// ========================================================================

void __fastcall idCoverActions::Init(idCoverActions *this, const aas2Cover_t *cover)
{
  char v4; // r8
  char v5; // r5
  __int16 flags; // r7
  bool v7; // r8

  this->Clear(this);
  v4 = (4 * cover->flags) & 0x80 | *((_BYTE *)this + 4) & 0x7F;
  *((_BYTE *)this + 4) = v4;
  v5 = (((cover->flags & 0x140) != 0) << 6) & 0x40 | v4 & 0xBF;
  *((_BYTE *)this + 4) = v5;
  flags = cover->flags;
  *((_BYTE *)this + 4) = (32 * HIBYTE(flags)) & 0x20 | v5 & 0xDF;
  v7 = (cover->flags & 0x280) != 0;
  *((_BYTE *)this + 4) = (16 * v7) & 0x10 | (32 * HIBYTE(flags)) & 0x20 | v5 & 0xCF;
  *((_BYTE *)this + 4) = (8 * ((unsigned int)cover->flags >> 9)) & 8
                       | (16 * v7) & 0x10
                       | (32 * HIBYTE(flags)) & 0x20
                       | v5 & 0xC7;
}

