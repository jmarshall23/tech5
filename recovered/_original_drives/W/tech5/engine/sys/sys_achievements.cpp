
// ========================================================================
// ?SyncAchievementBits@idAchievementSystem@@QAAXPAVidLocalUser@@@Z
// EA  : 0x829A2238
// RVA : 0x009A2238
// PDB : w:\tech5\engine\sys\sys_achievements.cpp
// ========================================================================

void __fastcall idAchievementSystem::SyncAchievementBits(idAchievementSystem *this, idLocalUser *user)
{
  int i; // r31
  idPlayerProfile *v4; // r3
  __int64 v5; // r10
  unsigned __int64 v6; // r8
  int v7; // r5
  _BYTE v8[136]; // [sp+50h] [-A0h] BYREF

  if ( user != nullptr && this->GetAchievementState(this, a2: user, a3: (idArray<bool,128> *)v8) )
  {
    for ( i = 0; i < 128; ++i )
    {
      if ( v8[i] != 0 )
      {
        v4 = user->GetProfile(this: user);
        idPlayerProfile::SetAchievement(this: v4, id: i, a3: v7, a4: v6, a5: v5);
      }
    }
  }
}

