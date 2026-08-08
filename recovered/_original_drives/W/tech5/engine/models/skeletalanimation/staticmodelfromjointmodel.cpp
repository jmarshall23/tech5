
// ========================================================================
// ?DrawVertToString@@YA?AVidStr@@ABVidDrawVert@@@Z
// EA  : 0x8285A5B8
// RVA : 0x0085A5B8
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

idStr *__fastcall DrawVertToString(idStr *result, const idDrawVert *v)
{
  int v4; // [sp+8h] [-128h]
  int v5; // [sp+Ch] [-124h]
  int v6; // [sp+10h] [-120h]
  int v7; // [sp+14h] [-11Ch]
  int v8; // [sp+18h] [-118h]
  int v9; // [sp+1Ch] [-114h]

  result->data = result->baseBuffer;
  result->allocedAndFlag = 20;
  result->len = 0;
  result->baseBuffer[0] = 0;
  idStr::Format(
    this: result,
    fmt: "XYZ:(%f %f %f) ST:(%f %f) color:(%i %i %i %i) normal:(%i %i %i %i) tangent:(%i %i %i %i)",
    v->xyz.x,
    v->xyz.y,
    v->xyz.z,
    v->st.x,
    v->st.y,
    (unsigned int)COERCE_UNSIGNED_INT64(v->xyz.x),
    (unsigned int)COERCE_UNSIGNED_INT64(v->xyz.y),
    (unsigned int)COERCE_UNSIGNED_INT64(v->xyz.z),
    (unsigned int)COERCE_UNSIGNED_INT64(v->st.x),
    (unsigned int)COERCE_UNSIGNED_INT64(v->st.y),
    v->color[0],
    v4,
    v5,
    v6,
    v7,
    v8,
    v9);
  return result;
}


// ========================================================================
// __unwind$221285
// EA  : 0x8285A6AC
// RVA : 0x0085A6AC
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void _unwind_221285()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 304;
  if ( (*(_DWORD *)(v0 - 304 + 176) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 176) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 324));
  }
}


// ========================================================================
// ?PrintTriangles@@YAXQBVidTriangles@@@Z
// EA  : 0x8285A6F8
// RVA : 0x0085A6F8
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void __fastcall PrintTriangles(idTriangles *tri_)
{
  idTriangles *standardTris; // r28
  int v2; // r30
  int v3; // r29
  idStr *v4; // r3
  int v5; // r29
  int v6; // r30
  idAutoStandardTriangles v7; // [sp+50h] [-70h] BYREF
  idStr v8[3]; // [sp+60h] [-60h] BYREF

  if ( tri_ != nullptr )
  {
    idAutoStandardTriangles::idAutoStandardTriangles(this: &v7, tri: tri_);
    standardTris = (idTriangles *)v7.standardTris;
    v2 = 0;
    if ( v7.standardTris->numVerts > 0 )
    {
      v3 = 0;
      do
      {
        v4 = DrawVertToString(result: v8, v: &standardTris->verts[v3]);
        idLib::Printf(fmt: "%5i: %s\n", v2, v4->data);
        idStr::FreeData(this: v8);
        ++v2;
        ++v3;
      }
      while ( v2 < standardTris->numVerts );
    }
    v5 = 0;
    if ( standardTris->numIndexes > 0 )
    {
      v6 = 0;
      do
      {
        idLib::Printf(
          fmt: "%5i: (%i %i %i)\n",
          v5 / 3,
          standardTris->indexes[v6],
          standardTris->indexes[v6 + 1],
          standardTris->indexes[v6 + 2]);
        v5 += 3;
        v6 += 3;
      }
      while ( v5 < standardTris->numIndexes );
    }
    if ( v7.freeOnDelete )
    {
      idTriangles::~idTriangles(this: standardTris);
      idMem::Free(this: &mem, ptr: standardTris, align: ALIGN_16);
    }
  }
  else
  {
    idLib::Printf(fmt: "<NULL>\n");
  }
}


// ========================================================================
// __unwind$221374
// EA  : 0x8285A810
// RVA : 0x0085A810
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void _unwind_221374()
{
  int v0; // r12

  idAutoStandardTriangles::~idAutoStandardTriangles(this: (idAutoStandardTriangles *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$221375
// EA  : 0x8285A838
// RVA : 0x0085A838
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void _unwind_221375()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?PrintDetailed@idMD6Model@@QBAXXZ
// EA  : 0x8285A860
// RVA : 0x0085A860
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void __fastcall idMD6Model::PrintDetailed(idMD6Model *this)
{
  int v2; // r30
  int v3; // r31

  idLib::Printf(fmt: "----------------------------- %s ----------------------------\n", this->name.str);
  idLib::Printf(fmt: "    verts tris  material\n");
  v2 = 0;
  if ( this->meshes.num > 0 )
  {
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "----- mesh %i : %s -----\n", v2, this->meshes.list[v3]->material->name.str);
      PrintTriangles(tri_: this->meshes.list[v3]->tris);
      ++v2;
      ++v3;
    }
    while ( v2 < this->meshes.num );
  }
}


// ========================================================================
// ?compareAnims_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8285A8F0
// RVA : 0x0085A8F0
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

void __fastcall compareAnims_f(const idCmdArgs *args)
{
  idMD6Model *v1; // r30
  idMD6Model *v2; // r31

  v1 = (idMD6Model *)idResourceList::Load(
                       this: &idMD6Model::resourceList,
                       name: "maps/user/johnc/megaanim/_combo/megamodel_func_animated_1.bmd6model",
                       makeDefault: true,
                       skipStaleCheck: false);
  v2 = (idMD6Model *)idResourceList::Load(
                       this: &idMD6Model::resourceList,
                       name: "md6/map_objects/creatures/vulture/mesh/vulture.md6mesh",
                       makeDefault: true,
                       skipStaleCheck: false);
  idMD6Model::PrintDetailed(this: v2);
  idMD6Model::PrintDetailed(this: v1);
  v2->Print(this: v2);
  v1->Print(this: v1);
}


// ========================================================================
// `dynamic initializer for 'compareAnims_v''
// EA  : 0x83344538
// RVA : 0x01344538
// PDB : w:\tech5\engine\models\skeletalanimation\staticmodelfromjointmodel.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__compareAnims_v__()
{
  return idCommandLink::idCommandLink(
           this: &compareAnims_v,
           cmdName: "compareAnims",
           function: compareAnims_f,
           description: "test code",
           argCompletion: nullptr);
}

