
// ========================================================================
// ??0idSWFShapeParser@@QAA@XZ
// EA  : 0x82791188
// RVA : 0x00791188
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.h
// ========================================================================

idSWFShapeParser *__fastcall idSWFShapeParser::idSWFShapeParser(idSWFShapeParser *this)
{
  this->verts.list = nullptr;
  this->verts.granularity = 0;
  this->verts.memTag = 72;
  this->verts.listStatic = 0;
  this->verts.size = 0;
  this->verts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->verts);
  this->fillDraws.granularity = 0;
  this->fillDraws.memTag = 72;
  this->fillDraws.listStatic = 0;
  this->fillDraws.list = nullptr;
  this->fillDraws.size = 0;
  this->fillDraws.num = 0;
  this->lineDraws.granularity = 0;
  this->lineDraws.memTag = 72;
  this->lineDraws.listStatic = 0;
  this->lineDraws.list = nullptr;
  this->lineDraws.size = 0;
  this->lineDraws.num = 0;
  return this;
}


// ========================================================================
// __unwind$219805
// EA  : 0x82791210
// RVA : 0x00791210
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.h
// ========================================================================

void _unwind_219805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$219806
// EA  : 0x8279123C
// RVA : 0x0079123C
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.h
// ========================================================================

void _unwind_219806()
{
  int v0; // r12

  idList<idSWFShapeParser::swfSPDrawFill_t,72>::Clear(this: (idList<idSWFShapeParser::swfSPDrawFill_t,72> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}

