
// ========================================================================
// ??0idAASObstacle@@QAA@XZ
// EA  : 0x829EE340
// RVA : 0x009EE340
// PDB : w:\tech5\tungsten\game\ai\aasobstacle.cpp
// ========================================================================

idAASObstacle *__fastcall idAASObstacle::idAASObstacle(idAASObstacle *this)
{
  idEntity::idEntity(this);
  *(_WORD *)&this->startOn = 1;
  this->__vftable = (idAASObstacle_vtbl *)&idAASObstacle::`vftable';
  this->travelFlags = AAS_TFL_INVALID;
  this->enabled = false;
  return this;
}


// ========================================================================
// ?ChangeAreaState@idAASObstacle@@AAAXXZ
// EA  : 0x829EE398
// RVA : 0x009EE398
// PDB : w:\tech5\tungsten\game\ai\aasobstacle.cpp
// ========================================================================

void __fastcall idAASObstacle::ChangeAreaState(idAASObstacle *this)
{
  idPhysics *Physics; // r3
  aas2TravelFlag_t travelFlags; // r30
  bool enabled; // r29
  const idBounds *v5; // r3
  idPhysics *v6; // r3
  int v7; // r30
  idPhysics *v8; // r3
  idPhysics *v9; // r3
  idPhysics *v10; // r3
  idPhysics *v11; // r3

  Physics = idEntity::GetPhysics(this);
  travelFlags = this->travelFlags;
  enabled = this->enabled;
  v5 = Physics->GetAbsBounds(this: Physics, a2: -1);
  idGameLocal::ChangeAreaTravelFlags(this: gameLocal, bounds: v5, areaFlags: 2048, travelFlags, set: enabled);
  if ( this->dynamicObstacle )
  {
    v6 = idEntity::GetPhysics(this);
    v7 = v6->GetContents(this: v6, a2: -1);
    if ( this->enabled )
    {
      v8 = idEntity::GetPhysics(this);
      v8->SetContents(this: v8, a2: v7 | 0x20000, a3: -1);
      v9 = idEntity::GetPhysics(this);
      v9->LinkClip(this: v9);
    }
    else
    {
      v10 = idEntity::GetPhysics(this);
      v10->SetContents(this: v10, a2: v7 & 0xFFFDFFFF, a3: -1);
      v11 = idEntity::GetPhysics(this);
      v11->UnlinkClip(this: v11);
    }
  }
}


// ========================================================================
// ?Spawn@idAASObstacle@@QAAXXZ
// EA  : 0x829EE498
// RVA : 0x009EE498
// PDB : w:\tech5\tungsten\game\ai\aasobstacle.cpp
// ========================================================================

void __fastcall idAASObstacle::Spawn(idAASObstacle *this)
{
  this->enabled = this->startOn;
  idAASObstacle::ChangeAreaState(this);
}


// ========================================================================
// ?OnActivate@idAASObstacle@@EAAXPAVidEntity@@@Z
// EA  : 0x829EE4A8
// RVA : 0x009EE4A8
// PDB : w:\tech5\tungsten\game\ai\aasobstacle.cpp
// ========================================================================

void __fastcall idAASObstacle::OnActivate(idAASObstacle *this, idEntity *activator)
{
  this->enabled = (_cntlzw(this->enabled) & 0x20) != 0;
  idAASObstacle::ChangeAreaState(this);
}

