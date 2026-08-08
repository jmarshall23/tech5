
// ========================================================================
// ??1idWarningInfo@@QAA@XZ
// EA  : 0x82606180
// RVA : 0x00606180
// PDB : w:\tech5\shared\idlib\lib.h
// ========================================================================

void __fastcall idWarningInfo::~idWarningInfo(idWarningInfo *this)
{
  if ( this->pushed )
    idLib::PopWarningInfo();
}


// ========================================================================
// ??1idPrintListener@@UAA@XZ
// EA  : 0x82642928
// RVA : 0x00642928
// PDB : w:\tech5\shared\idlib\lib.h
// ========================================================================

void __fastcall idPrintListener::~idPrintListener(idCommonLocal::idRefreshOnPrint *this)
{
  this->__vftable = (idCommonLocal::idRefreshOnPrint_vtbl *)&idPrintListener::`vftable';
  idPrintListener::UnRegisterPrintListener(this);
}


// ========================================================================
// ??1idScopedDontTrack@@QAA@XZ
// EA  : 0x828C7238
// RVA : 0x008C7238
// PDB : w:\tech5\shared\idlib\lib.h
// ========================================================================

void __fastcall idScopedDontTrack::~idScopedDontTrack(idScopedDontTrack *this)
{
  idLib::dontTrack = this->oldDontTrack;
}

