
// ========================================================================
// ??0idRenderModelAugmentOutline@@QAA@XZ
// EA  : 0x827F6990
// RVA : 0x007F6990
// PDB : w:\tech5\engine\models\rendermodelaugment.cpp
// ========================================================================

idRenderModelAugmentOutline *__fastcall idRenderModelAugmentOutline::idRenderModelAugmentOutline(
        idRenderModelAugmentOutline *this)
{
  char v2; // r10
  __int64 v4; // [sp+8h] [-B8h]
  __int64 v5; // [sp+10h] [-B0h]
  __int64 v6; // [sp+18h] [-A8h]
  __int64 v7; // [sp+20h] [-A0h]
  __int64 v8; // [sp+28h] [-98h]
  __int64 v9; // [sp+30h] [-90h]
  __int64 v10; // [sp+38h] [-88h]
  __int64 v11; // [sp+40h] [-80h]
  __int64 v12; // [sp+48h] [-78h]
  __int64 v13; // [sp+50h] [-70h]
  __int64 v14; // [sp+70h] [-50h]
  __int64 v15; // [sp+90h] [-30h]

  idRenderModel::idRenderModel(this);
  v2 = *((_BYTE *)&this->g + 104);
  *((_BYTE *)&this->g + 105) |= 0x84u;
  this->__vftable = (idRenderModelAugmentOutline_vtbl *)&idRenderModelAugmentOutline::`vftable';
  *((_BYTE *)&this->g + 104) = v2 | 2;
  idRenderModel::FreeSurfaces(this);
  WORD2(v14) = 256;
  *(float *)&v15 = 0.0;
  *((float *)&v15 + 1) = 0.0;
  HIDWORD(v14) = tr.unitSquareModel->surfaces.list->geometry;
  idRenderModel::AddSurface(
    this: (idRenderModel *)mtrOutline.r,
    surf: nullptr,
    a3: v14,
    a4: 0,
    a5: v15,
    a6: v4,
    a7: v5,
    a8: v6,
    a9: v7,
    a10: v8,
    a11: v9,
    a12: v10,
    a13: v11,
    a14: v12,
    a15: v13);
  return this;
}


// ========================================================================
// __unwind$229068
// EA  : 0x827F6A6C
// RVA : 0x007F6A6C
// PDB : w:\tech5\engine\models\rendermodelaugment.cpp
// ========================================================================

void _unwind_229068()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 192 + 212));
}


// ========================================================================
// ?CommitSubclass@idRenderModelAugmentOutline@@EAA_NXZ
// EA  : 0x827F6A98
// RVA : 0x007F6A98
// PDB : w:\tech5\engine\models\rendermodelaugment.cpp
// ========================================================================

int __fastcall idRenderModelAugmentOutline::CommitSubclass(idRenderModelAugmentOutline *this)
{
  int v1; // r9
  int v2; // r11
  const idMaterial *customMaterial; // r10

  v1 = 0;
  if ( this->surfaces.num > 0 )
  {
    v2 = 0;
    do
    {
      customMaterial = this->g.customMaterial;
      if ( customMaterial != nullptr )
        this->surfaces.list[v2].material = customMaterial;
      ++v1;
      ++v2;
    }
    while ( v1 < this->surfaces.num );
  }
  return 0;
}


// ========================================================================
// `dynamic initializer for 'mtrOutline''
// EA  : 0x833437B8
// RVA : 0x013437B8
// PDB : w:\tech5\engine\models\rendermodelaugment.cpp
// ========================================================================

void _dynamic_initializer_for__mtrOutline__()
{
  mtrOutline.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrOutline;
}

