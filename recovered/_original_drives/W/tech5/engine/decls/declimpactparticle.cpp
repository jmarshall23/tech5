
// ========================================================================
// ??0idDeclImpactParticle@@QAA@XZ
// EA  : 0x82623E88
// RVA : 0x00623E88
// PDB : w:\tech5\engine\decls\declimpactparticle.cpp
// ========================================================================

idDeclImpactParticle *__fastcall idDeclImpactParticle::idDeclImpactParticle(idDeclImpactParticle *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->defaultPrt = nullptr;
  this->__vftable = (idDeclImpactParticle_vtbl *)&idDeclImpactParticle::`vftable';
  this->metalPrt = nullptr;
  this->stonePrt = nullptr;
  this->fleshPrt = nullptr;
  this->woodPrt = nullptr;
  this->cardboardPrt = nullptr;
  this->liquidPrt = nullptr;
  this->glassPrt = nullptr;
  this->plasticPrt = nullptr;
  this->asphaltPrt = nullptr;
  this->dirtPrt = nullptr;
  this->concretePrt = nullptr;
  this->foliagePrt = nullptr;
  this->linoleumPrt = nullptr;
  this->fabricPrt = nullptr;
  this->rubberPrt = nullptr;
  this->rockPrt = nullptr;
  this->steamPipePrt = nullptr;
  this->waterPipePrt = nullptr;
  this->armorPrt = nullptr;
  this->sludgePrt = nullptr;
  this->shieldPrt = nullptr;
  this->bloodPoolPrt = nullptr;
  this->ashPrt = nullptr;
  this->mutantFleshPrt = nullptr;
  this->thickPaddingPrt = nullptr;
  return this;
}


// ========================================================================
// ?GetImpactParticleForMaterial@idDeclImpactParticle@@QBAPBVidDeclParticle@@H@Z
// EA  : 0x82623F30
// RVA : 0x00623F30
// PDB : w:\tech5\engine\decls\declimpactparticle.cpp
// ========================================================================

const idDeclParticle *__fastcall idDeclImpactParticle::GetImpactParticleForMaterial(
        idDeclImpactParticle *this,
        const int materialID)
{
  const idDeclParticle *result; // r3

  switch ( materialID )
  {
    case 1:
    case 22:
    case 29:
    case 30:
    case 32:
      result = this->metalPrt;
      break;
    case 2:
      result = this->stonePrt;
      break;
    case 3:
      result = this->fleshPrt;
      break;
    case 4:
    case 31:
      result = this->woodPrt;
      break;
    case 5:
      result = this->cardboardPrt;
      break;
    case 6:
      result = this->liquidPrt;
      break;
    case 7:
      result = this->glassPrt;
      break;
    case 8:
      result = this->plasticPrt;
      break;
    case 9:
      result = this->asphaltPrt;
      break;
    case 10:
      result = this->dirtPrt;
      break;
    case 11:
      result = this->concretePrt;
      break;
    case 12:
      result = this->foliagePrt;
      break;
    case 13:
      result = this->linoleumPrt;
      break;
    case 14:
      result = this->fabricPrt;
      break;
    case 15:
      result = this->rubberPrt;
      break;
    case 16:
      result = this->rockPrt;
      break;
    case 17:
      result = this->steamPipePrt;
      break;
    case 18:
      result = this->waterPipePrt;
      break;
    case 19:
      result = this->armorPrt;
      break;
    case 20:
      result = this->sludgePrt;
      break;
    case 25:
      result = this->bloodPoolPrt;
      break;
    case 26:
      result = this->ashPrt;
      break;
    case 27:
      result = this->mutantFleshPrt;
      break;
    case 28:
      result = this->thickPaddingPrt;
      break;
    default:
      result = this->defaultPrt;
      break;
  }
  return result;
}

