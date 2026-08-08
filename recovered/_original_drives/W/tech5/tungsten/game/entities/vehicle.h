
// ========================================================================
// ??0seatInfo_t@idVehicle@@QAA@XZ
// EA  : 0x824FB078
// RVA : 0x004FB078
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicle::seatInfo_t *__fastcall idVehicle::seatInfo_t::seatInfo_t(idVehicle::seatInfo_t *this)
{
  idStr::idStr(this: &this->tagName, text: "driver_model_tag");
  this->model = nullptr;
  this->weaponAttach = false;
  this->playerCanOccupy = true;
  this->isEasilyThrown = false;
  this->isFake = false;
  this->enterAnim.list = nullptr;
  this->enterAnim.granularity = 0;
  this->enterAnim.memTag = 5;
  this->enterAnim.listStatic = 0;
  this->enterAnim.size = 0;
  this->enterAnim.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enterAnim);
  this->enterViaAnimRefStr.len = 0;
  this->enterViaAnimRefStr.allocedAndFlag = 20;
  this->enterViaAnimRefStr.data = this->enterViaAnimRefStr.baseBuffer;
  this->enterViaAnimRefStr.baseBuffer[0] = 0;
  this->enterDstAnimRefStr.allocedAndFlag = 20;
  this->enterDstAnimRefStr.len = 0;
  this->enterDstAnimRefStr.data = this->enterDstAnimRefStr.baseBuffer;
  this->enterDstAnimRefStr.baseBuffer[0] = 0;
  this->exitAnim.list = nullptr;
  this->exitAnim.granularity = 0;
  this->exitAnim.memTag = 5;
  this->exitAnim.listStatic = 0;
  this->exitAnim.size = 0;
  this->exitAnim.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitAnim);
  this->exitViaAnimRefStr.allocedAndFlag = 20;
  this->exitViaAnimRefStr.len = 0;
  this->exitViaAnimRefStr.data = this->exitViaAnimRefStr.baseBuffer;
  this->exitViaAnimRefStr.baseBuffer[0] = 0;
  this->exitDstAnimRefStr.allocedAndFlag = 20;
  this->exitDstAnimRefStr.len = 0;
  this->exitDstAnimRefStr.data = this->exitDstAnimRefStr.baseBuffer;
  this->exitDstAnimRefStr.baseBuffer[0] = 0;
  this->exitSnapToEntity.spawnId.value = 0x1FFF;
  this->exitHideEntity = false;
  this->vehicleOccupant.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$584315
// EA  : 0x824FB18C
// RVA : 0x004FB18C
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_584315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$584316
// EA  : 0x824FB1B4
// RVA : 0x004FB1B4
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_584316()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// __unwind$584317
// EA  : 0x824FB1E0
// RVA : 0x004FB1E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_584317()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$584318
// EA  : 0x824FB20C
// RVA : 0x004FB20C
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_584318()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 88));
}


// ========================================================================
// ??0window_t@idVehicleWindow@@QAA@XZ
// EA  : 0x82592A20
// RVA : 0x00592A20
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicleWindow::window_t *__fastcall idVehicleWindow::window_t::window_t(idVehicleWindow::window_t *this)
{
  unsigned __int64 v1; // r30
  float z; // r4

  LODWORD(v1) = 0;
  this->decals.list = nullptr;
  this->decals.granularity = 0;
  this->decals.memTag = 5;
  this->decals.listStatic = 0;
  this->decals.size = 0;
  this->decals.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->normalModel = nullptr;
  this->brokenModel = nullptr;
  this->collisionModel = nullptr;
  this->clipQuery.index = v1;
  this->damageQuery.def = nullptr;
  this->damageQuery.inflictor.spawnId.value = 0x1FFF;
  this->damageQuery.attacker.spawnId.value = 0x1FFF;
  this->damageQuery.dir.x = vec3_origin.x;
  this->damageQuery.dir.y = vec3_origin.y;
  z = vec3_origin.z;
  this->damageQuery.scale = 1.0;
  this->damageQuery.dir.z = z;
  this->lastDecalIndex = -1;
  this->broken = false;
  return this;
}


