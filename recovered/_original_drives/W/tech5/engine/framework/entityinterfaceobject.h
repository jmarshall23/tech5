
// ========================================================================
// ??0idEntityInterfaceObject@@QAA@PAVidGame@@PAVidEntity@@@Z
// EA  : 0x82BDC558
// RVA : 0x00BDC558
// PDB : w:\tech5\engine\framework\entityinterfaceobject.h
// ========================================================================

idEntityInterfaceObject *__fastcall idEntityInterfaceObject::idEntityInterfaceObject(
        idEntityInterfaceObject *this,
        idGame *game,
        idEntity *entity)
{
  idGameLock::idGameLock(this: &this->lock, newGame: game);
  this->iface = nullptr;
  if ( entity != nullptr )
    this->iface = game->AllocEntityInterface(this: game, a2: entity);
  return this;
}


// ========================================================================
// __unwind$489881_0
// EA  : 0x82BDC5B8
// RVA : 0x00BDC5B8
// PDB : w:\tech5\engine\framework\entityinterfaceobject.h
// ========================================================================

void _unwind_489881_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: *(idGameLock **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idEntityInterfaceObject@@QAA@XZ
// EA  : 0x82BDC5E8
// RVA : 0x00BDC5E8
// PDB : w:\tech5\engine\framework\entityinterfaceobject.h
// ========================================================================

void __fastcall idEntityInterfaceObject::~idEntityInterfaceObject(idEntityInterfaceObject *this)
{
  idEntityInterface *iface; // r11
  int v3; // r3

  iface = this->iface;
  if ( iface != nullptr )
  {
    v3 = ((int (*)(void))iface->Game)();
    if ( v3 != 0 )
      (*(void (__fastcall **)(int, idEntityInterface *))(*(_DWORD *)v3 + 376))(a1: v3, a2: this->iface);
  }
  idGameLock::~idGameLock(this: &this->lock);
}


// ========================================================================
// __unwind$489900
// EA  : 0x82BDC664
// RVA : 0x00BDC664
// PDB : w:\tech5\engine\framework\entityinterfaceobject.h
// ========================================================================

void _unwind_489900()
{
  int v0; // r12

  idGameLock::~idGameLock(this: *(idGameLock **)(v0 - 112 + 132));
}

