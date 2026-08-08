
// ========================================================================
// ?GetAttackerEntity@idPresentableProjectile@@QBAPAVidEntity@@XZ
// EA  : 0x82AC20C8
// RVA : 0x00AC20C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

idEntity *__fastcall idPresentableProjectile::GetAttackerEntity(idPresentableProjectile *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_attacker; // r29
  int v3; // r31

  spawnId = this->attacker.spawnId;
  p_attacker = &this->attacker;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == p_attacker->spawnId )
  {
    return idPresentablePtr<idPresentableProjectile>::operator->(this: p_attacker)->entity;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Evaluate@OC_MoveFailedDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82B8AF80
// RVA : 0x00B8AF80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

int __fastcall OC_MoveFailedDone::Evaluate(idVehicleOccupant *this)
{
  return 9;
}


// ========================================================================
// ?GetType@idPresentableProjectile_Rocket@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82B8AF88
// RVA : 0x00B8AF88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

int __fastcall idPresentableProjectile_Rocket::GetType(idPresentableProjectile_Rocket *this)
{
  return 12;
}


// ========================================================================
// ?GetType@idPresentableProjectile_Homing@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82B8AF90
// RVA : 0x00B8AF90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

unsigned int __fastcall idPresentableProjectile_Homing::GetType(XGRAPHICS::_PS_PROGRAM_KEY *pProgKey)
{
  return 13;
}


// ========================================================================
// ??8idProjectileTarget@@QBA_NPBVidPresentable@@@Z
// EA  : 0x82ED27D0
// RVA : 0x00ED27D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

BOOL __fastcall idProjectileTarget::operator==(idProjectileTarget *this, const idPresentable *p)
{
  return this->type == TARGET_PRESENTABLE
      && (_cntlzw(
            (char *)p
          - (char *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable))
        & 0x20) != 0;
}


// ========================================================================
// ??BidProjectileTarget@@QBAABVidVec3@@XZ
// EA  : 0x82ED2830
// RVA : 0x00ED2830
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// ========================================================================

const idVec3 *__fastcall idProjectileTarget::operator idVec3 const &(idProjectileTarget *this)
{
  idPresentable *v1; // r3

  if ( this->type == TARGET_PRESENTABLE )
  {
    v1 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentable);
    if ( v1 == nullptr )
      return &vec3_origin;
    return &v1->origin;
  }
  else
  {
    if ( this->type != TARGET_POINT )
      return &vec3_origin;
    return &this->pos;
  }
}

