
// ========================================================================
// ?FiberEntry_OnActivate@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39B10
// RVA : 0x00C39B10
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnActivate(idSSObject *object, int activator)
{
  if ( object != nullptr )
    object->_OnActivate(this: object, a2: activator);
}


// ========================================================================
// ?FiberEntry_OnTrigger@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39B30
// RVA : 0x00C39B30
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnTrigger(idSSObject *object, int activator)
{
  if ( object != nullptr )
    object->_OnTrigger(this: object, a2: activator);
}


// ========================================================================
// ?FiberEntry_OnActivateTargets@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39B50
// RVA : 0x00C39B50
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnActivateTargets(idSSObject *object, int activator)
{
  if ( object != nullptr )
    object->_OnActivateTargets(this: object, a2: activator);
}


// ========================================================================
// ?FiberEntry_OnDamage@idSuperScriptSystem@@CAXPAVidSSObject@@HM@Z
// EA  : 0x82C39B70
// RVA : 0x00C39B70
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnDamage(idSSObject *object, int attacker, double scaledBodyDamage)
{
  if ( object != nullptr )
    object->_OnDamage(this: object, a2: attacker, a3: scaledBodyDamage);
}


// ========================================================================
// ?FiberEntry_OnDeath@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39B90
// RVA : 0x00C39B90
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnDeath(idSSObject *object, int attacker)
{
  if ( object != nullptr )
    object->_OnDeath(this: object, a2: attacker);
}


// ========================================================================
// ?FiberEntry_OnReachGoal@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39BB0
// RVA : 0x00C39BB0
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnReachGoal(idSSObject *object, int goalEntity)
{
  if ( object != nullptr )
    object->_OnReachGoal(this: object, a2: goalEntity);
}


// ========================================================================
// ?FiberEntry_OnAnimNotify@idSuperScriptSystem@@CAXPAVidSSObject@@PBD@Z
// EA  : 0x82C39BD0
// RVA : 0x00C39BD0
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnAnimNotify(idSSObject *object, const char *message)
{
  if ( object != nullptr )
    object->_OnAnimNotify(this: object, a2: message);
}


// ========================================================================
// ?FiberEntry_OnMoverNotify@idSuperScriptSystem@@CAXPAVidSSObject@@PBD@Z
// EA  : 0x82C39BF0
// RVA : 0x00C39BF0
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnMoverNotify(idSSObject *object, const char *message)
{
  if ( object != nullptr )
    object->_OnMoverNotify(this: object, a2: message);
}


// ========================================================================
// ?FiberEntry_OnEnter@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39C10
// RVA : 0x00C39C10
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnEnter(idSSObject *object, int dude)
{
  if ( object != nullptr )
    object->_OnEnter(this: object, a2: dude);
}


// ========================================================================
// ?FiberEntry_OnExit@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39C30
// RVA : 0x00C39C30
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnExit(idSSObject *object, int dude)
{
  if ( object != nullptr )
    object->_OnExit(this: object, a2: dude);
}


// ========================================================================
// ?FiberEntry_OnUse@idSuperScriptSystem@@CAXPAVidSSObject@@H@Z
// EA  : 0x82C39C50
// RVA : 0x00C39C50
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptSystem::FiberEntry_OnUse(idSSObject *object, int user)
{
  if ( object != nullptr )
    object->_OnUse(this: object, a2: user);
}


// ========================================================================
// ?SendNotify_OnActivate@idEntity@@QAAXH@Z
// EA  : 0x82C44C20
// RVA : 0x00C44C20
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnActivate(idEntity *this, char *activator)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnActivate") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnActivate",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnActivate,
              p1: activator);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnTrigger@idEntity@@QAAXH@Z
// EA  : 0x82C44D28
// RVA : 0x00C44D28
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnTrigger(idEntity *this, char *activator)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnTrigger") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnTrigger",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnTrigger,
              p1: activator);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnActivateTargets@idEntity@@QAAXH@Z
