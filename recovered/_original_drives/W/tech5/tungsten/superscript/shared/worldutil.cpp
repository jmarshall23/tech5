
// ========================================================================
// ?Init@ssWorldUtil@@UAAXXZ
// EA  : 0x82EECD50
// RVA : 0x00EECD50
// PDB : w:\tech5\tungsten\superscript\shared\worldutil.cpp
// ========================================================================

void __fastcall ssWorldUtil::Init(ssWorldUtil *this)
{
  const ssEntity *v2; // r3
  const ssEntity *v3; // r3
  const ssEntity *v4; // r3
  const ssEntity *v5; // r3
  const ssEntity *v6; // r3
  const ssEntity *v7; // r3
  const ssEntity *v8; // r3
  const ssEntity *v9; // r3
  const ssEntity *v10; // r3
  ssEntity v11[4]; // [sp+50h] [-40h] BYREF
  ssString v12[3]; // [sp+60h] [-30h] BYREF

  if ( this->self.spawnId == ssEntity::ssEntity(this: v11, name: "world")->spawnId )
  {
    v2 = ssEntity::ssEntity(this: v11, name: "world");
    ssEntity::ssEntity(this: &this->world, e: v2);
    v3 = ssEntity::ssEntity(this: v11, name: "player1");
    ssEntity::ssEntity(this: &this->player1, e: v3);
    v4 = ssEntity::ssEntity(this: v11, name: "player2");
    ssEntity::ssEntity(this: &this->player2, e: v4);
    v5 = ssEntity::ssEntity(this: v11, name: "player3");
    ssEntity::ssEntity(this: &this->player3, e: v5);
    v6 = ssEntity::ssEntity(this: v11, name: "player4");
    ssEntity::ssEntity(this: &this->player4, e: v6);
    v7 = ssEntity::ssEntity(this: v11, name: "player5");
    ssEntity::ssEntity(this: &this->player5, e: v7);
    v8 = ssEntity::ssEntity(this: v11, name: "player6");
    ssEntity::ssEntity(this: &this->player6, e: v8);
    v9 = ssEntity::ssEntity(this: v11, name: "player7");
    ssEntity::ssEntity(this: &this->player7, e: v9);
    v10 = ssEntity::ssEntity(this: v11, name: "player8");
    ssEntity::ssEntity(this: &this->player8, e: v10);
  }
  else
  {
    ssString::Init(this: v12);
    ssString::operator=(this: v12, text: "ssWorldUtil should only be placed on the world entity (worldspawn).");
    Error(msg: v12);
    ssString::Empty(this: v12);
  }
}


// ========================================================================
// __unwind$19054
// EA  : 0x82EECEB4
// RVA : 0x00EECEB4
// PDB : w:\tech5\tungsten\superscript\shared\worldutil.cpp
// ========================================================================

void _unwind_19054()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 96));
}

