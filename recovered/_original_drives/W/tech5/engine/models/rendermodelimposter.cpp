
// ========================================================================
// ??0idRenderModelImposter@@QAA@XZ
// EA  : 0x82801A00
// RVA : 0x00801A00
// PDB : w:\tech5\engine\models\rendermodelimposter.cpp
// ========================================================================

idRenderModelImposter *__fastcall idRenderModelImposter::idRenderModelImposter(idRenderModelImposter *this)
{
  idRenderModel::idRenderModel(this);
  this->parent = nullptr;
  this->__vftable = (idRenderModelImposter_vtbl *)&idRenderModelImposter::`vftable';
  return this;
}


// ========================================================================
// ?UpdateInView@idRenderModelImposter@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x82801AB0
// RVA : 0x00801AB0
// PDB : w:\tech5\engine\models\rendermodelimposter.cpp
// ========================================================================

int __fastcall idRenderModelImposter::UpdateInView(
        idRenderModelImposter *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int v5; // r8
  int v6; // r9
  idRenderModelSurface *v7; // r11
  idRenderModelSurface *v8; // r10

  if ( this->parent == nullptr )
    return 0;
  v5 = 0;
  if ( this->surfaces.num > 0 )
  {
    v6 = 0;
    do
    {
      ++v5;
      v7 = &this->surfaces.list[v6];
      v8 = &this->parent->surfaces.list[v6++];
      v7->geometry = v8->geometry;
      v7->material = v8->material;
      v7->materialNum = v8->materialNum;
      v7->joints = v8->joints;
      v7->morphMap = v8->morphMap;
      v7->skinOffsets.x = v8->skinOffsets.x;
      v7->skinOffsets.y = v8->skinOffsets.y;
      v7->skinOffsets.z = v8->skinOffsets.z;
      v7->skinOffsets.w = v8->skinOffsets.w;
      v7->extraGLState = v8->extraGLState;
    }
    while ( v5 < this->surfaces.num );
  }
  idRenderModel::CommitSurfaces(this);
  return 1;
}


// ========================================================================
// ?MimicRenderModel@idRenderModelImposter@@QAAXPAVidRenderModel@@@Z
// EA  : 0x82801B80
// RVA : 0x00801B80
// PDB : w:\tech5\engine\models\rendermodelimposter.cpp
// ========================================================================

void __fastcall idRenderModelImposter::MimicRenderModel(idRenderModelImposter *this, idRenderModel *parentModel)
{
  int v4; // r31
  int v5; // r30
  idRenderModelSurface *v6; // r11
  __int64 v7; // r6
  __int64 v8; // [sp+8h] [-C8h]
  __int64 v9; // [sp+10h] [-C0h]
  __int64 v10; // [sp+18h] [-B8h]
  __int64 v11; // [sp+20h] [-B0h]
  __int64 v12; // [sp+28h] [-A8h]
  __int64 v13; // [sp+30h] [-A0h]
  __int64 v14; // [sp+38h] [-98h]
  __int64 v15; // [sp+40h] [-90h]
  __int64 v16; // [sp+48h] [-88h]
  __int64 v17; // [sp+50h] [-80h]
  __int64 v18; // [sp+80h] [-50h]
  __int64 v19; // [sp+90h] [-40h]

  this->FreeSurfaces(this);
  v4 = 0;
  if ( parentModel->surfaces.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &parentModel->surfaces.list[v5];
      LODWORD(v18) = 0;
      *(float *)&v19 = v6->skinOffsets.z;
      *((float *)&v19 + 1) = v6->skinOffsets.w;
      HIDWORD(v18) = v6->morphMap;
      HIDWORD(v7) = v6->geometry;
      LODWORD(v7) = 0;
      idRenderModel::AddSurface(
        this: (idRenderModel *)v6->material,
        surf: (idRenderModelSurface *)v6->materialNum,
        a3: v7,
        a4: v18,
        a5: v19,
        a6: v8,
        a7: v9,
        a8: v10,
        a9: v11,
        a10: v12,
        a11: v13,
        a12: v14,
        a13: v15,
        a14: v16,
        a15: v17);
      ++v4;
      ++v5;
    }
    while ( v4 < parentModel->surfaces.num );
  }
  idRenderModel::FinishSurfaces(this);
  this->parent = parentModel;
}

