
// ========================================================================
// ??0idTarget_PlayerLoadSpecialWeapon@@QAA@XZ
// EA  : 0x82CE0BF8
// RVA : 0x00CE0BF8
// PDB : w:\tech5\tungsten\game\entities\target_player.cpp
// ========================================================================

idTarget_PlayerLoadSpecialWeapon *__fastcall idTarget_PlayerLoadSpecialWeapon::idTarget_PlayerLoadSpecialWeapon(
        idTarget_PlayerLoadSpecialWeapon *this)
{
  idEntity::idEntity(this);
  this->weaponDecl = nullptr;
  this->__vftable = (idTarget_PlayerLoadSpecialWeapon_vtbl *)&idTarget_PlayerLoadSpecialWeapon::`vftable';
  this->newWidth = 32.0;
  this->isActive = false;
  this->newHeight = 120.0;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_PlayerLoadSpecialWeapon@@EAAXPAVidEntity@@@Z
// EA  : 0x82CE0C58
// RVA : 0x00CE0C58
// PDB : w:\tech5\tungsten\game\entities\target_player.cpp
// ========================================================================

void __fastcall idTarget_PlayerLoadSpecialWeapon::OnActivate(
        idTarget_PlayerLoadSpecialWeapon *this,
        idPlayer *activator)
{
  idPlayer *v4; // r3
  idEntity *v5; // r31
  idJobManager *v6; // r3
  idInventoryCollection *v7; // r29
  idPhysics *Physics; // r3
  idInventoryCollection *v9; // r3
  idWeapon *InventoryItemByName; // r3
  idWeapon *v11; // r3
  idWeapon *v12; // r29
  const idDeclInventory *decl; // r11
  idPresentable *presentable; // r3
  equipSlot_t equipSlot; // r28
  int v16; // r3
  idPresentable *v17; // r29
  const idDeclWeapon *weaponDecl; // r30
  idInventoryCollection *v19; // r3
  idPresentable *v20; // r3
  idPresentablePlayer *v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  idJob *JobByDecl; // r3
  idPresentable *v25; // r4
  idWeapon *v26; // r29
  bool v27; // r4
  double newHeight; // fp1
  bool v29; // r4
  bool v30; // r4
  idPresentable *v31; // r3
  equipSlot_t v32; // r30
  int v33; // r3
  idPhysics *v34; // r3
  idPresentable *v35; // r3
  idPresentablePlayer *v36; // r3
  idPresentable *v37; // r3
  int v38; // r3

  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( this->weaponDecl != nullptr )
    {
      v6 = (idJobManager *)v4->GetInventory_2(this: v4);
      v7 = (idInventoryCollection *)v6;
      if ( v6 != nullptr )
      {
        if ( this->isActive )
        {
          this->isActive = false;
          idCVar::Set(this: &pm_normalviewheight, newValue: pm_normalviewheight.resetString, force: true);
          idCVar::Set(this: &pm_normalheight, newValue: pm_normalheight.resetString, force: true);
          idCVar::Set(this: &pm_bboxwidth, newValue: pm_bboxwidth.resetString, force: true);
          Physics = idEntity::GetPhysics(this: v5);
          ((void (__fastcall *)(idPhysics *, _DWORD, double))Physics->SetClipModel)(
            a1: Physics,
            a2: 0,
            a3: 0.0049999999);
          v9 = v5->GetInventory_2(this: v5);
          InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                                              this: v9,
                                              internalName: "knife");
          v11 = idWeapon::CastTo(c: InventoryItemByName);
          v12 = v11;
          if ( v11 != nullptr )
          {
            decl = v11->decl;
            presentable = v5->presentable;
            equipSlot = decl->equipSlot;
            if ( presentable != nullptr )
              v16 = (int)presentable->GetPlayerInterface_2(this: presentable);
            else
              v16 = 0;
            idHands::SelectWeaponInstantly(this: (idHands *)(v16 + 37616), slot: equipSlot, weapon: v12);
          }
          v17 = v5->presentable;
          if ( v17 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v17 = v5->presentable;
          }
          weaponDecl = this->weaponDecl;
          v19 = v5->GetInventory_2(this: v5);
          idInventoryCollection::DeleteInventoryItem(this: v19, owner: v17, decl: weaponDecl, count: 1);
          v20 = v5->presentable;
          if ( v20 != nullptr )
            v21 = v20->GetPlayerInterface_2(this: v20);
          else
            v21 = nullptr;
          idPresentablePlayer::ClearInhibitFlags(this: v21, flags: UCMD_INHIBIT_MOVEMENT_UP);
          v22 = v5->presentable;
          if ( v22 != nullptr )
            v23 = (int)v22->GetPlayerInterface_2(this: v22);
          else
            v23 = 0;
          *(_BYTE *)(v23 + 47034) &= ~0x40u;
        }
        else
        {
          JobByDecl = idJobManager::FindJobByDecl(this: v6, jobDecl: (const idDeclJob *)this->weaponDecl);
          if ( JobByDecl == nullptr )
          {
            v25 = v5->presentable;
            if ( v25 == nullptr )
            {
              idEntity::InitPresentableInternal(this: v5);
              v25 = v5->presentable;
            }
            idInventoryCollection::GiveItem(
              this: v7,
              owner: v25,
              decl: this->weaponDecl,
              count: 1,
              forceCount: false,
              canIntro: false);
            JobByDecl = idJobManager::FindJobByDecl(
                          this: (idJobManager *)v7,
                          jobDecl: (const idDeclJob *)this->weaponDecl);
          }
          v26 = idWeapon::CastTo(c: (idWeapon *)JobByDecl);
          if ( v26 != nullptr )
          {
            newHeight = this->newHeight;
            this->isActive = true;
            idCVar::SetFloat(this: &pm_normalviewheight, newValue: newHeight, force: v27);
            idCVar::SetFloat(this: &pm_normalheight, newValue: this->newHeight, force: v29);
            idCVar::SetFloat(this: &pm_bboxwidth, newValue: this->newWidth, force: v30);
            v31 = v5->presentable;
            v32 = v26->decl->equipSlot;
            if ( v31 != nullptr )
              v33 = (int)v31->GetPlayerInterface_2(this: v31);
            else
              v33 = 0;
            idHands::SelectWeaponInstantly(this: (idHands *)(v33 + 37616), slot: v32, weapon: v26);
            v34 = idEntity::GetPhysics(this: v5);
            ((void (__fastcall *)(idPhysics *, _DWORD, double))v34->SetClipModel)(a1: v34, a2: 0, a3: 0.0049999999);
            v35 = v5->presentable;
            if ( v35 != nullptr )
              v36 = v35->GetPlayerInterface_2(this: v35);
            else
              v36 = nullptr;
            idPresentablePlayer::SetInhibitFlags(this: v36, flags: UCMD_INHIBIT_MOVEMENT_UP);
            v37 = v5->presentable;
            if ( v37 != nullptr )
              v38 = (int)v37->GetPlayerInterface_2(this: v37);
            else
              v38 = 0;
            *(_BYTE *)(v38 + 47034) |= 0x40u;
          }
          else
          {
            idLib::Warning(fmt: "idTarget_PlayerLoadSpecialWeapon: error giving weapon");
          }
        }
      }
      else
      {
        idLib::Warning(fmt: "idTarget_PlayerLoadSpecialWeapon: no inventory on %s", activator->name.data);
      }
    }
    else
    {
      idLib::Warning(fmt: "idTarget_PlayerLoadSpecialWeapon ('%s') does not have a weapon decl", this->name.data);
    }
  }
  else if ( activator != nullptr )
  {
    idLib::Warning(fmt: "idTarget_PlayerLoadSpecialWeapon called with non player %s", activator->name.data);
  }
  else
  {
    idLib::Warning(fmt: "idTarget_PlayerLoadSpecialWeapon called with null activator");
  }
}