// EA  : 0x82C44E30
// RVA : 0x00C44E30
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnActivateTargets(idEntity *this, char *activator)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnActivateTargets") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnActivateTargets",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnActivateTargets,
              p1: activator);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnDamage@idEntity@@QAAXHM@Z
// EA  : 0x82C44F38
// RVA : 0x00C44F38
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnDamage(idEntity *this, char *attacker, double scaledBodyDamage)
{
  int num; // r9
  int v7; // r29
  int v8; // r27
  char v9; // r11
  unsigned int v10; // r10
  char v11; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v13; // r6
  idSSObject *v14; // r31

  num = this->superScriptObjects.num;
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      if ( v7 < 0 || (v9 = 1, v7 >= num) )
        v9 = 0;
      if ( v9 != 0 )
      {
        v10 = (unsigned int)this->superScriptObjects.list[v8];
        if ( v10 != 0 )
        {
          if ( v7 < 0 || (v11 = 1, v7 >= num) )
            v11 = 0;
          p_superScript = &gameLocal->superScript;
          v13 = (v11 == 0) - 1;
          v14 = (idSSObject *)(v13 & v10);
          if ( (v13 & v10) != 0 && v14->_isNotifyFunction(this: (idSSObject *)(v13 & v10), a2: "OnDamage") )
            idSuperScriptSystem::CreateThreadDelayed2<int,float>(
              this: p_superScript,
              name: "OnDamage",
              sso: v14,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnDamage,
              p1: attacker,
              p2: scaledBodyDamage);
        }
      }
      num = this->superScriptObjects.num;
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
}


// ========================================================================
// ?SendNotify_OnDeath@idEntity@@QAAXH@Z
// EA  : 0x82C45050
// RVA : 0x00C45050
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnDeath(idEntity *this, char *attacker)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnDeath") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnDeath",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnDeath,
              p1: attacker);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnReachGoal@idEntity@@QAAXH@Z
// EA  : 0x82C45158
// RVA : 0x00C45158
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnReachGoal(idEntity *this, char *goalEntity)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnReachGoal") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnReachGoal",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnReachGoal,
              p1: goalEntity);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnAnimNotify@idEntity@@QAAXPBD@Z
// EA  : 0x82C45260
// RVA : 0x00C45260
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnAnimNotify(idEntity *this, char *message)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnAnimNotify") )
            idSuperScriptSystem::CreateThreadDelayed1<char const *>(
              this: p_superScript,
              name: "OnAnimNotify",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnAnimNotify,
              p1: message);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnMoverNotify@idEntity@@QAAXPBD@Z
// EA  : 0x82C45368
// RVA : 0x00C45368
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnMoverNotify(idEntity *this, char *message)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnMoverNotify") )
            idSuperScriptSystem::CreateThreadDelayed1<char const *>(
              this: p_superScript,
              name: "OnMoverNotify",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnMoverNotify,
              p1: message);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnEnter@idEntity@@QAAXH@Z
// EA  : 0x82C45470
// RVA : 0x00C45470
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnEnter(idEntity *this, char *dude)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnEnter") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnEnter",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnEnter,
              p1: dude);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnExit@idEntity@@QAAXH@Z
// EA  : 0x82C45578
// RVA : 0x00C45578
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnExit(idEntity *this, char *dude)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnExit") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnExit",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnExit,
              p1: dude);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?SendNotify_OnUse@idEntity@@QAAXH@Z
