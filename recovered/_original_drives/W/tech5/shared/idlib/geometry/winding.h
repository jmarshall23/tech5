
// ========================================================================
// ??1idWinding@@UAA@XZ
// EA  : 0x825AEAA0
// RVA : 0x005AEAA0
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall idWinding::~idWinding(idWinding *this)
{
  idVec5 *p; // r4

  p = this->p;
  this->__vftable = (idWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  this->p = nullptr;
}


// ========================================================================
// ?Clear@idWinding@@UAAXXZ
// EA  : 0x825AEAF0
// RVA : 0x005AEAF0
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall idWinding::Clear(idWinding *this)
{
  idVec5 *p; // r4

  p = this->p;
  this->numPoints = 0;
  this->allocedSize = 0;
  idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  this->p = nullptr;
}


// ========================================================================
// ?AddPoint@idWinding@@QAAXABVidVec3@@@Z
// EA  : 0x825AEC20
// RVA : 0x005AEC20
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall idWinding::AddPoint(idWinding *this, const idVec3 *v)
{
  char v4; // r3
  idVec5 *v5; // r11

  if ( this->numPoints + 1 <= this->allocedSize )
    v4 = 1;
  else
    v4 = ((int (__fastcall *)(idWinding *))this->ReAllocate)(a1: this);
  if ( v4 != 0 )
  {
    v5 = &this->p[this->numPoints];
    v5->x = v->x;
    v5->y = v->y;
    v5->z = v->z;
    v5->t = 0.0;
    v5->s = 0.0;
    ++this->numPoints;
  }
}


// ========================================================================
// ?AddPoint@idWinding@@QAAXABVidVec5@@@Z
// EA  : 0x825C0F28
// RVA : 0x005C0F28
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall idWinding::AddPoint(idWinding *this, const idVec5 *v)
{
  char v4; // r3
  _DWORD *p_t; // r7
  int v6; // ctr
  float *v7; // r11

  if ( this->numPoints + 1 <= this->allocedSize )
    v4 = 1;
  else
    v4 = ((int (__fastcall *)(idWinding *))this->ReAllocate)(a1: this);
  if ( v4 != 0 )
  {
    p_t = (_DWORD *)&v[-1].t;
    v6 = 5;
    v7 = &this->p[this->numPoints - 1].t;
    do
    {
      *++v7 = *(float *)++p_t;
      --v6;
    }
    while ( v6 != 0 );
    ++this->numPoints;
  }
}


// ========================================================================
// ??0idFixedWinding@@QAA@XZ
// EA  : 0x825C39A8
// RVA : 0x005C39A8
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

idFixedWinding *__fastcall idFixedWinding::idFixedWinding(idFixedWinding *this)
{
  this->p = this->data;
  this->__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  this->numPoints = 0;
  this->allocedSize = 64;
  return this;
}


// ========================================================================
// ??1idFixedWinding@@UAA@XZ
// EA  : 0x825C39D0
// RVA : 0x005C39D0
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall idFixedWinding::~idFixedWinding(idFixedWinding *this)
{
  this->p = nullptr;
  this->__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  this->p = nullptr;
}


// ========================================================================
// ?_jxr_rbitstream_syncbyte@@YAXPAUrbitstream@@@Z
// EA  : 0x825C3A30
// RVA : 0x005C3A30
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

void __fastcall _jxr_rbitstream_syncbyte(bfx::DynKDNode *pLeafNode)
{
  pLeafNode->m_pLeft = nullptr;
}


// ========================================================================
// ??4idWinding@@QAAAAV0@ABV0@@Z
// EA  : 0x825C7390
// RVA : 0x005C7390
// PDB : w:\tech5\shared\idlib\geometry\winding.h
// ========================================================================

idWinding *__fastcall idWinding::operator=(idWinding *this, const idWinding *winding)
{
  char v4; // r3
  int numPoints; // r10
  int v6; // r7
  int v7; // r11
  float *p_t; // r8
  float *v9; // r9
  int i; // ctr

  if ( winding->numPoints <= this->allocedSize )
    v4 = 1;
  else
    v4 = ((int (__fastcall *)(idWinding *))this->ReAllocate)(a1: this);
  if ( v4 != 0 )
  {
    numPoints = winding->numPoints;
    v6 = 0;
    if ( numPoints > 0 )
    {
      v7 = 0;
      do
      {
        p_t = &winding->p[v7 - 1].t;
        v9 = &this->p[v7 - 1].t;
        for ( i = 5; i != 0; --i )
          *++v9 = *++p_t;
        numPoints = winding->numPoints;
        ++v6;
        ++v7;
      }
      while ( v6 < numPoints );
    }
    this->numPoints = numPoints;
  }
  else
  {
    this->numPoints = 0;
  }
  return this;
}

