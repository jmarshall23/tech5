
// ========================================================================
// ??1idPresentableDoorAnimated@@UAA@XZ
// EA  : 0x82B6EA88
// RVA : 0x00B6EA88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void __fastcall idPresentableDoorAnimated::~idPresentableDoorAnimated(idPresentableDoorAnimated *this)
{
  this->__vftable = (idPresentableDoorAnimated_vtbl *)&idPresentableDoorAnimated::`vftable';
  idPhysics_Static::~idPhysics_Static(this: &this->physicsObj);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$487524_0
// EA  : 0x82B6EADC
// RVA : 0x00B6EADC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void _unwind_487524_0()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?LinkCollision@idPresentableAnimatedPhysics@@QAAXXZ
// EA  : 0x82B6EB08
// RVA : 0x00B6EB08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void __fastcall idPresentableAnimatedPhysics::LinkCollision(idPresentableAnimatedPhysics *this)
{
  this->physicsObj.LinkClip(this: &this->physicsObj);
  this->linked = true;
}


// ========================================================================
// ?UnlinkCollision@idPresentableDoorAnimated@@QAAXXZ
// EA  : 0x82B6EB50
// RVA : 0x00B6EB50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void __fastcall idPresentableDoorAnimated::UnlinkCollision(idPresentableAnimatedPhysics *this)
{
  this->physicsObj.UnlinkClip(this: &this->physicsObj);
  this->linked = false;
}


// ========================================================================
// ?GetName@idFakeCB@@UAAPBDXZ
// EA  : 0x82B6EBA0
// RVA : 0x00B6EBA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

const char *__fastcall idFakeCB::GetName(idFakeCB *this)
{
  return "fakeCB";
}


// ========================================================================
// ?InitPhysics@idPresentableDoorAnimated@@AAAXPAVidPhysicsCallbacks@@PAVidStrClipModel@@_N@Z
// EA  : 0x82B6EC18
// RVA : 0x00B6EC18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void __fastcall idPresentableDoorAnimated::InitPhysics(
        idPresentableAnimatedPhysics *this,
        idPhysicsCallbacks *callbacks,
        idStrClipModel *clipModel,
        bool isObstacle)
{
  idPhysics_Static *p_physicsObj; // r30
  idClipModel *v8; // r3
  idClipModel *v9; // r4

  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: callbacks,
    entityNumber_: this->entityOwnerIndex);
  v8 = (idClipModel *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0xD8u,
                        tag: TAG_CLIPMODEL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idClipModel::idClipModel(
           this: v8,
           clip: &clientGame->clip,
           name: clipModel->str,
           overrideClipMaterial: nullptr);
  else
    v9 = nullptr;
  ((void (__fastcall *)(idPhysics_Static *, idClipModel *, double))p_physicsObj->SetClipModel)(
    a1: p_physicsObj,
    a2: v9,
    a3: 1.0);
  p_physicsObj->SetClipMask(this: p_physicsObj, a2: 4194305, a3: -1);
  p_physicsObj->SetContents(this: p_physicsObj, a2: (!isObstacle ? 0 : 0x20000) | 1, a3: -1);
  this->physicsInit = true;
}


// ========================================================================
// __unwind$487859
// EA  : 0x82B6ED2C
// RVA : 0x00B6ED2C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void _unwind_487859()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ??0idPresentableDoorAnimated@@QAA@PAVidDoor_Animated@@AAVidDoor_AnimatedPiece@@@Z
// EA  : 0x82B6ED60
// RVA : 0x00B6ED60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

idPresentableDoorAnimated *__fastcall idPresentableDoorAnimated::idPresentableDoorAnimated(
        idPresentableDoorAnimated *this,
        idDoor_Animated *door,
        idDoor_AnimatedPiece *piece)
{
  int entityNumber; // r27
  const idDeclFX *v7; // r3

  entityNumber = door->entityNumber;
  v7 = door->GetFXDecl(this: door);
  idPresentable::idPresentable(this, e: door, renderModel_: nullptr, entityNumber_: entityNumber, fxDecl_: v7);
  this->__vftable = (idPresentableDoorAnimated_vtbl *)&idPresentableDoorAnimated::`vftable';
  idPhysics_Static::idPhysics_Static(this: &this->physicsObj);
  this->clip.str = piece->clipModel.str;
  this->entityOwnerIndex = door->entityNumber;
  this->linked = false;
  idPresentableDoorAnimated::InitPhysics(
    (idPresentableAnimatedPhysics *)this,
    callbacks: &door->physicsCallbacks,
    clipModel: &piece->clipModel,
    isObstacle: piece->isObstacle);
  return this;
}


// ========================================================================
// __unwind$487994_0
// EA  : 0x82B6EDFC
// RVA : 0x00B6EDFC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void _unwind_487994_0()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487995_0
// EA  : 0x82B6EE24
// RVA : 0x00B6EE24
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void _unwind_487995_0()
{
  int v0; // r12

  idPhysics_Static::~idPhysics_Static(this: (idPhysics_Static *)(*(_DWORD *)(v0 - 128 + 148) + 1200));
}


// ========================================================================
// ?Serialize@idPresentableDoorAnimated@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6EE50
// RVA : 0x00B6EE50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.cpp
// ========================================================================

void __fastcall idPresentableDoorAnimated::Serialize(idPresentableDoorAnimated *this, idSerializer *ser)
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
    idPresentableDoorAnimated::InitPhysics(
      (idPresentableAnimatedPhysics *)this,
      callbacks: &fakeCB,
      clipModel: &this->clip,
      isObstacle: false);
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