// EA  : 0x82C45680
// RVA : 0x00C45680
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idEntity::SendNotify_OnUse(idEntity *this, char *user)
{
  int num; // r9
  int v5; // r29
  int v6; // r27
  char v7; // r11
  unsigned int v8; // r10
  char v9; // r11
  idSuperScriptSystem *p_superScript; // r30
  int v11; // r6
  idSSObject *v12; // r31

  num = this->superScriptObjects.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || (v7 = 1, v5 >= num) )
        v7 = 0;
      if ( v7 != 0 )
      {
        v8 = (unsigned int)this->superScriptObjects.list[v6];
        if ( v8 != 0 )
        {
          if ( v5 < 0 || (v9 = 1, v5 >= num) )
            v9 = 0;
          p_superScript = &gameLocal->superScript;
          v11 = (v9 == 0) - 1;
          v12 = (idSSObject *)(v11 & v8);
          if ( (v11 & v8) != 0 && v12->_isNotifyFunction(this: (idSSObject *)(v11 & v8), a2: "OnUse") )
            idSuperScriptSystem::CreateThreadDelayed1<int>(
              this: p_superScript,
              name: "OnUse",
              sso: v12,
              entryPoint: (idSSFiber_vtbl *)idSuperScriptSystem::FiberEntry_OnUse,
              p1: user);
        }
      }
      num = this->superScriptObjects.num;
      ++v5;
      ++v6;
    }
    while ( v5 < num );
  }
}


// ========================================================================
// ?OnMoverNotify@idSuperScriptObject@@UAAXVssString@@@Z
// EA  : 0x82EE1B70
// RVA : 0x00EE1B70
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::OnMoverNotify(idSuperScriptObject *this, ssString *__formal)
{
  ssString::Empty(this: __formal);
}


// ========================================================================
// ?_OnActivate@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1BB8
// RVA : 0x00EE1BB8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnActivate(idSuperScriptObject *this, XGRAPHICS::Compiler *activator)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: activator);
  v3->OnActivate(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnTrigger@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1C08
// RVA : 0x00EE1C08
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnTrigger(idSuperScriptObject *this, XGRAPHICS::Compiler *activator)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: activator);
  v3->OnTrigger(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnActivateTargets@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1C58
// RVA : 0x00EE1C58
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnActivateTargets(idSuperScriptObject *this, XGRAPHICS::Compiler *activator)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: activator);
  v3->OnActivateTargets(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnActionReached@idSuperScriptObject@@EAAXHH_N@Z
// EA  : 0x82EE1CA8
// RVA : 0x00EE1CA8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnActionReached(
        idSuperScriptObject *this,
        XGRAPHICS::Compiler *actionEntity,
        XGRAPHICS::Compiler *ai,
        BOOL firstTimeReached)
{
  idSuperScriptObject_vtbl *v7; // r28
  XGRAPHICS::VRegTable *v8; // r27
  XGRAPHICS::VRegTable *v9; // r3
  XGRAPHICS::VRegTable v10; // [sp+50h] [-40h] BYREF

  v7 = this->__vftable;
  v8 = ssEntity::ssEntity(this: &v10, context: ai);
  v9 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v10.symbols, context: actionEntity);
  v7->OnActionReached(this, a2: (ssEntity *)v9, a3: (ssEntity *)v8, a4: firstTimeReached);
}


// ========================================================================
// ?_OnGoalReach@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1D08
// RVA : 0x00EE1D08
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnGoalReach(idSuperScriptObject *this, XGRAPHICS::Compiler *ai)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: ai);
  v3->OnGoalReach(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnGoalAssigned@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1D58
// RVA : 0x00EE1D58
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnGoalAssigned(idSuperScriptObject *this, XGRAPHICS::Compiler *ai)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: ai);
  v3->OnGoalAssigned(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnDamage@idSuperScriptObject@@EAAXHM@Z
// EA  : 0x82EE1DA8
// RVA : 0x00EE1DA8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnDamage(
        idSuperScriptObject *this,
        XGRAPHICS::Compiler *attacker,
        double scaledBodyDamage)
{
  idSuperScriptObject_vtbl *v5; // r30
  XGRAPHICS::VRegTable *v6; // r3
  XGRAPHICS::VRegTable v7; // [sp+50h] [-30h] BYREF

  v5 = this->__vftable;
  v6 = ssEntity::ssEntity(this: &v7, context: attacker);
  v5->OnDamage(this, a2: (ssEntity *)v6, a3: scaledBodyDamage);
}