// ========================================================================
// ?GetCameraPlacement@idVehicle@@QAAABUcameraPlacement_t@idDeclVehicleProps@@XZ
// EA  : 0x82B04EA0
// RVA : 0x00B04EA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

const idDeclVehicleProps::cameraPlacement_t *__fastcall idVehicle::GetCameraPlacement(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return &presentable->GetVehicleInterface(this: presentable)->vehicleProps->camera;
  else
    return (const idDeclVehicleProps::cameraPlacement_t *)(MEMORY[0x2D6C] + 64);
}


// ========================================================================
// ?GetSteerAngle@idVehicle@@QBAMXZ
// EA  : 0x82B093E8
// RVA : 0x00B093E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle::GetSteerAngle(idVehicle *this)
{
  idPresentable *presentable; // r3
  double curSteerAngle; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    curSteerAngle = presentable->GetVehicleInterface(this: presentable)->curSteerAngle;
  else
    curSteerAngle = MEMORY[0x4424];
  return *((float *)&curSteerAngle + 1);
}


// ========================================================================
// ?UpdateSteerAngle@idVehicle@@QAAXM@Z
// EA  : 0x82B09440
// RVA : 0x00B09440
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::UpdateSteerAngle(idVehicle *this, double desiredAngle)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetVehicleInterface(this: presentable);
  else
    v4 = nullptr;
  idPresentableVehicle::UpdateSteerAngle(this: v4, idealSteerAngle: desiredAngle);
}


// ========================================================================
// ?SetMaxSteerSpeed@idVehicle@@QAAXM@Z
// EA  : 0x82B09498
// RVA : 0x00B09498
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::SetMaxSteerSpeed(idVehicle *this, double speed)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->maxSteerSpeed = speed;
  else
    MEMORY[0x4428] = speed;
}


// ========================================================================
// ?GetMaxSteerAngle@idVehicle@@QBAMM@Z
// EA  : 0x82B09500
// RVA : 0x00B09500
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle::GetMaxSteerAngle(idVehicle *this, double speed)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v4; // r3
  double MaxSteerAngle; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetVehicleInterface(this: presentable);
  else
    v4 = nullptr;
  MaxSteerAngle = idPresentableVehicle::GetMaxSteerAngle(this: v4, speed);
  return *((float *)&MaxSteerAngle + 1);
}


// ========================================================================
// ?GetCurrentSpeedInMPH@idVehicle@@QBAMXZ
// EA  : 0x82B09558
// RVA : 0x00B09558
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle::GetCurrentSpeedInMPH(idVehicle *this)
{
  idPresentable *presentable; // r3
  double currentMPH; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    currentMPH = presentable->GetVehicleInterface(this: presentable)->currentMPH;
  else
    currentMPH = MEMORY[0x45C8];
  return *((float *)&currentMPH + 1);
}


// ========================================================================
// ?UpdateCurrentThrottle@idVehicle@@QAAXM@Z
// EA  : 0x82B095B0
// RVA : 0x00B095B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::UpdateCurrentThrottle(idVehicle *this, double newthrottle)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetVehicleInterface(this: presentable);
  else
    v4 = nullptr;
  idPresentableVehicle::UpdateCurrentThrottle(this: v4, newThrottle: newthrottle);
}


// ========================================================================
// ?CanFireWeapons@idVehicle@@QBA_NXZ
// EA  : 0x82B09608
// RVA : 0x00B09608
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::CanFireWeapons(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->canFireWeapons;
  else
    return MEMORY[0x49EC];
}


// ========================================================================
// ?GetAFPhysics@idVehicle@@QAAPAVidPhysics_AF@@XZ
// EA  : 0x82B09660
// RVA : 0x00B09660
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::GetAFPhysics(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetVehicleInterface(this: presentable)->physicsObj;
  else
    return 16512;
}


