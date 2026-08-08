
// ========================================================================
// ?Update@idBotWeaponState@@QAAXABVidVec3@@@Z
// EA  : 0x82B444B8
// RVA : 0x00B444B8
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

void __fastcall idBotWeaponState::Update(idBotWeaponState *this, const idVec3 *currentAimPoint)
{
  idInventoryCollection *v3; // r3
  idWeapon *InventoryItemByName; // r30
  idWeapon *v5; // r3
  idWeapon *v6; // r30
  idWeapon_vtbl *v7; // r29
  idInventoryCollection *v8; // r3
  equipSlot_t equipSlot; // r29
  idPresentable *presentable; // r3
  int v11; // r3
  idInventoryCollection *v12; // r3
  idWeapon *v13; // r30
  idWeapon *v14; // r3
  idWeapon_vtbl *v15; // r29
  idInventoryCollection *v16; // r3
  idInventoryCollection *v17; // r3
  idWeapon *v18; // r30
  idWeapon *v19; // r3
  idWeapon *v20; // r30
  idWeapon_vtbl *v21; // r29
  idInventoryCollection *v22; // r3
  equipSlot_t v23; // r29
  idPresentable *v24; // r3
  int v25; // r3
  idInventoryCollection *v26; // r3
  idWeapon *v27; // r30
  idWeapon *v28; // r3
  idWeapon *v29; // r30
  equipSlot_t v30; // r29
  idPresentable *v31; // r3
  int v32; // r3

  v3 = this->owner->owner->GetInventory_2(this: this->owner->owner);
  InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                                      this: v3,
                                      internalName: "smg_reflex_scope");
  if ( (unsigned __int8)idWeapon::IsTypeOf(c: InventoryItemByName) != 0 )
  {
    v5 = idWeapon::CastTo(c: InventoryItemByName);
    v6 = v5;
    if ( v5 != nullptr )
    {
      v7 = v5->__vftable;
      v8 = this->owner->owner->GetInventory_2(this: this->owner->owner);
      if ( v7->TotalLoadedAmmoCount(this: v6, a2: v8, a3: false) > 0 )
        goto LABEL_4;
    }
  }
  v12 = this->owner->owner->GetInventory_2(this: this->owner->owner);
  v13 = (idWeapon *)idInventoryCollection::FindInventoryItemByName(this: v12, internalName: "assault_rifle_iron_sight");
  if ( (unsigned __int8)idWeapon::IsTypeOf(c: v13) != 0
    && (v14 = idWeapon::CastTo(c: v13), v6 = v14, v14 != nullptr)
    && (v15 = v14->__vftable,
        v16 = this->owner->owner->GetInventory_2(this: this->owner->owner),
        v15->TotalLoadedAmmoCount(this: v6, a2: v16, a3: false) > 0) )
  {
LABEL_4:
    equipSlot = v6->decl->equipSlot;
    presentable = this->owner->owner->presentable;
    if ( presentable != nullptr )
      v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = 0;
    idHands::SelectWeaponInstantly(this: (idHands *)(v11 + 37616), slot: equipSlot, weapon: v6);
    this->currentWeaponCategory = WEAPON_CATEGORY_SMG;
  }
  else
  {
    v17 = this->owner->owner->GetInventory_2(this: this->owner->owner);
    v18 = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                        this: v17,
                        internalName: "double_barrel_shotgun_iron_sight");
    if ( (unsigned __int8)idWeapon::IsTypeOf(c: v18) != 0
      && (v19 = idWeapon::CastTo(c: v18), v20 = v19, v19 != nullptr)
      && (v21 = v19->__vftable,
          v22 = this->owner->owner->GetInventory_2(this: this->owner->owner),
          v21->TotalLoadedAmmoCount(this: v20, a2: v22, a3: false) > 0) )
    {
      v23 = v20->decl->equipSlot;
      v24 = this->owner->owner->presentable;
      if ( v24 != nullptr )
        v25 = (int)v24->GetPlayerInterface_2(this: v24);
      else
        v25 = 0;
      idHands::SelectWeaponInstantly(this: (idHands *)(v25 + 37616), slot: v23, weapon: v20);
      this->currentWeaponCategory = WEAPON_CATEGORY_SHOTGUN;
    }
    else
    {
      v26 = this->owner->owner->GetInventory_2(this: this->owner->owner);
      v27 = (idWeapon *)idInventoryCollection::FindInventoryItemByName(this: v26, internalName: "fists");
      if ( (unsigned __int8)idWeapon::IsTypeOf(c: v27) != 0 )
      {
        v28 = idWeapon::CastTo(c: v27);
        v29 = v28;
        if ( v28 != nullptr )
        {
          v30 = v28->decl->equipSlot;
          v31 = this->owner->owner->presentable;
          if ( v31 != nullptr )
            v32 = (int)v31->GetPlayerInterface_2(this: v31);
          else
            v32 = 0;
          idHands::SelectWeaponInstantly(this: (idHands *)(v32 + 37616), slot: v30, weapon: v29);
          this->currentWeaponCategory = WEAPON_CATEGORY_MELEE;
        }
      }
    }
  }
}