// ========================================================================
// ?_OnDeath@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1E08
// RVA : 0x00EE1E08
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnDeath(idSuperScriptObject *this, XGRAPHICS::Compiler *attacker)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: attacker);
  v3->OnDeath(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnLeftGoal@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1E58
// RVA : 0x00EE1E58
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnLeftGoal(idSuperScriptObject *this, XGRAPHICS::Compiler *goalEntity)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: goalEntity);
  v3->OnLeftGoal(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnReachGoal@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1EA8
// RVA : 0x00EE1EA8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnReachGoal(idSuperScriptObject *this, XGRAPHICS::Compiler *goalEntity)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: goalEntity);
  v3->OnReachGoal(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnLeaveAction@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1EF8
// RVA : 0x00EE1EF8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnLeaveAction(idSuperScriptObject *this, XGRAPHICS::Compiler *actionEntity)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: actionEntity);
  v3->OnLeaveAction(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnReachAction@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1F48
// RVA : 0x00EE1F48
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnReachAction(idSuperScriptObject *this, XGRAPHICS::Compiler *actionEntity)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: actionEntity);
  v3->OnReachAction(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnAssignedGoal@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE1F98
// RVA : 0x00EE1F98
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnAssignedGoal(idSuperScriptObject *this, XGRAPHICS::Compiler *goalEntity)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: goalEntity);
  v3->OnAssignedGoal(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnAnimNotify@idSuperScriptObject@@EAAXPBD@Z
// EA  : 0x82EE1FE8
// RVA : 0x00EE1FE8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnAnimNotify(idSuperScriptObject *this, const char *message)
{
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: message);
  this->OnAnimNotify(this, a2: &v4);
}


// ========================================================================
// ?_OnAnimEnd@idSuperScriptObject@@EAAXXZ
// EA  : 0x82EE2048
// RVA : 0x00EE2048
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnAnimEnd(idSuperScriptObject *this)
{
  this->OnAnimEnd(this);
}


// ========================================================================
// ?_OnAnimStart@idSuperScriptObject@@EAAXXZ
// EA  : 0x82EE2058
// RVA : 0x00EE2058
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnAnimStart(idSuperScriptObject *this)
{
  this->OnAnimStart(this);
}


// ========================================================================
// ?_OnMoverNotify@idSuperScriptObject@@EAAXPBD@Z
// EA  : 0x82EE2068
// RVA : 0x00EE2068
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnMoverNotify(idSuperScriptObject *this, const char *message)
{
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: message);
  this->OnMoverNotify(this, a2: &v4);
}


// ========================================================================
// ?_OnTargetSpawn@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE20C8
// RVA : 0x00EE20C8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnTargetSpawn(idSuperScriptObject *this, XGRAPHICS::Compiler *spawned)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: spawned);
  v3->OnTargetSpawn(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnEnter@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE2118
// RVA : 0x00EE2118
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnEnter(idSuperScriptObject *this, XGRAPHICS::Compiler *dude)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: dude);
  v3->OnEnter(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnExit@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE2168
// RVA : 0x00EE2168
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnExit(idSuperScriptObject *this, XGRAPHICS::Compiler *dude)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: dude);
  v3->OnExit(this, a2: (ssEntity *)v4);
}


// ========================================================================
// ?_OnUse@idSuperScriptObject@@EAAXH@Z
// EA  : 0x82EE21B8
// RVA : 0x00EE21B8
// PDB : w:\tech5\tungsten\superscript\sys\ssnotify.h
// ========================================================================

void __fastcall idSuperScriptObject::_OnUse(idSuperScriptObject *this, XGRAPHICS::Compiler *user)
{
  idSuperScriptObject_vtbl *v3; // r30
  XGRAPHICS::VRegTable *v4; // r3
  char v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  v4 = ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v5, context: user);
  v3->OnUse(this, a2: (ssEntity *)v4);
}