// ========================================================================
// ?GetLastViewAxis@idVehicle@@QBA?AVidMat3@@XZ
// EA  : 0x82B096B8
// RVA : 0x00B096B8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicle *__fastcall idVehicle::GetLastViewAxis(idVehicle *this, idMat3 *result)
{
  float z; // r3
  int v4; // r3
  idVehicle_vtbl **v5; // r11
  idVehicle *v6; // r10
  int i; // ctr

  z = result[13].mat[1].z;
  if ( z == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 76))(a1: COERCE_DOUBLE(LODWORD(z)));
  v5 = (idVehicle_vtbl **)(v4 + 18872);
  v6 = (idVehicle *)((char *)this - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v5;
    v6 = (idVehicle *)((char *)v6 + 4);
    v6->__vftable = *v5;
  }
  return this;
}


// ========================================================================
// ?UpdateStickControl@idVehicle_Car@@QAAXMM@Z
// EA  : 0x82B09728
// RVA : 0x00B09728
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::UpdateStickControl(idVehicle_Car *this, double xFrac, double yFrac, bool a4)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v7; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = presentable->GetVehicleInterface(this: presentable);
  else
    v7 = nullptr;
  idPresentableVehicle::UpdateStickControl(this: v7, xFrac, yFrac, handBraking: a4);
}


// ========================================================================
// ?IsReversing@idVehicle_Car@@QBA_NXZ
// EA  : 0x82B09790
// RVA : 0x00B09790
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::IsReversing(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->reversing;
  else
    return MEMORY[0x2E67];
}


// ========================================================================
// ?IsAccelerating@idVehicle_Car@@QBA_NXZ
// EA  : 0x82B097E8
// RVA : 0x00B097E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::IsAccelerating(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->accelerating;
  else
    return MEMORY[0x2E66];
}


// ========================================================================
// ?IsBraking@idVehicle_Car@@QBA_NXZ
// EA  : 0x82B09840
// RVA : 0x00B09840
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::IsBraking(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->braking;
  else
    return MEMORY[0x2E6A];
}


// ========================================================================
// ?StopBoostFX@idVehicle_Car@@QAAXXZ
// EA  : 0x82B09898
// RVA : 0x00B09898
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::StopBoostFX(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::StopBoostFX(this: v2);
  }
  else
  {
    idPresentableVehicle::StopBoostFX(this: nullptr);
  }
}


// ========================================================================
// ?SetBraking@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82B098F0
// RVA : 0x00B098F0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetBraking(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->braking = bl;
  else
    MEMORY[0x2E6A] = bl;
}


// ========================================================================
// ?SetHandBraking@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82B09958
// RVA : 0x00B09958
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetHandBraking(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->handBraking = bl;
  else
    MEMORY[0x2E6B] = bl;
}


// ========================================================================
// ?SetAccelerating@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82B099C0
// RVA : 0x00B099C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetAccelerating(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->accelerating = bl;
  else
    MEMORY[0x2E66] = bl;
}


// ========================================================================
// ?SetReversing@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82B09A28
// RVA : 0x00B09A28
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetReversing(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->reversing = bl;
  else
    MEMORY[0x2E67] = bl;
}


// ========================================================================
// ?GetViolentRollStartTime@idVehicle_Car@@QBAHXZ
// EA  : 0x82B09A90
// RVA : 0x00B09A90
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::GetViolentRollStartTime(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->violentRollStartTime;
  else
    return MEMORY[0x4FC0];
}


// ========================================================================
// ?GetViolentRollStopTime@idVehicle_Car@@QBAHXZ
// EA  : 0x82B09AE8
// RVA : 0x00B09AE8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::GetViolentRollStopTime(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->violentRollStopTime;
  else
    return MEMORY[0x4FC4];
}


