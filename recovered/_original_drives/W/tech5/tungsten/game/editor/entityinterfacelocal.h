
// ========================================================================
// ?GetEyePosition@idEntityInterfaceLocal@@UBAXAAVidVec3@@@Z
// EA  : 0x82BD81A0
// RVA : 0x00BD81A0
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.h
// ========================================================================

void __fastcall idEntityInterfaceLocal::GetEyePosition(idEntityInterfaceLocal *this, idVec3 *eyePos)
{
  eyePos->x = 0.0;
  eyePos->y = 0.0;
  eyePos->z = 0.0;
}


// ========================================================================
// ?AddReference@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BD81B8
// RVA : 0x00BD81B8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.h
// ========================================================================

void __fastcall idEntityInterfaceLocal::AddReference(idEntityInterfaceLocal *this)
{
  ++this->refCount;
}


// ========================================================================
// ?RemoveReference@idEntityInterfaceLocal@@UAAXXZ
// EA  : 0x82BD81C8
// RVA : 0x00BD81C8
// PDB : w:\tech5\tungsten\game\editor\entityinterfacelocal.h
// ========================================================================

void __fastcall idEntityInterfaceLocal::RemoveReference(idEntityInterfaceLocal *this)
{
  --this->refCount;
}

