
// ========================================================================
// ??0idDeclImpactSound@@QAA@XZ
// EA  : 0x82624118
// RVA : 0x00624118
// PDB : w:\tech5\engine\decls\declimpactsound.cpp
// ========================================================================

idDeclImpactSound *__fastcall idDeclImpactSound::idDeclImpactSound(idDeclImpactSound *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->defaultSound = nullptr;
  this->__vftable = (idDeclImpactSound_vtbl *)&idDeclImpactSound::`vftable';
  this->metalSound = nullptr;
  this->stoneSound = nullptr;
  this->fleshSound = nullptr;
  this->woodSound = nullptr;
  this->cardboardSound = nullptr;
  this->liquidSound = nullptr;
  this->glassSound = nullptr;
  this->plasticSound = nullptr;
  this->asphaltSound = nullptr;
  this->dirtSound = nullptr;
  this->concreteSound = nullptr;
  this->foliageSound = nullptr;
  this->linoleumSound = nullptr;
  this->fabricSound = nullptr;
  this->rubberSound = nullptr;
  this->rockSound = nullptr;
  this->steamPipeSound = nullptr;
  this->waterPipeSound = nullptr;
  this->armorSound = nullptr;
  this->sludgeSound = nullptr;
  this->impNestSound = nullptr;
  this->hollowMetalSound = nullptr;
  this->sheetMetalSound = nullptr;
  this->fleshPlayerSound = nullptr;
  this->bloodPoolSound = nullptr;
  this->ashSound = nullptr;
  this->mutantFleshSound = nullptr;
  this->thickPaddingSound = nullptr;
  this->playerAPCMetalSound = nullptr;
  this->ricketyMetalSound = nullptr;
  this->ricketyWoodSound = nullptr;
  this->soundInterval = 100;
  return this;
}


// ========================================================================
// ?GetImpactSoundForMaterial@idDeclImpactSound@@QBAPBVidSoundShader@@H@Z
// EA  : 0x826241E0
// RVA : 0x006241E0
// PDB : w:\tech5\engine\decls\declimpactsound.cpp
// ========================================================================

const idSoundShader *__fastcall idDeclImpactSound::GetImpactSoundForMaterial(
        idDeclImpactSound *this,
        const int materialID)
{
  const idSoundShader *result; // r3

  switch ( materialID )
  {
    case 1:
      result = this->metalSound;
      break;
    case 2:
      result = this->stoneSound;
      break;
    case 3:
      result = this->fleshSound;
      break;
    case 4:
      result = this->woodSound;
      break;
    case 5:
      result = this->cardboardSound;
      break;
    case 6:
      result = this->liquidSound;
      break;
    case 7:
      result = this->glassSound;
      break;
    case 8:
      result = this->plasticSound;
      break;
    case 9:
      result = this->asphaltSound;
      break;
    case 10:
      result = this->dirtSound;
      break;
    case 11:
      result = this->concreteSound;
      break;
    case 12:
      result = this->foliageSound;
      break;
    case 13:
      result = this->linoleumSound;
      break;
    case 14:
      result = this->fabricSound;
      break;
    case 15:
      result = this->rubberSound;
      break;
    case 16:
      result = this->rockSound;
      break;
    case 17:
      result = this->steamPipeSound;
      break;
    case 18:
      result = this->waterPipeSound;
      break;
    case 19:
      result = this->armorSound;
      break;
    case 20:
      result = this->sludgeSound;
      break;
    case 21:
      result = this->impNestSound;
      break;
    case 22:
      result = this->hollowMetalSound;
      break;
    case 23:
      result = this->fleshPlayerSound;
      break;
    case 25:
      result = this->bloodPoolSound;
      break;
    case 26:
      result = this->ashSound;
      break;
    case 27:
      result = this->mutantFleshSound;
      break;
    case 28:
      result = this->thickPaddingSound;
      break;
    case 29:
      result = this->playerAPCMetalSound;
      break;
    case 30:
      result = this->ricketyMetalSound;
      break;
    case 31:
      result = this->ricketyWoodSound;
      break;
    case 32:
      result = this->sheetMetalSound;
      break;
    default:
      result = this->defaultSound;
      break;
  }
  return result;
}