// ========================================================================
// ?GetWeapon@idVehicle@@QAAPAVidVehicleWeapon@@H@Z
// EA  : 0x82B0AEF8
// RVA : 0x00B0AEF8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicleWeapon *__fastcall idVehicle::GetWeapon(idVehicle *this, int num)
{
  idPresentable *presentable; // r3
  int v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  return *(idVehicleWeapon **)(*(_DWORD *)(v4 + 18744) + 4 * num);
}


// ========================================================================
// ?GetNumWeapons@idVehicle@@QBAHXZ
// EA  : 0x82B0AF50
// RVA : 0x00B0AF50
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::GetNumWeapons(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->weapons.num;
  else
    return MEMORY[0x493C];
}


// ========================================================================
// ?GetNumWheels@idVehicle@@QBAHXZ
// EA  : 0x82B0AFA8
// RVA : 0x00B0AFA8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::GetNumWheels(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->wheels.num;
  else
    return MEMORY[0x406C];
}


// ========================================================================
// ?IsViolentRoll@idVehicle_Car@@QBA_NXZ
// EA  : 0x82B0B000
// RVA : 0x00B0B000
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::IsViolentRoll(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r11
  unsigned int v5; // r31
  int v6; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  v4 = this->presentable;
  v5 = *(_DWORD *)(v3 + 20416);
  if ( v4 != nullptr )
    v6 = (int)v4->GetVehicleInterface(this: v4);
  else
    v6 = 0;
  return ((((v5 ^ *(_DWORD *)(v6 + 20420)) & 0x80000000) == 0) + (*(_DWORD *)(v6 + 20420) >= v5)) & 1;
}


// ========================================================================
// ?GetLastCollision@idVehicle@@QAAAAUcollisionInfo_t@@XZ
// EA  : 0x82B20DF0
// RVA : 0x00B20DF0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::GetLastCollision(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetVehicleInterface(this: presentable)->lastCollision;
  else
    return 20272;
}


// ========================================================================
// ?SetMaxSpeed@idVehicle_Car@@QAAXM@Z
// EA  : 0x82B20E48
// RVA : 0x00B20E48
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetMaxSpeed(idVehicle_Car *this, double speed)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->currentMaxSpeed = speed;
  else
    MEMORY[0x45E0] = speed;
}


// ========================================================================
// ?GetOccupant@idVehicle@@QAAAAUvehicleOccupant_t@@H@Z
// EA  : 0x82B946E8
// RVA : 0x00B946E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

vehicleOccupant_t *__fastcall idVehicle::GetOccupant(idVehicle *this, int i)
{
  idPresentable *presentable; // r3
  int v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  return (vehicleOccupant_t *)(*(_DWORD *)(v4 + 16472) + 16 * i);
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleDecalDamage@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD6680
// RVA : 0x00BD6680
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleDecalDamage> *__fastcall idDeclVehicleDecalDamage::GetDeclInfo(
        idDeclVehicleDecalDamage *this)
{
  return &idDeclVehicleDecalDamage::resourceList;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleWindowKit@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD6DC8
// RVA : 0x00BD6DC8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleWindowKit> *__fastcall idDeclVehicleWindowKit::GetDeclInfo(
        idDeclVehicleWindowKit *this)
{
  return &idDeclVehicleWindowKit::resourceList;
}


// ========================================================================
// ?GetLastViewOrigin@idVehicle@@QBA?AVidVec3@@XZ
// EA  : 0x82CCBE90
// RVA : 0x00CCBE90
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicle *__fastcall idVehicle::GetLastViewOrigin(idVehicle *this, idVec3 *result)
{
  float z; // r3
  int v4; // r11
  idList<idEventReceiver *,5> *v6; // r9
  idList<idEventReceiver *,5> *v7; // r8

  z = result[40].z;
  if ( z == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 76))(a1: COERCE_DOUBLE(LODWORD(z)));
  v6 = *(idList<idEventReceiver *,5> **)(v4 + 18868);
  v7 = *(idList<idEventReceiver *,5> **)(v4 + 18872);
  this->__vftable = *(idVehicle_vtbl **)(v4 + 18864);
  this->listenerList = v6;
  this->listeningToList = v7;
  return this;
}


