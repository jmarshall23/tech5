
// ========================================================================
// ?GetMsgType@idClientGameMsg_HandsEquip@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B58738
// RVA : 0x00B58738
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_HandsEquip::GetMsgType(idClientGameMsg_HandsEquip *this)
{
  return 38;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_HandsEquip@@UAAXXZ
// EA  : 0x82B58740
// RVA : 0x00B58740
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_HandsEquip::PrintDebug(idClientGameMsg_HandsEquip *this)
{
  const idDeclAmmo *ammoDecl; // r11
  const char *v2; // r5
  const char *str; // r6
  const idDeclInventory *itemDecl; // r11

  ammoDecl = this->ammoDecl;
  v2 = "NULL";
  if ( ammoDecl != nullptr )
    str = ammoDecl->name.str;
  else
    str = "NULL";
  itemDecl = this->itemDecl;
  if ( itemDecl != nullptr )
    v2 = itemDecl->name.str;
  idLib::Printf(fmt: "idClientGameMsg_HandsEquip. Player: %d. Item: %s ammoDecl: %s \n", this->playerNumber, v2, str);
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_HandsAmmoChange@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B58780
// RVA : 0x00B58780
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_HandsAmmoChange::GetMsgType(idClientGameMsg_HandsAmmoChange *this)
{
  return 39;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_HandsAmmoChange@@UAAXXZ
// EA  : 0x82B58788
// RVA : 0x00B58788
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_HandsAmmoChange::PrintDebug(idClientGameMsg_HandsAmmoChange *this)
{
  const idDeclAmmo *ammoDecl; // r11
  const char *str; // r5

  ammoDecl = this->ammoDecl;
  if ( ammoDecl != nullptr )
    str = ammoDecl->name.str;
  else
    str = "NULL";
  idLib::Printf(fmt: "idClientGameMsg_HandsAmmoChange. Player: %d. Ammo: %s \n", this->playerNumber, str);
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_DropItem@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B592B8
// RVA : 0x00B592B8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_DropItem::GetMsgType(idClientGameMsg_DropItem *this)
{
  return 46;
}


// ========================================================================
// ?ShouldExecuteOnInstigator@idClientGameMsg_DropItem@@UAA_NXZ
// EA  : 0x82B592C0
// RVA : 0x00B592C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

BOOL __fastcall idClientGameMsg_DropItem::ShouldExecuteOnInstigator(idClientGameMsg_DropItem *this)
{
  return common->IsServer(this: common);
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_QuickUse@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B592D8
// RVA : 0x00B592D8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_QuickUse::GetMsgType(idClientGameMsg_QuickUse *this)
{
  return 42;
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_UseFocus@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B592E0
// RVA : 0x00B592E0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_UseFocus::GetMsgType(idClientGameMsg_UseFocus *this)
{
  return 43;
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_MeleeHit@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B592E8
// RVA : 0x00B592E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_MeleeHit::GetMsgType(idClientGameMsg_MeleeHit *this)
{
  return 45;
}


// ========================================================================
// ??1idClientGameMsg_MeleeHit@@UAA@XZ
// EA  : 0x82B592F0
// RVA : 0x00B592F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(idClientGameMsg_VehicleWeaponChange *this)
{
  this->__vftable = (idClientGameMsg_VehicleWeaponChange_vtbl *)&idClientGameMsg::`vftable';
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_ActorModifier@@UAAXXZ
// EA  : 0x82B59358
// RVA : 0x00B59358
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_ActorModifier::PrintDebug(idClientGameMsg_ActorModifier *this)
{
  idLib::Printf(fmt: "idClientGameMsg_ActorModifier.\n");
}


// ========================================================================
// ??0idClientGameMsg_HandsThrow@@QAA@XZ
// EA  : 0x82B59FC0
// RVA : 0x00B59FC0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

idClientGameMsg_HandsThrow *__fastcall idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow(
        idClientGameMsg_HandsThrow *this)
{
  idFinishFireResults *p_ffr; // r11
  int i; // ctr

  this->peerMask = -1;
  this->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_HandsThrow::`vftable';
  idFireParms::idFireParms(this: &this->fp);
  this->tfr.numTraces = 0;
  memset(Dst: this->tfr.traces, Val: 0, Size: sizeof(this->tfr.traces));
  memset(Dst: this->tfr.traceDirs, Val: 0, Size: sizeof(this->tfr.traceDirs));
  memset(Dst: this->tfr.traceLens, Val: 0, Size: sizeof(this->tfr.traceLens));
  this->ffr.numProjectiles = 0;
  p_ffr = &this->ffr;
  for ( i = 16; i != 0; --i )
  {
    p_ffr = (idFinishFireResults *)((char *)p_ffr + 4);
    p_ffr->numProjectiles = 0;
  }
  this->playerNumber = 0;
  this->throwItem = nullptr;
  this->throwType = HANDS_THROW_MAX;
  this->start = vec3_origin;
  this->fireAxis = mat3_identity;
  this->startTime = 0;
  this->initialSpeed = 0.0;
  this->serverTime = -1;
  this->predictedKey = -1;
  return this;
}


// ========================================================================
// __unwind$491637
// EA  : 0x82B5A118
// RVA : 0x00B5A118
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void _unwind_491637()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: *(idClientGameMsg_VehicleWeaponChange **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idClientGameMsg_HitScanHit@@QAA@XZ
// EA  : 0x82B5A1C0
// RVA : 0x00B5A1C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

idClientGameMsg_HitScanHit *__fastcall idClientGameMsg_HitScanHit::idClientGameMsg_HitScanHit(
        idClientGameMsg_HitScanHit *this)
{
  idClientGameMsg_HitScanHit *v1; // r10
  int i; // ctr

  this->__vftable = (idClientGameMsg_HitScanHit_vtbl *)&idClientGameMsg_HitScanHit::`vftable';
  this->peerMask = -1;
  v1 = this;
  this->attacker.spawnId = 0;
  for ( i = 24; i != 0; --i )
  {
    v1->hitInfos[0].entityNum = 0;
    v1 = (idClientGameMsg_HitScanHit *)((char *)v1 + 24);
    v1->__vftable = nullptr;
  }
  this->attacker.spawnId = 0;
  this->weaponDecl = nullptr;
  this->projDecl = nullptr;
  this->numHits = 0;
  this->serverTime = 0;
  this->startPos = vec3_origin;
  return this;
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_VehicleCrosshairChangeTarget@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B5A230
// RVA : 0x00B5A230
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_VehicleCrosshairChangeTarget::GetMsgType(
        idClientGameMsg_VehicleCrosshairChangeTarget *this)
{
  return 47;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_VehicleCrosshairChangeTarget@@UAAXXZ
// EA  : 0x82B5A238
// RVA : 0x00B5A238
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_VehicleCrosshairChangeTarget::PrintDebug(
        idClientGameMsg_VehicleCrosshairChangeTarget *this)
{
  idLib::Printf(fmt: "idClientGameMsg_VehicleCrosshairChangeTarget.\n");
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidStaticParticleModelData@@@@UBAHXZ
// EA  : 0x82B5A248
// RVA : 0x00B5A248
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idTypedResourceList<idStaticParticleModelData>::AllocSize(idTypedResourceList<idFileResource> *this)
{
  return 48;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_VehicleWeaponChange@@UAAXXZ
// EA  : 0x82B5A250
// RVA : 0x00B5A250
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_VehicleWeaponChange::PrintDebug(idClientGameMsg_VehicleWeaponChange *this)
{
  idLib::Printf(fmt: "idClientGameMsg_VehicleWeaponChange.\n");
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_UpdateStat@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B5A260
// RVA : 0x00B5A260
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_UpdateStat::GetMsgType(idClientGameMsg_UpdateStat *this)
{
  return 49;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_UpdateStat@@UAAXXZ
// EA  : 0x82B5A268
// RVA : 0x00B5A268
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void __fastcall idClientGameMsg_UpdateStat::PrintDebug(idClientGameMsg_UpdateStat *this)
{
  idLib::Printf(fmt: "idClientGameMsg_UpdateStat.\n");
}


// ========================================================================
// ??0idClientGameMsg_PostGameScoreRecap@@QAA@XZ
// EA  : 0x82B5BF60
// RVA : 0x00B5BF60
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

idClientGameMsg_PostGameScoreRecap *__fastcall idClientGameMsg_PostGameScoreRecap::idClientGameMsg_PostGameScoreRecap(
        idClientGameMsg_PostGameScoreRecap *this)
{
  this->peerMask = -1;
  this->__vftable = (idClientGameMsg_PostGameScoreRecap_vtbl *)&idClientGameMsg_PostGameScoreRecap::`vftable';
  this->items.list = nullptr;
  this->items.granularity = 0;
  this->items.memTag = 5;
  this->items.listStatic = 0;
  this->items.size = 0;
  this->items.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->items);
  return this;
}


// ========================================================================
// __unwind$494135_0
// EA  : 0x82B5BFD8
// RVA : 0x00B5BFD8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

void _unwind_494135_0()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: *(idClientGameMsg_VehicleWeaponChange **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetMsgType@idClientGameMsg_PostGameScoreRecap@@UAA?AW4gameReliable_t@@XZ
// EA  : 0x82B5C000
// RVA : 0x00B5C000
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

int __fastcall idClientGameMsg_PostGameScoreRecap::GetMsgType(idClientGameMsg_PostGameScoreRecap *this)
{
  return 58;
}


// ========================================================================
// ??0idClientGameMsg_MeleeHit@@QAA@PAVidPresentablePlayer@@HPBVidDeclDamage@@AAUtrace_t@@@Z
// EA  : 0x82ECE0B0
// RVA : 0x00ECE0B0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.h
// ========================================================================

idClientGameMsg_MeleeHit *__fastcall idClientGameMsg_MeleeHit::idClientGameMsg_MeleeHit(
        idClientGameMsg_MeleeHit *this,
        idPresentablePlayer *instigator_,
        int hitEntityNum_,
        const idDeclDamage *damageDecl_,
        trace_t *trace_)
{
  this->peerMask = -1;
  this->__vftable = (idClientGameMsg_MeleeHit_vtbl *)&idClientGameMsg_MeleeHit::`vftable';
  this->instigator.spawnId = 0;
  if ( instigator_ != nullptr )
    this->instigator.spawnId = instigator_->spawnId;
  else
    this->instigator.spawnId = 0;
  this->hitEntityNum = hitEntityNum_;
  this->damageDecl = damageDecl_;
  trace_t::operator=(this: &this->trace, __that: trace_);
  return this;
}

