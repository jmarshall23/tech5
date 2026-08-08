
// ========================================================================
// ??1idPresentableAnimatedPhysics@@UAA@XZ
// EA  : 0x82B6B7D8
// RVA : 0x00B6B7D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void __fastcall idPresentableAnimatedPhysics::~idPresentableAnimatedPhysics(idPresentableAnimatedPhysics *this)
{
  this->__vftable = (idPresentableAnimatedPhysics_vtbl *)&idPresentableAnimatedPhysics::`vftable';
  idPhysics_Static::~idPhysics_Static(this: &this->physicsObj);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$487524
// EA  : 0x82B6B82C
// RVA : 0x00B6B82C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void _unwind_487524()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetName@idDummyPhysicsCallback@@UAAPBDXZ
// EA  : 0x82B6B858
// RVA : 0x00B6B858
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

const char *__fastcall idDummyPhysicsCallback::GetName(idDummyPhysicsCallback *this)
{
  return "dummyCB";
}


// ========================================================================
// ?Present@idPresentableDoorAnimated@@UAAXXZ
// EA  : 0x82B6B8C8
// RVA : 0x00B6B8C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void __fastcall idPresentableDoorAnimated::Present(idPresentableAnimatedPhysics *this)
{
  struct idPhysics_Static *p_physicsObj; // r30

  p_physicsObj = &this->physicsObj;
  this->physicsObj.SetAxis(this: &this->physicsObj, a2: &this->axis, a3: -1);
  this->physicsObj.SetOrigin(this: p_physicsObj, a2: &this->origin, a3: -1);
  idPresentable::Present(this);
}


// ========================================================================
// ??0idPresentableAnimatedPhysics@@QAA@PAVidAnimatedSimplePhysics@@AAVidAnimPhysicsPiece@@@Z
// EA  : 0x82B6BA10
// RVA : 0x00B6BA10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

idPresentableAnimatedPhysics *__fastcall idPresentableAnimatedPhysics::idPresentableAnimatedPhysics(
        idPresentableAnimatedPhysics *this,
        idAnimatedSimplePhysics *entity,
        idAnimPhysicsPiece *piece)
{
  int entityNumber; // r27
  const idDeclFX *v7; // r3

  entityNumber = entity->entityNumber;
  v7 = entity->GetFXDecl(this: entity);
  idPresentable::idPresentable(this, e: entity, renderModel_: nullptr, entityNumber_: entityNumber, fxDecl_: v7);
  this->__vftable = (idPresentableAnimatedPhysics_vtbl *)&idPresentableAnimatedPhysics::`vftable';
  idPhysics_Static::idPhysics_Static(this: &this->physicsObj);
  this->clip.str = piece->clipModel.str;
  this->entityOwnerIndex = entity->entityNumber;
  this->linked = false;
  idPresentableDoorAnimated::InitPhysics(
    this,
    callbacks: &entity->physicsCallbacks,
    clipModel: &piece->clipModel,
    isObstacle: piece->isObstacle);
  return this;
}


// ========================================================================
// __unwind$487994
// EA  : 0x82B6BAAC
// RVA : 0x00B6BAAC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void _unwind_487994()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487995
// EA  : 0x82B6BAD4
// RVA : 0x00B6BAD4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void _unwind_487995()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 128 + 148) + 1200));
}


// ========================================================================
// ?Serialize@idPresentableAnimatedPhysics@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6BB00
// RVA : 0x00B6BB00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableanimatedphysics.cpp
// ========================================================================

void __fastcall idPresentableAnimatedPhysics::Serialize(idPresentableAnimatedPhysics *this, idSerializer *ser)
{
  bool linked; // r27
  idBitMsg *msg; // r3
  bool v6; // r29
  idBitMsg *v7; // r3
  BOOL v8; // r11
  idPhysics_Static_vtbl *v9; // r11
  idPhysics_Static *p_physicsObj; // r3
  bool v11; // zf

  idPresentable::Serialize(this, ser);
  linked = this->linked;
  idSerializer::SerializeString(this: ser, s: &this->clip);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->entityOwnerIndex, numBits: 32);
  else
    this->entityOwnerIndex = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = this->linked;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->linked, numBits: 1);
  else
    v6 = (_cntlzw(idBitMsg::ReadBits(this: v7, numBits: 1) - 1) & 0x20) != 0;
  this->linked = v6;
  if ( !ser->writing && !this->physicsInit )
  {
    idPresentableDoorAnimated::InitPhysics(this, callbacks: &dummyCB, clipModel: &this->clip, isObstacle: false);
    this->Present(this);
  }
  v8 = this->linked;
  if ( linked != v8 )
  {
    p_physicsObj = &this->physicsObj;
    v11 = !v8;
    v9 = this->physicsObj.__vftable;
    if ( v11 )
    {
      v9->UnlinkClip(this: p_physicsObj);
      this->linked = false;
    }
    else
    {
      v9->LinkClip(this: p_physicsObj);
      this->linked = true;
    }
  }
}