// ========================================================================
// ?GetMaxHealth@idVehicle@@UBAMXZ
// EA  : 0x82D1CB80
// RVA : 0x00D1CB80
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle::GetMaxHealth(idVehicle *this)
{
  double maxHealth; // fp1

  maxHealth = this->maxHealth;
  return *((float *)&maxHealth + 1);
}


// ========================================================================
// ?GetCrosshair@idVehicle@@QAAAAVidThirdPersonCrosshair@@XZ
// EA  : 0x82D1CB88
// RVA : 0x00D1CB88
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idThirdPersonCrosshair *__fastcall idVehicle::GetCrosshair(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
    return idPresentableVehicle::GetCrosshair(this: nullptr);
  v2 = presentable->GetVehicleInterface(this: presentable);
  return idPresentableVehicle::GetCrosshair(this: v2);
}


// ========================================================================
// ?GetWeaponControlIndex@idVehicle@@QBAHXZ
// EA  : 0x82D1CBE0
// RVA : 0x00D1CBE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::GetWeaponControlIndex(idVehicle *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->weaponControlIndex;
  else
    return MEMORY[0x4644];
}


// ========================================================================
// ?AllowAccelerate@idVehicle@@QAAX_N@Z
// EA  : 0x82D1CC38
// RVA : 0x00D1CC38
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::AllowAccelerate(idVehicle *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->canAccelerate = bl;
  else
    MEMORY[0x2E69] = bl;
}


// ========================================================================
// ?AddQuickItemThink@idVehicle_Car@@QAAXPAVidVehicleQuickItem@@@Z
// EA  : 0x82D1CCA0
// RVA : 0x00D1CCA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::AddQuickItemThink(
        idVehicle_Car *this,
        idVehicleQuickItem *item,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v10; // r3
  int v11; // [sp+8h] [-58h]
  int v12; // [sp+Ch] [-54h]
  int v13; // [sp+10h] [-50h]
  int v14; // [sp+14h] [-4Ch]
  int v15; // [sp+18h] [-48h]
  idVehicleQuickItem *v16; // [sp+1Ch] [-44h]

  presentable = this->presentable;
  if ( presentable != nullptr )
    v10 = presentable->GetVehicleInterface(this: presentable);
  else
    v10 = nullptr;
  idPresentableVehicle::AddQuickItemThink(
    this: v10,
    item,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16);
}


// ========================================================================
// ?IsPassenger@idVehicle@@IBA_NPAVidEntity@@@Z
// EA  : 0x82D1F350
// RVA : 0x00D1F350
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::IsPassenger(idVehicle *this, idEntity *player)
{
  idPresentable *presentable; // r3
  int v4; // r3
  unsigned __int8 v5; // r11

  if ( player != idVehicle::GetGunner(this) )
    return 0;
  presentable = this->presentable;
  v4 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
  v5 = 1;
  if ( *(int *)(v4 + 18748) > 0 )
    return 0;
  return v5;
}


