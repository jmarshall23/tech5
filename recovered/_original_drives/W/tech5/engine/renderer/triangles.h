
// ========================================================================
// ?CreateBounds@idTriangles@@QAAXXZ
// EA  : 0x825D40C8
// RVA : 0x005D40C8
// PDB : w:\tech5\engine\renderer\triangles.h
// ========================================================================

void __fastcall idTriangles::CreateBounds(idTriangles *this)
{
  char v1; // [sp+50h] [-30h] BYREF

  this->bounds = *idTriangles::BoundsFromVertScan(this: (idTriangles *)&v1, result: &this->bounds);
}


// ========================================================================
// ??0idAutoStandardTriangles@@QAA@PBVidTriangles@@@Z
// EA  : 0x82844F80
// RVA : 0x00844F80
// PDB : w:\tech5\engine\renderer\triangles.h
// ========================================================================

idAutoStandardTriangles *__fastcall idAutoStandardTriangles::idAutoStandardTriangles(
        idAutoStandardTriangles *this,
        idTriangles *tri)
{
  bool v4; // r11
  const idTriangles *StandardTriangles; // r3
  bool v6; // r11

  v4 = tri->numIndexes == 0 || tri->vertexMask == 31 && tri->verts != nullptr && tri->indexes != nullptr;
  StandardTriangles = tri;
  if ( !v4 )
    StandardTriangles = idTriangles::CreateStandardTriangles(this: tri);
  this->standardTris = StandardTriangles;
  v6 = tri->numIndexes == 0 || tri->vertexMask == 31 && tri->verts != nullptr && tri->indexes != nullptr;
  this->freeOnDelete = (_cntlzw(v6) & 0x20) != 0;
  return this;
}


// ========================================================================
// ??1idAutoStandardTriangles@@QAA@XZ
// EA  : 0x82845238
// RVA : 0x00845238
// PDB : w:\tech5\engine\renderer\triangles.h
// ========================================================================

void __fastcall idAutoStandardTriangles::~idAutoStandardTriangles(idAutoStandardTriangles *this)
{
  idTriangles *standardTris; // r31

  if ( this->freeOnDelete )
  {
    standardTris = (idTriangles *)this->standardTris;
    if ( this->standardTris != nullptr )
    {
      idTriangles::~idTriangles(this: (idTriangles *)this->standardTris);
      idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
    }
  }
}

