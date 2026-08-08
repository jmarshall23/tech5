
// ========================================================================
// ?IsPersistent@idLocalUser@@UBA_NXZ
// EA  : 0x829BA6D8
// RVA : 0x009BA6D8
// PDB : w:\tech5\engine\sys\sys_localuser.h
// ========================================================================

BOOL __fastcall idLocalUser::IsPersistent(idLocalUser *this)
{
  return this->IsProfileReady(this);
}


// ========================================================================
// ?GetProfile@idLocalUser@@UAAPAVidPlayerProfile@@XZ
// EA  : 0x829BAA38
// RVA : 0x009BAA38
// PDB : w:\tech5\engine\sys\sys_localuser.h
// ========================================================================

idPlayerProfile *__fastcall idLocalUser::GetProfile(idLocalUser *this)
{
  return idProfileMgr::GetProfile(this: &this->profileMgr);
}