// ========================================================================
// ??0eventAnimSupport_t@idVehicle@@QAA@XZ
// EA  : 0x82D26450
// RVA : 0x00D26450
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicle::eventAnimSupport_t *__fastcall idVehicle::eventAnimSupport_t::eventAnimSupport_t(
        idVehicle::eventAnimSupport_t *this)
{
  idList<int,5> *p_prevContents; // r28

  p_prevContents = &this->prevContents;
  this->orgRotation = quat_identity;
  this->orgOrigin = vec3_origin;
  this->nextRotation = quat_identity;
  this->nextOrigin = vec3_origin;
  this->animStartFrame = -1;
  this->animUpdatedFrame = -1;
  this->currentState = -1;
  this->queuedAnimState = -1;
  this->queuedBlendTime = -1;
  this->prevContents.list = nullptr;
  this->prevContents.granularity = 0;
  this->prevContents.memTag = 5;
  this->prevContents.listStatic = 0;
  this->prevContents.size = 0;
  this->prevContents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prevContents);
  this->prevClipMasks.list = nullptr;
  this->prevClipMasks.granularity = 0;
  this->prevClipMasks.memTag = 5;
  this->prevClipMasks.listStatic = 0;
  this->prevClipMasks.size = 0;
  this->prevClipMasks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prevClipMasks);
  this->prevWheelClipMasks.memTag = 5;
  this->prevWheelClipMasks.list = nullptr;
  this->prevWheelClipMasks.granularity = 0;
  this->prevWheelClipMasks.listStatic = 0;
  this->prevWheelClipMasks.size = 0;
  this->prevWheelClipMasks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prevWheelClipMasks);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_prevContents);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prevClipMasks);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prevWheelClipMasks);
  return this;
}


// ========================================================================
// __unwind$520549
// EA  : 0x82D265AC
// RVA : 0x00D265AC
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_520549()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 76));
}


// ========================================================================
// __unwind$520550
// EA  : 0x82D265D8
// RVA : 0x00D265D8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_520550()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 92));
}


// ========================================================================
// __unwind$520551
// EA  : 0x82D26604
// RVA : 0x00D26604
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void _unwind_520551()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 108));
}


// ========================================================================
// ?GetInventory@idVehicle@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82D2E610
// RVA : 0x00D2E610
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idInventoryCollection *__fastcall idVehicle::GetInventory(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v2 = 0;
  return (*(idInventoryCollection *(__fastcall **)(int))(*(_DWORD *)v2 + 324))(a1: v2);
}


// ========================================================================
// ?GetInventory@idVehicle@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x82D2E660
// RVA : 0x00D2E660
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

const idInventoryCollection *__fastcall idVehicle::GetInventory(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v2 = 0;
  return (*(const idInventoryCollection *(__fastcall **)(int))(*(_DWORD *)v2 + 328))(a1: v2);
}


// ========================================================================
// ?GetAttachments@idVehicle@@UAAPAVidAttachmentCollection@@XZ
// EA  : 0x82D2E6B0
// RVA : 0x00D2E6B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

const idAttachmentCollection *__fastcall idVehicle::GetAttachments(idVehicle *this)
{
  return &this->attachments;
}


// ========================================================================
// ?GetHealth@idVehicle@@UBAMXZ
// EA  : 0x82D2E6B8
// RVA : 0x00D2E6B8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle::GetHealth(idVehicle *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetHealth@idVehicle@@UAAXM@Z
// EA  : 0x82D2E6C0
// RVA : 0x00D2E6C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::SetHealth(idVehicle *this, double h)
{
  double maxHealth; // fp0
  idVehicleKey *playerKey; // r3

  maxHealth = this->maxHealth;
  this->health = h;
  if ( h > maxHealth )
    this->health = maxHealth;
  playerKey = this->playerKey;
  if ( playerKey != nullptr )
    idVehicleKey::SetHealth(this: playerKey, h: this->health);
}


// ========================================================================
// ?GetTriggerTouchList@idVehicle@@UBAPBV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@XZ
// EA  : 0x82D2E6F0
// RVA : 0x00D2E6F0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

const idList<idEntityPtr<idEntity>,5> *__fastcall idVehicle::GetTriggerTouchList(idVehicle *this)
{
  return &this->touching;
}


// ========================================================================
// ?GetDynamicCoverMgr@idVehicle@@UBAPBVidDynamicCoverMgr@@XZ
// EA  : 0x82D2E6F8
// RVA : 0x00D2E6F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicleCoverMgr *__fastcall idVehicle::GetDynamicCoverMgr(idVehicle *this)
{
  return &this->vehicleCover;
}


