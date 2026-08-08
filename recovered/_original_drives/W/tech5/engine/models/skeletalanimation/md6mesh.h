
// ========================================================================
// ??0idMD6Mesh@@QAA@XZ
// EA  : 0x82844780
// RVA : 0x00844780
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

idMD6Mesh *__fastcall idMD6Mesh::idMD6Mesh(idMD6Mesh *this)
{
  idTriangles *v2; // r3
  idTriangles *v3; // r3

  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->material = nullptr;
  this->discrete = false;
  this->allowSkinRemapping = true;
  this->numTexCoordSets = 0;
  this->numVerts = 0;
  this->numTris = 0;
  this->jointOffset = 0;
  this->numJoints = 0;
  this->morphMap.list = nullptr;
  this->morphMap.granularity = 0;
  this->morphMap.memTag = 5;
  this->morphMap.listStatic = 0;
  this->morphMap.size = 0;
  this->morphMap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphMap);
  this->skinRemaps.list = nullptr;
  this->skinRemaps.granularity = 0;
  this->skinRemaps.memTag = 5;
  this->skinRemaps.listStatic = 0;
  this->skinRemaps.size = 0;
  this->skinRemaps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->skinRemaps);
  this->vertexes.list = nullptr;
  this->vertexes.granularity = 0;
  this->vertexes.memTag = 19;
  this->vertexes.listStatic = 0;
  this->vertexes.size = 0;
  this->vertexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexes);
  this->stSets.granularity = 0;
  this->stSets.memTag = 19;
  this->stSets.listStatic = 0;
  this->stSets.list = nullptr;
  this->stSets.size = 0;
  this->stSets.num = 0;
  this->indexes.list = nullptr;
  this->indexes.granularity = 0;
  this->indexes.memTag = 19;
  this->indexes.listStatic = 0;
  this->indexes.size = 0;
  this->indexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexes);
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  v2 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_MD6_MESHES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idTriangles::idTriangles(this: v2);
  else
    v3 = nullptr;
  this->tris = v3;
  return this;
}


// ========================================================================
// __unwind$225918
// EA  : 0x82844908
// RVA : 0x00844908
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225918()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$225919
// EA  : 0x82844930
// RVA : 0x00844930
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225919()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 88));
}


// ========================================================================
// __unwind$225920
// EA  : 0x8284495C
// RVA : 0x0084495C
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225920()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$225921
// EA  : 0x82844988
// RVA : 0x00844988
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225921()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 124));
}


// ========================================================================
// __unwind$225922
// EA  : 0x828449B4
// RVA : 0x008449B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225922()
{
  int v0; // r12

  idList<idDeclAnimWeb::idLayerInfo,32>::Clear(this: (idList<idDeclAnimWeb::idLayerInfo,32> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 140));
}


// ========================================================================
// __unwind$225923
// EA  : 0x828449E0
// RVA : 0x008449E0
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225923()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 156));
}


// ========================================================================
// __unwind$225924
// EA  : 0x82844A0C
// RVA : 0x00844A0C
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_225924()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_MD6_MESHES);
}


// ========================================================================
// ??1idMD6Mesh@@QAA@XZ
// EA  : 0x82846D10
// RVA : 0x00846D10
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void __fastcall idMD6Mesh::~idMD6Mesh(idMD6Mesh *this)
{
  idMD6Mesh::stset_t *list; // r3

  idMD6Mesh::Free(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexes);
  if ( this->stSets.listStatic == 0 || this->stSets.listStatic == 2 )
  {
    list = this->stSets.list;
    if ( list != nullptr )
      idListArrayDelete<idMD6Mesh::stset_t>(ptr: (char *)list, num: this->stSets.size);
    this->stSets.list = nullptr;
    this->stSets.size = 0;
  }
  this->stSets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexes);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->skinRemaps);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphMap);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$230802
// EA  : 0x82846D94
// RVA : 0x00846D94
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230802()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$230803
// EA  : 0x82846DBC
// RVA : 0x00846DBC
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// __unwind$230804
// EA  : 0x82846DE8
// RVA : 0x00846DE8
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230804()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$230805
// EA  : 0x82846E14
// RVA : 0x00846E14
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 124));
}


// ========================================================================
// __unwind$230806
// EA  : 0x82846E40
// RVA : 0x00846E40
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230806()
{
  int v0; // r12

  idList<idDeclAnimWeb::idLayerInfo,32>::Clear(this: (idList<idDeclAnimWeb::idLayerInfo,32> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 140));
}


// ========================================================================
// __unwind$230807
// EA  : 0x82846E6C
// RVA : 0x00846E6C
// PDB : w:\tech5\engine\models\skeletalanimation\md6mesh.h
// ========================================================================

void _unwind_230807()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 156));
}

