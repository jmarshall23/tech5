
// ========================================================================
// ??0idStaticModelSurface@@QAA@XZ
// EA  : 0x82591E58
// RVA : 0x00591E58
// PDB : w:\tech5\engine\models\static\staticmodel.h
// ========================================================================

idStaticModelSurface *__fastcall idStaticModelSurface::idStaticModelSurface(idStaticModelSurface *this)
{
  unsigned __int64 v2; // r11

  HIDWORD(v2) = 0x82000000;
  LODWORD(v2) = 0;
  this->material = nullptr;
  this->materialNum = 0;
  this->extraGLState = v2;
  this->geometry = nullptr;
  this->geometryIsReference = false;
  this->referenceMask = 0;
  this->binaryModelId = 0;
  this->joints = nullptr;
  this->morphMap = nullptr;
  this->stMap = nullptr;
  this->skinOffsets.x = 0.0;
  this->skinOffsets.y = 0.0;
  this->skinOffsets.z = 0.0;
  this->skinOffsets.w = 0.0;
  this->skinRemaps.list = nullptr;
  this->skinRemaps.granularity = 0;
  this->skinRemaps.memTag = 5;
  this->skinRemaps.listStatic = 0;
  this->skinRemaps.size = 0;
  this->skinRemaps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->skinRemaps);
  return this;
}


// ========================================================================
// ?GetResourceList@idStaticModel@@UBAPAVidResourceList@@XZ
// EA  : 0x82869AC0
// RVA : 0x00869AC0
// PDB : w:\tech5\engine\models\static\staticmodel.h
// ========================================================================

idTypedResourceList<idStaticModel> *__fastcall idStaticModel::GetResourceList(idStaticModel *this)
{
  return &idStaticModel::resourceList;
}