// ========================================================================
// ?AddProjectileLock@idVehicle@@UAAXXZ
// EA  : 0x82D2E700
// RVA : 0x00D2E700
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::AddProjectileLock(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::AddProjectileLock(this: v2);
  }
  else
  {
    idPresentableVehicle::AddProjectileLock(this: nullptr);
  }
}


// ========================================================================
// ?RemoveProjectileLock@idVehicle@@UAAXXZ
// EA  : 0x82D2E758
// RVA : 0x00D2E758
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::RemoveProjectileLock(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::RemoveProjectileLock(this: v2);
  }
  else
  {
    idPresentableVehicle::RemoveProjectileLock(this: nullptr);
  }
}


// ========================================================================
// ?IsTargetLockable@idVehicle@@UBA_NPBVidDeclAmmo@@@Z
// EA  : 0x82D2E7B0
// RVA : 0x00D2E7B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle::IsTargetLockable(idVehicle *this, const idDeclAmmo *ammo)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v4; // r3
  int NumActiveOccupants; // r3
  unsigned __int8 v6; // r11

  if ( ((unsigned __int8 (__fastcall *)(idVehicle *, const idDeclAmmo *))this->IsDead)(a1: this, a2: ammo) != 0 )
    return 0;
  presentable = this->presentable;
  v4 = presentable != nullptr ? presentable->GetVehicleInterface(this: presentable) : nullptr;
  NumActiveOccupants = idPresentableVehicle::GetNumActiveOccupants(this: v4);
  v6 = 1;
  if ( NumActiveOccupants <= 0 )
    return 0;
  return v6;
}


// ========================================================================
// ?IsBoosting@idVehicle_Car@@QBA_NXZ
// EA  : 0x82D32ED0
// RVA : 0x00D32ED0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::IsBoosting(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  char v4; // r11
  idPresentable *v5; // r3
  int v6; // r3
  unsigned __int8 v7; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  if ( *(_BYTE *)(v3 + 11880) == 0 || (v4 = 1, *(_BYTE *)(v3 + 11881) == 0) )
    v4 = 0;
  if ( v4 == 0 )
    return 0;
  v5 = this->presentable;
  v6 = v5 != nullptr ? (int)v5->GetVehicleInterface(this: v5) : 0;
  v7 = 1;
  if ( *(_BYTE *)(v6 + 11881) == 0 )
    return 0;
  return v7;
}


// ========================================================================
// ?SetBoosting@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82D3C900
// RVA : 0x00D3C900
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetBoosting(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->boosting = bl;
  else
    MEMORY[0x2E68] = bl;
}


// ========================================================================
// ?StopBlurFX@idVehicle_Car@@QAAXXZ
// EA  : 0x82D3C968
// RVA : 0x00D3C968
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::StopBlurFX(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::StopBlurFX(this: v2);
  }
  else
  {
    idPresentableVehicle::StopBlurFX(this: nullptr);
  }
}


// ========================================================================
// ?GetImpactMgr@idVehicle_Car@@QAAAAVidImpactManager@@XZ
// EA  : 0x82D3C9C0
// RVA : 0x00D3C9C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::GetImpactMgr(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetVehicleInterface(this: presentable)->impactManager;
  else
    return 12504;
}


// ========================================================================
// ?SetEngineRunning@idVehicle_Car@@QAAX_N@Z
// EA  : 0x82D3CA18
// RVA : 0x00D3CA18
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle_Car::SetEngineRunning(idVehicle_Car *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->engineRunning = bl;
  else
    MEMORY[0x2E65] = bl;
}


// ========================================================================
// ?GetCgLocation@idVehicle_Car@@QBAABVidVec3@@XZ
// EA  : 0x82D3CA80
// RVA : 0x00D3CA80
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

const idVec3 *__fastcall idVehicle_Car::GetCgLocation(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return &presentable->GetVehicleInterface(this: presentable)->vehicleProps->cgLocation;
  else
    return (const idVec3 *)(MEMORY[0x2D6C] + 308);
}