// ========================================================================
// ?FindIndexOfWeaponRequestUser@idBotWeaponState@@QAAHPBD@Z
// EA  : 0x82B447B8
// RVA : 0x00B447B8
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

int __fastcall idBotWeaponState::FindIndexOfWeaponRequestUser(idBotWeaponState *this, const char *userName)
{
  int v3; // r30
  char **i; // r31

  v3 = 0;
  for ( i = &this->weaponRequests[0].weaponUserName.data;
        *(i - 1) == nullptr || idStr::Icmp(s1: *i, s2: userName) != 0;
        i += 12 )
  {
    if ( ++v3 >= 4 )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?AddWeaponRequest@idBotWeaponState@@QAAXW4botWeaponPriority_t@@W4botWeaponSlots_t@@PBDW4botWeaponFireMode_t@@@Z
// EA  : 0x82B44818
// RVA : 0x00B44818
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

void __fastcall idBotWeaponState::AddWeaponRequest(
        idBotWeaponState *this,
        const botWeaponPriority_t priority,
        const botWeaponSlots_t weapSlot,
        const char *userName,
        const botWeaponFireMode_t fireMode)
{
  int v6; // r11
  idStr *p_weaponUserName; // r10

  if ( idBotWeaponState::FindIndexOfWeaponRequestUser(this, userName) == -1 )
  {
    v6 = 0;
    p_weaponUserName = &this->weaponRequests[0].weaponUserName;
    do
    {
      if ( p_weaponUserName->len == 0 )
        break;
      ++v6;
      p_weaponUserName = (idStr *)((char *)p_weaponUserName + 48);
    }
    while ( v6 < 4 );
  }
}


// ========================================================================
// ??0idBotWeaponState@@QAA@XZ
// EA  : 0x82B44880
// RVA : 0x00B44880
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

idBotWeaponState *__fastcall idBotWeaponState::idBotWeaponState(idBotWeaponState *this)
{
  idBotWeaponState::BotWeaponRequest_t *weaponRequests; // r28

  weaponRequests = this->weaponRequests;
  this->owner = nullptr;
  `eh vector constructor iterator'(
    ptr: this->weaponRequests,
    size: 0x30u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idBotWeaponState::BotWeaponRequest_t::BotWeaponRequest_t,
    pDtor: (void (__fastcall *)(void *))idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t);
  this->weapons.list = nullptr;
  this->weapons.granularity = 0;
  this->weapons.memTag = 5;
  this->weapons.listStatic = 0;
  this->weapons.size = 0;
  this->weapons.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weapons);
  this->currentWeaponCategory = WEAPON_CATEGORY_MAX;
  memset(Dst: weaponRequests, Val: 0, Size: sizeof(idBotWeaponState::BotWeaponRequest_t));
  return this;
}


// ========================================================================
// __unwind$488664
// EA  : 0x82B44908
// RVA : 0x00B44908
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

void _unwind_488664()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 4),
    size: 0x30u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t);
}


// ========================================================================
// ??1idBotWeaponState@@QAA@XZ
// EA  : 0x82B44950
// RVA : 0x00B44950
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

void __fastcall idBotWeaponState::~idBotWeaponState(idBotWeaponState *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weapons);
  `eh vector destructor iterator'(
    ptr: this->weaponRequests,
    size: 0x30u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t);
}


// ========================================================================
// __unwind$488688_0
// EA  : 0x82B449A8
// RVA : 0x00B449A8
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.cpp
// ========================================================================

void _unwind_488688_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 4),
    size: 0x30u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t);
}

