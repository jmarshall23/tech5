
// ========================================================================
// ??0vertSet@idMorphVertices@@QAA@XZ
// EA  : 0x82591EF8
// RVA : 0x00591EF8
// PDB : w:\tech5\engine\models\morphskingen.h
// ========================================================================

idMorphVertices::vertSet *__fastcall idMorphVertices::vertSet::vertSet(idMorphVertices::vertSet *this)
{
  int v2; // ctr
  float *p_y; // r11
  float *p_z; // r10

  this->meshNum = -1;
  this->jointGroupIndex = -1;
  this->flags = 0;
  this->pos = vec3_origin;
  v2 = 9;
  p_y = &mat2_identity.mat[1].y;
  p_z = &this->size.z;
  this->size = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->vertices.list = nullptr;
  this->vertices.granularity = 0;
  this->vertices.memTag = 115;
  this->vertices.listStatic = 0;
  this->vertices.size = 0;
  this->vertices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  this->morphDirection.list = nullptr;
  this->morphDirection.granularity = 0;
  this->morphDirection.memTag = 115;
  this->morphDirection.listStatic = 0;
  this->morphDirection.size = 0;
  this->morphDirection.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphDirection);
  return this;
}


// ========================================================================
// __unwind$688069
// EA  : 0x82591FD8
// RVA : 0x00591FD8
// PDB : w:\tech5\engine\models\morphskingen.h
// ========================================================================

void _unwind_688069()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 72));
}


// ========================================================================
// ?GetResourceList@idMorphVertices@@UBAPAVidResourceList@@XZ
// EA  : 0x827DC0E8
// RVA : 0x007DC0E8
// PDB : w:\tech5\engine\models\morphskingen.h
// ========================================================================

idTypedResourceList<idMorphVertices> *__fastcall idMorphVertices::GetResourceList(idMorphVertices *this)
{
  return &idMorphVertices::resourceList;
}

