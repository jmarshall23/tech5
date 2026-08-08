
// ========================================================================
// ?Clear@idCoverCapabilities@@UAAXXZ
// EA  : 0x82A3EFE0
// RVA : 0x00A3EFE0
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

void __fastcall idCoverCapabilities::Clear(idCoverCapabilities *this)
{
  char v1; // r10

  v1 = *((_BYTE *)this + 8);
  *((_BYTE *)&this->idCoverActions + 4) &= 7u;
  *((_BYTE *)this + 8) = v1 & 1;
}


// ========================================================================
// ?HasCapability@idCoverCapabilities@@UBA_NABV1@@Z
// EA  : 0x82A3F000
// RVA : 0x00A3F000
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

BOOL __fastcall idCoverCapabilities::HasCapability(idCoverCapabilities *this, const idCoverCapabilities *other)
{
  return (*((_BYTE *)&other->idCoverActions + 4) & 0x40) != 0 && (*((_BYTE *)&this->idCoverActions + 4) & 0x40) != 0
      || (*((_BYTE *)&other->idCoverActions + 4) & 0x10) != 0 && (*((_BYTE *)&this->idCoverActions + 4) & 0x10) != 0
      || (*((_BYTE *)&other->idCoverActions + 4) & 0x80) != 0 && (*((_BYTE *)&this->idCoverActions + 4) & 0x80) != 0
      || (*((_BYTE *)&other->idCoverActions + 4) & 0x20) != 0 && (*((_BYTE *)&this->idCoverActions + 4) & 0x20) != 0
      || (*((_BYTE *)&other->idCoverActions + 4) & 8) != 0 && (*((_BYTE *)&this->idCoverActions + 4) & 8) != 0
      || (*((_BYTE *)other + 8) & 0x80) != 0 && (*((_BYTE *)this + 8) & 0x80) != 0
      || (*((_BYTE *)other + 8) & 0x40) != 0 && (*((_BYTE *)this + 8) & 0x40) != 0
      || (*((_BYTE *)other + 8) & 0x20) != 0 && (*((_BYTE *)this + 8) & 0x20) != 0
      || (*((_BYTE *)other + 8) & 0x10) != 0 && (*((_BYTE *)this + 8) & 0x10) != 0
      || (*((_BYTE *)other + 8) & 8) != 0 && (*((_BYTE *)this + 8) & 8) != 0
      || (*((_BYTE *)other + 8) & 4) != 0 && (*((_BYTE *)this + 8) & 4) != 0
      || (*((_BYTE *)other + 8) & 2) != 0 && (*((_BYTE *)this + 8) & 2) != 0;
}


// ========================================================================
// ?NumMatchingCapabilities@idCoverCapabilities@@QBAHABV1@@Z
// EA  : 0x82A3F170
// RVA : 0x00A3F170
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

int __fastcall idCoverCapabilities::NumMatchingCapabilities(
        idCoverCapabilities *this,
        const idCoverCapabilities *other)
{
  unsigned __int8 v2; // r8
  unsigned __int8 v3; // r9
  int v4; // r7
  int v5; // r5

  v2 = *((_BYTE *)&this->idCoverActions + 4);
  v3 = *((_BYTE *)&other->idCoverActions + 4);
  v4 = *((unsigned __int8 *)other + 8);
  v5 = *((unsigned __int8 *)this + 8);
  return ((~(v2 ^ v3) & 0x40) != 0)
       + ((~(v2 ^ v3) & 0x20) != 0)
       + ((~(v2 ^ v3) & 0x10) != 0)
       + ((~(v2 ^ v3) & 8) != 0)
       + ((~((unsigned __int8)v5 ^ (unsigned __int8)v4) & 0x40) != 0)
       + ((~((unsigned __int8)v5 ^ (unsigned __int8)v4) & 0x20) != 0)
       + ((~((unsigned __int8)v5 ^ (unsigned __int8)v4) & 0x10) != 0)
       + ((~((unsigned __int8)v5 ^ (unsigned __int8)v4) & 8) != 0)
       + ((~((unsigned __int8)v5 ^ (unsigned __int8)v4) & 4) != 0)
       + ((~(v5 ^ v4) & 2) != 0)
       + ((_cntlzw((v2 ^ v3) & 0x80) & 0x20) != 0)
       + ((_cntlzw((v5 ^ v4) & 0x80) & 0x20) != 0);
}


// ========================================================================
// ?Promote@idCoverCapabilities@@QAAXABVidCoverActions@@@Z
// EA  : 0x82A3F3A0
// RVA : 0x00A3F3A0
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

void __fastcall idCoverCapabilities::Promote(idCoverCapabilities *this, const idCoverActions *actions)
{
  char v2; // r8
  char v3; // r6
  char v4; // r9
  char v5; // r5
  char v6; // r9
  char v7; // r11
  char v8; // r7
  char v9; // r7
  char v10; // t0

  v2 = *((_BYTE *)this + 8);
  v3 = *((_BYTE *)actions + 4) & 0x80 | *((_BYTE *)&this->idCoverActions + 4) & 0x7F;
  *((_BYTE *)&this->idCoverActions + 4) = v3;
  v4 = *((_BYTE *)actions + 4) & 0x40 | v3 & 0xBF;
  *((_BYTE *)&this->idCoverActions + 4) = v4;
  v5 = *((_BYTE *)actions + 4) & 0x20 | v4 & 0xDF;
  *((_BYTE *)&this->idCoverActions + 4) = v5;
  v6 = *((_BYTE *)actions + 4) & 0x10 | v5 & 0xEF;
  *((_BYTE *)&this->idCoverActions + 4) = v6;
  *((_BYTE *)&this->idCoverActions + 4) = *((_BYTE *)actions + 4) & 8 | v6 & 0xF7;
  *((_BYTE *)this + 8) = (2 * *((_BYTE *)actions + 4)) & 0x80 | v2 & 0x7F;
  v7 = (4 * *((_BYTE *)actions + 4)) & 0x40 | *((_BYTE *)this + 8) & 0xBF;
  *((_BYTE *)this + 8) = v7;
  v8 = (*((_BYTE *)actions + 4) >> 2) & 0x20 | v7 & 0xDF;
  *((_BYTE *)this + 8) = v8;
  v9 = (*((_BYTE *)actions + 4) >> 2) & 0x10 | v8 & 0xEF;
  *((_BYTE *)this + 8) = v9;
  v10 = __ROR4__(*((unsigned __int8 *)actions + 4), 1);
  *((_BYTE *)this + 8) = v10 & 8 | v9 & 0xF7;
  *((_BYTE *)this + 8) = (*((_BYTE *)actions + 4) >> 5) & 4 | 2 | v10 & 8 | v9 & 0xF3;
}


// ========================================================================
// ?HasCapability@idCoverCapabilities@@UBA_NABVidCoverActions@@@Z
// EA  : 0x82A3F480
// RVA : 0x00A3F480
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

BOOL __fastcall idCoverCapabilities::HasCapability(idCoverCapabilities *this, const idCoverActions *other)
{
  idCoverCapabilities v4[2]; // [sp+50h] [-30h] BYREF

  *((_BYTE *)&v4[0].idCoverActions + 4) &= 7u;
  v4[0].__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
  *((_BYTE *)v4 + 8) &= 1u;
  idCoverCapabilities::Promote(this: v4, actions: other);
  return this->HasCapability(this, a2: v4);
}


// ========================================================================
// __unwind$487380
// EA  : 0x82A3F4F8
// RVA : 0x00A3F4F8
// PDB : w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// ========================================================================

void _unwind_487380()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 128 + 80));
}

