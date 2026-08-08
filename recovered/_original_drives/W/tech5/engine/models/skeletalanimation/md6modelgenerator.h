
// ========================================================================
// ??0idMD6BinaryGenerator@@QAA@XZ
// EA  : 0x82845BF0
// RVA : 0x00845BF0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

idMD6BinaryGenerator *__fastcall idMD6BinaryGenerator::idMD6BinaryGenerator(idMD6BinaryGenerator *this)
{
  this->sourceFileName.len = 0;
  this->sourceFileName.data = this->sourceFileName.baseBuffer;
  this->sourceFileName.allocedAndFlag = 20;
  this->sourceFileName.baseBuffer[0] = 0;
  this->timestamp = 0;
  this->remapForSkinning = false;
  this->morphSkinName.allocedAndFlag = 20;
  this->morphSkinName.data = this->morphSkinName.baseBuffer;
  this->morphSkinName.len = 0;
  this->morphSkinName.baseBuffer[0] = 0;
  this->skeleton = nullptr;
  this->jointRemap.list = nullptr;
  this->jointRemap.granularity = 0;
  this->jointRemap.memTag = 5;
  this->jointRemap.listStatic = 0;
  this->jointRemap.size = 0;
  this->jointRemap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
  this->surfaces.list = nullptr;
  this->surfaces.granularity = 0;
  this->surfaces.memTag = 5;
  this->surfaces.listStatic = 0;
  this->surfaces.size = 0;
  this->surfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  this->sourceSurfaces.list = nullptr;
  this->sourceSurfaces.granularity = 0;
  this->sourceSurfaces.memTag = 5;
  this->sourceSurfaces.listStatic = 0;
  this->sourceSurfaces.size = 0;
  this->sourceSurfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  this->minBoundsExpansion.z = 0.0;
  this->minBoundsExpansion.y = 0.0;
  this->minBoundsExpansion.x = 0.0;
  this->maxBoundsExpansion.z = 0.0;
  this->maxBoundsExpansion.y = 0.0;
  this->maxBoundsExpansion.x = 0.0;
  this->defaultBounds.b[0].z = 1.0e30;
  this->defaultBounds.b[0].y = 1.0e30;
  this->defaultBounds.b[0].x = 1.0e30;
  this->defaultBounds.b[1].z = -1.0e30;
  this->defaultBounds.b[1].y = -1.0e30;
  this->defaultBounds.b[1].x = -1.0e30;
  return this;
}


// ========================================================================
// __unwind$228655
// EA  : 0x82845D20
// RVA : 0x00845D20
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_228655()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$228656
// EA  : 0x82845D48
// RVA : 0x00845D48
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_228656()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 92));
}


// ========================================================================
// __unwind$228657
// EA  : 0x82845D74
// RVA : 0x00845D74
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_228657()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 128));
}


// ========================================================================
// __unwind$228658
// EA  : 0x82845DA0
// RVA : 0x00845DA0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_228658()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}


// ========================================================================
// ??1idMD6BinaryGenerator@@QAA@XZ
// EA  : 0x82847050
// RVA : 0x00847050
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void __fastcall idMD6BinaryGenerator::~idMD6BinaryGenerator(idMD6BinaryGenerator *this)
{
  idList<idVehicleState *,5> *p_surfaces; // r29

  p_surfaces = (idList<idVehicleState *,5> *)&this->surfaces;
  idList<idProcessSurface *,5>::DeleteContents(this: &this->surfaces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sourceSurfaces);
  idList<idThread *,58>::Clear(this: p_surfaces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointRemap);
  idStr::FreeData(this: &this->morphSkinName);
  idStr::FreeData(this: &this->sourceFileName);
}


// ========================================================================
// __unwind$231017
// EA  : 0x828470A4
// RVA : 0x008470A4
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_231017()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$231018_0
// EA  : 0x828470CC
// RVA : 0x008470CC
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_231018_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 92));
}


// ========================================================================
// __unwind$231019
// EA  : 0x828470F8
// RVA : 0x008470F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_231019()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 128));
}


// ========================================================================
// __unwind$231020
// EA  : 0x82847124
// RVA : 0x00847124
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_231020()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 144));
}


// ========================================================================
// __unwind$231021
// EA  : 0x82847150
// RVA : 0x00847150
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_231021()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 160));
}


// ========================================================================
// ??0idProcessMesh@@QAA@XZ
// EA  : 0x8284B018
// RVA : 0x0084B018
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

idProcessMesh *__fastcall idProcessMesh::idProcessMesh(idProcessMesh *this)
{
  this->vertexes.list = nullptr;
  this->vertexes.granularity = 0;
  this->vertexes.memTag = 5;
  this->vertexes.listStatic = 0;
  this->vertexes.size = 0;
  this->vertexes.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->uvs.granularity = 0;
  this->uvs.memTag = 5;
  this->uvs.listStatic = 0;
  this->uvs.list = nullptr;
  this->uvs.size = 0;
  this->uvs.num = 0;
  this->indexes.list = nullptr;
  this->indexes.granularity = 0;
  this->indexes.memTag = 5;
  this->indexes.listStatic = 0;
  this->indexes.size = 0;
  this->indexes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexes);
  this->faceMaterialIndex.list = nullptr;
  this->faceMaterialIndex.granularity = 0;
  this->faceMaterialIndex.memTag = 5;
  this->faceMaterialIndex.listStatic = 0;
  this->faceMaterialIndex.size = 0;
  this->faceMaterialIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faceMaterialIndex);
  this->minJoint = 0;
  this->maxJoint = 255;
  this->hashST = 0;
  return this;
}


// ========================================================================
// __unwind$235679
// EA  : 0x8284B0D0
// RVA : 0x0084B0D0
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_235679()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$235680
// EA  : 0x8284B0F8
// RVA : 0x0084B0F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_235680()
{
  int v0; // r12

  idList<processST_t,5>::~idList<processST_t,5>(this: (idList<idChapterPart,5> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$235681
// EA  : 0x8284B124
// RVA : 0x0084B124
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_235681()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// ??0idProcessSurface@@QAA@XZ
// EA  : 0x8284B520
// RVA : 0x0084B520
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

idProcessSurface *__fastcall idProcessSurface::idProcessSurface(idProcessSurface *this)
{
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->material = nullptr;
  this->discrete = false;
  this->allowSkinRemapping = true;
  this->numTexCoordSets = 1;
  idProcessMesh::idProcessMesh(this: &this->mesh);
  return this;
}


// ========================================================================
// __unwind$236083
// EA  : 0x8284B594
// RVA : 0x0084B594
// PDB : w:\tech5\engine\models\skeletalanimation\md6modelgenerator.h
// ========================================================================

void _unwind_236083()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}

