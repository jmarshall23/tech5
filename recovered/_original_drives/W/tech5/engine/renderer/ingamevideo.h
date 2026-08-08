
// ========================================================================
// ?GetResourceList@idInGameVideoFile@@UBAPAVidResourceList@@XZ
// EA  : 0x828D17A0
// RVA : 0x008D17A0
// PDB : w:\tech5\engine\renderer\ingamevideo.h
// ========================================================================

idTypedResourceList<idInGameVideoFile> *__fastcall idInGameVideoFile::GetResourceList(idInGameVideoFile *this)
{
  return &idInGameVideoFile::resourceList;
}


// ========================================================================
// ??1idInGameVideoManager@@UAA@XZ
// EA  : 0x828D17B0
// RVA : 0x008D17B0
// PDB : w:\tech5\engine\renderer\ingamevideo.h
// ========================================================================

void __fastcall idInGameVideoManager::~idInGameVideoManager(idInGameVideoManager *this)
{
  this->__vftable = (idInGameVideoManager_vtbl *)&idInGameVideoManager::`vftable';
}