// ========================================================================
// ??0aiProperties_t@idVehicle_Car@@QAA@XZ
// EA  : 0x82D3CAE0
// RVA : 0x00D3CAE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

idVehicle_Car::aiProperties_t *__fastcall idVehicle_Car::aiProperties_t::aiProperties_t(
        idVehicle_Car::aiProperties_t *this)
{
  float *p_maxSpeed; // r11
  int v2; // ctr
  const idDeclTable **v3; // r11
  int i; // ctr

  this->stickControl.angularScale[0] = 0.02;
  p_maxSpeed = &this->maxSpeed;
  this->stickControl.angularScale[1] = 0.025;
  this->stickControl.velocityScale[0] = 1.0;
  this->stickControl.velocityScale[1] = 6.0;
  v2 = 6;
  this->wheelForceScale = 1.0;
  this->cgLocation.x = -1.0;
  this->cgLocation.y = -1.0;
  this->cgLocation.z = -1.0;
  this->motorTorque = nullptr;
  this->brakeForce = 150000.0;
  this->handBrakeForce = 150000.0;
  this->maxSpeed = 150.0;
  do
  {
    *++p_maxSpeed = 0.0;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &this->friction_longitudinal[5];
  for ( i = 6; i != 0; --i )
    *++v3 = nullptr;
  this->turnspeed = nullptr;
  this->maxAngle = nullptr;
  this->steerSpeed = 90.0;
  this->health = 1000.0;
  return this;
}


// ========================================================================
// ?GetApproxSpeed@idVehicle_Car@@QAAEXZ
// EA  : 0x82D3CB98
// RVA : 0x00D3CB98
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

int __fastcall idVehicle_Car::GetApproxSpeed(idVehicle_Car *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetVehicleInterface(this: presentable)->approxSpeed;
  else
    return MEMORY[0x5020];
}


// ========================================================================
// ?IsDead@idVehicle_Car@@UBA_NXZ
// EA  : 0x82D3F710
// RVA : 0x00D3F710
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

BOOL __fastcall idVehicle_Car::IsDead(idVehicle_Car *this)
{
  return ((double (__fastcall *)(idVehicle_Car *))this->GetHealth)(a1: this) <= 0.0;
}


// ========================================================================
// ?GetMaxSpeed@idVehicle_Car@@UBAMXZ
// EA  : 0x82D3F758
// RVA : 0x00D3F758
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle_Car::GetMaxSpeed(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3
  double MaxSpeed; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    MaxSpeed = idPresentableVehicle::GetMaxSpeed(this: v2);
  }
  else
  {
    MaxSpeed = idPresentableVehicle::GetMaxSpeed(this: nullptr);
  }
  return *((float *)&MaxSpeed + 1);
}


// ========================================================================
// ?GetMaxReverseSpeed@idVehicle_Car@@UBAMXZ
// EA  : 0x82D3F7B0
// RVA : 0x00D3F7B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

float __fastcall idVehicle_Car::GetMaxReverseSpeed(idVehicle_Car *this)
{
  idPresentable *presentable; // r3
  double currentMaxReverseSpeed; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    currentMaxReverseSpeed = presentable->GetVehicleInterface(this: presentable)->currentMaxReverseSpeed;
  else
    currentMaxReverseSpeed = MEMORY[0x45E4];
  return *((float *)&currentMaxReverseSpeed + 1);
}


// ========================================================================
// ?AllowWeaponFiring@idVehicle@@QAAX_N@Z
// EA  : 0x82D4F4E8
// RVA : 0x00D4F4E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.h
// ========================================================================

void __fastcall idVehicle::AllowWeaponFiring(idVehicle *this, bool bl)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetVehicleInterface(this: presentable)->canFireWeapons = bl;
  else
    MEMORY[0x49EC] = bl;
}

