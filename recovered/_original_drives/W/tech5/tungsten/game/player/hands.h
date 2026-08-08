
// ========================================================================
// ?IsInRestState@idHands@@QBA_NXZ
// EA  : 0x82B80608
// RVA : 0x00B80608
// PDB : w:\tech5\tungsten\game\player\hands.h
// ========================================================================

int __fastcall idHands::IsInRestState(idHands *this)
{
  idHands::handsState_t State; // r3
  unsigned __int8 v2; // r11

  if ( this->weaponRelaxed )
    return 1;
  if ( this->weaponRelaxedToggler )
    return 1;
  State = idHands::GetState(this, animWeb: &this->web);
  v2 = 0;
  if ( State == HS_HIDEMOVE )
    return 1;
  return v2;
}


// ========================================================================
// ??0idHandsAction@idHands@@QAA@XZ
// EA  : 0x82DFDD38
// RVA : 0x00DFDD38
// PDB : w:\tech5\tungsten\game\player\hands.h
// ========================================================================

idHands::idHandsAction *__fastcall idHands::idHandsAction::idHandsAction(idHands::idHandsAction *this)
{
  this->action = HANDSACTION_NONE;
  this->ammoDecl = nullptr;
  this->weapon = nullptr;
  this->throwable = nullptr;
  this->useIntroBringUp = false;
  this->isSecondary = false;
  this->leftHand = false;
  this->extraNodeInfo.data = this->extraNodeInfo.baseBuffer;
  this->extraNodeInfo.allocedAndFlag = 20;
  this->extraNodeInfo.len = 0;
  this->extraNodeInfo.baseBuffer[0] = 0;
  idStr::Clear(this: &this->extraNodeInfo);
  return this;
}


// ========================================================================
// __unwind$494274
// EA  : 0x82DFDDB8
// RVA : 0x00DFDDB8
// PDB : w:\tech5\tungsten\game\player\hands.h
// ========================================================================

void _unwind_494274()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ?GetCookingProjectile@idHands@@QBAPAVidProjectile@@XZ
// EA  : 0x82E056D8
// RVA : 0x00E056D8
// PDB : w:\tech5\tungsten\game\player\hands.h
// ========================================================================

idProjectile *__fastcall idHands::GetCookingProjectile(idHands *this)
{
  int value; // r10
  idProjectile *v2; // r3

  value = this->cookingProjectile.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idProjectile *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idProjectile::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}

