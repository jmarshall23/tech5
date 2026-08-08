
// ========================================================================
// ??1idRenderModelInfo@@QAA@XZ
// EA  : 0x82C43410
// RVA : 0x00C43410
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.h
// ========================================================================

void __fastcall idRenderModelInfo::~idRenderModelInfo(idRenderModelInfo *this)
{
  char *list; // r3

  idRenderModelInfo::FreeRenderModel(this);
  idStr::FreeData(this: &this->editorModel);
  if ( this->renderParms.listStatic == 0 || this->renderParms.listStatic == 2 )
  {
    list = (char *)this->renderParms.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnRenderParm>(ptr: list, num: this->renderParms.size);
    this->renderParms.list = nullptr;
    this->renderParms.size = 0;
  }
  this->renderParms.num = 0;
}


// ========================================================================
// __unwind$507534
// EA  : 0x82C43494
// RVA : 0x00C43494
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.h
// ========================================================================

void _unwind_507534()
{
  int v0; // r12

  idList<idSpawnRenderParm,5>::Clear(this: (idList<idRenderParm,5> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$507535
// EA  : 0x82C434C0
// RVA : 0x00C434C0
// PDB : w:\tech5\tungsten\game\components\rendermodelcomponent.h
// ========================================================================

void _unwind_507535()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 76));
}

